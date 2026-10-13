/*
 * function: FLDMMDL_MOVE_FaceDirWaitTurn
 * address:  0x0219C034
 * packet:   pkt_0219C034
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
 *   FLDMMDL_ACMD_Update  0x02197EDC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17963.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_ACMD_Update(u8 *p);

int FLDMMDL_MOVE_FaceDirWaitTurn(u32 a, u32 b, u32 c, u32 d)
{
if (FLDMMDL_ACMD_Update((u8 *)a) == 1) {
    ((struct Obj17963 *)((u8 *)(b)))->f0 = 2;
    return 1;
}
return 0;
}

