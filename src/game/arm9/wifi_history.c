/*
 * file:     wifi_history.c
 * unit:     yes
 * function: WIFI_HISTORY_GetBlock, WIFI_HISTORY_InitLanguageRegion, WIFI_HISTORY_GetCountryRegionState, WIFI_HISTORY_SetCountryRegionState, WIFI_HISTORY_GetMode, WIFI_HISTORY_PromoteVisitedStates, WIFI_HISTORY_GetVisitedCountryCount, WIFI_HISTORY_GetDisplayCount, WIFI_HISTORY_GetFirstFreeEntry, WIFI_HISTORY_IncrementVisitedCountryCount, WIFI_HISTORY_SetRatingLevel, WIFI_HISTORY_GetRatingLevel, WIFI_HISTORY_SetGreetingSet, WIFI_HISTORY_GetGreetingSet, WIFI_HISTORY_GetEntryField, WIFI_HISTORY_SetEntryField, WIFI_HISTORY_GetEntry, WIFI_HISTORY_GetEntries, WIFI_HISTORY_MarkCountryVisited, WIFI_HISTORY_IsCountryVisited
 * address:  0x02009470
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from wifilist.c by tools/splitfile.py.
 *
 * symbols:
 *   MYSTATUS_SetNationAndArea  0x02008574  thumb
 *   SAVE_CONTROL_GetBlock    0x020071CC  thumb
 *   WIFI_HISTORY_GetVisitedCountryCount  0x02009584  thumb
 *   WIFI_HISTORY_IsCountryVisited  0x02009794  thumb
 *   MYSTATUS_GetNation  0x0200856C  thumb
 */
#include "game_sync_shared_types.h"
#include "wifi_history_shared_types.h"
#include "../version.h"

#define WIFI_HISTORY_BLOCK_ID 0x1D

#define WIFI_HISTORY_ENTRY_MAX 20

#define WIFI_HISTORY_COUNTRY_MAX 0xE9

#include "comm_player_support_shared_types.h"


/*
 * Save block 0x1D (0x1338 bytes): the Wi-Fi history. 20 entries, a bit per
 * country (1..232) and a grid of 2-bit states indexed by country and region.
 */
struct WifiHistory {
    struct HistoryEntry entries[WIFI_HISTORY_ENTRY_MAX];    /* 0x000 */
    u8 visitedCountryBits[0x1D];                            /* 0x320 */
    u8 reserved33D[7];
    u8 mode;                        /* 0x344 */
    u8 visitedCountryCount;         /* 0x345, saturates at 0xE9 */
    u8 greetingSet;                 /* 0x346, set only below 9 */
    u8 ratingLevel;                 /* 0x347, set only below 5 */
    u8 countryRegionState[0xFF0];   /* 0x348, 16 bytes per country row */
};

#include "save_control.h"

#include "mystatus.h"

extern u8 WIFI_HISTORY_GetVisitedCountryCount(const struct WifiHistory *history);


extern u32 WIFI_HISTORY_IsCountryVisited(const struct WifiHistory *history, u32 country);

struct WifiHistory *WIFI_HISTORY_GetBlock(struct SaveControl *saveControl);

void WIFI_HISTORY_InitLanguageRegion(struct WifiHistory *history, struct MyStatus *status, u8 country, u8 region);

u32 WIFI_HISTORY_GetCountryRegionState(const struct WifiHistory *history, int country, int region);

void WIFI_HISTORY_SetCountryRegionState(struct WifiHistory *history, int country, int region, int state);

u8 WIFI_HISTORY_GetMode(const struct WifiHistory *history);

#if LANGUAGE == LANGUAGE_JAPANESE
void WIFI_HISTORY_SetMode(struct WifiHistory *history, u8 mode);
#endif

void WIFI_HISTORY_PromoteVisitedStates(struct WifiHistory *history);

u8 WIFI_HISTORY_GetDisplayCount(struct WifiHistory *history, struct MyStatus *status, int flag);

u8 WIFI_HISTORY_GetFirstFreeEntry(const struct WifiHistory *history);

void WIFI_HISTORY_IncrementVisitedCountryCount(struct WifiHistory *history);

void WIFI_HISTORY_SetRatingLevel(struct WifiHistory *history, int value);

u8 WIFI_HISTORY_GetRatingLevel(const struct WifiHistory *history);

void WIFI_HISTORY_SetGreetingSet(struct WifiHistory *history, int value);

u8 WIFI_HISTORY_GetGreetingSet(const struct WifiHistory *history);

