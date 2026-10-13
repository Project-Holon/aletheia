/*
 * file:     btl_server_cmd.c
 * unit:     yes
 * function: BTL_SERVER_CMD_WriteU8, BTL_SERVER_CMD_ReadU8, BTL_SERVER_CMD_WriteU16, BTL_SERVER_CMD_ReadU16, BTL_SERVER_CMD_WriteU24, BTL_SERVER_CMD_ReadU24, BTL_SERVER_CMD_WriteU32, BTL_SERVER_CMD_ReadU32, BTL_SERVER_CMD_WriteCommand, BTL_SERVER_CMD_ReadFixedArgs, BTL_SERVER_CMD_Push, BTL_SERVER_CMD_Reserve, BTL_SERVER_CMD_FillReserved, BTL_SERVER_CMD_ReadNext, BTL_SERVER_CMD_WriteU8Wrapper, BTL_SERVER_CMD_ReadU8Wrapper, BTL_SERVER_CMD_PushVariable, BTL_SERVER_CMD_ReadVariableArgs, BTL_SERVER_CMD_Dummy
 * address:  0x021CCAA8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Battle server command queue: byte writers and readers, the command encoder and decoder driven by the layout table gBtlServerCmdLayouts.  Split from btl_server.c; it may be the front of btl_client.c (see the cut notes).  The empty-string literal gBtlEmptyString sits between the btl_server_flow.c and btl_client.c file-name strings.
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
 *   HAND_SIDE_InitTable 0x06898BFC thumb ov095
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
 *   BTL_MAIN_GetPlayerStatus 0x021B871C thumb ov093
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
 *   sDamageEffectiveness  0x021F3B2C  data  ov093  a4
 *   sDamageCriticalFlags  0x021F3B20  data  ov093  a4
 *   sDamageTargets  0x021F3B38  data  a4
 *   sDamageValues  0x021F3B26  data  ov093  a4
 *   sDamageAftereffects  0x021F3B23  data  ov093  a4
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
 *   HAND_SIDE_TickTurns 0x06898D54 thumb ov095
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
 *   HAND_SIDE_IsActive  0x06898CF4  thumb  ov095
 *   HAND_SIDE_GetStackCount 0x06898CE0 thumb ov095
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
 *   HAND_SIDE_AddFactor 0x06898C10 thumb ov095
 *   HAND_SIDE_Remove 0x06898D10 thumb ov095
 *   BTL_FIELD_QueryStaticSlotA 0x021EF8E8 thumb ov093
 *   HAND_POS_AddFactor 0x068981F0 thumb ov095
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
 *   gBtlEmptyString 0x021F3A84 data
 *   func_02034714 0x02034714 arm
 *   gBtlServerCmdLayouts  0x021EFF14  data  ov093
 *   gBtlServerCmdArgBuffer  0x021F3B44  data  ov093
 *   gBtlClientFileName 0x021F3A88 data a4
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
 *   BTLV_CORE_ClearWaitWindow 0x021EAE24 thumb ov093
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   func_021F88BC 0x021F88BC thumb ov094
 *   func_021F8678 0x021F8678 thumb ov094
 *   BTLV_CORE_GetWaitState 0x021EAE34 thumb ov093
 *   BTLV_CORE_SetCounterDisplay 0x021EAE74 thumb ov093
 *   gBtlClientCommandTable 0x021EFFEC data a4
 *   func_021F8524 0x021F8524 thumb ov094
 *   BTLV_CORE_StartOpening  0x021E90A0  thumb  ov093
 *   BTLV_CORE_PollOpening  0x021E90D0  thumb  ov093
 *   func_021F84E8  0x021F84E8  thumb  ov094
 *   func_021F8504  0x021F8504  thumb  ov094
 *   BTLV_CORE_ShowCounterValue  0x021EAEA8  thumb  ov093
 *   BTL_REC_ReadSkipFlag  0x021EE688  thumb  ov093
 *   func_021D3F54  0x021D3F54  thumb  ov093
 *   BTLV_CORE_InitInputWork  0x021EAA00  thumb  ov093
 *   BTLV_CORE_CancelWindowModeSelect  0x021EAA5C  thumb  ov093
 *   BTLV_CORE_PollWindowModeSelect  0x021EAA34  thumb  ov093
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021EAF50  0x021EAF50  thumb  ov093
 *   func_021EAF78  0x021EAF78  thumb  ov093
 *   BTL_REC_ReadRecord 0x021EE6B8 thumb ov093
 *   func_021D3FD0 0x021D3FD0 thumb ov093
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
 *   func_0689CB08 0x0689CB08 thumb ov095
 *   BTLV_CORE_IsMenuClosed 0x021E9974 thumb ov093
 *   BTLV_CORE_CloseMenu 0x021E9954 thumb ov093
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   func_021F7998 0x021F7998 thumb ov094
 *   BTLV_CORE_PrintTrainerMessage 0x021EA6B0 thumb ov093
 *   BTL_CALC_IsGymLeaderTrainer 0x021D7F38 thumb ov093
 *   func_021F87EC 0x021F87EC thumb ov094
 *   func_021F8774 0x021F8774 thumb ov094
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_0202A298 0x0202A298 thumb
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
 *   func_0689CB14 0x0689CB14 thumb ov095
 *   func_0689CB1C 0x0689CB1C thumb ov095
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
 *   BTLV_CORE_PrintMessageBuffer 0x021EA600 thumb ov093
 *   PMSI_PARAM_IsEnabled  0x02024450  thumb
 *   PMSI_PARAM_ToString  0x0202435C  thumb
 *   BTLV_CORE_CopyMessageBuffer  0x021EA5E4  thumb  ov093
 *   STRBUF_Delete   0x02045808  arm
 *   BTLV_CORE_BuildMessageToBuffer  0x021EA5F0  thumb  ov093
 *   func_02082A90 0x02082A90 arm
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
 *   func_021F81D0  0x021F81D0  thumb  ov094
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
 *   func_021F7E94 0x021F7E94 thumb ov094
 *   func_021F7EA4  0x021F7EA4  thumb  ov094
 *   BTLV_CORE_StartMonSpriteChangeAt  0x021EA8B4  thumb  ov093
 *   BTLV_CORE_WaitMonSpriteChangeAt  0x021EA8D4  thumb  ov093
 *   BTLV_CORE_StartHitAnim  0x021EA1B8  thumb  ov093
 *   BTLV_CORE_WaitHitAnim  0x021EA1F0  thumb  ov093
 *   BTLV_CORE_StartMonSpriteUnload 0x021EA8E4 thumb ov093
 *   BTLV_CORE_WaitMonSpriteUnload 0x021EA8F4 thumb ov093
 *   gEffortValueParams     0x021EFF88  data  ov093  a2
 *   func_021F8204 0x021F8204 thumb ov094
 *   func_021F8134 0x021F8134 thumb ov094
 *   func_021F8180 0x021F8180 thumb ov094
 *   BTL_EVENT_ReleaseClientHandle 0x021D6EA0 thumb ov093
 *   BTL_POKEPARAM_ReloadFromParam 0x021D6BFC thumb ov093
 *   func_021F8150 0x021F8150 thumb ov094
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
 *   func_020181F4   0x020181F4  thumb
 *   POKE_TOOL_GetLevelUpMove   0x02018328  thumb
 *   BTLV_CORE_BuildAndPrintMessageFlag   0x021EA638  thumb ov093
 *   BTLV_CORE_StartMoveForgetScreen   0x021EAC64  thumb ov093
 *   BTLV_CORE_ProcMoveForgetScreen   0x021EAC80  thumb ov093
 *   sLevelUpMoveScan      0x021F3B64  data
 *   func_021F7CFC 0x021F7CFC thumb ov094
 *   func_021F883C 0x021F883C thumb ov094
 *   gCatchShakeMessages 0x021EFF80 data a2
 *   func_021F7C0C 0x021F7C0C thumb ov094
 *   func_021F7D44  0x021F7D44  thumb  ov094
 *   BTLV_CORE_StartClearSidePosition  0x021EAA6C  thumb  ov093
 *   BTLV_CORE_RunProc  0x021EAAD8  thumb  ov093
 *   BTLV_CORE_ShowPortrait  0x021EA768  thumb  ov093
 *   BTLV_CORE_UpdatePortraitSlideIn  0x021EA778  thumb  ov093
 *   BTLV_CORE_ReloadPortrait  0x021EA7A8  thumb  ov093
 *   BTLV_CORE_UpdatePortraitMosaic  0x021EA7B8  thumb  ov093
 *   BTLV_CORE_StartMonSpriteLoad  0x021EA868  thumb  ov093
 *   BTLV_CORE_WaitMonSpriteLoad  0x021EA878  thumb  ov093
 *   func_0689C9D4 0x0689C9D4 thumb ov095
 */

