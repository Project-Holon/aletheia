/*
 * function: GF_FONT_ReadBits
 * address:  0x0201E4D4
 * packet:   pkt_0201E4D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_0209E74C  0x0209E74C  data
 *
 * The bit reader behind the compressed glyph stream: pulls `n` bits out of a
 * byte stream, most significant bit first.  The state is three fields, the
 * read pointer at +0, the number of bits still unconsumed in the byte at +4,
 * and that byte itself at +8; g_0209E74C is the 0..8 entry table of top-bit
 * masks.  When the request straddles a byte boundary the leading bits are
 * taken first, the next byte is fetched, and the two halves are OR'd back
 * together.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_ReadBits.c
 *       --func GF_FONT_ReadBits --addr 0x0201E4D4 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct BitReader {
    const u8 *src;
    u32       avail;
    u8        cur;
};

extern const u8 g_0209E74C[];

u8 GF_FONT_ReadBits(struct BitReader *r, u8 n)
{
    u8  hi;
    u32 lo;
    u8  cur;
    u32 used;

    if (r->avail < n) {
        hi = r->cur;
        hi &= g_0209E74C[r->avail];
        used = r->avail;
        n = (u8)(n - (u8)used);
        r->src++;
        r->cur = *r->src;
        r->avail = 8;
    } else {
        hi = 0;
        used = 0;
    }

    cur = r->cur;
    lo = g_0209E74C[n] & cur;
    r->avail = r->avail - n;
    if (r->avail == 0) {
        r->src++;
        r->cur = *r->src;
        r->avail = 8;
    } else {
        r->cur = (u8)(cur << n);
    }
    return (u8)((lo >> used) | hi);
}
