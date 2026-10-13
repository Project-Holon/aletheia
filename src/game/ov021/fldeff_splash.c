/*
 * file:     fldeff_splash.c
 * unit:     yes
 * function: func_021C4978, func_021C49AC, func_021C49C0, func_021C4A00, func_021C4A10, func_021C4A3C, func_021C4AE8, func_021C4B04, func_021C4B24, func_021C4B28, func_021C4B50, func_021C4B64, func_021C4BC4, func_021C4BE0, func_021C4C0C, func_021C4C50, func_021C4C54, func_021C4CDC
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
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02050340  0x02050340  arm
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02050804  0x02050804  arm
 *   func_0205082C  0x0205082C  arm
 *   func_020507F0  0x020507F0  arm
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C90  0x02188C90  thumb  ov021
 *   d_021DE47C     0x021DE47C  data  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_021AC1F0  0x021AC1F0  thumb  ov021
 *   func_020500F0  0x020500F0  arm
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021DAA2C     0x021DAA2C  data  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   d_021DE478     0x021DE478  data  a4
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C67D8  0x021C67D8  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   d_021DAA18     0x021DAA18  data  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216DBE8  0x0216DBE8  thumb  ov010
 *   func_021C6658  0x021C6658  thumb  ov021
 *   func_021C6844  0x021C6844  thumb  ov021
 *   func_021C66EC  0x021C66EC  thumb  ov021
 *   func_021C6828  0x021C6828  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021C67F4  0x021C67F4  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   abs_id_C2      0x000000C2  data
 *   ov171_id       0x000000AB  data  a1
 */
#include "field_effect_types.h"
#include "../ov010/fldmmdl_types.h"

struct BbActDesc;
struct BbActSys;
struct BbActRec;
struct X;
struct Actor;
struct Res_021C48A0;
struct IcaAnime;
struct Rec12;
struct Mtx33;
struct Big;
struct BgTemplate;
struct Bank;
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
struct Sub02008C20Obj;
struct Self;
struct S0201235C;

typedef signed short   s16_021C48A0;

typedef signed char    s8;

typedef int            s32_021C4E6C;

typedef signed int     s32_021C4F7C;

typedef signed short   s16_021C59A8;

typedef short s16_021C577C;

typedef struct { fx32 m[3][3]; } MtxFx33;

typedef struct FldEffBbRes {
    u32 unused00;
    struct BbActSys *actSys;              /* 0x04 */
    u16 imageIdx;                         /* 0x08 */
} FldEffBbRes;

/* Entry template for BILLBOARD_ACT_CreateEntries (0x24 bytes). */
typedef struct BbActDesc {
    u16 imageIdx;
    u16 scaleX;
    u16 scaleY;
    u8 alpha;
    u8 pad07;
    u32 visible;
    u32 animEnable;
    VecFx32 pos;
    void (*onEnd)(void);
    void *userData;
} BbActDesc;

/* Image record for BILLBOARD_ACT_CreateSlots. */
typedef struct BbActRec {
    void *resource;
    u8 type;
    u8 imageId;
    u8 cellWidth;
    u8 cellHeight;
    u32 count;
} BbActRec;

/* Splash, billboard kind: record made by func_021C4978 (0xC bytes). */
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

/* Splash, model kind: record made by func_021C4B28 (8 bytes). */
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

