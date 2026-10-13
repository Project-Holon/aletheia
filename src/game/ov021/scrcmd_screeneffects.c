/*
 * file:     scrcmd_screeneffects.c
 * unit:     yes
 * function: func_021B2830, func_021B2860, func_021B2874, func_021B2890, func_021B28E0, func_021B2910, func_021B2940, func_021B2970, func_021B29A0, func_021B29D0, func_021B2A00, func_021B2A30, func_021B2A60, func_021B2A90, func_021B2AA0, func_021B2AB0, func_021B2ADC, func_021B2B24, func_021B2B5C, func_021B2B94, func_021B2BD8, func_021B2BEC, func_021B2C08, func_021B2C5C, func_021B2CA0, func_021B2CE8, func_021B2D34, func_021B2D98, func_021B2DBC, func_021B2E08, func_021B2E3C, func_021B2E60, func_021B2E80, func_021B2EBC, func_021B2F18, func_021B2FB0
 * address:  0x021B2830
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from scrcmd_screeneffects.c at 0x021B2830 (lane L135, __FILE__ anchor scrcmd_screeneffects.c at 021B2EBC; brightness, fade and screen effect commands).
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_020113D0  0x020113D0  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_02189A24  0x02189A24  thumb  ov021
 *   sub_020113D0   0x020113D0  thumb
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_021C0AA0  0x021C0AA0  thumb  ov021
 *   func_021C0820  0x021C0820  thumb  ov021
 *   func_021C978C  0x021C978C  thumb  ov021
 *   func_021C9828  0x021C9828  thumb  ov021
 *   func_021C98F4  0x021C98F4  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218C654  0x0218C654  thumb  ov021
 *   func_0218C69C  0x0218C69C  thumb  ov021
 *   func_0218C54C  0x0218C54C  thumb  ov021
 *   func_0218C574  0x0218C574  thumb  ov021
 *   func_0218C7D8  0x0218C7D8  thumb  ov021
 *   func_0218BACC  0x0218BACC  thumb  ov021
 *   func_0218BA98  0x0218BA98  thumb  ov021
 *   func_0218C860  0x0218C860  thumb
 *   func_0218C88C  0x0218C88C  thumb  ov021
 *   func_0218C990  0x0218C990  thumb  ov021
 *   func_0218C89C  0x0218C89C  thumb  ov021
 *   d_021EE720     0x021EE720  data  a2
 *   func_0218C8D8  0x0218C8D8  thumb  ov021
 *   func_0218C9A4  0x0218C9A4  thumb  ov021
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_02189A1C  0x02189A1C  thumb  ov021
 *   d_021DE14C     0x021DE14C  data  a4
 *   func_02043658 0x02043658 arm
 *   func_02188DA0 0x02188DA0 thumb ov021
 *   func_02043534 0x02043534 arm
 *   func_02188DB0 0x02188DB0 thumb ov021
 *   func_02030EAC 0x02030EAC arm
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC5A0  0x021BC5A0  thumb  ov021
 */

#include "fieldmap_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

struct ScriptVm;
struct ScrcmdWork;
struct ScriptWork;
struct GameSystem;
struct GameData;
struct FieldMap;
struct FieldPlayer;
struct Tcb;
struct BuildModelMgr;
struct BuildModelEntry;
struct BuildModelNode;

/* Work of the fade task (0x18 bytes); the step is the task state. */
typedef struct FadeEffectTask {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct FieldMap *fieldMap;      /* 0x04 */
    u32 screenSelect;               /* 0x08: 0 fades with mask 3, else mask 12 */
    u32 skipWait;                   /* 0x0C: 1 ends the task right after the fade starts */
    u32 kind;                       /* 0x10: 0 slow in, 1 slow out, 2 fast in, 3 fast out */
    u32 step;                       /* 0x14 */
} FadeEffectTask;

