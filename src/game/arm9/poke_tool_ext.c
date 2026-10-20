/*
 * file:     poke_tool_ext.c
 * unit:     yes
 * function: POKE_TOOL_IsPPRestorable, POKE_TOOL_RestorePP, POKE_TOOL_HealFull, POKE_TOOL_HealParty, POKE_TOOL_GetGraphicIndex, POKE_TOOL_CalcGraphicIndex, POKE_TOOL_CalcIconPalette, POKE_TOOL_GetIconPalette, POKE_TOOL_GetIconPaletteArcId, POKE_TOOL_GetIconCellArcId, POKE_TOOL_GetIconCellArcIdSub, POKE_TOOL_GetIconCellEntryId, POKE_TOOL_GetIconCellEntryIdSub
 * address:  0x0201B920
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
 *   _IconPaletteTable  0x0209E474  data
 *   POKE_TOOL_GetPersonalParam 0x02019C90 thumb
 *   ARC_TOOL_GetMemberSize  0x020490A8  arm
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb arm9
 *   POKEPARTY_GetMember 0x0201AB28 thumb arm9
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb arm9
 */
#include "pokeparty_shared_types.h"

#define REG_DISPCNT      (*(volatile u32 *)0x04000000)

#define REG_DB_DISPCNT   (*(volatile u32 *)0x04001000)

#define OBJ_MAPPING_MASK 0x300010

#include "poke_tool.h"





#include "arc_tool.h"


#include "pokeparty.h"


u8 POKE_TOOL_IsPPRestorable(struct PokemonParam *pp, u32 slot);

u32 POKE_TOOL_RestorePP(struct PokemonParam *pp, u32 slot, u32 amount);

void POKE_TOOL_HealFull(struct PokemonParam *pp);

void POKE_TOOL_HealParty(struct Party *party);

u32 POKE_TOOL_GetGraphicIndex(struct BoxPokemon *box);

u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);

u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 female, u32 isEgg);

u32 POKE_TOOL_GetIconPalette(struct BoxPokemon *box);

int POKE_TOOL_GetIconPaletteArcId(void);

int POKE_TOOL_GetIconCellArcId(void);

int POKE_TOOL_GetIconCellArcIdSub(void);

int POKE_TOOL_GetIconCellEntryId(void);

int POKE_TOOL_GetIconCellEntryIdSub(void);

#include "waza_tool.h"

extern const u8 _IconPaletteTable[];

/*
 * A single function, matched as a byte range because the function after it is
 * a near miss and a committed range has to be EXACT end to end.
 *
 * pokeparty.c's "is this move slot short of PP" predicate: 78 bytes, three
 * reads of the party record and one call into the PP table.
 *
 * The three ids it reads are three parallel runs of the record's id space,
 * one per move slot: 0x36 + slot is the move, 0x3A + slot its current PP and
 * 0x3E + slot its PP ups.  src/matched/unit_0201C158.c turns the last two of
 * those into the slot's maximum, and the answer is whether the current PP is
 * below it.
 *
 * It stands alone rather than inside a unit with its neighbours because
 * POKE_TOOL_RestorePP, which sits immediately after it, is a documented near miss
 * (docs/notes/POKE_TOOL_RestorePP.c.txt) and a range cannot be committed while any
 * part of it is short of EXACT.  Its own single caller, POKE_TOOL_HealFull at
 * 0x0201BA18, is parked in src/pending/unit_0201B9F0.c and resolves this
 * address through the `matched` class off this entry.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id appears here.  0x36, 0x3A and 0x3E are party
 * record ids in src/matched/POKE_TOOL_GetPartyValueRaw.c's space, and the three are written
 * out as three separate literals rather than derived from one base, so a
 * version that inserted a field into that id space would move all three
 * independently.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The function has two epilogues and only the second truncates the result.
 * That is what says the early exit returns the result *variable* while it is
 * still provably zero rather than the literal zero: `return 0;` would be a
 * `movs r0, #0` where the original copies r5, and a shared exit would need the
 * two tests to be one conjunction, which they cannot be because the second one
 * depends on the first's call
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * The result variable is therefore wider than the return type: declared `u8`
 * it needs no truncation at the tail and the function is two bytes short.
 *
 * The third id is built by advancing r7 in place (`adds r7, #0x3e` over the
 * register that held the slot), which is the last use of the slot number and
 * not a separate pointer.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_TOOL_IsPPRestorable.c \
 *       --func POKE_TOOL_IsPPRestorable --addr 0x0201B920 --cc 1.1p1
 */
