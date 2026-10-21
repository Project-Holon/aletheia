/*
 * file:     daily_layout.c
 * unit:     yes
 * function: DAILY_LAYOUT_Generate, DAILY_LAYOUT_PickDistinct, DAILY_LAYOUT_ResetDeck, DAILY_LAYOUT_FindPoolCell, DAILY_LAYOUT_GetPoolCell, DAILY_LAYOUT_RemovePoolCell, DAILY_LAYOUT_DealCells
 * address:  0x021F36C0
 * region:   ov036
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GF_STANDARD_GetCachedDate  0x0203F4E4  arm
 *   DAILY_LAYOUT_DealCells  0x021F3980  thumb  ov036
 *   gDailyLayoutCellFlags     0x021F3AD4  data  a4
 *   gDailyLayoutMainDefs     0x021F3B4C  data  a4
 *   gDailyLayoutBonusDefs     0x021F3A98  data  a4
 *   gDailyLayoutFillerDefs     0x021F3BEC  data  a4
 *   GFL_USE_GetRandom 0x020056EC thumb
 *   gDailyLayoutAnchorCells     0x021F3A7C  data  a1
 *   gDailyLayoutCompanionCellsA     0x021F3A82  data  a1
 *   gDailyLayoutCompanionCellsB     0x021F3A90  data  a1
 */
#include "../sdk_rtc.h"
#include "../types.h"

#include "../sdk_rtc.h"

/*
 * Cell deal: pool of the 15 cells not dealt yet (poolLast is the index of the
 * last valid pool entry), the order in which cells were dealt, and the picks
 * made for the three entry categories.
 */
typedef struct CellDeck {
    u8 pool[15];
    u8 dealt[15];
    u8 dealtCount;
    u8 poolLast;
    u8 mainPick[7];
    u8 bonusPick[2];
    u8 fillerPick[10];
} CellDeck;

typedef struct DailyLayoutEntry {
    int slotId;
    int subId;
    int valueA;
    int category;       /* 0 main, 1 filler, 2 bonus */
    int valueC;
    int valueD;
    int unusedE;
} DailyLayoutEntry;

/* The 15 cells of the daily layout, filled by DAILY_LAYOUT_Generate. */
typedef struct DailyLayoutWork {
    u8 reserved0[6];
    u16 mainCount;
    u8 reserved8[4];
    DailyLayoutEntry entry[15];
    u8 flagAZeroCount;
    u8 flagAOneCount;
    u8 flagBZeroCount;
    u8 flagBOneCount;
} DailyLayoutWork;

typedef struct CellFlags {
    int flagA;
    int flagB;
} CellFlags;

typedef struct MainEntryDef {
    int valueA;
    int subId;
    int valueC;
    int valueD;
} MainEntryDef;

typedef struct ExtraEntryDef {
    int valueA;
    int valueC;
    int valueD;
} ExtraEntryDef;

#include "../arm9/gf_standard.h"
extern int DAILY_LAYOUT_DealCells(CellDeck *deck);
#include "../arm9/gfl_use.h"
void DAILY_LAYOUT_Generate(DailyLayoutWork *work);
void DAILY_LAYOUT_PickDistinct(int poolSize, int pickCount, unsigned char *scratch, unsigned char *picks);
void DAILY_LAYOUT_ResetDeck(CellDeck *deck);
int DAILY_LAYOUT_FindPoolCell(CellDeck *deck, int cell);
int DAILY_LAYOUT_GetPoolCell(CellDeck *deck, int poolIdx);
int DAILY_LAYOUT_RemovePoolCell(CellDeck *deck, int poolIdx);
extern const CellFlags gDailyLayoutCellFlags[];
extern const MainEntryDef gDailyLayoutMainDefs[];
extern const ExtraEntryDef gDailyLayoutBonusDefs[];
extern const ExtraEntryDef gDailyLayoutFillerDefs[];

/*
 * Builds the daily layout: the number of main entries depends on the weekday,
 * then cells are dealt and each category gets its entries on its cells.
 */
