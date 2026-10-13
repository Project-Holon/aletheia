/*
 * function: FLDEFF_IAIGIRI_Delete
 * address:  0x021C94E0
 * packet:   pkt_021C94E0
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
 *   FLDEFF_IAIGIRI_FreeResources  0x021C952C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void FLDEFF_IAIGIRI_FreeResources(void *p);
extern u32 func_020307B0(void *p);

void FLDEFF_IAIGIRI_Delete(u32 a, u8 *p)
{
    FLDEFF_IAIGIRI_FreeResources(p);
    func_020307B0(p);
}
