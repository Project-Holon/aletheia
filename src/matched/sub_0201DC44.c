/*
 * function: func_0201DC44
 * address:  0x0201DC44
 * packet:   pkt_0201DB20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * gf_font.c's glyph hand-off: the rendering hook installed at +8 of the font
 * object is called on the glyph bitmap, which starts three bytes into the
 * glyph record, and the record's own three metric bytes plus the byte at +0x59
 * of the font object are copied into the caller's four-byte descriptor.
 *
 * The width is a `u32` parameter and the hook takes it as `u16`, which is what
 * the single `lsls #16` / `lsrs #16` pair before the call is: a `u16`
 * parameter here would make the caller truncate instead and both callers in
 * this packet are two bytes short.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DC44.c \
 *       --func func_0201DC44 --addr 0x0201DC44 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Font {
    u32   pad00[2];
    void (*unk08)(const u8 *src, u16 w, void *dst);
    u32   pad0C[19];
    u8    pad58;
    u8    unk59;
};

void func_0201DC44(struct Font *f, const u8 *g, u32 w, void *d, u8 *out)
{
    f->unk08(g + 3, (u16)w, d);
    out[0] = g[0];
    out[1] = g[1];
    out[2] = g[2];
    out[3] = f->unk59;
}
