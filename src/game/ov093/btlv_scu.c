/*
 * file:     btlv_scu.c
 * unit:     yes
 * function: BTLV_SCU_PlaySeUnlessMainStep, BTLV_SCU_InitMessage, BTLV_SCU_AppendMessageArg, BTLV_SCU_SetMessageParam, BTLV_SCU_Create, BTLV_SCU_SetupDisplay, BTLV_SCU_LoadArcTiles, BTLV_SCU_Delete, BTLV_SCU_ReloadGraphics, BTLV_SCU_IsFadeDone, BTLV_SCU_StartEntryScene, BTLV_SCU_RunProc, BTLV_SCU_StartBrightnessFade, BTLV_SCU_ProcQuickEntry, BTLV_SCU_ProcQuickEntrySingle, BTLV_SCU_ProcQuickEntryDouble, BTLV_SCU_ProcQuickEntryTriple, BTLV_SCU_ProcEntrySingleWild, BTLV_SCU_GetEntryMessageId, BTLV_SCU_ProcEntrySingleTrainer, BTLV_SCU_ProcEntrySingleLink, BTLV_SCU_ProcEntryDoubleWild, BTLV_SCU_ProcEntryDoubleTrainerLocal, BTLV_SCU_ProcEntryDoubleTrainerComm, BTLV_SCU_ProcEntryDoubleLinkLocal, BTLV_SCU_ProcEntryDoubleLinkComm, BTLV_SCU_ProcEntryTriple, BTLV_SCU_ProcEntryTripleLink, BTLV_SCU_PhaseTrainerIntro, BTLV_SCU_PhaseTrainerIntroComm, BTLV_SCU_RunTrainerIntroOne, BTLV_SCU_RunTrainerIntroTwo, BTLV_SCU_PhaseOpponentSendOutSingle, BTLV_SCU_PhaseOpponentSendOutDouble, BTLV_SCU_RunOpponentSendOutDoubleOneTrainer, BTLV_SCU_RunOpponentSendOutDoubleTwoTrainers, BTLV_SCU_PhaseOpponentSendOutTriple, BTLV_SCU_PhaseOwnSendOutSingle, BTLV_SCU_PhaseOwnSendOutDouble, BTLV_SCU_RunOwnSendOutDoubleSolo, BTLV_SCU_RunOwnSendOutDoublePartner, BTLV_SCU_PhaseOwnSendOutTriple, BTLV_SCU_GetSendOutMessageId, BTLV_SCU_PrintMessageInstant, BTLV_SCU_StartMessage, BTLV_SCU_ConsumeMessageEnded, BTLV_SCU_UpdateMessage, BTLV_SCU_StartWazaEffect, BTLV_SCU_ProcWazaEffect, BTLV_SCU_RunWazaProc, BTLV_SCU_StartMonDamageAnim, BTLV_SCU_IsMonDamageAnimDone, BTLV_SCU_StartMonMotion, BTLV_SCU_IsMonMotionDone, BTLV_SCU_StartMonExit, BTLV_SCU_IsMonExitDone, BTLV_SCU_LoadAndShowMon, BTLV_SCU_IsMonLoadDone, BTLV_SCU_StartMonWithdraw, BTLV_SCU_IsMonWithdrawDone, BTLV_SCU_TaskMonWithdraw, BTLV_SCU_StartMonSendOut, BTLV_SCU_IsMonSendOutDone, BTLV_SCU_TaskMonSendOut, BTLV_SCU_StartHpGaugeUpdate, BTLV_SCU_IsHpGaugeIdle, BTLV_SCU_HideMonPair, BTLV_SCU_ShowMonPair, BTLV_SCU_HideMon, BTLV_SCU_ShowMon, BTLV_SCU_StartPosCueEffect, BTLV_SCU_IsPosCueEffectDone, BTLV_SCU_StartMonFormChange, BTLV_SCU_IsMonFormChangeDone, BTLV_SCU_TaskMonFormChange, BTLV_SCU_StartMonGraphicSwapFrom, BTLV_SCU_StartMonGraphicSwap, BTLV_SCU_IsMonGraphicSwapDone, BTLV_SCU_TaskMonGraphicSwap, BTLV_SCU_InitMsgWinFade, BTLV_SCU_StartMsgWinFadeOut, BTLV_SCU_StartMsgWinFadeIn, BTLV_SCU_UpdateMsgWinFade, BTLV_SCU_StartMsgWinFadeOutTask, BTLV_SCU_IsMsgWinFadeOutTaskDone, BTLV_SCU_TaskMsgWinFadeOut, BTLV_SCU_InitMonSlots, BTLV_SCU_ResetMonSlots, BTLV_SCU_InitMonSlot, BTLV_SCU_ResetMonSlot, BTLV_SCU_HideMonSlot, BTLV_SCU_ShowMonSlot, BTLV_SCU_GetNamePlateSide, BTLV_SCU_StartNamePlate, BTLV_SCU_ProcNamePlateAt, BTLV_SCU_HideNamePlateAt, BTLV_SCU_IsNamePlateHiddenAt, BTLV_SCU_RefreshNamePlateAt, BTLV_SCU_ProcNamePlateMosaicAt, BTLV_SCU_InitNamePlates, BTLV_SCU_FreeNamePlates, BTLV_SCU_PrepareNamePlate, BTLV_SCU_ProcNamePlate, BTLV_SCU_DrawNamePlate, BTLV_SCU_HideNamePlate, BTLV_SCU_IsNamePlateHidden, BTLV_SCU_RefreshNamePlate, BTLV_SCU_ProcNamePlateMosaic, BTLV_SCU_GetBallStates, BTLV_SCU_PrintWaitMessage, BTLV_SCU_UpdateWaitMessage, BTLV_SCU_NoOp, BTLV_SCU_StartFadeIn, BTLV_SCU_ClearWaitWindow, BTLV_SCU_GetWaitState, BTLV_SCU_StartBallWindowOpen, BTLV_SCU_UpdateBallWindowOpen, BTLV_SCU_StartBallWindowRefresh, BTLV_SCU_UpdateBallWindowRefresh, BTLV_SCU_StartBallWindowClose, BTLV_SCU_UpdateBallWindowClose, BTLV_SCU_StepBallWindowOpen, BTLV_SCU_StepBallWindowRefresh, BTLV_SCU_StepBallWindowClose
 * address:  0x021EAF00
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   GFL_HEAP_Alloc  0x02030734  arm    arm9
 *   gBtlvScuFileName     0x021F3AD0  data   a4
 *   STRBUF_Create  0x020457B0  arm    arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   PALANM_LoadArcPaletteToSlotAt 0x020215EC thumb
 *   PALANM_CopyToSlot 0x020215BC thumb
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   ARC_UTIL_UploadBgPaletteFromArchive 0x0204989C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_DrawFrame 0x020454E0 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   gBtlvScuBgTemplateMsg 0x021F3930 data a4
 *   gBtlvScuBgTemplateName 0x021F3950 data a4
 *   gBtlvScuBgTemplateBack 0x021F3970 data a4
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_UTIL_RegisterObjCharFromHandle  0x02049740  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   FADE_IsActive   0x0204E804  arm
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_IsMultiMode 0x021B86C8 thumb ov093
 *   GXx_GetMasterBrightness_  0x0207D55C  arm    arm9
 *   FADE_Start  0x0204E720  arm    arm9
 *   BTL_MAIN_GetSlotFromViewPos  0x021B8ED8  thumb  ov093
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb  ov093
 *   BTL_POKEPARAM_GetDisplayMon  0x021D5864  thumb  ov093
 *   BTLV_EFFECT_SetPokeSpriteKey  0x021F7EE8  thumb  ov094
 *   BTLV_EFFECT_IsBusy  0x021F7EB4  thumb  ov094
 *   gBtlvScuQuickSidesSingle  0x021F38AC  data  a4
 *   gBtlvScuQuickSidesDouble  0x021F38AE  data  a4
 *   gBtlvScuQuickSidesTriple  0x021F38B2  data  a4
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTLV_EFFECT_StartEffectOnPoke 0x021F7A28 thumb ov094
 *   BTL_MSG_FormatArgs 0x021EEE24 thumb ov093
 *   BTLV_EFFECT_StartEffect 0x021F7998 thumb ov094
 *   BTL_MAIN_CheckSetupStatusFlag  0x021BA1A8  thumb  ov093
 *   BTL_MAIN_GetSlotClientIdThunk 0x021B8DE4 thumb ov093
 *   BTL_MAIN_GetTrainerType 0x021BA020 thumb ov093
 *   BTLV_EFFECT_AddPokeSprite 0x021F7F58 thumb ov094
 *   BTLV_EFFECT_CreatePartyBallBar 0x021F823C thumb ov094
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   BTLV_EFFECT_DeletePartyBallBar 0x021F8260 thumb ov094
 *   BTLV_EFFECT_IsPartyBallBarActive 0x021F827C thumb ov094
 *   gBtlvScuSingleLinkPhases  0x021F38E8  data  a4
 *   BTL_MAIN_GetClientTrainerIndex 0x021B8BEC thumb ov093
 *   BTL_MAIN_GetEnemyLanePosFromWork 0x021B8C50 thumb ov093
 *   BTL_MAIN_GetViewPosOfSlot 0x021B8E70 thumb ov093
 *   gBtlvScuDoubleTrainerLocalPhases  0x021F38D0  data  a4
 *   gBtlvScuDoubleTrainerCommPhases  0x021F38DC  data  a4
 *   gBtlvScuDoubleLinkLocalPhases  0x021F3900  data  a4
 *   gBtlvScuDoubleLinkCommPhases  0x021F38B8  data  a4
 *   gBtlvScuEntryTriplePhases  0x021F38C4  data  a4
 *   gBtlvScuEntryTripleLinkPhases  0x021F3918  data  a4
 *   BTL_MAIN_GetOwnOpponentClient  0x021B904C  thumb  ov093
 *   BTL_MAIN_GetOpponentClient 0x021B9064 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_MAIN_GetOwnPartnerClient  0x021B9000  thumb  ov093
 *   BTL_MAIN_IsOwnClientSecondTeam 0x021B8FE4 thumb ov093
 *   BTL_MAIN_IsTrainerSlotNpc 0x021B9F70 thumb ov093
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BTL_MAIN_GetTextSpeedFrames  0x021B85DC  thumb  ov093
 *   PRINTSYS_PrintStreamCallBack  0x0201CD10  thumb
 *   PRINTSYS_PrintStreamStop  0x0201CE0C  thumb
 *   BTL_MAIN_GetCommPos  0x021B86C0  thumb  ov093
 *   PRINTSYS_PrintStreamRun  0x0201CE20  thumb  arm9
 *   PRINTSYS_PrintStreamIsOverrideSpeed  0x0201CED4  thumb  arm9
 *   PRINTSYS_PrintStreamSetSpeed  0x0201CE8C  thumb  arm9
 *   MSG_SPEED_GetWaitForSpeed  0x02013080  thumb  arm9
 *   PRINTSYS_PrintStreamResetSpeed  0x0201CEB8  thumb  arm9
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   KEY_GetCont  0x0203630C  arm  arm9
 *   TOUCHPANEL_GetCont  0x02035C38  arm  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   TOUCHPANEL_GetTrg  0x02035C60  arm  arm9
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   GFL_USE_IsSeqPlaying  0x02006254  thumb  arm9
 *   BTLV_EFFECT_StartEffectWithRequest  0x021F7B2C  thumb  ov094
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTLV_EFFECT_GaugeStartHpChangeAnimated  0x021F80FC  thumb  ov094
 *   BTLV_EFFECT_StartDamageTintTask  0x021F7C2C  thumb  ov094
 *   BTLV_EFFECT_GaugeStartHpChangeInstant  0x021F8118  thumb  ov094
 *   BTLV_EFFECT_GaugeIsAnimating  0x021F8180  thumb  ov094
 *   BTLV_EFFECT_GaugeDeleteSlot  0x021F80E4  thumb  ov094
 *   BTLV_EFFECT_StartPokeAppearEffect  0x021F7CE4  thumb  ov094
 *   BTLV_EFFECT_DeletePokeSprite  0x021F7F04  thumb  ov094
 *   TCBL_AddTask  0x020311B8  arm
 *   TCBL_GetWork  0x02031290  arm
 *   TCBL_DeleteTask  0x02031194  arm
 *   BTL_SIDE_GetClientPoke  0x021B9920  thumb  ov093
 *   BTLV_EFFECT_SetLowHpBgmSuppressed  0x021F87D4  thumb  ov094
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   BTLV_EFFECT_StartHitTask  0x021F7D80  thumb  ov094
 *   BTLV_EFFECT_ResetPokeSprite  0x021F7E38  thumb  ov094
 *   BTLV_EFFECT_GaugeInitSlotFromBattlePoke  0x021F803C  thumb  ov094
 *   G2x_SetBlendAlpha_  0x0207D63C  arm  arm9
 *   BTL_MAIN_GetRuleSlotSpan  0x021B8640  thumb  ov093
 *   BTL_MAIN_GetPosParity  0x021B9AE0  thumb  ov093
 *   BTL_MAIN_IsLocalSide  0x021B8BD0  thumb  ov093
 *   BTLV_EFFECT_TimerSetVisible  0x021F8504  thumb  ov094
 *   BTLV_EFFECT_ResumeVmWait  0x021F8B28  thumb  ov094
 *   ARC_UTIL_LoadBgCharDataFromArchive  0x02049DB4  arm
 *   BMP_Create  0x02043678  arm
 *   BMP_Delete  0x020437AC  arm
 *   BTLV_EFFECT_SetPokeEffectValue  0x021F8AE8  thumb  ov094
 *   BG_SYS_LoadTileData 0x02040B1C arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   BMP_GetPixels 0x020437D4 arm
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb ov094
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   BMP_GetByteSize 0x020437EC arm
 *   MIi_CpuCopy32 0x02082A90 arm
 *   PALANM_RequestFade  0x0202173C  thumb  arm9
 *   HAND_FIELD_AddFactor  0x06898020  thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   BTL_SIDE_GetSlotOfClientThunk 0x021B9AF8 thumb ov093
 *   BTL_SLOT_GetCount 0x021B9B94 thumb ov093
 *   BTL_SLOT_GetPokeParam 0x021B9C00 thumb ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex 0x021D62A8 thumb ov093
 *   BTL_POKEPARAM_IsAbleToBattle 0x021D5B7C thumb ov093
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BTL_POKEPARAM_ReadStatsFromMon  0x021D590C  thumb  ov093
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   BMP_WIN_GetHeight  0x02045740  arm
 *   gBtlRecFileName  0x021F3ADC  data  a4
 *   MI_CpuCopy8  0x02082D44  arm
 *   BTL_ACTION_SetRecordError  0x021D8470  thumb
 *   BTL_ACTION_SetRecordReset  0x021D845C  thumb
 *   gBtlAdapterSlots  0x021F6388  data  a4
 *   gBtlAdapterMode  0x021F6384  data  a4
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   gBtlAdapterFileName     0x021F3AE8  data  ov093  a4
 *   BTL_NET_ExpectReplies   0x021D4C58  thumb
 *   BTL_NET_SendServerCmd  0x021D4B58  thumb  ov093
 *   BTL_NET_AreAllRepliesReceived  0x021D4B98  thumb  ov093
 *   BTL_NET_GetClientReply  0x021D4BD4  thumb  ov093
 *   BTL_NET_HasServerCmd  0x021D4C60  thumb  ov093
 *   BTL_NET_GetServerCmd  0x021D4C6C  thumb  ov093
 *   BTL_NET_SendClientReply  0x021D4C84  thumb  ov093
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   gBtlMsgState     0x021F6398  data  ov093  a4
 *   gBtlMsgFlags     0x021F63D8  data  ov093  a4
 *   sBtlMsgBankFileIds     0x021F3990  data  ov093  a2
 *   WORDSET_Delete  0x0201ED04  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   BTL_SIDE_GetPokeById  0x021B9940  thumb  ov093
 *   WORDSET_SetSlotMonNickname  0x0201EEF4  thumb
 *   WORDSET_SetSlotMonSpeciesName  0x0201EE84  thumb
 *   WORDSET_SetSlotFromMsgBF  0x0201F0F8  thumb
 *   BTL_MAIN_GetTrainerId  0x021BA004  thumb  ov093
 *   BTL_MAIN_GetTrainerNameAndType  0x021B9FAC  thumb  ov093
 *   BTL_MAIN_GetTrainerHandle  0x021BA064  thumb  ov093
 *   BTL_MAIN_UpdateCommPlayerSupport  0x021BA080  thumb  ov093
 *   TPOKE_DATA_GetGenderValue  0x0202A3CC  thumb
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_SetSlotFromMsgBE  0x0201F134  thumb
 *   d_021F63C8     0x021F63C8  data  a4
 *   sBtlMsgSidePairIds     0x021F39A0  data  a2
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   sBtlMsgBuilders  0x021F39D8  data  a4
 *   d_021F39DC  0x021F39DC  data  a4
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   PRINTSYS_GetTagChar  0x0201D5C4  thumb
 *   PRINTSYS_IsWordSlotTag  0x0201D5CC  thumb
 *   PRINTSYS_GetTagParam  0x0201D670  thumb
 *   PRINTSYS_GetTagGroup  0x0201D5F4  thumb
 *   PRINTSYS_GetTagKind  0x0201D658  thumb
 *   PRINTSYS_SkipTag  0x0201D688  thumb
 *   STRBUF_GetChars  0x02045A90  arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_SetSlotFromMsgB6 0x0201EF8C thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   WORDSET_SetSlotFromMsg36 0x0201EF40 thumb
 *   WORDSET_SetSlotFromMsgC7 0x0201F020 thumb
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_MAIN_IsOpposingPos  0x021B8CE8  thumb  ov093
 *   BTL_SICKCONT_MakeNone  0x021E8918  thumb  ov093
 *   gBtlFieldCountdown  0x021F63F4  data  a4
 *   BTL_FIELD_RemoveSlot  0x021EFA94  thumb  ov093
 *   BTL_FIELD_AddSlotHolder  0x021EFAD8  thumb  ov093
 *   BTL_FIELD_RemoveHolderFromSlots  0x021EFB34  thumb  ov093
 *   BTL_FIELD_IsMoveSealedBySlot  0x021EFC1C  thumb  ov093
 *   BTL_FIELD_TickSlots  0x021EFC78  thumb  ov093
 *   BTL_FIELD_IsSlotInUse  0x021EFCE4  thumb  ov093
 *   gBtlFieldFileName  0x021F3AF8  data  a4
 *   BTL_SICKCONT_GetPosition  0x021E8A98  thumb  ov093
 *   BTL_MSG_GetUiString  0x021EF694  thumb
 *   BTL_MSG_BuildBallStatusOpen  0x021EF71C  thumb
 *   BTL_MSG_BuildBallStatusRefresh  0x021EF7AC  thumb
 *   PRINTSYS_MeasureWidestLine  0x0201D304  thumb  arm9
 *   PRINTSYS_CopyLine  0x0201D37C  thumb  arm9
 *   PRINTSYS_InitCallerSuppliedArray  0x0201D33C  thumb  arm9
 */
