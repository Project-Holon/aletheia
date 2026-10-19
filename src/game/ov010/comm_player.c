/*
 * file:     comm_player.c
 * unit:     yes
 * function: QUESTIONNAIRE_GetAnswerBitOffset, QUESTIONNAIRE_GetAnswerMax, SYMBOL_MAP_GetGroup, SYMBOL_MAP_GetSymbolIndex, SYMBOL_MAP_CopyEntryRange, SYMBOL_MAP_GetEntryPage0First, SYMBOL_MAP_GetEntryPage0Second, SYMBOL_MAP_GetEntryPage10, SYMBOL_MAP_GetEntryPage20, SYMBOL_MAP_GetEntryPage, COMM_PLAYER_Create, COMM_PLAYER_Delete, COMM_PLAYER_Update, COMM_PLAYER_Add, COMM_PLAYER_Del, COMM_PLAYER_Suspend, COMM_PLAYER_Resume, COMM_PLAYER_ClearPending, COMM_PLAYER_CheckOccupy, COMM_PLAYER_GetObjCode, COMM_PLAYER_SetPackage, COMM_PLAYER_UpdateMyPackage, COMM_PLAYER_SearchGridPos, COMM_PLAYER_SetEffect, COMM_PLAYER_GetMmdl, COMM_PLAYER_CheckActive, COMM_PLAYER_CreateSys
 * address:  0x02167380
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_02171F5F  0x02171F5F  data  a1
 *   d_02171F3C 0x02171F3C data a1
 *   SYMBOL_SAVE_FinalizeChecksum  0x0200E06C  thumb
 *   SYMBOL_SAVE_UpdateChecksum  0x0200E024  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_02172A18 0x02172A18 data a1
 *   GAMESYSTEM_IsFieldMapActive  0x02012114  thumb
 *   FIELD_COMM_ACTOR_CTRL_Delete  0x021942C8  thumb  ov021
 *   GF_PANIC_Fail  0x02034714  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   d_02172A28  0x02172A28  data  ov010  a4
 *   FLDEFF_GYOE_IsFinished  0x021BB5C8  thumb
 *   FIELD_COMM_ACTOR_CTRL_AddActor  0x02194300  thumb  ov021
 *   FIELD_COMM_ACTOR_CTRL_DeleteActor 0x02194354 thumb ov021
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELD_COMM_ACTOR_CTRL_Create  0x02194284  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerObjectCode  0x02012B28  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_GetSeasonDispFlag  0x02014484  thumb
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_PLAYER_GetFormSlot  0x021A34EC  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FLDMMDL_ACMD_GetDrawPos  0x02197CCC  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   GAME_DATA_GetPlayerPosition  0x02012AA0  thumb
 *   GAME_DATA_GetPlayerDirectionType  0x02012AE4  thumb
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   FIELD_COMM_ACTOR_CTRL_SearchGridPos   0x02194384  thumb
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELD_COMM_ACTOR_CTRL_GetMmdl  0x021943EC  thumb  ov021
 *   FLDEFF_GYOE_StartHeld  0x021BB578  thumb
 */
struct Entry32;
struct Ctx;
struct BigObj;
struct Rec44;
struct SaveBlock;
struct Sub02014444Obj;
struct FieldMap;
struct Tbl;
struct PlayerPosition;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct Entry32 {
    u32 id : 11;
    u32 rest : 21;
} Entry32;

typedef unsigned long long u64;

typedef int fx32;

