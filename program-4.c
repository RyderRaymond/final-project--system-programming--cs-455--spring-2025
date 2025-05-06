#include <stdlib.h>
#include <stdio.h>

#define NORMAL        "\033[0m"
#define RESET         NORMAL
#define GREEN         "\033[32m"
#define RED           "\033[31m"
#define BLUE          "\033[34m"

extern char etext;
extern char edata;
extern char end;

int main() {
	char *allocated_string = malloc(1024);	//The pointer will be stored in the stack, the 1024 bytes in the heap
	static int something_initialized = 7;				//This will be stored in the initialized data segment
	static int something_uninitialized;					//This will be stored in the uninitialized data segment

	printf("Memory address of something_uninitialized: %p\n", &something_uninitialized);
	printf("End of something_uninitialized: %s%p%s\n", GREEN, &something_uninitialized + 1, NORMAL);
	printf("Memory address of something_initialized: %p\n", &something_initialized);
	printf("End of something_initialized: %s%p%s\n", RED, &something_initialized + 1, NORMAL);

	printf("Address of etext (end of text segment): %s%p%s\n", BLUE, &etext, NORMAL);
	printf("Address of edata (end of initialized data segment): %s%p%s\n", RED, &edata, NORMAL);
	printf("Address of end (end of uninitialized data segment): %s%p%s\n", GREEN, &end, NORMAL);
	
	//Free the string we allocated earlier
	free(allocated_string);
	allocated_string = NULL;

  return 0;	
}
