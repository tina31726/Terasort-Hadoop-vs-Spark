Shared memory

To mount EBS volume disk, after creating instance, do following steps, take i3.large instance as exmple
1. lsblk
2. sudo mkfs -t ext4 /dev/nvme0n1
3. sudo mkdir /data
4. sudo mount /dev/nvme0n1 /data
5. df -h
6. now /data has 414GB disk available
We can generate data and run sorting program in /data

Before run progam, do following in instance
1. sudo apt-get update
2. sudo apt install gcc

copy gensort and valsort to /data disk, and do following in /data disk to generate data:
1. ./gensort -a <number of records> test 

compile and run file in /data disk
1. sudo gcc -pthread main.c -o main -lm
2. sudo gcc sort.c -o sort -lm
3. sudo gcc merge.c -o merge -lm
4. sudo ./main

* And we also provide makefile and sh file for easir compile and execution:
1. locate to the folder in Terminal;	
2. run the bash script file run.sh using command:
sh run.sh

To generate sorting:
1. ./valsort output





