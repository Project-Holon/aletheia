/*
 * file:     poke_personal.c
 * unit:     yes
 * function: POKE_PERSONAL_OpenHandle, POKE_PERSONAL_LoadData, POKE_PERSONAL_LoadDataDirect, POKE_PERSONAL_Create, POKE_PERSONAL_Delete, POKE_PERSONAL_GetParam, POKE_PERSONAL_IsFixedGender, POKE_PERSONAL_LoadFormTable, POKE_PERSONAL_GetFormDataId
 * address:  0x0201AD88
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
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   GFL_HEAP_Alloc 0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   _pPersonalArc  0x0214652C  data
 *   poke_personal_File  0x020A7310  data
 *   ARC_UTIL_LoadHandleMemberWithSize  0x0204A39C  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_GetHandleMemberOffset  0x02049578  arm
 *   ARC_TOOL_ReadHandle  0x020495F4  arm
 *   ARC_TOOL_SeekHandle  0x0204960C  arm
 */
#include "pokeparty_shared_types.h"

#include "poke_personal_types.h"

#include "arc_tool.h"

#include "gfl_heap_wrap.h"






#include "arc_util.h"

void POKE_PERSONAL_OpenHandle(u32 heap);

void POKE_PERSONAL_LoadData(u32 species, int form, void *dst);

void POKE_PERSONAL_LoadDataDirect(u32 species, int form, void *dst);

struct PersonalData *POKE_PERSONAL_Create(u32 species, int form, u32 heap);

void POKE_PERSONAL_Delete(struct PersonalData *data);

u32 POKE_PERSONAL_GetParam(const struct PersonalData *data, u32 field);

u32 POKE_PERSONAL_IsFixedGender(u32 ability);

u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);

u32 POKE_PERSONAL_GetFormDataId(u32 species, s32 form);

extern struct ArcHandle *_pPersonalArc;

extern const char poke_personal_File[];

/*
 * The lazy constructor for the static handle at 0x0214652C that
 * src/matched/unit_0201ADA4.c and src/matched/unit_0201ADD0.c thread every
 * call through: allocates a 0x10 byte object out of the heap named by the
 * parameter the first time it is asked and does nothing afterwards.
 *
 * The `adds r1, r0, #0` that moves the parameter out of r0 sits in front of
 * the guard's own load rather than inside the `if`, which is what the
 * parameter being live across the test costs; it is not an argument set-up
 * for a call that happens later.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AD88.c \
 *       --addr 0x0201AD88 --thumb
 */
void POKE_PERSONAL_OpenHandle(u32 heap)
{
    if (_pPersonalArc == 0) {
        _pPersonalArc = ARC_TOOL_CreateHandle(0x10, heap);
    }
}

/*
 * A three-parameter wrapper: calls POKE_PERSONAL_GetFormDataId(a, b) (0x0201AFD4, still
 * open) and threads its result through two handler calls keyed off a static
 * handle at 0x0214652C, then hands the third parameter off to a third
 * handler with a literal id of 0x3C.  Kept as its own file rather than
 * merged with the neighbouring POKE_PERSONAL_LoadDataDirect/POKE_PERSONAL_Create
 * (src/matched/unit_0201ADD0.c) because both of those call POKE_PERSONAL_GetFormDataId as
 * well; one range holding all three calls has none of them attested and
 * caps at MATCH (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 * With this function alone, the other two callers are outside the range and
 * carry the `label` evidence.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ADA4.c \
 *       --addr 0x0201ADA4 --thumb
 */
