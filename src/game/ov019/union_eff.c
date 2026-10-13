/*
 * file:     union_eff.c
 * unit:     yes
 * function: func_0217F8C0, func_0217F8EC, func_0217F914, func_0217F928, func_0217F93C, func_0217F948, func_0217F958, func_0217F97C, func_0217F9BC, func_0217F9DC, func_0217FA10, func_0217FA54, func_0217FA78, func_0217FA9C, func_0217FABC, func_0217FACC, func_0217FAF0, func_0217FB30, func_0217FB70, func_0217FBD0, func_0217FC08, func_0217FC64, func_0217FCA4, func_0217FCC0, func_0217FCC4, func_0217FCE4, func_0217FD04, func_0217FD38, func_0217FD88
 * address:  0x0217F8C0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02034714  0x02034714  arm
 *   func_0200873C  0x0200873C  thumb
 *   d_02180808     0x02180808  data   ov019 a4
 *   sub_020490F4   0x020490F4  arm
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   sub_02034714   0x02034714  arm
 *   func_02049238  0x02049238  arm
 *   d_02180814     0x02180814  data  ov019 a4
 *   func_020470D0 0x020470D0 arm
 *   func_02046EFC 0x02046EFC arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_0204762C 0x0204762C arm
 *   func_02047738 0x02047738 arm
 *   func_02047504 0x02047504 arm
 *   func_02047910 0x02047910 arm
 *   func_0216D88C 0x0216D88C thumb ov010
 *   func_02047AC8 0x02047AC8 arm
 *   func_0216DA30 0x0216DA30 thumb ov010
 *   MTX_Identity33_  0x0207ADC4  arm
 *   d_0218071C       0x0218071C  data   ov019 a4
 *   d_02180758       0x02180758  data   ov019 a4
 */

struct Ctx_0217BD9C;
struct Self;
struct Obj_0217E188;
struct Sub02008700Obj;
struct Rec;
struct Pair;
struct VecFx32;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef short          s16;
typedef int            s32;

typedef struct { int x,y,z; } VecFx32;
#include "../ov012/union_comm_types.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} Sys_0217BD9C;

typedef struct {
    Sys_0217BD9C *sys;
} Ctx_0217BD9C;

typedef struct {
    u8 f00;
    u8 pad01[0x6e - 1];
    s16 f6e;
} Obj_0217E188;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
} Bits_0217DC94;

typedef struct Rec {
    u8  pad0[7];
    u8  lo7 : 3;
    u8  flag7 : 1;
    u8  hi7 : 4;
    u8  pad8;
    u8  f9;
    u8  padA[2];
    u16 name[13];
    u8  f26;
    u8  f27;
} Rec;

typedef struct Sys {
    u32 f0;
    u32 pad4;
    u32 f8;
} Sys;

typedef struct Sub_0217DC94 {
    u8   pad0[0x14];
    Rec *rec;
} Sub_0217DC94;

typedef struct Pair {
    u32 f0;
    u32 f4;
} Pair;

typedef struct Tiles {
    u32 f0;
    u32 a[6];
    u32 b[6];
} Tiles;

typedef struct Self {
    Sys   *sys;
    u8     pad4[0x2800];
    void  *win2804;
    void  *msg2808;
    u8     pad280C[0xc];
    void  *f2818;
    u8     pad281C[0x2830 - 0x281C];
    Sub_0217DC94    sub;
    u8     pad2848[0x352C - 0x2848];
    void  *f352C;
    Tiles *f3530;
} Self;

struct Bits_0217DC94 { u8 pad[7]; unsigned char low:3; unsigned char kind:1; unsigned char high:4; };


#define UNION_EFF_ANIM_MAX    1
#define UNION_EFF_ICON_MAX    10
#define UNION_EFF_ANIM_FRAMES 90