extern u32 func_020307B0(void *work);
extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern struct ScriptWork *func_0215A5F4(struct ScrcmdWork *cmdWork);
extern u16 func_02159B10(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern struct GameSystem *func_0215A5DC(struct ScrcmdWork *cmdWork);
extern void func_0215897C(struct ScriptWork *scriptWork, void *event);
extern u16 *func_02159AE8(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern struct FieldMap *func_0201210C(struct GameSystem *gameSystem);
extern void *func_021BE92C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int mode, int arg3, int arg4, u8 season, u8 seasonAgain);
extern u16 func_02188C9C(struct FieldMap *fieldMap);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern u16 func_02011330(struct ScriptVm *vm);
extern void func_020113D0(struct ScriptVm *vm, int (*waitFunc)(struct ScriptVm *vm, struct ScrcmdWork *cmdWork));
extern u8 func_02012984(struct GameData *gameData);
extern void func_020061E4(u32 seNo);
extern void func_0204E720(u32 screenMask, s32 startLevel, s32 endLevel, s32 speed);
extern int func_0204E804(void);
extern u32 func_02189A24(struct FieldMap *fieldMap);
extern void *func_02158F50(struct ScriptWork *scriptWork);
extern void *func_021C0AA0(struct GameSystem *gameSystem, void *event);
extern void *func_021C0820(struct GameSystem *gameSystem, void *event, u32 param);
extern void *func_021C978C(void *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern void *func_021C9828(void *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern void *func_021C98F4(void *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap, int doorId);
extern void *func_02188C98(struct FieldMap *fieldMap);
extern struct BuildModelMgr *func_0218DC6C(void *g3dMapper);
extern struct BuildModelEntry *func_0218C654(struct BuildModelMgr *mgr, int modelId, VecFx32 *pos);
extern void func_0218C69C(struct BuildModelMgr *mgr, struct BuildModelEntry *entry, int arg3, int animId);
extern void func_0218C54C(struct BuildModelEntry *entry, int modelId);
extern void func_0218C574(struct BuildModelMgr *mgr, struct BuildModelEntry *entry, int modelIndex);
extern struct BuildModelNode *func_0218C7D8(struct BuildModelMgr *mgr, int modelId, VecFx32 *pos);
extern int func_0218BACC(struct BuildModelMgr *mgr, struct BuildModelNode *node);
extern struct BuildModelNode *func_0218BA98(struct BuildModelMgr *mgr, int handle);
extern void func_0218C860(struct BuildModelNode *node);
extern void func_0218C88C(struct BuildModelNode *node, int slot, int mode);
extern int func_0218C990(struct BuildModelNode *node, u16 *seOut);
extern void func_0218C89C(struct BuildModelNode *node, int mode);
extern int func_0218C8D8(struct BuildModelNode *node);
extern int func_0218C9A4(struct BuildModelNode *node);
extern u32 func_02188D30(struct FieldMap *fieldMap);
extern void *func_02030734(u32 heapId, u32 size, int align, const char *file, u16 line);
extern void func_02030DA8(u32 tcbSys, void (*func)(), void *work, u32 priority);
extern void func_02189A1C(struct FieldMap *fieldMap, u32 busy);
extern unsigned int func_02043658(void);
extern void func_02188DA0(void);
extern void func_02043534(unsigned int planes);
extern void func_02188DB0(struct FieldMap *fieldMap);
extern void func_02030EAC(struct Tcb *tcb);
extern void *func_02188D20(struct FieldMap *fieldMap);
extern void func_021BC5A0(void *placeName, u16 zoneId);
extern u16 d_021EE720;
extern u8 d_021DE14C;
int func_021B2830(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2860(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2874(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2890(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B28E0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2910(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2940(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2970(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B29A0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B29D0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2A00(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2A30(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2A60(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2A90(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2AA0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2AB0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2ADC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2B24(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2B5C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2B94(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
struct BuildModelMgr *func_021B2BD8(struct ScrcmdWork *cmdWork);
struct BuildModelEntry *func_021B2BEC(struct BuildModelMgr *mgr, int modelId, int x, int z);
int func_021B2C08(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2C5C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2CA0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2CE8(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2D34(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2D98(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2DBC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2E08(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2E3C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2E60(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2E80(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
void func_021B2EBC(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 kind, u32 screenSelect, u32 skipWait);
void func_021B2F18(struct Tcb *tcb, FadeEffectTask *task);
int func_021B2FB0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

/* Script command: change the screen brightness (mask, start level, end level, speed). */
int func_021B2830(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 screenMask = func_02011330(vm);
    u32 startLevel = func_02011330(vm);
    u32 endLevel = func_02011330(vm);
    u32 speed = func_02011330(vm);

    func_0204E720(screenMask, startLevel, endLevel, speed);
    return 0;
}

/* Wait function: finished once the brightness change is no longer active. */
int func_021B2860(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    if (func_0204E804() != 1) {
        return 1;
    }
    return 0;
}

/* Wait function: finished once the field map no longer reports a running script effect. */
int func_021B2874(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    if (func_02189A24(func_0201210C(func_0215A5DC(cmdWork))) != 1) {
        return 1;
    }
    return 0;
}

/*
 * Script command: start the field fade-in event for the current season.
 *
 * func_021BE92C reads its last two stack arguments with ldrb, so they are
 * u8 parameters: the narrowing then happens once at the call, scheduled
 * the way the original has it. A (u8) cast at the call site or a u8 local
 * feeding int parameters schedules the zero store after the shift pair.
 * Addresses are Black-image addresses.
 */
int func_021B2890(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct FieldMap *fieldMap;
    u32 season;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    season = func_02012984(gameData);
    func_0215897C(scriptWork, func_021BE92C(gameSystem, fieldMap, 3, 0, 0, season, season));
    return 0;
}

/* Script command: slow fade in. */
int func_021B28E0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    func_021B2EBC(gameSystem, func_0201210C(gameSystem), 0, 0, 0);
    return 0;
}

/* Script command: slow fade in (a second opcode with the same arguments as the one above). */
int func_021B2910(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    func_021B2EBC(gameSystem, func_0201210C(gameSystem), 0, 0, 0);
    return 0;
}

/* Script command: slow fade out. */
int func_021B2940(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    func_021B2EBC(gameSystem, func_0201210C(gameSystem), 1, 0, 0);
    return 0;
}

/* Script command: slow fade in on the second screen mask. */
int func_021B2970(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    func_021B2EBC(gameSystem, func_0201210C(gameSystem), 0, 1, 0);
    return 0;
}

/* Script command: slow fade out on the second screen mask. */
int func_021B29A0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    func_021B2EBC(gameSystem, func_0201210C(gameSystem), 1, 1, 0);
    return 0;
}

/* Script command: fast fade in. */
int func_021B29D0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    func_021B2EBC(gameSystem, func_0201210C(gameSystem), 2, 0, 0);
    return 0;
}

/* Script command: fast fade out. */
int func_021B2A00(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    func_021B2EBC(gameSystem, func_0201210C(gameSystem), 3, 0, 0);
    return 0;
}

/* Script command: fast fade in on the second screen mask. */
int func_021B2A30(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    func_021B2EBC(gameSystem, func_0201210C(gameSystem), 2, 1, 0);
    return 0;
}

/* Script command: fast fade out on the second screen mask. */
int func_021B2A60(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    func_021B2EBC(gameSystem, func_0201210C(gameSystem), 3, 1, 0);
    return 0;
}

/* Script command: wait until the brightness change has ended. */
int func_021B2A90(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    func_020113D0(vm, func_021B2860);
    return 1;
}

/* Script command: wait until the running script effect has ended. */
int func_021B2AA0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    func_020113D0(vm, func_021B2874);
    return 1;
}

/* Script command: start a map effect event on the script's event. */
int func_021B2AB0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    struct ScriptWork *scriptWork = func_0215A5F4(cmdWork);

    func_0215897C(scriptWork, func_021C0AA0(gameSystem, func_02158F50(scriptWork)));
    return 1;
}

/* Script command: start a map effect event that takes one script argument. */
int func_021B2ADC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    struct ScriptWork *scriptWork = func_0215A5F4(cmdWork);
    int param = (int)func_02159B10(vm, cmdWork);

    func_02188CB4(func_0201210C(gameSystem));
    func_0215897C(scriptWork, func_021C0820(gameSystem, func_02158F50(scriptWork), (unsigned char)param));
    return 1;
}

/* Script command: start the door open animation. */
int func_021B2B24(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    struct ScriptWork *scriptWork = func_0215A5F4(cmdWork);
    struct FieldMap *fieldMap = func_0201210C(gameSystem);

    func_0215897C(scriptWork, func_021C978C(func_02158F50(scriptWork), gameSystem, fieldMap));
    return 1;
}

/* Script command: start the door "set open" animation (door shown open without playing it). */
int func_021B2B5C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    struct ScriptWork *scriptWork = func_0215A5F4(cmdWork);
    struct FieldMap *fieldMap = func_0201210C(gameSystem);

    func_0215897C(scriptWork, func_021C9828(func_02158F50(scriptWork), gameSystem, fieldMap));
    return 1;
}

/* Script command: start the door close animation (door id from the script). */
int func_021B2B94(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    struct ScriptWork *scriptWork = func_0215A5F4(cmdWork);
    struct FieldMap *fieldMap = func_0201210C(gameSystem);
    int doorId = (int)func_02159B10(vm, cmdWork);

    func_0215897C(scriptWork, func_021C98F4(func_02158F50(scriptWork), gameSystem, fieldMap, doorId));
    return 1;
}

/* Returns the build model manager of the current field map. */
struct BuildModelMgr *func_021B2BD8(struct ScrcmdWork *cmdWork)
{
    return func_0218DC6C(func_02188C98(func_0201210C(func_0215A5DC(cmdWork))));
}

/*
 * Finds the build model entry of a model id near a tile position (x and z
 * are whole units, shifted into fx32).
 * Leaf filed for lane S20 (blocker of 021B2C08 and friends).
 *
 * Addresses are Black-image addresses.
 */
struct BuildModelEntry *func_021B2BEC(struct BuildModelMgr *mgr, int modelId, int x, int z)
{
    VecFx32 pos;

    pos.x = x << 16;
    pos.y = 0;
    pos.z = z << 16;
    return func_0218C654(mgr, modelId, &pos);
}

/* Script command: play the two animations (1 and 3) of the build model at a position. */
int func_021B2C08(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int modelId = (int)func_02159B10(vm, cmdWork);
    int x = (int)func_02159B10(vm, cmdWork);
    int z = (int)func_02159B10(vm, cmdWork);
    struct BuildModelMgr *mgr = func_021B2BD8(cmdWork);
    struct BuildModelEntry *entry = func_021B2BEC(mgr, modelId, x, z);

    if (entry) {
        func_0218C69C(mgr, entry, 0, 1);
        func_0218C69C(mgr, entry, 0, 3);
    }
    return 0;
}

/* Script command: play animation 2 of the build model at a position. */
int func_021B2C5C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int modelId = (int)func_02159B10(vm, cmdWork);
    int x = (int)func_02159B10(vm, cmdWork);
    int z = (int)func_02159B10(vm, cmdWork);
    struct BuildModelMgr *mgr = func_021B2BD8(cmdWork);
    struct BuildModelEntry *entry = func_021B2BEC(mgr, modelId, x, z);

    if (entry) {
        func_0218C69C(mgr, entry, 0, 2);
    }
    return 0;
}

/* Script command: swap the model id of the build model at a position. */
int func_021B2CA0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int modelId = (int)func_02159B10(vm, cmdWork);
    int x = (int)func_02159B10(vm, cmdWork);
    int z = (int)func_02159B10(vm, cmdWork);
    int newModelId = (int)func_02159B10(vm, cmdWork);
    struct BuildModelEntry *entry = func_021B2BEC(func_021B2BD8(cmdWork), modelId, x, z);

    if (entry) {
        func_0218C54C(entry, newModelId);
    }
    return 0;
}

/* Script command: set the model index of the build model at a position. */
int func_021B2CE8(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int modelId = (int)func_02159B10(vm, cmdWork);
    int x = (int)func_02159B10(vm, cmdWork);
    int z = (int)func_02159B10(vm, cmdWork);
    int modelIndex = (int)func_02159B10(vm, cmdWork);
    struct BuildModelMgr *mgr = func_021B2BD8(cmdWork);
    struct BuildModelEntry *entry = func_021B2BEC(mgr, modelId, x, z);

    if (entry) {
        func_0218C574(mgr, entry, modelIndex);
    }
    return 0;
}

/* Script command: create a build model node at a position; its handle goes to a script variable. */
int func_021B2D34(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    unsigned short *handleOut = func_02159AE8(vm, cmdWork);
    int modelId = func_02159B10(vm, cmdWork);
    int x = func_02159B10(vm, cmdWork);
    int z = func_02159B10(vm, cmdWork);
    struct BuildModelMgr *mgr;
    VecFx32 pos;

    mgr = func_0218DC6C(func_02188C98(func_0201210C(func_0215A5DC(cmdWork))));
    pos.x = x << 16;
    pos.y = 0;
    pos.z = z << 16;
    *handleOut = func_0218BACC(mgr, func_0218C7D8(mgr, modelId, &pos));
    return 0;
}

/* Script command: delete the build model node of a handle. */
int func_021B2D98(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 handle = func_02159B10(vm, cmdWork);
    struct BuildModelNode *node = func_0218BA98(func_021B2BD8(cmdWork), handle);

    if (node != 0) {
        func_0218C860(node);
    }
    return 0;
}

/* Script command: play a slot of a build model node and the sound effect its kind entry names. */
int func_021B2DBC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    unsigned short seNo;
    int handle = func_02159B10(vm, cmdWork);
    int slot = func_02159B10(vm, cmdWork);
    struct BuildModelNode *node = func_0218BA98(func_021B2BD8(cmdWork), handle);

    if (node) {
        func_0218C88C(node, slot, 0);
        if (func_0218C990(node, &seNo)) {
            func_020061E4(seNo);
        }
    }
    return 0;
}

/* Script command: play a slot of a build model node (mode 2). */
int func_021B2E08(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 handle = func_02159B10(vm, cmdWork);
    u32 slot = func_02159B10(vm, cmdWork);
    struct BuildModelNode *node = func_0218BA98(func_021B2BD8(cmdWork), handle);

    if (node != 0) {
        func_0218C88C(node, slot, 2);
    }
    return 0;
}

/* Script command: play the current slot of a build model node (mode 3). */
int func_021B2E3C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 handle = func_02159B10(vm, cmdWork);
    struct BuildModelNode *node = func_0218BA98(func_021B2BD8(cmdWork), handle);

    if (node != 0) {
        func_0218C89C(node, 3);
    }
    return 0;
}

/* Script command: remember a node handle and wait until that node's animation has ended. */
int func_021B2E60(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    d_021EE720 = func_02159B10(vm, cmdWork);
    func_020113D0(vm, func_021B2E80);
    return 1;
}

/* Wait function of the command above. */
int func_021B2E80(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct BuildModelNode *node = func_0218BA98(func_021B2BD8(cmdWork), d_021EE720);

    if (node == 0) {
        return 1;
    }
    if (func_0218C8D8(node) == 0) {
        return 0;
    }
    if (func_0218C9A4(node) == 0) {
        return 1;
    }
    return 0;
}

/* Creates the fade task: kind 0 slow in, 1 slow out, 2 fast in, 3 fast out. */
void func_021B2EBC(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 kind, u32 screenSelect, u32 skipWait)
{
    int tcbSys = func_02188D30(fieldMap);
    FadeEffectTask *task = func_02030734(4, 0x18, 1, (const char *)&d_021DE14C, 0x369);

    func_02030DA8(tcbSys, func_021B2F18, task, 0);
    func_02189A1C(fieldMap, 1);
    task->step = 0;
    task->gameSystem = gameSystem;
    task->fieldMap = fieldMap;
    task->screenSelect = screenSelect;
    task->skipWait = skipWait;
    task->kind = kind;
}

/* Fade task step: step 0 starts the brightness change, step 1 waits for it and frees the task. */
void func_021B2F18(struct Tcb *tcb, FadeEffectTask *task)
{
    int speed;
    int startLevel;
    int endLevel;
    int screenMask;
    int done;
    unsigned int visiblePlanes;

    switch (task->step) {
    case 0:
        if (task->kind <= 1) {
            speed = -1;
        } else {
            speed = 4;
        }
        if (task->kind == 0 || task->kind == 2) {
            startLevel = 16;
            endLevel = 0;
            visiblePlanes = func_02043658();
            func_02188DA0();
            func_02043534(visiblePlanes);
            func_02188DB0(task->fieldMap);
        } else {
            startLevel = 0;
            endLevel = 16;
        }
        if (task->screenSelect == 0) {
            screenMask = 3;
        } else {
            screenMask = 12;
        }
        func_0204E720(screenMask, startLevel, endLevel, speed);
        task->step = task->step + 1;
        break;
    case 1:
        done = 0;
        if (task->skipWait == 1) {
            done = 1;
        }
        if (func_0204E804() == 0) {
            done = 1;
        }
        if (done) {
            func_02189A1C(task->fieldMap, 0);
            func_02030EAC(tcb);
            func_020307B0(task);
        }
        break;
    }
}

/* Script command: force the place name banner of the current zone to show. */
int func_021B2FB0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct FieldMap *fieldMap = func_0201210C(func_0215A5DC(cmdWork));
    void *placeName = func_02188D20(fieldMap);

    func_021BC5A0(placeName, func_02188C9C(fieldMap));
    return 0;
}
