#include <assert.h>
#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

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
	unsigned int word_found = 0;
	for (int i = 0; word_found == 0 && i < argc ; i++) {
		word_found += find_word_in_text(argv[i], text);
	}
	
	if (word_found) { printf("%s\n", text); }
}

void find_all_words_and_print_text(int argc, char *argv[], char *text)
{
	unsigned int number_of_words_to_find = argc - 1;
	unsigned int i = 1;
	do {
		number_of_words_to_find -= find_word_in_text(argv[i], text);
		i++;
	} while (i < argc);

	if(number_of_words_to_find == 0) {
		printf("%s\n", text);
	}
}


int main(int argc, char *argv[]) {
	assert(argc > 1);

	// remove this later
	char * text_to_search = "Some foo text";


	int has_or_flag = strcmp(argv[1], "-o");
	if(has_or_flag == 0) {
		assert(argc > 2);
		find_any_word_and_print_text(argc, argv, text_to_search);
	} else {
		find_all_words_and_print_text(argc, argv, text_to_search);
	}

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
