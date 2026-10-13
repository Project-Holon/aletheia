/*
 * function: EVENT_TRAINER_EYE_StepWaitMark
 * address:  0x021AE58C
 * packet:   pkt_021AE58C
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
 *   FLDEFF_GYOE_IsFinished  0x021BB5C8  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09182.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_EFFECT_DeleteObject(u32);
extern int FLDEFF_GYOE_IsFinished(u32 a);

int EVENT_TRAINER_EYE_StepWaitMark(u32 a, u32 b, u32 c, u32 d)
{
if (FLDEFF_GYOE_IsFinished(((struct Obj09182 *)((u8 *)(a)))->f2C) == 1) {
    FIELD_EFFECT_DeleteObject(((struct Obj09182 *)((u8 *)(a)))->f2C);
    ((struct Obj09182 *)((u8 *)(a)))->f0 = 9;
}
return 0;
}

