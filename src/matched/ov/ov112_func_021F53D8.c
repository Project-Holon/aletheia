/*
 * function: MUSICAL_MCSS_ResetRender
 * address:  0x021F53D8
 * packet:   pkt_ov112_021F53D8
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   MUSICAL_MCSS_CopyField  0x021F62FC  thumb  ov112
 *   MUSICAL_MCSS_NoOp8  0x021F62DC  thumb  ov112
 */
#include "../include/Obj01717.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void MUSICAL_MCSS_CopyField(int, int);
extern void MUSICAL_MCSS_NoOp8(char *p);

void MUSICAL_MCSS_ResetRender(int a) {
    if (((struct Obj01717 *)a)->f4 == 1) {
        MUSICAL_MCSS_CopyField(((struct Obj01717 *)a)->fC, ((struct Obj01717 *)a)->f10);
        ((struct Obj01717 *)a)->f8 = ((struct Obj01717 *)a)->f10;
        ((struct Obj01717 *)a)->f4 = 0;
        MUSICAL_MCSS_NoOp8((char *)(((struct Obj01717 *)a)->fC));
    } else {
        MUSICAL_MCSS_CopyField(((struct Obj01717 *)a)->f10, ((struct Obj01717 *)a)->fC);
        ((struct Obj01717 *)a)->f8 = ((struct Obj01717 *)a)->fC;
        ((struct Obj01717 *)a)->f4 = 1;
        MUSICAL_MCSS_NoOp8((char *)(((struct Obj01717 *)a)->f10));
    }
}
