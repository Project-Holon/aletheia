/*
 * function: FLDMMDL_MOVECODE_InitFixedDir
 * address:  0x0219A528
 * packet:   pkt_0219A528
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * FLDMMDL_OffMoveBitMove (0x0216DA50) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_InitMoveProcWork  0x0216D684  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17954.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_MOVE_UpdateOldGridPos(int a0);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void *FLDMMDL_InitMoveProcWork(int a0, int a1, u32 a2, u32 a3);
extern u32 FLDMMDL_OffMoveBitMove(u32);

int FLDMMDL_MOVECODE_InitFixedDir(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj17954 *)((u8 *)(FLDMMDL_InitMoveProcWork(a, 8, c, d))))->f0 = b;
FLDMMDL_SetDrawStatus((void *)a, 0);
FLDMMDL_OffMoveBitMove(a);
return FLDMMDL_MOVE_UpdateOldGridPos(a);
}