#include "btl_server_cmd_types.h"

typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))

extern void func_02034714(const char *expr, u32 line, const char *file);
extern char gBtlEmptyString[];
extern const u8 gBtlServerCmdLayouts[];
extern s32 gBtlServerCmdArgBuffer[];

/* Appends one byte; an overflow of the queue is fatal. */
void BTL_SERVER_CMD_WriteU8(BtlServerCmdQueue *queue, u8 value)
{
    if (queue->writePos >= BTL_SERVER_CMD_QUEUE_SIZE) {
        func_02034714(gBtlEmptyString, 0, gBtlEmptyString);
    }
    queue->data[queue->writePos++] = value;
}

/* Reads one byte and advances the read cursor. */
u8 BTL_SERVER_CMD_ReadU8(BtlServerCmdQueue *queue)
{
    u32 pos = queue->readPos;
    queue->readPos = pos + 1;
    return queue->data[pos];
}

/* Appends a big-endian halfword. */
void BTL_SERVER_CMD_WriteU16(BtlServerCmdQueue *queue, u16 value)
{
    if (queue->writePos >= BTL_SERVER_CMD_QUEUE_SIZE - 1) {
        func_02034714(gBtlEmptyString, 0, gBtlEmptyString);
    }
    queue->data[queue->writePos++] = value >> 8;
    queue->data[queue->writePos++] = value;
}

