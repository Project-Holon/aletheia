/*
 * function: FLDMMDL_DRAW_DeleteEffect
 * address:  0x021A00E0
 * packet:   pkt_ov021_021A00E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetDrawProcWork  0x0216D6F0  thumb  ov010
 *   FLDMMDL_G3DOBJ_DelObj  0x0219D680  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u16 *FLDMMDL_GetDrawProcWork(u32);
extern void FLDMMDL_G3DOBJ_DelObj(u32 a, u32 b);

void FLDMMDL_DRAW_DeleteEffect(u32 a)
{
    FLDMMDL_G3DOBJ_DelObj(a, *FLDMMDL_GetDrawProcWork(a));
}
