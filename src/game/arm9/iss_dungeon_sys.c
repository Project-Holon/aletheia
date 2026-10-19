/*
 * file:     iss_dungeon_sys.c
 * unit:     yes
 * function: ISS_DUNGEON_SYS_ApplyTrack, ISS_DUNGEON_SYS_CreateTable, ISS_DUNGEON_SYS_DeleteTable, ISS_DUNGEON_SYS_FindRecord, ISS_DUNGEON_SYS_Create, ISS_DUNGEON_SYS_Delete, ISS_DUNGEON_SYS_Update, ISS_DUNGEON_SYS_SetTargetAreaId, ISS_DUNGEON_SYS_Start, ISS_DUNGEON_SYS_Stop, ISS_DUNGEON_SYS_IsActive, ISS_DUNGEON_SYS_HasRecord, ISS_DUNGEON_SYS_ResetTracks, ISS_DUNGEON_SYS_Activate, ISS_DUNGEON_SYS_Deactivate, ISS_DUNGEON_SYS_SelectRecord
 * address:  0x0202B2CC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from iss_dungeon_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   GFL_USE_GetBgmHandle  0x02005C3C  thumb
 *   GFL_USE_SetBgmTrackParams  0x02005EE0  thumb
 *   NNS_SndHandleSetTrackPitch  0x02073018  arm
 *   ARC_TOOL_ReadMemberRange  0x02048F74  arm
 *   ARC_TOOL_GetArchiveFileCount  0x02049030  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 */
#include "iss_road_sys_shared_types.h"

struct GameData;

struct Obj;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short  s16;

/* One 0x1c-byte row of the dungeon sound table (archive 0x92), keyed by area id. */
typedef struct DungeonSoundRecord {
    u16 areaId;
    u8 pad02[2];
    s16 trackValue[4];
    u16 trackSlot[4];
    u8 pad14[8];
} DungeonSoundRecord;

typedef struct DungeonSoundTable {
    u8 count;
    u8 pad01[3];
    DungeonSoundRecord * volatile records;
} DungeonSoundTable;

/* Dungeon-area sound state, 0x38 bytes. */
typedef struct IssDungeonSys {
    u16 heapId;
    u8 pad02[2];
    struct PlayerWork *player;
    struct GameData *gameData;
    u32 isActive;
    u16 currentAreaId;
    u16 targetAreaId;
    DungeonSoundTable *table;
    DungeonSoundRecord *record;
    u16 lastTrackSlot;
    u8 pad1E[2];
    u16 trackOffset[4];
    u16 trackScale[4];
    u16 trackValue[4];
} IssDungeonSys;

extern void GFL_USE_SetBgmTrackParams(u32 a, u32 b, u32 c, u32 d);
struct SndHandle;

extern struct SndHandle *GFL_USE_GetBgmHandle(void);

extern void NNS_SndHandleSetTrackPitch(struct SndHandle *handle, u32 trackMask, u32 value);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 ARC_TOOL_GetArchiveFileCount(u32 a);

extern void ARC_TOOL_ReadMemberRange(void *dst, u32 archiveID, u32 memberIdx, u32 offset, u32 size);

extern u32 GFL_HEAP_Free(void *p);

extern u8 GAME_DATA_GetSeason(const struct GameData *gd);

void ISS_DUNGEON_SYS_ApplyTrack(DungeonSoundRecord *record, u32 trackIndex);

DungeonSoundTable *ISS_DUNGEON_SYS_CreateTable(u32 heapId);

void ISS_DUNGEON_SYS_DeleteTable(DungeonSoundTable *table);

DungeonSoundRecord *ISS_DUNGEON_SYS_FindRecord(DungeonSoundTable *table, u16 areaId);

IssDungeonSys *ISS_DUNGEON_SYS_Create(struct GameData *gameData, struct PlayerWork *player, u32 heapId);

void ISS_DUNGEON_SYS_Delete(IssDungeonSys *dungeon);

void ISS_DUNGEON_SYS_Update(IssDungeonSys *dungeon);

void ISS_DUNGEON_SYS_SetTargetAreaId(IssDungeonSys *dungeon, u16 areaId);

void ISS_DUNGEON_SYS_Start(IssDungeonSys *dungeon);

void ISS_DUNGEON_SYS_Stop(IssDungeonSys *dungeon);

u32 ISS_DUNGEON_SYS_IsActive(IssDungeonSys *dungeon);

