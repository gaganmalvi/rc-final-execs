#!/usr/bin/python3

import os

root_directory = "rounds/final-executables/proprietary/"
dirsRound1 = os.listdir(root_directory + "round-1")
dirsRound2Easy = os.listdir(root_directory + "round-2/easy")
dirsRound2Hard = os.listdir(root_directory + "round-2/hard")
dirsRound2Medium = os.listdir(root_directory + "round-2/medium")

def changePermsToExec(path):
    os.system("chmod a+x " + path)
    return True

for directories in dirsRound1:
    changePermsToExec(root_directory + "round-1/" + directories + "/executables/" + directories + "-linux.lin")

for directories in dirsRound2Easy:
    changePermsToExec(root_directory + "round-2/easy/" + directories + "/executables/" + directories + "-linux.lin")

for directories in dirsRound2Hard:
    changePermsToExec(root_directory + "round-2/hard/" + directories + "/executables/" + directories + "-linux.lin")

for directories in dirsRound2Medium:
    changePermsToExec(root_directory + "round-2/medium/" + directories + "/executables/" + directories + "-linux.lin")
