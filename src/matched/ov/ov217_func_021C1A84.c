/*
 * function: CircleGraph_FindSliceIndexImpl
 * address:  0x021C1A84
 * packet:   pkt_ov217_021C1A84
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

struct Ent {
    u8 pad0[0x1C];
};

u8 CircleGraph_FindSliceIndexImpl(u8 *p, u8 key)
{
    int i;
    int n;
    u8 v;
    n = p[0x1AC];
    for (i = 0; i < n; i++) {
        v = p[0x1C + i * 0x14];
        if (v == key) {
            return i;
        }
    }
    return 0;
}
