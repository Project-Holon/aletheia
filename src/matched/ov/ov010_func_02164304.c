/*
 * function: func_02164304
 * address:  0x02164304
 * packet:   pkt_ov010_02164304
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201441C  0x0201441C  thumb
 *   func_0216D67C  0x0216D67C  thumb
 *   func_0216D4D4  0x0216D4D4  thumb
 *   func_0219E2C0  0x0219E2C0  thumb
 *   func_0216D684  0x0216D684  thumb
 *   func_0216435C  0x0216435C  thumb
 */
#include "../include/Obj09310.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

typedef struct {
    u16 a;
    u8 b;
    u8 c;
    s16 d;
    u16 e;
} Msg;

extern u8 func_0201441C(int i);
extern void *func_0216D67C(void *a0);
extern int func_0216D4D4(int a, int b);
extern void func_0219E2C0(int a, Msg *m);
extern void func_0216D684(int a, int b);
extern void func_0216435C(int a, Msg *m);

void func_02164304(int a, u8 *p)
{
    Msg m;
    u16 *q;

    m.a = ((struct Obj09310 *)p)->f1C;
    m.b = 1;
    q = (u16 *)(p + 0x1c);
    m.c = func_0201441C(((struct Obj09310 *)p)->fC);
    m.e = q[1];
    m.d = ((s16 *)q)[2];
    if (func_0216D4D4((int)func_0216D67C((void *)a), 0x10) != 0) {
        func_0219E2C0(a, &m);
        return;
    }
    func_0216D684(a, 0xc);
    func_0216435C(a, &m);
}
