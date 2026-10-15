/*
 * file:     field_g3dobj.c
 * unit:     yes
 * function: SWEET_SCENT_CreateEventNoPokemon, SWEET_SCENT_CreateEvent, SWEET_SCENT_EventMain, SWEET_SCENT_CheckWeatherClear, SWEET_SCENT_StartFade, SWEET_SCENT_FadeMain, SWEET_SCENT_FadeSetup, SWEET_SCENT_FadeCleanup, FIELD_G3DOBJ_Create, FIELD_G3DOBJ_Delete, FIELD_G3DOBJ_Update, FIELD_G3DOBJ_DrawAll, FIELD_G3DOBJ_SetPalTable, FIELD_G3DOBJ_AddResource, FIELD_G3DOBJ_AddResourceDefaultPal, FIELD_G3DOBJ_DeleteResource, FIELD_G3DOBJ_AddObject, FIELD_G3DOBJ_DeleteObject, FIELD_G3DOBJ_GetObjectTrans, FIELD_G3DOBJ_SetObjectTrans, FIELD_G3DOBJ_SetObjectHidden, FIELD_G3DOBJ_IncAnimeFrame, FIELD_G3DOBJ_LoopAnimeFrame, FIELD_G3DOBJ_SetAnimeFrame, FIELD_G3DOBJ_GetAnimeFrame, FIELD_G3DOBJ_SetObjectManualDraw, FIELD_G3DOBJ_DrawObject, FIELD_G3DOBJ_SetObjectRedrawFlag, FIELD_G3DOBJ_GetObjectRedrawFlag, FIELD_G3DOBJ_TransferResourceTexture, FIELD_G3DOBJ_LoadResource, FIELD_G3DOBJ_FreeResource, FIELD_G3DOBJ_CreateObject, FIELD_G3DOBJ_DestroyObject, FIELD_G3DOBJ_InitResDesc, FIELD_G3DOBJ_SetResDescModel, FIELD_G3DOBJ_SetResDescAnimeArc, FIELD_G3DOBJ_AddResDescAnimeFile, FIELDMAP_TCB_CAMERA_ZOOM_Create, FIELDMAP_TCB_CAMERA_ZOOM_Main, FIELDMAP_TCB_CAMERA_ZOOM_Step
 * address:  0x021C6068
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
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   FIELD_PLAYER_StartFormChange  0x021A2F48  thumb  ov021
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   FIELDMAP_GetFld3dCi  0x02189A00  thumb  ov021
 *   FLD3D_CI_StartPartyMemberSequence  0x021C1D68  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   FIELD_ENCOUNT_CheckWildEncount  0x021A9F40  thumb  ov021
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   FIELDMAP_GetWeather  0x02188C6C  thumb  ov021
 *   WEATHER_GetWeatherId  0x021A1BF4  thumb  ov021
 *   FIELDMAP_GetVReq  0x02188E30  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLD_VREQ_SetMainBlendAlphaEv  0x021D3288  thumb  ov021
 *   FLD_VREQ_SetMainBlendAlpha  0x021D325C  thumb  ov021
 *   FLD_VREQ_SetBgVisible  0x021D3244  thumb  ov021
 *   gSweetScentFadeBgPos     0x021DAAB4  data  a2
 *   func_02040588  0x02040588  arm
 *   func_02040E78  0x02040E78  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_02030734  0x02030734  arm
 *   gFieldG3dobjFileName     0x021DE4A8  data  ov021  a1
 *   func_020307B0  0x020307B0  arm
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 *   func_02047828  0x02047828  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   G3D_SYSTEM_CreateResourceArcHandle   0x02046E24  arm
 *   G3D_SYSTEM_CheckResourceType   0x02046F50  arm
 *   G3D_SYSTEM_GetResourceFile   0x02046F48  arm
 *   NNS_G3dGetTex   0x0206E964  arm
 *   PALANM_ConvertGrayTable   0x02022040  thumb
 *   MIi_CpuClear32  0x02082A7C  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   MI_CpuFill  0x02082C60  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_GetObjectRender  0x02047788  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   func_02030EAC  0x02030EAC  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetTcblSys  0x02188D30  thumb  ov021
 *   FIELD_CAMERA_GetDistance  0x0218ED54  thumb  ov021
 *   func_02030DA8  0x02030DA8  arm
 *   gFieldmapTcbCameraZoomFileName     0x021DE4B8  data  ov021  a4
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb  ov021
 *   _ffix          0x0209C494  arm
 *   _dsqrt         0x0209C5E0  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef s32 fx32;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx32 m[3][3]; } MtxFx33;

/* Sweet Scent field move (021C6068..021C6368)                          */

#define SWEET_SCENT_NO_POKEMON 6   /* party slots 0..5 are real; 6 and above mean no Pokemon */

/* Event work of the move (0x14 bytes). */
typedef struct SweetScentWork {
    u8 partyIdx;                           /* party slot of the user, 0xFF from the item */
    u8 pad01[3];
    void *gameSys;
    void *gameData;
    void *fieldMap;
    void *fieldPlayer;
} SweetScentWork;

/* Work of the screen fade task (8 bytes). */
typedef struct SweetScentFade {
    u8 bgLayer;
    u8 level;                              /* 0..8, fade strength */
    u8 interval;                           /* frames per level */
    u8 timer;
    void *vreq;                            /* VRAM request object of the field */
} SweetScentFade;

typedef struct BgPoint {
    u16 x;
    u16 y;
} BgPoint;

