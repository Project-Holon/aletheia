/*
 * file:     btl_client.c
 * unit:     yes
 * function: BTL_CLIENT_Create, BTL_CLIENT_Delete, BTL_CLIENT_MarkCommandIssued, BTL_CLIENT_ReadRecorderEntry, BTL_CLIENT_AttachRemoteLink, BTL_CLIENT_SetView, BTL_CLIENT_SetRequestParam, BTL_CLIENT_GetNetChannel, BTL_CLIENT_RunTick, BTL_CLIENT_StartRemoteStep, BTL_CLIENT_StartMainStep, BTL_CLIENT_IsRemote, BTL_CLIENT_GetQueuedCommandWord, BTL_CLIENT_IsMainStepActive, BTL_CLIENT_AddPoints, BTL_CLIENT_SetStepFn, BTL_CLIENT_StepMain, BTL_CLIENT_StepRemote, BTL_CLIENT_ResetSendWord, BTL_CLIENT_FindCommandStepFn, BTL_CLIENT_GetCursor, BTL_CLIENT_IsWindowWaiting, BTL_CLIENT_IsWindowDone, BTL_CLIENT_StepOpenBattleWindow, BTL_CLIENT_PollWindowStep, BTL_CLIENT_StoreMonParam, BTL_CLIENT_HasMonParamDropped, BTL_CLIENT_GetLeadPartyMon, BTL_CLIENT_StepWindowModeSelect, BTL_CLIENT_PickWindowMode, BTL_CLIENT_ReturnTrue, BTL_CLIENT_StartWindowModeSend, BTL_CLIENT_StartTimeLimit, BTL_CLIENT_PollTimeLimitReady, BTL_CLIENT_PollTimeLimitAndSetSub, BTL_CLIENT_StopTimeLimit, BTL_CLIENT_BuildActionPromptMessage, BTL_CLIENT_SetSubFn, BTL_CLIENT_RunSubFn, BTL_CLIENT_StepStartActionSelection, BTL_CLIENT_StepPlaybackRecordedAction, BTL_CLIENT_ResetActionCursor, BTL_CLIENT_InitActionSelection, BTL_CLIENT_ShowMessage, BTL_CLIENT_StepAutoSelectActions, BTL_CLIENT_StepSelectAction, BTL_CLIENT_StepShowSupportItemMessage, BTL_CLIENT_FindSupportItem, BTL_CLIENT_StepSelectMove, BTL_CLIENT_BuildMoveUsableTable, BTL_CLIENT_StepMoveHighlight, BTL_CLIENT_StepSelectSwitchTarget, BTL_CLIENT_StepSelectItem, BTL_CLIENT_IsLoneFoeSemiInvulnerable, BTL_CLIENT_StepSelectRun, BTL_CLIENT_StepAdvanceSlot, BTL_CLIENT_StepSendActions, BTL_CLIENT_ClearSlotLinkWords, BTL_CLIENT_SetSlotLinkWord, BTL_CLIENT_FlushSlotLinkWord, BTL_CLIENT_FlushSlotLinkWords, BTL_CLIENT_ClearSlotFlags, BTL_CLIENT_SetSlotFlag, BTL_CLIENT_SumSlotFlagsBeforeCurrent, BTL_CLIENT_IsActionForced, BTL_CLIENT_SetStruggleIfNoMoves, BTL_CLIENT_SetStruggleAction, BTL_CLIENT_IsMoveSelectionBlocked, BTL_CLIENT_BuildUsableMoveMask, BTL_CLIENT_IsHeldItemEffective, BTL_CLIENT_GetEscapeBlocker, BTL_CLIENT_GetEscapeBlockerForSide, BTL_CLIENT_FindTrapper, BTL_CLIENT_CanShadowTagTrap, BTL_CLIENT_CanArenaTrapTrap, BTL_CLIENT_CanMagnetPullTrap, BTL_CLIENT_ClearSlotOrder, BTL_CLIENT_HasSlotInOrder, BTL_CLIENT_SetSlotOrder, BTL_CLIENT_ChooseAiSwitchTarget, BTL_CLIENT_PickRandomFoe, BTL_CLIENT_IsCountdownEndingNext, BTL_CLIENT_ShouldSwitchVsWonderGuard, BTL_CLIENT_ShouldSwitchNoEffectiveMove, BTL_CLIENT_ShouldSwitchWhileLocked, BTL_CLIENT_FindSwitchFromHitHistory, BTL_CLIENT_FindNaturalCureSwitch, BTL_CLIENT_FindSwitchByTypeMatchup, BTL_CLIENT_FindMemberWithAbility, BTL_CLIENT_AnyMemberHasMoveVsTarget, BTL_CLIENT_FindMemberResistingType, BTL_CLIENT_HasMoveWithAffinityVsTarget, BTL_CLIENT_PickRotationPosition, BTL_CLIENT_StepAutoChooseActions, BTL_CLIENT_ListAbleMons, BTL_CLIENT_SortMonsByMovePower, BTL_CLIENT_BuildSlotChoices, BTL_CLIENT_SetChangeActionsFromChoice, BTL_CLIENT_SetChangeActionsFirstAble, BTL_CLIENT_CollectOwnReceivedIds, BTL_CLIENT_StepAskYesNo, BTL_CLIENT_StepChoiceMode2, BTL_CLIENT_StepChoiceMode1, BTL_CLIENT_ChooseReplacementsAuto, BTL_CLIENT_StepChooseReplacement, BTL_CLIENT_IsDoubleBattleLeadAlive, BTL_CLIENT_TrySetRotateAction, BTL_CLIENT_StepAskSwitchBeforeSendOut, BTL_CLIENT_RecordReceivedPacket, BTL_CLIENT_StepShowResultIfView, BTL_CLIENT_StepShowResultMessage, BTL_CLIENT_GetOutcomeForClient, BTL_CLIENT_StepShowTrainerResultIfView, BTL_CLIENT_StepShowTrainerResult, BTL_CLIENT_StepShowEndSpeechIfView, BTL_CLIENT_StepShowEndSpeech, BTL_CLIENT_ShowEndSpeech, BTL_CLIENT_StepShowPrizeMoneyMessage, BTL_CLIENT_StepShowBlackoutMessages, BTL_CLIENT_StepShowFixedMessage, BTL_CLIENT_StepRunServerCommandsIfView, BTL_CLIENT_StepRunServerCommands, BTL_CLIENT_StepShowRecallMessage, BTL_CLIENT_PickRecallMessageId, BTL_CLIENT_StepPlayRecallAnim, BTL_CLIENT_StepSendOutMon, BTL_CLIENT_PickSendOutMessageId, BTL_CLIENT_StepShowSideMessage, BTL_CLIENT_StepShowSideMessageWithSound, BTL_CLIENT_StepShowTaggedMessage, BTL_CLIENT_StepShowTaggedMessageWithSound, BTL_CLIENT_StepShowItemUseMessage, BTL_CLIENT_GetMoveAnimTarget, BTL_CLIENT_StepPlayMoveAnim, BTL_CLIENT_StepSetMonVisibility, BTL_CLIENT_StepPlayMonTaskAnim, BTL_CLIENT_StepPlayMultiMonAnim, BTL_CLIENT_StepUpdateMonGaugeThenMessage, BTL_CLIENT_StepStartEffectForMon, BTL_CLIENT_StepPlaySubstituteAnim, BTL_CLIENT_StepFaintMon, BTL_CLIENT_StepReviveMon, BTL_CLIENT_StepPlayMonEffect262, BTL_CLIENT_StepPlayMonEffect261, BTL_CLIENT_StepStartWeather, BTL_CLIENT_StepEndWeather, BTL_CLIENT_StepUpdateMonGauge, BTL_CLIENT_StepPlayMonAnim, BTL_CLIENT_StepUpdateMonGaugeCopy, BTL_CLIENT_StepRotatePositions, BTL_CLIENT_StepRotatePositionsTwice, BTL_CLIENT_StepPlayEffectOnMon, BTL_CLIENT_StepPlayEffectOnMonFast, BTL_CLIENT_StepTransformMon, BTL_CLIENT_StepPlayHitEffect, BTL_CLIENT_StepChangeBgm, BTL_CLIENT_StepPlayViewSequence, BTL_CLIENT_StepAddEffortValues, BTL_CLIENT_StepGiveExp, BTL_CLIENT_ForgetMoveSoundCallback, BTL_CLIENT_StepLearnLevelUpMoves, BTL_CLIENT_StepThrowBall, BTL_CLIENT_StepShowBallBlocked, BTL_CLIENT_StepClearSidePosition, BTL_CLIENT_StepSetAbilityWithPopup, BTL_CLIENT_StepSwapAbilitiesWithPopup, BTL_CLIENT_StepClearIllusion, BTL_CLIENT_StepPlayEffectById, BTL_CLIENT_StepPlayMonSimpleEffect
 * address:  0x021CD6F0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from btl_server.c (lane L189): __FILE__ anchor 021CD8CC (d_021F3A88 "btl_client.c") used by the 0x1b8-byte BtlClient constructor 021CD6F0, which is the first function of the file.
 *
 * symbols:
 *   data_021EFCF0  0x021EFCF0  data  ov093
 *   BTL_MAIN_DecodeMessageCode  0x021B8778  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_MAIN_GetClientTrainerIndex  0x021B8BEC  thumb  ov093
 *   d_021EFCF4  0x021EFCF4  data  ov093  a1
 *   d_021EFCFA  0x021EFCFA  data  ov093  a1
 *   BTL_MAIN_IsMultiMode 0x021B86C8 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_MAIN_IsClientUsed  0x021B8B9C  thumb  ov093
 *   func_02007F1C 0x02007F1C thumb
 *   func_02007E50 0x02007E50 thumb
 *   GPOWER_ApplyPrizeMoney  0x0201119C  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   func_0200C274  0x0200C274  thumb
 *   BTL_CALC_CalcDefeatMoneyLoss  0x021D7FF8  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   BTL_MAIN_GetFieldSituation  0x021B8714  thumb  ov093
 *   NATSUKI_Calc  0x0201B7A0  thumb
 *   func_021D54F4 0x021D54F4 thumb ov093
 *   BTL_POKEPARAM_IsIllusionActive  0x021D6C24  thumb  ov093
 *   BTL_POKEPARAM_GetDisplayMon  0x021D5864  thumb  ov093
 *   BTL_POKEPARAM_Delete 0x021D53B8 thumb ov093
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   BTL_POKEPARAM_Create 0x021D4D84 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_SetFakeMon 0x021D5848 thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   func_02017E1C 0x02017E1C thumb
 *   POKE_TOOL_Create 0x020173F0 thumb
 *   POKEPARTY_Init 0x0201A948 thumb
 *   BTL_POKEPARAM_WriteBackToParam 0x021D6B84 thumb ov093
 *   POKEPARTY_Add 0x0201A98C thumb
 *   POKEPARTY_Copy 0x0201AC2C thumb
 *   BTL_POKEPARAM_SetPokeParam 0x021D6C3C thumb ov093
 *   BTL_POKEPARAM_IsLevelUpPending  0x021D67D0  thumb  ov093
 *   func_02007B50 0x02007B50 thumb
 *   func_02007C70 0x02007C70 thumb
 *   BTL_MAIN_GetPositionsPerClient  0x021B6994  thumb  ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   data_021EFD70  0x021EFD70  data  ov093
 *   BTL_MAIN_GetEnemyLanePos 0x021B8C20 thumb ov093
 *   BTL_POKEPARAM_IsAbleToBattle 0x021D5B7C thumb ov093
 *   BTL_MAIN_CountClientTrainers  0x021B8B78  thumb  ov093
 *   BTL_POKEPARAM_ClearFakeMon  0x021D5854  thumb  ov093
 *   func_020307B0  0x020307B0  arm
 *   MYSTATUS_Create  0x0200846C  thumb
 *   MYSTATUS_Copy  0x02008494  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008510  0x02008510  thumb
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 *   STRBUF_Clone  0x02045874  arm
 *   func_02082D44  0x02082D44  arm
 *   PMSI_PARAM_Copy  0x02024570  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetChars  0x02045A00  arm
 *   COMM_PLAYER_SUPPORT_GetCurrent  0x0202E7DC  thumb
 *   POKEPARTY_Create 0x0201A920 thumb
 *   BTL_SETUP_CheckStatusFlag  0x02013158  thumb
 *   sub_02008DF0 0x02008DF0 thumb
 *   sub_02008DAC 0x02008DAC thumb
 *   BTL_MAIN_IsCommCompetitor 0x021B6818 thumb ov093
 *   NATSUKI_CalcUseItem  0x0201B7B4  thumb
 *   NATSUKI_CalcParty 0x0201B818 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   BTL_CALC_IsBossTrainer 0x021D7F60 thumb ov093
 *   func_021D805C 0x021D805C thumb ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex 0x021D62A8 thumb ov093
 *   _u32_div_f 0x0209C2B0 arm
 *   BTL_CLIENT_SET_GetCount  0x021D826C  thumb  ov093
 *   BTL_CLIENT_SET_JudgeResult  0x021D8270  thumb  ov093
 *   BTL_CALC_SetRngState  0x021D787C  thumb  ov093
 *   BTL_MAIN_InitClientParties  0x021B68D8  thumb  ov093
 *   func_021E9034  0x021E9034  thumb  ov093
 *   BTLV_CORE_ResetDisplay  0x021E8E28  thumb  ov093
 *   BTLV_CORE_Create  0x021E8F20  thumb  ov093
 *   BTL_POKEPARAM_GetUsedMoveTotal 0x021D54B4 thumb ov093
 *   func_02030734 0x02030734 arm
 *   d_021F3A60 0x021F3A60 data a4
 *   BTL_ADAPTER_Create  0x021EEA58  thumb  ov093
 *   STRBUF_Delete  0x02045808  arm
 *   BTL_ADAPTER_Delete  0x021EEAE0  thumb  ov093
 *   BTL_MAIN_GetCommPos 0x021B86C0 thumb ov093
 *   BTL_ADAPTER_GetSendBuffer  0x021EEB64  thumb  ov093
 *   BTL_MAIN_CheckShiftModePrompt  0x021B85A8  thumb  ov093
 *   BTL_CALC_ActionGetKind  0x021D8454  thumb  ov093
 *   BTL_REC_MakeResetPacket  0x021EE9A4  thumb  ov093
 *   BTL_MAIN_GetWinBgm  0x021B86DC  thumb  ov093
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   BTL_REC_LoadPacket  0x021EE9B4  thumb  ov093
 *   BTL_REC_NextRecord  0x021EE9E4  thumb  ov093
 *   func_0203EFC8  0x0203EFC8  arm
 *   BTL_REC_InitPacket 0x021EE8B4 thumb ov093
 *   BTL_REC_MakeSkipPacket 0x021EE8D8 thumb ov093
 *   BTL_REC_AddRecord  0x021EE8F4  thumb  ov093
 *   BTL_REC_FinishPacket  0x021EE96C  thumb  ov093
 *   BTL_ADAPTER_NotifyNet  0x021EEAE8  thumb  ov093
 *   BTL_ADAPTER_SetSendData  0x021EEB00  thumb  ov093
 *   BTL_ADAPTER_Idle  0x021EEAFC  thumb  ov093
 *   BTL_ADAPTER_Cancel 0x021EEB70 thumb ov093
 *   BTL_ADAPTER_Update 0x021EEB2C thumb ov093
 *   BTL_ADAPTER_ResetCommand 0x021EEAD0 thumb ov093
 *   GAME_BEACON_SetPokeLevelUp 0x02027268 thumb
 *   GAME_BEACON_SetPokeCapture 0x020271DC thumb
 *   SHINKA_CHECK_OpenHandle 0x0201B70C thumb
 *   gFlowSourceFileName 0x021F3A70 data a4
 *   BTL_EVENT_InitFactorList 0x021D6EAC thumb ov093
 *   BTL_FIELD_ResetStatic 0x021EF874 thumb ov093
 *   func_0689CFF0 0x0689CFF0 thumb ov095
 *   func_0689D118 0x0689D118 thumb ov095
 *   func_0689D1FC 0x0689D1FC thumb ov095
 *   MI_CpuFill8 0x02082BCC arm
 *   BTL_CLIENT_SET_Clear 0x021D8230 thumb ov093
 *   func_06898BFC 0x06898BFC thumb ov095
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BTL_MAIN_RegisterZukanSeen 0x021B8750 thumb ov093
 *   func_0689D134 0x0689D134 thumb ov095
 *   BTL_EVENT_ClearSuspendedFlags  0x021D6EE8  thumb  ov093
 *   BTL_EVENT_ResetVarStackIfUsed  0x021D74E4  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   func_0689D174 0x0689D174 thumb ov095
 *   BTL_MAIN_GetClientSide  0x021B8BC4  thumb  ov093
 *   func_0689D558 0x0689D558 thumb ov095
 *   BTL_FIELD_GetStaticSlotObject  0x021EF948  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   HAND_TOKUSEI_EnableAbilityHandlers  0x021D8548  thumb  ov093
 *   HAND_ITEM_EnablePokeFactors  0x021DCFB4  thumb  ov093
 *   func_0689D338 0x0689D338 thumb ov095
 *   HAND_WAZA_AddMoveHandler  0x021E02DC  thumb  ov093
 *   HAND_WAZA_RemoveMoveHandlerUnlessKept  0x021E0394  thumb  ov093
 *   BTL_ACTION_IsChangeDepleted  0x021D83E0  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 *   BTL_EVENT_SetVarRanged  0x021D7674  thumb  ov093
 *   BTL_CALC_MulRatio  0x021D7B10  thumb  ov093
 *   BTL_ACTION_GetFightMove  0x021D8340  thumb  ov093
 *   func_0689D588 0x0689D588 thumb ov095
 *   BTL_MAIN_GetCompetitorKind 0x021B86E4 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   BTL_POKEPARAM_SetTurnFlag 0x021D5FC0 thumb ov093
 *   POKE_TOOL_IsOwnedByPlayer 0x02018480 thumb
 *   func_021B871C 0x021B871C thumb ov093
 *   BTL_MAIN_GetBadgeCount 0x021B85A0 thumb ov093
 *   POKE_TOOL_IsBoxOwnedByPlayer 0x02018488 thumb
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   func_0689D5C8 0x0689D5C8 thumb ov095
 *   func_021D82FC  0x021D82FC  thumb  ov093
 *   func_0689CD40 0x0689CD40 thumb ov095
 *   func_0689CD38 0x0689CD38 thumb ov095
 *   func_0689CC70 0x0689CC70 thumb ov095
 *   func_0689D4F0 0x0689D4F0 thumb ov095
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   BTL_CLIENT_SET_Add 0x021D8244 thumb ov093
 *   func_0689C68C 0x0689C68C thumb ov095
 *   HAND_TOKUSEI_AddAbilityHandlers 0x021D8484 thumb ov093
 *   HAND_ITEM_AddHeldItemFactor 0x021DCF5C thumb ov093
 *   BTL_POKEPARAM_StartTurnThreshold 0x021D63EC thumb ov093
 *   BTL_POKEPARAM_ReloadAndResetEffects 0x021D6580 thumb ov093
 *   func_0689D320 0x0689D320 thumb ov095
 *   func_0689CB3C 0x0689CB3C thumb ov095
 *   func_0689CB48 0x0689CB48 thumb ov095
 *   func_0689CF24 0x0689CF24 thumb ov095
 *   func_0689CC84 0x0689CC84 thumb ov095
 *   func_0689CC8C 0x0689CC8C thumb ov095
 *   BTL_EVENT_DispatchEventToType 0x021D70FC thumb ov093
 *   BTL_POKEPARAM_ResetEffectsOnSwitchOut  0x021D64F0  thumb  ov093
 *   func_0689D2F8 0x0689D2F8 thumb ov095
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb  ov093
 *   BTLV_CORE_GetSlotValue  0x021E8B80  thumb  ov093
 *   BTL_POKEPARAM_GetMovePPById  0x021D55A0  thumb  ov093
 *   BTL_POKEPARAM_GetSemiInvulnerableFlag 0x021D5C08 thumb ov093
 *   BTL_CALC_DecideMoveTarget 0x021D80BC thumb ov093
 *   BTL_ACTION_SetFight 0x021D82D0 thumb ov093
 *   BTL_POKEPARAM_FindMoveSlot 0x021D5778 thumb ov093
 *   func_0689CEE4 0x0689CEE4 thumb ov095
 *   func_0689CD78 0x0689CD78 thumb ov095
 *   func_0689CD48 0x0689CD48 thumb ov095
 *   func_0689D01C 0x0689D01C thumb ov095
 *   BTL_POKEPARAM_RecordMoveUse 0x021D6744 thumb ov093
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_EVENT_SuspendPokeFactors 0x021D7394 thumb ov093
 *   HAND_WAZA_RemoveMoveHandlerOfPoke 0x021E03D8 thumb ov093
 *   BTL_EVENT_ResumePokeFactors 0x021D73D4 thumb ov093
 *   gPledgeMoveIds 0x021EFDB8 data a2
 *   BTL_EVENT_HasClientReservedChoice 0x021D6E74 thumb ov093
 *   BTL_EVENT_SetClientReservedChoice 0x021D6E40 thumb ov093
 *   WAZA_TOOL_GetCategory 0x0201C1BC thumb
 *   func_0689CD50 0x0689CD50 thumb ov095
 *   func_0689D050 0x0689D050 thumb ov095
 *   func_0689CC14 0x0689CC14 thumb ov095
 *   BTL_POKEPARAM_HasSubstitute  0x021D6D7C  thumb  ov093
 *   func_0689D59C 0x0689D59C thumb ov095
 *   BTL_POKEPARAM_GetSickParam  0x021D62D8  thumb  ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   BTL_CALC_ApplyAccuracyStage 0x021D7908 thumb ov093
 *   BTLV_CORE_MakeSlotKind2 0x021E896C thumb ov093
 *   BTL_POKEPARAM_IsSemiInvulnerable 0x021D5C30 thumb ov093
 *   BTLV_CORE_MakeSlotKind3  0x021E899C  thumb  ov093
 *   WAZA_TOOL_IsDamaging 0x0201C314 thumb
 *   BTL_POKEPARAM_GetMovePPChecked 0x021D5584 thumb ov093
 *   BTL_POKEPARAM_GetLastSelectedMoveId 0x021D67B8 thumb ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId 0x021D67A8 thumb ov093
 *   func_021EF91C 0x021EF91C thumb ov093
 *   BTL_CALC_RollPercent 0x021D7AF0 thumb ov093
 *   BTL_POKEPARAM_TickSlot6Turn  0x021D61A8  thumb  ov093
 *   BTL_POKEPARAM_TickSleepTurn  0x021D6130  thumb  ov093
 *   BTL_CALC_MakeDefaultSickCont 0x021D7D18 thumb ov093
 *   func_021D69A0  0x021D69A0  thumb  ov093
 *   BTL_POKEPARAM_DecrementMovePP  0x021D5608  thumb  ov093
 *   BTL_POKEPARAM_MarkMoveUsed  0x021D56CC  thumb  ov093
 *   func_0689CDCC 0x0689CDCC thumb ov095
 *   func_0689CE58 0x0689CE58 thumb ov095
 *   BTL_MAIN_CheckSceneOff 0x021B8590 thumb ov093
 *   func_0689CBB8 0x0689CBB8 thumb ov095
 *   d_021F3B2C  0x021F3B2C  data  ov093  a4
 *   d_021F3B20  0x021F3B20  data  ov093  a4
 *   d_021F3B38  0x021F3B38  data  a4
 *   d_021F3B26  0x021F3B26  data  ov093  a4
 *   d_021F3B23  0x021F3B23  data  ov093  a4
 *   d_021F3B20b 0x021F3B20  data  ov093  a4
 *   BTL_POKEPARAM_AddHitRecord  0x021D6848  thumb  ov093
 *   WAZA_TOOL_GetCategory   0x0201C1BC  thumb
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   func_0689CCF8 0x0689CCF8 thumb ov095
 *   func_0689CCB4 0x0689CCB4 thumb ov095
 *   WAZA_TOOL_GetParam   0x0201BD28  thumb
 *   BTL_CALC_MulPercent  0x021D7B3C  thumb  ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   BTL_CALC_CalcBaseDamage 0x021D7A44 thumb ov093
 *   BTL_CALC_GetWeatherMoveRatio 0x021D7C38 thumb ov093
 *   BTL_CALC_ApplyTypeAffinity 0x021D7A6C thumb ov093
 *   BTL_POKEPARAM_SetItem  0x021D5B44  thumb  ov093
 *   HAND_ITEM_RemoveUnforcedFactors  0x021DCF24  thumb  ov093
 *   BTL_POKEPARAM_ConsumeHeldItem  0x021D6730  thumb  ov093
 *   WAZA_TOOL_GetSickCont 0x0201BF58 thumb
 *   BTL_CALC_MakeSickContFromSpec 0x021D7C70 thumb ov093
 *   BTL_POKEPARAM_GetTypePair 0x021D57FC thumb ov093
 *   BTLV_CORE_HasByte 0x021E8D24 thumb ov093
 *   func_0689C364 0x0689C364 thumb ov095
 *   HAND_TOKUSEI_RemoveAbilityHandlers 0x021D8510 thumb ov093
 *   BTL_POKEPARAM_ChangeForm 0x021D66D8 thumb ov093
 *   BTL_CALC_HasDefaultSickCont 0x021D7D6C thumb ov093
 *   BTL_FIELD_GetCountdownValue  0x021EF884  thumb  ov093
 *   func_021D70E4 0x021D70E4 thumb ov093
 *   WAZA_TOOL_GetRankEffectCount 0x0201C020 thumb
 *   WAZA_TOOL_GetRankEffect  0x0201C0BC  thumb
 *   func_021D5D14 0x021D5D14 thumb ov093
 *   BTL_POKEPARAM_IsHpFull  0x021D5B48  thumb  ov093
 *   BTL_CALC_SummarizeTypeAffinity 0x021D7AD4 thumb ov093
 *   BTL_POKEPARAM_ZeroHp  0x021D5FB8  thumb  ov093
 *   BTL_POKEPARAM_GetSubstituteHp  0x021D6D90  thumb  ov093
 *   func_0689C7A4 0x0689C7A4 thumb ov095
 *   WAZA_TOOL_GetWeather  0x0201C184  thumb
 *   BTL_FIELD_GetCountdownCount 0x021EF894 thumb ov093
 *   func_021EF8A4 0x021EF8A4 thumb ov093
 *   BTL_FIELD_RegisterStaticSlot  0x021EF8C8  thumb  ov093
 *   BTLV_CORE_GetSlotPosition  0x021E8A98  thumb  ov093
 *   BTL_FIELD_SetStaticSlotValue  0x021EF8F8  thumb  ov093
 *   func_0689C954 0x0689C954 thumb ov095
 *   BTL_POKEPARAM_SetAbility 0x021D66D0 thumb ov093
 *   HAND_TOKUSEI_SwapAbilityHandlers 0x021D8564 thumb ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_POKEPARAM_SetSubstituteHp  0x021D6D5C  thumb  ov093
 *   BTL_POKEPARAM_DamageSubstitute  0x021D6D9C  thumb  ov093
 *   BTL_POKEPARAM_ClearSubstitute  0x021D6D70  thumb  ov093
 *   BTL_POKEPARAM_AdvanceTurn 0x021D6408 thumb ov093
 *   BTL_EVENT_ClearClientReservedChoice 0x021D6E88 thumb ov093
 *   BTL_EVENT_RemoveDeadFactors 0x021D701C thumb ov093
 *   BTL_MAIN_GetPmsWork 0x021B8630 thumb ov093
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   COMM_PLAYER_SUPPORT_GetMode 0x0202E7E0 thumb
 *   COMM_PLAYER_SUPPORT_SavePreviousAndSuspend 0x0202E7E4 thumb
 *   func_0689C9F8 0x0689C9F8 thumb ov095
 *   func_0689B7A8 0x0689B7A8 thumb ov095
 *   BTL_POKEPARAM_TickSickCont 0x021D6064 thumb ov093
 *   BTL_CALC_PackPokeIds 0x021D806C thumb ov093
 *   func_0689B8CC 0x0689B8CC thumb ov095
 *   func_06898D54 0x06898D54 thumb ov095
 *   BTL_FIELD_QueryStaticSlotC 0x021EF934 thumb ov093
 *   func_021C4C40 0x021C4C40 thumb ov093
 *   BTL_FIELD_TickCountdown 0x021EF8B8 thumb ov093
 *   BTL_CALC_GetWeatherDamage 0x021D7BD4 thumb ov093
 *   func_0689D15C 0x0689D15C thumb ov095
 *   BTL_POKEPARAM_ResetAllEffects 0x021D646C thumb ov093
 *   BTL_MAIN_GetRuleSlotSpan  0x021B8640  thumb  ov093
 *   func_0689D5FC 0x0689D5FC thumb ov095
 *   HAND_TOKUSEI_DisableAbilityHandlers 0x021D8538 thumb ov093
 *   HAND_ITEM_DisablePokeFactors 0x021DCFA4 thumb ov093
 *   HAND_WAZA_RemoveAllMoveHandlers 0x021E0434 thumb ov093
 *   BTL_POKEPARAM_CureSickBySource 0x021D6264 thumb ov093
 *   BTL_FIELD_QueryStaticSlotB 0x021EF90C thumb ov093
 *   BTL_MAIN_CheckEventOverlayAllowed 0x021B85EC thumb ov093
 *   func_0689D1A0 0x0689D1A0 thumb ov095
 *   func_0689D184 0x0689D184 thumb ov095
 *   func_0689D1BC 0x0689D1BC thumb ov095
 *   BTL_POKEPARAM_AddExp 0x021D69B8 thumb ov093
 *   BTL_POKEPARAM_ClearMajorStatus  0x021D61F0  thumb  ov093
 *   BTL_POKEPARAM_CureSick  0x021D6238  thumb  ov093
 *   BTL_CALC_FindMajorSick  0x021D7E10  thumb  ov093
 *   BTL_POKEPARAM_RaiseStatStage 0x021D5DC0 thumb ov093
 *   BTL_POKEPARAM_LowerStatStage 0x021D5E38 thumb ov093
 *   BTL_POKEPARAM_AddHp  0x021D5FA4  thumb  ov093
 *   BTL_POKEPARAM_SetSickCont  0x021D6034  thumb  ov093
 *   BTLV_CORE_IsSlotKind1Index15  0x021E8A78  thumb  ov093
 *   BTL_POKEPARAM_SubHp 0x021D5F90 thumb ov093
 *   BTL_POKEPARAM_RestoreRealMovePP  0x021D56A0  thumb  ov093
 *   BTL_POKEPARAM_RestoreMovePP  0x021D5674  thumb  ov093
 *   BTL_POKEPARAM_SetContFlag 0x021D5FE4 thumb ov093
 *   BTL_POKEPARAM_ClearContFlag 0x021D6008 thumb ov093
 *   WAZA_TOOL_GetType   0x0201C1C8  thumb
 *   WAZA_TOOL_GetDamageType   0x0201C1E8  thumb
 *   WAZA_TOOL_IsAlwaysHit  0x0201C1F4  thumb
 *   WAZA_TOOL_IsAlwaysCritical  0x0201C284  thumb
 *   BTL_POKEPARAM_GetCritStage  0x021D5F14  thumb  ov093
 *   BTL_CALC_RollCriticalHit  0x021D7930  thumb  ov093
 *   BTLV_CORE_GetHighByte 0x021E8CFC thumb ov093
 *   BTLV_CORE_GetLowByte 0x021E8D04 thumb ov093
 *   BTLV_CORE_BytesEqual 0x021E8DA8 thumb ov093
 *   BTL_CALC_CombineTypeAffinity 0x021D79E8 thumb ov093
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   func_0689C6E4 0x0689C6E4 thumb ov095
 *   func_0689C540 0x0689C540 thumb ov095
 *   BTL_CALC_GetTypeAffinity  0x021D794C  thumb  ov093
 *   BTL_CALC_RollHitCount  0x021D7BA4  thumb  ov093
 *   WAZA_TOOL_GetPower  0x0201C1D8  thumb
 *   BTL_POKEPARAM_GetStatForCrit 0x021D5AD8 thumb ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_CALC_MulRatioMin1  0x021D7B2C  thumb  ov093
 *   BTL_MAIN_CheckFrontPos 0x021B86A0 thumb ov093
 *   func_0689D5F4 0x0689D5F4 thumb ov095
 *   BTL_MAIN_GetActivePosPerSide  0x021B8670  thumb  ov093
 *   SHINKA_CHECK_GetRowParam 0x0201B718 thumb
 *   func_06898CF4  0x06898CF4  thumb  ov095
 *   func_06898CE0 0x06898CE0 thumb ov095
 *   func_068982AC  0x068982AC  thumb
 *   BTL_POKEPARAM_GetWeight 0x021D67E8 thumb ov093
 *   BTL_POKEPARAM_IsMovePPFull  0x021D55D8  thumb  ov093
 *   func_0689C464 0x0689C464 thumb ov095
 *   BTL_POKEPARAM_SetStatStage  0x021D5EA8  thumb  ov093
 *   BTL_POKEPARAM_RaiseLoweredStatStages 0x021D5EFC thumb ov093
 *   BTL_POKEPARAM_ResetStatStages  0x021D5F08  thumb  ov093
 *   BTL_POKEPARAM_SetStat 0x021D5970 thumb ov093
 *   func_0689C9C0 0x0689C9C0 thumb ov095
 *   BTL_POKEPARAM_SetTypes  0x021D66B0  thumb  ov093
 *   BTL_POKEPARAM_ClearTurnFlag 0x021D6440 thumb ov093
 *   func_06898C10 0x06898C10 thumb ov095
 *   func_06898D10 0x06898D10 thumb ov095
 *   BTL_FIELD_QueryStaticSlotA 0x021EF8E8 thumb ov093
 *   func_068981F0 0x068981F0 thumb ov095
 *   func_0689C974 0x0689C974 thumb ov095
 *   BTL_POKEPARAM_ClearConsumedItem 0x021D6738 thumb ov093
 *   HAND_ITEM_AddForcedFactor  0x021DCF78  thumb  ov093
 *   HAND_ITEM_RemoveFactor  0x021DCF9C  thumb  ov093
 *   BTL_POKEPARAM_ReplaceMove  0x021D5734  thumb  ov093
 *   BTL_POKEPARAM_PassEffects  0x021D65C8  thumb  ov093
 *   BTL_POKEPARAM_SetWeight 0x021D67D8 thumb ov093
 *   BTL_POKEPARAM_Transform 0x021D6C50 thumb ov093
 *   BTL_POKEPARAM_ClearIllusion  0x021D6C2C  thumb  ov093
 *   BTL_POKEPARAM_IsTransformed  0x021D6D54  thumb  ov093
 *   BTL_MAIN_GetOwnLanePos 0x021B8C38 thumb ov093
 *   BTL_CALC_GetFightersPerSide 0x021D7F00 thumb ov093
 *   BTL_MAIN_GetEnemyLanePosFromWork 0x021B8C50 thumb ov093
 *   BTL_CALC_CalcDefeatExp 0x021D7EB4 thumb ov093
 *   BTL_EVENT_GetClientPartyCount 0x021D6E04 thumb ov093
 *   BTL_EVENT_GetClientPartySlotId 0x021D6E0C thumb ov093
 *   func_02008564 0x02008564 thumb arm9
 *   GPOWER_ApplyExpRate 0x02011168 thumb arm9
 *   _ffltu         0x0209BE04  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0207C7B4  0x0207C7B4  arm
 *   BTL_POKEPARAM_GetMaxLevelExp  0x021D6B6C  thumb  ov093
 *   gEffortValueStatTable      0x021EFDC0  data  ov093
 *   func_02019C90   0x02019C90  thumb arm9
 *   POKE_TOOL_DecodePartyParam   0x02017D30  thumb arm9
 *   POKE_TOOL_EncodePartyParam   0x02017D70  thumb arm9
 *   gBagItemEffectTable 0x021EFDE4 data a4
 *   BTL_MAIN_CheckZukanSeen 0x021B8724 thumb ov093
 *   BTL_EVENT_StartClientPalAnm 0x021D6E24 thumb ov093
 *   GPOWER_ApplyCaptureRate 0x020111BC thumb
 *   FX_Div 0x0207C768 arm
 *   FX_Sqrt 0x0207C7B4 arm
 *   _ll_mul 0x0209C054 arm
 *   BTL_MAIN_GetZukanSeenCount  0x021B873C  thumb  ov093
 *   TIMEZONE_GetTimeZoneOfHour 0x020113F0 thumb
 *   func_0689C9A0 0x0689C9A0 thumb ov095
 *   _fflt 0x0209BDBC arm
 *   _s32_div_f 0x0209C0A4 arm
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   BTL_POKEPARAM_AddCritStage  0x021D5F38  thumb  ov093
 *   func_021D5450  0x021D5450  thumb  ov093
 *   BTL_POKEPARAM_GetRealMovePPLost  0x021D5568  thumb  ov093
 *   BTL_POKEPARAM_GetRealMoveId  0x021D54D0  thumb  ov093
 *   func_0689C9E4 0x0689C9E4 thumb ov095
 *   func_0689C8FC 0x0689C8FC thumb ov095
 *   BTLV_CORE_CheckPartySlotPair  0x021E869C  thumb  ov093
 *   func_0689D1D4 0x0689D1D4 thumb ov095
 *   gHandExRecordSizeTable     0x021EFE9C  data  a4
 *   data_021F3A84 0x021F3A84 data
 *   func_02034714 0x02034714 arm
 *   data_021EFF14  0x021EFF14  data  ov093
 *   data_021F3B44  0x021F3B44  data  ov093
 *   d_021F3A88 0x021F3A88 data a4
 *   func_021D3F04 0x021D3F04 thumb ov093
 *   func_021D3D9C 0x021D3D9C thumb ov093
 *   func_02187F00 0x02187F00 thumb ov096
 *   BTL_REC_CreateBuffer 0x021EE5E4 thumb ov093
 *   BTL_REC_DeleteBuffer 0x021EE600 thumb ov093
 *   func_02188080 0x02188080 thumb ov096
 *   BTL_REC_ReadEntry 0x021EE63C thumb ov093
 *   BTL_REC_CountFlaggedRecords 0x021EE830 thumb ov093
 *   func_021D3F48 0x021D3F48 thumb ov093
 *   BTL_REC_ResetReader 0x021EE674 thumb ov093
 *   BTL_ADAPTER_ClearRecvHeader 0x021EEBDC thumb ov093
 *   func_021D3F64 0x021D3F64 thumb ov093
 *   func_021D3F88 0x021D3F88 thumb ov093
 *   func_021D3FDC 0x021D3FDC thumb ov093
 *   BTL_ADAPTER_GetRecvCommand 0x021EEBE8 thumb ov093
 *   BTL_ADAPTER_GetRecvData 0x021EEC20 thumb ov093
 *   func_021D3FAC 0x021D3FAC thumb ov093
 *   func_021D3FC4 0x021D3FC4 thumb ov093
 *   func_021D3F4C 0x021D3F4C thumb ov093
 *   BTL_ADAPTER_SetRecvTarget 0x021EEC4C thumb ov093
 *   func_021D3F60 0x021D3F60 thumb ov093
 *   GFL_USE_SetPlayersAudible 0x02005CA4 thumb
 *   PM_VOICE_ResetMasterVolume 0x02006740 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   func_021D3FA8 0x021D3FA8 thumb ov093
 *   PM_VOICE_SetMasterVolume 0x02006734 thumb
 *   func_021D3F98 0x021D3F98 thumb ov093
 *   func_021EAE24 0x021EAE24 thumb ov093
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   func_021F88BC 0x021F88BC thumb ov094
 *   func_021F8678 0x021F8678 thumb ov094
 *   func_021EAE34 0x021EAE34 thumb ov093
 *   func_021EAE74 0x021EAE74 thumb ov093
 *   gBtlClientCommandTable 0x021EFFEC data a4
 *   func_021F8524 0x021F8524 thumb ov094
 *   func_021E90A0  0x021E90A0  thumb  ov093
 *   func_021E90D0  0x021E90D0  thumb  ov093
 *   func_021F84E8  0x021F84E8  thumb  ov094
 *   func_021F8504  0x021F8504  thumb  ov094
 *   func_021EAEA8  0x021EAEA8  thumb  ov093
 *   BTL_REC_ReadSkipFlag  0x021EE688  thumb  ov093
 *   func_021D3F54  0x021D3F54  thumb  ov093
 *   func_021EAA00  0x021EAA00  thumb  ov093
 *   func_021EAA5C  0x021EAA5C  thumb  ov093
 *   func_021EAA34  0x021EAA34  thumb  ov093
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021EAF50  0x021EAF50  thumb  ov093
 *   func_021EAF78  0x021EAF78  thumb  ov093
 *   BTL_REC_ReadRecord 0x021EE6B8 thumb ov093
 *   func_021D3FD0 0x021D3FD0 thumb ov093
 *   func_021EA614 0x021EA614 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   BTL_CALC_ActionSetNone 0x021D8434 thumb ov093
 *   func_021EAE44 0x021EAE44 thumb ov093
 *   func_021EAE54 0x021EAE54 thumb ov093
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   BTL_CALC_PeekMoveTarget 0x021D81F8 thumb ov093
 *   func_021EA65C 0x021EA65C thumb ov093
 *   func_021E9760 0x021E9760 thumb ov093
 *   func_021E979C 0x021E979C thumb ov093
 *   func_021E97A4 0x021E97A4 thumb ov093
 *   func_021E9964 0x021E9964 thumb ov093
 *   func_0689CB08 0x0689CB08 thumb ov095
 *   func_021E9974 0x021E9974 thumb ov093
 *   func_021E9954 0x021E9954 thumb ov093
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021EA6B0 0x021EA6B0 thumb ov093
 *   BTL_CALC_IsGymLeaderTrainer 0x021D7F38 thumb ov093
 *   func_021F87EC 0x021F87EC thumb ov094
 *   func_021F8774 0x021F8774 thumb ov094
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_0202A298 0x0202A298 thumb
 *   BTL_CALC_DivideMaxHp 0x021D7B60 thumb ov093
 *   gBtlClientSupportItemKeys 0x021EFF78 data ov093 a2
 *   func_021E97BC 0x021E97BC thumb ov093
 *   func_021E9808 0x021E9808 thumb ov093
 *   func_021E98AC 0x021E98AC thumb ov093
 *   func_021E98B4 0x021E98B4 thumb ov093
 *   func_021D832C 0x021D832C thumb ov093
 *   BTL_ACTION_SetRotate 0x021D83FC thumb ov093
 *   BTL_CALC_IsMultiFighterRule 0x021D7EF0 thumb ov093
 *   func_021E98BC 0x021E98BC thumb ov093
 *   func_021E9920 0x021E9920 thumb ov093
 *   func_021E98E8 0x021E98E8 thumb ov093
 *   func_021E9858 0x021E9858 thumb ov093
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb  ov093
 *   func_021E9CE0  0x021E9CE0  thumb  ov093
 *   func_021E9B14  0x021E9B14  thumb  ov093
 *   func_021E9B20  0x021E9B20  thumb  ov093
 *   func_021E9A78 0x021E9A78 thumb ov093
 *   func_0689CB14 0x0689CB14 thumb ov095
 *   func_0689CB1C 0x0689CB1C thumb ov095
 *   BTL_ACTION_SetChange 0x021D8394 thumb ov093
 *   func_021E9D04 0x021E9D04 thumb ov093
 *   func_021E9E70 0x021E9E70 thumb ov093
 *   func_021E9E80 0x021E9E80 thumb ov093
 *   func_021EA01C 0x021EA01C thumb ov093
 *   func_021EA044 0x021EA044 thumb ov093
 *   func_021EA030 0x021EA030 thumb ov093
 *   func_021EA04C 0x021EA04C thumb ov093
 *   BTL_ACTION_SetItem 0x021D8358 thumb ov093
 *   func_021EA058 0x021EA058 thumb ov093
 *   func_021EA720 0x021EA720 thumb ov093
 *   func_021EABC4 0x021EABC4 thumb ov093
 *   func_021EAC54 0x021EAC54 thumb ov093
 *   func_021D8414 0x021D8414 thumb ov093
 *   func_021EA7FC  0x021EA7FC  thumb  ov093
 *   func_021EA814  0x021EA814  thumb  ov093
 *   BTL_CALC_ActionSetForcedSkip  0x021D8444  thumb  ov093
 *   BTL_POKEPARAM_GetLastMoveSlot  0x021D67C4  thumb  ov093
 *   BTL_POKEPARAM_HasMove 0x021D5750 thumb ov093
 *   func_021EFCE4 0x021EFCE4 thumb ov093
 *   func_021EFC1C 0x021EFC1C thumb ov093
 *   BTLV_CORE_GetSlotLow 0x021E8AFC thumb ov093
 *   BTL_POKEPARAM_GetSickTurn 0x021D631C thumb ov093
 *   WAZA_TOOL_GetType 0x0201C1C8 thumb
 *   BTL_CALC_GetTypeAffinityVsPair 0x021D799C thumb ov093
 *   BTL_POKEPARAM_GetHitRecord 0x021D6940 thumb ov093
 *   gBtlClientAiHitKindRows 0x021EFFC2 data ov093 a2
 *   BTL_POKEPARAM_GetHpRatioFixed  0x021D5C44  thumb  ov093
 *   BTL_CALC_GetScanStartIndex 0x021D7F2C thumb ov093
 *   func_021D3DC4 0x021D3DC4 thumb ov093
 *   func_021880BC 0x021880BC thumb ov096
 *   func_02187FB0 0x02187FB0 thumb ov096
 *   func_02188134 0x02188134 thumb ov096
 *   func_02188140 0x02188140 thumb ov096
 *   func_0689CA98 0x0689CA98 thumb ov095
 *   func_0689CAB0 0x0689CAB0 thumb ov095
 *   func_0689CAE0 0x0689CAE0 thumb ov095
 *   BTL_ACTION_SetChangeDepleted 0x021D83C4 thumb ov093
 *   BTL_REC_AppendPacket  0x021EE608  thumb  ov093
 *   BTL_REC_GetPacketId  0x021EE638  thumb  ov093
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   func_021F878C   0x021F878C  thumb ov094
 *   func_021EA600 0x021EA600 thumb ov093
 *   PMSI_PARAM_IsEnabled  0x02024450  thumb
 *   PMSI_PARAM_ToString  0x0202435C  thumb
 *   func_021EA5E4  0x021EA5E4  thumb  ov093
 *   STRBUF_Delete   0x02045808  arm
 *   func_021EA5F0  0x021EA5F0  thumb  ov093
 *   func_02082A90 0x02082A90 arm
 *   func_021EA824 0x021EA824 thumb ov093
 *   gServerCommandHandlers 0x021F00DC data a4
 *   func_021EA458  0x021EA458  thumb  ov093
 *   func_021EA478  0x021EA478  thumb  ov093
 *   func_021EA488 0x021EA488 thumb ov093
 *   func_021EA4C4 0x021EA4C4 thumb ov093
 *   func_021EA678  0x021EA678  thumb  ov093
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_021EA694  0x021EA694  thumb  ov093
 *   func_021EA6F4  0x021EA6F4  thumb  ov093
 *   BTL_CALC_GetCurseTargetKind  0x021D80A8  thumb  ov093
 *   func_021EA0A0 0x021EA0A0 thumb ov093
 *   func_021EA0E4 0x021EA0E4 thumb ov093
 *   func_021EA354  0x021EA354  thumb  ov093
 *   func_021EA0F4  0x021EA0F4  thumb  ov093
 *   func_021EA120  0x021EA120  thumb  ov093
 *   func_021EA280  0x021EA280  thumb  ov093
 *   func_021EA2BC  0x021EA2BC  thumb  ov093
 *   func_021EA384  0x021EA384  thumb  ov093
 *   func_021EA3A0  0x021EA3A0  thumb  ov093
 *   func_021F81D0  0x021F81D0  thumb  ov094
 *   func_021EA40C  0x021EA40C  thumb  ov093
 *   func_021EA428  0x021EA428  thumb  ov093
 *   func_021EA438  0x021EA438  thumb  ov093
 *   func_021EA448  0x021EA448  thumb  ov093
 *   func_021EA7C8  0x021EA7C8  thumb  ov093
 *   func_021EA7E8  0x021EA7E8  thumb  ov093
 *   func_021EA7D8  0x021EA7D8  thumb  ov093
 *   BTL_FIELD_StoreCountdown  0x021EF9C0  thumb  ov093
 *   gWeatherEffects     0x021EFFAE  data   ov093  a2
 *   BTL_FIELD_ClearCountdown  0x021EF9C8  thumb  ov093
 *   func_021EA838  0x021EA838  thumb  ov093
 *   func_021EA850  0x021EA850  thumb  ov093
 *   func_021EA904  0x021EA904  thumb  ov093
 *   func_021EA950  0x021EA950  thumb  ov093
 *   func_021F7E94 0x021F7E94 thumb ov094
 *   func_021F7EA4  0x021F7EA4  thumb  ov094
 *   func_021EA8B4  0x021EA8B4  thumb  ov093
 *   func_021EA8D4  0x021EA8D4  thumb  ov093
 *   func_021EA1B8  0x021EA1B8  thumb  ov093
 *   func_021EA1F0  0x021EA1F0  thumb  ov093
 *   func_021EA8E4 0x021EA8E4 thumb ov093
 *   func_021EA8F4 0x021EA8F4 thumb ov093
 *   gEffortValueParams     0x021EFF88  data  ov093  a2
 *   func_021F8204 0x021F8204 thumb ov094
 *   func_021F8134 0x021F8134 thumb ov094
 *   func_021F8180 0x021F8180 thumb ov094
 *   BTL_EVENT_ReleaseClientHandle 0x021D6EA0 thumb ov093
 *   BTL_POKEPARAM_ReloadFromParam 0x021D6BFC thumb ov093
 *   func_021F8150 0x021F8150 thumb ov094
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   func_021EA3B8 0x021EA3B8 thumb ov093
 *   func_021EA3D4 0x021EA3D4 thumb ov093
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   func_021EADA4 0x021EADA4 thumb ov093
 *   func_021EADB4 0x021EADB4 thumb ov093
 *   func_021EADC4 0x021EADC4 thumb ov093
 *   func_021EADD4 0x021EADD4 thumb ov093
 *   func_021EADE4 0x021EADE4 thumb ov093
 *   func_021EADF4 0x021EADF4 thumb ov093
 *   gExpGainWork 0x021F3B64 data a4
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   func_020181F4   0x020181F4  thumb
 *   POKE_TOOL_GetLevelUpMove   0x02018328  thumb
 *   func_021EA638   0x021EA638  thumb ov093
 *   func_021EAC64   0x021EAC64  thumb ov093
 *   func_021EAC80   0x021EAC80  thumb ov093
 *   g_021F3B64      0x021F3B64  data
 *   func_021F7CFC 0x021F7CFC thumb ov094
 *   func_021F883C 0x021F883C thumb ov094
 *   gCatchShakeMessages 0x021EFF80 data a2
 *   func_021F7C0C 0x021F7C0C thumb ov094
 *   func_021F7D44  0x021F7D44  thumb  ov094
 *   func_021EAA6C  0x021EAA6C  thumb  ov093
 *   func_021EAAD8  0x021EAAD8  thumb  ov093
 *   func_021EA768  0x021EA768  thumb  ov093
 *   func_021EA778  0x021EA778  thumb  ov093
 *   func_021EA7A8  0x021EA7A8  thumb  ov093
 *   func_021EA7B8  0x021EA7B8  thumb  ov093
 *   func_021EA868  0x021EA868  thumb  ov093
 *   func_021EA878  0x021EA878  thumb  ov093
 *   func_0689C9D4 0x0689C9D4 thumb ov095
 *   BTL_MAIN_IsOpposingPos  0x021B8CE8  thumb  ov093
 *   BTL_MAIN_CollectLivingPokeIds  0x021B8D38  thumb  ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTL_MAIN_GetViewPosOfPoke  0x021B8DC0  thumb  ov093
 *   BTL_MAIN_GetSlotClientIdThunk  0x021B8DE4  thumb  ov093
 *   BTL_MAIN_GetSlotNthOfClient  0x021B8DEC  thumb  ov093
 *   BTL_MAIN_GetSlotClientAndNth  0x021B8E28  thumb  ov093
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   BTL_MAIN_GetOwnClientId  0x021B8FF4  thumb  ov093
 *   BTL_MAIN_IsSameTeamClient  0x021B902C  thumb  ov093
 *   BTL_MAIN_GetOwnOpponentClient  0x021B904C  thumb  ov093
 *   BTL_MAIN_GetOpponentClient  0x021B9064  thumb  ov093
 *   BTL_MAIN_AddItemToBag  0x021B9090  thumb  ov093
 *   BTL_MAIN_SubItemFromBag  0x021B90BC  thumb  ov093
 *   BTL_MAIN_IsRecordingActive  0x021B90F8  thumb  ov093
 *   BTL_MAIN_SetOutcomeIfUnset  0x021B916C  thumb  ov093
 *   BTL_MAIN_SetRecordInvalid  0x021B9184  thumb  ov093
 *   BTL_MAIN_GetPrizeMoney  0x021B919C  thumb  ov093
 *   BTL_MAIN_GetBonusMoney  0x021B9210  thumb  ov093
 *   BTL_MAIN_CalcPenaltyMoney  0x021B9244  thumb  ov093
 *   BTL_MAIN_SetKeepBgm  0x021B92A0  thumb  ov093
 *   BTL_MAIN_CopyLiveToSnapshotPoke  0x021B9358  thumb  ov093
 *   BTL_MAIN_ResolveIllusionPoke  0x021B937C  thumb  ov093
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb  ov093
 *   BTL_SIDE_GetClientPokeParam  0x021B990C  thumb  ov093
 *   BTL_SIDE_GetClientPoke  0x021B9920  thumb  ov093
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_MAIN_GetPositionsPerClientThunk  0x021B99B8  thumb  ov093
 *   BTL_MAIN_GetViewPositionsPerClient  0x021B99C0  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   BTL_SLOT_GetRotateSrcIndex  0x021B9AB0  thumb  ov093
 *   BTL_SIDE_GetSlotOfClient  0x021B9AEC  thumb  ov093
 *   BTL_SIDE_GetSlotOfClientThunk  0x021B9AF8  thumb  ov093
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_SLOT_CountLiving  0x021B9B98  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   BTL_SLOT_Swap  0x021B9C10  thumb  ov093
 *   BTL_SLOT_Rotate  0x021B9C50  thumb  ov093
 *   BTL_SLOT_FindPokeId  0x021B9CBC  thumb  ov093
 *   BTL_MAIN_IsTrainerSlotNpc  0x021B9F70  thumb  ov093
 *   BTL_MAIN_GetTrainerAiFlags  0x021B9FBC  thumb  ov093
 *   BTL_MAIN_GetTrainerId  0x021BA004  thumb  ov093
 *   BTL_MAIN_GetTrainerType  0x021BA020  thumb  ov093
 *   BTL_MAIN_GetTrainerSentence  0x021BA02C  thumb  ov093
 *   BTL_MAIN_GetField  0x021BA08C  thumb  ov093
 *   BTL_MAIN_CheckSetupStatusFlag  0x021BA1A8  thumb  ov093
 *   BTL_MAIN_IsRecordEnabledInComm  0x021BA1EC  thumb  ov093
 *   BTL_MAIN_NotifyLevelUp  0x021BA238  thumb  ov093
 *   BTL_MAIN_NotifyCapture  0x021BA2D4  thumb  ov093
 *   BTL_MAIN_GetLimitTimeCommand  0x021BA5C4  thumb  ov093
 *   BTL_MAIN_GetLimitTimeGame  0x021BA5D0  thumb  ov093
 *   BTL_MAIN_RestartBattle  0x021BA73C  thumb  ov093
 *   BTL_MAIN_StartClientMainSteps  0x021BA7F8  thumb  ov093
 *   BTL_MAIN_GetServerFlow  0x021BA820  thumb  ov093
 *   BTL_SERVER_LoadRecorderReplies  0x021BB4E0  thumb  ov093
 *   BTL_SERVER_CompareFlowOutput  0x021BB570  thumb  ov093
 *   BTL_SERVER_CMD_ReadNext  0x021CD5E0  thumb  ov093
 *   BTL_SERVER_CMD_ReadU8Wrapper  0x021CD644  thumb  ov093
 */
