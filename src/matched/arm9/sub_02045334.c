/*
 * unit:     no
 * address:  0x02045334
 * packet:   pkt_020452E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02045334
 *
 * symbols:
 *   sub_020416B8  0x020416B8  arm
 *   sub_020437D4  0x020437D4  arm
 *   sub_02040B1C  0x02040B1C  arm
 *
 * One of the descriptor family's two teardown/commit paths (the other is
 * sub_020452E8 immediately before it). It sizes the descriptor's payload
 * as
 *
 *   sub_020416B8(d->unk2) * (d->unk5 * d->unk6)
 *
 * and passes that, the heap handle obtained from d->heap via
 * sub_020437D4, and d->unkA on to sub_02040B1C.
 *
 * The u8 * u8 product compiles to `smulbb`, not `mul`: the compiler knows
 * both operands came from `ldrb` and fit in sixteen bits, so it uses the
 * halfword multiply. The second multiply, against a call result of
 * unknown range, has to be a full `mul`.
 *
 * The product is computed before the sub_020437D4 call and so has to
 * survive it, which is what buys the callee-saved r4 and turns
 * push {r4, lr} into push {r3, r4, r5, lr}: r5 holds the descriptor
 * pointer across all three calls and r3 is the alignment filler.
 *
 * d->unk2 is loaded twice, once for each call that takes it, rather than
 * kept in a register: re-reading the field is cheaper than spending a
 * third callee-saved register on it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045334.c \
 *       --func sub_02045334 --addr 0x02045334 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Descriptor {
    u16   unk0;
    u8    unk2;
    u8    unk3;
    u8    unk4;
    u8    unk5;
    u8    unk6;
    u8    unk7;
    u8    unk8;
    u8    unk9;
    u16   unkA;
    void *heap;
};

struct Bmp;
extern u8 sub_020416B8(int channel);
extern void *sub_020437D4(const struct Bmp *bmp);
extern void sub_02040B1C(int index, const void *src, u32 size, u32 tile);

void sub_02045334(struct Descriptor *d)
{
    u32 size;

    size = (d->unk5 * d->unk6) * sub_020416B8(d->unk2);
    sub_02040B1C(d->unk2, sub_020437D4(d->heap), size, d->unkA);
}