/*
 * Reads a big-endian halfword and advances the read cursor.  The bytes are
 * addressed from the queue base plus the cursor, with the data offset as the
 * load displacement and the cursor read again for the second byte: that is
 * the form the compiler turns into the original code (the plain data[] index
 * form changes the bytes).
 */
u32 BTL_SERVER_CMD_ReadU16(BtlServerCmdQueue *queue)
{
    const u8 *src;
    u16 value;
    int pos;

    pos = queue->readPos;
    src = (const u8 *)((u32)queue + queue->readPos);
    value = (*(const u8 *)((u32)queue + (u32)pos + BTL_SERVER_CMD_DATA_OFFSET) << 8) | *(const u8 *)((u32)queue + queue->readPos + BTL_SERVER_CMD_DATA_OFFSET + 1);
    queue->readPos += 2;
    return value;
}

/* Appends a big-endian 24-bit value. */
void BTL_SERVER_CMD_WriteU24(BtlServerCmdQueue *queue, u32 value)
{
    if (queue->writePos >= BTL_SERVER_CMD_QUEUE_SIZE - 2) {
        func_02034714(gBtlEmptyString, 0, gBtlEmptyString);
    }
    queue->data[queue->writePos++] = value >> 16;
    queue->data[queue->writePos++] = value >> 8;
    queue->data[queue->writePos++] = value;
}

/* Reads a big-endian 24-bit value and advances the read cursor.  Same base-plus-cursor form as BTL_SERVER_CMD_ReadU16. */
u32 BTL_SERVER_CMD_ReadU24(BtlServerCmdQueue *queue)
{
    u32 pos = queue->readPos;
    u8 *src = (u8 *)queue + pos;
    u32 value = (src[BTL_SERVER_CMD_DATA_OFFSET] << 16) | (src[BTL_SERVER_CMD_DATA_OFFSET + 1] << 8) | src[BTL_SERVER_CMD_DATA_OFFSET + 2];

    queue->readPos = pos + 3;
    return value;
}

/* Appends a big-endian word. */
void BTL_SERVER_CMD_WriteU32(BtlServerCmdQueue *queue, u32 value)
{
    if (queue->writePos >= BTL_SERVER_CMD_QUEUE_SIZE - 3) {
        func_02034714(gBtlEmptyString, 0, gBtlEmptyString);
    }
    queue->data[queue->writePos++] = value >> 24;
    queue->data[queue->writePos++] = value >> 16;
    queue->data[queue->writePos++] = value >> 8;
    queue->data[queue->writePos++] = value;
}

