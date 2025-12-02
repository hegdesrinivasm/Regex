#include <stdio.h>

#include "src/regex.h"

int main(int argc, const char **argv) {
    if (argc != 3) {
        printf("Usage: regexer \"<text>\" \"<regex>\"\n");
        return -1;
    }

    const char *text = argv[1];
    const char *re = argv[2];
    // const char *text = "somebody saw nobody";
    // const char *re = "saw";

    Regex regex;
    regex_create(&regex, re);

    bool matched = false;
    // for (int i = 0; text[i] && !matched; ++i) {
    //     regex_reset(&regex);
    //     for (int j = i; text[j] && !matched; ++j)
    //         matched = regex_step(&regex, text[j]);
    // }
    matched = regex_pattern_in_text(&regex, text);

    if (matched) printf("MATCHED!!!\n");
    else printf("NOT MATCHED!!!\n");

    regex_destroy(&regex);
}
