#ifndef ALETHEIA_OV039_UNIT_021F36C0_TYPES_H
#define ALETHEIA_OV039_UNIT_021F36C0_TYPES_H

/*
 * Field gimmick 39 (overlay 39): four lanes of rails with carts. Each lane
 * has one expansion model (unit 0, model = lane) and two cart animations
 * (animation 1 + cart, cart = 2 * lane + switch state). A lever per lane
 * (models 4 + lane and 8 + lane) selects which of the two carts of the lane
 * is in use. The player steps on a dock (9 tiles), the cart carries the
 * player along a recorded animation (ICA) to another dock.
 *
 * The functions of this overlay are the gimmick callbacks of the field map
 * (setup, per-frame task, end, save), two script entry points that create
 * events, and the ride events.
 */

/* The unplaced file one directory down includes this header after the path "../../ov021/...". */
#ifndef ALETHEIA_OV021_FLD_EXP_OBJ_TYPES_H
#include "../ov021/fld_exp_obj_types.h"
#endif

typedef signed char s8;
typedef short s16;
typedef long long s64;

struct FieldMap;
struct GameSystem;
struct GameData;
struct GameEvent;
struct GimmickWork;
struct FieldSoundSystem;
struct FieldPlayer;
struct Mmdl;
struct IcaAnime;
struct SndHandle;
struct Tcb;
struct TcbSys;
struct ScriptWork;

#define GIMMICK39_LANE_COUNT        4
#define GIMMICK39_DOCK_COUNT        9
#define GIMMICK39_CART_COUNT        8
#define GIMMICK39_SAVE_ID           2       /* gimmick id given to the work accessor */
#define GIMMICK39_WORK_SIZE         0x21F4
#define GIMMICK39_TILE_SIZE         0x10000 /* one tile in fx32 */
#define GIMMICK39_NO_DOCK           0xFF
#define GIMMICK39_NO_CART           0xFF
#define GIMMICK39_HEAP_ID           0x8015
#define GIMMICK39_RIDE_ANIME_ARC    0x6B
#define GIMMICK39_RIDE_ANIME_BUFFER_SIZE 0x21C0
#define GIMMICK39_DOCK_TIMER        0x5A    /* frames a cart stays at a dock */
#define GIMMICK39_GATE_OPEN_FRAME   0xF000  /* end of the gate animation (animation 0) */

/*
 * Offsets of Gimmick39Save.laneState and Gimmick39Work.parkedDock. The code
 * that sets up the gimmick and the per-frame task reads them through a row
 * pointer (base + lane) plus the field offset, and the compiler spills that
 * pointer as a variable of its own; the field form (base->laneState[lane])
 * recomputes the address and changes the bytes.
 */
#define GIMMICK39_SAVE_LANE_STATE   0x10
#define GIMMICK39_WORK_PARKED_DOCK  0x21F0

/* Bit of the key state (func_0203630C) the ride waits for: Down. */
#define GIMMICK39_KEY_DOWN          0x80

/* Sound effects and sound slots. */
#define GIMMICK39_SLOT_CART_LOOP    0x68A   /* FieldSoundSystem slot of the moving cart */
#define GIMMICK39_SE_CART_RUN       0x6DB   /* effect whose priority follows the cart distance */
#define GIMMICK39_SE_GATE           0x687
#define GIMMICK39_SE_SWITCH         0x689
#define GIMMICK39_SE_RIDE_START     0x68B
#define GIMMICK39_SE_RIDE_END       0x68C
#define GIMMICK39_SE_RIDE_BUMP      0x6D2

/* Scripts started by the ride events. */
#define GIMMICK39_SCRIPT_BOARD      0xD
#define GIMMICK39_SCRIPT_ARRIVE     0xE
#define GIMMICK39_SCRIPT_LOCKED_A   0xF
#define GIMMICK39_SCRIPT_LOCKED_B   0x7
#define GIMMICK39_SCRIPT_LOCKED_END 0x8

/* Model layers: model index = layer * GIMMICK39_LANE_COUNT + lane. */
#define GIMMICK39_LAYER_RAIL        0
#define GIMMICK39_LAYER_LEVER_A     1
#define GIMMICK39_LAYER_LEVER_B     2

/* Position of a dock tile (tile x and z). */
typedef struct Gimmick39DockCell {
    u16 x;
    u16 z;
} Gimmick39DockCell;

/*
 * The gimmick save area (work id 2 of the gimmick work, 0x18 bytes used).
 */
typedef struct Gimmick39Save {
    s32 laneFrame[GIMMICK39_LANE_COUNT];    /* 0x00: cart animation frame kept while the map is off */
    u8  laneState[GIMMICK39_LANE_COUNT];    /* 0x10: lever position of each lane, 0 or 1 */
    u16 laneUnlocked[2];                    /* 0x14: set by script for lanes 1 and 2 */
} Gimmick39Save;

