/*
 * file:     unit_021B1668.c
 * unit:     yes
 * function: func_021B1668, func_021B1698, func_021B16DC, func_021B16F0, func_021B1700, func_021B1738, func_021B176C, func_021B17B4, func_021B17F8, func_021B181C, func_021B18B8, func_021B18E4, func_021B1950, func_021B19B0, func_021B19E0, func_021B1A20, func_021B1A44, func_021B1B08, func_021B1BB8, func_021B1BE8, func_021B1BF4, func_021B1C2C, func_021B1CB0, func_021B1CFC, func_021B1D20, func_021B1D64, func_021B1DEC, func_021B1E74, func_021B1E80, func_021B1F60, func_021B1FB8, func_021B2040, func_021B2070, func_021B20B0, func_021B2104, func_021B2154, func_021B21AC, func_021B2218, func_021B229C
 * address:  0x021B1668
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from scrcmd_screeneffects.c at 0x021B1668 (lane L135, map model (NPC) and field effect command handlers; original unknown).
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216E0E8  0x0216E0E8  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012844  0x02012844  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_020113D0  0x020113D0  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_02158F90  0x02158F90  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_0216DE54  0x0216DE54  thumb  ov010
 *   func_0201134C  0x0201134C  thumb
 *   func_02197D3C  0x02197D3C  thumb  ov021
 *   func_0215A6DC  0x0215A6DC  thumb  ov010
 *   func_0215A6FC  0x0215A6FC  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216E3D0  0x0216E3D0  thumb  ov010
 *   func_0216CE6C  0x0216CE6C  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_02162744  0x02162744  thumb  ov010
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02162740  0x02162740  thumb  ov010
 *   func_0216CEE4  0x0216CEE4  thumb  ov010
 *   func_0216E084  0x0216E084  thumb  ov010
 *   func_0216D5B0  0x0216D5B0  thumb  ov010
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_0216DB80  0x0216DB80  thumb  ov010
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0219BBA4  0x0219BBA4  thumb  ov021
 *   d_021EE71C     0x021EE71C  data  a1
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216DB04  0x0216DB04  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_021A32A8  0x021A32A8  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C78DC  0x021C78DC  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_021627C8  0x021627C8  thumb  ov010
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021618A0  0x021618A0  thumb  ov010
 *   d_021D93FC     0x021D93FC  data   a2
 *   d_021D9404     0x021D9404  data   a4
 *   d_021D940C     0x021D940C  data   a4
 *   d_021D9414     0x021D9414  data   a4
 *   d_021D941C     0x021D941C  data   a4
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_02161AC0  0x02161AC0  thumb  ov010
 *   func_021A3238  0x021A3238  thumb  ov021
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_021B83FC  0x021B83FC  thumb  ov021
 *   func_021C474C  0x021C474C  thumb  ov021
 *   func_021B8484  0x021B8484  thumb  ov021
 *   func_021B7DC0  0x021B7DC0  thumb  ov021
 *   func_0219E2C0  0x0219E2C0  thumb  ov021
 *   func_021C7878  0x021C7878  thumb  ov021
 *   func_021C7220  0x021C7220  thumb  ov021
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_021C7684  0x021C7684  thumb  ov021
 *   d_021D9424     0x021D9424  data   a4
 */
#include "fieldmap_types.h"
#include "fldmmdl_rail_types.h"
#include "../ov010/fldmmdl_types.h"
#include "../ov010/script_work_types.h"

typedef signed short s16;
typedef signed int s32;

typedef struct ScrcmdWork ScrcmdWork;

struct GameData;
struct GameSystem;
struct GameEvent;
struct EventDataSystem;
struct EventWork;
struct FieldMap;
struct FieldPlayer;
struct FieldTask;
struct FieldTaskManager;
struct RailWork;

/* Bits of the pause flags: models released from the script pause that the wait function pauses again. */
#define FLDMMDL_PAUSE_FLAG_PLAYER        0x01
#define FLDMMDL_PAUSE_FLAG_MOVE_CODE_30  0x02
#define FLDMMDL_PAUSE_FLAG_TARGET        0x04
#define FLDMMDL_PAUSE_FLAG_PARTNER       0x08

