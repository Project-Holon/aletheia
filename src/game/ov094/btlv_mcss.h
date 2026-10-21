#ifndef GAME_OV094_BTLV_MCSS_H
#define GAME_OV094_BTLV_MCSS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btlv_mcss.c, prototypes copied from their definitions. */

struct TcbTask;

#include "../ov094/btlv_mcss_shared_types.h"
#include "../types.h"
#include "../arm9/mcss.h"

BtlvMcssWork *BTLV_MCSS_Create(int rule, void *taskOwner, u16 heapId);
void BTLV_MCSS_Delete(BtlvMcssWork *work);
void BTLV_MCSS_Update(BtlvMcssWork *work);
void BTLV_MCSS_Draw(BtlvMcssWork *work);
void BTLV_MCSS_AddPoke(BtlvMcssWork *work, void *pp, int pos);
void BTLV_MCSS_AddTrainer(BtlvMcssWork *work, void *trainer, int pos);
void BTLV_MCSS_RemoveSprite(BtlvMcssWork *work, int pos);
void BTLV_MCSS_SetSideScale(BtlvMcssWork *work, int scaleEven, int scaleOdd);
void BTLV_MCSS_SetPosition(BtlvMcssWork *work, int pos, int x, int y, int z);
void BTLV_MCSS_EnableOrthoMode(BtlvMcssWork *work);
void BTLV_MCSS_DisableOrthoMode(BtlvMcssWork *work);
void BTLV_MCSS_EnableBillboard(BtlvMcssWork *work, int pos);
void BTLV_MCSS_DisableBillboard(BtlvMcssWork *work, int pos);
void BTLV_MCSS_SetBlinkMode(BtlvMcssWork *work, int pos, int mode);
int BTLV_MCSS_IsAnimStopped(BtlvMcssWork *work, int pos);
void BTLV_MCSS_SetAnimStopMode(BtlvMcssWork *work, int pos, int mode);
int BTLV_MCSS_IsVanished(BtlvMcssWork *work, int pos);
void BTLV_MCSS_SetVanishMode(BtlvMcssWork *work, int pos, int mode);
void BTLV_MCSS_GetSlotPosition(BtlvMcssWork *work, BtlvMcssVec *out, int pos);
void BTLV_MCSS_GetSlotPositionForRule(const BtlvMcssVec *def, BtlvMcssVec *out, int pos, int rule);
int BTLV_MCSS_GetSlotScale(BtlvMcssWork *work, int pos, int mode);
void BTLV_MCSS_SetShadowVanish(BtlvMcssWork *work, int pos, u8 vanish);
void BTLV_MCSS_SetAnimSpeed(BtlvMcssWork *work, int pos, int speed);
void BTLV_MCSS_StartPositionTween(BtlvMcssWork *work, int pos, int kind, BtlvMcssVec *target, int frames, int waitFrames, int repeat);
void BTLV_MCSS_StartShadowScaleTween(BtlvMcssWork *work, int pos, int kind, BtlvMcssVec *target, int frames, int waitFrames, int repeat);
void BTLV_MCSS_StartScaleTween(BtlvMcssWork *work, int pos, int kind, BtlvMcssVec *target, int frames, int waitFrames, int repeat);
void BTLV_MCSS_StartDrawScaleTween(BtlvMcssWork *work, int pos, int kind, BtlvMcssVec *target, int frames, int waitFrames, int repeat);
void BTLV_MCSS_StartRotateTween(BtlvMcssWork *work, int pos, int kind, BtlvMcssVec *target, int frames, int waitFrames, int repeat);
void BTLV_MCSS_SwapSprites(BtlvMcssWork *work, int posA, int posB);
void BTLV_MCSS_StartBlinkTask(BtlvMcssWork *work, int pos, int kind, int interval, int toggles);
void BTLV_MCSS_StartAlphaTween(BtlvMcssWork *work, int pos, int kind, int alpha, int frames, int waitFrames, int repeat);
void BTLV_MCSS_StartShakeTask(BtlvMcssWork *work, BtlvMcssShakeParams *params);
void BTLV_MCSS_StartBounceTask(BtlvMcssWork *work, BtlvMcssBounceParams *params);
void BTLV_MCSS_StartMosaicTween(BtlvMcssWork *work, int pos, int kind, int mosaic, int frames, int waitFrames, int repeat);
int BTLV_MCSS_IsSpriteBusy(BtlvMcssWork *work, int pos);
int BTLV_MCSS_IsAnySpriteBusy(BtlvMcssWork *work);
int BTLV_MCSS_IsSpriteLoaded(BtlvMcssWork *work, int pos);
void BTLV_MCSS_SetPaletteFade(BtlvMcssWork *work, int pos, u8 cur, u8 target, u8 step, u32 color);
void BTLV_MCSS_StartPaletteTrans(BtlvMcssWork *work, int pos, u8 level, int color);
void BTLV_MCSS_StartPaletteCopy(BtlvMcssWork *work, int pos);
void BTLV_MCSS_RefreshSpriteFromParty(BtlvMcssWork *work, int pos, void *pp);
int BTLV_MCSS_GetSpriteWeight(BtlvMcssWork *work, int pos);
int BTLV_MCSS_GetSpriteAttrFlags(BtlvMcssWork *work, int pos);
int BTLV_MCSS_HasPersonalParam10(BtlvMcssWork *work, int pos);
int BTLV_MCSS_GetStopCellFlags(BtlvMcssWork *work, int pos);
void BTLV_MCSS_SetSubstituteSprite(BtlvMcssWork *work, int pos, int showSubstitute, int setSwapped);
void BTLV_MCSS_SetMosaic(BtlvMcssWork *work, int pos, int mosaic);
void BTLV_MCSS_CopySpriteResources(BtlvMcssWork *work, int posA, int posB);
void BTLV_MCSS_ReloadSpriteResource(BtlvMcssWork *work, int pos, McssAddWork *addWork);
int BTLV_MCSS_PlayCry(BtlvMcssWork *work, int pos, int pitch, int pan, int chorusParamA, int chorusParamB, int chorusParamC);
void BTLV_MCSS_StartRotation(BtlvMcssWork *work, int side, int dir, int playSound);
int BTLV_MCSS_GetSpriteColorCode(BtlvMcssWork *work, int pos);
void BTLV_MCSS_MakeAddWorkFromPoke(BtlvMcssWork *work, void *pp, McssAddWork *out, int pos);
int BTLV_MCSS_SetAnimIndexIfValid(BtlvMcssWork *work, int pos, int animIndex);
void BTLV_MCSS_SetAnimPendingCallback(BtlvMcssWork *work, int pos);
int BTLV_MCSS_IsAnimPending(BtlvMcssWork *work, int pos);
void BTLV_MCSS_ResetSpritePosition(BtlvMcssWork *work, int pos);
void BTLV_MCSS_SetSpriteWorkFlagForRule(BtlvMcssWork *work, int pos, int mode);
int BTLV_MCSS_TakeSpriteRefreshedFlag(BtlvMcssWork *work, int pos);
void BTLV_MCSS_SaveVanishStates(BtlvMcssWork *work);
void BTLV_MCSS_RestoreVanishStates(BtlvMcssWork *work);
void BTLV_MCSS_MakeAddWorkFromTrainer(void *trainer, McssAddWork *out, int pos);
void BTLV_MCSS_ApplySlotScale(BtlvMcssWork *work, int pos);
void BTLV_MCSS_CreateTweenTask(BtlvMcssWork *work, int pos, int kind, BtlvMcssVec *from, BtlvMcssVec *to, int frames, int waitFrames, int repeat, void (*fn)(struct TcbTask *, void *), void (*endCb)(void *), int mirrorOdd, u8 serial);
void BTLV_MCSS_PositionTweenTaskMain(struct TcbTask *task, void *arg);
void BTLV_MCSS_PositionTweenTaskEnd(void *task);
void BTLV_MCSS_ShadowScaleTweenTaskMain(struct TcbTask *task, void *arg);
void BTLV_MCSS_ShadowScaleTweenTaskEnd(void *task);
void BTLV_MCSS_ScaleTweenTaskMain(struct TcbTask *task, void *arg);
void BTLV_MCSS_ScaleTweenTaskEnd(void *task);
void BTLV_MCSS_DrawScaleTweenTaskMain(struct TcbTask *task, void *arg);
void BTLV_MCSS_DrawScaleTweenTaskEnd(void *task);
void BTLV_MCSS_RotateTweenTaskMain(struct TcbTask *task, void *arg);
void BTLV_MCSS_RotateTweenTaskEnd(void *task);
void BTLV_MCSS_BlinkTaskMain(struct TcbTask *task, void *arg);
void BTLV_MCSS_BlinkTaskEnd(void *task);
void BTLV_MCSS_AlphaTweenTaskMain(struct TcbTask *task, void *arg);
void BTLV_MCSS_AlphaTweenTaskEnd(void *task);
void BTLV_MCSS_ShakeTaskMain(struct TcbTask *task, void *arg);
void BTLV_MCSS_ShakeTaskEnd(void *task);
void BTLV_MCSS_BounceTaskMain(struct TcbTask *task, void *arg);
void BTLV_MCSS_BounceTaskEnd(void *task);
void BTLV_MCSS_MosaicTweenTaskMain(struct TcbTask *task, void *arg);
void BTLV_MCSS_MosaicTweenTaskEnd(void *task);
void BTLV_MCSS_AnimWatchTaskMain(struct TcbTask *task, void *arg);
void BTLV_MCSS_RotationTaskMain(struct TcbTask *task, void *arg);
void BTLV_MCSS_RotationTaskEnd(void *task);
void BTLV_MCSS_IdleAnimCallback(int pos);
int BTLV_MCSS_CellCallbackCheckStopCell(void *ctx, void *record, void *value, int stopCell);
void BTLV_MCSS_AnimCallbackClearPending(int pos);
void BTLV_MCSS_CalcSlotPosition(BtlvMcssWork *work, BtlvMcssVec *out, int pos);
int BTLV_MCSS_CalcSlotScale(BtlvMcssWork *work, int pos, int mode);
int BTLV_MCSS_FindSpriteIndex(BtlvMcssWork *work, int pos);
int BTLV_MCSS_LookupShadowEntry(int species, int pos, BtlvMcssVec *offset, u16 *rotateZ, int *visible);
/* END mkheaders: generated region */

#endif
