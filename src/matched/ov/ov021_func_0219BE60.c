/*
 * function: FLDMMDL_MOVE_DeleteHide
 * address:  0x0219BE60
 * packet:   pkt_ov021_0219BE60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_MOVE_GetHideEffect  0x0219BF48  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_MOVE_GetHideEffect(u32 a);
extern void FIELD_EFFECT_DeleteObject(u32);

void FLDMMDL_MOVE_DeleteHide(u32 a)
{
    u32 r = FLDMMDL_MOVE_GetHideEffect(a);
    if (r != 0) {
        FIELD_EFFECT_DeleteObject(r);
    }
}