extern MmdlSys *func_0215A5EC(ScrcmdWork *cmdWork);
extern ScriptWork *func_0215A5F4(ScrcmdWork *cmdWork);
extern struct GameSystem *func_0215A5DC(ScrcmdWork *cmdWork);
extern struct GameData *func_0215A5E4(ScrcmdWork *cmdWork);
extern ScriptFieldParam *func_02158F58(ScriptWork *scriptWork);
extern Mmdl *func_02158F90(ScriptWork *scriptWork);
extern void func_0215897C(ScriptWork *scriptWork, struct GameEvent *event);
extern u16 func_02159B10(ScriptVm *vm, ScrcmdWork *cmdWork);
extern u16 *func_02159AE8(ScriptVm *vm, ScrcmdWork *cmdWork);
extern void func_0215A6DC(ScrcmdWork *cmdWork, void *animeTask);
extern u32 func_0215A6FC(ScrcmdWork *cmdWork);
extern u16 func_02011330(ScriptVm *vm);
extern u32 func_0201134C(ScriptVm *vm);
extern void func_020113D0(ScriptVm *vm, int (*waitFunc)(ScriptVm *vm, ScrcmdWork *cmdWork));
extern struct FieldMap *func_0201210C(struct GameSystem *gameSystem);
extern struct EventDataSystem *func_02012844(const struct GameData *gameData);
extern struct EventWork *func_0201296C(const struct GameData *gameData);
extern void *func_020127A4(const struct GameData *gameData);
extern u16 func_02012AC8(const void *playerWork);
extern void func_020061E4(u32 seId);
extern int func_0216D83C(Mmdl *mmdl);
extern int func_0216D86C(Mmdl *mmdl);
extern u16 func_0216D5F8(Mmdl *mmdl);
extern int func_0216D454(Mmdl *mmdl);
extern void func_0216E0E8(Mmdl *mmdl, int moveCode);
extern u16 func_0216D588(Mmdl *mmdl);
extern u16 func_0216D5A0(Mmdl *mmdl);
extern u32 func_0216E3D0(struct EventWork *eventWork, u32 spriteId);
extern Mmdl *func_0216CE6C(MmdlSys *sys, s16 gridX, s16 gridZ, int dir, int objId, int objCode, int moveCode, int zoneId);
extern Mmdl *func_0216CEE4(MmdlSys *sys, const void *header, int zoneId, int count, struct EventWork *eventWork, u32 objId);
extern void func_0216DAF8(Mmdl *mmdl);
extern void func_0216CF2C(Mmdl *mmdl);
extern void func_0216E084(Mmdl *mmdl, s16 gridX, s16 gridY, s16 gridZ, u32 dir);
extern u16 func_0216D5B0(Mmdl *mmdl);
extern int func_0216D63C(Mmdl *mmdl, int no);
extern void func_0216DB80(Mmdl *mmdl, int flag);
extern int func_0216DA5C(Mmdl *mmdl);
extern void func_0216D9A0(MmdlSys *sys);
extern void func_0216DB04(Mmdl *mmdl);
extern void func_0216D9E4(MmdlSys *sys);
extern void func_0216D5E0(Mmdl *mmdl, int dir);
extern void func_0216D674(Mmdl *mmdl, u16 drawStatus);
extern Mmdl *func_0216DDDC(MmdlSys *sys, u32 gridX, u32 gridZ, s32 posY, s32 range, u32 flag);
extern Mmdl *func_0216DE54(MmdlSys *sys, u32 moveCode);
extern Mmdl *func_0216DE94(MmdlSys *sys, u32 objId);
extern Mmdl *func_0216DEE0(MmdlSys *sys);
extern void func_0216D88C(const Mmdl *mmdl, VecFx32 *out);
extern void func_0216D89C(Mmdl *mmdl, const VecFx32 *pos);
extern void func_0216D8C0(Mmdl *mmdl, const VecFx32 *offset);
extern int func_02163E58(Mmdl *mmdl, VecFx32 *pos, int *outHeight);
extern u16 func_021642A4(int index);
extern u16 func_02162744(struct EventDataSystem *eventData);
extern void *func_02162740(struct EventDataSystem *eventData);
extern void *func_021627C8(struct EventDataSystem *eventData, struct EventWork *eventWork, const VecFx32 *pos, int mode);
extern struct GameEvent *func_021618A0(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int objId, const void *acmdList);
extern struct GameEvent *func_02161AC0(struct GameSystem *gameSystem, Mmdl *mmdl, VecFx32 *start, VecFx32 *target);
extern u16 func_02188C9C(struct FieldMap *fieldMap);
extern MmdlSys *func_02188C7C(struct FieldMap *fieldMap);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern struct FieldTaskManager *func_02188D38(struct FieldMap *fieldMap);
extern void *func_02197D3C(Mmdl *mmdl, const void *acmdList);
extern Mmdl *func_0219BBA4(Mmdl *mmdl);
extern void *func_0219E348(Mmdl *mmdl);
extern void func_0219E2C0(Mmdl *mmdl, RailLocation *location);
extern Mmdl *func_021A3074(struct FieldPlayer *player);
extern void func_021A3038(struct FieldPlayer *player, VecFx32 *outPos);
extern void func_021A2F48(struct FieldPlayer *player, u32 code);
extern int func_021A2F54(struct FieldPlayer *player);
extern u16 func_021A3050(struct FieldPlayer *player);
extern u32 func_021A3098(struct FieldPlayer *player);
extern int func_021A3238(struct FieldPlayer *player);
extern Mmdl *func_021A32A8(struct FieldPlayer *player, u32 limit);
extern void func_021B83FC(struct RailWork *work, u16 *outRailIndex, u16 *outLineGrid, u16 *outWidthGrid);
extern void func_021B8484(struct RailWork *work, u32 railIndex, u32 lineGrid, int widthPos);
extern void func_021B7DC0(struct RailWork *work, RailLocation *outLocation);
extern struct GameEvent *func_021C474C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, Mmdl *mmdl);
extern struct FieldTask *func_021C78DC(struct FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl);
extern struct FieldTask *func_021C7878(struct FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl);
extern struct FieldTask *func_021C7220(struct FieldMap *fieldMap, u16 frames, int spins, Mmdl *mmdl);
extern struct FieldTask *func_021C7684(struct FieldMap *fieldMap, Mmdl *mmdl, int frames, int height);
extern void func_021C6DE0(struct FieldTaskManager *manager, struct FieldTask *task, struct FieldTask *prerequisite);

