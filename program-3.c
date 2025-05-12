#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NORMAL        "\033[0m"
#define RESET         NORMAL
#define GREEN         "\033[32m"
#define RED           "\033[31m"
#define BLUE          "\033[34m"

#define FIND_TERM     "Program 3"
#define REPLACE_TERM  "PROGRAM 3"

int main() {
  //Open to read and write
  FILE* readme_file = fopen("README.md", "r+");
  if (readme_file == NULL) {
    perror("Error opening README.md");
    exit(1);
  }

  char line_in_readme[BUFSIZ];

  readme_file->

  while (fgets(line_in_readme, BUFSIZ, readme_file) != NULL) {
    char *position_of_target_in_line = strstr(line_in_readme, FIND_TERM);

    if (position_of_target_in_line == NULL)
      continue;

    printf("Location of %s in line %ld", FIND_TERM, position_of_target_in_line - line_in_readme);
    printf("Location of %s in file %ld", FIND_TERM, position_of_target_in_line - line_in_readme);
    break;

  }

  exit(0);
}
