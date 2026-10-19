/*
 * file:     beacon.c
 * unit:     yes
 * function: BEACON_GetSize, BEACON_Init, BEACON_GetFromSave, BEACON_GetBlock, BEACON_SetInputFlag, BEACON_GetInputFlag, BEACON_ClearInputFlags, BEACON_SetSelect, BEACON_GetSelect, BEACON_GetBestScore, BEACON_SetBestScore, BEACON_GetRank, BEACON_SetRank, BEACON_GetGreetCount, BEACON_IncrementGreetCount, BEACON_GetThanksCount, BEACON_IncrementThanksCount, BEACON_GetGreetMessage, BEACON_SetGreetMessage, BEACON_GetThanksMessage, BEACON_SetThanksMessage, BEACON_GetMode, BEACON_SetMode, BEACON_GetBadge, BEACON_SetBadge, BEACON_CountBadges, BEACON_GetMoney, BEACON_AddMoney, BEACON_SubMoney, BEACON_SetTeam, BEACON_GetTeam, BEACON_SetSlotState, BEACON_GetSlotState, BEACON_GetSlotStates, BEACON_SetSlotStates, BEACON_GetEntryCount, BEACON_SetEntryCount, BEACON_GetRecentId, BEACON_SetRecentId, BEACON_GetRecentValue, BEACON_SetRecentValue, BEACON_AddRecentValue, BEACON_GetLastTime, BEACON_SetLastTime, BEACON_SetHashedId, BEACON_GetHashedId, BEACON_GetGatePoints, BEACON_SetGatePoints, BEACON_SubGatePoints, BEACON_GetRecorderFlag, BEACON_SetRecorderFlag
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
struct BeaconSelect {
    u8 kind : 6;
    u8 enabled : 1;
    u8 isSingle : 1;
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

struct BeaconSave {
    u32 money;
    u32 badges;
    u16 selectId;
    struct BeaconSelect select;
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
    /* stand-in: volatile keeps the two reads of BEACON_SubGatePoints (compare, then
     * subtract); every ordinary spelling folds them into one load, and a
     * 16-bit bitfield changes the getter and setter. */
    volatile u16 gatePoints;
    u16 unusedHalf;
    u8  unusedTail[8];
};

extern void MI_CpuFill8(void *dest, u8 value, u32 size);

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *save, u32 blockId);

extern struct MsgData *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern u32 MSGDATA_Delete(struct MsgData *msg);

extern struct StrBuf *MSGDATA_AllocString(struct MsgData *msg, u32 msgIndex);

extern void STRBUF_ToChars(struct StrBuf *str, u16 *out, u32 maxLen);

extern void STRBUF_Delete(struct StrBuf *str);

u32 BEACON_GetSize(void);

void BEACON_Init(struct BeaconSave *beacon);

struct BeaconSave *BEACON_GetFromSave(struct SaveControl *save);

struct BeaconSave *BEACON_GetBlock(struct SaveControl *save);

void BEACON_SetInputFlag(struct BeaconSave *beacon, u32 index, u8 value);

u8 BEACON_GetInputFlag(struct BeaconSave *beacon, u32 index);

void BEACON_ClearInputFlags(struct BeaconSave *beacon);

void BEACON_SetSelect(struct BeaconSave *beacon, u16 id, u32 kind, u32 enabled, u32 single);

void BEACON_GetSelect(const struct BeaconSave *beacon, u32 *id, u32 *kind, u32 *enabled, u32 *single);

u32 BEACON_GetBestScore(struct BeaconSave *beacon);

void BEACON_SetBestScore(struct BeaconSave *beacon, u32 score);

u8 BEACON_GetRank(struct BeaconSave *beacon);

void BEACON_SetRank(struct BeaconSave *beacon, u32 rank);

u32 BEACON_GetGreetCount(struct BeaconSave *beacon);

u32 BEACON_IncrementGreetCount(struct BeaconSave *beacon);

u32 BEACON_GetThanksCount(struct BeaconSave *beacon);

u32 BEACON_IncrementThanksCount(struct BeaconSave *beacon);

u16 *BEACON_GetGreetMessage(struct BeaconSave *beacon);

void BEACON_SetGreetMessage(struct BeaconSave *beacon, struct StrBuf *message);

u16 *BEACON_GetThanksMessage(struct BeaconSave *beacon);

void BEACON_SetThanksMessage(struct BeaconSave *beacon, struct StrBuf *message);

u8 BEACON_GetMode(struct BeaconSave *beacon);

void BEACON_SetMode(struct BeaconSave *beacon, u8 mode);

u32 BEACON_GetBadge(struct BeaconSave *beacon, u32 bit);

void BEACON_SetBadge(struct BeaconSave *beacon, u32 bit);

