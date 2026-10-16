/*
 * file:     btl_client.c
 * unit:     yes
 * function: BTL_CLIENT_Create, BTL_CLIENT_Delete, BTL_CLIENT_MarkCommandIssued, BTL_CLIENT_ReadRecorderEntry, BTL_CLIENT_AttachRemoteLink, BTL_CLIENT_SetView, BTL_CLIENT_SetRequestParam, BTL_CLIENT_GetNetChannel, BTL_CLIENT_RunTick, BTL_CLIENT_StartRemoteStep, BTL_CLIENT_StartMainStep, BTL_CLIENT_IsRemote, BTL_CLIENT_GetQueuedCommandWord, BTL_CLIENT_IsMainStepActive, BTL_CLIENT_AddPoints, BTL_CLIENT_SetStepFn, BTL_CLIENT_StepMain, BTL_CLIENT_StepRemote, BTL_CLIENT_ResetSendWord, BTL_CLIENT_FindCommandStepFn, BTL_CLIENT_GetCursor, BTL_CLIENT_IsWindowWaiting, BTL_CLIENT_IsWindowDone, BTL_CLIENT_StepOpenBattleWindow, BTL_CLIENT_PollWindowStep, BTL_CLIENT_StoreMonParam, BTL_CLIENT_HasMonParamDropped, BTL_CLIENT_GetLeadPartyMon, BTL_CLIENT_StepWindowModeSelect, BTL_CLIENT_PickWindowMode, BTL_CLIENT_ReturnTrue, BTL_CLIENT_StartWindowModeSend, BTL_CLIENT_StartTimeLimit, BTL_CLIENT_PollTimeLimitReady, BTL_CLIENT_PollTimeLimitAndSetSub, BTL_CLIENT_StopTimeLimit, BTL_CLIENT_BuildActionPromptMessage, BTL_CLIENT_SetSubFn, BTL_CLIENT_RunSubFn, BTL_CLIENT_StepStartActionSelection, BTL_CLIENT_StepPlaybackRecordedAction, BTL_CLIENT_ResetActionCursor, BTL_CLIENT_InitActionSelection, BTL_CLIENT_ShowMessage, BTL_CLIENT_StepAutoSelectActions, BTL_CLIENT_StepSelectAction, BTL_CLIENT_StepShowSupportItemMessage, BTL_CLIENT_FindSupportItem, BTL_CLIENT_StepSelectMove, BTL_CLIENT_BuildMoveUsableTable, BTL_CLIENT_StepMoveHighlight, BTL_CLIENT_StepSelectSwitchTarget, BTL_CLIENT_StepSelectItem, BTL_CLIENT_IsLoneFoeSemiInvulnerable, BTL_CLIENT_StepSelectRun, BTL_CLIENT_StepAdvanceSlot, BTL_CLIENT_StepSendActions, BTL_CLIENT_ClearSlotLinkWords, BTL_CLIENT_SetSlotLinkWord, BTL_CLIENT_FlushSlotLinkWord, BTL_CLIENT_FlushSlotLinkWords, BTL_CLIENT_ClearSlotFlags, BTL_CLIENT_SetSlotFlag, BTL_CLIENT_SumSlotFlagsBeforeCurrent, BTL_CLIENT_IsActionForced, BTL_CLIENT_SetStruggleIfNoMoves, BTL_CLIENT_SetStruggleAction, BTL_CLIENT_IsMoveSelectionBlocked, BTL_CLIENT_BuildUsableMoveMask, BTL_CLIENT_IsHeldItemEffective, BTL_CLIENT_GetEscapeBlocker, BTL_CLIENT_GetEscapeBlockerForSide, BTL_CLIENT_FindTrapper, BTL_CLIENT_CanShadowTagTrap, BTL_CLIENT_CanArenaTrapTrap, BTL_CLIENT_CanMagnetPullTrap, BTL_CLIENT_ClearSlotOrder, BTL_CLIENT_HasSlotInOrder, BTL_CLIENT_SetSlotOrder, BTL_CLIENT_ChooseAiSwitchTarget, BTL_CLIENT_PickRandomFoe, BTL_CLIENT_IsCountdownEndingNext, BTL_CLIENT_ShouldSwitchVsWonderGuard, BTL_CLIENT_ShouldSwitchNoEffectiveMove, BTL_CLIENT_ShouldSwitchWhileLocked, BTL_CLIENT_FindSwitchFromHitHistory, BTL_CLIENT_FindNaturalCureSwitch, BTL_CLIENT_FindSwitchByTypeMatchup, BTL_CLIENT_FindMemberWithAbility, BTL_CLIENT_AnyMemberHasMoveVsTarget, BTL_CLIENT_FindMemberResistingType, BTL_CLIENT_HasMoveWithAffinityVsTarget, BTL_CLIENT_PickRotationPosition, BTL_CLIENT_StepAutoChooseActions, BTL_CLIENT_ListAbleMons, BTL_CLIENT_SortMonsByMovePower, BTL_CLIENT_BuildSlotChoices, BTL_CLIENT_SetChangeActionsFromChoice, BTL_CLIENT_SetChangeActionsFirstAble, BTL_CLIENT_CollectOwnReceivedIds, BTL_CLIENT_StepAskYesNo, BTL_CLIENT_StepChoiceMode2, BTL_CLIENT_StepChoiceMode1, BTL_CLIENT_ChooseReplacementsAuto, BTL_CLIENT_StepChooseReplacement, BTL_CLIENT_IsDoubleBattleLeadAlive, BTL_CLIENT_TrySetRotateAction, BTL_CLIENT_StepAskSwitchBeforeSendOut, BTL_CLIENT_RecordReceivedPacket, BTL_CLIENT_StepShowResultIfView, BTL_CLIENT_StepShowResultMessage, BTL_CLIENT_GetOutcomeForClient, BTL_CLIENT_StepShowTrainerResultIfView, BTL_CLIENT_StepShowTrainerResult, BTL_CLIENT_StepShowEndSpeechIfView, BTL_CLIENT_StepShowEndSpeech, BTL_CLIENT_ShowEndSpeech, BTL_CLIENT_StepShowPrizeMoneyMessage, BTL_CLIENT_StepShowBlackoutMessages, BTL_CLIENT_StepShowFixedMessage, BTL_CLIENT_StepRunServerCommandsIfView, BTL_CLIENT_StepRunServerCommands, BTL_CLIENT_StepShowRecallMessage, BTL_CLIENT_PickRecallMessageId, BTL_CLIENT_StepPlayRecallAnim, BTL_CLIENT_StepSendOutMon, BTL_CLIENT_PickSendOutMessageId, BTL_CLIENT_StepShowSideMessage, BTL_CLIENT_StepShowSideMessageWithSound, BTL_CLIENT_StepShowTaggedMessage, BTL_CLIENT_StepShowTaggedMessageWithSound, BTL_CLIENT_StepShowItemUseMessage, BTL_CLIENT_GetMoveAnimTarget, BTL_CLIENT_StepPlayMoveAnim, BTL_CLIENT_StepSetMonVisibility, BTL_CLIENT_StepPlayMonTaskAnim, BTL_CLIENT_StepPlayMultiMonAnim, BTL_CLIENT_StepUpdateMonGaugeThenMessage, BTL_CLIENT_StepStartEffectForMon, BTL_CLIENT_StepPlaySubstituteAnim, BTL_CLIENT_StepFaintMon, BTL_CLIENT_StepReviveMon, BTL_CLIENT_StepPlayMonEffect262, BTL_CLIENT_StepPlayMonEffect261, BTL_CLIENT_StepStartWeather, BTL_CLIENT_StepEndWeather, BTL_CLIENT_StepUpdateMonGauge, BTL_CLIENT_StepPlayMonAnim, BTL_CLIENT_StepUpdateMonGaugeCopy, BTL_CLIENT_StepRotatePositions, BTL_CLIENT_StepRotatePositionsTwice, BTL_CLIENT_StepPlayEffectOnMon, BTL_CLIENT_StepPlayEffectOnMonFast, BTL_CLIENT_StepTransformMon, BTL_CLIENT_StepPlayHitEffect, BTL_CLIENT_StepChangeBgm, BTL_CLIENT_StepPlayViewSequence, BTL_CLIENT_StepAddEffortValues, BTL_CLIENT_StepGiveExp, BTL_CLIENT_ForgetMoveSoundCallback, BTL_CLIENT_StepLearnLevelUpMoves, BTL_CLIENT_StepThrowBall, BTL_CLIENT_StepShowBallBlocked, BTL_CLIENT_StepClearSidePosition, BTL_CLIENT_StepSetAbilityWithPopup, BTL_CLIENT_StepSwapAbilitiesWithPopup, BTL_CLIENT_StepClearIllusion, BTL_CLIENT_StepPlayEffectById, BTL_CLIENT_StepPlayMonSimpleEffect, BTL_CLIENT_CmdSwapViewPositions, BTL_CLIENT_CmdChangeForm, BTL_CLIENT_CmdShowStatusPanel, BTL_CLIENT_CmdHideStatusPanel, BTL_CLIENT_CmdHpMinus, BTL_CLIENT_CmdHpPlus, BTL_CLIENT_CmdPpMinusOriginal, BTL_CLIENT_CmdPpMinusWorking, BTL_CLIENT_CmdMarkMoveUsed, BTL_CLIENT_CmdHpZero, BTL_CLIENT_CmdPpPlusOriginal, BTL_CLIENT_CmdPpPlusWorking, BTL_CLIENT_CmdStatStageUp, BTL_CLIENT_CmdStatStageDown, BTL_CLIENT_CmdSetStatStages, BTL_CLIENT_CmdRecoverStatStages, BTL_CLIENT_CmdResetStatStages, BTL_CLIENT_CmdAddCritStage, BTL_CLIENT_CmdSetSick, BTL_CLIENT_CmdCureMajorSick, BTL_CLIENT_CmdCureSick, BTL_CLIENT_CmdMemberIn, BTL_CLIENT_CmdSetPokeType, BTL_CLIENT_CmdCureSickMulti, BTL_CLIENT_StepConsumeHeldItem, BTL_CLIENT_StepRecordMoveUse, BTL_CLIENT_StepSetContFlag, BTL_CLIENT_StepClearContFlag, BTL_CLIENT_StepSetTurnFlag, BTL_CLIENT_StepClearTurnFlag, BTL_CLIENT_StepSetAbility, BTL_CLIENT_StepSetItem, BTL_CLIENT_StepReplaceMove, BTL_CLIENT_StepResetEffectsOnSwitchOut, BTL_CLIENT_StepRegisterFieldSlot, BTL_CLIENT_StepAddFieldSlotHolder, BTL_CLIENT_StepRemoveFieldHolder, BTL_CLIENT_StepRemoveFieldSlot, BTL_CLIENT_StepSetPokeCounter, BTL_CLIENT_StepPassEffects, BTL_CLIENT_StepSetSubstituteHp, BTL_CLIENT_StepClearSubstitute, BTL_CLIENT_StepAddClientPoints, BTL_CLIENT_StepUpdateIllusion, BTL_CLIENT_StepClearConsumedItem, BTL_CLIENT_StepCureSickBySource, BTL_CLIENT_StepAddHitRecord, BTL_CLIENT_StepAdvanceTurn, BTL_CLIENT_StepTickFieldSlots, BTL_CLIENT_StepSetStat, BTL_CLIENT_StepSetWeight, BTL_CLIENT_GetClientId, BTL_CLIENT_GetSideData, BTL_CLIENT_GetPointCounter, BTL_CLIENT_LoadTrainerItems, BTL_CLIENT_TakeTrainerItemToUse, BTL_CLIENT_IsStatItemUsable, BTL_CLIENT_IsSickItemUsable, BTL_CLIENT_ResetCounter, BTL_CLIENT_SetCounterMaximum, BTL_CLIENT_IsCounterFadeDone, BTL_CLIENT_RequestCounterAdvance, BTL_CLIENT_GetCounterMode, BTL_CLIENT_StartCounterReplay, BTL_CLIENT_StopCounterReplay, BTL_CLIENT_IsCounterReplayDone, BTL_CLIENT_GetCounterTarget, BTL_CLIENT_TryLockCounter, BTL_CLIENT_UnlockCounter, BTL_CLIENT_DisableCounter, BTL_CLIENT_TickCounter
 * address:  0x021CD6F0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Split from btl_server.c (lane L189): __FILE__ anchor 021CD8CC (gBtlClientFileName "btl_client.c") used by the 0x1b8-byte BtlClient constructor 021CD6F0, which is the first function of the file.
 *
 * symbols:
 *   gClientFirstPokeIds  0x021EFCF0  data  ov093
 *   BTL_MAIN_DecodeMessageCode  0x021B8778  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_MAIN_GetClientTrainerIndex  0x021B8BEC  thumb  ov093
 *   gViewPosOfSlotDouble  0x021EFCF4  data  ov093  a1
 *   gViewPosOfSlotTriple  0x021EFCFA  data  ov093  a1
 *   BTL_MAIN_IsMultiMode 0x021B86C8 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_MAIN_IsClientUsed  0x021B8B9C  thumb  ov093
 *   func_02007F1C 0x02007F1C thumb
 *   func_02007E50 0x02007E50 thumb
 *   GPOWER_ApplyPrizeMoney  0x0201119C  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   BEACON_GetPoints  0x0200C274  thumb
 *   BTL_CALC_CalcDefeatMoneyLoss  0x021D7FF8  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   BTL_MAIN_GetFieldSituation  0x021B8714  thumb  ov093
 *   NATSUKI_Calc  0x0201B7A0  thumb
 *   BTL_POKEPARAM_CopyMoves 0x021D54F4 thumb ov093
 *   BTL_POKEPARAM_IsIllusionActive  0x021D6C24  thumb  ov093
 *   BTL_POKEPARAM_GetDisplayMon  0x021D5864  thumb  ov093
 *   BTL_POKEPARAM_Delete 0x021D53B8 thumb ov093
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   BTL_POKEPARAM_Create 0x021D4D84 thumb ov093
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_SetFakeMon 0x021D5848 thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
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
 *   gBtlPosTables  0x021EFD70  data  ov093
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
 *   MI_CpuCopy8  0x02082D44  arm
 *   PMSI_PARAM_Copy  0x02024570  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetChars  0x02045A00  arm
 *   COMM_PLAYER_SUPPORT_GetCurrent  0x0202E7DC  thumb
 *   POKEPARTY_Create 0x0201A920 thumb
 *   BTL_SETUP_CheckStatusFlag  0x02013158  thumb
 *   RECORD_AddOne 0x02008DF0 thumb
 *   RECORD_AddCounter 0x02008DAC thumb
 *   BTL_MAIN_IsCommCompetitor 0x021B6818 thumb ov093
 *   NATSUKI_CalcUseItem  0x0201B7B4  thumb
 *   NATSUKI_CalcParty 0x0201B818 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   BTL_CALC_IsBossTrainer 0x021D7F60 thumb ov093
 *   BTL_CALC_GetItemParam 0x021D805C thumb ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex 0x021D62A8 thumb ov093
 *   _u32_div_f 0x0209C2B0 arm
 *   BTL_CLIENT_SET_GetCount  0x021D826C  thumb  ov093
 *   BTL_CLIENT_SET_JudgeResult  0x021D8270  thumb  ov093
 *   BTL_CALC_SetRngState  0x021D787C  thumb  ov093
 *   BTL_MAIN_InitClientParties  0x021B68D8  thumb  ov093
 *   BTLV_CORE_Delete  0x021E9034  thumb  ov093
 *   BTLV_CORE_ResetDisplay  0x021E8E28  thumb  ov093
 *   BTLV_CORE_Create  0x021E8F20  thumb  ov093
 *   BTL_POKEPARAM_GetUsedMoveTotal 0x021D54B4 thumb ov093
 *   func_02030734 0x02030734 arm
 *   gBtlServerFileName 0x021F3A60 data a4
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
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
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
 *   BTL_WAZAREC_Init 0x0689CFF0 thumb ov095
 *   BTL_DEADREC_Init 0x0689D118 thumb ov095
 *   BTL_POSPOKE_Init 0x0689D1FC thumb ov095
 *   MI_CpuFill8 0x02082BCC arm
 *   BTL_CLIENT_SET_Clear 0x021D8230 thumb ov093
 *   HAND_SIDE_InitTable 0x06898BFC thumb ov095
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BTL_MAIN_RegisterZukanSeen 0x021B8750 thumb ov093
 *   BTL_DEADREC_StartTurn 0x0689D134 thumb ov095
 *   BTL_EVENT_ClearSuspendedFlags  0x021D6EE8  thumb  ov093
 *   BTL_EVENT_ResetVarStackIfUsed  0x021D74E4  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_DEADREC_GetCount 0x0689D174 thumb ov095
 *   BTL_MAIN_GetClientSide  0x021B8BC4  thumb  ov093
 *   BTL_POSPOKE_GetEmptyPosList 0x0689D558 thumb ov095
 *   BTL_FIELD_GetStaticSlotObject  0x021EF948  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   HAND_TOKUSEI_EnableAbilityHandlers  0x021D8548  thumb  ov093
 *   HAND_ITEM_EnablePokeFactors  0x021DCFB4  thumb  ov093
 *   BTL_POSPOKE_RotateInPoke 0x0689D338 thumb ov095
 *   HAND_WAZA_AddMoveHandler  0x021E02DC  thumb  ov093
 *   HAND_WAZA_RemoveMoveHandlerUnlessKept  0x021E0394  thumb  ov093
 *   BTL_ACTION_IsChangeDepleted  0x021D83E0  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 *   BTL_EVENT_SetVarRanged  0x021D7674  thumb  ov093
 *   BTL_CALC_MulRatio  0x021D7B10  thumb  ov093
 *   BTL_ACTION_GetFightMove  0x021D8340  thumb  ov093
 *   BTL_POSPOKE_IsPokeInside 0x0689D588 thumb ov095
 *   BTL_MAIN_GetCompetitorKind 0x021B86E4 thumb ov093
 *   BTL_POKEPARAM_GetCounter 0x021D69AC thumb ov093
 *   BTL_POKEPARAM_SetTurnFlag 0x021D5FC0 thumb ov093
 *   POKE_TOOL_IsOwnedByPlayer 0x02018480 thumb
 *   BTL_MAIN_GetPlayerStatus 0x021B871C thumb ov093
 *   BTL_MAIN_GetBadgeCount 0x021B85A0 thumb ov093
 *   POKE_TOOL_IsBoxOwnedByPlayer 0x02018488 thumb
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_POSPOKE_SearchPosByPokeId 0x0689D5C8 thumb ov095
 *   func_021D82FC  0x021D82FC  thumb  ov093
 *   BTL_POKESET_GetCountMax 0x0689CD40 thumb ov095
 *   BTL_POKESET_GetCount 0x0689CD38 thumb ov095
 *   BTL_POKESET_Get 0x0689CC70 thumb ov095
 *   BTL_POSPOKE_SwapPos 0x0689D4F0 thumb ov095
 *   BTL_POKEPARAM_GetStatRaw  0x021D58A8  thumb  ov093
 *   BTL_CLIENT_SET_Add 0x021D8244 thumb ov093
 *   BTL_SICK_ForceGroundedByTrap 0x0689C68C thumb ov095
 *   HAND_TOKUSEI_AddAbilityHandlers 0x021D8484 thumb ov093
 *   HAND_ITEM_AddHeldItemFactor 0x021DCF5C thumb ov093
 *   BTL_POKEPARAM_StartTurnThreshold 0x021D63EC thumb ov093
 *   BTL_POKEPARAM_ReloadAndResetEffects 0x021D6580 thumb ov093
 *   BTL_POSPOKE_SetPoke 0x0689D320 thumb ov095
 *   BTL_POKESET_Clear 0x0689CB3C thumb ov095
 *   BTL_POKESET_Add 0x0689CB48 thumb ov095
 *   BTL_POKESET_SortBySpeed 0x0689CF24 thumb ov095
 *   BTL_POKESET_SeekStart 0x0689CC84 thumb ov095
 *   BTL_POKESET_SeekNext 0x0689CC8C thumb ov095
 *   BTL_EVENT_DispatchEventToType 0x021D70FC thumb ov093
 *   BTL_POKEPARAM_ResetEffectsOnSwitchOut  0x021D64F0  thumb  ov093
 *   BTL_POSPOKE_RemovePoke 0x0689D2F8 thumb ov095
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb  ov093
 *   BTLV_CORE_GetSlotValue  0x021E8B80  thumb  ov093
 *   BTL_POKEPARAM_GetMovePPById  0x021D55A0  thumb  ov093
 *   BTL_POKEPARAM_GetSemiInvulnerableFlag 0x021D5C08 thumb ov093
 *   BTL_CALC_DecideMoveTarget 0x021D80BC thumb ov093
 *   BTL_ACTION_SetFight 0x021D82D0 thumb ov093
 *   BTL_POKEPARAM_FindMoveSlot 0x021D5778 thumb ov093
 *   BTL_POKESET_RemoveFainted 0x0689CEE4 thumb ov095
 *   BTL_POKESET_CopyAlive 0x0689CD78 thumb ov095
 *   BTL_POKESET_SetEmptyMarked 0x0689CD48 thumb ov095
 *   BTL_WAZAREC_Add 0x0689D01C thumb ov095
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
 *   BTL_POKESET_IsRemovedAll 0x0689CD50 thumb ov095
 *   BTL_WAZAREC_SetEffectiveLast 0x0689D050 thumb ov095
 *   BTL_POKESET_Remove 0x0689CC14 thumb ov095
 *   BTL_POKEPARAM_HasSubstitute  0x021D6D7C  thumb  ov093
 *   BTL_POSPOKE_GetFieldPos 0x0689D59C thumb ov095
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
 *   BTL_POKEPARAM_SetCounter  0x021D69A0  thumb  ov093
 *   BTL_POKEPARAM_DecrementMovePP  0x021D5608  thumb  ov093
 *   BTL_POKEPARAM_MarkMoveUsed  0x021D56CC  thumb  ov093
 *   BTL_POKESET_CopyFriends 0x0689CDCC thumb ov095
 *   BTL_POKESET_CopyEnemies 0x0689CE58 thumb ov095
 *   BTL_MAIN_CheckSceneOff 0x021B8590 thumb ov093
 *   BTL_POKESET_AddWithDamage 0x0689CBB8 thumb ov095
 *   sDamageEffectiveness  0x021F3B2C  data  ov093  a4
 *   sDamageCriticalFlags  0x021F3B20  data  ov093  a4
 *   sDamageTargets  0x021F3B38  data  a4
 *   sDamageValues  0x021F3B26  data  ov093  a4
 *   sDamageAftereffects  0x021F3B23  data  ov093  a4
 *   d_021F3B20b 0x021F3B20  data  ov093  a4
 *   BTL_POKEPARAM_AddHitRecord  0x021D6848  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_POKESET_GetPlainDamage 0x0689CCF8 thumb ov095
 *   BTL_POKESET_GetTotalDamage 0x0689CCB4 thumb ov095
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
 *   BTL_SICK_BuildCureMessage 0x0689C364 thumb ov095
 *   HAND_TOKUSEI_RemoveAbilityHandlers 0x021D8510 thumb ov093
 *   BTL_POKEPARAM_ChangeForm 0x021D66D8 thumb ov093
 *   BTL_CALC_HasDefaultSickCont 0x021D7D6C thumb ov093
 *   BTL_FIELD_GetCountdownValue  0x021EF884  thumb  ov093
 *   BTL_EVENT_DispatchEvent 0x021D70E4 thumb ov093
 *   WAZA_TOOL_GetRankEffectCount 0x0201C020 thumb
 *   WAZA_TOOL_GetRankEffect  0x0201C0BC  thumb
 *   BTL_POKEPARAM_CanChangeStatStage 0x021D5D14 thumb ov093
 *   BTL_POKEPARAM_IsHpFull  0x021D5B48  thumb  ov093
 *   BTL_CALC_SummarizeTypeAffinity 0x021D7AD4 thumb ov093
 *   BTL_POKEPARAM_ZeroHp  0x021D5FB8  thumb  ov093
 *   BTL_POKEPARAM_GetSubstituteHp  0x021D6D90  thumb  ov093
 *   BTL_SICK_ShowIngrainRoots 0x0689C7A4 thumb ov095
 *   WAZA_TOOL_GetWeather  0x0201C184  thumb
 *   BTL_FIELD_GetCountdownCount 0x021EF894 thumb ov093
 *   func_021EF8A4 0x021EF8A4 thumb ov093
 *   BTL_FIELD_RegisterStaticSlot  0x021EF8C8  thumb  ov093
 *   BTLV_CORE_GetSlotPosition  0x021E8A98  thumb  ov093
 *   BTL_FIELD_SetStaticSlotValue  0x021EF8F8  thumb  ov093
 *   BTL_ID_IsAbilitySkillSwapBlocked 0x0689C954 thumb ov095
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
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   COMM_PLAYER_SUPPORT_GetMode 0x0202E7E0 thumb
 *   COMM_PLAYER_SUPPORT_SavePreviousAndSuspend 0x0202E7E4 thumb
 *   BTL_ID_GetTurnCheckSick 0x0689C9F8 thumb ov095
 *   BTL_SICK_ProcAddedOrTurnEnd 0x0689B7A8 thumb ov095
 *   BTL_POKEPARAM_TickSickCont 0x021D6064 thumb ov093
 *   BTL_CALC_PackPokeIds 0x021D806C thumb ov093
 *   BTL_SICK_BuildDamageMessage 0x0689B8CC thumb ov095
 *   HAND_SIDE_TickTurns 0x06898D54 thumb ov095
 *   BTL_FIELD_QueryStaticSlotC 0x021EF934 thumb ov093
 *   func_021C4C40 0x021C4C40 thumb ov093
 *   BTL_FIELD_TickCountdown 0x021EF8B8 thumb ov093
 *   BTL_CALC_GetWeatherDamage 0x021D7BD4 thumb ov093
 *   BTL_DEADREC_Add 0x0689D15C thumb ov095
 *   BTL_POKEPARAM_ResetAllEffects 0x021D646C thumb ov093
 *   BTL_MAIN_GetRuleSlotSpan  0x021B8640  thumb  ov093
 *   BTL_POSPOKE_GetPokeIdAtPos 0x0689D5FC thumb ov095
 *   HAND_TOKUSEI_DisableAbilityHandlers 0x021D8538 thumb ov093
 *   HAND_ITEM_DisablePokeFactors 0x021DCFA4 thumb ov093
 *   HAND_WAZA_RemoveAllMoveHandlers 0x021E0434 thumb ov093
 *   BTL_POKEPARAM_CureSickBySource 0x021D6264 thumb ov093
 *   BTL_FIELD_QueryStaticSlotB 0x021EF90C thumb ov093
 *   BTL_MAIN_CheckEventOverlayAllowed 0x021B85EC thumb ov093
 *   BTL_DEADREC_IsReported 0x0689D1A0 thumb ov095
 *   BTL_DEADREC_GetPokeId 0x0689D184 thumb ov095
 *   BTL_DEADREC_SetReported 0x0689D1BC thumb ov095
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
 *   WAZA_TOOL_IsAlwaysHit  0x0201C1F4  thumb
 *   WAZA_TOOL_IsAlwaysCritical  0x0201C284  thumb
 *   BTL_POKEPARAM_GetCritStage  0x021D5F14  thumb  ov093
 *   BTL_CALC_RollCriticalHit  0x021D7930  thumb  ov093
 *   BTLV_CORE_GetHighByte 0x021E8CFC thumb ov093
 *   BTLV_CORE_GetLowByte 0x021E8D04 thumb ov093
 *   BTLV_CORE_BytesEqual 0x021E8DA8 thumb ov093
 *   BTL_CALC_CombineTypeAffinity 0x021D79E8 thumb ov093
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   BTL_SICK_ForceGroundedOrFloating 0x0689C6E4 thumb ov095
 *   BTL_SICK_OverrideGroundImmunity 0x0689C540 thumb ov095
 *   BTL_CALC_GetTypeAffinity  0x021D794C  thumb  ov093
 *   BTL_CALC_RollHitCount  0x021D7BA4  thumb  ov093
 *   WAZA_TOOL_GetPower  0x0201C1D8  thumb
 *   BTL_POKEPARAM_GetStatForCrit 0x021D5AD8 thumb ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_CALC_MulRatioMin1  0x021D7B2C  thumb  ov093
 *   BTL_MAIN_CheckFrontPos 0x021B86A0 thumb ov093
 *   BTL_POSPOKE_GetPosByPokeId 0x0689D5F4 thumb ov095
 *   BTL_MAIN_GetActivePosPerSide  0x021B8670  thumb  ov093
 *   SHINKA_CHECK_GetRowParam 0x0201B718 thumb
 *   HAND_SIDE_IsActive  0x06898CF4  thumb  ov095
 *   HAND_SIDE_GetStackCount 0x06898CE0 thumb ov095
 *   func_068982AC  0x068982AC  thumb
 *   BTL_POKEPARAM_GetWeight 0x021D67E8 thumb ov093
 *   BTL_POKEPARAM_IsMovePPFull  0x021D55D8  thumb  ov093
 *   BTL_SICK_BuildAddMessage 0x0689C464 thumb ov095
 *   BTL_POKEPARAM_SetStatStage  0x021D5EA8  thumb  ov093
 *   BTL_POKEPARAM_RaiseLoweredStatStages 0x021D5EFC thumb ov093
 *   BTL_POKEPARAM_ResetStatStages  0x021D5F08  thumb  ov093
 *   BTL_POKEPARAM_SetStat 0x021D5970 thumb ov093
 *   BTL_ID_IsArceusSpecies 0x0689C9C0 thumb ov095
 *   BTL_POKEPARAM_SetTypes  0x021D66B0  thumb  ov093
 *   BTL_POKEPARAM_ClearTurnFlag 0x021D6440 thumb ov093
 *   HAND_SIDE_AddFactor 0x06898C10 thumb ov095
 *   HAND_SIDE_Remove 0x06898D10 thumb ov095
 *   BTL_FIELD_QueryStaticSlotA 0x021EF8E8 thumb ov093
 *   HAND_POS_AddFactor 0x068981F0 thumb ov095
 *   BTL_ID_IsMultitypeAbility 0x0689C974 thumb ov095
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
 *   FX_Sqrt  0x0207C7B4  arm
 *   BTL_POKEPARAM_GetMaxLevelExp  0x021D6B6C  thumb  ov093
 *   gEffortValueStatTable      0x021EFDC0  data  ov093
 *   POKE_TOOL_GetPersonalParam   0x02019C90  thumb arm9
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
 *   BTL_ID_IsBallWithCatchBonus 0x0689C9A0 thumb ov095
 *   _fflt 0x0209BDBC arm
 *   _s32_div_f 0x0209C0A4 arm
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   BTL_POKEPARAM_AddCritStage  0x021D5F38  thumb  ov093
 *   BTL_POKEPARAM_CountRealMoves  0x021D5450  thumb  ov093
 *   BTL_POKEPARAM_GetRealMovePPLost  0x021D5568  thumb  ov093
 *   BTL_POKEPARAM_GetRealMoveId  0x021D54D0  thumb  ov093
 *   BTL_ID_GetItemCuredSick 0x0689C9E4 thumb ov095
 *   BTL_ID_IsHeldItemUseBlocked 0x0689C8FC thumb ov095
 *   BTLV_CORE_CheckPartySlotPair  0x021E869C  thumb  ov093
 *   BTL_DEADREC_GetLastPokeId 0x0689D1D4 thumb ov095
 *   gHandExRecordSizeTable     0x021EFE9C  data  a4
 *   gBtlEmptyString 0x021F3A84 data
 *   func_02034714 0x02034714 arm
 *   gBtlServerCmdLayouts  0x021EFF14  data  ov093
 *   gBtlServerCmdArgBuffer  0x021F3B44  data  ov093
 *   gBtlClientFileName 0x021F3A88 data a4
 *   TR_AI_Create 0x02187F00 thumb ov096
 *   BTL_REC_CreateBuffer 0x021EE5E4 thumb ov093
 *   BTL_REC_DeleteBuffer 0x021EE600 thumb ov093
 *   TR_AI_Delete 0x02188080 thumb ov096
 *   BTL_REC_ReadEntry 0x021EE63C thumb ov093
 *   BTL_REC_CountFlaggedRecords 0x021EE830 thumb ov093
 *   BTL_REC_ResetReader 0x021EE674 thumb ov093
 *   BTL_ADAPTER_ClearRecvHeader 0x021EEBDC thumb ov093
 *   BTL_ADAPTER_GetRecvCommand 0x021EEBE8 thumb ov093
 *   BTL_ADAPTER_GetRecvData 0x021EEC20 thumb ov093
 *   BTL_ADAPTER_SetRecvTarget 0x021EEC4C thumb ov093
 *   GFL_USE_SetPlayersAudible 0x02005CA4 thumb
 *   PM_VOICE_ResetMasterVolume 0x02006740 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   PM_VOICE_SetMasterVolume 0x02006734 thumb
 *   BTLV_CORE_ClearWaitWindow 0x021EAE24 thumb ov093
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   BTLV_EFFECT_SetFlag26 0x021F88BC thumb ov094
 *   BTLV_EFFECT_GetWorkPtr 0x021F8678 thumb ov094
 *   BTLV_CORE_GetWaitState 0x021EAE34 thumb ov093
 *   BTLV_CORE_SetCounterDisplay 0x021EAE74 thumb ov093
 *   gBtlClientCommandTable 0x021EFFEC data a4
 *   BTLV_EFFECT_TimerIsExpired 0x021F8524 thumb ov094
 *   BTLV_CORE_StartOpening  0x021E90A0  thumb  ov093
 *   BTLV_CORE_PollOpening  0x021E90D0  thumb  ov093
 *   BTLV_EFFECT_TimerStart  0x021F84E8  thumb  ov094
 *   BTLV_EFFECT_TimerSetVisible  0x021F8504  thumb  ov094
 *   BTLV_CORE_ShowCounterValue  0x021EAEA8  thumb  ov093
 *   BTL_REC_ReadSkipFlag  0x021EE688  thumb  ov093
 *   BTLV_CORE_InitInputWork  0x021EAA00  thumb  ov093
 *   BTLV_CORE_CancelWindowModeSelect  0x021EAA5C  thumb  ov093
 *   BTLV_CORE_PollWindowModeSelect  0x021EAA34  thumb  ov093
 *   BTLV_SCU_InitMessage  0x021EAF18  thumb  ov093
 *   BTLV_SCU_AppendMessageArg  0x021EAF50  thumb  ov093
 *   BTLV_SCU_SetMessageParam  0x021EAF78  thumb  ov093
 *   BTL_REC_ReadRecord 0x021EE6B8 thumb ov093
 *   BTLV_CORE_BuildAndPrintMessage 0x021EA614 thumb ov093
 *   BTLV_CORE_WaitMessage 0x021EA710 thumb ov093
 *   BTL_CALC_ActionSetNone 0x021D8434 thumb ov093
 *   BTLV_CORE_StartAutoSelectNotice 0x021EAE44 thumb ov093
 *   BTLV_CORE_PollAutoSelectNotice 0x021EAE54 thumb ov093
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   BTL_CALC_PeekMoveTarget 0x021D81F8 thumb ov093
 *   BTLV_CORE_BuildAndPrintMessageNow 0x021EA65C thumb ov093
 *   BTLV_CORE_StartActionMenu 0x021E9760 thumb ov093
 *   BTLV_CORE_AbortActionMenu 0x021E979C thumb ov093
 *   BTLV_CORE_PollActionMenu 0x021E97A4 thumb ov093
 *   BTLV_CORE_CloseMenuToReselect 0x021E9964 thumb ov093
 *   BTL_PICK_Pop 0x0689CB08 thumb ov095
 *   BTLV_CORE_IsMenuClosed 0x021E9974 thumb ov093
 *   BTLV_CORE_CloseMenu 0x021E9954 thumb ov093
 *   BTLV_EFFECT_AddPokeSprite 0x021F7F58 thumb ov094
 *   BTLV_EFFECT_StartEffect 0x021F7998 thumb ov094
 *   BTLV_CORE_PrintTrainerMessage 0x021EA6B0 thumb ov093
 *   BTL_CALC_IsGymLeaderTrainer 0x021D7F38 thumb ov093
 *   BTLV_EFFECT_SaveBgmNo 0x021F87EC thumb ov094
 *   BTLV_EFFECT_PollLowHpBgm 0x021F8774 thumb ov094
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   BTLV_EFFECT_IsBusy 0x021F7EB4 thumb ov094
 *   TPOKE_DATA_FindRecord 0x0202A298 thumb
 *   BTL_CALC_DivideMaxHp 0x021D7B60 thumb ov093
 *   gBtlClientSupportItemKeys 0x021EFF78 data ov093 a2
 *   BTLV_CORE_StartMoveMenu 0x021E97BC thumb ov093
 *   BTLV_CORE_StartMoveMenuForEntry 0x021E9808 thumb ov093
 *   BTLV_CORE_AbortMoveMenu 0x021E98AC thumb ov093
 *   BTLV_CORE_PollMoveMenu 0x021E98B4 thumb ov093
 *   func_021D832C 0x021D832C thumb ov093
 *   BTL_ACTION_SetRotate 0x021D83FC thumb ov093
 *   BTL_CALC_IsMultiFighterRule 0x021D7EF0 thumb ov093
 *   BTLV_CORE_StartTargetMenu 0x021E98BC thumb ov093
 *   BTLV_CORE_AbortTargetMenu 0x021E9920 thumb ov093
 *   BTLV_CORE_PollTargetMenu 0x021E98E8 thumb ov093
 *   BTLV_CORE_ReopenMoveMenu 0x021E9858 thumb ov093
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb  ov093
 *   BTLV_CORE_StartMoveHighlight  0x021E9CE0  thumb  ov093
 *   BTLV_CORE_LockPartyChoice  0x021E9B14  thumb  ov093
 *   BTLV_CORE_PollPartyMenu  0x021E9B20  thumb  ov093
 *   BTLV_CORE_StartPartyMenu 0x021E9A78 thumb ov093
 *   BTL_PICK_GetLocked 0x0689CB14 thumb ov095
 *   BTL_PICK_GetLast 0x0689CB1C thumb ov095
 *   BTL_ACTION_SetChange 0x021D8394 thumb ov093
 *   BTLV_CORE_StartBagMenu 0x021E9D04 thumb ov093
 *   BTLV_CORE_SkipBagPartyPrompt 0x021E9E70 thumb ov093
 *   BTLV_CORE_PollBagMenu 0x021E9E80 thumb ov093
 *   BTLV_CORE_GetSelectedItem 0x021EA01C thumb ov093
 *   BTLV_CORE_GetInputTargetSlot 0x021EA044 thumb ov093
 *   BTLV_CORE_GetSelectedItemPocket 0x021EA030 thumb ov093
 *   BTLV_CORE_GetInputResultFlag 0x021EA04C thumb ov093
 *   BTL_ACTION_SetItem 0x021D8358 thumb ov093
 *   BTLV_CORE_SaveBagCursors 0x021EA058 thumb ov093
 *   BTLV_CORE_ConsumeMessageFlag 0x021EA720 thumb ov093
 *   BTLV_CORE_StartYesNoMenu 0x021EABC4 thumb ov093
 *   BTLV_CORE_PollYesNoMenu 0x021EAC54 thumb ov093
 *   func_021D8414 0x021D8414 thumb ov093
 *   BTLV_CORE_StartWaitMessage  0x021EA7FC  thumb  ov093
 *   BTLV_CORE_UpdateWaitMessage  0x021EA814  thumb  ov093
 *   BTL_CALC_ActionSetForcedSkip  0x021D8444  thumb  ov093
 *   BTL_POKEPARAM_GetLastMoveSlot  0x021D67C4  thumb  ov093
 *   BTL_POKEPARAM_HasMove 0x021D5750 thumb ov093
 *   BTL_FIELD_IsSlotInUse 0x021EFCE4 thumb ov093
 *   BTL_FIELD_IsMoveSealedBySlot 0x021EFC1C thumb ov093
 *   BTLV_CORE_GetSlotLow 0x021E8AFC thumb ov093
 *   BTL_POKEPARAM_GetSickTurn 0x021D631C thumb ov093
 *   BTL_CALC_GetTypeAffinityVsPair 0x021D799C thumb ov093
 *   BTL_POKEPARAM_GetHitRecord 0x021D6940 thumb ov093
 *   gBtlClientAiHitKindRows 0x021EFFC2 data ov093 a2
 *   BTL_POKEPARAM_GetHpRatioFixed  0x021D5C44  thumb  ov093
 *   BTL_CALC_GetScanStartIndex 0x021D7F2C thumb ov093
 *   TR_AI_Start 0x021880BC thumb ov096
 *   TR_AI_Think 0x02187FB0 thumb ov096
 *   TR_AI_GetChosenMove 0x02188134 thumb ov096
 *   TR_AI_GetChosenTarget 0x02188140 thumb ov096
 *   BTL_PICK_InitSlotChoices 0x0689CA98 thumb ov095
 *   BTL_PICK_MarkSlotsSelectable 0x0689CAB0 thumb ov095
 *   BTL_PICK_InitList 0x0689CAE0 thumb ov095
 *   BTL_ACTION_SetChangeDepleted 0x021D83C4 thumb ov093
 *   BTL_REC_AppendPacket  0x021EE608  thumb  ov093
 *   BTL_REC_GetPacketId  0x021EE638  thumb  ov093
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   BTLV_EFFECT_StopLowHpBgm   0x021F878C  thumb ov094
 *   BTLV_CORE_PrintMessageBuffer 0x021EA600 thumb ov093
 *   PMSI_PARAM_IsEnabled  0x02024450  thumb
 *   PMSI_PARAM_ToString  0x0202435C  thumb
 *   BTLV_CORE_CopyMessageBuffer  0x021EA5E4  thumb  ov093
 *   BTLV_CORE_BuildMessageToBuffer  0x021EA5F0  thumb  ov093
 *   MIi_CpuCopy32 0x02082A90 arm
 *   BTLV_CORE_EndWaitMessage 0x021EA824 thumb ov093
 *   gServerCommandHandlers 0x021F00DC data a4
 *   BTLV_CORE_StartMonEffectTask  0x021EA458  thumb  ov093
 *   BTLV_CORE_WaitMonEffectTask  0x021EA478  thumb  ov093
 *   BTLV_CORE_StartMonSwap 0x021EA488 thumb ov093
 *   BTLV_CORE_WaitMonSwap 0x021EA4C4 thumb ov093
 *   BTLV_CORE_PrintSideMessage  0x021EA678  thumb  ov093
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   BTLV_CORE_PrintTaggedMessage  0x021EA694  thumb  ov093
 *   BTLV_CORE_PrintItemUseMessage  0x021EA6F4  thumb  ov093
 *   BTL_CALC_GetCurseTargetKind  0x021D80A8  thumb  ov093
 *   BTLV_CORE_StartSceneEffect 0x021EA0A0 thumb ov093
 *   BTLV_CORE_WaitSceneEffect 0x021EA0E4 thumb ov093
 *   BTLV_CORE_SetMonShown  0x021EA354  thumb  ov093
 *   BTLV_CORE_StartDamageEffect  0x021EA0F4  thumb  ov093
 *   BTLV_CORE_WaitDamageEffect  0x021EA120  thumb  ov093
 *   BTLV_CORE_StartMultiDamageEffect  0x021EA280  thumb  ov093
 *   BTLV_CORE_ProcMultiDamageEffect  0x021EA2BC  thumb  ov093
 *   BTLV_CORE_StartMonSpriteUpdate  0x021EA384  thumb  ov093
 *   BTLV_CORE_WaitMonSpriteUpdate  0x021EA3A0  thumb  ov093
 *   BTLV_EFFECT_GaugeSetStatusIcon  0x021F81D0  thumb  ov094
 *   BTLV_CORE_StartMonReset  0x021EA40C  thumb  ov093
 *   BTLV_CORE_WaitMonReset  0x021EA428  thumb  ov093
 *   BTLV_CORE_StartMonRefresh  0x021EA438  thumb  ov093
 *   BTLV_CORE_WaitMonRefresh  0x021EA448  thumb  ov093
 *   BTLV_CORE_StartViewEffect262  0x021EA7C8  thumb  ov093
 *   BTLV_CORE_WaitViewEffectDone  0x021EA7E8  thumb  ov093
 *   BTLV_CORE_StartViewEffect261  0x021EA7D8  thumb  ov093
 *   BTL_FIELD_StoreCountdown  0x021EF9C0  thumb  ov093
 *   gWeatherEffects     0x021EFFAE  data   ov093  a2
 *   BTL_FIELD_ClearCountdown  0x021EF9C8  thumb  ov093
 *   BTLV_CORE_StartSlotEffect25F  0x021EA838  thumb  ov093
 *   BTLV_CORE_WaitSlotEffect25F  0x021EA850  thumb  ov093
 *   BTLV_CORE_StartRotation  0x021EA904  thumb  ov093
 *   BTLV_CORE_WaitRotation  0x021EA950  thumb  ov093
 *   BTLV_EFFECT_StartPokeEffectId26E 0x021F7E94 thumb ov094
 *   BTLV_EFFECT_StartPokeEffectId26F  0x021F7EA4  thumb  ov094
 *   BTLV_CORE_StartMonSpriteChangeAt  0x021EA8B4  thumb  ov093
 *   BTLV_CORE_WaitMonSpriteChangeAt  0x021EA8D4  thumb  ov093
 *   BTLV_CORE_StartHitAnim  0x021EA1B8  thumb  ov093
 *   BTLV_CORE_WaitHitAnim  0x021EA1F0  thumb  ov093
 *   BTLV_CORE_StartMonSpriteUnload 0x021EA8E4 thumb ov093
 *   BTLV_CORE_WaitMonSpriteUnload 0x021EA8F4 thumb ov093
 *   gEffortValueParams     0x021EFF88  data  ov093  a2
 *   BTLV_EFFECT_GaugeIsSlotOccupied 0x021F8204 thumb ov094
 *   BTLV_EFFECT_GaugeStartExpGain 0x021F8134 thumb ov094
 *   BTLV_EFFECT_GaugeIsAnimating 0x021F8180 thumb ov094
 *   BTL_EVENT_ReleaseClientHandle 0x021D6EA0 thumb ov093
 *   BTL_POKEPARAM_ReloadFromParam 0x021D6BFC thumb ov093
 *   BTLV_EFFECT_GaugeRefreshForLevelUp 0x021F8150 thumb ov094
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   BTLV_CORE_StartViewEffect 0x021EA3B8 thumb ov093
 *   BTLV_CORE_WaitViewEffect 0x021EA3D4 thumb ov093
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   BTLV_CORE_StartBallWindowOpen 0x021EADA4 thumb ov093
 *   BTLV_CORE_UpdateBallWindowOpen 0x021EADB4 thumb ov093
 *   BTLV_CORE_StartBallWindowRefresh 0x021EADC4 thumb ov093
 *   BTLV_CORE_UpdateBallWindowRefresh 0x021EADD4 thumb ov093
 *   BTLV_CORE_StartBallWindowClose 0x021EADE4 thumb ov093
 *   BTLV_CORE_UpdateBallWindowClose 0x021EADF4 thumb ov093
 *   gExpGainWork 0x021F3B64 data a4
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   POKE_TOOL_SetMoveSlot   0x020181F4  thumb
 *   POKE_TOOL_GetLevelUpMove   0x02018328  thumb
 *   BTLV_CORE_BuildAndPrintMessageFlag   0x021EA638  thumb ov093
 *   BTLV_CORE_StartMoveForgetScreen   0x021EAC64  thumb ov093
 *   BTLV_CORE_ProcMoveForgetScreen   0x021EAC80  thumb ov093
 *   sLevelUpMoveScan      0x021F3B64  data
 *   BTLV_EFFECT_StartEffectWithColor 0x021F7CFC thumb ov094
 *   BTLV_EFFECT_StopLowHpBgmAndSuppress 0x021F883C thumb ov094
 *   gCatchShakeMessages 0x021EFF80 data a2
 *   BTLV_EFFECT_ResumeVm 0x021F7C0C thumb ov094
 *   BTLV_EFFECT_StartEffectWithValue  0x021F7D44  thumb  ov094
 *   BTLV_CORE_StartClearSidePosition  0x021EAA6C  thumb  ov093
 *   BTLV_CORE_RunProc  0x021EAAD8  thumb  ov093
 *   BTLV_CORE_ShowPortrait  0x021EA768  thumb  ov093
 *   BTLV_CORE_UpdatePortraitSlideIn  0x021EA778  thumb  ov093
 *   BTLV_CORE_ReloadPortrait  0x021EA7A8  thumb  ov093
 *   BTLV_CORE_UpdatePortraitMosaic  0x021EA7B8  thumb  ov093
 *   BTLV_CORE_StartMonSpriteLoad  0x021EA868  thumb  ov093
 *   BTLV_CORE_WaitMonSpriteLoad  0x021EA878  thumb  ov093
 *   BTL_ID_IsSimpleEffectId 0x0689C9D4 thumb ov095
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
 *   BTLV_CORE_StartViewEffectEx  0x021EA3E8  thumb  ov093
 *   BTLV_CORE_WaitViewEffectEx  0x021EA3F8  thumb  ov093
 *   BTLV_CORE_StartMonSpriteChange  0x021EA888  thumb  ov093
 *   BTLV_CORE_WaitMonSpriteChange  0x021EA8A4  thumb  ov093
 *   BTLV_CORE_StartPortraitSlideOut  0x021EA788  thumb  ov093
 *   BTLV_CORE_WaitPortraitSlideOut  0x021EA798  thumb  ov093
 *   BTL_POKEPARAM_DecrementRealMovePP 0x021D5640 thumb ov093
 *   BTL_SLOT_GetPoke  0x021B9BF0  thumb  ov093
 *   BTL_CALC_UnpackPokeIds  0x021D8090  thumb  ov093
 *   BTL_FIELD_RegisterSlot 0x021EF9F4 thumb ov093
 *   BTL_FIELD_AddSlotHolder 0x021EFAD8 thumb ov093
 *   BTL_FIELD_RemoveHolderFromSlots 0x021EFB34 thumb ov093
 *   BTL_FIELD_RemoveSlot 0x021EFA94 thumb ov093
 *   BTL_MAIN_AddClientPoints 0x021B9B10 thumb ov093
 *   BTL_SLOT_UpdateIllusion 0x021B9D10 thumb ov093
 *   BTL_FIELD_TickSlots   0x021EFC78  thumb
 *   BTL_FIELD_GetCountdownByte 0x021EF9A8 thumb ov093
 *   BTL_MAIN_GetTrainerItem 0x021B9F84 thumb ov093
 *   gBtlClientItemSlotLimits  0x021EFF74  data  a1
 *   gBtlClientItemStatChecks  0x021EFF94  data  ov093  a1
 *   gBtlClientItemSickChecks 0x021EFFA0 data a1
 *   BTLV_CORE_PollCounterInput 0x021EAE64 thumb ov093
 *   BTLV_CORE_StartFadeIn 0x021EAE04 thumb ov093
 *   BTLV_CORE_SetCounterValueMode 0x021EAECC thumb ov093
 *   BTLV_EFFECT_SuspendVmWait 0x021F8B10 thumb ov094
 *   BTLV_CORE_PollFadeInDone 0x021EAE14 thumb ov093
 *   gBtlNet 0x021F3B88 data ov093 a4
 *   gBtlNetSourceName 0x021F3A98 data ov093 a4
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   func_02007B00  0x02007B00  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   STRBUF_GetLength   0x020458F8  arm
 *   STRBUF_GetChars   0x02045A90  arm
 *   sub_0201F41C   0x0201F41C  thumb
 *   GFL_NET_HANDLE_SetUserInfo 0x0203A424 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   POKE_TOOL_GetStatusCondition  0x02017F90  thumb
 *   BTL_POKEPARAM_ClearSickConts  0x021D63B8  thumb  ov093
 *   BTL_POKEPARAM_ClearHitHistory  0x021D67F4  thumb  ov093
 *   BTL_POKEPARAM_ClearFoughtList  0x021D6DC4  thumb  ov093
 *   gBtlPokeparamFileName     0x021F3AA4  data  a1
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 *   POKE_TOOL_GetGender  0x02017F00  thumb
 *   BTLV_CORE_PackBytes  0x021E8CE0  thumb  ov093
 *   BTL_CALC_ApplyStatStage  0x021D78E4  thumb  ov093
 *   gSemiInvulnerableContFlags  0x021F040C  data  ov093
 *   _dflt   0x0209B750  arm
 *   _dfltu  0x0209B790  arm
 *   _ddiv   0x0209D1E0  arm
 *   _dgr    0x0209B864  arm
 *   _dmul   0x0209B2E8  arm
 *   _dadd   0x0209AC04  arm
 *   _dsub   0x0209AF34  arm
 *   _dfix   0x0209C508  arm
 */
