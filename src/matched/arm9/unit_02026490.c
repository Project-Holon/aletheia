/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02026490
 * packet:   pkt_02026250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02026490, sub_02026498, sub_020264AC
 *
 * The labelled sub_02026490 (8 bytes) is followed immediately by two more
 * unlabelled leaves reaching to the next real label at 0x020264B4, the
 * same shape as src/matched/unit_02026454.c just above it in the image.
 *
 * sub_02026490 sets byte field +4 to its argument and unconditionally
 * sets byte field +5 to 1. sub_02026498 and sub_020264AC are a
 * setter/getter pair on bit 2 of field +4: the setter narrows its 32-bit
 * argument to a byte before taking bit 0 of it
 * (`u8 f = (u8)flag;` is what produces the `lsls #0x18`/`lsrs #0x18`
 * truncation pair, not a mask, per the halfword-narrowing case in
 * docs/MATCHING.md), and the getter's `lsls #0x1d`/`lsrs #0x1f` pair is a
 * bitfield extraction rather than a type conversion (32 - 0x1d is 3, not
 * 8/16/32), which only reproduces from an actual bitfield member
 * declaration: docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02026490.c \
 *       --addr 0x02026490 --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

void sub_02026490(void *obj, u32 value)
{
    *((u8 *)obj + 4) = value;
    *((u8 *)obj + 5) = 1;
}

void sub_02026498(void *obj, u32 flag)
{
    u8 f = (u8)flag;
    u8 v = *((u8 *)obj + 4);

    v = (v & ~4) | ((f & 1) << 2);
    *((u8 *)obj + 4) = v;
}

struct Field4 {
    u8 lo : 2;
    u8 bit2 : 1;
    u8 hi : 5;
};

u32 sub_020264AC(void *obj)
{
    return ((struct Field4 *)((u8 *)obj + 4))->bit2;
}