extern void *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(void *task);
extern void MI_CpuFill8(void *p, int v, int n);
extern void *FIELDMAP_GetFieldPlayer(void *fieldMap);
extern void *func_020120F4(void *gameSys);
extern void FIELD_PLAYER_StartFormChange(void *player, u32 a1);
extern int FIELD_PLAYER_StepFormChange(void *player);
extern void *FIELD_PLAYER_GetMmdl(void *player);
extern void FLDMMDL_SetAcmd(void *mmdl, u16 a1);
extern int FLDMMDL_EndAcmd(void *mmdl);
extern void *FIELDMAP_GetFld3dCi(void *fieldMap);
extern void *FLD3D_CI_StartPartyMemberSequence(void *gameSys, void *a, int partyIdx);
extern void GAME_EVENT_CallEvent(void *task, void *sub);
extern void *FIELDMAP_GetEncount(void *fieldMap);
extern void *FIELD_ENCOUNT_CheckWildEncount(void *a, int mode);
extern int SCRIPT_SYS_CallScriptEvent(void *task, u16 b, int c, int d, u16 e);
extern void *FIELDMAP_GetMmdlSys(void *fieldMap);
extern u32 *FLDMMDL_SysResumeMove(void *c);
extern void *FIELDMAP_GetWeather(void *fieldMap);
extern u16 WEATHER_GetWeatherId(void *weatherTask);
extern void *FIELDMAP_GetVReq(void *fieldMap);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void FLD_VREQ_SetMainBlendAlphaEv(void *a, int b, int c);
extern void FLD_VREQ_SetMainBlendAlpha(void *p, u32 a, u32 b, u32 c, u32 d);
extern void FLD_VREQ_SetBgVisible(void *p, int i, u8 v);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(int, int, int, int, int, int, int);
extern void func_020409B4(u32 index);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern const BgPoint gSweetScentFadeBgPos;

/* Field camera zoom task (021C6B18..021C6BB4)                          */

/* Task work (0x10 bytes). */
typedef struct CameraZoomWork {
    void *fieldMap;
    u16 frame;
    u16 frameMax;
    fx32 startZoom;
    fx32 endZoom;
} CameraZoomWork;

extern u16 FIELDMAP_GetHeapId(void *fieldMap);
extern void *FIELDMAP_GetCamera(void *fieldMap);
extern u32 FIELDMAP_GetTcblSys(void *fieldMap);
extern fx32 FIELD_CAMERA_GetDistance(void *camera);
extern void FIELD_CAMERA_SetDistance(void *camera, fx32 v);
extern void func_02030DA8(u32 priority, void *cb, void *arg, int z);
extern void func_02030EAC(void *task);
extern char gFieldmapTcbCameraZoomFileName[];   /* source file name used as allocation site */
extern double _dsqrt(double x);

void *SWEET_SCENT_CreateEventNoPokemon(void *fieldMap, void *gameSys);
void *SWEET_SCENT_CreateEvent(void *gameSys, void *fieldMap, u8 partyIdx);
int SWEET_SCENT_EventMain(void *task, int *state, SweetScentWork *w);
int SWEET_SCENT_CheckWeatherClear(SweetScentWork *w);
void SWEET_SCENT_StartFade(void *task, void *gameSys, void *fieldMap);
int SWEET_SCENT_FadeMain(void *task, int *state, SweetScentFade *fade);
void SWEET_SCENT_FadeSetup(SweetScentFade *fade);
void SWEET_SCENT_FadeCleanup(SweetScentFade *fade);
void FIELDMAP_TCB_CAMERA_ZOOM_Create(void *fieldMap, u16 frames, fx32 zoomDelta);
void FIELDMAP_TCB_CAMERA_ZOOM_Main(void *task, CameraZoomWork *w);
void FIELDMAP_TCB_CAMERA_ZOOM_Step(CameraZoomWork *w);

/* Opaque 3D system objects (layouts in arm9/g3d_system_types.h). */
typedef struct G3dResource G3dResource;
typedef struct G3dRender G3dRender;
typedef struct G3dAnime G3dAnime;
typedef struct G3dObject G3dObject;

/* Field 3D object control (field_g3dobj.c, 021C63AC..021C6AFC)        */

#define FIELD_G3DOBJ_ANIME_MAX 8

/* FieldG3dObjRes.state */
#define FIELD_G3DOBJ_RES_FREE    0   /* being rebuilt or released */
#define FIELD_G3DOBJ_RES_READY   1   /* textures are in VRAM */
#define FIELD_G3DOBJ_RES_PENDING 2   /* textures are sent to VRAM on the next update */

/* FieldG3dObj.kind */
#define FIELD_G3DOBJ_FREE    0
#define FIELD_G3DOBJ_ACTIVE  1   /* g3dObject and anime are created */
#define FIELD_G3DOBJ_PENDING 2   /* waits for the resource textures; created by the next update */

/* Files of one resource: a model, a texture file and up to eight animations (0x24 bytes). */
typedef struct FieldG3dObjResDesc {
    u32 modelArc;                          /* archive handle of the model file */
    u32 texArc;                            /* archive handle of the texture file, 0 = none */
    u32 anmArc;                            /* archive handle of the animation files */
    u16 modelFile;
    u16 texFile;
    u16 anmFile[FIELD_G3DOBJ_ANIME_MAX];
    u8  anmCount;
} FieldG3dObjResDesc;

/* One loaded model with its texture and animations (0x2C bytes). */
typedef struct FieldG3dObjRes {
    G3dResource *model;
    G3dResource *texture;
    G3dResource *anime[FIELD_G3DOBJ_ANIME_MAX];
    u8 animeCount;
    u8 state;                              /* FIELD_G3DOBJ_RES_* */
} FieldG3dObjRes;