#include "btl_server_types.h"
#include "../../matched/include/G_StateData.h"
typedef unsigned long long u64;
#include "btl_client_types.h"
#include "btl_main_types.h"
#include "btl_pokeparam_types.h"
#include "btl_net_types.h"
#include "btl_field_types.h"

#define ENTRY(i) (&e[i])
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))
struct Unk021B8CB0;

struct Party;
struct U16Vec;
struct Rec8;
struct Buf;
struct Sub02008C20Obj;
struct Flags;
struct QA;
struct UtilWork;
struct Unk021D82FC;
struct Msg;
struct Out64B4;
struct Unk021BE518;
struct Unk021D82D0;
struct UtilSlots;
struct QL;
struct QI;
struct S_p12;


struct Entry_p11;
struct BtlvMessage;
struct Obj;
struct Result;
struct Pack;
struct BtlClientRecord;
struct Cmd;
struct S_p14;
struct Unk021D6C50;
struct Unk021D6C2C;
struct Unk021EFD70;
struct Sav;
struct QE;
struct QG;
struct QV;
struct Rat;

struct BtlvCore;
struct BtlPokeContainer;
struct BtlPokeParam;
struct Link;
struct Entry;
struct Unk021B8CB0 { u32 f0; u32 mode; };

typedef struct { u8 pad[0xC1]; unsigned char flag:1; unsigned char rest:7; } BtlMainRecordFlags;

