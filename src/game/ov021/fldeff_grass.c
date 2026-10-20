/*
 * file:     fldeff_grass.c
 * unit:     yes
 * function: FLDEFF_GRASS_Create, FLDEFF_GRASS_Delete, FLDEFF_GRASS_CreateSlots, FLDEFF_GRASS_DeleteSlots, FLDEFF_GRASS_Start, FLDEFF_GRASS_Init, FLDEFF_GRASS_Exit, FLDEFF_GRASS_Update, FLDEFF_GRASS_Draw, FLDEFF_GRASS_IsModelOnTile
 * address:  0x021AC68C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_effect.c at 0x021AC68C: __FILE__ fldeff_grass.c on 0x021AC68C (init, first
 * function).
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   BILLBOARD_ACT_DeleteSlots  0x02050278  arm
 *   d_021DE070  0x021DE070  data
 *   FIELDMAP_GetGroundBbdAct  0x02188C90  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   BILLBOARD_ACT_CreateSlots  0x020500F0  arm
 *   gFldeffGrassImageFiles     0x021D911C  data  a2
 *   gFldeffGrassObjFuncs  0x021D90EC  data
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FLDMMDL_GetZoneId  0x0216D590  thumb  ov010
 *   FLDMMDL_GetPosY  0x0216D8AC  thumb  ov010
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   FIELD_EFFECT_GetModelBaseOffset  0x021ABE28  thumb  ov021
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   FIELD_EFFECT_ApplyPaletteTable  0x021AC1F0  thumb  ov021
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FLDMMDL_GetCheckInfo  0x0216E1A4  thumb  ov010
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   BILLBOARD_ACT_CreateEntries  0x02050340  arm
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   BILLBOARD_ACT_SetEntryCommands  0x02050804  arm
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm
 *   BILLBOARD_ACT_SetEntryEnabled  0x020507F0  arm
 *   FIELD_EFFECT_GetObjectMode  0x021AC1A0  thumb  ov021
 *   FIELD_EFFECT_UpdateObject  0x021AC178  thumb  ov021
 *   sGrassAnimeCommands     0x021DE050  data  a4
 *   FLDMMDL_CheckCheckInfo  0x0216E1C4  thumb  ov010
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   BILLBOARD_ACT_GetEntryLastCommand  0x020508EC  arm
 *   BILLBOARD_ACT_SetEntryCursor  0x0205085C  arm
 *   sGrassEndsOnLeave     0x021D90C0  data
 *   sGrassCommandCursor     0x021D90C8  data  a2
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb  ov010
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb  ov010
 *   BILLBOARD_ACT_DeleteEntries  0x02050468  arm  arm9
 */
#include "field_effect_types.h"
#include "../arm9/billboard_act_types.h"
#include "../ov010/fldmmdl_types.h"

/* Id of the grass resource in the field effect system. */
#define FLDEFF_ID_GRASS 2

/* The grass effect has eight billboard images. */
#define FLDEFF_GRASS_IMAGE_COUNT 8

/* Columns of the image file table (one per model base offset). */
#define FLDEFF_GRASS_FILE_COLUMNS 4

/* Billboard images are 32 by 32 pixels. */
#define FLDEFF_GRASS_IMAGE_SIZE_S 0x24
#define FLDEFF_GRASS_IMAGE_SIZE_T 0x20
#define FLDEFF_GRASS_IMAGE_PALETTE 0x20

/* Model status bit that selects the fixed grass height. */
#define FLDEFF_GRASS_FIXED_HEIGHT_BIT 0x2000

/* Grass height above the ground: fixed or above the map height. */
#define FLDEFF_GRASS_RAISE_FIXED 7
#define FLDEFF_GRASS_RAISE_MAP   9

/* The grass is drawn this far in front of the model. */
#define FLDEFF_GRASS_BACK_OFFSET 0x2000

/*
 * Resource of the grass effect (0x18 bytes, allocated by FLDEFF_GRASS_Create).
 * It owns eight billboard slots, one per grass image.
 */
typedef struct FldeffGrass {
    FieldEffectSys *fieldEffect;                       /* 0x00 */
    struct BbActSys *billboardAct;                     /* 0x04 billboard system of the ground */
    u16 slotId[FLDEFF_GRASS_IMAGE_COUNT];              /* 0x08 */
} FldeffGrass;

