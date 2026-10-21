/*
 * file:     fldeff_splash.c
 * unit:     yes
 * function: FLDEFF_SPLASH_CreateBoardRes, FLDEFF_SPLASH_DeleteBoardRes, FLDEFF_SPLASH_LoadBoardImage, FLDEFF_SPLASH_UnloadBoardImage, FLDEFF_SPLASH_AddBoard, FLDEFF_SPLASH_InitBoardObj, FLDEFF_SPLASH_ExitBoardObj, FLDEFF_SPLASH_UpdateBoardObj, FLDEFF_SPLASH_DrawBoardObj, FLDEFF_SPLASH_CreateModelRes, FLDEFF_SPLASH_DeleteModelRes, FLDEFF_SPLASH_LoadModel, FLDEFF_SPLASH_UnloadModel, FLDEFF_SPLASH_AddModel, FLDEFF_SPLASH_InitModelObj, FLDEFF_SPLASH_ExitModelObj, FLDEFF_SPLASH_UpdateModelObj, FLDEFF_SPLASH_DrawModelObj
 * address:  0x021C4978
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   BILLBOARD_ACT_CreateEntries  0x02050340  arm
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   BILLBOARD_ACT_SetEntryCommands  0x02050804  arm
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm
 *   BILLBOARD_ACT_SetEntryEnabled  0x020507F0  arm
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FIELDMAP_GetGroundBbdAct  0x02188C90  thumb  ov021
 *   gFldeffSplashFileName     0x021DE47C  data  ov021
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   FIELD_EFFECT_ApplyPaletteTable  0x021AC1F0  thumb  ov021
 *   BILLBOARD_ACT_CreateSlots  0x020500F0  arm
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   gSplashBoardObjFuncs     0x021DAA2C  data  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   gSplashBoardCommands     0x021DE478  data  a4
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_G3DOBJ_InitResDesc  0x021C6AE0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescModel  0x021C6AF0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescAnimeArc  0x021C6AF8  thumb  ov021
 *   FIELD_G3DOBJ_AddResDescAnimeFile  0x021C6AFC  thumb  ov021
 *   FIELD_G3DOBJ_AddResourceDefaultPal  0x021C6574  thumb  ov021
 *   FIELD_G3DOBJ_AddObject  0x021C6590  thumb  ov021
 *   FIELD_G3DOBJ_SetObjectManualDraw  0x021C67D8  thumb  ov021
 *   FIELD_G3DOBJ_DeleteObject  0x021C6628  thumb  ov021
 *   FIELD_G3DOBJ_DeleteResource  0x021C6580  thumb  ov021
 *   gSplashModelObjFuncs     0x021DAA18  data  ov021
 *   FLDMMDL_GetCheckInfo  0x0216E1A4  thumb  ov010
 *   FLDMMDL_CheckCheckInfo  0x0216E1C4  thumb  ov010
 *   FLDMMDL_CheckMoveBitSplash  0x0216DBE8  thumb  ov010
 *   FIELD_G3DOBJ_GetObjectTrans  0x021C6658  thumb  ov021
 *   FIELD_G3DOBJ_GetObjectRedrawFlag  0x021C6844  thumb  ov021
 *   FIELD_G3DOBJ_LoopAnimeFrame  0x021C66EC  thumb  ov021
 *   FIELD_G3DOBJ_SetObjectRedrawFlag  0x021C6828  thumb  ov021
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   FIELD_G3DOBJ_DrawObject  0x021C67F4  thumb  ov021
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   abs_id_C2      0x000000C2  data
 *   ov171_id       0x000000AB  data  a1
 *   BILLBOARD_ACT_DeleteSlots  0x02050278  arm  arm9
 *   BILLBOARD_ACT_DeleteEntries  0x02050468  arm  arm9
 *   BILLBOARD_ACT_GetEntryLastCommand  0x020508EC  arm  arm9
 */
#include "field_effect_types.h"
#include "../ov010/fldmmdl_types.h"