extern void *func_021AC1AC(FieldEffectObj *obj);
extern void func_021AC1CC(FieldEffectObj *obj, VecFx32 *pos);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void func_021AC154(FieldEffectObj *obj);
extern void func_02050804(void *p, int idx, u32 v, u16 h);
extern void func_0205082C(void *p, int idx, u32 h);
extern void func_020507F0(void *p, int idx, u32 v);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern u32 func_020508EC(u8 *p, int i, u16 *out);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021ABE14(u8 *p);
extern u32 func_02188C90(u8 *p);
extern u32 func_020307B0(void *p);
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern void func_021AC1F0(struct X *x, void *b);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(FieldEffectSys *sys, void *funcs, u32 c, u32 d, void *param, u32 f);
extern void func_0216D88C(const Mmdl *mmdl, VecFx32 *out);
extern u32 func_021ABE18(unsigned char *p);
extern void func_021C6AE0(u32 a);
extern int func_021C6AF0(u32 a, u32 b, u32 c);
extern void func_021C6AF8(u32 *a, u32 b);
extern void func_021C6AFC(u32 *a, u32 b);
extern int func_021C6574(u32 a, u32 b, u32 c);
extern u16 func_021C6590(u32 a, u32 b, u32 c, u32 d);
extern void func_021C67D8(u32 a, u32 b, u32 c);
extern void func_021C6628(u32 o, u16 v);
extern void func_021C6580(u8 *p, int i);
extern int func_0216E1A4(Mmdl *mmdl, u32 *checkInfo);
extern int func_0216E1C4(Mmdl *mmdl, u32 *checkInfo);
extern int func_0216DBE8(Mmdl *mmdl);
extern int func_021C6658(u32 a, u32 b);
extern int func_021C6844(int a, int b);
extern int func_021C66EC(u32 *a, int idx, int v);
extern void func_021C6828(int a, int b, int c);
extern void func_021AC1B8(FieldEffectObj *obj, VecFx32 *out);
extern void func_021C67F4(u32 o, u16 id);
/* Retain the mode used to store f59 for the helper's second argument. */
SplashBoardRes *func_021C4978(FieldEffectSys *sys, u32 heapId);
void func_021C49AC(u32 unused, SplashBoardRes *res);
void func_021C49C0(SplashBoardRes *res);
void func_021C4A00(SplashBoardRes *res);
void func_021C4A10(FieldEffectSys *sys, Mmdl *mmdl);
void func_021C4A3C(FieldEffectObj *obj, SplashBoardWork *work);
void func_021C4AE8(FieldEffectObj *obj, SplashBoardWork *work);
void func_021C4B04(FieldEffectObj *obj, SplashBoardWork *work);
void func_021C4B24(void);
SplashModelRes *func_021C4B28(FieldEffectSys *sys, u32 heapId);
void func_021C4B50(u32 unused, SplashModelRes *res);
void func_021C4B64(SplashModelRes *res);
void func_021C4BC4(SplashModelRes *res);
void func_021C4BE0(FieldEffectSys *sys, Mmdl *mmdl);
void func_021C4C0C(FieldEffectObj *obj, SplashModelWork *work);
void func_021C4C50(void);
void func_021C4C54(FieldEffectObj *obj, SplashModelWork *work);
void func_021C4CDC(FieldEffectObj *obj, SplashModelWork *work);
extern char d_021DE47C[];
extern char d_021DAA2C[];
extern u8 d_021DE478[];
extern char d_021DAA18[];
extern unsigned char abs_id_C2[];
extern char ov171_id[];

/* Splash, billboard kind: allocates the record (0xC bytes) and loads its image. */
SplashBoardRes *func_021C4978(FieldEffectSys *sys, u32 heapId)
{
    SplashBoardRes *res = func_02030734(heapId, 0xC, 1, d_021DE47C, 0x7D);

    res->sys = sys;
    res->actSys = (struct BbActSys *)func_02188C90((u8 *)func_021ABE14((u8 *)sys));
    func_021C49C0(res);
    return res;
}

/* Deletes the record. */
void func_021C49AC(u32 unused, SplashBoardRes *res)
{
    func_021C4A00(res);
    func_020307B0(res);
}

/* Registers the splash image in the ground billboard system. */
void func_021C49C0(SplashBoardRes *res)
{
    BbActRec rec;
    u32 arcHandle = func_021ABE24((u8 *)res->sys);

    rec.type = 2;
    rec.imageId = 0x13;
    rec.cellWidth = 0x10;
    rec.cellHeight = 0x10;
    rec.count = 1;
    rec.resource = func_02046E24(arcHandle, 0x2d);
    func_021AC1F0((struct X *)res->sys, rec.resource);
    res->imageIdx = func_020500F0(res->actSys, &rec, 1);
}

/* Releases the splash image. */
void func_021C4A00(SplashBoardRes *res)
{
    func_02050278(res->actSys, res->imageIdx, 1);
}

/* Adds one splash board object for the model mmdl. */
void func_021C4A10(FieldEffectSys *sys, Mmdl *mmdl)
{
    SplashBoardParam param;

    param.res = (SplashBoardRes *)func_021ABEA0((u32)sys, 8);
    param.mmdl = mmdl;
    func_021ABFA8(sys, d_021DAA2C, 0, 0, &param, 0);
}

/* Init: starts the billboard entry above the model. */
void func_021C4A3C(FieldEffectObj *obj, SplashBoardWork *work)
{
    SplashBoardParam *param = (SplashBoardParam *)func_021AC1AC(obj);
    FldEffBbRes *bbRes;
    u32 actSys, entryId;
    VecFx32 pos;
    BbActDesc desc;

    work->param = *param;
    func_0216D88C(work->param.mmdl, &pos);
    bbRes = (FldEffBbRes *)work->param.res;
    actSys = (u32)bbRes->actSys;
    pos.y -= 0xE000;
    pos.z -= 0xA000;
    desc.imageIdx = bbRes->imageIdx;
    desc.scaleX = 0x1000;
    desc.scaleY = 0x1000;
    desc.alpha = 0x1f;
    desc.visible = 1;
    desc.animEnable = 1;
    desc.pos = pos;
    desc.onEnd = 0;
    desc.userData = work;
    work->entryId = func_02050340((struct BbActSys *)actSys, 0, &desc, 1, 3);
    if (work->entryId == 0xFFFF) {
        func_021AC154(obj);
        return;
    }
    func_02050804((void *)actSys, work->entryId, (u32)d_021DE478, 1);
    entryId = work->entryId;
    func_0205082C((void *)actSys, entryId, 0);
    func_020507F0((void *)actSys, entryId, 1);
}

