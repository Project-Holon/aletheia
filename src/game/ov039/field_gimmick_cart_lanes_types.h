#ifndef ALETHEIA_OV039_FIELD_GIMMICK_CART_LANES_TYPES_H
#define ALETHEIA_OV039_FIELD_GIMMICK_CART_LANES_TYPES_H

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
#include "../ov037/gimmick_save_types.h"

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

#define FIELD_GIMMICK_CART_LANES_DOCK_COUNT        9
#define FIELD_GIMMICK_CART_LANES_CART_COUNT        8
#define FIELD_GIMMICK_CART_LANES_SAVE_ID           2       /* gimmick id given to the work accessor */
#define FIELD_GIMMICK_CART_LANES_WORK_SIZE         0x21F4
#define FIELD_GIMMICK_CART_LANES_TILE_SIZE         0x10000 /* one tile in fx32 */
#define FIELD_GIMMICK_CART_LANES_NO_DOCK           0xFF
#define FIELD_GIMMICK_CART_LANES_NO_CART           0xFF
#define FIELD_GIMMICK_CART_LANES_HEAP_ID           0x8015
#define FIELD_GIMMICK_CART_LANES_RIDE_ANIME_ARC    0x6B
#define FIELD_GIMMICK_CART_LANES_RIDE_ANIME_BUFFER_SIZE 0x21C0
#define FIELD_GIMMICK_CART_LANES_DOCK_TIMER        0x5A    /* frames a cart stays at a dock */
#define FIELD_GIMMICK_CART_LANES_GATE_OPEN_FRAME   0xF000  /* end of the gate animation (animation 0) */

/*
 * Offsets of Gimmick39Save.laneState and Gimmick39Work.parkedDock. The code
 * that sets up the gimmick and the per-frame task reads them through a row
 * pointer (base + lane) plus the field offset, and the compiler spills that
 * pointer as a variable of its own; the field form (base->laneState[lane])
 * recomputes the address and changes the bytes.
 */
#define FIELD_GIMMICK_CART_LANES_SAVE_LANE_STATE   0x10
#define FIELD_GIMMICK_CART_LANES_WORK_PARKED_DOCK  0x21F0

/* Bit of the key state (KEY_GetCont) the ride waits for: Down. */
#define FIELD_GIMMICK_CART_LANES_KEY_DOWN          0x80

/* Sound effects and sound slots. */
#define FIELD_GIMMICK_CART_LANES_SLOT_CART_LOOP    0x68A   /* FieldSoundSystem slot of the moving cart */
#define FIELD_GIMMICK_CART_LANES_SE_CART_RUN       0x6DB   /* effect whose priority follows the cart distance */
#define FIELD_GIMMICK_CART_LANES_SE_GATE           0x687
#define FIELD_GIMMICK_CART_LANES_SE_SWITCH         0x689
#define FIELD_GIMMICK_CART_LANES_SE_RIDE_START     0x68B
#define FIELD_GIMMICK_CART_LANES_SE_RIDE_END       0x68C
#define FIELD_GIMMICK_CART_LANES_SE_RIDE_BUMP      0x6D2

/* Scripts started by the ride events. */
#define FIELD_GIMMICK_CART_LANES_SCRIPT_BOARD      0xD
#define FIELD_GIMMICK_CART_LANES_SCRIPT_ARRIVE     0xE
#define FIELD_GIMMICK_CART_LANES_SCRIPT_LOCKED_A   0xF
#define FIELD_GIMMICK_CART_LANES_SCRIPT_LOCKED_B   0x7
#define FIELD_GIMMICK_CART_LANES_SCRIPT_LOCKED_END 0x8

/* Model layers: model index = layer * FIELD_GIMMICK_CART_LANES_LANE_COUNT + lane. */
#define FIELD_GIMMICK_CART_LANES_LAYER_RAIL        0
#define FIELD_GIMMICK_CART_LANES_LAYER_LEVER_A     1
#define FIELD_GIMMICK_CART_LANES_LAYER_LEVER_B     2