u8 POKE_TOOL_IsPPRestorable(struct PokemonParam *pp, u32 slot)
{
    u16 move;
    u8 curPP;
    u8 ppUp;
    u32 result;

    result = 0;
    move = (u16)POKE_TOOL_GetPartyValue(pp, slot + 0x36, 0);
    if (move == 0) {
        return result;
    }
    curPP = (u8)POKE_TOOL_GetPartyValue(pp, slot + 0x3A, 0);
    ppUp = (u8)POKE_TOOL_GetPartyValue(pp, slot + 0x3E, 0);
    if (curPP < WAZA_TOOL_GetMaxPP(move, ppUp)) {
        result = 1;
    }
    return result;
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`id = slot;` before `id = slot + 0x3A;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT* in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 *
 * pokeparty.c.  Restore PP to one move slot: read the move (0x36 + slot),
 * its current PP (0x3A + slot) and its PP ups (0x3E + slot), ask
 * WAZA_TOOL_GetMaxPP for the slot's maximum, and if the slot is short either fill
 * it (amount 0x7F) or add `amount` and clamp at the maximum.
 *
 * The last register copy (`adds r2, r4, #0` ahead of POKE_TOOL_SetPartyValue, the new
 * PP kept in r4 where the old one lived) is the compound assignment
 * `pp += (u8)amount`: the spelled-out `pp = (u8)(pp + (u8)amount)` starts a
 * new value that coalesces straight into the argument register (wave 15;
 * docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-
 * the-cached-load.md is the same lever on a field).  WAZA_TOOL_GetMaxPP returns a
 * u8, so `max` is u8 (wave 14).  The dead store `id = slot` is the image's
 * `str r0, [sp]` before the add.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_RestorePP.c \
 *       --func POKE_TOOL_RestorePP --addr 0x0201B970 --thumb
 */
u32 POKE_TOOL_RestorePP(struct PokemonParam *pp, u32 slot, u32 amount)
{
    u16 move;
    u32 ppId;
    u8  curPP;
    u32 ppUp;
    u8  maxPP;

    move = (u16)POKE_TOOL_GetPartyValue(pp, slot + 0x36, 0);
    if (move == 0) {
        return 0;
    }
    ppId = slot + 0x3A;
    curPP = (u8)POKE_TOOL_GetPartyValue(pp, ppId, 0);
    ppUp = POKE_TOOL_GetPartyValue(pp, slot + 0x3E, 0);
    maxPP = WAZA_TOOL_GetMaxPP(move, (u8)ppUp);
    if (curPP < maxPP) {
        if (amount == 0x7F) {
            curPP = maxPP;
        } else {
            curPP += (u8)amount;
            if (curPP > maxPP) {
                curPP = maxPP;
            }
        }
        POKE_TOOL_SetPartyValue(pp, ppId, curPP);
        return 1;
    }
    return 0;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * pokeparty.c's healer: POKE_TOOL_HealFull restores one Pokemon (current HP to its
 * maximum, status to zero, and every move slot that is short of PP back to
 * full), and POKE_TOOL_HealParty runs it over every occupied slot of a party.
 * POKE_TOOL_HealParty is the packet's only entry point, reached from 0x02011062.
 *
 * Both of its calls into the neighbouring functions resolve, and the second one
 * is the interesting one.  0x0201B920 is covered by src/matched/
 * unit_0201B920.c, so the `matched` class would carry it on its own;
 * 0x0201B970 is a near miss (docs/notes/POKE_TOOL_RestorePP.c.txt) and has no matched
 * entry at all, and the only `bl` to it inside arm9_main is the one in this
 * file.  What attests it is an overlay: ov118 branches to 0x0201B970 at
 * 0x021BE4D0, and to 0x0201B920 at 0x021BDF2A, and those are real instructions
 * outside the compared range, which is exactly what the `label` class asks for
 * once it reads branches from the whole image rather than from arm9 alone.
 * The two functions here would otherwise have had to be split apart or parked.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id.  0x7F is the "fill the slot" sentinel
 * POKE_TOOL_RestorePP tests for and has to stay in step with it; 4 is the move slot
 * count written out as the loop bound; 0xA9, 0xA0, 0xA1 and 0x9D are party
 * record ids in src/matched/POKE_TOOL_GetPartyValueRaw.c's space.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The id 0xA1 read is used directly as the id 0xA0 write's third argument with
 * nothing bound to a local, so the result reaches r2 straight out of r0; this
 * is the site where the inline spelling is the right one
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 *
 * POKE_TOOL_HealFull's `for` runs 0 to 3 with no entry guard, because the compiler
 * can see the bound; the 0x7F is hoisted into r6 in front of the loop and the
 * index's zero is set before the two writes that precede it.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0201B9F0.c \
 *       --addr 0x0201B9F0 --thumb
 */
