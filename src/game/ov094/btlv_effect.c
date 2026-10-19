/*
 * file:     btlv_effect.c
 * unit:     yes
 * function: BTLV_EFFECT_CreateSetup, BTLV_EFFECT_CreateSetupFromBattleMain, BTLV_EFFECT_Init, BTLV_EFFECT_Exit, BTLV_EFFECT_Main, BTLV_EFFECT_StartEffect, BTLV_EFFECT_StartEffectOnPoke, BTLV_EFFECT_StartEffectBetweenPokes, BTLV_EFFECT_StartEffectWithRequest, BTLV_EFFECT_PauseVm, BTLV_EFFECT_ResumeVm, BTLV_EFFECT_StartDamageTintTask, BTLV_EFFECT_StartPokeAppearEffect, BTLV_EFFECT_StartEffectWithColor, BTLV_EFFECT_StartEffectWithValue, BTLV_EFFECT_StartHitTask, BTLV_EFFECT_ResetPokeSprite, BTLV_EFFECT_StartPokeEffectId285, BTLV_EFFECT_StartPokeEffectId286, BTLV_EFFECT_StartPokeEffectId26E, BTLV_EFFECT_StartPokeEffectId26F, BTLV_EFFECT_IsBusy, BTLV_EFFECT_SetPokeSpriteKey, BTLV_EFFECT_DeletePokeSprite, BTLV_EFFECT_IsPokeSpriteLoaded, BTLV_EFFECT_AddPokeSprite, BTLV_EFFECT_ReleasePokeSprite, BTLV_EFFECT_GaugeInitSlotFromBattlePoke, BTLV_EFFECT_GaugeInitSlotFromPartyPoke, BTLV_EFFECT_GaugeDeleteSlot, BTLV_EFFECT_GaugeStartHpChangeAnimated, BTLV_EFFECT_GaugeStartHpChangeInstant, BTLV_EFFECT_GaugeStartExpGain, BTLV_EFFECT_GaugeRefreshForLevelUp, BTLV_EFFECT_GaugeRequestStop, BTLV_EFFECT_GaugeIsAnimating, BTLV_EFFECT_GaugeSetSideVisible, BTLV_EFFECT_GaugeSetSlotVisible, BTLV_EFFECT_GaugeSetStatusIcon, BTLV_EFFECT_GaugeSelectSlot, BTLV_EFFECT_GaugeIsSlotOccupied, BTLV_EFFECT_GaugeGetSlotHealthInfo, BTLV_EFFECT_CreatePartyBallBar, BTLV_EFFECT_DeletePartyBallBar, BTLV_EFFECT_IsPartyBallBarActive, BTLV_EFFECT_SetStageFieldTint, BTLV_EFFECT_IsStageFieldBusy, BTLV_EFFECT_SetStageLayerHidden, BTLV_EFFECT_StartPokeSpriteTransitionTask, BTLV_EFFECT_SetPokeSpriteVisible, BTLV_EFFECT_GetPokeSlot, BTLV_EFFECT_TimerStart, BTLV_EFFECT_TimerSetVisible, BTLV_EFFECT_TimerIsExpired, BTLV_EFFECT_GetPokeSpriteState, BTLV_EFFECT_StartCameraMove, BTLV_EFFECT_GetPokeSpriteCameraTarget, BTLV_EFFECT_GetWorkPtr, BTLV_EFFECT_GetCamera, BTLV_EFFECT_GetMcss, BTLV_EFFECT_GetStage, BTLV_EFFECT_GetGauge, BTLV_EFFECT_GetEffvm, BTLV_EFFECT_GetOwner, BTLV_EFFECT_GetPalanm, BTLV_EFFECT_GetClact, BTLV_EFFECT_GetBg, BTLV_EFFECT_GetMode, BTLV_EFFECT_GetCompetitorType, BTLV_EFFECT_IsMultiMode, BTLV_EFFECT_GetTrainerType, BTLV_EFFECT_GetBattleMain, BTLV_EFFECT_GetSceneUnit, BTLV_EFFECT_PollLowHpBgm, BTLV_EFFECT_StopLowHpBgm, BTLV_EFFECT_SetLowHpBgmSuppressed, BTLV_EFFECT_SaveBgmNo, BTLV_EFFECT_IsBgmSaved, BTLV_EFFECT_StopLowHpBgmAndSuppress, BTLV_EFFECT_SetVisibilityMode, BTLV_EFFECT_GetVisibilityMode, BTLV_EFFECT_SetSeSuppressed, BTLV_EFFECT_IsSeSuppressed, BTLV_EFFECT_IsRecordEnabledInComm, BTLV_EFFECT_IsRecordAllowed, BTLV_EFFECT_SetAllPokeSpriteAnim, BTLV_EFFECT_RegisterTask, BTLV_EFFECT_FindTaskIndex, BTLV_EFFECT_DeleteTask, BTLV_EFFECT_DeleteTasksByArg, BTLV_EFFECT_SetIntroState, BTLV_EFFECT_StartIntroEffect, BTLV_EFFECT_ResetIntroState, BTLV_EFFECT_SetPokeEffectValue, BTLV_EFFECT_GetPokeEffectValue, BTLV_EFFECT_SuspendVmWait, BTLV_EFFECT_ResumeVmWait, BTLV_EFFECT_FindFreeTaskSlot, BTLV_EFFECT_DeleteAllTasks, BTLV_EFFECT_VBlankTask, BTLV_EFFECT_DamageTintTaskMain, BTLV_EFFECT_ClearTaskMaskM0, BTLV_EFFECT_SequenceTaskMain, BTLV_EFFECT_ClearTaskMaskM1, BTLV_EFFECT_PokeSpriteTransitionTaskMain, BTLV_EFFECT_ClearTaskMaskM2, BTLV_EFFECT_DelayedStartEffectTaskMain, BTLV_EFFECT_FreeTaskArg, BTLV_EFFECT_UpdateIntroInput, BTLV_EFFECT_ComputeScalarStep, BTLV_EFFECT_ComputeVectorStep, BTLV_EFFECT_StepScalarWithLimit, BTLV_EFFECT_StepMover, BTLV_EFFECT_GetBitMask, BTLV_EFFECT_UpdateTexturePaletteFade
 * address:  0x021F73F0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btlv_effvm.c, btlv_b_gauge.c, btlv_bg.c, btlv_finger_cursor.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   G3D_SYSTEM_GetResourceFile 0x02046F48 arm
 *   NNS_G3dGetTex 0x0206E964 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FX_Div  0x0207C768  arm
 *   gBtlvEffectFileName     0x0220AC90  data   ov094  a1
 *   BTL_MAIN_IsMultiMode 0x021B86C8 thumb ov093
 *   BTL_MAIN_IsOwnClientSecondTeam 0x021B8FE4 thumb ov093
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   BTL_MAIN_GetOwnPartnerClient 0x021B9000 thumb ov093
 *   BTL_MAIN_GetTrainerType 0x021BA020 thumb ov093
 *   BTL_MAIN_GetOwnOpponentClient 0x021B904C thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_MAIN_GetFieldSituation 0x021B8714 thumb ov093
 *   TCB_GetTaskOffset  0x02030CB0  arm
 *   TCB_Init  0x02030CBC  arm
 *   gBtlvEff     0x0220AF20  data   a4
 *   PALANM_Create  0x02021518  thumb
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb
 *   BTL_MAIN_CheckSetupStatusFlag  0x021BA1A8  thumb  ov093
 *   ZONEDATA_GetTimeLightColors  0x0201493C  thumb
 *   G3D_SYSTEM_SetLight  0x02046A94  arm
 *   BTLV_TIMER_Create  0x02209224  thumb  ov094
 *   BTLV_BG_Create  0x0220975C  thumb  ov094
 *   PARTICLE_InitManager  0x02050B80  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   PM_VOICE_AllocBuffers  0x02006674  thumb
 *   PM_VOICE_FreeBuffers 0x020066E8 thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   BTLV_TIMER_Delete 0x022092E8 thumb ov094
 *   BTLV_BG_Delete 0x0220977C thumb ov094
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   TCB_Noop 0x02030DA4 arm
 *   TCB_Main  0x02030D28  arm
 *   G3D_SYSTEM_DrawStart  0x02047964  arm
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm
 *   PARTICLE_Main  0x02050BE8  arm
 *   G3D_SYSTEM_DrawEnd  0x02047970  arm
 *   TCB_AddTask  0x02030DA8  arm
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   d_02209D0C     0x02209D0C  data   ov094  a1
 *   BTLV_GAUGE_StartHpChangeAnimated  0x02207B4C  thumb  ov094
 *   BTLV_GAUGE_StartHpChangeInstant  0x02207B68  thumb  ov094
 *   BTLV_GAUGE_StartExpGain 0x02207B84 thumb ov094
 *   BTLV_GAUGE_RefreshForLevelUp 0x02207BAC thumb ov094
 *   BTLV_GAUGE_RequestStop 0x022089AC thumb ov094
 *   BTLV_GAUGE_IsAnimating 0x02207C94 thumb ov094
 *   BTLV_GAUGE_SetSideVisible 0x02207CC4 thumb ov094
 *   BTLV_GAUGE_SetSlotVisible  0x02207D04  thumb  ov094
 *   BTLV_GAUGE_SetStatusIcon  0x02208814  thumb  ov094
 *   BTLV_GAUGE_SelectSlot 0x02208870 thumb ov094
 *   BTLV_GAUGE_IsSlotOccupied 0x02207D60 thumb ov094
 *   BTLV_GAUGE_GetSlotHealthInfo 0x02208958 thumb ov094
 *   BTLV_B_GAUGE_CreatePartyBallBar  0x02208DAC  thumb  ov094
 *   BTLV_B_GAUGE_DeletePartyBallBar 0x02209068 thumb ov094
 *   BTLV_B_GAUGE_IsPartyBallBarActive 0x022090A4 thumb ov094
 *   PALANM_RequestFade  0x0202173C  thumb
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   BTLV_TIMER_Start 0x02209318 thumb ov094
 *   BTLV_TIMER_SetVisible  0x022094BC  thumb  ov094
 *   BTLV_TIMER_IsExpired  0x02209500  thumb ov094
 *   g_0220AF20  0x0220AF20  data
 *   BTLV_GAUGE_IsLowHpBgmPlaying 0x022088F4 thumb ov094
 *   BTLV_GAUGE_SetLowHpBgmPlaying  0x02208900  thumb  ov094
 *   BTLV_GAUGE_SetLowHpBgmSuppressed  0x0220893C  thumb  ov094
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   BTLV_GAUGE_SetSavedBgmNo  0x02208918  thumb  ov094
 *   BTLV_GAUGE_SetBgmReplaced  0x02208924  thumb  ov094
 *   BTL_MAIN_IsRecordEnabledInComm 0x021BA1EC thumb ov093
 *   BTL_MAIN_IsRecordAllowed 0x021BA20C thumb ov093
 *   TCB_DeleteTask   0x02030EAC  arm
 *   TCBL_IsDeletePending   0x02030EE8  arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   gBtlvIntroPickTableA 0x0220AC70 data a4
 *   gBtlvIntroPickTableB 0x0220AC78 data a4
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   FX_Div  0x0207C768  arm
 *   PALANM_BlendColors  0x02021F64  thumb
 *   NNS_GfdRegisterNewVramTransferTask  0x02061CA4  arm
 *   BTLV_EFFECT_IsBgmSaved 0x021F882C thumb ov094
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb ov094
 *   BTLV_EFFECT_RegisterTask 0x021F896C thumb ov094
 *   BTLV_EFFECT_DeleteTask 0x021F89BC thumb ov094
 *   BTLV_EFFECT_ComputeVectorStep 0x021F918C thumb ov094
 *   BTLV_EFFECT_StepMover  0x021F9260  thumb  ov094
 *   BTLV_STAGE_Create 0x021F6560 thumb ov094
 *   BTLV_STAGE_Delete 0x021F6898 thumb ov094
 *   BTLV_STAGE_UpdateLayerAnims 0x021F6934 thumb ov094
 *   BTLV_STAGE_DrawLayers 0x021F69B0 thumb ov094
 *   BTLV_STAGE_StartTint 0x021F69E8 thumb ov094
 *   BTLV_STAGE_IsTintActive 0x021F6A18 thumb ov094
 *   BTLV_STAGE_SetLayerHidden 0x021F6A28 thumb ov094
 *   BTLV_STAGE_IsAnyLayerArmed 0x021F6AD0 thumb ov094
 *   BTLV_FIELD_Create 0x021F6B04 thumb ov094
 *   BTLV_FIELD_Delete 0x021F6CF0 thumb ov094
 *   BTLV_FIELD_UpdateAnims 0x021F6D5C thumb ov094
 *   BTLV_FIELD_Draw 0x021F6DD4 thumb ov094
 *   BTLV_FIELD_StartTint 0x021F6DEC thumb ov094
 *   BTLV_FIELD_IsTintActive 0x021F6E1C thumb ov094
 *   BTLV_FIELD_SetHidden 0x021F6E2C thumb ov094
 *   BTLV_CAMERA_Create 0x021F6E3C thumb ov094
 *   BTLV_CAMERA_Delete 0x021F6EC0 thumb ov094
 *   BTLV_CAMERA_UpdateMove 0x021F6ED4 thumb ov094
 *   BTLV_CAMERA_SetEyeAndTarget 0x021F6EDC thumb ov094
 *   BTLV_CAMERA_StartMove 0x021F6F48 thumb ov094
 *   BTLV_EFFVM_Create 0x021F93F4 thumb ov094
 *   BTLV_EFFVM_Main 0x021F9478 thumb ov094
 *   BTLV_EFFVM_Destroy 0x021F94D8 thumb ov094
 *   BTLV_EFFVM_StartScript 0x021F94F8 thumb ov094
 *   BTLV_EFFVM_StopScript 0x021F97E4 thumb ov094
 *   BTLV_EFFVM_ClearBlockedFlag 0x021F9814 thumb ov094
 *   BTLV_EFFVM_InitParams 0x021F9844 thumb ov094
 *   BTLV_EFFVM_StartSePlayTask 0x021F9858 thumb ov094
 *   BTLV_EFFVM_StartSeVolumeTask 0x021F9948 thumb ov094
 *   BTLV_EFFVM_StopLiveSounds 0x021F9A7C thumb ov094
 *   BTLV_EFFVM_ClearLastEffect 0x021F9AA4 thumb ov094
 *   BTLV_MCSS_Create 0x021FEAC0 thumb ov094
 *   BTLV_MCSS_Delete 0x021FEB78 thumb ov094
 *   BTLV_MCSS_Update 0x021FEBAC thumb ov094
 *   BTLV_MCSS_Draw 0x021FEE9C thumb ov094
 *   BTLV_MCSS_AddPoke 0x021FEEA8 thumb ov094
 *   BTLV_MCSS_AddTrainer 0x021FF088 thumb ov094
 *   BTLV_MCSS_RemoveSprite 0x021FF0F8 thumb ov094
 *   BTLV_MCSS_SetPosition 0x021FF144 thumb ov094
 *   BTLV_MCSS_EnableOrthoMode 0x021FF16C thumb ov094
 *   BTLV_MCSS_IsVanished 0x021FF348 thumb ov094
 *   BTLV_MCSS_SetVanishMode 0x021FF374 thumb ov094
 *   BTLV_MCSS_GetSlotPosition 0x021FF3F4 thumb ov094
 *   BTLV_MCSS_SwapSprites 0x021FF7B0 thumb ov094
 *   BTLV_MCSS_StartAlphaTween 0x021FF924 thumb ov094
 *   BTLV_MCSS_StartMosaicTween 0x021FFBBC thumb ov094
 *   BTLV_MCSS_IsSpriteBusy 0x021FFCB0 thumb ov094
 *   BTLV_MCSS_IsAnySpriteBusy 0x021FFD6C thumb ov094
 *   BTLV_MCSS_IsSpriteLoaded 0x021FFD9C thumb ov094
 *   BTLV_MCSS_SetPaletteFade 0x021FFDB4 thumb ov094
 *   BTLV_MCSS_RefreshSpriteFromParty 0x021FFE48 thumb ov094
 *   BTLV_MCSS_GetSpriteAttrFlags 0x021FFF38 thumb ov094
 *   BTLV_MCSS_ReloadSpriteResource 0x022001DC thumb ov094
 *   BTLV_MCSS_StartRotation 0x02200344 thumb ov094
 *   BTLV_MCSS_MakeAddWorkFromPoke 0x022003EC thumb ov094
 *   BTLV_MCSS_SetSpriteWorkFlagForRule 0x0220055C thumb ov094
 *   BTLV_MCSS_SaveVanishStates 0x02200608 thumb ov094
 *   BTLV_CLACT_Create 0x02201A8C thumb ov094
 *   BTLV_CLACT_Delete 0x02201AC4 thumb ov094
 *   BTLV_CLACT_Draw 0x02201AF0 thumb ov094
 *   BTLV_GAUGE_Create 0x02206BC8 thumb ov094
 *   BTLV_GAUGE_Delete 0x02206E28 thumb ov094
 *   BTLV_GAUGE_FlashTaskMain 0x02206EB4 thumb ov094
 *   BTLV_GAUGE_InitSlotFromBattlePoke 0x022070C0 thumb ov094
 *   BTLV_GAUGE_InitSlotFromPartyPoke 0x02207288 thumb ov094
 *   BTLV_GAUGE_DeleteSlotTask 0x02207960 thumb ov094
 */
