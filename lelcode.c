#include <stdio.h>
#include "tokenizer.c"

int main(int argc, const char *argv[]) {
	if(argc < 2) {
		fprintf(stderr, "No test input specified.\n");
		return 1;
	}
	struct tokenizer tokenizer = init_tokenizer(argv[1]);

	struct token token = {};
	while(next_token(&tokenizer, &token)) {
	}
}
