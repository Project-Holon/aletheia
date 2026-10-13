/*
 * function: FLDMMDL_MOVECODE_InitWalkRandom
 * address:  0x0219A290
 * packet:   pkt_ov021_0219A290
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
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_InitMoveProcWork(int a0, int a1, u32 a2, u32 a3);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_OffMoveBitMove(u8 *p);

void FLDMMDL_MOVECODE_InitWalkRandom(u32 a, u32 b, u32 c, u32 d)
{
    u32 *p = FLDMMDL_InitMoveProcWork(a, 16, c, d);
    p[1] = d;
    p[2] = b;
    p[3] = c;
    FLDMMDL_SetDrawStatus((void *)a, 0);
    FLDMMDL_OffMoveBitMove((u8 *)a);
}
