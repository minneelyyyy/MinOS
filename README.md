# MinOS

## An x86 toy operating system.

This is a hobbyist operating system that is not really an operating system.
I'm learning OS dev, this is essentially just a VGA text mode driver with a main function.

This project will expand as I learn. I am currently reading through Intel manuals and all sorts of tutorials.

# How to build
To compile this project, you are going to need:
 - nasm
 - a GCC x86 cross compiler
 - grub

The easiest way is to run the setup script `scripts/cc-setup.sh`, it's made for Debian but
can be easily converted to any Linux distribution. You're on your own.
You're probably going to want to use WSL to compile on Windows.

1. clone the project
```console
$ git clone https://github.com/minneelyyyy/MinOS.git
$ cd MinOS/
```

2. compile the project
```console
$ make
```
Tip: In order to recompile, use `make clean && make`

3. run
```console
$ sh run.sh # use run.bat on Windows
```

# Resources
Wanna learn OS Dev? Here are a few good resources.

 - [Intel 64 and IA-32 Software Developer's Manual](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html)
 - [OSDev Wiki](https://wiki.osdev.org/Main_Page)
 - [James Molloy](http://www.jamesmolloy.co.uk/tutorial_html/)
   This tutorial uses Multiboot 1, which is not compatbile with Multiboot 2. Use Multiboot 2
 - [Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/) (explains high level concepts)
 - Looking at code from other operating systems