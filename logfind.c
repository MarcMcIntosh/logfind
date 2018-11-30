#include <assert.h>
#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	assert(argc > 1);
	
	char * first_word = argv[1];
	
	char *words_found = NULL;
	words_found = strstr("some foo text to search", first_word);
	
	if(words_found) { printf("Found "); }
	return 0;
	/* FILE * configuration_file = fopen(".logfind", "r");
	assert(configuration_file);
	
	char * log_files[1024];
	fscanf(configuration_file, "%s", log_files);
	assert(log_files);
	// read data from cinfguration file
	fclose(configuration_file);
	return 0;
	*/
}
