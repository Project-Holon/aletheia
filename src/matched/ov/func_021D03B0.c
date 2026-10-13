/*
 * function: FLDEFF_HIDE_DeleteResources
 * address:  0x021D03B0
 * packet:   pkt_021D03B0
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
 *   FLDEFF_HIDE_FreeResources  0x021D0440  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void FLDEFF_HIDE_FreeResources(u16 *p);
extern u32 func_020307B0(void *p);

void FLDEFF_HIDE_DeleteResources(u32 a, u8 *p)
{
    FLDEFF_HIDE_FreeResources((u16 *)p);
    func_020307B0(p);
}
