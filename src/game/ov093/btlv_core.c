/*
 * file:     btlv_core.c
 * unit:     yes
 * function: BTLV_CORE_LoadOverlays, BTLV_CORE_UnloadOverlays, BTLV_CORE_ResetDisplay, BTLV_CORE_InitDisplay, BTLV_CORE_ExitDisplay, BTLV_CORE_Create, BTLV_CORE_Delete, BTLV_CORE_Update, BTLV_CORE_StartOpening, BTLV_CORE_PollOpening, BTLV_CORE_GetTaskWork, BTLV_CORE_StepOpeningEntry, BTLV_CORE_StepOpeningDemo, BTLV_CORE_GetPokeParamAtViewPos, BTLV_CORE_StepActionMenu, BTLV_CORE_StepTargetMenu, BTLV_CORE_SetStep, BTLV_CORE_ClearStep, BTLV_CORE_RunStep, BTLV_CORE_StartActionMenu, BTLV_CORE_AbortActionMenu, BTLV_CORE_PollActionMenu, BTLV_CORE_StartMoveMenu, BTLV_CORE_StartMoveMenuForEntry, BTLV_CORE_ReopenMoveMenu, BTLV_CORE_StepMoveMenu, BTLV_CORE_AbortMoveMenu, BTLV_CORE_PollMoveMenu, BTLV_CORE_StartTargetMenu, BTLV_CORE_PollTargetMenu, BTLV_CORE_AbortTargetMenu, BTLV_CORE_AbortInput, BTLV_CORE_CloseMenu, BTLV_CORE_CloseMenuToReselect, BTLV_CORE_IsMenuClosed, BTLV_CORE_InitPartyWork, BTLV_CORE_StartPartyMenu, BTLV_CORE_LockPartyChoice, BTLV_CORE_PollPartyMenu, BTLV_CORE_StartMoveHighlight, BTLV_CORE_StartBagMenu, BTLV_CORE_SkipBagPartyPrompt, BTLV_CORE_PollBagMenu, BTLV_CORE_GetSelectedItem, BTLV_CORE_GetSelectedItemCost, BTLV_CORE_GetItemTargetSlot, BTLV_CORE_GetItemTargetFlag, BTLV_CORE_SaveBagCursors, BTLV_CORE_StartSceneEffect, BTLV_CORE_WaitSceneEffect, BTLV_CORE_StartDamageEffect, BTLV_CORE_WaitDamageEffect, BTLV_CORE_ProcDamageEffect, BTLV_CORE_StartHitAnim, BTLV_CORE_WaitHitAnim, BTLV_CORE_ProcHitAnim, BTLV_CORE_StartMultiDamageEffect, BTLV_CORE_ProcMultiDamageEffect, BTLV_CORE_PlayEffectivenessSe, BTLV_CORE_SetMonShown, BTLV_CORE_StartMonSpriteUpdate, BTLV_CORE_WaitMonSpriteUpdate, BTLV_CORE_StartViewEffect, BTLV_CORE_WaitViewEffect, BTLV_CORE_StartViewEffectEx, BTLV_CORE_WaitViewEffectEx, BTLV_CORE_StartMonReset, BTLV_CORE_WaitMonReset, BTLV_CORE_StartMonRefresh, BTLV_CORE_WaitMonRefresh, BTLV_CORE_StartMonEffectTask, BTLV_CORE_WaitMonEffectTask, BTLV_CORE_StartMonSwap, BTLV_CORE_WaitMonSwap, BTLV_CORE_ProcMonSwap, BTLV_CORE_BuildMessage, BTLV_CORE_CopyMessageBuffer, BTLV_CORE_BuildMessageToBuffer, BTLV_CORE_PrintMessageBuffer, BTLV_CORE_BuildAndPrintMessage, BTLV_CORE_BuildAndPrintMessageFlag, BTLV_CORE_BuildAndPrintMessageNow, BTLV_CORE_PrintSideMessage, BTLV_CORE_PrintTaggedMessage, BTLV_CORE_PrintTrainerMessage, BTLV_CORE_PrintItemUseMessage, BTLV_CORE_WaitMessage, BTLV_CORE_ConsumeMessageFlag, BTLV_CORE_StartPrintMessage, BTLV_CORE_PrintMessageNow, BTLV_CORE_ShowPortrait, BTLV_CORE_UpdatePortraitSlideIn, BTLV_CORE_StartPortraitSlideOut, BTLV_CORE_WaitPortraitSlideOut, BTLV_CORE_ReloadPortrait, BTLV_CORE_UpdatePortraitMosaic, BTLV_CORE_StartViewEffect262, BTLV_CORE_StartViewEffect261, BTLV_CORE_WaitViewEffectDone, BTLV_CORE_StartWaitMessage, BTLV_CORE_UpdateWaitMessage, BTLV_CORE_EndWaitMessage, BTLV_CORE_StartSlotEffect25F, BTLV_CORE_WaitSlotEffect25F, BTLV_CORE_StartMonSpriteLoad, BTLV_CORE_WaitMonSpriteLoad, BTLV_CORE_StartMonSpriteChange, BTLV_CORE_WaitMonSpriteChange, BTLV_CORE_StartMonSpriteChangeAt, BTLV_CORE_WaitMonSpriteChangeAt, BTLV_CORE_StartMonSpriteUnload, BTLV_CORE_WaitMonSpriteUnload, BTLV_CORE_StartRotation, BTLV_CORE_WaitRotation, BTLV_CORE_ProcRotation, BTLV_CORE_InitInputWork, BTLV_CORE_PollWindowModeSelect, BTLV_CORE_CancelWindowModeSelect, BTLV_CORE_StartClearSidePosition, BTLV_CORE_RunProc, BTLV_CORE_ProcClearSidePosition, BTLV_CORE_StartYesNoMenu, BTLV_CORE_PollYesNoMenu, BTLV_CORE_StartMoveForgetScreen, BTLV_CORE_ProcMoveForgetScreen, BTLV_CORE_StartBallWindowOpen, BTLV_CORE_UpdateBallWindowOpen, BTLV_CORE_StartBallWindowRefresh, BTLV_CORE_UpdateBallWindowRefresh, BTLV_CORE_StartBallWindowClose, BTLV_CORE_UpdateBallWindowClose, BTLV_CORE_StartFadeIn, BTLV_CORE_PollFadeInDone, BTLV_CORE_ClearWaitWindow, BTLV_CORE_GetWaitState, BTLV_CORE_StartAutoSelectNotice, BTLV_CORE_PollAutoSelectNotice, BTLV_CORE_PollCounterInput, BTLV_CORE_SetCounterDisplay, BTLV_CORE_ShowCounterValue, BTLV_CORE_SetCounterValueMode
 * address:  0x021E8DC4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btl_dsi_overlay.c, btlv_core.c by tools/splitfile.py.
 *
 * symbols:
 *   BTLV_SCD_Create  0x06899AF0  thumb
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   ov094_id       0x0000005E  data
 *   ov095_id       0x0000005F  data
 *   ov096_id       0x00000060  data
 *   GX_SetBankForLCDC  0x0208068C  arm
 *   GFL_NET_IsNetTypeWifi  0x0203D29C  arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   gBtlvCoreVramBanks 0x021F387C data a4
 *   gBtlvCoreDispConfig 0x021F3850 data a4
 *   gBtlvCoreBgConfig 0x021F3860 data a4
 *   BTLV_EFFECT_Exit  0x021F7808  thumb  ov094
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BTL_CLIENT_GetClientId 0x021D3D70 thumb ov093
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   TCBL_Create 0x0203101C arm
 *   BTLV_SCU_Create 0x021EAF7C thumb ov093
 *   BTL_MSG_Init 0x021EEC78 thumb ov093
 *   gBtlvCoreFileName 0x021F3AC4 data a4
 *   BTLV_SCD_Delete  0x06899DD8  thumb
 *   BTL_MSG_Exit  0x021EECD8  thumb  ov093
 *   BTLV_SCU_Delete  0x021EB234  thumb  ov093
 *   TCBL_Destroy  0x02031140  arm
 *   STRBUF_Delete  0x02045808  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   BTLV_SCD_CreateInput  0x06899BE0  thumb
 *   BTLV_SCD_ShowCounterScreen  0x0689B780  thumb
 *   TCBL_Main  0x020310C4  arm
 *   BTLV_EFFECT_Main  0x021F78E4  thumb  ov094
 *   gBtlvOpeningStepTable  0x021F3840  data  a4
 *   BTLV_EFFECT_CreateSetupFromBattleMain  0x021F745C  thumb  ov094
 *   BTLV_EFFECT_Init  0x021F7544  thumb  ov094
 *   BTLV_SCU_SetupDisplay  0x021EB028  thumb  ov093
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTLV_SCU_StartEntryScene  0x021EB32C  thumb  ov093
 *   BTLV_SCU_RunProc  0x021EB52C  thumb  ov093
 *   BTL_CLIENT_IsRemote  0x021CD9C8  thumb  ov093
 *   BTL_CLIENT_GetQueuedCommandWord  0x021CD9DC  thumb  ov093
 *   BTLV_SCD_CloseInput  0x06899D64  thumb
 *   BTLV_SCD_IsInputIdle  0x06899DB0  thumb
 *   BTLV_SCD_StartActionMenuBackOnly  0x06899F00  thumb
 *   BTLV_SCD_WaitActionMenu  0x06899F28  thumb
 *   BTLV_SCD_StartMoveInfoMenu  0x06899FE8  thumb
 *   BTLV_EFFECT_ResumeVm  0x021F7C0C  thumb  ov094
 *   BTLV_EFFECT_StartDamageTintTask  0x021F7C2C  thumb  ov094
 *   BTLV_EFFECT_StartEffectWithColor  0x021F7CFC  thumb  ov094
 *   BTLV_EFFECT_IsBusy  0x021F7EB4  thumb  ov094
 *   BTLV_EFFECT_GaugeStartHpChangeAnimated  0x021F80FC  thumb  ov094
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb
 *   BTLV_SCU_PlaySeUnlessMainStep  0x021EAF00  thumb  ov093
 *   BTLV_SCU_InitMessage  0x021EAF18  thumb  ov093
 *   BTLV_SCU_AppendMessageArg  0x021EAF50  thumb  ov093
 *   BTLV_SCU_SetMessageParam  0x021EAF78  thumb  ov093
 *   BTLV_SCU_StartWazaEffect  0x021ED118  thumb  ov093
 *   BTLV_SCU_RunWazaProc  0x021ED1B0  thumb  ov093
 *   BTLV_SCU_IsMonDamageAnimDone  0x021ED250  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTLV_CORE_GetPokeParamAtViewPos 0x021E90C8 thumb ov093
 *   BTLV_CORE_StartBagMenu 0x021E9658 thumb ov093
 *   BTLV_CORE_PollBagMenu 0x021E97C4 thumb ov093
 *   BTLV_CORE_BuildAndPrintMessage 0x021E9EE8 thumb ov093
 *   BTLV_CORE_BuildAndPrintMessageNow 0x021E9F30 thumb ov093
 *   BTLV_CORE_PrintItemUseMessage 0x021E9FC8 thumb ov093
 *   BTLV_CORE_WaitMessage 0x021E9FE4 thumb ov093
 *   BTLV_CORE_ConsumeMessageFlag 0x021E9FF4 thumb ov093
 *   BTLV_CORE_StartPrintMessage 0x021EA004 thumb ov093
 *   BTLV_CORE_StartViewEffect262 0x021EA09C thumb ov093
 *   BTLV_CORE_WaitViewEffectDone 0x021EA0BC thumb ov093
 *   BTLV_SCD_StartActionMenu  0x06899ED0  thumb
 *   BTL_MAIN_GetSlotFromViewPos  0x021B8ED8  thumb  ov093
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb  ov093
 *   BTL_CLIENT_GetPointCounter  0x021D3D90  thumb  ov093
 *   BTLV_SCD_StartTargetMenu  0x0689A008  thumb
 *   BTLV_SCD_WaitTargetMenu  0x0689A020  thumb
 *   BTLV_SCD_StartMoveMenu  0x06899F40  thumb
 *   BTLV_SCD_StartRotateMenu  0x06899F64  thumb
 *   BTLV_SCD_WaitMoveMenu  0x06899FD4  thumb
 *   BTLV_SCD_ReopenMenu  0x06899FDC  thumb
 *   BTLV_SCD_IsTargetChosen  0x0689B0CC  thumb
 *   BTLV_SCD_CancelMenus  0x0689A028  thumb
 *   BTLV_EFFECT_StartIntroEffect  0x021F8A78  thumb  ov094
 *   BTLV_SCD_GetInputFlags  0x0689B66C  thumb
 *   BTLV_SCD_CloseInputIfOpen 0x06899D3C thumb ov095
 *   BTL_MAIN_SyncSideParty 0x021B8F5C thumb ov093
 *   BTL_MAIN_IsCommMulti 0x021B8F38 thumb ov093
 *   BTL_MAIN_SyncPartnerSideParty 0x021B8F7C thumb ov093
 *   BTL_MAIN_IsSecondTeamClient 0x021B8FC0 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_GetPositionsPerClientThunk 0x021B99B8 thumb ov093
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb ov094
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   BTL_MAIN_GetGameData 0x021B8748 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_PICK_GetCount  0x0689CB18  thumb
 *   BTL_PICK_GetSlot  0x0689CB2C  thumb
 *   BTLV_SCD_StartInputSlideIn  0x06899CA4  thumb
 *   BTLV_SCD_StartInputSlideOut  0x06899CDC  thumb
 *   BTLV_SCD_IsInputSlideDone  0x06899D04  thumb
 *   BTLV_SCD_OnSlideInDone  0x06899D2C  thumb
 *   BTLV_SCD_OnSlideOutStart  0x06899D30  thumb
 *   BTL_PICK_Push  0x0689CAEC  thumb
 *   B_PLIST_MAIN_Create 0x0220F3E8 thumb ov198
 *   ov196_id 0x000000C4 data
 *   ov198_id 0x000000C6 data
 *   BTL_MAIN_GetMyItem 0x021B90E8 thumb ov093
 *   BTL_MAIN_GetMapMatrix 0x021B90F0 thumb ov093
 *   BTL_MAIN_GetRegulationRules 0x021BA1E4 thumb ov093
 *   BTL_MAIN_CheckSetupStatusFlag 0x021BA1A8 thumb ov093
 *   BTL_SIDE_CountLivingOfClient 0x021B9B04 thumb ov093
 *   BTL_CLIENT_GetSideData 0x021D3D7C thumb ov093
 *   BTL_SLOT_GetCount 0x021B9B94 thumb ov093
 *   BTL_SLOT_GetPokeParam 0x021B9C00 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_ID_IsBagItemUseBlocked  0x0689C90C  thumb
 *   B_BAG_MAIN_Create 0x0220C834 thumb ov197
 *   ov197_id 0x000000C5 data
 *   BTLV_SCD_ShowRotateScreen  0x0689B514  thumb
 *   MYITEM_SAVEDATA_SetBattlePocketCursors  0x020082B8  thumb
 *   MYITEM_SAVEDATA_SetLastBattleItem  0x020082D4  thumb
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   BTLV_SCU_StartMonDamageAnim  0x021ED208  thumb  ov093
 *   BTLV_SCU_StartMonMotion  0x021ED268  thumb  ov093
 *   BTLV_SCU_IsMonMotionDone  0x021ED280  thumb  ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTLV_SCU_UpdateMessage  0x021ECF68  thumb  ov093
 *   BTLV_EFFECT_IsPokeSpriteLoaded  0x021F7F1C  thumb  ov094
 *   BTLV_EFFECT_GetPokeSpriteState  0x021F853C  thumb  ov094
 *   BTLV_EFFECT_StartPokeEffectId285  0x021F7E74  thumb  ov094
 *   BTLV_EFFECT_StartPokeEffectId286  0x021F7E84  thumb  ov094
 *   BTLV_SCU_StartHpGaugeUpdate  0x021ED494  thumb  ov093
 *   BTLV_SCU_IsHpGaugeIdle   0x021ED4D0  thumb  ov093
 *   BTLV_EFFECT_StartEffectOnPoke  0x021F7A28  thumb  ov094
 *   BTLV_EFFECT_StartEffectBetweenPokes  0x021F7AAC  thumb  ov094
 *   BTLV_SCU_StartMonExit  0x021ED294  thumb  ov093
 *   BTLV_SCU_IsMonExitDone   0x021ED2BC  thumb  ov093
 *   BTLV_SCU_LoadAndShowMon   0x021ED2D0  thumb  ov093
 *   BTLV_SCU_IsMonLoadDone   0x021ED304  thumb  ov093
 *   BTLV_SCU_StartMonWithdraw  0x021ED318  thumb  ov093
 *   BTLV_SCU_IsMonWithdrawDone   0x021ED374  thumb  ov093
 *   BTLV_SCU_StartMonSendOut  0x021ED3D4  thumb  ov093
 *   BTLV_SCU_IsMonSendOutDone  0x021ED450  thumb  ov093
 *   BTL_MSG_FormatWithSide  0x021EEE80  thumb  ov093
 *   BTL_MSG_DispatchTagged  0x021EEEF4  thumb  ov093
 *   BTL_MSG_GetUiString  0x021EF694  thumb  ov093
 *   BTL_MSG_BuildUiString  0x021EF6A8  thumb  ov093
 *   BTL_MSG_BuildTrainerString  0x021EF6E8  thumb  ov093
 *   BTL_MSG_BuildItemUse  0x021EF5E8  thumb  ov093
 *   BTL_MSG_BuildPlainEntry  0x021EF664  thumb  ov093
 *   STRBUF_Copy  0x02045838  arm
 *   TPOKE_DATA_FindRecord  0x0202A298  thumb
 *   TPOKE_DATA_ReadRecordString  0x0202A310  thumb
 *   BTLV_SCU_ConsumeMessageEnded   0x021ECF50  thumb  ov093
 *   BTLV_SCU_StartMessage  0x021ECEB8  thumb  ov093
 *   BTLV_SCU_PrintMessageInstant   0x021ECE60  thumb  ov093
 *   BTLV_SCU_StartNamePlate   0x021EDA5C  thumb  ov093
 *   BTLV_SCU_ProcNamePlateAt   0x021EDA94  thumb  ov093
 *   BTLV_SCU_HideNamePlateAt   0x021EDAB0  thumb  ov093
 *   BTLV_SCU_IsNamePlateHiddenAt   0x021EDAE0  thumb  ov093
 *   BTLV_SCU_RefreshNamePlateAt   0x021EDB00  thumb  ov093
 *   BTLV_SCU_ProcNamePlateMosaicAt   0x021EDB20  thumb  ov093
 *   BTLV_EFFECT_SetIntroState  0x021F8A40  thumb  ov094
 *   BTLV_SCU_PrintWaitMessage  0x021EE200  thumb  ov093
 *   BTLV_SCU_UpdateWaitMessage   0x021EE21C  thumb  ov093
 *   BTLV_SCU_NoOp  0x021EE224  thumb  ov093
 *   BTLV_SCU_StartPosCueEffect   0x021ED56C  thumb  ov093
 *   BTLV_SCU_IsPosCueEffectDone   0x021ED57C  thumb  ov093
 *   BTLV_SCU_StartMonFormChange   0x021ED590  thumb  ov093
 *   BTLV_SCU_IsMonFormChangeDone   0x021ED5D8  thumb  ov093
 *   BTLV_SCU_StartMonGraphicSwap  0x021ED6BC  thumb  ov093
 *   BTLV_SCU_IsMonGraphicSwapDone   0x021ED714  thumb  ov093
 *   BTLV_SCU_StartMonGraphicSwapFrom  0x021ED660  thumb  ov093
 *   BTLV_SCU_StartMsgWinFadeOutTask   0x021ED8AC  thumb  ov093
 *   BTLV_SCU_IsMsgWinFadeOutTaskDone   0x021ED8D8  thumb  ov093
 *   BTL_MAIN_GetClientTrainerIndex  0x021B8BEC  thumb  ov093
 *   BTLV_EFFECT_SetPokeSpriteVisible  0x021F84B4  thumb  ov094
 *   BTLV_SCU_HideMonPair  0x021ED4E4  thumb  ov093
 *   BTLV_SCU_ShowMonPair  0x021ED510  thumb  ov093
 *   BTL_SIDE_GetSlotOfClientThunk  0x021B9AF8  thumb  ov093
 *   BTLV_SCD_PollTouchKey  0x0689B524  thumb
 *   BTLV_SCD_OpenChoiceScreen  0x0689B5A4  thumb
 *   BTLV_SCD_CloseInputScreen  0x0689B558  thumb
 *   BTLV_EFFECT_StartPokeSpriteTransitionTask  0x021F8414  thumb  ov094
 *   BTLV_SCU_HideMon  0x021ED53C  thumb  ov093
 *   BTLV_SCU_ShowMon  0x021ED554  thumb  ov093
 *   BTLV_SCD_PollChoiceScreen   0x0689B5CC  thumb  ov095
 *   BTLV_SCU_StartBallWindowOpen 0x021EE264 thumb ov093
 *   BTLV_SCU_UpdateBallWindowOpen 0x021EE2A0 thumb ov093
 *   BTLV_SCU_StartBallWindowRefresh 0x021EE2F8 thumb ov093
 *   BTLV_SCU_UpdateBallWindowRefresh 0x021EE318 thumb ov093
 *   BTLV_SCU_StartBallWindowClose 0x021EE370 thumb ov093
 *   BTLV_SCU_UpdateBallWindowClose 0x021EE390 thumb ov093
 *   BTLV_SCU_StartFadeIn   0x021EE228  thumb  ov093
 *   BTLV_SCU_GetWaitState   0x021EE25C  thumb  ov093
 *   BTLV_SCU_ClearWaitWindow 0x021EE23C thumb ov093
 *   BTLV_SCD_BeginCloseSequence   0x0689B670  thumb  ov095
 *   BTLV_SCD_RunCloseSequence   0x0689B69C  thumb  ov095
 *   BTLV_SCD_PollCounterTouch   0x0689B790  thumb  ov095
 *   BTLV_CORE_GetTaskWork 0x021E9100 thumb ov093
 */
