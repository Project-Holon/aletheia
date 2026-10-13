/*
 * file:     field_flash.c
 * unit:     yes
 * function: func_021C6E5C, func_021C6E74, func_021C6E94, func_021C6EA8, func_021C6EDC, func_021C6F00, func_021C6F30, func_021C701C, func_021C7058, func_021C7094, func_021C70DC, func_021C71A4, func_021C71D4, func_021C7220, func_021C7260, func_021C72AC, func_021C72F8, func_021C734C, func_021C73B4, func_021C7418, func_021C748C, func_021C7500, func_021C754C, func_021C7584, func_021C7684, func_021C76C4, func_021C7730, func_021C77D8, func_021C7814, func_021C7844, func_021C7858, func_021C7878, func_021C78DC, func_021C7940, func_021C7A20, func_021C7A7C, func_021C7AE4, func_021C7B1C, func_021C7C10, func_021C7C74, func_021C7D28, func_021C7D78, func_021C7DAC, func_021C7DE0, func_021C7DFC, func_021C7E30, func_021C7E50, func_021C7E54, func_021C7E58, func_021C7E64, func_021C7E70, func_021C7E90, func_021C7EEC, func_021C7EF0, func_021C7EF4, func_021C7EF8, func_021C7EFC, func_021C7F18, func_021C7F44, func_021C7F70, func_021C7F9C, func_021C7FAC, func_021C7FB4, func_021C7FBC, func_021C7FC0, func_021C7FF0, func_021C8000, func_021C800C, func_021C8018, func_021C8054, func_021C8078, func_021C812C, func_021C8170, func_021C81B4, func_021C81F8, func_021C8268, func_021C82C4, func_021C85CC, func_021C8608, func_021C8660, func_021C868C, func_021C86E8, func_021C8738
 * address:  0x021C6E5C
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
 *   func_021C6CA8  0x021C6CA8  thumb  ov021
 *   func_021C6CBC  0x021C6CBC  thumb  ov021
 *   func_021C6CC4  0x021C6CC4  thumb  ov021
 *   func_021C6CE0  0x021C6CE0  thumb  ov021
 *   func_021C6CD0  0x021C6CD0  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 *   func_02188C58  0x02188C58  thumb
 *   func_0218ED54  0x0218ED54  thumb
 *   func_0218E138  0x0218E138  thumb
 *   func_0218E13C  0x0218E13C  thumb
 *   func_0218ED58  0x0218ED58  thumb
 *   _fgr           0x0209BBB0  arm
 *   _ffltu         0x0209BE04  arm
 *   _fflt          0x0209BDBC  arm
 *   _ffix          0x0209C494  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _fdiv          0x0209CE10  arm
 *   func_0218ED40  0x0218ED40  thumb  ov021
 *   func_0218ED2C  0x0218ED2C  thumb  ov021
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 *   _ffixu         0x0209C4C8  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   d_021DAAC0  0x021DAAC0  data  ov021  a2
 *   d_021DAAB8  0x021DAAB8  data  ov021  a2
 *   d_021DAAC8     0x021DAAC8  data  ov021  a2
 *   func_0209C5E0  0x0209C5E0  arm
 *   _f2d           0x0209BD38  arm
 *   _d2f           0x0209B64C  arm
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_02164010  0x02164010  thumb  ov010
 *   func_020520A4  0x020520A4  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_021AC528  0x021AC528  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   _ll_mul        0x0209C054  arm
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0218ECC4  0x0218ECC4  thumb  ov021
 *   func_0218ECD4  0x0218ECD4  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0207CEE4  0x0207CEE4  arm
 *   func_021ADD7C  0x021ADD7C  thumb  ov021
 *   d_021DE4FC  0x021DE4FC  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021DAAD0  0x021DAAD0  data  ov021  a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_0207C768  0x0207C768  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021DE50C  0x021DE50C  data  ov021  a4
 *   d_021DE520  0x021DE520  data  ov021  a4
 *   func_02046DB8  0x02046DB8  arm
 *   func_02047400  0x02047400  arm
 *   func_0204767C  0x0204767C  arm
 *   func_02047788  0x02047788  arm
 *   func_02047504  0x02047504  arm
 *   func_02047738  0x02047738  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_02046AFC  0x02046AFC  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0206AAD4  0x0206AAD4  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0204755C  0x0204755C  arm
 *   func_0206E394  0x0206E394  arm
 *   func_0206E4FC  0x0206E4FC  arm
 *   func_0206E484  0x0206E484  arm
 *   func_0206E574  0x0206E574  arm
 *   func_0206E40C  0x0206E40C  arm
 *   func_02047A60  0x02047A60  arm
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A00  0x02189A00  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021C1CB0  0x021C1CB0  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021C1D68  0x021C1D68  thumb  ov021
 *   func_021C30B8  0x021C30B8  thumb  ov021
 *   d_021DAAE0     0x021DAAE0  data  a2
 *   d_021DAAE2     0x021DAAE2  data  a2
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02014204  0x02014204  thumb
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_0218F1AC  0x0218F1AC  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_021BB260  0x021BB260  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218F818  0x0218F818  thumb  ov021
 *   func_0218F848  0x0218F848  thumb  ov021
 *   func_0218F900  0x0218F900  thumb  ov021
 *   func_0218FE50  0x0218FE50  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0218F878  0x0218F878  thumb  ov021
 *   func_021BEA30  0x021BEA30  thumb  ov021
 *   func_021854CC  0x021854CC  thumb  ov020
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC5BC  0x021BC5BC  thumb  ov021
 *   func_02043658  0x02043658  arm
 *   func_02188DA0  0x02188DA0  thumb  ov021
 *   func_02043534  0x02043534  arm
 *   func_02188DB0  0x02188DB0  thumb  ov021
 *   func_021BC578  0x021BC578  thumb  ov021
 *   func_0218F9C4  0x0218F9C4  thumb  ov021
 *   func_0218EC30  0x0218EC30  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_020124E4  0x020124E4  thumb
 *   func_0204E804  0x0204E804  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021F36C0  0x021F36C0  thumb  ov037
 *   d_021DE534     0x021DE534  data  a4
 *   d_00000024     0x00000024  data  a4
 *   func_021C87E0  0x021C87E0  thumb  ov021
 *   func_02158768  0x02158768  thumb  ov010
 */

#define FX_FX32_TO_F32(x) ((f32)((x) / 4096.0f))
#define FX32_ONE 0x1000
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;
typedef signed int s32;
typedef int fx32;
typedef float f32;

