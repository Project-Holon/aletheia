/*
 * function: FLDMMDL_RAIL_RailKeyToDir
 * address:  0x0219E940
 * packet:   pkt_ov021_0219E940
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

u32 FLDMMDL_RAIL_RailKeyToDir(int x)
{
    u32 r = 1;
    switch (x) {
    case 16: r = 0; break;
    case 4: r = 2; break;
    case 2: r = 3; break;
    case 8: break;
    }
    return r;
}
