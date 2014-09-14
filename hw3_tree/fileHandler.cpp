//
//  fileHandler.cpp
//  DS_hw3_Tree
//
//  Created by lin shih-feng on 9/12/14.
//  Copyright (c) 2014 lin shih-feng. All rights reserved.
//

#include "fileHandler.h"

void FILE_HANDLER::addFileName(std::string fileName) {
    fileList.push_back(fileName);
}

bool FILE_HANDLER::searchFileName(std::string cmpFileName) {
    for (unsigned i=0; i<fileList.size(); i++) {
        if (fileList[i].compare(cmpFileName)==0) {
            return true;
        }
    }
    return false;
}

bool cmpFunction(std::string a,std::string b) {
    return strcmp(a.c_str(), b.c_str())<0;
}

std::vector<std::string> FILE_HANDLER::getFileList() {
    std::sort(fileList.begin(), fileList.end(), cmpFunction);
    return fileList;
}