typedef struct VecFx32 {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

/* Opaque handles owned by other files. */
typedef struct FieldTask FieldTask;         /* field_task.c: state, work, update function */
typedef struct FieldMap FieldMap;
typedef struct FieldCamera FieldCamera;
typedef struct FieldPlayer FieldPlayer;
typedef struct Mmdl Mmdl;
typedef struct MmdlSys MmdlSys;
typedef struct FieldEffectCtrl FieldEffectCtrl;
typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct ScriptVm ScriptVm;
typedef struct ScrCmdWork ScrCmdWork;
typedef struct ScriptSystem ScriptSystem;
typedef struct Fld3dCi Fld3dCi;
typedef struct MyStatus MyStatus;
typedef struct ZoneStartLocation {
    u8 data[0x1C];
} ZoneStartLocation;

/* The task update function receives its work pointer and returns 1 when finished. */
typedef int (*FieldTaskUpdateFunc)();

/* Task list (home: field_task_manager, see "field_task_manager.c" assert string).
 * A slot holds a task and, optionally, the parent task it waits for. */
typedef struct FieldTaskList {
    u8 count;
    u8 pad[3];
    FieldTask **tasks;
    u32 *parents;
} FieldTaskList;

/* Camera distance tween: linear in float from the current distance to the target. */
typedef struct CameraDistanceTween {
    FieldMap *fieldMap;
    u8 state;
    u8 pad5;
    u16 frame;
    u16 frames;
    u16 padA;
    fx32 startDistance;
    fx32 targetDistance;
} CameraDistanceTween;

enum CameraAngleAxis {
    CAMERA_ANGLE_AXIS_YAW = 0,
    CAMERA_ANGLE_AXIS_PITCH = 1
};

/* Camera angle tween: smoothstep from the current angle to the target angle. */
typedef struct CameraAngleTween {
    FieldMap *fieldMap;
    FieldCamera *camera;
    u32 axis;
    u8 state;
    u8 padD;
    u16 frame;
    u16 frames;
    u16 pad12;
    u32 from;
    u32 to;
} CameraAngleTween;

/* Spin task: turns a field model through its four facing animations. */
typedef struct MmdlSpinTask {
    FieldMap *fieldMap;
    Mmdl *mmdl;
    u16 frame;
    u16 frames;
    u8 spins;
    u8 padD;
    u16 endDirection;
} MmdlSpinTask;

typedef struct SpinAcmdTable {
    u16 acmd[4];
} SpinAcmdTable;

/* Linear tween of a position between two points (player or camera target). */
typedef struct PosTween {
    u8 state;
    u8 pad1[3];
    FieldMap *fieldMap;
    int frame;
    int frames;
    VecFx32 from;
    VecFx32 to;
} PosTween;

/* Player drop task: draw offset falls from a height to the ground. */
typedef struct PlayerDropTask {
    u8 state;
    FieldMap *fieldMap;
    u16 frame;
    u16 frames;
    float height;
    Mmdl *mmdl;
} PlayerDropTask;

typedef struct WaitTask {
    u16 frame;
    u16 frames;
} WaitTask;

typedef struct FadeTask {
    FieldMap *fieldMap;
    u32 fadeMode;
    u32 startBrightness;
    u32 endBrightness;
    u32 wait;
} FadeTask;

/* Field model offset tween (draw offset or position offset). */
typedef struct MmdlOffsetTween {
    u8 state;
    u8 pad1[3];
    FieldMap *fieldMap;
    int reverse;
    u16 frame;
    u16 frames;
    VecFx32 offset;
    VecFx32 startPos;
    Mmdl *mmdl;
} MmdlOffsetTween;

/* Camera target linear interpolation. */
typedef struct CameraLerpTask {
    u8 state;
    u8 pad1[3];
    FieldMap *fieldMap;
    u16 frame;
    u16 frames;
    VecFx32 start;
    VecFx32 end;
    VecFx32 delta;
    int savedFlag;
} CameraLerpTask;

/* Calls a player effect every `interval` frames for `frames` frames. */
typedef struct RepeatEffectTask {
    FieldMap *fieldMap;
    FieldEffectCtrl *effectCtrl;
    Mmdl *mmdl;
    u8 state;
    u8 padD;
    u16 frame;
    u16 frames;
    u16 interval;
} RepeatEffectTask;

/* FIELD_FLASH: the cave flash light. A tween drives the size and alpha of the mask model. */
typedef struct FlashTween {
    fx32 size;
    u8 alpha;
    u8 pad5;
    u16 frame;
    u16 frames;
    u8 padA[2];
    fx32 sizeStart;
    fx32 sizeDelta;
    s16 alphaStart;
    s16 alphaDelta;
} FlashTween;

typedef struct FldWipe3dObj FldWipe3dObj;

typedef struct FieldFlash {
    FldWipe3dObj *model;
    FlashTween tween;
    u16 state;
    u16 pendingCommand;
} FieldFlash;

enum FlashState {
    FLASH_STATE_OFF = 0,
    FLASH_STATE_READY = 1,
    FLASH_STATE_EXPANDING = 2,
    FLASH_STATE_EXPANDED = 3
};

enum FlashCommand {
    FLASH_CMD_INIT = 0,
    FLASH_CMD_EXPAND = 1,
    FLASH_CMD_SHOW_EXPANDED = 2,
    FLASH_CMD_HIDE = 3,
    FLASH_CMD_NONE = 4
};

/* FIELDSKILL_MAPEFF: holds the map effects a field skill can add; only the flash so far. */
typedef struct FieldSkillMapEff {
    FieldFlash *flash;
} FieldSkillMapEff;

/* FLD_WIPE_3DOBJ: resource archive and object of the flash mask model. */
struct FldWipe3dObj {
    void *resArc;
    void *object;
};

typedef struct G3dLookAt {
    VecFx32 camPos;
    VecFx32 camUp;
    VecFx32 target;
} G3dLookAt; /* same layout as G3dLookAt in arm9/g3d_system_types.h */

typedef struct Mtx33 {
    int m[9];
} Mtx33;

typedef struct Mtx43 {
    int m[12];
} Mtx43;

typedef struct G3dObjectStatus {
    VecFx32 trans;
    VecFx32 scale;
    Mtx33 rotate;
} G3dObjectStatus; /* same layout as G3dObjectStatus in arm9/g3d_system_types.h */

typedef struct G3dRenderRef {
    int magic;
    void *rndObj;
} G3dRenderRef;

/* Wipe event work (wipe with a 3D cut-in and a map change). */
typedef struct CameraAnimFlags {
    u32 apply[6];
} CameraAnimFlags;

typedef struct CameraAnimParam {
    u32 padding0[3];
    VecFx32 targetPos;
    VecFx32 targetOffset;
    u16 pitch;
    u16 yaw;
    u32 distance;
    u16 fovy;
    u16 pad2E;
    CameraAnimFlags flags;
} CameraAnimParam;

typedef struct WipeMapChangeWork {
    GameSystem *gameSystem;
    u32 savedCameraBits;
    u32 zoneId;
    ZoneStartLocation startLocation;
    u32 cutInIdBefore;
    u32 cutInIdAfter;
} WipeMapChangeWork;

/* PLEASURE_BOAT work (0x1B8). */
typedef struct BoatPassenger {
    u8 info[0x18];
    int occupied;
} BoatPassenger;

typedef struct PleasureBoatWork {
    int eventPending;
    short timeTicks;
    u16 visitorCount;
    int periodCount;
    BoatPassenger passengers[15];
    u8 groupCount[4];
    int locked;
} PleasureBoatWork;

extern void func_021C6CA8(FieldTask *task);
extern void func_021C6CBC(FieldTask *task);
extern u32 func_021C6CE0(FieldTask *task);
extern void func_021C6CC4(FieldTask *task);
extern int func_021C6CD0(FieldTask *task);
extern u16 func_02188C84(FieldMap *fieldMap);
extern FieldTask *func_021C6C70(u32 heapId, u32 size, FieldTaskUpdateFunc update);
extern void *func_021C6CCC(FieldTask *task);
extern FieldCamera *func_02188C58(FieldMap *fieldMap);
extern fx32 func_0218ED54(FieldCamera *camera);
extern u32 func_0218E138(FieldCamera *camera);
extern void func_0218E13C(FieldCamera *camera, u32 value);
extern void func_0218ED58(FieldCamera *camera, fx32 distance);
extern u16 func_0218ED40(FieldCamera *camera);
extern u16 func_0218ED2C(FieldCamera *camera);
extern void func_0218ED34(FieldCamera *camera, u16 angle);
extern void func_0218ED48(FieldCamera *camera, u16 angle);
extern FieldPlayer *func_02188CB4(FieldMap *fieldMap);
extern Mmdl *func_021A3074(FieldPlayer *player);
extern u16 func_0216D5F8(Mmdl *mmdl);
extern double func_0209C5E0(double x);
extern void func_0216D410(Mmdl *mmdl, int acmd);
extern void func_0216D5E0(Mmdl *mmdl, int direction);
extern void func_021A3038(FieldPlayer *player, VecFx32 *pos);
extern void func_021A3044(FieldPlayer *player, VecFx32 *pos);
extern int func_02164010(Mmdl *mmdl);
extern void func_020520A4(const VecFx32 *v, int scale, VecFx32 *out);
extern void func_0207C9D0(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern FieldEffectCtrl *func_02188CD0(FieldMap *fieldMap);
extern void func_0216D8C0(Mmdl *mmdl, VecFx32 *offset);
extern void func_021AC528(Mmdl *mmdl, FieldEffectCtrl *effectCtrl);
extern void func_020061E4(u32 seId);
extern void func_0204E720(u32 mode, u32 start, u32 end, u32 wait);
extern void func_0216D88C(const Mmdl *mmdl, VecFx32 *pos);
extern void func_0216D89C(Mmdl *mmdl, VecFx32 *pos);
extern void func_0218ECC4(FieldCamera *camera, VecFx32 *out);
extern void func_0218ECD4(FieldCamera *camera, VecFx32 *v);
extern void func_0207CA00(VecFx32 *a, VecFx32 *b, VecFx32 *out);
extern void func_0218EC90(FieldCamera *camera, VecFx32 *v);
extern void func_0207CEE4(int t, VecFx32 *a, VecFx32 *b, VecFx32 *out);
extern void func_021ADD7C(Mmdl *mmdl, FieldEffectCtrl *effectCtrl);
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *dst, int value, int size);
extern u32 func_0207C768(u32 a, u32 b);
extern void *func_02046DB8(u32 arcId, u32 mode);
extern void *func_02047400(void *resArc, u32 index, void *param);
extern void *func_0204767C(void *render, u32 *anime, int count);
extern void func_02046EFC(void *resArc);
extern void func_02047504(void *render);
extern void func_02047738(void *object);
extern void *func_02047788(void *object);
extern void func_02046AFC(G3dLookAt *dst);
extern void func_0207CCA4(VecFx32 *src, VecFx32 *dst);
extern u32 *func_0206AAD4(void);
extern void func_02082B60(Mtx43 *src, Mtx33 *dst);
extern G3dRenderRef *func_0204755C(void *render);
extern void func_0206E394(void *mdl, int a, int b);
extern void func_0206E4FC(void *mdl, int a, int b);
extern void func_0206E484(void *mdl, int a, int b);
extern void func_0206E574(void *mdl, int a, int b);
extern void func_0206E40C(void *mdl, int a, int b);
extern void func_02047A60(void *object, G3dObjectStatus *status);
extern GameSystem *func_0215A5DC(ScrCmdWork *work);
extern FieldMap *func_0201210C(GameSystem *gameSystem);
extern Fld3dCi *func_02189A00(FieldMap *fieldMap);
extern u16 func_02011330(ScriptVm *vm);
extern ScriptSystem *func_0215A5F4(ScrCmdWork *work);
extern GameEvent *func_021C1CB0(GameSystem *gameSystem, Fld3dCi *ci, int id);
extern void func_0215897C(ScriptSystem *scriptSys, GameEvent *event);
extern unsigned int func_02159B10(ScriptVm *vm, ScrCmdWork *work);
extern GameEvent *func_021C1D68(GameSystem *gameSystem, Fld3dCi *ci, int value);
extern GameEvent *func_021C30B8(GameSystem *gameSystem, Fld3dCi *ci, unsigned int value);
extern GameEvent *func_020122C0(GameSystem *gameSystem, GameEvent *parent, int (*main)(), unsigned int workSize);
extern void *func_020124E8(GameEvent *event);
extern void *func_020120F4(GameSystem *gameSystem);
extern MyStatus *func_02012944(void *gameData);
extern u8 func_02008550(const MyStatus *myStatus);
extern void func_02014204(ZoneStartLocation *location, int zoneId);
extern u32 func_02188C5C(FieldMap *fieldMap);
extern void func_0218F1AC(FieldCamera *camera, u32 value);
extern u32 func_0218EC5C(FieldCamera *camera);
extern void func_0218F0A8(FieldCamera *camera);
extern u32 func_0218F0E8(FieldCamera *camera);
extern void func_021BB260(u32 bg, u32 value);
extern void func_0218EC54(FieldCamera *camera);
extern void func_0218F818(FieldCamera *camera);
extern void func_0218F848(FieldCamera *camera);
extern void func_0218F900(FieldCamera *camera, CameraAnimParam *param, int frames);
extern int func_0218FE50(FieldCamera *camera);
extern MmdlSys *func_02188C7C(FieldMap *fieldMap);
extern void func_0216D9A0(MmdlSys *mmdlSys);
extern void func_02012374(GameEvent *parent, GameEvent *child);
extern u32 *func_0216D9E4(MmdlSys *mmdlSys);
extern void func_0216DAC8(Mmdl *mmdl, unsigned int vanish);
extern void func_0218F878(FieldCamera *camera);
extern GameEvent *func_021BEA30(GameSystem *gameSystem, FieldMap *fieldMap, u32 a, u32 b);
extern GameEvent *func_021854CC(GameSystem *gameSystem, FieldMap *fieldMap, u16 zoneId, ZoneStartLocation *location, u16 flag);
extern void *func_02188D20(FieldMap *fieldMap);
extern int func_021BC5BC(void *msgBg);
extern u32 func_02043658(void);
extern void func_02188DA0(void);
extern void func_02043534(u32 planes);
extern void func_02188DB0(FieldMap *fieldMap);
extern void func_021BC578(void *msgBg, int zoneId);
extern void func_0218F9C4(FieldCamera *camera, CameraAnimFlags *flags, u16 frames);
extern void func_0218EC30(FieldCamera *camera, u32 bits);
extern void func_0218F05C(FieldCamera *camera);
extern GameSystem *func_020124E4(GameEvent *event);
extern int func_0204E804(void);
extern int func_02034AC4(s32 overlayId);
extern void func_02034A5C(int overlayId);
extern void func_021F36C0(PleasureBoatWork *work);
extern int func_021C87E0(PleasureBoatWork *work);
extern GameEvent *func_02158768(GameSystem *gameSystem, int a, int b, int scriptId);

/* Spin acmd tables (u16 per facing direction) and the FLD3D_CI id table (key, id pairs). */
extern SpinAcmdTable d_021DAAC0;
extern SpinAcmdTable d_021DAAB8;
extern SpinAcmdTable d_021DAAC8;
extern char d_021DE4FC[];
extern char d_021DE50C[];
extern char d_021DE520[];
extern unsigned short d_021DAAE0[];
extern unsigned short d_021DAAE2[];
extern char d_021DE534;
extern char d_00000024[];
extern void (*d_021DAAD0[])(FieldFlash *flash);

void func_021C6E5C(FieldTaskList *list, int slot, FieldTask *task, u32 parent);
void func_021C6E74(FieldTaskList *list, int slot);
void func_021C6E94(FieldTaskList *list, int slot);
void func_021C6EA8(FieldTaskList *list, int slot);
void func_021C6EDC(FieldTaskList *list, int slot);
FieldTask *func_021C6F00(FieldMap *fieldMap, u16 frames, fx32 targetDistance);
int func_021C6F30(CameraDistanceTween *tween);
FieldTask *func_021C701C(FieldMap *fieldMap, u16 frames, u32 targetAngle);
FieldTask *func_021C7058(FieldMap *fieldMap, u16 frames, u32 targetAngle);
void func_021C7094(CameraAngleTween *tween);
void func_021C70DC(CameraAngleTween *tween);
int func_021C71A4(CameraAngleTween *tween);
FieldTask *func_021C71D4(FieldMap *fieldMap, u32 frames, u32 spins);
FieldTask *func_021C7220(FieldMap *fieldMap, u16 frames, int spins, Mmdl *mmdl);
FieldTask *func_021C7260(FieldMap *fieldMap, u16 frames, int spins);
FieldTask *func_021C72AC(FieldMap *fieldMap, u16 frames, int spins, int endDirection);
u16 func_021C72F8(float frame, float frames, float spins);
u16 func_021C734C(float frame, float frames, float spins);
u16 func_021C73B4(float frame, float frames, float spins);
int func_021C7418(MmdlSpinTask *task);
int func_021C748C(MmdlSpinTask *task);
int func_021C7500(MmdlSpinTask *task);
FieldTask *func_021C754C(FieldMap *fieldMap, u32 frames, VecFx32 *to);
int func_021C7584(PosTween *tween);
FieldTask *func_021C7684(FieldMap *fieldMap, Mmdl *mmdl, int frames, int height);
void func_021C76C4(VecFx32 *out, float frame, float frames, float height);
int func_021C7730(PlayerDropTask *task);
FieldTask *func_021C77D8(FieldMap *fieldMap, u16 frames);
int func_021C77FC(WaitTask *task);
FieldTask *func_021C7814(FieldMap *fieldMap, u32 fadeMode, u32 startBrightness, u32 endBrightness, u32 wait);
int func_021C7844(FadeTask *task);
FieldTask *func_021C7858(FieldMap *fieldMap, int frames, const VecFx32 *offset);
FieldTask *func_021C7878(FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl);
FieldTask *func_021C78DC(FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl);
void func_021C7940(VecFx32 *out, u16 frame, VecFx32 *offset, u16 frames);
int func_021C7A20(MmdlOffsetTween *tween);
int func_021C7A7C(MmdlOffsetTween *tween);
FieldTask *func_021C7AE4(FieldMap *fieldMap, u32 frames, const VecFx32 *to);
int func_021C7B1C(PosTween *tween);
FieldTask *func_021C7C10(FieldMap *fieldMap, int frames, const VecFx32 *start, const VecFx32 *end);
int func_021C7C74(CameraLerpTask *task);
FieldTask *func_021C7D28(FieldMap *fieldMap, int unused, u16 frames, u16 interval);
int func_021C7D78(RepeatEffectTask *task);
FieldFlash *func_021C7DAC(u32 heapId);
void func_021C7DE0(FieldFlash *flash);
void func_021C7DFC(FieldFlash *flash);
void func_021C7E30(FieldFlash *flash);
void func_021C7E50(FieldFlash *flash, u16 command);
u16 func_021C7E54(FieldFlash *flash);
void func_021C7E58(FlashTween *tween);
void func_021C7E64(FlashTween *tween);
FlashTween *func_021C7E70(FlashTween *tween, fx32 sizeStart, fx32 sizeEnd, u32 alphaStart, u8 alphaEnd, u32 frames);
int func_021C7E90(FlashTween *tween);
u32 func_021C7EEC(FlashTween *tween);
void func_021C7EF0(FlashTween *tween, fx32 size);
u8 func_021C7EF4(FlashTween *tween);
FlashTween *func_021C7EF8(FlashTween *tween, u8 alpha);
void func_021C7EFC(FieldFlash *flash);
void func_021C7F18(FieldFlash *flash);
void func_021C7F44(FieldFlash *flash);
void func_021C7F60(FieldFlash *flash);
FieldSkillMapEff *func_021C7F70(u32 flags, u32 heapId);
void func_021C7F9C(FieldSkillMapEff *mapEff);
void func_021C7FAC(FieldSkillMapEff *mapEff);
void func_021C7FB4(FieldSkillMapEff *mapEff);
FieldFlash *func_021C7FBC(FieldSkillMapEff *mapEff);
void func_021C7FC0(FieldSkillMapEff *mapEff, u32 flags, u32 heapId);
void func_021C7FF0(FieldSkillMapEff *mapEff);
void func_021C8000(FieldSkillMapEff *mapEff);
void func_021C800C(FieldSkillMapEff *mapEff);
FldWipe3dObj *func_021C8018(u32 heapId);
int func_021C8054(FldWipe3dObj *obj);
void func_021C8078(FldWipe3dObj *obj, int size, int alpha);
int func_021C812C(ScriptVm *vm, ScrCmdWork *work);
int func_021C8170(ScriptVm *vm, ScrCmdWork *work);
int func_021C81B4(ScriptVm *vm, ScrCmdWork *work);
int func_021C81F8(ScriptVm *vm, ScrCmdWork *work);
GameEvent *func_021C8268(GameSystem *gameSystem, int unused, int zoneId);
int func_021C82C4(GameEvent *event, int *seq, WipeMapChangeWork *work);
int func_021C85CC(GameEvent *event, int *seq);
PleasureBoatWork *func_021C8608(void);
void func_021C8660(PleasureBoatWork *work);
GameEvent *func_021C868C(GameSystem *gameSystem, PleasureBoatWork *work);
void func_021C86E8(PleasureBoatWork *work, int seconds, int clamp);
int func_021C8738(PleasureBoatWork *work, int kind);

void func_021C6E5C(FieldTaskList *list, int slot, FieldTask *task, u32 parent)
{
    if (list->tasks[slot] == 0) {
        list->tasks[slot] = task;
        list->parents[slot] = parent;
    }
}

void func_021C6E74(FieldTaskList *list, int slot)
{
    if (list->tasks[slot] != 0) {
        func_021C6CA8(list->tasks[slot]);
        list->tasks[slot] = 0;
        list->parents[slot] = 0;
    }
}

void func_021C6E94(FieldTaskList *list, int slot)
{
    if (list->tasks[slot] != 0)
        func_021C6CBC(list->tasks[slot]);
}

void func_021C6EA8(FieldTaskList *list, int slot)
{
    if (list->tasks[slot] != 0 && list->parents[slot] != 0) {
        if (func_021C6CE0(list->tasks[slot]) == 0 && func_021C6CE0((FieldTask *)list->parents[slot]) == 2)
            func_021C6CC4(list->tasks[slot]);
    }
}

void func_021C6EDC(FieldTaskList *list, int slot)
{
    if (list->tasks[slot] != 0 && func_021C6CD0(list->tasks[slot]) == 1)
        func_021C6E74(list, slot);
}

FieldTask *func_021C6F00(FieldMap *fieldMap, u16 frames, fx32 targetDistance)
{
    FieldTask *task = func_021C6C70(func_02188C84(fieldMap), 0x14, func_021C6F30);
    CameraDistanceTween *tween = (CameraDistanceTween *)func_021C6CCC(task);
    tween->state = 0;
    tween->fieldMap = fieldMap;
    tween->frame = 0;
    tween->frames = frames;
    tween->targetDistance = targetDistance;
    return task;
}

int func_021C6F30(CameraDistanceTween *tween)
{
    FieldCamera *camera;
    u32 savedBits;
    f32 t;
    f32 start;
    f32 target;
    f32 distance;
    camera = func_02188C58(tween->fieldMap);
    switch (tween->state) {
    case 0:
        tween->startDistance = func_0218ED54(camera);
        tween->state++;
        break;
    case 1:
        tween->frame++;
        savedBits = func_0218E138(camera);
        func_0218E13C(camera, 0);
        t = (f32)tween->frame / (f32)tween->frames;
        start = FX_FX32_TO_F32(tween->startDistance);
        target = FX_FX32_TO_F32(tween->targetDistance);
        distance = (1.0f - t) * start + t * target;
        func_0218ED58(camera, FX_F32_TO_FX32(distance));
        func_0218E13C(camera, savedBits);
        if (tween->frames <= tween->frame)
            return 1;
        break;
    }
    return 0;
}

FieldTask *func_021C701C(FieldMap *fieldMap, u16 frames, u32 targetAngle)
{
    FieldTask *task = func_021C6C70(func_02188C84(fieldMap), 0x1c, func_021C71A4);
    CameraAngleTween *tween = (CameraAngleTween *)func_021C6CCC(task);
    tween->fieldMap = fieldMap;
    tween->camera = func_02188C58(fieldMap);
    tween->state = 0;
    tween->axis = CAMERA_ANGLE_AXIS_YAW;
    tween->frame = 0;
    tween->frames = frames;
    tween->to = targetAngle;
    return task;
}

FieldTask *func_021C7058(FieldMap *fieldMap, u16 frames, u32 targetAngle)
{
    FieldTask *task = func_021C6C70(func_02188C84(fieldMap), 0x1c, func_021C71A4);
    CameraAngleTween *tween = (CameraAngleTween *)func_021C6CCC(task);
    tween->fieldMap = fieldMap;
    tween->camera = func_02188C58(fieldMap);
    tween->state = 0;
    tween->axis = CAMERA_ANGLE_AXIS_PITCH;
    tween->frame = 0;
    tween->frames = frames;
    tween->to = targetAngle;
    return task;
}

/* Reads the current angle and moves the target by a full turn when the short way round crosses the wrap. */
void func_021C7094(CameraAngleTween *tween)
{
    u32 axis = tween->axis;
    u32 from = (u32)tween->camera;
    u32 to = tween->to;
    u32 diff;
    if (axis == 0 || axis != 1)
        from = func_0218ED40((FieldCamera *)from);
    else
        from = func_0218ED2C((FieldCamera *)from);
    if (from < to) {
        diff = to - from;
        if (diff > 0x8000)
            from += 0x10000;
    } else if (to < from) {
        diff = from - to;
        if (diff > 0x8000)
            to += 0x10000;
    }
    tween->from = from;
    tween->to = to;
}

void func_021C70DC(CameraAngleTween *tween)
{
    u16 frames;
    FieldCamera *camera;
    f32 t;
    f32 s;
    u16 angle;
    u32 savedBits;
    frames = tween->frames;
    camera = tween->camera;
    tween->frame++;
    if (tween->frame > frames)
        return;
    t = (f32)tween->frame / (f32)frames;
    s = (3.0f + -2.0f * t) * (t * t);
    angle = (u16)((1.0f - s) * (f32)tween->from + s * (f32)tween->to);
    savedBits = func_0218E138(camera);
    func_0218E13C(camera, 0);
    switch (tween->axis) {
    case CAMERA_ANGLE_AXIS_YAW:
        func_0218ED48(camera, angle);
        break;
    case CAMERA_ANGLE_AXIS_PITCH:
        func_0218ED34(camera, angle);
        break;
    }
    func_0218E13C(camera, savedBits);
}

int func_021C71A4(CameraAngleTween *tween)
{
    switch (tween->state) {
    case 0:
        func_021C7094(tween);
        tween->state++;
        break;
    case 1:
        func_021C70DC(tween);
        if (tween->frames <= tween->frame)
            return 1;
        break;
    }
    return 0;
}

/* Spin the player: linear rate of turn. */
FieldTask *func_021C71D4(FieldMap *fieldMap, u32 frames, u32 spins)
{
    u32 heapId = func_02188C84(fieldMap);
    FieldPlayer *player = func_02188CB4(fieldMap);
    FieldTask *task = func_021C6C70(heapId, 0x10, func_021C7418);
    MmdlSpinTask *spin = (MmdlSpinTask *)func_021C6CCC(task);
    Mmdl *mmdl;
    spin->fieldMap = fieldMap;
    mmdl = func_021A3074(player);
    spin->mmdl = mmdl;
    spin->frame = 0;
    spin->frames = frames;
    spin->spins = spins;
    spin->endDirection = func_0216D5F8(mmdl);
    return task;
}

/* Spin the given model: linear rate of turn. */
FieldTask *func_021C7220(FieldMap *fieldMap, u16 frames, int spins, Mmdl *mmdl)
{
    FieldTask *task;
    MmdlSpinTask *spin;
    task = func_021C6C70(func_02188C84(fieldMap), 0x10, func_021C7418);
    spin = (MmdlSpinTask *)func_021C6CCC(task);
    spin->fieldMap = fieldMap;
    spin->mmdl = mmdl;
    spin->frame = 0;
    spin->frames = frames;
    spin->spins = spins;
    spin->endDirection = func_0216D5F8(mmdl);
    return task;
}

/* Spin the player: rate of turn grows (ease in). */
FieldTask *func_021C7260(FieldMap *fieldMap, u16 frames, int spins)
{
    FieldTask *task;
    MmdlSpinTask *spin;
    u32 heapId;
    FieldPlayer *player;
    Mmdl *mmdl;
    heapId = func_02188C84(fieldMap);
    player = func_02188CB4(fieldMap);
    task = func_021C6C70(heapId, 0x10, func_021C748C);
    spin = (MmdlSpinTask *)func_021C6CCC(task);
    spin->fieldMap = fieldMap;
    mmdl = func_021A3074(player);
    spin->mmdl = mmdl;
    spin->frame = 0;
    spin->frames = frames;
    spin->spins = spins;
    spin->endDirection = func_0216D5F8(mmdl);
    return task;
}

/* Spin the player: rate of turn drops (ease out); ends facing endDirection. */
FieldTask *func_021C72AC(FieldMap *fieldMap, u16 frames, int spins, int endDirection)
{
    FieldTask *task;
    MmdlSpinTask *spin;
    u32 heapId;
    FieldPlayer *player;
    heapId = func_02188C84(fieldMap);
    player = func_02188CB4(fieldMap);
    task = func_021C6C70(heapId, 0x10, func_021C7500);
    spin = (MmdlSpinTask *)func_021C6CCC(task);
    spin->fieldMap = fieldMap;
    spin->mmdl = func_021A3074(player);
    spin->frame = 0;
    spin->frames = frames;
    spin->spins = spins;
    spin->endDirection = endDirection;
    return task;
}

/*
 * Picks one of four halfwords from a table by (int)(4*c/b*a) % 4, in soft float.
 * The last multiply keeps its operand order only through a named float local;
 * inline it and the compiler swaps to a * f.
 */
u16 func_021C72F8(float frame, float frames, float spins)
{
    SpinAcmdTable table = d_021DAAC0;
    float turnsPerFrame = 4.0f * spins / frames;
    int index = (int)(turnsPerFrame * frame);
    return table.acmd[index % 4];
}

u16 func_021C734C(float frame, float frames, float spins)
{
    SpinAcmdTable table = d_021DAAB8;
    float turnsPerFrame = 4.0f * spins / (frames * frames);
    float turns = turnsPerFrame * frame;
    int index = (int)(frame * turns);
    return table.acmd[index % 4];
}

u16 func_021C73B4(float frame, float frames, float spins)
{
    SpinAcmdTable table = d_021DAAC8;
    float fullTurns = 4.0f * spins;
    float rate = fullTurns * fullTurns / frames;
    int index = (int)(float)func_0209C5E0((double)(rate * frame));
    return table.acmd[index % 4];
}

int func_021C7418(MmdlSpinTask *task)
{
    Mmdl *mmdl;
    int acmd;
    mmdl = task->mmdl;
    func_0216D410(mmdl, func_021C72F8((float)(u32)task->frame, (float)(u32)task->frames, (float)(u32)task->spins));
    task->frame = task->frame + 1;
    if (task->frames < task->frame) {
        switch (task->endDirection) {
        default:
        case 0: acmd = 0; break;
        case 1: acmd = 1; break;
        case 2: acmd = 2; break;
        case 3: acmd = 3; break;
        }
        func_0216D410(mmdl, acmd);
        return 1;
    }
    return 0;
}

int func_021C748C(MmdlSpinTask *task)
{
    Mmdl *mmdl;
    int acmd;
    mmdl = task->mmdl;
    func_0216D410(mmdl, func_021C734C((float)(u32)task->frame, (float)(u32)task->frames, (float)(u32)task->spins));
    task->frame = task->frame + 1;
    if (task->frames < task->frame) {
        switch (task->endDirection) {
        default:
        case 0: acmd = 0; break;
        case 1: acmd = 1; break;
        case 2: acmd = 2; break;
        case 3: acmd = 3; break;
        }
        func_0216D410(mmdl, acmd);
        return 1;
    }
    return 0;
}

int func_021C7500(MmdlSpinTask *task)
{
    Mmdl *mmdl;
    mmdl = task->mmdl;
    func_0216D410(mmdl, func_021C73B4((float)(u32)task->frame, (float)(u32)task->frames, (float)(u32)task->spins));
    task->frame = task->frame + 1;
    if (task->frames < task->frame) {
        func_0216D5E0(mmdl, task->endDirection);
        return 1;
    }
    return 0;
}

/* The inline setter evaluates its arguments right to left, which puts y in r1 and z in r2
 * (three plain field copies swap them; a struct assignment is ldm/stm). */
static inline void setVec(VecFx32 *dst, int x, int y, int z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

/* Tween the player position to a point. */
FieldTask *func_021C754C(FieldMap *fieldMap, u32 frames, VecFx32 *to)
{
    FieldTask *task = func_021C6C70(func_02188C84(fieldMap), 0x28, func_021C7584);
    PosTween *tween = (PosTween *)func_021C6CCC(task);
    tween->state = 0;
    tween->fieldMap = fieldMap;
    tween->frame = 0;
    tween->frames = frames;
    setVec(&tween->to, to->x, to->y, to->z);
    return task;
}

int func_021C7584(PosTween *tween)
{
    FieldPlayer *player;
    Mmdl *mmdl;
    fx32 t;
    VecFx32 fromPart;
    VecFx32 toPart;
    VecFx32 pos;
    player = func_02188CB4(tween->fieldMap);
    mmdl = func_021A3074(player);
    switch (tween->state) {
    case 0:
        func_021A3038(player, &tween->from);
        tween->state++;
        break;
    case 1:
        tween->frame++;
        t = FX_F32_TO_FX32((f32)tween->frame / (f32)tween->frames);
        func_020520A4(&tween->from, FX32_ONE - t, &fromPart);
        func_020520A4(&tween->to, t, &toPart);
        func_0207C9D0(&fromPart, &toPart, &pos);
        func_021A3044(player, &pos);
        func_02164010(mmdl);
        if (tween->frames <= tween->frame)
            return 1;
        break;
    }
    return 0;
}

/* Player drop: the draw offset falls from `height` to the ground. */
FieldTask *func_021C7684(FieldMap *fieldMap, Mmdl *mmdl, int frames, int height)
{
    FieldTask *task;
    PlayerDropTask *drop;
    task = func_021C6C70(func_02188C84(fieldMap), 0x14, func_021C7730);
    drop = (PlayerDropTask *)func_021C6CCC(task);
    drop->state = 0;
    drop->fieldMap = fieldMap;
    drop->frame = 0;
    drop->frames = frames;
    drop->height = (float)height;
    drop->mmdl = mmdl;
    return task;
}

#undef FX_F32_TO_FX32
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))
/* Draw offset y of a falling model: height * (1 - (frame / frames)^2). */
void func_021C76C4(VecFx32 *out, float frame, float frames, float height)
{
    float rate = height / (frames * frames);
    float drop = rate * frame;
    float offsetY = height - frame * drop;
    out->x = 0;
    out->y = FX_F32_TO_FX32(offsetY);
    out->z = 0;
}

