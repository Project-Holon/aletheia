/*
 * unit:     yes
 * address:  0x0201D7C4
 * packet:   pkt_0201D6D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: PRINTSYS_GetNextRecord
 *
 * Steps the printsys.c record ring one slot on and returns the word stored
 * there, which is the next record or NULL.  The ring lives at +0x18 of the
 * object src/matched/unit_0201C450.c builds and its records are 0x1C bytes.
 *
 * Four `lsls #16` / `lsrs #16` pairs for one offset is the tell that the
 * arithmetic went through a `u16`-parameter helper the compiler inlined: the
 * argument is truncated, the parameter is truncated again on entry, the return
 * value is truncated, and the caller truncates it once more before indexing.
 * Reproducing them needs a `u32` local with an explicit `(u16)` written at each
 * of the four points; a `u16` local folds the redundant casts away and the
 * function is ten bytes short.
 *
 * GF_FONT_CopyStrbufD6D8 and GF_FONT_Copy, the two functions in front of this one, are
 * still open; see the note in src/matched/unit_0201D69C.c, which this work
 * narrows.  GF_FONT_CopyStrbufD6D8 is EXACT when it is compiled in a range with
 * GF_FONT_Copy, and GF_FONT_Copy is four bytes short: the original spills the
 * byte counter and keeps the ring cursor in r4, and every source shape tried
 * makes the opposite choice.  Since GF_FONT_Copy's only callers are the three
 * inside GF_FONT_CopyStrbufD6D8 the two cannot be cut apart, so neither lands.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D7C4.c \
 *       --addr 0x0201D7C4 --thumb
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;

struct PrintSys {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u8  unk06;
    u8  unk07;
    u32 unk08;
    u32 unk0C;
    void *unk10;
    void *unk14;
    u8  buf[4];
};

void *PRINTSYS_GetNextRecord(struct PrintSys *p, void *q)
{
    u32 off = (u16)((u8 *)q - &p->buf[0]);

    off = (u16)((u16)off + 0x1C);
    if (off >= p->unk04) {
        off = 0;
    }
    return *(void **)&p->buf[(u16)off];
}
