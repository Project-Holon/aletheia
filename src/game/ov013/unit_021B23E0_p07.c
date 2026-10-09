/*
 * file:     unit_021B23E0_p07.c
 * unit:     yes
 * function: func_021B2A20, func_021B2AA0
 * address:  0x021B2A20
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021B60D8  0x021B60D8  data  a4
 *   d_021B4BE0  0x021B4BE0  data  a4
 *   d_021B4C0C  0x021B4C0C  data  a4
 *   g_021B4BE0     0x021B4BE0  data  a4
 *   func_021B2DD0  0x021B2DD0  arm  ov013
 *   func_021B2894  0x021B2894  arm  ov013
 *   func_021B279C  0x021B279C  arm  ov013
 *   func_021B24FC  0x021B24FC  arm  ov013
 *   func_021B2724  0x021B2724  arm  ov013
 *   func_021B25B0  0x021B25B0  arm  ov013
 *   func_021B1F54  0x021B1F54  arm  ov013
 */
#include "../../matched/include/G_Sess.h"
#include "../../matched/include/G_N.h"

struct N;
struct Ctx;
struct Msg;
struct Q;
typedef unsigned char u8;

typedef struct N N;

typedef struct {
    int x;
    N *head;
    int pad[9];
    int flag;
    u8 id;
} G;

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

extern int func_021B2DD0(struct Pkt *pkt, struct Event *ev);
extern int func_021B2894(struct Ctx *c, struct Msg *m);
extern int func_021B279C(u8 *o, struct Q *q);
extern struct Node *func_021B24FC(unsigned int idx);
extern void func_021B2724(u8 *p, u8 v);
extern int func_021B25B0(int a, int b);
extern int func_021B1F54(struct Node *p);
N *func_021B2A20(int id);
int func_021B2AA0(struct Pkt *pkt, struct Event *ev);
extern struct Sess d_021B60D8;
extern G d_021B4BE0;
extern struct N d_021B4C0C;
extern struct Pool g_021B4BE0;


N *func_021B2A20(int id)
{
    N *n;

    n = d_021B4BE0.head;
    if (((int *)&d_021B60D8)[4] == 2) {
        if (d_021B4BE0.flag != 0 && d_021B4BE0.id == id)
            return &d_021B4C0C;
        return 0;
    }
    while (n) {
        if (n->a != 0 && n->id == id)
            return n;
        n = n->next;
    }
    return 0;
}


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
    node = (struct Node *)func_021B2A20(pkt->f8);
    if (node) {
        r = func_021B2894((struct Ctx *)node, (struct Msg *)pkt);
        switch (r) {
        case -1:
            return 0;
        case -2:
            ev->type = 0xC;
            node->state = 0;
            ev->node = node;
            return 1;
        }
        ev->type = func_021B279C((u8 *)pkt, (struct Q *)node);
        ev->node = node;
        node->fc = r;
        return ev->type != 0;
    }
    node = func_021B24FC(pkt->f8);
    if (node == 0) {
        func_021B2724((u8 *)(&g_021B4BE0.freeList), pkt->f8);
        func_021B25B0((int)(&g_021B4BE0.freeList), 3);
        return 0;
    }
    r = func_021B2894((struct Ctx *)node, (struct Msg *)pkt);
    if (r == -2 || r == -1) {
        func_021B1F54(node);
        return 0;
    }
    ev->type = func_021B279C((u8 *)pkt, (struct Q *)node);
    ev->node = node;
    node->fc = r;
    return ev->type != 0;
}