#include "btlv_effvm_types.h"
#include "btlv_stage_shared_types.h"
#include "btlv_field_shared_types.h"
#include "btlv_camera_shared_types.h"
#include "btlv_effect_shared_types.h"

#define REG_04000604 (*(volatile u16 *)0x04000604)

struct BtlMain;

struct BtlPokeParam;

struct ZukanSave;

/* Row of the stage table (archive 0x98 member 0), 0x24 bytes, indexed by BtlvEffFieldSituation.stageGroup. */
typedef struct BtlvEffStageRow {
    u8 hasLight;            /* 0x00: nonzero when the stage sets a light */
    u8 hasVariant;          /* 0x01: nonzero when BtlvEffFieldSituation.variant selects a stage variant */
    u8 fieldId[17];         /* 0x02: field id by stageIndex */
    u8 stageId[17];         /* 0x13: stage id by stageIndex */
} BtlvEffStageRow;

/* Light direction and color handed to G3D_SYSTEM_SetLight. */
typedef struct BtlvEffLight {
    s16 x;
    s16 y;
    s16 z;
    u16 color;
} BtlvEffLight;

/* Task record that waits for the running effects, then starts an effect script (0x14 bytes). */
typedef struct BtlvEffQueuedScript {
    int unused00;                   /* 0x00: never written or read */
    int attackerPos;                /* 0x04 */
    int defenderPos;                /* 0x08 */
    u32 scriptId;                   /* 0x0C */
    BtlvEffVmParams *params;        /* 0x10: freed with the task, 0 when the script has no parameters */
} BtlvEffQueuedScript;

/* Task record of the damage tint flicker (0x18 bytes). */
typedef struct BtlvEffDamageTintTask {
    int pos;                        /* 0x00: sprite position */
    int step;                       /* 0x04: 0 tint, 1 flash, 2 end of the cycle */
    int cyclesLeft;                 /* 0x08 */
    int wait;                       /* 0x0C: frames before the next step */
    u32 color;                      /* 0x10 */
    int skip;                       /* 0x14: nonzero leaves the sprite untouched (result of BTLV_MCSS_IsVanished) */
} BtlvEffDamageTintTask;

/* Task record of the faint animation (0x2C bytes). */
typedef struct BtlvEffHitTask {
    int pos;                        /* 0x00: sprite position */
    int step;                       /* 0x04 */
    BtlvMcssAddWork addWork;        /* 0x08: sprite resources to restore */
} BtlvEffHitTask;

/* Task record of the sprite transition (0x10 bytes). */
typedef struct BtlvEffSpriteTransitionTask {
    int step;                       /* 0x00 */
    u8 dir;                         /* 0x04: 0 when entering, 1 otherwise */
    int pos;                        /* 0x08: sprite position */
    int playSound;                  /* 0x0C */
} BtlvEffSpriteTransitionTask;

extern void *GFL_HEAP_Alloc(u32, u32, int, const char *, u16);

extern void *ARC_TOOL_LoadMember(u32, u32, u32);

extern void *G3D_SYSTEM_GetResourceFile(G3dResource *res);

extern NNSG3dResTex *NNS_G3dGetTex(void *file);

extern u32 GFL_HEAP_Free(void *p);

extern u32 GFL_HEAP_Free(void *p);

extern u32 FX_Div(u32 a, u32 b);

extern int BTL_MAIN_IsMultiMode(unsigned char **p);

extern u8 BTL_MAIN_IsOwnClientSecondTeam(u8 *p);

extern u8 BTL_MAIN_GetOwnClientId(u8 *);

extern u8 BTL_MAIN_GetOwnPartnerClient(u8 *p);

extern u16 BTL_MAIN_GetTrainerType(char *, int);

extern u8 BTL_MAIN_GetOwnOpponentClient(u8 *p, int k);

extern u32 BTL_MAIN_GetRule(void **p);

extern void *BTL_MAIN_GetCompetitor(void ***);

extern char *BTL_MAIN_GetFieldSituation(char **);

extern unsigned TCB_GetTaskOffset(unsigned);

extern struct Ctx *TCB_Init(u32 capacity, struct Ctx *c);

extern struct PalAnmSlot *PALANM_Create(u32 heap);

extern void PALANM_SetAutoTransfer(struct PalAnmSlot *palanm, int v);

extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);

extern int BTL_MAIN_CheckSetupStatusFlag(char **p, int m);

extern void ZONEDATA_GetTimeLightColors(u32 id, u32 hour, u32 minute, u32 lightTableId, u32 b0, u16 *b1, u16 heap);

extern void G3D_SYSTEM_SetLight(u32 idx, const BtlvEffLight *light);

BtlvTimer *BTLV_TIMER_Create(u16 heapId);

BtlvBg *BTLV_BG_Create(void *taskSystem, u16 heapId);

extern void PARTICLE_InitManager(u32);

extern void *GFL_USE_AddMainTask(void (*)(void *, void *), void *, int);

extern void PM_VOICE_AllocBuffers(int n, u32 heap);

extern void PM_VOICE_FreeBuffers(void);

extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);

extern u32 PALANM_Delete(void *ctx);

void BTLV_TIMER_Delete(BtlvTimer *timer);

void BTLV_BG_Delete(BtlvBg *bg);

extern void PARTICLE_ExitManager(void);

extern void TCB_DeleteTask(struct Node *n);

extern void TCB_Noop(void *);

extern void * TCB_Main(struct Ctx *c);

extern void G3D_SYSTEM_DrawStart(void);

extern void G3D_SYSTEM_ApplyLookAt(void);

extern void PARTICLE_Main(void);

extern void G3D_SYSTEM_DrawEnd(void);

extern void *TCB_AddTask(void *owner, void (*fn)(void *, void *), void *p, u32 n);

extern int WAZA_TOOL_GetDamageType(int);

void BTLV_GAUGE_StartHpChangeAnimated(BtlvGaugeWork *work, int slotIdx, int newHp);

void BTLV_GAUGE_StartHpChangeInstant(BtlvGaugeWork *work, int slotIdx, int newHp);

void BTLV_GAUGE_StartExpGain(BtlvGaugeWork *work, int slotIdx, int gain);

void BTLV_GAUGE_RefreshForLevelUp(BtlvGaugeWork *work, struct BtlPokeParam *pp, int slotIdx);

void BTLV_GAUGE_RequestStop(BtlvGaugeWork *work);

int BTLV_GAUGE_IsAnimating(BtlvGaugeWork *work);

void BTLV_GAUGE_SetSideVisible(BtlvGaugeWork *work, int visible, int side);

void BTLV_GAUGE_SetSlotVisible(BtlvGaugeWork *work, int visible, int slotIdx);

void BTLV_GAUGE_SetStatusIcon(BtlvGaugeWork *work, int status, int slotIdx);

void BTLV_GAUGE_SelectSlot(BtlvGaugeWork *work, int selectedSlot);

int BTLV_GAUGE_IsSlotOccupied(BtlvGaugeWork *work, int slotIdx);

int BTLV_GAUGE_GetSlotHealthInfo(BtlvGaugeWork *work, int slotIdx, int *hpState, int *statusAnim);

BtlvPartyBallBar *BTLV_B_GAUGE_CreatePartyBallBar(const BtlvPartyBallBarParam *param, u32 heapId);

void BTLV_B_GAUGE_DeletePartyBallBar(BtlvPartyBallBar *bar);

int BTLV_B_GAUGE_IsPartyBallBarActive(BtlvPartyBallBar *bar);

extern int PALANM_RequestFade(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);

extern u32 PALANM_GetFadeRequestBits(const char *ptr);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

void BTLV_TIMER_Start(BtlvTimer *timer, int secondsPlayer, int secondsEnemy);

void BTLV_TIMER_SetVisible(BtlvTimer *timer, int side, int visible, int restart);

int BTLV_TIMER_IsExpired(BtlvTimer *timer, int side);

