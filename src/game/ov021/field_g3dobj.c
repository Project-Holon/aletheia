/*
 * file:     field_g3dobj.c
 * unit:     yes
 * function: func_021C6068, func_021C6078, func_021C60B8, func_021C61D4, func_021C61EC, func_021C622C, func_021C62F0, func_021C6368, func_021C63AC, func_021C6400, func_021C6470, func_021C64E0, func_021C6534, func_021C6538, func_021C6574, func_021C6580, func_021C6590, func_021C6628, func_021C6658, func_021C6664, func_021C6678, func_021C6694, func_021C66EC, func_021C6744, func_021C67A8, func_021C67D8, func_021C67F4, func_021C6828, func_021C6844, func_021C6854, func_021C6874, func_021C6940, func_021C69B4, func_021C6A90, func_021C6AE0, func_021C6AF0, func_021C6AF8, func_021C6AFC, func_021C6B18, func_021C6B8C, func_021C6BB4
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_02189A00  0x02189A00  thumb  ov021
 *   func_021C1D68  0x021C1D68  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021A9F40  0x021A9F40  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02188C6C  0x02188C6C  thumb  ov021
 *   func_021A1BF4  0x021A1BF4  thumb  ov021
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021D3288  0x021D3288  thumb  ov021
 *   func_021D325C  0x021D325C  thumb  ov021
 *   func_021D3244  0x021D3244  thumb  ov021
 *   d_021DAAB4     0x021DAAB4  data  a2
 *   func_02040588  0x02040588  arm
 *   func_02040E78  0x02040E78  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_02030734  0x02030734  arm
 *   d_021DE4A8     0x021DE4A8  data  ov021  a1
 *   func_020307B0  0x020307B0  arm
 *   func_02047AC8  0x02047AC8  arm
 *   func_02047A60  0x02047A60  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_020478B8  0x020478B8  arm
 *   func_02047910  0x02047910  arm
 *   func_0204784C  0x0204784C  arm
 *   func_02047828  0x02047828  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02046E24   0x02046E24  arm
 *   func_02046F50   0x02046F50  arm
 *   func_02046F48   0x02046F48  arm
 *   func_0206E964   0x0206E964  arm
 *   func_02022040   0x02022040  thumb
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_02082C60  0x02082C60  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047788  0x02047788  arm
 *   func_02047738  0x02047738  arm
 *   func_02047504  0x02047504  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_0218ED54  0x0218ED54  thumb  ov021
 *   func_02030DA8  0x02030DA8  arm
 *   d_021DE4B8     0x021DE4B8  data  ov021  a4
 *   func_0218ED58  0x0218ED58  thumb  ov021
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
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02188CB4(void *fieldMap);
extern void *func_020120F4(void *gameSys);
extern void func_021A2F48(void *player, u32 a1);
extern int func_021A2F54(void *player);
extern void *func_021A3074(void *player);
extern void func_0216D410(void *mmdl, u16 a1);
extern int func_0216D480(void *mmdl);
extern void *func_02189A00(void *fieldMap);
extern void *func_021C1D68(void *gameSys, void *a, int partyIdx);
extern void func_02012374(void *task, void *sub);
extern void *func_02188CE8(void *fieldMap);
extern void *func_021A9F40(void *a, int mode);
extern int func_02158780(void *task, u16 b, int c, int d, u16 e);
extern void *func_02188C7C(void *fieldMap);
extern u32 *func_0216D9E4(void *c);
extern void *func_02188C6C(void *fieldMap);
extern u16 func_021A1BF4(void *weatherTask);
extern void *func_02188E30(void *fieldMap);
extern void func_020061E4(u32 a);
extern void func_021D3288(void *a, int b, int c);
extern void func_021D325C(void *p, u32 a, u32 b, u32 c, u32 d);
extern void func_021D3244(void *p, int i, u8 v);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(int, int, int, int, int, int, int);
extern void func_020409B4(u32 index);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern const BgPoint d_021DAAB4;

/* Field camera zoom task (021C6B18..021C6BB4)                          */

/* Task work (0x10 bytes). */
typedef struct CameraZoomWork {
    void *fieldMap;
    u16 frame;
    u16 frameMax;
    fx32 startZoom;
    fx32 endZoom;
} CameraZoomWork;

