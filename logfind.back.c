#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const size_t MAX_LINE_SIZE = 1024;

int find_word_in_text(char * word, char * text)
{
	assert(word);
	assert(text);
	char * word_found = NULL;
	word_found = strstr(text, word);
	/* if (word_found) {
		printf("%s\n", text);
	} */
	return word_found ? 1 : 0;
}

void find_any_word_and_print_text(int argc, char *argv[], char *text)
{
	unsigned int number_of_words_found = 0;
	unsigned int i = 1;
	int limit = 1;
	do {
		number_of_words_found += find_word_in_text(argv[i], text);
		i++;
	} while (number_of_words_found < limit && i < argc);
	
	if (number_of_words_found == limit) {
		printf("%s\n", text);
	}
}

void find_all_words_and_print_text(int argc, char *argv[], char *text)
{
	unsigned int number_of_words_found = 0;
	unsigned int i = 1;
	int limit = argc - 1;
	do {
		number_of_words_found += find_word_in_text(argv[i], text);
		i++;
	} while (number_of_words_found < limit && i < argc);

	if(number_of_words_found == limit) {
		printf("%s\n", text);
	}
}

int main(int argc, char *argv[]) {
	assert(argc > 1);
	
	// FILE * configuration_file = fopen(".logfind", "r");
	// assert(configuration_file);
	

	// remove this later
	int has_or_flag = strcmp(argv[1], "-o") ? 1 : 0;
	
	if(has_or_flag == 0) { assert(argc > 2); }

	// char * text_to_search = "Some foo text";
	
	char * text_buffer = calloc(MAX_LINE_SIZE, 1);
	FILE * hard_coded_file = NULL;
	int required_matches = (has_or_flag == 0) ? argc - 1 : 1;
	int total_matches = 0;

	hard_coded_file = fopen("README.md", "r");
	assert(hard_coded_file);

	while(fgets(text_buffer, MAX_LINE_SIZE-1, hard_coded_file) != NULL) {
		printf("Has or flag: %d\n", has_or_flag);
		printf("current word %s", argv[has_or_flag + 1]);
		for(int i = has_or_flag + 1; i < argc; i++) {
			printf("Searching for %s\n", argv[i]);
			char * found = strstr(text_buffer, argv[i]);
			if(found) {
				total_matches++;
			} 
		}
	}

	printf("total matches: %d\t, required: %d\n", total_matches, required_matches);
	if(total_matches >= required_matches) {
		char character;
		while((character = fgetc(hard_coded_file)) != EOF) {
			printf("%c", character);
		}
	}

	fclose(hard_coded_file);

/*

	if(has_or_flag == 0) {
		// assert(argc > 2);
		find_any_word_and_print_text(argc, argv, text_to_search);
	} else {
		find_all_words_and_print_text(argc, argv, text_to_search);
	}

*/
	// char *words_found = NULL;
	
	/* unsigned int word_count = argc - 1;
	int i = 1;
	do {
		printf("Searching for %s\n", argv[i]);
		word_count -= find_word_in_text(argv[i], text_to_search);
		i++;
	} while (i < argc);

	if(word_count == 0) {
		printf(text_to_search);
	} */



	// find_word_in_text(argv[1], text_to_search);
	//int word_found = find_word_in_text(first_word, text_to_search);
	
	// Words anded to gether
	// char * anded = NULL;
	// anded = strstr(text_to_search, "foo text");
	// if(anded) { printf("Added should not have worked"); }

	
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
