/*
 * file:     btlv_core.c
 * unit:     yes
 * function: BTLV_CORE_CheckPartySlotPair, BTLV_CORE_CheckPartySlotCondition, BTLV_CORE_CheckEitherSlotPair, BTLV_CORE_EventRedirectMove, BTLV_CORE_EventCounterMove, BTLV_CORE_EventQueueMoveNotice, BTLV_CORE_EventScaleDamage, BTLV_CORE_EventSetFlagIfAttacker, BTLV_CORE_EventTrySetFlagIfAttacker, BTLV_CORE_LoadDsiOverlay, BTLV_CORE_UnloadDsiOverlay, BTLV_CORE_GetZeroMasked, BTLV_CORE_IsSlotKindNone, BTLV_CORE_MakeSlotKind2Index, BTLV_CORE_MakeSlotKind2, BTLV_CORE_MakeSlotKind3, BTLV_CORE_MakeSlotKind1Empty, BTLV_CORE_MakeSlotKind1Value, BTLV_CORE_MakeSlotKind1, BTLV_CORE_MakeSlotKind4, BTLV_CORE_MakeSlotKind1Index15, BTLV_CORE_IsSlotKind1Index15, BTLV_CORE_GetSlotPosition, BTLV_CORE_SetSlotPosition, BTLV_CORE_GetSlotLow, BTLV_CORE_SetSlotValue, BTLV_CORE_GetSlotValue, BTLV_CORE_SetSlotFlag, BTLV_CORE_GetSlotFlag, BTLV_CORE_AddSlotIndex, BTLV_CORE_SetSlotIndex, BTLV_CORE_PackBytes, BTLV_CORE_PackByteTwice, BTLV_CORE_GetHighByte, BTLV_CORE_GetLowByte, BTLV_CORE_SplitBytes, BTLV_CORE_HasByte, BTLV_CORE_BytesOverlap, BTLV_CORE_BytesEqual, BTLV_CORE_LoadOverlays, BTLV_CORE_UnloadOverlays, BTLV_CORE_ResetDisplay, BTLV_CORE_InitDisplay, BTLV_CORE_ExitDisplay, BTLV_CORE_Create, BTLV_CORE_Delete, BTLV_CORE_Update, BTLV_CORE_StartOpening, BTLV_CORE_PollOpening, BTLV_CORE_GetTaskWork, BTLV_CORE_StepOpeningEntry, BTLV_CORE_StepOpeningDemo, BTLV_CORE_GetPokeParamAtViewPos, BTLV_CORE_StepActionMenu, BTLV_CORE_StepTargetMenu, BTLV_CORE_SetStep, BTLV_CORE_ClearStep, BTLV_CORE_RunStep, BTLV_CORE_StartActionMenu, BTLV_CORE_AbortActionMenu, BTLV_CORE_PollActionMenu, BTLV_CORE_StartMoveMenu, BTLV_CORE_StartMoveMenuForEntry, BTLV_CORE_ReopenMoveMenu, BTLV_CORE_StepMoveMenu, BTLV_CORE_AbortMoveMenu, BTLV_CORE_PollMoveMenu, BTLV_CORE_StartTargetMenu, BTLV_CORE_PollTargetMenu, BTLV_CORE_AbortTargetMenu, BTLV_CORE_AbortInput, BTLV_CORE_CloseMenu, BTLV_CORE_CloseMenuToReselect, BTLV_CORE_IsMenuClosed, BTLV_CORE_InitPartyWork, BTLV_CORE_StartPartyMenu, BTLV_CORE_LockPartyChoice, BTLV_CORE_PollPartyMenu, BTLV_CORE_StartMoveHighlight, BTLV_CORE_StartBagMenu, BTLV_CORE_SkipBagPartyPrompt, BTLV_CORE_PollBagMenu, BTLV_CORE_GetSelectedItem, BTLV_CORE_GetSelectedItemPocket, BTLV_CORE_GetInputTargetSlot, BTLV_CORE_GetInputResultFlag, BTLV_CORE_SaveBagCursors, BTLV_CORE_StartSceneEffect, BTLV_CORE_WaitSceneEffect, BTLV_CORE_StartDamageEffect, BTLV_CORE_WaitDamageEffect, BTLV_CORE_ProcDamageEffect, BTLV_CORE_StartHitAnim, BTLV_CORE_WaitHitAnim, BTLV_CORE_ProcHitAnim, BTLV_CORE_StartMultiDamageEffect, BTLV_CORE_ProcMultiDamageEffect, BTLV_CORE_PlayEffectivenessSe, BTLV_CORE_SetMonShown, BTLV_CORE_StartMonSpriteUpdate, BTLV_CORE_WaitMonSpriteUpdate, BTLV_CORE_StartViewEffect, BTLV_CORE_WaitViewEffect, BTLV_CORE_StartViewEffectEx, BTLV_CORE_WaitViewEffectEx, BTLV_CORE_StartMonReset, BTLV_CORE_WaitMonReset, BTLV_CORE_StartMonRefresh, BTLV_CORE_WaitMonRefresh, BTLV_CORE_StartMonEffectTask, BTLV_CORE_WaitMonEffectTask, BTLV_CORE_StartMonSwap, BTLV_CORE_WaitMonSwap, BTLV_CORE_ProcMonSwap, BTLV_CORE_BuildMessage, BTLV_CORE_CopyMessageBuffer, BTLV_CORE_BuildMessageToBuffer, BTLV_CORE_PrintMessageBuffer, BTLV_CORE_BuildAndPrintMessage, BTLV_CORE_BuildAndPrintMessageFlag, BTLV_CORE_BuildAndPrintMessageNow, BTLV_CORE_PrintSideMessage, BTLV_CORE_PrintTaggedMessage, BTLV_CORE_PrintTrainerMessage, BTLV_CORE_PrintItemUseMessage, BTLV_CORE_WaitMessage, BTLV_CORE_ConsumeMessageFlag, BTLV_CORE_StartPrintMessage, BTLV_CORE_PrintMessageNow, BTLV_CORE_ShowPortrait, BTLV_CORE_UpdatePortraitSlideIn, BTLV_CORE_StartPortraitSlideOut, BTLV_CORE_WaitPortraitSlideOut, BTLV_CORE_ReloadPortrait, BTLV_CORE_UpdatePortraitMosaic, BTLV_CORE_StartViewEffect262, BTLV_CORE_StartViewEffect261, BTLV_CORE_WaitViewEffectDone, BTLV_CORE_StartWaitMessage, BTLV_CORE_UpdateWaitMessage, BTLV_CORE_EndWaitMessage, BTLV_CORE_StartSlotEffect25F, BTLV_CORE_WaitSlotEffect25F, BTLV_CORE_StartMonSpriteLoad, BTLV_CORE_WaitMonSpriteLoad, BTLV_CORE_StartMonSpriteChange, BTLV_CORE_WaitMonSpriteChange, BTLV_CORE_StartMonSpriteChangeAt, BTLV_CORE_WaitMonSpriteChangeAt, BTLV_CORE_StartMonSpriteUnload, BTLV_CORE_WaitMonSpriteUnload, BTLV_CORE_StartRotation, BTLV_CORE_WaitRotation, BTLV_CORE_ProcRotation, BTLV_CORE_InitInputWork, BTLV_CORE_PollWindowModeSelect, BTLV_CORE_CancelWindowModeSelect, BTLV_CORE_StartClearSidePosition, BTLV_CORE_RunProc, BTLV_CORE_ProcClearSidePosition, BTLV_CORE_StartYesNoMenu, BTLV_CORE_PollYesNoMenu, BTLV_CORE_StartMoveForgetScreen, BTLV_CORE_ProcMoveForgetScreen, BTLV_CORE_StartBallWindowOpen, BTLV_CORE_UpdateBallWindowOpen, BTLV_CORE_StartBallWindowRefresh, BTLV_CORE_UpdateBallWindowRefresh, BTLV_CORE_StartBallWindowClose, BTLV_CORE_UpdateBallWindowClose, BTLV_CORE_StartFadeIn, BTLV_CORE_PollFadeInDone, BTLV_CORE_ClearWaitWindow, BTLV_CORE_GetWaitState, BTLV_CORE_StartAutoSelectNotice, BTLV_CORE_PollAutoSelectNotice, BTLV_CORE_PollCounterInput, BTLV_CORE_SetCounterDisplay, BTLV_CORE_ShowCounterValue, BTLV_CORE_SetCounterValueMode
 * address:  0x021E869C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * note (2026-10-03, wave B3 lane 01): every instruction, branch and pool word
 * matches (972 bytes, jump table included). The verdict is capped by the 8
 * calls to 0x021E95B4/95C4/95D4/95E4/95F4/9604/9614/9624: these are Thumb
 * bx-pc interworking veneers (bx pc; nop; ldr ip,[pc]; bx ip; .word) that the
 * linker placed right after this function. They have no label and no witness
 * outside this range, and C cannot produce them, so no witness file is
 * possible. The trailing star is the same 128 veneer bytes counted in the
 * listing extent (1100 = 972 + 8*16). It becomes EXACT when the Thumb bx-pc
 * veneer class is attested by the tools (out of scope for lanes).
 *
 * symbols:
 *   BTLV_SCD_Create  0x06899AF0  thumb
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   HAND_COMMON_IsItemBoundToSpecies  0x021E8638  thumb  ov093
 *   BTL_SERVER_FLOW_GetCompetitor  0x021C8168  thumb  ov093
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   WAZA_TOOL_GetCategory   0x0201C1BC  thumb
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_PushMoveQueueWithPos  0x021C8434  thumb  ov093
 *   BTL_POKEPARAM_IsSemiInvulnerable  0x021D5C30  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   OS_GetConsoleType  0x02085CBC  arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   gBtlvCoreDsiOverlayLoaded  0x021F6380  data
 *   ov140_id  0x0000008C  data  a1
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   ov094_id       0x0000005E  data
 *   ov095_id       0x0000005F  data
 *   ov096_id       0x00000060  data
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GX_SetBankForLCDC  0x0208068C  arm
 *   GFL_NET_IsNetTypeWifi  0x0203D29C  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   GF_FONT_ResetTextColor 0x0201DD60 thumb
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
 *   d_021F3844  0x021F3844  data  a4
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
 *   func_0209C0A4  0x0209C0A4  arm
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
 */