#include "btl_server_types.h"
#include "../../matched/include/G_StateData.h"

#define ENTRY(i) (&e[i])
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))
struct Unk021B8CB0;
struct R4;
struct S2;
struct Q1;
struct S_021B8CB0;
struct Party;
struct U16Vec;
struct Rec8;
struct Buf;
struct Sub02008C20Obj;
struct Unk021D62A8;
struct Flags;
struct T;
struct QA;
struct Q5;
struct Q7;
struct Q6;
struct Q4;
struct UtilWork;
struct Unk021D82FC;
struct Arr;
struct Msg;
struct O;
struct Out64B4;
struct Unk021BE518;
struct Unk021D82D0;
struct UtilSlots;
struct QL;
struct QI;
struct S_p12;
struct Q_021C0CB4;
struct Q_021C0CE8;
struct QJ;
struct Entry_p11;
struct Obj;
struct Result;
struct Pack;
struct Rec;
struct Q9;
struct Cmd;
struct Q10;
struct S_p14;
struct Unk021D6C50;
struct Unk021D6C2C;
struct Unk021EFD70;
struct Sav;
struct Q2;
struct QE;
struct Qd;
struct Q3;
struct L;
struct H;
struct QG;
struct QV;
struct G;
struct Rat;
struct G_021CFD50;
struct S;
struct Unk021B8CB0 { u32 f0; u32 mode; };

typedef struct { u8 pad[0xC1]; unsigned char flag:1; unsigned char rest:7; } Flags_021B9184;

typedef unsigned long long u64;

#include "btl_client_types.h"

struct Unk021EFD70 { u16 n0; volatile u16 n1; u8 b[6]; };

/* 021B9B54  ldrb r3,[r0,#0x18]; adds r2,r3,#1; strb r2,[r0,#0x18];
 *           lsls r2,r3,#2; str r1,[r0,r2] */
struct Q1 { u32 items[6]; u8 count; };

/* 021B9BF0  ldrb r2,[r0,#0x18]; cmp r1,r2; bhs; lsls r1,#2; ldr r0,[r0,r1] */
struct S2 { u8 *items[6]; u8 count; };

struct Arr { void *e[6]; u8 n; };

struct H {
    u16 a, b, c, d;
};

struct A {
    int vt;
    int q;
    u16 h8;
    u16 ha;
    int c;
    u16 h[4];
    struct H s18;
    struct H s20;
};

struct B_021B9A00 {
    int f0;
    int f4;
    int f8;
    char b[8];
    int f14;
    struct H s18;
    struct H s20;
};

struct B_021B9EF0 {
    int f0;
    int f4;
    int f8;
    char b[8];
    int f14;
    struct H s18;
    struct H s20;
    char pad[0x68 - 0x28];
    int f68;
};

/* 021BA08C  movs r1,#0xaf; lsls r1,#2; ldr r0,[r0,r1] */
struct Q2 { u8 pad[0x2bc]; u32 v; };

struct S_021B8CB0 { char pad[0x298]; void *a[4]; void *b[4]; void *c; };

/* 021BA5D0  movs r1,#0x11; lsls r1,#6; ldrh r0,[r0,r1] */
struct Q3 { u8 pad[0x440]; u16 v; };

struct T {
    int w[6];
};

/* 021BB840  strb r1,[r0,#0xb]; str r2,[r0]; strb r3,[r0,#0xa] */
struct Q4 { u32 w; u8 pad[6]; u8 c; u8 b; };

/* 021BB964  ldr r0,[r0,#0x44] */
struct Q5 { u8 pad[0x44]; u32 v; };

struct Unk021BE518 { u8 f0; u8 f1[6]; };

struct Buf { u32 wpos, rpos; };

struct S { u32 id[6]; u16 a[6], b[6]; u8 c[6]; u16 d[6]; u8 n, max, f44, f45; };

struct Rec { u32 value; u16 kind; u8 data, flag; };

struct O { u32 pos; struct Rec r[120]; };

struct Entry { u16 value; u16 id:5; u16 mode:4; u16 type:4; u16 marked:1; u16 special:1; u16 error:1; };

struct List_021BDB88 { u8 good, bad, count, pad; struct Entry entries[1]; };

struct Ent_021C0CB4 {
    u16 v;
    u16 lo:5;
    u16 b:4;
    u16 c:4;
    u16 d:1;
    u16 e:1;
    u16 f:1;
};

struct Q_021C0CB4 { u8 pad0[2]; u8 n; u8 pad3; struct Ent_021C0CB4 e[]; };

struct Ent_021C0CE8 {
    u16 v;
    u16 lo : 5;
    u16 b : 4;
    u16 c : 4;
    u16 d : 1;
    u16 e : 1;
    u16 f : 1;
};

struct Q_021C0CE8 { u8 pad0[2]; u8 n; u8 pad3; struct Ent_021C0CE8 e[1]; };

struct Entry_p08 { u16 value; u16 id:5, mode:4, type:4, marked:1, special:1, error:1; };

struct List_021C0F24 { u8 good, bad, count, pad; struct Entry_p08 entries[1]; };

struct Entry_p11 { u32 value; u8 flag; u8 a, b, c, d, e, f, pad; };

struct Out64B4 {
    u16 h0;
    u16 h2;
    u16 h4;
    u8 b6;
    u8 pad7;
    u32 w8;
    u32 wC;
    u32 w10;
};

typedef enum { KIND_NONE, KIND_FIRST, KIND_SECOND } Kind;

/* 021C7CD4  movs r1,#0x7e; lsls r1,#6; ldrh r0,[r0,r1] */
struct Q6 { u8 pad[0x1f80]; u16 v; };

/* 021C8138  ldr r0,[r0,#0x10]; lsls r0,#0x10; lsrs r0,#0x10 */
struct Q7 { u8 pad[0x10]; u32 v; };

struct S_p12 {
    u16 x;
    u16 y : 8;
    u16 n : 7;
    u16 z : 1;
    u32 arr[8];
};

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 mid : 10; u32 fl : 1; u32 top : 8;
    int value;
    u8 targets[12];
    u8 count;
    u8 flag;
    u8 gap[2];
    struct Msg msg;
} Ent_021C9068;

typedef struct { u32 low:8, index:5, pad:10, flag:1, high:8; u32 kind; union Slot value; u8 a,b,c,id,d; u8 pad11[3]; u8 msg[36]; } Ent_021C9178;

typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; enum Kind kind; u32 value; s8 a; u8 b,c,count; u8 ids[8]; u8 msg[36]; } Ent_021C9250;

struct Cmd { u32 a:8; u32 id:5; u32 b:19; };

struct Flags { u32 a:1; u32 b:31; };

struct T6 { u8 f0; u8 f1; u16 f2; u16 f4; };

struct S_p14 {
    unsigned int x : 10;
};

/* 021CC96C  ldr r0,[r0]; lsls #1; lsrs #0x1f */
struct Q9 { u32 a : 30; u32 b : 1; u32 c : 1; };

/* 021CC99C  ldr r0,[r0]; lsls #3; lsrs #0x1f */
struct Q10 { u32 a : 28; u32 b : 1; u32 c : 3; };

struct SizeEntry {
    u8 id;
    u8 size;
};

struct Pack {
    u32 lo : 10;
    u32 off : 9;
    u32 rest : 13;
    u8 data[500];
};

/* 021CD95C  str r1,[r0,#0x54] */
struct QA { u8 pad[0x54]; u32 v; };

/* 021CDA0C  str r1,[r0,#0x28]; movs r1,#0x6a; movs r2,#0; lsls r1,#2;
 *           strb r2,[r0,r1] */
struct QE { u8 pad[0x28]; u32 v; u8 rest[0x1a8 - 0x2c]; u8 z; };

typedef struct { u8 id; u8 flag; u16 pad; BtlClientStepFn callbacks[3]; } Entry_021CC768;

typedef struct { u32 kind : 4; u32 rest : 28; } Command;

struct L { u8 pad[0x11D]; u8 idx; u8 pad2[0x1A6-0x11E]; u8 sel; };

typedef enum { OFFSET = 0x19a } Off;

typedef struct { u32 kind:4; u32 sub:3; u32 id:16; u32 rest:9; } Record_td;

typedef struct { u8 *q; u8 f[4]; } Ent_021CECB4;

typedef enum { VALUE_ZERO, VALUE_ONE } Value;

struct Unk021D82D0 { u32 kind : 4; u32 sub : 3; u32 id : 16; u32 rest : 9; };

struct G_021CFD50 {
    void *p0;
    void *p1;
    u8 pad0[0xec];
    u64 seed;
    u64 mul;
    u64 add;
};

struct Row { u8 kind; u8 pad; u16 ids[4]; };

struct G {
    u8 pad0[0xf4];
    u64 seed;
    u64 mul;
    u64 add;
    u8 pad1[0xc];
    void *list;
};

typedef struct { u8 pad[0x1B3]; volatile u8 count; } CountField;

typedef struct { int code; BtlClientSeqFn fn; } CodeEntry;

typedef struct { u16 a; u16 b; } Pair16;

struct StateDataL { u8 pad0[8]; int counter; u32 remaining; u32 pad10; u8 result[14]; };

union DView { struct StateDataL s; u32 w[9]; };

