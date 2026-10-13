/*
 * function: EVENT_TRAINER_EYE_StepWaitAlert
 * address:  0x021AE5BC
 * packet:   pkt_021AE5BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12100.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_CheckEndAcmd(int a0, u32 a1, u32 a2, u32 a3);

int EVENT_TRAINER_EYE_StepWaitAlert(u32 a, u32 b, u32 c, u32 d)
{
if (FLDMMDL_CheckEndAcmd(((struct Obj12100 *)((u8 *)(a)))->f8, b, c, d) == 1) {
    ((struct Obj12100 *)((u8 *)(a)))->f0 = 9;
}
return 0;
}