/* Reads a big-endian word and advances the read cursor.  Same base-plus-cursor form as BTL_SERVER_CMD_ReadU16. */
u32 BTL_SERVER_CMD_ReadU32(BtlServerCmdQueue *queue)
{
    u32 value;
    u8 *src;

    src = (u8 *)queue + queue->readPos;
    value = ((u32)src[BTL_SERVER_CMD_DATA_OFFSET] << 24) | ((u32)src[BTL_SERVER_CMD_DATA_OFFSET + 1] << 16) | ((u32)src[BTL_SERVER_CMD_DATA_OFFSET + 2] << 8) | src[BTL_SERVER_CMD_DATA_OFFSET + 3];
    queue->readPos += 4;
    return value;
}

/* Writes command id and its arguments, packed as the layout byte says. */
void BTL_SERVER_CMD_WriteCommand(BtlServerCmdQueue *queue, u32 id, int layout, s32 *args)
{
    int i;
    BTL_SERVER_CMD_WriteU16(queue, id);
    switch (layout) {
    case 0x01:
        BTL_SERVER_CMD_WriteU8(queue, args[0]);
        break;
    case 0x11:
        BTL_SERVER_CMD_WriteU16(queue, args[0]);
        break;
    case 0x02:
        BTL_SERVER_CMD_WriteU8(queue, args[0]);
        BTL_SERVER_CMD_WriteU8(queue, args[1]);
        break;
    case 0x12:
        BTL_SERVER_CMD_WriteU8(queue, args[0]);
        BTL_SERVER_CMD_WriteU16(queue, args[1]);
        break;
    case 0x22:
        BTL_SERVER_CMD_WriteU8(queue, args[0]);
        BTL_SERVER_CMD_WriteU32(queue, args[1]);
        break;
    case 0x32:
        BTL_SERVER_CMD_WriteU8(queue, ((args[0] & 0xF) << 4) | (args[1] & 0xF));
        break;
    case 0x42:
        BTL_SERVER_CMD_WriteU8(queue, ((args[0] & 0x1F) << 3) | (args[1] & 7));
        break;
    case 0x03:
        BTL_SERVER_CMD_WriteU8(queue, ((args[0] & 0x1F) << 3) | (args[1] & 7));
        BTL_SERVER_CMD_WriteU8(queue, args[2]);
        break;
    case 0x13:
        BTL_SERVER_CMD_WriteU8(queue, ((args[0] & 0x1F) << 3) | (args[1] & 7));
        BTL_SERVER_CMD_WriteU16(queue, args[2]);
        break;
    case 0x23:
        BTL_SERVER_CMD_WriteU16(queue, (args[2] & 0x1F) | (((args[1] & 0x1F) << 5) | ((args[0] & 0x1F) << 10)));
        break;
    case 0x33:
        BTL_SERVER_CMD_WriteU24(queue, (args[2] & 0x3FFF) | (((args[1] & 0x1F) << 14) | ((args[0] & 0x1F) << 19)));
        break;
    case 0x43:
        BTL_SERVER_CMD_WriteU8(queue, args[0]);
        BTL_SERVER_CMD_WriteU8(queue, args[1]);
        BTL_SERVER_CMD_WriteU16(queue, args[2]);
        break;
    case 0x53:
        BTL_SERVER_CMD_WriteU8(queue, args[0]);
        BTL_SERVER_CMD_WriteU8(queue, args[1]);
        BTL_SERVER_CMD_WriteU32(queue, args[2]);
        break;
    case 0x14:
        BTL_SERVER_CMD_WriteU8(queue, ((args[0] & 0x1F) << 3) | (args[1] & 7));
        BTL_SERVER_CMD_WriteU8(queue, ((args[2] & 0x1F) << 3) | (args[3] & 7));
        break;
    case 0x04:
        BTL_SERVER_CMD_WriteU8(queue, ((args[0] & 0x1F) << 3) | (args[1] & 7));
        BTL_SERVER_CMD_WriteU8(queue, args[2]);
        BTL_SERVER_CMD_WriteU16(queue, args[3]);
        break;
    case 0x24:
        BTL_SERVER_CMD_WriteU24(queue, (args[2] & 0x3FFF) | (((args[1] & 0x1F) << 14) | ((args[0] & 0x1F) << 19)));
        BTL_SERVER_CMD_WriteU8(queue, args[3]);
        break;
    case 0x34:
        BTL_SERVER_CMD_WriteU24(queue, (args[2] & 0x3FFF) | (((args[1] & 0x1F) << 14) | ((args[0] & 0x1F) << 19)));
        BTL_SERVER_CMD_WriteU16(queue, args[3]);
        break;
    case 0x44:
        BTL_SERVER_CMD_WriteU16(queue, (args[2] & 0x3F) | (((args[1] & 0x1F) << 6) | ((args[0] & 0x1F) << 11)));
        BTL_SERVER_CMD_WriteU16(queue, args[3]);
        break;
    case 0x54:
        BTL_SERVER_CMD_WriteU8(queue, args[0]);
        BTL_SERVER_CMD_WriteU8(queue, args[1]);
        BTL_SERVER_CMD_WriteU16(queue, args[2]);
        BTL_SERVER_CMD_WriteU16(queue, args[3]);
        break;
    case 0x05:
        BTL_SERVER_CMD_WriteU16(queue, (args[2] & 0x1F) | (((args[1] & 0x1F) << 5) | ((args[0] & 0x1F) << 10)));
        BTL_SERVER_CMD_WriteU16(queue, args[3]);
        BTL_SERVER_CMD_WriteU16(queue, args[4]);
        break;
    case 0x15: {
        u8 hi = ((args[0] & 0x1F) << 3) | (args[1] & 7);
        u8 lo = ((args[2] & 0x7F) << 1) | (args[3] & 1);
        BTL_SERVER_CMD_WriteU16(queue, hi);
        BTL_SERVER_CMD_WriteU16(queue, lo);
        BTL_SERVER_CMD_WriteU16(queue, args[4]);
        break;
    }
    case 0x25:
        BTL_SERVER_CMD_WriteU8(queue, ((args[0] & 7) << 5) | ((args[1] & 7) << 2) | ((args[2] & 1) << 1) | (args[3] & 1));
        BTL_SERVER_CMD_WriteU16(queue, args[4]);
        break;
    case 0x06: {
        u16 v0 = (args[2] & 0x1F) | (((args[1] & 0x1F) << 5) | ((args[0] & 0x1F) << 10));
        u16 v1 = (args[5] & 0x1F) | (((args[4] & 0x1F) << 5) | ((args[3] & 0x1F) << 10));
        BTL_SERVER_CMD_WriteU16(queue, v0);
        BTL_SERVER_CMD_WriteU16(queue, v1);
        break;
    }
    case 0x16:
        BTL_SERVER_CMD_WriteU8(queue, ((args[0] & 7) << 5) | ((args[1] & 3) << 3) | ((args[2] & 1) << 2) | ((args[3] & 1) << 1) | (args[4] & 1));
        BTL_SERVER_CMD_WriteU16(queue, args[5]);
        break;
    case 0x26:
        BTL_SERVER_CMD_WriteU24(queue, ((args[0] & 0x1F) << 15) | ((args[1] & 0x1F) << 10) | ((args[2] & 0x1F) << 5) | (args[3] & 0x1F));
        BTL_SERVER_CMD_WriteU16(queue, args[4]);
        BTL_SERVER_CMD_WriteU16(queue, args[5]);
        break;
    case 0x07:
        for (i = 0; i < 7; i++)
            BTL_SERVER_CMD_WriteU8(queue, args[i]);
        break;
    case 0x08:
        for (i = 0; i < 8; i++)
            BTL_SERVER_CMD_WriteU8(queue, args[i]);
        break;
    }
}

