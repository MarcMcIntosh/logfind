#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

const size_t MAX_BUFFER_SIZE = 1024;

void print_usage ()
{
	printf("[USAGE] ./logfind [-o] [TERM] [TERM] [TERM]\n");
	printf("\tBy default TERMS are used for an and search\n");
	printf("\t-o\t Preform an or seach\n");

}

void print_file(FILE * file)
{
	rewind(file);
	char character;
	while((character = fgetc(file)) != EOF) {
		printf("%c", character);
	}
}

void search_file_for_words(char *file_name, char *words[], int required_matches)
{
	debug("opening file: %s", file_name);
	int total_matches = 0;

	FILE * file = NULL;
	file = fopen(file_name, "r");
	assert(file);
	char * buffer = NULL;
	buffer = calloc(MAX_BUFFER_SIZE, 0);
	while(fgets(buffer, MAX_BUFFER_SIZE - 1, file) != NULL) {
		
		for(int i = 0; words[i]; i++) {
			// debug("Searching %s for instances of: %s", file_name, words[i]);  
			char * word_is_in_buffer = strstr(buffer, words[i]);

			if(word_is_in_buffer) {
				total_matches++;
			}
		}
	}

	free(buffer);
	buffer = NULL;
	
	if(total_matches >= required_matches) {
		debug("### Matches found in file ### %s", file_name);
		print_file(file);
	}
	
}

void files_to_search_from_config() {
	char * buffer = calloc(MAX_BUFFER_SIZE, 0);
	FILE * config_file = NULL;
	
	assert(config_file);	
	
}

int main(int argc, char*argv[])
{
	// check args
	if(argc == 1) { 
		printf("nothing to search forn\n");
		print_usage();
		return 1;
	}

	int has_or_flag = strcmp(argv[1], "-o") ? 0 : 1;
	
	debug("Has or flag: %d", has_or_flag);

	if(has_or_flag && argc == 2) {
		print_usage();
		return 1;
	}

	// Knock undeed words from argv
	debug("Furst argment passed to function: %s", *argv);
	
	argv++;
	if(has_or_flag) { argv++; }

	debug("First word for function: %s", *argv);

	int number_of_matches = (has_or_flag) ? 1 : argc - 1;

	debug("Number of matches required: %d", number_of_matches);

	/* checking print_file works 
	FILE * current_file = fopen("README.md", "r");
	print_file(current_file);
	fclose(current_file);
	free(current_file); */


	// checking search file for words words
	search_file_for_words("README.md", argv, number_of_matches);
	
	files_to_search_from_config();
	
	return 0;
}
