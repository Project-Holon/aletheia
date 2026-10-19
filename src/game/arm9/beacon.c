/*
 * file:     beacon.c
 * unit:     yes
 * function: MISC_GetSize, MISC_Init, MISC_GetFromSave, MISC_GetBlock, MISC_SetInputFlag, MISC_GetInputFlag, MISC_ClearInputFlags, MISC_SetMonRecord, MISC_GetMonRecord, MISC_GetBestScore, MISC_SetBestScore, MISC_GetRank, MISC_SetRank, MISC_GetGreetCount, MISC_IncrementGreetCount, MISC_GetThanksCount, MISC_IncrementThanksCount, MISC_GetGreetMessage, MISC_SetGreetMessage, MISC_GetThanksMessage, MISC_SetThanksMessage, MISC_GetResearchRank, MISC_SetResearchRank, MISC_GetBadge, MISC_SetBadge, MISC_CountBadges, MISC_GetMoney, MISC_AddMoney, MISC_SubMoney, MISC_SetTeam, MISC_GetTeam, MISC_SetSlotState, MISC_GetSlotState, MISC_GetSlotStates, MISC_SetSlotStates, MISC_GetResearchMissionIndex, MISC_SetResearchMissionIndex, MISC_GetRecentId, MISC_SetRecentId, MISC_GetRecentValue, MISC_SetRecentValue, MISC_AddRecentValue, MISC_GetLastTime, MISC_SetLastTime, MISC_SetHashedId, MISC_GetHashedId, MISC_GetGatePoints, MISC_SetGatePoints, MISC_SubGatePoints, MISC_GetRecorderFlag, MISC_SetRecorderFlag
 * address:  0x0200C054
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from battle_rec.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8          0x02082BCC  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   MSGDATA_AllocString    0x02045EC0  arm
 *   STRBUF_ToChars    0x02045A38  arm
 *   STRBUF_Delete    0x02045808  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 */
#include "battle_rec_types.h"
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed int s32;
typedef unsigned short u16;

typedef unsigned long long u64;
struct MsgData;

/* A party Pokemon (0xDC bytes) and a boxed Pokemon (0x88 bytes).  Both are
 * declared as words: the copies of them are eight-byte stepped ldm/stm loops. */
struct PokeParam {
    u32 data[0x37];
};

struct StrBuf;

/* Save block 0x34: the C-Gear beacon record (greeting and thanks messages and
 * their counters, survey points, recent partners). */
struct MonRecord {
    u8 form : 6;
    u8 isEgg : 1;
    u8 gender : 1;
};

union BeaconTime {
    u64 value;
    struct {
        u32 lo;
        u32 hi;
    } half;
};

struct BeaconTeam {
    u16 species[6];
};

struct MiscSave {
    u32 money;
    u32 badges;
    u16 species;
    struct MonRecord monRecord;
    u8  padding;
    u8  inputFlags[8];
    u32 bestScore : 28;
    u32 rank : 4;
    u32 greetCount;
    u32 thanksCount;
    u16 greetMessage[9];
    u16 thanksMessage[9];
    u8  mode;
    u8  slotStates;         /* 2 bits per slot */
    u8  entryCount;
    u8  recentIds[3];
    u16 recentValues[3];
    union BeaconTime lastTime;
    struct BeaconTeam teams[8];
    u32 hashedIds[8];
    u32 unusedWord;
    u32 recorderFlag;
    /* stand-in: volatile keeps the two reads of MISC_SubGatePoints (compare, then
     * subtract); every ordinary spelling folds them into one load, and a
     * 16-bit bitfield changes the getter and setter. */
    volatile u16 gatePoints;
    u16 unusedHalf;
    u8  unusedTail[8];
};

extern void MI_CpuFill8(void *dest, u8 value, u32 size);

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *save, u32 blockId);
struct MsgBank;

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern u32 MSGDATA_Delete(struct MsgBank *bank);
struct Strbuf;

extern struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void STRBUF_ToChars(struct Strbuf *strbuf, u16 *out, u32 maxChars);

extern void STRBUF_Delete(struct Strbuf *strbuf);

u32 MISC_GetSize(void);

