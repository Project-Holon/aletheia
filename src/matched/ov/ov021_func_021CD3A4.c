/*
 * function: func_021CD3A4
 * address:  0x021CD3A4
 * packet:   pkt_ov021_021CD3A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * symbols:
 *   func_0200C1F8  0x0200C1F8  thumb
 *   func_02027198  0x02027198  thumb
 *   func_0200C210  0x0200C210  thumb
 *   func_020275C4  0x020275C4  thumb
 *   func_02045838  0x02045838  arm
 *   func_02165844  0x02165844  thumb  ov010
 */
#include "../include/Obj03150.h"
#include "../include/Obj06099.h"

typedef unsigned char u8;
typedef unsigned short u16;

struct Blk34;
struct U16Vec;
extern void func_0200C1F8(struct Blk34 *p, const u16 *src);
extern void func_02027198(void);
extern void func_0200C210(struct Blk34 *p, const u16 *src);
extern int func_020275C4(void *p);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern void func_02165844(void *v);

void func_021CD3A4(u8 *a, u8 *b)
{
    u16 *q = *(u16 * *)&((struct Obj03150 *)a)->f18;

    if (q) {
        if (((struct Obj06099 *)b)->f1C == 0)
            *q = 1;
        else
            *q = 0;
    }
    if (((struct Obj06099 *)b)->f1C == 1)
        return;
    switch (((struct Obj03150 *)a)->f4C) {
    case 5:
        func_0200C1F8((struct Blk34 *)(((struct Obj03150 *)a)->f8), (const u16 *)(((struct Obj06099 *)b)->f20));
        func_02027198();
        return;
    case 6:
        func_0200C210((struct Blk34 *)(((struct Obj03150 *)a)->f8), (const u16 *)(((struct Obj06099 *)b)->f20));
        return;
    case 7:
        func_02045838((struct U16Vec *)func_020275C4((void *)(((struct Obj03150 *)a)->f14)), (struct U16Vec *)(((struct Obj03150 *)a)->f3C));
        func_02165844((void *)(((struct Obj06099 *)b)->f20));
        return;
    }
}