int func_021C7730(PlayerDropTask *task)
{
    VecFx32 offset;
    Mmdl *mmdl;
    func_02188CB4(task->fieldMap);
    mmdl = task->mmdl;
    switch (task->state) {
    case 0:
        func_021C76C4(&offset, (float)(u32)task->frame, (float)(u32)task->frames, task->height);
        func_0216D8C0(mmdl, &offset);
        func_020061E4(0x681);
        task->state = task->state + 1;
        break;
    case 1:
        task->frame = task->frame + 1;
        func_021C76C4(&offset, (float)(u32)task->frame, (float)(u32)task->frames, task->height);
        func_0216D8C0(mmdl, &offset);
        if (task->frames <= task->frame) {
            func_021AC528(mmdl, func_02188CD0(task->fieldMap));
            func_020061E4(0x682);
            return 1;
        }
        break;
    }
    return 0;
}

FieldTask *func_021C77D8(FieldMap *fieldMap, u16 frames)
{
    FieldTask *task = func_021C6C70(func_02188C84(fieldMap), 4, func_021C77FC);
    WaitTask *wait = (WaitTask *)func_021C6CCC(task);
    wait->frame = 0;
    wait->frames = frames;
    return task;
}

int func_021C77FC(WaitTask *task)
{
    task->frame++;
    if (task->frames <= task->frame)
        return 1;
    return 0;
}