/* The original callers declare these with other argument or return widths than the headers do. */
/* The original callers declare these with other argument or return widths than the headers do. */
#ifdef __MWERKS__
#define BTL_MSG_FormatArgs BTL_MSG_FormatArgsHeader
#endif
/* The original callers declare these with other argument or return widths than the headers do. */
#ifdef __MWERKS__
#define STRBUF_Create STRBUF_CreateHeader
#endif
#include "btlv_scu_types.h"
#include "../sdk_ioreg.h"
#include "btlv_core_types.h"
#include "../ov094/btlv_effvm_types.h"
#include "../arm9/fade.h"

#define BTLV_SCU_SE_PLATE_SLIDE 0x573
#define BTLV_SCU_SE_PLATE_FADE 0x54d
#define BTLV_SCU_SE_PLATE_MOSAIC 0x54e
#define BTLV_SCU_EFFECT_WITHDRAW (BTLV_EFFECT_MOVE_END + 59)
#define BTLV_SCU_EFFECT_SEND_OUT (BTLV_EFFECT_MOVE_END + 60)
struct PaletteFade;
struct BgTemplate;
struct PrintStream;
/* Task procedure of the task system: (task, work). */
typedef void (*TcblTaskFn)(void *task, void *work);


/* Work of the mon send-out task (BTLV_SCU_TaskMonSendOut). */
struct BtlvScuSlotTask {
    BtlvScuMonSlot *slot;
    u16 step;
    u8 *counter;
};

/* Work of the withdraw task (BTLV_SCU_TaskMonWithdraw), 0x10 bytes. */
struct BtlvScuWithdrawTask {
    BtlvScuMonSlot *slot;
    u16 step;
    u16 viewPos;
    u16 effectId;
    u8 *counter;
};

/* Work of the mon form change task (BTLV_SCU_TaskMonFormChange), 0x18 bytes. */
struct BtlvScuFormChangeTask {
    BtlvScu *scu;
    u8 slotIdx;
    u8 reserved5[3];
    u32 viewPos;
    u32 step;
    u32 flag;
    u8 *counter;
};

/* Work of the mon graphic swap task (BTLV_SCU_TaskMonGraphicSwap), 0x18 bytes. */
struct BtlvScuGraphicSwapTask {
    BtlvScu *scu;
    u32 viewPos;
    void *mon;
    u32 step;
    u8 reserved10;
    u8 flag;
    u8 reserved12[2];
    u8 *counter;
};

/* Work of the message window fade-out task (BTLV_SCU_TaskMsgWinFadeOut), 0xC bytes. */
struct BtlvScuFadeTask {
    BtlvScu *scu;
    int step;
    u8 *counter;
};

#include "btl_client.h"
#include "../arm9/gfl_use.h"
#include "../arm9/gfl_heap_wrap.h"
struct PrintQueue;
#include "../arm9/bg_sys.h"
#include "../arm9/arc_util.h"
struct BmpWin;
#include "../arm9/bmp_win.h"
struct Bmp;
#include "../arm9/bmp.h"
#include "../arm9/arc_tool.h"
struct Strbuf;
struct BtlMain;
#include "btl_main.h"
#include "../arm9/gx.h"
struct PokemonParam;
#include "btl_pokeparam.h"
struct BtlvPartyBallBarParam;
#include "../arm9/gf_font.h"
struct GfFont;
struct TextPrinter;
#include "../arm9/msg_speed.h"
#include "../arm9/key.h"
#include "../arm9/touchpanel.h"
struct BtlvEffScriptRequest;
struct TcblSystem;
struct TcblTask;
struct BtlSide;
#include "../arm9/g2.h"
#include "../arm9/mi_memory.h"
#include "../arm9/printsys.h"
#include "../arm9/tcbl.h"
#include "btl_msg.h"
#include "../arm9/strbuf.h"
#include "../arm9/palanm.h"
#include "../ov094/btlv_effect.h"
#ifdef __MWERKS__
#undef STRBUF_Create
extern struct Strbuf * STRBUF_Create(int capacity, int heapId);
#endif
#ifdef __MWERKS__
#undef BTL_MSG_FormatArgs
extern void BTL_MSG_FormatArgs(struct Strbuf *dest, u32 msgId, u32 argCount, ...);
#endif
struct BtlSideSlot;
void BTLV_SCU_PlaySeUnlessMainStep(struct BtlvCore *core, int a);
void BTLV_SCU_InitMessage(struct BtlvMessage *msg, int kind, int id);
void BTLV_SCU_AppendMessageArg(struct BtlvMessage *msg, u32 val);
void BTLV_SCU_SetMessageParam(struct BtlvMessage *msg, u8 param);
BtlvScu *BTLV_SCU_Create(struct BtlvCore *core, struct BtlContext *context, struct BtlMonTable *monTable, void *taskSys, void *fontMain, void *fontSub, u8 clientIndex, int heapId);
void BTLV_SCU_SetupDisplay(BtlvScu *scu);
u16 BTLV_SCU_LoadArcTiles(BtlvScu *scu, u32 arcId, u32 fileId, u32 layer);
void BTLV_SCU_Delete(BtlvScu *scu);
void BTLV_SCU_ReloadGraphics(const BtlvScu *scu);
u32 BTLV_SCU_IsFadeDone(void);
void BTLV_SCU_StartEntryScene(BtlvScu *scu, u32 quickMode);
int BTLV_SCU_RunProc(BtlvScu *scu);
void BTLV_SCU_StartBrightnessFade(int speed);
int BTLV_SCU_ProcQuickEntry(BtlvScu *scu, int *state, u8 *sides, u8 count);
int BTLV_SCU_ProcQuickEntrySingle(BtlvScu *scu, int *state);
int BTLV_SCU_ProcQuickEntryDouble(BtlvScu *scu, int *state);
int BTLV_SCU_ProcQuickEntryTriple(BtlvScu *scu, int *state);
int BTLV_SCU_ProcEntrySingleWild(int *state, BtlvScu *scu);
int BTLV_SCU_GetEntryMessageId(BtlvScu *scu);
int BTLV_SCU_ProcEntrySingleTrainer(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntrySingleLink(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryDoubleWild(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryDoubleTrainerLocal(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryDoubleTrainerComm(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryDoubleLinkLocal(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryDoubleLinkComm(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryTriple(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryTripleLink(int *state, BtlvScu *scu);
int BTLV_SCU_PhaseTrainerIntro(BtlvScu *scu, int *state);
int BTLV_SCU_PhaseTrainerIntroComm(BtlvScu *scu, int *state);
int BTLV_SCU_RunTrainerIntroOne(BtlvScu *scu, int *state, u16 trainerClient);
int BTLV_SCU_RunTrainerIntroTwo(BtlvScu *scu, int *state, u16 trainerClientA, u16 trainerClientB);
int BTLV_SCU_PhaseOpponentSendOutSingle(BtlvScu *scu, int *state);
int BTLV_SCU_PhaseOpponentSendOutDouble(BtlvScu *scu, int *state);
int BTLV_SCU_RunOpponentSendOutDoubleOneTrainer(BtlvScu *scu, int *state, u8 trainerClient);
int BTLV_SCU_RunOpponentSendOutDoubleTwoTrainers(BtlvScu *scu, int *state, u16 clientA, u16 clientB);
int BTLV_SCU_PhaseOpponentSendOutTriple(BtlvScu *scu, int *state);
int BTLV_SCU_PhaseOwnSendOutSingle(BtlvScu *scu, int *state);
int BTLV_SCU_PhaseOwnSendOutDouble(BtlvScu *scu, int *state);
int BTLV_SCU_RunOwnSendOutDoubleSolo(BtlvScu *scu, int *state, u8 ownClient);
int BTLV_SCU_RunOwnSendOutDoublePartner(BtlvScu *scu, int *state, u32 ownClient, u8 partnerClient);
int BTLV_SCU_PhaseOwnSendOutTriple(BtlvScu *scu, int *state);
u16 BTLV_SCU_GetSendOutMessageId(BtlvScu *scu, int monCount);
void BTLV_SCU_PrintMessageInstant(BtlvScu *scu, struct Strbuf *str);
void BTLV_SCU_StartMessage(BtlvScu *scu, struct Strbuf *str, u16 wait, PrintCallback callback);
u32 BTLV_SCU_ConsumeMessageEnded(BtlvScu *scu);
int BTLV_SCU_UpdateMessage(BtlvScu *scu);
void BTLV_SCU_StartWazaEffect(BtlvScu *scu, int attackerPos, int defenderPos, u32 wazaId, u32 effectSeq, int turnCount, u8 continueCount);
int BTLV_SCU_ProcWazaEffect(int *state, BtlvScu *scu);
int BTLV_SCU_RunWazaProc(BtlvScu *scu);
void BTLV_SCU_StartMonDamageAnim(BtlvScu *scu, u8 slotIdx, u16 motionId, int instant);
int BTLV_SCU_IsMonDamageAnimDone(BtlvScu *scu);
void BTLV_SCU_StartMonMotion(BtlvScu *scu, u8 slotIdx, u32 motionId);
int BTLV_SCU_IsMonMotionDone(BtlvScu *scu);
void BTLV_SCU_StartMonExit(BtlvScu *scu, int slotIdx, u32 flag);
int BTLV_SCU_IsMonExitDone(BtlvScu *scu);
void BTLV_SCU_LoadAndShowMon(BtlvScu *scu, u8 slotIdx);
int BTLV_SCU_IsMonLoadDone(BtlvScu *scu);
void BTLV_SCU_StartMonWithdraw(BtlvScu *scu, u16 viewPos, u16 effectId, int instant);
u32 BTLV_SCU_IsMonWithdrawDone(BtlvScu *scu);
void BTLV_SCU_TaskMonWithdraw(struct TcblTask *task, void *workPtr);
void BTLV_SCU_StartMonSendOut(BtlvScu *scu, u8 slotIdx, int clientId, u8 partyIdx, int quiet);
int BTLV_SCU_IsMonSendOutDone(BtlvScu *scu);
void BTLV_SCU_TaskMonSendOut(struct TcblTask *task, void *workPtr);
void BTLV_SCU_StartHpGaugeUpdate(BtlvScu *scu, u8 slotIdx, int instant);
int BTLV_SCU_IsHpGaugeIdle(BtlvScu *scu);
void BTLV_SCU_HideMonPair(BtlvScu *scu, int slotA, int slotB);
int BTLV_SCU_ShowMonPair(BtlvScu *scu, int slotA, int slotB);
void BTLV_SCU_HideMon(BtlvScu *scu, int slotIdx);
int BTLV_SCU_ShowMon(BtlvScu *scu, int slotIdx);
struct BtlvScu;
void BTLV_SCU_StartPosCueEffect(struct BtlvScu *unused, int viewPos);
int BTLV_SCU_IsPosCueEffectDone(struct BtlvScu *unused, int viewPos);
void BTLV_SCU_StartMonFormChange(BtlvScu *scu, u8 slotIdx, u32 flag);
u32 BTLV_SCU_IsMonFormChangeDone(BtlvScu *scu);
void BTLV_SCU_TaskMonFormChange(struct TcblTask *task, void *workPtr);
void BTLV_SCU_StartMonGraphicSwapFrom(BtlvScu *scu, u32 destPos, u32 srcPos, u32 flag);
void BTLV_SCU_StartMonGraphicSwap(BtlvScu *scu, u32 viewPos, u32 flag);
u32 BTLV_SCU_IsMonGraphicSwapDone(BtlvScu *scu);
void BTLV_SCU_TaskMonGraphicSwap(struct TcblTask *task, void *workPtr);
void BTLV_SCU_InitMsgWinFade(BtlvScuWinSlide *fade, struct BmpWin *win);
void BTLV_SCU_StartMsgWinFadeOut(BtlvScuWinSlide *fade);
void BTLV_SCU_StartMsgWinFadeIn(BtlvScuWinSlide *fade, int keepText);
int BTLV_SCU_UpdateMsgWinFade(BtlvScuWinSlide *fade);
void BTLV_SCU_StartMsgWinFadeOutTask(BtlvScu *scu);
u32 BTLV_SCU_IsMsgWinFadeOutTaskDone(BtlvScu *scu);
void BTLV_SCU_TaskMsgWinFadeOut(struct TcblTask *task, void *workPtr);
void BTLV_SCU_InitMonSlots(BtlvScu *scu);
void BTLV_SCU_ResetMonSlots(BtlvScu *scu);
void BTLV_SCU_InitMonSlot(BtlvScuMonSlot *slot, BtlvScu *owner, u8 slotIdx);
void BTLV_SCU_ResetMonSlot(BtlvScuMonSlot *slot);
void BTLV_SCU_HideMonSlot(BtlvScuMonSlot *slot);
void BTLV_SCU_ShowMonSlot(BtlvScuMonSlot *slot);
BtlvScuPlateSide BTLV_SCU_GetNamePlateSide(struct BtlContext *ctx, u32 viewPos);
void BTLV_SCU_StartNamePlate(BtlvScu *scu, u8 viewPos, int closeLater);
int BTLV_SCU_ProcNamePlateAt(BtlvScu *scu, u32 viewPos);
void BTLV_SCU_HideNamePlateAt(BtlvScu *scu, u32 viewPos);
int BTLV_SCU_IsNamePlateHiddenAt(BtlvScu *scu, u32 viewPos);
void BTLV_SCU_RefreshNamePlateAt(BtlvScu *scu, u8 viewPos);
int BTLV_SCU_ProcNamePlateMosaicAt(BtlvScu *scu, u32 viewPos);
void BTLV_SCU_InitNamePlates(BtlvScu *scu, u32 tile);
void BTLV_SCU_FreeNamePlates(BtlvScu *scu);
void BTLV_SCU_PrepareNamePlate(BtlvScuNamePlate *plate, u8 viewPos, int closeLater);
int BTLV_SCU_ProcNamePlate(BtlvScuNamePlate *plate);
void BTLV_SCU_DrawNamePlate(BtlvScuNamePlate *plate);
void BTLV_SCU_HideNamePlate(BtlvScuNamePlate *plate);
int BTLV_SCU_IsNamePlateHidden(BtlvScuNamePlate *plate);
void BTLV_SCU_RefreshNamePlate(BtlvScuNamePlate *plate, u8 viewPos);
int BTLV_SCU_ProcNamePlateMosaic(BtlvScuNamePlate *plate);
void BTLV_SCU_GetBallStates(BtlvScu *scu, u32 *outStates, u32 clientA, u32 clientB, u32 sideFlag);
void BTLV_SCU_PrintWaitMessage(BtlvScu *scu);
int BTLV_SCU_UpdateWaitMessage(BtlvScu *scu);
void BTLV_SCU_NoOp(char *unused);
void BTLV_SCU_StartFadeIn(BtlvScu *scu);
void BTLV_SCU_ClearWaitWindow(BtlvScu *scu);
int BTLV_SCU_GetWaitState(BtlvScu *scu);
void BTLV_SCU_StartBallWindowOpen(BtlvScu *scu, void **partySource, BtlvBallStates *states);
int BTLV_SCU_UpdateBallWindowOpen(BtlvScu *scu);
void BTLV_SCU_StartBallWindowRefresh(BtlvScu *scu);
int BTLV_SCU_UpdateBallWindowRefresh(BtlvScu *scu);
void BTLV_SCU_StartBallWindowClose(BtlvScu *scu);
int BTLV_SCU_UpdateBallWindowClose(BtlvScu *scu);
int BTLV_SCU_StepBallWindowOpen(int *state, BtlvScu *scu);
int BTLV_SCU_StepBallWindowRefresh(int *state, BtlvScu *scu);
int BTLV_SCU_StepBallWindowClose(int *state, BtlvScu *scu);
extern u8 gBtlvScuFileName[];
extern const struct BgTemplate gBtlvScuBgTemplateMsg, gBtlvScuBgTemplateName, gBtlvScuBgTemplateBack;
extern u8 gBtlvScuQuickSidesSingle[];
extern u8 gBtlvScuQuickSidesDouble[];
extern u8 gBtlvScuQuickSidesTriple[];
extern const BtlvScuPhaseProc gBtlvScuEntryTriplePhases[];



/* Master brightness register of the main engine. */
#define REG_MASTER_BRIGHT_MAIN ((volatile u16 *)REG_MASTER_BRIGHT_ADDR)


extern int (*const gBtlvScuSingleLinkPhases[][2])(BtlvScu *, int *);


extern int (*const gBtlvScuDoubleTrainerLocalPhases[])(BtlvScu *, int *);


extern int (*const gBtlvScuDoubleTrainerCommPhases[])(BtlvScu *, int *);


extern int (*const gBtlvScuDoubleLinkLocalPhases[][2])(BtlvScu *, int *);


extern int (*const gBtlvScuDoubleLinkCommPhases[])(BtlvScu *, int *);



void BTLV_SCU_PlaySeUnlessMainStep(struct BtlvCore *core, int seNo)
{
    if (BTL_CLIENT_IsMainStepActive(core->client) == 0)
        GFL_USE_PlaySeDefaultVolume(seNo);
}



void BTLV_SCU_InitMessage(struct BtlvMessage *msg, int kind, int id)
{
    u32 i;
    for (i = 0; i < 8; i++)
        msg->args[i] = 0;
    msg->argCount = 0;
    msg->msgId = id;
    msg->kind = kind;
    msg->param = 0x50;
}



void BTLV_SCU_AppendMessageArg(struct BtlvMessage *msg, u32 val)
{
    u32 n = msg->argCount;
    if (n < 8) {
        msg->argCount = n + 1;
        msg->args[n] = val;
    }
}




/* 021EAF78  strb r1,[r0,#2] */
/*
 * Stores the second argument (a u8) into the param field at #2.
 */
void BTLV_SCU_SetMessageParam(struct BtlvMessage *msg, u8 param) { msg->param = param; }




BtlvScu *BTLV_SCU_Create(struct BtlvCore *core, struct BtlContext *context, struct BtlMonTable *monTable, void *taskSys, void *fontMain, void *fontSub, u8 clientIndex, int heapId)
{
    BtlvScu *scu;
    scu = GFL_HEAP_Alloc(heapId, sizeof(*scu), 1, (const char *)gBtlvScuFileName, 0x151);
    scu->core = core;
    scu->context = context;
    scu->monTable = monTable;
    scu->heapId = heapId;
    scu->clientIndex = clientIndex;
    scu->fontMain = fontMain;
    scu->fontSub = fontSub;
    scu->quickMode = 0;
    scu->msgStream = 0;
    scu->taskSys = taskSys;
    scu->textBuf = STRBUF_Create(0x400, heapId);
    scu->wordBuf0 = STRBUF_Create(0x180, heapId);
    scu->wordBuf1 = STRBUF_Create(0x180, heapId);
    scu->busyFlag = 0;
    scu->nameGfxFile = 0;
    scu->printer = (struct PrintSys *)PRINTSYS_QUE_Create(scu->heapId);
    scu->msgWinCopy = scu->msgWin;
    scu->lineIndex = 0;
    return scu;
}




void BTLV_SCU_SetupDisplay(BtlvScu *scu)
{
    u16 zero;
    u32 frameTile;
    BG_SYS_InitBgLayer(1, &gBtlvScuBgTemplateMsg, 0);
    BG_SYS_InitBgLayer(2, &gBtlvScuBgTemplateName, 0);
    BG_SYS_InitBgLayer(3, &gBtlvScuBgTemplateBack, 0);
    PALANM_LoadArcPaletteToSlotAt(BTLV_EFFECT_GetPalanm(), 0xb, 0x5a, scu->heapId, 0, 0x20, 0, 0);
    PALANM_LoadArcPaletteToSlotAt(BTLV_EFFECT_GetPalanm(), 0xb, 0xd6, scu->heapId, 0, 0x60, 0x10, 0x10);
    zero = 0;
    PALANM_CopyToSlot(BTLV_EFFECT_GetPalanm(), &zero, 0, 0, 2);
    BG_SYS_SetTileEntry(1, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_Init(1, 0, 1, 0);
    frameTile = BTLV_SCU_LoadArcTiles(scu, 0xb, 0x59, 1);
    scu->msgTile = BTLV_SCU_LoadArcTiles(scu, 0xb, 0xd5, 3);
    ARC_UTIL_UploadBgPaletteFromArchive(0xb, 0xd7, 2, 0, 0, 0, scu->heapId);
    ARC_UTIL_UploadBgPaletteFromArchive(0xb, 0xd8, 3, 0, 0, 0, scu->heapId);
    scu->msgWin = BMP_WIN_Create(1, 1, 0x13, 0x1e, 4, 0, 0);
    scu->msgWinChars = (struct CharBuf *)BMP_WIN_GetBmp(scu->msgWin);
    BMP_WIN_MakeScreen(scu->msgWin);
    BMP_WIN_DrawFrame(scu->msgWin, frameTile, 0);
    BMP_Clear((struct Bmp *)scu->msgWinChars, 0xc);
    BMP_WIN_TransferChars(scu->msgWin);
    scu->nameTile = BTLV_SCU_LoadArcTiles(scu, 0xb, 0xdd, 3);
    scu->nameWin = BMP_WIN_Create(3, 0x15, 0x25, 0xa, 0xc, 3, 0);
    scu->nameWinChars = (struct CharBuf *)BMP_WIN_GetBmp(scu->nameWin);
    BTLV_SCU_InitMsgWinFade(&scu->slide, scu->msgWin);
    BTLV_SCU_InitMonSlots(scu);
    BTLV_SCU_InitNamePlates(scu, scu->msgTile);
    BG_SYS_PushTile(1);
    BG_SYS_PushTile(2);
    BG_SYS_PushTile(3);
    BG_SYS_SetPlaneVisible(0, 1);
    BG_SYS_SetPlaneVisible(1, 1);
    BG_SYS_SetPlaneVisible(2, 1);
    BG_SYS_SetPlaneVisible(3, 1);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
}




u16 BTLV_SCU_LoadArcTiles(BtlvScu *scu, u32 arcId, u32 fileId, u32 layer)
{
    void *handle = ARC_TOOL_CreateHandle(arcId, (u16)((scu->heapId & 0x7fff) | 0x8000));
    u32 tileOffset = ARC_UTIL_RegisterObjCharFromHandle(handle, fileId, layer, 0, 0, (u16)((scu->heapId & 0x7fff) | 0x8000));

    ARC_TOOL_DeleteHandle(handle);
    return (u16)tileOffset;
}




void BTLV_SCU_Delete(BtlvScu *scu)
{
    BTLV_SCU_FreeNamePlates(scu);
    BTLV_SCU_ResetMonSlots(scu);
    if (scu->nameWin != 0) {
        BMP_WIN_Delete(scu->nameWin);
        scu->nameWin = 0;
    }
    if (scu->msgWin != 0) {
        BMP_WIN_Delete(scu->msgWin);
        scu->msgWin = 0;
    }
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(3);
    if (scu->printer != 0) {
        PRINTSYS_QUE_Delete((struct PrintQueue *)scu->printer);
        scu->printer = 0;
    }
    if (scu->wordBuf1 != 0) {
        STRBUF_Delete((struct Strbuf *)scu->wordBuf1);
        scu->wordBuf1 = 0;
    }
    if (scu->wordBuf0 != 0) {
        STRBUF_Delete((struct Strbuf *)scu->wordBuf0);
        scu->wordBuf0 = 0;
    }
    STRBUF_Delete((struct Strbuf *)scu->textBuf);
    GFL_HEAP_Free(scu);
}




/*
 * Lever: the parameter is const BtlvScu *; without const the ldrh of the heap
 * halfword schedules after the second zero stack store (DIFF, 19 lines).
 */
void BTLV_SCU_ReloadGraphics(const BtlvScu *scu)
{
    void *handle = ARC_TOOL_CreateHandle(0xb, (u16)((scu->heapId & 0x7fff) | 0x8000));

    ARC_UTIL_UploadBgCharFromHandle(handle, 0xd5, 3, scu->msgTile, 0, 0, scu->heapId);
    ARC_UTIL_UploadBgCharFromHandle(handle, 0xdd, 3, scu->nameTile, 0, 0, scu->heapId);
    ARC_TOOL_DeleteHandle(handle);
    BG_SYS_ClearSlot(3);
    ARC_UTIL_UploadBgPaletteFromArchive(0xb, 0xd8, 3, 0, 0, 0, scu->heapId);
}




/*
 * Calls the ARM9 predicate FADE_IsActive and returns its negation.  Filed here because it is the only witness available for BTLV_SCU_GetWaitState's pool word: no branch anywhere in the image targets 0x021EB318, so `label` and `sole-ref/code` both refuse it.  18 bytes against a 20-byte listing extent (the last two are alignment), so the entry is EXACT*.
 */
u32 BTLV_SCU_IsFadeDone(void) { if (FADE_IsActive() == 0) return 1; return 0; }



static inline void BTLV_SCU_SetProc(BtlvScu *scu, BtlvScuProc proc)
{
    scu->preProc = 0;
    scu->mainProc = proc;
    scu->procScu = scu;
    scu->procState = 0;
}



void BTLV_SCU_StartEntryScene(BtlvScu *scu, u32 quickMode)
{
    int battleType = BTL_MAIN_GetCompetitor((struct BtlMain *)scu->context);
    scu->phase = 0;
    scu->quickMode = quickMode;
    switch (BTL_MAIN_GetRule((struct BtlMain *)scu->context)) {
    case 0:
        switch (battleType) {
        default: case 0: case 4: BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntrySingleWild); return;
        case 1: case 2: BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntrySingleTrainer); return;
        case 3: BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntrySingleLink); return;
        }
    case 1:
        switch (battleType) {
        case 0: BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntryDoubleWild); return;
        case 3:
            if (!BTL_MAIN_IsMultiMode((struct BtlMain *)scu->context)) BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntryDoubleLinkLocal);
            else BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntryDoubleLinkComm);
            return;
        case 1: case 2:
            if (!BTL_MAIN_IsMultiMode((struct BtlMain *)scu->context)) BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntryDoubleTrainerLocal);
            else BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntryDoubleTrainerComm);
            return;
        }
        break;
    case 2:
        if (battleType != 3) BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntryTriple);
        else BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntryTripleLink);
        return;
    case 3:
        if (battleType != 3) BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntryTriple);
        else BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntryTripleLink);
        return;
    }
}




