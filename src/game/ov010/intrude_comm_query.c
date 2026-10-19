/*
 * file:     intrude_comm_query.c
 * unit:     yes
 * function: INTRUDE_COMM_CheckEntryAllowed, INTRUDE_COMM_GetWorkIfRunning, INTRUDE_COMM_GetPlayerNetId, INTRUDE_COMM_TogglePeerFlags, GAME_DATA_GetBattleRecSlotByNetId, GAME_DATA_GetMyStatusByNetId, INTRUDE_COMM_GetMemberEntry, GAME_DATA_GetIntrudeIdByte, INTRUDE_COMM_GetUnionInfoReceived, INTRUDE_COMM_GetReturnSlots, INTRUDE_COMM_GetAreaOwnerVersion, INTRUDE_COMM_GetAreaSlotFlag, INTRUDE_COMM_IsStepToOwnArea, INTRUDE_COMM_NormalizeVersion, INTRUDE_COMM_GetAreaOwnerVersionClass, INTRUDE_COMM_IsListedId, INTRUDE_COMM_HasUnlockFlags, INTRUDE_COMM_IsWarnedWithoutRequest, INTRUDE_COMM_GetVisitProgress, INTRUDE_COMM_SetCompleted, INTRUDE_COMM_GetRequestState, INTRUDE_COMM_CountEventPeers, INTRUDE_COMM_GetRequesterStatus, INTRUDE_COMM_IsSessionEndPending, INTRUDE_COMM_ClearHoldMode
 * address:  0x02158318
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from delivery_irc.c by tools/splitfile.py.
 *
 * symbols:
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   GAME_COMM_GetCounter  0x0202648C  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_IsTransition  0x02026460  thumb
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   GAME_DATA_GetLastBattleRecSlot   0x020127B8  thumb
 *   GAME_DATA_GetBattleRecSlot   0x020127AC  thumb
 *   GAME_DATA_GetPlayerStatus   0x02012950  thumb
 *   GAME_DATA_GetIntrudeId   0x02012B80  thumb
 *   MYSTATUS_GetAvatarId 0x0200855C thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   GAME_DATA_GetSlotFlag  0x02012B98  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_GetMapMode  0x0201444C  thumb
 *   sIntrudeListedIds 0x021700AC data a2
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   sIntrudeUnlockFlags 0x021700A8 data a2
 *   INTRUDE_COMM_IsSessionActive  0x02175B14  thumb
 *   INTRUDE_COMM_IsRequestFromSelf  0x02176258  thumb
 *   INTRUDE_COMM_GetRequesterNetId  0x02176230  thumb
 *   MYSTATUS_NameToStrbuf  0x02008500  thumb
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 */
#include "delivery_irc_shared_types.h"
#include "mystery_gift_mon_shared_types.h"
typedef signed char s8;

typedef short s16;

typedef int s32;

typedef unsigned long long u64;

#include "../ov011/intrude_comm_types.h"

/* Opaque here: only the accessors in arm9 game_beacon.c and game_data.c read these. */
typedef struct GameComm GameComm;

struct EventWork;

struct BattleRecSlot;

extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);

extern u32 MYSTATUS_GetId(const struct MyStatus *status);

extern GameComm *GAMESYSTEM_GetGameComm(struct GameSystem *gameSystem);

extern struct GameData *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);

extern int GAME_DATA_GetIntrudeCount(const struct GameData *gameData);

extern u32 GAME_COMM_GetCounter(GameComm *comm);

extern IntrudeCommSys *GAME_COMM_GetWork(GameComm *comm);

extern u32 GFL_NET_ERR_GetErrorLevel(void);

extern u32 GAME_COMM_GetKind(GameComm *comm);

extern u32 GAME_COMM_IsTransition(GameComm *comm);

extern struct GameData *GAME_COMM_GetGameData(GameComm *comm);

extern u8 GAME_DATA_GetExitMode(const struct GameData *gameData);

extern struct BattleRecSlot *GAME_DATA_GetLastBattleRecSlot(struct GameData *gameData);

extern struct BattleRecSlot *GAME_DATA_GetBattleRecSlot(struct GameData *gameData, u32 netId);

