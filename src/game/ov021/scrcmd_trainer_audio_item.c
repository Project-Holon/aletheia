/*
 * file:     scrcmd_trainer_audio_item.c
 * unit:     yes
 * function: SCRCMD_CreateTrainerEye, SCRCMD_CallTrainerEyePairEvent, SCRCMD_GetTrainerHitKind, SCRCMD_GetTrainerEyeTrainerId, SCRCMD_GetTrainerEyeObjId, SCRCMD_GetScriptTrainerId, SCRCMD_StartTrainerBattle, SCRCMD_StartMultiTrainerBattle, SCRCMD_GetTrainerMessageIds, SCRCMD_GetTrainerBattleKind, SCRCMD_PlayTrainerEncounterBgm, SCRCMD_FadeInField, SCRCMD_ClassifyTrainer, SCRCMD_GetTrainerBattleParam, SCRCMD_StartTrainerBattleWithMon, SCRCMD_IncrementTrainerRecord, SCRCMD_FadeOutPlayBgm, SCRCMD_FadeOutPlayBgmWithFade, SCRCMD_FadeOutPlayFixedBgm, SCRCMD_IsBgmPlaying, SCRCMD_WaitBgmStopped, SCRCMD_StartWaitBgmStopped, SCRCMD_FadeBgmVolume, SCRCMD_RestoreBgmVolume, SCRCMD_RestoreBgmVolumeEvent, SCRCMD_ResumeZoneBgm, SCRCMD_ResumeZoneBgmWithFade, SCRCMD_PushBgmAndPlayWait, SCRCMD_PushBgm, SCRCMD_PopBgm, SCRCMD_PopBgmEvent, SCRCMD_ResumeBgmSlots, SCRCMD_ResumeBgmSlotsEvent, SCRCMD_ClearFinishedSeSlots, SCRCMD_MarkSeSlot, SCRCMD_IsMarkedSeBusy, SCRCMD_StopMarkedSeSlots, SCRCMD_PlaySe, SCRCMD_StopSe, SCRCMD_WaitSeStopped, SCRCMD_StartWaitSeStopped, SCRCMD_PushAndPlayBgm, SCRCMD_WaitBgmThenPop, SCRCMD_StartWaitBgmThenPop, SCRCMD_PlayPokeVoice, SCRCMD_PlayPerapVoice, SCRCMD_WaitPokeVoice, SCRCMD_StartWaitPokeVoice, SCRCMD_IssSwitchOn, SCRCMD_IssSwitchOff, SCRCMD_IsIssSwitchOn, SCRCMD_PokeVoiceEvent, SCRCMD_AddItem, SCRCMD_RemoveItem, SCRCMD_CanAddItem, SCRCMD_HasItem, SCRCMD_GetItemQuantity, SCRCMD_IsItemMachine, SCRCMD_GetItemPocket, SCRCMD_GetItemPartyUse, SCRCMD_GetItemMachineFlag
 * address:  0x021AE948
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from scrcmd_screeneffects.c at 0x021AE948 (lane L135, script command handlers, first one calls the trainer eye creator 021AE454; original unknown).
 *
 * symbols:
 *   func_0215A460  0x0215A460  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_GetTrainerEntry  0x02159124  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   EVENT_TRAINER_EYE_Create  0x021AE454  thumb  ov021
 *   EVENT_TRAINER_EYE_CreatePairEvent  0x021AE430  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   SCRIPT_WORK_GetScriptId  0x02158F8C  thumb  ov010
 *   func_0215A4C8  0x0215A4C8  thumb  ov010
 *   func_0215A4B4  0x0215A4B4  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   EVENT_BATTLE_CreateEncounterTask  0x0216E818  thumb  ov010
 *   func_0215A4A0  0x0215A4A0  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   func_0202A230  0x0202A230  thumb
 *   FIELD_SOUND_SYSTEM_GetTrainerClassBgm  0x02029E20  thumb
 *   FIELD_SOUND_SYSTEM_StartPushAndPlayWaitTask  0x02029AF4  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   EVENT_BATTLE_CreateEncounterTaskWithMon  0x0216EAB0  thumb  ov010
 *   ZONEDATA_IsZoneInTableDFD2  0x02014024  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   VM_GetU16  0x02011330  thumb
 *   FIELD_SOUND_SYSTEM_StartFadeOutAndPlayTask  0x02029984  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_PauseSlots  0x02028BA0  thumb
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 *   FIELD_SOUND_SYSTEM_StartFadeOutAndPlayWithFadeTask  0x02029A04  thumb
 *   FIELD_SOUND_SYSTEM_StartFadeOutAndPlayFixedBgmTask  0x02029A74  thumb
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELD_SOUND_SYSTEM_FadeVolume  0x02028A58  thumb
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx  0x02029DF4  thumb
 *   FIELD_SOUND_SYSTEM_StartChangeTask  0x020298A0  thumb
 *   FIELD_SOUND_SYSTEM_ResumeSlots  0x02028BDC  thumb
 *   FIELD_SOUND_SYSTEM_StartPopAndWaitTask  0x02029620  thumb
 *   SCRIPT_WORK_GetTrainerParam  0x02158F88  thumb  ov010
 *   FIELD_SOUND_SYSTEM_IsBusy  0x020289B8  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   SCRCMD_WORK_GetFadeParam  0x0215A6AC  thumb
 *   PM_VOICE_IsActive  0x02006BD0  thumb
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   ISS_SYS_GetSwitchSys  0x0202B578  thumb
 *   GFL_USE_IsLoaderBusy  0x02005C64  thumb
 *   PM_VOICE_GetPerapVoiceSave  0x02006CAC  thumb
 *   PM_VOICE_Play  0x02006984  thumb
 *   SCRCMD_WORK_SetFadeParam  0x0215A6B8  thumb  ov010
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   MYITEM_SAVEDATA_RemoveItem  0x02007F1C  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   MYITEM_SAVEDATA_HasItem  0x02007F68  thumb
 *   func_02007FB8  0x02007FB8  thumb
 *   func_02021288  0x02021288  thumb
 *   VM_SetWait  0x020113D0  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb  arm9
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb  arm9
 *   FIELD_SOUND_SYSTEM_StartPushTask  0x020295A4  thumb  arm9
 *   FIELD_SOUND_SYSTEM_StartPushAndPlayTask  0x02029830  thumb  arm9
 *   ISS_SWITCH_SYS_SwitchOn  0x0202C0D0  thumb  arm9
 *   ISS_SWITCH_SYS_SwitchOff  0x0202C0E4  thumb  arm9
 *   ISS_SWITCH_SYS_IsSwitchOn  0x0202C0F8  thumb  arm9
 *   GFL_USE_StopSeSlot  0x020061F8  thumb  arm9
 */
