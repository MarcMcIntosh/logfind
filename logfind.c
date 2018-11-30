#include <assert.h>
#include <stdio.h>

int main(int argc) {
	assert(argc > 1);
	FILE * configuration_file = fopen(".logfind", "r");
	assert(configuration_file);
	return 0;
}