/* Start parameter of one grass (0x24 bytes). */
typedef struct FldeffGrassParam {
    FldeffGrass *grass;                   /* 0x00 */
    Mmdl *mmdl;                           /* 0x04 model that steps into the grass */
    int gridX;                            /* 0x08 */
    int gridZ;                            /* 0x0C */
    u16 objId;                            /* 0x10 object id of the model */
    u16 zoneId;                           /* 0x12 zone id of the model */
    VecFx32 pos;                          /* 0x14 */
    int index;                            /* 0x20 which of the eight images */
} FldeffGrassParam;

#include "../arm9/gfl_heap_wrap.h"
struct FieldMap;
struct GameSystem;
#include "fieldmap.h"
#include "../ov010/fldmmdl.h"
struct ArcHandle;
struct G3dResource;
#include "../arm9/g3d_system.h"
#include "../arm9/billboard_act.h"
#include "../ov010/fldmmdl_move.h"
struct Mmdl;
struct FieldEffectSys;
#include "field_effect.h"
FldeffGrass *FLDEFF_GRASS_Create(FieldEffectSys *sys, int heapId);
void FLDEFF_GRASS_Delete(FieldEffectSys *sys, FldeffGrass *grass);
void FLDEFF_GRASS_CreateSlots(FldeffGrass *grass);
void FLDEFF_GRASS_DeleteSlots(FldeffGrass *grass);
void FLDEFF_GRASS_Start(FieldEffectSys *sys, Mmdl *mmdl, u32 mode, int index);
extern char d_021DE070[];
extern u16 gFldeffGrassImageFiles[];
extern FieldEffectObjFuncs gFldeffGrassObjFuncs;

/* Work of one grass effect object. */
typedef struct GrassWork {
    u32 state;             /* 0x00 GRASS_STATE_* */
    FldeffGrassParam param; /* 0x04 */
    u16 checkInfo[4];      /* 0x28 model check info taken at the start */
    u16 entry;             /* 0x30 billboard entry of the effect */
} GrassWork;

#define GRASS_STATE_PLAY   0
#define GRASS_STATE_SETTLE 1
#define GRASS_STATE_HOLD_A 2
#define GRASS_STATE_HOLD_B 3

struct BbActCmd;
void FLDEFF_GRASS_Init(FieldEffectObj *effect, GrassWork *work);
void FLDEFF_GRASS_Exit(FieldEffectObj *effect, GrassWork *work);
void FLDEFF_GRASS_Update(FieldEffectObj *effect, GrassWork *work);
void FLDEFF_GRASS_Draw(void);
int FLDEFF_GRASS_IsModelOnTile(GrassWork *work);
extern u32 sGrassAnimeCommands[];                            /* grass: billboard animation commands of each kind */
extern u8 sGrassEndsOnLeave[];                             /* grass: 1 = the effect ends when the model leaves */
extern u16 sGrassCommandCursor[];                            /* grass: command cursor of each kind after the first play */

/* Resource creation: allocates the resource and makes the billboard slots. */
FldeffGrass *FLDEFF_GRASS_Create(FieldEffectSys *sys, int heapId)
{
    FldeffGrass *grass;

    grass = GFL_HEAP_Alloc(heapId, sizeof(FldeffGrass), 1, d_021DE070, 0x6c);
    grass->fieldEffect = sys;
    grass->billboardAct = FIELDMAP_GetGroundBbdAct((struct FieldMap *)FIELD_EFFECT_GetFieldMap(sys));
    FLDEFF_GRASS_CreateSlots(grass);
    return grass;
}









/* Resource deletion: frees the billboard slots and the resource. */
void FLDEFF_GRASS_Delete(FieldEffectSys *sys, FldeffGrass *grass)
{
    FLDEFF_GRASS_DeleteSlots(grass);
    GFL_HEAP_Free(grass);
}









