/*
 * function: FLDMMDL_MOVECODE_SpinStepWaitTurn
 * address:  0x0219A638
 * packet:   pkt_0219A638
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * FLDMMDL_GetEventType (0x0216D5A8) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_ACMD_Update  0x02197EDC  thumb  ov021
 *   FLDMMDL_GetEventType  0x0216D5A8  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12074.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_GetEventType(u32);
extern u32 FLDMMDL_ACMD_Update(u8 *p);

int FLDMMDL_MOVECODE_SpinStepWaitTurn(u32 a, u32 b, u32 c, u32 d)
{
if (FLDMMDL_ACMD_Update((u8 *)a) == 0) {
    return 0;
}
if (FLDMMDL_GetEventType(a) != 11) {
    ((struct Obj12074 *)((u8 *)(b)))->f4 = 0;
}
((struct Obj12074 *)((u8 *)(b)))->f2 = 2;
return 1;
}

