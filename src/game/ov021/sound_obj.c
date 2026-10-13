/*
 * file:     sound_obj.c
 * unit:     yes
 * function: func_021C4D14, func_021C4D7C, func_021C4DA8, func_021C4DC0, func_021C4DE4, func_021C4E08, func_021C4E20, func_021C4E34, func_021C4E6C
 * address:  0x021C4D14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldeff_splash.c at 0x021C4D14 (lane FXC, CL129: allocations with the sound_obj.c file string at 021C4D14 and 021C4D7C).
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02012134  0x02012134  thumb
 *   func_0202B57C  0x0202B57C  thumb
 *   func_02030734  0x02030734  arm
 *   func_0202B928  0x0202B928  thumb
 *   func_0202B920  0x0202B920  thumb
 *   d_021DE48C     0x021DE48C  data  a4
 *   func_02011558  0x02011558  thumb
 *   func_0201160C  0x0201160C  thumb
 *   func_0202B934  0x0202B934  thumb
 *   func_02011638  0x02011638  thumb
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_020520FC  0x020520FC  arm
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

typedef struct FieldMap FieldMap;
typedef struct { fx32 m[3][3]; } MtxFx33;
typedef struct SoundObjTarget {
    VecFx32 pos;
    VecFx32 scale;
    MtxFx33 rotate;
} SoundObjTarget;

typedef struct SoundObj {
    u16 heapId;
    u16 pad02;
    FieldMap *fieldMap;
    void *iss3dsSys;
    u32 sourceId;
    void *anime;
    SoundObjTarget *target;
} SoundObj;

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

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02188C80(void *p);
extern u32 func_02012134(u32 *p);
extern u32 func_0202B57C(void *obj);
extern int func_0202B928(int a, int b);
extern void func_0202B920(void *m, int i, int a, int b);
extern void func_02011558(struct IcaAnime *p);
extern void *func_02011510(u32 heap, u32 a1, u32 a2, u32 a3);
extern u32 func_02011590(struct IcaAnime *p, s32 v);
extern void func_020115EC(struct IcaAnime *p, s32 v);
extern u32 func_0201160C(struct IcaAnime *p);
extern u32 func_02011610(struct IcaAnime *t, VecFx32 *out);
extern void func_0202B934(u32 a, u32 b, VecFx32 *pos);
extern u32 func_02011638(struct IcaAnime *ctx, VecFx32 *out);
extern void func_0207ADC4(void *p);
extern void func_020520FC(int h, int s, int v, struct Mtx33 *out);
/* Retain the mode used to store f59 for the helper's second argument. */
SoundObj *func_021C4D14(FieldMap *fieldMap, VecFx32 *pos, u32 sourceId, u32 startArg0, u32 startArg1);
SoundObj *func_021C4D7C(FieldMap *fieldMap, SoundObjTarget *target);
int func_021C4DA8(SoundObj *obj);
void func_021C4DC0(SoundObj *obj, u32 arg0, u32 arg1, u32 arg2);
u32 func_021C4DE4(SoundObj *obj, s32 deltaFrame);
void func_021C4E08(SoundObj *obj, s32 frame);
u32 func_021C4E20(SoundObj *obj);
void func_021C4E34(SoundObj *obj);
void func_021C4E6C(SoundObj *obj);
extern char d_021DE48C[];
extern unsigned char abs_id_C2[];
extern char ov171_id[];
/* Sound object (sound_obj.c): a 3D sound source, optionally moved by an ICA animation. */
SoundObj *func_021C4D14(FieldMap *fieldMap, VecFx32 *pos, u32 sourceId, u32 startArg0, u32 startArg1)
{
    int heapId = func_02188C84((u8 *)fieldMap);
    void *iss3dsSys;
    SoundObj *obj;

    iss3dsSys = (void *)func_0202B57C((void *)func_02012134((u32 *)func_02188C80((void *)fieldMap)));
    obj = func_02030734(heapId, 0x18, 0, d_021DE48C, 0x3c);
    obj->heapId = heapId;
    obj->fieldMap = fieldMap;
    obj->iss3dsSys = iss3dsSys;
    obj->sourceId = sourceId;
    obj->anime = 0;
    obj->target = (SoundObjTarget *)pos;
    if (func_0202B928((int)iss3dsSys, sourceId) == 0) {
        func_0202B920(iss3dsSys, sourceId, startArg0, startArg1);
    }
    return obj;
}

