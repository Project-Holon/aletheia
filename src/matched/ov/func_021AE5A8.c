/*
 * function: EVENT_TRAINER_EYE_StepStartAlert
 * address:  0x021AE5A8
 * packet:   pkt_021AE5A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12099.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FLDMMDL_SetAcmd(void *a0, u16 a1);

int EVENT_TRAINER_EYE_StepStartAlert(u32 a, u32 b, u32 c, u32 d)
{
FLDMMDL_SetAcmd((void *)(((struct Obj12099 *)((u8 *)(a)))->f8), 101);
((struct Obj12099 *)((u8 *)(a)))->f0 = 8;
return 0;
}

