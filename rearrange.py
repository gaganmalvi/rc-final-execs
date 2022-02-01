#!/usr/bin/python3

import os

directories = sorted(os.listdir("round-1"))

copyDirs = directories

platforms = sorted([
    'mac',
    'windows',
    'linux'
])

for n in range(20):
    for i in directories: 
            destpathdir = 'round-1/' + i
            for f in platforms:
                if (f == 'linux'):
                    srcexec = destpathdir + '/executables/' + i + '-' + f
                    destexec = destpathdir + '/executables/' + i + '-' + f + ".lin"
                    print(destexec)
                    os.rename(srcexec, destexec)
                elif (f == 'mac'):
                    srcexec = destpathdir + '/executables/' + i + '-' + f
                    destexec = destpathdir + '/executables/' + i + '-' + f + ".mac"
                    os.rename(srcexec, destexec)
            directories.remove(i)
