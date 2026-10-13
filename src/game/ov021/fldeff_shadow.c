/*
 * file:     fldeff_shadow.c
 * unit:     yes
 * function: func_021AC218, func_021AC260, func_021AC274, func_021AC2AC, func_021AC2C0, func_021AC2F0, func_021AC384, func_021AC3A4, func_021AC3F8
 * address:  0x021AC218
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_effect.c at 0x021AC218: __FILE__ fldeff_shadow.c on 0x021AC218 (init, first
 * function); 0x021AC1A0..0x021AC1F0 are field_effect.c accessors called from many fldeff files.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_02188C88  0x02188C88  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   d_021DE028     0x021DE028  data  a1
 *   d_021D908C     0x021D908C  data  a4
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_02050278  0x02050278  arm
 *   d_021D9098  0x021D9098  data
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D98C  0x0216D98C  thumb  ov010
 *   func_0216DAB4  0x0216DAB4  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D92C  0x0216D92C  thumb  ov010
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_0204F720  0x0204F720  arm
 *   func_0204F638  0x0204F638  arm
 *   func_02046E24  0x02046E24  arm
 *   func_020500F0  0x020500F0  arm
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021AC178  0x021AC178  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 */
#include "field_effect_types.h"
#include "../arm9/billboard_act_types.h"
#include "../ov010/fldmmdl_types.h"

/* Id of the shadow resource in the field effect system. */
#define FLDEFF_ID_SHADOW 0

/* Shadow elevation above the model position. */
#define FLDEFF_SHADOW_RAISE 0x1000

/* Model flag that hides the shadow (moveBit). */
#define FLDEFF_SHADOW_HIDE_MOVE_BIT 0x8000

/* Billboard entry settings of one shadow. */
#define FLDEFF_SHADOW_ENTRY_SIZE   0x1000
#define FLDEFF_SHADOW_ENTRY_LAYER  0x13
#define FLDEFF_SHADOW_POLY_ID      2

/*
 * Resource of the shadow effect (0x1C bytes, allocated by
 * func_021AC218). It owns one billboard slot that every shadow of the map
 * draws from.
 */
typedef struct FldeffShadow {
    FieldEffectSys *fieldEffect;          /* 0x00 */
    VecFx32 baseOffset;                   /* 0x04 copied from a data table, never read here */
    struct BbActSys *billboardAct;        /* 0x10 billboard system of the field map */
    struct BbBoard *board;                /* 0x14 */
    u32 slotId;                           /* 0x18 slot made by the creation call */
} FldeffShadow;

/* Start parameter of one shadow (8 bytes). */
typedef struct FldeffShadowParam {
    FldeffShadow *shadow;
    Mmdl *mmdl;                           /* model that casts the shadow */
} FldeffShadowParam;

/* Work of one shadow (0x18 bytes). */
typedef struct FldeffShadowWork {
    u32 hidden;                           /* 0x00 1 while the shadow is not drawn */
    FldeffShadow *shadow;                 /* 0x04 */
    Mmdl *mmdl;                           /* 0x08 */
    u16 mmdlCheck[4];                     /* 0x0C identity check of the model */
    u32 entryId;                          /* 0x14 billboard entry (0xFFFF: none) */
} FldeffShadowWork;

