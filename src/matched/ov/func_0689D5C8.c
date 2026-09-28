/*
 * function: func_0689D5C8
 * address:  0x0689D5C8
 * packet:   pkt_0689D5C8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0689D5C8   0x0689D5C8  thumb
 *
 * Scan a table of 3-byte records: find the first record whose first byte is
 * non-zero and whose third byte equals `key`; return its index (0..5), or 6.
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

u8 func_0689D5C8(u8 *base, u8 key)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        if (base[i * 3] != 0 && base[i * 3 + 2] == key)
            return (u8)i;
    }
    return 6;
}
