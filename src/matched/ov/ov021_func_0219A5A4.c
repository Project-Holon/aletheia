/*
 * function: FLDMMDL_MOVECODE_InitSpin
 * address:  0x0219A5A4
 * packet:   pkt_ov021_0219A5A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_InitMoveProcWork  0x0216D684  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb  ov010
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u8 *FLDMMDL_InitMoveProcWork(u32, u32);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_OffMoveBitMove(u8 *p);
extern int FLDMMDL_MOVE_UpdateOldGridPos(int a0);

void FLDMMDL_MOVECODE_InitSpin(u32 a, u8 b)
{
    u8 *p = FLDMMDL_InitMoveProcWork(a, 8);
    *p = b;
    FLDMMDL_SetDrawStatus((void *)a, 0);
    FLDMMDL_OffMoveBitMove((u8 *)a);
    FLDMMDL_MOVE_UpdateOldGridPos(a);
}