unsigned int BTLV_GAUGE_IsLowHpBgmPlaying(BtlvGaugeWork *work);

void BTLV_GAUGE_SetLowHpBgmPlaying(BtlvGaugeWork *work, int playing);

void BTLV_GAUGE_SetLowHpBgmSuppressed(BtlvGaugeWork *work, int suppressed);

extern int GFL_USE_PopBgm(void);

extern void GFL_USE_CancelChangeAndPlayBgm(u32 a, u16 b);

void BTLV_GAUGE_SetSavedBgmNo(BtlvGaugeWork *work, int bgmNo);

void BTLV_GAUGE_SetBgmReplaced(BtlvGaugeWork *work, int replaced);

extern int BTL_MAIN_IsRecordEnabledInComm(char **p);

extern int BTL_MAIN_IsRecordAllowed(char **p);

extern void *TCBL_IsDeletePending(void *task);

extern void TCB_DeleteTask(struct Node *n);

extern void CLACT_VBlankSystem(void);

extern void PALANM_TransferPalettes(struct PalAnmSlot *palanm);


extern u32 KEY_GetTrg(void);

extern int TOUCHPANEL_GetTrg(void);

extern u32 GF_STANDARD_Rand(void);

extern u32 FX_Div(u32 a, u32 b);

extern void PALANM_BlendColors(u16 *src, u16 *dst, u32 count, int weight, u16 color);

extern s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32 size);

BtlvStage *BTLV_STAGE_Create(int mode, int group, int variant, u16 heap);

void BTLV_STAGE_Delete(BtlvStage *stage);

void BTLV_STAGE_UpdateLayerAnims(BtlvStage *stage);

void BTLV_STAGE_DrawLayers(BtlvStage *stage);

void BTLV_STAGE_StartTint(BtlvStage *stage, unsigned char startLevel, unsigned char targetLevel, unsigned char interval, unsigned short color);

int BTLV_STAGE_IsTintActive(BtlvStage *stage);

void BTLV_STAGE_SetLayerHidden(BtlvStage *stage, u32 side, u32 hide);

int BTLV_STAGE_IsAnyLayerArmed(BtlvStage *stage);

BtlvField *BTLV_FIELD_Create(int unused, int group, u8 variant, u16 heap);

void BTLV_FIELD_Delete(BtlvField *field);

void BTLV_FIELD_UpdateAnims(BtlvField *field);

void BTLV_FIELD_Draw(BtlvField *field);

void BTLV_FIELD_StartTint(BtlvField *field, unsigned char startLevel, unsigned char targetLevel, unsigned char interval, unsigned short color);

int BTLV_FIELD_IsTintActive(BtlvField *field);

void BTLV_FIELD_SetHidden(BtlvField *field, u32 hide);

BtlvCamera *BTLV_CAMERA_Create(void *owner, u16 heap);

void BTLV_CAMERA_Delete(BtlvCamera *camera);

void BTLV_CAMERA_UpdateMove(BtlvCamera *camera);

void BTLV_CAMERA_SetEyeAndTarget(BtlvCamera *camera, const BtlvVec3 *eye, const BtlvVec3 *target);

void BTLV_CAMERA_StartMove(BtlvCamera *camera, const BtlvVec3 *eyeDest, const BtlvVec3 *targetDest, int frames, int delay, int easeCount);

BtlvEffSetup *BTLV_EFFECT_CreateSetup(int rule, int competitor, const BtlvEffFieldSituation *situation, int isMultiMode, const u16 *trainerTypes, void *battle, int param, u16 heap);

BtlvEffSetup *BTLV_EFFECT_CreateSetupFromBattleMain(u8 *p, int a, u16 heap);

void BTLV_EFFECT_Init(BtlvEffSetup *p, void *font, u16 heap);

void BTLV_EFFECT_Exit(void);

void BTLV_EFFECT_Main(void);

void BTLV_EFFECT_StartEffect(u32 a);

void BTLV_EFFECT_StartEffectOnPoke(int a, u32 b);

void BTLV_EFFECT_StartEffectBetweenPokes(int a, int b, u32 c);

void BTLV_EFFECT_StartEffectWithRequest(const BtlvEffScriptRequest *r);

void BTLV_EFFECT_PauseVm(void);

void BTLV_EFFECT_ResumeVm(void);

void BTLV_EFFECT_StartDamageTintTask(int a, int b);

void BTLV_EFFECT_StartPokeAppearEffect(int a);

void BTLV_EFFECT_StartEffectWithColor(u32 a, u16 b, u8 c, int d, int e);

void BTLV_EFFECT_StartEffectWithValue(int a, unsigned short b);

void BTLV_EFFECT_StartHitTask(void *a, int b);

void BTLV_EFFECT_ResetPokeSprite(void *a, int b);

void BTLV_EFFECT_StartPokeEffectId285(u32 a);

void BTLV_EFFECT_StartPokeEffectId286(u32 a);

void BTLV_EFFECT_StartPokeEffectId26E(int a);

void BTLV_EFFECT_StartPokeEffectId26F(u32 a);

int BTLV_EFFECT_IsBusy(void);

void BTLV_EFFECT_SetPokeSpriteKey(void *m, int key);

void BTLV_EFFECT_DeletePokeSprite(int a);

int BTLV_EFFECT_IsPokeSpriteLoaded(int i);

void BTLV_EFFECT_AddPokeSprite(int a, u32 b, u32 c, u32 d, u32 e);

void BTLV_EFFECT_ReleasePokeSprite(int a);

void BTLV_EFFECT_GaugeInitSlotFromBattlePoke(struct BtlMain *battleMain, struct BtlPokeParam *battlePoke, u32 slotIdx);

void BTLV_EFFECT_GaugeInitSlotFromPartyPoke(struct ZukanSave *zukanSave, void *partyPoke, u32 slotIdx);

void BTLV_EFFECT_GaugeDeleteSlot(u32 a);

void BTLV_EFFECT_GaugeStartHpChangeAnimated(u32 a, u32 b);

void BTLV_EFFECT_GaugeStartHpChangeInstant(u32 a, u32 b);

void BTLV_EFFECT_GaugeStartExpGain(int index, u32 amount);

void BTLV_EFFECT_GaugeRefreshForLevelUp(int index, struct BtlPokeParam *obj);

void BTLV_EFFECT_GaugeRequestStop(void);

int BTLV_EFFECT_GaugeIsAnimating(void);

void BTLV_EFFECT_GaugeSetSideVisible(int a, int b);

void BTLV_EFFECT_GaugeSetSlotVisible(u32 a, u32 b);

void BTLV_EFFECT_GaugeSetStatusIcon(u32 a, u32 b);

void BTLV_EFFECT_GaugeSelectSlot(int sel);

int BTLV_EFFECT_GaugeIsSlotOccupied(int index);

int BTLV_EFFECT_GaugeGetSlotHealthInfo(int a, int *b, int *c);

void BTLV_EFFECT_CreatePartyBallBar(const BtlvPartyBallBarParam *p);

void BTLV_EFFECT_DeletePartyBallBar(u32 i);

int BTLV_EFFECT_IsPartyBallBarActive(u32 i);

void BTLV_EFFECT_SetStageFieldTint(u32 a, u8 b, u8 c, u8 d, u16 e);

int BTLV_EFFECT_IsStageFieldBusy(u32 a);

void BTLV_EFFECT_SetStageLayerHidden(u32 a, u32 b);

void BTLV_EFFECT_StartPokeSpriteTransitionTask(int a, int b, int c);

void BTLV_EFFECT_SetPokeSpriteVisible(u32 a, u32 b);

int BTLV_EFFECT_GetPokeSlot(int a);

void BTLV_EFFECT_TimerStart(int a, int b);

void BTLV_EFFECT_TimerSetVisible(u32 a, u32 b, u32 c);

int BTLV_EFFECT_TimerIsExpired(int i);

int BTLV_EFFECT_GetPokeSpriteState(int a);

void BTLV_EFFECT_StartCameraMove(u32 flags, int kind, int n, int s, int t);

void BTLV_EFFECT_GetPokeSpriteCameraTarget(u32 slot, BtlvVec3 *eyeOut, BtlvVec3 *basePos);

void *BTLV_EFFECT_GetWorkPtr(void);

BtlvCamera *BTLV_EFFECT_GetCamera(void);

BtlvMcssWork *BTLV_EFFECT_GetMcss(void);

BtlvStage *BTLV_EFFECT_GetStage(void);

BtlvGaugeWork *BTLV_EFFECT_GetGauge(void);

BtlvEffVmWork *BTLV_EFFECT_GetEffvm(void);

void *BTLV_EFFECT_GetOwner(void);

struct PalAnmSlot *BTLV_EFFECT_GetPalanm(void);

BtlvClact *BTLV_EFFECT_GetClact(void);

BtlvBg *BTLV_EFFECT_GetBg(void);

int BTLV_EFFECT_GetMode(void);

int BTLV_EFFECT_GetCompetitorType(void);

int BTLV_EFFECT_IsMultiMode(void);

unsigned short BTLV_EFFECT_GetTrainerType(int a);

void *BTLV_EFFECT_GetBattleMain(void);

int BTLV_EFFECT_GetSceneUnit(void);

void BTLV_EFFECT_PollLowHpBgm(void);

void BTLV_EFFECT_StopLowHpBgm(u32 a);

void BTLV_EFFECT_SetLowHpBgmSuppressed(u32 v);

void BTLV_EFFECT_SaveBgmNo(u32 v);

int BTLV_EFFECT_IsBgmSaved(void);

void BTLV_EFFECT_StopLowHpBgmAndSuppress(u32 a);

void BTLV_EFFECT_SetVisibilityMode(int a);

int BTLV_EFFECT_GetVisibilityMode(void);

void BTLV_EFFECT_SetSeSuppressed(int a);

int BTLV_EFFECT_IsSeSuppressed(void);

int BTLV_EFFECT_IsRecordEnabledInComm(void);

int BTLV_EFFECT_IsRecordAllowed(void);

void BTLV_EFFECT_SetAllPokeSpriteAnim(int a);

void BTLV_EFFECT_RegisterTask(void *task, void (*cb)(void *), int arg);

int BTLV_EFFECT_FindTaskIndex(void *h);

void BTLV_EFFECT_DeleteTask(void *task);

void BTLV_EFFECT_DeleteTasksByArg(int a);

void BTLV_EFFECT_SetIntroState(int a);

void BTLV_EFFECT_StartIntroEffect(void);

void BTLV_EFFECT_ResetIntroState(int a);

void BTLV_EFFECT_SetPokeEffectValue(int i, u32 v);

int BTLV_EFFECT_GetPokeEffectValue(int i);

void BTLV_EFFECT_SuspendVmWait(void);

void BTLV_EFFECT_ResumeVmWait(void);

int BTLV_EFFECT_FindFreeTaskSlot(void);

void BTLV_EFFECT_DeleteAllTasks(void);

void BTLV_EFFECT_VBlankTask(void *h, void *arg);

void BTLV_EFFECT_DamageTintTaskMain(void *h, void *arg);

void BTLV_EFFECT_ClearTaskMaskM0(void *h);

void BTLV_EFFECT_SequenceTaskMain(void *h, void *arg);

void BTLV_EFFECT_ClearTaskMaskM1(void *h);

void BTLV_EFFECT_PokeSpriteTransitionTaskMain(void *h, void *p);

void BTLV_EFFECT_ClearTaskMaskM2(void *h);

void BTLV_EFFECT_DelayedStartEffectTaskMain(void *h, void *arg);

void BTLV_EFFECT_FreeTaskArg(void *h);

void BTLV_EFFECT_UpdateIntroInput(void);

void BTLV_EFFECT_ComputeScalarStep(fx32 from, fx32 to, fx32 *stepOut, fx32 frames);

void BTLV_EFFECT_ComputeVectorStep(const BtlvVec3 *from, const BtlvVec3 *to, BtlvVec3 *stepOut, fx32 frames);

void BTLV_EFFECT_StepScalarWithLimit(fx32 *value, fx32 *step, fx32 *limit, int *notDone);

int BTLV_EFFECT_StepMover(BtlvMover *mover, BtlvVec3 *out);

int BTLV_EFFECT_GetBitMask(int x);

void BTLV_EFFECT_UpdateTexturePaletteFade(BtlvPalFade *fade);

BtlvEffVmWork *BTLV_EFFVM_Create(void *owner, u16 heap);

int BTLV_EFFVM_Main(BtlvEffVmWork *vm);

void BTLV_EFFVM_Destroy(BtlvEffVmWork *vm);

void BTLV_EFFVM_StartScript(BtlvEffVmWork *vm, u32 attackerPos, u32 defenderPos, u16 id, BtlvEffVmParams *q);

