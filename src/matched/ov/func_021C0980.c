/*
 * function: func_021C0980
 * address:  0x021C0980
 * packet:   pkt_021C0980
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040804  0x02040804  arm
 *   func_02041EE4  0x02041EE4  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B454  0x0204B454  arm
 */
#include "../include/Obj02346.h"

extern unsigned int func_02040804(unsigned int layer);
typedef unsigned int   u32;
extern void func_02041EE4(u32 index, u32 a, u32 b);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *, struct PtS *, unsigned int);

void func_021C0980(int a, unsigned char *p, int a2)
{
    switch (*(unsigned int *)&((struct Obj02346 *)p)->f70) {
    case 0:
        break;
    case 2:
        break;
    case 1:
        if ((int)func_02040804((int)7) >= 0x40) {
            func_02041EE4(7, 3, 0x40);
            ((struct Obj02346 *)p)->f70 = 2;
        } else {
            func_02041EE4(7, 4, 8);
            func_02041EE4(6, 4, 8);
        }
        break;
    case 3:
        if ((int)func_02040804((int)7) <= 0) {
            func_02041EE4(7, 3, 0);
            ((struct Obj02346 *)p)->f70 = 0;
        } else {
            func_02041EE4(7, 5, 8);
            func_02041EE4(6, 5, 8);
        }
        break;
    }
    if (*(int *)(p + 0x5c + 4 * ((struct Obj02346 *)p)->f64) == 0)
        return;
    {
        short v[2];

        switch (*(unsigned int *)&((struct Obj02346 *)p)->f74) {
        case 0:
            break;
        case 2:
            break;
        case 1:
            func_0204B454((struct Actor *)*(int *)(p + 0x5c + 4 * ((struct Obj02346 *)p)->f64), (struct PtS *)v, 1);
            if (v[1] <= 0x70) {
                v[1] = 0x70;
                ((struct Obj02346 *)p)->f74 = 2;
            } else {
                v[1] -= 8;
            }
            func_0204B404((struct Obj *)(*(int *)(p + 0x5c + 4 * ((struct Obj02346 *)p)->f64)), (const struct Vec2 *)v, 1);
            break;
        case 3:
            func_0204B454((struct Actor *)*(int *)(p + 0x5c + 4 * ((struct Obj02346 *)p)->f64), (struct PtS *)v, 1);
            if (v[1] >= 0xb0) {
                v[1] = 0xb0;
                ((struct Obj02346 *)p)->f74 = 0;
            } else {
                v[1] += 8;
            }
            func_0204B404((struct Obj *)(*(int *)(p + 0x5c + 4 * ((struct Obj02346 *)p)->f64)), (const struct Vec2 *)v, 1);
            break;
        }
    }
}
