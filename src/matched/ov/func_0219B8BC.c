/*
 * function: FLDMMDL_MOVE_InitLookPlayer
 * address:  0x0219B8BC
 * packet:   pkt_0219B8BC
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
 *   FLDMMDL_InitMoveProcWork  0x0216D684  thumb  ov010
 *   FLDMMDL_MOVE_UpdatePlayerTracking  0x0219B984  thumb  ov021
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb
 *   FLDMMDL_SetStatusBitFellowHit  0x0216DAE0  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void *FLDMMDL_InitMoveProcWork(int a0, int a1, u32 a2, u32 a3);
extern u32 FLDMMDL_OffMoveBitMove(u32);
extern u32 FLDMMDL_SetStatusBitFellowHit(u32, u32);
extern int FLDMMDL_MOVE_UpdatePlayerTracking(u32 a, u32 b);

int FLDMMDL_MOVE_InitLookPlayer(u32 a, u32 b, u32 c, u32 d)
{
FLDMMDL_MOVE_UpdatePlayerTracking(a, (u32)FLDMMDL_InitMoveProcWork(a, 8, c, d));
FLDMMDL_SetDrawStatus((void *)a, 0);
FLDMMDL_OffMoveBitMove(a);
return FLDMMDL_SetStatusBitFellowHit(a, 0);
}

