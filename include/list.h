#ifndef LIST_H
#define LIST_H

typedef struct List List;

List *initList(int dataSize);
void resetList(List *list);
int voidList(List *list);
void addDataList(List *list, void *data, int position);
void *readDataList(List *list, int position);
void removeDataList(List *list, int position);
void destroyList(List *list);

#endif // LIST_H
