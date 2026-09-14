/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: sub_0204B6F4, sub_0204B714
 * address:  0x0204B6F4
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A packed bitfield word at +0x60 of the 0x0204Bxxx object: a 12-bit field
 * at bits 0-11 (untouched here), a 4-bit field at bits 12-15, 15 pad bits,
 * and a 1-bit flag at bit 31.
 *
 *   sub_0204B6F4  set the 4-bit field and the top flag bit together (one
 *                 read-modify-write of the whole word).
 *   sub_0204B714  read the 4-bit field back out.
 *
 * The setter's double shift (`lsl r1,r1,#28` then `orr r1,r3,r1,lsr#16`) is
 * the compiler's general bitfield-store formula, value << (32-width) then
 * >> (32-width-offset); the getter's `lsl #16`/`lsr #28` is the matching
 * read formula, << (32-width-offset) then >> (32-width).  The flag bit
 * collapses to a single `lsl #31` because its offset+width is 32.
 *
 * The getter's redundant `and r0, r0, #0xff` (the field is already 0-15) is
 * only there because the source narrows the result to `unsigned char`
 * before returning it; reading the bitfield straight through as `u32` loses
 * those four bytes.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B6F4.c \
 *       --addr 0x0204B6F4 --arm
 */

typedef unsigned int u32;

struct Obj {
    u32 pad_00[0x18];
    struct {
        u32 fieldA : 12;
        u32 fieldB : 4;
        u32 pad    : 15;
        u32 flag   : 1;
    } bits60;
};

void sub_0204B6F4(struct Obj *o, u32 v, u32 flag)
{
    o->bits60.fieldB = v;
    o->bits60.flag = flag;
}

u32 sub_0204B714(struct Obj *o)
{
    return (unsigned char)o->bits60.fieldB;
}