/* Position of a dock tile (tile x and z). */
typedef struct Gimmick39DockCell {
    u16 x;
    u16 z;
} Gimmick39DockCell;

/* The common work of the gimmick on the field map (0x21F4 bytes, id 1). */
typedef struct Gimmick39Work {
    struct Tcb *task;                       /* 0x00: per-frame task */
    u8 selectedCart;                        /* 0x04: cart being ridden, FIELD_GIMMICK_CART_LANES_NO_CART if none */
    s8 switchLane;                          /* 0x05: lane whose lever is being thrown, -1 if none */
    u8 switchState;                         /* 0x06: lever position being set */
    s8 rideLane;                            /* 0x07: lane of the ride in progress, -1 if none */
    int dockTimer[FIELD_GIMMICK_CART_LANES_LANE_COUNT];    /* 0x08: frames left before the cart leaves its dock */
    struct IcaAnime *rideAnime;             /* 0x18: player path of the ride */
    u8 rideAnimeBuffer[0x21E4 - 0x1C];      /* 0x1C: buffer of rideAnime (0x21C0 bytes used) */
    int rideActive;                         /* 0x21E4: 1 while the player follows rideAnime */
    u8 switchRequest[FIELD_GIMMICK_CART_LANES_LANE_COUNT]; /* 0x21E8: lever thrown, cart swap still waiting */
    u8 activeCart[FIELD_GIMMICK_CART_LANES_LANE_COUNT];    /* 0x21EC: cart in use of each lane (lane * 2 + state) */
    s8 parkedDock[FIELD_GIMMICK_CART_LANES_LANE_COUNT];    /* 0x21F0: dock the cart of each lane waits at, -1 if moving */
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

#define FIELD_GIMMICK_CART_LANES_JOINT_NO_TRANSLATE    0x06    /* flags: the joint has no translation track */
#define FIELD_GIMMICK_CART_LANES_JOINT_X_CONSTANT      0x08
#define FIELD_GIMMICK_CART_LANES_JOINT_Y_CONSTANT      0x10
#define FIELD_GIMMICK_CART_LANES_JOINT_Z_CONSTANT      0x20

typedef int (*GameEventFunc)(struct GameEvent *event, int *seq, void *work);

/* Data of the overlay. */
extern const G3dUtilSetup sCartSetup;
extern const VecFx32 sModelPos00, sModelPos01, sModelPos02, sModelPos03, sModelPos04, sModelPos05;
extern const VecFx32 sModelPos06, sModelPos07, sModelPos08, sModelPos09, sModelPos10, sModelPos11;
extern u32 sRideAnimeIds[];
extern s8 sStopDocks[][2];
extern VecFx32 sRideAnimeOrigin;
extern VecFx32 sLaneRideOffsets[];
extern unsigned char sDockLanes[];
extern Gimmick39DockCell sDockCells[];
extern VecFx32 sRideExitPos;
extern const u32 sStopFrames[][2];
extern const u16 sSwitchFrameLimits[];

/* Functions of overlay 21 and arm9 that the gimmick uses. */
extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
extern FldExpObjCnt *FIELDMAP_GetExpObj(struct FieldMap *fieldMap);
extern struct TcbSys *FIELDMAP_GetTcblSys(struct FieldMap *fieldMap);
extern void *FIELDMAP_AllocCommonWork(struct FieldMap *fieldMap, int id, int heapId, int size);
extern void FIELDMAP_FreeCommonWork(struct FieldMap *fieldMap, int id);
extern void *FIELDMAP_GetCommonWork(struct FieldMap *fieldMap, int id);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct GimmickWork *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern Gimmick39Save *GIMMICK_WORK_GetSaveArea(struct GimmickWork *gimmickWork, u32 gimmickId);
extern struct FieldSoundSystem *GAME_DATA_GetBgmInfo(const struct GameData *gameData);
extern struct FieldMap *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent,
                                       GameEventFunc func, u32 workSize);