FieldTask *func_021C7814(FieldMap *fieldMap, u32 fadeMode, u32 startBrightness, u32 endBrightness, u32 wait)
{
    FieldTask *task = func_021C6C70(func_02188C84(fieldMap), 0x14, func_021C7844);
    FadeTask *fade = (FadeTask *)func_021C6CCC(task);
    fade->fieldMap = fieldMap;
    fade->fadeMode = fadeMode;
    fade->startBrightness = startBrightness;
    fade->endBrightness = endBrightness;
    fade->wait = wait;
    return task;
}

int func_021C7844(FadeTask *task)
{
    func_0204E720(task->fadeMode, task->startBrightness, task->endBrightness, task->wait);
    return 1;
}

FieldTask *func_021C7858(FieldMap *fieldMap, int frames, const VecFx32 *offset)
{
    return func_021C7878(fieldMap, frames, offset, func_021A3074(func_02188CB4(fieldMap)));
}

#undef FX_F32_TO_FX32
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

/* Draw offset of a model slides from zero to `offset` (negative frames: from `offset` back to zero). */
FieldTask *func_021C7878(FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl)
{
    MmdlOffsetTween *tween;
    FieldTask *task;
    task = func_021C6C70(func_02188C84(fieldMap), 0x2c, func_021C7A20);
    tween = (MmdlOffsetTween *)func_021C6CCC(task);
    tween->state = 0;
    tween->fieldMap = fieldMap;
    tween->mmdl = mmdl;
    func_0216D88C(mmdl, &tween->startPos);
    if (frames >= 0) {
        tween->reverse = 0;
        tween->frame = 0;
        tween->frames = frames;
    } else {
        tween->reverse = 1;
        tween->frame = 0;
        tween->frames = -frames;
    }
    setVec(&tween->offset, offset->x, offset->y, offset->z);
    return task;
}

