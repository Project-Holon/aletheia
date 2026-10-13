/*
 * function: FLDMMDL_MOVE_HideCreateEffect
 * address:  0x0219BED0
 * packet:   pkt_ov021_0219BED0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDEFF_HIDE_Create  0x0219BEB4  thumb  ov021
 *   FLDMMDL_MOVE_SetHideEffect  0x0219BF3C  thumb  ov021
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb  ov010
 *   FLDMMDL_OffMoveBitMoveEnd  0x0216DA7C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDEFF_HIDE_Create(u32 a, u32 b);
extern void FLDMMDL_MOVE_SetHideEffect(int a, u32 v);
extern void FLDMMDL_OffMoveBitMove(u8 *p);
extern void FLDMMDL_OffMoveBitMoveEnd(u8 *p);

int FLDMMDL_MOVE_HideCreateEffect(u32 a, u8 *s)
{
    if (s[2] == 0) {
        FLDMMDL_MOVE_SetHideEffect(a, FLDEFF_HIDE_Create(a, s[1]));
    }
    FLDMMDL_OffMoveBitMove((u8 *)a);
    FLDMMDL_OffMoveBitMoveEnd((u8 *)a);
    s[0]++;
    return 0;
}