extern void *SCRIPT_SYS_CallScriptEvent(struct GameEvent *event, u16 scriptId, int targetObj, int param, u16 heapId);
extern struct ScriptWork *SCRIPT_SYS_ChangeScriptEvent(struct GameEvent *event, int scriptId, int arg1, int heapId);
extern struct Tcb *func_02030DA8(struct TcbSys *tcbSys, void (*callback)(struct Tcb *, struct FieldMap *),
                                 struct FieldMap *work, u32 priority);
extern void func_02030EAC(struct Tcb *tcb);

extern void FLD_EXP_OBJ_RemoveUnit(FldExpObjCnt *expObj, u16 unitIndex);
extern G3dObjectStatus *FLD_EXP_OBJ_GetModelStatus(FldExpObjCnt *expObj, unsigned unitIndex, int modelIndex);
extern struct G3dObject *FLD_EXP_OBJ_GetModelObject(FldExpObjCnt *expObj, u32 unitIndex, u16 modelIndex);
extern void func_021BE580(FldExpObjCnt *expObj);
extern FldExpObjAnime *FLD_EXP_OBJ_GetAnime(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex, int animeIndex);
extern void func_021BE6B0(FldExpObjAnime *anime, int paused);
extern u8 func_021BE6B4(FldExpObjAnime *anime);
extern void FLD_EXP_OBJ_SetAnimeLoop(FldExpObjAnime *anime, int loop);
extern int func_021BE6BC(FldExpObjAnime *anime);
extern void FLD_EXP_OBJ_SetAnimeFrame(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int animeIndex, int frame);
extern int func_021BE6E8(FldExpObjCnt *expObj, int unitIndex, u8 modelIndex, u8 animeIndex);
extern void FLD_EXP_OBJ_SetAnimeEnabled(FldExpObjCnt *expObj, int unitIndex, int modelIndex, u8 animeIndex, int enable);
extern int func_021BE748(FldExpObjAnime *anime);
extern void FLD_EXP_OBJ_AddUnitFromArchive(FldExpObjCnt *expObj, const G3dUtilSetup *setup, u16 unitIndex);

extern void FIELD_PLAYER_GetPos(struct FieldPlayer *player, VecFx32 *outPos);
extern void FIELD_PLAYER_SetPos(struct FieldPlayer *player, const VecFx32 *pos);
extern u16 FIELD_PLAYER_GetDirDisp(struct FieldPlayer *player);
extern struct Mmdl *FIELD_PLAYER_GetMmdl(struct FieldPlayer *player);
extern void FLDMMDL_SetStatusBitVanish(struct Mmdl *mmdl, u32 value);
extern void FLDMMDL_SetDirDispCheckPause(struct Mmdl *mmdl, u32 value);

extern void FIELD_SOUND_SYSTEM_ClaimSlot(struct FieldSoundSystem *soundSys, u32 seId);
extern void FIELD_SOUND_SYSTEM_ReleaseSlot(struct FieldSoundSystem *soundSys, int seId);
extern void FIELD_SOUND_SYSTEM_TransferSlot(struct FieldSoundSystem *soundSys, u32 slot, u32 volume);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);
extern int GFL_USE_GetSeSlot(u32 seId);
extern void GFL_USE_StopSeSlot(int seSlot);
extern struct SndHandle *GFL_USE_GetSeHandle(int seSlot);
extern void GFL_USE_StopAllSe(void);
extern void NNS_SndHandleSetSeqPriority(struct SndHandle *handle, u8 priority);
extern unsigned int KEY_GetCont(void);

extern struct IcaAnime *ICA_ANIME_CreateWithFullBuffer(u32 heapId, u32 arcId, u16 dataId, void *buffer, u32 bufferSize);
extern u32 ICA_ANIME_GetTranslateAt(struct IcaAnime *anime, VecFx32 *translate, u32 frame);
extern void ICA_ANIME_Delete(struct IcaAnime *anime);

