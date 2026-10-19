/*
 * file:     fieldmap_ctrl_nogrid_work.c
 * unit:     yes
 * function: FIELDMAP_CTRL_NOGRID_WORK_Create, FIELDMAP_CTRL_NOGRID_WORK_Destroy, FIELDMAP_CTRL_NOGRID_WORK_Main, FIELDMAP_CTRL_NOGRID_WORK_GetTargetPos, FIELDMAP_CTRL_NOGRID_WORK_CreateWork, FIELDMAP_CTRL_NOGRID_WORK_FreeWork, FIELDMAP_CTRL_NOGRID_WORK_MovePlayer
 * address:  0x021A6CB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from weather_task.c (lane L141): __FILE__ anchor 021A6D98 (gFieldMapCtrlNogridWorkFileName "fieldmap_ctrl_nogrid_work.c"); 021A6CB8 creates the work via 021A6D58, same shape as fieldmap_ctrl_grid.c 021A2D88.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FLDMMDL_GetPosPtr  0x0216D888  thumb  ov010
 *   FIELDMAP_SetTargetPos  0x02188D40  thumb  ov021
 *   FIELDMAP_SetCtrlWork  0x02188CAC  thumb  ov021
 *   FIELDMAP_GetCtrlWork  0x02188CA4  thumb  ov021
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   gFieldMapCtrlNogridWorkFileName     0x021DDF1C  data  a1
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetCont  0x0203630C  arm
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerRail  0x02012AB8  thumb
 *   FIELD_NOGRID_MAPPER_BindCameraWork  0x021BB3AC  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   FIELD_PLAYER_SetDirDisp  0x021A305C  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_PLAYER_CreateNogrid  0x021A3664  thumb  ov021
 *   FIELD_PLAYER_UpdateNogrid  0x021A3674  thumb  ov021
 *   FIELD_PLAYER_GetNogridRailWork  0x021A36A4  thumb  ov021
 *   FIELD_PLAYER_SetNogridRailLocation  0x021A36B0  thumb  ov021
 *   FIELD_PLAYER_GetNogridRailPos  0x021A36D4  thumb  ov021
 */
#include "fieldmap_types.h"
#include "fldmmdl_rail_types.h"

typedef unsigned int u32;

struct FieldPlayer;
struct FieldNogridMapper;
struct Mmdl;

/* The nogrid map control work (8 bytes), kept in FieldMap.ctrlWork. */
typedef struct FieldMapCtrlNogridWork {
    struct FieldPlayer *player;     /* 0x00 */
    u32 reserved;                   /* 0x04: cleared by the allocation, never used */
} FieldMapCtrlNogridWork;

extern u32 GFL_HEAP_Free(void *memory);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *fileName, u16 line);
extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetCont(void);
extern u16 FIELDMAP_GetHeapId(FieldMap *fieldMap);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);
extern void FIELDMAP_SetCtrlWork(FieldMap *fieldMap, void *ctrlWork);
extern void *FIELDMAP_GetCtrlWork(FieldMap *fieldMap);
extern void FIELDMAP_SetTargetPos(FieldMap *fieldMap, VecFx32 *targetPos);
struct FieldMap;
struct FieldCamera;
extern struct FieldCamera *FIELDMAP_GetCamera(FieldMap *fieldMap);
extern struct FieldNogridMapper *FIELDMAP_GetNogridMapper(FieldMap *fieldMap);
extern void *FIELDMAP_GetGameSystem(FieldMap *fieldMap);
extern VecFx32 *FLDMMDL_GetPosPtr(struct Mmdl *mmdl);
extern void *GAMESYSTEM_GetGameData(void *gameSystem);
extern void *GAME_DATA_GetMyPlayerWork(void *gameData);
extern RailLocation *GAME_DATA_GetPlayerRail(void *saveRecord);
struct RailWork;
extern void FIELD_NOGRID_MAPPER_BindCameraWork(struct FieldNogridMapper *mapper, struct RailWork *work);
extern struct Mmdl *FIELD_PLAYER_GetMmdl(struct FieldPlayer *player);
extern void FIELD_PLAYER_SetPos(struct FieldPlayer *player, VecFx32 *pos);
extern void FIELD_PLAYER_SetDirDisp(struct FieldPlayer *player, int dir);
extern void FIELD_PLAYER_CreateNogrid(struct FieldPlayer *player, u32 heapId);
extern void FIELD_PLAYER_UpdateNogrid(struct FieldPlayer *player, u32 keyTrg, u32 keyCont);
extern u32 FIELD_PLAYER_GetNogridRailWork(struct FieldPlayer *player);
extern void FIELD_PLAYER_SetNogridRailLocation(struct FieldPlayer *player, RailLocation *location);
extern void FIELD_PLAYER_GetNogridRailPos(struct FieldPlayer *player, void *outPos);
extern const char gFieldMapCtrlNogridWorkFileName[];

