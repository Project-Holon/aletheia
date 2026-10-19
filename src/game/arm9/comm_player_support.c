/*
 * file:     comm_player_support.c
 * unit:     yes
 * function: COMM_PLAYER_SUPPORT_Create, COMM_PLAYER_SUPPORT_Delete, COMM_PLAYER_SUPPORT_Init, COMM_PLAYER_SUPPORT_SetModeAndCurrent, COMM_PLAYER_SUPPORT_GetCurrent, COMM_PLAYER_SUPPORT_GetMode, COMM_PLAYER_SUPPORT_SavePreviousAndSuspend, COMM_PLAYER_SUPPORT_StashMode, COMM_PLAYER_SUPPORT_HasSavedMode, COMM_PLAYER_SUPPORT_GetActiveRecord, COMM_PLAYER_SUPPORT_GetInfoCode, COMM_PLAYER_SUPPORT_IsSeasonChanged, COMM_PLAYER_SUPPORT_GetSeasonFromClock, COMM_PLAYER_SUPPORT_NextSeason, COMM_PLAYER_SUPPORT_PrevSeason, COMM_PLAYER_SUPPORT_SetSeason, COMM_PLAYER_SUPPORT_FindPeerRecord, COMM_PLAYER_SUPPORT_GetRecordFieldPtr, COMM_PLAYER_SUPPORT_GetRecordField
 * address:  0x0202E770
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
 *   GFL_HEAP_Alloc    0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   comm_player_support_File     0x020A77EC  data
 *   MI_CpuFill8  0x02082BCC  arm
 *   MYSTATUS_Init  0x020084A0  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetAreaSlotFlag  0x02158468  thumb
 *   GF_STANDARD_GetCachedDate  0x0203F4E4  arm
 *   GAME_DATA_SetSeason  0x0201298C  thumb
 *   MYSTATUS_GetName  0x020084F4  thumb
 *   MYSTATUS_GetIdLow16  0x02008534  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   WIFILIST_FindFriendByStatus  0x02009D1C  thumb
 */
#include "comm_player_support_shared_types.h"

struct PlayerInfo;

struct PlayerLookup;

/*
 * COMM_PLAYER_SUPPORT state object (0x4c bytes, allocated by
 * COMM_PLAYER_SUPPORT_Create): a mode word, the mode it replaced, a stashed mode, and
 * two player records, the current one and the one saved before a switch.
 */
struct CommPlayerSupport {
    u32 mode;                       /* 0x00 */
    u32 prevMode;                   /* 0x04, set by COMM_PLAYER_SUPPORT_SavePreviousAndSuspend */
    u32 stashedMode;                /* 0x08, set by COMM_PLAYER_SUPPORT_StashMode */
    struct PlayerRecord current;    /* 0x0c */
    struct PlayerRecord previous;   /* 0x2c */
};

/*
 * A record plus the three 6-byte addresses (MAC addresses of the peers it
 * has met) that follow it at +0x22.
 */
struct PeerBook {
    struct PlayerRecord record;     /* 0x00 */
    u8 reserved20[2];               /* 0x20 */
    u8 macs[3][6];                  /* 0x22 */
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *p);

extern void MI_CpuFill8(void *p, u32 value, u32 size);
struct MyStatus;

extern void MYSTATUS_Init(struct MyStatus *mystatus);
struct GameSystem;
struct GameComm;

extern struct GameComm *GAMESYSTEM_GetGameComm(struct GameSystem *gameSystem);

extern int INTRUDE_COMM_GetAreaSlotFlag(struct GameComm *comm);

extern void GF_STANDARD_GetCachedDate(struct RtcDate *date);

extern u8 GAME_DATA_SetSeason(s32 handle, u8 value);
struct GameData;

extern int GAME_DATA_GetIntrudeCount(struct GameData *gd);

extern u8 GAME_DATA_GetSeason(struct GameData *gd);
struct WifiList;

extern int WIFILIST_FindFriendByStatus(struct WifiList *list, struct MyStatus *status, u32 *outSlot);

extern void *MYSTATUS_GetName(void *mystatus);

extern u16 MYSTATUS_GetIdLow16(struct MyStatus *mystatus);

struct CommPlayerSupport *COMM_PLAYER_SUPPORT_Create(u32 heapId);

void COMM_PLAYER_SUPPORT_Delete(void *support);

void COMM_PLAYER_SUPPORT_Init(struct CommPlayerSupport *support);

void COMM_PLAYER_SUPPORT_SetModeAndCurrent(struct CommPlayerSupport *support, u32 mode, const struct PlayerRecord *record);

struct PlayerRecord *COMM_PLAYER_SUPPORT_GetCurrent(struct CommPlayerSupport *support);

u32 COMM_PLAYER_SUPPORT_GetMode(struct CommPlayerSupport *support);

void COMM_PLAYER_SUPPORT_SavePreviousAndSuspend(struct CommPlayerSupport *support);

