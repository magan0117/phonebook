#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#include "phonebook_hash.h"



entry* hashTable[HASH_SIZE];

/* FILL YOUR OWN IMPLEMENTATION HERE! */

static inline int hash(char lastname[])
{
    int num=0;
    while(*lastname)
        num+=*lastname++;
    return (num%HASH_SIZE);

}

entry* findName(char lastname[],entry *pHead)
{
    int index = hash(lastname);
    pHead = hashTable[index];

    while(pHead != NULL) {
        if(strcasecmp(lastname,pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;

    }
    return NULL;
}

entry* append(char lastname[],entry *e)
{
    int bucket = hash(lastname);
    e->pNext = (entry *)malloc(sizeof(entry));
    e = e->pNext;
    if(hashTable[bucket]) {
        hashTable[bucket]->pNext = e;
        e->pNext = NULL;
        strcpy(e->lastName,lastname);
        hashTable[bucket]=e;
    } else {
        e->pNext = NULL;
        strcpy(e->lastName,lastname);
        hashTable[bucket] = e;
    }
    free(e->pNext);
    return e;
}
