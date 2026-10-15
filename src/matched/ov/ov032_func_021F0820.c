/*
 * function: BEACON_VIEW_HasRepeatedDigits
 * address:  0x021F0820
 * packet:   pkt_ov032_021F0820
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

int BEACON_VIEW_HasRepeatedDigits(u32 x)
{
    u32 d;

    if (x / 100 == 0)
        return 0;
    d = x % 10;
    x = x / 10;
    do {
        if ((u8)(x % 10) != d)
            return 0;
        x = x / 10;
    } while (x != 0);
    return 1;
}
