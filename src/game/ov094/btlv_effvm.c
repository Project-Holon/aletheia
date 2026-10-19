/*
 * file:     btlv_effvm.c
 * unit:     yes
 * function: BTLV_EFFVM_Create, BTLV_EFFVM_Main, BTLV_EFFVM_Destroy, BTLV_EFFVM_StartScript, BTLV_EFFVM_StopScript, BTLV_EFFVM_ClearBlockedFlag, BTLV_EFFVM_GetFallbackScriptFlag, BTLV_EFFVM_InitParams, BTLV_EFFVM_StartSePlayTask, BTLV_EFFVM_StartSeVolumeTask, BTLV_EFFVM_StopLiveSounds, BTLV_EFFVM_ClearLastEffect, BTLV_EFFVM_CmdSetupCamera, BTLV_EFFVM_CmdMoveCameraTo, BTLV_EFFVM_CmdRotateCameraOrbit, BTLV_EFFVM_CmdMoveCameraEased, BTLV_EFFVM_CmdSetBillboardMode, BTLV_EFFVM_CmdSaveCameraPosition, BTLV_EFFVM_CmdLoadParticleResource, BTLV_EFFVM_CmdStartParticleEffect, BTLV_EFFVM_CmdStartParticleEffectFixedPos, BTLV_EFFVM_CmdStartParticleEffectTargeted, BTLV_EFFVM_CmdStartParticleEffectForEachInstance, BTLV_EFFVM_CmdDeleteParticleEmitter, BTLV_EFFVM_CmdStartParticleEffectOffset, BTLV_EFFVM_CmdStartParticleEffectConstOffset, BTLV_EFFVM_CmdStartParticleEffectTargetedOffset, BTLV_EFFVM_CmdStartParticleEffectTargetedConstOffset, BTLV_EFFVM_ParticleInitCallbackSource, BTLV_EFFVM_ParticleInitCallbackTarget, BTLV_EFFVM_CmdStartPokePositionTween, BTLV_EFFVM_CmdStartPokeShake, BTLV_EFFVM_CmdStartPokeBounce, BTLV_EFFVM_CmdStartPokeShadowScaleTween, BTLV_EFFVM_CmdStartPokeRotateTween, BTLV_EFFVM_CmdStartPokeAlphaTween, BTLV_EFFVM_CmdStartPokeMosaicTween, BTLV_EFFVM_CmdStartPokeBlink, BTLV_EFFVM_CmdSetPokeAnimStop, BTLV_EFFVM_CmdSetPokePaletteFade, BTLV_EFFVM_CmdSetPokeVanish, BTLV_EFFVM_CmdSetPokeShadowVanish, BTLV_EFFVM_CmdStartPokeShadowScaleTweenSecondary, BTLV_EFFVM_CmdDeletePokeSprites, BTLV_EFFVM_CmdAddPokeSprite, BTLV_EFFVM_CmdSetPokePosition, BTLV_EFFVM_CmdSetPokeAnimIndex, BTLV_EFFVM_CmdReleasePokeSprite, BTLV_EFFVM_CmdLoadBgPalette, BTLV_EFFVM_CmdStartBgScroll, BTLV_EFFVM_CmdNop4, BTLV_EFFVM_CmdNop5, BTLV_EFFVM_CmdSetBgLayerEnable, BTLV_EFFVM_CmdSetBlendRegister, BTLV_EFFVM_CmdSetStageFieldTint, BTLV_EFFVM_CmdSetStageLayerHidden, BTLV_EFFVM_CmdStartFadeTask, BTLV_EFFVM_CmdLoadClactAtPoke, BTLV_EFFVM_CmdStartClactPosTween, BTLV_EFFVM_CmdStartClactScaleTween, BTLV_EFFVM_CmdSetClactAnim, BTLV_EFFVM_CmdFadeClactPalette, BTLV_EFFVM_CmdReleaseClact, BTLV_EFFVM_CmdSetGaugeVisibility, BTLV_EFFVM_CmdPlaySe, BTLV_EFFVM_CmdStopSe, BTLV_EFFVM_CmdStartSeVolumeTween, BTLV_EFFVM_CmdStartSeVolumeTask, BTLV_EFFVM_CmdWaitFrames, BTLV_EFFVM_CmdWaitParticles, BTLV_EFFVM_CmdSetResult, BTLV_EFFVM_CmdJumpIf, BTLV_EFFVM_CmdJumpIfCondCompare, BTLV_EFFVM_CompareAndJump, BTLV_EFFVM_CmdJumpIfPokeLoaded, BTLV_EFFVM_CmdSetScriptVar, BTLV_EFFVM_CmdEvalCondition, BTLV_EFFVM_CmdSetParam, BTLV_EFFVM_CmdSetPokeCellFlag, BTLV_EFFVM_CmdCopyPokeSpriteState, BTLV_EFFVM_CmdStartPokeCry, BTLV_EFFVM_CmdSetTypeSource, BTLV_EFFVM_CmdLoadClactFromPoke, BTLV_EFFVM_CmdCallScript, BTLV_EFFVM_CmdReturnScript, BTLV_EFFVM_CmdJumpScript, BTLV_EFFVM_CmdWaitForTask, BTLV_EFFVM_CmdJumpToArchiveScript, BTLV_EFFVM_CmdStartWaitTask, BTLV_EFFVM_CmdSetPokeSpriteAnimMode, BTLV_EFFVM_ReleaseScriptResources, BTLV_EFFVM_IsAllIdle, BTLV_EFFVM_WaitFramesCallback, BTLV_EFFVM_WaitTaskCallback, BTLV_EFFVM_WaitParticleCallback, BTLV_EFFVM_ResolveBattlerList, BTLV_EFFVM_ResolveBattlerListExpanded, BTLV_EFFVM_ResolveSlotKey, BTLV_EFFVM_ResolveSide, BTLV_EFFVM_ResolveSideFromVm, BTLV_EFFVM_ResolveAnchorSlot, BTLV_EFFVM_AllocEmitterSlot, BTLV_EFFVM_SetEmitterHandle, BTLV_EFFVM_FindEmitterSlot, BTLV_EFFVM_GetEmitterHandle, BTLV_EFFVM_ParticleStartCallback, BTLV_EFFVM_ParticleMotionStep, BTLV_EFFVM_EmitterInitCallback, BTLV_EFFVM_EmitterMoveCallbackB, BTLV_EFFVM_DeleteEmitter, BTLV_EFFVM_RefreshMcssOrtho, BTLV_EFFVM_PlaySeWithParams, BTLV_EFFVM_EvalCondition, BTLV_EFFVM_StartParticleEffectInternal, BTLV_EFFVM_SetupEmitterCallbacks, BTLV_EFFVM_TransformVecByMtx44, BTLV_EFFVM_TransformVecByMtx43, BTLV_EFFVM_ResolveParticleKey, BTLV_EFFVM_StartSeVolumeTweenTask, BTLV_EFFVM_FindFreeSeSlot, BTLV_EFFVM_ResetPokePositionIfLoaded, BTLV_EFFVM_SetShadowVanishIfLoaded, BTLV_EFFVM_SePlayTaskMain, BTLV_EFFVM_SePlayTaskEnd, BTLV_EFFVM_SeVolumeTweenTaskMain, BTLV_EFFVM_SeVolumeTweenTaskEnd, BTLV_EFFVM_SeModulationTaskMain, BTLV_EFFVM_SeModulationTaskEnd, BTLV_EFFVM_DelayTaskMain, BTLV_EFFVM_BlendRegisterTaskMain, BTLV_EFFVM_BlendRegisterTaskEnd, BTLV_EFFVM_WaitVoiceTaskMain, BTLV_EFFVM_MultiPokeTaskMain, BTLV_EFFVM_ParticleLoadTaskMain, BTLV_EFFVM_SpriteCleanupTaskMain, BTLV_EFFVM_IsMultiSideResourceId
 * address:  0x021F93F4
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
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   FX_Div  0x0207C768  arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   TCB_AddTask  0x02030DA8  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   TCBL_IsDeletePending   0x02030EE8  arm
 *   d_0220AE68     0x0220AE68  data   ov094  a1
 *   d_02209DCC     0x02209DCC  data   ov094  a4
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   VM_Create  0x0201121C  thumb
 *   VM_Init  0x0201126C  thumb
 *   VM_Control  0x02011298  thumb
 *   VM_GetContext  0x02011324  thumb
 *   VM_Delete 0x02011264 thumb
 *   VM_Start  0x0201127C  thumb
 *   MIi_CpuClear16  0x02082A48  arm
 *   PM_VOICE_StopSlot 0x02006BB4 thumb
 *   VM_GetU32  0x0201134C  thumb
 *   d_0220ACA0  0x0220ACA0  data  a4
 *   d_0220ACE8  0x0220ACE8  data  a4
 *   d_0220AD00  0x0220AD00  data  a4
 *   d_0220AD78  0x0220AD78  data  a4
 *   d_0220ADA8  0x0220ADA8  data  a4
 *   d_0220ADD8  0x0220ADD8  data  a4
 *   d_0220AE20  0x0220AE20  data  a4
 *   VEC_Add  0x0207C9D0  arm
 *   VM_SetWait 0x020113D0 thumb
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   PARTICLE_CreateSystem 0x02050C30 arm
 *   PARTICLE_SetupSystemNoHandlers 0x02051380 arm
 *   PARTICLE_StartEffectWithCallback 0x020515CC arm
 *   PARTICLE_InitCamera 0x02051648 arm
 *   PARTICLE_EMITTER_GetBlock 0x02051788 arm
 *   d_02209E1C 0x02209E1C data a4
 *   d_02209D90 0x02209D90 data a4
 *   d_02209D78 0x02209D78 data a4
 *   d_02209E04 0x02209E04 data a4
 *   d_02209DC0 0x02209DC0 data ov094 a4
 *   d_02209D84 0x02209D84 data ov094 a4
 *   d_02209DA8 0x02209DA8 data ov094 a4
 *   d_02209D9C 0x02209D9C data ov094 a4
 *   BG_SYS_SetPriority  0x0204047C  arm
 *   ARC_UTIL_UploadBgCharFromArchive  0x02049624  arm
 *   ARC_UTIL_UploadBgPaletteFromArchive  0x0204989C  arm
 *   PALANM_LoadArcPaletteToSlotAt  0x020215EC  thumb
 *   BG_SYS_GetScrollX  0x020407E8  arm
 *   BG_SYS_GetScrollY  0x02040804  arm
 *   BTLV_BG_SetScroll  0x02209784  thumb  ov094
 *   BTLV_BG_StartScroll  0x022097CC  thumb  ov094
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   NNS_G3dWorldPosToScrPos  0x0206DF3C  arm
 *   BTLV_GAUGE_PlaceSlot  0x022079C0  thumb  ov094
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   GFL_USE_StopSeSlot 0x020061F8 thumb
 *   VM_Jump  0x020113B0  thumb
 *   PALANM_GetPairedCodeForFirst  0x0202142C  thumb
 *   VM_Call 0x020113B4 thumb
 *   VM_Return  0x020113C4  thumb
 *   VM_End 0x02011290 thumb
 *   BTLV_SCU_ReloadGraphics 0x021EB2A8 thumb ov093
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   BTLV_BG_IsScrolling 0x0220985C thumb ov094
 *   PARTICLE_GetEffectCount 0x02051614 arm
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   GFL_USE_IsSeSlotBusy 0x02006224 thumb
 *   PM_VOICE_IsSlotActive 0x02006BD0 thumb
 *   d_02209E58 0x02209E58 data a4
 *   d_02209E28 0x02209E28 data ov094 a4
 *   d_0220AD18 0x0220AD18 data ov094 a4
 *   d_0220AD38 0x0220AD38 data ov094 a4
 *   d_0220AD58     0x0220AD58  data   ov094
 *   PARTICLE_GetCallbackArg 0x02051774 arm
 *   PARTICLE_EMITTER_SetUserData 0x02051A2C arm
 *   PARTICLE_EMITTER_SetCallback 0x02051A24 arm
 *   VEC_Distance 0x0207CF3C arm
 *   VEC_Normalize 0x0207CCA4 arm
 *   VEC_DotProduct 0x0207CA68 arm
 *   FX_AcosIdx 0x0207D184 arm
 *   VEC_CrossProduct 0x0207CAE8 arm
 *   MTX_RotAxis43 0x0207B65C arm
 *   MTX_MultVec43 0x0207BC08 arm
 *   PARTICLE_EMITTER_SetBehavior2Data 0x020519C4 arm
 *   PARTICLE_EMITTER_SetBehavior5Data 0x02051A04 arm
 *   PARTICLE_EMITTER_GetRot 0x020517B4 arm
 *   PARTICLE_EMITTER_SetBehavior3Half 0x020519E4 arm
 *   PARTICLE_EMITTER_SetRot 0x02051880 arm
 *   PARTICLE_EMITTER_GetScaleX 0x020517D0 arm
 *   PARTICLE_EMITTER_GetAlpha 0x02051830 arm
 *   PARTICLE_EMITTER_GetAngle 0x02051820 arm
 *   PARTICLE_EMITTER_GetScaleY 0x020517E0 arm
 *   PARTICLE_EMITTER_SetScaleX 0x020517D8 arm
 *   PARTICLE_EMITTER_SetScaleY 0x020517E8 arm
 *   PARTICLE_EMITTER_SetAlpha 0x020518A4 arm
 *   PARTICLE_EMITTER_SetAngle 0x0205189C arm
 *   PARTICLE_EMITTER_GetPos 0x02051790 arm
 *   PARTICLE_EMITTER_SetPos 0x020517A4 arm
 *   PARTICLE_EMITTER_GetOffsetX 0x020517F0 arm
 *   PARTICLE_EMITTER_SetOffsetX 0x02051800 arm
 *   PARTICLE_EMITTER_GetOffsetY 0x02051808 arm
 *   PARTICLE_EMITTER_SetOffsetY 0x02051818 arm
 *   PARTICLE_EMITTER_SetEmitPos 0x02051838 arm
 *   PARTICLE_EMITTER_GetUserData  0x02051A34  arm
 *   PARTICLE_GetWorkBase  0x02051640  arm
 *   PARTICLE_DeleteSystem  0x02050DB8  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_PlaySeInSlot  0x0200616C  thumb
 *   GFL_USE_GetSeHandle  0x02006138  thumb
 *   GFL_USE_SetSeSlotParams  0x02006268  thumb
 *   NNS_SndHandleSetVolume  0x02072F34  arm
 *   NNS_SndHandleSetTrackModDepth  0x02073058  arm
 *   NNS_SndHandleSetTrackModSpeed  0x02073078  arm
 *   d_02209E10 0x02209E10 data
 *   d_02209DB4 0x02209DB4 data
 *   MTX_Copy43To44_  0x0207B5C0  arm
 *   MTX_Concat44     0x0207BE14  arm
 *   g_renderStateDrawParams       0x02148B98  data
 *   SCREENTEX_ProjectionMatrix       0x02148B54  data
 *   GFL_NET_SetBgmTrackVolumeUnlessVoiceChat  0x0200F698  thumb
 *   PARTICLE_ApplyLoadHandlers  0x02051394  arm
 *   d_02209DD8  0x02209DD8  data  ov094
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   BTLV_EFFECT_RegisterTask 0x021F896C thumb ov094
 *   BTLV_EFFECT_DeleteTask 0x021F89BC thumb ov094
 *   BTLV_CAMERA_SetEyeAndTarget 0x021F6EDC thumb ov094
 *   BTLV_CAMERA_RotateOrbit 0x021F6F20 thumb ov094
 *   BTLV_CAMERA_StartMove 0x021F6F48 thumb ov094
 *   BTLV_CAMERA_StartMoveWithEasing 0x021F7000 thumb ov094
 *   BTLV_CAMERA_GetEyeAndTarget 0x021F70F0 thumb ov094
 *   BTLV_CAMERA_AdvanceOrbitEye 0x021F7108 thumb ov094
 *   BTLV_CAMERA_GetDefaultEyeAndTarget 0x021F7208 thumb ov094
 *   BTLV_CAMERA_IsMoving 0x021F722C thumb ov094
 *   BTLV_EFFECT_DeletePokeSprite 0x021F7F04 thumb ov094
 *   BTLV_EFFECT_IsPokeSpriteLoaded 0x021F7F1C thumb ov094
 *   BTLV_EFFECT_AddPokeSprite 0x021F7F58 thumb ov094
 *   BTLV_EFFECT_ReleasePokeSprite 0x021F8010 thumb ov094
 *   BTLV_EFFECT_GaugeSetSideVisible 0x021F8198 thumb ov094
 *   BTLV_EFFECT_GaugeSetSlotVisible 0x021F81B4 thumb ov094
 *   BTLV_EFFECT_SetStageFieldTint 0x021F8298 thumb ov094
 *   BTLV_EFFECT_IsStageFieldBusy 0x021F8324 thumb ov094
 *   BTLV_EFFECT_SetStageLayerHidden 0x021F839C thumb ov094
 *   BTLV_EFFECT_GetPokeSlot 0x021F84D0 thumb ov094
 *   BTLV_EFFECT_GetCamera 0x021F8684 thumb ov094
 *   BTLV_EFFECT_GetMcss 0x021F8694 thumb ov094
 *   BTLV_EFFECT_GetGauge 0x021F86B4 thumb ov094
 *   BTLV_EFFECT_GetClact 0x021F86F0 thumb ov094
 *   BTLV_EFFECT_GetBg 0x021F8700 thumb ov094
 *   BTLV_EFFECT_GetMode 0x021F8710 thumb ov094
 *   BTLV_EFFECT_IsMultiMode 0x021F8730 thumb ov094
 *   BTLV_EFFECT_GetTrainerType 0x021F8740 thumb ov094
 *   BTLV_EFFECT_GetSceneUnit 0x021F8764 thumb ov094
 *   BTLV_EFFECT_IsSeSuppressed 0x021F88E0 thumb ov094
 *   BTLV_EFFECT_SetAllPokeSpriteAnim 0x021F8934 thumb ov094
 *   BTLV_EFFECT_DeleteTasksByArg 0x021F8A10 thumb ov094
 *   BTLV_EFFECT_ComputeScalarStep 0x021F9154 thumb ov094
 *   BTLV_EFFECT_StepScalarWithLimit 0x021F9220 thumb ov094
 *   BTLV_EFFECT_GetBitMask 0x021F935C thumb ov094
 *   BTLV_MCSS_SetSideScale 0x021FF134 thumb ov094
 *   BTLV_MCSS_EnableOrthoMode 0x021FF16C thumb ov094
 *   BTLV_MCSS_DisableOrthoMode 0x021FF1B0 thumb ov094
 *   BTLV_MCSS_EnableBillboard 0x021FF1F4 thumb ov094
 *   BTLV_MCSS_DisableBillboard 0x021FF228 thumb ov094
 *   BTLV_MCSS_SetAnimStopMode 0x021FF304 thumb ov094
 *   BTLV_MCSS_IsVanished 0x021FF348 thumb ov094
 *   BTLV_MCSS_SetVanishMode 0x021FF374 thumb ov094
 *   BTLV_MCSS_GetSlotPosition 0x021FF3F4 thumb ov094
 *   BTLV_MCSS_GetSlotPositionForRule 0x021FF3FC thumb ov094
 *   BTLV_MCSS_GetSlotScale 0x021FF468 thumb ov094
 *   BTLV_MCSS_SetShadowVanish 0x021FF470 thumb ov094
 *   BTLV_MCSS_StartPositionTween 0x021FF4C0 thumb ov094
 *   BTLV_MCSS_StartShadowScaleTween 0x021FF5B0 thumb ov094
 *   BTLV_MCSS_StartScaleTween 0x021FF630 thumb ov094
 *   BTLV_MCSS_StartDrawScaleTween 0x021FF6B0 thumb ov094
 *   BTLV_MCSS_StartRotateTween 0x021FF730 thumb ov094
 *   BTLV_MCSS_StartBlinkTask 0x021FF870 thumb ov094
 *   BTLV_MCSS_StartAlphaTween 0x021FF924 thumb ov094
 *   BTLV_MCSS_StartShakeTask 0x021FFA18 thumb ov094
 *   BTLV_MCSS_StartBounceTask 0x021FFB04 thumb ov094
 *   BTLV_MCSS_StartMosaicTween 0x021FFBBC thumb ov094
 *   BTLV_MCSS_IsSpriteBusy 0x021FFCB0 thumb ov094
 *   BTLV_MCSS_IsSpriteLoaded 0x021FFD9C thumb ov094
 *   BTLV_MCSS_SetPaletteFade 0x021FFDB4 thumb ov094
 *   BTLV_MCSS_GetSpriteWeight 0x021FFF0C thumb ov094
 *   BTLV_MCSS_GetSpriteAttrFlags 0x021FFF38 thumb ov094
 *   BTLV_MCSS_HasPersonalParam10 0x021FFF68 thumb ov094
 *   BTLV_MCSS_GetStopCellFlags 0x021FFFAC thumb ov094
 *   BTLV_MCSS_SetSubstituteSprite 0x021FFFD8 thumb ov094
 *   BTLV_MCSS_CopySpriteResources 0x02200140 thumb ov094
 *   BTLV_MCSS_PlayCry 0x02200218 thumb ov094
 *   BTLV_MCSS_GetSpriteColorCode 0x022003C4 thumb ov094
 *   BTLV_MCSS_SetAnimIndexIfValid 0x0220041C thumb ov094
 *   BTLV_MCSS_SetAnimPendingCallback 0x02200468 thumb ov094
 *   BTLV_MCSS_IsAnimPending 0x02200494 thumb ov094
 *   BTLV_MCSS_ResetSpritePosition 0x022004BC thumb ov094
 *   BTLV_MCSS_RestoreVanishStates 0x02200654 thumb ov094
 *   BTLV_CLACT_LoadActorSimple 0x02201AF8 thumb ov094
 *   BTLV_CLACT_LoadActor 0x02201B20 thumb ov094
 *   BTLV_CLACT_ReleaseActor 0x02201CA4 thumb ov094
 *   BTLV_CLACT_StartPosTween 0x02201CD0 thumb ov094
 *   BTLV_CLACT_StartScaleTween 0x02201D5C thumb ov094
 *   BTLV_CLACT_SetActorAnimSeq 0x02201DA0 thumb ov094
 *   BTLV_CLACT_RequestPaletteFade 0x02201DB4 thumb ov094
 */
#include "../arm9/nns_g3d_glb_types.h"
#include "btlv_effvm_types.h"
#include "btlv_camera_shared_types.h"
#include "btlv_effect_shared_types.h"
#include "btlv_effvm_shared_types.h"
#include "btlv_mcss_shared_types.h"
#include "btlv_clact_shared_types.h"
#include "../arm9/script_vm_types.h"
struct SndHandle;
#include "btlv_gauge_types.h"

#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))

#define REG16(a) (*(volatile u16 *)(a))

#define REG32(a) (*(volatile unsigned int *)(a))

struct ScriptVm;

struct ParticleSys;

struct Obj3D;

struct ParticleCameraParams;

struct BtlvCamera;

struct BtlvMcss;

struct ScriptVmParams;

struct Cursor;

struct Cur;

struct Ring;

struct BtlvEffVmEmitterMotion;

typedef struct BtlvEffVmEmitterMotion {
    int rotation[9]; /* 0x00: rotation matrix toward the target */
    BtlvEffVmVec pos; /* 0x24 */
    int halfDistance; /* 0x30 */
    int amplitude; /* 0x34 */
    int phaseA; /* 0x38 */
    int phaseB; /* 0x3C */
    int phaseStepA; /* 0x40 */
    int phaseStepB; /* 0x44 */
    int framesLeft; /* 0x48 */
    int kind; /* 0x4C */
    int delayLeft; /* 0x50 */
    int delayRate; /* 0x54 */
    int delayAccel; /* 0x58 */
    int projectToScreen; /* 0x5C */
} BtlvEffVmEmitterMotion;

#include "../types.h"

extern void *ARC_TOOL_LoadMember(u32 archiveID, u32 memberIdx, u16 heapID);

extern u32 GFL_HEAP_Free(void *p);
struct Tcb;

extern struct Tcb *GFL_USE_AddMainTask(void (*)(void *, void *), void *work, u32 priority);
struct TcbSystem;
struct TcbTask;

extern struct TcbTask *TCB_AddTask(struct TcbSystem *sys, void (*fn)(void *, void *), void *work, u32 priority);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
struct TcblSystem;

extern u32 TCBL_IsDeletePending(struct TcblSystem *tcbl);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct ScriptVm *VM_Create(u32 heapId, const struct ScriptVmParams *params);

extern void VM_Init(struct ScriptVm *vm, void *user);

extern int VM_Control(struct ScriptVm *vm);

extern void *VM_GetContext(struct ScriptVm *vm);

extern void VM_Delete(struct ScriptVm *vm);

