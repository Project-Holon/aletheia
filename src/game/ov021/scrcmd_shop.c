/*
 * file:     scrcmd_shop.c
 * unit:     yes
 * function: SCRCMD_SHOP_StartShop, SCRCMD_SHOP_PrepareFieldCamera
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
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   VM_SetWait  0x020113D0  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   SCRIPT_WORK_GetUserWorkPtr  0x02158FB4  thumb  ov010
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   FIELD_MSGBG_GetFont  0x021904AC  thumb  ov021
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   SCRCMD_PROC_FLD_StepShopTask  0x021B3158  thumb  ov021
 *   GAME_BEACON_SEARCH_SetFacilityEnter  0x021655D4  thumb  ov010
 *   d_021DE210     0x021DE210  data   ov021  a1
 *   FIELD_CAMERA_GetAreasEnabled  0x0218F1B4  thumb
 *   FIELD_CAMERA_SetAreasEnabled  0x0218F1AC  thumb
 *   FIELD_CAMERA_PushStateConstrained  0x0218F848  thumb
 *   FIELD_CAMERA_GetEyeRaw  0x0218ECE4  thumb
 *   FIELD_CAMERA_GetTargetRaw  0x0218ECB4  thumb
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb
 *   FIELD_CAMERA_StartMoveConstrained  0x0218F918  thumb
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

extern void *SCRCMD_WORK_GetScriptWork(struct ScrcmdWork *cmdWork);
extern u16 SCRIPT_WORK_ReadWorkValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern void *SCRCMD_WORK_GetGameSystem(struct ScrcmdWork *cmdWork);
extern u16 *SCRIPT_WORK_ReadWorkPointer(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern struct GameData *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);
extern struct FieldMap *GAMESYSTEM_GetFieldMap(struct GameSystem *gameSystem);
extern void *GAME_DATA_GetMyItem(struct GameData *gameData);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
extern struct FieldMsgBg *FIELDMAP_GetMsgBg(struct FieldMap *fieldMap);
extern void *GAME_DATA_GetMiscSave(struct GameData *gameData);
extern void *GAME_DATA_GetTrainerRecord(struct GameData *gameData);
extern void VM_SetWait(struct ScriptVm *vm, int (*waitFunc)(struct ScriptVm *vm, struct ScrcmdWork *cmdWork));
extern u16 FIELD_PLAYER_GetDirDisp(struct FieldPlayer *player);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int align, const char *file, u16 line);
extern ShopTask **SCRIPT_WORK_GetUserWorkPtr(void *scriptWork);
extern u8 *GAME_DATA_GetSecondUnionInfo(struct GameData *gameData);
extern u32 FIELD_MSGBG_GetFont(struct FieldMsgBg *msgBg);
extern void *SAVE_CONTROL_GetBlock(struct SaveControl *saveControl, u32 blockId);
extern int SCRCMD_PROC_FLD_StepShopTask(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern void GAME_BEACON_SEARCH_SetFacilityEnter(void);
extern u8 FIELD_CAMERA_GetAreasEnabled(void *fieldCamera);
extern void FIELD_CAMERA_SetAreasEnabled(void *fieldCamera, u32 value);
extern void FIELD_CAMERA_PushStateConstrained(void *fieldCamera);
extern void FIELD_CAMERA_GetEyeRaw(void *fieldCamera, VecFx32 *out);
extern void FIELD_CAMERA_GetTargetRaw(void *fieldCamera, VecFx32 *out);
extern void FIELD_CAMERA_StopTargetTrace(void *fieldCamera);
extern void FIELD_CAMERA_StartMoveConstrained(void *fieldCamera, FieldCameraMoveRequest *request, int frames);
int SCRCMD_SHOP_StartShop(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
void SCRCMD_SHOP_PrepareFieldCamera(ShopTask *task, struct FieldMap *fieldMap, void *fieldCamera);
extern u8 d_021DE210[];
extern VecFx32 d_021D9708[];

/*
 * Script command: open the shop screen. Reads the shop id from the script,
 * allocates the ShopTask, fills the save data pointers the shop reads and
 * arms SCRCMD_PROC_FLD_StepShopTask as the wait function that steps the task.
 */
int SCRCMD_SHOP_StartShop(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 shopId;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct FieldMap *fieldMap;
    ShopTask **taskSlot;
    struct FieldMsgBg *msgBg;
    u8 *shopTable;
    ShopTask *task;

    shopId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    taskSlot = SCRIPT_WORK_GetUserWorkPtr(SCRCMD_WORK_GetScriptWork(cmdWork));
    msgBg = FIELDMAP_GetMsgBg(fieldMap);
    shopTable = GAME_DATA_GetSecondUnionInfo(gameData);
    task = GFL_HEAP_Alloc(4, 0x214, 1, (const char *)d_021DE210, 0xFC);
    *taskSlot = task;
    task->shop.fontInfo = FIELD_MSGBG_GetFont(msgBg);
    task->shop.moneyData = (u32)GAME_DATA_GetMiscSave(gameData);
    task->shop.heapId = 0x15;
    task->shop.bagData = (u32)GAME_DATA_GetMyItem(gameData);
    task->shop.battlePointData = (u32)SAVE_CONTROL_GetBlock(GAME_DATA_GetSaveControl(gameData), 0x3a);
    task->shop.recordData = (u32)GAME_DATA_GetTrainerRecord(gameData);
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
    VM_SetWait(vm, SCRCMD_PROC_FLD_StepShopTask);
    if (shopId != 0xFE && shopId != 0xFD) {
        GAME_BEACON_SEARCH_SetFacilityEnter();
    }
    return 1;
}

/*
 * Prepare the field camera for the shop: save whether the camera areas are
 * enabled, disable them, push the camera state and move the camera by the
 * per-player-model offset of d_021D9708 over 10 frames.
 */
void SCRCMD_SHOP_PrepareFieldCamera(ShopTask *task, struct FieldMap *fieldMap, void *fieldCamera)
{
    FieldCameraMoveRequest request;
    int playerModel;

    task->fieldRegionArg = FIELD_CAMERA_GetAreasEnabled(fieldCamera);
    FIELD_CAMERA_SetAreasEnabled(fieldCamera, 0);
    FIELD_CAMERA_PushStateConstrained(fieldCamera);
    playerModel = FIELD_PLAYER_GetDirDisp(FIELDMAP_GetFieldPlayer(fieldMap));
    FIELD_CAMERA_GetEyeRaw(fieldCamera, &request.goal.eye);
    FIELD_CAMERA_GetTargetRaw(fieldCamera, &request.goal.target);
    FIELD_CAMERA_StopTargetTrace(fieldCamera);
    request.goal.target.x += d_021D9708[playerModel].x;
    request.goal.target.y += d_021D9708[playerModel].y;
    request.goal.target.z += d_021D9708[playerModel].z;
    request.channels.shift = 0;
    request.channels.pitch = 0;
    request.channels.yaw = 0;
    request.channels.distance = 0;
    request.channels.fov = 0;
    request.channels.target = 1;
    FIELD_CAMERA_StartMoveConstrained(fieldCamera, &request, 10);
}