#include "btlv_core_types.h"

#define BLDCNT (*(volatile u16 *)0x04000050)
#define SBLDCNT (*(volatile u16 *)0x04001050)
#define POWCNT (*(volatile u16 *)0x04000304)
#define DISP3DCNT (*(volatile u16 *)0x04000060)
#define BG0CNT (*(volatile u16 *)0x04000008)
struct QF;
struct QI;
struct UtilWork;
struct DispConfig;
struct DispVram;
struct Cfg;
struct GfFont;
struct Tcbl;
struct U16Vec;
struct S02031140;
struct MsgBank;
struct Rec;
struct BtlExpResult;
/*
 * One packed battle slot word.  Bits 0..2 hold the kind (1..4); the rest of
 * the word depends on the kind, so each accessor reads the variant it needs.
 * The constructors below zero the word and fill one variant.
 */
typedef union BtlvSlot {
    s32 word;
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 extra : 17; } pos;
    struct { u32 kind : 3; u32 index : 6; u32 value : 16; u32 extra : 7; } param;
    struct { u32 kind : 3; u32 skip : 12; u32 value : 16; u32 extra : 1; } wideParam;
    struct { u32 kind : 3; u32 skip : 22; u32 flag : 1; u32 extra : 6; } flagMid;
    struct { u32 kind : 3; u32 skip : 28; u32 flag : 1; } flagHigh;
    struct { u32 kind : 3; u32 index : 6; u32 extra : 23; } indexOnly;
} BtlvSlot;

/* Event record from BTL_SERVER_FLOW_AllocCmdRecord: a 4-byte header, then a list. */
struct BtlvEventRec {
    u32 header;
    u8 list[];
};

struct BtlvStateEntry {
    u32 state;
    BtlvCoreStepFn step;
};

/* Work of the scripted demo scene, kept in the task work area of the core. */
typedef struct BtlvDemoWork {
    void *msgBank;
    int timer;
} BtlvDemoWork;

extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int HAND_COMMON_IsItemBoundToSpecies(int a, int b);
extern int BTL_SERVER_FLOW_GetCompetitor(void *p);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern int BTL_EVENT_GetVar(int key);
extern int BTL_MAIN_IsPokeSamePair(u32 a, u32 b);
extern u32 WAZA_TOOL_GetCategory(u16 move);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void BTL_SERVER_FLOW_PushMoveQueueWithPos(u8 *p, int a, int b);
extern int BTL_POKEPARAM_IsSemiInvulnerable(struct UtilWork *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *l, int a, int b);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(void *l, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern u32 OS_GetConsoleType(void);
extern int GF_OVERLAY_Load(const void *overlayId);
extern void GF_OVERLAY_Unload(const void *overlayId);
extern int GF_OVERLAY_Load(const void *overlayId);
extern void GX_SetBankForLCDC(unsigned int v);
extern u32 GFL_NET_IsNetTypeWifi(void);
extern void GF_OVERLAY_Unload(const void *overlayId);
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
extern void GF_FONT_ResetTextColor(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void G3D_SYSTEM_Init(u32, u32, u32, u32, u16, u16, void (*)(void));
extern void G3D_SYSTEM_SetSwapBuffersMode(u32, u32);
extern void G3X_SetFog(int, int, int, int);
extern void G2x_SetBlendAlpha_(void *, int, int, int, int);
extern void CLACT_InitSystem(const struct Cfg *cfg, const struct DispVram *vram, u32 heapId);
extern void BTLV_EFFECT_Exit(void);
extern void CLACT_ExitSystem(void);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void G3D_SYSTEM_Exit(void);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 BTL_CLIENT_GetClientId(void *client);
extern struct MsgBuf *STRBUF_Create(u32 capacity, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern struct BtlvScu *BTLV_SCU_Create(u32 core, u32 context, u32 monTable, u32 taskList, u32 fontMain, u32 fontSub, u8 clientIndex, int heapId);
extern void *BTLV_SCD_Create(struct BtlvCore *core, void *context, u32 monTable, void *taskList, void *fontMain, void *client, int param, u16 heapId);
extern void BTL_MSG_Init(u32 context, u32 clientIndex, u32 monTable, u32 heapId);
extern void BTL_MSG_Exit(void);
extern void BTLV_SCD_Delete(struct BtlvAuxView *auxView);
extern void BTLV_SCU_Delete(struct BtlvScu *scu);
extern void TCBL_Destroy(struct S02031140 *p);
extern void STRBUF_Delete(struct MsgBuf *msgBuffer);
extern unsigned int GF_FONT_Delete(void *ptr);
extern u32 GFL_HEAP_Free(void *p);
extern void TCBL_Main(struct Tcbl *p);
extern void BTLV_EFFECT_Main(void);
extern void *BTLV_EFFECT_CreateSetupFromBattleMain(struct BtlContext *context, struct BtlvScu *scu, u16 heapId);
extern void BTLV_EFFECT_Init(void *p, void *fontSub, u16 heapId);
extern void BTLV_SCU_SetupDisplay(struct BtlvScu *scu);
extern void BTLV_SCD_CreateInput(struct BtlvAuxView *auxView);
extern u32 BTL_CLIENT_IsMainStepActive(struct BtlClient *client);
extern void BTLV_SCU_StartEntryScene(struct BtlvScu *scu, u32 flag);
extern int BTLV_SCU_RunProc(struct BtlvScu *scu);
extern u32 BTL_CLIENT_IsRemote(struct BtlClient *client);
extern u16 BTL_CLIENT_GetQueuedCommandWord(struct BtlClient *client);
extern void BTLV_SCD_ShowCounterScreen(struct BtlvAuxView *auxView, BtlvCounterCmd *cmd);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void BTLV_SCU_InitMessage(struct BtlvMessage *msg, int kind, int id);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *pokeParam);
extern void BTLV_SCU_AppendMessageArg(struct BtlvMessage *msg, u32 val);
extern void BTLV_SCU_SetMessageParam(struct BtlvMessage *msg, u8 param);
extern void BTLV_SCD_StartActionMenuBackOnly(struct BtlvAuxView *auxView, struct BtlPokeParam *pokeParam, u8 canBack, u32 actionCursor);
extern int BTLV_SCD_WaitActionMenu(struct BtlvAuxView *auxView);
extern void BTLV_SCD_StartMoveInfoMenu(struct BtlvAuxView *auxView, struct BtlPokeParam *pokeParam, u32 actionCursor);
extern void BTLV_SCD_CloseInput(struct BtlvAuxView *auxView);
extern int BTLV_SCD_IsInputIdle(struct BtlvAuxView *auxView);
extern u32 WAZA_TOOL_GetParam(u16 id, u32 field);
extern void BTLV_SCU_StartWazaEffect(struct BtlvScu *scu, int viewPosA, int viewPosB, u32 sceneId, u32 argA, int argB, u8 flags);
extern int BTLV_SCU_RunWazaProc(struct BtlvScu *scu);
extern int BTL_POKEPARAM_GetValue(struct BtlPokeParam *pokeParam, int valueId);
extern int func_0209C0A4(int a, int b);
extern void BTLV_EFFECT_GaugeStartHpChangeAnimated(u32 a, u32 b);
extern void BTLV_EFFECT_StartDamageTintTask(int a, int b);
extern void BTLV_SCU_PlaySeUnlessMainStep(struct BtlvCore *core, int seId);
extern int BTLV_SCU_IsMonDamageAnimDone(struct BtlvScu *scu);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern int BTLV_EFFECT_IsBusy(void);
extern void BTLV_EFFECT_StartEffectWithColor(u32 a, u16 b, u8 c, int d, int e);
extern void GFL_USE_CancelChangeAndPlayBgm(u32 a, u32 b);
extern int GFL_USE_IsBgmPlaying(void);
extern void BTLV_EFFECT_ResumeVm(void);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u8 BTL_MAIN_GetSlotFromViewPos(struct BtlContext *context, u8 viewPos);
extern struct BtlPokeParam *BTL_SIDE_GetPokeAtPos(struct BtlMonTable *monTable, u8 slot);
extern u8 BTL_CLIENT_GetPointCounter(struct BtlClient *client);
extern void BTLV_SCD_StartActionMenu(struct BtlvAuxView *auxView, struct BtlPokeParam *pokeParam, int canBack, int clientSlot, u8 *actionCursor);
extern void BTLV_SCD_StartTargetMenu(struct BtlvAuxView *auxView, struct BtlPokeParam *pokeParam, u8 *actionCursor);
extern int BTLV_SCD_WaitTargetMenu(struct BtlvAuxView *auxView);
extern void BTLV_SCD_StartMoveMenu(struct BtlvAuxView *auxView, struct BtlPokeParam *pokeParam, u8 *cursor);
extern void BTLV_SCD_StartRotateMenu(struct BtlvAuxView *auxView, u32 *entry, u8 *cursor);
extern int BTLV_SCD_WaitMoveMenu(struct BtlvAuxView *auxView);
extern void BTLV_SCD_ReopenMenu(struct BtlvAuxView *auxView);
extern int BTLV_SCD_IsTargetChosen(struct BtlvAuxView *auxView);
extern void BTLV_EFFECT_StartIntroEffect(void);
extern void BTLV_SCD_CancelMenus(struct BtlvAuxView *auxView);
extern void BTLV_SCD_CloseInputIfOpen(struct BtlvAuxView *auxView);
extern void *BTL_MAIN_SyncSideParty(void *context, u32 clientIndex);
extern int BTL_MAIN_IsCommMulti(void *context);
extern void *BTL_MAIN_SyncPartnerSideParty(void *context, u32 clientIndex);
extern u8 BTL_MAIN_IsSecondTeamClient(void *context, u32 clientIndex);
extern u32 BTL_MAIN_GetRule(void *context);
extern int BTL_MAIN_GetPositionsPerClientThunk(void *context, u32 clientIndex);
extern int BTLV_SCD_GetInputFlags(struct BtlvAuxView *auxView);
extern void *BTLV_EFFECT_GetOwner(void);
extern void *BTLV_EFFECT_GetPalanm(void);
extern void *BTL_MAIN_GetGameData(void *context);
extern int BTL_MAIN_GetCompetitor(void *context);
extern u32 BTL_PICK_GetCount(u8 *choiceFlags);
extern u8 BTL_PICK_GetSlot(u8 *choiceFlags, u8 index);
extern void BTLV_SCD_StartInputSlideIn(struct BtlvAuxView *auxView, int mode);
extern int BTLV_SCD_IsInputSlideDone(struct BtlvAuxView *auxView);
extern void BTLV_SCD_OnSlideInDone(struct BtlvAuxView *auxView);
extern void BTL_PICK_Push(u8 *choiceFlags, u8 index, u8 slot);
extern void BTLV_SCD_StartInputSlideOut(struct BtlvAuxView *auxView);
extern void BTLV_SCD_OnSlideOutStart(struct BtlvAuxView *auxView);
extern void B_PLIST_MAIN_Create(BtlvPlistWork *plist);
extern void *BTL_MAIN_GetMyItem(void *context);
extern void *BTL_MAIN_GetMapMatrix(void *context);
extern void *BTL_MAIN_GetRegulationRules(void *context);
extern int BTL_MAIN_CheckSetupStatusFlag(void *context, int flag);
extern u8 BTL_SIDE_CountLivingOfClient(struct BtlMonTable *monTable, int clientId);
extern void *BTL_CLIENT_GetSideData(void *client);
extern u8 BTL_SLOT_GetCount(void *pokeList);
extern void *BTL_SLOT_GetPokeParam(void *pokeList, u32 index);
extern int BTL_POKEPARAM_HasSick(void *pokeParam, int sickId);
extern int BTL_ID_IsBagItemUseBlocked(u16 itemId, u8 itemUseKind);
extern void B_BAG_MAIN_Create(BtlvBagWork *bag);
extern void MYITEM_SAVEDATA_SetBattlePocketCursors(struct MyItemSave *save, const s16 *cursorPos, const s16 *scrollPos);
extern void MYITEM_SAVEDATA_SetLastBattleItem(struct MyItemSave *save, u16 item, u16 page);
extern u8 BTL_MAIN_GetViewPosOfSlot(struct BtlContext *context, u32 slot);
extern void BTLV_SCU_StartMonDamageAnim(struct BtlvScu *scu, u8 slot, u16 animId, int mainStepActive);
extern void BTLV_SCU_StartMonMotion(struct BtlvScu *scu, u8 slot, u32 animId);
extern int BTLV_SCU_IsMonMotionDone(struct BtlvScu *scu);
extern int BTL_MAIN_GetTrainerSlotOfPoke(struct BtlContext *context, struct BtlMonTable *monTable, u32 pokeId);
extern int BTLV_SCU_UpdateMessage(struct BtlvScu *scu);
extern int BTLV_EFFECT_IsPokeSpriteLoaded(int viewPos);
extern int BTLV_EFFECT_GetPokeSpriteState(int viewPos);
extern void BTLV_EFFECT_StartPokeEffectId285(u32 viewPos);
extern void BTLV_EFFECT_StartPokeEffectId286(u32 viewPos);
extern void BTLV_SCU_StartHpGaugeUpdate(struct BtlvScu *scu, int slot, u32 mainStepActive);
extern void BTLV_EFFECT_StartEffectOnPoke(int viewPos, u32 effectId);
extern void BTLV_EFFECT_StartEffectBetweenPokes(int viewPos, int effectId, u32 param);
extern void BTLV_SCU_StartMonExit(struct BtlvScu *scu, int slot, u32 mainStepActive);
extern void BTLV_SCU_StartMonWithdraw(struct BtlvScu *scu, u16 viewPos, u16 effectId, int mainStepActive);
extern void BTLV_SCU_StartMonSendOut(struct BtlvScu *scu, u8 slot, int clientId, u8 pokeIdx, int mainStepActive);
extern int BTLV_SCU_IsMonSendOutDone(struct BtlvScu *scu);
extern void BTL_MSG_FormatWithSide(struct MsgBuf *buf, u16 msgId, u32 *args);
extern void BTL_MSG_DispatchTagged(struct MsgBuf *buf, u16 msgId, u32 *args);
extern void BTL_MSG_GetUiString(struct MsgBuf *buf, u32 msgId);
extern void BTL_MSG_BuildUiString(struct MsgBuf *buf, u32 msgId, u32 *args);
extern void BTL_MSG_BuildTrainerString(struct MsgBuf *buf, u32 msgId, u32 *args);
extern void BTL_MSG_BuildItemUse(struct MsgBuf *buf, u8 clientId, u16 item);
extern void BTL_MSG_BuildPlainEntry(struct MsgBuf *buf, u16 msgId, int arg);
void STRBUF_Copy(struct MsgBuf *dst, struct MsgBuf *src);
extern u32 TPOKE_DATA_FindRecord(u32 trainerId, u32 msgIndex, u32 heapId);
extern void TPOKE_DATA_ReadRecordString(int trainerId, int msgIndex, struct MsgBuf *dest, u32 heapId);
extern void BTLV_SCU_StartMessage(struct BtlvScu *scu, struct MsgBuf *buf, u16 speed, u32 flag);
extern void BTLV_EFFECT_SetIntroState(int a);
extern void BTLV_SCU_PrintWaitMessage(struct BtlvScu *scu);
extern int BTLV_SCU_UpdateWaitMessage(struct BtlvScu *scu);
extern void BTLV_SCU_NoOp(struct BtlvScu *scu);
extern void BTLV_SCU_StartPosCueEffect(struct BtlvScu *scu, int viewPos);
extern int BTLV_SCU_IsPosCueEffectDone(struct BtlvScu *scu, int viewPos);
extern void BTLV_SCU_StartMonGraphicSwap(struct BtlvScu *scu, u32 viewPos, u32 mode);
extern void BTLV_SCU_StartMonGraphicSwapFrom(struct BtlvScu *scu, u32 viewPos, u32 srcViewPos, u32 mode);
extern u8 BTL_MAIN_GetClientTrainerIndex(struct BtlContext *context, u32 clientId, u8 pos);
extern void BTLV_EFFECT_SetPokeSpriteVisible(u32 rotateA, u32 rotateB);
extern void BTLV_SCU_HideMonPair(struct BtlvScu *scu, int monSlotA, int monSlotB);
extern int BTLV_SCU_ShowMonPair(struct BtlvScu *scu, int monSlotA, int monSlotB);
extern struct BtlMonTable *BTL_SIDE_GetSlotOfClientThunk(struct BtlMonTable *monTable, int clientIndex);
extern void BTLV_SCD_ShowRotateScreen(void *auxView, u8 *work);
extern int BTLV_SCU_IsHpGaugeIdle(struct BtlvScu *scu);
extern int BTLV_SCU_IsMonExitDone(struct BtlvScu *scu);
extern void BTLV_SCU_LoadAndShowMon(struct BtlvScu *scu, u32 slot);
extern int BTLV_SCU_IsMonLoadDone(struct BtlvScu *scu);
extern int BTLV_SCU_IsMonWithdrawDone(struct BtlvScu *scu);
extern void BTLV_SCU_StartMonFormChange(struct BtlvScu *scu, u32 slot, u32 mode);
extern int BTLV_SCU_IsMonFormChangeDone(struct BtlvScu *scu);
extern int BTLV_SCU_IsMonGraphicSwapDone(struct BtlvScu *scu);
extern void BTLV_SCU_StartMsgWinFadeOutTask(struct BtlvScu *scu);
extern int BTLV_SCU_IsMsgWinFadeOutTaskDone(struct BtlvScu *scu);
extern int BTLV_SCU_ConsumeMessageEnded(struct BtlvScu *scu);
extern void BTLV_SCU_PrintMessageInstant(struct BtlvScu *scu, struct MsgBuf *buf);
extern void BTLV_SCU_StartNamePlate(struct BtlvScu *scu, u32 slot, u32 flag);
extern int BTLV_SCU_ProcNamePlateAt(struct BtlvScu *scu, u32 slot);
extern void BTLV_SCU_HideNamePlateAt(struct BtlvScu *scu, u32 slot);
extern int BTLV_SCU_IsNamePlateHiddenAt(struct BtlvScu *scu, u32 slot);
extern void BTLV_SCU_RefreshNamePlateAt(struct BtlvScu *scu, u32 slot);
extern int BTLV_SCU_ProcNamePlateMosaicAt(struct BtlvScu *scu, u32 slot);
extern int BTLV_SCD_PollTouchKey(struct BtlvAuxView *auxView, u8 *outMode);
extern void BTLV_SCD_CloseInputScreen(struct BtlvAuxView *auxView);
extern void BTLV_EFFECT_StartPokeSpriteTransitionTask(int kind, int side, int flag);
extern void BTLV_SCU_HideMon(struct BtlvScu *scu, int monSlot);
extern int BTLV_SCU_ShowMon(struct BtlvScu *scu, int monSlot);
extern void BTLV_SCD_OpenChoiceScreen(struct BtlvAuxView *auxView, BtlvYesNoWork *work);
extern int BTLV_SCD_PollChoiceScreen(struct BtlvAuxView *auxView, int *outResult);
extern void BTLV_SCD_BeginCloseSequence(struct BtlvAuxView *auxView);
extern int BTLV_SCD_RunCloseSequence(struct BtlvAuxView *auxView);
extern int BTLV_SCD_PollCounterTouch(struct BtlvAuxView *auxView);
extern void BTLV_SCU_StartBallWindowOpen(struct BtlvScu *scu, int pokeParam, struct BtlExpResult *result);
extern int BTLV_SCU_UpdateBallWindowOpen(struct BtlvScu *scu);
extern void BTLV_SCU_StartBallWindowRefresh(struct BtlvScu *scu);
extern int BTLV_SCU_UpdateBallWindowRefresh(struct BtlvScu *scu);
extern void BTLV_SCU_StartBallWindowClose(struct BtlvScu *scu);
extern int BTLV_SCU_UpdateBallWindowClose(struct BtlvScu *scu);
extern void BTLV_SCU_StartFadeIn(struct BtlvScu *scu);
extern void BTLV_SCU_ClearWaitWindow(struct BtlvScu *scu);
extern int BTLV_SCU_GetWaitState(struct BtlvScu *scu);
int BTLV_CORE_CheckPartySlotPair(void *party, int slot);
int BTLV_CORE_CheckPartySlotCondition(void *party, int slot);
int BTLV_CORE_CheckEitherSlotPair(void *party, int slotA, int slotB);
void BTLV_CORE_EventRedirectMove(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1);
void BTLV_CORE_EventCounterMove(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1);
void BTLV_CORE_EventQueueMoveNotice(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1);
void BTLV_CORE_EventScaleDamage(int factor);
void BTLV_CORE_EventSetFlagIfAttacker(int unusedArg0, int unusedArg1, int pokeId, int unusedArg2);
int BTLV_CORE_EventTrySetFlagIfAttacker(int unusedArg0, int unusedArg1, int pokeId);
void BTLV_CORE_LoadDsiOverlay(void);
void BTLV_CORE_UnloadDsiOverlay(void);
u32 BTLV_CORE_GetZeroMasked(void);
int BTLV_CORE_IsSlotKindNone(BtlvSlot slot);
int BTLV_CORE_MakeSlotKind2Index(u32 index);
int BTLV_CORE_MakeSlotKind2(u32 index, u32 value);
int BTLV_CORE_MakeSlotKind3(u32 index);
int BTLV_CORE_MakeSlotKind1Empty(void);
int BTLV_CORE_MakeSlotKind1Value(u32 value);
int BTLV_CORE_MakeSlotKind1(u32 index, u32 value);
int BTLV_CORE_MakeSlotKind4(u32 hi, u32 lo);
int BTLV_CORE_MakeSlotKind1Index15(void);
int BTLV_CORE_IsSlotKind1Index15(BtlvSlot slot);
u8 BTLV_CORE_GetSlotPosition(BtlvSlot slot);
void BTLV_CORE_SetSlotPosition(BtlvSlot *slot, u8 pos);
u8 BTLV_CORE_GetSlotLow(BtlvSlot slot);
void BTLV_CORE_SetSlotValue(BtlvSlot *slot, u16 value);
u16 BTLV_CORE_GetSlotValue(BtlvSlot slot);
void BTLV_CORE_SetSlotFlag(BtlvSlot *slot, int flag);
u32 BTLV_CORE_GetSlotFlag(BtlvSlot slot);
void BTLV_CORE_AddSlotIndex(BtlvSlot *slot, u32 delta);
void BTLV_CORE_SetSlotIndex(BtlvSlot *slot, int count);
u16 BTLV_CORE_PackBytes(u32 high, u32 low);
int BTLV_CORE_PackByteTwice(int byte);
u8 BTLV_CORE_GetHighByte(s32 word);
int BTLV_CORE_GetLowByte(int word);
void BTLV_CORE_SplitBytes(int word, unsigned char *high, unsigned char *low);
int BTLV_CORE_HasByte(int word, int byte);
int BTLV_CORE_BytesOverlap(int wordA, int wordB);
int BTLV_CORE_BytesEqual(int word);
void BTLV_CORE_LoadOverlays(unsigned short heapId);
void BTLV_CORE_UnloadOverlays(void);
void BTLV_CORE_ResetDisplay(u16 heapId);
void BTLV_CORE_InitDisplay(u16 heapId);
void BTLV_CORE_ExitDisplay(void);
struct BtlvCore *BTLV_CORE_Create(void *context, void *client, u32 monTable, int param, u16 heapId);
void BTLV_CORE_Delete(struct BtlvCore *core);
void BTLV_CORE_Update(struct BtlvCore *core);
void BTLV_CORE_StartOpening(struct BtlvCore *core, u32 state);
int BTLV_CORE_PollOpening(struct BtlvCore *core);
void *BTLV_CORE_GetTaskWork(struct BtlvCore *core, int size);
int BTLV_CORE_StepOpeningEntry(struct BtlvCore *core, int *state, void *work);
int BTLV_CORE_StepOpeningDemo(struct BtlvCore *core, int *state, BtlvDemoWork *w);
struct BtlPokeParam *BTLV_CORE_GetPokeParamAtViewPos(struct BtlvCore *core, u32 viewPos);
int BTLV_CORE_StepActionMenu(struct BtlvCore *core, int *state, void *work);
int BTLV_CORE_StepTargetMenu(struct BtlvCore *core, int *state, void *work);
void BTLV_CORE_SetStep(struct BtlvCore *core, BtlvCoreStepFn stepFn);
void BTLV_CORE_ClearStep(struct BtlvCore *core);
int BTLV_CORE_RunStep(struct BtlvCore *core);
void BTLV_CORE_StartActionMenu(struct BtlvCore *core, struct BtlPokeParam *pokeParam, int canBack, u8 *cursor);
void BTLV_CORE_AbortActionMenu(struct BtlvCore *core);
int BTLV_CORE_PollActionMenu(struct BtlvCore *core);
void BTLV_CORE_StartMoveMenu(struct BtlvCore *core, struct BtlPokeParam *pokeParam, u8 *cursor);
void BTLV_CORE_StartMoveMenuForEntry(struct BtlvCore *core, u32 *entry, u8 *cursor);
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
void BTLV_CORE_IsMenuClosed(struct BtlvCore *core);
void BTLV_CORE_InitPartyWork(struct BtlvCore *core, BtlvPlistWork *plist, int mode, u8 slot, int modeParam);
void BTLV_CORE_StartPartyMenu(struct BtlvCore *core, const u8 *slotChoices, int slot, int canCancel, u8 *choiceFlags);
void BTLV_CORE_LockPartyChoice(struct BtlvCore *core);
int BTLV_CORE_PollPartyMenu(struct BtlvCore *core);
void BTLV_CORE_StartMoveHighlight(struct BtlvCore *core, u8 slot, u8 kind);
void BTLV_CORE_StartBagMenu(struct BtlvCore *core, int isComm, u8 pointCounter, u8 itemId, u8 isLastSlot, u8 foeSemiInvulnerable);
void BTLV_CORE_SkipBagPartyPrompt(struct BtlvCore *core);
int BTLV_CORE_PollBagMenu(struct BtlvCore *core);
u16 BTLV_CORE_GetSelectedItem(struct BtlvCore *core);
u8 BTLV_CORE_GetSelectedItemPocket(struct BtlvCore *core);
u8 BTLV_CORE_GetInputTargetSlot(struct BtlvCore *core);
u8 BTLV_CORE_GetInputResultFlag(struct BtlvCore *core);
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
int BTLV_CORE_WaitViewEffect(void);
void BTLV_CORE_StartViewEffectEx(struct BtlvCore *core, int viewPos, int effectId, u32 param);
int BTLV_CORE_WaitViewEffectEx(int viewPos);
void BTLV_CORE_StartMonReset(struct BtlvCore *core, int slot);
int BTLV_CORE_WaitMonReset(struct BtlvCore *core);
void BTLV_CORE_StartMonRefresh(struct BtlvCore *core, u32 slot);
int BTLV_CORE_WaitMonRefresh(struct BtlvCore *core);
void BTLV_CORE_StartMonEffectTask(struct BtlvCore *core, u16 viewPos, u16 effectId);
int BTLV_CORE_WaitMonEffectTask(struct BtlvCore *core);
void BTLV_CORE_StartMonSwap(struct BtlvCore *core, u8 slot, u8 clientId, u8 pokeIdx);
int BTLV_CORE_WaitMonSwap(struct BtlvCore *core);
int BTLV_CORE_ProcMonSwap(int *state, struct BtlvCore *core);
void BTLV_CORE_BuildMessage(struct BtlvMessage *msg, struct MsgBuf *buf);
void BTLV_CORE_CopyMessageBuffer(struct BtlvCore *core, struct MsgBuf *src);
void BTLV_CORE_BuildMessageToBuffer(struct BtlvCore *core, struct BtlvMessage *msg);
void BTLV_CORE_PrintMessageBuffer(struct BtlvCore *core);
void BTLV_CORE_BuildAndPrintMessage(struct BtlvCore *core, struct BtlvMessage *msg);
void BTLV_CORE_BuildAndPrintMessageFlag(struct BtlvCore *core, struct BtlvMessage *msg, int flag);
void BTLV_CORE_BuildAndPrintMessageNow(struct BtlvCore *core, struct BtlvMessage *msg);
void BTLV_CORE_PrintSideMessage(struct BtlvCore *core, u16 msgId, u32 *args);
void BTLV_CORE_PrintTaggedMessage(struct BtlvCore *core, u16 msgId, u32 *args);
int BTLV_CORE_PrintTrainerMessage(struct BtlvCore *core, u16 trainerId, u16 msgIndex);
void BTLV_CORE_PrintItemUseMessage(struct BtlvCore *core, u8 clientId, u16 item);
int BTLV_CORE_WaitMessage(struct BtlvCore *core);
int BTLV_CORE_ConsumeMessageFlag(struct BtlvCore *core);
void BTLV_CORE_StartPrintMessage(struct BtlvCore *core, struct MsgBuf *buf, u16 speed, u32 flag);
void BTLV_CORE_PrintMessageNow(struct BtlvCore *core, struct MsgBuf *buf);
void BTLV_CORE_ShowPortrait(struct BtlvCore *core, u32 slot, u32 flag);
int BTLV_CORE_UpdatePortraitSlideIn(struct BtlvCore *core, u32 slot);
void BTLV_CORE_StartPortraitSlideOut(struct BtlvCore *core, u32 slot);
int BTLV_CORE_WaitPortraitSlideOut(struct BtlvCore *core, u32 slot);
void BTLV_CORE_ReloadPortrait(struct BtlvCore *core, u32 slot);
int BTLV_CORE_UpdatePortraitMosaic(struct BtlvCore *core, u32 slot);
void BTLV_CORE_StartViewEffect262(struct BtlvCore *core, int viewPos);
void BTLV_CORE_StartViewEffect261(struct BtlvCore *core, int viewPos);
int BTLV_CORE_WaitViewEffectDone(struct BtlvCore *core, int viewPos);
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
void BTLV_CORE_StartBallWindowOpen(struct BtlvCore *core, int pokeParam, struct BtlExpResult *result);
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
extern u8 ov140_id[];
extern int gBtlvCoreDsiOverlayLoaded;
extern char ov094_id[], ov095_id[], ov096_id[];
extern const struct DispVram gBtlvCoreVramBanks;
extern struct DispConfig gBtlvCoreDispConfig;
extern const struct Cfg gBtlvCoreBgConfig;
extern const char gBtlvCoreFileName[];
extern const struct BtlvStateEntry gBtlvOpeningStepTable[];
extern u8 ov196_id[];
extern u8 ov198_id[];
extern u8 ov197_id[];



int BTLV_CORE_CheckPartySlotPair(void *party, int slot)
{
    void *entry;
    int typeId;
    u16 level;

    entry = BTL_SERVER_FLOW_GetPokeParam(party, slot);
    typeId = BTL_POKEPARAM_GetSpecies(entry);
    level = (int)BTL_POKEPARAM_GetItem(entry);
    if (HAND_COMMON_IsItemBoundToSpecies(typeId, level) != 0)
        return 1;
    return 0;
}



/*
 * 2026-10-03: the `cmp r0,#1; beq; bne` pair is a disjunction of two tests that both
 * compare against 1 (likely two constants with the same value); the compiler keeps
 * one branch per operand.
 */
int BTLV_CORE_CheckPartySlotCondition(void *party, int slot)
{
    int result;

    if (BTL_SERVER_FLOW_GetCompetitor(party) == 0) {
        result = BTL_MAIN_PokeIdToClientIdThunk(slot);
        if (result == 1 || result == 1)
            return 1;
    }
    return 0;
}



int BTLV_CORE_CheckEitherSlotPair(void *party, int slotA, int slotB)
{
    void *entryA;
    void *entryB;
    int typeId;
    u16 level;

    if (BTLV_CORE_CheckPartySlotCondition(party, slotA) != 0)
        return 1;
    if (BTLV_CORE_CheckPartySlotPair(party, slotB) != 0)
        return 1;
    entryA = BTL_SERVER_FLOW_GetPokeParam(party, slotA);
    entryB = BTL_SERVER_FLOW_GetPokeParam(party, slotB);
    typeId = BTL_POKEPARAM_GetSpecies(entryA);
    level = (int)BTL_POKEPARAM_GetItem(entryB);
    if (HAND_COMMON_IsItemBoundToSpecies(typeId, level) != 0)
        return 1;
    return 0;
}



void BTLV_CORE_EventRedirectMove(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1)
{
    u8 attackerId;
    u16 moveId;

    attackerId = BTL_EVENT_GetVar(2);
    if (BTL_MAIN_IsPokeSamePair(attackerId, pokeId) == 0) {
        moveId = BTL_EVENT_GetVar(0x12);
        if (WAZA_TOOL_GetCategory(moveId) == 0xb) {
            if (WAZA_TOOL_GetFlag(moveId, 4) != 0) {
                if (BTL_EVENT_OverwriteVar(0x22, 0x19) != 0)
                    BTL_SERVER_FLOW_PushMoveQueueWithPos(eventCtx, pokeId, attackerId);
            }
        }
    }
}



void BTLV_CORE_EventCounterMove(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1)
{
    u8 defenderId;
    u16 moveId;
    int flagBit;

    flagBit = 4;
    if (pokeId == BTL_EVENT_GetVar(4)) {
        if (BTL_EVENT_GetVar(0x4e) == 0) {
            if (BTL_POKEPARAM_IsSemiInvulnerable(BTL_SERVER_FLOW_GetPokeParam(eventCtx, pokeId)) == 0) {
                moveId = BTL_EVENT_GetVar(0x12);
                if (WAZA_TOOL_GetFlag(moveId, flagBit) != 0) {
                    flagBit = 1;
                    if (BTL_EVENT_OverwriteVar(0x40, 1) != 0) {
                        defenderId = BTL_EVENT_GetVar(3);
                        BTL_SERVER_FLOW_PushMoveQueueWithPos(eventCtx, pokeId, defenderId);
                        BTL_EVENT_OverwriteVar(0x51, flagBit);
                    }
                }
            }
        }
    }
}



void BTLV_CORE_EventQueueMoveNotice(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1)
{
    struct BtlvEventRec *rec;
    int listKind;

    listKind = 2;
    if (pokeId == BTL_EVENT_GetVar(2)) {
        if (BTL_POKEPARAM_IsSemiInvulnerable(BTL_SERVER_FLOW_GetPokeParam(eventCtx, pokeId)) == 0) {
            rec = BTL_SERVER_FLOW_AllocCmdRecord(eventCtx, 4, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(rec->list, listKind, 0x2fc);
            BTL_SERVER_FLOW_AppendMsgRecordArg(rec->list, pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg(rec->list, BTL_EVENT_GetVar(0x12));
            BTL_SERVER_FLOW_CommitCmdRecord(eventCtx, rec);
        }
    }
}



void BTLV_CORE_EventScaleDamage(int factor)
{
    factor *= BTL_EVENT_GetVar(0x30);
    BTL_EVENT_OverwriteVar(0x30, factor);
}



void BTLV_CORE_EventSetFlagIfAttacker(int unusedArg0, int unusedArg1, int pokeId, int unusedArg2)
{
    if (BTL_MAIN_IsPokeSamePair((u8)BTL_EVENT_GetVar(2), pokeId) != 0)
        BTL_EVENT_OverwriteVar(0x51, 1);
}



int BTLV_CORE_EventTrySetFlagIfAttacker(int unusedArg0, int unusedArg1, int pokeId)
{
    if (BTL_MAIN_IsPokeSamePair((u8)BTL_EVENT_GetVar(2), pokeId) != 0) {
        if (BTL_EVENT_OverwriteVar(0x51, 1) != 0)
            return 1;
    }
    return 0;
}



void BTLV_CORE_LoadDsiOverlay(void)
{
    if (OS_GetConsoleType() & 0x02000000) {
        GF_OVERLAY_Load(ov140_id);
        gBtlvCoreDsiOverlayLoaded = 1;
    } else {
        gBtlvCoreDsiOverlayLoaded = 0;
    }
}



void BTLV_CORE_UnloadDsiOverlay(void)
{
    if (gBtlvCoreDsiOverlayLoaded != 0) {
        GF_OVERLAY_Unload(ov140_id);
        gBtlvCoreDsiOverlayLoaded = 0;
    }
}



/*
 * Returns 0 with a 4-byte frame that nothing ever stores to.  Taking the address of a local array forces the slot, and the optimizer then removes both the store and the reload (nothing outside can alias it), so the frame and the register-resident value both survive.  A scalar `u32 v = 0; v &= ~7u;` folds to 4 bytes, which is why O28's residue could not reach this; the address-taken local is the missing form.
 * stand-in: the word is reached through a cast of the byte array; a u32 array, a union or an address-taken u32 each change the bytes.
 */
u32 BTLV_CORE_GetZeroMasked(void) { u8 bytes[4]; *(u32 *)bytes = 0; return *(u32 *)bytes & ~7u; }



int BTLV_CORE_IsSlotKindNone(BtlvSlot slot)
{
    if (slot.pos.kind == 0)
        return 1;
    return 0;
}



/*
 * 2026-10-03 EXACT (wave B3, lane 21): the second pool word is 0xFE0001FF, not
 * 0x000001FF. It is the value:16 clear mask of the BTLV_CORE_MakeSlotKind2 slot, so this is
 * BTLV_CORE_MakeSlotKind2 with value = 0 and extra left zero from the initialiser.
 */
int BTLV_CORE_MakeSlotKind2Index(u32 index)
{
    BtlvSlot slot = {0};

    slot.param.kind = 2;
    slot.param.index = index & 0x3f;
    slot.param.value = 0;
    return slot.word;
}



int BTLV_CORE_MakeSlotKind2(u32 index, u32 value)
{
    BtlvSlot slot = {0};

    slot.param.kind = 2;
    slot.param.index = index & 0x3f;
    slot.param.value = value;
    return slot.word;
}



/*
 * Recursive MATCH unblocker: named callee of the parked ov093 HAND_ITEM_DestinyKnot_Infatuate
 * (+0080, `BTLV_CORE_MakeSlotKind3(c)` stored at record +8).  Packs a 3-bit constant
 * (3) with the low six bits of the argument shifted left by three, as a
 * bitfield union read back as a word; the empty frame is the compiler's
 * storage for the union local, and `= {0}` is what emits `movs r2,#0`
 * instead of reading the uninitialised slot back.
 *
 * Addresses are Black-image addresses.
 */
int BTLV_CORE_MakeSlotKind3(u32 index)
{
    BtlvSlot slot = {0};

    slot.indexOnly.kind = 3;
    slot.indexOnly.index = index & 0x3f;
    return slot.word;
}



int BTLV_CORE_MakeSlotKind1Empty(void)
{
    BtlvSlot slot = {0};

    slot.indexOnly.kind = 1;
    return slot.word;
}



int BTLV_CORE_MakeSlotKind1Value(u32 value)
{
    BtlvSlot slot = {0};
    slot.param.kind = 1;
    slot.param.value = value;
    return slot.word;
}



/*
 * Unlabelled leaf, the only blocker of BTL_CALC_MakeSickContFromSpec's MATCH (case 1 of its
 * kind switch).  Sibling of BTLV_CORE_MakeSlotKind3: packs kind 1, a 6-bit field and a
 * 16-bit field into a one-word bitfield.
 */
int BTLV_CORE_MakeSlotKind1(u32 index, u32 value)
{
    BtlvSlot slot = {0};
    slot.param.kind = 1;
    slot.param.index = index & 0x3f;
    slot.param.value = value;
    return slot.word;
}



int BTLV_CORE_MakeSlotKind4(u32 hi, u32 lo)
{
    BtlvSlot slot = {0};

    slot.pos.kind = 4;
    slot.pos.lo = lo & 0x3f;
    slot.pos.hi = hi & 0x3f;
    return slot.word;
}



int BTLV_CORE_MakeSlotKind1Index15(void)
{
    BtlvSlot slot = {0};

    slot.indexOnly.kind = 1;
    slot.indexOnly.index = 0xf;
    return slot.word;
}



int BTLV_CORE_IsSlotKind1Index15(BtlvSlot slot)
{
    if (slot.pos.kind == 1 && slot.pos.lo == 0xf)
        return 1;
    return 0;
}



u8 BTLV_CORE_GetSlotPosition(BtlvSlot slot)
{
    if (slot.pos.kind == 3)
        return slot.pos.lo;
    if (slot.pos.kind == 4)
        return slot.pos.hi;
    return 0x1f;
}



void BTLV_CORE_SetSlotPosition(BtlvSlot *slot, u8 pos)
{
    if (slot->pos.kind == 3)
        slot->pos.lo = pos;
    else if (slot->pos.kind == 4)
        slot->pos.hi = pos;
}



u8 BTLV_CORE_GetSlotLow(BtlvSlot slot)
{
    if (slot.pos.kind == 2) return slot.pos.lo;
    if (slot.pos.kind == 4) return slot.pos.lo;
    return 0;
}



void BTLV_CORE_SetSlotValue(BtlvSlot *slot, u16 value)
{
    if (slot->param.kind == 1) slot->param.value = value;
    else if (slot->param.kind == 3) slot->param.value = value;
    else if (slot->param.kind == 4) slot->wideParam.value = value;
    else if (slot->param.kind == 2) slot->param.value = value;
}



u16 BTLV_CORE_GetSlotValue(BtlvSlot slot)
{
    if (slot.param.kind == 1) return slot.param.value;
    if (slot.param.kind == 3) return slot.param.value;
    if (slot.param.kind == 4) return slot.wideParam.value;
    if (slot.param.kind == 2) return slot.param.value;
    return 0;
}



void BTLV_CORE_SetSlotFlag(BtlvSlot *slot, int flag)
{
    if (slot->flagMid.kind == 1) slot->flagMid.flag = flag;
    else if (slot->flagMid.kind == 3) slot->flagMid.flag = flag;
    else if (slot->flagMid.kind == 4) slot->flagHigh.flag = flag;
    else if (slot->flagMid.kind == 2) slot->flagMid.flag = flag;
}



u32 BTLV_CORE_GetSlotFlag(BtlvSlot slot)
{
    if (slot.flagMid.kind == 1) return slot.flagMid.flag;
    if (slot.flagMid.kind == 3) return slot.flagMid.flag;
    if (slot.flagMid.kind == 4) return slot.flagHigh.flag;
    if (slot.flagMid.kind == 2) return slot.flagMid.flag;
    return 0;
}



void BTLV_CORE_AddSlotIndex(BtlvSlot *slot, u32 delta)
{
    if (slot->indexOnly.kind == 2 && slot->indexOnly.index < 8) slot->indexOnly.index = slot->indexOnly.index + delta;
    if (slot->indexOnly.kind == 4 && slot->indexOnly.index < 8) slot->indexOnly.index = slot->indexOnly.index + delta;
}



void BTLV_CORE_SetSlotIndex(BtlvSlot *slot, int count)
{
    if (slot->indexOnly.kind == 2 && slot->indexOnly.index < 8) slot->indexOnly.index = count;
    if (slot->indexOnly.kind == 4 && slot->indexOnly.index < 8) slot->indexOnly.index = count;
}



/* 021E8CE0  ((high & 0xff) << 8) | (low & 0xff) as u16 */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: lsls r0, r0, #0x18; lsrs r2, r0, #0x10; lsls r0, r1, #0x18; lsrs r0, r0, #0x18; orrs r0, r2; lsls r0, r0, #0x10; lsrs r0, r0, #0x10; bx lr.
 */
u16 BTLV_CORE_PackBytes(u32 high, u32 low) { return (u16)(((high & 0xff) << 8) | (low & 0xff)); }



int BTLV_CORE_PackByteTwice(int byte)
{
    return BTLV_CORE_PackBytes(byte, byte);
}



/* 021E8CFC  asrs r0,r0,#8; lsls #0x18; lsrs #0x18 */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: asrs r0, r0, #8; lsls r0, r0, #0x18; lsrs r0, r0, #0x18; bx lr.
 */
u8 BTLV_CORE_GetHighByte(s32 word) { return (u8)(word >> 8); }



int BTLV_CORE_GetLowByte(int word)
{
    return (unsigned char)word;
}



void BTLV_CORE_SplitBytes(int word, unsigned char *high, unsigned char *low)
{
    *high = BTLV_CORE_GetHighByte(word);
    *low = BTLV_CORE_GetLowByte(word);
}



int BTLV_CORE_HasByte(int word, int byte)
{
    if (byte == BTLV_CORE_GetHighByte(word)) {
        return 1;
    }
    if (byte == BTLV_CORE_GetLowByte(word)) {
        return 1;
    }
    return 0;
}



int BTLV_CORE_BytesOverlap(int wordA, int wordB)
{
    if (BTLV_CORE_GetHighByte(wordA) == BTLV_CORE_GetHighByte(wordB)) return 1;
    if (BTLV_CORE_GetHighByte(wordA) == BTLV_CORE_GetLowByte(wordB)) return 1;
    if (BTLV_CORE_GetLowByte(wordA) == BTLV_CORE_GetHighByte(wordB)) return 1;
    if (BTLV_CORE_GetLowByte(wordA) == BTLV_CORE_GetLowByte(wordB)) return 1;
    return 0;
}



int BTLV_CORE_BytesEqual(int word)
{
    if (BTLV_CORE_GetHighByte(word) == BTLV_CORE_GetLowByte(word)) {
        return 1;
    }
    return 0;
}



void BTLV_CORE_LoadOverlays(unsigned short heapId)
{
    BTLV_CORE_InitDisplay(heapId);
    GF_OVERLAY_Load(ov094_id);
    GX_SetBankForLCDC(0x80);
    GF_OVERLAY_Load(ov095_id);
    if (GFL_NET_IsNetTypeWifi() == 0) {
        GF_OVERLAY_Load(ov096_id);
    }
}



void BTLV_CORE_UnloadOverlays(void)
{
    BTLV_CORE_ExitDisplay();
    GF_OVERLAY_Unload(ov094_id);
    GF_OVERLAY_Unload(ov095_id);
    if (GFL_NET_IsNetTypeWifi() == 0) {
        GF_OVERLAY_Unload(ov096_id);
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
    GF_FONT_ResetTextColor();
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
    CLACT_InitSystem(&gBtlvCoreBgConfig, &gBtlvCoreVramBanks, heapId);
}



void BTLV_CORE_ExitDisplay(void)
{
    BTLV_EFFECT_Exit();
    CLACT_ExitSystem();
    BMP_WIN_Exit();
    BG_SYS_Delete();
    G3D_SYSTEM_Exit();
}



struct BtlvCore *BTLV_CORE_Create(void *context, void *client, u32 monTable, int param, u16 heapId)
{
    struct BtlvCore *core;
    core = GFL_HEAP_Alloc(heapId, 0x188, 0, gBtlvCoreFileName, 0x12d);
    core->context = context;
    core->client = client;
    core->monTable = (struct BtlMonTable *)monTable;
    core->clientIndex = BTL_CLIENT_GetClientId(client);
    core->state = 4;
    core->heapId = heapId;
    core->msgBuffer = STRBUF_Create(0x200, heapId);
    core->fontMain = GF_FONT_Create(0x17, 0, 0, 0, heapId);
    core->fontSub = GF_FONT_Create(0x17, 2, 0, 0, heapId);
    core->taskList = TCBL_Create(heapId, heapId, 0x40, 0x80);
    core->sceneUnit = BTLV_SCU_Create((u32)core, (u32)core->context, monTable, (u32)core->taskList, (u32)core->fontMain, (u32)core->fontSub, core->clientIndex, heapId);
    core->auxView = BTLV_SCD_Create(core, core->context, monTable, core->taskList, core->fontMain, core->client, param, heapId);
    core->stepFn = 0;
    core->stepState = 0;
    core->subStep = 0;
    BTL_MSG_Init((u32)context, core->clientIndex, monTable, heapId);
    return core;
}


/* Destroys the battle view core: message system, aux view, scene unit, task list, message buffer, fonts and the core itself. */
void BTLV_CORE_Delete(struct BtlvCore *core)
{
    BTL_MSG_Exit();
    BTLV_SCD_Delete(core->auxView);
    BTLV_SCU_Delete(core->sceneUnit);
    TCBL_Destroy(core->taskList);
    STRBUF_Delete(core->msgBuffer);
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
        scene = BTLV_EFFECT_CreateSetupFromBattleMain(core->context, core->sceneUnit, core->heapId);
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
int BTLV_CORE_StepOpeningDemo(struct BtlvCore *core, int *state, BtlvDemoWork *w)
{
    switch (*state) {
    case 0: {
        void *scene = BTLV_EFFECT_CreateSetupFromBattleMain(core->context, core->sceneUnit, core->heapId);
        BTLV_EFFECT_Init(scene, core->fontSub, core->heapId);
        GFL_HEAP_Free(scene);
        BTLV_SCU_SetupDisplay(core->sceneUnit);
        BTLV_SCD_CreateInput(core->auxView);
        w->msgBank = MSGDATA_CreateFromArchive(0, 2, 0x14, core->heapId);
        w->timer = 0;
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
            BTLV_SCD_StartMoveInfoMenu(core->auxView, core->pokeParam, (u32)core->actionCursor);
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
            BTLV_EFFECT_GaugeStartHpChangeAnimated(1, func_0209C0A4(BTL_POKEPARAM_GetValue(BTLV_CORE_GetPokeParamAtViewPos(core, 1), 0xE), 6));
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
            MSGDATA_ReadString(w->msgBank, 0, core->msgBuffer);
            BTLV_CORE_StartPrintMessage(core, core->msgBuffer, 0, 0);
            w->timer = 0x3C;
            (*state)++;
        }
        break;
    case 13:
        if (BTLV_CORE_WaitMessage(core) && --w->timer == 0) {
            BTLV_SCD_StartActionMenuBackOnly(core->auxView, core->pokeParam, core->canBack, (u32)core->actionCursor);
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
            MSGDATA_ReadString(w->msgBank, 1, core->msgBuffer);
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
            MSGDATA_Delete((struct Rec *)w->msgBank);
            (*state)++;
        }
        break;
    case 20:
        return 1;
    }
    return 0;
}



/* The battle Pokemon on a view position of the core's client side. */
struct BtlPokeParam *BTLV_CORE_GetPokeParamAtViewPos(struct BtlvCore *core, u32 viewPos)
{
    return BTL_SIDE_GetPokeAtPos(core->monTable, BTL_MAIN_GetSlotFromViewPos(core->context, viewPos));
}



/* Step of the action menu (Fight, Bag, Pokemon, Run): opens it on the aux view, then waits for the choice. */
int BTLV_CORE_StepActionMenu(struct BtlvCore *core, int *state, void *work)
{
    switch (*state) {
    case 0:
        BTLV_SCD_StartActionMenu(core->auxView, core->pokeParam, core->canBack, BTL_CLIENT_GetPointCounter(core->client), core->actionCursor);
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
        BTLV_SCD_StartTargetMenu(core->auxView, core->pokeParam, core->actionCursor);
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
    BTLV_SCD_StartMoveMenu(core->auxView, core->pokeParam, cursor);
    BTLV_CORE_SetStep(core, BTLV_CORE_StepMoveMenu);
}



void BTLV_CORE_StartMoveMenuForEntry(struct BtlvCore *core, u32 *entry, u8 *cursor)
{
    struct BtlPokeParam *pokeParam = (struct BtlPokeParam *)*entry;

    core->pokeParam = pokeParam;
    core->pokeId = BTL_POKEPARAM_GetPokeId(pokeParam);
    core->entry = entry;
    core->actionCursor = cursor;
    BTLV_SCD_StartRotateMenu(core->auxView, entry, cursor);
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



void BTLV_CORE_IsMenuClosed(struct BtlvCore *core) { BTLV_SCD_IsInputIdle(core->auxView); }



void BTLV_CORE_InitPartyWork(struct BtlvCore *core, BtlvPlistWork *plist, int mode, u8 slot, int modeParam)
{
    u32 clientIndex;
    int isNotComm;
    int hasPartner;
    clientIndex = BTL_CLIENT_GetClientId(core->client);
    plist->party = BTL_MAIN_SyncSideParty(core->context, clientIndex);
    if (mode != 3) hasPartner = BTL_MAIN_IsCommMulti(core->context);
    else hasPartner = 0;
    plist->isCommMulti = hasPartner;
    if (hasPartner) {
        plist->partnerParty = BTL_MAIN_SyncPartnerSideParty(core->context, clientIndex);
        plist->isSecondTeam = BTL_MAIN_IsSecondTeamClient(core->context, clientIndex);
    } else {
        plist->partnerParty = 0;
        plist->isSecondTeam = 0;
    }
    plist->mode = mode;
    if (BTL_MAIN_GetRule(core->context) != 3) plist->positionsPerClient = BTL_MAIN_GetPositionsPerClientThunk(core->context, clientIndex);
    else plist->positionsPerClient = 3;
    switch (mode) {
    case 4:
    case 5: hasPartner = slot; break;
    default: hasPartner = 0; break;
    }
    plist->modeSlot = hasPartner;
    plist->slot = slot;
    plist->modeParam = modeParam;
    plist->result = 0;
    plist->heapId = core->heapId;
    plist->fontMain = core->fontMain;
    plist->rule = BTL_MAIN_GetRule(core->context);
    plist->auxViewHandle = BTLV_SCD_GetInputFlags(core->auxView);
    plist->effectSys = BTLV_EFFECT_GetOwner();
    plist->effectSysAux = BTLV_EFFECT_GetPalanm();
    plist->gameData = BTL_MAIN_GetGameData(core->context);
    plist->choiceLocked = 0;
    isNotComm = 0;
    if (BTL_MAIN_GetCompetitor(core->context) != 3) isNotComm = 1;
    plist->allowBag = isNotComm;
    plist->exitFlag = 0;
    plist->done = 0;
}


void BTLV_CORE_StartPartyMenu(struct BtlvCore *core, const u8 *slotChoices, int slot, int canCancel, u8 *choiceFlags)
{
    u32 i;
    u32 count;

    if (slot < 0) slot = 0;
    BTLV_CORE_InitPartyWork(core, &core->plist, slotChoices[0xb], slot, canCancel);
    count = BTL_PICK_GetCount(choiceFlags);
    for (i = 0; i < count; i++) {
        if (i >= 2) break;
        core->plist.chosenSlots[i] = BTL_PICK_GetSlot(choiceFlags, i);
    }
    for (; i < 2; i++)
        core->plist.chosenSlots[i] = 6;
    choiceFlags[8] = 1;
    core->choiceFlags = choiceFlags;
    core->subStep = 0;
}



void BTLV_CORE_LockPartyChoice(struct BtlvCore *core)
{
    core->plist.choiceLocked = 1;
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
        if ((u8)(core->plist.mode + 0xff) <= 1) BTLV_SCD_StartInputSlideIn(core->auxView, 0);
        else BTLV_SCD_StartInputSlideIn(core->auxView, 1);
        GF_OVERLAY_Load(ov196_id);
        core->subStep++;
        break;
    case 1:
        if (BTLV_SCD_IsInputSlideDone(core->auxView)) {
            BTLV_SCD_OnSlideInDone(core->auxView);
            GF_OVERLAY_Load(ov198_id);
            B_PLIST_MAIN_Create(&core->plist);
            core->subStep++;
        }
        break;
    case 2:
        if (core->plist.done) {
            if (core->plist.mode != 5 && core->plist.choiceLocked == 0) {
                for (i = 0; i < 3; i++) {
                    if (core->plist.pickedSlots[i] != 0xff) {
                        BTL_PICK_Push(core->choiceFlags, i, core->plist.pickedSlots[i]);
                        BTL_PICK_GetCount(core->choiceFlags);
                        core->choiceFlags[8] = 0;
                    }
                }
            }
            GF_OVERLAY_Unload(ov198_id);
            BTLV_SCD_StartInputSlideOut(core->auxView);
            BTLV_SCD_OnSlideOutStart(core->auxView);
            core->subStep++;
        }
        break;
    case 3:
        if (BTLV_SCD_IsInputSlideDone(core->auxView)) core->subStep++;
        break;
    default:
        GF_OVERLAY_Unload(ov196_id);
        core->subStep = 0;
        return 1;
    }
    return 0;
}



void BTLV_CORE_StartMoveHighlight(struct BtlvCore *core, u8 slot, u8 kind)
{
    BTLV_CORE_InitPartyWork(core, &core->plist, 5, slot, 0);
    core->plist.result = kind;
    core->subStep = 0;
}



void BTLV_CORE_StartBagMenu(struct BtlvCore *core, int isComm, u8 pointCounter, u8 itemId, u8 isLastSlot, u8 foeSemiInvulnerable)
{
    u32 i;
    u32 count;
    void *pokeList;
    int flag;
    if (core->subStep) return;
    core->bag.myItem = BTL_MAIN_GetMyItem(core->context);
    core->bag.myItemSave = BTL_MAIN_GetMapMatrix(core->context);
    core->bag.isComm = isComm;
    core->bag.fontMain = core->fontMain;
    core->bag.heapId = core->heapId;
    core->bag.pointCounter = pointCounter;
    core->bag.lastItem = itemId;
    core->bag.selectedItem = 0;
    core->bag.auxViewHandle = BTLV_SCD_GetInputFlags(core->auxView);
    core->bag.skipPartyPrompt = 0;
    core->bag.regulationRules = BTL_MAIN_GetRegulationRules(core->context);
    flag = 0;
    if (BTL_MAIN_GetCompetitor(core->context) != 3) flag = 1;
    core->bag.allowBag = flag;
    core->bag.cursorPos = 0;
    flag = 0;
    if (BTL_MAIN_GetCompetitor(core->context) == 0) flag = 1;
    core->bag.isWildBattle = flag;
    core->bag.done = 0;
    flag = 0;
    if (isLastSlot == 0) flag = 3;
    else if (BTL_MAIN_CheckSetupStatusFlag(core->context, 0x40)) flag = 1;
    else if (BTL_MAIN_GetCompetitor(core->context) == 0) {
        if (BTL_SIDE_CountLivingOfClient(core->monTable, 1) > 1) flag = 2;
        else if (foeSemiInvulnerable) flag = 4;
    }
    core->bag.buttonMode = flag;
    BTLV_CORE_InitPartyWork(core, &core->plist, 3, 0, 0);
    pokeList = BTL_CLIENT_GetSideData(core->client);
    count = BTL_SLOT_GetCount(pokeList);
    for (i = 0; i < count; i++)
        core->plist.sickFlags[i] = BTL_POKEPARAM_HasSick(BTL_SLOT_GetPokeParam(pokeList, (u8)i), 0x13);
    for (; i < 6; i++) core->plist.sickFlags[i] = 0;
    core->subStep = 1;
}



void BTLV_CORE_SkipBagPartyPrompt(struct BtlvCore *core)
{
    core->bag.skipPartyPrompt = 1;
    core->plist.choiceLocked = 1;
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
        GF_OVERLAY_Load(ov196_id);
        core->subStep = 2;
        break;
    case 2:
        if (BTLV_SCD_IsInputSlideDone(core->auxView)) {
            BTLV_SCD_OnSlideInDone(core->auxView);
            GF_OVERLAY_Load(ov197_id);
            B_BAG_MAIN_Create(&core->bag);
            core->subStep = 3;
        }
        break;
    case 3:
        if (core->bag.done) {
            GF_OVERLAY_Unload(ov197_id);
            if (core->bag.skipPartyPrompt == 0) core->subStep = 4;
            else core->subStep = 6;
        }
        break;
    case 4:
        if (core->bag.selectedItem && core->bag.selectedItemPage != 2 && !BTL_ID_IsBagItemUseBlocked(core->bag.selectedItem, core->bag.selectedItemPage)) {
            core->plist.itemId = core->bag.selectedItem;
            GF_OVERLAY_Load(ov198_id);
            B_PLIST_MAIN_Create(&core->plist);
            core->subStep = 5;
        } else core->subStep = 6;
        break;
    case 5:
        if (core->plist.done) {
            GF_OVERLAY_Unload(ov198_id);
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
            GF_OVERLAY_Unload(ov196_id);
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



u8 BTLV_CORE_GetSelectedItemPocket(struct BtlvCore *core)
{
    if (core->bag.done != 0)
        return core->bag.selectedItemPocket;
    return 0;
}



u8 BTLV_CORE_GetInputTargetSlot(struct BtlvCore *core) { return core->plist.modeSlot; }



u8 BTLV_CORE_GetInputResultFlag(struct BtlvCore *core)
{
    return core->plist.result;
}



/* Stores the bag cursors and the last used item into the save. */
void BTLV_CORE_SaveBagCursors(struct BtlvCore *core)
{
    if (core->bag.selectedItem != 0 && core->plist.modeSlot != 6 && core->bag.isComm != 1) {
        MYITEM_SAVEDATA_SetBattlePocketCursors(core->bag.myItemSave, core->bag.pocketCursorPos, core->bag.pocketScrollPos);
        MYITEM_SAVEDATA_SetLastBattleItem(core->bag.myItemSave, core->bag.selectedItem, core->bag.selectedItemPage);
    }
}



void BTLV_CORE_StartSceneEffect(struct BtlvCore *core, u32 slotFrom, u32 slotTo, u32 sceneId, u32 argA, u32 argB, u8 flags)
{
    u32 viewPosFrom;
    u32 viewPosTo;

    viewPosFrom = BTL_MAIN_GetViewPosOfSlot(core->context, slotFrom);
    if (slotTo != 6) {
        viewPosTo = BTL_MAIN_GetViewPosOfSlot(core->context, slotTo);
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
        work->slots[i] = BTL_MAIN_GetTrainerSlotOfPoke(core->context, core->monTable, pokeIds[i]);
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



int BTLV_CORE_WaitViewEffect(void)
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



int BTLV_CORE_WaitViewEffectEx(int viewPos)
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
    mon = BTL_SIDE_GetPokeAtPos(core->monTable, slot);
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
void BTLV_CORE_BuildMessage(struct BtlvMessage *msg, struct MsgBuf *buf)
{
    switch (msg->kind) {
    case BTLV_MSG_KIND_SIDE:
        BTL_MSG_FormatWithSide(buf, msg->msgId, msg->args);
        break;
    case BTLV_MSG_KIND_TAGGED:
        BTL_MSG_DispatchTagged(buf, msg->msgId, msg->args);
        break;
    case BTLV_MSG_KIND_UI:
        BTL_MSG_GetUiString(buf, msg->msgId);
        break;
    case BTLV_MSG_KIND_UI_ARGS:
        BTL_MSG_BuildUiString(buf, msg->msgId, msg->args);
        break;
    case BTLV_MSG_KIND_TRAINER:
        BTL_MSG_BuildTrainerString(buf, msg->msgId, msg->args);
        break;
    case BTLV_MSG_KIND_ITEM_USE:
        BTL_MSG_BuildItemUse(buf, msg->args[0], msg->args[1]);
        break;
    case BTLV_MSG_KIND_PLAIN:
        BTL_MSG_BuildPlainEntry(buf, msg->args[0], msg->args[1]);
        break;
    }
}



void BTLV_CORE_CopyMessageBuffer(struct BtlvCore *core, struct MsgBuf *src)
{
    STRBUF_Copy(core->msgBuffer, src);
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



void BTLV_CORE_BuildAndPrintMessageFlag(struct BtlvCore *core, struct BtlvMessage *msg, int flag)
{
    BTLV_CORE_BuildMessage(msg, core->msgBuffer);
    BTLV_CORE_StartPrintMessage(core, core->msgBuffer, msg->param, flag);
}



void BTLV_CORE_BuildAndPrintMessageNow(struct BtlvCore *core, struct BtlvMessage *msg)
{
    BTLV_CORE_BuildMessage(msg, core->msgBuffer);
    BTLV_CORE_PrintMessageNow(core, core->msgBuffer);
}



void BTLV_CORE_PrintSideMessage(struct BtlvCore *core, u16 msgId, u32 *args)
{
    BTL_MSG_FormatWithSide(core->msgBuffer, msgId, args);
    BTLV_CORE_StartPrintMessage(core, core->msgBuffer, 0x50, 0);
}



void BTLV_CORE_PrintTaggedMessage(struct BtlvCore *core, u16 msgId, u32 *args)
{
    BTL_MSG_DispatchTagged(core->msgBuffer, msgId, args);
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
    BTL_MSG_BuildItemUse(core->msgBuffer, clientId, item);
    BTLV_CORE_StartPrintMessage(core, core->msgBuffer, 0x50, 0);
}



int BTLV_CORE_WaitMessage(struct BtlvCore *core) { return BTLV_SCU_UpdateMessage(core->sceneUnit); }



int BTLV_CORE_ConsumeMessageFlag(struct BtlvCore *core) { return BTLV_SCU_ConsumeMessageEnded(core->sceneUnit); }



void BTLV_CORE_StartPrintMessage(struct BtlvCore *core, struct MsgBuf *buf, u16 speed, u32 flag)
{
    if (BTL_CLIENT_IsMainStepActive(core->client) == 0) {
        BTLV_SCU_StartMessage(core->sceneUnit, buf, speed, flag);
    }
}



void BTLV_CORE_PrintMessageNow(struct BtlvCore *core, struct MsgBuf *buf) { BTLV_SCU_PrintMessageInstant(core->sceneUnit, buf); }



void BTLV_CORE_ShowPortrait(struct BtlvCore *core, u32 slot, u32 flag) { BTLV_SCU_StartNamePlate(core->sceneUnit, slot, flag); }



int BTLV_CORE_UpdatePortraitSlideIn(struct BtlvCore *core, u32 slot) { return BTLV_SCU_ProcNamePlateAt(core->sceneUnit, slot); }



void BTLV_CORE_StartPortraitSlideOut(struct BtlvCore *core, u32 slot) { BTLV_SCU_HideNamePlateAt(core->sceneUnit, slot); }



int BTLV_CORE_WaitPortraitSlideOut(struct BtlvCore *core, u32 slot) { return BTLV_SCU_IsNamePlateHiddenAt(core->sceneUnit, slot); }



void BTLV_CORE_ReloadPortrait(struct BtlvCore *core, u32 slot) { BTLV_SCU_RefreshNamePlateAt(core->sceneUnit, slot); }



int BTLV_CORE_UpdatePortraitMosaic(struct BtlvCore *core, u32 slot) { return BTLV_SCU_ProcNamePlateMosaicAt(core->sceneUnit, slot); }



void BTLV_CORE_StartViewEffect262(struct BtlvCore *core, int viewPos)
{
    BTLV_EFFECT_StartEffectOnPoke(viewPos, 0x262);
}



void BTLV_CORE_StartViewEffect261(struct BtlvCore *core, int viewPos)
{
    BTLV_EFFECT_StartEffectOnPoke(viewPos, 0x261);
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
    BTLV_SCU_NoOp(core->sceneUnit);
}



void BTLV_CORE_StartSlotEffect25F(struct BtlvCore *core, u32 slot) { BTLV_SCU_StartPosCueEffect(core->sceneUnit, BTL_MAIN_GetViewPosOfSlot(core->context, slot)); }



int BTLV_CORE_WaitSlotEffect25F(struct BtlvCore *core, u32 slot) { return BTLV_SCU_IsPosCueEffectDone(core->sceneUnit, BTL_MAIN_GetViewPosOfSlot(core->context, slot)); }



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
    work->monSlotA = BTL_MAIN_GetClientTrainerIndex(core->context, clientId, posA);
    work->monSlotB = BTL_MAIN_GetClientTrainerIndex(core->context, clientId, posB);
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
    BTL_SIDE_GetSlotOfClientThunk(core->monTable, core->clientIndex);
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
        work->monSlot[0] = BTL_MAIN_GetClientTrainerIndex(core->context, clientId, 0);
        work->monSlot[1] = BTL_MAIN_GetClientTrainerIndex(core->context, clientId, 1);
        work->monSlot[2] = BTL_MAIN_GetClientTrainerIndex(core->context, clientId, 2);
        work->viewPos[0] = BTL_MAIN_GetViewPosOfSlot(core->context, work->monSlot[0]);
        work->viewPos[1] = BTL_MAIN_GetViewPosOfSlot(core->context, work->monSlot[1]);
        work->viewPos[2] = BTL_MAIN_GetViewPosOfSlot(core->context, work->monSlot[2]);
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
    return BTLV_SCD_PollChoiceScreen(core->auxView, outResult);
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
        GF_OVERLAY_Load(ov196_id);
        core->subStep++;
        break;
    case 1:
        if (BTLV_SCD_IsInputSlideDone(core->auxView)) {
            BTLV_SCD_OnSlideInDone(core->auxView);
            GF_OVERLAY_Load(ov198_id);
            B_PLIST_MAIN_Create(&core->plist);
            core->subStep++;
        }
        break;
    case 2:
        if (core->plist.done) {
            GF_OVERLAY_Unload(ov198_id);
            BTLV_SCD_StartInputSlideOut(core->auxView);
            BTLV_SCD_OnSlideOutStart(core->auxView);
            core->subStep++;
        }
        break;
    case 3:
        if (BTLV_SCD_IsInputSlideDone(core->auxView)) core->subStep++;
        break;
    default:
        *outSlot = core->plist.result;
        GF_OVERLAY_Unload(ov196_id);
        core->subStep = 0;
        return 1;
    }
    return 0;
}



void BTLV_CORE_StartBallWindowOpen(struct BtlvCore *core, int pokeParam, struct BtlExpResult *result)
{
    BTLV_SCU_StartBallWindowOpen(core->sceneUnit, pokeParam, result);
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