int BTLV_SCU_RunProc(BtlvScu *scu)
{
    if (scu->preProc != 0) {
        if (scu->preProc(&scu->procState, scu->procScu) != 0) {
            scu->preProc = 0;
            scu->procState = 0;
        }
        return 0;
    }
    if (scu->mainProc != 0) {
        if (scu->mainProc(&scu->procState, scu->procScu) != 0) {
            scu->mainProc = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}



void BTLV_SCU_StartBrightnessFade(int speed)
{
    if (GXx_GetMasterBrightness_(REG_MASTER_BRIGHT_MAIN) <= 0)
        FADE_Start(3, 0x10, 0, speed);
    else
        FADE_Start(0xc, 0x10, 0, speed);
}



int BTLV_SCU_ProcQuickEntry(BtlvScu *scu, int *state, u8 *sides, u8 count)
{
    switch (*state) {
    case 0: {
        u32 side;
        u32 i;
        u8 monIdx;
        for (i = 0; i < count; i++) {
            side = sides[i];
            monIdx = BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, side);
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon((struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, monIdx)), side);
            BTLV_SCU_ShowMonSlot(&scu->monSlots[monIdx]);
        }
        *state = *state + 1;
        break;
    }
    case 1:
        if (scu->quickMode != 0)
            return 1;
        BTLV_SCU_StartBrightnessFade(-3);
        *state = *state + 1;
        break;
    case 2:
        if (BTLV_EFFECT_IsBusy() == 0)
            return 1;
        break;
    }
    return 0;
}



int BTLV_SCU_ProcQuickEntrySingle(BtlvScu *scu, int *state)
{
    return BTLV_SCU_ProcQuickEntry(scu, state, gBtlvScuQuickSidesSingle, 2);
}



int BTLV_SCU_ProcQuickEntryDouble(BtlvScu *scu, int *state)
{
    return BTLV_SCU_ProcQuickEntry(scu, state, gBtlvScuQuickSidesDouble, 4);
}



int BTLV_SCU_ProcQuickEntryTriple(BtlvScu *scu, int *state)
{
    return BTLV_SCU_ProcQuickEntry(scu, state, gBtlvScuQuickSidesTriple, 6);
}



int BTLV_SCU_ProcEntrySingleWild(int *state, BtlvScu *scu)
{
    BtlvScuIntroState *intro = &scu->intro;
    if (scu->quickMode) return BTLV_SCU_ProcQuickEntrySingle(scu, state);
    switch (*state) {
    case 0:
        intro->single.side = 1;
        intro->single.monIdx = BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, intro->single.side);
        intro->single.mon = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, intro->single.monIdx);
        intro->single.monId = BTL_POKEPARAM_GetPokeId(intro->single.mon);
        BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
        (*state)++;
        break;
    case 1:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide)) {
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(intro->single.mon), intro->single.side);
            BTLV_EFFECT_StartEffectOnPoke(intro->single.side, BTLV_EFFECT_MOVE_END);
            BTLV_SCU_StartBrightnessFade(2);
            (*state)++;
        }
        break;
    case 2:
        if (!BTLV_EFFECT_IsBusy()) {
            BTL_MSG_FormatArgs(scu->textBuf, BTLV_SCU_GetEntryMessageId(scu), 1, intro->single.monId);
            BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_SCU_ShowMonSlot(&scu->monSlots[intro->single.monIdx]);
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 4:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide)) {
            if (BTL_MAIN_GetCompetitor((struct BtlMain *)scu->context) == 4) BTLV_EFFECT_StartEffect(BTLV_EFFECT_MOVE_END + 11);
            else BTLV_EFFECT_StartEffect(BTLV_EFFECT_MOVE_END + 1);
            (*state)++;
        }
        break;
    case 5:
        if (!BTLV_EFFECT_IsBusy()) {
            intro->single.side = 0;
            intro->single.monIdx = BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, intro->single.side);
            intro->single.mon = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, intro->single.monIdx);
            intro->single.monId = BTL_POKEPARAM_GetPokeId(intro->single.mon);
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(intro->single.mon), intro->single.side);
            BTLV_EFFECT_StartEffect(BTLV_EFFECT_MOVE_END + 3);
            BTL_MSG_FormatArgs(scu->textBuf, 11, 1, intro->single.monId);
            BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 6:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 7:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide)) (*state)++;
        break;
    case 8:
        if (!BTLV_EFFECT_IsBusy()) {
            BTLV_SCU_ShowMonSlot(&scu->monSlots[intro->single.monIdx]);
            return 1;
        }
        break;
    }
    return 0;
}




int BTLV_SCU_GetEntryMessageId(BtlvScu *scu)
{
    if (BTL_MAIN_CheckSetupStatusFlag((struct BtlMain *)scu->context, 4) != 0) {
        return 6;
    }
    if (BTL_MAIN_CheckSetupStatusFlag((struct BtlMain *)scu->context, 8) != 0) {
        return 3;
    }
    if (BTL_MAIN_CheckSetupStatusFlag((struct BtlMain *)scu->context, 0x80) != 0) {
        return 4;
    }
    if (BTL_MAIN_CheckSetupStatusFlag((struct BtlMain *)scu->context, 0x10) != 0) {
        return 5;
    }
    return 1;
}



