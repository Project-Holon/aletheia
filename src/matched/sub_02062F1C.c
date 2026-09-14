/*
 * unit:     no
 * function: sub_02062F1C
 * address:  0x02062F1C
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Index-of: how far the cursor at +0 of this record sits past the array
 * base its owner (+0x1c) keeps at +0xc, in units of eight bytes.  A leaf
 * with no prologue at all, which is why disasm.py never labelled it.
 *
 * The `lsl #13; lsr #16` pair is the folded form of "shift right by three,
 * then truncate to u16"
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md);
 * the shifts being logical is the evidence that the subtraction is done in
 * u32, not as a signed ptrdiff.
 *
 * This is the missing witness for src/pending/sub_0204B918.c, the only
 * other reference to this address in the image.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02062F1C.c \
 *       --func sub_02062F1C --addr 0x02062F1C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Owner {
    u8  pad_00[0xc];
    u32 base;
};

struct Node {
    u32           cursor;
    u8            pad_04[0x18];
    struct Owner *owner;
};

u16 sub_02062F1C(const struct Node *n)
{
    return (u16)((n->cursor - n->owner->base) >> 3);
}
