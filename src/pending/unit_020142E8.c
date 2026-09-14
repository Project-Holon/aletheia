/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x020142E8
 * packet:   pkt_02013ED8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * function: sub_020142E8, sub_02014314, sub_0201433C, sub_02014368,
 *           sub_02014388
 *
 * symbols:
 *   g_sub02014388Table  0x02146268  data
 *
 * Every concrete byte of this range reproduces the original; the whole
 * unit caps at MATCH because g_sub02014388Table's address (the pool word
 * at 0x020143C8) has no witness anywhere in the image outside this range.
 * Bundling sub_02014388 with its three callers already turned those three
 * calls into `local` relocations (see below); this is the one remaining
 * site, and nothing short of another caller of sub_02014388 (or another
 * reference to the table) closes it.  Parked per src/pending/README.md.
 *
 * alias: sub_020142E8/14/3C are three accessors on a one-byte bitmap
 * sub_02014388() locates for a given (a, b) pair: test, set and clear the
 * bit `b % 8` of the byte it returns.  `b % 8` for a signed b compiles to
 * a shift/rotate rather than a mask, which is the compiler's own
 * implementation of signed modulo by a power of two rather than anything
 * the source spells out.  sub_020142E8 folds its "no such byte" case and
 * its "bit not set" case into one shared return by testing the pointer as
 * the left operand of `&&`, matching docs/idioms/guard-chain-sharing-one-
 * exit-block-is-a-single-conjunction.md; testing it with a separate `if`
 * first produces two extra bytes and a second `bx lr` copy
 * (docs/idioms/initialise-the-result-before-the-input-or-every-arm-
 * duplicates-the-return.md is the same family of finding).  sub_02014368
 * is a plain loop calling sub_0201433C for every id in an inclusive range.
 *
 * sub_02014388 itself picks one of two byte tables by range: a small id
 * (b < 0x4000, itself b >> 3) indexes off the caller's own pointer
 * argument at a fixed offset; a large id falls to `(b - 0x4000) / 8`
 * (signed division by 8, the classic shift/round/shift-again sequence)
 * indexing a fixed global table instead.  Both ranges refuse an index
 * below a floor and return NULL.  Bundling it into this file rather than
 * splitting it out is what turns its three callers' calls into `local`
 * relocations, since sub_02014388 has no caller anywhere else in the
 * image to attest an external declaration
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md is the
 * same rule in the other direction: here the fix is not to split).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020142E8.c \
 *       --addr 0x020142E8 --thumb
 *
 * The `matched` class does not reach it either: an EXACT entry attests the code
 * it reproduced, never a data object one of its instructions loads, and
 * 0x02146268 is a table.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int             s32;

extern u8 g_sub02014388Table[];
static u8 *sub_02014388(u32 aa, s32 b);

u32 sub_020142E8(u32 a, s32 b)
{
    u8 *p = sub_02014388(a, b);
    return p != 0 && (*p & (1 << (b % 8))) != 0;
}

void sub_02014314(u32 a, s32 b)
{
    u8 *p = sub_02014388(a, b);
    if (p)
        *p |= (u8)(1 << (b % 8));
}

void sub_0201433C(u32 a, s32 b)
{
    u8 *p = sub_02014388(a, b);
    if (p)
        *p &= (u8)(0xFF ^ (1 << (b % 8)));
}

void sub_02014368(u32 a, s32 lo, s32 hi)
{
    s32 i;

    for (i = lo; i <= hi; i++)
        sub_0201433C(a, (u16)i);
}

static u8 *sub_02014388(u32 aa, s32 b)
{
    if (b == 0)
        return 0;
    if ((u32)b < 0x4000) {
        s32 idx = (u32)b >> 3;
        if (idx >= 0x16C)
            return 0;
        return (u8 *)(aa + 0x27C + idx);
    } else {
        s32 t = b - 0x4000;
        s32 idx2 = t / 8;
        if (idx2 >= 8)
            return 0;
        return &g_sub02014388Table[idx2];
    }
}
