# Operating-Systems (CS - 253)<br>
This repository contains practical programs for the OS Lab course. Each folder contains the programs for the respective practical along with the relevant Lab details (installations, methods etc).

# Table of Contents 
- [Lab 1](https://github.com/hydro-7/Operating-Systems/blob/main/README.md#lab-1--running-xv6-and-making-copy-cp--program-state-ps-programs)
  - [Installation](https://github.com/hydro-7/Operating-Systems/blob/main/README.md#installation)
  - [cp.c](https://github.com/hydro-7/Operating-Systems/blob/main/README.md#program-1)
  - [ps.c]()
- Link2
- Link3

# Lab 1 : Running XV6 and Making Copy (cp) & Program State (ps) programs

## Installation
In this Lab, we write programs on the XV6 Operating System (which is a re-implementation of the UNIX OS). To do this we need to configure XV6 onto our local system. To run XV6 on Windows Systems, follow the commands :
  1) Install WSL (Windows Subsystem for Linux)
      - Open Command Prompt (Win + R > cmd)
      - Type the command ```$ wsl --install```
      - By default, this installs the Ubuntu distro for WSL
      - Follow the steps being prompted and fill a valid username & password
      - After WSL installation, the system needs to be rebooted
        
  2) Run the Windows Subsystem using ```$ wsl```

  3) Run ```$ sudo apt update``` to update the list of available packages and their versions on a Linux system|

  4) Run ```$ sudo apt upgrade``` to download and install available updates for all currently installed packages on your system

  5) Run ```$ sudo apt install git build-essential qemu-system``` to make XV6

  6) Clone the XV6 repo for installation using ```$ git clone https://github.com/mit-pdos/xv6-public```

  7) Enter the xv6-public repository using ```$ cd xv6-public```

  8) Finally to run XV6 using ```$ make qemu-nox```
     - In case of errors :
       - ```$ nano Makefile```
       - Go to line 78 and remove "-Werror" from the line
       - Re-run the make command

## Program 1
- Task : Implement the copy command as "cp.c" and then include it in the XV6 OS and use it to copy file contents.
- Implement the cp.c program using ```$ vi cp.c```
  - Note that regular C programming commands won't work as this is XV6. It has only a few libraries so can't use header files like <stdio.h>
- After implementation of the C file, add it to the Makefile :
  - ```$ nano Makefile```
  - In the list of UPROGS, add "_cp\" under the other programs. Ensure that there is a blank line after insertion (Similar to how it was before insertion)
  - In the list of EXTRA, add "cp.c" beside the other .c files. Ensure that the spacing is maintained

# Lab 2