int BTLV_SCU_ProcEntrySingleTrainer(int *state, BtlvScu *scu)
{
    BtlvScuIntroState *intro = &scu->intro;
    u32 introArgs[7];
    u32 sendOutArgs[7];
    u32 side, trainerIdx;
    if (scu->quickMode) return BTLV_SCU_ProcQuickEntrySingle(scu, state);
    switch (*state) {
    case 0:
        side = BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, 1);
        trainerIdx = BTL_MAIN_GetSlotClientIdThunk((struct BtlMain *)scu->context, side);
        BTLV_EFFECT_AddPokeSprite(BTL_MAIN_GetTrainerType((struct BtlMain *)scu->context, trainerIdx), 9, 0, 0, 0);
        intro->single.side = 1;
        intro->single.trainerIdx = trainerIdx;
        intro->single.monIdx = side;
        intro->single.mon = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, intro->single.monIdx);
        intro->single.monId = BTL_POKEPARAM_GetPokeId(intro->single.mon);
        BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
        (*state)++;
        break;
    case 1:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide)) {
            BTLV_EFFECT_StartEffectOnPoke(intro->single.side, BTLV_EFFECT_MOVE_END + 6);
            BTLV_SCU_StartBrightnessFade(2);
            (*state)++;
        }
        break;
    case 2:
        if (!BTLV_EFFECT_IsBusy()) {
            BTLV_SCU_GetBallStates(scu, introArgs, intro->single.trainerIdx, 4, 1);
            BTLV_EFFECT_CreatePartyBallBar((struct BtlvPartyBallBarParam *)introArgs);
            BTL_MSG_FormatArgs(scu->textBuf, 7, 1, intro->single.trainerIdx);
            BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_EFFECT_StartEffectOnPoke(intro->single.side, BTLV_EFFECT_MOVE_END + 7);
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 4:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide) && !BTLV_EFFECT_IsBusy()) {
            BTL_MSG_FormatArgs(scu->textBuf, 14, 2, 1, intro->single.monId);
            BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 5:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(intro->single.mon), intro->single.side);
            BTLV_EFFECT_StartEffectOnPoke(intro->single.side, BTLV_EFFECT_MOVE_END + 8);
            BTLV_EFFECT_DeletePartyBallBar(1);
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 6:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide) && !BTLV_EFFECT_IsBusy()) {
            BTLV_SCU_GetBallStates(scu, sendOutArgs, BTL_MAIN_GetOwnClientId((struct BtlMain *)scu->context), 4, 0);
            BTLV_EFFECT_CreatePartyBallBar((struct BtlvPartyBallBarParam *)sendOutArgs);
            (*state)++;
        }
        break;
    case 7:
        BTLV_SCU_ShowMonSlot(&scu->monSlots[intro->single.monIdx]);
        BTLV_EFFECT_StartEffect(BTLV_EFFECT_MOVE_END + 1);
        (*state)++;
        break;
    case 8:
        if (!BTLV_EFFECT_IsBusy() && !BTLV_EFFECT_IsPartyBallBarActive(0)) {
            intro->single.side = 0;
            intro->single.monIdx = BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, intro->single.side);
            intro->single.mon = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, intro->single.monIdx);
            intro->single.monId = BTL_POKEPARAM_GetPokeId(intro->single.mon);
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(intro->single.mon), intro->single.side);
            BTLV_EFFECT_StartEffect(BTLV_EFFECT_MOVE_END + 3);
            BTL_MSG_FormatArgs(scu->textBuf, 11, 1, intro->single.monId);
            BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 9:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_EFFECT_DeletePartyBallBar(0);
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 10:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide)) (*state)++;
        break;
    case 11:
        if (!BTLV_EFFECT_IsBusy()) {
            BTLV_SCU_ShowMonSlot(&scu->monSlots[intro->single.monIdx]);
            return 1;
        }
        break;
    }
    return 0;
}





int BTLV_SCU_ProcEntrySingleLink(int *state, BtlvScu *scu)
{
    if (scu->quickMode != 0)
        return BTLV_SCU_ProcQuickEntrySingle(scu, state);
    if (scu->phase < 3) {
        if (gBtlvScuSingleLinkPhases[scu->phase][BTL_MAIN_GetOwnClientId((struct BtlMain *)scu->context)](scu, state) != 0) {
            scu->phase = scu->phase + 1;
            *state = 0;
        }
        return 0;
    }
    return 1;
}



/*
 * match-note: The loop stores and reads each call result through the same
 * pointer-typed lvalue. Integer-store/pointer-reload gave 628 bytes; a named
 * integer temporary gave 620 and lost the index spill; pointer lvalues gave
 * EXACT 624 bytes. Evidence: B10/BB20-r1.log through BB20-r3.log.
 */
int BTLV_SCU_ProcEntryDoubleWild(int *state, BtlvScu *scu)
{
    BtlvScuIntroState *intro = &scu->intro;
    u32 side;
    unsigned i;
    if (scu->quickMode) return BTLV_SCU_ProcQuickEntryDouble(scu, state);
    switch (*state) {
    case 0:
        side = BTL_MAIN_GetClientTrainerIndex((struct BtlMain *)scu->context, scu->clientIndex, 0);
        intro->dbl.monIdx[0] = BTL_MAIN_GetEnemyLanePosFromWork((struct BtlMain *)scu->context, side, 0);
        intro->dbl.mon[0] = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, intro->dbl.monIdx[0]);
        intro->dbl.monId[0] = BTL_POKEPARAM_GetPokeId(intro->dbl.mon[0]);
        intro->dbl.monIdx[1] = BTL_MAIN_GetEnemyLanePosFromWork((struct BtlMain *)scu->context, side, 1);
        intro->dbl.mon[1] = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, intro->dbl.monIdx[1]);
        intro->dbl.monId[1] = BTL_POKEPARAM_GetPokeId(intro->dbl.mon[1]);
        BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
        (*state)++;
        break;
    case 1:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide)) {
            side = BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)scu->context, intro->dbl.monIdx[0]);
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(intro->dbl.mon[0]), side);
            (*state)++;
        }
        break;
    case 2:
        if (!BTLV_EFFECT_IsBusy()) {
            side = BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)scu->context, intro->dbl.monIdx[1]);
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(intro->dbl.mon[1]), side);
            BTLV_EFFECT_StartEffectOnPoke(side, BTLV_EFFECT_MOVE_END);
            BTLV_SCU_StartBrightnessFade(2);
            (*state)++;
        }
        break;
    case 3:
        if (!BTLV_EFFECT_IsBusy()) {
            BTL_MSG_FormatArgs(scu->textBuf, 2, 2, intro->dbl.monId[0], intro->dbl.monId[1]);
            BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 4:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_SCU_ShowMonSlot(&scu->monSlots[intro->dbl.monIdx[0]]);
            BTLV_SCU_ShowMonSlot(&scu->monSlots[intro->dbl.monIdx[1]]);
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 5:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide)) {
            BTLV_EFFECT_StartEffect(BTLV_EFFECT_MOVE_END + 1);
            (*state)++;
        }
        break;
    case 6:
        if (!BTLV_EFFECT_IsBusy()) {
            intro->dbl.side[0] = 2;
            intro->dbl.side[1] = 4;
            intro->dbl.localSide = BTL_MAIN_GetOwnClientId((struct BtlMain *)scu->context);
            for (i = 0; i < 2; i++) {
                intro->dbl.monIdx[i] = BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, intro->dbl.side[i]);
                intro->dbl.mon[i] = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, intro->dbl.monIdx[i]);
                if (intro->dbl.mon[i]) intro->dbl.monId[i] = BTL_POKEPARAM_GetPokeId(intro->dbl.mon[i]);
            }
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(intro->dbl.mon[0]), intro->dbl.side[0]);
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(intro->dbl.mon[1]), intro->dbl.side[1]);
            BTLV_EFFECT_StartEffect(BTLV_EFFECT_MOVE_END + 3);
            BTL_MSG_FormatArgs(scu->textBuf, 12, 2, intro->dbl.monId[0], intro->dbl.monId[1]);
            BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 7:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 8:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide) && !BTLV_EFFECT_IsBusy()) {
            BTLV_SCU_ShowMonSlot(&scu->monSlots[intro->dbl.monIdx[0]]);
            BTLV_SCU_ShowMonSlot(&scu->monSlots[intro->dbl.monIdx[1]]);
            (*state)++;
        }
        break;
    case 9:
        if (!BTLV_EFFECT_IsBusy()) return 1;
        break;
    }
    return 0;
}





int BTLV_SCU_ProcEntryDoubleTrainerLocal(int *state, BtlvScu *scu)
{
    if (scu->quickMode != 0)
        return BTLV_SCU_ProcQuickEntryDouble(scu, state);
    if (scu->phase < 3) {
        if (gBtlvScuDoubleTrainerLocalPhases[scu->phase](scu, state) != 0) {
            scu->phase = scu->phase + 1;
            *state = 0;
        }
        return 0;
    }
    return 1;
}





int BTLV_SCU_ProcEntryDoubleTrainerComm(int *state, BtlvScu *scu)
{
    if (scu->quickMode != 0)
        return BTLV_SCU_ProcQuickEntryDouble(scu, state);
    if (scu->phase < 3) {
        if (gBtlvScuDoubleTrainerCommPhases[scu->phase](scu, state) != 0) {
            scu->phase = scu->phase + 1;
            *state = 0;
        }
        return 0;
    }
    return 1;
}





int BTLV_SCU_ProcEntryDoubleLinkLocal(int *state, BtlvScu *scu)
{
    if (scu->quickMode != 0)
        return BTLV_SCU_ProcQuickEntryDouble(scu, state);
    if (scu->phase < 3) {
        if (gBtlvScuDoubleLinkLocalPhases[scu->phase][BTL_MAIN_GetOwnClientId((struct BtlMain *)scu->context)](scu, state) != 0) {
            scu->phase = scu->phase + 1;
            *state = 0;
        }
        return 0;
    }
    return 1;
}





int BTLV_SCU_ProcEntryDoubleLinkComm(int *state, BtlvScu *scu)
{
    if (scu->quickMode != 0)
        return BTLV_SCU_ProcQuickEntryDouble(scu, state);
    if (scu->phase < 3) {
        if (gBtlvScuDoubleLinkCommPhases[scu->phase](scu, state) != 0) {
            scu->phase = scu->phase + 1;
            *state = 0;
        }
        return 0;
    }
    return 1;
}




int BTLV_SCU_ProcEntryTriple(int *state, BtlvScu *scu)
{
    if (scu->quickMode != 0)
        return BTLV_SCU_ProcQuickEntryTriple(scu, state);
    if (scu->phase < 3) {
        if (gBtlvScuEntryTriplePhases[scu->phase](scu, state) != 0) {
            scu->phase = scu->phase + 1;
            *state = 0;
        }
        return 0;
    }
    return 1;
}



/* Phase table of the triple link entry, indexed [phase][own client id]. */
extern int (*const gBtlvScuEntryTripleLinkPhases[][2])(BtlvScu *, int *);



/*
 * Entry scene of a triple or rotation battle against a link opponent. Each
 * phase function returns nonzero when finished; the phase counter then
 * advances and the step state resets.
 */
int BTLV_SCU_ProcEntryTripleLink(int *state, BtlvScu *scu)
{
    if (scu->quickMode != 0)
        return BTLV_SCU_ProcQuickEntryTriple(scu, state);
    if (scu->phase < 3) {
        if (gBtlvScuEntryTripleLinkPhases[scu->phase][BTL_MAIN_GetOwnClientId((struct BtlMain *)scu->context)](scu, state) != 0) {
            scu->phase = scu->phase + 1;
            *state = 0;
        }
        return 0;
    }
    return 1;
}



/* Trainer intro against the first opponent client (single trainer). */
int BTLV_SCU_PhaseTrainerIntro(BtlvScu *scu, int *state)
{
    return BTLV_SCU_RunTrainerIntroOne(scu, state, BTL_MAIN_GetOwnOpponentClient((struct BtlMain *)scu->context, 0));
}



/* Trainer intro against two opponent clients, or one when both are the same client. */
int BTLV_SCU_PhaseTrainerIntroComm(BtlvScu *scu, int *state)
{
    u8 clientA = BTL_MAIN_GetOwnOpponentClient((struct BtlMain *)scu->context, 0);
    u8 clientB = BTL_MAIN_GetOwnOpponentClient((struct BtlMain *)scu->context, 1);
    if (clientA != clientB)
        return BTLV_SCU_RunTrainerIntroTwo(scu, state, clientA, clientB);
    return BTLV_SCU_RunTrainerIntroOne(scu, state, clientA);
}



int BTLV_SCU_RunTrainerIntroOne(BtlvScu *scu, int *state, u16 trainerClient)
{
    BtlvScuIntroState *st = &scu->intro;
    int msgId;
    u32 ballStates[7];
    switch (*state) {
    case 0:
        st->trainers.side[1] = 9;
        BTLV_EFFECT_AddPokeSprite(BTL_MAIN_GetTrainerType((struct BtlMain *)scu->context, trainerClient), st->trainers.side[1], 0, 0, 0);
        BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
        (*state)++;
        break;
    case 1:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide)) {
            BTLV_EFFECT_StartEffectOnPoke(st->trainers.side[1], BTLV_EFFECT_MOVE_END + 6);
            BTLV_SCU_StartBrightnessFade(2);
            (*state)++;
        }
        break;
    case 2:
        if (!BTLV_EFFECT_IsBusy()) {
            if (BTL_MAIN_GetCompetitor((struct BtlMain *)scu->context) != 3) msgId = 7;
            else msgId = 8;
            BTLV_SCU_GetBallStates(scu, ballStates, trainerClient, 4, 1);
            BTLV_EFFECT_CreatePartyBallBar((struct BtlvPartyBallBarParam *)ballStates);
            BTL_MSG_FormatArgs(scu->textBuf, (u16)msgId, 1, trainerClient);
            BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_EFFECT_StartEffectOnPoke(st->trainers.side[1], BTLV_EFFECT_MOVE_END + 7);
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 4:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide) && !BTLV_EFFECT_IsBusy()) return 1;
        break;
    }
    return 0;
}



int BTLV_SCU_RunTrainerIntroTwo(BtlvScu *scu, int *state, u16 trainerClientA, u16 trainerClientB)
{
    BtlvScuIntroState *st = &scu->intro;
    int msgId;
    u32 ballStates[7];
    switch (*state) {
    case 0:
        st->trainers.side[0] = 11;
        st->trainers.side[1] = 13;
        BTLV_EFFECT_AddPokeSprite(BTL_MAIN_GetTrainerType((struct BtlMain *)scu->context, trainerClientA), st->trainers.side[0], 0, 0, 0);
        BTLV_EFFECT_AddPokeSprite(BTL_MAIN_GetTrainerType((struct BtlMain *)scu->context, trainerClientB), st->trainers.side[1], 0, 0, 0);
        BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
        (*state)++;
        break;
    case 1:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide)) {
            BTLV_EFFECT_StartEffectOnPoke(st->trainers.side[0], BTLV_EFFECT_MOVE_END + 6);
            BTLV_SCU_StartBrightnessFade(2);
            (*state)++;
        }
        break;
    case 2:
        if (!BTLV_EFFECT_IsBusy()) {
            if (BTL_MAIN_GetCompetitor((struct BtlMain *)scu->context) != 3) msgId = 9;
            else msgId = 10;
            BTLV_SCU_GetBallStates(scu, ballStates, trainerClientA, trainerClientB, 1);
            BTLV_EFFECT_CreatePartyBallBar((struct BtlvPartyBallBarParam *)ballStates);
            BTL_MSG_FormatArgs(scu->textBuf, (u16)msgId, 2, trainerClientA, trainerClientB);
            BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_EFFECT_StartEffectOnPoke(st->trainers.side[0], BTLV_EFFECT_MOVE_END + 7);
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 4:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide) && !BTLV_EFFECT_IsBusy()) return 1;
        break;
    }
    return 0;
}



/* Opponent sends out one monster (single battle, link). */
int BTLV_SCU_PhaseOpponentSendOutSingle(BtlvScu *scu, int *state)
{
    BtlvScuIntroState *st = &scu->intro;
    switch (*state) {
    case 0:
        st->single.side = 1;
        st->single.opponentClient = BTL_MAIN_GetOpponentClient((struct BtlMain *)scu->context, BTL_MAIN_GetOwnClientId((struct BtlMain *)scu->context), 0);
        st->single.monIdx = BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, st->single.side);
        st->single.mon = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, st->single.monIdx);
        st->single.monId = BTL_POKEPARAM_GetPokeId(st->single.mon);
        BTL_MSG_FormatArgs(scu->textBuf, BTLV_SCU_GetSendOutMessageId(scu, 1), 2, st->single.opponentClient, st->single.monId);
        BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
        (*state)++;
        break;
    case 1:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 2:
        BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(st->single.mon), st->single.side);
        BTLV_EFFECT_StartEffectOnPoke(st->single.side, BTLV_EFFECT_MOVE_END + 8);
        BTLV_EFFECT_DeletePartyBallBar(1);
        (*state)++;
        break;
    case 3:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide) && !BTLV_EFFECT_IsBusy()) {
            BTLV_SCU_ShowMonSlot(&scu->monSlots[st->single.monIdx]);
            (*state)++;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}



/* Opponent sends out two monsters: one trainer, or two when the opponent clients differ. */
int BTLV_SCU_PhaseOpponentSendOutDouble(BtlvScu *scu, int *state)
{
    u8 clientA = BTL_MAIN_GetOwnOpponentClient((struct BtlMain *)scu->context, 0);
    u8 clientB = BTL_MAIN_GetOwnOpponentClient((struct BtlMain *)scu->context, 1);
    if (clientA != clientB)
        return BTLV_SCU_RunOpponentSendOutDoubleTwoTrainers(scu, state, clientA, clientB);
    return BTLV_SCU_RunOpponentSendOutDoubleOneTrainer(scu, state, clientA);
}



