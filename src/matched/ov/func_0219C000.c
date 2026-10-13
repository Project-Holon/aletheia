/*
 * function: FLDMMDL_MOVE_FaceDirTurnSelf
 * address:  0x0219C000
 * packet:   pkt_0219C000
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
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetLocalAcmd  0x0216D438  thumb  ov010
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb
 *   FLDMMDL_OffMoveBitMoveEnd  0x0216DA7C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17962.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FLDMMDL_SetLocalAcmd(char *a0, int a1);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern u32 FLDMMDL_OffMoveBitMove(u32);
extern u32 FLDMMDL_OffMoveBitMoveEnd(u32);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);

int FLDMMDL_MOVE_FaceDirTurnSelf(char *a, u32 b, u32 c, u32 d)
{
FLDMMDL_SetLocalAcmd(a, (((u32)FLDMMDL_ACMD_ConvertCodeByDir((u32)(((u32)FLDMMDL_GetDirDisp((void *)a) << 16) >> 16), (u32)0) << 16) >> 16));
FLDMMDL_OffMoveBitMove((u32)a);
FLDMMDL_OffMoveBitMoveEnd((u32)a);
((struct Obj17962 *)((u8 *)(b)))->f0 = 1;
return 1;
}