extern void VM_Start(struct ScriptVm *vm, u8 *pc);

extern void MIi_CpuClear16(u16 data, void *destp, u32 size);

extern void PM_VOICE_StopSlot(u32 i);

extern u32 VM_GetU32(struct ScriptVm *p);

extern void VEC_Add(BtlvEffVmVec *a, BtlvEffVmVec *b, BtlvEffVmVec *c);

extern void VM_SetWait(struct ScriptVm *vm, int val);

extern void *PARTICLE_LoadArchiveMember(u32 archiveId, u32 member, u32 heapId);

extern struct ParticleSys *PARTICLE_CreateSystem(u32 workBuf, u32 workSize, u32 withCamera, u32 limitA, u32 limitB, u32 maxResIndex, u32 heapId);

extern void PARTICLE_SetupSystemNoHandlers(struct ParticleSys *sys, void *block);

extern int PARTICLE_StartEffectWithCallback(struct ParticleSys *sys, int resId, void (*callback)(void *), int userArg);

extern void PARTICLE_InitCamera(struct ParticleSys *sys, struct ParticleCameraParams *params, u16 angle, BtlvEffVmVec *pos, BtlvEffVmVec *target, BtlvEffVmVec *up, u16 heapId);

extern int PARTICLE_EMITTER_GetBlock(struct Obj3D *p);

extern void BG_SYS_SetPriority(int idx, unsigned short val);

extern u32 ARC_UTIL_UploadBgCharFromArchive(void *archiveID, void *memberIdx, void *bgId, void *tileOffset, u32 size, u32 heapID, u16 allocFlags);

extern void ARC_UTIL_UploadBgPaletteFromArchive(u32 archiveID, u32 memberIdx, u32 channel, u32 offset, u32 size, u32 heapID, u16 flags);

extern void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);

extern u32 BG_SYS_GetScrollX(u32 layer);

extern u32 BG_SYS_GetScrollY(u32 layer);
struct BtlvBg;

extern void BTLV_BG_SetScroll(struct BtlvBg *bg, u32 scrollX, u32 scrollY);

extern void BTLV_BG_StartScroll(struct BtlvBg *bg, s32 flipFlags, u32 mode, s32 x, s32 y, s32 frames, s32 phaseFrames, s32 cycleFrames);

extern void G2x_SetBlendAlpha_(u32 *reg, u32 a, u32 b, u32 c, u32 d);

extern int NNS_G3dWorldPosToScrPos(const BtlvEffVmVec *world, int *px, int *py);

extern void BTLV_GAUGE_PlaceSlot(BtlvGaugeWork *work, int slotIdx, BtlvGaugePoint *offset);

extern void GFL_USE_StopAllSe(void);

extern void GFL_USE_StopSeSlot(int i);

extern void VM_Jump(struct ScriptVm *vm, u8 *pc);

extern unsigned short PALANM_GetPairedCodeForFirst(int value);

extern void VM_Call(struct ScriptVm *vm, u8 *pc);

extern u8 *VM_Return(struct ScriptVm *r);

extern struct ScriptVm *VM_End(struct ScriptVm *vm);
struct BtlvScu;

extern void BTLV_SCU_ReloadGraphics(struct BtlvScu *scu);

extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);

extern u32 BTLV_BG_IsScrolling(struct BtlvBg *bg);

extern int PARTICLE_GetEffectCount(struct ParticleSys *sys);

extern int GFL_USE_IsAnySeBusy(void);

extern int GFL_USE_IsSeSlotBusy(unsigned);

extern u32 PM_VOICE_IsSlotActive(u32 i);

extern u32 PARTICLE_GetCallbackArg(void);

extern void PARTICLE_EMITTER_SetUserData(struct Obj3D *p, int v);

extern void PARTICLE_EMITTER_SetCallback(struct Obj3D *p, int v);

extern int VEC_Distance(const BtlvEffVmVec *a, const BtlvEffVmVec *b);

extern void VEC_Normalize(const BtlvEffVmVec *a, BtlvEffVmVec *b);

extern int VEC_DotProduct(const BtlvEffVmVec *a, const BtlvEffVmVec *b);

extern u16 FX_AcosIdx(int a);

extern void VEC_CrossProduct(const BtlvEffVmVec *a, const BtlvEffVmVec *b, BtlvEffVmVec *c);

extern void MTX_RotAxis43(void *m, void *v, s32 sinVal, s32 cosVal);

extern void MTX_MultVec43(const BtlvEffVmVec *a, const void *m, BtlvEffVmVec *out);

extern void PARTICLE_EMITTER_SetBehavior2Data(struct Obj3D *p, BtlvEffVmVec *q);

extern void PARTICLE_EMITTER_SetBehavior5Data(struct Obj3D *p, BtlvEffVmVec *q);

extern void PARTICLE_EMITTER_GetRot(struct Obj3D *p, BtlvEffVmVec16 *out);

extern void PARTICLE_EMITTER_SetBehavior3Half(struct Obj3D *p, u16 *q);

extern void PARTICLE_EMITTER_SetRot(struct Obj3D *o, const BtlvEffVmVec16 *v);

extern int PARTICLE_EMITTER_GetScaleX(struct Obj3D *p);

extern unsigned short PARTICLE_EMITTER_GetAlpha(struct Obj3D *p);

extern short PARTICLE_EMITTER_GetAngle(struct Obj3D *p);

extern int PARTICLE_EMITTER_GetScaleY(struct Obj3D *p);

extern void PARTICLE_EMITTER_SetScaleX(struct Obj3D *p, int v);

extern void PARTICLE_EMITTER_SetScaleY(struct Obj3D *p, int v);

extern void PARTICLE_EMITTER_SetAlpha(struct Obj3D *o, u16 v);

extern void PARTICLE_EMITTER_SetAngle(struct Obj3D *o, u32 v);

extern void PARTICLE_EMITTER_GetPos(struct Obj3D *p, BtlvEffVmVec *out);

extern void PARTICLE_EMITTER_SetPos(struct Obj3D *p, const BtlvEffVmVec *v);

extern short PARTICLE_EMITTER_GetOffsetX(struct Obj3D *p);

extern void PARTICLE_EMITTER_SetOffsetX(struct Obj3D *p, int v);

extern short PARTICLE_EMITTER_GetOffsetY(struct Obj3D *p);

extern void PARTICLE_EMITTER_SetOffsetY(struct Obj3D *p, int v);

extern void PARTICLE_EMITTER_SetEmitPos(struct Obj3D *p, const BtlvEffVmVec *v);

extern int PARTICLE_EMITTER_GetUserData(struct Obj3D *p);

extern void *PARTICLE_GetWorkBase(struct ParticleSys *sys);

extern void PARTICLE_DeleteSystem(struct ParticleSys *sys);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

extern int GFL_USE_GetSeSlot(u32 a);

extern void GFL_USE_PlaySeInSlot(u32 seqNo, s32 slot);

extern struct SndHandle *GFL_USE_GetSeHandle(int slot);

extern void GFL_USE_SetSeSlotParams(int i, u32 a, u32 b, u32 c);

extern void NNS_SndHandleSetVolume(struct SndHandle *handle, unsigned int volume);

extern void NNS_SndHandleSetTrackModDepth(struct SndHandle *handle, u32 trackMask, u32 value);

extern void NNS_SndHandleSetTrackModSpeed(struct SndHandle *handle, u32 trackMask, u32 value);

void MTX_Copy43To44_(const MtxFx43 *src, MtxFx44 *dst);

void MTX_Concat44(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);

fx32 FX_Div(fx32 numer, fx32 denom);

extern void GFL_NET_SetBgmTrackVolumeUnlessVoiceChat(void *a, void *b);

extern void PARTICLE_ApplyLoadHandlers(struct ParticleSys *sys);
struct BtlvVec3;

void BTLV_CAMERA_SetEyeAndTarget(struct BtlvCamera *camera, struct BtlvVec3 *eye, struct BtlvVec3 *target);

void BTLV_CAMERA_RotateOrbit(struct BtlvCamera *camera, int yaw, int pitch);

void BTLV_CAMERA_StartMove(struct BtlvCamera *camera, struct BtlvVec3 *eyeDest, struct BtlvVec3 *targetDest, s32 frames, s32 delay, s32 easeCount);

void BTLV_CAMERA_StartMoveWithEasing(struct BtlvCamera *camera, int mode, fx32 v, int unused, int n, int g, int h);

void BTLV_CAMERA_GetEyeAndTarget(struct BtlvCamera *camera, struct BtlvVec3 *eyeOut, struct BtlvVec3 *targetOut);

void BTLV_CAMERA_AdvanceOrbitEye(struct BtlvCamera *camera, s32 dPitch, s32 dYaw, struct BtlvVec3 *eyeOut, struct BtlvVec3 *targetBase);

void BTLV_CAMERA_GetDefaultEyeAndTarget(struct BtlvVec3 *eyeOut, struct BtlvVec3 *targetOut);

int BTLV_CAMERA_IsMoving(struct BtlvCamera *camera);

void BTLV_EFFECT_DeletePokeSprite(int a);

int BTLV_EFFECT_IsPokeSpriteLoaded(int i);

void BTLV_EFFECT_AddPokeSprite(int a, u32 b, u32 c, u32 d, u32 e);

void BTLV_EFFECT_ReleasePokeSprite(int a);

void BTLV_EFFECT_GaugeSetSideVisible(int a, int b);

void BTLV_EFFECT_GaugeSetSlotVisible(u32 a, u32 b);

void BTLV_EFFECT_SetStageFieldTint(u32 a, u8 b, u8 c, u8 d, u16 e);

int BTLV_EFFECT_IsStageFieldBusy(u32 a);

void BTLV_EFFECT_SetStageLayerHidden(u32 a, u32 b);

int BTLV_EFFECT_GetPokeSlot(int a);

struct BtlvCamera *BTLV_EFFECT_GetCamera(void);

BtlvMcssWork *BTLV_EFFECT_GetMcss(void);

BtlvGaugeWork *BTLV_EFFECT_GetGauge(void);

struct PalAnmSlot *BTLV_EFFECT_GetPalanm(void);

BtlvClact *BTLV_EFFECT_GetClact(void);

struct BtlvBg *BTLV_EFFECT_GetBg(void);

int BTLV_EFFECT_GetMode(void);

int BTLV_EFFECT_IsMultiMode(void);

unsigned short BTLV_EFFECT_GetTrainerType(int a);

int BTLV_EFFECT_GetSceneUnit(void);

int BTLV_EFFECT_IsSeSuppressed(void);

void BTLV_EFFECT_SetAllPokeSpriteAnim(int a);

void BTLV_EFFECT_RegisterTask(void *h, void (*cb)(void *), int arg);

void BTLV_EFFECT_DeleteTask(void *h);

void BTLV_EFFECT_DeleteTasksByArg(int a);

void BTLV_EFFECT_ComputeScalarStep(int a, int b, int *out, int c);

void BTLV_EFFECT_StepScalarWithLimit(int *p, int *d, int *lim, int *flag);

int BTLV_EFFECT_GetBitMask(int x);

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

void BTLV_EFFVM_TransformVecByMtx44(BtlvEffVmVec *pos, const BtlvEffVmVec *ofs);

void BTLV_EFFVM_TransformVecByMtx43(const BtlvEffVmVec *vec, const MtxFx44 *matrix, fx32 *out, fx32 *clipW);

unsigned int BTLV_EFFVM_ResolveParticleKey(BtlvEffVmWork *work, unsigned int key);

void BTLV_EFFVM_StartSeVolumeTweenTask(BtlvEffVmWork *work, int fromLevel, int toLevel, int steps);

int BTLV_EFFVM_FindFreeSeSlot(BtlvEffVmWork *work);

void BTLV_EFFVM_ResetPokePositionIfLoaded(void *unused);

void BTLV_EFFVM_SetShadowVanishIfLoaded(void *unused);

void BTLV_EFFVM_SePlayTaskMain(void *task, void *arg);

void BTLV_EFFVM_SePlayTaskEnd(void *task);

void BTLV_EFFVM_SeVolumeTweenTaskMain(void *task, void *arg);

void BTLV_EFFVM_SeVolumeTweenTaskEnd(void *task);

void BTLV_EFFVM_SeModulationTaskMain(void *task, void *arg);

void BTLV_EFFVM_SeModulationTaskEnd(void *task);

void BTLV_EFFVM_DelayTaskMain(void *task, void *arg);

void BTLV_EFFVM_BlendRegisterTaskMain(void *task, void *arg);

void BTLV_EFFVM_BlendRegisterTaskEnd(void *task);

void BTLV_EFFVM_WaitVoiceTaskMain(void *task, void *arg);

void BTLV_EFFVM_MultiPokeTaskMain(void *task, void *arg);

void BTLV_EFFVM_ParticleLoadTaskMain(void *task, void *arg);

void BTLV_EFFVM_SpriteCleanupTaskMain(fx32 scaleEven, fx32 scaleOdd, int frames, int waitFrames, int repeats);

int BTLV_EFFVM_IsMultiSideResourceId(int effectId);

void BTLV_MCSS_SetSideScale(BtlvMcssWork *mcss, int a, int b);

void BTLV_MCSS_EnableOrthoMode(BtlvMcssWork *mcss);

void BTLV_MCSS_DisableOrthoMode(BtlvMcssWork *mcss);

void BTLV_MCSS_EnableBillboard(BtlvMcssWork *mcss, int key);

void BTLV_MCSS_DisableBillboard(BtlvMcssWork *mcss, int key);

void BTLV_MCSS_SetAnimStopMode(BtlvMcssWork *mcss, int key, int mode);

int BTLV_MCSS_IsVanished(BtlvMcssWork *mcss, int key);

void BTLV_MCSS_SetVanishMode(BtlvMcssWork *mcss, int key, int kind);
struct BtlvMcssWork;

void BTLV_MCSS_GetSlotPosition(struct BtlvMcssWork *work, struct BtlvVec3 *out, s32 pos);

void BTLV_MCSS_GetSlotPositionForRule(struct BtlvVec3 *def, struct BtlvVec3 *out, s32 pos, s32 rule);

int BTLV_MCSS_GetSlotScale(BtlvMcssWork *mcss, int i, int mode);

void BTLV_MCSS_SetShadowVanish(BtlvMcssWork *mcss, int key, u8 v);

void BTLV_MCSS_StartPositionTween(struct BtlvMcssWork *work, s32 pos, s32 kind, struct BtlvVec3 *target, s32 frames, s32 waitFrames, s32 repeat);

void BTLV_MCSS_StartShadowScaleTween(struct BtlvMcssWork *work, s32 pos, s32 kind, struct BtlvVec3 *target, s32 frames, s32 waitFrames, s32 repeat);

void BTLV_MCSS_StartScaleTween(struct BtlvMcssWork *work, s32 pos, s32 kind, struct BtlvVec3 *target, s32 frames, s32 waitFrames, s32 repeat);

void BTLV_MCSS_StartDrawScaleTween(struct BtlvMcssWork *work, s32 pos, s32 kind, struct BtlvVec3 *target, s32 frames, s32 waitFrames, s32 repeat);

void BTLV_MCSS_StartRotateTween(struct BtlvMcssWork *work, s32 pos, s32 kind, struct BtlvVec3 *target, s32 frames, s32 waitFrames, s32 repeat);

void BTLV_MCSS_StartBlinkTask(BtlvMcssWork *mcss, int key, int kind, int a, int b);

void BTLV_MCSS_StartAlphaTween(BtlvMcssWork *mcss, int key, int kind, int value, int a, int b, int c);

void BTLV_MCSS_StartShakeTask(BtlvMcssWork *mcss, BtlvMcssShakeParams *params);

void BTLV_MCSS_StartBounceTask(BtlvMcssWork *mcss, BtlvMcssBounceParams *params);

void BTLV_MCSS_StartMosaicTween(BtlvMcssWork *mcss, int key, int kind, int value, int a, int b, int c);

int BTLV_MCSS_IsSpriteBusy(BtlvMcssWork *mcss, int key);

int BTLV_MCSS_IsSpriteLoaded(BtlvMcssWork *mcss, int key);

void BTLV_MCSS_SetPaletteFade(BtlvMcssWork *mcss, int key, u8 cur, u8 target, u8 step, u32 e);

int BTLV_MCSS_GetSpriteWeight(BtlvMcssWork *mcss, int key);

int BTLV_MCSS_GetSpriteAttrFlags(BtlvMcssWork *mcss, int key);

int BTLV_MCSS_HasPersonalParam10(BtlvMcssWork *mcss, int key);

int BTLV_MCSS_GetStopCellFlags(BtlvMcssWork *mcss, int key);

void BTLV_MCSS_SetSubstituteSprite(BtlvMcssWork *mcss, int key, int flag, int clear);

void BTLV_MCSS_CopySpriteResources(BtlvMcssWork *mcss, int key1, int key2);

int BTLV_MCSS_PlayCry(BtlvMcssWork *mcss, int key, int pitch, int pan, int chorusParamA, int chorusParamB, int chorusParamC);

int BTLV_MCSS_GetSpriteColorCode(BtlvMcssWork *mcss, int key);

int BTLV_MCSS_SetAnimIndexIfValid(BtlvMcssWork *mcss, int key, int n);

void BTLV_MCSS_SetAnimPendingCallback(BtlvMcssWork *mcss, int key);

int BTLV_MCSS_IsAnimPending(BtlvMcssWork *mcss, int key);

void BTLV_MCSS_ResetSpritePosition(BtlvMcssWork *mcss, int key);

void BTLV_MCSS_RestoreVanishStates(BtlvMcssWork *mcss);

int BTLV_CLACT_LoadActorSimple(BtlvClact *clact, int archiveId, int firstFile, s16 x, s16 y, int scaleX, int scaleY);

int BTLV_CLACT_LoadActor(BtlvClact *clact, u32 archiveId, int charFile, u32 palFile, int cellFile, int animFile, s16 x, s16 y, u32 scaleX, u32 scaleY);

void BTLV_CLACT_ReleaseActor(BtlvClact *clact, int slot);

void BTLV_CLACT_StartPosTween(BtlvClact *clact, int slot, int mode, s16 *offset, int frames, int waitTicks, int repeats);

void BTLV_CLACT_StartScaleTween(BtlvClact *clact, int slot, int mode, BtlvVec3 *scaleEnd, int frames, int waitTicks, int repeats);

u32 BTLV_CLACT_SetActorAnimSeq(BtlvClact *clact, int slot, int seq);

void BTLV_CLACT_RequestPaletteFade(BtlvClact *clact, int slot, u8 b, u8 c, s8 step, u16 d);

extern const s16 FX_SinCosTable_[];

extern const char d_0220AE68[];

extern char d_02209DCC[];

extern const BtlvEffVmVec d_0220ACA0[2];

extern const BtlvEffVmVec d_0220ACE8[];

extern const BtlvEffVmVec d_0220AD00[];

extern const BtlvEffVmVec d_0220AD78[];

extern const BtlvEffVmVec d_0220ADA8[];

extern const BtlvEffVmVec d_0220ADD8[];

extern const BtlvEffVmVec d_0220AE20[];

extern const BtlvEffVmVec d_02209E1C, d_02209D90;

extern const BtlvEffVmVec d_02209D78, d_02209E04;

extern const BtlvEffVmVec d_02209DC0, d_02209D84;

extern const BtlvEffVmVec d_02209DA8, d_02209D9C;

extern const BtlvEffVmTargetTable d_02209E58;

extern const BtlvEffVmTargetTable d_02209E28;

extern const int d_0220AD18[], d_0220AD38[];

extern const int d_0220AD58[];

extern const BtlvEffVmVec d_02209E10, d_02209DB4;

extern MtxFx43 g_renderStateDrawParams;

extern MtxFx44 SCREENTEX_ProjectionMatrix;

extern int d_02209DD8[];

#define FX(x) ((int)(((x) > 0) ? (0.5f + (float)((x) << 12)) : ((float)((x) << 12) - 0.5f)))

struct ScriptVm *BTLV_EFFVM_Create(void *owner, u32 heapId)
{
    BtlvEffVmWork *work;
    void *vm;
    int i;

    work = GFL_HEAP_Alloc(heapId, 0x2AC, 1, d_0220AE68, 0x27D);
    work->heapId = heapId;
    work->owner = owner;
    work->result = 1;
    work->layoutMode = 1;
    for (i = 0; i < 16; i++)
        work->voiceIds[i] = -1;
    for (i = 0; i < 4; i++)
        work->resources[i] = -1;
    for (i = 0; i < 6; i++)
        work->seVoiceIds[i] = -1;
    vm = VM_Create(heapId, (const struct ScriptVmParams *)d_02209DCC);
    VM_Init(vm, work);
    return vm;
}

int BTLV_EFFVM_Main(void *vm)
{
    int status;
    BtlvEffVmWork *work;

    status = VM_Control(vm);
    work = VM_GetContext(vm);
    if (work->flags.bit.blockedOnTask)
        return 0;
    if (status == 0 && work->scriptBuf != 0) {
        BTLV_EFFECT_GaugeSetSideVisible(1, 2);
        if (work->flags.bit.fallbackScript == 0)
            BTLV_EFFVM_StartSeVolumeTweenTask(work, 0x6B000, 0x7F000, 0x14);
        GFL_HEAP_Free(work->scriptBuf);
        work->scriptBuf = 0;
    }
    return status;
}

/*
 * Tears down the owner's work: BTLV_EFFVM_StopScript, free, then VM_Delete.
 */
void BTLV_EFFVM_Destroy(void *vm)
{
    BtlvEffVmWork *work = VM_GetContext(vm);
    BTLV_EFFVM_StopScript(vm);
    GFL_HEAP_Free(work);
    VM_Delete(vm);
}

void BTLV_EFFVM_StartScript(void *vm, u32 attackerPos, u32 defenderPos, u16 effectId, BtlvEffVmParams *params)
{
    BtlvEffVmWork *work;
    int entryOffset;
    int useFallback;
    u8 *scriptData;

    work = VM_GetContext(vm);
    work->scriptBuf = 0;
    BTLV_EFFECT_DeleteTasksByArg(1);
    if (params != 0)
        work->params = *params;
    else
        MIi_CpuClear16(0, &work->params, 0x10);
    work->attackerPos = attackerPos;
    work->defenderPos = defenderPos;
    work->layoutMode = 1;
    work->effectId = effectId;
    if (work->effectId >= 0x231 && (u16)(work->effectId + 0xFD9F) <= 1
        && work->lastEffectId == work->effectId && work->lastSlot == attackerPos)
        return;
    work->lastEffectId = work->effectId;
    work->lastSlot = attackerPos;
    if (BTLV_EFFVM_IsMultiSideResourceId(work->effectId) == 0)
        BTLV_EFFECT_SetAllPokeSpriteAnim(0);
    if (work->effectId < 0x231) {
        work->scriptBuf = ARC_TOOL_LoadMember(0x42, effectId, (u16)((work->heapId & 0x7fff) | 0x8000));
        if (work->effectId != 0x90 && work->effectId != 0x77 && work->effectId != 0x10b)
            BTLV_EFFECT_GaugeSetSideVisible(0, 2);
        BG_SYS_SetPlaneVisible(1, 0);
        BG_SYS_SetPlaneVisible(2, 0);
        BG_SYS_SetPlaneVisible(3, 0);
        work->flags.bit.fallbackScript = 0;
        BTLV_EFFVM_StartSeVolumeTweenTask(work, 0x7F000, 0x6B000, 0x14);
    } else {
        work->scriptBuf = ARC_TOOL_LoadMember(0x43, effectId - 0x231, (u16)((work->heapId & 0x7fff) | 0x8000));
        work->flags.bit.fallbackScript = 1;
        if (effectId >= 0x256 && (*(volatile u16 *)0x04000052 & 0x1f) == 0)
            BG_SYS_SetPlaneVisible(1, 0);
    }
    entryOffset = 4;
    if (params != 0) {
        if (((BtlvEffVmScriptFile *)work->scriptBuf)->variantCount <= params->variant)
            params->variant = 0;
        entryOffset += params->variant * 0x38;
    }
    useFallback = 0;
    if (BTLV_MCSS_IsSpriteLoaded(BTLV_EFFECT_GetMcss(), work->attackerPos)) {
        if (((work->effectId == 0xf8 || work->effectId == 0x161) && params->variant == 1)
            || work->effectId == 0x90 || work->effectId == 0x77 || work->effectId == 0x10b) {
        } else {
            useFallback = BTLV_MCSS_GetSpriteAttrFlags(BTLV_EFFECT_GetMcss(), work->attackerPos) & 1;
        }
    }
    if (work->effectId == 0x27e)
        work->flags.bit.keepBackground = 1;
    if (work->effectId == 0x291)
        work->flags.bit.keepBackground = 0;
    if (work->effectId == 0x27e && useFallback) {
        work->pendingScriptBuf = work->scriptBuf;
        work->pendingScriptOffset = entryOffset;
        work->scriptBuf = ARC_TOOL_LoadMember(0x43, 0x33, (u16)((work->heapId & 0x7fff) | 0x8000));
        work->flags.bit.fallbackScript = 1;
        work->flags.bit.fallbackPending = 1;
        entryOffset = 4;
    } else if (!work->flags.bit.fallbackScript && work->effectId != 0x90 && !work->flags.bit.fallbackPending && useFallback) {
        work->pendingScriptBuf = work->scriptBuf;
        work->pendingScriptOffset = entryOffset;
        work->scriptBuf = ARC_TOOL_LoadMember(0x43, 0x33, (u16)((work->heapId & 0x7fff) | 0x8000));
        work->flags.bit.fallbackScript = 1;
        entryOffset = 4;
    }
    scriptData = work->scriptBuf;
    work->scriptVar = 0;
    work->flags.bit.stopSeOnEnd = 0;
    work->typeSource = 8;
    VM_Start(vm, (u8 *)work->scriptBuf + *(int *)(scriptData + entryOffset));
}

