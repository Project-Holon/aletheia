/*
 * function: GF_FONT_InitBitReader
 * address:  0x0201E4C8
 * packet:   pkt_0201E4C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Opens the bit reader the glyph decompressor in this packet runs on: the
 * cursor at +0 is the byte pointer, +4 is the number of bits still unread out
 * of the byte cached at +8, and the first byte is latched on the spot.
 *
 * Twelve bytes, no prologue: the function saves nothing, so disasm.py's
 * prologue sweep never labels it and it prints as part of the `.word` run in
 * front of func_0201E4D4
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The bit count is assigned last.  Written before the cached byte the two
 * stores swap and the constant 8 is materialised earlier, four bytes wrong.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201E4C8.c \
 *       --func GF_FONT_InitBitReader --addr 0x0201E4C8 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct BitReader {
    const u8 *src;
    u32       nbits;
    u8        cur;
};

void GF_FONT_InitBitReader(struct BitReader *b, const u8 *p)
{
    b->src = p;
    b->cur = p[0];
    b->nbits = 8;
}