/* One placed object (0x68 bytes). */
typedef struct FieldG3dObj {
    u32 kind : 2;                          /* FIELD_G3DOBJ_* */
    u32 culling : 1;                       /* draw with the view box test */
    u32 hidden : 1;
    u32 manualDraw : 1;                    /* skipped by the batch draw */
    u32 redrawFlag : 1;                    /* cleared by the batch draw */
    u32 reserved : 26;
    u16 resIdx;                            /* index in FieldG3dObjCtrl.resTbl */
    u16 modelIdx;                          /* model inside the resource */
    VecFx32 trans;
    VecFx32 scale;
    MtxFx33 rotate;
    G3dObject *object;
    G3dAnime *anime[FIELD_G3DOBJ_ANIME_MAX];
} FieldG3dObj;

/* The control: a table of resources and a table of objects (0x14 bytes). */
typedef struct FieldG3dObjCtrl {
    u16 heapId;
    u16 ready;                             /* 0 while a table is being changed */
    u16 resCount;
    u16 objCount;
    FieldG3dObjRes *resTbl;
    FieldG3dObj *objTbl;
    const u8 *palTable;                    /* palette conversion table, 0 = none */
} FieldG3dObjCtrl;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void MI_CpuFill(void *p, int v, int n);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern void func_0207ADC4(MtxFx33 *m);
/* Palette block of a texture resource (NNSG3dResTex, only what is read here). */
typedef struct ResTexPltt {
    u8 pad00[0x30];
    u16 sizePltt;                          /* palette size in units of 8 bytes */
    u8 pad32[0x06];
    u32 ofsPlttData;
} ResTexPltt;

extern void PALANM_ConvertGrayTable(u16 *pal, int n, const u8 *table);
extern ResTexPltt *NNS_G3dGetTex(void *file);
extern void G3D_SYSTEM_DrawObjectCulling(G3dObject *obj, VecFx32 *status);
extern void G3D_SYSTEM_DrawObject(G3dObject *obj, VecFx32 *status);
extern int G3D_SYSTEM_IncObjectAnimeFrame(G3dObject *obj, int idx, int amount);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(G3dObject *obj, int idx, int amount);
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(G3dObject *obj, u16 idx, s32 *frame);
extern u32 func_02047828(G3dObject *obj, u32 idx, s32 *frame);
extern int G3D_SYSTEM_TransVramTexture(G3dResource *res);
extern G3dResource *G3D_SYSTEM_CreateResourceArcHandle(u32 arc, u32 file);
extern u32 G3D_SYSTEM_CheckResourceType(G3dResource *res, u32 kind);
extern void *G3D_SYSTEM_GetResourceFile(G3dResource *res);
extern int G3D_SYSTEM_FreeVramTexture(G3dResource *res);
extern void func_02046EFC(G3dResource *res);
extern G3dRender *G3D_SYSTEM_CreateRender(G3dResource *model, u32 modelIdx, G3dResource *texture);
extern G3dAnime *G3D_SYSTEM_CreateAnime(G3dRender *render, G3dResource *anime, int unused);
extern G3dObject *G3D_SYSTEM_CreateObject(G3dRender *render, G3dAnime **anime, int count);
extern u32 G3D_SYSTEM_EnableObjectAnime(G3dObject *obj, u32 idx);
extern void G3D_SYSTEM_DeleteAnime(G3dAnime *anime);
extern G3dRender *G3D_SYSTEM_GetObjectRender(G3dObject *obj);
extern void G3D_SYSTEM_DeleteObject(G3dObject *obj);
extern void G3D_SYSTEM_DeleteRender(G3dRender *render);

extern char gFieldG3dobjFileName[];   /* source file name used as allocation site */

FieldG3dObjCtrl *FIELD_G3DOBJ_Create(u32 heapId, u32 resCount, u32 objCount);
void FIELD_G3DOBJ_Delete(FieldG3dObjCtrl *ctrl);
void FIELD_G3DOBJ_Update(FieldG3dObjCtrl *ctrl);
void FIELD_G3DOBJ_DrawAll(FieldG3dObjCtrl *ctrl);
void FIELD_G3DOBJ_SetPalTable(FieldG3dObjCtrl *ctrl, const u8 *palTable);
u16 FIELD_G3DOBJ_AddResource(FieldG3dObjCtrl *ctrl, FieldG3dObjResDesc *desc, int mode, const u8 *palTable);
int FIELD_G3DOBJ_AddResourceDefaultPal(FieldG3dObjCtrl *ctrl, FieldG3dObjResDesc *desc, int mode);
void FIELD_G3DOBJ_DeleteResource(FieldG3dObjCtrl *ctrl, int resIdx);
u16 FIELD_G3DOBJ_AddObject(FieldG3dObjCtrl *ctrl, u16 resIdx, u16 modelIdx, VecFx32 *pos);
void FIELD_G3DOBJ_DeleteObject(FieldG3dObjCtrl *ctrl, int objIdx);
VecFx32 *FIELD_G3DOBJ_GetObjectTrans(FieldG3dObjCtrl *ctrl, int objIdx);
void FIELD_G3DOBJ_SetObjectTrans(FieldG3dObjCtrl *ctrl, int objIdx, VecFx32 *pos);
void FIELD_G3DOBJ_SetObjectHidden(FieldG3dObjCtrl *ctrl, int objIdx, int hidden);
int FIELD_G3DOBJ_IncAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int speed);
int FIELD_G3DOBJ_LoopAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int speed);
void FIELD_G3DOBJ_SetAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int animeIdx, s32 frame);
int FIELD_G3DOBJ_GetAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int animeIdx);
void FIELD_G3DOBJ_SetObjectManualDraw(FieldG3dObjCtrl *ctrl, int objIdx, int manualDraw);
void FIELD_G3DOBJ_DrawObject(FieldG3dObjCtrl *ctrl, int objIdx);
void FIELD_G3DOBJ_SetObjectRedrawFlag(FieldG3dObjCtrl *ctrl, int objIdx, int redrawFlag);
int FIELD_G3DOBJ_GetObjectRedrawFlag(FieldG3dObjCtrl *ctrl, int objIdx);
void FIELD_G3DOBJ_TransferResourceTexture(FieldG3dObjRes *res);
void FIELD_G3DOBJ_LoadResource(FieldG3dObjRes *res, int heapId, FieldG3dObjResDesc *desc, int mode, const u8 *palTable);
void FIELD_G3DOBJ_FreeResource(FieldG3dObjRes *res);
void FIELD_G3DOBJ_CreateObject(FieldG3dObj *obj, FieldG3dObjRes *res, u16 resIdx, u16 modelIdx, u32 heapId, VecFx32 *pos, int initDefaults);
void FIELD_G3DOBJ_DestroyObject(FieldG3dObj *obj, FieldG3dObjRes *res);
void FIELD_G3DOBJ_InitResDesc(FieldG3dObjResDesc *desc);
void FIELD_G3DOBJ_SetResDescModel(FieldG3dObjResDesc *desc, u32 arc, u32 file);
void FIELD_G3DOBJ_SetResDescAnimeArc(FieldG3dObjResDesc *desc, u32 arc);
void FIELD_G3DOBJ_AddResDescAnimeFile(FieldG3dObjResDesc *desc, u16 file);

