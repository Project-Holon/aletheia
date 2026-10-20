/*
 * file:     pokerus.c
 * unit:     yes
 * function: POKERUS_TryInfectParty, POKERUS_DecreaseDays, POKERUS_SpreadParty, POKERUS_GetInfectedMask, POKERUS_IsInfected, POKERUS_IsBoxInfected, POKERUS_IsCured, POKERUS_IsBoxCured
 * address:  0x0201B038
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pokeparty.c by tools/splitfile.py.
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   GF_STANDARD_Rand  0x0203F0A8  arm
 *   POKE_TOOL_CastToBoxParam  0x020185F0  thumb
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb arm9
 *   POKEPARTY_GetMember 0x0201AB28 thumb arm9
 *   _ull_mul                     0x0209C054  arm
 */
#include "pokeparty_shared_types.h"

#include "poke_tool.h"




#include "gf_standard.h"

#include "pokeparty.h"


void POKERUS_TryInfectParty(struct Party *party);

void POKERUS_DecreaseDays(struct Party *party, s32 days);

void POKERUS_SpreadParty(struct Party *party);

u32 POKERUS_GetInfectedMask(struct Party *party);

u32 POKERUS_IsInfected(struct PokemonParam *pp);

u32 POKERUS_IsBoxInfected(struct BoxPokemon *box);

u32 POKERUS_IsCured(struct PokemonParam *pp);

u32 POKERUS_IsBoxCured(struct BoxPokemon *box);

/*
 * note:     EXACT* only for the two bytes of alignment padding at
 *           0x0201B0FE.  The rare random event that seeds party record
 *           field 0x97 (see docs/notes/POKERUS_TryInfectParty.c.txt for the draws and
 *           the version-sensitive constants 0x4000/0x8000/0xC000, 7, 0xF3,
 *           content values rather than addresses).  Closed in wave 16: the
 *           packed byte is built as `w = v; w |= (u8)(v << 4);` (the copy is
 *           the image's `adds r3, r0, #0` before the orrs), and the last two
 *           truncations are written inside the call argument, which lets the
 *           final lsls/lsrs pair straddle the argument set-up.
 */
void POKERUS_TryInfectParty(struct Party *party)
{
    u32 infectedMask;
    u32 chance;
    u32 slot;
    struct PokemonParam *member;
    u32 strain;
    u32 pokerus;
    u32 memberCount;

    memberCount = POKEPARTY_GetCount(party);
    chance = (u16)((u64)GF_STANDARD_Rand() * 0x10000 >> 32);
    infectedMask = POKERUS_GetInfectedMask(party);
    if (chance == 0x4000 || chance == 0x8000 || chance == 0xC000) {
        do {
            slot = GF_STANDARD_Rand();
            if (memberCount != 0) {
                slot = (u32)(((u64)slot * memberCount) >> 32);
            }
            member = POKEPARTY_GetMember(party, slot);
        } while (POKE_TOOL_GetPartyValue(member, 5, 0) == 0
                 || POKE_TOOL_GetPartyValue(member, 0x4C, 0) != 0);
        if ((infectedMask & (1 << slot)) != 0) {
            return;
        }
        do {
            strain = (u8)((u64)GF_STANDARD_Rand() * 0x100 >> 32);
        } while ((strain & 7) == 0);
        if ((strain & 0xF0) != 0) {
            strain = strain & 7;
        }
        pokerus = strain; pokerus |= (u8)(strain << 4);
        POKE_TOOL_SetPartyValue(member, 0x97, (u8)((u8)(pokerus & 0xF3) + 1));
    }
}

/*
 * A whole translation unit, matched as one byte range.
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
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B100.c \
 *       --addr 0x0201B100 --thumb
 */
void POKERUS_DecreaseDays(struct Party *party, s32 days)
{
    s32 memberCount;
    struct PokemonParam *member;
    s32 i;
    u8 pokerus;
    s32 daysLeft;

    memberCount = POKEPARTY_GetCount(party);
    for (i = 0; i < memberCount; i++) {
        member = POKEPARTY_GetMember(party, i);
        if (POKE_TOOL_GetPartyValue(member, 5, 0) == 0) {
            continue;
        }
        pokerus = (u8)POKE_TOOL_GetPartyValue(member, 0x97, 0);
        daysLeft = pokerus & 0xF;
        if (daysLeft == 0) {
            continue;
        }
        if (daysLeft < days || days > 4) {
            pokerus &= 0xF0;
        } else {
            pokerus = (u8)(pokerus - (u8)days);
        }
        if (pokerus == 0) {
            pokerus = 0x10;
        }
        POKE_TOOL_SetPartyValue(member, 0x97, pokerus);
    }
}

void POKERUS_SpreadParty(struct Party *party)
{
    s32 i;
    struct PokemonParam *member;
    struct PokemonParam *neighbor;
    u8 pokerus;
    s32 memberCount;

    memberCount = POKEPARTY_GetCount(party);
    if ((u32)((u64)GF_STANDARD_Rand() * 3 >> 32) != 0) {
        return;
    }
    for (i = 0; i < memberCount; i++) {
        member = POKEPARTY_GetMember(party, i);
        if (POKE_TOOL_GetPartyValue(member, 5, 0) == 0) {
            continue;
        }
        pokerus = (u8)POKE_TOOL_GetPartyValue(member, 0x97, 0);
        if ((pokerus & 0xF) == 0) {
            continue;
        }
        if (i != 0) {
            neighbor = POKEPARTY_GetMember(party, i - 1);
            if ((POKE_TOOL_GetPartyValue(neighbor, 0x97, 0) & 0xF0) == 0) {
                POKE_TOOL_SetPartyValue(neighbor, 0x97, pokerus);
            }
        }
        if (i < memberCount - 1) {
            neighbor = POKEPARTY_GetMember(party, i + 1);
            if ((POKE_TOOL_GetPartyValue(neighbor, 0x97, 0) & 0xF0) == 0) {
                POKE_TOOL_SetPartyValue(neighbor, 0x97, pokerus);
                i++;
            }
        }
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
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
 * POKE_TOOL_CastToBoxParam.
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
 * the cast placement docs/MATCHING.md pins for MUSICAL_SAVE_AddProp: held in a `u8`
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
 */
u32 POKERUS_GetInfectedMask(struct Party *party)
{
    s32 i;
    u32 infectedMask;
    s32 memberCount;

    infectedMask = 0;
    memberCount = POKEPARTY_GetCount(party);
    for (i = 0; i < memberCount; i++) {
        if (POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(party, i), 0x97, 0) != 0) {
            infectedMask |= (u8)(1 << i);
        }
    }
    return infectedMask;
}

u32 POKERUS_IsInfected(struct PokemonParam *pp)
{
    return POKERUS_IsBoxInfected(POKE_TOOL_CastToBoxParam(pp));
}

u32 POKERUS_IsBoxInfected(struct BoxPokemon *box)
{
    u32 result;

    result = 0;
    if ((POKE_TOOL_GetBoxValue(box, 0x97, 0) & 0xF) != 0) {
        result = 1;
    }
    return result;
}

u32 POKERUS_IsCured(struct PokemonParam *pp)
{
    return POKERUS_IsBoxCured(POKE_TOOL_CastToBoxParam(pp));
}

u32 POKERUS_IsBoxCured(struct BoxPokemon *box)
{
    u32 result;
    u8 pokerus;

    result = 0;
    pokerus = (u8)POKE_TOOL_GetBoxValue(box, 0x97, 0);
    if ((pokerus & 0xF) == 0 && (pokerus & 0xF0) != 0) {
        result = 1;
    }
    return result;
}