void MISC_Init(struct MiscSave *beacon);

struct MiscSave *MISC_GetFromSave(struct SaveControl *save);

struct MiscSave *MISC_GetBlock(struct SaveControl *save);

void MISC_SetInputFlag(struct MiscSave *beacon, u32 index, u8 value);

u8 MISC_GetInputFlag(struct MiscSave *beacon, u32 index);

void MISC_ClearInputFlags(struct MiscSave *beacon);

void MISC_SetMonRecord(struct MiscSave *misc, u16 species, u32 form, u32 isEgg, u32 gender);

void MISC_GetMonRecord(const struct MiscSave *misc, u32 *species, u32 *form, u32 *isEgg, u32 *gender);

u32 MISC_GetBestScore(struct MiscSave *beacon);

void MISC_SetBestScore(struct MiscSave *beacon, u32 score);

u8 MISC_GetRank(struct MiscSave *beacon);

void MISC_SetRank(struct MiscSave *beacon, u32 rank);

u32 MISC_GetGreetCount(struct MiscSave *beacon);

u32 MISC_IncrementGreetCount(struct MiscSave *beacon);

u32 MISC_GetThanksCount(struct MiscSave *beacon);

u32 MISC_IncrementThanksCount(struct MiscSave *beacon);

u16 *MISC_GetGreetMessage(struct MiscSave *beacon);

void MISC_SetGreetMessage(struct MiscSave *beacon, struct StrBuf *message);

u16 *MISC_GetThanksMessage(struct MiscSave *beacon);

void MISC_SetThanksMessage(struct MiscSave *beacon, struct StrBuf *message);

u8 MISC_GetResearchRank(struct MiscSave *beacon);

void MISC_SetResearchRank(struct MiscSave *beacon, u8 mode);

u32 MISC_GetBadge(struct MiscSave *beacon, u32 bit);

void MISC_SetBadge(struct MiscSave *beacon, u32 bit);

u32 MISC_CountBadges(struct MiscSave *beacon);

u32 MISC_GetMoney(struct MiscSave *beacon);

u32 MISC_AddMoney(struct MiscSave *beacon, u32 add);

u32 MISC_SubMoney(struct MiscSave *beacon, u32 sub);

void MISC_SetTeam(struct MiscSave *beacon, u32 index, const u16 *species);

void MISC_GetTeam(struct MiscSave *beacon, u32 index, u16 *species);

void MISC_SetSlotState(struct MiscSave *beacon, u32 slot, u8 state);

u8 MISC_GetSlotState(struct MiscSave *beacon, u32 slot);

u8 MISC_GetSlotStates(struct MiscSave *beacon);

void MISC_SetSlotStates(struct MiscSave *beacon, u8 states);

u8 MISC_GetResearchMissionIndex(struct MiscSave *beacon);

void MISC_SetResearchMissionIndex(struct MiscSave *beacon, u8 count);

int MISC_GetRecentId(struct MiscSave *beacon, u32 index);

void MISC_SetRecentId(struct MiscSave *beacon, u8 index, u8 id);

u16 MISC_GetRecentValue(struct MiscSave *beacon, u32 index);

void MISC_SetRecentValue(struct MiscSave *beacon, u32 index, int value);

void MISC_AddRecentValue(struct MiscSave *beacon, u8 index, int add);

u64 MISC_GetLastTime(struct MiscSave *beacon);

void MISC_SetLastTime(struct MiscSave *beacon, u32 lo, u32 hi);

void MISC_SetHashedId(struct MiscSave *beacon, s32 index, u32 value);

u32 MISC_GetHashedId(struct MiscSave *beacon, s32 index);

u16 MISC_GetGatePoints(struct MiscSave *beacon);

void MISC_SetGatePoints(struct MiscSave *beacon, u16 points);

void MISC_SubGatePoints(struct MiscSave *beacon, u16 sub);

u8 MISC_GetRecorderFlag(struct MiscSave *beacon);

void MISC_SetRecorderFlag(struct MiscSave *beacon, u32 flag);

u32 MISC_GetSize(void)
{
    return sizeof(struct MiscSave);
}

