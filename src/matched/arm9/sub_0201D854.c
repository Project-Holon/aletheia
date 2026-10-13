/*
 * function: GF_FONT_LoadResource
 * address:  0x0201D854
 * packet:   pkt_0201D7EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     promoted 2026-09-21: the +0x16C ABS32 to 0x0201DC88 is now
 *           attested `matched` by src/matched/GF_FONT_GetProportionalWidth.c, which closed
 *           this file's last unresolved site.  13 of 13 relocations resolve.
 *
 * symbols:
 *   func_0201D854_File  0x020A7358  data
 *   GF_FONT_GetProportionalWidth       0x0201DC88  thumb
 *   GF_FONT_GetFixedWidth       0x0201DD58  thumb
 *   ARC_TOOL_GetHandleMemberOffsetOut       0x020494F4  arm
 *   func_020493D4       0x020493D4  arm
 *   sub_0204944C        0x0204944C  arm
 *   func_02030734       0x02030734  arm
 *   GF_FONT_GetGlyphIndex  0x0201DB20  thumb
 *
 * gf_font.c's metrics and buffer initialiser, 372 bytes, the largest function
 * in the file and the one func_0201D7EC calls right after the allocation.  It
 * pulls five sections out of the font resource: the 0x14-byte header block at
 * +0x58, the glyph directory at +0x80, either the whole glyph body (preloaded,
 * into a buffer at +0x84) or nothing (streamed), the eight metric bytes at
 * +0x74, and the character map at +0x88.  The hook at +0x6C is set to
 * GF_FONT_GetProportionalWidth for the streamed case and GF_FONT_GetFixedWidth for the preloaded one,
 * and that is the pointer src/matched/unit_0201DC6C.c calls through.  It
 * finishes by priming the fallback advance at +0x70 from the glyph for '?'
 * (0x3F).
 *
 * Three details cost time:
 *
 *   - **`x / 8` and `x % 8` on the same `u8` field get different signedness
 *     treatment.**  The division is a bare `lsrs #3` and the modulo is the
 *     full signed `lsls #29` / `subs` / `rors #29` sequence, in the same
 *     expression, on the same `ldrb`.  Writing the field into a `u32` local
 *     first makes mwcc lower the modulo test to `movs #7` / `tst` and the
 *     function is sixteen bytes short; writing the field expression out twice
 *     keeps the `int` promotion and reproduces both.  An `s32` local does not
 *     compile at all here.
 *   - **248, 266 and 271 are three `__LINE__` arguments and only two pool
 *     words.**  248 is small enough for `movs`; 266 takes a pool word and 271
 *     is that word plus a constant `adds #5`
 *     (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 *   - **The fallback advance is stored twice.**  `f->unk70 = 0;` then the
 *     result of GF_FONT_GetGlyphIndex over it; the first store is not dead, because
 *     GF_FONT_GetGlyphIndex reads the field on the path where no block matches.
 *
 * Every concrete byte is reproduced.  Three relocations stay wildcarded:
 *
 *   - ARC_TOOL_GetHandleMemberOffsetOut is an ARM SDK entry point whose only call site in the
 *     image is the one in this function, so the `label` class has nothing
 *     outside the range to point at.  This alone caps the function.
 *   - GF_FONT_GetProportionalWidth is a 64-byte unlabelled Thumb leaf, the streamed-glyph
 *     hook, and this pool word is its only reference image-wide.  It is not in
 *     any manifest entry: unit_0201DC6C stops at 0x0201DC88.  Matching it
 *     would convert this site to the `matched` class.
 *   - GF_FONT_GetFixedWidth resolves on `matched` from src/matched/unit_0201DD58.c and
 *     is listed here only because the pool word sits inside the compared
 *     range.
 *
 * The fields at +0x60, +0x64 and +0x68 are declared `u32` here rather than the
 * `void *` src/matched/unit_0201DC6C.c gives them, because this function does
 * arithmetic on all three; the loads are identical either way.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0201D854.c  *       --func GF_FONT_LoadResource --addr 0x0201D854 --cc 1.1p1 --thumb
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
    u32 unk60;
    u32 unk64;
    u32 unk68;
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

extern const char func_0201D854_File[];

struct ArcFile;
extern void sub_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern void ARC_TOOL_GetHandleMemberOffsetOut(struct ArcFile *arc, u32 member, u32 *out);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32   GF_FONT_GetGlyphIndex(struct Font *f, u16 ch);

extern u8 GF_FONT_GetProportionalWidth(u8 *obj, u32 id);
extern u32 GF_FONT_GetFixedWidth(struct Font *p);

void GF_FONT_LoadResource(struct Font *f, int resid, u32 flag, u32 heap)
{
    u32 size;

    if (f->unk50 == 0) {
        return;
    }
    sub_0204944C(f->unk50, resid, 0x18, 0x14, f->unk58);
    ARC_TOOL_GetHandleMemberOffsetOut(f->unk50, resid, (u32 *)(&f->unk80));
    f->unk72 = (u8)flag;
    if (flag != 0) {
        f->unk84 = 0;
        f->unk6C = (u32)GF_FONT_GetFixedWidth;
    } else {
        size = f->unk68 - f->unk64;
        f->unk84 = func_02030734(heap, size, 0, func_0201D854_File, 248);
        f->unk6C = (u32)GF_FONT_GetProportionalWidth;
        sub_0204944C(f->unk50, resid, f->unk64, size, f->unk84);
    }
    sub_0204944C(f->unk50, resid, f->unk60, 8, &f->unk74);
    f->unk7E = (u8)(f->unk74 / 8 + ((f->unk74 % 8) ? 1 : 0));
    f->unk7F = (u8)(f->unk75 / 8 + ((f->unk75 % 8) ? 1 : 0));
    f->unk7C = (u16)((f->unk74 * 2) % 8);
    if (f->unk7C == 0) {
        f->unk7C = 8;
    }
    f->unk8C = (void *)(f->unk60 + 8);
    f->unk90 = func_02030734(heap, f->unk76, 0, func_0201D854_File, 266);
    size = func_020493D4(f->unk50, resid) - f->unk68;
    f->unk88 = func_02030734(heap, size, 0, func_0201D854_File, 271);
    sub_0204944C(f->unk50, resid, f->unk68, size, f->unk88);
    f->unk70 = 0;
    f->unk70 = (u16)GF_FONT_GetGlyphIndex(f, 0x3F);
}