/* Position of a model slides by `offset` from its start position. */
FieldTask *func_021C78DC(FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl)
{
    MmdlOffsetTween *tween;
    FieldTask *task;
    task = func_021C6C70(func_02188C84(fieldMap), 0x2c, func_021C7A7C);
    tween = (MmdlOffsetTween *)func_021C6CCC(task);
    tween->state = 0;
    tween->fieldMap = fieldMap;
    tween->mmdl = mmdl;
    func_0216D88C(mmdl, &tween->startPos);
    if (frames >= 0) {
        tween->reverse = 0;
        tween->frame = 0;
        tween->frames = frames;
    } else {
        tween->reverse = 1;
        tween->frame = 0;
        tween->frames = -frames;
    }
    setVec(&tween->offset, offset->x, offset->y, offset->z);
    return task;
}

/* out = offset * (frame / frames) in fixed point. */
void func_021C7940(VecFx32 *out, u16 frame, VecFx32 *offset, u16 frames)
{
    fx32 t;
    t = FX_F32_TO_FX32((f32)frame / (f32)frames);
    out->x = (fx32)(((long long)offset->x * t + 0x800) >> 12);
    out->y = (fx32)(((long long)offset->y * t + 0x800) >> 12);
    out->z = (fx32)(((long long)offset->z * t + 0x800) >> 12);
}

