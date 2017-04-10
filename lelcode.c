#include <stdio.h>
#include "tokenizer.c"

int main(int argc, const char *argv[]) {
	// Don't judge me tbodt. It's impossible to get -1, I know.
	// I just always do this. kek.
	if(argc < 1)
	{
		fprintf(stderr, "No test input specified.");
		return 1;
	}
	struct tokenizer tokenizer = init_tokenizer(argv[0]);

	struct token token = {};
	while(next_token(tokenizer, &token))
	{
		printf("%s\n", token.text);
	}
}
