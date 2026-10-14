/*
 * function: COMM_TVT_SYS_GetHeapId
 * address:  0x021BE00C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u16 at +0.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u16 COMM_TVT_SYS_GetHeapId(u16 *p)
{
    return *p;
}
