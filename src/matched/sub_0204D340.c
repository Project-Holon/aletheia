/*
 * unit:     no
 * function: sub_0204D340
 * address:  0x0204D340
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_020627D8  0x020627D8  arm
 *   sub_0206434C  0x0206434C  arm
 *
 * One of this family's per-slot "apply" hooks: take the handle at +8,
 * resolve it through sub_020627D8, and feed the result to sub_0206434C
 * together with the embedded record at +0xc.  sub_0204D360 is a
 * byte-for-byte duplicate of this function at a different address (the two
 * differ only in their PC24 displacements), which is what a pair of
 * distinct table slots sharing one body looks like when neither was folded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D340.c \
 *       --func sub_0204D340 --addr 0x0204D340 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Rec {
    u8 unk_00[1];
};

struct Obj {
    u8         pad_00[8];
    void      *unk_08;
    struct Rec unk_0c;
};

extern void *sub_020627D8(void *h);
extern void  sub_0206434C(struct Rec *r, void *v);

void sub_0204D340(struct Obj *o)
{
    sub_0206434C(&o->unk_0c, sub_020627D8(o->unk_08));
}
