#!/usr/bin/python
with file('testcase','r') as infile:
  strlines=infile.readlines()

strlines=list(map(lambda x:x.replace('\n',''),strlines))

fileList=[]

outfile=file('checkResult','w')
outfile2=file('listResult','w')

for strline in strlines:
  if strline[0]=='A':
    fileList.append(strline[2:])
  elif strline[0]=='C':
    outfile.write(str(int(strline[2:] in fileList))+'\n')
  else:
    outfile2.write(','.join(sorted(fileList))+'\n')