int func_021C7A20(MmdlOffsetTween *tween)
{
    Mmdl *mmdl = tween->mmdl;
    VecFx32 offset;
    if (tween->state == 0) {
        tween->frame = tween->frame + 1;
        if (tween->reverse == 0) {
            func_021C7940(&offset, tween->frame, &tween->offset, tween->frames);
        } else if (tween->reverse == 1) {
            func_021C7940(&offset, tween->frames - tween->frame, &tween->offset, tween->frames);
        }
        func_0216D8C0(mmdl, &offset);
        if (tween->frames <= tween->frame) {
            return 1;
        }
    }
    return 0;
}

int func_021C7A7C(MmdlOffsetTween *tween)
{
    Mmdl *mmdl = tween->mmdl;
    VecFx32 offset;
    if (tween->state == 0) {
        tween->frame = tween->frame + 1;
        if (tween->reverse == 0) {
            func_021C7940(&offset, tween->frame, &tween->offset, tween->frames);
        } else if (tween->reverse == 1) {
            func_021C7940(&offset, tween->frames - tween->frame, &tween->offset, tween->frames);
        }
        func_0207C9D0(&offset, &tween->startPos, &offset);
        func_0216D89C(mmdl, &offset);
        if (tween->frames <= tween->frame) {
            return 1;
        }
    }
    return 0;
}

/*
 * The source vector is const: the const lets the scheduler hoist each
 * load above the preceding store (ldr x; str frames; ldr y; str x; ...).  The
 * sibling func_021C754C takes a plain pointer and keeps loads after the frames store.
 */
FieldTask *func_021C7AE4(FieldMap *fieldMap, u32 frames, const VecFx32 *to)
{
    FieldTask *task = func_021C6C70(func_02188C84(fieldMap), 0x28, func_021C7B1C);
    PosTween *tween = (PosTween *)func_021C6CCC(task);
    tween->state = 0;
    tween->fieldMap = fieldMap;
    tween->frame = 0;
    tween->frames = frames;
    setVec(&tween->to, to->x, to->y, to->z);
    return task;
}

/* Tween the camera target offset between two points. */
int func_021C7B1C(PosTween *tween)
{
    FieldCamera *camera;
    fx32 t;
    VecFx32 fromPart;
    VecFx32 toPart;
    VecFx32 pos;
    camera = func_02188C58(tween->fieldMap);
    switch (tween->state) {
    case 0:
        func_0218ECC4(camera, &tween->from);
        tween->state++;
        break;
    case 1:
        tween->frame++;
        t = FX_F32_TO_FX32((f32)tween->frame / (f32)tween->frames);
        func_020520A4(&tween->from, FX32_ONE - t, &fromPart);
        func_020520A4(&tween->to, t, &toPart);
        func_0207C9D0(&fromPart, &toPart, &pos);
        func_0218ECD4(camera, &pos);
        if (tween->frames <= tween->frame)
            return 1;
        break;
    }
    return 0;
}

/* Move the camera along a line from `start` to `end`. */
FieldTask *func_021C7C10(FieldMap *fieldMap, int frames, const VecFx32 *start, const VecFx32 *end)
{
    int heapId;
    FieldTask *task;
    CameraLerpTask *lerp;
    heapId = func_02188C84(fieldMap);
    func_02188C58(fieldMap);
    task = func_021C6C70(heapId, 0x34, func_021C7C74);
    lerp = (CameraLerpTask *)func_021C6CCC(task);
    lerp->state = 0;
    lerp->fieldMap = fieldMap;
    lerp->frame = 0;
    lerp->frames = frames;
    lerp->start = *start;
    lerp->end = *end;
    func_0207CA00(&lerp->end, &lerp->start, &lerp->delta);
    return task;
}

int func_021C7C74(CameraLerpTask *task)
{
    FieldCamera *camera;
    int t;
    float progress;
    VecFx32 pos;
    camera = func_02188C58(task->fieldMap);
    switch (task->state) {
    case 0:
        task->savedFlag = func_0218E138(camera);
        func_0218E13C(camera, 0);
        task->state = task->state + 1;
        break;
    case 1:
        task->frame = task->frame + 1;
        progress = (float)(u32)task->frame / (float)(u32)task->frames;
        if (progress > 0.0f) {
            t = (int)(4096.0f * progress + 0.5f);
        } else {
            t = (int)(4096.0f * progress - 0.5f);
        }
        func_0207CEE4(t, &task->delta, &task->start, &pos);
        func_0218EC90(camera, &pos);
        if (task->frames <= task->frame) {
            func_0218E13C(camera, task->savedFlag);
            return 1;
        }
        break;
    }
    return 0;
}

/* Run the player effect every `interval` frames for `frames` frames. */
FieldTask *func_021C7D28(FieldMap *fieldMap, int unused, u16 frames, u16 interval)
{
    int heapId;
    FieldPlayer *player;
    FieldTask *task;
    RepeatEffectTask *effect;
    heapId = func_02188C84(fieldMap);
    player = func_02188CB4(fieldMap);
    task = func_021C6C70(heapId, 0x14, func_021C7D78);
    effect = (RepeatEffectTask *)func_021C6CCC(task);
    effect->fieldMap = fieldMap;
    effect->effectCtrl = func_02188CD0(fieldMap);
    effect->mmdl = func_021A3074(player);
    effect->state = 0;
    effect->frame = 0;
    effect->frames = frames;
    effect->interval = interval;
    return task;
}

int func_021C7D78(RepeatEffectTask *task)
{
    if (task->state == 0) {
        if (task->frame % task->interval == 0)
            func_021ADD7C(task->mmdl, task->effectCtrl);
        if (task->frames <= task->frame++)
            return 1;
    }
    return 0;
}

FieldFlash *func_021C7DAC(u32 heapId)
{
    FieldFlash *flash = func_02030734(heapId, sizeof(FieldFlash), 1, d_021DE4FC, 0x7a);
    flash->model = func_021C8018(heapId);
    flash->state = FLASH_STATE_OFF;
    flash->pendingCommand = FLASH_CMD_NONE;
    func_021C7E58(&flash->tween);
    return flash;
}

void func_021C7DE0(FieldFlash *flash)
{
    if (flash != 0) {
        func_021C7E64(&flash->tween);
        func_021C8054(flash->model);
        func_020307B0(flash);
    }
}

/* Runs a pending command, then steps the tween while it expands. */
void func_021C7DFC(FieldFlash *flash)
{
    if (flash != 0) {
        if (flash->pendingCommand != FLASH_CMD_NONE) {
            d_021DAAD0[flash->pendingCommand](flash);
            flash->pendingCommand = FLASH_CMD_NONE;
        }
        if (flash->state == FLASH_STATE_EXPANDING && func_021C7E90(&flash->tween))
            flash->state = FLASH_STATE_EXPANDED;
    }
}

/* Applies the tween size and alpha to the mask model. */
void func_021C7E30(FieldFlash *flash)
{
    u32 size;
    if (flash != 0) {
        size = func_021C7EEC(&flash->tween);
        func_021C8078(flash->model, size, func_021C7EF4(&flash->tween));
    }
}

void func_021C7E50(FieldFlash *flash, u16 command)
{
    flash->pendingCommand = command;
}

/*
 * Unlabelled leaf accessor (prints as .word in the listing): returns the u16 at +0x1C (func_021C7E50 sets +0x1E).
 * Sole blocker of ov010 func_0215ECBC's MATCH.
 */
u16 func_021C7E54(FieldFlash *flash)
{
    return flash->state;
}

/* Tail-call thunk: pins arguments 2 and 3 to 0 and 24. */
void func_021C7E58(FlashTween *tween)
{
    func_02082BCC(tween, 0, 24);
}

void func_021C7E64(FlashTween *tween)
{
    func_02082BCC(tween, 0, 24);
}

/* Starts a tween of size sizeStart..sizeEnd and alpha alphaStart..alphaEnd over `frames`. */
FlashTween *func_021C7E70(FlashTween *tween, fx32 sizeStart, fx32 sizeEnd, u32 alphaStart, u8 alphaEnd, u32 frames)
{
    tween->size = sizeStart;
    tween->sizeStart = sizeStart;
    tween->sizeDelta = (sizeEnd - sizeStart);
    tween->alpha = alphaStart;
    tween->alphaStart = alphaStart;
    tween->alphaDelta = (alphaEnd - alphaStart);
    tween->frame = 0;
    tween->frames = frames;
    return tween;
}

/* Returns 1 once the tween has run its frames. */
int func_021C7E90(FlashTween *tween)
{
    if (tween->frame < tween->frames) {
        tween->frame = tween->frame + 1;
        tween->size = tween->sizeStart + func_0207C768((int)(((long long)tween->sizeDelta * (tween->frame << 12) + 0x800) >> 12), tween->frames << 12);
        tween->alpha = tween->alphaStart + tween->alphaDelta * tween->frame / tween->frames;
        return 0;
    }
    return 1;
}

u32 func_021C7EEC(FlashTween *tween)
{
    return tween->size;
}

