#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node{
    int data;
    struct Node * next;
} Node;

typedef struct {
    Node * head;
    int size;
} Queue;

void queue_constructor(Queue * queue);
void destructor(Queue ** queue);
void node_constructor(Node * node, int data);
void push(Queue * queue, int data);
int pop_front(Queue * queue);
void print_node(Queue * queue);

#endif