#include "btlv_core_types.h"
/* The original caller passes the item page as a second argument that the definition does not take. */
#ifdef __MWERKS__
#define BTL_ID_IsBagItemUseBlocked BTL_ID_IsBagItemUseBlockedHeader
#endif
#include "../ov095/btl_id_sets.h"
#ifdef __MWERKS__
#undef BTL_ID_IsBagItemUseBlocked
extern int BTL_ID_IsBagItemUseBlocked(u16 itemId, u8 itemUseKind);
#endif
#include "../ov095/btlv_scd.h"
/* The original calls declare the slot arguments of these callees as words. */
#ifdef __MWERKS__
#define BTLV_SCU_StartHpGaugeUpdate BTLV_SCU_StartHpGaugeUpdateHeader
#define BTLV_SCU_LoadAndShowMon BTLV_SCU_LoadAndShowMonHeader
#define BTLV_SCU_StartMonFormChange BTLV_SCU_StartMonFormChangeHeader
#define BTLV_SCU_StartNamePlate BTLV_SCU_StartNamePlateHeader
#define BTLV_SCU_RefreshNamePlateAt BTLV_SCU_RefreshNamePlateAtHeader
#endif
#include "btlv_scu.h"
#ifdef __MWERKS__
#undef BTLV_SCU_StartHpGaugeUpdate
#undef BTLV_SCU_LoadAndShowMon
#undef BTLV_SCU_StartMonFormChange
#undef BTLV_SCU_StartNamePlate
#undef BTLV_SCU_RefreshNamePlateAt
extern void BTLV_SCU_StartHpGaugeUpdate(struct BtlvScu *, s32, u32);
extern void BTLV_SCU_LoadAndShowMon(struct BtlvScu *, u32);
extern void BTLV_SCU_StartMonFormChange(struct BtlvScu *, u32, u32);
extern void BTLV_SCU_StartNamePlate(struct BtlvScu *, u32, u32);
extern void BTLV_SCU_RefreshNamePlateAt(struct BtlvScu *, u32);
#endif
#ifdef __MWERKS__
#define G3D_SYSTEM_Init G3D_SYSTEM_InitHeader
#endif
#include "../arm9/g3d_system.h"
#ifdef __MWERKS__
#undef G3D_SYSTEM_Init
extern void G3D_SYSTEM_Init(u32, u32, u32, u32, u16, u16, void (*)(void));
#endif
#include "../sdk_ioreg.h"

#define BLDCNT (*(volatile u16 *)REG_BLDCNT_ADDR)

#define SBLDCNT (*(volatile u16 *)REG_DB_BLDCNT_ADDR)

#define POWCNT (*(volatile u16 *)REG_POWCNT1_ADDR)

#define DISP3DCNT (*(volatile u16 *)REG_DISP3DCNT_ADDR)

#define BG0CNT (*(volatile u16 *)REG_BG0CNT_ADDR)

struct DispConfig;

struct DispVram;


struct GfFont;

struct Tcbl;

struct S02031140;

struct MsgBank;

struct Rec;

struct BtlvStateEntry {
    u32 state;
    BtlvCoreStepFn step;
};

/* Work of the scripted demo scene, kept in the task work area of the core. */
typedef struct BtlvDemoWork {
    void *msgBank;
    int timer;
} BtlvDemoWork;

#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../arm9/nns_g3d_anm_types.h"
#include "../sdk_nnsfnd.h"
#include "../arm9/gf_overlay.h"



#include "../arm9/gx_vramcnt.h"

#include "../arm9/net.h"


#include "../arm9/bg_sys.h"

#include "../arm9/bmp_win.h"

#include "../arm9/gf_font.h"




extern void G3D_SYSTEM_SetSwapBuffersMode(u32, u32);

#include "../arm9/g3x.h"

#include "../arm9/g2.h"

#include "../ov094/btlv_effect.h"

#include "../arm9/clact.h"



extern void G3D_SYSTEM_Exit(void);

#include "../arm9/gfl_heap_wrap.h"

#include "btl_client.h"
struct Strbuf;

#include "../arm9/strbuf.h"

struct TcblSystem;

#include "../arm9/tcbl.h"
struct BtlMonTable;
struct BtlContext;
struct BtlvCore;
struct BtlvScu;

extern struct BtlvScu *BTLV_SCU_Create(struct BtlvCore *core, struct BtlContext *context, struct BtlMonTable *monTable, void *taskSys, void *fontMain, void *fontSub, u8 clientIndex, s32 heapId);
struct BtlClient;
struct BtlSide;
struct BtlMain;
struct BtlvAuxView;

extern struct BtlvAuxView *BTLV_SCD_Create(struct BtlvCore *core, struct BtlMain *mainModule, struct BtlSide *pokeCon, void *taskList, void *fontMain, struct BtlClient *client, s32 viewParam, u16 heapId);
struct BtlPokeList;
struct BtlMain;

#include "btl_msg.h"


extern void BTLV_SCD_Delete(struct BtlvAuxView *auxView);

extern void BTLV_SCU_Delete(struct BtlvScu *scu);






struct BtlvEffSetup;



extern void BTLV_SCU_SetupDisplay(struct BtlvScu *scu);

extern void BTLV_SCD_CreateInput(struct BtlvAuxView *auxView);


extern void BTLV_SCU_StartEntryScene(struct BtlvScu *scu, u32 flag);

extern int BTLV_SCU_RunProc(struct BtlvScu *scu);



extern void BTLV_SCD_ShowCounterScreen(struct BtlvAuxView *view, void *payload);

#include "../arm9/msgdata.h"

extern void BTLV_SCU_InitMessage(struct BtlvMessage *msg, int kind, int id);

extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *pokeParam);

extern void BTLV_SCU_AppendMessageArg(struct BtlvMessage *msg, u32 val);

extern void BTLV_SCU_SetMessageParam(struct BtlvMessage *msg, u8 param);
union BtlAction;

extern void BTLV_SCD_StartActionMenuBackOnly(struct BtlvAuxView *view, struct BtlPokeParam *pokeParam, u8 canBack, union BtlAction *action);

extern u32 BTLV_SCD_WaitActionMenu(struct BtlvAuxView *auxView);

extern void BTLV_SCD_StartMoveInfoMenu(struct BtlvAuxView *view, struct BtlPokeParam *pokeParam, union BtlAction *action);

extern void BTLV_SCD_CloseInput(struct BtlvAuxView *auxView);

extern int BTLV_SCD_IsInputIdle(struct BtlvAuxView *auxView);

#include "../arm9/waza_tool.h"

extern void BTLV_SCU_StartWazaEffect(struct BtlvScu *scu, int viewPosA, int viewPosB, u32 sceneId, u32 argA, int argB, u8 flags);

extern int BTLV_SCU_RunWazaProc(struct BtlvScu *scu);

extern int BTL_POKEPARAM_GetValue(struct BtlPokeParam *pokeParam, int valueId);



extern void BTLV_SCU_PlaySeUnlessMainStep(struct BtlvCore *core, int seId);





