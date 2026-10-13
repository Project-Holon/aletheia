/*
 * file:     wifilist.c
 * unit:     yes
 * function: sub_02009448, sub_02009454, sub_0200945C, func_02009470, func_0200947C, func_0200949C, func_020094D8, func_0200952C, func_02009584, func_02009590, sub_020095C8, sub_020095E8, sub_020095FC, sub_0200960C,, WIFILIST_GetWorkSize, WIFILIST_Create, func_020097F0, func_02009800, func_02009860, func_02009864
 * address:  0x02009448
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   SAVE_CONTROL_GetBlock    0x020071CC  thumb
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_02009584  0x02009584  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02009794  0x02009794  thumb
 *   sWifilistFile  0x020A7198  data
 *   MI_CpuCopy8  0x02082D44  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   DWC_RAPCOMMON_InitUserData  0x02157138  thumb ov009
 *   ov_id_09       0x00000009  data
 *   ov_id_0A       0x0000000A  data
 *   ov_id_0B       0x0000000B  data
 *   ov_id_0D       0x0000000D  data
 *   DWC_IsValidFriendData 0x020596D8  arm
 *   STRBUF_SetStringN         0x02045994  arm
 *   STRBUF_ToChars         0x02045A38  arm
 *   MYSTATUS_SetLanguageAndVersion  0x02008574  thumb
 */
#define GAME_SYNC_BLOCK_ID 0x23
#define WIFI_HISTORY_BLOCK_ID 0x1D
#define WIFI_HISTORY_ENTRY_MAX 20
#define WIFI_HISTORY_COUNTRY_MAX 0xE9
#define WIFILIST_FRIEND_MAX 32

struct SaveControl;
struct MyStatus;
struct Strbuf;
struct U16Vec;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

/* Save block 0x23 (0x1338 bytes). This file only sizes, fetches and clears it. */
struct GameSyncData {
    u8 data[0x1338];
};

/* One player met over Wi-Fi: the player's MyStatus bytes. */
struct PlayerRecord {
    u8 data[0x20];
};

/* One slot of the 20-entry history table (0x28 bytes). */
struct HistoryEntry {
    struct PlayerRecord record;     /* 0x00 */
    u16 meetCount;                  /* 0x20 */
    u16 swapCount;                  /* 0x22 */
    u8  rank;                       /* 0x24 */
    u8  score;                      /* 0x25 */
    u8  greeting : 3;               /* 0x26, set only below 5 */
    u8  isMarked : 1;
    u8  isOccupied : 1;
    u8  : 3;
    u8  reserved27;                 /* 0x27 */
};

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

/* Save block 0x1E: the Wi-Fi friend list (same layout as in mystery_data.c). */
struct DWCFriendData {
    u8 data[0xC];
};

struct WifiFriendInfo {
    u8  nameData[0x1C];
    u32 trainerId;
    u32 profileId;
    u16 battleWins;
    u16 battleLosses;
    u16 tradeCount;
    u16 lastYear;
    u8  lastMonth;
    u8  lastDay;
    u8  language;
    u8  gender : 2;
    u8  statusFlags : 6;
};