void FIELDMAP_CTRL_NOGRID_WORK_Create(FieldMap *fieldMap, VecFx32 *pos, u32 dir);
void FIELDMAP_CTRL_NOGRID_WORK_Destroy(FieldMap *fieldMap);
void FIELDMAP_CTRL_NOGRID_WORK_Main(FieldMap *fieldMap, VecFx32 *pos);
VecFx32 *FIELDMAP_CTRL_NOGRID_WORK_GetTargetPos(FieldMap *fieldMap);
FieldMapCtrlNogridWork *FIELDMAP_CTRL_NOGRID_WORK_CreateWork(FieldMap *fieldMap, u32 heapId);
void FIELDMAP_CTRL_NOGRID_WORK_FreeWork(void *work);
void FIELDMAP_CTRL_NOGRID_WORK_MovePlayer(FieldMapCtrlNogridWork *work);

/*
 * Creates the nogrid control: the player stands on the rails at the location
 * stored in the save data. The first two getters have unused results.
 */
void FIELDMAP_CTRL_NOGRID_WORK_Create(FieldMap *fieldMap, VecFx32 *pos, u32 dir)
{
    struct FieldPlayer *player;

    FIELDMAP_GetCamera(fieldMap);
    FIELDMAP_GetNogridMapper(fieldMap);
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    FIELDMAP_SetCtrlWork(fieldMap, FIELDMAP_CTRL_NOGRID_WORK_CreateWork(fieldMap, FIELDMAP_GetHeapId(fieldMap)));
    FIELDMAP_SetTargetPos(fieldMap, FLDMMDL_GetPosPtr(FIELD_PLAYER_GetMmdl(player)));
    FIELD_PLAYER_SetNogridRailLocation(player, GAME_DATA_GetPlayerRail(GAME_DATA_GetMyPlayerWork(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)))));
    FIELD_PLAYER_GetNogridRailPos(player, pos);
    FIELD_PLAYER_SetPos(player, pos);
    FIELD_PLAYER_SetDirDisp(player, dir);
}

/* Destroy slot. */
void FIELDMAP_CTRL_NOGRID_WORK_Destroy(FieldMap *fieldMap)
{
    FIELDMAP_CTRL_NOGRID_WORK_FreeWork(FIELDMAP_GetCtrlWork(fieldMap));
}

/* Main slot. */
void FIELDMAP_CTRL_NOGRID_WORK_Main(FieldMap *fieldMap, VecFx32 *pos)
{
    FIELDMAP_CTRL_NOGRID_WORK_MovePlayer(FIELDMAP_GetCtrlWork(fieldMap));
}

/* Position of the player's model, the point the camera follows. */
VecFx32 *FIELDMAP_CTRL_NOGRID_WORK_GetTargetPos(FieldMap *fieldMap)
{
    return FLDMMDL_GetPosPtr(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)));
}

/* Allocates the work and binds the nogrid mapper camera to the player's rail work. */
FieldMapCtrlNogridWork *FIELDMAP_CTRL_NOGRID_WORK_CreateWork(FieldMap *fieldMap, u32 heapId)
{
    struct FieldNogridMapper *nogridMapper = FIELDMAP_GetNogridMapper(fieldMap);
    FieldMapCtrlNogridWork *work = GFL_HEAP_Alloc(heapId, sizeof(FieldMapCtrlNogridWork), 1, gFieldMapCtrlNogridWorkFileName, 0x3e);
    struct FieldPlayer *player = FIELDMAP_GetFieldPlayer(fieldMap);

    work->player = player;
    FIELD_PLAYER_CreateNogrid(player, heapId);
    FIELD_NOGRID_MAPPER_BindCameraWork(nogridMapper, (struct RailWork *)(FIELD_PLAYER_GetNogridRailWork(player)));
    return work;
}

/* Frees the work. */
void FIELDMAP_CTRL_NOGRID_WORK_FreeWork(void *work)
{
    GFL_HEAP_Free(work);
}

/* Moves the player along the rails with this frame's keys. */
void FIELDMAP_CTRL_NOGRID_WORK_MovePlayer(FieldMapCtrlNogridWork *work)
{
    u32 keyTrg = KEY_GetTrg();
    u32 keyCont = KEY_GetCont();

    FIELD_PLAYER_UpdateNogrid(work->player, keyTrg, keyCont);
}
