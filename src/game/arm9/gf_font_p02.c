/*
 * file:     gf_font_p02.c
 * unit:     yes
 * function: func_0201D9C8, func_0201DA00, func_0201DA24, func_0201DAA4, func_0201DADC, func_0201DAF0, sub_0201DB00, func_0201DB04
 * address:  0x0201D9C8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0209E73C  0x0209E73C  data
 *   func_0201DA24_File  0x020A7358  data
 *   func_020493D4       0x020493D4  arm
 *   func_02030734       0x02030734  arm
 *   sub_0204944C        0x0204944C  arm
 *   func_0201DBBC       0x0201DBBC  thumb
 *   func_0201DE40       0x0201DE40  thumb
 *   func_0201E538       0x0201E538  thumb
 *   func_0201E738       0x0201E738  thumb
 *   func_0201E928       0x0201E928  thumb
 *   func_0201DBF4  0x0201DBF4  thumb
 *   g_0209E744  0x0209E744  data
 */
#include "../../matched/include/Obj06870.h"

struct ArcFile;
struct Font_0201D9C8;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Font_0201D9C8 {
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

struct Font_0201DA00 {
    u32 unk00;
    u8  pad04[0x7A];
    u8  unk7E;
    u8  unk7F;
};

typedef void (*FontInit)(struct Font_0201DA00 *f, u32 w, u32 h, u32 heap);

struct Font_0201DA24 {
    u32   unk00;
    u32   unk04;
    u32   unk08;
    void *unk0C;
    u8    pad10[0x40];
    void *unk50;
    u32   unk54;
    u8    pad58[0x34];
    u32   unk8C;
};

typedef void (*FontFini)(struct Font_0201D9C8 *f);

struct Font_0201DAF0 {
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
extern void func_02049238(void *p);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void sub_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern void func_0201DBBC(const struct Font_0201DA24 *f, u32 i, void *d, u8 *out);
extern void func_0201DE40(const u8 *src, u32 n, u16 *dst);
extern void func_0201E538(const u8 *src, u32 n, u16 *dst);
extern void func_0201E738(const u8 *src, u32 n, u16 *dst);
extern void func_0201E928(const u8 *src, u32 n, u16 *dst);
extern void func_0201DBF4(const struct Font_0201D9C8 *f, u32 i, void *d, u8 *out);
void func_0201DAA4(char *p, int a, int b);
extern u32  func_0201DB20(struct Font_0201DAF0 *p, u16 ch);
extern FontInit g_0209E73C[];
extern const char func_0201DA24_File[];
extern FontFini g_0209E744[];




/*
 * gf_font.c's buffer release: frees the three heap blocks the constructor hung
 * off the object at +0x90, +0x84 and +0x88 and closes the resource handle at
 * +0x50, each guarded by its own null check.
 *
 * All three offsets are past the reach of a Thumb `ldr` immediate, so each
 * access costs an `adds rN, #imm` that is an encoding artefact rather than a
 * pointer in the source (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D9C8.c \
 *       --addr 0x0201D9C8 --thumb
 */
void func_0201D9C8(struct Font_0201D9C8 *p)
{
    if (p->unk90 != 0) {
        func_020307B0(p->unk90);
    }
    if (p->unk84 != 0) {
        func_020307B0(p->unk84);
    }
    if (p->unk88 != 0) {
        func_020307B0(p->unk88);
    }
    if (p->unk50 != 0) {
        func_02049238(p->unk50);
    }
}


/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
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
void func_0201DA00(struct Font_0201DA00 *f, u32 fmt, u32 heap)
{
    f->unk00 = fmt;
    g_0209E73C[fmt](f, f->unk7E, f->unk7F, heap);
}


void func_0201DA24(struct Font_0201DA24 *f, u32 a, u32 b, u8 heap)
{
    u32 size;
    u32 p;

    size = func_020493D4(f->unk50, f->unk54) - f->unk8C;
    f->unk0C = func_02030734(heap, size, 0, func_0201DA24_File, 363);
    sub_0204944C(f->unk50, f->unk54, f->unk8C, size, f->unk0C);
    f->unk04 = (u32)func_0201DBBC;
    if (a == 1) {
        p = (u32)func_0201DE40;
        if (b != 1) {
            p = (u32)func_0201E538;
        }
        f->unk08 = p;
    } else {
        p = (u32)func_0201E738;
        if (b != 1) {
            p = (u32)func_0201E928;
        }
        f->unk08 = p;
    }
}



/*
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
void func_0201DAA4(char *p, int a, int b)
{
    ((struct Obj06870 *)p)->fC = 0;
    ((struct Obj06870 *)p)->f4 = (u32)func_0201DBF4;
    if (a == 1)
        ((struct Obj06870 *)p)->f8 = (b == 1) ? (u32)func_0201DE40 : (u32)func_0201E538;
    else
        ((struct Obj06870 *)p)->f8 = (b == 1) ? (u32)func_0201E738 : (u32)func_0201E928;
}



/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
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
void func_0201DADC(struct Font_0201D9C8 *f)
{
    g_0209E744[f->unk00](f);
}


/*
 * gf_font.c's glyph-buffer release, an empty hook, and the entry point every
 * text routine in the region reaches a glyph through.
 *
 * sub_0201DB00 is two bytes, `bx lr`, which is `void f(void) {}`, a hook that
 * was never filled in.  It carries no label because it has no prologue.
 *
 * func_0201DB04 looks up the glyph with func_0201DB20 and dispatches through the
 * function pointer at +4 of the font object.  func_0201DB20 itself, the glyph
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
 */
void func_0201DAF0(struct Font_0201DAF0 *p)
{
    func_020307B0(p->unk0C);
    p->unk0C = 0;
}

/*
 * gf_font.c's glyph-buffer release, an empty hook, and the entry point every
 * text routine in the region reaches a glyph through.
 *
 * sub_0201DB00 is two bytes, `bx lr`, which is `void f(void) {}`, a hook that
 * was never filled in.  It carries no label because it has no prologue.
 *
 * func_0201DB04 looks up the glyph with func_0201DB20 and dispatches through the
 * function pointer at +4 of the font object.  func_0201DB20 itself, the glyph
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
 */
void sub_0201DB00(struct Font_0201DAF0 *p)
{
}

/*
 * gf_font.c's glyph-buffer release, an empty hook, and the entry point every
 * text routine in the region reaches a glyph through.
 *
 * sub_0201DB00 is two bytes, `bx lr`, which is `void f(void) {}`, a hook that
 * was never filled in.  It carries no label because it has no prologue.
 *
 * func_0201DB04 looks up the glyph with func_0201DB20 and dispatches through the
 * function pointer at +4 of the font object.  func_0201DB20 itself, the glyph
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
 */
void func_0201DB04(struct Font_0201DAF0 *p, u16 ch, void *c, void *d)
{
    ((void (*)(struct Font_0201DAF0 *, u32, void *, void *))p->unk04)(
        p, func_0201DB20(p, ch), c, d);
}