/* Reads the arguments of a fixed-layout command into args. */
void BTL_SERVER_CMD_ReadFixedArgs(BtlServerCmdQueue *queue, int layout, s32 *args)
{
    u8 byte;
    u32 half;
    u32 word;
    int i;
    switch (layout) {
    case 0x01:
        args[0] = BTL_SERVER_CMD_ReadU8(queue);
        break;
    case 0x11:
        args[0] = BTL_SERVER_CMD_ReadU16(queue);
        break;
    case 0x02:
        args[0] = BTL_SERVER_CMD_ReadU8(queue);
        args[1] = BTL_SERVER_CMD_ReadU8(queue);
        break;
    case 0x12:
        args[0] = BTL_SERVER_CMD_ReadU8(queue);
        args[1] = BTL_SERVER_CMD_ReadU16(queue);
        break;
    case 0x22:
        args[0] = BTL_SERVER_CMD_ReadU8(queue);
        args[1] = BTL_SERVER_CMD_ReadU32(queue);
        break;
    case 0x32:
        byte = BTL_SERVER_CMD_ReadU8(queue);
        args[0] = (byte >> 4) & 0xF;
        args[1] = byte & 0xF;
        break;
    case 0x42:
        byte = BTL_SERVER_CMD_ReadU8(queue);
        args[0] = (byte >> 3) & 0x1F;
        args[1] = byte & 7;
        break;
    case 0x03:
        byte = BTL_SERVER_CMD_ReadU8(queue);
        args[0] = (byte >> 3) & 0x1F;
        args[1] = byte & 7;
        args[2] = BTL_SERVER_CMD_ReadU8(queue);
        break;
    case 0x13:
        byte = BTL_SERVER_CMD_ReadU8(queue);
        args[0] = (byte >> 3) & 0x1F;
        args[1] = byte & 7;
        args[2] = BTL_SERVER_CMD_ReadU16(queue);
        break;
    case 0x23:
        half = BTL_SERVER_CMD_ReadU16(queue);
        args[0] = (half >> 10) & 0x1F;
        args[1] = (half >> 5) & 0x1F;
        args[2] = half & 0x1F;
        break;
    case 0x33:
        word = BTL_SERVER_CMD_ReadU24(queue);
        args[0] = (word >> 19) & 0x1F;
        args[1] = (word >> 14) & 0x1F;
        args[2] = word & 0x3FFF;
        break;
    case 0x43:
        args[0] = BTL_SERVER_CMD_ReadU8(queue);
        args[1] = BTL_SERVER_CMD_ReadU8(queue);
        args[2] = BTL_SERVER_CMD_ReadU16(queue);
        break;
    case 0x53:
        args[0] = BTL_SERVER_CMD_ReadU8(queue);
        args[1] = BTL_SERVER_CMD_ReadU8(queue);
        args[2] = BTL_SERVER_CMD_ReadU32(queue);
        break;
    case 0x14:
        byte = BTL_SERVER_CMD_ReadU8(queue);
        args[0] = (byte >> 3) & 0x1F;
        args[1] = byte & 7;
        byte = BTL_SERVER_CMD_ReadU8(queue);
        args[2] = (byte >> 3) & 0x1F;
        args[3] = byte & 7;
        break;
    case 0x04:
        byte = BTL_SERVER_CMD_ReadU8(queue);
        args[0] = (byte >> 3) & 0x1F;
        args[1] = byte & 7;
        args[2] = BTL_SERVER_CMD_ReadU8(queue);
        args[3] = BTL_SERVER_CMD_ReadU16(queue);
        break;
    case 0x24:
        word = BTL_SERVER_CMD_ReadU24(queue);
        args[0] = (word >> 19) & 0x1F;
        args[1] = (word >> 14) & 0x1F;
        args[2] = word & 0x3FFF;
        args[3] = BTL_SERVER_CMD_ReadU8(queue);
        break;
    case 0x34:
        word = BTL_SERVER_CMD_ReadU24(queue);
        args[0] = (word >> 19) & 0x1F;
        args[1] = (word >> 14) & 0x1F;
        args[2] = word & 0x3FFF;
        args[3] = BTL_SERVER_CMD_ReadU16(queue);
        break;
    case 0x44:
        half = BTL_SERVER_CMD_ReadU16(queue);
        args[0] = (half >> 11) & 0x1F;
        args[1] = (half >> 6) & 0x1F;
        args[2] = half & 0x3F;
        args[3] = BTL_SERVER_CMD_ReadU16(queue);
        break;
    case 0x54:
        args[0] = BTL_SERVER_CMD_ReadU8(queue);
        args[1] = BTL_SERVER_CMD_ReadU8(queue);
        args[2] = BTL_SERVER_CMD_ReadU16(queue);
        args[3] = BTL_SERVER_CMD_ReadU16(queue);
        break;
    case 0x05:
        half = BTL_SERVER_CMD_ReadU16(queue);
        args[0] = (half >> 10) & 0x1F;
        args[1] = (half >> 5) & 0x1F;
        args[2] = half & 0x1F;
        args[3] = BTL_SERVER_CMD_ReadU16(queue);
        args[4] = BTL_SERVER_CMD_ReadU16(queue);
        break;
    case 0x15: {
        u32 hi = BTL_SERVER_CMD_ReadU16(queue);
        u32 lo = BTL_SERVER_CMD_ReadU16(queue);
        args[0] = ((u8)hi >> 3) & 0x1F;
        args[1] = (u8)hi & 7;
        args[2] = ((u8)lo >> 1) & 0x7F;
        args[3] = (u8)lo & 1;
        args[4] = BTL_SERVER_CMD_ReadU16(queue);
        break;
    }
    case 0x25:
        word = BTL_SERVER_CMD_ReadU8(queue);
        args[0] = (word >> 5) & 7;
        args[1] = (word >> 2) & 7;
        args[2] = (word >> 1) & 1;
        args[3] = word & 1;
        args[4] = BTL_SERVER_CMD_ReadU16(queue);
        break;
    case 0x06: {
        u32 v0 = BTL_SERVER_CMD_ReadU16(queue);
        u32 v1 = BTL_SERVER_CMD_ReadU16(queue);
        args[0] = (v0 >> 10) & 0x1F;
        args[1] = (v0 >> 5) & 0x1F;
        args[2] = v0 & 0x1F;
        args[3] = (v1 >> 10) & 0x1F;
        args[4] = (v1 >> 5) & 0x1F;
        args[5] = v1 & 0x1F;
        break;
    }
    case 0x16:
        word = BTL_SERVER_CMD_ReadU8(queue);
        args[0] = (word >> 5) & 7;
        args[1] = (word >> 3) & 3;
        args[2] = (word >> 2) & 1;
        args[3] = (word >> 1) & 1;
        args[4] = word & 1;
        args[5] = BTL_SERVER_CMD_ReadU16(queue);
        break;
    case 0x26:
        word = BTL_SERVER_CMD_ReadU24(queue);
        args[0] = (word >> 15) & 0x1F;
        args[1] = (word >> 10) & 0x1F;
        args[2] = (word >> 5) & 0x1F;
        args[3] = word & 0x1F;
        args[4] = BTL_SERVER_CMD_ReadU16(queue);
        args[5] = BTL_SERVER_CMD_ReadU16(queue);
        break;
    case 0x07:
        for (i = 0; i < 7; i++)
            args[i] = BTL_SERVER_CMD_ReadU8(queue);
        break;
    case 0x08:
        for (i = 0; i < 8; i++)
            args[i] = BTL_SERVER_CMD_ReadU8(queue);
        break;
    }
}

