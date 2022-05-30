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

void free_tree(node *root);
void print_tree(node *root);
bool search(node *root, int number);

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

    bool isThreePresent = search(tree, 3);
    bool isFourPresent = search(tree, 4);
    printf("Is 3 present: %i\nIs 4 present: %i\n", isThreePresent, isFourPresent);

    print_tree(tree);
    free_tree(tree);
}

void print_tree(node *root) {
    if (root == NULL) {
        return;
    }

    print_tree(root->left);
    printf("%i ", root->number);
    print_tree(root->right);
}

void free_tree(node *root) {
    if (root == NULL) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

bool search(node *root, int number) {
    if (root == NULL) {
        return false;
    } else if (number < root->number) {
        return search(root->left, number);
    } else if (number > root->number) {
        return search(root->right, number);
    } else {
        return true;
    }
}