void *SWEET_SCENT_CreateEventNoPokemon(void *fieldMap, void *gameSys) { return SWEET_SCENT_CreateEvent(gameSys, fieldMap, 0xff); }

void *SWEET_SCENT_CreateEvent(void *gameSys, void *fieldMap, u8 partyIdx)
{
    void *task;
    SweetScentWork *w;

    task = func_020122C0(gameSys, 0, SWEET_SCENT_EventMain, sizeof(SweetScentWork));
    w = func_020124E8(task);
    MI_CpuFill8(w, 0, sizeof(SweetScentWork));
    w->partyIdx = partyIdx;
    w->gameSys = gameSys;
    w->fieldMap = fieldMap;
    w->fieldPlayer = FIELDMAP_GetFieldPlayer(fieldMap);
    w->gameData = func_020120F4(gameSys);
    return task;
}

int SWEET_SCENT_EventMain(void *task, int *state, SweetScentWork *w)
{
    void *sub;

    switch (*state) {
    case 0:
        if (w->partyIdx >= SWEET_SCENT_NO_POKEMON) {
            *state = 5;
            break;
        }
        FIELD_PLAYER_StartFormChange(w->fieldPlayer, 0x80);
        (*state)++;
    case 1:
        if (FIELD_PLAYER_StepFormChange(w->fieldPlayer) != 1)
            break;
        FLDMMDL_SetAcmd(FIELD_PLAYER_GetMmdl(w->fieldPlayer), 0xa2);
        (*state)++;
        break;
    case 2:
        if (FLDMMDL_EndAcmd(FIELD_PLAYER_GetMmdl(w->fieldPlayer)) != 1)
            break;
        sub = FLD3D_CI_StartPartyMemberSequence(w->gameSys, FIELDMAP_GetFld3dCi(w->fieldMap), w->partyIdx);
        if (sub != 0)
            GAME_EVENT_CallEvent(task, sub);
        (*state)++;
        break;
    case 3:
        FIELD_PLAYER_StartFormChange(w->fieldPlayer, 8);
        (*state)++;
    case 4:
        if (FIELD_PLAYER_StepFormChange(w->fieldPlayer) != 1)
            break;
        *state = 5;
        break;
    case 5:
        if (SWEET_SCENT_CheckWeatherClear(w) == 0) {
            *state = 8;
            break;
        }
        SWEET_SCENT_StartFade(task, w->gameSys, w->fieldMap);
        *state = 6;
        break;
    case 6:
        sub = FIELD_ENCOUNT_CheckWildEncount(FIELDMAP_GetEncount(w->fieldMap), 2);
        if (sub == 0) {
            *state = 7;
            break;
        }
        GAME_EVENT_CallEvent(task, sub);
        *state = 9;
        break;
    case 7:
        SCRIPT_SYS_CallScriptEvent(task, 0x2793, 0, 0, 0x15);
        *state = 9;
        break;
    case 8:
        SCRIPT_SYS_CallScriptEvent(task, 0x2794, 0, 0, 0x15);
        *state = 9;
        break;
    case 9:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(w->fieldMap));
        return 1;
    }
    return 0;
}

int SWEET_SCENT_CheckWeatherClear(SweetScentWork *w)
{
    if (WEATHER_GetWeatherId(FIELDMAP_GetWeather(w->fieldMap)) == 0) {
        return 1;
    }
    return 0;
}

void SWEET_SCENT_StartFade(void *task, void *gameSys, void *fieldMap)
{
    void *fadeTask;
    SweetScentFade *fade;

    fadeTask = func_020122C0(gameSys, 0, SWEET_SCENT_FadeMain, sizeof(SweetScentFade));
    fade = func_020124E8(fadeTask);
    fade->bgLayer = 3;
    fade->level = 0;
    fade->interval = 2;
    fade->timer = 0;
    fade->vreq = FIELDMAP_GetVReq(fieldMap);
    GAME_EVENT_CallEvent(task, fadeTask);
}

