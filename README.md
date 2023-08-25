## INSTRUCTIONS

Please note that required to build the software are opencv libraries and headers (tested with opencv 4.8.0, cmake 3.24.3, GNU make 3.81) on Linux or MacOS. Higher-resolution images require lower input values during the calculation (e.g. for an image of resolution 1280x720 pixels, input values between 1 to 10 return a numeric result). When running the program, the window displaying the given image must be closed in order to enter the values.

The following command-line steps build and run the program from its source code directory. 

```console
foo@bar:~$ cmake .
foo@bar:~$ make
foo@bar:~$ ./hucent <path/to/binary/image/file>
```