extern struct MyStatus *GAME_DATA_GetPlayerStatus(struct GameData *gameData, u32 netId);

extern u8 GAME_DATA_GetIntrudeId(const struct GameData *gameData);

extern u8 MYSTATUS_GetAvatarId(const struct MyStatus *status);

extern u8 GAME_DATA_GetSeason(const struct GameData *gameData);

extern u8 GAME_DATA_GetSlotFlag(const struct GameData *gameData, u32 slot);

extern void *GAME_DATA_GetMoveModelSys(const struct GameData *gameData);

extern u32 FIELD_STATUS_GetMapMode(void *fieldStatus);

extern struct EventWork *GAME_DATA_GetEventWork(const struct GameData *gameData);

extern u32 ZONEDATA_CheckEventFlag(struct EventWork *eventWork, int flag);

extern int INTRUDE_COMM_IsSessionActive(IntrudeSession *session);

extern int INTRUDE_COMM_IsRequestFromSelf(IntrudeCommSys *work);

extern int INTRUDE_COMM_GetRequesterNetId(IntrudeCommSys *work, IntrudeSession *session);

extern void MYSTATUS_NameToStrbuf(const struct MyStatus *src, struct MyStatus *dst);

extern int GFL_NET_IsSessionNull(void);

int INTRUDE_COMM_CheckEntryAllowed(struct GameSystem *gameSystem);

IntrudeCommSys *INTRUDE_COMM_GetWorkIfRunning(GameComm *comm);

int INTRUDE_COMM_GetPlayerNetId(GameComm *comm);

int INTRUDE_COMM_TogglePeerFlags(IntrudeCommSys *work, int mask, int unused);

struct BattleRecSlot *GAME_DATA_GetBattleRecSlotByNetId(struct GameData *gameData, u32 netId);

struct MyStatus *GAME_DATA_GetMyStatusByNetId(struct GameData *gameData, u32 netId);

IntrudeMemberEntry *INTRUDE_COMM_GetMemberEntry(IntrudeCommSys *work, int index);

u8 GAME_DATA_GetIntrudeIdByte(struct GameData *gameData);

u8 INTRUDE_COMM_GetUnionInfoReceived(IntrudeCommSys *work);

void *INTRUDE_COMM_GetReturnSlots(IntrudeCommSys *work);

int INTRUDE_COMM_GetAreaOwnerVersion(GameComm *comm);

int INTRUDE_COMM_GetAreaSlotFlag(GameComm *comm);

int INTRUDE_COMM_IsStepToOwnArea(GameComm *comm, struct GameData *gameData, int stepKind);

int INTRUDE_COMM_NormalizeVersion(int version, u32 trainerId);

int INTRUDE_COMM_GetAreaOwnerVersionClass(GameComm *comm, struct GameData *gameData);

int INTRUDE_COMM_IsListedId(u16 value);

int INTRUDE_COMM_HasUnlockFlags(struct GameData *gameData);

int INTRUDE_COMM_IsWarnedWithoutRequest(IntrudeCommSys *work);

int INTRUDE_COMM_GetVisitProgress(GameComm *comm);

void INTRUDE_COMM_SetCompleted(GameComm *comm);

int INTRUDE_COMM_GetRequestState(GameComm *comm);

int INTRUDE_COMM_CountEventPeers(GameComm *comm);

int INTRUDE_COMM_GetRequesterStatus(GameComm *comm, struct MyStatus *out);

int INTRUDE_COMM_IsSessionEndPending(GameComm *comm, int unused);

void INTRUDE_COMM_ClearHoldMode(GameComm *comm);

extern const u16 sIntrudeListedIds[61];

extern const u16 sIntrudeUnlockFlags[2];

/*
 * Returns 0 while the game data has exactly one visit count and the
 * game comm counter is nonzero, else 1.
 */
int INTRUDE_COMM_CheckEntryAllowed(struct GameSystem *gameSystem)
{
    GameComm *comm = GAMESYSTEM_GetGameComm(gameSystem);
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);

    if (GAME_DATA_GetIntrudeCount(gameData) == 1 && GAME_COMM_GetCounter(comm) != 0)
        return 0;
    return 1;
}

