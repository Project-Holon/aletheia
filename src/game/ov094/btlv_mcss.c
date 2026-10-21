/*
 * file:     btlv_mcss.c
 * unit:     yes
 * function: BTLV_MCSS_Create, BTLV_MCSS_Delete, BTLV_MCSS_Update, BTLV_MCSS_Draw, BTLV_MCSS_AddPoke, BTLV_MCSS_AddTrainer, BTLV_MCSS_RemoveSprite, BTLV_MCSS_SetSideScale, BTLV_MCSS_SetPosition, BTLV_MCSS_EnableOrthoMode, BTLV_MCSS_DisableOrthoMode, BTLV_MCSS_EnableBillboard, BTLV_MCSS_DisableBillboard, BTLV_MCSS_SetBlinkMode, BTLV_MCSS_IsAnimStopped, BTLV_MCSS_SetAnimStopMode, BTLV_MCSS_IsVanished, BTLV_MCSS_SetVanishMode, BTLV_MCSS_GetSlotPosition, BTLV_MCSS_GetSlotPositionForRule, BTLV_MCSS_GetSlotScale, BTLV_MCSS_SetShadowVanish, BTLV_MCSS_SetAnimSpeed, BTLV_MCSS_StartPositionTween, BTLV_MCSS_StartShadowScaleTween, BTLV_MCSS_StartScaleTween, BTLV_MCSS_StartDrawScaleTween, BTLV_MCSS_StartRotateTween, BTLV_MCSS_SwapSprites, BTLV_MCSS_StartBlinkTask, BTLV_MCSS_StartAlphaTween, BTLV_MCSS_StartShakeTask, BTLV_MCSS_StartBounceTask, BTLV_MCSS_StartMosaicTween, BTLV_MCSS_IsSpriteBusy, BTLV_MCSS_IsAnySpriteBusy, BTLV_MCSS_IsSpriteLoaded, BTLV_MCSS_SetPaletteFade, BTLV_MCSS_StartPaletteTrans, BTLV_MCSS_StartPaletteCopy, BTLV_MCSS_RefreshSpriteFromParty, BTLV_MCSS_GetSpriteWeight, BTLV_MCSS_GetSpriteAttrFlags, BTLV_MCSS_HasPersonalParam10, BTLV_MCSS_GetStopCellFlags, BTLV_MCSS_SetSubstituteSprite, BTLV_MCSS_SetMosaic, BTLV_MCSS_CopySpriteResources, BTLV_MCSS_ReloadSpriteResource, BTLV_MCSS_PlayCry, BTLV_MCSS_StartRotation, BTLV_MCSS_GetSpriteColorCode, BTLV_MCSS_MakeAddWorkFromPoke, BTLV_MCSS_SetAnimIndexIfValid, BTLV_MCSS_SetAnimPendingCallback, BTLV_MCSS_IsAnimPending, BTLV_MCSS_ResetSpritePosition, BTLV_MCSS_SetSpriteWorkFlagForRule, BTLV_MCSS_TakeSpriteRefreshedFlag, BTLV_MCSS_SaveVanishStates, BTLV_MCSS_RestoreVanishStates, BTLV_MCSS_MakeAddWorkFromTrainer, BTLV_MCSS_ApplySlotScale, BTLV_MCSS_CreateTweenTask, BTLV_MCSS_PositionTweenTaskMain, BTLV_MCSS_PositionTweenTaskEnd, BTLV_MCSS_ShadowScaleTweenTaskMain, BTLV_MCSS_ShadowScaleTweenTaskEnd, BTLV_MCSS_ScaleTweenTaskMain, BTLV_MCSS_ScaleTweenTaskEnd, BTLV_MCSS_DrawScaleTweenTaskMain, BTLV_MCSS_DrawScaleTweenTaskEnd, BTLV_MCSS_RotateTweenTaskMain, BTLV_MCSS_RotateTweenTaskEnd, BTLV_MCSS_BlinkTaskMain, BTLV_MCSS_BlinkTaskEnd, BTLV_MCSS_AlphaTweenTaskMain, BTLV_MCSS_AlphaTweenTaskEnd, BTLV_MCSS_ShakeTaskMain, BTLV_MCSS_ShakeTaskEnd, BTLV_MCSS_BounceTaskMain, BTLV_MCSS_BounceTaskEnd, BTLV_MCSS_MosaicTweenTaskMain, BTLV_MCSS_MosaicTweenTaskEnd, BTLV_MCSS_AnimWatchTaskMain, BTLV_MCSS_RotationTaskMain, BTLV_MCSS_RotationTaskEnd, BTLV_MCSS_IdleAnimCallback, BTLV_MCSS_CellCallbackCheckStopCell, BTLV_MCSS_AnimCallbackClearPending, BTLV_MCSS_CalcSlotPosition, BTLV_MCSS_CalcSlotScale, BTLV_MCSS_FindSpriteIndex, BTLV_MCSS_LookupShadowEntry
 * address:  0x021FEAC0
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
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   TCB_DeleteTask 0x02030EAC arm
 *   TCB_AddTask  0x02030DA8  arm
 *   TCBL_GetOwnedWork   0x02030EE8  arm
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   FX_Div  0x0207C768  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_USE_StopSeSlot 0x020061F8 thumb
 *   GFL_USE_PlaySeInSlot  0x0200616C  thumb
 *   MCSS_Init  0x02014B08  thumb
 *   MCSS_SetDepthStep  0x020163B0  thumb
 *   MCSS_SetNearDepthRange  0x020163B4  thumb
 *   gBtlvMcssSourceFileName     0x0220AE7C  data   ov094
 *   MCSS_Exit  0x02014BA8  thumb
 *   MCSS_RestartAnime 0x02016374 thumb
 *   MCSS_Main 0x02014C08 thumb
 *   MCSS_Draw  0x02014D2C  thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_IsShiny 0x02017EAC thumb
 *   POKE_TOOL_GetPersonalParam 0x02019C90 thumb
 *   BGWINFRM_GetScaleRank 0x0202D034 thumb
 *   MCSS_Add 0x020159C8 thumb
 *   MCSS_SetShadowAlpha 0x02015FD4 thumb
 *   MCSS_SetShadowOffset 0x02015D94 thumb
 *   MCSS_SetShadowRotateZ 0x02015D88 thumb
 *   MCSS_SetAnimCallback 0x02015F2C thumb
 *   MCSS_Del  0x02015BA4  thumb
 *   MCSS_SetPosition  0x02015C48  thumb
 *   MCSS_SetOrthoMode   0x02015BF0  thumb
 *   MCSS_ResetOrthoMode   0x02015C00  thumb
 *   MCSS_SetOrthoBillboardFlag  0x02015C0C  thumb
 *   MCSS_ResetOrthoBillboardFlag  0x02015C1C  thumb
 *   MCSS_SetMepachiFlag  0x02015DB0  thumb
 *   MCSS_ResetMepachiFlag  0x02015DC0  thumb
 *   MCSS_FlipMepachiFlag  0x02015DD4  thumb
 *   MCSS_GetAnmStopFlag  0x02015DF8  thumb
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   MCSS_SetAnmStopFlagAlways  0x02015E28  thumb
 *   MCSS_ResetAnmStopFlagAlways  0x02015E70  thumb
 *   MCSS_ResetAnmStopFlag  0x02015E4C  thumb
 *   MCSS_GetVanishFlag  0x02015E94  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   MCSS_FlipVanishFlag  0x02015EC4  thumb
 *   gBtlvMcssSlotPosSingle  0x0220A050  data  ov094
 *   gBtlvMcssSlotPosDouble  0x0220A080  data  ov094
 *   gBtlvMcssSlotPosTriple  0x0220A158  data  ov094
 *   gBtlvMcssSlotPosRotation  0x0220A1A0  data  ov094
 *   MCSS_SetShadowVanishFlag  0x02015FF0  thumb
 *   MCSS_SetAnimeSpeed  0x020160C4  thumb
 *   MCSS_GetPosition 0x02015C30 thumb
 *   MCSS_GetShadowScale  0x02015CC4  thumb
 *   MCSS_GetScale  0x02015C94  thumb
 *   MCSS_GetRotate  0x02015CF8  thumb
 *   BTLV_GAUGE_HideSlot  0x022089BC  thumb  ov094
 *   MCSS_GetAlpha 0x02015FAC thumb
 *   MCSS_GetMosaic 0x02016068 thumb
 *   MCSS_CheckPaletteFade  0x0201600C  thumb
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   MCSS_CreatePaletteTransTask  0x020160D4  thumb
 *   MCSS_CreatePaletteCopyTask  0x0201624C  thumb
 *   MCSS_GetStopCellFlags  0x02015F24  thumb
 *   MCSS_TOOL_SetSpindaSpotHook 0x020172AC thumb
 *   MCSS_ReloadResource 0x02014CF8 thumb
 *   POKEGRA_GetArcID 0x0202D060 thumb
 *   MCSS_SetMosaic  0x02016078  thumb
 *   BTL_MAIN_GetVoiceOfSlot  0x021B994C  thumb
 *   PM_VOICE_Play  0x02006984  thumb
 *   PM_VOICE_AddVolume  0x02006A8C  thumb
 *   PM_VOICE_AddFrequency  0x02006AEC  thumb
 *   gBtlvMcssVoiceIdSingle  0x02209FC0  data  ov094
 *   gBtlvMcssVoiceIdDouble  0x02209FE0  data  ov094
 *   gBtlvMcssVoiceIdRotation  0x02209FF0  data  ov094
 *   gBtlvMcssVoiceIdTriple  0x0220A068  data  ov094
 *   MCSS_TOOL_MakeAddWorkFromPP  0x02017100  thumb
 *   MCSS_GetAnimSeqNumEx  0x020160CC  thumb
 *   MCSS_SetAnimeIndex   0x02016028  thumb
 *   MCSS_GetOfsPosition  0x02015C60  thumb
 *   MCSS_SetOfsPosition  0x02015C78  thumb
 *   MCSS_SetMepachiDrawLast  0x02016394  thumb
 *   MCSS_TOOL_MakeAddWorkFromTrainer  0x02017214  thumb
 *   MCSS_SetScale  0x02015CAC  thumb
 *   MCSS_SetOfsScale  0x02015D30  thumb
 *   MCSS_SetShadowScale  0x02015CDC  thumb
 *   MCSS_GetDrawScale  0x02015D4C  thumb
 *   MCSS_SetDrawScale  0x02015D64  thumb
 *   MCSS_SetRotate  0x02015D14  thumb
 *   MCSS_SetAlpha  0x02015FBC  thumb
 *   MCSS_GetAnimCtrl 0x02015EE8 thumb
 *   MCSS_SetCellCallback 0x02015F40 thumb
 *   gBtlvMcssIdleWaitFrames 0x0220AE78 data a4
 *   gBtlvMcssRotationPositions     0x0220A0C8  data
 *   gBtlvMcssRotationStartAngles     0x0220A0B0  data
 *   gBtlvMcssRotationTargets     0x0220A0E0  data
 *   MCSS_GetStopCellNum 0x02015EF4 thumb
 *   MCSS_GetAnimSeqNum 0x02015EEC thumb
 *   MCSS_GetStopCellIndex  0x02015EFC  thumb
 *   gBtlvMcssSlotPosTrainer  0x0220A110  data  ov094
 *   gBtlvMcssSlotScaleSingle  0x02209FC8  data  ov094
 *   gBtlvMcssSlotScaleDouble  0x02209FD0  data  ov094
 *   gBtlvMcssSlotScaleRotation  0x0220A008  data  ov094
 *   gBtlvMcssSlotScaleTrainer  0x0220A020  data  ov094
 *   gBtlvMcssSlotScaleTriple  0x0220A038  data  ov094
 *   gBtlvMcssShadowTable  0x0220A1E8  data  ov094
 *   gBtlvMcssShadowTableOffsetX  0x0220A1EA  data  ov094
 *   gBtlvMcssShadowTableOffsetZ  0x0220A1EC  data  ov094
 *   gBtlvMcssShadowTableRotateZ  0x0220A1EE  data  ov094
 *   BTLV_EFFECT_RegisterTask 0x021F896C thumb ov094
 *   BTLV_EFFECT_DeleteTask 0x021F89BC thumb ov094
 *   BTLV_EFFECT_ComputeVectorStep 0x021F918C thumb ov094
 *   BTLV_EFFECT_StepMover  0x021F9260  thumb  ov094
 *   BTLV_STAGE_ArmLayerEntry 0x021F6AA8 thumb ov094
 *   BTLV_EFFECT_IsBusy 0x021F7EB4 thumb ov094
 *   BTLV_EFFECT_GaugeGetSlotHealthInfo 0x021F821C thumb ov094
 *   BTLV_EFFECT_GetMcss 0x021F8694 thumb ov094
 *   BTLV_EFFECT_GetStage 0x021F86A4 thumb ov094
 *   BTLV_EFFECT_GetGauge 0x021F86B4 thumb ov094
 *   BTLV_EFFECT_GetEffvm 0x021F86C4 thumb ov094
 *   BTLV_EFFECT_GetMode 0x021F8710 thumb ov094
 *   BTLV_EFFECT_GetBattleMain 0x021F8754 thumb ov094
 *   BTLV_EFFECT_GetBitMask 0x021F935C thumb ov094
 *   BTLV_EFFVM_GetFallbackScriptFlag 0x021F9824 thumb ov094
 *   _fadd                        0x0209C95C  arm
 *   _fdiv                        0x0209CE10  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fgr                         0x0209BBB0  arm
 *   _fmul                        0x0209C77C  arm
 *   _fsub                        0x0209CB8C  arm
 *   _ull_mul                     0x0209C054  arm
 */
#include "btlv_mcss_shared_types.h"

#include "../types.h"
#include "../arm9/nns_g2d_anim_types.h"

