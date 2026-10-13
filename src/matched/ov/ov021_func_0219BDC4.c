/*
 * function: FLDMMDL_MOVE_InitHide
 * address:  0x0219BDC4
 * packet:   pkt_ov021_0219BDC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   FLDMMDL_InitMoveProcWork  0x0216D684  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   gHideDrawOffsetInit     0x021D5474  data   ov021  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 FLDMMDL_InitMoveProcWork(u32, u32);
typedef unsigned short u16;
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_OffMoveBitMove(u32);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern void FLDMMDL_SetDrawOffset(u32, void *);

typedef struct { u32 a, b, c; } T12;
extern T12 gHideDrawOffsetInit;

void FLDMMDL_MOVE_InitHide(u32 a, u32 b)
{
    T12 t;
    u32 k = 8;
    *(u8 *)(FLDMMDL_InitMoveProcWork(a, 8) + 1) = b;
    FLDMMDL_SetDrawStatus((void *)a, 0);
    FLDMMDL_OffMoveBitMove(a);
    FLDMMDL_SetMoveBit((void *)a, k << 12);
    t = gHideDrawOffsetInit;
    FLDMMDL_SetDrawOffset(a, &t);
}