extern int BTL_POKEPARAM_IsFainted(void *m);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 BTL_MAIN_GetClientTrainerIndex(u8 *p, u32 k, u8 n);
extern int BTL_MAIN_IsMultiMode(unsigned char **p);
extern void *BTL_MAIN_GetCompetitor(void ***p);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern int BTL_POKEPARAM_IsIllusionActive(struct R4 *p);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void POKEPARTY_Init(struct Party *p);
extern u32 BTL_MAIN_GetRule(void **p);
extern int BTL_POKEPARAM_IsAbleToBattle(void *);
extern u32 func_020307B0(void *p);
extern void PMSI_PARAM_Copy(struct Rec8 *dst, const struct Rec8 *src);
extern u32 sub_02008DF0(struct Sub02008C20Obj *, int);
extern u32 sub_02008DAC(struct Sub02008C20Obj *, int, u32);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 func_021D805C(void *p, u32 n);
extern u32 _u32_div_f(u32, u32);
extern void *func_02030734(u16, unsigned int, int, const char *, u16);
extern void *BTL_ADAPTER_Create(u32, int, u32, u32);
extern void BTL_ADAPTER_Delete(void *p);
extern u8 BTL_MAIN_GetCommPos(u8 **p);
extern u32 BTL_CALC_ActionGetKind(Action *);
extern u16 BTL_MAIN_GetWinBgm(void **);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void MI_CpuFill8(void *, int, u32);
extern void BTL_CLIENT_SET_Clear(u8 *p);
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern u32 WAZA_TOOL_GetParam(u32 v, u32 n);
extern u32 BTL_ACTION_GetFightMove(Action *m);
extern int BTL_MAIN_GetCompetitorKind(unsigned int **p);
extern union Slot BTL_POKEPARAM_GetSickContRaw(void *p, int i);
extern u16 BTLV_CORE_GetSlotValue(union Slot v);
extern void BTL_ACTION_SetFight(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u8 BTL_POKEPARAM_FindMoveSlot(struct UtilWork *p, u16 id);
extern int WAZA_TOOL_GetFlag(void *bag, int item);
extern u32 WAZA_TOOL_GetCategory(u16);
extern u16 BTL_POKEPARAM_GetSickParam(struct UtilSlots *p, int i);
extern int BTL_POKEPARAM_IsSemiInvulnerable(struct UtilWork *p);
extern u32 BTL_POKEPARAM_GetMovePPChecked(struct UtilWork *p, u32 i);
extern u16 BTL_POKEPARAM_GetLastSelectedMoveId(u8 *);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct QL *p);
extern u32 WAZA_TOOL_IsDamaging(void *p);
extern unsigned int BTL_MAIN_CheckSceneOff(unsigned char *p);
extern u32 WAZA_TOOL_GetCategory(u16 move);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int WAZA_TOOL_GetDamageType(int a);
extern u16 BTL_POKEPARAM_GetTypePair(void *);
extern int BTL_POKEPARAM_IsHpFull(u8 *p);
extern int BTL_CALC_SummarizeTypeAffinity(int);
extern void BTL_POKEPARAM_SetAbility(struct QJ *p, u32 v);
extern u32 func_0203F0A8(void);
extern void BTL_POKEPARAM_ResetAllEffects(u8 *);
extern int BTL_POKEPARAM_AddExp(struct Obj *p, u32 *remaining, struct Result *r);
extern u8 WAZA_TOOL_GetType(void *p);
extern int WAZA_TOOL_GetDamageType(int a);
extern int BTL_POKEPARAM_HasType(void *p, int k);
extern u16 WAZA_TOOL_GetPower(void *p);
unsigned int BTL_MAIN_GetActivePosPerSide(unsigned int **p);
extern int BTL_POKEPARAM_Transform(struct Unk021D6C50 *a, struct Unk021D6C50 *b);
extern void BTL_POKEPARAM_ClearIllusion(struct Unk021D6C2C *p);
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern void func_021D3F04(u8 *);
extern void func_021D3D9C(u8 *);
extern void *func_02187F00(void **, u32, u32, u32, u16);
extern void *BTL_REC_CreateBuffer(u32);
extern void BTL_REC_DeleteBuffer(void *);
extern void func_02188080(void *);
extern u16 *BTL_REC_ReadEntry(u16 *, u32 *);
extern u32 BTL_REC_CountFlaggedRecords(void *);
extern void func_021D3F48(u8 *,u32);
extern void BTL_REC_ResetReader(void *);
extern void BTL_ADAPTER_ClearRecvHeader(void *);
extern void func_021D3F64(u8 *,u16);
extern void func_021D3F88(void *p);
extern void func_021D3FDC(u8 *p, struct Qd *q);
extern u8 BTL_ADAPTER_GetRecvCommand(void *);
extern int BTL_ADAPTER_GetRecvData(int, void *);
extern int func_021D3FAC(u8 *);
extern void func_021D3FC4(u8 *);
extern int func_021D3F4C(void *);
extern int BTL_ADAPTER_SetRecvTarget(void *,void *,u32);
extern u8 func_021D3F60(u8 *);
extern void GFL_USE_SetPlayersAudible(int,u32);
extern void PM_VOICE_ResetMasterVolume(void);
extern int GFL_USE_IsBgmFading(void);
extern u16 func_021D3FA8(u8 *p);
extern void PM_VOICE_SetMasterVolume(u8);
extern int func_021D3F98(u8 *);
extern void func_021EAE24(u8 *p);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void func_021F88BC(int);
extern void *func_021F8678(void);
extern int func_021EAE34(u8 *p);
extern void func_021EAE74(char *p, u32 a, u32 b);
extern int func_021F8524(int);
extern void func_021E90A0(unsigned int *o, unsigned int key);
extern int func_021E90D0(void *s);
extern void func_021F84E8(int a, int b);
extern void func_021F8504(u32 a, u32 b, u32 c);
extern void func_021EAEA8(u8 *p, int v);
extern int BTL_REC_ReadSkipFlag(int, int);
extern void func_021D3F54(u8 *p);
extern void func_021EAA00(u8 *p, u8 v);
extern void func_021EAA5C(u8 *o);
extern int func_021EAA34(u8 *o, u8 *out);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EAF78(u8 *o, u8 v);
extern u32 *BTL_REC_ReadRecord(void *,u8,u8 *,u8 *);
extern void func_021D3FD0(unsigned char *p);
extern void func_021EA614(char *p, void *h);
extern int func_021EA710(u32 *p);
extern void BTL_CALC_ActionSetNone(u32 *p);
extern void func_021EAE44(void *);
extern int func_021EAE54(void *);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern u32 BTL_CALC_PeekMoveTarget(void *,void *,void *,u32,void *);
extern void func_021EA65C(char *p, void *h);
extern void func_021E9760(char *, u8 *, int, int);
extern void func_021E979C(char *p);
extern int func_021E97A4(char *p);
extern void func_021E9964(u32);
extern void func_0689CB08(u8 *);
extern int func_021E9974(u32);
extern void func_021E9954(void *);
extern void func_021F7F58(int, u32, u32, u32, u32);
extern void func_021F7998(u32 a);
extern int func_021EA6B0(char *, u16, u16);
extern int BTL_CALC_IsGymLeaderTrainer(u32 n);
extern void func_021F87EC(u32);
extern int func_021F8774(void);
extern void GFL_USE_FadeOutBgm(u32);
extern int func_021F7EB4(void);
extern u32 func_0202A298(u32,u32,u32);
extern u32 BTL_CALC_DivideMaxHp(void *p, u32 b);
extern void func_021E97BC(char *p, u8 *a, int b);
extern void func_021E9808(char *p, u32 *q, int c);
extern void func_021E98AC(void *);
extern u32 func_021E98B4(void *);
extern u32 func_021D832C(struct Unk021D82FC *p);
extern void BTL_ACTION_SetRotate(u32 *p, u32 sub);
extern u32 BTL_CALC_IsMultiFighterRule(u32);
extern void func_021E98BC(char *p, u8 *a, int b);
extern void func_021E9920(void *);
extern int func_021E98E8(char *p);
extern void func_021E9858(char *p);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern void func_021E9CE0(u8 *p, u8 a, u8 b);
extern void func_021E9B14(unsigned int *p);
extern int func_021E9B20(u8 *p);
extern void func_021E9A78(char *, const u8 *, int, int, u8 *);
extern int func_0689CB14(void *);
extern u8 func_0689CB1C(void *);
extern void BTL_ACTION_SetChange(void *, u8, u8);
extern void func_021E9D04(void *, int, int, int, u32, u32);
extern void func_021E9E70(u8 *p);
extern int func_021E9E80(u8 *p);
extern u16 func_021EA01C(u8 *p);
extern u8 func_021EA044(struct QV *p);
extern u8 func_021EA030(u8 *p);
extern u8 func_021EA04C(u8 *p);
extern void BTL_ACTION_SetItem(u32 *p, u32 id, u32 sub, u32 val);
extern void func_021EA058(char *p);
extern int func_021EA720(u32 *p);
extern void func_021EABC4(u8 *a, u32 x, u32 y, u32 z);
extern int func_021EAC54(void *, int *);
extern void func_021D8414(u32 *p);
extern void func_021EA7FC(char *p);
extern int func_021EA814(u32 *p);
extern void BTL_CALC_ActionSetForcedSkip(u32 *p);
extern u8 BTL_POKEPARAM_GetLastMoveSlot(u8 *p);
extern int BTL_POKEPARAM_HasMove(void *, u32);
extern void *func_021EFCE4(char *arg0, int arg1);
extern int func_021EFC1C(int, int, void *, u32);
extern u8 BTLV_CORE_GetSlotLow(union Slot);
extern u8 BTL_POKEPARAM_GetSickTurn(u8 *p, int i);
extern u8 WAZA_TOOL_GetType(void *p);
extern int BTL_CALC_GetTypeAffinityVsPair(int, u16);
extern int BTL_POKEPARAM_GetHitRecord(const u8 *p, int i, u32 j, u16 *out);
extern int BTL_POKEPARAM_GetHpRatioFixed(struct Rat *p);
extern u8 BTL_CALC_GetScanStartIndex(u32 a, u8 b);
extern u32 func_021D3DC4(u8 *, void *, void *);
extern void func_021880BC(int, u8 *, int);
extern int func_02187FB0(u8 *);
extern u8 func_02188134(u8 *);
extern u8 func_02188140(u8 *);
extern void func_0689CA98(void *, u32, u32, u32);
extern void func_0689CAB0(void *, u32);
extern void func_0689CAE0(void *, void *);
extern void BTL_ACTION_SetChangeDepleted(u32 *p);
extern void BTL_REC_AppendPacket(u8 *p, const u8 *src, int n);
extern u8 BTL_REC_GetPacketId(u8 *p);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void func_021F878C(u32 a);
extern void func_021EA600(char *p);
extern int PMSI_PARAM_IsEnabled(const u16 *p);
extern void *PMSI_PARAM_ToString(void *slots, unsigned int heap);
extern void func_021EA5E4(unsigned char *p, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021EA5F0(char *p, void *h);
extern void func_02082A90(const void *, void *, u32);
extern void func_021EA824(char *p);
extern void func_021EA458(char *ctx, u16 a, u16 b);
extern int func_021EA478(u32 *p);
extern void func_021EA488(void *s, u8 a, u8 b, u8 c);
extern int func_021EA4C4(void *s);
extern void func_021EA678(char *p, u16 k, int *c);
extern void GFL_USE_PlaySeDefaultVolume(unsigned int arg);
extern void func_021EA694(char *p, u16 k, int *c);
extern void func_021EA6F4(void *p, u8 b, u16 c);
extern int BTL_CALC_GetCurseTargetKind(void *p);
extern void func_021EA0A0(u32 *p, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u8 s7);
extern int func_021EA0E4(u32 *p);
extern void func_021EA354(void *ctx, int a, int b);
extern void func_021EA0F4(void *s, u32 a, u32 b, u32 c);
extern int func_021EA120(void *s);
extern void func_021EA280(char *ctx, u32 n, int b, const u8 *c, u16 e);
extern int func_021EA2BC(char *ctx);
extern void func_021EA384(char *ctx, int a);
extern int func_021EA3A0(u32 *p);
extern void func_021F81D0(u32 a, u32 b);
extern void func_021EA40C(char *ctx, int a);
extern int func_021EA428(u32 *p);
extern void func_021EA438(u32 *p, u32 a2);
extern int func_021EA448(u32 *p);
extern void func_021EA7C8(void *ctx, int a);
extern int func_021EA7E8(void *w, int v);
extern void func_021EA7D8(void *ctx, int a);
extern int *BTL_FIELD_StoreCountdown(int *p, int a, int b);
extern void BTL_FIELD_ClearCountdown(int *p);
extern void func_021EA838(u32 *p, u32 k);
extern int func_021EA850(u32 *p, u32 k);
extern void func_021EA904(void *w, u32 a, u32 b, u32 c, int d, int e);
extern int func_021EA950(void *w);
extern void func_021F7E94(int a);
extern void func_021F7EA4(u32 v);
extern void func_021EA8B4(char *ctx, u32 a, u32 b);
extern int func_021EA8D4(u32 *p);
extern void func_021EA1B8(void *s, u32 a, int b, int c);
extern int func_021EA1F0(void *s);
extern void func_021EA8E4(u32 *p);
extern int func_021EA8F4(u32 *p);
extern int func_021F8204(int);
extern void func_021F8134(int, u32);
extern int func_021F8180(void);
extern void BTL_EVENT_ReleaseClientHandle(void *);
extern void BTL_POKEPARAM_ReloadFromParam(u8 *p);
extern void func_021F8150(int, void *);
extern int GFL_USE_IsAnySeBusy(void);
extern void func_021EA3B8(char *ctx, int a, int b);
extern int func_021EA3D4(void *);
extern void GFL_USE_SetBgmPlayerParam(void *);
extern int GFL_USE_PushBgm(void);
extern int GFL_USE_IsBgmPlaying(void);
extern int GFL_USE_PopBgm(void);
extern void func_021EADA4(u8 *, int, void *);
extern int func_021EADB4(u8 *);
extern void func_021EADC4(u8 *);
extern int func_021EADD4(u8 *);
extern void func_021EADE4(u8 *);
extern int func_021EADF4(u8 *);
extern int GFL_USE_IsSeqPlaying(unsigned int);
extern u16 POKE_TOOL_GetLevelUpMove(void *p, u32 *idx, u32 heap);
extern void func_021EA638(char *p, void *h, int c);
extern void func_021EAC64(u8 *p, u8 a, int c);
extern int func_021EAC80(u8 *p, u8 *out);
extern void func_020181F4(void *p, u16 move, u32 slot);
extern void func_021F7CFC(u32, u16, u8, int, int);
extern void func_021F883C(u32);
extern void func_021F7C0C(void);
extern void func_021F7D44(int a, u16 b);
extern void func_021EAA6C(u32 a, int b, int c);
extern int func_021EAAD8(u32 a);
extern void func_021EA768(u32 *p, u32 a2, u32 a3);
extern int func_021EA778(u32 *p, u32 a2);
extern void func_021EA7A8(u32 *p, u32 a2);
extern int func_021EA7B8(u32 *p, u32 a2);
extern void func_021EA868(u32 *p, u32 a2, u32 a3);
extern int func_021EA878(u32 *p);
extern int func_0689C9D4(u16);
int BTL_MAIN_IsOpposingPos(int a, int b, int c);
u8 BTL_MAIN_CollectLivingPokeIds(void *p, int a, int k, u8 *out);
u8 BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
unsigned char BTL_MAIN_GetViewPosOfPoke(unsigned char *p,void *a,unsigned int b);
u8 BTL_MAIN_GetSlotClientIdThunk(char *p, int i);
unsigned char BTL_MAIN_GetSlotNthOfClient(char *p,unsigned char k);
void BTL_MAIN_GetSlotClientAndNth(u8 *p, u8 n, u8 *out, u8 *cnt_out);
u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
u8 BTL_MAIN_GetOwnClientId(u8 *p);
int BTL_MAIN_IsSameTeamClient(int a, int b);
u8 BTL_MAIN_GetOwnOpponentClient(u8 *p,int k);
u32 BTL_MAIN_GetOpponentClient(u8 *p, int k, int x);
void BTL_MAIN_AddItemToBag(u8 *p, u32 k, u32 x);
void BTL_MAIN_SubItemFromBag(u8 *p,u8 k,u32 x);
int BTL_MAIN_IsRecordingActive(u8 *p);
void BTL_MAIN_SetOutcomeIfUnset(u8 *p,u32 x);
void BTL_MAIN_SetRecordInvalid(Flags_021B9184 **p);
u32 BTL_MAIN_GetPrizeMoney(u8 *p);
u32 BTL_MAIN_GetBonusMoney(u8 *p);
u32 BTL_MAIN_CalcPenaltyMoney(char *p);
void BTL_MAIN_SetKeepBgm(u8 *p);
void BTL_MAIN_CopyLiveToSnapshotPoke(char *p, int i);
u8 *BTL_MAIN_ResolveIllusionPoke(void *a, char *b, u8 *c);
u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
void *BTL_SIDE_GetClientPokeParam(char *p, unsigned int i, unsigned int j);
u8 *BTL_SIDE_GetClientPoke(void *p, u32 i, u8 j);
u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
int BTL_MAIN_GetPositionsPerClientThunk(void *pp, unsigned int b);
u8 BTL_MAIN_GetViewPositionsPerClient(void **p, u32 b);
int BTL_MAIN_IsPokeSamePair(unsigned int a, unsigned int b);
u8 BTL_SLOT_GetRotateSrcIndex(u8 x);
char *BTL_SIDE_GetSlotOfClient(char *p, int i);
char *BTL_SIDE_GetSlotOfClientThunk(char *p, int i);
u8 BTL_SLOT_GetCount(void *p);
u8 BTL_SLOT_CountLiving(u8 *p);
u8 *BTL_SLOT_GetPokeParam(void *p, u32 i);
void BTL_SLOT_Swap(u32 *p, int a, int b);
void BTL_SLOT_Rotate(u8 **p, u8 k, u8 **o1, u8 **o2);
int BTL_SLOT_FindPokeId(u8 *p, int v);
int BTL_MAIN_IsTrainerSlotNpc(u8 *p, int i);
int BTL_MAIN_GetTrainerAiFlags(char *p, int i);
u16 BTL_MAIN_GetTrainerId(char *p, int i);
unsigned short BTL_MAIN_GetTrainerType(char *p, int i);
void *BTL_MAIN_GetTrainerSentence(char *p, int i, int mode);
u32 BTL_MAIN_GetField(void *p);
int BTL_MAIN_CheckSetupStatusFlag(char **p, int m);
BOOL BTL_MAIN_IsRecordEnabledInComm(char **p);
void BTL_MAIN_NotifyLevelUp(char *p, void *m);
void BTL_MAIN_NotifyCapture(u32 p, u32 *q);
u16 BTL_MAIN_GetLimitTimeCommand(u8 *p);
u16 BTL_MAIN_GetLimitTimeGame(void *p);
void BTL_MAIN_RestartBattle(char *p, u16 x);
void BTL_MAIN_StartClientMainSteps(char *p);
u32 BTL_MAIN_GetServerFlow(int *p);
void BTL_SERVER_LoadRecorderReplies(Obj_td *p, void *src, int n);
int BTL_SERVER_CompareFlowOutput(u8 *p, int sel, void *data, u32 n);
int BTL_SERVER_CMD_ReadNext(Buf_021CC768 *r, s32 *a);
u8 BTL_SERVER_CMD_ReadU8Wrapper(u8 *p);
BtlClient *BTL_CLIENT_Create(u8 *battleMain, u8 *sideSet, int netEnabled, int netSystem, u16 clientIndex, u16 slotTotal, u8 clientKind, int isCommBattle, int isReplay, BtlClientRng *rngInit, u16 heapId);
void BTL_CLIENT_Delete(BtlClient *client);
void BTL_CLIENT_MarkCommandIssued(BtlClient *client);
u16 *BTL_CLIENT_ReadRecorderEntry(BtlClient *client, u32 *out);
void BTL_CLIENT_AttachRemoteLink(BtlClient *client, void *a);
void BTL_CLIENT_SetView(BtlClient *client, u32 v);
void BTL_CLIENT_SetRequestParam(BtlClient *client, u32 v);
u32 BTL_CLIENT_GetNetChannel(BtlClient *client);
void BTL_CLIENT_RunTick(BtlClient *client);
void BTL_CLIENT_StartRemoteStep(BtlClient *client, u16 n);
void BTL_CLIENT_StartMainStep(BtlClient *client);
u32 BTL_CLIENT_IsRemote(BtlClient *client);
u16 BTL_CLIENT_GetQueuedCommandWord(BtlClient *client);
u32 BTL_CLIENT_IsMainStepActive(BtlClient *client);
void BTL_CLIENT_AddPoints(BtlClient *client, u8 n);
void BTL_CLIENT_SetStepFn(BtlClient *client, u32 v);
int BTL_CLIENT_StepMain(BtlClient *client);
int BTL_CLIENT_StepRemote(BtlClient *client);
void BTL_CLIENT_ResetSendWord(BtlClient *client);
BtlClientStepFn BTL_CLIENT_FindCommandStepFn(BtlClient *client, u32 id, int *out);
void BTL_CLIENT_GetCursor(BtlClient *client, int *o);
int BTL_CLIENT_IsWindowWaiting(BtlClient *client);
u32 BTL_CLIENT_IsWindowDone(BtlClient *client);
int BTL_CLIENT_StepOpenBattleWindow(BtlClient *client, int *st);
int BTL_CLIENT_PollWindowStep(BtlClient *client, int b);
void BTL_CLIENT_StoreMonParam(BtlClient *client);
u32 BTL_CLIENT_HasMonParamDropped(BtlClient *client);
void *BTL_CLIENT_GetLeadPartyMon(BtlClient *client);
int BTL_CLIENT_StepWindowModeSelect(BtlClient *client, int *st);
u32 BTL_CLIENT_PickWindowMode(u32 mode);
int BTL_CLIENT_ReturnTrue(void);
void BTL_CLIENT_StartWindowModeSend(BtlClient *client);
void BTL_CLIENT_StartTimeLimit(BtlClient *client);
int BTL_CLIENT_PollTimeLimitReady(BtlClient *client);
int BTL_CLIENT_PollTimeLimitAndSetSub(BtlClient *client, void *q);
void BTL_CLIENT_StopTimeLimit(BtlClient *client);
void BTL_CLIENT_BuildActionPromptMessage(BtlClient *client, u8 *q, u8 *o);
void BTL_CLIENT_SetSubFn(BtlClient *client, void *q);
u32 BTL_CLIENT_RunSubFn(BtlClient *client);
u32 BTL_CLIENT_StepStartActionSelection(BtlClient *client, s32 *st);
int BTL_CLIENT_StepPlaybackRecordedAction(BtlClient *client, int *state);
void BTL_CLIENT_ResetActionCursor(BtlClient *client);
u32 BTL_CLIENT_InitActionSelection(BtlClient *client);
void BTL_CLIENT_ShowMessage(BtlClient *client, void *q);
int BTL_CLIENT_StepAutoSelectActions(BtlClient *client, int *state);
int BTL_CLIENT_StepSelectAction(BtlClient *client, u32 *st);
u32 BTL_CLIENT_StepShowSupportItemMessage(BtlClient *client, int *st);
u32 BTL_CLIENT_FindSupportItem(BtlClient *client, u16 *out);
int BTL_CLIENT_StepSelectMove(BtlClient *client, u32 *state);
void BTL_CLIENT_BuildMoveUsableTable(BtlClient *client, Ent_021CECB4 *out);
u32 BTL_CLIENT_StepMoveHighlight(BtlClient *client, s32 *st);
u32 BTL_CLIENT_StepSelectSwitchTarget(BtlClient *client, int *st);
u32 BTL_CLIENT_StepSelectItem(BtlClient *client, int *st);
u32 BTL_CLIENT_IsLoneFoeSemiInvulnerable(BtlClient *client);
u32 BTL_CLIENT_StepSelectRun(BtlClient *client, u32 *st);
u32 BTL_CLIENT_StepAdvanceSlot(BtlClient *client, int *st);
u32 BTL_CLIENT_StepSendActions(BtlClient *client, s32 *st);
void BTL_CLIENT_ClearSlotLinkWords(BtlClient *client);
void BTL_CLIENT_SetSlotLinkWord(BtlClient *client, u32 i, u32 v);
void BTL_CLIENT_FlushSlotLinkWord(BtlClient *client, u32 i);
void BTL_CLIENT_FlushSlotLinkWords(BtlClient *client);
void BTL_CLIENT_ClearSlotFlags(BtlClient *client);
void BTL_CLIENT_SetSlotFlag(BtlClient *client, u32 i, u32 v);
u8 BTL_CLIENT_GetSlotFlag(BtlClient *client, u32 i);
u8 BTL_CLIENT_SumSlotFlagsBeforeCurrent(BtlClient *client);
u32 BTL_CLIENT_IsActionForced(u8 *p, void *q, u8 *o);
u32 BTL_CLIENT_SetStruggleIfNoMoves(BtlClient *client, void *q, u32 y);
void BTL_CLIENT_SetStruggleAction(struct Unk021D82D0 *out, BtlClient *client, void *q);
int BTL_CLIENT_IsMoveSelectionBlocked(BtlClient *client, void *m, u32 move, void *out);
u32 BTL_CLIENT_BuildUsableMoveMask(BtlClient *client, void *q, u8 *out);
int BTL_CLIENT_IsHeldItemEffective(BtlClient *client, void *q);
u32 BTL_CLIENT_GetEscapeBlocker(BtlClient *client, void *q, u8 *a, u16 *b);
u32 BTL_CLIENT_GetEscapeBlockerForSide(BtlClient *client, u8 *a, u16 *b);
u32 BTL_CLIENT_FindTrapper(BtlClient *client, void *m, u8 *a, u16 *b);
int BTL_CLIENT_CanShadowTagTrap(void *p, void *q);
int BTL_CLIENT_CanArenaTrapTrap(BtlClient *client, void *m);
int BTL_CLIENT_CanMagnetPullTrap(void *p, void *q);
void BTL_CLIENT_ClearSlotOrder(BtlClient *client);
int BTL_CLIENT_HasSlotInOrder(BtlClient *client, int v);
void BTL_CLIENT_SetSlotOrder(BtlClient *client, u32 i, u32 v);
int BTL_CLIENT_ChooseAiSwitchTarget(BtlClient *client, void *m, u32 slot, u8 *out);
u8 *BTL_CLIENT_PickRandomFoe(BtlClient *client, int k);
int BTL_CLIENT_IsCountdownEndingNext(void *p, void *q);
int BTL_CLIENT_ShouldSwitchVsWonderGuard(BtlClient *client, void *a, void *b);
int BTL_CLIENT_ShouldSwitchNoEffectiveMove(BtlClient *client, void *a, void *b);
int BTL_CLIENT_ShouldSwitchWhileLocked(BtlClient *client, void *mon, void *target);
int BTL_CLIENT_FindSwitchFromHitHistory(BtlClient *client, void *mon, void *target, u8 *out);
int BTL_CLIENT_FindNaturalCureSwitch(BtlClient *client, void *m, u8 *out);
int BTL_CLIENT_FindSwitchByTypeMatchup(BtlClient *client, void *mon, void *target, u8 *out);
int BTL_CLIENT_FindMemberWithAbility(BtlClient *client, u16 a, u8 *out);
int BTL_CLIENT_AnyMemberHasMoveVsTarget(BtlClient *client, void *a, int b);
int BTL_CLIENT_FindMemberResistingType(BtlClient *client, u8 a, int b, u8 *out);
int BTL_CLIENT_HasMoveWithAffinityVsTarget(BtlClient *client, void *m, void *a, int b);
u8 BTL_CLIENT_PickRotationPosition(BtlClient *client);
int BTL_CLIENT_StepAutoChooseActions(BtlClient *client, u32 *state);
u8 BTL_CLIENT_ListAbleMons(BtlClient *client, u8 *out);
void BTL_CLIENT_SortMonsByMovePower(BtlClient *client, u8 *order, u8 count, void *target);
void BTL_CLIENT_BuildSlotChoices(BtlClient *client, u32 a, u32 b, void *q, void *out);
void BTL_CLIENT_SetChangeActionsFromChoice(BtlClient *client, u8 *s);
void BTL_CLIENT_SetChangeActionsFirstAble(BtlClient *client);
u8 BTL_CLIENT_CollectOwnReceivedIds(BtlClient *client, u8 *out);
int BTL_CLIENT_StepAskYesNo(BtlClient *client, int *state);
int BTL_CLIENT_StepChoiceMode2(BtlClient *client, int *state);
int BTL_CLIENT_StepChoiceMode1(BtlClient *client, int *state);
int BTL_CLIENT_ChooseReplacementsAuto(BtlClient *client);
int BTL_CLIENT_StepForwardToSubFn(BtlClient *client, int *state);
int BTL_CLIENT_StepChooseReplacement(BtlClient *client, int *state, u8 param);
int BTL_CLIENT_IsDoubleBattleLeadAlive(BtlClient *client);
int BTL_CLIENT_TrySetRotateAction(BtlClient *client, void *q);
int BTL_CLIENT_StepAskSwitchBeforeSendOut(BtlClient *client, int *state);
int BTL_CLIENT_RecordReceivedPacket(BtlClient *client);
int BTL_CLIENT_StepShowResultIfView(BtlClient *client, int *state);
int BTL_CLIENT_StepShowResultMessage(BtlClient *client, int *state, void *a2);
int BTL_CLIENT_GetOutcomeForClient(BtlClient *client);
int BTL_CLIENT_StepShowTrainerResultIfView(BtlClient *client, int *state);
int BTL_CLIENT_StepShowTrainerResult(BtlClient *client, int *state, void *q);
int BTL_CLIENT_StepShowEndSpeechIfView(BtlClient *client, int *state);
int BTL_CLIENT_StepShowEndSpeech(BtlClient *client, int *state, void *a2);
void BTL_CLIENT_ShowEndSpeech(BtlClient *client, int a, int b);
int BTL_CLIENT_StepShowPrizeMoneyMessage(BtlClient *client, int *state);
int BTL_CLIENT_StepShowBlackoutMessages(BtlClient *client, int *state);
int BTL_CLIENT_StepShowFixedMessage(BtlClient *client, int *state);
int BTL_CLIENT_StepRunServerCommandsIfView(BtlClient *client, int *state);
int BTL_CLIENT_StepRunServerCommands(BtlClient *client, int *state, void *a2);
int BTL_CLIENT_StepShowRecallMessage(BtlClient *client, int *state, int *pp);
int BTL_CLIENT_PickRecallMessageId(BtlClient *client, u8 x, int *out);
int BTL_CLIENT_StepPlayRecallAnim(BtlClient *client, int *state, int *pp);
int BTL_CLIENT_StepSendOutMon(BtlClient *client, int *state, const u32 *params);
int BTL_CLIENT_PickSendOutMessageId(BtlClient *client);
int BTL_CLIENT_StepShowSideMessage(BtlClient *client, int *state, u32 *a);
int BTL_CLIENT_StepShowSideMessageWithSound(BtlClient *client, int *state, u32 *a);
int BTL_CLIENT_StepShowTaggedMessage(BtlClient *client, int *state, u32 *a);
int BTL_CLIENT_StepShowTaggedMessageWithSound(BtlClient *client, int *state, u32 *a);
int BTL_CLIENT_StepShowItemUseMessage(BtlClient *client, int *state, u32 *a);
u32 BTL_CLIENT_GetMoveAnimTarget(BtlClient *client, u32 k, u8 b);
int BTL_CLIENT_StepPlayMoveAnim(BtlClient *client, int *state, const u32 *a);
int BTL_CLIENT_StepSetMonVisibility(BtlClient *client, int *state, u32 *a);
int BTL_CLIENT_StepPlayMonTaskAnim(BtlClient *client, int *state, u32 *a);
int BTL_CLIENT_StepPlayMultiMonAnim(BtlClient *client, int *state, u32 *a);
int BTL_CLIENT_StepUpdateMonGaugeThenMessage(BtlClient *client, int *state, u32 *a);
int BTL_CLIENT_StepStartEffectForMon(BtlClient *client, int *state, u32 *a);
int BTL_CLIENT_StepPlaySubstituteAnim(BtlClient *client, int *state, u32 *a);
int BTL_CLIENT_StepFaintMon(BtlClient *client, int *st, u32 *c);
int BTL_CLIENT_StepReviveMon(BtlClient *client, int *st, u32 *c);
int BTL_CLIENT_StepPlayMonEffect262(BtlClient *client, int *st, u32 *c);
int BTL_CLIENT_StepPlayMonEffect261(BtlClient *client, int *st, u32 *c);
int BTL_CLIENT_StepStartWeather(BtlClient *client, int *st, u32 *c);
int BTL_CLIENT_StepEndWeather(BtlClient *client, int *st, u32 *c);
int BTL_CLIENT_StepUpdateMonGauge(BtlClient *client, int *st, u32 *c);
int BTL_CLIENT_StepPlayMonAnim(BtlClient *client, int *st, u32 *c);
int BTL_CLIENT_StepUpdateMonGaugeCopy(BtlClient *client, int *st, u32 *c);
int BTL_CLIENT_StepRotatePositions(BtlClient *client, int *st, u32 *c);
int BTL_CLIENT_StepRotatePositionsTwice(BtlClient *client, int *st, u32 *c);
int BTL_CLIENT_StepPlayEffectOnMon(BtlClient *client, int *state, unsigned int *q);
int BTL_CLIENT_StepPlayEffectOnMonFast(BtlClient *client, int *st, u32 *c);
int BTL_CLIENT_StepTransformMon(BtlClient *client, int *st, u32 *c);
int BTL_CLIENT_StepPlayHitEffect(BtlClient *client, int *b, u32 *c);
int BTL_CLIENT_StepChangeBgm(int a, int b, int *c);
int BTL_CLIENT_StepPlayViewSequence(BtlClient *client, int *state);
int BTL_CLIENT_StepAddEffortValues(BtlClient *client, int b, u32 *c);
int BTL_CLIENT_StepGiveExp(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_ForgetMoveSoundCallback(int n);
int BTL_CLIENT_StepLearnLevelUpMoves(BtlClient *client, int *state, void *mon);
int BTL_CLIENT_StepThrowBall(BtlClient *client, int *b, const u32 *c);
int BTL_CLIENT_StepShowBallBlocked(BtlClient *client, int *b, u32 *c);
int BTL_CLIENT_StepClearSidePosition(BtlClient *client, int *b, u32 *c);
int BTL_CLIENT_StepSetAbilityWithPopup(BtlClient *client, int *b, u32 *c);
int BTL_CLIENT_StepSwapAbilitiesWithPopup(BtlClient *client, int *b, u32 *c);
int BTL_CLIENT_StepClearIllusion(BtlClient *client, int *b, u32 *c);
int BTL_CLIENT_StepPlayEffectById(BtlClient *client, int *state, unsigned int *q);
int BTL_CLIENT_StepPlayMonSimpleEffect(BtlClient *client, int *b, u32 *c);
extern struct Unk021EFD70 data_021EFD70[];
extern struct T6 gEffortValueStatTable[];
extern struct SizeEntry gHandExRecordSizeTable[0x3B];
extern u8 d_021F3A88[];
extern const Entry_021CC768 gBtlClientCommandTable[15];
extern const u16 gBtlClientSupportItemKeys[4];
extern const struct Row gBtlClientAiHitKindRows[4];
extern const CodeEntry gServerCommandHandlers[];
extern Pair16 gWeatherEffects[5];
extern u16 gEffortValueParams[];
extern union DView gExpGainWork;
extern struct StateData g_021F3B64;
extern const u16 gCatchShakeMessages[];

BtlClient *BTL_CLIENT_Create(u8 *battleMain, u8 *sideSet, int netEnabled, int netSystem, u16 clientIndex, u16 slotTotal, u8 clientKind, int isCommBattle, int isReplay, BtlClientRng *rngInit, u16 heapId)
{
    BtlClient *client;
    u32 slot;
    int useNet, recordKey;
    client = func_02030734(heapId, 0x1b8, 1, (const char *)d_021F3A88, 0x209);
    useNet = 1;
    if (netEnabled == 0 || clientKind != 0)
        useNet = 0;
    client->clientId = clientIndex;
    client->heapId = heapId;
    client->kind = clientKind;
    client->netChannel = BTL_ADAPTER_Create(netSystem, (u8)clientIndex, useNet, heapId);
    client->sideData = BTL_SIDE_GetSlotOfClientThunk((char *)sideSet, clientIndex);
    client->main = battleMain;
    client->side = sideSet;
    client->slotCount = slotTotal;
    client->slotIndex = 0;
    client->clientIdCopy = clientIndex;
    client->windowMode = 0;
    client->view = 0;
    client->lastMonValue = 0;
    client->workBuffer = func_02030734(heapId, 0xbc0, 1, (const char *)d_021F3A88, 0x21a);
    client->tickFn = (BtlClientTickFn)BTL_CLIENT_StepMain;
    client->stepPhase = 0;
    client->requestParam = 0;
    client->flags.bit.requestSet = 0;
    client->requestId = 0;
    client->viewLocked = 0;
    client->pointCounter = 0;
    client->timeLimit = 0;
    client->timeElapsed = 0;
    client->limitReady = 0;
    client->flags.bit.resultPending = 0;
    client->flags.bit.commandIssued = 0;
    client->flags.bit.windowOpen = 0;
    client->flags.bit.windowDone = 0;
    *(u32 *)&client->battleField = BTL_MAIN_GetField(battleMain);
    client->isComm = isCommBattle;
    BTL_CLIENT_SET_Clear((u8 *)&client->cursor);
    func_021D3F04(client->commandQueue);
    func_021D3D9C((u8 *)client);
    client->rng = *rngInit;
    if (client->kind == 1 && isReplay == 0) {
        recordKey = BTL_MAIN_GetTrainerAiFlags(client->main, client->clientId);
        client->recorder = func_02187F00(client->main, BTL_MAIN_GetServerFlow(client->main), (u32)client->side, recordKey, client->heapId);
    } else {
        client->recorder = 0;
    }
    for (slot = 0; slot < 4; slot++)
        client->chosenSlots[slot] = 0;
    if (client->kind == 0 && BTL_MAIN_IsRecordingActive(client->main))
        client->timeLimitTimer = BTL_REC_CreateBuffer(heapId);
    else
        client->timeLimitTimer = 0;
    return client;
}














void BTL_CLIENT_Delete(BtlClient *client) {
 if(client->timeLimitTimer)BTL_REC_DeleteBuffer(client->timeLimitTimer);
 if(client->recorder)func_02188080(client->recorder);
 func_020307B0(client->workBuffer);
 BTL_ADAPTER_Delete(client->netChannel);
 func_020307B0(client);
}














void BTL_CLIENT_MarkCommandIssued(BtlClient *client) {*(u8 *)&client->flags|=2;}














u16 *BTL_CLIENT_ReadRecorderEntry(BtlClient *client, u32 *out) { if (client->timeLimitTimer) return BTL_REC_ReadEntry(client->timeLimitTimer,out); return 0; }














/*
 * Prototype: 021D3F48 stores only r1 low16; caller forwards full getter
 * result without truncation, so its extern argument is widened to u32.
 */
void BTL_CLIENT_AttachRemoteLink(BtlClient *client, void *a) { client->kind=2; client->remoteLink=a; func_021D3F48(client->commandQueue,BTL_REC_CountFlaggedRecords(a)); }














/*
 * Stores the second argument (a u32) into the field at #0x54.
 */
void BTL_CLIENT_SetView(BtlClient *client, u32 v) { *(u32 *)&client->view = v; }















void BTL_CLIENT_SetRequestParam(BtlClient *client, u32 v) {
    client->requestParam = v;
    *(u8 *)&client->flags |= 8;
}














/*
 * Reads the u32 field at #0x50 of the argument and returns it.
 */
u32 BTL_CLIENT_GetNetChannel(BtlClient *client) { return (u32)client->netChannel; }














/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: push {r3, lr}; ldr r1, [r0, #0x28]; blx r1; pop {r3, pc}.
 */
void BTL_CLIENT_RunTick(BtlClient *client) { client->tickFn(client); }














/*
 * Prototype: 021CDA0C stores its r1 payload unchanged at +0x28; caller
 * passes a callback address. Pointer replaces legacy u32 for that payload.
 */
void BTL_CLIENT_StartRemoteStep(BtlClient *client, u16 n) { BTL_REC_ResetReader(client->remoteLink); BTL_ADAPTER_ClearRecvHeader(client->netChannel); func_021D3F64(client->commandQueue,n); BTL_CLIENT_SetStepFn(client,(u32)BTL_CLIENT_StepRemote); }














void BTL_CLIENT_StartMainStep(BtlClient *client) { func_021D3F88(client->commandQueue); BTL_CLIENT_SetStepFn(client,(u32)BTL_CLIENT_StepMain); }















/* 021CD9C8  byte field 0x1a7 == 2 */
/*
 * 8 instructions, 16 bytes: ldr r1, pool_021CD9D8; ldrb r0, [r0, r1]; cmp r0, #2; bne loc_021CD9D4; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 BTL_CLIENT_IsRemote(BtlClient *client)
{
    return (client->kind == 2);
}














/*
 * Reads the u16 field at #0x22 of the argument and returns it.
 */
u16 BTL_CLIENT_GetQueuedCommandWord(BtlClient *client) { return *(u16 *)&client->commandQueue[10]; }















/* 021CD9E0  function-pointer slot 0x28 compared with 0x021CDC0D */
/*
 * 8 instructions, 16 bytes: ldr r1, [r0, #0x28]; ldr r0, pool_021CD9F0; cmp r1, r0; bne loc_021CD9EC; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 BTL_CLIENT_IsMainStepActive(BtlClient *client)
{
    return ((unsigned int)client->tickFn == 0x021CDC0D);
}














/*
 * u8 step preserves the low-byte result for every incoming word; no
 * signed int addition overflow. Wide step emits an extra narrowing pair.
 */
void BTL_CLIENT_AddPoints(BtlClient *client, u8 n) { client->pointCounter+=n; if(client->pointCounter>14) client->pointCounter=14; }













void BTL_CLIENT_SetStepFn(BtlClient *client, u32 v)
{
    *(u32 *)&client->tickFn = v;
    client->stepPhase = 0;
}













int BTL_CLIENT_StepMain(BtlClient *client)
{
    u32 id, *pair, x, y;
    int flag;
    u16 n;
    func_021D3FDC((u8 *)client,(struct Qd *)client->commandQueue);
    switch (client->stepPhase) {
    case 0:
        id = BTL_ADAPTER_GetRecvCommand(client->netChannel);
        if (client->kind == 2 && (client->flags.bit.windowOpen || client->flags.bit.windowDone) && !id) return 0;
        BTL_CLIENT_ResetSendWord(client);
        if (id == 9) {
            BTL_ADAPTER_GetRecvData((int)client->netChannel,&pair);
            x = pair[0]; y = pair[1];
            client->cursor.y = y;
            client->cursor.x = x;
            client->stepState = 0;
            client->stepPhase = 3;
        } else if (id) {
            client->stepFn = BTL_CLIENT_FindCommandStepFn(client,id,&flag);
            if (flag) {
                if (!func_021D3FAC(client->commandQueue)) { client->stepPhase = 6; break; }
            } else func_021D3FC4(client->commandQueue);
            if (client->stepFn) {
                client->stepPhase = 1;
                client->stepState = 0;
            } else {
                client->stepState = 0;
                client->stepPhase = 2;
            }
        } else if (client->flags.bit.commandIssued) return 1;
        break;
    case 1:
        if ((client->stepFn)(client,&client->stepState)) {
            if (client->flags.bit.commandIssued) return 1;
            if (func_021D3F4C(client->commandQueue)) client->stepPhase = 4;
            else client->stepPhase = 2;
        }
        break;
    case 2:
        if (BTL_ADAPTER_SetRecvTarget(client->netChannel,client->sendData,client->sendSize)) client->stepPhase = 0;
        if (client->flags.bit.commandIssued) return 1;
        break;
    case 3:
        if (BTL_ADAPTER_SetRecvTarget(client->netChannel,client->sendData,client->sendSize)) client->stepPhase = 7;
        if (client->flags.bit.commandIssued) return 1;
        break;
    case 6:
        if (func_021D3F4C(client->commandQueue)) client->stepPhase = 4;
        break;
    case 4:
        if (func_021D3F60(client->commandQueue) == 1) client->stepPhase = 7;
        else {
            if (client->view) { GFL_USE_SetPlayersAudible(1,62); PM_VOICE_ResetMasterVolume(); }
            client->stepPhase = 5;
        }
        break;
    case 5:
        if (!GFL_USE_IsBgmFading()) {
            n = func_021D3FA8(client->commandQueue);
            GFL_USE_SetPlayersAudible(0,1);
            BTL_MAIN_RestartBattle(client->main,n);
            PM_VOICE_SetMasterVolume(0);
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}













/*
 * extent: The store-and-return follower at 0x021CDD34 is included here;
 * the larger lookup follower at 0x021CDD50 has its own verified shard.
 */
int BTL_CLIENT_StepRemote(BtlClient *client)
{
    u32 id;
    u16 n;
    int zero;
    func_021D3FDC((u8 *)client,(struct Qd *)client->commandQueue);
    switch (client->stepPhase) {
    case 0:
        client->stepPhase = 1;
    case 1:
        if (!func_021D3F98(client->commandQueue)) {
            id = BTL_ADAPTER_GetRecvCommand(client->netChannel);
            if (id) {
                zero = 0;
                client->stepFn = BTL_CLIENT_FindCommandStepFn(client,id,0);
                if (client->stepFn) {
                    client->stepPhase = 2;
                    client->stepState = zero;
                }
                else {
                    BTL_CLIENT_ResetSendWord(client);
                    client->stepPhase = 3;
                    client->stepState = zero;
                }
            }
        } else {
            if (client->view) {
                GFL_USE_SetPlayersAudible(1,1);
                func_021EAE24(client->view);
                GFL_USE_FadeInBgmFull(30);
                func_021F88BC(0);
                PM_VOICE_ResetMasterVolume();
            }
            client->stepPhase = 4;
        }
        break;
    case 2:
        if ((client->stepFn)(client,&client->stepState)) {
            client->stepPhase = 3;
            client->stepState = 0;
            if (func_021F8678()) func_021F88BC(1);
        }
        break;
    case 3:
        if (BTL_ADAPTER_SetRecvTarget(client->netChannel,client->sendData,client->sendSize)) client->stepPhase = 1;
        break;
    case 4:
        if (client->view) {
            if (func_021EAE34(client->view)) {
                if (!GFL_USE_IsBgmFading()) {
                    n = (int)func_021D3FA8(client->commandQueue);
                    func_021EAE74(client->view,n,n);
                    BTL_MAIN_StartClientMainSteps(client->main);
                }
            }
        }
        break;
    case 5: return 1;
    }
    return 0;
}













void BTL_CLIENT_ResetSendWord(BtlClient *client)
{
    client->sendFlag = 0;
    client->sendData = (u8 *)&client->sendFlag;
    client->sendSize = 4;
}













BtlClientStepFn BTL_CLIENT_FindCommandStepFn(BtlClient *client, u32 id, int *outFlag)
{
    u32 entryIndex;
    for (entryIndex=0; entryIndex<15; entryIndex++) {
        if (gBtlClientCommandTable[entryIndex].id == id) {
            if (outFlag) *outFlag = gBtlClientCommandTable[entryIndex].flag;
            return gBtlClientCommandTable[entryIndex].callbacks[client->kind];
        }
    }
    return 0;
}














void BTL_CLIENT_GetCursor(BtlClient *client, int *outCursor)
{
    *(BtlClientPoint *)outCursor = client->cursor;
}













/*
 * unresolved THM_CALL at +0x14. Region hint ov094 does not supply a witness.
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021F8524 is an ov094 Thumb wrapper (pool-based tail), other overlay, not filed here (ov094 belongs to another owner). Integrator: seed label.
 */
int BTL_CLIENT_IsWindowWaiting(BtlClient *client) { if(client->kind!=2) { if(client->timeElapsed) return func_021F8524(0); return 0; } return client->flags.bit.windowOpen; }













u32 BTL_CLIENT_IsWindowDone(BtlClient *client) { return client->flags.bit.windowDone; }













/*
 * Levers (from the DIFF note): case 0 is the call written in each arm, `!= 4` arm first
 * (a-boolean-argument-is-a-call-in-each-arm.md; a flag value hoists `movs r1,#1`);
 * func_021F84E8 takes two arguments as its own file says, the second being the 0xe4
 * halfword still live in r1 from the || test; func_021D3FA8 is declared u32 here because
 * the original narrows its result before the u16 parameter of func_021EAEA8.
 */
int BTL_CLIENT_StepOpenBattleWindow(BtlClient *client, int *state)
{
    switch (*state) {
    case 0:
        if ((int)BTL_MAIN_GetCompetitor(client->main) != 4) {
            func_021E90A0(client->view, 0);
        } else {
            func_021E90A0(client->view, 1);
        }
        *state = *state + 1;
        break;
    case 1:
        if (func_021E90D0(client->view) == 0) {
            break;
        }
        client->timeLimit = BTL_MAIN_GetLimitTimeCommand(client->main);
        client->timeElapsed = BTL_MAIN_GetLimitTimeGame(client->main);
        if (client->timeLimit != 0 || client->timeElapsed != 0) {
            func_021F84E8(client->timeElapsed, client->timeLimit);
            if (client->timeElapsed != 0) {
                func_021F8504(0, 1, 1);
            }
        }
        BTL_CLIENT_StoreMonParam(client);
        if (BTL_CLIENT_IsMainStepActive(client) != 0) {
            func_021EAEA8(client->view, (u16)((u32)func_021D3FA8(client->commandQueue)));
        }
        return 1;
    }
    return 0;
}













int BTL_CLIENT_PollWindowStep(BtlClient *client, int b)
{
    int r4;
    if (client->view != 0) {
        r4 = BTL_CLIENT_StepOpenBattleWindow(client, (int *)b);
        if (r4 != 0) {
            if (BTL_REC_ReadSkipFlag((int)client->remoteLink, client->clientId) != 0)
                func_021D3F54(client->commandQueue);
        }
        return r4;
    }
    BTL_REC_ReadSkipFlag((int)client->remoteLink, client->clientId);
    return 1;
}












void BTL_CLIENT_StoreMonParam(BtlClient *client) { void *a; a=BTL_CLIENT_GetLeadPartyMon(client); if(a) client->lastMonValue=func_021D59B4(a,13); }












u32 BTL_CLIENT_HasMonParamDropped(BtlClient *client) { void *a; u32 now,old; a=BTL_CLIENT_GetLeadPartyMon(client); if(a) { now=func_021D59B4(a,13); old=client->lastMonValue; if(now>=old) return 0; return _u32_div_f((old-now)*100,now); } return 0; }











/*
 * Prototype: original narrows getter result to u8 before 021B9920;
 * caller extern has u8 second argument; named u8 local keeps shift in r0.
 */
void *BTL_CLIENT_GetLeadPartyMon(BtlClient *client) { u8 side; if(BTL_MAIN_GetRule(client->main)==0 && BTL_MAIN_GetCommPos(client->main)==0) { side=BTL_MAIN_GetOpponentClient(client->main,client->clientId,0); return BTL_SIDE_GetClientPoke(client->side,side,0); } return 0; }












int BTL_CLIENT_StepWindowModeSelect(BtlClient *client, int *state)
{
    u8 chosenMode;

    switch (*state) {
    case 0:
        func_021EAA00(client->view, client->windowMode);
        BTL_CLIENT_StartTimeLimit(client);
        *state = *state + 1;
        break;
    case 1:
        if (BTL_CLIENT_PollTimeLimitReady(client) != 0) {
            func_021EAA5C(client->view);
            *state = 2;
        } else if (func_021EAA34(client->view, &chosenMode) != 0) {
            client->windowMode = chosenMode;
            *state = 3;
        }
        break;
    case 2:
        client->windowMode = BTL_CLIENT_PickWindowMode(client->windowMode);
        *state = *state + 1;
        break;
    case 3:
        BTL_CLIENT_StopTimeLimit(client);
        *state = *state + 1;
        break;
    case 4:
        client->sendData = &client->windowMode;
        client->sendSize = 1;
        return 1;
    }
    return 0;
}










/*
 * Lever: each switch arm writes its own `mode = (u8)t;` before `break`. The copies are
 * cross-jumped into `b join` after branch threading, so each arm's `blo` keeps landing on
 * its own hop (a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.md).
 * One shared `mode = (u8)t;` after the switch threads the hops away (4 bytes short).
 */
u32 BTL_CLIENT_PickWindowMode(u32 mode)
{
    u32 v;
    int t;

    v = (u32)(((u64)func_0203F0A8() * 100) >> 32);
    if (mode == 0) {
        if (v < 0x1e) {
            mode = 3;
        } else if (v < 0x3c) {
            mode = 2;
        } else {
            mode = 1;
        }
    } else {
        switch (mode) {
        case 1:
        default:
            t = (v < 0x32) ? 2 : 3;
            mode = (u8)t;
            break;
        case 3:
            t = (v < 0x28) ? 2 : 1;
            mode = (u8)t;
            break;
        case 2:
            t = (v < 0x28) ? 3 : 1;
            mode = (u8)t;
            break;
        }
    }
    return mode;
}









int BTL_CLIENT_ReturnTrue(void)
{
    return 1;
}









void BTL_CLIENT_StartWindowModeSend(BtlClient *client) { client->windowMode=BTL_CLIENT_PickWindowMode(client->windowMode); client->sendData=&client->windowMode; client->sendSize=1; }










void BTL_CLIENT_StartTimeLimit(BtlClient *client) { if(client->timeLimit) { func_021F8504(1,1,1); client->limitReady=0; } }










/*
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Same blocker as 021CDDA0: ov094 0x021F8524 needs a label/witness.
 */
int BTL_CLIENT_PollTimeLimitReady(BtlClient *client) { if(client->timeLimit!=0) { if(client->limitReady==0) { if(func_021F8524(1)) client->limitReady=1; } return client->limitReady; } return 0; }










int BTL_CLIENT_PollTimeLimitAndSetSub(BtlClient *client, void *q) { if(BTL_CLIENT_PollTimeLimitReady(client)) { if(q) BTL_CLIENT_SetSubFn(client,q); return 1; } return 0; }










void BTL_CLIENT_StopTimeLimit(BtlClient *client) { if(client->timeLimit!=0) func_021F8504(1,0,0); }











void BTL_CLIENT_BuildActionPromptMessage(BtlClient *client, u8 *mon, u8 *outMessage)
{
    if (BTL_MAIN_GetRule(client->main) != 3) {
        func_021EAF18((struct L *)outMessage, 1, 0x45);
        func_021EAF50((struct L *)outMessage, BTL_POKEPARAM_GetPokeId(mon));
        func_021EAF78(outMessage, 0);
    } else {
        func_021EAF18((struct L *)outMessage, 1, 0x46);
        func_021EAF50((struct L *)outMessage, client->clientId);
        func_021EAF78(outMessage, 0);
    }
}










void BTL_CLIENT_SetSubFn(BtlClient *client, void *q) { client->subFn=q; client->subState=0; }











/* 021CE160  the receiver pointer is also the FIRST argument: the image keeps
 * r0 = p, puts p+0xd4 in r1 and the slot from [p+0xd0] in r2. */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: push {r3, lr}; adds r2, r0, #0; adds r2, #0xd0; adds r1, r0, #0; ldr r2, [r2]; adds r1, #0xd4; blx r2; pop {r3, pc}.
 */
u32 BTL_CLIENT_RunSubFn(BtlClient *client)
{
    return client->subFn(client, &client->subState);
}










u32 BTL_CLIENT_StepStartActionSelection(BtlClient *client, s32 *state)
{
    switch (*state) {
    case 0:
        BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_InitActionSelection));
        BTL_CLIENT_StartTimeLimit(client);
        *state = *state + 1;
        break;
    case 1:
        BTL_CLIENT_PollTimeLimitReady(client);
        if (BTL_CLIENT_RunSubFn(client) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}









int BTL_CLIENT_StepPlaybackRecordedAction(BtlClient *client, int *state)
{
    u8 wordCount;
    u8 skipFlag;
    u32 *record;
    switch (*state) {
    case 0:
        if (client->flags.bit.windowDone) {
            BTL_CLIENT_ResetActionCursor(client);
            return 1;
        }
        record = BTL_REC_ReadRecord(client->remoteLink,client->clientId,&wordCount,&skipFlag);
        if (skipFlag) func_021D3F54(client->commandQueue);
        *(u32 * *)&client->sendData = record;
        client->sendSize = wordCount * 4;
        if (((Command *)record)->kind == 8) {
            func_021D3FD0(client->commandQueue);
            if (client->view) {
                func_021EAF18((struct L *)&client->messageA,1,0xb7);
                func_021EA614(client->view,&client->messageA);
                (*state)++;
            } else {
                BTL_CLIENT_ResetActionCursor(client);
                *(u8 *)&client->flags |= 0x10;
                return 1;
            }
        } else if (((Command *)record)->kind == 9) {
            *(u8 *)&client->flags |= 0x20;
            func_021D3FD0(client->commandQueue);
            if (client->view) {
                func_021EAF18((struct L *)&client->messageA,1,0xb8);
                func_021EA614(client->view,&client->messageA);
                *state += 2;
            } else {
                BTL_CLIENT_ResetActionCursor(client);
                return 1;
            }
        } else return 1;
        break;
    case 1:
        if (func_021EA710(client->view)) {
            BTL_CLIENT_ResetActionCursor(client);
            *(u8 *)&client->flags |= 0x10;
            return 1;
        }
        break;
    case 2:
        if (func_021EA710(client->view)) {
            BTL_CLIENT_ResetActionCursor(client);
            return 1;
        }
        break;
    }
    return 0;
}









void BTL_CLIENT_ResetActionCursor(BtlClient *client) { client->actionCursor=(u8 *)client->actions; BTL_CALC_ActionSetNone(client->actions); client->sendData=client->actionCursor; client->sendSize=4; }










u32 BTL_CLIENT_InitActionSelection(BtlClient *client)
{
    u32 slot = 0;
    u32 mon;
    client->slotIndex = 0;
    ((s8 *)client)[0x11e] = -1;
    client->slotsDone = 0;
    client->flags.bit.moveSelected = 0;
    BTL_CLIENT_BuildSlotChoices(client, 0, client->slotCount, client->slotChoices, client->choiceFlags);
    BTL_CLIENT_ClearSlotFlags(client);
    BTL_CLIENT_ClearSlotLinkWords(client);
    for (slot = 0; slot < 3; slot++) {
        BTL_CALC_ActionSetNone((u32 *)((u8 *)client->actions + slot * 4));
    }
    for (slot = 0; slot < client->slotCount; slot++) {
        mon = (u32)BTL_SIDE_GetClientPokeParam((char *)(client->side), client->clientId, (u8)slot);
        if (BTL_CLIENT_IsActionForced((u8 *)client, (void *)mon, 0) == 0) {
            client->slotsDone = slot;
            break;
        }
    }
    BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectAction));
    return 0;
}









void BTL_CLIENT_ShowMessage(BtlClient *client, void *q) { func_021EA614(client->view,q); client->redrawRequest=1; }









int BTL_CLIENT_StepAutoSelectActions(BtlClient *client, int *state)
{
    u8 usableMask[4];
    u32 moveIndex;
    u32 moveId;
    switch (*state) {
    case 0:
        func_021EAE44(client->view);
        (*state)++;
        break;
    case 1:
        if (func_021EAE54(client->view)) {
            for (; client->slotIndex < client->slotCount; client->slotIndex++) {
                client->activeMon = BTL_SIDE_GetClientPokeParam(client->side,client->clientId,client->slotIndex);
                client->actionCursor = (u8 *)client->actions+client->slotIndex*4;
                BTL_CALC_ActionSetNone((u32 *)(client->actionCursor));
                if (!BTL_CLIENT_IsActionForced((u8 *)client,client->activeMon,client->actionCursor)) {
                    moveIndex = BTL_CLIENT_BuildUsableMoveMask(client,client->activeMon,usableMask);
                    if (moveIndex < 4) {
                        moveId = BTL_POKEPARAM_GetMoveId(client->activeMon,moveIndex);
                        BTL_ACTION_SetFight((struct Unk021D82D0 *)(client->actionCursor),moveId,BTL_CALC_PeekMoveTarget(client->main,client->side,client->activeMon,moveId,client->actionResult));
                    } else BTL_CLIENT_SetStruggleAction((struct Unk021D82D0 *)(client->actionCursor),client,client->activeMon);
                }
            }
            (*state)++;
        }
        break;
    case 2:
        client->sendData = (u8 *)client->actions;
        client->sendSize = client->slotCount*4;
        BTL_CLIENT_SetSubFn(client,(void *)((u32)BTL_CLIENT_StepSendActions));
        break;
    }
    return 0;
}







/*
 * note 2026-10-05 (wave P26 lane 2): byte-identical to the original except that two call
 * relocations have no witness in the current index: func_021E979C and func_021E9954. Both
 * leaves are now filed (src/matched/ov/ov093_func_021E979C.c, ov093_func_021E9954.c, EXACT);
 * the verdict becomes EXACT once the integrator regenerates the index. The original extent is
 * 772 B: 756 B of C plus the 16 B linker veneer at 021CE7C4 (not C, resolved as a veneer witness).
 * Two changes closed the 253 B residue of the older draft: (1) no shared increment label and
 * no goto: each arm writes ++*st; break; so the compiler builds the single shared state store
 * and one epilogue (756 to 748 B, branch layout); (2) the countdown loop reads the index byte
 * through a struct field (struct L at 0x11D and 0x1A6) instead of a count pointer local, so
 * mwcc hoists three separate address computations (count pointer in r5, a copy in r6, a
 * stack copy for the loop test) as in the original.
 * Not tried again from the older note: unsigned-long state pointer, full-word countdown.
 * proof: full unsigned state dispatch <=8; byte selectors0..255; countdown assigned before reads; byte/state additions wrap at their original widths; fixed veneer is omitted from C.
 */
int BTL_CLIENT_StepSelectAction(BtlClient *client, u32 *state)
{
    u32 viewResult;
    switch (*state) {
    case 0:
        (client->activeMon) = BTL_SIDE_GetClientPokeParam((client->side), client->clientId, client->slotIndex);
        (client->actionCursor) = (u8 *)client->actions + client->slotIndex * 4;
        client->extraActionCount = 0;
        BTL_CALC_ActionSetNone(((void *)client->actionCursor));
        if (BTL_CLIENT_IsActionForced((u8 *)client, (client->activeMon), (client->actionCursor))) {
            BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
            break;
        }
        if (BTL_CLIENT_FindSupportItem(client, &client->receivedCode) == 1) {
            BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepShowSupportItemMessage));
            break;
        }
        ++*state; break;
    case 1:
        if (client->prevSlotIndex != client->slotIndex || client->redrawRequest) {
            BTL_CLIENT_BuildActionPromptMessage(client, (client->activeMon), (u8 *)&client->messageA);
            func_021EA65C((client->view), &client->messageA);
            client->redrawRequest = 0;
            client->prevSlotIndex = client->slotIndex;
            ++*state; break;
        }
        *state += 2U;
        break;
    case 2:
        if (!func_021EA710((client->view))) return 0;
        ++*state;
        /* falls through */
    case 3:
        func_021E9760((client->view), (client->activeMon), client->slotIndex > client->slotsDone, (int)(client->actionCursor));
        ++*state; break;
    case 4:
        if (BTL_CLIENT_PollTimeLimitAndSetSub(client, (void *)((u32)BTL_CLIENT_StepAutoSelectActions))) {
            func_021E979C((client->view));
            return 0;
        }
        viewResult = func_021E97A4((client->view));
        switch (viewResult) {
        case 3:
            if (BTL_POKEPARAM_HasSick((client->activeMon), 0x21)) {
                func_021E9964(((u32)client->view));
                *state = 6;
            } else {
                BTL_CLIENT_SetSlotFlag(client, client->slotIndex, 0);
                BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectSwitchTarget));
            }
            break;
        case 1:
            BTL_CLIENT_SetSlotFlag(client, client->slotIndex, 0);
            BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectMove));
            break;
        case 2:
            if (BTL_POKEPARAM_HasSick((client->activeMon), 0x21)) *state = 6;
            else if (client->isComm == 1 && !BTL_MAIN_IsRecordEnabledInComm((client->main))) {
                func_021E9964(((u32)client->view));
                *state = 5;
            } else BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectItem));
            break;
        case 4:
            if (client->slotIndex == client->slotsDone) {
                if (BTL_POKEPARAM_HasSick((client->activeMon), 0x21) && BTL_MAIN_GetCompetitorKind((client->main)) != 2) *state = 6;
                else {
                    BTL_CLIENT_SetSlotFlag(client, client->slotIndex, 0);
                    BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectRun));
                }
                break;
            }
            if (client->slotIndex == 0) break;
            do {
                --((struct L *)client)->idx;
                if (!BTL_CLIENT_IsActionForced((u8 *)client, BTL_SIDE_GetClientPokeParam((client->side), ((struct L *)client)->sel, ((struct L *)client)->idx), 0)) {
                    client->pointCounter += BTL_CLIENT_GetSlotFlag(client, client->slotIndex);
                    if (BTL_CALC_ActionGetKind((Action *)((u8 *)client->actions + client->slotIndex * 4)) == 3)
                        func_0689CB08(client->choiceFlags);
                    if (BTL_CALC_ActionGetKind((Action *)((u8 *)client->actions + client->slotIndex * 4)) == 2)
                        BTL_CLIENT_FlushSlotLinkWord(client, client->slotIndex);
                    BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectAction));
                    return 0;
                }
            } while (((struct L *)client)->idx != 0);
            break;
        }
        break;
    case 5:
        if (func_021E9974(((u32)client->view))) *state = 3;
        break;
    case 6:
        func_021E9954((client->view));
        ++*state; break;
    case 7:
        if (!func_021E9974(((u32)client->view))) break;
        func_021EAF18((struct L *)&client->messageA, 1, 0xC5);
        func_021EAF50((struct L *)&client->messageA, BTL_POKEPARAM_GetPokeId((client->activeMon)));
        BTL_CLIENT_ShowMessage(client, (u8 *)&client->messageA);
        ++*state; break;
    case 8:
        if (func_021EA710((client->view))) *state = 1;
        break;
    }
    return 0;
}