typedef struct PlayerPosition {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

/*
 * One remote player as comm_player.c keeps it. The position is a two-word
 * block (u64 + u32): copying it as one aggregate gives the ldm/stm runs the
 * image has.
 */
typedef struct CommPlayerPos {
    u64 xy;
    u32 z;
} CommPlayerPos;

typedef struct CommPlayerEntry {
    CommPlayerPos pos;      /* 0x00 */
    u32 vanish;             /* 0x0C */
    u16 zoneId;             /* 0x10 */
    u16 objCode;            /* 0x12 */
    u8 used : 1;            /* 0x14 */
    u8 pending : 1;
    u8 dir : 4;
    u8 pad15[3];
    u32 effect;             /* 0x18 */
} CommPlayerEntry;

/* Last own position sent to the other players. */
typedef struct CommPlayerLastPos {
    VecFx32 pos;            /* 0x00 */
    u16 zoneId;             /* 0x0C */
    u8 dir : 4;             /* 0x0E */
    u8 vanish : 1;
} CommPlayerLastPos;

#include "comm_player_types.h"

typedef struct CommPlayerWork {
    void *gameSystem;           /* 0x00 */
    void *playerSys;            /* 0x04 */
    CommPlayerEntry entries[4]; /* 0x08 */
    CommPlayerLastPos last;     /* 0x78 */
    u8 pad88[4];
    u16 heapId;                 /* 0x8C */
    u8 playerMax;               /* 0x8E */
    u8 updateStopped;           /* 0x8F */
    u8 sysOption;               /* 0x90 */
} CommPlayerWork;

/* Flag byte of entry i seen from base + 0x1C (stride 0x1C); see COMM_PLAYER_Del. */
typedef struct CommPlayerFlagView {
    u8 used : 1;
    u8 pending : 1;
    u8 dir : 4;
    u8 pad[3];
    u32 effect;
    u8 tail[20];
} CommPlayerFlagView;

/* Entry i seen from base + i * 0x1C (flags at +0x1C); see COMM_PLAYER_CheckOccupy. */
typedef struct CommPlayerRowView {
    u8 head[28];
    CommPlayerFlagView flags;
} CommPlayerRowView;
struct SymbolSave;

extern void SYMBOL_SAVE_FinalizeChecksum(struct SymbolSave *save);
extern void SYMBOL_SAVE_UpdateChecksum(struct SymbolSave *save);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void *GFL_HEAP_Alloc(u32, u32, int, const char *, u16);
struct GameSystem;
extern unsigned int GAMESYSTEM_IsFieldMapActive(struct GameSystem *gameSystem);
struct FieldCommActorCtrl;
extern void FIELD_COMM_ACTOR_CTRL_Delete(struct FieldCommActorCtrl *ctrl);
extern void GF_PANIC_Fail(const char *expr, u32 line, const char *file);
extern u32 GFL_HEAP_Free(void *p);
extern int FLDEFF_GYOE_IsFinished(void *task);
struct MmdlVec;
extern void FIELD_COMM_ACTOR_CTRL_AddActor(struct FieldCommActorCtrl *ctrl, int id, int objCode, unsigned short *dir, struct MmdlVec *pos, int *vanish);
extern void FIELD_COMM_ACTOR_CTRL_DeleteActor(struct FieldCommActorCtrl *ctrl, unsigned int id);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct MmdlSys;
extern struct MmdlSys *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);
extern struct FieldCommActorCtrl *FIELD_COMM_ACTOR_CTRL_Create(int actorMax, struct MmdlSys *mmdlSys, int heapId, int useRunAnime);
struct GameData;
extern struct GameData *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);
struct PlayerWork;
extern struct PlayerWork *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);
extern u32 GAME_DATA_GetPlayerObjectCode(struct PlayerWork *player);
extern void *GAME_DATA_GetMoveModelSys(struct GameData *gd);
struct FieldStatus;
extern u8 FIELD_STATUS_GetSeasonDispFlag(struct FieldStatus *fs);
extern int FIELDMAP_IsReady(struct FieldMap *fieldMap);
struct FieldPlayer;
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *p);
struct Mmdl;
extern struct Mmdl *FIELD_PLAYER_GetMmdl(struct FieldPlayer *player);
extern int FIELD_PLAYER_GetFormSlot(struct FieldPlayer *player);
extern void FIELD_PLAYER_GetPos(struct FieldPlayer *player, VecFx32 *out);
struct MmdlVec;
extern void FLDMMDL_ACMD_GetDrawPos(struct Mmdl *mmdl, struct MmdlVec *out);
extern u16 FIELD_PLAYER_GetDirDisp(struct FieldPlayer *player);
struct PlayerPosition;
extern struct PlayerPosition *GAME_DATA_GetPlayerPosition(struct PlayerWork *player);
extern u16 GAME_DATA_GetPlayerDirectionType(void *pl);
extern fx32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);
extern int FIELD_COMM_ACTOR_CTRL_SearchGridPos(void *playerSys, int, int, int, int, int);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern u32 FIELD_COMM_ACTOR_CTRL_GetMmdl(struct Tbl *t, u32 key);
extern u32 FLDEFF_GYOE_StartHeld(void *a, void *b, int c, int d);
u8 QUESTIONNAIRE_GetAnswerBitOffset(u32 id);
u8 QUESTIONNAIRE_GetAnswerMax(u32 i);
u8 SYMBOL_MAP_GetGroup(u8 *p);
u8 SYMBOL_MAP_GetSymbolIndex(u8 *p);
u8 SYMBOL_MAP_CopyEntryRange(Entry32 *list, Entry32 *out, u32 cap, u32 start, int count);
u16 SYMBOL_MAP_GetEntryPage0First(Entry32 *list, Entry32 *out, u32 cap, u8 *count);
int SYMBOL_MAP_GetEntryPage0Second(Entry32 *list, Entry32 *out, u32 cap, u8 *count);
u16 SYMBOL_MAP_GetEntryPage10(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n);
u16 SYMBOL_MAP_GetEntryPage20(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n);
u16 SYMBOL_MAP_GetEntryPage(Entry32 *list, Entry32 *out, u32 cap, int page, u8 *n);
void *COMM_PLAYER_Create(int playerMax, void *gameSystem, u16 heapId, int sysOption);
void COMM_PLAYER_Delete(void *gameSystem, CommPlayerWork *work);
void COMM_PLAYER_Update(void *gameSystem, CommPlayerWork *work);
void COMM_PLAYER_Add(CommPlayerWork *work, int index, int objCode, CommPlayerPackage *package);
void COMM_PLAYER_Del(CommPlayerWork *work, int index);
void COMM_PLAYER_Suspend(CommPlayerWork *work);
void COMM_PLAYER_Resume(CommPlayerWork *work);
void COMM_PLAYER_ClearPending(CommPlayerWork *work);
int COMM_PLAYER_CheckOccupy(CommPlayerWork *work, int index);
u16 COMM_PLAYER_GetObjCode(CommPlayerWork *work, int index);
void COMM_PLAYER_SetPackage(CommPlayerWork *work, int index, CommPlayerPackage *package);
int COMM_PLAYER_UpdateMyPackage(CommPlayerWork *work, CommPlayerPackage *out);
int COMM_PLAYER_SearchGridPos(CommPlayerWork *work, int index, int gridY, int gridZ, int outId, int searchIndex);
int COMM_PLAYER_SetEffect(CommPlayerWork *work, int index);
u32 COMM_PLAYER_GetMmdl(CommPlayerWork *work, int index);
int COMM_PLAYER_CheckActive(CommPlayerWork *work, int index);
void COMM_PLAYER_CreateSys(void *gameSystem, CommPlayerWork *work);
extern u8 d_02171F5F[];
extern const u8 d_02171F3C[];
extern const char d_02172A18[];
extern const char d_02172A28[];





