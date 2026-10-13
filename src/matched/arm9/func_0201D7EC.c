/*
 * function: func_0201D7EC
 * address:  0x0201D7EC
 * packet:   pkt_0201D7EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   GF_FONT_LoadResource 0x0201D854 thumb
 *   GF_FONT_SetFormat 0x0201DA00 thumb
 *   lbl_020A7358  0x020A7358 data
 *
 * gf_font.c's constructor: allocates the 0x94-byte font object, opens the
 * resource handle for `a0`, records the archive id at +0x54, then hands the
 * object to GF_FONT_LoadResource (metrics and buffers) and GF_FONT_SetFormat (the format
 * selector).  A null allocation returns straight out, which is why both calls
 * sit inside the one guard.
 *
 * Promoted 2026-09-21 from src/pending/func_0201D7EC.c with no change to the
 * C: both calls now resolve on the `matched` class from
 * src/matched/sub_0201D854.c and src/matched/sub_0201DA00.c, which were
 * MATCH-parked when this file was written.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201D7EC.c \
 *       --func func_0201D7EC --addr 0x0201D7EC --cc 1.1p1 --thumb
 *   EXACT, 80 bytes, 5 relocation sites, all 5 resolved.
 */

typedef unsigned int u32;

struct GfFont {
    char pad_00[0x50];
    void *field_50;
    int field_54;
};

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
struct Font;
extern void GF_FONT_LoadResource(struct Font *f, int resid, u32 flag, u32 heap);
extern void GF_FONT_SetFormat(struct Font *f, u32 fmt, u32 heap);
extern const char lbl_020A7358[];

struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId)
{
    struct GfFont *font = func_02030734(heapId, 0x94, 0, lbl_020A7358, 0xC0);

    if (font != 0) {
        font->field_50 = func_020490F4(a0, heapId);
        font->field_54 = a1;
        GF_FONT_LoadResource((struct Font *)font, a1, a3, heapId);
        GF_FONT_SetFormat((struct Font *)font, a2, heapId);
    }
    return font;
}
