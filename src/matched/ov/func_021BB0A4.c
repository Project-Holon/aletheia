/*
 * function: RAIL_ATTR_Delete
 * address:  0x021BB0A4
 * packet:   pkt_021BB0A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   RAIL_ATTR_Release  0x021BB11C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void RAIL_ATTR_Release(u32 *p);
extern u32 func_020307B0(void *p);

void RAIL_ATTR_Delete(u8 *p, u32 a1, u32 a2, u32 a3)
{
    RAIL_ATTR_Release((u32 *)p);
    func_020307B0(p);
}
