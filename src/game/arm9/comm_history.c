/*
 * file:     comm_history.c
 * unit:     yes
 * function: COMM_HISTORY_InsertIfNationSet, COMM_HISTORY_InsertOrReplace, COMM_HISTORY_CountLeadingOccupied, COMM_HISTORY_CountByKey, COMM_HISTORY_FindByKey, COMM_HISTORY_FindByKeys, COMM_HISTORY_RemoveAt, COMM_HISTORY_StoreAndNotify, COMM_HISTORY_StoreAt, SCROLLBAR_GetValueFromPos, SCROLLBAR_GetPosFromValue
 * address:  0x0202EB7C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from time_icon.c by tools/splitfile.py.
 *
 * symbols:
 *   WIFI_HISTORY_GetEntries  0x0200974C  thumb
 *   MYSTATUS_GetNation  0x0200856C  thumb
 *   COMM_HISTORY_CountLeadingOccupied  0x0202EC24  thumb
 *   MYSTATUS_GetId   0x02008530  thumb
 *   WIFI_HISTORY_MarkCountryVisited   0x02009750  thumb
 *   WIFI_HISTORY_IncrementVisitedCountryCount   0x020095E8  thumb
 *   _u32_div_f      0x0209C2B0  arm
 */
#include "comm_player_support_shared_types.h"

struct HistoryOwner;

/* One slot of the 20-entry history table (0x28 bytes). */
struct HistoryEntry {
    struct MyStatus record;     /* 0x00 */
    u8 reserved20[6];               /* 0x20 */
    u8 : 3;                         /* 0x26 */
    u8 isMarked : 1;
    u8 isOccupied : 1;
    u8 : 3;
    u8 reserved27;                  /* 0x27 */
};
struct MyStatus;

#include "mystatus.h"

#include "wifi_history.h"

struct WifiHistory;



u32 COMM_HISTORY_InsertIfNationSet(struct HistoryOwner *owner, struct HistoryEntry *entry);

u32 COMM_HISTORY_InsertOrReplace(struct HistoryOwner *owner, struct HistoryEntry *entry);

u32 COMM_HISTORY_CountLeadingOccupied(const struct HistoryEntry *table);

u32 COMM_HISTORY_CountByKey(struct HistoryEntry *table, u32 key);

s32 COMM_HISTORY_FindByKey(struct HistoryEntry *table, u32 key);

s32 COMM_HISTORY_FindByKeys(struct HistoryEntry *table, struct HistoryEntry *entry);

void COMM_HISTORY_RemoveAt(struct HistoryEntry *table, u32 index);

void COMM_HISTORY_StoreAndNotify(struct HistoryOwner *owner, struct HistoryEntry *entry, u32 mark);

void COMM_HISTORY_StoreAt(struct HistoryEntry *table, struct HistoryEntry *entry, u32 mark);

u32 SCROLLBAR_GetValueFromPos(u32 maxValue, u32 value, u32 rangeStart, u32 rangeEnd, u32 margin);

u32 SCROLLBAR_GetPosFromValue(u32 total, u32 rate, u32 start, u32 end, u32 margin);

/*
 * Byte-correct, MATCH-capped.
 *
 * All 30 concrete bytes are right; the call to COMM_HISTORY_InsertOrReplace is the only open
 * site and it is blocked on `label`: the sole branch to 0x0202EB9C image-wide
 * is the one inside this function, so there is no witness outside the
 * compared range and no cut helps (the range cannot be smaller than the one
 * function holding the call).  It closes when COMM_HISTORY_InsertOrReplace itself gets a
 * manifest entry or a second caller appears.
 *
 * The trailing `*` is the unlabelled follower at 0x0202EB9C: the listing's
 * extent runs 32 bytes against 30 compiled because the follower carries no
 * `func_` label in the generated listing.
 */
u32 COMM_HISTORY_InsertIfNationSet(struct HistoryOwner *owner, struct HistoryEntry *entry)
{
    if (MYSTATUS_GetNation((struct MyStatus *)(&entry->record)) == 0) {
        return 0;
    }
    return COMM_HISTORY_InsertOrReplace(owner, entry);
}

/*
 * The history table dispatcher (look the entry up; remove and notify, or
 * insert by key under the count-capped policy).  Closed in wave 16 under
 * 1.1p1, no pin: the notify call is written in BOTH arms of the count test.
 * 1.1p1 then cross-jumps the two notify tails (the then-arm's `b` at
 * 0x0202EC04, reached by the inner `blo` as a jump to a jump) and no longer
 * merges the two COMM_HISTORY_RemoveAt calls, and the a/b/v register rotation
 * resolves with it.  `isMarked` is the +0x26 bit-3 field.
 *
 * Returns 1 when an existing entry was replaced and 2 when a new one was
 * inserted.
 */