#include "../arm9/script_vm_types.h"
#include "../ov010/script_work_types.h"
#include "event_trainer_eye_types.h"

typedef struct ScrcmdWork ScrcmdWork;
typedef struct GameSystem GameSystem;
typedef struct FieldMap FieldMap;
typedef struct GameData GameData;
typedef struct GameEvent GameEvent;
typedef struct FieldSoundSystem FieldSoundSystem;
typedef struct TrainerRecord TrainerRecord;
typedef struct MyItem MyItem;
typedef struct IssSystem IssSystem;
typedef struct IssSwitchSys IssSwitchSys;

/* One trainer record of a script work (0x1C bytes): the trainer that saw the player, plus the eye event made for it. */
typedef struct ScriptTrainerSlot {
    TrainerEyeHit hit;          /* 0x00 */
    TrainerEyeWork *eyeWork;    /* 0x18: event work made by EVENT_TRAINER_EYE_Create */
} ScriptTrainerSlot;

/*
 * Work of the small game events below that change the BGM (event functions
 * with a state counter). The first field is the game system, the third the
 * script work that queues the follow-up event.
 */
typedef struct BgmEventWork {
    GameSystem *gameSystem;  /* 0x00 */
    u32 reserved04;                 /* 0x04 */
    ScriptWork *scriptWork;         /* 0x08 */
} BgmEventWork;

/* Work of the Pokemon voice event (0x0C bytes). */
typedef struct PokeVoiceWork {
    u16 species;                    /* 0x00 */
    u16 form;                       /* 0x02 */
    u32 usePerapVoice;              /* 0x04: 1 plays the recorded voice of the voice save */
    ScrcmdWork *cmdWork;     /* 0x08: receives the voice handle */
} PokeVoiceWork;

extern u32 func_0215A460(u32 scriptId);
extern GameData *GAMESYSTEM_GetGameData(GameSystem *gameSystem);
extern FieldMap *GAMESYSTEM_GetFieldMap(GameSystem *gameSystem);
extern ScriptWork *SCRCMD_WORK_GetScriptWork(ScrcmdWork *cmdWork);
extern GameSystem *SCRCMD_WORK_GetGameSystem(ScrcmdWork *cmdWork);
extern GameData *SCRCMD_WORK_GetGameData(ScrcmdWork *cmdWork);
extern u16 SCRCMD_WORK_GetHeapId(ScrcmdWork *cmdWork);
extern u16 SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, ScrcmdWork *cmdWork);
extern u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, ScrcmdWork *cmdWork);
extern ScriptFieldParam *SCRIPT_WORK_ResetFieldParam(ScriptWork *scriptWork);
extern u16 SCRIPT_WORK_GetScriptId(ScriptWork *scriptWork);
extern ScriptTrainerSlot *SCRIPT_WORK_GetTrainerEntry(ScriptWork *scriptWork, int index);
extern GameSystem *SCRIPT_WORK_GetGameSystem(ScriptWork *scriptWork);
extern u8 *SCRIPT_WORK_GetTrainerParam(ScriptWork *scriptWork);
extern void SCRIPT_SYS_CallEvent(ScriptWork *scriptWork, GameEvent *event);
extern void SCRIPT_WORK_SetCheckFlag(int checkFlag);
extern void SCRIPT_WORK_ResetCheckFlag(int checkFlag);
extern TrainerEyeWork *EVENT_TRAINER_EYE_Create(u32 heapId, FieldMap *fieldMap, TrainerEyeHit *hit, int recordIndex);
extern GameEvent *EVENT_TRAINER_EYE_CreatePairEvent(GameSystem *gameSystem, TrainerEyeWork *first, TrainerEyeWork *second);
extern u16 FLDMMDL_GetObjId(Mmdl *mmdl);
extern int func_0215A4C8(int trainerId);
extern int func_0215A4B4(int trainerId);
extern u32 func_0215A4A0(u32 scriptId);
extern GameEvent *EVENT_BATTLE_CreateEncounterTask(GameSystem *gameSystem, FieldMap *fieldMap, int battleKind, int allyTrainerId, int trainerId, int secondTrainerId, int thirdTrainerId);
extern GameEvent *EVENT_BATTLE_CreateEncounterTaskWithMon(GameSystem *gameSystem, FieldMap *fieldMap, u32 battleKind, u32 reserved, u32 trainerId, u32 secondTrainerId, u32 thirdTrainerId, u32 fourthTrainerId);
extern u32 func_0202A230(u32 trainerId, u32 index);
extern u16 FIELD_SOUND_SYSTEM_GetTrainerClassBgm(u32 trainerClass);
extern GameEvent *FIELD_SOUND_SYSTEM_StartPushAndPlayWaitTask(GameSystem *gameSystem, u32 bgmNo);
extern GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeIn(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait, int restoreBg, u8 seasonShown, u8 seasonTarget);
extern TrainerRecord *GAME_DATA_GetTrainerRecord(GameData *gameData);
extern u16 FIELDMAP_GetZoneId(FieldMap *fieldMap);
extern int ZONEDATA_IsZoneInTableDFD2(u32 zoneId);
extern u32 func_02008DF0(TrainerRecord *record, int index);
extern u16 VM_GetU16(ScriptVm *vm);
extern GameEvent *FIELD_SOUND_SYSTEM_StartFadeOutAndPlayTask(GameSystem *gameSystem, u32 bgmNo);
extern FieldSoundSystem *GAME_DATA_GetBgmInfo(GameData *gameData);
extern void FIELD_SOUND_SYSTEM_PauseSlots(FieldSoundSystem *soundSystem, u32 slotMask);
extern GameEvent *FIELD_SOUND_SYSTEM_StartFadeOutAndPlayWithFadeTask(GameSystem *gameSystem, u32 bgmNo, u16 fadeFrames);
extern GameEvent *FIELD_SOUND_SYSTEM_StartFadeOutAndPlayFixedBgmTask(GameSystem *gameSystem, u16 bgmNo);
extern int GFL_USE_IsBgmPlaying(void);
extern void VM_SetWait(ScriptVm *vm, ScriptWaitFn waitFn);
extern void FIELD_SOUND_SYSTEM_FadeVolume(FieldSoundSystem *soundSystem, u8 level, u16 frames);
extern u8 GAME_DATA_GetSeason(GameData *gameData);
extern u32 FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(GameData *gameData, u32 zoneId, u32 season);
extern GameEvent *FIELD_SOUND_SYSTEM_StartChangeTask(GameSystem *gameSystem, u32 bgmNo, u32 fadeOutFrames, u32 fadeInFrames);
extern void FIELD_SOUND_SYSTEM_ResumeSlots(FieldSoundSystem *soundSystem, u32 slotMask);
extern GameEvent *FIELD_SOUND_SYSTEM_StartPopAndWaitTask(GameSystem *gameSystem, u32 a, u32 b);
extern GameEvent *FIELD_SOUND_SYSTEM_StartPushTask(GameSystem *gameSystem, u32 bgmNo);
extern GameEvent *FIELD_SOUND_SYSTEM_StartPushAndPlayTask(GameSystem *gameSystem, u32 bgmNo);
extern int GFL_USE_IsSeSlotBusy(u32 slot);
extern int GFL_USE_GetSeSlot(u32 seNo);
extern void GFL_USE_StopSeSlot(int slot);
extern void GFL_USE_PlaySeDefaultVolume(u32 seNo);
extern u32 FIELD_SOUND_SYSTEM_IsBusy(FieldSoundSystem *soundSystem);
extern GameEvent *GAME_EVENT_Create(GameSystem *gameSystem, GameEvent *parent, void *func, unsigned int workSize);
extern void *GAME_EVENT_GetWork(GameEvent *event);
extern u32 PM_VOICE_IsActive(u32 handle);
extern u32 SCRCMD_WORK_GetFadeParam(ScrcmdWork *cmdWork);
extern IssSystem *GAMESYSTEM_GetIssSystem(GameSystem *gameSystem);
extern IssSwitchSys *ISS_SYS_GetSwitchSys(IssSystem *issSystem);
extern void ISS_SWITCH_SYS_SwitchOn(IssSwitchSys *switchSys, u32 switchNo);
extern void ISS_SWITCH_SYS_SwitchOff(IssSwitchSys *switchSys, u32 switchNo);
extern int ISS_SWITCH_SYS_IsSwitchOn(IssSwitchSys *switchSys, int switchNo);
extern int GFL_USE_IsLoaderBusy(void);
extern void PM_VOICE_GetPerapVoiceSave(void **out);
extern u32 PM_VOICE_Play(u32 species, u32 form, u32 pan, u32 dual, u32 volumeBiasB, u32 frequencyOffsetB, u32 reverse, void **recordedVoice);
extern void SCRCMD_WORK_SetFadeParam(ScrcmdWork *cmdWork, u32 voiceHandle);
extern MyItem *GAME_DATA_GetMyItem(GameData *gameData);
extern u16 func_02007E50(MyItem *myItem, u32 itemNo, u32 count, u32 heapId);
extern u16 MYITEM_SAVEDATA_RemoveItem(MyItem *myItem, u32 itemNo, u32 count, u32 heapId);
extern u16 func_02007E3C(MyItem *myItem, u32 itemNo, u32 count, u32 heapId);
extern u16 MYITEM_SAVEDATA_HasItem(MyItem *myItem, u32 itemNo, u32 count, u32 heapId);
extern u16 func_02007FB8(MyItem *myItem, u32 itemNo, u32 heapId);
extern u32 func_02020FE4(u32 itemNo, u32 selector, u32 heapId);
extern u32 func_02021288(u32 itemNo);

