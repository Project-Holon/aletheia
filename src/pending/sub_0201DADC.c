/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * function: func_0201DADC
 * address:  0x0201DADC
 * packet:   pkt_0201DA00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   g_0209E744  0x0209E744  data
 *
 * gf_font.c's format teardown, the mirror of func_0201DA00: it dispatches on
 * the format word the selector stored at +0 through a second four-entry table
 * that sits two words after the first one.  Twenty bytes, one indirect call.
 *
 * Every concrete byte is reproduced.  The unresolved relocation is the table
 * base 0x0209E744 and the pool word here is its only witness image-wide, the
 * same dead end as src/pending/sub_0201DA00.c.  Note that the two tables being
 * eight bytes apart is *not* usable as evidence: expressing one as an offset
 * from the other would be a claim that they are one object, and the image does
 * not say so.
 *
 * This is in turn what keeps func_0201D83C, src/pending/sub_0201D83C.c, out of
 * src/matched.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0201DADC.c \
 *       --func func_0201DADC --addr 0x0201DADC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Font {
    u32 unk00;
};

typedef void (*FontFini)(struct Font *f);

extern FontFini g_0209E744[];

void func_0201DADC(struct Font *f)
{
    g_0209E744[f->unk00](f);
}
