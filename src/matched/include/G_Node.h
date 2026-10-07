#ifndef ALETHEIA_G_NODE_H
#define ALETHEIA_G_NODE_H
/* g_021542B8 (arm9) */
struct Node {
    struct Node *next;
    void (*b)(void *);
    void *a;
};
#endif
