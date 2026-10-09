/*
 * file:     unit_021B23E0_p01.c
 * unit:     yes
 * function: func_021B23E0, func_021B2488, func_021B24FC, func_021B2564, func_021B25B0, func_021B25FC
 * address:  0x021B23E0
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
 *   d_021B4BD0  0x021B4BD0  data  ov013  a4
 *   d_021B3C48  0x021B3C48  data  ov013  a4
 *   d_021B4BE0  0x021B4BE0  data  a4
 *   d_021B4C0C  0x021B4C0C  data  ov013  a4
 *   func_020870D0  0x020870D0  arm
 *   func_021B26DC  0x021B26DC  arm  ov013
 *   func_021B2D54  0x021B2D54  arm  ov013
 *   func_021B2AA0  0x021B2AA0  arm  ov013
 *   func_021B2BE0  0x021B2BE0  arm  ov013
 *   func_021B2724  0x021B2724  arm  ov013
 *   func_021B2010  0x021B2010  arm  ov013
 *   func_021B275C  0x021B275C  arm  ov013
 *   func_021B20D4  0x021B20D4  arm  ov013
 */
#include "../../matched/include/G_Pool.h"
#include "../../matched/include/G_Stat.h"
#include "../../matched/include/Obj00947.h"

struct Event;
struct Pkt;
struct Chan;
typedef unsigned long long u64;

typedef unsigned char u8;

typedef struct St {
    u8 b0;
    u8 pad[3];
    int (*cb)(int, int, int, int);
    int arg;
    int fC;
    int state;
} St;

typedef struct Node {
    char pad[0x14];
    struct Node *next;
} Node;

typedef struct Pool Pool;

extern u64 func_020870D0(void);
extern void func_021B26DC(int);
extern int func_021B2D54(u8 *p, int *out);
extern int func_021B2AA0(struct Pkt *pkt, struct Event *ev);
extern int func_021B2BE0(struct Pkt *pkt, struct Event *ev);
extern void func_021B2724(Node *n, unsigned int idx);
extern int func_021B2010(void *a, unsigned int b, unsigned char *buf, unsigned int c);
extern int func_021B275C(u8 *o, u8 *p);
extern int func_021B20D4(struct Chan *a, unsigned int b, unsigned char *buf, unsigned int c);
void func_021B23E0(void);
int func_021B2488(int a, u8 *p, int len, int x);
Node *func_021B24FC(unsigned int idx);
int func_021B2564(int a, int b);
int func_021B25B0(int a, int b);
void func_021B25FC(u8 *a,u8 *b);
extern St d_021B60D8;
extern struct Stat d_021B4BD0;
extern u64 d_021B3C48;
extern struct Pool d_021B4BE0;
extern char d_021B4C0C;


void func_021B23E0(void)
{
    u64 now;

    now = func_020870D0();
    if (d_021B60D8.state != 2)
        return;
    if (d_021B60D8.fC == 0)
        return;
    if (d_021B4BD0.t == 0)
        return;
    if (now - d_021B4BD0.t <= d_021B3C48)
        return;
    d_021B4BD0.t = 0;
    d_021B4BE0.active_state = 0;
    d_021B4BE0.active_fc = 0;
    func_021B26DC(0);
    d_021B60D8.cb(*((unsigned char *)&d_021B4BE0 + 0x30), 9, (int)&d_021B4C0C, d_021B60D8.arg);
}




int func_021B2488(int a, u8 *p, int len, int x)
{
    if (len != 0x10)
        return 0;
    if (p[8] != a || p[9] != d_021B60D8.b0)
        return 0;
    if (p[5] != 0x10)
        return func_021B2D54(p, (int *)x);
    if (d_021B60D8.fC == 0)
        return func_021B2AA0((struct Pkt *)p, (struct Event *)x);
    return func_021B2BE0((struct Pkt *)p, (struct Event *)x);
}





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


void func_021B25FC(u8 *a,u8 *b)
{
    if(b[10] == 1) {
        b[11]=a[4];
        ((struct Obj00947 *)b)->fC=d_021B4BD0.mask;
    }
}