int SWEET_SCENT_FadeMain(void *task, int *state, SweetScentFade *fade)
{
    switch (*state) {
    case 0:
        SWEET_SCENT_FadeSetup(fade);
        GFL_USE_PlaySeDefaultVolume(0x683);
        *state = *state + 1;
        break;
    case 1:
        if (fade->timer++ >= fade->interval) {
            fade->level++;
            FLD_VREQ_SetMainBlendAlphaEv(fade->vreq, fade->level, 0x10 - fade->level);
            fade->timer = 0;
        }
        if (fade->level >= 8) {
            *state = *state + 1;
        }
        break;
    case 2:
        if (fade->timer++ < 0x1e) {
            *state = *state + 1;
        }
        break;
    case 3:
        if (fade->timer++ >= fade->interval) {
            fade->level--;
            FLD_VREQ_SetMainBlendAlphaEv(fade->vreq, fade->level, 0x10 - fade->level);
            fade->timer = 0;
        }
        if (fade->level == 0) {
            *state = *state + 1;
        }
        break;
    case 4:
        FLD_VREQ_SetMainBlendAlpha(fade->vreq, 0, 0, 0, 0x1f);
        FLD_VREQ_SetBgVisible(fade->vreq, fade->bgLayer, 0);
        *state = *state + 1;
        break;
    default:
        SWEET_SCENT_FadeCleanup(fade);
        return 1;
    }
    return 0;
}

void SWEET_SCENT_FadeSetup(SweetScentFade *fade)
{
    BgPoint pos;

    pos = gSweetScentFadeBgPos;
    func_02040588(fade->bgLayer, 0);
    func_02040E78(fade->bgLayer, &pos, 8, 0x20);
    func_02040C14(fade->bgLayer, 1, 1, 0x100);
    func_02041300(fade->bgLayer, 0x100, 0, 0, 0x20, 0x20, 1);
    func_020409B4(fade->bgLayer);
    FLD_VREQ_SetMainBlendAlpha(fade->vreq, 8, 0x37, fade->level, 0x10 - fade->level);
    FLD_VREQ_SetBgVisible(fade->vreq, fade->bgLayer, 1);
}

void SWEET_SCENT_FadeCleanup(SweetScentFade *fade)
{
    BgPoint pos = {0, 0};

    func_02040E78(fade->bgLayer, &pos, 8, 0x20);
    func_02041300(fade->bgLayer, 0, 0, 0, 0x20, 0x20, 1);
    func_020409B4(fade->bgLayer);
    func_02040DA8(fade->bgLayer, 1, 0x100);
}

FieldG3dObjCtrl *FIELD_G3DOBJ_Create(u32 heapId, u32 resCount, u32 objCount)
{
    FieldG3dObjCtrl *ctrl;

    ctrl = func_02030734(heapId, sizeof(FieldG3dObjCtrl), 1, gFieldG3dobjFileName, 0x72);
    ctrl->resTbl = func_02030734(heapId, resCount * sizeof(FieldG3dObjRes), 1, gFieldG3dobjFileName, 0x75);
    ctrl->objTbl = func_02030734(heapId, objCount * sizeof(FieldG3dObj), 1, gFieldG3dobjFileName, 0x78);
    ctrl->heapId = heapId;
    ctrl->resCount = resCount;
    ctrl->objCount = objCount;
    ctrl->ready = 1;
    return ctrl;
}

void FIELD_G3DOBJ_Delete(FieldG3dObjCtrl *ctrl)
{
    u32 i;
    FieldG3dObj *obj;
    FieldG3dObjRes *res;

    i = 0;
    ctrl->ready = 0;
    obj = ctrl->objTbl;
    if (i < ctrl->objCount)
        for (; i < ctrl->objCount; i++) {
            if (obj->kind == FIELD_G3DOBJ_ACTIVE && obj->object != 0)
                FIELD_G3DOBJ_DestroyObject(obj, &ctrl->resTbl[obj->resIdx]);
            obj++;
        }
    func_020307B0(ctrl->objTbl);
    i = 0;
    res = ctrl->resTbl;
    if (i < ctrl->resCount)
        for (; i < ctrl->resCount; i++) {
            FIELD_G3DOBJ_FreeResource(res);
            res++;
        }
    func_020307B0(ctrl->resTbl);
    func_020307B0(ctrl);
}

void FIELD_G3DOBJ_Update(FieldG3dObjCtrl *ctrl)
{
    int i;
    int j;
    FieldG3dObj *obj;
    FieldG3dObjRes *res;

    if (ctrl->ready == 1) {
        obj = ctrl->objTbl;
        res = ctrl->resTbl;
        for (i = 0; i < ctrl->resCount; i++) {
            if (res->state == FIELD_G3DOBJ_RES_PENDING)
                FIELD_G3DOBJ_TransferResourceTexture(res);
            res++;
        }
        res = ctrl->resTbl;
        for (j = 0; j < ctrl->objCount; j++) {
            if (obj->kind == FIELD_G3DOBJ_PENDING)
                FIELD_G3DOBJ_CreateObject(obj, &res[obj->resIdx], obj->resIdx, obj->modelIdx, ctrl->heapId, 0, 0);
            obj++;
        }
    }
}