extern u16 func_02188C84(void *fieldMap);
extern void *func_02188C58(void *fieldMap);
extern u32 func_02188D30(void *fieldMap);
extern fx32 func_0218ED54(void *camera);
extern void func_0218ED58(void *camera, fx32 v);
extern void func_02030DA8(u32 priority, void *cb, void *arg, int z);
extern void func_02030EAC(void *task);
extern char d_021DE4B8[];   /* source file name used as allocation site */
extern double _dsqrt(double x);

void *func_021C6068(void *fieldMap, void *gameSys);
void *func_021C6078(void *gameSys, void *fieldMap, u8 partyIdx);
int func_021C60B8(void *task, int *state, SweetScentWork *w);
int func_021C61D4(SweetScentWork *w);
void func_021C61EC(void *task, void *gameSys, void *fieldMap);
int func_021C622C(void *task, int *state, SweetScentFade *fade);
void func_021C62F0(SweetScentFade *fade);
void func_021C6368(SweetScentFade *fade);
void func_021C6B18(void *fieldMap, u16 frames, fx32 zoomDelta);
void func_021C6B8C(void *task, CameraZoomWork *w);
void func_021C6BB4(CameraZoomWork *w);

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
extern void func_02082C60(void *p, int v, int n);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern void func_0207ADC4(MtxFx33 *m);
/* Palette block of a texture resource (NNSG3dResTex, only what is read here). */
typedef struct ResTexPltt {
    u8 pad00[0x30];
    u16 sizePltt;                          /* palette size in units of 8 bytes */
    u8 pad32[0x06];
    u32 ofsPlttData;
} ResTexPltt;

extern void func_02022040(u16 *pal, int n, const u8 *table);
extern ResTexPltt *func_0206E964(void *file);
extern void func_02047AC8(G3dObject *obj, VecFx32 *status);
extern void func_02047A60(G3dObject *obj, VecFx32 *status);
extern int func_020478B8(G3dObject *obj, int idx, int amount);
extern int func_02047910(G3dObject *obj, int idx, int amount);
extern u32 func_0204784C(G3dObject *obj, u16 idx, s32 *frame);
extern u32 func_02047828(G3dObject *obj, u32 idx, s32 *frame);
extern int func_02046FF8(G3dResource *res);
extern G3dResource *func_02046E24(u32 arc, u32 file);
extern u32 func_02046F50(G3dResource *res, u32 kind);
extern void *func_02046F48(G3dResource *res);
extern int func_020470D0(G3dResource *res);
extern void func_02046EFC(G3dResource *res);
extern G3dRender *func_02047400(G3dResource *model, u32 modelIdx, G3dResource *texture);
extern G3dAnime *func_02047564(G3dRender *render, G3dResource *anime, int unused);
extern G3dObject *func_0204767C(G3dRender *render, G3dAnime **anime, int count);
extern u32 func_020477A4(G3dObject *obj, u32 idx);
extern void func_0204762C(G3dAnime *anime);
extern G3dRender *func_02047788(G3dObject *obj);
extern void func_02047738(G3dObject *obj);
extern void func_02047504(G3dRender *render);

extern char d_021DE4A8[];   /* source file name used as allocation site */