int BTLV_SCU_RunOpponentSendOutDoubleOneTrainer(BtlvScu *scu, int *state, u8 trainerClient)
{
    BtlvScuIntroState *st = &scu->intro;
    unsigned i;
    switch (*state) {
    case 0:
        st->pair.side[0] = 3;
        st->pair.side[1] = 5;
        st->pair.clientId = trainerClient;
        st->pair.aliveCount = 0;
        for (i = 0; i < 2; i++) {
            st->pair.monIdx[i] = BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, st->pair.side[i]);
            st->pair.mon[i] = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, st->pair.monIdx[i]);
            st->pair.monId[i] = BTL_POKEPARAM_GetPokeId(st->pair.mon[i]);
            if (!BTL_POKEPARAM_IsFainted(st->pair.mon[i])) st->pair.aliveCount++;
        }
        BTL_MSG_FormatArgs(scu->textBuf, BTLV_SCU_GetSendOutMessageId(scu, st->pair.aliveCount), 3, st->pair.clientId, st->pair.monId[0], st->pair.monId[1]);
        BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
        (*state)++;
        break;
    case 1:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 2:
        BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(st->pair.mon[0]), st->pair.side[0]);
        if (st->pair.aliveCount == 2) BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(st->pair.mon[1]), st->pair.side[1]);
        BTLV_EFFECT_StartEffectOnPoke(st->pair.side[0], BTLV_EFFECT_MOVE_END + 8);
        BTLV_EFFECT_DeletePartyBallBar(1);
        (*state)++;
        break;
    case 3:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide) && !BTLV_EFFECT_IsBusy()) {
            BTLV_SCU_ShowMonSlot(&scu->monSlots[st->pair.monIdx[0]]);
            if (st->pair.aliveCount == 2) BTLV_SCU_ShowMonSlot(&scu->monSlots[st->pair.monIdx[1]]);
            (*state)++;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}



/*
 * lever: u16 clientA and clientB retain the entry spill and the later argument reload order.
 */
int BTLV_SCU_RunOpponentSendOutDoubleTwoTrainers(BtlvScu *scu, int *state, u16 clientA, u16 clientB)
{
    BtlvScuIntroState *st = &scu->intro;
    switch (*state) {
    case 0:
        st->pair.side[0] = 3;
        st->pair.monIdx[0] = BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, st->pair.side[0]);
        st->pair.mon[0] = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, st->pair.monIdx[0]);
        st->pair.monId[0] = BTL_POKEPARAM_GetPokeId(st->pair.mon[0]);
        st->pair.side[1] = 5;
        st->pair.monIdx[1] = BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, st->pair.side[1]);
        st->pair.mon[1] = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, st->pair.monIdx[1]);
        st->pair.monId[1] = BTL_POKEPARAM_GetPokeId(st->pair.mon[1]);
        BTL_MSG_FormatArgs(scu->textBuf, BTLV_SCU_GetSendOutMessageId(scu, 1), 2, clientA, st->pair.monId[0]);
        BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
        (*state)++;
        break;
    case 1:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 2:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide)) {
            BTL_MSG_FormatArgs(scu->textBuf, BTLV_SCU_GetSendOutMessageId(scu, 1), 2, clientB, st->pair.monId[1]);
            BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(st->pair.mon[0]), st->pair.side[0]);
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(st->pair.mon[1]), st->pair.side[1]);
            BTLV_EFFECT_StartEffectOnPoke(st->pair.side[0], BTLV_EFFECT_MOVE_END + 8);
            BTLV_EFFECT_DeletePartyBallBar(1);
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 4:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide) && !BTLV_EFFECT_IsBusy()) {
            BTLV_SCU_ShowMonSlot(&scu->monSlots[st->pair.monIdx[0]]);
            BTLV_SCU_ShowMonSlot(&scu->monSlots[st->pair.monIdx[1]]);
            (*state)++;
        }
        break;
    case 5:
        return 1;
    }
    return 0;
}



/* Opponent sends out three monsters (triple battle, link). */
int BTLV_SCU_PhaseOpponentSendOutTriple(BtlvScu *scu, int *state)
{
    BtlvScuIntroState *st = &scu->intro;
    unsigned i;
    switch (*state) {
    case 0:
        st->triple.side[0] = 3;
        st->triple.side[1] = 5;
        st->triple.side[2] = 7;
        st->triple.aliveCount = 0;
        st->triple.clientId = BTL_MAIN_GetOpponentClient((struct BtlMain *)scu->context, BTL_MAIN_GetOwnClientId((struct BtlMain *)scu->context), 0);
        for (i = 0; i < 3; i++) {
            st->triple.monIdx[i] = BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, st->triple.side[i]);
            st->triple.mon[i] = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, st->triple.monIdx[i]);
            st->triple.monId[i] = BTL_POKEPARAM_GetPokeId(st->triple.mon[i]);
            if (!BTL_POKEPARAM_IsFainted(st->triple.mon[i])) st->triple.aliveCount++;
        }
        BTL_MSG_FormatArgs(scu->textBuf, BTLV_SCU_GetSendOutMessageId(scu, st->triple.aliveCount), 4, st->triple.clientId, st->triple.monId[0], st->triple.monId[1], st->triple.monId[2]);
        BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
        (*state)++;
        break;
    case 1:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 2:
        BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(st->triple.mon[0]), st->triple.side[0]);
        if (st->triple.aliveCount > 1) BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(st->triple.mon[1]), st->triple.side[1]);
        if (st->triple.aliveCount > 2) BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(st->triple.mon[2]), st->triple.side[2]);
        BTLV_EFFECT_StartEffectOnPoke(st->triple.side[0], BTLV_EFFECT_MOVE_END + 8);
        BTLV_EFFECT_DeletePartyBallBar(1);
        (*state)++;
        break;
    case 3:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide) && !BTLV_EFFECT_IsBusy()) {
            BTLV_SCU_ShowMonSlot(&scu->monSlots[st->triple.monIdx[0]]);
            if (st->triple.aliveCount > 1) BTLV_SCU_ShowMonSlot(&scu->monSlots[st->triple.monIdx[1]]);
            if (st->triple.aliveCount > 2) BTLV_SCU_ShowMonSlot(&scu->monSlots[st->triple.monIdx[2]]);
            (*state)++;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}



/* Own side sends out one monster (single battle, link): ball display, then "Go!" message. */
int BTLV_SCU_PhaseOwnSendOutSingle(BtlvScu *scu, int *state)
{
    BtlvScuIntroState *st = &scu->intro;
    u32 ballStates[7];
    switch (*state) {
    case 0:
        st->single.trainerIdx = BTL_MAIN_GetOwnClientId((struct BtlMain *)scu->context);
        BTLV_SCU_GetBallStates(scu, ballStates, st->single.trainerIdx, 4, 0);
        BTLV_EFFECT_CreatePartyBallBar((struct BtlvPartyBallBarParam *)ballStates);
        (*state)++;
        break;
    case 1:
        if (!BTLV_EFFECT_IsBusy()) {
            BTLV_EFFECT_StartEffect(BTLV_EFFECT_MOVE_END + 1);
            (*state)++;
        }
        break;
    case 2:
        if (!BTLV_EFFECT_IsBusy() && !BTLV_EFFECT_IsPartyBallBarActive(0)) {
            st->single.side = 0;
            st->single.trainerIdx = BTL_MAIN_GetOwnClientId((struct BtlMain *)scu->context);
            st->single.monIdx = BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, st->single.side);
            st->single.mon = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, st->single.monIdx);
            st->single.monId = BTL_POKEPARAM_GetPokeId(st->single.mon);
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(st->single.mon), st->single.side);
            BTLV_EFFECT_StartEffect(BTLV_EFFECT_MOVE_END + 3);
            BTL_MSG_FormatArgs(scu->textBuf, 11, 1, st->single.monId);
            BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_EFFECT_DeletePartyBallBar(0);
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 4:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide) && !BTLV_EFFECT_IsBusy()) {
            BTLV_SCU_ShowMonSlot(&scu->monSlots[st->single.monIdx]);
            (*state)++;
        }
        break;
    case 5:
        return 1;
    }
    return 0;
}



/* Own side sends out two monsters: alone, or with a partner client when one exists. */
int BTLV_SCU_PhaseOwnSendOutDouble(BtlvScu *scu, int *state)
{
    u8 ownClient = BTL_MAIN_GetOwnClientId((struct BtlMain *)scu->context);
    u8 partnerClient = BTL_MAIN_GetOwnPartnerClient((struct BtlMain *)scu->context);
    if (partnerClient == 4)
        return BTLV_SCU_RunOwnSendOutDoubleSolo(scu, state, ownClient);
    return BTLV_SCU_RunOwnSendOutDoublePartner(scu, state, ownClient, partnerClient);
}



/*
 * lever: unsigned long loop counter fixes the base/counter register swap;
 * use one pointer element type for the store, null guard and subsequent calls.
 */
int BTLV_SCU_RunOwnSendOutDoubleSolo(BtlvScu *scu, int *state, u8 ownClient)
{
    BtlvScuIntroState *st = &scu->intro;
    unsigned long i;
    u32 ballStates[7];
    switch (*state) {
    case 0:
        st->pair.clientId = ownClient;
        BTLV_SCU_GetBallStates(scu, ballStates, st->pair.clientId, 4, 0);
        BTLV_EFFECT_CreatePartyBallBar((struct BtlvPartyBallBarParam *)ballStates);
        (*state)++;
        break;
    case 1:
        if (!BTLV_EFFECT_IsBusy()) {
            BTLV_EFFECT_StartEffect(BTLV_EFFECT_MOVE_END + 1);
            (*state)++;
        }
        break;
    case 2:
        if (!BTLV_EFFECT_IsBusy() && !BTLV_EFFECT_IsPartyBallBarActive(0)) {
            st->pair.side[0] = 2;
            st->pair.side[1] = 4;
            st->pair.aliveCount = 0;
            st->pair.clientId = BTL_MAIN_GetOwnClientId((struct BtlMain *)scu->context);
            for (i = 0; i < 2U; i++) {
                st->pair.monIdx[i] = BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, st->pair.side[i]);
                st->pair.mon[i] = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, st->pair.monIdx[i]);
                if (st->pair.mon[i]) {
                    st->pair.monId[i] = BTL_POKEPARAM_GetPokeId(st->pair.mon[i]);
                    if (!BTL_POKEPARAM_IsFainted(st->pair.mon[i])) st->pair.aliveCount++;
                }
            }
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(st->pair.mon[0]), st->pair.side[0]);
            if (st->pair.aliveCount > 1) BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(st->pair.mon[1]), st->pair.side[1]);
            BTLV_EFFECT_StartEffect(BTLV_EFFECT_MOVE_END + 3);
            BTL_MSG_FormatArgs(scu->textBuf, (u16)(st->pair.aliveCount == 2 ? 12 : 11), 2, st->pair.monId[0], st->pair.monId[1]);
            BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_EFFECT_DeletePartyBallBar(0);
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 4:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide) && !BTLV_EFFECT_IsBusy()) {
            BTLV_SCU_ShowMonSlot(&scu->monSlots[st->pair.monIdx[0]]);
            if (st->pair.aliveCount > 1) BTLV_SCU_ShowMonSlot(&scu->monSlots[st->pair.monIdx[1]]);
            (*state)++;
        }
        break;
    case 5:
        return 1;
    }
    return 0;
}



int BTLV_SCU_RunOwnSendOutDoublePartner(BtlvScu *scu, int *state, u32 ownClient, u8 partnerClient)
{
    BtlvScuIntroState *st = &scu->intro;
    unsigned long i;
    u32 ballStates[7];
    u8 partnerMonIdx;
    u8 ownMonIdx;
    u16 msgId;
    switch (*state) {
    case 0:
        if (ownClient < partnerClient) BTLV_SCU_GetBallStates(scu, ballStates, ownClient, partnerClient, 0);
        else BTLV_SCU_GetBallStates(scu, ballStates, partnerClient, ownClient, 0);
        BTLV_EFFECT_CreatePartyBallBar((struct BtlvPartyBallBarParam *)ballStates);
        (*state)++;
        break;
    case 1:
        if (!BTLV_EFFECT_IsBusy()) {
            BTLV_EFFECT_StartEffect(BTLV_EFFECT_MOVE_END + 2);
            (*state)++;
        }
        break;
    case 2:
        if (!BTLV_EFFECT_IsBusy() && !BTLV_EFFECT_IsPartyBallBarActive(0)) {
            st->pair.side[0] = 2;
            st->pair.side[1] = 4;
            st->pair.clientId = BTL_MAIN_GetOwnClientId((struct BtlMain *)scu->context);
            partnerMonIdx = BTL_MAIN_IsOwnClientSecondTeam((struct BtlMain *)scu->context) ^ 1;
            for (i = 0; i < 2U; i++) {
                st->pair.monIdx[i] = BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, st->pair.side[i]);
                st->pair.mon[i] = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, st->pair.monIdx[i]);
                st->pair.monId[i] = BTL_POKEPARAM_GetPokeId(st->pair.mon[i]);
            }
            msgId = BTL_MAIN_IsTrainerSlotNpc((struct BtlMain *)scu->context, partnerClient) ? 14 : 17;
            BTL_MSG_FormatArgs(scu->textBuf, (u16)msgId, 2, partnerClient, st->pair.monId[partnerMonIdx]);
            BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_EFFECT_DeletePartyBallBar(0);
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 4:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide)) {
            ownMonIdx = BTL_MAIN_IsOwnClientSecondTeam((struct BtlMain *)scu->context);
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(st->pair.mon[0]), st->pair.side[0]);
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(st->pair.mon[1]), st->pair.side[1]);
            BTLV_EFFECT_StartEffect(BTLV_EFFECT_MOVE_END + 3);
            BTL_MSG_FormatArgs(scu->textBuf, 11, 1, st->pair.monId[ownMonIdx]);
            BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 5:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 6:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide) && !BTLV_EFFECT_IsBusy()) {
            BTLV_SCU_ShowMonSlot(&scu->monSlots[st->pair.monIdx[0]]);
            BTLV_SCU_ShowMonSlot(&scu->monSlots[st->pair.monIdx[1]]);
            return 1;
        }
        break;
    }
    return 0;
}



/* Own side sends out three monsters (triple battle, link). */
int BTLV_SCU_PhaseOwnSendOutTriple(BtlvScu *scu, int *state)
{
    BtlvScuIntroState *st = &scu->intro;
    unsigned long i;
    u32 ballStates[7];
    u16 msgId;
    switch (*state) {
    case 0:
        st->triple.clientId = BTL_MAIN_GetOwnClientId((struct BtlMain *)scu->context);
        BTLV_SCU_GetBallStates(scu, ballStates, st->triple.clientId, 4, 0);
        BTLV_EFFECT_CreatePartyBallBar((struct BtlvPartyBallBarParam *)ballStates);
        (*state)++;
        break;
    case 1:
        if (!BTLV_EFFECT_IsBusy()) {
            BTLV_EFFECT_StartEffect(BTLV_EFFECT_MOVE_END + 1);
            (*state)++;
        }
        break;
    case 2:
        if (!BTLV_EFFECT_IsBusy() && !BTLV_EFFECT_IsPartyBallBarActive(0)) {
            st->triple.side[0] = 2;
            st->triple.side[1] = 4;
            st->triple.side[2] = 6;
            st->triple.aliveCount = 0;
            st->triple.clientId = BTL_MAIN_GetOwnClientId((struct BtlMain *)scu->context);
            for (i = 0; i < 3U; i++) {
                st->triple.monIdx[i] = BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, st->triple.side[i]);
                st->triple.mon[i] = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, st->triple.monIdx[i]);
                st->triple.monId[i] = BTL_POKEPARAM_GetPokeId(st->triple.mon[i]);
                if (!BTL_POKEPARAM_IsFainted(st->triple.mon[i])) st->triple.aliveCount++;
            }
            BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(st->triple.mon[0]), st->triple.side[0]);
            if (st->triple.aliveCount > 1) BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(st->triple.mon[1]), st->triple.side[1]);
            if (st->triple.aliveCount > 2) BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(st->triple.mon[2]), st->triple.side[2]);
            BTLV_EFFECT_StartEffect(BTLV_EFFECT_MOVE_END + 3);
            if (st->triple.aliveCount == 3) msgId = 13;
            else msgId = st->triple.aliveCount == 2 ? 12 : 11;
            BTL_MSG_FormatArgs(scu->textBuf, (u16)msgId, 3, st->triple.monId[0], st->triple.monId[1], st->triple.monId[2]);
            BTLV_SCU_StartMessage(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (BTLV_SCU_UpdateMessage(scu)) {
            BTLV_EFFECT_DeletePartyBallBar(0);
            BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
            (*state)++;
        }
        break;
    case 4:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide) && !BTLV_EFFECT_IsBusy()) {
            BTLV_SCU_ShowMonSlot(&scu->monSlots[st->triple.monIdx[0]]);
            if (st->triple.aliveCount > 1) BTLV_SCU_ShowMonSlot(&scu->monSlots[st->triple.monIdx[1]]);
            if (st->triple.aliveCount > 1) BTLV_SCU_ShowMonSlot(&scu->monSlots[st->triple.monIdx[2]]);
            (*state)++;
        }
        break;
    case 5:
        return 1;
    }
    return 0;
}




/*
 * Message id for an opponent send-out, by battle type and number of monsters:
 * wild 1/2, trainer 14..16, link 17..19.
 */
u16 BTLV_SCU_GetSendOutMessageId(BtlvScu *scu, int monCount)
{
    int r;

    switch (BTL_MAIN_GetCompetitor((struct BtlMain *)scu->context)) {
    case 0:
    default:
        r = 1;
        if (monCount != 1)
            r = 2;
        return r;
    case 1:
    case 2:
        if (monCount == 1)
            return 0xe;
        if (monCount == 2)
            return 0xf;
        return 0x10;
    case 3:
        if (monCount == 1)
            return 0x11;
        if (monCount == 2)
            return 0x12;
        return 0x13;
    }
}



/* Sound effects played by the battle view. */
#define BTLV_SCU_SE_MSG_ADVANCE 0x547