void POKE_PERSONAL_LoadData(u32 species, int form, void *dst)
{
    u32 dataId = POKE_PERSONAL_GetFormDataId(species, form);

    dataId = ARC_TOOL_GetHandleMemberOffset(_pPersonalArc, dataId);
    ARC_TOOL_SeekHandle((struct FSFile *)_pPersonalArc, dataId);
    ARC_TOOL_ReadHandle((struct ArcHandleRaw *)_pPersonalArc, 0x3C, dst);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * POKE_PERSONAL_LoadDataDirect is a second, smaller wrapper around POKE_PERSONAL_GetFormDataId (see
 * src/matched/unit_0201ADA4.c for why it is not merged with that file); here
 * the result goes straight to one handler call with a literal id of 0x12.
 *
 * POKE_PERSONAL_Create constructs an object from the debug allocator,
 * GFL_HEAP_Alloc(heap, size, zero, file, tag), with the __FILE__
 * argument an ABS32 into the packed string area rather than a locally
 * emitted string (docs/idioms/file-string-is-an-abs32-into-the-string-area.md).
 * The string is "poke_personal.c" at 0x020A7310, attested by the `string`
 * class off the terminator of "pokeparty.c" just before it; both sit in the
 * same run of Pokemon-data file names as "poke_tool.c", "poke_regulation.c"
 * and "shinka_check.c" starting at 0x020A72E4, which is the strongest single
 * clue to this packet's subsystem: species/personal-data records, not the
 * WCM/NHTTP wireless code the neighbouring packets' sdk_calls hint at.  It
 * then forwards to POKE_PERSONAL_LoadData (src/matched/unit_0201ADA4.c) and returns the
 * newly allocated object.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ADD0.c \
 *       --addr 0x0201ADD0 --thumb
 */
void POKE_PERSONAL_LoadDataDirect(u32 species, int form, void *dst)
{
    u32 dataId = POKE_PERSONAL_GetFormDataId(species, form);

    ARC_TOOL_ReadMember(dst, 0x12, dataId);
}

struct PersonalData *POKE_PERSONAL_Create(u32 species, int form, u32 heap)
{
    struct PersonalData *data = GFL_HEAP_Alloc(heap, 0x3C, 0, poke_personal_File, 0x76);

    POKE_PERSONAL_LoadData(species, form, data);
    return data;
}

/*
 * poke_personal.c's record destructor: four bytes of code and one pool word,
 * a tail call with no argument set-up at all
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  It abuts
 * src/matched/unit_0201ADD0.c on the left, whose POKE_PERSONAL_Create carries the
 * "poke_personal.c" file string.
 *
 * This file used to hold the whole middle of poke_personal.c
 * (0x0201AE14..0x0201AFD4: this destructor, the 44 field getter, the
 * placeholder-ability predicate and the form-table loader).  It was cut into
 * three so that the 44 field getter, which the whole poke_* region reads the
 * personal record through, gets a manifest entry of its own instead of being
 * an interior function with no attestable address
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).  The other two
 * pieces are src/matched/POKE_PERSONAL_GetParam.c and src/matched/unit_0201AF6C.c; the
 * C in all three is unchanged, only the file boundaries moved, and no
 * relocation crosses a new boundary.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AE14.c \
 *       --addr 0x0201AE14 --thumb
 */
void POKE_PERSONAL_Delete(struct PersonalData *data)
{
    GFL_HEAP_Free(data);
}

/*
 * poke_personal.c's 44 field getter over the 0x3C byte personal record, cut
 * out of src/matched/unit_0201AE14.c so that it has a manifest entry of its
 * own.  The bytes and the C are unchanged; only the file boundary moved.
 *
 * Why it is its own file: the manifest records one entry per unit at the
 * unit's start address, so while this function sat in the middle of
 * unit_0201AE14.c the address 0x0201AE1C had no entry, was not an address the
 * `matched` evidence class could attest, and read as still open to every
 * consumer that asked the manifest what the record layer covers
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).  It has high
 * fan-in: it is the field selector the whole poke_* region reads the personal
 * record through, so it is exactly the address that wants an entry.
 *
 * Splitting costs nothing here: POKE_PERSONAL_Delete (the record destructor, four
 * bytes of code and a pool word) keeps the start address and therefore keeps
 * its entry, POKE_PERSONAL_IsFixedGender and POKE_PERSONAL_LoadFormTable move into
 * src/matched/unit_0201AF6C.c which starts at the address of the first of
 * them, and this function holds no relocation at all, so no cut can take a
 * witness away from anybody.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * The 44 case ids are an interface rather than content: they are the field
 * selector the whole region uses, and src/matched/POKE_TOOL_CalcParam.c reads the
 * same record through ids of its own.  The field offsets are structure and
 * will not move; the ids will not either unless a field is added, which is
 * exactly the kind of thing a version diff does, so the map below is the thing
 * to check against IRAO rather than any single number.  No constant in this
 * function is a content id.
 *
 * ---------------------------------------------------------------------------
 * THE FIELD MAP, from the jump table
 * ---------------------------------------------------------------------------
 * The table at 0x0201AE2E is 44 signed halfwords and every one of them names a
 * real body, so the source has case labels 0 through 43 with no gaps
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md).  The bodies
 * are emitted in the source's order, which here is also the numeric order,
 * even though the offsets they read are not monotonic: id 9 reads +0x22 and id
 * 36 reads +0x09, both out of sequence.
 *
 *    0.. 5  +0x00..+0x05  the six base stats
 *    6, 7   +0x06, +0x07  the two types
 *    8      +0x08
 *    9      +0x22
 *   10..15  +0x0A bits 0..11, six 2 bit fields: the six effort yields
 *   16      +0x0A bit 12, one bit
 *   17..19  +0x0C, +0x0E, +0x10  three held item ids
 *   20..29  +0x12..+0x1B  ten bytes
 *   30, 31  +0x1C, +0x1E  the form table base and its companion; +0x1C is the
 *                         same field src/matched/unit_0201AFD4.c reads
 *   32      +0x20         the form count, also read by unit_0201AFD4.c
 *   33      +0x21 bits 0..5
 *   34, 35  +0x21 bit 6, bit 7
 *   36      +0x09
 *   37, 38  +0x24, +0x26
 *   39..43  +0x28..+0x38  five words
 *
 * Two shapes in there are readings of the declaration rather than of the code.
 * The 2 bit and 1 bit extractions at +0x0A are `lsls`/`lsrs` pairs whose width
 * is neither 8, 16 nor 32, so they are bitfields and nothing else
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md); the
 * container has to be `u16` for the load to be a `ldrh`, and `u8` at +0x21 for
 * it to be a `ldrb`.  And the two bytes at +0x20 and +0x21 each cost an
 * `adds r0, #0x20` first, which is only the byte immediate's reach of 31
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md); the halfword at +0x22
 * needs none, because `ldrh` reaches 62.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/POKE_PERSONAL_GetParam.c \
 *       --addr 0x0201AE1C --thumb
 */
u32 POKE_PERSONAL_GetParam(const struct PersonalData *data, u32 field)
{
    switch (field) {
    case 0:  return data->baseHp;
    case 1:  return data->baseAttack;
    case 2:  return data->baseDefense;
    case 3:  return data->baseSpeed;
    case 4:  return data->baseSpAttack;
    case 5:  return data->baseSpDefense;
    case 6:  return data->type1;
    case 7:  return data->type2;
    case 8:  return data->catchRate;
    case 9:  return data->baseExp;
    case 10: return data->evHp;
    case 11: return data->evAttack;
    case 12: return data->evDefense;
    case 13: return data->evSpeed;
    case 14: return data->evSpAttack;
    case 15: return data->evSpDefense;
    case 16: return data->yieldFlag;
    case 17: return data->heldItemCommon;
    case 18: return data->heldItemRare;
    case 19: return data->heldItemDream;
    case 20: return data->genderRatio;
    case 21: return data->eggCycles;
    case 22: return data->baseFriendship;
    case 23: return data->growthRate;
    case 24: return data->eggGroup1;
    case 25: return data->eggGroup2;
    case 26: return data->ability1;
    case 27: return data->ability2;
    case 28: return data->hiddenAbility;
    case 29: return data->escapeRate;
    case 30: return data->formStatsIndex;
    case 31: return data->formSpriteIndex;
    case 32: return data->formCount;
    case 33: return data->color;
    case 34: return data->spriteFlip;
    case 35: return data->formSpriteShared;
    case 36: return data->evoStage;
    case 37: return data->height;
    case 38: return data->weight;
    case 39: return data->tmFlags1;
    case 40: return data->tmFlags2;
    case 41: return data->tmFlags3;
    case 42: return data->tmFlags4;
    case 43: return data->tutorFlags;
    }
    return 0;
}

/*
 * The tail of poke_personal.c: the "is this a placeholder ability id"
 * predicate and the form-table loader.  Cut out of
 * src/matched/unit_0201AE14.c together with src/matched/POKE_PERSONAL_GetParam.c so
 * that the 44 field getter at 0x0201AE1C gets a manifest entry of its own
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).  The C is
 * unchanged; only the file boundary moved.  This file still starts at the
 * address of its own first function, so it loses no entry by the same rule:
 * POKE_PERSONAL_LoadFormTable was already an interior function of unit_0201AE14.c.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Three content constants live here and every one of them is a number the
 * game's data, not its structure, decides:
 *
 *   0x29C (668)  POKE_PERSONAL_LoadFormTable's archive member id, the form table.  It is the
 *                index of one member inside the handle at 0x0214652C, so it
 *                moves if the archive is repacked; IRAO is expected to share
 *                the packing but this is the first thing to re-read.
 *   999          POKE_PERSONAL_LoadFormTable's "no entry" sentinel in that form table.  It is
 *                a species-space sentinel, not a count, and it is what the
 *                entry count is measured against.
 *   0, 0xFE,0xFF POKE_PERSONAL_IsFixedGender's three accepted ids.  The callers (0x02017D00,
 *                0x0201860E, 0x020186AE, 0x020186FE, 0x02018718) all feed it a
 *                value read out of the personal record, so these are content
 *                ids in the same space as the record's own fields.
 *
 * ---------------------------------------------------------------------------
 * THE TWO FUNCTIONS
 * ---------------------------------------------------------------------------
 * POKE_PERSONAL_IsFixedGender is a disjunction and not a conjunction.  The `beq` from the
 * first test lands on the `movs r0, #1` that the second test's `bhi` falls
 * through to, and the `movs r0, #0` is out of line behind it; written
 * `if (v != 0 && v - 0xFE > 1) return 0;` every byte is still right and the
 * two exit blocks come out in the opposite order
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md,
 * docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * POKE_PERSONAL_LoadFormTable narrows the byte length the archive hands back to a halfword
 * count with a single `lsls #0xf` / `lsrs #0x10` pair.  The amounts are
 * unequal, so it is a cast folded with a shift and not a bitfield: 32 - 16 is
 * the width and 15 - 16 is the shift, i.e. `(u16)(len >> 1)`
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * Writing `(u16)(len / 2)` costs a second pair.  The counter's zero is a copy
 * of the accumulator's (`adds r2, r5, #0`), which is what says the
 * accumulator is assigned first
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AF6C.c \
 *       --addr 0x0201AF6C --thumb
 */
u32 POKE_PERSONAL_IsFixedGender(u32 ability)
{
    if (ability == 0 || ability - 0xFE <= 1) {
        return 1;
    }
    return 0;
}

u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut)
{
    u32 size;
    u16 *table;
    u16 count;
    u16 entryCount;
    u16 i;

    count = 0;
    table = ARC_UTIL_LoadHandleMemberWithSize(_pPersonalArc, 0x29C, 0, heap, &size);
    entryCount = (u16)(size >> 1);
    if (countOut != 0) {
        for (i = 0; i < entryCount; i++) {
            if (table[i] != 999) {
                count++;
            }
        }
        *countOut = count;
    }
    return table;
}

