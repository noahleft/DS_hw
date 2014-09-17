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
#include <fstream>
using namespace::std;

FILE_HANDLER handler;

bool CompareListResult(string &g,vector<string> &r) {
    string::size_type idx;
    
    unsigned tmpidx=0;
    while (g.size()!=0) {
        idx=g.find(',');
        string cmp_str;
        if (idx!=string::npos) {
            cmp_str=g.substr(0,idx);
            g=g.substr(idx+1);
        }
        else {
            cmp_str=g;
            g="";
        }
        if (tmpidx==r.size()) {
            return false;
        }
        if (cmp_str.compare(r[tmpidx])!=0) {
            return false;
        }
        tmpidx++;
    }
    if (tmpidx!=r.size()) {
        return false;
    }
    return true;
}

int main(int argc, const char * argv[])
{
    cout<<"DS HW3 File system control"<<endl;
    vector<string> seqList;
    fstream infile("testcase",ios::in);
    while (!infile.eof()) {
        string str;
        getline(infile, str);
        seqList.push_back(str);
    }
    
    unsigned no_success=0;
    unsigned no_fail=0;
    
    clock_t start_time,end_time;
    start_time=clock();
    
    fstream checkIn("checkResult",ios::in);
    fstream listIn("listResult",ios::in);
    
    for (unsigned i=0; i<seqList.size(); i++) {
        if (seqList[i][0]=='A') {
            handler.addFileName(seqList[i].substr(2));
        }
        else if (seqList[i][0]=='C') {
            bool tmp_result=handler.searchFileName(seqList[i].substr(2));
            string result;
            getline(checkIn, result);
            if (tmp_result && result[0]=='1') {
                no_success++;
            }
            else if (!tmp_result && result[0]=='0') {
                no_success++;
            }
            else {
                no_fail++;
            }
        }
        else if(seqList[i][0]=='L'){
            vector<string> tmp_result=handler.getFileList();
            string result;
            getline(listIn, result);
            if (CompareListResult(result,tmp_result)) {
                no_success++;
            }
            else {
                no_fail++;
            }
        }
    }
    
    end_time=clock();
    cout<<"Total use  "<<(end_time-start_time)/CLOCKS_PER_SEC<<" secs"<<endl;
    cout<<"Total pass "<<no_success<<" cases and fail "<<no_fail<<" cases"<<endl;
    return 0;
}