/*
 * Releases the owner's script buffer (scriptBuf) after BTLV_EFFVM_ReleaseScriptResources.
 */
void BTLV_EFFVM_StopScript(void *vm)
{
    BtlvEffVmWork *work = VM_GetContext(vm);

    if (work->scriptBuf != 0) {
        BTLV_EFFVM_ReleaseScriptResources(vm, VM_GetContext(vm));
        GFL_HEAP_Free(work->scriptBuf);
        work->scriptBuf = 0;
    }
}

/*
 * Clears the blockedOnTask flag of the owner's work.
 */
void BTLV_EFFVM_ClearBlockedFlag(void *vm)
{
    ((BtlvEffVmWork *)VM_GetContext(vm))->flags.bit.blockedOnTask = 0;
}

/*
 * Returns the fallbackScript flag of the owner's work when scriptBuf is set, else -1.
 */
int BTLV_EFFVM_GetFallbackScriptFlag(void *vm)
{
    BtlvEffVmWork *work = VM_GetContext(vm);
    int result = -1;

    if (work->scriptBuf != 0)
        result = work->flags.bit.fallbackScript;
    return result;
}

void BTLV_EFFVM_InitParams(BtlvEffVmParams *params)
{
    params->kind = 0;
    params->variant = 0;
    params->option = 0;
    params->side = 0;
    params->argA = 0;
    params->argB = 0;
    params->typeCode = 0;
}

void BTLV_EFFVM_StartSePlayTask(void *vm, u32 seId, int slot, u32 pan, int pitch, u32 volume, int modDepth, int modSpeed, int delay)
{
    BtlvEffVmWork *work;
    BtlvEffVmSePlayJob *job;
    work = VM_GetContext(vm);
    if (BTLV_EFFECT_IsSeSuppressed() == 1)
        return;
    work->flags.bit.stopSeOnEnd = 1;
    if (pan == 2)
        pan = 0;
    else if (pan <= 1) {
        if (pan & 1)
            pan = 127;
        else
            pan = -128;
    } else {
        if (BTLV_EFFVM_ResolveSlotKey(vm, pan) & 1)
            pan = 127;
        else
            pan = -128;
    }
    if (modDepth > 255)
        modDepth = 255;
    if (modSpeed > 255)
        modSpeed = 255;
    if (delay == 0) {
        BTLV_EFFVM_PlaySeWithParams(seId, slot, pan, pitch, volume, modDepth, modSpeed);
        return;
    }
    job = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x24, 0, d_0220AE68, 0x431);
    job->work = work;
    job->seId = seId;
    job->slot = slot;
    job->pan = pan;
    job->delay = delay;
    job->pitch = pitch;
    job->volume = volume;
    job->modDepth = modDepth;
    job->modSpeed = modSpeed;
    work->flags.bit.seVolumeRamp = 1;
    BTLV_EFFECT_RegisterTask(TCB_AddTask(work->owner, BTLV_EFFVM_SePlayTaskMain, job, 0), BTLV_EFFVM_SePlayTaskEnd, 1);
}

void BTLV_EFFVM_StartSeVolumeTask(void *vm, u32 slot, int mode, int param, int from, int to, int startDelay, int stepCount, int framesPerStep, int duration)
{
    BtlvEffVmWork *work;
    BtlvEffVmSeRampJob *job;
    float stepFx;
    int spanFx;
    work = VM_GetContext(vm);
    job = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x38, 0, d_0220AE68, 0x455);
    job->work = work;
    job->slot = slot;
    job->mode = mode;
    job->param = param;
    job->from = from;
    job->to = to;
    job->startDelay = startDelay;
    job->stepsLeft = stepCount;
    job->stepCount = stepCount;
    job->frameCounter = 0;
    job->framesPerStep = framesPerStep;
    job->passes = duration * 2;
    if (mode == 1 && job->passes == 0)
        job->passes = 2;
    job->current = FX(job->from);
    if (job->stepsLeft > 0)
        stepFx = 0.5f + (float)(job->stepsLeft << 12);
    else
        stepFx = (float)(job->stepsLeft << 12) - 0.5f;
    spanFx = FX(job->to - job->from);
    job->delta = FX_Div(spanFx, (int)stepFx);
    BTLV_EFFECT_RegisterTask(TCB_AddTask(work->owner, BTLV_EFFVM_SeVolumeTweenTaskMain, job, 0), BTLV_EFFVM_SeVolumeTweenTaskEnd, 1);
    work->flags.bit.sePanRamp = 1;
}

/*
 * Stops every live sound slot of the owner's work (seVoiceIds, -1 = free).
 */
void BTLV_EFFVM_StopLiveSounds(void *vm)
{
    BtlvEffVmWork *work = VM_GetContext(vm);
    int i;

    for (i = 0; i < 6; i++) {
        if (work->seVoiceIds[i] != -1)
            PM_VOICE_StopSlot(work->seVoiceIds[i]);
    }
}

/*
 * Clears lastEffectId and lastSlot of the owner's work.
 */
void BTLV_EFFVM_ClearLastEffect(void *vm)
{
    BtlvEffVmWork *work = VM_GetContext(vm);
    work->lastEffectId = 0;
    work->lastSlot = 0;
}

/*
 * note: d_0220ACA0 holds six vectors but is declared with a short bound. Cases 14, 18 and
 *   19 index past it; MWCC then treats those loads as possibly aliasing A/B and keeps each
 *   load after the preceding store (any bound 1..4 matches; in-bounds models such as [6],
 *   [2][3] or a pair struct hoist the last load above the B.y store).
 */
int BTLV_EFFVM_CmdSetupCamera(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BtlvEffVmVec eye;
    BtlvEffVmVec target;
    int moveType;
    int view;
    int frames;
    int easeIn;
    int easeMode;
    int battleMode;
    int battler;

    moveType = VM_GetU32(vm);
    view = VM_GetU32(vm);
    frames = VM_GetU32(vm);
    easeIn = VM_GetU32(vm);
    easeMode = VM_GetU32(vm);
    if (work->flags.bit.cameraLocked) {
        return work->result;
    }
    if (view == 13 && work->camVecSaved == 0) {
        view = 8;
    }
    if (view != 8 && view != 15 && view != 16 && view != 14 && view != 17) {
        BTLV_EFFVM_RefreshMcssOrtho(work);
    } else {
        work->flags.bit.cameraOverride = 1;
    }
    switch (view) {
    case 15:
    case 16:
        battleMode = BTLV_EFFECT_GetMode();
        if (view == 15) {
            battler = work->attackerPos;
        } else {
            battler = work->defenderPos;
        }
        switch (battleMode) {
        case 0:
            return work->result;
        case 1:
        case 2:
            switch (battler) {
            case 2:
                view = 2;
                break;
            case 3:
                view = 8;
                if (battleMode != 1) {
                    view = 18;
                }
                break;
            case 4:
                view = 4;
                if (battleMode != 1) {
                    view = 8;
                }
                break;
            case 5:
                view = 8;
                break;
            case 6:
                view = 8;
                if (battleMode != 1) {
                    view = 6;
                }
                break;
            case 7:
            default:
                return work->result;
            }
            break;
        case 3:
            if (battler == 4 || battler == 6) {
                view = 19;
            }
            break;
        }
        break;
    case 14:
        battleMode = BTLV_EFFECT_GetMode();
        if (battleMode == 0 || battleMode == 3) {
            return work->result;
        }
        break;
    case 20:
        battleMode = BTLV_EFFECT_GetMode();
        if (battleMode == 0 || battleMode == 3) {
            BTLV_MCSS_EnableOrthoMode(BTLV_EFFECT_GetMcss());
            return work->result;
        }
        view = 14;
        break;
    case 21:
        battleMode = BTLV_EFFECT_GetMode();
        if (battleMode == 0 || battleMode == 3) {
            view = work->attackerPos;
        } else if (work->attackerPos & 1) {
            view = 1;
        } else {
            view = 14;
        }
        break;
    case 17:
        view = 8;
        break;
    case 9:
    case 10:
        battleMode = BTLV_EFFECT_GetMode();
        view = work->attackerPos;
        if (battleMode == 3 && (view == 4 || view == 6)) {
            view = 19;
        }
        break;
    case 11:
    case 12:
        switch (work->params.kind) {
        case 0:
        case 1:
        case 2:
        case 3:
            view = work->defenderPos;
            if (view == 0xff) {
                view = (work->attackerPos & 1) ^ 1;
            }
            break;
        case 5:
        case 7:
        case 9:
        case 13:
            view = work->defenderPos;
            if (view != 0xff) {
                break;
            }
        case 11:
            view = (work->attackerPos & 1) ^ 1;
            break;
        case 6:
        case 12:
            view = work->attackerPos & 1;
            break;
        case 4:
        case 8:
        case 10:
            battleMode = BTLV_EFFECT_GetMode();
            if (battleMode == 0 || battleMode == 3) {
                view = (work->attackerPos & 1) ^ 1;
            } else {
                view = 14;
            }
            break;
        }
        break;
    }
    switch (view) {
    case 0:
    case 1:
        eye.x = d_0220ACE8[view].x;
        eye.y = d_0220ACE8[view].y;
        eye.z = d_0220ACE8[view].z;
        target.x = d_0220AD00[view].x;
        target.y = d_0220AD00[view].y;
        target.z = d_0220AD00[view].z;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        battleMode = BTLV_EFFECT_GetMode();
        if (battleMode == 3) {
            eye.x = d_0220ACE8[view - 2].x;
            eye.y = d_0220ACE8[view - 2].y;
            eye.z = d_0220ACE8[view - 2].z;
            target.x = d_0220AD00[view - 2].x;
            target.y = d_0220AD00[view - 2].y;
            target.z = d_0220AD00[view - 2].z;
        } else if (battleMode == 1) {
            eye.x = d_0220AD78[view - 2].x;
            eye.y = d_0220AD78[view - 2].y;
            eye.z = d_0220AD78[view - 2].z;
            target.x = d_0220ADA8[view - 2].x;
            target.y = d_0220ADA8[view - 2].y;
            target.z = d_0220ADA8[view - 2].z;
        } else {
            eye.x = d_0220ADD8[view - 2].x;
            eye.y = d_0220ADD8[view - 2].y;
            eye.z = d_0220ADD8[view - 2].z;
            target.x = d_0220AE20[view - 2].x;
            target.y = d_0220AE20[view - 2].y;
            target.z = d_0220AE20[view - 2].z;
        }
        break;
    case 6:
    case 7:
        eye.x = d_0220ADD8[view - 2].x;
        eye.y = d_0220ADD8[view - 2].y;
        eye.z = d_0220ADD8[view - 2].z;
        target.x = d_0220AE20[view - 2].x;
        target.y = d_0220AE20[view - 2].y;
        target.z = d_0220AE20[view - 2].z;
        break;
    case 13:
        eye.x = work->camEye.x;
        eye.y = work->camEye.y;
        eye.z = work->camEye.z;
        target.x = work->camTarget.x;
        target.y = work->camTarget.y;
        target.z = work->camTarget.z;
        break;
    case 14:
        eye.x = d_0220ACA0[0].x;
        eye.y = d_0220ACA0[0].y;
        eye.z = d_0220ACA0[0].z;
        target.x = d_0220ACA0[2].x;
        target.y = d_0220ACA0[2].y;
        target.z = d_0220ACA0[2].z;
        if (work->flags.bit.cameraOverride) {
            BTLV_EFFVM_SpriteCleanupTaskMain(0xa66, 0xb9a, frames, easeIn, 0);
            work->flags.bit.cameraOffset = 1;
        }
        break;
    case 19:
        eye.x = d_0220ACA0[3].x;
        eye.y = d_0220ACA0[3].y;
        eye.z = d_0220ACA0[3].z;
        target.x = d_0220ACA0[1].x;
        target.y = d_0220ACA0[1].y;
        target.z = d_0220ACA0[1].z;
        if (work->flags.bit.cameraOverride) {
            BTLV_EFFVM_SpriteCleanupTaskMain(0xa66, 0xb9a, frames, easeIn, 0);
            work->flags.bit.cameraOffset = 1;
        }
        break;
    case 18:
        eye.x = d_0220ACA0[5].x;
        eye.y = d_0220ACA0[5].y;
        eye.z = d_0220ACA0[5].z;
        target.x = d_0220ACA0[4].x;
        target.y = d_0220ACA0[4].y;
        target.z = d_0220ACA0[4].z;
        break;
    default:
        BTLV_CAMERA_GetDefaultEyeAndTarget((struct BtlvVec3 *)(&eye), (struct BtlvVec3 *)(&target));
        if (work->flags.bit.cameraOffset) {
            BTLV_EFFVM_SpriteCleanupTaskMain(0x1000, 0x1000, frames, easeIn, 0);
            work->flags.bit.cameraOffset = 0;
        }
        break;
    }
    switch (moveType) {
    case 0:
        BTLV_CAMERA_SetEyeAndTarget(BTLV_EFFECT_GetCamera(), (struct BtlvVec3 *)(&eye), (struct BtlvVec3 *)(&target));
        break;
    case 1:
        BTLV_CAMERA_StartMove(BTLV_EFFECT_GetCamera(), (struct BtlvVec3 *)(&eye), (struct BtlvVec3 *)(&target), frames, easeIn, easeMode);
        break;
    }
    return work->result;
}

int BTLV_EFFVM_CmdMoveCameraTo(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BtlvEffVmVec eye;
    BtlvEffVmVec target;
    BtlvEffVmVec curEye;
    BtlvEffVmVec curTarget;
    int frames;
    int easeIn;
    int easeMode;
    int moveType;

    moveType = VM_GetU32(vm);
    eye.x = VM_GetU32(vm);
    eye.y = VM_GetU32(vm);
    eye.z = VM_GetU32(vm);
    target.x = VM_GetU32(vm);
    target.y = VM_GetU32(vm);
    target.z = VM_GetU32(vm);
    frames = VM_GetU32(vm);
    easeIn = VM_GetU32(vm);
    easeMode = VM_GetU32(vm);
    BTLV_EFFVM_RefreshMcssOrtho(work);
    switch (moveType) {
    case 0:
        BTLV_CAMERA_SetEyeAndTarget(BTLV_EFFECT_GetCamera(), (struct BtlvVec3 *)(&eye), (struct BtlvVec3 *)(&target));
        break;
    case 1:
        BTLV_CAMERA_StartMove(BTLV_EFFECT_GetCamera(), (struct BtlvVec3 *)(&eye), (struct BtlvVec3 *)(&target), frames, easeIn, easeMode);
        break;
    case 2:
        BTLV_CAMERA_GetEyeAndTarget(BTLV_EFFECT_GetCamera(), (struct BtlvVec3 *)(&curEye), (struct BtlvVec3 *)(&curTarget));
        VEC_Add(&curEye, &eye, &eye);
        VEC_Add(&curTarget, &target, &target);
        BTLV_CAMERA_StartMove(BTLV_EFFECT_GetCamera(), (struct BtlvVec3 *)(&eye), (struct BtlvVec3 *)(&target), frames, easeIn, easeMode);
        break;
    }
    return work->result;
}

int BTLV_EFFVM_CmdRotateCameraOrbit(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BtlvEffVmVec eye;
    BtlvEffVmVec target;
    int yaw;
    int pitch;
    int frames;
    int easeIn;
    int easeMode;
    int moveType;

    moveType = VM_GetU32(vm);
    yaw = VM_GetU32(vm);
    pitch = VM_GetU32(vm);
    frames = VM_GetU32(vm);
    easeIn = VM_GetU32(vm);
    easeMode = VM_GetU32(vm);
    BTLV_EFFVM_RefreshMcssOrtho(work);
    switch (moveType) {
    case 0:
        BTLV_CAMERA_RotateOrbit(BTLV_EFFECT_GetCamera(), yaw, pitch);
        break;
    case 1:
        BTLV_CAMERA_AdvanceOrbitEye(BTLV_EFFECT_GetCamera(), yaw, pitch, (struct BtlvVec3 *)(&eye), (struct BtlvVec3 *)(&target));
        BTLV_CAMERA_StartMove(BTLV_EFFECT_GetCamera(), (struct BtlvVec3 *)(&eye), (struct BtlvVec3 *)(&target), frames, easeIn, easeMode);
        break;
    }
    return work->result;
}

int BTLV_EFFVM_CmdMoveCameraEased(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int mode;
    int amount;
    int unused;
    int frames;
    int easeIn;
    int speed;

    mode = VM_GetU32(vm);
    amount = VM_GetU32(vm);
    unused = VM_GetU32(vm);
    frames = VM_GetU32(vm);
    easeIn = VM_GetU32(vm);
    speed = VM_GetU32(vm);
    BTLV_CAMERA_StartMoveWithEasing(BTLV_EFFECT_GetCamera(), mode, amount, unused, frames, easeIn, speed);
    return work->result;
}

int BTLV_EFFVM_CmdSetBillboardMode(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int targetIds[8];
    int mode;
    int targetCount;
    int targetIdx;

    mode = VM_GetU32(vm);
    if (VM_GetU32(vm) == 0) {
        work->layoutMode = mode;
        BTLV_EFFVM_RefreshMcssOrtho(work);
    } else {
        targetCount = BTLV_EFFVM_ResolveBattlerList(work, 14, targetIds);
        if (targetCount != 0) {
            for (targetIdx = 0; targetIdx < targetCount; targetIdx++) {
                if (mode == 1)
                    BTLV_MCSS_DisableBillboard(BTLV_EFFECT_GetMcss(), targetIds[targetIdx]);
                else
                    BTLV_MCSS_EnableBillboard(BTLV_EFFECT_GetMcss(), targetIds[targetIdx]);
            }
        }
    }
    return work->result;
}

int BTLV_EFFVM_CmdSaveCameraPosition(int vm, BtlvEffVmWork *work)
{
    work->camVecSaved = 1;
    BTLV_CAMERA_GetEyeAndTarget(BTLV_EFFECT_GetCamera(), (struct BtlvVec3 *)(&work->camEye), (struct BtlvVec3 *)(&work->camTarget));
    return work->result;
}

/*
 * witness: arm9 PARTICLE_SetupSystemNoHandlers filed as src/matched/arm9/PARTICLE_SetupSystemNoHandlers.c.
 * witness: BTLV_EFFVM_WaitParticleCallback filed as src/matched/ov/BTLV_EFFVM_WaitParticleCallback.c.
 */
int BTLV_EFFVM_CmdLoadParticleResource(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int slot;
    int key;
    void *buffer;
    void *resource;
    BtlvEffVmParticleLoadJob *job;
    int line;

    key = BTLV_EFFVM_ResolveParticleKey(work, VM_GetU32(vm));
    if (BTLV_EFFVM_AllocEmitterSlot(work, key, &slot) == 1) {
        line = 0x715;
        buffer = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x4800, 0, d_0220AE68, line);
        resource = (void *)PARTICLE_LoadArchiveMember(6, key, (u16)((work->heapId & 0x7fff) | 0x8000));
        if (buffer != 0 && resource != 0) {
            work->emitters[slot] = PARTICLE_CreateSystem((u32)buffer, 0x4800, 0, 5, 6, 0x36, (u16)((work->heapId & 0x7fff) | 0x8000));
            if (work->emitters[slot] != 0) {
                PARTICLE_SetupSystemNoHandlers(work->emitters[slot], resource);
                line += 10;
                job = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 12, 0, d_0220AE68, line);
                job->work = work;
                job->emitter = work->emitters[slot];
                job->resource = resource;
                work->flags.bit.particleSysActive = 1;
                BTLV_EFFECT_RegisterTask(GFL_USE_AddMainTask(BTLV_EFFVM_ParticleLoadTaskMain, job, 0), 0, 1);
                VM_SetWait(vm, (int)BTLV_EFFVM_WaitParticleCallback);
                BTLV_EFFVM_SetEmitterHandle(work, slot, resource);
            }
        }
        if (work->emitters[slot] == 0) {
            if (buffer != 0)
                GFL_HEAP_Free(buffer);
            if (resource != 0)
                GFL_HEAP_Free(resource);
            work->voiceIds[slot] = -1;
        }
    }
    return 1;
}

int BTLV_EFFVM_CmdStartParticleEffect(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BtlvEffVmParticleReq *req;
    int slot;
    int effectIdx;

    req = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x74a);
    slot = BTLV_EFFVM_FindEmitterSlot(work, BTLV_EFFVM_ResolveParticleKey(work, VM_GetU32(vm)));
    effectIdx = VM_GetU32(vm);
    req->vm = vm;
    req->srcKey = VM_GetU32(vm);
    req->dstKey = VM_GetU32(vm);
    req->offset.x = 0;
    req->offset.y = VM_GetU32(vm);
    req->offset.z = 0;
    req->arcAngle = VM_GetU32(vm);
    VM_GetU32(vm);
    req->scaleX = VM_GetU32(vm);
    req->alphaScale = VM_GetU32(vm);
    req->angleScale = VM_GetU32(vm);
    req->posScale = VM_GetU32(vm);
    if (req->dstKey == 8)
        req->dstKey = req->srcKey;
    if (slot != 16)
        BTLV_EFFVM_StartParticleEffectInternal(work, req, slot, effectIdx);
    GFL_HEAP_Free(req);
    return work->result;
}

int BTLV_EFFVM_CmdStartParticleEffectFixedPos(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BtlvEffVmParticleReq *req;
    int slot;
    int effectIdx;
    int result;

    req = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x77d);
    slot = BTLV_EFFVM_FindEmitterSlot(work, BTLV_EFFVM_ResolveParticleKey(work, VM_GetU32(vm)));
    effectIdx = VM_GetU32(vm);
    req->vm = vm;
    req->srcKey = 8;
    req->dstKey = 8;
    req->fixedSrc.x = VM_GetU32(vm);
    req->fixedSrc.y = VM_GetU32(vm);
    req->fixedSrc.z = VM_GetU32(vm);
    req->fixedDst.x = VM_GetU32(vm);
    req->fixedDst.y = VM_GetU32(vm);
    req->fixedDst.z = VM_GetU32(vm);
    req->offset.x = 0;
    req->offset.y = VM_GetU32(vm);
    req->offset.z = 0;
    req->arcAngle = VM_GetU32(vm);
    VM_GetU32(vm);
    req->scaleX = VM_GetU32(vm);
    req->alphaScale = VM_GetU32(vm);
    req->angleScale = VM_GetU32(vm);
    req->posScale = VM_GetU32(vm);
    if (slot != 16) {
        result = PARTICLE_StartEffectWithCallback(work->emitters[slot], effectIdx, BTLV_EFFVM_ParticleStartCallback, (int)req);
        if (result == -1)
            GFL_HEAP_Free(req);
    } else {
        GFL_HEAP_Free(req);
    }
    return work->result;
}

/*
 * witness: arm9 PARTICLE_EMITTER_GetBlock filed as src/matched/arm9/PARTICLE_EMITTER_GetBlock.c.
 */
