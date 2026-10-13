/*
 * file:     iss_dungeon_sys.c
 * unit:     yes
 * function: ISS_ROAD_SYS_UpdateVolume, ISS_ROAD_SYS_HasPlayerMoved, ISS_ROAD_SYS_FadeIn, ISS_ROAD_SYS_FadeOut, ISS_ROAD_SYS_ApplyVolume, ISS_DUNGEON_SYS_ApplyTrack, ISS_DUNGEON_SYS_CreateTable, ISS_DUNGEON_SYS_DeleteTable, ISS_DUNGEON_SYS_FindRecord, ISS_DUNGEON_SYS_Create, ISS_DUNGEON_SYS_Delete, ISS_DUNGEON_SYS_Update, ISS_DUNGEON_SYS_SetTargetAreaId, ISS_DUNGEON_SYS_Start, ISS_DUNGEON_SYS_Stop, func_0202B434, func_0202B438, ISS_DUNGEON_SYS_ResetTracks, ISS_DUNGEON_SYS_Activate, ISS_DUNGEON_SYS_Deactivate, ISS_DUNGEON_SYS_SelectRecord
 * address:  0x0202B230
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
 *   func_02012984  0x02012984  thumb
 *   GFL_USE_GetBgmHandle  0x02005C3C  thumb
 *   GFL_USE_SetBgmTrackParams  0x02005EE0  thumb
 *   GFL_USE_SetBgmTrackVolume  0x02005F24  thumb
 *   NNS_SndHandleSetTrackPitch  0x02073018  arm
 */
struct PlayerWork;
struct GameData;
struct Obj;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef signed int    s32;

typedef unsigned short u16;

typedef signed short  s16;

typedef struct PlayerPosition {
    u32 x, y, z;
} PlayerPosition;

/* Footstep-road sound state (same layout as in iss_road_sys.c). */
typedef struct IssRoadSys {
    u32 isActive;
    s32 volume;
    struct PlayerWork *player;
    PlayerPosition lastPosition;
} IssRoadSys;

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

extern PlayerPosition *func_02012AA0(struct PlayerWork *player);
extern void GFL_USE_SetBgmTrackVolume(u32 a, u32 b);
extern void GFL_USE_SetBgmTrackParams(u32 a, u32 b, u32 c, u32 d);
extern u32 *GFL_USE_GetBgmHandle(void);
extern void NNS_SndHandleSetTrackPitch(struct Obj *o, u32 v, u32 w);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02049030(u32 a);
extern void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
extern u32 func_020307B0(void *p);
extern u8 func_02012984(const struct GameData *gd);
void ISS_ROAD_SYS_UpdateVolume(IssRoadSys *road);
u32 ISS_ROAD_SYS_HasPlayerMoved(IssRoadSys *road);
void ISS_ROAD_SYS_FadeIn(IssRoadSys *road);
void ISS_ROAD_SYS_FadeOut(IssRoadSys *road);
void ISS_ROAD_SYS_ApplyVolume(IssRoadSys *road);
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
u32 func_0202B434(IssDungeonSys *dungeon);
u32 func_0202B438(IssDungeonSys *dungeon, u16 areaId);
void ISS_DUNGEON_SYS_ResetTracks(IssDungeonSys *dungeon);
void ISS_DUNGEON_SYS_Activate(IssDungeonSys *dungeon);
void ISS_DUNGEON_SYS_Deactivate(IssDungeonSys *dungeon);
void ISS_DUNGEON_SYS_SelectRecord(IssDungeonSys *dungeon, u16 areaId);

/*
 * Road sound update. When the road sound is active, raises the volume if the
 * player moved since the last call, otherwise lowers it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ROAD_SYS_UpdateVolume.c \
 *       --func ISS_ROAD_SYS_UpdateVolume --addr 0x0202B230 --thumb --cc 1.1p1
 */
void ISS_ROAD_SYS_UpdateVolume(IssRoadSys *road)
{
    if (road->isActive == 0) {
        return;
    }
    if (ISS_ROAD_SYS_HasPlayerMoved(road) != 0) {
        ISS_ROAD_SYS_FadeIn(road);
    } else {
        ISS_ROAD_SYS_FadeOut(road);
    }
}

