/*
 * unit:     no
 * function: sub_0204CED8
 * address:  0x0204CED8
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_0204B49C  0x0204B49C  arm
 *   sub_0204B84C  0x0204B84C  arm
 *   sub_0204B878  0x0204B878  arm
 *   sub_0204B95C  0x0204B95C  arm
 *
 * Apply the seven-field request to the object: the two signed halfwords at
 * +0 and +2 are the two axes of the same setter, selected by a trailing
 * 0/1; the byte at +6 replaces the low eight bits of the flag word at
 * +0x60; the byte at +7 and the halfword at +4 go to their own setters, and
 * sub_0204B95C commits the result.
 *
 * `ldrsh` with no immediate offset form is the only evidence that the first
 * two fields are `s16` rather than `u16`
 * (docs/idioms/ldrsh-register-offset-is-signedness.md); the third is
 * `ldrh`, so the request really does mix the two.
 *
 * The flag-word update is a plain `bic #0xff` / `orr`, with no shift on
 * either side, which places the field at bit 0 and fixes its width at
 * eight: the value comes from an `ldrb`, so nothing has to mask it first.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CED8.c \
 *       --func sub_0204CED8 --addr 0x0204CED8 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Req {
    s16 unk_00;
    s16 unk_02;
    u16 unk_04;
    u8  unk_06;
    u8  unk_07;
};

struct Obj {
    u8  pad_00[0x60];
    u32 low     : 8;
    u32 flag_hi : 24;
};

extern void sub_0204B49C(struct Obj *o, s16 value, void *ctx, u32 axis);
extern void sub_0204B84C(struct Obj *o, u8 value);
extern void sub_0204B878(struct Obj *o, u16 value);
extern void sub_0204B95C(struct Obj *o);

void sub_0204CED8(struct Obj *o, const struct Req *r, void *ctx)
{
    sub_0204B49C(o, r->unk_00, ctx, 0);
    sub_0204B49C(o, r->unk_02, ctx, 1);
    o->low = r->unk_06;
    sub_0204B84C(o, r->unk_07);
    sub_0204B878(o, r->unk_04);
    sub_0204B95C(o);
}
