/*
 * function: FLDEFF_RIPPLE_Delete
 * address:  0x021C47E8
 * packet:   pkt_021C47E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   FLDEFF_RIPPLE_RemoveActor  0x021C483C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void FLDEFF_RIPPLE_RemoveActor(u8 *p);
extern u32 func_020307B0(void *p);

void FLDEFF_RIPPLE_Delete(u32 a, u8 *p)
{
    FLDEFF_RIPPLE_RemoveActor(p);
    func_020307B0(p);
}
