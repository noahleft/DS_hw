//
//  fileHandler.h
//  DS_hw3_Tree
//
//  Created by lin shih-feng on 9/12/14.
//  Copyright (c) 2014 lin shih-feng. All rights reserved.
//

#ifndef __DS_hw3_Tree__fileHandler__
#define __DS_hw3_Tree__fileHandler__

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>

class FILE_HANDLER {
private:
    std::vector<std::string> fileList;
    
public:
    void addFileName(std::string);
    bool searchFileName(std::string);
    std::vector<std::string> getFileList();
};

#endif /* defined(__DS_hw3_Tree__fileHandler__) */
