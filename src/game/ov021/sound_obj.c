/*
 * file:     sound_obj.c
 * unit:     yes
 * function: SOUND_OBJ_Create, SOUND_OBJ_CreateNoSource, SOUND_OBJ_Delete, SOUND_OBJ_SetAnime, SOUND_OBJ_AdvanceAnime, SOUND_OBJ_SetAnimeFrame, SOUND_OBJ_GetAnimeFrame, SOUND_OBJ_ApplyPosition, SOUND_OBJ_ApplyRotation
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
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   ISS_SYS_Get3dsSys  0x0202B57C  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   ISS_3DS_SYS_IsSourceActive  0x0202B928  thumb
 *   ISS_3DS_SYS_StartSource  0x0202B920  thumb
 *   gSoundObjFileName     0x021DE48C  data  a4
 *   ICA_ANIME_Delete  0x02011558  thumb
 *   ICA_ANIME_GetFrame  0x0201160C  thumb
 *   ISS_3DS_SYS_SetSourcePos  0x0202B934  thumb
 *   ICA_ANIME_GetRotate  0x02011638  thumb
 *   MTX_Identity33_  0x0207ADC4  arm
 *   BUTTON_MAN_MakeRotMtxXYZ  0x020520FC  arm
 *   abs_id_C2      0x000000C2  data
 *   ov171_id       0x000000AB  data  a1
 *   ICA_ANIME_CreateStream  0x02011510  thumb  arm9
 *   ICA_ANIME_IncFrameLoop  0x02011590  thumb  arm9
 *   ICA_ANIME_SetFrame  0x020115EC  thumb  arm9
 *   ICA_ANIME_GetTranslate  0x02011610  thumb  arm9
 *   _fadd                        0x0209C95C  arm
 *   _fdiv                        0x0209CE10  arm
 *   _ffixu                       0x0209C4C8  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fls                         0x0209BC74  arm
 *   _fmul                        0x0209C77C  arm
 */
#include "field_effect_types.h"
#include "../ov010/fldmmdl_types.h"

struct BbActDesc;
struct BbActSys;
struct BbActRec;
struct Actor;
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


typedef signed char    s8;





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

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 GFL_HEAP_Free(void *p);
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
struct GameSystem;
extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
extern void *GAMESYSTEM_GetIssSystem(struct GameSystem *gameSystem);
extern u32 ISS_SYS_Get3dsSys(void *obj);
extern int ISS_3DS_SYS_IsSourceActive(int a, int b);
extern void ISS_3DS_SYS_StartSource(void *m, int i, int a, int b);
extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern struct IcaAnime *ICA_ANIME_CreateStream(u32 heap, u32 arcId, u32 dataId, u32 bufFrameNum);
extern u32 ICA_ANIME_IncFrameLoop(struct IcaAnime *p, s32 v);
extern void ICA_ANIME_SetFrame(struct IcaAnime *p, s32 v);
extern u32 ICA_ANIME_GetFrame(struct IcaAnime *p);
extern u32 ICA_ANIME_GetTranslate(struct IcaAnime *t, VecFx32 *out);
extern void ISS_3DS_SYS_SetSourcePos(u32 a, u32 b, VecFx32 *pos);
extern u32 ICA_ANIME_GetRotate(struct IcaAnime *ctx, VecFx32 *out);
extern void MTX_Identity33_(void *p);
extern void BUTTON_MAN_MakeRotMtxXYZ(int h, int s, int v, struct Mtx33 *out);
/* Retain the mode used to store f59 for the helper's second argument. */
SoundObj *SOUND_OBJ_Create(FieldMap *fieldMap, VecFx32 *pos, u32 sourceId, u32 startArg0, u32 startArg1);
SoundObj *SOUND_OBJ_CreateNoSource(FieldMap *fieldMap, SoundObjTarget *target);
int SOUND_OBJ_Delete(SoundObj *obj);
void SOUND_OBJ_SetAnime(SoundObj *obj, u32 arcId, u32 dataId, u32 bufFrameNum);
u32 SOUND_OBJ_AdvanceAnime(SoundObj *obj, s32 deltaFrame);
void SOUND_OBJ_SetAnimeFrame(SoundObj *obj, s32 frame);
u32 SOUND_OBJ_GetAnimeFrame(SoundObj *obj);
void SOUND_OBJ_ApplyPosition(SoundObj *obj);
void SOUND_OBJ_ApplyRotation(SoundObj *obj);
extern char gSoundObjFileName[];
extern unsigned char abs_id_C2[];
extern char ov171_id[];
/* Sound object (sound_obj.c): a 3D sound source, optionally moved by an ICA animation. */
SoundObj *SOUND_OBJ_Create(FieldMap *fieldMap, VecFx32 *pos, u32 sourceId, u32 startArg0, u32 startArg1)
{
    int heapId = FIELDMAP_GetHeapId((struct FieldMap *)fieldMap);
    void *iss3dsSys;
    SoundObj *obj;

    iss3dsSys = (void *)ISS_SYS_Get3dsSys((void *)GAMESYSTEM_GetIssSystem((struct GameSystem *)FIELDMAP_GetGameSystem((void *)fieldMap)));
    obj = GFL_HEAP_Alloc(heapId, 0x18, 0, gSoundObjFileName, 0x3c);
    obj->heapId = heapId;
    obj->fieldMap = fieldMap;
    obj->iss3dsSys = iss3dsSys;
    obj->sourceId = sourceId;
    obj->anime = 0;
    obj->target = (SoundObjTarget *)pos;
    if (ISS_3DS_SYS_IsSourceActive((int)iss3dsSys, sourceId) == 0) {
        ISS_3DS_SYS_StartSource(iss3dsSys, sourceId, startArg0, startArg1);
    }
    return obj;
}