extern void *func_02030734(u32 heapId, u32 size, int align, const char *file, u16 line);
extern void func_0216D88C(const Mmdl *mmdl, VecFx32 *out);
extern const MmdlObjCodeParam *func_0216E3C4(const Mmdl *mmdl);
extern struct BbActSys *func_02188C88(struct FieldMap *fieldmap);
extern struct BbBoard *func_02050080(struct BbActSys *act);
extern void ENV_SetResourceSet(void *p);
extern void *func_02046E24(int arcHandle, u32 id);
extern u16 func_020500F0(struct BbActSys *act, const struct BbActRec *recs, u32 count);
extern void func_02050278(struct BbActSys *act, u32 first, u32 count);
extern int func_0216E1A4(const Mmdl *mmdl, u16 *out);
extern u16 func_02050340(struct BbActSys *act, u16 baseSlot, const struct BbActDesc *desc, u32 count, u32 mode);
extern void func_0204F6DC(struct BbBoard *board, int elemId, u8 *polyId);
extern void func_02050468(struct BbActSys *act, u16 first, u32 count);
extern int func_0216E1C4(const Mmdl *mmdl, const u16 *info);
extern void *func_0216D67C(const Mmdl *mmdl);
extern int func_0216D98C(void *mmdlSys);
extern int func_0216DAB4(const Mmdl *mmdl);
extern u32 func_0216D57C(const Mmdl *mmdl, u32 bit);
extern void func_0216D92C(const Mmdl *mmdl, VecFx32 *out);
extern void func_0207C9D0(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void func_0216D8B0(const Mmdl *mmdl, VecFx32 *out);
extern void func_0204F720(struct BbBoard *board, u32 elemId, u32 *visible);
extern void func_0204F638(struct BbBoard *board, int elemId, const VecFx32 *pos);
struct FieldMap *func_021ABE14(FieldEffectSys *sys);
int func_021ABE24(FieldEffectSys *sys);
void *func_021ABEA0(FieldEffectSys *sys, int id);
void func_021ABFA8(FieldEffectSys *sys, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority);
void func_021AC154(FieldEffectObj *obj);
void func_021AC178(FieldEffectObj *obj);
void *func_021AC1AC(FieldEffectObj *obj);
FldeffShadow *func_021AC218(FieldEffectSys *sys, int heapId);
void func_021AC260(FieldEffectSys *sys, FldeffShadow *shadow);
void func_021AC274(FldeffShadow *shadow);
void func_021AC2AC(FldeffShadow *shadow);
void func_021AC2C0(Mmdl *mmdl, FieldEffectSys *sys);
void func_021AC2F0(FieldEffectObj *obj, FldeffShadowWork *work);
void func_021AC384(FieldEffectObj *obj, FldeffShadowWork *work);
void func_021AC3A4(FieldEffectObj *obj, FldeffShadowWork *work);
void func_021AC3F8(FieldEffectObj *obj, FldeffShadowWork *work);
extern char d_021DE028[];
extern VecFx32 d_021D908C;
extern FieldEffectObjFuncs d_021D9098;

/* Resource creation: allocates the resource and makes its billboard slot. */
FldeffShadow *func_021AC218(FieldEffectSys *sys, int heapId)
{
    FldeffShadow *shadow;

    shadow = func_02030734(heapId, sizeof(FldeffShadow), 1, d_021DE028, 0x5c);
    shadow->fieldEffect = sys;
    shadow->baseOffset = d_021D908C;
    shadow->billboardAct = func_02188C88(func_021ABE14(sys));
    shadow->board = func_02050080(shadow->billboardAct);
    func_021AC274(shadow);
    return shadow;
}









/* Resource deletion: frees the billboard slot and the resource. */
void func_021AC260(FieldEffectSys *sys, FldeffShadow *shadow)
{
    func_021AC2AC(shadow);
    ENV_SetResourceSet(shadow);
}









/* Makes the billboard slot that holds the shadow image. */
void func_021AC274(FldeffShadow *shadow)
{
    struct BbActRec rec;

    rec.resource = (u32)func_02046E24(func_021ABE24(shadow->fieldEffect), 0x2f);
    rec.format = 2;
    rec.sizeS = 0x11;
    rec.sizeT = 0x10;
    rec.paletteId = 0x10;
    rec.kind = 1;
    shadow->slotId = func_020500F0(shadow->billboardAct, &rec, 1);
}









/* Frees the billboard slot of the shadow image. */
void func_021AC2AC(FldeffShadow *shadow)
{
    func_02050278(shadow->billboardAct, (u16)shadow->slotId, 1);
}









/* Starts the shadow effect of a model. */
void func_021AC2C0(Mmdl *mmdl, FieldEffectSys *sys)
{
    FldeffShadowParam param;

    param.shadow = func_021ABEA0(sys, FLDEFF_ID_SHADOW);
    param.mmdl = mmdl;
    func_021ABFA8(sys, &d_021D9098, 0, 0, &param, 0);
}









/* Shadow effect: init, makes the billboard entry of the shadow. */
void func_021AC2F0(FieldEffectObj *obj, FldeffShadowWork *work)
{
    FldeffShadowParam *param = func_021AC1AC(obj);
    u8 polyId;
    struct BbActDesc desc;

    work->shadow = param->shadow;
    work->mmdl = param->mmdl;
    func_0216E1A4(param->mmdl, work->mmdlCheck);
    desc.slot = 0;
    desc.width = FLDEFF_SHADOW_ENTRY_SIZE;
    desc.height = FLDEFF_SHADOW_ENTRY_SIZE;
    desc.layer = FLDEFF_SHADOW_ENTRY_LAYER;
    desc.flags = 1;
    desc.color = 1;
    {
        VecFx32 zero = {0, 0, 0};

        desc.pos = zero;
    }
    desc.hook = 0;
    desc.hookArg = (u32)work;
    work->entryId = func_02050340(work->shadow->billboardAct, (u16)work->shadow->slotId, &desc, 1, 3);
    if (work->entryId == 0xFFFF) {
        func_021AC154(obj);
        return;
    }
    polyId = FLDEFF_SHADOW_POLY_ID;
    func_0204F6DC(work->shadow->board, work->entryId, &polyId);
    func_021AC178(obj);
}








/* Shadow effect: exit, deletes the billboard entry. */
void func_021AC384(FieldEffectObj *obj, FldeffShadowWork *work)
{
    if (work->entryId != 0xFFFF)
        func_02050468(work->shadow->billboardAct, (u16)work->entryId, 1);
}








/* Shadow effect: update, ends the effect when the model is gone and tracks if it hides the shadow. */
void func_021AC3A4(FieldEffectObj *obj, FldeffShadowWork *work)
{
    if (func_0216E1C4(work->mmdl, work->mmdlCheck) == 0) {
        func_021AC154(obj);
        return;
    }
    if (func_0216D98C(func_0216D67C(work->mmdl)) == 0) {
        func_021AC154(obj);
        return;
    }
    if (func_0216DAB4(work->mmdl) == 1 || func_0216D57C(work->mmdl, FLDEFF_SHADOW_HIDE_MOVE_BIT) != 0)
        work->hidden = 1;
    else
        work->hidden = 0;
}








/* Shadow effect: draw, shows the entry below the model or hides it. */
void func_021AC3F8(FieldEffectObj *obj, FldeffShadowWork *work)
{
    VecFx32 pos;
    VecFx32 offset;
    u32 show;
    u32 hide;
    u32 entryId = work->entryId;
    const MmdlObjCodeParam *codeParam = func_0216E3C4(work->mmdl);
    if (work->hidden == 0) {
        show = 1;
        func_0216D88C(work->mmdl, &pos);
        func_0216D92C(work->mmdl, &offset);
        func_0207C9D0(&pos, &offset, &pos);
        if ((u8)(codeParam->drawProcNo + 246) <= 1) {
            func_0216D8B0(work->mmdl, &offset);
            if (codeParam->mdlSize == 0)
                offset.y = -0x800;
            func_0207C9D0(&pos, &offset, &pos);
        }
        func_0204F720(work->shadow->board, entryId, &show);
        pos.y += FLDEFF_SHADOW_RAISE;
        func_0204F638(work->shadow->board, entryId, &pos);
    } else {
        hide = 0;
        func_0204F720(work->shadow->board, entryId, &hide);
    }
}
