#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage ()
{
	printf("[USAGE] ./logfind [-o] [TERM] [TERM] [TERM]\n");
	printf("\tBy default TERMS are used for an and search\n");
	printf("\t-o\t Preform an or seach\n");

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

}