struct WifiList {
    u8 userData[0x40];                                      /* DWC user data */
    struct DWCFriendData friendData[WIFILIST_FRIEND_MAX];   /* 0x040 */
    struct WifiFriendInfo friendInfo[WIFILIST_FRIEND_MAX];  /* 0x1C0 */
    u8 reserved[4];                                         /* 0x7C0 */
};

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *saveControl, u32 blockId);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern void MYSTATUS_SetLanguageAndVersion(struct MyStatus *status, u8 country, u8 region);
extern u8 func_02009584(const struct WifiHistory *history);
extern u8 func_0200856C(const struct MyStatus *status);
extern u32 func_02009794(const struct WifiHistory *history, u32 country);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern void func_02009800(struct WifiList *list);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MI_CpuFill8(void *dst, int val, unsigned n);
extern void func_02034A5C(int handle);
extern int func_02034AC4(int id);
extern void DWC_RAPCOMMON_InitUserData(void *p);
extern int  DWC_IsValidFriendData(const void *friendData);
extern void STRBUF_SetStringN(struct Strbuf *dest, const u16 *src, u32 size);
extern void STRBUF_ToChars(struct U16Vec *src, u16 *dest, u32 size);
struct GameSyncData *sub_02009448(struct SaveControl *saveControl);
u32 sub_02009454(void);
void sub_0200945C(struct GameSyncData *data);
struct WifiHistory *sub_02009470(struct SaveControl *saveControl);
void sub_0200947C(struct WifiHistory *history, struct MyStatus *status, u8 country, u8 region);
u32 sub_0200949C(const struct WifiHistory *history, int country, int region);
void sub_020094D8(struct WifiHistory *history, int country, int region, int state);
u8 sub_02009524(const struct WifiHistory *history);
void sub_0200952C(struct WifiHistory *history);
u8 sub_02009584(const struct WifiHistory *history);
u8 func_02009590(struct WifiHistory *history, struct MyStatus *status, int flag);
u8 sub_020095C8(const struct WifiHistory *history);
void sub_020095E8(struct WifiHistory *history);
void sub_020095FC(struct WifiHistory *history, int value);
u8 sub_0200960C(const struct WifiHistory *history);
void sub_02009618(struct WifiHistory *history, int value);
u8 sub_02009628(const struct WifiHistory *history);
u32 sub_02009634(const struct WifiHistory *history, u32 index, u32 field);
void sub_02009698(struct WifiHistory *history, int index, u32 field, u32 value);
struct HistoryEntry *sub_0200973C(struct WifiHistory *history, int index);
void sub_0200974C(void);
u32 sub_02009750(struct WifiHistory *history, u32 country);
u32 sub_02009794(const struct WifiHistory *history, u32 country);
u32 WIFILIST_GetWorkSize(void);
struct WifiList *WIFILIST_Create(int heapId);
void WIFILIST_Copy(const struct WifiList *src, struct WifiList *dest);
void WIFILIST_Init(struct WifiList *list);
struct WifiList *WIFILIST_GetWork(struct WifiList *list);
u32 WIFILIST_GetFriendInfoField(const struct WifiList *list, u32 index, u32 field);
void WIFILIST_SetFriendInfoField(struct WifiList *list, u32 index, u32 field, u32 value);
struct DWCFriendData *WIFILIST_GetDwcFriendData(struct WifiList *list, int index);
struct WifiFriendInfo *WIFILIST_GetFriendInfo(struct WifiList *list, int index);
void WIFILIST_CopyFriendNameToStrbuf(struct WifiList *list, int index, struct Strbuf *dest);
void WIFILIST_StoreFriendNameFromStrbuf(struct WifiList *list, int index, struct U16Vec *dest);
int WIFILIST_IsFriendDataValid(struct WifiList *list, u32 index);
extern char sWifilistFile[];
extern unsigned char ov_id_09[];
extern unsigned char ov_id_0A[];
extern unsigned char ov_id_0B[];
extern unsigned char ov_id_0D[];





static inline void MI_CpuClear32(void *dest, u32 size)
{
    MIi_CpuClear32(0, dest, size);
}





/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * alias: the whole of the save block with id 0x23, 0x1338 bytes: the getter,
 * the size and a constructor that clears it and does nothing else.  Three
 * functions, forty bytes, and not one of them carries a label.
 *
 * sub_02009454 is `ldr r0, [pc, #0]; bx lr` over its own pool word: 0x1338 is
 * past every Thumb immediate and past `movs` plus one `lsls`, so the constant
 * costs a word.  sub_0200945C loads the same constant into its own pool rather
 * than calling sub_02009454, so the source spells the size out in both, which
 * is what `sizeof` does.
 *
 * `MI_CpuClear32` is the SDK header's inline wrapper over MIi_CpuClear32 with
 * a zero fill value, and it is the last statement of a void function, so it
 * comes out as the pool word and `bx` of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md rather than as a `blx`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009448.c \
 *       --addr 0x02009448 --thumb
 */
struct GameSyncData *sub_02009448(struct SaveControl *saveControl)
{
    return SAVE_CONTROL_GetBlock(saveControl, GAME_SYNC_BLOCK_ID);
}





u32 sub_02009454(void)
{
    return sizeof(struct GameSyncData);
}





void sub_0200945C(struct GameSyncData *data)
{
    MI_CpuClear32(data, sizeof(struct GameSyncData));
}





