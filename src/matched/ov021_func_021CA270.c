/*
 * function: func_021CA270
 * address:  0x021CA270
 * packet:   pkt_ov021_021CA270
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Maps a kind 0..8 to a small class number.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_021CA270(int kind)
{
    switch (kind) {
    case 0:
    case 4:
    case 5:
        return 3;
    case 1:
    case 6:
        return 4;
    case 2:
    case 3:
    case 7:
    case 8:
        return 2;
    }
    return 0;
}