/* One effect model over a field model (0x14 bytes, union_eff.c). */
typedef struct UnionEffObj {
    void *mmdl;      /* 0x00 field model the effect follows; NULL when free */
    void *render;    /* 0x04 G3D render object */
    void *anime;     /* 0x08 G3D animation (anim group only) */
    void *object;    /* 0x0C G3D object; NULL when the slot is free */
    u16 serial;      /* 0x10 creation order, the oldest is reused when full */
    u16 frame;       /* 0x12 frames played (anim group) */
} UnionEffObj;

/* Animated reaction effect (0x20 bytes). */
typedef struct UnionEffAnimGroup {
    UnionEffObj obj[UNION_EFF_ANIM_MAX];  /* 0x00 */
    void *resModel;                       /* 0x14 arc 0x59 file 0x14 */
    void *resAnime;                       /* 0x18 arc 0x59 file 0x15 */
    u16 serial;                           /* 0x1C next serial */
    u8 pad1E[2];
} UnionEffAnimGroup;

/* Still icons over players (0xD4 bytes). */
typedef struct UnionEffIconGroup {
    UnionEffObj obj[UNION_EFF_ICON_MAX];  /* 0x00 */
    void *resModel[2];                    /* 0xC8 arc 0x59 files 0x16, 0x17 */
    u16 serial;                           /* 0xD0 next serial */
    u8 padD2[2];
} UnionEffIconGroup;

/* union_eff work (0xF4 bytes, heap tag 0x8E). */
typedef struct UnionEffWork {
    UnionEffAnimGroup anim;   /* 0x00 */
    UnionEffIconGroup icon;   /* 0x20 */
} UnionEffWork;

/* Draw parameters of G3D_SYSTEM_DrawObjectCulling (0x3C bytes). */
typedef struct UnionEffDrawStatus {
    VecFx32 trans;     /* 0x00 */
    VecFx32 scale;     /* 0x0C */
    s32 rotate[9];     /* 0x18 3x3 matrix */
} UnionEffDrawStatus;

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const void *site, unsigned short tag);
extern u32 func_020307B0(void *p);
void func_02034714(const void *expr, u32 line, const void *file);
struct Sub02008700Obj *func_0200873C(void *sys);
extern void *sub_020490F4(u32 id, u32 heap);
extern void *func_02046E24(void *arc, u32 fileId);
extern int func_02046FF8(void *self);
extern void sub_02034714(const char *expr, u32 line, const char *file);
extern void func_02049238(void *h);
extern int func_020470D0(void *p);
extern void func_02046EFC(void *p);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern void *func_02047564(void *render, const void *resAnime, int index);
extern void *func_0204767C(void *render, void **anime, int animeCount);
extern u32 func_020477A4(void *sys, u32 idx);
extern void func_0204762C(void *p);
extern void func_02047738(void *p);
extern void func_02047504(void *p);
extern int func_02047910(void *p, int idx, int amount);
extern void func_0216D88C(const void *a, void *out);
extern int func_02047AC8(void *a, void *b);
extern int func_0216DA30(void *mmdl);
extern void MTX_Identity33_(void *m);
UnionEffWork *func_0217F8C0(u16 heapId);
void func_0217F8EC(UnionEffWork *work);
void func_0217F914(UnionEffWork *work);
void func_0217F928(UnionEffWork *work);
void func_0217F93C(UnionEffWork *work, void *mmdl);
void func_0217F948(UnionEffWork *work, void *mmdl, u32 iconKind);
void func_0217F958(UnionEffWork *work, void *mmdl);
void func_0217F97C(UnionEffAnimGroup *anim, u32 heapId);
void func_0217F9BC(UnionEffAnimGroup *anim);
void func_0217F9DC(UnionEffAnimGroup *anim, void *mmdl);
void func_0217FA10(UnionEffAnimGroup *anim, UnionEffObj *obj, void *mmdl, u16 serial);
void func_0217FA54(UnionEffObj *obj);
void func_0217FA78(UnionEffObj *obj);
void func_0217FA9C(UnionEffObj *obj, UnionEffDrawStatus *status);
void func_0217FABC(UnionEffAnimGroup *anim);
void func_0217FACC(UnionEffAnimGroup *anim);
void func_0217FAF0(UnionEffAnimGroup *anim);
UnionEffObj *func_0217FB30(UnionEffObj *objs);
void func_0217FB70(UnionEffIconGroup *icon, u32 heapId);
void func_0217FBD0(UnionEffIconGroup *icon);
void func_0217FC08(UnionEffIconGroup *icon, void *mmdl, u32 iconKind);
void func_0217FC64(UnionEffIconGroup *icon, UnionEffObj *obj, void *mmdl, u16 serial, int iconKind);
void func_0217FCA4(UnionEffObj *obj);
void func_0217FCC0(UnionEffObj *obj);
void func_0217FCC4(UnionEffObj *obj, UnionEffDrawStatus *status);
void func_0217FCE4(UnionEffIconGroup *icon);
void func_0217FD04(UnionEffIconGroup *icon);
void func_0217FD38(UnionEffIconGroup *icon);
UnionEffObj *func_0217FD88(UnionEffObj *objs);
extern u32 d_02180808[];
extern const char d_02180814[];
extern const UnionEffDrawStatus d_0218071C;
extern const UnionEffDrawStatus d_02180758;





