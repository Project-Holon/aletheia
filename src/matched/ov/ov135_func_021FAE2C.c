/*
 * function: func_021FAE2C
 * address: 0x021FAE2C
 * packet: pkt_ov135_021FAE2C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9A88 0x021F9A88 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 */
#include "../include/Obj00246.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 func_021F9A88(void *, void *);
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
int func_021FAE2C(u8 *p)
{
    u32 sel = func_021F9A88(p, p + 96);
    if (sel != -2) {
        if (sel <= 8) {
            func_0204B3DC(((struct Obj00246 *)p)->f8, 1);
            func_0204B878(((struct Obj00246 *)p)->f8, 19);
            ((struct Obj00246 *)p)->f48 = 8;
            ((struct Obj00246 *)p)->f38 = sel;
        }
    } else {
        func_0204B3DC(((struct Obj00246 *)p)->f8, 1);
        func_0204B878(((struct Obj00246 *)p)->f8, CLACT_GetActorAnimSeq(((struct Obj00246 *)p)->f8) + 9);
        ((struct Obj00246 *)p)->f48 = 3;
        ((struct Obj00246 *)p)->f4C = 8;
        ((struct Obj00246 *)p)->f38 = -1;
    }
    return -1;
}
