#ifndef GAME_OV094_BTLV_EFFECT_H
#define GAME_OV094_BTLV_EFFECT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btlv_effect.c, prototypes copied from their definitions. */

struct BtlMain;
struct BtlPokeParam;
struct ZukanSave;
struct TcbTask;

#include "../ov094/btlv_effect_shared_types.h"
#include "../ov094/btlv_effect_shared_types.h"
#include "../types.h"
#include "../ov094/btlv_b_gauge_types.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"
#include "../ov094/btlv_camera_shared_types.h"
#include "../ov094/btlv_mcss_shared_types.h"
#include "../ov094/btlv_stage_shared_types.h"
#include "../ov094/btlv_gauge_types.h"
#include "../ov094/btlv_effvm_types.h"
#include "../arm9/palanm.h"
#include "../ov094/btlv_clact_shared_types.h"
#include "../ov094/btlv_bg_types.h"

BtlvEffSetup *BTLV_EFFECT_CreateSetup(int rule, int competitor, const BtlvEffFieldSituation *situation, int isMultiMode, const u16 *trainerTypes, void *battle, int param, u16 heap);
BtlvEffSetup *BTLV_EFFECT_CreateSetupFromBattleMain(u8 *battleMain, int param, u16 heap);
void BTLV_EFFECT_Init(BtlvEffSetup *setup, void *font, u16 heap);
void BTLV_EFFECT_Exit(void);
void BTLV_EFFECT_Main(void);
void BTLV_EFFECT_StartEffect(u32 scriptId);
void BTLV_EFFECT_StartEffectOnPoke(int attackerPos, u32 scriptId);
void BTLV_EFFECT_StartEffectBetweenPokes(int attackerPos, int defenderPos, u32 scriptId);
void BTLV_EFFECT_StartEffectWithRequest(const BtlvEffScriptRequest *request);
void BTLV_EFFECT_PauseVm(void);
void BTLV_EFFECT_ResumeVm(void);
void BTLV_EFFECT_StartDamageTintTask(int pos, int moveId);
void BTLV_EFFECT_StartPokeAppearEffect(int pos);
void BTLV_EFFECT_StartEffectWithColor(u32 defenderPos, u16 typeCode, u8 side, int argA, int argB);
void BTLV_EFFECT_StartEffectWithValue(int defenderPos, unsigned short typeCode);
void BTLV_EFFECT_StartHitTask(void *poke, int pos);
void BTLV_EFFECT_ResetPokeSprite(void *poke, int pos);
void BTLV_EFFECT_StartPokeEffectId285(u32 pos);
void BTLV_EFFECT_StartPokeEffectId286(u32 pos);
void BTLV_EFFECT_StartPokeEffectId26E(int pos);
void BTLV_EFFECT_StartPokeEffectId26F(u32 pos);
int BTLV_EFFECT_IsBusy(void);
void BTLV_EFFECT_SetPokeSpriteKey(void *poke, int key);
void BTLV_EFFECT_DeletePokeSprite(int pos);
int BTLV_EFFECT_IsPokeSpriteLoaded(int i);
void BTLV_EFFECT_AddPokeSprite(int trainerId, u32 pos, u32 x, u32 y, u32 z);
void BTLV_EFFECT_ReleasePokeSprite(int pos);
void BTLV_EFFECT_GaugeInitSlotFromBattlePoke(struct BtlMain *battleMain, struct BtlPokeParam *battlePoke, u32 slotIdx);
void BTLV_EFFECT_GaugeInitSlotFromPartyPoke(struct ZukanSave *zukanSave, void *partyPoke, u32 slotIdx);
void BTLV_EFFECT_GaugeDeleteSlot(u32 slotIdx);
void BTLV_EFFECT_GaugeStartHpChangeAnimated(u32 slotIdx, u32 newHp);
void BTLV_EFFECT_GaugeStartHpChangeInstant(u32 slotIdx, u32 newHp);
void BTLV_EFFECT_GaugeStartExpGain(int index, u32 amount);
void BTLV_EFFECT_GaugeRefreshForLevelUp(int index, struct BtlPokeParam *obj);
void BTLV_EFFECT_GaugeRequestStop(void);
int BTLV_EFFECT_GaugeIsAnimating(void);
void BTLV_EFFECT_GaugeSetSideVisible(int visible, int side);
void BTLV_EFFECT_GaugeSetSlotVisible(u32 visible, u32 slotIdx);
void BTLV_EFFECT_GaugeSetStatusIcon(u32 status, u32 slotIdx);
void BTLV_EFFECT_GaugeSelectSlot(int sel);
int BTLV_EFFECT_GaugeIsSlotOccupied(int index);
int BTLV_EFFECT_GaugeGetSlotHealthInfo(int slotIdx, int *hpState, int *statusAnim);
void BTLV_EFFECT_CreatePartyBallBar(const BtlvPartyBallBarParam *param);
void BTLV_EFFECT_DeletePartyBallBar(u32 i);
int BTLV_EFFECT_IsPartyBallBarActive(u32 i);
void BTLV_EFFECT_SetStageFieldTint(u32 scope, u8 startLevel, u8 targetLevel, u8 interval, u16 color);
int BTLV_EFFECT_IsStageFieldBusy(u32 scope);
void BTLV_EFFECT_SetStageLayerHidden(u32 layer, u32 hide);
void BTLV_EFFECT_StartPokeSpriteTransitionTask(int kind, int pos, int playSound);
void BTLV_EFFECT_SetPokeSpriteVisible(u32 posA, u32 posB);
int BTLV_EFFECT_GetPokeSlot(int pos);
void BTLV_EFFECT_TimerStart(int secondsPlayer, int secondsEnemy);
void BTLV_EFFECT_TimerSetVisible(u32 side, u32 visible, u32 restart);
int BTLV_EFFECT_TimerIsExpired(int i);
int BTLV_EFFECT_GetPokeSpriteState(int pos);
void BTLV_EFFECT_StartCameraMove(u32 flags, int kind, int frames, int delay, int easeCount);
void BTLV_EFFECT_GetPokeSpriteCameraTarget(u32 slot, VecFx32 *eyeOut, VecFx32 *basePos);
void *BTLV_EFFECT_GetWorkPtr(void);
BtlvCamera *BTLV_EFFECT_GetCamera(void);
BtlvMcssWork *BTLV_EFFECT_GetMcss(void);
BtlvStage *BTLV_EFFECT_GetStage(void);
BtlvGaugeWork *BTLV_EFFECT_GetGauge(void);
BtlvEffVmWork *BTLV_EFFECT_GetEffvm(void);
void *BTLV_EFFECT_GetOwner(void);
PaletteFade *BTLV_EFFECT_GetPalanm(void);
BtlvClact *BTLV_EFFECT_GetClact(void);
BtlvBg *BTLV_EFFECT_GetBg(void);
int BTLV_EFFECT_GetMode(void);
int BTLV_EFFECT_GetCompetitorType(void);
int BTLV_EFFECT_IsMultiMode(void);
unsigned short BTLV_EFFECT_GetTrainerType(int index);
void *BTLV_EFFECT_GetBattleMain(void);
int BTLV_EFFECT_GetSceneUnit(void);
int BTLV_EFFECT_PollLowHpBgm(void);
void BTLV_EFFECT_StopLowHpBgm(u32 bgmNo);
void BTLV_EFFECT_SetLowHpBgmSuppressed(u32 suppressed);
void BTLV_EFFECT_SaveBgmNo(u32 bgmNo);
int BTLV_EFFECT_IsBgmSaved(void);
void BTLV_EFFECT_StopLowHpBgmAndSuppress(u32 bgmNo);
void BTLV_EFFECT_SetVisibilityMode(int mode);
int BTLV_EFFECT_GetVisibilityMode(void);
void BTLV_EFFECT_SetSeSuppressed(int value);
int BTLV_EFFECT_IsSeSuppressed(void);
int BTLV_EFFECT_IsRecordEnabledInComm(void);
int BTLV_EFFECT_IsRecordAllowed(void);
void BTLV_EFFECT_SetAllPokeSpriteAnim(int mode);
void BTLV_EFFECT_RegisterTask(void *task, void (*cb)(void *), int arg);
int BTLV_EFFECT_FindTaskIndex(void *task);
void BTLV_EFFECT_DeleteTask(void *task);
void BTLV_EFFECT_DeleteTasksByArg(int arg);
void BTLV_EFFECT_SetIntroState(int state);
void BTLV_EFFECT_StartIntroEffect(void);
void BTLV_EFFECT_ResetIntroState(int state);
void BTLV_EFFECT_SetPokeEffectValue(int i, u32 value);
int BTLV_EFFECT_GetPokeEffectValue(int i);
void BTLV_EFFECT_SuspendVmWait(void);
void BTLV_EFFECT_ResumeVmWait(void);
int BTLV_EFFECT_FindFreeTaskSlot(void);
void BTLV_EFFECT_DeleteAllTasks(void);
void BTLV_EFFECT_VBlankTask(struct TcbTask *task, void *arg);
void BTLV_EFFECT_DamageTintTaskMain(struct TcbTask *task, void *arg);
void BTLV_EFFECT_ClearTaskMaskM0(void *tcb);
void BTLV_EFFECT_SequenceTaskMain(struct TcbTask *task, void *arg);
void BTLV_EFFECT_ClearTaskMaskM1(void *tcb);
void BTLV_EFFECT_PokeSpriteTransitionTaskMain(struct TcbTask *task, void *arg);
void BTLV_EFFECT_ClearTaskMaskM2(void *tcb);
void BTLV_EFFECT_DelayedStartEffectTaskMain(struct TcbTask *task, void *arg);
void BTLV_EFFECT_FreeTaskArg(void *tcb);
void BTLV_EFFECT_UpdateIntroInput(void);
void BTLV_EFFECT_ComputeScalarStep(fx32 from, fx32 to, fx32 *stepOut, fx32 frames);
void BTLV_EFFECT_ComputeVectorStep(const VecFx32 *from, const VecFx32 *to, VecFx32 *stepOut, fx32 frames);
void BTLV_EFFECT_StepScalarWithLimit(fx32 *value, fx32 *step, fx32 *limit, int *notDone);
int BTLV_EFFECT_StepMover(BtlvMover *mover, VecFx32 *out);
int BTLV_EFFECT_GetBitMask(int pos);
void BTLV_EFFECT_UpdateTexturePaletteFade(BtlvPalFade *fade);
/* END mkheaders: generated region */

#endif