void FIELD_G3DOBJ_DrawAll(FieldG3dObjCtrl *ctrl)
{
    u32 i;
    FieldG3dObj *obj;

    obj = ctrl->objTbl;
    for (i = 0; i < ctrl->objCount; i++) {
        if (obj->kind == FIELD_G3DOBJ_ACTIVE) {
            if (obj->manualDraw == 0 && obj->hidden == 0) {
                if (obj->culling == 1)
                    G3D_SYSTEM_DrawObjectCulling(obj->object, &obj->trans);
                else
                    G3D_SYSTEM_DrawObject(obj->object, &obj->trans);
            }
            obj->redrawFlag = 0;
        }
        obj++;
    }
}

/*
 * Setter: stores the palette conversion table at +0x10.  Unlabelled in
 * the listing; called from FIELDMAP_SeqCreateSubsystems.
 */
void FIELD_G3DOBJ_SetPalTable(FieldG3dObjCtrl *ctrl, const u8 *palTable)
{
    ctrl->palTable = palTable;
}

u16 FIELD_G3DOBJ_AddResource(FieldG3dObjCtrl *ctrl, FieldG3dObjResDesc *desc, int mode, const u8 *palTable)
{
    u16 i;
    FieldG3dObjRes *res = ctrl->resTbl;
    for (i = 0; i < ctrl->resCount; i++, res++) {
        if (res->model == 0) {
            FIELD_G3DOBJ_LoadResource(res, ctrl->heapId, desc, mode, palTable);
            return i;
        }
    }
    return 0;
}

int FIELD_G3DOBJ_AddResourceDefaultPal(FieldG3dObjCtrl *ctrl, FieldG3dObjResDesc *desc, int mode)
{
    return FIELD_G3DOBJ_AddResource(ctrl, desc, mode, ctrl->palTable);
}

/*
 * Tail call on a strided element of the resource table.
 */
void FIELD_G3DOBJ_DeleteResource(FieldG3dObjCtrl *ctrl, int resIdx)
{
    FIELD_G3DOBJ_FreeResource(&ctrl->resTbl[resIdx]);
}

u16 FIELD_G3DOBJ_AddObject(FieldG3dObjCtrl *ctrl, u16 resIdx, u16 modelIdx, VecFx32 *pos)
{
    u16 i;
    FieldG3dObj *obj;
    FieldG3dObjRes *res;

    obj = ctrl->objTbl;
    for (i = 0; i < ctrl->objCount; i++) {
        if (obj->kind == FIELD_G3DOBJ_FREE && obj->object == 0) {
            res = &ctrl->resTbl[resIdx];
            if (res->state == FIELD_G3DOBJ_RES_PENDING) {
                obj->resIdx = resIdx;
                obj->modelIdx = modelIdx;
                obj->kind = FIELD_G3DOBJ_PENDING;
                obj->culling = 1;
                obj->scale.x = 0x1000;
                obj->scale.y = 0x1000;
                obj->scale.z = 0x1000;
                if (pos != 0)
                    obj->trans = *pos;
                func_0207ADC4(&obj->rotate);
            } else {
                FIELD_G3DOBJ_CreateObject(obj, res, resIdx, modelIdx, ctrl->heapId, pos, 1);
            }
            return i;
        }
        obj++;
    }
    return 0;
}

void FIELD_G3DOBJ_DeleteObject(FieldG3dObjCtrl *ctrl, int objIdx)
{
    FieldG3dObj *obj;
    obj = &ctrl->objTbl[objIdx];
    ctrl->ready = 0;
    if (obj->kind == FIELD_G3DOBJ_ACTIVE)
        FIELD_G3DOBJ_DestroyObject(obj, &ctrl->resTbl[obj->resIdx]);
    ctrl->ready = 1;
}

VecFx32 *FIELD_G3DOBJ_GetObjectTrans(FieldG3dObjCtrl *ctrl, int objIdx)
{
    return &ctrl->objTbl[objIdx].trans;
}

void FIELD_G3DOBJ_SetObjectTrans(FieldG3dObjCtrl *ctrl, int objIdx, VecFx32 *pos)
{
    ctrl->objTbl[objIdx].trans = *pos;
}

void FIELD_G3DOBJ_SetObjectHidden(FieldG3dObjCtrl *ctrl, int objIdx, int hidden)
{
    ctrl->objTbl[objIdx].hidden = hidden;
}

/*
 * Advances every animation of the object by speed, clamped at the ends.
 * Returns 1 when one of them moved or the object is not created yet.
 */
int FIELD_G3DOBJ_IncAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int speed)
{
    int result = 0;
    FieldG3dObj *obj = &ctrl->objTbl[objIdx];
    int count, i;

    if (obj->kind == FIELD_G3DOBJ_ACTIVE) {
        count = ctrl->resTbl[obj->resIdx].animeCount;
        for (i = result; i < count; i++) {
            if (G3D_SYSTEM_IncObjectAnimeFrame(obj->object, (u16)i, speed))
                result = 1;
        }
    } else if (obj->kind == FIELD_G3DOBJ_PENDING) {
        result = 1;
    }
    return result;
}

/* Same as FIELD_G3DOBJ_IncAnimeFrame, but the animations wrap at the ends. */
int FIELD_G3DOBJ_LoopAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int speed)
{
    int result = 0;
    FieldG3dObj *obj = &ctrl->objTbl[objIdx];
    int count, i;

    if (obj->kind == FIELD_G3DOBJ_ACTIVE) {
        count = ctrl->resTbl[obj->resIdx].animeCount;
        for (i = result; i < count; i++) {
            if (G3D_SYSTEM_LoopObjectAnimeFrame(obj->object, (u16)i, speed))
                result = 1;
        }
    } else if (obj->kind == FIELD_G3DOBJ_PENDING) {
        result = 1;
    }
    return result;
}

