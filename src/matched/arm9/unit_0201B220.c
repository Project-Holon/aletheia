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
 * function: POKERUS_GetInfectedMask, POKERUS_IsInfected, POKERUS_IsBoxInfected, POKERUS_IsCured,
 *           POKERUS_IsBoxCured
 *
 * Five readers of one packed byte field, id 0x97 of the party record, whose
 * two nibbles are written by the loop at 0x0201B0DC in the same file.
 *
 * POKERUS_GetInfectedMask answers a bitmask of the party slots whose field is non zero,
 * one bit per slot, and is the value the code at 0x0201B056 tests before it
 * writes a new one.  POKERUS_IsBoxInfected asks whether the low nibble is set and
 * POKERUS_IsBoxCured whether the high nibble is set and the low one is not;
 * POKERUS_IsInfected and POKERUS_IsCured are their two-instruction wrappers over
 * POKE_TOOL_Dummy.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id appears here.  0x97 is a party record id in
 * src/matched/POKE_TOOL_GetPartyValueRaw.c's space, and the two nibble masks 0xF and 0xF0
 * are the field's own layout.  What is worth re-reading for IRAO is the
 * meaning rather than the numbers: the field is a counter in the low nibble
 * and a flag set in the high one, and a version that widened either would
 * change all five of these functions and the writer at 0x0201B0DC together.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * POKERUS_GetInfectedMask assigns the mask before it asks for the party count, which is
 * what keeps the zero a `movs` in the prologue and lets the loop index take a
 * second `movs` after the call rather than a pool word
 * (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 * Its shift is truncated to a byte at the use, `mask |= (u8)(1 << i)`, which is
 * the cast placement docs/MATCHING.md pins for sub_0200A6BC: held in a `u8`
 * temporary instead, the truncation cannot sink and the tail of the loop comes
 * out with every register moved.
 *
 * POKERUS_IsBoxCured reads the field into a `u8` local and tests it twice, so the
 * constant is the `tst`'s first operand and the field its second; POKERUS_IsBoxInfected
 * tests the call result directly and gets the other operand order.  That one
 * byte is the only difference between the two shapes, and it is the same tell
 * docs/idioms/cmp-operand-order-names-the-temporary.md records for `cmp`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B220.c \
 *       --addr 0x0201B220 --thumb
 *
 * symbols:
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_Dummy  0x020185F0  thumb
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern u32   POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern u32   POKE_TOOL_GetBoxValue(void *mon, u32 id, u32 v);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void *POKE_TOOL_Dummy(void *a);

u32 POKERUS_IsBoxInfected(void *mon);
u32 POKERUS_IsBoxCured(void *mon);

u32 POKERUS_GetInfectedMask(void *party)
{
    s32 i;
    u32 mask;
    s32 n;

    mask = 0;
    n = POKEPARTY_GetCount(party);
    for (i = 0; i < n; i++) {
        if (POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(party, i), 0x97, 0) != 0) {
            mask |= (u8)(1 << i);
        }
    }
    return mask;
}

u32 POKERUS_IsInfected(void *a)
{
    return POKERUS_IsBoxInfected(POKE_TOOL_Dummy(a));
}

u32 POKERUS_IsBoxInfected(void *mon)
{
    u32 r;

    r = 0;
    if ((POKE_TOOL_GetBoxValue(mon, 0x97, 0) & 0xF) != 0) {
        r = 1;
    }
    return r;
}

u32 POKERUS_IsCured(void *a)
{
    return POKERUS_IsBoxCured(POKE_TOOL_Dummy(a));
}

u32 POKERUS_IsBoxCured(void *mon)
{
    u32 r;
    u8 v;

    r = 0;
    v = (u8)POKE_TOOL_GetBoxValue(mon, 0x97, 0);
    if ((v & 0xF) == 0 && (v & 0xF0) != 0) {
        r = 1;
    }
    return r;
}