struct BbActDesc;
struct BbActSys;
struct BbActRec;
#include "../arm9/billboard_act_types.h"
struct FieldEffectSys;
struct ClactActor;
struct IcaAnime;
struct Rec12;
struct Mtx33;
struct Big;
struct BgTemplate;
struct Unit;
struct GfFont;
struct MsgBank;
struct Obj;
struct PrintSys;
struct Rec;
struct Node;
struct Descriptor;
struct Cfg;
struct Slot;
struct Src;
struct PtS;
struct Vec2;
struct Desc;
struct Evt;
struct BigObj;
struct Ctx;
struct RecordBlock;
struct Self;
struct S0201235C;

#include "../types.h"

#include "../sdk_fx.h"

typedef struct FldEffBbRes {
    u32 unused00;
    struct BbActSys *actSys;              /* 0x04 */
    u16 imageIdx;                         /* 0x08 */
} FldEffBbRes;

/* Splash, billboard kind: record made by FLDEFF_SPLASH_CreateBoardRes (0xC bytes). */
typedef struct SplashBoardRes {
    FieldEffectSys *sys;
    struct BbActSys *actSys;
    u16 imageIdx;
} SplashBoardRes;

typedef struct SplashBoardParam {
    SplashBoardRes *res;
    Mmdl *mmdl;
} SplashBoardParam;

typedef struct SplashBoardWork {
    SplashBoardParam param;
    u16 entryId;
} SplashBoardWork;

/* Splash, model kind: record made by FLDEFF_SPLASH_CreateModelRes (8 bytes). */
typedef struct SplashModelRes {
    FieldEffectSys *sys;
    u16 resIdx;
    u16 objIdx;
} SplashModelRes;

typedef struct SplashModelParam {
    SplashModelRes *res;
    Mmdl *mmdl;
} SplashModelParam;

typedef struct SplashModelWork {
    SplashModelParam param;
    u32 checkInfo[2];
    u16 objIdx;
} SplashModelWork;

#include "field_effect.h"
#include "../arm9/billboard_act.h"
struct BbActCmd;
#include "../arm9/gfl_heap_wrap.h"
struct FieldMap;
#include "fieldmap.h"
struct ArcHandle;
struct G3dResource;
#include "../arm9/g3d_system.h"
struct FieldEffectObjFuncs;
struct VecFx32;
struct Mmdl;
#include "../ov010/fldmmdl.h"
struct FieldG3dObjResDesc;
#include "field_g3dobj.h"
struct FieldG3dObjCtrl;
struct MmdlCheckInfo;
/* Retain the mode used to store f59 for the helper's second argument. */
SplashBoardRes *FLDEFF_SPLASH_CreateBoardRes(FieldEffectSys *sys, u32 heapId);
void FLDEFF_SPLASH_DeleteBoardRes(u32 unused, SplashBoardRes *res);
void FLDEFF_SPLASH_LoadBoardImage(SplashBoardRes *res);
void FLDEFF_SPLASH_UnloadBoardImage(SplashBoardRes *res);
void FLDEFF_SPLASH_AddBoard(FieldEffectSys *sys, Mmdl *mmdl);
void FLDEFF_SPLASH_InitBoardObj(FieldEffectObj *obj, SplashBoardWork *work);
void FLDEFF_SPLASH_ExitBoardObj(FieldEffectObj *obj, SplashBoardWork *work);
void FLDEFF_SPLASH_UpdateBoardObj(FieldEffectObj *obj, SplashBoardWork *work);
void FLDEFF_SPLASH_DrawBoardObj(void);
SplashModelRes *FLDEFF_SPLASH_CreateModelRes(FieldEffectSys *sys, u32 heapId);
void FLDEFF_SPLASH_DeleteModelRes(u32 unused, SplashModelRes *res);
void FLDEFF_SPLASH_LoadModel(SplashModelRes *res);
void FLDEFF_SPLASH_UnloadModel(SplashModelRes *res);
void FLDEFF_SPLASH_AddModel(FieldEffectSys *sys, Mmdl *mmdl);
void FLDEFF_SPLASH_InitModelObj(FieldEffectObj *obj, SplashModelWork *work);
void FLDEFF_SPLASH_ExitModelObj(void);
void FLDEFF_SPLASH_UpdateModelObj(FieldEffectObj *obj, SplashModelWork *work);
void FLDEFF_SPLASH_DrawModelObj(FieldEffectObj *obj, SplashModelWork *work);
extern char gFldeffSplashFileName[];
extern char gSplashBoardObjFuncs[];
extern u8 gSplashBoardCommands[];
extern char gSplashModelObjFuncs[];
extern unsigned char abs_id_C2[];
extern char ov171_id[];