/* The common work of the gimmick on the field map (0x21F4 bytes, id 1). */
typedef struct Gimmick39Work {
    struct Tcb *task;                       /* 0x00: per-frame task */
    u8 selectedCart;                        /* 0x04: cart being ridden, GIMMICK39_NO_CART if none */
    s8 switchLane;                          /* 0x05: lane whose lever is being thrown, -1 if none */
    u8 switchState;                         /* 0x06: lever position being set */
    s8 rideLane;                            /* 0x07: lane of the ride in progress, -1 if none */
    int dockTimer[GIMMICK39_LANE_COUNT];    /* 0x08: frames left before the cart leaves its dock */
    struct IcaAnime *rideAnime;             /* 0x18: player path of the ride */
    u8 rideAnimeBuffer[0x21E4 - 0x1C];      /* 0x1C: buffer of rideAnime (0x21C0 bytes used) */
    int rideActive;                         /* 0x21E4: 1 while the player follows rideAnime */
    u8 switchRequest[GIMMICK39_LANE_COUNT]; /* 0x21E8: lever thrown, cart swap still waiting */
    u8 activeCart[GIMMICK39_LANE_COUNT];    /* 0x21EC: cart in use of each lane (lane * 2 + state) */
    s8 parkedDock[GIMMICK39_LANE_COUNT];    /* 0x21F0: dock the cart of each lane waits at, -1 if moving */
} Gimmick39Work;

/* The joint animation resource: the offset of the tag of each joint follows the header. */
typedef struct Gimmick39JointAnim {
    u8  header[0x14];
    u16 tagOffset[1];   /* per joint, from the start of the resource */
} Gimmick39JointAnim;

/* A joint animation track: key format flags and the offset of the key array. */
typedef struct Gimmick39JointTrack {
    u32 info;           /* bit 29: 16 bit keys; bits 30, 31: key step 2 or 4; bits 16..28: last frame */
    u32 dataOffset;     /* from the start of the animation resource */
} Gimmick39JointTrack;

/* The tag of a joint: flags and the tracks of the axes that are not constant. */
typedef struct Gimmick39JointTag {
    u32 flags;
    Gimmick39JointTrack track[3];
} Gimmick39JointTag;

#define GIMMICK39_JOINT_NO_TRANSLATE    0x06    /* flags: the joint has no translation track */
#define GIMMICK39_JOINT_X_CONSTANT      0x08
#define GIMMICK39_JOINT_Y_CONSTANT      0x10
#define GIMMICK39_JOINT_Z_CONSTANT      0x20

typedef int (*GameEventFunc)(struct GameEvent *event, int *seq, void *work);

/* Data of the overlay. */
extern const G3dUtilSetup d_021F4C18;
extern const VecFx32 d_021F4D60, d_021F4D0C, d_021F4D6C, d_021F4D18, d_021F4D24, d_021F4D3C;
extern const VecFx32 d_021F4D00, d_021F4CD0, d_021F4CDC, d_021F4D30, d_021F4D48, d_021F4CE8;
extern u32 d_021F4C38[];
extern s8 d_021F4C28[][2];
extern VecFx32 d_021F4D54;
extern VecFx32 d_021F4CA0[];
extern unsigned char d_021F4C0C[];
extern Gimmick39DockCell d_021F4C58[];
extern VecFx32 d_021F4CF4;
extern const u32 d_021F4D78[][2];
extern const u16 d_021F4BE4[];

/* Functions of overlay 21 and arm9 that the gimmick uses. */
extern struct GameSystem *func_02188C80(struct FieldMap *fieldMap);
extern u16 func_02188C84(struct FieldMap *fieldMap);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern FldExpObjCnt *func_02188D2C(struct FieldMap *fieldMap);
extern struct TcbSys *func_02188D30(struct FieldMap *fieldMap);
extern void *func_02189764(struct FieldMap *fieldMap, int id, int heapId, int size);
extern void func_021897A0(struct FieldMap *fieldMap, int id);
extern void *func_021897BC(struct FieldMap *fieldMap, int id);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct GimmickWork *func_02012EC4(struct GameData *gameData);
extern Gimmick39Save *func_0200B3A4(struct GimmickWork *gimmickWork, u32 gimmickId);
extern struct FieldSoundSystem *func_02012A30(const struct GameData *gameData);
extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent,
                                       GameEventFunc func, u32 workSize);
extern void *func_02158780(struct GameEvent *event, u16 scriptId, int targetObj, int param, u16 heapId);
extern struct ScriptWork *func_021587B0(struct GameEvent *event, int scriptId, int arg1, int heapId);
extern struct Tcb *func_02030DA8(struct TcbSys *tcbSys, void (*callback)(struct Tcb *, struct FieldMap *),
                                 struct FieldMap *work, u32 priority);
extern void func_02030EAC(struct Tcb *tcb);

