/*
 * file:     field_gimmick_d06.c
 * unit:     yes
 * function: FIELD_GIMMICK_D06_FindStoneTableRow, FIELD_GIMMICK_D06_GetStonePositions, FIELD_GIMMICK_D06_GetStoneCount, FIELD_GIMMICK_D06_FindPanelTable, FIELD_GIMMICK_D06_GetPanelPositions, FIELD_GIMMICK_D06_GetPanelCount, FIELD_GIMMICK_D06_Init, FIELD_GIMMICK_D06_Exit, FIELD_GIMMICK_D06_Update, FIELD_GIMMICK_D06_CheckPushStone, FIELD_GIMMICK_D06_CreateSlideEvent, FIELD_GIMMICK_D06_EventSlideStone, FIELD_GIMMICK_D06_EventStoneBlocked, FIELD_GIMMICK_D06_AddStone, FIELD_GIMMICK_D06_AttachStone, FIELD_GIMMICK_D06_ScanSlide, FIELD_GIMMICK_D06_GetSlideSteps, FIELD_GIMMICK_D06_IsStoneNextToPanel, FIELD_GIMMICK_D06_AddPanelPulse, FIELD_GIMMICK_D06_TriggerPanelPulse, FIELD_GIMMICK_D06_AddStoneMmdl, FIELD_GIMMICK_D06_GetWork, FIELD_GIMMICK_D06_GetGimmickId
 * address:  0x021F36C0
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gGimmickD06StoneTable 0x021F3DB4 data a4
 *   gGimmickD06PanelTable 0x021F3DFC data a4
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELD_GIMMICK_D06_GetGimmickId  0x021F3D94  thumb  ov051
 *   GIMMICK_WORK_GetWork  0x0200B3A4  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   FIELD_EFFECT_LoadResources  0x021ABE30  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb
 *   FLDMMDL_GetObjId  0x0216D588  thumb
 *   gGimmickD06SourceFile     0x021F40A0  data  ov051  a4
 *   GFL_HEAP_Free 0x020307B0 arm
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   MI_CpuFill  0x02082C60  arm
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb
 *   FLDMMDL_SetAcmd  0x0216D410  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb
 *   FLDMMDL_EndAcmd  0x0216D480  thumb
 *   FLDEFF_D06DENKI_FollowFreezeLoop  0x021C909C  thumb
 *   FLDEFF_D06DENKI_FollowStartEnding  0x021C90AC  thumb
 *   FLDEFF_D06DENKI_FollowIsEnded  0x021C90D0  thumb
 *   FLDMMDL_GetPos  0x0216D88C  thumb
 *   FLDEFF_D06DENKI_StartFollow  0x021C9064  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb
 *   FLDMMDL_MOVE_AddDirGrid  0x02164240  thumb
 *   FLDMMDL_MOVE_HitCheckMoveCurrent  0x02163994  thumb
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb
 *   FLDMMDL_GetPosY  0x0216D8AC  thumb
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb
 *   MAP_ATTR_IsElectricPanel  0x021AB3F8  thumb
 *   FLDEFF_D06DENKI_StartPulse 0x021C9258 thumb ov021
 *   FLDEFF_D06DENKI_PulseTrigger 0x021C928C thumb ov021
 *   FLDMMDL_AddMmdlParam 0x0216CE6C thumb ov010
 */
/* Original prototypes (docs/ORIGINAL_BUGS.tsv): the DS file declares these differently from the ARM9 headers. */
#ifdef __MWERKS__
#define FLDMMDL_AddMmdlParam FLDMMDL_AddMmdlParam_header
#define FLDMMDL_SetAcmd FLDMMDL_SetAcmd_header
#define FLDMMDL_MOVE_HitCheckMoveCurrent FLDMMDL_MOVE_HitCheckMoveCurrent_header
#endif
#include "../ov021/fld_exp_obj_types.h"
#include "field_gimmick_d06_types.h"
extern struct FieldEffectObj *FLDEFF_D06DENKI_StartFollow(struct FieldEffectSys *effects, const VecFx32 *pos, struct Mmdl *mmdl);
extern struct FieldEffectObj *FLDEFF_D06DENKI_StartPulse(struct FieldEffectSys *effects, const VecFx32 *pos);
extern void FLDEFF_D06DENKI_PulseTrigger(struct FieldEffectObj *effect);
extern void FLDEFF_D06DENKI_FollowFreezeLoop(struct FieldEffectObj *effect);
extern void FLDEFF_D06DENKI_FollowStartEnding(struct FieldEffectObj *effect);
extern int FLDEFF_D06DENKI_FollowIsEnded(struct FieldEffectObj *effect);