#include "../arm9/gfl_use.h"




void BTLV_CORE_LoadOverlays(unsigned short heapId);

void BTLV_CORE_UnloadOverlays(void);

void BTLV_CORE_ResetDisplay(u16 heapId);

void BTLV_CORE_InitDisplay(u16 heapId);

void BTLV_CORE_ExitDisplay(void);
struct BtlSide;

struct BtlvCore *BTLV_CORE_Create(void *context, void *client, struct BtlSide *monTable, int param, u16 heapId);

void BTLV_CORE_Delete(struct BtlvCore *core);

void BTLV_CORE_Update(struct BtlvCore *core);

void BTLV_CORE_StartOpening(struct BtlvCore *core, u32 state);

int BTLV_CORE_PollOpening(struct BtlvCore *core);

void *BTLV_CORE_GetTaskWork(struct BtlvCore *core, int size);

int BTLV_CORE_StepOpeningEntry(struct BtlvCore *core, int *state, void *work);

int BTLV_CORE_StepOpeningDemo(struct BtlvCore *core, int *state, BtlvDemoWork *w);

struct BtlPokeParam *BTLV_CORE_GetPokeParamAtViewPos(struct BtlvCore *core, u32 viewPos);

void BTLV_CORE_StartBagMenu(struct BtlvCore *core, int isComm, u8 pointCounter, u8 itemId, u8 isLastSlot, u8 foeSemiInvulnerable);

int BTLV_CORE_PollBagMenu(struct BtlvCore *core);

void BTLV_CORE_BuildAndPrintMessage(struct BtlvCore *core, struct BtlvMessage *msg);

void BTLV_CORE_BuildAndPrintMessageNow(struct BtlvCore *core, struct BtlvMessage *msg);

void BTLV_CORE_PrintItemUseMessage(struct BtlvCore *core, u8 clientId, u16 item);

int BTLV_CORE_WaitMessage(struct BtlvCore *core);

int BTLV_CORE_ConsumeMessageFlag(struct BtlvCore *core);

void BTLV_CORE_StartPrintMessage(struct BtlvCore *core, struct Strbuf *buf, u16 speed, PrintCallback callback);

void BTLV_CORE_StartViewEffect262(struct BtlvCore *core, int viewPos);

int BTLV_CORE_WaitViewEffectDone(struct BtlvCore *core, int viewPos);

extern char ov094_id[], ov095_id[], ov096_id[];

extern const struct DispVram gBtlvCoreVramBanks;

extern struct DispConfig gBtlvCoreDispConfig;

extern const struct ClactSysInit gBtlvCoreBgConfig;

extern const char gBtlvCoreFileName[];

extern const struct BtlvStateEntry gBtlvOpeningStepTable[];

void BTLV_CORE_LoadOverlays(unsigned short heapId)
{
    BTLV_CORE_InitDisplay(heapId);
    GF_OVERLAY_Load((sptr)ov094_id);
    GX_SetBankForLCDC(0x80);
    GF_OVERLAY_Load((sptr)ov095_id);
    if (GFL_NET_IsNetTypeWifi() == 0) {
        GF_OVERLAY_Load((sptr)ov096_id);
    }
}

void BTLV_CORE_UnloadOverlays(void)
{
    BTLV_CORE_ExitDisplay();
    GF_OVERLAY_Unload((sptr)ov094_id);
    GF_OVERLAY_Unload((sptr)ov095_id);
    if (GFL_NET_IsNetTypeWifi() == 0) {
        GF_OVERLAY_Unload((sptr)ov096_id);
    }
}

/*
 * wrapper over BTLV_CORE_ExitDisplay, BTLV_CORE_InitDisplay
 */
void BTLV_CORE_ResetDisplay(u16 heapId)
{
    BTLV_CORE_ExitDisplay();
    BTLV_CORE_InitDisplay(heapId);
}

/*
 * lever: the POWCNT read/OR/write is spelled as assignment, not compound assignment.
 * volatile: 021E8E60 POWCNT; 021E8E8E,021E8E9C,021E8EA4 DISP3DCNT; 021E8EBE BG0CNT.
 */
void BTLV_CORE_InitDisplay(u16 heapId)
{
    BG_SYS_Create(heapId);
    BMP_WIN_Init(heapId);
    GF_FONT_InitTextColor();
    BG_SYS_SetVramBanks(&gBtlvCoreVramBanks);
    BLDCNT = 0;
    SBLDCNT = 0;
    POWCNT = (u16)(POWCNT | 0x8000);
    BG_SYS_SetGraphicsMode(&gBtlvCoreDispConfig);
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, heapId, 0);
    G3D_SYSTEM_SetSwapBuffersMode(1, 0);
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 8);
    DISP3DCNT &= (u16)~0x3020;
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 16);
    G3X_SetFog(0, 0, 0, 0);
    BG0CNT = (u16)((BG0CNT & ~3) | 1);
    G2x_SetBlendAlpha_((void *)&BLDCNT, 2, 0x3d, 0x1f, 3);
    CLACT_InitSystem(&gBtlvCoreBgConfig, (const struct DispVramCfg *)(&gBtlvCoreVramBanks), heapId);
}

void BTLV_CORE_ExitDisplay(void)
{
    BTLV_EFFECT_Exit();
    CLACT_ExitSystem();
    BMP_WIN_Exit();
    BG_SYS_Delete();
    G3D_SYSTEM_Exit();
}

struct BtlvCore *BTLV_CORE_Create(void *context, void *client, struct BtlSide *monTable, int param, u16 heapId)
{
    struct BtlvCore *core;
    core = GFL_HEAP_Alloc(heapId, sizeof(*core), 0, gBtlvCoreFileName, 0x12d);
    core->context = context;
    core->client = client;
    core->monTable = (struct BtlMonTable *)monTable;
    core->clientIndex = BTL_CLIENT_GetClientId(client);
    core->state = 4;
    core->heapId = heapId;
    core->msgBuffer = (struct Strbuf *)STRBUF_Create(0x200, heapId);
    core->fontMain = GF_FONT_Create(0x17, 0, 0, 0, heapId);
    core->fontSub = GF_FONT_Create(0x17, 2, 0, 0, heapId);
    core->taskList = TCBL_Create(heapId, heapId, 0x40, 0x80);
    core->sceneUnit = BTLV_SCU_Create((struct BtlvCore *)core, (struct BtlContext *)core->context, (struct BtlMonTable *)monTable, (void *)core->taskList, (void *)core->fontMain, (void *)core->fontSub, core->clientIndex, heapId);
    core->auxView = BTLV_SCD_Create(core, (struct BtlMain *)core->context, (struct BtlSide *)monTable, core->taskList, core->fontMain, core->client, param, heapId);
    core->stepFn = 0;
    core->stepState = 0;
    core->subStep = 0;
    BTL_MSG_Init((struct BtlMain *)context, core->clientIndex, (struct BtlPokeList *)monTable, heapId);
    return core;
}

/* Destroys the battle view core: message system, aux view, scene unit, task list, message buffer, fonts and the core itself. */
void BTLV_CORE_Delete(struct BtlvCore *core)
{
    BTL_MSG_Exit();
    BTLV_SCD_Delete(core->auxView);
    BTLV_SCU_Delete(core->sceneUnit);
    TCBL_Destroy(core->taskList);
    STRBUF_Delete((struct Strbuf *)core->msgBuffer);
    GF_FONT_Delete(core->fontMain);
    GF_FONT_Delete(core->fontSub);
    GFL_HEAP_Free(core);
}

/* Runs the task list of the view core and the effect system once per frame. */
void BTLV_CORE_Update(struct BtlvCore *core)
{
    TCBL_Main(core->taskList);
    BTLV_EFFECT_Main();
}

/* Starts the opening step of the battle view: state 0 is the normal entry scene, state 1 the scripted demo scene. */
void BTLV_CORE_StartOpening(struct BtlvCore *core, u32 state)
{
    u32 i;

    for (i = 0; i < 2; i++) {
        if (state == gBtlvOpeningStepTable[i].state) {
            core->state = state;
            core->stepFn = gBtlvOpeningStepTable[i].step;
            core->stepState = 0;
            return;
        }
    }
}

