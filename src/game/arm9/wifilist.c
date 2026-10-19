/*
 * file:     wifilist.c
 * unit:     yes
 * function: WIFILIST_GetWorkSize, WIFILIST_Create, WIFILIST_Copy, WIFILIST_Init, WIFILIST_GetWork, WIFILIST_GetFriendInfoField, WIFILIST_SetFriendInfoField, WIFILIST_GetDwcFriendData, WIFILIST_GetFriendInfo, WIFILIST_CopyFriendNameToStrbuf, WIFILIST_StoreFriendNameFromStrbuf, WIFILIST_IsFriendDataValid, WIFILIST_CountFriends, WIFILIST_GetFriendListEnd, WIFILIST_RemoveFriendSlot, WIFILIST_MoveFriendSlot, WIFILIST_CompactFriendList, WIFILIST_SetFriendLastSeen, WIFILIST_AddFriendBattleRecord, WIFILIST_MergeFriendRecord, WIFILIST_CreateExchangeToken, WIFILIST_MakeExchangeToken, WIFILIST_GetGsProfileId, WIFILIST_IsProfileValid, WIFILIST_GetFromSave, WIFILIST_FindFriendByStatus, WIFILIST_FindFriendByStatusAndOutfit
 * address:  0x020097BC
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
 *   DWC_CheckHasProfile    0x020597C8  arm
 *   DWC_CheckValidConsole  0x02059760  arm
 *   DWC_CreateExchangeToken 0x020599BC  arm
 *   DWC_GetGsProfileId     0x020598EC  arm
 *   DWC_IsValidFriendData 0x020596D8  arm
 *   DWC_RAPCOMMON_InitUserData  0x02157138  thumb ov009
 *   GF_STANDARD_GetCachedDate  0x0203F4E4  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   MYSTATUS_GetId  0x02008530  thumb
 *   MYSTATUS_GetName  0x020084F4  thumb
 *   MYSTATUS_GetOutfitVariant  0x02008550  thumb
 *   SAVE_CONTROL_GetBlock    0x020071CC  thumb
 *   STRBUF_SetStringN         0x02045994  arm
 *   STRBUF_ToChars         0x02045A38  arm
 *   WIFILIST_GetFriendInfo  0x020099D4  thumb
 *   WIFILIST_GetFriendInfoField  0x02009864  thumb
 *   WIFILIST_GetWork  0x02009860  thumb
 *   WIFILIST_IsFriendDataValid  0x02009A1C  thumb
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   ov_id_09       0x00000009  data
 *   ov_id_0A       0x0000000A  data
 *   ov_id_0B       0x0000000B  data
 *   ov_id_0D       0x0000000D  data
 *   sWifilistFile  0x020A7198  data
 *   GFL_HEAP_Alloc  0x02030734  arm
 */
#include "game_sync_shared_types.h"
#include "wifi_history_shared_types.h"

#define WIFILIST_FRIEND_MAX 32

struct Strbuf;

struct U16Vec;

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

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);

extern void WIFILIST_Init(struct WifiList *list);

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern void MI_CpuFill8(void *dst, int val, unsigned n);

extern void GF_OVERLAY_Unload(int handle);

extern int GF_OVERLAY_Load(int id);

extern void DWC_RAPCOMMON_InitUserData(void *p);

extern int  DWC_IsValidFriendData(const void *friendData);

extern void STRBUF_SetStringN(struct Strbuf *dest, const u16 *src, u32 size);

extern void STRBUF_ToChars(struct U16Vec *src, u16 *dest, u32 size);

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

/* RTC calendar date (config.c layout). */
struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

extern void GF_STANDARD_GetCachedDate(struct RTCDate *date);

extern void DWC_CreateExchangeToken(void *userData, void *friendData);

extern int  DWC_GetGsProfileId(void *userData, void *friendData);

extern int  DWC_CheckValidConsole(void *userData);

extern int  DWC_CheckHasProfile(void *userData);

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *save, u32 blockId);

extern u32  MYSTATUS_GetId(const struct MyStatus *status);

extern u8   MYSTATUS_GetOutfitVariant(const struct MyStatus *status);

extern const void *MYSTATUS_GetName(const void *status);

u32 WIFILIST_GetWorkSize(void)
{
    return sizeof(struct WifiList);
}

