/*
 * function: WORLDTRADE_INPUT_StateRestoreCursorAlt
 * address:  0x021FBA5C
 * packet:   pkt_021FBA5C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020355C4  0x020355C4  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *
 * State select before the notify call.
 */
#include "../include/Obj05872.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern u8 func_020355C4(void);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *a, unsigned int b);

int WORLDTRADE_INPUT_StateRestoreCursorAlt(u8 *p)
{
    u32 v;
    int n;

    ((struct Obj05872 *)p)->f48 = 0x16;
    ((struct Obj05872 *)p)->f44 = ((struct Obj05872 *)p)->f3A;
    if (func_020355C4() == 1) {
        v = ((struct Obj05872 *)p)->f8;
        n = 0;
    } else {
        v = ((struct Obj05872 *)p)->f8;
        n = 1;
    }
    CLACT_SetActorDrawEnable((struct Obj *)v, n);
    return -1;
}