/* Exit: deletes the billboard entry unless the creation failed. */
void func_021C4AE8(FieldEffectObj *obj, SplashBoardWork *work)
{
    u32 actSys = (u32)work->param.res->actSys;

    if (work->entryId != 0xFFFF)
        func_02050468((struct BbActSys *)actSys, work->entryId, 1);
}

/* Update: ends the effect when the entry has run its last command. */
void func_021C4B04(FieldEffectObj *obj, SplashBoardWork *work)
{
    u32 lastCommand;

    if (func_020508EC((u8 *)work->param.res->actSys, work->entryId, (u16 *)(&lastCommand)) != 0)
        func_021AC154(obj);
}

/* Draw: nothing to do. */
void func_021C4B24(void) {}

/* Splash, model kind: allocates the record (8 bytes) and loads its model. */
SplashModelRes *func_021C4B28(FieldEffectSys *sys, u32 heapId)
{
    SplashModelRes *res = func_02030734(heapId, 8, 1, d_021DE47C, 0x163);

    res->sys = sys;
    func_021C4B64(res);
    return res;
}

/* Deletes the record. */
void func_021C4B50(u32 unused, SplashModelRes *res)
{
    func_021C4BC4(res);
    func_020307B0(res);
}

/* Loads the splash model resource and creates its object (hidden from the batch draw). */
void func_021C4B64(SplashModelRes *res)
{
    u32 resDesc[9];
    u32 g3dObjCtrl = func_021ABE18((unsigned char *)res->sys);
    u32 arcHandle = func_021ABE24((u8 *)res->sys);

    func_021C6AE0((u32)resDesc);
    func_021C6AF0((u32)resDesc, arcHandle, 0x5f);
    func_021C6AF8(resDesc, arcHandle);
    func_021C6AFC(resDesc, 0x6a);
    res->resIdx = func_021C6574(g3dObjCtrl, (u32)resDesc, 0);
    res->objIdx = func_021C6590(g3dObjCtrl, res->resIdx, 0, 0);
    func_021C67D8(g3dObjCtrl, res->objIdx, 1);
}

/* Deletes the model object and its resource. */
void func_021C4BC4(SplashModelRes *res)
{
    u32 g3dObjCtrl = func_021ABE18((unsigned char *)res->sys);

    func_021C6628(g3dObjCtrl, res->objIdx);
    func_021C6580((u8 *)g3dObjCtrl, res->resIdx);
}

/* Adds one splash model object for the model mmdl. */
void func_021C4BE0(FieldEffectSys *sys, Mmdl *mmdl)
{
    SplashModelParam param;

    param.res = (SplashModelRes *)func_021ABEA0((u32)sys, 0x11);
    param.mmdl = mmdl;
    func_021ABFA8(sys, d_021DAA18, 0, 0, &param, 0);
}

/* Init: copies the parameter and puts the object under the model. */
void func_021C4C0C(FieldEffectObj *obj, SplashModelWork *work)
{
    VecFx32 pos;
    SplashModelParam *param = (SplashModelParam *)func_021AC1AC(obj);

    work->param = *param;
    func_0216E1A4(work->param.mmdl, work->checkInfo);
    func_0216D88C(work->param.mmdl, &pos);
    pos.z += 0x8000;
    func_021AC1CC(obj, &pos);
    work->objIdx = work->param.res->objIdx;
}

/* Exit: nothing to do. */
void func_021C4C50(void) {}

/* Update: follows the model while it stays in the water; ends the effect otherwise. */
void func_021C4C54(FieldEffectObj *obj, SplashModelWork *work)
{
    VecFx32 pos;
    int objIdx;
    int g3dObjCtrl;

    if (func_0216E1C4(work->param.mmdl, work->checkInfo) == 0) {
        func_021AC154(obj);
        return;
    }
    if (func_0216DBE8(work->param.mmdl) == 0) {
        func_021AC154(obj);
        return;
    }
    objIdx = work->objIdx;
    g3dObjCtrl = func_021ABE18((u8 *)work->param.res->sys);
    func_021C6658(g3dObjCtrl, objIdx);
    if (func_021C6844(g3dObjCtrl, objIdx) == 0) {
        func_021C66EC((u32 *)g3dObjCtrl, objIdx, 0x1000);
        func_021C6828(g3dObjCtrl, objIdx, 1);
    }
    func_0216D88C(work->param.mmdl, &pos);
    pos.z += 0x8000;
    func_021AC1CC(obj, &pos);
}

/* Draw: copies the effect object position into the model object. */
void func_021C4CDC(FieldEffectObj *obj, SplashModelWork *work)
{
    u16 objIdx = work->objIdx;
    u32 g3dObjCtrl = func_021ABE18((u8 *)work->param.res->sys);
    VecFx32 *dst = (VecFx32 *)func_021C6658(g3dObjCtrl, objIdx);
    VecFx32 pos;

    func_021AC1B8(obj, &pos);
    *dst = pos;
    func_021C67F4(g3dObjCtrl, objIdx);
}
