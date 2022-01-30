#!/usr/bin/python3

import os

directories = sorted(os.listdir("test"))
directories.remove(".git")

copyDirs = directories

platforms = sorted([
    'mac',
    'windows',
    'linux'
])

problemDirs = []
for i in range(20):
    problemDirs.append("Problem-" + str(i + 1))

for n in range(20):
    for i in directories: 
        if not os.path.exists('test/' + str(n + 1)):
            sourcepathdir = 'test/' + i
            destpathdir = 'test/' + str(n + 1)
            os.rename(sourcepathdir, destpathdir)
            for f in platforms:
                if (f == 'windows'):
                    srcexec = destpathdir + '/executables/' + i + '-windows.exe'
                    destexec = destpathdir + '/executables/' + str(n + 1) + '-windows.exe'
                    os.rename(srcexec, destexec)
                elif (f == 'linux' or f == 'mac'):
                    srcexec = destpathdir + '/executables/' + i + '-' + f
                    destexec = destpathdir + '/executables/' + str(n + 1) + '-' + f
                    os.rename(srcexec, destexec)
            directories.remove(i)
        else:
            break