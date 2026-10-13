/*
 * function: FLDMMDL_MOVE_FaceDirWaitPlayerTurn
 * address:  0x0219C0AC
 * packet:   pkt_0219C0AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * FLDMMDL_OffMoveBitMove (0x0216DA50) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_ACMD_Update  0x02197EDC  thumb  ov021
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb
 *   FLDMMDL_OffMoveBitMoveEnd  0x0216DA7C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17965.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_OffMoveBitMove(u32);
extern u32 FLDMMDL_OffMoveBitMoveEnd(u32);
extern u32 FLDMMDL_ACMD_Update(u8 *p);

int FLDMMDL_MOVE_FaceDirWaitPlayerTurn(u32 a, u32 b, u32 c, u32 d)
{
if (FLDMMDL_ACMD_Update((u8 *)a) == 0) {
    return 0;
}
FLDMMDL_OffMoveBitMove(a);
FLDMMDL_OffMoveBitMoveEnd(a);
((struct Obj17965 *)((u8 *)(b)))->f0 = 2;
return 0;
}