/*
 * The intrude comm work of the game comm, or 0 unless the game comm runs
 * kind 2 outside a transition from kind 1 and the work exists.
 */
IntrudeCommSys *INTRUDE_COMM_GetWorkIfRunning(GameComm *comm)
{
    IntrudeCommSys *work = GAME_COMM_GetWork(comm);

    if (GFL_NET_ERR_GetErrorLevel() != 0 || GAME_COMM_GetKind(comm) != 2 || GAME_COMM_IsTransition(comm) == 1 || work == 0)
        return 0;
    return work;
}

int INTRUDE_COMM_GetPlayerNetId(GameComm *comm)
{
    IntrudeCommSys *work = INTRUDE_COMM_GetWorkIfRunning(comm);

    if (work == 0) {
        return GAME_DATA_GetExitMode(GAME_COMM_GetGameData(comm));
    }
    return work->ownNetId;
}

/*
 * When one of the mask bits is set in the 2-bit peer flags, flips the low
 * bit of the flags and answers 1.
 */
int INTRUDE_COMM_TogglePeerFlags(IntrudeCommSys *work, int mask, int unused)
{
    u8 flags = work->peerFlags;

    if (mask & flags) {
        work->peerFlags ^= 1;
        return 1;
    }
    return 0;
}

/*
 * The battle record slot of a net ID: the last-battle slot for the own net
 * ID, the per-ID slot for any other.
 */
struct BattleRecSlot *GAME_DATA_GetBattleRecSlotByNetId(struct GameData *gameData, u32 netId)
{
    if (GAME_DATA_GetExitMode(gameData) == netId)
        return GAME_DATA_GetLastBattleRecSlot(gameData);

    return GAME_DATA_GetBattleRecSlot(gameData, netId);
}

/*
 * The MyStatus of a net ID: the own status for the own net ID, the player
 * status of the net ID for any other.
 */
struct MyStatus *GAME_DATA_GetMyStatusByNetId(struct GameData *gameData, u32 netId)
{
    if (GAME_DATA_GetExitMode(gameData) == netId)
        return GAME_DATA_GetMyStatus(gameData);

    return GAME_DATA_GetPlayerStatus(gameData, netId);
}

/*
 * Address of the member entry (0x28 bytes) of the session at index.
 */
IntrudeMemberEntry *INTRUDE_COMM_GetMemberEntry(IntrudeCommSys *work, int index)
{
    return &work->session.members[index];
}

/*
 * The net ID of the player whose area is visited, as a byte.
 */
u8 GAME_DATA_GetIntrudeIdByte(struct GameData *gameData)
{
    return (u8)(unsigned)GAME_DATA_GetIntrudeId(gameData);
}

/*
 * Unlabelled leaf (no lr save, so disasm.py prints it inside the extent of
 * GAME_DATA_GetIntrudeIdByte); sole blocker of ov018 INTRUDE_SUBDISP_Update. Followed by another
 * unlabelled leaf at 0x02158434.
 */
u8 INTRUDE_COMM_GetUnionInfoReceived(IntrudeCommSys *work)
{
    return work->unionInfoReceived;
}

/*
 * Unlabelled Thumb leaf (no lr save, prints as .word data in the listing),
 * called from ov020 FIELD_WFBC_DATA_LOCAL_CreatePersonTalkEvent.
 */
void *INTRUDE_COMM_GetReturnSlots(IntrudeCommSys *work)
{
    return work->returnSlots;
}

/*
 * Version code (20 or 21) of the owner of the visited area. Answers 21
 * when no visit is running.
 *
 * extent: Two zero alignment bytes at 0x02158466 precede 0x02158468.
 * lever: A named u8 id truncates the result in r0 before preparing r1.
 */
int INTRUDE_COMM_GetAreaOwnerVersion(GameComm *comm)
{
    struct GameData *gameData = GAME_COMM_GetGameData(comm);
    u8 areaOwnerId;

    if (GAME_DATA_GetIntrudeCount(gameData) == 0)
        return 21;
    areaOwnerId = (int)GAME_DATA_GetIntrudeId(gameData);
    return MYSTATUS_GetAvatarId(GAME_DATA_GetMyStatusByNetId(gameData, areaOwnerId));
}

