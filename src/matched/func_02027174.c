/*
 * function: func_02027174
 * address:  0x02027174
 * packet:   pkt_02027174
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module: inserts three bits (6..8) into the
 * word at +0x10 of the nested object at +4, then sets the byte at +0x62.
 * Pairs with func_02027138; the inner-object pointer pins the two-step
 * address form (see func_0202715C).
 *
 * symbols:
 *   g_02146940  0x02146940  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Inner {
    u8  pad00[0x0c];
    u32 f0c;
    u8  pad10[0x4e];
    u8  f5e;
};

struct Outer {
    u32 f00;
    struct Inner in;
};

extern struct Outer *g_02146940;

void func_02027174(u32 x)
{
    struct Inner *in = &g_02146940->in;

    in->f0c = (in->f0c & 0xFFFFFE3Fu) | ((x << 29) >> 23);
    in->f5e = 1;
}