extern struct G3dAnime *G3D_SYSTEM_GetObjectAnime(struct G3dObject *obj, u16 anmIdx);
extern NNSG3dAnmObj *G3D_SYSTEM_GetAnimeObj(struct G3dAnime *anime);
extern u32 G3D_SYSTEM_GetObjectAnimeFrame(struct G3dObject *obj, u32 anmIdx, fx32 *frame);
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct G3dObject *obj, u16 anmIdx, fx32 *frame);
extern void func_0207C9D0(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void func_0207CA00(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern fx32 func_0207CBD0(const VecFx32 *v);

/* Functions of the overlay. */
u8 FIELD_GIMMICK_CART_LANES_FindDockAt(int x, int z);
u8 FIELD_GIMMICK_CART_LANES_GetActiveCart(Gimmick39Work *work, int lane);
void FIELD_GIMMICK_CART_LANES_Setup(struct FieldMap *fieldMap);
void FIELD_GIMMICK_CART_LANES_UpdateTask(struct Tcb *tcb, struct FieldMap *fieldMap);
void FIELD_GIMMICK_CART_LANES_End(struct FieldMap *fieldMap);
void FIELD_GIMMICK_CART_LANES_SaveCartFrames(struct FieldMap *fieldMap);
void FIELD_GIMMICK_CART_LANES_TransferSound(struct GameSystem *gameSystem);
u8 FIELD_GIMMICK_CART_LANES_GetDockCart(Gimmick39Work *work, int dock);
unsigned char FIELD_GIMMICK_CART_LANES_GetDockLane(int dock);
int FIELD_GIMMICK_CART_LANES_IsCartAtDock(Gimmick39Work *work, int dock);
int FIELD_GIMMICK_CART_LANES_GetAnimeFrame(FldExpObjCnt *expObj, u16 lane, u16 animeIndex);
void FIELD_GIMMICK_CART_LANES_SetAnimeFrame(FldExpObjCnt *expObj, u8 lane, u16 animeIndex, int frame);
struct GameEvent *FIELD_GIMMICK_CART_LANES_CreateSwitchEvent(struct GameSystem *gameSystem, u32 lane);
int FIELD_GIMMICK_CART_LANES_SwitchEventMain(struct GameEvent *event, int *seq, void *eventWork);
struct GameEvent *FIELD_GIMMICK_CART_LANES_CheckRideEvent(struct GameSystem *gameSystem);
void FIELD_GIMMICK_CART_LANES_UnlockLaneFromScript(struct GameSystem *gameSystem, u32 lane);
int FIELD_GIMMICK_CART_LANES_IsLaneLocked(Gimmick39Save *save, int lane);
void FIELD_GIMMICK_CART_LANES_UnlockLane(Gimmick39Save *save, u8 lane);
int FIELD_GIMMICK_CART_LANES_RideEventMain(struct GameEvent *event, int *seq, void *eventWork);
int FIELD_GIMMICK_CART_LANES_RideRefusedEventMain(struct GameEvent *event, int *seq, void *eventWork);
void FIELD_GIMMICK_CART_LANES_ApplySwitch(struct FieldMap *fieldMap, FldExpObjCnt *expObj);
void FIELD_GIMMICK_CART_LANES_SwapCartAnimes(FldExpObjCnt *expObj, int oldState, int lane);
int FIELD_GIMMICK_CART_LANES_FindStopAtFrame(u32 cart, u32 frame, u8 *stopIndex);
int FIELD_GIMMICK_CART_LANES_IsCartBeforeSwitchLimit(FldExpObjCnt *expObj, int lane, u8 cart);
void FIELD_GIMMICK_CART_LANES_SampleJointTranslation(const u8 *resAnm, int jointIndex, int frame, VecFx32 *out);
void FIELD_GIMMICK_CART_LANES_SampleJointTrack(int *out, int frame, const Gimmick39JointTrack *track, const u8 *base);
void FIELD_GIMMICK_CART_LANES_UpdateCartSound(struct FieldMap *fieldMap, Gimmick39Work *work);

#endif