int BTLV_EFFVM_CmdStartParticleEffectTargeted(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    struct ParticleCameraParams projection;
    BtlvEffVmParticleReq *req;
    int slot;
    int effectIdx;

    req = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x7b6);
    slot = BTLV_EFFVM_FindEmitterSlot(work, BTLV_EFFVM_ResolveParticleKey(work, VM_GetU32(vm)));
    effectIdx = VM_GetU32(vm);
    req->vm = vm;
    req->srcKey = VM_GetU32(vm);
    req->dstKey = VM_GetU32(vm);
    req->offset.x = VM_GetU32(vm);
    req->offset.y = VM_GetU32(vm);
    req->offset.z = VM_GetU32(vm);
    req->scaleX = VM_GetU32(vm);
    req->alphaScale = VM_GetU32(vm);
    req->angleScale = VM_GetU32(vm);
    req->posScale = VM_GetU32(vm);
    req->mode = 1;
    if (req->srcKey == 13) {
        req->srcKey = 9;
        req->mode = 2;
    }
    if (req->dstKey == 8)
        req->dstKey = req->srcKey;
    if (slot != 16) {
        BtlvEffVmVec cameraPos = {0, 0, 0};
        BtlvEffVmVec cameraTarget;
        BtlvEffVmVec cameraUp;
        cameraTarget = d_02209E1C;
        cameraUp = d_02209D90;
        projection.projType = 2;
        projection.fovSin = 0x3000;
        projection.fovCos = 0xffffd000;
        projection.aspect = 0xffffc000;
        projection.orthoExtent = 0x4000;
        projection.nearZ = 0x1000;
        projection.farZ = 0x200000;
        projection.projScale = 0x1000;
        if (PARTICLE_EMITTER_GetBlock((struct Obj3D *)work->emitters[slot]) == 0)
            PARTICLE_InitCamera(work->emitters[slot], &projection, 0x2000, &cameraPos, &cameraTarget, &cameraUp, (u16)((work->heapId & 0x7fff) | 0x8000));
        BTLV_EFFVM_StartParticleEffectInternal(work, req, slot, effectIdx);
    }
    GFL_HEAP_Free(req);
    return work->result;
}

int BTLV_EFFVM_CmdStartParticleEffectForEachInstance(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    struct ParticleCameraParams projection;
    BtlvEffVmParticleReq *req;
    int slot;
    int effectCount;
    int useScreenCamera;
    int effectIdx;

    req = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x7ff);
    slot = BTLV_EFFVM_FindEmitterSlot(work, BTLV_EFFVM_ResolveParticleKey(work, VM_GetU32(vm)));
    effectCount = BTLV_EFFVM_GetEmitterHandle(work, slot);
    req->vm = vm;
    req->srcKey = VM_GetU32(vm);
    req->dstKey = VM_GetU32(vm);
    req->offset.x = 0;
    req->offset.y = VM_GetU32(vm);
    req->offset.z = 0;
    req->arcAngle = VM_GetU32(vm);
    useScreenCamera = VM_GetU32(vm);
    req->scaleX = VM_GetU32(vm);
    req->alphaScale = VM_GetU32(vm);
    req->angleScale = VM_GetU32(vm);
    req->posScale = VM_GetU32(vm);
    if (slot != 16) {
        if (useScreenCamera != 0) {
            BtlvEffVmVec cameraPos = {0, 0, 0};
            BtlvEffVmVec cameraTarget;
            BtlvEffVmVec cameraUp;
            cameraTarget = d_02209D78;
            cameraUp = d_02209E04;
            projection.projType = 2;
            projection.fovSin = 0x3000;
            projection.fovCos = 0xffffd000;
            projection.aspect = 0xffffc000;
            projection.orthoExtent = 0x4000;
            projection.nearZ = 0x1000;
            projection.farZ = 0x200000;
            projection.projScale = 0x1000;
            if (PARTICLE_EMITTER_GetBlock((struct Obj3D *)work->emitters[slot]) == 0)
                PARTICLE_InitCamera(work->emitters[slot], &projection, 0x2000, &cameraPos, &cameraTarget, &cameraUp, (u16)((work->heapId & 0x7fff) | 0x8000));
            req->mode = 2;
        }
        if (req->dstKey == 8)
            req->dstKey = req->srcKey;
        for (effectIdx = 0; effectIdx < effectCount; effectIdx++)
            BTLV_EFFVM_StartParticleEffectInternal(work, req, slot, effectIdx);
    }
    GFL_HEAP_Free(req);
    return work->result;
}

int BTLV_EFFVM_CmdDeleteParticleEmitter(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int slot = BTLV_EFFVM_FindEmitterSlot(work, BTLV_EFFVM_ResolveParticleKey(work, VM_GetU32(vm)));

    if (slot != 16) {
        struct ParticleSys **emitterSlot = work->emitters + slot;
        BTLV_EFFVM_DeleteEmitter(*emitterSlot);
        *emitterSlot = 0;
        work->voiceIds[slot] = -1;
    }
    return work->result;
}

int BTLV_EFFVM_CmdStartParticleEffectOffset(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BtlvEffVmParticleReq *req;
    int slot;
    int effectIdx;

    req = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x868);
    slot = BTLV_EFFVM_FindEmitterSlot(work, BTLV_EFFVM_ResolveParticleKey(work, VM_GetU32(vm)));
    effectIdx = VM_GetU32(vm);
    req->vm = vm;
    req->motionKind = VM_GetU32(vm);
    req->srcKey = VM_GetU32(vm);
    req->dstKey = VM_GetU32(vm);
    req->offset.x = 0;
    req->offset.y = VM_GetU32(vm);
    req->offset.z = 0;
    req->travelTime = VM_GetU32(vm);
    req->arcScale = VM_GetU32(vm);
    req->scaleX = 0x1000;
    req->alphaScale = VM_GetU32(vm);
    req->angleScale = 0x1000;
    req->posScale = VM_GetU32(vm);
    req->wobbleScale = VM_GetU32(vm);
    if (req->wobbleScale == 0)
        req->wobbleScale = 1;
    if (slot != 16) {
        if (PARTICLE_StartEffectWithCallback(work->emitters[slot], effectIdx, BTLV_EFFVM_ParticleStartCallback, (int)req) == -1)
            GFL_HEAP_Free(req);
    } else {
        GFL_HEAP_Free(req);
    }
    return work->result;
}

int BTLV_EFFVM_CmdStartParticleEffectConstOffset(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BtlvEffVmParticleReq *req;
    int slot;
    int effectIdx;
    req = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x8a2);
    slot = BTLV_EFFVM_FindEmitterSlot(work, BTLV_EFFVM_ResolveParticleKey(work, VM_GetU32(vm)));
    effectIdx = VM_GetU32(vm);
    req->vm = vm;
    req->motionKind = VM_GetU32(vm);
    req->srcKey = 8;
    req->fixedSrc.x = VM_GetU32(vm);
    req->fixedSrc.y = VM_GetU32(vm);
    req->fixedSrc.z = VM_GetU32(vm);
    req->dstKey = VM_GetU32(vm);
    req->offset.x = 0;
    req->offset.y = VM_GetU32(vm);
    req->offset.z = 0;
    req->travelTime = VM_GetU32(vm);
    req->arcScale = VM_GetU32(vm);
    req->scaleX = 0x1000;
    req->alphaScale = VM_GetU32(vm);
    req->angleScale = 0x1000;
    req->posScale = VM_GetU32(vm);
    req->wobbleScale = VM_GetU32(vm);
    if (req->wobbleScale == 0) req->wobbleScale = 1;
    if (slot != 16) {
        if (PARTICLE_StartEffectWithCallback(work->emitters[slot], effectIdx, BTLV_EFFVM_ParticleStartCallback, (int)req) == -1) {
            GFL_HEAP_Free(req);
        }
    } else {
        GFL_HEAP_Free(req);
    }
    return work->result;
}

int BTLV_EFFVM_CmdStartParticleEffectTargetedOffset(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    struct ParticleCameraParams projection;
    BtlvEffVmParticleReq *req;
    int slot;
    int effectIdx;
    req = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x8e0);
    slot = BTLV_EFFVM_FindEmitterSlot(work, BTLV_EFFVM_ResolveParticleKey(work, VM_GetU32(vm)));
    effectIdx = VM_GetU32(vm);
    req->vm = vm;
    req->motionKind = VM_GetU32(vm);
    req->srcKey = VM_GetU32(vm);
    req->dstKey = VM_GetU32(vm);
    req->offset.x = 0;
    req->offset.y = VM_GetU32(vm);
    req->offset.z = 0;
    req->travelTime = VM_GetU32(vm);
    req->arcScale = VM_GetU32(vm);
    req->scaleX = 0xc00;
    req->alphaScale = VM_GetU32(vm);
    req->angleScale = 0xc00;
    req->posScale = VM_GetU32(vm);
    req->wobbleScale = VM_GetU32(vm);
    req->mode = 3;
    if (req->wobbleScale == 0) req->wobbleScale = 1;
    if (slot != 16) {
        BtlvEffVmVec cameraPos = {0, 0, 0};
        BtlvEffVmVec cameraTarget;
        BtlvEffVmVec cameraUp;
        cameraTarget = d_02209DC0;
        cameraUp = d_02209D84;
        projection.projType = 2;
        projection.fovSin = 0x3000;
        projection.fovCos = 0xffffd000;
        projection.aspect = 0xffffc000;
        projection.orthoExtent = 0x4000;
        projection.nearZ = 0x1000;
        projection.farZ = 0x200000;
        projection.projScale = 0x1000;
        if (PARTICLE_EMITTER_GetBlock((struct Obj3D *)work->emitters[slot]) == 0)
            PARTICLE_InitCamera(work->emitters[slot], &projection, 0x2000, &cameraPos, &cameraTarget, &cameraUp, (work->heapId & 0x7fff) | 0x8000);
        if (PARTICLE_StartEffectWithCallback(work->emitters[slot], effectIdx, BTLV_EFFVM_ParticleStartCallback, (int)req) == -1) {
            GFL_HEAP_Free(req);
        }
    } else {
        GFL_HEAP_Free(req);
    }
    return work->result;
}

/*
 * witness: arm9 PARTICLE_EMITTER_GetBlock filed as src/matched/arm9/PARTICLE_EMITTER_GetBlock.c.
 * trailing: 021FAC94 and 021FACA0 are tail-call stubs; not filed while ARM9 blocks.
 */
int BTLV_EFFVM_CmdStartParticleEffectTargetedConstOffset(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    struct ParticleCameraParams projection;
    BtlvEffVmParticleReq *req;
    int slot;
    int effectIdx;
    req = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x92d);
    slot = BTLV_EFFVM_FindEmitterSlot(work, BTLV_EFFVM_ResolveParticleKey(work, VM_GetU32(vm)));
    effectIdx = VM_GetU32(vm);
    req->vm = vm;
    req->motionKind = VM_GetU32(vm);
    req->srcKey = 8;
    req->fixedSrc.x = VM_GetU32(vm);
    req->fixedSrc.y = VM_GetU32(vm);
    req->fixedSrc.z = VM_GetU32(vm);
    req->dstKey = VM_GetU32(vm);
    req->offset.x = 0;
    req->offset.y = VM_GetU32(vm);
    req->offset.z = 0;
    req->travelTime = VM_GetU32(vm);
    req->arcScale = VM_GetU32(vm);
    req->scaleX = 0x1000;
    req->alphaScale = VM_GetU32(vm);
    req->posScale = VM_GetU32(vm);
    req->angleScale = VM_GetU32(vm);
    req->mode = 3;
    if (slot != 16) {
        BtlvEffVmVec cameraPos = {0, 0, 0};
        BtlvEffVmVec cameraTarget;
        BtlvEffVmVec cameraUp;
        cameraTarget = d_02209DA8;
        cameraUp = d_02209D9C;
        projection.projType = 2;
        projection.fovSin = 0x3000;
        projection.fovCos = 0xffffd000;
        projection.aspect = 0xffffc000;
        projection.orthoExtent = 0x4000;
        projection.nearZ = 0x1000;
        projection.farZ = 0x200000;
        projection.projScale = 0x1000;
        if (PARTICLE_EMITTER_GetBlock((struct Obj3D *)work->emitters[slot]) == 0)
            PARTICLE_InitCamera(work->emitters[slot], &projection, 0x2000, &cameraPos, &cameraTarget, &cameraUp, (work->heapId & 0x7fff) | 0x8000);
        if (PARTICLE_StartEffectWithCallback(work->emitters[slot], effectIdx, BTLV_EFFVM_ParticleStartCallback, (int)req) == -1) {
            GFL_HEAP_Free(req);
        }
    } else {
        GFL_HEAP_Free(req);
    }
    return work->result;
}

/*
 * Tail call to BTLV_EFFVM_SetupEmitterCallbacks with mode 0.
 */
void BTLV_EFFVM_ParticleInitCallbackSource(void *vm, void *work)
{
    BTLV_EFFVM_SetupEmitterCallbacks(vm, work, 0);
}

/*
 * Tail call to BTLV_EFFVM_SetupEmitterCallbacks with mode 1.
 */
void BTLV_EFFVM_ParticleInitCallbackTarget(void *vm, void *work)
{
    BTLV_EFFVM_SetupEmitterCallbacks(vm, work, 1);
}

int BTLV_EFFVM_CmdStartPokePositionTween(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int targetIds[8];
    BtlvEffVmVec target;
    int targetCount;
    int kind;
    int frames;
    int waitFrames;
    int repeat;
    int targetIdx;

    targetCount = BTLV_EFFVM_ResolveBattlerList(work, VM_GetU32(vm), targetIds);
    kind = VM_GetU32(vm);
    target.x = VM_GetU32(vm);
    target.y = VM_GetU32(vm);
    targetIdx = 0;
    target.z = 0;
    frames = VM_GetU32(vm);
    waitFrames = VM_GetU32(vm);
    repeat = VM_GetU32(vm);
    if (targetCount != 0) {
        for (; targetIdx < targetCount; targetIdx++)
            BTLV_MCSS_StartPositionTween(BTLV_EFFECT_GetMcss(), targetIds[targetIdx], kind, (struct BtlvVec3 *)(&target), frames, waitFrames, repeat);
    }
    return work->result;
}

int BTLV_EFFVM_CmdStartPokeShake(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BtlvMcssShakeParams params;
    int targetIds[8];
    int targetCount;
    int targetIdx;

    targetCount = BTLV_EFFVM_ResolveBattlerList(work, (int)VM_GetU32(vm), targetIds);
    params.mode = (int)VM_GetU32(vm);
    params.waveStart = (int)VM_GetU32(vm);
    params.amplitudeX = (int)VM_GetU32(vm);
    params.amplitudeY = (int)VM_GetU32(vm);
    params.stepsPerCycle = (int)VM_GetU32(vm) >> 12;
    params.stepInterval = (int)VM_GetU32(vm) >> 12;
    params.cycles = (int)VM_GetU32(vm) >> 12;
    params.cyclePause = (int)VM_GetU32(vm);
    if (targetCount != 0 && params.cycles != 0) {
        for (targetIdx = 0; targetIdx < targetCount; targetIdx++) {
            params.pos = targetIds[targetIdx];
            BTLV_MCSS_StartShakeTask(BTLV_EFFECT_GetMcss(), &params);
        }
    }
    return work->result;
}

int BTLV_EFFVM_CmdStartPokeBounce(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BtlvMcssBounceParams params;
    int targetIds[8];
    int targetCount;
    int axisY;
    int phaseStart;
    int phaseEnd;
    int amplitude;
    int frames;
    int targetIdx;

    targetCount = BTLV_EFFVM_ResolveBattlerList(work, VM_GetU32(vm), targetIds);
    axisY = VM_GetU32(vm);
    phaseStart = VM_GetU32(vm);
    phaseEnd = VM_GetU32(vm);
    amplitude = VM_GetU32(vm);
    frames = VM_GetU32(vm);
    params.phase = phaseStart;
    params.frames = frames;
    params.axisY = axisY;
    params.amplitude = amplitude;
    params.phaseStep = FX_Div(phaseEnd - phaseStart, frames << 12);
    if (targetCount != 0) {
        for (targetIdx = 0; targetIdx < targetCount; targetIdx++) {
            params.pos = targetIds[targetIdx];
            BTLV_MCSS_StartBounceTask(BTLV_EFFECT_GetMcss(), &params);
        }
    }
    return work->result;
}

int BTLV_EFFVM_CmdStartPokeShadowScaleTween(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BtlvEffVmVec target;
    int targetIds[8];
    int targetCount;
    int kind;
    int frames;
    int waitFrames;
    int repeat;
    int targetIdx;

    targetCount = BTLV_EFFVM_ResolveBattlerList(work, VM_GetU32(vm), targetIds);
    kind = VM_GetU32(vm);
    target.x = VM_GetU32(vm);
    target.y = VM_GetU32(vm);
    target.z = 0x1000;
    frames = VM_GetU32(vm);
    waitFrames = VM_GetU32(vm);
    repeat = VM_GetU32(vm);
    if (targetCount != 0) {
        for (targetIdx = 0; targetIdx < targetCount; targetIdx++)
            BTLV_MCSS_StartShadowScaleTween(BTLV_EFFECT_GetMcss(), targetIds[targetIdx], kind, (struct BtlvVec3 *)(&target), frames, waitFrames, repeat);
    }
    return work->result;
}

int BTLV_EFFVM_CmdStartPokeRotateTween(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int targetIds[8];
    BtlvEffVmVec target;
    int targetCount;
    int kind;
    int frames;
    int waitFrames;
    int repeat;
    int targetIdx;

    targetCount = BTLV_EFFVM_ResolveBattlerList(work, VM_GetU32(vm), targetIds);
    kind = VM_GetU32(vm);
    targetIdx = 0;
    target.x = 0;
    target.y = 0;
    target.z = VM_GetU32(vm);
    frames = VM_GetU32(vm);
    waitFrames = VM_GetU32(vm);
    repeat = VM_GetU32(vm);
    if (targetCount != 0) {
        for (; targetIdx < targetCount; targetIdx++)
            BTLV_MCSS_StartRotateTween(BTLV_EFFECT_GetMcss(), targetIds[targetIdx], kind, (struct BtlvVec3 *)(&target), frames, waitFrames, repeat);
    }
    return work->result;
}

int BTLV_EFFVM_CmdStartPokeAlphaTween(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int targetIds[8];
    int targetCount;
    int kind;
    int alpha;
    int frames;
    int waitFrames;
    int repeat;
    int targetIdx;

    targetCount = BTLV_EFFVM_ResolveBattlerList(work, VM_GetU32(vm), targetIds);
    kind = VM_GetU32(vm);
    alpha = VM_GetU32(vm);
    frames = VM_GetU32(vm);
    waitFrames = VM_GetU32(vm);
    repeat = VM_GetU32(vm);
    if (targetCount != 0) {
        for (targetIdx = 0; targetIdx < targetCount; targetIdx++)
            BTLV_MCSS_StartAlphaTween(BTLV_EFFECT_GetMcss(), targetIds[targetIdx], kind, alpha, frames, waitFrames, repeat);
    }
    return work->result;
}

int BTLV_EFFVM_CmdStartPokeMosaicTween(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int targetIds[8];
    int targetCount;
    int kind;
    int mosaic;
    int frames;
    int waitFrames;
    int repeat;
    int targetIdx;

    targetCount = BTLV_EFFVM_ResolveBattlerList(work, VM_GetU32(vm), targetIds);
    kind = VM_GetU32(vm);
    mosaic = VM_GetU32(vm);
    frames = VM_GetU32(vm);
    waitFrames = VM_GetU32(vm);
    repeat = VM_GetU32(vm);
    if (targetCount != 0) {
        for (targetIdx = 0; targetIdx < targetCount; targetIdx++)
            BTLV_MCSS_StartMosaicTween(BTLV_EFFECT_GetMcss(), targetIds[targetIdx], kind, mosaic, frames, waitFrames, repeat);
    }
    return work->result;
}

int BTLV_EFFVM_CmdStartPokeBlink(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int targetIds[8];
    int targetCount;
    int kind;
    int interval;
    int toggles;
    int targetIdx;

    targetCount = BTLV_EFFVM_ResolveBattlerList(work, VM_GetU32(vm), targetIds);
    kind = VM_GetU32(vm);
    interval = VM_GetU32(vm);
    toggles = VM_GetU32(vm);
    if (targetCount != 0) {
        if (toggles == 0)
            toggles = 1;
        for (targetIdx = 0; targetIdx < targetCount; targetIdx++)
            BTLV_MCSS_StartBlinkTask(BTLV_EFFECT_GetMcss(), targetIds[targetIdx], kind, interval, toggles);
    }
    return work->result;
}

int BTLV_EFFVM_CmdSetPokeAnimStop(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int targetIds[8];
    int targetCount;
    int mode;
    int targetIdx;

    targetCount = BTLV_EFFVM_ResolveBattlerList(work, VM_GetU32(vm), targetIds);
    mode = VM_GetU32(vm);
    if (targetCount != 0) {
        for (targetIdx = 0; targetIdx < targetCount; targetIdx++)
            BTLV_MCSS_SetAnimStopMode(BTLV_EFFECT_GetMcss(), targetIds[targetIdx], mode);
    }
    return work->result;
}

int BTLV_EFFVM_CmdSetPokePaletteFade(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int targetIds[8];
    int targetCount;
    int cur;
    int target;
    int step;
    int color;
    int targetIdx;

    targetCount = BTLV_EFFVM_ResolveBattlerList(work, VM_GetU32(vm), targetIds);
    cur = VM_GetU32(vm);
    target = VM_GetU32(vm);
    step = VM_GetU32(vm);
    color = VM_GetU32(vm);
    if (targetCount != 0) {
        for (targetIdx = 0; targetIdx < targetCount; targetIdx++)
            BTLV_MCSS_SetPaletteFade(BTLV_EFFECT_GetMcss(), targetIds[targetIdx], cur, target, step, color);
    }
    return work->result;
}

int BTLV_EFFVM_CmdSetPokeVanish(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int targetIds[8];
    int targetCount;
    int mode;
    int targetIdx;

    targetCount = BTLV_EFFVM_ResolveBattlerList(work, VM_GetU32(vm), targetIds);
    mode = VM_GetU32(vm);
    if (mode == 5) {
        BTLV_MCSS_RestoreVanishStates(BTLV_EFFECT_GetMcss());
    } else if (targetCount != 0) {
        for (targetIdx = 0; targetIdx < targetCount; targetIdx++)
            BTLV_MCSS_SetVanishMode(BTLV_EFFECT_GetMcss(), targetIds[targetIdx], mode);
    }
    return work->result;
}

int BTLV_EFFVM_CmdSetPokeShadowVanish(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int targetIds[8];
    int targetCount;
    int targetIdx;
    int vanish;

    targetCount = BTLV_EFFVM_ResolveBattlerList(work, VM_GetU32(vm), targetIds);
    vanish = VM_GetU32(vm);
    if (targetCount != 0) {
        for (targetIdx = 0; targetIdx < targetCount; targetIdx++)
            BTLV_MCSS_SetShadowVanish(BTLV_EFFECT_GetMcss(), targetIds[targetIdx], vanish);
    }
    return work->result;
}

int BTLV_EFFVM_CmdStartPokeShadowScaleTweenSecondary(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BtlvEffVmVec target;
    int targetIds[8];
    int targetCount;
    int targetIdx;
    int kind, frames, waitFrames, repeat;

    targetCount = BTLV_EFFVM_ResolveBattlerList(work, VM_GetU32(vm), targetIds);
    kind = VM_GetU32(vm);
    target.x = VM_GetU32(vm);
    target.y = VM_GetU32(vm);
    target.z = 0x1000;
    frames = VM_GetU32(vm);
    waitFrames = VM_GetU32(vm);
    repeat = VM_GetU32(vm);
    if (targetCount != 0) {
        for (targetIdx = 0; targetIdx < targetCount; targetIdx++)
            BTLV_MCSS_StartDrawScaleTween(BTLV_EFFECT_GetMcss(), targetIds[targetIdx], kind, (struct BtlvVec3 *)(&target), frames, waitFrames, repeat);
    }
    return work->result;
}

/*
 * Script command: runs BTLV_EFFECT_DeletePokeSprite on each id listed by BTLV_EFFVM_ResolveBattlerList.
 */
int BTLV_EFFVM_CmdDeletePokeSprites(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int targetIds[8];
    int targetCount;
    int targetIdx;

    targetCount = BTLV_EFFVM_ResolveBattlerList(work, VM_GetU32(vm), targetIds);
    if (targetCount != 0) {
        for (targetIdx = 0; targetIdx < targetCount; targetIdx++)
            BTLV_EFFECT_DeletePokeSprite(targetIds[targetIdx]);
    }
    return work->result;
}

int BTLV_EFFVM_CmdAddPokeSprite(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int effectKind, battlerPos, paramC, paramD, paramE;

    effectKind = VM_GetU32(vm);
    battlerPos = BTLV_EFFVM_ResolveSlotKey(vm, VM_GetU32(vm));
    paramC = VM_GetU32(vm);
    paramD = VM_GetU32(vm);
    paramE = VM_GetU32(vm);
    if (effectKind == -1)
        effectKind = work->scriptVar;
    BTLV_EFFECT_AddPokeSprite(effectKind, battlerPos, paramC, paramD, paramE);
    return work->result;
}

int BTLV_EFFVM_CmdSetPokePosition(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BtlvEffVmVec target;
    int kind;
    int targetPos;
    int frames, waitFrames, repeat;

    targetPos = BTLV_EFFECT_GetPokeSlot(VM_GetU32(vm));
    kind = VM_GetU32(vm);
    target.x = VM_GetU32(vm);
    target.y = VM_GetU32(vm);
    target.z = VM_GetU32(vm);
    frames = VM_GetU32(vm);
    waitFrames = VM_GetU32(vm);
    repeat = VM_GetU32(vm);
    BTLV_MCSS_StartPositionTween(BTLV_EFFECT_GetMcss(), targetPos, kind, (struct BtlvVec3 *)(&target), frames, waitFrames, repeat);
    return work->result;
}

