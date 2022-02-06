#!/usr/bin/python3

import os

root_directory = "rounds/final-executables/proprietary/"
dirsRound2Easy = os.listdir(root_directory + "round-2")

def changePermsToExec(path):
    os.system("chmod a+x " + path)
    return True
'''
for directories in dirsRound1:
    changePermsToExec(root_directory + "round-1/" + directories + "/executables/" + directories + "-linux.lin")
    changePermsToExec(root_directory + "round-1/" + directories + "/executables/" + directories + "-mac.mac")
'''
for directories in dirsRound2Easy:
    changePermsToExec(root_directory + "round-2/" + directories + "/executables/" + directories + "-linux.lin")
    changePermsToExec(root_directory + "round-2/" + directories + "/executables/" + directories + "-mac.mac")

#for directories in dirsRound2Easy:
 #   changePermsToExec(root_directory + "round-2/Easy/" + directories + "/executables/" + directories + "-linux.lin")
  #  changePermsToExec(root_directory + "round-2/hard/" + directories + "/executables/" + directories + "-mac.mac")

#for directories in dirsRound2Medium:
 #   changePermsToExec(root_directory + "round-2/medium/" + directories + "/executables/" + directories + "-linux.lin")
  #  changePermsToExec(root_directory + "round-2/medium/" + directories + "/executables/" + directories + "-mac.mac")
