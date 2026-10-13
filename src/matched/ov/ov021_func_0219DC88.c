/*
 * function: FLDMMDL_RAIL_MOVE_AcWalkSet
 * address:  0x0219DC88
 * packet:   pkt_ov021_0219DC88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_RAIL_SetMoveRequest  0x0219E370  thumb  ov021
 *   FLDMMDL_RAIL_SetGridPosByDir  0x0219E6C8  thumb  ov021
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void FLDMMDL_RAIL_SetMoveRequest(u32 a, u32 b, u32 c);
extern void FLDMMDL_RAIL_SetGridPosByDir(u32, u16);
extern int FLDMMDL_SetDirAll(int a0, int a1);
extern void FLDMMDL_SetDrawStatus(u32, u32);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern void FLDMMDL_IncAcmdSeq(u8 *p);

void FLDMMDL_RAIL_MOVE_AcWalkSet(u32 a, u32 b, u32 c, u32 d)
{
    FLDMMDL_RAIL_SetMoveRequest(a, (u16)b, c);
    FLDMMDL_RAIL_SetGridPosByDir(a, b);
    FLDMMDL_SetDirAll((u32)a, (u16)b);
    FLDMMDL_SetDrawStatus(a, d);
    FLDMMDL_SetMoveBit((void *)a, 0x20);
    FLDMMDL_IncAcmdSeq((u8 *)a);
}
