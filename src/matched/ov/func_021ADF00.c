/*
 * function: FLDEFF_FISHING_Delete
 * address:  0x021ADF00
 * packet:   pkt_021ADF00
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
 *   FLDEFF_FISHING_FreeResources  0x021ADF68  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern int FLDEFF_FISHING_FreeResources(void *a);
extern u32 func_020307B0(void *p);

void FLDEFF_FISHING_Delete(u32 a, u8 *p)
{
    FLDEFF_FISHING_FreeResources(p);
    func_020307B0(p);
}
