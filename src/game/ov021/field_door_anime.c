/*
 * file:     field_door_anime.c
 * unit:     yes
 * function: FIELD_DOOR_ANIME_OpenTask, FIELD_DOOR_ANIME_StartOpen, FIELD_DOOR_ANIME_SetOpenTask, FIELD_DOOR_ANIME_StartSetOpen, FIELD_DOOR_ANIME_CloseTask, FIELD_DOOR_ANIME_StartClose
 * address:  0x021C96CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from bsubway_scr.c at 0x021C96CC: door open/close tasks called from scrcmd_screeneffects.c (file name guess, no anchor).
 *
 * symbols:
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb  ov021
 *   FIELD_BUILDMODEL_GetFirstEntryInRect  0x0218C638  thumb  ov021
 *   FIELD_BUILDMODEL_PlayEntryAnim  0x0218C69C  thumb  ov021
 */
struct Desc;
struct Obj;
struct FieldMap;
struct VecFx32;
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;

/* SE ids: door open, door hold, door close. */
#define SE_DOOR_OPEN  0x55B
#define SE_DOOR_HOLD  0x55C
#define SE_DOOR_CLOSE 0x55D

/* Work of the door tasks (0x14 bytes, allocated by the task system). */
typedef struct DoorAnimeWork {
    u32 gameSys;   /* +0x00: owner passed to the task system */
    u32 fieldmap;  /* +0x04: field map; gives the player and the build-model manager */
    u32 door;      /* +0x08: build model found around the player, 0 if none */
    u32 pad0C;     /* +0x0C: not used by these tasks */
    u32 silent;    /* +0x10: close without the close SE */
} DoorAnimeWork;

extern int GFL_USE_GetSeSlot(u32 seqNo);
extern struct Desc *GAME_EVENT_Create(void *owner, void *a, void *b, u32 size);
extern void *GAME_EVENT_GetWork(struct Obj *p);
extern void *FIELDMAP_GetFieldPlayer(struct FieldMap *p);
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern int GFL_USE_IsSeSlotBusy(u32 slot);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern u32 FIELD_G3D_MAPPER_GetBuildModel(u8 *p);
extern int FIELD_BUILDMODEL_GetFirstEntryInRect(int a, int b, int c);
extern void FIELD_BUILDMODEL_PlayEntryAnim(unsigned char *p, int b, int i, int c);
int FIELD_DOOR_ANIME_OpenTask(u32 task, u32 *seq, DoorAnimeWork *work);
u32 FIELD_DOOR_ANIME_StartOpen(u32 prio, u32 gameSys, u32 fieldmap);
int FIELD_DOOR_ANIME_SetOpenTask(u32 task, u32 *seq, DoorAnimeWork *work);
u32 FIELD_DOOR_ANIME_StartSetOpen(u32 prio, u32 gameSys, u32 fieldmap);
int FIELD_DOOR_ANIME_CloseTask(u32 task, u32 *seq, DoorAnimeWork *work);
u32 FIELD_DOOR_ANIME_StartClose(u32 prio, u32 gameSys, u32 fieldmap, u32 silent);

/*
 * Door open task: plays the open SE and the open animation (0) of the build
 * model within one tile of the player, waits for the SE, then plays the hold
 * SE and animation 1.
 */
int FIELD_DOOR_ANIME_OpenTask(u32 task, u32 *seq, DoorAnimeWork *work)
{
    int pos[3];
    int area[4];
    u32 bmodelMan;
    u32 door;

    switch (seq[0]) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(SE_DOOR_OPEN);
        FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer((struct FieldMap *)work->fieldmap), (struct VecFx32 *)pos);
        area[0] = pos[2] - 0x10000;
        area[1] = pos[2] + 0x10000;
        area[2] = pos[0] - 0x10000;
        area[3] = pos[0] + 0x10000;
        bmodelMan = FIELD_G3D_MAPPER_GetBuildModel((u8 *)FIELDMAP_GetG3dMapper((void *)work->fieldmap));
        door = FIELD_BUILDMODEL_GetFirstEntryInRect(bmodelMan, 4, (int)area);
        if (door != 0) {
            work->door = door;
            FIELD_BUILDMODEL_PlayEntryAnim((unsigned char *)bmodelMan, door, 0, 0);
        }
        seq[0]++;
        break;
    case 1:
        if (GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(SE_DOOR_OPEN)) == 0) {
            seq[0]++;
        }
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(SE_DOOR_HOLD);
        if (work->door != 0) {
            bmodelMan = FIELD_G3D_MAPPER_GetBuildModel((u8 *)FIELDMAP_GetG3dMapper((void *)work->fieldmap));
            FIELD_BUILDMODEL_PlayEntryAnim((unsigned char *)bmodelMan, work->door, 1, 2);
        }
        seq[0]++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

