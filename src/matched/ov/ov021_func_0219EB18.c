/*
 * function: FLDMMDL_RAIL_LookAroundInit
 * address:  0x0219EB18
 * packet:   pkt_ov021_0219EB18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_RAIL_InitMoveWork  0x0219E968  thumb  ov021
 *   FLDMMDL_RAIL_GetRandomTableEntry  0x0219EA10  thumb  ov021
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb  ov010
 *   d_021D84AC     0x021D84AC  data
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12689.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u32 d_021D84AC[];
extern void *FLDMMDL_RAIL_InitMoveWork(u32 a, u32 size);
extern int FLDMMDL_RAIL_GetRandomTableEntry(u32 *a, int b);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_OffMoveBitMove(u8 *p);

void FLDMMDL_RAIL_LookAroundInit(u32 a, u16 b)
{
    u8 *q = FLDMMDL_RAIL_InitMoveWork(a, 16);
    ((struct Obj12689 *)q)->fC = FLDMMDL_RAIL_GetRandomTableEntry(d_021D84AC, -1);
    ((struct Obj12689 *)q)->fE = b;
    FLDMMDL_SetDrawStatus((void *)a, 0);
    FLDMMDL_OffMoveBitMove((u8 *)a);
}