void MISC_Init(struct MiscSave *beacon)
{
    struct MsgData *msg;
    struct StrBuf *greet;
    struct StrBuf *thanks;

    MI_CpuFill8(beacon, 0, sizeof(struct MiscSave));
    MISC_ClearInputFlags(beacon);
    beacon->bestScore = 0;
    msg = (struct MsgData *)MSGDATA_CreateFromArchive(0, 3, 0x2f, 0x8007);
    greet = (struct StrBuf *)MSGDATA_AllocString((struct MsgBank *)msg, 0x151);
    STRBUF_ToChars((struct Strbuf *)greet, beacon->greetMessage, 9);
    STRBUF_Delete((struct Strbuf *)greet);
    thanks = (struct StrBuf *)MSGDATA_AllocString((struct MsgBank *)msg, 0x159);
    STRBUF_ToChars((struct Strbuf *)thanks, beacon->thanksMessage, 9);
    STRBUF_Delete((struct Strbuf *)thanks);
    MSGDATA_Delete((struct MsgBank *)msg);
    beacon->mode = 0;
    beacon->entryCount = 0;
    beacon->recentIds[0] = 0xff;
    beacon->recentIds[1] = 0xff;
    beacon->recentIds[2] = 0xff;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           MISC_ClearInputFlags, MISC_SetMonRecord, MISC_GetMonRecord, MISC_GetBestScore,
 *           MISC_SetBestScore, MISC_GetRank, MISC_SetRank, MISC_GetGreetCount,
 *           MISC_IncrementGreetCount, MISC_GetThanksCount, MISC_IncrementThanksCount, MISC_GetGreetMessage,
 *           MISC_SetGreetMessage, MISC_GetThanksMessage, MISC_SetThanksMessage, MISC_GetResearchRank,
 *           MISC_SetResearchRank, MISC_GetBadge, MISC_SetBadge, MISC_CountBadges,
 *           MISC_GetMoney, MISC_AddMoney, MISC_SubMoney, MISC_SetTeam,
 *           MISC_GetTeam, MISC_SetSlotState, MISC_GetSlotState, MISC_GetSlotStates,
 *           MISC_SetSlotStates, MISC_GetResearchMissionIndex, MISC_SetResearchMissionIndex, MISC_GetRecentId,
 *           MISC_SetRecentId, MISC_GetRecentValue, MISC_SetRecentValue, MISC_AddRecentValue,
 *           MISC_GetLastTime, MISC_SetLastTime, MISC_SetHashedId, MISC_GetHashedId,
 *           MISC_GetGatePoints, MISC_SetGatePoints, MISC_SubGatePoints, MISC_GetRecorderFlag,
 *           MISC_SetRecorderFlag
 *
 * 780 bytes, 0x0200C0E8..0x0200C3F4, 49 functions, forty-four of which carry
 * no label in the generated listing: the file is almost entirely accessors
 * and none of them saves lr.
 *
 * The object is the save block with id 0x34: MISC_GetBlock is the whole of
 * its lookup, `SAVE_CONTROL_GetBlock(sys, 0x34)`, and MISC_GetFromSave is a wrapper
 * that forwards to it.  The layout below is read off the accessors and is
 * self-consistent to the byte from +0x00 to +0xE2; nothing here returns
 * sizeof, because the size getter of this block belongs to whatever file
 * precedes it, so the tail past +0xE2 is not pinned.
 *
 * Three things in it cost real time.
 *
 *  - MISC_GetMonRecord takes a **const** pointer, and that is the whole
 *    difference between it and the twelve-byte-longer version.  Its three
 *    bitfield reads come out of one `ldrb` in the original, and through a
 *    non-const pointer this compiler reloads the byte before each of the two
 *    later ones, because the intervening `str` through a `u32 *` may alias
 *    it.  See docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md.
 *  - MISC_SubGatePoints goes the other way and reads +0xE0 twice, once for the
 *    compare and once for the subtraction, with the address recomputed each
 *    time.  Nothing that leaves the field ordinary reproduces that: the
 *    compiler folds the two reads into one under every spelling of the
 *    branch, the arms, the cast and the pointer.  Declaring the field
 *    `volatile` is what keeps both reads, and it costs nothing in the getter
 *    and setter on either side of it, which touch it once each.
 *  - the pair at +0x50 is one `u64` read back as two words, the union of
 *    docs/idioms/long-long-aligns-to-four.md: MISC_GetLastTime returns the
 *    64-bit value and MISC_SetLastTime stores the two halves from two register
 *    arguments.
 */
struct MiscSave *MISC_GetFromSave(struct SaveControl *save)
{
    return MISC_GetBlock(save);
}

struct MiscSave *MISC_GetBlock(struct SaveControl *save)
{
    return SAVE_CONTROL_GetBlock(save, 0x34);
}

void MISC_SetInputFlag(struct MiscSave *beacon, u32 index, u8 value)
{
    beacon->inputFlags[index] = value;
}

u8 MISC_GetInputFlag(struct MiscSave *beacon, u32 index)
{
    return beacon->inputFlags[index];
}

void MISC_ClearInputFlags(struct MiscSave *beacon)
{
    MI_CpuFill8(beacon->inputFlags, 0, sizeof(beacon->inputFlags));
}

void MISC_SetMonRecord(struct MiscSave *misc, u16 species, u32 form, u32 isEgg, u32 gender)
{
    misc->species = species;
    misc->monRecord.form = form;
    misc->monRecord.isEgg = isEgg;
    misc->monRecord.gender = (gender == 1);
}

void MISC_GetMonRecord(const struct MiscSave *misc, u32 *species, u32 *form, u32 *isEgg, u32 *gender)
{
    *species = misc->species;
    *form = misc->monRecord.form;
    *isEgg = misc->monRecord.isEgg;
    *gender = misc->monRecord.gender;
}

u32 MISC_GetBestScore(struct MiscSave *beacon)
{
    return beacon->bestScore;
}

void MISC_SetBestScore(struct MiscSave *beacon, u32 score)
{
    beacon->bestScore = score;
}

u8 MISC_GetRank(struct MiscSave *beacon)
{
    return beacon->rank;
}

void MISC_SetRank(struct MiscSave *beacon, u32 rank)
{
    beacon->rank = rank;
}

u32 MISC_GetGreetCount(struct MiscSave *beacon)
{
    return beacon->greetCount;
}

u32 MISC_IncrementGreetCount(struct MiscSave *beacon)
{
    if (beacon->greetCount < 99999) {
        beacon->greetCount++;
    }
    return beacon->greetCount;
}

u32 MISC_GetThanksCount(struct MiscSave *beacon)
{
    return beacon->thanksCount;
}

u32 MISC_IncrementThanksCount(struct MiscSave *beacon)
{
    if (beacon->thanksCount < 99999) {
        beacon->thanksCount++;
    }
    return beacon->thanksCount;
}

u16 *MISC_GetGreetMessage(struct MiscSave *beacon)
{
    return beacon->greetMessage;
}

void MISC_SetGreetMessage(struct MiscSave *beacon, struct StrBuf *message)
{
    STRBUF_ToChars((struct Strbuf *)message, beacon->greetMessage, 9);
}

u16 *MISC_GetThanksMessage(struct MiscSave *beacon)
{
    return beacon->thanksMessage;
}

void MISC_SetThanksMessage(struct MiscSave *beacon, struct StrBuf *message)
{
    STRBUF_ToChars((struct Strbuf *)message, beacon->thanksMessage, 9);
}

u8 MISC_GetResearchRank(struct MiscSave *beacon)
{
    return beacon->mode;
}

void MISC_SetResearchRank(struct MiscSave *beacon, u8 mode)
{
    beacon->mode = mode;
}

u32 MISC_GetBadge(struct MiscSave *beacon, u32 bit)
{
    return (beacon->badges & (1 << bit)) != 0;
}

void MISC_SetBadge(struct MiscSave *beacon, u32 bit)
{
    beacon->badges |= 1 << bit;
}

u32 MISC_CountBadges(struct MiscSave *beacon)
{
    u32 count = 0;
    u32 bits;

    for (bits = beacon->badges; bits != 0; bits >>= 1) {
        if (bits & 1) {
            count++;
        }
    }
    return count;
}

u32 MISC_GetMoney(struct MiscSave *beacon)
{
    return beacon->money;
}

u32 MISC_AddMoney(struct MiscSave *beacon, u32 add)
{
    if (add > 9999999) {
        beacon->money = 9999999;
    } else {
        beacon->money += add;
    }
    if (beacon->money > 9999999) {
        beacon->money = 9999999;
    }
    return beacon->money;
}

u32 MISC_SubMoney(struct MiscSave *beacon, u32 sub)
{
    if (beacon->money < sub) {
        beacon->money = 0;
    } else {
        beacon->money -= sub;
    }
    return beacon->money;
}

void MISC_SetTeam(struct MiscSave *beacon, u32 index, const u16 *species)
{
    s32 i;

    for (i = 0; i < 6; i++) {
        beacon->teams[index].species[i] = species[i];
    }
}

void MISC_GetTeam(struct MiscSave *beacon, u32 index, u16 *species)
{
    s32 i;

    for (i = 0; i < 6; i++) {
        species[i] = beacon->teams[index].species[i];
    }
}

void MISC_SetSlotState(struct MiscSave *beacon, u32 slot, u8 state)
{
    beacon->slotStates |= (u8)(state << (slot * 2));
}

u8 MISC_GetSlotState(struct MiscSave *beacon, u32 slot)
{
    return (u8)((beacon->slotStates >> (slot * 2)) & 3);
}

u8 MISC_GetSlotStates(struct MiscSave *beacon)
{
    return beacon->slotStates;
}

void MISC_SetSlotStates(struct MiscSave *beacon, u8 states)
{
    beacon->slotStates = states;
}

u8 MISC_GetResearchMissionIndex(struct MiscSave *beacon)
{
    return beacon->entryCount;
}

void MISC_SetResearchMissionIndex(struct MiscSave *beacon, u8 count)
{
    beacon->entryCount = count;
}

int MISC_GetRecentId(struct MiscSave *beacon, u32 index)
{
    return beacon->recentIds[index];
}

void MISC_SetRecentId(struct MiscSave *beacon, u8 index, u8 id)
{
    beacon->recentIds[index] = id;
}

u16 MISC_GetRecentValue(struct MiscSave *beacon, u32 index)
{
    return beacon->recentValues[index];
}

void MISC_SetRecentValue(struct MiscSave *beacon, u32 index, int value)
{
    beacon->recentValues[index] = value;
}

void MISC_AddRecentValue(struct MiscSave *beacon, u8 index, int add)
{
    u32 value = beacon->recentValues[index];

    value += add;
    if (value > 0xFFFF) {
        value = 0xFFFF;
    }
    beacon->recentValues[index] = value;
}

u64 MISC_GetLastTime(struct MiscSave *beacon)
{
    return beacon->lastTime.value;
}

void MISC_SetLastTime(struct MiscSave *beacon, u32 lo, u32 hi)
{
    beacon->lastTime.half.lo = lo;
    beacon->lastTime.half.hi = hi;
}

void MISC_SetHashedId(struct MiscSave *beacon, s32 index, u32 value)
{
    if (index < 8) {
        beacon->hashedIds[index] = value;
    }
}

u32 MISC_GetHashedId(struct MiscSave *beacon, s32 index)
{
    if (index >= 8) {
        return 0;
    }
    return beacon->hashedIds[index];
}

u16 MISC_GetGatePoints(struct MiscSave *beacon)
{
    return beacon->gatePoints;
}

void MISC_SetGatePoints(struct MiscSave *beacon, u16 points)
{
    beacon->gatePoints = points;
}

void MISC_SubGatePoints(struct MiscSave *beacon, u16 sub)
{
    if (sub <= beacon->gatePoints) {
        beacon->gatePoints = beacon->gatePoints - sub;
    } else {
        beacon->gatePoints = 0;
    }
}

u8 MISC_GetRecorderFlag(struct MiscSave *beacon)
{
    return beacon->recorderFlag;
}

void MISC_SetRecorderFlag(struct MiscSave *beacon, u32 flag)
{
    beacon->recorderFlag = flag;
}