/* Value ids of POKE_TOOL_GetPartyValue read by the battle view. */
#define BTLV_PARTY_VALUE_PERSONAL_RAND 0
#define BTLV_PARTY_VALUE_SPECIES 5
#define BTLV_PARTY_VALUE_FORM 0x6f
#define BTLV_PARTY_VALUE_EFFECT_CODE 0x98
#define BTLV_PARTY_VALUE_HP 0xa0
#define BTLV_PARTY_VALUE_MAX_HP 0xa1

#define BTLV_MCSS_SE_ROTATION_START 0x6ca
#define BTLV_MCSS_SE_ROTATION_END 0x57a
#define BTLV_MCSS_CRY_PITCH_AUTO ((int)0x80000000)

#define INT_TO_FX32(x) ((int)(((x) > 0) ? ((float)((x) << 12) + .5f) : ((float)((x) << 12) - .5f)))
#define FX32_FROM_FLOAT(x) ((int)(((x) > 0.0f) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))
#define FX32_MUL(a, b) ((int)(((s64)(a) * (b) + 0x800) >> 12))

struct TcblTask; /* task record of the task list (TCB_AddTask) */

/* Linear move state stepped by BTLV_EFFECT_StepMover: BtlvMover (0x3c bytes) from btlv_camera_shared_types.h. */

/* Task state of the position, scale, rotate, alpha and mosaic tweens (0x54 bytes). */
typedef struct BtlvMcssTween {
    BtlvMcssWork *work;     /* 0x00 */
    int pos;                /* 0x04 */
    BtlvMcssVec cur;        /* 0x08: value being tweened, for the tweens that do not read it from the sprite */
    BtlvMover state;        /* 0x14 */
    int serial;             /* 0x50: task ends when the work serial of this position changes */
} BtlvMcssTween;

/* Task state of the eye blink (same 0x54 byte allocation as BtlvMcssTween). */
typedef struct BtlvMcssBlinkTask {
    BtlvMcssWork *work;     /* 0x00 */
    int pos;                /* 0x04 */
    int unused08[3];        /* 0x08 */
    int kind;               /* 0x14: written, never read */
    int unused18[11];       /* 0x18 */
    int wait;               /* 0x44: frames until the next blink toggle */
    int reload;             /* 0x48 */
    int count;              /* 0x4c: toggles left */
    int serial;             /* 0x50 */
} BtlvMcssBlinkTask;

/* Task state of the rotation battle formation turn (0x24 bytes). */
typedef struct BtlvMcssRotationTask {
    BtlvMcssWork *work;     /* 0x00 */
    u32 state : 31;         /* 0x04: 0 wait for free spots, 1 turn, 2 settle */
    u32 playSound : 1;
    int side;               /* 0x08: 0 player side, 1 opponent side */
    int dir;                /* 0x0c: 0 clockwise */
    int angle[3];           /* 0x10 */
    int framesLeft;         /* 0x1c */
    int angleStep;          /* 0x20 */
} BtlvMcssRotationTask;

/* Task state of the idle animation watcher (12 bytes). */
typedef struct BtlvMcssAnimWatch {
    int state;              /* 0x00: 0 start, 1 wait, 2 finish */
    int pos;                /* 0x04 */
    int wait;               /* 0x08 */
} BtlvMcssAnimWatch;

typedef struct BtlvMcssAnimEntry {
    u16 species : 14;
    u16 mirror : 1;
    u16 shadowVisible : 1;
} BtlvMcssAnimEntry;

/* Arm9 helpers */
#include "../arm9/gfl_heap_wrap.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
struct TcbSystem;
struct TcblSystem;
#include "../arm9/tcbl.h"
#include "../arm9/gf_standard.h"
#include "../arm9/fx_cp.h"
#include "../arm9/gfl_use.h"
struct McssSys;

          
#include "../arm9/mcss.h"
struct McssWork;
 /* archive id and the seven file ids of a McssAddWork */
struct McssAddWork;
#include "../arm9/pokegra.h"
struct PokemonParam;

/* Pokemon data, voices, battle */
#include "../arm9/poke_tool.h"
#include "../arm9/bgwinfrm.h"
struct PerapVoice;
struct BtlMain;
#include "../ov093/btl_main.h"
#include "../arm9/pm_voice.h"
struct BtlvStage;

/* Battle view helpers (other files of this overlay) */
#include "btlv_stage.h"
#include "btlv_effect.h"
struct BtlvGaugeWork;
#include "btlv_effvm.h"
#include "btlv_gauge.h"

extern const s16 FX_SinCosTable_[];
extern char gBtlvMcssSourceFileName[];
extern const BtlvMcssVec gBtlvMcssSlotPosSingle[];
extern const BtlvMcssVec gBtlvMcssSlotPosDouble[];
extern const BtlvMcssVec gBtlvMcssSlotPosTriple[];
extern const BtlvMcssVec gBtlvMcssSlotPosRotation[];
extern const BtlvMcssVec gBtlvMcssSlotPosTrainer[];
extern u32 gBtlvMcssVoiceIdSingle[];
extern u32 gBtlvMcssVoiceIdDouble[];
extern u32 gBtlvMcssVoiceIdRotation[];
extern u32 gBtlvMcssVoiceIdTriple[];
extern const u8 gBtlvMcssIdleWaitFrames[];
extern const int gBtlvMcssSlotScaleSingle[];
extern const int gBtlvMcssSlotScaleDouble[];
extern const int gBtlvMcssSlotScaleRotation[];
extern const int gBtlvMcssSlotScaleTrainer[];
extern const int gBtlvMcssSlotScaleTriple[];
extern const char gBtlvMcssShadowTable[];
extern const char gBtlvMcssShadowTableOffsetX[];
extern const char gBtlvMcssShadowTableOffsetZ[];
extern const char gBtlvMcssShadowTableRotateZ[];

typedef struct BtlvMcssSideTable {
    int v[2][3];
} BtlvMcssSideTable;

typedef struct BtlvMcssRotateTable {
    int v[2][2][3];
} BtlvMcssRotateTable;

extern const BtlvMcssSideTable gBtlvMcssRotationPositions;
extern const BtlvMcssSideTable gBtlvMcssRotationStartAngles;
extern const BtlvMcssRotateTable gBtlvMcssRotationTargets;

/* forward declarations */
BtlvMcssWork *BTLV_MCSS_Create(int rule, void *taskOwner, u16 heapId);
void BTLV_MCSS_Delete(BtlvMcssWork *w);
void BTLV_MCSS_Update(BtlvMcssWork *w);
void BTLV_MCSS_Draw(BtlvMcssWork *w);
void BTLV_MCSS_AddPoke(BtlvMcssWork *w, void *pp, int pos);
void BTLV_MCSS_AddTrainer(BtlvMcssWork *w, u32 trainer, int pos);
void BTLV_MCSS_RemoveSprite(BtlvMcssWork *w, int pos);
void BTLV_MCSS_SetSideScale(BtlvMcssWork *w, int scaleEven, int scaleOdd);
void BTLV_MCSS_SetPosition(BtlvMcssWork *w, int pos, int x, int y, int z);
void BTLV_MCSS_EnableOrthoMode(BtlvMcssWork *w);
void BTLV_MCSS_DisableOrthoMode(BtlvMcssWork *w);
void BTLV_MCSS_EnableBillboard(BtlvMcssWork *w, int pos);
void BTLV_MCSS_DisableBillboard(BtlvMcssWork *w, int pos);
void BTLV_MCSS_SetBlinkMode(BtlvMcssWork *w, int pos, int mode);
int BTLV_MCSS_IsAnimStopped(BtlvMcssWork *w, int pos);
void BTLV_MCSS_SetAnimStopMode(BtlvMcssWork *w, int pos, int mode);
int BTLV_MCSS_IsVanished(BtlvMcssWork *w, int pos);
void BTLV_MCSS_SetVanishMode(BtlvMcssWork *w, int pos, int mode);
void BTLV_MCSS_GetSlotPosition(BtlvMcssWork *w, BtlvMcssVec *out, int pos);
void BTLV_MCSS_GetSlotPositionForRule(const BtlvMcssVec *def, BtlvMcssVec *out, int pos, int rule);
int BTLV_MCSS_GetSlotScale(BtlvMcssWork *w, int pos, int mode);
void BTLV_MCSS_SetShadowVanish(BtlvMcssWork *w, int pos, u8 vanish);
void BTLV_MCSS_SetAnimSpeed(BtlvMcssWork *w, int pos, int speed);
void BTLV_MCSS_StartPositionTween(BtlvMcssWork *w, int pos, int kind, BtlvMcssVec *target, int frames, int waitFrames, int repeat);
void BTLV_MCSS_StartShadowScaleTween(BtlvMcssWork *w, int pos, int kind, BtlvMcssVec *target, int frames, int waitFrames, int repeat);
void BTLV_MCSS_StartScaleTween(BtlvMcssWork *w, int pos, int kind, BtlvMcssVec *target, int frames, int waitFrames, int repeat);
void BTLV_MCSS_StartDrawScaleTween(BtlvMcssWork *w, int pos, int kind, BtlvMcssVec *target, int frames, int waitFrames, int repeat);
void BTLV_MCSS_StartRotateTween(BtlvMcssWork *w, int pos, int kind, BtlvMcssVec *target, int frames, int waitFrames, int repeat);
void BTLV_MCSS_SwapSprites(BtlvMcssWork *w, int posA, int posB);
void BTLV_MCSS_StartBlinkTask(BtlvMcssWork *w, int pos, int kind, int interval, int toggles);
void BTLV_MCSS_StartAlphaTween(BtlvMcssWork *w, int pos, int kind, int alpha, int frames, int waitFrames, int repeat);
void BTLV_MCSS_StartShakeTask(BtlvMcssWork *w, BtlvMcssShakeParams *params);
void BTLV_MCSS_StartBounceTask(BtlvMcssWork *w, BtlvMcssBounceParams *params);
void BTLV_MCSS_StartMosaicTween(BtlvMcssWork *w, int pos, int kind, int mosaic, int frames, int waitFrames, int repeat);
int BTLV_MCSS_IsSpriteBusy(BtlvMcssWork *w, int pos);
int BTLV_MCSS_IsAnySpriteBusy(BtlvMcssWork *w);
int BTLV_MCSS_IsSpriteLoaded(BtlvMcssWork *w, int pos);
void BTLV_MCSS_SetPaletteFade(BtlvMcssWork *w, int pos, u8 cur, u8 target, u8 step, u32 color);
void BTLV_MCSS_StartPaletteTrans(BtlvMcssWork *w, int pos, u8 a, int b);
void BTLV_MCSS_StartPaletteCopy(BtlvMcssWork *w, int pos);
void BTLV_MCSS_RefreshSpriteFromParty(BtlvMcssWork *w, int pos, void *pp);
int BTLV_MCSS_GetSpriteWeight(BtlvMcssWork *w, int pos);
int BTLV_MCSS_GetSpriteAttrFlags(BtlvMcssWork *w, int pos);
int BTLV_MCSS_HasPersonalParam10(BtlvMcssWork *w, int pos);
int BTLV_MCSS_GetStopCellFlags(BtlvMcssWork *w, int pos);
void BTLV_MCSS_SetSubstituteSprite(BtlvMcssWork *w, int pos, int showSubstitute, int setSwapped);
void BTLV_MCSS_SetMosaic(BtlvMcssWork *w, int pos, int mosaic);
void BTLV_MCSS_CopySpriteResources(BtlvMcssWork *w, int posA, int posB);
void BTLV_MCSS_ReloadSpriteResource(BtlvMcssWork *w, int pos, McssAddWork *addWork);
int BTLV_MCSS_PlayCry(BtlvMcssWork *w, int pos, int pitch, int pan, int chorusParamA, int chorusParamB, int chorusParamC);
void BTLV_MCSS_StartRotation(BtlvMcssWork *w, int side, int dir, int playSound);
int BTLV_MCSS_GetSpriteColorCode(BtlvMcssWork *w, int pos);
void BTLV_MCSS_MakeAddWorkFromPoke(BtlvMcssWork *w, void *pp, McssAddWork *out, int pos);
int BTLV_MCSS_SetAnimIndexIfValid(BtlvMcssWork *w, int pos, int animIndex);
void BTLV_MCSS_SetAnimPendingCallback(BtlvMcssWork *w, int pos);
int BTLV_MCSS_IsAnimPending(BtlvMcssWork *w, int pos);
void BTLV_MCSS_ResetSpritePosition(BtlvMcssWork *w, int pos);
void BTLV_MCSS_SetSpriteWorkFlagForRule(BtlvMcssWork *w, int pos, int mode);
int BTLV_MCSS_TakeSpriteRefreshedFlag(BtlvMcssWork *w, int pos);
void BTLV_MCSS_SaveVanishStates(BtlvMcssWork *w);
void BTLV_MCSS_RestoreVanishStates(BtlvMcssWork *w);
void BTLV_MCSS_MakeAddWorkFromTrainer(u32 trainer, McssAddWork *out, int pos);
void BTLV_MCSS_ApplySlotScale(BtlvMcssWork *w, int pos);
void BTLV_MCSS_CreateTweenTask(BtlvMcssWork *w, int pos, int kind, BtlvMcssVec *from, BtlvMcssVec *to, int frames, int waitFrames, int repeat, void (*fn)(struct TcbTask *, void *), void (*endCb)(void *), int mirrorOdd, u8 serial);
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
void BTLV_MCSS_CalcSlotPosition(BtlvMcssWork *w, BtlvMcssVec *out, int pos);
int BTLV_MCSS_CalcSlotScale(BtlvMcssWork *w, int pos, int mode);
int BTLV_MCSS_FindSpriteIndex(BtlvMcssWork *w, int pos);
int BTLV_MCSS_LookupShadowEntry(int species, int pos, BtlvMcssVec *offset, u16 *rotateZ, int *visible);

