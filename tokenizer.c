#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tokenizer.h"

struct tokenizer init_tokenizer(const char *input) {
	struct tokenizer tokenizer = {
		.input = input,
		.index = 0,
		.len = strlen(input)
	};
	return tokenizer;
}

bool next_token(struct tokenizer *tokenizer, struct token *token_out) {
	if (tokenizer->index >= tokenizer->len) {
		return false;
	}

	bool separator;
	bool first = true;

	int start = tokenizer->index;
	do {
		char c = tokenizer->input[tokenizer->index];
		separator = ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c < '0' || c > '9'));

		if (separator && c != '\'' && c != '"' && tokenizer->quote) {
			separator = false;
		}

		if (!separator || first) {
			tokenizer->index++;
		}

		first = false;
	} while(tokenizer->index < tokenizer->len && !separator);

	if (tokenizer->index - start == 1 && tokenizer->input[start] == ' ') {
		return next_token(tokenizer, token_out);
	}

	char* str = strndup(tokenizer->input + start, tokenizer->index - start);
	printf("%s\n", str);

	if (strcmp(str, "'") == 0 || strcmp(str, "\"") == 0) {
		tokenizer->quote = !tokenizer->quote;
	}

	free(str);
	return tokenizer->index < tokenizer->len;
}