/*
 * Appends command id with its variadic arguments; the layout byte gives the count.
 * stand-in: id is volatile.  Removing it changes the bytes.
 */
void BTL_SERVER_CMD_Push(BtlServerCmdQueue *queue, volatile u32 id, ...)
{
    va_list ap;
    u32 i = 0;
    u8 layout = gBtlServerCmdLayouts[id];
    u32 argCount = layout & 0xF;

    va_start(ap, id);
    for (; i < argCount; i++) {
        gBtlServerCmdArgBuffer[i] = va_arg(ap, s32);
    }
    BTL_SERVER_CMD_WriteCommand(queue, id, layout, gBtlServerCmdArgBuffer);
}

/*
 * Reserves room for command id: writes it with zero arguments to measure its
 * length, then overwrites the start with a filler record of that length.
 * Returns the position of the slot for BTL_SERVER_CMD_FillReserved to fill in later.
 */
u16 BTL_SERVER_CMD_Reserve(BtlServerCmdQueue *queue, u32 id)
{
    u8 layout;
    u8 argCount;
    u8 i;
    u8 length;
    u16 slotPos;

    layout = gBtlServerCmdLayouts[id];
    argCount = layout & 0xf;
    i = 0;
    if (argCount != 0) {
        do {
            gBtlServerCmdArgBuffer[i] = 0;
            i++;
        } while (i < argCount);
    }
    slotPos = queue->writePos;
    BTL_SERVER_CMD_WriteCommand(queue, id, layout, gBtlServerCmdArgBuffer);
    length = queue->writePos - slotPos;
    queue->writePos = slotPos;
    BTL_SERVER_CMD_WriteU16(queue, BTL_SERVER_CMD_ID_FILLER);
    BTL_SERVER_CMD_WriteU8(queue, length - 3);
    queue->writePos = slotPos + length;
    return slotPos;
}

