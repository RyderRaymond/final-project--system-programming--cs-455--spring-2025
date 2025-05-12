#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h> //For using strtol since it returns LONG_MIN or LONG_MAX on error

//Adding the ### prevents the program from editing instances of "Program 3" that are not
//the heading instance we want to replace
#define FIND_TERM     "### Program 3"
#define REPLACE_TERM  "### PROGRAM 3"

#define BUFFER_SIZE   1024

ssize_t find_target_location_in_file(int file_descriptor);

/** @brief program-3: Finds and replaces the 'Program 3' heading with 'PROGRAM 3'.
 *                    If given the location of the target as a command-line argument, the program
 *                    skips finding 'Program 3' and immediately lseek's to the given location,
 *                    regardless of what content will be replaced.
 *
 * @param argc  Argument count
 * @param argv  Argument vector. Holds location of 'Program 3' if given.
 * @return 0 on status, !0 on failure.
 */
int main(int argc, char *argv[]) {
  //Open to read and write
  const int readme_file_desc = open("README.md", O_RDWR);

  if (readme_file_desc < 0) {
    perror("Error opening README.md");

    exit(1);
  }

  ssize_t location_of_target;

  if (argc == 2) {
    location_of_target = strtol(argv[1], NULL, 10);

    if (location_of_target == LONG_MIN || location_of_target == LONG_MAX) {
      printf("Usage: %s [location_of_target]", argv[0]);

      exit(1);
    }
  }
  else {
    location_of_target = find_target_location_in_file(readme_file_desc);
  }

  if (location_of_target < 0)
    exit(2);

  lseek(readme_file_desc, location_of_target, SEEK_SET);

  char buffer[strlen(REPLACE_TERM) + 1];
  read(readme_file_desc, buffer, strlen(REPLACE_TERM));
  buffer[strlen(REPLACE_TERM)] = '\0';
  printf("Text to be replaced: '%s'\n", buffer);

  lseek(readme_file_desc, location_of_target, SEEK_SET);

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

/** @brief find_target_location_in_file: Finds the location of the target in the file
 *
 * @param file_descriptor File descriptor of the file in which to search
 * @return The location or <0 on error
 */
ssize_t find_target_location_in_file(const int file_descriptor) {
  //Go to the start of the file before searching.
  lseek(file_descriptor, 0, SEEK_SET);

  //Add +1 char space for a null terminator to be added
  char read_buffer[BUFFER_SIZE + 1];
  ssize_t total_bytes_read = 0;
  ssize_t bytes_read;

  while ((bytes_read = read(file_descriptor, read_buffer, BUFFER_SIZE)) != 0) {
    if (bytes_read < 0) {
      perror("Error reading README.md");

      return -1;
    }

    read_buffer[BUFFER_SIZE] = '\0';
    char *position_of_target_in_buffer = strstr(read_buffer, FIND_TERM);

    //Did not find our target, so remember how far we are into the file and continue reading
    if (position_of_target_in_buffer == NULL) {
      total_bytes_read += bytes_read;

      continue;
    }

    //found the target so save its spot in this file for lseek
    total_bytes_read += position_of_target_in_buffer - read_buffer;
    printf("Location of '%s' in file %ld\n", FIND_TERM, total_bytes_read);

    //Set file back to starting location
    lseek(file_descriptor, 0, 0);
    return total_bytes_read;
  }

  printf("Target not in file\n");

  return -1;
}
