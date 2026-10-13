/*
 * function: FLDMMDL_RAIL_GetTableLength
 * address:  0x0219E9F8
 * packet:   pkt_ov021_0219E9F8
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

int FLDMMDL_RAIL_GetTableLength(u32 *arr, u32 v)
{
    int i;
    for (i = 0; arr[i] != v; i++) {
    }
    return i;
}
