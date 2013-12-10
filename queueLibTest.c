#include "testUtils.h"
#include "queueLib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
Queue expected,*actual;
int areEqual(Queue a,Queue e){
	int result;
	result = a.length == e.length && a.elementSize == e.elementSize;
	if(!result) return 0;
	return 0 == memcmp(a.baseAddress,e.baseAddress,a.elementSize*a.length); 
}

void test_should_create_que_to_store_intData_and_return_quePtr(){
	int arr[] = {0,0,0,0,0};
	int result;
	expected.baseAddress = arr;
	expected.length = 5;
	expected.elementSize = sizeof(int);
	actual = create(sizeof(int),5);
	result = areEqual(*actual,expected);
	ASSERT(result);
	ASSERT(actual->front==0);
	ASSERT(actual->rear==-1);
	ASSERT(*((int*)actual->baseAddress+2) == 0);
	free(actual->baseAddress);
	free(actual);
}
void test_should_create_que_to_store_doubleData_and_return_quePtr(){
	double arr[] = {0,0,0,0,0};
	int result;
	expected.baseAddress = arr;
	expected.length = 5;
	expected.elementSize = sizeof(double);
	actual = create(sizeof(double),5);
	result = areEqual(*actual,expected);
	ASSERT(result);
	ASSERT(actual->front==0);
	ASSERT(actual->rear==-1);
	ASSERT(*((int*)actual->baseAddress+2) == 0);
	free(actual->baseAddress);
	free(actual);
}
void test_should_create_que_to_store_String_and_return_quePtr(){
	String *strPtr = calloc(5,sizeof(String));
	int result;
	expected.baseAddress = strPtr;
	expected.length = 5;
	expected.elementSize = sizeof(String);
	actual = create(sizeof(String),5);
	result = areEqual(*actual,expected);
	ASSERT(result);
	ASSERT(actual->front==0);
	ASSERT(actual->rear==-1);
	free(actual->baseAddress);
	free(actual);
	free(strPtr);
}
void test_should_enqueue_intElement_into_que_and_return_true(){
	int result;
	int* element = malloc(sizeof(int));
	*element = 4;
	actual = create(sizeof(int),5);
	result = enqueue(actual,element);
	ASSERT(result);
	ASSERT(*((int*)actual->baseAddress)==4);
	ASSERT(actual->rear==0);
	free(actual->baseAddress);
	free(actual);
	free(element);
}
void test_should_dequeue_intelement_from_the_queue_and_return_address_of_it(){
	int result;
	int* element = malloc(sizeof(int));
	*element = 4;
	actual = create(sizeof(int),5);
	enqueue(actual,element);
	*element = 5;
	enqueue(actual,element);
	ASSERT(*(int*)dequeue(actual)==5);
	free(actual->baseAddress);
	free(actual);
	free(element);
}
void test_should_enqueue_DoubleElement_and_return_true(){
	double result;
	double* element = malloc(sizeof(double));
	*element = 4.5;
	actual = create(sizeof(double),5);
	result = enqueue(actual,element);
	ASSERT(result);
	ASSERT(*((double*)actual->baseAddress)==4.5);
	ASSERT(actual->rear==0);
	free(actual->baseAddress);
	free(actual);
	free(element);
}
void test_should_dequeue_doubleElement_from_the_queue_and_return_address_of_it(){
	int result;
	double* element = malloc(sizeof(double));
	*element = 4.5;
	actual = create(sizeof(double),5);
	enqueue(actual,element);
	*element = 5.5;
	enqueue(actual,element);
	ASSERT(*(double*)dequeue(actual)==5.5);
	free(actual->baseAddress);
	free(actual);
	free(element);
}
void test_should_enqueue_StringElement_and_return_true(){
	double result;
	char *strPtr = calloc(1,sizeof(String));
	strcpy(strPtr,"abcd");
	actual = create(sizeof(String),5);
	result = enqueue(actual,strPtr);
	ASSERT(result);
	ASSERT(0==strcmp(((char*)actual->baseAddress),"abcd"));
	ASSERT(actual->rear==0);
	free(actual->baseAddress);
	free(actual);
	free(strPtr);
}
void test_should_dequeue_StringElement_from_the_queue_and_return_address_of_it(){
	char* result;
	char *strPtr = calloc(1,sizeof(String));
	strcpy(strPtr,"abcd");
	actual = create(sizeof(String),5);
	enqueue(actual,strPtr);
	result = dequeue(actual);
	ASSERT(0==strcmp(((char*)actual->baseAddress),"abcd"));
	free(actual->baseAddress);
	free(actual);
	free(strPtr);
}
void test_should_return_false_when_trying_to_enque_fullQue(){
	int result;
	int* element = malloc(sizeof(int));
	*element = 4;
	actual = create(sizeof(int),3);
	enqueue(actual,element);
	enqueue(actual,element);
	enqueue(actual,element);
	result	= enqueue(actual,element);
	ASSERT(!result);
	ASSERT(actual->rear==2);
	free(actual->baseAddress);
	free(actual);
	free(element);
}
void test_should_return_false_when_trying_to_deque_emptyQue(){
	int* result;
	int* element = malloc(sizeof(int));
	*element = 4;
	actual = create(sizeof(int),3);
	enqueue(actual,element);
	dequeue(actual);
	result = dequeue(actual);
	ASSERT(result==NULL);
	free(actual->baseAddress);
	free(actual);
	free(element);
}