const GimmickD06ZoneTable *FIELD_GIMMICK_D06_FindStoneTableRow(int zoneId);
const GimmickD06GridPos *FIELD_GIMMICK_D06_GetStonePositions(int zoneId);
int FIELD_GIMMICK_D06_GetStoneCount(int zoneId);
const GimmickD06ZoneTable *FIELD_GIMMICK_D06_FindPanelTable(int zoneId);
const GimmickD06GridPos *FIELD_GIMMICK_D06_GetPanelPositions(int zoneId);
int FIELD_GIMMICK_D06_GetPanelCount(int zoneId);
void FIELD_GIMMICK_D06_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_D06_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_D06_Update(void);
struct GameEvent *FIELD_GIMMICK_D06_CheckPushStone(struct FieldMap *fieldMap, int facingDir);
struct GameEvent *FIELD_GIMMICK_D06_CreateSlideEvent(struct FieldMap *fieldMap, struct Mmdl *stone, int direction);
int FIELD_GIMMICK_D06_EventSlideStone(struct GameEvent *event, int *seq, void *work);
int FIELD_GIMMICK_D06_EventStoneBlocked(struct GameEvent *event, int *seq, void *work);
void FIELD_GIMMICK_D06_AddStone(GimmickD06Work *work, GimmickD06StoneSlot *slot, int gridX, int gridZ);
void FIELD_GIMMICK_D06_AttachStone(GimmickD06Work *work, GimmickD06StoneSlot *slot, struct Mmdl *mmdl);
int FIELD_GIMMICK_D06_ScanSlide(GimmickD06Work *work, GimmickD06StoneSlot *slot, int direction, unsigned short maxSteps, unsigned int *steps);
int FIELD_GIMMICK_D06_GetSlideSteps(GimmickD06Work *work, GimmickD06StoneSlot *slot, int direction);
int FIELD_GIMMICK_D06_IsStoneNextToPanel(GimmickD06Work *work, GimmickD06StoneSlot *slot);
void FIELD_GIMMICK_D06_AddPanelPulse(GimmickD06Work *work, struct FieldEffectObj **pulse, int gridX, int gridY, int gridZ);
void FIELD_GIMMICK_D06_TriggerPanelPulse(struct FieldMap *fieldMap, int panelIndex);
struct Mmdl *FIELD_GIMMICK_D06_AddStoneMmdl(struct FieldMap *fieldMap, int gridX, int gridZ);
GimmickD06Work *FIELD_GIMMICK_D06_GetWork(struct FieldMap *fieldMap);

/* The __FILE__ string of the allocation in the setup function. */
extern char gGimmickD06SourceFile[];
/* The stone cells and the panel cells of the three zones. */
extern const GimmickD06ZoneTable gGimmickD06StoneTable[GIMMICK_D06_ZONE_COUNT];
extern const GimmickD06ZoneTable gGimmickD06PanelTable[GIMMICK_D06_ZONE_COUNT];
#include "field_gimmick_d06_ids.h"
#include "../ov021/fieldmap.h"
#include "../arm9/gamesystem.h"
#include "../arm9/game_data.h"
#include "../arm9/gimmick.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../ov021/field_effect.h"
#include "../arm9/game_event.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gfl_use.h"
#include "../ov010/fldmmdl.h"
#include "../ov010/fldmmdl_move.h"
#include "../ov021/fldmmdl_acmd.h"
#include "../ov021/field_player.h"
#include "../ov021/map_attr.h"
#include "field_gimmick_d06.h"
#ifdef __MWERKS__
#undef FLDMMDL_AddMmdlParam
#undef FLDMMDL_SetAcmd
#undef FLDMMDL_MOVE_HitCheckMoveCurrent
struct Mmdl *FLDMMDL_AddMmdlParam(struct MmdlSys *mmdlSys, short gridX, short gridZ, u16 dir, u16 objId,
                                  u16 objCode, u16 moveCode, u32 zoneId);
