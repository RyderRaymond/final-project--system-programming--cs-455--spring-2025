#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // char *process_name;
  //
  // if (argc == 2)
  //   process_name = argv[1];
  // else
  //   process_name = "top";
  //
  // DIR * proc_dir = opendir("/proc");
  // if (proc_dir == NULL) {
  //   perror("Failed to open /proc");
  //   exit(1);
  // }
  //
  // readdir(proc_dir);

  if (argc != 2) {
    printf("usage: %s: [process_id]", argv[0]);
    exit(1);
  }

  long strtol_result = strtol(argv[1], NULL, 10);
  if (strtol_result < 0 || strtol_result > INT_MAX) {
    printf("usage: %s: [process_id]", argv[0]);
    perror("Invalid process ID");
    exit(1);
  }

  char process_stat_file_path[100] = "/proc/";
  strcat(process_stat_file_path, argv[1]);
  strcat(process_stat_file_path, "/status");

  FILE *proc_status = fopen(process_stat_file_path, "r");
  if (proc_status == NULL) {
    perror("Failed to open process status file");
    exit(2);
  }

  char process_name[100];
  char process_parent_name;
  char process_PPID;

  //1. Get name of this process
  //2. Get PPID for this process
  //3. Get name of parent process (/proc<ppid>/status);

  
  exit(0);
}