u32 WIFI_HISTORY_GetEntryField(const struct WifiHistory *history, u32 index, u32 field);

void WIFI_HISTORY_SetEntryField(struct WifiHistory *history, int index, u32 field, u32 value);

struct HistoryEntry *WIFI_HISTORY_GetEntry(struct WifiHistory *history, int index);

struct HistoryEntry *WIFI_HISTORY_GetEntries(struct WifiHistory *history);

u32 WIFI_HISTORY_MarkCountryVisited(struct WifiHistory *history, u32 country);


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           WIFI_HISTORY_GetMode, WIFI_HISTORY_PromoteVisitedStates, WIFI_HISTORY_GetVisitedCountryCount
 *
 * alias: the save block with id 0x1D.  Its bulk is a 0xFF0-byte array of
 * two-bit fields at +0x348, sixteen bytes (sixty-four fields) per row, and
 * every function here is an access into it.
 *
 * The index arithmetic is the same five instructions in the getter and the
 * setter: `b / 4` is the signed divide-by-four `asrs #1` / `lsrs #30` / `adds`
 * / `asrs #2`, and `b % 4` is the `lsrs #31` / `lsls #30` / `subs` / `rors #30`
 * / `adds` sequence.  Both are signed, so the column index is a signed `int`;
 * `& 3` and `>> 2` would each be one instruction and are not what is there.
 * The row term is added second, `b / 4 + (a - 1) * 16`, which is the operand
 * order of the `adds`.
 *
 * WIFI_HISTORY_SetCountryRegionState clears and sets in two separate read-modify-writes with a
 * `ldrb` in each, because the destination is a `u8` array element rather than
 * a bitfield.  Two spellings are load bearing there.  The mask is `0xFF ^
 * (3 << sh)` and not `~(3 << sh)`: the second gives a single `mvns`, two bytes
 * shorter, and the whole file after it shifts.  And the element is reached
 * through a pointer computed once, `u8 *cell = &history->countryRegionState[i]`, not through an
 * index into the array: with the index spelling the compiler evaluates the
 * column modulo before the base address and twenty-four bytes are in the wrong
 * order with every register renumbered.
 *
 * NEAR MISS, 0x02009590, 56 bytes, 2 bytes wrong, skipped.  It is
 *
 *   u8 WIFI_HISTORY_GetDisplayCount(const struct WifiHistory *history,
 *                   const struct MyStatus *status, int flag)
 *   {
 *       u8 v = WIFI_HISTORY_GetVisitedCountryCount(history);
 *
 *       if (flag == 0) {
 *           u8 t = MYSTATUS_GetNation(status);
 *
 *           if (t == 0) {
 *               v = 0;
 *           } else if (WIFI_HISTORY_IsCountryVisited(history) != 0 && v != 0) {
 *               v = v - 1;
 *           }
 *       }
 *       return v;
 *   }
 *
 * which reproduces 54 of its 56 bytes: same size, same schedule, same branch
 * targets.  The one instruction that differs is the test of the second call's
 * result, where the original has `adds r1, r0, #0` (a register move that sets
 * the flags) and every spelling tried gives `cmp r0, #0`.  Twenty-seven source
 * shapes were swept: six types for the temporary crossed with `== 0` and `!`,
 * the nested and the else-if arm shapes, early returns instead of the common
 * exit, a second temporary, reassigning each of the three parameters instead
 * of declaring a local, and a fourth dead parameter.  All of them are exactly
 * these two bytes out and nothing else moves, so this is register allocation
 * of a dead temporary and not a shape the source can state.
 *
 * WIFI_HISTORY_PromoteVisitedStates is the same field written as a rewrite pass: for every one of
 * the 0xFF0 bytes it walks the four fields and turns every 1 into a 2, keeping
 * the byte in a register across the inner loop and storing it once.  The four
 * constants it needs are hoisted out of both loops, 3 twice because one is the
 * read mask and the other the shift base.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009470.c \
 *       --addr 0x02009470 --thumb
 */
struct WifiHistory *WIFI_HISTORY_GetBlock(struct SaveControl *saveControl)
{
    return SAVE_CONTROL_GetBlock(saveControl, WIFI_HISTORY_BLOCK_ID);
}

void WIFI_HISTORY_InitLanguageRegion(struct WifiHistory *history, struct MyStatus *status,
                  u8 country, u8 region)
{
    MYSTATUS_SetNationAndArea(status, country, region);
    WIFI_HISTORY_SetCountryRegionState(history, country, region, 3);
}

