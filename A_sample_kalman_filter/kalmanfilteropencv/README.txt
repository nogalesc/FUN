AUTHOR: CHRIS NOGALES
DATE: 9/21/2015
This small program allows user to hover a mouse over a window and trace its path. Two paths are drawn, 
one path is the original and the other is a kalman filtered path.
I like this example because I used it to learn to use Kalman filter from OpenCV and brush up on the build process.

Reminder:
*Compilation* refers to the processing of source code files (.c, .cc, or .cpp) and the creation of an 'object' file. 
*Linking* refers to the creation of a single executable file from multiple object files.
The total process of going from source code files to an executable might better be referred to as a *build*. 

How to build:

-Wall         = Warn all
-o            = names the executable

$ g++ -Wall -o kalmanfilter kalmanfilter.cpp

(You may need to change permissions of the executable like this)
$ chmod +x kalmanfilter

How to run executable file:
$ ./kalmanfilter

--------USING CMAKE------------
This tutorial:

http://docs.opencv.org/doc/tutorials/introduction/linux_gcc_cmake/linux_gcc_cmake.html#linux-gcc-usage

$ cmake .
$ make
