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
      - Type the command **_$ wsl --install_**
      - By default, this installs the Ubuntu distro for WSL
      - Follow the steps being prompted and fill a valid username & password
      - After WSL installation, the system needs to be rebooted
  2) Run the Windows Subsystem using **_$ wsl_**
  3) Run **_$ sudo apt update_** to update the list of available packages and their versions on a Linux system
  4) Run **_$ sudo apt upgrade_** to download and install available updates for all currently installed packages on your system
  5) Run **_$ sudo apt install git build-essential qemu-system_** to make XV6
  6) Clone the XV6 repo for installation using **_$ git clone https://github.com/mit-pdos/xv6-public_**
  7) Enter the xv6-public repository using **_$ cd xv6-public_**
  8) Finally to run XV6 using **_$ make qemu-nox_**
     - In case of errors :
       - **_$ nano Makefile_**
       - Go to line 78 and remove "-Werror" from the line
       - Re-run the make command


# Lab 2