u32 FIELD_DOOR_ANIME_StartOpen(u32 prio, u32 gameSys, u32 fieldmap)
{
    u32 task = (u32)GAME_EVENT_Create((void *)gameSys, (void *)prio, FIELD_DOOR_ANIME_OpenTask, 0x14);
    DoorAnimeWork *work = GAME_EVENT_GetWork((struct Obj *)task);
    work->gameSys = gameSys;
    work->fieldmap = fieldmap;
    work->door = 0;
    return task;
}

/* Sets the door near the player to its open state (animation 1) at once, no SE. */
int FIELD_DOOR_ANIME_SetOpenTask(u32 task, u32 *seq, DoorAnimeWork *work)
{
    int pos[3];
    int area[4];
    u32 bmodelMan;
    u32 door;

    switch (seq[0]) {
    case 0:
        FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer((struct FieldMap *)work->fieldmap), (struct VecFx32 *)pos);
        area[0] = pos[2] - 0x10000;
        area[1] = pos[2] + 0x10000;
        area[2] = pos[0] - 0x10000;
        area[3] = pos[0] + 0x10000;
        bmodelMan = FIELD_G3D_MAPPER_GetBuildModel((u8 *)FIELDMAP_GetG3dMapper((void *)work->fieldmap));
        door = FIELD_BUILDMODEL_GetFirstEntryInRect(bmodelMan, 4, (int)area);
        if (door != 0) {
            work->door = door;
            FIELD_BUILDMODEL_PlayEntryAnim((unsigned char *)bmodelMan, door, 1, 2);
        }
        seq[0]++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

u32 FIELD_DOOR_ANIME_StartSetOpen(u32 prio, u32 gameSys, u32 fieldmap)
{
    u32 task = (u32)GAME_EVENT_Create((void *)gameSys, (void *)prio, FIELD_DOOR_ANIME_SetOpenTask, 0x14);
    DoorAnimeWork *work = GAME_EVENT_GetWork((struct Obj *)task);
    work->gameSys = gameSys;
    work->fieldmap = fieldmap;
    work->door = 0;
    return task;
}

/* Door close task: close SE (unless silent) and close animation (2), waits for the SE. */
int FIELD_DOOR_ANIME_CloseTask(u32 task, u32 *seq, DoorAnimeWork *work)
{
    int pos[3];
    int area[4];
    u32 bmodelMan;
    u32 door;

    switch (seq[0]) {
    case 0:
        if (work->silent == 0)
            GFL_USE_PlaySeDefaultVolume(SE_DOOR_CLOSE);
        FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer((struct FieldMap *)work->fieldmap), (struct VecFx32 *)pos);
        area[0] = pos[2] - 0x10000;
        area[1] = pos[2] + 0x10000;
        area[2] = pos[0] - 0x10000;
        area[3] = pos[0] + 0x10000;
        bmodelMan = FIELD_G3D_MAPPER_GetBuildModel((u8 *)FIELDMAP_GetG3dMapper((void *)work->fieldmap));
        door = FIELD_BUILDMODEL_GetFirstEntryInRect(bmodelMan, 4, (int)area);
        if (door != 0) {
            work->door = door;
            FIELD_BUILDMODEL_PlayEntryAnim((unsigned char *)bmodelMan, door, 2, 0);
        }
        seq[0]++;
        break;
    case 1:
        if (work->silent == 0) {
            if (GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(SE_DOOR_CLOSE)) == 0) {
                seq[0]++;
            }
        } else {
            seq[0]++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}

u32 FIELD_DOOR_ANIME_StartClose(u32 prio, u32 gameSys, u32 fieldmap, u32 silent)
{
    u32 task = (u32)GAME_EVENT_Create((void *)gameSys, (void *)prio, FIELD_DOOR_ANIME_CloseTask, 0x14);
    DoorAnimeWork *work = GAME_EVENT_GetWork((struct Obj *)task);
    work->gameSys = gameSys;
    work->fieldmap = fieldmap;
    work->door = 0;
    work->silent = silent;
    return task;
}
