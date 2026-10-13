/*
 * unit:     no
 * address:  0x020452E8
 * packet:   pkt_020452E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: BMP_WIN_Delete
 *
 * symbols:
 *   sub_0203FB44  0x0203FB44  arm
 *   BMP_Delete  0x020437AC  arm
 *   sub_020307B0  0x020307B0  arm
 *
 * The descriptor family's destructor: release the payload through
 * sub_0203FB44, release the heap handle through BMP_Delete, then free
 * the descriptor itself with the generic free at 0x020307B0 (the same
 * free STRBUF_Delete tail-calls).
 *
 * The payload size is (d->unk5 * d->unk6) * 32, doubled when the top bit
 * of the halfword at +0 is set. That bit is a 1-wide bitfield, not a
 * mask: `ldrh` followed by `lsl #16` / `lsrs #31` is the bitfield extract
 * shape (shift the field to the top, then all the way down by 32 minus
 * its width), and a plain `d->unk0 & 0x8000` test folds to a single
 * `tst`. Declaring the halfword as a 15-bit field plus a 1-bit field is
 * what reproduces it.
 *
 * Both arms of the doubling compute the u8 * u8 product themselves, which
 * is why `smulbb` appears twice under opposite predicates rather than
 * once before the test. Writing the shared multiply above the `if` and
 * only the doubling inside it produces one unconditional `smulbb` and a
 * different register assignment throughout; this is
 * docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md seen from
 * the entry side.
 *
 * The whole conditional is predicated, so there is no branch at all: the
 * `s` suffix on the `lsrs` is the test, and the three following
 * instructions carry `eq`/`ne`. Because there is no branch, the only
 * thing that fixes their order is source order: the `eq` arm is emitted
 * first, so the undoubled case has to be written as the `if` and the
 * doubled case as the `else`, even though `if (bit) double` reads more
 * naturally (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_Delete.c \
 *       --func BMP_WIN_Delete --addr 0x020452E8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Descriptor {
    u16   unk0_0 : 15;
    u16   unk0_15 : 1;
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

struct Obj020437AC;
extern void sub_0203FB44(u32 layer, u32 offset, u32 size);
extern void BMP_Delete(struct Obj020437AC *p);
extern u32 sub_020307B0(void *p);

u32 BMP_WIN_Delete(struct Descriptor *d)
{
    u32 size;

    if (d->unk0_15 == 0) {
        size = d->unk5 * d->unk6;
    } else {
        size = (d->unk5 * d->unk6) * 2;
    }
    sub_0203FB44(d->unk2, d->unkA, size * 32);
    BMP_Delete(d->heap);
    return sub_020307B0(d);
}
