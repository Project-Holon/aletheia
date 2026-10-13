/*
 * function: EVENT_TRAINER_EYE_StepResumeMove
 * address:  0x021AE498
 * packet:   pkt_021AE498
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
 *   FLDMMDL_CheckMoveBitMove  0x0216DA5C  thumb  ov010
 *   FLDMMDL_OffMoveBitMovePause  0x0216DB04  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09181.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_CheckMoveBitMove(void *a0);
extern char *FLDMMDL_OffMoveBitMovePause(void *a0);

int EVENT_TRAINER_EYE_StepResumeMove(u32 a, u32 b, u32 c, u32 d)
{
if (FLDMMDL_CheckMoveBitMove((void *)(((struct Obj09181 *)((u8 *)(a)))->f8)) == 1) {
    FLDMMDL_OffMoveBitMovePause((void *)(((struct Obj09181 *)((u8 *)(a)))->f8));
}
((struct Obj09181 *)((u8 *)(a)))->f0 = 1;
return 1;
}