int SCRCMD_CreateTrainerEye(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_CallTrainerEyePairEvent(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetTrainerHitKind(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetTrainerEyeTrainerId(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetTrainerEyeObjId(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetScriptTrainerId(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_StartTrainerBattle(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_StartMultiTrainerBattle(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetTrainerMessageIds(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetTrainerBattleKind(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PlayTrainerEncounterBgm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FadeInField(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_ClassifyTrainer(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetTrainerBattleParam(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_StartTrainerBattleWithMon(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_IncrementTrainerRecord(ScrcmdWork *cmdWork);
int SCRCMD_FadeOutPlayBgm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FadeOutPlayBgmWithFade(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FadeOutPlayFixedBgm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_IsBgmPlaying(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WaitBgmStopped(ScriptVm *vm, void *user);
int SCRCMD_StartWaitBgmStopped(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FadeBgmVolume(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_RestoreBgmVolume(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_RestoreBgmVolumeEvent(BgmEventWork *work, u32 *seq);
int SCRCMD_ResumeZoneBgm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_ResumeZoneBgmWithFade(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PushBgmAndPlayWait(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PushBgm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PopBgm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PopBgmEvent(BgmEventWork *work, u32 *seq);
int SCRCMD_ResumeBgmSlots(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_ResumeBgmSlotsEvent(BgmEventWork *work, u32 *seq);
void SCRCMD_ClearFinishedSeSlots(ScriptWork *scriptWork);
void SCRCMD_MarkSeSlot(ScriptWork *scriptWork, u32 seNo);
int SCRCMD_IsMarkedSeBusy(ScriptWork *scriptWork);
void SCRCMD_StopMarkedSeSlots(ScriptWork *scriptWork);
int SCRCMD_PlaySe(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_StopSe(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WaitSeStopped(ScriptVm *vm, void *user);
int SCRCMD_StartWaitSeStopped(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PushAndPlayBgm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WaitBgmThenPop(ScriptVm *vm, void *user);
int SCRCMD_StartWaitBgmThenPop(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PlayPokeVoice(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PlayPerapVoice(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WaitPokeVoice(ScriptVm *vm, void *user);
int SCRCMD_StartWaitPokeVoice(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_IssSwitchOn(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_IssSwitchOff(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_IsIssSwitchOn(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PokeVoiceEvent(GameEvent *event, u32 *seq, PokeVoiceWork *work);
int SCRCMD_AddItem(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_RemoveItem(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_CanAddItem(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_HasItem(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetItemQuantity(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_IsItemMachine(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetItemPocket(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetItemPartyUse(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetItemMachineFlag(u32 itemNo);


/*
 * Script command: create the trainer eye event for trainer slot 0 or 1 and
 * keep it in the slot. The slot index is the first script operand.
 */
int SCRCMD_CreateTrainerEye(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 slotIndex;
    ScriptWork *scriptWork;
    ScriptFieldParam *fieldParam;
    ScriptTrainerSlot *slot;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    fieldParam = SCRIPT_WORK_ResetFieldParam(scriptWork);
    slotIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    if (slotIndex == 0) {
        slot = SCRIPT_WORK_GetTrainerEntry(scriptWork, 0);
    } else if (slotIndex == 1) {
        slot = SCRIPT_WORK_GetTrainerEntry(scriptWork, 1);
    }
    slot->eyeWork = EVENT_TRAINER_EYE_Create(SCRCMD_WORK_GetHeapId(cmdWork), fieldParam->fieldSystem, &slot->hit, slotIndex);
    return 0;
}

/* Script command: run the event that makes both trainers walk up to the player together. */
int SCRCMD_CallTrainerEyePairEvent(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    ScriptTrainerSlot *firstSlot = SCRIPT_WORK_GetTrainerEntry(scriptWork, 0);
    ScriptTrainerSlot *secondSlot = SCRIPT_WORK_GetTrainerEntry(scriptWork, 1);

    SCRIPT_SYS_CallEvent(scriptWork, EVENT_TRAINER_EYE_CreatePairEvent(SCRCMD_WORK_GetGameSystem(cmdWork), firstSlot->eyeWork, secondSlot->eyeWork));
    return 1;
}

/* Script command: store the hit kind of trainer slot 0 in a script variable. */
int SCRCMD_GetTrainerHitKind(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptTrainerSlot *slot = SCRIPT_WORK_GetTrainerEntry(SCRCMD_WORK_GetScriptWork(cmdWork), 0);

    *SCRIPT_WORK_ReadWorkPointer(vm, cmdWork) = slot->hit.hitKind;
    return 0;
}

/* Script command: store the trainer id of slot 0 or 1 (0 when the slot index is invalid). */
int SCRCMD_GetTrainerEyeTrainerId(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 slotIndex;
    ScriptWork *scriptWork;
    u16 *result;
    ScriptTrainerSlot *slot;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    slotIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    result = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    slot = 0;
    if (slotIndex == 0) {
        slot = SCRIPT_WORK_GetTrainerEntry(scriptWork, 0);
    } else if (slotIndex == 1) {
        slot = SCRIPT_WORK_GetTrainerEntry(scriptWork, 1);
    }
    *result = slot ? slot->hit.trainerId : 0;
    return 0;
}

/* Script command: store the field object id of the trainer in slot 0 or 1 (0 when invalid). */
int SCRCMD_GetTrainerEyeObjId(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 slotIndex;
    ScriptWork *scriptWork;
    u16 *result;
    ScriptTrainerSlot *slot;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    slotIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    result = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    slot = 0;
    if (slotIndex == 0) {
        slot = SCRIPT_WORK_GetTrainerEntry(scriptWork, 0);
    } else if (slotIndex == 1) {
        slot = SCRIPT_WORK_GetTrainerEntry(scriptWork, 1);
    }
    *result = slot ? FLDMMDL_GetObjId(slot->hit.trainer) : 0;
    return 0;
}

/* Script command: store the trainer id that belongs to the running script id. */
int SCRCMD_GetScriptTrainerId(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    u32 scriptId;

    SCRIPT_WORK_ResetFieldParam(scriptWork);
    scriptId = SCRIPT_WORK_GetScriptId(scriptWork);
    *SCRIPT_WORK_ReadWorkPointer(vm, cmdWork) = func_0215A460(scriptId);
    return 0;
}

/*
 * Script command: start a trainer battle. Operands: trainer id, second
 * trainer id, third trainer id. The battle kind comes from the trainer id;
 * a double battle trainer without a second id uses its own id twice.
 * The casts on the func_0215A4C8 call keep the register allocation of the
 * original (without them the first two operands swap registers).
 */
int SCRCMD_StartTrainerBattle(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    u32 trainerId, secondTrainerId, thirdTrainerId, battleKind;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    SCRIPT_WORK_GetScriptId(scriptWork);
    trainerId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    secondTrainerId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    thirdTrainerId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    battleKind = (u32)func_0215A4C8((u32)trainerId);
    if (secondTrainerId == 0 && func_0215A4B4(trainerId) == 1) {
        secondTrainerId = trainerId;
    }
    SCRIPT_SYS_CallEvent(scriptWork, EVENT_BATTLE_CreateEncounterTask(SCRIPT_WORK_GetGameSystem(scriptWork), SCRIPT_WORK_ResetFieldParam(scriptWork)->fieldSystem, battleKind, 0, trainerId, secondTrainerId, thirdTrainerId));
    SCRCMD_IncrementTrainerRecord(cmdWork);
    return 1;
}

/* Script command: start a multi battle (kind 1) with an ally and three trainer ids read from the script. */
int SCRCMD_StartMultiTrainerBattle(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 allyTrainerId, trainerId, secondTrainerId, thirdTrainerId;
    ScriptWork *scriptWork;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    SCRIPT_WORK_GetScriptId(scriptWork);
    allyTrainerId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    trainerId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    secondTrainerId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    thirdTrainerId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRIPT_SYS_CallEvent(scriptWork, EVENT_BATTLE_CreateEncounterTask(SCRIPT_WORK_GetGameSystem(scriptWork), SCRIPT_WORK_ResetFieldParam(scriptWork)->fieldSystem, 1, allyTrainerId, trainerId, secondTrainerId, thirdTrainerId));
    SCRCMD_IncrementTrainerRecord(cmdWork);
    return 1;
}

/*
 * Script command: store three message indices of the running trainer script:
 * one set for a single battle trainer, one for a pair when the script id
 * test func_0215A4A0 is 0, one for the other pairs.
 */
int SCRCMD_GetTrainerMessageIds(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 scriptId;
    u16 *firstResult, *secondResult, *thirdResult;
    u32 firstMsg, secondMsg, thirdMsg;

    scriptId = SCRIPT_WORK_GetScriptId(SCRCMD_WORK_GetScriptWork(cmdWork));
    firstResult = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    secondResult = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    thirdResult = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    if ((u16)func_0215A4B4(func_0215A460(scriptId)) == 0) {
        firstMsg = 0;
        secondMsg = 2;
        thirdMsg = 24;
    } else if ((u16)func_0215A4A0(scriptId) == 0) {
        firstMsg = 3;
        secondMsg = 5;
        thirdMsg = 6;
    } else {
        firstMsg = 7;
        secondMsg = 9;
        thirdMsg = 10;
    }
    *firstResult = firstMsg;
    *secondResult = secondMsg;
    *thirdResult = thirdMsg;
    return 0;
}

/* Script command: store the battle kind of a trainer id. */
int SCRCMD_GetTrainerBattleKind(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 trainerId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    *SCRIPT_WORK_ReadWorkPointer(vm, cmdWork) = func_0215A4C8(trainerId);
    return 0;
}

/*
 * Script command: play the encounter BGM of the trainer class of a trainer
 * id (the BGM change is queued as an event of the script).
 *
 * Compiled 66 of a 68-byte extent: the trailing halfword is an unlabelled
 * follower.
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_PlayTrainerEncounterBgm(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem;
    ScriptWork *scriptWork;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    SCRCMD_WORK_GetGameData(cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    SCRIPT_SYS_CallEvent(scriptWork, FIELD_SOUND_SYSTEM_StartPushAndPlayWaitTask(gameSystem, FIELD_SOUND_SYSTEM_GetTrainerClassBgm(func_0202A230(SCRIPT_WORK_ReadWorkValue(vm, cmdWork), 1))));
    return 1;
}

/* Script command: fade the field in again (event of the field map control). */
int SCRCMD_FadeInField(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);

    SCRIPT_SYS_CallEvent(scriptWork, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), 0, 0, 1, 0, 0));
    return 1;
}

/* Script command: store 1 or 2 when the trainer id has trainer data flag 9 or 11, else 0. */
int SCRCMD_ClassifyTrainer(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 trainerId;
    u16 *result;
    u32 kind;

    trainerId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    result = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    if (func_0202A230(trainerId, 9)) {
        kind = 1;
    } else if (func_0202A230(trainerId, 11)) {
        kind = 2;
    } else {
        kind = 0;
    }
    *result = kind;
    return 0;
}

/* Script command: store trainer data field 11 of a trainer id. */
int SCRCMD_GetTrainerBattleParam(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 trainerId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    *SCRIPT_WORK_ReadWorkPointer(vm, cmdWork) = func_0202A230(trainerId, 0xb);
    return 0;
}

/*
 * Script command: start a battle that also carries a Pokemon (event
 * 0216EAB0). Operands: four values passed on to the event.
 *
 * The four SCRIPT_WORK_ReadWorkValue results are u16 locals (the callee returns u16):
 * with u32 locals the stack-argument stores for EVENT_BATTLE_CreateEncounterTaskWithMon schedule
 * after the r1/r2 setup instead of before it.
 * Addresses are Black-image addresses.
 */
int SCRCMD_StartTrainerBattleWithMon(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 battleKind;
    ScriptWork *scriptWork;
    u16 trainerId, secondTrainerId, thirdTrainerId, fourthTrainerId;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    SCRIPT_WORK_GetScriptId(scriptWork);
    trainerId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    secondTrainerId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    thirdTrainerId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    fourthTrainerId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    battleKind = func_0215A4C8(trainerId);
    if (secondTrainerId == 0 && func_0215A4B4(trainerId) == 1) {
        secondTrainerId = trainerId;
    }
    SCRIPT_SYS_CallEvent(scriptWork, EVENT_BATTLE_CreateEncounterTaskWithMon(SCRIPT_WORK_GetGameSystem(scriptWork), SCRIPT_WORK_ResetFieldParam(scriptWork)->fieldSystem, battleKind, 0, trainerId, secondTrainerId, thirdTrainerId, fourthTrainerId));
    return 1;
}

/* Adds one to the trainer record counter 0x20 when the zone is in the zone table of ZONEDATA_IsZoneInTableDFD2. */
void SCRCMD_IncrementTrainerRecord(ScrcmdWork *cmdWork)
{
    ScriptFieldParam *fieldParam = SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork));
    TrainerRecord *record = GAME_DATA_GetTrainerRecord(SCRCMD_WORK_GetGameData(cmdWork));

    if (ZONEDATA_IsZoneInTableDFD2(FIELDMAP_GetZoneId(fieldParam->fieldSystem)) != 0)
        func_02008DF0(record, 0x20);
}

/* Script command: fade out the BGM and play another one (operand: BGM number). */
int SCRCMD_FadeOutPlayBgm(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem;
    ScriptWork *scriptWork;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    SCRIPT_SYS_CallEvent(scriptWork, FIELD_SOUND_SYSTEM_StartFadeOutAndPlayTask(gameSystem, VM_GetU16(vm)));
    FIELD_SOUND_SYSTEM_PauseSlots(GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(gameSystem)), 2);
    SCRIPT_WORK_SetCheckFlag(13);
    return 1;
}

/* Script command: as above with a fade length (operands: BGM number, fade frames). */
int SCRCMD_FadeOutPlayBgmWithFade(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem;
    ScriptWork *scriptWork;
    GameEvent *event;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    event = FIELD_SOUND_SYSTEM_StartFadeOutAndPlayWithFadeTask(gameSystem, VM_GetU16(vm), VM_GetU16(vm));
    SCRIPT_SYS_CallEvent(scriptWork, event);
    FIELD_SOUND_SYSTEM_PauseSlots(GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(gameSystem)), 2);
    SCRIPT_WORK_SetCheckFlag(13);
    return 1;
}

/* Script command: fade out the BGM and play the fixed BGM (operand: BGM number). */
int SCRCMD_FadeOutPlayFixedBgm(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameEvent *event;
    GameSystem *gameSystem;
    ScriptWork *scriptWork;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    event = FIELD_SOUND_SYSTEM_StartFadeOutAndPlayFixedBgmTask(gameSystem, VM_GetU16(vm));
    SCRIPT_SYS_CallEvent(scriptWork, event);
    FIELD_SOUND_SYSTEM_PauseSlots(GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(gameSystem)), 2);
    SCRIPT_WORK_SetCheckFlag(13);
    return 1;
}

/* Script command: store whether a BGM is playing. */
int SCRCMD_IsBgmPlaying(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VM_GetU16(vm);
    *SCRIPT_WORK_ReadWorkPointer(vm, cmdWork) = GFL_USE_IsBgmPlaying();
    return 0;
}

/* Wait function: done when no BGM plays. */
int SCRCMD_WaitBgmStopped(ScriptVm *vm, void *user)
{
    ScrcmdWork *cmdWork = user;

    SCRCMD_WORK_GetGameSystem(cmdWork);
    SCRCMD_WORK_GetScriptWork(cmdWork);
    if (GFL_USE_IsBgmPlaying() == 0) {
        return 1;
    }
    return 0;
}

/* Script command: wait until the BGM stops. */
int SCRCMD_StartWaitBgmStopped(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VM_SetWait(vm, SCRCMD_WaitBgmStopped);
    return 1;
}

/* Script command: fade the BGM volume to a level over a number of frames, then set check flag 12. */
int SCRCMD_FadeBgmVolume(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 level;
    GameData *gameData;
    GameSystem *gameSystem;
    FieldSoundSystem *soundSystem;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    GAMESYSTEM_GetFieldMap(gameSystem);
    soundSystem = GAME_DATA_GetBgmInfo(gameData);
    level = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    FIELD_SOUND_SYSTEM_FadeVolume(soundSystem, level, (u8)SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    SCRIPT_WORK_SetCheckFlag(12);
    return 0;
}

/* Script command: bring the BGM volume back to the maximum (0x7F) over a number of frames, then clear check flag 12. */
int SCRCMD_RestoreBgmVolume(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameData *gameData;
    GameSystem *gameSystem;
    FieldSoundSystem *soundSystem;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    GAMESYSTEM_GetFieldMap(gameSystem);
    soundSystem = GAME_DATA_GetBgmInfo(gameData);
    FIELD_SOUND_SYSTEM_FadeVolume(soundSystem, 0x7f, (u8)SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    SCRIPT_WORK_ResetCheckFlag(12);
    return 0;
}

/* Event function: restore the BGM volume at once, then finish. */
int SCRCMD_RestoreBgmVolumeEvent(BgmEventWork *work, u32 *seq)
{
    FieldSoundSystem *soundSystem = GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(work->gameSystem));

    switch (*seq) {
    case 0:
        FIELD_SOUND_SYSTEM_FadeVolume(soundSystem, 0x7f, 0);
        (*seq)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

/*
 * Script command: bring back the BGM of the current zone (fade out 90
 * frames, fade in 60 frames).
 *
 * Literal pool word 0x02029EB5 (an arm9 leaf address) has no witness outside this range.
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_ResumeZoneBgm(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 season, zoneBgm;
    GameSystem *gameSystem;
    GameData *gameData;
    FieldMap *fieldMap;
    FieldSoundSystem *soundSystem;
    ScriptWork *scriptWork;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    soundSystem = GAME_DATA_GetBgmInfo(gameData);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    season = GAME_DATA_GetSeason(gameData);
    zoneBgm = FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(gameData, FIELDMAP_GetZoneId(fieldMap), season);
    SCRIPT_SYS_CallEvent(scriptWork, FIELD_SOUND_SYSTEM_StartChangeTask(gameSystem, zoneBgm, 0x5a, 0x3c));
    FIELD_SOUND_SYSTEM_ResumeSlots(soundSystem, 2);
    SCRIPT_WORK_ResetCheckFlag(13);
    return 1;
}

/* Script command: as above with the fade out length read from the script. */
int SCRCMD_ResumeZoneBgmWithFade(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 season, fadeOutFrames, zoneBgm;
    GameSystem *gameSystem;
    GameData *gameData;
    FieldMap *fieldMap;
    FieldSoundSystem *soundSystem;
    ScriptWork *scriptWork;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    soundSystem = GAME_DATA_GetBgmInfo(gameData);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    fadeOutFrames = VM_GetU16(vm);
    season = GAME_DATA_GetSeason(gameData);
    zoneBgm = FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(gameData, FIELDMAP_GetZoneId(fieldMap), season);
    SCRIPT_SYS_CallEvent(scriptWork, FIELD_SOUND_SYSTEM_StartChangeTask(gameSystem, zoneBgm, fadeOutFrames, 0x3c));
    FIELD_SOUND_SYSTEM_ResumeSlots(soundSystem, 2);
    SCRIPT_WORK_ResetCheckFlag(13);
    return 1;
}

/* Script command: push the current BGM and play another one, then wait (operand: BGM number). */
int SCRCMD_PushBgmAndPlayWait(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    ScriptWork *scriptWork;

    GAMESYSTEM_GetGameData(gameSystem);
    GAMESYSTEM_GetFieldMap(gameSystem);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    SCRIPT_SYS_CallEvent(scriptWork, FIELD_SOUND_SYSTEM_StartPushAndPlayWaitTask(gameSystem, SCRIPT_WORK_ReadWorkValue(vm, cmdWork)));
    return 1;
}

/* Script command: push the current BGM (operand: BGM number), then set check flag 10. */
int SCRCMD_PushBgm(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);

    SCRIPT_SYS_CallEvent(scriptWork, FIELD_SOUND_SYSTEM_StartPushTask(gameSystem, SCRIPT_WORK_ReadWorkValue(vm, cmdWork)));
    SCRIPT_WORK_SetCheckFlag(10);
    return 1;
}

/* Script command: pop the pushed BGM, then clear check flag 10. */
int SCRCMD_PopBgm(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 firstOperand;
    GameSystem *gameSystem;
    ScriptWork *scriptWork;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    firstOperand = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRIPT_SYS_CallEvent(scriptWork, FIELD_SOUND_SYSTEM_StartPopAndWaitTask(gameSystem, firstOperand, SCRIPT_WORK_ReadWorkValue(vm, cmdWork)));
    SCRIPT_WORK_ResetCheckFlag(10);
    return 1;
}

/* Event function: queue the pop BGM event on the script, then finish. */
int SCRCMD_PopBgmEvent(BgmEventWork *work, u32 *seq)
{
    ScriptWork *scriptWork = work->scriptWork;

    SCRIPT_WORK_ResetFieldParam(scriptWork);
    switch (*seq) {
    case 0:
        SCRIPT_SYS_CallEvent(scriptWork, FIELD_SOUND_SYSTEM_StartPopAndWaitTask(work->gameSystem, 0, 0));
        (*seq)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

/* Script command: resume the BGM slots of mask 2, then clear check flag 13. */
int SCRCMD_ResumeBgmSlots(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    FIELD_SOUND_SYSTEM_ResumeSlots(GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(cmdWork))), 2);
    SCRIPT_WORK_ResetCheckFlag(13);
    return 0;
}

/* Event function: resume the BGM slots of mask 2 and finish. */
int SCRCMD_ResumeBgmSlotsEvent(BgmEventWork *work, u32 *seq)
{
    FIELD_SOUND_SYSTEM_ResumeSlots(GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(work->gameSystem)), 2);
    return 1;
}

/* Sound effect slots a script started: one bit per slot (5 slots) in the trainer parameter byte of the script work. */

/* Clears the bits of the sound effect slots that no longer play. */
void SCRCMD_ClearFinishedSeSlots(ScriptWork *scriptWork)
{
    int slot;
    u8 *seSlotMask;

    seSlotMask = SCRIPT_WORK_GetTrainerParam(scriptWork);
    for (slot = 0; slot < 5; slot++) {
        if (*seSlotMask & (1 << slot)) {
            if (GFL_USE_IsSeSlotBusy(slot) == 0)
                *seSlotMask &= ~(1 << slot);
        }
    }
}

/* Sets the bit of the slot that plays a sound effect. */
void SCRCMD_MarkSeSlot(ScriptWork *scriptWork, u32 seNo)
{
    u8 *seSlotMask = SCRIPT_WORK_GetTrainerParam(scriptWork);

    *seSlotMask |= 1 << GFL_USE_GetSeSlot(seNo);
}

/* Returns 1 when a marked slot still plays; otherwise clears the marks and returns 0. */
int SCRCMD_IsMarkedSeBusy(ScriptWork *scriptWork)
{
    int slot;
    u8 *seSlotMask;

    seSlotMask = SCRIPT_WORK_GetTrainerParam(scriptWork);
    for (slot = 0; slot < 5; slot++) {
        if (*seSlotMask & (1 << slot)) {
            if (GFL_USE_IsSeSlotBusy(slot) == 1)
                return 1;
        }
    }
    *seSlotMask = 0;
    return 0;
}

/* Stops every marked slot and clears the marks. */
void SCRCMD_StopMarkedSeSlots(ScriptWork *scriptWork)
{
    int slot;
    u8 *seSlotMask;

    seSlotMask = SCRIPT_WORK_GetTrainerParam(scriptWork);
    for (slot = 0; slot < 5; slot++) {
        if (*seSlotMask & (1 << slot))
            GFL_USE_StopSeSlot(slot);
    }
    *seSlotMask = 0;
}

/* Script command: play a sound effect (operand: SE number) and remember its slot. */
int SCRCMD_PlaySe(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 seNo = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);

    SCRCMD_ClearFinishedSeSlots(scriptWork);
    GFL_USE_PlaySeDefaultVolume(seNo);
    SCRCMD_MarkSeSlot(scriptWork, seNo);
    return 0;
}

/* Script command: stop the sound effects this script started. */
int SCRCMD_StopSe(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    SCRCMD_StopMarkedSeSlots(SCRCMD_WORK_GetScriptWork(cmdWork));
    return 0;
}

/* Wait function: done when none of the marked sound effect slots plays. */
int SCRCMD_WaitSeStopped(ScriptVm *vm, void *user)
{
    ScrcmdWork *cmdWork = user;

    if (SCRCMD_IsMarkedSeBusy(SCRCMD_WORK_GetScriptWork(cmdWork)) == 0) {
        return 1;
    }
    return 0;
}

/* Script command: wait for the sound effects this script started. */
int SCRCMD_StartWaitSeStopped(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VM_SetWait(vm, SCRCMD_WaitSeStopped);
    return 1;
}

/* Script command: push the current BGM and play another one (operand: BGM number). */
int SCRCMD_PushAndPlayBgm(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);

    SCRIPT_SYS_CallEvent(scriptWork, FIELD_SOUND_SYSTEM_StartPushAndPlayTask(gameSystem, VM_GetU16(vm)));
    return 1;
}

/* Wait function: when the BGM stopped and the sound system is idle, queue the pop BGM event. */
int SCRCMD_WaitBgmThenPop(ScriptVm *vm, void *user)
{
    ScrcmdWork *cmdWork = user;
    FieldSoundSystem *soundSystem;
    GameSystem *gameSystem;
    ScriptWork *scriptWork;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    soundSystem = GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(gameSystem));
    if (GFL_USE_IsBgmPlaying() == 0 && FIELD_SOUND_SYSTEM_IsBusy(soundSystem) == 0) {
        SCRIPT_SYS_CallEvent(scriptWork, FIELD_SOUND_SYSTEM_StartPopAndWaitTask(gameSystem, 0, 6));
        return 1;
    }
    return 0;
}

/* Script command: start waiting with SCRCMD_WaitBgmThenPop. */
int SCRCMD_StartWaitBgmThenPop(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VM_SetWait(vm, SCRCMD_WaitBgmThenPop);
    return 1;
}

/* Script command: play the voice of a Pokemon (operands: species, form) from a game event. */
int SCRCMD_PlayPokeVoice(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 species, form;
    GameEvent *event;
    ScriptWork *scriptWork;
    GameSystem *gameSystem;
    PokeVoiceWork *voiceWork;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    species = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    form = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    event = GAME_EVENT_Create(gameSystem, 0, SCRCMD_PokeVoiceEvent, 12);
    voiceWork = GAME_EVENT_GetWork(event);
    voiceWork->species = species;
    voiceWork->form = form;
    voiceWork->usePerapVoice = 0;
    voiceWork->cmdWork = cmdWork;
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: as above, but plays the recorded voice of the voice save. */
int SCRCMD_PlayPerapVoice(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 species, form;
    GameEvent *event;
    ScriptWork *scriptWork;
    GameSystem *gameSystem;
    PokeVoiceWork *voiceWork;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    species = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    form = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    event = GAME_EVENT_Create(gameSystem, 0, SCRCMD_PokeVoiceEvent, 12);
    voiceWork = GAME_EVENT_GetWork(event);
    voiceWork->species = species;
    voiceWork->form = form;
    voiceWork->usePerapVoice = 1;
    voiceWork->cmdWork = cmdWork;
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/*
 * Wait function: done when the Pokemon voice started by the command above
 * stopped (its voice handle sits in the fade parameter of the script command
 * work).
 *
 * Promoted from src/pending/: the blocker this file named is filed.
 * SCRCMD_WORK_GetFadeParam (0x0215A6AC) is a matched manifest entry, so the "matched"
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_WaitPokeVoice(ScriptVm *vm, void *user)
{
    ScrcmdWork *cmdWork = user;

    if (PM_VOICE_IsActive(SCRCMD_WORK_GetFadeParam(cmdWork)) == 0) {
        return 1;
    }
    return 0;
}

/* Script command: wait until the Pokemon voice ends. */
int SCRCMD_StartWaitPokeVoice(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VM_SetWait(vm, SCRCMD_WaitPokeVoice);
    return 1;
}

/* Script command: switch an ISS (area sound) switch on (operand: switch number). */
int SCRCMD_IssSwitchOn(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    IssSwitchSys *switchSys = ISS_SYS_GetSwitchSys(GAMESYSTEM_GetIssSystem(SCRCMD_WORK_GetGameSystem(cmdWork)));

    ISS_SWITCH_SYS_SwitchOn(switchSys, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

/* Script command: switch an ISS switch off (operand: switch number). */
int SCRCMD_IssSwitchOff(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    IssSwitchSys *switchSys = ISS_SYS_GetSwitchSys(GAMESYSTEM_GetIssSystem(SCRCMD_WORK_GetGameSystem(cmdWork)));

    ISS_SWITCH_SYS_SwitchOff(switchSys, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

/* Script command: store whether an ISS switch is on (operand: switch number). */
int SCRCMD_IsIssSwitchOn(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    IssSwitchSys *switchSys = ISS_SYS_GetSwitchSys(GAMESYSTEM_GetIssSystem(SCRCMD_WORK_GetGameSystem(cmdWork)));

    *SCRIPT_WORK_ReadWorkPointer(vm, cmdWork) = ISS_SWITCH_SYS_IsSwitchOn(switchSys, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

/* Event function: start the Pokemon voice once the loader is free, and hand the voice handle to the script command work. */
int SCRCMD_PokeVoiceEvent(GameEvent *event, u32 *seq, PokeVoiceWork *work)
{
    void *voiceSave;
    u32 voiceHandle;

    if (GFL_USE_IsLoaderBusy()) {
        return 0;
    }
    if (work->usePerapVoice) {
        u32 species, form;
        form = work->form;
        species = work->species;
        PM_VOICE_GetPerapVoiceSave(&voiceSave);
        voiceHandle = PM_VOICE_Play(species, form, 0x40, 0, 0, 0, 0, &voiceSave);
    } else {
        voiceHandle = PM_VOICE_Play(work->species, work->form, 0x40, 0, 0, 0, 0, 0);
    }
    SCRCMD_WORK_SetFadeParam(work->cmdWork, voiceHandle);
    return 1;
}

/* Script command: add items to the bag (operands: item, count); stores whether it worked. */
int SCRCMD_AddItem(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 heapId;
    MyItem *myItem;
    u32 itemNo, count;
    u16 *result;

    heapId = SCRCMD_WORK_GetHeapId(cmdWork);
    myItem = GAME_DATA_GetMyItem(SCRCMD_WORK_GetGameData(cmdWork));
    itemNo = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    count = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    result = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *result = func_02007E50(myItem, itemNo, count, heapId);
    return 0;
}

/* Script command: remove items from the bag (operands: item, count); stores the result. */
int SCRCMD_RemoveItem(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 heapId = SCRCMD_WORK_GetHeapId(cmdWork);
    MyItem *myItem;
    u32 itemNo, count;
    u16 *result;

    myItem = GAME_DATA_GetMyItem(SCRCMD_WORK_GetGameData(cmdWork));
    itemNo = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    count = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    result = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *result = MYITEM_SAVEDATA_RemoveItem(myItem, itemNo, count, heapId);
    return 0;
}

/* Script command: store whether the bag has room for items (operands: item, count). */
int SCRCMD_CanAddItem(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 heapId = SCRCMD_WORK_GetHeapId(cmdWork);
    MyItem *myItem;
    u32 itemNo, count;
    u16 *result;

    myItem = GAME_DATA_GetMyItem(SCRCMD_WORK_GetGameData(cmdWork));
    itemNo = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    count = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    result = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *result = func_02007E3C(myItem, itemNo, count, heapId);
    return 0;
}

/* Script command: store whether the bag holds at least a number of an item (operands: item, count). */
int SCRCMD_HasItem(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 heapId = SCRCMD_WORK_GetHeapId(cmdWork);
    MyItem *myItem;
    u32 itemNo, count;
    u16 *result;

    myItem = GAME_DATA_GetMyItem(SCRCMD_WORK_GetGameData(cmdWork));
    itemNo = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    count = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    result = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *result = MYITEM_SAVEDATA_HasItem(myItem, itemNo, count, heapId);
    return 0;
}

/* Script command: store how many of an item the bag holds (operand: item). */
int SCRCMD_GetItemQuantity(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 heapId = SCRCMD_WORK_GetHeapId(cmdWork);
    MyItem *myItem;
    u32 itemNo;
    u16 *result;

    myItem = GAME_DATA_GetMyItem(SCRCMD_WORK_GetGameData(cmdWork));
    itemNo = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    result = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *result = func_02007FB8(myItem, itemNo, heapId);
    return 0;
}

/* Script command: store the machine flag of an item (operand: item). */
int SCRCMD_IsItemMachine(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 itemNo = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    *SCRIPT_WORK_ReadWorkPointer(vm, cmdWork) = SCRCMD_GetItemMachineFlag(itemNo);
    return 0;
}

/* Script command: store the bag pocket of an item (operand: item). */
int SCRCMD_GetItemPocket(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 heapId = SCRCMD_WORK_GetHeapId(cmdWork);
    u32 itemNo = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    *SCRIPT_WORK_ReadWorkPointer(vm, cmdWork) = func_02020FE4(itemNo, 5, heapId);
    return 0;
}

/* Script command: store the party use of an item (item record field 15; operand: item). */
int SCRCMD_GetItemPartyUse(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 heapId = SCRCMD_WORK_GetHeapId(cmdWork);
    u32 itemNo = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    *SCRIPT_WORK_ReadWorkPointer(vm, cmdWork) = func_02020FE4(itemNo, 0xf, heapId);
    return 0;
}

/* Returns the machine flag of an item as a halfword. */
int SCRCMD_GetItemMachineFlag(u32 itemNo)
{
    return ((func_02021288(itemNo) << 16) >> 16);
}

