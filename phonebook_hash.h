#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H
#define MAX_LAST_NAME_SIZE 16
#define HASH_SIZE 26

//detail part
typedef struct __PHONE_BOOK_DETAIL {
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __PHONE_BOOK_DETAIL *pNext;
} detail;

//struct lastname part
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    detail *detail;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

entry* append(char lastname[], entry *e);
entry* findName(char lastname[], entry *pHead);

#endif