u32 ISS_DUNGEON_SYS_HasRecord(IssDungeonSys *dungeon, u16 areaId);

void ISS_DUNGEON_SYS_ResetTracks(IssDungeonSys *dungeon);

void ISS_DUNGEON_SYS_Activate(IssDungeonSys *dungeon);

void ISS_DUNGEON_SYS_Deactivate(IssDungeonSys *dungeon);

void ISS_DUNGEON_SYS_SelectRecord(IssDungeonSys *dungeon, u16 areaId);

/*
 * Applies one track of a sound record: its trackSlot entry to the tile/VRAM
 * helper, and its signed trackValue entry to the second helper.
 */
void ISS_DUNGEON_SYS_ApplyTrack(DungeonSoundRecord *record, u32 trackIndex)
{
    u32 offset = trackIndex << 1;

    GFL_USE_SetBgmTrackParams(0xffff, *(u16 *)((u8 *)record + 0xc + offset), 0xffffffff, 0);
    NNS_SndHandleSetTrackPitch((struct SndHandle *)GFL_USE_GetBgmHandle(), 0xfcff, (u32)*(short *)((u8 *)record + 4 + offset));
}

/*
 * Builds the sound table: a count byte is fetched from ARC_TOOL_GetArchiveFileCount, then
 * that many 0x1c-byte records are allocated and each one loaded from archive
 * 0x92.
 */
DungeonSoundTable *ISS_DUNGEON_SYS_CreateTable(u32 heapId)
{
    u32 i;
    DungeonSoundTable *table = (DungeonSoundTable *)GFL_HEAP_Alloc(heapId, 8, 0, (const void *)0x020A7718, 0x77);

    table->count = (u8)ARC_TOOL_GetArchiveFileCount(0x92);
    table->records = (DungeonSoundRecord *)GFL_HEAP_Alloc(heapId, 0x1c * table->count, 0,
                                         (const void *)0x020A7718, 0x79);

    for (i = 0; (int)i < (int)table->count; i++) {
        ARC_TOOL_ReadMemberRange((u8 *)table->records + i * 0x1c, (u32)0x92, (u32)i, (u32)0, (u32)0x1c);
    }
    return table;
}

/*
 * Releases the record array and then the table itself.
 */
void ISS_DUNGEON_SYS_DeleteTable(DungeonSoundTable *table)
{
    GFL_HEAP_Free(table->records);
    GFL_HEAP_Free(table);
}

/*
 * Finds the record whose area id matches, or NULL.
 * Three shape facts close it:
 *   - the loop is written as its own guard plus do/while, with the records
 *     base loaded inside the guard (the image loads it after `cmp; ble`);
 *   - the records pointer member is volatile, so the hit path re-reads it
 *     (`ldr r0, [r0, #4]`) instead of reusing the loop base;
 *   - the count goes through a copy local before the bound, which swaps the
 *     bound and the base between r7 and r6 to the image choice.
 */
DungeonSoundRecord *ISS_DUNGEON_SYS_FindRecord(DungeonSoundTable *table, u16 areaId)
{
    int i;
    int n;
    DungeonSoundRecord *records;
    int count = table->count;

    n = count;
    i = 0;
    if (i < n) {
        records = table->records;
        do {
            if (areaId == records[i].areaId)
                return &table->records[i];
            i++;
        } while (i < n);
    }
    return 0;
}

/*
 * Allocates a 0x38-byte dungeon sound state, fills its header fields,
 * builds the sound table through ISS_DUNGEON_SYS_CreateTable and resets the track state
 * with ISS_DUNGEON_SYS_ResetTracks.
 */
IssDungeonSys *ISS_DUNGEON_SYS_Create(struct GameData *gameData, struct PlayerWork *player, u32 heapId)
{
    IssDungeonSys *dungeon = (IssDungeonSys *)GFL_HEAP_Alloc(heapId, 0x38, 0,
                                                  (const void *)0x020A7718, 0x109);

    dungeon->heapId = (u16)heapId;
    dungeon->gameData = gameData;
    dungeon->player = player;
    dungeon->isActive = 0;
    dungeon->currentAreaId = 0xffff;
    dungeon->targetAreaId = 0xffff;
    dungeon->table = ISS_DUNGEON_SYS_CreateTable(heapId);
    dungeon->record = 0;
    ISS_DUNGEON_SYS_ResetTracks(dungeon);
    return dungeon;
}