/* Runs the opening step; nonzero once it has finished (state 4 marks the idle core). */
int BTLV_CORE_PollOpening(struct BtlvCore *core)
{
    if (core->state != 4) {
        if (core->stepFn(core, &core->stepState, core->task.work) != 0) {
            core->state = 4;
            core->stepFn = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}

/* 021E9100  adds r0,#0x2c */
/*
 * Leaf with no calls and no pool; 2 instructions, 4 bytes: adds r0, #0x2c; bx lr.
 */
void *BTLV_CORE_GetTaskWork(struct BtlvCore *core, int size) { return core->task.work; }

/* Opening step 0: builds the scene, shows the entry scene, and in a remote client shows the queued command counter. */
int BTLV_CORE_StepOpeningEntry(struct BtlvCore *core, int *state, void *work)
{
    void *scene;

    switch (*state) {
    case 0:
        scene = BTLV_EFFECT_CreateSetupFromBattleMain((u8 *)core->context, core->sceneUnit, core->heapId);
        BTLV_EFFECT_Init(scene, core->fontSub, core->heapId);
        GFL_HEAP_Free(scene);
        BTLV_SCU_SetupDisplay(core->sceneUnit);
        BTLV_SCD_CreateInput(core->auxView);
        (*state)++;
        break;
    case 1:
        BTLV_SCU_StartEntryScene(core->sceneUnit, BTL_CLIENT_IsMainStepActive(core->client));
        (*state)++;
        break;
    case 2:
        if (BTLV_SCU_RunProc(core->sceneUnit) != 0) {
            if (BTL_CLIENT_IsRemote(core->client) != 0) {
                core->counterCmd.current = 1;
                core->counterCmd.target = 1;
                core->counterCmd.commandWord = BTL_CLIENT_GetQueuedCommandWord(core->client);
                core->counterCmd.mode = 0;
                if (BTL_CLIENT_IsMainStepActive(core->client) == 0) {
                    BTLV_SCD_ShowCounterScreen(core->auxView, &core->counterCmd);
                }
            }
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Opening step 1: the scripted demo scene. The first Pokemon uses move 1 and the second one move 43
 * with their use messages, then the messages of the demo text bank are shown and the music is changed.
 */
int BTLV_CORE_StepOpeningDemo(struct BtlvCore *core, int *state, BtlvDemoWork *demo)
{
    switch (*state) {
    case 0: {
        void *scene = BTLV_EFFECT_CreateSetupFromBattleMain((u8 *)core->context, core->sceneUnit, core->heapId);
        BTLV_EFFECT_Init(scene, core->fontSub, core->heapId);
        GFL_HEAP_Free(scene);
        BTLV_SCU_SetupDisplay(core->sceneUnit);
        BTLV_SCD_CreateInput(core->auxView);
        demo->msgBank = MSGDATA_CreateFromArchive(0, 2, 0x14, core->heapId);
        demo->timer = 0;
        (*state)++;
        break;
    }
    case 1:
        BTLV_SCU_StartEntryScene(core->sceneUnit, 0);
        (*state)++;
        break;
    case 2:
        if (BTLV_SCU_RunProc(core->sceneUnit)) {
            struct BtlvMessage msg;
            struct BtlPokeParam *pokeParam = BTLV_CORE_GetPokeParamAtViewPos(core, 0);
            BTLV_SCU_InitMessage(&msg, 1, 0x45);
            BTLV_SCU_AppendMessageArg(&msg, BTL_POKEPARAM_GetPokeId(pokeParam));
            BTLV_SCU_SetMessageParam(&msg, 0);
            BTLV_CORE_BuildAndPrintMessageNow(core, &msg);
            (*state)++;
        }
        break;
    case 3:
        core->pokeParam = BTLV_CORE_GetPokeParamAtViewPos(core, 0);
        core->pokeId = BTL_POKEPARAM_GetPokeId(core->pokeParam);
        core->actionCursor = 0;
        core->actionResult = 0;
        core->canBack = 0;
        BTLV_SCD_StartActionMenuBackOnly(core->auxView, core->pokeParam, core->canBack, 0);
        (*state)++;
        break;
    case 4:
        if (BTLV_SCD_WaitActionMenu(core->auxView)) {
            BTLV_SCD_StartMoveInfoMenu(core->auxView, core->pokeParam, (union BtlAction *)core->actionCursor);
            (*state)++;
        }
        break;
    case 5:
        if (BTLV_SCD_WaitActionMenu(core->auxView)) {
            BTLV_CORE_PrintItemUseMessage(core, BTL_POKEPARAM_GetPokeId(BTLV_CORE_GetPokeParamAtViewPos(core, 0)), 1);
            BTLV_SCD_CloseInput(core->auxView);
            (*state)++;
        }
        break;
    case 6:
        if (BTLV_CORE_WaitMessage(core) && BTLV_SCD_IsInputIdle(core->auxView)) {
            BTLV_SCU_StartWazaEffect(core->sceneUnit, 0, 1, 1, WAZA_TOOL_GetParam(1, 0x1B), 0, 0);
            (*state)++;
        }
        break;
    case 7:
        if (BTLV_SCU_RunWazaProc(core->sceneUnit)) {
            BTLV_EFFECT_GaugeStartHpChangeAnimated(1, BTL_POKEPARAM_GetValue(BTLV_CORE_GetPokeParamAtViewPos(core, 1), 0xE) / 6);
            BTLV_EFFECT_StartDamageTintTask(1, 1);
            BTLV_SCU_PlaySeUnlessMainStep(core, 0x564);
            (*state)++;
        }
        break;
    case 8:
        if (BTLV_SCU_IsMonDamageAnimDone(core->sceneUnit)) {
            BTLV_CORE_PrintItemUseMessage(core, BTL_POKEPARAM_GetPokeId(BTLV_CORE_GetPokeParamAtViewPos(core, 1)), 0x2B);
            (*state)++;
        }
        break;
    case 9:
        if (BTLV_CORE_WaitMessage(core)) {
            BTLV_SCU_StartWazaEffect(core->sceneUnit, 1, 0, 0x2B, WAZA_TOOL_GetParam(0x2B, 0x1B), 0, 0);
            (*state)++;
        }
        break;
    case 10:
        if (BTLV_SCU_RunWazaProc(core->sceneUnit)) {
            BTLV_CORE_StartViewEffect262(core, 0);
            (*state)++;
        }
        break;
    case 11:
        if (BTLV_CORE_WaitViewEffectDone(core, 0)) {
            struct BtlvMessage msg;
            struct BtlPokeParam *pokeParam = BTLV_CORE_GetPokeParamAtViewPos(core, 0);
            BTLV_SCU_InitMessage(&msg, 2, 0x5D);
            BTLV_SCU_AppendMessageArg(&msg, BTL_POKEPARAM_GetPokeId(pokeParam));
            BTLV_SCU_SetMessageParam(&msg, 0);
            BTLV_CORE_BuildAndPrintMessage(core, &msg);
            (*state)++;
        }
        break;
    case 12:
        if (BTLV_CORE_WaitMessage(core)) {
            MSGDATA_ReadString(demo->msgBank, 0, (struct Strbuf *)core->msgBuffer);
            BTLV_CORE_StartPrintMessage(core, core->msgBuffer, 0, 0);
            demo->timer = 0x3C;
            (*state)++;
        }
        break;
    case 13:
        if (BTLV_CORE_WaitMessage(core) && --demo->timer == 0) {
            BTLV_SCD_StartActionMenuBackOnly(core->auxView, core->pokeParam, core->canBack, (union BtlAction *)core->actionCursor);
            (*state)++;
        }
        break;
    case 14:
        if (BTLV_SCD_WaitActionMenu(core->auxView)) {
            BTLV_CORE_StartBagMenu(core, 2, 0, 0, 1, 0);
            (*state)++;
        }
        break;
    case 15:
        if (BTLV_CORE_PollBagMenu(core)) {
            MSGDATA_ReadString(demo->msgBank, 1, (struct Strbuf *)core->msgBuffer);
            BTLV_CORE_StartPrintMessage(core, core->msgBuffer, 0, 0);
            BTLV_SCD_CloseInput(core->auxView);
            (*state)++;
        }
        break;
    case 16:
        if (BTLV_CORE_WaitMessage(core) && !BTLV_EFFECT_IsBusy()) {
            BTLV_EFFECT_StartEffectWithColor(1, 4, 3, 1, 0);
            (*state)++;
        }
        break;
    case 17:
        if (!BTLV_EFFECT_IsBusy()) {
            struct BtlvMessage msg;
            struct BtlPokeParam *pokeParam = BTLV_CORE_GetPokeParamAtViewPos(core, 1);
            BTLV_SCU_InitMessage(&msg, 1, 0x41);
            BTLV_SCU_AppendMessageArg(&msg, BTL_POKEPARAM_GetPokeId(pokeParam));
            BTLV_CORE_BuildAndPrintMessage(core, &msg);
            (*state)++;
        }
        break;
    case 18:
        if (BTLV_CORE_ConsumeMessageFlag(core)) {
            GFL_USE_CancelChangeAndPlayBgm(0x518, 0xFFFF);
        }
        if (BTLV_CORE_WaitMessage(core)) {
            (*state)++;
        }
        break;
    case 19:
        if (!GFL_USE_IsBgmPlaying()) {
            BTLV_EFFECT_ResumeVm();
            MSGDATA_Delete((struct MsgBank *)demo->msgBank);
            (*state)++;
        }
        break;
    case 20:
        return 1;
    }
    return 0;
}

struct BtlExpResult;



#include "btl_main.h"



extern void BTLV_SCD_StartActionMenu(struct BtlvAuxView *view, struct BtlPokeParam *pokeParam, u8 canBack, u8 clientSlot, union BtlAction *action);

extern void BTLV_SCD_StartTargetMenu(struct BtlvAuxView *view, struct BtlPokeParam *pokeParam, union BtlAction *action);

extern int BTLV_SCD_WaitTargetMenu(struct BtlvAuxView *auxView);

extern void BTLV_SCD_StartMoveMenu(struct BtlvAuxView *view, struct BtlPokeParam *pokeParam, union BtlAction *action);
struct BtlvRotateSet;

extern void BTLV_SCD_StartRotateMenu(struct BtlvAuxView *view, struct BtlvRotateSet *rotateSet, union BtlAction *action);

extern int BTLV_SCD_WaitMoveMenu(struct BtlvAuxView *auxView);

extern void BTLV_SCD_ReopenMenu(struct BtlvAuxView *auxView);

extern u8 BTLV_SCD_IsTargetChosen(struct BtlvAuxView *auxView);


extern void BTLV_SCD_CancelMenus(struct BtlvAuxView *auxView);

extern void BTLV_SCD_CloseInputIfOpen(struct BtlvAuxView *auxView);







extern u8 *BTLV_SCD_GetInputFlags(struct BtlvAuxView *auxView);




struct BtlPickList;

#include "../ov095/btl_pick_list.h"


extern void BTLV_SCD_StartInputSlideIn(struct BtlvAuxView *view, u32 mode);

extern int BTLV_SCD_IsInputSlideDone(struct BtlvAuxView *auxView);

extern void BTLV_SCD_OnSlideInDone(struct BtlvAuxView *auxView);


extern void BTLV_SCD_StartInputSlideOut(struct BtlvAuxView *auxView);

extern void BTLV_SCD_OnSlideOutStart(struct BtlvAuxView *auxView);

#include "../ov198/b_plist_main.h"




struct BtlSide;


struct BtlSideSlot;



#include "btl_pokeparam.h"


#include "../ov197/b_bag_main.h"
struct BagCursor;

#include "../arm9/myitem_savedata.h"



extern void BTLV_SCU_StartMonDamageAnim(struct BtlvScu *scu, u8 slot, u16 animId, int mainStepActive);

extern void BTLV_SCU_StartMonMotion(struct BtlvScu *scu, u8 slot, u32 animId);

extern int BTLV_SCU_IsMonMotionDone(struct BtlvScu *scu);


extern int BTLV_SCU_UpdateMessage(struct BtlvScu *scu);








extern void BTLV_SCU_StartMonExit(struct BtlvScu *scu, int slot, u32 mainStepActive);

extern void BTLV_SCU_StartMonWithdraw(struct BtlvScu *scu, u16 viewPos, u16 effectId, int mainStepActive);

extern void BTLV_SCU_StartMonSendOut(struct BtlvScu *scu, u8 slot, int clientId, u8 pokeIdx, int mainStepActive);

extern int BTLV_SCU_IsMonSendOutDone(struct BtlvScu *scu);









#include "../arm9/tpoke_data.h"


extern void BTLV_SCU_StartMessage(struct BtlvScu *scu, struct Strbuf *buf, u16 speed, PrintCallback callback);


extern void BTLV_SCU_PrintWaitMessage(struct BtlvScu *scu);

extern int BTLV_SCU_UpdateWaitMessage(struct BtlvScu *scu);

extern void BTLV_SCU_NoOp(char *unused);

extern void BTLV_SCU_StartPosCueEffect(struct BtlvScu *unused, s32 viewPos);

extern int BTLV_SCU_IsPosCueEffectDone(struct BtlvScu *unused, s32 viewPos);

extern void BTLV_SCU_StartMonGraphicSwap(struct BtlvScu *scu, u32 viewPos, u32 mode);

extern void BTLV_SCU_StartMonGraphicSwapFrom(struct BtlvScu *scu, u32 viewPos, u32 srcViewPos, u32 mode);



extern void BTLV_SCU_HideMonPair(struct BtlvScu *scu, int monSlotA, int monSlotB);

extern int BTLV_SCU_ShowMonPair(struct BtlvScu *scu, int monSlotA, int monSlotB);


extern void BTLV_SCD_ShowRotateScreen(struct BtlvAuxView *view, void *payload);





extern u32 BTLV_SCU_IsMonWithdrawDone(struct BtlvScu *scu);


extern u32 BTLV_SCU_IsMonFormChangeDone(struct BtlvScu *scu);

extern u32 BTLV_SCU_IsMonGraphicSwapDone(struct BtlvScu *scu);

extern void BTLV_SCU_StartMsgWinFadeOutTask(struct BtlvScu *scu);

extern u32 BTLV_SCU_IsMsgWinFadeOutTaskDone(struct BtlvScu *scu);

extern u32 BTLV_SCU_ConsumeMessageEnded(struct BtlvScu *scu);

extern void BTLV_SCU_PrintMessageInstant(struct BtlvScu *scu, struct Strbuf *buf);



extern void BTLV_SCU_HideNamePlateAt(struct BtlvScu *scu, u32 slot);




extern int BTLV_SCD_PollTouchKey(struct BtlvAuxView *auxView, u8 *outMode);

extern void BTLV_SCD_CloseInputScreen(struct BtlvAuxView *auxView);


extern void BTLV_SCU_HideMon(struct BtlvScu *scu, int monSlot);

extern int BTLV_SCU_ShowMon(struct BtlvScu *scu, int monSlot);
struct BtlvYesNoWork;

extern void BTLV_SCD_OpenChoiceScreen(struct BtlvAuxView *view, struct BtlvYesNoWork *value);

extern int BTLV_SCD_PollChoiceScreen(struct BtlvAuxView *view, u32 *outChoice);

extern void BTLV_SCD_BeginCloseSequence(struct BtlvAuxView *auxView);

extern int BTLV_SCD_RunCloseSequence(struct BtlvAuxView *auxView);

struct BtlvBallStates;

extern void BTLV_SCU_StartBallWindowOpen(struct BtlvScu *scu, void **partySource, struct BtlvBallStates *states);

extern int BTLV_SCU_UpdateBallWindowOpen(struct BtlvScu *scu);

extern void BTLV_SCU_StartBallWindowRefresh(struct BtlvScu *scu);

extern int BTLV_SCU_UpdateBallWindowRefresh(struct BtlvScu *scu);

extern void BTLV_SCU_StartBallWindowClose(struct BtlvScu *scu);

extern int BTLV_SCU_UpdateBallWindowClose(struct BtlvScu *scu);


extern void BTLV_SCU_ClearWaitWindow(struct BtlvScu *scu);


int BTLV_CORE_StepActionMenu(struct BtlvCore *core, int *state, void *work);

int BTLV_CORE_StepTargetMenu(struct BtlvCore *core, int *state, void *work);

void BTLV_CORE_SetStep(struct BtlvCore *core, BtlvCoreStepFn stepFn);

void BTLV_CORE_ClearStep(struct BtlvCore *core);

int BTLV_CORE_RunStep(struct BtlvCore *core);

void BTLV_CORE_StartActionMenu(struct BtlvCore *core, struct BtlPokeParam *pokeParam, int canBack, u8 *cursor);

void BTLV_CORE_AbortActionMenu(struct BtlvCore *core);

int BTLV_CORE_PollActionMenu(struct BtlvCore *core);

void BTLV_CORE_StartMoveMenu(struct BtlvCore *core, struct BtlPokeParam *pokeParam, u8 *cursor);

void BTLV_CORE_StartMoveMenuForEntry(struct BtlvCore *core, struct BtlPokeParam **entry, u8 *cursor);

void BTLV_CORE_ReopenMoveMenu(struct BtlvCore *core);

int BTLV_CORE_StepMoveMenu(struct BtlvCore *core, int *state, void *work);

void BTLV_CORE_AbortMoveMenu(struct BtlvCore *core);

u32 BTLV_CORE_PollMoveMenu(struct BtlvCore *core);

void BTLV_CORE_StartTargetMenu(struct BtlvCore *core, struct BtlPokeParam *pokeParam, u8 *cursor);

int BTLV_CORE_PollTargetMenu(struct BtlvCore *core);

void BTLV_CORE_AbortTargetMenu(struct BtlvCore *core);

void BTLV_CORE_AbortInput(struct BtlvCore *core);

void BTLV_CORE_CloseMenu(struct BtlvCore *core);

void BTLV_CORE_CloseMenuToReselect(struct BtlvCore *core);

int BTLV_CORE_IsMenuClosed(struct BtlvCore *core);

void BTLV_CORE_InitPartyWork(struct BtlvCore *core, struct B_PlistHost *plist, int mode, u8 slot, int modeParam);

void BTLV_CORE_StartPartyMenu(struct BtlvCore *core, const BtlSlotChoices *slotChoices, int slot, int canCancel, BtlPickList *choiceFlags);

void BTLV_CORE_LockPartyChoice(struct BtlvCore *core);

int BTLV_CORE_PollPartyMenu(struct BtlvCore *core);

void BTLV_CORE_StartMoveHighlight(struct BtlvCore *core, u8 slot, u8 kind);

void BTLV_CORE_SkipBagPartyPrompt(struct BtlvCore *core);

u16 BTLV_CORE_GetSelectedItem(struct BtlvCore *core);

u8 BTLV_CORE_GetSelectedItemCost(struct BtlvCore *core);

u8 BTLV_CORE_GetItemTargetSlot(struct BtlvCore *core);

u8 BTLV_CORE_GetItemTargetFlag(struct BtlvCore *core);

void BTLV_CORE_SaveBagCursors(struct BtlvCore *core);

void BTLV_CORE_StartSceneEffect(struct BtlvCore *core, u32 slotFrom, u32 slotTo, u32 sceneId, u32 argA, u32 argB, u8 flags);

int BTLV_CORE_WaitSceneEffect(struct BtlvCore *core);

void BTLV_CORE_StartDamageEffect(struct BtlvCore *core, u32 animId, u32 slot, u32 effectiveness);

int BTLV_CORE_WaitDamageEffect(struct BtlvCore *core);

int BTLV_CORE_ProcDamageEffect(int *state, struct BtlvCore *core);

void BTLV_CORE_StartHitAnim(struct BtlvCore *core, u32 animId, int slot, int effectiveness);

int BTLV_CORE_WaitHitAnim(struct BtlvCore *core);

int BTLV_CORE_ProcHitAnim(int *state, struct BtlvCore *core);

void BTLV_CORE_StartMultiDamageEffect(struct BtlvCore *core, u32 count, int effectiveness, const u8 *pokeIds, u16 animId);

int BTLV_CORE_ProcMultiDamageEffect(struct BtlvCore *core);

void BTLV_CORE_PlayEffectivenessSe(struct BtlvCore *core, int effectiveness);

void BTLV_CORE_SetMonShown(struct BtlvCore *core, int viewPos, int shown);

void BTLV_CORE_StartMonSpriteUpdate(struct BtlvCore *core, int slot);

int BTLV_CORE_WaitMonSpriteUpdate(struct BtlvCore *core);

void BTLV_CORE_StartViewEffect(struct BtlvCore *core, int viewPos, int effectId);

int BTLV_CORE_WaitViewEffect(struct BtlvCore *core);

void BTLV_CORE_StartViewEffectEx(struct BtlvCore *core, int viewPos, int effectId, u32 param);

int BTLV_CORE_WaitViewEffectEx(void *viewPos);

void BTLV_CORE_StartMonReset(struct BtlvCore *core, int slot);

int BTLV_CORE_WaitMonReset(struct BtlvCore *core);

void BTLV_CORE_StartMonRefresh(struct BtlvCore *core, u32 slot);

int BTLV_CORE_WaitMonRefresh(struct BtlvCore *core);

void BTLV_CORE_StartMonEffectTask(struct BtlvCore *core, u16 viewPos, u16 effectId);

int BTLV_CORE_WaitMonEffectTask(struct BtlvCore *core);

void BTLV_CORE_StartMonSwap(struct BtlvCore *core, u8 slot, u8 clientId, u8 pokeIdx);

int BTLV_CORE_WaitMonSwap(struct BtlvCore *core);

int BTLV_CORE_ProcMonSwap(int *state, struct BtlvCore *core);

void BTLV_CORE_BuildMessage(struct BtlvMessage *msg, struct Strbuf *buf);

void BTLV_CORE_CopyMessageBuffer(struct BtlvCore *core, struct Strbuf *src);

void BTLV_CORE_BuildMessageToBuffer(struct BtlvCore *core, struct BtlvMessage *msg);

void BTLV_CORE_PrintMessageBuffer(struct BtlvCore *core);

void BTLV_CORE_BuildAndPrintMessageFlag(struct BtlvCore *core, struct BtlvMessage *msg, PrintCallback callback);

void BTLV_CORE_PrintSideMessage(struct BtlvCore *core, u16 msgId, u32 *args);

void BTLV_CORE_PrintTaggedMessage(struct BtlvCore *core, u16 msgId, u32 *args);

int BTLV_CORE_PrintTrainerMessage(struct BtlvCore *core, u16 trainerId, u16 msgIndex);

void BTLV_CORE_PrintMessageNow(struct BtlvCore *core, struct Strbuf *buf);

void BTLV_CORE_ShowPortrait(struct BtlvCore *core, u32 slot, u32 flag);

int BTLV_CORE_UpdatePortraitSlideIn(struct BtlvCore *core, u32 slot);

void BTLV_CORE_StartPortraitSlideOut(struct BtlvCore *core, u32 slot);

int BTLV_CORE_WaitPortraitSlideOut(struct BtlvCore *core, u32 slot);

void BTLV_CORE_ReloadPortrait(struct BtlvCore *core, u32 slot);

int BTLV_CORE_UpdatePortraitMosaic(struct BtlvCore *core, u32 slot);

void BTLV_CORE_StartViewEffect261(struct BtlvCore *core, int viewPos);

void BTLV_CORE_StartWaitMessage(struct BtlvCore *core);

int BTLV_CORE_UpdateWaitMessage(struct BtlvCore *core);

void BTLV_CORE_EndWaitMessage(struct BtlvCore *core);

void BTLV_CORE_StartSlotEffect25F(struct BtlvCore *core, u32 slot);

int BTLV_CORE_WaitSlotEffect25F(struct BtlvCore *core, u32 slot);

void BTLV_CORE_StartMonSpriteLoad(struct BtlvCore *core, u32 slot, u32 mode);

int BTLV_CORE_WaitMonSpriteLoad(struct BtlvCore *core);

void BTLV_CORE_StartMonSpriteChange(struct BtlvCore *core, int viewPos);

int BTLV_CORE_WaitMonSpriteChange(struct BtlvCore *core);

void BTLV_CORE_StartMonSpriteChangeAt(struct BtlvCore *core, u32 viewPos, u32 srcViewPos);

int BTLV_CORE_WaitMonSpriteChangeAt(struct BtlvCore *core);

void BTLV_CORE_StartMonSpriteUnload(struct BtlvCore *core);

int BTLV_CORE_WaitMonSpriteUnload(struct BtlvCore *core);

void BTLV_CORE_StartRotation(struct BtlvCore *core, u32 clientId, u32 rotateA, u32 rotateB, u8 posA, u8 posB);

int BTLV_CORE_WaitRotation(struct BtlvCore *core);

int BTLV_CORE_ProcRotation(int *state, struct BtlvCore *core);

void BTLV_CORE_InitInputWork(struct BtlvCore *core, u8 unused);

int BTLV_CORE_PollWindowModeSelect(struct BtlvCore *core, u8 *outMode);

void BTLV_CORE_CancelWindowModeSelect(struct BtlvCore *core);

void BTLV_CORE_StartClearSidePosition(struct BtlvCore *core, u32 clientId, u32 kind);

int BTLV_CORE_RunProc(struct BtlvCore *core);

int BTLV_CORE_ProcClearSidePosition(int *state, struct BtlvCore *core);

void BTLV_CORE_StartYesNoMenu(struct BtlvCore *core, struct BtlvMessage *yesMsg, struct BtlvMessage *noMsg, u32 mode);

int BTLV_CORE_PollYesNoMenu(struct BtlvCore *core, int *outResult);

void BTLV_CORE_StartMoveForgetScreen(struct BtlvCore *core, u8 pokeSlot, int moveId);

int BTLV_CORE_ProcMoveForgetScreen(struct BtlvCore *core, u8 *outSlot);

void BTLV_CORE_StartBallWindowOpen(struct BtlvCore *core, void **pokeParam, struct BtlExpResult *result);

int BTLV_CORE_UpdateBallWindowOpen(struct BtlvCore *core);

void BTLV_CORE_StartBallWindowRefresh(struct BtlvCore *core);

int BTLV_CORE_UpdateBallWindowRefresh(struct BtlvCore *core);

void BTLV_CORE_StartBallWindowClose(struct BtlvCore *core);

int BTLV_CORE_UpdateBallWindowClose(struct BtlvCore *core);

void BTLV_CORE_StartFadeIn(struct BtlvCore *core);

int BTLV_CORE_PollFadeInDone(struct BtlvCore *core);

void BTLV_CORE_ClearWaitWindow(struct BtlvCore *core);

int BTLV_CORE_GetWaitState(struct BtlvCore *core);

void BTLV_CORE_StartAutoSelectNotice(struct BtlvCore *core);

int BTLV_CORE_PollAutoSelectNotice(struct BtlvCore *core);

int BTLV_CORE_PollCounterInput(struct BtlvCore *core);

void BTLV_CORE_SetCounterDisplay(struct BtlvCore *core, u32 current, u32 target);

void BTLV_CORE_ShowCounterValue(struct BtlvCore *core, int value);

void BTLV_CORE_SetCounterValueMode(struct BtlvCore *core, int value, int mode);

extern u8 ov196_id[];

extern u8 ov198_id[];

extern u8 ov197_id[];

/* The battle Pokemon on a view position of the core's client side. */
struct BtlPokeParam *BTLV_CORE_GetPokeParamAtViewPos(struct BtlvCore *core, u32 viewPos)
{
    return (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)core->monTable, BTL_MAIN_GetSlotFromViewPos((struct BtlMain *)core->context, viewPos));
}

/* Step of the action menu (Fight, Bag, Pokemon, Run): opens it on the aux view, then waits for the choice. */
int BTLV_CORE_StepActionMenu(struct BtlvCore *core, int *state, void *work)
{
    switch (*state) {
    case 0:
        BTLV_SCD_StartActionMenu(core->auxView, core->pokeParam, core->canBack, BTL_CLIENT_GetPointCounter(core->client), (union BtlAction *)core->actionCursor);
        (*state)++;
    case 1:
        core->actionResult = BTLV_SCD_WaitActionMenu(core->auxView);
        if (core->actionResult)
            return 1;
    }
    return 0;
}

/* Step of the target menu: opens it on the aux view, then waits for the choice. */
int BTLV_CORE_StepTargetMenu(struct BtlvCore *core, int *state, void *work)
{
    switch (*state) {
    case 0:
        BTLV_SCD_StartTargetMenu(core->auxView, core->pokeParam, (union BtlAction *)core->actionCursor);
        (*state)++;
        break;
    case 1:
        if (BTLV_SCD_WaitTargetMenu(core->auxView))
            return 1;
        break;
    }
    return 0;
}

void BTLV_CORE_SetStep(struct BtlvCore *core, BtlvCoreStepFn stepFn)
{
    core->stepFn = stepFn;
    core->stepState = 0;
}

void BTLV_CORE_ClearStep(struct BtlvCore *core)
{
    core->stepFn = 0;
    core->stepState = 0;
}

int BTLV_CORE_RunStep(struct BtlvCore *core)
{
    if (core->stepFn != 0) {
        if (core->stepFn(core, &core->stepState, core->task.work) != 0) {
            core->stepFn = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}

void BTLV_CORE_StartActionMenu(struct BtlvCore *core, struct BtlPokeParam *pokeParam, int canBack, u8 *cursor)
{
    core->pokeParam = pokeParam;
    core->pokeId = BTL_POKEPARAM_GetPokeId(pokeParam);
    core->actionCursor = cursor;
    core->actionResult = 0;
    core->canBack = canBack;
    BTLV_CORE_SetStep(core, BTLV_CORE_StepActionMenu);
}

void BTLV_CORE_AbortActionMenu(struct BtlvCore *core) { BTLV_CORE_AbortInput(core); }

int BTLV_CORE_PollActionMenu(struct BtlvCore *core)
{
    if (BTLV_CORE_RunStep(core) != 0) {
        return core->actionResult;
    }
    return 0;
}

void BTLV_CORE_StartMoveMenu(struct BtlvCore *core, struct BtlPokeParam *pokeParam, u8 *cursor)
{
    core->pokeParam = pokeParam;
    core->pokeId = BTL_POKEPARAM_GetPokeId(pokeParam);
    core->actionCursor = cursor;
    BTLV_SCD_StartMoveMenu(core->auxView, core->pokeParam, (union BtlAction *)cursor);
    BTLV_CORE_SetStep(core, BTLV_CORE_StepMoveMenu);
}

void BTLV_CORE_StartMoveMenuForEntry(struct BtlvCore *core, struct BtlPokeParam **entry, u8 *cursor)
{
    struct BtlPokeParam *pokeParam = *entry;

    core->pokeParam = pokeParam;
    core->pokeId = BTL_POKEPARAM_GetPokeId(pokeParam);
    core->entry = entry;
    core->actionCursor = cursor;
    BTLV_SCD_StartRotateMenu(core->auxView, (struct BtlvRotateSet *)entry, (union BtlAction *)cursor);
    BTLV_CORE_SetStep(core, BTLV_CORE_StepMoveMenu);
}

void BTLV_CORE_ReopenMoveMenu(struct BtlvCore *core)
{
    BTLV_SCD_ReopenMenu(core->auxView);
    BTLV_CORE_SetStep(core, BTLV_CORE_StepMoveMenu);
}

int BTLV_CORE_StepMoveMenu(struct BtlvCore *core, int *state, void *work) { return BTLV_SCD_WaitMoveMenu(core->auxView) != 0; }

/*
 * leaf: only-blocker of ov093 021CEA94; parent expanded scope.
 * interface: eight-byte ldr-r3/bx-r3 stub forwards only live r0;
 * target body reads only r0. Original caller does not read result.
 */
void BTLV_CORE_AbortMoveMenu(struct BtlvCore *core)
{
    BTLV_CORE_AbortInput(core);
}

/*
 * leaf: only-blocker of ov093 021CEA94; parent expanded scope.
 * interface: eight-byte ldr-r3/bx-r3 stub forwards only live r0;
 * target body reads only r0. Original caller compares returned r0 with zero.
 */
u32 BTLV_CORE_PollMoveMenu(struct BtlvCore *core)
{
    return BTLV_CORE_RunStep(core);
}

void BTLV_CORE_StartTargetMenu(struct BtlvCore *core, struct BtlPokeParam *pokeParam, u8 *cursor)
{
    core->pokeParam = pokeParam;
    core->pokeId = BTL_POKEPARAM_GetPokeId(pokeParam);
    core->actionCursor = cursor;
    BTLV_CORE_SetStep(core, BTLV_CORE_StepTargetMenu);
}

int BTLV_CORE_PollTargetMenu(struct BtlvCore *core)
{
    if (BTLV_CORE_RunStep(core) != 0) {
        if (BTLV_SCD_IsTargetChosen(core->auxView) != 0) {
            return 1;
        }
        return 2;
    }
    return 0;
}

/*
 * leaf: only-blocker of ov093 021CEA94; parent expanded scope.
 * interface: eight-byte ldr-r3/bx-r3 stub forwards only live r0;
 * target body reads only r0. Original caller does not read result.
 */
void BTLV_CORE_AbortTargetMenu(struct BtlvCore *core)
{
    BTLV_CORE_AbortInput(core);
}

void BTLV_CORE_AbortInput(struct BtlvCore *core)
{
    BTLV_EFFECT_StartIntroEffect();
    BTLV_SCD_CancelMenus(core->auxView);
    BTLV_CORE_ClearStep(core);
}

/*
 * Indexed-dispatch thunk, sibling of BTLV_CORE_CloseMenuToReselect (same shape, other tail target).
 * Tail call T(core->auxView) with the index materialised as a scaled immediate.
 * Unlabelled leaf filed as the witness for the call in BTL_CLIENT_StepSelectAction.
 */
void BTLV_CORE_CloseMenu(struct BtlvCore *core) { BTLV_SCD_CloseInputIfOpen(core->auxView); }

/*
 * Indexed-dispatch thunk (o18's 23-member shape): the member's whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base; only the scratch register, the index constant and the tail target differ. Tail call T(core->auxView) with the index materialised as a scaled immediate.
 */
void BTLV_CORE_CloseMenuToReselect(struct BtlvCore *core) { BTLV_SCD_CloseInput(core->auxView); }

int BTLV_CORE_IsMenuClosed(struct BtlvCore *core) { return BTLV_SCD_IsInputIdle(core->auxView); }

void BTLV_CORE_InitPartyWork(struct BtlvCore *core, struct B_PlistHost *plist, int mode, u8 slot, int modeParam)
{
    u32 clientIndex;
    int isNotComm;
    int hasPartner;
    clientIndex = BTL_CLIENT_GetClientId(core->client);
    plist->party = BTL_MAIN_SyncSideParty((struct BtlMain *)core->context, clientIndex);
    if (mode != 3) hasPartner = BTL_MAIN_IsCommMulti((struct BtlMain *)core->context);
    else hasPartner = 0;
    plist->hasPartner = hasPartner;
    if (hasPartner) {
        plist->partnerParty = BTL_MAIN_SyncPartnerSideParty((struct BtlMain *)core->context, clientIndex);
        plist->isSecondTeam = BTL_MAIN_IsSecondTeamClient((struct BtlMain *)core->context, clientIndex);
    } else {
        plist->partnerParty = 0;
        plist->isSecondTeam = 0;
    }
    plist->listType = mode;
    if (BTL_MAIN_GetRule((struct BtlMain *)core->context) != 3) plist->partyCount = BTL_MAIN_GetPositionsPerClientThunk((struct BtlMain *)core->context, clientIndex);
    else plist->partyCount = 3;
    switch (mode) {
    case 4:
    case 5: hasPartner = slot; break;
    default: hasPartner = 0; break;
    }
    plist->orderIndex = hasPartner;
    plist->pickIndex = slot;
    plist->moveId = modeParam;
    plist->order[3] = 0;
    plist->heapId = core->heapId;
    plist->font = core->fontMain;
    plist->rule = BTL_MAIN_GetRule((struct BtlMain *)core->context);
    plist->syncFlagPtr = BTLV_SCD_GetInputFlags(core->auxView);
    plist->fadeContext = BTLV_EFFECT_GetOwner();
    plist->palAnm = BTLV_EFFECT_GetPalanm();
    plist->gameData = BTL_MAIN_GetGameData((struct BtlMain *)core->context);
    plist->cancelRequest = 0;
    isNotComm = 0;
    if (BTL_MAIN_GetCompetitor((struct BtlMain *)core->context) != 3) isNotComm = 1;
    plist->seEnabled = isNotComm;
    plist->exitRequest = 0;
    plist->done = 0;
}

void BTLV_CORE_StartPartyMenu(struct BtlvCore *core, const BtlSlotChoices *slotChoices, int slot, int canCancel, BtlPickList *choiceFlags)
{
    u32 i;
    u32 count;

    if (slot < 0) slot = 0;
    BTLV_CORE_InitPartyWork(core, &core->plist, slotChoices->mode, slot, canCancel);
    count = BTL_PICK_GetCount(choiceFlags);
    for (i = 0; i < count; i++) {
        if (i >= 2) break;
        core->plist.selected[i] = BTL_PICK_GetSlot(choiceFlags, i);
    }
    for (; i < 2; i++)
        core->plist.selected[i] = 6;
    choiceFlags->locked = 1;
    core->choiceFlags = choiceFlags;
    core->subStep = 0;
}

void BTLV_CORE_LockPartyChoice(struct BtlvCore *core)
{
    core->plist.cancelRequest = 1;
}

/*
 * note: 2026-10-03 EXACT*: the calls go through Thumb-entry linker veneers
 *   (bx pc; nop; ldr ip,[pc]; bx ip; .word <ov095 function>), attested by the
 *   match.py `veneer` class. The listing extent includes the veneers.
 * extent: lead is 320 bytes; eight 16-byte Thumb veneers follow.
 */
int BTLV_CORE_PollPartyMenu(struct BtlvCore *core)
{
    u32 i;
    switch (core->subStep) {
    case 0:
        if ((u8)(core->plist.listType + 0xff) <= 1) BTLV_SCD_StartInputSlideIn(core->auxView, 0);
        else BTLV_SCD_StartInputSlideIn(core->auxView, 1);
        GF_OVERLAY_Load((sptr)ov196_id);
        core->subStep++;
        break;
    case 1:
        if (BTLV_SCD_IsInputSlideDone(core->auxView)) {
            BTLV_SCD_OnSlideInDone(core->auxView);
            GF_OVERLAY_Load((sptr)ov198_id);
            B_PLIST_MAIN_Create(&core->plist);
            core->subStep++;
        }
        break;
    case 2:
        if (core->plist.done) {
            if (core->plist.listType != 5 && core->plist.cancelRequest == 0) {
                for (i = 0; i < 3; i++) {
                    if (core->plist.order[i] != 0xff) {
                        BTL_PICK_Push(core->choiceFlags, i, core->plist.order[i]);
                        BTL_PICK_GetCount(core->choiceFlags);
                        core->choiceFlags->locked = 0;
                    }
                }
            }
            GF_OVERLAY_Unload((sptr)ov198_id);
            BTLV_SCD_StartInputSlideOut(core->auxView);
            BTLV_SCD_OnSlideOutStart(core->auxView);
            core->subStep++;
        }
        break;
    case 3:
        if (BTLV_SCD_IsInputSlideDone(core->auxView)) core->subStep++;
        break;
    default:
        GF_OVERLAY_Unload((sptr)ov196_id);
        core->subStep = 0;
        return 1;
    }
    return 0;
}

void BTLV_CORE_StartMoveHighlight(struct BtlvCore *core, u8 slot, u8 kind)
{
    BTLV_CORE_InitPartyWork(core, &core->plist, 5, slot, 0);
    core->plist.order[3] = kind;
    core->subStep = 0;
}

void BTLV_CORE_StartBagMenu(struct BtlvCore *core, int isComm, u8 pointCounter, u8 itemId, u8 isLastSlot, u8 foeSemiInvulnerable)
{
    u32 i;
    u32 count;
    void *pokeList;
    int flag;
    if (core->subStep) return;
    core->bag.myItem = BTL_MAIN_GetMyItem((struct BtlMain *)core->context);
    core->bag.myItemSave = (struct MyItemSave *)BTL_MAIN_GetMapMatrix((struct BtlMain *)core->context);
    core->bag.isComm = isComm;
    core->bag.fontMain = core->fontMain;
    core->bag.heapId = core->heapId;
    core->bag.pointCounter = pointCounter;
    core->bag.lastItem = itemId;
    core->bag.selectedItem = 0;
    core->bag.auxViewHandle = BTLV_SCD_GetInputFlags(core->auxView);
    core->bag.skipPartyPrompt = 0;
    core->bag.regulationRules = BTL_MAIN_GetRegulationRules((struct BtlMain *)core->context);
    flag = 0;
    if (BTL_MAIN_GetCompetitor((struct BtlMain *)core->context) != 3) flag = 1;
    core->bag.allowBag = flag;
    core->bag.cursorPos = 0;
    flag = 0;
    if (BTL_MAIN_GetCompetitor((struct BtlMain *)core->context) == 0) flag = 1;
    core->bag.isWildBattle = flag;
    core->bag.done = 0;
    flag = 0;
    if (isLastSlot == 0) flag = 3;
    else if (BTL_MAIN_CheckSetupStatusFlag((struct BtlMain *)core->context, 0x40)) flag = 1;
    else if (BTL_MAIN_GetCompetitor((struct BtlMain *)core->context) == 0) {
        if (BTL_SIDE_CountLivingOfClient((struct BtlSide *)core->monTable, 1) > 1) flag = 2;
        else if (foeSemiInvulnerable) flag = 4;
    }
    core->bag.buttonMode = flag;
    BTLV_CORE_InitPartyWork(core, &core->plist, 3, 0, 0);
    pokeList = BTL_CLIENT_GetSideData(core->client);
    count = BTL_SLOT_GetCount(pokeList);
    for (i = 0; i < count; i++)
        core->plist.slotFlags[i] = BTL_POKEPARAM_HasSick(BTL_SLOT_GetPokeParam(pokeList, (u8)i), 0x13);
    for (; i < 6; i++) core->plist.slotFlags[i] = 0;
    core->subStep = 1;
}

void BTLV_CORE_SkipBagPartyPrompt(struct BtlvCore *core)
{
    core->bag.skipPartyPrompt = 1;
    core->plist.cancelRequest = 1;
}

/*
 * note: 2026-10-03 EXACT*: the calls go through Thumb-entry linker veneers
 *   (bx pc; nop; ldr ip,[pc]; bx ip; .word <ov095 function>), attested by the
 *   match.py `veneer` class. The listing extent includes the veneers.
 * extent: lead is 300 bytes; seven 16-byte Thumb veneers follow.
 */
int BTLV_CORE_PollBagMenu(struct BtlvCore *core)
{
    switch (core->subStep) {
    case 0: break;
    case 1:
        BTLV_SCD_StartInputSlideIn(core->auxView, 1);
        GF_OVERLAY_Load((sptr)ov196_id);
        core->subStep = 2;
        break;
    case 2:
        if (BTLV_SCD_IsInputSlideDone(core->auxView)) {
            BTLV_SCD_OnSlideInDone(core->auxView);
            GF_OVERLAY_Load((sptr)ov197_id);
            B_BAG_MAIN_Create((u8 *)(&core->bag));
            core->subStep = 3;
        }
        break;
    case 3:
        if (core->bag.done) {
            GF_OVERLAY_Unload((sptr)ov197_id);
            if (core->bag.skipPartyPrompt == 0) core->subStep = 4;
            else core->subStep = 6;
        }
        break;
    case 4:
        /* The DS code passes the item page as a second argument; the definition takes one and ignores it. */
#ifdef __MWERKS__
        if (core->bag.selectedItem && core->bag.selectedItemPage != 2 && !BTL_ID_IsBagItemUseBlocked(core->bag.selectedItem, core->bag.selectedItemPage)) {
            core->plist.itemId = core->bag.selectedItem;
            GF_OVERLAY_Load((sptr)ov198_id);
            B_PLIST_MAIN_Create(&core->plist);
            core->subStep = 5;
        } else core->subStep = 6;
#else
        if (core->bag.selectedItem && core->bag.selectedItemPage != 2 && !BTL_ID_IsBagItemUseBlocked(core->bag.selectedItem)) {
            core->plist.itemId = core->bag.selectedItem;
            GF_OVERLAY_Load((sptr)ov198_id);
            B_PLIST_MAIN_Create(&core->plist);
            core->subStep = 5;
        } else core->subStep = 6;
#endif
        break;
    case 5:
        if (core->plist.done) {
            GF_OVERLAY_Unload((sptr)ov198_id);
            core->subStep = 6;
        }
        break;
    case 6:
        BTLV_SCD_StartInputSlideOut(core->auxView);
        BTLV_SCD_OnSlideOutStart(core->auxView);
        core->subStep = 7;
        break;
    case 7:
        if (BTLV_SCD_IsInputSlideDone(core->auxView)) {
            GF_OVERLAY_Unload((sptr)ov196_id);
            core->subStep = 0;
            return 1;
        }
        break;
    }
    return 0;
}

/* Selected bag item, valid only after the bag returned a choice. */
u16 BTLV_CORE_GetSelectedItem(struct BtlvCore *core)
{
    if (core->bag.done != 0)
        return core->bag.selectedItem;
    return 0;
}

u8 BTLV_CORE_GetSelectedItemCost(struct BtlvCore *core)
{
    if (core->bag.done != 0)
        return core->bag.selectedItemCost;
    return 0;
}

u8 BTLV_CORE_GetItemTargetSlot(struct BtlvCore *core) { return core->plist.orderIndex; }

u8 BTLV_CORE_GetItemTargetFlag(struct BtlvCore *core)
{
    return core->plist.order[3];
}

/* Stores the bag cursors and the last used item into the save. */
void BTLV_CORE_SaveBagCursors(struct BtlvCore *core)
{
    if (core->bag.selectedItem != 0 && core->plist.orderIndex != 6 && core->bag.isComm != 1) {
        MYITEM_SAVEDATA_SetBattlePocketCursors((struct BagCursor *)core->bag.myItemSave, core->bag.pocketCursorPos, core->bag.pocketScrollPos);
        MYITEM_SAVEDATA_SetLastBattleItem((struct BagCursor *)core->bag.myItemSave, core->bag.selectedItem, core->bag.selectedItemPage);
    }
}

void BTLV_CORE_StartSceneEffect(struct BtlvCore *core, u32 slotFrom, u32 slotTo, u32 sceneId, u32 argA, u32 argB, u8 flags)
{
    u32 viewPosFrom;
    u32 viewPosTo;

    viewPosFrom = BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)core->context, slotFrom);
    if (slotTo != 6) {
        viewPosTo = BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)core->context, slotTo);
    } else {
        viewPosTo = 0xff;
    }
    BTLV_SCU_StartWazaEffect(core->sceneUnit, viewPosFrom, viewPosTo, sceneId, argA, argB, flags);
}

int BTLV_CORE_WaitSceneEffect(struct BtlvCore *core) { return BTLV_SCU_RunWazaProc(core->sceneUnit); }

void BTLV_CORE_StartDamageEffect(struct BtlvCore *core, u32 animId, u32 slot, u32 effectiveness)
{
    struct BtlvCoreDamageWork *work;

    work = (struct BtlvCoreDamageWork *)BTLV_CORE_GetTaskWork(core, 0xc);
    work->effectiveness = effectiveness;
    work->slot = slot;
    work->step = 0;
    work->animId = animId;
    core->task.preProc = 0;
    core->task.mainProc = BTLV_CORE_ProcDamageEffect;
    core->task.procCore = core;
    core->task.procState = 0;
}

int BTLV_CORE_WaitDamageEffect(struct BtlvCore *core)
{
    if (core->task.preProc != 0) {
        if (core->task.preProc(&core->task.procState, core->task.procCore) != 0) {
            core->task.preProc = 0;
            core->task.procState = 0;
        }
        return 0;
    }
    if (core->task.mainProc != 0) {
        if (core->task.mainProc(&core->task.procState, core->task.procCore) != 0) {
            core->task.mainProc = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}

int BTLV_CORE_ProcDamageEffect(int *state, struct BtlvCore *core)
{
    struct BtlvCoreDamageWork *work;

    work = (struct BtlvCoreDamageWork *)BTLV_CORE_GetTaskWork(core, 0xc);
    switch (*state) {
    case 0:
        BTLV_SCU_StartMonDamageAnim(core->sceneUnit, work->slot, work->animId, BTL_CLIENT_IsMainStepActive(core->client));
        BTLV_CORE_PlayEffectivenessSe(core, work->effectiveness);
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_SCU_IsMonDamageAnimDone(core->sceneUnit) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

void BTLV_CORE_StartHitAnim(struct BtlvCore *core, u32 animId, int slot, int effectiveness)
{
    struct BtlvCoreDamageWork *work;

    if (BTL_CLIENT_IsMainStepActive(core->client) == 0) {
        work = (struct BtlvCoreDamageWork *)BTLV_CORE_GetTaskWork(core, 0xc);
        work->effectiveness = effectiveness;
        work->slot = slot;
        work->step = 0;
        work->animId = animId;
        core->task.preProc = 0;
        core->task.mainProc = BTLV_CORE_ProcHitAnim;
        core->task.procCore = core;
        core->task.procState = 0;
    }
}

int BTLV_CORE_WaitHitAnim(struct BtlvCore *core)
{
    if (core->task.preProc != 0) {
        if (core->task.preProc(&core->task.procState, core->task.procCore) != 0) {
            core->task.preProc = 0;
            core->task.procState = 0;
        }
        return 0;
    }
    if (core->task.mainProc != 0) {
        if (core->task.mainProc(&core->task.procState, core->task.procCore) != 0) {
            core->task.mainProc = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}

int BTLV_CORE_ProcHitAnim(int *state, struct BtlvCore *core)
{
    struct BtlvCoreDamageWork *work;

    work = (struct BtlvCoreDamageWork *)BTLV_CORE_GetTaskWork(core, 0xc);
    switch (*state) {
    case 0:
        BTLV_SCU_StartMonMotion(core->sceneUnit, work->slot, work->animId);
        BTLV_CORE_PlayEffectivenessSe(core, work->effectiveness);
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_SCU_IsMonMotionDone(core->sceneUnit) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

void BTLV_CORE_StartMultiDamageEffect(struct BtlvCore *core, u32 count, int effectiveness, const u8 *pokeIds, u16 animId)
{
    struct BtlvCoreMultiDamageWork *work;
    u32 i;

    work = (struct BtlvCoreMultiDamageWork *)BTLV_CORE_GetTaskWork(core, 0x14);
    work->effectiveness = effectiveness;
    work->count = count;
    work->animId = animId;
    work->step = 0;
    for (i = 0; i < count; i++) {
        work->slots[i] = BTL_MAIN_GetTrainerSlotOfPoke((struct BtlMain *)core->context, (struct BtlSide *)core->monTable, pokeIds[i]);
    }
}

int BTLV_CORE_ProcMultiDamageEffect(struct BtlvCore *core)
{
    struct BtlvCoreMultiDamageWork *work;
    u32 mainStepActive;
    u32 i;

    work = (struct BtlvCoreMultiDamageWork *)BTLV_CORE_GetTaskWork(core, 0x14);
    switch (work->step) {
    case 0:
        mainStepActive = BTL_CLIENT_IsMainStepActive(core->client);
        for (i = 0; i < work->count; i++) {
            BTLV_SCU_StartMonDamageAnim(core->sceneUnit, work->slots[i], work->animId, mainStepActive);
        }
        BTLV_CORE_PlayEffectivenessSe(core, work->effectiveness);
        work->step = work->step + 1;
        break;
    case 1:
        if (BTLV_SCU_IsMonDamageAnimDone(core->sceneUnit) != 0) {
            if (BTLV_SCU_UpdateMessage(core->sceneUnit) != 0) {
                return 1;
            }
        }
        break;
    }
    return 0;
}

/* Plays the sound that matches the damage effectiveness. */
void BTLV_CORE_PlayEffectivenessSe(struct BtlvCore *core, int effectiveness)
{
    int seId;

    switch (effectiveness) {
    case 2:
        seId = 0x563;
        break;
    case 3:
        seId = 0x565;
        break;
    default:
        seId = 0x564;
        break;
    }
    BTLV_SCU_PlaySeUnlessMainStep(core, seId);
}

/*
 * note:     2026-10-03: byte-correct. The three callees are unlabelled Thumb tail-call stubs in
 *           ov094 (ov093 window does not hold them; the ov094 hint is right). Witnesses filed
 *           EXACT: src/matched/ov/BTLV_EFFECT_GetPokeSpriteState.c, ov094_func_021F7E74.c,
 *           BTLV_EFFECT_StartPokeEffectId286.c. Once the integrator creates their shards, the `matched`
 *           class resolves the three sites through the ov094 hint; re-verify and file EXACT.
 */
void BTLV_CORE_SetMonShown(struct BtlvCore *core, int viewPos, int shown)
{
    if (BTLV_EFFECT_IsPokeSpriteLoaded(viewPos) != 0) {
        if (shown != BTLV_EFFECT_GetPokeSpriteState(viewPos)) {
            if (shown == 1) {
                BTLV_EFFECT_StartPokeEffectId285(viewPos);
            } else {
                BTLV_EFFECT_StartPokeEffectId286(viewPos);
            }
        }
    }
}

void BTLV_CORE_StartMonSpriteUpdate(struct BtlvCore *core, int slot)
{
    BTLV_SCU_StartHpGaugeUpdate(core->sceneUnit, slot, BTL_CLIENT_IsMainStepActive(core->client));
}

int BTLV_CORE_WaitMonSpriteUpdate(struct BtlvCore *core) { return BTLV_SCU_IsHpGaugeIdle(core->sceneUnit) != 0; }

void BTLV_CORE_StartViewEffect(struct BtlvCore *core, int viewPos, int effectId)
{
    if (BTL_CLIENT_IsMainStepActive(core->client) == 0) {
        BTLV_EFFECT_StartEffectOnPoke(viewPos, effectId);
    }
}

int BTLV_CORE_WaitViewEffect(struct BtlvCore *core)
{
    if (BTLV_EFFECT_IsBusy() == 0) {
        return 1;
    }
    return 0;
}

void BTLV_CORE_StartViewEffectEx(struct BtlvCore *core, int viewPos, int effectId, u32 param)
{
    BTLV_EFFECT_StartEffectBetweenPokes(viewPos, effectId, param);
}

int BTLV_CORE_WaitViewEffectEx(void *viewPos)
{
    if (BTLV_EFFECT_IsBusy() == 0) {
        return 1;
    }
    return 0;
}

void BTLV_CORE_StartMonReset(struct BtlvCore *core, int slot)
{
    BTLV_SCU_StartMonExit(core->sceneUnit, slot, BTL_CLIENT_IsMainStepActive(core->client));
}

int BTLV_CORE_WaitMonReset(struct BtlvCore *core) { return BTLV_SCU_IsMonExitDone(core->sceneUnit); }

void BTLV_CORE_StartMonRefresh(struct BtlvCore *core, u32 slot) { BTLV_SCU_LoadAndShowMon(core->sceneUnit, slot); }

int BTLV_CORE_WaitMonRefresh(struct BtlvCore *core) { return BTLV_SCU_IsMonLoadDone(core->sceneUnit); }

void BTLV_CORE_StartMonEffectTask(struct BtlvCore *core, u16 viewPos, u16 effectId)
{
    BTLV_SCU_StartMonWithdraw(core->sceneUnit, viewPos, effectId, BTL_CLIENT_IsMainStepActive(core->client));
}

int BTLV_CORE_WaitMonEffectTask(struct BtlvCore *core) { return BTLV_SCU_IsMonWithdrawDone(core->sceneUnit); }

void BTLV_CORE_StartMonSwap(struct BtlvCore *core, u8 slot, u8 clientId, u8 pokeIdx)
{
    struct BtlvCoreSwapWork *work;
    struct BtlPokeParam *mon;

    work = (struct BtlvCoreSwapWork *)BTLV_CORE_GetTaskWork(core, 4);
    mon = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain **)core->monTable, slot);
    work->clientId = clientId;
    work->pokeIdx = pokeIdx;
    work->slot = slot;
    work->pokeId = BTL_POKEPARAM_GetPokeId(mon);
    core->task.preProc = 0;
    core->task.mainProc = BTLV_CORE_ProcMonSwap;
    core->task.procCore = core;
    core->task.procState = 0;
}

int BTLV_CORE_WaitMonSwap(struct BtlvCore *core)
{
    if (core->task.preProc != 0) {
        if (core->task.preProc(&core->task.procState, core->task.procCore) != 0) {
            core->task.preProc = 0;
            core->task.procState = 0;
        }
        return 0;
    }
    if (core->task.mainProc != 0) {
        if (core->task.mainProc(&core->task.procState, core->task.procCore) != 0) {
            core->task.mainProc = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}

int BTLV_CORE_ProcMonSwap(int *state, struct BtlvCore *core)
{
    struct BtlvCoreSwapWork *work;

    work = (struct BtlvCoreSwapWork *)BTLV_CORE_GetTaskWork(core, 4);
    switch (*state) {
    case 0:
        BTLV_SCU_StartMonSendOut(core->sceneUnit, work->slot, work->clientId, work->pokeIdx, BTL_CLIENT_IsMainStepActive(core->client));
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_SCU_IsMonSendOutDone(core->sceneUnit) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

/* Formats a message record into the buffer, by kind. */
void BTLV_CORE_BuildMessage(struct BtlvMessage *msg, struct Strbuf *buf)
{
    switch (msg->kind) {
    case BTLV_MSG_KIND_SIDE:
        BTL_MSG_FormatWithSide((struct Strbuf *)buf, msg->msgId, msg->args);
        break;
    case BTLV_MSG_KIND_TAGGED:
        BTL_MSG_DispatchTagged((struct Strbuf *)buf, msg->msgId, msg->args);
        break;
    case BTLV_MSG_KIND_UI:
        BTL_MSG_GetUiString((struct Strbuf *)buf, msg->msgId);
        break;
    case BTLV_MSG_KIND_UI_ARGS:
        BTL_MSG_BuildUiString((struct Strbuf *)buf, msg->msgId, msg->args);
        break;
    case BTLV_MSG_KIND_TRAINER:
        BTL_MSG_BuildTrainerString((struct Strbuf *)buf, msg->msgId, msg->args);
        break;
    case BTLV_MSG_KIND_ITEM_USE:
        BTL_MSG_BuildItemUse((struct Strbuf *)buf, msg->args[0], msg->args[1]);
        break;
    case BTLV_MSG_KIND_PLAIN:
        BTL_MSG_BuildPlainEntry((struct Strbuf *)buf, msg->args[0], msg->args[1]);
        break;
    }
}

void BTLV_CORE_CopyMessageBuffer(struct BtlvCore *core, struct Strbuf *src)
{
    STRBUF_Copy((struct Strbuf *)core->msgBuffer, (struct Strbuf *)src);
}

void BTLV_CORE_BuildMessageToBuffer(struct BtlvCore *core, struct BtlvMessage *msg)
{
    BTLV_CORE_BuildMessage(msg, core->msgBuffer);
}

void BTLV_CORE_PrintMessageBuffer(struct BtlvCore *core)
{
    BTLV_CORE_StartPrintMessage(core, core->msgBuffer, 0x50, 0);
}

void BTLV_CORE_BuildAndPrintMessage(struct BtlvCore *core, struct BtlvMessage *msg)
{
    BTLV_CORE_BuildMessage(msg, core->msgBuffer);
    BTLV_CORE_StartPrintMessage(core, core->msgBuffer, msg->param, 0);
}

void BTLV_CORE_BuildAndPrintMessageFlag(struct BtlvCore *core, struct BtlvMessage *msg, PrintCallback callback)
{
    BTLV_CORE_BuildMessage(msg, core->msgBuffer);
    BTLV_CORE_StartPrintMessage(core, core->msgBuffer, msg->param, callback);
}

void BTLV_CORE_BuildAndPrintMessageNow(struct BtlvCore *core, struct BtlvMessage *msg)
{
    BTLV_CORE_BuildMessage(msg, core->msgBuffer);
    BTLV_CORE_PrintMessageNow(core, core->msgBuffer);
}

void BTLV_CORE_PrintSideMessage(struct BtlvCore *core, u16 msgId, u32 *args)
{
    BTL_MSG_FormatWithSide((struct Strbuf *)core->msgBuffer, msgId, args);
    BTLV_CORE_StartPrintMessage(core, core->msgBuffer, 0x50, 0);
}

void BTLV_CORE_PrintTaggedMessage(struct BtlvCore *core, u16 msgId, u32 *args)
{
    BTL_MSG_DispatchTagged((struct Strbuf *)core->msgBuffer, msgId, args);
    BTLV_CORE_StartPrintMessage(core, core->msgBuffer, 0x50, 0);
}

int BTLV_CORE_PrintTrainerMessage(struct BtlvCore *core, u16 trainerId, u16 msgIndex)
{
    if (TPOKE_DATA_FindRecord(trainerId, msgIndex, core->heapId) != 0) {
        TPOKE_DATA_ReadRecordString(trainerId, msgIndex, core->msgBuffer, core->heapId);
        BTLV_CORE_StartPrintMessage(core, core->msgBuffer, 0x50, 0);
    } else {
        return 0;
    }
    return 1;
}

void BTLV_CORE_PrintItemUseMessage(struct BtlvCore *core, u8 clientId, u16 item)
{
    BTL_MSG_BuildItemUse((struct Strbuf *)core->msgBuffer, clientId, item);
    BTLV_CORE_StartPrintMessage(core, core->msgBuffer, 0x50, 0);
}

int BTLV_CORE_WaitMessage(struct BtlvCore *core) { return BTLV_SCU_UpdateMessage(core->sceneUnit); }

int BTLV_CORE_ConsumeMessageFlag(struct BtlvCore *core) { return BTLV_SCU_ConsumeMessageEnded(core->sceneUnit); }

void BTLV_CORE_StartPrintMessage(struct BtlvCore *core, struct Strbuf *buf, u16 speed, PrintCallback callback)
{
    if (BTL_CLIENT_IsMainStepActive(core->client) == 0) {
        BTLV_SCU_StartMessage(core->sceneUnit, buf, speed, callback);
    }
}

void BTLV_CORE_PrintMessageNow(struct BtlvCore *core, struct Strbuf *buf) { BTLV_SCU_PrintMessageInstant(core->sceneUnit, buf); }

void BTLV_CORE_ShowPortrait(struct BtlvCore *core, u32 slot, u32 flag) { BTLV_SCU_StartNamePlate(core->sceneUnit, slot, flag); }

int BTLV_CORE_UpdatePortraitSlideIn(struct BtlvCore *core, u32 slot) { return BTLV_SCU_ProcNamePlateAt(core->sceneUnit, slot); }

void BTLV_CORE_StartPortraitSlideOut(struct BtlvCore *core, u32 slot) { BTLV_SCU_HideNamePlateAt(core->sceneUnit, slot); }

int BTLV_CORE_WaitPortraitSlideOut(struct BtlvCore *core, u32 slot) { return BTLV_SCU_IsNamePlateHiddenAt(core->sceneUnit, slot); }

void BTLV_CORE_ReloadPortrait(struct BtlvCore *core, u32 slot) { BTLV_SCU_RefreshNamePlateAt(core->sceneUnit, slot); }

int BTLV_CORE_UpdatePortraitMosaic(struct BtlvCore *core, u32 slot) { return BTLV_SCU_ProcNamePlateMosaicAt(core->sceneUnit, slot); }

void BTLV_CORE_StartViewEffect262(struct BtlvCore *core, int viewPos)
{
    BTLV_EFFECT_StartEffectOnPoke(viewPos, BTLV_EFFECT_MOVE_END + 49);
}

void BTLV_CORE_StartViewEffect261(struct BtlvCore *core, int viewPos)
{
    BTLV_EFFECT_StartEffectOnPoke(viewPos, BTLV_EFFECT_MOVE_END + 48);
}

int BTLV_CORE_WaitViewEffectDone(struct BtlvCore *core, int viewPos)
{
    if (BTLV_EFFECT_IsBusy() == 0) {
        return 1;
    }
    return 0;
}

void BTLV_CORE_StartWaitMessage(struct BtlvCore *core)
{
    BTLV_EFFECT_SetIntroState(3);
    BTLV_SCU_PrintWaitMessage(core->sceneUnit);
}

int BTLV_CORE_UpdateWaitMessage(struct BtlvCore *core) { return BTLV_SCU_UpdateWaitMessage(core->sceneUnit); }

void BTLV_CORE_EndWaitMessage(struct BtlvCore *core)
{
    BTLV_EFFECT_StartIntroEffect();
    BTLV_SCU_NoOp((char *)core->sceneUnit);
}

void BTLV_CORE_StartSlotEffect25F(struct BtlvCore *core, u32 slot) { BTLV_SCU_StartPosCueEffect(core->sceneUnit, BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)core->context, slot)); }

int BTLV_CORE_WaitSlotEffect25F(struct BtlvCore *core, u32 slot) { return BTLV_SCU_IsPosCueEffectDone(core->sceneUnit, BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)core->context, slot)); }

void BTLV_CORE_StartMonSpriteLoad(struct BtlvCore *core, u32 slot, u32 mode) { BTLV_SCU_StartMonFormChange(core->sceneUnit, slot, mode); }

int BTLV_CORE_WaitMonSpriteLoad(struct BtlvCore *core) { return BTLV_SCU_IsMonFormChangeDone(core->sceneUnit); }

void BTLV_CORE_StartMonSpriteChange(struct BtlvCore *core, int viewPos)
{
    BTLV_SCU_StartMonGraphicSwap(core->sceneUnit, viewPos, BTL_CLIENT_IsMainStepActive(core->client));
}

int BTLV_CORE_WaitMonSpriteChange(struct BtlvCore *core) { return BTLV_SCU_IsMonGraphicSwapDone(core->sceneUnit); }

void BTLV_CORE_StartMonSpriteChangeAt(struct BtlvCore *core, u32 viewPos, u32 srcViewPos)
{
    BTLV_SCU_StartMonGraphicSwapFrom(core->sceneUnit, viewPos, srcViewPos, BTL_CLIENT_IsMainStepActive(core->client));
}

int BTLV_CORE_WaitMonSpriteChangeAt(struct BtlvCore *core) { return BTLV_SCU_IsMonGraphicSwapDone(core->sceneUnit); }

void BTLV_CORE_StartMonSpriteUnload(struct BtlvCore *core) { BTLV_SCU_StartMsgWinFadeOutTask(core->sceneUnit); }

int BTLV_CORE_WaitMonSpriteUnload(struct BtlvCore *core) { return BTLV_SCU_IsMsgWinFadeOutTaskDone(core->sceneUnit); }

void BTLV_CORE_StartRotation(struct BtlvCore *core, u32 clientId, u32 rotateA, u32 rotateB, u8 posA, u8 posB)
{
    struct BtlvCoreRotationWork *work;

    work = (struct BtlvCoreRotationWork *)BTLV_CORE_GetTaskWork(core, 7);
    work->clientId = clientId;
    work->rotateA = rotateA;
    work->rotateB = rotateB;
    work->posA = posA;
    work->posB = posB;
    work->monSlotA = BTL_MAIN_GetClientTrainerIndex((struct BtlMain *)core->context, clientId, posA);
    work->monSlotB = BTL_MAIN_GetClientTrainerIndex((struct BtlMain *)core->context, clientId, posB);
    core->task.preProc = 0;
    core->task.mainProc = BTLV_CORE_ProcRotation;
    core->task.procCore = core;
    core->task.procState = 0;
}

int BTLV_CORE_WaitRotation(struct BtlvCore *core)
{
    if (core->task.preProc != 0) {
        if (core->task.preProc(&core->task.procState, core->task.procCore) != 0) {
            core->task.preProc = 0;
            core->task.procState = 0;
        }
        return 0;
    }
    if (core->task.mainProc != 0) {
        if (core->task.mainProc(&core->task.procState, core->task.procCore) != 0) {
            core->task.mainProc = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}

int BTLV_CORE_ProcRotation(int *state, struct BtlvCore *core)
{
    struct BtlvCoreRotationWork *work = (struct BtlvCoreRotationWork *)BTLV_CORE_GetTaskWork(core, 7);

    switch (*state) {
    case 0:
        BTLV_EFFECT_SetPokeSpriteVisible(work->rotateA, work->rotateB);
        BTLV_SCU_PlaySeUnlessMainStep(core, 0x57b);
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_EFFECT_IsBusy() == 0) {
            BTLV_SCU_HideMonPair(core->sceneUnit, work->monSlotA, work->monSlotB);
            *state = *state + 1;
        }
        break;
    case 2:
        if (BTLV_SCU_ShowMonPair(core->sceneUnit, work->monSlotA, work->monSlotB) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

/* Hands the work area to the input view; the slot lookup result is not used. */
void BTLV_CORE_InitInputWork(struct BtlvCore *core, u8 unused)
{
    u8 *work;

    work = BTLV_CORE_GetTaskWork(core, 0x3c);
    BTL_SIDE_GetSlotOfClientThunk((struct BtlSide *)core->monTable, core->clientIndex);
    BTLV_SCD_ShowRotateScreen(core->auxView, work);
}

int BTLV_CORE_PollWindowModeSelect(struct BtlvCore *core, u8 *outMode)
{
    if (BTLV_SCD_PollTouchKey(core->auxView, outMode) != 0) {
        return 1;
    }
    return 0;
}

void BTLV_CORE_CancelWindowModeSelect(struct BtlvCore *core)
{
    BTLV_SCD_CloseInputScreen(core->auxView);
}

void BTLV_CORE_StartClearSidePosition(struct BtlvCore *core, u32 clientId, u32 kind)
{
    BtlvClearSideWork *work;

    if (kind != 1) {
        work = (BtlvClearSideWork *)BTLV_CORE_GetTaskWork(core, 8);
        work->clientId = clientId;
        work->kind = kind;
        work->monSlot[0] = BTL_MAIN_GetClientTrainerIndex((struct BtlMain *)core->context, clientId, 0);
        work->monSlot[1] = BTL_MAIN_GetClientTrainerIndex((struct BtlMain *)core->context, clientId, 1);
        work->monSlot[2] = BTL_MAIN_GetClientTrainerIndex((struct BtlMain *)core->context, clientId, 2);
        work->viewPos[0] = BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)core->context, work->monSlot[0]);
        work->viewPos[1] = BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)core->context, work->monSlot[1]);
        work->viewPos[2] = BTL_MAIN_GetViewPosOfSlot((struct BtlMain *)core->context, work->monSlot[2]);
        core->task.preProc = 0;
        core->task.mainProc = BTLV_CORE_ProcClearSidePosition;
        core->task.procCore = core;
        core->task.procState = 0;
    }
}

int BTLV_CORE_RunProc(struct BtlvCore *core)
{
    if (core->task.preProc != 0) {
        if (core->task.preProc(&core->task.procState, core->task.procCore) != 0) {
            core->task.preProc = 0;
            core->task.procState = 0;
        }
        return 0;
    }
    if (core->task.mainProc != 0) {
        if (core->task.mainProc(&core->task.procState, core->task.procCore) != 0) {
            core->task.mainProc = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}

int BTLV_CORE_ProcClearSidePosition(int *state, struct BtlvCore *core)
{
    BtlvClearSideWork *work = (BtlvClearSideWork *)BTLV_CORE_GetTaskWork(core, 8);
    int allDone;

    switch (*state) {
    case 0:
        BTLV_EFFECT_StartPokeSpriteTransitionTask(work->kind, work->viewPos[0] & 1, BTL_CLIENT_IsMainStepActive(core->client) == 0);
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_EFFECT_IsBusy() == 0) {
            BTLV_SCU_HideMon(core->sceneUnit, work->monSlot[0]);
            BTLV_SCU_HideMon(core->sceneUnit, work->monSlot[1]);
            BTLV_SCU_HideMon(core->sceneUnit, work->monSlot[2]);
            *state = *state + 1;
        }
        break;
    case 2:
        allDone = 1;
        if (BTLV_SCU_ShowMon(core->sceneUnit, work->monSlot[0]) == 0) {
            allDone = 0;
        }
        if (BTLV_SCU_ShowMon(core->sceneUnit, work->monSlot[1]) == 0) {
            allDone = 0;
        }
        if (BTLV_SCU_ShowMon(core->sceneUnit, work->monSlot[2]) == 0) {
            allDone = 0;
        }
        if (allDone != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

void BTLV_CORE_StartYesNoMenu(struct BtlvCore *core, struct BtlvMessage *yesMsg, struct BtlvMessage *noMsg, u32 mode)
{
    BtlvYesNoWork *work = BTLV_CORE_GetTaskWork(core, 12);

    work->yesText = STRBUF_Create(0x20, (u16)((core->heapId & 0x7fff) | 0x8000));
    work->noText = STRBUF_Create(0x20, (u16)((core->heapId & 0x7fff) | 0x8000));
    work->mode = mode;
    BTLV_CORE_BuildMessage(yesMsg, work->yesText);
    BTLV_CORE_BuildMessage(noMsg, work->noText);
    BTLV_SCD_OpenChoiceScreen(core->auxView, work);
    GFL_HEAP_Free(work->yesText);
    GFL_HEAP_Free(work->noText);
}

int BTLV_CORE_PollYesNoMenu(struct BtlvCore *core, int *outResult)
{
    return BTLV_SCD_PollChoiceScreen(core->auxView, (u32 *)outResult);
}

void BTLV_CORE_StartMoveForgetScreen(struct BtlvCore *core, u8 pokeSlot, int moveId)
{
    BTLV_CORE_InitPartyWork(core, &core->plist, 4, pokeSlot, moveId);
    core->subStep = 0;
}

/*
 * The calls go through Thumb-entry linker veneers (bx pc; nop; ldr ip,[pc];
 * bx ip; .word <ov095 function>), attested by the match.py `veneer` class.
 * The listing extent includes six veneers at 021EAD44..021EADA4, then six
 * tail stubs 021EADA4/ADB4/ADC4/ADD4/ADE4/ADF4. No C unit may span veneers.
 */
int BTLV_CORE_ProcMoveForgetScreen(struct BtlvCore *core, u8 *outSlot)
{
    switch (core->subStep) {
    case 0:
        BTLV_SCD_StartInputSlideIn(core->auxView, 0);
        GF_OVERLAY_Load((sptr)ov196_id);
        core->subStep++;
        break;
    case 1:
        if (BTLV_SCD_IsInputSlideDone(core->auxView)) {
            BTLV_SCD_OnSlideInDone(core->auxView);
            GF_OVERLAY_Load((sptr)ov198_id);
            B_PLIST_MAIN_Create(&core->plist);
            core->subStep++;
        }
        break;
    case 2:
        if (core->plist.done) {
            GF_OVERLAY_Unload((sptr)ov198_id);
            BTLV_SCD_StartInputSlideOut(core->auxView);
            BTLV_SCD_OnSlideOutStart(core->auxView);
            core->subStep++;
        }
        break;
    case 3:
        if (BTLV_SCD_IsInputSlideDone(core->auxView)) core->subStep++;
        break;
    default:
        *outSlot = core->plist.order[3];
        GF_OVERLAY_Unload((sptr)ov196_id);
        core->subStep = 0;
        return 1;
    }
    return 0;
}

void BTLV_CORE_StartBallWindowOpen(struct BtlvCore *core, void **pokeParam, struct BtlExpResult *result)
{
    BTLV_SCU_StartBallWindowOpen(core->sceneUnit, pokeParam, (struct BtlvBallStates *)result);
}

int BTLV_CORE_UpdateBallWindowOpen(struct BtlvCore *core)
{
    return BTLV_SCU_UpdateBallWindowOpen(core->sceneUnit);
}

void BTLV_CORE_StartBallWindowRefresh(struct BtlvCore *core)
{
    BTLV_SCU_StartBallWindowRefresh(core->sceneUnit);
}

int BTLV_CORE_UpdateBallWindowRefresh(struct BtlvCore *core)
{
    return BTLV_SCU_UpdateBallWindowRefresh(core->sceneUnit);
}

void BTLV_CORE_StartBallWindowClose(struct BtlvCore *core)
{
    BTLV_SCU_StartBallWindowClose(core->sceneUnit);
}

int BTLV_CORE_UpdateBallWindowClose(struct BtlvCore *core)
{
    return BTLV_SCU_UpdateBallWindowClose(core->sceneUnit);
}

void BTLV_CORE_StartFadeIn(struct BtlvCore *core) { BTLV_SCU_StartFadeIn(core->sceneUnit); }

int BTLV_CORE_PollFadeInDone(struct BtlvCore *core) { return BTLV_SCU_GetWaitState(core->sceneUnit); }

void BTLV_CORE_ClearWaitWindow(struct BtlvCore *core)
{
    BTLV_SCU_ClearWaitWindow(core->sceneUnit);
}

int BTLV_CORE_GetWaitState(struct BtlvCore *core)
{
    return BTLV_SCU_GetWaitState(core->sceneUnit);
}

void BTLV_CORE_StartAutoSelectNotice(struct BtlvCore *core) { BTLV_SCD_BeginCloseSequence(core->auxView); }

int BTLV_CORE_PollAutoSelectNotice(struct BtlvCore *core) { return BTLV_SCD_RunCloseSequence(core->auxView); }

int BTLV_CORE_PollCounterInput(struct BtlvCore *core) { return BTLV_SCD_PollCounterTouch(core->auxView); }

void BTLV_CORE_SetCounterDisplay(struct BtlvCore *core, u32 current, u32 target)
{
    core->counterCmd.current = current;
    core->counterCmd.target = target;
    core->counterCmd.mode = 0;
    BTLV_SCD_ShowCounterScreen(core->auxView, &core->counterCmd);
}

void BTLV_CORE_ShowCounterValue(struct BtlvCore *core, int value)
{
    core->counterCmd.current = value;
    core->counterCmd.target = value;
    core->counterCmd.mode = 3;
    BTLV_SCD_ShowCounterScreen(core->auxView, &core->counterCmd);
}

void BTLV_CORE_SetCounterValueMode(struct BtlvCore *core, int value, int mode)
{
    core->counterCmd.current = value;
    core->counterCmd.target = value;
    core->counterCmd.mode = mode;
    BTLV_SCD_ShowCounterScreen(core->auxView, &core->counterCmd);
}
