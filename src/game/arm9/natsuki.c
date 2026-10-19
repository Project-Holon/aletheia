/*
 * file:     natsuki.c
 * unit:     yes
 * function: NATSUKI_Calc, NATSUKI_CalcUseItem, NATSUKI_CalcWalk, NATSUKI_CalcParty, NATSUKI_Apply
 * address:  0x0201B7A0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from shinka_check.c by tools/splitfile.py.
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   GF_STANDARD_Rand  0x0203F0A8  arm
 *   FILE_UTIL_GetItemParam   0x02020FE4  thumb
 *   _NatsukiDeltaTable     0x0209E45C  data
 *   _NatsukiWalkDeltas     0x0209E465  data  a1
 *   _NatsukiPartyDeltas     0x0209E462  data
 *   ZONEDATA_GetPlaceNameId   0x02013E4C  thumb
 *   GPOWER_ApplyFriendshipBonus   0x02011014  thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb arm9
 *   POKEPARTY_GetMember 0x0201AB28 thumb arm9
 */
#include "pokeparty_shared_types.h"
#include "../types.h"

extern u32   POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 id, u32 arg);

extern void  POKE_TOOL_SetPartyValue(struct PokemonParam *pp, u32 id, u32 value);

extern u32   GF_STANDARD_Rand(void);

extern u32   FILE_UTIL_GetItemParam(u32 item, u32 sel, u32 heap);

extern u32   ZONEDATA_GetPlaceNameId(u32 zoneId);

extern int   GPOWER_ApplyFriendshipBonus(int delta);

u32 POKEPARTY_GetCount(const struct Party *party);

struct PokemonParam *POKEPARTY_GetMember(struct Party *party, u32 pos);

void NATSUKI_Calc(struct PokemonParam *pp, int type, int zoneId, u16 heap);

void NATSUKI_CalcUseItem(struct PokemonParam *pp, int item, u16 zoneId, u16 heap);

void NATSUKI_CalcWalk(struct PokemonParam *pp, int zoneId, u16 heap);

void NATSUKI_CalcParty(struct Party *party, int zoneId, u16 heap);

void NATSUKI_Apply(struct PokemonParam *pp, const s8 *deltas, int zoneId, u16 heap);

extern const s8 _NatsukiDeltaTable[];

extern const s8 _NatsukiWalkDeltas[];

extern const s8 _NatsukiPartyDeltas[];

/*
 *           at 0x0201B7B0, inside the compared range; every concrete byte is
 *           right.
 *
 * A three-byte-stride table entry is handed to NATSUKI_Apply along with the
 * caller's own third and fourth arguments.  Those two are forwarded
 * unchanged - they are already in r2/r3 - so no instruction moves them, and
 * that is also why the call is a real `bl` rather than a tail call: a Thumb
 * tail call spends r3 on the target address, so a four-argument call cannot
 * be one.  The 3 is lsls #1 plus adds; the table pointer is this function's
 * own pool word at 0x0201B7B0.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/NATSUKI_Calc.c \
 *       --func NATSUKI_Calc --addr 0x0201B7A0 --cc 1.1p1 --thumb
 */
void NATSUKI_Calc(struct PokemonParam *pp, int type, int zoneId, u16 heap)
{
    NATSUKI_Apply(pp, &_NatsukiDeltaTable[type * 3], zoneId, heap);
}

/*
 * Three bytes are built one selector at a time - selectors 0x3C, 0x3D, 0x3E
 * - and the three-byte buffer is then handed to NATSUKI_Apply along with
 * the caller's own second and fourth arguments.  No literal pool: the only
 * pointers are the two call targets.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NATSUKI_CalcUseItem.c \
 *       --func NATSUKI_CalcUseItem --addr 0x0201B7B4 --cc 1.1p1 --thumb
 */
void NATSUKI_CalcUseItem(struct PokemonParam *pp, int item, u16 zoneId, u16 heap)
{
    u8 deltas[3];
    int i;

    for (i = 0; i < 3; i++) {
        deltas[i] = (u8)FILE_UTIL_GetItemParam(item, (u16)(i + 0x3C), heap);
    }
    NATSUKI_Apply(pp, (const s8 *)deltas, zoneId, heap);
}

/*
 * shinka_check.c.  The coin-flip sibling of NATSUKI_Calc / NATSUKI_CalcParty:
 * on an even draw below 2, hand the fixed row _NatsukiWalkDeltas to NATSUKI_Apply.
 *
 * The `movs r1,#0 / lsls r1,r1,#1 / lsrs r0,r0,#31 / orrs` run that four
 * waves read as a scheduling tie of two u32 shifts is the high word of a
 * 64-bit product: the draw widened to u64, times 2, shifted right 32 (the
 * random-below-N idiom, docs/idioms/random-below-n-is-a-64-bit-multiply-high.md,
 * with N = 2).  The zero high half is shifted left by one and ORed with the
 * low half's carry-out bit; the compiler emits the two halves in that order,
 * which is the order no u32 spelling could reach.  `% 2 == 0` gives the
 * `tst` against 1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NATSUKI_CalcWalk.c \
 *       --func NATSUKI_CalcWalk --addr 0x0201B7EC --cc 1.1p1 --thumb
 */
