/*
 * function: func_021CA2A4
 * address:  0x021CA2A4
 * packet:   pkt_ov021_021CA2A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Linear search of a halfword array.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_021CA2A4(const u16 *arr, u16 val, u16 n)
{
    u16 i;
    for (i = 0; i < n; i++) {
        if (val == arr[i])
            return 1;
    }
    return 0;
}