struct Unk021EFD70 { u16 n0; volatile u16 n1; u8 b[6]; };

/* 021B9B54  ldrb r3,[r0,#0x18]; adds r2,r3,#1; strb r2,[r0,#0x18];
 *           lsls r2,r3,#2; str r1,[r0,r2] */

/* 021B9BF0  ldrb r2,[r0,#0x18]; cmp r1,r2; bhs; lsls r1,#2; ldr r0,[r0,r1] */







/* 021BA08C  movs r1,#0xaf; lsls r1,#2; ldr r0,[r0,r1] */



/* 021BA5D0  movs r1,#0x11; lsls r1,#6; ldrh r0,[r0,r1] */


/* 021BB840  strb r1,[r0,#0xb]; str r2,[r0]; strb r3,[r0,#0xa] */

/* 021BB964  ldr r0,[r0,#0x44] */

struct Unk021BE518 { u8 f0; u8 f1[6]; };

struct Buf { u32 wpos, rpos; };


struct BtlClientRecord { u32 value; u16 kind; u8 data, flag; };


struct Entry { u16 value; u16 id:5; u16 mode:4; u16 type:4; u16 marked:1; u16 special:1; u16 error:1; };











struct Entry_p08 { u16 value; u16 id:5, mode:4, type:4, marked:1, special:1, error:1; };



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

/* 021C8138  ldr r0,[r0,#0x10]; lsls r0,#0x10; lsrs r0,#0x10 */

struct S_p12 {
    u16 x;
    u16 y : 8;
    u16 n : 7;
    u16 z : 1;
    u32 arr[8];
};







struct Cmd { u32 a:8; u32 id:5; u32 b:19; };

struct Flags { u32 a:1; u32 b:31; };


struct S_p14 {
    unsigned int x : 10;
};

/* 021CC96C  ldr r0,[r0]; lsls #1; lsrs #0x1f */

/* 021CC99C  ldr r0,[r0]; lsls #3; lsrs #0x1f */

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

typedef struct { u8 id; u8 flag; u16 pad; BtlClientStepFn callbacks[3]; } BtlCommandEntry;

typedef struct { u32 kind : 4; u32 rest : 28; } Command;


typedef enum { OFFSET = 0x19a } Off;

typedef struct { u32 kind:4; u32 sub:3; u32 id:16; u32 rest:9; } Record_td;

typedef struct { u8 *q; u8 f[4]; } BtlClientMoveUsableEntry;

typedef enum { VALUE_ZERO, VALUE_ONE } Value;

struct Unk021D82D0 { u32 kind : 4; u32 sub : 3; u32 id : 16; u32 rest : 9; };



struct Row { u8 kind; u8 pad; u16 ids[4]; };


typedef struct { u8 pad[0x1B3]; volatile u8 count; } CountField;

typedef struct { int code; BtlClientSeqFn fn; } CodeEntry;

typedef struct { u16 a; u16 b; } Pair16;

struct StateDataL { u8 pad0[8]; int counter; u32 remaining; u32 pad10; u8 result[14]; };

union DView { struct StateDataL s; u32 w[9]; };

/* Trainer item effect checks of the AI: the item parameter that must be set
   and the stat stage or sick condition it applies to. */
typedef struct {
    u8 itemParam;
    u8 statIndex;
} BtlClientItemStatCheck;

typedef struct {
    u8 itemParam;
    u8 sickId;
} BtlClientItemSickCheck;

typedef struct {
    u8 pad00[0x28];
    u8 f28[0x40];
    u32 f68;
} Out;



