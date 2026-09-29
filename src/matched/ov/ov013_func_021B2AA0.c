/*
 * function: func_021B2AA0
 * address:  0x021B2AA0
 * packet:   pkt_ov013_021B2AA0
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021B4BE0     0x021B4BE0  data  a4
 *   func_021B2DD0  0x021B2DD0  arm  ov013
 *   func_021B2A20  0x021B2A20  arm  ov013
 *   func_021B2894  0x021B2894  arm  ov013
 *   func_021B279C  0x021B279C  arm  ov013
 *   func_021B24FC  0x021B24FC  arm  ov013
 *   func_021B2724  0x021B2724  arm  ov013
 *   func_021B25B0  0x021B25B0  arm  ov013
 *   func_021B1F54  0x021B1F54  arm  ov013
 */

struct Node {
    unsigned int state;
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
    unsigned int f4;
    void *tick;
    unsigned int mul;
    unsigned int add;
    struct Node freeList;
    struct Node active;
};

struct Pkt {
    unsigned char pad0[4];
    unsigned char f4;
    unsigned char f5;
    unsigned char f6;
    unsigned char f7;
    unsigned char f8;
    unsigned char f9;
    unsigned char fa;
    unsigned char fb;
    unsigned int fc;
};

struct Event {
    int type;
    struct Node *node;
};

extern struct Pool g_021B4BE0;
extern int func_021B2DD0(struct Pkt *pkt, struct Event *ev);
extern struct Node *func_021B2A20(unsigned char id);
extern int func_021B2894(struct Node *node, struct Pkt *pkt);
extern int func_021B279C(struct Pkt *pkt, struct Node *node);
extern struct Node *func_021B24FC(unsigned char id);
extern void func_021B2724(struct Node *list, unsigned char id);
extern void func_021B25B0(struct Node *list, int reason);
extern void func_021B1F54(struct Node *node);

int func_021B2AA0(struct Pkt *pkt, struct Event *ev)
{
    struct Node *node;
    int r;

    if (pkt->f4 == 0xFF) {
        if (pkt->f6 == 4)
            return func_021B2DD0(pkt, ev);
        if (pkt->f6 == 3)
            return 0;
    }
    node = func_021B2A20(pkt->f8);
    if (node) {
        r = func_021B2894(node, pkt);
        switch (r) {
        case -1:
            return 0;
        case -2:
            ev->type = 0xC;
            node->state = 0;
            ev->node = node;
            return 1;
        }
        ev->type = func_021B279C(pkt, node);
        ev->node = node;
        node->fc = r;
        return ev->type != 0;
    }
    node = func_021B24FC(pkt->f8);
    if (node == 0) {
        func_021B2724(&g_021B4BE0.freeList, pkt->f8);
        func_021B25B0(&g_021B4BE0.freeList, 3);
        return 0;
    }
    r = func_021B2894(node, pkt);
    if (r == -2 || r == -1) {
        func_021B1F54(node);
        return 0;
    }
    ev->type = func_021B279C(pkt, node);
    ev->node = node;
    node->fc = r;
    return ev->type != 0;
}