u32 WIFI_HISTORY_GetCountryRegionState(const struct WifiHistory *history, int country, int region)
{
    if (country == 0) {
        return 0;
    }
    return (history->countryRegionState[region / 4 + (country - 1) * 16] >> ((region % 4) * 2)) & 3;
}

void WIFI_HISTORY_SetCountryRegionState(struct WifiHistory *history, int country, int region, int state)
{
    u8 *cell;
    int shift;

    if (country == 0) {
        return;
    }
    cell = &history->countryRegionState[region / 4 + (country - 1) * 16];
    shift = (region % 4) * 2;
    *cell &= 0xFF ^ (3 << shift);
    *cell |= state << shift;
#if LANGUAGE == LANGUAGE_JAPANESE
    if (country != 0x69) {
        WIFI_HISTORY_SetMode(history, 1);
    }
#endif
}

u8 WIFI_HISTORY_GetMode(const struct WifiHistory *history)
{
    return history->mode;
}

#if LANGUAGE == LANGUAGE_JAPANESE
void WIFI_HISTORY_SetMode(struct WifiHistory *history, u8 mode)
{
    history->mode = mode;
}
#endif

void WIFI_HISTORY_PromoteVisitedStates(struct WifiHistory *history)
{
    int byteIndex;
    int shift;
    u8 cells;

    for (byteIndex = 0; byteIndex < 0xFF0; byteIndex++) {
        cells = history->countryRegionState[byteIndex];
        for (shift = 0; shift < 8; shift += 2) {
            if (((cells >> shift) & 3) == 1) {
                cells &= 0xFF ^ (3 << shift);
                cells |= 2 << shift;
            }
        }
        history->countryRegionState[byteIndex] = cells;
    }
}

u8 WIFI_HISTORY_GetVisitedCountryCount(const struct WifiHistory *history)
{
    return history->visitedCountryCount;
}

/*
 * Checks mode and validity flags, adjusting count when active.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009590.c \
 *       --addr 0x02009590 --thumb
 */
