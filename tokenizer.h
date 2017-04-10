struct token {
    enum token_type {
        tt_yarn,
        tt_numbr,
        tt_win,
    } type;
    const char *text;
};

struct tokenizer {
    const char *input;
    int index;
};

struct tokenizer init_tokenizer(const char *input);
bool next_token(struct tokenizer tokenizer, struct token *token_out);