FieldG3dObjCtrl *func_021C63AC(u32 heapId, u32 resCount, u32 objCount);
void func_021C6400(FieldG3dObjCtrl *ctrl);
void func_021C6470(FieldG3dObjCtrl *ctrl);
void func_021C64E0(FieldG3dObjCtrl *ctrl);
void func_021C6534(FieldG3dObjCtrl *ctrl, const u8 *palTable);
u16 func_021C6538(FieldG3dObjCtrl *ctrl, FieldG3dObjResDesc *desc, int mode, const u8 *palTable);
int func_021C6574(FieldG3dObjCtrl *ctrl, FieldG3dObjResDesc *desc, int mode);
void func_021C6580(FieldG3dObjCtrl *ctrl, int resIdx);
u16 func_021C6590(FieldG3dObjCtrl *ctrl, u16 resIdx, u16 modelIdx, VecFx32 *pos);
void func_021C6628(FieldG3dObjCtrl *ctrl, int objIdx);
VecFx32 *func_021C6658(FieldG3dObjCtrl *ctrl, int objIdx);
void func_021C6664(FieldG3dObjCtrl *ctrl, int objIdx, VecFx32 *pos);
void func_021C6678(FieldG3dObjCtrl *ctrl, int objIdx, int hidden);
int func_021C6694(FieldG3dObjCtrl *ctrl, int objIdx, int speed);
int func_021C66EC(FieldG3dObjCtrl *ctrl, int objIdx, int speed);
void func_021C6744(FieldG3dObjCtrl *ctrl, int objIdx, int animeIdx, s32 frame);
int func_021C67A8(FieldG3dObjCtrl *ctrl, int objIdx, int animeIdx);
void func_021C67D8(FieldG3dObjCtrl *ctrl, int objIdx, int manualDraw);
void func_021C67F4(FieldG3dObjCtrl *ctrl, int objIdx);
void func_021C6828(FieldG3dObjCtrl *ctrl, int objIdx, int redrawFlag);
int func_021C6844(FieldG3dObjCtrl *ctrl, int objIdx);
void func_021C6854(FieldG3dObjRes *res);
void func_021C6874(FieldG3dObjRes *res, int heapId, FieldG3dObjResDesc *desc, int mode, const u8 *palTable);
void func_021C6940(FieldG3dObjRes *res);
void func_021C69B4(FieldG3dObj *obj, FieldG3dObjRes *res, u16 resIdx, u16 modelIdx, u32 heapId, VecFx32 *pos, int initDefaults);
void func_021C6A90(FieldG3dObj *obj, FieldG3dObjRes *res);
void func_021C6AE0(FieldG3dObjResDesc *desc);
void func_021C6AF0(FieldG3dObjResDesc *desc, u32 arc, u32 file);
void func_021C6AF8(FieldG3dObjResDesc *desc, u32 arc);
void func_021C6AFC(FieldG3dObjResDesc *desc, u16 file);

void *func_021C6068(void *fieldMap, void *gameSys) { return func_021C6078(gameSys, fieldMap, 0xff); }

void *func_021C6078(void *gameSys, void *fieldMap, u8 partyIdx)
{
    void *task;
    SweetScentWork *w;

    task = func_020122C0(gameSys, 0, func_021C60B8, sizeof(SweetScentWork));
    w = func_020124E8(task);
    func_02082BCC(w, 0, sizeof(SweetScentWork));
    w->partyIdx = partyIdx;
    w->gameSys = gameSys;
    w->fieldMap = fieldMap;
    w->fieldPlayer = func_02188CB4(fieldMap);
    w->gameData = func_020120F4(gameSys);
    return task;
}

int func_021C60B8(void *task, int *state, SweetScentWork *w)
{
    void *sub;

    switch (*state) {
    case 0:
        if (w->partyIdx >= SWEET_SCENT_NO_POKEMON) {
            *state = 5;
            break;
        }
        func_021A2F48(w->fieldPlayer, 0x80);
        (*state)++;
    case 1:
        if (func_021A2F54(w->fieldPlayer) != 1)
            break;
        func_0216D410(func_021A3074(w->fieldPlayer), 0xa2);
        (*state)++;
        break;
    case 2:
        if (func_0216D480(func_021A3074(w->fieldPlayer)) != 1)
            break;
        sub = func_021C1D68(w->gameSys, func_02189A00(w->fieldMap), w->partyIdx);
        if (sub != 0)
            func_02012374(task, sub);
        (*state)++;
        break;
    case 3:
        func_021A2F48(w->fieldPlayer, 8);
        (*state)++;
    case 4:
        if (func_021A2F54(w->fieldPlayer) != 1)
            break;
        *state = 5;
        break;
    case 5:
        if (func_021C61D4(w) == 0) {
            *state = 8;
            break;
        }
        func_021C61EC(task, w->gameSys, w->fieldMap);
        *state = 6;
        break;
    case 6:
        sub = func_021A9F40(func_02188CE8(w->fieldMap), 2);
        if (sub == 0) {
            *state = 7;
            break;
        }
        func_02012374(task, sub);
        *state = 9;
        break;
    case 7:
        func_02158780(task, 0x2793, 0, 0, 0x15);
        *state = 9;
        break;
    case 8:
        func_02158780(task, 0x2794, 0, 0, 0x15);
        *state = 9;
        break;
    case 9:
        func_0216D9E4(func_02188C7C(w->fieldMap));
        return 1;
    }
    return 0;
}