/*
 * Record-field accessor (third of the four-leaf run 0x02167358..0x021673A8):
 * returns byte 3 of the 4-byte record for id, 0 when id > 0x1d.  The record
 * table starts at 0x02171F5C; the pool word names the field address itself.
 * Unlabelled in the listing (no lr-saving prologue, callers all in arm9).
 */
u8 QUESTIONNAIRE_GetAnswerBitOffset(u32 id)
{
    if (id > 0x1d)
        return 0;
    return d_02171F5F[id * 4];
}





u8 QUESTIONNAIRE_GetAnswerMax(u32 i) { if (i > 29) return 0; return d_02171F3C[i]; }






/*
 * Reads the byte at +0x848 of the shared state under its lock
 * (SYMBOL_SAVE_FinalizeChecksum / SYMBOL_SAVE_UpdateChecksum).
 */
u8 SYMBOL_MAP_GetGroup(u8 *p)
{
    u8 v;

    SYMBOL_SAVE_FinalizeChecksum((struct SymbolSave *)p);
    v = p[0x848];
    SYMBOL_SAVE_UpdateChecksum((struct SymbolSave *)p);
    return v;
}






/*
 * Reads the byte at +0x849 of the shared state under its lock
 * (SYMBOL_SAVE_FinalizeChecksum / SYMBOL_SAVE_UpdateChecksum).
 */
