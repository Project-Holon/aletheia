/*
 * function: EVENT_TRAINER_EYE_StepStartMark
 * address:  0x021AE56C
 * packet:   pkt_021AE56C
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
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_GYOE_SetMMdl  0x021BB528  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07221.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELDMAP_GetEffect(u8 *p);
extern u32 FLDEFF_GYOE_SetMMdl(u32, u32, u32, u32);

int EVENT_TRAINER_EYE_StepStartMark(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj07221 *)((u8 *)(a)))->f2C = FLDEFF_GYOE_SetMMdl(FIELDMAP_GetEffect((u8 *)(((struct Obj07221 *)((u8 *)(a)))->f30)), ((struct Obj07221 *)((u8 *)(a)))->f8, 0, 0);
((struct Obj07221 *)((u8 *)(a)))->f0 = 6;
return 0;
}

