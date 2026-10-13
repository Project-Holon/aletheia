/*
 * function: FLDMMDL_MOVE_RecoverHide
 * address:  0x0219BE70
 * packet:   pkt_ov021_0219BE70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_MOVE_SetHideEffect  0x0219BF3C  thumb  ov021
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   gHideDrawOffsetRecover     0x021D5480  data   ov021  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u32 a, b, c; } T12;
extern T12 gHideDrawOffsetRecover;
extern void *FLDMMDL_GetMoveProcWork(void *p);
extern void FLDMMDL_MOVE_SetHideEffect(int a, u32 v);
extern void FLDMMDL_SetDrawOffset(u32, void *);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);

void FLDMMDL_MOVE_RecoverHide(u32 a)
{
    u8 *p = FLDMMDL_GetMoveProcWork((void *)a);
    T12 t;
    p[0] = 0;
    FLDMMDL_MOVE_SetHideEffect(a, 0);
    if (p[2] == 0) {
        t = gHideDrawOffsetRecover;
        FLDMMDL_SetDrawOffset(a, &t);
        FLDMMDL_SetMoveBit((void *)a, 2 << 14);
    }
}