/*
 * Lever: `u16 heapId` (the strh of the heap id makes the parameter 16-bit; it
 * is spilled at entry and reloaded, as the image does).
 */
BtlvMcssWork *BTLV_MCSS_Create(int rule, void *taskOwner, u16 heapId)
{
    BtlvMcssWork *w;
    int sysParam = 0xe;
    int i;
    w = GFL_HEAP_Alloc(heapId, 0x5b4, 1, gBtlvMcssSourceFileName, 0x184);
    w->mcss = (struct McssSys *)MCSS_Init(sysParam, heapId);
    w->taskOwner = taskOwner;
    w->heapId = heapId;
    sysParam += 0xf2;
    MCSS_SetDepthStep((struct McssSys *)w->mcss, sysParam);
    MCSS_SetNearDepthRange((struct McssSys *)w->mcss, 1);
    w->orthoActive = 1;
    w->scaleEven = 0x1000;
    w->scaleOdd = 0x1000;
    w->flags.triple = (rule == BTLV_MCSS_RULE_TRIPLE);
    w->flags.rotation = (rule == BTLV_MCSS_RULE_ROTATION);
    for (i = 0; i < BTLV_MCSS_SPRITE_MAX; i++)
        w->sprites[i].pos = 0xff;
    return w;
}

void BTLV_MCSS_Delete(BtlvMcssWork *work)
{
    BtlvMcssPos pos;

    for (pos = 0; pos < BTLV_MCSS_SPRITE_MAX; pos++) {
        if (BTLV_MCSS_IsSpriteLoaded(work, pos))
            BTLV_MCSS_RemoveSprite(work, pos);
    }
    MCSS_Exit((struct McssSys *)work->mcss);
    GFL_HEAP_Free(work);
}

/*
 * lever: enum loop counter keeps both entry guards; a separate local spriteIdx for the
 *   first loop index puts idx at sp+8 and flag at sp+4 (one shared idx swapped them).
 */
void BTLV_MCSS_Update(BtlvMcssWork *work)
{
    BtlvMcssPos pos;
    int spriteIdx;
    int idx;
    int tintStepped;
    int statusArg;
    int statusKind;

    for (pos = 0; pos < BTLV_MCSS_POKE_POS_COUNT; pos++) {
        if (BTLV_MCSS_IsSpriteLoaded(work, pos)) {
            spriteIdx = BTLV_MCSS_FindSpriteIndex(work, pos);
            if (work->sprites[spriteIdx].flags.restartAnim) {
                work->sprites[spriteIdx].flags.restartAnim = 0;
                MCSS_RestartAnime((struct McssWork *)work->sprites[spriteIdx].mcss);
            }
        }
    }
    MCSS_Main((struct McssSys *)work->mcss);
    if (work->flags.rotating == 0) {
        for (pos = 0; pos < BTLV_MCSS_POKE_POS_COUNT; pos++) {
            /* 1 in 100 frames: start an eye blink */
            if (BTLV_MCSS_IsSpriteLoaded(work, pos)
                && (u32)(((u64)GF_STANDARD_Rand() * 100) >> 32) == 0
                && (BTLV_EFFECT_GetBitMask(pos) & work->blinkTaskMask) == 0
                && BTLV_MCSS_IsAnimStopped(work, pos) == 0)
                BTLV_MCSS_StartBlinkTask(work, pos, 2, 4, 1);
            if (BTLV_MCSS_IsSpriteLoaded(work, pos) == 0)
                continue;
            idx = BTLV_MCSS_FindSpriteIndex(work, pos);
            tintStepped = 0;
            if (BTLV_EFFECT_IsBusy() && work->sprites[idx].flags.paletteFadeSet) {
                work->sprites[idx].flags.paletteFadeSet = 0;
                work->sprites[idx].flags.paletteFadeHold = 1;
            }
            if (BTLV_EFFECT_IsBusy() && work->sprites[idx].flags.paletteFadeHold)
                continue;
            work->sprites[idx].flags.paletteFadeHold = 0;
            if (BTLV_MCSS_GetSpriteAttrFlags(work, pos) & BTLV_MCSS_ATTR_SUBSTITUTE)
                continue;
            if (BTLV_EFFECT_GaugeGetSlotHealthInfo(pos, &statusArg, &statusKind) == 0)
                continue;
            if (work->sprites[idx].flags.statusTinting == 1) {
                if (work->sprites[idx].tintStep == 0)
                    work->sprites[idx].tintStep = 1;
                if (work->sprites[idx].tintTimer++ > 0x18) {
                    tintStepped = 1;
                    work->sprites[idx].tintTimer = 0;
                    work->sprites[idx].tintLevel += work->sprites[idx].tintStep;
                    if (work->sprites[idx].tintLevel == 0 || work->sprites[idx].tintLevel == 12)
                        work->sprites[idx].tintStep *= -1;
                }
            }
            switch (statusKind) {
            case 3:
                BTLV_MCSS_StartPaletteCopy(work, pos);
                BTLV_MCSS_SetBlinkMode(work, pos, 3);
                BTLV_MCSS_SetAnimStopMode(work, pos, 3);
                BTLV_MCSS_SetAnimSpeed(work, pos, 0x555);
                work->sprites[idx].flags.statusTinting = 1;
                break;
            case 1:
                if (tintStepped == 1)
                    BTLV_MCSS_StartPaletteTrans(work, pos, (u8)work->sprites[idx].tintLevel, 0x1ef);
                BTLV_MCSS_SetBlinkMode(work, pos, 4);
                BTLV_MCSS_SetAnimStopMode(work, pos, 3);
                work->sprites[idx].flags.statusTinting = 1;
                break;
            case 2:
                if (tintStepped == 1)
                    BTLV_MCSS_StartPaletteTrans(work, pos, 8, 0x7def);
                BTLV_MCSS_SetBlinkMode(work, pos, 4);
                BTLV_MCSS_SetAnimStopMode(work, pos, 2);
                work->sprites[idx].flags.statusTinting = 1;
                break;
            case 5:
                if (tintStepped == 1)
                    BTLV_MCSS_StartPaletteTrans(work, pos, (u8)work->sprites[idx].tintLevel, 0xf);
                BTLV_MCSS_SetBlinkMode(work, pos, 4);
                BTLV_MCSS_SetAnimStopMode(work, pos, 3);
                work->sprites[idx].flags.statusTinting = 1;
                break;
            case 4:
            case 7:
                if (tintStepped == 1)
                    BTLV_MCSS_StartPaletteTrans(work, pos, (u8)work->sprites[idx].tintLevel, 0x3c0f);
                BTLV_MCSS_SetBlinkMode(work, pos, 4);
                BTLV_MCSS_SetAnimStopMode(work, pos, 3);
                work->sprites[idx].flags.statusTinting = 1;
                break;
            case 8:
            default:
                if (work->sprites[idx].flags.statusTinting == 1) {
                    BTLV_MCSS_StartPaletteCopy(work, pos);
                    BTLV_MCSS_SetBlinkMode(work, pos, 4);
                    BTLV_MCSS_SetAnimStopMode(work, pos, 3);
                    BTLV_MCSS_SetAnimSpeed(work, pos, 0x1000);
                    work->sprites[idx].flags.statusTinting = 0;
                    work->sprites[idx].tintStep = 0;
                    work->sprites[idx].tintLevel = 0;
                    work->sprites[idx].tintTimer = 0;
                }
                break;
            }
            if (statusKind == 8) {
                if ((u32)(statusArg - 2) <= 1)
                    BTLV_MCSS_SetAnimSpeed(work, pos, 0x555);
                else
                    BTLV_MCSS_SetAnimSpeed(work, pos, 0x1000);
            }
        }
    }
}

void BTLV_MCSS_Draw(BtlvMcssWork *work)
{
    MCSS_Draw((struct McssSys *)work->mcss);
}

/*
 * levers: grouped vectors fix stack order; integer address arithmetic on the
 * second buffer argument prevents CSE; the idle counter is one two-bit assignment.
 */
void BTLV_MCSS_AddPoke(BtlvMcssWork *work, void *pp, int pos)
{
    int i;
    int visible;
    u16 angle;
    struct {
        BtlvMcssVec shadowOffset;
        BtlvMcssVec position;
    } vectors;
    u32 hp, maxHp;
    for (i = 0; i < BTLV_MCSS_SPRITE_MAX; i++) {
        if (work->sprites[i].mcss == 0)
            break;
    }
    if (pos < BTLV_MCSS_SPRITE_MAX && i < BTLV_MCSS_SPRITE_MAX) {
        work->sprites[i].attrFlags = 0;
        work->sprites[i].flags.blinkLocked = 0;
        work->sprites[i].flags.statusTinting = 0;
        work->sprites[i].flags.vanishHeld = 0;
        work->sprites[i].flags.orthoBillboard = work->orthoActive;
        work->sprites[i].pos = pos;
        work->sprites[i].identity.personalRand = POKE_TOOL_GetPartyValue(pp, BTLV_PARTY_VALUE_PERSONAL_RAND, 0);
        work->sprites[i].colorCode = POKE_TOOL_GetPartyValue(pp, BTLV_PARTY_VALUE_EFFECT_CODE, 0);
        if (POKE_TOOL_IsShiny(pp) == 1)
            work->sprites[i].attrFlags |= BTLV_MCSS_ATTR_SHINY;
        BTLV_MCSS_MakeAddWorkFromPoke(work, pp, &work->sprites[i].addWork, pos);
        BTLV_MCSS_CalcSlotPosition(work, &vectors.position, pos);
        work->sprites[i].mcss = MCSS_Add(work->mcss, vectors.position.x, vectors.position.y, vectors.position.z, &work->sprites[i].addWork);
        BTLV_MCSS_SetSpriteWorkFlagForRule(work, pos, 1);
        work->sprites[i].identity.species = POKE_TOOL_GetPartyValue(pp, BTLV_PARTY_VALUE_SPECIES, 0);
        work->sprites[i].identity.form = POKE_TOOL_GetPartyValue(pp, BTLV_PARTY_VALUE_FORM, 0);
        work->sprites[i].identity.weight = POKE_TOOL_GetPersonalParam(work->sprites[i].identity.species, work->sprites[i].identity.form, 0x26);
        hp = POKE_TOOL_GetPartyValue(pp, BTLV_PARTY_VALUE_HP, 0);
        maxHp = POKE_TOOL_GetPartyValue(pp, BTLV_PARTY_VALUE_MAX_HP, 0);
        work->sprites[i].identity.hpState = BGWINFRM_GetScaleRank(hp, maxHp);
        if (BTLV_MCSS_LookupShadowEntry(work->sprites[i].identity.species, pos, &vectors.shadowOffset, &angle, &visible) == 0) {
            vectors.shadowOffset.x = -0x400;
            vectors.shadowOffset.y = 0;
            vectors.shadowOffset.z = -0x600;
            angle = 0xf800;
            visible = 1;
        }
        if (visible == 0)
            MCSS_SetShadowAlpha((struct McssWork *)work->sprites[i].mcss, 0);
        else {
            MCSS_SetShadowOffset((struct McssWork *)work->sprites[i].mcss, (s32 *)(&vectors.shadowOffset));
            MCSS_SetShadowRotateZ((struct McssWork *)work->sprites[i].mcss, angle);
        }
        work->sprites[i].flags.idleCounter = 3;
        BTLV_MCSS_ApplySlotScale(work, pos);
        MCSS_SetAnimCallback(work->sprites[i].mcss, i, (uptr)BTLV_MCSS_IdleAnimCallback, 1);
    }
}

void BTLV_MCSS_AddTrainer(BtlvMcssWork *work, u32 trainer, int pos)
{
    int i;
    McssAddWork addWork;
    BtlvMcssVec position;

    for (i = 0; i < BTLV_MCSS_SPRITE_MAX; i++) {
        if (work->sprites[i].mcss == 0)
            break;
    }
    if (pos < BTLV_MCSS_SPRITE_MAX && i < BTLV_MCSS_SPRITE_MAX) {
        work->sprites[i].flags.orthoBillboard = 1;
        work->sprites[i].pos = pos;
        BTLV_MCSS_MakeAddWorkFromTrainer(trainer, &addWork, pos);
        BTLV_MCSS_CalcSlotPosition(work, &position, pos);
        work->sprites[i].mcss = MCSS_Add(work->mcss, position.x, position.y, position.z, &addWork);
        BTLV_MCSS_ApplySlotScale(work, pos);
    }
}

void BTLV_MCSS_RemoveSprite(BtlvMcssWork *work, int pos)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    MCSS_Del((struct McssSys *)work->mcss, (struct McssWork *)work->sprites[idx].mcss);
    work->sprites[idx].mcss = 0;
    if (work->sprites[idx].animWatchTask != 0) {
        GFL_HEAP_Free(TCBL_GetOwnedWork(work->sprites[idx].animWatchTask));
        TCB_DeleteTask(work->sprites[idx].animWatchTask);
        work->sprites[idx].animWatchTask = 0;
    }
}

void BTLV_MCSS_SetSideScale(BtlvMcssWork *work, int scaleEven, int scaleOdd)
{
    work->scaleEven = scaleEven;
    work->scaleOdd = scaleOdd;
}

void BTLV_MCSS_SetPosition(BtlvMcssWork *work, int pos, int x, int y, int z)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);
    BtlvMcssVec v;

    v.x = x;
    v.y = y;
    v.z = z;
    MCSS_SetPosition((struct McssWork *)work->sprites[idx].mcss, (u32 *)(&v));
}

void BTLV_MCSS_EnableOrthoMode(BtlvMcssWork *work)
{
    int i;
    int idx;

    MCSS_SetOrthoMode((struct McssSys *)work->mcss);
    work->orthoActive = 1;
    for (i = 0; i < BTLV_MCSS_SPRITE_MAX; i++) {
        idx = BTLV_MCSS_FindSpriteIndex(work, i);
        if (idx != -1) {
            work->sprites[idx].flags.orthoBillboard = 1;
            BTLV_MCSS_ApplySlotScale(work, i);
        }
    }
}