void POKE_TOOL_HealFull(struct PokemonParam *pp)
{
    s32 i;

    POKE_TOOL_SetPartyValue(pp, 0xA0, POKE_TOOL_GetPartyValue(pp, 0xA1, 0));
    POKE_TOOL_SetPartyValue(pp, 0x9D, 0);
    for (i = 0; i < 4; i++) {
        if (POKE_TOOL_IsPPRestorable(pp, i) == 1) {
            POKE_TOOL_RestorePP(pp, i, 0x7F);
        }
    }
}

void POKE_TOOL_HealParty(struct Party *party)
{
    s32 memberCount;
    s32 i;
    struct PokemonParam *member;

    memberCount = POKEPARTY_GetCount(party);
    for (i = 0; i < memberCount; i++) {
        member = POKEPARTY_GetMember(party, i);
        if (POKE_TOOL_GetPartyValue(member, 0xA9, 0) != 0) {
            POKE_TOOL_HealFull(member);
        }
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * The graphics index of a Pokemon: POKE_TOOL_GetGraphicIndex unpacks the four values that
 * decide it out of the record and POKE_TOOL_CalcGraphicIndex turns them into a member number
 * of archive 7.  The pair that follows them, POKE_TOOL_CalcIconPalette and POKE_TOOL_GetIconPalette, is
 * the same index arithmetic over a different table and is parked in
 * src/pending/unit_0201BB5C.c because that table has no witness; the cut
 * between the two pairs is what lets this half land
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * POKE_TOOL_GetGraphicIndex brackets its four reads with POKE_TOOL_DecodeBoxParam and POKE_TOOL_EncodeBoxParam,
 * which is the pair the region uses around a run of raw field reads; that is
 * why the reads here are POKE_TOOL_GetBoxValue and not the POKE_TOOL_GetPartyValue of
 * src/matched/POKE_TOOL_CalcParam.c.  The fourth read is written inline as the call's
 * fourth argument rather than bound to a local, which is what puts it in r3
 * with the other three already in place.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Four content constants, and the index arithmetic that ties them together is
 * itself a statement about how the sprite archive is packed:
 *
 *   490    the species whose egg has a graphic of its own.  Every other
 *          species shares one egg graphic.
 *   650    the index the ordinary egg occupies, so 651 is that species' egg;
 *          the same 650/651 pair src/matched/unit_0201AFD4.c rejects as
 *          species ids.
 *   7      the first member of archive 7 that belongs to a species, and the
 *          stride is two members per index.
 *   1311   the member the alternate forms start at, which is 652 * 2 + 7, i.e.
 *          immediately after the two egg indices.  A White build with a
 *          different species count would move this number and only this one.
 *   0x1F, 0x20, 0x23   the three personal-record attributes POKE_TOOL_GetPersonalParam
 *          answers: the form block's first index, the form count, and the flag
 *          that says the forms are not drawn separately.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The `case 1` arm binds the archive query to a local before assigning the
 * gender.  Written inline, `gender = 1;` is hoisted in front of the `blx` and
 * six bytes come out in the wrong order; the named local is what pins the
 * order, the same way
 * docs/idioms/cmp-operand-order-names-the-temporary.md pins a comparison.
 *
 * `case 2`'s `gender = 0;` and `case 1`'s failure arm are one block, reached
 * by a `b` whose displacement is zero: the source writes the statement out in
 * both arms and the compiler cross-jumps the two copies
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).  The switch
 * is a `cmp`/`beq` chain rather than a table, because three labels are too few
 * for mwccarm to build one
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md, the other side of
 * the density rule).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201BA68.c \
 *       --addr 0x0201BA68 --thumb
 */
