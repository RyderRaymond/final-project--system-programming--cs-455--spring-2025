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

The second reason is just in case the process attempts to access argv[argc], as if it was not NULL, 
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

REPLACE THIS CONTENT WITH YOUR ANSWER

---

### 5. Consider the following C program. The variables and functions get allocated to which memory segments? Write your answers in comments to the right of each item

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 128

char my_string[MAX];
char class_name[] = "System Programming";
int global_integer = 3;

void print_global() {
  printf("%d\n", global_integer);
}

int square(int x) {
  int result = x * x;

  return result;
}

int main (int argc, char *argv[]) {
  char *dynamic_memory;
  dynamic_memory = malloc(MAX);
  free(dynamic_memory);
  dynamic_memory = NULL;

  return 0;
}
```

---

### 6. Explain the difference between `malloc`, `calloc`, `realloc`

REPLACE THIS CONTENT WITH YOUR ANSWER

---

### 7. Explain the difference between `brk` and `sbrk`. Why is `malloc` a better option of `brk`, and `sbrk`?

REPLACE THIS CONTENT WITH YOUR ANSWER

---

### 8. Explain why a shadow password file is needed

REPLACE THIS CONTENT WITH YOUR ANSWER

---

### 9. What is the numeric equivalent of the `README.md` file’s permission bits below, and what is the command to give the file full access, across the board?

```sh
-rw-r--r-- 1  johnnythunders  staff  3476 May  1 11:57 README.md
```

REPLACE THIS CONTENT WITH YOUR ANSWER

---

### 10. What does `kill -9 1` do? Explain in detail

REPLACE THIS CONTENT WITH YOUR ANSWER