int func_021C61D4(SweetScentWork *w)
{
    if (func_021A1BF4(func_02188C6C(w->fieldMap)) == 0) {
        return 1;
    }
    return 0;
}

void func_021C61EC(void *task, void *gameSys, void *fieldMap)
{
    void *fadeTask;
    SweetScentFade *fade;

    fadeTask = func_020122C0(gameSys, 0, func_021C622C, sizeof(SweetScentFade));
    fade = func_020124E8(fadeTask);
    fade->bgLayer = 3;
    fade->level = 0;
    fade->interval = 2;
    fade->timer = 0;
    fade->vreq = func_02188E30(fieldMap);
    func_02012374(task, fadeTask);
}

int func_021C622C(void *task, int *state, SweetScentFade *fade)
{
    switch (*state) {
    case 0:
        func_021C62F0(fade);
        func_020061E4(0x683);
        *state = *state + 1;
        break;
    case 1:
        if (fade->timer++ >= fade->interval) {
            fade->level++;
            func_021D3288(fade->vreq, fade->level, 0x10 - fade->level);
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
            func_021D3288(fade->vreq, fade->level, 0x10 - fade->level);
            fade->timer = 0;
        }
        if (fade->level == 0) {
            *state = *state + 1;
        }
        break;
    case 4:
        func_021D325C(fade->vreq, 0, 0, 0, 0x1f);
        func_021D3244(fade->vreq, fade->bgLayer, 0);
        *state = *state + 1;
        break;
    default:
        func_021C6368(fade);
        return 1;
    }
    return 0;
}

void func_021C62F0(SweetScentFade *fade)
{
    BgPoint pos;

    pos = d_021DAAB4;
    func_02040588(fade->bgLayer, 0);
    func_02040E78(fade->bgLayer, &pos, 8, 0x20);
    func_02040C14(fade->bgLayer, 1, 1, 0x100);
    func_02041300(fade->bgLayer, 0x100, 0, 0, 0x20, 0x20, 1);
    func_020409B4(fade->bgLayer);
    func_021D325C(fade->vreq, 8, 0x37, fade->level, 0x10 - fade->level);
    func_021D3244(fade->vreq, fade->bgLayer, 1);
}

void func_021C6368(SweetScentFade *fade)
{
    BgPoint pos = {0, 0};

    func_02040E78(fade->bgLayer, &pos, 8, 0x20);
    func_02041300(fade->bgLayer, 0, 0, 0, 0x20, 0x20, 1);
    func_020409B4(fade->bgLayer);
    func_02040DA8(fade->bgLayer, 1, 0x100);
}

FieldG3dObjCtrl *func_021C63AC(u32 heapId, u32 resCount, u32 objCount)
{
    FieldG3dObjCtrl *ctrl;

    ctrl = func_02030734(heapId, sizeof(FieldG3dObjCtrl), 1, d_021DE4A8, 0x72);
    ctrl->resTbl = func_02030734(heapId, resCount * sizeof(FieldG3dObjRes), 1, d_021DE4A8, 0x75);
    ctrl->objTbl = func_02030734(heapId, objCount * sizeof(FieldG3dObj), 1, d_021DE4A8, 0x78);
    ctrl->heapId = heapId;
    ctrl->resCount = resCount;
    ctrl->objCount = objCount;
    ctrl->ready = 1;
    return ctrl;
}

void func_021C6400(FieldG3dObjCtrl *ctrl)
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
                func_021C6A90(obj, &ctrl->resTbl[obj->resIdx]);
            obj++;
        }
    func_020307B0(ctrl->objTbl);
    i = 0;
    res = ctrl->resTbl;
    if (i < ctrl->resCount)
        for (; i < ctrl->resCount; i++) {
            func_021C6940(res);
            res++;
        }
    func_020307B0(ctrl->resTbl);
    func_020307B0(ctrl);
}

