/*
 * function: func_021738D4
 * address:  0x021738D4
 * packet:   pkt_ov012_021738D4
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217505C  0x0217505C  thumb  ov012
 *   func_02167688  0x02167688  thumb  ov010
 */
#include "../include/Obj07339.h"
#include "../include/Obj12444.h"
#include "../include/Obj19239.h"

typedef unsigned char u8;

typedef struct { u8 pad[0xc8]; u8 f : 1; u8 pad2[0]; } S0;
typedef struct { u8 pad[0xc8]; u8 f; u8 g; } S;
typedef struct { u8 pad0[0x282A]; u8 a; u8 pad1[0x355C-0x282B]; S *b; } T;

extern void func_0217505C(void *o, int v);
struct Work;
extern void func_02167688(struct Work *w);

void func_021738D4(int a, T *p)
{
    S *o;

    o = p->b;
    if (o != 0) {
        if (o->g == 1) {
            func_0217505C(o, ((struct Obj19239 *)(*(u8 * *)&((struct Obj07339 *)p)->f0))->fC);
            p->b = 0;
        } else if (((S0 *)o)->f == 1) {
            func_02167688(((struct Obj12444 *)o)->f0);
        }
    }
    p->a = 0;
}
