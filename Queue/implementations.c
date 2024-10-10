#include "lib.h"

void queue_constructor(Queue * queue) {
    if (queue == NULL) {
        printf("List is empty!\n");
        return;
    }
    queue->head = NULL;
    queue->size = 0;
    return;
}

void destructor(Queue ** queue) {
    if (*queue == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    Node * current = (*queue)->head;
    while(current->next) {
        Node * tmp = current;
        current = current->next;
        free(tmp);
        tmp = NULL;
    }
    free(current);
    current = NULL;
    (*queue)->size = 0;
    *queue = NULL;
}

void node_constructor(Node * node, int data) {
    if (node == NULL) {
        printf("Node is empty!\n");
        return;
    }
    node->data = data;
    node->next = NULL;
    return;
}

void push(Queue * queue, int data) {
    if (queue == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node * new_node = (Node *) malloc(sizeof(Node));
    node_constructor(new_node, data);
    if(queue->head == NULL) {
        queue->head = new_node;
    } else {
        Node * current = queue->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
    ++queue->size;
    return;
}

int pop_front(Queue * queue) {
    Node * tmp = queue->head;
    int data = tmp->data;
    queue->head = tmp->next;
    free(tmp);
    queue->size--;
    return data;
}


void print_node(Queue * queue) {
    if (queue == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node * current = queue->head;
    int incr = 1;
    while(current->next) {
        printf("%d: %d\n", incr++, current->data);
        current = current->next;
    }
    printf("%d: %d\n", incr, current->data);
    return;
}