struct WifiList *WIFILIST_Create(int heapId)
{
    struct WifiList *list = GFL_HEAP_Alloc((unsigned short)heapId, sizeof(struct WifiList), 1, sWifilistFile, 0x39);
    WIFILIST_Init(list);
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
    GF_OVERLAY_Unload((int)ov_id_0A);
    GF_OVERLAY_Unload((int)ov_id_0B);
    GF_OVERLAY_Load((int)ov_id_0D);
    GF_OVERLAY_Load((int)ov_id_09);
    DWC_RAPCOMMON_InitUserData(list);
    GF_OVERLAY_Unload((int)ov_id_09);
    GF_OVERLAY_Unload((int)ov_id_0D);
    GF_OVERLAY_Load((int)ov_id_0A);
    GF_OVERLAY_Load((int)ov_id_0B);
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

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           WIFILIST_CompactFriendList, WIFILIST_SetFriendLastSeen, WIFILIST_AddFriendBattleRecord
 *
 * alias: wifilist.c's list maintenance.  The two parallel arrays of
 * src/matched/unit_02009860.c hold 32 slots each, an 0x0C-byte DWC friend
 * record at +0x40 and an 0x30-byte entry at +0x1C0, and every function here
 * moves both together.
 *
 * WIFILIST_CompactFriendList is the compaction pass and is the one worth reading.  It scans
 * the 32 slots keeping `j` at the first hole it has seen, and when it finds a
 * used slot after a hole it moves it down with WIFILIST_MoveFriendSlot and then sets
 * `i = -1` so the `i++` restarts the scan from zero.  The compiler cross-jumps
 * the two assignments to `j`: the restart arm's `j = -1` and the hole arm's
 * `j = i` become one `adds r5, r4, #0` reached from both, which is only
 * correct because `i` has just been set to -1 on the first path.  Reading that
 * shared instruction as a single statement is what makes the restart visible.
 *
 * -1 costs three materialisations here, one in a register and two in stack
 * slots, because the function is out of callee-saved registers: the same
 * constant is the loop's sentinel, the value assigned to `i`, and the value
 * compared against in the other arm.
 *
 * The tail of WIFILIST_RemoveFriendSlot is where the shape of the source is visible.  It
 * clears slot 31 of both arrays, and the original reaches it as base plus
 * offset in two separate adds: `list + 0x1C0` and then `+ 0x5D0`, with the
 * friend array's `+ 0x174` derived from that same 0x5D0 by a `lsrs #2`.
 * Written as `&list->friendInfo[31]` the compiler folds the two constants into one
 * 0x790 and the tail is 34 bytes different; only a local pointer, assigned
 * from the array *after* the loop and indexed with the literal 31, keeps them
 * apart.  Assigning the same pointers before the loop is wrong too: they then
 * stay live in callee-saved registers and the reload of `obj` from its stack
 * slot disappears.
 *
 * WIFILIST_SetFriendLastSeen stamps the entry with the date.  GF_STANDARD_GetCachedDate fills a 0x10-byte
 * record on the stack whose first three words are year, month and day, and the
 * year is stored as `year + 2000`, which is the `movs r0, #0x7D; lsls r0, #4`
 * in front of the `strh`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009A34.c \
 *       --addr 0x02009A34 --thumb
 */
u32 WIFILIST_CountFriends(struct WifiList *list)
{
    int i;
    u32 count = 0;

    for (i = 0; i < 0x20; i++) {
        if (WIFILIST_IsFriendDataValid(list, i) != 0) {
            count++;
        }
    }
    return count;
}

u32 WIFILIST_GetFriendListEnd(struct WifiList *list)
{
    int i;
    u32 end = 0;

    for (i = 0; i < 0x20; i++) {
        if (WIFILIST_IsFriendDataValid(list, i) != 0) {
            end = i + 1;
        }
    }
    return end;
}

void WIFILIST_RemoveFriendSlot(struct WifiList *list, u32 slot)
{
    struct WifiFriendInfo *infos;
    struct DWCFriendData *friends;

    if (slot >= 0x20) {
        return;
    }
    for (; (int)slot < 0x1F; slot++) {
        MI_CpuCopy8(&list->friendInfo[slot + 1], &list->friendInfo[slot],
                    sizeof(list->friendInfo[0]));
        MI_CpuCopy8(&list->friendData[slot + 1], &list->friendData[slot],
                    sizeof(list->friendData[0]));
    }
    infos = list->friendInfo;
    friends = list->friendData;
    MI_CpuFill8(&infos[0x1F], 0, sizeof(infos[0]));
    MI_CpuFill8(&friends[0x1F], 0, sizeof(friends[0]));
}

void WIFILIST_MoveFriendSlot(struct WifiList *list, u32 dest, u32 src)
{
    MI_CpuCopy8(&list->friendInfo[src], &list->friendInfo[dest], sizeof(list->friendInfo[0]));
    MI_CpuCopy8(&list->friendData[src], &list->friendData[dest], sizeof(list->friendData[0]));
    MI_CpuFill8(&list->friendInfo[src], 0, sizeof(list->friendInfo[0]));
    MI_CpuFill8(&list->friendData[src], 0, sizeof(list->friendData[0]));
}

void WIFILIST_CompactFriendList(struct WifiList *list)
{
    int i;
    int hole = -1;

    for (i = 0; i < 0x20; i++) {
        if (WIFILIST_IsFriendDataValid(list, i) != 0) {
            if (hole != -1) {
                WIFILIST_MoveFriendSlot(list, hole, i);
                i = -1;
                hole = -1;
            }
        } else {
            if (hole == -1) {
                hole = i;
            }
        }
    }
}

void WIFILIST_SetFriendLastSeen(struct WifiList *list, int slot)
{
    struct RTCDate date;

    GF_STANDARD_GetCachedDate(&date);
    list->friendInfo[slot].lastYear = date.year + 2000;
    list->friendInfo[slot].lastMonth = date.month;
    list->friendInfo[slot].lastDay = date.day;
}

void WIFILIST_AddFriendBattleRecord(struct WifiList *list, int slot, int wins, int losses, int trades)
{
    if (slot < 0 || slot >= 0x20) {
        return;
    }
    list->friendInfo[slot].battleWins += (u16)wins;
    if (list->friendInfo[slot].battleWins > 9999) {
        list->friendInfo[slot].battleWins = 9999;
    }
    list->friendInfo[slot].battleLosses += (u16)losses;
    if (list->friendInfo[slot].battleLosses > 9999) {
        list->friendInfo[slot].battleLosses = 9999;
    }
    list->friendInfo[slot].tradeCount += (u16)trades;
    if (list->friendInfo[slot].tradeCount > 9999) {
        list->friendInfo[slot].tradeCount = 9999;
    }
    WIFILIST_SetFriendLastSeen(list, slot);
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * alias: wifilist.c.  WIFILIST_MergeFriendRecord folds one entry's three counters into
 * another's, clamping each at 9999 the way WIFILIST_AddFriendBattleRecord does, and then clears
 * the entry it drained.
 *
 * The cut between this range and src/matched/unit_02009CB0.c is what makes
 * both halves EXACT.  DWC_CreateExchangeToken is reached from exactly two
 * places in the image, the pool word of WIFILIST_CreateExchangeToken at 0x02009CAC and the
 * `blx` inside WIFILIST_MakeExchangeToken at 0x02009CB8, and a range holding both leaves the
 * address with no witness at all.  Split, the `blx` attests this file's pool
 * word and the pool word attests that file's `blx`.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009C24.c  *       --addr 0x02009C24 --thumb
 */
void WIFILIST_MergeFriendRecord(struct WifiList *list, int src, int dest)
{
    if (dest < 0 || dest >= 0x20) {
        return;
    }
    if (src < 0 || src >= 0x20) {
        return;
    }
    list->friendInfo[dest].battleWins += list->friendInfo[src].battleWins;
    if (list->friendInfo[dest].battleWins > 9999) {
        list->friendInfo[dest].battleWins = 9999;
    }
    list->friendInfo[dest].battleLosses += list->friendInfo[src].battleLosses;
    if (list->friendInfo[dest].battleLosses > 9999) {
        list->friendInfo[dest].battleLosses = 9999;
    }
    list->friendInfo[dest].tradeCount += list->friendInfo[src].tradeCount;
    if (list->friendInfo[dest].tradeCount > 9999) {
        list->friendInfo[dest].tradeCount = 9999;
    }
    MI_CpuFill8(&list->friendInfo[src], 0, sizeof(list->friendInfo[0]));
}

void WIFILIST_CreateExchangeToken(void *userData, void *friendData)
{
    DWC_CreateExchangeToken(userData, friendData);
}

void WIFILIST_MakeExchangeToken(struct WifiList *list, void *token)
{
    DWC_CreateExchangeToken(WIFILIST_GetWork(list), token);
}

/*
 * Compared as a unit rather than as a single function because the packet's
 * range runs two bytes past the last instruction: `match.py one` sees the
 * original as 36 bytes against the compiler's 34 and reports EXACT*, while
 * `tu` lays the section out and reproduces the linker's two-byte filler.
 */
int WIFILIST_GetGsProfileId(struct WifiList *list)
{
    u8 token[12];
    void *userData = WIFILIST_GetWork(list);

    WIFILIST_MakeExchangeToken(list, token);
    return DWC_GetGsProfileId(userData, token);
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * alias: the DWC-facing end of wifilist.c.  WIFILIST_GetFromSave is the one that names
 * the save block: it fetches block id 0x1E out of SAVE_CONTROL_GetBlock and hands it
 * straight to the entry accessor of src/matched/unit_02009860.c, so the wifi
 * friend list lives in block 0x1E.
 *
 * WIFILIST_GetWork, the two-byte `bx lr` in src/matched/unit_02009860.c, is used
 * here the way MYSTATUS_GetName is used in src/matched/unit_02008F48.c: its result
 * feeds the next call's first argument with no move in between, so it is an
 * identity accessor and is declared with the type that call needs.
 *
 * NEAR MISS, 0x02009CB0 and 0x02009CC0, 50 bytes, skipped for attestation and
 * not for codegen.  They are
 *
 *   void WIFILIST_MakeExchangeToken(struct WifiList *obj, void *out)
 *   {
 *       DWC_CreateExchangeToken(WIFILIST_GetWork(obj), out);
 *   }
 *
 *   void WIFILIST_GetGsProfileId(struct WifiList *obj)
 *   {
 *       u8 token[0xC];
 *       void *account = WIFILIST_GetWork(obj);
 *
 *       WIFILIST_MakeExchangeToken(obj, token);
 *       DWC_GetGsProfileId(account, token);
 *   }
 *
 * and with WIFILIST_MergeFriendRecord they reproduce every concrete byte.  The chain that
 * blocks them is two links long.  DWC_CreateExchangeToken is reached from
 * exactly two places in the image: the pool word of WIFILIST_CreateExchangeToken at 0x02009CAC
 * and the `blx` in WIFILIST_MakeExchangeToken at 0x02009CB8.  Whichever of the two is in the
 * range, the other is its witness, so exactly one of them can be matched, and
 * src/matched/unit_02009C24.c takes WIFILIST_CreateExchangeToken because that choice is what
 * lets its own pool word be attested by the `blx`.  WIFILIST_MakeExchangeToken is then
 * unmatched, and the only branch to *it* anywhere in the image is the one in
 * WIFILIST_GetGsProfileId, so WIFILIST_GetGsProfileId cannot be matched either.  Both close the day
 * anything else in the image calls either address.
 *
 * WIFILIST_FindFriendByStatusAndOutfit compares two call results against two parameters, and both
 * comparisons only come out `cmp r0, rN` when a named local holds the result:
 * written inline, in either operand order or as one `&&` chain, the compiler
 * normalises to `cmp rN, r0` and the file is two bytes wrong.  See
 * docs/idioms/cmp-operand-order-names-the-temporary.md.
 *
 * WIFILIST_FindFriendByStatusAndOutfit's second parameter is dead: nothing in it reads r1, and
 * WIFILIST_FindFriendByStatus still computes MYSTATUS_GetName(p) to pass there.  Leaving the
 * parameter out moves every argument and the function does not match, so the
 * dead argument is part of the shape.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009C24.c \
 *       --addr 0x02009C24 --thumb
 */
u32 WIFILIST_IsProfileValid(struct WifiList *list)
{
    void *userData = WIFILIST_GetWork(list);

    if (DWC_CheckHasProfile(userData) != 0) {
        if (DWC_CheckValidConsole(userData) != 0) {
            return 1;
        }
    }
    return 0;
}

struct WifiList *WIFILIST_GetFromSave(struct SaveControl *save)
{
    struct WifiList *list = SAVE_CONTROL_GetBlock(save, 0x1E);

    WIFILIST_GetFriendInfo(list, 0);
    return list;
}

int WIFILIST_FindFriendByStatus(struct WifiList *list, struct MyStatus *status,
                 u32 *outSlot)
{
    u32 id = MYSTATUS_GetId(status);
    u8 outfitVariant = MYSTATUS_GetOutfitVariant(status);

    return WIFILIST_FindFriendByStatusAndOutfit(list, MYSTATUS_GetName(status), id, outfitVariant, outSlot);
}

int WIFILIST_FindFriendByStatusAndOutfit(struct WifiList *list, const void *name, u32 id,
                 u32 outfitVariant, u32 *outSlot)
{
    u8 i;
    u32 value;

    for (i = 0; i < 0x20; i++) {
        if (WIFILIST_IsFriendDataValid(list, i) == 1) {
            value = WIFILIST_GetFriendInfoField(list, i, 0);
            if (value == id) {
                value = WIFILIST_GetFriendInfoField(list, i, 9);
                if (value == outfitVariant) {
                    if (outSlot != 0) {
                        *outSlot = i;
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}
