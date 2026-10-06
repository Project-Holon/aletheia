/*
 * function: func_021BABE0
 * address:  0x021BABE0
 * packet:   pkt_ov068_021BABE0
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The clamp of the +0x34 field is a nested ternary (if/else-if reallocates
 * registers); the first call result goes through a local so the sum is
 * `adds r7, r0, r1`.
 *
 * symbols:
 *   func_02040804  0x02040804  arm
 *   func_02041EE4  0x02041EE4  arm
 *   func_0204B404  0x0204B404  arm
 *   d_021BB704     0x021BB704  data  a4
 */
#include "../include/Obj04326.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u16 x; u16 y; } Pt;

extern u32 func_02040804(u32 layer);
extern void func_02041EE4(u32 index, u32 a, u32 b);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u32  d_021BB704[][6];

void func_021BABE0(u8 *p, int a1, int a2, int a3)
{
    int i;
    int v;
    int t;
    Pt pt;

    t = func_02040804(((struct Obj04326 *)p)->f2);
    v = t + a1;
    if (v > a3) {
        v = a3;
    } else if (v < a2) {
        v = a2;
    }
    func_02041EE4((u8)((struct Obj04326 *)p)->f0, 3, v + 0x14);
    func_02041EE4((u8)((struct Obj04326 *)p)->f2, 3, v);
    t = ((struct Obj04326 *)p)->f34 - a1;
    ((struct Obj04326 *)p)->f34 = t;
    ((struct Obj04326 *)p)->f34 = t > 0x10 - a2 ? 0x10 - a2 : (t < 0x10 - a3 ? 0x10 - a3 : t);
    for (i = 0; i < 11; i++) {
        pt.x = d_021BB704[i][2];
        pt.y = ((struct Obj04326 *)p)->f34 + d_021BB704[i][3];
        func_0204B404((struct Obj *)(*(u32 *)(p + i * 4 + 8)), (const struct Vec2 *)(&pt), 0);
    }
}