u32 BEACON_CountBadges(struct BeaconSave *beacon);

u32 BEACON_GetMoney(struct BeaconSave *beacon);

u32 BEACON_AddMoney(struct BeaconSave *beacon, u32 add);

u32 BEACON_SubMoney(struct BeaconSave *beacon, u32 sub);

void BEACON_SetTeam(struct BeaconSave *beacon, u32 index, const u16 *species);

void BEACON_GetTeam(struct BeaconSave *beacon, u32 index, u16 *species);

void BEACON_SetSlotState(struct BeaconSave *beacon, u32 slot, u8 state);

u8 BEACON_GetSlotState(struct BeaconSave *beacon, u32 slot);

u8 BEACON_GetSlotStates(struct BeaconSave *beacon);

void BEACON_SetSlotStates(struct BeaconSave *beacon, u8 states);

u8 BEACON_GetEntryCount(struct BeaconSave *beacon);

void BEACON_SetEntryCount(struct BeaconSave *beacon, u8 count);

int BEACON_GetRecentId(struct BeaconSave *beacon, u32 index);

void BEACON_SetRecentId(struct BeaconSave *beacon, u8 index, u8 id);

u16 BEACON_GetRecentValue(struct BeaconSave *beacon, u32 index);

void BEACON_SetRecentValue(struct BeaconSave *beacon, u32 index, int value);

void BEACON_AddRecentValue(struct BeaconSave *beacon, u8 index, int add);

u64 BEACON_GetLastTime(struct BeaconSave *beacon);

void BEACON_SetLastTime(struct BeaconSave *beacon, u32 lo, u32 hi);

void BEACON_SetHashedId(struct BeaconSave *beacon, s32 index, u32 value);

u32 BEACON_GetHashedId(struct BeaconSave *beacon, s32 index);

u16 BEACON_GetGatePoints(struct BeaconSave *beacon);

void BEACON_SetGatePoints(struct BeaconSave *beacon, u16 points);

void BEACON_SubGatePoints(struct BeaconSave *beacon, u16 sub);

u8 BEACON_GetRecorderFlag(struct BeaconSave *beacon);

void BEACON_SetRecorderFlag(struct BeaconSave *beacon, u32 flag);

u32 BEACON_GetSize(void)
{
    return sizeof(struct BeaconSave);
}