/*
 * Script command: when BTLV_MCSS_SetAnimIndexIfValid(x, y) reports 1, calls BTLV_MCSS_SetAnimPendingCallback(x).
 */
int BTLV_EFFVM_CmdSetPokeAnimIndex(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int pos = VM_GetU32(vm);
    int value = VM_GetU32(vm);

    if (BTLV_MCSS_SetAnimIndexIfValid(BTLV_EFFECT_GetMcss(), pos, value) == 1)
        BTLV_MCSS_SetAnimPendingCallback(BTLV_EFFECT_GetMcss(), pos);
    return work->result;
}

/*
 * Script command: passes one argument to BTLV_EFFECT_ReleasePokeSprite.
 */
int BTLV_EFFVM_CmdReleasePokeSprite(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BTLV_EFFECT_ReleasePokeSprite(VM_GetU32(vm));
    return work->result;
}

int BTLV_EFFVM_CmdLoadBgPalette(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int fileId;

    fileId = VM_GetU32(vm);
    BG_SYS_SetPriority(3, 1);
    ARC_UTIL_UploadBgCharFromArchive((void *)0x5f, (void *)(fileId + 1), (void *)3, 0, 0, 0, (work->heapId & 0x7fff) | 0x8000);
    ARC_UTIL_UploadBgPaletteFromArchive(0x5f, fileId, 3, 0, 0, 0, (work->heapId & 0x7fff) | 0x8000);
    PALANM_LoadArcPaletteToSlotAt((struct PalAnmSlot *)BTLV_EFFECT_GetPalanm(), (int)0x5f, (int)(fileId + 2), (u16)((work->heapId & 0x7fff) | 0x8000), (int)0, (int)0, (int)0x80, (int)0);
    work->bg3ScrollX = BG_SYS_GetScrollX(3);
    work->bg3ScrollY = BG_SYS_GetScrollY(3);
    BTLV_BG_SetScroll(BTLV_EFFECT_GetBg(), 0, 0);
    work->flags.bit.gfxReloadPending = 1;
    return work->result;
}

int BTLV_EFFVM_CmdStartBgScroll(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int mode, x, y, frames, phaseFrames, cycleFrames, flipFlags;

    mode = VM_GetU32(vm);
    x = VM_GetU32(vm);
    y = VM_GetU32(vm);
    frames = VM_GetU32(vm);
    phaseFrames = VM_GetU32(vm);
    cycleFrames = VM_GetU32(vm);
    flipFlags = BTLV_EFFVM_ResolveSlotKey(vm, 14);
    BTLV_BG_StartScroll(BTLV_EFFECT_GetBg(), flipFlags, mode, x, y, frames, phaseFrames, cycleFrames);
    return work->result;
}

/*
 * Script command: no-op that skips 4 arguments.
 */
int BTLV_EFFVM_CmdNop4(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    VM_GetU32(vm);
    VM_GetU32(vm);
    VM_GetU32(vm);
    VM_GetU32(vm);
    return work->result;
}

/*
 * Script command: no-op that skips 5 arguments.
 */
int BTLV_EFFVM_CmdNop5(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    VM_GetU32(vm);
    VM_GetU32(vm);
    VM_GetU32(vm);
    VM_GetU32(vm);
    VM_GetU32(vm);
    return work->result;
}

/*
 * Script command: BG_SYS_SetPriority(3, arg) and sets the gfxReloadPending flag.
 */
int BTLV_EFFVM_CmdSetBgLayerEnable(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BG_SYS_SetPriority(3, (unsigned char)VM_GetU32(vm));
    work->flags.bit.gfxReloadPending = 1;
    return work->result;
}

int BTLV_EFFVM_CmdSetBlendRegister(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int blendLevel;

    VM_GetU32(vm);
    VM_GetU32(vm);
    blendLevel = VM_GetU32(vm);
    VM_GetU32(vm);
    VM_GetU32(vm);
    VM_GetU32(vm);
    if (blendLevel == 0x1f)
        G2x_SetBlendAlpha_((u32 *)0x04000050, 2, 0x3d, 0x1f, 7);
    else
        G2x_SetBlendAlpha_((u32 *)0x04000050, 10, 0x35, 0x1f, blendLevel);
    work->flags.bit.blendActive = 1;
    return work->result;
}

int BTLV_EFFVM_CmdSetStageFieldTint(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int layer, fadeStart, fadeEnd, fadeStep, color;

    layer = VM_GetU32(vm);
    fadeStart = VM_GetU32(vm);
    fadeEnd = VM_GetU32(vm);
    fadeStep = VM_GetU32(vm);
    color = VM_GetU32(vm);
    BTLV_EFFECT_SetStageFieldTint(layer, fadeStart, fadeEnd, fadeStep, color);
    return work->result;
}

/*
 * Script command: passes two arguments to BTLV_EFFECT_SetStageLayerHidden.
 */
int BTLV_EFFVM_CmdSetStageLayerHidden(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int layer = VM_GetU32(vm);
    BTLV_EFFECT_SetStageLayerHidden(layer, VM_GetU32(vm));
    return work->result;
}

int BTLV_EFFVM_CmdStartFadeTask(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BtlvEffVmWindowWipeJob *job;

    job = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x28, 1, d_0220AE68, 0xd88);
    job->work = work;
    job->direction = VM_GetU32(vm);
    job->edgeX = VM_GetU32(vm);
    job->edgeY = VM_GetU32(vm);
    job->windowBits = VM_GetU32(vm);
    job->stepsLeft = VM_GetU32(vm);
    job->framesPerStep = VM_GetU32(vm);
    job->keepWindow = VM_GetU32(vm);
    BG_SYS_SetPlaneVisible(1, 0);
    BG_SYS_SetPlaneVisible(2, 0);
    BTLV_EFFECT_RegisterTask((void *)TCB_AddTask((void *)work->owner, BTLV_EFFVM_BlendRegisterTaskMain, job, 0), BTLV_EFFVM_BlendRegisterTaskEnd, 1);
    work->flags.bit.bgFadeActive = 1;
    return work->result;
}

/*
 * (pos is a full vector: z is not used here but sets the 0x30 stack frame)
 */
int BTLV_EFFVM_CmdLoadClactAtPoke(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BtlvEffVmVec pos;
    int screenX, screenY;
    int slot, firstFile, battlerPos, dx, dy, scaleX, scaleY;

    slot = VM_GetU32(vm);
    firstFile = VM_GetU32(vm);
    battlerPos = BTLV_EFFVM_ResolveSlotKey(vm, VM_GetU32(vm));
    dx = VM_GetU32(vm);
    dy = VM_GetU32(vm);
    scaleX = VM_GetU32(vm);
    scaleY = VM_GetU32(vm);
    BTLV_MCSS_GetSlotPosition(BTLV_EFFECT_GetMcss(), (struct BtlvVec3 *)(&pos), battlerPos);
    pos.x += dx;
    pos.y += dy;
    NNS_G3dWorldPosToScrPos(&pos, &screenX, &screenY);
    work->resources[slot] =
        BTLV_CLACT_LoadActorSimple(BTLV_EFFECT_GetClact(), 0x5f, firstFile, screenX, screenY, scaleX, scaleY);
    return work->result;
}

int BTLV_EFFVM_CmdStartClactPosTween(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    s16 offset[2];
    int slot, mode, frames, waitTicks, repeats;

    slot = VM_GetU32(vm);
    mode = VM_GetU32(vm);
    offset[0] = VM_GetU32(vm);
    offset[1] = VM_GetU32(vm);
    frames = VM_GetU32(vm);
    waitTicks = VM_GetU32(vm);
    repeats = VM_GetU32(vm);
    BTLV_CLACT_StartPosTween(BTLV_EFFECT_GetClact(), work->resources[slot], mode, offset, frames, waitTicks, repeats);
    return work->result;
}

int BTLV_EFFVM_CmdStartClactScaleTween(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BtlvVec3 scaleEnd;
    int slot, mode, frames, waitTicks, repeats;

    slot = VM_GetU32(vm);
    mode = VM_GetU32(vm);
    scaleEnd.x = VM_GetU32(vm);
    scaleEnd.y = VM_GetU32(vm);
    scaleEnd.z = 0x1000;
    frames = VM_GetU32(vm);
    waitTicks = VM_GetU32(vm);
    repeats = VM_GetU32(vm);
    BTLV_CLACT_StartScaleTween(BTLV_EFFECT_GetClact(), work->resources[slot], mode, &scaleEnd, frames, waitTicks, repeats);
    return work->result;
}

/*
 * Script command: passes slot arg of the table at 0xcc and a value to BTLV_CLACT_SetActorAnimSeq.
 */
int BTLV_EFFVM_CmdSetClactAnim(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int slot = VM_GetU32(vm);
    int seq = VM_GetU32(vm);

    BTLV_CLACT_SetActorAnimSeq(BTLV_EFFECT_GetClact(), work->resources[slot], seq);
    return work->result;
}

int BTLV_EFFVM_CmdFadeClactPalette(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int slot = VM_GetU32(vm);
    int fadeStart = VM_GetU32(vm);
    int fadeEnd = VM_GetU32(vm);
    int fadeStep = VM_GetU32(vm);
    int color = VM_GetU32(vm);

    BTLV_CLACT_RequestPaletteFade(BTLV_EFFECT_GetClact(), work->resources[slot], fadeStart, fadeEnd, fadeStep, color);
    return work->result;
}

/*
 * Script command: releases slot arg of the table at 0xcc and marks it free.
 */
int BTLV_EFFVM_CmdReleaseClact(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int *resources = work->resources;
    int slot = VM_GetU32(vm);

    BTLV_CLACT_ReleaseActor(BTLV_EFFECT_GetClact(), resources[slot]);
    resources[slot] = -1;
    return work->result;
}

/*
 * The last loop reads the list through `((int *)ids)[i]`. The cast stops
 * the element address folding into sp-relative form, so the compiler hoists
 * `add r6, sp, #0x10` to function entry (ahead of the s spill) and reloads
 * the element after each call, while the case 4 call still takes a fresh
 * `add r2, sp, #0x10`. A `p = ids` pointer local instead CSEs that argument
 * into r6 and leaves 6 bytes out. `pt.x *= -1` and `BtlvGaugePoint pt = {0, 0};` in the
 * loop block are required for the rest.
 */
int BTLV_EFFVM_CmdSetGaugeVisibility(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int targetIds[8];
    int placeIds[8];
    u32 action;
    u32 targetSel;
    int count;
    int idx;

    action = VM_GetU32(vm);
    targetSel = VM_GetU32(vm);
    if (action <= 1) {
        switch (targetSel) {
        case 3:
            BTLV_EFFECT_GaugeSetSlotVisible(action, work->attackerPos);
            break;
        case 4:
            count = BTLV_EFFVM_ResolveBattlerList(work, 0x10, targetIds);
            if (count != 0) {
                for (idx = 0; idx < count; idx++)
                    BTLV_EFFECT_GaugeSetSlotVisible(action, targetIds[count]);
            }
            break;
        default:
            BTLV_EFFECT_GaugeSetSideVisible(action, targetSel);
            break;
        }
    } else {
        count = 0;
        switch (targetSel) {
        case 0:
            for (idx = 0; idx < 8; idx += 2) {
                if (BTLV_EFFECT_IsPokeSpriteLoaded(idx)) {
                    placeIds[count] = idx;
                    count++;
                }
            }
            break;
        case 1:
            for (idx = 1; idx < 8; idx += 2) {
                if (BTLV_EFFECT_IsPokeSpriteLoaded(idx)) {
                    placeIds[count] = idx;
                    count++;
                }
            }
            break;
        case 2:
            for (idx = 0; idx < 8; idx++) {
                if (BTLV_EFFECT_IsPokeSpriteLoaded(idx)) {
                    placeIds[count] = idx;
                    count++;
                }
            }
            break;
        case 3:
            count = 1;
            placeIds[0] = work->attackerPos;
            break;
        case 4:
            count = BTLV_EFFVM_ResolveBattlerList(work, 0x10, placeIds);
            break;
        }
        if (count != 0) {
            for (idx = 0; idx < count; idx++) {
                BtlvGaugePoint pt = {0, 0};

                pt.x = (action == 2) ? 0x80 : -0x10;
                if (((int *)placeIds)[idx] & 1)
                    pt.x *= -1;
                BTLV_GAUGE_PlaceSlot(BTLV_EFFECT_GetGauge(), ((int *)placeIds)[idx], &pt);
            }
        }
    }
    return work->result;
}

int BTLV_EFFVM_CmdPlaySe(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int seId = VM_GetU32(vm);
    int slot = VM_GetU32(vm);
    int pan = VM_GetU32(vm);
    int delay = VM_GetU32(vm);
    int pitch = VM_GetU32(vm);
    int volume = VM_GetU32(vm);
    int modDepth = VM_GetU32(vm);
    int modSpeed = VM_GetU32(vm);

    VM_GetU32(vm);
    BTLV_EFFVM_StartSePlayTask(vm, seId, slot, pan, pitch, volume, modDepth, modSpeed, delay);
    return work->result;
}

/*
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * Script command: mode 5 calls GFL_USE_StopAllSe, any other mode is passed to
 * GFL_USE_StopSeSlot.
 */
int BTLV_EFFVM_CmdStopSe(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int mode = VM_GetU32(vm);

    if (mode == 5)
        GFL_USE_StopAllSe();
    else
        GFL_USE_StopSeSlot(mode);
    return work->result;
}

int BTLV_EFFVM_CmdStartSeVolumeTween(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BtlvEffVmSeRampJob *job;
    int fromPos;
    int toPos;
    int diff;
    float stepsFx;
    float rangeFx;
    job = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x38, 0, d_0220AE68, 0xf17);
    job->work = work;
    job->slot = VM_GetU32(vm);
    job->mode = VM_GetU32(vm);
    job->param = 2;
    fromPos = BTLV_EFFVM_ResolveSlotKey(vm, VM_GetU32(vm));
    toPos = BTLV_EFFVM_ResolveSlotKey(vm, VM_GetU32(vm));
    job->from = (fromPos & 1) ? 127 : -128;
    job->to = (toPos & 1) ? 127 : -128;
    job->startDelay = VM_GetU32(vm);
    job->stepsLeft = VM_GetU32(vm);
    job->stepCount = job->stepsLeft;
    job->frameCounter = 0;
    job->framesPerStep = VM_GetU32(vm);
    job->passes = VM_GetU32(vm) * 2;
    if (job->mode == 1 && job->passes == 0) job->passes = 2;
    if (job->from > 0) job->current = (int)(0.5f + (float)(job->from << 12));
    else job->current = (int)((float)(job->from << 12) - 0.5f);
    if (job->stepsLeft > 0) stepsFx = (0.5f + (float)(job->stepsLeft << 12));
    else stepsFx = ((float)(job->stepsLeft << 12) - 0.5f);
    diff = job->to - job->from;
    if (diff > 0) rangeFx = (0.5f + (float)(diff << 12));
    else rangeFx = ((float)(diff << 12) - 0.5f);
    fromPos = (int)rangeFx;
    toPos = (int)stepsFx;
    job->delta = FX_Div(fromPos, toPos);
    BTLV_EFFECT_RegisterTask(TCB_AddTask(work->owner, BTLV_EFFVM_SeVolumeTweenTaskMain, job, 0), BTLV_EFFVM_SeVolumeTweenTaskEnd, 1);
    work->flags.bit.sePanRamp = 1;
    return work->result;
}

int BTLV_EFFVM_CmdStartSeVolumeTask(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int slot = VM_GetU32(vm);
    int mode = VM_GetU32(vm);
    int param = VM_GetU32(vm);
    int from = VM_GetU32(vm);
    int to = VM_GetU32(vm);
    int startDelay = VM_GetU32(vm);
    int stepCount = VM_GetU32(vm);
    int framesPerStep = VM_GetU32(vm);
    int duration = VM_GetU32(vm);

    BTLV_EFFVM_StartSeVolumeTask(vm, slot, mode, param, from, to, startDelay, stepCount, framesPerStep, duration);
    return work->result;
}

/*
 * Script command: stores one argument in waitMode, waits on BTLV_EFFVM_IsAllIdle, and suspends.
 */
int BTLV_EFFVM_CmdWaitFrames(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    work->waitMode = VM_GetU32(vm);
    VM_SetWait(vm, (int)BTLV_EFFVM_IsAllIdle);
    work->result = 1;
    return 1;
}

/*
 * Script command: stores one argument in waitFrames, waits on BTLV_EFFVM_WaitFramesCallback, and suspends.
 */
int BTLV_EFFVM_CmdWaitParticles(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    work->waitFrames = VM_GetU32(vm);
    VM_SetWait(vm, (int)BTLV_EFFVM_WaitFramesCallback);
    work->result = 1;
    return 1;
}

/*
 * Script command: stores one argument in result.
 */
void BTLV_EFFVM_CmdSetResult(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    work->result = VM_GetU32(vm);
}

int BTLV_EFFVM_CmdJumpIf(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int lhs = BTLV_EFFVM_EvalCondition(work, VM_GetU32(vm));
    int op = VM_GetU32(vm);
    int rhs = VM_GetU32(vm);
    int jumpOffset = VM_GetU32(vm);

    BTLV_EFFVM_CompareAndJump(vm, lhs, rhs, op, jumpOffset);
    return work->result;
}

int BTLV_EFFVM_CmdJumpIfCondCompare(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int lhs = BTLV_EFFVM_EvalCondition(work, VM_GetU32(vm));
    int op = VM_GetU32(vm);
    int rhs = BTLV_EFFVM_EvalCondition(work, VM_GetU32(vm));
    int jumpOffset = VM_GetU32(vm);

    BTLV_EFFVM_CompareAndJump(vm, lhs, rhs, op, jumpOffset);
    return work->result;
}

void BTLV_EFFVM_CompareAndJump(struct ScriptVm *vm, int lhs, int rhs, int op, int off)
{
    int cond = 0;

    switch (op) {
    case 0:
        if (lhs == rhs)
            cond = 1;
        break;
    case 1:
        if (lhs != rhs)
            cond = 1;
        break;
    case 2:
        if (lhs < rhs)
            cond = 1;
        break;
    case 3:
        if (lhs > rhs)
            cond = 1;
        break;
    case 4:
        if (lhs <= rhs)
            cond = 1;
        break;
    case 5:
        if (lhs >= rhs)
            cond = 1;
        break;
    }
    if (cond == 1)
        VM_Jump(vm, (u8 *)vm->pc + off);
}

/*
 * Script command: relative jump when BTLV_EFFECT_IsPokeSpriteLoaded(x) equals y.
 */
int BTLV_EFFVM_CmdJumpIfPokeLoaded(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int pos = VM_GetU32(vm);
    int expected = VM_GetU32(vm);
    int jumpOffset = VM_GetU32(vm);

    if (expected == BTLV_EFFECT_IsPokeSpriteLoaded(pos))
        VM_Jump(vm, (u8 *)vm->pc + jumpOffset);
    return work->result;
}

/*
 * Script command: stores one argument in scriptVar.
 */
int BTLV_EFFVM_CmdSetScriptVar(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    work->scriptVar = VM_GetU32(vm);
    return work->result;
}

/*
 * Script command: stores BTLV_EFFVM_EvalCondition(s, arg) in scriptVar.
 */
/*
 * Script command: stores BTLV_EFFVM_EvalCondition(s, arg) in scriptVar.
 */
int BTLV_EFFVM_CmdEvalCondition(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    work->scriptVar = BTLV_EFFVM_EvalCondition(work, VM_GetU32(vm));
    return work->result;
}

int BTLV_EFFVM_CmdSetParam(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int sel = VM_GetU32(vm);
    int value = VM_GetU32(vm);

    switch (sel) {
    case 9:
        work->params.kind = value;
        break;
    case 10:
        work->params.variant = value;
        break;
    case 11:
        work->params.option = value;
        break;
    case 12:
        work->params.side = value;
        break;
    case 13:
        work->params.argA = value;
        break;
    case 14:
        work->params.argB = value;
        break;
    case 15:
        work->params.typeCode = value;
        break;
    case 0x35:
        work->flags.bit.cameraOffset = value;
        break;
    case 0x36:
        work->camVecSaved = value;
        break;
    case 0x37:
        work->scratchVar = value;
        break;
    case 0x38:
        work->flags.bit.cameraLocked = value;
        break;
    }
    return work->result;
}

int BTLV_EFFVM_CmdSetPokeCellFlag(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int targetIds[8];
    int showSubstitute = VM_GetU32(vm);
    int targetCount = BTLV_EFFVM_ResolveBattlerList(work, VM_GetU32(vm), targetIds);
    int setSwapped = VM_GetU32(vm);
    int targetIdx;

    if (targetCount != 0) {
        for (targetIdx = 0; targetIdx < targetCount; targetIdx++)
            BTLV_MCSS_SetSubstituteSprite(BTLV_EFFECT_GetMcss(), targetIds[targetIdx], showSubstitute, setSwapped);
    }
    return work->result;
}

int BTLV_EFFVM_CmdCopyPokeSpriteState(int vm, BtlvEffVmWork *work)
{
    BTLV_MCSS_CopySpriteResources(BTLV_EFFECT_GetMcss(), work->defenderPos, work->attackerPos);
    return work->result;
}

int BTLV_EFFVM_CmdStartPokeCry(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int targetIds[8];
    int targetCount;
    int pitch;
    int pan;
    int chorusParamA;
    int chorusParamB;
    int chorusParamC;
    int duration;
    int targetIdx;
    int slot;
    BtlvEffVmCryJob *job;
    BtlvEffVmFadeWaitJob *wait;
    targetCount = BTLV_EFFVM_ResolveBattlerList(work, VM_GetU32(vm), targetIds);
    pitch = VM_GetU32(vm);
    pan = VM_GetU32(vm);
    chorusParamA = VM_GetU32(vm);
    chorusParamB = VM_GetU32(vm);
    chorusParamC = VM_GetU32(vm);
    duration = VM_GetU32(vm);
    if (targetCount != 0) {
        if (duration == 0) {
            for (targetIdx = 0; targetIdx < targetCount; targetIdx++) {
                slot = BTLV_EFFVM_FindFreeSeSlot(work);
                work->seVoiceIds[slot] = BTLV_MCSS_PlayCry(BTLV_EFFECT_GetMcss(), targetIds[targetIdx], pitch, pan, chorusParamA, chorusParamB, chorusParamC);
            }
            BTLV_EFFVM_StartSeVolumeTweenTask(work, 0x7f000, 0x6b000, 10);
            if (!work->flags.bit.fadeRestart) {
                wait = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 4, 0, d_0220AE68, 0x10f9);
                wait->work = work;
                BTLV_EFFECT_RegisterTask(TCB_AddTask(work->owner, BTLV_EFFVM_WaitVoiceTaskMain, wait, 0), 0, 0);
            }
        } else {
            for (targetIdx = 0; targetIdx < targetCount; targetIdx++) {
                job = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x20, 0, d_0220AE68, 0x1104);
                job->work = work;
                job->battlerPos = targetIds[targetIdx];
                job->pitch = pitch;
                job->pan = pan;
                job->chorusParamA = chorusParamA;
                job->chorusParamB = chorusParamB;
                job->chorusParamC = chorusParamC;
                job->delay = duration;
                work->flags.bit.particleTaskActive = 1;
                BTLV_EFFECT_RegisterTask(TCB_AddTask(work->owner, BTLV_EFFVM_SeModulationTaskMain, job, 0), BTLV_EFFVM_SeModulationTaskEnd, 1);
            }
        }
    }
    return work->result;
}

/*
 * Script command: stores one argument in typeSource.
 */
int BTLV_EFFVM_CmdSetTypeSource(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    work->typeSource = VM_GetU32(vm);
    return work->result;
}

int BTLV_EFFVM_CmdLoadClactFromPoke(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int slot = VM_GetU32(vm);
    int battlerPos = BTLV_EFFVM_ResolveSlotKey(vm, VM_GetU32(vm));
    int dx = VM_GetU32(vm);
    int dy = VM_GetU32(vm);
    int scaleX = VM_GetU32(vm);
    int scaleY = VM_GetU32(vm);
    BtlvEffVmVec pos;
    int screenX;
    int screenY;
    int typeIdx;

    BTLV_MCSS_GetSlotPosition(BTLV_EFFECT_GetMcss(), (struct BtlvVec3 *)(&pos), battlerPos);
    pos.x += dx;
    pos.y += dy;
    NNS_G3dWorldPosToScrPos(&pos, &screenX, &screenY);
    typeIdx = PALANM_GetPairedCodeForFirst(work->params.typeCode);
    typeIdx = (typeIdx == 0 || typeIdx > 0x19) ? 4 : typeIdx;
    typeIdx = (typeIdx == 0x19) ? 0x11 : typeIdx;
    typeIdx *= 2;
    work->resources[slot] = BTLV_CLACT_LoadActor(BTLV_EFFECT_GetClact(), 0x5f, typeIdx + 0x81, typeIdx + 0x82, 0x81, 0x82, screenX, screenY, scaleX, scaleY);
    return work->result;
}