void BTLV_MCSS_DisableOrthoMode(BtlvMcssWork *work)
{
    int i;
    int idx;

    MCSS_ResetOrthoMode((struct McssSys *)work->mcss);
    work->orthoActive = 0;
    for (i = 0; i < BTLV_MCSS_SPRITE_MAX; i++) {
        idx = BTLV_MCSS_FindSpriteIndex(work, i);
        if (idx != -1) {
            work->sprites[idx].flags.orthoBillboard = 0;
            BTLV_MCSS_ApplySlotScale(work, i);
        }
    }
}

void BTLV_MCSS_EnableBillboard(BtlvMcssWork *work, int pos)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (idx == -1)
        return;
    work->sprites[idx].flags.orthoBillboard = 1;
    MCSS_SetOrthoBillboardFlag((struct McssWork *)work->sprites[idx].mcss);
    BTLV_MCSS_ApplySlotScale(work, pos);
}

void BTLV_MCSS_DisableBillboard(BtlvMcssWork *work, int pos)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (idx == -1)
        return;
    work->sprites[idx].flags.orthoBillboard = 0;
    MCSS_ResetOrthoBillboardFlag((struct McssWork *)work->sprites[idx].mcss);
    BTLV_MCSS_ApplySlotScale(work, pos);
}

/* mode 1 blink on, 2 toggle, 3 blink on and lock, 4 unlock and off, other off */
void BTLV_MCSS_SetBlinkMode(BtlvMcssWork *work, int pos, int mode)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    if (mode == 4) {
        MCSS_ResetMepachiFlag((struct McssWork *)work->sprites[idx].mcss);
        work->sprites[idx].flags.blinkLocked = 0;
    }
    if (work->sprites[idx].flags.blinkLocked)
        return;
    if (mode == 2) {
        MCSS_FlipMepachiFlag((struct McssWork *)work->sprites[idx].mcss);
    } else if (mode == 1) {
        MCSS_SetMepachiFlag((struct McssWork *)work->sprites[idx].mcss);
    } else if (mode == 3) {
        MCSS_SetMepachiFlag((struct McssWork *)work->sprites[idx].mcss);
        work->sprites[idx].flags.blinkLocked = 1;
    } else {
        MCSS_ResetMepachiFlag((struct McssWork *)work->sprites[idx].mcss);
    }
}

int BTLV_MCSS_IsAnimStopped(BtlvMcssWork *work, int pos)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (idx == -1)
        return 0;
    if (work->sprites[idx].mcss == 0)
        return 0;
    return MCSS_GetAnmStopFlag((struct McssWork *)work->sprites[idx].mcss);
}

/* mode 1 stop, 2 stop always, 3 release always, other release */
void BTLV_MCSS_SetAnimStopMode(BtlvMcssWork *work, int pos, int mode)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    if (mode == 1)
        MCSS_SetAnmStopFlag((struct McssWork *)work->sprites[idx].mcss);
    else if (mode == 2)
        MCSS_SetAnmStopFlagAlways((struct McssWork *)work->sprites[idx].mcss);
    else if (mode == 3)
        MCSS_ResetAnmStopFlagAlways((struct McssWork *)work->sprites[idx].mcss);
    else
        MCSS_ResetAnmStopFlag((struct McssWork *)work->sprites[idx].mcss);
}

int BTLV_MCSS_IsVanished(BtlvMcssWork *work, int pos)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (idx == -1)
        return 0;
    if (work->sprites[idx].mcss == 0)
        return 0;
    return MCSS_GetVanishFlag((struct McssWork *)work->sprites[idx].mcss);
}

/* mode 0 show, 1 hide, 2 toggle, 3 hide and remember if it was already hidden, 4 undo mode 3 */
void BTLV_MCSS_SetVanishMode(BtlvMcssWork *work, int pos, int mode)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    switch (mode) {
    case 2:
        MCSS_FlipVanishFlag((struct McssWork *)work->sprites[idx].mcss);
        break;
    case 1:
        MCSS_SetVanishFlag((struct McssWork *)work->sprites[idx].mcss);
        break;
    case 0:
        MCSS_ResetVanishFlag((struct McssWork *)work->sprites[idx].mcss);
        break;
    case 3:
        if (MCSS_GetVanishFlag((struct McssWork *)work->sprites[idx].mcss))
            work->sprites[idx].flags.vanishHeld = 1;
        MCSS_SetVanishFlag((struct McssWork *)work->sprites[idx].mcss);
        break;
    case 4:
        if (work->sprites[idx].flags.vanishHeld)
            work->sprites[idx].flags.vanishHeld = 0;
        else
            MCSS_ResetVanishFlag((struct McssWork *)work->sprites[idx].mcss);
        break;
    }
}

void BTLV_MCSS_GetSlotPosition(BtlvMcssWork *work, BtlvMcssVec *out, int pos)
{
    BTLV_MCSS_CalcSlotPosition(work, out, pos);
}

/*
 * Unlabelled: no func_ label in the listing (leaf, saves no lr); reached
 * by bl from BTLV_EFFVM_ParticleStartCallback.
 */
void BTLV_MCSS_GetSlotPositionForRule(const BtlvMcssVec *def, BtlvMcssVec *out, int pos, int rule)
{
    switch (pos) {
    case 0:
    case 1:
        def = &gBtlvMcssSlotPosSingle[pos];
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (rule == BTLV_MCSS_RULE_ROTATION)
            def = &gBtlvMcssSlotPosRotation[pos - 2];
        else if (rule == BTLV_MCSS_RULE_TRIPLE)
            def = &gBtlvMcssSlotPosTriple[pos - 2];
        else
            def = &gBtlvMcssSlotPosDouble[pos - 2];
        break;
    case 6:
    case 7:
        if (rule == BTLV_MCSS_RULE_ROTATION)
            def = &gBtlvMcssSlotPosRotation[pos - 2];
        else
            def = &gBtlvMcssSlotPosTriple[pos - 2];
        break;
    }
    out->x = def->x;
    out->y = def->y;
    out->z = def->z;
}

int BTLV_MCSS_GetSlotScale(BtlvMcssWork *work, int pos, int mode)
{
    return BTLV_MCSS_CalcSlotScale(work, pos, mode);
}

void BTLV_MCSS_SetShadowVanish(BtlvMcssWork *work, int pos, u8 vanish)
{
    int i = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (i == -1)
        return;
    if (work->sprites[i].mcss == 0)
        return;
    MCSS_SetShadowVanishFlag((struct McssWork *)work->sprites[i].mcss, vanish);
}

void BTLV_MCSS_SetAnimSpeed(BtlvMcssWork *work, int pos, int speed)
{
    int i = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (i == -1)
        return;
    if (work->sprites[i].mcss == 0)
        return;
    MCSS_SetAnimeSpeed((struct McssWork *)work->sprites[i].mcss, speed);
}

void BTLV_MCSS_StartPositionTween(BtlvMcssWork *work, int pos, int kind, BtlvMcssVec *target, int frames, int waitFrames, int repeat)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);
    BtlvMcssVec start;
    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    MCSS_GetPosition((struct McssWork *)work->sprites[idx].mcss, (u32 *)(&start));
    if (kind == BTLV_MCSS_TWEEN_ABSOLUTE) {
        if (pos & 1)
            target->x = start.x - target->x;
        else
            target->x += start.x;
        target->y += start.y;
        target->z += start.z;
    }
    if (kind == BTLV_MCSS_TWEEN_SLOT_MOVE) {
        BTLV_MCSS_CalcSlotPosition(work, target, pos);
        kind = BTLV_MCSS_TWEEN_ABSOLUTE;
    }
    if (kind == BTLV_MCSS_TWEEN_SLOT_SET) {
        BTLV_MCSS_CalcSlotPosition(work, target, pos);
        kind = BTLV_MCSS_TWEEN_SET;
    }
    if (kind == BTLV_MCSS_TWEEN_SET) {
        MCSS_SetPosition((struct McssWork *)work->sprites[idx].mcss, (u32 *)target);
        return;
    }
    work->positionSerial[pos]++;
    BTLV_MCSS_CreateTweenTask(work, pos, kind, &start, target, frames, waitFrames, repeat, BTLV_MCSS_PositionTweenTaskMain, BTLV_MCSS_PositionTweenTaskEnd, 1, work->positionSerial[pos]);
    work->positionTweenMask |= BTLV_EFFECT_GetBitMask(pos);
}

void BTLV_MCSS_StartShadowScaleTween(BtlvMcssWork *work, int pos, int kind, BtlvMcssVec *target, int frames, int waitFrames, int repeat)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);
    BtlvMcssVec cur;

    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    MCSS_GetShadowScale((struct McssWork *)work->sprites[idx].mcss, (u32 *)(&cur));
    work->shadowScaleSerial[pos]++;
    BTLV_MCSS_CreateTweenTask(work, pos, kind, &cur, target, frames, waitFrames, repeat, BTLV_MCSS_ShadowScaleTweenTaskMain, BTLV_MCSS_ShadowScaleTweenTaskEnd, 0, work->shadowScaleSerial[pos]);
    work->shadowScaleTweenMask |= BTLV_EFFECT_GetBitMask(pos);
}

void BTLV_MCSS_StartScaleTween(BtlvMcssWork *work, int pos, int kind, BtlvMcssVec *target, int frames, int waitFrames, int repeat)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);
    BtlvMcssVec cur;

    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    MCSS_GetScale((struct McssWork *)work->sprites[idx].mcss, (u32 *)(&cur));
    work->scaleSerial[pos]++;
    BTLV_MCSS_CreateTweenTask(work, pos, kind, &cur, target, frames, waitFrames, repeat, BTLV_MCSS_ScaleTweenTaskMain, BTLV_MCSS_ScaleTweenTaskEnd, 0, work->scaleSerial[pos]);
    work->scaleTweenMask |= BTLV_EFFECT_GetBitMask(pos);
}

/* The start value is read from the shadow scale, the task then moves the draw scale. */
void BTLV_MCSS_StartDrawScaleTween(BtlvMcssWork *work, int pos, int kind, BtlvMcssVec *target, int frames, int waitFrames, int repeat)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);
    BtlvMcssVec cur;

    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    MCSS_GetShadowScale((struct McssWork *)work->sprites[idx].mcss, (u32 *)(&cur));
    work->drawScaleSerial[pos]++;
    BTLV_MCSS_CreateTweenTask(work, pos, kind, &cur, target, frames, waitFrames, repeat, BTLV_MCSS_DrawScaleTweenTaskMain, BTLV_MCSS_DrawScaleTweenTaskEnd, 0, work->drawScaleSerial[pos]);
    work->drawScaleTweenMask |= BTLV_EFFECT_GetBitMask(pos);
}

void BTLV_MCSS_StartRotateTween(BtlvMcssWork *work, int pos, int kind, BtlvMcssVec *target, int frames, int waitFrames, int repeat)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);
    BtlvMcssVec cur;

    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    MCSS_GetRotate((struct McssWork *)work->sprites[idx].mcss, (u32 *)(&cur));
    work->rotateSerial[pos]++;
    BTLV_MCSS_CreateTweenTask(work, pos, kind, &cur, target, frames, waitFrames, repeat, BTLV_MCSS_RotateTweenTaskMain, BTLV_MCSS_RotateTweenTaskEnd, 1, work->rotateSerial[pos]);
    work->rotateTweenMask |= BTLV_EFFECT_GetBitMask(pos);
}

/* Exchange two sprites: each moves to the other's slot position and takes its position number. */
void BTLV_MCSS_SwapSprites(BtlvMcssWork *work, int posA, int posB)
{
    int positions[2];
    int idx[2];
    BtlvMcssVec slotPosition;
    int i;

    positions[0] = posA;
    positions[1] = posB;
    for (i = 0; i < 2; i++) {
        idx[i] = BTLV_MCSS_FindSpriteIndex(work, positions[i]);
        if (BTLV_MCSS_IsSpriteLoaded(work, positions[i])) {
            BTLV_MCSS_CalcSlotPosition(work, &slotPosition, positions[i ^ 1]);
            BTLV_MCSS_StartPositionTween(work, positions[i], 0, &slotPosition, 0, 0, 0);
            BTLV_GAUGE_HideSlot(BTLV_EFFECT_GetGauge(), positions[i]);
            if (work->sprites[idx[i]].flags.repositionHidden) {
                work->sprites[idx[i]].flags.repositionHidden = 0;
                BTLV_MCSS_SetVanishMode(work, positions[i], 0);
            }
        }
    }
    for (i = 0; i < 2; i++) {
        if (idx[i] != -1)
            work->sprites[idx[i]].pos = positions[i ^ 1];
    }
}

/* kind 2 timed blink, 3 blink on, 4 blink off */
void BTLV_MCSS_StartBlinkTask(BtlvMcssWork *work, int pos, int kind, int interval, int toggles)
{
    BtlvMcssBlinkTask *task;

    switch (kind) {
    case 3:
        BTLV_MCSS_SetBlinkMode(work, pos, 1);
        return;
    case 4:
        BTLV_MCSS_SetBlinkMode(work, pos, 0);
        return;
    case 2:
        task = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x54, 0, gBtlvMcssSourceFileName, 0x5e5);
        task->work = work;
        task->pos = pos;
        task->kind = kind;
        task->wait = 0;
        task->reload = interval;
        task->count = toggles * 2;
        work->blinkSerial[pos]++;
        task->serial = work->blinkSerial[pos];
        BTLV_EFFECT_RegisterTask(TCB_AddTask(work->taskOwner, BTLV_MCSS_BlinkTaskMain, task, 0), BTLV_MCSS_BlinkTaskEnd, 2);
        work->blinkTaskMask |= BTLV_EFFECT_GetBitMask(pos);
        return;
    }
}