/*
 * The season of the game data when no visit runs or the visited area is the
 * own one, else the slot flag of the visited area's owner.
 */
int INTRUDE_COMM_GetAreaSlotFlag(GameComm *comm)
{
    struct GameData *gameData = GAME_COMM_GetGameData(comm);
    u8 areaOwnerId;

    if (GAME_DATA_GetIntrudeCount(gameData) == 0) {
        return GAME_DATA_GetSeason(gameData);
    }
    areaOwnerId = GAME_DATA_GetIntrudeIdByte(gameData);
    if (areaOwnerId == GAME_DATA_GetExitMode(gameData)) {
        return GAME_DATA_GetSeason(gameData);
    }
    return GAME_DATA_GetSlotFlag(gameData, areaOwnerId);
}

/*
 * Whether stepping the local area owner ID one place back (stepKind 2) or
 * forward, wrapping at the highest net ID, lands on the own net ID. Answers 1
 * when no visit work exists.
 */
int INTRUDE_COMM_IsStepToOwnArea(GameComm *comm, struct GameData *gameData, int stepKind)
{
    IntrudeCommSys *work = INTRUDE_COMM_GetWorkIfRunning(comm);
    int next;
    int current;

    if (work == 0)
        return 1;
    current = work->localPeer.intrudeId;
    if (stepKind == 2) {
        next = current - 1;
        if (next < 0)
            next = work->lastAreaIndex;
    } else {
        next = current + 1;
        if (next >= work->lastAreaIndex + 1)
            next = 0;
    }
    if (next == GAME_DATA_GetExitMode(gameData))
        return 1;
    return 0;
}

/*
 * Normalizes a version code to 20 or 21: other codes become 20 when bit 16
 * of the trainer ID is set, else 21.
 */
int INTRUDE_COMM_NormalizeVersion(int version, u32 trainerId)
{
    if (version == 21)
        return version;
    if (version == 20)
        return version;
    if (trainerId & 0x10000)
        return 20;
    return 21;
}

/*
 * Version class of the visited area's owner: 0 for the own area or when the
 * field status is not map mode 1, 1 for version 20, 2 for version 21, 3 for
 * any other. The work of the comm is fetched first and not used.
 */
int INTRUDE_COMM_GetAreaOwnerVersionClass(GameComm *comm, struct GameData *gameData)
{
    u8 areaOwnerId;
    struct MyStatus *status;
    int version;

    INTRUDE_COMM_GetWorkIfRunning(comm);
    if (FIELD_STATUS_GetMapMode(GAME_DATA_GetMoveModelSys(gameData)) != 1)
        return 0;
    areaOwnerId = GAME_DATA_GetIntrudeIdByte(gameData);
    if (areaOwnerId == GAME_DATA_GetExitMode(gameData))
        return 0;
    status = GAME_DATA_GetPlayerStatus(gameData, areaOwnerId);
    version = INTRUDE_COMM_NormalizeVersion(MYSTATUS_GetAvatarId(status), MYSTATUS_GetId(status));
    switch (version) {
    case 20:
        return 1;
    case 21:
        return 2;
    default:
        return 3;
    }
}

/*
 * Whether value is one of the 61 ids of the table.
 *
 * lever: The ternary loop condition preserves the branch to the bottom test.
 */
int INTRUDE_COMM_IsListedId(u16 value)
{
    unsigned int i;

    for (i = 0; (i < 61) ? 1 : 0; i++) {
        if (value == sIntrudeListedIds[i])
            return 1;
    }
    return 0;
}

/*
 * Whether both event flags of the table are set.
 */
int INTRUDE_COMM_HasUnlockFlags(struct GameData *gameData)
{
    struct EventWork *eventWork = GAME_DATA_GetEventWork(gameData);
    unsigned int i;

    for (i = 0; i < 2; i++) {
        if (ZONEDATA_CheckEventFlag(eventWork, sIntrudeUnlockFlags[i]) == 0)
            return 0;
    }
    return 1;
}

/*
 * 1 when the session has been warned but no request is active.
 */
