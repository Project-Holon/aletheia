/*
 * file:     fieldmap_ctrl_grid.c
 * unit:     yes
 * function: FIELDMAP_CTRL_GRID_Create, FIELDMAP_CTRL_GRID_Destroy, FIELDMAP_CTRL_GRID_Main, FIELDMAP_CTRL_GRID_GetTargetPos, FIELDMAP_CTRL_GRID_SetBusy
 * address:  0x021A2D88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from weather_task.c (lane L141): __FILE__ anchor 021A2DE0 (gFieldMapCtrlGridFileName "fieldmap_ctrl_grid.c"); 021A2D88 allocates the 0x10 holder, 021A2D30 before it is called from weather_task code.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_GetPosPtr  0x0216D888  thumb  ov010
 *   FIELDMAP_SetTargetPos  0x02188D40  thumb  ov021
 *   FIELDMAP_SetCtrlWork  0x02188CAC  thumb  ov021
 *   gFieldMapCtrlGridFileName     0x021DDE90  data  a4
 *   FIELDMAP_GetCtrlWork  0x02188CA4  thumb  ov021
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetCont  0x0203630C  arm
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_PLAYER_CheckMoveRestrictFlag  0x021A35BC  thumb  ov021
 *   FIELD_PLAYER_CreateGrid  0x021A35E0  thumb  ov021
 *   FIELD_PLAYER_MoveGrid  0x021A35F0  thumb  ov021
 */
#include "fieldmap_types.h"

typedef unsigned short u16;
typedef unsigned int u32;

struct FieldPlayer;
struct Mmdl;

/* The grid map control work (0x10 bytes), kept in FieldMap.ctrlWork. */
typedef struct FieldMapCtrlGridWork {
    u16 heapId;             /* 0x00 */
    u16 heapIdPad;          /* 0x02: alignment, never read */
    FieldMap *fieldMap;     /* 0x04 */
    u32 reserved;           /* 0x08: cleared by the allocation, never used */
    u32 busy;               /* 0x0C: set from outside (union room) to stop the player update */
} FieldMapCtrlGridWork;

extern u32 GFL_HEAP_Free(void *memory);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *fileName, u16 line);
extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetCont(void);
extern u16 FIELDMAP_GetHeapId(FieldMap *fieldMap);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);
extern void FIELDMAP_SetCtrlWork(FieldMap *fieldMap, void *ctrlWork);
extern void *FIELDMAP_GetCtrlWork(FieldMap *fieldMap);
extern void FIELDMAP_SetTargetPos(FieldMap *fieldMap, VecFx32 *targetPos);
extern void FLDMMDL_SetDirDispCheckPause(struct Mmdl *mmdl, int dir);
extern VecFx32 *FLDMMDL_GetPosPtr(struct Mmdl *mmdl);
extern struct Mmdl *FIELD_PLAYER_GetMmdl(struct FieldPlayer *player);
extern int FIELD_PLAYER_CheckMoveRestrictFlag(struct FieldPlayer *player);
extern void FIELD_PLAYER_CreateGrid(struct FieldPlayer *player, u32 heapId);
extern void FIELD_PLAYER_MoveGrid(struct FieldPlayer *player, u32 keyTrg, u32 keyCont, u32 flags);
extern int gFieldMapCtrlGridFileName;

void FIELDMAP_CTRL_GRID_Create(FieldMap *fieldMap, VecFx32 *pos, int dir);
void FIELDMAP_CTRL_GRID_Destroy(FieldMap *fieldMap);
void FIELDMAP_CTRL_GRID_Main(FieldMap *fieldMap, VecFx32 *pos);
VecFx32 *FIELDMAP_CTRL_GRID_GetTargetPos(FieldMap *fieldMap);
void FIELDMAP_CTRL_GRID_SetBusy(FieldMap *fieldMap, u32 busy);

/* Creates the grid control: the player walks on the grid and the camera targets its position. */
void FIELDMAP_CTRL_GRID_Create(FieldMap *fieldMap, VecFx32 *pos, int dir)
{
    int heapId;
    struct FieldPlayer *player;
    struct Mmdl *mmdl;
    FieldMapCtrlGridWork *work;

    heapId = FIELDMAP_GetHeapId(fieldMap);
    work = GFL_HEAP_Alloc(heapId, sizeof(FieldMapCtrlGridWork), 1, (const char *)&gFieldMapCtrlGridFileName, 0x68);
    work->heapId = heapId;
    work->fieldMap = fieldMap;
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    mmdl = FIELD_PLAYER_GetMmdl(player);
    FLDMMDL_SetDirDispCheckPause(mmdl, dir);
    FIELD_PLAYER_CreateGrid(player, heapId);
    FIELDMAP_SetTargetPos(fieldMap, FLDMMDL_GetPosPtr(mmdl));
    FIELDMAP_SetCtrlWork(fieldMap, work);
}

/* Destroy slot: frees the work. */
void FIELDMAP_CTRL_GRID_Destroy(FieldMap *fieldMap)
{
    GFL_HEAP_Free(FIELDMAP_GetCtrlWork(fieldMap));
}

/* Main slot: moves the player with this frame's keys unless the work is busy. */
void FIELDMAP_CTRL_GRID_Main(FieldMap *fieldMap, VecFx32 *pos)
{
    FieldMapCtrlGridWork *work = FIELDMAP_GetCtrlWork(fieldMap);
    struct FieldPlayer *player = FIELDMAP_GetFieldPlayer(fieldMap);

    if (work->busy == 0) {
        u32 keyTrg = KEY_GetTrg();
        u32 keyCont = KEY_GetCont();
        u32 flags = 0;

        if (FIELD_PLAYER_CheckMoveRestrictFlag(player) == 1)
            flags |= 1;
        FIELD_PLAYER_MoveGrid(player, keyTrg, keyCont, flags);
    }
}

/* Position of the player's model, the point the camera follows. */
VecFx32 *FIELDMAP_CTRL_GRID_GetTargetPos(FieldMap *fieldMap)
{
    return FLDMMDL_GetPosPtr(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)));
}

void FIELDMAP_CTRL_GRID_SetBusy(FieldMap *fieldMap, u32 busy)
{
    ((FieldMapCtrlGridWork *)FIELDMAP_GetCtrlWork(fieldMap))->busy = busy;
}
