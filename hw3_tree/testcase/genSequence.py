#!/usr/bin/python
import random

with file('addFile','r') as infile:
  addFileList=infile.readlines()

with file('searchFile','r') as infile:
  searchFileList=infile.readlines()

num=len(addFileList)+len(searchFileList)

addFileIndex=0
searchFileIndex=0

outfile=file('testcase','w')

for index in range(num/4):
  if random.uniform(0,1)<0.8 and addFileIndex<len(addFileList):
    outfile.write('A,'+addFileList[addFileIndex])
    addFileIndex+=1
  else:
    outfile.write('C,'+searchFileList[searchFileIndex])
    searchFileIndex+=1
  if random.uniform(0,1)<0.01:
    outfile.write('L\n')

for index in range(num/4,num/4*3):
  if random.uniform(0,1)<0.5 and addFileIndex<len(addFileList):
    outfile.write('A,'+addFileList[addFileIndex])
    addFileIndex+=1
  else:
    outfile.write('C,'+searchFileList[searchFileIndex])
    searchFileIndex+=1
  if random.uniform(0,1)<0.1:
    outfile.write('L\n')

for index in range(num/4*3,num):
  if random.uniform(0,1)<0.3 and addFileIndex<len(addFileList):
    outfile.write('A,'+addFileList[addFileIndex])
    addFileIndex+=1
  else:
    outfile.write('C,'+searchFileList[searchFileIndex])
    searchFileIndex+=1
  if random.uniform(0,1)<0.2:
    outfile.write('L\n')

