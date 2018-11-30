#include <assert.h>
#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

void find_word_in_text(char * word, char * text)
{
	assert(word);
	assert(text);
	char * word_found = NULL;
	word_found = strstr(text, word);
	if (word_found) {
		printf("%s\n", text);
	}
}

int main(int argc, char *argv[]) {
	assert(argc > 1);


	// char * first_word = argv[1];
	
	char * text_to_search = "Some foo text";
	// char *words_found = NULL;
	find_word_in_text(argv[1], text_to_search);
	//int word_found = find_word_in_text(first_word, text_to_search);
	
	// Words anded to gether
	char * anded = NULL;
	anded = strstr(text_to_search, "foo text");
	if(anded) { printf("Added should not have worked"); }

	
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