/*
 * union_eff.c part (anchor 0x0217F8C0): reaction effects drawn over the field
 * models of the union room.  The anim group plays one animated model (arc
 * 0x59 files 0x14/0x15) for 90 frames; the icon group keeps up to ten still
 * models (files 0x16/0x17) over players until they are removed.
 */
UnionEffWork *func_0217F8C0(u16 heapId)
{
    UnionEffWork *work = func_02030734(heapId, sizeof(UnionEffWork), 1, (const char *)d_02180808, 0x8e);
    func_0217F97C(&work->anim, heapId);
    func_0217FB70(&work->icon, heapId);
    return work;
}

void func_0217F8EC(UnionEffWork *work)
{
    if (work) {
        func_0217FCE4(&work->icon);
        func_0217FBD0(&work->icon);
        func_0217FABC(&work->anim);
        func_0217F9BC(&work->anim);
        func_020307B0(work);
    }
}

void func_0217F914(UnionEffWork *work)
{
    if (work) {
        func_0217FD04(&work->icon);
        func_0217FACC(&work->anim);
    }
}

void func_0217F928(UnionEffWork *work)
{
    if (work) {
        func_0217FD38(&work->icon);
        func_0217FAF0(&work->anim);
    }
}

void func_0217F93C(UnionEffWork *work, void *mmdl)
{
    if (work != NULL)
        func_0217F9DC(&work->anim, mmdl);
}

void func_0217F948(UnionEffWork *work, void *mmdl, u32 iconKind)
{
    if (work)
        func_0217FC08(&work->icon, mmdl, iconKind);
}

void func_0217F958(UnionEffWork *work, void *mmdl)
{
    UnionEffIconGroup *icon = &work->icon;
    int i;
    for (i = 0; i < UNION_EFF_ICON_MAX; i++) {
        void *objMmdl = icon->obj[i].mmdl;
        if (objMmdl == mmdl) {
            func_0217FCA4(&icon->obj[i]);
            return;
        }
    }
}

/*
 * Loads the animated model and its animation from arc 0x59, then sends the
 * texture to VRAM (an error there goes to the GFL assert, d_02180814).
 */
void func_0217F97C(UnionEffAnimGroup *anim, u32 heapId)
{
    void *arc = sub_020490F4(0x59, heapId);

    anim->resModel = func_02046E24(arc, 0x14);
    anim->resAnime = func_02046E24(arc, 0x15);
    if (func_02046FF8(anim->resModel) == 0) {
        func_02034714(d_02180814, 0, d_02180814);
    }
    func_02049238(arc);
}