/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02009524, sub_0200952C, sub_02009584
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
 * sub_020094D8 clears and sets in two separate read-modify-writes with a
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
 *   u8 sub_02009590(const struct WifiHistory *history,
 *                   const struct MyStatus *status, int flag)
 *   {
 *       u8 v = sub_02009584(history);
 *
 *       if (flag == 0) {
 *           u8 t = MYSTATUS_GetLanguage(status);
 *
 *           if (t == 0) {
 *               v = 0;
 *           } else if (sub_02009794(history) != 0 && v != 0) {
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
 * sub_0200952C is the same field written as a rewrite pass: for every one of
 * the 0xFF0 bytes it walks the four fields and turns every 1 into a 2, keeping
 * the byte in a register across the inner loop and storing it once.  The four
 * constants it needs are hoisted out of both loops, 3 twice because one is the
 * read mask and the other the shift base.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009470.c \
 *       --addr 0x02009470 --thumb
 */
struct WifiHistory *sub_02009470(struct SaveControl *saveControl)
{
    return SAVE_CONTROL_GetBlock(saveControl, WIFI_HISTORY_BLOCK_ID);
}






void sub_0200947C(struct WifiHistory *history, struct MyStatus *status,
                  u8 country, u8 region)
{
    MYSTATUS_SetLanguageAndVersion(status, country, region);
    sub_020094D8(history, country, region, 3);
}



u32 sub_0200949C(const struct WifiHistory *history, int country, int region)
{
    if (country == 0) {
        return 0;
    }
    return (history->countryRegionState[region / 4 + (country - 1) * 16] >> ((region % 4) * 2)) & 3;
}



void sub_020094D8(struct WifiHistory *history, int country, int region, int state)
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
}



u8 sub_02009524(const struct WifiHistory *history)
{
    return history->mode;
}



void sub_0200952C(struct WifiHistory *history)
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



u8 sub_02009584(const struct WifiHistory *history)
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
u8 func_02009590(struct WifiHistory *history, struct MyStatus *status, int flag)
{
    u8 count = func_02009584(history);

    if (flag == 0) {
        int country = func_0200856C(status);
        if (country == 0) {
            count = 0;
        } else if (func_02009794(history, country) && count != 0) {
            count--;
        }
    }

    return count;
}




/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           sub_02009618, sub_02009628, sub_02009634, sub_02009698,
 *           sub_0200973C, sub_0200974C, sub_02009750, sub_02009794
 *
 * alias: the rest of the save block with id 0x1D whose first half is
 * src/matched/unit_02009470.c.  This half is the twenty 0x28-byte records at
 * the front of the block, the 0xE9-bit flag array at +0x320, and the four
 * scalars at +0x344..+0x347 that sit between them.
 *
 * sub_02009634 and sub_02009698 are the getter and the setter over the record
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
 * setter and in sub_0200973C (`bge`, `blt`), so the three functions do not
 * agree about the type of their index and the source says so.
 *
 * sub_02009750 seeds its result from a literal pool word holding zero rather
 * than from a `movs`, which costs four bytes and is what the compiler does
 * here for a value initialised before a conditional; the `bne` that follows
 * reads the flags of the `adds r5, r1, #0` that moved the argument, so there
 * is no `cmp` for the first test at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020095C8.c \
 *       --addr 0x020095C8 --thumb
 */
u8 sub_020095C8(const struct WifiHistory *history)
{
    int i;

    for (i = 0; i < WIFI_HISTORY_ENTRY_MAX; i++) {
        if (history->entries[i].isOccupied == 0) {
            break;
        }
    }
    return i;
}



void sub_020095E8(struct WifiHistory *history)
{
    if (history->visitedCountryCount < WIFI_HISTORY_COUNTRY_MAX) {
        history->visitedCountryCount++;
    }
}



void sub_020095FC(struct WifiHistory *history, int value)
{
    if (value < 5) {
        history->ratingLevel = value;
    }
}



u8 sub_0200960C(const struct WifiHistory *history)
{
    return history->ratingLevel;
}



void sub_02009618(struct WifiHistory *history, int value)
{
    if (value < 9) {
        history->greetingSet = value;
    }
}



u8 sub_02009628(const struct WifiHistory *history)
{
    return history->greetingSet;
}



u32 sub_02009634(const struct WifiHistory *history, u32 index, u32 field)
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



void sub_02009698(struct WifiHistory *history, int index, u32 field, u32 value)
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



struct HistoryEntry *sub_0200973C(struct WifiHistory *history, int index)
{
    if (index >= WIFI_HISTORY_ENTRY_MAX) {
        return 0;
    }
    return &history->entries[index];
}



void sub_0200974C(void)
{
}



u32 sub_02009750(struct WifiHistory *history, u32 country)
{
    u32 isNew = 0;

    if (country == 0) {
        return isNew;
    }
    if (country < WIFI_HISTORY_COUNTRY_MAX) {
        if (sub_02009794(history, country) == 0) {
            isNew = 1;
        }
        history->visitedCountryBits[country >> 3] |= (u8)(1 << (u8)(country & 7));
    }
    return isNew;
}



u32 sub_02009794(const struct WifiHistory *history, u32 country)
{
    if (country < WIFI_HISTORY_COUNTRY_MAX) {
        u8 bit = (history->visitedCountryBits[country >> 3] >> (u8)(country & 7)) & 1;

        if (bit != 0) {
            return 1;
        }
    }
    return 0;
}



u32 WIFILIST_GetWorkSize(void)
{
    return sizeof(struct WifiList);
}



struct WifiList *WIFILIST_Create(int heapId)
{
    struct WifiList *list = func_02030734((unsigned short)heapId, sizeof(struct WifiList), 1, sWifilistFile, 0x39);
    func_02009800(list);
    return list;
}




/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * alias: wifilist.c's whole-record copy.  Twelve bytes with no prologue and no
 * label: two pool loads and a `bx`, which is the ARM tail call of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md with the size constant in the
 * same pool.  It sits between the allocator at 0x020097C4 and the constructor
 * at 0x02009800, so its range is its own.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020097F0.c \
 *       --addr 0x020097F0 --thumb
 */
void WIFILIST_Copy(const struct WifiList *src, struct WifiList *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct WifiList));
}