/*
 * push {r0-r3} entry (0x021C6744); the fourth parameter's address is taken.
 * animeIdx 8 sets every animation of the object.
 */
void FIELD_G3DOBJ_SetAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int animeIdx, s32 frame)
{
    FieldG3dObj *obj = &ctrl->objTbl[objIdx];
    int count, i;

    if (obj->kind == FIELD_G3DOBJ_ACTIVE) {
        count = ctrl->resTbl[obj->resIdx].animeCount;
        if (animeIdx == FIELD_G3DOBJ_ANIME_MAX) {
            i = 0;
            if (count > 0) {
                do {
                    G3D_SYSTEM_SetObjectAnimeFrame(obj->object, (u16)i, &frame);
                    i++;
                } while (i < count);
            }
        } else if (animeIdx < count) {
            G3D_SYSTEM_SetObjectAnimeFrame(obj->object, (u16)animeIdx, &frame);
        }
    }
}

int FIELD_G3DOBJ_GetAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int animeIdx)
{
    int frame = 0;
    FieldG3dObj *obj = &ctrl->objTbl[objIdx];
    if (obj->kind == FIELD_G3DOBJ_ACTIVE) {
        if ((int)func_02047828(obj->object, (u16)animeIdx, &frame) == 0)
            frame = 0;
    }
    return frame;
}

void FIELD_G3DOBJ_SetObjectManualDraw(FieldG3dObjCtrl *ctrl, int objIdx, int manualDraw)
{
    ctrl->objTbl[objIdx].manualDraw = manualDraw;
}

/* Draws one object at once unless it is hidden. */
void FIELD_G3DOBJ_DrawObject(FieldG3dObjCtrl *ctrl, int objIdx)
{
    FieldG3dObj *obj = &ctrl->objTbl[objIdx];
    if (obj->kind == FIELD_G3DOBJ_ACTIVE && obj->hidden == 0) {
        if (obj->culling == 1)
            G3D_SYSTEM_DrawObjectCulling(obj->object, &obj->trans);
        else
            G3D_SYSTEM_DrawObject(obj->object, &obj->trans);
    }
}

void FIELD_G3DOBJ_SetObjectRedrawFlag(FieldG3dObjCtrl *ctrl, int objIdx, int redrawFlag)
{
    ctrl->objTbl[objIdx].redrawFlag = redrawFlag;
}

int FIELD_G3DOBJ_GetObjectRedrawFlag(FieldG3dObjCtrl *ctrl, int objIdx)
{
    return ctrl->objTbl[objIdx].redrawFlag;
}

/* Sends the texture of the resource to VRAM. */
void FIELD_G3DOBJ_TransferResourceTexture(FieldG3dObjRes *res)
{
    res->state = FIELD_G3DOBJ_RES_FREE;
    if (res->texture != 0)
        G3D_SYSTEM_TransVramTexture(res->texture);
    else
        G3D_SYSTEM_TransVramTexture(res->model);
    res->state = FIELD_G3DOBJ_RES_READY;
}

void FIELD_G3DOBJ_LoadResource(FieldG3dObjRes *res, int heapId, FieldG3dObjResDesc *desc, int mode, const u8 *palTable)
{
    G3dResource *palRes;
    ResTexPltt *tex;
    int i;

    if (desc->modelArc != 0)
        res->model = G3D_SYSTEM_CreateResourceArcHandle(desc->modelArc, desc->modelFile);
    if (desc->texArc != 0)
        res->texture = G3D_SYSTEM_CreateResourceArcHandle(desc->texArc, desc->texFile);
    if (palTable != 0) {
        palRes = 0;
        if (res->model != 0)
            palRes = res->model;
        if (res->texture != 0)
            palRes = res->texture;
        if (G3D_SYSTEM_CheckResourceType(palRes, 2)) {
            tex = NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile(palRes));
            PALANM_ConvertGrayTable((u16 *)((u8 *)tex + tex->ofsPlttData), (u32)(tex->sizePltt << 3) / sizeof(u16), palTable);
        }
    }
    if (res->model != 0 || res->texture != 0) {
        if (mode == 1)
            FIELD_G3DOBJ_TransferResourceTexture(res);
        else
            res->state = FIELD_G3DOBJ_RES_PENDING;
    }
    if (desc->anmCount != 0) {
        res->animeCount = desc->anmCount;
        MIi_CpuClear32(0, res->anime, sizeof(res->anime));
        for (i = 0; i < res->animeCount; i++)
            res->anime[i] = G3D_SYSTEM_CreateResourceArcHandle(desc->anmArc, desc->anmFile[i]);
    }
}

void FIELD_G3DOBJ_FreeResource(FieldG3dObjRes *res)
{
    int i;
    u8 state = res->state;

    res->state = FIELD_G3DOBJ_RES_FREE;
    if (state == FIELD_G3DOBJ_RES_READY) {
        if (res->texture != 0)
            G3D_SYSTEM_FreeVramTexture(res->texture);
        else if (res->model != 0)
            G3D_SYSTEM_FreeVramTexture(res->model);
    }
    if (res->texture != 0)
        func_02046EFC(res->texture);
    if (res->model != 0)
        func_02046EFC(res->model);
    if (res->animeCount != 0) {
        for (i = 0; i < res->animeCount; i++)
            func_02046EFC(res->anime[i]);
    }
    MI_CpuFill(res, 0, sizeof(FieldG3dObjRes));
    res->state = FIELD_G3DOBJ_RES_READY;
}

/*
 * The unused 5th parameter (heapId) puts pos and initDefaults at sp+0x1c and
 * sp+0x20.  G3D_SYSTEM_CreateObject takes the animation count as a third argument
 * (the last animeCount load is reused in r2).
 */
