/*
 * function: FLDMMDL_MOVECODE_BackForthStepWaitWalk
 * address:  0x0219AA08
 * packet:   pkt_0219AA08
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
 *   FLDMMDL_ACMD_Update  0x02197EDC  thumb  ov021
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb
 *   FLDMMDL_MOVECODE_IsMirrorEventType  0x0219B358  thumb  ov021
 *   FLDMMDL_MOVECODE_EndMirrorTurn  0x0219B404  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17956.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_OffMoveBitMove(u32);
extern u32 FLDMMDL_ACMD_Update(u8 *p);
extern int FLDMMDL_MOVECODE_IsMirrorEventType(u32 a);
extern void FLDMMDL_MOVECODE_EndMirrorTurn(u32 a, u8 *s);

int FLDMMDL_MOVECODE_BackForthStepWaitWalk(u32 a, u32 b, u32 c, u32 d)
{
if (FLDMMDL_ACMD_Update((u8 *)a) == 1) {
    FLDMMDL_OffMoveBitMove(a);
    if (FLDMMDL_MOVECODE_IsMirrorEventType(a) == 1) {
        FLDMMDL_MOVECODE_EndMirrorTurn(a, (u8 *)(b + 4));
    }
    ((struct Obj17956 *)((u8 *)(b)))->f0 = 0;
}
return 0;
}

