/*
 * function: TR_AI_CmdMapMoveToEffectSequence
 * address:  0x02189524
 * packet:   pkt_ov096_02189524
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   TR_AI_GetMoveParam  0x0218A378  thumb  ov096
 */
#include "../include/Obj07924.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int TR_AI_GetMoveParam(int, u16, int);

int TR_AI_CmdMapMoveToEffectSequence(int a, int b) {
    int t;
    if (((struct Obj07924 *)b)->f38 != 0) {
        t = TR_AI_GetMoveParam(b, (u16)((struct Obj07924 *)b)->f38, 0x1c);
    } else {
        t = -1;
    }
    ((struct Obj07924 *)b)->f38 = t;
    return ((struct Obj07924 *)b)->fC4;
}