/*
 * The species-to-form resolver the three wrappers in
 * src/matched/unit_0201ADA4.c and src/matched/unit_0201ADD0.c open with: it
 * reads the 0x3C byte personal record for the species out of the archive
 * handle at 0x0214652C and, when the record has a form table and the
 * requested form is inside it, answers with the form's own species-like id.
 *
 * VERSION SENSITIVITY: the guard rejects exactly the two ids 650 and 651,
 * which are the egg and bad-egg entries src/pending/POKE_TOOL_GetBoxValueRaw.c's field
 * map already names, and it spells them as a 16 bit range test.  They are
 * content ids rather than structure offsets, so they are the first thing to
 * re-read for a Pokemon White build; nothing else in this function is
 * version dependent.
 *
 * The test is written `(u16)(species + 0xFD76) > 1`, not `species - 650`:
 * 0x28A does not fit an 8 bit immediate either way, and only the positive
 * unsigned 16 bit spelling of the complement keeps the constant in the pool
 * where the original has it
 * (docs/idioms/out-of-range-immediate-subtract-costs-a-pool-word.md).
 *
 * The three tests in the tail are one disjunction guarding `return species`,
 * not the conjunction guarding the computed answer that the semantics
 * suggest: written the other way round every byte is still right but the two
 * exit blocks are emitted in the opposite order, because the block the source
 * writes inside the `if` is the one that comes first
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md and
 * docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * The record's halfword at +0x1C is reached with a plain `ldrh [r0, #0x1c]`
 * while its byte at +0x20 costs an `add r0, sp, #0x20` first, which is only
 * the byte immediate's reach of 31 and not a second pointer
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AFD4.c \
 *       --addr 0x0201AFD4 --thumb
 */
u32 POKE_PERSONAL_GetFormDataId(u32 species, s32 form)
{
    struct PersonalData data;

    if ((u16)(species + 0xFD76) <= 1) {
        return 0;
    }
    ARC_TOOL_SeekHandle((struct FSFile *)_pPersonalArc, ARC_TOOL_GetHandleMemberOffset(_pPersonalArc, species));
    ARC_TOOL_ReadHandle((struct ArcHandleRaw *)_pPersonalArc, 0x3C, &data);
    if (data.formStatsIndex == 0 || data.formCount <= form || form == 0) {
        return species;
    }
    return (u16)(data.formStatsIndex + form - 1);
}
