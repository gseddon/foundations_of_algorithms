#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct node node_t;
typedef int data_t;

struct node {
    data_t data;
    node_t * next;
};

typedef struct {
    node_t* head;
} mystack_t;


mystack_t* make_empty_stack();
mystack_t* push(data_t data, mystack_t* stack);
data_t pop(mystack_t* stack);

int main() {

    mystack_t* stack = make_empty_stack();
    data_t  data;
    int i;
    for (i=0;i<4;i++){
        data = i;
        push(data, stack);
    }

    while ((data = pop(stack))) {
        printf("Popped %d\n", data);
    }

    return 0;
}

mystack_t *make_empty_stack() {
    mystack_t *stack = malloc(sizeof(mystack_t));
    stack->head = NULL;
    return stack;
}

mystack_t *push(data_t data, mystack_t* stack) {
    node_t *node = malloc(sizeof(node_t));
    assert(node);
    node->next = stack->head;
    node->data = data;
    stack -> head = node;
    return stack;
}

data_t pop(mystack_t *stack) {
    node_t* head = stack->head;
    data_t data;
    if (head){
        stack->head = head->next;
        data = head->data;
        free(head);
        return data;
    }
    return NULL;
}

