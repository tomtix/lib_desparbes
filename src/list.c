#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

typedef struct ElementList{
    void *data;
    struct ElementList *next;
}ElementList;

typedef struct List{
    ElementList *first;
    ElementList *cursor;
    int posCursor;
    int length;
    int dataSize;
}List;

static void cursorList(List *list, int position)
{
    if(list->posCursor > position){
	list->posCursor = 0;
	list->cursor = list->first;
    }
    if(position > list->length)
	fprintf(stderr, "Error: position asked is outside the list.\n");

    while(list->posCursor < position){
	list->posCursor++;
	list->cursor = list->cursor->next;
    }
}

List *initList(int dataSize)
{
    if(dataSize <= 0){
	fprintf(stderr, "Error: incorrect size of data in list.\n");
	return NULL;
    }

    List *list = malloc(sizeof(List));
    ElementList *sentinel = malloc(sizeof(ElementList));

    if(list == NULL || sentinel == NULL)
	fprintf(stderr, "Error: malloc failed during list initilization.\n");
    
    sentinel->next = sentinel;
    list->cursor = sentinel;
    list->posCursor = 0;
    list->first = sentinel;
    list->length = 0;
    list->dataSize = dataSize;
    return list;
}


void resetList(List *list)
{
    ElementList *cursor = list->first->next;
    ElementList *destroy = list->first->next;
    
    while(cursor != list->first){
	cursor = cursor->next;
	free(destroy->data);
	free(destroy);
	destroy = cursor;
    }
    
    list->length = 0;
}   

int voidList(List *list)
{
    return (list->length <= 0);
}	

void addDataList(List *list, void *data, int position)
{
    ElementList *newElementList = malloc(sizeof(ElementList));
    newElementList->data = malloc(list->dataSize);

    if(newElementList == NULL || newElementList->data == NULL){
	fprintf(stderr, "Error: malloc failed attempting adding data to list.\n");
	return;
    }

    cursorList(list, position - 1);

    memcpy(newElementList->data, data, list->dataSize);
    newElementList->next = list->cursor->next;
    list->cursor->next = newElementList;
    list->length++;
}

void *readDataList(List *list, int position)
{
    cursorList(list, position);
    return list->cursor->next->data;
} 

void removeDataList(List *list, int position)
{
    cursorList(list, position - 1);
    ElementList *destroy = list->cursor->next;
    
    list->cursor->next = destroy->next;
    list->length--;
    free(destroy->data);
    free(destroy);
}

void destroyList(List *list)
{
    resetList(list);
    free(list->first);
    free(list);
}
