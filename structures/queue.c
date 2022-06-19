# include <stdlib.h>

struct queue_node{
    struct queue_node *next;
    int data;
};

typedef struct{
    struct queue_node *start;
    struct queue_node *end;
} queue;

void init_queue(queue *q){
    q->start = NULL;
    q->end = NULL;
}

void __init_queue_node(struct queue_node *n, int value){
    n->next = NULL;
    n->data = value;
}

void enqueue(queue *q, int value){
    struct queue_node *node = malloc(sizeof(struct queue_node));
    __init_queue_node(node, value);
    if(q->end == NULL) {
        q->start = node;
        q->end = node;
    }
    else {
        q->end->next = node;
        q->end = node;
    }
}

int dequeue(queue *q){
    if(q->start != NULL){
        int d = q->start->data;
        q->start = q->start->next;
        return d; 
    }
    else return -1;
}