/* Splash, billboard kind: allocates the record (0xC bytes) and loads its image. */
SplashBoardRes *FLDEFF_SPLASH_CreateBoardRes(FieldEffectSys *sys, u32 heapId)
{
    SplashBoardRes *res = GFL_HEAP_Alloc(heapId, 0xC, 1, gFldeffSplashFileName, 0x7D);

    res->sys = sys;
    res->actSys = (struct BbActSys *)FIELDMAP_GetGroundBbdAct((struct FieldMap *)FIELD_EFFECT_GetFieldMap((struct FieldEffectSys *)sys));
    FLDEFF_SPLASH_LoadBoardImage(res);
    return res;
}

/* Deletes the record. */
void FLDEFF_SPLASH_DeleteBoardRes(u32 unused, SplashBoardRes *res)
{
    FLDEFF_SPLASH_UnloadBoardImage(res);
    GFL_HEAP_Free(res);
}

/* Registers the splash image in the ground billboard system. */
void FLDEFF_SPLASH_LoadBoardImage(SplashBoardRes *res)
{
    BbActRec rec;
    struct ArcHandle *arcHandle = FIELD_EFFECT_GetArcHandle((struct FieldEffectSys *)res->sys);

    rec.format = 2;
    rec.sizeS = 0x13;
    rec.sizeT = 0x10;
    rec.paletteId = 0x10;
    rec.kind = 1;
    rec.resource = (uptr)G3D_SYSTEM_CreateResourceArcHandle(arcHandle, 0x2d);
    FIELD_EFFECT_ApplyPaletteTable((struct FieldEffectSys *)res->sys, (void *)rec.resource);
    res->imageIdx = BILLBOARD_ACT_CreateSlots(res->actSys, &rec, 1);
}

/* Releases the splash image. */
void FLDEFF_SPLASH_UnloadBoardImage(SplashBoardRes *res)
{
    BILLBOARD_ACT_DeleteSlots(res->actSys, res->imageIdx, 1);
}

/* Adds one splash board object for the model mmdl. */
void FLDEFF_SPLASH_AddBoard(FieldEffectSys *sys, Mmdl *mmdl)
{
    SplashBoardParam param;

    param.res = (SplashBoardRes *)FIELD_EFFECT_GetResource((struct FieldEffectSys *)sys, 8);
    param.mmdl = mmdl;
    FIELD_EFFECT_AddObject(sys, (struct FieldEffectObjFuncs *)gSplashBoardObjFuncs, 0, 0, &param, 0);
}

