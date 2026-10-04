/*
 * function: func_021C71D0
 * address: 0x021C71D0
 * packet: pkt_ov136_021C71D0
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj00412.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
struct Control {
    u8 enabled : 1;
    u8 mode : 7;
    u8 action : 4;
    u8 phase : 4;
    u8 a, b, c, d, e, f;
};
typedef unsigned int u32;
struct WinMgr;
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void func_0202CFC0(struct WinMgr *mgr, u32 idx, u16 *w, u16 *h);
int func_021C71D0(u8 *p, int v, int w)
{
    struct Temp { s8 b, a; u16 c, d; } t;
    struct Control *q;
    func_0202CF98(**(void ** *)&((struct Obj00412 *)p)->f8, v, &t.a, &t.b);
    func_0202CFC0(**(void ** *)&((struct Obj00412 *)p)->f8, v, &t.d, &t.c);
    q = (struct Control *)(*(u8 * *)&((struct Obj00412 *)p)->f8 + 0x300);
    q->enabled = 1;
    q->mode = 2;
    q->action = 2;
    q->phase = 1;
    q->a = 0;
    q->b = 0;
    q->c = t.a;
    q->d = t.b;
    q->e = t.d;
    q->f = t.c;
    *(int *)&((struct Obj00412 *)p)->f28 = w;
    return 5;
}
