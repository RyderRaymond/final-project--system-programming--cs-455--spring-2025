#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define NORMAL        "\033[0m"
#define RESET         NORMAL
#define GREEN         "\033[32m"
#define RED           "\033[31m"
#define BLUE          "\033[34m"

#define FIND_TERM     "Program 3"
#define REPLACE_TERM  "PROGRAM 3"
#define BUFFER_SIZE   1024

int main() {
  //Open to read and write
  int readme_file_desc = open("README.md", O_RDWR);
  if (readme_file_desc < 0) {
    perror("Error opening README.md");

    exit(1);
  }

  char line_in_readme[BUFFER_SIZE + 1];
  ssize_t total_bytes_read = 0;
  ssize_t bytes_read;

  while ((bytes_read = read(readme_file_desc, line_in_readme, BUFFER_SIZE)) != 0) {
    if (bytes_read < 0) {
      perror("Error reading README.md");

      exit(2);
    }

    line_in_readme[BUFFER_SIZE] = '\0';

    char *position_of_target_in_line = strstr(line_in_readme, FIND_TERM);

    if (position_of_target_in_line == NULL) {
      total_bytes_read += bytes_read;

      continue;
    }
    else {
      total_bytes_read += position_of_target_in_line - line_in_readme;
    }

    printf("Location of %s in line %ld\n", FIND_TERM, position_of_target_in_line - line_in_readme);
    printf("Location of %s in file %ld\n", FIND_TERM, total_bytes_read);

    break;
  }

  lseek(readme_file_desc, total_bytes_read, SEEK_SET);

  read(readme_file_desc, line_in_readme, strlen(FIND_TERM));
  line_in_readme[strlen(FIND_TERM)] = '\0';
  printf("%s", line_in_readme);

  lseek(readme_file_desc, total_bytes_read, SEEK_SET);
  if (write(readme_file_desc, REPLACE_TERM, strlen(REPLACE_TERM)) < 0) {
    perror("Error writing to README.md");
    exit(3);
  }

  if (close(readme_file_desc) < 0) {
    perror("Error closing README.md");
    exit(4);
  }

  exit(0);
}