extern int BTL_POKEPARAM_IsFainted(void *m);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *p);
extern u8 BTL_MAIN_GetClientTrainerIndex(u8 *p, u32 k, u8 n);
extern int BTL_MAIN_IsMultiMode(unsigned char **p);
extern void *BTL_MAIN_GetCompetitor(void ***p);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern int BTL_POKEPARAM_IsIllusionActive(struct BtlPokeParam *p);
extern int BTL_POKEPARAM_GetValue(void *p, int k);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKEPARTY_Init(struct Party *p);
extern u32 BTL_MAIN_GetRule(void **p);
extern int BTL_POKEPARAM_IsAbleToBattle(void *);
extern u32 func_020307B0(void *p);
extern void PMSI_PARAM_Copy(struct Rec8 *dst, const struct Rec8 *src);
extern u32 RECORD_AddOne(struct Sub02008C20Obj *, int);
extern u32 RECORD_AddCounter(struct Sub02008C20Obj *, int, u32);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 BTL_CALC_GetItemParam(void *p, u32 n);
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
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *p, int i);
extern u32 WAZA_TOOL_GetParam(u32 v, u32 n);
extern u32 BTL_ACTION_GetFightMove(Action *m);
extern int BTL_MAIN_GetCompetitorKind(unsigned int **p);
extern union Slot BTL_POKEPARAM_GetSickContRaw(void *p, int i);
extern u16 BTLV_CORE_GetSlotValue(union Slot v);
extern void BTL_ACTION_SetFight(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u8 BTL_POKEPARAM_FindMoveSlot(struct UtilWork *p, u16 id);
extern int WAZA_TOOL_GetFlag(void *bag, int item);
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
extern void BTL_POKEPARAM_SetAbility(struct BtlPokeParam *p, u32 ability);
extern u32 GF_STANDARD_Rand(void);
extern void BTL_POKEPARAM_ResetAllEffects(struct BtlPokeParam *);
extern int BTL_POKEPARAM_AddExp(struct Obj *p, u32 *remaining, struct Result *r);
extern u8 WAZA_TOOL_GetType(void *p);
extern int BTL_POKEPARAM_HasType(void *p, int k);
extern u16 WAZA_TOOL_GetPower(void *p);
unsigned int BTL_MAIN_GetActivePosPerSide(unsigned int **p);
extern int BTL_POKEPARAM_Transform(struct BtlPokeParam *a, struct BtlPokeParam *b);
extern void BTL_POKEPARAM_ClearIllusion(struct Unk021D6C2C *p);
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern void *TR_AI_Create(void **, u32, u32, u32, u16);
extern void *BTL_REC_CreateBuffer(u32);
extern void BTL_REC_DeleteBuffer(void *);
extern void TR_AI_Delete(void *);
extern u16 *BTL_REC_ReadEntry(u16 *, u32 *);
extern u32 BTL_REC_CountFlaggedRecords(void *);
extern void BTL_REC_ResetReader(void *);
extern void BTL_ADAPTER_ClearRecvHeader(void *);
extern u8 BTL_ADAPTER_GetRecvCommand(void *);
extern int BTL_ADAPTER_GetRecvData(int, void *);
extern int BTL_ADAPTER_SetRecvTarget(void *,void *,u32);
extern void GFL_USE_SetPlayersAudible(int,u32);
extern void PM_VOICE_ResetMasterVolume(void);
extern int GFL_USE_IsBgmFading(void);
extern void PM_VOICE_SetMasterVolume(u8);
extern void BTLV_CORE_ClearWaitWindow(u8 *p);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void BTLV_EFFECT_SetFlag26(int);
extern void *BTLV_EFFECT_GetWorkPtr(void);
extern int BTLV_CORE_GetWaitState(u8 *p);
extern void BTLV_CORE_SetCounterDisplay(char *p, u32 a, u32 b);
extern int BTLV_EFFECT_TimerIsExpired(int);
extern void BTLV_CORE_StartOpening(unsigned int *o, unsigned int key);
extern int BTLV_CORE_PollOpening(void *s);
extern void BTLV_EFFECT_TimerStart(int a, int b);
extern void BTLV_EFFECT_TimerSetVisible(u32 a, u32 b, u32 c);
extern void BTLV_CORE_ShowCounterValue(u8 *p, int v);
extern int BTL_REC_ReadSkipFlag(int, int);
extern void BTLV_CORE_InitInputWork(u8 *p, u8 v);
extern void BTLV_CORE_CancelWindowModeSelect(u8 *o);
extern int BTLV_CORE_PollWindowModeSelect(u8 *o, u8 *out);
extern void BTLV_SCU_InitMessage(struct BtlvMessage *p, int kind, int id);
extern void BTLV_SCU_AppendMessageArg(struct BtlvMessage *p, u32 val);
extern void BTLV_SCU_SetMessageParam(u8 *o, u8 v);
extern u32 *BTL_REC_ReadRecord(void *,u8,u8 *,u8 *);
extern void BTLV_CORE_BuildAndPrintMessage(char *p, void *h);
extern int BTLV_CORE_WaitMessage(u32 *p);
extern void BTL_CALC_ActionSetNone(u32 *p);
extern void BTLV_CORE_StartAutoSelectNotice(void *);
extern int BTLV_CORE_PollAutoSelectNotice(void *);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern u32 BTL_CALC_PeekMoveTarget(void *,void *,void *,u32,void *);
extern void BTLV_CORE_BuildAndPrintMessageNow(char *p, void *h);
extern void BTLV_CORE_StartActionMenu(char *, u8 *, int, int);
extern void BTLV_CORE_AbortActionMenu(char *p);
extern int BTLV_CORE_PollActionMenu(char *p);
extern void BTLV_CORE_CloseMenuToReselect(u32);
extern void BTL_PICK_Pop(u8 *);
extern int BTLV_CORE_IsMenuClosed(u32);
extern void BTLV_CORE_CloseMenu(void *);
extern void BTLV_EFFECT_AddPokeSprite(int, u32, u32, u32, u32);
extern void BTLV_EFFECT_StartEffect(u32 a);
extern int BTLV_CORE_PrintTrainerMessage(char *, u16, u16);
extern int BTL_CALC_IsGymLeaderTrainer(u32 n);
extern void BTLV_EFFECT_SaveBgmNo(u32);
extern int BTLV_EFFECT_PollLowHpBgm(void);
extern void GFL_USE_FadeOutBgm(u32);
extern int BTLV_EFFECT_IsBusy(void);
extern u32 TPOKE_DATA_FindRecord(u32,u32,u32);
extern u32 BTL_CALC_DivideMaxHp(void *p, u32 b);
extern void BTLV_CORE_StartMoveMenu(char *p, u8 *a, int b);
extern void BTLV_CORE_StartMoveMenuForEntry(char *p, u32 *q, int c);
extern void BTLV_CORE_AbortMoveMenu(void *);
extern u32 BTLV_CORE_PollMoveMenu(void *);
extern u32 func_021D832C(struct Unk021D82FC *p);
extern void BTL_ACTION_SetRotate(u32 *p, u32 sub);
extern u32 BTL_CALC_IsMultiFighterRule(u32);
extern void BTLV_CORE_StartTargetMenu(char *p, u8 *a, int b);
extern void BTLV_CORE_AbortTargetMenu(void *);
extern int BTLV_CORE_PollTargetMenu(char *p);
extern void BTLV_CORE_ReopenMoveMenu(char *p);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern void BTLV_CORE_StartMoveHighlight(u8 *p, u8 a, u8 b);
extern void BTLV_CORE_LockPartyChoice(unsigned int *p);
extern int BTLV_CORE_PollPartyMenu(u8 *p);
extern void BTLV_CORE_StartPartyMenu(char *, const u8 *, int, int, u8 *);
extern int BTL_PICK_GetLocked(void *);
extern u8 BTL_PICK_GetLast(void *);
extern void BTL_ACTION_SetChange(void *, u8, u8);
extern void BTLV_CORE_StartBagMenu(void *, int, int, int, u32, u32);
extern void BTLV_CORE_SkipBagPartyPrompt(u8 *p);
extern int BTLV_CORE_PollBagMenu(u8 *p);
extern u16 BTLV_CORE_GetSelectedItem(u8 *p);
extern u8 BTLV_CORE_GetInputTargetSlot(struct QV *p);
extern u8 BTLV_CORE_GetSelectedItemPocket(u8 *p);
extern u8 BTLV_CORE_GetInputResultFlag(u8 *p);
extern void BTL_ACTION_SetItem(u32 *p, u32 id, u32 sub, u32 val);
extern void BTLV_CORE_SaveBagCursors(char *p);
extern int BTLV_CORE_ConsumeMessageFlag(u32 *p);
extern void BTLV_CORE_StartYesNoMenu(u8 *a, u32 x, u32 y, u32 z);
extern int BTLV_CORE_PollYesNoMenu(void *, int *);
extern void func_021D8414(u32 *p);
extern void BTLV_CORE_StartWaitMessage(char *p);
extern int BTLV_CORE_UpdateWaitMessage(u32 *p);
extern void BTL_CALC_ActionSetForcedSkip(u32 *p);
extern u8 BTL_POKEPARAM_GetLastMoveSlot(u8 *p);
extern int BTL_POKEPARAM_HasMove(void *, u32);
extern void *BTL_FIELD_IsSlotInUse(char *arg0, int arg1);
extern int BTL_FIELD_IsMoveSealedBySlot(int, int, void *, u32);
extern u8 BTLV_CORE_GetSlotLow(union Slot);
extern u8 BTL_POKEPARAM_GetSickTurn(u8 *p, int i);
extern int BTL_CALC_GetTypeAffinityVsPair(int, u16);
extern int BTL_POKEPARAM_GetHitRecord(const u8 *p, int i, u32 j, u16 *out);
extern int BTL_POKEPARAM_GetHpRatioFixed(struct Rat *p);
extern u8 BTL_CALC_GetScanStartIndex(u32 a, u8 b);
extern void TR_AI_Start(int, u8 *, int);
extern int TR_AI_Think(u8 *);
extern u8 TR_AI_GetChosenMove(u8 *);
extern u8 TR_AI_GetChosenTarget(u8 *);
extern void BTL_PICK_InitSlotChoices(void *, u32, u32, u32);
extern void BTL_PICK_MarkSlotsSelectable(void *, u32);
extern void BTL_PICK_InitList(void *, void *);
extern void BTL_ACTION_SetChangeDepleted(u32 *p);
extern void BTL_REC_AppendPacket(u8 *p, const u8 *src, int n);
extern u8 BTL_REC_GetPacketId(u8 *p);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void BTLV_EFFECT_StopLowHpBgm(u32 a);
extern void BTLV_CORE_PrintMessageBuffer(char *p);
extern int PMSI_PARAM_IsEnabled(const u16 *p);
extern void *PMSI_PARAM_ToString(void *slots, unsigned int heap);
extern void BTLV_CORE_CopyMessageBuffer(unsigned char *p, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BTLV_CORE_BuildMessageToBuffer(char *p, void *h);
extern void MIi_CpuCopy32(const void *, void *, u32);
extern void BTLV_CORE_EndWaitMessage(char *p);
extern void BTLV_CORE_StartMonEffectTask(char *ctx, u16 a, u16 b);
extern int BTLV_CORE_WaitMonEffectTask(u32 *p);
extern void BTLV_CORE_StartMonSwap(void *s, u8 a, u8 b, u8 c);
extern int BTLV_CORE_WaitMonSwap(void *s);
extern void BTLV_CORE_PrintSideMessage(char *p, u16 k, int *c);
extern void GFL_USE_PlaySeDefaultVolume(unsigned int arg);
extern void BTLV_CORE_PrintTaggedMessage(char *p, u16 k, int *c);
extern void BTLV_CORE_PrintItemUseMessage(void *p, u8 b, u16 c);
extern int BTL_CALC_GetCurseTargetKind(void *p);
extern void BTLV_CORE_StartSceneEffect(u32 *p, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u8 s7);
extern int BTLV_CORE_WaitSceneEffect(u32 *p);
extern void BTLV_CORE_SetMonShown(void *ctx, int a, int b);
extern void BTLV_CORE_StartDamageEffect(void *s, u32 a, u32 b, u32 c);
extern int BTLV_CORE_WaitDamageEffect(void *s);
extern void BTLV_CORE_StartMultiDamageEffect(char *ctx, u32 n, int b, const u8 *c, u16 e);
extern int BTLV_CORE_ProcMultiDamageEffect(char *ctx);
extern void BTLV_CORE_StartMonSpriteUpdate(char *ctx, int a);
extern int BTLV_CORE_WaitMonSpriteUpdate(u32 *p);
extern void BTLV_EFFECT_GaugeSetStatusIcon(u32 a, u32 b);
extern void BTLV_CORE_StartMonReset(char *ctx, int a);
extern int BTLV_CORE_WaitMonReset(u32 *p);
extern void BTLV_CORE_StartMonRefresh(u32 *p, u32 a2);
extern int BTLV_CORE_WaitMonRefresh(u32 *p);
extern void BTLV_CORE_StartViewEffect262(void *ctx, int a);
extern int BTLV_CORE_WaitViewEffectDone(void *w, int v);
extern void BTLV_CORE_StartViewEffect261(void *ctx, int a);
extern int *BTL_FIELD_StoreCountdown(int *p, int a, int b);
extern void BTL_FIELD_ClearCountdown(int *p);
extern void BTLV_CORE_StartSlotEffect25F(u32 *p, u32 k);
extern int BTLV_CORE_WaitSlotEffect25F(u32 *p, u32 k);
extern void BTLV_CORE_StartRotation(void *w, u32 a, u32 b, u32 c, int d, int e);
extern int BTLV_CORE_WaitRotation(void *w);
extern void BTLV_EFFECT_StartPokeEffectId26E(int a);
extern void BTLV_EFFECT_StartPokeEffectId26F(u32 v);
extern void BTLV_CORE_StartMonSpriteChangeAt(char *ctx, u32 a, u32 b);
extern int BTLV_CORE_WaitMonSpriteChangeAt(u32 *p);
extern void BTLV_CORE_StartHitAnim(void *s, u32 a, int b, int c);
extern int BTLV_CORE_WaitHitAnim(void *s);
extern void BTLV_CORE_StartMonSpriteUnload(u32 *p);
extern int BTLV_CORE_WaitMonSpriteUnload(u32 *p);
extern int BTLV_EFFECT_GaugeIsSlotOccupied(int);
extern void BTLV_EFFECT_GaugeStartExpGain(int, u32);
extern int BTLV_EFFECT_GaugeIsAnimating(void);
extern void BTL_EVENT_ReleaseClientHandle(void *);
extern void BTL_POKEPARAM_ReloadFromParam(u8 *p);
extern void BTLV_EFFECT_GaugeRefreshForLevelUp(int, void *);
extern int GFL_USE_IsAnySeBusy(void);
extern void BTLV_CORE_StartViewEffect(char *ctx, int a, int b);
extern int BTLV_CORE_WaitViewEffect(void *);
extern void GFL_USE_SetBgmPlayerParam(void *);
extern int GFL_USE_PushBgm(void);
extern int GFL_USE_IsBgmPlaying(void);
extern int GFL_USE_PopBgm(void);
extern void BTLV_CORE_StartBallWindowOpen(u8 *, int, void *);
extern int BTLV_CORE_UpdateBallWindowOpen(u8 *);
extern void BTLV_CORE_StartBallWindowRefresh(u8 *);
extern int BTLV_CORE_UpdateBallWindowRefresh(u8 *);
extern void BTLV_CORE_StartBallWindowClose(u8 *);
extern int BTLV_CORE_UpdateBallWindowClose(u8 *);
extern int GFL_USE_IsSeqPlaying(unsigned int);
extern u16 POKE_TOOL_GetLevelUpMove(void *p, u32 *idx, u32 heap);
extern void BTLV_CORE_BuildAndPrintMessageFlag(char *p, void *h, int c);
extern void BTLV_CORE_StartMoveForgetScreen(u8 *p, u8 a, int c);
extern int BTLV_CORE_ProcMoveForgetScreen(u8 *p, u8 *out);
extern void POKE_TOOL_SetMoveSlot(void *p, u16 move, u32 slot);
extern void BTLV_EFFECT_StartEffectWithColor(u32, u16, u8, int, int);
extern void BTLV_EFFECT_StopLowHpBgmAndSuppress(u32);
extern void BTLV_EFFECT_ResumeVm(void);
extern void BTLV_EFFECT_StartEffectWithValue(int a, u16 b);
extern void BTLV_CORE_StartClearSidePosition(u32 a, int b, int c);
extern int BTLV_CORE_RunProc(u32 a);
extern void BTLV_CORE_ShowPortrait(u32 *p, u32 a2, u32 a3);
extern int BTLV_CORE_UpdatePortraitSlideIn(u32 *p, u32 a2);
extern void BTLV_CORE_ReloadPortrait(u32 *p, u32 a2);
extern int BTLV_CORE_UpdatePortraitMosaic(u32 *p, u32 a2);
extern void BTLV_CORE_StartMonSpriteLoad(u32 *p, u32 a2, u32 a3);
extern int BTLV_CORE_WaitMonSpriteLoad(u32 *p);
extern int BTL_ID_IsSimpleEffectId(u16);
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
void BTL_MAIN_SetRecordInvalid(BtlMainRecordFlags **p);
u32 BTL_MAIN_GetPrizeMoney(u8 *p);
u32 BTL_MAIN_GetBonusMoney(u8 *p);
u32 BTL_MAIN_CalcPenaltyMoney(char *p);
void BTL_MAIN_SetKeepBgm(u8 *p);
void BTL_MAIN_CopyLiveToSnapshotPoke(char *p, int i);
struct BtlPokeParam *BTL_MAIN_ResolveIllusionPoke(void *a, char *b, struct BtlPokeParam *c);
struct BtlPokeParam *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
void *BTL_SIDE_GetClientPokeParam(char *p, unsigned int i, unsigned int j);
struct BtlPokeParam *BTL_SIDE_GetClientPoke(void *p, u32 i, u8 j);
struct BtlPokeParam *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
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
int BTL_SERVER_CMD_ReadNext(BtlServerCmdBuffer *r, s32 *a);
u8 BTL_SERVER_CMD_ReadU8Wrapper(u8 *p);
extern void BTLV_CORE_StartViewEffectEx(struct BtlvCore *view, int viewPosA, int viewPosB, u32 param);
extern int BTLV_CORE_WaitViewEffectEx(struct BtlvCore *view);
extern void BTL_POKEPARAM_ChangeForm(struct BtlPokeParam *pokeParam, u8 form);
extern void BTLV_CORE_StartMonSpriteChange(struct BtlvCore *view, int viewPos);
extern int BTLV_CORE_WaitMonSpriteChange(struct BtlvCore *view);
extern void BTLV_CORE_StartPortraitSlideOut(struct BtlvCore *view, u32 position);
extern int BTLV_CORE_WaitPortraitSlideOut(struct BtlvCore *view, u32 position);
extern void BTL_POKEPARAM_SubHp(struct BtlPokeParam *pokeParam, u16 damage);
extern void BTL_POKEPARAM_AddHp(struct BtlPokeParam *pokeParam, u16 amount);
extern void BTL_POKEPARAM_DecrementMovePP(struct BtlPokeParam *pokeParam, u8 slot, u8 amount);
extern void BTL_POKEPARAM_DecrementRealMovePP(struct BtlPokeParam *pokeParam, u32 slot, u32 amount);
extern void BTL_POKEPARAM_MarkMoveUsed(struct BtlPokeParam *pokeParam, u8 slot);
extern void BTL_POKEPARAM_ZeroHp(struct BtlPokeParam *pokeParam);
extern u16 BTL_POKEPARAM_RestoreMovePP(struct BtlPokeParam *pokeParam, u32 slot, u8 amount);
extern u16 BTL_POKEPARAM_RestoreRealMovePP(struct BtlPokeParam *pokeParam, u32 slot, u8 amount);
extern u8 BTL_POKEPARAM_RaiseStatStage(struct BtlPokeParam *pokeParam, int statIndex, u8 steps);
extern u8 BTL_POKEPARAM_LowerStatStage(struct BtlPokeParam *pokeParam, int statIndex, u8 steps);
extern void BTL_POKEPARAM_SetStatStage(struct BtlPokeParam *pokeParam, int statIndex, u8 stage);
extern int BTL_POKEPARAM_RaiseLoweredStatStages(struct BtlPokeParam *pokeParam);
extern void BTL_POKEPARAM_ResetStatStages(struct BtlPokeParam *pokeParam);
extern int BTL_POKEPARAM_AddCritStage(struct BtlPokeParam *pokeParam, int delta);
extern void BTL_POKEPARAM_SetSickCont(struct BtlPokeParam *pokeParam, int sickIndex, union SickCont cont);
extern void BTL_POKEPARAM_ClearMajorStatus(struct BtlPokeParam *pokeParam);
extern void BTL_POKEPARAM_CureSick(struct BtlPokeParam *pokeParam, int sickIndex);
extern struct BtlPokeParam *BTL_SLOT_GetPoke(void *party, u32 index);
extern void BTL_POKEPARAM_StartTurnThreshold(struct BtlPokeParam *pokeParam, u16 threshold);
extern void BTL_POKEPARAM_ReloadAndResetEffects(struct BtlPokeParam *pokeParam);
extern void BTL_POKEPARAM_SetTypes(struct BtlPokeParam *pokeParam, int species);
extern void BTL_CALC_UnpackPokeIds(u32 packed, u8 *out);
extern u32 BTL_ID_GetTurnCheckSick(u32 index);
extern int BTL_POKEPARAM_TickSickCont(struct BtlPokeParam *pokeParam, u32 sickIndex, union SickCont *outCont, int *outCured);
extern void BTL_POKEPARAM_ConsumeHeldItem(struct BtlPokeParam *p, u16 v);
extern void BTL_POKEPARAM_RecordMoveUse(struct BtlPokeParam *p, u8 a, int f, u8 b, u16 c, u16 d);
extern void BTL_POKEPARAM_SetContFlag(struct BtlPokeParam *, u32);
extern void BTL_POKEPARAM_ClearContFlag(struct BtlPokeParam *, u32);
extern void BTL_POKEPARAM_SetTurnFlag(struct BtlPokeParam *, u32);
extern void BTL_POKEPARAM_ClearTurnFlag(struct BtlPokeParam *, u32);
extern void BTL_POKEPARAM_ResetEffectsOnSwitchOut(struct BtlPokeParam *p);
extern int BTL_FIELD_RegisterSlot(BtlFieldState *, u32, BtlFieldSlotKey, int);
extern int BTL_FIELD_AddSlotHolder(BtlFieldState *state, u32 slot, u32 pokeId);
extern void BTL_FIELD_RemoveHolderFromSlots(BtlFieldState *state, u32 pokeId);
extern int BTL_FIELD_RemoveSlot(BtlFieldState *state, u32 slot);
extern void BTL_POKEPARAM_SetCounter(struct BtlPokeParam *, int, u8);
extern void BTL_POKEPARAM_PassEffects(struct BtlPokeParam *, struct BtlPokeParam *);
extern void BTL_POKEPARAM_SetSubstituteHp(struct BtlPokeParam *, u16);
extern void BTL_POKEPARAM_ClearSubstitute(struct BtlPokeParam *p);
extern void BTL_MAIN_AddClientPoints(struct BtlMain *, u8, u8);
extern void BTL_SLOT_UpdateIllusion(struct BtlMain *, struct BtlSideSlot *, int);
extern void BTL_POKEPARAM_ClearConsumedItem(struct BtlPokeParam *p);
extern void BTL_POKEPARAM_CureSickBySource(struct BtlPokeParam *p, int sourceId);
extern void BTL_POKEPARAM_AddHitRecord(struct BtlPokeParam *p, struct BtlHitRecord *r);
extern void BTL_POKEPARAM_AdvanceTurn(struct BtlPokeParam *);
extern void BTL_EVENT_ClearClientReservedChoice(struct BtlPokeParam *);
extern void BTL_POKEPARAM_SetWeight(struct BtlPokeParam *p, u32 weight);
extern u8 BTL_FIELD_GetCountdownByte(void *);
extern u16 BTL_MAIN_GetTrainerItem(struct BtlMain *main, int slot, unsigned int index);
extern u8 BTL_POKEPARAM_GetCritStage(struct BtlPokeParam *p);
extern int BTLV_CORE_PollCounterInput(void *);
extern void BTLV_CORE_StartFadeIn(u32 *p);
extern void BTLV_CORE_SetCounterValueMode(u8 *p, int v, int w);
extern int BTLV_EFFECT_SuspendVmWait(void);
extern int BTLV_CORE_PollFadeInDone(u32 *p);
extern int POKE_REGULATION_GetDataSize(void);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void MIi_CpuClear16(u16 data, void *dst, u32 size);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern void sub_0201F41C(const u16 *src, u16 *dst, u32 n);
extern void GFL_NET_HANDLE_SetUserInfo(char *p, int a, int b, int c);
extern u32 POKE_TOOL_GetStatusCondition(void *);
extern u32 WAZA_TOOL_GetMaxPP(u32, u32);
extern u8 POKE_TOOL_GetGender(void *h);
void BTL_POKEPARAM_ReplaceMove(struct BtlPokeParam *p, u8 i, u16 a, u8 b, u32 c);
void BTL_POKEPARAM_SetStat(struct BtlPokeParam *p, int valueId, u16 v);
void BTL_POKEPARAM_SetItem(struct BtlPokeParam *p, u16 v);
int BTL_POKEPARAM_CanChangeStatStage(struct BtlPokeParam *p, int i, int sign);
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
BtlClientStepFn BTL_CLIENT_FindCommandStepFn(BtlClient *client, u32 id, int *outFlag);
void BTL_CLIENT_GetCursor(BtlClient *client, int *outCursor);
int BTL_CLIENT_IsWindowWaiting(BtlClient *client);
u32 BTL_CLIENT_IsWindowDone(BtlClient *client);
int BTL_CLIENT_StepOpenBattleWindow(BtlClient *client, int *state);
int BTL_CLIENT_PollWindowStep(BtlClient *client, int b);
void BTL_CLIENT_StoreMonParam(BtlClient *client);
u32 BTL_CLIENT_HasMonParamDropped(BtlClient *client);
void *BTL_CLIENT_GetLeadPartyMon(BtlClient *client);
int BTL_CLIENT_StepWindowModeSelect(BtlClient *client, int *state);
u32 BTL_CLIENT_PickWindowMode(u32 mode);
int BTL_CLIENT_ReturnTrue(void);
void BTL_CLIENT_StartWindowModeSend(BtlClient *client);
void BTL_CLIENT_StartTimeLimit(BtlClient *client);
int BTL_CLIENT_PollTimeLimitReady(BtlClient *client);
int BTL_CLIENT_PollTimeLimitAndSetSub(BtlClient *client, void *q);
void BTL_CLIENT_StopTimeLimit(BtlClient *client);
void BTL_CLIENT_BuildActionPromptMessage(BtlClient *client, struct BtlPokeParam *mon, u8 *outMessage);
void BTL_CLIENT_SetSubFn(BtlClient *client, void *q);
u32 BTL_CLIENT_RunSubFn(BtlClient *client);
u32 BTL_CLIENT_StepStartActionSelection(BtlClient *client, s32 *state);
int BTL_CLIENT_StepPlaybackRecordedAction(BtlClient *client, int *state);
void BTL_CLIENT_ResetActionCursor(BtlClient *client);
u32 BTL_CLIENT_InitActionSelection(BtlClient *client);
void BTL_CLIENT_ShowMessage(BtlClient *client, void *q);
int BTL_CLIENT_StepAutoSelectActions(BtlClient *client, int *state);
int BTL_CLIENT_StepSelectAction(BtlClient *client, u32 *state);
u32 BTL_CLIENT_StepShowSupportItemMessage(BtlClient *client, int *state);
u32 BTL_CLIENT_FindSupportItem(BtlClient *client, u16 *outItemKey);
int BTL_CLIENT_StepSelectMove(BtlClient *client, u32 *state);
void BTL_CLIENT_BuildMoveUsableTable(BtlClient *client, BtlClientMoveUsableEntry *out);
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
u32 BTL_CLIENT_IsActionForced(u8 *client, void *mon, u8 *outAction);
u32 BTL_CLIENT_SetStruggleIfNoMoves(BtlClient *client, void *mon, u32 outAction);
void BTL_CLIENT_SetStruggleAction(struct Unk021D82D0 *out, BtlClient *client, void *mon);
int BTL_CLIENT_IsMoveSelectionBlocked(BtlClient *client, void *mon, u32 move, void *outMessage);
u32 BTL_CLIENT_BuildUsableMoveMask(BtlClient *client, void *mon, u8 *out);
int BTL_CLIENT_IsHeldItemEffective(BtlClient *client, void *mon);
u32 BTL_CLIENT_GetEscapeBlocker(BtlClient *client, void *mon, u8 *outBlockerPokeId, u16 *outBlockerAbility);
u32 BTL_CLIENT_GetEscapeBlockerForSide(BtlClient *client, u8 *outBlockerPokeId, u16 *outBlockerAbility);
u32 BTL_CLIENT_FindTrapper(BtlClient *client, void *mon, u8 *outBlockerPokeId, u16 *outBlockerAbility);
int BTL_CLIENT_CanShadowTagTrap(void *client, void *mon);
int BTL_CLIENT_CanArenaTrapTrap(BtlClient *client, void *mon);
int BTL_CLIENT_CanMagnetPullTrap(void *client, void *mon);
void BTL_CLIENT_ClearSlotOrder(BtlClient *client);
int BTL_CLIENT_HasSlotInOrder(BtlClient *client, int v);
void BTL_CLIENT_SetSlotOrder(BtlClient *client, u32 i, u32 v);
int BTL_CLIENT_ChooseAiSwitchTarget(BtlClient *client, void *mon, u32 orderSlot, u8 *outMember);
struct BtlPokeParam *BTL_CLIENT_PickRandomFoe(BtlClient *client, int positionId);
int BTL_CLIENT_IsCountdownEndingNext(void *client, void *mon);
int BTL_CLIENT_ShouldSwitchVsWonderGuard(BtlClient *client, void *mon, void *foe);
int BTL_CLIENT_ShouldSwitchNoEffectiveMove(BtlClient *client, void *mon, void *foe);
int BTL_CLIENT_ShouldSwitchWhileLocked(BtlClient *client, void *mon, void *target);
int BTL_CLIENT_FindSwitchFromHitHistory(BtlClient *client, void *mon, void *target, u8 *out);
int BTL_CLIENT_FindNaturalCureSwitch(BtlClient *client, void *mon, u8 *out);
int BTL_CLIENT_FindSwitchByTypeMatchup(BtlClient *client, void *mon, void *target, u8 *out);
int BTL_CLIENT_FindMemberWithAbility(BtlClient *client, u16 ability, u8 *outMember);
int BTL_CLIENT_AnyMemberHasMoveVsTarget(BtlClient *client, void *target, int minAffinity);
int BTL_CLIENT_FindMemberResistingType(BtlClient *client, u8 attackType, int maxAffinity, u8 *outMember);
int BTL_CLIENT_HasMoveWithAffinityVsTarget(BtlClient *client, void *mon, void *target, int minAffinity);
u8 BTL_CLIENT_PickRotationPosition(BtlClient *client);
int BTL_CLIENT_StepAutoChooseActions(BtlClient *client, u32 *state);
u8 BTL_CLIENT_ListAbleMons(BtlClient *client, u8 *ableIndexes);
void BTL_CLIENT_SortMonsByMovePower(BtlClient *client, u8 *partyOrder, u8 orderCount, void *targetMon);
void BTL_CLIENT_BuildSlotChoices(BtlClient *client, u32 a, u32 b, void *q, void *out);
void BTL_CLIENT_SetChangeActionsFromChoice(BtlClient *client, u8 *choice);
void BTL_CLIENT_SetChangeActionsFirstAble(BtlClient *client);
u8 BTL_CLIENT_CollectOwnReceivedIds(BtlClient *client, u8 *ownIds);
int BTL_CLIENT_StepAskYesNo(BtlClient *client, int *state);
int BTL_CLIENT_StepChoiceMode2(BtlClient *client, int *state);
int BTL_CLIENT_StepChoiceMode1(BtlClient *client, int *state);
int BTL_CLIENT_ChooseReplacementsAuto(BtlClient *client);
int BTL_CLIENT_StepForwardToSubFn(BtlClient *client, int *state);
int BTL_CLIENT_StepChooseReplacement(BtlClient *client, int *state, u8 choiceMode);
int BTL_CLIENT_IsDoubleBattleLeadAlive(BtlClient *client);
int BTL_CLIENT_TrySetRotateAction(BtlClient *client, void *action);
int BTL_CLIENT_StepAskSwitchBeforeSendOut(BtlClient *client, int *state);
int BTL_CLIENT_RecordReceivedPacket(BtlClient *client);
int BTL_CLIENT_StepShowResultIfView(BtlClient *client, int *state);
int BTL_CLIENT_StepShowResultMessage(BtlClient *client, int *state, void *view);
int BTL_CLIENT_GetOutcomeForClient(BtlClient *client);
int BTL_CLIENT_StepShowTrainerResultIfView(BtlClient *client, int *state);
int BTL_CLIENT_StepShowTrainerResult(BtlClient *client, int *state, void *view);
int BTL_CLIENT_StepShowEndSpeechIfView(BtlClient *client, int *state);
int BTL_CLIENT_StepShowEndSpeech(BtlClient *client, int *state, void *view);
void BTL_CLIENT_ShowEndSpeech(BtlClient *client, int outcome, int trainerSide);
int BTL_CLIENT_StepShowPrizeMoneyMessage(BtlClient *client, int *state);
int BTL_CLIENT_StepShowBlackoutMessages(BtlClient *client, int *state);
int BTL_CLIENT_StepShowFixedMessage(BtlClient *client, int *state);
int BTL_CLIENT_StepRunServerCommandsIfView(BtlClient *client, int *state);
int BTL_CLIENT_StepRunServerCommands(BtlClient *client, int *state, void *view);
int BTL_CLIENT_StepShowRecallMessage(BtlClient *client, int *state, int *args);
int BTL_CLIENT_PickRecallMessageId(BtlClient *client, u8 targetClient, int *addTrainerName);
int BTL_CLIENT_StepPlayRecallAnim(BtlClient *client, int *state, int *args);
int BTL_CLIENT_StepSendOutMon(BtlClient *client, int *state, const u32 *params);
int BTL_CLIENT_PickSendOutMessageId(BtlClient *client);
int BTL_CLIENT_StepShowSideMessage(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepShowSideMessageWithSound(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepShowTaggedMessage(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepShowTaggedMessageWithSound(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepShowItemUseMessage(BtlClient *client, int *state, u32 *args);
u32 BTL_CLIENT_GetMoveAnimTarget(BtlClient *client, u32 moveId, u8 attackerId);
int BTL_CLIENT_StepPlayMoveAnim(BtlClient *client, int *state, const u32 *args);
int BTL_CLIENT_StepSetMonVisibility(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepPlayMonTaskAnim(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepPlayMultiMonAnim(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepUpdateMonGaugeThenMessage(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepStartEffectForMon(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepPlaySubstituteAnim(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepFaintMon(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepReviveMon(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepPlayMonEffect262(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepPlayMonEffect261(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepStartWeather(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepEndWeather(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepUpdateMonGauge(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepPlayMonAnim(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepUpdateMonGaugeCopy(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepRotatePositions(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepRotatePositionsTwice(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepPlayEffectOnMon(BtlClient *client, int *state, unsigned int *args);
int BTL_CLIENT_StepPlayEffectOnMonFast(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepTransformMon(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepPlayHitEffect(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepChangeBgm(int unusedClient, int unusedState, int *bgmId);
int BTL_CLIENT_StepPlayViewSequence(BtlClient *client, int *state);
int BTL_CLIENT_StepAddEffortValues(BtlClient *client, int unusedState, u32 *args);
int BTL_CLIENT_StepGiveExp(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_ForgetMoveSoundCallback(int step);
int BTL_CLIENT_StepLearnLevelUpMoves(BtlClient *client, int *state, void *mon);
int BTL_CLIENT_StepThrowBall(BtlClient *client, int *state, const u32 *args);
int BTL_CLIENT_StepShowBallBlocked(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepClearSidePosition(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepSetAbilityWithPopup(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepSwapAbilitiesWithPopup(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepClearIllusion(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepPlayEffectById(BtlClient *client, int *state, unsigned int *args);
int BTL_CLIENT_StepPlayMonSimpleEffect(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_CmdSwapViewPositions(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdChangeForm(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdShowStatusPanel(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdHideStatusPanel(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdHpMinus(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdHpPlus(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdPpMinusOriginal(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdPpMinusWorking(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdMarkMoveUsed(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdHpZero(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdPpPlusOriginal(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdPpPlusWorking(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdStatStageUp(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdStatStageDown(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdSetStatStages(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdRecoverStatStages(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdResetStatStages(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdAddCritStage(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdSetSick(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdCureMajorSick(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdCureSick(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdMemberIn(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdSetPokeType(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdCureSickMulti(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_StepConsumeHeldItem(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepRecordMoveUse(BtlClient *client, int *state, const u32 *args);
int BTL_CLIENT_StepSetContFlag(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepClearContFlag(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepSetTurnFlag(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepClearTurnFlag(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepSetAbility(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepSetItem(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepReplaceMove(BtlClient *client, int *state, const u32 *args);
int BTL_CLIENT_StepResetEffectsOnSwitchOut(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepRegisterFieldSlot(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepAddFieldSlotHolder(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepRemoveFieldHolder(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepRemoveFieldSlot(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepSetPokeCounter(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepPassEffects(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepSetSubstituteHp(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepClearSubstitute(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepAddClientPoints(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepUpdateIllusion(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepClearConsumedItem(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepCureSickBySource(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepAddHitRecord(BtlClient *client, int *state, const u32 *args);
int BTL_CLIENT_StepAdvanceTurn(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepTickFieldSlots(BtlClient *client);
int BTL_CLIENT_StepSetStat(BtlClient *client, int *state, u32 *args);
int BTL_CLIENT_StepSetWeight(BtlClient *client, int *state, u32 *args);
u8 BTL_CLIENT_GetClientId(BtlClient *client);
void *BTL_CLIENT_GetSideData(BtlClient *client);
u8 BTL_CLIENT_GetFieldCountdownByte(BtlClient *client);
u8 BTL_CLIENT_GetPointCounter(BtlClient *client);
void BTL_CLIENT_LoadTrainerItems(BtlClient *client);
u32 BTL_CLIENT_TakeTrainerItemToUse(BtlClient *client, struct BtlPokeParam *mon, void *party);
int BTL_CLIENT_IsStatItemUsable(u32 itemId, struct BtlPokeParam *mon);
int BTL_CLIENT_IsSickItemUsable(u32 itemId, struct BtlPokeParam *mon);
void BTL_CLIENT_ResetCounter(BtlClientCounter *counter);
void BTL_CLIENT_SetCounterMaximum(BtlClientCounter *counter, u32 v);
int BTL_CLIENT_IsCounterFadeDone(BtlClientCounter *counter);
void BTL_CLIENT_RequestCounterAdvance(BtlClientCounter *counter);
u8 BTL_CLIENT_GetCounterMode(BtlClientCounter *counter);
void BTL_CLIENT_StartCounterReplay(BtlClientCounter *counter, u16 v);
void BTL_CLIENT_StopCounterReplay(BtlClientCounter *counter);
int BTL_CLIENT_IsCounterReplayDone(BtlClientCounter *counter);
u16 BTL_CLIENT_GetCounterTarget(BtlClientCounter *counter);
int BTL_CLIENT_TryLockCounter(BtlClientCounter *counter);
void BTL_CLIENT_UnlockCounter(BtlClientCounter *counter);
void BTL_CLIENT_DisableCounter(BtlClientCounter *counter);
void BTL_CLIENT_TickCounter(BtlClient *client, BtlClientCounter *counter);
extern struct Unk021EFD70 gBtlPosTables[];
extern BtlEffortValueStat gEffortValueStatTable[];
extern struct SizeEntry gHandExRecordSizeTable[0x3B];
extern u8 gBtlClientFileName[];
extern const BtlCommandEntry gBtlClientCommandTable[15];
extern const u16 gBtlClientSupportItemKeys[4];
extern const struct Row gBtlClientAiHitKindRows[4];
extern const CodeEntry gServerCommandHandlers[];
extern Pair16 gWeatherEffects[5];
extern u16 gEffortValueParams[];
extern union DView gExpGainWork;
extern struct StateData sLevelUpMoveScan;
extern const u16 gCatchShakeMessages[];
extern u8 gBtlClientItemSlotLimits[];
extern BtlClientItemStatCheck gBtlClientItemStatChecks[];
extern BtlClientItemSickCheck gBtlClientItemSickChecks[];
extern const char gBtlNetSourceName[];
extern const char gBtlPokeparamFileName[];
extern const u32 gSemiInvulnerableContFlags[4];

BtlClient *BTL_CLIENT_Create(u8 *battleMain, u8 *sideSet, int netEnabled, int netSystem, u16 clientIndex, u16 slotTotal, u8 clientKind, int isCommBattle, int isReplay, BtlClientRng *rngInit, u16 heapId)
{
    BtlClient *client;
    u32 slot;
    int useNet, recordKey;
    client = func_02030734(heapId, 0x1b8, 1, (const char *)gBtlClientFileName, 0x209);
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
    client->workBuffer = func_02030734(heapId, 0xbc0, 1, (const char *)gBtlClientFileName, 0x21a);
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
    BTL_CLIENT_ResetCounter(&client->counter);
    BTL_CLIENT_LoadTrainerItems(client);
    client->rng = *rngInit;
    if (client->kind == 1 && isReplay == 0) {
        recordKey = BTL_MAIN_GetTrainerAiFlags(client->main, client->clientId);
        client->recorder = TR_AI_Create(client->main, BTL_MAIN_GetServerFlow(client->main), (u32)client->side, recordKey, client->heapId);
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
 if(client->recorder)TR_AI_Delete(client->recorder);
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
void BTL_CLIENT_AttachRemoteLink(BtlClient *client, void *a) { client->kind=2; client->remoteLink=a; BTL_CLIENT_SetCounterMaximum(&client->counter,BTL_REC_CountFlaggedRecords(a)); }

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
void BTL_CLIENT_StartRemoteStep(BtlClient *client, u16 n) { BTL_REC_ResetReader(client->remoteLink); BTL_ADAPTER_ClearRecvHeader(client->netChannel); BTL_CLIENT_StartCounterReplay(&client->counter,n); BTL_CLIENT_SetStepFn(client,(u32)BTL_CLIENT_StepRemote); }

void BTL_CLIENT_StartMainStep(BtlClient *client) { BTL_CLIENT_StopCounterReplay(&client->counter); BTL_CLIENT_SetStepFn(client,(u32)BTL_CLIENT_StepMain); }

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
u16 BTL_CLIENT_GetQueuedCommandWord(BtlClient *client) { return client->counter.maximum; }

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
    BTL_CLIENT_TickCounter(client,&client->counter);
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
                if (!BTL_CLIENT_TryLockCounter(&client->counter)) { client->stepPhase = 6; break; }
            } else BTL_CLIENT_UnlockCounter(&client->counter);
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
            if (BTL_CLIENT_IsCounterFadeDone(&client->counter)) client->stepPhase = 4;
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
        if (BTL_CLIENT_IsCounterFadeDone(&client->counter)) client->stepPhase = 4;
        break;
    case 4:
        if (BTL_CLIENT_GetCounterMode(&client->counter) == 1) client->stepPhase = 7;
        else {
            if (client->view) { GFL_USE_SetPlayersAudible(1,62); PM_VOICE_ResetMasterVolume(); }
            client->stepPhase = 5;
        }
        break;
    case 5:
        if (!GFL_USE_IsBgmFading()) {
            n = BTL_CLIENT_GetCounterTarget(&client->counter);
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
    BTL_CLIENT_TickCounter(client,&client->counter);
    switch (client->stepPhase) {
    case 0:
        client->stepPhase = 1;
    case 1:
        if (!BTL_CLIENT_IsCounterReplayDone(&client->counter)) {
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
                BTLV_CORE_ClearWaitWindow(client->view);
                GFL_USE_FadeInBgmFull(30);
                BTLV_EFFECT_SetFlag26(0);
                PM_VOICE_ResetMasterVolume();
            }
            client->stepPhase = 4;
        }
        break;
    case 2:
        if ((client->stepFn)(client,&client->stepState)) {
            client->stepPhase = 3;
            client->stepState = 0;
            if (BTLV_EFFECT_GetWorkPtr()) BTLV_EFFECT_SetFlag26(1);
        }
        break;
    case 3:
        if (BTL_ADAPTER_SetRecvTarget(client->netChannel,client->sendData,client->sendSize)) client->stepPhase = 1;
        break;
    case 4:
        if (client->view) {
            if (BTLV_CORE_GetWaitState(client->view)) {
                if (!GFL_USE_IsBgmFading()) {
                    n = (int)BTL_CLIENT_GetCounterTarget(&client->counter);
                    BTLV_CORE_SetCounterDisplay(client->view,n,n);
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
int BTL_CLIENT_IsWindowWaiting(BtlClient *client) { if(client->kind!=2) { if(client->timeElapsed) return BTLV_EFFECT_TimerIsExpired(0); return 0; } return client->flags.bit.windowOpen; }

u32 BTL_CLIENT_IsWindowDone(BtlClient *client) { return client->flags.bit.windowDone; }

/*
 * Levers (from the DIFF note): case 0 is the call written in each arm, `!= 4` arm first
 * (a-boolean-argument-is-a-call-in-each-arm.md; a flag value hoists `movs r1,#1`);
 * BTLV_EFFECT_TimerStart takes two arguments as its own file says, the second being the 0xe4
 * halfword still live in r1 from the || test; BTL_CLIENT_GetCounterTarget is declared u32 here because
 * the original narrows its result before the u16 parameter of BTLV_CORE_ShowCounterValue.
 */
int BTL_CLIENT_StepOpenBattleWindow(BtlClient *client, int *state)
{
    switch (*state) {
    case 0:
        if ((int)BTL_MAIN_GetCompetitor(client->main) != 4) {
            BTLV_CORE_StartOpening(client->view, 0);
        } else {
            BTLV_CORE_StartOpening(client->view, 1);
        }
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_CORE_PollOpening(client->view) == 0) {
            break;
        }
        client->timeLimit = BTL_MAIN_GetLimitTimeCommand(client->main);
        client->timeElapsed = BTL_MAIN_GetLimitTimeGame(client->main);
        if (client->timeLimit != 0 || client->timeElapsed != 0) {
            BTLV_EFFECT_TimerStart(client->timeElapsed, client->timeLimit);
            if (client->timeElapsed != 0) {
                BTLV_EFFECT_TimerSetVisible(0, 1, 1);
            }
        }
        BTL_CLIENT_StoreMonParam(client);
        if (BTL_CLIENT_IsMainStepActive(client) != 0) {
            BTLV_CORE_ShowCounterValue(client->view, (u16)((u32)BTL_CLIENT_GetCounterTarget(&client->counter)));
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
                BTL_CLIENT_RequestCounterAdvance(&client->counter);
        }
        return r4;
    }
    BTL_REC_ReadSkipFlag((int)client->remoteLink, client->clientId);
    return 1;
}

void BTL_CLIENT_StoreMonParam(BtlClient *client) { void *a; a=BTL_CLIENT_GetLeadPartyMon(client); if(a) client->lastMonValue=BTL_POKEPARAM_GetValue(a,13); }

u32 BTL_CLIENT_HasMonParamDropped(BtlClient *client) { void *a; u32 now,old; a=BTL_CLIENT_GetLeadPartyMon(client); if(a) { now=BTL_POKEPARAM_GetValue(a,13); old=client->lastMonValue; if(now>=old) return 0; return _u32_div_f((old-now)*100,now); } return 0; }

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
        BTLV_CORE_InitInputWork(client->view, client->windowMode);
        BTL_CLIENT_StartTimeLimit(client);
        *state = *state + 1;
        break;
    case 1:
        if (BTL_CLIENT_PollTimeLimitReady(client) != 0) {
            BTLV_CORE_CancelWindowModeSelect(client->view);
            *state = 2;
        } else if (BTLV_CORE_PollWindowModeSelect(client->view, &chosenMode) != 0) {
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

    v = (u32)(((u64)GF_STANDARD_Rand() * 100) >> 32);
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

void BTL_CLIENT_StartTimeLimit(BtlClient *client) { if(client->timeLimit) { BTLV_EFFECT_TimerSetVisible(1,1,1); client->limitReady=0; } }

/*
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Same blocker as 021CDDA0: ov094 0x021F8524 needs a label/witness.
 */
int BTL_CLIENT_PollTimeLimitReady(BtlClient *client) { if(client->timeLimit!=0) { if(client->limitReady==0) { if(BTLV_EFFECT_TimerIsExpired(1)) client->limitReady=1; } return client->limitReady; } return 0; }

int BTL_CLIENT_PollTimeLimitAndSetSub(BtlClient *client, void *q) { if(BTL_CLIENT_PollTimeLimitReady(client)) { if(q) BTL_CLIENT_SetSubFn(client,q); return 1; } return 0; }

void BTL_CLIENT_StopTimeLimit(BtlClient *client) { if(client->timeLimit!=0) BTLV_EFFECT_TimerSetVisible(1,0,0); }

void BTL_CLIENT_BuildActionPromptMessage(BtlClient *client, struct BtlPokeParam *mon, u8 *outMessage)
{
    if (BTL_MAIN_GetRule(client->main) != 3) {
        BTLV_SCU_InitMessage((struct BtlvMessage *)outMessage, 1, 0x45);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)outMessage, BTL_POKEPARAM_GetPokeId(mon));
        BTLV_SCU_SetMessageParam(outMessage, 0);
    } else {
        BTLV_SCU_InitMessage((struct BtlvMessage *)outMessage, 1, 0x46);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)outMessage, client->clientId);
        BTLV_SCU_SetMessageParam(outMessage, 0);
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
        if (skipFlag) BTL_CLIENT_RequestCounterAdvance(&client->counter);
        *(u32 * *)&client->sendData = record;
        client->sendSize = wordCount * 4;
        if (((Command *)record)->kind == 8) {
            BTL_CLIENT_DisableCounter(&client->counter);
            if (client->view) {
                BTLV_SCU_InitMessage((struct BtlvMessage *)&client->messageA,1,0xb7);
                BTLV_CORE_BuildAndPrintMessage(client->view,&client->messageA);
                (*state)++;
            } else {
                BTL_CLIENT_ResetActionCursor(client);
                *(u8 *)&client->flags |= 0x10;
                return 1;
            }
        } else if (((Command *)record)->kind == 9) {
            *(u8 *)&client->flags |= 0x20;
            BTL_CLIENT_DisableCounter(&client->counter);
            if (client->view) {
                BTLV_SCU_InitMessage((struct BtlvMessage *)&client->messageA,1,0xb8);
                BTLV_CORE_BuildAndPrintMessage(client->view,&client->messageA);
                *state += 2;
            } else {
                BTL_CLIENT_ResetActionCursor(client);
                return 1;
            }
        } else return 1;
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(client->view)) {
            BTL_CLIENT_ResetActionCursor(client);
            *(u8 *)&client->flags |= 0x10;
            return 1;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMessage(client->view)) {
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

void BTL_CLIENT_ShowMessage(BtlClient *client, void *q) { BTLV_CORE_BuildAndPrintMessage(client->view,q); client->redrawRequest=1; }

int BTL_CLIENT_StepAutoSelectActions(BtlClient *client, int *state)
{
    u8 usableMask[4];
    u32 moveIndex;
    u32 moveId;
    switch (*state) {
    case 0:
        BTLV_CORE_StartAutoSelectNotice(client->view);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_PollAutoSelectNotice(client->view)) {
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
 * relocations have no witness in the current index: BTLV_CORE_AbortActionMenu and BTLV_CORE_CloseMenu. Both
 * leaves are now filed (src/matched/ov/ov093_func_021E979C.c, ov093_func_021E9954.c, EXACT);
 * the verdict becomes EXACT once the integrator regenerates the index. The original extent is
 * 772 B: 756 B of C plus the 16 B linker veneer at 021CE7C4 (not C, resolved as a veneer witness).
 * Two changes closed the 253 B residue of the older draft: (1) no shared increment label and
 * no goto: each arm writes ++*st; break; so the compiler builds the single shared state store
 * and one epilogue (756 to 748 B, branch layout); (2) the countdown loop reads the index byte
 * through a struct field (BtlClient.slotIndex at 0x11D and BtlClient.clientId at 0x1A6) instead of a count pointer local, so
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
            BTLV_CORE_BuildAndPrintMessageNow((client->view), &client->messageA);
            client->redrawRequest = 0;
            client->prevSlotIndex = client->slotIndex;
            ++*state; break;
        }
        *state += 2U;
        break;
    case 2:
        if (!BTLV_CORE_WaitMessage((client->view))) return 0;
        ++*state;
        /* falls through */
    case 3:
        BTLV_CORE_StartActionMenu((client->view), (client->activeMon), client->slotIndex > client->slotsDone, (int)(client->actionCursor));
        ++*state; break;
    case 4:
        if (BTL_CLIENT_PollTimeLimitAndSetSub(client, (void *)((u32)BTL_CLIENT_StepAutoSelectActions))) {
            BTLV_CORE_AbortActionMenu((client->view));
            return 0;
        }
        viewResult = BTLV_CORE_PollActionMenu((client->view));
        switch (viewResult) {
        case 3:
            if (BTL_POKEPARAM_HasSick((client->activeMon), 0x21)) {
                BTLV_CORE_CloseMenuToReselect(((u32)client->view));
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
                BTLV_CORE_CloseMenuToReselect(((u32)client->view));
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
                --client->slotIndex;
                if (!BTL_CLIENT_IsActionForced((u8 *)client, BTL_SIDE_GetClientPokeParam((client->side), client->clientId, client->slotIndex), 0)) {
                    client->pointCounter += BTL_CLIENT_GetSlotFlag(client, client->slotIndex);
                    if (BTL_CALC_ActionGetKind((Action *)((u8 *)client->actions + client->slotIndex * 4)) == 3)
                        BTL_PICK_Pop(client->choiceFlags);
                    if (BTL_CALC_ActionGetKind((Action *)((u8 *)client->actions + client->slotIndex * 4)) == 2)
                        BTL_CLIENT_FlushSlotLinkWord(client, client->slotIndex);
                    BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectAction));
                    return 0;
                }
            } while (client->slotIndex != 0);
            break;
        }
        break;
    case 5:
        if (BTLV_CORE_IsMenuClosed(((u32)client->view))) *state = 3;
        break;
    case 6:
        BTLV_CORE_CloseMenu((client->view));
        ++*state; break;
    case 7:
        if (!BTLV_CORE_IsMenuClosed(((u32)client->view))) break;
        BTLV_SCU_InitMessage((struct BtlvMessage *)&client->messageA, 1, 0xC5);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)&client->messageA, BTL_POKEPARAM_GetPokeId((client->activeMon)));
        BTL_CLIENT_ShowMessage(client, (u8 *)&client->messageA);
        ++*state; break;
    case 8:
        if (BTLV_CORE_WaitMessage((client->view))) *state = 1;
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
        BTLV_EFFECT_AddPokeSprite(BTL_MAIN_GetTrainerType(client->main, opponentClientId), 9, 0, 0, zero);
        BTLV_EFFECT_StartEffect(0x270);
        BTLV_CORE_PrintTrainerMessage(client->view, trainerId, client->receivedCode);
        if ((u16)(client->receivedCode + 0xffed) <= 1 &&
            BTL_CALC_IsGymLeaderTrainer(BTL_MAIN_GetTrainerType(client->main, opponentClientId)) && !client->flags.bit.resultPending) {
            BTLV_EFFECT_SaveBgmNo(0x47b);
            if (!BTLV_EFFECT_PollLowHpBgm()) {
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
        if (!BTLV_EFFECT_IsBusy() && BTLV_CORE_WaitMessage(client->view)) {
            BTLV_EFFECT_StartEffect(0x271);
            ++*state;
        }
        break;
    case 3:
        if (!BTLV_EFFECT_IsBusy()) BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectAction));
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
            if (TPOKE_DATA_FindRecord(trainerId,itemKey,client->heapId)) {
                switch (itemKey - 0x11) {
                case 1:
                    hpNow = BTL_POKEPARAM_GetValue(leadMon,13);
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
                        hpNowPair = BTL_POKEPARAM_GetValue(leadMon,13);
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
            BTL_CLIENT_BuildMoveUsableTable(client, (BtlClientMoveUsableEntry *)client->recvEntry);
            *state = 2;
        }
        break;
    case 1:
        BTLV_CORE_StartMoveMenu(client->view, (u8 *)(client->activeMon), (u32)client->actionCursor);
        *state = 3;
        break;
    case 2:
        BTLV_CORE_StartMoveMenuForEntry(client->view, (u32 *)client->recvEntry, (int)client->actionCursor);
        *state = 3;
        break;
    case 3:
        if (BTL_CLIENT_PollTimeLimitAndSetSub(client, (void *)((u32)BTL_CLIENT_StepAutoSelectActions))) {
            BTLV_CORE_AbortMoveMenu(client->view);
            return 0;
        }
        if (BTLV_CORE_PollMoveMenu(client->view)) {
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
                    BTLV_SCU_SetMessageParam((u8 *)&client->messageA, 0xff);
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
        BTLV_CORE_StartTargetMenu(client->view, (u8 *)(client->activeMon), (u32)client->actionCursor);
        *state = 6;
        break;
    case 6:
        if (BTL_CLIENT_PollTimeLimitAndSetSub(client, (void *)((u32)BTL_CLIENT_StepAutoSelectActions))) {
            BTLV_CORE_AbortTargetMenu(client->view);
            return 0;
        }
        actionKind = BTLV_CORE_PollTargetMenu(client->view);
        if (actionKind == 1) BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
        else if (actionKind == 2) *state = 1;
        break;
    case 7:
        if (BTLV_CORE_WaitMessage(client->view)) {
            BTLV_CORE_ReopenMoveMenu(client->view);
            *state = 3;
        }
        break;
    }
    return 0;
}

void BTL_CLIENT_BuildMoveUsableTable(BtlClient *client, BtlClientMoveUsableEntry *out)
{
    u32 memberIndex;
    u32 moveSlot;
    u8 *mon;
    u32 moveCount;
    u32 moveIndex;
    BtlClientMoveUsableEntry *entry;
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
        BTLV_CORE_StartMoveHighlight((u8 *)(client->view), client->highlightSlot, client->highlightKind);
        *st = *st + 1;
        break;
    case 1:
        zero = 0;
        if (BTL_CLIENT_PollTimeLimitAndSetSub(client, 0) != 0) {
            BTLV_CORE_LockPartyChoice((unsigned int *)(client->view));
            *st = 2;
            return zero;
        }
        if (BTLV_CORE_PollPartyMenu((u8 *)(client->view)) != 0) {
            BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectMove));
        }
        break;
    case 2:
        if (BTLV_CORE_PollPartyMenu((u8 *)(client->view)) != 0) {
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
        BTLV_CORE_StartPartyMenu(client->view, client->slotChoices, client->slotIndex, canCancel, client->choiceFlags);
        ++*st;
        break;
    case 1:
        canCancel = 0;
        if (BTL_CLIENT_PollTimeLimitAndSetSub(client, 0)) {
            BTLV_CORE_LockPartyChoice((unsigned int *)(client->view));
            *st = 2;
            return canCancel;
        }
        if (BTLV_CORE_PollPartyMenu((u8 *)(client->view))) {
            if (BTL_PICK_GetLocked(client->choiceFlags) == 0) {
                chosenMember = BTL_PICK_GetLast(client->choiceFlags);
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
        if (BTLV_CORE_PollPartyMenu((u8 *)(client->view))) BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepAutoSelectActions));
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
        BTLV_CORE_StartBagMenu(client->view, client->isComm, client->pointCounter, itemId, isLastSlot, foeSemiInvulnerable);
        ++*st;
        break;
    case 1:
        zero = 0;
        if (BTL_CLIENT_PollTimeLimitAndSetSub(client, 0)) {
            BTLV_CORE_SkipBagPartyPrompt(client->view);
            *st = 2;
            return zero;
        }
        if (BTLV_CORE_PollBagMenu(client->view)) {
            itemId = BTLV_CORE_GetSelectedItem(client->view);
            itemPocket = BTLV_CORE_GetInputTargetSlot(client->view);
            if (itemId && itemPocket != 6) {
                pointCost = BTLV_CORE_GetSelectedItemPocket(client->view);
                itemTarget = BTLV_CORE_GetInputResultFlag(client->view);
                if (client->pointCounter >= pointCost) client->pointCounter = client->pointCounter - pointCost;
                else {
                    client->pointCounter = zero;
                    pointCost = client->pointCounter;
                }
                BTL_CLIENT_SetSlotFlag(client, client->slotIndex, pointCost);
                BTL_ACTION_SetItem((void *)client->actionCursor, itemId, (u8)itemPocket, (u8)itemTarget);
                BTLV_CORE_SaveBagCursors(client->view);
                if (BTL_CALC_GetItemParam((void *)itemId, 0xf) == 4) *(u8 *)&client->flags |= 4;
                BTL_CLIENT_SetSlotLinkWord(client, client->slotIndex, itemId);
                BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
            } else BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectAction));
        }
        break;
    case 2:
        if (BTLV_CORE_PollBagMenu(client->view)) BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepAutoSelectActions));
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
                BTLV_SCU_InitMessage((struct BtlvMessage *)&client->messageA, 2, 0x365);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)&client->messageA, blockerPokeId);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)&client->messageA, blockerAbility);
            } else {
                BTLV_SCU_InitMessage((struct BtlvMessage *)&client->messageA, 1, 0x4a);
            }
            BTL_CLIENT_ShowMessage(client, (u8 *)&client->messageA);
            *st = 1;
            break;
        case 1:
            BTLV_SCU_InitMessage((struct BtlvMessage *)&client->messageA, 1, 0x4c);
            BTL_CLIENT_ShowMessage(client, (u8 *)&client->messageA);
            *st = 1;
            break;
        case 2:
            BTLV_SCU_InitMessage((struct BtlvMessage *)&client->messageA, 1, 0x4d);
            BTLV_SCU_SetMessageParam((u8 *)&client->messageA, 0xff);
            BTL_CLIENT_ShowMessage(client, (u8 *)&client->messageA);
            *st = 3;
            break;
        }
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(client->view)) {
            BTL_CLIENT_BuildActionPromptMessage(client, client->activeMon, (u8 *)&client->messageA);
            BTLV_CORE_BuildAndPrintMessageNow(client->view, &client->messageA);
            *st = 2;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMessage(client->view))
            BTL_CLIENT_SetSubFn(client, (void *)((u32)BTL_CLIENT_StepSelectAction));
        break;
    case 3:
        BTLV_CORE_WaitMessage(client->view);
        if (BTLV_CORE_ConsumeMessageFlag(client->view)) {
            BTLV_SCU_InitMessage((struct BtlvMessage *)&client->messageA, 3, 8);
            BTLV_SCU_InitMessage((struct BtlvMessage *)&client->messageB, 3, 9);
            BTLV_CORE_StartYesNoMenu(client->view, (u32)&client->messageA, (u32)&client->messageB, 1);
            *st = 4;
        }
        break;
    case 4:
        if (BTLV_CORE_WaitMessage(client->view)) {
            if (BTLV_CORE_PollYesNoMenu(client->view, &confirmResult)) {
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
        BTLV_CORE_CloseMenuToReselect((unsigned int)client->view);
        ++*st;
        break;
    case 1:
        if (BTLV_CORE_IsMenuClosed((unsigned int)client->view)) {
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
            BTLV_CORE_StartWaitMessage((char *)(client->view));
            *st = *st + 1;
        } else {
            *st = *st + 2;
        }
        break;
    case 1:
        if (BTLV_CORE_UpdateWaitMessage(client->view) != 0) {
            *st = *st + 1;
        }
        break;
    case 2:
        if (BTLV_EFFECT_IsBusy() == 0) {
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
                BTLV_SCU_InitMessage(outMessage, 1, 0x63);
                BTLV_SCU_AppendMessageArg(outMessage, BTL_POKEPARAM_GetItem(mon));
                BTLV_SCU_AppendMessageArg(outMessage, lockedMoveId);
            }
            return 1;
        }
    }
    if (BTL_POKEPARAM_HasSick(mon, 0x17)) {
        forcedMoveId = BTLV_CORE_GetSlotValue(BTL_POKEPARAM_GetSickContRaw(mon, 0x17));
        if (move != forcedMoveId) {
            if (outMessage) {
                BTLV_SCU_InitMessage(outMessage, 1, 0x64);
                BTLV_SCU_AppendMessageArg(outMessage, BTL_POKEPARAM_GetPokeId(mon));
                BTLV_SCU_AppendMessageArg(outMessage, forcedMoveId);
            }
            return 1;
        }
    }
    if (BTL_POKEPARAM_HasSick(mon, 0xb) && WAZA_TOOL_IsDamaging((void *)move) == 0) {
        if (outMessage) {
            BTLV_SCU_InitMessage(outMessage, 2, 0x23b);
            BTLV_SCU_AppendMessageArg(outMessage, BTL_POKEPARAM_GetPokeId(mon));
            BTLV_SCU_AppendMessageArg(outMessage, move);
        }
        return 1;
    }
    if (BTL_POKEPARAM_HasSick(mon, 0xc) && move == BTL_POKEPARAM_GetLastSelectedMoveId(mon)) {
        if (outMessage) {
            BTLV_SCU_InitMessage(outMessage, 2, 0x244);
            BTLV_SCU_AppendMessageArg(outMessage, BTL_POKEPARAM_GetPokeId(mon));
            BTLV_SCU_AppendMessageArg(outMessage, move);
        }
        return 1;
    }
    if (BTL_POKEPARAM_HasSick(mon, 0xd) && move == BTL_POKEPARAM_GetSickParam(mon, 0xd) && move != 0xa5) {
        if (outMessage) {
            BTLV_SCU_InitMessage(outMessage, 2, 0x253);
            BTLV_SCU_AppendMessageArg(outMessage, BTL_POKEPARAM_GetPokeId(mon));
            BTLV_SCU_AppendMessageArg(outMessage, move);
        }
        return 1;
    }
    if (BTL_POKEPARAM_HasSick(mon, 0xf) && WAZA_TOOL_GetFlag((void *)move, 0xc)) {
        if (outMessage) {
            BTLV_SCU_InitMessage(outMessage, 2, 0x37a);
            BTLV_SCU_AppendMessageArg(outMessage, BTL_POKEPARAM_GetPokeId(mon));
            BTLV_SCU_AppendMessageArg(outMessage, move);
        }
        return 1;
    }
    if (BTL_FIELD_IsSlotInUse((char *)(client->battleField), 3) && BTL_FIELD_IsMoveSealedBySlot((int)client->battleField, (int)client->side, mon, move)) {
        if (outMessage) {
            BTLV_SCU_InitMessage(outMessage, 2, 0x24d);
            BTLV_SCU_AppendMessageArg(outMessage, BTL_POKEPARAM_GetPokeId(mon));
            BTLV_SCU_AppendMessageArg(outMessage, move);
        }
        return 1;
    }
    if (BTL_FIELD_IsSlotInUse((char *)(client->battleField), 2) && WAZA_TOOL_GetFlag((void *)move, 9)) {
        if (outMessage) {
            BTLV_SCU_InitMessage(outMessage, 2, 0x43e);
            BTLV_SCU_AppendMessageArg(outMessage, BTL_POKEPARAM_GetPokeId(mon));
            BTLV_SCU_AppendMessageArg(outMessage, move);
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
    if (BTL_FIELD_IsSlotInUse(client->battleField, 7)) return 0;
    if (BTL_POKEPARAM_HasSick(mon, 19)) return 0;
    if (BTL_POKEPARAM_GetValue(mon, 17) != 103) return 1;
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
            if (BTL_POKEPARAM_GetValue(mon, 0x11) == 0x32)
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
    struct BtlPokeParam *foe;
    u16 foeAbility;
    foeCount = BTL_MAIN_CollectLivingPokeIds(client->main, (int)client->side, (u16)(BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, BTL_POKEPARAM_GetPokeId(mon)) | 0x100), foeSlots);
    for (i = 0; i < foeCount; i++) {
        foe = BTL_SIDE_GetPokeByIdThunk(client->side, foeSlots[i]);
        foeAbility = BTL_POKEPARAM_GetValue(foe, 0x11);
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
    if (BTL_POKEPARAM_GetValue(mon, 17) != 23) return 1;
    return 0;
}

int BTL_CLIENT_CanArenaTrapTrap(BtlClient *client, void *mon)
{
    u32 itemEffective;

    itemEffective = BTL_CLIENT_IsHeldItemEffective(client, mon);
    if (BTL_FIELD_IsSlotInUse((char *)(client->battleField), 2) != 0)
        return 1;
    if (BTL_POKEPARAM_HasSick(mon, 0x1f) != 0)
        return 1;
    if (BTL_POKEPARAM_HasSick(mon, 0x15) != 0)
        return 1;
    if (itemEffective != 0 && BTL_POKEPARAM_GetItem(mon) == 0x116)
        return 1;
    if (BTL_POKEPARAM_GetValue(mon, 0x11) == 0x1a)
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
    struct BtlPokeParam *foe;
    u32 candidateCount;
    u32 i;
    u8 shouldSwitch;
    chosenMember = 6;
    if (BTL_CLIENT_GetEscapeBlocker(client, mon, &trapperPokeId, &trapperAbility) != 4) return 0;
    if (BTL_SLOT_CountLiving(client->sideData) <= client->slotCount) return 0;
    foe = BTL_CLIENT_PickRandomFoe(client, BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, BTL_POKEPARAM_GetPokeId(mon)));
    if (!foe) return 0;
    if (BTL_POKEPARAM_IsIllusionActive(foe))
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

struct BtlPokeParam *BTL_CLIENT_PickRandomFoe(BtlClient *client, int positionId)
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
    if (BTL_POKEPARAM_GetValue(foe, 0x11) == 0x19) {
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

    if (BTL_POKEPARAM_GetValue(mon, 0x11) == 0x1e) {
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
    for (member = 1; member <= 7; member++) totalBoosts += BTL_POKEPARAM_GetValue(mon, member);
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
            if (BTL_POKEPARAM_IsFainted(member) == 0 && ability == BTL_POKEPARAM_GetValue(member, 0x11)) {
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
        moveOrItem = BTL_CLIENT_TakeTrainerItemToUse(client,(client->activeMon),client->sideData);
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
            TR_AI_Start((int)client->recorder,moveAvailability,target);
            *state = 2;
        } else {
            BTL_CLIENT_SetStruggleAction((struct Unk021D82D0 *)((u32)(client->actionCursor)),client,(client->activeMon));
            goto complete;
        }
        break;
    case 2:
        if (TR_AI_Think(client->recorder)) break;
        moveSlot = TR_AI_GetChosenMove(client->recorder);
        if (moveSlot != 4) {
            targetOrPosition = TR_AI_GetChosenTarget(client->recorder);
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
    BTL_PICK_InitSlotChoices(q, (unsigned int)client->sideData, b, a);
    BTL_PICK_MarkSlotsSelectable(q, client->slotCount);
    BTL_PICK_InitList(out, q);
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
        BTLV_SCU_InitMessage((struct BtlvMessage *)client->messageA.data, 3, 5);
        BTLV_SCU_InitMessage((struct BtlvMessage *)((u8 *)&client->messageB), 3, 1);
        BTLV_CORE_StartYesNoMenu(client->view, (u32)client->messageA.data, (u32)((u8 *)&client->messageB), 0);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_PollYesNoMenu(client->view, &answer)) {
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
    struct BtlPokeParam *targetMon;
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
                BTLV_CORE_StartPartyMenu(client->view, client->slotChoices, pairValues[0], 0, client->choiceFlags);
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
            BTLV_CORE_LockPartyChoice(client->view);
            *state = 2;
        } else if (BTLV_CORE_PollPartyMenu(client->view) != 0) {
            BTL_CLIENT_SetChangeActionsFromChoice(client, client->choiceFlags);
            *state = 3;
        }
        break;
    case 2:
        if (BTLV_CORE_PollPartyMenu(client->view) != 0) {
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
            BTLV_CORE_StartWaitMessage(client->view);
            *state = 5;
        } else {
            *state = 6;
        }
        break;
    case 5:
        if (BTLV_CORE_UpdateWaitMessage(client->view) != 0) {
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
            BTLV_SCU_InitMessage((struct BtlvMessage *)&client->messageA, 1, 0x14);
            BTLV_SCU_AppendMessageArg((struct BtlvMessage *)&client->messageA, 1);
            BTLV_SCU_AppendMessageArg((struct BtlvMessage *)&client->messageA, received[0]);
            BTLV_SCU_SetMessageParam((u8 *)&client->messageA, 0xFF);
            BTLV_CORE_BuildAndPrintMessage(client->view, &client->messageA);
            *state = 1;
        } else *state = 4;
        break;
    case 1:
        BTLV_CORE_WaitMessage(client->view);
        if (BTLV_CORE_ConsumeMessageFlag(client->view) != 0) {
            BTLV_SCU_InitMessage((struct BtlvMessage *)&client->messageA, 3, 6);
            BTLV_SCU_InitMessage((struct BtlvMessage *)&client->messageB, 3, 7);
            BTLV_CORE_StartYesNoMenu(client->view, (u32)&client->messageA, (u32)&client->messageB, 1);
            *state = 2;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMessage(client->view) != 0) {
            if (BTLV_CORE_PollYesNoMenu(client->view, &answer) != 0) {
                if (answer == 0) {
                    BTL_CLIENT_BuildSlotChoices(client, 0, 1, client->slotChoices, client->choiceFlags);
                    BTLV_CORE_StartPartyMenu(client->view, client->slotChoices, 0, 0, client->choiceFlags);
                    *state = 3;
                } else *state = 4;
            }
        }
        break;
    case 3:
        if (BTLV_CORE_PollPartyMenu(client->view) != 0) {
            if (BTL_PICK_GetLocked(client->choiceFlags) == 0) {
                chosenIndex = BTL_PICK_GetLast(client->choiceFlags);
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
        BTLV_SCU_InitMessage((struct BtlvMessage *)&client->messageA, 1, messageId);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)&client->messageA, trainerIndex);
        if (isMultiMode != 0)
            BTLV_SCU_AppendMessageArg((struct BtlvMessage *)&client->messageA, BTL_MAIN_GetOwnOpponentClient(client->main, 1));
        BTLV_CORE_BuildAndPrintMessage(client->view, &client->messageA);
        if (outcome == 1) {
            GFL_USE_CancelChangeAndPlayBgm(BTL_MAIN_GetWinBgm(client->main), 0xFFFF);
            (*state)++;
        } else {
            GFL_USE_FadeOutBgm(0x1E);
            *state += 2;
        }
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(client->view) != 0)
            return 1;
        break;
    case 2:
        if (BTLV_CORE_WaitMessage(client->view) != 0)
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
            BTLV_EFFECT_StopLowHpBgm(BTL_MAIN_GetWinBgm(client->main));
            firstTrainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 0);
            secondTrainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 1);
            if (firstTrainerIndex == secondTrainerIndex) {
                BTLV_SCU_InitMessage((struct BtlvMessage *)client->messageA.data, 1, 44);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, firstTrainerIndex);
            } else {
                BTLV_SCU_InitMessage((struct BtlvMessage *)client->messageA.data, 1, 45);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, firstTrainerIndex);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, secondTrainerIndex);
            }
            BTLV_CORE_BuildAndPrintMessage(client->view, client->messageA.data);
            *state = 1;
        } else if (BTL_MAIN_CheckSetupStatusFlag(client->main, 0x100) == 0) {
            firstTrainerIndex = BTL_MAIN_GetOwnClientId(client->main);
            BTLV_SCU_InitMessage((struct BtlvMessage *)client->messageA.data, 1, 54);
            BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, firstTrainerIndex);
            BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, firstTrainerIndex);
            BTLV_CORE_BuildAndPrintMessage(client->view, client->messageA.data);
            *state = 9;
        } else {
            return 1;
        }
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(client->view)) {
            firstTrainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 0);
            BTLV_EFFECT_AddPokeSprite(BTL_MAIN_GetTrainerType(client->main, firstTrainerIndex), 9, 0, 0, 0);
            BTLV_EFFECT_StartEffect(0x270);
            *state = 2;
        }
        break;
    case 2:
        if (BTLV_EFFECT_IsBusy() == 0) {
            firstTrainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 0);
            BTLV_CORE_PrintTrainerMessage(client->view, BTL_MAIN_GetTrainerId(client->main, firstTrainerIndex), 1);
            *state = 3;
        }
        break;
    case 3:
        if (BTLV_CORE_WaitMessage(client->view)) {
            firstTrainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 0);
            if (firstTrainerIndex != BTL_MAIN_GetOwnOpponentClient(client->main, 1)) {
                BTLV_EFFECT_StartEffect(0x271);
                *state = 4;
            } else {
                *state = 7;
            }
        }
        break;
    case 4:
        if (BTLV_EFFECT_IsBusy() == 0) {
            firstTrainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 1);
            BTLV_EFFECT_AddPokeSprite(BTL_MAIN_GetTrainerType(client->main, firstTrainerIndex), 9, 0, 0, 0);
            BTLV_EFFECT_StartEffect(0x270);
            *state = 5;
        }
        break;
    case 5:
        if (BTLV_EFFECT_IsBusy() == 0) {
            firstTrainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 1);
            BTLV_CORE_PrintTrainerMessage(client->view, BTL_MAIN_GetTrainerId(client->main, firstTrainerIndex), 1);
            *state = 6;
        }
        break;
    case 6:
        if (BTLV_CORE_WaitMessage(client->view))
            *state = 7;
        break;
    case 7:
        firstTrainerIndex = BTL_MAIN_GetPrizeMoney(client->main);
        if (firstTrainerIndex) {
            secondTrainerIndex = BTL_MAIN_GetOwnClientId(client->main);
            BTLV_SCU_InitMessage((struct BtlvMessage *)client->messageA.data, 1, 58);
            BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, secondTrainerIndex);
            BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, firstTrainerIndex);
            BTLV_CORE_BuildAndPrintMessage(client->view, client->messageA.data);
        }
        if (BTL_MAIN_GetBonusMoney(client->main) == 0)
            *state = 11;
        else
            *state = 8;
        break;
    case 8:
        if (BTLV_CORE_WaitMessage(client->view)) {
            firstTrainerIndex = BTL_MAIN_GetBonusMoney(client->main);
            if (firstTrainerIndex) {
                secondTrainerIndex = BTL_MAIN_GetOwnClientId(client->main);
                BTLV_SCU_InitMessage((struct BtlvMessage *)client->messageA.data, 1, 59);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, secondTrainerIndex);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, firstTrainerIndex);
                BTLV_CORE_BuildAndPrintMessage(client->view, client->messageA.data);
            }
            *state = 11;
        }
        break;
    case 9:
        if (BTLV_CORE_WaitMessage(client->view)) {
            firstTrainerIndex = BTL_MAIN_CalcPenaltyMoney(client->main);
            if (firstTrainerIndex) {
                BTLV_SCU_InitMessage((struct BtlvMessage *)client->messageA.data, 1, 56);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, client->clientId);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, firstTrainerIndex);
                BTLV_CORE_BuildAndPrintMessage(client->view, client->messageA.data);
            }
            *state = 10;
        }
        break;
    case 10:
        if (BTLV_CORE_WaitMessage(client->view)) {
            BTLV_SCU_InitMessage((struct BtlvMessage *)client->messageA.data, 1, 57);
            BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, client->clientId);
            BTLV_CORE_BuildAndPrintMessage(client->view, client->messageA.data);
            *state = 11;
        }
        break;
    case 11:
        if (BTLV_CORE_WaitMessage(client->view))
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
        if (outcome == 1) BTLV_EFFECT_StopLowHpBgm(BTL_MAIN_GetWinBgm(client->main));
        if (outcome <= 1) {
            trainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 0);
            BTLV_EFFECT_AddPokeSprite(BTL_MAIN_GetTrainerType(client->main, trainerIndex), 9, 0, 0, 0);
            BTLV_EFFECT_StartEffect(0x270);
            BTL_CLIENT_ShowEndSpeech(client, outcome, 0);
            *state = 1;
        } else return 1;
        break;
    case 1:
        if (BTLV_EFFECT_IsBusy() == 0) {
            BTLV_CORE_PrintMessageBuffer(client->view);
            *state = 2;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMessage(client->view) != 0) {
            trainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 0);
            if (trainerIndex == BTL_MAIN_GetOwnOpponentClient(client->main, 1)) return 1;
            BTLV_EFFECT_StartEffect(0x271);
            *state = 3;
        }
        break;
    case 3:
        if (BTLV_EFFECT_IsBusy() == 0) {
            outcome = BTL_CLIENT_GetOutcomeForClient(client);
            trainerIndex = BTL_MAIN_GetOwnOpponentClient(client->main, 1);
            BTLV_EFFECT_AddPokeSprite(BTL_MAIN_GetTrainerType(client->main, trainerIndex), 9, 0, 0, 0);
            BTLV_EFFECT_StartEffect(0x270);
            BTL_CLIENT_ShowEndSpeech(client, outcome, 1);
            *state = 4;
        }
        break;
    case 4:
        if (BTLV_EFFECT_IsBusy() == 0) {
            BTLV_CORE_PrintMessageBuffer(client->view);
            *state = 5;
        }
        break;
    case 5:
        if (BTLV_CORE_WaitMessage(client->view) != 0) return 1;
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
        BTLV_CORE_CopyMessageBuffer(client->view, speechText);
        STRBUF_Delete(speechText);
        return;
    }
    trainerId = BTL_MAIN_GetTrainerId(client->main, trainerIndex);
    if (trainerId != 0) {
        BTLV_SCU_InitMessage((struct BtlvMessage *)client->messageA.data, 7, (int)0);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, (int)trainerId);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, (int)outcome);
        BTLV_CORE_BuildMessageToBuffer(client->view, client->messageA.data);
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
                BTLV_SCU_InitMessage((struct BtlvMessage *)client->messageA.data, 1, 0x3b);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, b);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, a);
                BTLV_CORE_BuildAndPrintMessage(client->view, client->messageA.data);
            }
        }
        (*state)++;
    case 1:
        if (BTLV_CORE_WaitMessage(client->view) != 0)
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
        BTLV_SCU_InitMessage((struct BtlvMessage *)client->messageA.data, 1, 0x36);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, client->clientId);
        BTLV_CORE_BuildAndPrintMessage(client->view, client->messageA.data);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(client->view) != 0) {
            a = BTL_MAIN_CalcPenaltyMoney(client->main);
            if (a != 0) {
                BTLV_SCU_InitMessage((struct BtlvMessage *)client->messageA.data, 1, 0x37);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, client->clientId);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, a);
                BTLV_CORE_BuildAndPrintMessage(client->view, client->messageA.data);
            }
            (*state)++;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMessage(client->view) != 0) {
            BTLV_SCU_InitMessage((struct BtlvMessage *)client->messageA.data, 1, 0x39);
            BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, client->clientId);
            BTLV_CORE_BuildAndPrintMessage(client->view, client->messageA.data);
            (*state)++;
        }
        break;
    case 3:
        if (BTLV_CORE_WaitMessage(client->view) != 0)
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
        BTLV_SCU_InitMessage((struct BtlvMessage *)client->messageA.data, 1, 0xb7);
        BTLV_CORE_BuildAndPrintMessage(client->view, client->messageA.data);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(client->view) != 0)
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
    BtlServerCmdBuffer *commandBuffer;
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
        MIi_CpuCopy32(packet, commandBuffer->buf, packetLen);
        commandBuffer->wpos = packetLen;
        commandBuffer->rpos = 0;
        if (client->viewLocked != 0) {
            client->viewLocked = 0;
            BTLV_CORE_EndWaitMessage(client->view);
        }
        (*state)++;
    case 1:
        commandBuffer = client->workBuffer;
        if (commandBuffer->rpos == commandBuffer->wpos) {
            *state = 4;
            return 1;
        }
        if (BTL_CLIENT_IsCounterFadeDone(&client->counter) != 0) return 1;
        (*state)++;
    case 2:
        commandCode = BTL_SERVER_CMD_ReadNext(client->workBuffer, (s32 *)client->seqArgs);
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
        if ((client->seqFn)(client, &client->seqState, (s32 *)client->seqArgs) != 0) {
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
        BTLV_SCU_InitMessage((struct BtlvMessage *)client->messageA.data, 1, BTL_CLIENT_PickRecallMessageId(client, args[0], &addTrainerName));
        if (addTrainerName != 0)
            BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, args[0]);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)client->messageA.data, args[1]);
        BTLV_CORE_BuildAndPrintMessage(client->view, client->messageA.data);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(client->view) != 0)
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
        BTLV_CORE_StartMonEffectTask(client->view, BTL_MAIN_GetViewPosOfSlot(client->main, (u8)args[0]), (u16)args[1]);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMonEffectTask(client->view) != 0)
            return 1;
        break;
    }
    return 0;
}

static inline void showMessageWithIds(BtlClient *client, int code, u32 value, u32 id)
{
    BTLV_SCU_InitMessage((struct BtlvMessage *)&client->messageA, 1, code);
    BTLV_SCU_AppendMessageArg((struct BtlvMessage *)&client->messageA, value);
    BTLV_SCU_AppendMessageArg((struct BtlvMessage *)&client->messageA, id);
    BTLV_CORE_BuildAndPrintMessage(client->view, &client->messageA);
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
                    BTLV_SCU_InitMessage((struct BtlvMessage *)&client->messageA, 1, BTL_CLIENT_PickSendOutMessageId(client));
                    BTLV_SCU_AppendMessageArg((struct BtlvMessage *)&client->messageA, pokeId);
                    BTLV_CORE_BuildAndPrintMessage(client->view, &client->messageA);
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
        if (BTLV_CORE_WaitMessage(client->view) != 0) {
            BTLV_CORE_StartMonSwap(client->view, BTL_MAIN_GetClientTrainerIndex(client->main, side, position), side, position);
            (*state)++;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMonSwap(client->view) != 0) {
            BTL_CLIENT_StoreMonParam(client);
            return 1;
        }
        break;
    }
    return 0;
}

int BTL_CLIENT_PickSendOutMessageId(BtlClient *client)
{
    struct BtlPokeParam *leadMon;
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
        BTLV_CORE_PrintSideMessage(client->view, args[0], (int *)(args + 1));
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(client->view)) {
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
        BTLV_CORE_PrintSideMessage(client->view, args[0], (int *)(args + 2));
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_CORE_ConsumeMessageFlag(client->view)) {
            GFL_USE_PlaySeDefaultVolume(args[1]);
        }
        if (BTLV_CORE_WaitMessage(client->view)) {
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
        BTLV_CORE_PrintTaggedMessage(client->view, args[0], (int *)(args + 1));
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(client->view)) {
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
        BTLV_CORE_PrintTaggedMessage(client->view, args[0], (int *)(args + 2));
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_CORE_ConsumeMessageFlag(client->view)) {
            GFL_USE_PlaySeDefaultVolume(args[1]);
        }
        if (BTLV_CORE_WaitMessage(client->view)) {
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
        BTLV_CORE_PrintItemUseMessage(client->view, args[0], args[1]);
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(client->view)) {
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
    struct BtlPokeParam *attacker;

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
            BTLV_CORE_StartSceneEffect(client->view, attackerId, defenderId, moveId, targetKind, hitFlag, 0);
            *state = *state + 1;
        } else {
            return 1;
        }
        break;
    case 1:
        if (BTLV_CORE_WaitSceneEffect(client->view)) {
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
        BTLV_CORE_SetMonShown(client->view, t, args[1] != 0);
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_EFFECT_IsBusy() == 0) {
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
        BTLV_CORE_StartDamageEffect(client->view, (u16)args[2], t, (u8)args[1]);
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_CORE_WaitDamageEffect(client->view)) {
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
        BTLV_CORE_StartMultiDamageEffect(client->view, monCount, param, monIds, soundId);
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_CORE_ProcMultiDamageEffect(client->view)) {
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
        BTLV_CORE_StartMonSpriteUpdate(client->view, BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)args[0]));
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_CORE_WaitMonSpriteUpdate(client->view)) {
            BTLV_CORE_PrintSideMessage(client->view, 0x61, (int *)args);
            *state = *state + 1;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMessage(client->view)) {
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
        BTLV_EFFECT_GaugeSetStatusIcon(args[1], BTL_MAIN_GetViewPosOfSlot(client->main, t));
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
            BTLV_CORE_StartSceneEffect(client->view, t, t, 1, WAZA_TOOL_GetParam(1, 0x1B), 0, 0);
        }
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_CORE_WaitSceneEffect(client->view)) {
            t = BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)args[0]);
            if (BTL_CLIENT_IsMainStepActive(client) == 0) {
                GFL_USE_PlaySeDefaultVolume(0x564);
            }
            BTLV_CORE_StartDamageEffect(client->view, 1, t, 1);
            *state = *state + 1;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitDamageEffect(client->view)) {
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
        BTLV_CORE_StartMonReset(client->view, BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)(*args)));
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMonReset(client->view)) {
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
        BTLV_CORE_StartMonRefresh(client->view, BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)(*args)));
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMonRefresh(client->view))
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
        BTLV_CORE_StartViewEffect262(client->view, t);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitViewEffectDone(client->view, t))
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
        BTLV_CORE_StartViewEffect261(client->view, t);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitViewEffectDone(client->view, t))
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
            BTLV_EFFECT_StartEffect(gWeatherEffects[weatherId].b);
        (*state)++;
        break;
    case 1:
        if (!BTLV_EFFECT_IsBusy()) {
            BTLV_CORE_PrintSideMessage(client->view, gWeatherEffects[weatherId].a, 0);
            (*state)++;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMessage(client->view))
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
        BTLV_CORE_PrintSideMessage(client->view, messageId, 0);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(client->view)) {
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
        BTLV_CORE_StartMonSpriteUpdate(client->view, BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)(*args)));
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMonSpriteUpdate(client->view))
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
        BTLV_CORE_StartSlotEffect25F(client->view, t);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitSlotEffect25F(client->view, t))
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
        BTLV_CORE_StartMonSpriteUpdate(client->view, BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, id));
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMonSpriteUpdate(client->view))
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
        BTLV_CORE_StartRotation(client->view, side, fromTrainer, toTrainer, fromPosition, toPosition);
        (*state)++;
        break;
    }
    case 1:
        if (BTLV_CORE_WaitRotation(client->view))
            return 1;
        break;
    }
    return 0;
}

int BTL_CLIENT_StepRotatePositionsTwice(BtlClient *client, int *state, u32 *args)
{
    switch (*state) {
    case 0:
        BTLV_EFFECT_StartEffect(0x281);
        (*state)++;
        break;
    case 1:
        if (!BTLV_EFFECT_IsBusy()) {
            u8 side = args[0], fromIndex = args[1];
            u32 trainerIndexA, trainerIndexB, trainerA, trainerB;
            trainerIndexA = BTL_MAIN_GetClientTrainerIndex(client->main, side, fromIndex);
            trainerIndexB = BTL_MAIN_GetClientTrainerIndex(client->main, side, 1);
            trainerA = BTL_MAIN_GetViewPosOfSlot(client->main, trainerIndexA);
            trainerB = BTL_MAIN_GetViewPosOfSlot(client->main, trainerIndexB);
            BTL_SLOT_Swap((u32 *)BTL_SIDE_GetSlotOfClient(client->side, side), fromIndex, 1);
            BTLV_CORE_StartRotation(client->view, side, trainerA, trainerB, fromIndex, 1);
            (*state)++;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitRotation(client->view)) {
            u8 side = args[2], fromIndex = args[3];
            u32 trainerIndexA, trainerIndexB, trainerA, trainerB;
            trainerIndexA = BTL_MAIN_GetClientTrainerIndex(client->main, side, fromIndex);
            trainerIndexB = BTL_MAIN_GetClientTrainerIndex(client->main, side, 1);
            trainerA = BTL_MAIN_GetViewPosOfSlot(client->main, trainerIndexA);
            trainerB = BTL_MAIN_GetViewPosOfSlot(client->main, trainerIndexB);
            BTL_SLOT_Swap((u32 *)BTL_SIDE_GetSlotOfClient(client->side, side), fromIndex, 1);
            BTLV_CORE_StartRotation(client->view, side, trainerA, trainerB, fromIndex, 1);
            (*state)++;
        }
        break;
    case 3:
        if (BTLV_CORE_WaitRotation(client->view)) return 1;
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
        BTLV_EFFECT_StartPokeEffectId26E((u8)BTL_MAIN_GetViewPosOfSlot(client->main, (u8)args[0]));
        (*state)++;
        break;
    case 1:
        if (BTLV_EFFECT_IsBusy() == 0) return 1;
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
            BTLV_EFFECT_SetFlag26(1);
        BTLV_EFFECT_StartPokeEffectId26F(t);
        (*state)++;
        break;
    }
    case 1:
        if (!BTLV_EFFECT_IsBusy()) {
            if (BTL_CLIENT_IsMainStepActive(client))
                BTLV_EFFECT_SetFlag26(0);
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
        struct BtlPokeParam *sourceMon = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
        struct BtlPokeParam *targetMon = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[1]);
        int sourceSlot = (int)BTL_MAIN_GetViewPosOfPoke(client->main, client->side, (u8)args[0]);
        int targetSlot = (int)BTL_MAIN_GetViewPosOfPoke(client->main, client->side, (u8)args[1]);
        BTL_POKEPARAM_Transform(sourceMon, targetMon);
        BTLV_CORE_StartMonSpriteChangeAt(client->view, sourceSlot, targetSlot);
        (*state)++;
        break;
    }
    case 1:
        if (BTLV_CORE_WaitMonSpriteChangeAt(client->view))
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
            BTLV_CORE_StartHitAnim(client->view, (u16)args[2], monSlot, BTL_CALC_SummarizeTypeAffinity(args[1]));
            (*state)++;
            break;
        }
        return 1;
    case 1:
        if (BTLV_CORE_WaitHitAnim(client->view) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

int BTL_CLIENT_StepChangeBgm(int unusedClient, int unusedState, int *bgmId)
{
    BTLV_EFFECT_StopLowHpBgm(*bgmId);
    return 1;
}

int BTL_CLIENT_StepPlayViewSequence(BtlClient *client, int *state)
{
    switch (*state) {
    case 0:
        BTLV_CORE_StartMonSpriteUnload(client->view);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMonSpriteUnload(client->view) != 0) return 1;
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
            newValue = args[statIndex + 1] + POKE_TOOL_GetPartyValue(mon, paramId, 0);
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
    if (monSlot != 0xff && BTLV_EFFECT_GaugeIsSlotOccupied(monSlot)) gaugeActive = 1;
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
                    BTLV_EFFECT_GaugeStartExpGain(monSlot, gExpGainWork.s.remaining);
                    *state = 2;
                } else *state = 13;
                expRemaining = 0;
            }
            gExpGainWork.s.remaining = expRemaining;
        } else *state = 13;
        break;
    case 2:
        if (!BTLV_EFFECT_GaugeIsAnimating()) *state = 13;
        break;
    case 3:
        BTL_EVENT_ReleaseClientHandle(pokeParam);
        BTL_POKEPARAM_ReloadFromParam(pokeParam);
        if (gaugeActive) {
            BTLV_EFFECT_GaugeRefreshForLevelUp(monSlot, pokeParam);
            *state = 4;
        } else *state = 6;
        break;
    case 4:
        if (!BTLV_EFFECT_GaugeIsAnimating() && !GFL_USE_IsAnySeBusy()) {
            BTLV_CORE_StartViewEffect(client->view, monSlot, 0x25d);
            *state = 5;
        }
        break;
    case 5:
        if (BTLV_CORE_WaitViewEffect(client->view)) *state = 6;
        break;
    case 6:
        BTLV_SCU_InitMessage((struct BtlvMessage *)&client->messageA, 1, 0x3c);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)&client->messageA, (int)pokeId);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)&client->messageA, (int)gExpGainWork.s.result[0]);
        BTLV_CORE_BuildAndPrintMessage(client->view, &client->messageA);
        *state = 7;
        break;
    case 7:
        if (BTLV_CORE_ConsumeMessageFlag(client->view)) {
            GFL_USE_SetBgmPlayerParam((void *)1);
            GFL_USE_PushBgm();
            GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        }
        if (BTLV_CORE_WaitMessage(client->view) && !GFL_USE_IsBgmPlaying()) {
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
            BTLV_CORE_StartBallWindowOpen(client->view, (int)pokeParam, gExpGainWork.s.result);
            *state = 9;
        }
        break;
    case 9:
        if (BTLV_CORE_UpdateBallWindowOpen(client->view) && ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg())) {
            BTLV_CORE_StartBallWindowRefresh(client->view);
            *state = 10;
        }
        break;
    case 10:
        if (BTLV_CORE_UpdateBallWindowRefresh(client->view) && ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg())) {
            BTLV_CORE_StartBallWindowClose(client->view);
            *state = 11;
        }
        break;
    case 11:
        if (BTLV_CORE_UpdateBallWindowClose(client->view)) {
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
        sLevelUpMoveScan.iter = 0;
        sLevelUpMoveScan.move = 0;
        *state = 1;
    case 1:
        sLevelUpMoveScan.move = POKE_TOOL_GetLevelUpMove(BTL_POKEPARAM_GetMon(mon), &sLevelUpMoveScan.iter, client->heapId);
        if (sLevelUpMoveScan.move == 0)
            return 1;
        if (sLevelUpMoveScan.move == 0xFFFE)
            break;
        if (sLevelUpMoveScan.move & 0x8000) {
            sLevelUpMoveScan.move &= 0x7FFF;
            *state = 5;
        } else {
            *state = 2;
        }
        break;
    case 2: {
        void *p = BTL_SIDE_GetPokeByIdThunk(client->side, pokeId);
        BTL_POKEPARAM_GetMon(p);
        BTL_POKEPARAM_ReloadFromParam(p);
        BTLV_SCU_InitMessage((struct BtlvMessage *)(&client->messageA), 5, 3);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)(&client->messageA), pokeId);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)(&client->messageA), sLevelUpMoveScan.move);
        BTLV_CORE_BuildAndPrintMessage(client->view, (&client->messageA));
        *state = 3;
    }
    case 3:
        if (BTLV_CORE_ConsumeMessageFlag(client->view)) {
            GFL_USE_SetBgmPlayerParam((void *)1);
            GFL_USE_PushBgm();
            GFL_USE_CancelChangeAndPlayBgm(0x515, 0xFFFF);
        }
        if (BTLV_CORE_WaitMessage(client->view))
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
        BTLV_SCU_InitMessage((struct BtlvMessage *)(&client->messageA), 5, 4);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)(&client->messageA), pokeId);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)(&client->messageA), sLevelUpMoveScan.move);
        BTLV_SCU_SetMessageParam((u8 *)(&client->messageA), 255);
        BTLV_CORE_BuildAndPrintMessage(client->view, (&client->messageA));
        *state = 6;
    case 6:
        if (BTLV_CORE_ConsumeMessageFlag(client->view)) {
            BtlClientMessage yes, no;
            BTLV_SCU_InitMessage((struct BtlvMessage *)(&yes), 6, 2);
            BTLV_SCU_InitMessage((struct BtlvMessage *)(&no), 6, 3);
            BTLV_CORE_StartYesNoMenu(client->view, (u32)(&yes), (u32)(&no), 1);
        }
        if (BTLV_CORE_WaitMessage(client->view))
            *state = 7;
        break;
    case 7: {
        int sel;
        if (BTLV_CORE_PollYesNoMenu(client->view, &sel)) {
            if (sel == 0) {
                BTLV_CORE_StartMoveForgetScreen(client->view, BTL_SLOT_FindPokeId((u8 *)BTL_SIDE_GetSlotOfClientThunk(client->side, client->clientId), pokeId), sLevelUpMoveScan.move);
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
        if (BTLV_CORE_ProcMoveForgetScreen(client->view, &slot) == 0)
            break;
        if (slot == 4) {
            *state = 5;
            break;
        }
        pp = BTL_POKEPARAM_GetMon(BTL_SIDE_GetPokeByIdThunk(client->side, pokeId));
        old = POKE_TOOL_GetPartyValue(pp, slot + 54, 0);
        POKE_TOOL_SetMoveSlot(pp, sLevelUpMoveScan.move, slot);
        BTLV_SCU_InitMessage((struct BtlvMessage *)(&client->messageA), 5, 5);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)(&client->messageA), pokeId);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)(&client->messageA), old);
        BTLV_CORE_BuildAndPrintMessageFlag(client->view, (&client->messageA), (int)((void (*)(void))BTL_CLIENT_ForgetMoveSoundCallback));
        *state = 9;
        break;
    }
    case 9:
        if (BTLV_CORE_WaitMessage(client->view))
            *state = 2;
        break;
    case 10:
        BTLV_SCU_InitMessage((struct BtlvMessage *)(&client->messageA), 5, 7);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)(&client->messageA), pokeId);
        BTLV_SCU_AppendMessageArg((struct BtlvMessage *)(&client->messageA), sLevelUpMoveScan.move);
        BTLV_SCU_SetMessageParam((u8 *)(&client->messageA), 255);
        BTLV_CORE_BuildAndPrintMessage(client->view, (&client->messageA));
        *state = 11;
        break;
    case 11:
        if (BTLV_CORE_ConsumeMessageFlag(client->view)) {
            BtlClientMessage yes, no;
            BTLV_SCU_InitMessage((struct BtlvMessage *)(&yes), 6, 4);
            BTLV_SCU_AppendMessageArg((struct BtlvMessage *)(&yes), sLevelUpMoveScan.move);
            BTLV_SCU_InitMessage((struct BtlvMessage *)(&no), 6, 5);
            BTLV_SCU_AppendMessageArg((struct BtlvMessage *)(&no), sLevelUpMoveScan.move);
            BTLV_CORE_StartYesNoMenu(client->view, (u32)(&yes), (u32)(&no), 1);
        }
        if (BTLV_CORE_WaitMessage(client->view))
            *state = 12;
        break;
    case 12: {
        int sel;
        if (BTLV_CORE_PollYesNoMenu(client->view, &sel)) {
            if (sel == 0) {
                BTLV_SCU_InitMessage((struct BtlvMessage *)(&client->messageA), 5, 8);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)(&client->messageA), pokeId);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)(&client->messageA), sLevelUpMoveScan.move);
                BTLV_CORE_BuildAndPrintMessage(client->view, (&client->messageA));
                *state = 13;
            } else {
                *state = 5;
            }
        }
        break;
    }
    case 13:
        if (BTLV_CORE_WaitMessage(client->view))
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
        BTLV_EFFECT_StartEffectWithColor(BTL_MAIN_GetViewPosOfSlot(client->main, (u8)args[0]), (u16)args[5], (u8)args[1], args[2], args[4]);
        (*state)++;
        break;
    case 1:
        if (!BTLV_EFFECT_IsBusy()) {
            if (args[2]) {
                struct BtlPokeParam *pokeParam = BTL_SIDE_GetPokeAtPos((char *const *)client->side, (u8)args[0]);
                BTLV_SCU_InitMessage((struct BtlvMessage *)((u8 *)&client->messageA), 1, 0x41);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)((u8 *)&client->messageA), BTL_POKEPARAM_GetPokeId(pokeParam));
                BTLV_EFFECT_StopLowHpBgmAndSuppress(0x518);
            } else {
                int messageId;
                if (args[1] < 4) messageId = gCatchShakeMessages[args[1]];
                else messageId = 0x3d;
                BTLV_SCU_InitMessage((struct BtlvMessage *)((u8 *)&client->messageA), 1, messageId);
            }
            BTLV_CORE_BuildAndPrintMessage(client->view, ((u8 *)&client->messageA));
            (*state)++;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMessage(client->view)) {
            if (args[2]) {
                BTL_MAIN_NotifyCapture((u32)(client->main), (u32 *)BTL_SIDE_GetPokeAtPos((char *const *)client->side, (u8)args[0]));
                (*state)++;
            } else return 1;
        }
        break;
    case 3:
        if (!GFL_USE_IsBgmPlaying()) {
            BTLV_EFFECT_ResumeVm();
            GFL_USE_CancelChangeAndPlayBgm(0x47c, 0xffff);
            BTL_MAIN_SetKeepBgm(client->main);
            if (args[3]) {
                struct BtlPokeParam *pokeParam = BTL_SIDE_GetPokeAtPos((char *const *)client->side, (u8)args[0]);
                BTLV_SCU_InitMessage((struct BtlvMessage *)((u8 *)&client->messageA), 1, 0x42);
                BTLV_SCU_AppendMessageArg((struct BtlvMessage *)((u8 *)&client->messageA), BTL_POKEPARAM_GetPokeId(pokeParam));
                BTLV_CORE_BuildAndPrintMessage(client->view, ((u8 *)&client->messageA));
                (*state)++;
            } else return 1;
        }
        break;
    case 4:
        if (BTLV_CORE_WaitMessage(client->view)) (*state)++;
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
        BTLV_EFFECT_StartEffectWithValue(BTL_MAIN_GetViewPosOfSlot(client->main, (u8)args[0]), (u16)args[1]);
        (*state)++;
        break;
    case 1:
        if (BTLV_EFFECT_IsBusy() == 0) {
            BTLV_SCU_InitMessage((struct BtlvMessage *)((u8 *)&client->messageA), 1, 0x43);
            BTLV_CORE_BuildAndPrintMessage(client->view, ((u8 *)&client->messageA));
            (*state)++;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMessage(client->view) != 0) {
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
        BTLV_CORE_StartClearSidePosition((u32)client->view, side, kind);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_RunProc((u32)client->view) != 0) {
            side = (u8)args[1];
            if (side == 1) {
                return 1;
            }
            isPlayerSide = BTL_MAIN_IsTrainerSlotNpc(client->main, (u8)args[0]);
            BTLV_CORE_PrintSideMessage(client->view, selectSideEndMessageId(side, isPlayerSide), (int *)args);
            (*state)++;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMessage(client->view) != 0) {
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
            BTL_POKEPARAM_SetAbility(BTL_SIDE_GetPokeByIdThunk(client->side, pokeId), args[1]);
            return 1;
        }
        BTLV_CORE_ShowPortrait(client->view, monSlot, 0);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_UpdatePortraitSlideIn(client->view, monSlot) != 0) {
            BTL_POKEPARAM_SetAbility(BTL_SIDE_GetPokeByIdThunk(client->side, pokeId), args[1]);
            BTLV_CORE_ReloadPortrait(client->view, monSlot);
            (*state)++;
        }
        break;
    case 2:
        if (BTLV_CORE_UpdatePortraitMosaic(client->view, monSlot) != 0) {
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
    struct BtlPokeParam *pokeParamA, *pokeParamB;
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
            BTL_POKEPARAM_SetAbility(pokeParamA, abilityA);
            BTL_POKEPARAM_SetAbility(pokeParamB, abilityB);
            return 1;
        }
        if (BTL_MAIN_IsPokeSamePair(pokeIdA, pokeIdB)) {
            BTL_POKEPARAM_SetAbility(pokeParamA, abilityA);
            BTL_POKEPARAM_SetAbility(pokeParamB, abilityB);
            return 1;
        }
        BTLV_CORE_ShowPortrait((u32 *)(client->view), slotA, 0);
        gExpGainWork.w[1] = 8;
        (*state)++;
        break;
    case 1:
        BTLV_CORE_UpdatePortraitSlideIn(client->view, slotA);
        if (gExpGainWork.w[1]) gExpGainWork.w[1]--;
        else {
            BTLV_CORE_ShowPortrait(client->view, slotB, 0);
            (*state)++;
        }
        break;
    case 2: {
        u8 doneA, doneB;
        doneA = BTLV_CORE_UpdatePortraitSlideIn(client->view, slotA);
        doneB = BTLV_CORE_UpdatePortraitSlideIn(client->view, slotB);
        if (doneA && doneB) (*state)++;
        break;
    }
    case 3:
        BTL_POKEPARAM_SetAbility(pokeParamA, abilityA);
        BTL_POKEPARAM_SetAbility(pokeParamB, abilityB);
        gExpGainWork.w[1] = 0;
        (*state)++;
        break;
    case 4:
        gExpGainWork.w[1]++;
        if (gExpGainWork.w[1] > 8) {
            BTLV_CORE_ReloadPortrait(client->view, slotA);
            (*state)++;
        }
        break;
    case 5:
        if (BTLV_CORE_UpdatePortraitMosaic(client->view, slotA)) {
            BTLV_CORE_ReloadPortrait(client->view, slotB);
            (*state)++;
        }
        break;
    case 6:
        if (BTLV_CORE_UpdatePortraitMosaic(client->view, slotB)) (*state)++;
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
    struct BtlPokeParam *pokeParam;
    int mainStepActive;

    switch (*state) {
    case 0:
        pokeId = (u8)args[0];
        monSlot = BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, pokeId);
        pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, pokeId);
        mainStepActive = BTL_CLIENT_IsMainStepActive(client);
        BTL_POKEPARAM_ClearIllusion((struct Unk021D6C2C *)pokeParam);
        BTLV_CORE_StartMonSpriteLoad(client->view, monSlot, mainStepActive);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMonSpriteLoad(client->view) != 0) {
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
        BTLV_EFFECT_StartEffect(args[0]);
        (*state)++;
    } else {
        if (BTLV_EFFECT_IsBusy() == 0) return 1;
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
            if (BTL_ID_IsSimpleEffectId((u16)args[1]) != 0) {
                return 1;
            }
        }
        BTLV_CORE_StartViewEffect(client->view, monSlot, (u16)args[1]);
        (*state)++;
    } else {
        if (BTLV_CORE_WaitViewEffect(client->view) != 0) {
            return 1;
        }
    }
    return 0;
}

