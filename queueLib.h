typedef struct{
	void* baseAddress;
	int elementSize;
	int length;
	int front;
	int rear;
}Queue;
typedef char String[256];
Queue* create(int typeSize,int noOfElements);
int enqueue(Queue *queue,void* element);
void* dequeue(Queue *queue);
int isFull(Queue *queue);
int isEmpty(Queue *queue);
