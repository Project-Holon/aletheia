#ifndef ALETHEIA_G_NODE_H
#define ALETHEIA_G_NODE_H
/* gOverlayEndCallbacks (arm9) */
struct Node {
    struct Node *next;
    void (*b)(void *);
    void *a;
};
#endif