void func_021C7EF0(FlashTween *tween, fx32 size)
{
    tween->size = size;
}

u8 func_021C7EF4(FlashTween *tween)
{
    return tween->alpha;
}

FlashTween *func_021C7EF8(FlashTween *tween, u8 alpha)
{
    tween->alpha = alpha;
    return tween;
}

/* Command 0: small lit area (size 3.0, full alpha). */
void func_021C7EFC(FieldFlash *flash)
{
    flash->state = FLASH_STATE_READY;
    func_021C7EF0(&flash->tween, (3 << 12));
    func_021C7EF8(&flash->tween, 31);
}

/* Command 1: grow the lit area to size 10.6 in 15 frames (flash was just used). */
void func_021C7F18(FieldFlash *flash)
{
    flash->state = FLASH_STATE_EXPANDING;
    func_021C7E70(&flash->tween, 0x3000, 0xaa00, 0x1f, 0x1f, 0xf);
    func_020061E4(0x767);
}

/* Command 2: show the expanded lit area at once (flash was already active). */
void func_021C7F44(FieldFlash *flash)
{
    flash->state = FLASH_STATE_EXPANDED;
    func_021C7EF0(&flash->tween, 0xaa00);
    func_021C7EF8(&flash->tween, 0x1f);
}

/* Command 3: hide the mask. */
void func_021C7F60(FieldFlash *flash)
{
    flash->state = FLASH_STATE_OFF;
    func_021C7EF0(&flash->tween, 0);
}

FieldSkillMapEff *func_021C7F70(u32 flags, u32 heapId)
{
    FieldSkillMapEff *mapEff = func_02030734(heapId, sizeof(FieldSkillMapEff), 1, d_021DE50C, 0x49);
    func_021C7FC0(mapEff, flags, heapId);
    return mapEff;
}

void func_021C7F9C(FieldSkillMapEff *mapEff)
{
    func_021C7FF0(mapEff);
    func_020307B0(mapEff);
}

/* Tail-call thunk: forwards to func_021C8000 with no argument change. */
void func_021C7FAC(FieldSkillMapEff *mapEff)
{
    func_021C8000(mapEff);
}

/* Tail-call thunk: forwards to func_021C800C with no argument change. */
void func_021C7FB4(FieldSkillMapEff *mapEff)
{
    func_021C800C(mapEff);
}

/*
 * Unlabelled leaf accessor (prints as .word in the listing): returns the first word of its argument.
 * Sole blocker of ov010 func_0215ECBC's MATCH.
 */
FieldFlash *func_021C7FBC(FieldSkillMapEff *mapEff)
{
    return mapEff->flash;
}

/* Creates the flash when the map effect mask has bit 0 or 1; bit 1 starts it already expanded. */
void func_021C7FC0(FieldSkillMapEff *mapEff, u32 flags, u32 heapId)
{
    if (flags & 3) {
        mapEff->flash = func_021C7DAC(heapId);
        if (flags & 2)
            func_021C7E50(mapEff->flash, FLASH_CMD_SHOW_EXPANDED);
        else
            func_021C7E50(mapEff->flash, FLASH_CMD_INIT);
    } else {
        mapEff->flash = 0;
    }
}

void func_021C7FF0(FieldSkillMapEff *mapEff)
{
    func_021C7DE0(mapEff->flash);
    mapEff->flash = 0;
}

/* Tail-call thunk: forwards the flash to func_021C7DFC. */
void func_021C8000(FieldSkillMapEff *mapEff)
{
    func_021C7DFC(mapEff->flash);
}

/* Tail-call thunk: forwards the flash to func_021C7E30. */
void func_021C800C(FieldSkillMapEff *mapEff)
{
    func_021C7E30(mapEff->flash);
}

FldWipe3dObj *func_021C8018(u32 heapId)
{
    FldWipe3dObj *obj = func_02030734(heapId, sizeof(FldWipe3dObj), 1, d_021DE520, 0x24);
    obj->resArc = func_02046DB8(0x4a, 0);
    obj->object = func_0204767C(func_02047400(obj->resArc, 0, 0), 0, 0);
    return obj;
}

int func_021C8054(FldWipe3dObj *obj)
{
    func_02047504(func_02047788(obj->object));
    func_02047738(obj->object);
    func_02046EFC(obj->resArc);
    return func_020307B0(obj);
}

/* Draws the mask model as a camera-facing billboard of the given size and alpha. */
void func_021C8078(FldWipe3dObj *obj, int size, int alpha)
{
    G3dObjectStatus status;
    G3dLookAt lookAt;
    VecFx32 viewDir;
    int viewY;
    void *mdl;
    if (size == 0) {
        return;
    }
    func_02046AFC(&lookAt);
    status.trans = lookAt.camPos;
    func_0207CA00(&lookAt.target, &lookAt.camPos, &viewDir);
    func_0207CCA4(&viewDir, &viewDir);
    viewY = viewDir.y;
    if (viewY <= 0) {
        viewY = -viewY;
    }
    status.scale.x = size;
    status.scale.y = (int)(((long long)size * viewY + 0x800) >> 12);
    status.scale.z = 0x4000;
    func_02082B60((Mtx43 *)func_0206AAD4(), &status.rotate);
    mdl = func_0204755C(func_02047788(obj->object))->rndObj;
    func_0206E394(mdl, 0, 0);
    func_0206E4FC(mdl, 0, 0);
    func_0206E484(mdl, 0, 2);
    func_0206E574(mdl, 0, alpha);
    func_0206E40C(mdl, 0, 0);
    func_02047A60(obj->object, &status);
}

/* Script command: start the FLD3D_CI sequence whose id is the next script halfword. */
int func_021C812C(ScriptVm *vm, ScrCmdWork *work)
{
    Fld3dCi *ci;
    int ciId;
    GameSystem *gameSystem;
    ScriptSystem *scriptSys;
    GameEvent *event;
    gameSystem = func_0215A5DC(work);
    ci = func_02189A00(func_0201210C(gameSystem));
    ciId = func_02011330(vm);
    scriptSys = func_0215A5F4(work);
    event = func_021C1CB0(gameSystem, ci, (unsigned char)ciId);
    if (event) {
        func_0215897C(scriptSys, event);
    }
    return 1;
}

/* Script command: start the FLD3D_CI sequence whose id is read from a script value. */
int func_021C8170(ScriptVm *vm, ScrCmdWork *work)
{
    Fld3dCi *ci;
    int ciId;
    GameSystem *gameSystem;
    ScriptSystem *scriptSys;
    GameEvent *event;
    gameSystem = func_0215A5DC(work);
    ci = func_02189A00(func_0201210C(gameSystem));
    ciId = func_02159B10(vm, work);
    scriptSys = func_0215A5F4(work);
    event = func_021C1D68(gameSystem, ci, (unsigned char)ciId);
    if (event) {
        func_0215897C(scriptSys, event);
    }
    return 1;
}

/* Script command: run the FLD3D_CI main function with a script value. */
int func_021C81B4(ScriptVm *vm, ScrCmdWork *work)
{
    Fld3dCi *ci;
    int value;
    GameSystem *gameSystem;
    ScriptSystem *scriptSys;
    GameEvent *event;
    gameSystem = func_0215A5DC(work);
    ci = func_02189A00(func_0201210C(gameSystem));
    value = (int)func_02159B10(vm, work);
    scriptSys = func_0215A5F4(work);
    event = func_021C30B8(gameSystem, ci, value);
    if (event) {
        func_0215897C(scriptSys, event);
    }
    return 1;
}

/* Script command: map a script value through the 17-entry key table to a FLD3D_CI id and start it. */
int func_021C81F8(ScriptVm *vm, ScrCmdWork *work)
{
    GameSystem *gameSystem;
    Fld3dCi *ci;
    int value;
    int found;
    int i;
    ScriptSystem *scriptSys;
    unsigned short ciId;
    GameEvent *event;
    gameSystem = func_0215A5DC(work);
    ci = func_02189A00(func_0201210C(gameSystem));
    value = (int)func_02159B10(vm, work);
    found = 0;
    for (i = 0; i < 17; i++) {
        if (value == d_021DAAE0[i * 2]) {
            found = 1;
            ciId = d_021DAAE2[i * 2];
            break;
        }
    }
    if (found) {
        scriptSys = func_0215A5F4(work);
        event = func_021C1CB0(gameSystem, ci, (unsigned char)ciId);
        if (event) {
            func_0215897C(scriptSys, event);
        }
    }
    return 1;
}

/* Creates the wipe event: picks the two FLD3D_CI ids by player outfit and remembers the destination zone. */
GameEvent *func_021C8268(GameSystem *gameSystem, int unused, int zoneId)
{
    GameEvent *event;
    WipeMapChangeWork *work;
    int cutInIdAfter;
    event = func_020122C0(gameSystem, 0, func_021C82C4, 0x30);
    work = func_020124E8(event);
    func_02082BCC(work, 0, 0x30);
    work->gameSystem = gameSystem;
    work->zoneId = zoneId;
    if (func_02008550(func_02012944(func_020120F4(gameSystem))) == 0) {
        work->cutInIdBefore = 11;
        cutInIdAfter = 12;
    } else {
        work->cutInIdBefore = 18;
        cutInIdAfter = 19;
    }
    work->cutInIdAfter = cutInIdAfter;
    func_02014204(&work->startLocation, (unsigned short)zoneId);
    return event;
}