void BTLV_MCSS_StartAlphaTween(BtlvMcssWork *work, int pos, int kind, int alpha, int frames, int waitFrames, int repeat)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);
    BtlvMcssVec start, end;
    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    start.x = INT_TO_FX32(MCSS_GetAlpha((struct McssWork *)work->sprites[idx].mcss));
    start.y = 0;
    start.z = 0;
    end.x = INT_TO_FX32(alpha);
    end.y = 0;
    end.z = 0;
    work->alphaSerial[pos]++;
    BTLV_MCSS_CreateTweenTask(work, pos, kind, &start, &end, frames, waitFrames, repeat, BTLV_MCSS_AlphaTweenTaskMain, BTLV_MCSS_AlphaTweenTaskEnd, 0, work->alphaSerial[pos]);
    work->alphaTweenMask |= BTLV_EFFECT_GetBitMask(pos);
}

/*
 * lever: the 4/5 mode test is an unsigned range check; individual equality tests cost two bytes.
 */
void BTLV_MCSS_StartShakeTask(BtlvMcssWork *work, BtlvMcssShakeParams *params)
{
    BtlvMcssShakeParams *task = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x3c, 0, gBtlvMcssSourceFileName, 0x627);
    task->work = work;
    task->pos = params->pos;
    task->mode = params->mode;
    task->waveStart = params->waveStart;
    task->amplitudeX = params->amplitudeX;
    task->amplitudeY = params->amplitudeY;
    task->stepsPerCycle = params->stepsPerCycle;
    task->stepInterval = params->stepInterval;
    task->cycles = params->cycles;
    task->cyclePause = params->cyclePause;
    task->intervalCounter = 0;
    task->pauseCounter = 0;
    if (task->pos & 1) {
        if ((task->mode != 0 && task->mode != 1 && (unsigned)(task->mode - 4) > 1)
            || (params->waveStart != 2 && params->waveStart != 3))
            task->waveStart ^= 1;
    }
    task->phase = (task->mode & 1) ? 0x10000 : 0;
    task->phaseStep = 0x10000 / params->stepsPerCycle;
    work->positionSerial[task->pos]++;
    task->serial = work->positionSerial[task->pos];
    BTLV_EFFECT_RegisterTask(TCB_AddTask(work->taskOwner, BTLV_MCSS_ShakeTaskMain, task, 0), BTLV_MCSS_ShakeTaskEnd, 2);
    work->positionTweenMask |= BTLV_EFFECT_GetBitMask(task->pos);
}

void BTLV_MCSS_StartBounceTask(BtlvMcssWork *work, BtlvMcssBounceParams *params)
{
    BtlvMcssBounceParams *task = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x2c, 0, gBtlvMcssSourceFileName, 0x660);
    int idx = BTLV_MCSS_FindSpriteIndex(work, params->pos);

    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    *task = *params;
    task->work = work;
    MCSS_GetPosition((struct McssWork *)work->sprites[idx].mcss, (u32 *)(&task->startPosition));
    work->positionSerial[task->pos]++;
    task->serial = work->positionSerial[task->pos];
    BTLV_EFFECT_RegisterTask(TCB_AddTask(work->taskOwner, BTLV_MCSS_BounceTaskMain, task, 0), BTLV_MCSS_BounceTaskEnd, 2);
    work->positionTweenMask |= BTLV_EFFECT_GetBitMask(task->pos);
}

void BTLV_MCSS_StartMosaicTween(BtlvMcssWork *work, int pos, int kind, int mosaic, int frames, int waitFrames, int repeat)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);
    BtlvMcssVec start, end;
    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    start.x = INT_TO_FX32(MCSS_GetMosaic((struct McssWork *)work->sprites[idx].mcss));
    start.y = 0;
    start.z = 0;
    end.x = INT_TO_FX32(mosaic);
    end.y = 0;
    end.z = 0;
    work->mosaicSerial[pos]++;
    BTLV_MCSS_CreateTweenTask(work, pos, kind, &start, &end, frames, waitFrames, repeat, BTLV_MCSS_MosaicTweenTaskMain, BTLV_MCSS_MosaicTweenTaskEnd, 0, work->mosaicSerial[pos]);
    work->mosaicTweenMask |= BTLV_EFFECT_GetBitMask(pos);
}

int BTLV_MCSS_IsSpriteBusy(BtlvMcssWork *work, int pos)
{
    int fading = 0;

    if (BTLV_MCSS_IsSpriteLoaded(work, pos))
        fading = MCSS_CheckPaletteFade((struct McssWork *)(work->sprites[BTLV_MCSS_FindSpriteIndex(work, pos)].mcss));
    if (BTLV_EFFECT_GetBitMask(pos) & work->positionTweenMask
        || BTLV_EFFECT_GetBitMask(pos) & work->shadowScaleTweenMask
        || BTLV_EFFECT_GetBitMask(pos) & work->drawScaleTweenMask
        || BTLV_EFFECT_GetBitMask(pos) & work->scaleTweenMask
        || BTLV_EFFECT_GetBitMask(pos) & work->rotateTweenMask
        || BTLV_EFFECT_GetBitMask(pos) & work->blinkTaskMask
        || BTLV_EFFECT_GetBitMask(pos) & work->alphaTweenMask
        || BTLV_EFFECT_GetBitMask(pos) & work->mosaicTweenMask
        || work->flags.rotating
        || fading)
        return 1;
    return 0;
}

int BTLV_MCSS_IsAnySpriteBusy(BtlvMcssWork *work)
{
    BtlvMcssPos pos;

    for (pos = 0; pos < BTLV_MCSS_POKE_POS_COUNT; pos++) {
        if (BTLV_MCSS_IsSpriteLoaded(work, pos) && BTLV_MCSS_IsSpriteBusy(work, pos))
            return 1;
    }
    return 0;
}

int BTLV_MCSS_IsSpriteLoaded(BtlvMcssWork *work, int pos)
{
    if (BTLV_MCSS_FindSpriteIndex(work, pos) != -1)
        return 1;
    return 0;
}

void BTLV_MCSS_SetPaletteFade(BtlvMcssWork *work, int pos, u8 cur, u8 target, u8 step, u32 color)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    MCSS_SetPaletteFade((struct McssWork *)work->sprites[idx].mcss, cur, target, (s8)step, color);
    work->sprites[idx].flags.paletteFadeSet = 1;
}

void BTLV_MCSS_StartPaletteTrans(BtlvMcssWork *work, int pos, u8 level, int color)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    MCSS_CreatePaletteTransTask(work->mcss, work->sprites[idx].mcss, level, color);
}

void BTLV_MCSS_StartPaletteCopy(BtlvMcssWork *work, int pos)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    MCSS_CreatePaletteCopyTask((struct McssSys *)work->mcss, (struct McssWork *)work->sprites[idx].mcss);
}

void BTLV_MCSS_RefreshSpriteFromParty(BtlvMcssWork *work, int pos, void *pp)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    work->sprites[idx].identity.species = POKE_TOOL_GetPartyValue(pp, BTLV_PARTY_VALUE_SPECIES, 0);
    work->sprites[idx].identity.form = POKE_TOOL_GetPartyValue(pp, BTLV_PARTY_VALUE_FORM, 0);
    work->sprites[idx].identity.weight = POKE_TOOL_GetPersonalParam(work->sprites[idx].identity.species, work->sprites[idx].identity.form, 0x26);
    work->sprites[idx].identity.personalRand = POKE_TOOL_GetPartyValue(pp, BTLV_PARTY_VALUE_PERSONAL_RAND, 0);
    work->sprites[idx].colorCode = POKE_TOOL_GetPartyValue(pp, BTLV_PARTY_VALUE_EFFECT_CODE, 0);
    if (POKE_TOOL_IsShiny(pp) == 1)
        work->sprites[idx].attrFlags |= BTLV_MCSS_ATTR_SHINY;
    work->sprites[idx].identity.hpState = BGWINFRM_GetScaleRank(POKE_TOOL_GetPartyValue(pp, BTLV_PARTY_VALUE_HP, 0), POKE_TOOL_GetPartyValue(pp, BTLV_PARTY_VALUE_MAX_HP, 0));
    work->sprites[idx].flags.refreshed = 1;
}

int BTLV_MCSS_GetSpriteWeight(BtlvMcssWork *work, int pos)
{
    int i = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (i == -1)
        return 0;
    if (work->sprites[i].mcss == 0)
        return 0;
    return work->sprites[i].identity.weight;
}

int BTLV_MCSS_GetSpriteAttrFlags(BtlvMcssWork *work, int pos)
{
    int i;

    if (pos == 0xff)
        return 0;
    i = BTLV_MCSS_FindSpriteIndex(work, pos);
    if (i == -1)
        return 0;
    if (work->sprites[i].mcss == 0)
        return 0;
    return work->sprites[i].attrFlags;
}

int BTLV_MCSS_HasPersonalParam10(BtlvMcssWork *work, int pos)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (idx == -1)
        return 0;
    if (work->sprites[idx].mcss == 0)
        return 0;
    if (POKE_TOOL_GetPersonalParam(work->sprites[idx].identity.species, work->sprites[idx].identity.form, 0x10))
        return 1;
    return 0;
}

int BTLV_MCSS_GetStopCellFlags(BtlvMcssWork *work, int pos)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (idx == -1)
        return 0;
    if (work->sprites[idx].mcss == 0)
        return 0;
    return MCSS_GetStopCellFlags((struct McssWork *)work->sprites[idx].mcss);
}

/* showSubstitute 0 restores the Pokemon sprite, otherwise the substitute doll resources are loaded. */
void BTLV_MCSS_SetSubstituteSprite(BtlvMcssWork *work, int pos, int showSubstitute, int setSwapped)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);
    BtlvMcssSprite *sprites;
    McssAddWork addWork;
    int odd;

    if (idx == -1)
        return;
    sprites = work->sprites;
    if (sprites[idx].mcss == 0)
        return;
    if (showSubstitute == 0) {
        MCSS_TOOL_SetSpindaSpotHook(work->mcss, work->sprites[idx].identity.personalRand);
        MCSS_ReloadResource(work->mcss, work->sprites[idx].mcss, (const McssAddWork *)&work->sprites[idx].addWork.arcId);
        MCSS_SetAnimCallback(work->sprites[idx].mcss, idx, (uptr)BTLV_MCSS_IdleAnimCallback, 1);
        if (setSwapped)
            work->sprites[idx].attrFlags &= ~BTLV_MCSS_ATTR_SWAPPED;
        work->sprites[idx].attrFlags &= ~BTLV_MCSS_ATTR_SUBSTITUTE;
    } else {
        addWork.arcId = POKEGRA_GetArcID();
        odd = pos & 1;
        addWork.textureMember = odd ? 0x37a0 : 0x37a6;
        addWork.paletteMember = 0x37ac;
        addWork.cellMember = odd ? 0x37a1 : 0x37a7;
        addWork.cellAnimMember = odd ? 0x37a2 : 0x37a8;
        addWork.multiCellMember = odd ? 0x37a3 : 0x37a9;
        addWork.multiCellAnimMember = odd ? 0x37a4 : 0x37aa;
        addWork.cellHeaderMember = odd ? 0x37a5 : 0x37ab;
        addWork.heapMode = 0;
        MCSS_ReloadResource(work->mcss, sprites[idx].mcss, (const McssAddWork *)&addWork.arcId);
        BTLV_MCSS_StartPaletteCopy(work, pos);
        if (setSwapped)
            work->sprites[idx].attrFlags |= BTLV_MCSS_ATTR_SWAPPED;
        work->sprites[idx].attrFlags |= BTLV_MCSS_ATTR_SUBSTITUTE;
    }
}

void BTLV_MCSS_SetMosaic(BtlvMcssWork *work, int pos, int mosaic)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    MCSS_TOOL_SetSpindaSpotHook(work->mcss, work->sprites[idx].identity.personalRand);
    MCSS_SetMosaic((struct McssSys *)work->mcss, (struct McssWork *)work->sprites[idx].mcss, mosaic);
}

/* Copy the identity and resources of sprite posA to posB, shifting the resource ids to the other side's set. */
void BTLV_MCSS_CopySpriteResources(BtlvMcssWork *work, int posA, int posB)
{
    int idxA = BTLV_MCSS_FindSpriteIndex(work, posA);
    int idxB = BTLV_MCSS_FindSpriteIndex(work, posB);

    work->sprites[idxB].addWork.arcId = work->sprites[idxA].addWork.arcId;
    work->sprites[idxB].addWork.paletteMember = work->sprites[idxA].addWork.paletteMember;
    if (posA & 1) {
        work->sprites[idxB].addWork.textureMember = work->sprites[idxA].addWork.textureMember + 9;
        work->sprites[idxB].addWork.cellMember = work->sprites[idxA].addWork.cellMember + 9;
        work->sprites[idxB].addWork.cellAnimMember = work->sprites[idxA].addWork.cellAnimMember + 9;
        work->sprites[idxB].addWork.multiCellMember = work->sprites[idxA].addWork.multiCellMember + 9;
        work->sprites[idxB].addWork.multiCellAnimMember = work->sprites[idxA].addWork.multiCellAnimMember + 9;
        work->sprites[idxB].addWork.cellHeaderMember = work->sprites[idxA].addWork.cellHeaderMember + 9;
    } else {
        work->sprites[idxB].addWork.textureMember = work->sprites[idxA].addWork.textureMember - 9;
        work->sprites[idxB].addWork.cellMember = work->sprites[idxA].addWork.cellMember - 9;
        work->sprites[idxB].addWork.cellAnimMember = work->sprites[idxA].addWork.cellAnimMember - 9;
        work->sprites[idxB].addWork.multiCellMember = work->sprites[idxA].addWork.multiCellMember - 9;
        work->sprites[idxB].addWork.multiCellAnimMember = work->sprites[idxA].addWork.multiCellAnimMember - 9;
        work->sprites[idxB].addWork.cellHeaderMember = work->sprites[idxA].addWork.cellHeaderMember - 9;
    }
    work->sprites[idxB].identity = work->sprites[idxA].identity;
    MCSS_ReloadResource(work->mcss, work->sprites[idxB].mcss, (const McssAddWork *)&work->sprites[idxB].addWork.arcId);
}

