#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFreq;

WordFreq wordTable[MAX_WORDS];
int wordCount = 0;

int findWordIndex(const char* word) {
    for (int i = 0; i < wordCount; ++i) {
        if (strcmp(wordTable[i].word, word) == 0)
            return i;
    }
    return -1;
}

void addWord(const char* word) {
    if (strlen(word) == 0)
        return;

    int index = findWordIndex(word);
    if (index != -1) {
        wordTable[index].count++;
    } else if (wordCount < MAX_WORDS) {
        strcpy(wordTable[wordCount].word, word);
        wordTable[wordCount].count = 1;
        wordCount++;
    }
}

int main() {
    char filename[100];
    FILE *fp;

    printf("Enter file name to analyze: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    int ch, totalChars = 0, totalWords = 0, totalLines = 0;
    int charFreq[256] = {0};

    char word[MAX_WORD_LEN];
    int i = 0;

    while ((ch = fgetc(fp)) != EOF) {
        totalChars++;
        charFreq[ch]++;

        if (ch == '\n')
            totalLines++;

        if (isalnum(ch)) {
            if (i < MAX_WORD_LEN - 1)
                word[i++] = tolower(ch);
        } else {
            if (i > 0) {
                word[i] = '\0';
                addWord(word);
                totalWords++;
                i = 0;
            }
        }
    }

    // In case file ends with a word without space/newline
    if (i > 0) {
        word[i] = '\0';
        addWord(word);
        totalWords++;
    }

    fclose(fp);

    printf("\n--- File Statistics ---\n");
    printf("Total Characters: %d\n", totalChars);
    printf("Total Words     : %d\n", totalWords);
    printf("Total Lines     : %d\n", totalLines);

    printf("\n--- Character Frequency ---\n");
    for (int i = 0; i < 256; ++i) {
        if (charFreq[i] > 0)
            printf("'%c' (%d): %d\n", isprint(i) ? i : '?', i, charFreq[i]);
    }

    printf("\n--- Word Frequency ---\n");
    for (int i = 0; i < wordCount; ++i) {
        printf("'%s': %d\n", wordTable[i].word, wordTable[i].count);
    }

    return 0;
}
