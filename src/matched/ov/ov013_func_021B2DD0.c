/*
 * function: func_021B2DD0
 * address:  0x021B2DD0
 * packet:   pkt_ov013_021B2DD0
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021B4BE0     0x021B4BE0  data  a4
 *   g_021B60D8     0x021B60D8  data  a4
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

struct Sess {
    unsigned char f0;
    unsigned char f1;
    unsigned char pad2[0xe];
    unsigned int f10;
    unsigned int f14;
};

struct Pkt {
    unsigned char pad0[8];
    unsigned char f8;
    unsigned char f9;
    unsigned char fa;
    unsigned char fb;
    unsigned int fc;
};

struct Event {
    unsigned int type;
    struct Node *node;
};

extern struct Pool g_021B4BE0;
extern struct Sess g_021B60D8;

int func_021B2DD0(struct Pkt *pkt, struct Event *ev)
{
    if (g_021B60D8.f10 != 2)
        return 0;
    if (g_021B60D8.f1 != pkt->f8)
        return 0;
    switch (pkt->fa) {
    case 0:
        if (g_021B4BE0.active.state == 0)
            return 0;
        if (g_021B4BE0.active.fc == 5 || g_021B4BE0.active.fc == 2)
            ev->type = 9;
        else
            ev->type = 5;
        g_021B4BE0.active.state = 0;
        g_021B4BE0.active.fc = 0;
        ev->node = &g_021B4BE0.active;
        break;
    case 1:
        g_021B4BE0.active.state = 2;
        if (pkt->fb == g_021B60D8.f0) {
            g_021B4BE0.active.fc = 2;
            ev->type = 7;
            g_021B4BE0.active.f8 = pkt->fc;
        } else {
            g_021B4BE0.active.fc = 3;
            ev->type = 6;
            g_021B4BE0.active.f8 = pkt->fb == 0 ? 1 : 1 << pkt->fb;
        }
        g_021B4BE0.active.f5 = pkt->fb;
        ev->node = &g_021B4BE0.active;
        break;
    default:
        return 0;
    }
    return 1;
}
