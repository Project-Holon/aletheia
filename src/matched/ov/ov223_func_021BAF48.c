/*
 * function: func_021BAF48
 * address: 0x021BAF48
 * packet: pkt_ov223_021BAF48
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing AFC2 halfword is zero alignment padding. Forming q = p + i*4
 * before fixed field offsets retains the observed invariant constants;
 * computing p + constant + i*4 instead hoists pointer bases and spills p.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj08461.h"
#include "../include/Obj26093.h"
typedef unsigned char u8;
struct Descriptor;
struct Cfg;
struct PrintSys;
extern void *func_02045770(struct Descriptor *);
extern unsigned func_0201C6C4(struct PrintSys *, void *);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(unsigned);
int func_021BAF48(char *p)
{
    int finished = 1;
    u8 i;
    for (i = 0; i < 3; i++) {
        char *q = p + i * 4;
        if (((struct Obj08461 *)q)->f244 == 0) {
            if (func_0201C6C4(*(struct PrintSys * *)&((struct Obj26093 *)p)->f1C,
                            func_02045770(*(struct Descriptor * *)&((struct Obj08461 *)q)->f238)) != 0) {
                finished = 0;
            } else {
                struct Descriptor *d = *(struct Descriptor * *)&((struct Obj08461 *)q)->f238;
                func_02045334(d);
                func_02045374((struct Cfg *)d);
                func_02041B6C(func_02045730(d));
                ((struct Obj08461 *)q)->f244 = 1;
            }
        }
    }
    return finished;
}