/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id sites
 *           ov_id_0D (13) and ov_id_09 (9) resolve as `overlay_id` (a layout
 *           overlay index, loaded by a pc-relative load of this function,
 *           reaching the id register of a known overlay loader), which was
 *           the last blocker.
 *
 * The wifilist constructor, diagnosed in the header of
 * src/matched/unit_02009860.c under "NEAR MISS, 0x02009800".  The only
 * branch to DWC_RAPCOMMON_InitUserData (ov009) in the image is the call in this
 * function; since seed round 9 it resolves as `sole-ref` on the seeded
 * ov009 start.
 *
 * The four ids arrive from literal pool words holding 0x09, 0x0A, 0x0B and
 * 0x0D rather than as `movs`, so they are relocations against absolute
 * symbols, not integer literals: see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.  With
 * the four declared as extern data symbols all four sites resolve and every
 * concrete byte reproduces.
 */
void WIFILIST_Init(struct WifiList *list)
{
    MI_CpuFill8(list, 0, sizeof(struct WifiList));
    func_02034A5C((int)ov_id_0A);
    func_02034A5C((int)ov_id_0B);
    func_02034AC4((int)ov_id_0D);
    func_02034AC4((int)ov_id_09);
    DWC_RAPCOMMON_InitUserData(list);
    func_02034A5C((int)ov_id_09);
    func_02034A5C((int)ov_id_0D);
    func_02034AC4((int)ov_id_0A);
    func_02034AC4((int)ov_id_0B);
}