int INTRUDE_COMM_IsWarnedWithoutRequest(IntrudeCommSys *work)
{
    if (work->warned != 0 && INTRUDE_COMM_IsSessionActive(&work->session) == 0)
        return 1;
    return 0;
}

/*
 * Progress of the visit: 0 without work, 3 once the gear reported flag is set,
 * else 2 or 1 from the state of INTRUDE_COMM_GetRequestState (3 gives 2).
 *
 * Callee 02158344 consumes incoming r0.
 */
int INTRUDE_COMM_GetVisitProgress(GameComm *comm)
{
    IntrudeCommSys *work = INTRUDE_COMM_GetWorkIfRunning(comm);

    if (work == 0)
        return 0;
    if (work->gearReported == 0) {
        if (INTRUDE_COMM_GetRequestState(comm) == 3)
            return 2;
        return 1;
    }
    return 3;
}

/*
 * Sets the gear reported flag of the work.
 *
 * The callee reads its incoming r0; legacy void prototypes omit it.
 */
void INTRUDE_COMM_SetCompleted(GameComm *comm)
{
    IntrudeCommSys *work = INTRUDE_COMM_GetWorkIfRunning(comm);

    if (work != 0)
        work->gearReported = 1;
}

/*
 * State of the active request: 0 without work, 1 without an active
 * session, 2 when the request is the player's own, else 1 or 3 by the
 * event flags (3 when both are set).
 */
int INTRUDE_COMM_GetRequestState(GameComm *comm)
{
    IntrudeCommSys *work = INTRUDE_COMM_GetWorkIfRunning(comm);

    if (work == 0)
        return 0;
    if (INTRUDE_COMM_IsSessionActive(&work->session) == 1) {
        if (INTRUDE_COMM_IsRequestFromSelf(work) == 1)
            return 2;
        if (INTRUDE_COMM_HasUnlockFlags(GAME_COMM_GetGameData(comm)) == 0)
            return 1;
        return 3;
    }
    return 1;
}

/*
 * Number of peers with the event flag set (at least 1) while a session is
 * active, else 0.
 */
int INTRUDE_COMM_CountEventPeers(GameComm *comm)
{
    int count = 0;
    u8 i;
    IntrudeCommSys *work = INTRUDE_COMM_GetWorkIfRunning(comm);

    if (work == 0)
        return count;
    if (INTRUDE_COMM_IsSessionActive(&work->session) == 0)
        return count;
    for (i = 0; i < 3; i++) {
        if (work->peers[i].eventJoined == 1)
            count++;
    }
    if (count == 0)
        count = 1;
    return count;
}

/*
 * Copies the status of the requester of the active session to out. Answers 0
 * when no work or no active session exists.
 */
int INTRUDE_COMM_GetRequesterStatus(GameComm *comm, struct MyStatus *out)
{
    IntrudeCommSys *work = INTRUDE_COMM_GetWorkIfRunning(comm);
    struct GameData *gameData = GAME_COMM_GetGameData(comm);

    if (work == 0 || INTRUDE_COMM_IsSessionActive(&work->session) == 0)
        return 0;
    MYSTATUS_NameToStrbuf(GAME_DATA_GetPlayerStatus(gameData, INTRUDE_COMM_GetRequesterNetId(work, &work->session)), out);
    return 1;
}

/*
 * Three guards (kind == 2, a non-null work, session-ended bit set) then a
 * predicate whose one result is inverted.
 */
int INTRUDE_COMM_IsSessionEndPending(GameComm *comm, int unused)
{
    IntrudeCommSys *work;

    if (GAME_COMM_GetKind(comm) != 2)
        return 0;
    work = GAME_COMM_GetWork(comm);
    if (work == 0)
        return 0;
    if (work->sessionEnded == 0)
        return 0;
    if (GFL_NET_IsSessionNull() == 1)
        return 0;
    return 1;
}

/*
 * Clears the 2-bit zone check of the work.
 */
void INTRUDE_COMM_ClearHoldMode(GameComm *comm)
{
    IntrudeCommSys *work = INTRUDE_COMM_GetWorkIfRunning(comm);

    if (work != 0)
        work->zoneCheck = 0;
}
