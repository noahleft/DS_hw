//
//  main.cpp
//  DS_hw3_Tree
//
//  Created by lin shih-feng on 9/12/14.
//  Copyright (c) 2014 lin shih-feng. All rights reserved.
//

#include <iostream>
#include "fileHandler.h"
#include <ctime>
using namespace::std;

FILE_HANDLER handler;

int main(int argc, const char * argv[])
{
    cout<<"DS HW3 File system control"<<endl;
    vector<string> exampleInput;
    vector<string> exampleCheck;
    vector<string> compareList;
    
    exampleInput={"Captain_Kirk","Enterprise","Commander_Spock","battleship","starTrek"};
    exampleCheck={"HAL","Clock","battleship","Major_Tom","Space_Odyssey"};
    
    compareList=exampleInput;
    for (unsigned i=0; i<compareList.size(); i++) {
        for (unsigned j=i+1; j<compareList.size(); j++) {
            if (strcmp(compareList[i].c_str(), compareList[j].c_str())>0) {
                swap(compareList[i], compareList[j]);
            }
        }
    }
    
    clock_t start_time,end_time;
    start_time=clock();
    
    for (unsigned i=0; i<exampleInput.size(); i++) {
        handler.addFileName(exampleInput[i]);
        cout<<"Add file:"<<exampleInput[i]<<endl;
    }
    
    for (unsigned i=0; i<exampleCheck.size(); i++) {
        if (handler.searchFileName(exampleCheck[i])==true) {
            cout<<"Check file:"<<exampleCheck[i]<<" exists"<<endl;
        }
        else {
            cout<<"Check file:"<<exampleCheck[i]<<" doesn't exist"<<endl;
        }
    }
    
    vector<string> fileList;
    bool checkPass=true;
    fileList=handler.getFileList();
    if (fileList.size()!=compareList.size()) {
        cout<<"List file: unequal size"<<endl;
        checkPass=false;
    }
    else {
        for (unsigned i=0; i<fileList.size(); i++) {
            if (strcmp(fileList[i].c_str(), compareList[i].c_str())!=0) {
                cout<<"List file: fail"<<endl;
                checkPass=false;
                break;
            }
        }
    }
    if (checkPass) {
        cout<<"List file: success"<<endl;
    }
    
    end_time=clock();
    cout<<"Total use "<<(end_time-start_time)/CLOCKS_PER_SEC<<" secs"<<endl;
    return 0;
}