void FLDMMDL_SetAcmd(struct Mmdl *mmdl, int acmd);
int FLDMMDL_MOVE_HitCheckMoveCurrent(struct Mmdl *mmdl, int x, int y, int z, u32 dir);
#endif

/* The row of the stone table for a zone; the first row for an unknown zone. */
const GimmickD06ZoneTable *FIELD_GIMMICK_D06_FindStoneTableRow(int zoneId)
{
    unsigned int i;
    const GimmickD06ZoneTable *table = gGimmickD06StoneTable;

    for (i = 0; i < GIMMICK_D06_ZONE_COUNT; i++, table++)
        if (table->zoneId == zoneId)
            return table;
    return gGimmickD06StoneTable;
}

/*
 * Two accessors over the result of FIELD_GIMMICK_D06_FindStoneTableRow: the cells and their count.
 */
const GimmickD06GridPos *FIELD_GIMMICK_D06_GetStonePositions(int zoneId)
{
    return FIELD_GIMMICK_D06_FindStoneTableRow(zoneId)->positions;
}

int FIELD_GIMMICK_D06_GetStoneCount(int zoneId)
{
    return FIELD_GIMMICK_D06_FindStoneTableRow(zoneId)->count;
}

/* The row of the panel table for a zone; the first row for an unknown zone. */
const GimmickD06ZoneTable *FIELD_GIMMICK_D06_FindPanelTable(int zoneId)
{
    unsigned int i;
    const GimmickD06ZoneTable *table = gGimmickD06PanelTable;

    for (i = 0; i < GIMMICK_D06_ZONE_COUNT; i++, table++)
        if (table->zoneId == zoneId)
            return table;
    return gGimmickD06PanelTable;
}

/*
 * Two accessors over the result of FIELD_GIMMICK_D06_FindPanelTable: the cells and their count.
 */
const GimmickD06GridPos *FIELD_GIMMICK_D06_GetPanelPositions(int zoneId)
{
    return FIELD_GIMMICK_D06_FindPanelTable(zoneId)->positions;
}

int FIELD_GIMMICK_D06_GetPanelCount(int zoneId)
{
    return FIELD_GIMMICK_D06_FindPanelTable(zoneId)->count;
}

/*
 * Gimmick setup: allocate the work and put the stones and the panel effects of
 * the zone on the map. The first visit creates the stones from the table;
 * later visits pick up the stone objects the map holds.
 *
 * note:     the flag test reads the placed byte as unsigned char (ldrb); a plain char
 *           test gives ldrsb with a zero register hoisted above the branch.
 */
