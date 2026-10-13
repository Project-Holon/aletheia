#ifndef ALETHEIA_OV040_UNIT_021F36C0_TYPES_H
#define ALETHEIA_OV040_UNIT_021F36C0_TYPES_H

/*
 * Field gimmick 40 (overlay 40): one expansion model with one animation.
 * Script commands set a flag, read it, and start the animation event.
 */

/*
 * The expansion object types come from ov021/fld_exp_obj_types.h, which the
 * source file includes first (the compiler resolves includes against the
 * source file directory, so this header cannot include it). A file that does
 * not include it sees the types as opaque.
 */
#ifndef ALETHEIA_OV021_FLD_EXP_OBJ_TYPES_H
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int fx32;
typedef struct FldExpObjCnt FldExpObjCnt;
typedef struct FldExpObjAnime FldExpObjAnime;
typedef struct G3dUtilSetup G3dUtilSetup;
typedef struct G3dObjectStatus G3dObjectStatus;
#endif

struct FieldMap;
struct GameSystem;
struct GameData;
struct GameEvent;
struct GimmickWork;

typedef int (*GameEventFunc)(struct GameEvent *event, int *seq, void *work);

/* The common work of the gimmick on the field map (4 bytes, id 1). */
typedef struct Gimmick40Work {
    u16 modelIndex;     /* 0x00: model whose animation the event plays */
    u16 reserved;       /* 0x02 */
} Gimmick40Work;

/* The gimmick save area (work id 3 of the gimmick work). */
typedef struct Gimmick40Save {
    s32 flag;           /* 0x00: set and read by script commands */
    u8  animeDone[1];   /* 0x04: per model, the animation was played */
} Gimmick40Save;

/* Where the model stands (x and z in fx32). */
typedef struct Gimmick40ModelPos {
    fx32 x;
    fx32 z;
} Gimmick40ModelPos;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
extern FldExpObjCnt *func_02188D2C(struct FieldMap *fieldMap);
extern u16 func_02188C84(struct FieldMap *fieldMap);
extern void *func_02189764(struct FieldMap *fieldMap, int id, int heapId, int size);
extern void func_021897A0(struct FieldMap *fieldMap, int id);
extern void *func_021897BC(struct FieldMap *fieldMap, int id);
extern struct GameSystem *func_02188C80(struct FieldMap *fieldMap);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct GimmickWork *func_02012EC4(struct GameData *gameData);
extern void *func_0200B3A4(struct GimmickWork *gimmickWork, u32 gimmickId);
extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent,
                                       GameEventFunc func, u32 workSize);
extern void func_021BE310(FldExpObjCnt *expObj, G3dUtilSetup *setup, u16 unitIndex);
extern void func_021BE418(FldExpObjCnt *expObj, u16 unitIndex);
extern G3dObjectStatus *func_021BE480(FldExpObjCnt *expObj, unsigned unitIndex, int modelIndex);
extern FldExpObjAnime *func_021BE674(FldExpObjCnt *expObj, int unitIndex, unsigned modelIndex, int animeIndex);
extern void func_021BE6B0(FldExpObjAnime *anime, int paused);
extern void func_021BE6B8(FldExpObjAnime *anime, int loop);
extern int func_021BE6BC(FldExpObjAnime *anime);
extern void func_021BE6CC(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int animeIndex, int frame);
extern void func_021BE700(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int animeIndex, int enable);
extern int func_021BE748(FldExpObjAnime *anime);
extern void func_021BE580(FldExpObjCnt *expObj);

int func_021F381C(struct GameEvent *event, int *seq, void *work);

#endif
