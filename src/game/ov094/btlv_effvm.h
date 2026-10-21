#ifndef GAME_OV094_BTLV_EFFVM_H
#define GAME_OV094_BTLV_EFFVM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btlv_effvm.c, prototypes copied from their definitions. */

struct ScriptVm;
struct TcbTask;

#include "../types.h"
#include "../ov094/btlv_effvm_types.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"

struct ScriptVm *BTLV_EFFVM_Create(void *owner, u32 heapId);
int BTLV_EFFVM_Main(void *vm);
void BTLV_EFFVM_Destroy(void *vm);
void BTLV_EFFVM_StartScript(void *vm, u32 attackerPos, u32 defenderPos, u16 effectId, BtlvEffVmParams *params);
void BTLV_EFFVM_StopScript(void *vm);
void BTLV_EFFVM_ClearBlockedFlag(void *vm);
int BTLV_EFFVM_GetFallbackScriptFlag(void *vm);
void BTLV_EFFVM_InitParams(BtlvEffVmParams *params);
void BTLV_EFFVM_StartSePlayTask(void *vm, u32 seId, int slot, u32 pan, int pitch, u32 volume, int modDepth, int modSpeed, int delay);
void BTLV_EFFVM_StartSeVolumeTask(void *vm, u32 slot, int mode, int param, int from, int to, int startDelay, int stepCount, int framesPerStep, int duration);
void BTLV_EFFVM_StopLiveSounds(void *vm);
void BTLV_EFFVM_ClearLastEffect(void *vm);
int BTLV_EFFVM_CmdSetupCamera(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdMoveCameraTo(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdRotateCameraOrbit(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdMoveCameraEased(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetBillboardMode(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSaveCameraPosition(int vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdLoadParticleResource(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartParticleEffect(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartParticleEffectFixedPos(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartParticleEffectTargeted(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartParticleEffectForEachInstance(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdDeleteParticleEmitter(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartParticleEffectOffset(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartParticleEffectConstOffset(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartParticleEffectTargetedOffset(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartParticleEffectTargetedConstOffset(struct ScriptVm *vm, BtlvEffVmWork *work);
void BTLV_EFFVM_ParticleInitCallbackSource(void *vm, void *work);
void BTLV_EFFVM_ParticleInitCallbackTarget(void *vm, void *work);
int BTLV_EFFVM_CmdStartPokePositionTween(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartPokeShake(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartPokeBounce(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartPokeShadowScaleTween(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartPokeRotateTween(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartPokeAlphaTween(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartPokeMosaicTween(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartPokeBlink(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetPokeAnimStop(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetPokePaletteFade(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetPokeVanish(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetPokeShadowVanish(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartPokeShadowScaleTweenSecondary(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdDeletePokeSprites(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdAddPokeSprite(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetPokePosition(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetPokeAnimIndex(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdReleasePokeSprite(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdLoadBgPalette(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartBgScroll(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdNop4(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdNop5(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetBgLayerEnable(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetBlendRegister(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetStageFieldTint(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetStageLayerHidden(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartFadeTask(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdLoadClactAtPoke(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartClactPosTween(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartClactScaleTween(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetClactAnim(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdFadeClactPalette(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdReleaseClact(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetGaugeVisibility(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdPlaySe(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStopSe(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartSeVolumeTween(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartSeVolumeTask(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdWaitFrames(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdWaitParticles(struct ScriptVm *vm, BtlvEffVmWork *work);
void BTLV_EFFVM_CmdSetResult(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdJumpIf(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdJumpIfCondCompare(struct ScriptVm *vm, BtlvEffVmWork *work);
void BTLV_EFFVM_CompareAndJump(struct ScriptVm *vm, int lhs, int rhs, int op, int off);
int BTLV_EFFVM_CmdJumpIfPokeLoaded(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetScriptVar(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdEvalCondition(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetParam(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetPokeCellFlag(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdCopyPokeSpriteState(int vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartPokeCry(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetTypeSource(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdLoadClactFromPoke(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdCallScript(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdReturnScript(int vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdJumpScript(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdWaitForTask(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdJumpToArchiveScript(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdStartWaitTask(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_CmdSetPokeSpriteAnimMode(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_ReleaseScriptResources(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_IsAllIdle(int vm, BtlvEffVmWork *work);
int BTLV_EFFVM_WaitFramesCallback(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_WaitTaskCallback(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_WaitParticleCallback(struct ScriptVm *vm, BtlvEffVmWork *work);
int BTLV_EFFVM_ResolveBattlerList(BtlvEffVmWork *work, int cmd, int *out);
int BTLV_EFFVM_ResolveBattlerListExpanded(BtlvEffVmWork *work, int unused, int *out);
int BTLV_EFFVM_ResolveSlotKey(struct ScriptVm *vm, int idx);
int BTLV_EFFVM_ResolveSide(BtlvEffVmWork *work, int pos);
int BTLV_EFFVM_ResolveSideFromVm(struct ScriptVm *vm, int pos);
int BTLV_EFFVM_ResolveAnchorSlot(struct ScriptVm *vm, int *out);
int BTLV_EFFVM_AllocEmitterSlot(BtlvEffVmWork *work, int key, int *out);
void BTLV_EFFVM_SetEmitterHandle(BtlvEffVmWork *work, int slot, BtlvEffVmParticleResHeader *resource);
int BTLV_EFFVM_FindEmitterSlot(BtlvEffVmWork *work, int key);
int BTLV_EFFVM_GetEmitterHandle(BtlvEffVmWork *work, int slot);
void BTLV_EFFVM_ParticleStartCallback(void *emitter);
void BTLV_EFFVM_ParticleMotionStep(void *emitter, int active);
void BTLV_EFFVM_EmitterInitCallback(void *emitter);
void BTLV_EFFVM_EmitterMoveCallbackB(void *emitter, int active);
void BTLV_EFFVM_DeleteEmitter(void *emitter);
void BTLV_EFFVM_RefreshMcssOrtho(BtlvEffVmWork *work);
void BTLV_EFFVM_PlaySeWithParams(u32 seId, int slot, int pan, int pitch, unsigned int volume, unsigned int modDepth, unsigned int modSpeed);
int BTLV_EFFVM_EvalCondition(BtlvEffVmWork *work, unsigned int key);
void BTLV_EFFVM_StartParticleEffectInternal(BtlvEffVmWork *work, BtlvEffVmParticleReq *req, int slot, int arg);
int BTLV_EFFVM_SetupEmitterCallbacks(void *vm, BtlvEffVmWork *work, int mode);
void BTLV_EFFVM_TransformVecByMtx44(VecFx32 *pos, const VecFx32 *ofs);
void BTLV_EFFVM_TransformVecByMtx43(const VecFx32 *vec, const MtxFx44 *matrix, fx32 *out, fx32 *clipW);
unsigned int BTLV_EFFVM_ResolveParticleKey(BtlvEffVmWork *work, unsigned int key);
void BTLV_EFFVM_StartSeVolumeTweenTask(BtlvEffVmWork *work, int fromLevel, int toLevel, int steps);
int BTLV_EFFVM_FindFreeSeSlot(BtlvEffVmWork *work);
void BTLV_EFFVM_ResetPokePositionIfLoaded(void *unused);
void BTLV_EFFVM_SetShadowVanishIfLoaded(void *unused);
void BTLV_EFFVM_SePlayTaskMain(struct TcbTask *task, void *arg);
void BTLV_EFFVM_SePlayTaskEnd(void *task);
void BTLV_EFFVM_SeVolumeTweenTaskMain(struct TcbTask *task, void *arg);
void BTLV_EFFVM_SeVolumeTweenTaskEnd(void *task);
void BTLV_EFFVM_SeModulationTaskMain(struct TcbTask *task, void *arg);
void BTLV_EFFVM_SeModulationTaskEnd(void *task);
void BTLV_EFFVM_DelayTaskMain(struct TcbTask *task, void *arg);
void BTLV_EFFVM_BlendRegisterTaskMain(struct TcbTask *task, void *arg);
void BTLV_EFFVM_BlendRegisterTaskEnd(void *task);
void BTLV_EFFVM_WaitVoiceTaskMain(struct TcbTask *task, void *arg);
void BTLV_EFFVM_MultiPokeTaskMain(struct TcbTask *task, void *arg);
void BTLV_EFFVM_ParticleLoadTaskMain(struct TcbTask *task, void *arg);
void BTLV_EFFVM_SpriteCleanupTaskMain(fx32 scaleEven, fx32 scaleOdd, int frames, int waitFrames, int repeats);
int BTLV_EFFVM_IsMultiSideResourceId(int effectId);
/* END mkheaders: generated region */

#endif