/* Four player facing codes, tried in order by the turn-to-event command. */
typedef struct FacingCodes {
    u16 codes[4];
} FacingCodes;

extern u8 d_021EE71C;           /* pause flags */
extern FacingCodes d_021D93FC;  /* facing codes */
extern u8 d_021D9404[];         /* acmd list: turn right */
extern u8 d_021D940C[];         /* acmd list: turn left */
extern u8 d_021D9414[];         /* acmd list: turn down */
extern u8 d_021D941C[];         /* acmd list: turn up */
extern const VecFx32 d_021D9424; /* draw offset of a dropped-in model */

Mmdl *func_021B1668(ScrcmdWork *cmdWork, u32 objId);
int func_021B1698(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B16DC(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B16F0(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1700(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1738(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B176C(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B17B4(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B17F8(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B181C(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B18B8(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B18E4(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1950(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B19B0(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B19E0(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1A20(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1A44(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1B08(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1BB8(ScriptVm *vm, ScrcmdWork *cmdWork);
void func_021B1BE8(ScrcmdWork *cmdWork);
int func_021B1BF4(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1C2C(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1CB0(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1CFC(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1D20(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1D64(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1DEC(ScriptVm *vm, ScrcmdWork *cmdWork);
Mmdl *func_021B1E74(ScrcmdWork *cmdWork);
int func_021B1E80(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1F60(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B1FB8(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B2040(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B2070(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B20B0(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B2104(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B2154(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B21AC(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B2218(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021B229C(ScriptVm *vm, ScrcmdWork *cmdWork);

/*
 * Finds the model a script names: 0xF2 is the model with move code 0x30.
 * For 0xF1 (talk target) the original returns the result variable unset.
 */
Mmdl *func_021B1668(ScrcmdWork *cmdWork, u32 objId)
{
    MmdlSys *mmdlSys;
    Mmdl *mmdl;

    mmdlSys = func_0215A5EC(cmdWork);
    if (objId == 0xf2) {
        mmdl = func_0216DE54(mmdlSys, 0x30);
    } else if (objId == 0xf1) {
        func_0215A5F4(cmdWork);
    } else {
        mmdl = func_0216DE94(mmdlSys, objId);
    }
    return mmdl;
}

/* Script command: run a movement command list on a model (list at a script offset). */
int func_021B1698(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    int objId;
    int listOffset;
    Mmdl *mmdl;

    func_0215A5F4(cmdWork);
    objId = func_02159B10(vm, cmdWork);
    listOffset = func_0201134C(vm);
    mmdl = func_021B1668(cmdWork, objId);
    if (mmdl == 0) {
        return 0;
    }
    func_0215A6DC(cmdWork, func_02197D3C(mmdl, vm->pc + listOffset));
    return 0;
}

/* Wait function: ends when every running movement command list is done. */
int func_021B16DC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    if (func_0215A6FC(cmdWork) == 0) {
        return 1;
    }
    return 0;
}

/* Script command: wait for the running movement command lists. */
int func_021B16F0(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    func_020113D0(vm, func_021B16DC);
    return 1;
}

/* Script command: read the move code of a model into a script variable. */
int func_021B1700(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    MmdlSys *mmdlSys = func_0215A5EC(cmdWork);
    u16 *moveCodeVar = func_02159AE8(vm, cmdWork);

    *moveCodeVar = 0;
    *moveCodeVar = func_0216D5A0(func_0216DE94(mmdlSys, func_02159B10(vm, cmdWork)));
    return 0;
}

/* Script command: change the move code of a model. */
int func_021B1738(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    MmdlSys *mmdlSys = func_0215A5EC(cmdWork);
    u32 objId = func_02159B10(vm, cmdWork);
    u32 moveCode = func_02159B10(vm, cmdWork);

    func_0216E0E8(func_0216DE94(mmdlSys, objId), moveCode);
    return 0;
}

/* Script command: read the grid position of a model into two script variables. */
int func_021B176C(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    MmdlSys *mmdlSys;
    Mmdl *mmdl;
    u16 *gridXVar;
    u16 *gridZVar;

    mmdlSys = func_0215A5EC(cmdWork);
    mmdl = func_0216DE94(mmdlSys, func_02159B10(vm, cmdWork));
    gridXVar = func_02159AE8(vm, cmdWork);
    gridZVar = func_02159AE8(vm, cmdWork);
    *gridXVar = func_0216D83C(mmdl);
    *gridZVar = func_0216D86C(mmdl);
    return 0;
}

/* Script command: read the grid position of the player into two script variables. */
int func_021B17B4(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    Mmdl *playerMmdl;
    u16 *gridXVar;
    u16 *gridZVar;

    playerMmdl = func_021A3074(func_02188CB4(func_02158F58(func_0215A5F4(cmdWork))->fieldSystem));
    gridXVar = func_02159AE8(vm, cmdWork);
    gridZVar = func_02159AE8(vm, cmdWork);
    *gridXVar = func_0216D83C(playerMmdl);
    *gridZVar = func_0216D86C(playerMmdl);
    return 0;
}

/* Script command: read the displayed direction of the player into a script variable. */
int func_021B17F8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    Mmdl *playerMmdl = func_021B1E74(cmdWork);
    u16 *dirVar = func_02159AE8(vm, cmdWork);

    *dirVar = func_0216D5F8(playerMmdl);
    return 0;
}

/* Script command: add a model at a grid position (object id, sprite, move code from the script). */
int func_021B181C(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptFieldParam *fieldParam;
    int gridX;
    int gridZ;
    int dir;
    int objId;
    int spriteId;
    int moveCode;
    int zoneId;
    MmdlSys *mmdlSys;
    int objCode;
    Mmdl *mmdl;

    fieldParam = func_02158F58(func_0215A5F4(cmdWork));
    gridX = func_02159B10(vm, cmdWork);
    gridZ = func_02159B10(vm, cmdWork);
    dir = func_02159B10(vm, cmdWork);
    objId = func_02159B10(vm, cmdWork);
    spriteId = func_02159B10(vm, cmdWork);
    moveCode = func_02159B10(vm, cmdWork);
    zoneId = func_02188C9C(fieldParam->fieldSystem);
    mmdlSys = func_0215A5EC(cmdWork);
    objCode = func_0216E3D0(func_0201296C(func_0215A5E4(cmdWork)), spriteId);
    mmdl = func_0216CE6C(mmdlSys, gridX, gridZ, dir, objId, objCode, moveCode, zoneId);
    if (mmdl != 0) {
        func_0216DAF8(mmdl);
    }
    return 0;
}

/* Script command: delete a model. */
int func_021B18B8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    MmdlSys *mmdlSys = func_0215A5EC(cmdWork);
    Mmdl *mmdl = func_0216DE94(mmdlSys, func_02159B10(vm, cmdWork));

    if (mmdl != 0) {
        func_0216CF2C(mmdl);
    }
    return 0;
}

/* Script command: add the model of the party follower (header from the event data). */
int func_021B18E4(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameData *gameData;
    MmdlSys *mmdlSys;
    struct EventDataSystem *eventData;
    int count;
    int zoneId;
    int objId;
    struct EventWork *eventWork;
    Mmdl *mmdl;

    mmdlSys = func_0215A5EC(cmdWork);
    gameData = func_0215A5E4(cmdWork);
    eventData = func_02012844(gameData);
    count = func_02162744(eventData);
    zoneId = func_02012AC8(func_020127A4(gameData));
    objId = func_02159B10(vm, cmdWork);
    if (count != 0) {
        eventWork = func_0201296C(gameData);
        mmdl = func_0216CEE4(mmdlSys, func_02162740(eventData), zoneId, count, eventWork, objId);
        if (mmdl != 0) {
            func_0216DAF8(mmdl);
        }
    }
    return 0;
}

/* Script command: set the grid position and direction of a model. */
int func_021B1950(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    int objId;
    s16 gridX;
    s16 gridY;
    s16 gridZ;
    int dir;
    Mmdl *mmdl;

    objId = func_02159B10(vm, cmdWork);
    gridX = func_02159B10(vm, cmdWork);
    gridY = func_02159B10(vm, cmdWork);
    gridZ = func_02159B10(vm, cmdWork);
    dir = func_02159B10(vm, cmdWork);
    mmdl = func_0216DE94(func_0215A5EC(cmdWork), objId);
    if (mmdl) {
        func_0216E084(mmdl, gridX, gridY, gridZ, dir);
    }
    return 0;
}

/* Script command: read the event flag of a model into a script variable. */
int func_021B19B0(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 objId = func_02159B10(vm, cmdWork);
    u16 *eventFlagVar = func_02159AE8(vm, cmdWork);
    Mmdl *mmdl = func_0216DE94(func_0215A5EC(cmdWork), objId);

    if (mmdl != 0) {
        *eventFlagVar = func_0216D5B0(mmdl);
    }
    return 0;
}

/* Script command: read parameter 0..2 of a model into a script variable. */
int func_021B19E0(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    int objId;
    unsigned int paramIndex;
    u16 *paramVar;
    Mmdl *mmdl;

    objId = func_02159B10(vm, cmdWork);
    paramIndex = func_02159B10(vm, cmdWork);
    paramVar = func_02159AE8(vm, cmdWork);
    mmdl = func_0216DE94(func_0215A5EC(cmdWork), objId);
    if (paramIndex <= 2 && mmdl != 0) {
        *paramVar = func_0216D63C(mmdl, paramIndex);
    }
    return 0;
}

/* Script command: keep a model when the zone changes. */
int func_021B1A20(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 objId = func_02159B10(vm, cmdWork);
    Mmdl *mmdl = func_0216DE94(func_0215A5EC(cmdWork), objId);

    if (mmdl != 0) {
        func_0216DB80(mmdl, 1);
    }
    return 0;
}

/* Wait function: pauses again each model released by the pause command once it is idle. */
int func_021B1A44(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    Mmdl *targetMmdl;
    Mmdl *playerMmdl;
    Mmdl *moveCode30Mmdl;
    Mmdl *partnerMmdl;
    MmdlSys *mmdlSys;

    targetMmdl = func_02158F90(func_0215A5F4(cmdWork));
    playerMmdl = func_021B1E74(cmdWork);
    mmdlSys = func_0215A5EC(cmdWork);
    if (d_021EE71C & FLDMMDL_PAUSE_FLAG_PLAYER) {
        if (func_0216D454(playerMmdl) == 1) {
            func_0216DAF8(playerMmdl);
            d_021EE71C &= ~FLDMMDL_PAUSE_FLAG_PLAYER;
        }
    }
    if (d_021EE71C & FLDMMDL_PAUSE_FLAG_TARGET) {
        if (func_0216DA5C(targetMmdl) == 0) {
            func_0216DAF8(targetMmdl);
            d_021EE71C &= ~FLDMMDL_PAUSE_FLAG_TARGET;
        }
    }
    if (d_021EE71C & FLDMMDL_PAUSE_FLAG_MOVE_CODE_30) {
        moveCode30Mmdl = func_0216DE54(mmdlSys, 0x30);
        if (func_0216DA5C(moveCode30Mmdl) == 0) {
            func_0216DAF8(moveCode30Mmdl);
            d_021EE71C &= ~FLDMMDL_PAUSE_FLAG_MOVE_CODE_30;
        }
    }
    if (d_021EE71C & FLDMMDL_PAUSE_FLAG_PARTNER) {
        partnerMmdl = func_0219BBA4(targetMmdl);
        if (partnerMmdl == 0) {
            d_021EE71C &= ~FLDMMDL_PAUSE_FLAG_PARTNER;
        } else if (func_0216DA5C(partnerMmdl) == 0) {
            func_0216DAF8(partnerMmdl);
            d_021EE71C &= ~FLDMMDL_PAUSE_FLAG_PARTNER;
        }
    }
    if (d_021EE71C == 0) {
        return 1;
    }
    return 0;
}

/* Pauses all models, then releases the player, the talk target and its partner so they can finish moving; waits for them. */
int func_021B1B08(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    MmdlSys *mmdlSys;
    Mmdl *targetMmdl;
    Mmdl *playerMmdl;
    Mmdl *partnerMmdl;

    scriptWork = func_0215A5F4(cmdWork);
    mmdlSys = func_0215A5EC(cmdWork);
    targetMmdl = func_02158F90(scriptWork);
    playerMmdl = func_021B1E74(cmdWork);
    func_0216DE54(mmdlSys, 0x30);
    partnerMmdl = func_0219BBA4(targetMmdl);
    d_021EE71C = 0;
    func_0216D9A0(mmdlSys);
    if (func_0216D454(playerMmdl) == 0) {
        d_021EE71C |= FLDMMDL_PAUSE_FLAG_PLAYER;
        func_0216DB04(playerMmdl);
    }
    if (targetMmdl != 0) {
        if (func_0216DA5C(targetMmdl) == 1) {
            d_021EE71C |= FLDMMDL_PAUSE_FLAG_TARGET;
            func_0216DB04(targetMmdl);
        }
    }
    if (partnerMmdl != 0) {
        if (func_0216DA5C(partnerMmdl) == 1) {
            d_021EE71C |= FLDMMDL_PAUSE_FLAG_PARTNER;
            func_0216DB04(partnerMmdl);
        }
    }
    func_020113D0(vm, func_021B1A44);
    return 1;
}

/* Script command: pause all models (without a talk target), or pause them and wait for the released ones. */
int func_021B1BB8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    if (func_02158F90(func_0215A5F4(cmdWork)) == 0) {
        func_0216D9A0(func_0215A5EC(cmdWork));
    } else {
        return func_021B1B08(vm, cmdWork);
    }
    return 0;
}

/* Called by the script work code: releases the pause of all models. */
void func_021B1BE8(ScrcmdWork *cmdWork)
{
    func_0216D9E4(func_0215A5EC(cmdWork));
}

/* Script command: turn the talk target to face the player. */
int func_021B1BF4(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = func_0215A5F4(cmdWork);
    u32 dir = func_021642A4(func_0216D5F8(func_021B1E74(cmdWork)));
    Mmdl *targetMmdl = func_02158F90(scriptWork);

    if (targetMmdl != 0) {
        func_0216D5E0(targetMmdl, dir);
        func_0216D674(targetMmdl, 0);
    }
    return 0;
}

/* Script command: look for a model at a grid position; sets a found flag and its object id. */
int func_021B1C2C(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct FieldMap *fieldMap;
    u16 *objIdVar;
    u16 *foundVar;
    int gridX;
    int posY;
    int gridZ;
    Mmdl *mmdl;

    fieldMap = func_02158F58(func_0215A5F4(cmdWork))->fieldSystem;
    objIdVar = func_02159AE8(vm, cmdWork);
    foundVar = func_02159AE8(vm, cmdWork);
    gridX = func_02159B10(vm, cmdWork);
    posY = func_02159B10(vm, cmdWork);
    gridZ = func_02159B10(vm, cmdWork);
    mmdl = func_0216DDDC(func_02188C7C(fieldMap), (s16)gridX, (s16)gridZ, posY << 16, 0x8000, 0);
    if (mmdl) {
        *foundVar = 1;
        *objIdVar = func_0216D588(mmdl);
    } else {
        *foundVar = 0;
    }
    return 0;
}

/* Script command: look for the model in front of the player; sets a found flag and its object id. */
int func_021B1CB0(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct FieldPlayer *player;
    u16 *objIdVar;
    u16 *foundVar;
    Mmdl *mmdl;

    player = func_02188CB4(func_0201210C(func_0215A5DC(cmdWork)));
    objIdVar = func_02159AE8(vm, cmdWork);
    foundVar = func_02159AE8(vm, cmdWork);
    mmdl = func_021A32A8(player, 0x8000);
    if (mmdl != 0) {
        *foundVar = 1;
        *objIdVar = func_0216D588(mmdl);
    } else {
        *foundVar = 0;
    }
    return 0;
}

/* Wait function: ends when the player animation is done. */
int func_021B1CFC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    if (func_021A2F54(func_02188CB4(func_02158F58(func_0215A5F4(cmdWork))->fieldSystem)) == 1) {
        return 1;
    }
    return 0;
}

/* Script command: start a player animation (code from the script) and wait for it. */
int func_021B1D20(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptFieldParam *fieldParam;
    u32 animeCode;
    struct FieldPlayer *player;

    fieldParam = func_02158F58(func_0215A5F4(cmdWork));
    animeCode = func_02011330(vm);
    player = func_02188CB4(fieldParam->fieldSystem);
    func_021A2F48(player, animeCode);
    if (func_021A2F54(player) == 1)
        return 0;
    func_020113D0(vm, func_021B1CFC);
    return 1;
}

/* Script command: move the player model by a vertical offset over a number of frames (sign and direction from the script). */
int func_021B1D64(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VecFx32 offset;
    struct FieldMap *fieldMap;
    struct FieldTaskManager *taskManager;
    int negate;
    int height;
    int frames;
    int down;
    Mmdl *playerMmdl;

    fieldMap = func_02158F58(func_0215A5F4(cmdWork))->fieldSystem;
    taskManager = func_02188D38(fieldMap);
    negate = func_02159B10(vm, cmdWork);
    frames = func_02159B10(vm, cmdWork);
    height = func_02159B10(vm, cmdWork);
    down = func_02159B10(vm, cmdWork);
    if (negate != 0)
        frames = -frames;
    if (down == 0) {
        offset.x = 0;
        offset.y = -height << 12;
        offset.z = 0;
    } else {
        offset.x = 0;
        offset.y = height << 12;
        offset.z = 0;
    }
    playerMmdl = func_021A3074(func_02188CB4(fieldMap));
    func_021C6DE0(taskManager, func_021C78DC(fieldMap, frames, &offset, playerMmdl), 0);
    return 0;
}

/* Second script command with the same body as the previous one. */
int func_021B1DEC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VecFx32 offset;
    struct FieldMap *fieldMap;
    struct FieldTaskManager *taskManager;
    int negate;
    int height;
    int frames;
    int down;
    Mmdl *playerMmdl;

    fieldMap = func_02158F58(func_0215A5F4(cmdWork))->fieldSystem;
    taskManager = func_02188D38(fieldMap);
    negate = func_02159B10(vm, cmdWork);
    frames = func_02159B10(vm, cmdWork);
    height = func_02159B10(vm, cmdWork);
    down = func_02159B10(vm, cmdWork);
    if (negate != 0)
        frames = -frames;
    if (down == 0) {
        offset.x = 0;
        offset.y = -height << 12;
        offset.z = 0;
    } else {
        offset.x = 0;
        offset.y = height << 12;
        offset.z = 0;
    }
    playerMmdl = func_021A3074(func_02188CB4(fieldMap));
    func_021C6DE0(taskManager, func_021C78DC(fieldMap, frames, &offset, playerMmdl), 0);
    return 0;
}

/* Returns the player model. */
Mmdl *func_021B1E74(ScrcmdWork *cmdWork)
{
    return func_0216DEE0(func_0215A5EC(cmdWork));
}

/* Script command: when an event waits in front of the player, turn the player toward it unless already facing it. */
int func_021B1E80(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct FieldMap *fieldMap;
    struct GameData *gameData;
    struct GameSystem *gameSystem;
    FacingCodes facingCodes;
    int i;
    struct EventDataSystem *eventData;
    struct EventWork *eventWork;
    struct FieldPlayer *player;
    VecFx32 pos;
    int facing;
    int found;
    int playerFacing;
    u8 *turnList;

    scriptWork = func_0215A5F4(cmdWork);
    fieldMap = func_02158F58(scriptWork)->fieldSystem;
    gameData = func_0215A5E4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    facingCodes = d_021D93FC;
    eventData = func_02012844(gameData);
    eventWork = func_0201296C(gameData);
    player = func_02188CB4(fieldMap);
    func_021A3038(player, &pos);
    for (i = 0; i < 4; i++) {
        facing = facingCodes.codes[i];
        if (func_021627C8(eventData, eventWork, &pos, facing) != 0) {
            found = facing;
            break;
        }
    }
    playerFacing = func_021A3050(player);
    if (playerFacing != found) {
        if (found == 0) {
            turnList = d_021D941C;
        } else if (found == 1) {
            turnList = d_021D9414;
        } else if (found == 2) {
            turnList = d_021D940C;
        } else if (found == 3) {
            turnList = d_021D9404;
        } else {
            return 0;
        }
        func_0215897C(scriptWork, func_021618A0(gameSystem, fieldMap, 0xff, turnList));
        return 1;
    }
    return 0;
}

/*
 * Script command: read the player move form (0..3) into a script variable.
 * Each arm stores its constant through the variable itself; cross-jumping merges the
 * stores, leaving cases 2 and 3 branching onto case 1's branch.
 */
int func_021B1F60(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct FieldPlayer *player = func_02188CB4(func_02158F58(func_0215A5F4(cmdWork))->fieldSystem);
    u16 *formVar = func_02159AE8(vm, cmdWork);

    switch (func_021A3098(player)) {
    case 0:
        *formVar = 0;
        break;
    case 1:
        *formVar = 1;
        break;
    case 2:
        *formVar = 2;
        break;
    case 3:
        *formVar = 3;
        break;
    default:
        *formVar = 0;
        break;
    }
    return 0;
}

/* Script command: move a model to the centre of a grid cell by an event; waits for it. */
int func_021B1FB8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VecFx32 start;
    VecFx32 target;
    ScriptWork *scriptWork;
    int objId;
    int gridX;
    int gridY;
    int gridZ;
    MmdlSys *mmdlSys;
    struct GameSystem *gameSystem;
    Mmdl *mmdl;

    scriptWork = func_0215A5F4(cmdWork);
    objId = func_02159B10(vm, cmdWork);
    gridX = func_02159B10(vm, cmdWork);
    gridY = func_02159B10(vm, cmdWork);
    gridZ = func_02159B10(vm, cmdWork);
    mmdlSys = func_0215A5EC(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    mmdl = func_0216DE94(mmdlSys, objId);
    func_0216D88C(mmdl, &start);
    target.x = (gridX << 16) + 0x8000;
    target.y = gridY << 16;
    target.z = (gridZ << 16) + 0x8000;
    func_0215897C(scriptWork, func_02161AC0(gameSystem, mmdl, &start, &target));
    return 1;
}

/* Script command: read a player value (meaning unclear) into a script variable. */
int func_021B2040(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct FieldPlayer *player = func_02188CB4(func_02158F58(func_0215A5F4(cmdWork))->fieldSystem);
    u16 *resultVar = func_02159AE8(vm, cmdWork);

    *resultVar = func_021A3238(player);
    return 0;
}

/* Script command: read the rail location of the player into three script variables. */
int func_021B2070(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    Mmdl *playerMmdl;
    u16 *railIndexVar;
    u16 *lineGridVar;
    u16 *widthGridVar;

    playerMmdl = func_021B1E74(cmdWork);
    railIndexVar = func_02159AE8(vm, cmdWork);
    lineGridVar = func_02159AE8(vm, cmdWork);
    widthGridVar = func_02159AE8(vm, cmdWork);
    func_021B83FC(func_0219E348(playerMmdl), railIndexVar, lineGridVar, widthGridVar);
    return 0;
}

/* Script command: read the rail location of a model into three script variables. */
int func_021B20B0(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    Mmdl *mmdl;
    u16 *railIndexVar;
    u16 *lineGridVar;
    u16 *widthGridVar;

    mmdl = func_0216DE94(func_0215A5EC(cmdWork), func_02159B10(vm, cmdWork));
    railIndexVar = func_02159AE8(vm, cmdWork);
    lineGridVar = func_02159AE8(vm, cmdWork);
    widthGridVar = func_02159AE8(vm, cmdWork);
    func_021B83FC(func_0219E348(mmdl), railIndexVar, lineGridVar, widthGridVar);
    return 0;
}

/* Script command: start an event for a model (purpose unclear); waits for it. */
int func_021B2104(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameEvent *event;
    MmdlSys *mmdlSys;
    Mmdl *mmdl;
    struct GameSystem *gameSystem;

    gameSystem = func_0215A5DC(cmdWork);
    scriptWork = func_0215A5F4(cmdWork);
    mmdlSys = func_0215A5EC(cmdWork);
    mmdl = func_0216DE94(mmdlSys, func_02159B10(vm, cmdWork));
    event = func_021C474C(gameSystem, func_02158F58(scriptWork)->fieldSystem, mmdl);
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: put the player on a rail location. */
int func_021B2154(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    RailLocation location;
    Mmdl *playerMmdl;
    struct RailWork *railWork;
    u32 railIndex;
    u32 lineGrid;
    u32 widthPos;

    playerMmdl = func_021B1E74(cmdWork);
    railIndex = func_02159B10(vm, cmdWork);
    lineGrid = func_02159B10(vm, cmdWork);
    widthPos = func_02159B10(vm, cmdWork);
    railWork = func_0219E348(playerMmdl);
    func_021B8484(railWork, railIndex, lineGrid, widthPos);
    func_021B7DC0(railWork, &location);
    func_0219E2C0(playerMmdl, &location);
    return 0;
}

/* Script command: put a model on a rail location. */
int func_021B21AC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    RailLocation location;
    Mmdl *mmdl;
    struct RailWork *railWork;
    u32 railIndex;
    u32 lineGrid;
    u32 widthPos;

    mmdl = func_0216DE94(func_0215A5EC(cmdWork), func_02159B10(vm, cmdWork));
    railIndex = func_02159B10(vm, cmdWork);
    lineGrid = func_02159B10(vm, cmdWork);
    widthPos = func_02159B10(vm, cmdWork);
    railWork = func_0219E348(mmdl);
    func_021B8484(railWork, railIndex, lineGrid, widthPos);
    func_021B7DC0(railWork, &location);
    func_0219E2C0(mmdl, &location);
    return 0;
}

/* Script command: make a model spin and rise (sound effect 0x676). */
int func_021B2218(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VecFx32 riseOffset;
    ScriptWork *scriptWork;
    u32 objId;
    Mmdl *mmdl;
    struct FieldMap *fieldMap;
    struct FieldTaskManager *taskManager;
    struct FieldTask *riseTask;

    scriptWork = func_0215A5F4(cmdWork);
    objId = func_02159B10(vm, cmdWork);
    mmdl = func_0216DE94(func_0215A5EC(cmdWork), objId);
    fieldMap = func_02158F58(scriptWork)->fieldSystem;
    taskManager = func_02188D38(fieldMap);
    func_020061E4(0x676);
    riseOffset.x = 0;
    riseOffset.y = 0x96 << 12;
    riseOffset.z = 0;
    riseTask = func_021C7878(fieldMap, 0x18, &riseOffset, mmdl);
    func_021C6DE0(taskManager, func_021C7220(fieldMap, 0x18, 3, mmdl), 0);
    func_021C6DE0(taskManager, riseTask, 0);
    return 0;
}

/* Script command: place a model on the ground at a grid cell, then drop it in from above. */
int func_021B229C(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VecFx32 pos;
    VecFx32 dropOffset;
    int groundHeight;
    int objId;
    int gridX;
    int gridZ;
    int dir;
    Mmdl *mmdl;
    struct FieldMap *fieldMap;
    struct FieldTaskManager *taskManager;
    ScriptWork *scriptWork;

    scriptWork = func_0215A5F4(cmdWork);
    objId = func_02159B10(vm, cmdWork);
    gridX = func_02159B10(vm, cmdWork);
    gridZ = func_02159B10(vm, cmdWork);
    dir = func_02159B10(vm, cmdWork);
    mmdl = func_0216DE94(func_0215A5EC(cmdWork), objId);
    fieldMap = func_02158F58(scriptWork)->fieldSystem;
    taskManager = func_02188D38(fieldMap);
    if (mmdl == 0) {
        return 0;
    }
    groundHeight = 0;
    pos.x = (gridX << 16) + 0x8000;
    pos.y = 0xFA000;
    pos.z = (gridZ << 16) + 0x8000;
    func_02163E58(mmdl, &pos, &groundHeight);
    pos.y = groundHeight;
    func_0216E084(mmdl, gridX, (pos.y >> 4) / 0x1000, gridZ, dir);
    func_0216D89C(mmdl, &pos);
    dropOffset = d_021D9424;
    func_0216D8C0(mmdl, &dropOffset);
    func_021C6DE0(taskManager, func_021C7684(fieldMap, mmdl, 0x28, 0xfa), 0);
    return 0;
}
