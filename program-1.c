#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

/** @brief program-1: Takes in a PID (process ID) and prints the process' PPID
 *                    and some other information.
 *
 *                    To use with the 'top' program in particular, run top in a separate
 *                    terminal, use ps -el | grep 'top' to get the PID and run this
 *                    program with that PID as an argument.
 *
 *
 * @param argc  number of arguments: must be 2: the name of this program (given by system) and a PID (given by user)
 * @param argv  argument vector
 * @return      0 on success and !0 on failure
 */
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("usage: %s <process_id>\n", argv[0]);
    printf("%s: Missing PID to get PPID\n", argv[0]);
    exit(1);
  }

  //Make sure PID is all digits
  const char *character_in_PID_argument = argv[1];

  while (*character_in_PID_argument != '\0') {
    if (!isdigit(*character_in_PID_argument++)) {
      printf("%s: Invalid PID\n", argv[0]);
      exit(2);
    }
  }

  //Get file path for this PID status file
  char process_status_file_path[100] = "/proc/";
  if (strlen(process_status_file_path) + strlen(argv[1]) + strlen("/status") > 100) {
    printf("Process number too large");
    exit(3);
  }
  strcat(process_status_file_path, argv[1]);
  strcat(process_status_file_path, "/status");

  FILE *process_status_file = fopen(process_status_file_path, "r");
  if (process_status_file == NULL) {
    printf("Failed to open process status file: %s\n", process_status_file_path);
    printf("Likely that no process with this PID exists\n");
    exit(4);
  }

  char process_name[100];
  char process_parent_name[100];
  char process_PPID[100];
  char line_in_file [BUFSIZ]; //we will read line by line

  //Read up through line 7
  //Line 1 is the process name of the PID given as an argument
  //Line 7 is the PPID of the given PID
  for (int i = 1; i <= 7; i++) {
    if (fgets(line_in_file, 100, process_status_file) == NULL) {
      perror("Failed to read from process status file");
      exit(5);
    }

    switch (i) {
      case 1:
        const char *name = strstr(line_in_file, "\t");
        name++; //right after the tab is the content for each field
        strcpy(process_name, name);
        process_name[strlen(process_name) - 1] = '\0'; //replace newline character with terminator
        break;
      case 7:
        const char* ppid = strstr(line_in_file, "\t");
        ppid++;
        strcpy(process_PPID, ppid);
        process_PPID[strlen(process_PPID) - 1] = '\0';
        break;
    }
  }

  printf("The PPID for process named '%s' is %s\n", process_name, process_PPID);

  if (fclose(process_status_file) != 0) {
    perror("Failed to close process stat file");
    exit(6);
  }

  //Now we get the name of the parent process
  char process_parent_status_file_path[100] = "/proc/";
  strcat(process_parent_status_file_path, process_PPID);
  strcat(process_parent_status_file_path, "/status");

  FILE *parent_process_status_file = fopen(process_parent_status_file_path, "r");
  if (parent_process_status_file == NULL) {
    perror("Failed to open parent process status file");
    exit(7);
  }

  if (fgets(line_in_file, 100, parent_process_status_file) == NULL) {
    perror("Failed to get parent process' name");
    exit(8);
  }

  const char* name = strstr(line_in_file, "\t");
  name++;
  strcpy(process_parent_name, name);
  process_parent_name[strlen(process_parent_name) - 1] = '\0';

  printf("Name of parent process is '%s'\n", process_parent_name);

  if (fclose(parent_process_status_file) != 0) {
    perror("Failed to close parent process status file");
    exit(9);
  }

  exit(0);
}