/* Sound object without a sound source, only the animated target. */
SoundObj *SOUND_OBJ_CreateNoSource(FieldMap *fieldMap, SoundObjTarget *target)
{
    u32 heapId = FIELDMAP_GetHeapId((struct FieldMap *)fieldMap);
    SoundObj *obj = GFL_HEAP_Alloc(heapId, 0x18, 0, gSoundObjFileName, 0x61);

    obj->heapId = heapId;
    obj->fieldMap = fieldMap;
    obj->iss3dsSys = 0;
    obj->anime = 0;
    obj->target = target;
    return obj;
}

int SOUND_OBJ_Delete(SoundObj *obj)
{
    if (obj->anime != 0) {
        ICA_ANIME_Delete((struct IcaAnime *)obj->anime);
    }
    return GFL_HEAP_Free(obj);
}

/* Restarts the animation with a new stream. */
void SOUND_OBJ_SetAnime(SoundObj *obj, u32 arcId, u32 dataId, u32 bufFrameNum)
{
    if (obj->anime != 0)
        ICA_ANIME_Delete((struct IcaAnime *)obj->anime);
    obj->anime = ICA_ANIME_CreateStream(obj->heapId, arcId, dataId, bufFrameNum);
}

/* Advances the animation by deltaFrame, then applies position and rotation. Returns the frame result. */
u32 SOUND_OBJ_AdvanceAnime(SoundObj *obj, s32 deltaFrame)
{
    u32 result;

    if (obj->anime == 0)
        return 0;
    result = ICA_ANIME_IncFrameLoop((struct IcaAnime *)obj->anime, deltaFrame);
    SOUND_OBJ_ApplyPosition(obj);
    SOUND_OBJ_ApplyRotation(obj);
    return result;
}

/* Sets the animation frame and applies the position. */
void SOUND_OBJ_SetAnimeFrame(SoundObj *obj, s32 frame)
{
    if (obj->anime != 0) {
        ICA_ANIME_SetFrame((struct IcaAnime *)obj->anime, frame);
        SOUND_OBJ_ApplyPosition(obj);
    }
}

/* Returns the animation frame, 0 without an animation. */
u32 SOUND_OBJ_GetAnimeFrame(SoundObj *obj)
{
    if (obj->anime == 0)
        return 0;
    return ICA_ANIME_GetFrame((struct IcaAnime *)obj->anime);
}

static inline void V3_Set(VecFx32 *dst, int x, int y, int z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

/* Copies the animated position into the target and moves the sound source there. */
void SOUND_OBJ_ApplyPosition(SoundObj *obj)
{
    VecFx32 pos;

    if (obj->anime != 0 && ICA_ANIME_GetTranslate((struct IcaAnime *)obj->anime, (VecFx32 *)&pos) == 1) {
        V3_Set(&obj->target->pos, pos.x, pos.y, pos.z);
        if (obj->iss3dsSys != 0)
            ISS_3DS_SYS_SetSourcePos((u32)obj->iss3dsSys, obj->sourceId, &pos);
    }
}

/*
 * Builds the rotation matrix of the target from the animated rotation: three
 * 4.12 angles in degrees, wrapped into [0,360), rescaled to 0..65535.
 */
void SOUND_OBJ_ApplyRotation(SoundObj *obj)
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
    if (ICA_ANIME_GetRotate((struct IcaAnime *)obj->anime, (VecFx32 *)rotation) != 1) {
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
    MTX_Identity33_(&obj->target->rotate);
    BUTTON_MAN_MakeRotMtxXYZ(rotX, rotY, rotZ, (struct Mtx33 *)&obj->target->rotate);
}