void BTLV_MCSS_ReloadSpriteResource(BtlvMcssWork *work, int pos, McssAddWork *addWork)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    work->sprites[idx].addWork = *addWork;
    MCSS_TOOL_SetSpindaSpotHook(work->mcss, work->sprites[idx].identity.personalRand);
    MCSS_ReloadResource(work->mcss, work->sprites[idx].mcss, (const McssAddWork *)&work->sprites[idx].addWork.arcId);
}

int BTLV_MCSS_PlayCry(BtlvMcssWork *work, int pos, int pitch, int pan, int chorusParamA, int chorusParamB, int chorusParamC)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);
    u32 voiceId;
    u32 buf;
    u32 *out;
    int chorus;
    void *main;
    u32 voice;

    if (idx == -1)
        return 0;
    if (work->sprites[idx].mcss == 0)
        return 0;
    switch (pos) {
    case 0:
    case 1:
        voiceId = gBtlvMcssVoiceIdSingle[pos];
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (work->flags.rotation)
            voiceId = gBtlvMcssVoiceIdRotation[pos - 2];
        else if (work->flags.triple)
            voiceId = gBtlvMcssVoiceIdTriple[pos - 2];
        else
            voiceId = gBtlvMcssVoiceIdDouble[pos - 2];
        break;
    case 6:
    case 7:
        if (work->flags.rotation)
            voiceId = gBtlvMcssVoiceIdRotation[pos - 2];
        else
            voiceId = gBtlvMcssVoiceIdTriple[pos - 2];
        break;
    }
    main = BTLV_EFFECT_GetBattleMain();
    out = &buf;
    chorus = 0;
    if (main != 0) {
        if (BTL_MAIN_GetVoiceOfSlot(main, pos, (struct PerapVoice **)out) == 0)
            out = 0;
    } else {
        out = 0;
    }
    if (chorusParamA != 0 || chorusParamB != 0)
        chorus = 1;
    if (pitch == BTLV_MCSS_CRY_PITCH_AUTO) {
        if (work->sprites[idx].identity.hpState == 1)
            pitch = -0xa00;
        else
            pitch = 0;
    }
    voice = PM_VOICE_Play(work->sprites[idx].identity.species, work->sprites[idx].identity.form, (u8)voiceId, chorus, chorusParamA, chorusParamB, chorusParamC, (void **)out);
    PM_VOICE_AddVolume(voice, (signed char)pan);
    PM_VOICE_AddFrequency(voice, pitch);
    return voice;
}

/* Start the formation turn of a rotation battle: side 0 or 1, dir 0 or 1. */
void BTLV_MCSS_StartRotation(BtlvMcssWork *work, int side, int dir, int playSound)
{
    BtlvMcssRotationTask *task = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x24, 0, gBtlvMcssSourceFileName, 0x8f2);

    task->work = work;
    task->state = 0;
    task->playSound = playSound;
    task->side = side;
    task->dir = dir;
    work->flags.rotating = 1;
    BTLV_EFFECT_RegisterTask(TCB_AddTask(work->taskOwner, BTLV_MCSS_RotationTaskMain, task, 0), BTLV_MCSS_RotationTaskEnd, 2);
}

int BTLV_MCSS_GetSpriteColorCode(BtlvMcssWork *work, int pos)
{
    int i = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (i == -1)
        return 0;
    if (work->sprites[i].mcss == 0)
        return 0;
    return work->sprites[i].colorCode;
}

void BTLV_MCSS_MakeAddWorkFromPoke(BtlvMcssWork *work, void *pp, McssAddWork *out, int pos)
{
    int isBack = 1;

    if (pos & 1)
        isBack = 0;
    MCSS_TOOL_MakeAddWorkFromPP(pp, (struct McssAddWork *)out, isBack);
    MCSS_TOOL_SetSpindaSpotHook(work->mcss, POKE_TOOL_GetPartyValue(pp, BTLV_PARTY_VALUE_PERSONAL_RAND, 0));
}

/*
 * The extern takes `int` as return type for MCSS_GetAnimSeqNumEx (u16 not needed at the caller).
 */
int BTLV_MCSS_SetAnimIndexIfValid(BtlvMcssWork *work, int pos, int animIndex)
{
    int ok = 0;
    int i = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (i == -1)
        return 0;
    if (work->sprites[i].mcss == 0)
        return 0;
    if (animIndex < MCSS_GetAnimSeqNumEx((struct McssWork *)work->sprites[i].mcss)) {
        MCSS_SetAnimeIndex(work->sprites[i].mcss, animIndex);
        ok = 1;
        work->sprites[i].animPending = ok;
    }
    return ok;
}

void BTLV_MCSS_SetAnimPendingCallback(BtlvMcssWork *work, int pos)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    MCSS_SetAnimCallback(work->sprites[idx].mcss, idx, (uptr)BTLV_MCSS_AnimCallbackClearPending, 1);
}

int BTLV_MCSS_IsAnimPending(BtlvMcssWork *work, int pos)
{
    int i = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (i == -1)
        return 0;
    if (work->sprites[i].mcss == 0)
        return 0;
    return work->sprites[i].animPending;
}

/* Put the sprite back on its slot position and hide it when it had to be moved. */
void BTLV_MCSS_ResetSpritePosition(BtlvMcssWork *work, int pos)
{
    BtlvMcssVec want;
    BtlvMcssVec cur;
    BtlvMcssVec off;
    int i = BTLV_MCSS_FindSpriteIndex(work, pos);

    if (i == -1)
        return;
    if (work->sprites[i].mcss == 0)
        return;
    BTLV_MCSS_CalcSlotPosition(work, &want, pos);
    MCSS_GetPosition((struct McssWork *)work->sprites[i].mcss, (u32 *)(&cur));
    MCSS_GetOfsPosition((struct McssWork *)work->sprites[i].mcss, (u32 *)(&off));
    work->sprites[i].flags.repositionHidden = 0;
    if (want.x == cur.x && want.y == cur.y && want.z == cur.z
        && off.x == 0 && off.y == 0 && off.z == 0)
        return;
    work->sprites[i].flags.repositionHidden = 1;
    off.x = 0;
    off.y = 0;
    off.z = 0;
    MCSS_SetPosition((struct McssWork *)work->sprites[i].mcss, (u32 *)(&want));
    MCSS_SetOfsPosition((struct McssWork *)work->sprites[i].mcss, (u32 *)(&off));
    MCSS_SetVanishFlag((struct McssWork *)work->sprites[i].mcss);
}

/*
 * lever: each arm of the result switch writes `flag = 1` out in its own inner switch
 *   (`switch (pos) { case 3: case 4: flag = 1; break; }`), so the case-1 copy is
 *   cross-jumped into a `b` after threading and the pos == 3 beq keeps pointing at it;
 *   a shared `set:` label lets the beq be threaded straight to `flag = 1` (2 bytes out),
 *   and `pos == 3 || pos == 4` folds to a range test.
 */
void BTLV_MCSS_SetSpriteWorkFlagForRule(BtlvMcssWork *work, int pos, int mode)
{
    int flag = 0;
    int i;

    i = BTLV_MCSS_FindSpriteIndex(work, pos);
    if (i == -1)
        return;
    if (work->sprites[i].mcss == 0)
        return;
    if (mode == 1) {
        switch (BTLV_EFFECT_GetMode()) {
        case BTLV_MCSS_RULE_SINGLE:
        case BTLV_MCSS_RULE_ROTATION:
            break;
        case BTLV_MCSS_RULE_DOUBLE:
            switch (pos) {
            case 3:
            case 4:
                flag = 1;
                break;
            }
            break;
        case BTLV_MCSS_RULE_TRIPLE:
            switch (pos) {
            case 2:
            case 5:
            case 6:
                flag = 1;
                break;
            }
            break;
        }
    }
    MCSS_SetMepachiDrawLast((struct McssWork *)work->sprites[i].mcss, flag);
}

int BTLV_MCSS_TakeSpriteRefreshedFlag(BtlvMcssWork *work, int pos)
{
    int i = BTLV_MCSS_FindSpriteIndex(work, pos);
    int r;

    if (i == -1)
        return 0;
    if (work->sprites[i].mcss == 0)
        return 0;
    if (work->sprites[i].flags.refreshed)
        r = 1;
    else
        r = 0;
    work->sprites[i].flags.refreshed = 0;
    return r;
}

void BTLV_MCSS_SaveVanishStates(BtlvMcssWork *work)
{
    BtlvMcssPos pos;
    int j;

    for (pos = 0; pos < BTLV_MCSS_POKE_POS_COUNT; pos++) {
        if (BTLV_MCSS_IsSpriteLoaded(work, pos)) {
            j = BTLV_MCSS_FindSpriteIndex(work, pos);
            work->sprites[j].flags.vanishSaved = BTLV_MCSS_IsVanished(work, pos);
        }
    }
}

void BTLV_MCSS_RestoreVanishStates(BtlvMcssWork *work)
{
    BtlvMcssPos pos;
    int j;

    for (pos = 0; pos < BTLV_MCSS_POKE_POS_COUNT; pos++) {
        if (BTLV_MCSS_IsSpriteLoaded(work, pos)) {
            j = BTLV_MCSS_FindSpriteIndex(work, pos);
            BTLV_MCSS_SetVanishMode(work, pos, work->sprites[j].flags.vanishSaved);
            work->sprites[j].flags.vanishHeld = 0;
        }
    }
}

/*
 * Tail-call stub: forwards (trainer, out) and passes !(pos & 1) as the third
 * argument of MCSS_TOOL_MakeAddWorkFromTrainer.
 */
void BTLV_MCSS_MakeAddWorkFromTrainer(u32 trainer, McssAddWork *out, int pos)
{
    MCSS_TOOL_MakeAddWorkFromTrainer((void *)(uptr)trainer, out, (void *)(uptr)((pos & 1) == 0));
}

static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}

/* Set the sprite scale from the slot scale and the side factor. */
void BTLV_MCSS_ApplySlotScale(BtlvMcssWork *work, int pos)
{
    int idx = BTLV_MCSS_FindSpriteIndex(work, pos);
    fx32 scale;
    BtlvMcssVec s;

    if (idx == -1)
        return;
    if (work->sprites[idx].mcss == 0)
        return;
    scale = BTLV_MCSS_CalcSlotScale(work, pos, work->sprites[idx].flags.orthoBillboard);
    if (pos & 1)
        scale = FX_Mul(scale, work->scaleOdd);
    else
        scale = FX_Mul(scale, work->scaleEven);
    s.x = scale;
    s.y = scale;
    s.z = 0x1000;
    MCSS_SetScale((struct McssWork *)work->sprites[idx].mcss, (u32 *)(&s));
    scale = BTLV_MCSS_CalcSlotScale(work, pos, 0);
    s.x = scale;
    s.y = scale;
    s.z = 0x1000;
    MCSS_SetOfsScale((struct McssWork *)work->sprites[idx].mcss, (u32 *)(&s));
}

/* Create the task of one tween; fn steps it each frame, endCb clears the work mask bit. */
void BTLV_MCSS_CreateTweenTask(BtlvMcssWork *work, int pos, int kind, BtlvMcssVec *from, BtlvMcssVec *to, int frames,
                   int waitFrames, int repeat, void (*fn)(struct TcbTask *, void *), void (*endCb)(void *), int mirrorOdd, u8 serial)
{
    BtlvMcssTween *task = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), 0x54, 0, gBtlvMcssSourceFileName, 0xa4e);

    task->work = work;
    task->pos = pos;
    task->state.mode = kind;
    task->state.count = frames;
    task->state.countReset = frames;
    task->state.wait = 0;
    task->state.waitReset = waitFrames;
    task->state.repeat = repeat * 2;
    task->state.start.x = from->x;
    task->state.start.y = from->y;
    task->state.start.z = from->z;
    task->state.end.x = to->x;
    task->state.end.y = to->y;
    task->state.end.z = to->z;
    task->cur.x = from->x;
    task->cur.y = from->y;
    task->cur.z = from->z;
    task->serial = serial;
    switch (kind) {
    case 0:
        break;
    case 1:
    case 4:
        BTLV_EFFECT_ComputeVectorStep(&task->state.start, to, &task->state.step, INT_TO_FX32(frames));
        break;
    case 3:
        task->state.repeat *= 2;
    case 2:
        task->state.step.x = FX_Div(to->x, INT_TO_FX32(frames));
        task->state.step.y = FX_Div(to->y, INT_TO_FX32(frames));
        task->state.step.z = FX_Div(to->z, INT_TO_FX32(frames));
        if ((pos & 1) && mirrorOdd) {
            task->state.step.x *= -1;
            task->state.step.z *= -1;
        }
        break;
    }
    BTLV_EFFECT_RegisterTask(TCB_AddTask(work->taskOwner, fn, task, 0), endCb, 2);
}

/* Position tween task. */
void BTLV_MCSS_PositionTweenTaskMain(struct TcbTask *task, void *arg)
{
    BtlvMcssTween *t = arg;
    BtlvMcssWork *w = t->work;
    int i = BTLV_MCSS_FindSpriteIndex(w, t->pos);
    BtlvMcssVec v;
    int done;

    if (i == -1) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (w->sprites[i].mcss == 0) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (t->serial != w->positionSerial[t->pos]) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    MCSS_GetPosition((struct McssWork *)w->sprites[i].mcss, (u32 *)(&v));
    done = BTLV_EFFECT_StepMover(&t->state, &v);
    MCSS_SetPosition((struct McssWork *)w->sprites[i].mcss, (u32 *)(&v));
    if (done == 1)
        BTLV_EFFECT_DeleteTask(task);
}