/* Effects started through the battle effect player. */
#define BTLV_SCU_EFFECT_POS_CUE (BTLV_EFFECT_MOVE_END + 46)



/* Hardware registers of the main engine. */
#define REG_MOSAIC (*(volatile u8 *)REG_MOSAIC_ADDR)



/* Slot number meaning no monster slot. */
#define BTLV_SCU_SLOT_NONE 6



/* Blend control register of the main engine. */
#define REG_BLDCNT REG_BLDCNT_ADDR



/* Prints a message into the message window at once. */
void BTLV_SCU_PrintMessageInstant(BtlvScu *scu, struct Strbuf *str)
{
    BMP_Clear((struct Bmp *)scu->msgWinChars, 0xc);
    GF_FONT_SetTextColor(1, 9, 0xc);
    PRINTSYS_Print((struct Bmp *)scu->msgWinChars, 0, 0, (struct Strbuf *)str, scu->fontMain);
    BMP_WIN_TransferChars(scu->msgWin);
    scu->msgStep = 0;
    scu->msgWait = 0;
    scu->msgWaitReload = 0;
    scu->msgWaitEnd = 0;
    scu->msgKeepText = 1;
    scu->msgEnded = 0;
}



/* Starts a streamed message; wait 0xFF means the default 0x50 frames. */
void BTLV_SCU_StartMessage(BtlvScu *scu, struct Strbuf *str, u16 wait, PrintCallback callback)
{
    struct TextPrinter *stream;

    BMP_Clear((struct Bmp *)scu->msgWinChars, 0xc);
    GF_FONT_SetTextColor(1, 9, 0xc);
    stream = PRINTSYS_PrintStreamCallBack(scu->msgWin, 0, 0, str, scu->fontMain,
                      BTL_MAIN_GetTextSpeedFrames((struct BtlMain *)scu->context),
                      scu->taskSys, 0,
                      scu->heapId, 0xc, callback);
    scu->msgStream = stream;
    PRINTSYS_PrintStreamStop(stream);
    scu->msgStep = 0;
    scu->msgKeepText = 0;
    if (wait == 0xff) {
        scu->msgWait = 0x50;
        scu->msgWaitEnd = 0;
    } else {
        scu->msgWait = wait;
        scu->msgWaitEnd = wait;
    }
    scu->msgWaitReload = scu->msgWait;
    scu->msgEnded = 0;
}



/*
 * Mid-stream entry point (reached only through bx r3 tail thunks). Reads the
 * stream-finished flag at 0x141: returns 1 and clears it when set. The index
 * is too wide for a Thumb ldrb immediate, so it comes from a pool word.
 */
u32 BTLV_SCU_ConsumeMessageEnded(BtlvScu *scu) { if (scu->msgEnded) { scu->msgEnded = 0; return 1; } return 0; }



/*
 * Steps the message procedure: returns 1 when the message is done.
 * Case 2 writes the next state in if/else arms (the ternary loses the 0x144 base kept in r5),
 * case 4 decrements with -- (reload of the halfword), and case 5 restarts the counter from
 * msgWaitReload without a decrement.
 */
int BTLV_SCU_UpdateMessage(BtlvScu *scu)
{
    switch (scu->msgStep) {
    case 0:
        BTLV_SCU_StartMsgWinFadeIn(&scu->slide, scu->msgKeepText);
        scu->msgStep = scu->msgStep + 1;
    case 1:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide) == 0)
            break;
        if (scu->msgKeepText != 0) {
            scu->msgStep = 6;
            break;
        }
        if (scu->msgStream != 0)
            PRINTSYS_PrintStreamRun(scu->msgStream);
        scu->msgStep = scu->msgStep + 1;
    case 2:
        if (scu->msgStream != 0) {
            if (BTL_MAIN_GetCommPos((struct BtlMain *)scu->context) == 0) {
                if ((KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0) {
                    if (PRINTSYS_PrintStreamIsOverrideSpeed(scu->msgStream) == 0)
                        PRINTSYS_PrintStreamSetSpeed(scu->msgStream, MSG_SPEED_GetWaitForSpeed(2));
                } else {
                    if (PRINTSYS_PrintStreamIsOverrideSpeed(scu->msgStream) != 0)
                        PRINTSYS_PrintStreamResetSpeed(scu->msgStream);
                }
            }
            scu->msgStreamState = PRINTSYS_PrintStreamGetState(scu->msgStream);
            if (scu->msgStreamState != 0) {
                if (BTL_MAIN_GetCommPos((struct BtlMain *)scu->context) == 0)
                    scu->msgStep = 3;
                else
                    scu->msgStep = 4;
                if (scu->msgStreamState == 2) {
                    scu->msgWait = scu->msgWaitEnd;
                    scu->msgEnded = 1;
                }
            }
        } else {
            scu->msgStep = 6;
        }
        break;
    case 3:
        if ((KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() != 0)
            scu->msgWait = 0;
        if (scu->msgWait != 0) {
            scu->msgWait = scu->msgWait - 1;
            break;
        }
        scu->msgStep = 5;
        break;
    case 4:
        if (scu->msgWait != 0) {
            scu->msgWait--;
            break;
        }
        scu->msgStep = 5;
        break;
    case 5:
        if (scu->msgStreamState == 2) {
            GF_FONT_SetDefaultTextColor();
            PRINTSYS_PrintStreamDelete(scu->msgStream);
            scu->msgStream = 0;
            scu->msgStep = 6;
            break;
        }
        PRINTSYS_PrintStreamReleasePause(scu->msgStream);
        GFL_USE_PlaySeDefaultVolume(BTLV_SCU_SE_MSG_ADVANCE);
        scu->msgStep = 2;
        scu->msgWait = scu->msgWaitReload;
        break;
    case 6:
        if (GFL_USE_IsSeqPlaying(BTLV_SCU_SE_MSG_ADVANCE) == 0) {
            scu->msgStep = 7;
            return 1;
        }
        break;
    case 7:
    default:
        return 1;
    }
    return 0;
}



/* Starts a move effect: the message window fades out first. */
void BTLV_SCU_StartWazaEffect(BtlvScu *scu, int attackerPos, int defenderPos, u32 wazaId, u32 effectSeq, int turnCount, u8 continueCount)
{
    BtlvScuWazaRequest *req = &scu->intro.waza;
    req->wazaId = wazaId;
    req->attackerPos = attackerPos;
    req->defenderPos = defenderPos;
    req->turnCount = turnCount;
    req->continueCount = continueCount;
    req->effectSeq = effectSeq;
    scu->preProc = 0;
    scu->mainProc = BTLV_SCU_ProcWazaEffect;
    scu->procScu = scu;
    scu->procState = 0;
}



/* Procedure of the move effect: fade out the window, start the effect, wait for it. */
int BTLV_SCU_ProcWazaEffect(int *state, BtlvScu *scu)
{
    switch (*state) {
    case 0:
        BTLV_SCU_StartMsgWinFadeOut(&scu->slide);
    next:
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_SCU_UpdateMsgWinFade(&scu->slide) != 0) {
            BTLV_EFFECT_StartEffectWithRequest((struct BtlvEffScriptRequest *)(&scu->intro.waza));
            goto next;
        }
        break;
    case 2:
        if (BTLV_EFFECT_IsBusy() == 0) {
            GFL_USE_StopAllSe();
            goto next;
        }
        break;
    default:
        return 1;
    }
    return 0;
}



/* Runs the pre procedure, else the main procedure; returns 1 when none is left (same code as BTLV_SCU_RunProc). */
int BTLV_SCU_RunWazaProc(BtlvScu *scu)
{
    BtlvScuProc proc;
    proc = scu->preProc;
    if (proc != 0) {
        if (proc(&scu->procState, scu->procScu) != 0) {
            scu->preProc = 0;
            scu->procState = 0;
        }
        return 0;
    }
    proc = scu->mainProc;
    if (proc != 0) {
        if (proc(&scu->procState, scu->procScu) != 0) {
            scu->mainProc = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}



/* Starts the damage motion of a slot; the HP gauge update is animated unless instant. */
void BTLV_SCU_StartMonDamageAnim(BtlvScu *scu, u8 slotIdx, u16 motionId, int instant)
{
    int value;
    u32 viewPos;
    value = BTL_POKEPARAM_GetValue((struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, slotIdx), 0xd);
    viewPos = BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)scu->context, slotIdx);
    if (instant == 0) {
        BTLV_EFFECT_GaugeStartHpChangeAnimated(viewPos, value);
        BTLV_EFFECT_StartDamageTintTask(viewPos, motionId);
    } else {
        BTLV_EFFECT_GaugeStartHpChangeInstant(viewPos, value);
    }
}



/* Both the effect player and the gauge are idle. */
int BTLV_SCU_IsMonDamageAnimDone(BtlvScu *scu)
{
    int effectBusy = BTLV_EFFECT_IsBusy();
    if ((BTLV_EFFECT_GaugeIsAnimating() | effectBusy) == 0)
        return 1;
    return 0;
}



/* Starts a motion on the monster of a slot. */
void BTLV_SCU_StartMonMotion(BtlvScu *scu, u8 slotIdx, u32 motionId)
{
    BTLV_EFFECT_StartDamageTintTask(BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)scu->context, slotIdx), motionId);
}



/* The effect player is idle. */
int BTLV_SCU_IsMonMotionDone(BtlvScu *scu)
{
    if (BTLV_EFFECT_IsBusy() == 0)
        return 1;
    return 0;
}



/* Hides the sprite of a slot and starts its exit motion (flag selects the variant). */
void BTLV_SCU_StartMonExit(BtlvScu *scu, int slotIdx, u32 flag)
{
    u8 viewPos = BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)scu->context, slotIdx);
    BTLV_EFFECT_GaugeDeleteSlot(viewPos);
    if (flag == 0)
        BTLV_EFFECT_StartPokeAppearEffect(viewPos);
    else
        BTLV_EFFECT_DeletePokeSprite(viewPos);
}



/* The effect player is idle. */
int BTLV_SCU_IsMonExitDone(BtlvScu *scu)
{
    if (BTLV_EFFECT_IsBusy() == 0)
        return 1;
    return 0;
}



/* Loads the sprite of the monster in a slot and shows the slot. */
void BTLV_SCU_LoadAndShowMon(BtlvScu *scu, u8 slotIdx)
{
    u8 viewPos = BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)scu->context, slotIdx);
    BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon((struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, slotIdx)), viewPos);
    BTLV_SCU_ShowMonSlot(&scu->monSlots[slotIdx]);
}



/* The effect player is idle. */
int BTLV_SCU_IsMonLoadDone(BtlvScu *scu)
{
    if (BTLV_EFFECT_IsBusy() == 0)
        return 1;
    return 0;
}



/* Withdraws the sprite at a view position, with a recall effect unless instant. */
void BTLV_SCU_StartMonWithdraw(BtlvScu *scu, u16 viewPos, u16 effectId, int instant)
{
    struct BtlvScuWithdrawTask *work;
    if (instant != 0 || effectId == 0) {
        BTLV_EFFECT_GaugeDeleteSlot(viewPos);
        BTLV_EFFECT_DeletePokeSprite(viewPos);
        return;
    }
    work = TCBL_GetWork(TCBL_AddTask(scu->taskSys, BTLV_SCU_TaskMonWithdraw, 0x10, 1));
    work->viewPos = viewPos;
    work->slot = &scu->monSlots[viewPos];
    work->counter = &scu->withdrawTaskCount;
    /* Dead after the early return above; the original has it. */
    if (effectId == 0)
        effectId = BTLV_SCU_EFFECT_WITHDRAW;
    work->effectId = effectId;
    work->step = 0;
    (*work->counter)++;
}



/* No withdraw task is running. */
u32 BTLV_SCU_IsMonWithdrawDone(BtlvScu *scu) { if (scu->withdrawTaskCount == 0) return 1; return 0; }



/* Task: plays the withdraw effect, then hides the sprite. */
void BTLV_SCU_TaskMonWithdraw(struct TcblTask *task, void *workPtr)
{
    struct BtlvScuWithdrawTask *work = workPtr;
    switch (work->step) {
    case 0:
        BTLV_EFFECT_StartEffectOnPoke(work->viewPos, work->effectId);
        (work->step)++;
        break;
    case 1:
        if (BTLV_EFFECT_IsBusy() == 0) {
            BTLV_EFFECT_GaugeDeleteSlot(work->viewPos);
            BTLV_EFFECT_DeletePokeSprite(work->viewPos);
            (work->step)++;
        }
        break;
    case 2:
        (*work->counter)--;
        TCBL_DeleteTask(task);
        break;
    }
}



/*
 * Starts the send-out of a monster into a slot (plays the send-out effect unless quiet).
 * Lever: the record from TCBL_GetWork is a struct pointer, not u8 *: the
 * counter field is then forwarded across the step store instead of being reloaded
 * (u8 * base plus a local kept in r1 gave 84 bytes out).
 */
void BTLV_SCU_StartMonSendOut(BtlvScu *scu, u8 slotIdx, int clientId, u8 partyIdx, int quiet)
{
    struct BtlvScuSlotTask *work;
    struct BtlPokeParam *mon;
    u8 viewPos;
    work = TCBL_GetWork(TCBL_AddTask(scu->taskSys, BTLV_SCU_TaskMonSendOut, 0xc, 1));
    work->slot = &scu->monSlots[slotIdx];
    work->counter = &scu->sendOutTaskCount;
    work->step = 0;
    (*work->counter)++;
    mon = BTL_SIDE_GetClientPoke((struct BtlSide *)scu->monTable, clientId, partyIdx);
    viewPos = BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)scu->context, slotIdx);
    BTLV_EFFECT_SetPokeSpriteKey(BTL_POKEPARAM_GetDisplayMon(mon), viewPos);
    if (quiet == 0)
        BTLV_EFFECT_StartEffectOnPoke(viewPos, BTLV_SCU_EFFECT_SEND_OUT);
}



/* No send-out task is running (adds #0x41, ldrb, cmp #0: a 16-byte leaf with no calls and no pool). */
int BTLV_SCU_IsMonSendOutDone(BtlvScu *scu) { return scu->sendOutTaskCount == 0; }



/* Task: waits for the effect, then shows the slot. */
void BTLV_SCU_TaskMonSendOut(struct TcblTask *task, void *workPtr)
{
    struct BtlvScuSlotTask *work = workPtr;
    switch (work->step) {
    case 0:
        if (BTLV_EFFECT_IsBusy() == 0) {
            BTLV_SCU_ShowMonSlot(work->slot);
            work->step = work->step + 1;
        }
        break;
    case 1:
        (*work->counter)--;
        TCBL_DeleteTask(task);
        break;
    }
}



/* Starts the HP gauge update of a slot (animated unless instant). */
void BTLV_SCU_StartHpGaugeUpdate(BtlvScu *scu, u8 slotIdx, int instant)
{
    int value = BTL_POKEPARAM_GetValue((struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable, slotIdx), 0xd);
    u8 viewPos = BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)scu->context, slotIdx);
    if (instant != 0)
        BTLV_EFFECT_GaugeStartHpChangeInstant(viewPos, value);
    else
        BTLV_EFFECT_GaugeStartHpChangeAnimated(viewPos, value);
}



/* The gauge is idle. */
int BTLV_SCU_IsHpGaugeIdle(BtlvScu *scu)
{
    if (BTLV_EFFECT_GaugeIsAnimating() == 0)
        return 1;
    return 0;
}



/* Hides two slots. */
void BTLV_SCU_HideMonPair(BtlvScu *scu, int slotA, int slotB)
{
    BTLV_SCU_HideMonSlot(&scu->monSlots[slotA]);
    BTLV_SCU_HideMonSlot(&scu->monSlots[slotB]);
    BTLV_EFFECT_SetLowHpBgmSuppressed(1);
}



/* Shows two slots; returns 1 (step procedure form). */
int BTLV_SCU_ShowMonPair(BtlvScu *scu, int slotA, int slotB)
{
    BTLV_SCU_ShowMonSlot(&scu->monSlots[slotA]);
    BTLV_SCU_ShowMonSlot(&scu->monSlots[slotB]);
    BTLV_EFFECT_SetLowHpBgmSuppressed(0);
    return 1;
}



/* Hides one slot. */
void BTLV_SCU_HideMon(BtlvScu *scu, int slotIdx)
{
    BTLV_SCU_HideMonSlot(&scu->monSlots[slotIdx]);
    BTLV_EFFECT_SetLowHpBgmSuppressed(1);
}



/* Shows one slot; returns 1 (step procedure form). */
int BTLV_SCU_ShowMon(BtlvScu *scu, int slotIdx)
{
    BTLV_SCU_ShowMonSlot(&scu->monSlots[slotIdx]);
    BTLV_EFFECT_SetLowHpBgmSuppressed(0);
    return 1;
}



/* Starts the cue effect at a view position. */
void BTLV_SCU_StartPosCueEffect(struct BtlvScu *unused, int viewPos)
{
    BTLV_EFFECT_StartEffectOnPoke(viewPos, BTLV_SCU_EFFECT_POS_CUE);
}



/* The effect player is idle. */
int BTLV_SCU_IsPosCueEffectDone(struct BtlvScu *unused, int viewPos)
{
    if (BTLV_EFFECT_IsBusy() == 0)
        return 1;
    return 0;
}



