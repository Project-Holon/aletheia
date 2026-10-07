/*
 * file:     unit_021B23E0_p05.c
 * unit:     yes
 * function: func_021B2D54, func_021B2DD0, func_021B2ED8
 * address:  0x021B2D54
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
 *   d_021B4BF4  0x021B4BF4  data  a4
 *   func_021B2A20  0x021B2A20  arm  ov013
 *   func_021B25B0  0x021B25B0  arm  ov013
 *   func_021B2724  0x021B2724  arm  ov013
 *   g_021B4BE0     0x021B4BE0  data  a4
 *   g_021B60D8     0x021B60D8  data  a4
 *   d_021B4C24 0x021B4C24 data a4
 *   func_02082AC0 0x02082AC0 arm
 */
#include "../../matched/include/G_Sess.h"

typedef unsigned char u8;

typedef struct N {
    int a;
} N;

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

typedef unsigned int u32;

typedef struct E { struct E *next; u8 pad[0x474]; } E;

typedef struct { E *cur; E *buf; } G;

extern N *func_021B2A20(int id);
extern int func_021B25B0(int a, int b);
extern void func_021B2724(u8 *p, u8 v);
extern void func_02082AC0(int, void *, u32);
int func_021B2D54(u8 *p, int *out);
int func_021B2DD0(struct Pkt *pkt, struct Event *ev);
int func_021B2ED8(E *a, u32 b);
extern int d_021B4BF4[];
extern struct Pool g_021B4BE0;
extern struct Sess g_021B60D8;
extern G d_021B4C24;


int func_021B2D54(u8 *p, int *out)
{
    N *n;

    if (p[4] == 0xff && p[6] == 4)
        return 0;
    n = func_021B2A20(p[8]);
    if (n) {
        out[0] = 2;
        out[1] = (int)n;
        n->a = 0;
        func_021B25B0((int)n, 2);
        return 1;
    }
    func_021B2724((u8 *)d_021B4BF4, p[8]);
    func_021B25B0((int)d_021B4BF4, 2);
    return 0;
}


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

/*
 * lever: fill call takes data, p and b; r1/r2 stay live across the guards.
 */
int func_021B2ED8(E *a, u32 b)
{
    u32 i;
    u32 n;
    E *p;
    n = b / 0x478;
    p = a;
    d_021B4C24.buf = p;
    if (n < 4 || n > 0x48) return 0;
    if (p == 0) return 0;
    if ((u32)p & 0x1f) {
        d_021B4C24.buf = 0;
        return 0;
    }
    i = 0;
    func_02082AC0(i, p, b);
    for (i = 0; i < n - 1; i++)
        d_021B4C24.buf[i].next = &d_021B4C24.buf[i + 1];
    (d_021B4C24.buf + n)[-1].next = 0;
    d_021B4C24.cur = d_021B4C24.buf;
    return 1;
}
