/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F38AC, func_021F38F4, func_021F3934, func_021F394C, func_021F395C, func_021F3980
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
 *   func_0203F4E4  0x0203F4E4  arm
 *   func_021F3980  0x021F3980  thumb  ov036
 *   d_021F3AD4     0x021F3AD4  data  a4
 *   d_021F3B4C     0x021F3B4C  data  a4
 *   d_021F3A98     0x021F3A98  data  a4
 *   d_021F3BEC     0x021F3BEC  data  a4
 *   func_020056EC 0x020056EC thumb
 *   d_021F3A7C     0x021F3A7C  data  a1
 *   d_021F3A82     0x021F3A82  data  a1
 *   d_021F3A90     0x021F3A90  data  a1
 */
struct RtcDate;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
} RTCDate;

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

/* The 15 cells of the daily layout, filled by func_021F36C0. */
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

extern void func_0203F4E4(struct RtcDate *date);
extern int func_021F3980(CellDeck *deck);
extern u32 func_020056EC(u32 range);
void func_021F36C0(DailyLayoutWork *work);
void func_021F38AC(int poolSize, int pickCount, unsigned char *scratch, unsigned char *picks);
void func_021F38F4(CellDeck *deck);
int func_021F3934(CellDeck *deck, int cell);
int func_021F394C(CellDeck *deck, int poolIdx);
int func_021F395C(CellDeck *deck, int poolIdx);
extern const CellFlags d_021F3AD4[];
extern const MainEntryDef d_021F3B4C[];
extern const ExtraEntryDef d_021F3A98[];
extern const ExtraEntryDef d_021F3BEC[];


/*
 * Builds the daily layout: the number of main entries depends on the weekday,
 * then cells are dealt and each category gets its entries on its cells.
 */
void func_021F36C0(DailyLayoutWork *work)
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

    func_0203F4E4((struct RtcDate *)(&date));
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
    func_021F38F4(&deck);
    if (func_021F3980(&deck) == 0)
        func_021F38F4(&deck);
    func_021F38AC(10, mainCount, mainScratch, deck.mainPick);
    func_021F38AC(5, 2, bonusScratch, deck.bonusPick);
    func_021F38AC(15, 15 - (mainCount + 2), fillerScratch, deck.fillerPick);
    for (i = 0; i < mainCount; i++) {
        cell = deck.dealt[i];
        if (d_021F3AD4[cell].flagA == 0)
            work->flagAZeroCount++;
        else
            work->flagAOneCount++;
        if (d_021F3AD4[cell].flagB == 0)
            work->flagBZeroCount++;
        else
            work->flagBOneCount++;
    }
    dealtIdx = 0;
    for (i = 0; i < mainCount; i++) {
        entryCell = deck.dealt[dealtIdx];
        pick = deck.mainPick[i];
        work->entry[entryCell].slotId = pick;
        work->entry[entryCell].subId = d_021F3B4C[pick].subId;
        work->entry[entryCell].valueA = d_021F3B4C[pick].valueA;
        work->entry[entryCell].category = 0;
        work->entry[entryCell].valueC = d_021F3B4C[pick].valueC;
        work->entry[entryCell].valueD = d_021F3B4C[pick].valueD;
        dealtIdx++;
    }
    for (i = 0; i < 2; i++) {
        entryCell = deck.dealt[dealtIdx];
        pick = deck.bonusPick[i];
        work->entry[entryCell].slotId = i;
        work->entry[entryCell].subId = 0;
        work->entry[entryCell].valueA = d_021F3A98[pick].valueA;
        work->entry[entryCell].category = 2;
        work->entry[entryCell].valueC = d_021F3A98[pick].valueC;
        work->entry[entryCell].valueD = d_021F3A98[pick].valueD;
        dealtIdx++;
    }
    fillerCount = 15u - (mainCount + 2);
    for (i = 0; i < fillerCount; i++) {
        entryCell = deck.dealt[dealtIdx];
        pick = deck.fillerPick[i];
        work->entry[entryCell].slotId = i;
        work->entry[entryCell].subId = 0;
        work->entry[entryCell].valueA = d_021F3BEC[pick].valueA;
        work->entry[entryCell].category = 1;
        work->entry[entryCell].valueC = d_021F3BEC[pick].valueC;
        work->entry[entryCell].valueD = d_021F3BEC[pick].valueD;
        dealtIdx++;
    }
}


/* Picks pickCount distinct values out of 0..poolSize-1 into picks, without repeats. */
void func_021F38AC(int poolSize, int pickCount, unsigned char *scratch, unsigned char *picks)
{
    unsigned char i;
    unsigned char pickIdx;
    unsigned char rolled;

    for (i = 0; i < poolSize; i++)
        scratch[i] = i;
    for (pickIdx = 0; pickIdx < pickCount; pickIdx++) {
        rolled = func_020056EC(poolSize);
        picks[pickIdx] = scratch[rolled];
        scratch[rolled] = scratch[poolSize - 1];
        poolSize--;
    }
}

/* Resets the deck: all 15 cells in the pool, nothing dealt, identity picks. */
void func_021F38F4(CellDeck *deck)
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
int func_021F3934(CellDeck *deck, int cell)
{
    int i;
    for (i = 0; i < 15; i++) {
        if (deck->pool[i] == cell) return i;
    }
    return -1;
}

/* Cell at the pool index, or -1 past the end. */
int func_021F394C(CellDeck *deck, int poolIdx)
{
    if (poolIdx > deck->poolLast) return -1;
    return deck->pool[poolIdx];
}

/* Removes the pool entry by moving the last one into its place. */
int func_021F395C(CellDeck *deck, int poolIdx)
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

typedef enum { K_021F3980 } KType_021F3980;

extern u8 d_021F3A7C[];
extern u8 d_021F3A82[];
extern u8 d_021F3A90[];

/*
 * Deals all 15 cells: one anchor cell first, then one companion cell for the
 * half the anchor does not cover, then the rest in random order.  Returns 0
 * when a pool operation fails.
 */
int func_021F3980(CellDeck *deck)
{
    int hasFlagA;
    int hasFlagB;
    int anchorIdx;
    int cell;
    int remaining;
    KType_021F3980 poolSize;
    int i;
    int rolled;
    int picked;

    hasFlagA = 0;
    hasFlagB = 0;
    anchorIdx = func_020056EC(6);
    cell = d_021F3A7C[anchorIdx];
    if (func_021F395C(deck, func_021F3934(deck, cell)) == 0)
        return hasFlagA;
    (deck->dealt)[deck->dealtCount] = cell;
    deck->dealtCount++;
    poolSize = 15;
    remaining = poolSize - 1;
    if (d_021F3AD4[anchorIdx].flagA == 0)
        hasFlagA = 1;
    else
        hasFlagB = 1;
    if (hasFlagB == 0 || hasFlagA == 0) {
        if (hasFlagB == 0)
            cell = d_021F3A82[func_020056EC(7)];
        else
            cell = d_021F3A90[func_020056EC(8)];
        if (func_021F395C(deck, func_021F3934(deck, cell)) == 0)
            return 0;
        remaining--;
        (deck->dealt)[deck->dealtCount] = cell;
        deck->dealtCount++;
    }
    for (i = 0; i < remaining; i++) {
        rolled = func_020056EC(remaining - i);
        picked = func_021F394C(deck, rolled);
        if (picked < 0)
            return 0;
        if (func_021F395C(deck, rolled) == 0)
            return 0;
        (deck->dealt)[deck->dealtCount] = picked;
        deck->dealtCount++;
    }
    return 1;
}