void COMM_PLAYER_SUPPORT_StashMode(struct CommPlayerSupport *support);

int COMM_PLAYER_SUPPORT_HasSavedMode(const struct CommPlayerSupport *support);

struct PlayerRecord *COMM_PLAYER_SUPPORT_GetActiveRecord(struct CommPlayerSupport *support);

int COMM_PLAYER_SUPPORT_GetInfoCode(struct PlayerInfo *info);

int COMM_PLAYER_SUPPORT_IsSeasonChanged(struct PlayerInfo *info, u16 *outStored, u16 *outCurrent);

u8 COMM_PLAYER_SUPPORT_GetSeasonFromClock(void);

u8 COMM_PLAYER_SUPPORT_NextSeason(u8 season);

u8 COMM_PLAYER_SUPPORT_PrevSeason(s32 season);

u8 COMM_PLAYER_SUPPORT_SetSeason(s32 handle, s32 value);

int COMM_PLAYER_SUPPORT_FindPeerRecord(const struct PeerBook *book, struct PlayerLookup *lookup, const u8 *mac);

u16 *COMM_PLAYER_SUPPORT_GetRecordFieldPtr(const struct PlayerRecord *record);

u16 COMM_PLAYER_SUPPORT_GetRecordField(const struct PlayerRecord *record);

extern const char comm_player_support_File[];

struct CommPlayerSupport *COMM_PLAYER_SUPPORT_Create(u32 heapId)
{
    struct CommPlayerSupport *support = GFL_HEAP_Alloc(heapId, 0x4c, 1, comm_player_support_File, 0x2c);

    COMM_PLAYER_SUPPORT_Init(support);
    return support;
}

/*
 * A pool-word-and-bx tail call into the ARM deallocator
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md): eight bytes, no
 * prologue, no label in the listing. The destructor half of the
 * constructor at 0x0202E770, which allocates the same object.
 */
void COMM_PLAYER_SUPPORT_Delete(void *support)
{
    GFL_HEAP_Free(support);
}

void COMM_PLAYER_SUPPORT_Init(struct CommPlayerSupport *support)
{
    MI_CpuFill8(support, 0, 0x4c);
    support->mode = 0;
    support->prevMode = 0;
    support->stashedMode = 0;
    MYSTATUS_Init((struct MyStatus *)(&support->current));
    MYSTATUS_Init((struct MyStatus *)(&support->previous));
}

/* Sets the mode word and copies a 32-byte record into the current slot. */
void COMM_PLAYER_SUPPORT_SetModeAndCurrent(struct CommPlayerSupport *support, u32 mode, const struct PlayerRecord *record)
{
    support->mode = mode;
    support->current = *record;
}

/*
 * Returns the current record.  Leaf accessor matched to give overlay call
 * sites a `matched` witness.
 */
struct PlayerRecord *COMM_PLAYER_SUPPORT_GetCurrent(struct CommPlayerSupport *support)
{
    return &support->current;
}

/* Witness leaf for ov093 BTL_SERVER_FLOW_ProcPlayerSupportHeal (tiny arm9 leaf). */
u32 COMM_PLAYER_SUPPORT_GetMode(struct CommPlayerSupport *support) { return support->mode; }

/* Remembers the mode and the current record, then enters mode 3. */
void COMM_PLAYER_SUPPORT_SavePreviousAndSuspend(struct CommPlayerSupport *support)
{
    support->prevMode = support->mode;
    support->previous = support->current;
    support->mode = 3;
}

/*
 * Moves the mode into the stashed slot and clears it.  Witness for the call
 * in ov010 EVENT_BATTLE_ProcBattleTask.
 */
void COMM_PLAYER_SUPPORT_StashMode(struct CommPlayerSupport *support)
{
    support->stashedMode = support->mode;
    support->mode = 0;
}

/* Nonzero if either the previous mode or the stashed mode is set. */
int COMM_PLAYER_SUPPORT_HasSavedMode(const struct CommPlayerSupport *support)
{
    if (support->prevMode != 0 || support->stashedMode != 0)
        return 1;
    return 0;
}

/* The saved record when a previous mode is set, else the current record. */
struct PlayerRecord *COMM_PLAYER_SUPPORT_GetActiveRecord(struct CommPlayerSupport *support)
{
    if (support->prevMode != 0)
        return &support->previous;
    return &support->current;
}

int COMM_PLAYER_SUPPORT_GetInfoCode(struct PlayerInfo *info)
{
    return INTRUDE_COMM_GetAreaSlotFlag(GAMESYSTEM_GetGameComm((struct GameSystem *)info));
}

/*
 * Reads the stored season of the record into *outStored and the season to
 * compare against into *outCurrent; returns 1 when they differ.  A fixed
 * record always reports 0.
 */