void BTLV_EFFVM_StopScript(BtlvEffVmWork *vm);

void BTLV_EFFVM_ClearBlockedFlag(BtlvEffVmWork *vm);

void BTLV_EFFVM_InitParams(BtlvEffVmParams *p);

void BTLV_EFFVM_StartSePlayTask(BtlvEffVmWork *vm, u32 a, int b, u32 c, int e, u32 f, int g, int h, int d);

void BTLV_EFFVM_StartSeVolumeTask(BtlvEffVmWork *vm, u32 a, int mode, int c, int x, int dest, int e, int f, int g, int duration);

void BTLV_EFFVM_StopLiveSounds(BtlvEffVmWork *vm);

void BTLV_EFFVM_ClearLastEffect(BtlvEffVmWork *vm);

BtlvMcssWork *BTLV_MCSS_Create(int rule, void *taskOwner, u16 heapId);

void BTLV_MCSS_Delete(BtlvMcssWork *w);

void BTLV_MCSS_Update(BtlvMcssWork *w);

void BTLV_MCSS_Draw(BtlvMcssWork *w);

void BTLV_MCSS_AddPoke(BtlvMcssWork *w, void *pp, int pos);

void BTLV_MCSS_AddTrainer(BtlvMcssWork *w, void *trainer, int pos);

void BTLV_MCSS_RemoveSprite(BtlvMcssWork *w, int pos);

void BTLV_MCSS_SetPosition(BtlvMcssWork *w, int pos, int x, int y, int z);

void BTLV_MCSS_EnableOrthoMode(BtlvMcssWork *w);

int BTLV_MCSS_IsVanished(BtlvMcssWork *w, int pos);

void BTLV_MCSS_SetVanishMode(BtlvMcssWork *w, int pos, int mode);

void BTLV_MCSS_GetSlotPosition(BtlvMcssWork *w, BtlvMcssVec *out, int pos);

void BTLV_MCSS_SwapSprites(BtlvMcssWork *w, int posA, int posB);

void BTLV_MCSS_StartAlphaTween(BtlvMcssWork *w, int pos, int kind, int alpha, int frames, int waitFrames, int repeat);

void BTLV_MCSS_StartMosaicTween(BtlvMcssWork *w, int pos, int kind, int mosaic, int frames, int waitFrames, int repeat);

int BTLV_MCSS_IsSpriteBusy(BtlvMcssWork *w, int pos);

int BTLV_MCSS_IsAnySpriteBusy(BtlvMcssWork *w);

int BTLV_MCSS_IsSpriteLoaded(BtlvMcssWork *w, int pos);

void BTLV_MCSS_SetPaletteFade(BtlvMcssWork *w, int pos, u8 cur, u8 target, u8 step, u32 color);

void BTLV_MCSS_RefreshSpriteFromParty(BtlvMcssWork *w, int pos, void *pp);

int BTLV_MCSS_GetSpriteAttrFlags(BtlvMcssWork *w, int pos);

void BTLV_MCSS_ReloadSpriteResource(BtlvMcssWork *w, int pos, BtlvMcssAddWork *addWork);

void BTLV_MCSS_StartRotation(BtlvMcssWork *w, int side, int dir, int playSound);

void BTLV_MCSS_MakeAddWorkFromPoke(BtlvMcssWork *w, void *pp, BtlvMcssAddWork *out, int pos);

void BTLV_MCSS_SetSpriteWorkFlagForRule(BtlvMcssWork *w, int pos, int mode);

void BTLV_MCSS_SaveVanishStates(BtlvMcssWork *w);

BtlvClact *BTLV_CLACT_Create(void *owner, u16 heap);

void BTLV_CLACT_Delete(BtlvClact *clact);

void BTLV_CLACT_Draw(void *unused);

BtlvGaugeWork *BTLV_GAUGE_Create(void *font, u16 heapId);

void BTLV_GAUGE_Delete(BtlvGaugeWork *work);

void BTLV_GAUGE_FlashTaskMain(BtlvGaugeWork *work);

void BTLV_GAUGE_InitSlotFromBattlePoke(BtlvGaugeWork *work, struct BtlMain *battleMain, struct BtlPokeParam *battlePoke, int layout, int slotIdx);

void BTLV_GAUGE_InitSlotFromPartyPoke(BtlvGaugeWork *work, struct ZukanSave *zukanSave, void *partyPoke, int layout, int slotIdx);

void BTLV_GAUGE_DeleteSlotTask(BtlvGaugeWork *work, int slotIdx);

extern const char gBtlvEffectFileName[];

extern BtlvEff *gBtlvEff;

extern u8 d_02209D0C[];

extern BtlvEff *g_0220AF20;

extern u32 gBtlvIntroPickTableA[];

extern u32 gBtlvIntroPickTableB[];

BtlvEffSetup *BTLV_EFFECT_CreateSetup(int rule, int competitor, const BtlvEffFieldSituation *situation, int isMultiMode, const u16 *trainerTypes, void *battle, int param, u16 heap)
{
    BtlvEffSetup *o;
    int i = 0;

    o = GFL_HEAP_Alloc((u16)((heap & 0x7fff) | 0x8000), 0x2c, 0, gBtlvEffectFileName, 0xca);
    o->mode = rule;
    o->competitor = competitor;
    o->situation = *situation;
    o->isMultiMode = isMultiMode;
    o->sceneUnit = param;
    o->battle = battle;
    for (; i < 4; i++)
        o->trainerType[i] = trainerTypes[i];
    return o;
}

BtlvEffSetup *BTLV_EFFECT_CreateSetupFromBattleMain(u8 *battleMain, int param, u16 heap)
{
    u16 trainerTypes[4];
    unsigned int i;
    int side, idx, other;
    int mode, type;
    BtlvEffFieldSituation *fieldSituation;
    for (i = 0; i < 4; i++) trainerTypes[i] = 0;
    if (BTL_MAIN_IsMultiMode((unsigned char **)battleMain) == 1) {
        side = BTL_MAIN_IsOwnClientSecondTeam(battleMain);
        idx = BTL_MAIN_GetOwnClientId(battleMain);
        other = BTL_MAIN_GetOwnPartnerClient(battleMain);
        trainerTypes[side * 2] = BTL_MAIN_GetTrainerType((char *)battleMain, idx);
        if (other != 4) trainerTypes[(side ^ 1) * 2] = BTL_MAIN_GetTrainerType((char *)battleMain, other);
        trainerTypes[1] = BTL_MAIN_GetTrainerType((char *)battleMain, BTL_MAIN_GetOwnOpponentClient(battleMain, 0));
        trainerTypes[3] = BTL_MAIN_GetTrainerType((char *)battleMain, BTL_MAIN_GetOwnOpponentClient(battleMain, 1));
    } else {
        trainerTypes[0] = BTL_MAIN_GetTrainerType((char *)battleMain, BTL_MAIN_GetOwnClientId(battleMain));
        trainerTypes[1] = BTL_MAIN_GetTrainerType((char *)battleMain, BTL_MAIN_GetOwnOpponentClient(battleMain, 0));
        trainerTypes[2] = 0;
        trainerTypes[3] = 0;
    }
    mode = BTL_MAIN_GetRule((void **)battleMain);
    type = (int)BTL_MAIN_GetCompetitor((void ***)battleMain);
    fieldSituation = (BtlvEffFieldSituation *)BTL_MAIN_GetFieldSituation((char **)battleMain);
    return BTLV_EFFECT_CreateSetup(mode, type, fieldSituation, BTL_MAIN_IsMultiMode((unsigned char **)battleMain), trainerTypes, battleMain, param, heap);
}

/*
 * note:     the two BTLV_FIELD_Create calls and the two f244 stores are written per arm;
 *           the compiler tail-merges them, which is what keeps the 0x194-based
 *           offsets and the reload of &gBtlvEff seen in the listing.
 */
void BTLV_EFFECT_Init(BtlvEffSetup *setup, void *font, u16 heap)
{
    BtlvEff *w;
    BtlvEffStageRow *tbl;
    u8 v;
    int i;
    BtlvEffLight r;
    u16 out[10];

    w = GFL_HEAP_Alloc(heap, sizeof(BtlvEff), 1, gBtlvEffectFileName, 0x116);
    gBtlvEff = w;
    w->setup = *setup;
    w->heap = heap;
    gBtlvEff->taskBuf = GFL_HEAP_Alloc(heap, TCB_GetTaskOffset(0x20), 1, gBtlvEffectFileName, 0x11c);
    gBtlvEff->owner = TCB_Init(0x20, gBtlvEff->taskBuf);
    gBtlvEff->effvm = BTLV_EFFVM_Create(gBtlvEff->owner, heap);
    gBtlvEff->palanm = PALANM_Create(heap);
    PALANM_SetAutoTransfer(gBtlvEff->palanm, 1);
    PALANM_AllocSlotBuffers(gBtlvEff->palanm, 0, 0x200, heap);
    PALANM_AllocSlotBuffers(gBtlvEff->palanm, 1, 0x1e0, heap);
    PALANM_AllocSlotBuffers(gBtlvEff->palanm, 2, 0x200, heap);
    PALANM_AllocSlotBuffers(gBtlvEff->palanm, 3, 0x1e0, heap);
    v = 0;
    gBtlvEff->mcss = BTLV_MCSS_Create(setup->mode, gBtlvEff->owner, heap);
    tbl = ARC_TOOL_LoadMember(0x98, 0, (u16)((gBtlvEff->heap & 0x7fff) | 0x8000));
    if (tbl[setup->situation.stageGroup].hasVariant != 0) {
        v = setup->situation.variant;
    }
    gBtlvEff->stage = BTLV_STAGE_Create(setup->mode, tbl[setup->situation.stageGroup].stageId[setup->situation.stageIndex], v, heap);
    if (gBtlvEff->setup.battle != 0) {
        gBtlvEff->field = BTLV_FIELD_Create(BTL_MAIN_CheckSetupStatusFlag(gBtlvEff->setup.battle, 0x400), tbl[setup->situation.stageGroup].fieldId[setup->situation.stageIndex], v, heap);
    } else {
        gBtlvEff->field = BTLV_FIELD_Create(0, tbl[setup->situation.stageGroup].fieldId[setup->situation.stageIndex], v, heap);
    }
    if (tbl[setup->situation.stageGroup].hasLight != 0) {
        ZONEDATA_GetTimeLightColors(setup->situation.lightArg1, setup->situation.lightArg2, setup->situation.lightArg3, setup->situation.lightArg0, setup->situation.variant, out, gBtlvEff->heap);
        r.color = out[0];
        r.x = 0;
        r.y = -0x1000;
        r.z = 0;
        G3D_SYSTEM_SetLight(0, &r);
    }
    GFL_HEAP_Free(tbl);
    gBtlvEff->camera = BTLV_CAMERA_Create(gBtlvEff->owner, heap);
    gBtlvEff->clact = BTLV_CLACT_Create(gBtlvEff->owner, heap);
    gBtlvEff->gauge = BTLV_GAUGE_Create(font, heap);
    gBtlvEff->timer = BTLV_TIMER_Create(heap);
    gBtlvEff->bg = BTLV_BG_Create(gBtlvEff->owner, heap);
    BTLV_MCSS_EnableOrthoMode(gBtlvEff->mcss);
    PARTICLE_InitManager(heap);
    for (i = 0; i < 8; i++) {
        gBtlvEff->pokeSprite[i] = -1;
    }
    if (gBtlvEff->setup.battle != 0) {
        if (BTL_MAIN_CheckSetupStatusFlag(gBtlvEff->setup.battle, 0x800)) {
            gBtlvEff->introTimerMax = 300;
        } else {
            gBtlvEff->introTimerMax = 900;
        }
    }
    gBtlvEff->vblankTask = GFL_USE_AddMainTask(BTLV_EFFECT_VBlankTask, 0, 1);
    PM_VOICE_AllocBuffers(2, gBtlvEff->heap);
}

void BTLV_EFFECT_Exit(void)
{
    if (gBtlvEff != 0) {
        PM_VOICE_FreeBuffers();
        BTLV_EFFECT_DeleteAllTasks();
        PALANM_FreeSlotBuffers(gBtlvEff->palanm, 0);
        PALANM_FreeSlotBuffers(gBtlvEff->palanm, 1);
        PALANM_FreeSlotBuffers(gBtlvEff->palanm, 2);
        PALANM_FreeSlotBuffers(gBtlvEff->palanm, 3);
        PALANM_Delete(gBtlvEff->palanm);
        BTLV_MCSS_Delete(gBtlvEff->mcss);
        BTLV_STAGE_Delete(gBtlvEff->stage);
        BTLV_FIELD_Delete(gBtlvEff->field);
        BTLV_CAMERA_Delete(gBtlvEff->camera);
        BTLV_CLACT_Delete(gBtlvEff->clact);
        BTLV_GAUGE_Delete(gBtlvEff->gauge);
        BTLV_TIMER_Delete(gBtlvEff->timer);
        BTLV_BG_Delete(gBtlvEff->bg);
        PARTICLE_ExitManager();
        BTLV_EFFVM_Destroy(gBtlvEff->effvm);
        TCB_DeleteTask(gBtlvEff->vblankTask);
        TCB_Noop(gBtlvEff->owner);
        GFL_HEAP_Free(gBtlvEff->taskBuf);
        GFL_HEAP_Free(gBtlvEff);
        gBtlvEff = 0;
    }
}

