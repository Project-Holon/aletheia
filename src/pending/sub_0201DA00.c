/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * function: func_0201DA00
 * address:  0x0201DA00
 * packet:   pkt_0201DA00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   g_0209E73C  0x0209E73C  data
 *
 * gf_font.c's format selector: it records the requested glyph format in the
 * object's first word and dispatches on it through a four-entry table of
 * initialisers, handing each the cell width and height the constructor left at
 * +0x7E and +0x7F.  func_0201DADC, src/pending/sub_0201DADC.c, is the matching
 * teardown and dispatches on the same word through the neighbouring table.
 *
 * Every concrete byte is reproduced.  The one unresolved relocation is the
 * table base 0x0209E73C: the pool word inside this function is the only word
 * in the image that holds it, so the `literal` class has no witness left once
 * the compared range is excluded, and no cut helps because the function is
 * twenty bytes of dispatch with nothing to cut away.  It needs a second
 * reference to the table, most likely from an overlay, to move.
 *
 * This is also what keeps func_0201D7EC, src/pending/sub_0201D7EC.c, out of
 * src/matched: its only witness for the call to this function would be having
 * it local in the same unit, and a unit that spans it inherits this same
 * unresolved table word.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0201DA00.c \
 *       --func func_0201DA00 --addr 0x0201DA00 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Font {
    u32 unk00;
    u8  pad04[0x7A];
    u8  unk7E;
    u8  unk7F;
};

typedef void (*FontInit)(struct Font *f, u32 w, u32 h, u32 heap);

extern FontInit g_0209E73C[];

void func_0201DA00(struct Font *f, u32 fmt, u32 heap)
{
    f->unk00 = fmt;
    g_0209E73C[fmt](f, f->unk7E, f->unk7F, heap);
}