/* Writes command id with its variadic arguments into a slot reserved by BTL_SERVER_CMD_Reserve. */
void BTL_SERVER_CMD_FillReserved(BtlServerCmdQueue *queue, u16 slotPos, u32 id, ...)
{
    va_list ap;
    u32 i = 0;
    u8 layout = gBtlServerCmdLayouts[id];
    u32 argCount = layout & 0xF;
    u16 savedPos;

    va_start(ap, id);
    for (; i < argCount; i++) {
        gBtlServerCmdArgBuffer[i] = va_arg(ap, s32);
    }
    savedPos = queue->readPos;
    queue->readPos = slotPos;
    BTL_SERVER_CMD_ReadU16(queue);
    BTL_SERVER_CMD_ReadU8(queue);
    queue->readPos = savedPos;
    if (id != BTL_SERVER_CMD_ID_FILLER) {
        savedPos = queue->writePos;
        queue->writePos = slotPos;
        BTL_SERVER_CMD_WriteCommand(queue, id, layout, gBtlServerCmdArgBuffer);
        queue->writePos = savedPos;
    }
}

/*
 * Reads the next command into args, skipping filler records; returns its id,
 * or BTL_SERVER_CMD_ID_NONE when the read cursor reaches the write cursor.
 */
int BTL_SERVER_CMD_ReadNext(BtlServerCmdQueue *queue, s32 *args)
{
    int id;
    u8 layout;

    id = BTL_SERVER_CMD_ReadU16(queue);
    while (id == BTL_SERVER_CMD_ID_FILLER) {
        queue->readPos += BTL_SERVER_CMD_ReadU8(queue);
        if (queue->readPos >= queue->writePos) {
            return BTL_SERVER_CMD_ID_NONE;
        }
        id = BTL_SERVER_CMD_ReadU16(queue);
    }
    layout = gBtlServerCmdLayouts[id];
    if (layout != 0 && layout != 0x10) {
        BTL_SERVER_CMD_ReadFixedArgs(queue, layout, args);
    } else {
        BTL_SERVER_CMD_ReadVariableArgs(queue, id, args);
    }
    return id;
}

