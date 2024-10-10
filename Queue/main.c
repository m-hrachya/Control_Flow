#include "lib.h"

int main() {
    Queue * queue = (Queue *) malloc(sizeof(Queue));
    assert(queue != NULL);
    queue_constructor(queue);
    
    
    return 0;
}