/*
 * Compares the 12-byte last position against the player's current position,
 * then stores the current position either way, and reports whether they
 * differed.
 *
 * The guard has to be written as a conjunction of equalities over subscripts:
 * `if (s[0] == d[0] && s[1] == d[1] && s[2] == d[2]) differ = 0; else differ = 1;`
 * Each test then branches *away* to the shared "1" block and the "0" block falls
 * through, which is the original shape (movs r3,#0; b over; movs r3,#1).  The
 * disjunction of inequalities is the same value but emits the last test with
 * the opposite polarity; the ternary spelling keeps the polarity but moves the
 * copy, and loses the match.
 */
u32 ISS_ROAD_SYS_HasPlayerMoved(IssRoadSys *road)
{
    u32 *position = (u32 *)func_02012AA0(road->player);
    int moved;

    if (position[0] == road->lastPosition.x && position[1] == road->lastPosition.y &&
        position[2] == road->lastPosition.z) {
        moved = 0;
    } else {
        moved = 1;
    }
    road->lastPosition = *(PlayerPosition *)position;
    return (u32)moved;
}

/*
 * Raises the signed volume by 8, saturating at 0x7f, and applies it.
 */
void ISS_ROAD_SYS_FadeIn(IssRoadSys *road)
{
    s32 volume = road->volume;

    if (volume < 0x7f) {
        volume += 8;
        if (volume > 0x7f) {
            volume = 0x7f;
        }
        road->volume = volume;
        ISS_ROAD_SYS_ApplyVolume(road);
    }
}

/*
 * Lowers the volume by 8, saturating at 0, and applies it.
 */
void ISS_ROAD_SYS_FadeOut(IssRoadSys *road)
{
    s32 volume = road->volume;

    if (volume > 0) {
        volume -= 8;
        if (volume < 0) {
            volume = 0;
        }
        road->volume = volume;
        ISS_ROAD_SYS_ApplyVolume(road);
    }
}

/*
 * Tail-calls GFL_USE_SetBgmTrackVolume(0x300, volume).
 */
void ISS_ROAD_SYS_ApplyVolume(IssRoadSys *road)
{
    GFL_USE_SetBgmTrackVolume(0x300, road->volume);
}

/*
 * Applies one track of a sound record: its trackSlot entry to the tile/VRAM
 * helper, and its signed trackValue entry to the second helper.
 */
void ISS_DUNGEON_SYS_ApplyTrack(DungeonSoundRecord *record, u32 trackIndex)
{
    u32 offset = trackIndex << 1;

    GFL_USE_SetBgmTrackParams(0xffff, *(u16 *)((u8 *)record + 0xc + offset), 0xffffffff, 0);
    NNS_SndHandleSetTrackPitch((struct Obj *)GFL_USE_GetBgmHandle(), 0xfcff, (u32)*(short *)((u8 *)record + 4 + offset));
}

/*
 * Builds the sound table: a count byte is fetched from func_02049030, then
 * that many 0x1c-byte records are allocated and each one loaded from archive
 * 0x92.
 */
DungeonSoundTable *ISS_DUNGEON_SYS_CreateTable(u32 heapId)
{
    u32 i;
    DungeonSoundTable *table = (DungeonSoundTable *)func_02030734(heapId, 8, 0, (const void *)0x020A7718, 0x77);

    table->count = (u8)func_02049030(0x92);
    table->records = (DungeonSoundRecord *)func_02030734(heapId, 0x1c * table->count, 0,
                                         (const void *)0x020A7718, 0x79);

    for (i = 0; (int)i < (int)table->count; i++) {
        func_02048F74((u8 *)table->records + i * 0x1c, 0x92, i, 0, (u32 *)0x1c);
    }
    return table;
}

/*
 * Releases the record array and then the table itself.
 */
void ISS_DUNGEON_SYS_DeleteTable(DungeonSoundTable *table)
{
    func_020307B0(table->records);
    func_020307B0(table);
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
    IssDungeonSys *dungeon = (IssDungeonSys *)func_02030734(heapId, 0x38, 0,
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
    func_020307B0(dungeon);
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
u32 func_0202B434(IssDungeonSys *dungeon)
{
    return dungeon->isActive;
}

/*
 * Returns 1 when the table holds a record with the given area id, else 0.
 */
u32 func_0202B438(IssDungeonSys *dungeon, u16 areaId)
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
        ISS_DUNGEON_SYS_ApplyTrack(dungeon->record, func_02012984(dungeon->gameData));
    }
}
