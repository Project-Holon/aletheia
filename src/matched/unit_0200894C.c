/*
 * The second half of the id 0x1C save-block file, matched as one byte range.
 * Written from the disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x0200894C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0200894C, sub_02008954, sub_0200895C, sub_02008964,
 *           sub_0200896C, sub_02008970, sub_02008978, sub_02008980,
 *           sub_02008988, sub_02008990, sub_02008998, sub_020089A0
 *
 * alias: twelve accessors on the same 0x9C-byte block unit_02008828.c opens.
 * The two files would be one but for the pair at 0x0200892C and 0x0200893C
 * sitting between them, which reach 0x02014468 and 0x02014464 and are the only
 * code in the image that does, so the addresses those two relocations need
 * cannot be attested from outside the bytes under test.  They are recorded as
 * a near miss in docs/MATCHING.md and skipped here; everything on either side
 * of them is EXACT.  0x0200894C..0x020089A8 is 92 bytes.
 *
 * All twelve are unlabelled in the generated listing, which emits the whole
 * range as data words: each is two instructions with no register-saving
 * prologue, so disasm.py's sweep never sees them.  They were read out of the
 * bytes and the byte range they occupy is closed on both sides, so nothing is
 * being guessed about where they begin and end.
 *
 * One detail worth keeping: the +0x78 word is reached with a plain
 * `str r1, [r0, #0x78]` while the halfwords at +0x76, +0x7C and +0x7E each
 * cost an `adds r0, #imm` first.  That is not a type or a source difference,
 * it is the Thumb encodings: the word form of str scales its 5-bit immediate
 * by 4 and reaches 124, the halfword form scales by 2 and stops at 62.
 *
 * This unit supersedes src/matched/sub_02008954.c, which matched eight of
 * these bytes on its own.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200894C.c \
 *       --addr 0x0200894C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* Only the tail of the block is reachable from this file; the layout is
 * documented in unit_02008828.c. */
struct Sub02008828Obj {
    u8  unk00[0x73];
    u8  unk73;
    u8  unk74;
    u8  unk75;
    u16 unk76;
    u32 unk78;
    u16 unk7C;
    u16 unk7E;
};

void sub_0200894C(struct Sub02008828Obj *obj, u8 value)
{
    obj->unk73 = value;
}

void sub_02008954(const struct Sub02008828Obj *obj, u8 *out)
{
    *out = obj->unk73;
}

void sub_0200895C(struct Sub02008828Obj *obj, u8 value)
{
    obj->unk74 = value;
}

void sub_02008964(const struct Sub02008828Obj *obj, u8 *out)
{
    *out = obj->unk74;
}

void sub_0200896C(struct Sub02008828Obj *obj, u32 value)
{
    obj->unk78 = value;
}

void sub_02008970(const struct Sub02008828Obj *obj, u32 *out)
{
    *out = obj->unk78;
}

u16 sub_02008978(const struct Sub02008828Obj *obj)
{
    return obj->unk7C;
}

void sub_02008980(struct Sub02008828Obj *obj, u16 value)
{
    obj->unk7C = value;
}

void sub_02008988(struct Sub02008828Obj *obj, u16 value)
{
    obj->unk7E = value;
}

u16 sub_02008990(const struct Sub02008828Obj *obj)
{
    return obj->unk7E;
}

u16 sub_02008998(const struct Sub02008828Obj *obj)
{
    return obj->unk76;
}

void sub_020089A0(struct Sub02008828Obj *obj, u16 value)
{
    obj->unk76 = value;
}
