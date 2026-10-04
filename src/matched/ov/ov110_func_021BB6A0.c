/*
 * function: func_021BB6A0
 * address: 0x021BB6A0
 * packet: pkt_ov110_021BB6A0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: ordered if/else chain, not switch dispatch; template word is 0x012C0190.
 * symbols:
 *   d_021C38D0 0x021C38D0 data ov110 a2
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BAC3C 0x021BAC3C thumb ov110
 *   func_021BCF7C 0x021BCF7C thumb ov110
 *   func_021BB224 0x021BB224 thumb ov110
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../include/Obj04445.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct { s16 x, y; } Vec2;
extern const Vec2 d_021C38D0;
extern u8 func_021BF6DC(u8 *);
extern unsigned func_021BAC3C(u8 *);
extern void func_021BCF7C(u8 *, int, int);
extern void func_021BB224(unsigned, int *, int *);
extern void func_0204B404(void *, const Vec2 *, unsigned);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
void func_021BB6A0(u8 *p, unsigned index)
{
    Vec2 pos;
    int x, y;
    int state;
    u8 *q;
    pos = d_021C38D0;
    if (func_021BF6DC(*(u8 * *)&((struct Obj04445 *)p)->f4) == 0 && index != 254) {
        pos.x = 48 + 80 * (index % 3U);
        pos.y = 64 + 24 * (index / 3U);
        state = 4;
    } else {
        q = (u8 *)func_021BAC3C(*(u8 * *)&((struct Obj04445 *)p)->f0);
        state = 16;
        if (index == 252) {
            if (**(int * *)&((struct Obj04445 *)p)->f5C == 0) func_021BCF7C(q, 0, 1);
            else func_021BCF7C(q, 0, 0);
        } else if (index == 253) {
            if (**(int * *)&((struct Obj04445 *)p)->f5C == 0) func_021BCF7C(q, 1, 1);
            else func_021BCF7C(q, 0, 0);
        } else if (index == 254) {
            if (**(int * *)&((struct Obj04445 *)p)->f5C == 0) func_021BCF7C(q, 2, 1);
            else func_021BCF7C(q, 0, 0);
        } else {
            func_021BCF7C(q, 0, 0);
            func_021BB224(index, &x, &y);
            pos.x = x + 18;
            pos.y = y + 56;
            state = 6;
        }
    }
    func_0204B404(((struct Obj04445 *)p)->f54, &pos, 0);
    func_0204B878(((struct Obj04445 *)p)->f54, state);
}
