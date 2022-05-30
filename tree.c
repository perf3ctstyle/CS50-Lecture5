//
// Created by perf3ctstyle on 30.05.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int number;
    struct node *left;
    struct node *right;
} node;

int main(void) {
    node *tree = NULL;

    node *n = malloc(sizeof(node));
    if (n == NULL) {
        return 1;
    }

    n->number = 2;
    n->left = NULL;
    n->right = NULL;

    tree = n;

    n = malloc(sizeof(node));
    if (n == NULL) {
        free(tree);
        return 1;
    }

    n->number = 1;
    n->left = NULL;
    n->right = NULL;

    tree->left = n;

    n = malloc(sizeof(node));
    if (n == NULL) {
        free(tree);
        return 1;
    }

    n->number = 3;
    n->left = NULL;
    n->right = NULL;

    tree->right = n;
}