void NATSUKI_CalcWalk(struct PokemonParam *pp, int zoneId, u16 heap)
{
    if ((u32)((u64)GF_STANDARD_Rand() * 2 >> 32) % 2 == 0) {
        NATSUKI_Apply(pp, _NatsukiWalkDeltas, zoneId, heap);
    }
}

/*
 * was-blocked: 0209E462.  The `literal` class still refuses it -- the only
 *           pool word in the image holding 0x0209E462 is this function's own,
 *           at 0x0201B84C, inside the compared range.  The site resolves as
 *           `sole-ref` instead, so the entry is EXACT and not MATCH.
 *
 * for (i = 0; i < count(a0); i++) NATSUKI_Apply(entry(a0, i), &_NatsukiPartyDeltas,
 * a1, a2); - the entry pointer the loop computes is what feeds the second
 * call's first argument, which is why no `r0 = a0` copy appears in front of
 * it (the returned r0 is already the argument), and the bound is
 * re-evaluated at the bottom of the loop so it stays a call in the
 * condition.  The table pointer is this function's own pool word at
 * 0x0201B84C, behind the C0 46 alignment filler at 0x0201B84A.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NATSUKI_CalcParty.c \
 *       --func NATSUKI_CalcParty --addr 0x0201B818 --cc 1.1p1 --thumb
 */
void NATSUKI_CalcParty(struct Party *party, int zoneId, u16 heap)
{
    int i;

    for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
        NATSUKI_Apply(POKEPARTY_GetMember(party, i), _NatsukiPartyDeltas, zoneId, heap);
    }
}

/*
 * Applies an EV/stat-like gain to party record id 9, scaled by a per-band
 * table the caller supplies.  The species read (id 0xAB) gates the whole
 * body: species 0 and species 650 both return early.
 *
 * The band index `idx` doubles as the literal zero argument of the three
 * POKE_TOOL_GetPartyValue reads, which is why it is a named u8 initialised before the
 * species call rather than three separate `0` literals; and the two
 * increments must be spelled `idx++` (post-increment), not `idx = idx + 1`,
 * or the compiler proves idx is still 0 at the first band test and folds it
 * to `movs r5, #1`, costing the `adds/lsls/lsrs` triple.
 *
 * The function returns void: an `int` return adds a `movs r0, #0` before the
 * epilogue.
 *
 * VERSION SENSITIVITY: 650 is a species id and 0xAB / 6 / 9 / 0x96 / 0x98 are
 * party-record ids; both are content numbering and should be re-read for a
 * White build.  0x35 is the value FILE_UTIL_GetItemParam returns for one particular
 * kind and is content numbering too.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/NATSUKI_Apply.c \
 *       --func NATSUKI_Apply --addr 0x0201B850 --cc 1.1p1 --thumb
 *   python tools/match.py tu --src src/matched/NATSUKI_Apply.c \
 *       --addr 0x0201B850 --thumb
 */
void NATSUKI_Apply(struct PokemonParam *pp, const s8 *deltas, int zoneId, u16 heap)
{
    int placeId;
    u32 species;
    u32 holdEffect;
    int friendship;
    int delta;
    u8 band;

    placeId = ZONEDATA_GetPlaceNameId(zoneId);
    band = 0;
    species = (u16)POKE_TOOL_GetPartyValue(pp, 0xAB, 0);
    if (species == 0 || species == 650) {
        return;
    }
    holdEffect = (u8)FILE_UTIL_GetItemParam((u16)POKE_TOOL_GetPartyValue(pp, 6, band), 1, heap);
    friendship = POKE_TOOL_GetPartyValue(pp, 9, band);

    if (friendship >= 100) {
        band++;
    }
    if (friendship >= 200) {
        band++;
    }
    delta = deltas[band];
    if (delta > 0) {
        if (POKE_TOOL_GetPartyValue(pp, 0x98, 0) == 11) {
            delta = delta + 1;
        }
    }
    if (placeId != 0 && delta > 0) {
        if (placeId == (int)POKE_TOOL_GetPartyValue(pp, 0x96, 0)) {
            delta = delta + 1;
        }
    }
    if (delta > 0 && holdEffect == 0x35) {
        delta = delta * 150 / 100;
    }
    friendship = friendship + GPOWER_ApplyFriendshipBonus(delta);
    if (friendship < 0) {
        friendship = 0;
    }
    if (friendship > 255) {
        friendship = 255;
    }
    POKE_TOOL_SetPartyValue(pp, 9, friendship);
    return;
}