/*
 * volatile: 0x021F7980 0x021F7986 (0x04000604 read twice, results unused)
 */
void BTLV_EFFECT_Main(void)
{
    if (gBtlvEff != 0) {
        gBtlvEff->effvmActive = BTLV_EFFVM_Main(gBtlvEff->effvm);
        BTLV_EFFECT_UpdateIntroInput();
        TCB_Main(gBtlvEff->owner);
        BTLV_MCSS_Update(gBtlvEff->mcss);
        BTLV_STAGE_UpdateLayerAnims(gBtlvEff->stage);
        BTLV_FIELD_UpdateAnims(gBtlvEff->field);
        BTLV_CAMERA_UpdateMove(gBtlvEff->camera);
        BTLV_GAUGE_FlashTaskMain(gBtlvEff->gauge);
        BTLV_CLACT_Draw(gBtlvEff->clact);
        G3D_SYSTEM_DrawStart();
        G3D_SYSTEM_ApplyLookAt();
        BTLV_STAGE_DrawLayers(gBtlvEff->stage);
        BTLV_FIELD_Draw(gBtlvEff->field);
        BTLV_MCSS_Draw(gBtlvEff->mcss);
        REG_04000604;
        PARTICLE_Main();
        REG_04000604;
        G3D_SYSTEM_DrawEnd();
    }
}

void BTLV_EFFECT_StartEffect(u32 scriptId)
{
    BtlvEffQueuedScript *o;

    if (BTLV_EFFECT_IsBusy() == 0) {
        BTLV_EFFVM_StartScript(gBtlvEff->effvm, 0xff, 0xff, scriptId, 0);
        gBtlvEff->effvmActive = 1;
        return;
    }
    o = GFL_HEAP_Alloc((u16)((gBtlvEff->heap & 0x7fff) | 0x8000), 0x14, 1, gBtlvEffectFileName, 0x210);
    o->attackerPos = 0xff;
    o->defenderPos = 0xff;
    o->scriptId = scriptId;
    BTLV_EFFECT_RegisterTask(TCB_AddTask(gBtlvEff->owner, BTLV_EFFECT_DelayedStartEffectTaskMain, o, 0), BTLV_EFFECT_FreeTaskArg, 0);
}

void BTLV_EFFECT_StartEffectOnPoke(int attackerPos, u32 scriptId)
{
    BtlvEffQueuedScript *o;

    if (BTLV_EFFECT_IsBusy() == 0) {
        BTLV_EFFVM_StartScript(gBtlvEff->effvm, attackerPos, 0xff, scriptId, 0);
        gBtlvEff->effvmActive = 1;
        return;
    }
    o = GFL_HEAP_Alloc(gBtlvEff->heap, 0x14, 1, gBtlvEffectFileName, 0x22c);
    o->attackerPos = attackerPos;
    o->defenderPos = 0xff;
    o->scriptId = scriptId;
    BTLV_EFFECT_RegisterTask(TCB_AddTask(gBtlvEff->owner, BTLV_EFFECT_DelayedStartEffectTaskMain, o, 0), BTLV_EFFECT_FreeTaskArg, 0);
}

void BTLV_EFFECT_StartEffectBetweenPokes(int attackerPos, int defenderPos, u32 scriptId)
{
    BtlvEffQueuedScript *o;

    if (BTLV_EFFECT_IsBusy() == 0) {
        BTLV_EFFVM_StartScript(gBtlvEff->effvm, attackerPos, defenderPos, scriptId, 0);
        gBtlvEff->effvmActive = 1;
        return;
    }
    o = GFL_HEAP_Alloc(gBtlvEff->heap, 0x14, 1, gBtlvEffectFileName, 0x249);
    o->attackerPos = attackerPos;
    o->defenderPos = defenderPos;
    o->scriptId = scriptId;
    BTLV_EFFECT_RegisterTask(TCB_AddTask(gBtlvEff->owner, BTLV_EFFECT_DelayedStartEffectTaskMain, o, 0), BTLV_EFFECT_FreeTaskArg, 0);
}

void BTLV_EFFECT_StartEffectWithRequest(const BtlvEffScriptRequest *request)
{
    BtlvEffQueuedScript *o;
    BtlvEffVmParams l;

    if (BTLV_EFFECT_IsBusy() == 0) {
        BTLV_EFFVM_InitParams(&l);
        l.kind = request->kind;
        l.variant = request->variant;
        l.option = request->option;
        BTLV_EFFVM_StartScript(gBtlvEff->effvm, request->attackerPos, request->defenderPos, request->scriptId, &l);
        gBtlvEff->effvmActive = 1;
        return;
    }
    o = GFL_HEAP_Alloc(gBtlvEff->heap, 0x14, 1, gBtlvEffectFileName, 0x26b);
    o->params = GFL_HEAP_Alloc(gBtlvEff->heap, 0x10, 1, gBtlvEffectFileName, 0x26c);
    o->attackerPos = request->attackerPos;
    o->defenderPos = request->defenderPos;
    o->scriptId = request->scriptId;
    o->params->kind = request->kind;
    o->params->variant = request->variant;
    o->params->option = request->option;
    BTLV_EFFECT_RegisterTask(TCB_AddTask(gBtlvEff->owner, BTLV_EFFECT_DelayedStartEffectTaskMain, o, 0), BTLV_EFFECT_FreeTaskArg, 0);
}

/*
 * Calls BTLV_EFFVM_StopScript on the handle at 0x188 of the global work block, then sets the word at 0x1e8 to 0.
 */
void BTLV_EFFECT_PauseVm(void)
{
    BTLV_EFFVM_StopScript(gBtlvEff->effvm);
    gBtlvEff->effvmActive = 0;
}

/*
 * Calls BTLV_EFFVM_ClearBlockedFlag on the handle at 0x188 of the global work block, then sets the word at 0x1e8 to 1.
 */
void BTLV_EFFECT_ResumeVm(void)
{
    BTLV_EFFVM_ClearBlockedFlag(gBtlvEff->effvm);
    gBtlvEff->effvmActive = 1;
}

/*
 * witness: arm9 WAZA_TOOL_GetDamageType filed as src/matched/arm9/WAZA_TOOL_GetDamageType.c.
 */
void BTLV_EFFECT_StartDamageTintTask(int pos, int moveId)
{
    BtlvEffDamageTintTask *o;

    o = GFL_HEAP_Alloc((u16)((gBtlvEff->heap & 0x7fff) | 0x8000), 0x18, 0, gBtlvEffectFileName, 0x29b);
    o->step = 0;
    o->pos = pos;
    o->cyclesLeft = 3;
    o->wait = 0;
    o->skip = BTLV_MCSS_IsVanished(gBtlvEff->mcss, pos);
    if (WAZA_TOOL_GetDamageType(moveId) == 1)
        o->color = 0x842;
    else
        o->color = 0x6318;
    gBtlvEff->damageTintTaskMask |= BTLV_EFFECT_GetBitMask(pos);
    BTLV_EFFECT_RegisterTask(TCB_AddTask(gBtlvEff->owner, BTLV_EFFECT_DamageTintTaskMain, o, 0), BTLV_EFFECT_ClearTaskMaskM0, 0);
}

/*
 * Runs BTLV_EFFECT_StartEffectOnPoke with code 0x23b, then BTLV_EFFECT_SetPokeEffectValue with 0.
 */
void BTLV_EFFECT_StartPokeAppearEffect(int pos)
{
    BTLV_EFFECT_StartEffectOnPoke(pos, 0x23b);
    BTLV_EFFECT_SetPokeEffectValue(pos, 0);
}

void BTLV_EFFECT_StartEffectWithColor(u32 defenderPos, u16 typeCode, u8 side, int argA, int argB)
{
    BtlvEffVmParams l;

    BTLV_EFFVM_InitParams(&l);
    l.side = side;
    l.argB = argB;
    l.argA = argA;
    l.typeCode = typeCode;
    BTLV_EFFVM_StartScript(gBtlvEff->effvm, 0, defenderPos, 0x23a, &l);
    gBtlvEff->effvmActive = 1;
}

/*
 * Queues request 0x23d with value b on the handle at 0x188, then sets the word at 0x1e8 to 1.
 */
void BTLV_EFFECT_StartEffectWithValue(int defenderPos, unsigned short typeCode)
{
    BtlvEffVmParams req;

    BTLV_EFFVM_InitParams(&req);
    req.typeCode = typeCode;
    BTLV_EFFVM_StartScript(gBtlvEff->effvm, 0, defenderPos, 0x23d, (BtlvEffVmParams *)&req);
    gBtlvEff->effvmActive = 1;
}

void BTLV_EFFECT_StartHitTask(void *poke, int pos)
{
    BtlvEffHitTask *o;

    o = GFL_HEAP_Alloc((u16)((gBtlvEff->heap & 0x7fff) | 0x8000), 0x2c, 0, gBtlvEffectFileName, 0x2f9);
    o->step = 0;
    o->pos = pos;
    BTLV_MCSS_RefreshSpriteFromParty(gBtlvEff->mcss, pos, poke);
    BTLV_MCSS_MakeAddWorkFromPoke(gBtlvEff->mcss, poke, &o->addWork, pos);
    gBtlvEff->hitTaskMask |= BTLV_EFFECT_GetBitMask(pos);
    BTLV_EFFECT_RegisterTask(TCB_AddTask(gBtlvEff->owner, BTLV_EFFECT_SequenceTaskMain, o, 0), BTLV_EFFECT_ClearTaskMaskM1, 0);
}

void BTLV_EFFECT_ResetPokeSprite(void *poke, int pos)
{
    BtlvMcssAddWork buf;

    BTLV_MCSS_RefreshSpriteFromParty(gBtlvEff->mcss, pos, poke);
    BTLV_MCSS_MakeAddWorkFromPoke(gBtlvEff->mcss, poke, &buf, pos);
    BTLV_MCSS_ReloadSpriteResource(gBtlvEff->mcss, pos, &buf);
}

void BTLV_EFFECT_StartPokeEffectId285(u32 pos)
{
    BTLV_EFFECT_StartEffectOnPoke(pos, 0x285);
}

/*
 * Unlabelled tail-call stub, filed as a witness for the caller ov093 BTLV_CORE_SetMonShown (wave B3 lane 17).
 */
void BTLV_EFFECT_StartPokeEffectId286(u32 pos)
{
    BTLV_EFFECT_StartEffectOnPoke(pos, 0x286);
}

/*
 * Thumb tail call through r3 with a constant second argument. Labelled in wave D8.
 */
void BTLV_EFFECT_StartPokeEffectId26E(int pos)
{
    BTLV_EFFECT_StartEffectOnPoke(pos, 0x26E);
}

/*
 * Unlabelled tail-call stub, filed for the caller ov093 BTL_CLIENT_StepPlayEffectOnMonFast (lane S16).
 */
void BTLV_EFFECT_StartPokeEffectId26F(u32 pos)
{
    BTLV_EFFECT_StartEffectOnPoke(pos, 0x26F);
}

int BTLV_EFFECT_IsBusy(void)
{
    BtlvEff *p = gBtlvEff;
    u32 t = p->effvmActive | p->damageTintTaskMask | p->hitTaskMask | p->spriteTransitionTaskMask;

    if (t != 0)
        return 1;
    return 0;
}

/*
 * Unlabelled leaf, filed as the blocker of ov093 callers (lane S15).
 */
void BTLV_EFFECT_SetPokeSpriteKey(void *poke, int key)
{
    BTLV_MCSS_AddPoke(gBtlvEff->mcss, poke, key);
}

/*
 * Tail call to BTLV_MCSS_RemoveSprite with the handle at 0x190 of the global work block.
 */
void BTLV_EFFECT_DeletePokeSprite(int pos)
{
    BTLV_MCSS_RemoveSprite(gBtlvEff->mcss, pos);
}

int BTLV_EFFECT_IsPokeSpriteLoaded(int i)
{
    if (i < 8)
        return BTLV_MCSS_IsSpriteLoaded(gBtlvEff->mcss, i);
    if (gBtlvEff->pokeSprite[i - 8] != -1)
        return 1;
    return 0;
}