/* Starts the form change of the monster in a slot (slot 6 means none). */
void BTLV_SCU_StartMonFormChange(BtlvScu *scu, u8 slotIdx, u32 flag)
{
    struct BtlvScuFormChangeTask *work;
    if (slotIdx != BTLV_SCU_SLOT_NONE) {
        work = TCBL_GetWork(TCBL_AddTask(scu->taskSys, BTLV_SCU_TaskMonFormChange, 0x18, 1));
        work->scu = scu;
        work->slotIdx = slotIdx;
        work->flag = flag;
        work->viewPos = BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)scu->context, slotIdx);
        work->counter = &scu->monTaskCount;
        work->step = 0;
        (*work->counter)++;
    }
}



/* No form change or window fade task is running. */
u32 BTLV_SCU_IsMonFormChangeDone(BtlvScu *scu) { if (scu->monTaskCount == 0) return 1; return 0; }



/* Task: swaps the graphic of the monster, hides it, then shows it again. */
void BTLV_SCU_TaskMonFormChange(struct TcblTask *task, void *workPtr)
{
    struct BtlvScuFormChangeTask *work = workPtr;
    void *mon;
    switch (work->step) {
    case 0:
        mon = BTL_POKEPARAM_GetMon((struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)work->scu->monTable, work->slotIdx));
        if (work->flag == 0)
            BTLV_EFFECT_StartHitTask(mon, work->viewPos);
        else
            BTLV_EFFECT_ResetPokeSprite(mon, work->viewPos);
        BTLV_EFFECT_GaugeDeleteSlot(work->viewPos);
        work->step++;
        break;
    case 1:
        if (BTLV_EFFECT_IsBusy() == 0) {
            BTLV_EFFECT_GaugeInitSlotFromBattlePoke((struct BtlMain *)work->scu->context,
                          (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)work->scu->monTable, work->slotIdx), work->viewPos);
            (*work->counter)--;
            TCBL_DeleteTask(task);
        }
        break;
    }
}



/* Starts a graphic swap at destPos using the monster found at srcPos. */
void BTLV_SCU_StartMonGraphicSwapFrom(BtlvScu *scu, u32 destPos, u32 srcPos, u32 flag)
{
    struct BtlvScuGraphicSwapTask *work;
    work = TCBL_GetWork(TCBL_AddTask(scu->taskSys, BTLV_SCU_TaskMonGraphicSwap, 0x18, 1));
    work->mon = BTL_POKEPARAM_GetMon((struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable,
                                              BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, srcPos)));
    work->scu = scu;
    work->viewPos = destPos;
    work->counter = &scu->monTaskCount;
    work->flag = flag;
    work->step = 0;
    (*work->counter)++;
}



/* Starts a graphic swap of the monster at a view position. */
void BTLV_SCU_StartMonGraphicSwap(BtlvScu *scu, u32 viewPos, u32 flag)
{
    struct BtlvScuGraphicSwapTask *work;
    work = TCBL_GetWork(TCBL_AddTask(scu->taskSys, BTLV_SCU_TaskMonGraphicSwap, 0x18, 1));
    work->mon = BTL_POKEPARAM_GetMon((struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)scu->monTable,
                                              BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)scu->context, viewPos)));
    work->scu = scu;
    work->viewPos = viewPos;
    work->counter = &scu->monTaskCount;
    work->flag = flag;
    work->step = 0;
    (*work->counter)++;
}



/* No graphic swap or window fade task is running. */
u32 BTLV_SCU_IsMonGraphicSwapDone(BtlvScu *scu) { if (scu->monTaskCount == 0) return 1; return 0; }



/* Task: swaps the graphic and waits for the effect player. */
void BTLV_SCU_TaskMonGraphicSwap(struct TcblTask *task, void *workPtr)
{
    struct BtlvScuGraphicSwapTask *work = workPtr;
    switch (work->step) {
    case 0:
        if (work->flag == 0)
            BTLV_EFFECT_StartHitTask(work->mon, work->viewPos);
        else
            BTLV_EFFECT_ResetPokeSprite(work->mon, work->viewPos);
        work->step++;
        break;
    case 1:
        if (BTLV_EFFECT_IsBusy() == 0) {
            (*work->counter)--;
            TCBL_DeleteTask(task);
        }
        break;
    }
}



/* Sets up the message window fade: window shown, blend registers set. */
void BTLV_SCU_InitMsgWinFade(BtlvScuWinSlide *fade, struct BmpWin *win)
{
    fade->win = win;
    fade->state = 0;
    fade->evA = 0x1f000;
    fade->evB = 0x7000;
    G2x_SetBlendAlpha_((u32 *)REG_BLDCNT, 2, 0x3d, 0x1f, 7);
}



/* Starts fading the window out (only from shown or fading in). */
void BTLV_SCU_StartMsgWinFadeOut(BtlvScuWinSlide *fade)
{
    u8 state = fade->state;
    if (state == 0 || state == 3) {
        fade->evA = 0x1f000;
        fade->evB = 0x7000;
        fade->evADelta = -0x52aa;
        fade->evBDelta = 0x1800;
        fade->stepsLeft = 6;
        fade->state = 1;
    }
}



/* Requests fading the window back in; the text is erased unless keepText. */
void BTLV_SCU_StartMsgWinFadeIn(BtlvScuWinSlide *fade, int keepText)
{
    if ((u8)(fade->state + 0xff) <= 1) {
        if (keepText == 0) {
            BMP_Clear(BMP_WIN_GetBmp(fade->win), 0xc);
            BMP_WIN_TransferChars(fade->win);
        }
        fade->evA = 0;
        fade->evB = 0x10000;
        fade->evADelta = 0x52aa;
        fade->evBDelta = -0x1800;
        fade->stepsLeft = 6;
        fade->state = 4;
    }
}



/*
 * Steps the window fade; returns 1 when it has settled (shown or hidden).
 * Lever: the shared step block at 0x021ED84A is the same code written in
 * both arms (case 3 and case 1) with the same `if (stepsLeft != 0)` polarity; the
 * compiler cross-jumps the second copy into `b 0x021ED84A`.  A goto into the
 * first copy, or `== 0` polarity, moves the branches.
 */
int BTLV_SCU_UpdateMsgWinFade(BtlvScuWinSlide *fade)
{
    switch (fade->state) {
    case 2:
        return 1;
    case 0:
        return 1;
    case 4:
        fade->state = 3;
        return 0;
    case 3:
        if (fade->stepsLeft != 0) {
            fade->evA += fade->evADelta;
            fade->evB += fade->evBDelta;
            fade->stepsLeft = fade->stepsLeft - 1;
        } else {
            fade->evA = 0x1f000;
            fade->evB = 0x7000;
            fade->state = 0;
        }
        break;
    case 1:
        if (fade->stepsLeft != 0) {
            fade->evA += fade->evADelta;
            fade->evB += fade->evBDelta;
            fade->stepsLeft = fade->stepsLeft - 1;
        } else {
            fade->evA = 0;
            fade->evB = 0x10000;
            fade->state = 2;
        }
        break;
    }
    G2x_SetBlendAlpha_((u32 *)REG_BLDCNT, 2, 0x3d, (u8)(fade->evA >> 12), (u8)(fade->evB >> 12));
    return 0;
}



/* Starts a task that fades the message window out. */
void BTLV_SCU_StartMsgWinFadeOutTask(BtlvScu *scu)
{
    struct BtlvScuFadeTask *work;
    work = TCBL_GetWork(TCBL_AddTask(scu->taskSys, BTLV_SCU_TaskMsgWinFadeOut, 0xc, 1));
    work->scu = scu;
    work->counter = &scu->monTaskCount;
    work->step = 0;
    (*work->counter)++;
}



/* Mid-stream entry point, same shape as BTLV_SCU_IsMonWithdrawDone with the offset 0x40. */
u32 BTLV_SCU_IsMsgWinFadeOutTaskDone(BtlvScu *scu) { if (scu->monTaskCount == 0) return 1; return 0; }



/* Task: fades the message window out and waits for it. */
void BTLV_SCU_TaskMsgWinFadeOut(struct TcblTask *task, void *workPtr)
{
    struct BtlvScuFadeTask *work = workPtr;
    switch (work->step) {
    case 0:
        BTLV_SCU_StartMsgWinFadeOut(&work->scu->slide);
        work->step++;
        break;
    case 1:
        if (BTLV_SCU_UpdateMsgWinFade(&work->scu->slide) != 0) {
            (*work->counter)--;
            TCBL_DeleteTask(task);
        }
        break;
    }
}



/*
 * Clears the monster slots and initialises the ones the battle rule needs.
 * The clear loop runs one slot too far (7 slots); the extra writes land on
 * the first name plate, which is set up later.
 */
void BTLV_SCU_InitMonSlots(BtlvScu *scu)
{
    u32 i;
    u32 count;
#ifdef __MWERKS__
    for (i = 0; i <= 6; i++) {
        scu->monSlots[i].isActive = 0;
        scu->monSlots[i].mon = 0;
    }
#else
    for (i = 0; i < 6; i++) {
        scu->monSlots[i].isActive = 0;
        scu->monSlots[i].mon = 0;
    }
    /* the DS slot 6 clear lands on the first name plate */
    scu->namePlates[0].scu = 0;
    scu->namePlates[0].bgPlane = 0;
#endif
    if (BTL_MAIN_GetRule((struct BtlMain *)scu->context) != 3) {
        count = BTL_MAIN_GetRuleSlotSpan((struct BtlMain *)scu->context);
    } else {
        count = 5;
    }
    for (i = 0; i <= count; i++) {
        BTLV_SCU_InitMonSlot(&scu->monSlots[i], scu, i);
    }
}



/* Resets all six monster slots. */
void BTLV_SCU_ResetMonSlots(BtlvScu *scu)
{
    u32 i;
    for (i = 0; i < 6; i++)
        BTLV_SCU_ResetMonSlot(&scu->monSlots[i]);
}



/* Initialises one monster slot. */
void BTLV_SCU_InitMonSlot(BtlvScuMonSlot *slot, BtlvScu *owner, u8 slotIdx)
{
    slot->slotIdx = slotIdx;
    slot->viewPos = BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)owner->context, slotIdx);
    slot->owner = owner;
    slot->isShown = 0;
    slot->isActive = 1;
    slot->mon = 0;
}



/* Resets one monster slot: hides its sprite and marks it unused. */
void BTLV_SCU_ResetMonSlot(BtlvScuMonSlot *slot)
{
    if (slot->isActive != 0) {
        if (slot->isShown != 0) {
            BTLV_EFFECT_GaugeDeleteSlot(slot->viewPos);
            slot->isShown = 0;
        }
        slot->mon = 0;
        slot->isActive = 0;
    }
}



/* Hides the sprite of a slot when it is shown. */
void BTLV_SCU_HideMonSlot(BtlvScuMonSlot *slot)
{
    if (slot->isShown != 0) {
        BTLV_EFFECT_GaugeDeleteSlot(slot->viewPos);
        slot->isShown = 0;
    }
}



/* Shows the sprite of the monster standing at the slot, unless it fainted. */
void BTLV_SCU_ShowMonSlot(BtlvScuMonSlot *slot)
{
    if (slot->isActive != 0) {
        slot->mon = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)slot->owner->monTable, slot->slotIdx);
        if (BTL_POKEPARAM_IsFainted(slot->mon) == 0) {
            BTLV_EFFECT_GaugeInitSlotFromBattlePoke((struct BtlMain *)slot->owner->context, slot->mon, slot->viewPos);
            slot->isShown = 1;
        }
    }
}



/*
 * Which name plate a view position uses: 0 on the local side, 1 otherwise.
 * The 0/1 return uses enum constants: with int constants the compiler folds the two returns
 * into a boolean and lays the one first (bne). See
 * docs/idioms/a-flag-ternary-over-enum-constants-keeps-the-bne-to-one-polarity.md.
 */
BtlvScuPlateSide BTLV_SCU_GetNamePlateSide(struct BtlContext *ctx, u32 viewPos)
{
    if (BTL_MAIN_IsLocalSide((struct BtlMain *)ctx, BTL_MAIN_GetPosParity(viewPos)) != 0)
        return BTLV_SCU_PLATE_LOCAL;
    return BTLV_SCU_PLATE_OPPOSING;
}



/* Shows the name plate of the monster at a view position. */
void BTLV_SCU_StartNamePlate(BtlvScu *scu, u8 viewPos, int closeLater)
{
    int side = BTLV_SCU_GetNamePlateSide(scu->context, viewPos);
    if (side == 0)
        BTLV_EFFECT_TimerSetVisible(0, 0, 0);
    BTLV_EFFECT_ResumeVmWait();
    BTLV_SCU_PrepareNamePlate(&scu->namePlates[side], viewPos, closeLater);
}



/* Steps the slide-in of the name plate of a view position. */
int BTLV_SCU_ProcNamePlateAt(BtlvScu *scu, u32 viewPos)
{
    return BTLV_SCU_ProcNamePlate(&scu->namePlates[BTLV_SCU_GetNamePlateSide(scu->context, viewPos)]);
}



/* Starts hiding the name plate of a view position. */
void BTLV_SCU_HideNamePlateAt(BtlvScu *scu, u32 viewPos)
{
    u8 side = BTLV_SCU_GetNamePlateSide(scu->context, viewPos);
    BTLV_SCU_HideNamePlate(&scu->namePlates[side]);
    if (side == 0)
        BTLV_EFFECT_TimerSetVisible(0, 1, 0);
}



/* Checks the name plate of a view position (always 1). */
int BTLV_SCU_IsNamePlateHiddenAt(BtlvScu *scu, u32 viewPos)
{
    u8 side = BTLV_SCU_GetNamePlateSide(scu->context, viewPos);
    return BTLV_SCU_IsNamePlateHidden(&scu->namePlates[side]);
}



/* Redraws the name plate of a view position for its current monster. */
void BTLV_SCU_RefreshNamePlateAt(BtlvScu *scu, u8 viewPos)
{
    BTLV_SCU_RefreshNamePlate(&scu->namePlates[BTLV_SCU_GetNamePlateSide(scu->context, viewPos)], viewPos);
}



/* Steps the mosaic change of the name plate of a view position. */
int BTLV_SCU_ProcNamePlateMosaicAt(BtlvScu *scu, u32 viewPos)
{
    return BTLV_SCU_ProcNamePlateMosaic(&scu->namePlates[BTLV_SCU_GetNamePlateSide(scu->context, viewPos)]);
}



/* Loads the plate graphics and creates the two name plates. */
void BTLV_SCU_InitNamePlates(BtlvScu *scu, u32 tile)
{
    u32 i;
    scu->nameGfxFile = ARC_UTIL_LoadBgCharDataFromArchive((u32)0xb, (u32)0xd5, (u32)0, (&scu->nameGfx), scu->heapId);
    for (i = 0; i < 2; i++) {
        scu->namePlates[i].scu = scu;
        scu->namePlates[i].sideIdx = i;
        scu->namePlates[i].bgPlane = (i == 0) ? 2 : 3;
        scu->namePlates[i].templatePixels = scu->nameGfx->pixels + i * 0x900;
        scu->namePlates[i].bmp = BMP_Create(0x12, 4, 0x20, scu->heapId);
        scu->namePlates[i].speciesId = 0;
        scu->namePlates[i].pokeId = 0x1f;
        scu->namePlates[i].tile = tile + i * 0x48;
        scu->namePlates[i].isShown = 0;
    }
}



/* Frees the plate bitmaps and the plate graphics. */
void BTLV_SCU_FreeNamePlates(BtlvScu *scu)
{
    u32 i;
    for (i = 0; i < 2; i++) {
        if (scu->namePlates[i].bmp != 0) {
            BMP_Delete(scu->namePlates[i].bmp);
            scu->namePlates[i].bmp = 0;
        }
    }
    if (scu->nameGfxFile != 0) {
        GFL_HEAP_Free(scu->nameGfxFile);
        scu->nameGfxFile = 0;
    }
}



/*
 * Prepares a plate for the monster at a view position: hides the old plate, redraws the
 * text when the monster changed, restarts the plate procedure.
 * note:     viewPos is a narrow (u8/u16, both give EXACT*) parameter: it pins the
 *           spill store to the front of the prologue; closeLater is int, cast (u8)
 *           at the bitfield store.
 */
void BTLV_SCU_PrepareNamePlate(BtlvScuNamePlate *plate, u8 viewPos, int closeLater)
{
    struct BtlPokeParam *mon;
    u16 speciesId;
    u8 pokeId;
    mon = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)plate->scu->monTable, viewPos);
    speciesId = BTL_POKEPARAM_GetValue(mon, 0x10);
    pokeId = BTL_POKEPARAM_GetPokeId(mon);
    if (plate->isShown) {
        if (pokeId == plate->pokeId) {
            return;
        }
        BTLV_SCU_HideNamePlate(plate);
    }
    if (speciesId != plate->speciesId || pokeId != plate->pokeId) {
        plate->speciesId = speciesId;
        plate->pokeId = pokeId;
        BTLV_SCU_DrawNamePlate(plate);
    }
    plate->closeRequested = (u8)closeLater;
    plate->phase = 0;
    BTLV_EFFECT_SetPokeEffectValue(viewPos, speciesId);
}



/*
 * Plate procedure: sends the graphics, slides the plate in, copies the text
 * rows, holds until a close is requested, then fades the palette. Returns 1
 * when it waits or is done.
 */
