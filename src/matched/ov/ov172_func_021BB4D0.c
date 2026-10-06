/*
 * function: func_021BB4D0
 * address: 0x021BB4D0
 * packet: pkt_ov172_021BB4D0
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: s16 array scratch with direct subscript keeps base in r7; struct field access hoists address of y.
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B898 0x0204B898 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
#include "../include/Obj02880.h"
#include "../include/Obj14307.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
struct Obj;
struct PtS { s16 x, y; };
extern u32 func_0204B98C(struct Actor *);
extern u16 func_0204B898(struct Obj *);
extern void func_02041EE4(u32, u32, u32);
extern void func_0204B454(struct Actor *, struct PtS *, u32);
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021BB4D0(void *unused, u8 *q)
{
    s16 pos[2];
    u8 i;
    int changed = 0;
    if (func_0204B98C(*(struct Actor * *)&((struct Obj02880 *)q)->f6C) == 0 ||
        func_0204B898(*(struct Obj * *)&((struct Obj02880 *)q)->f6C) == 1) {
        if ((u8)q[4] < (u8)q[5]) { q[5] -= 24; changed = 1; }
        else if ((u8)q[4] > (u8)q[5]) { q[5] += 24; changed = 1; }
    }
    if (changed == 1) {
        func_02041EE4(0, 3, 24 - (u8)q[5]);
        for (i = 0; i < 6; i++) {
            u8 *element = q + i * 4;
            func_0204B454(*(struct Actor * *)&((struct Obj14307 *)element)->f58, (struct PtS *)pos, 0);
            pos[1] = q[5] + 180;
            if (i == 5) pos[1] -= 12;
            func_0204B404((struct Obj *)(*(struct Actor * *)&((struct Obj14307 *)element)->f58), (const struct Vec2 *)pos, 0);
        }
    }
}
