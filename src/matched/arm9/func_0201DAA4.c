/*
 * function: func_0201DAA4
 * address:  0x0201DAA4
 * packet:   pkt_0201DA24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201DBF4  0x0201DBF4  thumb
 *   func_0201DE40  0x0201DE40  thumb
 *   func_0201E538  0x0201E538  thumb
 *   func_0201E738  0x0201E738  thumb
 *   func_0201E928  0x0201E928  thumb
 *
 * gf_font.c's format-1 hook installer: clears +0xC, plants the shared measure
 * hook func_0201DBF4 at +4, and picks one of four glyph decoders for +8 on the
 * 2x2 cross of the two flags (a == 1 selects the first pair, b == 1 the first
 * of each pair).  src/matched/func_0201DE40.c is the (1,1) decoder.
 *
 * Promoted 2026-09-21.  The file was parked at MATCH with the last pool word
 * declared as `func_0201E938`, an address that is NOT a function start: it is
 * the first `bl` inside func_0201E928.  Because the naming convention derives
 * the address from the identifier, the extern was pinned sixteen bytes into
 * the fourth decoder, where nothing can attest it (and, being a `bl`, it was
 * even guessed ARM).  The pool word is 0x0201E929, i.e. thumb func_0201E928;
 * renaming the extern is the whole fix and the concrete bytes never changed.
 * The lesson is that a wildcarded relocation hides a wrong address as
 * effectively as a missing witness does.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201DAA4.c \
 *       --func func_0201DAA4 --addr 0x0201DAA4 --cc 1.1p1 --thumb
 *   EXACT, 56 bytes, 5 relocation sites, all 5 resolved.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned char  u8;
struct Font;
extern void func_0201DBF4(const struct Font *f, u32 i, void *d, u8 *out);
extern void func_0201DE40(const u8 *src, u32 n, u16 *dst);
extern void func_0201E538(const u8 *src, u32 n, u16 *dst);
extern void func_0201E738(const u8 *src, u32 n, u16 *dst);
extern void func_0201E928(const u8 *src, u32 n, u16 *dst);

void func_0201DAA4(char *p, int a, int b)
{
    *(u32 *)(p + 0xc) = 0;
    *(u32 *)(p + 4) = (u32)func_0201DBF4;
    if (a == 1)
        *(u32 *)(p + 8) = (b == 1) ? (u32)func_0201DE40 : (u32)func_0201E538;
    else
        *(u32 *)(p + 8) = (b == 1) ? (u32)func_0201E738 : (u32)func_0201E928;
}
