# Spring 2025 System Programming — Final Project

## Written Portion

### 1. Describe what happens to memory released by the OS with regard to virtual memory

When memory is released by the OS, with regard to virtual memory, what happens is that an entire page of storage in RAM is freed
to be used for other processes. In virtual memory, a process' memory layout is stored in RAM
as a set of pages, which is a determined size or unit of storage. When a process is loaded into RAM,
the OS loads pages of the program code into RAM as they are needed, placing them in any free page slot.
When the OS releases some memory from a process, the OS will free the page in RAM and allow
other processes to store a page in that location in RAM. This could happen if the process terminates
completely, in which case the OS would set all of its pages as free in RAM, or similarly if the process
simply requires less storage due to freeing some large objects stored in the heap or requiring less
of the code to be loaded into RAM, in which case only the corresponding pages in RAM would be freed.

---

### 2. In a C program, why does `argv[argc]` return `NULL`?

argv[argc] returns NULL for two reasons. 

The first reason is that it is useful for looping through
the list of arguments. For instance, rather than using a for loop from 1 to argc - 1 to access
the values in argv, it is simpler and more efficient to create a pointer to the first element
of argv and then increment this pointer in a while loop until we reach the NULL pointer. 

The second reason is just in case the process attempts to access argv[argc], because if it was not NULL, 
the process would be accessing unknown memory. Since off-by-one errors are very common, it is a 
good safety feature to have. 

---

### 3. When a system call is made the CPU changes from user mode to kernel mode. Why?

The CPU changes from user mode to kernel mode when a system call is made because the system call will
require accessing kernel memory, which is protected from the regular user. The system call may require 
using other kernel-level functions or services, or reading or writing protected kernel-level files, for example. 
These services must be protected from the user, as the user may have malicious intent
or would simply misuse the services out of ignorance, so requiring the user to access
these services through a system call as an interface allows the kernel to more strictly determine 
how the service should be used to prevent misuse. 

---

### 4. Explain the relationship between the return value of a system call and the global variable `errno`

The relationship between the return value of a system call and the global variable 'errno' is that when the return
value of a system call is that of an error value, the system call will have set 'errno' to some value that
explains the error that the system call encountered. If the system call does not return a value that represents an error, 
the system call will have most likely not changed the value of 'errno', so the program should not check 'errno' as its value
will be explaining the error encountered by the last failed system call, not the current one. For instance, if a call to 
'open' fails because the file does not exist and the flag to create the file is not set, then 'open' will return some negative value
and set 'errno' to the value that represents the file not being found. 

---

### 5. Consider the following C program. The variables and functions get allocated to which memory segments? Write your answers in comments to the right of each item

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 128                             //Symbolic constants not stored but rather replaced in preprocessing with its defined value

char my_string[MAX];                        //Uninitialized data segment
char class_name[] = "System Programming";   //Initialized data segment
int global_integer = 3;                     //Initialized data segment

void print_global() {                       //Function instructions allocated to text segment
  printf("%d\n", global_integer);
}

int square(int x) {                         //Function allocated to text segment; Parameter allocated to stack frame for 'square()'
  int result = x * x;                       //Allocated in stack frame for 'square()'

  return result;                            //Passed in register to calling function
}

int main (int argc, char *argv[]) {         //Function 'main' stored in text segment. 'argc', 'argv' stored in stack frame for 'main()'
  char *dynamic_memory;                     //Pointer stored in stack frame for 'main()'
  dynamic_memory = malloc(MAX);             //Memory allocated using 'malloc' stored in heap, pointer stored in variable 'dynamic_memory' in stack
  free(dynamic_memory);                    
  dynamic_memory = NULL;                    

  return 0;                                 //Return value passed to calling function in a register
}
```

---

### 6. Explain the difference between `malloc`, `calloc`, `realloc`

Malloc allocates dynamic memory on the heap of the size of bytes given to it and returns 
a pointer to the newly allocated memory. This memory is not initialized and is only the size
that is given.

Calloc is like malloc, but rather than allocating memory on the heap for one item, it 
allocates memory for an array of items of the same type. It takes in the size of a single item
and the number of items as an argument, and unlike malloc, it initializes the newly allocated 
memory to 0. 

Realloc does not allocate memory for a new item or an array of new items, but instead attempts
to resize the memory allocated to an existing item from a previous call to malloc or calloc. 
If realloc is able to allocate the requested new size, then the data in the existing block
of memory is moved to the new location if realloc could not simply extend the existing block to 
the requested size.

---

### 7. Explain the difference between `brk` and `sbrk`. Why is `malloc` a better option of `brk`, and `sbrk`?

'brk' and 'sbrk' both move the program break (the size of the heap) to a new location. The 
difference is that brk sets the program break to a specific location that it is given as an argument,
whereas sbrk increases the size by an increment. 

Malloc is a better option of brk and sbrk for a few reasons: 

1. The first is that it allows the program to hold blocks of data even after a call to 'free', to avoid having to keep using the 
    system calls to readjust the heap size. This improves performance, as system calls have some
    overhead due to switching into kernel mode and back to user mode. 
2. It makes it easier to handle allocating memory. For instance, it is easy to test a failed call to
    malloc by checking if a NULL pointer is returned, and it is easy to pass a pointer returned
    by malloc to 'free' to handle deallocating the memory than manually moving the program break.
3. It is part of the C standard library, promoting cross-platform compatibility, and allows for use with other malloc family functions like 
    free and realloc. 

---

### 8. Explain why a shadow password file is needed

A shadow password file is needed because the /etc/passwd file holds password-related information
that must be readable by non-privileged programs, such as the username, home directory, and
login shell. If non-privileged programs are allowed to read the encrypted password for a user,
it allows for potentially malicious programs to attempt password-cracking techniques like 
dictionary attacks, comparing these encrypted passwords to other cracked encrypted passwords 
to attempt to find a match, or even brute-force attacks. Moving the encrypted password to the 
shadow file and requiring privileged access prevents potentially untrusted programs from 
accessing the file and reading the encrypted passwords. 

---

### 9. What is the numeric equivalent of the `README.md` file’s permission bits below, and what is the command to give the file full access, across the board?

```sh
-rw-r--r-- 1  johnnythunders  staff  3476 May  1 11:57 README.md
```

The numeric equivalent of the README file's permission bits is '644'. 

The command to give full file access is `chmod 777`, which sets the permission bits to `-rwxrwxrwx`.

---

### 10. What does `kill -9 1` do? Explain in detail

`kill -9 1` sends the `SIGKILL` signal to the process with PID 1, which is either 'init' or 'systemd' 
depending on the operating system. When run as a regular user, bash notifies the user that this 
operation is not permitted, as the init or systemd process cannot be killed. If run as a superuser, 
the command goes through, but nothing happens, again because the initializing process cannot be killed.