u32 POKE_TOOL_GetGraphicIndex(struct BoxPokemon *box)
{
    u32 wasDecoded;
    u32 species;
    u32 form;
    u32 gender;
    u32 index;

    wasDecoded = POKE_TOOL_DecodeBoxParam(box);
    species = POKE_TOOL_GetBoxValue(box, 5, 0);
    form = POKE_TOOL_GetBoxValue(box, 0x6F, 0);
    gender = POKE_TOOL_GetBoxValue(box, 0x6E, 0);
    index = POKE_TOOL_CalcGraphicIndex(species, form, gender, POKE_TOOL_GetBoxValue(box, 0x4C, 0));
    POKE_TOOL_EncodeBoxParam(box, wasDecoded);
    return index;
}

u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg)
{
    u32 firstFormIndex;
    u32 formsShared;
    u32 formCount;
    u32 index;
    u32 hasFemale;

    index = species * 2 + 7;
    if (isEgg != 0) {
        index = (u32)((species == 490 ? 1 : 0) + 650) * 2 + 7;
    } else if (form != 0) {
        firstFormIndex = POKE_TOOL_GetPersonalParam((u16)species, 0, 0x1F);
        formsShared = POKE_TOOL_GetPersonalParam((u16)species, 0, 0x23);
        formCount = POKE_TOOL_GetPersonalParam((u16)species, 0, 0x20);
        if (form >= formCount) {
            form = 0;
        }
        if (formsShared == 0 && form != 0) {
            index = (firstFormIndex + form - 1) * 2 + 1311;
        }
    }
    switch (gender) {
    case 0:
        break;
    case 1:
        hasFemale = ARC_TOOL_GetMemberSize(7, index + 1);
        gender = 1;
        if (hasFemale == 0) {
            gender = 0;
        }
        break;
    case 2:
        gender = 0;
        break;
    }
    return index + gender;
}

/*
 * note:     224 bytes, two functions
 *
 * The nibble-table twin of src/matched/unit_0201BA68.c: the same egg and
 * alternate-form index arithmetic, indexing a packed table of two four bit
 * values per entry instead of an archive.  POKE_TOOL_GetIconPalette unpacks the four
 * inputs out of a Pokemon record, bracketed by the POKE_TOOL_DecodeBoxParam /
 * POKE_TOOL_EncodeBoxParam pair, and hands them over.
 *
 * The index is the same logical number unit_0201BA68.c computes, one step
 * short of it: there the answer is `n * 2 + 7`, a member of archive 7, here it
 * is `n` itself, and the alternate-form case reaches it as `first + form +
 * 651` where the other reaches `(first + form - 1) * 2 + 1311`.  1311 is
 * 652 * 2 + 7, so the two agree.
 *
 * ---------------------------------------------------------------------------
 * WHY IT WAS CAPPED (HISTORY)
 * ---------------------------------------------------------------------------
 * NO LONGER CAPPED (re-verified 2026-09-22).  The pool word at 0x0201BBE4 is
 * still the only word in the image that holds 0x0209E474, so the `literal`
 * class does discard its only witness.  What closed it is the sole-ref
 * widening of 2026-09-21: 0x0209E474 is 4-aligned and starts a recognised
 * data object, so the site now resolves as `sole-ref` and the unit is EXACT.
 * The old "WHY IT IS CAPPED" reading below is kept only as history.
 *
 * The cut between this pair and POKE_TOOL_GetGraphicIndex/POKE_TOOL_CalcGraphicIndex is what let those
 * two land EXACT.  POKE_TOOL_CalcIconPalette is reached only from 0x0201BC34, inside this
 * range, so that call is the `local` class and needs no evidence.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 *   490    the species whose egg has an entry of its own.
 *   650    the ordinary egg's index, so 651 is that species' egg; 651 again is
 *          the base the alternate-form block is counted from.
 *   0x1F, 0x20, 0x23   the three personal-record attributes POKE_TOOL_GetPersonalParam
 *          answers: the form block's first index, the form count, and the
 *          "not drawn separately" flag.
 *   0x0209E474  the table itself, one packed byte per index.  Its contents are
 *          content and are not reproduced here.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The two returns are unequal shift pairs, not bitfields: `lsls #0x14` /
 * `lsrs #0x18` is `(u8)(x >> 4)`, because 32 - 24 is the width and 20 - 24 is
 * the shift, and the low half's equal pair is a plain `(u8)`
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * The mask has to be written out as well as the cast; `x >> 4` on its own
 * loses the `ands`.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_0201BB5C.c \
 *       --addr 0x0201BB5C --thumb
 */
