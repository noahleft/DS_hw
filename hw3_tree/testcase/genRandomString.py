#!/usr/bin/python
import sys
import random
import string

addFileList=[]
searchFileList=[]

case=int(sys.argv[1])

for index in range(case):
  N=random.randint(5,10)
  strline=''.join(random.choice(string.ascii_uppercase + string.digits + '_') for _ in range(N))
  addFileList.append(strline)
  if random.uniform(0,1)<0.8:
    searchFileList.append(strline)

for index in range(case-len(searchFileList)):
  N=random.randint(5,10)
  strline=''.join(random.choice(string.ascii_uppercase + string.digits + '_') for _ in range(N))
  searchFileList.append(strline)

random.shuffle(addFileList)
random.shuffle(searchFileList)

with file('addFile','w') as outfile:
  for strline in addFileList:
    outfile.write(strline+'\n')

with file('searchFile','w') as outfile:
  for strline in searchFileList:
    outfile.write(strline+'\n')