u8 WIFI_HISTORY_GetDisplayCount(struct WifiHistory *history, struct MyStatus *status, int flag)
{
    u8 count = WIFI_HISTORY_GetVisitedCountryCount(history);

    if (flag == 0) {
        int country = MYSTATUS_GetNation(status);
        if (country == 0) {
            count = 0;
        } else if (WIFI_HISTORY_IsCountryVisited(history, country) && count != 0) {
            count--;
        }
    }

    return count;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           WIFI_HISTORY_SetGreetingSet, WIFI_HISTORY_GetGreetingSet, WIFI_HISTORY_GetEntryField, WIFI_HISTORY_SetEntryField,
 *           WIFI_HISTORY_GetEntry, WIFI_HISTORY_GetEntries, WIFI_HISTORY_MarkCountryVisited, WIFI_HISTORY_IsCountryVisited
 *
 * alias: the rest of the save block with id 0x1D whose first half is
 * src/matched/unit_02009470.c.  This half is the twenty 0x28-byte records at
 * the front of the block, the 0xE9-bit flag array at +0x320, and the four
 * scalars at +0x344..+0x347 that sit between them.
 *
 * WIFI_HISTORY_GetEntryField and WIFI_HISTORY_SetEntryField are the getter and the setter over the record
 * fields, both dispatched through a PC-relative halfword table; see
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.  The two tables
 * are the interesting part, because they disagree.  The getter's seven entries
 * all point at real bodies, so the source has `case 0` through `case 6`.  The
 * setter's first four point at the function's exit, and those four are still
 * case labels in the source: with only `case 4`, `case 5` and `case 6` this
 * compiler abandons the table and emits a three-way `cmp` / `beq` chain, eight
 * bytes longer and a completely different function.  Four empty arms in front
 * of the real ones are what bring the table back.  See
 * docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *
 * The setter also has to reach the record through a pointer,
 * `entry = &history->entries[i]`, while the getter's `history->entries[i].field` spelling
 * would do: written with the index in each arm the multiply by 0x28 is
 * recomputed inside every case instead of being hoisted in front of the
 * switch, and seventy bytes move.
 *
 * The record's byte at +0x26 is three fields, and the getter is the only place
 * that says so: `lsls #0x1D` / `lsrs #0x1D` for the low three bits, then
 * `lsls #0x1C` / `lsrs #0x1F` and `lsls #0x1B` / `lsrs #0x1F` for the two bits
 * above them.  The setter writes the three-bit field as one masked assignment
 * and the two single bits as `orrs #8` / `bics #8` and `orrs #0x10` /
 * `bics #0x10`, which is an `if (value) f = 1; else f = 0;` on a one-bit
 * bitfield and not an assignment of the value itself.
 *
 * The index bound is checked unsigned in the getter (`blo`) and signed in the
 * setter and in WIFI_HISTORY_GetEntry (`bge`, `blt`), so the three functions do not
 * agree about the type of their index and the source says so.
 *
 * WIFI_HISTORY_MarkCountryVisited seeds its result from a literal pool word holding zero rather
 * than from a `movs`, which costs four bytes and is what the compiler does
 * here for a value initialised before a conditional; the `bne` that follows
 * reads the flags of the `adds r5, r1, #0` that moved the argument, so there
 * is no `cmp` for the first test at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020095C8.c \
 *       --addr 0x020095C8 --thumb
 */
u8 WIFI_HISTORY_GetFirstFreeEntry(const struct WifiHistory *history)
{
    int i;

    for (i = 0; i < WIFI_HISTORY_ENTRY_MAX; i++) {
        if (history->entries[i].isOccupied == 0) {
            break;
        }
    }
    return i;
}

void WIFI_HISTORY_IncrementVisitedCountryCount(struct WifiHistory *history)
{
    if (history->visitedCountryCount < WIFI_HISTORY_COUNTRY_MAX) {
        history->visitedCountryCount++;
    }
}

void WIFI_HISTORY_SetRatingLevel(struct WifiHistory *history, int value)
{
    if (value < 5) {
        history->ratingLevel = value;
    }
}

u8 WIFI_HISTORY_GetRatingLevel(const struct WifiHistory *history)
{
    return history->ratingLevel;
}

void WIFI_HISTORY_SetGreetingSet(struct WifiHistory *history, int value)
{
    if (value < 9) {
        history->greetingSet = value;
    }
}

u8 WIFI_HISTORY_GetGreetingSet(const struct WifiHistory *history)
{
    return history->greetingSet;
}

u32 WIFI_HISTORY_GetEntryField(const struct WifiHistory *history, u32 index, u32 field)
{
    const struct HistoryEntry *entry;

    if (index >= WIFI_HISTORY_ENTRY_MAX) {
        return 0;
    }
    entry = &history->entries[index];
    switch (field) {
    case 0:
        return entry->meetCount;
    case 1:
        return entry->swapCount;
    case 2:
        return entry->rank;
    case 3:
        return entry->score;
    case 4:
        return entry->greeting;
    case 5:
        return entry->isMarked;
    case 6:
        return entry->isOccupied;
    }
    return 0;
}

void WIFI_HISTORY_SetEntryField(struct WifiHistory *history, int index, u32 field, u32 value)
{
    struct HistoryEntry *entry;

    if (index >= WIFI_HISTORY_ENTRY_MAX) {
        return;
    }
    entry = &history->entries[index];
    switch (field) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        if (value < 5) {
            entry->greeting = value;
        }
        break;
    case 5:
        if (value) {
            entry->isMarked = 1;
        } else {
            entry->isMarked = 0;
        }
        break;
    case 6:
        if (value) {
            entry->isOccupied = 1;
        } else {
            entry->isOccupied = 0;
        }
        break;
    }
}

struct HistoryEntry *WIFI_HISTORY_GetEntry(struct WifiHistory *history, int index)
{
    if (index >= WIFI_HISTORY_ENTRY_MAX) {
        return 0;
    }
    return &history->entries[index];
}

struct HistoryEntry *WIFI_HISTORY_GetEntries(struct WifiHistory *history)
{
    return (struct HistoryEntry *)history;
}

u32 WIFI_HISTORY_MarkCountryVisited(struct WifiHistory *history, u32 country)
{
    u32 isNew = 0;

    if (country == 0) {
        return isNew;
    }
    if (country < WIFI_HISTORY_COUNTRY_MAX) {
        if (WIFI_HISTORY_IsCountryVisited(history, country) == 0) {
            isNew = 1;
        }
        history->visitedCountryBits[country >> 3] |= (u8)(1 << (u8)(country & 7));
    }
    return isNew;
}

u32 WIFI_HISTORY_IsCountryVisited(const struct WifiHistory *history, u32 country)
{
    if (country < WIFI_HISTORY_COUNTRY_MAX) {
        u8 bit = (history->visitedCountryBits[country >> 3] >> (u8)(country & 7)) & 1;

        if (bit != 0) {
            return 1;
        }
    }
    return 0;
}