void func_0217F9BC(UnionEffAnimGroup *anim)
{
    func_020470D0(anim->resModel);
    func_02046EFC(anim->resAnime);
    anim->resAnime = NULL;
    func_02046EFC(anim->resModel);
    anim->resModel = NULL;
}

void func_0217F9DC(UnionEffAnimGroup *anim, void *mmdl)
{
    UnionEffObj *obj;
    if (anim->resModel == NULL) func_02034714(d_02180814, 0, d_02180814);
    obj = func_0217FB30(anim->obj);
    func_0217FA10(anim, obj, mmdl, anim->serial);
    (anim->serial)++;
}

void func_0217FA10(UnionEffAnimGroup *anim, UnionEffObj *obj, void *mmdl, u16 serial)
{
    func_02082BCC(obj, 0, sizeof(UnionEffObj));
    obj->mmdl = mmdl;
    obj->serial = serial;
    obj->render = func_02047400(anim->resModel, 0, anim->resModel);
    obj->anime = func_02047564(obj->render, anim->resAnime, 0);
    obj->object = func_0204767C(obj->render, &obj->anime, 1);
    func_020477A4(obj->object, 0);
}

void func_0217FA54(UnionEffObj *obj)
{
    func_0204762C(obj->anime);
    func_02047738(obj->object);
    func_02047504(obj->render);
    func_02082BCC(obj, 0, sizeof(UnionEffObj));
}

void func_0217FA78(UnionEffObj *obj)
{
    func_02047910(obj->object, 0, 0x1000);
    (obj->frame)++;
    if (obj->frame > UNION_EFF_ANIM_FRAMES) func_0217FA54(obj);
}

void func_0217FA9C(UnionEffObj *obj, UnionEffDrawStatus *status)
{
    func_0216D88C(obj->mmdl, &status->trans);
    status->trans.y -= 0x6000;
    func_02047AC8(obj->object, status);
}

void func_0217FABC(UnionEffAnimGroup *anim)
{
    if (anim->obj[0].object != NULL) func_0217FA54(anim->obj);
}

void func_0217FACC(UnionEffAnimGroup *anim)
{
    if (anim->obj[0].object != NULL) {
        if (func_0216DA30(anim->obj[0].mmdl) == 1) func_0217FA78(anim->obj);
        else func_0217FA54(anim->obj);
    }
}

void func_0217FAF0(UnionEffAnimGroup *anim)
{
    UnionEffDrawStatus status = d_0218071C;
    MTX_Identity33_(&status.rotate);
    if (anim->obj[0].object != NULL && func_0216DA30(anim->obj[0].mmdl) == 1) {
        func_0217FA9C(anim->obj, &status);
    }
}

/* A free object, else the oldest one (lowest serial), deleted for reuse. */
UnionEffObj *func_0217FB30(UnionEffObj *objs)
{
    int i, oldest = 0;
    for (i = 0; i < UNION_EFF_ANIM_MAX; i++) {
        UnionEffObj *obj = &objs[i];
        if (obj->object == NULL) {
            return obj;
        }
        if (obj->serial < objs[oldest].serial) {
            oldest = i;
        }
    }
    func_0217FA54(&objs[oldest]);
    return &objs[oldest];
}

/* Loads the two icon models from arc 0x59 and sends their textures to VRAM. */
void func_0217FB70(UnionEffIconGroup *icon, u32 heapId)
{
    void *arc = sub_020490F4(0x59, heapId);
    icon->resModel[0] = func_02046E24(arc, 0x16);
    icon->resModel[1] = func_02046E24(arc, 0x17);
    if (func_02046FF8(icon->resModel[0]) == 0) {
        func_02034714(d_02180814, 0, d_02180814);
    }
    if (func_02046FF8(icon->resModel[1]) == 0) {
        func_02034714(d_02180814, 0, d_02180814);
    }
    func_02049238(arc);
}