void BTLV_EFFECT_AddPokeSprite(int trainerId, u32 pos, u32 x, u32 y, u32 z)
{
    if (!(pos & 1)) {
        switch (trainerId) {
        case 0:
        case 1:
            if (BTLV_EFFECT_IsRecordEnabledInComm())
                trainerId += 4;
            break;
        case 0x3D:
            trainerId = 2;
            break;
        case 0x25:
            trainerId = 3;
            break;
        default:
            if (d_02209D0C[trainerId] == 0)
                trainerId = 0;
            else
                trainerId = 1;
            break;
        }
    } else {
        switch (trainerId) {
        case 0:
        case 1:
            if (BTLV_EFFECT_IsRecordEnabledInComm())
                trainerId += 0x67;
            break;
        }
    }
    BTLV_MCSS_AddTrainer(gBtlvEff->mcss, (void *)trainerId, pos);
    if (x != 0 || y != 0 || z != 0)
        BTLV_MCSS_SetPosition(gBtlvEff->mcss, pos, x, y, z);
    gBtlvEff->pokeSprite[pos - 8] = pos;
}

void BTLV_EFFECT_ReleasePokeSprite(int pos)
{
    BTLV_MCSS_RemoveSprite(gBtlvEff->mcss, pos);
    gBtlvEff->pokeSprite[pos - 8] = -1;
}

void BTLV_EFFECT_GaugeInitSlotFromBattlePoke(struct BtlMain *battleMain, struct BtlPokeParam *battlePoke, u32 slotIdx)
{
    switch ((u32)gBtlvEff->setup.mode) {
    case 2:
        BTLV_GAUGE_InitSlotFromBattlePoke(gBtlvEff->gauge, battleMain, battlePoke, 2, slotIdx);
        break;
    case 3:
        BTLV_GAUGE_InitSlotFromBattlePoke(gBtlvEff->gauge, battleMain, battlePoke, 3, slotIdx);
        break;
    default:
        BTLV_GAUGE_InitSlotFromBattlePoke(gBtlvEff->gauge, battleMain, battlePoke, 0, slotIdx);
        break;
    }
}

/*
 * extent: Already matched followers begin at 0x021F80E4.
 */
void BTLV_EFFECT_GaugeInitSlotFromPartyPoke(struct ZukanSave *zukanSave, void *partyPoke, u32 slotIdx)
{
    switch ((u32)gBtlvEff->setup.mode) {
    case 2:
        BTLV_GAUGE_InitSlotFromPartyPoke(gBtlvEff->gauge, zukanSave, partyPoke, 2, slotIdx);
        break;
    case 3:
        BTLV_GAUGE_InitSlotFromPartyPoke(gBtlvEff->gauge, zukanSave, partyPoke, 3, slotIdx);
        break;
    default:
        BTLV_GAUGE_InitSlotFromPartyPoke(gBtlvEff->gauge, zukanSave, partyPoke, 0, slotIdx);
        break;
    }
}

/*
 * Unlabelled leaf, filed as the blocker of ov093 callers (lane S17).
 */
void BTLV_EFFECT_GaugeDeleteSlot(u32 slotIdx)
{
    BTLV_GAUGE_DeleteSlotTask(gBtlvEff->gauge, slotIdx);
}

void BTLV_EFFECT_GaugeStartHpChangeAnimated(u32 slotIdx, u32 newHp)
{
    BTLV_GAUGE_StartHpChangeAnimated(gBtlvEff->gauge, slotIdx, newHp);
}

void BTLV_EFFECT_GaugeStartHpChangeInstant(u32 slotIdx, u32 newHp)
{
    BTLV_GAUGE_StartHpChangeInstant(gBtlvEff->gauge, slotIdx, newHp);
}

void BTLV_EFFECT_GaugeStartExpGain(int index, u32 amount)
{
    BTLV_GAUGE_StartExpGain(gBtlvEff->gauge, index, amount);
}

void BTLV_EFFECT_GaugeRefreshForLevelUp(int index, struct BtlPokeParam *obj)
{
    BTLV_GAUGE_RefreshForLevelUp(gBtlvEff->gauge, obj, index);
}

/*
 * Tail call to BTLV_GAUGE_RequestStop with the handle at 0x1a4 of the global work block.
 */
void BTLV_EFFECT_GaugeRequestStop(void)
{
    BTLV_GAUGE_RequestStop(gBtlvEff->gauge);
}

/*
 * Tail call to BTLV_GAUGE_IsAnimating with the handle at 0x1a4 of the global work block.
 */
int BTLV_EFFECT_GaugeIsAnimating(void)
{
    return BTLV_GAUGE_IsAnimating(gBtlvEff->gauge);
}

/*
 * Tail call to BTLV_GAUGE_SetSideVisible with the handle at 0x1a4 of the global work block.
 */
void BTLV_EFFECT_GaugeSetSideVisible(int visible, int side)
{
    BTLV_GAUGE_SetSideVisible(gBtlvEff->gauge, visible, side);
}

void BTLV_EFFECT_GaugeSetSlotVisible(u32 visible, u32 slotIdx)
{
    BTLV_GAUGE_SetSlotVisible(gBtlvEff->gauge, visible, slotIdx);
}

/*
 * Unlabelled leaf, filed as the blocker of ov093 BTL_CLIENT_StepStartEffectForMon (lane S15).
 */
void BTLV_EFFECT_GaugeSetStatusIcon(u32 status, u32 slotIdx)
{
    BTLV_GAUGE_SetStatusIcon(gBtlvEff->gauge, status, slotIdx);
}

void BTLV_EFFECT_GaugeSelectSlot(int sel)
{
    BTLV_GAUGE_SelectSlot(gBtlvEff->gauge, sel);
}

int BTLV_EFFECT_GaugeIsSlotOccupied(int index)
{
    return BTLV_GAUGE_IsSlotOccupied(gBtlvEff->gauge, index);
}

/*
 * Forwards three arguments to BTLV_GAUGE_GetSlotHealthInfo with the handle at 0x1a4 of the global work block.
 */
int BTLV_EFFECT_GaugeGetSlotHealthInfo(int slotIdx, int *hpState, int *statusAnim)
{
    return BTLV_GAUGE_GetSlotHealthInfo(gBtlvEff->gauge, slotIdx, hpState, statusAnim);
}

void BTLV_EFFECT_CreatePartyBallBar(const BtlvPartyBallBarParam *param)
{
    BtlvPartyBallBar *r = BTLV_B_GAUGE_CreatePartyBallBar(param, gBtlvEff->heap);

    gBtlvEff->partyBallBar[param->side] = r;
}

/*
 * Leaf blocking ov093 BTLV_SCU_ProcEntrySingleTrainer.
 */
void BTLV_EFFECT_DeletePartyBallBar(u32 i)
{
    BTLV_B_GAUGE_DeletePartyBallBar(gBtlvEff->partyBallBar[i]);
}

int BTLV_EFFECT_IsPartyBallBarActive(u32 i)
{
    return BTLV_B_GAUGE_IsPartyBallBarActive(gBtlvEff->partyBallBar[i]);
}

void BTLV_EFFECT_SetStageFieldTint(u32 scope, u8 startLevel, u8 targetLevel, u8 interval, u16 color)
{
    if (scope == 0 || scope == 2 || scope == 4)
        BTLV_STAGE_StartTint(gBtlvEff->stage, startLevel, targetLevel, interval, color);
    if (scope == 1 || scope == 2 || scope == 4)
        BTLV_FIELD_StartTint(gBtlvEff->field, startLevel, targetLevel, interval, color);
    if (scope - 3 <= 1)
        PALANM_RequestFade(gBtlvEff->palanm, 1, 0xFF00, (s8)interval, startLevel, targetLevel, color, *(void **)gBtlvEff);
}

int BTLV_EFFECT_IsStageFieldBusy(u32 scope)
{
    int x = 0;
    int y = 0;
    int z = 0;

    if (scope == 0 || scope == 2 || scope == 4)
        x = BTLV_STAGE_IsTintActive(gBtlvEff->stage);
    if (scope == 1 || scope == 2 || scope == 4)
        y = BTLV_FIELD_IsTintActive(gBtlvEff->field);
    if (scope - 3 <= 1) {
        z = PALANM_GetFadeRequestBits((const char *)gBtlvEff->palanm) != 0;
    }
    if (x == 1 || y == 1 || z == 1)
        return 1;
    return 0;
}

void BTLV_EFFECT_SetStageLayerHidden(u32 layer, u32 hide)
{
    switch (layer) {
    case 0:
        BTLV_STAGE_SetLayerHidden(gBtlvEff->stage, 2, hide);
        break;
    case 1:
        BTLV_FIELD_SetHidden(gBtlvEff->field, hide);
        break;
    case 2:
        BG_SYS_SetPlaneVisible(3, (u8)(hide ^ 1));
        break;
    case 3:
        BTLV_STAGE_SetLayerHidden(gBtlvEff->stage, 0, hide);
        break;
    case 4:
        BTLV_STAGE_SetLayerHidden(gBtlvEff->stage, 1, hide);
        break;
    }
}

void BTLV_EFFECT_StartPokeSpriteTransitionTask(int kind, int pos, int playSound)
{
    BtlvEffSpriteTransitionTask *s = GFL_HEAP_Alloc((u16)((gBtlvEff->heap & 0x7FFF) | 0x8000), 0x10, 0, gBtlvEffectFileName, 0x538);

    if (kind != 1) {
        s->step = 0;
        s->dir = (kind == 3) ? 0 : 1;
        s->pos = pos;
        s->playSound = playSound;
        gBtlvEff->spriteTransitionTaskMask |= BTLV_EFFECT_GetBitMask(pos);
        BTLV_EFFECT_RegisterTask(TCB_AddTask(gBtlvEff->owner, BTLV_EFFECT_PokeSpriteTransitionTaskMain, s, 0), BTLV_EFFECT_ClearTaskMaskM2, 0);
    }
}

void BTLV_EFFECT_SetPokeSpriteVisible(u32 posA, u32 posB)
{
    BTLV_MCSS_SwapSprites(gBtlvEff->mcss, posA, posB);
}

/*
 * Returns slot a-8 of the table at 0x1f8 of the global work block.
 */
int BTLV_EFFECT_GetPokeSlot(int pos)
{
    return gBtlvEff->pokeSprite[pos - 8];
}

/*
 * Tail call to BTLV_TIMER_Start with the handle at 0x1b0 of the global work block.
 */
void BTLV_EFFECT_TimerStart(int secondsPlayer, int secondsEnemy)
{
    BTLV_TIMER_Start(gBtlvEff->timer, secondsPlayer, secondsEnemy);
}

void BTLV_EFFECT_TimerSetVisible(u32 side, u32 visible, u32 restart)
{
    BTLV_TIMER_SetVisible(gBtlvEff->timer, side, visible, restart);
}

/*
 * Thumb tail call through r3: the work record at +0x1B0 of gBtlvEff and the argument. Labelled in wave D8.
 */
int BTLV_EFFECT_TimerIsExpired(int i)
{
    return BTLV_TIMER_IsExpired(gBtlvEff->timer, i);
}

/*
 * Tail call to BTLV_MCSS_IsVanished with the handle at 0x190 of the global work block.
 * Unlabelled; filed as a witness for the caller ov093 BTLV_CORE_SetMonShown (wave B3 lane 17).
 */
int BTLV_EFFECT_GetPokeSpriteState(int pos)
{
    return BTLV_MCSS_IsVanished(gBtlvEff->mcss, pos);
}

void BTLV_EFFECT_StartCameraMove(u32 flags, int kind, int frames, int delay, int easeCount)
{
    BtlvVec3 a;
    BtlvVec3 b;

    if (flags & 1) {
        BTLV_EFFECT_GetPokeSpriteCameraTarget(flags, &a, &b);
        switch (kind) {
        case 0:
            BTLV_CAMERA_SetEyeAndTarget(gBtlvEff->camera, &a, &b);
            break;
        case 1:
            BTLV_CAMERA_StartMove(gBtlvEff->camera, &a, &b, frames, delay, easeCount);
            break;
        }
        return;
    }
    switch (gBtlvEff->setup.mode) {
    case 0:
        BTLV_EFFECT_StartEffect(0x23F);
        break;
    case 1:
        if (flags == 2) {
            BTLV_EFFECT_StartEffect(0x240);
        } else {
            BTLV_EFFECT_StartEffect(0x241);
        }
        break;
    case 2:
        if (flags == 2) {
            BTLV_EFFECT_StartEffect(0x242);
        } else if (flags == 4) {
            BTLV_EFFECT_StartEffect(0x23F);
        } else {
            BTLV_EFFECT_StartEffect(0x243);
        }
        break;
    case 3:
        BTLV_EFFECT_StartEffect(0x245);
        break;
    }
}

