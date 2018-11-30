#include <assert.h>
#include <stdio.h>

int main(int argc) {
	assert(argc > 1);
	FILE * configuration_file = fopen(".errors", "r");
	assert(configuration_file);
	return 0;
}