/* Wipe event: camera swing and FLD3D_CI cut-in, map change, then the reverse cut-in. */
int func_021C82C4(GameEvent *event, int *seq, WipeMapChangeWork *work)
{
    FieldMap *fieldMap;
    FieldCamera *camera;
    Fld3dCi *ci;
    u32 bg;
    GameEvent *child;
    void *msgBg;
    u32 visiblePlanes;
    Mmdl *mmdl;
    CameraAnimParam param1;
    CameraAnimParam param2;
    VecFx32 playerPos1;
    VecFx32 playerPos2;
    CameraAnimFlags flags;
    fieldMap = func_0201210C(work->gameSystem);
    camera = func_02188C58(fieldMap);
    ci = func_02189A00(fieldMap);
    bg = func_02188C5C(fieldMap);
    switch (*seq) {
    case 0:
        func_0218F1AC(camera, 0);
        work->savedCameraBits = func_0218EC5C(camera);
        func_0218F0A8(camera);
        (*seq)++;
        break;
    case 1:
        if (work->savedCameraBits != 0 && func_0218F0E8(camera) != 0)
            break;
        func_021BB260(bg, 0);
        func_0218EC54(camera);
        func_0218F818(camera);
        func_021A3038(func_02188CB4(fieldMap), &playerPos1);
        param1.pitch = 0x25d8;
        param1.yaw = 0;
        param1.distance = 0xed000;
        param1.targetOffset.x = 0;
        param1.targetOffset.y = 0x4000;
        param1.targetOffset.z = 0;
        param1.targetPos = playerPos1;
        param1.fovy = 0xe38;
        param1.flags.apply[0] = 1;
        param1.flags.apply[1] = 1;
        param1.flags.apply[2] = 0;
        param1.flags.apply[3] = 1;
        param1.flags.apply[4] = 1;
        param1.flags.apply[5] = 1;
        func_0218F900(camera, &param1, 10);
        (*seq)++;
    case 2:
        if (func_0218FE50(camera) != 0)
            break;
        func_0216D9A0(func_02188C7C(fieldMap));
        child = func_021C1CB0(work->gameSystem, ci, (u8)work->cutInIdBefore);
        if (child != 0)
            func_02012374(event, child);
        (*seq)++;
        break;
    case 3:
        func_0216D9E4(func_02188C7C(fieldMap));
        func_0216DAC8(func_021A3074(func_02188CB4(fieldMap)), 1);
        func_0218F878(camera);
        func_02012374(event, func_021BEA30(work->gameSystem, fieldMap, 0, 0));
        (*seq)++;
        break;
    case 4:
        func_02012374(event, func_021854CC(work->gameSystem, fieldMap, work->zoneId, &work->startLocation, 1));
        (*seq)++;
        break;
    case 5:
        func_021BC5BC(func_02188D20(fieldMap));
        work->savedCameraBits = func_0218EC5C(camera);
        func_0218F0A8(camera);
        (*seq)++;
        break;
    case 6:
        if (work->savedCameraBits != 0 && func_0218F0E8(camera) != 0)
            break;
        func_021BB260(bg, 0);
        func_0218EC54(camera);
        func_0218F848(camera);
        func_0218F1AC(camera, 0);
        func_021A3038(func_02188CB4(fieldMap), &playerPos2);
        param2.pitch = 0x25d8;
        param2.yaw = 0;
        param2.distance = 0xed000;
        param2.targetOffset.x = 0;
        param2.targetOffset.y = 0x4000;
        param2.targetOffset.z = 0;
        param2.targetPos = playerPos2;
        param2.fovy = 0xe38;
        param2.flags.apply[0] = 1;
        param2.flags.apply[1] = 1;
        param2.flags.apply[2] = 0;
        param2.flags.apply[3] = 1;
        param2.flags.apply[4] = 1;
        param2.flags.apply[5] = 1;
        func_0218F900(camera, &param2, 1);
        (*seq)++;
    case 7:
        if (func_0218FE50(camera) != 0)
            break;
        func_0216DAC8(func_021A3074(func_02188CB4(fieldMap)), 1);
        visiblePlanes = func_02043658();
        func_02188DA0();
        func_02043534(visiblePlanes);
        func_02188DB0(fieldMap);
        (*seq)++;
        break;
    case 8:
        func_0216D9A0(func_02188C7C(fieldMap));
        child = func_021C1CB0(work->gameSystem, ci, (u8)work->cutInIdAfter);
        if (child != 0) {
            func_02012374(event, child);
        } else {
            mmdl = func_021A3074(func_02188CB4(fieldMap));
            func_0216DAC8(mmdl, 0);
            func_0216D5E0(mmdl, 1);
            func_02012374(event, func_020122C0(work->gameSystem, event, func_021C85CC, 0));
        }
        (*seq)++;
        break;
    case 9:
        func_0216D9E4(func_02188C7C(fieldMap));
        func_021BC578(func_02188D20(fieldMap), work->zoneId);
        flags.apply[0] = 1;
        flags.apply[1] = 1;
        flags.apply[2] = 0;
        flags.apply[3] = 1;
        flags.apply[4] = 1;
        flags.apply[5] = 1;
        func_0218F9C4(camera, &flags, 10);
        (*seq)++;
    case 10:
        if (func_0218FE50(camera) != 0)
            break;
        if (work->savedCameraBits != 0)
            func_0218EC30(camera, work->savedCameraBits);
        func_0218F05C(camera);
        func_021BB260(bg, 1);
        func_0218F878(camera);
        func_0218F1AC(camera, 1);
        return 1;
    }
    return 0;
}

/* Fades the screen out, then ends. */
int func_021C85CC(GameEvent *event, int *seq)
{
    func_0201210C(func_020124E4(event));
    switch (*seq) {
    case 0:
        func_0204E720(3, 0x10, 0, 0);
        (*seq)++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}

PleasureBoatWork *func_021C8608(void)
{
    PleasureBoatWork *work = func_02030734(5, sizeof(PleasureBoatWork), 1, &d_021DE534, 0x31);
    work->eventPending = 0;
    work->timeTicks = 0;
    work->periodCount = 0;
    work->groupCount[0] = 0;
    work->groupCount[1] = 0;
    work->groupCount[2] = 0;
    work->groupCount[3] = 0;
    work->locked = 0;
    func_02034AC4((int)d_00000024); /* stand-in: overlay id passed as a raw address constant; a plain 0x24 changes the literal pool */
    func_021F36C0(work);
    func_02034A5C((int)d_00000024);
    return work;
}

/* Plays the arrival jingle and moves to the next period once the pending flag is set. */
void func_021C8660(PleasureBoatWork *work)
{
    if (work != 0 && work->locked == 0 && work->eventPending != 0) {
        func_020061E4(0x6dd);
        work->periodCount++;
        work->eventPending = 0;
    }
}

/* Advances the boat clock; returns the script event when the boat reaches a milestone. */
GameEvent *func_021C868C(GameSystem *gameSystem, PleasureBoatWork *work)
{
    GameEvent *event;
    int hasEvent;
    int milestone;
    if (work == 0) {
        return 0;
    }
    if (work->locked != 0) {
        return 0;
    }
    work->timeTicks = work->timeTicks + 1;
    milestone = func_021C87E0(work);
    switch (milestone) {
    case 1:
        work->eventPending = 1;
        hasEvent = 0;
        break;
    case 2:
        event = func_02158768(gameSystem, 1, 0, 0x8015);
        hasEvent = 1;
        break;
    default:
        hasEvent = 0;
        break;
    }
    if (hasEvent == 0) {
        event = 0;
    }
    return event;
}

/*
 * The sum is built in two statements (`r = f4 % 1350; r += b * 30;`) so
 * the multiply lands after the _s32_div_f call; one expression, or a
 * separate `t = b * 30` local, hoists it above the call into r4.
 * Adds `seconds` of boat time (30 ticks per second, 1350 ticks per period).
 * At a period end the clock stops one tick short (clamp) or enters the next period.
 */
void func_021C86E8(PleasureBoatWork *work, int seconds, int clamp)
{
    int ticks;
    ticks = work->timeTicks % 1350;
    ticks += seconds * 30;
    if (ticks >= 1350) {
        if (clamp) {
            work->timeTicks = (work->periodCount + 1) * 1350 - 1;
        } else {
            work->timeTicks = (work->periodCount + 1) * 1350;
            work->periodCount++;
        }
    } else {
        work->timeTicks += seconds * 30;
    }
}

/* Reads one boat statistic: kinds 0-3 are the group counters, 4 the visitor count, 5 the used passenger slots. */
int func_021C8738(PleasureBoatWork *work, int kind)
{
    int result;
    int i;
    switch (kind) {
    case 0:
        result = work->groupCount[0];
        break;
    case 1:
        result = work->groupCount[1];
        break;
    case 2:
        result = work->groupCount[2];
        break;
    case 3:
        result = work->groupCount[3];
        break;
    case 4:
        result = work->visitorCount;
        break;
    case 5:
        result = 0;
        for (i = 0; i < 15; i++) {
            if (work->passengers[i].occupied != 0) {
                result++;
            }
        }
        break;
    default:
        result = 0;
        break;
    }
    return result;
}
