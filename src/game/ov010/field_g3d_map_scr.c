/*
 * file:     field_g3d_map_scr.c
 * unit:     yes
 * function: FIELD_G3D_MAP_ScrCmdReadSaveByte, FIELD_G3D_MAP_StoreBeaconTrainerKey, FIELD_G3D_MAP_CheckBeaconTrainerKey
 * address:  0x0216BF38
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldmmdl.c at 0x0216BFD4 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MOVE_POKEMON_SAVE_GetBlock  0x0200D418  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   MOVE_POKEMON_SAVE_GetEntryState  0x0200D468  thumb
 *   MYSTATUS_GetId 0x02008530 thumb
 *   MISC_SetHashedId 0x0200C38C thumb
 *   g_BeaconTrainerKeys 0x02172508 data a4
 *   MISC_GetHashedId 0x0200C39C thumb
 */
struct ScriptWorkRef;
struct ScriptSaveBlock;
struct MiscSave;
struct TrainerRec;
#include "../types.h"

struct ScrcmdWork;
struct GameData;

#include "scrcmd_work.h"
struct SaveControl;
#include "../arm9/game_data.h"
#include "../arm9/move_pokemon_save.h"
struct ScriptVm;
#include "script_work_cmd.h"
struct MovePokemonSave;
struct MyStatus;
#include "../arm9/mystatus.h"
#include "../arm9/beacon.h"
int FIELD_G3D_MAP_ScrCmdReadSaveByte(ScriptVm *vm, ScrcmdWork *cmdWork);
void FIELD_G3D_MAP_StoreBeaconTrainerKey(void *beaconSave, int slot, void *trainerRec);
int FIELD_G3D_MAP_CheckBeaconTrainerKey(void *beaconSave, int slot, void *trainerRec);
extern const u32 g_BeaconTrainerKeys[];

/* Script command: copy byte [index] of the 0x38-byte save block into a script variable. */
int FIELD_G3D_MAP_ScrCmdReadSaveByte(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    void *saveBlock;
    u8 index;
    u16 *dest;

    saveBlock = MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(cmdWork)));
    index = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    dest = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *dest = MOVE_POKEMON_SAVE_GetEntryState(saveBlock, index);
    return 0;
}

/* Store the trainer ID of trainerRec, xored with the slot key, in the beacon save. */
void FIELD_G3D_MAP_StoreBeaconTrainerKey(void *beaconSave, int slot, void *trainerRec) {
    if(slot<8) MISC_SetHashedId(beaconSave,slot,MYSTATUS_GetId(trainerRec)^*(const u32 *)((u8 *)g_BeaconTrainerKeys+(u32)slot*4));
}

/*
 * lever: named second call-result local preserves the original comparison registers.
 */
int FIELD_G3D_MAP_CheckBeaconTrainerKey(void *beaconSave, int slot, void *trainerRec) {
    u32 trainerId; u32 storedId;
    if(slot>=8) return 0;
    trainerId=MYSTATUS_GetId(trainerRec);
    storedId=MISC_GetHashedId(beaconSave,slot);
    if((storedId^trainerId)==*(const u32 *)((u8 *)g_BeaconTrainerKeys+(u32)slot*4)) return 1;
    return 0;
}
