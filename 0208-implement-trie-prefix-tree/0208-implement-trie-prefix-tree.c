#include <stdbool.h>
#include <stdlib.h>

typedef struct Trie {
    struct Trie* child[26];
    bool isEnd;
} Trie;

Trie* trieCreate() {
    Trie* node = (Trie*)malloc(sizeof(Trie));

    node->isEnd = false;

    for (int i = 0; i < 26; i++)
        node->child[i] = NULL;

    return node;
}

void trieInsert(Trie* obj, char* word) {
    Trie* curr = obj;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (curr->child[index] == NULL)
            curr->child[index] = trieCreate();

        curr = curr->child[index];
    }

    curr->isEnd = true;
}

bool trieSearch(Trie* obj, char* word) {
    Trie* curr = obj;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (curr->child[index] == NULL)
            return false;

        curr = curr->child[index];
    }

    return curr->isEnd;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    Trie* curr = obj;

    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';

        if (curr->child[index] == NULL)
            return false;

        curr = curr->child[index];
    }

    return true;
}

void trieFree(Trie* obj) {
    for (int i = 0; i < 26; i++) {
        if (obj->child[i] != NULL)
            trieFree(obj->child[i]);
    }

    free(obj);
}