int BTLV_EFFVM_CmdCallScript(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int scriptId = VM_GetU32((struct ScriptVm *)vm);
    int newAttackerPos = VM_GetU32((struct ScriptVm *)vm);
    int newDefenderPos = VM_GetU32((struct ScriptVm *)vm);
    BtlvEffVmScriptFile *file;

    work->savedAttackerPos[work->callDepth] = work->attackerPos;
    work->savedDefenderPos[work->callDepth] = work->defenderPos;
    work->savedScriptBuf[work->callDepth] = (int)work->scriptBuf;
    work->savedScriptVar[work->callDepth] = work->scriptVar;
    if (newAttackerPos != 14) work->attackerPos = newAttackerPos;
    if (newDefenderPos != 16) work->defenderPos = newDefenderPos;
    work->scriptVar = 0;
    file = ARC_TOOL_LoadMember(0x43, scriptId - 0x231, (u16)((work->heapId & 0x7fff) | 0x8000));
    work->scriptBuf = file;
    VM_Call(vm, (u8 *)file + file->variant[0].entryOffset);
    work->callDepth++;
    return work->result;
}

int BTLV_EFFVM_CmdReturnScript(int vm, BtlvEffVmWork *work)
{
    int depth;

    work->callDepth--;
    GFL_HEAP_Free(work->scriptBuf);
    depth = work->callDepth;
    work->attackerPos = work->savedAttackerPos[depth];
    work->defenderPos = work->savedDefenderPos[depth];
    work->scriptBuf = (void *)work->savedScriptBuf[depth];
    work->scriptVar = work->savedScriptVar[depth];
    VM_Return((struct ScriptVm *)vm);
    return work->result;
}

/*
 * Script command: jumps the reader by a relative offset.
 */
int BTLV_EFFVM_CmdJumpScript(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int off = VM_GetU32(vm);
    VM_Jump(vm, (u8 *)vm->pc + off);
    return work->result;
}

/*
 * Script command: sets the blockedOnTask flag, waits on BTLV_EFFVM_WaitTaskCallback, and suspends.
 */
int BTLV_EFFVM_CmdWaitForTask(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    work->flags.bit.blockedOnTask = 1;
    VM_SetWait(vm, (int)BTLV_EFFVM_WaitTaskCallback);
    work->result = 1;
    return 1;
}

/*
 * Script command: loads script id (archive 0x42 below 0x231, else 0x43) into scriptBuf and jumps into it.
 */
int BTLV_EFFVM_CmdJumpToArchiveScript(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int id = VM_GetU32(vm);
    BtlvEffVmScriptFile *file;

    GFL_HEAP_Free(work->scriptBuf);
    if (id < 0x231)
        work->scriptBuf = ARC_TOOL_LoadMember((int)0x42, (int)id, (u16)((work->heapId & 0x7fff) | 0x8000));
    else
        work->scriptBuf = ARC_TOOL_LoadMember((int)0x43, (int)(id - 0x231), (u16)((work->heapId & 0x7fff) | 0x8000));
    file = work->scriptBuf;
    work->scriptVar = 0;
    VM_Jump(vm, (u8 *)file + file->variant[0].entryOffset);
    return work->result;
}

int BTLV_EFFVM_CmdStartWaitTask(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int side = VM_GetU32(vm);
    BtlvEffVmSlotSweepJob *job;

    job = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0xc, 0, d_0220AE68, 0x1250);
    job->work = work;
    job->side = side;
    job->doneMask = 0;
    BTLV_EFFECT_RegisterTask(TCB_AddTask((void *)work->owner, BTLV_EFFVM_MultiPokeTaskMain, job, 0), 0, 1);
    return work->result;
}

/*
 * Script command: passes one argument to BTLV_EFFECT_SetAllPokeSpriteAnim.
 */
int BTLV_EFFVM_CmdSetPokeSpriteAnimMode(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    BTLV_EFFECT_SetAllPokeSpriteAnim(VM_GetU32(vm));
    return work->result;
}

/*
 * Script reset: frees slot objects and buffers, restores display state, then resumes the
 * pending script at 0x1ec or reloads script 0x34 when the follow-up conditions hold.
 */
int BTLV_EFFVM_ReleaseScriptResources(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    int i;
    int useFallback;
    u16 curEffectId;
    u16 finalEffectId;
    int fallbackPending;
    int entryOffset;
    char *scriptPtr;
    void *scu;

    for (i = 0; i < 16; i++) {
        if (work->emitters[i] != 0) {
            BTLV_EFFVM_DeleteEmitter(work->emitters[i]);
            work->emitters[i] = 0;
        }
        work->voiceIds[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        if (work->resources[i] != -1) {
            BTLV_CLACT_ReleaseActor(BTLV_EFFECT_GetClact(), work->resources[i]);
            work->resources[i] = -1;
        }
    }
    for (i = 0; i < work->allocBufferCount; i++)
        GFL_HEAP_Free(work->allocBuffers[i]);
    work->allocBufferCount = 0;
    BTLV_EFFECT_DeleteTasksByArg(1);
    BTLV_EFFVM_ResetPokePositionIfLoaded(work);
    BTLV_EFFVM_SetShadowVanishIfLoaded(work);
    if (work->flags.bit.keepBackground == 0)
        BTLV_EFFECT_SetAllPokeSpriteAnim(1);
    VM_End(vm);
    work->result = 1;
    if (work->flags.bit.gfxReloadPending) {
        scu = (void *)BTLV_EFFECT_GetSceneUnit();
        if (scu != 0)
            BTLV_SCU_ReloadGraphics(scu);
        BG_SYS_SetPriority(3, 0);
        work->flags.bit.gfxReloadPending = 0;
        BG_SYS_ChangeScrollImmediate(3, 0, work->bg3ScrollX);
        BG_SYS_ChangeScrollImmediate(3, 3, work->bg3ScrollY);
    }
    if (work->flags.bit.blendActive) {
        G2x_SetBlendAlpha_((u32 *)0x04000050, 2, 0x3d, 0x1f, 7);
        work->flags.bit.blendActive = 0;
    }
    if (work->flags.bit.stopSeOnEnd)
        GFL_USE_StopAllSe();
    useFallback = 0;
    if (BTLV_MCSS_IsSpriteLoaded(BTLV_EFFECT_GetMcss(), work->attackerPos) != 0) {
        curEffectId = work->effectId;
        if (((curEffectId == 0xf8 || curEffectId == 0x161) && work->params.variant == 1) || curEffectId == 0x90 || curEffectId == 0x77 || curEffectId == 0x10b) {
        } else {
            useFallback = BTLV_MCSS_GetSpriteAttrFlags(BTLV_EFFECT_GetMcss(), work->attackerPos) & 1;
        }
    }
    if (work->pendingScriptBuf != 0) {
        GFL_HEAP_Free(work->scriptBuf);
        scriptPtr = work->pendingScriptBuf;
        work->scriptBuf = scriptPtr;
        work->pendingScriptBuf = 0;
        work->flags.bit.fallbackScript = 0;
        entryOffset = work->pendingScriptOffset;
        BG_SYS_SetPlaneVisible(1, 0);
        BG_SYS_SetPlaneVisible(2, 0);
        BG_SYS_SetPlaneVisible(3, 0);
        work->scriptVar = 0;
        VM_Start(vm, (u8 *)((char *)work->scriptBuf + *(int *)(scriptPtr + entryOffset)));
        return 1;
    }
    fallbackPending = work->flags.bit.fallbackPending;
    if (fallbackPending == 1 && work->effectId == 0x291) {
        GFL_HEAP_Free(work->scriptBuf);
        work->effectId = 0x34;
        scriptPtr = ARC_TOOL_LoadMember(0x43, work->effectId, (u16)((work->heapId & 0x7fff) | 0x8000));
        work->scriptBuf = scriptPtr;
        work->flags.bit.fallbackScript = 1;
        work->scriptVar = 0;
        work->flags.bit.fallbackPending = 0;
        VM_Start(vm, (u8 *)(scriptPtr + ((BtlvEffVmScriptFile *)scriptPtr)->variant[0].entryOffset));
        return 1;
    }
    finalEffectId = work->effectId;
    if ((finalEffectId == 0x286 || work->flags.bit.fallbackScript == 0) && finalEffectId != 0x90 && finalEffectId != 0xe2 && fallbackPending == 0 && useFallback != 0) {
        if (finalEffectId == 0x1f6)
            BTLV_MCSS_SetVanishMode(BTLV_EFFECT_GetMcss(), work->attackerPos, 0);
        GFL_HEAP_Free(work->scriptBuf);
        work->effectId = 0x34;
        scriptPtr = ARC_TOOL_LoadMember(0x43, work->effectId, (u16)((work->heapId & 0x7fff) | 0x8000));
        work->scriptBuf = scriptPtr;
        work->flags.bit.fallbackScript = 1;
        work->scriptVar = 0;
        work->flags.bit.fallbackPending = 0;
        VM_Start(vm, (u8 *)(scriptPtr + ((BtlvEffVmScriptFile *)scriptPtr)->variant[0].entryOffset));
        return 1;
    }
    if (finalEffectId != 0x27e) {
        BG_SYS_SetPlaneVisible(1, 1);
        BG_SYS_SetPlaneVisible(2, 1);
        BG_SYS_SetPlaneVisible(3, 1);
    }
    return 1;
}

/*
 * witness: arm9 PARTICLE_GetEffectCount filed as src/matched/arm9/PARTICLE_GetEffectCount.c.
 * followers: 021FC9D0 countdown <=0; 021FC9E4 !flags bit7;
 *   021FC9F4 !flags bit16 (filed as their own packets).
 * lever: enum loop counters retain entry guards; flag bitfields retain
 *   shift-pair tests (raw unsigned mask expressions added 16 bytes).
 */
int BTLV_EFFVM_IsAllIdle(int vm, BtlvEffVmWork *work)
{
    int i;
    BtlvSlotIndex pos;

    if (work->waitMode <= 1) {
        if (BTLV_CAMERA_IsMoving(BTLV_EFFECT_GetCamera()) == 1) return 0;
        if (work->flags.bit.cameraOverride) {
            work->flags.bit.cameraOverride = 0;
            work->layoutMode = 1;
            BTLV_MCSS_EnableOrthoMode(BTLV_EFFECT_GetMcss());
        }
    }
    if (work->waitMode == 0 || work->waitMode == 3) {
        for (pos = 0; pos < 14; pos++) {
            if (BTLV_MCSS_IsSpriteBusy(BTLV_EFFECT_GetMcss(), pos) == 1) return 0;
        }
    }
    if (work->waitMode == 4) {
        for (pos = 8; pos < 14; pos++) {
            if (BTLV_MCSS_IsSpriteLoaded(BTLV_EFFECT_GetMcss(), pos)) {
                if (BTLV_MCSS_IsAnimPending(BTLV_EFFECT_GetMcss(), pos) == 1) return 0;
            }
        }
    }
    if (work->waitMode == 0 || work->waitMode == 5) {
        if (BTLV_BG_IsScrolling((void *)BTLV_EFFECT_GetBg()) == 1) return 0;
    }
    if (work->waitMode == 0 || work->waitMode == 2) {
        for (i = 0; i < 16; i++) {
            if (work->emitters[i] != 0) {
                if (PARTICLE_GetEffectCount(work->emitters[i]) != 0) return 0;
            }
        }
    }
    if (work->waitMode == 0 || work->waitMode == 6 || work->waitMode == 8) {
        if (BTLV_EFFECT_IsStageFieldBusy(0) != 0) return 0;
    }
    if (work->waitMode == 0 || work->waitMode == 7 || work->waitMode == 8) {
        if (BTLV_EFFECT_IsStageFieldBusy(1) != 0) return 0;
    }
    if (work->waitMode == 0 || work->waitMode == 9) {
        if (BTLV_EFFECT_IsStageFieldBusy(3) != 0) return 0;
    }
    if (work->waitMode == 10) {
        if (GFL_USE_IsAnySeBusy() != 0 || work->flags.bit.seVolumeRamp || work->flags.bit.sePanRamp) return 0;
    }
    if (work->waitMode == 11) {
        if (GFL_USE_IsSeSlotBusy(1) != 0 || work->flags.bit.seVolumeRamp || work->flags.bit.sePanRamp) return 0;
    }
    if (work->waitMode == 12) {
        if (GFL_USE_IsSeSlotBusy(2) != 0 || work->flags.bit.seVolumeRamp || work->flags.bit.sePanRamp) return 0;
    }
    if (work->waitMode == 13) {
        if (GFL_USE_IsSeSlotBusy(4) != 0 || work->flags.bit.seVolumeRamp || work->flags.bit.sePanRamp) return 0;
    }
    if (work->waitMode == 14) {
        if (GFL_USE_IsSeSlotBusy(3) != 0 || work->flags.bit.seVolumeRamp || work->flags.bit.sePanRamp) return 0;
    }
    if (work->waitMode == 15) {
        if (GFL_USE_IsSeSlotBusy(0) != 0 || work->flags.bit.seVolumeRamp || work->flags.bit.sePanRamp) return 0;
    }
    if (work->waitMode == 16) {
        if (work->flags.bit.particleTaskActive) return 0;
        for (i = 0; i < 6; i++) {
            if (work->seVoiceIds[i] != -1) {
                if (PM_VOICE_IsSlotActive(work->seVoiceIds[i]) != 0) return 0;
                work->seVoiceIds[i] = -1;
            }
        }
    }
    if (work->waitMode == 0 || work->waitMode == 17) {
        if (work->flags.bit.bgFadeActive) return 0;
    }
    return 1;
}

/*
 * Wait callback: decrements waitFrames, done when it reaches zero.
 */
int BTLV_EFFVM_WaitFramesCallback(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    return --work->waitFrames <= 0;
}

/*
 * Wait callback: done once the blockedOnTask flag is clear.
 */
int BTLV_EFFVM_WaitTaskCallback(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    if (work->flags.bit.blockedOnTask)
        return 0;
    return 1;
}

/*
 * Wait callback: done once the particleSysActive flag is clear.
 */
int BTLV_EFFVM_WaitParticleCallback(struct ScriptVm *vm, BtlvEffVmWork *work)
{
    if (work->flags.bit.particleSysActive)
        return 0;
    return 1;
}

int BTLV_EFFVM_ResolveBattlerList(BtlvEffVmWork *work, int cmd, int *out)
{
    BtlvMcssPos pos;
    int count = 1;
    int mode;
    BtlvEffVmTargetTable table;
    int group;
    int *row;
    int i;
    int lastPos;

    switch (cmd) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6:
    case 7: case 8: case 9: case 10: case 11: case 12: case 13:
        out[0] = cmd;
        break;
    case 14:
        out[0] = work->attackerPos;
        if (out[0] == 0xff) {
            if (BTLV_EFFECT_IsPokeSpriteLoaded(0) == 1) {
                out[0] = 0;
            } else if (BTLV_EFFECT_IsPokeSpriteLoaded(2) == 1) {
                out[0] = 2;
            } else if (BTLV_EFFECT_IsPokeSpriteLoaded(4) == 1) {
                out[0] = 4;
            } else if (BTLV_EFFECT_IsPokeSpriteLoaded(4) == 1) {
                out[0] = 6;
            }
        }
        break;
    case 15:
        if (work->attackerPos > 1) {
            out[0] = work->attackerPos ^ 2;
        } else {
            out[0] = 0xff;
        }
        break;
    case 16:
        out[0] = work->defenderPos;
        if (out[0] == 0xff) {
            mode = BTLV_EFFECT_GetMode();
            count = 0;
            if (mode == 0 || mode == 3) {
                if (work->params.kind == 8 || work->params.kind == 10) {
                    out[0] = work->attackerPos;
                    count = 1;
                    if (BTLV_EFFECT_IsPokeSpriteLoaded(work->attackerPos ^ 1)) {
                        out[1] = work->attackerPos ^ 1;
                        count++;
                    }
                } else {
                    pos = BTLV_MCSS_POS_BB;
                    count = 0;
                    if (BTLV_EFFECT_IsPokeSpriteLoaded(work->attackerPos ^ pos)) {
                        out[0] = work->attackerPos ^ pos;
                        count++;
                    }
                }
            } else {
                switch (work->params.kind) {
                case 0: case 1: case 2: case 3:
                    break;
                case 4:
                    if (mode == 2 && work->attackerPos != 4 && work->attackerPos != 5) {
                        table = d_02209E58;
                        group = work->attackerPos > 3 ? 2 : 0;
                        i = 0;
                        row = table.row[(work->attackerPos & 1) + group];
                        for (; i < 3; i++) {
                            if (BTLV_EFFECT_IsPokeSpriteLoaded(row[i])) {
                                out[count] = row[i];
                                count++;
                            }
                        }
                    } else {
                        for (pos = BTLV_MCSS_POS_A; pos <= BTLV_MCSS_POS_F; pos++) {
                            if (work->attackerPos != pos && BTLV_EFFECT_IsPokeSpriteLoaded(pos)) {
                                out[count] = pos;
                                count++;
                            }
                        }
                    }
                    break;
                case 5: case 7: case 9: case 13:
                    pos = (work->attackerPos & 1) ? BTLV_MCSS_POS_A : BTLV_MCSS_POS_B;
                    lastPos = (mode == 2) ? 7 : 5;
                    if (mode == 2) {
                        if (work->attackerPos <= 3)
                            pos += 2;
                        if (work->attackerPos >= 6)
                            lastPos -= 2;
                    }
                    for (; pos <= lastPos; pos += 2) {
                        if (BTLV_EFFECT_IsPokeSpriteLoaded(pos)) {
                            out[count] = pos;
                            count++;
                        }
                    }
                    break;
                case 11:
                    pos = (work->attackerPos & 1) ? BTLV_MCSS_POS_A : BTLV_MCSS_POS_B;
                    for (; pos <= BTLV_MCSS_POS_F; pos += 2) {
                        if (BTLV_EFFECT_IsPokeSpriteLoaded(pos)) {
                            out[count] = pos;
                            count++;
                        }
                    }
                    break;
                case 6: case 12:
                    pos = (work->attackerPos & 1) ? BTLV_MCSS_POS_B : BTLV_MCSS_POS_A;
                    for (; pos <= BTLV_MCSS_POS_F; pos += 2) {
                        if (BTLV_EFFECT_IsPokeSpriteLoaded(pos)) {
                            out[count] = pos;
                            count++;
                        }
                    }
                    break;
                case 8: case 10:
                    for (pos = BTLV_MCSS_POS_A; pos <= BTLV_MCSS_POS_F; pos++) {
                        if (BTLV_EFFECT_IsPokeSpriteLoaded(pos)) {
                            out[count] = pos;
                            count++;
                        }
                    }
                    break;
                }
            }
        }
        break;
    case 17:
        if (work->defenderPos > 1) {
            out[0] = work->defenderPos ^ 2;
        } else {
            out[0] = 0xff;
        }
        break;
    case 18:
        count = 0;
        for (pos = BTLV_MCSS_POS_AA; pos <= BTLV_MCSS_POS_F; pos++) {
            if (BTLV_EFFECT_IsPokeSpriteLoaded(pos)) {
                out[count] = pos;
                count++;
            }
        }
        break;
    case 19: case 20:
        pos = (cmd == 19) ? BTLV_MCSS_POS_AA : (BtlvMcssPos)count;
        count = 0;
        for (; pos <= BTLV_MCSS_POS_F; pos += 2) {
            if (BTLV_EFFECT_IsPokeSpriteLoaded(pos)) {
                out[count] = pos;
                count++;
            }
        }
        break;
    }
    if (out[0] != 0xff && out[0] < 8) {
        if (BTLV_EFFECT_IsPokeSpriteLoaded(out[0]) == 1) {
            out[0] = BTLV_EFFVM_ResolveSide(work, out[0]);
        } else {
            out[0] = 0xff;
            count = 0;
        }
    }
    return count;
}

/*
 * lever: enum key retains loop entry guards and constant one; shared outer
 *   exit, separate output store/increment, and branch-local n=0 reproduce
 *   the original scheduling (r1 266 bytes DIFF; r2 532 bytes; r3 EXACT).
 */
int BTLV_EFFVM_ResolveBattlerListExpanded(BtlvEffVmWork *work, int unused, int *out)
{
    BtlvMcssPos pos = BTLV_MCSS_POS_BB;
    int count = 1;
    int mode;
    BtlvEffVmTargetTable table;
    int group;
    int *row;
    int i;

    out[0] = work->defenderPos;
    if (out[0] == 0xff) {
    mode = BTLV_EFFECT_GetMode();
    count = 0;
    if (mode == 0 || mode == 3) {
        if (work->params.kind == 8 || work->params.kind == 10) {
            out[0] = work->attackerPos;
            count = 1;
            if (BTLV_EFFECT_IsPokeSpriteLoaded(work->attackerPos ^ 1)) {
                out[1] = work->attackerPos ^ 1;
                count++;
            }
        } else {
            count = 0;
            if (BTLV_EFFECT_IsPokeSpriteLoaded(work->attackerPos ^ 1)) {
                out[0] = work->attackerPos ^ 1;
                count++;
            }
        }
    } else {
        switch (work->params.kind) {
        case 0: case 1: case 2: case 3:
            break;
        case 4:
            if (mode == 2 && work->attackerPos != 4 && work->attackerPos != 5) {
                table = d_02209E28;
                group = work->attackerPos > 3 ? 2 : 0;
                i = 0;
                row = table.row[(work->attackerPos & 1) + group];
                for (; i < 3; i++) {
                    if (BTLV_EFFECT_IsPokeSpriteLoaded(row[i]) && !BTLV_MCSS_IsVanished(BTLV_EFFECT_GetMcss(), row[i])) {
                        out[count] = row[i];
                        count++;
                    }
                }
            } else {
                for (pos = BTLV_MCSS_POS_A; pos <= BTLV_MCSS_POS_F; pos++) {
                    if (work->attackerPos != pos && BTLV_EFFECT_IsPokeSpriteLoaded(pos) && !BTLV_MCSS_IsVanished(BTLV_EFFECT_GetMcss(), pos)) {
                        out[count] = pos;
                        count++;
                    }
                }
            }
            break;
        case 5: case 7: case 9: case 13:
            if (mode == 1) {
                out[0] = (work->attackerPos & pos) ? 0 : pos;
                count = 1;
            } else {
                if (work->attackerPos != 4 && work->attackerPos != 5) {
                    out[0] = d_0220AD18[work->attackerPos];
                    count = pos;
                } else {
                    out[0] = work->attackerPos ^ 1;
                    count = 1;
                }
            }
            break;
        case 11:
            if (mode == 1) {
                out[0] = (work->attackerPos & pos) ? 0 : pos;
                count = 1;
            } else {
                if (work->attackerPos != 4 && work->attackerPos != 5) {
                    out[0] = d_0220AD38[work->attackerPos];
                    count = pos;
                } else {
                    out[0] = work->attackerPos ^ 1;
                    count = 1;
                }
            }
            break;
        case 6: case 12:
            pos = (work->attackerPos & pos) ? BTLV_MCSS_POS_B : BTLV_MCSS_POS_A;
            for (; pos <= BTLV_MCSS_POS_F; pos += 2) {
                if (BTLV_EFFECT_IsPokeSpriteLoaded(pos) && !BTLV_MCSS_IsVanished(BTLV_EFFECT_GetMcss(), pos)) {
                    out[count] = pos;
                    count++;
                }
            }
            break;
        case 8: case 10:
            for (pos = BTLV_MCSS_POS_A; pos <= BTLV_MCSS_POS_F; pos++) {
                if (BTLV_EFFECT_IsPokeSpriteLoaded(pos) && !BTLV_MCSS_IsVanished(BTLV_EFFECT_GetMcss(), pos)) {
                    out[count] = pos;
                    count++;
                }
            }
            break;
        }
    }
    }
    return count;
}

