/*
 * function: func_021B1F54
 * address:  0x021B1F54
 * packet:   pkt_ov013_021B1F54
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021B4BE0  0x021B4BE0  data  a4
 *   g_021B60D8  0x021B60D8  data  a4
 */

struct Node {
    unsigned int f0;
    unsigned char f4;
    unsigned char f5;
    unsigned short f6;
    unsigned int f8;
    unsigned int fc;
    unsigned int f10;
    struct Node *next;
};

struct Pool {
    struct Node *nodes;
    struct Node *activeHead;
    void *tick;
    unsigned int mul;
    unsigned int add;
    struct Node freeList;
    struct Node active;
};

struct Sess {
    unsigned char pad[0x10];
    unsigned int f10;
};

extern struct Pool g_021B4BE0;
extern struct Sess g_021B60D8;

int func_021B1F54(struct Node *p)
{
    struct Node *prev = 0;
    struct Node *cur = g_021B4BE0.activeHead;

    if (p == 0)
        return 0;
    if (g_021B60D8.f10 == 2) {
        if (p == &g_021B4BE0.active)
            g_021B4BE0.active.f0 = 0;
        return 1;
    }
    for (; cur; prev = cur, cur = cur->next) {
        if (cur == p) {
            p->f0 = 0;
            if (prev)
                prev->next = p->next;
            else if (cur->next)
                g_021B4BE0.activeHead = cur->next;
            else
                g_021B4BE0.activeHead = 0;
            p->next = g_021B4BE0.nodes;
            g_021B4BE0.nodes = p;
            return 1;
        }
    }
    return 0;
}
