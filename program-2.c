#include <stdio.h>
#include <stdlib.h>
//The Linux Programming Interface says it is preferred to get the
//environment this way rather than as an argument to main
extern char **environ;

int main() {
  const int num_named_vars = 3;
  const char * const named_variables_to_get[3] = {"SHELL", "PATH", "USERNAME"};

  for (int i = 0; i < num_named_vars; i++)
    printf("%s: %s\n\n", named_variables_to_get[i], getenv(named_variables_to_get[i]));

  printf("USERNAME was not set for my environment on Fedora Linux, but they were on Ubuntu.\nUSER and LOGNAME were set, so here are their values:\n\n");
  printf("USER: %s\n", getenv("USER"));
  printf("LOGNAME: %s\n", getenv("LOGNAME"));

  printf("\n-----------------------------------------------------------------\n");
  printf("Other information available in environ:\n\n");

  for (char **env = environ; *env != NULL; env++) {
    printf("%s\n", *env);
  }

  return 0;
}