/* Makes one billboard slot for each of the eight grass images. */
void FLDEFF_GRASS_CreateSlots(FldeffGrass *grass)
{
    struct BbActRec rec;
    int i;
    u32 arcHandle = FIELD_EFFECT_GetArcHandle(grass->fieldEffect);
    u16 *fileTable;
    u32 modelBase;
    FIELDMAP_GetGameSystem((struct FieldMap *)(FIELD_EFFECT_GetFieldMap(grass->fieldEffect)));
    modelBase = FIELD_EFFECT_GetModelBaseOffset(grass->fieldEffect);
    rec.format = 0;
    rec.sizeS = FLDEFF_GRASS_IMAGE_SIZE_S;
    rec.sizeT = FLDEFF_GRASS_IMAGE_SIZE_T;
    rec.paletteId = FLDEFF_GRASS_IMAGE_PALETTE;
    rec.kind = 1;
    fileTable = gFldeffGrassImageFiles + modelBase;
    for (i = 0; i < FLDEFF_GRASS_IMAGE_COUNT; i++) {
        rec.resource = (u32)G3D_SYSTEM_CreateResourceArcHandle((struct ArcHandle *)arcHandle, fileTable[i * FLDEFF_GRASS_FILE_COLUMNS]);
        FIELD_EFFECT_ApplyPaletteTable(grass->fieldEffect, (void *)rec.resource);
        grass->slotId[i] = BILLBOARD_ACT_CreateSlots(grass->billboardAct, &rec, 1);
    }
}





/* Frees the eight billboard slots. */
void FLDEFF_GRASS_DeleteSlots(FldeffGrass *grass)
{
    int i;

    for (i = 0; i < FLDEFF_GRASS_IMAGE_COUNT; i++)
        BILLBOARD_ACT_DeleteSlots(grass->billboardAct, grass->slotId[i], 1);
}





/*
 * The pos.z -= FLDEFF_GRASS_BACK_OFFSET adjust is written in both arms of the if; the
 * compiler tail-merges the arms and keeps the 2 of 0x2000 in r6
 * (docs/idioms/a-constant-shifted-in-a-merged-tail-is-a-statement-repeated-in-each-arm.md).
 */
/* Starts a grass effect under a model, drawn with one of the eight images. */
void FLDEFF_GRASS_Start(FieldEffectSys *sys, Mmdl *mmdl, u32 mode, int index)
{
    VecFx32 pos;
    FldeffGrassParam param;
    int mapHeight;

    if (index >= FLDEFF_GRASS_IMAGE_COUNT)
        return;
    param.grass = (struct FldeffGrass *)FIELD_EFFECT_GetResource(sys, FLDEFF_ID_GRASS);
    param.mmdl = mmdl;
    param.index = index;
    param.objId = FLDMMDL_GetObjId(mmdl);
    param.zoneId = FLDMMDL_GetZoneId(mmdl);
    param.gridX = FLDMMDL_GetGridNowX(mmdl);
    param.gridZ = FLDMMDL_GetGridNowZ(mmdl);
    FLDMMDL_MOVE_GridToVectorPos((s16)param.gridX, (s16)param.gridZ, &pos);
    pos.y = FLDMMDL_GetPosY(mmdl);
    if (FLDMMDL_CheckStatusBit(mmdl, FLDEFF_GRASS_FIXED_HEIGHT_BIT) != 0) {
        pos.y += FLDEFF_GRASS_RAISE_FIXED * 0x1000;
        pos.z -= FLDEFF_GRASS_BACK_OFFSET;
    } else {
        FLDMMDL_MOVE_GetMapHeight(mmdl, &pos, &mapHeight);
        pos.y = mapHeight + FLDEFF_GRASS_RAISE_MAP * 0x1000;
        pos.z -= FLDEFF_GRASS_BACK_OFFSET;
    }
    param.pos = pos;
    FIELD_EFFECT_AddObject(sys, &gFldeffGrassObjFuncs, 0, mode, &param, 0);
}

/* Grass effect init: shows the billboard of the kind and starts its animation. */
void FLDEFF_GRASS_Init(FieldEffectObj *effect, GrassWork *work)
{
    FldeffGrassParam *param = FIELD_EFFECT_GetObjectParam(effect);
    struct BbActDesc desc;
    u16 kind;
    u32 billboards;
    u16 entry;

    work->param = *param;
    FLDMMDL_GetCheckInfo( (Mmdl *)param->mmdl, (MmdlCheckInfo *)work->checkInfo);
    FIELD_EFFECT_SetObjectPos(effect, &param->pos);
    kind = work->param.index;
    desc.slot = work->param.grass->slotId[kind];
    desc.width = 0x2000;
    desc.height = 0x2000;
    desc.layer = 0x1f;
    desc.flags = 1;
    desc.color = 1;
    desc.pos = param->pos;
    desc.hook = 0;
    desc.hookArg = (u32)work;
    billboards = (u32)work->param.grass->billboardAct;
    work->entry = BILLBOARD_ACT_CreateEntries((struct BbActSys *)billboards, 0, &desc, 1, 0);
    if (work->entry == 0xFFFF) {
        FIELD_EFFECT_DeleteObject(effect);
        return;
    }
    BILLBOARD_ACT_SetEntryCommands((struct BbActSys *)billboards, work->entry, (struct BbActCmd **)sGrassAnimeCommands[kind], 1);
    entry = work->entry;
    BILLBOARD_ACT_SetEntryList((struct BbActSys *)billboards, entry, 0);
    BILLBOARD_ACT_SetEntryEnabled((struct BbActSys *)billboards, entry, 1);
    if (FIELD_EFFECT_GetObjectMode(effect) == 0)
        work->state = GRASS_STATE_SETTLE;
    FIELD_EFFECT_UpdateObject(effect);
}

