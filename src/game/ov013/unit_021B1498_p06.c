/*
 * file:     unit_021B1498_p06.c
 * unit:     yes
 * function: func_021B1F54, func_021B2010, func_021B20B0, func_021B20D4
 * address:  0x021B1F54
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
 *   g_021B4BE0  0x021B4BE0  data  a4
 *   g_021B60D8  0x021B60D8  data  a4
 *   func_021B2848  0x021B2848  arm  ov013
 *   func_021B29A4  0x021B29A4  arm  ov013
 *   func_021B2958  0x021B2958  arm  ov013
 *   d_021B60D8 0x021B60D8 data a4
 *   func_021B2564 0x021B2564 arm ov013
 */
#include "../../matched/include/G_Sess.h"

struct N;
struct Msg;
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

typedef unsigned char  u8;

struct Chan {
    unsigned char pad[4];
    unsigned char f4;
    unsigned char pad5[3];
    unsigned int f8;
    int fc;
};

extern void func_021B2848(void *a, void *b, unsigned int c);
extern int func_021B29A4(int *obj, const u8 *q);
extern int func_021B2958(struct N *p);
extern int func_021B2564(int, int);
int func_021B1F54(struct Node *p);
int func_021B2010(void *a, unsigned int b, unsigned char *buf, unsigned int c);
int func_021B20B0(int a, int b);
int func_021B20D4(struct Chan *a, unsigned int b, unsigned char *buf, unsigned int c);
extern struct Pool g_021B4BE0;
extern struct Sess g_021B60D8;
extern struct Sess d_021B60D8;


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


int func_021B2010(void *a, unsigned int b, unsigned char *buf, unsigned int c)
{
    int r = 0xff;

    if (a == 0)
        return -1;
    if (c < 0x10)
        return -1;
    if (g_021B60D8.fc == 1)
        return -3;
    if (b >= 5)
        return -3;
    buf[4] = r;
    func_021B2848(a, buf, b & 0xff);
    if (func_021B29A4(a, buf) == 0)
        return 0xfc - r;
    if (g_021B60D8.f10 == 1 && b == 0) {
        if (func_021B2958(a) == 0)
            return 0xfc - r;
    }
    return 0;
}

int func_021B20B0(int a, int b)
{
    if (((int *)&d_021B60D8)[4] == 2) return -3;
    return func_021B2564(a,b);
}


int func_021B20D4(struct Chan *a, unsigned int b, unsigned char *buf, unsigned int c)
{
    int z = 0;

    if (a == 0)
        return -1;
    if (c < 0x10)
        return -1;
    if (b >= 6)
        return -3;
    buf[4] = z;
    func_021B2848((u8 *)a, (struct Msg *)buf, b & 0xff);
    if (b == 0) {
        if (g_021B60D8.f10 == 1 && a->fc == 4) {
            if (func_021B2958((struct N *)a) == 0)
                return z - 3;
        }
        a->f8 = a->f4 ? 1 << a->f4 : 1;
    }
    if (func_021B29A4((int *)a, buf) == 0)
        return -3;
    return 0;
}
