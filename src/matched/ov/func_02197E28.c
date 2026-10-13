/*
 * function: FLDMMDL_ACMD_ListStateWaitEnd
 * address:  0x02197E28
 * packet:   pkt_02197E28
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
#include "../include/Obj12073.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_CheckEndAcmd(int a0, u32 a1, u32 a2, u32 a3);

int FLDMMDL_ACMD_ListStateWaitEnd(u32 a, u32 b, u32 c, u32 d)
{
if (FLDMMDL_CheckEndAcmd(((struct Obj12073 *)((u8 *)(a)))->fC, b, c, d) == 0) {
    return 0;
}
((struct Obj12073 *)((u8 *)(a)))->f0 = 4;
return 1;
}

