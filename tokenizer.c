#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "tokenizer.h"

struct tokenizer init_tokenizer(const char *input)
{
	struct tokenizer tokenizer = {
		.input = input,
		.index = 0
	};
	return tokenizer;
}

bool next_token(struct tokenizer tokenizer, struct token *token_out)
{
	int token_start = 0;

	int len = strlen(tokenizer.input);
	if(len <= 0)
	{
		return false;
	}

	bool separator;
	do
	{
		printf("%d / %d", tokenizer.index, len);
		char c = tokenizer.input[tokenizer.index];

		bool space = c == ' ';
		separator = space || c == '(' || c == ')' || c == '\n' || c == '[' || c == ']' || c == '{' || c == '}';

		if(space && tokenizer.index + 1 >= len && tokenizer.input[tokenizer.index + 1] == ' ')
		{
			token_start++;
		}
		tokenizer.index++;
	}
	while(!separator && tokenizer.index < len);

	printf("%i..%i", token_start, tokenizer.index);

	return true;
}
