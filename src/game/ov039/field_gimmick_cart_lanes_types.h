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

#include "../types.h"

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
struct TcbTask;
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
 * Offsets of FieldGimmickCartLanesSave.laneState and FieldGimmickCartLanesWork.parkedDock. The code
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
typedef struct FieldGimmickCartLanesDockCell {
    u16 x;
    u16 z;
} FieldGimmickCartLanesDockCell;

/* The common work of the gimmick on the field map (0x21F4 bytes, id 1). */
typedef struct FieldGimmickCartLanesWork {
    struct TcbTask *task;                       /* 0x00: per-frame task */
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
} FieldGimmickCartLanesWork;

/* The joint animation resource: the offset of the tag of each joint follows the header. */
typedef struct FieldGimmickCartLanesJointAnim {
    u8  header[0x14];
    u16 tagOffset[1];   /* per joint, from the start of the resource */
} FieldGimmickCartLanesJointAnim;

/* A joint animation track: key format flags and the offset of the key array. */
typedef struct FieldGimmickCartLanesJointTrack {
    u32 info;           /* bit 29: 16 bit keys; bits 30, 31: key step 2 or 4; bits 16..28: last frame */
    u32 dataOffset;     /* from the start of the animation resource */
} FieldGimmickCartLanesJointTrack;

/* The tag of a joint: flags and the tracks of the axes that are not constant. */
typedef struct FieldGimmickCartLanesJointTag {
    u32 flags;
    FieldGimmickCartLanesJointTrack track[3];
} FieldGimmickCartLanesJointTag;

#define FIELD_GIMMICK_CART_LANES_JOINT_NO_TRANSLATE    0x06    /* flags: the joint has no translation track */
#define FIELD_GIMMICK_CART_LANES_JOINT_X_CONSTANT      0x08
#define FIELD_GIMMICK_CART_LANES_JOINT_Y_CONSTANT      0x10
#define FIELD_GIMMICK_CART_LANES_JOINT_Z_CONSTANT      0x20

#include "../arm9/ica_anime_shared_types.h"

/* Data of the overlay. */
extern const G3dUtilSetup sCartSetup;
extern const VecFx32 sModelPos00, sModelPos01, sModelPos02, sModelPos03, sModelPos04, sModelPos05;
extern const VecFx32 sModelPos06, sModelPos07, sModelPos08, sModelPos09, sModelPos10, sModelPos11;
extern u32 sRideAnimeIds[];
extern s8 sStopDocks[][2];
extern VecFx32 sRideAnimeOrigin;
extern VecFx32 sLaneRideOffsets[];
extern unsigned char sDockLanes[];
extern FieldGimmickCartLanesDockCell sDockCells[];
extern VecFx32 sRideExitPos;
extern const u32 sStopFrames[][2];
extern const u16 sSwitchFrameLimits[];

/* Functions of overlay 21 and arm9 that the gimmick uses. */
#include "../arm9/tcb_list.h"
#include "../arm9/game_event.h"

#include "../ov021/fld_exp_obj.h"





/* Functions of the overlay. */
u8 FIELD_GIMMICK_CART_LANES_FindDockAt(int x, int z);
u8 FIELD_GIMMICK_CART_LANES_GetActiveCart(FieldGimmickCartLanesWork *work, int lane);
void FIELD_GIMMICK_CART_LANES_Setup(struct FieldMap *fieldMap);
void FIELD_GIMMICK_CART_LANES_UpdateTask(struct TcbTask *tcb, struct FieldMap *fieldMap);
void FIELD_GIMMICK_CART_LANES_End(struct FieldMap *fieldMap);
void FIELD_GIMMICK_CART_LANES_SaveCartFrames(struct FieldMap *fieldMap);
void FIELD_GIMMICK_CART_LANES_TransferSound(struct GameSystem *gameSystem);
u8 FIELD_GIMMICK_CART_LANES_GetDockCart(FieldGimmickCartLanesWork *work, int dock);
unsigned char FIELD_GIMMICK_CART_LANES_GetDockLane(int dock);
int FIELD_GIMMICK_CART_LANES_IsCartAtDock(FieldGimmickCartLanesWork *work, int dock);
int FIELD_GIMMICK_CART_LANES_GetAnimeFrame(FldExpObjCnt *expObj, u16 lane, u16 animeIndex);
void FIELD_GIMMICK_CART_LANES_SetAnimeFrame(FldExpObjCnt *expObj, u8 lane, u16 animeIndex, int frame);
struct GameEvent *FIELD_GIMMICK_CART_LANES_CreateSwitchEvent(struct GameSystem *gameSystem, u32 lane);
int FIELD_GIMMICK_CART_LANES_SwitchEventMain(struct GameEvent *event, int *seq, void *eventWork);
struct GameEvent *FIELD_GIMMICK_CART_LANES_CheckRideEvent(struct GameSystem *gameSystem);
void FIELD_GIMMICK_CART_LANES_UnlockLaneFromScript(struct GameSystem *gameSystem, u32 lane);
int FIELD_GIMMICK_CART_LANES_IsLaneLocked(FieldGimmickCartLanesSave *save, int lane);
void FIELD_GIMMICK_CART_LANES_UnlockLane(FieldGimmickCartLanesSave *save, u8 lane);
int FIELD_GIMMICK_CART_LANES_RideEventMain(struct GameEvent *event, int *seq, void *eventWork);
int FIELD_GIMMICK_CART_LANES_RideRefusedEventMain(struct GameEvent *event, int *seq, void *eventWork);
void FIELD_GIMMICK_CART_LANES_ApplySwitch(struct FieldMap *fieldMap, FldExpObjCnt *expObj);
void FIELD_GIMMICK_CART_LANES_SwapCartAnimes(FldExpObjCnt *expObj, int oldState, int lane);
int FIELD_GIMMICK_CART_LANES_FindStopAtFrame(u32 cart, u32 frame, u8 *stopIndex);
int FIELD_GIMMICK_CART_LANES_IsCartBeforeSwitchLimit(FldExpObjCnt *expObj, int lane, u8 cart);
void FIELD_GIMMICK_CART_LANES_SampleJointTranslation(const u8 *resAnm, int jointIndex, int frame, VecFx32 *out);
void FIELD_GIMMICK_CART_LANES_SampleJointTrack(int *out, int frame, const FieldGimmickCartLanesJointTrack *track, const u8 *base);
void FIELD_GIMMICK_CART_LANES_UpdateCartSound(struct FieldMap *fieldMap, FieldGimmickCartLanesWork *work);

#endif