void func_021C6470(FieldG3dObjCtrl *ctrl)
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
                func_021C6854(res);
            res++;
        }
        res = ctrl->resTbl;
        for (j = 0; j < ctrl->objCount; j++) {
            if (obj->kind == FIELD_G3DOBJ_PENDING)
                func_021C69B4(obj, &res[obj->resIdx], obj->resIdx, obj->modelIdx, ctrl->heapId, 0, 0);
            obj++;
        }
    }
}

void func_021C64E0(FieldG3dObjCtrl *ctrl)
{
    u32 i;
    FieldG3dObj *obj;

    obj = ctrl->objTbl;
    for (i = 0; i < ctrl->objCount; i++) {
        if (obj->kind == FIELD_G3DOBJ_ACTIVE) {
            if (obj->manualDraw == 0 && obj->hidden == 0) {
                if (obj->culling == 1)
                    func_02047AC8(obj->object, &obj->trans);
                else
                    func_02047A60(obj->object, &obj->trans);
            }
            obj->redrawFlag = 0;
        }
        obj++;
    }
}

/*
 * Setter: stores the palette conversion table at +0x10.  Unlabelled in
 * the listing; called from func_021881D8.
 */
void func_021C6534(FieldG3dObjCtrl *ctrl, const u8 *palTable)
{
    ctrl->palTable = palTable;
}

u16 func_021C6538(FieldG3dObjCtrl *ctrl, FieldG3dObjResDesc *desc, int mode, const u8 *palTable)
{
    u16 i;
    FieldG3dObjRes *res = ctrl->resTbl;
    for (i = 0; i < ctrl->resCount; i++, res++) {
        if (res->model == 0) {
            func_021C6874(res, ctrl->heapId, desc, mode, palTable);
            return i;
        }
    }
    return 0;
}

int func_021C6574(FieldG3dObjCtrl *ctrl, FieldG3dObjResDesc *desc, int mode)
{
    return func_021C6538(ctrl, desc, mode, ctrl->palTable);
}

/*
 * Tail call on a strided element of the resource table.
 */
void func_021C6580(FieldG3dObjCtrl *ctrl, int resIdx)
{
    func_021C6940(&ctrl->resTbl[resIdx]);
}

u16 func_021C6590(FieldG3dObjCtrl *ctrl, u16 resIdx, u16 modelIdx, VecFx32 *pos)
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
                func_021C69B4(obj, res, resIdx, modelIdx, ctrl->heapId, pos, 1);
            }
            return i;
        }
        obj++;
    }
    return 0;
}

void func_021C6628(FieldG3dObjCtrl *ctrl, int objIdx)
{
    FieldG3dObj *obj;
    obj = &ctrl->objTbl[objIdx];
    ctrl->ready = 0;
    if (obj->kind == FIELD_G3DOBJ_ACTIVE)
        func_021C6A90(obj, &ctrl->resTbl[obj->resIdx]);
    ctrl->ready = 1;
}

VecFx32 *func_021C6658(FieldG3dObjCtrl *ctrl, int objIdx)
{
    return &ctrl->objTbl[objIdx].trans;
}

void func_021C6664(FieldG3dObjCtrl *ctrl, int objIdx, VecFx32 *pos)
{
    ctrl->objTbl[objIdx].trans = *pos;
}

void func_021C6678(FieldG3dObjCtrl *ctrl, int objIdx, int hidden)
{
    ctrl->objTbl[objIdx].hidden = hidden;
}

/*
 * Advances every animation of the object by speed, clamped at the ends.
 * Returns 1 when one of them moved or the object is not created yet.
 */
int func_021C6694(FieldG3dObjCtrl *ctrl, int objIdx, int speed)
{
    int result = 0;
    FieldG3dObj *obj = &ctrl->objTbl[objIdx];
    int count, i;

    if (obj->kind == FIELD_G3DOBJ_ACTIVE) {
        count = ctrl->resTbl[obj->resIdx].animeCount;
        for (i = result; i < count; i++) {
            if (func_020478B8(obj->object, (u16)i, speed))
                result = 1;
        }
    } else if (obj->kind == FIELD_G3DOBJ_PENDING) {
        result = 1;
    }
    return result;
}