void BEACON_Init(struct BeaconSave *beacon)
{
    struct MsgData *msg;
    struct StrBuf *greet;
    struct StrBuf *thanks;

    MI_CpuFill8(beacon, 0, sizeof(struct BeaconSave));
    BEACON_ClearInputFlags(beacon);
    beacon->bestScore = 0;
    msg = MSGDATA_CreateFromArchive(0, 3, 0x2f, 0x8007);
    greet = MSGDATA_AllocString(msg, 0x151);
    STRBUF_ToChars(greet, beacon->greetMessage, 9);
    STRBUF_Delete(greet);
    thanks = MSGDATA_AllocString(msg, 0x159);
    STRBUF_ToChars(thanks, beacon->thanksMessage, 9);
    STRBUF_Delete(thanks);
    MSGDATA_Delete(msg);
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
 *           BEACON_ClearInputFlags, BEACON_SetSelect, BEACON_GetSelect, BEACON_GetBestScore,
 *           BEACON_SetBestScore, BEACON_GetRank, BEACON_SetRank, BEACON_GetGreetCount,
 *           BEACON_IncrementGreetCount, BEACON_GetThanksCount, BEACON_IncrementThanksCount, BEACON_GetGreetMessage,
 *           BEACON_SetGreetMessage, BEACON_GetThanksMessage, BEACON_SetThanksMessage, BEACON_GetMode,
 *           BEACON_SetMode, BEACON_GetBadge, BEACON_SetBadge, BEACON_CountBadges,
 *           BEACON_GetMoney, BEACON_AddMoney, BEACON_SubMoney, BEACON_SetTeam,
 *           BEACON_GetTeam, BEACON_SetSlotState, BEACON_GetSlotState, BEACON_GetSlotStates,
 *           BEACON_SetSlotStates, BEACON_GetEntryCount, BEACON_SetEntryCount, BEACON_GetRecentId,
 *           BEACON_SetRecentId, BEACON_GetRecentValue, BEACON_SetRecentValue, BEACON_AddRecentValue,
 *           BEACON_GetLastTime, BEACON_SetLastTime, BEACON_SetHashedId, BEACON_GetHashedId,
 *           BEACON_GetGatePoints, BEACON_SetGatePoints, BEACON_SubGatePoints, BEACON_GetRecorderFlag,
 *           BEACON_SetRecorderFlag
 *
 * 780 bytes, 0x0200C0E8..0x0200C3F4, 49 functions, forty-four of which carry
 * no label in the generated listing: the file is almost entirely accessors
 * and none of them saves lr.
 *
 * The object is the save block with id 0x34: BEACON_GetBlock is the whole of
 * its lookup, `SAVE_CONTROL_GetBlock(sys, 0x34)`, and BEACON_GetFromSave is a wrapper
 * that forwards to it.  The layout below is read off the accessors and is
 * self-consistent to the byte from +0x00 to +0xE2; nothing here returns
 * sizeof, because the size getter of this block belongs to whatever file
 * precedes it, so the tail past +0xE2 is not pinned.
 *
 * Three things in it cost real time.
 *
 *  - BEACON_GetSelect takes a **const** pointer, and that is the whole
 *    difference between it and the twelve-byte-longer version.  Its three
 *    bitfield reads come out of one `ldrb` in the original, and through a
 *    non-const pointer this compiler reloads the byte before each of the two
 *    later ones, because the intervening `str` through a `u32 *` may alias
 *    it.  See docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md.
 *  - BEACON_SubGatePoints goes the other way and reads +0xE0 twice, once for the
 *    compare and once for the subtraction, with the address recomputed each
 *    time.  Nothing that leaves the field ordinary reproduces that: the
 *    compiler folds the two reads into one under every spelling of the
 *    branch, the arms, the cast and the pointer.  Declaring the field
 *    `volatile` is what keeps both reads, and it costs nothing in the getter
 *    and setter on either side of it, which touch it once each.
 *  - the pair at +0x50 is one `u64` read back as two words, the union of
 *    docs/idioms/long-long-aligns-to-four.md: BEACON_GetLastTime returns the
 *    64-bit value and BEACON_SetLastTime stores the two halves from two register
 *    arguments.
 */
struct BeaconSave *BEACON_GetFromSave(struct SaveControl *save)
{
    return BEACON_GetBlock(save);
}

struct BeaconSave *BEACON_GetBlock(struct SaveControl *save)
{
    return SAVE_CONTROL_GetBlock(save, 0x34);
}

void BEACON_SetInputFlag(struct BeaconSave *beacon, u32 index, u8 value)
{
    beacon->inputFlags[index] = value;
}

u8 BEACON_GetInputFlag(struct BeaconSave *beacon, u32 index)
{
    return beacon->inputFlags[index];
}

void BEACON_ClearInputFlags(struct BeaconSave *beacon)
{
    MI_CpuFill8(beacon->inputFlags, 0, sizeof(beacon->inputFlags));
}

void BEACON_SetSelect(struct BeaconSave *beacon, u16 id, u32 kind, u32 enabled, u32 single)
{
    beacon->selectId = id;
    beacon->select.kind = kind;
    beacon->select.enabled = enabled;
    beacon->select.isSingle = (single == 1);
}

void BEACON_GetSelect(const struct BeaconSave *beacon, u32 *id, u32 *kind, u32 *enabled, u32 *single)
{
    *id = beacon->selectId;
    *kind = beacon->select.kind;
    *enabled = beacon->select.enabled;
    *single = beacon->select.isSingle;
}

u32 BEACON_GetBestScore(struct BeaconSave *beacon)
{
    return beacon->bestScore;
}

void BEACON_SetBestScore(struct BeaconSave *beacon, u32 score)
{
    beacon->bestScore = score;
}

u8 BEACON_GetRank(struct BeaconSave *beacon)
{
    return beacon->rank;
}

void BEACON_SetRank(struct BeaconSave *beacon, u32 rank)
{
    beacon->rank = rank;
}

u32 BEACON_GetGreetCount(struct BeaconSave *beacon)
{
    return beacon->greetCount;
}

u32 BEACON_IncrementGreetCount(struct BeaconSave *beacon)
{
    if (beacon->greetCount < 99999) {
        beacon->greetCount++;
    }
    return beacon->greetCount;
}

u32 BEACON_GetThanksCount(struct BeaconSave *beacon)
{
    return beacon->thanksCount;
}

u32 BEACON_IncrementThanksCount(struct BeaconSave *beacon)
{
    if (beacon->thanksCount < 99999) {
        beacon->thanksCount++;
    }
    return beacon->thanksCount;
}

u16 *BEACON_GetGreetMessage(struct BeaconSave *beacon)
{
    return beacon->greetMessage;
}

void BEACON_SetGreetMessage(struct BeaconSave *beacon, struct StrBuf *message)
{
    STRBUF_ToChars(message, beacon->greetMessage, 9);
}

u16 *BEACON_GetThanksMessage(struct BeaconSave *beacon)
{
    return beacon->thanksMessage;
}

void BEACON_SetThanksMessage(struct BeaconSave *beacon, struct StrBuf *message)
{
    STRBUF_ToChars(message, beacon->thanksMessage, 9);
}

u8 BEACON_GetMode(struct BeaconSave *beacon)
{
    return beacon->mode;
}

void BEACON_SetMode(struct BeaconSave *beacon, u8 mode)
{
    beacon->mode = mode;
}

u32 BEACON_GetBadge(struct BeaconSave *beacon, u32 bit)
{
    return (beacon->badges & (1 << bit)) != 0;
}

void BEACON_SetBadge(struct BeaconSave *beacon, u32 bit)
{
    beacon->badges |= 1 << bit;
}

u32 BEACON_CountBadges(struct BeaconSave *beacon)
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

u32 BEACON_GetMoney(struct BeaconSave *beacon)
{
    return beacon->money;
}

u32 BEACON_AddMoney(struct BeaconSave *beacon, u32 add)
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

u32 BEACON_SubMoney(struct BeaconSave *beacon, u32 sub)
{
    if (beacon->money < sub) {
        beacon->money = 0;
    } else {
        beacon->money -= sub;
    }
    return beacon->money;
}

void BEACON_SetTeam(struct BeaconSave *beacon, u32 index, const u16 *species)
{
    s32 i;

    for (i = 0; i < 6; i++) {
        beacon->teams[index].species[i] = species[i];
    }
}

void BEACON_GetTeam(struct BeaconSave *beacon, u32 index, u16 *species)
{
    s32 i;

    for (i = 0; i < 6; i++) {
        species[i] = beacon->teams[index].species[i];
    }
}

void BEACON_SetSlotState(struct BeaconSave *beacon, u32 slot, u8 state)
{
    beacon->slotStates |= (u8)(state << (slot * 2));
}

u8 BEACON_GetSlotState(struct BeaconSave *beacon, u32 slot)
{
    return (u8)((beacon->slotStates >> (slot * 2)) & 3);
}

u8 BEACON_GetSlotStates(struct BeaconSave *beacon)
{
    return beacon->slotStates;
}

void BEACON_SetSlotStates(struct BeaconSave *beacon, u8 states)
{
    beacon->slotStates = states;
}

u8 BEACON_GetEntryCount(struct BeaconSave *beacon)
{
    return beacon->entryCount;
}

void BEACON_SetEntryCount(struct BeaconSave *beacon, u8 count)
{
    beacon->entryCount = count;
}

int BEACON_GetRecentId(struct BeaconSave *beacon, u32 index)
{
    return beacon->recentIds[index];
}

void BEACON_SetRecentId(struct BeaconSave *beacon, u8 index, u8 id)
{
    beacon->recentIds[index] = id;
}

u16 BEACON_GetRecentValue(struct BeaconSave *beacon, u32 index)
{
    return beacon->recentValues[index];
}

void BEACON_SetRecentValue(struct BeaconSave *beacon, u32 index, int value)
{
    beacon->recentValues[index] = value;
}

void BEACON_AddRecentValue(struct BeaconSave *beacon, u8 index, int add)
{
    u32 value = beacon->recentValues[index];

    value += add;
    if (value > 0xFFFF) {
        value = 0xFFFF;
    }
    beacon->recentValues[index] = value;
}

u64 BEACON_GetLastTime(struct BeaconSave *beacon)
{
    return beacon->lastTime.value;
}

void BEACON_SetLastTime(struct BeaconSave *beacon, u32 lo, u32 hi)
{
    beacon->lastTime.half.lo = lo;
    beacon->lastTime.half.hi = hi;
}

void BEACON_SetHashedId(struct BeaconSave *beacon, s32 index, u32 value)
{
    if (index < 8) {
        beacon->hashedIds[index] = value;
    }
}

u32 BEACON_GetHashedId(struct BeaconSave *beacon, s32 index)
{
    if (index >= 8) {
        return 0;
    }
    return beacon->hashedIds[index];
}

u16 BEACON_GetGatePoints(struct BeaconSave *beacon)
{
    return beacon->gatePoints;
}

void BEACON_SetGatePoints(struct BeaconSave *beacon, u16 points)
{
    beacon->gatePoints = points;
}

void BEACON_SubGatePoints(struct BeaconSave *beacon, u16 sub)
{
    if (sub <= beacon->gatePoints) {
        beacon->gatePoints = beacon->gatePoints - sub;
    } else {
        beacon->gatePoints = 0;
    }
}

u8 BEACON_GetRecorderFlag(struct BeaconSave *beacon)
{
    return beacon->recorderFlag;
}

void BEACON_SetRecorderFlag(struct BeaconSave *beacon, u32 flag)
{
    beacon->recorderFlag = flag;
}