u8 SYMBOL_MAP_GetSymbolIndex(u8 *p)
{
    u8 v;

    SYMBOL_SAVE_FinalizeChecksum((struct SymbolSave *)p);
    v = p[0x849];
    SYMBOL_SAVE_UpdateChecksum((struct SymbolSave *)p);
    return v;
}






/*
 * Copies `count` 4-byte entries starting at index `start` out of the
 * shared list under its lock into a cleared buffer of `cap` entries, and
 * answers how many leading entries are in use (non-zero 11-bit id).
 */
u8 SYMBOL_MAP_CopyEntryRange(Entry32 *list, Entry32 *out, u32 cap, u32 start, int count)
{
    int i;

    i = 0;
    MI_CpuFill8(out, 0, cap * 4);
    SYMBOL_SAVE_FinalizeChecksum((struct SymbolSave *)list);
    MI_CpuCopy8(&list[start], out, count * 4);
    SYMBOL_SAVE_UpdateChecksum((struct SymbolSave *)list);
    for (i = 0; i < count; i++) {
        if (out[i].id == 0)
            break;
    }
    return i;
}






/* The first ten entries of page 0. */
u16 SYMBOL_MAP_GetEntryPage0First(Entry32 *list, Entry32 *out, u32 cap, u8 *count)
{
    *count = SYMBOL_MAP_CopyEntryRange(list, out, cap, 0, 10);
    return 0;
}






/* The second ten entries of page 0. */
int SYMBOL_MAP_GetEntryPage0Second(Entry32 *list, Entry32 *out, u32 cap, u8 *count)
{
    *count = SYMBOL_MAP_CopyEntryRange(list, out, cap, 10, 10);
    return 10;
}






/*
 * One of the three 10-entry pages from index 20.
 */
u16 SYMBOL_MAP_GetEntryPage10(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n)
{
    u16 start;

    start = page * 10 + 20;
    *n = SYMBOL_MAP_CopyEntryRange(list, out, cap, start, 10);
    return start;
}






/*
 * One of the 20-entry pages from index 50.
 */
u16 SYMBOL_MAP_GetEntryPage20(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n)
{
    u16 start;

    start = page * 20 + 50;
    *n = SYMBOL_MAP_CopyEntryRange(list, out, cap, start, 20);
    return start;
}






/*
 * Fetches list page `page` (0: the first twenty entries, 1..3: ten-entry
 * pages, 4 and up: twenty-entry pages); answers its start index and the
 * number of used entries in *n.
 */
u16 SYMBOL_MAP_GetEntryPage(Entry32 *list, Entry32 *out, u32 cap, int page, u8 *n)
{
    u8 more;
    u16 start;

    more = 0;
    MI_CpuFill8(out, 0, cap * 4);
    if (page == 0) {
        start = SYMBOL_MAP_GetEntryPage0First(list, out, cap, n);
        out += 10;
        cap -= 10;
        SYMBOL_MAP_GetEntryPage0Second(list, out, cap, &more);
        *n += more;
    } else if (page >= 1 && page < 4) {
        start = SYMBOL_MAP_GetEntryPage10(list, out, cap, page - 1, n);
    } else {
        start = SYMBOL_MAP_GetEntryPage20(list, out, cap, page - 4, n);
    }
    return start;
}





void *COMM_PLAYER_Create(int playerMax, void *gameSystem, u16 heapId, int sysOption) {
    CommPlayerWork *work;
    work = GFL_HEAP_Alloc(heapId, sizeof(CommPlayerWork), 1, d_02172A18, 97);
    work->playerMax = playerMax;
    work->gameSystem = gameSystem;
    work->heapId = heapId;
    work->sysOption = sysOption;
    return work;
}

void COMM_PLAYER_Delete(void *gameSystem, CommPlayerWork *work)
{
    int i;
    if (work->playerSys != 0) {
        for (i = 0; i < 4; i++)
            COMM_PLAYER_Del(work, i);
        if (GAMESYSTEM_IsFieldMapActive(gameSystem) == 1)
            FIELD_COMM_ACTOR_CTRL_Delete(work->playerSys);
        else
            GF_PANIC_Fail(d_02172A28, 0, d_02172A28);
    }
    GFL_HEAP_Free(work);
}

