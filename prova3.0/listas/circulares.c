#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_at_beginning(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if (head == NULL) {
        new_node->next = new_node;
    } else {
        new_node->next = head->next;
        head->next = new_node;
    }
    head = new_node;
}

void insert_at_end(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if (head == NULL) {
        new_node->next = new_node;
    } else {
        new_node->next = head->next;
        head->next = new_node;
    }
}

void insert_after_node(struct node *prev_node, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void delete_node(struct node *node) {
    if (node == head) {
        if (head->next == head) {
            head = NULL;
        } else {
            head = head->next;
            node->next->next = head;
        }
    } else {
        node->next->next = node->next;
    }
    free(node);
}

void print_list() {
    struct node *temp = head;
    if (head == NULL) {
        printf("Lista vazia\n");
        return;
    }
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);
    insert_at_beginning(5);
    insert_after_node(head->next, 15);
    print_list();
    delete_node(head->next->next);
    print_list();
    return 0;
}