int BTLV_SCU_ProcNamePlate(BtlvScuNamePlate *plate)
{
    u32 i;
    u8 *src;
    u32 dst;
    void *slots;
    void *ctx;
    u16 mask;
    switch (plate->phase) {
    case 0:
        BG_SYS_LoadTileData(plate->bgPlane, plate->templatePixels, 0x900, plate->tile);
        plate->phase++;
        break;
    case 1:
        plate->timer = 8;
        if (plate->sideIdx == 0) {
            plate->slideX = 0x90000;
            plate->slideDx = -0x12000;
        } else {
            plate->slideX = -0x90000;
            plate->slideDx = 0x12000;
        }
        BG_SYS_ChangeScrollImmediate(plate->bgPlane, 0, plate->slideX >> 12);
        BG_SYS_ChangeScrollImmediate(plate->bgPlane, 3, 0);
        GFL_USE_PlaySeDefaultVolume(BTLV_SCU_SE_PLATE_SLIDE);
        plate->phase++;
        break;
    case 2:
        if (plate->timer != 0) {
            plate->slideX += plate->slideDx;
            BG_SYS_ChangeScrollImmediate(plate->bgPlane, 0, plate->slideX >> 12);
            plate->timer--;
        } else {
            BG_SYS_ChangeScrollImmediate(plate->bgPlane, 0, 0);
            plate->counter = 0;
            plate->phase++;
        }
        break;
    case 3:
        if (plate->counter < 17) {
            src = (u8 *)BMP_GetPixels(plate->bmp);
            dst = plate->tile + plate->counter;
            src += plate->counter * 32;
            for (i = 0; i < 4; i++) {
                BG_SYS_LoadTileData(plate->bgPlane, src + i * 0x240, 32, dst + i * 18);
            }
            plate->counter++;
        } else {
            plate->isShown = 1;
            if (plate->closeRequested == 0) return 1;
            plate->phase++;
        }
        break;
    case 4:
        slots = (void *)BTLV_EFFECT_GetPalanm();
        ctx = BTLV_EFFECT_GetOwner();
        mask = 1 << (plate->sideIdx + 1);
        GFL_USE_PlaySeDefaultVolume(BTLV_SCU_SE_PLATE_FADE);
        PALANM_RequestFade(slots, 1, mask, 0, 16, 0, 0x7fff, ctx);
        plate->phase++;
        break;
    case 5:
        if (PALANM_GetFadeRequestBits(BTLV_EFFECT_GetPalanm()) == 0) plate->phase++;
        break;
    case 6:
        if (GFL_USE_IsSeqPlaying(BTLV_SCU_SE_PLATE_FADE) == 0 && GFL_USE_IsSeqPlaying(BTLV_SCU_SE_PLATE_SLIDE) == 0) return 1;
        break;
    }
    return 0;
}



/* Draws the text of a plate: the template, then one or two lines of message 0x67. */
void BTLV_SCU_DrawNamePlate(BtlvScuNamePlate *plate)
{
    BtlvScu *scu;
    u32 size;
    void *pixels;
    u32 widths[2];
    int right;
    int left;
    int gap;
    int extra;
    int half;
    u32 edge;
    u32 width;
    u32 center;
    scu = plate->scu;
    size = BMP_GetByteSize(plate->bmp);
    pixels = BMP_GetPixels(plate->bmp);
    MIi_CpuCopy32(plate->scu->nameGfx->pixels + plate->sideIdx * 0x900, pixels, size);
    GF_FONT_SetTextColor(1, 2, 0);
    BTL_MSG_FormatArgs(scu->wordBuf0, 0x67, 2, plate->pokeId, plate->speciesId);
    if ((u8)PRINTSYS_InitCallerSuppliedArray((struct Strbuf *)scu->wordBuf0, scu->fontSub, 0, widths, 2) > 1) {
        width = widths[0];
        edge = width + 8;
        right = 0x84 - widths[1];
        gap = edge - right;
        if (gap < 12) {
            extra = 12 - gap;
            half = extra / 2;
            edge += half;
            extra -= half;
            right -= extra;
        }
        left = edge;
        left = left - width;
        if (left < 0) left = 0;
        if (right < 0) right = 0;
        PRINTSYS_CopyLine((struct Strbuf *)scu->wordBuf0, (struct Strbuf *)scu->wordBuf1, 0);
        PRINTSYS_Print(plate->bmp, left, 7, (struct Strbuf *)scu->wordBuf1, scu->fontSub);
        PRINTSYS_CopyLine((struct Strbuf *)scu->wordBuf0, (struct Strbuf *)scu->wordBuf1, 1);
        PRINTSYS_Print(plate->bmp, right, 18, (struct Strbuf *)scu->wordBuf1, scu->fontSub);
    } else {
        center = (0x88 - PRINTSYS_MeasureWidestLine((struct Strbuf *)scu->wordBuf0, scu->fontSub, 0)) / 2;
        if ((int)center < 0) center = 0;
        PRINTSYS_Print(plate->bmp, center, 18, (struct Strbuf *)scu->wordBuf0, scu->fontSub);
    }
}



/* Scrolls the plate back out and marks it hidden. */
void BTLV_SCU_HideNamePlate(BtlvScuNamePlate *plate)
{
    if (plate->sideIdx == 0)
        BG_SYS_ChangeScrollImmediate(plate->bgPlane, 0, 0x90);
    else
        BG_SYS_ChangeScrollImmediate(plate->bgPlane, 0, -0x90);
    plate->isShown = 0;
}



/* Returns the constant 1 (movs r0, #1). */
int BTLV_SCU_IsNamePlateHidden(BtlvScuNamePlate *plate) { return 1; }



/* Redraws the plate when the monster at the view position changed. */
void BTLV_SCU_RefreshNamePlate(BtlvScuNamePlate *plate, u8 viewPos)
{
    struct BtlPokeParam *mon;
    u16 speciesId;
    u8 pokeId;
    mon = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)plate->scu->monTable, viewPos);
    speciesId = BTL_POKEPARAM_GetValue(mon, 0x10);
    pokeId = BTL_POKEPARAM_GetPokeId(mon);
    if (speciesId != plate->speciesId || pokeId != plate->pokeId) {
        plate->pokeId = pokeId;
        plate->speciesId = speciesId;
        BTLV_SCU_DrawNamePlate(plate);
    }
    plate->phase = 0;
    BTLV_EFFECT_SetPokeEffectValue(viewPos, speciesId);
}



static inline void G2_BG2Mosaic(int enable)
{
    if (enable) *(volatile u16 *)REG_BG2CNT_ADDR |= 0x40;
    else *(volatile u16 *)REG_BG2CNT_ADDR &= ~0x40;
}



static inline void G2_BG3Mosaic(int enable)
{
    if (enable) *(volatile u16 *)REG_BG3CNT_ADDR |= 0x40;
    else *(volatile u16 *)REG_BG3CNT_ADDR &= ~0x40;
}



/* Plate mosaic procedure: ramps the mosaic up, reloads the pixels, ramps it down. Returns 1 when done. */
int BTLV_SCU_ProcNamePlateMosaic(BtlvScuNamePlate *plate)
{
    u8 level;
    switch (plate->phase) {
    case 0:
        REG_MOSAIC = 0;
        if (plate->sideIdx == 0) G2_BG2Mosaic(1);
        else G2_BG3Mosaic(1);
        plate->timer = 0;
        plate->counter = 0;
        GFL_USE_PlaySeDefaultVolume(BTLV_SCU_SE_PLATE_MOSAIC);
        plate->phase++;
        break;
    case 1:
        plate->timer++;
        if (plate->timer > 1) {
            plate->timer = 0;
            plate->counter++;
            level = plate->counter;
            REG_MOSAIC = level | (level << 4);
            if (plate->counter >= 15) plate->phase++;
        }
        break;
    case 2:
        BG_SYS_LoadTileData(plate->bgPlane, BMP_GetPixels(plate->bmp), 0x900, plate->tile);
        plate->phase++;
        break;
    case 3:
        plate->timer++;
        if (plate->timer > 1) {
            plate->timer = 0;
            plate->counter--;
            level = plate->counter;
            REG_MOSAIC = level | (level << 4);
            if (plate->counter == 0) plate->phase++;
        }
        break;
    case 4:
        if (plate->sideIdx == 0) G2_BG2Mosaic(0);
        else G2_BG3Mosaic(0);
        plate->phase++;
        break;
    case 5:
        if (GFL_USE_IsSeqPlaying(BTLV_SCU_SE_PLATE_MOSAIC) == 0) plate->phase++;
        break;
    default:
        return 1;
    }
    return 0;
}


/* Fill the ball states of up to two clients (a double battle shows three
   balls per client). outStates[0] is the side flag, then six ball states. */
void BTLV_SCU_GetBallStates(BtlvScu *scu, u32 *outStates, u32 clientA, u32 clientB, u32 sideFlag)
{
    void *partyLists[2] = {0, 0};
    int partyCounts[2] = {0, 0};
    int i;
    int side;
    s8 slot;
    void *mon;
    MI_CpuFill8(outStates, 0, 28);
    partyLists[0] = BTL_SIDE_GetSlotOfClientThunk((struct BtlSide *)scu->monTable, clientA);
    partyCounts[0] = BTL_SLOT_GetCount(partyLists[0]);
    if (clientB < 4) {
        partyLists[1] = BTL_SIDE_GetSlotOfClientThunk((struct BtlSide *)scu->monTable, clientB);
        partyCounts[1] = BTL_SLOT_GetCount(partyLists[1]);
        if (partyCounts[0] > 3) partyCounts[0] = 3;
        if (partyCounts[1] > 3) partyCounts[1] = 3;
    }
    outStates[0] = sideFlag;
    for (i = 0; i < 6; i++) {
        if (i < partyCounts[0] + partyCounts[1]) {
            if (i < partyCounts[0]) { side = 0; slot = i; }
            else { side = 1; slot = i - partyCounts[0]; }
            mon = BTL_SLOT_GetPokeParam(partyLists[side], (u8)slot);
            if (BTL_POKEPARAM_IsFainted(mon)) outStates[side * 3 + slot + 1] = 2;
            else if (BTL_POKEPARAM_GetMajorStatusIndex(mon)) outStates[side * 3 + slot + 1] = 3;
            else if (!BTL_POKEPARAM_IsAbleToBattle(mon)) outStates[side * 3 + slot + 1] = 0;
            else outStates[side * 3 + slot + 1] = 1;
        }
    }
}


/* Print the wait message (message id 0xF) in the message window. */
void BTLV_SCU_PrintWaitMessage(BtlvScu *scu)
{
    BTL_MSG_GetUiString((struct Strbuf *)scu->textBuf, 0xf);
    BTLV_SCU_StartMessage(scu, scu->textBuf, 0, 0);
}


/*
 * Untraced mid-stream entry point: a plain tail thunk (ldr r3,=T; bx r3) whose pool word names BTLV_SCU_UpdateMessage.
 */
int BTLV_SCU_UpdateWaitMessage(BtlvScu *scu) { return BTLV_SCU_UpdateMessage(scu); }


void BTLV_SCU_NoOp(char *unused)
{
}


/* Fade the screen in from black. */
void BTLV_SCU_StartFadeIn(BtlvScu *scu)
{
    int x = 0x10;
    FADE_Start(1, 0, x, x - 0x13);
}


/* Clear the message window and fade the screen out. */
void BTLV_SCU_ClearWaitWindow(BtlvScu *scu)
{
    BMP_Clear((struct Bmp *)scu->msgWinChars, 12);
    BMP_WIN_TransferChars(scu->msgWin);
    FADE_Start(1, 16, 0, -3);
}


int BTLV_SCU_GetWaitState(BtlvScu *scu)
{
    return BTLV_SCU_IsFadeDone();
}


/* Start the ball window: arm the open step with the party source and states. */
void BTLV_SCU_StartBallWindowOpen(BtlvScu *scu, void **partySource, BtlvBallStates *states)
{
    scu->partySource = partySource;
    scu->ballStates = *states;
    scu->preProc = 0;
    scu->mainProc = BTLV_SCU_StepBallWindowOpen;
    scu->procScu = scu;
    scu->procState = 0;
}


/* Run the ball window steps; returns 1 when no step is left. */
int BTLV_SCU_UpdateBallWindowOpen(BtlvScu *scu)
{
    if (scu->preProc != 0) {
        if (scu->preProc(&scu->procState, scu->procScu) != 0) {
            scu->preProc = 0;
            scu->procState = 0;
        }
        return 0;
    }
    if (scu->mainProc != 0) {
        if (scu->mainProc(&scu->procState, scu->procScu) != 0) {
            scu->mainProc = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


void BTLV_SCU_StartBallWindowRefresh(BtlvScu *scu)
{
    scu->preProc = 0;
    scu->mainProc = BTLV_SCU_StepBallWindowRefresh;
    scu->procScu = scu;
    scu->procState = 0;
}


int BTLV_SCU_UpdateBallWindowRefresh(BtlvScu *scu)
{
    if (scu->preProc != 0) {
        if (scu->preProc(&scu->procState, scu->procScu) != 0) {
            scu->preProc = 0;
            scu->procState = 0;
        }
        return 0;
    }
    if (scu->mainProc != 0) {
        if (scu->mainProc(&scu->procState, scu->procScu) != 0) {
            scu->mainProc = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


void BTLV_SCU_StartBallWindowClose(BtlvScu *scu)
{
    scu->preProc = 0;
    scu->mainProc = BTLV_SCU_StepBallWindowClose;
    scu->procScu = scu;
    scu->procState = 0;
}


int BTLV_SCU_UpdateBallWindowClose(BtlvScu *scu)
{
    if (scu->preProc != 0) {
        if (scu->preProc(&scu->procState, scu->procScu) != 0) {
            scu->preProc = 0;
            scu->procState = 0;
        }
        return 0;
    }
    if (scu->mainProc != 0) {
        if (scu->mainProc(&scu->procState, scu->procScu) != 0) {
            scu->mainProc = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


/* Open step: draw the frame, print the ball line, scroll the window in. */
int BTLV_SCU_StepBallWindowOpen(int *state, BtlvScu *scu)
{
    switch (*state) {
    case 0:
        GF_FONT_SetTextColor(1, 9, 12);
        BMP_WIN_MakeScreen(scu->nameWin);
        BMP_WIN_DrawFrame(scu->nameWin, scu->nameTile, 3);
        BMP_Clear((struct Bmp *)scu->nameWinChars, 12);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(scu->nameWin));
        (*state)++;
        break;
    case 1:
        BTL_MSG_BuildBallStatusOpen((struct Strbuf *)scu->textBuf, scu->ballStates.ball[0], scu->ballStates.ball[1], scu->ballStates.ball[2], scu->ballStates.ball[3], scu->ballStates.ball[4], scu->ballStates.ball[5]);
        PRINTSYS_Print((struct Bmp *)scu->nameWinChars, 0, 0, (struct Strbuf *)scu->textBuf, scu->fontMain);
        (*state)++;
        break;
    case 2:
        BMP_WIN_TransferChars(scu->nameWin);
        (*state)++;
        break;
    case 3:
        BG_SYS_ChangeScrollImmediate(3, 0, 0);
        BG_SYS_ChangeScrollImmediate(3, 3, 0x100);
        GFL_USE_PlaySeDefaultVolume(0x547);
        (*state)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}


/* Refresh step: re-read the party and reprint the ball line. */
int BTLV_SCU_StepBallWindowRefresh(int *state, BtlvScu *scu)
{
    switch (*state) {
    case 0:
        BTL_POKEPARAM_ReadStatsFromMon((struct PokemonParam **)scu->partySource, &scu->ballStates.sideFlag);
        BTL_MSG_BuildBallStatusRefresh((struct Strbuf *)scu->textBuf, scu->ballStates.ball[0], scu->ballStates.ball[1], scu->ballStates.ball[2], scu->ballStates.ball[3], scu->ballStates.ball[4], scu->ballStates.ball[5]);
        BMP_Clear((struct Bmp *)scu->nameWinChars, 12);
        PRINTSYS_Print((struct Bmp *)scu->nameWinChars, 0, 0, (struct Strbuf *)scu->textBuf, scu->fontMain);
        (*state)++;
        break;
    case 1:
        BMP_WIN_TransferChars(scu->nameWin);
        GFL_USE_PlaySeDefaultVolume(0x547);
        (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}


/* Close step: erase the frame and scroll the window out. */
int BTLV_SCU_StepBallWindowClose(int *state, BtlvScu *scu)
{
    int left;
    int top;
    int width;
    int height;
    u8 index;

    switch (*state) {
    case 0:
        left = BMP_WIN_GetPosX(scu->nameWin) - 1;
        top = BMP_WIN_GetPosY(scu->nameWin) - 1;
        width = BMP_WIN_GetWidth(scu->nameWin) + 2;
        height = BMP_WIN_GetHeight(scu->nameWin) + 2;
        index = BMP_WIN_GetBgLayer(scu->nameWin);
        BG_SYS_SetTileEntry(index, 0, (u8)left, (u8)top, (u8)width, (u8)height, 0);
        BG_SYS_PushTile(index);
        GFL_USE_PlaySeDefaultVolume(0x547);
        (*state)++;
        break;
    case 1:
        BG_SYS_ChangeScrollImmediate(3, 0, -0x90);
        BG_SYS_ChangeScrollImmediate(3, 3, 0);
        (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}
