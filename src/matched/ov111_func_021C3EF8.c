/*
 * function: func_021C3EF8
 * address:  0x021C3EF8
 * packet:   pkt_ov111_021C3EF8
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 pad5;
    u8 b6;
} Info;

void func_021C3EF8(Info *info)
{
    info->b6++;
    if (info->b6 > (info->f4_1 + 1) * 8 - 1) {
        info->b6 = info->f4_1 * 8;
    }
}