/* Same as BTL_SERVER_CMD_WriteU8, called through a wrapper. */
void BTL_SERVER_CMD_WriteU8Wrapper(BtlServerCmdQueue *queue, u8 value)
{
    BTL_SERVER_CMD_WriteU8(queue, value);
}

/* Same as BTL_SERVER_CMD_ReadU8, called through a wrapper. */
u8 BTL_SERVER_CMD_ReadU8Wrapper(BtlServerCmdQueue *queue)
{
    return BTL_SERVER_CMD_ReadU8(queue);
}

/*
 * Appends a variable-length command: id, first argument and (for the long
 * list command) a second halfword, then words up to BTL_SERVER_CMD_ARG_END.
 */
void BTL_SERVER_CMD_PushVariable(BtlServerCmdQueue *queue, u8 id, ...)
{
    va_list ap;
    u16 first;
    s32 word;

    va_start(ap, id);
    first = va_arg(ap, s32);
    BTL_SERVER_CMD_WriteU16(queue, id);
    BTL_SERVER_CMD_WriteU16(queue, first);
    if (id == BTL_SERVER_CMD_ID_LONG_LIST) {
        BTL_SERVER_CMD_WriteU16(queue, va_arg(ap, s32));
    }
    do {
        word = va_arg(ap, s32);
        BTL_SERVER_CMD_WriteU32(queue, word);
    } while (word != (s32)BTL_SERVER_CMD_ARG_END);
}

/* Reads the arguments of a variable-length command into args (at most 16). */
void BTL_SERVER_CMD_ReadVariableArgs(BtlServerCmdQueue *queue, u8 id, s32 *args)
{
    int i;

    i = 1;
    args[0] = BTL_SERVER_CMD_ReadU16(queue);
    if (id == BTL_SERVER_CMD_ID_LONG_LIST) {
        args[1] = BTL_SERVER_CMD_ReadU16(queue);
        i++;
    }
    for (; i < BTL_SERVER_CMD_MAX_ARGS; i++) {
        args[i] = BTL_SERVER_CMD_ReadU32(queue);
        if (args[i] == BTL_SERVER_CMD_ARG_END) {
            break;
        }
    }
}

/* Empty function. */
void BTL_SERVER_CMD_Dummy(void)
{
}