u32 BTL_CLIENT_StepShowSupportItemMessage(BtlClient *client, int *state)
{
    u32 opponentClientId;
    u16 trainerId;
    u32 zero;
    switch (*state) {
    case 0:
        zero = 0;
        opponentClientId = BTL_MAIN_GetOwnOpponentClient(client->main, 0);
        trainerId = BTL_MAIN_GetTrainerId(client->main, opponentClientId);
        func_021F7F58(BTL_MAIN_GetTrainerType(client->main, opponentClientId), 9, 0, 0, zero);
        func_021F7998(0x270);
        func_021EA6B0(client->view, trainerId, client->receivedCode);
        if ((u16)(client->receivedCode + 0xffed) <= 1 &&
            BTL_CALC_IsGymLeaderTrainer(BTL_MAIN_GetTrainerType(client->main, opponentClientId)) && !client->flags.bit.resultPending) {
            func_021F87EC(0x47b);
            if (!func_021F8774()) {
                GFL_USE_FadeOutBgm(8);
                *state = 1;
                break;
            }
        }
        *state = 2;
        break;
    case 1:
        if (!GFL_USE_IsBgmFading()) {
            GFL_USE_CancelChangeAndPlayBgm(0x47b, 0xffff);
            *(u8 *)&client->flags = (*(u8 *)&client->flags & ~1) | 1;
            ++*state;
        }
        break;
    case 2:
        if (!func_021F7EB4() && func_021EA710(client->view)) {
            func_021F7998(0x271);
            ++*state;
        }
        break;
    case 3:
        if (!func_021F7EB4()) BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectAction));
        break;
    }
    return 0;
}









