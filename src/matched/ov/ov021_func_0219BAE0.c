/*
 * function: FLDMMDL_MOVE_InitLookFellow
 * address:  0x0219BAE0
 * packet:   pkt_ov021_0219BAE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_InitMoveProcWork  0x0216D684  thumb  ov010
 *   FLDMMDL_MOVE_UpdateFellowTracking  0x0219BC48  thumb  ov021
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u8 *FLDMMDL_InitMoveProcWork(u32, u32);
extern int FLDMMDL_MOVE_UpdateFellowTracking(int a, u8 *b);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_OffMoveBitMove(u8 *p);

void FLDMMDL_MOVE_InitLookFellow(u32 a)
{
    u8 *p = FLDMMDL_InitMoveProcWork(a, 12);
    FLDMMDL_MOVE_UpdateFellowTracking(a, p);
    FLDMMDL_SetDrawStatus((void *)a, 0);
    FLDMMDL_OffMoveBitMove((u8 *)a);
    p[1] = 0;
}