/*
 * Runs the destructor chain: ISS_DUNGEON_SYS_Stop (deactivate), then releases the
 * table and the dungeon state itself.
 */
void ISS_DUNGEON_SYS_Delete(IssDungeonSys *dungeon)
{
    ISS_DUNGEON_SYS_Stop(dungeon);
    ISS_DUNGEON_SYS_DeleteTable(dungeon->table);
    GFL_HEAP_Free(dungeon);
}

/*
 * When active and the current and target area ids differ, latches the
 * target and re-selects the record.
 */
void ISS_DUNGEON_SYS_Update(IssDungeonSys *dungeon)
{
    u16 current;
    u16 target;

    if (dungeon->isActive == 0) {
        return;
    }
    current = dungeon->currentAreaId;
    target = dungeon->targetAreaId;
    if (current == target) {
        return;
    }
    dungeon->currentAreaId = target;
    ISS_DUNGEON_SYS_SelectRecord(dungeon, dungeon->currentAreaId);
}

/*
 * A four-byte setter for the target area id.
 */
void ISS_DUNGEON_SYS_SetTargetAreaId(IssDungeonSys *dungeon, u16 areaId)
{
    dungeon->targetAreaId = areaId;
}

/*
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x0202B47C, the callee
 * address with its Thumb bit set (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 */
void ISS_DUNGEON_SYS_Start(IssDungeonSys *dungeon)
{
    ISS_DUNGEON_SYS_Activate(dungeon);
}

/*
 * A bare tail-call thunk to ISS_DUNGEON_SYS_Deactivate.  The callee is an unlabelled leaf,
 * so its ISA has to be declared here; with `symbols:` absent the name
 * convention defaults it to ARM and the `matched` class refuses the EXACT
 * entry at 0x0202B490 on the ISA mismatch.
 */
void ISS_DUNGEON_SYS_Stop(IssDungeonSys *dungeon)
{
    ISS_DUNGEON_SYS_Deactivate(dungeon);
}

/*
 * Returns the active flag.
 */
u32 ISS_DUNGEON_SYS_IsActive(IssDungeonSys *dungeon)
{
    return dungeon->isActive;
}

/*
 * Returns 1 when the table holds a record with the given area id, else 0.
 */
u32 ISS_DUNGEON_SYS_HasRecord(IssDungeonSys *dungeon, u16 areaId)
{
    DungeonSoundTable *table = dungeon->table;

    if (table == 0) {
        return 0;
    }
    return ISS_DUNGEON_SYS_FindRecord(table, areaId) != 0 ? 1 : 0;
}

/*
 * Resets the last track slot and the per-track offset, scale and value
 * arrays to their idle values (scale 0x100 is unity).
 */
void ISS_DUNGEON_SYS_ResetTracks(IssDungeonSys *dungeon)
{
    int i;
    dungeon->lastTrackSlot = 0xffff;
    for (i = 0; i < 4; i++) {
        dungeon->trackOffset[i] = 0;
        dungeon->trackScale[i] = 0x100;
        dungeon->trackValue[i] = 0;
    }
}

/*
 * When idle, marks the dungeon sound active and selects the record of the
 * current area id.
 */
void ISS_DUNGEON_SYS_Activate(IssDungeonSys *dungeon)
{
    if (dungeon->isActive == 0) {
        dungeon->isActive = 1;
        ISS_DUNGEON_SYS_SelectRecord(dungeon, dungeon->currentAreaId);
    }
}

/*
 * Clears the active flag when it is set.
 */
void ISS_DUNGEON_SYS_Deactivate(IssDungeonSys *dungeon)
{
    if (dungeon->isActive != 0) {
        dungeon->isActive = 0;
    }
}

/*
 * Looks the area id up in the table, stores the found record, and when one
 * exists applies the track selected by the game data area index through
 * ISS_DUNGEON_SYS_ApplyTrack.
 */
void ISS_DUNGEON_SYS_SelectRecord(IssDungeonSys *dungeon, u16 areaId)
{
    u32 found = (u32)ISS_DUNGEON_SYS_FindRecord(dungeon->table, areaId);

    dungeon->record = (DungeonSoundRecord *)found;
    if (found != 0) {
        ISS_DUNGEON_SYS_ApplyTrack(dungeon->record, GAME_DATA_GetSeason(dungeon->gameData));
    }
}
