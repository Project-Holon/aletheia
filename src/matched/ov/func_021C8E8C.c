/*
 * function: FLDEFF_D06DENKI_Delete
 * address:  0x021C8E8C
 * packet:   pkt_021C8E8C
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
 *   FLDEFF_D06DENKI_FreeResources  0x021C8F38  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void FLDEFF_D06DENKI_FreeResources(u8 *p);
extern u32 func_020307B0(void *p);

void FLDEFF_D06DENKI_Delete(u32 a, u8 *p)
{
    FLDEFF_D06DENKI_FreeResources(p);
    func_020307B0(p);
}