void BTLV_MCSS_PositionTweenTaskEnd(void *task)
{
    BtlvMcssTween *t = (struct BtlvMcssTween *)TCBL_GetOwnedWork(task);

    if (t->serial == t->work->positionSerial[t->pos])
        t->work->positionTweenMask &= BTLV_EFFECT_GetBitMask(t->pos) ^ 0xFFFFFFFF;
}

/* Shadow scale tween task. */
void BTLV_MCSS_ShadowScaleTweenTaskMain(struct TcbTask *task, void *arg)
{
    BtlvMcssTween *t = arg;
    BtlvMcssWork *w = t->work;
    int i = BTLV_MCSS_FindSpriteIndex(w, t->pos);
    BtlvMcssVec v;
    int done;

    if (i == -1) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (w->sprites[i].mcss == 0) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (t->serial != w->shadowScaleSerial[t->pos]) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    MCSS_GetShadowScale((struct McssWork *)w->sprites[i].mcss, (u32 *)(&v));
    done = BTLV_EFFECT_StepMover(&t->state, &v);
    MCSS_SetShadowScale((struct McssWork *)w->sprites[i].mcss, (u32 *)(&v));
    if (done == 1)
        BTLV_EFFECT_DeleteTask(task);
}

void BTLV_MCSS_ShadowScaleTweenTaskEnd(void *task)
{
    BtlvMcssTween *t = (struct BtlvMcssTween *)TCBL_GetOwnedWork(task);

    if (t->serial == t->work->shadowScaleSerial[t->pos])
        t->work->shadowScaleTweenMask &= BTLV_EFFECT_GetBitMask(t->pos) ^ 0xFFFFFFFF;
}

/* Scale tween task. */
void BTLV_MCSS_ScaleTweenTaskMain(struct TcbTask *task, void *arg)
{
    BtlvMcssTween *t = arg;
    BtlvMcssWork *w = t->work;
    int i = BTLV_MCSS_FindSpriteIndex(w, t->pos);
    BtlvMcssVec v;
    int done;

    if (i == -1) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (w->sprites[i].mcss == 0) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (t->serial != w->scaleSerial[t->pos]) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    MCSS_GetScale((struct McssWork *)w->sprites[i].mcss, (u32 *)(&v));
    done = BTLV_EFFECT_StepMover(&t->state, &v);
    MCSS_SetScale((struct McssWork *)w->sprites[i].mcss, (u32 *)(&v));
    if (done == 1)
        BTLV_EFFECT_DeleteTask(task);
}

void BTLV_MCSS_ScaleTweenTaskEnd(void *task)
{
    BtlvMcssTween *t = (struct BtlvMcssTween *)TCBL_GetOwnedWork(task);

    if (t->serial == t->work->scaleSerial[t->pos])
        t->work->scaleTweenMask &= BTLV_EFFECT_GetBitMask(t->pos) ^ 0xFFFFFFFF;
}

/* Draw scale tween task. */
void BTLV_MCSS_DrawScaleTweenTaskMain(struct TcbTask *task, void *arg)
{
    BtlvMcssTween *t = arg;
    BtlvMcssWork *w = t->work;
    int i = BTLV_MCSS_FindSpriteIndex(w, t->pos);
    BtlvMcssVec v;
    int done;

    if (i == -1) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (w->sprites[i].mcss == 0) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (t->serial != w->drawScaleSerial[t->pos]) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    MCSS_GetDrawScale((struct McssWork *)w->sprites[i].mcss, (u32 *)(&v));
    done = BTLV_EFFECT_StepMover(&t->state, &v);
    MCSS_SetDrawScale((struct McssWork *)w->sprites[i].mcss, (u32 *)(&v));
    if (done == 1)
        BTLV_EFFECT_DeleteTask(task);
}

void BTLV_MCSS_DrawScaleTweenTaskEnd(void *task)
{
    BtlvMcssTween *t = (struct BtlvMcssTween *)TCBL_GetOwnedWork(task);

    if (t->serial == t->work->drawScaleSerial[t->pos])
        t->work->drawScaleTweenMask &= BTLV_EFFECT_GetBitMask(t->pos) ^ 0xFFFFFFFF;
}

/* Rotate tween task. */
void BTLV_MCSS_RotateTweenTaskMain(struct TcbTask *task, void *arg)
{
    BtlvMcssTween *t = arg;
    BtlvMcssWork *w = t->work;
    int i = BTLV_MCSS_FindSpriteIndex(w, t->pos);
    BtlvMcssVec v;
    int done;

    if (i == -1) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (w->sprites[i].mcss == 0) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (t->serial != w->rotateSerial[t->pos]) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    MCSS_GetRotate((struct McssWork *)w->sprites[i].mcss, (u32 *)(&v));
    done = BTLV_EFFECT_StepMover(&t->state, &v);
    MCSS_SetRotate((struct McssWork *)w->sprites[i].mcss, (u32 *)(&v));
    if (done == 1)
        BTLV_EFFECT_DeleteTask(task);
}

void BTLV_MCSS_RotateTweenTaskEnd(void *task)
{
    BtlvMcssTween *t = (struct BtlvMcssTween *)TCBL_GetOwnedWork(task);

    if (t->serial == t->work->rotateSerial[t->pos])
        t->work->rotateTweenMask &= BTLV_EFFECT_GetBitMask(t->pos) ^ 0xFFFFFFFF;
}

/* Blink task: toggles the blink every `reload` frames until `count` toggles are done. */
void BTLV_MCSS_BlinkTaskMain(struct TcbTask *task, void *arg)
{
    BtlvMcssBlinkTask *t = arg;

    BtlvMcssWork *w = t->work;

    if (BTLV_MCSS_IsSpriteLoaded(w, t->pos) == 0 || t->serial != w->blinkSerial[t->pos]) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (t->wait == 0) {
        t->wait = t->reload;
        BTLV_MCSS_SetBlinkMode(t->work, t->pos, 2);
        if (--t->count == 0) {
            BTLV_MCSS_SetBlinkMode(t->work, t->pos, 0);
            BTLV_EFFECT_DeleteTask(task);
        }
    } else {
        t->wait--;
    }
}

void BTLV_MCSS_BlinkTaskEnd(void *task)
{
    BtlvMcssBlinkTask *t = (struct BtlvMcssBlinkTask *)TCBL_GetOwnedWork(task);

    if (t->serial == t->work->blinkSerial[t->pos])
        t->work->blinkTaskMask &= BTLV_EFFECT_GetBitMask(t->pos) ^ 0xFFFFFFFF;
}

/* Alpha tween task. */
void BTLV_MCSS_AlphaTweenTaskMain(struct TcbTask *task, void *arg)
{
    BtlvMcssTween *t = arg;
    BtlvMcssWork *w = t->work;
    int i = BTLV_MCSS_FindSpriteIndex(w, t->pos);
    int done;

    if (i == -1) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (w->sprites[i].mcss == 0) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (t->serial != w->alphaSerial[t->pos]) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    done = BTLV_EFFECT_StepMover(&t->state, &t->cur);
    MCSS_SetAlpha((struct McssWork *)w->sprites[i].mcss, (u8)(t->cur.x >> 12));
    if (done == 1)
        BTLV_EFFECT_DeleteTask(task);
}

void BTLV_MCSS_AlphaTweenTaskEnd(void *task)
{
    BtlvMcssTween *t = (struct BtlvMcssTween *)TCBL_GetOwnedWork(task);

    if (t->serial == t->work->alphaSerial[t->pos])
        t->work->alphaTweenMask &= BTLV_EFFECT_GetBitMask(t->pos) ^ 0xFFFFFFFF;
}

/* Shake task: moves the sprite offset along a sine wave in one of three planes. */
void BTLV_MCSS_ShakeTaskMain(struct TcbTask *task, void *arg)
{
    BtlvMcssShakeParams *q = arg;

    BtlvMcssWork *w = q->work;
    BtlvMcssVec v = {0, 0, 0};
    int i = BTLV_MCSS_FindSpriteIndex(w, q->pos);
    int offsetX, offsetY;
    int sinIndex;
    if (i == -1) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (w->sprites[i].mcss == 0) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (q->serial != w->positionSerial[q->pos]) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (q->pauseCounter == 0) {
        if (q->intervalCounter == q->stepInterval) {
        q->intervalCounter = 0;
        if (q->mode & 1)
            q->phase -= q->phaseStep;
        else
            q->phase += q->phaseStep;
        if (q->phase & 0xffff0000) {
            q->phase = (u16)q->phase;
            q->cycles -= 1;
            q->pauseCounter = q->cyclePause;
        }
        if (q->cycles != 0) {
            switch (q->waveStart) {
            case 0:
                sinIndex = ((u16)(q->phase + 0x4000) >> 4) * 2;
                offsetX = FX_SinCosTable_[sinIndex];
                offsetX = -FX32_MUL(offsetX, q->amplitudeX);
                offsetY = FX_SinCosTable_[sinIndex + 1];
                offsetY = -FX32_MUL(offsetY, q->amplitudeY);
                offsetX += q->amplitudeX;
                break;
            case 1:
                sinIndex = ((u16)(q->phase + 0x4000) >> 4) * 2;
                offsetX = FX_SinCosTable_[sinIndex];
                offsetX = FX32_MUL(offsetX, q->amplitudeX) - q->amplitudeX;
                offsetY = FX_SinCosTable_[sinIndex + 1];
                offsetY = FX32_MUL(offsetY, q->amplitudeY);
                break;
            case 2:
                sinIndex = (q->phase >> 4) * 2;
                offsetX = FX_SinCosTable_[sinIndex];
                offsetX = -FX32_MUL(offsetX, q->amplitudeX);
                offsetY = FX_SinCosTable_[sinIndex + 1];
                offsetY = -FX32_MUL(offsetY, q->amplitudeY);
                offsetY += q->amplitudeY;
                break;
            case 3:
                sinIndex = (q->phase >> 4) * 2;
                offsetX = FX_SinCosTable_[sinIndex];
                offsetX = FX32_MUL(offsetX, q->amplitudeX);
                offsetY = FX_SinCosTable_[sinIndex + 1];
                offsetY = FX32_MUL(offsetY, q->amplitudeY) - q->amplitudeY;
                break;
            }
            switch ((q->mode & 7) >> 1) {
            default:
            case 0:
                v.z = offsetX;
                v.y = offsetY;
                break;
            case 1:
                v.x = offsetX;
                v.z = offsetY;
                break;
            case 2:
                v.x = offsetX;
                v.y = offsetY;
                break;
            }
        }
        MCSS_SetOfsPosition((struct McssWork *)w->sprites[i].mcss, (u32 *)(&v));
        } else {
            q->intervalCounter += 1;
        }
    } else {
        q->pauseCounter -= 1;
    }
    if (q->cycles == 0)
        BTLV_EFFECT_DeleteTask(task);
}

/*
 * 2026-10-02 EXACT: the call argument is spelled as a raw offset load
 * (*(int *)((char *)p + 4)) while the tag index uses q->pos. With one spelling CSE hoists
 * pos ahead of the index and it loads first (the +0x50 twins' order); with two spellings pos
 * is copy-propagated and p->work loads first, as the image does.
 */
void BTLV_MCSS_ShakeTaskEnd(void *task)
{
    BtlvMcssShakeParams *q = (struct BtlvMcssShakeParams *)TCBL_GetOwnedWork(task);

    if (q->serial == q->work->positionSerial[q->pos])
        q->work->positionTweenMask &= BTLV_EFFECT_GetBitMask(*(int *)((char *)q + 4)) ^ 0xFFFFFFFF;
}

/*
 * lever: Separate x/y/z clears preserve the original store order.
 */
void BTLV_MCSS_BounceTaskMain(struct TcbTask *task, void *arg)
{
    BtlvMcssBounceParams *q = arg;

    BtlvMcssWork *w = q->work;
    BtlvMcssVec v = {0, 0, 0};
    int i = BTLV_MCSS_FindSpriteIndex(w, q->pos);
    int sine, offset;
    if (i == -1) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (w->sprites[i].mcss == 0) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (q->serial != w->positionSerial[q->pos]) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    q->phase += q->phaseStep;
    sine = FX_SinCosTable_[((q->phase & 0x0ffff000) >> 16) * 2];
    offset = FX32_FROM_FLOAT((float)sine / 4096.0f);
    offset = (int)(((s64)offset * q->amplitude + 0x800) >> 12);
    if (q->axisY != 0) v.y = offset;
    else v.x = offset;
    MCSS_SetOfsPosition((struct McssWork *)w->sprites[i].mcss, (u32 *)(&v));
    q->frames -= 1;
    if (q->frames == 0) {
        v.x = 0;
        v.y = 0;
        v.z = 0;
        MCSS_SetOfsPosition((struct McssWork *)w->sprites[i].mcss, (u32 *)(&v));
        BTLV_EFFECT_DeleteTask(task);
    }
}

/*
 * 2026-10-02 EXACT: see BTLV_MCSS_ShakeTaskEnd: the call argument is a raw offset load while the
 * tag index uses q->pos.
 */
void BTLV_MCSS_BounceTaskEnd(void *task)
{
    BtlvMcssBounceParams *q = (struct BtlvMcssBounceParams *)TCBL_GetOwnedWork(task);

    if (q->serial == q->work->positionSerial[q->pos])
        q->work->positionTweenMask &= BTLV_EFFECT_GetBitMask(*(int *)((char *)q + 4)) ^ 0xFFFFFFFF;
}