/* Grass effect exit: removes the billboard. */
void FLDEFF_GRASS_Exit(FieldEffectObj *effect, GrassWork *work)
{
    u32 billboards = (u32)work->param.grass->billboardAct;

    if (work->entry != 0xFFFF)
        BILLBOARD_ACT_DeleteEntries((struct BbActSys *)billboards, work->entry, 1);
}

/*
 * Compiled 212 of a 216-byte extent: the follower at 0x021AC9D4 is an
 * unlabelled `bx lr` stub.
 *
 * Addresses are Black-image addresses.
 */
/* Grass effect update: plays the animation, then keeps the grass while the model stays on the tile. */
void FLDEFF_GRASS_Update(FieldEffectObj *effect, GrassWork *work)
{
    u32 billboards = (u32)work->param.grass->billboardAct;
    Mmdl *mmdl;
    u16 lastCommand;

    switch (work->state) {
    case GRASS_STATE_PLAY:
        if (sGrassEndsOnLeave[work->param.index] == 1) {
            mmdl = work->param.mmdl;
            if (FLDMMDL_CheckCheckInfo( (Mmdl *)mmdl, (const MmdlCheckInfo *)work->checkInfo) == 1 && FLDEFF_GRASS_IsModelOnTile(work) == 0 && FLDMMDL_GetDirMove( (Mmdl *)mmdl) == 1) {
                FIELD_EFFECT_DeleteObject(effect);
                return;
            }
        }
        if (BILLBOARD_ACT_GetEntryLastCommand((struct BbActSys *)billboards, work->entry, &lastCommand) != 0)
            work->state++;
        break;
    case GRASS_STATE_SETTLE:
        if (FLDMMDL_CheckCheckInfo( (Mmdl *)work->param.mmdl, (const MmdlCheckInfo *)work->checkInfo) == 0) {
            FIELD_EFFECT_DeleteObject(effect);
            return;
        }
        BILLBOARD_ACT_SetEntryCursor((struct BbActSys *)billboards, work->entry, sGrassCommandCursor[work->param.index]);
        work->state++;
        break;
    case GRASS_STATE_HOLD_A:
        work->state++;
    case GRASS_STATE_HOLD_B:
        if (FLDMMDL_CheckCheckInfo( (Mmdl *)work->param.mmdl, (const MmdlCheckInfo *)work->checkInfo) == 0) {
            FIELD_EFFECT_DeleteObject(effect);
            return;
        }
        if (FLDEFF_GRASS_IsModelOnTile(work) == 0)
            FIELD_EFFECT_DeleteObject(effect);
        break;
    }
}

/* Grass effect draw: empty, the billboard system draws the grass. */
void FLDEFF_GRASS_Draw(void) {}

/* Returns 1 when the model stands on the tile of the effect, or just left it while still moving off. */
int FLDEFF_GRASS_IsModelOnTile(GrassWork *work)
{
    Mmdl *mmdl = work->param.mmdl;
    u32 x = FLDMMDL_GetGridNowX(mmdl);
    u32 z = FLDMMDL_GetGridNowZ(mmdl);
    u32 leaveEnds = sGrassEndsOnLeave[work->param.index];
    if (work->param.gridX == x && work->param.gridZ == z)
        goto onTile;
    if (leaveEnds == 0 && FLDMMDL_GetDirMove(mmdl) == 0) {
        x = FLDMMDL_GetGridOldX(mmdl);
        z = FLDMMDL_GetGridOldZ(mmdl);
        if (work->param.gridX == x && work->param.gridZ == z)
            return 1;
    }
    return 0;
onTile:
    return 1;
}