/* Init: starts the billboard entry above the model. */
void FLDEFF_SPLASH_InitBoardObj(FieldEffectObj *obj, SplashBoardWork *work)
{
    SplashBoardParam *param = (SplashBoardParam *)FIELD_EFFECT_GetObjectParam(obj);
    FldEffBbRes *bbRes;
    struct BbActSys *actSys; u32 entryId;
    VecFx32 pos;
    BbActDesc desc;

    work->param = *param;
    FLDMMDL_GetPos(work->param.mmdl, (struct VecFx32 *)(&pos));
    bbRes = (FldEffBbRes *)work->param.res;
    actSys = bbRes->actSys;
    pos.y -= 0xE000;
    pos.z -= 0xA000;
    desc.slot = bbRes->imageIdx;
    desc.width = 0x1000;
    desc.height = 0x1000;
    desc.layer = 0x1f;
    desc.flags = 1;
    desc.color = 1;
    desc.pos = pos;
    desc.hook = 0;
    desc.hookArg = (uptr)work;
    work->entryId = BILLBOARD_ACT_CreateEntries(actSys, 0, &desc, 1, 3);
    if (work->entryId == 0xFFFF) {
        FIELD_EFFECT_DeleteObject(obj);
        return;
    }
    BILLBOARD_ACT_SetEntryCommands(actSys, work->entryId, (struct BbActCmd **)gSplashBoardCommands, 1);
    entryId = work->entryId;
    BILLBOARD_ACT_SetEntryList(actSys, entryId, 0);
    BILLBOARD_ACT_SetEntryEnabled(actSys, entryId, 1);
}

/* Exit: deletes the billboard entry unless the creation failed. */
void FLDEFF_SPLASH_ExitBoardObj(FieldEffectObj *obj, SplashBoardWork *work)
{
    struct BbActSys *actSys = work->param.res->actSys;

    if (work->entryId != 0xFFFF)
        BILLBOARD_ACT_DeleteEntries(actSys, work->entryId, 1);
}

/* Update: ends the effect when the entry has run its last command. */
void FLDEFF_SPLASH_UpdateBoardObj(FieldEffectObj *obj, SplashBoardWork *work)
{
    u32 lastCommand;

    if (BILLBOARD_ACT_GetEntryLastCommand((struct BbActSys *)work->param.res->actSys, work->entryId, (u16 *)(&lastCommand)) != 0)
        FIELD_EFFECT_DeleteObject(obj);
}

/* Draw: nothing to do. */
void FLDEFF_SPLASH_DrawBoardObj(void) {}

/* Splash, model kind: allocates the record (8 bytes) and loads its model. */
SplashModelRes *FLDEFF_SPLASH_CreateModelRes(FieldEffectSys *sys, u32 heapId)
{
    SplashModelRes *res = GFL_HEAP_Alloc(heapId, 8, 1, gFldeffSplashFileName, 0x163);

    res->sys = sys;
    FLDEFF_SPLASH_LoadModel(res);
    return res;
}

/* Deletes the record. */
void FLDEFF_SPLASH_DeleteModelRes(u32 unused, SplashModelRes *res)
{
    FLDEFF_SPLASH_UnloadModel(res);
    GFL_HEAP_Free(res);
}

/* Loads the splash model resource and creates its object (hidden from the batch draw). */
void FLDEFF_SPLASH_LoadModel(SplashModelRes *res)
{
    u32 resDesc[9];
    struct FieldG3dObjCtrl *g3dObjCtrl = FIELD_EFFECT_GetFieldMapData((struct FieldEffectSys *)res->sys);
    struct ArcHandle *arcHandle = FIELD_EFFECT_GetArcHandle((struct FieldEffectSys *)res->sys);

    FIELD_G3DOBJ_InitResDesc((struct FieldG3dObjResDesc *)resDesc);
    FIELD_G3DOBJ_SetResDescModel((struct FieldG3dObjResDesc *)resDesc, arcHandle, 0x5f);
    FIELD_G3DOBJ_SetResDescAnimeArc((struct FieldG3dObjResDesc *)resDesc, arcHandle);
    FIELD_G3DOBJ_AddResDescAnimeFile((struct FieldG3dObjResDesc *)resDesc, 0x6a);
    res->resIdx = FIELD_G3DOBJ_AddResourceDefaultPal(g3dObjCtrl, (struct FieldG3dObjResDesc *)resDesc, 0);
    res->objIdx = FIELD_G3DOBJ_AddObject(g3dObjCtrl, res->resIdx, 0, 0);
    FIELD_G3DOBJ_SetObjectManualDraw(g3dObjCtrl, res->objIdx, 1);
}

