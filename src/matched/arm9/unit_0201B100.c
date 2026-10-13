/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0201B100
 * packet:   pkt_0201B038
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKERUS_DecreaseDays, POKERUS_SpreadParty
 *
 * The two writers of the packed byte field id 0x97 that
 * src/matched/unit_0201B220.c reads: POKERUS_DecreaseDays counts its low nibble down
 * across the whole party, and POKERUS_SpreadParty spreads it to the neighbouring
 * slots one time in three.
 *
 * POKERUS_DecreaseDays walks every occupied slot, clears the low nibble outright when
 * the amount to subtract is larger than it or larger than 4, subtracts it
 * otherwise, and forces 0x10 when the whole byte comes out zero so that the
 * high nibble stays distinguishable from "never set".  POKERUS_SpreadParty copies a
 * slot's byte into the slot before and the slot after it whenever theirs has
 * no high nibble, and advances the index an extra step when it wrote forwards
 * so that a value cannot propagate down the party in one pass.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id.  What is content shaped:
 *
 *   4      POKERUS_DecreaseDays's threshold: an amount above it always clears the
 *          nibble instead of subtracting, so it is a rule about the field's
 *          range rather than about its layout.
 *   0x10   the value written when the subtraction leaves zero, i.e. the low
 *          nibble empty and the high nibble at one.
 *   3      POKERUS_SpreadParty's odds, one call in three.
 *   0xF, 0xF0   the two nibble masks, the field's own layout.
 *   0x97, 5   party record ids in src/matched/POKE_TOOL_GetPartyValueRaw.c's space.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * POKERUS_SpreadParty's odds are a 64 bit multiply and not a modulo:
 * `(u64)rand() * 3 >> 32` puts the answer in the `_ull_mul` call's **r1**, and
 * the `movs r1, #0` in front of the call is the draw's high half rather than a
 * second argument.  See
 * docs/idioms/random-below-n-is-a-64-bit-multiply-high.md.
 *
 * It has no `last` variable.  The original loads the count once, tests it,
 * decrements it and spills the result, which reads like `last = n - 1` written
 * after an `if (n > 0)` guard; it is not.  It is `if (i < n - 1)` inside the
 * loop, with `n - 1` hoisted into the loop preheader by the compiler, which is
 * why the decrement lands after the loop's own entry guard rather than before
 * it.  Writing the guard and the local out by hand costs six bytes.
 *
 * POKERUS_DecreaseDays's two arms are not spelled the same way.  The masking arm is a
 * compound assignment, `v &= 0xF0`, and the subtracting arm carries an explicit
 * `(u8)` cast; written with the cast on both, the two truncations cross-jump
 * into one block that both arms branch to and the function is four bytes
 * short.  That is
 * docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md
 * seen on a local rather than on a field: the compound form is the one that
 * does not materialise a fresh truncation.
 *
 * Both loop counters are signed, and in POKERUS_DecreaseDays the amount and the
 * extracted nibble are signed too: the comparisons are `blt` and `ble`, not
 * `blo` and `bls`.
 *
 * symbols:
 *   _ull_mul  0x0209C054  arm
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B100.c \
 *       --addr 0x0201B100 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;
typedef unsigned long long u64;

extern u32   func_02017E1C(void *mon, u32 id, u32 v);
extern void  func_02017E40(void *mon, u32 id, u32 v);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32   func_0203F0A8(void);

void POKERUS_DecreaseDays(void *party, s32 amount)
{
    s32 n;
    void *mon;
    s32 i;
    u8 v;
    s32 low;

    n = POKEPARTY_GetCount(party);
    for (i = 0; i < n; i++) {
        mon = POKEPARTY_GetMember(party, i);
        if (func_02017E1C(mon, 5, 0) == 0) {
            continue;
        }
        v = (u8)func_02017E1C(mon, 0x97, 0);
        low = v & 0xF;
        if (low == 0) {
            continue;
        }
        if (low < amount || amount > 4) {
            v &= 0xF0;
        } else {
            v = (u8)(v - (u8)amount);
        }
        if (v == 0) {
            v = 0x10;
        }
        func_02017E40(mon, 0x97, v);
    }
}

void POKERUS_SpreadParty(void *party)
{
    s32 i;
    void *mon;
    void *other;
    u8 v;
    s32 n;

    n = POKEPARTY_GetCount(party);
    if ((u32)((u64)func_0203F0A8() * 3 >> 32) != 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        mon = POKEPARTY_GetMember(party, i);
        if (func_02017E1C(mon, 5, 0) == 0) {
            continue;
        }
        v = (u8)func_02017E1C(mon, 0x97, 0);
        if ((v & 0xF) == 0) {
            continue;
        }
        if (i != 0) {
            other = POKEPARTY_GetMember(party, i - 1);
            if ((func_02017E1C(other, 0x97, 0) & 0xF0) == 0) {
                func_02017E40(other, 0x97, v);
            }
        }
        if (i < n - 1) {
            other = POKEPARTY_GetMember(party, i + 1);
            if ((func_02017E1C(other, 0x97, 0) & 0xF0) == 0) {
                func_02017E40(other, 0x97, v);
                i++;
            }
        }
    }
}
