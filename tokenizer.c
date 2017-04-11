#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tokenizer.h"

struct tokenizer init_tokenizer(const char *input) {
	struct tokenizer tokenizer = {
		.input = input,
		.index = 0
	};
	return tokenizer;
}

bool next_token(struct tokenizer *tokenizer, struct token *token_out) {
	int token_start = tokenizer->index;

	int len = strlen(tokenizer->input);
	if (tokenizer->index >= len) {
		return false;
	}

	bool separator;
	bool first = true;
	do {
		char c = tokenizer->input[tokenizer->index];

		bool space = c == ' ';
		separator = space || (c < 'a' || c > 'z') && (c < 'A' || c > 'Z');

		if (space && tokenizer->index + 1 < len && tokenizer->input[tokenizer->index + 1] == ' ') {
			token_start++;
		} else if (!separator || space || first) {
			tokenizer->index++;
		}

		first = false;
	} while(tokenizer->index < len && !separator);

	printf("%i..%i ", token_start, tokenizer->index);
	char* str = strndup(tokenizer->input + token_start, tokenizer->index - token_start);
	printf("%s\n", str);

	free(str);
	return tokenizer->index < len;
}
