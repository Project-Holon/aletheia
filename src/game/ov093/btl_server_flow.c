/*
 * file:     btl_server_flow.c
 * unit:     yes
 * function: BTL_SERVER_FLOW_Create, BTL_SERVER_FLOW_Reset, BTL_SERVER_FLOW_InitState, BTL_SERVER_FLOW_Destroy, BTL_SERVER_FLOW_RunBattleStart, BTL_SERVER_FLOW_ResetInitState, BTL_SERVER_FLOW_StartTurn, BTL_SERVER_FLOW_ProcTurnStartEvents, BTL_SERVER_FLOW_ResetInitStateAfterSelect, BTL_SERVER_FLOW_StartAfterPokeSelect, BTL_SERVER_FLOW_ResetInitStateAfterChange, BTL_SERVER_FLOW_StartAfterPokeChange, BTL_SERVER_FLOW_RunActionOrder, BTL_SERVER_FLOW_ResortActionOrder, BTL_SERVER_FLOW_ProcPokeChangeActions, BTL_SERVER_FLOW_CheckShowdown, BTL_SERVER_FLOW_CheckPlayerSideAlive, BTL_SERVER_FLOW_RunEscapeFromLead, BTL_SERVER_FLOW_RunBagModeSetup, BTL_SERVER_FLOW_PushBagModePositions, BTL_SERVER_FLOW_ProcRotation, BTL_SERVER_FLOW_CollectChangeRequests, BTL_SERVER_FLOW_GetSlotTable, BTL_SERVER_FLOW_GetChosenSlot, BTL_SERVER_FLOW_ProcPreTurnMoveCheck, BTL_SERVER_FLOW_BuildActionOrder, BTL_SERVER_FLOW_SortActionOrder, BTL_SERVER_FLOW_CalcMovePriority, BTL_SERVER_FLOW_CalcPokeSpeed, BTL_SERVER_FLOW_FindActionByPokeId, BTL_SERVER_FLOW_FindNextActionByPokeId, BTL_SERVER_FLOW_FindPendingActionByMove, BTL_SERVER_FLOW_FindPendingMoveActionForPoke, BTL_SERVER_FLOW_GetActionIndex, BTL_SERVER_FLOW_MoveActionForward, BTL_SERVER_FLOW_MoveActionToEnd, BTL_SERVER_FLOW_ProcAction, BTL_SERVER_FLOW_NotifyActionStart, BTL_SERVER_FLOW_DispatchActionStartEvent, BTL_SERVER_FLOW_DispatchActionEndEvent, BTL_SERVER_FLOW_CheckDisobedience, BTL_SERVER_FLOW_CheckObedienceOverride, BTL_SERVER_FLOW_ForceExecuteMoveAction, BTL_SERVER_FLOW_PromoteActionOfPoke, BTL_SERVER_FLOW_PromoteActionsByMove, BTL_SERVER_FLOW_DemoteActionOfPoke, BTL_SERVER_FLOW_MarkActionDone, BTL_SERVER_FLOW_InitTurnState, BTL_SERVER_FLOW_SetupTurnState, BTL_SERVER_FLOW_InitFieldPokeIter, BTL_SERVER_FLOW_SetFieldPokeIterRule, BTL_SERVER_FLOW_NextFieldPokeIter, BTL_SERVER_FLOW_ProcShift, BTL_SERVER_FLOW_ShiftPokes, BTL_SERVER_FLOW_DispatchShiftEvents, BTL_SERVER_FLOW_DispatchShiftInEventLocked, BTL_SERVER_FLOW_DispatchShiftInEvent, BTL_SERVER_FLOW_ProcEscape, BTL_SERVER_FLOW_TryEscape, BTL_SERVER_FLOW_CheckEscapeGuaranteed, BTL_SERVER_FLOW_CommitEscape, BTL_SERVER_FLOW_CheckEscapePrevented, BTL_SERVER_FLOW_CheckEscapeMessageSuppressed, BTL_SERVER_FLOW_ProcMemberInCore, BTL_SERVER_FLOW_ProcMemberIn, BTL_SERVER_FLOW_ProcAfterMemberIn, BTL_SERVER_FLOW_DispatchPokeEntryEvent, BTL_SERVER_FLOW_DispatchPokeEntryEventToType4, BTL_SERVER_FLOW_DispatchMemberInBeginEvent, BTL_SERVER_FLOW_DispatchMemberInEndEvent, BTL_SERVER_FLOW_NotifyRotationEnd, BTL_SERVER_FLOW_DispatchRotationEndEvent, BTL_SERVER_FLOW_PushMemberOutCmd, BTL_SERVER_FLOW_ProcMemberChange, BTL_SERVER_FLOW_ProcMemberOut, BTL_SERVER_FLOW_ProcMemberOutCore, BTL_SERVER_FLOW_DispatchMemberOutEvent, BTL_SERVER_FLOW_GetEncoredMove, BTL_SERVER_FLOW_ProcFight, BTL_SERVER_FLOW_CheckMoveRestricted, BTL_SERVER_FLOW_ProcDeferredMoves, BTL_SERVER_FLOW_InitMoveQueue, BTL_SERVER_FLOW_PushMoveQueue, BTL_SERVER_FLOW_ProcInterruptMove, BTL_SERVER_FLOW_DispatchMoveTypeEvent, BTL_SERVER_FLOW_DispatchMoveParamEventLocked, BTL_SERVER_FLOW_DispatchMoveParamEvent, BTL_SERVER_FLOW_ProcPledgeCombo, func_021BE7E4, BTL_SERVER_FLOW_DispatchMoveExecuteCheckEvent, BTL_SERVER_FLOW_NotifyMoveExecuteFail, BTL_SERVER_FLOW_DispatchMoveExecuteFailEvent, BTL_SERVER_FLOW_NotifyMoveStart, BTL_SERVER_FLOW_DispatchMoveStartEvent, BTL_SERVER_FLOW_NotifyMoveEnd, BTL_SERVER_FLOW_DispatchMoveEndEvent, BTL_SERVER_FLOW_DispatchMoveInterruptEvent, BTL_SERVER_FLOW_DispatchDeferredMoveEvent, BTL_SERVER_FLOW_CheckMoveInterrupt, BTL_SERVER_FLOW_DispatchMoveInterruptCheckEvent, BTL_SERVER_FLOW_PushMoveExecCmd, BTL_SERVER_FLOW_IsPlayerSidePoke, BTL_SERVER_FLOW_RecordSpecialMoveUse, func_021BEC58, BTL_SERVER_FLOW_RemoveOutOfRangeTargets, BTL_SERVER_FLOW_RemoveSelfTarget, BTL_SERVER_FLOW_CheckAccuracyCheckRequired, BTL_SERVER_FLOW_RemoveSubstituteTargets, BTL_SERVER_FLOW_NotifyMoveSucceeded, BTL_SERVER_FLOW_NotifyMoveFailed, BTL_SERVER_FLOW_NotifyMoveFinished, BTL_SERVER_FLOW_DispatchMoveResultEvent, func_021BF324, BTL_SERVER_FLOW_ProcAccuracyCheck, BTL_SERVER_FLOW_ProcNoEffectChecks, BTL_SERVER_FLOW_ProcNoEffectCheck, BTL_SERVER_FLOW_RunTargetNoEffectEvent, BTL_SERVER_FLOW_RemoveImmuneTargets, BTL_SERVER_FLOW_RemoveMissedTargets, BTL_SERVER_FLOW_CheckMoveAvoidEvent, BTL_SERVER_FLOW_CheckAllyMoveAutoHit, BTL_SERVER_FLOW_RollMoveAccuracy, BTL_SERVER_FLOW_PushPendingHpRecovery, func_021BFC08, BTL_SERVER_FLOW_ProcMoveUseDecide, BTL_SERVER_FLOW_ClearMoveLockSicks, BTL_SERVER_FLOW_ProcMoveReflectOrAbsorb, BTL_SERVER_FLOW_ReleaseBindingTarget, func_021C001C, BTL_SERVER_FLOW_CheckMoveExecuteFailByEvent, BTL_SERVER_FLOW_QueryStatusSkipEvent, BTL_SERVER_FLOW_QueryMoveFailReasonEvent, BTL_SERVER_FLOW_CheckParalysisFail, BTL_SERVER_FLOW_CheckConfusionSelfHit, BTL_SERVER_FLOW_TickSleepTurn, BTL_SERVER_FLOW_CheckFreezeThaw, BTL_SERVER_FLOW_ProcMoveExecuteFail, BTL_SERVER_FLOW_PushMoveFailMessage, BTL_SERVER_FLOW_SetPokeCounter, BTL_SERVER_FLOW_ReducePPByEvent, BTL_SERVER_FLOW_QueryMovePPCostEvent, BTL_SERVER_FLOW_ConsumeMovePP, BTL_SERVER_FLOW_DecrementMovePP, BTL_SERVER_FLOW_ProcMoveHitTargets, BTL_SERVER_FLOW_BuildDamageList, BTL_SERVER_FLOW_GetHitFlagsByte2, BTL_SERVER_FLOW_UnpackDamageEntries, BTL_SERVER_FLOW_UnpackEntryPokes, BTL_SERVER_FLOW_UnpackHitEntries, BTL_SERVER_FLOW_SumHitRecordDamage, BTL_SERVER_FLOW_ProcDamageTargets, BTL_SERVER_FLOW_ProcMultiHitDamage, BTL_SERVER_FLOW_IsFirstHit, BTL_SERVER_FLOW_GetHitFlagsMultiHit, BTL_SERVER_FLOW_SetHitFlagsResultIf3, BTL_SERVER_FLOW_ProcDamageRecordIfAny, BTL_SERVER_FLOW_ApplyDamageRecord, BTL_SERVER_FLOW_RemoveSelfProtectedTargets, func_021C15AC, BTL_SERVER_FLOW_ClampDamageToHp, BTL_SERVER_FLOW_RunMoveHitEventLocked, BTL_SERVER_FLOW_RunMoveHitEvent, BTL_SERVER_FLOW_CheckEndureEvent, BTL_SERVER_FLOW_ProcDamageAftereffect, BTL_SERVER_FLOW_RunDamageAftereffectEvent, BTL_SERVER_FLOW_RunTargetsDamagedEventLocked, BTL_SERVER_FLOW_RunTargetsDamagedEvent, BTL_SERVER_FLOW_RecordDamageHit, BTL_SERVER_FLOW_ProcMoveCategoryEffect, BTL_SERVER_FLOW_RunDamageDealtEventLocked, BTL_SERVER_FLOW_RunDamageDealtEvent, BTL_SERVER_FLOW_ProcDamagedItemReaction, BTL_SERVER_FLOW_RunDamagedItemEvent, BTL_SERVER_FLOW_RunMoveUsedEventLocked, BTL_SERVER_FLOW_RunMoveUsedEvent, BTL_SERVER_FLOW_ProcMoveAfterDamageEvents, BTL_SERVER_FLOW_RunMoveDamageGroupEvent, BTL_SERVER_FLOW_RunMoveDamageEndEvent, BTL_SERVER_FLOW_ProcFlinchChance, BTL_SERVER_FLOW_ThawTargetsHitByFireMove, BTL_SERVER_FLOW_RollFlinch, BTL_SERVER_FLOW_ProcDrainHeal, BTL_SERVER_FLOW_RecoverHpFromDrain, BTL_SERVER_FLOW_CalcMoveDamage, BTL_SERVER_FLOW_ProcDamageAbsorbRecovery, BTL_SERVER_FLOW_CheckAbsorbRecoverAllowed, BTL_SERVER_FLOW_ProcAbsorbRecovery, BTL_SERVER_FLOW_ProcHeldItemActivate, BTL_SERVER_FLOW_RunItemActivateCheckEvent, BTL_SERVER_FLOW_SetHeldItem, BTL_SERVER_FLOW_ProcPokeHpChangeFinish, BTL_SERVER_FLOW_ProcMoveAddedSick, BTL_SERVER_FLOW_RollMoveAddedSick, BTL_SERVER_FLOW_ProcMoveSickAllTargets, BTL_SERVER_FLOW_ProcMoveSickOnTarget, BTL_SERVER_FLOW_QueryMoveSickIdEvent, BTL_SERVER_FLOW_RunMoveSickSelectedEvent, BTL_SERVER_FLOW_RunMoveSickContEvent, BTL_SERVER_FLOW_ApplyMoveSick, BTL_SERVER_FLOW_TryApplySick, BTL_SERVER_FLOW_CheckSickImmunity, BTL_SERVER_FLOW_ProcSickAdded, BTL_SERVER_FLOW_GetEffectiveWeather, BTL_SERVER_FLOW_QueryPokeMultiplierEvent, BTL_SERVER_FLOW_QuerySickBlockedEvent, BTL_SERVER_FLOW_RunSickAppliedEvent, BTL_SERVER_FLOW_RunSickAddedContEvent, BTL_SERVER_FLOW_RunSickAddedEvent, BTL_SERVER_FLOW_RunSickEndEvent, BTL_SERVER_FLOW_ProcMoveAddedRankEffect, BTL_SERVER_FLOW_RollMoveAddedEffectChance, BTL_SERVER_FLOW_ProcMoveRankEffectAllTargets, BTL_SERVER_FLOW_NextSerialNumber, BTL_SERVER_FLOW_ProcMoveRankEffects, BTL_SERVER_FLOW_QueryMoveRankEffectEvent, BTL_SERVER_FLOW_TryChangeStatStage, BTL_SERVER_FLOW_QueryStatStageChangeEvent, BTL_SERVER_FLOW_ProcMoveRankAndSickAllTargets, BTL_SERVER_FLOW_ProcMoveRecoverHpAllTargets, BTL_SERVER_FLOW_TryRecoverHp, BTL_SERVER_FLOW_IsHpRecoverUnneeded, BTL_SERVER_FLOW_CheckHealBlocked, BTL_SERVER_FLOW_ApplyHpRecover, BTL_SERVER_FLOW_ProcMoveOhko, BTL_SERVER_FLOW_ProcOhkoFaint, BTL_SERVER_FLOW_ProcOhkoEndured, BTL_SERVER_FLOW_ProcOhkoSubstituteBroken, BTL_SERVER_FLOW_ProcMoveForceSwitchAllTargets, BTL_SERVER_FLOW_TryForceSwitchTarget, BTL_SERVER_FLOW_IsForceSwitchByParty, BTL_SERVER_FLOW_PickRandomBenchPoke, BTL_SERVER_FLOW_QueryForceSwitchBlockedEvent, BTL_SERVER_FLOW_ProcMoveWeather, BTL_SERVER_FLOW_TryChangeWeather, BTL_SERVER_FLOW_CanChangeWeather, BTL_SERVER_FLOW_ApplyWeatherChange, BTL_SERVER_FLOW_ProcWeatherChanged, BTL_SERVER_FLOW_QueryWeatherPokeEvent, BTL_SERVER_FLOW_TryRegisterFieldSlot, BTL_SERVER_FLOW_DispatchPokeMoveEvent, BTL_SERVER_FLOW_ProcMoveSpecialEffect, BTL_SERVER_FLOW_ProcSkillSwap, BTL_SERVER_FLOW_RecheckOpponentAbilityEffects, BTL_SERVER_FLOW_ProcSubstituteMove, BTL_SERVER_FLOW_ProcSubstituteDamage, BTL_SERVER_FLOW_RemoveSubstitute, BTL_SERVER_FLOW_ProcDamageEndEvents, BTL_SERVER_FLOW_DispatchDamageEndEvents, BTL_SERVER_FLOW_DispatchMoveFailCheck, BTL_SERVER_FLOW_CollectActivePokes, BTL_SERVER_FLOW_ProcTurnCheck, BTL_SERVER_FLOW_ProcTripleShift, BTL_SERVER_FLOW_ProcPlayerSupportHeal, BTL_SERVER_FLOW_ProcTurnCheckPhase, BTL_SERVER_FLOW_DispatchTurnCheckEvent, BTL_SERVER_FLOW_ProcTurnCheckSickness, BTL_SERVER_FLOW_ProcSickDamage, BTL_SERVER_FLOW_CalcSickDamage, BTL_SERVER_FLOW_ProcSideEffectsExpire, BTL_SERVER_FLOW_OnSideEffectExpired, BTL_SERVER_FLOW_PushSideEffectExpireMessage, BTL_SERVER_FLOW_ProcFieldEffectsExpire, func_021C4C40, BTL_SERVER_FLOW_PushFieldEffectExpireMessage, BTL_SERVER_FLOW_ProcWeatherTurnCheck, BTL_SERVER_FLOW_CalcWeatherDamage, BTL_SERVER_FLOW_ApplyWeatherDamage, BTL_SERVER_FLOW_ProcFaintedPoke, BTL_SERVER_FLOW_GetHighestOpponentLevel, BTL_SERVER_FLOW_ProcPokeLeaveField, BTL_SERVER_FLOW_DispatchPokeLeaveEvent, BTL_SERVER_FLOW_ProcFaintRewards, BTL_SERVER_FLOW_ProcExpForFaintedPoke, BTL_SERVER_FLOW_ApplyPartyExp, BTL_SERVER_FLOW_TryClearContFlag, BTL_SERVER_FLOW_ClearPendingCounter, BTL_SERVER_FLOW_PushPokeEffectAnim, BTL_SERVER_FLOW_PushActionBlockedMessage, BTL_SERVER_FLOW_PushConfusionMessage, BTL_SERVER_FLOW_PushInfatuationMessage, BTL_SERVER_FLOW_ApplyFixedDamageEffect, BTL_SERVER_FLOW_CureMajorStatusWithMessage, BTL_SERVER_FLOW_PushPokeCmd59, BTL_SERVER_FLOW_CureSick, BTL_SERVER_FLOW_ResolveCureSickId, BTL_SERVER_FLOW_PushMsgStdFailed, BTL_SERVER_FLOW_PushMoveBlockedMessage, BTL_SERVER_FLOW_PushNoEffectMessage, BTL_SERVER_FLOW_PushActionFailedMessage, BTL_SERVER_FLOW_PushMoveEffectiveness, func_021C5840, BTL_SERVER_FLOW_PushCriticalHitMessage, BTL_SERVER_FLOW_PushAbilityPopupIn, BTL_SERVER_FLOW_PushAbilityPopupOut, BTL_SERVER_FLOW_PushSignedChangeMessage, BTL_SERVER_FLOW_ChangeStatStage, BTL_SERVER_FLOW_ChangeHp, BTL_SERVER_FLOW_KillPoke, BTL_SERVER_FLOW_SetSickCont, BTL_SERVER_FLOW_PushSickFailedMessage, BTL_SERVER_FLOW_PushMsgSetPoke, BTL_SERVER_FLOW_PushMsgStd, BTL_SERVER_FLOW_PushMsgStdSe, BTL_SERVER_FLOW_PushMsgSet, BTL_SERVER_FLOW_PushMsgSetSe, BTL_SERVER_FLOW_SubtractHp, BTL_SERVER_FLOW_RestoreMovePp, BTL_SERVER_FLOW_PushPokeCmd42, BTL_SERVER_FLOW_SetContFlag, BTL_SERVER_FLOW_ClearContFlag, BTL_SERVER_FLOW_SetTurnFlag, BTL_SERVER_FLOW_ProcClientMemberChange, BTL_SERVER_FLOW_ProcPursuitBeforeSwitch, BTL_SERVER_FLOW_QueryForcedMoveEvent, BTL_SERVER_FLOW_QueryActionAllowedEvent, BTL_SERVER_FLOW_NotifyMoveEvent, BTL_SERVER_FLOW_ProcConfusionDamage, BTL_SERVER_FLOW_QueryActionMessageEvent, BTL_SERVER_FLOW_GetMoveParam, BTL_SERVER_FLOW_DispatchMoveDoneEvent, BTL_SERVER_FLOW_QueryMoveExecuteEvent, BTL_SERVER_FLOW_QueryActionCancelEvent, BTL_SERVER_FLOW_QueryFirstTargetBlockEvent, BTL_SERVER_FLOW_QueryMoveBlockedEvent, BTL_SERVER_FLOW_QueryMoveRedirectEvent, BTL_SERVER_FLOW_NotifyMoveBeginEvent, BTL_SERVER_FLOW_NotifyMoveFinishEvent, BTL_SERVER_FLOW_QueryMoveTargetsAllowedEvent, BTL_SERVER_FLOW_QuerySemiInvulnerableHit, func_021C69B8, BTL_SERVER_FLOW_CalcAccuracyRatio, BTL_SERVER_FLOW_CheckOneHitKoHit, BTL_SERVER_FLOW_QueryTypeImmunityEvent, BTL_SERVER_FLOW_NotifyTypeImmunityEvent, BTL_SERVER_FLOW_CheckCriticalHit, BTL_SERVER_FLOW_CalcMoveDrainRecoil, BTL_SERVER_FLOW_DispatchPostMoveEvent, BTL_SERVER_FLOW_DispatchPostMoveKindEvent, BTL_SERVER_FLOW_CalcTypeEffectiveness, BTL_SERVER_FLOW_IsPokeGrounded, BTL_SERVER_FLOW_QueryPokeGroundedEvent, BTL_SERVER_FLOW_ProcImmunityOverrideNotice, BTL_SERVER_FLOW_NotifyImmunityOverrideEvent, BTL_SERVER_FLOW_CalcSingleTypeAffinity, BTL_SERVER_FLOW_PushEffectAnim, BTL_SERVER_FLOW_QueryEffectBlockedEvent, BTL_SERVER_FLOW_CalcMultiHitCount, BTL_SERVER_FLOW_CalcMovePower, BTL_SERVER_FLOW_QueryTargetableEvent, func_021C7374, func_021C7474, func_021C75EC, func_021C7664, func_021C76F4, func_021C7780, func_021C77B0, func_021C7820, func_021C785C, func_021C78A8, func_021C78F4, func_021C7998, func_021C79E0, func_021C7A54, func_021C7AA0, func_021C7AD0, func_021C7B0C, func_021C7B3C, func_021C7B7C, func_021C7BA8, func_021C7BF8, func_021C7C18, func_021C7C24, func_021C7CBC, func_021C7CC8, func_021C7CD4, func_021C7CDC, func_021C7CE8, func_021C7CF4, func_021C7D00, func_021C7D34, func_021C7D44, func_021C7D54, func_021C7DAC, func_021C7E14, func_021C7EC4, func_021C7ED8, func_021C7EEC, func_021C7F04, func_021C7F24, func_021C7F4C, func_021C7F68, func_021C7FCC, func_021C7FE0, func_021C8010, func_021C8020, func_021C8030, func_021C804C, func_021C80AC, func_021C8114, func_021C8120, func_021C812C, func_021C8130, func_021C8138, func_021C8140, func_021C814C, func_021C815C, func_021C8168, func_021C8174, func_021C8180, func_021C818C, func_021C81C8, func_021C81D0, func_021C8234, func_021C824C, func_021C8288, func_021C8290, func_021C82B8, func_021C82C4, func_021C82D0, func_021C82F4, func_021C8300, func_021C830C, func_021C831C, func_021C8338, func_021C8348, func_021C8374, func_021C83A0, func_021C83CC, func_021C83D4, func_021C83DC, func_021C83E8, func_021C8408, func_021C8434, func_021C846C, func_021C8494, func_021C84AC, func_021C84D0, func_021C84D8, func_021C84E0, func_021C84E8, func_021C84F4, func_021C8534, func_021C8588, func_021C859C, func_021C85B8, func_021C85D4, func_021C8810, func_021C8828, func_021C8838, func_021C8860, func_021C888C, func_021C88A4, func_021C88B4, func_021C88C8, func_021C88E4, func_021C8910, func_021C8918, func_021C8C6C, func_021C8CBC, func_021C8D0C, func_021C8D2C, func_021C8DE4, func_021C8E58, func_021C8F24, func_021C8FA4, func_021C9010, func_021C9068, func_021C9178, func_021C9250, func_021C9394, func_021C9448, func_021C947C, func_021C94C8, func_021C95D0, func_021C962C, func_021C96D4, func_021C9728, func_021C9750, func_021C9778, func_021C97A4, func_021C97D0, func_021C9828, func_021C9898, func_021C98C4, func_021C98E4, func_021C99A0, func_021C9A24, func_021C9A60, func_021C9BB8, func_021C9CC0, func_021C9DCC, func_021C9DE8, func_021C9E3C, func_021C9ECC, func_021C9F0C, func_021C9F4C, func_021C9F6C, func_021CA128, func_021CA158, func_021CA1D0, func_021CA248, func_021CA270, func_021CA2E8, func_021CA318, func_021CA370, func_021CA394, func_021CA3AC, func_021CA3D0, func_021CA47C, func_021CA570, func_021CA5CC, func_021CA6C4, func_021CA6FC, func_021CA738, func_021CA748, func_021CA7C4, func_021CA7D4, func_021CA7F4, func_021CA8F8, func_021CAA24, func_021CAA58, func_021CACF4, func_021CAFD8, func_021CB174, func_021CB1A4, func_021CB1D4, func_021CB214, func_021CB274, func_021CB2D4, func_021CB55C, func_021CB5F0, func_021CB730, func_021CBA40, func_021CBB34, func_021CBCF4, func_021CBD48, func_021CBEA8, func_021CBF30, func_021CBF40, func_021CBF50, func_021CBF60, func_021CBF70, func_021CBF80, func_021CBF90, func_021CBFA0, func_021CC008, func_021CC098, func_021CC0A8, func_021CC0B8, func_021CC0C8, func_021CC0D8, func_021CC0E8, func_021CC0F8, func_021CC178, func_021CC214, func_021CC2C0, func_021CC350, func_021CC398, func_021CC438, func_021CC4AC, func_021CC508, func_021CC558, func_021CC5F4, func_021CC668, func_021CC768, func_021CC800, func_021CC8A0, func_021CC8B0, func_021CC8B8, func_021CC8C0, func_021CC8C8, func_021CC8D8, func_021CC918, func_021CC95C, func_021CC960, func_021CC96C, func_021CC974, func_021CC99C, func_021CC9A4, func_021CC9AC, func_021CCA74
 * address:  0x021BB968
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from btl_server.c (lane L189): __FILE__ anchor 021BB9C4 (d_021F3A70 "btl_server_flow.c") used by the 0x212c-byte ServerFlow constructor 021BB968, which is the first function of the file.
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
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   BTL_POKEPARAM_Create 0x021D4D84 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_SetFakeMon 0x021D5848 thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   func_02017E1C 0x02017E1C thumb
 *   POKE_TOOL_Create 0x020173F0 thumb
 *   POKEPARTY_Init 0x0201A948 thumb
 *   BTL_POKEPARAM_WriteBackToParam 0x021D6B84 thumb ov093
 *   func_0201A98C 0x0201A98C thumb
 *   func_0201AC2C 0x0201AC2C thumb
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
 *   func_0201A920 0x0201A920 thumb
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
 *   func_020362DC  0x020362DC  arm
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
 *   d_021F3A70 0x021F3A70 data a4
 *   BTL_EVENT_InitFactorList 0x021D6EAC thumb ov093
 *   BTL_FIELD_ResetStatic 0x021EF874 thumb ov093
 *   func_0689CFF0 0x0689CFF0 thumb ov095
 *   func_0689D118 0x0689D118 thumb ov095
 *   func_0689D1FC 0x0689D1FC thumb ov095
 *   func_02082BCC 0x02082BCC arm
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
 *   BTL_CALC_EnableAbilityHandlers  0x021D8548  thumb  ov093
 *   BTL_HANDLER_ITEM_EnablePokeFactors  0x021DCFB4  thumb  ov093
 *   func_0689D338 0x0689D338 thumb ov095
 *   func_021E02DC  0x021E02DC  thumb  ov093
 *   func_021E0394  0x021E0394  thumb  ov093
 *   BTL_ACTION_IsChangeDepleted  0x021D83E0  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   func_0201BD28  0x0201BD28  thumb
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
 *   BTL_CALC_AddAbilityHandlers 0x021D8484 thumb ov093
 *   BTL_HANDLER_ITEM_AddHeldItemFactor 0x021DCF5C thumb ov093
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
 *   func_021E03D8 0x021E03D8 thumb ov093
 *   BTL_EVENT_ResumePokeFactors 0x021D73D4 thumb ov093
 *   d_021EFDB8 0x021EFDB8 data a2
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
 *   sub_0201BD28   0x0201BD28  thumb
 *   BTL_CALC_MulPercent  0x021D7B3C  thumb  ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   BTL_CALC_CalcBaseDamage 0x021D7A44 thumb ov093
 *   BTL_CALC_GetWeatherMoveRatio 0x021D7C38 thumb ov093
 *   BTL_CALC_ApplyTypeAffinity 0x021D7A6C thumb ov093
 *   BTL_POKEPARAM_SetItem  0x021D5B44  thumb  ov093
 *   BTL_HANDLER_ITEM_RemoveUnforcedFactors  0x021DCF24  thumb  ov093
 *   BTL_POKEPARAM_ConsumeHeldItem  0x021D6730  thumb  ov093
 *   WAZA_TOOL_GetSickCont 0x0201BF58 thumb
 *   BTL_CALC_MakeSickContFromSpec 0x021D7C70 thumb ov093
 *   BTL_POKEPARAM_GetTypePair 0x021D57FC thumb ov093
 *   BTLV_CORE_HasByte 0x021E8D24 thumb ov093
 *   func_0689C364 0x0689C364 thumb ov095
 *   BTL_CALC_RemoveAbilityHandlers 0x021D8510 thumb ov093
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
 *   BTL_CALC_SwapAbilityHandlers 0x021D8564 thumb ov093
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
 *   func_021D6064 0x021D6064 thumb ov093
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
 *   BTL_CALC_DisableAbilityHandlers 0x021D8538 thumb ov093
 *   BTL_HANDLER_ITEM_DisablePokeFactors 0x021DCFA4 thumb ov093
 *   func_021E0434 0x021E0434 thumb ov093
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
 *   BTL_HANDLER_ITEM_AddForcedFactor  0x021DCF78  thumb  ov093
 *   BTL_HANDLER_ITEM_RemoveFactor  0x021DCF9C  thumb  ov093
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
 *   g_021EFDC0      0x021EFDC0  data  ov093
 *   func_02019C90   0x02019C90  thumb arm9
 *   POKE_TOOL_DecodePartyParam   0x02017D30  thumb arm9
 *   POKE_TOOL_EncodePartyParam   0x02017D70  thumb arm9
 *   data_021EFDE4 0x021EFDE4 data a4
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
 *   d_021EFE9C     0x021EFE9C  data  a4
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
 *   d_021EFFEC 0x021EFFEC data a4
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
 *   d_021EFF78 0x021EFF78 data ov093 a2
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
 *   d_021EFFC2 0x021EFFC2 data ov093 a2
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
 *   d_021F00DC 0x021F00DC data a4
 *   func_021EA458  0x021EA458  thumb  ov093
 *   func_021EA478  0x021EA478  thumb  ov093
 *   func_021EA488 0x021EA488 thumb ov093
 *   func_021EA4C4 0x021EA4C4 thumb ov093
 *   func_021EA678  0x021EA678  thumb  ov093
 *   func_020061E4  0x020061E4  thumb
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
 *   d_021EFFAE     0x021EFFAE  data   ov093  a2
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
 *   d_021EFF88     0x021EFF88  data  ov093  a2
 *   func_021F8204 0x021F8204 thumb ov094
 *   func_021F8134 0x021F8134 thumb ov094
 *   func_021F8180 0x021F8180 thumb ov094
 *   BTL_EVENT_ReleaseClientHandle 0x021D6EA0 thumb ov093
 *   BTL_POKEPARAM_ReloadFromParam 0x021D6BFC thumb ov093
 *   func_021F8150 0x021F8150 thumb ov094
 *   func_02006238 0x02006238 thumb
 *   func_021EA3B8 0x021EA3B8 thumb ov093
 *   func_021EA3D4 0x021EA3D4 thumb ov093
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   func_02005F38 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   func_021EADA4 0x021EADA4 thumb ov093
 *   func_021EADB4 0x021EADB4 thumb ov093
 *   func_021EADC4 0x021EADC4 thumb ov093
 *   func_021EADD4 0x021EADD4 thumb ov093
 *   func_021EADE4 0x021EADE4 thumb ov093
 *   func_021EADF4 0x021EADF4 thumb ov093
 *   d_021F3B64 0x021F3B64 data a4
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   func_020181F4   0x020181F4  thumb
 *   POKE_TOOL_GetLevelUpMove   0x02018328  thumb
 *   func_021EA638   0x021EA638  thumb ov093
 *   func_021EAC64   0x021EAC64  thumb ov093
 *   func_021EAC80   0x021EAC80  thumb ov093
 *   g_021F3B64      0x021F3B64  data
 *   func_021F7CFC 0x021F7CFC thumb ov094
 *   func_021F883C 0x021F883C thumb ov094
 *   d_021EFF80 0x021EFF80 data a2
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
 *   func_021B8CB0  0x021B8CB0  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021B8DEC  0x021B8DEC  thumb  ov093
 *   func_021B8E28  0x021B8E28  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021B9010  0x021B9010  thumb  ov093
 *   func_021B902C  0x021B902C  thumb  ov093
 *   func_021B9064  0x021B9064  thumb  ov093
 *   func_021B9090  0x021B9090  thumb  ov093
 *   func_021B911C  0x021B911C  thumb  ov093
 *   func_021B92B0  0x021B92B0  thumb  ov093
 *   func_021B937C  0x021B937C  thumb  ov093
 *   func_021B98A4  0x021B98A4  thumb  ov093
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021B990C  0x021B990C  thumb  ov093
 *   func_021B9920  0x021B9920  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021B9940  0x021B9940  thumb  ov093
 *   func_021B997C  0x021B997C  thumb  ov093
 *   func_021B99B8  0x021B99B8  thumb  ov093
 *   func_021B99C0  0x021B99C0  thumb  ov093
 *   func_021B99E0  0x021B99E0  thumb  ov093
 *   func_021B99F0  0x021B99F0  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021B9A6C  0x021B9A6C  thumb  ov093
 *   func_021B9AB0  0x021B9AB0  thumb  ov093
 *   func_021B9AE0  0x021B9AE0  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B9B98  0x021B9B98  thumb  ov093
 *   func_021B9BC4  0x021B9BC4  thumb  ov093
 *   func_021B9BF0  0x021B9BF0  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021B9C10  0x021B9C10  thumb  ov093
 *   func_021B9C50  0x021B9C50  thumb  ov093
 *   func_021B9C98  0x021B9C98  thumb  ov093
 *   func_021B9CE8  0x021B9CE8  thumb  ov093
 *   func_021B9D10  0x021B9D10  thumb  ov093
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 *   func_021BA1B4  0x021BA1B4  thumb  ov093
 *   func_021BA1CC  0x021BA1CC  thumb  ov093
 *   func_021BA250  0x021BA250  thumb  ov093
 *   func_021BA534  0x021BA534  thumb  ov093
 *   BTL_SERVER_GetClientChecked  0x021BB85C  thumb  ov093
 *   BTL_SERVER_GetClientIfUsed  0x021BB878  thumb  ov093
 *   BTL_SERVER_IsClientUsed  0x021BB890  thumb  ov093
 *   BTL_SERVER_GetActionTableValue  0x021BB8A8  thumb  ov093
 *   BTL_SERVER_GetActionTableEntry  0x021BB8B0  thumb  ov093
 *   BTL_SERVER_AddMainCounter  0x021BB908  thumb  ov093
 *   BTL_SERVER_FinishMainCounter  0x021BB914  thumb  ov093
 *   BTL_SERVER_ClearPokeChangeRequests  0x021BB920  thumb  ov093
 *   BTL_SERVER_AddPokeChangeRequest  0x021BB930  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_SERVER_CMD_Reserve  0x021CD4FC  thumb  ov093
 *   BTL_SERVER_CMD_FillReserved  0x021CD568  thumb  ov093
 *   BTL_SERVER_CMD_WriteU8Wrapper  0x021CD63C  thumb  ov093
 *   BTL_SERVER_CMD_PushVariable  0x021CD64C  thumb  ov093
 */
#include "../../matched/include/Obj21039.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj09958.h"
#include "btl_server_types.h"
#include "btl_server_flow_types.h"
#include "../../matched/include/Obj13305.h"
#include "../../matched/include/Obj13306.h"
#include "../../matched/include/Obj09961.h"
#include "../../matched/include/Obj13311.h"
#include "../../matched/include/Obj21056.h"
#include "../../matched/include/Obj04358.h"
#include "../../matched/include/Obj13317.h"
#include "../../matched/include/Obj05190.h"
#include "../../matched/include/Obj21063.h"
#include "../../matched/include/Obj21074.h"
#include "../../matched/include/Obj02778.h"
#include "../../matched/include/Obj09968.h"
#include "../../matched/include/Obj13323.h"
#include "../../matched/include/Obj13324.h"
#include "../../matched/include/Obj13325.h"
#include "../../matched/include/Obj21079.h"
#include "../../matched/include/Obj09967.h"
#include "../../matched/include/Obj09971.h"
#include "../../matched/include/Obj07754.h"
#include "../../matched/include/Obj21097.h"
#include "../../matched/include/Obj07759.h"
#include "../../matched/include/Obj18319.h"
#include "../../matched/include/Obj18320.h"
#include "../../matched/include/Obj18322.h"
#include "../../matched/include/Obj18323.h"
#include "../../matched/include/Obj18325.h"
#include "../../matched/include/Obj21110.h"
#include "../../matched/include/Obj21111.h"
#include "../../matched/include/Obj13340.h"
#include "../../matched/include/Obj18333.h"
#include "../../matched/include/Obj26329.h"
#include "../../matched/include/Obj26330.h"
#include "../../matched/include/Obj18335.h"
#include "../../matched/include/Obj18336.h"
#include "../../matched/include/Obj18337.h"
#include "../../matched/include/Obj13341.h"
#include "../../matched/include/Obj21115.h"
#include "../../matched/include/Obj21119.h"
#include "../../matched/include/Obj21120.h"
#include "../../matched/include/Obj13342.h"
#include "../../matched/include/Obj09974.h"
#include "../../matched/include/Obj21121.h"
#include "../../matched/include/Obj18339.h"
#include "../../matched/include/Obj21124.h"
#include "../../matched/include/Obj21125.h"
#include "../../matched/include/Obj05194.h"
#include "../../matched/include/Obj21127.h"
#include "../../matched/include/Obj09977.h"
#include "../../matched/include/Obj13345.h"
#include "../../matched/include/Obj13346.h"
#include "../../matched/include/Obj06229.h"
#include "../../matched/include/Obj09981.h"
#include "../../matched/include/Obj05195.h"
#include "../../matched/include/Obj09983.h"
#include "../../matched/include/Obj06230.h"
#include "../../matched/include/Obj13347.h"
#include "../../matched/include/Obj05196.h"
#include "../../matched/include/Obj09984.h"
#include "../../matched/include/Obj21130.h"
#include "../../matched/include/Obj18356.h"
#include "../../matched/include/G_StateData.h"

#define ENTRY(i) (&e[i])
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))
struct Unk021B8CB0;
struct Blk34;
struct Work;
struct R4;
struct S2;
struct Q1;
struct QF;
struct QH;
struct S_021B8CB0;
struct Party;
struct PartyMon;
struct Rec534;
struct R3;
struct PerapVoice;
struct Sub0200852CObj;
struct U16Vec;
struct Rec8;
struct Buf;
struct Sub02008C20Obj;
struct Unk021D62A8;
struct Flags;
struct T;
struct QA;
struct Scene;
struct Q5;
struct Q7;
struct Q6;
struct Q4;
struct QW;
struct UtilWork;
struct Unk021BDE48;
struct Unk021D82FC;
struct B;
struct Arr;
struct Msg;
struct O;
struct Out64B4;
struct Unk021BD1E0;
struct Unk021BE518;
struct Unk021D82D0;
struct UtilSlots;
struct Q;
struct QL;
struct QI;
struct S_p12;
struct Q_021C0CB4;
struct Q_021C0CE8;
struct QK;
struct S_021C2E4C;
struct QJ;
struct Entry_p11;
struct Obj;
struct Result;
struct Unk021D5FA4;
struct Pack;
struct Rec;
struct Q9;
struct Cmd;
struct Q10;
struct S_p14;
struct Unk021D6C50;
struct Unk021D6C2C;
struct R5;
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

typedef struct {
    u8 pad[0x473];
    u8 a : 1;
    u8 b : 1;
    u8 c : 1;
    u8 d : 1;
    u8 e : 1;
    u8 f : 1;
    u8 g : 1;
} B_td;

typedef struct { u8 lo:6; u8 flag:1; u8 hi:1; } Flags_021B9210;

typedef unsigned long long u64;

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

struct F {
    u8 b : 1;
};

/* 021BA5D0  movs r1,#0x11; lsls r1,#6; ldrh r0,[r0,r1] */
struct Q3 { u8 pad[0x440]; u16 v; };

struct T {
    int w[6];
};

typedef struct { unsigned int a, b; } Pair_td;

typedef struct {
    u32 pad : 7;
    u32 f : 3;
} B_021B9EF0_td;

typedef struct { u32 h; u32 x[2]; } EntP;

typedef struct { u32 w; } W;

typedef struct { W v[3]; } D;

typedef struct {
    u8 pad0[0x14];
    EntP e[4];
    u8 pad1[0x70];
    D d[4];
    u8 c[4];
} P;

/* 021BB840  strb r1,[r0,#0xb]; str r2,[r0]; strb r3,[r0,#0xa] */
struct Q4 { u32 w; u8 pad[6]; u8 c; u8 b; };

/* 021BB964  ldr r0,[r0,#0x44] */
struct Q5 { u8 pad[0x44]; u32 v; };

typedef struct { u8 a:1; u8 b:1; u8 c:1; u8 pad:3; u8 d:1; u8 rest:1; } Flags_td;

typedef struct { u32 a; u32 kind : 4; u32 x : 3; u32 y : 3; u32 z : 1; u32 pad : 21; u32 c; u8 d, f; unsigned short pad2; } E_021BBCD4;

typedef struct {
    u8 *f0; void *f4; u8 pad8[4]; int *fC; u8 pad10[4]; u32 f14;
    u8 pad18[0x3e0 - 0x18]; u8 g3e0[0xee]; u8 g4ce[0x77c - 0x4ce];
    u8 init; u8 pad77d[5]; u8 n; u8 k; u8 pad784[0x5c]; E_021BBCD4 e[6];
} S_021B8CB0_td;

typedef struct { u32 a:4; u32 b:3; u32 action:16; u32 rest:9; } EntBits;

typedef struct { u8 *a; EntBits b; u32 c; u8 d, f; unsigned short pad; } E;

typedef struct { u8 pad[0x14]; u32 state; u8 pad2[0x76a]; u8 n; u8 pad3[0x5d]; E e[6]; } S_021BBFA8;

typedef struct { u8 *a; EntBits b; u32 c; u8 d,f; u16 pad; } E2;

/* Same layout as Entry. Reading e[l].b through this second type keeps mwcc from reusing r->b; the bytes need that reload. */
typedef struct { u8 *a; Action b; u32 c; u8 d; u8 done; u8 f; u8 pad; } EntryAlt;

typedef struct { u32 x; void *m; } Q_td;

struct Unk021BD200 {
    u16 f0;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
};

struct Cursor { u8 a, b, c, d; };

enum Offset { queue = 0x1a68 };

struct Fl { u8 f : 1; };

struct Out_021BDB88 { u8 c0; u8 pad; u16 c2; u8 c4; };

struct Cell { u32 w[5]; };

struct Out_021BE3A8 { u8 pad[16]; u32 flag : 1; u32 rest : 31; };

struct Unk021BE518 { u8 f0; u8 f1[6]; };

struct Lock_021BDB88 { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };

struct State { u16 f0; u8 f2, f3, f4; u8 a:1, b:1, rest:6; };

struct Bits78A { u8 low:4, skip:1, rest:3; };

struct Buf { u32 wpos, rpos; };

struct S { u32 id[6]; u16 a[6], b[6]; u8 c[6]; u16 d[6]; u8 n, max, f44, f45; };

struct Rec { u32 value; u16 kind; u8 data, flag; };

struct O { u32 pos; struct Rec r[120]; };

struct O_p11 { u16 h; u8 b; };

struct Lock_021BF244 { u32 a:10, b:9, c:9, d:1, e:1, f:1, g:1; };

struct Bf { u8 pad[0x10]; u32 f : 1; };

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

struct St { u8 pad[5]; u8 f : 1; };

struct Rec_p09 { u16 a; u16 b; u8 c; u8 d; u8 e; };

typedef struct { u32 a:10,b:9,c:9,d:1,e:1,f:1,g:1; } Lock_td;

typedef struct { u8 pad[5]; u8 f:1; } BF_021C1184;

typedef struct { u8 pad[0x78a]; u8 low:4; u8 f:1; } State_td;

typedef struct { u8 pad[5]; u8 f : 1; } BF_021C2AB0;

typedef struct { u32 x; } W_021C2E4C;

typedef struct { u8 pad[5]; u8 f : 1; } BF;

struct Flags_021C2E4C { u8 pad[5]; u8 a:1; u8 rest:7; };

typedef struct { u8 pad[5]; u8 f : 1; } Q_p10;

enum Mode { M0, M1, M2, Mneg = -1 };

struct Pair { u8 count, id; };

typedef struct { u8 pad[5]; u8 a:1,b:1,c:6; } Flag_td;

typedef struct { u8 a:4,b:1,c:3; } ByteFlag;

struct Flags_021C5108 { u8 a:1; u8 b:1; u8 rest:6; };

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

typedef struct { u32 value; u8 flag; u8 pad[7]; } Rec_021CAA58;

struct Flag { u8 pad[0x78a]; u8 low:3; u8 set:1; u8 high:4; };

typedef struct { u32 lo : 4; u32 hi : 28; } W_p12;

typedef union { u32 u; W_p12 w; } U;

typedef struct { u8 *a; U b; u32 c; u32 d; } E_p12;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E_p12 e[4]; } S_td;

/* 021C8138  ldr r0,[r0,#0x10]; lsls r0,#0x10; lsrs r0,#0x10 */
struct Q7 { u8 pad[0x10]; u32 v; };

typedef struct { u32 f0; u8 pad[60]; } E64;

typedef short s16_021C82F4;

typedef int s32_021C82F4;

struct Bits { unsigned char a:1; unsigned char rest:7; };

typedef signed short s16_021C83CC;

typedef signed int s32_021C83CC;

struct Flags_021C7D34 { u8 low:5; u8 flag:1; u8 high:2; };

struct Flags_021C8588 { u8 low : 3; u8 a : 1; u8 b : 1; u8 high : 3; };

struct Packed021C8810 { u16 low : 8; u16 high : 8; };

struct S_p12 {
    u16 x;
    u16 y : 8;
    u16 n : 7;
    u16 z : 1;
    u32 arr[8];
};

struct Packed021C888C { u16 low : 8; u16 index : 7; u16 active : 1; };

typedef struct {
    u32 id : 8;
    u32 client : 5;
    u32 unk13 : 11;
    u32 ignoreIfBusy : 1;
    u32 checkFainted : 1;
    u32 unk26 : 6;
} BtlCmd;

typedef struct {
    u8 unk0[8];
    void *party;        /* 0x0008 */
    u8 unk0C[0x1D68];
    u8 queue[4];        /* 0x1D74 */
} BattleCtx;

typedef struct { u32 pad : 8; u32 idx : 5; u32 rest : 19; } Ent;

typedef struct { u32 pad : 8; u32 idx : 5; u32 rest : 19; } Ent_021C8CBC;

typedef struct { u32 pad : 8; u32 idx : 5; u32 rest : 19; } Ent_021C8D0C;

typedef struct {
    u32 w; u16 h4; u8 b6; u8 b7; u16 h8; u16 ha;
} Ent_021C8DE4;

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 mid : 10; u32 fl : 1; u32 top : 8;
    u16 h4; u8 b6; u8 f7a : 1; u8 f7b : 1; u8 f7c : 6; u16 h8; u8 ba; u8 bb;
} Ent_021C8E58;

typedef struct {
    u32 w; u8 n; u8 b5; u8 b6; u8 ids[9]; u32 v[4];
} Ent_021C8F24;

typedef struct { int pad0; int pad1; char *f8; } P_021C8CBC;

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 rest : 19;
    u8 b4; u8 b5; u8 b6; u8 f7a : 1; u8 f7b : 1; u8 f7c : 6;
} Ent_021C8FA4;

typedef struct {
    u32 w; u8 b4; u8 b5; u8 b6; u8 f7a : 1; u8 f7b : 1; u8 f7c : 6;
} Ent_021C9010;

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

typedef struct {
    u32 w; u8 b[8];
} Ent_021C9394;

typedef struct { int pad0; int pad1; char *f8; void *fc; } P_021C9178;

typedef struct { u32 w; u8 n; u8 ids[1]; } Ent_021C9448;

typedef struct { u32 w; u16 values[5]; u8 id; u8 f0:1,f1:1,f2:1,f3:1,f4:1,pad:3; u8 msg[36]; } Ent_021C94C8;

typedef struct { u32 w; u8 b4; u8 b5; } Ent_021C95D0;

typedef struct { u32 w; u16 h4; u8 b6; u8 b7; } Ent_021C962C;

struct Cmd_021C96D4 {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 10;
    u32 flag : 1;
};

struct Cmd_021C97D0 {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 w4;
    u32 w8;
    u8 b12;
};

struct Cmd_021C98E4 {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 3;
    u32 pad2 : 7;
    u32 flag : 1;
    u32 pad3 : 8;
    u8 b4;
    u8 b5;
    u8 b6;
};

struct Cmd_021C9A24 { u32 a:8; u32 id:5; u32 pad:19; u32 w4; u8 b8; u8 pad9[3]; u8 data[16]; u8 b28; };

typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; u16 value; u8 id,a; u8 pad8[4]; u8 msg[36]; } Ent_021C9A60;

typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; u16 value; u8 id,a,b,c; u8 padA[2]; u8 msg[36]; } Ent_021C9BB8;

typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; u8 id,pad5[3]; u8 msg[108]; } Ent_021C9CC0;

struct Cmd_021C9DE8 {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 f0 : 1;
    u32 f1 : 1;
};

struct Cmd_021C9E3C {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u8 b4;
    u8 b5;
    u16 h6;
};

struct Cmd_021C9ECC {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 w4;
};

struct Cmd_021C9F0C {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u16 h8;
};

struct Out { u16 h0,h2,h4; u8 b6,pad7; u32 w8,wc,w10; };

struct State_p13 { u16 h0; u8 b2,b3,b4; u8 flag:1; u8 rest:7; };

struct Bits_p13 { u32 low : 8; u32 index : 5; u32 high : 19; };

struct Cmd_021CA158 {
    u8 pad[0x4C];
    u8 b4c;
    u8 b4d;
};

struct Cmd_021CA1D0 {
    u32 pad;
    u8 b4;
    u8 b5;
};

struct Cmd_021CA248 {
    u32 pad;
    u8 b4;
    u8 b5;
    u16 h6;
};

struct Q_021C95D0 {
    u32 a : 8;
    u32 b : 5;
    u32 c : 19;
    u16 e;
    u8 f;
    u8 lo : 4;
    u8 hi : 4;
};

struct Cmd_021CA2E8 { u32 a:8; u32 id:5; u32 b:10; u32 flag:1; u32 c:8; u8 target; };

struct Cmd { u32 a:8; u32 id:5; u32 b:19; };

struct Q_021CA5CC {
    u32 lo : 23;
    u32 f : 1;
    u32 hi : 8;
    u8 pad4[0];
};

typedef struct {
    u8 unk0[0x4A8];
    u8 *state;          /* 0x4A8 */
} BattleCtx_021CA7C4;

typedef struct {
    u8 unk0[5];
    u8 flag : 1;
    u8 unk5 : 7;
} BattleState;

typedef struct {
    u8 unk0[0x4A8];
    BattleState *state; /* 0x4A8 */
} BattleCtx_021CA7D4;

struct Flags { u32 a:1; u32 b:31; };

struct Record { u16 n0, n1; u8 ids[6]; };

struct T6 { u8 f0; u8 f1; u16 f2; u16 f4; };

typedef enum
{
  COND_ZERO,
  COND_ONE,
  COND_TWO
} Condition;

typedef int (*Callback_021CAA58)(BtlServerFlow *, u8 *, u16, u32, u32);

typedef struct
{
  u16 id;
  u8 mode;
  u8 exact;
  Callback_021CAA58 call;
} Entry_021CAA58;

typedef signed long long s64;

typedef struct Word_021CAA58 { u32 v; } Word_021CAA58_td;

typedef struct Rec_021CC008 {
    int f00;
    u32 f04;
    u8 f08;
    u8 pad[11];
    u8 f14;
} Rec_021CC008_td;

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

struct Rec_p14 {
    u32 id : 8;
    u32 b : 5;
    u32 size : 10;
    u32 x : 1;
    u32 pad : 2;
    u32 y : 1;
    u32 rest : 5;
};

struct Pack {
    u32 lo : 10;
    u32 off : 9;
    u32 rest : 13;
    u8 data[500];
};

typedef struct {
    u32 unk0;
    u32 pos;
} ByteStream;

typedef char *va_list;

typedef struct { u8 f0:1,f1:1,f2:1,f3:1,f4:1,f5:1,rest:2; } Flags_021CC768;

/* 021CD95C  str r1,[r0,#0x54] */
struct QA { u8 pad[0x54]; u32 v; };

/* 021CD978  ldr r0,[r0,#0x50] */
struct QB { u8 pad[0x50]; u32 v; };

/* 021CD97C  push {r3,lr}; ldr r1,[r0,#0x28]; blx r1; pop {r3,pc} */
struct R2 { u8 pad[0x28]; void (*fn)(struct R2 *); };

/* 021CD9DC  ldrh r0,[r0,#0x22] */
struct QD { u8 pad[0x22]; u16 v; };

/* 021CDA0C  str r1,[r0,#0x28]; movs r1,#0x6a; movs r2,#0; lsls r1,#2;
 *           strb r2,[r0,r1] */
struct QE { u8 pad[0x28]; u32 v; u8 rest[0x1a8 - 0x2c]; u8 z; };

typedef int (*Callback_021CC768)(u8 *,int *);

typedef struct { u8 f0:1,f1:1,f2:1,f3:1,f4:1,f5:1,rest:2; } Flags_021CDA18;

typedef struct { u8 id; u8 flag; u16 pad; Callback_021CC768 callbacks[3]; } Entry_021CC768;

typedef struct {
    int a;
    int b;
} S_p14_td;

struct Flags_021CDDA0 { u8 pad[0x1b2]; u8 low:4; u8 flag:1; u8 high:3; };

struct Flags_021CDDCC { u8 pad[0x1b2]; u8 low:5; u8 flag:1; u8 high:2; };

typedef struct { u8 a : 5; u8 flag : 1; } Flags_021CE1B0;

typedef struct { u32 kind : 4; u32 rest : 28; } Command;

typedef struct { u8 a : 2; u8 f : 1; } Flags_021CE308;

struct L { u8 pad[0x11D]; u8 idx; u8 pad2[0x1A6-0x11E]; u8 sel; };

typedef struct { u8 flag : 1; u8 rest : 7; } Flags_021CE7D4;

typedef enum { OFFSET = 0x19a } Off;

struct Offsets { Off skip,ok0,ok1,ok2,ok3,invalid; };

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

struct G_021CFE08 {
    void *p0;
    u8 pad0[0xf0];
    u64 seed;
    u64 mul;
    u64 add;
};

struct G_021CFE98 { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };

struct G_021CFFAC { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };

struct G_021D0100 { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };

struct Row { u8 kind; u8 pad; u16 ids[4]; };

struct G_021D0248 {
    u8 pad0[0xf4];
    u64 seed;
    u64 mul;
    u64 add;
};

struct G_021D0304 { void *p0; u8 pad[0xf0]; u64 seed; u64 mul; u64 add; u8 pad2[0xc]; void *list; u8 start; };

struct G {
    u8 pad0[0xf4];
    u64 seed;
    u64 mul;
    u64 add;
    u8 pad1[0xc];
    void *list;
};

typedef struct {
    void *battle;         /* 0x00 */
    u8 unk04[0x50];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq_021D0B6C;

typedef struct { u8 pad[0x1B3]; volatile u8 count; } CountField;

typedef struct { u8 pad[0x1B2]; unsigned char f0:5; unsigned char flag:1; unsigned char f6:2; } Flags_p15;

typedef struct {
    void *battle;         /* 0x00 */
    void *unk04;          /* 0x04 */
    u8 unk08[0x4C];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq_021D123C;

typedef struct { u8 pad[0x1B2]; unsigned char f0:5; unsigned char flag:1; unsigned char f6:2; } Flags_021D1410;

typedef struct { u8 pad[0x1B2]; unsigned char f0:3; unsigned char flag:1; unsigned char f4:4; } Flags_021D1A60;

typedef int (*Callback)(u8 *, int *, int *);

typedef struct { int code; Callback fn; } CodeEntry;

typedef struct {
    u8 unk00[0x54];
    void *win;            /* 0x54 */
} Seq_021D123C;

typedef struct {
    u32 unk00;
    void *unk04;
    u8 unk08[0x4C];
    void *win;
} Seq_021D2030;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq_021D20BC;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq_021D210C;

typedef struct {
    u8 unk00[0x54];
    void *win;            /* 0x54 */
    u8 unk58[0x134 - 0x58];
    u32 unk134;
} Seq_021D215C;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq_021D21D4;

typedef struct {
    u32 unk00;
    u32 unk04;
} Seq_021D2234;

typedef struct { u16 a; u16 b; } Pair16;

typedef struct { u8 data[0x24]; } MsgParam;

typedef struct {
    void *battle;
    void *party;
    u8 unk008[0x4c];
    void *msgWin;
    MsgParam msg;
    u8 unk07C[0x11e];
    u16 level;
    u8 unk19C[0xa];
    u8 side;
} LearnSeq_021D123C;

struct StateDataL { u8 pad0[8]; int counter; u32 remaining; u32 pad10; u8 result[14]; };

typedef struct {
    void *battle;       /* 0x000 */
    void *party;        /* 0x004 */
    u8 unk008[0x4C];
    void *msgWin;       /* 0x054 */
    MsgParam msg;       /* 0x058 */
    u8 unk07C[0x11E];
    u16 level;          /* 0x19A */
    u8 unk19C[0xA];
    u8 side;            /* 0x1A6 */
} LearnSeq_021D2C7C;

union DView { struct StateDataL s; u32 w[9]; };

extern u8 BTL_MAIN_DecodeMessageCode(struct Unk021B8CB0 **p, int k, u8 *out);
extern int BTL_POKEPARAM_IsFainted(void *m);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 BTL_MAIN_GetClientTrainerIndex(u8 *p, u32 k, u8 n);
extern void *BTL_MAIN_GetCompetitor(void ***p);
extern int BTL_MAIN_IsClientUsed(u8 *p, u8 k);
extern u32 GPOWER_ApplyPrizeMoney(u32 v);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern char *BTL_MAIN_GetFieldSituation(char **p);
extern void NATSUKI_Calc(void *a0, int a1, int a2, int a3);
extern int BTL_POKEPARAM_IsIllusionActive(struct R4 *p);
extern int func_021D59B4(u8 *p, int k);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void POKEPARTY_Init(struct Party *p);
extern u32 BTL_MAIN_GetRule(void **p);
extern int BTL_POKEPARAM_IsAbleToBattle(void *);
extern u32 func_020307B0(void *p);
extern void PMSI_PARAM_ClearSentence(void *a);
extern void PMSI_PARAM_Copy(struct Rec8 *dst, const struct Rec8 *src);
extern void STRBUF_SetChars(struct Buf *buf, const void *src, u32 n);
char *COMM_PLAYER_SUPPORT_GetCurrent(char *p);
int BTL_SETUP_CheckStatusFlag(char *base, int m);
extern u32 sub_02008DF0(struct Sub02008C20Obj *, int);
extern u32 sub_02008DAC(struct Sub02008C20Obj *, int, u32);
extern void NATSUKI_CalcUseItem(void *, int, u16, u16);
extern void NATSUKI_CalcParty(void *a0, int a1, int a2);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 func_021D805C(void *p, u32 n);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern u32 _u32_div_f(u32, u32);
extern void *func_02030734(u16, unsigned int, int, const char *, u16);
extern u8 BTL_MAIN_GetCommPos(u8 **p);
extern u32 BTL_CALC_ActionGetKind(Action *);
extern u16 BTL_MAIN_GetWinBgm(void **);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void GAME_BEACON_SetPokeLevelUp(u32);
extern void GAME_BEACON_SetPokeCapture(u16);
extern void *SHINKA_CHECK_OpenHandle(u16 heap);
extern void BTL_EVENT_InitFactorList(void);
extern int BTL_FIELD_ResetStatic(int a);
extern void func_0689CFF0(void *);
extern void func_0689D118(void *);
extern void func_0689D1FC(void *, void *, void *, u32);
extern void func_02082BCC(void *, int, u32);
extern void BTL_CLIENT_SET_Clear(u8 *p);
extern void func_06898BFC(void *);
extern void ARC_TOOL_DeleteHandle(u32);
extern void BTL_MAIN_RegisterZukanSeen(char *p, unsigned char k, void *m);
extern void func_0689D134(u8 *);
extern void BTL_EVENT_ClearSuspendedFlags(void);
extern void BTL_EVENT_ResetVarStackIfUsed(void);
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern int func_0689D174(void *, int);
extern unsigned char BTL_MAIN_GetClientSide(int unused, unsigned int b);
extern u8 func_0689D558(u8 *, u8, u8 *);
extern int BTL_FIELD_GetStaticSlotObject(int k);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void BTL_CALC_EnableAbilityHandlers(void *p);
extern void BTL_HANDLER_ITEM_EnablePokeFactors(void *p);
extern void func_0689D338(u8 *, int, int, u8 *, u8 *);
extern int func_021E02DC(u8 *a, u16 key, u32 sub_pri);
extern void func_021E0394(u8 *a, int b);
extern int BTL_ACTION_IsChangeDepleted(Action *p);
extern u32 BTL_CALC_Random(u32 range);
extern u32 func_0201BD28(u32 v, u32 n);
extern void BTL_EVENT_PushVarFrame(int line);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);
extern void BTL_EVENT_SetVarRanged(int key, u32 a, u32 b, u32 c);
extern u32 BTL_CALC_MulRatio(u32 a, u32 b);
extern u32 BTL_ACTION_GetFightMove(Action *m);
extern int func_0689D588(u8 *, u8);
extern int BTL_MAIN_GetCompetitorKind(unsigned int **p);
extern u8 func_021D69AC(u8 *, int);
extern void BTL_POKEPARAM_SetTurnFlag(struct UtilWork *p, u32 n);
extern int func_021B871C(char *);
extern int POKE_TOOL_IsOwnedByPlayer(void *, int);
extern u8 BTL_MAIN_GetBadgeCount(u8 **p);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern u8 func_0689D5C8(u8 *, int);
extern void func_021D82FC(Action *p, int sub);
extern int func_0689CD40(void *);
extern u32 func_0689CD38(void *);
extern void *func_0689CC70(void *, u32);
extern void func_0689D4F0(u8 *, int, int);
extern int func_021D58A8(u8 *p, int k);
extern void BTL_CLIENT_SET_Add(struct B *p, int n);
extern void func_0689C68C(BtlServerFlow *, u8 *);
extern void *BTL_CALC_AddAbilityHandlers(void *a);
extern void *BTL_HANDLER_ITEM_AddHeldItemFactor(void *p);
extern void BTL_POKEPARAM_StartTurnThreshold(u8 *p, u16 n);
extern void BTL_POKEPARAM_ReloadAndResetEffects(void *);
extern void func_0689D320(void *, int, u8, void *);
extern void func_0689CB3C(void *);
extern void func_0689CB48(void *, void *);
extern void func_0689CF24(void *, BtlServerFlow *);
extern void func_0689CC84(void *);
extern void *func_0689CC8C(void *);
extern void BTL_EVENT_DispatchEventToType(int a, int b, int c);
extern void BTL_POKEPARAM_ResetEffectsOnSwitchOut(u8 *a);
extern void func_0689D2F8(void *, int);
extern union Slot BTL_POKEPARAM_GetSickContRaw(void *p, int i);
extern u16 BTLV_CORE_GetSlotValue(union Slot v);
extern int BTL_POKEPARAM_GetMovePPById(struct UtilWork *p, int id);
extern u32 BTL_POKEPARAM_GetSemiInvulnerableFlag(struct UtilWork *p);
extern u8 BTL_CALC_DecideMoveTarget(void *p, int a, int m, u16 move);
extern void BTL_ACTION_SetFight(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u8 BTL_POKEPARAM_FindMoveSlot(struct UtilWork *p, u16 id);
extern void func_0689CEE4(void *);
extern void func_0689CD78(void *, void *);
extern void func_0689CD48(void *, int);
extern void func_0689D01C(void *, u16, u32, u32);
extern void BTL_POKEPARAM_RecordMoveUse(u8 *, u8, int, u8, u16, u16);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern int WAZA_TOOL_GetFlag(void *bag, int item);
extern void BTL_EVENT_SuspendPokeFactors(int kind);
extern void func_021E03D8(u8 *a, int b);
extern void BTL_EVENT_ResumePokeFactors(int kind);
extern u32 BTL_EVENT_HasClientReservedChoice(u8 *p);
extern void BTL_EVENT_SetClientReservedChoice(u8 *, u8, u16);
extern u32 WAZA_TOOL_GetCategory(u16);
extern int func_0689CD50(void *);
extern void func_0689D050(struct O *);
extern void func_0689CC14(void *, void *);
extern u32 BTL_POKEPARAM_HasSubstitute(u8 *p);
extern int func_0689D59C(u8 *, int, u32);
extern u16 BTL_POKEPARAM_GetSickParam(struct UtilSlots *p, int i);
extern void BTL_EVENT_MultiplyVar(int, int);
extern unsigned char BTL_CALC_ApplyAccuracyStage(int a, int i);
extern union Slot BTLV_CORE_MakeSlotKind2(int, int);
extern int BTL_POKEPARAM_IsSemiInvulnerable(struct UtilWork *p);
extern union Slot BTLV_CORE_MakeSlotKind3(u32 a);
extern u32 BTL_POKEPARAM_GetMovePPChecked(struct UtilWork *p, u32 i);
extern u16 BTL_POKEPARAM_GetLastSelectedMoveId(u8 *);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct QL *p);
extern u32 WAZA_TOOL_IsDamaging(void *p);
extern int func_021EF91C(void *, u8 *, u16);
extern int BTL_CALC_RollPercent(u32);
extern int BTL_POKEPARAM_TickSlot6Turn(struct UtilSlots *p);
extern int BTL_POKEPARAM_TickSleepTurn(struct UtilSlots *p);
extern union Slot BTL_CALC_MakeDefaultSickCont(int);
extern void func_021D69A0(u8 *base, int idx, u8 val);
extern void BTL_POKEPARAM_DecrementMovePP(struct UtilWork *p, int i, u8 n);
extern void BTL_POKEPARAM_MarkMoveUsed(struct Work *p, int i);
extern void func_0689CDCC(u8 *, u8 *, u8 *);
extern void func_0689CE58(u8 *, u8 *, u8 *);
extern unsigned int BTL_MAIN_CheckSceneOff(unsigned char *p);
extern void func_0689CBB8(void *, void *, u16, int);
extern void BTL_POKEPARAM_AddHitRecord(u8 *c, struct Rec_p09 *r);
extern u32 WAZA_TOOL_GetCategory(u16 move);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int func_0689CCF8(u8 *, u8 *, u32 *);
extern int func_0689CCB4(u8 *, u8 *, u32 *);
extern u32 sub_0201BD28(u16 id, u32 field);
extern u32 BTL_CALC_MulPercent(u32 a, u32 b);
extern int WAZA_TOOL_GetDamageType(int a);
extern u32 BTL_CALC_CalcBaseDamage(u32 a, u32 b, u32 c, u32 d);
extern u32 BTL_CALC_GetWeatherMoveRatio(int a, int b);
extern u32 BTL_CALC_ApplyTypeAffinity(u32, u32);
extern void BTL_POKEPARAM_SetItem(struct QI *p, u16 v);
extern void BTL_HANDLER_ITEM_RemoveUnforcedFactors(u8 *a);
extern void BTL_POKEPARAM_ConsumeHeldItem(struct QK *p, u16 v);
extern W_021C312C WAZA_TOOL_GetSickCont(u16);
extern void BTL_CALC_MakeSickContFromSpec(W_021C312C, u32, union Slot *);
extern u16 BTL_POKEPARAM_GetTypePair(void *);
extern int BTLV_CORE_HasByte(int x, int k);
extern void func_0689C364(int, union Slot, u8 *, struct Msg *);
extern void BTL_CALC_RemoveAbilityHandlers(void *p);
extern void BTL_POKEPARAM_ChangeForm(void *, u8);
extern int BTL_CALC_HasDefaultSickCont(int);
extern int BTL_FIELD_GetCountdownValue(void);
extern void func_021D70E4(void *a, int id);
extern u8 WAZA_TOOL_GetRankEffectCount(u16);
extern u8 WAZA_TOOL_GetRankEffect(u16 id, u32 idx, s32 *out);
extern int func_021D5D14(s8 *p, int i, int sign);
extern int BTL_POKEPARAM_IsHpFull(u8 *p);
extern int BTL_CALC_SummarizeTypeAffinity(int);
extern void BTL_POKEPARAM_ZeroHp(u8 *p);
extern int BTL_POKEPARAM_GetSubstituteHp(u8 *p);
extern void func_0689C7A4(BtlServerFlow *, u8 *);
extern u32 WAZA_TOOL_GetWeather(int id);
extern int BTL_FIELD_GetCountdownCount(void);
extern void func_021EF8A4(u32, u32);
extern int BTL_FIELD_RegisterStaticSlot(int a, union Slot c);
extern int BTLV_CORE_GetSlotPosition(union Slot c);
extern void BTL_FIELD_SetStaticSlotValue(int a, int r);
extern int func_0689C954(u16);
extern void BTL_POKEPARAM_SetAbility(struct QJ *p, u32 v);
extern void BTL_CALC_SwapAbilityHandlers(int a, int b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void BTL_POKEPARAM_SetSubstituteHp(u8 *a, u16 v);
extern int BTL_POKEPARAM_DamageSubstitute(u8 *c, u16 *d);
extern void BTL_POKEPARAM_ClearSubstitute(u8 *p);
extern void BTL_POKEPARAM_AdvanceTurn(u8 *);
extern void BTL_EVENT_ClearClientReservedChoice(u8 *);
extern void BTL_EVENT_RemoveDeadFactors(void);
extern u32 BTL_MAIN_GetPmsWork(u32 **p);
extern u32 COMM_PLAYER_SUPPORT_GetMode(BtlServerFlow *);
extern u32 func_0203F0A8(void);
extern void COMM_PLAYER_SUPPORT_SavePreviousAndSuspend(void *);
extern u8 *func_0689C9F8(u32);
extern void func_0689B7A8(u8 *, u8 *, union Slot, u32, BtlServerFlow *);
extern int func_021D6064(u8 *p, u32 k, union Slot *out, int *changed);
extern u32 BTL_CALC_PackPokeIds(const u8 *p);
extern void func_0689B8CC(u8 *, u8 *, u32);
extern void func_06898D54(void (*cb)(u8, u32, u32), u32 arg);
extern int BTL_FIELD_QueryStaticSlotC(int, int);
extern void func_021C4C40(int, void *);
extern u32 BTL_FIELD_TickCountdown(void);
extern int BTL_CALC_GetWeatherDamage(void *, int);
extern void func_0689D15C(u8 *, u8);
extern void BTL_POKEPARAM_ResetAllEffects(u8 *);
extern unsigned int BTL_MAIN_GetRuleSlotSpan(unsigned int **p);
extern int func_0689D5FC(u8 *, u8);
extern void BTL_CALC_DisableAbilityHandlers(void *p);
extern void BTL_HANDLER_ITEM_DisablePokeFactors(void *p);
extern void func_021E0434(u8 *);
extern void BTL_POKEPARAM_CureSickBySource(struct UtilSlots *p, int v);
extern int BTL_FIELD_QueryStaticSlotB(int a);
extern int BTL_MAIN_CheckEventOverlayAllowed(u32 **p);
extern int func_0689D1A0(u8 *, int, u8);
extern int func_0689D184(u8 *, int, u8);
extern void func_0689D1BC(u8 *, int, u8);
extern int BTL_POKEPARAM_AddExp(struct Obj *p, u32 *remaining, struct Result *r);
extern void BTL_POKEPARAM_ClearMajorStatus(struct UtilSlots *p);
extern void BTL_POKEPARAM_CureSick(struct UtilSlots *p, int k);
extern int BTL_CALC_FindMajorSick(struct Unk021D62A8 *p);
extern u8 BTL_POKEPARAM_RaiseStatStage(s8 *p, int i, u8 n);
extern u8 BTL_POKEPARAM_LowerStatStage(s8 *p, int i, u8 n);
extern void BTL_POKEPARAM_AddHp(struct Unk021D5FA4 *p, u16 n);
extern void BTL_POKEPARAM_SetSickCont(u8 *a, int k, union Slot s);
extern int BTLV_CORE_IsSlotKind1Index15(union Slot s);
extern void BTL_POKEPARAM_SubHp(u8 *, u16);
extern void BTL_POKEPARAM_RestoreRealMovePP(u8 *a, int b, int c);
extern void BTL_POKEPARAM_RestoreMovePP(u8 *a, int b, int c);
extern void BTL_POKEPARAM_SetContFlag(u8 *p, unsigned int n);
extern void BTL_POKEPARAM_ClearContFlag(u8 *, unsigned int);
extern u8 WAZA_TOOL_GetType(void *p);
extern int WAZA_TOOL_GetDamageType(int a);
extern u32 WAZA_TOOL_IsAlwaysHit(u16 id);
extern u8 BTL_POKEPARAM_GetCritStage(struct UtilWork *p);
extern int BTL_CALC_RollCriticalHit(int i);
extern u32 WAZA_TOOL_IsAlwaysCritical(u16 id);
extern u8 BTLV_CORE_GetHighByte(int);
extern int BTLV_CORE_GetLowByte(int);
extern int BTLV_CORE_BytesEqual(int);
extern int BTL_CALC_CombineTypeAffinity(int, int);
extern int BTL_POKEPARAM_HasType(void *p, int k);
extern void func_0689C6E4(BtlServerFlow *, u8 *);
extern void func_0689C540(BtlServerFlow *, u8 *);
extern int BTL_CALC_GetTypeAffinity(int a, int b);
extern int BTL_CALC_RollHitCount(int a);
extern u16 WAZA_TOOL_GetPower(void *p);
extern int BTL_POKEPARAM_GetStatForCrit(u8 *, int);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern u32 BTL_CALC_MulRatioMin1(u32 a, u32 b);
extern int BTL_MAIN_CheckFrontPos(unsigned int **, unsigned int);
extern int func_0689D5F4(u8 *, int);
unsigned int BTL_MAIN_GetActivePosPerSide(unsigned int **p);
extern unsigned int SHINKA_CHECK_GetRowParam(void *, unsigned int, unsigned int, unsigned int);
int func_06898CF4(int a, int b);
extern int func_06898CE0(unsigned int, int);
extern int func_068982AC(int);
extern u16 BTL_POKEPARAM_GetWeight(u8 *p);
extern int BTL_POKEPARAM_IsMovePPFull(u8 *p, int i, int s);
extern int func_0689C464(int, union Slot, u8 *, unsigned long, struct Msg *);
extern void BTL_POKEPARAM_SetStatStage(u8 *p, int i, u8 n);
extern int BTL_POKEPARAM_RaiseLoweredStatStages(char *);
extern void BTL_POKEPARAM_ResetStatStages(char *p);
extern void BTL_POKEPARAM_SetStat(u8 *, int, u16);
extern int func_0689C9C0(int);
extern void BTL_POKEPARAM_SetTypes(u8 *p, int n);
extern void BTL_POKEPARAM_ClearTurnFlag(u8 *p, u32 n);
extern void *func_06898C10(u8, int, Word_021CAA58_td);
extern int func_06898D10(u32, u32);
extern int BTL_FIELD_QueryStaticSlotA(int);
extern int func_068981F0(u32, u8, u8, const void *, u8);
extern int func_0689C974(u16);
extern void BTL_POKEPARAM_ClearConsumedItem(u8 *);
extern void *BTL_HANDLER_ITEM_AddForcedFactor(void *p, unsigned int k);
extern void BTL_HANDLER_ITEM_RemoveFactor(void *n);
extern void BTL_POKEPARAM_ReplaceMove(u8 *p, u8 i, u16 a, u8 b, u32 c);
extern void BTL_POKEPARAM_PassEffects(struct Work *p, struct Work *q);
extern void BTL_POKEPARAM_SetWeight(u8 *, u32);
extern int BTL_POKEPARAM_Transform(struct Unk021D6C50 *a, struct Unk021D6C50 *b);
extern void BTL_POKEPARAM_ClearIllusion(struct Unk021D6C2C *p);
extern int BTL_POKEPARAM_IsTransformed(struct R5 *p);
extern u8 BTL_MAIN_GetOwnLanePos(u8, u8);
extern u32 BTL_CALC_GetFightersPerSide(u32);
extern u8 BTL_MAIN_GetEnemyLanePosFromWork(char **p, u32 v, int k);
extern u32 BTL_CALC_CalcDefeatExp(void *a);
extern unsigned char BTL_EVENT_GetClientPartyCount(unsigned char *p);
extern u8 BTL_EVENT_GetClientPartySlotId(u8 *p, u32 i);
extern u8 func_02008564(const struct Sub0200852CObj *obj);
extern u32 GPOWER_ApplyExpRate(u32);
extern int func_0207C7B4(int x);
extern u32 BTL_POKEPARAM_GetMaxLevelExp(u8 *p);
extern u32 func_02019C90(u32 a, u32 b, u32 c);
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern int BTL_MAIN_CheckZukanSeen(char *p, void *m);
extern void BTL_EVENT_StartClientPalAnm(void **p, int value);
extern int GPOWER_ApplyCaptureRate(int);
extern int FX_Div(int, int);
extern int FX_Sqrt(int);
extern u32 BTL_MAIN_GetZukanSeenCount(char **p);
extern int TIMEZONE_GetTimeZoneOfHour(int row, int col);
extern int func_0689C9A0(u16);
extern Word_021CAA58_td BTLV_CORE_MakeSlotKind2Index(int v);
extern int BTL_POKEPARAM_AddCritStage(struct S_p14 *p, int n);
extern u8 func_021D5450(struct Work *p);
extern u8 BTL_POKEPARAM_GetRealMovePPLost(u8 *p, u32 i);
extern u32 BTL_POKEPARAM_GetRealMoveId(u8 *p, u8 i);
extern u32 func_0689C9E4(int);
extern int func_0689C8FC(u16);
extern int BTLV_CORE_CheckPartySlotPair(void *p, int id);
extern int func_0689D1D4(void *);
extern void GFL_USE_SetPlayersAudible(int,u32);
extern void PM_VOICE_ResetMasterVolume(void);
extern int GFL_USE_IsBgmFading(void);
extern void PM_VOICE_SetMasterVolume(u8);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void GFL_USE_FadeOutBgm(u32);
extern u8 WAZA_TOOL_GetType(void *p);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern int PMSI_PARAM_IsEnabled(const u16 *p);
extern void *PMSI_PARAM_ToString(void *slots, unsigned int heap);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void GFL_USE_SetBgmPlayerParam(void *);
extern int GFL_USE_PushBgm(void);
extern int GFL_USE_PopBgm(void);
extern int GFL_USE_IsSeqPlaying(unsigned int);
extern u16 POKE_TOOL_GetLevelUpMove(void *p, u32 *idx, u32 heap);
u8 func_021B8CB0(struct Unk021B8CB0 **p, u8 x);
u8 func_021B8D8C(void *p, void *a, u32 b);
u8 func_021B8DDC(u32 x);
u8 func_021B8DE4(char *p, int i);
unsigned char func_021B8DEC(char *p,unsigned char k);
void func_021B8E28(u8 *p, u8 n, u8 *out, u8 *cnt_out);
u8 func_021B8FF4(u8 *p);
u8 func_021B9010(u8 *p, u8 k);
int func_021B902C(int a, int b);
u32 func_021B9064(u8 *p, int k, int x);
void func_021B9090(u8 *p, u32 k, u32 x);
int func_021B911C(void *p, int k);
void func_021B92B0(char *p,void *m,int k);
u8 *func_021B937C(void *a, char *b, u8 *c);
u8 *func_021B98A4(char *const *q, u8 b);
u8 *func_021B98AC(char *const *q, u8 b);
void *func_021B990C(char *p, unsigned int i, unsigned int j);
u8 *func_021B9920(void *p, u32 i, u8 j);
u8 *func_021B9934(char *p, int i);
u8 *func_021B9940(char *p, u8 i);
int func_021B997C(u8 *p, unsigned int i);
int func_021B99B8(void *pp, unsigned int b);
u8 func_021B99C0(struct S_021B8CB0 **p, u32 b);
struct Unk021EFD70 *func_021B99E0(int i);
u32 func_021B99F0(u32 x);
int func_021B9A24(unsigned int a, unsigned int b);
unsigned char func_021B9A40(unsigned int x);
int func_021B9A6C(int a, u32 b);
u8 func_021B9AB0(u8 x);
unsigned char func_021B9AE0(unsigned int x);
char *func_021B9AEC(char *p, int i);
char *func_021B9AF8(char *p, int i);
u8 func_021B9B94(struct Q1 *p);
u8 func_021B9B98(u8 *p);
u8 func_021B9BC4(u8 *p,int i);
u32 func_021B9BF0(struct S2 *p, u32 i);
u8 *func_021B9C00(struct S2 *p, u32 i);
void func_021B9C10(u32 *p, int a, int b);
void func_021B9C50(u8 **p, u8 k, u8 **o1, u8 **o2);
int func_021B9C98(u8 *p,u32 v);
void *func_021B9CE8(u8 *p);
void func_021B9D10(char *a, struct Arr *arr, int k);
int func_021BA1A8(char **p, int m);
void func_021BA1B4(char **p, int i);
void func_021BA1CC(char **p, int i, u32 delta);
void func_021BA250(char *p, u8 *a, int b);
int func_021BA534(void ***p);
u8 *BTL_SERVER_GetClientChecked(u8 *p, unsigned int i);
u8 *BTL_SERVER_GetClientIfUsed(u8 *p, u32 i);
int BTL_SERVER_IsClientUsed(u8 *p, u8 i);
u8 BTL_SERVER_GetActionTableValue(u8 *p, u8 i);
Action BTL_SERVER_GetActionTableEntry(u8 *p, u8 i, u8 j);
void BTL_SERVER_AddMainCounter(int *p, int add);
void BTL_SERVER_FinishMainCounter(int *p);
void BTL_SERVER_ClearPokeChangeRequests(u8 *p);
void BTL_SERVER_AddPokeChangeRequest(u8 *p, u32 value);
BtlServerFlow *BTL_SERVER_FLOW_Create(void *a, void *b, void *c, void *d, int e, u16 heap);
void BTL_SERVER_FLOW_Reset(BtlServerFlow *flow);
void BTL_SERVER_FLOW_InitState(BtlServerFlow *flow);
void BTL_SERVER_FLOW_Destroy(u8 *p);
int BTL_SERVER_FLOW_RunBattleStart(BtlServerFlow *flow);
void BTL_SERVER_FLOW_ResetInitState(u8 *p);
int BTL_SERVER_FLOW_StartTurn(BtlServerFlow *flow, int a);
void BTL_SERVER_FLOW_ProcTurnStartEvents(BtlServerFlow *flow);
void BTL_SERVER_FLOW_ResetInitStateAfterSelect(u8 *p);
int BTL_SERVER_FLOW_StartAfterPokeSelect(BtlServerFlow *flow, int a);
void BTL_SERVER_FLOW_ResetInitStateAfterChange(u8 *p);
int BTL_SERVER_FLOW_StartAfterPokeChange(BtlServerFlow *flow, int a);
u32 BTL_SERVER_FLOW_RunActionOrder(BtlServerFlow *flow, u32 i);
void BTL_SERVER_FLOW_ResortActionOrder(BtlServerFlow *flow, Entry *e, u32 n);
int BTL_SERVER_FLOW_ProcPokeChangeActions(BtlServerFlow *flow, u8 *o);
int BTL_SERVER_FLOW_CheckShowdown(BtlServerFlow *flow);
int BTL_SERVER_FLOW_CheckPlayerSideAlive(BtlServerFlow *flow);
int BTL_SERVER_FLOW_RunEscapeFromLead(BtlServerFlow *flow);
int BTL_SERVER_FLOW_RunBagModeSetup(BtlServerFlow *flow);
void BTL_SERVER_FLOW_PushBagModePositions(BtlServerFlow *flow);
void BTL_SERVER_FLOW_ProcRotation(BtlServerFlow *flow, int a, u8 b);
int BTL_SERVER_FLOW_CollectChangeRequests(BtlServerFlow *flow, u8 *out);
u8 *BTL_SERVER_FLOW_GetSlotTable(BtlServerFlow *flow);
u8 BTL_SERVER_FLOW_GetChosenSlot(BtlServerFlow *flow);
void BTL_SERVER_FLOW_ProcPreTurnMoveCheck(BtlServerFlow *flow);
u8 BTL_SERVER_FLOW_BuildActionOrder(BtlServerFlow *flow, u8 *o, Entry *e, int unused);
void BTL_SERVER_FLOW_SortActionOrder(Entry *p, u32 n);
int BTL_SERVER_FLOW_CalcMovePriority(BtlServerFlow *flow, u32 x, u8 *a);
u16 BTL_SERVER_FLOW_CalcPokeSpeed(BtlServerFlow *flow, u8 *x, int flag);
Entry *BTL_SERVER_FLOW_FindActionByPokeId(BtlServerFlow *flow, u8 x);
Entry *BTL_SERVER_FLOW_FindNextActionByPokeId(BtlServerFlow *flow, Entry *cur, u32 x);
Entry *BTL_SERVER_FLOW_FindPendingActionByMove(BtlServerFlow *flow, u16 x, u32 i);
Entry *BTL_SERVER_FLOW_FindPendingMoveActionForPoke(BtlServerFlow *flow, u16 x, u8 y, u32 unused);
int BTL_SERVER_FLOW_GetActionIndex(BtlServerFlow *flow, Entry *cur);
int BTL_SERVER_FLOW_MoveActionForward(BtlServerFlow *flow, Entry *cur, int start);
void BTL_SERVER_FLOW_MoveActionToEnd(BtlServerFlow *flow, Entry *cur);
u32 BTL_SERVER_FLOW_ProcAction(BtlServerFlow *flow, Entry *e);
void BTL_SERVER_FLOW_NotifyActionStart(BtlServerFlow *flow, u8 *a, u32 k);
void BTL_SERVER_FLOW_DispatchActionStartEvent(BtlServerFlow *flow, u8 *a, u32 k);
void BTL_SERVER_FLOW_DispatchActionEndEvent(BtlServerFlow *flow, u8 *a, u32 k);
int BTL_SERVER_FLOW_CheckDisobedience(BtlServerFlow *flow, u8 *a);
int BTL_SERVER_FLOW_CheckObedienceOverride(BtlServerFlow *flow, u8 *a);
int BTL_SERVER_FLOW_ForceExecuteMoveAction(BtlServerFlow *flow, u8 x, u32 y);
int BTL_SERVER_FLOW_PromoteActionOfPoke(BtlServerFlow *flow, u8 x);
int BTL_SERVER_FLOW_PromoteActionsByMove(BtlServerFlow *flow, u16 x);
int BTL_SERVER_FLOW_DemoteActionOfPoke(BtlServerFlow *flow, u8 x);
void BTL_SERVER_FLOW_MarkActionDone(BtlServerFlow *flow, u8 n);
void BTL_SERVER_FLOW_InitTurnState(struct Unk021BD1E0 *p);
void BTL_SERVER_FLOW_SetupTurnState(struct Unk021BD1E0 *p, BtlServerFlow *flow, u8 *a, void *t);
void BTL_SERVER_FLOW_InitFieldPokeIter(u8 *p, u8 **q);
void BTL_SERVER_FLOW_SetFieldPokeIterRule(u8 *p, BtlServerFlow *flow);
int BTL_SERVER_FLOW_NextFieldPokeIter(u8 *p, u8 **q, u8 **out);
void BTL_SERVER_FLOW_ProcShift(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_ShiftPokes(BtlServerFlow *flow, int i, u8 a, u8 b, int c);
void BTL_SERVER_FLOW_DispatchShiftEvents(BtlServerFlow *flow, int i, u8 a, u8 b);
void BTL_SERVER_FLOW_DispatchShiftInEventLocked(BtlServerFlow *flow, u8 *m);
void BTL_SERVER_FLOW_DispatchShiftInEvent(BtlServerFlow *flow, u8 *m);
int BTL_SERVER_FLOW_ProcEscape(BtlServerFlow *flow, u8 *a);
int BTL_SERVER_FLOW_TryEscape(BtlServerFlow *flow, u8 *a, u8 flag);
int BTL_SERVER_FLOW_CheckEscapeGuaranteed(BtlServerFlow *flow, u8 *a);
int BTL_SERVER_FLOW_CommitEscape(BtlServerFlow *flow, u8 *a, int r, int z);
int BTL_SERVER_FLOW_CheckEscapePrevented(BtlServerFlow *flow, u8 *a);
int BTL_SERVER_FLOW_CheckEscapeMessageSuppressed(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_ProcMemberInCore(BtlServerFlow *flow, u8 i, u8 a, u8 b);
void BTL_SERVER_FLOW_ProcMemberIn(BtlServerFlow *flow, u8 i, u8 a, u8 b, int c);
int BTL_SERVER_FLOW_ProcAfterMemberIn(BtlServerFlow *flow);
void BTL_SERVER_FLOW_DispatchPokeEntryEvent(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_DispatchPokeEntryEventToType4(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_DispatchMemberInBeginEvent(BtlServerFlow *flow);
void BTL_SERVER_FLOW_DispatchMemberInEndEvent(BtlServerFlow *flow);
void BTL_SERVER_FLOW_NotifyRotationEnd(BtlServerFlow *flow);
void BTL_SERVER_FLOW_DispatchRotationEndEvent(BtlServerFlow *flow);
void BTL_SERVER_FLOW_PushMemberOutCmd(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_ProcMemberChange(BtlServerFlow *flow, u8 *a, u8 v);
int BTL_SERVER_FLOW_ProcMemberOut(BtlServerFlow *flow, u8 *a, int c);
void BTL_SERVER_FLOW_ProcMemberOutCore(BtlServerFlow *flow, u8 *a, u32 c);
void BTL_SERVER_FLOW_DispatchMemberOutEvent(BtlServerFlow *flow, u8 *a);
u16 BTL_SERVER_FLOW_GetEncoredMove(void *p, Action *m);
void BTL_SERVER_FLOW_ProcFight(BtlServerFlow *flow, u8 *a, Action *act, u32 key);
int BTL_SERVER_FLOW_CheckMoveRestricted(BtlServerFlow *flow, u8 *a, u16 *s);
void BTL_SERVER_FLOW_ProcDeferredMoves(BtlServerFlow *flow, u16 key);
void BTL_SERVER_FLOW_InitMoveQueue(struct Unk021BE518 *p);
void BTL_SERVER_FLOW_PushMoveQueue(u8 *p, int a, int b, int c);
void BTL_SERVER_FLOW_ProcInterruptMove(BtlServerFlow *flow, u8 *b, u16 c, void *unused);
void BTL_SERVER_FLOW_DispatchMoveTypeEvent(BtlServerFlow *flow, u8 *a, u8 *c);
void BTL_SERVER_FLOW_DispatchMoveParamEventLocked(BtlServerFlow *flow, u8 *a, u8 *c, int k);
void BTL_SERVER_FLOW_DispatchMoveParamEvent(BtlServerFlow *flow, u8 *a, u8 *c, int k);
int BTL_SERVER_FLOW_ProcPledgeCombo(BtlServerFlow *flow, u8 *a, u16 key, u32 x);
int func_021BE7E4(BtlServerFlow *flow, u8 *a, u32 b, u32 c, u8 *q);
int BTL_SERVER_FLOW_DispatchMoveExecuteCheckEvent(BtlServerFlow *flow, u8 *a, u32 v);
void BTL_SERVER_FLOW_NotifyMoveExecuteFail(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_DispatchMoveExecuteFailEvent(BtlServerFlow *flow,u8 *a);
void BTL_SERVER_FLOW_NotifyMoveStart(BtlServerFlow *flow, u8 *a, u32 v);
void BTL_SERVER_FLOW_DispatchMoveStartEvent(BtlServerFlow *flow, u8 *a, u32 v);
void BTL_SERVER_FLOW_NotifyMoveEnd(BtlServerFlow *flow,u8 *a,u32 c,u32 d);
void BTL_SERVER_FLOW_DispatchMoveEndEvent(BtlServerFlow *flow, u8 *a, u32 c, u32 d);
void BTL_SERVER_FLOW_DispatchMoveInterruptEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c);
void BTL_SERVER_FLOW_DispatchDeferredMoveEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c);
int BTL_SERVER_FLOW_CheckMoveInterrupt(BtlServerFlow *flow, u8 *a, int b, void *c, u8 *q);
int BTL_SERVER_FLOW_DispatchMoveInterruptCheckEvent(int a, u8 *b, int c, void *d, u8 *e, u8 *g);
void BTL_SERVER_FLOW_PushMoveExecCmd(BtlServerFlow *flow,u8 *a,int c,int d);
int BTL_SERVER_FLOW_IsPlayerSidePoke(BtlServerFlow *flow,u8 *a);
void BTL_SERVER_FLOW_RecordSpecialMoveUse(BtlServerFlow *flow,u8 *a,int c);
int func_021BEC58(BtlServerFlow *flow, u8 *a, u16 key, u8 *d);
void BTL_SERVER_FLOW_RemoveOutOfRangeTargets(BtlServerFlow *flow, u16 *b, int s, void *c);
void BTL_SERVER_FLOW_RemoveSelfTarget(int u, u8 *b, void *c, u8 *d, int e);
int BTL_SERVER_FLOW_CheckAccuracyCheckRequired(BtlServerFlow *flow, u16 *a, u8 *b);
void BTL_SERVER_FLOW_RemoveSubstituteTargets(int u, u16 *b, u8 *s, void *c, int e);
void BTL_SERVER_FLOW_NotifyMoveSucceeded(BtlServerFlow *flow, u32 a, u32 b);
void BTL_SERVER_FLOW_NotifyMoveFailed(BtlServerFlow *flow, u32 a, u32 b);
void BTL_SERVER_FLOW_NotifyMoveFinished(BtlServerFlow *flow, u32 a, u32 b);
void BTL_SERVER_FLOW_DispatchMoveResultEvent(BtlServerFlow *flow, u32 a, u32 b, int k);
int func_021BF324(BtlServerFlow *flow, u8 *a, u8 *b);
void BTL_SERVER_FLOW_ProcAccuracyCheck(BtlServerFlow *flow, int b, u8 *a, void *d, void *arr);
void BTL_SERVER_FLOW_ProcNoEffectChecks(BtlServerFlow *flow, u8 *b, u8 *a, void *d, void *e);
int BTL_SERVER_FLOW_ProcNoEffectCheck(BtlServerFlow *flow, u8 *b, u8 *c2, u8 *d, void *s0, int s1);
int BTL_SERVER_FLOW_RunTargetNoEffectEvent(BtlServerFlow *flow, u8 *b, int c, u8 *d, u8 *e, void *f, void *g, int *h);
void BTL_SERVER_FLOW_RemoveImmuneTargets(BtlServerFlow *flow, u16 *b, u8 *c, void *d);
void BTL_SERVER_FLOW_RemoveMissedTargets(BtlServerFlow *flow, u16 *b, u8 *c, void *d);
int BTL_SERVER_FLOW_CheckMoveAvoidEvent(BtlServerFlow *flow, u8 *a, u8 *b, u16 *c);
int BTL_SERVER_FLOW_CheckAllyMoveAutoHit(BtlServerFlow *flow, u8 *a, u8 *b, void *item);
int BTL_SERVER_FLOW_RollMoveAccuracy(BtlServerFlow *flow, u8 *a, u8 *b, struct Q *q);
void BTL_SERVER_FLOW_PushPendingHpRecovery(BtlServerFlow *flow, u32 fallback, u8 *record, u32 pos);
int func_021BFC08(BtlServerFlow *flow, u8 *q, u8 *d, u16 c);
int BTL_SERVER_FLOW_ProcMoveUseDecide(BtlServerFlow *flow, u8 *q, u16 c, u8 *d, u16 e);
void BTL_SERVER_FLOW_ClearMoveLockSicks(BtlServerFlow *flow, u8 *a);
int BTL_SERVER_FLOW_ProcMoveReflectOrAbsorb(BtlServerFlow *flow, u8 *a, u8 *b, int *out);
void BTL_SERVER_FLOW_ReleaseBindingTarget(BtlServerFlow *flow, u8 *a, int z);
int func_021C001C(BtlServerFlow *flow, u8 *a, u16 c, u16 d);
int BTL_SERVER_FLOW_CheckMoveExecuteFailByEvent(BtlServerFlow *flow, u8 *a, u16 c);
int BTL_SERVER_FLOW_QueryStatusSkipEvent(BtlServerFlow *flow, u8 *a, u32 c, u32 d);
int BTL_SERVER_FLOW_QueryMoveFailReasonEvent(BtlServerFlow *flow, u8 *a, u32 c, int k);
int BTL_SERVER_FLOW_CheckParalysisFail(BtlServerFlow *flow, u8 *a);
int BTL_SERVER_FLOW_CheckConfusionSelfHit(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_TickSleepTurn(BtlServerFlow *flow, u8 *a, u16 a2);
int BTL_SERVER_FLOW_CheckFreezeThaw(BtlServerFlow *flow, u8 *a, void *bag);
void BTL_SERVER_FLOW_ProcMoveExecuteFail(BtlServerFlow *flow, u8 *q, u16 c, int k);
void BTL_SERVER_FLOW_PushMoveFailMessage(BtlServerFlow *flow, u8 *a, u16 b, u32 c);
void BTL_SERVER_FLOW_SetPokeCounter(BtlServerFlow *flow, u8 *a, int i, u8 v);
int BTL_SERVER_FLOW_ReducePPByEvent(BtlServerFlow *flow, u8 *a, u16 c, u16 d, void *e);
int BTL_SERVER_FLOW_QueryMovePPCostEvent(BtlServerFlow *flow, u8 *a, u16 c, u16 d, void *e);
int BTL_SERVER_FLOW_ConsumeMovePP(BtlServerFlow *flow, u8 *a, u32 b, u8 c);
void BTL_SERVER_FLOW_DecrementMovePP(BtlServerFlow *flow, u8 *a, int b, u8 c);
void BTL_SERVER_FLOW_ProcMoveHitTargets(BtlServerFlow *flow, u8 *q, u8 *a, u8 *b, const u32 *c, u32 d);
void BTL_SERVER_FLOW_BuildDamageList(BtlServerFlow *flow, u8 *a, u8 *b, const u8 *q, const u32 *c, u32 k, struct List_021BDB88 *out);
u32 BTL_SERVER_FLOW_GetHitFlagsByte2(u8 *p);
int BTL_SERVER_FLOW_UnpackDamageEntries(BtlServerFlow *flow, const List_td *l, u32 *o0, u16 *o1, u32 *o2, u8 *o3);
int BTL_SERVER_FLOW_UnpackEntryPokes(BtlServerFlow *flow, const struct Q_021C0CB4 *q, u32 *out);
int BTL_SERVER_FLOW_UnpackHitEntries(BtlServerFlow *flow, const struct Q_021C0CE8 *q, u32 *o1, u16 *o2, u32 *o3, u8 *o4, u8 *o5);
u32 BTL_SERVER_FLOW_SumHitRecordDamage(const u8 *q);
u32 BTL_SERVER_FLOW_ProcDamageTargets(BtlServerFlow *flow, u8 *q, u8 *a, u8 *b, const u32 *c, u32 *out, u32 d);
u32 BTL_SERVER_FLOW_ProcMultiHitDamage(BtlServerFlow *flow, u8 *q, u8 *a, u8 *d, const u32 *c);
int BTL_SERVER_FLOW_IsFirstHit(const u8 *p);
u8 BTL_SERVER_FLOW_GetHitFlagsMultiHit(u8 *p);
void BTL_SERVER_FLOW_SetHitFlagsResultIf3(unsigned char *p, int x);
u32 BTL_SERVER_FLOW_ProcDamageRecordIfAny(BtlServerFlow *flow, u16 *a, u8 *b, u8 *c, u8 *d, u8 *e, u32 f, CallFlags g);
int BTL_SERVER_FLOW_ApplyDamageRecord(BtlServerFlow *flow, u8 *x, u8 *unused, u8 *y, u16 *e, u8 *st, u32 a6, CallFlags a7);
void BTL_SERVER_FLOW_RemoveSelfProtectedTargets(BtlServerFlow *flow, u8 *a, int b, u8 *c);
void func_021C15AC(BtlServerFlow *flow, int k);
u32 BTL_SERVER_FLOW_ClampDamageToHp(void *p, u32 n);
void BTL_SERVER_FLOW_RunMoveHitEventLocked(BtlServerFlow *flow, u8 *a, u8 *b, u16 *c);
void BTL_SERVER_FLOW_RunMoveHitEvent(BtlServerFlow *flow, u8 *a, u8 *b, u16 *c);
int BTL_SERVER_FLOW_CheckEndureEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c, u16 *d);
void BTL_SERVER_FLOW_ProcDamageAftereffect(BtlServerFlow *flow, u8 *a, int k);
void BTL_SERVER_FLOW_RunDamageAftereffectEvent(BtlServerFlow *flow, u8 *q, int k);
void BTL_SERVER_FLOW_RunTargetsDamagedEventLocked(BtlServerFlow *flow, u32 x, u8 *a, u32 n, u32 *arr);
void BTL_SERVER_FLOW_RunTargetsDamagedEvent(BtlServerFlow *flow, u32 x, u8 *a, u32 n, u8 **arr);
void BTL_SERVER_FLOW_RecordDamageHit(BtlServerFlow *flow, u8 b, u8 *x, u8 *c, u8 *q, u16 w);
void BTL_SERVER_FLOW_ProcMoveCategoryEffect(BtlServerFlow *flow, u8 *q, u8 *a, u8 *b, u32 s0, int s1);
void BTL_SERVER_FLOW_RunDamageDealtEventLocked(BtlServerFlow *flow, u8 *a, u8 *q, u32 v);
void BTL_SERVER_FLOW_RunDamageDealtEvent(BtlServerFlow *flow, u8 *a, u8 *q, u32 v);
void BTL_SERVER_FLOW_ProcDamagedItemReaction(BtlServerFlow *flow, u8 *q, u32 n);
void BTL_SERVER_FLOW_RunDamagedItemEvent(BtlServerFlow *flow, u8 *q, u32 n);
void BTL_SERVER_FLOW_RunMoveUsedEventLocked(BtlServerFlow *flow, u8 *a, u8 *q);
void BTL_SERVER_FLOW_RunMoveUsedEvent(BtlServerFlow *flow, u8 *a, u8 *q);
void BTL_SERVER_FLOW_ProcMoveAfterDamageEvents(BtlServerFlow *flow, u8 *a, u8 *b, u8 *c, u32 unused, u32 d);
void BTL_SERVER_FLOW_RunMoveDamageGroupEvent(BtlServerFlow *flow, u8 *a, u8 *b, u8 *c, u32 d, u8 e, int f);
void BTL_SERVER_FLOW_RunMoveDamageEndEvent(BtlServerFlow *flow, u8 *a, u32 unused, u8 *q, u32 v);
int BTL_SERVER_FLOW_ProcFlinchChance(BtlServerFlow *flow, u16 *x, u8 *a, u8 *q);
void BTL_SERVER_FLOW_ThawTargetsHitByFireMove(BtlServerFlow *flow, u8 *q, u32 unused, u8 *w);
int BTL_SERVER_FLOW_RollFlinch(BtlServerFlow *flow, u8 *q, u32 n);
void BTL_SERVER_FLOW_ProcDrainHeal(BtlServerFlow *flow, u8 *q, u32 a, u8 *b, u32 s);
int BTL_SERVER_FLOW_RecoverHpFromDrain(BtlServerFlow *flow, u8 *q, u32 a, u32 b);
int BTL_SERVER_FLOW_CalcMoveDamage(BtlServerFlow *flow, u8 *a, u8 *b, const u8 *c, u32 d, u32 e, u32 f, int g, u16 *out);
void BTL_SERVER_FLOW_ProcDamageAbsorbRecovery(BtlServerFlow *flow, u8 *a, u16 b, u32 c);
int BTL_SERVER_FLOW_CheckAbsorbRecoverAllowed(BtlServerFlow *flow, u8 *a, int r);
int BTL_SERVER_FLOW_ProcAbsorbRecovery(BtlServerFlow *flow, u8 *a, int c, u8 *l);
int BTL_SERVER_FLOW_ProcHeldItemActivate(BtlServerFlow *flow, u8 *a);
int BTL_SERVER_FLOW_RunItemActivateCheckEvent(BtlServerFlow *flow, u8 *a, u16 c);
void BTL_SERVER_FLOW_SetHeldItem(BtlServerFlow *flow, u8 *a, u16 b, u32 c);
int BTL_SERVER_FLOW_ProcPokeHpChangeFinish(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_ProcMoveAddedSick(BtlServerFlow *flow, const u16 *a, u8 *b, u8 *c);
u32 BTL_SERVER_FLOW_RollMoveAddedSick(BtlServerFlow *flow, u16 id, u8 *a, u8 *b, union Slot *dest);
void BTL_SERVER_FLOW_ProcMoveSickAllTargets(BtlServerFlow *flow, u16 id, u8 *a, void *c);
int BTL_SERVER_FLOW_ProcMoveSickOnTarget(BtlServerFlow *flow, u8 *a, u8 *b, u32 unused, u32 s0, union Slot s1, u32 s2);
int BTL_SERVER_FLOW_QueryMoveSickIdEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c);
void BTL_SERVER_FLOW_RunMoveSickSelectedEvent(BtlServerFlow *flow, u32 a, u8 *b, u8 *c, u32 d);
void BTL_SERVER_FLOW_RunMoveSickContEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c, union Slot *d);
int BTL_SERVER_FLOW_ApplyMoveSick(BtlServerFlow *flow, u8 *x, u8 *y, int z, union Slot a, u32 b, u32 c);
int BTL_SERVER_FLOW_TryApplySick(BtlServerFlow *flow, u8 *x, u8 *y, int z, union Slot a, u8 b, u32 c);
int BTL_SERVER_FLOW_CheckSickImmunity(BtlServerFlow *flow, struct Unk021D62A8 *b, int c, union Slot d, u8 e);
void BTL_SERVER_FLOW_ProcSickAdded(BtlServerFlow *flow, u8 *a, u8 *b, int kind, union Slot value, int f, int g, const void *m);
int BTL_SERVER_FLOW_GetEffectiveWeather(BtlServerFlow *flow);
int BTL_SERVER_FLOW_QueryPokeMultiplierEvent(u8 *p, u8 *a);
int BTL_SERVER_FLOW_QuerySickBlockedEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c);
void BTL_SERVER_FLOW_RunSickAppliedEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c);
void BTL_SERVER_FLOW_RunSickAddedContEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c, u32 d);
void BTL_SERVER_FLOW_RunSickAddedEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c);
void BTL_SERVER_FLOW_RunSickEndEvent(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_ProcMoveAddedRankEffect(BtlServerFlow *flow, u16 *q, u8 *a, u8 *b);
int BTL_SERVER_FLOW_RollMoveAddedEffectChance(BtlServerFlow *flow, u16 *q, u8 *b, u8 *c);
void BTL_SERVER_FLOW_ProcMoveRankEffectAllTargets(BtlServerFlow *flow, u32 a, u32 b, void *c);
u32 BTL_SERVER_FLOW_NextSerialNumber(BtlServerFlow *flow);
int BTL_SERVER_FLOW_ProcMoveRankEffects(BtlServerFlow *flow, const u16 *q, u8 *a, u8 *b, int k);
void BTL_SERVER_FLOW_QueryMoveRankEffectEvent(BtlServerFlow *flow, u16 x, u32 y, u8 *c, u8 *s0, s32 *s1, s32 *s2);
int BTL_SERVER_FLOW_TryChangeStatStage(BtlServerFlow *flow, u8 b, u8 *a, enum Kind kind, int value, u8 f, u16 g, u32 h, int i, u32 j);
int BTL_SERVER_FLOW_QueryStatStageChangeEvent(BtlServerFlow *flow, u8 *a, enum Kind b, u8 c, u16 e, int d);
void BTL_SERVER_FLOW_ProcMoveRankAndSickAllTargets(BtlServerFlow *flow, const u16 *q, u32 r, void *c);
void BTL_SERVER_FLOW_ProcMoveRecoverHpAllTargets(BtlServerFlow *flow, u32 q, u32 b, void *c);
int BTL_SERVER_FLOW_TryRecoverHp(BtlServerFlow *flow, u8 *q, int a, int b);
int BTL_SERVER_FLOW_IsHpRecoverUnneeded(BtlServerFlow *flow, void *q);
int BTL_SERVER_FLOW_CheckHealBlocked(BtlServerFlow *flow, u8 *q, int r);
void BTL_SERVER_FLOW_ApplyHpRecover(BtlServerFlow *flow, u8 *b, int c);
void BTL_SERVER_FLOW_ProcMoveOhko(BtlServerFlow *flow, u16 *q, u8 *a, u8 *out);
void BTL_SERVER_FLOW_ProcOhkoFaint(BtlServerFlow *flow, u8 *a, u16 *b, int c);
void BTL_SERVER_FLOW_ProcOhkoEndured(BtlServerFlow *flow, u8 *q, u16 *r, int a, int b, u16 c);
u16 BTL_SERVER_FLOW_ProcOhkoSubstituteBroken(BtlServerFlow *flow, u8 *a, u16 *b, int c);
void BTL_SERVER_FLOW_ProcMoveForceSwitchAllTargets(BtlServerFlow *flow, u16 a1, int b, void *it);
int BTL_SERVER_FLOW_TryForceSwitchTarget(BtlServerFlow *flow, u8 *a, u8 *b, int force, int *out, u16 move, int ignore, const struct Msg *msg);
BOOL BTL_SERVER_FLOW_IsForceSwitchByParty(BtlServerFlow *flow);
int BTL_SERVER_FLOW_PickRandomBenchPoke(BtlServerFlow *flow, u8 *b);
int BTL_SERVER_FLOW_QueryForceSwitchBlockedEvent(BtlServerFlow *flow, int unused, u8 *a);
void BTL_SERVER_FLOW_ProcMoveWeather(BtlServerFlow *flow, u16 *a, u8 *b);
int BTL_SERVER_FLOW_TryChangeWeather(BtlServerFlow *flow, int a, u8 b);
BOOL BTL_SERVER_FLOW_CanChangeWeather(BtlServerFlow *flow, u32 a, u32 b);
void BTL_SERVER_FLOW_ApplyWeatherChange(BtlServerFlow *flow, u32 a, u32 b);
void BTL_SERVER_FLOW_ProcWeatherChanged(BtlServerFlow *flow, u32 a);
u8 BTL_SERVER_FLOW_QueryWeatherPokeEvent(BtlServerFlow *flow, int k, u8 *a);
int BTL_SERVER_FLOW_TryRegisterFieldSlot(BtlServerFlow *flow, int a, union Slot c, int d);
void BTL_SERVER_FLOW_DispatchPokeMoveEvent(BtlServerFlow *flow, u8 *b, int c);
void BTL_SERVER_FLOW_ProcMoveSpecialEffect(BtlServerFlow *flow, u16 *b, u8 *a, u8 *c);
void BTL_SERVER_FLOW_ProcSkillSwap(BtlServerFlow *flow, u8 *a, u8 *c);
void BTL_SERVER_FLOW_RecheckOpponentAbilityEffects(BtlServerFlow *flow, u8 *a);
int BTL_SERVER_FLOW_ProcSubstituteMove(BtlServerFlow *flow, u8 *a);
u16 BTL_SERVER_FLOW_ProcSubstituteDamage(BtlServerFlow *flow, u8 *q, u8 *c, u16 d, int sa, u8 sb, u16 *e);
void BTL_SERVER_FLOW_RemoveSubstitute(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_ProcDamageEndEvents(BtlServerFlow *flow, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3);
void BTL_SERVER_FLOW_DispatchDamageEndEvents(BtlServerFlow *flow, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3);
int BTL_SERVER_FLOW_DispatchMoveFailCheck(BtlServerFlow *flow, u16 *b, u8 *a, u8 *c, int *out);
void BTL_SERVER_FLOW_CollectActivePokes(BtlServerFlow *flow, u8 *a);
int BTL_SERVER_FLOW_ProcTurnCheck(BtlServerFlow *flow);
void BTL_SERVER_FLOW_ProcTripleShift(BtlServerFlow *flow);
void BTL_SERVER_FLOW_ProcPlayerSupportHeal(BtlServerFlow *flow);
int BTL_SERVER_FLOW_ProcTurnCheckPhase(BtlServerFlow *flow, u8 *a, u8 *b);
void BTL_SERVER_FLOW_DispatchTurnCheckEvent(BtlServerFlow *flow, u32 a, int k);
int BTL_SERVER_FLOW_ProcTurnCheckSickness(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_ProcSickDamage(BtlServerFlow *flow, u8 *a, u32 b, u32 c);
int BTL_SERVER_FLOW_CalcSickDamage(BtlServerFlow *flow, u8 *a, u32 b, u32 c);
void BTL_SERVER_FLOW_ProcSideEffectsExpire(BtlServerFlow *flow);
void BTL_SERVER_FLOW_OnSideEffectExpired(int v, int k, BtlServerFlow *flow);
void BTL_SERVER_FLOW_PushSideEffectExpireMessage(BtlServerFlow *flow, int k, int v);
void BTL_SERVER_FLOW_ProcFieldEffectsExpire(BtlServerFlow *flow);
void BTL_SERVER_FLOW_OnFieldEffectExpired(int result, void *arg);
void BTL_SERVER_FLOW_PushFieldEffectExpireMessage(BtlServerFlow *flow, int k);
int BTL_SERVER_FLOW_ProcWeatherTurnCheck(BtlServerFlow *flow, void *it);
int BTL_SERVER_FLOW_CalcWeatherDamage(BtlServerFlow *flow, u8 *a, u32 b, u32 c);
void BTL_SERVER_FLOW_ApplyWeatherDamage(BtlServerFlow *flow, u8 *a, int k, int n);
int BTL_SERVER_FLOW_ProcFaintedPoke(BtlServerFlow *flow, u8 *a);
u32 BTL_SERVER_FLOW_GetHighestOpponentLevel(BtlServerFlow *flow);
void BTL_SERVER_FLOW_ProcPokeLeaveField(BtlServerFlow *flow, u8 *a, int b);
void BTL_SERVER_FLOW_DispatchPokeLeaveEvent(BtlServerFlow *flow, u8 *a);
int BTL_SERVER_FLOW_ProcFaintRewards(BtlServerFlow *flow);
int BTL_SERVER_FLOW_ProcExpForFaintedPoke(BtlServerFlow *flow, u8 *a);
int BTL_SERVER_FLOW_ApplyPartyExp(BtlServerFlow *flow, u8 *g, const struct Entry_p11 *q);
int BTL_SERVER_FLOW_TryClearContFlag(BtlServerFlow *flow, u8 *a, int b);
void *BTL_SERVER_FLOW_ClearPendingCounter(char *p);
void BTL_SERVER_FLOW_PushPokeEffectAnim(BtlServerFlow *flow, u8 *a, int b);
void BTL_SERVER_FLOW_PushActionBlockedMessage(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_PushConfusionMessage(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_PushInfatuationMessage(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_ApplyFixedDamageEffect(BtlServerFlow *flow, u8 *a, int c);
void BTL_SERVER_FLOW_CureMajorStatusWithMessage(BtlServerFlow *flow, u8 *a, int k, int flag);
void BTL_SERVER_FLOW_PushPokeCmd59(BtlServerFlow *flow, u8 *a, int b);
void BTL_SERVER_FLOW_CureSick(BtlServerFlow *flow, u8 *a, int k, union Slot *out);
int BTL_SERVER_FLOW_ResolveCureSickId(u8 *p, int *pv);
void BTL_SERVER_FLOW_PushMsgStdFailed(BtlServerFlow *flow, u8 *a, u32 b);
void BTL_SERVER_FLOW_PushMoveBlockedMessage(BtlServerFlow *flow, u8 *a, u32 v);
void BTL_SERVER_FLOW_PushNoEffectMessage(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_PushActionFailedMessage(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_PushMoveEffectiveness(BtlServerFlow *flow, u16 *a, u32 n, int *arr, u8 **ptrs, u16 *vals, u8 *unused1, int unused2);
void func_021C5840(BtlServerFlow *flow, u32 count, int *v, u8 **a, int flag);
void BTL_SERVER_FLOW_PushCriticalHitMessage(BtlServerFlow *flow, u32 n, u8 **a, u8 *b, int flag);
void BTL_SERVER_FLOW_PushAbilityPopupIn(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_PushAbilityPopupOut(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_PushSignedChangeMessage(BtlServerFlow *flow, u8 *a, int b, int c);
void BTL_SERVER_FLOW_ChangeStatStage(BtlServerFlow *flow, u8 *a, int c, int d, u16 msg, int flag);
void BTL_SERVER_FLOW_ChangeHp(BtlServerFlow *flow, u8 *a, int c, int d);
void BTL_SERVER_FLOW_KillPoke(BtlServerFlow *flow, u8 *a, int c);
void BTL_SERVER_FLOW_SetSickCont(BtlServerFlow *flow, u8 *a, int k, union Slot s);
void BTL_SERVER_FLOW_PushSickFailedMessage(BtlServerFlow *flow, u8 *a, int kind, u32 v);
void BTL_SERVER_FLOW_PushMsgSetPoke(BtlServerFlow *flow, u8 *a, int b);
void BTL_SERVER_FLOW_PushMsgStd(BtlServerFlow *flow, u32 a, int n, const int *v);
void BTL_SERVER_FLOW_PushMsgStdSe(BtlServerFlow *flow, u32 a, u32 b, int n, int *v);
void BTL_SERVER_FLOW_PushMsgSet(BtlServerFlow *flow, u32 a, int n, const int *v);
void BTL_SERVER_FLOW_PushMsgSetSe(BtlServerFlow *flow, u32 a, u32 b, int n, int *v);
void BTL_SERVER_FLOW_SubtractHp(BtlServerFlow *flow, u8 *a, int n);
void BTL_SERVER_FLOW_RestoreMovePp(BtlServerFlow *flow, u8 *a, int b, int c, int d);
void BTL_SERVER_FLOW_PushPokeCmd42(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_SetContFlag(BtlServerFlow *flow, u8 *a, u32 n);
void BTL_SERVER_FLOW_ClearContFlag(BtlServerFlow *flow, u8 *a, unsigned int n);
void BTL_SERVER_FLOW_SetTurnFlag(BtlServerFlow *flow, u8 *a, unsigned int n);
void BTL_SERVER_FLOW_ProcClientMemberChange(BtlServerFlow *flow, u8 *a);
int BTL_SERVER_FLOW_ProcPursuitBeforeSwitch(BtlServerFlow *flow, u8 *a);
int BTL_SERVER_FLOW_QueryForcedMoveEvent(BtlServerFlow *flow, u8 *a, u32 unused, u32 c, struct O_p11 *out);
u8 BTL_SERVER_FLOW_QueryActionAllowedEvent(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_NotifyMoveEvent(BtlServerFlow *flow, u8 *a, unsigned int n);
u32 BTL_SERVER_FLOW_ProcConfusionDamage(BtlServerFlow *flow, u8 *q);
int BTL_SERVER_FLOW_QueryActionMessageEvent(BtlServerFlow *flow, u8 *a, u32 c, u32 d, u8 *e);
void BTL_SERVER_FLOW_GetMoveParam(BtlServerFlow *flow, u16 q, u8 *a, struct Out64B4 *out);
void BTL_SERVER_FLOW_DispatchMoveDoneEvent(BtlServerFlow *flow, u8 *a, u32 c, u32 d);
int BTL_SERVER_FLOW_QueryMoveExecuteEvent(BtlServerFlow *flow, u8 *a, u32 e, u8 *d);
int BTL_SERVER_FLOW_QueryActionCancelEvent(BtlServerFlow *flow, u8 *a, u8 *a2, u16 a3);
int BTL_SERVER_FLOW_QueryFirstTargetBlockEvent(BtlServerFlow *flow, u8 *a, void *c);
int BTL_SERVER_FLOW_QueryMoveBlockedEvent(BtlServerFlow *flow, u8 *a, u32 c);
int BTL_SERVER_FLOW_QueryMoveRedirectEvent(BtlServerFlow *flow, u8 *a, u8 *d, u16 unused, u8 *out8, u32 *out32);
void BTL_SERVER_FLOW_NotifyMoveBeginEvent(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_NotifyMoveFinishEvent(BtlServerFlow *flow, u8 *a, int a2);
int BTL_SERVER_FLOW_QueryMoveTargetsAllowedEvent(BtlServerFlow *flow, u8 *a, u8 *d, u16 a3);
int BTL_SERVER_FLOW_QuerySemiInvulnerableHit(BtlServerFlow *flow, u8 *a, u8 *b, u32 v);
int func_021C69B8(BtlServerFlow *flow, u8 *a, u32 c, u16 id);
int BTL_SERVER_FLOW_CalcAccuracyRatio(BtlServerFlow *flow, u8 *a, u8 *b, struct Q *q);
int BTL_SERVER_FLOW_CheckOneHitKoHit(BtlServerFlow *flow, u8 *a, u8 *b, u16 id);
int BTL_SERVER_FLOW_QueryTypeImmunityEvent(BtlServerFlow *flow, u8 *a, u8 *b, u8 *q);
void BTL_SERVER_FLOW_NotifyTypeImmunityEvent(BtlServerFlow *flow, u8 *a, u8 *b);
int BTL_SERVER_FLOW_CheckCriticalHit(BtlServerFlow *flow, u8 *a, u8 *b, u16 q);
int BTL_SERVER_FLOW_CalcMoveDrainRecoil(BtlServerFlow *flow, u8 *a, u16 b, int amount, int *out);
void BTL_SERVER_FLOW_DispatchPostMoveEvent(BtlServerFlow *flow, u8 *a);
void BTL_SERVER_FLOW_DispatchPostMoveKindEvent(BtlServerFlow *flow, u8 *a, u8 k);
int BTL_SERVER_FLOW_CalcTypeEffectiveness(BtlServerFlow *flow, u8 *a, u8 *b, u8 *q, int flag);
int BTL_SERVER_FLOW_IsPokeGrounded(BtlServerFlow *flow, u8 *a, int k);
int BTL_SERVER_FLOW_QueryPokeGroundedEvent(BtlServerFlow *flow, u8 *a, int f);
void BTL_SERVER_FLOW_ProcImmunityOverrideNotice(BtlServerFlow *flow, u8 *q);
void BTL_SERVER_FLOW_NotifyImmunityOverrideEvent(BtlServerFlow *flow, u8 *a);
int BTL_SERVER_FLOW_CalcSingleTypeAffinity(BtlServerFlow *flow, u8 *a, u8 *b, u32 q, u8 s);
void BTL_SERVER_FLOW_PushEffectAnim(BtlServerFlow *flow, int a, int b, int c, int e, u32 f);
int BTL_SERVER_FLOW_QueryEffectBlockedEvent(BtlServerFlow *flow, u8 *a, u32 v);
int BTL_SERVER_FLOW_CalcMultiHitCount(BtlServerFlow *flow, u8 *a, u32 x, u8 *out);
u16 BTL_SERVER_FLOW_CalcMovePower(BtlServerFlow *flow, u8 *a, u8 *b, const u8 *s);
int BTL_SERVER_FLOW_QueryTargetableEvent(BtlServerFlow *flow, u8 *a);
u16 func_021C7374(BtlServerFlow *flow, u8 *a, u8 *b, const u8 *c, int flag);
u16 func_021C7474(BtlServerFlow *flow, u8 *a, u8 *b, const u8 *c, u32 flag);
int func_021C75EC(BtlServerFlow *flow, u8 *a, int k);
int func_021C7664(BtlServerFlow *flow, u32 x, u8 *a);
int func_021C76F4(BtlServerFlow *flow, u8 *a, u32 k);
void func_021C7780(BtlServerFlow *flow, u8 *a);
int func_021C77B0(BtlServerFlow *flow, u8 *a, u32 b, u32 c, u32 d, u32 e);
void func_021C7820(BtlServerFlow *flow, u8 *a, u32 k);
void func_021C785C(BtlServerFlow *flow, u32 a, u8 *b, u32 c, u32 d);
void func_021C78A8(BtlServerFlow *flow, u8 *a, u32 b, u32 c, u32 d);
u16 func_021C78F4(BtlServerFlow *flow, u8 *a, u8 *b, u32 s);
void func_021C7998(BtlServerFlow *flow, u32 x);
u32 func_021C79E0(BtlServerFlow *flow, u32 x, u8 *a);
int func_021C7A54(BtlServerFlow *flow, u8 *a, u32 c);
void func_021C7AA0(BtlServerFlow *flow, u8 *a);
void func_021C7AD0(BtlServerFlow *flow, u8 *a, u32 k);
void func_021C7B0C(BtlServerFlow *flow, u8 *a);
void func_021C7B3C(BtlServerFlow *flow, u32 a, u16 b, u16 c);
void func_021C7B7C(BtlServerFlow *flow, unsigned int i);
void func_021C7BA8(BtlServerFlow *flow, u8 a, u32 b, u32 c, u32 *out);
void func_021C7BF8(BtlServerFlow *flow);
void func_021C7C18(void *p);
void func_021C7C24(u16 *p, int unused, u8 *b, u8 *c, int e);
u16 func_021C7CBC(u8 *p);
u16 func_021C7CC8(u8 *p);
u16 func_021C7CD4(struct Q6 *p);
u16 func_021C7CDC(u8 *p);
u16 func_021C7CE8(u8 *p);
void *func_021C7CF4(int *p, int i);
int func_021C7D00(BtlServerFlow *flow, int b);
int func_021C7D34(char *p, int i);
int func_021C7D44(char *p, u8 i);
u8 func_021C7D54(u8 *p, u8 *k, u8 *out);
int func_021C7DAC(BtlServerFlow *flow, int a, int b, u16 c);
u16 func_021C7E14(BtlServerFlow *flow, u8 a, u8 b, u16 c, int e0, int e1);
u32 func_021C7EC4(u8 *p);
int func_021C7ED8(u8 *p, int i);
int func_021C7EEC(BtlServerFlow *flow, int i);
int func_021C7F04(BtlServerFlow *flow, int i);
int func_021C7F24(BtlServerFlow *flow, int i);
int func_021C7F4C(struct Flag *p);
u8 func_021C7F68(BtlServerFlow *flow, int b, u8 *out);
char *func_021C7FCC(BtlServerFlow *flow, int i);
char *func_021C7FE0(BtlServerFlow *flow, int v);
int func_021C8010(BtlServerFlow *flow, unsigned int v);
u8 func_021C8020(BtlServerFlow *flow, u8 v);
int func_021C8030(BtlServerFlow *flow, int v, u16 k);
int func_021C804C(S_td *p, u8 key, u32 *out);
int func_021C80AC(u8 *p, int key);
u16 func_021C8114(u8 *p);
u8 *func_021C8120(u8 *p, int b);
u8 *func_021C812C(u8 *p);
u8 *func_021C8130(u8 *p);
u16 func_021C8138(struct Q7 *p);
unsigned char func_021C8140(char *p, int i);
int func_021C814C(u8 *p, u8 v);
int func_021C815C(int *p);
void func_021C8168(int *p);
int func_021C8174(int *p);
int func_021C8180(int *p);
int func_021C818C(u8 *p, int v);
u16 func_021C81C8(BtlServerFlow *flow, u8 *x, int flag);
u16 func_021C81D0(BtlServerFlow *flow, u8 *a, u32 y);
int func_021C8234(BtlServerFlow *flow, int i);
int func_021C824C(BtlServerFlow *flow, int v);
int func_021C8288(BtlServerFlow *flow);
int func_021C8290(BtlServerFlow *flow, int a, int b, void *item);
int func_021C82B8(BtlServerFlow *flow, int z);
int func_021C82C4(int a, int b, int c);
int func_021C82D0(int unused, unsigned int v, int k);
int func_021C82F4(int a, int b, int c);
u32 func_021C8300(int *p, u8 k);
unsigned int func_021C830C(u8 *p);
void func_021C831C(u8 *p, int v);
int func_021C8338(BtlServerFlow *flow, int i);
int func_021C8348(BtlServerFlow *flow, int i);
int func_021C8374(BtlServerFlow *flow, int i);
u32 func_021C83A0(u8 *p, int i);
u32 func_021C83CC(BtlServerFlow *flow);
int func_021C83D4(BtlServerFlow *flow);
void func_021C83DC(char *p, int x);
int func_021C83E8(unsigned char *p, int i, int b);
void func_021C8408(u8 *p, int a);
void func_021C8434(u8 *p, int a, int b);
int func_021C846C(BtlServerFlow *flow, int a, int b, int *out);
void func_021C8494(BtlServerFlow *flow, int i);
int func_021C84AC(BtlServerFlow *flow, u8 *a, u8 *out);
void func_021C84D0(BtlServerFlow *flow, u8 *a);
int func_021C84D8(u8 *p);
void func_021C84E0(BtlServerFlow *flow, unsigned int v);
void func_021C84E8(BtlServerFlow *flow);
void func_021C84F4(BtlServerFlow *flow, unsigned int v);
int func_021C8534(BtlServerFlow *flow);
void func_021C8588(BtlServerFlow *flow);
void func_021C859C(BtlServerFlow *flow);
void func_021C85B8(BtlServerFlow *flow);
void func_021C85D4(BtlServerFlow *flow, int index, int clear);
void func_021C8810(u8 *p);
u32 func_021C8828(u8 *p);
void func_021C8838(void *p, int a, int b);
void func_021C8860(struct S_p12 *p, u32 val);
void func_021C888C(u8 *p, u32 v);
void *func_021C88A4(BtlServerFlow *flow, int a, int b);
void func_021C88B4(BtlServerFlow *flow, int k, int b);
void func_021C88C8(BtlServerFlow *flow, void *b);
int func_021C88E4(BtlServerFlow *flow);
int func_021C8910(BtlServerFlow *flow);
void func_021C8918(BtlServerFlow *flow, void *cmd);
u8 func_021C8C6C(BtlServerFlow *flow, BtlCmd *e);
u8 func_021C8CBC(BtlServerFlow *flow, Ent_021C8CBC *e);
u8 func_021C8D0C(BtlServerFlow *flow, Ent_021C8D0C *e);
u8 func_021C8D2C(BtlServerFlow *flow, const Ent_021C8D2C *e, int c);
u8 func_021C8DE4(BtlServerFlow *flow, const Ent_021C8DE4 *e, int unused);
u8 func_021C8E58(BtlServerFlow *flow, const Ent_021C8E58 *e);
u8 func_021C8F24(BtlServerFlow *flow, const Ent_021C8F24 *e);
u8 func_021C8FA4(BtlServerFlow *flow, const Ent_021C8FA4 *e, int unused);
u8 func_021C9010(BtlServerFlow *flow, const Ent_021C9010 *e, int unused);
u8 func_021C9068(BtlServerFlow *flow, const Ent_021C9068 *e, u16 arg);
u8 func_021C9178(BtlServerFlow *flow, const Ent_021C9178 *e);
u8 func_021C9250(BtlServerFlow *flow, const Ent_021C9250 *e, u16 arg);
u8 func_021C9394(BtlServerFlow *flow, const Ent_021C9394 *e);
u8 func_021C9448(BtlServerFlow *flow, u8 *e);
u8 func_021C947C(BtlServerFlow *flow, const Ent_021C9448 *e);
u8 func_021C94C8(BtlServerFlow *flow, const Ent_021C94C8 *e);
u8 func_021C95D0(BtlServerFlow *flow, const Ent_021C95D0 *e);
u8 func_021C962C(BtlServerFlow *flow, const Ent_021C962C *e);
u8 func_021C96D4(BtlServerFlow *flow, struct Cmd_021C96D4 *c);
u8 func_021C9728(BtlServerFlow *flow, u8 *q);
u8 func_021C9750(BtlServerFlow *flow, u8 *q);
u8 func_021C9778(BtlServerFlow *flow, u8 *q);
u8 func_021C97A4(BtlServerFlow *flow, u8 *q);
u8 func_021C97D0(BtlServerFlow *flow, const struct Cmd_021C97D0 *c);
u8 func_021C9828(BtlServerFlow *flow, u8 *s);
u8 func_021C9898(BtlServerFlow *flow, u8 *q);
u8 func_021C98C4(BtlServerFlow *flow, u8 *q);
u8 func_021C98E4(BtlServerFlow *flow, struct Cmd_021C98E4 *c);
int func_021C99A0(BtlServerFlow *flow, const struct Msg *m);
u8 func_021C9A24(BtlServerFlow *flow, const struct Cmd_021C9A24 *q);
u8 func_021C9A60(BtlServerFlow *flow, const Ent_021C9A60 *e);
u8 func_021C9BB8(BtlServerFlow *flow, const Ent_021C9BB8 *e);
u8 func_021C9CC0(BtlServerFlow *flow, const Ent_021C9CC0 *e);
u8 func_021C9DCC(BtlServerFlow *flow, u8 *q);
u8 func_021C9DE8(BtlServerFlow *flow, struct Cmd_021C9DE8 *c);
u8 func_021C9E3C(BtlServerFlow *flow, struct Cmd_021C9E3C *c);
u8 func_021C9ECC(BtlServerFlow *flow, struct Cmd_021C9ECC *c);
u8 func_021C9F0C(BtlServerFlow *flow, const struct Cmd_021C9F0C *c);
u8 func_021C9F4C(BtlServerFlow *flow, u8 *q);
u8 func_021C9F6C(BtlServerFlow *flow, u8 *q);
u8 func_021CA128(BtlServerFlow *flow, struct Bits_p13 *q);
u8 func_021CA158(BtlServerFlow *flow, struct Cmd_021CA158 *c);
u8 func_021CA1D0(BtlServerFlow *flow, const struct Cmd_021CA1D0 *c);
u8 func_021CA248(BtlServerFlow *flow, const u8 *q);
u8 func_021CA270(BtlServerFlow *flow, const struct Cmd_021CA248 *c);
u8 func_021CA2E8(BtlServerFlow *flow, const u8 *q);
u8 func_021CA318(BtlServerFlow *flow, const struct Q_021C95D0 *q);
u8 func_021CA370(BtlServerFlow *flow, const u8 *q);
u8 func_021CA394(BtlServerFlow *flow, const u8 *q);
u8 func_021CA3AC(BtlServerFlow *flow, const u8 *q);
u8 func_021CA3D0(BtlServerFlow *flow, u8 *q);
u8 func_021CA47C(BtlServerFlow *flow, struct Cmd_021CA2E8 *q);
u8 func_021CA570(BtlServerFlow *flow, u8 *q);
u8 func_021CA5CC(BtlServerFlow *flow, const struct Cmd *q);
u8 func_021CA6C4(BtlServerFlow *flow, const u8 *q);
u8 func_021CA6FC(BtlServerFlow *flow, const u8 *q);
u8 func_021CA738(BtlServerFlow *flow, void *unused);
u8 func_021CA748(BtlServerFlow *flow, const struct Q_021CA5CC *q);
u8 func_021CA7C4(BtlServerFlow *flow, u8 *cmd);
u8 func_021CA7D4(BtlServerFlow *flow, void *cmd);
int func_021CA7F4(BtlServerFlow *flow, u8 *a, u8 b, const u8 *q, void *out);
int func_021CA8F8(BtlServerFlow *flow, u8 *a, int unused, u8 *q, int id, void *out);
u8 func_021CAA24(BtlServerFlow *flow, u8 *q, int m, u8 n, u8 value);
int func_021CAA58(BtlServerFlow *flow, u8 *a, u8 move, u8 *q, int id, void *out);
int func_021CACF4(BtlServerFlow *flow, u8 *a, u8 move, u8 *q, long id, void *out);
int func_021CAFD8(BtlServerFlow *flow, u32 mode, void *m, const u16 *item, u8 self, void *out);
void *func_021CB174(BtlServerFlow *flow, u8 n, int k);
void *func_021CB1A4(BtlServerFlow *flow, u8 n);
u8 func_021CB1D4(BtlServerFlow *flow, u8 *a, u8 *b, u32 d);
u8 func_021CB214(BtlServerFlow *flow, u8 *a, u8 *b);
u8 func_021CB274(BtlServerFlow *flow, u8 *a, u8 *b, u32 d);
void func_021CB2D4(BtlServerFlow *flow, u8 *a, u32 b, Rec_021CAA58 *rec);
u32 func_021CB55C(void *p, u32 a, u16 b, u16 c);
void func_021CB5F0(u32 *a0, u8 *a1, u8 *a2);
int func_021CB730(BtlServerFlow *flow, u8 *a, u16 move, u8 arg, u8 slot);
int func_021CBA40(BtlServerFlow *flow, void *a, u16 b);
int func_021CBB34(BtlServerFlow *flow, void *q, void *m, u16 mode, u8 *out, u8 *flag);
u32 func_021CBCF4(BtlServerFlow *flow);
int func_021CBD48(BtlServerFlow *flow, void *unused, void *q, int k);
int func_021CBEA8(BtlServerFlow *flow, int x);
void func_021CBF30(BtlServerFlow *flow, void *b, int c, int d);
void func_021CBF40(BtlServerFlow *flow, void *b, int c, int d);
void func_021CBF50(BtlServerFlow *flow, void *b, int c, int d);
void func_021CBF60(BtlServerFlow *flow, void *b, int c, int d);
void func_021CBF70(BtlServerFlow *flow, void *b, int c, int d);
void func_021CBF80(BtlServerFlow *flow, void *b, int c, int d);
void func_021CBF90(BtlServerFlow *flow, void *b, int c, int d);
int func_021CBFA0(BtlServerFlow *flow, u8 *q);
int func_021CC008(BtlServerFlow *flow, u8 *q, u16 s);
void func_021CC098(BtlServerFlow *flow, void *b, int c, u8 d);
void func_021CC0A8(BtlServerFlow *flow, void *b, int c, u8 d);
void func_021CC0B8(BtlServerFlow *flow, void *b, int c, u8 d);
void func_021CC0C8(BtlServerFlow *flow, void *b, int c, u8 d);
void func_021CC0D8(BtlServerFlow *flow, void *b, int c, u8 d);
void func_021CC0E8(BtlServerFlow *flow, void *b, int c, u8 d);
int func_021CC0F8(char *p, void *m, int c, int n);
int func_021CC178(BtlServerFlow *flow, void *m, void *s, int d, u8 n);
int func_021CC214(BtlServerFlow *flow, void *m, void *s);
int func_021CC2C0(BtlServerFlow *flow, void *m, void *s);
int func_021CC350(BtlServerFlow *flow, void *m, int c, int d, u32 v);
int func_021CC398(BtlServerFlow *flow, void *m, int c, int d, u32 v);
int func_021CC438(BtlServerFlow *flow, void *m, int c, u8 d, u32 e);
u8 func_021CC4AC(BtlServerFlow *flow, void *m);
int func_021CC508(BtlServerFlow *flow, void *m);
int func_021CC558(BtlServerFlow *flow, void *m);
int func_021CC5F4(BtlServerFlow *flow, void *m);
int func_021CC668(u8 *p);
int func_021CC768(void *a, u8 *p, u8 *q, int want);
void func_021CC800(u8 *a, u32 *out1, u32 *out2, u8 want);
void func_021CC8A0(u32 *p);
void func_021CC8B0(u32 *p, u32 i, u32 b);
u32 func_021CC8B8(u32 *p, u32 i);
u32 func_021CC8C0(u32 *p, u32 i);
void func_021CC8C8(u32 *p);
u32 func_021CC8D8(void *lock, int line);
u32 func_021CC918(Bf_td *p, u32 v, int unused);
void func_021CC95C(u32 *p, u32 v, int line);
unsigned short func_021CC960(struct S_p14 *p);
int func_021CC96C(struct Q9 *p);
void func_021CC974(Word_021CC768 *p,int flag);
int func_021CC99C(struct Q10 *p);
u32 func_021CC9A4(u32 *p);
struct Rec_p14 *func_021CC9AC(struct Pack *p, int id, int b);
void func_021CCA74(QueueA *p,QueueB *q);
void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
u16 BTL_SERVER_CMD_Reserve(Buf_021CC768 *w, u32 id);
void BTL_SERVER_CMD_FillReserved(Buf_021CC768 *w, u16 x, u32 id, ...);
void BTL_SERVER_CMD_WriteU8Wrapper(void *p, u8 v);
void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);
extern const u8 data_021EFCF0[4];
extern u8 d_021EFCF4[2][3];
extern u8 d_021EFCFA[2][3];
extern struct Unk021EFD70 data_021EFD70[];
extern u8 d_021F3A60[];
extern u8 d_021F3A70[];
extern const u16 d_021EFDB8[3];
extern u32 d_021F3B2C[];
extern u8 d_021F3B20[];
extern u8 *d_021F3B38[];
extern u16 d_021F3B26[];
extern u8 d_021F3B23[];
extern u32 d_021F3B20b[];
extern struct T6 g_021EFDC0[];
extern const Entry_021CAA58 data_021EFDE4[];
extern struct SizeEntry d_021EFE9C[0x3B];
extern char data_021F3A84[];
extern const u8 data_021EFF14[];
extern s32 data_021F3B44[];
extern u8 d_021F3A88[];
extern const Entry_021CC768 d_021EFFEC[15];
extern const u16 d_021EFF78[4];
extern const struct Row d_021EFFC2[4];
extern const CodeEntry d_021F00DC[];
extern Pair16 d_021EFFAE[5];
extern u16 d_021EFF88[];
extern union DView d_021F3B64;
extern struct StateData g_021F3B64;
extern const u16 d_021EFF80[];














BtlServerFlow *flow(void *a, void *b, void *c, void *d, int e, u16 heap)
{
    BtlServerFlow *flowB;
    flowB = func_02030734(heap, 0x212c, 1, (const char *)d_021F3A70, 0x245);
    flowB->server = a;
    flowB->pokeCon = c;
    flowB->mainModule = b;
    flowB->numActOrder = 0;
    flowB->turnCount = 0;
    flowB->flowResult = 0;
    flowB->cmdQueue = d;
    flowB->heapId = heap;
    flowB->bagMode = e;
    flowB->evolutionHandle = SHINKA_CHECK_OpenHandle(heap);
    BTL_SERVER_FLOW_InitState(flowB);
    return flowB;
}














void BTL_SERVER_FLOW_Reset(BtlServerFlow *flow)
{
    BTL_SERVER_FLOW_InitState(flow);
}












/*
 * Lever: the four flag clears are typed bitfield assignments, emitting bics.
 * BTL_SERVER_FLOW_ClearPendingCounter leaves its input in r0 for the following func_06898BFC.
 */
void BTL_SERVER_FLOW_InitState(BtlServerFlow *flow)
{
    BTL_EVENT_InitFactorList();
    BTL_FIELD_ResetStatic(0);
    func_0689CFF0(flow->turnRecord);
    func_0689D118(flow->historyList);
    func_0689D1FC(flow->posPoke, flow->mainModule, flow->pokeCon, BTL_MAIN_GetRule(flow->mainModule));
    func_02082BCC(flow->pokeFlagsA, 0, 0x18);
    func_02082BCC(flow->pokeFlagsB, 0, 0x18);
    func_02082BCC(flow->slotFlags, 0, 4);
    func_02082BCC(flow->actOrderScratch, 0, 0x2a0);
    func_021C7C18(flow->turnDeadRecord);
    func_021C8588(flow);
    BTL_CLIENT_SET_Clear(flow->slotTable);
    func_021CC8C8(&flow->lock);
    func_06898BFC(BTL_SERVER_FLOW_ClearPendingCounter((char *)flow->eventParamBuf));
    flow->chainCount = 0;
    flow->unusedByte = 0;
    ((Flags_td *)&flow->stateFlags)->a = 0;
    ((Flags_td *)&flow->stateFlags)->b = 0;
    ((Flags_td *)&flow->stateFlags)->c = 0;
    flow->initDone = 0;
    flow->lastPokeId = 31;
    flow->lastActionId = 0;
    flow->chosenSlot = 6;
    flow->actionCounter = 0;
    flow->onceFlag = 0;
    flow->serialNumber = 0;
    ((Flags_td *)&flow->stateFlags)->d = 0;
}











void BTL_SERVER_FLOW_Destroy(u8 *p)
{
    ARC_TOOL_DeleteHandle(((struct Obj21039 *)p)->f4A4);
    func_020307B0(p);
}












int BTL_SERVER_FLOW_RunBattleStart(BtlServerFlow *flow)
{
    u8 *initial;
    u32 i;
    int result;
    void *m;
    u32 *out = flow->cmdQueue;
    out[0] = 0;
    result = 0;
    out[1] = 0;
    initial = (u8 *)BTL_MAIN_GetFieldSituation((char * *)(flow->mainModule));
    if (initial[8] && BTL_SERVER_FLOW_TryChangeWeather(flow, initial[8], 255)) result = 1;
    for (i = 0; i < 4; i++) {
        u8 *q = BTL_SERVER_GetClientIfUsed(flow->server, (u8)i);
        if (q) {
            u32 j;
            for (j = 0; j < q[9]; j++) {
                m = (void *)func_021B9BF0(((struct Obj09958 *)q)->f4, (u8)j);
                if (m && !BTL_POKEPARAM_IsFainted(m)) BTL_SERVER_FLOW_ProcMemberInCore(flow, i, j, j);
            }
            if (BTL_MAIN_GetRule(flow->mainModule) == 3) {
                for (j = 0; j < 3; j++) {
                    m = (void *)func_021B9BF0(((struct Obj09958 *)q)->f4, (u8)j);
                    if (m && !BTL_POKEPARAM_IsFainted(m)) BTL_MAIN_RegisterZukanSeen(flow->mainModule, i, m);
                }
            }
        }
    }
    if (BTL_SERVER_FLOW_ProcAfterMemberIn(flow)) result = 1;
    return result;
}













void BTL_SERVER_FLOW_ResetInitState(u8 *p)
{
    p[0x77c] = 0;
    p[0x783] = 0;
}











int BTL_SERVER_FLOW_StartTurn(BtlServerFlow *flow, int a)
{
    int *q;
    u32 i;

    flow->flowResult = 0;
    q = flow->cmdQueue;
    q[0] = 0;
    q[1] = 0;
    if (flow->initDone == 0) {
        func_021C84E8(flow);
        func_0689D134(flow->historyList);
        for (i = 0; i < 4; i++)
            flow->onceFlags[i] = 0;
        BTL_EVENT_ClearSuspendedFlags();
        BTL_SERVER_ClearPokeChangeRequests((u8 *)(flow->server));
        BTL_EVENT_ResetVarStackIfUsed();
        BTL_SERVER_FLOW_ProcTurnStartEvents(flow);
        flow->numActOrder = BTL_SERVER_FLOW_BuildActionOrder(flow, (u8 *)a, flow->actOrder, 6);
        flow->initDone = 1;
    }
    flow->actOrderIndex = BTL_SERVER_FLOW_RunActionOrder(flow, flow->actOrderIndex);
    return flow->flowResult;
}










void BTL_SERVER_FLOW_ProcTurnStartEvents(BtlServerFlow *flow)
{
    u32 it;
    u8 *x;
    u32 n;

    BTL_SERVER_FLOW_InitFieldPokeIter((u8 *)&it, (u8 **)flow);
    if (BTL_SERVER_FLOW_NextFieldPokeIter((u8 *)&it, (u8 **)flow, &x) != 0) {
        n = 12;
        do {
            if (BTL_POKEPARAM_TestContFlag((struct UtilWork *)x, n) != 0)
                BTL_SERVER_FLOW_ClearContFlag(flow, x, n);
        } while (BTL_SERVER_FLOW_NextFieldPokeIter((u8 *)&it, (u8 **)flow, &x) != 0);
    }
}











void BTL_SERVER_FLOW_ResetInitStateAfterSelect(u8 *p)
{
    p[0x77c] = 0;
}











int BTL_SERVER_FLOW_StartAfterPokeSelect(BtlServerFlow *flow, int a)
{
    int *q;

    flow->flowResult = 0;
    q = flow->cmdQueue;
    q[0] = 0;
    q[1] = 0;
    if (flow->initDone == 0) {
        BTL_SERVER_ClearPokeChangeRequests((u8 *)(flow->server));
        BTL_EVENT_ResetVarStackIfUsed();
        flow->unusedFlag = 0;
        flow->initDone = 1;
        if (BTL_SERVER_FLOW_ProcPokeChangeActions(flow, (u8 *)a) != 0) {
            flow->flowResult = 3;
            return 3;
        }
    }
    flow->actOrderIndex = BTL_SERVER_FLOW_RunActionOrder(flow, flow->actOrderIndex);
    return flow->flowResult;
}











void BTL_SERVER_FLOW_ResetInitStateAfterChange(u8 *p)
{
    p[0x77c] = 0;
}











int BTL_SERVER_FLOW_StartAfterPokeChange(BtlServerFlow *flow, int a)
{
    int *q;
    u32 i;
    int saved;
    int ret;

    flow->flowResult = 0;
    q = flow->cmdQueue;
    q[0] = 0;
    q[1] = 0;
    if (flow->initDone == 0) {
        BTL_SERVER_ClearPokeChangeRequests(flow->server);
        BTL_EVENT_ResetVarStackIfUsed();
        saved = func_0689D174(flow->historyList, 0);
        flow->numActOrder = BTL_SERVER_FLOW_BuildActionOrder(flow, (u8 *)a, flow->actOrder, 6);
        flow->actOrderIndex = 0;
        for (i = 0; i < flow->numActOrder; i++) {
            if (flow->actOrder[i].b.small.type == 3 && flow->actOrder[i].b.small.z == 0) {
                if (BTL_POKEPARAM_IsFainted((void *)flow->actOrder[i].a) == 0) {
                    BTL_SERVER_FLOW_ProcMemberChange(flow, (u8 *)flow->actOrder[i].a, flow->actOrder[i].b.small.move);
                    flow->actOrder[i].done = 1;
                }
            }
        }
        for (i = 0; i < flow->numActOrder; i++) {
            if (flow->actOrder[i].b.small.type == 3 && flow->actOrder[i].b.small.z == 0) {
                if (BTL_POKEPARAM_IsFainted((void *)flow->actOrder[i].a) != 0) {
                    BTL_SERVER_FLOW_ProcMemberIn(flow, flow->actOrder[i].d, flow->actOrder[i].b.small.select, flow->actOrder[i].b.small.move, 1);
                    flow->actOrder[i].done = 1;
                }
            }
        }
        if (BTL_MAIN_GetRule(flow->mainModule) == 3) {
            for (i = 0; i < flow->numActOrder; i++) {
                if (flow->actOrder[i].b.small.type == 6 && flow->actOrder[i].b.small.z == 0)
                    BTL_SERVER_FLOW_ProcAction(flow, &flow->actOrder[i]);
            }
        }
        flow->initDone = 1;
    }
    BTL_SERVER_FLOW_ProcAfterMemberIn(flow);
    BTL_SERVER_FLOW_ProcFaintRewards(flow);
    BTL_SERVER_FLOW_CollectChangeRequests(flow, flow->pokeIdBuf);
    ret = 0;
    if (saved == func_0689D174(flow->historyList, 0)) {
        BTL_SERVER_FLOW_ProcTripleShift(flow);
        return ret;
    }
    if (BTL_SERVER_FLOW_CheckShowdown(flow) == 0) {
        BTL_SERVER_FLOW_ProcClientMemberChange(flow, flow->pokeIdBuf);
        return 2;
    }
    return 4;
}







u32 BTL_SERVER_FLOW_RunActionOrder(BtlServerFlow *flow, u32 i)
{
    u32 previous = 0;
    for (; i < flow->numActOrder; i++) {
        u32 current = BTL_CALC_ActionGetKind(&flow->actOrder[i].b);
        u8 stop;
        if (previous == 6 && current != 6) {
            BTL_SERVER_FLOW_NotifyRotationEnd(flow);
            BTL_SERVER_FLOW_ResortActionOrder(flow, &flow->actOrder[i], flow->numActOrder - i);
        }
        previous = BTL_SERVER_FLOW_ProcAction(flow, &flow->actOrder[i]);
        stop = BTL_SERVER_FLOW_ProcFaintRewards(flow);
        if ((u8)BTL_SERVER_FLOW_CheckShowdown(flow)) { flow->flowResult = 4; return i + 1; }
        if (flow->flowResult == 6) return i + 1;
        if (flow->flowResult == 1) return i + 1;
        if (stop) { flow->flowResult = 3; return i + 1; }
    }
    if (flow->flowResult == 0) {
        u8 stop = BTL_SERVER_FLOW_ProcTurnCheck(flow);
        int present;
        if ((u8)BTL_SERVER_FLOW_CheckShowdown(flow)) { flow->flowResult = 4; return flow->numActOrder; }
        if (stop) { flow->flowResult = 3; return flow->numActOrder; }
        present = func_0689D174((u8 *)flow->historyList, 0);
        if (func_021C8534(flow) || present) {
            BTL_SERVER_FLOW_CollectChangeRequests(flow, (u8 *)flow->pokeIdBuf);
            BTL_SERVER_FLOW_ProcClientMemberChange(flow, (u8 *)flow->pokeIdBuf);
            flow->flowResult = 2;
            return flow->numActOrder;
        }
        flow->flowResult = 0;
    }
    return flow->numActOrder;
}









static inline void set_accuracy(Entry *e, u16 v)
{
    e->c = (v & 0x1fff) | (e->c & 0xffffe000);
}









static inline u32 pack(u16 low, u8 a, u8 b, u8 c)
{
    return (low & 0x1fff) | (((u16)(a << 13)) | ((((u32)(u16)(c << 13) << 9)) | (((u32)b & 63) << 16)));
}









static inline void update(Entry *e, int result)
{
    u16 low = (u16)(e->c & 0x1fff);
    u8 a = (e->c >> 13) & 7;
    u8 c = (e->c >> 22) & 7;
    e->c = pack(low, a, result, c);
}









void BTL_SERVER_FLOW_ResortActionOrder(BtlServerFlow *flow, Entry *e, u32 n)
{
    u32 i;
    u32 off;
    u32 type;
    u16 value;
    u32 lock;
    int result;
    Entry *q;
    for (i = 0; i < n; i++) {
        off = i * 16;
        q = &e[i];
        set_accuracy(q, BTL_SERVER_FLOW_CalcPokeSpeed(flow, ENTRY(i)->a, 1));
        type = BTL_CALC_ActionGetKind(&q->b);
        if (type == 1) {
            if (((Entry *)e)[i].b.full.type == 1) value = ((Entry *)e)[i].b.full.move; else value = 0;
            lock = func_021CC8D8(&flow->lock, 1076);
            q = (Entry *)((u32)e + off);
            result = BTL_SERVER_FLOW_CalcMovePriority(flow, value, q->a);
            update(q, result);
            func_021CC95C(&flow->lock, lock, 1079);
        }
        if (type == 1 || type == 5) {
            lock = func_021CC8D8(&flow->lock, 1087);
            q = (Entry *)((u32)e + off);
            q->c = ((BTL_SERVER_FLOW_QueryActionAllowedEvent(flow, q->a) & 7) << 13) | (q->c & 0xffff1fff);
            func_021CC95C(&flow->lock, lock, 1090);
        }
    }
    BTL_SERVER_FLOW_SortActionOrder(e, n);
}











/*
 * BTL_SERVER_GetActionTableEntry returns a 4-byte bitfield struct: declaring it that way
 * (a u32 return with shifts and masks gives a different frame) is what
 * matches.
 */
int BTL_SERVER_FLOW_ProcPokeChangeActions(BtlServerFlow *flow, u8 *o)
{
    u32 i;
    u32 j;
    u32 n;
    Action v;

    for (i = 0; i < 4; i++) {
        if (BTL_SERVER_GetClientChecked((u8 *)((int)flow->server), (u8)i) != 0) {
            n = BTL_SERVER_GetActionTableValue(o, i);
            for (j = 0; j < n; j++) {
                v = BTL_SERVER_GetActionTableEntry(o, i, j);
                if (v.small.type == 3 && v.small.z == 0)
                    BTL_SERVER_FLOW_ProcMemberIn(flow, i, v.small.select, v.small.move, 1);
            }
        }
    }
    BTL_SERVER_FLOW_ProcAfterMemberIn(flow);
    return BTL_SERVER_FLOW_ProcFaintRewards(flow);
}











int BTL_SERVER_FLOW_CheckShowdown(BtlServerFlow *flow)
{
    u8 f[2];
    u32 i;

    f[1] = 0;
    f[0] = f[1];
    for (i = 0; i < 4; i++) {
        if (BTL_MAIN_IsClientUsed(flow->mainModule, i) != 0) {
            char *q = func_021B9AEC(flow->pokeCon, i);
            u8 k = BTL_MAIN_GetClientSide((int)(flow->mainModule), (u8)i);

            if (func_021B9B98((u8 *)q) != 0)
                f[k] = 1;
        }
    }
    if (f[0] == 0 || f[1] == 0)
        return 1;
    return 0;
}










int BTL_SERVER_FLOW_CheckPlayerSideAlive(BtlServerFlow *flow)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        if (BTL_MAIN_IsClientUsed(flow->mainModule, i) != 0) {
            u8 a = BTL_MAIN_GetClientSide((int)(flow->mainModule), (u8)i);
            u8 b = BTL_MAIN_GetClientSide((int)(flow->mainModule), (u8)func_021B8FF4(flow->mainModule));

            if (a == b) {
                if (func_021B9B98((u8 *)func_021B9AEC(flow->pokeCon, i)) != 0)
                    return 1;
            }
        }
    }
    return 0;
}









/*
 * extent: two zero alignment bytes at 0x021BC38E, then BTL_SERVER_FLOW_RunBagModeSetup.
 * Lever: bind the first call result before initializing the boolean result.
 */
int BTL_SERVER_FLOW_RunEscapeFromLead(BtlServerFlow *flow)
{
    u8 *a;
    u32 side;
    int result;
    u32 *out;
    side = func_021B8FF4(flow->mainModule);
    result = 0;
    a = func_021B990C(flow->pokeCon, side, 0);
    out = flow->cmdQueue;
    out[0] = 0;
    out[1] = 0;
    if (BTL_SERVER_FLOW_ProcEscape(flow, a)) result = 1;
    return result;
}









/*
 * extent: two zero alignment bytes at 0x021BC3AE, then matched BTL_SERVER_FLOW_PushBagModePositions.
 */
int BTL_SERVER_FLOW_RunBagModeSetup(BtlServerFlow *flow)
{
    int result = 0;
    u32 *out = flow->cmdQueue;
    out[0] = 0;
    out[1] = 0;
    BTL_SERVER_FLOW_PushBagModePositions(flow);
    if (*(u32 *)flow->cmdQueue) result = 1;
    return result;
}








void BTL_SERVER_FLOW_PushBagModePositions(BtlServerFlow *flow)
{
    u32 i;
    u8 x[4];
    u32 v;

    if (flow->bagMode == 1) {
        for (i = 0; i < 4; i++) {
            if (BTL_SERVER_IsClientUsed(flow->server, i) != 0) {
                if (BTL_MAIN_GetRule(flow->mainModule) != 2)
                    v = 1;
                else
                    v = func_0689D558(flow->posPoke, i, x) + 1;
                BTL_SERVER_CMD_Push(flow->cmdQueue, 0x29, (u8)i, (u8)v);
            }
        }
    }
}














void BTL_SERVER_FLOW_ProcRotation(BtlServerFlow *flow, int a, u8 b)
{
    u8 *t;
    u8 *v1;
    u8 *v2;
    int k;

    if (b == 1)
        return;
    if (b == 0)
        return;
    t = (u8 *)func_021B9AEC((char *)(flow->pokeCon), a);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x48, a, b);
    func_021B9C50((u8 **)t, b, &v1, &v2);
    if (BTL_POKEPARAM_IsFainted(v1) == 0)
        BTL_SERVER_FLOW_ProcPokeLeaveField(flow, v1, 1);
    if (BTL_POKEPARAM_IsFainted(v2) == 0) {
        if (BTL_FIELD_GetStaticSlotObject(2) != 0) {
            k = 0x20;
            if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)v2, k) != 0)
                BTL_SERVER_FLOW_CureSick(flow, v2, k, 0);
            k = 0x1e;
            if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)v2, k) != 0)
                BTL_SERVER_FLOW_CureSick(flow, v2, k, 0);
        }
        BTL_CALC_EnableAbilityHandlers(v2);
        BTL_HANDLER_ITEM_EnablePokeFactors(v2);
    }
    func_0689D338(flow->posPoke, b, a, v2, flow->pokeCon);
}














int BTL_SERVER_FLOW_CollectChangeRequests(BtlServerFlow *flow, u8 *out)
{
    u8 buf[4];
    u8 i;
    u8 n;
    u8 j;
    int ok = 0;
    *out = 0;
    for (i = 0; i < 4; i++) {
        n = func_0689D558(flow->posPoke, i, buf);
        if (n != 0) {
            for (j = 0; j < n; j++)
                BTL_SERVER_AddPokeChangeRequest(flow->server, buf[j]);
            ok = 1;
            out[(*out)++ + 1] = i;
        }
    }
    return ok;
}














u8 *BTL_SERVER_FLOW_GetSlotTable(BtlServerFlow *flow)
{
    return flow->slotTable;
}














u8 BTL_SERVER_FLOW_GetChosenSlot(BtlServerFlow *flow)
{
    return flow->chosenSlot;
}














void BTL_SERVER_FLOW_ProcPreTurnMoveCheck(BtlServerFlow *flow)
{
    u32 lk = func_021CC8D8(&flow->lock, 1425);
    u32 i;
    for (i = 0; i < flow->numActOrder; i++) {
        u16 id;
        u8 *a;
        Entry *e;
        e = &flow->actOrder[i];
        if (e->b.full.type == 1)
            id = e->b.full.move;
        else
            id = 0;
        if (id != 0) {
            a = flow->actOrder[i].a;
            if (func_021E02DC(a, id, func_021D59B4(a, 12))) {
                BTL_SERVER_FLOW_NotifyMoveEvent(flow, a, id);
                func_021E0394(a, id);
            }
        }
    }
    func_021CC95C(&flow->lock, lk, 0x5a0);
}














u8 BTL_SERVER_FLOW_BuildActionOrder(BtlServerFlow *flow, u8 *o, Entry *e, int unused)
{
    u8 cnt;
    u32 k;
    u8 *a;
    u32 lock;
    u8 i;
    u8 j;
    u8 n;
    u32 flag;
    u8 l;
    Q_td *q;
    Entry *r;

    flag = 0;
    for (i = 0, cnt = 0; i < 4; i++) {
        q = (Q_td *)BTL_SERVER_GetClientChecked(flow->server, i);
        if (q != 0) {
            u8 r5;
            n = BTL_SERVER_GetActionTableValue(o, i);
            r5 = 0;
            for (j = 0; j < n; j++) {
                u32 t;
                r = &e[cnt];
                r->b = BTL_SERVER_GetActionTableEntry(o, i, j);
                if (BTL_ACTION_IsChangeDepleted(&r->b) != 0)
                    break;
                t = BTL_CALC_ActionGetKind(&r->b) & 0xff;
                switch (t) {
                case 6:
                    r5 = func_021B9AB0(r->b.full.select);
                    r->a = (u8 *)func_021B9BF0(q->m, (u8)r5);
                    flag = 1;
                    break;
                case 3:
                    r->a = (u8 *)func_021B9BF0(q->m, (u8)r->b.full.select);
                    r5++;
                    break;
                default:
                    r->a = (u8 *)func_021B9BF0(q->m, (u8)r5);
                    r5++;
                    break;
                }
                r->d = i;
                r->done = 0;
                r->f = 0;
                cnt++;
            }
        }
    }
    for (l = 0; l < cnt; l++) {
        u32 m = 0x1FFF;
        u8 r5;
        u32 sub;
        lock = func_021CC8D8(&flow->lock, 0x678 - 0x38);
        r = &e[l];
        a = e[l].a;
        switch (r->b.full.type) {
        case 4:
            if (BTL_MAIN_GetCompetitor((void ***)flow->mainModule) == 0 && r->d == 1) {
                r5 = 0;
            } else {
                r5 = 4;
            }
            break;
        case 3:
            r5 = 3;
            break;
        case 2:
            r5 = 2;
            break;
        case 6:
            r5 = 1;
            break;
        case 7:
            r5 = 0;
            break;
        case 5:
            r5 = 0;
            break;
        case 1:
            r5 = 0;
            break;
        case 0:
            r->c = 0x01002000;
            continue;
        case 8:
            continue;
        default:
            r5 = 0;
            break;
        }
        if (r->b.full.type == 1) {
            u16 id;
            if (((EntryAlt *)e)[l].b.full.type == 1)
                id = ((EntryAlt *)e)[l].b.full.move;
            else
                id = 0;
            sub = BTL_SERVER_FLOW_CalcMovePriority(flow, id, a);
        } else if (r->b.full.type == 5 || r->b.full.type == 7) {
            sub = 7;
        } else {
            sub = 0;
        }
        k = BTL_SERVER_FLOW_CalcPokeSpeed(flow, a, 1);
        func_021CC95C(&flow->lock, lock, 0x678);
        r->c = (k & m) | ((m + 1) | (((r5 & 7) << 22) | ((sub & 0x3f) << 16)));
    }
    BTL_SERVER_FLOW_SortActionOrder(e, cnt);
    if (flag == 0) {
        for (i = 0; i < cnt; i++) {
            r = &e[i];
            if (r->b.full.type == 1 || r->b.full.type == 5) {
                u32 lock = func_021CC8D8(&flow->lock, 0x68A);
                u32 v = BTL_SERVER_FLOW_QueryActionAllowedEvent(flow, r->a);
                r->c = (r->c & 0xFFFF1FFF) | ((v & 7) << 13);
                func_021CC95C(&flow->lock, lock, 0x68A + 3);
            }
        }
        BTL_SERVER_FLOW_SortActionOrder(e, cnt);
    }
    return cnt;
}














void BTL_SERVER_FLOW_SortActionOrder(Entry *p, u32 n)
{
    u32 i;
    u32 j;
    Entry *a;
    Entry *b;
    Entry t;
    for (i = 0; i < n; i++) {
        j = i + 1;
        if (j < n) {
            a = &p[i];
            do {
                b = &p[j];
                if (a->c <= b->c && (a->c != b->c || BTL_CALC_Random(2) != 0)) {
                    t = *a;
                    *a = *b;
                    *b = t;
                }
                j++;
            } while (j < n);
        }
    }
}














int BTL_SERVER_FLOW_CalcMovePriority(BtlServerFlow *flow, u32 x, u8 *a)
{
    u8 n = func_0201BD28(x, 6) + 7;
    u8 r;
    BTL_EVENT_PushVarFrame(1735);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, x);
    BTL_EVENT_SetVar(0x18, n);
    func_021D70F0(flow, 0x11);
    r = BTL_EVENT_GetVar(0x18);
    BTL_EVENT_PopVarFrame(1741);
    return r;
}














u16 BTL_SERVER_FLOW_CalcPokeSpeed(BtlServerFlow *flow, u8 *x, int flag)
{
    u32 r;
    int k = func_021D59B4(x, 0xc);
    int one;
    BTL_EVENT_PushVarFrame(1760);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(x));
    BTL_EVENT_SetVarReadOnly(0x2f, k);
    one = 1;
    BTL_EVENT_SetVar(0x51, 1);
    BTL_EVENT_SetVar(0x4a, 0);
    BTL_EVENT_SetVarRanged(0x35, one << 12, 410, one << 17);
    func_021D70F0(flow, 0x13);
    r = BTL_CALC_MulRatio(BTL_EVENT_GetVar(0x2f), BTL_EVENT_GetVar(0x35));
    if (BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)x) == 1 && BTL_EVENT_GetVar(0x51) != 0)
        r = r * 25 / 100;
    if (r > 10000)
        r = 10000;
    if (flag != 0 && BTL_EVENT_GetVar(0x4a) != 0)
        r = 10000 - r;
    BTL_EVENT_PopVarFrame(1792);
    return r;
}














Entry *BTL_SERVER_FLOW_FindActionByPokeId(BtlServerFlow *flow, u8 x)
{
    u32 i;
    u32 y = x;
    for (i = 0; i < flow->numActOrder; i++) {
        if (y == BTL_POKEPARAM_GetPokeId(flow->actOrder[i].a))
            return &flow->actOrder[i];
    }
    return 0;
}














Entry *BTL_SERVER_FLOW_FindNextActionByPokeId(BtlServerFlow *flow, Entry *cur, u32 x)
{
    u32 i;
    for (i = 0; i < flow->numActOrder; i++) {
        if (&flow->actOrder[i] == cur) {
            i++;
            break;
        }
    }
    for (; i < flow->numActOrder; i++) {
        if (x == BTL_POKEPARAM_GetPokeId(flow->actOrder[i].a))
            return &flow->actOrder[i];
    }
    return 0;
}














Entry *BTL_SERVER_FLOW_FindPendingActionByMove(BtlServerFlow *flow, u16 x, u32 i)
{
    for (; i < flow->numActOrder; i++) {
        if (flow->actOrder[i].done == 0 && BTL_CALC_ActionGetKind(&flow->actOrder[i].b) == 1 && x == BTL_ACTION_GetFightMove(&flow->actOrder[i].b))
            return &flow->actOrder[i];
    }
    return 0;
}














Entry *BTL_SERVER_FLOW_FindPendingMoveActionForPoke(BtlServerFlow *flow, u16 x, u8 y, u32 unused)
{
    Entry *e = BTL_SERVER_FLOW_FindPendingActionByMove(flow, x, 0);
    while (e) {
        if (func_021B9A24(y, BTL_POKEPARAM_GetPokeId(e->a)) && BTL_POKEPARAM_IsFainted(e->a) == 0)
            return e;
        e = BTL_SERVER_FLOW_FindPendingActionByMove(flow, x, (u8)(BTL_SERVER_FLOW_GetActionIndex(flow, e) + 1));
    }
    return 0;
}














/*
 * unlabelled leaf (push {r3, r4}); filed as the blocker of BTL_SERVER_FLOW_FindPendingMoveActionForPoke.
 */
int BTL_SERVER_FLOW_GetActionIndex(BtlServerFlow *flow, Entry *cur)
{
    int i;
    int n = flow->numActOrder;
    for (i = 0; i < n; i++) {
        if (&flow->actOrder[i] == cur)
            return (u8)i;
    }
    return n;
}














int BTL_SERVER_FLOW_MoveActionForward(BtlServerFlow *flow, Entry *cur, int start)
{
    int a = -1;
    int b = -1;
    int i;
    int n = flow->numActOrder;
    for (i = start; i < n; i++) {
        if (&flow->actOrder[i] == cur) {
            a = i;
            break;
        }
    }
    for (; start < n; start++) {
        if (flow->actOrder[start].done == 0) {
            b = start;
            break;
        }
    }
    if (a >= 0 && b >= 0 && a > b) {
        flow->actOrderTemp = *cur;
        for (i = a; i > b; i--)
            flow->actOrder[i] = flow->actOrder[i - 1];
        flow->actOrder[b] = flow->actOrderTemp;
        return b;
    }
    return -1;
}














void BTL_SERVER_FLOW_MoveActionToEnd(BtlServerFlow *flow, Entry *cur)
{
    int i;
    int idx = -1;
    int n = flow->numActOrder;
    for (i = 0; i < n; i++) {
        if (&flow->actOrder[i] == cur) {
            idx = i;
            break;
        }
    }
    if (idx < 0)
        return;
    flow->actOrderTemp = *cur;
    for (i = idx; i < flow->numActOrder - 1; i++)
        flow->actOrder[i] = flow->actOrder[i + 1];
    flow->actOrder[i] = flow->actOrderTemp;
}














/*
 * interface: CC8D8's own matched source returns one-word struct Lock;
 *   this caller treats all r0 bits as a raw u32, copies r0 to r6 at 021BCEA4,
 *   and forwards r6 unchanged in r1 at 021BCEB6 to CC95C (str r1,[r0]).
 *   CC8D8 returns the entire pre-mutation 32-bit word. No bit is interpreted,
 *   narrowed or changed; both line arguments and all arities are preserved.
 *   Matched BD708 uses this same scalar interface. Struct diagnostic run03
 *   adds 8 frame bytes; byte score is not the payload/effect equivalence proof.
 * lever: Union views preserve bits7..22 for the full move field and bits7..9
 *   for case3; arg is bits23..30. Wrapping arithmetic is never signed.
 * semantics: Packed word widths derive from listing shift pairs; all fields
 *   unsigned, no signed arithmetic or asserted external selector bounds.
 */
u32 BTL_SERVER_FLOW_ProcAction(BtlServerFlow *flow, Entry *e)
{
    u8 *a;
    Action b;
    u32 lock;
    if (e->done == 0) {
        a = e->a;
        b = e->b;
        func_021C859C(flow);
        e->done = 1;
        if (flow->flowResult == 5 && b.full.type != 4) goto end;
        if (BTL_POKEPARAM_IsFainted(a) != 0) goto end;
        if (b.full.type != 6 && func_0689D588(flow->posPoke, BTL_POKEPARAM_GetPokeId(a)) == 0) goto end;
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 0x21) != 0) {
            if (b.full.type != 4 || BTL_MAIN_GetCompetitorKind((unsigned int **)flow->mainModule) != 2) {
                if (func_021D69AC(a, 3) != 0) BTL_SERVER_FLOW_SetPokeCounter(flow, a, 3, 0);
                goto end;
            }
        }
        BTL_SERVER_FLOW_NotifyActionStart(flow, a, e->b.full.type);
        BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, 0);
        switch (b.full.type) {
        case 6:
            if (BTL_MAIN_GetRule((void **)flow->mainModule) == 3) BTL_SERVER_FLOW_ProcRotation(flow, e->d, (u8)b.full.select);
            break;
        case 1:
            if (flow->onceFlags[0] == 0) {
                BTL_SERVER_FLOW_ProcPreTurnMoveCheck(flow);
                flow->onceFlags[0] = 1;
            }
            flow->pendingResult = BTL_SERVER_FLOW_CheckDisobedience(flow, a);
            BTL_SERVER_FLOW_ProcFight(flow, a, &b, e->c & 0x3fffff);
            break;
        case 2:
            if (func_021CB730(flow, a, (u16)b.full.move, (u8)b.full.arg, (u8)b.full.select) == 1) {
                if (BTL_SERVER_FLOW_CommitEscape(flow, a, 1, 1)) flow->flowResult = 5;
            }
            break;
        case 3:
            BTL_SERVER_FLOW_ProcMemberChange(flow, a, (u8)b.small.move);
            BTL_SERVER_FLOW_ProcAfterMemberIn(flow);
            break;
        case 4:
            if (BTL_SERVER_FLOW_ProcEscape(flow, a)) flow->flowResult = 5;
            break;
        case 8:
            flow->flowResult = 4;
            break;
        case 5:
            BTL_SERVER_FLOW_ProcShift(flow, a);
            break;
        case 7:
            BTL_SERVER_FLOW_PushActionBlockedMessage(flow, a);
            break;
        case 0:
        default:
            break;
        }
        if (b.full.type == 1 || b.full.type == 2) {
            BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, 1);
            BTL_SERVER_FLOW_SetContFlag(flow, a, 0);
        }
        lock = func_021CC8D8(&flow->lock, 0x83b);
        BTL_SERVER_FLOW_DispatchActionEndEvent(flow, a, b.full.type);
        func_021CC95C(&flow->lock, lock, 0x83d);
    end:
        func_021C85B8(flow);
        return b.full.type;
    }
    return 0;
}













/*
 * interface: func_021CC8D8 returns its four-byte Lock in r0; use the
 * full-word payload spelling of matched caller BTL_SERVER_FLOW_ProcPreTurnMoveCheck. The entire
 * func_021CC95C body is str r1,[r0]; bx lr, retaining every payload bit.
 * Aggregate spelling added eight bytes of frame; paired fixed-flag
 * runs were DIFF (60 bytes) and EXACT (56 bytes). Calls and stores agree.
 */
void BTL_SERVER_FLOW_NotifyActionStart(BtlServerFlow *flow, u8 *a, u32 k)
{
    int line = 0x854;
    u32 old = func_021CC8D8(&flow->lock, line);
    BTL_SERVER_FLOW_DispatchActionStartEvent(flow, a, k);
    func_021CC95C(&flow->lock, old, line + 3);
}















void BTL_SERVER_FLOW_DispatchActionStartEvent(BtlServerFlow *flow, u8 *a, u32 k)
{
    int line = 0x864;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(12, k);
    func_021D70F0(flow, 1);
    BTL_EVENT_PopVarFrame(line + 4);
}















void BTL_SERVER_FLOW_DispatchActionEndEvent(BtlServerFlow *flow, u8 *a, u32 k)
{
    int line = 0x874;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(12, k);
    func_021D70F0(flow, 2);
    BTL_EVENT_PopVarFrame(line + 4);
}














/*
 * note 2026-10-05 (wD9r lane04): EXACT* (the trailing 021BD07E halfword is alignment padding). Closed
 *   with `r -= x - y; if (r < x - y) return 3;` in place of the one-expression
 *   `(u16)(r - (u16)(x - y)) < x - y`. The redefinition of r splits its live range, so the first use
 *   reloads the spilled r (`str r0,[sp]; ldr r0,[sp]`). No cast stand-in.
 * note 2026-10-05 (wD9 lane18): still DIFF 55 B (no stand-in). Reading: the first use of r must be an
 *   operation on the spilled r (the u16 to u32 widening node), not the call temp; any plain form forwards r0.
 *   Tried: a static inline u16 rnd(u32) for both random calls; operands reversed (x - y > r) in one and both
 *   compares; an int d = x - y block; r as u32 with (u16) at the def and (int)r at the compare (a real
 *   signedness cast, still forwards r0). All 55 B.
 * note 2026-10-05 (integrator): the source no longer has the (int)(u32)r stand-in cast, so it is DIFF (the plain compare drops the reload of r). With the cast it verifies EXACT*: rejected as a stand-in.
 * note: the reload `str r0,[sp]; ldr r0,[sp]` at 021BD046/021BD048 comes only
 *   from spelling the first use of r through a widening cast, `(int)(u32)r`;
 *   plain `r`, `(int)r` and u16/u32/int locals forward r0 into the compare
 *   and drop the ldr (55 bytes out), and `(u32)r` alone reloads but turns
 *   the bge into bhs.
 */
int BTL_SERVER_FLOW_CheckDisobedience(BtlServerFlow *flow, u8 *a)
{
    int k;
    u32 n;
    u16 x, y;
    if ((u32)BTL_MAIN_GetCompetitor((void ***)flow->mainModule) <= 1) {
        k = func_021B8DDC(BTL_POKEPARAM_GetPokeId(a));
        if (k == func_021B8FF4((u8 *)flow->mainModule)) {
            void *v = BTL_POKEPARAM_GetMon(a);
            if (POKE_TOOL_IsOwnedByPlayer(v, func_021B871C((char *)flow->mainModule)) == 0) {
                n = BTL_MAIN_GetBadgeCount((u8 **)flow->mainModule);
                if (n < 8) {
                    u16 r;
                    x = (u16)func_021D59B4(a, 15);
                    y = (u16)(10 * (n + 1));
                    if (x <= y) return 0;
                    if ((u16)BTL_CALC_Random(x + y + 1) < y) return 0;
                    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 2) != 0) return 4;
                    r = BTL_CALC_Random(256);
                    if (r < x - y && BTL_SERVER_FLOW_CheckObedienceOverride(flow, a) == 0) return 2;
                    r -= x - y;
                    if (r < x - y) return 3;
                    return 4;
                }
            }
        }
    }
    return 0;
}














int BTL_SERVER_FLOW_CheckObedienceOverride(BtlServerFlow *flow, u8 *a)
{
    int r;
    BTL_EVENT_PushVarFrame(2256);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarOnce(0x41, 0);
    func_021D70F0(flow, 0xe);
    r = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(2261);
    return r;
}














int BTL_SERVER_FLOW_ForceExecuteMoveAction(BtlServerFlow *flow, u8 x, u32 y)
{
    Entry *e = BTL_SERVER_FLOW_FindActionByPokeId(flow, x);
    if (e) {
        if (e->done != 0 && BTL_CALC_ActionGetKind(&e->b) == 6) {
            e = BTL_SERVER_FLOW_FindNextActionByPokeId(flow, e, x);
        }
        if (e->done == 0) {
            if (BTL_SERVER_FLOW_GetEncoredMove(e->a, &e->b)) return 0;
            if (BTL_CALC_ActionGetKind(&e->b) == 6) return 0;
            func_021D82FC(&e->b, func_0689D5C8(flow->posPoke, y));
            BTL_SERVER_FLOW_ProcAction(flow, e);
            return 1;
        }
    }
    return 0;
}











int BTL_SERVER_FLOW_PromoteActionOfPoke(BtlServerFlow *flow, u8 x)
{
    Entry *e = BTL_SERVER_FLOW_FindActionByPokeId(flow, x);
    if (e && e->done == 0) {
        if (BTL_SERVER_FLOW_MoveActionForward(flow, e, 0) >= 0) return 1;
    }
    return 0;
}











int BTL_SERVER_FLOW_PromoteActionsByMove(BtlServerFlow *flow, u16 x)
{
    int i = 0;
    int r;
    Entry *e = BTL_SERVER_FLOW_FindPendingActionByMove(flow, x, 0);
    r = 0;
    while (e) {
        i = BTL_SERVER_FLOW_MoveActionForward(flow, e, i);
        if (i < 0) break;
        i++;
        e = BTL_SERVER_FLOW_FindPendingActionByMove(flow, x, (u8)i);
        r = 1;
    }
    return r;
}











int BTL_SERVER_FLOW_DemoteActionOfPoke(BtlServerFlow *flow, u8 x)
{
    Entry *e = BTL_SERVER_FLOW_FindActionByPokeId(flow, x);
    if (e && e->done == 0) {
        BTL_SERVER_FLOW_MoveActionToEnd(flow, e);
        return 1;
    }
    return 0;
}











/* 021BD1D0  guard on a callee's pointer result, then set a byte */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; bl BTL_SERVER_FLOW_FindActionByPokeId; cmp r0, #0; beq loc_021BD1DE; movs r1, #1; strb r1, [r0, #0xd]; pop {r3, pc}.
 */
void BTL_SERVER_FLOW_MarkActionDone(BtlServerFlow *flow, u8 n)
{
    Entry *e = BTL_SERVER_FLOW_FindActionByPokeId(flow, n);
    if (e != 0)
        e->done = 1;
}











void BTL_SERVER_FLOW_InitTurnState(struct Unk021BD1E0 *p)
{
    p->f0 = 0;
    p->f2 = 6;
    p->f3 = 6;
    p->f4 = 0;
    p->b0 = 0;
    p->b1 = 0;
}











void BTL_SERVER_FLOW_SetupTurnState(struct Unk021BD1E0 *p, BtlServerFlow *flow, u8 *a, void *t)
{
    int r = func_0689CD40(t);
    p->f2 = func_0689D5C8(flow->posPoke, BTL_POKEPARAM_GetPokeId(a));
    p->f3 = 6;
    p->b0 = 0;
    p->b1 = 0;
    if (r == 1 && func_0689CD38(t)) {
        p->f3 = func_0689D5C8(flow->posPoke, BTL_POKEPARAM_GetPokeId(func_0689CC70(t, 0)));
    }
}












void BTL_SERVER_FLOW_InitFieldPokeIter(u8 *p, u8 **q)
{
    u8 i = 0;
    u8 *m;
    u8 j;
    u8 *x;
    int f;
    p[0] = i;
    p[1] = i;
    p[2] = 1;
    p[3] = i;
    for (; i < 4; i++) {
        m = BTL_SERVER_GetClientIfUsed(*q, i);
        if (m == 0) continue;
        for (j = 0; j < m[9]; j++) {
            x = func_021B9C00((struct S2 *)(*(u8 * *)&((struct Obj13305 *)m)->f4), j);
            if (x) f = BTL_POKEPARAM_IsFainted(x) == 0;
            else f = 0;
            if (f) {
                p[0] = i;
                p[2] = 0;
                p[1] = j;
                return;
            }
        }
    }
}











void BTL_SERVER_FLOW_SetFieldPokeIterRule(u8 *p, BtlServerFlow *flow)
{
    if (BTL_MAIN_GetRule(flow->mainModule) == 3) p[3] = 1;
}












int BTL_SERVER_FLOW_NextFieldPokeIter(u8 *p, u8 **q, u8 **out)
{
    u8 *m;
    u8 *x;
    u8 n;
    int f;
    if (p[2] != 0) return 0;
    *out = (u8 *)func_021B9BF0((struct S2 *)(*(u8 **)(BTL_SERVER_GetClientChecked(*q, p[0]) + 4)), p[1]);
    p[1]++;
    while (p[0] < 4) {
        m = BTL_SERVER_GetClientIfUsed(*q, p[0]);
        if (m) {
            n = p[3] == 0 ? m[9] : 3;
            for (; p[1] < n; p[1]++) {
                x = (u8 *)func_021B9BF0((struct S2 *)(*(u8 * *)&((struct Obj13306 *)m)->f4), p[1]);
                if (x) f = BTL_POKEPARAM_IsFainted(x) == 0;
                else f = 0;
                if (f) return 1;
            }
        }
        p[0]++;
        p[1] = 0;
    }
    p[2] = 1;
    return 1;
}












void BTL_SERVER_FLOW_ProcShift(BtlServerFlow *flow, u8 *a)
{
    int i;
    int r;
    i = func_021B8DDC(BTL_POKEPARAM_GetPokeId(a));
    r = func_021B9C98((u8 *)func_021B9AEC((char *)flow->pokeCon, i), (u32)a);
    if (r == 0 || r == 2) {
        BTL_SERVER_FLOW_ShiftPokes(flow, i, r, 1, 0);
        BTL_SERVER_FLOW_PushMsgSetPoke(flow, a, 0xe7);
        BTL_SERVER_FLOW_DispatchShiftEvents(flow, i, r, 1);
    }
}











void BTL_SERVER_FLOW_ShiftPokes(BtlServerFlow *flow, int i, u8 a, u8 b, int c)
{
    char *s = func_021B9AEC((char *)flow->pokeCon, i);
    int x = BTL_MAIN_GetClientTrainerIndex((u8 *)flow->mainModule, i, a);
    int y = BTL_MAIN_GetClientTrainerIndex((u8 *)flow->mainModule, i, b);
    u8 *q;
    u8 *r;
    func_0689D4F0(flow->posPoke, x, y);
    func_021B9C10((u32 *)s, a, b);
    if (c == 0) {
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x44, i, x, y);
        q = (u8 *)func_021B9BF0((struct S2 *)s, a);
        r = (u8 *)func_021B9BF0((struct S2 *)s, b);
        if (!BTL_POKEPARAM_IsFainted(q)) BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)q, 0xc);
        if (!BTL_POKEPARAM_IsFainted(r)) BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)r, 0xc);
    }
}












void BTL_SERVER_FLOW_DispatchShiftEvents(BtlServerFlow *flow, int i, u8 a, u8 b)
{
    u8 *arr;
    u8 *first;
    u8 *second;
    arr = (u8 *)func_021B9AEC((char *)flow->pokeCon, i);
    first = func_021B9C00((struct S2 *)arr, a);
    second = func_021B9C00((struct S2 *)arr, b);
    BTL_SERVER_FLOW_DispatchShiftInEventLocked(flow, first);
    BTL_SERVER_FLOW_DispatchShiftInEventLocked(flow, second);
}












/*
 * return evidence: func_021CC8D8's matched Lock is one full 32-bit word;
 *   021CC8DA loads it, 021CC900 returns that unchanged word in r0.
 *   This caller saves r0 in r4 and passes it unchanged in r1 to restore.
 *   Scalar u32 return follows matched neighbours 021BD708/021BDA00;
 *   union aggregate spelling gave a spurious 8-byte stack frame (run 1).
 */
void BTL_SERVER_FLOW_DispatchShiftInEventLocked(BtlServerFlow *flow, u8 *m)
{
    u32 old;
    if (BTL_POKEPARAM_IsFainted(m) == 0) {
        old = func_021CC8D8(&flow->lock, 2697);
        BTL_SERVER_FLOW_DispatchShiftInEvent(flow, m);
        func_021CC95C(&flow->lock, old, 2699);
    }
}












void BTL_SERVER_FLOW_DispatchShiftInEvent(BtlServerFlow *flow, u8 *m)
{
    BTL_EVENT_PushVarFrame(2712);
    BTL_EVENT_SetVar(2, BTL_POKEPARAM_GetPokeId(m));
    func_021D70F0(flow, 164);
    BTL_EVENT_PopVarFrame(2715);
}













int BTL_SERVER_FLOW_ProcEscape(BtlServerFlow *flow, u8 *a)
{
    int k = func_021B8DDC(BTL_POKEPARAM_GetPokeId(a));
    int m = func_021B8FF4((u8 *)flow->mainModule);
    int s = BTL_SERVER_FLOW_TryEscape(flow, a, 0);
    if (s) return 1;
    if (k == m) {
        func_021BA1B4((char **)flow->mainModule, 0x4e);
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 0x49, 0xffff0000);
    } else {
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x36b, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
    }
    if (k == m) {
        flow->chainCount++;
        if (flow->chainCount > 0x1e) flow->chainCount = 0x1e;
    }
    return s;
}













int BTL_SERVER_FLOW_TryEscape(BtlServerFlow *flow, u8 *a, u8 flag)
{
    int ret = 0;
    int k;
    u8 *q;
    u16 lo;
    u16 hi;
    int d;
    u32 t;
    if (BTL_MAIN_GetCompetitorKind((unsigned int **)flow->mainModule) == 0) {
        k = func_021B8DDC(BTL_POKEPARAM_GetPokeId(a));
        if (k == func_021B8FF4((u8 *)flow->mainModule)) {
            ret = BTL_SERVER_FLOW_CheckEscapeGuaranteed(flow, a);
            if (ret) flag = 1;
        } else {
            flag = 1;
        }
    } else {
        flag = 1;
        ret = 1;
    }
    if (flag == 0) {
        q = func_021B9920(flow->pokeCon, 1, 0);
        if (q) {
            lo = func_021D58A8(a, 0xc);
            hi = func_021D58A8(q, 0xc);
            if (lo <= hi) {
                d = (((int)lo << 12) / (int)hi << 7) >> 12;
                t = d + flow->chainCount * 30;
                if (BTL_CALC_Random(0x100) >= t) return 0;
            }
        }
    }
    return BTL_SERVER_FLOW_CommitEscape(flow, a, ret, 0);
}













int BTL_SERVER_FLOW_CheckEscapeGuaranteed(BtlServerFlow *flow, u8 *a)
{
    int r;
    if (BTL_POKEPARAM_IsFainted(a) == 0) {
        BTL_EVENT_PushVarFrame(2849);
        BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
        BTL_EVENT_SetVarOnce(0x51, 0);
        func_021D70F0(flow, 0xb);
        r = BTL_EVENT_GetVar(0x51);
        BTL_EVENT_PopVarFrame(2854);
        return r;
    }
    return 0;
}











int BTL_SERVER_FLOW_CommitEscape(BtlServerFlow *flow, u8 *a, int r, int z)
{
    int k = func_021B8DDC(BTL_POKEPARAM_GetPokeId(a));
    u8 f;
    if (BTL_MAIN_GetCompetitorKind((unsigned int **)flow->mainModule) == 0) {
        f = (u8)(func_021B902C(k, func_021B8FF4((u8 *)flow->mainModule)) == 0 ? 1 : 0);
        if (r == 0 && BTL_POKEPARAM_IsFainted(a) == 0) {
            u32 l;
            l = func_021CC8D8(&flow->lock, 2888);
            r = BTL_SERVER_FLOW_CheckEscapePrevented(flow, a);
            func_021CC95C(&flow->lock, l, 2890);
            if (r) return 0;
        }
        if (flow->stateFlags.bits.b2 == 0) {
            if (z == 0) {
                u32 l;
                l = func_021CC8D8(&flow->lock, 2904);
                r = BTL_SERVER_FLOW_CheckEscapeMessageSuppressed(flow, a);
                func_021CC95C(&flow->lock, l, 2906);
            } else {
                r = 0;
            }
            if (r == 0) {
                if (f != 0) {
                    if (BTL_MAIN_GetCompetitor((void ***)flow->mainModule) == 0)
                        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5c, 0x4b, 0x56a, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
                } else {
                    BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5c, 0x48, 0x56a, 0xffff0000);
                }
            }
            flow->stateFlags.raw |= 4;
        }
    } else {
        if (BTL_MAIN_GetCommPos((u8 **)flow->mainModule) != 0 && flow->stateFlags.bits.b2 == 0) {
            BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 0xc6, 0xffff0000);
            flow->stateFlags.raw |= 4;
        }
    }
    BTL_CLIENT_SET_Add((struct B *)(flow->slotTable), k);
    return 1;
}










int BTL_SERVER_FLOW_CheckEscapePrevented(BtlServerFlow *flow, u8 *a)
{
    int r;
    BTL_EVENT_PushVarFrame(2957);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarOnce(0x41, 0);
    func_0689C68C(flow, a);
    func_021D70F0(flow, 0xc);
    r = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(2963);
    return r;
}









int BTL_SERVER_FLOW_CheckEscapeMessageSuppressed(BtlServerFlow *flow, u8 *a)
{
    int r;
    BTL_EVENT_PushVarFrame(2979);
    BTL_EVENT_SetVar(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarOnce(0x51, 0);
    func_021D70F0(flow, 0xd);
    r = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(2984);
    return r;
}








void BTL_SERVER_FLOW_ProcMemberInCore(BtlServerFlow *flow, u8 i, u8 a, u8 b)
{
    char *arr;
    u8 *m;
    u8 id;
    u8 *flags;
    arr = func_021B9AEC((char *)flow->pokeCon, i);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 42, i);
    func_021B9D10((char *)flow->mainModule, (struct Arr *)arr, i);
    if (a != b) func_021B9C10((u32 *)arr, a, b);
    m = (u8 *)func_021B9BF0((struct S2 *)arr, a);
    id = BTL_POKEPARAM_GetPokeId(m);
    BTL_MAIN_RegisterZukanSeen(flow->mainModule, i, m);
    BTL_CALC_AddAbilityHandlers(m);
    BTL_HANDLER_ITEM_AddHeldItemFactor(m);
    BTL_POKEPARAM_StartTurnThreshold(m, flow->turnCount);
    BTL_POKEPARAM_ReloadAndResetEffects(m);
    flags = flow->pokeFlagsB;
    flags[id] = 1;
    if (BTL_MAIN_GetRule(flow->mainModule) == 3) {
        if ((u32)func_021B99B8(flow->mainModule, (int)i) <= a) flags[id] = 0;
    }
    BTL_SERVER_CMD_Push(flow->cmdQueue, 18, i, a, b, (u16)flow->turnCount);
    func_0689D320(flow->posPoke, BTL_MAIN_GetClientTrainerIndex((u8 *)flow->mainModule, i, a), id, flow->pokeCon);
}







/*
 * extent: 42-byte function followed by 2-byte zero alignment padding.
 */
void BTL_SERVER_FLOW_ProcMemberIn(BtlServerFlow *flow, u8 i, u8 a, u8 b, int c)
{
    BTL_SERVER_FLOW_ProcMemberInCore(flow, i, a, b);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 61, i, a, b, (u8)c);
}







/*
 * lever: enum queue offset declared after the live locals retains r7;
 * cursor declared before out places cursor at sp+8 and out at sp+4.
 */
int BTL_SERVER_FLOW_ProcAfterMemberIn(BtlServerFlow *flow)
{
    int result = 0;
    struct Cursor cursor;
    u8 *out;
    u32 lock;
    u8 *flag;
    enum Offset q = queue;
    func_0689CB3C((u8 *)flow + q);
    BTL_SERVER_FLOW_InitFieldPokeIter((u8 *)(&cursor), (u8 **)flow);
    while (BTL_SERVER_FLOW_NextFieldPokeIter((u8 *)(&cursor), (u8 **)flow, &out) != 0) {
        flag = (u8 *)flow + BTL_POKEPARAM_GetPokeId(out);
        if (flag[0x7c1] != 0) {
            func_0689CB48((u8 *)flow + q, out);
            flag[0x7c1] = 0;
        }
    }
    func_0689CF24((u8 *)flow + q, flow);
    lock = func_021CC8D8(&flow->lock, 3096);
    BTL_SERVER_FLOW_DispatchMemberInBeginEvent(flow);
    if (func_021C88E4(flow) != 0) result = 1;
    func_021CC95C(&flow->lock, lock, 3102);
    func_0689CC84((u8 *)flow + q);
    out = func_0689CC8C((u8 *)flow + q);
    while (out != 0) {
        lock = func_021CC8D8(&flow->lock, 3108);
        BTL_SERVER_FLOW_DispatchPokeEntryEvent(flow, out);
        if (func_021C88E4(flow) != 0) result = 1;
        func_021CC95C(&flow->lock, lock, 3114);
        out = func_0689CC8C((u8 *)flow + q);
    }
    lock = func_021CC8D8(&flow->lock, 3117);
    BTL_SERVER_FLOW_DispatchMemberInEndEvent(flow);
    if (func_021C88E4(flow) != 0) result = 1;
    func_021CC95C(&flow->lock, lock, 3123);
    return result;
}
























void BTL_SERVER_FLOW_DispatchPokeEntryEvent(BtlServerFlow *flow, u8 *a)
{
    BTL_EVENT_PushVarFrame(0xc43);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    func_021D70F0(flow, 0x55);
    BTL_EVENT_PopVarFrame(0xc46);
}

























void BTL_SERVER_FLOW_DispatchPokeEntryEventToType4(BtlServerFlow *flow, u8 *a)
{
    BTL_EVENT_PushVarFrame(0xc55);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_DispatchEventToType((int)flow, 0x55, 4);
    BTL_EVENT_PopVarFrame(0xc58);
}

























void BTL_SERVER_FLOW_DispatchMemberInBeginEvent(BtlServerFlow *flow)
{
    BTL_EVENT_PushVarFrame(3173);
    func_021D70F0(flow, 86);
    BTL_EVENT_PopVarFrame(3175);
}

























void BTL_SERVER_FLOW_DispatchMemberInEndEvent(BtlServerFlow *flow)
{
    BTL_EVENT_PushVarFrame(3187);
    func_021D70F0(flow, 87);
    BTL_EVENT_PopVarFrame(3189);
}

























void BTL_SERVER_FLOW_NotifyRotationEnd(BtlServerFlow *flow)
{
    u32 old;
    old = func_021CC8D8(&flow->lock, 0xc82);
    BTL_SERVER_FLOW_DispatchRotationEndEvent(flow);
    func_021CC95C(&flow->lock, old, 0xc84);
}

























void BTL_SERVER_FLOW_DispatchRotationEndEvent(BtlServerFlow *flow)
{
    BTL_EVENT_PushVarFrame(3217);
    func_021D70F0(flow, 88);
    BTL_EVENT_PopVarFrame(3219);
}

























void BTL_SERVER_FLOW_PushMemberOutCmd(BtlServerFlow *flow, u8 *a)
{
    u8 id;
    int value;
    id = BTL_POKEPARAM_GetPokeId(a);
    value = func_021B8DDC(id);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x3b, value, id);
}


























void BTL_SERVER_FLOW_ProcMemberChange(BtlServerFlow *flow, u8 *a, u8 v)
{
    u8 buf[2];
    u8 r;
    u8 *q;
    BTL_SERVER_FLOW_PushMemberOutCmd(flow, a);
    if (BTL_SERVER_FLOW_ProcMemberOut(flow, a, 0)) {
        r = func_021B8D8C(flow->mainModule, flow->pokeCon, BTL_POKEPARAM_GetPokeId(a));
        func_021B8E28(flow->mainModule, r, &buf[1], &buf[0]);
        q = flow->slotFlags;
        if (q[buf[1]] < 0xFF) q[buf[1]]++;
        BTL_SERVER_FLOW_ProcMemberIn(flow, buf[1], buf[0], v, 1);
    }
}


























int BTL_SERVER_FLOW_ProcMemberOut(BtlServerFlow *flow, u8 *a, int c)
{
    u32 n, i;
    if (c == 0) {
        n = BTL_SERVER_FLOW_ProcPursuitBeforeSwitch(flow, a);
        if (n != 0) {
            ((struct Fl *)&flow->stateFlags)->f = 1;
            for (i = 0; i < n; i++) {
                BTL_SERVER_FLOW_ForceExecuteMoveAction(flow, flow->frontOrder[i], BTL_POKEPARAM_GetPokeId(a));
                if (BTL_POKEPARAM_IsFainted(a)) break;
            }
            ((struct Fl *)&flow->stateFlags)->f = 0;
        }
    }
    if (BTL_POKEPARAM_IsFainted(a) == 0) {
        BTL_SERVER_FLOW_ProcMemberOutCore(flow, a, 0x26C);
        return 1;
    }
    return 0;
}
























void BTL_SERVER_FLOW_ProcMemberOutCore(BtlServerFlow *flow, u8 *a, u32 c)
{
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    u32 s;
    int r = func_021B8D8C(flow->mainModule, flow->pokeCon, n);
    if (r != 6) BTL_SERVER_CMD_Push(flow->cmdQueue, 0x3C, r, c);
    BTL_SERVER_FLOW_MarkActionDone(flow, n);
    s = func_021CC8D8(&flow->lock, 3327);
    BTL_SERVER_FLOW_DispatchMemberOutEvent(flow, a);
    func_021CC95C(&flow->lock, s, 3329);
    BTL_SERVER_FLOW_ProcPokeLeaveField(flow, a, 0);
    BTL_POKEPARAM_ResetEffectsOnSwitchOut(a);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x20, BTL_POKEPARAM_GetPokeId(a));
    func_0689D2F8(flow->posPoke, n);
}
























void BTL_SERVER_FLOW_DispatchMemberOutEvent(BtlServerFlow *flow, u8 *a)
{
    BTL_EVENT_PushVarFrame(3348);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    func_021D70F0(flow, 0x54);
    BTL_EVENT_PopVarFrame(3351);
}

























u16 BTL_SERVER_FLOW_GetEncoredMove(void *p, Action *m)
{
    u16 r = 0x17;
    if (BTL_POKEPARAM_HasSick(p, 0x17) && m->full.move != 0xA5) {
        r = BTLV_CORE_GetSlotValue(BTL_POKEPARAM_GetSickContRaw(p, r));
        if (r != m->full.move && BTL_POKEPARAM_GetMovePPById(p, r)) return r;
    }
    return 0;
}
























static inline void ev18(void *w, u32 x, u32 s, u32 c, u32 b, u32 i2, u32 i1)
{
    BTL_SERVER_CMD_Push(w, 0x18, x, s, c, b, i2, i1);
}
























void BTL_SERVER_FLOW_ProcFight(BtlServerFlow *flow, u8 *a, Action *act, u32 key)
{
    u8 sel;
    u32 prev;
    int chk1, chk2;
    int found;
    u8 flag;
    u8 pr;
    u16 m;
    u16 id;
    u16 id2;
    struct Out_021BDB88 o;

    prev = BTL_POKEPARAM_GetSemiInvulnerableFlag((struct UtilWork *)a);
    BTL_SERVER_FLOW_InitTurnState((struct Unk021BD1E0 *)flow->curTurnState);
    BTL_SERVER_FLOW_InitMoveQueue((struct Unk021BE518 *)flow->curDeferredQueue);
    o.c2 = 0;
    o.c4 = 6;
    m = BTL_SERVER_FLOW_GetEncoredMove(a, (Action *)act);
    if (m != 0) {
        BTL_ACTION_SetFight((struct Unk021D82D0 *)act, m, BTL_CALC_DecideMoveTarget(flow->mainModule, (int)flow->pokeCon, (int)a, m));
    }
    id = act->full.move;
    pr = BTL_POKEPARAM_FindMoveSlot((struct UtilWork *)a, id);
    id2 = id;
    sel = (u8)act->full.select;
    flag = 0;
    o.c0 = 0;
    chk1 = (u8)BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 0x19);
    chk2 = (u8)BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 0x1a);
    func_021E02DC(a, id, key);
    BTL_SERVER_FLOW_NotifyMoveStart(flow, a, id);
    if (func_021C001C(flow, a, id, (u8)((chk1 != 0 || chk2 != 0) ? 1 : flag)) != 0) goto end;
    if (BTL_SERVER_FLOW_QueryForcedMoveEvent(flow, a, id, sel, (struct O_p11 *)(&o.c2)) == 0) {
        BTL_SERVER_FLOW_PushPokeCmd59(flow, a, id);
        BTL_SERVER_FLOW_GetMoveParam(flow, id, a, (struct Out64B4 *)flow->curMoveParamBackup);
        func_021CA7F4(flow, a, sel, flow->curMoveParamBackup, flow->curTargetSet);
        BTL_SERVER_FLOW_ReducePPByEvent(flow, a, id, pr, flow->curTargetSet);
        flag = 1;
        BTL_SERVER_FLOW_ProcMoveExecuteFail(flow, a, id, 0x1a);
        goto end;
    }
    found = (u8)((o.c2 != 0) ? 1 : 0);
    if (found) {
        BTL_SERVER_FLOW_PushPokeCmd59(flow, a, id);
        BTL_SERVER_FLOW_PushMoveExecCmd(flow, a, id, sel);
        func_021E02DC(a, o.c2, key);
        id2 = o.c2;
        sel = o.c4;
    } else {
        id2 = id;
    }
    BTL_SERVER_FLOW_GetMoveParam(flow, id, a, (struct Out64B4 *)flow->curMoveParamBackup);
    if (found) {
        BTL_SERVER_FLOW_GetMoveParam(flow, id2, a, (struct Out64B4 *)flow->curMoveParam);
        ((u32 *)flow->curMoveParam)[4] |= 4;
        ((u16 *)flow->curMoveParam)[1] = id;
        if (BTL_SERVER_FLOW_CheckMoveRestricted(flow, a, (u16 *)flow->curMoveParam) != 0) {
            BTL_SERVER_FLOW_ReducePPByEvent(flow, a, id, pr, flow->curTargetSet);
            flag = 1;
            goto end;
        }
    } else {
        *(struct Cell *)flow->curMoveParam = *(struct Cell *)flow->curMoveParamBackup;
    }
    func_0689CB3C(flow->curTargetSet);
    func_0689CB3C(flow->curTargetSetWork);
    func_021CA7F4(flow, a, sel, flow->curMoveParam, flow->curTargetSet);
    {
        u32 v = (u8)func_0689CD40(flow->curTargetSet);
        func_0689CEE4(flow->curTargetSet);
        func_0689CD78(flow->curTargetSet, flow->curTargetSetWork);
        func_0689CD48(flow->curTargetSetWork, v);
    }
    if (chk1 == 0 && chk2 == 0 && pr != 4) {
        BTL_SERVER_FLOW_ReducePPByEvent(flow, a, id, pr, flow->curTargetSet);
        flag = 1;
    }
    {
        BTL_SERVER_FLOW_DispatchMoveParamEventLocked(flow, a, flow->curMoveParamBackup, 0x22);
        BTL_SERVER_FLOW_DispatchMoveTypeEvent(flow, a, flow->curMoveParam);
        if (BTL_SERVER_FLOW_QueryActionMessageEvent(flow, a, id, id2, flow->msgParam) != 0) {
            func_021C99A0(flow, (const struct Msg *)flow->msgParam);
            func_021C8810(flow->msgParam);
        } else {
            BTL_SERVER_FLOW_PushPokeCmd59(flow, a, id2);
        }
    }
    flow->lastActionId = id2;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 0x22) != 0) {
        BTL_SERVER_FLOW_CureSick(flow, a, 0x22, 0);
        BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, 0xe);
    }
    if (BTL_SERVER_FLOW_CheckMoveExecuteFailByEvent(flow, a, id2) == 0
        && func_021BE7E4(flow, a, id2, sel, (u8 *)&o) == 0
        && BTL_SERVER_FLOW_ProcPledgeCombo(flow, a, id2, sel) == 0) {
        func_0689D01C(flow->turnRecord, id2, flow->turnCount, BTL_POKEPARAM_GetPokeId(a));
        BTL_SERVER_FLOW_DispatchMoveParamEventLocked(flow, a, flow->curMoveParam, 0x23);
        if (BTL_SERVER_FLOW_CheckMoveInterrupt(flow, a, id2, flow->curTargetSetWork, flow->curInterruptQueue) != 0) {
            BTL_SERVER_FLOW_ProcInterruptMove(flow, a, id2, flow->curTargetSetWork);
        } else {
            o.c0 = func_021BEC58(flow, a, id2, flow->curTargetSetWork);
        }
    }
end:
    BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, 3);
    if (flag != 0 || chk1 != 0 || id2 == 0xa5) {
        BTL_POKEPARAM_RecordMoveUse(a, sel, o.c0, ((u8 *)flow->curMoveParam)[6], id2, id);
        ev18(flow->cmdQueue, BTL_POKEPARAM_GetPokeId(a), sel, o.c0, ((u8 *)flow->curMoveParam)[6], id2, id);
    } else if (func_021D69AC(a, 3) != 0) {
        BTL_SERVER_FLOW_SetPokeCounter(flow, a, 3, 0);
    }
    if (prev != 0x10 && BTL_POKEPARAM_GetSemiInvulnerableFlag((struct UtilWork *)a) != 0x10) BTL_SERVER_FLOW_ClearMoveLockSicks(flow, a);
    if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)a, 0xb) != 0) {
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x31, BTL_POKEPARAM_GetPokeId(a), 0);
        BTL_SERVER_FLOW_ReleaseBindingTarget(flow, a, 0);
    }
    BTL_SERVER_FLOW_NotifyMoveEnd(flow, a, id2, o.c0);
    if (o.c2 != 0) func_021E0394(a, o.c2);
    func_021E0394(a, id);
    BTL_SERVER_FLOW_ProcDeferredMoves(flow, id2);
}




























int BTL_SERVER_FLOW_CheckMoveRestricted(BtlServerFlow *flow, u8 *a, u16 *s)
{
    u16 t = *s;
    int k = 0;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 0xF) && (u32)WAZA_TOOL_GetFlag((void *)t, (int)0xC)) {
        k = 0xD;
    } else if (BTL_FIELD_GetStaticSlotObject(2) && (u32)WAZA_TOOL_GetFlag((void *)t, (int)9)) {
        k = 0x14;
    }
    if (k) {
        BTL_SERVER_FLOW_ProcMoveExecuteFail(flow, a, t, k);
        return 1;
    }
    return 0;
}




























void BTL_SERVER_FLOW_ProcDeferredMoves(BtlServerFlow *flow, u16 key)
{
    u32 i;
    u8 *a;
    u8 *b;
    u32 lock;
    for (i = 0; i < (flow->curDeferredQueue)[0]; i++) {
        a = func_021B9934(flow->pokeCon, (flow->curDeferredQueue)[i + 1]);
        b = func_021B9934(flow->pokeCon, (flow->curDeferredQueue)[i + 13]);
        if (BTL_POKEPARAM_IsAbleToBattle(a) != 0) {
            lock = func_021CC8D8(&flow->lock, 3657);
            BTL_SERVER_FLOW_DispatchDeferredMoveEvent(flow, a, b, key);
            func_021CC95C(&flow->lock, lock, 3659);
            BTL_SERVER_FLOW_GetMoveParam(flow, key, a, (struct Out64B4 *)(flow->curMoveParam));
            (((struct Out_021BE3A8*)flow->curMoveParam))->flag = 1;
            func_021CA7F4(flow, a, (flow->curDeferredQueue)[i + 7], (const u8 *)(flow->curMoveParam), flow->curEffectSet);
            BTL_EVENT_SuspendPokeFactors(BTL_POKEPARAM_GetPokeId(a));
            func_021E02DC(a, key, func_021D59B4(a, 12));
            func_021BEC58(flow, a, key, flow->curEffectSet);
            func_021E03D8(a, key);
            BTL_EVENT_ResumePokeFactors(BTL_POKEPARAM_GetPokeId(a));
        }
    }
}




























void BTL_SERVER_FLOW_InitMoveQueue(struct Unk021BE518 *p)
{
    u32 i;
    p->f0 = 0;
    for (i = 0; i < 6; i++) p->f1[i] = 0x1F;
}



























/*
 * evidence: Each byte store may alias p[0], so reread the index.
 */
void BTL_SERVER_FLOW_PushMoveQueue(u8 *p, int a, int b, int c)
{
    if (p[0] < 6) {
        (p + p[0])[1] = a;
        (p + p[0])[13] = b;
        (p + p[0])[7] = c;
        p[0]++;
    }
}



























void BTL_SERVER_FLOW_ProcInterruptMove(BtlServerFlow *flow, u8 *b, u16 c, void *unused)
{
    u8 *a;
    u32 lock;
    if ((flow->curInterruptQueue)[0] != 0) {
        a = func_021B9934(flow->pokeCon, (flow->curInterruptQueue)[1]);
        lock = func_021CC8D8(&flow->lock, 3720);
        BTL_SERVER_FLOW_DispatchMoveInterruptEvent(flow, a, b, c);
        func_021CC95C(&flow->lock, lock, 3722);
        BTL_SERVER_FLOW_GetMoveParam(flow, c, a, flow->curMoveParam);
        func_021CA7F4(flow, a, (flow->curInterruptQueue)[7], flow->curMoveParam, flow->curEffectSet);
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 15) != 0 && (u32)WAZA_TOOL_GetFlag((void *)c, (int)12) != 0) {
            BTL_SERVER_FLOW_PushMoveFailMessage(flow, a, c, 13);
            return;
        }
        func_021E02DC(a, c, func_021D59B4(a, 12));
        func_021BEC58(flow, a, c, flow->curEffectSet);
        func_021E03D8(a, c);
    }
}




























void BTL_SERVER_FLOW_DispatchMoveTypeEvent(BtlServerFlow *flow, u8 *a, u8 *c)
{
    BTL_EVENT_PushVarFrame(3755);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, ((struct Obj09961 *)c)->f0);
    BTL_EVENT_SetVarOnce(0x16, c[6]);
    func_021D70F0(flow, 0xA2);
    c[6] = BTL_EVENT_GetVar(0x16);
    BTL_EVENT_PopVarFrame(3761);
}



























/*
 * evidence: CC8D8 returns its four-byte Lock_021BDB88 in r0; preserve that complete
 * word as u32, as matched twin 021BE924 does. CC95C stores r1 unchanged.
 */
void BTL_SERVER_FLOW_DispatchMoveParamEventLocked(BtlServerFlow *flow, u8 *a, u8 *c, int k)
{
    u32 old;
    old = func_021CC8D8((struct Lock_021BDB88 *)&flow->lock, 3774);
    BTL_SERVER_FLOW_DispatchMoveParamEvent(flow, a, c, k);
    func_021CC95C(&flow->lock, old, 3778);
}




























void BTL_SERVER_FLOW_DispatchMoveParamEvent(BtlServerFlow *flow, u8 *a, u8 *c, int k)
{
    BTL_EVENT_PushVarFrame(3791);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, ((struct Obj13311 *)c)->f0);
    BTL_EVENT_SetVarReadOnly(0x16, c[6]);
    func_021D70F0(flow, k);
    BTL_EVENT_PopVarFrame(3796);
}



























int BTL_SERVER_FLOW_ProcPledgeCombo(BtlServerFlow *flow, u8 *a, u16 key, u32 x)
{
    u32 i;
    u32 n;
    u8 id;
    u8 *chosen;
    u32 best;
    u8 chosen_id;
    Entry *cur;
    Entry *found[2];
    u32 v;
    for (i = 0; i < 3; i++) {
        if (key == d_021EFDB8[i]) break;
    }
    if (i == 3) goto fail;
    if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)a, 10) != 0) goto fail;
    if (BTL_EVENT_HasClientReservedChoice(a) != 0) goto fail;
    n = 0;
    id = BTL_POKEPARAM_GetPokeId(a);
    for (i = 0; i < 3; i++) {
        if (key != d_021EFDB8[i]) {
            found[n] = BTL_SERVER_FLOW_FindPendingMoveActionForPoke(flow, d_021EFDB8[i], id, x);
            if (found[n] != 0) {
                n++;
                if (n >= 2) break;
            }
        }
    }
    if (n == 0) goto fail;
    best = 6;
    chosen = found[0]->a;
    for (i = 0; i < n; i++) {
        cur = found[i];
        v = (u32)BTL_SERVER_FLOW_GetActionIndex(flow, cur);
        if (v < best) {
            best = v;
            chosen = cur->a;
        }
    }
    chosen_id = BTL_POKEPARAM_GetPokeId(chosen);
    BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, 10);
    BTL_EVENT_SetClientReservedChoice(chosen, id, key);
    BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 91, 0x47a, id, chosen_id, 0xffff0000);
    BTL_SERVER_FLOW_PromoteActionOfPoke(flow, chosen_id);
    return 1;
fail:
    return 0;
}




























int func_021BE7E4(BtlServerFlow *flow, u8 *a, u32 b, u32 c, u8 *q)
{
    u32 lk = func_021CC8D8(&flow->lock, 3894);
    int r = BTL_SERVER_FLOW_DispatchMoveExecuteCheckEvent(flow, a, c);
    int s;
    *q = 0;
    if (r) {
        s = func_021B8D8C(flow->mainModule, flow->pokeCon, BTL_POKEPARAM_GetPokeId(a));
        if (func_021C88E4(flow) == 2) {
            BTL_SERVER_CMD_Push(flow->cmdQueue, 0x30, s, c, b, 0);
            BTL_SERVER_FLOW_NotifyMoveExecuteFail(flow, a);
            *q = 1;
        } else {
            BTL_SERVER_FLOW_PushMsgStdFailed(flow, a, b);
        }
    }
    func_021CC95C(&flow->lock, lk, 3913);
    return r;
}




























int BTL_SERVER_FLOW_DispatchMoveExecuteCheckEvent(BtlServerFlow *flow, u8 *a, u32 v)
{
    int r;
    BTL_EVENT_PushVarFrame(3931);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0xD, v);
    BTL_EVENT_SetVarOnce(0x51, 0);
    func_021D70F0(flow, 6);
    r = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(3937);
    return r;
}

























void BTL_SERVER_FLOW_NotifyMoveExecuteFail(BtlServerFlow *flow, u8 *a)
{
    u32 old;
    old = func_021CC8D8((struct Lock_021BDB88 *)&flow->lock, 3951);
    BTL_SERVER_FLOW_DispatchMoveExecuteFailEvent(flow, a);
    func_021CC95C(&flow->lock, old, 3956);
}

























void BTL_SERVER_FLOW_DispatchMoveExecuteFailEvent(BtlServerFlow *flow,u8 *a)
{
    BTL_EVENT_PushVarFrame(3968);
    BTL_EVENT_SetVarReadOnly(3,BTL_POKEPARAM_GetPokeId(a));
    func_021D70F0(flow,7);
    BTL_EVENT_PopVarFrame(3971);
}


























void BTL_SERVER_FLOW_NotifyMoveStart(BtlServerFlow *flow, u8 *a, u32 v)
{
    u32 s = func_021CC8D8(&flow->lock, 3985);
    BTL_SERVER_FLOW_DispatchMoveStartEvent(flow, a, v);
    func_021CC95C(&flow->lock, s, 3987);
}

























void BTL_SERVER_FLOW_DispatchMoveStartEvent(BtlServerFlow *flow, u8 *a, u32 v)
{
    BTL_EVENT_PushVarFrame(4000);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, v);
    func_021D70F0(flow, 3);
    BTL_EVENT_PopVarFrame(4004);
}
























/*
 * Interface: getter's matched Lock_021BDB88 return is one full word; original
 * 021CC8DA loads old [r0] into r1; 021CC900 copies r1 to r0 unchanged.
 * This caller
 * saves r0 at 021BE9A8 and restores all bits through r1 at 021BE9BA;
 * 021CC95C is str r1,[r0]; bx lr. Scalar spelling follows matched caller
 * 021BC568 and retains the same word ABI. Struct/union locals used a
 * 12-byte frame and separate 4019 pool; scalar uses original 4-byte frame.
 */
void BTL_SERVER_FLOW_NotifyMoveEnd(BtlServerFlow *flow,u8 *a,u32 c,u32 d)
{
    u32 old;
    old=func_021CC8D8(&flow->lock, 4017);
    BTL_SERVER_FLOW_DispatchMoveEndEvent(flow,a,c,d);
    func_021CC95C(&flow->lock,old,4019);
}

























void BTL_SERVER_FLOW_DispatchMoveEndEvent(BtlServerFlow *flow, u8 *a, u32 c, u32 d)
{
    BTL_EVENT_PushVarFrame(4032);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, c);
    BTL_EVENT_SetVarReadOnly(0x51, d);
    func_021D70F0(flow, 4);
    BTL_EVENT_PopVarFrame(4037);
}

























void BTL_SERVER_FLOW_DispatchMoveInterruptEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c)
{
    BTL_EVENT_PushVarFrame(4051);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x12, c);
    func_021D70F0(flow, 8);
    BTL_EVENT_PopVarFrame(4056);
}
























void BTL_SERVER_FLOW_DispatchDeferredMoveEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c)
{
    BTL_EVENT_PushVarFrame(4069);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x12, c);
    BTL_EVENT_SetVarOnce(0x51, 0);
    func_021D70F0(flow, 9);
    BTL_EVENT_PopVarFrame(4075);
}























/*
 * The byte loaded and compared in r1 remains the veneer call's second
 * argument. The veneer at 021BEB04 preserves r0/r1 to its target.
 */
int BTL_SERVER_FLOW_CheckMoveInterrupt(BtlServerFlow *flow, u8 *a, int b, void *c, u8 *q)
{
    u8 buf[2];
    buf[1] = 0x1F;
    buf[0] = 0x1F;
    BTL_SERVER_FLOW_DispatchMoveInterruptCheckEvent((int)flow, a, b, c, &buf[1], &buf[0]);
    if (buf[1] != 0x1F) {
        q[7] = (buf[0] != 0x1F) ? func_0689D5C8(flow->posPoke, buf[0]) : 6;
        q[1] = buf[1];
        q[0] = 1;
        return 1;
    }
    return 0;
}





















int BTL_SERVER_FLOW_DispatchMoveInterruptCheckEvent(int a, u8 *b, int c, void *d, u8 *e, u8 *g)
{
    u32 n;
    u32 i;
    n = func_0689CD38(d);
    BTL_EVENT_PushVarFrame(4136);
    BTL_EVENT_SetVarReadOnly(0x12, c);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(5, n);
    for (i = 0; i < n; i++)
        BTL_EVENT_SetVarReadOnly(6 + i, BTL_POKEPARAM_GetPokeId(func_0689CC70(d, i)));
    BTL_EVENT_SetVarOnce(2, 0x1f);
    BTL_EVENT_SetVar(4, 0x1f);
    func_021D70F0((void *)a, 0x1a);
    *e = BTL_EVENT_GetVar(2);
    *g = BTL_EVENT_GetVar(4);
    BTL_EVENT_PopVarFrame(4155);
    if (*e != 0x1f)
        return 1;
    return 0;
}





















void BTL_SERVER_FLOW_PushMoveExecCmd(BtlServerFlow *flow,u8 *a,int c,int d)
{
    int n;
    n=func_021B8D8C(flow->mainModule,flow->pokeCon,BTL_POKEPARAM_GetPokeId(a));
    BTL_SERVER_CMD_Push(flow->cmdQueue,0x30,n,d,c,0);
}






















int BTL_SERVER_FLOW_IsPlayerSidePoke(BtlServerFlow *flow,u8 *a)
{
    int n;
    n=func_021B8DDC(BTL_POKEPARAM_GetPokeId(a));
    if(n==func_021B8FF4(flow->mainModule)) return 1;
    return 0;
}






















void BTL_SERVER_FLOW_RecordSpecialMoveUse(BtlServerFlow *flow,u8 *a,int c)
{
    if(BTL_SERVER_FLOW_IsPlayerSidePoke(flow,a)) {
        if(c==150) func_021BA1B4((char **)(flow->mainModule),73);
        else if(c==165) func_021BA1B4((char **)(flow->mainModule),74);
    }
}





















/*
 * budget: 2 iteration one; scheduling variant1/2 consumed; no checks/permuter.
 * Single action/filter pipeline, with flags initialized at EC74..EC7E.
 * All exit paths and switch table mappings retain their original results.
 * CC8D8 returns the full pre-mutation 32-bit Lock_021BDB88 (10+9+9+1+1+1+1).
 * ECFA saves all r0 and ED0E/ED14 forwards all r1 to own CC95C's u32
 * store; preserve line inputs 10A8/10AA under original return-use rule.
 * C5718's own one-input body does not erase the original loaded r1/r2.
 * Veneers EFEC/FFC/00C/01C/02C/03C forward respectively to ov095
 * CB3C/CEE4/CD50/CD50/CD50/D050; own matched records fix their widths.
 * Original ED78 branches onto ED7A: duplicated forced=1 arms retain the
 * cross-jumped break. Original EDB0..EDB4 extracts byte bit4, represented
 * by Bits78A. EE44 branches directly to EE6C, skipping C5718 at EE68;
 * only BF02C's true path performs that call before BF27C.
 */
int func_021BEC58(BtlServerFlow *flow, u8 *a, u16 key, u8 *d)
{
    u32 lock;
    u32 action = WAZA_TOOL_GetCategory(key);
    u8 id = BTL_POKEPARAM_GetPokeId(a);
    int active = 1;
    int execute = 0;
    int forced = 0;
    u32 pos;
    int result;
    struct State *s;
    BTL_SERVER_FLOW_RecordSpecialMoveUse(flow, a, key);
    if ((u32)WAZA_TOOL_GetFlag((void *)key, (int)1)) {
        switch (func_021BFC08(flow, a, d, key)) {
        case 0: break;
        case 1: return execute;
        case 2: return active;
        case 3: return execute;
        case 4: break;
        }
    }
    func_0689CB3C(flow->curDamageSet);
    pos = BTL_SERVER_CMD_Reserve(flow->cmdQueue, 0x30);
    BTL_SERVER_FLOW_SetupTurnState((struct Unk021BD1E0 *)((struct State * )flow->curTurnState), flow, a, d);
    lock = func_021CC8D8(&flow->lock, 0x10a8);
    result = BTL_SERVER_FLOW_QueryMoveExecuteEvent(flow, a, key, d);
    func_021CC95C(&flow->lock, lock, 0x10aa);
    if (result != 0) {
        s = (struct State * )flow->curTurnState;
        if (s->a == 0) s->a = 1;
        if (result == 2) {
            BTL_SERVER_FLOW_PushPendingHpRecovery(flow, key, flow->curTurnState, pos);
            return 1;
        }
    }
    switch (action) {
    case 0: case 4: case 6: case 7: case 8:
        execute = 1;
        forced = 1;
        break;
    case 9:
        forced = 1;
        break;
    }
    func_0689CEE4((struct S *)d);
    BTL_SERVER_FLOW_RemoveOutOfRangeTargets(flow, flow->curMoveParam, (int)a, d);
    BTL_SERVER_FLOW_RemoveSelfTarget((int)flow, a, d, flow->curMoveParam, execute);
    if (func_0689CD50((struct S *)d)) {
        if (((struct Bits78A *)&flow->stateFlags)->skip == 0) BTL_SERVER_FLOW_PushMsgStdFailed(flow, a, key);
        active = 0;
    }
    if (active != 0) {
        if (action != 9) BTL_SERVER_FLOW_RemoveImmuneTargets(flow, flow->curMoveParam, a, d);
        func_021CC8A0((u32 *)flow->targetParam);
        if (forced != 0 || BTL_SERVER_FLOW_CheckAccuracyCheckRequired(flow, flow->curMoveParam, a))
            BTL_SERVER_FLOW_ProcAccuracyCheck(flow, (int)flow->curMoveParam, a, d, flow->targetParam);
        BTL_SERVER_FLOW_ProcNoEffectChecks(flow, flow->curMoveParam, a, d, flow->targetParam);
        if (action != 9) BTL_SERVER_FLOW_RemoveMissedTargets(flow, flow->curMoveParam, a, d);
        if (func_0689CD50((struct S *)d)) {
            BTL_SERVER_FLOW_NotifyMoveFailed(flow, id, key);
            active = 0;
        } else {
            BTL_SERVER_FLOW_RemoveSubstituteTargets((int)flow, flow->curMoveParam, a, d, forced);
            if (func_0689CD50((struct S *)d)) {
                BTL_SERVER_FLOW_PushMsgStdFailed(flow, a, key);
                BTL_SERVER_FLOW_NotifyMoveFailed(flow, id, key);
                active = 0;
            }
        }
    }
    if (active != 0) {
        if (execute != 0) {
            BTL_SERVER_FLOW_ProcMoveHitTargets(flow, flow->curMoveParam, a, d, (const u32 *)flow->targetParam, 0);
        } else {
            switch (action) {
            case 2: BTL_SERVER_FLOW_ProcMoveRankEffectAllTargets(flow, (u32)flow->curMoveParam, (u32)a, d); break;
            case 1: BTL_SERVER_FLOW_ProcMoveSickAllTargets(flow, key, a, d); break;
            case 5: BTL_SERVER_FLOW_ProcMoveRankAndSickAllTargets(flow, flow->curMoveParam, (u32)a, d); break;
            case 9: BTL_SERVER_FLOW_ProcMoveOhko(flow, flow->curMoveParam, a, d); break;
            case 12: BTL_SERVER_FLOW_ProcMoveForceSwitchAllTargets(flow, key, (int)a, d); break;
            case 3: BTL_SERVER_FLOW_ProcMoveRecoverHpAllTargets(flow, key, (u32)a, d); break;
            case 10: BTL_SERVER_FLOW_ProcMoveWeather(flow, flow->curMoveParam, a); break;
            case 11: case 13: BTL_SERVER_FLOW_ProcMoveSpecialEffect(flow, flow->curMoveParam, a, d); break;
            }
        }
        s = (struct State * )flow->curTurnState;
        if (s->a != 0) {
            if (s->b == 0) BTL_SERVER_FLOW_PushPendingHpRecovery(flow, key, flow->curTurnState, pos);
            func_0689D050((struct O *)flow->turnRecord);
            if (!BTL_POKEPARAM_IsFainted(a) && (u32)WAZA_TOOL_GetFlag((void *)key, (int)2)) BTL_SERVER_FLOW_SetContFlag(flow, a, 12);
            BTL_SERVER_FLOW_NotifyMoveSucceeded(flow, id, key);
        } else {
            BTL_SERVER_FLOW_NotifyMoveFailed(flow, id, key);
            active = 0;
        }
    } else {
        s = (struct State * )flow->curTurnState;
        if (s->a != 0) BTL_SERVER_FLOW_PushPendingHpRecovery(flow, key, flow->curTurnState, pos);
    }
    BTL_SERVER_FLOW_NotifyMoveFinished(flow, id, key);
    BTL_SERVER_FLOW_ProcFaintedPoke(flow, a);
    return active;
}



















void BTL_SERVER_FLOW_RemoveOutOfRangeTargets(BtlServerFlow *flow, u16 *b, int s, void *c)
{
    u8 *x;
    func_0689CC84(c);
    x = func_0689CC8C(c);
    while (x != 0) {
        if (BTL_SERVER_FLOW_CheckAllyMoveAutoHit(flow, (u8 *)s, x, (void *)(*b)) != 0) {
            func_0689CC14(c, x);
            BTL_SERVER_FLOW_PushMoveBlockedMessage(flow, x, *b);
            flow->stateFlags.raw |= 0x10;
        }
        x = func_0689CC8C(c);
    }
}


















void BTL_SERVER_FLOW_RemoveSelfTarget(int u, u8 *b, void *c, u8 *d, int e)
{
    u8 *x;
    if (func_0689CD40(c) == 1) {
        x = func_0689CC70(c, 0);
        if (x != 0) {
            if (BTL_POKEPARAM_GetPokeId(x) == BTL_POKEPARAM_GetPokeId(b)) {
                if (((struct Obj21056 *)d)->fC != 7) {
                    if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)b, 12) != 0 || e != 0)
                        func_0689CC14(c, x);
                }
            }
        }
    }
}


















int BTL_SERVER_FLOW_CheckAccuracyCheckRequired(BtlServerFlow *flow, u16 *a, u8 *b)
{
    int r;
    BTL_EVENT_PushVarFrame(4500);
    BTL_EVENT_SetVar(3, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVar(0x12, *a);
    BTL_EVENT_SetVarOnce(0x51, 0);
    func_021D70F0(flow, 0x3d);
    r = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(4506);
    return r;
}


















void BTL_SERVER_FLOW_RemoveSubstituteTargets(int u, u16 *b, u8 *s, void *c, int e)
{
    u8 *x;
    func_0689CC84(c);
    x = func_0689CC8C(c);
    while (x != 0) {
        if (s != x && BTL_POKEPARAM_HasSubstitute(x) != 0 && e == 0 && (u32)WAZA_TOOL_GetFlag((void *)((u16)((void *)*b)), (int)0xd) == 0)
            func_0689CC14(c, x);
        x = func_0689CC8C(c);
    }
}

















/*
 * interface: The four-byte Lock_021BF244 getter returns its entire original word in
 * r0 (021CC8DA,021CC900); restore 021CC95C stores that word unchanged.
 * Scalar payload follows matched caller 021BCEFC and preserves every bit.
 */
void BTL_SERVER_FLOW_NotifyMoveSucceeded(BtlServerFlow *flow, u32 a, u32 b)
{
    int line = 0x11e7;
    u32 old = func_021CC8D8((struct Lock_021BF244 *)&flow->lock, line);
    BTL_SERVER_FLOW_DispatchMoveResultEvent(flow, a, b, 0x25);
    func_021CC95C(&flow->lock, old, line + 2);
}

















void BTL_SERVER_FLOW_NotifyMoveFailed(BtlServerFlow *flow, u32 a, u32 b)
{
    int line = 0x11f6;
    u32 old = func_021CC8D8((struct Lock_021BF244 *)&flow->lock, line);
    BTL_SERVER_FLOW_DispatchMoveResultEvent(flow, a, b, 0x26);
    func_021CC95C(&flow->lock, old, line + 2);
}

















void BTL_SERVER_FLOW_NotifyMoveFinished(BtlServerFlow *flow, u32 a, u32 b)
{
    int line = 0x1205;
    u32 old = func_021CC8D8((struct Lock_021BF244 *)&flow->lock, line);
    BTL_SERVER_FLOW_DispatchMoveResultEvent(flow, a, b, 0x27);
    func_021CC95C(&flow->lock, old, line + 2);
}

















void BTL_SERVER_FLOW_DispatchMoveResultEvent(BtlServerFlow *flow, u32 a, u32 b, int k)
{
    int line = 0x1214;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVarReadOnly(2, a);
    BTL_EVENT_SetVarReadOnly(0x12, b);
    func_021D70F0(flow, k);
    BTL_EVENT_PopVarFrame(line + 4);
}

















int func_021BF324(BtlServerFlow *flow, u8 *a, u8 *b)
{
    u8 t;
    if (func_0689D59C(flow->posPoke, (int)flow->mainModule, BTL_POKEPARAM_GetPokeId(a)) != 0) {
        if (func_021D59B4(a, 0x11) == 0x63)
            return 1;
    }
    if (func_0689D59C(flow->posPoke, (int)flow->mainModule, BTL_POKEPARAM_GetPokeId(b)) != 0) {
        if (func_021D59B4(b, 0x11) == 0x63)
            return 1;
    }
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 0x1c) != 0)
        return 1;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 0x1d) != 0) {
        t = BTL_POKEPARAM_GetSickParam((struct UtilSlots *)a, 0x1d);
        if (t == BTL_POKEPARAM_GetPokeId(b))
            return 1;
    }
    return 0;
}















void BTL_SERVER_FLOW_ProcAccuracyCheck(BtlServerFlow *flow, int b, u8 *a, void *d, void *arr)
{
    u8 *x;
    int r;
    int e;
    func_021CC8A0(arr);
    func_0689CC84(d);
    x = func_0689CC8C(d);
    while (x != 0) {
        r = BTL_SERVER_FLOW_CalcTypeEffectiveness(flow, a, x, (u8 *)b, 1);
        func_021CC8B0(arr, BTL_POKEPARAM_GetPokeId(x), r);
        if (r == 0) {
            func_0689CC14(d, x);
            func_021C7C24((u16 *)flow->turnDeadRecord, (int)flow, a, x, 0);
            e = func_021B8DDC(BTL_POKEPARAM_GetPokeId(a));
            if (e == func_021B8FF4(flow->mainModule))
                func_021BA1B4((char **)(flow->mainModule), 0x4b);
        }
        x = func_0689CC8C(d);
    }
}













void BTL_SERVER_FLOW_ProcNoEffectChecks(BtlServerFlow *flow, u8 *b, u8 *a, void *d, void *e)
{
    u8 *q;
    func_0689CC84(d);
    q = func_0689CC8C(d);
    while (q) {
        if (func_021BF324(flow, a, q) == 0 && BTL_SERVER_FLOW_ProcNoEffectCheck(flow, b, a, q, e, 43))
            func_0689CC14(d, q);
        q = func_0689CC8C(d);
    }
    func_0689CC84(d);
    q = func_0689CC8C(d);
    while (q) {
        if (BTL_SERVER_FLOW_ProcNoEffectCheck(flow, b, a, q, e, 44)) func_0689CC14(d, q);
        q = func_0689CC8C(d);
    }
    if ((u32)WAZA_TOOL_GetFlag((void *)(((struct Obj04358 *)b)->f0), (int)3)) {
        func_0689CC84(d);
        q = func_0689CC8C(d);
        while (q) {
            if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)q, 7) && BTL_SERVER_FLOW_QueryActionCancelEvent(flow, a, q, ((struct Obj04358 *)b)->f0) == 0) {
                func_0689CC14(d, q);
                BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 91, 523, BTL_POKEPARAM_GetPokeId(q), 0xffff0000);
            }
            q = func_0689CC8C(d);
        }
    }
    func_0689CC84(d);
    q = func_0689CC8C(d);
    while (q) {
        if (BTL_SERVER_FLOW_ProcNoEffectCheck(flow, b, a, q, e, 45)) func_0689CC14(d, q);
        q = func_0689CC8C(d);
    }
}














int BTL_SERVER_FLOW_ProcNoEffectCheck(BtlServerFlow *flow, u8 *b, u8 *c2, u8 *d, void *s0, int s1)
{
    u32 s;
    int flag;
    int r;
    s = func_021CC8D8(&flow->lock, 4784);
    flag = 0;
    r = BTL_SERVER_FLOW_RunTargetNoEffectEvent(flow, b, s1, c2, d, s0, flow->msgParam, &flag);
    if (r != 0) {
        if (func_021C8828(flow->msgParam) != 0) {
            func_021C99A0(flow, (const struct Msg *)flow->msgParam);
            func_021C8810(flow->msgParam);
        } else if (func_021C88E4(flow) == 0 && flag == 0) {
            BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0xd2, BTL_POKEPARAM_GetPokeId(d), 0xffff0000);
        }
    }
    func_021CC95C(&flow->lock, s, 4810);
    return r;
}















int BTL_SERVER_FLOW_RunTargetNoEffectEvent(BtlServerFlow *flow, u8 *b, int c, u8 *d, u8 *e, void *f, void *g, int *h)
{
    u32 t;
    int r;
    t = func_021CC8C0(f, BTL_POKEPARAM_GetPokeId(e));
    func_021C8810(g);
    BTL_EVENT_PushVarFrame(4834);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(d));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(e));
    BTL_EVENT_SetVarReadOnly(0x12, ((struct Obj13317 *)b)->f0);
    BTL_EVENT_SetVarReadOnly(0x16, b[6]);
    BTL_EVENT_SetVarReadOnly(0x4e, ((struct Bf *)b)->f);
    BTL_EVENT_SetVarReadOnly(0x3f, (u32)g);
    BTL_EVENT_SetVarReadOnly(0x38, t);
    BTL_EVENT_SetVarOnce(0x40, 0);
    BTL_EVENT_SetVarOnce(0x51, 0);
    func_021D70F0(flow, c);
    r = BTL_EVENT_GetVar(0x40);
    *h = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(4847);
    return r;
}















void BTL_SERVER_FLOW_RemoveImmuneTargets(BtlServerFlow *flow, u16 *b, u8 *c, void *d)
{
    u8 *x;
    func_0689CC84(d);
    x = func_0689CC8C(d);
    while (x != 0) {
        if (func_021BF324(flow, c, x) == 0) {
            if (BTL_SERVER_FLOW_QuerySemiInvulnerableHit(flow, c, x, *b) != 0) {
                func_0689CC14(d, x);
                BTL_SERVER_FLOW_PushMoveBlockedMessage(flow, x, *b);
            }
        }
        x = func_0689CC8C(d);
    }
}












void BTL_SERVER_FLOW_RemoveMissedTargets(BtlServerFlow *flow, u16 *b, u8 *c, void *d)
{
    u8 *x;
    if (func_0689CD40(d) == 1 && func_0689CC70(d, 0) == c)
        return;
    func_0689CC84(d);
    x = func_0689CC8C(d);
    while (x != 0) {
        if (BTL_SERVER_FLOW_CheckMoveAvoidEvent(flow, c, x, b) == 0 && BTL_SERVER_FLOW_RollMoveAccuracy(flow, c, x, (struct Q *)b) == 0) {
            func_0689CC14(d, x);
            BTL_SERVER_FLOW_PushMoveBlockedMessage(flow, x, *b);
        }
        x = func_0689CC8C(d);
    }
}















int BTL_SERVER_FLOW_CheckMoveAvoidEvent(BtlServerFlow *flow, u8 *a, u8 *b, u16 *c)
{
    int r;
    BTL_EVENT_PushVarFrame(4929);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x12, *c);
    BTL_EVENT_SetVarOnce(0x51, 0);
    func_021D70F0(flow, 0x1c);
    r = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(4936);
    return r;
}
















int BTL_SERVER_FLOW_CheckAllyMoveAutoHit(BtlServerFlow *flow, u8 *a, u8 *b, void *item)
{
    int x;
    int y;
    if (BTL_MAIN_GetRule(flow->mainModule) == 2) {
        if (item != 0 && WAZA_TOOL_GetFlag(item, 0xb) != 0) return 0;
        x = func_021B8D8C(flow->mainModule, flow->pokeCon, BTL_POKEPARAM_GetPokeId(a));
        y = func_021B8D8C(flow->mainModule, flow->pokeCon, BTL_POKEPARAM_GetPokeId(b));
        if (func_021B9A6C(x, y) == 0) return 1;
    }
    return 0;
}















/*
 * lever: Declare flag before base to place their spills at the original stack offsets.
 */
int BTL_SERVER_FLOW_RollMoveAccuracy(BtlServerFlow *flow, u8 *a, u8 *b, struct Q *q)
{
    u8 flag;
    s8 x, y;
    int base;
    u32 scale;
    int v;
    u32 chance;
    if (func_021BF324(flow, a, b)) return 1;
    if (func_021C69B8(flow, a, (u32)b, q->h0)) return 1;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)b, 32)) return 1;
    base = BTL_SERVER_FLOW_CalcAccuracyRatio(flow, a, b, q);
    BTL_EVENT_PushVarFrame(5014);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarOnce(75, 0);
    BTL_EVENT_SetVar(39, func_021D59B4(a, 6));
    BTL_EVENT_SetVar(40, func_021D59B4(b, 7));
    BTL_EVENT_SetVarRanged(53, 4 << 10, 41, 4 << 15);
    func_021D70F0(flow, 51);
    x = BTL_EVENT_GetVar(39);
    y = BTL_EVENT_GetVar(40);
    flag = BTL_EVENT_GetVar(75);
    if ((BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)b, 17) && y > 6) || flag) y = 6;
    if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)a, 14)) BTL_EVENT_MultiplyVar(53, 4915);
    scale = BTL_EVENT_GetVar(53);
    BTL_EVENT_PopVarFrame(5039);
    v = x + 6 - y;
    if (v < 0) v = 0;
    if (v > 12) v = 12;
    chance = BTL_CALC_MulRatio(BTL_CALC_ApplyAccuracyStage((u8)base, (u8)(s8)v), scale);
    if (chance > 100) chance = 100;
    if (func_021B911C(flow->mainModule, 6)) chance = 100;
    if (BTL_CALC_Random(100) < (u8)chance) return 1;
    return 0;
}















void BTL_SERVER_FLOW_PushPendingHpRecovery(BtlServerFlow *flow, u32 fallback, u8 *record, u32 pos)
{
    u32 value = ((struct Obj05190 *)record)->f0;
    if (value == 0) value = fallback;
    BTL_SERVER_CMD_FillReserved(flow->cmdQueue, (u16)pos, 0x30,
                 record[2], record[3], value, record[4]);
    record[4] = 0;
    record[5] |= 2;
}













/*
 * lever: Wide n/callee parameter avoids truncation; named one-word union Slot result supplies the frame word.
 */
int func_021BFC08(BtlServerFlow *flow, u8 *q, u8 *d, u16 c)
{
    int result;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)q, 26) == 0) {
        u16 n = func_021B8D8C(flow->mainModule, flow->pokeCon, BTL_POKEPARAM_GetPokeId(q));
        if (BTL_SERVER_FLOW_QueryFirstTargetBlockEvent(flow, q, d)) {
            BTL_SERVER_FLOW_PushMsgStdFailed(flow, q, c);
            return 1;
        }
        if (BTL_SERVER_FLOW_QueryMoveBlockedEvent(flow, q, c) == 0) {
            if (BTL_SERVER_FLOW_ProcMoveUseDecide(flow, q, n, d, c)) {
                union Slot s = BTLV_CORE_MakeSlotKind2(2, c);
                BTL_SERVER_FLOW_SetSickCont(flow, q, 26, s);
            }
            return 2;
        }
        if (BTL_SERVER_FLOW_ProcMoveUseDecide(flow, q, n, d, c) == 0) return 1;
        {
            u32 lock = func_021CC8D8(&flow->lock, 5124);
            BTL_SERVER_FLOW_NotifyMoveFinishEvent(flow, q, c);
            func_021CC95C(&flow->lock, lock, 5126);
        }
    }
    (flow->curTurnState)[4] = 1;
    {
        u32 lock = func_021CC8D8(&flow->lock, 5134);
        result = BTL_SERVER_FLOW_QueryMoveTargetsAllowedEvent(flow, q, d, c);
        func_021CC95C(&flow->lock, lock, 5136);
    }
    BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)q, 11);
    BTL_SERVER_FLOW_ClearMoveLockSicks(flow, q);
    return result ? 4 : 3;
}












int BTL_SERVER_FLOW_ProcMoveUseDecide(BtlServerFlow *flow, u8 *q, u16 c, u8 *d, u16 e)
{
    u32 out;
    u8 id;
    u32 lock;
    int r;
    u8 n;
    out = 0;
    id = 31;
    lock = func_021CC8D8(&flow->lock, 5160);
    r = BTL_SERVER_FLOW_QueryMoveRedirectEvent(flow, q, d, e, &id, &out);
    if (r) {
        n = flow->reserveSlot;
        if (func_0689CD38(d))
            n = func_0689D5C8(flow->posPoke, BTL_POKEPARAM_GetPokeId(func_0689CC70(d, 0)));
        BTL_SERVER_CMD_Push(flow->cmdQueue, 48, c, n, e, 0);
    }
    func_021CC95C(&flow->lock, lock, 5173);
    if (r) {
        lock = func_021CC8D8(&flow->lock, 5177);
        BTL_SERVER_FLOW_NotifyMoveBeginEvent(flow, q);
        func_021CC95C(&flow->lock, lock, 5179);
        if (BTL_POKEPARAM_IsSemiInvulnerable((struct UtilWork *)q))
            BTL_SERVER_CMD_Push(flow->cmdQueue, 49, BTL_POKEPARAM_GetPokeId(q), 1);
        if (id != 31)
            BTL_SERVER_CMD_Push(flow->cmdQueue, 49, id, 1);
    } else if (out == 0) {
        BTL_SERVER_FLOW_PushMsgStdFailed(flow, q, e);
    }
    return r;
}














void BTL_SERVER_FLOW_ClearMoveLockSicks(BtlServerFlow *flow, u8 *a)
{
    int k = 0x1a;
    u32 r;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, k) != 0) {
        BTL_SERVER_FLOW_CureSick(flow, a, k, 0);
        BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, 0xb);
    }
    r = BTL_POKEPARAM_GetSemiInvulnerableFlag((struct UtilWork *)a);
    while (r != 0x10) {
        BTL_SERVER_FLOW_ClearContFlag(flow, a, r);
        r = BTL_POKEPARAM_GetSemiInvulnerableFlag((struct UtilWork *)a);
    }
}














int BTL_SERVER_FLOW_ProcMoveReflectOrAbsorb(BtlServerFlow *flow, u8 *a, u8 *b, int *out)
{
    u8 n;
    union Slot t;
    *out = 0;
    if (BTL_POKEPARAM_IsFainted(b) == 0 && BTL_POKEPARAM_HasSubstitute(b) == 0 && BTL_POKEPARAM_IsSemiInvulnerable((struct UtilWork *)b) == 0) {
        if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)b, 7) == 0) {
            n = BTL_POKEPARAM_GetPokeId(b);
            BTL_SERVER_FLOW_SetContFlag(flow, a, 3);
            BTL_SERVER_FLOW_SetContFlag(flow, b, 3);
            BTL_SERVER_FLOW_SetPokeCounter(flow, a, 4, n + 1);
            t = BTLV_CORE_MakeSlotKind3(BTL_POKEPARAM_GetPokeId(a));
            BTL_SERVER_FLOW_ProcSickAdded(flow, b, a, 0x21, t, 0, 0, 0);
            return 1;
        }
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x20b, BTL_POKEPARAM_GetPokeId(b), 0xffff0000);
        *out = 1;
    }
    return 0;
}













void BTL_SERVER_FLOW_ReleaseBindingTarget(BtlServerFlow *flow, u8 *a, int z)
{
    u8 k;
    int n;
    u8 *w;
    n = func_021D69AC(a, 4);
    if (n == 0) goto bad;
    k = n - 1;
    if (k < 0x18) goto ok;
bad:
    k = 0x1f;
ok:
    if (k != 0x1f) {
        w = func_021B9934(flow->pokeCon, k);
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)w, 0x21) != 0) {
            BTL_SERVER_FLOW_CureSick(flow, w, 0x21, 0);
            BTL_SERVER_FLOW_ClearContFlag(flow, w, 3);
            if (func_0689D588(flow->posPoke, k) != 0) {
                BTL_SERVER_CMD_Push(flow->cmdQueue, 0x31, k, 0);
                BTL_SERVER_FLOW_PushMsgSetPoke(flow, w, 0x465);
            }
        }
        BTL_SERVER_FLOW_SetPokeCounter(flow, a, 4, 0);
        k = 0;
        if (z == 0 && BTL_POKEPARAM_IsFainted(a) == 0) {
            BTL_SERVER_CMD_Push(flow->cmdQueue, 0x31, BTL_POKEPARAM_GetPokeId(a), k);
        }
    }
}











/*
 * lever: Naming the one-word union result before passing it restores the original frame.
 * Symbol hints retain the Thumb ISA of the two already-matched ARM9 callees.
 */
int func_021C001C(BtlServerFlow *flow, u8 *a, u16 c, u16 d)
{
    int mode;
    int changed = 0;
    int reason;
    union Slot move;
    BTL_SERVER_FLOW_TickSleepTurn(flow, a, c);
    mode = BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)a);
    if (mode == 2) {
        reason = 2;
        if (BTL_SERVER_FLOW_QueryStatusSkipEvent(flow, a, c, 2) == 0) goto done;
    }
    changed = BTL_SERVER_FLOW_CheckFreezeThaw(flow, a, (void *)c);
    mode = BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)a);
    if (mode == 3 && changed == 0) { reason = 4; goto done; }
    if (flow->pendingResult == 4) { reason = 22; goto done; }
    if (flow->pendingResult == 2) { reason = 23; goto done; }
    if (d == 0) {
        int index = BTL_POKEPARAM_FindMoveSlot((struct UtilWork *)a, c);
        if (index != 4 && BTL_POKEPARAM_GetMovePPChecked((struct UtilWork *)a, index) == 0) { reason = 1; goto done; }
    }
    reason = BTL_SERVER_FLOW_QueryMoveFailReasonEvent(flow, a, c, 30);
    if (reason) goto done;
    if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)a, 6)) { reason = 7; goto done; }
    if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)a, 4)) { reason = 6; goto done; }
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 13) && c != 165) {
        move = BTL_POKEPARAM_GetSickContRaw(a, 13);
        if (c == BTLV_CORE_GetSlotValue(move)) { reason = 9; goto done; }
    }
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 15) && (u32)WAZA_TOOL_GetFlag((void *)c, (int)12)) { reason = 13; goto done; }
    if (BTL_FIELD_GetStaticSlotObject(2) && (u32)WAZA_TOOL_GetFlag((void *)c, (int)9)) { reason = 20; goto done; }
    if (c != 165) {
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 23)) {
            u16 id = BTL_POKEPARAM_GetLastSelectedMoveId(a);
            if (id != 165 && id != c) { reason = 17; goto done; }
        }
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 25) && c != BTL_POKEPARAM_GetLastUsedMoveId((struct QL *)a)) { reason = 17; goto done; }
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 11) && WAZA_TOOL_IsDamaging((void *)c) == 0) { reason = 10; goto done; }
        if (BTL_FIELD_GetStaticSlotObject(3) && func_021EF91C(flow->pokeCon, a, c)) { reason = 12; goto done; }
    }
    if (BTL_SERVER_FLOW_CheckParalysisFail(flow, a)) { reason = 5; goto done; }
    if (mode == 1 && BTL_CALC_RollPercent(25)) { reason = 3; goto done; }
    if (BTL_SERVER_FLOW_CheckConfusionSelfHit(flow, a)) reason = 8;
done:
    if (reason) {
        BTL_SERVER_FLOW_ProcMoveExecuteFail(flow, a, c, reason);
        return 1;
    }
    if (mode == 2) {
        BTL_SERVER_FLOW_PushMoveFailMessage(flow, a, c, 2);
        BTL_SERVER_FLOW_PushPokeEffectAnim(flow, a, 598);
    } else if (changed && mode == 3) {
        BTL_SERVER_FLOW_CureMajorStatusWithMessage(flow, a, mode, 0);
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 91, 303, BTL_POKEPARAM_GetPokeId(a), c, 0xffff0000);
    }
    return 0;
}














/*
 * lever: Wide third extern argument preserves the full r2 passed by the image.
 */
int BTL_SERVER_FLOW_CheckMoveExecuteFailByEvent(BtlServerFlow *flow, u8 *a, u16 c)
{
    int result;
    if (c != 0xa5) {
        result = BTL_SERVER_FLOW_QueryMoveFailReasonEvent(flow, a, c, 0x1f);
        if (result != 0) {
            BTL_SERVER_FLOW_ProcMoveExecuteFail(flow, a, c, result);
            return 1;
        }
    }
    return 0;
}















int BTL_SERVER_FLOW_QueryStatusSkipEvent(BtlServerFlow *flow, u8 *a, u32 c, u32 d)
{
    int r;
    BTL_EVENT_PushVarFrame(5537);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x22, d);
    BTL_EVENT_SetVarReadOnly(0x12, c);
    BTL_EVENT_SetVarOnce(0x41, 0);
    func_021D70F0(flow, 0x1D);
    r = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(5544);
    return r;
}















int BTL_SERVER_FLOW_QueryMoveFailReasonEvent(BtlServerFlow *flow, u8 *a, u32 c, int k)
{
    int r;
    BTL_EVENT_PushVarFrame(5563);
    BTL_EVENT_SetVarReadOnly(0x12, c);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarOnce(0x22, 0);
    func_021D70F0(flow, k);
    r = BTL_EVENT_GetVar(0x22);
    BTL_EVENT_PopVarFrame(5569);
    return r;
}














int BTL_SERVER_FLOW_CheckParalysisFail(BtlServerFlow *flow, u8 *a)
{
    int k = 6;
    if (flow->pendingResult == 3) {
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 0xbc, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
        return 1;
    }
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, k) != 0) {
        if (BTL_POKEPARAM_TickSlot6Turn((struct UtilSlots *)a) != 0) {
            BTL_SERVER_FLOW_CureSick(flow, a, k, 0);
            BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x15f, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
            return 0;
        }
        BTL_SERVER_FLOW_PushConfusionMessage(flow, a);
        return BTL_CALC_RollPercent(50);
    }
    return 0;
}















int BTL_SERVER_FLOW_CheckConfusionSelfHit(BtlServerFlow *flow, u8 *a)
{
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 7) != 0) {
        BTL_SERVER_FLOW_PushInfatuationMessage(flow, a);
        if (BTL_CALC_RollPercent(50) != 0) return 1;
    }
    return 0;
}















void BTL_SERVER_FLOW_TickSleepTurn(BtlServerFlow *flow, u8 *a, u16 a2)
{
    int k = BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)a);
    if (k == 2 && BTL_POKEPARAM_TickSleepTurn((struct UtilSlots *)a) != 0) {
        BTL_SERVER_FLOW_CureMajorStatusWithMessage(flow, a, k, 1);
    }
}














int BTL_SERVER_FLOW_CheckFreezeThaw(BtlServerFlow *flow, u8 *a, void *bag)
{
    int k = BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)a);
    int f = 0;
    int r = 0;
    if (k == 3) {
        if (WAZA_TOOL_GetFlag(bag, 10) != 0) {
            r = 1;
        } else if (BTL_CALC_RollPercent(20) != 0) {
            f = 1;
        }
    }
    if (f != 0) {
        BTL_SERVER_FLOW_CureMajorStatusWithMessage(flow, a, k, 1);
    }
    return r;
}














/*
 * lever: Raw u32 lock return avoids an aggregate frame word; Slot_021C024C remains a one-word aggregate.
 */
/*
 * lever: Raw u32 lock return avoids an aggregate frame word; Slot remains a one-word aggregate.
 */
void BTL_SERVER_FLOW_ProcMoveExecuteFail(BtlServerFlow *flow, u8 *q, u16 c, int k)
{
    u32 old;
    if (k == 5) {
        BTL_SERVER_FLOW_ProcConfusionDamage(flow, q);
        if (BTL_SERVER_FLOW_ProcFaintedPoke(flow, q) && BTL_SERVER_FLOW_CheckShowdown(flow)) return;
    } else {
        BTL_SERVER_FLOW_PushMoveFailMessage(flow, q, c, k);
        switch (k) {
        case 2: BTL_SERVER_FLOW_PushPokeEffectAnim(flow, q, 598); break;
        case 3: BTL_SERVER_FLOW_PushPokeEffectAnim(flow, q, 602); break;
        case 4: BTL_SERVER_FLOW_PushPokeEffectAnim(flow, q, 601); break;
        case 23: {
            union Slot s = BTL_CALC_MakeDefaultSickCont(2);
            BTL_SERVER_CMD_Push(flow->cmdQueue, 49, BTL_POKEPARAM_GetPokeId(q), 0);
            BTL_SERVER_FLOW_SetSickCont(flow, q, 2, s);
            BTL_SERVER_FLOW_PushPokeEffectAnim(flow, q, 598);
            break;
        }
        }
    }
    old = func_021CC8D8(&flow->lock, 5728);
    BTL_SERVER_FLOW_DispatchMoveDoneEvent(flow, q, c, k);
    func_021CC95C(&flow->lock, old, 5730);
}














/*
 * lever: a u8 local for the random result narrows in r0 before copying to r2.
 */
void BTL_SERVER_FLOW_PushMoveFailMessage(BtlServerFlow *flow, u8 *a, u16 b, u32 c)
{
    u32 id = BTL_POKEPARAM_GetPokeId(a);
    switch (c) {
    case 2: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x135, id, 0xffff0000); break;
    case 3: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x114, id, 0xffff0000); break;
    case 4: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x123, id, 0xffff0000); break;
    case 6: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x16b, id, 0xffff0000); break;
    case 7: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x16e, id, 0xffff0000); break;
    case 8: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x150, id, 0xffff0000); break;
    case 9: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x253, id, b, 0xffff0000); break;
    case 18: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x1bd, id, 0xffff0000); break;
    case 10: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x23b, id, b, 0xffff0000); break;
    case 11: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x244, id, b, 0xffff0000); break;
    case 12: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x24d, id, b, 0xffff0000); break;
    case 13: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x37a, id, b, 0xffff0000); break;
    case 14: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x37d, id, 0xffff0000); break;
    case 15:
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x57, id);
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x1c3, id, 0xffff0000);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x58, id);
        break;
    case 20: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x43e, id, b, 0xffff0000); break;
    case 22:
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 2) != 0) {
            BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 0xc2, id, 0xffff0000);
        } else {
            u8 rand = BTL_CALC_Random(4);
            BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, rand + 0xbc, id, 0xffff0000);
        }
        break;
    case 23: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 0xc1, id, 0xffff0000); break;
    case 1:
        BTL_SERVER_FLOW_PushPokeCmd59(flow, a, b);
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 0x52, id, 0xffff0000);
        break;
    default: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 0x47, id, 0xffff0000); break;
    case 19:
    case 25:
        break;
    }
}















void BTL_SERVER_FLOW_SetPokeCounter(BtlServerFlow *flow, u8 *a, int i, u8 v)
{
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x25, BTL_POKEPARAM_GetPokeId(a), (u8)i, v);
    func_021D69A0(a, i, v);
}














/*
 * extent: Two alignment bytes at 0x021C07D2 precede matched BTL_SERVER_FLOW_QueryMovePPCostEvent.
 * lever: Wide forwarded arguments avoid truncations absent before the first call.
 */
int BTL_SERVER_FLOW_ReducePPByEvent(BtlServerFlow *flow, u8 *a, u16 c, u16 d, void *e)
{
    u8 result = BTL_SERVER_FLOW_QueryMovePPCostEvent(flow, a, d, c, e);
    return BTL_SERVER_FLOW_ConsumeMovePP(flow, a, d, result);
}











/*
 * c and d are narrow parameters: their home stores (`str r2,[sp]` first,
 * `str r3,[sp,#4]` after `adds r7,r1`) sit where the narrow-parameter idiom
 * puts them; as u32 both sink below `ldr r5`. u8 and u16 compile the same
 * (any mix of the two); nothing in the image fixes the width, u16 chosen.
 * The calls to func_0689CD38 and func_0689CC70 go through linker veneers
 * (021C0868/0878/0888) that the linker makes.
 * `i = 0;` as its own statement before the func_0689CD38 call puts
 * `movs r4,#0` between `adds r0,r5` and that bl.
 */
int BTL_SERVER_FLOW_QueryMovePPCostEvent(BtlServerFlow *flow, u8 *a, u16 c, u16 d, void *e)
{
    int i;
    u8 *r;
    int res;
    BTL_EVENT_PushVarFrame(0x16ef);
    i = 0;
    BTL_EVENT_SetVarReadOnly(5, func_0689CD38(e));
    r = func_0689CC70(e, 0);
    if (r != 0) {
        do {
            BTL_EVENT_SetVarReadOnly(i + 6, BTL_POKEPARAM_GetPokeId(r));
            i++;
            r = func_0689CC70(e, i);
        } while (r != 0);
    }
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, d);
    BTL_EVENT_SetVarReadOnly(0x17, c);
    BTL_EVENT_SetVar(0x20, 1);
    func_021D70F0(flow, 0x4e);
    res = BTL_EVENT_GetVar(0x20);
    BTL_EVENT_PopVarFrame(0x1704);
    return res;
}










int BTL_SERVER_FLOW_ConsumeMovePP(BtlServerFlow *flow, u8 *a, u32 b, u8 c)
{
    u8 limit = BTL_POKEPARAM_GetMovePPChecked((struct UtilWork *)a, b);
    if (c >= limit) c = limit;
    if (c != 0) {
        BTL_SERVER_FLOW_DecrementMovePP(flow, a, b, c);
        return 1;
    }
    return 0;
}












void BTL_SERVER_FLOW_DecrementMovePP(BtlServerFlow *flow, u8 *a, int b, u8 c)
{
    u32 n;
    if (func_021B911C(flow->mainModule, 5) == 0) {
        n = BTL_POKEPARAM_GetPokeId(a);
        BTL_POKEPARAM_DecrementMovePP((struct UtilWork *)a, b, c);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 4, n, b, c);
        BTL_POKEPARAM_MarkMoveUsed((struct Work *)a, b);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 6, n, b);
    }
}











void BTL_SERVER_FLOW_ProcMoveHitTargets(BtlServerFlow *flow, u8 *q, u8 *a, u8 *b, const u32 *c, u32 d)
{
    u32 result = 0;
    int flag = 0;
    u32 out;
    flow->onceFlags[1] = 0;
    BTL_SERVER_FLOW_RunMoveUsedEventLocked(flow, a, q);
    func_0689CB3C(flow->curDamageSet);
    BTL_SERVER_FLOW_CalcMultiHitCount(flow, a, ((struct Obj04358 *)q)->f0, flow->curHitFlags);
    BTL_SERVER_FLOW_RemoveSelfProtectedTargets(flow, a, (int)q, b);
    if (func_0689CD38(b) != 0) {
        if (BTL_SERVER_FLOW_GetHitFlagsMultiHit(flow->curHitFlags) != 0 && func_0689CD40(b) == 1) {
            result = BTL_SERVER_FLOW_ProcMultiHitDamage(flow, q, a, b, c);
        } else {
            result = BTL_SERVER_FLOW_ProcDamageTargets(flow, q, a, b, c, &out, d);
            flag = 1;
        }
        BTL_SERVER_FLOW_ProcDamageAbsorbRecovery(flow, a, ((struct Obj04358 *)q)->f0, result);
    }
    BTL_SERVER_FLOW_ProcMoveAfterDamageEvents(flow, q, a, flow->curDamageSet, result, d);
    if (flag != 0) {
        struct State_p06 *s = (struct State_p06 * )flow->curTurnState;
        if (s->a == 0) {
            s->a = 1;
            s->b = 1;
        }
        BTL_SERVER_FLOW_PushPendingHpRecovery(flow, ((struct Obj04358 *)q)->f0, flow->curTurnState, out);
    }
}









void BTL_SERVER_FLOW_BuildDamageList(BtlServerFlow *flow, u8 *a, u8 *b, const u8 *q, const u32 *c, u32 k, struct List_021BDB88 *out)
{
    int i = 0;
    u8 *r;
    struct { u16 x, y; } temp;
    out->good = 0;
    out->bad = 0;
    func_0689CC84(b);
    r = func_0689CC8C(b);
    if (r != 0) {
        do {
            out->entries[i].id = BTL_POKEPARAM_GetPokeId(r);
            out->entries[i].marked = (u16)BTL_SERVER_FLOW_CheckCriticalHit(flow, a, r, (u32)(((struct Obj21063 *)q)->f0));
            out->entries[i].mode = (u16)(int)func_021CC8B8((u32 *)c, (u8)out->entries[i].id);
            out->entries[i].special = (u16)BTL_SERVER_FLOW_CalcMoveDamage(flow, a, r, q, out->entries[i].mode, k, out->entries[i].marked, 0, &temp.y);
            out->entries[i].value = temp.y;
            if (out->entries[i].special) {
                out->entries[i].marked = 0;
                out->entries[i].mode = 3;
            }
            out->entries[i].error = (u16)BTL_POKEPARAM_HasSubstitute(r);
            if (!out->entries[i].error) {
                temp.x = BTL_SERVER_FLOW_ClampDamageToHp(r, out->entries[i].value);
                out->entries[i].type = (u16)BTL_SERVER_FLOW_CheckEndureEvent(flow, a, r, 1, &temp.x);
                out->entries[i].value = temp.x;
                out->good++;
            } else {
                out->entries[i].value = temp.y;
                out->entries[i].type = 0;
                out->bad++;
            }
            func_021C7C24((u16 *)flow->turnDeadRecord, (int)flow, a, r, out->entries[i].mode);
            i++;
            r = func_0689CC8C(b);
        } while (r != 0);
    }
    out->count = i;
}










/* 021C0C34  ldrb r0,[r0,#2] */
/*
 * Reads the u8 field at #2 of the argument and returns it.
 */
u32 BTL_SERVER_FLOW_GetHitFlagsByte2(u8 *p) { return p[2]; }










int BTL_SERVER_FLOW_UnpackDamageEntries(BtlServerFlow *flow, const List_td *l, u32 *o0, u16 *o1, u32 *o2, u8 *o3)
{
    u32 i = 0;
    int k = 0;
    for (; i < l->n; i++) {
        if (l->r[i].flag) {
            o0[k] = (u32)func_021B9934(flow->pokeCon, (u8)l->r[i].idx);
            o1[k] = l->r[i].v;
            o2[k] = l->r[i].b;
            o3[k] = l->r[i].c;
            k++;
        }
    }
    return k;
}










/*
 * Record shape follows the matched unpacker BTL_SERVER_FLOW_UnpackHitEntries.
 * The byte count admits multiple four-byte trailing records (q+4+i*4);
 * a flexible array models that extent without imposing a one-record bound.
 * The original narrows the five-bit field to u8 before the call.
 */
int BTL_SERVER_FLOW_UnpackEntryPokes(BtlServerFlow *flow, const struct Q_021C0CB4 *q, u32 *out)
{
    u32 i = 0;
    for (; i < q->n; i++)
        out[i] = (u32)func_021B9934(flow->pokeCon, (u8)q->e[i].lo);
    return q->n;
}











/*
 * Structure recovered (7 parameters; the three stack pointers are re-stored to
 * their own slots in the prologue, `ldr r0,[sp,#0x28]; str r0,[sp,#0x28]`,
 * which the compiled code reproduces). Entries at q+4, stride 4: {u16 v; u16
 * bitfield}, bitfield lo:5 b:4 c:4 d:1 e:1 f:1 (LSB first: lsls #0x1b, #0x17,
 * #0x13, #0x12, #0x10 pairs). Loop keeps entries with f == 0 and packs
 * o1[n]=func_021B9934(p[8], lo) (u8 argument: a `lsls/lsrs #0x18` follows the
 * 5-bit extract), o2[n]=v, o3[n]=b, o4[n]=d, o5[n]=c.
 *
 * Residue: register/spill allocation of the loop. Original: q in r6, i in r7,
 * n in r4, i*4 in r5, the hoisted q+6 spilled to [sp+0x10], flag test through
 * (q+r5)+6 and the lo/b/c/d fields through ONE shared halfword load from the
 * hoisted base (`ldrh r0,[r0,r5]` after `ldr r0,[sp,#0x10]`) with the flag and v read
 * separately through q+r5. Compiled: q in r7, i spilled to [sp+0x10], the hoisted
 * q+6 in r6, and each bitfield reloaded from memory (138 B against 136 B, no
 * cast; 142 B with the u8 parameter). Struct Bits copy (`t = e[i].bits`) gives
 * the single shared load but adds a stack temp and swaps i/n.
 *
 * checks: 1 func_021B9934 is (char *p, int i) in its matched file; the original casts the lo field to u8 before the bl, so the extern parameter is u8 (tried: +4 bytes of cast, spills unchanged); 2 no twin in ov093 with a 7-parameter bitfield unpack; 3 u32/int for i and n, u8-cast loop bound, n declared before i, struct Bits copy for b/c/d, manual (h>>5)&0xf form (gives asrs/ands, wrong), pointer form q+4 cast to struct Ent: none moved q into r6 and i into r7; 4 none fits (declaration-order idiom tried as n-before-i, no change); 5 no new idiom. Sweep I would run: the permuter over declaration order and over which of the flag/lo/b/c/d reads go through a shared u16 local.
 */
int BTL_SERVER_FLOW_UnpackHitEntries(BtlServerFlow *flow, const struct Q_021C0CE8 *q, u32 *o1, u16 *o2, u32 *o3, u8 *o4, u8 *o5)
{
    u32 i = 0;
    u32 n = 0;
    for (; i < q->n; i++) {
        if (q->e[i].f == 0) {
            o1[n] = (u32)func_021B9934(flow->pokeCon, (u8)q->e[i].lo);
            o2[n] = q->e[i].v;
            o3[n] = q->e[i].b;
            o4[n] = q->e[i].d;
            o5[n] = q->e[i].c;
            n++;
        }
    }
    return n;
}










/*
 * Extent ends with two zero alignment bytes at 0x021C0D8E.
 * Declare i before sum, but initialize sum before i, to reproduce both
 * register allocation and the order of the initial movs instructions.
 * Each record supplies the halfword at offset 4, stride 4.
 */
u32 BTL_SERVER_FLOW_SumHitRecordDamage(const u8 *q)
{
    u32 i;
    u32 sum = 0;
    i = 0;
    for (; i < q[2]; i++)
        sum += *(const u16 *)(q + 4 + i * 4);
    return sum;
}








u32 BTL_SERVER_FLOW_ProcDamageTargets(BtlServerFlow *flow, u8 *q, u8 *a, u8 *b, const u32 *c, u32 *out, u32 d)
{
    u16 k;
    u32 result;
    CallFlags f;
    if (func_0689CD40(b) == 1) k = 0x1000;
    else k = 0xc00;
    result = 0;
    f.bits.a = func_0689CD38(b) > 1;
    f.bits.b = d;
    func_0689CDCC(b, a, flow->curHitSetA);
    func_0689CE58(b, a, flow->curHitSetB);
    BTL_SERVER_FLOW_BuildDamageList(flow, a, flow->curHitSetA, q, c, k, flow->curHitRecordA);
    BTL_SERVER_FLOW_BuildDamageList(flow, a, flow->curHitSetB, q, c, k, flow->curHitRecordB);
    *out = BTL_SERVER_CMD_Reserve(flow->cmdQueue, 0x30);
    if (func_0689CD38(flow->curHitSetA) != 0) {
        result += BTL_SERVER_FLOW_ProcDamageRecordIfAny(flow, (u16 *)q, a, flow->curHitSetA, flow->curHitRecordA, flow->curHitFlags, k, f);
        if (result != 0 && BTL_SERVER_FLOW_IsPlayerSidePoke(flow, a) != 0)
            func_021BA1B4((char **)(flow->mainModule), 0x4d);
    }
    if (func_0689CD38(flow->curHitSetB) != 0)
        result += BTL_SERVER_FLOW_ProcDamageRecordIfAny(flow, (u16 *)q, a, flow->curHitSetB, flow->curHitRecordB, flow->curHitFlags, k, f);
    return result;
}







u32 BTL_SERVER_FLOW_ProcMultiHitDamage(BtlServerFlow *flow, u8 *q, u8 *a, u8 *d, const u32 *c)
{
    u32 i;
    u32 completed;
    u32 sum = 0;
    int old;
    u8 tag = 6;
    u8 *b = (u8 *)func_0689CC70(d, 0);
    struct State_p06 *s;
    CallFlags f;
    flow->lastPokeId = BTL_POKEPARAM_GetPokeId(b);
    if (BTL_MAIN_CheckSceneOff(flow->mainModule)) {
        tag = func_0689D5C8(flow->posPoke, BTL_POKEPARAM_GetPokeId(b));
        if (tag != 6) {
            BTL_SERVER_CMD_Push(flow->cmdQueue, 0x4e,
                func_0689D5C8(flow->posPoke, BTL_POKEPARAM_GetPokeId(a)), tag, 0x27e);
        }
    }
    i = 0;
    completed = 0;
    f.word = 0;
    for (; i < (flow->curHitFlags)[0]; i++) {
        old = BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)a);
        s = (struct State_p06 * )flow->curTurnState;
        if (s->a == 0) {
            s->a = 1;
            s->b = 1;
        }
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x30,
            (flow->curTurnState)[2], (flow->curTurnState)[3], ((struct Obj21074 *)q)->f0, 0);
        BTL_SERVER_FLOW_BuildDamageList(flow, a, d, q, c, 0x1000, flow->curHitRecordB);
        sum += BTL_SERVER_FLOW_ProcDamageRecordIfAny(flow, (u16 *)q, a, d,
            flow->curHitRecordB, (u8 *)flow->curHitFlags, 0x1000, f);
        completed++;
        if (BTL_POKEPARAM_IsFainted(b)) break;
        if (BTL_POKEPARAM_IsFainted(a)) break;
        BTL_SERVER_FLOW_ProcDamagedItemReaction(flow, b, 1);
        if (BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)a) == 2 && old != 2) break;
        if ((flow->curHitFlags)[2] != 0 &&
            !BTL_SERVER_FLOW_RollMoveAccuracy(flow, a, b, (struct Q *)q)) break;
    }
    if (completed != 0) {
        func_021C15AC(flow, (flow->curHitFlags)[5]);
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 0x20, completed, 0xffff0000);
    }
    if (BTL_POKEPARAM_IsFainted(b)) {
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0, BTL_POKEPARAM_GetPokeId(b), 0xffff0000);
    }
    if (tag != 6) {
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x4d,
            func_0689D5C8(flow->posPoke, BTL_POKEPARAM_GetPokeId(a)), 0x291);
    }
    flow->lastPokeId = 0x1f;
    return sum;
}
















int BTL_SERVER_FLOW_IsFirstHit(const u8 *p)
{
    return p[1] == 0;
}


















/* 021C1194  ldrb r0,[r0,#3] */
u8 BTL_SERVER_FLOW_GetHitFlagsMultiHit(u8 *p) { return p[3]; }

















void BTL_SERVER_FLOW_SetHitFlagsResultIf3(unsigned char *p, int x)
{
    if (p[5] == 3) {
        p[5] = x;
    }
}
















u32 BTL_SERVER_FLOW_ProcDamageRecordIfAny(BtlServerFlow *flow, u16 *a, u8 *b, u8 *c, u8 *d, u8 *e, u32 f, CallFlags g)
{
    u32 r;
    if ((u8)BTL_SERVER_FLOW_GetHitFlagsByte2(d) != 0) {
        r = BTL_SERVER_FLOW_ApplyDamageRecord(flow, b, c, d, a, e, f, g);
        BTL_SERVER_FLOW_RunDamageDealtEventLocked(flow, b, (u8 *)a, r);
        return r;
    }
    return 0;
}















/*
 * 2026-10-05 Q10/Q10b/Q10c/G7L9 (pengy share, user-approved): body from the listing, 47 of 704 bytes off (spill
 *   slot order m/k*4 around the third count, and the 5798/5840/59C4 argument order). Facts kept: v28 is u8,
 *   021C4104 takes sa/sb as separate stack args, 021C1198 takes an int, a7 is a one-bit field struct, the last
 *   loop's byte argument is d_021F3B20[k], 021C5798 has 8 parameters (two unused).
 * pass 2 2026-10-06 P2L45: EXACT (was 47 bytes off). Closing form: variables reused as a person would. The third
 *   count reuses `cnt` (no separate cnt3), the m loop reuses `j` from the cnt2 loop, and the later loops reuse
 *   `i` (neutral). A reused variable gets a second web numbered after the declared locals, which puts the m index
 *   at the lowest slot and the k*4 temp above the count (36 B). Then `cnt` and `cnt2` as u8 (the counts are u8
 *   results): mwcc keeps the reload of a spilled narrow local below the outgoing stack stores
 *   (docs/idioms/a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local.md), which fixes the
 *   5798/5840/59C4 order; u8 cnt2 fixes the cnt/cnt2 slot swap. No (u8) casts needed. EXACT in --lang c99 and c.
 */
int BTL_SERVER_FLOW_ApplyDamageRecord(BtlServerFlow *flow, u8 *x, u8 *unused, u8 *y, u16 *e, u8 *st, u32 a6, CallFlags a7)
{
    int sum;
    u8 v28;
    u8 cnt;
    u8 cnt2;
    u16 h;
    int i;
    int j;
    int flag;

    v28 = func_0689D5C8(flow->posPoke, BTL_POKEPARAM_GetPokeId(x));
    sum = BTL_SERVER_FLOW_SumHitRecordDamage(y);
    cnt = BTL_SERVER_FLOW_UnpackDamageEntries(flow, (List_td *)y, (u32 *)d_021F3B38, (u16 *)d_021F3B26, (u32 *)d_021F3B2C, (u8 *)d_021F3B20);
    for (i = 0; i < cnt; i++) {
        if (BTL_POKEPARAM_HasSubstitute(d_021F3B38[i])) {
            h = BTL_SERVER_FLOW_ProcSubstituteDamage(flow, x, d_021F3B38[i], d_021F3B26[i], d_021F3B2C[i], d_021F3B20[i], e);
            func_0689CBB8(flow->curDamageSet, d_021F3B38[i], h, 1);
            sum -= d_021F3B26[i] - h;
        }
    }
    if (BTL_SERVER_FLOW_IsFirstHit(st)) {
        cnt2 = BTL_SERVER_FLOW_UnpackEntryPokes(flow, (const struct Q_021C0CB4 *)y, (u32 *)d_021F3B38);
        for (j = 0; j < cnt2; j++)
            BTL_SERVER_FLOW_RunMoveHitEventLocked(flow, x, d_021F3B38[j], e);
    }
    st[1] = st[1] + 1;
    cnt = BTL_SERVER_FLOW_UnpackHitEntries(flow, (const struct Q_021C0CE8 *)y, (u32 *)d_021F3B38, d_021F3B26, d_021F3B2C, d_021F3B20, d_021F3B23);
    if (cnt == 0)
        return sum;
    BTL_SERVER_FLOW_RunTargetsDamagedEventLocked(flow, (u32)e, x, cnt, (u32 *)d_021F3B38);
    flag = a7.bits.a;
    BTL_SERVER_FLOW_PushMoveEffectiveness(flow, e, cnt, (int *)d_021F3B2C, d_021F3B38, d_021F3B26, d_021F3B20, flag);
    if (BTL_SERVER_FLOW_GetHitFlagsMultiHit(st) == 0)
        func_021C5840(flow, cnt, (int *)d_021F3B2C, d_021F3B38, flag);
    else
        BTL_SERVER_FLOW_SetHitFlagsResultIf3(st, d_021F3B20b[3]);
    BTL_SERVER_FLOW_PushCriticalHitMessage(flow, cnt, d_021F3B38, d_021F3B20, flag);
    for (j = 0; j < cnt; j++) {
        func_0689CBB8(flow->curDamageSet, d_021F3B38[j], d_021F3B26[j], 0);
        BTL_SERVER_FLOW_RecordDamageHit(flow, v28, x, d_021F3B38[j], (u8 *)e, d_021F3B26[j]);
        BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)d_021F3B38[j], 2);
    }
    for (i = 0; i < cnt; i++) {
        if (d_021F3B23[i])
            BTL_SERVER_FLOW_ProcDamageAftereffect(flow, d_021F3B38[i], d_021F3B23[i]);
    }
    for (i = 0; i < cnt; i++) {
        BTL_SERVER_FLOW_ProcFlinchChance(flow, e, x, d_021F3B38[i]);
        BTL_SERVER_FLOW_ProcDrainHeal(flow, (u8 *)e, (u32)x, d_021F3B38[i], d_021F3B26[i]);
        BTL_SERVER_FLOW_ProcMoveCategoryEffect(flow, (u8 *)e, x, d_021F3B38[i], d_021F3B26[i], 0);
        BTL_SERVER_FLOW_ProcDamageEndEvents(flow, x, d_021F3B38[i], (u8 *)e, d_021F3B2C[i], d_021F3B26[i], d_021F3B20[i], 0);
    }
    for (i = 0; i < cnt; i++)
        BTL_SERVER_FLOW_ProcFaintedPoke(flow, d_021F3B38[i]);
    BTL_SERVER_FLOW_ProcFaintedPoke(flow, x);
    return sum;
}














void BTL_SERVER_FLOW_RemoveSelfProtectedTargets(BtlServerFlow *flow, u8 *a, int b, u8 *c)
{
    u8 *r;
    u32 s;
    func_0689CC84(c);
    r = func_0689CC8C(c);
    if (r != 0) {
        do {
            if (BTL_SERVER_FLOW_QueryTypeImmunityEvent(flow, a, r, (u8 *)b) != 0) {
                struct St *st = (struct St * )flow->curTurnState;
                if (st->f == 0) st->f = 1;
                s = func_021CC8D8(&flow->lock, 0x197b);
                BTL_SERVER_FLOW_NotifyTypeImmunityEvent(flow, a, r);
                func_021CC95C(&flow->lock, s, 0x197f);
                func_0689CC14(c, r);
            }
            r = func_0689CC8C(c);
        } while (r != 0);
    }
}

















void func_021C15AC(BtlServerFlow *flow, int k)
{
    if (k < 3) {
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 0x4f, 0xffff0000);
    } else if (k > 3) {
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 0x4e, 0xffff0000);
    }
}


















u32 BTL_SERVER_FLOW_ClampDamageToHp(void *p, u32 n)
{
    u32 v = func_021D59B4(p, 13);
    if (n > v) n = v;
    return n;
}


















/*
 * interface: Complete lock word returned in r0 at 021CC900; restore
 * 021CC95C stores the unchanged full r1 word. Scalar u32 preserves all bits.
 */
void BTL_SERVER_FLOW_RunMoveHitEventLocked(BtlServerFlow *flow, u8 *a, u8 *b, u16 *c)
{
    u32 s = func_021CC8D8(&flow->lock, 6570);
    BTL_SERVER_FLOW_RunMoveHitEvent(flow, a, b, c);
    func_021CC95C(&flow->lock, s, 6570 + 4);
}

















void BTL_SERVER_FLOW_RunMoveHitEvent(BtlServerFlow *flow, u8 *a, u8 *b, u16 *c)
{
    BTL_EVENT_PushVarFrame(0x19bd);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x12, c[0]);
    BTL_EVENT_SetVarReadOnly(0x16, ((u8 *)c)[6]);
    func_021D70F0(flow, 0x45);
    BTL_EVENT_PopVarFrame(0x19bd + 7);
}

















int BTL_SERVER_FLOW_CheckEndureEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c, u16 *d)
{
    int r;
    if (func_021D59B4(b, 13) > *d) return 0;
    BTL_EVENT_PushVarFrame(0x19df);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x51, c);
    BTL_EVENT_SetVarOnce(0x3a, 0);
    func_021D70F0(flow, 0x74);
    r = BTL_EVENT_GetVar(0x3a);
    BTL_EVENT_PopVarFrame(0x19df + 7);
    if (r != 0) *d = func_021D59B4(b, 13) - 1;
    return r;
}

















/*
 * The empty `case 3: break;` is what keeps the `cmp r4, #3` and the
 * unconditional branch; a plain `if (k == 3) {}` compiles differently.
 */
void BTL_SERVER_FLOW_ProcDamageAftereffect(BtlServerFlow *flow, u8 *a, int k)
{
    u32 s;
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    switch (k) {
    case 1:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x202, n, 0xffff0000);
        return;
    case 3:
        break;
    }
    s = func_021CC8D8(&flow->lock, 0x1a04);
    BTL_SERVER_FLOW_RunDamageAftereffectEvent(flow, a, k);
    func_021CC95C(&flow->lock, s, 0x1a07);
}

















void BTL_SERVER_FLOW_RunDamageAftereffectEvent(BtlServerFlow *flow, u8 *q, int k)
{
    BTL_EVENT_PushVarFrame(0x1a17);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(q));
    func_021D70F0(flow, 0x75);
    BTL_EVENT_PopVarFrame(0x1a17 + 3);
}
















void BTL_SERVER_FLOW_RunTargetsDamagedEventLocked(BtlServerFlow *flow, u32 x, u8 *a, u32 n, u32 *arr)
{
    u32 s = func_021CC8D8(&flow->lock, 6697);
    BTL_SERVER_FLOW_RunTargetsDamagedEvent(flow, x, a, n, (u8 **)arr);
    func_021CC95C(&flow->lock, s, 6702);
}
















void BTL_SERVER_FLOW_RunTargetsDamagedEvent(BtlServerFlow *flow, u32 x, u8 *a, u32 n, u8 **arr)
{
    u32 i;
    BTL_EVENT_PushVarFrame(6719);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(5, n);
    for (i = 0; i < n; i++) {
        BTL_EVENT_SetVarReadOnly(6 + i, BTL_POKEPARAM_GetPokeId(arr[i]));
    }
    func_021D70F0(flow, 0x44);
    BTL_EVENT_PopVarFrame(6727);
}
















/*
 * The Rec build loads q[6] and q[0] first (ldrb, ldrh) only when both are
 * read into their own locals (c6 before a0), assigned after the second
 * BTL_POKEPARAM_GetPokeId call; reading them straight into the fields interleaves
 * loads and stores.
 */
void BTL_SERVER_FLOW_RecordDamageHit(BtlServerFlow *flow, u8 b, u8 *x, u8 *c, u8 *q, u16 w)
{
    struct Rec_p09 r;
    u8 c6;
    u16 a0;
    u8 n = BTL_POKEPARAM_GetPokeId(x);
    u8 m = BTL_POKEPARAM_GetPokeId(c);
    c6 = q[6];
    a0 = ((struct Obj02778 *)q)->f0;
    r.a = a0;
    r.b = w;
    r.c = c6;
    r.d = n;
    r.e = b;
    BTL_POKEPARAM_AddHitRecord(c, &r);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x2d, m, n, b, q[6], ((struct Obj02778 *)q)->f0, w);
}
















void BTL_SERVER_FLOW_ProcMoveCategoryEffect(BtlServerFlow *flow, u8 *q, u8 *a, u8 *b, u32 s0, int s1)
{
    switch (WAZA_TOOL_GetCategory(((struct Obj09968 *)q)->f0)) {
    case 7:
        BTL_SERVER_FLOW_ProcMoveAddedRankEffect(flow, (u16 *)q, a, a);
        break;
    case 6:
        if (s1 == 0) {
            BTL_SERVER_FLOW_ProcMoveAddedRankEffect(flow, (u16 *)q, a, b);
        }
        break;
    case 4:
        if (s1 == 0) {
            BTL_SERVER_FLOW_ProcMoveAddedSick(flow, (const u16 *)q, a, b);
        }
        break;
    }
}
















void BTL_SERVER_FLOW_RunDamageDealtEventLocked(BtlServerFlow *flow, u8 *a, u8 *q, u32 v)
{
    u32 s = func_021CC8D8(&flow->lock, 6802);
    BTL_SERVER_FLOW_RunDamageDealtEvent(flow, a, q, v);
    func_021CC95C(&flow->lock, s, 6802 + 3);
}
















void BTL_SERVER_FLOW_RunDamageDealtEvent(BtlServerFlow *flow, u8 *a, u8 *q, u32 v)
{
    BTL_EVENT_PushVarFrame(6823);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, ((struct Obj13323 *)q)->f0);
    BTL_EVENT_SetVarReadOnly(0x16, q[6]);
    BTL_EVENT_SetVarReadOnly(0x32, v);
    func_021D70F0(flow, 0x4d);
    BTL_EVENT_PopVarFrame(6829);
}
















void BTL_SERVER_FLOW_ProcDamagedItemReaction(BtlServerFlow *flow, u8 *q, u32 n)
{
    if (BTL_POKEPARAM_GetItem((struct QI *)q)) {
        u32 s = func_021CC8D8(&flow->lock, 6844);
        BTL_SERVER_FLOW_RunDamagedItemEvent(flow, q, n);
        func_021CC95C(&flow->lock, s, 6850);
    }
}















void BTL_SERVER_FLOW_RunDamagedItemEvent(BtlServerFlow *flow, u8 *q, u32 n)
{
    BTL_EVENT_PushVarFrame(0x1acf);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(q));
    BTL_EVENT_SetVarReadOnly(0x2e, n);
    func_021D70F0(flow, 0x91);
    BTL_EVENT_PopVarFrame(0x1acf + 4);
}















void BTL_SERVER_FLOW_RunMoveUsedEventLocked(BtlServerFlow *flow, u8 *a, u8 *q)
{
    u32 s = func_021CC8D8(&flow->lock, 6874);
    BTL_SERVER_FLOW_RunMoveUsedEvent(flow, a, q);
    func_021CC95C(&flow->lock, s, 6874 + 2);
}















void BTL_SERVER_FLOW_RunMoveUsedEvent(BtlServerFlow *flow, u8 *a, u8 *q)
{
    BTL_EVENT_PushVarFrame(6890);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, ((struct Obj13324 *)q)->f0);
    BTL_EVENT_SetVarReadOnly(0x16, q[6]);
    func_021D70F0(flow, 0x81);
    BTL_EVENT_PopVarFrame(6897);
}














void BTL_SERVER_FLOW_ProcMoveAfterDamageEvents(BtlServerFlow *flow, u8 *a, u8 *b, u8 *c, u32 unused, u32 d)
{
    u32 lock;
    u8 *x;
    BTL_SERVER_FLOW_ThawTargetsHitByFireMove(flow, a, (u32)b, c);
    lock = func_021CC8D8(&flow->lock, 0x1b07);
    BTL_SERVER_FLOW_RunMoveDamageGroupEvent(flow, b, c, a, d, 0, 0x84);
    BTL_SERVER_FLOW_RunMoveDamageGroupEvent(flow, b, c, a, d, 1, 0x83);
    BTL_SERVER_FLOW_RunMoveDamageGroupEvent(flow, b, c, a, d, 0, 0x85);
    func_0689CC84(c);
    x = func_0689CC8C(c);
    while (x) {
        BTL_SERVER_FLOW_ProcDamagedItemReaction(flow, x, 1);
        x = func_0689CC8C(c);
    }
    BTL_SERVER_FLOW_RunMoveDamageGroupEvent(flow, b, c, a, d, 0, 0x86);
    BTL_SERVER_FLOW_RunMoveDamageGroupEvent(flow, b, c, a, d, 1, 0x87);
    BTL_SERVER_FLOW_RunMoveDamageEndEvent(flow, b, (u32)c, a, d);
    func_021CC95C(&flow->lock, lock, 0x1b1b);
}











void BTL_SERVER_FLOW_RunMoveDamageGroupEvent(BtlServerFlow *flow, u8 *a, u8 *b, u8 *c, u32 d, u8 e, int f)
{
    u32 sum;
    u32 n;
    u32 got;
    u32 i;
    u32 v;
    u8 *x;
    int ok;
    n = func_0689CD38(b);
    sum = 0;
    got = 0;
    BTL_EVENT_PushVarFrame(0x1b2b);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x4d, d);
    BTL_EVENT_SetVarReadOnly(0x12, ((struct Obj13325 *)c)->f0);
    BTL_EVENT_SetVarReadOnly(0x16, c[6]);
    for (i = 0; i < n; i++) {
        x = func_0689CC70(b, i);
        if (e) ok = func_0689CCF8(b, x, &v);
        else ok = func_0689CCB4(b, x, &v);
        if (ok) {
            sum += v;
            BTL_EVENT_SetVarReadOnly(got + 6, BTL_POKEPARAM_GetPokeId(x));
            got++;
        }
    }
    if (got) {
        BTL_EVENT_SetVarReadOnly(5, got);
        BTL_EVENT_SetVarOnce(0x47, 0);
        BTL_EVENT_SetVarOnce(0x48, 0);
        BTL_EVENT_SetVarReadOnly(0x32, sum);
        func_021D70F0(flow, 0x82);
        if (!BTL_EVENT_GetVar(0x48)) func_021D70F0(flow, f);
    }
    BTL_EVENT_PopVarFrame(0x1b52);
}












void BTL_SERVER_FLOW_RunMoveDamageEndEvent(BtlServerFlow *flow, u8 *a, u32 unused, u8 *q, u32 v)
{
    BTL_EVENT_PushVarFrame(7009);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x4d, v);
    BTL_EVENT_SetVarReadOnly(0x12, ((struct Obj21079 *)q)->f0);
    func_021D70F0(flow, 0x88);
    BTL_EVENT_PopVarFrame(7014);
}












int BTL_SERVER_FLOW_ProcFlinchChance(BtlServerFlow *flow, u16 *x, u8 *a, u8 *q)
{
    int n;
    n = func_021C7664(flow, *x, a);
    return BTL_SERVER_FLOW_RollFlinch(flow, q, n);
}













void BTL_SERVER_FLOW_ThawTargetsHitByFireMove(BtlServerFlow *flow, u8 *q, u32 unused, u8 *w)
{
    u8 *t;
    if (q[6] == 9) {
        func_0689CC84(w);
        t = func_0689CC8C(w);
        while (t) {
            int k = 3;
            if (BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)t) == 3 && BTL_POKEPARAM_HasSubstitute(t) == 0) {
                BTL_SERVER_FLOW_CureMajorStatusWithMessage(flow, t, k, 1);
            }
            t = func_0689CC8C(w);
        }
    }
}












int BTL_SERVER_FLOW_RollFlinch(BtlServerFlow *flow, u8 *q, u32 n)
{
    if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)q, 5)) {
        BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)q, 6);
        return 1;
    }
    if (func_021C76F4(flow, q, n)) {
        BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)q, 4);
        return 1;
    }
    if (n >= 100) {
        u32 s = func_021CC8D8(&flow->lock, 7085);
        func_021C7780(flow, q);
        func_021CC95C(&flow->lock, s, 7087);
    }
    return 0;
}












void BTL_SERVER_FLOW_ProcDrainHeal(BtlServerFlow *flow, u8 *q, u32 a, u8 *b, u32 s)
{
    if (WAZA_TOOL_GetCategory(((struct Obj09967 *)q)->f0) == 8) {
        if (BTL_SERVER_FLOW_RecoverHpFromDrain(flow, (u8 *)a, (u32)b, (u16)BTL_CALC_MulPercent(s, sub_0201BD28(((struct Obj09967 *)q)->f0, 0x19)))) {
            BTL_SERVER_FLOW_PushMsgSetPoke(flow, b, 0x383);
        }
    }
}












int BTL_SERVER_FLOW_RecoverHpFromDrain(BtlServerFlow *flow, u8 *q, u32 a, u32 b)
{
    u32 s = func_021CC8D8(&flow->lock, 7154);
    int r = 0;
    u8 *t = (u8 *)func_021C78F4(flow, q, (u8 *)a, b);
    if (t) {
        if (BTL_SERVER_FLOW_IsHpRecoverUnneeded(flow, q) == 0) {
            r = BTL_SERVER_FLOW_TryRecoverHp(flow, q, (int)t, 1);
        }
    }
    func_021CC95C(&flow->lock, s, 7168);
    return r;
}











/*
 *   Call +0x10 has no witness outside 021C1E74..021C2048; all concrete
 *   bytes match, and the other 39 relocation sites resolve.
 *   Verified one --thumb, no --region, dsi/1.1p1 -O4,p: EXACT, 12 bytes.
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   extern u32 sub_0201BD28(u16, u32);
 * lever: a separately narrowed u8 level local avoids the extra r0-to-r2
 *   copy from narrowing an inline call argument. value * scale selects
 *   the original multiplication destination; scale * value adds a copy.
 */
int BTL_SERVER_FLOW_CalcMoveDamage(BtlServerFlow *flow, u8 *a, u8 *b, const u8 *c, u32 d, u32 e, u32 f, int g, u16 *out)
{
    int category = WAZA_TOOL_GetDamageType(*(u16 *)c);
    int flag = 0;
    u32 result;
    u32 x;
    u32 y;
    u32 value;
    u32 factor;
    u16 scale;
    u8 level;
    BTL_EVENT_PushVarFrame(0x1c21);
    BTL_EVENT_SetVarReadOnly(0x38, d);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x45, f);
    BTL_EVENT_SetVarReadOnly(0x16, c[6]);
    BTL_EVENT_SetVarReadOnly(0x12, *(u16 *)c);
    BTL_EVENT_SetVarReadOnly(0x1a, category);
    BTL_EVENT_SetVar(0x37, 0);
    func_021D70F0(flow, 0x46);
    result = (u32)BTL_EVENT_GetVar(0x37);
    if (result) {
        flag = 1;
    } else {
        x = BTL_SERVER_FLOW_CalcMovePower(flow, a, b, c);
        y = func_021C7374(flow, a, b, c, f);
        value = func_021C7474(flow, a, b, c, f);
        level = func_021D59B4(a, 15);
        value = BTL_CALC_CalcBaseDamage(x, y, level, value);
        if (e != 0x1000) value = BTL_CALC_MulRatio(value, e);
        factor = BTL_CALC_GetWeatherMoveRatio(BTL_SERVER_FLOW_GetEffectiveWeather(flow), c[6]);
        if (factor != 0x1000) value = BTL_CALC_MulRatio(value, factor);
        if (f) value *= 2;
        if (!func_021B911C(flow->mainModule, 7)) {
            if (g) scale = 85;
            else scale = 100 - BTL_CALC_Random(16);
            value = (u32)(value * scale) / 100u;
        }
        if (c[6] != 17) value = BTL_CALC_MulRatio(value, func_021C75EC(flow, a, c[6]));
        value = BTL_CALC_ApplyTypeAffinity(value, d);
        if (category == 1 && BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)a) == 4 && func_021D59B4(a, 17) != 62) {
            value = (u32)(50u * value) / 100u;
        }
        if (!value) value = 1;
        BTL_EVENT_SetVarRanged(0x35, 0x1000, 0x29, 0x20000);
        BTL_EVENT_SetVar(0x32, value);
        func_021D70F0(flow, 0x47);
        factor = (u32)BTL_EVENT_GetVar(0x35);
        result = BTL_CALC_MulRatio((u32)BTL_EVENT_GetVar(0x32), factor);
    }
    func_021D70F0(flow, 0x48);
    BTL_EVENT_PopVarFrame(0x1c8d);
    *out = result;
    return flag;
}












void BTL_SERVER_FLOW_ProcDamageAbsorbRecovery(BtlServerFlow *flow, u8 *a, u16 b, u32 c)
{
    int loc;
    int r;
    if (BTL_POKEPARAM_IsFainted(a) != 0)
        return;
    r = BTL_SERVER_FLOW_CalcMoveDrainRecoil(flow, a, b, c, &loc);
    if (r == 0)
        return;
    func_021C8838(flow->msgParam, 2, 378);
    func_021C8860((struct S_p12 *)flow->msgParam, BTL_POKEPARAM_GetPokeId(a));
    if (loc == 0 && BTL_SERVER_FLOW_CheckAbsorbRecoverAllowed(flow, a, r) == 0)
        return;
    BTL_SERVER_FLOW_ProcAbsorbRecovery(flow, a, r, flow->msgParam);
}











/*
 * extent: two zero alignment bytes follow the return at 0x021C20CE.
 */
int BTL_SERVER_FLOW_CheckAbsorbRecoverAllowed(BtlServerFlow *flow, u8 *a, int r)
{
    if (BTL_SERVER_FLOW_QueryTargetableEvent(flow, a))
        return 1;
    return 0;
}












int BTL_SERVER_FLOW_ProcAbsorbRecovery(BtlServerFlow *flow, u8 *a, int c, u8 *l)
{
    int r;
    c = -c;
    if (c != 0) {
        BTL_SERVER_FLOW_ChangeHp(flow, a, c, 1);
        BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, 2);
        if (l != 0) {
            func_021C99A0(flow, (const struct Msg *)l);
            func_021C8810(l);
        }
        r = 1;
        BTL_SERVER_FLOW_ProcDamagedItemReaction(flow, a, 1);
        if (BTL_SERVER_FLOW_ProcFaintedPoke(flow, a) != 0) {
            BTL_SERVER_FLOW_CheckShowdown(flow);
            return r;
        }
        return r;
    }
    return 0;
}










int BTL_SERVER_FLOW_ProcHeldItemActivate(BtlServerFlow *flow, u8 *a)
{
    int t = BTL_POKEPARAM_GetItem((struct QI *)a);
    int result = 0;
    u32 s;
    u32 v;
    u16 pos;
    if (func_0689D588(flow->posPoke, BTL_POKEPARAM_GetPokeId(a))) {
        s = func_021CC8D8(&flow->lock, 0x1cea);
        if (BTL_SERVER_FLOW_RunItemActivateCheckEvent(flow, a, (u16)t) == 0) result = 1;
        if (result) {
            pos = BTL_SERVER_CMD_Reserve(flow->cmdQueue, 0x42);
            v = func_021CC918((Bf_td *)&flow->lock, (u16)t, 0x1cf4);
            BTL_SERVER_FLOW_DispatchPostMoveEvent(flow, a);
            if (func_021C88E4(flow) != 2) result = 0;
            func_021CC95C(&flow->lock, v, 0x1cf9);
            if (result) {
                BTL_SERVER_CMD_FillReserved(flow->cmdQueue, pos, 0x42, BTL_POKEPARAM_GetPokeId(a));
                if (func_021D805C((void *)((u16)t), 0x10)) BTL_SERVER_FLOW_SetHeldItem(flow, a, 0, 1);
            }
        }
        func_021CC95C(&flow->lock, s, 0x1d06);
    }
    return result;
}













int BTL_SERVER_FLOW_RunItemActivateCheckEvent(BtlServerFlow *flow, u8 *a, u16 c)
{
    int r;
    BTL_EVENT_PushVarFrame(7449);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x2d, c);
    BTL_EVENT_SetVarOnce(0x41, 0);
    func_021D70F0(flow, 0x90);
    r = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(7455);
    return r;
}














void BTL_SERVER_FLOW_SetHeldItem(BtlServerFlow *flow, u8 *a, u16 b, u32 c)
{
    u32 s;
    u16 t;
    int name;
    name = BTL_POKEPARAM_GetPokeId(a);
    t = (u16)(int)BTL_POKEPARAM_GetItem((struct QI *)a);
    s = func_021CC8D8(&flow->lock, 7469);
    func_021C7AD0(flow, a, b);
    func_021CC95C(&flow->lock, s, 7471);
    if (b == 0)
        BTL_SERVER_FLOW_SetContFlag(flow, a, 15);
    BTL_HANDLER_ITEM_RemoveUnforcedFactors(a);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x1E, name, b);
    BTL_POKEPARAM_SetItem((struct QI *)a, b);
    if (b != 0)
        BTL_HANDLER_ITEM_AddHeldItemFactor(a);
    s = func_021CC8D8(&flow->lock, 7485);
    func_021C7B0C(flow, a);
    func_021CC95C(&flow->lock, s, 7487);
    if (c != 0) {
        BTL_POKEPARAM_ConsumeHeldItem((struct QK *)a, t);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x17, name, t);
        BTL_SERVER_FLOW_SetTurnFlag(flow, a, 8);
    }
}













/*
 * extent: two zero alignment bytes follow the return at 0x021C232A.
 * interface: BTL_SERVER_FLOW_KillPoke reads r0/r1/r2 and forwards r2 unchanged;
 * BTL_SERVER_FLOW_ProcFaintedPoke has two arguments in its existing DIFF note.
 */
int BTL_SERVER_FLOW_ProcPokeHpChangeFinish(BtlServerFlow *flow, u8 *a)
{
    BTL_SERVER_FLOW_KillPoke(flow, a, 0);
    return BTL_SERVER_FLOW_ProcFaintedPoke(flow, a);
}












void BTL_SERVER_FLOW_ProcMoveAddedSick(BtlServerFlow *flow, const u16 *a, u8 *b, u8 *c)
{
    union Slot loc;
    u32 r;
    r = BTL_SERVER_FLOW_RollMoveAddedSick(flow, *a, b, c, &loc);
    if (r != 0 && BTL_POKEPARAM_IsFainted(c) == 0)
        BTL_SERVER_FLOW_ProcMoveSickOnTarget(flow, b, c, *a, r, loc, 0);
}










static inline int chance(u32 n)
{
    return BTL_CALC_Random(100) < n;
}










u32 BTL_SERVER_FLOW_RollMoveAddedSick(BtlServerFlow *flow, u16 id, u8 *a, u8 *b, union Slot *dest)
{
    u32 s;
    W_021C312C w;
    union Slot out;
    u8 rate;
    u32 result;
    u8 changedRate;
    u8 veto;
    s = sub_0201BD28(id, 11);
    w = WAZA_TOOL_GetSickCont(id);
    rate = sub_0201BD28(id, 12);
    BTL_CALC_MakeSickContFromSpec(w, (u32)a, &out);
    BTL_EVENT_PushVarFrame(0x1d7c);
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, id);
    BTL_EVENT_SetVar(0x1d, s);
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_SetVarOnce(0x1e, out.raw);
    BTL_EVENT_SetVar(0x26, rate);
    func_021D70F0(flow, 0x64);
    result = BTL_EVENT_GetVar(0x1d);
    rate = BTL_EVENT_GetVar(0x26);
    veto = BTL_EVENT_GetVar(0x41);
    if (result == 0xffff) result = 0;
    out.raw = BTL_EVENT_GetVar(0x1e);
    BTL_EVENT_PopVarFrame(0x1d8f);
    if (!veto && result) {
        if (chance(rate)) {
            *dest = out;
            return result;
        }
        if (func_021B911C(flow->mainModule, 0)) {
            *dest = out;
            return result;
        }
    }
    return 0;
}









void BTL_SERVER_FLOW_ProcMoveSickAllTargets(BtlServerFlow *flow, u16 id, u8 *a, void *c)
{
    u32 s;
    W_021C312C w;
    union Slot out;
    u8 *t;
    int got;
    s = sub_0201BD28(id, 11);
    w = WAZA_TOOL_GetSickCont(id);
    got = 0;
    if (func_0689CD38(c)) {
        func_0689CC84(c);
        for (t = func_0689CC8C(c); t; t = func_0689CC8C(c)) {
            BTL_CALC_MakeSickContFromSpec(w, (u32)a, &out);
            if (BTL_SERVER_FLOW_ProcMoveSickOnTarget(flow, a, t, id, s, out, 1)) {
                BF_021C1184 *flag = (BF_021C1184 * )flow->curTurnState;
                if (!flag->f) flag->f = 1;
                got = 1;
            }
        }
        if (!got && !((State_td *)flow)->f) BTL_SERVER_FLOW_PushMsgStdFailed(flow, a, id);
    } else {
        BTL_SERVER_FLOW_PushMsgStdFailed(flow, a, id);
    }
}












int BTL_SERVER_FLOW_ProcMoveSickOnTarget(BtlServerFlow *flow, u8 *a, u8 *b, u32 unused, u32 s0, union Slot s1, u32 s2)
{
    int t;
    func_021C8810(flow->msgParam);
    if (s0 == 0xFFFF) {
        s0 = BTL_SERVER_FLOW_QueryMoveSickIdEvent(flow, a, b, (u32)flow->msgParam);
        if (s0 == 0 || s0 == 0xFFFF)
            return 0;
    } else {
        BTL_SERVER_FLOW_RunMoveSickSelectedEvent(flow, s0, a, b, (u32)flow->msgParam);
    }
    BTL_SERVER_FLOW_RunMoveSickContEvent(flow, a, b, s0, &s1);
    t = func_021C8828(flow->msgParam) ? 0 : 1;
    if (BTL_SERVER_FLOW_ApplyMoveSick(flow, b, a, s0, s1, s2, t) != 0) {
        if (t == 0) {
            func_021C99A0(flow, (const struct Msg *)flow->msgParam);
            func_021C8810(flow->msgParam);
        }
        return 1;
    }
    return 0;
}













int BTL_SERVER_FLOW_QueryMoveSickIdEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c)
{
    int r;
    BTL_EVENT_PushVarFrame(7681);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x3f, c);
    BTL_EVENT_SetVar(0x1d, 0);
    func_021D70F0(flow, 0x60);
    r = BTL_EVENT_GetVar(0x1d);
    BTL_EVENT_PopVarFrame(7688);
    return r;
}













void BTL_SERVER_FLOW_RunMoveSickSelectedEvent(BtlServerFlow *flow, u32 a, u8 *b, u8 *c, u32 d)
{
    BTL_EVENT_PushVarFrame(7704);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(c));
    BTL_EVENT_SetVarReadOnly(0x3f, d);
    BTL_EVENT_SetVarReadOnly(0x1d, a);
    func_021D70F0(flow, 0x61);
    BTL_EVENT_PopVarFrame(7710);
}













void BTL_SERVER_FLOW_RunMoveSickContEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c, union Slot *d)
{
    BTL_EVENT_PushVarFrame(7726);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x1d, c);
    BTL_EVENT_SetVar(0x1e, d->raw);
    func_021D70F0(flow, 0x62);
    d->raw = BTL_EVENT_GetVar(0x1e);
    BTL_EVENT_PopVarFrame(7726 + 7);
}











int BTL_SERVER_FLOW_ApplyMoveSick(BtlServerFlow *flow, u8 *x, u8 *y, int z, union Slot a, u32 b, u32 c)
{
    if (BTL_SERVER_FLOW_TryApplySick(flow, x, y, z, a, 0, b) == 0) {
        BTL_SERVER_FLOW_ProcSickAdded(flow, x, y, z, a, c, 0, 0);
        return 1;
    }
    return 0;
}










/*
 * The fifth parameter is a one-word struct passed by value and handed on
 * to BTL_SERVER_FLOW_CheckSickImmunity by value (`add r3, sp, #0x20; ldr r3, [r3]`, the
 * push-r0-r3 struct idiom); a plain u32 folds to `ldr r3, [sp, #0x20]`.
 * The caller BTL_SERVER_FLOW_ApplyMoveSick passes it as a plain u32 word. Declaring s
 * before t puts s in [sp, #8].
 */
int BTL_SERVER_FLOW_TryApplySick(BtlServerFlow *flow, u8 *x, u8 *y, int z, union Slot a, u8 b, u32 c)
{
    int r;
    u32 s;
    int t;
    r = BTL_SERVER_FLOW_CheckSickImmunity(flow, (struct Unk021D62A8 *)x, z, a, b);
    if (r != 0) {
        if (c != 0)
            BTL_SERVER_FLOW_PushSickFailedMessage(flow, x, r, z);
        return 1;
    }
    s = func_021CC8D8(&flow->lock, 7779);
    t = BTL_SERVER_FLOW_QuerySickBlockedEvent(flow, y, x, z);
    if (t != 0 && c != 0) {
        BTL_SERVER_FLOW_RunSickAppliedEvent(flow, x, y, z);
        flow->stateFlags.raw |= 0x10;
    }
    func_021CC95C(&flow->lock, s, 7792);
    return t;
}









int BTL_SERVER_FLOW_CheckSickImmunity(BtlServerFlow *flow, struct Unk021D62A8 *b, int c, union Slot d, u8 e)
{
    u16 t;
    if (BTL_POKEPARAM_HasSick(b, c) && e != 2) return 1;
    if (c < 6 && BTL_POKEPARAM_GetMajorStatusIndex(b) && e == 0) return 3;
    if (BTL_SERVER_FLOW_GetEffectiveWeather(flow) == 1 && c == 3) return 3;
    if (c == 5) {
        t = BTL_POKEPARAM_GetTypePair(b);
        if (BTLV_CORE_HasByte(t, 8) || BTLV_CORE_HasByte(t, 3)) return 2;
    }
    if (c == 4 && BTLV_CORE_HasByte(BTL_POKEPARAM_GetTypePair(b), 9)) return 2;
    if (c == 3 && BTLV_CORE_HasByte(BTL_POKEPARAM_GetTypePair(b), 14)) return 2;
    if (c == 18 && BTLV_CORE_HasByte(BTL_POKEPARAM_GetTypePair(b), 11)) return 2;
    if (c == 14 && BTL_POKEPARAM_GetMajorStatusIndex(b)) return 3;
    if (c == 16 && func_021D59B4((u8 *)b, 16) == 121) return 3;
    return 0;
}









void BTL_SERVER_FLOW_ProcSickAdded(BtlServerFlow *flow, u8 *a, u8 *b, int kind, union Slot value, int f, int g, const void *m)
{
    u32 lock;
    BTL_SERVER_FLOW_SetSickCont(flow, a, kind, value);
    switch (kind) {
    case 5: BTL_SERVER_FLOW_PushPokeEffectAnim(flow, a, 599); break;
    case 4: BTL_SERVER_FLOW_PushPokeEffectAnim(flow, a, 600); break;
    case 1: BTL_SERVER_FLOW_PushPokeEffectAnim(flow, a, 602); break;
    case 3: BTL_SERVER_FLOW_PushPokeEffectAnim(flow, a, 601); break;
    case 2: BTL_SERVER_FLOW_PushPokeEffectAnim(flow, a, 598); break;
    case 6: BTL_SERVER_FLOW_PushPokeEffectAnim(flow, a, 603); break;
    case 7: BTL_SERVER_FLOW_PushPokeEffectAnim(flow, a, 604); break;
    case 0: break;
    }
    if (f) {
        func_0689C364(kind, value, a, (struct Msg *)flow->msgParam);
        func_021C99A0(flow, (struct Msg *)flow->msgParam);
        func_021C8810(flow->msgParam);
    } else if (m) func_021C99A0(flow, m);
    if (kind == 3 && BTL_POKEPARAM_GetSpecies((struct QF *)a) == 492 && func_021D59B4(a, 19) == 1) {
        BTL_CALC_RemoveAbilityHandlers(a);
        BTL_POKEPARAM_ChangeForm(a, 0);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 79, BTL_POKEPARAM_GetPokeId(a), 0);
        BTL_CALC_AddAbilityHandlers(a);
        BTL_SERVER_FLOW_PushMsgSetPoke(flow, a, 222);
    }
    lock = func_021CC8D8(&flow->lock, 7936);
    if (BTL_CALC_HasDefaultSickCont(kind)) {
        BTL_SERVER_FLOW_RunSickAddedContEvent(flow, a, b, kind, value.raw);
    } else if (kind == 16) {
        BTL_SERVER_FLOW_RunSickEndEvent(flow, (u8 *)((int)a));
        if (func_021D59B4(a, 17) == 127) BTL_SERVER_FLOW_RecheckOpponentAbilityEffects(flow, a);
    } else BTL_SERVER_FLOW_RunSickAddedEvent(flow, a, b, kind);
    func_021CC95C(&flow->lock, lock, 7951);
    if (!g) BTL_SERVER_FLOW_ProcDamagedItemReaction(flow, a, 3);
}










int BTL_SERVER_FLOW_GetEffectiveWeather(BtlServerFlow *flow)
{
    int r;
    int t;
    BTL_EVENT_PushVarFrame(7971);
    BTL_EVENT_SetVarOnce(0x41, 0);
    r = 0;
    func_021D70F0(flow, 0x7a);
    t = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(7975);
    if (t == 0)
        r = BTL_FIELD_GetCountdownValue();
    return r;
}










int BTL_SERVER_FLOW_QueryPokeMultiplierEvent(u8 *p, u8 *a)
{
    int r;
    BTL_EVENT_PushVarFrame(7997);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarRanged(0x35, 2 << 11, 410, 2 << 16);
    func_021D70F0(p, 0x7B);
    r = BTL_EVENT_GetVar(0x35);
    BTL_EVENT_PopVarFrame(8002);
    return r;
}










int BTL_SERVER_FLOW_QuerySickBlockedEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c)
{
    int r;
    BTL_EVENT_PushVarFrame(8021);
    BTL_EVENT_SetVarReadOnly(3, a ? BTL_POKEPARAM_GetPokeId(a) : 0x1F);
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x1D, c);
    BTL_EVENT_SetVarOnce(0x41, 0);
    func_021D70F0(flow, 0x65);
    r = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(8028);
    return r;
}










void BTL_SERVER_FLOW_RunSickAppliedEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c)
{
    BTL_EVENT_PushVarFrame(8042);
    BTL_EVENT_SetVar(4, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVar(3, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVar(0x1D, c);
    func_021D70F0(flow, 0x67);
    BTL_EVENT_PopVarFrame(8047);
}










void BTL_SERVER_FLOW_RunSickAddedContEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c, u32 d)
{
    BTL_EVENT_PushVarFrame(8062);
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(3, (u8)(b ? BTL_POKEPARAM_GetPokeId(b) : 0x1F));
    BTL_EVENT_SetVarReadOnly(0x1D, c);
    BTL_EVENT_SetVarReadOnly(0x1E, d);
    func_021D70F0(flow, 0x68);
    BTL_EVENT_PopVarFrame(8071);
}










void BTL_SERVER_FLOW_RunSickAddedEvent(BtlServerFlow *flow, u8 *a, u8 *b, u32 c)
{
    BTL_EVENT_PushVarFrame(8085);
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(3, (u8)(b ? BTL_POKEPARAM_GetPokeId(b) : 0x1F));
    BTL_EVENT_SetVarReadOnly(0x1D, c);
    func_021D70F0(flow, 0x69);
    BTL_EVENT_PopVarFrame(8093);
}









void BTL_SERVER_FLOW_RunSickEndEvent(BtlServerFlow *flow, u8 *a)
{
    BTL_EVENT_PushVarFrame(8105);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    func_021D70E4(flow, 0x6a);
    BTL_EVENT_PopVarFrame(8108);
}









/*
 * extent: two bytes of zero alignment padding at 0x021C2D0E.
 */
void BTL_SERVER_FLOW_ProcMoveAddedRankEffect(BtlServerFlow *flow, u16 *q, u8 *a, u8 *b)
{
    if (BTL_POKEPARAM_IsFainted(b) == 0) {
        if (BTL_SERVER_FLOW_RollMoveAddedEffectChance(flow, q, a, b) != 0)
            BTL_SERVER_FLOW_ProcMoveRankEffects(flow, q, a, b, 0);
    }
}









int BTL_SERVER_FLOW_RollMoveAddedEffectChance(BtlServerFlow *flow, u16 *q, u8 *b, u8 *c)
{
    u8 s, x, y;
    u32 t;
    s = sub_0201BD28(*q, 0x12);
    BTL_EVENT_PushVarFrame(8142);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(c));
    BTL_EVENT_SetVarReadOnly(0x12, *q);
    t = 0;
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_SetVar(0x26, s);
    func_021D70F0(flow, 0x51);
    x = BTL_EVENT_GetVar(0x41);
    y = BTL_EVENT_GetVar(0x26);
    BTL_EVENT_PopVarFrame(8152);
    if (x == 0) {
        if (BTL_CALC_Random(100) < y)
            t = 1;
        if (t)
            return 1;
        if (func_021B911C((void *)(flow->mainModule), 0) != 0)
            return 1;
    }
    return 0;
}








void BTL_SERVER_FLOW_ProcMoveRankEffectAllTargets(BtlServerFlow *flow, u32 a, u32 b, void *c)
{
    u8 *t;
    func_0689CC84(c);
    for (t = func_0689CC8C(c); t != 0; t = func_0689CC8C(c)) {
        if (BTL_SERVER_FLOW_ProcMoveRankEffects(flow, (const u16 *)a, (u8 *)b, t, 1) != 0) {
            BF_021C2AB0 *f = (BF_021C2AB0 * )flow->curTurnState;
            if (!f->f)
                f->f = 1;
        }
    }
}






























u32 BTL_SERVER_FLOW_NextSerialNumber(BtlServerFlow *flow)
{
    if (++flow->serialNumber == 0)
        flow->serialNumber = 1;
    return flow->serialNumber;
}































/*
 * lever: enum Kind keeps the output guard in r0 and reloads it into r3 at the call.
 */
int BTL_SERVER_FLOW_ProcMoveRankEffects(BtlServerFlow *flow, const u16 *q, u8 *a, u8 *b, int k)
{
    u8 id;
    int result;
    u32 count, i;
    u32 serial;
    enum Kind kind;
    s32 value;
    int ok;
    u8 j;
    u32 lock;
    result = 0;
    id = BTL_POKEPARAM_GetPokeId(a);
    serial = BTL_SERVER_FLOW_NextSerialNumber(flow);
    count = WAZA_TOOL_GetRankEffectCount(*q);
    for (i = 0; i < count; i++) {
        ok = 0;
        BTL_SERVER_FLOW_QueryMoveRankEffectEvent(flow, *q, i, a, b, (s32 *)&kind, &value);
        if (kind != 0) {
            if (kind != 10) {
                ok = BTL_SERVER_FLOW_TryChangeStatStage(flow, id, b, kind, value, id, ok, serial, k, 1);
            } else {
                for (j = 1; j < 6; j++) {
                    if (BTL_SERVER_FLOW_TryChangeStatStage(flow, id, b, j, value, id, 0, serial, k, 1)) ok = 1;
                }
            }
            if (ok) {
                lock = func_021CC8D8((struct Lock *)&flow->lock, 8247);
                func_021C78A8(flow, b, *q, kind, value);
                func_021CC95C(&flow->lock, lock, 8249);
                result = 1;
            }
        }
    }
    return result;
}
































void BTL_SERVER_FLOW_QueryMoveRankEffectEvent(BtlServerFlow *flow, u16 x, u32 y, u8 *c, u8 *s0, s32 *s1, s32 *s2)
{
    u32 m;
    *s1 = WAZA_TOOL_GetRankEffect(x, y, s2);
    BTL_EVENT_PushVarFrame(8275);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(c));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(s0));
    BTL_EVENT_SetVar(0x1F, *s1);
    BTL_EVENT_SetVar(0x20, *s2);
    BTL_EVENT_SetVar(0x35, 1);
    func_021D70F0(flow, 0x59);
    *s1 = BTL_EVENT_GetVar(0x1F);
    *s2 = BTL_EVENT_GetVar(0x20);
    m = (u8)BTL_EVENT_GetVar(0x35);
    if (m > 1)
        *s2 = *s2 * m;
    BTL_EVENT_PopVarFrame(8290);
    if (*s1 == 8)
        *s1 = 0;
}





























/*
 * lever: reassigning value to the transformed result keeps it in its incoming register.
 */
int BTL_SERVER_FLOW_TryChangeStatStage(BtlServerFlow *flow, u8 b, u8 *a, enum Kind kind, int value, u8 f, u16 g, u32 h, int i, u32 j)
{
    int result;
    u32 lock;
    value = BTL_SERVER_FLOW_QueryStatStageChangeEvent(flow, a, kind, f, g, value);
    if (!func_021D5D14((s8 *)a, kind, value)) {
        if (i) {
            BTL_SERVER_FLOW_PushSignedChangeMessage(flow, a, kind, value);
            flow->stateFlags.raw |= 0x10;
        }
        return 0;
    }
    if (BTL_POKEPARAM_HasSubstitute(a)) {
        u8 id;
        id = BTL_POKEPARAM_GetPokeId(a);
        if (b != id) {
            if (i) BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0xd2, id, 0xffff0000);
            return 0;
        }
    }
    result = 1;
    if (func_021C77B0(flow, a, kind, b, value, h)) {
        BTL_SERVER_FLOW_ChangeStatStage(flow, a, kind, value, g, j);
        lock = func_021CC8D8(&flow->lock, 8349);
        func_021C785C(flow, b, a, kind, value);
        func_021CC95C(&flow->lock, lock, 8351);
    } else {
        if (i) {
            lock = func_021CC8D8(&flow->lock, 8358);
            func_021C7820(flow, a, h);
            func_021CC95C(&flow->lock, lock, 8360);
        }
        result = 0;
    }
    return result;
}






























/*
 * Note (final push 2026-10-05 G4L8): the script result is written back into the
 * stack parameter d (the caller BTL_SERVER_FLOW_TryChangeStatStage does value = BTL_SERVER_FLOW_QueryStatStageChangeEvent(..., value)).
 * Assigning to a stack-passed parameter, instead of a fresh local r, keeps the end
 * line as its own pool word (no ldr + adds #7 fold). Both --lang c99 and c EXACT.
 */
int BTL_SERVER_FLOW_QueryStatStageChangeEvent(BtlServerFlow *flow, u8 *a, enum Kind b, u8 c, u16 e, int d)
{
    BTL_EVENT_PushVarFrame(8385);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(3, c);
    BTL_EVENT_SetVarReadOnly(0x1F, b);
    BTL_EVENT_SetVarOnce(0x20, d);
    func_021D70F0(flow, 0x5A);
    d = BTL_EVENT_GetVar(0x20);
    BTL_EVENT_PopVarFrame(8392);
    return d;
}






























/*
 * WAZA_TOOL_GetSickCont is declared here as returning a one-halfword struct (the
 * store of r0 with no sign extension and the dead-looking second strh are
 * the struct-return temp plus its copy); its own file says s16.
 * BTL_CALC_MakeSickContFromSpec's first argument and BTL_SERVER_FLOW_ProcMoveSickOnTarget's sixth are structs
 * passed by value.
 */
void BTL_SERVER_FLOW_ProcMoveRankAndSickAllTargets(BtlServerFlow *flow, const u16 *q, u32 r, void *c)
{
    u8 *t;
    u32 s;
    union Slot out;
    W_021C312C v;
    s = sub_0201BD28(*q, 0xB);
    v = WAZA_TOOL_GetSickCont(*q);
    BTL_CALC_MakeSickContFromSpec(v, r, &out);
    func_0689CC84(c);
    for (t = func_0689CC8C(c); t != 0; t = func_0689CC8C(c)) {
        if (BTL_SERVER_FLOW_ProcMoveRankEffects(flow, (const u16 *)((u32)q), (u8 *)r, t, 1) != 0) {
            BF *f = (BF * )flow->curTurnState;
            if (!f->f)
                f->f = 1;
        }
        if (BTL_SERVER_FLOW_ProcMoveSickOnTarget(flow, (u8 *)r, t, *q, s, out, 1) != 0) {
            BF *f = (BF * )flow->curTurnState;
            if (!f->f)
                f->f = 1;
        }
    }
}




























void BTL_SERVER_FLOW_ProcMoveRecoverHpAllTargets(BtlServerFlow *flow, u32 q, u32 b, void *c)
{
    u8 *t;
    func_0689CC84(c);
    for (t = func_0689CC8C(c); t != 0; t = func_0689CC8C(c)) {
        u8 m = BTL_POKEPARAM_GetPokeId(t);
        if (BTL_SERVER_FLOW_IsHpRecoverUnneeded(flow, (void *)t) == 0) {
            if (BTL_SERVER_FLOW_TryRecoverHp(flow, t, (u16)func_021C79E0(flow, q, t), 1) != 0) {
                BF *f = (BF * )flow->curTurnState;
                if (!f->f)
                    f->f = 1;
                BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 387, m, 0xffff0000);
            }
        } else if (BTL_POKEPARAM_IsHpFull(t) != 0) {
            BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 893, m, 0xffff0000);
        }
    }
}




























int BTL_SERVER_FLOW_TryRecoverHp(BtlServerFlow *flow, u8 *q, int a, int b)
{
    if (BTL_SERVER_FLOW_CheckHealBlocked(flow, q, b) == 0) {
        BTL_SERVER_FLOW_ApplyHpRecover(flow, q, a);
        return 1;
    }
    return 0;
}




























int BTL_SERVER_FLOW_IsHpRecoverUnneeded(BtlServerFlow *flow, void *q)
{
    if (BTL_POKEPARAM_IsAbleToBattle(q) == 0) return 1;
    if (BTL_POKEPARAM_IsHpFull(q) != 0) return 1;
    return 0;
}





























int BTL_SERVER_FLOW_CheckHealBlocked(BtlServerFlow *flow, u8 *q, int r)
{
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)q, 15) != 0) {
        if (r != 0) {
            BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 887, BTL_POKEPARAM_GetPokeId(q), 0xffff0000);
            flow->stateFlags.raw |= 0x20;
        }
        return 1;
    }
    return 0;
}





























void BTL_SERVER_FLOW_ApplyHpRecover(BtlServerFlow *flow, u8 *b, int c)
{
    int v = func_0689D5C8(flow->posPoke, BTL_POKEPARAM_GetPokeId(b));
    if (v != 6)
        BTL_SERVER_CMD_Push((void *)((int)flow->cmdQueue), 0x4d, v, 0x263);
    BTL_SERVER_FLOW_ChangeHp(flow, (u8 *)b, c, 1);
}


























void BTL_SERVER_FLOW_ProcMoveOhko(BtlServerFlow *flow, u16 *q, u8 *a, u8 *out)
{
    u8 speed;
    u8 *b;
    u8 id;
    u32 item;
    u32 lock;
    u8 tag;
    int category;
    int event1, event2;
    u32 i;
    u16 half;
    struct Flags_021C2E4C *flags;
    i = 0;
    speed = (u8)func_021D59B4(a, 15);
    for (;;) {
        int kind;
        b = (u8 *)func_0689CC70(out, i++);
        if (b == 0) break;
        if (BTL_POKEPARAM_IsFainted(b)) continue;
        id = BTL_POKEPARAM_GetPokeId(b);
        if (!func_021BF324(flow, a, b)) {
            if (BTL_SERVER_FLOW_QuerySemiInvulnerableHit(flow, a, b, *q)) {
                BTL_SERVER_FLOW_PushMoveBlockedMessage(flow, b, *q);
                continue;
            }
        }
        if (BTL_SERVER_FLOW_CheckAllyMoveAutoHit(flow, a, b, (void *)(u32)*q)) {
            BTL_SERVER_FLOW_PushMoveBlockedMessage(flow, b, *q);
            continue;
        }
        if (speed < (u8)func_021D59B4(b, 15)) {
            BTL_SERVER_FLOW_PushActionFailedMessage(flow, b);
            continue;
        }
        item = func_021CC8B8((u32 *)flow->targetParam, id);
        if (item == 0) {
            BTL_SERVER_FLOW_PushActionFailedMessage(flow, b);
            continue;
        }
        lock = func_021CC8D8(&flow->lock, 0x216b);
        if (BTL_SERVER_FLOW_CheckOneHitKoHit(flow, a, b, *q)) {
            tag = func_0689D5C8(flow->posPoke, BTL_POKEPARAM_GetPokeId(a));
            half = func_021D59B4(b, 13);
            category = BTL_CALC_SummarizeTypeAffinity(item);
            event1 = 0;
            event2 = 0;
            flags = (struct Flags_021C2E4C * )flow->curTurnState;
            if (!flags->a) flags->a = 1;
            if (BTL_POKEPARAM_HasSubstitute(b)) {
                half = BTL_SERVER_FLOW_ProcOhkoSubstituteBroken(flow, b, q, category);
                func_0689CBB8(out, b, half, 1);
                event1 = 1;
            } else {
                kind = BTL_SERVER_FLOW_CheckEndureEvent(flow, a, b, 1, &half);
                if (kind == 0) {
                    BTL_SERVER_FLOW_ProcOhkoFaint(flow, b, q, category);
                } else {
                    BTL_SERVER_FLOW_ProcOhkoEndured(flow, b, q, category, kind, half);
                    func_0689CBB8(out, b, half, 0);
                    event2 = 1;
                }
            }
            if (!event1) BTL_SERVER_FLOW_RecordDamageHit(flow, tag, a, b, (u8 *)q, half);
            BTL_SERVER_FLOW_ProcDamageEndEvents(flow, a, b, (u8 *)q, item, half, 0, event1);
            if (event2 || event1) BTL_SERVER_FLOW_RunMoveDamageEndEvent(flow, a, (u32)out, (u8 *)q, 0);
            BTL_SERVER_FLOW_ProcFaintedPoke(flow, b);
        } else if (!func_021C88E4(flow)) {
            BTL_SERVER_FLOW_PushMoveBlockedMessage(flow, b, *q);
        }
        func_021CC95C(&flow->lock, lock, 0x219c);
    }
}


























void BTL_SERVER_FLOW_ProcOhkoFaint(BtlServerFlow *flow, u8 *a, u16 *b, int c)
{
    int i = BTL_POKEPARAM_GetPokeId(a);
    BTL_POKEPARAM_ZeroHp(a);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 3, i);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x32, i, (u8)c, *b);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x34, i);
}


























/*
 * The final 00 00 at 0x021C371E is alignment padding before 0x021C3720.
 * A separate call-result local keeps the halfword load before that call.
 */
void BTL_SERVER_FLOW_ProcOhkoEndured(BtlServerFlow *flow, u8 *q, u16 *r, int a, int b, u16 c)
{
    int n;
    int v;
    BTL_SERVER_FLOW_SubtractHp(flow, q, c);
    n = *r;
    v = BTL_POKEPARAM_GetPokeId(q);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x32, v, (u8)a, n);
    BTL_SERVER_FLOW_ProcDamageAftereffect(flow, q, b);
}



























u16 BTL_SERVER_FLOW_ProcOhkoSubstituteBroken(BtlServerFlow *flow, u8 *a, u16 *b, int c)
{
    int i = BTL_POKEPARAM_GetPokeId(a);
    u16 v = BTL_POKEPARAM_GetSubstituteHp(a);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x34, i);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x32, i, (u8)c, *b);
    BTL_SERVER_FLOW_RemoveSubstitute(flow, a);
    return v;
}



























void BTL_SERVER_FLOW_ProcMoveForceSwitchAllTargets(BtlServerFlow *flow, u16 a1, int b, void *it)
{
    int v = 0;
    u8 *r;
    func_0689CC84(it);
    r = func_0689CC8C(it);
    while (r) {
        if (BTL_SERVER_FLOW_TryForceSwitchTarget(flow, (u8 *)b, r, 0, &v, 0, 0, 0)) {
            Q_p10 *q = (Q_p10 * )flow->curTurnState;
            if (!q->f)
                q->f = 1;
        } else if (v == 0) {
            BTL_SERVER_FLOW_PushMsgStdFailed(flow, (u8 *)b, a1);
        }
        r = func_0689CC8C(it);
    }
}
























static inline u8 rule(u8 n)
{
    if (n != 0) {
        n--;
        if (n < 24) return n;
    }
    return 31;
}
























int BTL_SERVER_FLOW_TryForceSwitchTarget(BtlServerFlow *flow, u8 *a, u8 *b, int force, int *out, u16 move, int ignore, const struct Msg *msg)
{
    enum Mode mode;
    u8 position;
    u32 lock;
    u8 blocked;
    struct Pair pair;
    *out = 0;
    if (force) mode = M1;
    else mode = BTL_SERVER_FLOW_IsForceSwitchByParty(flow);
    if (mode == M2) return 0;
    position = func_021B8D8C(flow->mainModule, flow->pokeCon, BTL_POKEPARAM_GetPokeId(b));
    if (position == 6) return 0;
    if (BTL_POKEPARAM_IsFainted(b)) return 0;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)b, 33)) return 0;
    if (rule(func_021D69AC(b, 4)) != 31) return 0;
    lock = func_021CC8D8(&flow->lock, 8732);
    blocked = BTL_SERVER_FLOW_QueryForceSwitchBlockedEvent(flow, (int)a, b);
    if (blocked && func_021C88E4(flow)) *out = 1;
    func_021CC95C(&flow->lock, lock, 8740);
    if (blocked) return 0;
    func_021B8E28(flow->mainModule, position, &pair.id, &pair.count);
    if (mode == M1) {
        u8 id;
        mode = BTL_SERVER_FLOW_PickRandomBenchPoke(flow, BTL_SERVER_GetClientChecked(flow->server, pair.id));
        if (mode >= 0) {
            id = BTL_POKEPARAM_GetPokeId((u8 *)func_021B990C((char *)((u32)flow->pokeCon), pair.id, (u8)mode));
            BTL_SERVER_FLOW_ProcMemberOutCore(flow, b, move);
            if (msg) func_021C99A0(flow, msg);
            BTL_SERVER_FLOW_ProcMemberIn(flow, pair.id, pair.count, (u8)mode, 0);
            BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 845, id, 0xffff0000);
            BTL_SERVER_FLOW_ProcAfterMemberIn(flow);
        } else return 0;
    } else {
        int slot;
        slot = func_021B8DDC(BTL_POKEPARAM_GetPokeId(a));
        if (!ignore) {
            u8 speed;
            speed = (u8)func_021D59B4(a, 15);
            if ((u8)func_021D59B4(b, 15) > speed) return 0;
        }
        BTL_CLIENT_SET_Add((struct B *)flow->slotTable, slot);
        BTL_SERVER_FLOW_ProcMemberOutCore(flow, b, move);
        flow->flowResult = 5;
    }
    return 1;
}
























BOOL BTL_SERVER_FLOW_IsForceSwitchByParty(BtlServerFlow *flow)
{
    u32 a;
    void *b;
    a = BTL_MAIN_GetRule(flow->mainModule);
    b = BTL_MAIN_GetCompetitor(flow->mainModule);
    if (a == 0) {
        if (b == 0) {
            return FALSE;
        } else {
            return TRUE;
        }
    }
    return TRUE;
}

























int BTL_SERVER_FLOW_PickRandomBenchPoke(BtlServerFlow *flow, u8 *b)
{
    u8 buf[8];
    u32 n;
    u32 i;
    int c;

    n = func_021B9B94(((struct Obj09971 *)b)->f4);
    i = func_021B99C0(flow->mainModule, b[0xb]);
    c = 0;
    for (; i < n; i++) {
        if (BTL_POKEPARAM_IsAbleToBattle(func_021B9C00(((struct Obj09971 *)b)->f4, (u8)i))) {
            buf[c] = i;
            c++;
        }
    }
    if (c != 0) {
        return buf[BTL_CALC_Random(c)];
    }
    return -1;
}

























int BTL_SERVER_FLOW_QueryForceSwitchBlockedEvent(BtlServerFlow *flow, int unused, u8 *a)
{
    int r;
    BTL_EVENT_PushVarFrame(8877);
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(a));
    func_021D70F0(flow, 0x8b);
    func_0689C7A4(flow, a);
    r = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(8883);
    return r;
}

























void BTL_SERVER_FLOW_ProcMoveWeather(BtlServerFlow *flow, u16 *a, u8 *b)
{
    u8 k = WAZA_TOOL_GetWeather(*a);
    if (k) {
        int x = BTL_SERVER_FLOW_QueryWeatherPokeEvent(flow, k, b);
        if (BTL_SERVER_FLOW_TryChangeWeather(flow, k, (u8)(x + 5))) {
            Q_p10 *q = (Q_p10 * )flow->curTurnState;
            if (!q->f)
                q->f = 1;
            return;
        }
        BTL_SERVER_FLOW_PushMsgStdFailed(flow, (u8 *)b, *a);
    } else {
        u32 s;
        int e;
        s = func_021CC8D8(&flow->lock, 0x22c8);
        BTL_SERVER_FLOW_DispatchPokeMoveEvent(flow, b, *a);
        e = (func_021C88E4(flow) == 2);
        func_021CC95C(&flow->lock, s, 0x22cc);
        if (e) {
            Q_p10 *q = (Q_p10 * )flow->curTurnState;
            if (!q->f)
                q->f = 1;
        } else {
            BTL_SERVER_FLOW_PushMsgStdFailed(flow, (u8 *)b, *a);
        }
    }
}
























int BTL_SERVER_FLOW_TryChangeWeather(BtlServerFlow *flow, int a, u8 b)
{
    if (BTL_SERVER_FLOW_CanChangeWeather(flow, a, b)) {
        BTL_SERVER_FLOW_ApplyWeatherChange(flow, a, b);
        return 1;
    }
    return 0;
}
























BOOL BTL_SERVER_FLOW_CanChangeWeather(BtlServerFlow *flow, u32 a, u32 b)
{
    if (a >= 5) return FALSE;
    if (a == BTL_FIELD_GetCountdownValue() && (b != 255 || BTL_FIELD_GetCountdownCount() == 255)) {
        return FALSE;
    }
    return TRUE;
}
























void BTL_SERVER_FLOW_ApplyWeatherChange(BtlServerFlow *flow, u32 a, u32 b)
{
    func_021EF8A4(a, b);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x3f, a, b);
    BTL_SERVER_FLOW_ProcWeatherChanged(flow, a);
}
























/*
 * interface: Lock scalar word return preserves the complete r0 payload,
 * as in matched caller 021C3810; restore consumes the same word.
 */
void BTL_SERVER_FLOW_ProcWeatherChanged(BtlServerFlow *flow, u32 a)
{
    u32 old;
    int line = 0x2303;
    old = func_021CC8D8(&flow->lock, line);
    func_021C7998(flow, a);
    func_021CC95C(&flow->lock, old, line + 2);
}

























u8 BTL_SERVER_FLOW_QueryWeatherPokeEvent(BtlServerFlow *flow, int k, u8 *a)
{
    u8 r;
    BTL_EVENT_PushVarFrame(8983);
    BTL_EVENT_SetVarReadOnly(0x39, k);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVar(0x24, 0);
    func_021D70F0(flow, 0x7c);
    r = BTL_EVENT_GetVar(0x24);
    BTL_EVENT_PopVarFrame(8989);
    return r;
}

























/*
 * The handed address 0x021C3C62 is the second label after `push {r0-r3}`
 * (0x021C3C60). The third parameter is a one-word struct passed by value
 * (its home slot is read through `add r7, sp, #0x20`).
 */
int BTL_SERVER_FLOW_TryRegisterFieldSlot(BtlServerFlow *flow, int a, union Slot c, int d)
{
    int r;
    if (BTL_FIELD_RegisterStaticSlot(a, c)) {
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x21, (u8)a, c.raw);
        return 1;
    }
    if (d) {
        r = BTLV_CORE_GetSlotPosition(c);
        if (r != 0x1f) {
            BTL_FIELD_SetStaticSlotValue(a, r);
            BTL_SERVER_CMD_Push(flow->cmdQueue, 0x22, (u8)a, r);
            return 1;
        }
    }
    return 0;
}
























void BTL_SERVER_FLOW_DispatchPokeMoveEvent(BtlServerFlow *flow, u8 *b, int c)
{
    int line = 0x2360;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVar(3, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVar(0x12, c);
    func_021D70F0(flow, 0x9e);
    BTL_EVENT_PopVarFrame(line + 4);
}























void BTL_SERVER_FLOW_ProcMoveSpecialEffect(BtlServerFlow *flow, u16 *b, u8 *a, u8 *c)
{
    int out;
    u32 s, r;
    Flag_td *f;
    if (func_0689CD50(c) != 0) return;
    switch (*b) {
    case 0x11d:
        BTL_SERVER_FLOW_ProcSkillSwap(flow, a, c);
        return;
    case 0xa4:
        if (BTL_SERVER_FLOW_ProcSubstituteMove(flow, a)) {
            f = (Flag_td * )flow->curTurnState;
            if (f->a == 0) {
                f->a = 1;
                f->b = 1;
            }
        }
        return;
    default:
        s = func_021CC8D8(&flow->lock, 9087);
        r = func_021C88E4(flow);
        if (BTL_SERVER_FLOW_DispatchMoveFailCheck(flow, b, a, c, &out)) {
            r = func_021C88E4(flow);
            if (r == 2) {
                f = (Flag_td * )flow->curTurnState;
                if (f->a == 0) f->a = 1;
            }
        }
        if (r <= 1 && out != 0 && ((ByteFlag *)&flow->stateFlags)->b == 0) {
            BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 0x47, 0xffff0000);
        }
        func_021CC95C(&flow->lock, s, 9113);
    }
}





















void BTL_SERVER_FLOW_ProcSkillSwap(BtlServerFlow *flow, u8 *a, u8 *c)
{
    u8 *b;
    u32 x, y, ai, bi;
    u32 s, t;
    int line;
    Flag_td *f;
    b = func_0689CC70(c, 0);
    x = func_021D59B4(a, 16);
    y = func_021D59B4(b, 16);
    if (x != y && !func_0689C954(x) && !func_0689C954(y)) {
        ai = BTL_POKEPARAM_GetPokeId(a);
        bi = BTL_POKEPARAM_GetPokeId(b);
        f = (Flag_td * )flow->curTurnState;
        if (f->a == 0) f->a = 1;
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x4a, ai, bi, (u16)y, (u16)x);
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x1fc, ai, 0xffff0000);
        line = 9140;
        s = func_021CC8D8(&flow->lock, line);
        func_021C7B3C(flow, ai, x, y);
        func_021C7B3C(flow, bi, y, x);
        func_021CC95C(&flow->lock, s, line + 3);
        BTL_POKEPARAM_SetAbility((struct QJ *)a, y);
        BTL_POKEPARAM_SetAbility((struct QJ *)b, x);
        BTL_CALC_SwapAbilityHandlers((int)a, (int)b);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x58, ai);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x58, bi);
        if (x != y) {
            t = func_021CC8D8(&flow->lock, line + 16);
            func_021C7B7C(flow, ai);
            func_021C7B7C(flow, bi);
            line += 19;
            func_021CC95C(&flow->lock, t, line);
        }
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 16) == 0) {
            if (x == 0x67) BTL_SERVER_FLOW_ProcDamagedItemReaction(flow, a, 0);
            if (x == 0x7f) BTL_SERVER_FLOW_RecheckOpponentAbilityEffects(flow, a);
        }
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)b, 16) == 0) {
            if (y == 0x67) BTL_SERVER_FLOW_ProcDamagedItemReaction(flow, b, 0);
            if (y == 0x7f) BTL_SERVER_FLOW_RecheckOpponentAbilityEffects(flow, b);
        }
    } else {
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 0x47, 0xffff0000);
    }
}






















void BTL_SERVER_FLOW_RecheckOpponentAbilityEffects(BtlServerFlow *flow, u8 *a)
{
    u32 it;
    u8 *cur;
    int k = BTL_POKEPARAM_GetPokeId(a);
    BTL_SERVER_FLOW_InitFieldPokeIter((u8 *)&it, (u8 **)flow);
    while (BTL_SERVER_FLOW_NextFieldPokeIter((u8 *)&it, (u8 **)flow, &cur)) {
        if (func_021B9A24(k, BTL_POKEPARAM_GetPokeId(cur)) == 0)
            BTL_SERVER_FLOW_ProcDamagedItemReaction(flow, cur, 0);
    }
}






















int BTL_SERVER_FLOW_ProcSubstituteMove(BtlServerFlow *flow, u8 *a)
{
    int n;
    int r;
    if (BTL_POKEPARAM_HasSubstitute(a) == 0) {
        n = BTL_CALC_DivideMaxHpMin1(a, 4);
        if (func_021D59B4(a, 0xd) > n) {
            r = func_0689D5C8(flow->posPoke, BTL_POKEPARAM_GetPokeId(a));
            if (r != 6) {
                BTL_SERVER_FLOW_ChangeHp(flow, a, -n, 1);
                BTL_SERVER_FLOW_ProcDamagedItemReaction(flow, a, 1);
                BTL_POKEPARAM_SetSubstituteHp(a, n);
                BTL_SERVER_CMD_Push(flow->cmdQueue, 0x27, BTL_POKEPARAM_GetPokeId(a), (u16)n);
                BTL_SERVER_CMD_Push(flow->cmdQueue, 0x51, r);
                BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x311, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
                return 1;
            }
        }
        BTL_SERVER_FLOW_PushMsgStd(flow, 0x7b, 0, 0);
    } else {
        BTL_SERVER_FLOW_PushMsgSetPoke(flow, a, 0x314);
    }
    return 0;
}





















/*
 * Opens with `push {r0-r3}`: the address of parameters 3-6 is taken; the
 * fifth and sixth parameters are one 8-byte struct passed by value.
 */
u16 BTL_SERVER_FLOW_ProcSubstituteDamage(BtlServerFlow *flow, u8 *q, u8 *c, u16 d, int sa, u8 sb, u16 *e)
{
    u16 ev = *e;
    u8 sav = sa;
    int m = BTL_POKEPARAM_GetPokeId(c);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x54, m, sav, ev);
    BTL_SERVER_FLOW_PushMsgSetPoke(flow, c, 0x317);
    func_021C5840(flow, 1, (int *)(&sa), &c, 0);
    BTL_SERVER_FLOW_PushCriticalHitMessage(flow, 1, &c, &sb, 0);
    if (BTL_POKEPARAM_DamageSubstitute(c, &d))
        BTL_SERVER_FLOW_RemoveSubstitute(flow, c);
    BTL_SERVER_FLOW_ProcDrainHeal(flow, (u8 *)e, (u32)q, c, d);
    BTL_SERVER_FLOW_ProcMoveCategoryEffect(flow, (u8 *)e, q, c, d, 1);
    BTL_SERVER_FLOW_ProcDamageEndEvents(flow, q, c, (u8 *)e, sa, d, sb, 1);
    return d;
}





















void BTL_SERVER_FLOW_RemoveSubstitute(BtlServerFlow *flow, u8 *a)
{
    int i = BTL_POKEPARAM_GetPokeId(a);
    int r = func_0689D5C8(flow->posPoke, i);
    BTL_SERVER_FLOW_PushMsgSetPoke(flow, a, 0x31a);
    BTL_POKEPARAM_ClearSubstitute(a);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x28, i);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x52, r);
}




















void BTL_SERVER_FLOW_ProcDamageEndEvents(BtlServerFlow *flow, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3)
{
    u32 s = func_021CC8D8(&flow->lock, 9310);
    BTL_SERVER_FLOW_DispatchDamageEndEvents(flow, a, b, c, s0, s1, s2, s3);
    func_021CC95C(&flow->lock, s, 9313);
}





















void BTL_SERVER_FLOW_DispatchDamageEndEvents(BtlServerFlow *flow, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3)
{
    u8 x = BTL_POKEPARAM_GetPokeId(b);
    BTL_EVENT_PushVarFrame(9335);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, x);
    BTL_EVENT_SetVarReadOnly(0x14, ((struct Obj07754 *)c)->f2);
    BTL_EVENT_SetVarReadOnly(0x12, ((struct Obj07754 *)c)->f0);
    BTL_EVENT_SetVarReadOnly(0x38, s0);
    BTL_EVENT_SetVarReadOnly(0x16, c[6]);
    BTL_EVENT_SetVarReadOnly(0x1a, ((struct Obj07754 *)c)->f8);
    BTL_EVENT_SetVarReadOnly(0x32, s1);
    BTL_EVENT_SetVarReadOnly(0x45, s2);
    BTL_EVENT_SetVarReadOnly(0x46, s3);
    BTL_EVENT_SetVarOnce(0x47, 0);
    func_021D70F0(flow, 0x4a);
    func_021D70F0(flow, 0x4b);
    func_021D70F0(flow, 0x4c);
    BTL_EVENT_PopVarFrame(9352);
}





















int BTL_SERVER_FLOW_DispatchMoveFailCheck(BtlServerFlow *flow, u16 *b, u8 *a, u8 *c, int *out)
{
    u8 n1;
    u8 n2;
    u8 i;
    BTL_EVENT_PushVarFrame(9370);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    n1 = func_0689CD40(c);
    n2 = func_0689CD38(c);
    BTL_EVENT_SetVarReadOnly(5, n2);
    BTL_EVENT_SetVarOnce(0x51, 1);
    for (i = 0; i < n2; i++) {
        BTL_EVENT_SetVarReadOnly(i + 6, BTL_POKEPARAM_GetPokeId(func_0689CC70(c, i)));
    }
    BTL_EVENT_SetVarReadOnly(0x12, *b);
    if (n1 != 0) {
        if (n2 != 0) {
            func_021D70F0(flow, 0xa0);
        }
    } else {
        func_021D70F0(flow, 0xa1);
    }
    *out = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(9402);
    if (func_021C88E4(flow) != 0) {
        return 1;
    }
    return 0;
}


















void BTL_SERVER_FLOW_CollectActivePokes(BtlServerFlow *flow, u8 *a)
{
    u32 it;
    u8 *x;
    func_0689CB3C(a);
    BTL_SERVER_FLOW_InitFieldPokeIter((u8 *)&it, (u8 **)flow);
    while (BTL_SERVER_FLOW_NextFieldPokeIter((u8 *)&it, (u8 **)flow, &x)) {
        func_0689CB48(a, x);
    }
    func_0689CF24(a, flow);
}
















int BTL_SERVER_FLOW_ProcTurnCheck(BtlServerFlow *flow)
{
    u8 *a;
    u8 *q;
    int result = 0;
    a = flow->curTargetSetWork;
    if (flow->onceFlag == 0) {
        BTL_SERVER_FLOW_CollectActivePokes(flow, a);
        flow->onceFlag = 1;
        BTL_SERVER_FLOW_ProcPlayerSupportHeal(flow);
    }
    switch (flow->onceFlag) {
    case 0: break;
    case 1:
        flow->onceFlag++;
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x56, 0);
        result = 0;
        if (BTL_SERVER_FLOW_ProcWeatherTurnCheck(flow, a)) { result = 1; break; }
        if (BTL_SERVER_FLOW_CheckShowdown(flow)) return 0;
    case 2:
        flow->onceFlag++;
        if (BTL_SERVER_FLOW_ProcTurnCheckPhase(flow, a, (u8 *)0x76)) { result = 1; break; }
        if (BTL_SERVER_FLOW_CheckShowdown(flow)) return 0;
    case 3:
        flow->onceFlag++;
        if (BTL_SERVER_FLOW_ProcTurnCheckSickness(flow, a)) { result = 1; break; }
        if (BTL_SERVER_FLOW_CheckShowdown(flow)) return 0;
    case 4:
        flow->onceFlag++;
        BTL_SERVER_FLOW_ProcSideEffectsExpire(flow);
        BTL_SERVER_FLOW_ProcFieldEffectsExpire(flow);
    case 5:
        flow->onceFlag++;
        if (BTL_SERVER_FLOW_ProcTurnCheckPhase(flow, a, (u8 *)0x77)) { result = 1; break; }
        if (BTL_SERVER_FLOW_CheckShowdown(flow)) return 0;
    case 6:
        BTL_SERVER_FLOW_ProcTurnCheckPhase(flow, a, (u8 *)0x78);
        flow->onceFlag++;
        func_0689CC84(a);
        q = func_0689CC8C(a);
        while (q) {
            BTL_POKEPARAM_AdvanceTurn(q);
            BTL_EVENT_ClearClientReservedChoice(q);
            BTL_SERVER_CMD_Push(flow->cmdQueue, 0x2e, BTL_POKEPARAM_GetPokeId(q));
            q = func_0689CC8C(a);
        }
        BTL_SERVER_FLOW_ProcTripleShift(flow);
        BTL_EVENT_RemoveDeadFactors();
        if (flow->turnCount < 9999) (flow->turnCount)++;
        flow->onceFlag = 0;
        flow->actionCounter = 0;
        return 0;
    default: break;
    }
    return result;
}















void BTL_SERVER_FLOW_ProcTripleShift(BtlServerFlow *flow)
{
    u32 first, a, b;
    char *x, *y;
    u8 *m, *n;
    u32 mi, ni;
    u8 s, t;
    u8 v, w;
    if (BTL_MAIN_GetRule(flow->mainModule) != 2) return;
    a = func_021B8FF4(flow->mainModule);
    first = a;
    b = (u8)func_021B9064(flow->mainModule, a, 0);
    if (a > b) { first = b; b = a; }
    x = func_021B9AEC(flow->pokeCon, first);
    y = func_021B9AEC(flow->pokeCon, b);
    if (func_021B9B98((u8 *)x) != 1) return;
    if (func_021B9B98((u8 *)y) != 1) return;
    m = func_021B9CE8((u8 *)x);
    n = func_021B9CE8((u8 *)y);
    mi = BTL_POKEPARAM_GetPokeId(m);
    ni = BTL_POKEPARAM_GetPokeId(n);
    s = func_0689D5C8(flow->posPoke, mi);
    t = func_0689D5C8(flow->posPoke, ni);
    if (s == 6 || t == 6) return;
    v = func_021B8DEC(flow->mainModule, s);
    w = func_021B8DEC(flow->mainModule, t);
    if (v != w) return;
    if (func_021B99F0(s) != 0) return;
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x50, first, v, b, w);
    BTL_SERVER_FLOW_ShiftPokes(flow, first, v, 1, 1);
    BTL_SERVER_FLOW_ShiftPokes(flow, b, w, 1, 1);
    BTL_SERVER_FLOW_DispatchShiftEvents(flow, first, v, 1);
    BTL_SERVER_FLOW_DispatchShiftEvents(flow, b, w, 1);
}















/*
 * Verified with one --thumb without region, dsi/1.1p1 -O4,p:
 * typedef unsigned int u32;
 * typedef struct { u32 a[8]; } Block;
 * typedef struct { u32 mode, old, other; Block current, previous; } State;
 * 0x0202E7E0 EXACT: u32 COMM_PLAYER_SUPPORT_GetMode(State *p) { return p->mode; }
 * 0x0202E7E4 EXACT: void COMM_PLAYER_SUPPORT_SavePreviousAndSuspend(State *p) {
 *     p->old = p->mode; p->previous = p->current; p->mode = 3;
 * }
 * lever: a u64 draw and a separate u32 slot preserve the high-product register.
 * note 2026-10-05 (D8 lane16): witnesses COMM_PLAYER_SUPPORT_GetMode and COMM_PLAYER_SUPPORT_SavePreviousAndSuspend filed as src/matched/arm9/COMM_PLAYER_SUPPORT_GetMode.c and COMM_PLAYER_SUPPORT_SavePreviousAndSuspend.c (both EXACT); this file becomes EXACT once the integrator seeds them.
 */
void BTL_SERVER_FLOW_ProcPlayerSupportHeal(BtlServerFlow *flow)
{
    u8 list[4];
    u8 i, n;
    void *work;
    u32 mode, side;
    u8 *desc, *m;
    u32 value, slot;
    u64 draw;
    u8 id;
    int live;
    work = (void *)BTL_MAIN_GetPmsWork(flow->mainModule);
    if (work == 0) return;
    mode = COMM_PLAYER_SUPPORT_GetMode(work);
    if (mode == 0 || mode == 3) return;
    side = func_021B8FF4(flow->mainModule);
    desc = BTL_SERVER_GetClientChecked(flow->server, (int)side);
    i = 0;
    n = 0;
    for (; i < desc[9]; i++) {
        m = func_021B990C(flow->pokeCon, side, (u8)i);
        if (m != 0) {
            if (BTL_POKEPARAM_IsFainted(m) == 0) live = 1;
            else live = 0;
        } else live = 0;
        if (live) {
            if (BTL_POKEPARAM_IsHpFull(m) == 0) list[n++] = BTL_POKEPARAM_GetPokeId(m);
        }
    }
    if (n == 0) return;
    draw = func_0203F0A8();
    slot = (u32)draw;
    if (n != 0) slot = (u32)((draw * (u32)n) >> 32);
    id = list[slot];
    m = func_021B9934(flow->pokeCon, id);
    value = (u32)func_021D59B4(m, 14);
    if (mode == 1) value >>= 1;
    if (value == 0) return;
    if (BTL_SERVER_FLOW_TryRecoverHp(flow, m, (u16)value, (u32)0)) {
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, (u32)0x5a, 0x53, 4, id, 0xffff0000);
        COMM_PLAYER_SUPPORT_SavePreviousAndSuspend(work);
    }
}
















int BTL_SERVER_FLOW_ProcTurnCheckPhase(BtlServerFlow *flow, u8 *a, u8 *b)
{
    u32 s;
    u8 *q;
    func_0689CC84(a);
    s = func_021CC8D8(&flow->lock, 9644);
    BTL_SERVER_FLOW_DispatchTurnCheckEvent(flow, 0x1f, (int)b);
    func_021CC95C(&flow->lock, s, 9646);
    if (BTL_SERVER_FLOW_CheckShowdown(flow) == 0) {
        q = func_0689CC8C(a);
        if (q != 0) {
            do {
                s = func_021CC8D8(&flow->lock, 9652);
                BTL_SERVER_FLOW_DispatchTurnCheckEvent(flow, BTL_POKEPARAM_GetPokeId(q), (int)b);
                func_021CC95C(&flow->lock, s, 9654);
                BTL_SERVER_FLOW_ProcFaintedPoke(flow, q);
                if (BTL_SERVER_FLOW_CheckShowdown(flow) != 0) {
                    break;
                }
                q = func_0689CC8C(a);
            } while (q != 0);
        }
    }
    return BTL_SERVER_FLOW_ProcFaintRewards(flow);
}














void BTL_SERVER_FLOW_DispatchTurnCheckEvent(BtlServerFlow *flow, u32 a, int k)
{
    BTL_EVENT_PushVarFrame(9667);
    BTL_EVENT_SetVarReadOnly(2, a);
    func_021D70F0(flow, k);
    BTL_EVENT_PopVarFrame(9670);
}














/*
 * lever: the first out-value is a one-word struct passed by value.
 */
int BTL_SERVER_FLOW_ProcTurnCheckSickness(BtlServerFlow *flow, u8 *a)
{
    u8 list[6];
    union Slot y;
    u32 x;
    u32 i, n, k, s;
    u8 *q, *m;
    list[0] = 0;
    list[1] = 0;
    list[2] = 0;
    list[3] = 0;
    list[4] = 3;
    list[5] = 0;
    i = 0;
    n = func_0689CD38(a);
    for (; i < n; i++) list[i] = BTL_POKEPARAM_GetPokeId(func_0689CC70(a, i));
    k = 0;
    for (;;) {
        q = func_0689C9F8(k++);
        if (q == 0) break;
        for (i = 0; i < n; i++) {
            m = func_021B9934(flow->pokeCon, list[i]);
            if (BTL_POKEPARAM_IsFainted(m) == 0) {
                if (func_021D6064(m, (u32)q, (union Slot *)(&y), (int *)(&x))) {
                    s = func_021CC8D8(&flow->lock, 9719);
                    func_0689B7A8(m, q, y, x, flow);
                    func_021CC95C(&flow->lock, s, 9721);
                }
            }
        }
        if (BTL_SERVER_FLOW_CheckShowdown(flow)) break;
    }
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x15, (u8)n, (u8)k, BTL_CALC_PackPokeIds(list));
    return BTL_SERVER_FLOW_ProcFaintRewards(flow);
}












void BTL_SERVER_FLOW_ProcSickDamage(BtlServerFlow *flow, u8 *a, u32 b, u32 c)
{
    u32 lock;
    int r;
    lock = func_021CC8D8(&flow->lock, 0x261b);
    r = BTL_SERVER_FLOW_CalcSickDamage(flow, a, b, c);
    if (r && BTL_SERVER_FLOW_CheckAbsorbRecoverAllowed(flow, a, r)) {
        switch (b) {
        case 0: case 1: case 2: case 3: break;
        case 5: BTL_SERVER_FLOW_PushPokeEffectAnim(flow, a, 0x257); break;
        case 4: BTL_SERVER_FLOW_PushPokeEffectAnim(flow, a, 0x258); break;
        case 6: case 7: case 8: break;
        case 10: BTL_SERVER_FLOW_PushPokeEffectAnim(flow, a, 0x273); break;
        case 9: BTL_SERVER_FLOW_PushPokeEffectAnim(flow, a, 0x274); break;
        }
        func_021C8810(flow->msgParam);
        func_0689B8CC(flow->msgParam, a, b);
        BTL_SERVER_FLOW_ProcAbsorbRecovery(flow, a, r, flow->msgParam);
    }
    func_021CC95C(&flow->lock, lock, 0x263b);
}














int BTL_SERVER_FLOW_CalcSickDamage(BtlServerFlow *flow, u8 *a, u32 b, u32 c)
{
    int r;
    BTL_EVENT_PushVarFrame(9801);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x1d, b);
    BTL_EVENT_SetVar(0x32, c);
    func_021D70F0(flow, 0x6b);
    r = BTL_EVENT_GetVar(0x32);
    BTL_EVENT_PopVarFrame(9807);
    return r;
}















/*
 * C tail call through r3 into the ov095 walker func_06898D54 (ov095 is
 * loaded in VRAM at 0x0689xxxx), with the ov093 callback BTL_SERVER_FLOW_OnSideEffectExpired.
 * Earlier notes called this a linker thunk; it is plain mwcc C.
 * 2026-10-05 (D9r lane16): every byte right; MATCH only because the ABS32
 * to BTL_SERVER_FLOW_OnSideEffectExpired needs that file's manifest shard (filed EXACT this wave).
 * Re-run after the shard lands; expected EXACT, then move to src/matched/ov.
 */
void BTL_SERVER_FLOW_ProcSideEffectsExpire(BtlServerFlow *flow)
{
    func_06898D54((void (*)(u8,  u32,  u32))BTL_SERVER_FLOW_OnSideEffectExpired, (u32)flow);
}















void BTL_SERVER_FLOW_OnSideEffectExpired(int v, int k, BtlServerFlow *flow)
{
    BTL_SERVER_FLOW_PushSideEffectExpireMessage(flow, k, v);
}















void BTL_SERVER_FLOW_PushSideEffectExpireMessage(BtlServerFlow *flow, int k, int v)
{
    int r = -1;
    switch (k) {
    case 0: r = 0x7e; break;
    case 1: r = 0x82; break;
    case 2: r = 0x86; break;
    case 3: r = 0x8a; break;
    case 4: r = 0x8e; break;
    case 5: r = 0x92; break;
    case 6: r = 0x96; break;
    case 7: r = 0x9a; break;
    case 8: r = 0x9e; break;
    case 9: break;
    case 10: break;
    case 11: r = 0xa6; break;
    case 12: r = 0xaa; break;
    case 13: r = 0xae; break;
    }
    if (r >= 0) {
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, r, v, 0xffff0000);
    }
}














/*
 * The extent continues into the existing SDK BTL_SERVER_FLOW_OnFieldEffectExpired at 021C4C40.
 * BTL_FIELD_SetCountdown takes two full-word payloads; the original passes
 * the callback address and p unchanged in r0/r1.
 */
void BTL_SERVER_FLOW_ProcFieldEffectsExpire(BtlServerFlow *flow)
{
    BTL_FIELD_QueryStaticSlotC((int)func_021C4C40, (int)flow);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 47, 0);
}














void BTL_SERVER_FLOW_OnFieldEffectExpired(int result, void *arg)
{
    BTL_SERVER_FLOW_PushFieldEffectExpireMessage(arg, result);
}














void BTL_SERVER_FLOW_PushFieldEffectExpireMessage(BtlServerFlow *flow, int k)
{
    int r = -1;
    u8 *q;
    switch (k) {
    case 0: break;
    case 1: r = 0x74; break;
    case 2: r = 0x76; break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: r = 0xb3; break;
    case 7: r = 0xb5; break;
    }
    if (r >= 0) {
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, r, 0xffff0000);
    }
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x24, (u8)k);
    if (k == 7) {
        BTL_SERVER_FLOW_CollectActivePokes(flow, flow->curQueuedSet);
        func_0689CC84(flow->curQueuedSet);
        q = func_0689CC8C(flow->curQueuedSet);
        while (q) {
            if (BTL_POKEPARAM_IsAbleToBattle(q)) {
                BTL_SERVER_FLOW_ProcDamagedItemReaction(flow, q, 0);
            }
            q = func_0689CC8C(flow->curQueuedSet);
        }
    }
}










int BTL_SERVER_FLOW_ProcWeatherTurnCheck(BtlServerFlow *flow, void *it)
{
    int r;
    int changed;
    int mode;
    u8 *a;
    u32 lock;
    int line;
    r = BTL_FIELD_TickCountdown();
    if (r) {
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x40, r);
        BTL_SERVER_FLOW_ProcWeatherChanged(flow, 0);
        return 0;
    }
    changed = 0;
    mode = BTL_SERVER_FLOW_GetEffectiveWeather(flow);
    func_0689CC84(it);
    a = func_0689CC8C(it);
    if (a) {
        line = 0x26c6;
        line += 12;
        do {
            if (!BTL_POKEPARAM_IsFainted(a) && !BTL_POKEPARAM_TestContFlag((struct UtilWork *)a, 5) && !BTL_POKEPARAM_TestContFlag((struct UtilWork *)a, 4)) {
                lock = func_021CC8D8(&flow->lock, 0x26c6);
                r = BTL_SERVER_FLOW_CalcWeatherDamage(flow, a, mode, BTL_CALC_GetWeatherDamage(a, mode));
                if (r) {
                    BTL_SERVER_FLOW_ApplyWeatherDamage(flow, a, mode, r);
                    changed = 1;
                }
                func_021CC95C(&flow->lock, lock, line);
                BTL_SERVER_FLOW_ProcFaintedPoke(flow, a);
            }
            a = func_0689CC8C(it);
        } while (a);
    }
    if (changed) BTL_SERVER_FLOW_PushEffectAnim(flow, 0x255, 6, 6, 0, 0);
    return BTL_SERVER_FLOW_ProcFaintRewards(flow);
}











int BTL_SERVER_FLOW_CalcWeatherDamage(BtlServerFlow *flow, u8 *a, u32 b, u32 c)
{
    u8 f;
    int r;
    int s;
    BTL_EVENT_PushVarFrame(9960);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x39, b);
    r = 0;
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_SetVar(0x32, c);
    func_021D70F0(flow, 0x7f);
    s = BTL_EVENT_GetVar(0x32);
    f = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(9969);
    if (f == 0) {
        r = s;
    }
    return r;
}












void BTL_SERVER_FLOW_ApplyWeatherDamage(BtlServerFlow *flow, u8 *a, int k, int n)
{
    u8 x = BTL_POKEPARAM_GetPokeId(a);
    switch (k) {
    case 4:
        func_021C8838(flow->msgParam, 2, 396);
        func_021C8860((struct S_p12 *)flow->msgParam, x);
        break;
    case 3:
        func_021C8838(flow->msgParam, 2, 399);
        func_021C8860((struct S_p12 *)flow->msgParam, x);
        break;
    default:
        func_021C8810(flow->msgParam);
        break;
    }
    if (n > 0 && BTL_SERVER_FLOW_CheckAbsorbRecoverAllowed(flow, a, n) != 0) {
        func_021C99A0(flow, (const struct Msg *)flow->msgParam);
        func_021C8810(flow->msgParam);
        BTL_SERVER_FLOW_PushEffectAnim(flow, 0x290, func_021C8010(flow, x), 6, 0, 0);
        if ((int)func_021D59B4(a, 0xd) <= n) {
            BTL_SERVER_FLOW_PushEffectAnim(flow, 0x255, 6, 6, 0, 0);
        }
        BTL_SERVER_FLOW_ProcAbsorbRecovery(flow, a, n, 0);
    }
}











/*
 * note: 2026-10-05 recoup: `ok = 0;` written after the call to BTL_SERVER_FLOW_ProcPokeLeaveField (it is
 * only read by the later compare), not before it; this puts the zero store in r2 as in the
 * original. EXACT in c99 and c. Callees: func_021D59B4 and func_021BA1A8 return int,
 * func_021B8DDC (unlabelled in ov093 matched set) returns u8, BTL_SERVER_FLOW_ProcPokeLeaveField and
 * func_021B92B0 are void with three arguments.
 */
int BTL_SERVER_FLOW_ProcFaintedPoke(BtlServerFlow *flow, u8 *a)
{
    u8 k = BTL_POKEPARAM_GetPokeId(a);
    u8 *flags = flow->pokeFlagsA;
    int ok;
    int side;
    int health;
    if (!flags[k] && BTL_POKEPARAM_IsFainted(a)) {
    flags[k] = 1;
    func_0689D15C(flow->historyList, k);
    if (!(func_021BA1A8(flow->mainModule, 0x200) && func_021B8DDC(k) != 0) && flow->lastPokeId != k)
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0, k, 0xffff0000);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x39, k);
    BTL_SERVER_FLOW_ProcPokeLeaveField(flow, a, 0);
    ok = 0;
    BTL_POKEPARAM_ResetAllEffects(a);
    side = func_021B8DDC(k);
    if (side == func_021B8FF4(flow->mainModule)) {
        health = func_021D59B4(a, 15);
        if (health + 30 <= (int)BTL_SERVER_FLOW_GetHighestOpponentLevel(flow)) ok = 1;
        func_021B92B0((char *)(flow->mainModule), a, ok);
    }
    func_0689D2F8(flow->posPoke, k);
    side = func_021B8DDC(k);
    {
        int current = func_021B8FF4(flow->mainModule);
        if (side == current) {
            func_021BA1B4((char **)(flow->mainModule), 0x4c);
        } else if (!func_021B902C(side, current)) {
            func_021BA1B4((char **)(flow->mainModule), 0x19);
            func_021BA1B4((char **)(flow->mainModule), 0x52);
        }
    }
    return 1;
    }
    return 0;
}









u32 BTL_SERVER_FLOW_GetHighestOpponentLevel(BtlServerFlow *flow)
{
    u32 best = 1;
    u32 n = BTL_MAIN_GetRuleSlotSpan((unsigned int **)(flow->mainModule));
    u8 x = func_021B8FF4(flow->mainModule);
    u32 i;
    for (i = 0; i <= n; i++) {
        if (func_021B902C(x, func_021B8DE4((char *)(flow->mainModule), (u8)i)) == 0) {
            int r = func_0689D5FC(flow->posPoke, i);
            if (r != 0x1f) {
                u32 t = func_021D59B4((u8 *)func_021B9934(flow->pokeCon, r), 0xf);
                if (t > best) {
                    best = t;
                }
            }
        }
    }
    return best;
}









/*
 * extent: 198 compiled bytes followed by two zero padding bytes at 021C51CE.
 */
void BTL_SERVER_FLOW_ProcPokeLeaveField(BtlServerFlow *flow, u8 *a, int b)
{
    u32 it;
    u8 *cur;
    int k = BTL_POKEPARAM_GetPokeId(a);
    BTL_SERVER_FLOW_DispatchPokeLeaveEvent(flow, a);
    BTL_SERVER_FLOW_ReleaseBindingTarget(flow, a, 0);
    if (b == 0) {
        BTL_CALC_RemoveAbilityHandlers(a);
        BTL_HANDLER_ITEM_RemoveUnforcedFactors(a);
    } else {
        BTL_CALC_DisableAbilityHandlers(a);
        BTL_HANDLER_ITEM_DisablePokeFactors(a);
    }
    func_021E0434(a);
    BTL_SERVER_FLOW_InitFieldPokeIter((u8 *)&it, (u8 **)flow);
    BTL_SERVER_FLOW_SetFieldPokeIterRule((u8 *)&it, flow);
    while (BTL_SERVER_FLOW_NextFieldPokeIter((u8 *)&it, (u8 **)flow, &cur)) {
        BTL_POKEPARAM_CureSickBySource((struct UtilSlots *)cur, k);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x2c, BTL_POKEPARAM_GetPokeId(cur), k);
    }
    BTL_FIELD_QueryStaticSlotB(k);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x23, k);
    if (!BTL_SERVER_FLOW_CheckShowdown(flow) && (u16)func_021D59B4(a, 0x11) == 0x7f)
        BTL_SERVER_FLOW_RecheckOpponentAbilityEffects(flow, a);
}









void BTL_SERVER_FLOW_DispatchPokeLeaveEvent(BtlServerFlow *flow, u8 *a)
{
    int line = 0x27DF;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVar(2, BTL_POKEPARAM_GetPokeId(a));
    func_021D70F0(flow, 0xA3);
    BTL_EVENT_PopVarFrame(line + 3);
}








int BTL_SERVER_FLOW_ProcFaintRewards(BtlServerFlow *flow)
{
    int result = 0;
    u32 i;
    u32 count;
    u8 *a;
    if (BTL_MAIN_CheckEventOverlayAllowed(flow->mainModule)) {
        count = func_0689D174(flow->historyList, 0);
        for (i = 0; i < count; i++) {
            if (!func_0689D1A0(flow->historyList, 0, i)) {
                a = func_021B9934((char *)(flow->pokeCon), func_0689D184(flow->historyList, 0, i));
                if (!BTL_MAIN_GetCompetitor(flow->mainModule) && !((struct Flags_021C5108 *)&flow->stateFlags)->b && BTL_SERVER_FLOW_CheckShowdown(flow) && BTL_SERVER_FLOW_CheckPlayerSideAlive(flow)) {
                    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x55, BTL_MAIN_GetWinBgm(flow->mainModule));
                    ((struct Flags_021C5108 *)&flow->stateFlags)->b = 1;
                }
                if (BTL_SERVER_FLOW_ProcExpForFaintedPoke(flow, a)) result = 1;
                func_0689D1BC(flow->historyList, 0, i);
            }
        }
    }
    return result;
}

















int BTL_SERVER_FLOW_ProcExpForFaintedPoke(BtlServerFlow *flow, u8 *a)
{
    char *g;
    if (func_021B9A40(BTL_POKEPARAM_GetPokeId(a)) == 1) {
        g = func_021B9AEC(flow->pokeCon, func_021B8FF4(flow->mainModule));
        func_021CB2D4(flow, (u8 *)g, (u32)a, (Rec_021CAA58 *)flow->moveEffectParam);
        return BTL_SERVER_FLOW_ApplyPartyExp(flow, (u8 *)g, (const struct Entry_p11 *)flow->moveEffectParam);
    }
    return 0;
}

















/*
 * lever: const entry source schedules byte arguments early; k precedes entry in declarations.
 */
int BTL_SERVER_FLOW_ApplyPartyExp(BtlServerFlow *flow, u8 *g, const struct Entry_p11 *q)
{
    u32 i;
    int result = 0;
    u8 *a;
    int k;
    u32 value;
    int cmd;
    const struct Entry_p11 *entry;
    u32 remaining;
    for (i = 0; i < 6; i++) {
        entry = &q[i];
        if (!entry->value) continue;
        a = (u8 *)func_021B9BF0((struct S2 *)g, (u8)i);
        if (func_021D59B4(a, 15) >= 100) continue;
        value = entry->value;
        cmd = entry->flag ? 0x2b : 0x2a;
        k = BTL_POKEPARAM_GetPokeId(a);
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, (u16)cmd, k, value, 0xffff0000);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x3e, k, q->a, q->b, q->c, q->d, q->e, q->f);
        remaining = value;
        while (BTL_POKEPARAM_AddExp((struct Obj *)a, &remaining, (struct Result *)flow->expResult)) {}
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x45, k, value);
        func_021BA1CC(flow->mainModule, 0x1b, value);
        result = 1;
    }
    return result;
}


















int BTL_SERVER_FLOW_TryClearContFlag(BtlServerFlow *flow, u8 *a, int b)
{
    u8 n;
    if (BTL_POKEPARAM_TestContFlag((struct UtilWork *)a, b)) {
        n = BTL_POKEPARAM_GetPokeId(a);
        BTL_SERVER_FLOW_ClearContFlag(flow, a, b);
        b = 0x1a;
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 0x1a)) {
            BTL_SERVER_FLOW_CureSick(flow, a, b, 0);
        }
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x31, n, 0);
        BTL_SERVER_FLOW_MarkActionDone(flow, n);
        return 1;
    }
    return 0;
}


















void *BTL_SERVER_FLOW_ClearPendingCounter(char *p)
{
    ((struct Obj21097 *)p)->f220 = 0;
    return p;
}


















void BTL_SERVER_FLOW_PushPokeEffectAnim(BtlServerFlow *flow, u8 *a, int b)
{
    int r = func_0689D5C8(flow->posPoke, BTL_POKEPARAM_GetPokeId(a));
    if (r != 6) {
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x4d, r, b);
    }
}


















/*
 * leaf: Sole blocker of BTL_SERVER_FLOW_ProcAction; ordinary default-argument tail call.
 * extent: Next function 021C54C8 is already separately matched; 12-byte leaf.
 * semantics: Forwards both pointer inputs unchanged; literal argument 0x350.
 */
void BTL_SERVER_FLOW_PushActionBlockedMessage(BtlServerFlow *flow, u8 *a)
{
    BTL_SERVER_FLOW_PushMsgSetPoke(flow, a, 0x350);
}



















void BTL_SERVER_FLOW_PushConfusionMessage(BtlServerFlow *flow, u8 *a)
{
    BTL_SERVER_FLOW_PushPokeEffectAnim(flow, a, 0x25B);
    BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x15C, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
}



















void BTL_SERVER_FLOW_PushInfatuationMessage(BtlServerFlow *flow, u8 *a)
{
    u8 v = BTL_POKEPARAM_GetSickParam((struct UtilSlots *)a, 7);
    BTL_SERVER_FLOW_PushPokeEffectAnim(flow, a, 0x25C);
    BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x14d, BTL_POKEPARAM_GetPokeId(a), v, 0xffff0000);
}


















void BTL_SERVER_FLOW_ApplyFixedDamageEffect(BtlServerFlow *flow, u8 *a, int c)
{
    int n;
    n = BTL_POKEPARAM_GetPokeId(a);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x36, n);
    BTL_SERVER_FLOW_ChangeHp(flow, a, (int)(0u - (u32)c), 1);
    BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 0x50, n, 0xffff0000);
}



















void BTL_SERVER_FLOW_CureMajorStatusWithMessage(BtlServerFlow *flow, u8 *a, int k, int flag)
{
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    BTL_POKEPARAM_ClearMajorStatus((struct UtilSlots *)a);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x10, n);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x35, n, 0);
    if (flag != 0) {
        switch (k) {
        case 2:
            BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x138, n, 0xffff0000);
            break;
        case 3:
            BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x126, n, 0xffff0000);
            break;
        default:
            BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x156, n, 0xffff0000);
            break;
        }
    }
}



















void BTL_SERVER_FLOW_PushPokeCmd59(BtlServerFlow *flow, u8 *a, int b)
{
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x59, BTL_POKEPARAM_GetPokeId(a), b);
}
















void BTL_SERVER_FLOW_CureSick(BtlServerFlow *flow, u8 *a, int k, union Slot *out)
{
    u8 n;
    if (k != 0) {
        n = BTL_POKEPARAM_GetPokeId(a);
        if (out != 0) *out = BTL_POKEPARAM_GetSickContRaw(a, k);
        if (k < 6) {
            BTL_POKEPARAM_ClearMajorStatus((struct UtilSlots *)a);
            BTL_SERVER_CMD_Push(flow->cmdQueue, 0x10, n);
            if (func_0689D5C8(flow->posPoke, n) != 6) {
                BTL_SERVER_CMD_Push(flow->cmdQueue, 0x35, n, 0);
            }
        } else {
            BTL_POKEPARAM_CureSick((struct UtilSlots *)a, k);
            BTL_SERVER_CMD_Push(flow->cmdQueue, 0x11, n, (u16)k);
        }
    }
}

















int BTL_SERVER_FLOW_ResolveCureSickId(u8 *p, int *pv)
{
    int ret = 0;
    int r = BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)p);
    int t;
    switch (*pv) {
    case 0:
        break;
    case 0x24:
        if (r) ret = r;
        *pv = 0;
        break;
    case 0x25:
        if (r) {
            ret = r;
            *pv = 6;
        } else {
            if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)p, 6)) ret = 6;
            *pv = 0;
        }
        break;
    case 0x26:
        t = BTL_CALC_FindMajorSick((struct Unk021D62A8 *)p);
        if (t) return t;
        *pv = ret;
        return t;
    default:
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)p, *pv)) ret = *pv;
        *pv = 0;
        break;
    }
    return ret;
}

















/* 021C5718  4-arg call, field 0xc and the pool constant 0xffff0000 */
void BTL_SERVER_FLOW_PushMsgStdFailed(BtlServerFlow *flow, u8 *a, u32 b)
{
    BTL_SERVER_CMD_PushVariable((void *)(flow->cmdQueue), 0x5a, 0x47, 0xffff0000);
}



















void BTL_SERVER_FLOW_PushMoveBlockedMessage(BtlServerFlow *flow, u8 *a, u32 v)
{
    BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 213, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
}



















void BTL_SERVER_FLOW_PushNoEffectMessage(BtlServerFlow *flow, u8 *a)
{
    BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 210, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
}



















void BTL_SERVER_FLOW_PushActionFailedMessage(BtlServerFlow *flow, u8 *a)
{
    BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 216, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
}




















void BTL_SERVER_FLOW_PushMoveEffectiveness(BtlServerFlow *flow, u16 *a, u32 n, int *arr, u8 **ptrs, u16 *vals, u8 *unused1, int unused2)
{
    u32 i;
    u8 hi;
    u8 lo;
    int k;
    lo = 0;
    hi = 0;
    for (i = 0; i < n; i++) {
        BTL_SERVER_FLOW_SubtractHp(flow, ptrs[i], vals[i]);
        if (arr[i] > 3) hi++;
        if (arr[i] < 3) lo++;
    }
    if (hi) k = 2;
    else if (lo) k = 3;
    else k = 1;
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x33, (u8)n, (u8)k, *a);
    for (i = 0; i < n; i++) {
        BTL_SERVER_CMD_WriteU8Wrapper(flow->cmdQueue, BTL_POKEPARAM_GetPokeId(ptrs[i]));
    }
}



















void func_021C5840(BtlServerFlow *flow, u32 count, int *v, u8 **a, int flag)
{
    u8 low = 0;
    u8 high = 0;
    u32 i;
    u8 list[3];
    for (i = 0; i < count; i++) {
        if (v[i] > 3) high++;
        if (v[i] < 3) low++;
    }
    if (flag) {
        if (high) {
            u8 n = 0;
            for (i = 0; i < count; i++) {
                if (v[i] > 3) list[n++] = BTL_POKEPARAM_GetPokeId(a[i]);
            }
            switch (high) {
            case 1: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 6, list[0], 0xffff0000); break;
            case 2: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 9, list[0], list[1], 0xffff0000); break;
            case 3: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 12, list[0], list[1], list[2], 0xffff0000); break;
            }
        }
        if (low) {
            u8 n;
            i = 0;
            n = 0;
            for (; i < count; i++) {
                if (v[i] < 3) list[n++] = BTL_POKEPARAM_GetPokeId(a[i]);
            }
            switch (low) {
            case 1: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 15, list[0], 0xffff0000); break;
            case 2: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 18, list[0], list[1], 0xffff0000); break;
            case 3: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 21, list[0], list[1], list[2], 0xffff0000); break;
            }
        }
    } else {
        if (high) BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 78, 0xffff0000);
        else if (low) BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 79, 0xffff0000);
    }
}




















void BTL_SERVER_FLOW_PushCriticalHitMessage(BtlServerFlow *flow, u32 n, u8 **a, u8 *b, int flag)
{
    u32 i;
    for (i = 0; i < n; i++) {
        if (b[i]) {
            if (flag) {
                BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x180, BTL_POKEPARAM_GetPokeId(a[i]), 0xffff0000);
            } else {
                BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 0x51, 0xffff0000);
            }
        }
    }
}


















void BTL_SERVER_FLOW_PushAbilityPopupIn(BtlServerFlow *flow, u8 *a)
{
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x57, BTL_POKEPARAM_GetPokeId(a));
}


















void BTL_SERVER_FLOW_PushAbilityPopupOut(BtlServerFlow *flow, u8 *a)
{
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x58, BTL_POKEPARAM_GetPokeId(a));
}



















void BTL_SERVER_FLOW_PushSignedChangeMessage(BtlServerFlow *flow, u8 *a, int b, int c)
{
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    if (c > 0) {
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x99, n, b, 0xffff0000);
    } else {
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0xae, n, b, 0xffff0000);
    }
}

















void BTL_SERVER_FLOW_ChangeStatStage(BtlServerFlow *flow, u8 *a, int c, int d, u16 msg, int flag)
{
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    if (d > 0) {
        int x = BTL_POKEPARAM_RaiseStatStage((s8 *)a, c, d);
        u8 t = x;
        BTL_SERVER_CMD_Push(flow->cmdQueue, 9, n, (u8)c, t);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x37, n, (u8)c, t);
        if (flag) {
            if (msg == 0) BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x1b, n, c, x, 0xffff0000);
            else BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x3aa, n, msg, c, x, 0xffff0000);
        }
    } else {
        int x = BTL_POKEPARAM_LowerStatStage((s8 *)a, c, -d);
        u8 t = x;
        BTL_SERVER_CMD_Push(flow->cmdQueue, 10, n, (u8)c, t);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x38, n, (u8)c, t);
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x5a, n, c, x, 0xffff0000);
    }
}


















void BTL_SERVER_FLOW_ChangeHp(BtlServerFlow *flow, u8 *a, int c, int d)
{
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    if (c > 0) {
        BTL_POKEPARAM_AddHp((struct Unk021D5FA4 *)a, (u16)c);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 2, n, (u16)c);
    } else if (c < 0) {
        BTL_SERVER_FLOW_SubtractHp(flow, a, -c);
    }
    if (d) {
        if (func_0689D5C8(flow->posPoke, n) != 6) {
            BTL_SERVER_CMD_Push(flow->cmdQueue, 0x41, n);
        }
    }
}
















void BTL_SERVER_FLOW_KillPoke(BtlServerFlow *flow, u8 *a, int c)
{
    int n;
    func_021D59B4(a, 13);
    n = BTL_POKEPARAM_GetPokeId(a);
    BTL_POKEPARAM_ZeroHp(a);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 3, n);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x43, n, c);
}

















void BTL_SERVER_FLOW_SetSickCont(BtlServerFlow *flow, u8 *a, int k, union Slot s)
{
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    BTL_POKEPARAM_SetSickCont(a, k, s);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0xf, n, (u8)k, s.raw);
    if (k < 6) {
        if (k == 5 && BTLV_CORE_IsSlotKind1Index15(s)) k = 6;
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x35, n, k);
    }
}
















void BTL_SERVER_FLOW_PushSickFailedMessage(BtlServerFlow *flow, u8 *a, int kind, u32 v)
{
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    switch (kind) {
    case 1:
        switch (v) {
        case 5: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0xf9, n, 0xffff0000); break;
        case 4: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x10b, n, 0xffff0000); break;
        case 1: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x11a, n, 0xffff0000); break;
        case 2: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x13b, n, 0xffff0000); break;
        case 3: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x129, n, 0xffff0000); break;
        case 6: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x162, n, 0xffff0000); break;
        case 15: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x18, n, 0xffff0000); break;
        case 20: return;
        default: BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 0x47, 0xffff0000); break;
        }
        flow->stateFlags.raw |= 0x10;
        break;
    case 2:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0xd2, n, 0xffff0000);
        flow->stateFlags.raw |= 0x10;
        break;
    default:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, 0x47, 0xffff0000);
        flow->stateFlags.raw |= 0x10;
        break;
    }
}

















void BTL_SERVER_FLOW_PushMsgSetPoke(BtlServerFlow *flow, u8 *a, int b)
{
    BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, b, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
}

















void BTL_SERVER_FLOW_PushMsgStd(BtlServerFlow *flow, u32 a, int n, const int *v)
{
    switch (n) {
    default:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, a, 0xffff0000);
        break;
    case 1:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, a, v[0], 0xffff0000);
        break;
    case 2:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, a, v[0], v[1], 0xffff0000);
        break;
    case 3:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, a, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5a, a, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}

















void BTL_SERVER_FLOW_PushMsgStdSe(BtlServerFlow *flow, u32 a, u32 b, int n, int *v)
{
    switch (n) {
    default:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5c, a, b, 0xffff0000);
        break;
    case 1:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5c, a, b, v[0], 0xffff0000);
        break;
    case 2:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5c, a, b, v[0], v[1], 0xffff0000);
        break;
    case 3:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5c, a, b, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5c, a, b, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}

















void BTL_SERVER_FLOW_PushMsgSet(BtlServerFlow *flow, u32 a, int n, const int *v)
{
    switch (n) {
    default:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, a, 0xffff0000);
        break;
    case 1:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, a, v[0], 0xffff0000);
        break;
    case 2:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, a, v[0], v[1], 0xffff0000);
        break;
    case 3:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, a, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, a, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}

















void BTL_SERVER_FLOW_PushMsgSetSe(BtlServerFlow *flow, u32 a, u32 b, int n, int *v)
{
    switch (n) {
    default:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5d, a, b, 0xffff0000);
        break;
    case 1:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5d, a, b, v[0], 0xffff0000);
        break;
    case 2:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5d, a, b, v[0], v[1], 0xffff0000);
        break;
    case 3:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5d, a, b, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5d, a, b, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}
















void BTL_SERVER_FLOW_SubtractHp(BtlServerFlow *flow, u8 *a, int n)
{
    if (func_021B911C(flow->mainModule, 4) == 0) {
        BTL_POKEPARAM_SubHp(a, n);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 1, BTL_POKEPARAM_GetPokeId(a), (u16)n);
    }
}

















void BTL_SERVER_FLOW_RestoreMovePp(BtlServerFlow *flow, u8 *a, int b, int c, int d)
{
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    if (d) {
        BTL_POKEPARAM_RestoreRealMovePP(a, b, c);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 8, n, b, c);
    } else {
        BTL_POKEPARAM_RestoreMovePP(a, b, c);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 7, n, b, c);
    }
}
















void BTL_SERVER_FLOW_PushPokeCmd42(BtlServerFlow *flow, u8 *a)
{
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x42, BTL_POKEPARAM_GetPokeId(a));
}
















void BTL_SERVER_FLOW_SetContFlag(BtlServerFlow *flow, u8 *a, u32 n)
{
    BTL_POKEPARAM_SetContFlag(a, n);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x19, BTL_POKEPARAM_GetPokeId(a), n);
}
















void BTL_SERVER_FLOW_ClearContFlag(BtlServerFlow *flow, u8 *a, unsigned int n)
{
    BTL_POKEPARAM_ClearContFlag(a, n);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x1a, BTL_POKEPARAM_GetPokeId(a), n);
}
















void BTL_SERVER_FLOW_SetTurnFlag(BtlServerFlow *flow, u8 *a, unsigned int n)
{
    BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, n);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x1b, BTL_POKEPARAM_GetPokeId(a), n);
}
















void BTL_SERVER_FLOW_ProcClientMemberChange(BtlServerFlow *flow, u8 *a)
{
    unsigned int i;
    struct Arr *arr;
    for (i = 0; i < a[0]; i++) {
        arr = (struct Arr *)func_021B9AEC(flow->pokeCon, a[i + 1]);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x2a, a[i + 1]);
        func_021B9D10(flow->mainModule, arr, a[i + 1]);
    }
}
















static inline u16 entry_key(Entry *e)
{
    if (e->b.full.type == 1) return e->b.full.move;
    return 0;
}
















int BTL_SERVER_FLOW_ProcPursuitBeforeSwitch(BtlServerFlow *flow, u8 *a)
{
    u32 i;
    for (i = 0; i < flow->numActOrder; i++) {
        u16 key;
        if (flow->actOrder[i].a == a) continue;
        if (flow->actOrder[i].done) continue;
        key = entry_key(&flow->actOrder[i]);
        if (key == 228) {
            if (func_021E02DC(flow->actOrder[i].a, key, func_021D59B4(flow->actOrder[i].a, 12)))
                flow->actOrder[i].f = 1;
        }
    }
    flow->lastFlag = 0;
    BTL_EVENT_PushVarFrame(11288);
    BTL_EVENT_SetVarReadOnly(6, BTL_POKEPARAM_GetPokeId(a));
    func_021D70F0(flow, 0x53);
    BTL_EVENT_PopVarFrame(11291);
    for (i = 0; i < flow->numActOrder; i++) {
        u16 key;
        if (flow->actOrder[i].f) {
            key = entry_key(&flow->actOrder[i]);
            if (key == 228) func_021E03D8(flow->actOrder[i].a, key);
            flow->actOrder[i].f = 0;
        }
    }
    return flow->lastFlag;
}
















int BTL_SERVER_FLOW_QueryForcedMoveEvent(BtlServerFlow *flow, u8 *a, u32 unused, u32 c, struct O_p11 *out)
{
    int t;
    int line = 11327;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0xE, c);
    BTL_EVENT_SetVar(0x12, 0);
    BTL_EVENT_SetVar(0xD, 6);
    BTL_EVENT_SetVarOnce(0x41, 0);
    func_021D70F0(flow, 0x18);
    out->h = BTL_EVENT_GetVar(0x12);
    out->b = BTL_EVENT_GetVar(0xD);
    t = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(line + 13);
    return t == 0;
}
















u8 BTL_SERVER_FLOW_QueryActionAllowedEvent(BtlServerFlow *flow, u8 *a)
{
    u8 r;
    BTL_EVENT_PushVarFrame(11357);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarOnce(0x11, 1);
    func_021D70F0(flow, 0xF);
    r = BTL_EVENT_GetVar(0x11);
    BTL_EVENT_PopVarFrame(11362);
    return r;
}















void BTL_SERVER_FLOW_NotifyMoveEvent(BtlServerFlow *flow, u8 *a, unsigned int n)
{
    BTL_EVENT_PushVarFrame(11378);
    BTL_EVENT_SetVar(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVar(0x12, n);
    func_021D70F0(flow, 0x15);
    BTL_EVENT_PopVarFrame(11382);
}
















u32 BTL_SERVER_FLOW_ProcConfusionDamage(BtlServerFlow *flow, u8 *q)
{
    u16 dmg;
    int r;
    int a = func_021D59B4(q, 8);
    int b = func_021D59B4(q, 9);
    int c = func_021D59B4(q, 0xF);

    dmg = BTL_CALC_CalcBaseDamage(0x28, a, c, b);
    dmg = _u32_div_f((100 - BTL_CALC_Random(16)) * dmg, 100);
    if (dmg == 0) {
        dmg = 1;
    }
    r = BTL_SERVER_FLOW_CheckEndureEvent(flow, q, q, 0, &dmg);
    BTL_SERVER_FLOW_ApplyFixedDamageEffect(flow, q, dmg);
    if (r != 0) {
        BTL_SERVER_FLOW_ProcDamageAftereffect(flow, q, r);
    }
    return dmg;
}
















int BTL_SERVER_FLOW_QueryActionMessageEvent(BtlServerFlow *flow, u8 *a, u32 c, u32 d, u8 *e)
{
    int r;
    int line = 11440;
    func_021C8810(e);
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, d);
    BTL_EVENT_SetVarReadOnly(0x3F, (u32)e);
    BTL_EVENT_SetVarOnce(0x51, 0);
    func_021D70F0(flow, 0x19);
    r = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(line + 7);
    return r;
}
















/*
 * Byte-correct except the call to the unlabelled arm9 leaf 0x0201C1E8,
 * which has no witness outside this function (evidence class: none until the
 * leaf is filed; it belongs to another owner, inside a labelled arm9 region). Verified C for
 * that leaf (`one` --thumb, no --region, EXACT, 12 bytes):
 *
 *   extern u32 sub_0201BD28(void *p, u32 id);   // symbols: sub_0201BD28 0x0201BD28 thumb
 *   u32 WAZA_TOOL_GetDamageType(void *p) { return sub_0201BD28(p, 2); }
 *
 * Once the leaf's shard exists re-run this file; it should go EXACT.
 */
void BTL_SERVER_FLOW_GetMoveParam(BtlServerFlow *flow, u16 q, u8 *a, struct Out64B4 *out)
{
    int line = 11464;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarOnce(0x16, WAZA_TOOL_GetType((void *)q));
    BTL_EVENT_SetVar(0x1C, BTL_POKEPARAM_GetTypePair(a));
    BTL_EVENT_SetVar(0x1A, WAZA_TOOL_GetDamageType(q));
    BTL_EVENT_SetVar(0x1B, sub_0201BD28(q, 0x1B));
    BTL_EVENT_SetVarOnce(0x4B, 0);
    func_021D70F0(flow, 0x28);
    out->h0 = q;
    out->h2 = q;
    out->b6 = BTL_EVENT_GetVar(0x16);
    out->h4 = BTL_EVENT_GetVar(0x1C);
    out->w8 = BTL_EVENT_GetVar(0x1A);
    out->wC = BTL_EVENT_GetVar(0x1B);
    out->w10 = 0;
    if (BTL_EVENT_GetVar(0x4B) != 0) {
        out->b6 = 0x11;
    }
    BTL_EVENT_PopVarFrame(11493);
}
















void BTL_SERVER_FLOW_DispatchMoveDoneEvent(BtlServerFlow *flow, u8 *a, u32 c, u32 d)
{
    BTL_EVENT_PushVarFrame(11508);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, c);
    BTL_EVENT_SetVarReadOnly(0x22, d);
    func_021D70F0(flow, 0x21);
    BTL_EVENT_PopVarFrame(11513);
}
















int BTL_SERVER_FLOW_QueryMoveExecuteEvent(BtlServerFlow *flow, u8 *a, u32 e, u8 *d)
{
    u32 n;
    u32 i;
    int r;
    u16 t;
    n = func_0689CD38(d);
    BTL_EVENT_PushVarFrame(11533);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, e);
    BTL_EVENT_SetVarReadOnly(5, n);
    for (i = 0; i < n; i++) {
        BTL_EVENT_SetVarReadOnly(i + 6, BTL_POKEPARAM_GetPokeId(func_0689CC70(d, i)));
    }
    BTL_EVENT_SetVarOnce(0x3E, 0);
    BTL_EVENT_SetVarOnce(0x13, 0);
    func_021D70F0(flow, 0x24);
    r = BTL_EVENT_GetVar(0x3E);
    t = BTL_EVENT_GetVar(0x13);
    BTL_EVENT_PopVarFrame(11550);
    if (t != 0) {
        *(u16 *)flow->curTurnState = t;
    }
    return r;
}














int BTL_SERVER_FLOW_QueryActionCancelEvent(BtlServerFlow *flow, u8 *a, u8 *a2, u16 a3)
{
    int r;
    BTL_EVENT_PushVarFrame(11574);
    BTL_EVENT_SetVar(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVar(0x51, 0);
    func_021D70F0(flow, 0x2E);
    r = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(11579);
    return r;
}














int BTL_SERVER_FLOW_QueryFirstTargetBlockEvent(BtlServerFlow *flow, u8 *a, void *c)
{
    u8 *q;
    int r;
    q = func_0689CC70(c, 0);
    BTL_EVENT_PushVarFrame(11599);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, q ? BTL_POKEPARAM_GetPokeId(q) : 0x1F);
    BTL_EVENT_SetVarOnce(0x41, 0);
    func_021D70F0(flow, 0x93);
    r = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(11605);
    return r;
}













int BTL_SERVER_FLOW_QueryMoveBlockedEvent(BtlServerFlow *flow, u8 *a, u32 c)
{
    int r;
    BTL_EVENT_PushVarFrame(11622);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, c);
    BTL_EVENT_SetVarOnce(0x51, 0);
    func_021D70F0(flow, 0x94);
    r = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(11628);
    return r;
}













int BTL_SERVER_FLOW_QueryMoveRedirectEvent(BtlServerFlow *flow, u8 *a, u8 *d, u16 unused, u8 *out8, u32 *out32)
{
    u32 n;
    u32 i;
    int t;
    n = func_0689CD38(d);
    BTL_EVENT_PushVarFrame(11648);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(5, n);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            BTL_EVENT_SetVarReadOnly(i + 6, BTL_POKEPARAM_GetPokeId(func_0689CC70(d, i)));
        }
    } else {
        BTL_EVENT_SetVarReadOnly(6, 0x1F);
    }
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_SetVarOnce(0x51, 0);
    BTL_EVENT_SetVarOnce(0x4F, 0);
    func_021D70F0(flow, 0x95);
    if (BTL_EVENT_GetVar(0x51) != 0) {
        *out8 = BTL_EVENT_GetVar(6);
    } else {
        *out8 = 0x1F;
    }
    *out32 = BTL_EVENT_GetVar(0x4F);
    t = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(11677);
    return t == 0;
}












void BTL_SERVER_FLOW_NotifyMoveBeginEvent(BtlServerFlow *flow, u8 *a)
{
    BTL_EVENT_PushVarFrame(11692);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    func_021D70F0(flow, 0x96);
    BTL_EVENT_PopVarFrame(11695);
}












void BTL_SERVER_FLOW_NotifyMoveFinishEvent(BtlServerFlow *flow, u8 *a, int a2)
{
    BTL_EVENT_PushVarFrame(11709);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    func_021D70F0(flow, 0x97);
    BTL_EVENT_PopVarFrame(11712);
}












int BTL_SERVER_FLOW_QueryMoveTargetsAllowedEvent(BtlServerFlow *flow, u8 *a, u8 *d, u16 a3)
{
    u32 n;
    u32 i;
    u8 t;
    n = func_0689CD38(d);
    BTL_EVENT_PushVarFrame(11731);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_SetVarReadOnly(5, n);
    for (i = 0; i < n; i++) {
        BTL_EVENT_SetVarReadOnly(i + 6, BTL_POKEPARAM_GetPokeId(func_0689CC70(d, i)));
    }
    func_021D70F0(flow, 0x98);
    t = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(11742);
    return t == 0;
}













int BTL_SERVER_FLOW_QuerySemiInvulnerableHit(BtlServerFlow *flow, u8 *a, u8 *b, u32 v)
{
    int r = 0;
    u32 t = BTL_POKEPARAM_GetSemiInvulnerableFlag((struct UtilWork *)b);
    if (t != 0x10) {
        BTL_EVENT_PushVarFrame(11765);
        BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
        BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
        BTL_EVENT_SetVarReadOnly(0x21, t);
        BTL_EVENT_SetVarOnce(0x42, 1);
        func_021D70F0(flow, 0x99);
        if (BTL_EVENT_GetVar(0x42)) r = 1;
        BTL_EVENT_PopVarFrame(11775);
    }
    return r;
}














int func_021C69B8(BtlServerFlow *flow, u8 *a, u32 c, u16 id)
{
    int r = WAZA_TOOL_IsAlwaysHit(id);
    if (r == 0) {
        BTL_EVENT_PushVarFrame(0x2E15);
        BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
        BTL_EVENT_SetVarOnce(0x51, 0);
        func_021D70F0(flow, 0x32);
        r = BTL_EVENT_GetVar(0x51);
        BTL_EVENT_PopVarFrame(0x2E1A);
    }
    return r;
}














int BTL_SERVER_FLOW_CalcAccuracyRatio(BtlServerFlow *flow, u8 *a, u8 *b, struct Q *q)
{
    int x, y;
    u32 t = sub_0201BD28(q->h0, 4);
    BTL_EVENT_PushVarFrame(0x2E2F);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x12, q->h0);
    BTL_EVENT_SetVarReadOnly(0x1a, q->w8);
    BTL_EVENT_SetVarOnce(0x2b, t);
    BTL_EVENT_SetVarRanged(0x35, 4 << 10, 0x19A, 4 << 15);
    func_021D70F0(flow, 0x34);
    x = BTL_EVENT_GetVar(0x2b);
    y = BTL_EVENT_GetVar(0x35);
    BTL_EVENT_PopVarFrame(0x2E39);
    return BTL_CALC_MulRatio(x, y);
}














int BTL_SERVER_FLOW_CheckOneHitKoHit(BtlServerFlow *flow, u8 *a, u8 *b, u16 id)
{
    u8 x, y, c;
    int r, t;
    x = func_021D59B4(a, 15);
    y = func_021D59B4(b, 15);
    if (x < y) return 0;
    BTL_EVENT_PushVarFrame(0x2E5A);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    r = 0;
    BTL_EVENT_SetVarOnce(0x41, 0);
    func_021D70F0(flow, 0x70);
    t = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(0x2E60);
    if (t) return r;
    if (func_021BF324(flow, a, b)) {
        r = 1;
    } else {
        c = sub_0201BD28(id, 4);
        c += (u8)(x - y);
        if (BTL_CALC_Random(100) < c) r = 1;
    }
    return r;
}














int BTL_SERVER_FLOW_QueryTypeImmunityEvent(BtlServerFlow *flow, u8 *a, u8 *b, u8 *q)
{
    int r;
    BTL_EVENT_PushVarFrame(11907);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x16, q[6]);
    BTL_EVENT_SetVarOnce(0x51, 0);
    func_021D70F0(flow, 0x30);
    r = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(11914);
    return r;
}














void BTL_SERVER_FLOW_NotifyTypeImmunityEvent(BtlServerFlow *flow, u8 *a, u8 *b)
{
    BTL_EVENT_PushVarFrame(11928);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    func_021D70F0(flow, 0x31);
    BTL_EVENT_PopVarFrame(11932);
}














#pragma opt_lifetimes off













/*
 * note 2026-10-05 (wave P13 B10): the older DIFF (12 B, p and h/r in each other's
 *   r4/r5) closed with #pragma opt_lifetimes off around the function, see
 *   docs/idioms/a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off.md.
 *   Source is unchanged from the old draft. Plain literals already (11952, 0x2c).
 *   Callees: BTL_POKEPARAM_GetCritStage returns u8, BTL_CALC_RollCriticalHit takes u8 (both matched);
 *   sub_0201BD28 and WAZA_TOOL_IsAlwaysCritical return u32 (matched arm9 units).
 */
int BTL_SERVER_FLOW_CheckCriticalHit(BtlServerFlow *flow, u8 *a, u8 *b, u16 q)
{
    int r, n;
    u16 h;
    h = sub_0201BD28(q, 7);
    h = h + BTL_POKEPARAM_GetCritStage((struct UtilWork *)a);
    BTL_EVENT_PushVarFrame(11952);
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVar(0x2c, h);
    r = 0;
    BTL_EVENT_SetVarOnce(0x41, 0);
    func_021D70F0(flow, 0x36);
    if (BTL_EVENT_GetVar(0x41) == 0) {
        if (WAZA_TOOL_IsAlwaysCritical(q)) {
            r = 1;
        } else {
            n = BTL_EVENT_GetVar(0x2c);
            if (n > 4) n = 4;
            r = BTL_CALC_RollCriticalHit((u8)((u16)n));
        }
        if (func_021B911C((void *)((int)flow->mainModule), 3)) r = 1;
    }
    BTL_EVENT_PopVarFrame(11975);
    return r;
}














#pragma opt_lifetimes reset













/*
 * note 2026-10-05 (wave P8): earlier DIFF (288 vs 292 B) closed by local declaration
 *   order (line, n, v, t, y, z, x, then kind); spill slots follow it. Plain literals
 *   12019 and 12032 are EXACT, so no line local. Also EXACT with --lang c.
 */
int BTL_SERVER_FLOW_CalcMoveDrainRecoil(BtlServerFlow *flow, u8 *a, u16 b, int amount, int *out)
{
    u8 n, v;
    u8 t, y, z, x;
    int kind;
    n = BTL_POKEPARAM_GetPokeId(a);
    v = func_0201BD28((u32)b, 30);
    kind = 0;
    *out = kind;
    if (v) kind = KIND_FIRST;
    else {
        v = func_0201BD28((u32)b, 31);
        if (v) kind = KIND_SECOND;
    }
    if (WAZA_TOOL_GetCategory(b) == 8) return 0;
    BTL_EVENT_PushVarFrame(12019);
    BTL_EVENT_SetVarReadOnly(3, n);
    BTL_EVENT_SetVar(0x35, v);
    BTL_EVENT_SetVar(0x36, 0);
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_SetVarOnce(0x51, 0);
    func_021D70F0(flow, 0x50);
    x = BTL_EVENT_GetVar(0x35);
    y = BTL_EVENT_GetVar(0x41);
    z = BTL_EVENT_GetVar(0x51);
    t = BTL_EVENT_GetVar(0x36);
    BTL_EVENT_PopVarFrame(12032);
    if (z == 0 && y == 1) return 0;
    x += t;
    if (x) {
        if (kind == KIND_SECOND) {
            amount = BTL_CALC_MulPercent(func_021D59B4(a, 14), x);
            if (amount < 1) amount = 1;
        } else if (amount != 0) {
            amount = BTL_CALC_MulPercent(amount, x);
            if (amount < 1) amount = 1;
        }
        *out = z;
        return amount;
    }
    return 0;
}












void BTL_SERVER_FLOW_DispatchPostMoveEvent(BtlServerFlow *flow, u8 *a)
{
    int line = 12077;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    func_021D70F0(flow, 114);
    BTL_EVENT_PopVarFrame(line + 3);
}












void BTL_SERVER_FLOW_DispatchPostMoveKindEvent(BtlServerFlow *flow, u8 *a, u8 k)
{
    int line = 12093;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVar(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVar(3, k);
    func_021D70E4(flow, 115);
    BTL_EVENT_PopVarFrame(line + 4);
}












int BTL_SERVER_FLOW_CalcTypeEffectiveness(BtlServerFlow *flow, u8 *a, u8 *b, u8 *q, int flag)
{
    int r, x;
    int changed = 0;
    if (q[6] == 17) return 3;
    x = BTL_POKEPARAM_GetTypePair(b);
    r = BTL_SERVER_FLOW_CalcSingleTypeAffinity(flow, a, b, q[6], BTLV_CORE_GetHighByte(x));
    if (BTLV_CORE_BytesEqual(x) == 0)
        r = BTL_CALC_CombineTypeAffinity(r, BTL_SERVER_FLOW_CalcSingleTypeAffinity(flow, a, b, q[6], BTLV_CORE_GetLowByte(x)));
    if (r != 0) {
        if (q[6] != 4) return r;
        changed = BTL_SERVER_FLOW_IsPokeGrounded(flow, b, 0);
        if (changed == 0) return r;
        r = 0;
    } else if (q[6] == 4) {
        if (BTL_SERVER_FLOW_IsPokeGrounded(flow, b, 1) == 0) return 3;
    }
    if (r == 0 && flag != 0) {
        if (changed == 0) BTL_SERVER_FLOW_PushNoEffectMessage(flow, b);
        else BTL_SERVER_FLOW_ProcImmunityOverrideNotice(flow, b);
    }
    return r;
}












int BTL_SERVER_FLOW_IsPokeGrounded(BtlServerFlow *flow, u8 *a, int k)
{
    if (BTL_FIELD_GetStaticSlotObject(2) == 0 && BTL_SERVER_FLOW_QueryPokeGroundedEvent(flow, a, k) != 0)
        return 1;
    return 0;
}











int BTL_SERVER_FLOW_QueryPokeGroundedEvent(BtlServerFlow *flow, u8 *a, int f)
{
    int t;
    u8 x, y;
    if (f) {
        t = BTL_POKEPARAM_HasType(a, 2);
    } else {
        t = 0;
    }
    BTL_EVENT_PushVarFrame(12220);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarOnce(0x51, (u8)t);
    BTL_EVENT_SetVarOnce(0x41, (u8)0);
    func_021D70F0(flow, 0x12);
    func_0689C6E4(flow, a);
    x = BTL_EVENT_GetVar(0x51);
    y = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(12228);
    if (y) return 0;
    return x;
}










void BTL_SERVER_FLOW_ProcImmunityOverrideNotice(BtlServerFlow *flow, u8 *q)
{
    u32 v = func_021CC8D8(&flow->lock, 12246);
    BTL_SERVER_FLOW_NotifyImmunityOverrideEvent(flow, q);
    if (func_021C88E4(flow) != 2) BTL_SERVER_FLOW_PushNoEffectMessage(flow, q);
    func_021CC95C(&flow->lock, v, 12253);
}










void BTL_SERVER_FLOW_NotifyImmunityOverrideEvent(BtlServerFlow *flow, u8 *a)
{
    int line = 12265;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    func_021D70F0(flow, 27);
    BTL_EVENT_PopVarFrame(line + 3);
}











int BTL_SERVER_FLOW_CalcSingleTypeAffinity(BtlServerFlow *flow, u8 *a, u8 *b, u32 q, u8 s)
{
    int x, y, r;
    BTL_EVENT_PushVarFrame(12290);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x15, s);
    BTL_EVENT_SetVarReadOnly(0x16, q);
    BTL_EVENT_SetVarOnce(0x4b, 0);
    BTL_EVENT_SetVarOnce(0x4c, 0);
    func_0689C540(flow, b);
    func_021D70F0(flow, 0x3e);
    x = BTL_EVENT_GetVar(0x4b);
    y = BTL_EVENT_GetVar(0x4c);
    BTL_EVENT_PopVarFrame(12303);
    if (y) return 3;
    r = BTL_CALC_GetTypeAffinity(q, s);
    if (r == 0 && x) r = 3;
    return r;
}











void BTL_SERVER_FLOW_PushEffectAnim(BtlServerFlow *flow, int a, int b, int c, int e, u32 f)
{
    int m;
    if (c != 6) {
        m = 2;
    } else {
        m = 1;
        if (b == 6) m = 0;
    }
    if (e) {
        switch (m) {
        case 0: BTL_SERVER_CMD_FillReserved(flow->cmdQueue, f, 0x4c, a); return;
        case 1: BTL_SERVER_CMD_FillReserved(flow->cmdQueue, f, 0x4d, b, a); return;
        case 2: BTL_SERVER_CMD_FillReserved(flow->cmdQueue, f, 0x4e, b, c, a); return;
        }
    } else {
        switch (m) {
        case 0: BTL_SERVER_CMD_Push(flow->cmdQueue, 0x4c, a); return;
        case 1: BTL_SERVER_CMD_Push(flow->cmdQueue, 0x4d, b, a); return;
        case 2: BTL_SERVER_CMD_Push(flow->cmdQueue, 0x4e, b, c, a); return;
        }
    }
}











int BTL_SERVER_FLOW_QueryEffectBlockedEvent(BtlServerFlow *flow, u8 *a, u32 v)
{
    int r;
    BTL_EVENT_PushVarFrame(12399);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x17, v);
    BTL_EVENT_SetVarOnce(0x51, 0);
    func_021D70F0(flow, 0x4f);
    r = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(12405);
    return r;
}











int BTL_SERVER_FLOW_CalcMultiHitCount(BtlServerFlow *flow, u8 *a, u32 x, u8 *out)
{
    u8 id = func_0201BD28(x, 8);
    u32 r;

    out[1] = 0;
    out[5] = 3;
    if (id > 1) {
        r = BTL_CALC_RollHitCount(id);
        BTL_EVENT_PushVarFrame(12432);
        BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
        BTL_EVENT_SetVarReadOnly(0x29, id);
        BTL_EVENT_SetVar(0x2a, r);
        BTL_EVENT_SetVarOnce(0x51, 0);
        BTL_EVENT_SetVarOnce(0x42, 0);
        func_021D70F0(flow, 0x35);
        if (id <= 5 && BTL_EVENT_GetVar(0x51) != 0) {
            out[0] = id;
            out[2] = 0;
        } else {
            out[0] = BTL_EVENT_GetVar(0x2a);
            out[2] = BTL_EVENT_GetVar(0x42);
        }
        out[3] = 1;
        BTL_EVENT_PopVarFrame(12455);
        return 1;
    }
    out[0] = 1;
    out[2] = 0;
    out[3] = 0;
    return 0;
}











u16 BTL_SERVER_FLOW_CalcMovePower(BtlServerFlow *flow, u8 *a, u8 *b, const u8 *s)
{
    u32 t = WAZA_TOOL_GetPower((void *)(((struct Obj07759 *)s)->f0));
    u16 x;
    u32 y;

    BTL_EVENT_PushVarFrame(12487);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x12, ((struct Obj07759 *)s)->f0);
    BTL_EVENT_SetVarReadOnly(0x16, s[6]);
    BTL_EVENT_SetVarReadOnly(0x1a, ((struct Obj07759 *)s)->f8);
    BTL_EVENT_SetVarOnce(0x30, t);
    func_021D70F0(flow, 0x37);
    BTL_EVENT_SetVarRanged(0x31, 0x1000, 0x29, 0x200000);
    func_021D70F0(flow, 0x38);
    x = BTL_EVENT_GetVar(0x30);
    y = BTL_EVENT_GetVar(0x31);
    BTL_EVENT_PopVarFrame(12500);
    return BTL_CALC_MulRatio(x, y);
}











int BTL_SERVER_FLOW_QueryTargetableEvent(BtlServerFlow *flow, u8 *a)
{
    int r;
    BTL_EVENT_PushVarFrame(12521);
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarOnce(0x51, 1);
    func_021D70F0(flow, 0x80);
    r = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(12526);
    return r;
}











/*
 *   no witness outside this caller (7374-r2.log). Verified blocker C copied
 *   from ov093_func_021C1E74.c, whose header records its EXACT compile:
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   extern u32 sub_0201BD28(u16, u32);
 * lever: bind the category call result before initialising k to prevent
 *   its constant assignment moving before the call.
 */
u16 func_021C7374(BtlServerFlow *flow, u8 *a, u8 *b, const u8 *c, int flag)
{
    int k;
    u16 value;
    u8 index;
    int mode = WAZA_TOOL_GetDamageType(*(u16 *)c);
    k = 10;
    if (mode != 2) k = 8;
    BTL_EVENT_PushVarFrame(12542);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVar(0x3b, 0x1f);
    BTL_EVENT_SetVar(0x51, 0);
    func_021D70F0(flow, 0x39);
    index = BTL_EVENT_GetVar(0x3b);
    if (index != 0x1f) a = (u8 *)func_021B9934(flow->pokeCon, index);
    if (BTL_EVENT_GetVar(0x51)) value = func_021D58A8(a, k);
    else if (flag) value = BTL_POKEPARAM_GetStatForCrit(a, k);
    else value = func_021D59B4(a, k);
    BTL_EVENT_SetVarReadOnly(0x12, *(u16 *)c);
    BTL_EVENT_SetVarReadOnly(0x16, c[6]);
    BTL_EVENT_SetVarReadOnly(0x1a, *(u32 *)(c + 8));
    BTL_EVENT_SetVar(0x33, value);
    BTL_EVENT_SetVarRanged(0x35, 1 << 12, 410, 1 << 17);
    func_021D70F0(flow, 0x3b);
    value = BTL_EVENT_GetVar(0x33);
    value = BTL_CALC_MulRatio(value, BTL_EVENT_GetVar(0x35));
    BTL_EVENT_PopVarFrame(12579);
    return value;
}











/*
 *   no witness outside this caller (7474-r1.log). Verified blocker C copied
 *   from ov093_func_021C1E74.c, whose header records its EXACT compile:
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   extern u32 sub_0201BD28(u16, u32);
 */
u16 func_021C7474(BtlServerFlow *flow, u8 *a, u8 *b, const u8 *c, u32 flag)
{
    int k;
    u32 field;
    u16 value;
    u8 other;
    int scale;
    int mode = WAZA_TOOL_GetDamageType(*(u16 *)c);
    k = 11;
    if (mode != 2) k = 9;
    field = *(u32 *)(c + 8);
    BTL_EVENT_PushVarFrame(12595);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x3c, k);
    BTL_EVENT_SetVar(0x3d, 0);
    BTL_EVENT_SetVarOnce(0x51, 0);
    func_021D70F0(flow, 0x3a);
    if (BTL_EVENT_GetVar(0x3d) & 1) {
        if (k == 9) k = 11;
        else k = 9;
        if (k == 9) field = 1;
        else field = 2;
    }
    other = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(12610);
    if (other) value = func_021D58A8(b, k);
    else if (flag) value = BTL_POKEPARAM_GetStatForCrit(b, k);
    else value = func_021D59B4(b, k);
    if (BTL_SERVER_FLOW_GetEffectiveWeather(flow) == 4 && BTL_POKEPARAM_HasType(b, 5) && k == 11)
        value = BTL_CALC_MulRatio(value, 6 << 10);
    BTL_EVENT_PushVarFrame(12631);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x12, *(u16 *)c);
    BTL_EVENT_SetVarReadOnly(0x16, c[6]);
    BTL_EVENT_SetVarReadOnly(0x1a, field);
    BTL_EVENT_SetVar(0x34, value);
    BTL_EVENT_SetVarRanged(0x35, 4 << 10, 410, 4 << 15);
    func_021D70F0(flow, 0x3c);
    value = BTL_EVENT_GetVar(0x34);
    scale = BTL_EVENT_GetVar(0x35);
    BTL_EVENT_PopVarFrame(12642);
    return BTL_CALC_MulRatio(value, scale);
}











int func_021C75EC(BtlServerFlow *flow, u8 *a, int k)
{
    int f = BTL_POKEPARAM_HasType(a, k);
    u32 v = 0x1000;
    int x;
    int r;

    BTL_EVENT_PushVarFrame(12664);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarOnce(0x51, f);
    func_021D70F0(flow, 0x40);
    x = BTL_EVENT_GetVar(0x51);
    if (x != 0)
        v = 0x1800;
    BTL_EVENT_SetVarReadOnly(0x44, x);
    BTL_EVENT_SetVar(0x35, v);
    func_021D70F0(flow, 0x41);
    r = BTL_EVENT_GetVar(0x35);
    BTL_EVENT_PopVarFrame(12681);
    return r;
}











int func_021C7664(BtlServerFlow *flow, u32 x, u8 *a)
{
    int c41;
    int c45;
    int c26;
    int s;

    s = func_0201BD28(x, 10);
    BTL_EVENT_PushVarFrame(12701);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x25, s);
    BTL_EVENT_SetVarOnce(0x45, 0);
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_SetVar(0x26, 0);
    func_021D70F0(flow, 0x6c);
    c41 = BTL_EVENT_GetVar(0x41);
    c45 = BTL_EVENT_GetVar(0x45);
    c26 = BTL_EVENT_GetVar(0x26);
    BTL_EVENT_PopVarFrame(12712);
    if (c41 != 0 && s != 0)
        return 0;
    if (s == 0)
        s = s + c26;
    if (c45 != 0)
        s = s << 1;
    return s;
}











int func_021C76F4(BtlServerFlow *flow, u8 *a, u32 k)
{
    int res;
    int c26;
    int c41;

    BTL_EVENT_PushVarFrame(12745);
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVar(0x26, k);
    BTL_EVENT_SetVarOnce(0x41, 0);
    res = 0;
    func_021D70F0(flow, 0x6d);
    c26 = BTL_EVENT_GetVar(0x26);
    c41 = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(12753);
    if (c41 != 0)
        return 0;
    if (c26 != 0) {
        if (func_021C82B8(flow, res) != 0)
            return 1;
        if (BTL_CALC_Random(100) < (u8)c26)
            res = 1;
        return res;
    }
    return res;
}










void func_021C7780(BtlServerFlow *flow, u8 *a)
{
    int line = 12778;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVar(2, BTL_POKEPARAM_GetPokeId(a));
    func_021D70F0(flow, 110);
    BTL_EVENT_PopVarFrame(line + 3);
}











int func_021C77B0(BtlServerFlow *flow, u8 *a, u32 b, u32 c, u32 d, u32 e)
{
    int r;
    int res;

    BTL_EVENT_PushVarFrame(12801);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(3, c);
    BTL_EVENT_SetVarReadOnly(0x1f, b);
    BTL_EVENT_SetVarReadOnly(0x20, d);
    BTL_EVENT_SetVarReadOnly(0x19, e);
    res = 0;
    BTL_EVENT_SetVarOnce(0x41, 0);
    func_021D70F0(flow, 0x5b);
    r = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(12810);
    if (r == 0)
        res = 1;
    return res;
}










void func_021C7820(BtlServerFlow *flow, u8 *a, u32 k)
{
    int line = 12826;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(25, k);
    func_021D70F0(flow, 92);
    BTL_EVENT_PopVarFrame(line + 4);
}











void func_021C785C(BtlServerFlow *flow, u32 a, u8 *b, u32 c, u32 d)
{
    BTL_EVENT_PushVarFrame(12846);
    BTL_EVENT_SetVarReadOnly(3, a);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x1f, c);
    BTL_EVENT_SetVarReadOnly(0x20, d);
    func_021D70F0(flow, 0x5d);
    BTL_EVENT_PopVarFrame(12852);
}











void func_021C78A8(BtlServerFlow *flow, u8 *a, u32 b, u32 c, u32 d)
{
    BTL_EVENT_PushVarFrame(12868);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, b);
    BTL_EVENT_SetVarReadOnly(0x1f, c);
    BTL_EVENT_SetVarReadOnly(0x20, d);
    func_021D70F0(flow, 0x5e);
    BTL_EVENT_PopVarFrame(12874);
}











u16 func_021C78F4(BtlServerFlow *flow, u8 *a, u8 *b, u32 s)
{
    int k;
    u32 y;
    u16 r;

    if (b != 0)
        k = BTL_POKEPARAM_GetPokeId(b);
    else
        k = 0x1f;
    BTL_EVENT_PushVarFrame(12894);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, (u8)k);
    BTL_EVENT_SetVarRanged(0x35, 0x1000, 410, 0x20000);
    BTL_EVENT_SetVar(0x20, s);
    func_021D70F0(flow, 0x8c);
    s = (u16)BTL_EVENT_GetVar(0x20);
    y = BTL_EVENT_GetVar(0x35);
    if (s != 0)
        s = (u16)BTL_CALC_MulRatioMin1(s, y);
    BTL_EVENT_OverwriteVar(0x20, s);
    func_021D70F0(flow, 0x8d);
    r = BTL_EVENT_GetVar(0x20);
    BTL_EVENT_PopVarFrame(12911);
    return r;
}











void func_021C7998(BtlServerFlow *flow, u32 x)
{
    BTL_EVENT_PushVarFrame(12930);
    BTL_EVENT_SetVarReadOnly(0x39, x);
    BTL_EVENT_SetVarOnce(0x41, 0);
    func_021D70F0(flow, 0x7d);
    if (BTL_EVENT_GetVar(0x41) == 0)
        func_021D70F0(flow, 0x7e);
    BTL_EVENT_PopVarFrame(12938);
}











u32 func_021C79E0(BtlServerFlow *flow, u32 x, u8 *a)
{
    u32 s = func_0201BD28(x, 0x1a);
    int c;
    u32 m;
    u32 r;

    BTL_EVENT_PushVarFrame(12956);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVar(0x35, 0);
    func_021D70F0(flow, 0x8f);
    c = BTL_EVENT_GetVar(0x35);
    BTL_EVENT_PopVarFrame(12961);
    m = func_021D59B4(a, 0xe);
    if (c != 0)
        r = BTL_CALC_MulRatio(m, c);
    else
        r = BTL_CALC_MulPercent(m, s);
    if (r == 0)
        return 1;
    if (r > m)
        r = m;
    return r;
}











int func_021C7A54(BtlServerFlow *flow, u8 *a, u32 c)
{
    int r;
    BTL_EVENT_PushVarFrame(12996);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x2d, c);
    BTL_EVENT_SetVarOnce(0x41, 0);
    func_021D70F0(flow, 0x9a);
    r = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(13002);
    return r;
}










void func_021C7AA0(BtlServerFlow *flow, u8 *a)
{
    int line = 13017;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    func_021D70F0(flow, 155);
    BTL_EVENT_PopVarFrame(line + 3);
}










void func_021C7AD0(BtlServerFlow *flow, u8 *a, u32 k)
{
    int line = 13033;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(45, k);
    func_021D70F0(flow, 156);
    BTL_EVENT_PopVarFrame(line + 4);
}










void func_021C7B0C(BtlServerFlow *flow, u8 *a)
{
    int line = 13050;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    func_021D70F0(flow, 157);
    BTL_EVENT_PopVarFrame(line + 3);
}











void func_021C7B3C(BtlServerFlow *flow, u32 a, u16 b, u16 c)
{
    BTL_EVENT_PushVarFrame(13068);
    BTL_EVENT_SetVarReadOnly(2, a);
    BTL_EVENT_SetVarReadOnly(0xf, b);
    BTL_EVENT_SetVarReadOnly(0x10, c);
    func_021D70F0(flow, 0x89);
    BTL_EVENT_PopVarFrame(13073);
}










void func_021C7B7C(BtlServerFlow *flow, unsigned int i) { BTL_EVENT_PushVarFrame(13085); BTL_EVENT_SetVarReadOnly(2,i); func_021D70F0(flow,138); BTL_EVENT_PopVarFrame(13088); }











void func_021C7BA8(BtlServerFlow *flow, u8 a, u32 b, u32 c, u32 *out)
{
    BTL_EVENT_PushVarFrame(13102);
    BTL_EVENT_SetVarReadOnly(2, a);
    BTL_EVENT_SetVarReadOnly(0x52, c);
    BTL_EVENT_SetVarReadOnly(0x53, b);
    BTL_EVENT_SetVar(0x1e, *out);
    func_021D70F0(flow, 0x9f);
    *out = BTL_EVENT_GetVar(0x1e);
    BTL_EVENT_PopVarFrame(13109);
}










void func_021C7BF8(BtlServerFlow *flow) { BTL_EVENT_PushVarFrame(13123); func_021D70F0(flow, 121); BTL_EVENT_PopVarFrame(13125); }











void func_021C7C18(void *p)
{
    func_02082BCC(p, 0, (u32)0xc);
}











void func_021C7C24(u16 *p, int unused, u8 *b, u8 *c, int e)
{
    u8 x = BTL_POKEPARAM_GetPokeId(b);
    u8 y = BTL_POKEPARAM_GetPokeId(c);
    int mx = func_021B8DDC(x);
    int my = func_021B8DDC(y);
    u8 same = (func_021B9A24(x, y) == 0);
    u16 *q = 0;
    if (mx == 0) {
        if (same) {
            if (e == 0) {
                q = p;
            } else if (e > 3) {
                q = p + 1;
            } else if (e < 3) {
                q = p + 2;
            }
        }
    } else if (my == 0) {
        if (same) {
            if (e == 0) {
                q = p + 3;
            } else if (e > 3) {
                q = p + 4;
            } else if (e < 3) {
                q = p + 5;
            }
        }
    }
    if (q != 0) {
        if (*q < 9999) {
            *q += 1;
        }
    }
}











/*
 * ldrh at #0x1f7c (pool constant)
 */
u16 func_021C7CBC(u8 *p)
{
    return ((struct Obj18319 *)p)->f1F7C;
}











/*
 * ldrh at #0x1f7e (pool constant)
 */
u16 func_021C7CC8(u8 *p)
{
    return ((struct Obj18320 *)p)->f1F7E;
}










/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x7e; lsls r1, r1, #6; ldrh r0, [r0, r1]; bx lr.
 */
u16 func_021C7CD4(struct Q6 *p) { return p->v; }











/*
 * ldrh at #0x1f82 (pool constant)
 */
u16 func_021C7CDC(u8 *p)
{
    return ((struct Obj18322 *)p)->f1F82;
}











u16 func_021C7CE8(u8 *p)
{
    return ((struct Obj18323 *)p)->f1F86;
}










/*
 * Forwarding tail call: p[2] and the caller's i go to func_021B9934, whose
 * listing reads both (lsls r1, r1, #2), and its result is returned.
 */
void *func_021C7CF4(int *p, int i)
{
    return func_021B9934((char *)p[2], i);
}









int func_021C7D00(BtlServerFlow *flow, int b) { int i = func_0689D5C8(flow->posPoke, b); if (!BTL_MAIN_CheckFrontPos((unsigned int **)flow->mainModule, i)) i = 6; return i; }
















/*
 * witness: owned verified ov095 leaf 0x0689D5F4 resolves the tail pool.
 * ABI: full-word r1 index is preserved; ov095 body reads r0/r1 and returns
 * the byte in r0. Tail pool target is 0x0689D5F4 + 1. This ov095 leaf
 * was authorized by root separately; no domain assumptions.
 */
int func_021C7D34(char *p, int i) { return func_0689D5F4((u8 *)(p + 0x1ab8), i); }
















/*
 * witness: owned verified ov095 leaf 0x0689D5FC resolves the tail pool.
 * ABI: full-word r1 index is preserved; ov095 body reads r0/r1 and returns
 * the byte in r0. Tail pool target is 0x0689D5FC + 1. This ov095 leaf
 * was authorized by root separately; no domain assumptions.
 */
int func_021C7D44(char *p, u8 i) { return func_0689D5FC((u8 *)(p + 0x1ab8), i); }

















u8 func_021C7D54(u8 *p, u8 *k, u8 *out)
{
    u32 it;
    u8 *x;
    u8 n = 0;
    BTL_SERVER_FLOW_InitFieldPokeIter((u8 *)&it, (u8 **)p);
    while (BTL_SERVER_FLOW_NextFieldPokeIter((u8 *)&it, (u8 **)p, &x)) {
        if (func_021B9A24((u32)k, BTL_POKEPARAM_GetPokeId(x)) == 0) {
            out[n++] = BTL_POKEPARAM_GetPokeId(x);
        }
    }
    return n;
}

















int func_021C7DAC(BtlServerFlow *flow, int a, int b, u16 c)
{
    int buf[5];
    int r;
    u8 *x = func_021B9934(flow->pokeCon, a);
    u8 *y = func_021B9934(flow->pokeCon, b);
    flow->actionCounter += 1;
    if (BTL_POKEPARAM_IsIllusionActive((struct R4 *)y)) {
        y = func_021B937C(flow->mainModule, flow->pokeCon, y);
    }
    BTL_SERVER_FLOW_GetMoveParam(flow, c, x, (struct Out64B4 *)buf);
    r = BTL_SERVER_FLOW_CalcTypeEffectiveness(flow, x, y, (u8 *)buf, 0);
    flow->actionCounter -= 1;
    return r;
}

















u16 func_021C7E14(BtlServerFlow *flow, u8 a, u8 b, u16 c, int e0, int e1)
{
    int buf[5];
    u16 o;
    u8 *x;
    u8 *y;
    int z;
    if (c != 0 && WAZA_TOOL_IsDamaging((void *)c) != 0) {
        x = func_021B9934(flow->pokeCon, a);
        y = func_021B9934(flow->pokeCon, b);
        flow->actionCounter += 1;
        if (BTL_POKEPARAM_IsIllusionActive((struct R4 *)y)) {
            y = func_021B937C(flow->mainModule, flow->pokeCon, y);
        }
        if (e0) {
            z = func_021C7DAC(flow, a, b, c);
        } else {
            z = 3;
        }
        BTL_SERVER_FLOW_GetMoveParam(flow, c, x, (struct Out64B4 *)buf);
        BTL_SERVER_FLOW_CalcMoveDamage(flow, x, y, (u8 *)buf, z, 0x1000, 0, e1 == 0, &o);
        flow->actionCounter -= 1;
        return o;
    }
    return 0;
}

















/* 021C7EC4  nonzero test of the pooled offset 0x774 */
/*
 * 8 instructions, 16 bytes: ldr r1, pool_021C7ED4; ldr r0, [r0, r1]; cmp r0, #0; beq loc_021C7ED0; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021C7EC4(u8 *p)
{
    return (((struct Obj18325 *)p)->f774 != 0);
}
















int func_021C7ED8(u8 *p, int i) { return func_021B997C(*(u8 * *)&((struct Obj21110 *)p)->f4, func_021B8DDC(i)); }
















int func_021C7EEC(BtlServerFlow *flow, int i) { return BTL_SERVER_GetClientChecked((u8 *)flow->server, func_021B8DDC(i))[9]; }
















int func_021C7F04(BtlServerFlow *flow, int i) { if (BTL_MAIN_GetRule(flow->mainModule) != 3) return func_021C7EEC(flow, i); return 3; }
















int func_021C7F24(BtlServerFlow *flow, int i) { char *q = func_021C7FCC(flow, i); if (func_021B9BC4((u8 *)q, func_021C7F04(flow, i))) return 1; return 0; }















int func_021C7F4C(struct Flag *p) { if (p->set) return 0; p->set = 1; return 1; }
















/*
 * Named by the parked ov093 file BTL_CALC_IntimidateOnEnter.c.  Builds a candidate list in
 * a local buffer and copies the accepted entries to `out`.  EXACT*: the
 * completed extent runs into an unlabelled follower.  Three levers: `n` must
 * be volatile (it is spilled/reloaded around the loop calls), the boolean is
 * materialised through a `?:` rather than a bare `&&`, and the `u8` locals
 * are declared `j` before `i` with both initialised in the for-clause.
 */
u8 func_021C7F68(BtlServerFlow *flow, int b, u8 *out)
{
    u8 buf[8];
    volatile u32 n = (u32)BTL_MAIN_DecodeMessageCode((struct Unk021B8CB0 **)flow->mainModule, b, buf);
    u8 j;
    u8 i;

    for (i = 0, j = 0; i < n; i++) {
        u8 *x = func_021B98A4((char *const *)flow->pokeCon, buf[i]);
        int ok = (x != 0) ? (BTL_POKEPARAM_IsFainted(x) == 0) : 0;

        if (ok)
            out[j++] = BTL_POKEPARAM_GetPokeId(x);
    }
    return j;
}















char *func_021C7FCC(BtlServerFlow *flow, int i) { return func_021B9AF8((char *)flow->pokeCon, func_021B8DDC(i)); }















/*
 * extent: two bytes alignment padding follow.
 * ABI: original forwards full-word B8DDC/B9010 results without narrowing;
 * widen B9010 and B8B9C input declarations relative to narrow legacy sources.
 */
char *func_021C7FE0(BtlServerFlow *flow, int v) { u8 k; k=func_021B9010((u8 *)flow->mainModule, func_021B8DDC(v)); if(BTL_MAIN_IsClientUsed((u8 *)flow->mainModule,k)) return func_021B9AF8((char *)flow->pokeCon,k); return 0; }















int func_021C8010(BtlServerFlow *flow, unsigned int v) { return func_021B8D8C(flow->mainModule, flow->pokeCon, v); }















/*
 * extent: two bytes alignment padding follow.
 */
u8 func_021C8020(BtlServerFlow *flow, u8 v) { return BTL_POKEPARAM_GetPokeId((u8 *)func_021B98AC((char *const *)flow->pokeCon, v)); }















int func_021C8030(BtlServerFlow *flow, int v, u16 k) { return BTL_CALC_DecideMoveTarget(flow->mainModule, (int)flow->pokeCon, (int)func_021B9934((char *)flow->pokeCon,v), k); }
















/*
 * Levers: the record array read as p->e[i] of the twins' S (BTL_SERVER_FLOW_FindActionByPokeId,
 * BTL_SERVER_FLOW_FindPendingActionByMove), which keeps i*16 live and recomputes p+i*16 for the second
 * load; the second word as a union of u32 and a 4-bit bitfield read in place
 * (a union local takes a stack slot); key as a u8 parameter, which puts its
 * spill ahead of the count load (int/u32 key leave it after).
 */
int func_021C804C(S_td *p, u8 key, u32 *out)
{
    u32 i;
    for (i = 0; i < p->n; i++) {
        if (key == BTL_POKEPARAM_GetPokeId(p->e[i].a)) {
            if (p->e[i].b.w.lo != 6) {
                *out = p->e[i].b.u;
                return 1;
            }
        }
    }
    return 0;
}
















int func_021C80AC(u8 *p, int key)
{
    u32 i;
    u32 total;
    u32 flagged;
    flagged = 0;
    total = 0;
    for (i = 0; i < p[0x782]; i++) {
        u8 *e = p + i * 16;
        if (key != BTL_POKEPARAM_GetPokeId(*(u8 * *)&((struct Obj13340 *)e)->f7E0)) {
            total++;
            if (e[0x7ed] != 0) {
                flagged++;
            }
        }
    }
    return total == flagged;
}
















/*
 * ldrh at #0x1f74 (pool constant)
 */
u16 func_021C8114(u8 *p)
{
    return ((struct Obj18333 *)p)->f1F74;
}
















/*
 * pointer add #0x1fec
 */
u8 *func_021C8120(u8 *p, int b)
{
    return p + 0x1fec;
}
















/* 021C812C  adds r0,#0x1c */
u8 *func_021C812C(u8 *p) { return p + 0x1c; }
















/* 021C8130  movs r1,#0x3e; lsls r1,#4; adds r0,r0,r1 */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x3e; lsls r1, r1, #4; adds r0, r0, r1; bx lr.
 */
u8 *func_021C8130(u8 *p) { return p + 0x3e0; }















/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0, #0x10]; lsls r0, r0, #0x10; lsrs r0, r0, #0x10; bx lr.
 */
u16 func_021C8138(struct Q7 *p) { return (u16)p->v; }















unsigned char func_021C8140(char *p, int i)
{
    return *(unsigned char *)(p + i + 0x7d9);
}














/*
 * ABI: ov095 D588 forwards the same table pointer and key to D5C8;
 * original keeps r1 live and has no narrowing, so retain a full-word key.
 */
int func_021C814C(u8 *p, u8 v) { return func_0689D588(p+0x1ab8,v); }















/*
 * Two tail thunks forwarding p->field4 to distinct callees.
 */
int func_021C815C(int *p)
{
    return BTL_MAIN_GetRule((void **)(((struct Obj26329 *)p)->f4));
}















void func_021C8168(int *p)
{
    BTL_MAIN_GetCompetitor((void ***)(((struct Obj26330 *)p)->f4));
}















int func_021C8174(int *p)
{
    return ((struct Obj18336 *)((char *)BTL_MAIN_GetFieldSituation((char **)(((struct Obj18335 *)p)->f4))))->f4;
}















int func_021C8180(int *p)
{
    return BTL_MAIN_GetActivePosPerSide((unsigned int **)(((struct Obj18337 *)p)->f4));
}














int func_021C818C(u8 *p, int v) { unsigned int species; u16 i; species=BTL_POKEPARAM_GetSpecies((struct QF *)func_021B9934(*(char * *)&((struct Obj13341 *)p)->f8,v)); for(i=0;i<7;i++) { if(SHINKA_CHECK_GetRowParam(((struct Obj13341 *)p)->f4A4,species,0,i)) return 1; } return 0; }















u16 func_021C81C8(BtlServerFlow *flow, u8 *x, int flag)
{
    return BTL_SERVER_FLOW_CalcPokeSpeed(flow, x, flag);
}















u16 func_021C81D0(BtlServerFlow *flow, u8 *a, u32 y)
{
    u32 it;
    u8 *x;
    u16 n;
    u32 base = func_021C81C8(flow, a, y);
    int k = BTL_POKEPARAM_GetPokeId(a);
    n = 0;
    BTL_SERVER_FLOW_InitFieldPokeIter((u8 *)&it, (u8 **)flow);
    while (BTL_SERVER_FLOW_NextFieldPokeIter((u8 *)&it, (u8 **)flow, &x)) {
        if (k != BTL_POKEPARAM_GetPokeId(x)) {
            if (func_021C81C8(flow, x, y) > base) {
                n++;
            }
        }
    }
    return n;
}














/*
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */
int func_021C8234(BtlServerFlow *flow, int i) { return BTL_SERVER_FLOW_IsPokeGrounded(flow, func_021B9934(flow->pokeCon, i), 1); }













int func_021C824C(BtlServerFlow *flow, int v) { void *m; m=func_021B9934((char *)flow->pokeCon,v); if(func_021D59B4(m,17)==103) return 0; if(BTL_POKEPARAM_HasSick(m,19)) return 0; if(BTL_FIELD_GetStaticSlotObject(7)==0) return 1; return 0; }














/*
 * tail-call thunk to BTL_SERVER_FLOW_GetEffectiveWeather
 */
int func_021C8288(BtlServerFlow *flow)
{
    return BTL_SERVER_FLOW_GetEffectiveWeather(flow);
}













int func_021C8290(BtlServerFlow *flow, int a, int b, void *item) { u8 *x; x=func_021B9934(flow->pokeCon,a); return BTL_SERVER_FLOW_CheckAllyMoveAutoHit(flow,x,func_021B9934(flow->pokeCon,b),item); }













int func_021C82B8(BtlServerFlow *flow, int z)
{
    return func_021B911C(flow->mainModule, z);
}













int func_021C82C4(int a, int b, int c)
{
    (void)a;
    return func_06898CF4(b, c);
}










/*
 * extent: two bytes alignment padding precede non-C veneer 021C82E4.
 */
int func_021C82D0(int unused, unsigned int v, int k) { return func_06898CE0(func_021B9AE0(v),k); }













/*
 * Tail-call stub: mov r0, r2; bx to the pool word 0x068982AD (a thumb
 * target in the 0x06xxxxxx window, not an image address).
 */
int func_021C82F4(int a, int b, int c)
{
    return func_068982AC(c);
}














u32 func_021C8300(int *p, u8 k)
{
    return func_021B9010((u8 *)p[1], k);
}













/*
 * lever: unsigned-char bitfield gives the byte load and 31-bit shift pair.
 */
unsigned int func_021C830C(u8 *p) { return ((struct Bits *)(p+0x78a))->a; }













/*
 * lever: add the byte index to the base before applying the constant offset.
 */
void func_021C831C(u8 *p, int v) { unsigned int n; n=p[0x788]; if(n<6) { p[0x788]=n+1; (p+n)[0x78b]=v; } }













/*
 * extent: Two bytes of alignment padding follow the 14-byte function.
 */
int func_021C8338(BtlServerFlow *flow, int i)
{
    return BTL_POKEPARAM_IsSemiInvulnerable((struct UtilWork *)func_021B9934(flow->pokeCon, i));
}













/*
 * extent: Two bytes of alignment padding follow the 42-byte function.
 */
int func_021C8348(BtlServerFlow *flow, int i)
{
    u8 n = func_021D69AC(func_021B9934(flow->pokeCon, i), 4);
    if (n != 0) {
        n--;
        if (n < 24) goto done;
    }
    n = 31;
done:
    if (n != 31) return 1;
    return 0;
}













int func_021C8374(BtlServerFlow *flow, int i)
{
    if (func_021C8348(flow, i)) return 1;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)func_021B9934(flow->pokeCon, i), 33)) return 1;
    return 0;
}













u32 func_021C83A0(u8 *p, int i)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj21119 *)p)->f8, i);
    int b = BTL_SERVER_FLOW_QueryPokeMultiplierEvent(p, a);
    u32 r = BTL_CALC_MulRatio(BTL_POKEPARAM_GetWeight(a), b);
    if (r < 1) r = 1;
    return r;
}













/*
 * tail-call thunk to BTL_SERVER_FLOW_NextSerialNumber
 */
u32 func_021C83CC(BtlServerFlow *flow)
{
    return BTL_SERVER_FLOW_NextSerialNumber(flow);
}













/*
 * tail-call thunk to BTL_SERVER_FLOW_CheckShowdown
 */
int func_021C83D4(BtlServerFlow *flow)
{
    return BTL_SERVER_FLOW_CheckShowdown(flow);
}













void func_021C83DC(char *p, int x)
{
    *(char *)(((struct Obj21120 *)p)->f4A8 + 4) = x;
}












/*
 * evidence: Original loads r1 for BTL_SERVER_AddMainCounter even though its body ignores it.
 */
int func_021C83E8(unsigned char *p, int i, int b)
{
    if ((unsigned int)BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj13342 *)p)->f4) <= 1) {
        BTL_SERVER_AddMainCounter(*(int * *)&((struct Obj13342 *)p)->f0, i);
        return 1;
    }
    return 0;
}











void func_021C8408(u8 *p, int a)
{
    unsigned int t = (unsigned int)BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj09974 *)p)->f4);
    int k = func_021B8DDC(a);
    if (t <= 1 && k == func_021B8FF4(*(u8 * *)&((struct Obj09974 *)p)->f4)) BTL_SERVER_FinishMainCounter(*(int * *)&((struct Obj09974 *)p)->f0);
}











void func_021C8434(u8 *p, int a, int b)
{
    int c = func_0689D5C8(p + 0x1ab8, b);
    BTL_SERVER_FLOW_PushMoveQueue(*(u8 * *)&((struct Obj21121 *)p)->f4B0, a, b, c);
}










/*
 * extent: Two bytes of alignment padding follow the 38-byte function.
 */
int func_021C846C(BtlServerFlow *flow, int a, int b, int *out)
{
    u8 *x = func_021B9934(flow->pokeCon, a);
    u8 *y = func_021B9934(flow->pokeCon, b);
    return BTL_SERVER_FLOW_ProcMoveReflectOrAbsorb(flow, x, y, out);
}











/*
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */
void func_021C8494(BtlServerFlow *flow, int i) { BTL_SERVER_FLOW_ReleaseBindingTarget(flow, func_021B9934(flow->pokeCon, i), 1); }










int func_021C84AC(BtlServerFlow *flow, u8 *a, u8 *out)
{
    int r;
    ((struct Flags_021C7D34 *)&flow->stateFlags)->flag = 0;
    r = BTL_SERVER_FLOW_ProcHeldItemActivate(flow, a);
    *out = ((struct Flags_021C7D34 *)&flow->stateFlags)->flag;
    return r;
}











/*
 * tail-call thunk to BTL_SERVER_FLOW_DispatchPokeEntryEventToType4
 */
void func_021C84D0(BtlServerFlow *flow, u8 *a)
{
    BTL_SERVER_FLOW_DispatchPokeEntryEventToType4(flow, a);
}











/*
 * tail-call thunk to func_021CC668
 */
int func_021C84D8(u8 *p)
{
    return func_021CC668(p);
}











/*
 * Was MATCH (pool word to the unlabelled 0x021C84F4 had no witness); the
 * matched func_021C84F4 now resolves it, verified EXACT.
 */
void func_021C84E0(BtlServerFlow *flow, unsigned int v)
{
    func_021C84F4(flow, v);
}











void func_021C84E8(BtlServerFlow *flow)
{
    flow->seenCount = 0;
}










/*
 * Unlabelled Thumb leaf in a .word run.  Extent 0x021C84F4..0x021C8534
 * (64 bytes, including a 2-byte pool-alignment nop and two pool words).
 * Searches the u8 set at p+0x791 for v; if absent and i < 0x18, appends v
 * and bumps the count at p+0x785.
 */
void func_021C84F4(BtlServerFlow *flow, unsigned int v)
{
    unsigned int i;
    unsigned int n = flow->seenCount;

    for (i = 0; i < n; i++) {
        if (v == flow->seenValues[i])
            return;
    }
    if (i < 0x18) {
        flow->seenValues[i] = v;
        flow->seenCount = flow->seenCount + 1;
    }
}











int func_021C8534(BtlServerFlow *flow)
{
    u32 i;
    u8 buf[4];
    for (i = 0; i < flow->seenCount; i++) {
        if (func_0689D558(flow->posPoke, func_021B8DDC(flow->seenValues[i]), buf)) {
            return 1;
        }
    }
    return 0;
}








void func_021C8588(BtlServerFlow *flow)
{
    *(int *)&flow->frameDepth = 0;
    func_021C85D4(flow, 0, 1);
}








void func_021C859C(BtlServerFlow *flow)
{
    if (flow->frameDepth < 6) {
        ++flow->frameDepth;
        func_021C85D4(flow, flow->frameDepth, 1);
    }
}








void func_021C85B8(BtlServerFlow *flow)
{
    if (flow->frameDepth != 0) {
        --flow->frameDepth;
        func_021C85D4(flow, flow->frameDepth, 0);
    }
}









void func_021C85D4(BtlServerFlow *flow, int index, int clear)
{
    BtlServerFlowFrame *frame = &flow->frames[index];
    flow->curTargetSet = frame->targetSet;
    flow->curTargetSetWork = frame->targetSetWork;
    flow->curHitSetA = frame->hitSetA;
    flow->curHitSetB = frame->hitSetB;
    flow->curDamageSet = frame->damageSet;
    flow->curEffectSet = frame->effectSet;
    flow->curQueuedSet = frame->queuedSet;
    flow->curTurnState = frame->turnState;
    flow->curMoveParam = frame->moveParam;
    flow->curMoveParamBackup = frame->moveParamBackup;
    flow->curHitFlags = frame->hitFlags;
    flow->curInterruptQueue = frame->interruptQueue;
    flow->curDeferredQueue = frame->deferredQueue;
    flow->curHitRecordA = frame->hitRecordA;
    flow->curHitRecordB = frame->hitRecordB;
    flow->reserveSlot = frame->reserveSlot;
    ((struct Flags_021C8588 *)&flow->stateFlags)->a = frame->flagsA;
    ((struct Flags_021C8588 *)&flow->stateFlags)->b = frame->flagsB;
    if (clear) {
        func_0689CB3C(frame->targetSet);
        func_0689CB3C(flow->curTargetSetWork);
        func_0689CB3C(flow->curHitSetA);
        func_0689CB3C(flow->curHitSetB);
        func_0689CB3C(flow->curDamageSet);
        func_0689CB3C(flow->curEffectSet);
        func_0689CB3C(flow->curQueuedSet);
        BTL_SERVER_FLOW_InitTurnState((struct Unk021BD1E0 * )flow->curTurnState);
        func_02082BCC(flow->curMoveParam, 0, 0x14);
        func_02082BCC(flow->curMoveParamBackup, 0, 0x14);
        func_02082BCC(flow->curHitFlags, 0, 6);
        func_02082BCC(flow->curInterruptQueue, 0, 0x13);
        func_02082BCC(flow->curDeferredQueue, 0, 0x13);
        func_02082BCC(flow->curHitRecordA, 0, 0x1c);
        func_02082BCC(flow->curHitRecordB, 0, 0x1c);
        flow->reserveSlot = 6;
        ((struct Flags_021C8588 *)&flow->stateFlags)->a = 0;
        ((struct Flags_021C8588 *)&flow->stateFlags)->b = 0;
    }
}









void func_021C8810(u8 *p)
{
    func_02082BCC(p, 0, 0x24);
    ((struct Packed021C8810 *)(p + 2))->low = 0;
}










/* 021C8828  u8 of the low halfword, != 0 */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldrh r0, [r0, #2]; lsls r0, r0, #0x18; lsrs r0, r0, #0x18; beq loc_021C8834; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021C8828(u8 *p)
{
    return ((u8)((struct Obj18339 *)p)->f2 != 0);
}










/*
 * Named by the parked ov093 files (BTL_HANDLER_ITEM_DestinyKnot_Infatuate / BTL_HANDLER_ITEM_RockyHelmetDamageReaction /
 * func_021E7388).  Low byte of the +2 halfword <- (u8)a; +0 halfword <- b;
 * then bits 8..14 of the +2 halfword are cleared.  `(u8)(u16)a` and the
 * `(int)` cast before `~0x7F00` are both load-bearing: the first gives the
 * double narrowing, the second keeps the mask sign-extended (0xFFFF80FF) so
 * the pooled word matches.
 */
void func_021C8838(void *p, int a, int b)
{
    u16 *h = (u16 *)((u8 *)p + 2);
    u8 av = (u8)(u16)a;

    *h = (*h & ~0xff) | av;
    ((struct Obj21124 *)p)->f0 = (u16)b;
    *h = (u16)((int)*h & ~0x7F00);
}










/*
 * Named by the parked ov093 files (BTL_HANDLER_ITEM_DestinyKnot_Infatuate / BTL_HANDLER_ITEM_RockyHelmetDamageReaction /
 * func_021E7388).  Appends `val` to the record at p: the count in bits 8..14
 * of the +2 halfword (max 7 entries) is incremented and `val` stored at
 * p + 4 + idx*4.  The 7-bit unsigned bitfield is what makes the count
 * unsigned (`bhs`, not `bge`) and produces the lsl/lsr extraction pair.
 */
void func_021C8860(struct S_p12 *p, u32 val)
{
    unsigned int idx = p->n;

    if (idx >= 8)
        return;
    p->n = idx + 1;
    p->arr[idx] = val;
}









/*
 * extent: two-byte alignment padding at 0x021C88A2.
 */
void func_021C888C(u8 *p, u32 v)
{
    if (((struct Packed021C888C *)(p + 2))->index < 8) {
        ((struct Obj21125 *)p)->f20 = v;
        ((struct Packed021C888C *)(p + 2))->active = 1;
    }
}










/*
 * word at +0x0C names 0x021CC9AC.  That address is real Thumb code in ov093
 * (a 176-byte unlabelled bitfield packer, disasm prints it as a `.word` run)
 * but no listing labels it and no branch or pool word anywhere outside this
 * range names it, so `label`, `literal`, `sole-ref/code` and `matched` all
 * refuse.  It can only be witnessed by matching it bottom-up.  Passing the
 * full (char*, int, int) arity through to the callee is what makes the two
 * loads schedule as the original (add before the target load).
 *
 * Named by five parked pending files (BTL_CALC_IntimidateOnEnter / BTL_HANDLER_ITEM_DestinyKnot_Infatuate /
 * BTL_HANDLER_ITEM_RockyHelmetDamageReaction / func_021E4A70 / func_021E7388).
 *
 * 2026-10-05 (D9 lane 02): unchanged. 0x021CC9AC is a 176-byte packer, not a tiny leaf, and ov093 below 0x021D4000 is pengy's, so no witness filed. Needs the integrator seed.
 * 2026-10-05 (D9r lane 14): callee 0x021CC9AC is now matched EXACT as
 * src/matched/ov/ov093_func_021CC9AC.c (user-approved). Re-verified MATCH: the
 * relocation still waits on that file's shard (integrator manifest), then this
 * should verify EXACT with no source change.
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021CC9AC is a real 176-byte Thumb bitfield packer (bitfield insert into a table with 0x3b-entry byte lookup), not a veneer and not tiny; not filed in this lane. Needs bottom-up match or integrator seed.
 */
void *func_021C88A4(BtlServerFlow *flow, int a, int b)
{
    return func_021CC9AC((struct Pack *)&flow->lock, a, b);
}










/*
 * Named by the parked ov093 files (BTL_CALC_IntimidateOnEnter / BTL_HANDLER_ITEM_DestinyKnot_Infatuate /
 * BTL_HANDLER_ITEM_RockyHelmetDamageReaction / func_021E4A70 / func_021E7388).  EXACT*: both calls resolve
 * (func_021C88A4 by `label`, func_021C88C8 by `label`), the extent runs two
 * bytes long into the unlabelled follower.
 */
void func_021C88B4(BtlServerFlow *flow, int k, int b)
{
    func_021C88C8(flow, func_021C88A4(flow, k, b));
}










/*
 * Unlabelled-record helper reached from the five ov093 packets that name it
 * (BTL_HANDLER_ITEM_RockyHelmetDamageReaction / func_021E4A70 / BTL_CALC_IntimidateOnEnter / func_021E7388 /
 * BTL_HANDLER_ITEM_DestinyKnot_Infatuate).  Runs the battle-command dispatcher on (`a`, `b`), then
 * dispatches the same command through the record `a + 0x1D74`.
 */
void func_021C88C8(BtlServerFlow *flow, void *b)
{
    func_021C8918(flow, b);
    func_021CCA74((QueueA *)&flow->lock, (QueueB *)b);
}










int func_021C88E4(BtlServerFlow *flow)
{
    if (func_021CC96C((struct Q9 *)&flow->lock) != 0) {
        if (func_021CC9A4(&flow->lock) != 0) return 2;
        return 1;
    }
    return 0;
}










/*
 * tail-call thunk to func_021C88E4
 */
int func_021C8910(BtlServerFlow *flow)
{
    return func_021C88E4(flow);
}










void func_021C8918(BtlServerFlow *flow, void *cmd)
{
    u16 arg = func_021CC960((struct S_p14 *)&flow->lock);
    u8 r;

    if (func_021CC96C((struct Q9 *)&flow->lock))
        r = func_021CC99C((struct Q10 *)&flow->lock);
    else
        r = 1;

    if (((BtlCmd *)cmd)->ignoreIfBusy && r == 0)
        return;
    if (((BtlCmd *)cmd)->checkFainted && BTL_POKEPARAM_IsFainted(func_021B9940(flow->pokeCon, ((BtlCmd *)cmd)->client)))
        return;

    switch (((BtlCmd *)cmd)->id) {
    case 1:
        r = func_021C8C6C(flow, cmd);
        break;
    case 2:
        r = func_021C8CBC(flow, cmd);
        break;
    case 3:
        r = func_021C8D0C(flow, cmd);
        break;
    case 0:
        r = func_021C9DE8(flow, cmd);
        break;
    case 5:
        r = func_021C8D2C(flow, (Ent_021C8D2C *)cmd, arg);
        break;
    case 6:
        r = func_021C8DE4(flow, cmd, arg);
        break;
    case 7:
        r = func_021C8E58(flow, cmd);
        break;
    case 8:
        r = func_021C8F24(flow, cmd);
        break;
    case 9:
        r = func_021C8FA4(flow, cmd, arg);
        break;
    case 10:
        r = func_021C9010(flow, cmd, arg);
        break;
    case 11:
        r = func_021C9068(flow, cmd, arg);
        break;
    case 12:
        r = func_021C9178(flow, cmd);
        break;
    case 14:
        r = func_021C9250(flow, cmd, arg);
        break;
    case 15:
        r = func_021C9394(flow, cmd);
        break;
    case 18:
        r = func_021C9448(flow, cmd);
        break;
    case 16:
        r = func_021C947C(flow, cmd);
        break;
    case 17:
        r = func_021C94C8(flow, cmd);
        break;
    case 19:
        r = func_021C95D0(flow, cmd);
        break;
    case 20:
        r = func_021C962C(flow, cmd);
        break;
    case 4:
        r = func_021C96D4(flow, cmd);
        break;
    case 21:
        r = func_021C9728(flow, cmd);
        break;
    case 22:
        r = func_021C9750(flow, cmd);
        break;
    case 23:
        r = func_021C9778(flow, cmd);
        break;
    case 24:
        r = func_021C97A4(flow, cmd);
        break;
    case 25:
        r = func_021C97D0(flow, cmd);
        break;
    case 26:
        r = func_021C9828(flow, cmd);
        break;
    case 27:
        r = func_021C9898(flow, cmd);
        break;
    case 29:
        r = func_021C98E4(flow, cmd);
        break;
    case 28:
        r = func_021C98C4(flow, cmd);
        break;
    case 30:
        r = func_021C9A24(flow, cmd);
        break;
    case 31:
        r = func_021C9A60(flow, cmd);
        break;
    case 32:
        r = func_021C9BB8(flow, cmd);
        break;
    case 33:
        r = func_021C9DCC(flow, cmd);
        break;
    case 34:
        r = func_021C9E3C(flow, cmd);
        break;
    case 35:
        r = func_021C9ECC(flow, cmd);
        break;
    case 36:
        r = func_021C9CC0(flow, cmd);
        break;
    case 37:
        r = func_021C9F0C(flow, cmd);
        break;
    case 38:
        r = func_021C9F4C(flow, cmd);
        break;
    case 39:
        r = func_021C9F6C(flow, cmd);
        break;
    case 40:
        r = func_021CA128(flow, cmd);
        break;
    case 41:
        r = func_021CA158(flow, cmd);
        break;
    case 42:
        r = func_021CA1D0(flow, cmd);
        break;
    case 43:
        r = func_021CA248(flow, cmd);
        break;
    case 44:
        r = func_021CA270(flow, cmd);
        break;
    case 45:
        r = func_021CA2E8(flow, cmd);
        break;
    case 46:
        r = func_021CA318(flow, cmd);
        break;
    case 47:
        r = func_021CA370(flow, cmd);
        break;
    case 48:
        r = func_021CA394(flow, cmd);
        break;
    case 49:
        r = func_021CA3AC(flow, cmd);
        break;
    case 50:
        r = func_021CA3D0(flow, cmd);
        break;
    case 51:
        r = func_021CA47C(flow, cmd);
        break;
    case 52:
        r = func_021CA570(flow, cmd);
        break;
    case 53:
        r = func_021CA5CC(flow, cmd);
        break;
    case 54:
        r = func_021CA6C4(flow, cmd);
        break;
    case 55:
        r = func_021CA6FC(flow, cmd);
        break;
    case 56:
        r = func_021CA738(flow, cmd);
        break;
    case 57:
        r = func_021CA748(flow, cmd);
        break;
    case 58:
        r = func_021CA7C4(flow, cmd);
        break;
    case 59:
        r = func_021CA7D4(flow, cmd);
        break;
    }
    func_021CC974((Word_021CC768 *)&flow->lock, r);
}








u8 func_021C8C6C(BtlServerFlow *flow, BtlCmd *e)
{
    if (func_0689D588(flow->posPoke, e->client)) {
        BTL_SERVER_FLOW_PushPokeCmd42(flow, func_021B9934(flow->pokeCon, (u8)e->client));
        return 1;
    }
    return 0;
}









u8 func_021C8CBC(BtlServerFlow *flow, Ent_021C8CBC *e)
{
    if (func_0689D588(flow->posPoke, e->idx)) {
        BTL_SERVER_FLOW_PushAbilityPopupIn(flow, func_021B9934((char *)flow->pokeCon, (u8)e->idx));
        return 1;
    }
    return 0;
}










/*
 * note: caller narrows index to u8 before func_021B9934.
 */
u8 func_021C8D0C(BtlServerFlow *flow, Ent_021C8D0C *e)
{
    BTL_SERVER_FLOW_PushAbilityPopupOut(flow, func_021B9934((char *)flow->pokeCon, (u8)e->idx));
    return 1;
}











u8 func_021C8D2C(BtlServerFlow *flow, const Ent_021C8D2C *e, int c)
{
    u8 r = 0;
    u8 *a = func_021B9934((char *)flow->pokeCon, (u8)e->idx);
    u8 *b = func_021B9934((char *)flow->pokeCon, e->b6);

    if (BTL_SERVER_FLOW_IsHpRecoverUnneeded(flow, b) == 0) {
        if (e->fl)
            BTL_SERVER_FLOW_PushAbilityPopupIn(flow, a);
        if (e->b7 == 0) {
            r = !BTL_SERVER_FLOW_CheckHealBlocked(flow, b, 1);
        } else {
            r = 1;
        }
        if (r) {
            BTL_SERVER_FLOW_ApplyHpRecover(flow, b, e->h4);
            if ((u8)e->ha)
                func_021C99A0(flow, (void *)&e->h8);
            else if (c)
                BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x38c, e->b6, c, 0xffff0000);
        }
        if (e->fl)
            BTL_SERVER_FLOW_PushAbilityPopupOut(flow, a);
    }
    return r;
}










u8 func_021C8DE4(BtlServerFlow *flow, const Ent_021C8DE4 *e, int unused)
{
    int s = 0;
    int t;

    if (e->b7 != 0x1f)
        s = (int)func_021B9934((char *)flow->pokeCon, e->b7);
    if (func_0689D588(flow->posPoke, e->b6)) {
        t = (int)func_021B9934((char *)flow->pokeCon, e->b6);
        if (BTL_POKEPARAM_IsFainted((void *)t) == 0 && BTL_SERVER_FLOW_RecoverHpFromDrain(flow, (u8 *)t, s, e->h4)) {
            if ((u8)e->ha)
                func_021C99A0(flow, (void *)&e->h8);
            return 1;
        }
    }
    return 0;
}










u8 func_021C8E58(BtlServerFlow *flow, const Ent_021C8E58 *e)
{
    int a;
    u8 *b;
    u32 i;

    if (func_0689D588(flow->posPoke, e->b6)) {
        a = (int)func_021B9934((char *)flow->pokeCon, e->b6);
        b = 0;
        i = e->idx;
        if (i != 0x1f)
            b = func_021B9934((char *)flow->pokeCon, (u8)i);
        if (BTL_POKEPARAM_IsFainted((void *)a) == 0) {
            if (!e->f7a || BTL_POKEPARAM_IsSemiInvulnerable((struct UtilWork *)a) == 0) {
                if (BTL_SERVER_FLOW_CheckAbsorbRecoverAllowed(flow, (u8 *)a, e->h4)) {
                    if (e->fl)
                        BTL_SERVER_FLOW_PushAbilityPopupIn(flow, b);
                    if (e->f7b)
                        BTL_SERVER_FLOW_PushEffectAnim(flow, e->h8, e->ba, e->bb, 0, 0);
                    BTL_SERVER_FLOW_ProcAbsorbRecovery(flow, (u8 *)a, e->h4, (void *)((u8 *)e + 0xc));
                    if (e->fl)
                        BTL_SERVER_FLOW_PushAbilityPopupOut(flow, b);
                    return 1;
                }
            }
        }
    }
    return 0;
}










u8 func_021C8F24(BtlServerFlow *flow, const Ent_021C8F24 *e)
{
    u8 r = 0;
    u32 i;
    u8 *a;

    for (i = 0; i < e->n; i++) {
        if (func_0689D588(flow->posPoke, e->ids[i])) {
            a = func_021B9934(flow->pokeCon, e->ids[i]);
            if (BTL_POKEPARAM_IsFainted(a) == 0) {
                BTL_SERVER_FLOW_ChangeHp(flow, a, e->v[i], !e->b5);
                if (e->b6 == 0)
                    BTL_SERVER_FLOW_ProcDamagedItemReaction(flow, a, 1);
                r = 1;
            }
        }
    }
    return r;
}











u8 func_021C8FA4(BtlServerFlow *flow, const Ent_021C8FA4 *e, int unused)
{
    u8 *a;
    int r;

    func_021B9934((char *)flow->pokeCon, (u8)e->idx);
    a = func_021B9934((char *)flow->pokeCon, e->b5);
    if (BTL_POKEPARAM_IsAbleToBattle(a) || e->f7b) {
        r = !e->f7a;
        if (BTL_POKEPARAM_IsMovePPFull(a, e->b6, r) == 0) {
            BTL_SERVER_FLOW_RestoreMovePp(flow, a, e->b6, e->b4, r);
            func_021C99A0(flow, (void *)((u8 *)e + 8));
            return 1;
        }
    }
    return 0;
}











u8 func_021C9010(BtlServerFlow *flow, const Ent_021C9010 *e, int unused)
{
    int a;

    a = (int)func_021B9934((char *)flow->pokeCon, e->b5);
    if (BTL_POKEPARAM_IsFainted((void *)a) == 0 || e->f7b) {
        if (BTL_SERVER_FLOW_ConsumeMovePP(flow, (u8 *)a, e->b6, e->b4)) {
            func_021C99A0(flow, (void *)((u8 *)e + 8));
            if (BTL_SERVER_FLOW_QueryEffectBlockedEvent(flow, (u8 *)a, e->b6))
                BTL_SERVER_FLOW_ProcHeldItemActivate(flow, (u8 *)a);
        }
        return 1;
    }
    return 0;
}










/*
 * checks: 1 own B9934/C5620/C56A8/C99A0 bodies rederived, original
 *   B9934 narrowing and five-argument 9168 veneer setup preserved;
 *   2 matched C8E58/C8FA4 bodies refreshed, no exact twin;
 *   3 full-word unsigned-long veneer argument compiles unchanged at256/18;
 *   4 long-index, loop-invariant and typed-address idioms read;
 *   5 full idiom directory relisted, C8FA4 refreshed, Slot frame agrees.
 * residual: 256/256 bytes, 8 concrete bytes; 13/13 relocations resolve.
 *   Only the pool load + adds r7 (p+0x1ae4) versus movs #1/str result order at +70..76 differs.
 * retry: wave76 R8,4 compiles. Long arg and long i each retain18;
 *   integer-spelled msg address hoists both addresses and regresses to73;
 *   three nonshrinking changes stopped iteration; check 3 wide veneer
 *   argument retains18. Pointer msg spelling restored in best C.
 * permuter: prior once300 --types consumed; expand(work x3) improved64
 *   to18 and match.py agreed. No search repeated. Prior inner work local,
 *   enum arg and redundant work assignment gave65/18/64 respectively.
 * proof: original passes the full fourth argument word; no narrowing,
 *   volatile, invented defaults or altered control flow accepted.
 * recoup 2026-10-05 (lane X6, no pending file existed; started from the
 *   docs/notes draft, 18 B off, 12 compiles): callee return types checked,
 *   all match the draft (B9934 u8*, 5A1C/5A34/5620 void, 56A8 int, 99A0 int,
 *   8810 void, 195C void); 9168 is a veneer, no definition. Tried:
 *   (1) arg as u16/u8 with u16 callee param: store of r2 moves to the top of
 *   the entry (original has it after the first lsls), 18 B, other residue same;
 *   arg as int: same as unsigned long, 18 B. (2) work address in a local w
 *   (struct Msg *): compiler hoists msg and w to the for-body top, 64 B.
 *   (3) result as int: 32 B (extra uxtb at return). (4) result = 1 before msg:
 *   22 B. (5) const Ent_021C9068 *e, pragma scheduling off, opt_lifetimes off: 18 B
 *   unchanged. opt_propagation off: 198 B. (6) callee B9934 declared (char *,
 *   int): drops the u8 narrowing, 225 B. (7) idx in a u8 local: 18 B.
 *   Residue: entry spill str r2,[sp,#8] sits after the first lsls in the
 *   original, after the call args in ours; and the pool load + adds r7 for
 *   p+0x1ae4 comes before movs #1/str result in the original, after it in ours.
 *   Idioms read: a-later-parameters-width-reorders-the-entry-spill-stores,
 *   a-copy-and-a-pointer-step-hoisted-above-a-call-are-written-before-it,
 *   a-local-declared-at-its-first-use-schedules-its-store-there,
 *   a-spilled-pointer-plus-constant-argument-is-the-sum-stored-in-the-local,
 *   a-const-record-pointer-moves-the-outgoing-stack-store-below-the-register-copies.
 * final push 2026-10-05 G5L5 (37 compiles, 3 rounds, 18 B -> 8 B): the entry spill residue is closed
 *   by the shape of matched func_021C9250 (same prologue): p as u8 * with raw offsets
 *   (*(char **)(p + 8), p + 0x1ae4), const Ent_021C9068 *e, u16 arg with the callee still taking unsigned long.
 *   Any one of the three alone keeps 18 B (struct p with const e and u16 arg: 18 B; u16 arg without const e: 18 B).
 *   Remaining: the original computes the work address (ldr pool; adds r7) before movs #1/str result;
 *   ours emits the loop-invariant store first. Tried with no change (8 B): result = 1 at the top, the end,
 *   after BTL_SERVER_FLOW_CureSick or inside the do body (the store is hoisted to the same place); a named work
 *   local (u8 *w = p; w += 0x1ae4 before result) is propagated, a typed Msg * local hoists the msg and
 *   work setup to the top of the for body (54 to 64 B); &p[0x1ae4] and a struct view; callee 9168 with const
 *   Msg *; pragmas scheduling, opt_lifetimes, opt_common_subs off (8 B each); opt_propagation off (188 B);
 *   while (k) form instead of if + do-while (146 to 154 B); int result with return (u8) (22 B).
 *   Matched-assembly search for ldr pool; adds rN,r5,r0; movs; str over ov093.s: only this function.
 *   Idioms read: of-two-equal-temps-the-later-born-one-gets-the-lower-register (no change),
 *   opt-propagation-off-with-named-locals-pins-argument-constants-against-stack-stores (188 B).
 * pass 2 2026-10-06 P2L18: EXACT (256/256). The work buffer passed to func_0689C464 is a named
 *   local w assigned at the top of the do body and used only in that call; the two calls after it
 *   spell p + 0x1ae4 again (they CSE onto w), and result = 1 is written after the if/else in the
 *   body. Both named assignments are hoisted into the inner preheader in source order (w before
 *   result), which gives the original pool load + adds r7 before movs #1/str. A w used in all three
 *   calls is hoisted out of the outer for loop (54 B); the expression form puts the hoisted
 *   address after result (8 B).
 */
u8 func_021C9068(BtlServerFlow *flow, const Ent_021C9068 *e, u16 arg)
{
    const struct Msg *msg;
    u8 *first;
    u8 result;
    unsigned long i;
    u8 *a;
    int value;
    int k;
    union Slot slot;
    struct Msg *w;
    first = (u8 *)func_021B9934((char *)flow->pokeCon, (u8)e->idx);
    result = 0;
    if (e->fl) BTL_SERVER_FLOW_PushAbilityPopupIn(flow, first);
    for (i = 0; i < e->count; i++) {
        a = (u8 *)func_021B9934((char *)flow->pokeCon, (u8)e->targets[i]);
        if (BTL_POKEPARAM_IsAbleToBattle(a)) {
          value = e->value;
          k = BTL_SERVER_FLOW_ResolveCureSickId(a, &value);
          if (k) {
          msg = &e->msg;
          do {
            w = (struct Msg *)flow->msgParam;
            BTL_SERVER_FLOW_CureSick(flow, a, k, &slot);
            if (!e->flag) {
                if (func_0689C464(k, slot, a, arg, w)) {
                    func_021C99A0(flow, (struct Msg *)flow->msgParam);
                    func_021C8810((u8 *)flow->msgParam);
                }
            } else {
                func_021C99A0(flow, msg);
            }
            result = 1;
            if (k == 0x13) BTL_SERVER_FLOW_ProcDamagedItemReaction(flow, a, 0);
            k = BTL_SERVER_FLOW_ResolveCureSickId(a, &value);
          } while (k);
          }
        }
    }
    if (e->fl) BTL_SERVER_FLOW_PushAbilityPopupOut(flow, first);
    return result;
}









u8 func_021C9178(BtlServerFlow *flow, const Ent_021C9178 *e)
{
    u8 *a;
    u8 f;
    u8 *b;
    if (e->index != 31) a = func_021B9934(flow->pokeCon, (u8)e->index);
    else a = 0;
    f = (int)func_021C8828((u8 *)e->msg) == 0 && e->b == 0;
    if (func_0689D588(flow->posPoke, e->id)) {
        b = func_021B9934(flow->pokeCon, (u8)e->id);
        if (!BTL_POKEPARAM_IsFainted(b)) {
            if (!BTL_SERVER_FLOW_TryApplySick(flow, b, a, e->kind, e->value, e->d, e->a)) {
                if (e->flag) BTL_SERVER_FLOW_PushAbilityPopupIn(flow, a);
                BTL_SERVER_FLOW_ProcSickAdded(flow, b, a, e->kind, e->value, f, e->c, e->msg);
                if (e->flag) BTL_SERVER_FLOW_PushAbilityPopupOut(flow, a);
                return 1;
            }
        }
    }
    return 0;
}









u8 func_021C9250(BtlServerFlow *flow, const Ent_021C9250 *e, u16 arg)
{
    u8 *a;
    int f;
    u8 result;
    u32 i;
    u8 *b;
    const u8 *m;
    a = func_021B9934(flow->pokeCon, (u8)e->index);
    f = 0;
    result = 0;
    for (i = 0; i < e->count; i++) {
        if (func_0689D588(flow->posPoke, e->ids[i])) {
            b = func_021B9934(flow->pokeCon, (u8)e->ids[i]);
            if (!BTL_POKEPARAM_IsFainted(b)) {
                if (func_021D5D14((s8 *)b, (u32)e->kind, e->a)) {
                    f = 1;
                    break;
                }
            }
        }
    }
    if (f && e->flag) BTL_SERVER_FLOW_PushAbilityPopupIn(flow, a);
    m = (const u8 *)e;
    m += 24;
    for (i = 0; i < e->count; i++) {
        if (func_0689D588(flow->posPoke, e->ids[i])) {
            b = func_021B9934(flow->pokeCon, (u8)e->ids[i]);
            if (!BTL_POKEPARAM_IsFainted(b)) {
                if (BTL_SERVER_FLOW_TryChangeStatStage(flow, e->index, b, e->kind, e->a, 31, arg, e->value, e->c, e->b == 0)) {
                    func_021C99A0(flow, (const struct Msg *)m);
                    result = 1;
                }
            }
        }
    }
    if (f && e->flag) BTL_SERVER_FLOW_PushAbilityPopupOut(flow, a);
    return result;
}









u8 func_021C9394(BtlServerFlow *flow, const Ent_021C9394 *e)
{
    u8 *a;

    if (func_0689D588(flow->posPoke, e->b[0])) {
        a = func_021B9934((char *)flow->pokeCon, e->b[0]);
        if (BTL_POKEPARAM_IsFainted(a) == 0) {
            BTL_POKEPARAM_SetStatStage(a, 1, e->b[1]);
            BTL_POKEPARAM_SetStatStage(a, 2, e->b[2]);
            BTL_POKEPARAM_SetStatStage(a, 3, e->b[3]);
            BTL_POKEPARAM_SetStatStage(a, 4, e->b[4]);
            BTL_POKEPARAM_SetStatStage(a, 5, e->b[5]);
            BTL_POKEPARAM_SetStatStage(a, 6, e->b[6]);
            BTL_POKEPARAM_SetStatStage(a, 7, e->b[7]);
            BTL_SERVER_CMD_Push(flow->cmdQueue, 0xb, e->b[0], e->b[1], e->b[2], e->b[3], e->b[4], e->b[5], e->b[6], e->b[7]);
            return 1;
        }
    }
    return 0;
}









/*
 * extent: compiled 50 bytes; 021C947A..021C947C is alignment padding.
 * note: caller consumes live r0 after void-declared BTL_POKEPARAM_RaiseLoweredStatStages;
 *       return interface follows its explicit u8 truncation at 021C9470.
 */
u8 func_021C9448(BtlServerFlow *flow, u8 *e)
{
    char *a;
    a = (char *)func_021B9934((char *)flow->pokeCon, e[4]);
    if (BTL_POKEPARAM_IsFainted(a) == 0) {
        BTL_SERVER_CMD_Push(flow->cmdQueue, 12, e[4]);
        return (u8)BTL_POKEPARAM_RaiseLoweredStatStages(a);
    }
    return 0;
}










u8 func_021C947C(BtlServerFlow *flow, const Ent_021C9448 *e)
{
    u8 r = 0;
    u32 i;
    u8 *a;

    for (i = 0; i < e->n; i++) {
        a = func_021B9934(flow->pokeCon, e->ids[i]);
        if (BTL_POKEPARAM_IsFainted(a) == 0) {
            BTL_SERVER_CMD_Push(flow->cmdQueue, 0xd, e->ids[i]);
            BTL_POKEPARAM_ResetStatStages((char *)a);
            r = 1;
        }
    }
    return r;
}








u8 func_021C94C8(BtlServerFlow *flow, const Ent_021C94C8 *e)
{
    u8 *a;
    if (func_0689D588(flow->posPoke, e->id)) {
        a = func_021B9934(flow->pokeCon, e->id);
        if (e->f0) { BTL_POKEPARAM_SetStat(a, 8, e->values[0]); BTL_SERVER_CMD_Push(flow->cmdQueue, 19, e->id, 8, (u8)e->values[0]); }
        if (e->f1) { BTL_POKEPARAM_SetStat(a, 9, e->values[1]); BTL_SERVER_CMD_Push(flow->cmdQueue, 19, e->id, 9, (u8)e->values[1]); }
        if (e->f2) { BTL_POKEPARAM_SetStat(a, 10, e->values[2]); BTL_SERVER_CMD_Push(flow->cmdQueue, 19, e->id, 10, (u8)e->values[2]); }
        if (e->f3) { BTL_POKEPARAM_SetStat(a, 11, e->values[3]); BTL_SERVER_CMD_Push(flow->cmdQueue, 19, e->id, 11, (u8)e->values[3]); }
        if (e->f4) { BTL_POKEPARAM_SetStat(a, 12, e->values[4]); BTL_SERVER_CMD_Push(flow->cmdQueue, 19, e->id, 12, (u8)e->values[4]); }
        func_021C99A0(flow, (const struct Msg *)e->msg);
        return 1;
    }
    return 0;
}

















u8 func_021C95D0(BtlServerFlow *flow, const Ent_021C95D0 *e)
{
    int a;

    if (func_0689D588(flow->posPoke, e->b4)) {
        a = (int)func_021B9934((char *)flow->pokeCon, e->b4);
        if (BTL_POKEPARAM_IsFainted((void *)a) == 0 || e->b5) {
            func_021C99A0(flow, (void *)((u8 *)e + 8));
            BTL_SERVER_FLOW_ProcPokeHpChangeFinish(flow, (u8 *)a);
            return 1;
        }
    }
    return 0;
}

















u8 func_021C962C(BtlServerFlow *flow, const Ent_021C962C *e)
{
    int a;

    if (func_0689D588(flow->posPoke, e->b6)) {
        a = (int)func_021B9934((char *)flow->pokeCon, e->b6);
        if (BTL_POKEPARAM_IsFainted((void *)a) == 0 && func_0689C9C0(BTL_POKEPARAM_GetSpecies((void *)a)) == 0) {
            BTL_SERVER_CMD_Push(flow->cmdQueue, 0x16, e->b6, e->h4);
            BTL_POKEPARAM_SetTypes((void *)a, e->h4);
            if (e->b7 == 0 && BTLV_CORE_BytesEqual(e->h4))
                BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x380, e->b6, BTLV_CORE_GetHighByte(e->h4), 0xffff0000);
            return 1;
        }
    }
    return 0;
}


















u8 func_021C96D4(BtlServerFlow *flow, struct Cmd_021C96D4 *c)
{
    u8 *r = 0;
    int id = c->id;
    if (id != 0x1F) {
        r = func_021B9934((char *)flow->pokeCon, (u8)id);
    }
    if (c->flag && r) BTL_SERVER_FLOW_PushAbilityPopupIn(flow, r);
    func_021C99A0(flow, (const struct Msg *)((u8 *)c + 4));
    if (c->flag && r) BTL_SERVER_FLOW_PushAbilityPopupOut(flow, r);
    return 1;
}


















/*
 * extent: two bytes of trailing alignment padding.
 */
u8 func_021C9728(BtlServerFlow *flow, u8 *q)
{
    u8 *a = func_021B9934((char *)flow->pokeCon, q[8]);
    if (!BTL_POKEPARAM_IsFainted(a)) {
        BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}


















u8 func_021C9750(BtlServerFlow *flow, u8 *q)
{
    u8 *a = func_021B9934((char *)flow->pokeCon, q[8]);
    if (!BTL_POKEPARAM_IsFainted(a)) {
        BTL_POKEPARAM_ClearTurnFlag(a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}


















u8 func_021C9778(BtlServerFlow *flow, u8 *q)
{
    u8 *a = func_021B9934((char *)flow->pokeCon, q[8]);
    if (!BTL_POKEPARAM_IsFainted(a)) {
        BTL_SERVER_FLOW_SetContFlag(flow, a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}


















u8 func_021C97A4(BtlServerFlow *flow, u8 *q)
{
    u8 *a = func_021B9934((char *)flow->pokeCon, q[8]);
    if (!BTL_POKEPARAM_IsFainted(a)) {
        BTL_SERVER_FLOW_ClearContFlag(flow, a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}

















u8 func_021C97D0(BtlServerFlow *flow, const struct Cmd_021C97D0 *c)
{
    u32 v;
    void *pv;
    v = c->w8;
    pv = &v;
    func_021C7BA8(flow, c->id, c->w4, c->b12, pv);
    if (func_06898C10(c->b12, c->w4, *(Word_021CAA58_td *)pv) != 0) {
        func_021C99A0(flow, (const struct Msg *)((u8 *)c + 0x10));
        return 1;
    }
    return 0;
}















static inline int test(u8 *s, u32 i)
{
    u8 idx = (i >> 3) + 1;
    u8 bit = i & 7;
    if (idx < s[4]) {
        if ((1 << bit) & s[4 + idx]) return 1;
        else return 0;
    }
    return 0;
}















u8 func_021C9828(BtlServerFlow *flow, u8 *s)
{
    u8 r = 0;
    u32 i;
    for (i = 0; i < 14; i++) {
        if (test(s, i) && func_06898D10(s[7], i)) {
            BTL_SERVER_FLOW_PushSideEffectExpireMessage(flow, i, s[7]);
            r = 1;
        }
    }
    return r;
}














/*
 * extent: two bytes of trailing alignment padding.
 */
u8 func_021C9898(BtlServerFlow *flow, u8 *q)
{
    if (BTL_SERVER_FLOW_TryRegisterFieldSlot(flow, *(int *)(q + 4), *(union Slot *)(q + 8), q[12])) {
        func_021C99A0(flow, (const struct Msg *)(q + 16));
        return 1;
    }
    return 0;
}















u8 func_021C98C4(BtlServerFlow *flow, u8 *q)
{
    if (BTL_FIELD_QueryStaticSlotA(*(int *)(q + 4))) {
        BTL_SERVER_FLOW_PushFieldEffectExpireMessage(flow, *(int *)(q + 4));
        return 1;
    }
    return 0;
}
















u8 func_021C98E4(BtlServerFlow *flow, struct Cmd_021C98E4 *c)
{
    u8 *id = func_021B9934((char *)flow->pokeCon, (u8)c->id);
    int r = 0;
    u32 s;
    if (c->b4 != 0) {
        if (BTL_SERVER_FLOW_CanChangeWeather(flow, c->b4, c->b5) != 0) {
            if (c->flag) BTL_SERVER_FLOW_PushAbilityPopupIn(flow, id);
            BTL_SERVER_FLOW_ApplyWeatherChange(flow, c->b4, c->b5);
            func_021C99A0(flow, (const struct Msg *)((u8 *)c + 8));
            r = 1;
            if (c->flag) BTL_SERVER_FLOW_PushAbilityPopupOut(flow, id);
        }
    } else if (c->b6 != 0) {
        if (c->flag) BTL_SERVER_FLOW_PushAbilityPopupIn(flow, id);
        func_021C99A0(flow, (const struct Msg *)((u8 *)c + 8));
        s = func_021CC8D8(&flow->lock, 15467);
        func_021C7BF8(flow);
        func_021CC95C((u32 *)&flow->lock, s, 15469);
        r = 1;
        if (c->flag) BTL_SERVER_FLOW_PushAbilityPopupOut(flow, id);
    }
    return r;
}
















int func_021C99A0(BtlServerFlow *flow, const struct Msg *m)
{
    if (!m->flag) {
        switch (m->kind) {
        case 1:
            BTL_SERVER_FLOW_PushMsgStd(flow, m->a, m->n, (const int *)m->data);
            return 1;
        case 2:
            BTL_SERVER_FLOW_PushMsgSet(flow, m->a, m->n, (const int *)m->data);
            return 1;
        }
    } else {
        u16 x = m->w20;
        switch (m->kind) {
        case 1:
            BTL_SERVER_FLOW_PushMsgStdSe(flow, m->a, x, m->n, (int *)m->data);
            return 1;
        case 2:
            BTL_SERVER_FLOW_PushMsgSetSe(flow, m->a, x, m->n, (int *)m->data);
            return 1;
        }
    }
    return 0;
}















/*
 * lever: const source pointer hoists the id load before the outgoing
 * stack-argument store; mutable source gave 16 scheduling bytes different.
 */
u8 func_021C9A24(BtlServerFlow *flow, const struct Cmd_021C9A24 *q)
{
    int r;
    if (func_068981F0(q->w4, q->b8, q->id, q->data, q->b28)) r = 1;
    else r = 0;
    return r;
}












u8 func_021C9A60(BtlServerFlow *flow, const Ent_021C9A60 *e)
{
    u8 *a;
    u16 x;
    int line;
    u32 s;
    u32 t;
    a = func_021B9934(flow->pokeCon, e->id);
    x = func_021D59B4(a, 16);
    if (func_0689C974(x)) return 0;
    if (BTL_POKEPARAM_IsFainted(a)) return 0;
    if (e->a || e->value != x) {
        if (e->flag) BTL_SERVER_CMD_Push(flow->cmdQueue, 87, (u8)e->index);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 73, e->id, e->value);
        func_021C99A0(flow, (const struct Msg *)e->msg);
        line = 15561;
        s = func_021CC8D8(&flow->lock, line);
        func_021C7B3C(flow, e->id, x, e->value);
        func_021CC95C((u32 *)&flow->lock, s, line + 2);
        BTL_CALC_RemoveAbilityHandlers(a);
        BTL_POKEPARAM_SetAbility((struct QJ *)a, e->value);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 29, e->id, e->value);
        BTL_CALC_AddAbilityHandlers(a);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 88, e->id);
        if (x != e->value) {
            t = func_021CC8D8(&flow->lock, line + 16);
            func_021C7B7C(flow, e->id);
            line += 18;
            func_021CC95C((u32 *)&flow->lock, t, line);
        }
        if (e->flag) BTL_SERVER_CMD_Push(flow->cmdQueue, 88, (u8)e->index);
        if (!BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 16)) {
            if (x == 103) BTL_SERVER_FLOW_ProcDamagedItemReaction(flow, a, 0);
            if (x == 127) BTL_SERVER_FLOW_RecheckOpponentAbilityEffects(flow, a);
        }
        return 1;
    }
    return 0;
}















u8 func_021C9BB8(BtlServerFlow *flow, const Ent_021C9BB8 *e)
{
    u8 *a;
    int line;
    u32 s;
    u8 f;
    u32 t;
    a = func_021B9934(flow->pokeCon, e->id);
    if (e->index != e->id) {
        line = 15615;
        s = func_021CC8D8(&flow->lock, line);
        f = func_021C7A54(flow, a, e->value);
        func_021CC95C((u32 *)&flow->lock, s, line + 2);
        if (f) {
            t = func_021CC8D8(&flow->lock, line + 6);
            func_021C7AA0(flow, a);
            func_021CC95C((u32 *)&flow->lock, t, line + 8);
            return 0;
        }
    }
    if (e->flag) BTL_SERVER_CMD_Push(flow->cmdQueue, 87, (u8)e->index);
    func_021C99A0(flow, (const struct Msg *)e->msg);
    BTL_SERVER_FLOW_SetHeldItem(flow, a, e->value, 0);
    if (e->flag) BTL_SERVER_CMD_Push(flow->cmdQueue, 88, (u8)e->index);
    if (e->a) {
        BTL_POKEPARAM_ClearConsumedItem(a);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 43, e->id);
    }
    if (e->b) {
        BTL_POKEPARAM_ClearConsumedItem(func_021B9934(flow->pokeCon, e->c));
        BTL_SERVER_CMD_Push(flow->cmdQueue, 43, e->c);
    }
    BTL_SERVER_FLOW_ProcDamagedItemReaction(flow, a, 0);
    return 1;
}
















/*
 * lever: truncated accessor results live in u32 locals; u16 locals rotate seven spill offsets.
 */
u8 func_021C9CC0(BtlServerFlow *flow, const Ent_021C9CC0 *e)
{
    u8 *a;
    u8 *b;
    u16 x;
    u16 y;
    u32 s;
    u8 f;
    u32 t;
    a = func_021B9934(flow->pokeCon, (u8)e->id);
    b = func_021B9934(flow->pokeCon, (u8)e->index);
    x = (u16)(int)BTL_POKEPARAM_GetItem((struct QI *)b);
    y = (u16)(int)BTL_POKEPARAM_GetItem((struct QI *)a);
    s = func_021CC8D8(&flow->lock, 15671);
    f = func_021C7A54(flow, a, x);
    func_021CC95C((u32 *)&flow->lock, s, 15673);
    if (f) {
        t = func_021CC8D8(&flow->lock, 15676);
        func_021C7AA0(flow, a);
        func_021CC95C((u32 *)&flow->lock, t, 15678);
        return 0;
    }
    if (e->flag) BTL_SERVER_FLOW_PushAbilityPopupIn(flow, b);
    func_021C99A0(flow, (const struct Msg *)e->msg);
    func_021C99A0(flow, (const struct Msg *)(e->msg + 36));
    func_021C99A0(flow, (const struct Msg *)(e->msg + 72));
    if (e->flag) BTL_SERVER_FLOW_PushAbilityPopupOut(flow, b);
    BTL_SERVER_FLOW_SetHeldItem(flow, b, y, 0);
    BTL_SERVER_FLOW_SetHeldItem(flow, a, x, 0);
    BTL_SERVER_FLOW_ProcDamagedItemReaction(flow, b, 0);
    BTL_SERVER_FLOW_ProcDamagedItemReaction(flow, a, 0);
    return 1;
}
















u8 func_021C9DCC(BtlServerFlow *flow, u8 *q)
{
    u8 *a = func_021B9934((char *)flow->pokeCon, q[4]);
    BTL_SERVER_FLOW_ProcDamagedItemReaction(flow, a, *(u32 *)(q + 8));
    return 1;
}
















u8 func_021C9DE8(BtlServerFlow *flow, struct Cmd_021C9DE8 *c)
{
    u8 *r = func_021B9934((char *)flow->pokeCon, (u8)c->id);
    if (BTL_POKEPARAM_IsFainted(r) == 0 || c->f1) {
        if (c->f0 && BTL_POKEPARAM_IsHpFull(r) != 0) return 0;
        if (BTL_SERVER_FLOW_ProcHeldItemActivate(flow, r) != 0) return 1;
    }
    return 0;
}
















u8 func_021C9E3C(BtlServerFlow *flow, struct Cmd_021C9E3C *c)
{
    int r = (int)func_021B9934((char *)flow->pokeCon, c->b4);
    int x;
    u16 t;
    u32 s;
    if (BTL_POKEPARAM_IsFainted((void *)r) == 0) {
        x = (int)BTL_HANDLER_ITEM_AddForcedFactor((void *)r, c->h6);
        if (x != 0) {
            t = BTL_SERVER_CMD_Reserve(flow->cmdQueue, 0x42);
            s = func_021CC8D8(&flow->lock, 15755);
            BTL_SERVER_FLOW_DispatchPostMoveKindEvent(flow, (u8 *)r, c->id);
            if (func_021C88E4(flow) == 2) {
                BTL_SERVER_CMD_FillReserved(flow->cmdQueue, t, 0x42, c->b4);
            }
            func_021CC95C((u32 *)&flow->lock, s, 15762);
            BTL_HANDLER_ITEM_RemoveFactor((void *)x);
            return 1;
        }
    }
    return 0;
}
















u8 func_021C9ECC(BtlServerFlow *flow, struct Cmd_021C9ECC *c)
{
    u8 *r = func_021B9934((char *)flow->pokeCon, (u8)c->id);
    if (c->w4 == 0) {
        BTL_SERVER_FLOW_PushPokeCmd42(flow, r);
        func_021C99A0(flow, (const struct Msg *)((u8 *)c + 8));
    }
    BTL_SERVER_FLOW_SetHeldItem(flow, r, 0, 1);
    return 1;
}
















u8 func_021C9F0C(BtlServerFlow *flow, const struct Cmd_021C9F0C *c)
{
    u8 *r = func_021B9934((char *)flow->pokeCon, c->b4);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x1F, c->b4, c->b5, c->b6, c->b7, c->h8);
    BTL_POKEPARAM_ReplaceMove(r, c->b5, c->h8, c->b6, c->b7);
    return 1;
}













u8 func_021C9F4C(BtlServerFlow *flow, u8 *q)
{
    u8 *a = func_021B9934((char *)flow->pokeCon, q[4]);
    BTL_SERVER_FLOW_SetPokeCounter(flow, a, q[5], q[6]);
    return 1;
}












u8 func_021C9F6C(BtlServerFlow *flow, u8 *q)
{
    u8 work[28];
    struct Out *out = (struct Out *)(work + 8);
    u16 *saved;
    u8 *a = func_021B9934((char *)flow->pokeCon, q[4]);
    u8 *b = func_021B9934((char *)flow->pokeCon, q[5]);
    struct State_p13 *state;
    u32 flag;
    BTL_SERVER_FLOW_GetMoveParam(flow, *(u16 *)(q + 6), a, (struct Out64B4 *)out);
    func_0689CB3C(flow->curDamageSet);
    func_0689CB3C(flow->curQueuedSet);
    func_0689CB48(flow->curQueuedSet, b);
    func_0689CD48(flow->curQueuedSet, 1);
    func_0689CEE4(flow->curQueuedSet);
    if (func_0689CD50(flow->curQueuedSet)) {
        BTL_SERVER_FLOW_PushMsgStdFailed(flow, a, ((u16 *)work)[4]);
        return 0;
    }
    BTL_SERVER_FLOW_RemoveImmuneTargets(flow, (u16 *)out, a, flow->curQueuedSet);
    BTL_SERVER_FLOW_ProcAccuracyCheck(flow, (int)out, a, flow->curQueuedSet, flow->targetParam);
    BTL_SERVER_FLOW_ProcNoEffectChecks(flow, (u8 *)out, a, flow->curQueuedSet, flow->targetParam);
    BTL_SERVER_FLOW_RemoveMissedTargets(flow, (u16 *)out, a, flow->curQueuedSet);
    if (func_0689CD50(flow->curQueuedSet)) return 0;
    state = (struct State_p13 *)flow->curTurnState;
    saved = (u16 *)work;
    saved[0] = ((struct Obj05194 *)state)->f0;
    saved[1] = ((struct Obj05194 *)state)->f2;
    saved[2] = ((struct Obj05194 *)state)->f4;
    BTL_SERVER_FLOW_InitTurnState((struct Unk021BD1E0 *)state);
    BTL_SERVER_FLOW_SetupTurnState((struct Unk021BD1E0 *)((struct State_p13 *)flow->curTurnState), flow, a, flow->curQueuedSet);
    ((struct State_p13 *)flow->curTurnState)->b4 = 1;
    BTL_SERVER_FLOW_ProcMoveHitTargets(flow, (u8 *)out, a, (u8 *)flow->curQueuedSet, (const u32 *)flow->targetParam, 1);
    state = (struct State_p13 *)flow->curTurnState;
    flag = state->flag;
    ((struct Obj05194 *)state)->f0 = saved[0];
    ((struct Obj05194 *)state)->f2 = saved[1];
    ((struct Obj05194 *)state)->f4 = saved[2];
    return flag;
}











u8 func_021CA128(BtlServerFlow *flow, struct Bits_p13 *q)
{
    u8 *a = func_021B9934((char *)flow->pokeCon, (u8)q->index);
    if (BTL_SERVER_FLOW_TryEscape(flow, a, 1)) {
        flow->flowResult = 5;
        return 1;
    }
    return 0;
}













u8 func_021CA158(BtlServerFlow *flow, struct Cmd_021CA158 *c)
{
    u8 *r = func_021B9934((char *)flow->pokeCon, c->b4c);
    if (BTL_SERVER_FLOW_CheckShowdown(flow) == 0 && func_021C8374(flow, c->b4c) == 0 && flow->flowResult == 0) {
        func_021C99A0(flow, (const struct Msg *)((u8 *)c + 4));
        if (BTL_SERVER_FLOW_ProcMemberOut(flow, r, c->b4d) != 0) {
            BTL_SERVER_AddPokeChangeRequest(flow->server, func_021B8D8C(flow->mainModule, flow->pokeCon, c->b4c));
            func_021C99A0(flow, (const struct Msg *)((u8 *)c + 0x28));
            flow->flowResult = 1;
            return 1;
        }
    }
    return 0;
}













u8 func_021CA1D0(BtlServerFlow *flow, const struct Cmd_021CA1D0 *c)
{
    u8 *a = func_021B9934((char *)flow->pokeCon, c->b4);
    u8 *b = func_021B9934((char *)flow->pokeCon, c->b5);
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 0x10) != 0) BTL_SERVER_FLOW_RunSickEndEvent(flow, b);
    BTL_POKEPARAM_PassEffects((struct Work *)b, (struct Work *)a);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 0x26, c->b4, c->b5);
    if (BTL_POKEPARAM_HasSubstitute(b) != 0) {
        int r = func_0689D5C8(flow->posPoke, c->b5);
        BTL_SERVER_CMD_Push(flow->cmdQueue, 0x51, r);
    }
    return 1;
}











u8 func_021CA248(BtlServerFlow *flow, const u8 *q)
{
    u8 r;
    if (BTL_SERVER_FLOW_RollFlinch(flow, func_021B9934((char *)flow->pokeCon, q[4]), q[5])) r = 1;
    else r = 0;
    return r;
}












u8 func_021CA270(BtlServerFlow *flow, const struct Cmd_021CA248 *c)
{
    u8 s;
    u8 a;
    u8 b;
    BTL_POKEPARAM_AddHp((struct Unk021D5FA4 *)func_021B9934((char *)flow->pokeCon, c->b4), c->h6);
    BTL_SERVER_CMD_Push(flow->cmdQueue, 2, c->b4, c->h6);
    flow->pokeFlagsA[c->b4] = 0;
    func_021C99A0(flow, (const struct Msg *)((u8 *)c + 8));
    s = func_021B8D8C(flow->mainModule, flow->pokeCon, c->b4);
    if (s != 6) {
        a = func_021B8DDC(c->b4);
        b = func_021B8DEC((char *)flow->mainModule, s);
        BTL_SERVER_FLOW_ProcMemberIn(flow, a, b, b, 1);
        BTL_SERVER_FLOW_ProcAfterMemberIn(flow);
    }
    return 1;
}











/*
 * extent: two zero bytes at 021CA316 are alignment padding.
 */
u8 func_021CA2E8(BtlServerFlow *flow, const u8 *q)
{
    BTL_POKEPARAM_SetWeight(func_021B9934((char *)flow->pokeCon, q[4]), *(const u16 *)(q + 6));
    BTL_SERVER_CMD_Push(flow->cmdQueue, 20, q[4], *(const u16 *)(q + 6));
    func_021C99A0(flow, (const struct Msg *)(q + 8));
    return 1;
}












u8 func_021CA318(BtlServerFlow *flow, const struct Q_021C95D0 *q)
{
    int out[1];
    u8 *a = func_021B9934((char *)flow->pokeCon, q->f);
    u8 *b = func_021B9934((char *)flow->pokeCon, (u8)q->b);
    if (BTL_SERVER_FLOW_TryForceSwitchTarget(flow, b, a, q->lo, out, q->e, q->hi, (const struct Msg *)((u8 *)q + 8))) return 1;
    return 0;
}











/*
 * extent: two zero bytes at 021CA392 are alignment padding.
 */
u8 func_021CA370(BtlServerFlow *flow, const u8 *q)
{
    if (BTL_SERVER_FLOW_PromoteActionOfPoke(flow, q[4])) {
        func_021C99A0(flow, (const struct Msg *)(q + 8));
        return 1;
    }
    return 0;
}











u8 func_021CA394(BtlServerFlow *flow, const u8 *q)
{
    u8 r;
    if (BTL_SERVER_FLOW_PromoteActionsByMove(flow, *(const u16 *)&((struct Obj21127 *)q)->f4)) r = 1;
    else r = 0;
    return r;
}











/*
 * extent: two zero bytes at 021CA3CE are alignment padding.
 */
u8 func_021CA3AC(BtlServerFlow *flow, const u8 *q)
{
    if (BTL_SERVER_FLOW_DemoteActionOfPoke(flow, q[4])) {
        func_021C99A0(flow, (const struct Msg *)(q + 8));
        return 1;
    }
    return 0;
}












u8 func_021CA3D0(BtlServerFlow *flow, u8 *q)
{
    int a, b;
    u8 *m1, *m2;
    char *o;
    s16 i, j;
    if (q[4] != q[5]) {
        a = func_021B8DDC(q[4]);
        b = func_021B8DDC(q[5]);
        if (a == b) {
            m1 = func_021B9934((char *)flow->pokeCon, q[4]);
            m2 = func_021B9934((char *)flow->pokeCon, q[5]);
            if (!BTL_POKEPARAM_IsFainted(m1) && !BTL_POKEPARAM_IsFainted(m2)) {
                o = func_021B9AEC((char *)flow->pokeCon, a);
                i = func_021B9C98((u8 *)o, (u32)m1);
                j = func_021B9C98((u8 *)o, (u32)m2);
                if (i >= 0 && j >= 0) {
                    BTL_SERVER_FLOW_ShiftPokes(flow, a, i, j, 0);
                    func_021C99A0(flow, (const struct Msg *)(q + 8));
                    BTL_SERVER_FLOW_DispatchShiftEvents(flow, a, i, j);
                    return 1;
                }
            }
        }
    }
    return 0;
}











u8 func_021CA47C(BtlServerFlow *flow, struct Cmd_021CA2E8 *q)
{
    u8 *a = func_021B9934((char *)flow->pokeCon, (u8)q->id);
    u8 *b = func_021B9934((char *)flow->pokeCon, (u8)q->target);
    u16 k;
    int x, y;
    u32 lock;
    if (!BTL_POKEPARAM_IsIllusionActive((struct R4 *)a) && !BTL_POKEPARAM_IsIllusionActive((struct R4 *)b) && !BTL_POKEPARAM_IsSemiInvulnerable((struct UtilWork *)a)) {
        k = func_021D59B4(a, 16);
        if (BTL_POKEPARAM_Transform((struct Unk021D6C50 *)a, (struct Unk021D6C50 *)b)) {
            x = BTL_POKEPARAM_GetPokeId(a);
            y = BTL_POKEPARAM_GetPokeId(b);
            if (q->flag) BTL_SERVER_FLOW_PushAbilityPopupIn(flow, a);
            func_021E0434(a);
            BTL_CALC_RemoveAbilityHandlers(a);
            BTL_CALC_AddAbilityHandlers(a);
            BTL_SERVER_CMD_Push(flow->cmdQueue, 0x53, x, y);
            func_021C99A0(flow, (const struct Msg *)((u8 *)q + 8));
            if (q->flag) BTL_SERVER_FLOW_PushAbilityPopupOut(flow, a);
            if (k != func_021D59B4(a, 17)) {
                lock = func_021CC8D8(&flow->lock, 0x3f0a);
                func_021C7B7C(flow, x);
                func_021CC95C((u32 *)&flow->lock, lock, 0x3f0c);
            }
            return 1;
        }
    }
    return 0;
}












u8 func_021CA570(BtlServerFlow *flow, u8 *q)
{
    u8 *m;
    if (func_0689D588(flow->posPoke, q[4])) {
        m = func_021B9934(flow->pokeCon, q[4]);
        if (BTL_POKEPARAM_IsIllusionActive((struct R4 *)m)) {
            BTL_POKEPARAM_ClearIllusion((struct Unk021D6C2C *)m);
            BTL_SERVER_CMD_Push(flow->cmdQueue, 0x4b, q[4]);
            func_021C99A0(flow, (const struct Msg *)(q + 8));
            return 1;
        }
    }
    return 0;
}










/*
 * lever: C7F68 returns its normalized u8 j, and u8 n restores the count reload.
 */
u8 func_021CA5CC(BtlServerFlow *flow, const struct Cmd *q)
{
    u8 buf[8];
    u8 n;
    u8 i;
    u8 *a;
    int changed;
    u8 t;
    n = func_021C7F68(flow, (u16)(func_021B8D8C(flow->mainModule, flow->pokeCon, (u8)q->id) | 0x800), buf);
    i = 0;
    if (i >= n) goto done;
loop:
    {
        a = (u8 *)func_021B9934((char *)flow->pokeCon, buf[i]);
        changed = 0;
        if (BTL_POKEPARAM_TestContFlag((struct UtilWork *)a, 3)) {
            BTL_SERVER_FLOW_TryClearContFlag(flow, a, 3);
            t = func_021D69AC(a, 4);
            if (!(t && (t = (u8)(t - 1)) < 24)) t = 31;
            if (t != 31) func_0203EFC8((const u8 *)flow, a, 1);
            changed = 1;
        }
        if (BTL_SERVER_FLOW_QueryPokeGroundedEvent(flow, a, 1)) changed = 1;
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 30)) {
            BTL_SERVER_FLOW_CureSick(flow, a, 30, 0);
            changed = 1;
        }
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 32)) {
            BTL_SERVER_FLOW_CureSick(flow, a, 32, 0);
            changed = 1;
        }
        if (changed) BTL_SERVER_CMD_PushVariable(flow->cmdQueue, 0x5b, 0x43b, buf[i], 0xffff0000);
    }
    i++;
    if (i < n) goto loop;
done:
    return 1;
}










u8 func_021CA6C4(BtlServerFlow *flow, const u8 *q)
{
    u8 *m = func_021B9934((char *)flow->pokeCon, q[4]);
    if (!BTL_POKEPARAM_IsFainted(m) && BTL_SERVER_FLOW_TryClearContFlag(flow, m, *(const int *)(q + 8))) {
        func_021C99A0(flow, (const struct Msg *)(q + 12));
        return 1;
    }
    return 0;
}










u8 func_021CA6FC(BtlServerFlow *flow, const u8 *q)
{
    if (q[11]) BTL_SERVER_CMD_Push(flow->cmdQueue, 86, 0);
    BTL_SERVER_FLOW_PushEffectAnim(flow, *(const u16 *)(q + 4), q[6], q[7], q[10], *(const u16 *)(q + 8));
    func_021C99A0(flow, (const struct Msg *)(q + 12));
    return 1;
}











/* 021CA738  3-arg call on field 0xc, then returns 1 */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; ldr r0, [r0, #0xc]; movs r1, #0x56; movs r2, #0; bl BTL_SERVER_CMD_Push; movs r0, #1; pop {r3, pc}.
 */
u8 func_021CA738(BtlServerFlow *flow, void *unused)
{
    BTL_SERVER_CMD_Push((void *)(flow->cmdQueue), 0x56, 0);
    return 1;
}













/*
 * The listing extent (172 bytes) runs on into func_021CA7C4 and func_021CA7D4,
 * which are filed separately.
 */
u8 func_021CA748(BtlServerFlow *flow, const struct Q_021CA5CC *q)
{
    u8 t;
    void *m = func_021B9934((char *)flow->pokeCon, ((u8 *)q)[4]);
    if (!BTL_POKEPARAM_IsFainted(m) && !BTL_POKEPARAM_IsTransformed(m)) {
        t = func_021D59B4(m, 0x13);
        if (t != ((u8 *)q)[5]) {
            if (q->f) BTL_SERVER_FLOW_PushAbilityPopupIn(flow, m);
            BTL_POKEPARAM_ChangeForm(m, ((u8 *)q)[5]);
            BTL_SERVER_CMD_Push(flow->cmdQueue, 0x4f, ((u8 *)q)[4], ((u8 *)q)[5]);
            func_021C99A0(flow, (const struct Msg *)((u8 *)q + 8));
            if (q->f) BTL_SERVER_FLOW_PushAbilityPopupOut(flow, m);
            return 1;
        }
    }
    return 0;
}














/* command handler: copy the argument byte of the command into the state block */
u8 func_021CA7C4(BtlServerFlow *flow, u8 *cmd)
{
    flow->curTurnState[4] = cmd[4];
    return 1;
}














/* command handler: latch the state flag once */
u8 func_021CA7D4(BtlServerFlow *flow, void *cmd)
{
    BattleState *st = (BattleState *)flow->curTurnState;

    if (!st->flag)
        st->flag = 1;
    return 1;
}











int func_021CA7F4(BtlServerFlow *flow, u8 *a, u8 b, const u8 *q, void *out)
{
    u32 mode = BTL_MAIN_GetRule(flow->mainModule);
    u32 id = 31;
    if (!((struct Flags *)(q + 16))->a) id = func_021CB214(flow, a, (u8 *)q);
    func_0689CB3C(out);
    flow->reserveSlot = 6;
    switch (mode) {
    case 0: default:
        id = func_021CA8F8(flow, a, b, (u8 *)q, id, out);
        break;
    case 1:
        id = func_021CAA58(flow, a, b, (u8 *)q, id, out);
        break;
    case 2:
        id = func_021CACF4(flow, a, b, (u8 *)q, id, out);
        break;
    case 3:
        id = func_021CA8F8(flow, a, b, (u8 *)q, id, out);
        break;
    }
    if (id == 1) {
        u8 *m = func_0689CC70(out, 0);
        if (m) flow->reserveSlot = func_0689D5F4(flow->posPoke, BTL_POKEPARAM_GetPokeId(m));
        if (!func_021CAFD8(flow, mode, a, (const u16 *)q, b, out)) id = 0;
    }
    return id;
}







int func_021CA8F8(BtlServerFlow *flow, u8 *a, int unused, u8 *q, int id, void *out)
{
    u8 n = func_021B8D8C(flow->mainModule, flow->pokeCon, BTL_POKEPARAM_GetPokeId(a));
    u8 *b;
    switch (*(u32 *)(q + 12)) {
    case 0: case 3: case 4: case 5: case 9:
        if (id == 31) b = func_021CB174(flow, n, 0);
        else b = (u8 *)func_021B9934((char *)flow->pokeCon, id);
        func_0689CB48(out, b);
        return 1;
    case 1: case 7:
        if (id == 31) func_0689CB48(out, a);
        else func_0689CB48(out, (void *)func_021B9934((char *)flow->pokeCon, id));
        return 1;
    case 8:
        func_0689CB48(out, a);
        func_0689CB48(out, func_021CB174(flow, n, 0));
        return 2;
    case 13:
        if (id != 31) {
            func_0689CB48(out, (void *)func_021B9934((char *)flow->pokeCon, id));
            return 1;
        }
        return 0;
    case 2: case 6: case 10: case 11: case 12: default:
        return 0;
    }
}






u8 func_021CAA24(BtlServerFlow *flow, u8 *q, int m, u8 n, u8 value)
{
    if (((struct Obj09977 *)q)->f0 == 174) {
        if (((struct Obj09977 *)q)->fC == 0) {
            if (n == value || value == 6)
                return BTL_CALC_DecideMoveTarget(flow->mainModule, (int)flow->pokeCon, m, 174);
        } else if (((struct Obj09977 *)q)->fC == 7 && n != value) {
            value = n;
        }
    }
    return value;
}








int func_021CAA58(BtlServerFlow *flow, u8 *a, u8 move, u8 *q, int id, void *out)
{
    u8 n = func_021B8D8C(flow->mainModule, flow->pokeCon, BTL_POKEPARAM_GetPokeId(a));
    u8 key = func_021CAA24(flow, q, (int)a, n, move);
    u8 *b;
    u8 selected;
    switch (*(u32 *)(q + 12)) {
    case 0:
        b = func_021B98A4(flow->pokeCon, key);
        break;
    case 3:
        b = func_021B98A4(flow->pokeCon, key);
        break;
    case 9:
        b = func_021CB174(flow, n, (u8)BTL_CALC_Random(2));
        break;
    case 5:
        func_0689CB48(out, func_021CB174(flow, n, (u8)0));
        func_0689CB48(out, func_021CB174(flow, n, (u8)1));
        return 2;
    case 4:
        func_0689CB48(out, func_021CB1A4(flow, n));
        func_0689CB48(out, func_021CB174(flow, n, (u8)0));
        func_0689CB48(out, func_021CB174(flow, n, (u8)1));
        return 3;
    case 8:
        func_0689CB48(out, a);
        func_0689CB48(out, func_021CB1A4(flow, n));
        func_0689CB48(out, func_021CB174(flow, n, (u8)0));
        func_0689CB48(out, func_021CB174(flow, n, (u8)1));
        return 3;
    case 7:
        if (id == 31) func_0689CB48(out, a);
        else func_0689CB48(out, (void *)func_021B9934((char *)flow->pokeCon, id));
        return 1;
    case 1:
        func_0689CB48(out, func_021B98A4(flow->pokeCon, key));
        return 1;
    case 2:
        func_0689CB48(out, func_021CB1A4(flow, n));
        return 1;
    case 13:
        if (id != 31) {
            b = (u8 *)func_021B9934((char *)flow->pokeCon, id);
            break;
        }
        return 0;
    case 6: case 10: case 11: case 12: default:
        return 0;
    }
    if (b) {
        selected = func_021CB1D4(flow, a, q, BTL_POKEPARAM_GetPokeId(b));
        if (selected != 31) b = (u8 *)func_021B9934((char *)flow->pokeCon, selected);
        func_0689CB48(out, b);
        return 1;
    }
    return 0;
}










int func_021CACF4(BtlServerFlow *flow, u8 *a, u8 move, u8 *q, long id, void *out)
{
    u32 i, count;
    u8 n = func_021B8D8C(flow->mainModule, flow->pokeCon, BTL_POKEPARAM_GetPokeId(a));
    u8 *b = (u8 *)func_021B99E0(n);
    u8 key = func_021CAA24(flow, q, (int)a, n, move);
    u8 selected;
    switch (*(u32 *)(q + 12)) {
    case 0:
        b = func_021B98A4(flow->pokeCon, key);
        break;
    case 3:
        b = func_021B98A4(flow->pokeCon, key);
        break;
    case 9:
        selected = BTL_CALC_Random(*(u16 *)b);
        b = func_021B98A4(flow->pokeCon, ((struct Record *)b)->ids[selected]);
        break;
    case 5:
        for (i = 0; i < *(u16 *)b; i++)
            func_0689CB48(out, func_021B98A4(flow->pokeCon, b[4 + i]));
        return (u8)*(u16 *)b;
    case 4: {
        long j;
        i = 0;
        count = 0;
        for (; i < *(u16 *)b; i++) {
            func_0689CB48(out, func_021B98A4(flow->pokeCon, b[4 + i]));
            count++;
        }
        for (j = 0; (u32)j < *(u16 *)(b + 2); j++) {
            if (n != b[7 + j]) {
                func_0689CB48(out, func_021B98A4(flow->pokeCon, b[7 + j]));
                count++;
            }
        }
        return (u8)count;
    }
    case 8:
        func_0689CB48(out, a);
        for (i = 0; i < 3; i++) {
            selected = BTL_MAIN_GetOwnLanePos(n, (u8)i);
            if (selected != n) func_0689CB48(out, func_021B98A4(flow->pokeCon, selected));
        }
        func_0689CB48(out, func_021CB174(flow, n, 0));
        func_0689CB48(out, func_021CB174(flow, n, 1));
        func_0689CB48(out, func_021CB174(flow, n, 2));
        return 6;
    case 7:
        if (id == 31) func_0689CB48(out, a);
        else func_0689CB48(out, (void *)func_021B9934((char *)flow->pokeCon, id));
        return 1;
    case 1:
        func_0689CB48(out, func_021B98A4(flow->pokeCon, key));
        return 1;
    case 2:
        func_0689CB48(out, func_021B98A4(flow->pokeCon, key));
        return 1;
    case 13:
        if (id != 31) {
            b = (u8 *)func_021B9934((char *)flow->pokeCon, id);
            break;
        }
        return 0;
    case 6: case 10: case 11: case 12: default:
        return 0;
    }
    if (b) {
        selected = func_021CB1D4(flow, a, q, BTL_POKEPARAM_GetPokeId(b));
        if (selected != 31) b = (u8 *)func_021B9934((char *)flow->pokeCon, selected);
        func_0689CB48(out, b);
        return 1;
    }
    return 0;
}










int func_021CAFD8(BtlServerFlow *flow, u32 mode, void *m, const u16 *item, u8 self, void *out)
{
    int count;
    u8 j;
    void *previous;
    int position;
    u16 target;
    u8 indices[6];
    int members[3];
    int d1;
    u8 i;
    u8 choice;
    int d0;
    u32 n;
    if (BTL_CALC_GetFightersPerSide(mode) <= 1 || func_0689CD38(out) != 1) goto fail;
    previous = func_0689CC70(out, 0);
    if (!BTL_POKEPARAM_IsFainted(previous)) goto fail;
    if (func_021B9A24(BTL_POKEPARAM_GetPokeId(m), BTL_POKEPARAM_GetPokeId(previous))) goto fail;
    position = func_021B8D8C(flow->mainModule, flow->pokeCon, BTL_POKEPARAM_GetPokeId(m));
    func_0689CC14(out, previous);
    if (WAZA_TOOL_GetFlag((void *)*item, 0xb)) target = 0x600 | position;
    else target = 0x100 | position;
    n = BTL_MAIN_DecodeMessageCode(flow->mainModule, target, indices);
    for (j = 0; j < 3; j++) members[j] = 0;
    count = 0;
    for (i = count; i < n; i++) {
        members[count] = (int)func_021B98A4(flow->pokeCon, indices[i]);
        if (!BTL_POKEPARAM_IsFainted((void *)members[count])) {
            indices[count] = indices[i];
            count = (u8)(count + 1);
        }
    }
    if (!count) return 0;
    if (count != 2) choice = 0;
    else {
        d0 = indices[0] - self;
        if (d0 < 0) d0 *= -1;
        d1 = indices[1] - self;
        if (d1 < 0) d1 *= -1;
        if (d0 == d1) {
            d0 = func_021D59B4((void *)members[0], 13);
            d1 = func_021D59B4((void *)members[1], 13);
        }
        if (d0 < d1) choice = 0;
        else if (d1 < d0) choice = 1;
        else choice = BTL_CALC_Random(2);
    }
    if (members[choice]) { func_0689CB48(out, (void *)members[choice]); return 1; }
fail:
    return 0;
}











/*
 * interface: BTL_MAIN_GetEnemyLanePosFromWork forwards live r1/r2 to BTL_MAIN_GetEnemyLanePos and returns r0.
 */
void *func_021CB174(BtlServerFlow *flow, u8 n, int k)
{
    u8 out[2];
    func_021B8E28((u8 *)flow->mainModule, BTL_MAIN_GetEnemyLanePosFromWork(flow->mainModule, n, k), out + 1, out);
    return (void *)func_021B9BF0(*(void **)(BTL_SERVER_GetClientChecked(flow->server, out[1]) + 4), out[0]);
}











void *func_021CB1A4(BtlServerFlow *flow, u8 n)
{
    u8 out[2];
    func_021B8E28((u8 *)flow->mainModule, func_021B8CB0(flow->mainModule, n), out + 1, out);
    return (void *)func_021B9BF0(*(void **)(BTL_SERVER_GetClientChecked(flow->server, out[1]) + 4), out[0]);
}












u8 func_021CB1D4(BtlServerFlow *flow, u8 *a, u8 *b, u32 d)
{
    u32 s = func_021CC8D8(&flow->lock, 611);
    u8 r = func_021CB274(flow, a, b, d);
    func_021CC95C((u32 *)&flow->lock, s, 613);
    return r;
}












u8 func_021CB214(BtlServerFlow *flow, u8 *a, u8 *b)
{
    u8 r;
    BTL_EVENT_PushVarFrame(631);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x16, b[6]);
    BTL_EVENT_SetVarReadOnly(0x12, ((struct Obj13345 *)b)->f0);
    BTL_EVENT_SetVarOnce(4, 0x1f);
    BTL_EVENT_SetVarOnce(0x50, 0);
    func_021D70F0(flow, 0x29);
    r = BTL_EVENT_GetVar(4);
    BTL_EVENT_PopVarFrame(639);
    return r;
}












u8 func_021CB274(BtlServerFlow *flow, u8 *a, u8 *b, u32 d)
{
    u8 r;
    BTL_EVENT_PushVarFrame(656);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x16, b[6]);
    BTL_EVENT_SetVarReadOnly(0x12, ((struct Obj13346 *)b)->f0);
    BTL_EVENT_SetVarOnce(4, d);
    func_021D70F0(flow, 0x2a);
    r = BTL_EVENT_GetVar(4);
    BTL_EVENT_PopVarFrame(663);
    if (r == d) r = 0x1f;
    return r;
}











/*
 * note: final push 2026-10-05 G1R6: closed. The loop count n is a u16 local and
 *   func_021B9B94 is declared u8 (its matched definition returns u8). A narrow bound with
 *   narrow counters gives unsigned compares and keeps the loop-3 counter store before the
 *   bound reload. Earlier drafts kept n u32 (4 B off) or u8 (signed compares, 35 B off).
 *   Same shape as ov021 FIELD_MSGBG_DrawFrameBmp (u16 bound, u16 counter). A separate u16 counter i3
 *   for loop 3 gives the spill slots of the counter and of id.
 */
void func_021CB2D4(BtlServerFlow *flow, u8 *a, u32 b, Rec_021CAA58 *rec)
{
  u32 scale;
  u16 n;
  u32 share;
  u16 lvl;
  u16 lvl2;
  u32 k;
  u16 i;
  u8 id;
  u16 i3;
  u32 half;
  u16 cnt;
  u32 avg;
  int n2;
  u32 n3;
  u8 cnt2;
  u16 j;
  u16 m;
  u8 q;
  u8 *t;

  scale = BTL_CALC_CalcDefeatExp((void *)b);
  n = func_021B9B94((struct Q1 *)a);
  cnt = 0;
  if (BTL_MAIN_GetCompetitor(flow->mainModule) == (void *) 1)
    scale = scale * 15 / 10;
  for (i = 0, j = 0; i < 6; i++)
    func_02082BCC(rec + i, j, 12);
  for (j = 0; j < n; j++)
  {
    t = func_021B9C00((struct S2 *)a, (u8) j);
    if (BTL_POKEPARAM_IsFainted(t) == 0 && (u32)BTL_POKEPARAM_GetItem((struct QI *)t) == 0xd8)
      cnt++;
  }
  if (cnt)
  {
    half = scale >> 1;
    scale = scale - half;
    avg = half / cnt;
    if (avg == 0)
      avg = 1;
    for (j = 0; j < n; j++)
    {
      t = func_021B9C00((struct S2 *)a, (u8) j);
      if (BTL_POKEPARAM_IsFainted(t) == 0 && (u32)BTL_POKEPARAM_GetItem((struct QI *)t) == 0xd8)
        rec[j].value = avg;
    }
  }
  n2 = (int)BTL_EVENT_GetClientPartyCount((unsigned char *)b);
  cnt2 = 0;
  for (j = 0; j < n2; j++)
  {
    if (BTL_POKEPARAM_IsFainted(func_021B9934(flow->pokeCon, (u32)BTL_EVENT_GetClientPartySlotId((u8 *)b, (u8) j))) == 0)
      cnt2++;
  }
  share = scale / cnt2;
  if (share == 0)
    share = 1;
  for (i3 = 0; i3 < n; i3++)
  {
    t = func_021B9C00((struct S2 *)a, (u8) i3);
    if (BTL_POKEPARAM_IsFainted(t) == 0)
    {
      id = BTL_POKEPARAM_GetPokeId(t);
      n3 = n2;
      for (q = 0; q < n3; q++)
      {
        if (id == (u32)BTL_EVENT_GetClientPartySlotId((u8 *)b, q))
          rec[i3].value += share;
      }
    }
  }
  for (j = 0; j < n; j++)
  {
    if (rec[j].value != 0)
    {
      void *save;
      void *v28;
      u32 v24;

      v24 = (u32)func_021B871C(flow->mainModule);
      t = func_021B9C00((struct S2 *)a, (u8) j);
      v28 = BTL_POKEPARAM_GetMon(t);
      lvl = func_021D59B4(t, 15);
      lvl2 = func_021D59B4((void *) b, 15);
      rec[j].value = func_021CB55C(t, rec[j].value, lvl, lvl2);
      if (POKE_TOOL_IsOwnedByPlayer(v28, (u32)v24) == 0)
      {
        save = (void *) func_02017E1C(v28, 12, 0);
        if ((u32) save != func_02008564((const struct Sub0200852CObj *)v24))
          k = 0x1b33;
        else
          k = 0x1800;
        rec[j].value = BTL_CALC_MulRatio(rec[j].value, k);
        rec[j].flag = 1;
      }
      if ((u32)BTL_POKEPARAM_GetItem((struct QI *)t) == 0xe7)
      {
        rec[j].value = BTL_CALC_MulRatio(rec[j].value, 0x1800);
        rec[j].flag = 1;
      }
      rec[j].value = GPOWER_ApplyExpRate(rec[j].value);
    }
  }
  for (m = 0; m < n; m++)
  {
    if (rec[m].value != 0)
      func_021CB5F0((u32 *)func_021B9BF0((struct S2 *)a, (u8) m), (u8 *)b, (u8 *)(rec + m));
  }
}











/*
 * note: the second block squares y in place (y *= y) and then multiplies the
 *   root by y: the product lands in the root copy register as in the original.
 *   Found in final push 2026-10-05 G1R4 after the Product helper and every
 *   named-yy form kept the product in the squared register.
 */
u32 func_021CB55C(void *p, u32 a, u16 b, u16 c)
{
  int tmp;
  u32 tmp1;
  u32 r, lim;
  u32 x = (2 * c) + 10;
  u32 y = (c + b) + 10;
  u32 t1 = ((u32) (func_0207C7B4((int) ((x > 0) ? ((x * (1 << 12)) + 0.5f) : ((x * (1 << 12)) - 0.5f))) * (x * x))) >> 12;
  tmp = (int) ((y > 0) ? ((y * (1 << 12)) + 0.5f) : ((y * (1 << 12)) - 0.5f));
  tmp1 = func_0207C7B4(tmp);
  y *= y;
  r = ((a * t1) / ((y * tmp1) >> 12)) + 1;
  lim = BTL_POKEPARAM_GetMaxLevelExp(p);
  if (r > lim)
    r = lim;
  return r;
}












/*
 * Builds the six per-party "battle handicap" bytes and writes them to the
 * output record.  Reads the record's u16 fields 0xc and 0x13, asks the
 * battle dispatcher func_02019C90 for a base value per entry of the six
 * entry table at 0x021EFDC0 (6-byte records: u8 at +0, u16 at +2, u16 at
 * +4), doubles them when the mode field 0x12 is 0xd7, then walks the table
 * again to add func_021D805C's value for the entry whose +4 field matches
 * and to fold each result into the savedata record 0x97 through the
 * func_02017E1C/POKE_TOOL_SetPartyValue read/write pair, clamped at 0xff.  The final
 * switch on the loop index is the image's, not a source choice: the table
 * at 0x021CB6F4 is six four-byte arms, case i storing the byte at
 * a2[5 + i].  Ends by releasing the savedata record.
 */
void func_021CB5F0(u32 *a0, u8 *a1, u8 *a2)
{
    u8 buf[6];
    u8 i;
    u16 v6;
    u32 m;
    u32 t;
    void *rec;
    u32 sv;

    m = BTL_POKEPARAM_GetSpecies((struct QF *)a1);
    v6 = (u16)func_021D59B4(a1, 0x13);
    for (i = 0; i < 6; i++) {
        buf[i] = (u8)func_02019C90(m, v6, g_021EFDC0[i].f0);
    }
    if (BTL_POKEPARAM_GetItem((struct QI *)a0) == 0xd7) {
        for (i = 0; i < 6; i++) {
            buf[i] = buf[i] * 2;
        }
    }
    for (i = 0; i < 6; i++) {
        t = g_021EFDC0[i].f4;
        if (t == BTL_POKEPARAM_GetItem((struct QI *)a0)) {
            buf[i] = (u8)(buf[i] + (u8)func_021D805C((void *)t, 2));
        }
    }
    rec = BTL_POKEPARAM_GetMon(a0);
    sv = POKE_TOOL_DecodePartyParam(rec);
    if (func_02017E1C(rec, 0x97, 0) != 0) {
        for (i = 0; i < 6; i++) {
            buf[i] = buf[i] * 2;
        }
    }
    for (i = 0; i < 6; i++) {
        u8 v;
        u32 w;

        v = buf[i];
        if (v == 0) {
            continue;
        }
        t = g_021EFDC0[i].f2;
        w = func_02017E1C(rec, t, 0) + v;
        if (w > 0xff) {
            w = 0xff;
        }
        POKE_TOOL_SetPartyValue(rec, t, w);
        switch (i) {
        case 0: a2[5] = v; break;
        case 1: a2[6] = v; break;
        case 2: a2[7] = v; break;
        case 3: a2[8] = v; break;
        case 4: a2[9] = v; break;
        case 5: a2[0xa] = v; break;
        }
    }
    POKE_TOOL_EncodePartyParam(rec, sv);
}











/*
 * lever: the local holding the u8 result of func_021B8DDC is a u8 (not int);
 *   its spill reload then stays below the outgoing stack-argument stores
 *   (ov093 021CD64C call at +0xDA) and the stack parameter load moves ahead
 *   of the p copy at entry. Both residues closed by this one type change.
 *   See docs/idioms/a-narrow-spilled-parameter-keeps-its-reload-below-a-store.md.
 * note: 2026-10-05 wave P2 lane Q8. Dropped the (void)(&pos) no-op from the
 *   older draft (it changed nothing).
 */
int func_021CB730(BtlServerFlow *flow, u8 *a, u16 move, u8 arg, u8 slot)
{
  u32 n;
  char *party;
  u8 side;
  u32 monId;
  Condition initial;
  u8 condition;
  u8 *mon;
  unsigned long lock;
  u32 result;
  unsigned long state;
  u32 mark;
  u16 pos;
  u32 allowed;
  u32 i;
  const Entry_021CAA58 *e;
  u8 *tmp;
  u8 *tmp1;
  side = func_021B8DDC(BTL_POKEPARAM_GetPokeId(a));
  mon = 0;
  initial = 0;
  if (slot != 6)
  {
    party = func_021B9AEC(*((char **) &flow->pokeCon), side);
    n = func_021B99B8(*((void **) &flow->mainModule), side);
    mon = (u8 *)func_021B9BF0((struct S2 *)party, slot);
    monId = BTL_POKEPARAM_GetPokeId(mon);
    state = func_0689D5C8(flow->posPoke, monId);
    if (slot >= n)
      initial = 2;
    condition = (u8) initial;
    if (((BTL_MAIN_GetRule(*((void **) &flow->mainModule)) == 3) && (condition == 2)) && (slot < 3))
      condition = 1;
  }
  if ((*((u32 *) &flow->bagMode)) != 1)
  {
    BTL_SERVER_CMD_PushVariable(*((void **) &flow->cmdQueue), 0x5a, 0x21, side, move, 0xffff0000);
    if (func_021D805C((void *)move, 15) == 4)
    {
      if (func_021CBA40(flow, a, move))
        func_021B9090(*((u8 **) &flow->mainModule), side, move);
      return 0;
    }
    if (func_021D805C((void *)move, 7) == 3)
    {
      func_021B9090(*((u8 **) &flow->mainModule), side, move);
      return 1;
    }
  }
  else
  {
    BTL_SERVER_CMD_PushVariable(*((void **) &flow->cmdQueue), 0x5a, 0x24, side, monId, move, 0xffff0000);
    if (side == func_021B8FF4(*((u8 **) &flow->mainModule)))
      func_021BA1B4(*((void **) &flow->mainModule), 0x6f);
  }
  allowed = ((condition == 0) && (state != 6)) ? (1) : (0);
  if (!allowed)
  {
    for (i = 0; i < 23; i++)
    {
      e = data_021EFDE4;
      e = e + i;
      if ((e->exact && (move == e->id)) || ((!e->exact) && func_021D805C((void *)move, e->id)))
      {
        if (e->mode == 0)
        {
          allowed = 1;
          break;
        }
        if (((e->mode == 1) && (condition < 2)) && (state != 6))
        {
          allowed = 1;
          break;
        }
      }
    }

  }
  if (!allowed)
  {
    BTL_SERVER_CMD_PushVariable(*((void **) &flow->cmdQueue), 0x5a, 0xc4, 0xffff0000);
    return 0;
  }
  if ((*((u32 *) &flow->bagMode)) == 1)
  {
    if (state != 6)
      BTL_SERVER_CMD_Push(*((void **) &flow->cmdQueue), 0x4d, state, 0x282);
    for (i = 0; i < 23; i++)
    {
      if (data_021EFDE4[i].exact && (move == data_021EFDE4[i].id))
      {
        result = 0;
        if (!func_021C8338(flow, monId))
        {
          pos = BTL_SERVER_CMD_Reserve(*((void **) &flow->cmdQueue), 0x4d);
          result = data_021EFDE4[i].call(flow, mon, move, 0, arg);
          if (result == 1)
          {
            BTL_SERVER_CMD_FillReserved(*((void **) &flow->cmdQueue), pos, 0x4d, state, 0x25e);
            BTL_SERVER_CMD_Push(*((void **) &flow->cmdQueue), 0x4c, 0x236);
            return 0;
          }
        }
        if (result == 0)
          BTL_SERVER_CMD_PushVariable(*((void **) &flow->cmdQueue), 0x5a, 0x44, 0xffff0000);
        BTL_SERVER_CMD_Push(*((void **) &flow->cmdQueue), 0x4c, 0x236);
        return 0;
      }
    }

  }
  mark = 0;
  pos = BTL_SERVER_CMD_Reserve(*((void **) &flow->cmdQueue), 0x4d);
  lock = func_021CC8D8(&flow->lock, 1217);
  for (i = 0; i < 23; i++)
  {
    e = data_021EFDE4 + i;
    result = func_021D805C((void *)move, e->id);
    if (result && e->call(flow, mon, move, result, arg))
      mark = 1;
  }

  if (mark)
  {
    BTL_SERVER_CMD_FillReserved(*((void **) &flow->cmdQueue), pos, 0x4d, state, (u16) ((state != 6) ? (0x25e) : (0x292)));
    if ((*((u32 *) &flow->bagMode)) != 1)
    {
      func_021B9090(*((u8 **) &flow->mainModule), side, move);
      func_021BA250(*((char **) &flow->mainModule), mon, move);
    }
  }
  else
    BTL_SERVER_CMD_PushVariable(*((void **) &flow->cmdQueue), 0x5a, 0x44, 0xffff0000);
  func_021CC95C((u32 *)&flow->lock, lock, 1246);
  BTL_SERVER_CMD_Push(*((void **) &flow->cmdQueue), 0x4c, 0x236);
  return 0;
}









/*
 * lever: Separate six-byte selection and two-byte output arrays reproduce
 * the unaligned stack base; a u16 third parameter pins its early home store.
 */
int func_021CBA40(BtlServerFlow *flow, void *a, u16 b)
{
    void *m = 0;
    u8 chosen = 6;
    u8 buf[6];
    u8 out[2];
    u8 count;
    u8 i;
    u8 result;
    u8 flag;
    count = BTL_MAIN_DecodeMessageCode(flow->mainModule, (unsigned short)((chosen << 8) | func_021B8D8C(flow->mainModule, flow->pokeCon, BTL_POKEPARAM_GetPokeId(a))), buf);
    for (i = 0; i < count; i++) {
        m = func_021B98A4((char *const *)flow->pokeCon, buf[i]);
        if (!BTL_POKEPARAM_IsFainted(m)) { chosen = buf[i]; break; }
    }
    if (!BTL_MAIN_GetCompetitor(flow->mainModule)) {
        if (chosen != 6) {
            result = func_021CBB34(flow, a, m, b, &out[1], &out[0]);
            if (result) {
                flow->flowResult = 6;
                flow->chosenSlot = chosen;
                flag = BTL_MAIN_CheckZukanSeen(flow->mainModule, m) == 0 ? 1 : 0;
                BTL_EVENT_StartClientPalAnm(m, b);
            } else { flag = 0; }
            BTL_SERVER_CMD_Push(flow->cmdQueue, 0x46, chosen, out[1], result, flag, out[0], b);
        }
        return 1;
    }
    if (chosen != 6) BTL_SERVER_CMD_Push(flow->cmdQueue, 0x47, chosen, b);
    return 0;
}









/*
 * lever: A u16 mode homes its spill early; named u16 form avoids an
 * argument copy. Ternary count selection shares the flag read across
 * the preceding threshold branch and settles the register allocation.
 */
int func_021CBB34(BtlServerFlow *flow, void *q, void *m, u16 mode, u8 *out, u8 *flag)
{
    u32 a, t;
    int rate, factor, v;
    u32 count, i;
    u16 species, form;
    *flag = 0;
    if (mode == 1) { *out = 3; return 1; }
    a = func_021D59B4((void *)m, 14) * 3;
    t = a - func_021D59B4((void *)m, 13) * 2;
    v = (int)(t != 0 ? 0.5f + (float)(t << 12) : (float)(t << 12) - 0.5f);
    if (func_021BA1A8(flow->mainModule, 32)) {
        factor = func_021CBCF4(flow);
        v = ((s64)v * factor + 0x800) >> 12;
    }
    species = BTL_POKEPARAM_GetSpecies((void *)m);
    form = func_021D59B4((void *)m, 19);
    v *= (u16)func_02019C90(species, form, 8);
    factor = func_021CBD48(flow, q, (void *)m, mode);
    v = ((s64)v * factor + 0x800) >> 12;
    v = (u32)v / a;
    switch (BTL_POKEPARAM_GetMajorStatusIndex((void *)m)) {
    case 2: case 3: v = ((s64)v * 0x2800 + 0x800) >> 12; break;
    case 1: case 4: case 5: v = ((s64)v * 0x1800 + 0x800) >> 12; break;
    }
    rate = GPOWER_ApplyCaptureRate(v);
    *flag = func_021CBEA8(flow, rate);
    if (rate >= 0xff000) { *out = *flag ? 1 : 3; return 1; }
    count = *flag ? 1 : 3;
    rate = FX_Div(0x10000000, FX_Sqrt(FX_Sqrt(FX_Div(0xff000, rate)))) >> 12;
    *out = 0;
    for (i = 0; i < count; i++) {
        if (BTL_CALC_Random(0x10000) < (u32)rate) (*out)++;
        else return 0;
    }
    return 1;
}










u32 func_021CBCF4(BtlServerFlow *flow)
{
    u32 v = BTL_MAIN_GetZukanSeenCount((char **)flow->mainModule);
    if (v > 600) return 0x1000;
    if (v > 450) return 0xe66;
    if (v > 300) return 0xccd;
    if (v > 150) return 0xb33;
    if (v > 30) return 0x800;
    return 0x4cd;
}









/*
 * outside covered regions. Its call has no external witness; tu split
 * census reports zero witnesses and no viable partition. The trailing
 * 16 bytes are that veneer, not compiled C.
 */
int func_021CBD48(BtlServerFlow *flow, void *unused, void *q, int k)
{
    u16 n;
    float f;
    int value;
    u8 flag;
    u8 *t;
    switch (k) {
    case 3: return 0x1800;
    case 2: return 0x2000;
    case 6:
        if (BTL_POKEPARAM_HasType(q,10) || BTL_POKEPARAM_HasType(q,6)) return 0x3000;
        break;
    case 7:
        if (func_021BA1A8(flow->mainModule,1)) return 0x3800;
        if (*(int *)(BTL_MAIN_GetFieldSituation((char **)flow->mainModule)+4) == 6) return 0x3800;
        break;
    case 8:
        n = func_021D59B4(q,15);
        if (n < 30) {
            n = 41 - n;
            if (n > 40) n = 40;
            if (n != 0) f = 0.5f + (float)(n << 12);
            else f = (float)(n << 12) - 0.5f;
            return (int)f / 10;
        }
        break;
    case 9:
        if (BTL_MAIN_CheckZukanSeen(flow->mainModule,q)) return 0x3000;
        break;
    case 10:
        value = flow->turnCount*0x4cd+0x1000;
        if (value > 0x4000) value = 0x4000;
        return value;
    case 13:
        t = (u8 *)BTL_MAIN_GetFieldSituation((char **)flow->mainModule);
        flag = TIMEZONE_GetTimeZoneOfHour(t[9],t[12]);
        if ((unsigned)(*(int *)t - 4) <= 1) return 0x3800;
        if (func_0689C9A0(*(int *)t)) {
            if ((u8)(flag + 253) <= 1) return 0x3800;
        }
        break;
    case 15:
        if (flow->turnCount == 0) return 0x5000;
        break;
    default: break;
    }
    return 0x1000;
}












/*
 * note:     the divide by 6 belongs to the fixed-point multiply's statement
 *           (`x = FX_MUL(x, k) / 6;`); the `>> 12` goes inside the compare.
 *           A separate `q = x / 6;` statement lets the compiler move the
 *           divide after the call, and a separate shift statement moves the
 *           shift before it.
 */
int func_021CBEA8(BtlServerFlow *flow, int x)
{
    u32 v = BTL_MAIN_GetZukanSeenCount((char **)flow->mainModule);
    int k;
    if (v > 600) k = 0x2800;
    else if (v > 450) k = 0x2000;
    else if (v > 300) k = 0x1800;
    else if (v > 150) k = 0x1000;
    else if (v > 30) k = 0x800;
    else return 0;
    if (x > 0xff000) x = 0xff000;
    x = (int)(((long long)x * k + 0x800) >> 12) / 6;
    if (BTL_CALC_Random(256) < (u32)(x >> 12))
        return 1;
    return 0;
}












/* 021CBF30  stack-arg wrapper: func_021CC350(a, b, c, d, 0x2) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #2; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF30(BtlServerFlow *flow, void *b, int c, int d) { func_021CC350(flow, b, c, d, 0x2); }












/* 021CBF40  stack-arg wrapper: func_021CC350(a, b, c, d, 0x5) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #5; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF40(BtlServerFlow *flow, void *b, int c, int d) { func_021CC350(flow, b, c, d, 0x5); }












/* 021CBF50  stack-arg wrapper: func_021CC350(a, b, c, d, 0x4) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #4; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF50(BtlServerFlow *flow, void *b, int c, int d) { func_021CC350(flow, b, c, d, 0x4); }












/* 021CBF60  stack-arg wrapper: func_021CC350(a, b, c, d, 0x3) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #3; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF60(BtlServerFlow *flow, void *b, int c, int d) { func_021CC350(flow, b, c, d, 0x3); }












/* 021CBF70  stack-arg wrapper: func_021CC350(a, b, c, d, 0x1) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #1; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF70(BtlServerFlow *flow, void *b, int c, int d) { func_021CC350(flow, b, c, d, 0x1); }












/* 021CBF80  stack-arg wrapper: func_021CC350(a, b, c, d, 0x6) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #6; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF80(BtlServerFlow *flow, void *b, int c, int d) { func_021CC350(flow, b, c, d, 0x6); }











/* 021CBF90  stack-arg wrapper: func_021CC398(a, b, c, d, 0x7) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #7; str r4, [sp]; bl func_021CC398; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF90(BtlServerFlow *flow, void *b, int c, int d) { func_021CC398(flow, b, c, d, 0x7); }











int func_021CBFA0(BtlServerFlow *flow, u8 *q)
{
    u8 m;
    u8 *w;
    Word_021CAA58_td t;
    m = func_021B9A40(BTL_POKEPARAM_GetPokeId(q));
    t = BTLV_CORE_MakeSlotKind2Index(5);
    if (func_06898C10(m, 3, t)) {
        w = func_021C88A4(flow, 4, 0x1f);
        func_021C8838(w + 4, 1, 0x88);
        func_021C8860((struct S_p12 *)(w + 4), m);
        func_021C88C8(flow, w);
        return 1;
    }
    return 0;
}










/*
 * The switch stores into w+6 in every arm (as func_021CC2C0 does), which
 * lays the arms out as the original has them; the default arm calls
 * func_021D805C again. s is narrow: as u32 (or a pointer, as the sibling
 * handlers func_021CC2C0/CC178/CC214 declare it) its `ldr r0,[sp]` reload
 * is hoisted above `strb r7,[r4,#4]`; u16 and u8 both keep it below.
 * Nothing in the image fixes the width; u16 chosen. The function sits in
 * the handler table at 0x021EFE28.
 */
int func_021CC008(BtlServerFlow *flow, u8 *q, u16 s)
{
    int id;
    u8 *w;
    u32 r;
    if (BTL_POKEPARAM_IsFainted(q)) {
        id = BTL_POKEPARAM_GetPokeId(q);
        w = func_021C88A4(flow, 0x2c, id);
        w[4] = id;
        r = func_021D805C((void *)s, 0x3a);
        switch (r) {
        case 0xff:
            ((struct Obj06229 *)w)->f6 = func_021D59B4(q, 0xe);
            break;
        case 0xfe:
            ((struct Obj06229 *)w)->f6 = BTL_CALC_DivideMaxHpMin1(q, 2);
            break;
        case 0xfd:
            ((struct Obj06229 *)w)->f6 = BTL_CALC_DivideMaxHpMin1(q, 4);
            break;
        default:
            ((struct Obj06229 *)w)->f6 = func_021D805C((void *)s, 0x3a);
            break;
        }
        func_021C8838(w + 8, 2, 3);
        func_021C8860((struct S_p12 *)(w + 8), id);
        func_021C88C8(flow, w);
        func_021C84E0(flow, id);
        return 1;
    }
    return 0;
}










/* 021CC098  stack-arg wrapper: func_021CC438(a, b, c, d, 0x1) */
void func_021CC098(BtlServerFlow *flow, void *b, int c, u8 d) { func_021CC438(flow, b, c, d, 0x1); }










/* 021CC0A8  stack-arg wrapper: func_021CC438(a, b, c, d, 0x2) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #2; str r4, [sp]; bl func_021CC438; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CC0A8(BtlServerFlow *flow, void *b, int c, u8 d) { func_021CC438(flow, b, c, d, 0x2); }










/* 021CC0B8  stack-arg wrapper: func_021CC438(a, b, c, d, 0x3) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #3; str r4, [sp]; bl func_021CC438; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CC0B8(BtlServerFlow *flow, void *b, int c, u8 d) { func_021CC438(flow, b, c, d, 0x3); }










/* 021CC0C8  stack-arg wrapper: func_021CC438(a, b, c, d, 0x4) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #4; str r4, [sp]; bl func_021CC438; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CC0C8(BtlServerFlow *flow, void *b, int c, u8 d) { func_021CC438(flow, b, c, d, 0x4); }










/* 021CC0D8  stack-arg wrapper: func_021CC438(a, b, c, d, 0x5) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #5; str r4, [sp]; bl func_021CC438; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CC0D8(BtlServerFlow *flow, void *b, int c, u8 d) { func_021CC438(flow, b, c, d, 0x5); }










/* 021CC0E8  stack-arg wrapper: func_021CC438(a, b, c, d, 0x6) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #6; str r4, [sp]; bl func_021CC438; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CC0E8(BtlServerFlow *flow, void *b, int c, u8 d) { func_021CC438(flow, b, c, d, 0x6); }










int func_021CC0F8(char *p, void *m, int c, int n)
{
    int flag;

    flag = 0;
    if (BTL_POKEPARAM_TestContFlag(m, 9) == 0) {
        BTL_POKEPARAM_SetContFlag(m, 9);
        BTL_SERVER_CMD_Push(((struct Obj09981 *)p)->fC, 0x19, BTL_POKEPARAM_GetPokeId(m), 9);
        flag = 1;
    }
    if (n > 1) {
        if (BTL_POKEPARAM_AddCritStage(m, n - 1) != 0) {
            BTL_SERVER_CMD_Push(((struct Obj09981 *)p)->fC, 0xe, BTL_POKEPARAM_GetPokeId(m), n - 1);
            flag = 1;
        }
    }
    if (flag) {
        BTL_SERVER_CMD_PushVariable(((struct Obj09981 *)p)->fC, 0x5b, 0x411, BTL_POKEPARAM_GetPokeId(m), 0xffff0000);
        return 1;
    }
    return 0;
}










int func_021CC178(BtlServerFlow *flow, void *m, void *s, int d, u8 n)
{
    u8 id;
    u32 cnt;
    u32 lim;
    u8 *r;

    if (func_021D5450(m) > n) {
        id = BTL_POKEPARAM_GetPokeId(m);
        cnt = BTL_POKEPARAM_GetRealMovePPLost(m, n);
        lim = (u8)func_021D805C(s, 0x3b);
        if (lim != 0x7f && cnt > lim)
            cnt = lim;
        if (cnt != 0) {
            r = (u8 *)func_021C88A4(flow, 9, id);
            r[4] = cnt;
            r[5] = id;
            r[6] = n;
            r[7] |= 2;
            func_021C8838(r + 8, 2, 390);
            func_021C8860((struct S_p12 *)(r + 8), id);
            func_021C8860((struct S_p12 *)(r + 8), BTL_POKEPARAM_GetRealMoveId(m, n));
            func_021C88C8(flow, r);
            return 1;
        }
    }
    return 0;
}










int func_021CC214(BtlServerFlow *flow, void *m, void *s)
{
    u8 id;
    u32 n;
    int ok;
    u32 lim;
    u32 c;
    u32 i;
    u8 *r;

    id = BTL_POKEPARAM_GetPokeId(m);
    lim = (u8)func_021D805C(s, 0x3b);
    ok = 0;
    n = func_021D5450(m);
    for (i = 0; i < n; i++) {
        c = (u32)BTL_POKEPARAM_GetRealMovePPLost(m, (u8)i);
        if (c > lim)
            c = lim;
        if (c != 0) {
            r = (u8 *)func_021C88A4(flow, 9, id);
            r[6] = i;
            r[5] = id;
            r[4] = c;
            r[7] |= 2;
            func_021C88C8(flow, r);
            ok = 1;
        }
    }
    if (ok) {
        r = (u8 *)func_021C88A4(flow, 4, id);
        func_021C8838(r + 4, 2, 393);
        func_021C8860((struct S_p12 *)(r + 4), id);
        func_021C88C8(flow, r);
    }
    return ok;
}









int func_021CC2C0(BtlServerFlow *flow, void *m, void *s)
{
    int id;
    u8 *r;
    u32 k;

    if (BTL_POKEPARAM_IsHpFull(m) == 0 && BTL_POKEPARAM_IsFainted(m) == 0) {
        id = BTL_POKEPARAM_GetPokeId(m);
        r = (u8 *)func_021C88A4(flow, 5, id);
        r[6] = id;
        r[7] = 1;
        k = func_021D805C(s, 0x3a);
        switch (k) {
        case 0xff:
            ((struct Obj05195 *)r)->f4 = func_021D59B4(m, 14);
            break;
        case 0xfe:
            ((struct Obj05195 *)r)->f4 = BTL_CALC_DivideMaxHpMin1(m, 2);
            break;
        case 0xfd:
            ((struct Obj05195 *)r)->f4 = BTL_CALC_DivideMaxHpMin1(m, 4);
            break;
        default:
            ((struct Obj05195 *)r)->f4 = k;
            break;
        }
        func_021C8838(r + 8, 2, 387);
        func_021C8860((struct S_p12 *)(r + 8), id);
        func_021C88C8(flow, r);
        return 1;
    }
    return 0;
}









int func_021CC350(BtlServerFlow *flow, void *m, int c, int d, u32 v)
{
    u8 id;
    Rec_021CC008_td *r;

    if (BTL_POKEPARAM_IsFainted(m) == 0 && BTL_POKEPARAM_HasSick(m, v) != 0) {
        id = BTL_POKEPARAM_GetPokeId(m);
        r = (Rec_021CC008_td *)func_021C88A4(flow, 11, id);
        r->f14 = 1;
        r->f08 = id;
        r->f04 = v;
        func_021C88C8(flow, r);
        return 1;
    }
    return 0;
}









int func_021CC398(BtlServerFlow *flow, void *m, int c, int d, u32 v)
{
    u32 k;
    int ret;
    int id;
    u8 *r;
    int i;

    if (BTL_POKEPARAM_IsFainted(m) == 0) {
        if (func_0689D588(flow->posPoke, BTL_POKEPARAM_GetPokeId(m)) == 0) {
            ret = 0;
            i = 0;
            for (;;) {
                k = func_0689C9E4(i++);
                if (k == 0)
                    break;
                if (BTL_POKEPARAM_HasSick(m, k) != 0) {
                    id = BTL_POKEPARAM_GetPokeId(m);
                    r = (u8 *)func_021C88A4(flow, 11, id);
                    r[0x14] = 1;
                    r[8] = id;
                    ((struct Obj09983 *)r)->f4 = k;
                    func_021C88C8(flow, r);
                    ret = 1;
                }
            }
            return ret;
        }
    }
    return 0;
}








int func_021CC438(BtlServerFlow *flow, void *m, int c, u8 d, u32 e)
{
    int id;
    u8 *r;

    id = BTL_POKEPARAM_GetPokeId(m);
    if (func_0689D5C8(flow->posPoke, id) != 6) {
        if (BTL_POKEPARAM_IsFainted(m) == 0 && func_021D5D14(m, e, d) != 0) {
            r = (u8 *)func_021C88A4(flow, 14, id);
            r[0xf] = 1;
            r[0x10] = id;
            ((struct Obj06230 *)r)->f4 = e;
            r[0xc] = d;
            r[0xe] = 1;
            func_021C88C8(flow, r);
            return 1;
        }
    }
    return 0;
}








u8 func_021CC4AC(BtlServerFlow *flow, void *m)
{
    u8 buf;

    if (func_0689C8FC((u16)(u32)BTL_POKEPARAM_GetItem(m)) == 0) {
        BTL_POKEPARAM_GetPokeId(m);
        if ((u8)func_021C84AC(flow, m, &buf) == 0) {
            return buf != 0 ? 2 : 0;
        }
        return 1;
    }
    return 0;
}









int func_021CC508(BtlServerFlow *flow, void *m)
{
    u32 s;
    int r;

    if (func_021D59B4(m, 16) != 150) {
        s = func_021CC8D8(&flow->lock, 1921);
        func_021C84D0(flow, m);
        r = func_021C8910(flow);
        func_021CC95C((u32 *)&flow->lock, s, 1926);
        if (r == 2)
            return 1;
    }
    return 0;
}









int func_021CC558(BtlServerFlow *flow, void *m)
{
    u32 s;
    int id;
    u32 t;
    char *q;

    if (BTLV_CORE_CheckPartySlotPair(flow, BTL_POKEPARAM_GetPokeId(m)) == 0) {
        t = (u16)(u32)BTL_POKEPARAM_GetItem(m);
        if (t != 0) {
            s = func_021CC8D8(&flow->lock, 1944);
            id = BTL_POKEPARAM_GetPokeId(m);
            q = (char *)func_021C88A4(flow, 32, id);
            q[6] = id;
            ((struct Obj13347 *)q)->f4 = 0;
            func_021C8838(q + 12, 2, 225);
            func_021C8860((struct S_p12 *)(q + 12), id);
            func_021C8860((struct S_p12 *)(q + 12), t);
            func_021C88C8(flow, q);
            func_021CC95C((u32 *)&flow->lock, s, 1957);
            return 1;
        }
    }
    return 0;
}









int func_021CC5F4(BtlServerFlow *flow, void *m)
{
    u32 s;
    int id;
    u8 *r;
    char *q;

    s = func_021CC8D8(&flow->lock, 1968);
    id = BTL_POKEPARAM_GetPokeId(m);
    r = (u8 *)func_021C88A4(flow, 16, id);
    r[4] = 1;
    r[5] = id;
    func_021C88C8(flow, r);
    q = (char *)func_021C88A4(flow, 4, id);
    func_021C8838(q + 4, 2, 228);
    func_021C8860((struct S_p12 *)(q + 4), id);
    func_021C88C8(flow, q);
    func_021CC95C((u32 *)&flow->lock, s, 1984);
    return 1;
}








int func_021CC668(u8 *p)
{
    u8 live[2];
    u8 counts[2];
    u32 i;
    char *list;
    u8 side;
    u8 other;
    int k;
    live[0] = live[1] = 0;
    counts[0] = counts[1] = 0;
    for (i = 0; i < 4; i++) {
        if (BTL_MAIN_IsClientUsed(((struct Obj05196 *)p)->f4, i)) {
            list = func_021B9AEC(*(char * *)&((struct Obj05196 *)p)->f8,i);
            if (func_021B9B94((struct Q1 *)list)) {
                side = BTL_MAIN_GetClientSide((int)(((struct Obj05196 *)p)->f4),(u8)i);
                live[side] += func_021B9B98((u8 *)list);
                counts[side] += func_021B9B94((struct Q1 *)list);
            }
        }
    }
    side = BTL_MAIN_GetClientSide((int)(((struct Obj05196 *)p)->f4),(u8)func_021B8FF4(((struct Obj05196 *)p)->f4));
    other = side ^ 1;
    if (live[side] == 0 && live[other] != 0) return 0;
    if (live[other] == 0 && live[side] != 0) return 1;
    if (!func_021BA534(((struct Obj05196 *)p)->f4)) return 2;
    if (live[0] == 0) {
        k = func_0689D1D4(p+0x3e0);
        if (k != 31) {
            k = func_021B9A40(k);
            if (k == side) return 1;
            return 0;
        }
        return 2;
    }
    return func_021CC768(p, live, counts, side);
}












int func_021CC768(void *a, u8 *p, u8 *q, int want)
{
    int d0;
    int d1;
    int res;
    int vc;
    int v8;
    int v4;
    int v0;

    d0 = q[0] - p[0];
    d1 = q[1] - p[1];
    if (d0 != d1) {
        res = 1;
        if (d0 < d1)
            res = 0;
        if ((u8)res == want)
            return 1;
        return 0;
    }
    func_021CC800(a, (u32 *)(&v8), (u32 *)(&v0), 0);
    func_021CC800(a, (u32 *)(&vc), (u32 *)(&v4), 1);
    if (v0 != v4) {
        res = 1;
        if (v0 > v4)
            res = 0;
        if ((u8)res == want)
            return 1;
        return 0;
    }
    if (v8 != vc) {
        res = 1;
        if (v8 > vc)
            res = 0;
        if ((u8)res == want)
            return 1;
        return 0;
    }
    return 2;
}












void func_021CC800(u8 *a, u32 *out1, u32 *out2, u8 want)
{
    u32 sum;
    u32 j;
    u32 i;
    char *p;
    u32 n;
    u8 *t;

    sum = 0;
    *out1 = 0;
    *out2 = 0;
    for (j = 0; j < 4; j++) {
        if (BTL_MAIN_IsClientUsed(((struct Obj09984 *)a)->f4, j) != 0 &&
            want == BTL_MAIN_GetClientSide((int)(((struct Obj09984 *)a)->f4), (u8)j)) {
            p = func_021B9AEC(((struct Obj09984 *)a)->f8, j);
            n = func_021B9B94((struct Q1 *)p);
            for (i = 0; i < n; i++) {
                t = func_021B9C00((struct S2 *)p, (u8)i);
                sum += func_021D59B4(t, 14);
                *out1 += func_021D59B4(t, 13);
            }
        }
    }
    *out2 = _u32_div_f(*out1 * 100, sum);
}











void func_021CC8A0(u32 *p) { u32 i; for (i=0;i<24;i++) p[i]=6; }












void func_021CC8B0(u32 *p, u32 i, u32 b)
{
    *(u32 *)&p[i] = b;
}












/*
 * indexed load
 */
u32 func_021CC8B8(u32 *p, u32 i)
{
    return p[i];
}












u32 func_021CC8C0(u32 *p, u32 i)
{
    return p[i];
}










void func_021CC8C8(u32 *p) { *p++=0; func_02082BCC(p,0,500); }










u32 func_021CC8D8(void *lock, int line)
{
    struct Lock *p = lock;
    u32 old = *(u32 *)p;
    p->a = 0;
    p->c = p->b;
    p->e = 0;
    p->d = 0;
    p->f = 0;
    return old;
}











u32 func_021CC918(Bf_td *p, u32 v, int unused)
{
    u32 old = ((struct Obj21130 *)p)->f0;
    p->a = v;
    p->c = p->b;
    p->e = 0;
    p->d = 0;
    p->f = 0;
    return old;
}











/* 021CC95C  str r1,[r0] */
/*
 * Stores the second argument (a u32) into the field at offset 0.
 */
void func_021CC95C(u32 *p, u32 v, int line) { *p = v; }











unsigned short func_021CC960(struct S_p14 *p)
{
    return p->x;
}










/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; lsls r0, r0, #1; lsrs r0, r0, #0x1f; bx lr.
 */
int func_021CC96C(struct Q9 *p) { return p->b; }










void func_021CC974(Word_021CC768 *p,int flag) { if(flag) {p->a=1;p->b=1;} else p->a=0; p->c=1; }










/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; lsls r0, r0, #3; lsrs r0, r0, #0x1f; bx lr.
 */
int func_021CC99C(struct Q10 *p) { return p->b; }











u32 func_021CC9A4(u32 *p)
{
    return (((struct Obj18356 *)p)->f0 << 2) >> 31;
}











struct Rec_p14 *func_021CC9AC(struct Pack *p, int id, int b)
{
    u32 i;
    u32 size;
    u32 off;
    u32 j;
    struct Rec_p14 *rec;

    i = 0;
    size = 0;
    for (; i < 0x3B; i++) {
        if (id == d_021EFE9C[i].id) {
            size = d_021EFE9C[i].size;
            break;
        }
    }
    if (size != 0) {
        while (size & 3) {
            size++;
        }
        off = p->off;
        if (off + size <= 500) {
            rec = (struct Rec_p14 *)(p->data + off);
            for (j = 0; j < size; j++) {
                p->data[p->off + j] = 0;
            }
            rec->id = id;
            rec->size = size;
            rec->b = b;
            rec->x = 0;
            rec->y = 1;
            p->off = p->off + size;
            return rec;
        }
    }
    return 0;
}










void func_021CCA74(QueueA *p,QueueB *q) { unsigned a,b,t; a=p->size;b=q->size;if(b<=a) {t=(u32)q-((u32)p+4);t+=b;if(t==a) p->size=a-b;} }
