# Spring 2025 System Programming — Final Project

## Written Portion

### 1. Describe what happens to memory released by the OS with regard to virtual memory

REPLACE THIS CONTENT WITH YOUR ANSWER

---

### 2. In a C program, why does `argv[argc]` return `NULL`?

REPLACE THIS CONTENT WITH YOUR ANSWER

---

### 3. When a system call is made the CPU changes from user mode to kernel mode. Why?

REPLACE THIS CONTENT WITH YOUR ANSWER

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