/* Deletes the model object and its resource. */
void FLDEFF_SPLASH_UnloadModel(SplashModelRes *res)
{
    struct FieldG3dObjCtrl *g3dObjCtrl = FIELD_EFFECT_GetFieldMapData((struct FieldEffectSys *)res->sys);

    FIELD_G3DOBJ_DeleteObject(g3dObjCtrl, res->objIdx);
    FIELD_G3DOBJ_DeleteResource(g3dObjCtrl, res->resIdx);
}

/* Adds one splash model object for the model mmdl. */
void FLDEFF_SPLASH_AddModel(FieldEffectSys *sys, Mmdl *mmdl)
{
    SplashModelParam param;

    param.res = (SplashModelRes *)FIELD_EFFECT_GetResource((struct FieldEffectSys *)sys, 0x11);
    param.mmdl = mmdl;
    FIELD_EFFECT_AddObject(sys, (struct FieldEffectObjFuncs *)gSplashModelObjFuncs, 0, 0, &param, 0);
}

/* Init: copies the parameter and puts the object under the model. */
void FLDEFF_SPLASH_InitModelObj(FieldEffectObj *obj, SplashModelWork *work)
{
    VecFx32 pos;
    SplashModelParam *param = (SplashModelParam *)FIELD_EFFECT_GetObjectParam(obj);

    work->param = *param;
    FLDMMDL_GetCheckInfo(work->param.mmdl, (struct MmdlCheckInfo *)work->checkInfo);
    FLDMMDL_GetPos(work->param.mmdl, (struct VecFx32 *)(&pos));
    pos.z += 0x8000;
    FIELD_EFFECT_SetObjectPos(obj, &pos);
    work->objIdx = work->param.res->objIdx;
}

/* Exit: nothing to do. */
void FLDEFF_SPLASH_ExitModelObj(void) {}

/* Update: follows the model while it stays in the water; ends the effect otherwise. */
void FLDEFF_SPLASH_UpdateModelObj(FieldEffectObj *obj, SplashModelWork *work)
{
    VecFx32 pos;
    int objIdx;
    struct FieldG3dObjCtrl *g3dObjCtrl;

    if (FLDMMDL_CheckCheckInfo(work->param.mmdl, (struct MmdlCheckInfo *)work->checkInfo) == 0) {
        FIELD_EFFECT_DeleteObject(obj);
        return;
    }
    if (FLDMMDL_CheckMoveBitSplash(work->param.mmdl) == 0) {
        FIELD_EFFECT_DeleteObject(obj);
        return;
    }
    objIdx = work->objIdx;
    g3dObjCtrl = FIELD_EFFECT_GetFieldMapData((struct FieldEffectSys *)work->param.res->sys);
    FIELD_G3DOBJ_GetObjectTrans(g3dObjCtrl, objIdx);
    if (FIELD_G3DOBJ_GetObjectRedrawFlag(g3dObjCtrl, objIdx) == 0) {
        FIELD_G3DOBJ_LoopAnimeFrame(g3dObjCtrl, objIdx, 0x1000);
        FIELD_G3DOBJ_SetObjectRedrawFlag(g3dObjCtrl, objIdx, 1);
    }
    FLDMMDL_GetPos(work->param.mmdl, (struct VecFx32 *)(&pos));
    pos.z += 0x8000;
    FIELD_EFFECT_SetObjectPos(obj, &pos);
}

/* Draw: copies the effect object position into the model object. */
void FLDEFF_SPLASH_DrawModelObj(FieldEffectObj *obj, SplashModelWork *work)
{
    u16 objIdx = work->objIdx;
    struct FieldG3dObjCtrl *g3dObjCtrl = FIELD_EFFECT_GetFieldMapData((struct FieldEffectSys *)work->param.res->sys);
    VecFx32 *dst = &FIELD_G3DOBJ_GetObjectTrans(g3dObjCtrl, objIdx)->trans;
    VecFx32 pos;

    FIELD_EFFECT_GetObjectPos(obj, &pos);
    *dst = pos;
    FIELD_G3DOBJ_DrawObject(g3dObjCtrl, objIdx);
}