static inline void initOffset(Off *value)
{
    *value = OFFSET;
    *value -= 0x88;
}









/*
 * lever: Six ordinary int offsets each receive 0x19a then 0x112;
 * a cached row pointer preserves their distinct stack homes and r5 base.
 * Reverse declarations and a full-word k local restore the spill order.
 * note 2026-10-05 (wave D9r lane 131): removed the 6 dead first assignments
 * (`invalid=0x19a;` before `invalid=0x112;`; `ok3=0x19a;` before
 * `ok3=0x112;` and 4 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
u32 BTL_CLIENT_FindSupportItem(BtlClient *client, u16 *outItemKey)
{
    u32 partyEntry;
    int result;
    u32 count;
    u32 trainerId;
    u32 itemKey;
    u32 opponentClientId, i;
    int hpNow, hpNowPair;
    u8 *leadMon;
    u8 *flagRow;
    int triedFlagOffset,appliedFlagOffsetHalfHp,appliedFlagOffsetNotFull,appliedFlagOffsetPair,appliedFlagOffsetPairHalfHp,unusableFlagOffset;
    if ((u32)BTL_MAIN_GetCompetitor(client->main) != 1) goto fail;
    opponentClientId = BTL_MAIN_GetOwnOpponentClient(client->main,0);
    trainerId = BTL_MAIN_GetTrainerId(client->main,opponentClientId);
    if (!trainerId) goto fail;
    partyEntry = (u32)BTL_SIDE_GetSlotOfClient(client->side,opponentClientId);
    leadMon = BTL_SIDE_GetClientPokeParam(client->side,opponentClientId,(u8)0);
    if (BTL_POKEPARAM_IsFainted(leadMon)) {
        count = BTL_MAIN_GetPositionsPerClientThunk(client->main,opponentClientId);
        for (i=1;i<count;i++) {
            leadMon = BTL_SIDE_GetClientPokeParam(client->side,opponentClientId,(u8)i);
            if (!BTL_POKEPARAM_IsFainted(leadMon)) break;
        }
    }
    result = -1;
    unusableFlagOffset=0x112;
    appliedFlagOffsetPairHalfHp=0x112;
    appliedFlagOffsetPair=0x112;
    appliedFlagOffsetNotFull=0x112;
    appliedFlagOffsetHalfHp=0x112;
    triedFlagOffset=0x112;
    for (i=0;i<4;i++) {
        flagRow = (u8 *)client + i;
        if (!flagRow[triedFlagOffset]) {
            itemKey = gBtlClientSupportItemKeys[i];
            if (func_0202A298(trainerId,itemKey,client->heapId)) {
                switch (itemKey - 0x11) {
                case 1:
                    hpNow = func_021D59B4(leadMon,13);
                    if ((u32)hpNow <= BTL_CALC_DivideMaxHp(leadMon,2)) { result = i; flagRow[appliedFlagOffsetHalfHp] = 1; }
                    break;
                case 0:
                    if (!BTL_POKEPARAM_IsHpFull(leadMon)) { result = i; flagRow[appliedFlagOffsetNotFull] = 1; }
                    break;
                case 2:
                    if (BTL_SLOT_GetCount((void *)partyEntry) > 1 && BTL_SLOT_CountLiving((u8 *)partyEntry) == 1) { result = i; flagRow[appliedFlagOffsetPair] = 1; }
                    break;
                case 3:
                    if (BTL_SLOT_GetCount((void *)partyEntry) > 1 && BTL_SLOT_CountLiving((u8 *)partyEntry) == 1) {
                        hpNowPair = func_021D59B4(leadMon,13);
                        if ((u32)hpNowPair <= BTL_CALC_DivideMaxHp(leadMon,2)) { result = i; flagRow[appliedFlagOffsetPairHalfHp] = 1; }
                    }
                    break;
                }
            } else flagRow[unusableFlagOffset] = 1;
        }
    }
    if (result >= 0) { *outItemKey = gBtlClientSupportItemKeys[result]; return 1; }
fail:
    return 0;
}









/*
 * witnesses: four ov093 blocker leaves 021E98AC, 021E98B4,
 * 021D7EF0, 021E9920 filed and individually shard-verified first.
 * lever: packed unsigned bitfields plus narrow caller extern CF5B0 move;
 * record declared before sub settles r6/r7 allocation (one variant).
 * interface: CF5B0 own source takes u32 move, but original narrows id at
 * 021CEBC6/021CEBCC; u16 extern preserves observed caller truncation.
 * CE3B4 ignores r1 but caller explicitly supplies p+0x58, retained here.
 * semantics: word bitfields use unsigned shifts; all dynamic address adds
 * and scaling are u32 modulo 2^32, without assuming selector/index bounds.
 * Byte increment is promoted in 0..255 then narrowed; all locals initialized
 * on each path to a use. The branch to state 4 has no uninitialized outputs.
 */
int BTL_CLIENT_StepSelectMove(BtlClient *client, u32 *state)
{
    void *mon;
    u32 monSlot, actionKind;
    u32 *action;
    u8 rotationSub;
    switch (*state) {
    case 0:
        if (BTL_MAIN_GetRule(client->main) != 3) {
            if (BTL_CLIENT_SetStruggleIfNoMoves(client, client->activeMon, (u32)client->actionCursor))
                BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
            else *state = 1;
        } else {
            BTL_CLIENT_BuildMoveUsableTable(client, (Ent_021CECB4 *)client->recvEntry);
            *state = 2;
        }
        break;
    case 1:
        func_021E97BC(client->view, (u8 *)(client->activeMon), (u32)client->actionCursor);
        *state = 3;
        break;
    case 2:
        func_021E9808(client->view, (u32 *)client->recvEntry, (int)client->actionCursor);
        *state = 3;
        break;
    case 3:
        if (BTL_CLIENT_PollTimeLimitAndSetSub(client, (void *)((u32)BTL_CLIENT_StepAutoSelectActions))) {
            func_021E98AC(client->view);
            return 0;
        }
        if (func_021E98B4(client->view)) {
            actionKind = BTL_CALC_ActionGetKind((Action *)client->actionCursor);
            if (actionKind == 0) BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectAction));
            else if (actionKind == 5) BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
            else {
                mon = client->activeMon;
                action = (u32 *)client->actionCursor;
                rotationSub = 0;
                monSlot = client->slotIndex;
                if (BTL_MAIN_GetRule(client->main) == 3) {
                    rotationSub = (u8)((Record_td *)&client->recordKey)->sub;
                    monSlot = BTL_SLOT_GetRotateSrcIndex(rotationSub);
                    mon = *(void **)((u32)client + monSlot * 8U + 0xa4U);
                }
                if (func_021D832C((struct Unk021D82FC *)action)) {
                    client->highlightSlot = monSlot;
                    client->highlightKind = BTL_POKEPARAM_FindMoveSlot(mon, (u16)((Record_td *)action)->id);
                    if (client->highlightKind != 4) {
                        BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepMoveHighlight));
                        return 0;
                    }
                }
                if (BTL_CLIENT_IsMoveSelectionBlocked(client, mon, (u16)((Record_td *)action)->id, (u8 *)&client->messageA)) {
                    func_021EAF78((u8 *)&client->messageA, 0xff);
                    BTL_CLIENT_ShowMessage(client, (u8 *)&client->messageA);
                    *state = 7;
                } else {
                    if (BTL_MAIN_GetRule(client->main) == 3 && rotationSub != 0 && rotationSub != 1 && !BTL_POKEPARAM_IsFainted(mon)) {
                        actionKind = BTL_ACTION_GetFightMove((Action *)&client->actionKey);
                        action = (u32 *)client->actionCursor;
                        *(u32 *)&client->actionCursor = (u32)action + 4U;
                        BTL_ACTION_SetRotate(action, rotationSub);
                        BTL_ACTION_SetFight((void *)client->actionCursor, actionKind, 6);
                        ++client->extraActionCount;
                    }
                    *state = 4;
                }
            }
        }
        break;
    case 4:
        if (BTL_CALC_IsMultiFighterRule(BTL_MAIN_GetRule(client->main))) *state = 5;
        else BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
        break;
    case 5:
        func_021E98BC(client->view, (u8 *)(client->activeMon), (u32)client->actionCursor);
        *state = 6;
        break;
    case 6:
        if (BTL_CLIENT_PollTimeLimitAndSetSub(client, (void *)((u32)BTL_CLIENT_StepAutoSelectActions))) {
            func_021E9920(client->view);
            return 0;
        }
        actionKind = func_021E98E8(client->view);
        if (actionKind == 1) BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
        else if (actionKind == 2) *state = 1;
        break;
    case 7:
        if (func_021EA710(client->view)) {
            func_021E9858(client->view);
            *state = 3;
        }
        break;
    }
    return 0;
}








void BTL_CLIENT_BuildMoveUsableTable(BtlClient *client, Ent_021CECB4 *out)
{
    u32 memberIndex;
    u32 moveSlot;
    u8 *mon;
    u32 moveCount;
    u32 moveIndex;
    Ent_021CECB4 *entry;
    for (memberIndex = 0; memberIndex < 3; memberIndex++) {
        mon = BTL_SLOT_GetPokeParam(client->sideData, (u8)memberIndex);
        entry = out + memberIndex;
        entry->q = mon;
        for (moveSlot = 0; moveSlot < 4; moveSlot++) {
            entry->f[moveSlot] = 0;
        }
        if (BTL_POKEPARAM_IsFainted(mon) == 0) {
            moveCount = BTL_POKEPARAM_GetMoveCount((struct QG *)mon);
            for (moveIndex = 0; moveIndex < moveCount; moveIndex++) {
                if (BTL_POKEPARAM_GetMovePPChecked((struct UtilWork *)mon, (u8)moveIndex) == 0 || BTL_CLIENT_IsMoveSelectionBlocked(client, mon, (u32)BTL_POKEPARAM_GetMoveId(mon, (u8)moveIndex), 0) != 0) {
                    entry->f[moveIndex] = 0;
                } else {
                    entry->f[moveIndex] = 1;
                }
            }
        }
    }
}








u32 BTL_CLIENT_StepMoveHighlight(BtlClient *client, s32 *st)
{
    u32 zero;
    switch (*st) {
    case 0:
        func_021E9CE0((u8 *)(client->view), client->highlightSlot, client->highlightKind);
        *st = *st + 1;
        break;
    case 1:
        zero = 0;
        if (BTL_CLIENT_PollTimeLimitAndSetSub(client, 0) != 0) {
            func_021E9B14((unsigned int *)(client->view));
            *st = 2;
            return zero;
        }
        if (func_021E9B20((u8 *)(client->view)) != 0) {
            BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectMove));
        }
        break;
    case 2:
        if (func_021E9B20((u8 *)(client->view)) != 0) {
            BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepAutoSelectActions));
        }
        break;
    }
    return 0;
}








u32 BTL_CLIENT_StepSelectSwitchTarget(BtlClient *client, int *st)
{
    u8 trapperPokeId;
    u16 trapperAbility;
    u32 canCancel;
    u8 chosenMember;
    switch (*st) {
    case 0:
        canCancel = 0;
        if ((u8)BTL_CLIENT_GetEscapeBlocker(client, client->activeMon, &trapperPokeId, &trapperAbility) != 4 ||
            trapperPokeId == BTL_POKEPARAM_GetPokeId(client->activeMon)) canCancel = 1;
        func_021E9A78(client->view, client->slotChoices, client->slotIndex, canCancel, client->choiceFlags);
        ++*st;
        break;
    case 1:
        canCancel = 0;
        if (BTL_CLIENT_PollTimeLimitAndSetSub(client, 0)) {
            func_021E9B14((unsigned int *)(client->view));
            *st = 2;
            return canCancel;
        }
        if (func_021E9B20((u8 *)(client->view))) {
            if (func_0689CB14(client->choiceFlags) == 0) {
                chosenMember = func_0689CB1C(client->choiceFlags);
                if (chosenMember < 6) {
                    BTL_ACTION_SetChange(client->actionCursor, client->slotIndex, chosenMember);
                    BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
                    break;
                }
            }
            BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectAction));
        }
        break;
    case 2:
        if (func_021E9B20((u8 *)(client->view))) BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepAutoSelectActions));
        break;
    }
    return 0;
}












static inline u8 isSameSlotIndex(BtlClient *client)
{
    return client->slotIndex == client->slotsDone ? 1 : 0;
}












/*
 * lever: u16 b/d retain the spilled reload and narrow only at the u8 call;
 *        enum same retains the early ternary truncation.
 */
u32 BTL_CLIENT_StepSelectItem(BtlClient *client, int *st)
{
    u32 itemId, pointCost, zero;
    u16 itemPocket, itemTarget;
    Value isLastSlot;
    u32 foeSemiInvulnerable;
    switch (*st) {
    case 0:
        itemId = BTL_CLIENT_SumSlotFlagsBeforeCurrent(client);
        isLastSlot = isSameSlotIndex(client);
        foeSemiInvulnerable = (u8)BTL_CLIENT_IsLoneFoeSemiInvulnerable(client);
        func_021E9D04(client->view, client->isComm, client->pointCounter, itemId, isLastSlot, foeSemiInvulnerable);
        ++*st;
        break;
    case 1:
        zero = 0;
        if (BTL_CLIENT_PollTimeLimitAndSetSub(client, 0)) {
            func_021E9E70(client->view);
            *st = 2;
            return zero;
        }
        if (func_021E9E80(client->view)) {
            itemId = func_021EA01C(client->view);
            itemPocket = func_021EA044(client->view);
            if (itemId && itemPocket != 6) {
                pointCost = func_021EA030(client->view);
                itemTarget = func_021EA04C(client->view);
                if (client->pointCounter >= pointCost) client->pointCounter = client->pointCounter - pointCost;
                else {
                    client->pointCounter = zero;
                    pointCost = client->pointCounter;
                }
                BTL_CLIENT_SetSlotFlag(client, client->slotIndex, pointCost);
                BTL_ACTION_SetItem((void *)client->actionCursor, itemId, (u8)itemPocket, (u8)itemTarget);
                func_021EA058(client->view);
                if (func_021D805C((void *)itemId, 0xf) == 4) *(u8 *)&client->flags |= 4;
                BTL_CLIENT_SetSlotLinkWord(client, client->slotIndex, itemId);
                BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
            } else BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectAction));
        }
        break;
    case 2:
        if (func_021E9E80(client->view)) BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepAutoSelectActions));
        break;
    }
    return 0;
}












u32 BTL_CLIENT_IsLoneFoeSemiInvulnerable(BtlClient *client)
{
    char *foeParty;
    u32 checkCount;
    u32 semiInvulnerable;
    u32 i;
    u32 aliveCount;
    u8 *mon;
    u32 partyCount;
    if (BTL_MAIN_GetCompetitor(client->main) == 0) {
        foeParty = BTL_SIDE_GetSlotOfClientThunk(client->side, 1);
        partyCount = BTL_SLOT_GetCount(foeParty);
        checkCount = BTL_MAIN_GetActivePosPerSide((unsigned int **)(client->main));
        if (checkCount > partyCount) {
            checkCount = partyCount;
        }
        semiInvulnerable = 0;
        aliveCount = 0;
        for (i = 0; i < checkCount; i++) {
            mon = BTL_SLOT_GetPokeParam(foeParty, (u8)i);
            if (BTL_POKEPARAM_IsFainted(mon) == 0) {
                aliveCount++;
                if (BTL_POKEPARAM_IsSemiInvulnerable((struct UtilWork *)mon) != 0) {
                    semiInvulnerable = 1;
                }
            }
        }
        if (aliveCount == 1 && semiInvulnerable != 0) {
            return 1;
        }
    }
    return 0;
}











u32 BTL_CLIENT_StepSelectRun(BtlClient *client, u32 *st)
{
    u8 blockerPokeId;
    u16 blockerAbility;
    int confirmResult;
    switch (*st) {
    case 0:
        switch (BTL_MAIN_GetCompetitorKind(client->main)) {
        default:
        case 0:
            if (BTL_CLIENT_GetEscapeBlockerForSide(client, &blockerPokeId, &blockerAbility) == 4) {
                *st = 5;
                break;
            }
            if (blockerAbility) {
                func_021EAF18((struct L *)&client->messageA, 2, 0x365);
                func_021EAF50((struct L *)&client->messageA, blockerPokeId);
                func_021EAF50((struct L *)&client->messageA, blockerAbility);
            } else {
                func_021EAF18((struct L *)&client->messageA, 1, 0x4a);
            }
            BTL_CLIENT_ShowMessage(client, (u8 *)&client->messageA);
            *st = 1;
            break;
        case 1:
            func_021EAF18((struct L *)&client->messageA, 1, 0x4c);
            BTL_CLIENT_ShowMessage(client, (u8 *)&client->messageA);
            *st = 1;
            break;
        case 2:
            func_021EAF18((struct L *)&client->messageA, 1, 0x4d);
            func_021EAF78((u8 *)&client->messageA, 0xff);
            BTL_CLIENT_ShowMessage(client, (u8 *)&client->messageA);
            *st = 3;
            break;
        }
        break;
    case 1:
        if (func_021EA710(client->view)) {
            BTL_CLIENT_BuildActionPromptMessage(client, client->activeMon, (u8 *)&client->messageA);
            func_021EA65C(client->view, &client->messageA);
            *st = 2;
        }
        break;
    case 2:
        if (func_021EA710(client->view))
            BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectAction));
        break;
    case 3:
        func_021EA710(client->view);
        if (func_021EA720(client->view)) {
            func_021EAF18((struct L *)&client->messageA, 3, 8);
            func_021EAF18((struct L *)&client->messageB, 3, 9);
            func_021EABC4(client->view, (u32)&client->messageA, (u32)&client->messageB, 1);
            *st = 4;
        }
        break;
    case 4:
        if (func_021EA710(client->view)) {
            if (func_021EAC54(client->view, &confirmResult)) {
                if (confirmResult == 0)
                    *st = 5;
                else
                    BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectAction));
            } else if (BTL_CLIENT_PollTimeLimitReady(client)) {
                BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepAutoSelectActions));
            }
        }
        break;
    case 5:
        func_021D8414((void *)client->actionCursor);
        *(u8 *)&client->flags |= 4;
        BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
        break;
    }
    return 0;
}











u32 BTL_CLIENT_StepAdvanceSlot(BtlClient *client, int *st)
{
    u8 actionCount;
    void *mon;
    switch (*st) {
    case 0:
        func_021E9964((unsigned int)client->view);
        ++*st;
        break;
    case 1:
        if (func_021E9974((unsigned int)client->view)) {
            ++client->slotIndex;
            if (client->slotIndex < client->slotCount) {
                if ((((u32)*(u8 *)&client->flags << 29) >> 31) == 0) {
                    BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectAction));
                    break;
                }
                while (client->slotIndex < client->slotCount) {
                    mon = BTL_SIDE_GetClientPokeParam((char *)(client->side), client->clientId, client->slotIndex);
                    if (!BTL_CLIENT_IsActionForced((u8 *)client, mon, (u8 *)client->actions + client->slotIndex * 4))
                        BTL_CALC_ActionSetNone((u32 *)((u8 *)client->actions + client->slotIndex * 4));
                    ++client->slotIndex;
                }
            }
            if (client->slotIndex >= client->slotCount) {
                actionCount = client->slotCount + client->extraActionCount;
                client->extraActionCount = 0;
                client->sendData = (u8 *)client->actions;
                client->sendSize = actionCount * 4;
                BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSendActions));
            }
        }
        break;
    }
    return 0;
}












u32 BTL_CLIENT_StepSendActions(BtlClient *client, s32 *st)
{
    switch (*st) {
    case 0:
        BTL_CLIENT_FlushSlotLinkWords(client);
        if (BTL_MAIN_GetCommPos(client->main) != 0) {
            client->viewLocked = 1;
            func_021EA7FC((char *)(client->view));
            *st = *st + 1;
        } else {
            *st = *st + 2;
        }
        break;
    case 1:
        if (func_021EA814(client->view) != 0) {
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            BTL_CLIENT_StopTimeLimit(client);
            *st = *st + 1;
            return 1;
        }
        break;
    default:
        return 1;
    }
    return 0;
}











void BTL_CLIENT_ClearSlotLinkWords(BtlClient *client) { u32 i; for(i=0;i<3;i++) client->slotLinkWords[i]=0; }











void BTL_CLIENT_SetSlotLinkWord(BtlClient *client, u32 i, u32 v) { if(client->isComm==0) { if(client->clientId==BTL_MAIN_GetOwnClientId(client->main)) { client->slotLinkWords[i]=v; BTL_MAIN_AddItemToBag(client->main,client->clientId,v); } } }











/*
 * lever: BTL_MAIN_SubItemFromBag consumes the live r2 halfword as its third argument;
 * its matched body forwards it to func_02007E50.
 */
void BTL_CLIENT_FlushSlotLinkWord(BtlClient *client, u32 i)
{
    if (client->isComm == 0) {
        if (client->clientId == BTL_MAIN_GetOwnClientId(client->main)) {
            u16 *a = client->slotLinkWords;
            u32 v = a[i];
            if (v != 0) {
                a[i] = 0;
                BTL_MAIN_SubItemFromBag(client->main, client->clientId, v);
            }
        }
    }
}











void BTL_CLIENT_FlushSlotLinkWords(BtlClient *client) { u32 i; if(client->isComm==0) for(i=0;i<3;i++) BTL_CLIENT_FlushSlotLinkWord(client,(u8)i); }











void BTL_CLIENT_ClearSlotFlags(BtlClient *client) { MI_CpuFill8(client->slotFlags,0,3); }










/*
 * follower: unlabelled byte accessor at 0x021CF43C.
 */
void BTL_CLIENT_SetSlotFlag(BtlClient *client, u32 i, u32 v)
{
    client->slotFlags[i] = v;
}










u8 BTL_CLIENT_GetSlotFlag(BtlClient *client, u32 i)
{
    return client->slotFlags[i];
}










u8 BTL_CLIENT_SumSlotFlagsBeforeCurrent(BtlClient *client)
{
    u32 i;
    u32 sum;
    u32 n;
    sum = 0;
    n = client->slotIndex;
    i = 0;
    for (; i < n; i++) sum += client->slotFlags[i];
    return sum;
}











u32 BTL_CLIENT_IsActionForced(u8 *client, void *mon, u8 *outAction)
{
    u32 moveId;
    u16 lastMoveId;
    u32 moveSlot;
    union Slot sickCont;
    if (BTL_POKEPARAM_IsFainted(mon) != 0) {
        if (outAction != 0) {
            BTL_CALC_ActionSetNone((u32 *)outAction);
        }
        return 1;
    }
    if (BTL_POKEPARAM_TestContFlag(mon, 0xc) != 0) {
        if (outAction != 0) {
            BTL_CALC_ActionSetForcedSkip((u32 *)outAction);
        }
        return 1;
    }
    moveId = 0x19;
    if (BTL_POKEPARAM_HasSick(mon, moveId) != 0) {
        sickCont = BTL_POKEPARAM_GetSickContRaw(mon, moveId);
        moveId = BTLV_CORE_GetSlotValue(sickCont);
        moveSlot = BTL_POKEPARAM_GetLastMoveSlot(mon);
        if (outAction != 0) {
            BTL_ACTION_SetFight((struct Unk021D82D0 *)outAction, moveId, moveSlot);
        }
        return 1;
    }
    if (BTL_POKEPARAM_HasSick(mon, 0x1a) != 0) {
        lastMoveId = BTL_POKEPARAM_GetLastUsedMoveId(mon);
        moveSlot = BTL_POKEPARAM_GetLastMoveSlot(mon);
        BTL_POKEPARAM_FindMoveSlot(mon, lastMoveId);
        if (outAction != 0) {
            BTL_ACTION_SetFight((struct Unk021D82D0 *)outAction, lastMoveId, moveSlot);
        }
        return 1;
    }
    return 0;
}











u32 BTL_CLIENT_SetStruggleIfNoMoves(BtlClient *client, void *mon, u32 outAction)
{
    u32 moveCount = BTL_POKEPARAM_GetMoveCount(mon);
    u32 usableCount = 0;
    u32 i = 0;
    for (; i < moveCount; i++) {
        if (BTL_CLIENT_IsMoveSelectionBlocked(client, mon, (u32)BTL_POKEPARAM_GetMoveId(mon, (u8)i), 0) == 0) {
            if ((u32)BTL_POKEPARAM_GetMovePPChecked(mon, (u8)i) != 0) {
                usableCount++;
            }
        }
    }
    if (usableCount == 0) {
        BTL_CLIENT_SetStruggleAction((struct Unk021D82D0 *)outAction, client, mon);
        return 1;
    }
    return 0;
}










void BTL_CLIENT_SetStruggleAction(struct Unk021D82D0 *out, BtlClient *client, void *mon)
{
    u32 target;
    target = BTL_CALC_PeekMoveTarget(client->main, client->side, mon, 165, client->actionResult);
    BTL_ACTION_SetFight(out, 165, target);
}










int BTL_CLIENT_IsMoveSelectionBlocked(BtlClient *client, void *mon, u32 move, void *outMessage)
{
    u32 lockedMoveId;
    u32 forcedMoveId;
    union Slot sickCont;
    if (move == 0xa5) return 0;
    if (BTL_CLIENT_IsHeldItemEffective(client, mon) && BTL_POKEPARAM_HasSick(mon, 0x1b)) {
        sickCont = BTL_POKEPARAM_GetSickContRaw(mon, 0x1b);
        lockedMoveId = BTLV_CORE_GetSlotValue(sickCont);
        if (BTL_POKEPARAM_HasMove(mon, lockedMoveId) && lockedMoveId != move) {
            if (outMessage) {
                func_021EAF18(outMessage, 1, 0x63);
                func_021EAF50(outMessage, BTL_POKEPARAM_GetItem(mon));
                func_021EAF50(outMessage, lockedMoveId);
            }
            return 1;
        }
    }
    if (BTL_POKEPARAM_HasSick(mon, 0x17)) {
        forcedMoveId = BTLV_CORE_GetSlotValue(BTL_POKEPARAM_GetSickContRaw(mon, 0x17));
        if (move != forcedMoveId) {
            if (outMessage) {
                func_021EAF18(outMessage, 1, 0x64);
                func_021EAF50(outMessage, BTL_POKEPARAM_GetPokeId(mon));
                func_021EAF50(outMessage, forcedMoveId);
            }
            return 1;
        }
    }
    if (BTL_POKEPARAM_HasSick(mon, 0xb) && WAZA_TOOL_IsDamaging((void *)move) == 0) {
        if (outMessage) {
            func_021EAF18(outMessage, 2, 0x23b);
            func_021EAF50(outMessage, BTL_POKEPARAM_GetPokeId(mon));
            func_021EAF50(outMessage, move);
        }
        return 1;
    }
    if (BTL_POKEPARAM_HasSick(mon, 0xc) && move == BTL_POKEPARAM_GetLastSelectedMoveId(mon)) {
        if (outMessage) {
            func_021EAF18(outMessage, 2, 0x244);
            func_021EAF50(outMessage, BTL_POKEPARAM_GetPokeId(mon));
            func_021EAF50(outMessage, move);
        }
        return 1;
    }
    if (BTL_POKEPARAM_HasSick(mon, 0xd) && move == BTL_POKEPARAM_GetSickParam(mon, 0xd) && move != 0xa5) {
        if (outMessage) {
            func_021EAF18(outMessage, 2, 0x253);
            func_021EAF50(outMessage, BTL_POKEPARAM_GetPokeId(mon));
            func_021EAF50(outMessage, move);
        }
        return 1;
    }
    if (BTL_POKEPARAM_HasSick(mon, 0xf) && WAZA_TOOL_GetFlag((void *)move, 0xc)) {
        if (outMessage) {
            func_021EAF18(outMessage, 2, 0x37a);
            func_021EAF50(outMessage, BTL_POKEPARAM_GetPokeId(mon));
            func_021EAF50(outMessage, move);
        }
        return 1;
    }
    if (func_021EFCE4((char *)(client->battleField), 3) && func_021EFC1C((int)client->battleField, (int)client->side, mon, move)) {
        if (outMessage) {
            func_021EAF18(outMessage, 2, 0x24d);
            func_021EAF50(outMessage, BTL_POKEPARAM_GetPokeId(mon));
            func_021EAF50(outMessage, move);
        }
        return 1;
    }
    if (func_021EFCE4((char *)(client->battleField), 2) && WAZA_TOOL_GetFlag((void *)move, 9)) {
        if (outMessage) {
            func_021EAF18(outMessage, 2, 0x43e);
            func_021EAF50(outMessage, BTL_POKEPARAM_GetPokeId(mon));
            func_021EAF50(outMessage, move);
        }
        return 1;
    }
    return 0;
}











u32 BTL_CLIENT_BuildUsableMoveMask(BtlClient *client, void *mon, u8 *out)
{
    u8 moveCount = BTL_POKEPARAM_GetMoveCount(mon);
    u32 firstUsable = 4;
    u8 moveIndex = 0;
    for (; moveIndex < moveCount; moveIndex++) {
        if (BTL_POKEPARAM_GetMovePPChecked(mon, moveIndex) != 0) {
            out[moveIndex] = (BTL_CLIENT_IsMoveSelectionBlocked(client, mon, BTL_POKEPARAM_GetMoveId(mon, moveIndex), 0) == 0) ? 1 : 0;
            if (firstUsable == 4 && out[moveIndex] != 0) {
                firstUsable = moveIndex;
            }
        } else {
            out[moveIndex] = 0;
        }
    }
    for (; moveIndex < 4; moveIndex++) {
        out[moveIndex] = 0;
    }
    return firstUsable;
}










int BTL_CLIENT_IsHeldItemEffective(BtlClient *client, void *mon)
{
    if (func_021EFCE4(client->battleField, 7)) return 0;
    if (BTL_POKEPARAM_HasSick(mon, 19)) return 0;
    if (func_021D59B4(mon, 17) != 103) return 1;
    return 0;
}











u32 BTL_CLIENT_GetEscapeBlocker(BtlClient *client, void *mon, u8 *outBlockerPokeId, u16 *outBlockerAbility)
{
    u32 result;
    if (BTL_CLIENT_IsHeldItemEffective(client, mon) != 0) {
        if (BTL_POKEPARAM_GetItem(mon) == 0x127) {
            return 4;
        }
    }
    result = BTL_CLIENT_FindTrapper(client, mon, outBlockerPokeId, outBlockerAbility);
    if (result == 4) {
        *outBlockerPokeId = 0x1f;
        *outBlockerAbility = 0;
        result = 4;
    }
    return result;
}











u32 BTL_CLIENT_GetEscapeBlockerForSide(BtlClient *client, u8 *outBlockerPokeId, u16 *outBlockerAbility)
{
    u32 i;
    u8 *mon;
    u32 result;

    for (i = 0; i < client->slotCount; i++) {
        mon = BTL_SLOT_GetPokeParam(client->sideData, (u8)i);
        if (BTL_POKEPARAM_IsFainted(mon) == 0) {
            if (BTL_CLIENT_IsHeldItemEffective(client, mon) != 0 && BTL_POKEPARAM_GetItem((struct QI *)mon) == 0xe4)
                return 4;
            if (func_021D59B4(mon, 0x11) == 0x32)
                return 4;
        }
    }
    for (i = 0; i < client->slotCount; i++) {
        result = BTL_CLIENT_FindTrapper(client, BTL_SLOT_GetPokeParam(client->sideData, (u8)i), outBlockerPokeId, outBlockerAbility);
        if (result != 4)
            return result;
    }
    return 4;
}










