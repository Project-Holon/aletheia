/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200BBC8
 * packet:   pkt_0200B448
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200BBC8, func_0200BBD8, func_0200BBEC, func_0200BBFC,
 *           func_0200BC10, func_0200BC20, func_0200BC2C, func_0200BC4C,
 *           func_0200BC88, func_0200BCA0, func_0200BCA8, func_0200BCB8,
 *           func_0200BCD8, func_0200BCEC
 *
 * 384 bytes, 0x0200BBC8..0x0200BD48, 14 functions, none of which carries a
 * label in the generated listing: not one of them saves lr, so the whole
 * range arrives as a run of `.word`s between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * The object is two 0xE4-byte slots at +0x000, each an in-use word, a
 * 0xDC-byte payload and a word behind it, plus a flag word at +0x1C8.  That
 * is 0x1CC bytes and it is exactly what func_0200BD98 in
 * src/matched/unit_0200BD98.c returns as the size of the save block with id
 * 0x32, so the record is pinned from both ends.  The halfword of bits at
 * +0x358 that func_0200BBC8, func_0200BBD8 and func_0200BBFC reach is past
 * that end and therefore belongs to some other object the same file also
 * serves; it is declared here as one struct only because nothing in the range
 * distinguishes the two.  The three sizes are pinned by the three
 * `ldm`/`stm` copies and agree: 0x1B pairs plus a word is the 0xDC payload
 * func_0200BC4C stores, and 0x1C pairs plus a word is the whole 0xE4 slot
 * func_0200BCEC swaps through a stack temporary.  See
 * docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; both copies are
 * eight-byte stepped, which is what says the payload is word aligned rather
 * than a byte array.
 *
 * func_0200BBEC belongs to a different object: it is pure address arithmetic
 * over a 0x330-byte record holding six 0x88-byte entries, and it is here only
 * because the file it was written in also holds the accessors above.  Its one
 * caller in this region, func_0200BBA8, is outside this range.
 *
 * Every guard in the file that ends in a shared exit is written as one
 * conjunction rather than as a run of early returns, which is what gives the
 * single epilogue the original has; see
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Payload {
    u32 unk00[0x37];
};

struct Slot {
    u32 unk00;
    struct Payload unk04;
    u32 unkE0;
};

struct Obj {
    struct Slot slot[2];
    u32 unk1C8;
    u8  unk1CC[0x358 - 0x1CC];
    u16 unk358;
};

void func_0200BBC8(struct Obj *p, u32 v)
{
    p->unk358 |= (u16)v;
}

void func_0200BBD8(struct Obj *p, u16 v)
{
    p->unk358 &= ~v;
}

void *func_0200BBEC(void *base, u32 i, u32 j)
{
    return (u8 *)base + i * 0x330 + j * 0x88;
}

u32 func_0200BBFC(struct Obj *p, u32 mask)
{
    if ((p->unk358 & mask) != 0) {
        return 1;
    }
    return 0;
}

void func_0200BC10(struct Obj *p)
{
    if (p->unk1C8 != 1) {
        p->unk1C8 = 1;
    }
}

void func_0200BC20(struct Obj *p)
{
    p->unk1C8 = 0;
}

struct Payload *func_0200BC2C(struct Obj *p, s32 i)
{
    if (i < 0 || i >= 2 || p->slot[i].unk00 != 1) {
        i = 0;
    }
    return &p->slot[i].unk04;
}

void func_0200BC4C(struct Obj *p, s32 i, const struct Payload *src)
{
    if (i >= 0 && i < 2 && p->slot[i].unk00 != 1) {
        p->slot[i].unk04 = *src;
        p->slot[i].unk00 = 1;
        p->slot[i].unkE0 = 0;
    }
}

void func_0200BC88(struct Obj *p, s32 i)
{
    if (i >= 0 && i < 2 && p->slot[i].unk00 == 1) {
        p->slot[i].unk00 = 0;
    }
}

u32 func_0200BCA0(struct Obj *p)
{
    return p->unk1C8;
}

u32 func_0200BCA8(struct Obj *p, u32 i)
{
    if (i >= 2) {
        return 0;
    }
    return p->slot[i].unk00;
}

u32 func_0200BCB8(struct Obj *p)
{
    s32 i;
    u32 n = 0;

    for (i = 0; i < 2; i++) {
        if (p->slot[i].unk00 == 1) {
            n++;
        }
    }
    return n;
}

u32 func_0200BCD8(struct Obj *p, u32 i)
{
    if (i >= 2) {
        return 0;
    }
    return p->slot[i].unkE0;
}

void func_0200BCEC(struct Obj *p, s32 a, s32 b)
{
    struct Slot tmp;

    if (a >= 0 && a < 2 && b >= 0 && b < 2) {
        tmp = p->slot[a];
        p->slot[a] = p->slot[b];
        p->slot[b] = tmp;
    }
}