void BTLV_EFFECT_GetPokeSpriteCameraTarget(u32 slot, BtlvVec3 *eyeOut, BtlvVec3 *basePos)
{
    BTLV_MCSS_GetSlotPosition(gBtlvEff->mcss, basePos, slot);
    eyeOut->x = basePos->x + 0x4B33;
    eyeOut->y = basePos->y + 0x2299;
    eyeOut->z = basePos->z + 0x99CD;
    basePos->y = basePos->y + 0x2000;
}

void *BTLV_EFFECT_GetWorkPtr(void)
{
    return g_0220AF20;
}

BtlvCamera *BTLV_EFFECT_GetCamera(void)
{
    return gBtlvEff->camera;
}

BtlvMcssWork *BTLV_EFFECT_GetMcss(void)
{
    return gBtlvEff->mcss;
}

BtlvStage *BTLV_EFFECT_GetStage(void)
{
    return gBtlvEff->stage;
}

/*
 * Returns the word at 0x1a4 of the global work block.
 */
BtlvGaugeWork *BTLV_EFFECT_GetGauge(void)
{
    return gBtlvEff->gauge;
}

/*
 * Returns the word at 0x188 of the global work block.
 */
BtlvEffVmWork *BTLV_EFFECT_GetEffvm(void)
{
    return gBtlvEff->effvm;
}

void *BTLV_EFFECT_GetOwner(void)
{
    return *(void **)g_0220AF20;
}

/*
 * Returns the word at 0x18c of the global work block.
 */
struct PalAnmSlot *BTLV_EFFECT_GetPalanm(void)
{
    return gBtlvEff->palanm;
}

/*
 * Returns the word at 0x1a0 of the global work block.
 */
BtlvClact *BTLV_EFFECT_GetClact(void)
{
    return gBtlvEff->clact;
}

/*
 * Returns the word at 0x1b4 of the global work block.
 */
BtlvBg *BTLV_EFFECT_GetBg(void)
{
    return gBtlvEff->bg;
}

int BTLV_EFFECT_GetMode(void)
{
    return gBtlvEff->setup.mode;
}

/*
 * Returns the word at 0x1c0 of the global work block.
 */
int BTLV_EFFECT_GetCompetitorType(void)
{
    return gBtlvEff->setup.competitor;
}

/*
 * Returns the multi battle flag (word at 0x1dc of the global work block).
 */
int BTLV_EFFECT_IsMultiMode(void)
{
    return gBtlvEff->setup.isMultiMode;
}

/*
 * Returns halfword a of the table at 0x1d4 of the global work block.
 */
unsigned short BTLV_EFFECT_GetTrainerType(int index)
{
    return gBtlvEff->setup.trainerType[index];
}

/*
 * Returns the word at 0x1e4 of the global work block.
 */
void *BTLV_EFFECT_GetBattleMain(void)
{
    return gBtlvEff->setup.battle;
}

/*
 * Returns the word at 0x1e0 of the global work block.
 */
int BTLV_EFFECT_GetSceneUnit(void)
{
    return gBtlvEff->setup.sceneUnit;
}

/*
 * Tail call to BTLV_GAUGE_IsLowHpBgmPlaying with the handle at 0x1a4 of the global work block.
 */
void BTLV_EFFECT_PollLowHpBgm(void)
{
    BTLV_GAUGE_IsLowHpBgmPlaying(gBtlvEff->gauge);
}

void BTLV_EFFECT_StopLowHpBgm(u32 bgmNo)
{
    if (BTLV_GAUGE_IsLowHpBgmPlaying(gBtlvEff->gauge)) {
        BTLV_GAUGE_SetLowHpBgmPlaying(gBtlvEff->gauge, 0);
        GFL_USE_PopBgm();
    }
    BTLV_GAUGE_SetLowHpBgmSuppressed(gBtlvEff->gauge, 1);
    GFL_USE_CancelChangeAndPlayBgm(bgmNo, 0xFFFF);
}

/*
 * Witness leaf for ov093 BTLV_SCU_HideMonPair: tail call (obj, v) to BTLV_GAUGE_SetLowHpBgmSuppressed.
 */
void BTLV_EFFECT_SetLowHpBgmSuppressed(u32 suppressed)
{
    BTLV_GAUGE_SetLowHpBgmSuppressed(gBtlvEff->gauge, suppressed);
}

void BTLV_EFFECT_SaveBgmNo(u32 bgmNo)
{
    gBtlvEff->bgmSaved = 1;
    BTLV_GAUGE_SetSavedBgmNo(gBtlvEff->gauge, bgmNo);
    if (BTLV_GAUGE_IsLowHpBgmPlaying(gBtlvEff->gauge) == 0)
        BTLV_GAUGE_SetBgmReplaced(gBtlvEff->gauge, 1);
}

int BTLV_EFFECT_IsBgmSaved(void)
{
    return gBtlvEff->bgmSaved;
}

void BTLV_EFFECT_StopLowHpBgmAndSuppress(u32 bgmNo)
{
    if (BTLV_GAUGE_IsLowHpBgmPlaying(gBtlvEff->gauge) == 1)
        GFL_USE_PopBgm();
    BTLV_GAUGE_SetLowHpBgmSuppressed(gBtlvEff->gauge, 1);
    BTLV_GAUGE_SetLowHpBgmPlaying(gBtlvEff->gauge, 0);
    GFL_USE_CancelChangeAndPlayBgm(bgmNo, 0x0000FFFF);
}

/*
 * Stores the low 8 bits of the argument in bits 18..25 of the word at 0x1ec of the global work block.
 */
void BTLV_EFFECT_SetVisibilityMode(int mode)
{
    gBtlvEff->visibilityMode = mode;
}

/*
 * Returns bits 18..25 of the word at 0x1ec of the global work block.
 */
int BTLV_EFFECT_GetVisibilityMode(void)
{
    return gBtlvEff->visibilityMode;
}

/*
 * Sets flag bit 26 of the word at 0x1ec of the global work block.
 */
void BTLV_EFFECT_SetSeSuppressed(int value)
{
    gBtlvEff->seSuppressed = value;
}

int BTLV_EFFECT_IsSeSuppressed(void)
{
    return gBtlvEff->seSuppressed;
}

/*
 * Returns BTL_MAIN_IsRecordEnabledInComm of the handle at 0x1e4 of the global work block, or 0 when it is null.
 */
int BTLV_EFFECT_IsRecordEnabledInComm(void)
{
    int r = 0;
    void *h = gBtlvEff->setup.battle;
    if (h != 0)
        r = BTL_MAIN_IsRecordEnabledInComm(h);
    return r;
}

/*
 * Returns BTL_MAIN_IsRecordAllowed of the handle at 0x1e4 of the global work block, or 0 when it is null.
 */
int BTLV_EFFECT_IsRecordAllowed(void)
{
    int r = 0;
    void *h = gBtlvEff->setup.battle;
    if (h != 0)
        r = BTL_MAIN_IsRecordAllowed(h);
    return r;
}

/*
 * Runs BTLV_MCSS_SetSpriteWorkFlagForRule with a (enum counter keeps the entry guard) on each of the first 8 active slots of the handle at 0x190.
 */
void BTLV_EFFECT_SetAllPokeSpriteAnim(int mode)
{
    BtlvSlotIndex i;

    for (i = 0; i < 8; i++) {
        if (BTLV_MCSS_IsSpriteLoaded(gBtlvEff->mcss, i) != 0)
            BTLV_MCSS_SetSpriteWorkFlagForRule(gBtlvEff->mcss, i, mode);
    }
}

void BTLV_EFFECT_RegisterTask(void *task, void (*cb)(void *), int arg)
{
    int i = BTLV_EFFECT_FindFreeTaskSlot();

    gBtlvEff->taskHandle[i] = task;
    gBtlvEff->taskCallback[i] = cb;
    gBtlvEff->taskArg[i] = arg;
}

int BTLV_EFFECT_FindTaskIndex(void *task)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (gBtlvEff->taskHandle[i] == task)
            break;
    }
    return i;
}

void BTLV_EFFECT_DeleteTask(void *task)
{
    int i = BTLV_EFFECT_FindTaskIndex(task);
    void *w;

    if (task == 0)
        return;
    w = TCBL_IsDeletePending(task);
    if (gBtlvEff->taskCallback[i] != 0)
        gBtlvEff->taskCallback[i](task);
    if (w != 0)
        GFL_HEAP_Free(w);
    TCB_DeleteTask(task);
    gBtlvEff->taskHandle[i] = 0;
    gBtlvEff->taskCallback[i] = 0;
}

/*
 * Runs BTLV_EFFECT_DeleteTask on each live object owned by a.
 */
void BTLV_EFFECT_DeleteTasksByArg(int arg)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (gBtlvEff->taskHandle[i] != 0 && arg == gBtlvEff->taskArg[i])
            BTLV_EFFECT_DeleteTask(gBtlvEff->taskHandle[i]);
    }
}

void BTLV_EFFECT_SetIntroState(int state)
{
    gBtlvEff->introState = state;
    if (gBtlvEff->introState != 2) {
        gBtlvEff->introPhase = 0;
        gBtlvEff->introTimer = 0;
    }
    if (state == 3)
        BTLV_MCSS_SaveVanishStates(gBtlvEff->mcss);
}

void BTLV_EFFECT_StartIntroEffect(void)
{
    BTLV_EFFECT_PauseVm();
    if (gBtlvEff->introState == 3 && BTL_MAIN_CheckSetupStatusFlag(gBtlvEff->setup.battle, 0x400))
        BTLV_EFFECT_StartEffect(0x251);
    else
        BTLV_EFFECT_StartEffect(0x236);
    gBtlvEff->introState = 0;
}

/*
 * Calls BTLV_EFFECT_PauseVm, then stores the argument at 0x238 and clears 0x23c and 0x240 of the global work block.
 */
void BTLV_EFFECT_ResetIntroState(int state)
{
    BTLV_EFFECT_PauseVm();
    gBtlvEff->introState = state;
    gBtlvEff->introPhase = 0;
    gBtlvEff->introTimer = 0;
}

void BTLV_EFFECT_SetPokeEffectValue(int i, u32 value)
{
    gBtlvEff->pokeEffectValue[i] = value;
}

int BTLV_EFFECT_GetPokeEffectValue(int i)
{
    return gBtlvEff->pokeEffectValue[i];
}

void BTLV_EFFECT_SuspendVmWait(void)
{
    BTLV_EFFVM_StopLiveSounds(gBtlvEff->effvm);
}

void BTLV_EFFECT_ResumeVmWait(void)
{
    BTLV_EFFVM_ClearLastEffect(gBtlvEff->effvm);
}

int BTLV_EFFECT_FindFreeTaskSlot(void)
{
    BtlvEff *w;
    int i;

    i = 0;
    w = gBtlvEff;
    for (; i < 32; i++) {
        if (w->taskHandle[i] == 0)
            break;
    }
    if (i == 32) {
        BTLV_EFFECT_DeleteTask(w->taskHandle[0]);
        i = 0;
    }
    return i;
}

/*
 * Runs BTLV_EFFECT_DeleteTask on each of the 32 live objects at 8 of the global work block.
 */
void BTLV_EFFECT_DeleteAllTasks(void)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (gBtlvEff->taskHandle[i] != 0)
            BTLV_EFFECT_DeleteTask(gBtlvEff->taskHandle[i]);
    }
}

/*
 * Calls CLACT_VBlankSystem, then PALANM_TransferPalettes on the handle at 0x18c of the global work block.
 */
void BTLV_EFFECT_VBlankTask(void *task, void *arg)
{
    CLACT_VBlankSystem();
    PALANM_TransferPalettes(gBtlvEff->palanm);
}

void BTLV_EFFECT_DamageTintTaskMain(void *task, void *arg)
{
    BtlvEffDamageTintTask *p = arg;

    if (p->wait != 0) {
        p->wait--;
        return;
    }
    switch (p->step) {
    case 0:
        if (p->skip == 0)
            BTLV_MCSS_SetPaletteFade(gBtlvEff->mcss, p->pos, 16, 16, 0, p->color);
        p->wait = 3;
        p->step = 1;
        break;
    case 1:
        if (p->skip == 0)
            BTLV_MCSS_SetVanishMode(gBtlvEff->mcss, p->pos, 1);
        p->wait = 3;
        p->step = 2;
        break;
    case 2:
        p->step = 0;
        if (p->skip == 0) {
            BTLV_MCSS_SetVanishMode(gBtlvEff->mcss, p->pos, 0);
            BTLV_MCSS_SetPaletteFade(gBtlvEff->mcss, p->pos, 0, 0, 0, 0x7fff);
        }
        p->wait = 3;
        if (--p->cyclesLeft == 0)
            BTLV_EFFECT_DeleteTask(task);
        break;
    }
}

