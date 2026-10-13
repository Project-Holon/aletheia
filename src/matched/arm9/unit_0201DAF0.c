/*
 * unit:     yes
 * address:  0x0201DAF0
 * packet:   pkt_0201D6D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GF_FONT_FreeGlyphData, GF_FONT_ExitStreamedGlyphs, GF_FONT_ReadGlyph
 *
 * gf_font.c's glyph-buffer release, an empty hook, and the entry point every
 * text routine in the region reaches a glyph through.
 *
 * GF_FONT_ExitStreamedGlyphs is two bytes, `bx lr`, which is `void f(void) {}`, a hook that
 * was never filled in.  It carries no label because it has no prologue.
 *
 * GF_FONT_ReadGlyph looks up the glyph with GF_FONT_GetGlyphIndex and dispatches through the
 * function pointer at +4 of the font object.  GF_FONT_GetGlyphIndex itself, the glyph
 * index lookup at 0x0201DB20, is still open: it reproduces all 154 bytes bar a
 * consistent interchange of r4 with r6, the run cursor against the two binary
 * search bounds, and no declaration order, scope or type tried moves it.  Its
 * one non-obvious detail is worth recording anyway: the base pointer at +0x88
 * has to be spelled `*(struct FontRun **)((u8 *)p + 0x88)` at the top of the
 * function and `p->unk88` at the rebasing site, or the compiler keeps one copy
 * in a register across the loop and spends an extra move; the original
 * rematerialises the address in the cold path instead.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DAF0.c \
 *       --addr 0x0201DAF0 --thumb
 *
 * symbols:
 *   GF_FONT_GetGlyphIndex  0x0201DB20  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Font {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    void *unk0C;
    u8  pad10[0x40];
    void *unk50;
    void *unk54;
    u8  unk58[8];
    void *unk60;
    void *unk64;
    void *unk68;
    u32 unk6C;
    u16 unk70;
    u8  unk72;
    u8  pad73;
    u8  unk74;
    u8  unk75;
    u16 unk76;
    u8  pad78[4];
    u16 unk7C;
    u8  unk7E;
    u8  unk7F;
    void *unk80;
    void *unk84;
    void *unk88;
    void *unk8C;
    void *unk90;
};

extern u32 func_020307B0(void *p);
extern u32  GF_FONT_GetGlyphIndex(struct Font *p, u16 ch);

void GF_FONT_FreeGlyphData(struct Font *p)
{
    func_020307B0(p->unk0C);
    p->unk0C = 0;
}

void GF_FONT_ExitStreamedGlyphs(struct Font *p)
{
}

void GF_FONT_ReadGlyph(struct Font *p, u16 ch, void *c, void *d)
{
    ((void (*)(struct Font *, u32, void *, void *))p->unk04)(
        p, GF_FONT_GetGlyphIndex(p, ch), c, d);
}
