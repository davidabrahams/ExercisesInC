## Homework 3

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

[Here is a link to the ex03 directory in my repository](https://github.com/davidabrahams/ExercisesInC/tree/master/exercises/ex03)


### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically true about files systems but not true of their implementations.

That there is a hierarchical structure to file systems. For example, all files are a parent of "/". On a HDD, there is no natural hierarchical structure, all data is layed out sequentially (in some order).

2) What information do you imagine is stored in an `OpenFileTableEntry`?

Perhaps a pointer to where in the file we are reading? Maybe some of the data pre-buffered? TBH, this part of the reading was a bit confusing to me. I read it a few times, and still didn't feel like I had a good grasp of what the OpenFileTableEntry is. Would love clarification here!

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

When writing to a file, write to RAM and wait to dump content to the disk all in one go. Also, cache recently used blocks in case they must be accessed again.

4) Suppose your program writes a file and prints a message indicating that it is done writing. Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the file you wrote is not there.  What happened?

Might have been buffered (so, not actually written, just stored in RAM to be written later?)

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

FAT seems closer to the abstracted version of the FS, so might be easier on the programmer who writes the OS? Honestly not sure. I Googled for like 10 minutes, seems like inodes make things easier to recover. Didn't really understand the explanation though.

6) What is overhead?  What is fragmentation?

Overhead is the memory used by the allocator (not actual data in the FS). Fragmentation is when blocks are partially used, and no longer usable for new data.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

Makes reading files and reading user input easy, because they're the same thing. It can be weird because users can enter "EOF" characters, which doesn't really make intuitive sense.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).
=======
