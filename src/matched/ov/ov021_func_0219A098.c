/*
 * function: FLDMMDL_MOVECODE_InitTurnRandom
 * address:  0x0219A098
 * packet:   pkt_ov021_0219A098
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_InitMoveProcWork  0x0216D684  thumb  ov010
 *   FLDMMDL_MOVECODE_GetRandomTableEntry  0x0219B0F0  thumb  ov021
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb
 *   gMmdlRandomWaitFrames     0x021D4FA4  data  a4
 */
#include "../include/Obj12644.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 *FLDMMDL_InitMoveProcWork(u32, u32);
extern int FLDMMDL_MOVECODE_GetRandomTableEntry(u32 a, u32 b);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern int FLDMMDL_OffMoveBitMove(u32);
extern u8 gMmdlRandomWaitFrames[];

int FLDMMDL_MOVECODE_InitTurnRandom(u32 a, u32 b)
{
    u16 *p;
    int k = 8;
    p = FLDMMDL_InitMoveProcWork(a, 8);
    p[1] = FLDMMDL_MOVECODE_GetRandomTableEntry((u32)gMmdlRandomWaitFrames, k - 9);
    ((struct Obj12644 *)p)->f4 = b;
    FLDMMDL_SetDrawStatus((void *)a, 0);
    return FLDMMDL_OffMoveBitMove(a);
}
