#ifndef ALETHEIA_G_NODELIST_H
#define ALETHEIA_G_NODELIST_H
/* g_021F3CB0 (arm9) */
struct Node;
struct NodeList {
    unsigned int serial;
    struct Node *head;
    unsigned int used;
    struct Node *pool[132];
};
#endif