u32 BTL_CLIENT_FindTrapper(BtlClient *client, void *mon, u8 *outBlockerPokeId, u16 *outBlockerAbility)
{
    u8 foeSlots[4];
    u8 foeCount;
    u8 i;
    u8 *foe;
    u16 foeAbility;
    foeCount = BTL_MAIN_CollectLivingPokeIds(client->main, (int)client->side, (u16)(BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, BTL_POKEPARAM_GetPokeId(mon)) | 0x100), foeSlots);
    for (i = 0; i < foeCount; i++) {
        foe = BTL_SIDE_GetPokeByIdThunk(client->side, foeSlots[i]);
        foeAbility = func_021D59B4(foe, 0x11);
        BTL_POKEPARAM_GetPokeId(foe);
        if (foeAbility == 0x17 && BTL_CLIENT_CanShadowTagTrap(client, mon)) {
            *outBlockerPokeId = BTL_POKEPARAM_GetPokeId(foe);
            *outBlockerAbility = foeAbility;
            return 0;
        }
        if (foeAbility == 0x47 && BTL_CLIENT_CanArenaTrapTrap(client, mon)) {
            *outBlockerPokeId = BTL_POKEPARAM_GetPokeId(foe);
            *outBlockerAbility = foeAbility;
            return 0;
        }
        if (foeAbility == 0x2a && BTL_CLIENT_CanMagnetPullTrap(client, mon)) {
            *outBlockerPokeId = BTL_POKEPARAM_GetPokeId(foe);
            *outBlockerAbility = foeAbility;
            return 0;
        }
    }
    if (BTL_POKEPARAM_HasSick(mon, 0x16) || BTL_POKEPARAM_HasSick(mon, 8) || BTL_POKEPARAM_HasSick(mon, 0x15)) {
        *outBlockerPokeId = BTL_POKEPARAM_GetPokeId(mon);
        *outBlockerAbility = 0;
        return 3;
    }
    return 4;
}










int BTL_CLIENT_CanShadowTagTrap(void *client, void *mon)
{
    if (func_021D59B4(mon, 17) != 23) return 1;
    return 0;
}











int BTL_CLIENT_CanArenaTrapTrap(BtlClient *client, void *mon)
{
    u32 itemEffective;

    itemEffective = BTL_CLIENT_IsHeldItemEffective(client, mon);
    if (func_021EFCE4((char *)(client->battleField), 2) != 0)
        return 1;
    if (BTL_POKEPARAM_HasSick(mon, 0x1f) != 0)
        return 1;
    if (BTL_POKEPARAM_HasSick(mon, 0x15) != 0)
        return 1;
    if (itemEffective != 0 && BTL_POKEPARAM_GetItem(mon) == 0x116)
        return 1;
    if (func_021D59B4(mon, 0x11) == 0x1a)
        return 0;
    if (BTL_POKEPARAM_HasType(mon, 2) != 0)
        return 0;
    if (BTL_POKEPARAM_HasSick(mon, 0x1e) != 0)
        return 0;
    if (BTL_POKEPARAM_HasSick(mon, 0x20) != 0)
        return 0;
    if (itemEffective != 0 && BTL_POKEPARAM_GetItem(mon) == 0x21d)
        return 0;
    return 1;
}










/*
 * extent: follower 0x021CFBA4 already has its own matched source/shard.
 */
int BTL_CLIENT_CanMagnetPullTrap(void *client, void *mon)
{
    if (BTL_POKEPARAM_HasType(mon, 8)) return 1;
    return 0;
}










/*
 * semantic: signed byte -1 has the original stored bits 0xff. The body
 *   only writes bytes and never reads through p. Six stores cover p10c..p111.
 */
void BTL_CLIENT_ClearSlotOrder(BtlClient *client)
{
    u32 i = 0;
    s8 fill = -1;
    for (; i < 6; i++) client->slotOrder[i] = fill;
}









int BTL_CLIENT_HasSlotInOrder(BtlClient *client, int v)
{
    u32 i = 0;
    for (; i < 6; i++) {
        if (client->slotOrder[i] == v) return 1;
    }
    return 0;
}









void BTL_CLIENT_SetSlotOrder(BtlClient *client, u32 i, u32 v)
{
    if (i < 6) client->slotOrder[i] = v;
}









int BTL_CLIENT_ChooseAiSwitchTarget(BtlClient *client, void *mon, u32 orderSlot, u8 *outMember)
{
    u8 chosenMember;
    u8 trapperPokeId;
    u16 trapperAbility;
    u8 candidates[6];
    u8 *foe;
    u32 candidateCount;
    u32 i;
    u8 shouldSwitch;
    chosenMember = 6;
    if (BTL_CLIENT_GetEscapeBlocker(client, mon, &trapperPokeId, &trapperAbility) != 4) return 0;
    if (BTL_SLOT_CountLiving(client->sideData) <= client->slotCount) return 0;
    foe = BTL_CLIENT_PickRandomFoe(client, BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, BTL_POKEPARAM_GetPokeId(mon)));
    if (!foe) return 0;
    if (BTL_POKEPARAM_IsIllusionActive((struct R4 *)foe))
        foe = BTL_MAIN_ResolveIllusionPoke(client->main, client->side, foe);
    if (BTL_CLIENT_IsCountdownEndingNext(client, mon)) shouldSwitch = 1;
    else if (BTL_CLIENT_ShouldSwitchVsWonderGuard(client, mon, foe)) shouldSwitch = 1;
    else if (BTL_CLIENT_ShouldSwitchNoEffectiveMove(client, mon, foe)) shouldSwitch = 1;
    else if (BTL_CLIENT_ShouldSwitchWhileLocked(client, mon, foe)) shouldSwitch = 1;
    else if (BTL_CLIENT_FindSwitchFromHitHistory(client, mon, foe, &chosenMember)) shouldSwitch = 1;
    else if (BTL_CLIENT_FindNaturalCureSwitch(client, mon, &chosenMember)) shouldSwitch = 1;
    else if (BTL_CLIENT_FindSwitchByTypeMatchup(client, mon, foe, &chosenMember)) shouldSwitch = 1;
    else return 0;
    if (!shouldSwitch) return 0;
    if (chosenMember == 6) {
        candidateCount = BTL_CLIENT_ListAbleMons(client, candidates);
        BTL_CLIENT_SortMonsByMovePower(client, candidates, candidateCount, foe);
        for (i = 0; i < candidateCount; i++) {
            if (!BTL_CLIENT_HasSlotInOrder(client, candidates[i])) {
                chosenMember = candidates[i];
                break;
            }
        }
    }
    if (chosenMember == 6) return 0;
    BTL_CLIENT_SetSlotOrder(client, orderSlot, chosenMember);
    *outMember = chosenMember;
    return 1;
}









u8 *BTL_CLIENT_PickRandomFoe(BtlClient *client, int positionId)
{
    u8 foeSlots[4];
    u8 foeCount;
    u32 pick;

    foeCount = BTL_MAIN_CollectLivingPokeIds(client->main, (int)client->side, (u16)(positionId | 0x100), foeSlots);
    if (foeCount) {
        client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
        if (foeCount == 0) {
            pick = (u32)(client->rng.seed >> 32);
        } else {
            pick = (u32)(((client->rng.seed >> 32) * (u32)foeCount) >> 32);
        }
        return BTL_SIDE_GetPokeByIdThunk(client->side, foeSlots[(u8)pick]);
    }
    return 0;
}








/*
 * lever: explicit aggregate return local reserves the original eight-byte frame;
 *   named incremented accessor result gives cmp r0,r4.
 */
int BTL_CLIENT_IsCountdownEndingNext(void *client, void *mon)
{
    u32 limit;
    u32 sickId = 20;
    u32 nextTurn;
    union Slot sickCont;
    if (BTL_POKEPARAM_HasSick(mon, sickId)) {
        sickCont = BTL_POKEPARAM_GetSickContRaw(mon, sickId);
        limit = BTLV_CORE_GetSlotLow(sickCont);
        nextTurn = BTL_POKEPARAM_GetSickTurn(mon, sickId) + 1;
        if (nextTurn == limit) return 1;
    }
    return 0;
}









int BTL_CLIENT_ShouldSwitchVsWonderGuard(BtlClient *client, void *mon, void *foe)
{
    if (BTL_MAIN_GetRule(client->main) != 0)
        return 0;
    if (func_021D59B4(foe, 0x11) == 0x19) {
        if (BTL_CLIENT_HasMoveWithAffinityVsTarget(client, mon, foe, 4) == 0 && BTL_CLIENT_AnyMemberHasMoveVsTarget(client, foe, 4) != 0) {
            client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
            if ((u32)(((client->rng.seed >> 32) * 3) >> 32) < 2)
                return 1;
        }
    }
    return 0;
}








/*
 * extent: two zero padding bytes at 0x021CFFAA, followed by labelled BTL_CLIENT_ShouldSwitchWhileLocked.
 */
int BTL_CLIENT_ShouldSwitchNoEffectiveMove(BtlClient *client, void *mon, void *foe)
{
    u8 moveCount;
    u16 foeTypePair;
    u32 damagingCount;
    u32 i;
    u32 moveId;
    foeTypePair = BTL_POKEPARAM_GetTypePair(foe);
    moveCount = BTL_POKEPARAM_GetMoveCount(mon);
    damagingCount = 0;
    for (i = 0; i < moveCount; i++) {
        moveId = (u32)BTL_POKEPARAM_GetMoveId(mon, (u8)i);
        if (WAZA_TOOL_IsDamaging((void *)moveId)) {
            if (BTL_CALC_GetTypeAffinityVsPair(WAZA_TOOL_GetType((void *)moveId), foeTypePair))
                return 0;
            damagingCount++;
        }
    }
    if (damagingCount >= 2) {
        if (BTL_CLIENT_AnyMemberHasMoveVsTarget(client, foe, 4)) {
            client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
            return (u32)(((client->rng.seed >> 32) * 3) >> 32) < 2;
        }
        if (BTL_CLIENT_AnyMemberHasMoveVsTarget(client, foe, 3)) {
            client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
            return (u32)(((client->rng.seed >> 32) * 2) >> 32) < 1;
        }
    }
    return 0;
}







int BTL_CLIENT_ShouldSwitchWhileLocked(BtlClient *client, void *mon, void *target)
{
    u32 id;
    int valid;
    u32 kind;
    union Slot slot;
    if (BTL_POKEPARAM_HasSick(mon, 0x1b)) {
        slot = BTL_POKEPARAM_GetSickContRaw(mon, 0x1b);
        id = BTLV_CORE_GetSlotValue(slot);
        if (id) {
            valid = WAZA_TOOL_IsDamaging((void *)id);
            kind = WAZA_TOOL_GetType((void *)id);
            if (BTL_CALC_GetTypeAffinityVsPair(kind, BTL_POKEPARAM_GetTypePair(target)) == 0 && valid) {
                if (BTL_CLIENT_AnyMemberHasMoveVsTarget(client, target, 4)) {
                    client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
                    return (u32)(((client->rng.seed >> 32) * 3) >> 32) < 2;
                }
                if (BTL_CLIENT_AnyMemberHasMoveVsTarget(client, target, 3)) {
                    client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
                    return (u32)(((client->rng.seed >> 32) * 2) >> 32) < 1;
                }
            }
            if (!valid) {
                client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
                return (u32)(((client->rng.seed >> 32) * 2) >> 32) < 1;
            }
        }
    }
    return 0;
}







int BTL_CLIENT_FindSwitchFromHitHistory(BtlClient *client, void *mon, void *target, u8 *out)
{
    u16 hitRecord[5];
    u32 rowIndex;
    u8 recordPos;
    u32 abilityIndex;
    const struct Row *kindRow;
    recordPos = 0;
    if (BTL_CLIENT_HasMoveWithAffinityVsTarget(client, mon, target, 4)) {
        client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
        if ((u32)(((client->rng.seed >> 32) * 3) >> 32) == 0) return 0;
    }
    while (BTL_POKEPARAM_GetHitRecord(mon, 1, recordPos++, hitRecord + 1)) {
        for (rowIndex = 0; rowIndex < 4; rowIndex++) {
            kindRow = &gBtlClientAiHitKindRows[rowIndex];
            if (((u8 *)hitRecord)[6] == kindRow->kind) {
                for (abilityIndex = 0; abilityIndex < 4; abilityIndex++) {
                    if (!kindRow->ids[abilityIndex]) break;
                    if (BTL_CLIENT_FindMemberWithAbility(client, kindRow->ids[abilityIndex], (u8 *)hitRecord)) {
                        client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
                        if ((u32)(((client->rng.seed >> 32) * 2) >> 32) == 0) {
                            *out = ((u8 *)hitRecord)[0];
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}








int BTL_CLIENT_FindNaturalCureSwitch(BtlClient *client, void *mon, u8 *out)
{
    u16 hitRecord[4];
    u8 member;

    if (func_021D59B4(mon, 0x11) == 0x1e) {
        if (BTL_POKEPARAM_HasSick(mon, 2) || BTL_POKEPARAM_HasSick(mon, 3)) {
            if (BTL_POKEPARAM_GetHpRatioFixed(mon) >= 0x32000) {
                if (BTL_POKEPARAM_GetHitRecord(mon, 1, 0, hitRecord)) {
                    if (BTL_CLIENT_FindMemberResistingType(client, ((u8 *)hitRecord)[4], 2, &member)) {
                        *out = member;
                        return 1;
                    }
                } else {
                    client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
                    return (u32)(((client->rng.seed >> 32) * 2) >> 32) ? 0 : 1;
                }
            }
        }
    }
    return 0;
}







int BTL_CLIENT_FindSwitchByTypeMatchup(BtlClient *client, void *mon, void *target, u8 *out)
{
    u16 hitRecord[4];
    u32 totalBoosts;
    u32 member;
    u32 partyCount;
    u8 *candidate;
    int hitAffinity;
    if (BTL_CLIENT_HasMoveWithAffinityVsTarget(client, mon, target, 4)) {
        client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
        if ((u32)(((client->rng.seed >> 32) * 10) >> 32) != 0) return 0;
    }
    totalBoosts = 0;
    for (member = 1; member <= 7; member++) totalBoosts += func_021D59B4(mon, member);
    if (totalBoosts >= 4) return 0;
    if (BTL_POKEPARAM_GetHitRecord(mon, 1, 0, hitRecord)) {
        partyCount = BTL_SLOT_GetCount(client->sideData);
        member = BTL_CALC_GetScanStartIndex(BTL_MAIN_GetRule(client->main), client->slotCount);
        for (; member < partyCount; member++) {
            if (!BTL_CLIENT_HasSlotInOrder(client, (u8)member)) {
                candidate = BTL_SLOT_GetPokeParam(client->sideData, (u8)member);
                if (BTL_CLIENT_HasMoveWithAffinityVsTarget(client, candidate, target, 4)) {
                    hitAffinity = BTL_CALC_GetTypeAffinityVsPair(((u8 *)hitRecord)[4], BTL_POKEPARAM_GetTypePair(candidate));
                    if (hitAffinity == 0) {
                        client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
                        if ((u32)(((client->rng.seed >> 32) * 2) >> 32) == 0) {
                            *out = member;
                            return 1;
                        }
                    } else if (hitAffinity < 3) {
                        client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
                        if ((u32)(((client->rng.seed >> 32) * 3) >> 32) == 0) {
                            *out = member;
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}








int BTL_CLIENT_FindMemberWithAbility(BtlClient *client, u16 ability, u8 *outMember)
{
    u32 n;
    u32 i;
    u8 *member;

    n = BTL_SLOT_GetCount(client->sideData);
    i = BTL_CALC_GetScanStartIndex(BTL_MAIN_GetRule(client->main), client->slotCount);
    for (; i < n; i++) {
        if (BTL_CLIENT_HasSlotInOrder(client, (u8)i) == 0) {
            member = BTL_SLOT_GetPokeParam(client->sideData, (u8)i);
            if (BTL_POKEPARAM_IsFainted(member) == 0 && ability == func_021D59B4(member, 0x11)) {
                *outMember = i;
                return 1;
            }
        }
    }
    return 0;
}








int BTL_CLIENT_AnyMemberHasMoveVsTarget(BtlClient *client, void *target, int minAffinity)
{
    u32 n;
    u32 i;

    n = BTL_SLOT_GetCount(client->sideData);
    i = BTL_CALC_GetScanStartIndex(BTL_MAIN_GetRule(client->main), client->slotCount);
    for (; i < n; i++) {
        if (BTL_CLIENT_HasSlotInOrder(client, (u8)i) == 0) {
            if (BTL_CLIENT_HasMoveWithAffinityVsTarget(client, BTL_SLOT_GetPokeParam(client->sideData, (u8)i), target, minAffinity))
                return 1;
        }
    }
    return 0;
}








int BTL_CLIENT_FindMemberResistingType(BtlClient *client, u8 attackType, int maxAffinity, u8 *outMember)
{
    u32 n;
    u32 i;
    u8 *m;

    n = BTL_SLOT_GetCount(client->sideData);
    i = BTL_CALC_GetScanStartIndex(BTL_MAIN_GetRule(client->main), client->slotCount);
    for (; i < n; i++) {
        if (BTL_CLIENT_HasSlotInOrder(client, (u8)i) == 0) {
            m = BTL_SLOT_GetPokeParam(client->sideData, (u8)i);
            if (BTL_POKEPARAM_IsAbleToBattle(m) != 0 && BTL_CALC_GetTypeAffinityVsPair(attackType, BTL_POKEPARAM_GetTypePair(m)) <= maxAffinity) {
                *outMember = i;
                return 1;
            }
        }
    }
    return 0;
}








int BTL_CLIENT_HasMoveWithAffinityVsTarget(BtlClient *client, void *mon, void *target, int minAffinity)
{
    u16 targetTypePair;
    u8 moveCount;
    u32 i;
    u32 moveId;

    if (BTL_POKEPARAM_IsFainted(mon) == 0) {
        targetTypePair = BTL_POKEPARAM_GetTypePair(target);
        moveCount = BTL_POKEPARAM_GetMoveCount(mon);
        for (i = 0; i < moveCount; i++) {
            moveId = BTL_POKEPARAM_GetMoveId(mon, (u8)i);
            if (BTL_POKEPARAM_GetMovePPChecked(mon, (u8)i) && WAZA_TOOL_IsDamaging((void *)moveId)
                && BTL_CLIENT_IsMoveSelectionBlocked(client, mon, moveId, 0) == 0) {
                if (BTL_CALC_GetTypeAffinityVsPair(WAZA_TOOL_GetType((void *)moveId), targetTypePair) >= minAffinity)
                    return 1;
            }
        }
    }
    return 0;
}








u8 BTL_CLIENT_PickRotationPosition(BtlClient *client)
{
    u8 positions[2];
    u32 positionCount;
    u32 pickedIndex;

    positionCount = 1;
    positions[0] = 1;
    if (BTL_POKEPARAM_IsFainted(BTL_SLOT_GetPokeParam(client->sideData, (u8)(int)BTL_SLOT_GetRotateSrcIndex(2))) == 0) {
        positions[positionCount++] = 2;
    }
    if (BTL_POKEPARAM_IsFainted(BTL_SLOT_GetPokeParam(client->sideData, (u8)(int)BTL_SLOT_GetRotateSrcIndex(3))) == 0) {
        positions[positionCount++] = 3;
    }
    if (positionCount > 1) {
        client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
        if (positionCount == 0) {
            pickedIndex = (u32)(client->rng.seed >> 32);
        } else {
            pickedIndex = (u32)(((client->rng.seed >> 32) * (u32)positionCount) >> 32);
        }
        return positions[pickedIndex];
    }
    return 1;
}







/*
 * lever: nested one-word aggregate return removes its extra frame word;
 *   named count/bytes reproduce original final read/store order. Three
 *   iteration runs, two scheduling variants; no prior compiles.
 * semantic: state/cursor arithmetic is unsigned; byte counters promote
 *   safely and narrow on store. CF81C writes all four availability bytes
 *   before return; CFBF0 writes the single output byte on every nonzero
 *   return path. Full-width pointer payloads retain their original bits.
 */
int BTL_CLIENT_StepAutoChooseActions(BtlClient *client, u32 *state)
{
    u8 moveAvailability[4];
    u8 changeTarget;
    u32 moveOrItem;
    u32 moveSlot;
    u8 rotationPosition;
    u32 targetOrPosition;
    u32 target;
    u32 slotTotal;
    u32 sendBytes;
    switch (*state) {
    case 0:
        BTL_CLIENT_ClearSlotOrder(client);
        client->slotIndex = 0;
        client->extraActionCount = 0;
        *state = 1;
    case 1:
        if (client->slotIndex >= client->slotCount) break;
        (client->activeMon) = BTL_SLOT_GetPokeParam(client->sideData, client->slotIndex);
        (client->actionCursor) = (u8 *)client->actions+client->slotIndex*4;
        if (BTL_POKEPARAM_IsFainted((client->activeMon))) {
            BTL_CALC_ActionSetNone((u32 *)(client->actionCursor));
            goto complete;
        }
        if (BTL_CLIENT_IsActionForced((u8 *)client,(client->activeMon),(client->actionCursor))) goto complete;
        moveOrItem = func_021D3DC4((u8 *)client,(client->activeMon),client->sideData);
        if (moveOrItem) {
            BTL_ACTION_SetItem((u32 *)(client->actionCursor),moveOrItem,client->slotIndex,0);
            goto complete;
        }
        if (BTL_MAIN_GetCompetitor(client->main) && BTL_CLIENT_ChooseAiSwitchTarget(client,(client->activeMon),client->slotIndex,&changeTarget)) {
            BTL_ACTION_SetChange((client->actionCursor),client->slotIndex,changeTarget);
            goto complete;
        }
        if (BTL_MAIN_GetRule(client->main) == 3) {
            rotationPosition = BTL_CLIENT_PickRotationPosition(client);
            if (rotationPosition != 1) {
                targetOrPosition = BTL_SLOT_GetRotateSrcIndex(rotationPosition);
                BTL_ACTION_SetRotate((u32 *)(client->actionCursor),rotationPosition);
                (client->activeMon) = BTL_SLOT_GetPokeParam(client->sideData,targetOrPosition);
                client->extraActionCount = 1;
                (client->actionCursor) = (u8 *)((u32)(client->actionCursor)+4U);
            }
        }
        if (BTL_POKEPARAM_HasSick((client->activeMon),0x19)) {
            moveOrItem = BTLV_CORE_GetSlotValue(BTL_POKEPARAM_GetSickContRaw((client->activeMon),0x19));
            target = BTL_CALC_PeekMoveTarget(client->main,client->side,(client->activeMon),moveOrItem,(u8 *)&client->rng);
            BTL_ACTION_SetFight((struct Unk021D82D0 *)(client->actionCursor),moveOrItem,target);
            goto complete;
        }
        if (BTL_CLIENT_SetStruggleIfNoMoves(client,(client->activeMon),(u32)(client->actionCursor))) *state = 3;
        BTL_POKEPARAM_GetMoveCount((client->activeMon));
        moveSlot = BTL_CLIENT_BuildUsableMoveMask(client,(client->activeMon),moveAvailability);
        if (moveSlot != 4) {
            target = BTL_MAIN_GetTrainerSlotOfPoke(client->main,client->side,BTL_POKEPARAM_GetPokeId((client->activeMon)));
            func_021880BC((int)client->recorder,moveAvailability,target);
            *state = 2;
        } else {
            BTL_CLIENT_SetStruggleAction((struct Unk021D82D0 *)((u32)(client->actionCursor)),client,(client->activeMon));
            goto complete;
        }
        break;
    case 2:
        if (func_02187FB0(client->recorder)) break;
        moveSlot = func_02188134(client->recorder);
        if (moveSlot != 4) {
            targetOrPosition = func_02188140(client->recorder);
            moveOrItem = BTL_POKEPARAM_GetMoveId((client->activeMon),moveSlot);
            BTL_ACTION_SetFight((struct Unk021D82D0 *)(client->actionCursor),moveOrItem,targetOrPosition);
        } else func_021D8414((u32 *)(client->actionCursor));
complete:
        *state = 3;
        break;
    case 3:
        client->slotIndex++;
        slotTotal = client->slotCount;
        if (client->slotIndex >= slotTotal) {
            sendBytes = (slotTotal+client->extraActionCount)*4;
            client->sendData = (u8 *)client->actions;
            client->sendSize = sendBytes;
            client->extraActionCount = 0;
            return 1;
        }
        *state = 1;
        break;
    }
    return 0;
}








u8 BTL_CLIENT_ListAbleMons(BtlClient *client, u8 *ableIndexes)
{
    u32 partySize;
    u8 ableCount;
    u32 partyIndex;

    partySize = BTL_SLOT_GetCount(client->sideData);
    partyIndex = BTL_CALC_GetScanStartIndex(BTL_MAIN_GetRule(client->main), client->slotCount);
    ableCount = 0;
    for (; partyIndex < partySize; partyIndex = (u8)(partyIndex + 1)) {
        if (BTL_POKEPARAM_IsAbleToBattle(BTL_SLOT_GetPokeParam(client->sideData, partyIndex))) {
            if (ableIndexes)
                ableIndexes[ableCount] = partyIndex;
            ableCount = (u8)(ableCount + 1);
        }
    }
    return ableCount;
}





/*
 * pass 6 2026-10-06 P6L01: EXACT* (302 B code plus 2 B pad), also EXACT* under -lang c99. The
 * closing change is u16 type with BTL_CALC_GetTypeAffinityVsPair declared (int, u16). The callee
 * (ov093_func_021D799C.c) also matches EXACT with a u16 second parameter, so the prototype is consistent.
 * Why it closes (seen in a debugger capture of the post-RA scheduler of mwccarm): a word-sized spill of a
 * narrow variable gets the "narrow locals" alias set. With int type, the type store after the call
 * has its own alias, so the count home store has a height of 6 and 'adds r0,r3' (height 7) goes before
 * it. With u16 type (no int conversion, so no hoisted int temp), the type store is in the same set, the
 * count store gets an edge to it (height 7), and it issues second, as in the original. Passes 1 to 5
 * (all 5 B or more) tried every source shape of the entry block; none can change this edge.
 */
void BTL_CLIENT_SortMonsByMovePower(BtlClient *client, u8 *partyOrder, u8 orderCount, void *targetMon)
{
    u16 bestPower[6];
    u16 targetTypePair;
    u8 orderIndex;
    u8 moveIndex;
    void *partyMon;
    u16 moveId;
    u16 movePower;
    u16 swapScore;
    u8 swapIndex;
    targetTypePair = BTL_POKEPARAM_GetTypePair(targetMon);
    for (orderIndex = 0; orderIndex < orderCount; orderIndex++) {
        bestPower[orderIndex] = 0;
        partyMon = BTL_SLOT_GetPokeParam(client->sideData, partyOrder[orderIndex]);
        if (!BTL_POKEPARAM_IsFainted(partyMon)) {
            u8 n;
            n = BTL_POKEPARAM_GetMoveCount(partyMon);
            for (moveIndex = 0; moveIndex < n; moveIndex++) {
                if (BTL_POKEPARAM_GetMovePPChecked(partyMon, moveIndex)) {
                    moveId = BTL_POKEPARAM_GetMoveId(partyMon, moveIndex);
                    if (WAZA_TOOL_IsDamaging((void *)(u32)moveId)) {
                        int moveType;
                        moveType = WAZA_TOOL_GetType((void *)(u32)moveId);
                        movePower = WAZA_TOOL_GetPower((void *)(u32)moveId);
                        if (movePower < 10) movePower = 60;
                        switch (BTL_CALC_GetTypeAffinityVsPair(moveType, targetTypePair)) {
                        case 5: movePower *= 4; break;
                        case 4: movePower *= 2; break;
                        case 2: movePower /= 2; break;
                        case 1: movePower /= 4; break;
                        case 0: movePower = 0; break;
                        case 3: break;
                        }
                        if (bestPower[orderIndex] < movePower) bestPower[orderIndex] = movePower;
                    }
                }
            }
        }
    }
    for (orderIndex = 0; orderIndex < orderCount; orderIndex++) {
        for (moveIndex = orderIndex + 1; moveIndex < orderCount; moveIndex++) {
            if (bestPower[orderIndex] < bestPower[moveIndex]) {
                swapScore = bestPower[orderIndex];
                bestPower[orderIndex] = bestPower[moveIndex];
                bestPower[moveIndex] = swapScore;
                swapIndex = partyOrder[orderIndex];
                partyOrder[orderIndex] = partyOrder[moveIndex];
                partyOrder[moveIndex] = swapIndex;
            }
        }
    }
}





void BTL_CLIENT_BuildSlotChoices(BtlClient *client, u32 a, u32 b, void *q, void *out)
{
    func_0689CA98(q, (unsigned int)client->sideData, b, a);
    func_0689CAB0(q, client->slotCount);
    func_0689CAE0(out, q);
}







void BTL_CLIENT_SetChangeActionsFromChoice(BtlClient *client, u8 *choice)
{
    u8 i;

    for (i = 0; i < choice[6]; i++)
        BTL_ACTION_SetChange((u8 *)client->actions + i * 4, choice[i + 3], choice[i]);
    client->sendData = (u8 *)client->actions;
    client->sendSize = choice[6] << 2;
}






void BTL_CLIENT_SetChangeActionsFirstAble(BtlClient *client)
{
    u8 pairClients[2];
    u8 firstCandidate;
    u8 actionCount;
    u32 partySize;
    u32 i;
    u32 j;
    actionCount = 0;
    partySize = BTL_SLOT_GetCount(client->sideData);
    firstCandidate = BTL_MAIN_GetViewPositionsPerClient(client->main, client->clientId);
    for (i = 0; i < client->pairCount; i++) {
        BTL_MAIN_GetSlotClientAndNth(client->main, client->pairs[i], &pairClients[1], &pairClients[0]);
        for (j = firstCandidate; j < partySize; j++) {
            if (!BTL_POKEPARAM_IsFainted(BTL_SLOT_GetPokeParam(client->sideData, (u8)j))) {
                BTL_ACTION_SetChange((u8 *)client->actions + actionCount++ * 4, pairClients[0], j);
                firstCandidate = j + 1;
                break;
            }
        }
    }
    *(void * *)&client->sendData = client->actions;
    client->sendSize = actionCount * 4;
}







u8 BTL_CLIENT_CollectOwnReceivedIds(BtlClient *client, u8 *ownIds)
{
    u8 *receivedIds;
    u8 receivedCount;
    u32 i;
    u32 ownCount;

    receivedCount = BTL_ADAPTER_GetRecvData((int)client->netChannel, &receivedIds);
    i = 0;
    ownCount = 0;
    for (; i < receivedCount; i++) {
        if (client->clientId == BTL_MAIN_GetSlotClientIdThunk(client->main, receivedIds[i])) {
            ownIds[ownCount] = receivedIds[i];
            ownCount++;
        }
    }
    return ownCount;
}







int BTL_CLIENT_StepAskYesNo(BtlClient *client, int *state)
{
    int answer;
    u8 *sendByte;
    u8 answerFlag;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)client->messageA.data, 3, 5);
        func_021EAF18((struct L *)((u8 *)&client->messageB), 3, 1);
        func_021EABC4(client->view, (u32)client->messageA.data, (u32)((u8 *)&client->messageB), 0);
        (*state)++;
        break;
    case 1:
        if (func_021EAC54(client->view, &answer)) {
            answerFlag = 0;
            if (answer != 0)
                answerFlag = 1;
            sendByte = &client->sendByte;
            *sendByte = answerFlag;
            client->sendData = sendByte;
            client->sendSize = 1;
            return 1;
        }
        break;
    }
    return 0;
}





int BTL_CLIENT_StepChoiceMode2(BtlClient *client, int *state)
{
    return BTL_CLIENT_StepChooseReplacement(client, state, 2);
}





int BTL_CLIENT_StepChoiceMode1(BtlClient *client, int *state)
{
    return BTL_CLIENT_StepChooseReplacement(client, state, 1);
}






/*
 * lever: separate order[6] then pair[2] stack arrays keep the order base
 * at sp+6 and the index in the ldrb register offset; one buffer or a
 * struct member array reassociates this into a base+index and immediate 2.
 * follower: 021D0E74 is an eight-byte tail-call stub to BTL_CLIENT_StepPlaybackRecordedAction;
 * included in this complete 300-byte unit after parent ownership audit.
 */
int BTL_CLIENT_ChooseReplacementsAuto(BtlClient *client)
{
    u8 partyOrder[6];
    u8 pairValues[2];
    u8 changeCount;
    u8 ableCount;
    u8 i;
    u8 *targetMon;
    int rotateSize;
    client->pairCount = BTL_CLIENT_CollectOwnReceivedIds(client, client->pairs);
    if (client->pairCount) {
        ableCount = BTL_CLIENT_ListAbleMons(client,partyOrder);
        if (ableCount) {
            changeCount = client->pairCount;
            targetMon = BTL_CLIENT_PickRandomFoe(client,client->pairs[0]);
            if (targetMon) BTL_CLIENT_SortMonsByMovePower(client,partyOrder,ableCount,targetMon);
            if (changeCount > ableCount) {
                if (BTL_MAIN_GetRule(client->main) == 3) {
                    rotateSize = BTL_CLIENT_TrySetRotateAction(client,client->actions);
                    if (rotateSize) {
                        client->sendSize = rotateSize;
                        *(void * *)&client->sendData = client->actions;
                        return 1;
                    }
                }
                changeCount = ableCount;
            }
            for (i=0;i<changeCount;i++) {
                BTL_MAIN_GetSlotClientAndNth(client->main,client->pairs[i],pairValues,pairValues+1);
                BTL_ACTION_SetChange((u8 *)client->actions+i*4,pairValues[1],partyOrder[i]);
            }
            *(void * *)&client->sendData = client->actions;
            client->sendSize = changeCount*4;
        } else {
            if (BTL_CLIENT_IsDoubleBattleLeadAlive(client)) {
                rotateSize = BTL_CLIENT_TrySetRotateAction(client,client->actions);
                if (rotateSize) {
                    client->sendSize = rotateSize;
                    *(void * *)&client->sendData = client->actions;
                    return 1;
                }
            }
            BTL_ACTION_SetChangeDepleted(client->actions);
            *(void * *)&client->sendData = client->actions;
            client->sendSize = 4;
        }
    } else {
        BTL_CALC_ActionSetNone(client->actions);
        *(void * *)&client->sendData = client->actions;
        client->sendSize = 4;
    }
    return 1;
}






int BTL_CLIENT_StepForwardToSubFn(BtlClient *client, int *state)
{
    return BTL_CLIENT_StepPlaybackRecordedAction(client,state);
}






/*
 * lever: the state-0 fallbacks and single-mon path set state 4, not 6;
 * duplicating the state-4 assignment inside both fallback arms preserves
 * the late cross-jump of D8/DC stores. Factoring it outside adds 12 bytes.
 * volatile: count at 021D0EB2 is reread at 021D0EB6 and 021D0ECC.
 */
int BTL_CLIENT_StepChooseReplacement(BtlClient *client, int *state, u8 choiceMode)
{
    u8 partyOrder[6];
    u8 pairValues[2];
    u32 ableCount;
    u32 changeCount;
    int rotateSize;
    void *leadMon;
    switch (*state) {
    case 0:
        ((CountField *)client)->count = BTL_CLIENT_CollectOwnReceivedIds(client, client->pairs);
        if (((CountField *)client)->count != 0) {
            ableCount = BTL_CLIENT_ListAbleMons(client, partyOrder);
            if (ableCount != 0) {
                changeCount = ((CountField *)client)->count;
                if (changeCount > ableCount) changeCount = ableCount;
                if (BTL_CLIENT_IsDoubleBattleLeadAlive(client) != 0) {
                    leadMon = BTL_SLOT_GetPokeParam(client->sideData, 0);
                    if (ableCount == 1 && BTL_POKEPARAM_IsFainted(leadMon) != 0) {
                        BTL_ACTION_SetChange(client->actions, 0, partyOrder[0]);
                        client->sendData = (u8 *)client->actions;
                        client->sendSize = 4;
                        *state = 4;
                        break;
                    }
                }
                BTL_MAIN_GetSlotClientAndNth(client->main, client->pairs[0], &pairValues[1], &pairValues[0]);
                BTL_CLIENT_BuildSlotChoices(client, choiceMode, changeCount, client->slotChoices, client->choiceFlags);
                func_021E9A78(client->view, client->slotChoices, pairValues[0], 0, client->choiceFlags);
                BTL_CLIENT_StartTimeLimit(client);
                *state = 1;
            } else {
                if (BTL_CLIENT_IsDoubleBattleLeadAlive(client) != 0 && (rotateSize = BTL_CLIENT_TrySetRotateAction(client, client->actions)) != 0) {
                    client->sendSize = rotateSize;
                    client->sendData = (u8 *)client->actions;
                    *state = 4;
                } else {
                    BTL_ACTION_SetChangeDepleted(client->actions);
                    client->sendData = (u8 *)client->actions;
                    client->sendSize = 4;
                    *state = 4;
                }
            }
        } else {
            BTL_CALC_ActionSetNone(client->actions);
            client->sendData = (u8 *)client->actions;
            client->sendSize = 4;
            *state = 4;
        }
        break;
    case 1:
        if (BTL_CLIENT_PollTimeLimitReady(client) != 0) {
            func_021E9B14(client->view);
            *state = 2;
        } else if (func_021E9B20(client->view) != 0) {
            BTL_CLIENT_SetChangeActionsFromChoice(client, client->choiceFlags);
            *state = 3;
        }
        break;
    case 2:
        if (func_021E9B20(client->view) != 0) {
            BTL_CLIENT_SetChangeActionsFirstAble(client);
            *state = 3;
        }
        break;
    case 3:
        BTL_CLIENT_StopTimeLimit(client);
        *state = 4;
        break;
    case 4:
        if (BTL_MAIN_GetCommPos(client->main) != 0) {
            client->viewLocked = 1;
            func_021EA7FC(client->view);
            *state = 5;
        } else {
            *state = 6;
        }
        break;
    case 5:
        if (func_021EA814(client->view) != 0) {
            *state = 6;
        }
        break;
    case 6:
        return 1;
    }
    return 0;
}






/*
 * extent: compiled 42 bytes followed by two zero alignment bytes.
 */
int BTL_CLIENT_IsDoubleBattleLeadAlive(BtlClient *client)
{
    if (BTL_MAIN_GetRule(client->main) == 3 && BTL_POKEPARAM_IsFainted(BTL_SLOT_GetPokeParam(client->sideData, 0)) != 0) return 1;
    return 0;
}







int BTL_CLIENT_TrySetRotateAction(BtlClient *client, void *action)
{
    int position;

    position = 2;
    if (BTL_POKEPARAM_IsFainted(BTL_SLOT_GetPokeParam(client->sideData, (u8)(int)BTL_SLOT_GetRotateSrcIndex(2))) == 0) {
        BTL_ACTION_SetRotate(action, position);
        return 4;
    }
    position = 3;
    if (BTL_POKEPARAM_IsFainted(BTL_SLOT_GetPokeParam(client->sideData, (u8)(int)BTL_SLOT_GetRotateSrcIndex(3))) == 0) {
        BTL_ACTION_SetRotate(action, position);
        return 4;
    }
    return 0;
}



int BTL_CLIENT_StepAskSwitchBeforeSendOut(BtlClient *client, int *state)
{
    u8 *received;
    int answer;
    u8 chosenIndex;
    switch (*state) {
    case 0:
        BTL_ADAPTER_GetRecvData((int)client->netChannel, &received);
        if (received[0] != 0x1F) {
            func_021EAF18((struct L *)&client->messageA, 1, 0x14);
            func_021EAF50((struct L *)&client->messageA, 1);
            func_021EAF50((struct L *)&client->messageA, received[0]);
            func_021EAF78((u8 *)&client->messageA, 0xFF);
            func_021EA614(client->view, &client->messageA);
            *state = 1;
        } else *state = 4;
        break;
    case 1:
        func_021EA710(client->view);
        if (func_021EA720(client->view) != 0) {
            func_021EAF18((struct L *)&client->messageA, 3, 6);
            func_021EAF18((struct L *)&client->messageB, 3, 7);
            func_021EABC4(client->view, (u32)&client->messageA, (u32)&client->messageB, 1);
            *state = 2;
        }
        break;
    case 2:
        if (func_021EA710(client->view) != 0) {
            if (func_021EAC54(client->view, &answer) != 0) {
                if (answer == 0) {
                    BTL_CLIENT_BuildSlotChoices(client, 0, 1, client->slotChoices, client->choiceFlags);
                    func_021E9A78(client->view, client->slotChoices, 0, 0, client->choiceFlags);
                    *state = 3;
                } else *state = 4;
            }
        }
        break;
    case 3:
        if (func_021E9B20(client->view) != 0) {
            if (func_0689CB14(client->choiceFlags) == 0) {
                chosenIndex = func_0689CB1C(client->choiceFlags);
                if (chosenIndex != 0 && chosenIndex < 6) {
                    BTL_ACTION_SetChange(client->actions, 0, chosenIndex);
                    *state = 5;
                } else {
invalid:
                    *state = 4;
                }
            } else goto invalid;
        }
        break;
    case 4:
        BTL_CALC_ActionSetNone(client->actions);
        *state = 5;
    case 5:
        client->sendData = (u8 *)client->actions;
        client->sendSize = 4;
        return 1;
    }
    return 0;
}











int BTL_CLIENT_RecordReceivedPacket(BtlClient *client)
{
    u8 *packet;
    int packetSize = BTL_ADAPTER_GetRecvData((int)client->netChannel, &packet);
    if (client->timeLimitTimer != 0)
        BTL_REC_AppendPacket((u8 *)(client->timeLimitTimer), (const u8 *)packet, packetSize);
    if (client->requestParam != 0) {
        BTL_SERVER_LoadRecorderReplies((Obj_td *)client->requestParam, packet, packetSize);
        client->requestId = BTL_REC_GetPacketId((u8 *)packet);
    }
    return 1;
}










/*
 * extent: compiled 18 bytes followed by two zero alignment bytes.
 * interface: r2 loads p+0x54 before bl; retained as third argument even where callee does not read it.
 */
int BTL_CLIENT_StepShowResultIfView(BtlClient *client, int *state)
{
    void *q;
    q = client->view;
    if (q != 0) return BTL_CLIENT_StepShowResultMessage(client, state, q);
    return 1;
}









/*
 * lever: the 0x1B2 bit5 test is a byte bitfield, not a shifted integer mask.
 */
int BTL_CLIENT_StepShowResultMessage(BtlClient *client, int *state, void *view)
{
    int trainerIndex;
    int outcome;
    u8 isMultiMode;
    u16 messageId;
    switch (*state) {
    case 0:
        if (client->flags.bit.windowDone != 0)
            return 1;
        trainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 0);
        outcome = BTL_CLIENT_GetOutcomeForClient(client);
        isMultiMode = BTL_MAIN_IsMultiMode((unsigned char **)(client->main));
        BTL_MAIN_SetOutcomeIfUnset(client->main, outcome);
        switch (outcome) {
        case 1: messageId = isMultiMode != 0 ? 0x31 : 0x30; break;
        case 0: messageId = isMultiMode != 0 ? 0x33 : 0x32; break;
        case 2: messageId = isMultiMode != 0 ? 0x35 : 0x34; break;
        default: return 1;
        }
        func_021EAF18((struct L *)&client->messageA, 1, messageId);
        func_021EAF50((struct L *)&client->messageA, trainerIndex);
        if (isMultiMode != 0)
            func_021EAF50((struct L *)&client->messageA, BTL_MAIN_GetOwnOpponentClient(client->main, 1));
        func_021EA614(client->view, &client->messageA);
        if (outcome == 1) {
            GFL_USE_CancelChangeAndPlayBgm(BTL_MAIN_GetWinBgm(client->main), 0xFFFF);
            (*state)++;
        } else {
            GFL_USE_FadeOutBgm(0x1E);
            *state += 2;
        }
        break;
    case 1:
        if (func_021EA710(client->view) != 0)
            return 1;
        break;
    case 2:
        if (func_021EA710(client->view) != 0)
            (*state)++;
        break;
    case 3:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_CancelChangeAndStopBgm();
            return 1;
        }
        break;
    }
    return 0;
}









int BTL_CLIENT_GetOutcomeForClient(BtlClient *client)
{
    u16 *result;

    BTL_ADAPTER_GetRecvData((int)client->netChannel, (u8 **)&result);
    switch (result[1]) {
    case 0:
        if (BTL_MAIN_IsSameTeamClient((u8)result[0], client->clientId) == 0)
            return 1;
        break;
    case 1:
        if (BTL_MAIN_IsSameTeamClient((u8)result[0], client->clientId) == 0)
            return 0;
        break;
    }
    return result[1];
}







int BTL_CLIENT_StepShowTrainerResultIfView(BtlClient *client, int *state)
{
    void *q;
    q = client->view;
    if (q != 0) return BTL_CLIENT_StepShowTrainerResult(client, state, q);
    return 1;
}











int BTL_CLIENT_StepShowTrainerResult(BtlClient *client, int *state, void *view)
{
    int firstTrainerIndex;
    int secondTrainerIndex;

    switch (*state) {
    case 0:
        if (BTL_CLIENT_GetOutcomeForClient(client) == 1) {
            func_021F878C(BTL_MAIN_GetWinBgm(client->main));
            firstTrainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 0);
            secondTrainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 1);
            if (firstTrainerIndex == secondTrainerIndex) {
                func_021EAF18((struct L *)client->messageA.data, 1, 44);
                func_021EAF50((struct L *)client->messageA.data, firstTrainerIndex);
            } else {
                func_021EAF18((struct L *)client->messageA.data, 1, 45);
                func_021EAF50((struct L *)client->messageA.data, firstTrainerIndex);
                func_021EAF50((struct L *)client->messageA.data, secondTrainerIndex);
            }
            func_021EA614(client->view, client->messageA.data);
            *state = 1;
        } else if (BTL_MAIN_CheckSetupStatusFlag(client->main, 0x100) == 0) {
            firstTrainerIndex = BTL_MAIN_GetOwnClientId(client->main);
            func_021EAF18((struct L *)client->messageA.data, 1, 54);
            func_021EAF50((struct L *)client->messageA.data, firstTrainerIndex);
            func_021EAF50((struct L *)client->messageA.data, firstTrainerIndex);
            func_021EA614(client->view, client->messageA.data);
            *state = 9;
        } else {
            return 1;
        }
        break;
    case 1:
        if (func_021EA710(client->view)) {
            firstTrainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 0);
            func_021F7F58(BTL_MAIN_GetTrainerType(client->main, firstTrainerIndex), 9, 0, 0, 0);
            func_021F7998(0x270);
            *state = 2;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            firstTrainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 0);
            func_021EA6B0(client->view, BTL_MAIN_GetTrainerId(client->main, firstTrainerIndex), 1);
            *state = 3;
        }
        break;
    case 3:
        if (func_021EA710(client->view)) {
            firstTrainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 0);
            if (firstTrainerIndex != BTL_MAIN_GetOwnOpponentClient(client->main, 1)) {
                func_021F7998(0x271);
                *state = 4;
            } else {
                *state = 7;
            }
        }
        break;
    case 4:
        if (func_021F7EB4() == 0) {
            firstTrainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 1);
            func_021F7F58(BTL_MAIN_GetTrainerType(client->main, firstTrainerIndex), 9, 0, 0, 0);
            func_021F7998(0x270);
            *state = 5;
        }
        break;
    case 5:
        if (func_021F7EB4() == 0) {
            firstTrainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 1);
            func_021EA6B0(client->view, BTL_MAIN_GetTrainerId(client->main, firstTrainerIndex), 1);
            *state = 6;
        }
        break;
    case 6:
        if (func_021EA710(client->view))
            *state = 7;
        break;
    case 7:
        firstTrainerIndex = BTL_MAIN_GetPrizeMoney(client->main);
        if (firstTrainerIndex) {
            secondTrainerIndex = BTL_MAIN_GetOwnClientId(client->main);
            func_021EAF18((struct L *)client->messageA.data, 1, 58);
            func_021EAF50((struct L *)client->messageA.data, secondTrainerIndex);
            func_021EAF50((struct L *)client->messageA.data, firstTrainerIndex);
            func_021EA614(client->view, client->messageA.data);
        }
        if (BTL_MAIN_GetBonusMoney(client->main) == 0)
            *state = 11;
        else
            *state = 8;
        break;
    case 8:
        if (func_021EA710(client->view)) {
            firstTrainerIndex = BTL_MAIN_GetBonusMoney(client->main);
            if (firstTrainerIndex) {
                secondTrainerIndex = BTL_MAIN_GetOwnClientId(client->main);
                func_021EAF18((struct L *)client->messageA.data, 1, 59);
                func_021EAF50((struct L *)client->messageA.data, secondTrainerIndex);
                func_021EAF50((struct L *)client->messageA.data, firstTrainerIndex);
                func_021EA614(client->view, client->messageA.data);
            }
            *state = 11;
        }
        break;
    case 9:
        if (func_021EA710(client->view)) {
            firstTrainerIndex = BTL_MAIN_CalcPenaltyMoney(client->main);
            if (firstTrainerIndex) {
                func_021EAF18((struct L *)client->messageA.data, 1, 56);
                func_021EAF50((struct L *)client->messageA.data, client->clientId);
                func_021EAF50((struct L *)client->messageA.data, firstTrainerIndex);
                func_021EA614(client->view, client->messageA.data);
            }
            *state = 10;
        }
        break;
    case 10:
        if (func_021EA710(client->view)) {
            func_021EAF18((struct L *)client->messageA.data, 1, 57);
            func_021EAF50((struct L *)client->messageA.data, client->clientId);
            func_021EA614(client->view, client->messageA.data);
            *state = 11;
        }
        break;
    case 11:
        if (func_021EA710(client->view))
            return 1;
        break;
    default:
        return 1;
    }
    return 0;
}