/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           WIFILIST_GetFriendInfo, WIFILIST_CopyFriendNameToStrbuf, WIFILIST_StoreFriendNameFromStrbuf, WIFILIST_IsFriendDataValid
 *
 * alias: wifilist.c, the body of the record whose size and copy are in
 * src/matched/unit_020097BC.c and src/matched/unit_020097F0.c.  The record is
 *
 *   +0x000  u8[0x40]
 *   +0x040  Friend[0x20]   0x0C bytes each, DWC friend data
 *   +0x1C0  Entry[32]      0x30 bytes each
 *   +0x7C0  u8[4]
 *
 * NEAR MISS, 0x02009800, 72 bytes, skipped, and for two independent reasons.
 * It is the constructor: it clears the 0x7C4 bytes with MI_CpuFill8, brackets a
 * call to DWC_RAPCOMMON_InitUserData with four pairs of calls on the ids 9, 10, 11 and 13
 * (two of one function on the way in and two of the other on the way out, and
 * the reverse afterwards), and returns.
 *
 *  - DWC_RAPCOMMON_InitUserData lives in ov009, and the only branch to it anywhere in the
 *    image is this one.  The overlay-label rule needs a witness outside the
 *    compared range and there is none, so the site stays wildcarded whatever
 *    the C says, and no cut can help: shrinking the range to this one function
 *    keeps the call in it.
 *  - independently of that, 44 of its 72 bytes are wrong in every spelling
 *    tried.  Each of the four ids is materialised by the original with
 *    `ldr rN, [pc, #n]` out of its own literal pool word holding 0x0A, 0x0B,
 *    0x0D and 0x09, and then moved into r0 with an `adds`; plain arguments,
 *    `u32` locals holding them, an enum and pointer-typed constants all give
 *    `movs r0, #0xa` instead, which is shorter and changes the register
 *    allocation of the whole function.  A small constant that costs a pool
 *    word is not something the source has been made to say yet.
 *
 * WIFILIST_GetFriendInfoField and WIFILIST_SetFriendInfoField are the getter and the setter over the entry's
 * ten fields, both through a PC-relative halfword table.  The tables disagree
 * in the middle rather than at the bottom: the getter reads all ten, the
 * setter's entries 2, 3 and 4 point at its exit, and since entries 0 and 1 are
 * real the table exists without them, so those three really are case labels
 * the source does not have.  That is the ordinary gap reading of
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md, and the
 * contrasting case is in src/matched/unit_020095C8.c.
 *
 * Both tables also put case 9 in front of case 8: the displacement for 9 names
 * an earlier address than the one for 8 in each, and the arms only line up when
 * the source lists `case 9:` before `case 8:`.  A jump table fixes the case
 * *values*, and the order the bodies are emitted in is still source order, so
 * the two together recover the order the arms were written in.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009800.c \
 *       --addr 0x02009800 --thumb
 */
struct WifiList *WIFILIST_GetWork(struct WifiList *list)
{
    return list;
}


u32 WIFILIST_GetFriendInfoField(const struct WifiList *list, u32 index, u32 field)
{
    u32 value = 0;

    switch (field) {
    case 0:
        value = list->friendInfo[index].profileId;
        break;
    case 1:
        value = list->friendInfo[index].trainerId;
        break;
    case 2:
        value = list->friendInfo[index].battleWins;
        break;
    case 3:
        value = list->friendInfo[index].battleLosses;
        break;
    case 4:
        value = list->friendInfo[index].tradeCount;
        break;
    case 5:
        value = list->friendInfo[index].lastYear;
        break;
    case 6:
        value = list->friendInfo[index].lastMonth;
        break;
    case 7:
        value = list->friendInfo[index].lastDay;
        break;
    case 9:
        value = list->friendInfo[index].gender;
        break;
    case 8:
        value = list->friendInfo[index].language;
        break;
    }
    return value;
}


void WIFILIST_SetFriendInfoField(struct WifiList *list, u32 index, u32 field, u32 value)
{
    switch (field) {
    case 0:
        list->friendInfo[index].profileId = value;
        break;
    case 1:
        list->friendInfo[index].trainerId = value;
        break;
    case 5:
        list->friendInfo[index].lastYear = value;
        break;
    case 6:
        list->friendInfo[index].lastMonth = value;
        break;
    case 7:
        list->friendInfo[index].lastDay = value;
        break;
    case 9:
        list->friendInfo[index].gender = value;
        break;
    case 8:
        list->friendInfo[index].language = value;
        break;
    }
}


struct DWCFriendData *WIFILIST_GetDwcFriendData(struct WifiList *list, int index)
{
    return &list->friendData[index];
}


struct WifiFriendInfo *WIFILIST_GetFriendInfo(struct WifiList *list, int index)
{
    return &list->friendInfo[index];
}


void WIFILIST_CopyFriendNameToStrbuf(struct WifiList *list, int index, struct Strbuf *dest)
{
    STRBUF_SetStringN(dest, (const u16 *)&list->friendInfo[index], 0x10);
}


void WIFILIST_StoreFriendNameFromStrbuf(struct WifiList *list, int index, struct U16Vec *dest)
{
    STRBUF_ToChars(dest, (u16 *)(&list->friendInfo[index]), 0x10);
}


int WIFILIST_IsFriendDataValid(struct WifiList *list, u32 index)
{
    if (index >= WIFILIST_FRIEND_MAX) {
        return 0;
    }
    return DWC_IsValidFriendData(&list->friendData[index]);
}