/* Command 0x4F. Two battle positions swap places in the view; args: positionA, positionB, animation. */
int BTL_CLIENT_CmdSwapViewPositions(struct BtlClient *client, int *seq, u32 *args)
{
    int viewPosA;
    int viewPosB;

    if (*seq == 0) {
        if (BTL_CLIENT_IsMainStepActive(client) != 0) {
            return 1;
        }
        viewPosA = BTL_MAIN_GetViewPosOfSlot(client->main, (u8)args[0]);
        viewPosB = BTL_MAIN_GetViewPosOfSlot(client->main, (u8)args[1]);
        BTLV_CORE_StartViewEffectEx(client->view, viewPosA, viewPosB, (u16)args[2]);
        (*seq)++;
    } else {
        if (BTLV_CORE_WaitViewEffectEx(client->view) != 0) {
            return 1;
        }
    }
    return 0;
}

/* Command 0x50. A Pokemon changes form; args: pokeId, form. */
int BTL_CLIENT_CmdChangeForm(struct BtlClient *client, int *seq, u32 *args)
{
    int viewPos;

    switch (*seq) {
    case 0:
        viewPos = BTL_MAIN_GetViewPosOfSlot(client->main, BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)args[0]));
        BTL_POKEPARAM_ChangeForm((struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]), (u8)args[1]);
        BTLV_CORE_StartMonSpriteChange(client->view, viewPos);
        (*seq)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMonSpriteChange(client->view) != 0) {
            (*seq)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}