u32 COMM_HISTORY_InsertOrReplace(struct HistoryOwner *owner, struct HistoryEntry *entry)
{
    struct HistoryEntry *table;
    u32 index;
    u32 value;

    table = WIFI_HISTORY_GetEntries((struct WifiHistory *)owner);
    index = COMM_HISTORY_FindByKeys(table, entry);

    if (index != 0x14) {
        if (table[index].isMarked)
            value = 1;
        else
            value = 0;
        COMM_HISTORY_RemoveAt(table, index);
        COMM_HISTORY_StoreAndNotify(owner, entry, value);
        return 1;
    }

    value = MYSTATUS_GetNation((struct MyStatus *)(&entry->record));
    if (COMM_HISTORY_CountByKey(table, value) < 5) {
        if (COMM_HISTORY_CountLeadingOccupied(table) >= 0x14)
            COMM_HISTORY_RemoveAt(table, 0);
        COMM_HISTORY_StoreAndNotify(owner, entry, 0);
    } else {
        COMM_HISTORY_RemoveAt(table, COMM_HISTORY_FindByKey(table, value));
        COMM_HISTORY_StoreAndNotify(owner, entry, 0);
    }
    return 2;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Counts the leading run of occupied entries in a 20-entry array of
 * 0x28-byte records and returns the index of the first free one, or 20.
 * No prologue at all, because it calls nothing and needs no callee-saved
 * register, so `disasm.py` gives it no label.
 *
 * The occupancy test is `lsls #0x1B` / `lsrs #0x1F` on a byte at offset
 * 0x26, which is a one-bit unsigned bitfield at bit 4 and cannot be
 * written as a mask: `& 0x10` folds to `movs`/`ands` and a shift pair
 * with unequal amounts is a narrowing cast, not a field
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md,
 * docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * The record stride arrives as `movs r1, #0x28` / `muls` rather than a
 * scaled index because 0x28 is not a power of two.
 *
 * Matched as a one-function unit because the two bytes of `00 00` after
 * its last instruction are the linker's inter-section fill, so `one`
 * reports EXACT* for a padding gap rather than for an unlabelled
 * follower; `tu` compares the section as laid out.
 */
u32 COMM_HISTORY_CountLeadingOccupied(const struct HistoryEntry *table)
{
    u32 i;

    for (i = 0; i < 20; i++) {
        if (table[i].isOccupied == 0) {
            break;
        }
    }
    return i;
}

/*
 * Counts the occupied entries whose key matches, capped at five.  Same
 * 0x28-byte record as COMM_HISTORY_FindByKey, matched next door.
 */
u32 COMM_HISTORY_CountByKey(struct HistoryEntry *table, u32 key)
{
    u32 i;
    u32 count = 0;

    for (i = 0; i < 0x14; i++) {
        u32 entryKey;
        if (!table[i].isOccupied)
            break;
        entryKey = MYSTATUS_GetNation((struct MyStatus *)(&table[i].record));
        if (entryKey == key)
            count++;
    }

    if (count > 5)
        count = 5;
    return count;
}

/* Index of the first occupied entry with the given key, or 0x14. */
s32 COMM_HISTORY_FindByKey(struct HistoryEntry *table, u32 key)
{
    u32 i;

    for (i = 0; i < 0x14; i++) {
        u32 entryKey;
        if (!table[i].isOccupied) break;
        entryKey = MYSTATUS_GetNation((struct MyStatus *)(&table[i].record));
        if (entryKey == key) return i;
    }
    return 0x14;
}

/*
 * Finds the first occupied entry whose two keys both match the reference
 * entry's, or 0x14 when there is none.
 */
s32 COMM_HISTORY_FindByKeys(struct HistoryEntry *table, struct HistoryEntry *entry)
{
    u32 keyA = MYSTATUS_GetId((struct MyStatus *)(&entry->record));
    u32 keyB = MYSTATUS_GetNation((struct MyStatus *)(&entry->record));
    u32 i;

    for (i = 0; i < 0x14; i++) {
        u32 candidateA, candidateB;
        if (!table[i].isOccupied)
            break;
        candidateA = MYSTATUS_GetId((struct MyStatus *)(&table[i].record));
        if (candidateA == keyA) {
            candidateB = MYSTATUS_GetNation((struct MyStatus *)(&table[i].record));
            if (candidateB == keyB)
                return i;
        }
    }
    return 0x14;
}

/*
 * Removes entry `index` by shifting the following entries down, then clears
 * the occupied flag of the tail.
 *
 * EXACT* only for the two bytes of alignment padding at 0x0202ED5E.  Closed
 * in wave 16 (the residue since wave 12 was the ldm/stm base order of the
 * record copy): the copy goes through a named destination and a source
 * derived from it (`dst = &table[index]; src = dst + 1; *dst = *src;`), and
 * the flag test must NOT share the `table + index` subexpression with them,
 * or the front end rematerialises table + index*0x28 and computes the
 * source first.  `(table + 1)[index]` shares only the index*0x28 product,
 * which is what the image keeps in r7.
 */
void COMM_HISTORY_RemoveAt(struct HistoryEntry *table, u32 index)
{
    struct HistoryEntry *dst;
    struct HistoryEntry *src;

    if (index >= 0x14)
        return;

    if (index < 0x13) {
        while (1) {
            dst = &table[index];
            src = dst + 1;
            *dst = *src;
            if (!(table + 1)[index].isOccupied) {
                index++;
                break;
            }
            index++;
            if (index >= 0x13)
                break;
        }
    }

    while (index < 0x14) {
        table[index].isOccupied = 0;
        index++;
    }
}

/*
 * Stores the entry in the owner's table, then asks the owner whether the
 * entry's key now needs its follow-up (WIFI_HISTORY_IncrementVisitedCountryCount).  The key is read out
 * of the entry once into a named local and handed to WIFI_HISTORY_MarkCountryVisited; that
 * call's answer decides whether WIFI_HISTORY_IncrementVisitedCountryCount runs.
 */
void COMM_HISTORY_StoreAndNotify(struct HistoryOwner *owner, struct HistoryEntry *entry, u32 mark)
{
    struct HistoryEntry *table = WIFI_HISTORY_GetEntries((struct WifiHistory *)owner);
    u32 key;

    COMM_HISTORY_StoreAt(table, entry, mark);

    key = MYSTATUS_GetNation((struct MyStatus *)(&entry->record));
    if (WIFI_HISTORY_MarkCountryVisited((struct WifiHistory *)owner, key) != 0)
        WIFI_HISTORY_IncrementVisitedCountryCount((struct WifiHistory *)owner);
}

/*
 * Stores the entry at the first free index of the table (COMM_HISTORY_CountLeadingOccupied),
 * after setting the bit-3 mark from `mark` and the bit-4 occupied flag.
 */
void COMM_HISTORY_StoreAt(struct HistoryEntry *table, struct HistoryEntry *entry, u32 mark)
{
    u32 index = COMM_HISTORY_CountLeadingOccupied(table);

    if (index >= 0x14)
        return;

    if (mark != 0)
        entry->isMarked = 1;
    else
        entry->isMarked = 0;

    entry->isOccupied = 1;

    table[index] = *entry;
}

/* Maps value into the band [rangeStart+margin/2, rangeEnd-margin/2]: 0 below it and maxValue above it. */
u32 SCROLLBAR_GetValueFromPos(u32 maxValue, u32 value, u32 rangeStart, u32 rangeEnd, u32 margin)
{
    u32 halfMargin  = margin >> 1;
    u32 low = rangeStart + halfMargin;
    u32 high = rangeEnd - halfMargin;
    u32 offset;

    if (value <= low)
        return 0;
    if (value >= high)
        return maxValue;

    offset = value - low;
    return (offset * (maxValue << 8) / (high - low)) >> 8;
}

/*
 * A scaled-span helper: the span (end - start - margin) is raised eight
 * bits, scaled by the rate, divided by the total and shifted back down; the
 * quotient joins start and half of margin.
 *
 * The quotient `scaled` is kept in its own local: the image shifts it
 * into r2 right after the divide, then re-reads `margin`.  With
 * propagation on, mwcc moves the shift into the return expression and
 * reads `margin` first; `opt_propagation off` keeps the statement order.
 * The sum associates as `(start + scaled) + (margin >> 1)`: the other
 * order swaps the operands of the two `adds`.
 */
#pragma opt_propagation off

u32 SCROLLBAR_GetPosFromValue(u32 total, u32 rate, u32 start, u32 end, u32 margin)
{
    u32 span = ((end - start) - margin) << 8;
    u32 scaled = span * rate / total >> 8;

    return (start + scaled) + (margin >> 1);
}

#pragma opt_propagation reset
