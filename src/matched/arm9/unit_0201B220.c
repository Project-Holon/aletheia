/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0201B220
 * packet:   pkt_0201B038
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201B220, sub_0201B25C, sub_0201B268, sub_0201B280,
 *           sub_0201B28C
 *
 * Five readers of one packed byte field, id 0x97 of the party record, whose
 * two nibbles are written by the loop at 0x0201B0DC in the same file.
 *
 * sub_0201B220 answers a bitmask of the party slots whose field is non zero,
 * one bit per slot, and is the value the code at 0x0201B056 tests before it
 * writes a new one.  sub_0201B268 asks whether the low nibble is set and
 * sub_0201B28C whether the high nibble is set and the low one is not;
 * sub_0201B25C and sub_0201B280 are their two-instruction wrappers over
 * func_020185F0.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id appears here.  0x97 is a party record id in
 * src/matched/sub_02018DB4.c's space, and the two nibble masks 0xF and 0xF0
 * are the field's own layout.  What is worth re-reading for IRAO is the
 * meaning rather than the numbers: the field is a counter in the low nibble
 * and a flag set in the high one, and a version that widened either would
 * change all five of these functions and the writer at 0x0201B0DC together.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * sub_0201B220 assigns the mask before it asks for the party count, which is
 * what keeps the zero a `movs` in the prologue and lets the loop index take a
 * second `movs` after the call rather than a pool word
 * (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 * Its shift is truncated to a byte at the use, `mask |= (u8)(1 << i)`, which is
 * the cast placement docs/MATCHING.md pins for sub_0200A6BC: held in a `u8`
 * temporary instead, the truncation cannot sink and the tail of the loop comes
 * out with every register moved.
 *
 * sub_0201B28C reads the field into a `u8` local and tests it twice, so the
 * constant is the `tst`'s first operand and the field its second; sub_0201B268
 * tests the call result directly and gets the other operand order.  That one
 * byte is the only difference between the two shapes, and it is the same tell
 * docs/idioms/cmp-operand-order-names-the-temporary.md records for `cmp`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B220.c \
 *       --addr 0x0201B220 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern u32   func_02017E1C(void *mon, u32 id, u32 v);
extern u32   func_02017E88(void *mon, u32 id, u32 v);
extern u32 sub_0201AA18(void *p);
extern void *sub_0201AB28(void *p, u32 idx);
extern void *func_020185F0(void *a);

u32 sub_0201B268(void *mon);
u32 sub_0201B28C(void *mon);

u32 sub_0201B220(void *party)
{
    s32 i;
    u32 mask;
    s32 n;

    mask = 0;
    n = sub_0201AA18(party);
    for (i = 0; i < n; i++) {
        if (func_02017E1C(sub_0201AB28(party, i), 0x97, 0) != 0) {
            mask |= (u8)(1 << i);
        }
    }
    return mask;
}

u32 sub_0201B25C(void *a)
{
    return sub_0201B268(func_020185F0(a));
}

u32 sub_0201B268(void *mon)
{
    u32 r;

    r = 0;
    if ((func_02017E88(mon, 0x97, 0) & 0xF) != 0) {
        r = 1;
    }
    return r;
}

u32 sub_0201B280(void *a)
{
    return sub_0201B28C(func_020185F0(a));
}

u32 sub_0201B28C(void *mon)
{
    u32 r;
    u8 v;

    r = 0;
    v = (u8)func_02017E88(mon, 0x97, 0);
    if ((v & 0xF) == 0 && (v & 0xF0) != 0) {
        r = 1;
    }
    return r;
}
