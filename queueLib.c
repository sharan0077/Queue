#include "queueLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Queue* create(int typeSize,int noOfElements){
	Queue *queue = malloc(sizeof(Queue));
	queue->baseAddress = calloc(noOfElements,typeSize);
	queue->length = noOfElements;
	queue->elementSize = typeSize;
	queue->front = 0;
	queue->rear = -1;
	return queue;
}
int isFull(Queue *queue){
	if(queue->rear>=queue->length-1) return 1;
	return 0;
}
int enqueue(Queue *queue,void* element){
	void* destinationAddr; 
	if(isFull(queue)) return 0;
	queue->rear += 1;
	destinationAddr = queue->baseAddress+(queue->rear*queue->elementSize);
	memcpy(destinationAddr,element,queue->elementSize);
	return 1;
}
void* dequeue(Queue *queue){
	int bytesToMove;
	void *sourceAddr;
	if(queue->front==queue->rear) 
		return NULL;
	sourceAddr = queue->baseAddress+queue->elementSize;
	bytesToMove = queue->elementSize*queue->rear;
	memmove(queue->baseAddress,sourceAddr,bytesToMove);
	queue->front += 1;
	return queue->baseAddress;
}