void COMM_PLAYER_Update(void *gameSystem, CommPlayerWork *work)
{
    int i;
    COMM_PLAYER_CreateSys(gameSystem, work);
    if (GAMESYSTEM_IsFieldMapActive(work->gameSystem) == 1) {
        for (i = 0; i < 4; i++) {
            if (work->entries[i].used == 1 && work->entries[i].effect != 0 && FLDEFF_GYOE_IsFinished((void *)work->entries[i].effect) == 1)
                work->entries[i].effect = 0;
        }
    }
}

static inline void CopyPos(CommPlayerPos *dst, CommPlayerPos *src)
{
    *dst = *src;
}

void COMM_PLAYER_Add(CommPlayerWork *work, int index, int objCode, CommPlayerPackage *package)
{
    if (work->playerSys != 0 && work->entries[index].used != 1) {
        CopyPos(&work->entries[index].pos, (CommPlayerPos *)&package->pos);
        /* row view as in COMM_PLAYER_SetPackage: entries[index] here changes the bytes */
        ((CommPlayerWork *)((char *)work + index * 0x1C))->entries[0].zoneId = package->zoneId;
        ((CommPlayerWork *)((char *)work + index * 0x1C))->entries[0].vanish = package->vanish;
        work->entries[index].objCode = objCode;
        work->entries[index].pending = 0;
        work->entries[index].used = 1;
        work->entries[index].effect = 0;
        FIELD_COMM_ACTOR_CTRL_AddActor(work->playerSys, index, objCode, &work->entries[index].zoneId, (struct MmdlVec *)((&work->entries[index])), (int *)((&work->entries[index].vanish)));
    }
}

/*
 * lever: test the one-bit field directly; == 1 inserts an extra cmp.
 * domain: no index bound assumed; flag base and unsigned scaled offset use modulo-32 address arithmetic, with no fixed-array subscript.
 * address lever: separate flags base and off locals preserve the original base/offset registers; a combined raw address folds i+1, while the CommPlayerFlagView accesses share the scaled pointer.
 */
void COMM_PLAYER_Del(CommPlayerWork *work, int index) {
    CommPlayerFlagView *flags;
    u32 offset;
    flags = (CommPlayerFlagView *)((u32)work + 28u);
    offset = (u32)index * 28u;
    if (((CommPlayerFlagView *)((u32)flags + offset))->used && work->playerSys != 0) {
        *(u32 *)((u32)work + offset + 32u) = 0;
        FIELD_COMM_ACTOR_CTRL_DeleteActor(work->playerSys, index);
        ((CommPlayerFlagView *)((u32)flags + offset))->used = 0;
    }
}

void COMM_PLAYER_Suspend(CommPlayerWork *work)
{
    CommPlayerFlagView *flags;
    int i;
    if (GAMESYSTEM_IsFieldMapActive(work->gameSystem) != 1)
        GF_PANIC_Fail((const char *)d_02172A28, 0, (const char *)d_02172A28);
    if (work->playerSys != 0) {
        i = 0;
        flags = (CommPlayerFlagView *)((char *)work + 0x1C);
        for (; i < 4; i++) {
            if (flags[i].used == 1) {
                COMM_PLAYER_Del(work, i);
                *(u8 *)&flags[i] |= 2;
            }
        }
        FIELD_COMM_ACTOR_CTRL_Delete(work->playerSys);
        work->playerSys = 0;
    }
}

void COMM_PLAYER_Resume(CommPlayerWork *work)
{
    CommPlayerPackage package;
    CommPlayerFlagView *flags;
    int i;
    if (GAMESYSTEM_IsFieldMapActive(work->gameSystem) != 1)
        GF_PANIC_Fail((const char *)d_02172A28, 0, (const char *)d_02172A28);
    if (work->playerSys != 0)
        GF_PANIC_Fail((const char *)d_02172A28, 0, (const char *)d_02172A28);
    work->playerSys = FIELD_COMM_ACTOR_CTRL_Create(work->playerMax, FIELDMAP_GetMmdlSys(GAMESYSTEM_GetFieldMap(work->gameSystem)), work->heapId, work->sysOption);
    MI_CpuFill8(&package, 0, 0x14);
    flags = (CommPlayerFlagView *)work;
    flags = (CommPlayerFlagView *)((char *)flags + 0x1C);
    for (i = 0; i < 4; i++) {
        if (flags[i].pending == 1) {
            package.pos = *(VecFx32 *)&work->entries[i].pos;
            package.zoneId = work->entries[i].zoneId;
            package.vanish = 0;
            package.dir = flags[i].dir;
            COMM_PLAYER_Add(work, i, work->entries[i].objCode, &package);
        }
    }
}

