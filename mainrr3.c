#include <stdio.h>
#include <ctype.h>

// funktsiia perevirky, chy slovo mistyt khotia b odyn bukvenyi abo tsyfrovyi symvol
int is_valid_word(const char *word, int length) {
    for (int i = 0; i < length; ++i) {
        if (isalnum((unsigned char)word[i])) {
            return 1; // slovo validne
        }
    }
    return 0; // tilky punktuatsia
}

int main(void) {
    int c;
    int in_word = 0;       // flag, chy my v seredyni slova
    char buffer[256];      // bufer dlia potocnoho slova
    int buf_len = 0;       // dovzhyna potocnoho slova
    int word_count = 0;    // kilkist sliv

    printf("Enter text (finish with Ctrl+Z):\n");

    while ((c = getchar()) != EOF) {
        if (isspace(c)) {
            // kinets slova
            if (in_word) {
                if (is_valid_word(buffer, buf_len)) {
                    word_count++;
                }
                buf_len = 0;
                in_word = 0;
            }
        } else {
            // chastyna slova
            if (buf_len < 255) {
                buffer[buf_len++] = (char)c;
            }
            in_word = 1;
        }
    }

    // perevirka ostannoho slova, yakshcho vvedennia zakinchylosia bez probilu
    if (in_word && buf_len > 0) {
        if (is_valid_word(buffer, buf_len)) {
            word_count++;
        }
    }

    // zapys rezultatu u fail
    FILE *fout = fopen("result.txt", "w");
    if (!fout) {
        printf("Error: cannot open file for writing.\n");
        return 1;
    }
    fprintf(fout, "Word count = %d\n", word_count);
    fclose(fout);

    printf("Word count = %d (saved to result.txt)\n", word_count);
    return 0;
}