void FIELD_GIMMICK_D06_Init(struct FieldMap *fieldMap)
{
    int effectId;
    u32 iterator;
    struct Mmdl *mmdl;
    int heapId;
    struct GimmickWork *gimmickWork;
    struct FieldEffectSys *effects;
    int zoneId;
    GimmickD06Save *save;
    GimmickD06Work *work;
    unsigned int i;
    unsigned int count;
    const GimmickD06GridPos *pos;
    struct MmdlSys *mmdlSys;

    heapId = FIELDMAP_GetHeapId(fieldMap);
    gimmickWork = (struct GimmickWork *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    effects = FIELDMAP_GetEffect(fieldMap);
    zoneId = FIELDMAP_GetZoneId(fieldMap);
    save = (GimmickD06Save *)GIMMICK_WORK_GetWork(gimmickWork, FIELD_GIMMICK_D06_GetGimmickId(zoneId));
    work = GFL_HEAP_Alloc(heapId, sizeof(GimmickD06Work), 1, gGimmickD06SourceFile, 0xca);
    save->work = work;
    work->save = save;
    work->fieldMap = fieldMap;
    work->zoneId = zoneId;
    effectId = 0xb;
    FIELD_EFFECT_LoadResources(effects, &effectId, 1);
    if (save->placed == 0) {
        count = FIELD_GIMMICK_D06_GetStoneCount(work->zoneId);
        pos = FIELD_GIMMICK_D06_GetStonePositions(work->zoneId);
        i = 0;
        if (i < count)
            for (; i < count; i++) {
                FIELD_GIMMICK_D06_AddStone(work, &work->stones[i], pos->x, pos->z);
                pos++;
            }
    } else {
        i = 0;
        iterator = 0;
        mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
        while (FLDMMDL_SysSearchUseMmdl(mmdlSys, &mmdl, &iterator)) {
            if (FLDMMDL_GetObjId(mmdl) == GIMMICK_D06_STONE_OBJ_ID) {
                FIELD_GIMMICK_D06_AttachStone(work, &work->stones[i], mmdl);
                i++;
                if (i >= GIMMICK_D06_STONE_MAX)
                    break;
            }
        }
    }
    count = FIELD_GIMMICK_D06_GetPanelCount(work->zoneId);
    pos = FIELD_GIMMICK_D06_GetPanelPositions(work->zoneId);
    i = 0;
    if (i < count)
        for (; i < count; i++) {
            FIELD_GIMMICK_D06_AddPanelPulse(work, &work->panelPulse[i], pos->x, pos->y, pos->z);
            pos++;
        }
    save->placed = 1;
}

/* Gimmick exit: free the work. */
void FIELD_GIMMICK_D06_Exit(struct FieldMap *fieldMap)
{
    struct GimmickWork *gimmickWork;

    FIELDMAP_GetHeapId(fieldMap);
    gimmickWork = (struct GimmickWork *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    FIELDMAP_GetEffect(fieldMap);
    GFL_HEAP_Free(((GimmickD06Save *)GIMMICK_WORK_GetWork(gimmickWork, FIELD_GIMMICK_D06_GetGimmickId(FIELDMAP_GetZoneId(fieldMap))))->work);
}

/*
 * Gimmick update: empty.
 * note: extent follower at 0x021F38A0 is an empty return stub; no existing same-region source or shard was found.
 */
void FIELD_GIMMICK_D06_Update(void)
{
}

/*
 * Check for a stone in front of the player: the cell ahead of the player is
 * on a stone, push it. Also pulse the panel when a panel cell is the one ahead.
 * Returns the slide event or null.
 */
struct GameEvent *FIELD_GIMMICK_D06_CheckPushStone(struct FieldMap *fieldMap, int facingDir)
{
    VecFx32 pos;
    struct GameEvent *event;
    int gridX;
    int gridZ;
    struct Mmdl *mmdl;
    unsigned int i;
    const GimmickD06GridPos *panel;
    unsigned int count;
    GimmickD06Work *work;

    event = 0;
    work = FIELD_GIMMICK_D06_GetWork(fieldMap);
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &pos);
    FLDMMDL_MOVE_AddDirVector(facingDir, &pos, 1 << 16);
    gridX = (short)(((pos.x >> 4) / 4096));
    gridZ = (short)(((pos.z >> 4) / 4096));
    count = FIELD_GIMMICK_D06_GetPanelCount(work->zoneId);
    panel = FIELD_GIMMICK_D06_GetPanelPositions(work->zoneId);
    i = 0;
    if (i < count)
        for (; i < count; i++) {
            if (panel->x == gridX && panel->z == gridZ)
                FIELD_GIMMICK_D06_TriggerPanelPulse(fieldMap, i);
            panel++;
        }
    mmdl = FLDMMDL_SysSearchGridPos(FIELDMAP_GetMmdlSys(fieldMap), gridX, gridZ, 0);
    if (mmdl != 0 && FLDMMDL_GetObjId(mmdl) == GIMMICK_D06_STONE_OBJ_ID)
        event = FIELD_GIMMICK_D06_CreateSlideEvent(fieldMap, mmdl, facingDir);
    return event;
}

/*
 * Create the event of a push on one stone. A stone that already touches a panel
 * is not pushed. Without a panel to reach the stone does not move.
 */
struct GameEvent *FIELD_GIMMICK_D06_CreateSlideEvent(struct FieldMap *fieldMap, struct Mmdl *stone, int direction)
{
    int steps;
    struct GameSystem *gameSystem;
    struct GameEvent *event;
    unsigned short i;
    struct Mmdl *mmdl;
    GimmickD06Work *work;
    GimmickD06StoneSlot *slot;
    GimmickD06SlideEvent *slide;

    work = FIELD_GIMMICK_D06_GetWork(fieldMap);
    gameSystem = FIELDMAP_GetGameSystem(fieldMap);
    for (i = 0; i < GIMMICK_D06_STONE_MAX; i++) {
        mmdl = work->stones[i].mmdl;
        if (mmdl == stone)
            break;
    }
    if (i >= GIMMICK_D06_STONE_MAX)
        i = 0;
    slot = &work->stones[i];
    if (FIELD_GIMMICK_D06_IsStoneNextToPanel(work, slot) == 1)
        return 0;
    steps = FIELD_GIMMICK_D06_GetSlideSteps(work, slot, direction);
    if (steps == 0)
        event = GAME_EVENT_Create(gameSystem, 0, FIELD_GIMMICK_D06_EventStoneBlocked, sizeof(GimmickD06SlideEvent));
    else
        event = GAME_EVENT_Create(gameSystem, 0, FIELD_GIMMICK_D06_EventSlideStone, sizeof(GimmickD06SlideEvent));
    slide = GAME_EVENT_GetWork(event);
    MI_CpuFill(slide, 0, sizeof(*slide));
    slide->direction = direction;
    slide->work = work;
    slide->slotIndex = i;
    slide->slot = slot;
    slide->stepsLeft = steps;
    return event;
}

/*
 * Event: the stone slides to a panel. The player bumps against it, the stone
 * moves one tile per step and slows down at the end, then both stop.
 */
int FIELD_GIMMICK_D06_EventSlideStone(struct GameEvent *event, int *seq, void *work)
{
    GimmickD06SlideEvent *slide = work;
    struct Mmdl *playerMmdl;

    playerMmdl = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(slide->work->fieldMap));
    switch (*seq) {
    case 0:
        if (FLDMMDL_CheckPossibleAcmd(playerMmdl) == 1) {
            FLDMMDL_SetAcmd(playerMmdl, FLDMMDL_ACMD_ConvertCodeByDir(slide->direction, GIMMICK_D06_ACMD_PLAYER_BUMP));
            GFL_USE_PlaySeDefaultVolume(GIMMICK_D06_SE_PUSH_START);
            *seq = *seq + 1;
        }
        break;
    case 1:
        if (FLDMMDL_CheckPossibleAcmd(slide->slot->mmdl) == 1) {
            if (slide->stepsLeft > 0) {
                int acmdBase = GIMMICK_D06_ACMD_SLIDE_FAST;
                if (slide->stepsLeft <= 1)
                    acmdBase = GIMMICK_D06_ACMD_SLIDE_SLOW;
                else if (slide->stepsLeft <= 2)
                    acmdBase = GIMMICK_D06_ACMD_SLIDE_SLOW;
                else if (slide->stepsLeft <= 4)
                    acmdBase = GIMMICK_D06_ACMD_SLIDE_MID;
                FLDMMDL_SetAcmd(slide->slot->mmdl, FLDMMDL_ACMD_ConvertCodeByDir(slide->direction, acmdBase));
                slide->stepsLeft = slide->stepsLeft - 1;
            } else {
                GFL_USE_PlaySeDefaultVolume(GIMMICK_D06_SE_SLIDE_END);
                *seq = *seq + 1;
            }
        }
        break;
    case 2:
        if (FLDMMDL_CheckEndAcmd(playerMmdl) == 1) {
            FLDMMDL_EndAcmd(slide->slot->mmdl);
            FLDMMDL_EndAcmd(playerMmdl);
            FLDEFF_D06DENKI_FollowFreezeLoop(slide->slot->follow);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Event: the stone cannot move. The player bumps against it and its effect
 * plays the ending. The first cases fall through on purpose.
 */
int FIELD_GIMMICK_D06_EventStoneBlocked(struct GameEvent *event, int *seq, void *work)
{
    GimmickD06SlideEvent *slide = work;
    struct Mmdl *playerMmdl;

    playerMmdl = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(slide->work->fieldMap));
    switch (*seq) {
    case 0:
        if (FLDMMDL_CheckPossibleAcmd(playerMmdl) == 1) {
            FLDMMDL_SetAcmd(playerMmdl, FLDMMDL_ACMD_ConvertCodeByDir(slide->direction, GIMMICK_D06_ACMD_PLAYER_BUMP));
            GFL_USE_PlaySeDefaultVolume(GIMMICK_D06_SE_PUSH_BLOCKED);
            *seq = *seq + 1;
        }
    case 1:
        FLDEFF_D06DENKI_FollowStartEnding(slide->slot->follow);
        *seq = *seq + 1;
        break;
    case 2:
        if (FLDEFF_D06DENKI_FollowIsEnded(slide->slot->follow) == 0)
            break;
        *seq = *seq + 1;
    case 3:
        if (FLDMMDL_CheckEndAcmd(playerMmdl) == 1) {
            FLDMMDL_EndAcmd(playerMmdl);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Create a stone at a cell and its follow effect. The effect freezes at once
 * when the stone already rests against a panel.
 */
void FIELD_GIMMICK_D06_AddStone(GimmickD06Work *work, GimmickD06StoneSlot *slot, int gridX, int gridZ)
{
    VecFx32 pos;

    slot->mmdl = FIELD_GIMMICK_D06_AddStoneMmdl(work->fieldMap, gridX, gridZ);
    FLDMMDL_GetPos(slot->mmdl, (struct VecFx32 *)&pos);
    slot->follow = FLDEFF_D06DENKI_StartFollow(FIELDMAP_GetEffect(work->fieldMap), &pos, slot->mmdl);
    if (FIELD_GIMMICK_D06_IsStoneNextToPanel(work, slot) == 1)
        FLDEFF_D06DENKI_FollowFreezeLoop(slot->follow);
}

/*
 * Take over a stone object the map already holds, with a new follow effect.
 * note: two-byte alignment padding at 0x021F3BC2 follows the return.
 * note: FLDEFF_D06DENKI_StartFollow's result is stored and read by caller; extern preserves r0 despite its void definition.
 */
void FIELD_GIMMICK_D06_AttachStone(GimmickD06Work *work, GimmickD06StoneSlot *slot, struct Mmdl *mmdl)
{
    VecFx32 pos;

    slot->mmdl = mmdl;
    FLDMMDL_GetPos(mmdl, (struct VecFx32 *)&pos);
    slot->follow = FLDEFF_D06DENKI_StartFollow(FIELDMAP_GetEffect(work->fieldMap), &pos, slot->mmdl);
    if (FIELD_GIMMICK_D06_IsStoneNextToPanel(work, slot) == 1)
        FLDEFF_D06DENKI_FollowFreezeLoop(slot->follow);
}

/*
 * Look ahead from the stone, up to maxSteps tiles, in one direction. The scan
 * ends at the first tile that stops the stone; it reports 1 when that tile is
 * an electric panel, and then the number of tiles up to it in steps (0 when
 * the scan found no panel).
 */
int FIELD_GIMMICK_D06_ScanSlide(GimmickD06Work *work, GimmickD06StoneSlot *slot, int direction, unsigned short maxSteps, unsigned int *steps)
{
    struct Mmdl *mmdl = slot->mmdl;
    unsigned short i = 0;
    VecFx32 vec;
    short gridX;
    short gridZ;
    int found = 0;
    struct FieldG3dMapper *mapper;
    int gridY;
    int result;

    mapper = FIELDMAP_GetG3dMapper(work->fieldMap);
    gridX = FLDMMDL_GetGridNowX(mmdl);
    gridY = FLDMMDL_GetGridNowY(mmdl);
    gridZ = FLDMMDL_GetGridNowZ(mmdl);
    do {
        FLDMMDL_MOVE_AddDirGrid(direction, &gridX, &gridZ, 1);
        result = FLDMMDL_MOVE_HitCheckMoveCurrent(mmdl, gridX, gridY, gridZ, direction) & ~GIMMICK_D06_MOVE_FAIL_IGNORED;
        if (result != 0) {
            if (result & GIMMICK_D06_MOVE_FAIL_TERRAIN) {
                FLDMMDL_MOVE_GridToVectorPos(gridX, gridZ, &vec);
                vec.y = FLDMMDL_GetPosY(mmdl);
                result = MAP_ATTR_GetAt(mapper, &vec);
                if (result != -1) {
                    if (MAP_ATTR_IsElectricPanel(MAP_ATTR_GetTerrainId(result)) == 1)
                        found = 1;
                }
            }
            break;
        }
        i = i + 1;
    } while (i < maxSteps);
    if (found == 0)
        i = 0;
    *steps = i;
    return found;
}

/* Number of tiles the stone slides in a direction until it meets a panel (0 when it never does). */
int FIELD_GIMMICK_D06_GetSlideSteps(GimmickD06Work *work, GimmickD06StoneSlot *slot, int direction)
{
    unsigned int steps;

    FIELD_GIMMICK_D06_ScanSlide(work, slot, direction, GIMMICK_D06_SLIDE_SCAN_MAX, &steps);
    return steps;
}

/* 1 when the stone rests against a panel in any of the four directions. */
int FIELD_GIMMICK_D06_IsStoneNextToPanel(GimmickD06Work *work, GimmickD06StoneSlot *slot)
{
    unsigned short direction = 0;
    unsigned steps;

    do {
        if (FIELD_GIMMICK_D06_ScanSlide(work, slot, direction, 1, &steps) == 1)
            return 1;
        direction++;
    } while (direction < 4);
    return 0;
}

/*
 * Start the pulse effect of one panel.
 * note: Original 021F3CFE stores r0 after 021C9258, whose filed void
 *       definition leaves its final call result live; caller uses unsigned.
 */
void FIELD_GIMMICK_D06_AddPanelPulse(GimmickD06Work *work, struct FieldEffectObj **pulse, int gridX, int gridY, int gridZ)
{
    VecFx32 pos;

    FLDMMDL_MOVE_GridToVectorPos((short)gridX, (short)gridZ, &pos);
    pos.y = (int)(((unsigned)gridY << 16) + 0x8000u);
    *pulse = FLDEFF_D06DENKI_StartPulse(FIELDMAP_GetEffect(work->fieldMap), &pos);
}

/* Trigger the pulse of one panel. */
void FIELD_GIMMICK_D06_TriggerPanelPulse(struct FieldMap *fieldMap, int panelIndex)
{
    struct GimmickWork *gimmickWork = (struct GimmickWork *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    GimmickD06Work *work = ((GimmickD06Save *)GIMMICK_WORK_GetWork(gimmickWork, FIELD_GIMMICK_D06_GetGimmickId(FIELDMAP_GetZoneId(fieldMap))))->work;

    FLDEFF_D06DENKI_PulseTrigger(work->panelPulse[panelIndex]);
}

/* Add a stone object at a cell. */
struct Mmdl *FIELD_GIMMICK_D06_AddStoneMmdl(struct FieldMap *fieldMap, int gridX, int gridZ)
{
    struct MmdlSys *mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
    int zoneId = FIELDMAP_GetZoneId(fieldMap);

    return FLDMMDL_AddMmdlParam(mmdlSys, gridX, gridZ, 0, GIMMICK_D06_STONE_OBJ_ID, 0, 0, zoneId);
}

/* The work of the gimmick of the current zone. */
GimmickD06Work *FIELD_GIMMICK_D06_GetWork(struct FieldMap *fieldMap)
{
    struct GimmickWork *gimmickWork = (struct GimmickWork *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));

    return ((GimmickD06Save *)GIMMICK_WORK_GetWork(gimmickWork, FIELD_GIMMICK_D06_GetGimmickId(FIELDMAP_GetZoneId(fieldMap))))->work;
}

/* The gimmick id of the zone (the id of its save area); the first one for an unknown zone. */
int FIELD_GIMMICK_D06_GetGimmickId(int zoneId)
{
    switch (zoneId) {
    case GIMMICK_D06_ZONE_R0101:
        return GIMMICK_D06_GIMMICK_ID_R0101;
    case GIMMICK_D06_ZONE_R0102:
        return GIMMICK_D06_GIMMICK_ID_R0102;
    case GIMMICK_D06_ZONE_R0103:
        return GIMMICK_D06_GIMMICK_ID_R0103;
    }
    return GIMMICK_D06_GIMMICK_ID_R0101;
}
