/*
 * file:     scrcmd_shop.c
 * unit:     yes
 * function: func_021B2FD8, func_021B30C8
 * address:  0x021B2FD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from scrcmd_screeneffects.c at 0x021B2FD8 (lane L135, __FILE__ anchor scrcmd_shop.c at 021B2FD8).
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_020113D0  0x020113D0  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_020127C4  0x020127C4  thumb
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_020071CC  0x020071CC  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_021B3158  0x021B3158  thumb  ov021
 *   func_021655D4  0x021655D4  thumb  ov010
 *   d_021DE210     0x021DE210  data   ov021  a1
 *   func_0218F1B4  0x0218F1B4  thumb
 *   func_0218F1AC  0x0218F1AC  thumb
 *   func_0218F848  0x0218F848  thumb
 *   func_0218ECE4  0x0218ECE4  thumb
 *   func_0218ECB4  0x0218ECB4  thumb
 *   func_0218EC54  0x0218EC54  thumb
 *   func_0218F918  0x0218F918  thumb
 *   d_021D9708     0x021D9708  data
 */

#include "scrcmd_proc_fld_types.h"
#include "field_camera_types.h"

struct ScriptVm;
struct ScrcmdWork;
struct GameSystem;
struct GameData;
struct FieldMap;
struct FieldMsgBg;
struct FieldPlayer;
struct SaveControl;

extern void *func_0215A5F4(struct ScrcmdWork *cmdWork);
extern u16 func_02159B10(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern void *func_0215A5DC(struct ScrcmdWork *cmdWork);
extern u16 *func_02159AE8(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern struct FieldMap *func_0201210C(struct GameSystem *gameSystem);
extern void *func_0201292C(struct GameData *gameData);
extern struct SaveControl *func_02012EBC(struct GameData *gameData);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern struct FieldMsgBg *func_02188C54(struct FieldMap *fieldMap);
extern void *func_02012F08(struct GameData *gameData);
extern void *func_02012F2C(struct GameData *gameData);
extern void func_020113D0(struct ScriptVm *vm, int (*waitFunc)(struct ScriptVm *vm, struct ScrcmdWork *cmdWork));
extern u16 func_021A3050(struct FieldPlayer *player);
extern void *func_02030734(u32 heapId, u32 size, int align, const char *file, u16 line);
extern ShopTask **func_02158FB4(void *scriptWork);
extern u8 *func_020127C4(struct GameData *gameData);
extern u32 func_021904AC(struct FieldMsgBg *msgBg);
extern void *func_020071CC(struct SaveControl *saveControl, u32 blockId);
extern int func_021B3158(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern void func_021655D4(void);
extern u8 func_0218F1B4(void *fieldCamera);
extern void func_0218F1AC(void *fieldCamera, u32 value);
extern void func_0218F848(void *fieldCamera);
extern void func_0218ECE4(void *fieldCamera, VecFx32 *out);
extern void func_0218ECB4(void *fieldCamera, VecFx32 *out);
extern void func_0218EC54(void *fieldCamera);
extern void func_0218F918(void *fieldCamera, FieldCameraMoveRequest *request, int frames);
int func_021B2FD8(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
void func_021B30C8(ShopTask *task, struct FieldMap *fieldMap, void *fieldCamera);
extern u8 d_021DE210[];
extern VecFx32 d_021D9708[];

/*
 * Script command: open the shop screen. Reads the shop id from the script,
 * allocates the ShopTask, fills the save data pointers the shop reads and
 * arms func_021B3158 as the wait function that steps the task.
 */
int func_021B2FD8(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 shopId;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct FieldMap *fieldMap;
    ShopTask **taskSlot;
    struct FieldMsgBg *msgBg;
    u8 *shopTable;
    ShopTask *task;

    shopId = func_02159B10(vm, cmdWork);
    func_02159AE8(vm, cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    taskSlot = func_02158FB4(func_0215A5F4(cmdWork));
    msgBg = func_02188C54(fieldMap);
    shopTable = func_020127C4(gameData);
    task = func_02030734(4, 0x214, 1, (const char *)d_021DE210, 0xFC);
    *taskSlot = task;
    task->shop.fontInfo = func_021904AC(msgBg);
    task->shop.moneyData = (u32)func_02012F08(gameData);
    task->shop.heapId = 0x15;
    task->shop.bagData = (u32)func_0201292C(gameData);
    task->shop.battlePointData = (u32)func_020071CC(func_02012EBC(gameData), 0x3a);
    task->shop.recordData = (u32)func_02012F2C(gameData);
    task->shop.shopTable = shopTable;
    switch (shopId) {
    case 0xFF:
        task->shopKind = shopId;
        break;
    case 0xFE:
        task->shopKind = shopId;
        break;
    case 0xFD:
        task->shopKind = shopId;
        break;
    case 0xF7:
    case 0xF8:
    case 0xF9:
    case 0xFA:
    case 0xFB:
        task->shopKind = shopId;
        break;
    default:
        task->shopKind = (u8)shopId;
        task->shopVariant = (u8)shopId;
        break;
    }
    func_020113D0(vm, func_021B3158);
    if (shopId != 0xFE && shopId != 0xFD) {
        func_021655D4();
    }
    return 1;
}

/*
 * Prepare the field camera for the shop: save whether the camera areas are
 * enabled, disable them, push the camera state and move the camera by the
 * per-player-model offset of d_021D9708 over 10 frames.
 */
void func_021B30C8(ShopTask *task, struct FieldMap *fieldMap, void *fieldCamera)
{
    FieldCameraMoveRequest request;
    int playerModel;

    task->fieldRegionArg = func_0218F1B4(fieldCamera);
    func_0218F1AC(fieldCamera, 0);
    func_0218F848(fieldCamera);
    playerModel = func_021A3050(func_02188CB4(fieldMap));
    func_0218ECE4(fieldCamera, &request.goal.eye);
    func_0218ECB4(fieldCamera, &request.goal.target);
    func_0218EC54(fieldCamera);
    request.goal.target.x += d_021D9708[playerModel].x;
    request.goal.target.y += d_021D9708[playerModel].y;
    request.goal.target.z += d_021D9708[playerModel].z;
    request.channels.shift = 0;
    request.channels.pitch = 0;
    request.channels.yaw = 0;
    request.channels.distance = 0;
    request.channels.fov = 0;
    request.channels.target = 1;
    func_0218F918(fieldCamera, &request, 10);
}