/* Same as func_021C6694, but the animations wrap at the ends. */
int func_021C66EC(FieldG3dObjCtrl *ctrl, int objIdx, int speed)
{
    int result = 0;
    FieldG3dObj *obj = &ctrl->objTbl[objIdx];
    int count, i;

    if (obj->kind == FIELD_G3DOBJ_ACTIVE) {
        count = ctrl->resTbl[obj->resIdx].animeCount;
        for (i = result; i < count; i++) {
            if (func_02047910(obj->object, (u16)i, speed))
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
void func_021C6744(FieldG3dObjCtrl *ctrl, int objIdx, int animeIdx, s32 frame)
{
    FieldG3dObj *obj = &ctrl->objTbl[objIdx];
    int count, i;

    if (obj->kind == FIELD_G3DOBJ_ACTIVE) {
        count = ctrl->resTbl[obj->resIdx].animeCount;
        if (animeIdx == FIELD_G3DOBJ_ANIME_MAX) {
            i = 0;
            if (count > 0) {
                do {
                    func_0204784C(obj->object, (u16)i, &frame);
                    i++;
                } while (i < count);
            }
        } else if (animeIdx < count) {
            func_0204784C(obj->object, (u16)animeIdx, &frame);
        }
    }
}

int func_021C67A8(FieldG3dObjCtrl *ctrl, int objIdx, int animeIdx)
{
    int frame = 0;
    FieldG3dObj *obj = &ctrl->objTbl[objIdx];
    if (obj->kind == FIELD_G3DOBJ_ACTIVE) {
        if ((int)func_02047828(obj->object, (u16)animeIdx, &frame) == 0)
            frame = 0;
    }
    return frame;
}

void func_021C67D8(FieldG3dObjCtrl *ctrl, int objIdx, int manualDraw)
{
    ctrl->objTbl[objIdx].manualDraw = manualDraw;
}

/* Draws one object at once unless it is hidden. */
void func_021C67F4(FieldG3dObjCtrl *ctrl, int objIdx)
{
    FieldG3dObj *obj = &ctrl->objTbl[objIdx];
    if (obj->kind == FIELD_G3DOBJ_ACTIVE && obj->hidden == 0) {
        if (obj->culling == 1)
            func_02047AC8(obj->object, &obj->trans);
        else
            func_02047A60(obj->object, &obj->trans);
    }
}

void func_021C6828(FieldG3dObjCtrl *ctrl, int objIdx, int redrawFlag)
{
    ctrl->objTbl[objIdx].redrawFlag = redrawFlag;
}

int func_021C6844(FieldG3dObjCtrl *ctrl, int objIdx)
{
    return ctrl->objTbl[objIdx].redrawFlag;
}

/* Sends the texture of the resource to VRAM. */
void func_021C6854(FieldG3dObjRes *res)
{
    res->state = FIELD_G3DOBJ_RES_FREE;
    if (res->texture != 0)
        func_02046FF8(res->texture);
    else
        func_02046FF8(res->model);
    res->state = FIELD_G3DOBJ_RES_READY;
}

void func_021C6874(FieldG3dObjRes *res, int heapId, FieldG3dObjResDesc *desc, int mode, const u8 *palTable)
{
    G3dResource *palRes;
    ResTexPltt *tex;
    int i;

    if (desc->modelArc != 0)
        res->model = func_02046E24(desc->modelArc, desc->modelFile);
    if (desc->texArc != 0)
        res->texture = func_02046E24(desc->texArc, desc->texFile);
    if (palTable != 0) {
        palRes = 0;
        if (res->model != 0)
            palRes = res->model;
        if (res->texture != 0)
            palRes = res->texture;
        if (func_02046F50(palRes, 2)) {
            tex = func_0206E964(func_02046F48(palRes));
            func_02022040((u16 *)((u8 *)tex + tex->ofsPlttData), (u32)(tex->sizePltt << 3) / sizeof(u16), palTable);
        }
    }
    if (res->model != 0 || res->texture != 0) {
        if (mode == 1)
            func_021C6854(res);
        else
            res->state = FIELD_G3DOBJ_RES_PENDING;
    }
    if (desc->anmCount != 0) {
        res->animeCount = desc->anmCount;
        MIi_CpuClear32(0, res->anime, sizeof(res->anime));
        for (i = 0; i < res->animeCount; i++)
            res->anime[i] = func_02046E24(desc->anmArc, desc->anmFile[i]);
    }
}

void func_021C6940(FieldG3dObjRes *res)
{
    int i;
    u8 state = res->state;

    res->state = FIELD_G3DOBJ_RES_FREE;
    if (state == FIELD_G3DOBJ_RES_READY) {
        if (res->texture != 0)
            func_020470D0(res->texture);
        else if (res->model != 0)
            func_020470D0(res->model);
    }
    if (res->texture != 0)
        func_02046EFC(res->texture);
    if (res->model != 0)
        func_02046EFC(res->model);
    if (res->animeCount != 0) {
        for (i = 0; i < res->animeCount; i++)
            func_02046EFC(res->anime[i]);
    }
    func_02082C60(res, 0, sizeof(FieldG3dObjRes));
    res->state = FIELD_G3DOBJ_RES_READY;
}

/*
 * The unused 5th parameter (heapId) puts pos and initDefaults at sp+0x1c and
 * sp+0x20.  func_0204767C takes the animation count as a third argument
 * (the last animeCount load is reused in r2).
 */
void func_021C69B4(FieldG3dObj *obj, FieldG3dObjRes *res, u16 resIdx, u16 modelIdx, u32 heapId, VecFx32 *pos, int initDefaults)
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
    render = func_02047400(res->model, modelIdx, texRes);
    if (res->animeCount != 0) {
        MIi_CpuClear32(0, obj->anime, sizeof(obj->anime));
        for (i = 0; i < res->animeCount; i++)
            obj->anime[i] = func_02047564(render, res->anime[i], 0);
    }
    obj->object = func_0204767C(render, obj->anime, res->animeCount);
    if (res->animeCount != 0) {
        for (i = 0; i < res->animeCount; i++)
            func_020477A4(obj->object, (u16)i);
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

void func_021C6A90(FieldG3dObj *obj, FieldG3dObjRes *res)
{
    G3dRender *render;
    int i;

    if (obj->anime) {
        for (i = 0; i < res->animeCount; i++)
            func_0204762C(obj->anime[i]);
    }
    if (obj->object != 0) {
        render = func_02047788(obj->object);
        func_02047738(obj->object);
        func_02047504(render);
    }
    func_02082C60(obj, 0, sizeof(FieldG3dObj));
}

/*
 * Tail call with a zero first argument and a constant size.
 */
void func_021C6AE0(FieldG3dObjResDesc *desc)
{
    MIi_CpuClear32(0, desc, sizeof(FieldG3dObjResDesc));
}

void func_021C6AF0(FieldG3dObjResDesc *desc, u32 arc, u32 file)
{
    desc->modelArc = arc;
    desc->modelFile = file;
}

void func_021C6AF8(FieldG3dObjResDesc *desc, u32 arc)
{
    desc->anmArc = arc;
}

void func_021C6AFC(FieldG3dObjResDesc *desc, u16 file)
{
    desc->anmFile[desc->anmCount] = file;
    desc->anmCount++;
}

void func_021C6B18(void *fieldMap, u16 frames, fx32 zoomDelta)
{
    u32 heapId = func_02188C84(fieldMap);
    void *camera = func_02188C58(fieldMap);
    u32 priority = func_02188D30(fieldMap);
    CameraZoomWork *w;

    w = func_02030734((u16)((heapId & 0x7FFF) | 0x8000), sizeof(CameraZoomWork), 0, d_021DE4B8, 0x5F);
    w->frame = 0;
    w->frameMax = frames;
    w->startZoom = func_0218ED54(camera);
    w->endZoom = zoomDelta + func_0218ED54(camera);
    w->fieldMap = fieldMap;
    func_02030DA8(priority, func_021C6B8C, w, 0);
}

void func_021C6B8C(void *task, CameraZoomWork *w)
{
    func_021C6BB4(w);
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
void func_021C6BB4(CameraZoomWork *w)
{
    void *camera = func_02188C58(w->fieldMap);
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
        func_0218ED58(camera, (int)zoom);
    }
}