int BTLV_EFFVM_ResolveSlotKey(struct ScriptVm *vm, int idx)
{
    BtlvEffVmWork *work = VM_GetContext(vm);
    int pos;

    switch (idx) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        pos = idx;
        break;
    case 14:
        pos = work->attackerPos;
        if (pos == 0xff) {
            if (BTLV_EFFECT_IsPokeSpriteLoaded(2) == 1)
                return 2;
            if (BTLV_EFFECT_IsPokeSpriteLoaded(4) == 1)
                return 4;
            if (BTLV_EFFECT_IsPokeSpriteLoaded(6) == 1)
                return 6;
            return 0;
        }
        break;
    case 15:
        if (work->attackerPos > 1)
            pos = work->attackerPos ^ 2;
        else
            pos = 0xff;
        break;
    case 16:
        pos = work->defenderPos;
        if (pos == 0xff) {
            if (work->attackerPos & 1) {
                if (BTLV_EFFECT_IsPokeSpriteLoaded(2) == 1)
                    return 2;
                if (BTLV_EFFECT_IsPokeSpriteLoaded(4) == 1)
                    return 4;
                if (BTLV_EFFECT_IsPokeSpriteLoaded(6) == 1)
                    return 6;
                return 0;
            } else {
                if (BTLV_EFFECT_IsPokeSpriteLoaded(3) == 1)
                    return 3;
                if (BTLV_EFFECT_IsPokeSpriteLoaded(5) == 1)
                    return 5;
                if (BTLV_EFFECT_IsPokeSpriteLoaded(7) == 1)
                    return 7;
                return 1;
            }
        }
        break;
    case 17:
        if (work->defenderPos > 1)
            pos = work->defenderPos ^ 2;
        else
            pos = 0xff;
        break;
    }
    return BTLV_EFFVM_ResolveSideFromVm(vm, pos);
}

#define MUL(a, b) ((int)(((s64)(a) * (b) + 0x800) >> 12))

int BTLV_EFFVM_ResolveSide(BtlvEffVmWork *work, int pos)
{
    if (BTLV_EFFECT_IsPokeSpriteLoaded(pos) == 1) {
        if (work->flags.bit.flipSides)
            pos ^= 1;
    } else {
        pos = 0xff;
    }
    return pos;
}

int BTLV_EFFVM_ResolveSideFromVm(struct ScriptVm *vm, int pos)
{
    int result = pos;

    if (((BtlvEffVmWork *)VM_GetContext(vm))->flags.bit.flipSides)
        result ^= 1;
    return result;
}

int BTLV_EFFVM_ResolveAnchorSlot(struct ScriptVm *vm, int *out)
{
    BtlvEffVmWork *work = VM_GetContext(vm);
    int mode = BTLV_EFFECT_GetMode();
    int attackerPos;

    *out = work->defenderPos;
    if (*out != 0xff)
        return mode;
    if (mode == 0 || mode == 3 || work->flags.bit.fallbackScript == 1) {
        *out = work->attackerPos ^ 1;
        return mode;
    }
    switch (work->params.kind) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
    case 5:
    case 8:
    case 10:
        if (mode == 1) {
            mode = 0;
            *out = !(work->attackerPos & 1);
        } else {
            attackerPos = work->attackerPos;
            if (attackerPos != 4 && attackerPos != 5) {
                mode = 1;
                *out = d_0220AD58[attackerPos];
            } else {
                *out = attackerPos ^ 1;
            }
        }
        break;
    case 7:
    case 9:
    case 13:
        *out = work->attackerPos ^ 1;
        break;
    case 11:
        mode = 0;
        *out = !(work->attackerPos & 1);
        break;
    case 6:
    case 12:
        mode = 0;
        *out = (work->attackerPos & 1) != 0;
        break;
    }
    return mode;
}

int BTLV_EFFVM_AllocEmitterSlot(BtlvEffVmWork *work, int key, int *out)
{
    int slot;
    int isNew = 1;

    for (slot = 0; slot < 16; slot++) {
        if (key == work->voiceIds[slot]) {
            isNew = 0;
            break;
        }
    }
    if (slot == 16) {
        for (slot = 0; slot < 16; slot++) {
            if (work->voiceIds[slot] == -1) {
                work->voiceIds[slot] = key;
                break;
            }
        }
    }
    *out = slot;
    return isNew;
}

void BTLV_EFFVM_SetEmitterHandle(BtlvEffVmWork *work, int slot, BtlvEffVmParticleResHeader *resource)
{
    work->soundHandles[slot] = resource->soundHandle;
}

int BTLV_EFFVM_FindEmitterSlot(BtlvEffVmWork *work, int key)
{
    int slot;

    for (slot = 0; slot < 16; slot++) {
        if (work->voiceIds[slot] == key)
            break;
    }
    return slot;
}

int BTLV_EFFVM_GetEmitterHandle(BtlvEffVmWork *work, int slot)
{
    return work->soundHandles[slot];
}

/*
 * 2026-10-02: the kind == 4 swap closed. It is a per-axis swap through
 * temps from a (tx = a.x; a.x = b.x; ...), then the sums read the new a:
 * b.x = tx + a.x. Grouped temps, temps from b and `b.x = b.x + tx` all
 * leave the spill on old b.y or the add operands reversed.
 */
void BTLV_EFFVM_ParticleStartCallback(void *emitter)
{
    BtlvEffVmVec srcPos;
    BtlvEffVmVec dstPos;
    BtlvEffVmVec emitterPos;
    BtlvEffVmVec rotAxis;
    BtlvEffVmVec travelDir;
    BtlvEffVmVec refAxis;
    MtxFx43 turnMatrix;
    BtlvEffVmVec fromDirXZ;
    BtlvEffVmVec toDirXZ;
    BtlvEffVmVec turnAxis;
    BtlvEffVmVec scaled;
    BtlvEffVmEmitterDir emitterDir;
    BtlvEffVmParticleReq *req;
    int flip;
    BtlvEffVmWork *work;
    BtlvEffVmEmitterMotion *motion;
    u16 angle;
    int oldScaleX, oldAlpha, oldAngle, oldScaleY;
    int dstMode;
    int swapX, swapY, swapZ;

    req = (BtlvEffVmParticleReq *)PARTICLE_GetCallbackArg();
    flip = req->flip;
    switch (req->srcKey) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        req->srcKey = BTLV_EFFVM_ResolveSideFromVm(req->vm, req->srcKey);
        break;
    case 9:
    case 11:
        req->srcKey = BTLV_EFFVM_ResolveSlotKey(req->vm, req->srcKey + 5);
        break;
    case 8:
        srcPos.x = req->fixedSrc.x;
        srcPos.y = req->fixedSrc.y;
        srcPos.z = req->fixedSrc.z;
        break;
    case 14: case 15: case 16: case 17:
        BTLV_MCSS_GetSlotPositionForRule((struct BtlvVec3 *)(BTLV_EFFECT_GetMcss()), (struct BtlvVec3 *)(&srcPos), req->srcKey - 12, 1);
        req->srcKey = -1;
        break;
    case 18: case 19: case 20: case 21:
        BTLV_MCSS_GetSlotPositionForRule((struct BtlvVec3 *)(BTLV_EFFECT_GetMcss()), (struct BtlvVec3 *)(&srcPos), req->srcKey - 16, 1);
        switch (req->srcKey) {
        case 18: srcPos.z += 0x1a00; break;
        case 19: srcPos.z += 0x2600; break;
        case 20: srcPos.z += 0x600; break;
        case 21: srcPos.z += 0x3900; break;
        }
        req->srcKey = -1;
        break;
    }
    if (req->srcKey != -1 && req->srcKey != 8)
        BTLV_MCSS_GetSlotPosition(BTLV_EFFECT_GetMcss(), (struct BtlvVec3 *)(&srcPos), req->srcKey);
    switch (req->dstKey) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        req->dstKey = BTLV_EFFVM_ResolveSideFromVm(req->vm, req->dstKey);
        break;
    case 9:
        req->dstKey = BTLV_EFFVM_ResolveSlotKey(req->vm, req->dstKey + 5);
        break;
    case 10:
        flip = 1;
        req->dstKey = BTLV_EFFVM_ResolveSlotKey(req->vm, req->dstKey + 4);
        break;
    case 12:
        flip = 1;
    case 11:
        dstMode = BTLV_EFFVM_ResolveAnchorSlot(req->vm, &req->dstKey);
        BTLV_MCSS_GetSlotPositionForRule((struct BtlvVec3 *)(BTLV_EFFECT_GetMcss()), (struct BtlvVec3 *)(&dstPos), req->dstKey, dstMode);
        req->dstKey = -1;
        break;
    case 8:
        dstPos.x = req->fixedDst.x;
        dstPos.y = req->fixedDst.y;
        dstPos.z = req->fixedDst.z;
        break;
    case 14: case 15: case 16: case 17:
        BTLV_MCSS_GetSlotPositionForRule((struct BtlvVec3 *)(BTLV_EFFECT_GetMcss()), (struct BtlvVec3 *)(&dstPos), req->dstKey - 12, 1);
        req->dstKey = -1;
        break;
    case 18: case 19: case 20: case 21:
        BTLV_MCSS_GetSlotPositionForRule((struct BtlvVec3 *)(BTLV_EFFECT_GetMcss()), (struct BtlvVec3 *)(&dstPos), req->dstKey - 16, 1);
        switch (req->srcKey) {
        case 18: dstPos.z += 0x1a00; break;
        case 19: dstPos.z += 0x2600; break;
        case 20: dstPos.z += 0x600; break;
        case 21: dstPos.z += 0x3900; break;
        }
        req->dstKey = -1;
        break;
    }
    if (req->dstKey != -1 && req->dstKey != 8)
        BTLV_MCSS_GetSlotPosition(BTLV_EFFECT_GetMcss(), (struct BtlvVec3 *)(&dstPos), req->dstKey);
    BTLV_EFFECT_GetMode();
    srcPos.z += 0x500;
    dstPos.z += 0x500;
    if ((u32)(req->mode - 1) <= 1) {
        BTLV_EFFVM_TransformVecByMtx44(&srcPos, (const BtlvEffVmVec *)(&req->offset));
        BTLV_EFFVM_TransformVecByMtx44(&dstPos, (const BtlvEffVmVec *)(&req->offset));
    } else if (req->mode == 3) {
        emitterPos.x = srcPos.x;
        emitterPos.y = srcPos.y;
        emitterPos.z = srcPos.z;
        srcPos.y += req->offset.y;
        BTLV_EFFVM_TransformVecByMtx44(&emitterPos, (const BtlvEffVmVec *)(&req->offset));
    } else {
        srcPos.y += req->offset.y;
    }
    dstPos.y += req->offset.y;
    if (req->motionKind != 0) {
        work = VM_GetContext((void *)req->vm);
        work->allocBuffers[work->allocBufferCount] = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x60, 0, d_0220AE68, 0x194a);
        motion = (BtlvEffVmEmitterMotion *)work->allocBuffers[work->allocBufferCount];
        PARTICLE_EMITTER_SetUserData(emitter, (int)motion);
        PARTICLE_EMITTER_SetCallback(emitter, (int)BTLV_EFFVM_ParticleMotionStep);
        work->allocBufferCount += 1;
        motion->phaseA = 0;
        motion->delayLeft = 0;
        motion->delayRate = 0;
        motion->delayAccel = 0;
        motion->kind = req->motionKind;
        motion->framesLeft = req->travelTime >> 12;
        motion->projectToScreen = req->mode;
        if (req->motionKind == 3) {
            motion->phaseStepA = FX_Div(0x6000000, req->travelTime);
        } else if ((u32)(req->motionKind - 5) <= 1) {
            motion->phaseStepA = FX_Div(0x8000000, req->travelTime);
            motion->phaseStepB = FX_Div(0x10000000, req->travelTime);
            motion->phaseStepB = MUL(motion->phaseStepB, req->wobbleScale);
        } else {
            motion->phaseStepA = FX_Div(0x8000000, req->travelTime);
        }
        if (motion->phaseStepA == 0)
            motion->phaseStepA = 1;
        motion->halfDistance = VEC_Distance((const BtlvEffVmVec *)&srcPos, (const BtlvEffVmVec *)&dstPos) / 2;
        if (req->motionKind == 1 || req->motionKind == 4)
            motion->amplitude = 0;
        else
            motion->amplitude = req->arcScale;
        if (req->motionKind == 4) {
            swapX = srcPos.x;
            srcPos.x = dstPos.x;
            swapY = srcPos.y;
            srcPos.y = dstPos.y;
            swapZ = srcPos.z;
            srcPos.z = dstPos.z;
            dstPos.x = swapX + srcPos.x;
            dstPos.y = swapY + srcPos.y;
            dstPos.z = swapZ + srcPos.z;
        }
        travelDir.x = dstPos.x - srcPos.x;
        travelDir.y = dstPos.y - srcPos.y;
        travelDir.z = dstPos.z - srcPos.z;
        VEC_Normalize((const BtlvEffVmVec *)&travelDir, &travelDir);
        refAxis.x = 0x1000;
        refAxis.y = 0;
        refAxis.z = 0;
        angle = FX_AcosIdx(VEC_DotProduct((const BtlvEffVmVec *)&refAxis, (const BtlvEffVmVec *)&travelDir));
        VEC_CrossProduct((const BtlvEffVmVec *)&refAxis, (const BtlvEffVmVec *)&travelDir, &rotAxis);
        VEC_Normalize((const BtlvEffVmVec *)&rotAxis, &rotAxis);
        MTX_RotAxis43((void *)motion, (void *)&rotAxis, FX_SinCosTable_[(angle >> 4) * 2], FX_SinCosTable_[(angle >> 4) * 2 + 1]);
        motion->pos.x = srcPos.x;
        motion->pos.y = srcPos.y;
        motion->pos.z = srcPos.z;
    }
    if (req->srcKey != 8 && req->dstKey != 8 && req->srcKey != req->dstKey) {
        emitterDir.mode = 2;
        dstPos.x -= srcPos.x;
        dstPos.y -= srcPos.y;
        dstPos.z -= srcPos.z;
        PARTICLE_EMITTER_SetBehavior2Data(emitter, &dstPos);
        PARTICLE_EMITTER_SetBehavior5Data(emitter, &dstPos);
        toDirXZ.x = dstPos.x;
        toDirXZ.y = 0;
        toDirXZ.z = dstPos.z;
        PARTICLE_EMITTER_GetRot(emitter, &emitterDir.dir);
        fromDirXZ.x = emitterDir.dir.x;
        fromDirXZ.y = 0;
        fromDirXZ.z = emitterDir.dir.z;
        VEC_Normalize((const BtlvEffVmVec *)&fromDirXZ, &fromDirXZ);
        VEC_Normalize((const BtlvEffVmVec *)&toDirXZ, &toDirXZ);
        angle = FX_AcosIdx(VEC_DotProduct((const BtlvEffVmVec *)&fromDirXZ, (const BtlvEffVmVec *)&toDirXZ));
        VEC_CrossProduct((const BtlvEffVmVec *)&fromDirXZ, (const BtlvEffVmVec *)&toDirXZ, &turnAxis);
        VEC_Normalize((const BtlvEffVmVec *)&turnAxis, &turnAxis);
        MTX_RotAxis43((void *)(&turnMatrix), (void *)&turnAxis, FX_SinCosTable_[(angle >> 4) * 2], FX_SinCosTable_[(angle >> 4) * 2 + 1]);
        fromDirXZ.x = emitterDir.dir.x;
        fromDirXZ.y = emitterDir.dir.y;
        fromDirXZ.z = emitterDir.dir.z;
        MTX_MultVec43((const BtlvEffVmVec *)&fromDirXZ, &turnMatrix, &fromDirXZ);
        VEC_Normalize((const BtlvEffVmVec *)&fromDirXZ, &fromDirXZ);
        if (flip == 1) {
            fromDirXZ.x *= -1;
            fromDirXZ.z *= -1;
        }
        emitterDir.dir.x = fromDirXZ.x;
        emitterDir.dir.y = fromDirXZ.y;
        emitterDir.dir.z = fromDirXZ.z;
        if (angle < 0x2000 || (angle > 0x6000 && angle < 0xa000) || angle > 0xe000)
            emitterDir.mode = 0;
        PARTICLE_EMITTER_SetBehavior3Half(emitter, &emitterDir.mode);
        PARTICLE_EMITTER_SetRot(emitter, &emitterDir.dir);
    }
    if ((req->mode != 0 && (req->srcKey & 1)) || req->mode == 0 || (u32)(req->mode - 2) <= 1) {
        oldScaleX = PARTICLE_EMITTER_GetScaleX(emitter);
        oldAlpha = PARTICLE_EMITTER_GetAlpha(emitter) << 12;
        oldAngle = PARTICLE_EMITTER_GetAngle(emitter);
        oldScaleY = PARTICLE_EMITTER_GetScaleY(emitter);
        if (req->scaleX != 0) {
            PARTICLE_EMITTER_SetScaleX(emitter, MUL(oldScaleX, req->scaleX));
            PARTICLE_EMITTER_SetScaleY(emitter, MUL(oldScaleY, req->scaleX));
        }
        if (req->alphaScale != 0)
            PARTICLE_EMITTER_SetAlpha(emitter, (u16)(MUL(oldAlpha, req->alphaScale) >> 12));
        if (req->angleScale != 0)
            PARTICLE_EMITTER_SetAngle(emitter, (s16)MUL(oldAngle, req->angleScale));
        if (req->posScale != 0) {
            PARTICLE_EMITTER_GetPos(emitter, &scaled);
            scaled.x = MUL(scaled.x, req->posScale);
            scaled.y = MUL(scaled.y, req->posScale);
            scaled.z = MUL(scaled.z, req->posScale);
            PARTICLE_EMITTER_SetPos(emitter, (const BtlvEffVmVec *)&scaled);
            oldScaleX = PARTICLE_EMITTER_GetOffsetX(emitter);
            PARTICLE_EMITTER_SetOffsetX(emitter, (s16)MUL(oldScaleX, req->posScale));
            oldScaleX = PARTICLE_EMITTER_GetOffsetY(emitter);
            PARTICLE_EMITTER_SetOffsetY(emitter, (s16)MUL(oldScaleX, req->posScale));
        }
    }
    if (req->mode == 3)
        PARTICLE_EMITTER_SetEmitPos(emitter, (const BtlvEffVmVec *)&emitterPos);
    else
        PARTICLE_EMITTER_SetEmitPos(emitter, (const BtlvEffVmVec *)&srcPos);
    GFL_HEAP_Free(req);
}

#undef MUL
#define MUL(a,b) ((int)(((long long)(a) * (b) + 0x800) >> 12))

/*
 * The 5 and default arms are separate `else if` / `else` blocks with the
 * whole MUL repeated; the compiler cross-jumps their common tail, and the
 * 0 high word of the rounding addend stays CSE'd in r4 across all three
 * arms (a ternary index colours it differently).
 * Caller BTLV_EFFVM_ParticleStartCallback (same lane) shows s is a 0x60 object: 3x3 matrix,
 * pos at 0x24, counters from 0x30.
 */
void BTLV_EFFVM_ParticleMotionStep(void *emitter, int active)
{
    BtlvEffVmVec pos;
    u16 angleA;
    u16 angleB;
    BtlvEffVmEmitterMotion *motion;

    motion = (BtlvEffVmEmitterMotion *)PARTICLE_EMITTER_GetUserData(emitter);
    if (motion->framesLeft == 0 || active == 0)
        return;
    if (motion->kind == 3) {
        if (motion->delayLeft != 0) {
            motion->delayLeft--;
            return;
        }
        motion->delayAccel += 0xc;
        motion->delayRate += motion->delayAccel;
        motion->delayLeft = motion->delayRate >> 12;
    }
    motion->framesLeft--;
    motion->phaseA += motion->phaseStepA;
    motion->phaseB += motion->phaseStepB;
    angleA = (motion->phaseA >> 12) + 0xc000;
    angleB = (motion->phaseB >> 12) + 0xc000;
    pos.x = FX_SinCosTable_[(angleA >> 4) * 2];
    pos.x = MUL(pos.x, motion->halfDistance);
    pos.x += motion->halfDistance;
    if (motion->kind == 6) {
        pos.z = FX_SinCosTable_[(angleB >> 4) * 2 + 1];
        pos.z = MUL(pos.z, motion->amplitude);
        pos.y = 0;
    } else if (motion->kind == 5) {
        pos.y = FX_SinCosTable_[(angleB >> 4) * 2 + 1];
        pos.y = MUL(pos.y, motion->amplitude);
        pos.z = 0;
    } else {
        pos.y = FX_SinCosTable_[(angleA >> 4) * 2 + 1];
        pos.y = MUL(pos.y, motion->amplitude);
        pos.z = 0;
    }
    MTX_MultVec43(&pos, motion, &pos);
    if (motion->projectToScreen != 0)
        BTLV_EFFVM_TransformVecByMtx44((&pos), (const BtlvEffVmVec *)((const BtlvEffVmVec *)0));
    PARTICLE_EMITTER_SetEmitPos(emitter, (const BtlvEffVmVec *)&pos);
}

void BTLV_EFFVM_EmitterInitCallback(void *emitter)
{
    BtlvEffVmCircleMotion *motion = (BtlvEffVmCircleMotion *)PARTICLE_GetCallbackArg();

    if (motion->projectToScreen != 0 && motion->center.z < 0)
        PARTICLE_EMITTER_SetAngle(emitter, 0x800);
    PARTICLE_EMITTER_SetUserData(emitter, (int)motion);
    PARTICLE_EMITTER_SetCallback(emitter, (int)BTLV_EFFVM_EmitterMoveCallbackB);
}

void BTLV_EFFVM_EmitterMoveCallbackB(void *emitter, int active)
{
    BtlvEffVmCircleMotion *motion;
    BtlvEffVmVec pos;
    motion = (BtlvEffVmCircleMotion *)PARTICLE_EMITTER_GetUserData(emitter);
    if (active == 0)
        return;
    if (motion->pauseCounter == 0) {
        if (motion->intervalCounter == 0) {
            motion->intervalCounter = motion->interval;
            if (motion->anchorKind & 1)
                motion->phase -= motion->phaseStep;
            else
                motion->phase += motion->phaseStep;
            motion->phase = (u16)motion->phase;
            pos.x = FX_SinCosTable_[(motion->phase >> 4) * 2];
            pos.x = MUL(pos.x, motion->radiusX);
            pos.x += motion->center.x;
            pos.y = motion->center.y;
            pos.z = FX_SinCosTable_[(motion->phase >> 4) * 2 + 1];
            pos.z = MUL(pos.z, motion->radiusZ);
            pos.z += motion->center.z;
            if (motion->projectToScreen != 0)
                BTLV_EFFVM_TransformVecByMtx44((&pos), (const BtlvEffVmVec *)((const BtlvEffVmVec *)0));
            PARTICLE_EMITTER_SetEmitPos(emitter, (const BtlvEffVmVec *)&pos);
            if (motion->stepsLeft != 0) {
                motion->stepsLeft--;
            } else {
                motion->stepsLeft = motion->stepsPerCycle;
                motion->pauseCounter = motion->pauseFrames;
            }
        } else {
            motion->intervalCounter--;
        }
    } else {
        motion->pauseCounter--;
    }
}

void BTLV_EFFVM_DeleteEmitter(void *emitter)
{
    void *q = PARTICLE_GetWorkBase(emitter);

    PARTICLE_DeleteSystem(emitter);
    GFL_HEAP_Free(q);
}

void BTLV_EFFVM_RefreshMcssOrtho(BtlvEffVmWork *work)
{
    if (work->layoutMode == 1)
        BTLV_MCSS_DisableOrthoMode(BTLV_EFFECT_GetMcss());
    else
        BTLV_MCSS_EnableOrthoMode(BTLV_EFFECT_GetMcss());
}

void BTLV_EFFVM_PlaySeWithParams(u32 seId, int slot, int pan, int pitch, unsigned int volume, unsigned int modDepth, unsigned int modSpeed)
{
    if (slot == 5) {
        GFL_USE_PlaySeDefaultVolume(seId);
        slot = GFL_USE_GetSeSlot(seId);
    } else {
        GFL_USE_PlaySeInSlot((u32)seId, slot);
    }
    NNS_SndHandleSetVolume(GFL_USE_GetSeHandle(slot), volume);
    GFL_USE_SetSeSlotParams(slot, -1, -1, pan);
    GFL_USE_SetSeSlotParams(slot, -1, pitch, -1);
    if (modDepth) {
        NNS_SndHandleSetTrackModDepth(GFL_USE_GetSeHandle(slot), 0xffff, modDepth);
        NNS_SndHandleSetTrackModSpeed(GFL_USE_GetSeHandle(slot), 0xffff, modSpeed);
    }
}

/*
 * leaves: parent-cleared ov094 getters 0x021F8730 and 0x021F8740 filed separately.
 * domain: selector values 0..57; out-of-range result is unspecified.
 */
