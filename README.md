# Operating-Systems (CS - 253)<br>
This repository contains practical programs for the OS Lab course. Each folder contains the programs for the respective practical along with the relevant Lab details (installations, methods etc).

# Table of Contents 
- [Lab 1](https://github.com/hydro-7/Operating-Systems/blob/main/README.md#lab-1--running-xv6-and-making-copy-cp--program-state-ps-programs)
  - [Installation](https://github.com/hydro-7/Operating-Systems/blob/main/README.md#installation)
  - [cp.c](https://github.com/hydro-7/Operating-Systems/blob/main/README.md#program-1)
  - [ps.c]()
- [Lab 2](https://github.com/hydro-7/Operating-Systems?tab=readme-ov-file#lab-2--run-programs-using-an-fcfs-scheduling-algorithm)
  - [Introduction](https://github.com/hydro-7/Operating-Systems?tab=readme-ov-file#introduction-)
  - [Method](https://github.com/hydro-7/Operating-Systems?tab=readme-ov-file#method-)
- [Lab 3](https://github.com/hydro-7/Operating-Systems/blob/main/README.md#lab-3--implement-scheduling-algorithms-in-c)
  - [Task](https://github.com/hydro-7/Operating-Systems?tab=readme-ov-file#task-)
- [Lab 4](https://github.com/hydro-7/Operating-Systems/blob/main/README.md#lab-4--implement-scheduling-algorithms-in-c-preemptive)
  - [Task](https://github.com/hydro-7/Operating-Systems/blob/main/README.md#task--1)


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

 ## Program 2
- Task : Implement the Process State command as "ps.c" and then include it in the XV6 OS and use it to view the processes running on wsl currently.
- Follow the tutorial [Tutorial Link](https://medium.com/@harshalshree03/xv6-implementing-ps-nice-system-calls-and-priority-scheduling-b12fa10494e4).
- Some Corrections/Improvements to the above tutorial :
  - After opening your wsl, complete the first step and in the "proc.h" file, move down to the "proc" structure and add ```int priority``` to a new line in it.
  - In one of the steps in the tutorial it says "users.h", but it is "user.h"
- On completing the tutorial, run ```$ make qemu-nox``` to run XV6.
- Within it, run the ```$ ps``` command, it should give you a result similar to this :
  ![WhatsApp Image 2025-01-23 at 14 44 49_b76d97c1](https://github.com/user-attachments/assets/884c86c6-56ac-479f-bac9-3203ba23ce38)



# Lab 2 : Run programs using an FCFS Scheduling Algorithm 

## Introduction :
In XV6, the default scheduling algorithm is **Round Robin**, which we will change to **FCFS** (First Come First Serve) and then compare how they execute processes using a testing file. We do this by making changes within the **proc.c** file.

## Method :
- Within the scheduler function, the for(;;) represents an infinite loop which constantly runs the prcoesses, within this acquire(&ptable.lock) gets the table of processes, using which we apply the respective scheduling algorithm.
- Using an if else condition, make a toggle selection for selecting either Default or FCFS.
- Within the **proc\*** structure, add the line ```$ p -> ctime = ticks``` to keep a track of the process creation time.
- But to use the ticks counter, you need to add ```$ int ctime, etime, rtime, iotime``` to the **proc** structure in the **proc.h** file.
- Now to test the schedulers, we make a test_FCFS file (which we add to the Makefile similar to Lab 1), which prints the pid and iteration number for that particular process.
- Observe the difference between the FCFS & Round Robin Schedulers.
- For further ref : [Link](https://github.com/Akshat-Goyal/Customized-xv6-OS/blob/master/xv6/proc.c)


# Lab 3 : Implement Scheduling Algorithms in C (Non - Preemptive)

## Task : 
We need to implement the following Non - Preemptive Scheduling Algorithms : **FCFS** (First Come First Serve), **SJF** (Shortest Job First), **LJF** (Longest Job First), **HRRN** (Highest Response Ratio Next).

# Lab 4 : Implement Scheduling Algorithms in C (Preemptive)

## Task : 
We need to implement the following Preemptive Scheduling Scheduling Algorithms : **RR** (Round Robin), **PS** (Priority Scheduling), **SRTF** (Shortest Remaining Time First), **LRTF** (Longest Remaining Time First)

# Lab 5 : Implement Shared Memory for Producer Consumer problem 

## Introduction : 
There are two fundamental models of interprocess communication : i) Shared Memory Syetms ii) Message Passing. 

In the shared memory model, a region of memory that is shared by cooperating processes is established. Processes can then exchange information by reading and writing data to the shared region.

The process which wishes to communicate creates the shared memory segment within its memory and and process that wishes to recieve information from it attaches the memory to it's address space. Here, one common example where this shared memory is used is the Producer and Consumer problem. 

To allow the producer and consumer processes to run concurrently, we must have a buffer that can be filled by the producer and emptied by the consumer. In general, these buffers can be classified into two types : i) Unbounded Buffer ii) Bounded Buffer

The unbounded buffer has no limit on the buffer size, which means the producer can endlessly produce items. The bounded buffer has a finite limit on the size such that the producer must wait for consumption before pushing if the buffer is full.

