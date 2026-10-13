/*
 * function: func_021FF2D0
 * address: 0x021FF2D0
 * packet: pkt_ov135_021FF2D0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   func_021FE9B0 0x021FE9B0 thumb ov135
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_020355C4 0x020355C4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   d_02203D4A 0x02203D4A data a2
 */
#include "../include/Obj00018.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern int func_021FE9B0(u8 *);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u8 func_020355C4(void);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern const u16 d_02203D4A[][4];
int func_021FF2D0(u8 *p)
{
    if (CLACT_IsActorAnimActive((struct Actor *)(((struct Obj00018 *)p)->fBF4)) == 0) {
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00018 *)p)->fBF4), d_02203D4A[func_021FE9B0(p)][0]);
        if (func_020355C4() == 1) {
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00018 *)p)->fBF4, 0);
        } else {
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00018 *)p)->fBF4, 1);
        }
        ((struct Obj00018 *)p)->f28 = 1;
    }
    return 2;
}