void func_0217FBD0(UnionEffIconGroup *icon)
{
    func_020470D0(icon->resModel[0]);
    func_020470D0(icon->resModel[1]);
    func_02046EFC(icon->resModel[0]);
    func_02046EFC(icon->resModel[1]);
    icon->resModel[0] = NULL;
    icon->resModel[1] = NULL;
}

void func_0217FC08(UnionEffIconGroup *icon, void *mmdl, u32 iconKind)
{
    if (icon->resModel[0] == NULL) {
        func_02034714(d_02180814, 0, d_02180814);
    }
    if (icon->resModel[1] == NULL) {
        func_02034714(d_02180814, 0, d_02180814);
    }
    func_0217FC64(icon, func_0217FD88(icon->obj), mmdl, icon->serial, iconKind);
    icon->serial = icon->serial + 1;
}

/*
 * stand-in: the reload of obj->render before the last call is spelled with a
 * volatile read (the plain read keeps the value in a register).
 */
void func_0217FC64(UnionEffIconGroup *icon, UnionEffObj *obj, void *mmdl, u16 serial, int iconKind)
{
    void **resModel;
    func_02082BCC(obj, 0, sizeof(UnionEffObj));
    obj->mmdl = mmdl;
    obj->serial = serial;
    if (iconKind == 0) {
        resModel = &icon->resModel[0];
    } else {
        resModel = &icon->resModel[1];
    }
    obj->render = func_02047400(*resModel, 0, *resModel);
    obj->object = func_0204767C((void *)*(volatile u32 *)&obj->render, NULL, 0);
}

void func_0217FCA4(UnionEffObj *obj)
{
    func_02047738(obj->object);
    func_02047504(obj->render);
    func_02082BCC(obj, 0, sizeof(UnionEffObj));
}

void func_0217FCC0(UnionEffObj *obj)
{
}

void func_0217FCC4(UnionEffObj *obj, UnionEffDrawStatus *status)
{
    func_0216D88C(obj->mmdl, &status->trans);
    status->trans.y -= 0x6800;
    func_02047AC8(obj->object, status);
}

void func_0217FCE4(UnionEffIconGroup *icon)
{
    int i;
    for (i = 0; i < UNION_EFF_ICON_MAX; i++) {
        UnionEffObj *obj = &icon->obj[i];
        if (obj->object != NULL) func_0217FCA4(obj);
    }
}

void func_0217FD04(UnionEffIconGroup *icon)
{
    int i;
    for (i = 0; i < UNION_EFF_ICON_MAX; i++) {
        UnionEffObj *obj = &icon->obj[i];
        if (obj->object != NULL) {
            if (func_0216DA30(obj->mmdl) == 1) func_0217FCC0(obj);
            else func_0217FCA4(obj);
        }
    }
}

void func_0217FD38(UnionEffIconGroup *icon)
{
    UnionEffDrawStatus status = d_02180758;
    int i;
    MTX_Identity33_(&status.rotate);
    for (i = 0; i < UNION_EFF_ICON_MAX; i++) {
        UnionEffObj *obj = &icon->obj[i];
        if (obj->object != NULL && func_0216DA30(obj->mmdl) == 1) {
            func_0217FCC4(obj, &status);
        }
    }
}

/* A free object, else the oldest one (lowest serial), deleted for reuse. */
UnionEffObj *func_0217FD88(UnionEffObj *objs)
{
    int i;
    int oldest = 0;
    UnionEffObj *obj;
    for (i = 0; i < UNION_EFF_ICON_MAX; i++) {
        obj = &objs[i];
        if (obj->object == NULL)
            return obj;
        if (obj->serial < objs[oldest].serial)
            oldest = i;
    }
    obj = &objs[oldest];
    func_0217FCA4(obj);
    return obj;
}