/* Command 0x58. Show the status panel of a Pokemon; args: pokeId. */
int BTL_CLIENT_CmdShowStatusPanel(struct BtlClient *client, int *seq, u32 *args)
{
    int position;

    position = BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)args[0]);
    switch (*seq) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(client) != 0) {
            return 1;
        }
        BTLV_CORE_ShowPortrait(client->view, position, 1);
        (*seq)++;
        break;
    case 1:
        if (BTLV_CORE_UpdatePortraitSlideIn(client->view, position) != 0) {
            (*seq)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}

/* Command 0x01. Hide the status panel of a Pokemon; args: pokeId. */
int BTL_CLIENT_CmdHideStatusPanel(struct BtlClient *client, int *seq, u32 *args)
{
    int position;

    position = BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->side, (u8)args[0]);
    switch (*seq) {
    case 0:
        BTLV_CORE_StartPortraitSlideOut(client->view, position);
        (*seq)++;
        break;
    case 1:
        if (BTLV_CORE_WaitPortraitSlideOut(client->view, position) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Command 0x02. Subtract HP; args: pokeId, damage.
 * extent: compiled 30 bytes followed by two zero alignment bytes.
 */
int BTL_CLIENT_CmdHpMinus(struct BtlClient *client, int *seq, u32 *args)
{
    BTL_POKEPARAM_SubHp((struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]), args[1]);
    return 1;
}

/* Command 0x03. Add HP up to the maximum; args: pokeId, amount. */
int BTL_CLIENT_CmdHpPlus(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = (struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_AddHp(pokeParam, args[1]);
    return 1;
}

/* Command 0x05. Subtract PP of a move in both the original and the working copy; args: pokeId, moveSlot, amount. */
int BTL_CLIENT_CmdPpMinusOriginal(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    u8 moveSlot, amount;
    moveSlot = args[1];
    amount = args[2];
    pokeParam = (struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_DecrementMovePP(pokeParam, moveSlot, amount);
    return 1;
}

/* Command 0x06. Subtract PP of a move in the working copy only; args: pokeId, moveSlot, amount. */
int BTL_CLIENT_CmdPpMinusWorking(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    u8 moveSlot, amount;
    moveSlot = args[1];
    amount = args[2];
    pokeParam = (struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_DecrementRealMovePP(pokeParam, moveSlot, amount);
    return 1;
}

/* Command 0x07. Mark a move slot as used; args: pokeId, moveSlot. */
int BTL_CLIENT_CmdMarkMoveUsed(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    u8 moveSlot;
    moveSlot = args[1];
    pokeParam = (struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_MarkMoveUsed(pokeParam, moveSlot);
    return 1;
}

/* Command 0x04. Set HP to 0; args: pokeId. */
int BTL_CLIENT_CmdHpZero(struct BtlClient *client, int *seq, u32 *args)
{
    BTL_POKEPARAM_ZeroHp((struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)*args));
    return 1;
}

/* Command 0x08. Restore PP of the original move; args: pokeId, moveSlot, amount. */
int BTL_CLIENT_CmdPpPlusOriginal(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = (struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_RestoreMovePP(pokeParam, (u8)args[1], args[2]);
    return 1;
}

/* Command 0x09. Restore PP of the working move copy; args: pokeId, moveSlot, amount. */
int BTL_CLIENT_CmdPpPlusWorking(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = (struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_RestoreRealMovePP(pokeParam, (u8)args[1], args[2]);
    return 1;
}

/* Command 0x0A. Raise one stat stage; args: pokeId, statIndex, steps. */
int BTL_CLIENT_CmdStatStageUp(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = (struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_RaiseStatStage(pokeParam, args[1], args[2]);
    return 1;
}

/* Command 0x0B. Lower one stat stage; args: pokeId, statIndex, steps. */
int BTL_CLIENT_CmdStatStageDown(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = (struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_LowerStatStage(pokeParam, args[1], args[2]);
    return 1;
}

/* Command 0x0C. Set all seven stat stages; args: pokeId, then one stage per stat. */
int BTL_CLIENT_CmdSetStatStages(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = (struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_SetStatStage(pokeParam, 1, args[1]);
    BTL_POKEPARAM_SetStatStage(pokeParam, 2, args[2]);
    BTL_POKEPARAM_SetStatStage(pokeParam, 3, args[3]);
    BTL_POKEPARAM_SetStatStage(pokeParam, 4, args[4]);
    BTL_POKEPARAM_SetStatStage(pokeParam, 5, args[5]);
    BTL_POKEPARAM_SetStatStage(pokeParam, 6, args[6]);
    BTL_POKEPARAM_SetStatStage(pokeParam, 7, args[7]);
    return 1;
}

/* Command 0x0D. Recover lowered stat stages; args: pokeId. */
int BTL_CLIENT_CmdRecoverStatStages(struct BtlClient *client, int *seq, u32 *args)
{
    BTL_POKEPARAM_RaiseLoweredStatStages((struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)*args));
    return 1;
}

/* Command 0x0E. Reset all stat stages to neutral; args: pokeId. */
int BTL_CLIENT_CmdResetStatStages(struct BtlClient *client, int *seq, u32 *args)
{
    BTL_POKEPARAM_ResetStatStages((struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)*args));
    return 1;
}

/* Command 0x0F. Change the critical hit stage; args: pokeId, delta. */
int BTL_CLIENT_CmdAddCritStage(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = (struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_AddCritStage(pokeParam, args[1]);
    return 1;
}

/*
 * Command 0x10. Store a status condition; args: pokeId, sickIndex, condition.
 * lever: A declared one-word local assigned from args[2] preserves all 32
 * bits and emits the otherwise unused frame word. A cast lvalue at
 * args+2 compiled 30 bytes with the wrong frame and redundant address add.
 */
int BTL_CLIENT_CmdSetSick(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    union SickCont cont;

    pokeParam = (struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    cont.raw = args[2];
    BTL_POKEPARAM_SetSickCont(pokeParam, args[1], cont);
    return 1;
}

/* Command 0x11. Clear the major status; args: pokeId. */
int BTL_CLIENT_CmdCureMajorSick(struct BtlClient *client, int *seq, u32 *args)
{
    BTL_POKEPARAM_ClearMajorStatus((struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)*args));
    return 1;
}

/* Command 0x12. Clear one status condition; args: pokeId, sickIndex. */
int BTL_CLIENT_CmdCureSick(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = (struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_CureSick(pokeParam, args[1]);
    return 1;
}

/*
 * Command 0x13. A party member comes into battle: swap the two party
 * entries, reload the incoming Pokemon and arm its turn threshold; args[3]
 * is the threshold. The indices and the client come from the client work.
 */
int BTL_CLIENT_CmdMemberIn(struct BtlClient *client, int *seq, u32 *args)
{
    u8 indexFrom;
    u8 indexTo;
    void *party;
    struct BtlPokeParam *incoming;

    indexFrom = client->seqArgs[1];
    indexTo = client->seqArgs[2];
    party = BTL_SIDE_GetSlotOfClient(client->side, (u8)client->seqArgs[0]);
    if (indexFrom != indexTo)
        BTL_SLOT_Swap(party, indexFrom, indexTo);
    incoming = BTL_SLOT_GetPoke(party, indexFrom);
    BTL_POKEPARAM_StartTurnThreshold(incoming, args[3]);
    BTL_POKEPARAM_ReloadAndResetEffects(incoming);
    return 1;
}

/* Command 0x15. Set the two types of a Pokemon from a species; args: pokeId, species. */
int BTL_CLIENT_CmdSetPokeType(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = (struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_SetTypes(pokeParam, (u16)args[1]);
    return 1;
}

/*
 * Command 0x17. Clear status conditions on several Pokemon; args:
 * pokeCount, sickCount, packed poke ids (six 5-bit values). Each sick index
 * comes from BTL_ID_GetTurnCheckSick; a zero index ends the list.
 */
int BTL_CLIENT_CmdCureSickMulti(struct BtlClient *client, int *seq, u32 *args)
{
    u8 pokeIds[6];
    u32 i;
    u32 sickCount;
    u32 pokeCount;
    u32 j;
    u32 sickIndex;
    struct BtlPokeParam *pokeParam;

    sickCount = args[1];
    pokeCount = args[0];
    BTL_CALC_UnpackPokeIds(args[2], pokeIds);
    for (i = 0; i < sickCount; i++) {
        sickIndex = BTL_ID_GetTurnCheckSick(i);
        if (sickIndex == 0)
            break;
        for (j = 0; j < pokeCount; j++) {
            pokeParam = (struct BtlPokeParam *)BTL_SIDE_GetPokeByIdThunk(client->side, pokeIds[j]);
            if (BTL_POKEPARAM_IsFainted(pokeParam) == 0)
                BTL_POKEPARAM_TickSickCont(pokeParam, sickIndex, 0, 0);
        }
    }
    return 1;
}

/* Command steps 0x021D3A20 to 0x021D3D50. Every step takes the client, the
   step state and the command arguments; args[0] is the id of the Pokemon the
   command is about. The steps finish at once and return 1. */
int BTL_CLIENT_StepConsumeHeldItem(BtlClient *client, int *state, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_ConsumeHeldItem(pokeParam, args[1]);
    return 1;
}

/* args: pokeId, move slot, keep streak, target position, used move, selected move. */
int BTL_CLIENT_StepRecordMoveUse(BtlClient *client, int *state, const u32 *args)
{
    struct BtlPokeParam *pokeParam;
    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_RecordMoveUse(pokeParam, args[1], args[2], args[3], args[4], args[5]);
    return 1;
}

int BTL_CLIENT_StepSetContFlag(BtlClient *client, int *state, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_SetContFlag(pokeParam, args[1]);
    return 1;
}

int BTL_CLIENT_StepClearContFlag(BtlClient *client, int *state, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_ClearContFlag(pokeParam, args[1]);
    return 1;
}

int BTL_CLIENT_StepSetTurnFlag(BtlClient *client, int *state, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_SetTurnFlag(pokeParam, args[1]);
    return 1;
}

int BTL_CLIENT_StepClearTurnFlag(BtlClient *client, int *state, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_ClearTurnFlag(pokeParam, args[1]);
    return 1;
}

int BTL_CLIENT_StepSetAbility(BtlClient *client, int *state, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_SetAbility(pokeParam, args[1]);
    return 1;
}

int BTL_CLIENT_StepSetItem(BtlClient *client, int *state, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_SetItem(pokeParam, args[1]);
    return 1;
}

/* args: pokeId, move slot, pp cap, to-real flag, new move id. */
int BTL_CLIENT_StepReplaceMove(BtlClient *client, int *state, const u32 *args)
{
    struct BtlPokeParam *pokeParam;
    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_ReplaceMove(pokeParam, args[1], args[4], args[2], args[3]);
    return 1;
}

int BTL_CLIENT_StepResetEffectsOnSwitchOut(BtlClient *client, int *state, u32 *args)
{
    BTL_POKEPARAM_ResetEffectsOnSwitchOut(BTL_SIDE_GetPokeByIdThunk(client->side, (u8)*args));
    return 1;
}

/* args: field slot, slot key. */
int BTL_CLIENT_StepRegisterFieldSlot(BtlClient *client, int *state, u32 *args)
{
    BtlFieldSlotKey key;
    key.word = args[1];
    BTL_FIELD_RegisterSlot(client->battleField, args[0], key, 0);
    return 1;
}

/* args: field slot, pokeId. */
int BTL_CLIENT_StepAddFieldSlotHolder(BtlClient *client, int *state, u32 *args)
{
    BTL_FIELD_AddSlotHolder(client->battleField, args[0], (u8)args[1]);
    return 1;
}

int BTL_CLIENT_StepRemoveFieldHolder(BtlClient *client, int *state, u32 *args)
{
    BTL_FIELD_RemoveHolderFromSlots(client->battleField, (u8)args[0]);
    return 1;
}

int BTL_CLIENT_StepRemoveFieldSlot(BtlClient *client, int *state, u32 *args)
{
    BTL_FIELD_RemoveSlot(client->battleField, args[0]);
    return 1;
}

/* args: pokeId, counter index, value. */
int BTL_CLIENT_StepSetPokeCounter(BtlClient *client, int *state, u32 *args)
{
    struct BtlPokeParam *pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_SetCounter(pokeParam, args[1], args[2]);
    return 1;
}

/* args: pokeId of the one passing its effects, pokeId of the one receiving them. */
int BTL_CLIENT_StepPassEffects(BtlClient *client, int *state, u32 *args)
{
    struct BtlPokeParam *source = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    struct BtlPokeParam *target = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[1]);
    BTL_POKEPARAM_PassEffects(target, source);
    return 1;
}

int BTL_CLIENT_StepSetSubstituteHp(BtlClient *client, int *state, u32 *args)
{
    struct BtlPokeParam *pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_SetSubstituteHp(pokeParam, args[1]);
    return 1;
}

int BTL_CLIENT_StepClearSubstitute(BtlClient *client, int *state, u32 *args)
{
    BTL_POKEPARAM_ClearSubstitute(BTL_SIDE_GetPokeByIdThunk(client->side, (u8)*args));
    return 1;
}

/* args: client id, points. The points go to this client or to the battle main. */
int BTL_CLIENT_StepAddClientPoints(BtlClient *client, int *state, u32 *args)
{
    u8 clientId = args[0];
    u8 points = args[1];
    if (clientId == client->clientId)
        BTL_CLIENT_AddPoints(client, points);
    else
        BTL_MAIN_AddClientPoints(client->main, clientId, points);
    return 1;
}

int BTL_CLIENT_StepUpdateIllusion(BtlClient *client, int *state, u32 *args)
{
    u8 clientId = args[0];
    struct BtlSideSlot *slot = (struct BtlSideSlot *)BTL_SIDE_GetSlotOfClient(client->side, clientId);
    BTL_SLOT_UpdateIllusion(client->main, slot, clientId);
    return 1;
}

int BTL_CLIENT_StepClearConsumedItem(BtlClient *client, int *state, u32 *args)
{
    BTL_POKEPARAM_ClearConsumedItem(BTL_SIDE_GetPokeByIdThunk(client->side, (u8)*args));
    return 1;
}

/* args: pokeId, sick source. */
int BTL_CLIENT_StepCureSickBySource(BtlClient *client, int *state, u32 *args)
{
    struct BtlPokeParam *pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_CureSickBySource(pokeParam, (u8)args[1]);
    return 1;
}

/* args: pokeId, attacker id, hit flags, move type, move id, damage.
 * The const source pointer restores the five-load acquisition order. The hit
 * flags are stored as a byte, so the record keeps its high flag byte
 * uninitialized, as in the original. */
int BTL_CLIENT_StepAddHitRecord(BtlClient *client, int *state, const u32 *args)
{
    struct BtlHitRecord record;
    struct BtlPokeParam *pokeParam;
    u16 moveId, damage;
    u8 moveType, hitFlags, attackerId;
    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    moveId = args[4];
    damage = args[5];
    moveType = args[3];
    hitFlags = args[2];
    attackerId = args[1];
    record.moveId = moveId;
    record.damage = damage;
    record.moveType = moveType;
    record.attackerId = attackerId;
    *(u8 *)&record.hitFlags = hitFlags;
    BTL_POKEPARAM_AddHitRecord(pokeParam, &record);
    return 1;
}

int BTL_CLIENT_StepAdvanceTurn(BtlClient *client, int *state, u32 *args)
{
    struct BtlPokeParam *pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_AdvanceTurn(pokeParam);
    BTL_EVENT_ClearClientReservedChoice(pokeParam);
    return 1;
}

/* Tick every field slot without an expiry callback. */
int BTL_CLIENT_StepTickFieldSlots(BtlClient *client)
{
    BTL_FIELD_TickSlots(client->battleField, 0, 0);
    return 1;
}

/* args: pokeId, value index, value. */
int BTL_CLIENT_StepSetStat(BtlClient *client, int *state, u32 *args)
{
    int valueId = args[1];
    struct BtlPokeParam *pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_SetStat(pokeParam, valueId, args[2]);
    return 1;
}

int BTL_CLIENT_StepSetWeight(BtlClient *client, int *state, u32 *args)
{
    struct BtlPokeParam *pokeParam = BTL_SIDE_GetPokeByIdThunk(client->side, (u8)args[0]);
    BTL_POKEPARAM_SetWeight(pokeParam, (u16)args[1]);
    return 1;
}

u8 BTL_CLIENT_GetClientId(BtlClient *client)
{
    return client->clientId;
}

void *BTL_CLIENT_GetSideData(BtlClient *client)
{
    return client->sideData;
}

u8 BTL_CLIENT_GetFieldCountdownByte(BtlClient *client)
{
    return BTL_FIELD_GetCountdownByte(client->battleField);
}

u8 BTL_CLIENT_GetPointCounter(BtlClient *client)
{
    return client->pointCounter;
}

/* Fill the trainer item list of the client from the battle main. */
void BTL_CLIENT_LoadTrainerItems(BtlClient *client)
{
    u32 i;
    for (i = 0; i < 4; i++)
        client->trainerItems[i] = BTL_MAIN_GetTrainerItem(client->main, client->clientId, (u8)i);
}

/* Choose a trainer item for the AI to use on the Pokemon, or return 0. The
   item is removed from the list when chosen. */
u32 BTL_CLIENT_TakeTrainerItemToUse(BtlClient *client, struct BtlPokeParam *mon, void *party)
{
    u32 i;
    u32 usable;
    u32 itemId;
    u32 limit;
    u32 off;
    u8 *items;

    limit = BTL_SLOT_GetCount(party);
    if (BTL_POKEPARAM_HasSick(mon, 0x13) != 0)
        return 0;
    for (i = 0; i < 4; i++) {
        if (gBtlClientItemSlotLimits[i] < limit)
            break;
        off = i * 2;
        if (*(u16 *)((u8 *)client + off + 0xe8) != 0) {
            usable = 0;
            if (BTL_CALC_GetItemParam((void *)(u32)*(u16 *)((u8 *)client + off + 0xe8), 0x29) != 0) {
                usable = BTL_POKEPARAM_GetValue(mon, 0xd);
                if (usable > BTL_CALC_DivideMaxHp(mon, 4))
                    continue;
                usable = 1;
            } else {
                if (BTL_CLIENT_IsStatItemUsable((u32)*(u16 *)((u8 *)client + off + 0xe8), mon) != 0)
                    usable = 1;
                else if (BTL_CLIENT_IsSickItemUsable((u32)*(u16 *)((u8 *)client + off + 0xe8), mon) != 0)
                    usable = 1;
            }
            if (usable != 0) {
                items = (u8 *)client + 0xe8;
                itemId = *(u16 *)(items + off);
                *(u16 *)(items + off) = 0;
                return itemId;
            }
        }
    }
    return 0;
}

/* Whether the item raises a stat stage of the Pokemon that is not yet raised. */
int BTL_CLIENT_IsStatItemUsable(u32 itemId, struct BtlPokeParam *mon)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        if (BTL_CALC_GetItemParam((void *)itemId, gBtlClientItemStatChecks[i].itemParam) != 0 && BTL_POKEPARAM_CanChangeStatStage(mon, gBtlClientItemStatChecks[i].statIndex, 1) != 0)
            return 1;
    }
    if (BTL_CALC_GetItemParam((void *)itemId, 0x24) != 0 && BTL_POKEPARAM_GetCritStage(mon) == 0)
        return 1;
    return 0;
}

/* Whether the item cures a sick condition the Pokemon has. */
int BTL_CLIENT_IsSickItemUsable(u32 itemId, struct BtlPokeParam *mon)
{
    u32 i;
    for (i = 0; i < 7; i++)
        if (BTL_CALC_GetItemParam((void *)itemId, gBtlClientItemSickChecks[i].itemParam) && BTL_POKEPARAM_HasSick(mon, gBtlClientItemSickChecks[i].sickId))
            return 1;
    return 0;
}

void BTL_CLIENT_ResetCounter(BtlClientCounter *counter)
{
    counter->mode = 0;
    counter->advancePending = 0;
    counter->state = 0;
    counter->fadeStarted = 0;
    counter->current = 0;
    counter->fadeDone = 0;
    counter->target = 0;
    counter->replaying = 0;
    counter->maximum = 0;
    counter->locked = 0;
    counter->disabled = 0;
    counter->tick = 0;
    counter->confirmDelay = 0;
}

/*
 * strh v at #0xa
 */
void BTL_CLIENT_SetCounterMaximum(BtlClientCounter *counter, u32 v)
{
    counter->maximum = v;
}

int BTL_CLIENT_IsCounterFadeDone(BtlClientCounter *counter)
{
    return counter->fadeDone;
}

/*
 * Extent follower 021D3F60 is already filed separately.
 */
void BTL_CLIENT_RequestCounterAdvance(BtlClientCounter *counter)
{
    counter->advancePending = 1;
}

/*
 * extent: Parent approved only the bounded four-byte accessor. Unapproved
 * followers 021D3F64 and 021D3F88, matched 021D3F98 and code 021D3FA8 follow;
 * no follower is included in this source.
 */
u8 BTL_CLIENT_GetCounterMode(BtlClientCounter *counter)
{
    return counter->mode;
}

/*
 * note 2026-10-05: object is the same 14-byte record as BTL_CLIENT_ResetCounter (bit flags in byte 2).
 *   Sets h8 = v, bit0 = 1, h12 = 0, clears bits 1 and 2. Source order h12 = 0 before h8 = v:
 *   the scheduler hoists the strh, and r1 (v) stays live so the zero takes r2.
 */
void BTL_CLIENT_StartCounterReplay(BtlClientCounter *counter, u16 v)
{
    counter->replaying = 1;
    counter->tick = 0;
    counter->target = v;
    counter->fadeStarted = 0;
    counter->fadeDone = 0;
}

/*
 * Extent follower 021D3F98 is already filed separately; bitfield clear produces bics.
 */
void BTL_CLIENT_StopCounterReplay(BtlClientCounter *counter)
{
    counter->state = 0;
    counter->replaying = 0;
}

int BTL_CLIENT_IsCounterReplayDone(BtlClientCounter *counter)
{
    if (counter->tick == counter->target) return 1;
    return 0;
}

/*
 * ldrh at #0x8
 */
u16 BTL_CLIENT_GetCounterTarget(BtlClientCounter *counter)
{
    return counter->target;
}

/*
 * extent: Twenty-two code bytes plus two zero padding bytes at 021D3FC2;
 * the approved separate 021D3FC4 leaf and existing 021D3FD0 follow.
 */
int BTL_CLIENT_TryLockCounter(BtlClientCounter *counter)
{
    if (counter->fadeStarted) return 0;
    counter->locked = 1;
    return 1;
}

/*
 * match-note: Clearing the unsigned-char bitfield emits bics #0x10;
 * raw p[2] &= ~0x10 emits ands #0xef and was four bytes out.
 * extent: Ten bytes of code, two zero padding bytes at 021D3FCE, then
 * existing matched BTL_CLIENT_DisableCounter at 021D3FD0; no follower included.
 */
void BTL_CLIENT_UnlockCounter(BtlClientCounter *counter)
{
    counter->locked = 0;
}

void BTL_CLIENT_DisableCounter(BtlClientCounter *counter)
{
    counter->disabled = 1;
}

/*
 * note 2026-10-05: now verifies EXACT (BTLV_EFFECT_SuspendVmWait resolves).
 * match-note: A goto to the bottom epilogue reproduces the entry guards;
 * input is called before adjusted=0, preserving the original scheduling.
 */
void BTL_CLIENT_TickCounter(BtlClient *client, BtlClientCounter *counter)
{
    int changed, adjusted, input;
    if (client->kind != 2 || counter->locked || counter->disabled || !counter->maximum) goto done;
    changed = 0;
    if (counter->advancePending) {
        counter->advancePending = 0;
        if (!counter->replaying) {
            if (counter->current < counter->maximum && counter->state == 0) {
                ++counter->current;
                if (!counter->confirmDelay) counter->target = counter->current;
                changed = 1;
            }
        } else {
            if (counter->tick < counter->target) {
                ++counter->tick;
                if (counter->tick == counter->target) {
                    counter->current = counter->target;
                    if (client->view) BTLV_CORE_SetCounterDisplay(client->view,counter->current,counter->target);
                }
            }
            return;
        }
    }
    if (!counter->current || !client->view) return;
    switch (counter->state) {
    case 0:
        input = BTLV_CORE_PollCounterInput(client->view);
        adjusted = 0;
        switch (input) {
        case 2:
            counter->mode = 1;
            BTLV_CORE_StartFadeIn(client->view);
            counter->fadeStarted = 1;
            counter->state = 1;
            BTLV_CORE_SetCounterValueMode(client->view,counter->current,1);
            GFL_USE_FadeOutBgm(30);
            GFL_USE_SetPlayersAudible(0,62);
            PM_VOICE_SetMasterVolume(0);
            BTLV_EFFECT_SuspendVmWait();
            BTL_MAIN_SetKeepBgm((u8 *)client->main);
            break;
        case 0:
            if (counter->target > 1) { --counter->target; adjusted = 1; }
            counter->confirmDelay = 45;
            break;
        case 1:
            if (counter->target < counter->maximum) { ++counter->target; adjusted = 1; }
            counter->confirmDelay = 45;
            break;
        }
        if (adjusted || changed) BTLV_CORE_SetCounterDisplay(client->view,counter->current,counter->target);
        if (counter->confirmDelay) {
            --counter->confirmDelay;
            if (!counter->confirmDelay) {
                counter->mode = 2;
                BTLV_CORE_StartFadeIn(client->view);
                counter->fadeStarted = 1;
                counter->state = 1;
                GFL_USE_FadeOutBgm(30);
                GFL_USE_SetPlayersAudible(0,62);
                PM_VOICE_SetMasterVolume(0);
                BTLV_EFFECT_SuspendVmWait();
            }
        }
        break;
    case 1:
        if (BTLV_CORE_PollFadeInDone(client->view)) { counter->fadeDone = 1; counter->state = 2; }
        break;
    case 2:
        break;
    }
done:
    return;
}