u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 female, u32 isEgg)
{
    u32 firstFormIndex;
    u32 formsShared;
    u32 formCount;
    u32 index;

    index = species;
    if (isEgg != 0) {
        index = (species == 490 ? 1 : 0) + 650;
    } else if (form != 0) {
        firstFormIndex = POKE_TOOL_GetPersonalParam((u16)species, 0, 0x1F);
        formsShared = POKE_TOOL_GetPersonalParam((u16)species, 0, 0x23);
        formCount = POKE_TOOL_GetPersonalParam((u16)species, 0, 0x20);
        if (form >= formCount) {
            form = 0;
        }
        if (formsShared == 0 && form != 0) {
            index = firstFormIndex + form + 651;
        }
    }
    if (female != 0) {
        return (u8)((_IconPaletteTable[index] & 0xF0) >> 4);
    }
    return (u8)(_IconPaletteTable[index] & 0xF);
}

u32 POKE_TOOL_GetIconPalette(struct BoxPokemon *box)
{
    u32 wasDecoded;
    u32 species;
    u32 form;
    u32 gender;
    u32 isEgg;

    wasDecoded = POKE_TOOL_DecodeBoxParam(box);
    species = POKE_TOOL_GetBoxValue(box, 5, 0);
    form = POKE_TOOL_GetBoxValue(box, 0x6F, 0);
    gender = POKE_TOOL_GetBoxValue(box, 0x6E, 0);
    isEgg = POKE_TOOL_GetBoxValue(box, 0x4C, 0);
    POKE_TOOL_EncodeBoxParam(box, wasDecoded);
    return POKE_TOOL_CalcIconPalette(species, form, gender, isEgg);
}

/*
 *           POKE_TOOL_GetIconCellEntryIdSub
 *
 * Five leaves after POKE_TOOL_GetIconPalette.  The first returns 0.  The other four read
 * the OBJ character mapping bits of DISPCNT (bit 4, 1D mapping, and bits
 * 20..21, the 1D boundary) for the main engine (0x04000000) or the sub engine
 * (0x04001000) and turn the 32/64/128 KB boundary into a shift: 2/4/6 and
 * 1/3/5, with the unlisted 256 KB case falling into a separate default that
 * repeats the last value.  Seeded from ov208 0x021C5304, 0x021C531E,
 * 0x021C5324 (ZUKAN_DETAIL_FORM_LoadIconResources) and ov021 0x021CC8EA, 0x021CC906, 0x021CC90C.
 *
 * Addresses are Black-image addresses.
 */
int POKE_TOOL_GetIconPaletteArcId(void)
{
    return 0;
}

int POKE_TOOL_GetIconCellArcId(void)
{
    switch (REG_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 2;
    case 0x100010: return 4;
    case 0x200010: return 6;
    default:       return 6;
    }
}

int POKE_TOOL_GetIconCellArcIdSub(void)
{
    switch (REG_DB_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 2;
    case 0x100010: return 4;
    case 0x200010: return 6;
    default:       return 6;
    }
}

int POKE_TOOL_GetIconCellEntryId(void)
{
    switch (REG_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 1;
    case 0x100010: return 3;
    case 0x200010: return 5;
    default:       return 5;
    }
}

int POKE_TOOL_GetIconCellEntryIdSub(void)
{
    switch (REG_DB_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 1;
    case 0x100010: return 3;
    case 0x200010: return 5;
    default:       return 5;
    }
}