/*
 * Clears the current task's mask bits from the low byte at 0x1ec of the global work block.
 */
void BTLV_EFFECT_ClearTaskMaskM0(void *tcb)
{
    BtlvEffDamageTintTask *task = TCBL_IsDeletePending(tcb);
    int m = BTLV_EFFECT_GetBitMask(task->pos);
    gBtlvEff->damageTintTaskMask &= m ^ 0xffffffff;
}

void BTLV_EFFECT_SequenceTaskMain(void *task, void *arg)
{
    BtlvEffHitTask *p = arg;

    switch (p->step) {
    case 0:
        BTLV_EFFVM_StartScript(gBtlvEff->effvm, p->pos, 0xff, 0x253, 0);
        gBtlvEff->effvmActive = 1;
        p->step++;
        break;
    case 1:
        if (gBtlvEff->effvmActive == 0) {
            if (BTLV_MCSS_GetSpriteAttrFlags(gBtlvEff->mcss, p->pos) & 1) {
                BTLV_EFFVM_StartScript(gBtlvEff->effvm, p->pos, 0xff, 0x264, 0);
                gBtlvEff->effvmActive = 1;
            }
            p->step++;
        }
        break;
    case 2:
        if (gBtlvEff->effvmActive == 0) {
            BTLV_MCSS_StartAlphaTween(gBtlvEff->mcss, p->pos, 0, 16, 0, 0, 0);
            BTLV_MCSS_StartMosaicTween(gBtlvEff->mcss, p->pos, 1, 8, 8, 1, 0);
            BTLV_EFFVM_StartSePlayTask(gBtlvEff->effvm, 0x5aa, 1, 14, -500, 127, 0, 0, 0);
            BTLV_EFFVM_StartSeVolumeTask(gBtlvEff->effvm, 1, 0, 1, 127, 0, 30, 10, 0, 0);
            p->step++;
        }
        break;
    case 3:
        if (BTLV_MCSS_IsSpriteBusy(gBtlvEff->mcss, p->pos) == 0) {
            BTLV_MCSS_ReloadSpriteResource(gBtlvEff->mcss, p->pos, &p->addWork);
            p->step++;
        }
        break;
    case 4:
        BTLV_MCSS_StartMosaicTween(gBtlvEff->mcss, p->pos, 1, 0, 8, 1, 0);
        p->step++;
        break;
    case 5:
        if (BTLV_MCSS_IsSpriteBusy(gBtlvEff->mcss, p->pos) == 0) {
            BTLV_EFFVM_StartSePlayTask(gBtlvEff->effvm, 0x560, 1, 14, 0, 0, 0, 0, 0);
            BTLV_MCSS_StartAlphaTween(gBtlvEff->mcss, p->pos, 0, 31, 0, 0, 0);
            if (BTLV_MCSS_GetSpriteAttrFlags(gBtlvEff->mcss, p->pos) & 1) {
                BTLV_EFFVM_StartScript(gBtlvEff->effvm, p->pos, 0xff, 0x265, 0);
                gBtlvEff->effvmActive = 1;
            }
            p->step++;
        }
        break;
    case 6:
        if (gBtlvEff->effvmActive == 0) {
            BTLV_EFFVM_StartScript(gBtlvEff->effvm, p->pos, 0xff, 0x254, 0);
            gBtlvEff->effvmActive = 1;
            p->step++;
        }
        break;
    case 7:
        if (gBtlvEff->effvmActive == 0)
            BTLV_EFFECT_DeleteTask(task);
        break;
    }
}

/*
 * Clears the current task's mask bits from bits 8..15 of the word at 0x1ec of the global work block.
 */
void BTLV_EFFECT_ClearTaskMaskM1(void *tcb)
{
    BtlvEffHitTask *task = TCBL_IsDeletePending(tcb);
    int m = BTLV_EFFECT_GetBitMask(task->pos);
    gBtlvEff->hitTaskMask &= m ^ 0xffffffff;
}

void BTLV_EFFECT_PokeSpriteTransitionTaskMain(void *task, void *arg)
{
    BtlvEffSpriteTransitionTask *s = arg;
    int st;
    u32 m;

    st = s->step;
    switch (st) {
    case 0:
        m = gBtlvEff->damageTintTaskMask | gBtlvEff->effvmActive | gBtlvEff->hitTaskMask;
        if (m)
            return;
        s->step = st + 1;
    case 1:
        BTLV_MCSS_StartRotation(gBtlvEff->mcss, s->pos, s->dir, s->playSound);
        s->step = s->step + 1;
        return;
    case 2:
        if (BTLV_STAGE_IsAnyLayerArmed(gBtlvEff->stage))
            return;
        if (BTLV_MCSS_IsAnySpriteBusy(gBtlvEff->mcss))
            return;
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
}

void BTLV_EFFECT_ClearTaskMaskM2(void *tcb)
{
    BtlvEffSpriteTransitionTask *task = TCBL_IsDeletePending(tcb);
    int m = BTLV_EFFECT_GetBitMask(task->pos);
    gBtlvEff->spriteTransitionTaskMask &= m ^ 0xffffffff;
}

void BTLV_EFFECT_DelayedStartEffectTaskMain(void *task, void *arg)
{
    BtlvEffQueuedScript *p = arg;

    if (BTLV_EFFECT_IsBusy() == 0) {
        BTLV_EFFVM_StartScript(gBtlvEff->effvm, p->attackerPos, p->defenderPos, p->scriptId, p->params);
        gBtlvEff->effvmActive = 1;
        BTLV_EFFECT_DeleteTask(task);
    }
}

/*
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * Frees the buffer at 0x10 of the current task's work, if any.
 */
void BTLV_EFFECT_FreeTaskArg(void *tcb)
{
    BtlvEffQueuedScript *task = TCBL_IsDeletePending(tcb);
    if (task->params != 0)
        GFL_HEAP_Free(task->params);
}

/*
 * lever: Assign table lookups to a shared local before the call; duplicated
 * calls cross-jump the indexed load and shorten the function by four bytes.
 */
void BTLV_EFFECT_UpdateIntroInput(void)
{
    int a, b;
    u32 n, value;
    a = KEY_GetTrg();
    b = TOUCHPANEL_GetTrg();
    if (gBtlvEff->introState == 0)
        return;
    if (gBtlvEff->introState != 2 && gBtlvEff->introState != 3 && (a != 0 || b != 0)) {
        BTLV_EFFECT_PauseVm();
        BTLV_EFFECT_StartEffect(0x252);
        gBtlvEff->introPhase = 0;
        gBtlvEff->introTimer = 0;
    }
    switch (gBtlvEff->introPhase) {
    case 0:
        if (gBtlvEff->introTimer < gBtlvEff->introTimerMax) {
            gBtlvEff->introTimer++;
            return;
        }
        gBtlvEff->introPhase = 1;
    case 1:
        if (BTLV_EFFECT_IsBusy() == 0) {
            if (gBtlvEff->introState == 3 && BTL_MAIN_CheckSetupStatusFlag(gBtlvEff->setup.battle, 0x400)) {
                do {
                    n = (u32)(((u64)GF_STANDARD_Rand() * 2) >> 32);
                } while (gBtlvEff->introLastPick == n);
                gBtlvEff->introLastPick = n;
                value = gBtlvIntroPickTableA[gBtlvEff->introLastPick];
            } else {
                do {
                    n = (u32)(((u64)GF_STANDARD_Rand() * 6) >> 32);
                } while (gBtlvEff->introLastPick == n);
                gBtlvEff->introLastPick = n;
                value = gBtlvIntroPickTableB[gBtlvEff->introLastPick];
            }
            BTLV_EFFECT_StartEffect(value);
            gBtlvEff->effvmActive = 1;
        }
        break;
    }
}

/*
 * Signed step from a to b in units of c (default 0x1000), at least one unit.
 */
void BTLV_EFFECT_ComputeScalarStep(fx32 from, fx32 to, fx32 *stepOut, fx32 frames)
{
    *stepOut = 0;
    if (to - from == 0)
        return;
    if (frames == 0)
        frames = 0x1000;
    *stepOut = FX_Div(to - from, frames);
    if (*stepOut == 0) {
        if (to > from)
            *stepOut = 1;
        else
            *stepOut = -1;
    }
}

void BTLV_EFFECT_ComputeVectorStep(const BtlvVec3 *from, const BtlvVec3 *to, BtlvVec3 *stepOut, fx32 frames)
{
    stepOut->x = 0;
    stepOut->y = 0;
    stepOut->z = 0;
    if (frames == 0)
        frames = 0x1000;
    if (to->x - from->x != 0) {
        stepOut->x = FX_Div(to->x - from->x, frames);
        if (stepOut->x == 0)
            stepOut->x = (to->x > from->x) ? 1 : -1;
    }
    if (to->y - from->y != 0) {
        stepOut->y = FX_Div(to->y - from->y, frames);
        if (stepOut->y == 0)
            stepOut->y = (to->y > from->y) ? 1 : -1;
    }
    if (to->z - from->z != 0) {
        stepOut->z = FX_Div(to->z - from->z, frames);
        if (stepOut->z == 0)
        {
            if (to->z > from->z)
                stepOut->z = 1;
            else
                stepOut->z = -1;
        }
    }
}

/*
 * EXACT*: inferred extent runs two bytes long; the follower is an unlabelled
 * padding pair.
 */
void BTLV_EFFECT_StepScalarWithLimit(fx32 *value, fx32 *step, fx32 *limit, int *notDone)
{
    int n = *value + *step;
    *value = n;
    if (*step < 0) {
        if (n <= *limit) {
            *value = *limit;
        } else {
            if (notDone)
                *notDone = 0;
        }
    } else {
        if (n >= *limit) {
            *value = *limit;
        } else {
            if (notDone)
                *notDone = 0;
        }
    }
}

int BTLV_EFFECT_StepMover(BtlvMover *mover, BtlvVec3 *out)
{
    int ret = 1;

    switch (mover->mode) {
    case 0:
        out->x = mover->end.x;
        out->y = mover->end.y;
        out->z = mover->end.z;
        break;
    case 1:
    case 4:
        if (mover->wait == 0) {
            mover->wait = mover->waitReset;
            BTLV_EFFECT_StepScalarWithLimit(&out->x, &mover->step.x, &mover->end.x, &ret);
            BTLV_EFFECT_StepScalarWithLimit(&out->y, &mover->step.y, &mover->end.y, &ret);
            BTLV_EFFECT_StepScalarWithLimit(&out->z, &mover->step.z, &mover->end.z, &ret);
        } else {
            mover->wait--;
            ret = 0;
        }
        break;
    case 2:
    case 3:
        if (mover->wait == 0) {
            mover->wait = mover->waitReset;
            out->x += mover->step.x;
            out->y += mover->step.y;
            out->z += mover->step.z;
            if (--mover->count == 0) {
                mover->repeat--;
                mover->count = mover->countReset;
                if (mover->mode == 2 || (mover->mode == 3 && (mover->repeat & 1))) {
                    mover->step.x *= -1;
                    mover->step.y *= -1;
                    mover->step.z *= -1;
                }
            }
        } else {
            mover->wait--;
        }
        if (mover->repeat != 0) {
            ret = 0;
        } else {
            out->x = mover->start.x;
            out->y = mover->start.y;
            out->z = mover->start.z;
        }
        break;
    }
    return ret;
}

int BTLV_EFFECT_GetBitMask(int pos)
{
    return 1 << pos;
}

void BTLV_EFFECT_UpdateTexturePaletteFade(BtlvPalFade *fade)
{
    int i;
    NNSG3dResTex *tex;
    u32 size;
    u32 vramOffset;

    if (fade->enabled != 0) {
        if (fade->wait == 0) {
            fade->wait = fade->interval;
            for (i = 0; i < fade->count; i++) {
                tex = NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile(fade->resources[i]));
                size = tex->plttInfo.sizePltt << 3;
                vramOffset = (u16)tex->plttInfo.vramKey << 3;
                PALANM_BlendColors((u16 *)((char *)tex + tex->plttInfo.ofsPlttData), fade->palettes[i], (u16)(size >> 1), fade->current, fade->color);
                NNS_GfdRegisterNewVramTransferTask((void *)1, vramOffset, (u32)fade->palettes[i], size);
            }
            if (fade->current == fade->target) {
                fade->enabled = 0;
            } else if (fade->current > fade->target) {
                fade->current = fade->current - 1;
            } else {
                fade->current = fade->current + 1;
            }
        } else {
            fade->wait = fade->wait - 1;
        }
    }
}