int COMM_PLAYER_SUPPORT_IsSeasonChanged(struct PlayerInfo *info, u16 *outStored, u16 *outCurrent)
{
    int isFixed;
    int stored;
    int current;

    isFixed = GAME_DATA_GetIntrudeCount((struct GameData *)info);
    if ((unsigned int)isFixed != 0) {
        stored = GAME_DATA_GetSeason((struct GameData *)info);
        *outStored = (unsigned short)stored;
        *outCurrent = *outStored;
        return 0;
    } else {
        stored = GAME_DATA_GetSeason((struct GameData *)info);
        *outStored = (unsigned short)stored;
        current = COMM_PLAYER_SUPPORT_GetSeasonFromClock();
        *outCurrent = (unsigned short)current;
        if (*outStored != *outCurrent) {
            return 1;
        } else {
            return 0;
        }
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Four small season helpers. COMM_PLAYER_SUPPORT_GetSeasonFromClock asks the ARM clock getter for a
 * 0x10-byte date and reduces its month to a two-bit season;
 * COMM_PLAYER_SUPPORT_NextSeason and COMM_PLAYER_SUPPORT_PrevSeason step that value forwards and backwards
 * around the same four-element cycle.
 *
 * The `lsrs #0x1F` / `lsls #0x1E` / `subs` / `rors #0x1E` quartet in the
 * two steppers is a signed `% 4` and nothing else: `& 3` is a two
 * instruction `movs`/`ands`, which is exactly what COMM_PLAYER_SUPPORT_GetSeasonFromClock uses at
 * the top, and `/ 4` carries a different rounding correction. Both
 * spellings appear four instructions apart in the same 80 bytes, so the
 * pair of them pins the signedness of each operand independently.
 *
 * The `lsls #0x18` / `lsrs #0x18` at the end of all three is the `(u8)`
 * return type.
 *
 * COMM_PLAYER_SUPPORT_SetSeason is a twelve byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) that narrows its
 * second argument to `u8` on the way through.
 */
u8 COMM_PLAYER_SUPPORT_GetSeasonFromClock(void)
{
    struct RtcDate date;

    GF_STANDARD_GetCachedDate(&date);
    return (u8)((date.month - 1) & 3);
}

u8 COMM_PLAYER_SUPPORT_NextSeason(u8 season)
{
    return (u8)((season + 1) % 4);
}

u8 COMM_PLAYER_SUPPORT_PrevSeason(s32 season)
{
    return (u8)((season + 3) % 4);
}

u8 COMM_PLAYER_SUPPORT_SetSeason(s32 handle, s32 value)
{
    return GAME_DATA_SetSeason(handle, (u8)value);
}

/*
 * Matches a six-byte address against the three-slot address table of the
 * book (six bytes apart).  Both loop counters are `unsigned char` - the
 * lsls 0x18 / lsrs 0x18 pair after each increment is the narrowing, and the
 * comparisons are `blo`, so signed ints give `blt` instead.
 *
 * Do NOT bind the slot base to a local pointer: writing the inner compare
 * through a hoisted base makes the compiler move `adds r4, book, i*6` ahead
 * of the ok/j initialisers and differs by six bytes.  Indexing the table
 * inside the compare leaves the hoist where the original has it (after
 * `movs r6,#1` and `movs r3,#0`).
 *
 * EXACT*: the compared extent ran long by the follower's padding - the
 * follower at 0x0202E930 is a two-halfword `ldr r3,[pc]; bx r3`
 * long-branch veneer with no label of its own.
 */
int COMM_PLAYER_SUPPORT_FindPeerRecord(const struct PeerBook *book, struct PlayerLookup *lookup, const u8 *mac)
{
    unsigned char slot;
    unsigned char byte;

    if (lookup == 0) {
        return 0;
    }
    for (slot = 0; slot < 3; slot++) {
        int matches = 1;

        for (byte = 0; byte < 6; byte++) {
            if (book->macs[slot][byte] != mac[byte]) {
                matches = 0;
                break;
            }
        }
        if (matches == 1) {
            return WIFILIST_FindFriendByStatus((struct WifiList *)lookup, (struct MyStatus *)(&book->record), 0);
        }
    }
    return 0;
}

/*
 * A forwarding leaf after COMM_PLAYER_SUPPORT_FindPeerRecord's pop: a pool-word tail call to
 * MYSTATUS_GetName (the u16 pointer accessor), the caller's argument passed
 * through untouched ("ldr r3, [pc]; bx r3").  Called from the overlays only.
 */
u16 *COMM_PLAYER_SUPPORT_GetRecordFieldPtr(const struct PlayerRecord *record)
{
    return MYSTATUS_GetName((void *)record);
}

/* Forwarding leaf: pool-word tail call to MYSTATUS_GetIdLow16 (the u16 getter). */
u16 COMM_PLAYER_SUPPORT_GetRecordField(const struct PlayerRecord *record)
{
    return MYSTATUS_GetIdLow16((struct MyStatus *)record);
}