void DAILY_LAYOUT_Generate(DailyLayoutWork *work)
{
    RTCDate date;
    CellDeck deck;
    u8 mainScratch[10];
    u8 fillerScratch[15];
    u8 bonusScratch[5];
    int mainCount;
    u8 i;
    int dealtIdx;
    int fillerCount;
    u8 cell;
    u8 pick;
    u8 entryCell;

    GF_STANDARD_GetCachedDate((RTCDate *)(&date));
    switch (date.week) {
    case 1:
        mainCount = 4;
        break;
    case 2:
        mainCount = 3;
        break;
    case 3:
        mainCount = 4;
        break;
    case 4:
        mainCount = 5;
        break;
    case 5:
        mainCount = 4;
        break;
    case 6:
        mainCount = 6;
        break;
    case 0:
        mainCount = 7;
        break;
    default:
        mainCount = 0;
        break;
    }
    work->mainCount = mainCount;
    DAILY_LAYOUT_ResetDeck(&deck);
    if (DAILY_LAYOUT_DealCells(&deck) == 0)
        DAILY_LAYOUT_ResetDeck(&deck);
    DAILY_LAYOUT_PickDistinct(10, mainCount, mainScratch, deck.mainPick);
    DAILY_LAYOUT_PickDistinct(5, 2, bonusScratch, deck.bonusPick);
    DAILY_LAYOUT_PickDistinct(15, 15 - (mainCount + 2), fillerScratch, deck.fillerPick);
    for (i = 0; i < mainCount; i++) {
        cell = deck.dealt[i];
        if (gDailyLayoutCellFlags[cell].flagA == 0)
            work->flagAZeroCount++;
        else
            work->flagAOneCount++;
        if (gDailyLayoutCellFlags[cell].flagB == 0)
            work->flagBZeroCount++;
        else
            work->flagBOneCount++;
    }
    dealtIdx = 0;
    for (i = 0; i < mainCount; i++) {
        entryCell = deck.dealt[dealtIdx];
        pick = deck.mainPick[i];
        work->entry[entryCell].slotId = pick;
        work->entry[entryCell].subId = gDailyLayoutMainDefs[pick].subId;
        work->entry[entryCell].valueA = gDailyLayoutMainDefs[pick].valueA;
        work->entry[entryCell].category = 0;
        work->entry[entryCell].valueC = gDailyLayoutMainDefs[pick].valueC;
        work->entry[entryCell].valueD = gDailyLayoutMainDefs[pick].valueD;
        dealtIdx++;
    }
    for (i = 0; i < 2; i++) {
        entryCell = deck.dealt[dealtIdx];
        pick = deck.bonusPick[i];
        work->entry[entryCell].slotId = i;
        work->entry[entryCell].subId = 0;
        work->entry[entryCell].valueA = gDailyLayoutBonusDefs[pick].valueA;
        work->entry[entryCell].category = 2;
        work->entry[entryCell].valueC = gDailyLayoutBonusDefs[pick].valueC;
        work->entry[entryCell].valueD = gDailyLayoutBonusDefs[pick].valueD;
        dealtIdx++;
    }
    fillerCount = 15u - (mainCount + 2);
    for (i = 0; i < fillerCount; i++) {
        entryCell = deck.dealt[dealtIdx];
        pick = deck.fillerPick[i];
        work->entry[entryCell].slotId = i;
        work->entry[entryCell].subId = 0;
        work->entry[entryCell].valueA = gDailyLayoutFillerDefs[pick].valueA;
        work->entry[entryCell].category = 1;
        work->entry[entryCell].valueC = gDailyLayoutFillerDefs[pick].valueC;
        work->entry[entryCell].valueD = gDailyLayoutFillerDefs[pick].valueD;
        dealtIdx++;
    }
}

/* Picks pickCount distinct values out of 0..poolSize-1 into picks, without repeats. */
void DAILY_LAYOUT_PickDistinct(int poolSize, int pickCount, unsigned char *scratch, unsigned char *picks)
{
    unsigned char i;
    unsigned char pickIdx;
    unsigned char rolled;

    for (i = 0; i < poolSize; i++)
        scratch[i] = i;
    for (pickIdx = 0; pickIdx < pickCount; pickIdx++) {
        rolled = GFL_USE_GetRandom(poolSize);
        picks[pickIdx] = scratch[rolled];
        scratch[rolled] = scratch[poolSize - 1];
        poolSize--;
    }
}

