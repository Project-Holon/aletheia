/*
 * file:     wifilist_tail.c
 * unit:     yes
 * function: WIFILIST_CountFriends, WIFILIST_GetFriendListEnd, WIFILIST_RemoveFriendSlot, WIFILIST_MoveFriendSlot, WIFILIST_CompactFriendList, WIFILIST_SetFriendLastSeen, WIFILIST_AddFriendBattleRecord, WIFILIST_MergeFriendRecord, WIFILIST_CreateExchangeToken, WIFILIST_MakeExchangeToken, WIFILIST_GetGsProfileId, WIFILIST_IsProfileValid, WIFILIST_GetFromSave, WIFILIST_FindFriendByStatus, WIFILIST_FindFriendByStatusAndOutfit
 * address:  0x02009A34
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mystery_data.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   GF_STANDARD_SetField00_F4E4  0x0203F4E4  arm
 *   DWC_CreateExchangeToken 0x020599BC  arm
 *   DWC_CheckValidConsole  0x02059760  arm
 *   DWC_CheckHasProfile    0x020597C8  arm
 *   DWC_GetGsProfileId     0x020598EC  arm
 *   func_020071CC  0x020071CC  thumb
 *   MYSTATUS_GetName  0x020084F4  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   MYSTATUS_GetOutfitVariant  0x02008550  thumb
 *   WIFILIST_GetWork  0x02009860  thumb
 *   WIFILIST_GetFriendInfoField  0x02009864  thumb
 *   WIFILIST_GetFriendInfo  0x020099D4  thumb
 *   WIFILIST_IsFriendDataValid  0x02009A1C  thumb
 */
#include "wifilist_tail_shared_types.h"

/*
 * Save block 0x1E, the Wi-Fi friend list (wifilist.c).  Two parallel arrays
 * of 32 slots: the DWC friend data and the per-friend record.
 */
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
    u8 userData[0x40];                    /* DWC user data, at offset 0 */
    struct DWCFriendData friendData[0x20];
    struct WifiFriendInfo friendInfo[32];
    u8 reserved[4];
};

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern void GF_STANDARD_SetField00_F4E4(struct RTCDate *date);

extern void DWC_CreateExchangeToken(void *userData, void *friendData);

extern int  DWC_GetGsProfileId(void *userData, void *friendData);

extern int  DWC_CheckValidConsole(void *userData);

extern int  DWC_CheckHasProfile(void *userData);

extern void *func_020071CC(struct SaveControl *save, u32 blockId);

extern u32  MYSTATUS_GetId(const struct MyStatus *status);

extern u8   MYSTATUS_GetOutfitVariant(const struct MyStatus *status);

extern const void *MYSTATUS_GetName(const void *status);

struct WifiList *WIFILIST_GetWork(struct WifiList *list);

u32 WIFILIST_GetFriendInfoField(const struct WifiList *list, u32 i, u32 field);

struct WifiFriendInfo *WIFILIST_GetFriendInfo(struct WifiList *list, int i);

int WIFILIST_IsFriendDataValid(struct WifiList *list, u32 i);

u32 WIFILIST_CountFriends(struct WifiList *list);

u32 WIFILIST_GetFriendListEnd(struct WifiList *list);

void WIFILIST_RemoveFriendSlot(struct WifiList *list, u32 slot);

void WIFILIST_MoveFriendSlot(struct WifiList *list, u32 dest, u32 src);

void WIFILIST_CompactFriendList(struct WifiList *list);

void WIFILIST_SetFriendLastSeen(struct WifiList *list, int slot);

void WIFILIST_AddFriendBattleRecord(struct WifiList *list, int slot, int wins, int losses, int trades);

void WIFILIST_MergeFriendRecord(struct WifiList *list, int src, int dest);

void WIFILIST_CreateExchangeToken(void *userData, void *friendData);

void WIFILIST_MakeExchangeToken(struct WifiList *list, void *token);

int WIFILIST_GetGsProfileId(struct WifiList *list);

u32 WIFILIST_IsProfileValid(struct WifiList *list);

struct WifiList *WIFILIST_GetFromSave(struct SaveControl *save);

int WIFILIST_FindFriendByStatus(struct WifiList *list, struct MyStatus *status, u32 *outSlot);

int WIFILIST_FindFriendByStatusAndOutfit(struct WifiList *list, const void *name, u32 id, u32 outfitVariant, u32 *outSlot);

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
 * WIFILIST_SetFriendLastSeen stamps the entry with the date.  GF_STANDARD_SetField00_F4E4 fills a 0x10-byte
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

    GF_STANDARD_SetField00_F4E4(&date);
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
 * `blx` inside sub_02009CB0 at 0x02009CB8, and a range holding both leaves the
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
 * the save block: it fetches block id 0x1E out of func_020071CC and hands it
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
 *   void sub_02009CB0(struct WifiList *obj, void *out)
 *   {
 *       DWC_CreateExchangeToken(WIFILIST_GetWork(obj), out);
 *   }
 *
 *   void sub_02009CC0(struct WifiList *obj)
 *   {
 *       u8 token[0xC];
 *       void *account = WIFILIST_GetWork(obj);
 *
 *       sub_02009CB0(obj, token);
 *       DWC_GetGsProfileId(account, token);
 *   }
 *
 * and with WIFILIST_MergeFriendRecord they reproduce every concrete byte.  The chain that
 * blocks them is two links long.  DWC_CreateExchangeToken is reached from
 * exactly two places in the image: the pool word of WIFILIST_CreateExchangeToken at 0x02009CAC
 * and the `blx` in sub_02009CB0 at 0x02009CB8.  Whichever of the two is in the
 * range, the other is its witness, so exactly one of them can be matched, and
 * src/matched/unit_02009C24.c takes WIFILIST_CreateExchangeToken because that choice is what
 * lets its own pool word be attested by the `blx`.  sub_02009CB0 is then
 * unmatched, and the only branch to *it* anywhere in the image is the one in
 * sub_02009CC0, so sub_02009CC0 cannot be matched either.  Both close the day
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
    struct WifiList *list = func_020071CC(save, 0x1E);

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
