/*
 * function: MB_SEQ_StepSelectFlash
 * address: 0x021C5C84
 * packet: pkt_ov136_021C5C84
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MB_SEQ_StepSelectFlash 0x021C5C84 thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj10603.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Fade {
    u8 a : 1;
    u8 idx : 7;
    u8 lo : 4;
    u8 hi : 4;
    u8 state;
    u8 count;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
};
struct Obj;
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32);

int MB_SEQ_StepSelectFlash(u8 *p)
{
    struct Fade *s = (struct Fade *)(*(u8 * *)&((struct Obj10603 *)p)->f8 + 0x300);
    switch (s->state) {
    case 0:
        if (s->a == 0) {
            CLACT_SetActorPaletteOffset((struct Obj *)(*(u32 *)(*(u8 * *)&((struct Obj10603 *)p)->f8 + s->idx * 4 + 0x1F0)), s->lo, 1);
        } else {
            func_020413B0(s->idx, s->b4, s->b5, s->b6, s->b7, s->lo);
            func_02041B6C(s->idx);
        }
        s->state++;
        break;
    case 1:
        s->count++;
        if (s->count == 4) {
            if (s->a == 0) {
                CLACT_SetActorPaletteOffset((struct Obj *)(*(u32 *)(*(u8 * *)&((struct Obj10603 *)p)->f8 + s->idx * 4 + 0x1F0)), s->hi, 1);
            } else {
                func_020413B0(s->idx, s->b4, s->b5, s->b6, s->b7, s->hi);
                func_02041B6C(s->idx);
            }
            s->count = 0;
            s->state++;
        }
        break;
    case 2:
        s->count++;
        if (s->count == 2) {
            return 0;
        }
        break;
    }
    return 1;
}