/*
 * extent: compiled 18 bytes followed by two zero alignment bytes.
 * interface: r2 loads p+0x54 before bl; retained as third argument even where callee does not read it.
 */
int BTL_CLIENT_StepShowEndSpeechIfView(BtlClient *client, int *state)
{
    void *q;
    q = client->view;
    if (q != 0) return BTL_CLIENT_StepShowEndSpeech(client, state, q);
    return 1;
}











/*
 * lever: the 0x1B2 bit5 test is a byte bitfield, preserving the shift pair.
 */
int BTL_CLIENT_StepShowEndSpeech(BtlClient *client, int *state, void *view)
{
    u32 outcome;
    int trainerIndex;
    switch (*state) {
    case 0:
        if (client->flags.bit.windowDone != 0) return 1;
        outcome = BTL_CLIENT_GetOutcomeForClient(client);
        BTL_MAIN_SetOutcomeIfUnset(client->main, outcome);
        if (outcome == 1) func_021F878C(BTL_MAIN_GetWinBgm(client->main));
        if (outcome <= 1) {
            trainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 0);
            func_021F7F58(BTL_MAIN_GetTrainerType(client->main, trainerIndex), 9, 0, 0, 0);
            func_021F7998(0x270);
            BTL_CLIENT_ShowEndSpeech(client, outcome, 0);
            *state = 1;
        } else return 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021EA600(client->view);
            *state = 2;
        }
        break;
    case 2:
        if (func_021EA710(client->view) != 0) {
            trainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 0);
            if (trainerIndex == BTL_MAIN_GetOwnOpponentClient(client->main, 1)) return 1;
            func_021F7998(0x271);
            *state = 3;
        }
        break;
    case 3:
        if (func_021F7EB4() == 0) {
            outcome = BTL_CLIENT_GetOutcomeForClient(client);
            trainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 1);
            func_021F7F58(BTL_MAIN_GetTrainerType(client->main, trainerIndex), 9, 0, 0, 0);
            func_021F7998(0x270);
            BTL_CLIENT_ShowEndSpeech(client, outcome, 1);
            *state = 4;
        }
        break;
    case 4:
        if (func_021F7EB4() == 0) {
            func_021EA600(client->view);
            *state = 5;
        }
        break;
    case 5:
        if (func_021EA710(client->view) != 0) return 1;
        break;
    }
    return 0;
}











/*
 * Verified C for it (match.py one --thumb, no --region, EXACT, 20 bytes):
 *   int PMSI_PARAM_IsEnabled(u16 *p) { return *p != 0xffff; }
 */
void BTL_CLIENT_ShowEndSpeech(BtlClient *client, int outcome, int trainerSide)
{
    int trainerIndex;
    void *speech;
    void *speechText;
    int trainerId;

    trainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, trainerSide);
    speech = BTL_MAIN_GetTrainerSentence(client->main, trainerIndex, outcome);
    if (speech != 0 && PMSI_PARAM_IsEnabled(speech) != 0) {
        speechText = PMSI_PARAM_ToString(speech, (u16)((client->heapId & 0x7fff) | 0x8000));
        func_021EA5E4(client->view, speechText);
        STRBUF_Delete(speechText);
        return;
    }
    trainerId = BTL_MAIN_GetTrainerId(client->main, trainerIndex);
    if (trainerId != 0) {
        func_021EAF18((struct L *)client->messageA.data, 7, (int)0);
        func_021EAF50((struct L *)client->messageA.data, (int)trainerId);
        func_021EAF50((struct L *)client->messageA.data, (int)outcome);
        func_021EA5F0(client->view, client->messageA.data);
    }
}











int BTL_CLIENT_StepShowPrizeMoneyMessage(BtlClient *client, int *state)
{
    int a;
    int b;

    switch (*state) {
    case 0:
        if (BTL_MAIN_CheckSetupStatusFlag(client->main, 0x200) == 0) {
            a = BTL_MAIN_GetBonusMoney(client->main);
            if (a != 0) {
                b = BTL_MAIN_GetOwnClientId(client->main);
                func_021EAF18((struct L *)client->messageA.data, 1, 0x3b);
                func_021EAF50((struct L *)client->messageA.data, b);
                func_021EAF50((struct L *)client->messageA.data, a);
                func_021EA614(client->view, client->messageA.data);
            }
        }
        (*state)++;
    case 1:
        if (func_021EA710(client->view) != 0)
            return 1;
        break;
    }
    return 0;
}











int BTL_CLIENT_StepShowBlackoutMessages(BtlClient *client, int *state)
{
    int a;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)client->messageA.data, 1, 0x36);
        func_021EAF50((struct L *)client->messageA.data, client->clientId);
        func_021EA614(client->view, client->messageA.data);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(client->view) != 0) {
            a = BTL_MAIN_CalcPenaltyMoney(client->main);
            if (a != 0) {
                func_021EAF18((struct L *)client->messageA.data, 1, 0x37);
                func_021EAF50((struct L *)client->messageA.data, client->clientId);
                func_021EAF50((struct L *)client->messageA.data, a);
                func_021EA614(client->view, client->messageA.data);
            }
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA710(client->view) != 0) {
            func_021EAF18((struct L *)client->messageA.data, 1, 0x39);
            func_021EAF50((struct L *)client->messageA.data, client->clientId);
            func_021EA614(client->view, client->messageA.data);
            (*state)++;
        }
        break;
    case 3:
        if (func_021EA710(client->view) != 0)
            (*state)++;
        break;
    default:
        return 1;
    }
    return 0;
}











int BTL_CLIENT_StepShowFixedMessage(BtlClient *client, int *state)
{
    switch (*state) {
    case 0:
        func_021EAF18((struct L *)client->messageA.data, 1, 0xb7);
        func_021EA614(client->view, client->messageA.data);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(client->view) != 0)
            (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}









int BTL_CLIENT_StepRunServerCommandsIfView(BtlClient *client, int *state)
{
    void *q;
    q = client->view;
    if (q != 0) return BTL_CLIENT_StepRunServerCommands(client, state, q);
    return 1;
}









int BTL_CLIENT_StepRunServerCommands(BtlClient *client, int *state, void *view)
{
    u8 *packet;
    int packetSize;
    u16 packetLen;
    Buf_021CC768 *commandBuffer;
    u32 tableIndex;
    int commandCode;
again:
    switch (*state) {
    case 0:
        packetSize = BTL_ADAPTER_GetRecvData((int)client->netChannel, &packet);
        if (client->requestParam != 0 && client->requestId != 0 && client->flags.bit.requestSet != 0) {
            if (BTL_SERVER_CompareFlowOutput((u8 *)client->requestParam, client->requestId, packet, packetSize) != 0) {
                BTL_MAIN_SetRecordInvalid(client->main);
                client->flags.bit.requestSet = 0;
            }
            client->requestId = 0;
        }
        commandBuffer = client->workBuffer;
        packetLen = packetSize;
        func_02082A90(packet, commandBuffer->buf, packetLen);
        commandBuffer->wpos = packetLen;
        commandBuffer->rpos = 0;
        if (client->viewLocked != 0) {
            client->viewLocked = 0;
            func_021EA824(client->view);
        }
        (*state)++;
    case 1:
        commandBuffer = client->workBuffer;
        if (commandBuffer->rpos == commandBuffer->wpos) {
            *state = 4;
            return 1;
        }
        if (func_021D3F4C(client->commandQueue) != 0) return 1;
        (*state)++;
    case 2:
        commandCode = BTL_SERVER_CMD_ReadNext(client->workBuffer, (s32 *)client->seqCursorBuf);
        client->seqCode = commandCode;
        if (commandCode == 0x5E) return 1;
        for (tableIndex = 0; tableIndex < 0x5D; tableIndex++) {
            if (commandCode == gServerCommandHandlers[tableIndex].code) break;
        }
        if (tableIndex == 0x5D) {
            *state = 1;
            goto again;
        }
        client->seqFn = gServerCommandHandlers[tableIndex].fn;
        client->seqState = 0;
        (*state)++;
    case 3:
        if ((client->seqFn)(client, &client->seqState, (s32 *)client->seqCursorBuf) != 0) {
            *state = 1;
            goto again;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}








int BTL_CLIENT_StepShowRecallMessage(BtlClient *client, int *state, int *args)
{
    int addTrainerName;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)client->messageA.data, 1, BTL_CLIENT_PickRecallMessageId(client, args[0], &addTrainerName));
        if (addTrainerName != 0)
            func_021EAF50((struct L *)client->messageA.data, args[0]);
        func_021EAF50((struct L *)client->messageA.data, args[1]);
        func_021EA614(client->view, client->messageA.data);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(client->view) != 0)
            return 1;
        break;
    }
    return 0;
}











int BTL_CLIENT_PickRecallMessageId(BtlClient *client, u8 targetClient, int *addTrainerName)
{
    u32 hpDropPercent;

    if (targetClient == client->clientId) {
        *addTrainerName = 0;
        if (BTL_MAIN_GetRule(client->main) == 0 && BTL_MAIN_GetCommPos(client->main) == 0) {
            hpDropPercent = BTL_CLIENT_HasMonParamDropped(client);
            if (hpDropPercent >= 0x4b)
                return 0x1d;
            if (hpDropPercent > 0x32)
                return 0x1c;
            if (hpDropPercent > 0x19)
                return 0x1b;
            if (hpDropPercent != 0)
                return 0x1a;
            return 0x19;
        }
        return 0x1a;
    }
    *addTrainerName = 1;
    if (BTL_MAIN_IsTrainerSlotNpc(client->main, targetClient) != 0)
        return 0x1e;
    return 0x1f;
}











int BTL_CLIENT_StepPlayRecallAnim(BtlClient *client, int *state, int *args)
{
    switch (*state) {
    case 0:
        func_021EA458(client->view, BTL_MAIN_GetViewPosOfSlot(client->main, (u8)args[0]), (u16)args[1]);
        (*state)++;
        break;
    case 1:
        if (func_021EA478(client->view) != 0)
            return 1;
        break;
    }
    return 0;
}









static inline void showMessageWithIds(BtlClient *client, int code, u32 value, u32 id)
{
    func_021EAF18((struct L *)&client->messageA, 1, code);
    func_021EAF50((struct L *)&client->messageA, value);
    func_021EAF50((struct L *)&client->messageA, id);
    func_021EA614(client->view, &client->messageA);
}









/*
 * lever: append-id and send are written in every message arm; the inline
 * helper includes that tail. Factoring it outside the conditional merges
 * the initialisation call too early and loses 16 bytes.
 */
int BTL_CLIENT_StepSendOutMon(BtlClient *client, int *state, const u32 *params)
{
    u8 side = params[0];
    u8 position = params[1];
    u8 showMessage = params[3];
    u8 pokeId;
    switch (*state) {
    case 0:
        if (showMessage != 0) {
            pokeId = BTL_POKEPARAM_GetPokeId(BTL_SIDE_GetClientPoke(client->side, side, position));
            if (BTL_MAIN_IsOpposingPos((int)(client->main), client->clientId, side) == 0) {
                if (client->clientId == side) {
                    func_021EAF18((struct L *)&client->messageA, 1, BTL_CLIENT_PickSendOutMessageId(client));
                    func_021EAF50((struct L *)&client->messageA, pokeId);
                    func_021EA614(client->view, &client->messageA);
                } else {
                    showMessageWithIds(client, 0x11, side, pokeId);
                }
            } else if (BTL_MAIN_IsTrainerSlotNpc(client->main, side) != 0) {
                showMessageWithIds(client, 0xE, side, pokeId);
            } else {
                showMessageWithIds(client, 0x11, side, pokeId);
            }
        }
        (*state)++;
        break;
    case 1:
        if (func_021EA710(client->view) != 0) {
            func_021EA488(client->view, BTL_MAIN_GetClientTrainerIndex(client->main, side, position), side, position);
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA4C4(client->view) != 0) {
            BTL_CLIENT_StoreMonParam(client);
            return 1;
        }
        break;
    }
    return 0;
}









int BTL_CLIENT_PickSendOutMessageId(BtlClient *client)
{
    u8 *leadMon;
    u8 position;
    int hpRatio;

    if (BTL_MAIN_GetRule(client->main) == 0) {
        position = BTL_MAIN_GetOpponentClient(client->main, client->clientId, 0);
        leadMon = BTL_SIDE_GetClientPoke(client->side, position, 0);
        if (BTL_POKEPARAM_IsFainted(leadMon) != 0)
            return 0xb;
        hpRatio = BTL_POKEPARAM_GetHpRatioFixed((struct Rat *)leadMon);
        if (hpRatio >= 0x4d800)
            return 0xb;
        if (hpRatio >= 0x37000)
            return 0x15;
        if (hpRatio >= 0x20800)
            return 0x16;
        if (hpRatio >= 0xa000)
            return 0x17;
        return 0x18;
    }
    return 0xb;
}









int BTL_CLIENT_StepShowSideMessage(BtlClient *client, int *state, u32 *args)
{
    switch (*state) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(client)) {
            return 1;
        }
        func_021EA678(client->view, args[0], (int *)(args + 1));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}









int BTL_CLIENT_StepShowSideMessageWithSound(BtlClient *client, int *state, u32 *args)
{
    switch (*state) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(client)) {
            return 1;
        }
        func_021EA678(client->view, args[0], (int *)(args + 2));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA720(client->view)) {
            GFL_USE_PlaySeDefaultVolume(args[1]);
        }
        if (func_021EA710(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}









int BTL_CLIENT_StepShowTaggedMessage(BtlClient *client, int *state, u32 *args)
{
    switch (*state) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(client)) {
            return 1;
        }
        func_021EA694(client->view, args[0], (int *)(args + 1));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}









int BTL_CLIENT_StepShowTaggedMessageWithSound(BtlClient *client, int *state, u32 *args)
{
    switch (*state) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(client)) {
            return 1;
        }
        func_021EA694(client->view, args[0], (int *)(args + 2));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA720(client->view)) {
            GFL_USE_PlaySeDefaultVolume(args[1]);
        }
        if (func_021EA710(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}








int BTL_CLIENT_StepShowItemUseMessage(BtlClient *client, int *state, u32 *args)
{
    switch (*state) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(client)) {
            return 1;
        }
        func_021EA6F4(client->view, args[0], args[1]);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}








/*
 * Unlabelled leaf (filed for the blocker of BTL_CLIENT_StepPlayMoveAnim, lane S15).
 */
u32 BTL_CLIENT_GetMoveAnimTarget(BtlClient *client, u32 moveId, u8 attackerId)
{
    u8 *attacker;

    if (moveId != 0xAE) {
        return WAZA_TOOL_GetParam(moveId, 0x1B);
    }
    attacker = BTL_SIDE_GetPokeAtPos((char *const *)client->side, attackerId);
    if (attacker) {
        return BTL_CALC_GetCurseTargetKind(attacker);
    }
    return WAZA_TOOL_GetParam(moveId, 0x1B);
}









/*
 * lever: word locals with casts at the four descriptor loads, t2 before v
 * in declaration order, and a named nested-call result keep v in r7 and
 * t1/t2 in the original spill slots. The u8 b in the callee's own source
 * is widened here: the original caller has no second truncation after v.
 */
int BTL_CLIENT_StepPlayMoveAnim(BtlClient *client, int *state, const u32 *args)
{
    u32 moveId;
    u8 attackerId;
    u32 defenderId;
    u32 hitFlag;
    u32 targetKind;
    switch (*state) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(client)) {
            return 1;
        }
        if (BTL_MAIN_CheckSceneOff((unsigned char *)client->main)) {
            attackerId = (u8)args[0];
            defenderId = (u8)args[1];
            moveId = (u16)args[2];
            hitFlag = (u8)args[3];
            targetKind = BTL_CLIENT_GetMoveAnimTarget(client, moveId, attackerId);
            func_021EA0A0(client->view, attackerId, defenderId, moveId, targetKind, hitFlag, 0);
            *state = *state + 1;
        } else {
            return 1;
        }
        break;
    case 1:
        if (func_021EA0E4(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}










int BTL_CLIENT_StepSetMonVisibility(BtlClient *client, int *state, u32 *args)
{
    u32 t;

    switch (*state) {
    case 0:
        t = (u32)BTL_MAIN_GetViewPosOfPoke((unsigned char *)client->main, client->side, (u8)args[0]);
        func_021EA354(client->view, t, args[1] != 0);
        *state = *state + 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            return 1;
        }
        return 0;
    }
    return 0;
}