int BTLV_EFFVM_EvalCondition(BtlvEffVmWork *work, unsigned int key)
{
    switch (key) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        return BTLV_MCSS_GetSpriteWeight(BTLV_EFFECT_GetMcss(), key);
    case 8: return BTLV_MCSS_GetSpriteWeight(BTLV_EFFECT_GetMcss(), work->attackerPos);
    case 9: return work->params.kind;
    case 10: return work->params.variant;
    case 11: return work->params.option;
    case 12: return work->params.side;
    case 13: return work->params.argA;
    case 14: return work->params.argB;
    case 15: return work->params.typeCode;
    case 16: return work->scriptVar;
    case 17: return work->attackerPos;
    case 18: return BTLV_MCSS_IsVanished(BTLV_EFFECT_GetMcss(), work->attackerPos);
    case 19: return work->attackerPos & 1;
    case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27:
        if (BTLV_MCSS_GetSpriteAttrFlags(BTLV_EFFECT_GetMcss(), key - 20) & 2)
            return 1;
        return 0;
    case 28:
        if (BTLV_MCSS_GetSpriteAttrFlags(BTLV_EFFECT_GetMcss(), work->attackerPos) & 2)
            return 1;
        return 0;
    case 29: case 30: case 31: case 32: case 33: case 34: case 35: case 36:
        return BTLV_MCSS_HasPersonalParam10(BTLV_EFFECT_GetMcss(), key - 29);
    case 37: return BTLV_MCSS_HasPersonalParam10(BTLV_EFFECT_GetMcss(), work->attackerPos);
    case 38: return BTLV_EFFECT_IsMultiMode();
    case 39: return BTLV_EFFECT_GetMode();
    case 40: case 41: case 42: case 43: return BTLV_EFFECT_GetTrainerType(key - 40);
    case 44: case 45: case 46: case 47: case 48: case 49: case 50: case 51:
        return BTLV_MCSS_GetStopCellFlags(BTLV_EFFECT_GetMcss(), key - 44);
    case 52: return BTLV_MCSS_GetStopCellFlags(BTLV_EFFECT_GetMcss(), work->attackerPos);
    case 53: return work->flags.bit.cameraOffset;
    case 54: return work->camVecSaved;
    case 55: return work->scratchVar;
    case 56: return work->flags.bit.cameraLocked;
    case 57: return work->defenderPos;
    }
}

/*
 * lever: declare count before n to place them at sp+0x18 and sp+0x14;
 *   reversed declarations produced five differing spill/reload bytes.
 */
void BTLV_EFFVM_StartParticleEffectInternal(BtlvEffVmWork *work, BtlvEffVmParticleReq *req, int slot, int arg)
{
    int targets[8];
    int keys[8];
    int count;
    int keyCount;
    int i;
    BtlvEffVmParticleReq *reqCopy;

    if (req->dstKey == req->srcKey && (u32)(req->dstKey - 11) <= 1) {
        if (req->dstKey == 12)
            req->flip = 1;
        count = BTLV_EFFVM_ResolveBattlerListExpanded(work, 16, targets);
        if (count != 0) {
            for (i = 0; i < count; i++) {
                reqCopy = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x1c0e);
                *reqCopy = *req;
                reqCopy->srcKey = targets[i];
                reqCopy->dstKey = targets[i];
                if (PARTICLE_StartEffectWithCallback(work->emitters[slot], arg, BTLV_EFFVM_ParticleStartCallback, (int)reqCopy) == -1)
                    GFL_HEAP_Free(reqCopy);
            }
        }
    } else if (req->dstKey == req->srcKey && work->params.kind == 12 && !work->flags.bit.fallbackScript && work->effectId != 0x16e && (u32)(req->dstKey - 9) <= 1) {
        if (req->dstKey == 10)
            req->flip = 1;
        switch (BTLV_EFFECT_GetMode()) {
        default:
        case 0: case 3:
            keys[0] = work->attackerPos;
            keyCount = 1;
            break;
        case 1:
            keys[0] = (work->attackerPos & 1) ? 1 : 0;
            keyCount = 1;
            break;
        case 2:
            keys[0] = (work->attackerPos & 1) ? 19 : 18;
            keys[1] = (work->attackerPos & 1) ? 21 : 20;
            keyCount = 2;
            break;
        }
        if (keyCount != 0) {
            for (i = 0; i < keyCount; i++) {
                reqCopy = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x1c45);
                *reqCopy = *req;
                reqCopy->srcKey = keys[i];
                reqCopy->dstKey = keys[i];
                if (PARTICLE_StartEffectWithCallback(work->emitters[slot], arg, BTLV_EFFVM_ParticleStartCallback, (int)reqCopy) == -1)
                    GFL_HEAP_Free(reqCopy);
            }
        }
    } else {
        reqCopy = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x1c56);
        *reqCopy = *req;
        if (PARTICLE_StartEffectWithCallback(work->emitters[slot], arg, BTLV_EFFVM_ParticleStartCallback, (int)reqCopy) == -1)
            GFL_HEAP_Free(reqCopy);
    }
}

int BTLV_EFFVM_SetupEmitterCallbacks(void *vm, BtlvEffVmWork *work, int mode)
{
    BtlvEffVmCircleMotion *motion;
    int idx;
    int effectIdx;
    int heightOffset;
    int anchorPos;

    idx = BTLV_EFFVM_FindEmitterSlot(work, BTLV_EFFVM_ResolveParticleKey(work, VM_GetU32(vm)));
    effectIdx = VM_GetU32(vm);
    anchorPos = 0;
    work->allocBuffers[work->allocBufferCount] = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x40, 0, d_0220AE68, 0x1c79);
    motion = work->allocBuffers[work->allocBufferCount];
    work->allocBufferCount += 1;
    motion->anchorKind = VM_GetU32(vm);
    motion->radiusX = VM_GetU32(vm);
    motion->radiusZ = VM_GetU32(vm);
    heightOffset = VM_GetU32(vm);
    motion->phase = 0;
    motion->stepsPerCycle = motion->stepsLeft = VM_GetU32(vm);
    motion->intervalCounter = 0;
    motion->interval = VM_GetU32(vm);
    motion->scriptArg12 = VM_GetU32(vm);
    motion->pauseCounter = 0;
    motion->pauseFrames = VM_GetU32(vm);
    motion->phaseStep = 0x10000 / motion->stepsLeft;
    motion->projectToScreen = mode;
    if (idx == 16)
        goto end;
    if (mode == 1) {
        if (PARTICLE_EMITTER_GetBlock((struct Obj3D *)work->emitters[idx]) == 0) {
            struct ParticleCameraParams projection;
            BtlvEffVmVec cameraPos = {0, 0, 0};
            BtlvEffVmVec cameraTarget;
            BtlvEffVmVec cameraUp;
            cameraTarget = d_02209E10;
            cameraUp = d_02209DB4;
            projection.projType = 2;
            projection.fovSin = 0x3000;
            projection.fovCos = 0xffffd000;
            projection.aspect = 0xffffc000;
            projection.orthoExtent = 0x4000;
            projection.nearZ = 0x1000;
            projection.farZ = 0x200000;
            projection.projScale = 0x1000;
            PARTICLE_InitCamera(work->emitters[idx], &projection, 0x2000, &cameraPos, &cameraTarget, &cameraUp, (work->heapId & 0x7fff) | 0x8000);
        }
    }
    switch (motion->anchorKind) {
    case 0:
    case 1:
        anchorPos = BTLV_EFFVM_ResolveSlotKey(vm, 14);
        BTLV_MCSS_GetSlotPosition(BTLV_EFFECT_GetMcss(), (struct BtlvVec3 *)(&motion->center), anchorPos);
        break;
    case 2:
    case 3:
        anchorPos = BTLV_EFFVM_ResolveSlotKey(vm, 16);
        BTLV_MCSS_GetSlotPosition(BTLV_EFFECT_GetMcss(), (struct BtlvVec3 *)(&motion->center), anchorPos);
        break;
    case 4:
    case 5:
        motion->center.x = 0;
        motion->center.y = 0;
        motion->center.z = 0;
        break;
    }
    if (anchorPos & 1)
        motion->phase = 0x8000;
    motion->center.y += heightOffset;
    if (PARTICLE_StartEffectWithCallback(work->emitters[idx], effectIdx, BTLV_EFFVM_EmitterInitCallback, (int)motion) == -1)
        GFL_HEAP_Free(motion);
end:
    return work->result;
}

void BTLV_EFFVM_TransformVecByMtx44(BtlvEffVmVec *pos, const BtlvEffVmVec *ofs)
{
    fx32 clipW;
    MtxFx44 projection;

    MTX_Copy43To44_(&g_renderStateDrawParams, &projection);
    MTX_Concat44(&projection, &SCREENTEX_ProjectionMatrix, &projection);
    if (ofs != 0) {
        pos->x += ofs->x;
        pos->y += ofs->y;
        pos->z += ofs->z;
    }
    BTLV_EFFVM_TransformVecByMtx43((const BtlvEffVmVec *)((const BtlvEffVmVec *)pos), &projection, (fx32 *)((BtlvEffVmVec *)pos), &clipW);
    pos->x = FX_MUL(FX_Div(pos->x, clipW), 0x4000);
    pos->y = FX_MUL(FX_Div(pos->y, clipW), 0x3000);
    pos->z = -pos->z;
}

void BTLV_EFFVM_TransformVecByMtx43(const BtlvEffVmVec *vec, const MtxFx44 *matrix, fx32 *out, fx32 *clipW)
{
    fx64 vy = vec->y;
    fx64 vx = vec->x;
    fx64 vz = vec->z;
    fx64 sum;

    sum = vz * matrix->m[2][0] + (vx * matrix->m[0][0] + vy * matrix->m[1][0]);
    out[0] = (fx32)(sum >> 12) + matrix->m[3][0];
    sum = vz * matrix->m[2][1] + (vx * matrix->m[0][1] + vy * matrix->m[1][1]);
    out[1] = (fx32)(sum >> 12) + matrix->m[3][1];
    sum = vz * matrix->m[2][2] + (vx * matrix->m[0][2] + vy * matrix->m[1][2]);
    out[2] = (fx32)(sum >> 12) + matrix->m[3][2];
    sum = vz * matrix->m[2][3] + (vx * matrix->m[0][3] + vy * matrix->m[1][3]);
    *clipW = (fx32)(sum >> 12) + matrix->m[3][3];
}

/*
 * Levers: v and k unsigned (bhi/bhs/blo compares); the middle arm is
 * `mode != 8` and the mode==8 arm last, which puts its block after the
 * cross-jumped BTLV_MCSS_GetSpriteColorCode call.
 */
unsigned int BTLV_EFFVM_ResolveParticleKey(BtlvEffVmWork *work, unsigned int key)
{
    int mode = work->typeSource;
    unsigned int typeIdx;

    if (mode == 9)
        typeIdx = BTLV_MCSS_GetSpriteColorCode(BTLV_EFFECT_GetMcss(), work->attackerPos);
    else if (mode != 8)
        typeIdx = BTLV_MCSS_GetSpriteColorCode(BTLV_EFFECT_GetMcss(), mode);
    else
        typeIdx = PALANM_GetPairedCodeForFirst(work->params.typeCode);
    if (typeIdx == 0 || typeIdx > 0x19)
        typeIdx = 4;
    typeIdx--;
    switch (key) {
    case 3:
        key += typeIdx;
        break;
    case 0x1d:
        if (typeIdx + 1 == 0x19)
            typeIdx = 0x10;
        else if (typeIdx + 1 >= 0x10)
            typeIdx = 3;
        key += typeIdx;
        break;
    case 0x2e:
    case 0x2f:
    case 0x30:
    case 0x31:
        key += typeIdx << 2;
        break;
    }
    return key;
}

/*
 * Sets/clears the fading and fadeRestart flags of *o, allocates a 0x10-byte record
 * (heap from heapId), converts n to fx32 (n<<12, +-0.5 rounding)
 * and registers BTLV_EFFVM_DelayTaskMain as a task callback through TCB_AddTask.
 */
void BTLV_EFFVM_StartSeVolumeTweenTask(BtlvEffVmWork *work, int fromLevel, int toLevel, int steps)
{
    BtlvEffVmFadeJob *job;
    int stepFx;

    if (fromLevel > toLevel) {
        if (work->flags.bit.fading) {
            work->flags.bit.fadeRestart = 1;
            return;
        }
        work->flags.bit.fading = 1;
    } else {
        work->flags.bit.fading = 0;
    }
    job = GFL_HEAP_Alloc((u16)(((u16)work->heapId & 0x7fff) | 0x8000), 0x10, 0, d_0220AE68, 0x1d78);
    job->current = fromLevel;
    job->target = toLevel;
    job->flags = &work->flags;
    if (steps > 0)
        stepFx = (int)(0.5f + (float)(steps << 12));
    else
        stepFx = (int)((float)(steps << 12) - 0.5f);
    BTLV_EFFECT_ComputeScalarStep(job->current, job->target, &job->step, stepFx);
    BTLV_EFFECT_RegisterTask((void *)TCB_AddTask((void *)work->owner, BTLV_EFFVM_DelayTaskMain, job, 0), 0, 1);
}

int BTLV_EFFVM_FindFreeSeSlot(BtlvEffVmWork *work)
{
    int slot;

    for (slot = 0; slot < 6; slot++) {
        if (work->seVoiceIds[slot] == -1)
            break;
    }
    if (slot == 6)
        slot = 0;
    return slot;
}

void BTLV_EFFVM_ResetPokePositionIfLoaded(void *unused)
{
    BtlvMcssPos i;

    for (i = 0; i < 8; i++) {
        if (BTLV_MCSS_IsSpriteLoaded(BTLV_EFFECT_GetMcss(), i) == 1)
            BTLV_MCSS_ResetSpritePosition(BTLV_EFFECT_GetMcss(), i);
    }
}

void BTLV_EFFVM_SetShadowVanishIfLoaded(void *unused)
{
    BtlvMcssPos i;

    for (i = 0; i < 8; i++) {
        if (BTLV_MCSS_IsSpriteLoaded(BTLV_EFFECT_GetMcss(), i) == 1)
            BTLV_MCSS_SetShadowVanish(BTLV_EFFECT_GetMcss(), i, 0);
    }
}

void BTLV_EFFVM_SePlayTaskMain(void *task, void *arg)
{
    BtlvEffVmSePlayJob *job = arg;

    if (--job->delay == 0) {
        BTLV_EFFVM_PlaySeWithParams(job->seId, job->slot, job->pan, job->pitch, job->volume, job->modDepth, job->modSpeed);
        BTLV_EFFECT_DeleteTask(task);
    }
}

void BTLV_EFFVM_SePlayTaskEnd(void *task)
{
    BtlvEffVmWork *work = *((BtlvEffVmWork **)TCBL_IsDeletePending(task));

    work->flags.word &= ~4u;
}

/*
 * trailing: two zero alignment bytes at 0x021FE68E.
 */
void BTLV_EFFVM_SeVolumeTweenTaskMain(void *task, void *arg)
{
    BtlvEffVmSeRampJob *job = arg;

    int done;
    int level;
    done = 0;
    if (job->startDelay != 0) {
        job->startDelay--;
        return;
    }
    if (job->frameCounter == 0) {
        job->frameCounter = job->framesPerStep;
        job->current += job->delta;
        level = job->current >> 12;
        if (job->passes & 1) {
            if (job->delta < 0) {
                if (level < job->from)
                    level = job->from;
            } else {
                if (level > job->from)
                    level = job->from;
            }
        } else {
            if (job->delta < 0) {
                if (level < job->to)
                    level = job->to;
            } else {
                if (level > job->to)
                    level = job->to;
            }
        }
        if (level > 0)
            job->current = (int)(0.5f + (float)(level << 12));
        else
            job->current = (int)((float)(level << 12) - 0.5f);
        switch (job->param) {
        case 0: GFL_USE_SetSeSlotParams(job->slot, -1, level, -1); break;
        case 1: NNS_SndHandleSetVolume(GFL_USE_GetSeHandle(job->slot), level); break;
        case 2: GFL_USE_SetSeSlotParams(job->slot, -1, -1, level); break;
        }
        if (job->stepsLeft == 0) {
            job->stepsLeft = job->stepCount;
            switch (job->mode) {
            case 0: done = 1; break;
            case 1:
                job->passes--;
                if (job->passes != 0)
                    job->delta *= -1;
                else
                    done = 1;
                break;
            }
        } else {
            job->stepsLeft--;
        }
    } else {
        job->frameCounter--;
    }
    if (done == 1)
        BTLV_EFFECT_DeleteTask(task);
}

void BTLV_EFFVM_SeVolumeTweenTaskEnd(void *task)
{
    BtlvEffVmWork *work = *((BtlvEffVmWork **)TCBL_IsDeletePending(task));

    work->flags.word &= ~8u;
}

void BTLV_EFFVM_SeModulationTaskMain(void *task, void *arg)
{
    BtlvEffVmCryJob *job = arg;

    int slot;
    BtlvEffVmFadeWaitJob *wait;

    job->delay--;
    if (job->delay != 0)
        return;
    slot = BTLV_EFFVM_FindFreeSeSlot(job->work);
    job->work->seVoiceIds[slot] =
        BTLV_MCSS_PlayCry(BTLV_EFFECT_GetMcss(), job->battlerPos, job->pitch, job->pan, job->chorusParamA, job->chorusParamB, job->chorusParamC);
    BTLV_EFFVM_StartSeVolumeTweenTask(job->work, 0x7f000, 0x6b000, 10);
    if (!job->work->flags.bit.fadeRestart) {
        wait = GFL_HEAP_Alloc((u16)(((u16)job->work->heapId & 0x7fff) | 0x8000), 4, 0, d_0220AE68, 0x1e6d);
        wait->work = job->work;
        BTLV_EFFECT_RegisterTask((void *)TCB_AddTask((void *)job->work->owner, BTLV_EFFVM_WaitVoiceTaskMain, wait, 0), 0, 0);
    }
    BTLV_EFFECT_DeleteTask(task);
}

void BTLV_EFFVM_SeModulationTaskEnd(void *task)
{
    BtlvEffVmWork *work = *((BtlvEffVmWork **)TCBL_IsDeletePending(task));

    work->flags.word &= ~0x800u;
}

void BTLV_EFFVM_DelayTaskMain(void *task, void *arg)
{
    BtlvEffVmFadeJob *job = arg;

    int flag = 1;

    BTLV_EFFECT_StepScalarWithLimit(&job->current, &job->step, &job->target, &flag);
    GFL_NET_SetBgmTrackVolumeUnlessVoiceChat((void *)0xffff, (void *)(job->current >> 12));
    if (flag)
        BTLV_EFFECT_DeleteTask(task);
}

static inline void window0(int x1, int y1, int x2, int y2)
{
    REG16(0x04000040) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000044) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}

static inline void window1(int x1, int y1, int x2, int y2)
{
    REG16(0x04000042) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000046) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}

/*
 * volatile: WININ re-read at 0x021FE7BE; WINOUT and display register accesses.
 */
void BTLV_EFFVM_BlendRegisterTaskMain(void *task, void *arg)
{
    BtlvEffVmWindowWipeJob *job = arg;

    switch (job->state) {
    case 0:
        REG16(0x04000048) = (u16)((REG16(0x04000048) & ~0x3f) | (u8)job->windowBits);
        REG16(0x04000048) = (u16)((REG16(0x04000048) & ~0x3f00) | (u16)(job->windowBits << 8));
        REG16(0x0400004a) = (u16)((REG16(0x0400004a) & ~0x3f) | ((job->windowBits & 0xff00) >> 8));
        REG32(0x04000000) = (REG32(0x04000000) & ~0xe000) | 0x6000;
        REG16(0x04000042) = 0;
        REG16(0x04000046) = 0;
        job->state++;
    case 1:
        if (job->frameCounter == 0) {
            job->frameCounter = job->framesPerStep;
            switch (job->direction) {
            case 0: job->edgeY -= 0x100; job->edgeY++; break;
            case 1: job->edgeY += 0x100; job->edgeY--; break;
            case 2: job->edgeX -= 0x100; job->edgeX++; break;
            case 3: job->edgeX += 0x100; job->edgeX--; break;
            }
            window0(job->edgeX >> 8, job->edgeY >> 8, job->edgeX, job->edgeY);
            if ((u8)job->edgeX == 0xff) {
                window1(1, job->edgeY >> 8, 0, job->edgeY);
            } else {
                window1(0, 0, 0, 0);
            }
            job->stepsLeft--;
            if (job->stepsLeft == 0)
                BTLV_EFFECT_DeleteTask(task);
        } else {
            job->frameCounter--;
        }
        break;
    }
}

void BTLV_EFFVM_BlendRegisterTaskEnd(void *task)
{
    BtlvEffVmWindowWipeJob *job = (BtlvEffVmWindowWipeJob *)TCBL_IsDeletePending(task);

    if (job->keepWindow == 0)
        *(volatile unsigned int *)0x04000000 &= ~0xE000u;
    job->work->flags.word &= ~0x100u;
}

void BTLV_EFFVM_WaitVoiceTaskMain(void *task, void *arg)
{
    BtlvEffVmFadeWaitJob *job = arg;

    int i;

    for (i = 0; i < 6; i++) {
        if (job->work->seVoiceIds[i] != -1) {
            if (PM_VOICE_IsSlotActive(job->work->seVoiceIds[i]) != 0)
                return;
            job->work->seVoiceIds[i] = -1;
        }
    }
    BTLV_EFFVM_StartSeVolumeTweenTask(job->work, 0x6b000, 0x7f000, 10);
    job->work->flags.bit.fadeRestart = 0;
    BTLV_EFFECT_DeleteTask(task);
}

/*
 * Lever: the `mask |= 1 << i` tail is written out in both arms (then-arm
 * innermost, and the else arm); the compiler cross-jumps them and leaves the
 * `b` to the next instruction.  A single shared tail (goto/continue) gives no
 * `b` and hoists r7/r4 in the other order.
 */
void BTLV_EFFVM_MultiPokeTaskMain(void *task, void *arg)
{
    BtlvEffVmSlotSweepJob *job = arg;

    int i = 1;
    int want;

    if (job->side == 0)
        i = 0;
    if (job->side != 0)
        want = 0xaa;
    else
        want = 0x55;
    while (i <= 7) {
        if (BTLV_EFFECT_IsPokeSpriteLoaded(i)) {
            if (BTLV_MCSS_IsSpriteBusy(BTLV_EFFECT_GetMcss(), i) == 0) {
                if ((BTLV_EFFECT_GetBitMask(i) & job->doneMask) == 0) {
                    BTLV_MCSS_SetAnimStopMode(BTLV_EFFECT_GetMcss(), i, 0);
                    BTLV_MCSS_SetShadowVanish(BTLV_EFFECT_GetMcss(), i, 0);
                    job->doneMask |= BTLV_EFFECT_GetBitMask(i);
                }
            }
        } else {
            job->doneMask |= BTLV_EFFECT_GetBitMask(i);
        }
        i += 2;
    }
    if (want == job->doneMask)
        BTLV_EFFECT_DeleteTask(task);
}

void BTLV_EFFVM_ParticleLoadTaskMain(void *task, void *arg)
{
    BtlvEffVmParticleLoadJob *job = arg;

    u16 line = *(volatile u16 *)0x04000006;

    if (line >= 0xc0 && line <= 0xc8) {
        PARTICLE_ApplyLoadHandlers(job->emitter);
        job->work->flags.word &= ~0x10000u;
        BTLV_EFFECT_DeleteTask(task);
    }
}

/*
 * Lever: the loop counter is an enum (keeps the `cmp r4,#8; bge` entry guard
 * and the unfolded (1<<12)>>1 rounding constants after it), see
 * docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md.
 */
void BTLV_EFFVM_SpriteCleanupTaskMain(fx32 scaleEven, fx32 scaleOdd, int frames, int waitFrames, int repeats)
{
    BtlvMcssPos i;
    BtlvEffVmVec scale;
    fx32 curScale;
    fx32 newScale;

    BTLV_MCSS_SetSideScale(BTLV_EFFECT_GetMcss(), scaleEven, scaleOdd);
    for (i = 0; i < 8; i++) {
        if (BTLV_MCSS_IsSpriteLoaded(BTLV_EFFECT_GetMcss(), i)) {
            curScale = BTLV_MCSS_GetSlotScale(BTLV_EFFECT_GetMcss(), i, 1);
            if (i & 1)
                newScale = (fx32)(((fx64)curScale * scaleOdd + ((fx64)(1 << 12) >> 1)) >> 12);
            else
                newScale = (fx32)(((fx64)curScale * scaleEven + ((fx64)(1 << 12) >> 1)) >> 12);
            scale.x = newScale;
            scale.y = newScale;
            scale.z = 1 << 12;
            BTLV_MCSS_StartScaleTween(BTLV_EFFECT_GetMcss(), i, 1, (struct BtlvVec3 *)(&scale), frames, waitFrames, repeats);
        }
    }
}

int BTLV_EFFVM_IsMultiSideResourceId(int effectId)
{
    unsigned int i;

    for (i = 0; i < 11; i++) {
        if (effectId == d_02209DD8[i])
            return 1;
    }
    return 0;
}