/* Mosaic tween task. */
void BTLV_MCSS_MosaicTweenTaskMain(struct TcbTask *task, void *arg)
{
    BtlvMcssTween *t = arg;
    BtlvMcssWork *w = t->work;
    int i = BTLV_MCSS_FindSpriteIndex(w, t->pos);
    int done;

    if (i == -1) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (w->sprites[i].mcss == 0) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (t->serial != w->mosaicSerial[t->pos]) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    done = BTLV_EFFECT_StepMover(&t->state, &t->cur);
    BTLV_MCSS_SetMosaic(w, t->pos, t->cur.x >> 12);
    if (done == 1) {
        MCSS_SetAnimCallback(w->sprites[i].mcss, i, (uptr)BTLV_MCSS_IdleAnimCallback, 1);
        BTLV_EFFECT_DeleteTask(task);
    }
}

void BTLV_MCSS_MosaicTweenTaskEnd(void *task)
{
    BtlvMcssTween *t = (struct BtlvMcssTween *)TCBL_GetOwnedWork(task);

    if (t->serial == t->work->mosaicSerial[t->pos])
        t->work->mosaicTweenMask &= BTLV_EFFECT_GetBitMask(t->pos) ^ 0xFFFFFFFF;
}

/*
 * lever: Offset local precedes the entry pointer, and is initialized first.
 */
void BTLV_MCSS_AnimWatchTaskMain(struct TcbTask *task, void *arg)
{
    BtlvMcssAnimWatch *q = arg;

    BtlvMcssWork *w = BTLV_EFFECT_GetMcss();
    int i = q->pos;
    int off;
    char *e;
    if (i == -1) {
        GFL_HEAP_Free(q);
        TCB_DeleteTask(task);
        return;
    }
    off = i * 0x5c;
    e = (char *)w->sprites;
    if (*(struct McssWork **)(e + off) == 0) {
        GFL_HEAP_Free(q);
        TCB_DeleteTask(task);
        return;
    }
    switch (q->state) {
    case 0:
        ((AnimCtrl *)MCSS_GetAnimCtrl(*(struct McssWork **)(e + off)))->bActive = 0;
        MCSS_SetCellCallback(*(struct McssWork **)(e + off), i | 0x80000000, BTLV_MCSS_CellCallbackCheckStopCell);
        q->state++;
        q->wait = gBtlvMcssIdleWaitFrames[(u32)(((u64)GF_STANDARD_Rand() * 3) >> 32)];
        return;
    case 1:
        q->wait--;
        if (q->wait != 0 && w->rotateTweenMask == 0 && BTLV_EFFVM_GetFallbackScriptFlag(BTLV_EFFECT_GetEffvm()) != 0) break;
        MCSS_SetAnimeIndex(*(struct McssWork **)(e + off), 0);
        ((AnimCtrl *)MCSS_GetAnimCtrl(*(struct McssWork **)(e + off)))->bActive = 1;
        MCSS_SetCellCallback(*(struct McssWork **)(e + off), i, BTLV_MCSS_CellCallbackCheckStopCell);
        q->state++;
        return;
    case 2:
        MCSS_SetAnimCallback(*(struct McssWork **)(e + off), i, (uptr)BTLV_MCSS_IdleAnimCallback, 1);
        GFL_HEAP_Free(q);
        TCB_DeleteTask(task);
        *(void **)((char *)w + off + 0x30) = 0;
        break;
    }
}

/*
 * Rotation battle: turns the three sprites of one side around the field.
 * lever: the slot test written as char-pointer arithmetic (p + k * 0x5c + 0x30)
 * swaps the row and base registers in the case-0 loop; indexing a 0x5c-byte
 * struct array evaluates the row first, as the original does.
 */
void BTLV_MCSS_RotationTaskMain(struct TcbTask *task, void *arg)
{
    BtlvMcssRotationTask *t = arg;

    BtlvMcssSideTable positions = gBtlvMcssRotationPositions;
    BtlvMcssSideTable angles = gBtlvMcssRotationStartAngles;
    BtlvMcssRotateTable targets = gBtlvMcssRotationTargets;
    BtlvMcssVec v;
    BtlvMcssVec pos;
    int idx[3];
    int i;
    int step;

    switch (t->state) {
    case 0:
        for (i = 0; i < 3; i++) {
            if (t->work->sprites[positions.v[t->side][i]].animWatchTask != 0)
                break;
        }
        if (i != 3)
            return;
        for (i = 0; i < 3; i++)
            t->angle[i] = angles.v[t->side][i];
        step = (t->dir == 0) ? 0x1000 : -0x1000;
        BTLV_STAGE_ArmLayerEntry(BTLV_EFFECT_GetStage(), t->side, 0, step, 0x3c);
        t->angleStep = (t->dir == 0) ? 0x16c : -0x16c;
        t->framesLeft = 0x3c;
        if (t->playSound)
            GFL_USE_PlaySeInSlot(BTLV_MCSS_SE_ROTATION_START, 2);
        t->state++;
        return;
    case 1:
        for (i = 0; i < 3; i++) {
            if (BTLV_MCSS_IsSpriteLoaded(t->work, positions.v[t->side][i])) {
                v.x = FX32_MUL(FX_SinCosTable_[((u16)t->angle[i] >> 4) * 2], 0x5000);
                v.y = 0x666;
                v.z = (t->side == 0) ? 0xc000 : -0xd000;
                v.z += FX32_MUL(FX_SinCosTable_[((u16)t->angle[i] >> 4) * 2 + 1], 0x5000);
                BTLV_MCSS_StartPositionTween(t->work, positions.v[t->side][i], 0, &v, 0, 0, 0);
            }
            t->angle[i] += t->angleStep;
        }
        if (--t->framesLeft != 0)
            return;
        for (i = 0; i < 3; i++) {
            if (BTLV_MCSS_IsSpriteLoaded(t->work, positions.v[t->side][i])) {
                BTLV_MCSS_CalcSlotPosition(t->work, &pos, targets.v[t->dir][t->side][i]);
                BTLV_MCSS_StartPositionTween(t->work, positions.v[t->side][i], 0, &pos, 0, 0, 0);
            }
        }
        t->state++;
        return;
    case 2:
        if (t->work->positionTweenMask != 0)
            return;
        for (i = 0; i < 3; i++) {
            idx[i] = BTLV_MCSS_FindSpriteIndex(t->work, positions.v[t->side][i]);
            BTLV_GAUGE_HideSlot(BTLV_EFFECT_GetGauge(), positions.v[t->side][i]);
        }
        for (i = 0; i < 3; i++) {
            if (idx[i] != -1)
                t->work->sprites[idx[i]].pos = targets.v[t->dir][t->side][i];
        }
        if (t->playSound) {
            GFL_USE_StopSeSlot(2);
            GFL_USE_PlaySeInSlot(BTLV_MCSS_SE_ROTATION_END, 1);
        }
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
}

void BTLV_MCSS_RotationTaskEnd(void *task)
{
    BtlvMcssWork *w = *((BtlvMcssWork **)TCBL_GetOwnedWork(task));
    w->flags.rotating = 0;
}

/*
 * Animation callback: after the sprite stops on its last idle cell, count down and
 * start the idle animation watcher.
 * lever: Bind the random draw before the variable 64-bit product.
 */
void BTLV_MCSS_IdleAnimCallback(int pos)
{
    BtlvMcssWork *w = BTLV_EFFECT_GetMcss();
    BtlvMcssSprite *sprites;
    unsigned n;
    u32 draw;
    BtlvMcssAnimWatch *watch;
    if (pos == -1) return;
    sprites = w->sprites;
    if (sprites[pos].mcss == 0) return;
    if (BTLV_EFFVM_GetFallbackScriptFlag(BTLV_EFFECT_GetEffvm()) == 0) return;
    if (w->flags.rotating) return;
    if (MCSS_GetStopCellNum((struct McssWork *)sprites[pos].mcss) == 0xff) {
        w->sprites[pos].flags.restartAnim = 1;
        return;
    }
    n = w->sprites[pos].flags.idleCounter;
    w->sprites[pos].flags.idleCounter = n - 1;
    draw = GF_STANDARD_Rand();
    if ((u32)(((u64)draw * n) >> 32) != 0) return;
    w->sprites[pos].flags.idleCounter = 3;
    watch = GFL_HEAP_Alloc((u16)((w->heapId & 0x7fff) | 0x8000), 12, 1, gBtlvMcssSourceFileName, 0xd5e);
    watch->pos = pos;
    if (MCSS_GetAnimSeqNum((struct McssWork *)sprites[pos].mcss) > 1) MCSS_SetAnimeIndex(sprites[pos].mcss, 1);
    w->sprites[pos].animWatchTask = TCB_AddTask(w->taskOwner, BTLV_MCSS_AnimWatchTaskMain, watch, 0);
}

/*
 * Cell callback: reports through out[3] whether the cell is one of the stop cells.
 * lever: the first test reads the row through the indexed base (`base[idx].mcss`), the loop
 *   through `s = &base[idx]` inside the loop body; a shared `base + off` char cast is CSE'd
 *   into one register and comes out 8 bytes short. `idx == -1` (u16 against int -1) is not
 *   folded: it keeps the movs/mvns pair. The two `v = 1` arms cross-jump only when the
 *   found test is `if (found == 0) v = 0; else v = 1;`.
 */
int BTLV_MCSS_CellCallbackCheckStopCell(void *ctx, void *record, void *value, int stopCell)
{
    u32 flags = (u32)(uptr)ctx;
    int *out = value;
    BtlvMcssWork *work = BTLV_EFFECT_GetMcss();
    u16 idx = flags;
    int found;
    int n;
    int i;
    int v;

    if (idx == -1)
        return 0;
    if (work->sprites[idx].mcss == 0)
        return 0;
    if (flags & 0x80000000) {
        found = 0;
        n = MCSS_GetStopCellNum((struct McssWork *)work->sprites[idx].mcss);
        for (i = 0; i < n; i++) {
            BtlvMcssSprite *s = &work->sprites[idx];

            if (stopCell == MCSS_GetStopCellIndex((struct McssWork *)s->mcss, i))
                found = 1;
        }
        if (found == 0)
            v = 0;
        else
            v = 1;
    } else {
        v = 1;
    }
    out[3] = v;
    return 1;
}

void BTLV_MCSS_AnimCallbackClearPending(int pos)
{
    BTLV_EFFECT_GetMcss()->sprites[pos].animPending = 0;
}

/* Slot position of a sprite, depending on the battle rule. */
void BTLV_MCSS_CalcSlotPosition(BtlvMcssWork *work, BtlvMcssVec *out, int pos)
{
    const BtlvMcssVec *t = (const BtlvMcssVec *)work;

    switch (pos) {
    case 0:
    case 1:
        t = &gBtlvMcssSlotPosSingle[pos];
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (work->flags.rotation)
            t = &gBtlvMcssSlotPosRotation[pos - 2];
        else if (work->flags.triple)
            t = &gBtlvMcssSlotPosTriple[pos - 2];
        else
            t = &gBtlvMcssSlotPosDouble[pos - 2];
        break;
    case 6:
    case 7:
        if (work->flags.rotation)
            t = &gBtlvMcssSlotPosRotation[pos - 2];
        else
            t = &gBtlvMcssSlotPosTriple[pos - 2];
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        t = &gBtlvMcssSlotPosTrainer[pos - 8];
        break;
    }
    out->x = t->x;
    out->y = t->y;
    out->z = t->z;
}

/* Default scale (fx32) of a slot; mode 0 is the per rule table, otherwise 2.0 / 1.0 by side. */
int BTLV_MCSS_CalcSlotScale(BtlvMcssWork *work, int pos, int mode)
{
    if (mode == 0) {
        switch (pos) {
        case 0:
        case 1:
            return gBtlvMcssSlotScaleSingle[pos];
        case 2:
        case 3:
        case 4:
        case 5:
            if (work->flags.rotation)
                return gBtlvMcssSlotScaleRotation[pos - 2];
            if (work->flags.triple)
                return gBtlvMcssSlotScaleTriple[pos - 2];
            return gBtlvMcssSlotScaleDouble[pos - 2];
        case 6:
        case 7:
            if (work->flags.rotation)
                return gBtlvMcssSlotScaleRotation[pos - 2];
            return gBtlvMcssSlotScaleTriple[pos - 2];
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            return gBtlvMcssSlotScaleTrainer[pos - 8];
        }
        return (sptr)work;
    } else {
        if (pos < 8) {
            if (pos & 1)
                return 0x10000;
            return 0x20000;
        }
        return 0x10000;
    }
}

int BTLV_MCSS_FindSpriteIndex(BtlvMcssWork *work, int pos)
{
    int i;

    for (i = 0; i < BTLV_MCSS_SPRITE_MAX; i++) {
        if (work->sprites[i].mcss != 0 && pos == work->sprites[i].pos)
            return i;
    }
    return -1;
}

/*
 * Shadow offset, rotation and visibility of species `species` on the side of `pos`.
 * lever: `(pos & 1) == e->mirror` written inline in the condition; a hoisted local `f = pos & 1` costs a different register order.
 */
int BTLV_MCSS_LookupShadowEntry(int species, int pos, BtlvMcssVec *offset, u16 *rotateZ, int *visible)
{
    int found = 0;
    unsigned i;

    for (i = 0; i < 0x30; i++) {
        const BtlvMcssAnimEntry *e = (const BtlvMcssAnimEntry *)(gBtlvMcssShadowTable + i * 8);
        unsigned o = i * 8;

        if (species == e->species && (pos & 1) == e->mirror) {
            offset->x = *(const s16 *)(gBtlvMcssShadowTableOffsetX + o);
            offset->y = 0;
            offset->z = *(const s16 *)(gBtlvMcssShadowTableOffsetZ + o);
            *rotateZ = *(const u16 *)(gBtlvMcssShadowTableRotateZ + o);
            *visible = e->shadowVisible;
            found = 1;
            break;
        }
    }
    return found;
}
