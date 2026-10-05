/*
 * function: func_021D1080
 * address:  0x021D1080
 * packet:   pkt_ov021_021D1080
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Bit set in the 128-bit field at +0x28, ignoring out-of-range indices.
 * Region ov021 for the same reason as func_021D1058 (wave A1 witness).
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Flags {
    u8 pad[0x28];
    u8 bits[16];
} Flags;

void func_021D1080(Flags *p, u32 n)
{
    if (n < 0x80) {
        p->bits[(u8)(n >> 3)] |= (u8)(1 << (u8)(n & 7));
    }
}