void COMM_PLAYER_ClearPending(CommPlayerWork *work)
{
    CommPlayerFlagView *flags;
    int i;
    if (GAMESYSTEM_IsFieldMapActive(work->gameSystem) != 1)
        GF_PANIC_Fail((const char *)d_02172A28, 0, (const char *)d_02172A28);
    if (work->playerSys != 0)
        GF_PANIC_Fail((const char *)d_02172A28, 0, (const char *)d_02172A28);
    i = 0;
    flags = (CommPlayerFlagView *)((char *)work + 0x1C);
    for (; i < 4; i++) {
        if (flags[i].pending == 1)
            flags[i].pending = 0;
    }
}

/*
 * domain: the signed index>=4 guard admits negative indices; raw unsigned scaling preserves the original modulo-32 address arithmetic without a fixed-array bound.
 * address lever: CommPlayerRowView supplies the +28 load offset after unsigned scaling; combining +28 with the scaled index folds index+1 and changes the instructions.
 */
int COMM_PLAYER_CheckOccupy(CommPlayerWork *work, int index) {
    if (work == 0 || index >= 4) GF_PANIC_Fail(d_02172A28, 0, d_02172A28);
    return ((CommPlayerRowView *)((u32)work + (u32)index * 28u))->flags.used;
}

u16 COMM_PLAYER_GetObjCode(CommPlayerWork *work, int index)
{
    if (work == 0 || index >= 4 || work->entries[index].used != 1)
        GF_PANIC_Fail((const char *)d_02172A28, 0, (const char *)d_02172A28);
    return work->entries[index].objCode;
}

/*
 * Recursive MATCH unblocker: callee of COLOSSEUM_UpdateCommPlayers (ov019) +005C.  An
 * unlabelled Thumb leaf inside ov010: `disasm.py` emitted its body as the
 * `pool_02167844` word run because its `push {r4, r5}` prologue saves no `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  ov009 holds
 * ARM data at the address, ov011/ov018/ov019 only call it, so ov010 is the
 * region it lives in.
 *
 * The byte shape turns on the 12-byte aggregate copy: writing the position
 * as one `struct { u64; u32; }` assignment is what makes mwcc evaluate the
 * destination address first (dst in r3, the package kept in r2) and emit the
 * exact `ldm r5!`/`stm r4!` run.  Splitting it into a `u64` store plus a `u32`
 * store makes the allocator compute the source address first.
 * See docs/notes/recursive-match-unblocker-ov010-0215.c.txt and
 * docs/idioms/a-twelve-byte-aggregate-copy-pins-the-destination-first.md.
 */
void COMM_PLAYER_SetPackage(CommPlayerWork *work, int index, CommPlayerPackage *package)
{
    /* row = the work shifted by index entries, so entries[0] of row is entry
     * index; &work->entries[index] folds the +8 and changes the bytes. */
    CommPlayerWork *row = (CommPlayerWork *)((char *)work + index * 0x1C);
    row->entries[0].pos = *(CommPlayerPos *)&package->pos;
    row->entries[0].zoneId = package->zoneId;
    row->entries[0].vanish = package->vanish;
}

/*
 * Report the player's position, zone and facing (from the saved copy
 * while flying, from the ov021 rail object, or from the player object),
 * returning 1 only when it differs from the last report. One lever: the
 * change test written positively so the update block comes before the
 * `return 0`.
 */
