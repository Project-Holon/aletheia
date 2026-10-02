/*
 * unit:     no
 * function: sub_0204D360
 * address:  0x0204D360
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
 * The second copy of sub_0204D340: same body, same two callees, emitted
 * again thirty-two bytes later.  Two adjacent dispatch-table slots each got
 * their own definition and nothing folded them, so the only difference
 * between the two functions in the image is the PC24 displacement.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D360.c \
 *       --func sub_0204D360 --addr 0x0204D360 --cc 1.1p1 --arm
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

extern void *sub_020627D8(void *h, u32 idx);
extern void  sub_0206434C(struct Rec *r, void *v);

void sub_0204D360(struct Obj *o, u32 idx)
{
    sub_0206434C(&o->unk_0c, sub_020627D8(o->unk_08, idx));
}