int BTL_CLIENT_StepPlayMonTaskAnim(BtlClient *client, int *state, u32 *args)
{
    int t;

    switch (*state) {
    case 0:
        t = BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)args[0]);
        func_021EA0F4(client->view, (u16)args[2], t, (u8)args[1]);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA120(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}










int BTL_CLIENT_StepPlayMultiMonAnim(BtlClient *client, int *state, u32 *args)
{
    u8 monIds[8];
    u8 i;
    u16 monCount;
    u32 param;
    u16 soundId;

    switch (*state) {
    case 0:
        monCount = args[0];
        param = args[1];
        soundId = args[2];
        for (i = 0; i < monCount; i++) {
            monIds[i] = BTL_SERVER_CMD_ReadU8Wrapper(client->workBuffer);
        }
        func_021EA280(client->view, monCount, param, monIds, soundId);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA2BC(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}










int BTL_CLIENT_StepUpdateMonGaugeThenMessage(BtlClient *client, int *state, u32 *args)
{
    switch (*state) {
    case 0:
        func_021EA384(client->view, BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)args[0]));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA3A0(client->view)) {
            func_021EA678(client->view, 0x61, (int *)args);
            *state = *state + 1;
        }
        break;
    case 2:
        if (func_021EA710(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}










int BTL_CLIENT_StepStartEffectForMon(BtlClient *client, int *state, u32 *args)
{
    int t;

    switch (*state) {
    case 0:
        t = BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)args[0]);
        func_021F81D0(args[1], BTL_MAIN_GetViewPosOfSlot(client->main, t));
        *state = *state + 1;
        break;
    case 1:
        return 1;
    }
    return 0;
}









int BTL_CLIENT_StepPlaySubstituteAnim(BtlClient *client, int *state, u32 *args)
{
    int t;

    switch (*state) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(client) == 0) {
            t = BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)args[0]);
            func_021EA0A0(client->view, t, t, 1, WAZA_TOOL_GetParam(1, 0x1B), 0, 0);
        }
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA0E4(client->view)) {
            t = BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)args[0]);
            if (BTL_CLIENT_IsMainStepActive(client) == 0) {
                GFL_USE_PlaySeDefaultVolume(0x564);
            }
            func_021EA0F4(client->view, 1, t, 1);
            *state = *state + 1;
        }
        break;
    case 2:
        if (func_021EA120(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}









int BTL_CLIENT_StepFaintMon(BtlClient *client, int *state, u32 *args)
{
    switch (*state) {
    case 0:
        func_021EA40C(client->view, BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)(*args)));
        (*state)++;
        break;
    case 1:
        if (func_021EA428(client->view)) {
            BTL_POKEPARAM_ResetAllEffects(BTL_SIDE_GetPokeByIdThunk(client->side, (u8)(*args)));
            return 1;
        }
        break;
    }
    return 0;
}









int BTL_CLIENT_StepReviveMon(BtlClient *client, int *state, u32 *args)
{
    switch (*state) {
    case 0:
        func_021EA438(client->view, BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)(*args)));
        (*state)++;
        break;
    case 1:
        if (func_021EA448(client->view))
            return 1;
        break;
    }
    return 0;
}









int BTL_CLIENT_StepPlayMonEffect262(BtlClient *client, int *state, u32 *args)
{
    u32 t = BTL_MAIN_GetViewPosOfSlot(client->main, BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)(*args)));

    switch (*state) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(client))
            return 1;
        if (!BTL_MAIN_CheckSceneOff(client->main))
            return 1;
        func_021EA7C8(client->view, t);
        (*state)++;
        break;
    case 1:
        if (func_021EA7E8(client->view, t))
            return 1;
        break;
    }
    return 0;
}









int BTL_CLIENT_StepPlayMonEffect261(BtlClient *client, int *state, u32 *args)
{
    u32 t = BTL_MAIN_GetViewPosOfSlot(client->main, BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)(*args)));

    switch (*state) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(client))
            return 1;
        if (!BTL_MAIN_CheckSceneOff(client->main))
            return 1;
        func_021EA7D8(client->view, t);
        (*state)++;
        break;
    case 1:
        if (func_021EA7E8(client->view, t))
            return 1;
        break;
    }
    return 0;
}









int BTL_CLIENT_StepStartWeather(BtlClient *client, int *state, u32 *args)
{
    u8 weatherId = args[0];

    switch (*state) {
    case 0:
        BTL_FIELD_StoreCountdown(client->battleField, (u8)weatherId, (u16)args[1]);
        if (BTL_CLIENT_IsMainStepActive(client))
            return 1;
        if (weatherId < 5)
            func_021F7998(gWeatherEffects[weatherId].b);
        (*state)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            func_021EA678(client->view, gWeatherEffects[weatherId].a, 0);
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA710(client->view))
            return 1;
        break;
    }
    return 0;
}









int BTL_CLIENT_StepEndWeather(BtlClient *client, int *state, u32 *args)
{
    u16 messageId;

    switch (*state) {
    case 0:
        switch ((u8)args[0]) {
        case 1:
            messageId = 0x59;
            break;
        case 2:
            messageId = 0x5a;
            break;
        case 4:
            messageId = 0x5b;
            break;
        case 3:
            messageId = 0x5c;
            break;
        default:
            return 1;
        }
        func_021EA678(client->view, messageId, 0);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(client->view)) {
            BTL_FIELD_ClearCountdown(client->battleField);
            return 1;
        }
        break;
    }
    return 0;
}









int BTL_CLIENT_StepUpdateMonGauge(BtlClient *client, int *state, u32 *args)
{
    switch (*state) {
    case 0:
        func_021EA384(client->view, BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)(*args)));
        (*state)++;
        break;
    case 1:
        if (func_021EA3A0(client->view))
            return 1;
        break;
    }
    return 0;
}









int BTL_CLIENT_StepPlayMonAnim(BtlClient *client, int *state, u32 *args)
{
    int t = BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)(*args));

    switch (*state) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(client))
            return 1;
        if (!BTL_MAIN_CheckSceneOff(client->main))
            return 1;
        func_021EA838(client->view, t);
        (*state)++;
        break;
    case 1:
        if (func_021EA850(client->view, t))
            return 1;
        break;
    }
    return 0;
}









int BTL_CLIENT_StepUpdateMonGaugeCopy(BtlClient *client, int *state, u32 *args)
{
    u8 id = *args;

    switch (*state) {
    case 0:
        func_021EA384(client->view, BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, id));
        (*state)++;
        break;
    case 1:
        if (func_021EA3A0(client->view))
            return 1;
        break;
    }
    return 0;
}









int BTL_CLIENT_StepRotatePositions(BtlClient *client, int *state, u32 *args)
{
    switch (*state) {
    case 0: {
        u8 side = args[0];
        u8 fromIndex = args[1];
        u8 toIndex = args[2];
        int fromPosition = BTL_MAIN_GetSlotNthOfClient(client->main, fromIndex);
        int toPosition = BTL_MAIN_GetSlotNthOfClient(client->main, toIndex);
        u32 fromTrainer = BTL_MAIN_GetViewPosOfSlot(client->main, fromIndex);
        u32 toTrainer = BTL_MAIN_GetViewPosOfSlot(client->main, toIndex);
        BTL_SLOT_Swap((u32 *)BTL_SIDE_GetSlotOfClient(client->side, side), fromPosition, toPosition);
        func_021EA904(client->view, side, fromTrainer, toTrainer, fromPosition, toPosition);
        (*state)++;
        break;
    }
    case 1:
        if (func_021EA950(client->view))
            return 1;
        break;
    }
    return 0;
}








int BTL_CLIENT_StepRotatePositionsTwice(BtlClient *client, int *state, u32 *args)
{
    switch (*state) {
    case 0:
        func_021F7998(0x281);
        (*state)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            u8 side = args[0], fromIndex = args[1];
            u32 trainerIndexA, trainerIndexB, trainerA, trainerB;
            trainerIndexA = BTL_MAIN_GetClientTrainerIndex(client->main, side, fromIndex);
            trainerIndexB = BTL_MAIN_GetClientTrainerIndex(client->main, side, 1);
            trainerA = BTL_MAIN_GetViewPosOfSlot(client->main, trainerIndexA);
            trainerB = BTL_MAIN_GetViewPosOfSlot(client->main, trainerIndexB);
            BTL_SLOT_Swap((u32 *)BTL_SIDE_GetSlotOfClient(client->side, side), fromIndex, 1);
            func_021EA904(client->view, side, trainerA, trainerB, fromIndex, 1);
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA950(client->view)) {
            u8 side = args[2], fromIndex = args[3];
            u32 trainerIndexA, trainerIndexB, trainerA, trainerB;
            trainerIndexA = BTL_MAIN_GetClientTrainerIndex(client->main, side, fromIndex);
            trainerIndexB = BTL_MAIN_GetClientTrainerIndex(client->main, side, 1);
            trainerA = BTL_MAIN_GetViewPosOfSlot(client->main, trainerIndexA);
            trainerB = BTL_MAIN_GetViewPosOfSlot(client->main, trainerIndexB);
            BTL_SLOT_Swap((u32 *)BTL_SIDE_GetSlotOfClient(client->side, side), fromIndex, 1);
            func_021EA904(client->view, side, trainerA, trainerB, fromIndex, 1);
            (*state)++;
        }
        break;
    case 3:
        if (func_021EA950(client->view)) return 1;
        break;
    }
    return 0;
}








/*
 * evidence: Thumb 01 49 02 4b 18 47 c0 46; pools 0x26e and 0x021F7A29. No ARM9/SDK blocker work.
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021F7E94 is an ov094 Thumb tail stub (pool 0x26E, 0x021F7A29); other overlay, not filed. Integrator: seed label.
 */
int BTL_CLIENT_StepPlayEffectOnMon(BtlClient *client, int *state, unsigned int *args)
{
    switch (*state) {
    case 0:
        func_021F7E94((u8)BTL_MAIN_GetViewPosOfSlot(client->main, (u8)args[0]));
        (*state)++;
        break;
    case 1:
        if (func_021F7EB4() == 0) return 1;
        break;
    }
    return 0;
}









int BTL_CLIENT_StepPlayEffectOnMonFast(BtlClient *client, int *state, u32 *args)
{
    switch (*state) {
    case 0: {
        u32 t = BTL_MAIN_GetViewPosOfSlot(client->main, (u8)(*args));
        if (BTL_CLIENT_IsMainStepActive(client))
            func_021F88BC(1);
        func_021F7EA4(t);
        (*state)++;
        break;
    }
    case 1:
        if (!func_021F7EB4()) {
            if (BTL_CLIENT_IsMainStepActive(client))
                func_021F88BC(0);
            return 1;
        }
        break;
    }
    return 0;
}









int BTL_CLIENT_StepTransformMon(BtlClient *client, int *state, u32 *args)
{
    switch (*state) {
    case 0: {
        u8 *sourceMon = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
        u8 *targetMon = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[1]);
        int sourceSlot = (int)BTL_MAIN_GetViewPosOfPoke(client->main, client->side, (u8)args[0]);
        int targetSlot = (int)BTL_MAIN_GetViewPosOfPoke(client->main, client->side, (u8)args[1]);
        BTL_POKEPARAM_Transform((struct Unk021D6C50 *)sourceMon, (struct Unk021D6C50 *)targetMon);
        func_021EA8B4(client->view, sourceSlot, targetSlot);
        (*state)++;
        break;
    }
    case 1:
        if (func_021EA8D4(client->view))
            return 1;
        break;
    }
    return 0;
}








int BTL_CLIENT_StepPlayHitEffect(BtlClient *client, int *state, u32 *args)
{
    int monSlot;

    switch (*state) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(client) == 0) {
            monSlot = BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)args[0]);
            func_021EA1B8(client->view, (u16)args[2], monSlot, BTL_CALC_SummarizeTypeAffinity(args[1]));
            (*state)++;
            break;
        }
        return 1;
    case 1:
        if (func_021EA1F0(client->view) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}








int BTL_CLIENT_StepChangeBgm(int unusedClient, int unusedState, int *bgmId)
{
    func_021F878C(*bgmId);
    return 1;
}







int BTL_CLIENT_StepPlayViewSequence(BtlClient *client, int *state)
{
    switch (*state) {
    case 0:
        func_021EA8E4(client->view);
        (*state)++;
        break;
    case 1:
        if (func_021EA8F4(client->view) != 0) return 1;
        break;
    }
    return 0;
}







int BTL_CLIENT_StepAddEffortValues(BtlClient *client, int unusedState, u32 *args)
{
    void *mon;
    u32 statIndex;
    int paramId;
    u32 newValue;

    mon = BTL_POKEPARAM_GetMon(BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]));
    for (statIndex = 0; statIndex < 6; statIndex++) {
        if (gEffortValueParams[statIndex + 1] != 0) {
            paramId = gEffortValueParams[statIndex];
            newValue = args[statIndex + 1] + func_02017E1C(mon, paramId, 0);
            if (newValue > 0xff) {
                newValue = 0xff;
            }
            POKE_TOOL_SetPartyValue(mon, paramId, newValue);
        }
    }
    return 1;
}






/*
 * evidence: 43/43 relocations resolved after parent-coordinated overlay
 * leaf witnesses; all ARM9 calls resolve without new ARM9 files.
 * lever: int id loaded via (u8) cast fixes spill slots; widening the
 * BTL_MAIN_GetViewPosOfPoke third extern parameter removes absent call truncation.
 * StateData fields keep counter updates on one global base.
 */
int BTL_CLIENT_StepGiveExp(BtlClient *client, int *state, u32 *args)
{
    void *pokeParam;
    int pokeId;
    int monSlot;
    int gaugeActive;
    u32 expRemaining;
    pokeId = (u8)args[0];
    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, pokeId);
    monSlot = BTL_MAIN_GetViewPosOfPoke(client->main, client->side, pokeId);
    gaugeActive = 0;
    if (monSlot != 0xff && func_021F8204(monSlot)) gaugeActive = 1;
    switch (*state) {
    case 0:
        gExpGainWork.s.remaining = args[1];
        gExpGainWork.s.counter = 0;
        *state = 1;
    case 1:
        if (gExpGainWork.s.remaining) {
            expRemaining = gExpGainWork.s.remaining;
            if (BTL_POKEPARAM_AddExp(pokeParam, &expRemaining, (struct Result *)gExpGainWork.s.result)) {
                *state = 3;
            } else {
                if (gaugeActive) {
                    func_021F8134(monSlot, gExpGainWork.s.remaining);
                    *state = 2;
                } else *state = 13;
                expRemaining = 0;
            }
            gExpGainWork.s.remaining = expRemaining;
        } else *state = 13;
        break;
    case 2:
        if (!func_021F8180()) *state = 13;
        break;
    case 3:
        BTL_EVENT_ReleaseClientHandle(pokeParam);
        BTL_POKEPARAM_ReloadFromParam(pokeParam);
        if (gaugeActive) {
            func_021F8150(monSlot, pokeParam);
            *state = 4;
        } else *state = 6;
        break;
    case 4:
        if (!func_021F8180() && !GFL_USE_IsAnySeBusy()) {
            func_021EA3B8(client->view, monSlot, 0x25d);
            *state = 5;
        }
        break;
    case 5:
        if (func_021EA3D4(client->view)) *state = 6;
        break;
    case 6:
        func_021EAF18((struct L *)&client->messageA, 1, 0x3c);
        func_021EAF50((struct L *)&client->messageA, (int)pokeId);
        func_021EAF50((struct L *)&client->messageA, (int)gExpGainWork.s.result[0]);
        func_021EA614(client->view, &client->messageA);
        *state = 7;
        break;
    case 7:
        if (func_021EA720(client->view)) {
            GFL_USE_SetBgmPlayerParam((void *)1);
            GFL_USE_PushBgm();
            GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        }
        if (func_021EA710(client->view) && !GFL_USE_IsBgmPlaying()) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPlayerParam(0);
            gExpGainWork.s.counter = 0;
            *state = 8;
        }
        break;
    case 8:
        gExpGainWork.s.counter++;
        if ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg() || gExpGainWork.s.counter > 80) {
            gExpGainWork.s.counter = 0;
            BTL_MAIN_NotifyLevelUp(client->main, pokeParam);
            func_021EADA4(client->view, (int)pokeParam, gExpGainWork.s.result);
            *state = 9;
        }
        break;
    case 9:
        if (func_021EADB4(client->view) && ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg())) {
            func_021EADC4(client->view);
            *state = 10;
        }
        break;
    case 10:
        if (func_021EADD4(client->view) && ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg())) {
            func_021EADE4(client->view);
            *state = 11;
        }
        break;
    case 11:
        if (func_021EADF4(client->view)) {
            gExpGainWork.s.counter = 0;
            *state = 12;
        }
        break;
    case 12:
        if (BTL_CLIENT_StepLearnLevelUpMoves(client, &gExpGainWork.s.counter, pokeParam)) *state = 1;
        break;
    case 13:
        BTL_MAIN_CopyLiveToSnapshotPoke(client->main, pokeId);
        return 1;
    }
    return 0;
}





int BTL_CLIENT_ForgetMoveSoundCallback(int step)
{
    switch (step) {
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x56b);
        break;
    case 5:
        if (GFL_USE_IsSeqPlaying(0x56b) != 0) return 1;
        break;
    }
    return 0;
}






int BTL_CLIENT_StepLearnLevelUpMoves(BtlClient *client, int *state, void *mon)
{
    int pokeId = BTL_POKEPARAM_GetPokeId(mon);

    switch (*state) {
    case 0:
        g_021F3B64.iter = 0;
        g_021F3B64.move = 0;
        *state = 1;
    case 1:
        g_021F3B64.move = POKE_TOOL_GetLevelUpMove(BTL_POKEPARAM_GetMon(mon), &g_021F3B64.iter, client->heapId);
        if (g_021F3B64.move == 0)
            return 1;
        if (g_021F3B64.move == 0xFFFE)
            break;
        if (g_021F3B64.move & 0x8000) {
            g_021F3B64.move &= 0x7FFF;
            *state = 5;
        } else {
            *state = 2;
        }
        break;
    case 2: {
        void *p = BTL_SIDE_GetPokeByIdThunk(client->side, pokeId);
        BTL_POKEPARAM_GetMon(p);
        BTL_POKEPARAM_ReloadFromParam(p);
        func_021EAF18((struct L *)(&client->messageA), 5, 3);
        func_021EAF50((struct L *)(&client->messageA), pokeId);
        func_021EAF50((struct L *)(&client->messageA), g_021F3B64.move);
        func_021EA614(client->view, (&client->messageA));
        *state = 3;
    }
    case 3:
        if (func_021EA720(client->view)) {
            GFL_USE_SetBgmPlayerParam((void *)1);
            GFL_USE_PushBgm();
            GFL_USE_CancelChangeAndPlayBgm(0x515, 0xFFFF);
        }
        if (func_021EA710(client->view))
            *state = 4;
        break;
    case 4:
        if (GFL_USE_IsBgmPlaying() == 0) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPlayerParam(0);
            *state = 1;
        }
        break;
    case 5:
        func_021EAF18((struct L *)(&client->messageA), 5, 4);
        func_021EAF50((struct L *)(&client->messageA), pokeId);
        func_021EAF50((struct L *)(&client->messageA), g_021F3B64.move);
        func_021EAF78((u8 *)(&client->messageA), 255);
        func_021EA614(client->view, (&client->messageA));
        *state = 6;
    case 6:
        if (func_021EA720(client->view)) {
            BtlClientMessage yes, no;
            func_021EAF18((struct L *)(&yes), 6, 2);
            func_021EAF18((struct L *)(&no), 6, 3);
            func_021EABC4(client->view, (u32)(&yes), (u32)(&no), 1);
        }
        if (func_021EA710(client->view))
            *state = 7;
        break;
    case 7: {
        int sel;
        if (func_021EAC54(client->view, &sel)) {
            if (sel == 0) {
                func_021EAC64(client->view, BTL_SLOT_FindPokeId((u8 *)BTL_SIDE_GetSlotOfClientThunk(client->side, client->clientId), pokeId), g_021F3B64.move);
                *state = 8;
            } else {
                *state = 10;
            }
        }
        break;
    }
    case 8: {
        u8 slot;
        void *pp;
        u16 old;
        if (func_021EAC80(client->view, &slot) == 0)
            break;
        if (slot == 4) {
            *state = 5;
            break;
        }
        pp = BTL_POKEPARAM_GetMon(BTL_SIDE_GetPokeByIdThunk(client->side, pokeId));
        old = func_02017E1C(pp, slot + 54, 0);
        func_020181F4(pp, g_021F3B64.move, slot);
        func_021EAF18((struct L *)(&client->messageA), 5, 5);
        func_021EAF50((struct L *)(&client->messageA), pokeId);
        func_021EAF50((struct L *)(&client->messageA), old);
        func_021EA638(client->view, (&client->messageA), (int)((void (*)(void))BTL_CLIENT_ForgetMoveSoundCallback));
        *state = 9;
        break;
    }
    case 9:
        if (func_021EA710(client->view))
            *state = 2;
        break;
    case 10:
        func_021EAF18((struct L *)(&client->messageA), 5, 7);
        func_021EAF50((struct L *)(&client->messageA), pokeId);
        func_021EAF50((struct L *)(&client->messageA), g_021F3B64.move);
        func_021EAF78((u8 *)(&client->messageA), 255);
        func_021EA614(client->view, (&client->messageA));
        *state = 11;
        break;
    case 11:
        if (func_021EA720(client->view)) {
            BtlClientMessage yes, no;
            func_021EAF18((struct L *)(&yes), 6, 4);
            func_021EAF50((struct L *)(&yes), g_021F3B64.move);
            func_021EAF18((struct L *)(&no), 6, 5);
            func_021EAF50((struct L *)(&no), g_021F3B64.move);
            func_021EABC4(client->view, (u32)(&yes), (u32)(&no), 1);
        }
        if (func_021EA710(client->view))
            *state = 12;
        break;
    case 12: {
        int sel;
        if (func_021EAC54(client->view, &sel)) {
            if (sel == 0) {
                func_021EAF18((struct L *)(&client->messageA), 5, 8);
                func_021EAF50((struct L *)(&client->messageA), pokeId);
                func_021EAF50((struct L *)(&client->messageA), g_021F3B64.move);
                func_021EA614(client->view, (&client->messageA));
                *state = 13;
            } else {
                *state = 5;
            }
        }
        break;
    }
    case 13:
        if (func_021EA710(client->view))
            *state = 1;
        break;
    }
    return 0;
}





/*
 * lever: const on the read-only descriptor schedules c[1] before the
 * stack-argument store in the first arm.
 */
int BTL_CLIENT_StepThrowBall(BtlClient *client, int *state, const u32 *args)
{
    switch (*state) {
    case 0:
        func_021F7CFC(BTL_MAIN_GetViewPosOfSlot(client->main, (u8)args[0]), (u16)args[5], (u8)args[1], args[2], args[4]);
        (*state)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            if (args[2]) {
                u8 *pokeParam = BTL_SIDE_GetPokeAtPos((char *const *)client->side, (u8)args[0]);
                func_021EAF18((struct L *)((u8 *)&client->messageA), 1, 0x41);
                func_021EAF50((struct L *)((u8 *)&client->messageA), BTL_POKEPARAM_GetPokeId(pokeParam));
                func_021F883C(0x518);
            } else {
                int messageId;
                if (args[1] < 4) messageId = gCatchShakeMessages[args[1]];
                else messageId = 0x3d;
                func_021EAF18((struct L *)((u8 *)&client->messageA), 1, messageId);
            }
            func_021EA614(client->view, ((u8 *)&client->messageA));
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA710(client->view)) {
            if (args[2]) {
                BTL_MAIN_NotifyCapture((u32)(client->main), (u32 *)BTL_SIDE_GetPokeAtPos((char *const *)client->side, (u8)args[0]));
                (*state)++;
            } else return 1;
        }
        break;
    case 3:
        if (!GFL_USE_IsBgmPlaying()) {
            func_021F7C0C();
            GFL_USE_CancelChangeAndPlayBgm(0x47c, 0xffff);
            BTL_MAIN_SetKeepBgm(client->main);
            if (args[3]) {
                u8 *pokeParam = BTL_SIDE_GetPokeAtPos((char *const *)client->side, (u8)args[0]);
                func_021EAF18((struct L *)((u8 *)&client->messageA), 1, 0x42);
                func_021EAF50((struct L *)((u8 *)&client->messageA), BTL_POKEPARAM_GetPokeId(pokeParam));
                func_021EA614(client->view, ((u8 *)&client->messageA));
                (*state)++;
            } else return 1;
        }
        break;
    case 4:
        if (func_021EA710(client->view)) (*state)++;
        break;
    default:
        return 1;
    }
    return 0;
}






int BTL_CLIENT_StepShowBallBlocked(BtlClient *client, int *state, u32 *args)
{
    switch (*state) {
    case 0:
        func_021F7D44(BTL_MAIN_GetViewPosOfSlot(client->main, (u8)args[0]), (u16)args[1]);
        (*state)++;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021EAF18((struct L *)((u8 *)&client->messageA), 1, 0x43);
            func_021EA614(client->view, ((u8 *)&client->messageA));
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA710(client->view) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}






static inline u16 selectSideEndMessageId(u32 u, u32 k)
{
    if (u == 3) {
        return (k != 0) ? 0x26 : 0x27;
    }
    return (k != 0) ? 0x28 : 0x29;
}






/*
 * Levers: the 0x26..0x29 selection is a `static inline u16` helper returning nested
 * ternaries; inlined, its result stays in r0 and each arm branches (the inner join of the
 * u == 3 arm is the unthreaded `b` hop). Written in the caller (ternary, if/else, nested
 * ternary, call in each arm) it is if-converted into r1, and a plain `static` helper is
 * not inlined. `u` is `int` (permuter: u32 put c[1] first into r7 in case 0).
 */
int BTL_CLIENT_StepClearSidePosition(BtlClient *client, int *state, u32 *args)
{
    u8 kind;
    int side;
    u8 isPlayerSide;
    char *sideEntry;

    switch (*state) {
    case 0:
        side = (u8)args[0];
        kind = (u8)args[1];
        sideEntry = BTL_SIDE_GetSlotOfClient(client->side, side);
        BTL_SLOT_Rotate((u8 **)sideEntry, kind, 0, 0);
        func_021EAA6C((u32)client->view, side, kind);
        (*state)++;
        break;
    case 1:
        if (func_021EAAD8((u32)client->view) != 0) {
            side = (u8)args[1];
            if (side == 1) {
                return 1;
            }
            isPlayerSide = BTL_MAIN_IsTrainerSlotNpc(client->main, (u8)args[0]);
            func_021EA678(client->view, selectSideEndMessageId(side, isPlayerSide), (int *)args);
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA710(client->view) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}






int BTL_CLIENT_StepSetAbilityWithPopup(BtlClient *client, int *state, u32 *args)
{
    u32 pokeId;
    int monSlot;

    pokeId = (u8)args[0];
    monSlot = BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, pokeId);
    switch (*state) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(client) != 0) {
            BTL_POKEPARAM_SetAbility((struct QJ *)BTL_SIDE_GetPokeByIdThunk(client->side, pokeId), args[1]);
            return 1;
        }
        func_021EA768(client->view, monSlot, 0);
        (*state)++;
        break;
    case 1:
        if (func_021EA778(client->view, monSlot) != 0) {
            BTL_POKEPARAM_SetAbility((struct QJ *)BTL_SIDE_GetPokeByIdThunk(client->side, pokeId), args[1]);
            func_021EA7A8(client->view, monSlot);
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA7B8(client->view, monSlot) != 0) {
            (*state)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}





/*
 * pass 6 2026-10-06 P6L08: EXACT (364 B), also EXACT under -lang c99. The closing change is u16 x, y
 * with BTL_POKEPARAM_SetAbility declared (void *, u16), non-const a, and source order u, v, x, y. The callee
 * (BTL_POKEPARAM_SetAbility.c, strh to a u16 field) also matches EXACT with a u16 parameter, so the prototype is
 * consistent. Why it closes (scheduler trace, scratchpad wD9r/p6_P6L08): the word spill of the narrow
 * variable x uses the unknown-memory alias set (AO1), not a fresh spill alias object. With non-const a,
 * the pointee of a is in that set, so `str x, [sp]` gets a memory edge to the a[1] load and the load
 * waits after it, as in the original. With const a, the pointee of a is not in the set (22 B).
 * Earlier passes (wave75 to pass 6 P6L04) stayed at 13 B with u32 locals.
 */
int BTL_CLIENT_StepSwapAbilitiesWithPopup(BtlClient *client, int *state, u32 *args)
{
    u32 pokeIdA, pokeIdB;
    u16 abilityA, abilityB;
    int slotA, slotB;
    u8 *pokeParamA, *pokeParamB;
    pokeIdA = (u8)args[0];
    pokeIdB = (u8)args[1];
    abilityA = (u16)args[2];
    abilityB = (u16)args[3];
    slotA = BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, pokeIdA);
    slotB = BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, pokeIdB);
    pokeParamA = BTL_SIDE_GetPokeByIdThunk(client->side, pokeIdA);
    pokeParamB = BTL_SIDE_GetPokeByIdThunk(client->side, pokeIdB);
    switch (*state) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(client)) {
            BTL_POKEPARAM_SetAbility((struct QJ *)pokeParamA, abilityA);
            BTL_POKEPARAM_SetAbility((struct QJ *)pokeParamB, abilityB);
            return 1;
        }
        if (BTL_MAIN_IsPokeSamePair(pokeIdA, pokeIdB)) {
            BTL_POKEPARAM_SetAbility((struct QJ *)pokeParamA, abilityA);
            BTL_POKEPARAM_SetAbility((struct QJ *)pokeParamB, abilityB);
            return 1;
        }
        func_021EA768((u32 *)(client->view), slotA, 0);
        gExpGainWork.w[1] = 8;
        (*state)++;
        break;
    case 1:
        func_021EA778(client->view, slotA);
        if (gExpGainWork.w[1]) gExpGainWork.w[1]--;
        else {
            func_021EA768(client->view, slotB, 0);
            (*state)++;
        }
        break;
    case 2: {
        u8 doneA, doneB;
        doneA = func_021EA778(client->view, slotA);
        doneB = func_021EA778(client->view, slotB);
        if (doneA && doneB) (*state)++;
        break;
    }
    case 3:
        BTL_POKEPARAM_SetAbility((struct QJ *)pokeParamA, abilityA);
        BTL_POKEPARAM_SetAbility((struct QJ *)pokeParamB, abilityB);
        gExpGainWork.w[1] = 0;
        (*state)++;
        break;
    case 4:
        gExpGainWork.w[1]++;
        if (gExpGainWork.w[1] > 8) {
            func_021EA7A8(client->view, slotA);
            (*state)++;
        }
        break;
    case 5:
        if (func_021EA7B8(client->view, slotA)) {
            func_021EA7A8(client->view, slotB);
            (*state)++;
        }
        break;
    case 6:
        if (func_021EA7B8(client->view, slotB)) (*state)++;
        break;
    default:
        return 1;
    }
    return 0;
}






int BTL_CLIENT_StepClearIllusion(BtlClient *client, int *state, u32 *args)
{
    u32 pokeId;
    int monSlot;
    u8 *pokeParam;
    int mainStepActive;

    switch (*state) {
    case 0:
        pokeId = (u8)args[0];
        monSlot = BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, pokeId);
        pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, pokeId);
        mainStepActive = BTL_CLIENT_IsMainStepActive(client);
        BTL_POKEPARAM_ClearIllusion((struct Unk021D6C2C *)pokeParam);
        func_021EA868(client->view, monSlot, mainStepActive);
        (*state)++;
        break;
    case 1:
        if (func_021EA878(client->view) != 0) {
            (*state)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}





/*
 * extent: compiled 54 bytes followed by two zero alignment bytes.
 */
int BTL_CLIENT_StepPlayEffectById(BtlClient *client, int *state, unsigned int *args)
{
    if (*state == 0) {
        if (BTL_CLIENT_IsMainStepActive(client) != 0) return 1;
        func_021F7998(args[0]);
        (*state)++;
    } else {
        if (func_021F7EB4() == 0) return 1;
    }
    return 0;
}






int BTL_CLIENT_StepPlayMonSimpleEffect(BtlClient *client, int *state, u32 *args)
{
    u8 monSlot;

    monSlot = BTL_MAIN_GetViewPosOfSlot(client->main, (u8)args[0]);
    if (*state == 0) {
        if (BTL_CLIENT_IsMainStepActive(client) != 0) {
            return 1;
        }
        if (BTL_MAIN_CheckSceneOff((unsigned char *)client->main) == 0) {
            if (func_0689C9D4((u16)args[1]) != 0) {
                return 1;
            }
        }
        func_021EA3B8(client->view, monSlot, (u16)args[1]);
        (*state)++;
    } else {
        if (func_021EA3D4(client->view) != 0) {
            return 1;
        }
    }
    return 0;
}
