#ifndef ALETHEIA_OV054_UNIT_021F36C0_TYPES_H
#define ALETHEIA_OV054_UNIT_021F36C0_TYPES_H

/*
 * Field gimmick 54 (overlay 54): two 3D sound objects that follow models of
 * the expansion unit. Each plays its animation once, waits a random time
 * between its limits, and plays it again. The frame of each animation is
 * kept in the gimmick work (slot 11) while the map is left.
 *
 * The expansion object and model types come from ov021/fld_exp_obj_types.h,
 * which the source file includes first (the compiler resolves includes
 * against the source file directory, so this header cannot include it).
 */

#ifndef ALETHEIA_OV021_FLD_EXP_OBJ_TYPES_H
#error "include ../ov021/fld_exp_obj_types.h before this header"
#endif

struct FieldMap;
struct GameSystem;
struct GameData;
struct GimmickWork;
struct FieldCamera;
struct G3dCamera;
struct IssSystem;
struct Iss3dsSys;
struct SoundObj;

/* Archive of the sound data of this gimmick, and the sound sources of its two objects. */
#define GIMMICK54_ARC_ID 0x7f
#define GIMMICK54_SOUND_OBJ_COUNT 2

/* The gimmick work slot that keeps the animation frames. */
#define GIMMICK54_SAVE_SLOT 11

/* Work of the gimmick (0x28 bytes, common work id 0 of the field map). */
typedef struct Gimmick54Work {
    u16 heapId;                                         /* 0x00 */
    u16 reserved02;
    struct Iss3dsSys *iss3ds;                           /* 0x04 */
    struct SoundObj *soundObj[GIMMICK54_SOUND_OBJ_COUNT];   /* 0x08 */
    int waitFrames[GIMMICK54_SOUND_OBJ_COUNT];          /* 0x10: frames left before the animation starts again; 0 while it plays */
    int minWait[GIMMICK54_SOUND_OBJ_COUNT];             /* 0x18: shortest wait */
    int maxWait[GIMMICK54_SOUND_OBJ_COUNT];             /* 0x20: longest wait */
} Gimmick54Work;

/* The animation frames (in whole frames) in the gimmick work. */
typedef struct Gimmick54Save {
    int animeFrame[GIMMICK54_SOUND_OBJ_COUNT];
} Gimmick54Save;

/* Archive members that hold the wait limits of each object. */
typedef struct Gimmick54WaitMembers {
    int member[GIMMICK54_SOUND_OBJ_COUNT];
} Gimmick54WaitMembers;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
extern u16 func_02188C84(struct FieldMap *fieldMap);
extern FldExpObjCnt *func_02188D2C(struct FieldMap *fieldMap);
extern void func_021BE310(FldExpObjCnt *expObj, G3dUtilSetup *setup, u16 unitIndex);
extern void *func_02189764(struct FieldMap *fieldMap, int id, int heapId, int size);
extern void *func_021897BC(struct FieldMap *fieldMap, int id);
extern void func_021897A0(struct FieldMap *fieldMap, int id);
extern void ISS_3DS_SYS_SetVolume(struct Iss3dsSys *iss3ds, u32 volume);
extern int func_021C4DA8(struct SoundObj *obj);
extern struct FieldCamera *func_02188C58(struct FieldMap *fieldMap);
extern struct G3dCamera *func_0218EC2C(struct FieldCamera *camera);
extern void func_02048AE8(struct G3dCamera *camera, VecFx32 *eye);
extern void func_02048B30(struct G3dCamera *camera, VecFx32 *target);
extern void ISS_3DS_SYS_SetCamera(struct Iss3dsSys *iss3ds, VecFx32 *eye, VecFx32 *target);
extern u32 func_021C4DE4(struct SoundObj *obj, s32 deltaFrame);
extern struct GameSystem *func_02188C80(struct FieldMap *fieldMap);
extern struct IssSystem *func_02012134(struct GameSystem *gameSystem);
extern struct Iss3dsSys *func_0202B57C(struct IssSystem *issSystem);
extern int *func_02048F60(u32 archiveId, u32 member, u32 heapId);
extern G3dObjectStatus *func_021BE480(FldExpObjCnt *expObj, unsigned unitIndex, int modelIndex);
extern struct SoundObj *func_021C4D14(struct FieldMap *fieldMap, VecFx32 *pos, u32 sourceId, u32 radius, u32 amplitude);
extern void func_021C4DC0(struct SoundObj *obj, u32 arcId, u32 dataId, u32 bufferFrames);
extern u32 func_020307B0(void *p);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct GimmickWork *func_02012EC4(struct GameData *gameData);
extern Gimmick54Save *func_0200B3A4(struct GimmickWork *gimmickWork, u32 slotId);
extern u32 func_021C4E20(struct SoundObj *obj);
extern void func_021C4E08(struct SoundObj *obj, s32 frame);
extern unsigned func_02005728(unsigned limit);

void func_021F393C(Gimmick54Work *work, int index);

#endif
