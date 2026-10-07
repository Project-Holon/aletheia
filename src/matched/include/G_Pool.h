#ifndef ALETHEIA_G_POOL_H
#define ALETHEIA_G_POOL_H
/* g_021B4BE0 (arm9) */
struct Node;
struct Pool {
    struct Node *nodes;
    struct Node *head;
    void *tick;
    unsigned int mul;
    unsigned int add;
    unsigned int freeList_state;
    unsigned char freeList_f4;
    unsigned char freeList_f5;
    unsigned short freeList_f6;
    unsigned int freeList_f8;
    unsigned int freeList_fc;
    unsigned int freeList_f10;
    struct Node *freeList_next;
    unsigned int active_state;
    unsigned char id;
    unsigned char active_f5;
    unsigned short active_f6;
    unsigned int active_f8;
    unsigned int active_fc;
    unsigned int active_f10;
    struct Node *active_next;
};
#endif