int COMM_PLAYER_UpdateMyPackage(CommPlayerWork *work, CommPlayerPackage *out)
{
    VecFx32 pos;
    void *railPlayer;
    void *player;
    void *gameData;
    CommPlayerLastPos *last;
    void *rail;
    u32 vanish;
    u32 dir;
    u16 zoneId;
    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    last = &work->last;
    vanish = 0;
    if (work->updateStopped == 1)
        return 0;
    player = GAME_DATA_GetMyPlayerWork(gameData);
    dir = GAME_DATA_GetPlayerObjectCode(player);
    if (FIELD_STATUS_GetSeasonDispFlag(GAME_DATA_GetMoveModelSys(gameData)) == 2) {
        zoneId = last->zoneId;
        pos = last->pos;
        vanish = 1;
        dir = last->dir;
    } else if (GAMESYSTEM_IsFieldMapActive(work->gameSystem) == 1 && FIELDMAP_IsReady(GAMESYSTEM_GetFieldMap(work->gameSystem)) == 1) {
        rail = FIELDMAP_GetFieldPlayer(GAMESYSTEM_GetFieldMap(work->gameSystem));
        railPlayer = FIELD_PLAYER_GetMmdl(rail);
        if (FIELD_PLAYER_GetFormSlot(rail) == 4)
            FIELD_PLAYER_GetPos(rail, &pos);
        else
            FLDMMDL_ACMD_GetDrawPos(railPlayer, (struct MmdlVec *)((fx32 *)(&pos)));
        zoneId = FIELD_PLAYER_GetDirDisp(rail);
    } else {
        pos = *GAME_DATA_GetPlayerPosition(player);
        zoneId = GAME_DATA_GetPlayerDirectionType(player);
    }
    out->zoneId = zoneId;
    out->pos = pos;
    out->vanish = vanish;
    out->dir = dir;
    if (zoneId != last->zoneId || dir != last->dir || vanish != last->vanish
        || GF_STANDARD_CompareBytes((const u8 *)(&pos), (const u8 *)last, sizeof(VecFx32)) != 0) {
        last->zoneId = zoneId;
        last->pos = pos;
        last->dir = dir;
        last->vanish = vanish;
        return 1;
    }
    return 0;
}

/*
 * Forwards a five-argument request for one player to the ov021 player
 * system, with a zero bail when that system is not created.
 */
int COMM_PLAYER_SearchGridPos(CommPlayerWork *work, int gridX, int gridY, int gridZ, int outId, int searchIndex)
{
    void *playerSys = work->playerSys;
    if (playerSys == 0)
        return 0;
    return FIELD_COMM_ACTOR_CTRL_SearchGridPos(playerSys, gridX, gridY, gridZ, outId, searchIndex);
}

int COMM_PLAYER_SetEffect(CommPlayerWork *work, int index)
{
    CommPlayerEntry *entry;
    void *effectSys;
    entry = &work->entries[index];
    if (work->playerSys == 0 || entry->used == 0 || entry->effect != 0)
        return 0;
    effectSys = (void *)FIELDMAP_GetEffect(GAMESYSTEM_GetFieldMap(work->gameSystem));
    entry->effect = FLDEFF_GYOE_StartHeld(effectSys, (void *)FIELD_COMM_ACTOR_CTRL_GetMmdl(work->playerSys, index), 0, 0);
    return 1;
}

u32 COMM_PLAYER_GetMmdl(CommPlayerWork *work, int index)
{
    if (work->playerSys == 0)
        GF_PANIC_Fail((const char *)d_02172A28, 0, (const char *)d_02172A28);
    if (work->entries[index].used != 1)
        GF_PANIC_Fail((const char *)d_02172A28, 0, (const char *)d_02172A28);
    return FIELD_COMM_ACTOR_CTRL_GetMmdl(work->playerSys, index);
}

/*
 * Unlabelled leaf (sole blocker of ov018 EVENT_COMM_COMMON_TalkedStartEventMain).
 */
int COMM_PLAYER_CheckActive(CommPlayerWork *work, int index)
{
    if (work == 0 || work->playerSys == 0 || !((CommPlayerFlagView *)((char *)work + index * 0x1c + 0x1c))->used) {
        return 0;
    }
    return 1;
}

void COMM_PLAYER_CreateSys(void *gameSystem, CommPlayerWork *work)
{
    void *fieldmap;
    if (work->playerSys == 0) {
        fieldmap = GAMESYSTEM_GetFieldMap(gameSystem);
        if (fieldmap != 0 && FIELDMAP_IsReady(fieldmap) != 0)
            work->playerSys = FIELD_COMM_ACTOR_CTRL_Create(work->playerMax, FIELDMAP_GetMmdlSys(fieldmap), work->heapId, work->sysOption);
    }
}