/* Resets the deck: all 15 cells in the pool, nothing dealt, identity picks. */
void DAILY_LAYOUT_ResetDeck(CellDeck *deck)
{
    int i;
    int j;

    deck->poolLast = 14;
    deck->dealtCount = 0;
    for (i = 0; i < 15; i++) {
        deck->pool[i] = i;
        deck->dealt[i] = 0;
    }
    for (j = 0; j < 7; j++)
        deck->mainPick[j] = j;
    for (i = 0; i < 2; i++)
        deck->bonusPick[i] = i;
    for (i = 0; i < 10; i++)
        deck->fillerPick[i] = i;
}

/* Index of the cell in the pool, or -1. */
int DAILY_LAYOUT_FindPoolCell(CellDeck *deck, int cell)
{
    int i;
    for (i = 0; i < 15; i++) {
        if (deck->pool[i] == cell) return i;
    }
    return -1;
}

/* Cell at the pool index, or -1 past the end. */
int DAILY_LAYOUT_GetPoolCell(CellDeck *deck, int poolIdx)
{
    if (poolIdx > deck->poolLast) return -1;
    return deck->pool[poolIdx];
}

/* Removes the pool entry by moving the last one into its place. */
int DAILY_LAYOUT_RemovePoolCell(CellDeck *deck, int poolIdx)
{
    if (poolIdx > deck->poolLast)
        return 0;
    if (poolIdx < 0)
        return 0;
    deck->pool[poolIdx] = deck->pool[deck->poolLast];
    if (deck->poolLast != 0)
        deck->poolLast = deck->poolLast - 1;
    return 1;
}

typedef enum { DAILY_LAYOUT_POOL_SIZE_NONE } DailyLayoutPoolSize;

extern u8 gDailyLayoutAnchorCells[];
extern u8 gDailyLayoutCompanionCellsA[];
extern u8 gDailyLayoutCompanionCellsB[];

/*
 * Deals all 15 cells: one anchor cell first, then one companion cell for the
 * half the anchor does not cover, then the rest in random order.  Returns 0
 * when a pool operation fails.
 */
int DAILY_LAYOUT_DealCells(CellDeck *deck)
{
    int hasFlagA;
    int hasFlagB;
    int anchorIdx;
    int cell;
    int remaining;
    DailyLayoutPoolSize poolSize;
    int i;
    int rolled;
    int picked;

    hasFlagA = 0;
    hasFlagB = 0;
    anchorIdx = GFL_USE_GetRandom(6);
    cell = gDailyLayoutAnchorCells[anchorIdx];
    if (DAILY_LAYOUT_RemovePoolCell(deck, DAILY_LAYOUT_FindPoolCell(deck, cell)) == 0)
        return hasFlagA;
    (deck->dealt)[deck->dealtCount] = cell;
    deck->dealtCount++;
    poolSize = 15;
    remaining = poolSize - 1;
    if (gDailyLayoutCellFlags[anchorIdx].flagA == 0)
        hasFlagA = 1;
    else
        hasFlagB = 1;
    if (hasFlagB == 0 || hasFlagA == 0) {
        if (hasFlagB == 0)
            cell = gDailyLayoutCompanionCellsA[GFL_USE_GetRandom(7)];
        else
            cell = gDailyLayoutCompanionCellsB[GFL_USE_GetRandom(8)];
        if (DAILY_LAYOUT_RemovePoolCell(deck, DAILY_LAYOUT_FindPoolCell(deck, cell)) == 0)
            return 0;
        remaining--;
        (deck->dealt)[deck->dealtCount] = cell;
        deck->dealtCount++;
    }
    for (i = 0; i < remaining; i++) {
        rolled = GFL_USE_GetRandom(remaining - i);
        picked = DAILY_LAYOUT_GetPoolCell(deck, rolled);
        if (picked < 0)
            return 0;
        if (DAILY_LAYOUT_RemovePoolCell(deck, rolled) == 0)
            return 0;
        (deck->dealt)[deck->dealtCount] = picked;
        deck->dealtCount++;
    }
    return 1;
}
