/*
 * unit:     no
 * function: sub_0204CF74
 * address:  0x0204CF74
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_0204B0C8  0x0204B0C8  arm
 *
 * Measure entry `id`, writing the two halfwords of the answer through
 * `out`.  The sentinel id 0xFFFF means "nothing", and zeroes both.
 *
 * 0xFFFF costs a pool word because it is not an ARM rotated immediate
 * (docs/idioms/out-of-range-immediate-subtract-costs-a-pool-word.md is the
 * same constraint on the other side of the comparison).  The whole early
 * return is predicated: one `moveq` feeding two `strheq` and a `popeq`,
 * with no branch anywhere.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CF74.c \
 *       --func sub_0204CF74 --addr 0x0204CF74 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Inner {
    u8    pad_00[8];
    void *unk_08;
};

struct Obj {
    u8            pad_00[8];
    struct Inner *unk_08;
};

extern void sub_0204B0C8(void *src, u32 id, u16 *out);

void sub_0204CF74(struct Obj *o, u32 id, u16 *out)
{
    if (id == 0xFFFF) {
        out[0] = 0;
        out[1] = 0;
        return;
    }
    sub_0204B0C8(o->unk_08->unk_08, id, out);
}
