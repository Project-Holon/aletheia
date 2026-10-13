/*
 * function: FLDMMDL_RAIL_StoreNowLocation
 * address:  0x0219EA78
 * packet:   pkt_ov021_0219EA78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B7DC0  0x021B7DC0  thumb  ov021
 *   FLDMMDL_RAIL_StoreLocation  0x0219EAD8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void func_021B7DC0(void *p, u16 *out);
extern void FLDMMDL_RAIL_StoreLocation(u32 *p, u16 *src);

void FLDMMDL_RAIL_StoreNowLocation(u32 *p, u32 a1)
{
    u16 buf[4];
    func_021B7DC0((void *)*p, buf);
    FLDMMDL_RAIL_StoreLocation(p, buf);
}