void FIELD_G3DOBJ_CreateObject(FieldG3dObj *obj, FieldG3dObjRes *res, u16 resIdx, u16 modelIdx, u32 heapId, VecFx32 *pos, int initDefaults)
{
    int i;
    G3dRender *render;
    G3dResource *texRes;

    texRes = 0;
    obj->resIdx = resIdx;
    obj->modelIdx = modelIdx;
    if (res->state == FIELD_G3DOBJ_RES_READY) {
        texRes = res->model;
        if (res->texture != 0)
            texRes = res->texture;
    }
    render = G3D_SYSTEM_CreateRender(res->model, modelIdx, texRes);
    if (res->animeCount != 0) {
        MIi_CpuClear32(0, obj->anime, sizeof(obj->anime));
        for (i = 0; i < res->animeCount; i++)
            obj->anime[i] = G3D_SYSTEM_CreateAnime(render, res->anime[i], 0);
    }
    obj->object = G3D_SYSTEM_CreateObject(render, obj->anime, res->animeCount);
    if (res->animeCount != 0) {
        for (i = 0; i < res->animeCount; i++)
            G3D_SYSTEM_EnableObjectAnime(obj->object, (u16)i);
    }
    if (pos != 0)
        obj->trans = *pos;
    if (initDefaults != 0) {
        obj->culling = 1;
        obj->scale.x = 0x1000;
        obj->scale.y = 0x1000;
        obj->scale.z = 0x1000;
        func_0207ADC4(&obj->rotate);
    }
    obj->kind = FIELD_G3DOBJ_ACTIVE;
}

void FIELD_G3DOBJ_DestroyObject(FieldG3dObj *obj, FieldG3dObjRes *res)
{
    G3dRender *render;
    int i;

    if (obj->anime) {
        for (i = 0; i < res->animeCount; i++)
            G3D_SYSTEM_DeleteAnime(obj->anime[i]);
    }
    if (obj->object != 0) {
        render = G3D_SYSTEM_GetObjectRender(obj->object);
        G3D_SYSTEM_DeleteObject(obj->object);
        G3D_SYSTEM_DeleteRender(render);
    }
    MI_CpuFill(obj, 0, sizeof(FieldG3dObj));
}

/*
 * Tail call with a zero first argument and a constant size.
 */
void FIELD_G3DOBJ_InitResDesc(FieldG3dObjResDesc *desc)
{
    MIi_CpuClear32(0, desc, sizeof(FieldG3dObjResDesc));
}

void FIELD_G3DOBJ_SetResDescModel(FieldG3dObjResDesc *desc, u32 arc, u32 file)
{
    desc->modelArc = arc;
    desc->modelFile = file;
}

void FIELD_G3DOBJ_SetResDescAnimeArc(FieldG3dObjResDesc *desc, u32 arc)
{
    desc->anmArc = arc;
}

void FIELD_G3DOBJ_AddResDescAnimeFile(FieldG3dObjResDesc *desc, u16 file)
{
    desc->anmFile[desc->anmCount] = file;
    desc->anmCount++;
}

void FIELDMAP_TCB_CAMERA_ZOOM_Create(void *fieldMap, u16 frames, fx32 zoomDelta)
{
    u32 heapId = FIELDMAP_GetHeapId(fieldMap);
    void *camera = FIELDMAP_GetCamera(fieldMap);
    u32 priority = FIELDMAP_GetTcblSys(fieldMap);
    CameraZoomWork *w;

    w = func_02030734((u16)((heapId & 0x7FFF) | 0x8000), sizeof(CameraZoomWork), 0, gFieldmapTcbCameraZoomFileName, 0x5F);
    w->frame = 0;
    w->frameMax = frames;
    w->startZoom = FIELD_CAMERA_GetDistance(camera);
    w->endZoom = zoomDelta + FIELD_CAMERA_GetDistance(camera);
    w->fieldMap = fieldMap;
    func_02030DA8(priority, FIELDMAP_TCB_CAMERA_ZOOM_Main, w, 0);
}

void FIELDMAP_TCB_CAMERA_ZOOM_Main(void *task, CameraZoomWork *w)
{
    FIELDMAP_TCB_CAMERA_ZOOM_Step(w);
    w->frame++;
    if (w->frameMax < w->frame) {
        func_020307B0(w);
        func_02030EAC(task);
    }
}

/*
 * Lever: `t = 1.0f; t *= a / b;` keeps the fmul by 1.0f; a plain `1.0f * x`
 * or `x * 1.0f` folds away. The FX32 round (x > 0 ? x*4096+0.5 : x*4096-0.5)
 * must go through one float temp so the _ffix and the call are shared.
 */
void FIELDMAP_TCB_CAMERA_ZOOM_Step(CameraZoomWork *w)
{
    void *camera = FIELDMAP_GetCamera(w->fieldMap);
    u32 frameMax = w->frameMax;
    float ratio, startZoom, endZoom, zoom;

    if (w->frame <= frameMax) {
        ratio = 1.0f;
        ratio *= (float)(u32)w->frame / (float)frameMax;
        ratio = (float)_dsqrt((double)ratio);
        startZoom = (float)w->startZoom / 4096.0f;
        endZoom = (float)w->endZoom / 4096.0f;
        zoom = (1.0f - ratio) * startZoom + ratio * endZoom;
        if (zoom > 0.0f)
            zoom = 4096.0f * zoom + 0.5f;
        else
            zoom = 4096.0f * zoom - 0.5f;
        FIELD_CAMERA_SetDistance(camera, (int)zoom);
    }
}