/* Sound object without a sound source, only the animated target. */
SoundObj *func_021C4D7C(FieldMap *fieldMap, SoundObjTarget *target)
{
    u32 heapId = func_02188C84((u8 *)fieldMap);
    SoundObj *obj = func_02030734(heapId, 0x18, 0, d_021DE48C, 0x61);

    obj->heapId = heapId;
    obj->fieldMap = fieldMap;
    obj->iss3dsSys = 0;
    obj->anime = 0;
    obj->target = target;
    return obj;
}

int func_021C4DA8(SoundObj *obj)
{
    if (obj->anime != 0) {
        func_02011558((struct IcaAnime *)obj->anime);
    }
    return func_020307B0(obj);
}

/* Restarts the animation with a new stream. */
void func_021C4DC0(SoundObj *obj, u32 arg0, u32 arg1, u32 arg2)
{
    if (obj->anime != 0)
        func_02011558((struct IcaAnime *)obj->anime);
    obj->anime = func_02011510(obj->heapId, arg0, arg1, arg2);
}

/* Advances the animation by deltaFrame, then applies position and rotation. Returns the frame result. */
u32 func_021C4DE4(SoundObj *obj, s32 deltaFrame)
{
    u32 result;

    if (obj->anime == 0)
        return 0;
    result = func_02011590((struct IcaAnime *)obj->anime, deltaFrame);
    func_021C4E34(obj);
    func_021C4E6C(obj);
    return result;
}

/* Sets the animation frame and applies the position. */
void func_021C4E08(SoundObj *obj, s32 frame)
{
    if (obj->anime != 0) {
        func_020115EC((struct IcaAnime *)obj->anime, frame);
        func_021C4E34(obj);
    }
}

/* Returns the animation frame, 0 without an animation. */
u32 func_021C4E20(SoundObj *obj)
{
    if (obj->anime == 0)
        return 0;
    return func_0201160C((struct IcaAnime *)obj->anime);
}

static inline void V3_Set(VecFx32 *dst, int x, int y, int z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

/* Copies the animated position into the target and moves the sound source there. */
void func_021C4E34(SoundObj *obj)
{
    VecFx32 pos;

    if (obj->anime != 0 && func_02011610((struct IcaAnime *)obj->anime, (VecFx32 *)&pos) == 1) {
        V3_Set(&obj->target->pos, pos.x, pos.y, pos.z);
        if (obj->iss3dsSys != 0)
            func_0202B934((u32)obj->iss3dsSys, obj->sourceId, &pos);
    }
}

/*
 * Builds the rotation matrix of the target from the animated rotation: three
 * 4.12 angles in degrees, wrapped into [0,360), rescaled to 0..65535.
 */
void func_021C4E6C(SoundObj *obj)
{
    s32 rotation[3];
    u16 rotX;
    u16 rotY;
    u16 rotZ;
    float degX;
    float degY;
    float degZ;

    if (obj->anime == 0) {
        return;
    }
    if (func_02011638((struct IcaAnime *)obj->anime, (VecFx32 *)rotation) != 1) {
        return;
    }

    degX = rotation[0] / 4096.0f;
    degY = rotation[1] / 4096.0f;
    degZ = rotation[2] / 4096.0f;

    while (degX < 0.0f) {
        degX += 360.0f;
    }
    while (degY < 0.0f) {
        degY += 360.0f;
    }
    while (degZ < 0.0f) {
        degZ += 360.0f;
    }

    rotX = (u16)(u32)(65535.0f * (degX / 360.0f));
    rotY = (u16)(u32)(65535.0f * (degY / 360.0f));
    rotZ = (u16)(u32)(65535.0f * (degZ / 360.0f));
    func_0207ADC4(&obj->target->rotate);
    func_020520FC(rotX, rotY, rotZ, (struct Mtx33 *)&obj->target->rotate);
}