extern void func_021BE418(FldExpObjCnt *expObj, u16 unitIndex);
extern G3dObjectStatus *func_021BE480(FldExpObjCnt *expObj, unsigned unitIndex, int modelIndex);
extern struct G3dObject *func_021BE4C4(FldExpObjCnt *expObj, u32 unitIndex, u16 modelIndex);
extern void func_021BE580(FldExpObjCnt *expObj);
extern FldExpObjAnime *func_021BE674(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex, int animeIndex);
extern void func_021BE6B0(FldExpObjAnime *anime, int paused);
extern u8 func_021BE6B4(FldExpObjAnime *anime);
extern void func_021BE6B8(FldExpObjAnime *anime, int loop);
extern int func_021BE6BC(FldExpObjAnime *anime);
extern void func_021BE6CC(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int animeIndex, int frame);
extern int func_021BE6E8(FldExpObjCnt *expObj, int unitIndex, u8 modelIndex, u8 animeIndex);
extern void func_021BE700(FldExpObjCnt *expObj, int unitIndex, int modelIndex, u8 animeIndex, int enable);
extern int func_021BE748(FldExpObjAnime *anime);
extern void func_021BE760(FldExpObjCnt *expObj, const G3dUtilSetup *setup, u16 unitIndex);

extern void func_021A3038(struct FieldPlayer *player, VecFx32 *outPos);
extern void func_021A3044(struct FieldPlayer *player, const VecFx32 *pos);
extern u16 func_021A3050(struct FieldPlayer *player);
extern struct Mmdl *func_021A3074(struct FieldPlayer *player);
extern void func_0216DAC8(struct Mmdl *mmdl, u32 value);
extern void func_0216D5E0(struct Mmdl *mmdl, u32 value);

extern void func_02028A7C(struct FieldSoundSystem *soundSys, u32 seId);
extern void func_02028B50(struct FieldSoundSystem *soundSys, int seId);
extern void FIELD_SOUND_SYSTEM_TransferSlot(struct FieldSoundSystem *soundSys, u32 slot, u32 volume);
extern void func_020061E4(u32 seId);
extern int func_02006148(u32 seId);
extern void func_020061F8(int seSlot);
extern struct SndHandle *GFL_USE_GetSeHandle(int seSlot);
extern void GFL_USE_StopAllSe(void);
extern void NNS_SndHandleSetSeqPriority(struct SndHandle *handle, u8 priority);
extern unsigned int func_0203630C(void);

extern struct IcaAnime *ICA_ANIME_CreateWithFullBuffer(u32 heapId, u32 arcId, u16 dataId, void *buffer, u32 bufferSize);
extern u32 ICA_ANIME_GetTranslateAt(struct IcaAnime *anime, VecFx32 *translate, u32 frame);
extern void func_02011558(struct IcaAnime *anime);

extern struct G3dAnime *func_02047790(struct G3dObject *obj, u16 anmIdx);
extern NNSG3dAnmObj *func_02047674(struct G3dAnime *anime);
extern u32 func_02047828(struct G3dObject *obj, u32 anmIdx, fx32 *frame);
extern u32 func_0204784C(struct G3dObject *obj, u16 anmIdx, fx32 *frame);
extern void func_0207C9D0(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void func_0207CA00(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern fx32 func_0207CBD0(const VecFx32 *v);

/* Functions of the overlay. */
u8 func_021F36C0(int x, int z);
u8 func_021F36F0(Gimmick39Work *work, int lane);
void func_021F36FC(struct FieldMap *fieldMap);
void func_021F3A34(struct Tcb *tcb, struct FieldMap *fieldMap);
void func_021F3CD8(struct FieldMap *fieldMap);
void func_021F3D1C(struct FieldMap *fieldMap);
void func_021F3D74(struct GameSystem *gameSystem);
u8 func_021F3D98(Gimmick39Work *work, int dock);
unsigned char func_021F3DAC(int dock);
int func_021F3DB8(Gimmick39Work *work, int dock);
int func_021F3DE4(FldExpObjCnt *expObj, u16 lane, u16 animeIndex);
void func_021F3E04(FldExpObjCnt *expObj, u8 lane, u16 animeIndex, int frame);
struct GameEvent *func_021F3E24(struct GameSystem *gameSystem, u32 lane);
int func_021F3E70(struct GameEvent *event, int *seq, void *eventWork);
struct GameEvent *func_021F404C(struct GameSystem *gameSystem);
void func_021F4134(struct GameSystem *gameSystem, u32 lane);
int func_021F4158(Gimmick39Save *save, int lane);
void func_021F4184(Gimmick39Save *save, u8 lane);
int func_021F41A8(struct GameEvent *event, int *seq, void *eventWork);
int func_021F4610(struct GameEvent *event, int *seq, void *eventWork);
void func_021F4740(struct FieldMap *fieldMap, FldExpObjCnt *expObj);
void func_021F47D8(FldExpObjCnt *expObj, int oldState, int lane);
int func_021F4864(u32 cart, u32 frame, u8 *stopIndex);
int func_021F4894(FldExpObjCnt *expObj, int lane, u8 cart);
void func_021F48C0(const u8 *resAnm, int jointIndex, int frame, VecFx32 *out);
void func_021F4928(int *out, int frame, const Gimmick39JointTrack *track, const u8 *base);
void func_021F4A18(struct FieldMap *fieldMap, Gimmick39Work *work);

#endif
