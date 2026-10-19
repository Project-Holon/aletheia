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
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;
struct ScrcmdWork;
struct GameData;

extern struct GameData *SCRCMD_WORK_GetGameData(struct ScrcmdWork *work);
struct SaveControl;
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gd);
extern void *MOVE_POKEMON_SAVE_GetBlock(void *saveSys);
struct ScriptVm;
extern unsigned int SCRIPT_WORK_ReadWorkValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern unsigned short *SCRIPT_WORK_ReadWorkPointer(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
struct MovePokemonSave;
extern u8 MOVE_POKEMON_SAVE_GetEntryState(struct MovePokemonSave *pSave, u32 slot);
struct MyStatus;
extern u32 MYSTATUS_GetId(struct MyStatus *mystatus);
extern void MISC_SetHashedId(struct MiscSave *p, s32 i, u32 v);
extern u32 MISC_GetHashedId(struct MiscSave *p, s32 i);
int FIELD_G3D_MAP_ScrCmdReadSaveByte(int cmdState, int scriptCtx);
void FIELD_G3D_MAP_StoreBeaconTrainerKey(void *beaconSave, int slot, void *trainerRec);
int FIELD_G3D_MAP_CheckBeaconTrainerKey(void *beaconSave, int slot, void *trainerRec);
extern const u32 g_BeaconTrainerKeys[];

/* Script command: copy byte [index] of the 0x38-byte save block into a script variable. */
int FIELD_G3D_MAP_ScrCmdReadSaveByte(int cmdState, int scriptCtx)
{
    /* The register copies below are kept: they decide the original's register allocation. */
    int index;
    int cmdStateCopy;
    int scriptCtxCopy;
    void *saveBlock;
    void *chain;

    scriptCtxCopy = scriptCtx;
    cmdStateCopy = cmdState;
    cmdState = scriptCtxCopy;
    chain = SCRCMD_WORK_GetGameData((void *)cmdState);
    chain = GAME_DATA_GetSaveControl((struct GameData *)chain);
    saveBlock = MOVE_POKEMON_SAVE_GetBlock(chain);
    cmdState = cmdStateCopy;
    scriptCtx = scriptCtxCopy;
    cmdState = SCRIPT_WORK_ReadWorkValue((void *)cmdState, (void *)scriptCtx);
    cmdState = cmdState << 0x18;
    index = (unsigned)cmdState >> 0x18;
    cmdState = cmdStateCopy;
    scriptCtx = scriptCtxCopy;
    cmdState = (int)SCRIPT_WORK_ReadWorkPointer((void *)cmdState, (void *)scriptCtx); /* int-typed on purpose: pointer local changes codegen */
    cmdStateCopy = cmdState;
    scriptCtx = index;
    cmdState = MOVE_POKEMON_SAVE_GetEntryState(saveBlock, scriptCtx);
    *(u16 *)cmdStateCopy = cmdState;
    cmdState = 0;
    return cmdState;
}

/* Store the trainer ID of trainerRec, xored with the slot key, in the beacon save. */
void FIELD_G3D_MAP_StoreBeaconTrainerKey(void *beaconSave, int slot, void *trainerRec) {
    if(slot<8) MISC_SetHashedId(beaconSave,slot,MYSTATUS_GetId(trainerRec)^*(const u32 *)((u32)g_BeaconTrainerKeys+(u32)slot*4));
}

/*
 * lever: named second call-result local preserves the original comparison registers.
 */
int FIELD_G3D_MAP_CheckBeaconTrainerKey(void *beaconSave, int slot, void *trainerRec) {
    u32 trainerId; u32 storedId;
    if(slot>=8) return 0;
    trainerId=MYSTATUS_GetId(trainerRec);
    storedId=MISC_GetHashedId(beaconSave,slot);
    if((storedId^trainerId)==*(const u32 *)((u32)g_BeaconTrainerKeys+(u32)slot*4)) return 1;
    return 0;
}
