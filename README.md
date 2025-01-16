# Operating-Systems (CS - 253)<br>
This repository contains practical programs for the OS Lab course. Each folder contains the programs for the respective practical along with the relevant Lab details (installations, methods etc).

# Table of Contents 
- Link1
  - Sublink 1
  - Sublink 1 1
  - Sublink 1 2
- Link2
- Link3

# Lab 1 
In this Lab, we write programs on the XV6 Operating System (which is a re-implementation of the UNIX OS). To do this we need to configure XV6 onto our local system. To run XV6 on Windows Systems, follow the commands :
  1) Install WSL (Windows Subsystem for Linux)
      - Open Command Prompt (Win + R > cmd)
      - Type the command ```$ wsl --install```
      - By default, this installs the Ubuntu distro for WSL
      - Follow the steps being prompted and fill a valid username & password
      - After WSL installation, the system needs to be rebooted
  2) Run the Windows Subsystem using ```$ wsl```
  3) Run ```$ sudo apt update``` to update the list of available packages and their versions on a Linux system
  4) Run ```$ sudo apt upgrade``` to download and install available updates for all currently installed packages on your system
  5) Run ```$ sudo apt install git build-essential qemu-system``` to make XV6
  6) Clone the XV6 repo for installation using ```$ git clone https://github.com/mit-pdos/xv6-public```
  7) Enter the xv6-public repository using ```$ cd xv6-public```
  8) Finally to run XV6 using ```$ make qemu-nox```
     - In case of errors :
       - ```$ nano Makefile```
       - Go to line 78 and remove "-Werror" from the line
       - Re-run the make command


# Lab 2
