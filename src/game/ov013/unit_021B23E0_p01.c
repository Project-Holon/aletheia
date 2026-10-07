/*
 * file:     unit_021B23E0_p01.c
 * unit:     yes
 * function: func_021B24FC, func_021B2564, func_021B25B0
 * address:  0x021B24FC
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
 *   d_021B60D8  0x021B60D8  data  ov013  a4
 *   d_021B4BE0  0x021B4BE0  data  a4
 *   func_021B2724  0x021B2724  arm  ov013
 *   func_021B2010  0x021B2010  arm  ov013
 *   func_021B275C  0x021B275C  arm  ov013
 *   func_021B20D4  0x021B20D4  arm  ov013
 */
#include "../../matched/include/G_Pool.h"

struct Chan;
typedef unsigned char u8;

typedef struct Ctx {
    u8 b0;
} Ctx;

typedef struct Node {
    char pad[0x14];
    struct Node *next;
} Node;

typedef struct Pool Pool;

extern void func_021B2724(Node *n, unsigned int idx);
extern int func_021B2010(void *a, unsigned int b, unsigned char *buf, unsigned int c);
extern int func_021B275C(u8 *o, u8 *p);
extern int func_021B20D4(struct Chan *a, unsigned int b, unsigned char *buf, unsigned int c);
Node *func_021B24FC(unsigned int idx);
int func_021B2564(int a, int b);
int func_021B25B0(int a, int b);
extern Ctx d_021B60D8;
extern struct Pool d_021B4BE0;


Node *func_021B24FC(unsigned int idx)
{
    Node *n;

    if (idx >= 0x20)
        return 0;
    if (idx == d_021B60D8.b0)
        return 0;
    n = d_021B4BE0.nodes;
    if (n == 0)
        return 0;
    d_021B4BE0.nodes = n->next;
    func_021B2724(n, idx);
    n->next = d_021B4BE0.head;
    d_021B4BE0.head = n;
    return n;
}


int func_021B2564(int a, int b)
{
    u8 buf[16];
    int r;

    r = func_021B2010((void *)a, b, buf, 16);
    if (r != 0)
        return r;
    if (func_021B275C((u8 *)a, buf) != 0)
        return 0;
    return -4;
}


int func_021B25B0(int a, int b)
{
    u8 buf[16];
    int r;

    r = func_021B20D4((struct Chan *)a, b, buf, 16);
    if (r != 0)
        return r;
    if (func_021B275C((u8 *)a, buf) != 0)
        return 0;
    return -4;
}
