/*
 * file:     hand_waza.c
 * unit:     yes
 * function: HAND_ITEM_GemMovePower, HAND_ITEM_GemMoveDamageEnd, HAND_WAZA_AddMoveHandler, HAND_WAZA_CanAddMoveHandler, HAND_WAZA_RemoveMoveHandlerUnlessKept, HAND_WAZA_RemoveMoveHandlerOfPoke, HAND_WAZA_IsKeptOnSuspend, HAND_WAZA_RemoveMoveHandlerById, HAND_WAZA_RemoveAllMoveHandlers, HAND_WAZA_GetConversionHandlers, HAND_WAZA_ConversionEffect, HAND_WAZA_GetCamouflageHandlers, HAND_WAZA_CamouflageChangeType, HAND_WAZA_GetTrickRoomHandlers, HAND_WAZA_TrickRoomAddFieldEffect, HAND_WAZA_GetGravityHandlers, HAND_WAZA_GravityAddFieldEffect, HAND_WAZA_GetWaterSportHandlers, HAND_WAZA_WaterSportAddFieldEffect, HAND_WAZA_GetMudSportHandlers, HAND_WAZA_MudSportAddFieldEffect, HAND_WAZA_GetDefogHandlers, HAND_WAZA_DefogLowerEvasionRemoveSideEffects, HAND_WAZA_GetBrickBreakHandlers, HAND_WAZA_BrickBreakSetSkipCheck, HAND_WAZA_BrickBreakClearSkipCheck, HAND_WAZA_BrickBreakRemoveScreens, HAND_WAZA_BrickBreakSkipScreens, HAND_WAZA_GetJumpKickHandlers, HAND_WAZA_JumpKickCrashOnFail, HAND_WAZA_JumpKickDealCrashDamage, HAND_WAZA_GetMimicHandlers, HAND_WAZA_MimicCopyTargetMove, HAND_WAZA_GetSketchHandlers, HAND_WAZA_SketchLearnTargetMove, HAND_WAZA_GetFollowMeHandlers, HAND_WAZA_FollowMeFailOutsideMultiBattle, HAND_WAZA_FollowMeShowMessage, HAND_WAZA_FollowMeRedirectTarget, HAND_WAZA_FollowMeRemoveFactor, HAND_WAZA_GetRefreshHandlers, HAND_WAZA_RefreshCureMajorStatus, HAND_WAZA_GetTrapHandlers, HAND_WAZA_TrapAddNoEscape, HAND_WAZA_GetHazeHandlers, HAND_WAZA_HazeResetRanks, HAND_WAZA_GetSplashHandlers, HAND_WAZA_SplashShowMessage, HAND_WAZA_GetCurseHandlers, HAND_WAZA_CurseSetTargetKind, HAND_WAZA_CurseApply, HAND_WAZA_GetThunderWaveHandlers, HAND_WAZA_ThunderWaveSetAccuracyCheckFlag, HAND_WAZA_GetWorrySeedHandlers, HAND_WAZA_WorrySeedFailOnTruantOrInsomnia, HAND_WAZA_WorrySeedChangeAbility, HAND_WAZA_GetDreamEaterHandlers, HAND_WAZA_DreamEaterFailIfAwake, HAND_WAZA_DreamEaterSetFailFlag, HAND_WAZA_GetCaptivateHandlers, HAND_WAZA_CaptivateFailOnSameOrNoGender, HAND_WAZA_GetTriAttackHandlers, HAND_WAZA_TriAttackOnDecideAddSick, HAND_WAZA_AddSecretPower, HAND_WAZA_SecretPowerGetGroundEffect, HAND_WAZA_SecretPowerOnPrepareMove, HAND_WAZA_SecretPowerOnAddEffect, HAND_WAZA_AddChatter, HAND_WAZA_ChatterOnDecideAddSick, HAND_WAZA_AddTrap, HAND_WAZA_TrapOnDecideAddSick, HAND_WAZA_TrapOnAddSickMessage, HAND_WAZA_AddWhirlpool, HAND_WAZA_WhirlpoolOnInvulnerableCheck, HAND_WAZA_WhirlpoolOnCalcDamageRatio, HAND_WAZA_AddSuperFang, HAND_WAZA_SuperFangOnCalcFixedDamage, HAND_WAZA_AddDragonRage, HAND_WAZA_DragonRageOnCalcFixedDamage, HAND_WAZA_AddSonicBoom, HAND_WAZA_SonicBoomOnCalcFixedDamage, HAND_WAZA_AddEndeavor, HAND_WAZA_EndeavorOnNoEffectCheck, HAND_WAZA_EndeavorOnCalcFixedDamage, HAND_WAZA_AddLevelDamage, HAND_WAZA_LevelDamageOnCalcFixedDamage, HAND_WAZA_AddPsywave, HAND_WAZA_PsywaveOnCalcFixedDamage, HAND_WAZA_AddStockpile, HAND_WAZA_StockpileOnMoveFailCheck, HAND_WAZA_StockpileOnMoveEffect, HAND_WAZA_AddSpitUp, HAND_WAZA_StockpileUseOnMoveFailCheck, HAND_WAZA_SpitUpOnGetMovePower, HAND_WAZA_StockpileUseOnMoveEnd, HAND_WAZA_AddSwallow, HAND_WAZA_SwallowOnCalcHealRatio, HAND_WAZA_AddCounter, HAND_WAZA_CounterOnMoveFailCheck, HAND_WAZA_CounterOnDecideTarget, HAND_WAZA_CounterOnCalcFixedDamage, HAND_WAZA_AddMirrorCoat, HAND_WAZA_MirrorCoatOnMoveFailCheck, HAND_WAZA_MirrorCoatOnDecideTarget, HAND_WAZA_MirrorCoatOnCalcFixedDamage, HAND_WAZA_AddMetalBurst, HAND_WAZA_MetalBurstOnMoveFailCheck, HAND_WAZA_MetalBurstOnDecideTarget, HAND_WAZA_MetalBurstOnCalcFixedDamage, HAND_WAZA_RetaliateOnMoveFailCheck, HAND_WAZA_RetaliateOnDecideTarget, HAND_WAZA_RetaliateOnCalcFixedDamage, HAND_WAZA_FindRetaliateHit, HAND_WAZA_AddLastResort, HAND_WAZA_LastResortOnMoveFailCheck, HAND_WAZA_AddSnore, HAND_WAZA_SnoreOnActionCheck, HAND_WAZA_SnoreOnMoveFailCheck, HAND_WAZA_AddNightmare, HAND_WAZA_NightmareOnNoEffectCheck, HAND_WAZA_AddSuckerPunch, HAND_WAZA_SuckerPunchCheckNoEffect, HAND_WAZA_PursuitGetHandlers, HAND_WAZA_PursuitQueueIntercept, HAND_WAZA_PursuitAlwaysHitOnIntercept, HAND_WAZA_PursuitDoublePowerOnIntercept, HAND_WAZA_SelfDestructGetHandlers, HAND_WAZA_SelfDestructFaintOnHit, HAND_WAZA_SelfDestructPushUserCmd, HAND_WAZA_SelfDestructFaintOnFinish, HAND_WAZA_FocusEnergyGetHandlers, HAND_WAZA_FocusEnergyApplyEffect, HAND_WAZA_ChargeGetHandlers, HAND_WAZA_ChargeStoreOnUse, HAND_WAZA_ChargeBoostElectricPower, HAND_WAZA_ChargeArmOnNextMove, HAND_WAZA_ChargeExpireOnMoveEnd, HAND_WAZA_PerishSongGetHandlers, HAND_WAZA_PerishSongShowMessage, HAND_WAZA_PerishSongClearNoEffect, HAND_WAZA_LeechSeedGetHandlers, HAND_WAZA_LeechSeedSetSickCont, HAND_WAZA_PayDayGetHandlers, HAND_WAZA_PayDayScatterCoins, HAND_WAZA_RageGetHandlers, HAND_WAZA_RageKeepOnExecute, HAND_WAZA_RageRaiseAttackOnHit, HAND_WAZA_RageEndOnActionStart, HAND_WAZA_AquaRingGetHandlers, HAND_WAZA_AquaRingApplyEffect, HAND_WAZA_ThrashGetHandlers, HAND_WAZA_ThrashStartLock, HAND_WAZA_ThrashAdvanceTurn, HAND_WAZA_ThrashEndOnSleep, HAND_WAZA_UproarGetHandlers, HAND_WAZA_UproarStart, HAND_WAZA_UproarEndOnFailure, HAND_WAZA_UproarOnTurnEnd, HAND_WAZA_UproarPreventSleep, HAND_WAZA_UproarPreventSleepSilently, HAND_WAZA_RolloutGetHandlers, HAND_WAZA_RolloutStartLock, HAND_WAZA_RolloutEndOnDoneOrFail, HAND_WAZA_RolloutEndOnMoveEnd, HAND_WAZA_RolloutEndLock, HAND_WAZA_RolloutScalePower, HAND_WAZA_TripleKickGetHandlers, HAND_WAZA_TripleKickRaisePower, HAND_WAZA_TripleKickCheckEachHit, HAND_WAZA_GyroBallGetHandlers, HAND_WAZA_GyroBallCalcPower, HAND_WAZA_RevengeGetHandlers, HAND_WAZA_RevengeDoublePowerOnHit, HAND_WAZA_FlailGetHandlers, HAND_WAZA_FlailCalcPower, HAND_WAZA_FacadeGetHandlers, HAND_WAZA_FacadeDoublePowerOnStatus, HAND_WAZA_PaybackGetHandlers, HAND_WAZA_PaybackDoublePowerIfTargetMoved, HAND_WAZA_EruptionGetHandlers, HAND_WAZA_EruptionOnWazaPower, HAND_WAZA_AddWringOut, HAND_WAZA_WringOutOnWazaPower, HAND_WAZA_AddBrine, HAND_WAZA_BrineOnPowerRatio, HAND_WAZA_AddReturn, HAND_WAZA_ReturnOnWazaPower, HAND_WAZA_AddFrustration, HAND_WAZA_FrustrationOnWazaPower, HAND_WAZA_AddWakeUpSlap, HAND_WAZA_WakeUpSlapOnWazaPower, HAND_WAZA_WakeUpSlapOnDamageEnd, HAND_WAZA_AddSmellingSalt, HAND_WAZA_SmellingSaltOnWazaPower, HAND_WAZA_SmellingSaltOnDamageEnd, HAND_WAZA_AddPresent, HAND_WAZA_PresentOnVariantDecide, HAND_WAZA_PresentOnHealEffect, HAND_WAZA_PresentOnWazaPower, HAND_WAZA_AddTrumpCard, HAND_WAZA_TrumpCardOnWazaPower, HAND_WAZA_AddPunishment, HAND_WAZA_PunishmentOnWazaPower, HAND_WAZA_AddFuryCutter, HAND_WAZA_FuryCutterOnWazaPower, HAND_WAZA_AddAssurance, HAND_WAZA_AssuranceOnWazaPower, HAND_WAZA_AddLowKick, HAND_WAZA_LowKickOnWazaPower, HAND_WAZA_AddWeatherBall, HAND_WAZA_WeatherBallOnWazaTypeCheck, HAND_WAZA_WeatherBallOnWazaPower, HAND_WAZA_AddGust, HAND_WAZA_GustOnInvulnerableCheck, HAND_WAZA_GustOnWazaPower, HAND_WAZA_AddSkyUppercut, HAND_WAZA_SkyUppercutOnInvulnerableCheck, HAND_WAZA_AddThunder, HAND_WAZA_ThunderOnInvulnerableCheck, HAND_WAZA_ThunderOnHitCheck, HAND_WAZA_ThunderOnAccuracyCheck, HAND_WAZA_AddBlizzard, HAND_WAZA_BlizzardOnHitCheck, HAND_WAZA_AddEarthquake, HAND_WAZA_EarthquakeOnInvulnerableCheck, HAND_WAZA_EarthquakeOnDamageRatio, HAND_WAZA_AddJudgment, HAND_WAZA_JudgmentOnWazaTypeCheck, HAND_WAZA_AddTechnoBlast, HAND_WAZA_TechnoBlastOnWazaTypeCheck, HAND_WAZA_AddHiddenPower, HAND_WAZA_HiddenPowerOnWazaTypeCheck, HAND_WAZA_HiddenPowerOnWazaPower, HAND_WAZA_AddNaturalGift, HAND_WAZA_NaturalGiftOnExecuteCheck, HAND_WAZA_NaturalGiftOnWazaTypeCheck, HAND_WAZA_NaturalGiftOnWazaPower, HAND_WAZA_NaturalGiftOnWazaFinish, HAND_WAZA_AddKnockOff, HAND_WAZA_KnockOffOnDamageEnd, HAND_WAZA_AddMagicCoat, HAND_WAZA_MagicCoatOnExecuteCheck, HAND_WAZA_MagicCoatOnWazaExecute, HAND_WAZA_MagicCoatOnWazaCounter, HAND_WAZA_MagicCoatOnWazaNotice, HAND_WAZA_MagicCoatOnTurnEnd, HAND_WAZA_AddSnatch, HAND_WAZA_SnatchOnWazaExecute, HAND_WAZA_SnatchOnSnatchCheck, HAND_WAZA_SnatchOnSnatched, HAND_WAZA_SnatchOnTurnEnd, HAND_WAZA_AddThief, HAND_WAZA_ThiefOnWazaPrepare, HAND_WAZA_ThiefOnDamageEnd, HAND_WAZA_AddTrick, HAND_WAZA_TrickOnWazaExecute, HAND_WAZA_AddMagnitude, HAND_WAZA_MagnitudeOnWazaStart, HAND_WAZA_MagnitudeSetDefaultLevel, HAND_WAZA_GetSurfHandlers, HAND_WAZA_SurfHitDiving, HAND_WAZA_SurfDoubleDamageVsDiving, HAND_WAZA_GetStompHandlers, HAND_WAZA_StompDoubleDamageVsMinimized, HAND_WAZA_GetFalseSwipeHandlers, HAND_WAZA_FalseSwipeLeaveOneHp, HAND_WAZA_GetEndureHandlers, HAND_WAZA_EndureBraceUp, HAND_WAZA_EndureSurviveAtOneHp, HAND_WAZA_EndureRemoveAtTurnEnd, HAND_WAZA_GetProtectHandlers, HAND_WAZA_ProtectResetStreakAfterOtherMove, HAND_WAZA_ProtectCheckSuccess, HAND_WAZA_ProtectResetStreakOnFail, HAND_WAZA_ProtectActivate, HAND_WAZA_ProtectIncrementStreak, HAND_WAZA_GetBideHandlers, HAND_WAZA_BideAdvanceTurn, HAND_WAZA_BideSelectMessage, HAND_WAZA_BideCheckStoredDamage, HAND_WAZA_BideDecideTarget, HAND_WAZA_BideStoreDamage, HAND_WAZA_BideDoubleStoredDamage, HAND_WAZA_BideEndOnFail, HAND_WAZA_BideFindTarget, HAND_WAZA_BideCureStoringState, HAND_WAZA_GetRecycleHandlers, HAND_WAZA_RecycleRestoreItem, HAND_WAZA_GetPsychoShiftHandlers, HAND_WAZA_PsychoShiftTransferStatus, HAND_WAZA_GetPainSplitHandlers, HAND_WAZA_PainSplitAverageHp, HAND_WAZA_GetBellyDrumHandlers, HAND_WAZA_BellyDrumMaximizeAttack, HAND_WAZA_GetFeintHandlers, HAND_WAZA_FeintSetBypassFlag, HAND_WAZA_FeintBreakProtect, HAND_WAZA_FeintBreakSideGuard, HAND_WAZA_GetAcupressureHandlers, HAND_WAZA_AcupressureRaiseRandomStat, HAND_WAZA_GetRestHandlers, HAND_WAZA_RestCheckFail, HAND_WAZA_RestSleepAndHeal, HAND_WAZA_GetAttractHandlers, HAND_WAZA_AttractCheckGender, HAND_WAZA_GetConversion2Handlers, HAND_WAZA_Conversion2ChangeType, HAND_WAZA_GetEncoreHandlers, HAND_WAZA_EncoreAddSick, HAND_WAZA_GetTauntHandlers, HAND_WAZA_TauntOnUncategorizedMove, HAND_WAZA_AddTorment, HAND_WAZA_TormentOnUncategorizedMove, HAND_WAZA_AddDisable, HAND_WAZA_DisableOnUncategorizedMove, HAND_WAZA_AddImprison, HAND_WAZA_ImprisonOnUncategorizedMove, HAND_WAZA_AddAromatherapy, HAND_WAZA_AromatherapyOnUncategorizedMoveNoTarget, HAND_WAZA_AddHealBell, HAND_WAZA_HealBellOnUncategorizedMoveNoTarget, HAND_WAZA_CureParty, HAND_WAZA_CollectStatusedPokeIds, HAND_WAZA_AddMemento, HAND_WAZA_MementoOnUncategorizedMove, HAND_WAZA_AddSpite, HAND_WAZA_SpiteOnUncategorizedMove, HAND_WAZA_AddPsychUp, HAND_WAZA_PsychUpOnUncategorizedMove, HAND_WAZA_AddHeartSwap, HAND_WAZA_HeartSwapOnUncategorizedMove, HAND_WAZA_AddPowerSwap, HAND_WAZA_PowerSwapOnUncategorizedMove, HAND_WAZA_AddGuardSwap, HAND_WAZA_GuardSwapOnUncategorizedMove, HAND_WAZA_AddPowerTrick, HAND_WAZA_PowerTrickOnUncategorizedMove, HAND_WAZA_AddPowerSplit, HAND_WAZA_PowerSplitOnUncategorizedMove, HAND_WAZA_AddGuardSplit, HAND_WAZA_GuardSplitOnUncategorizedMove, HAND_WAZA_AddLockOn, HAND_WAZA_LockOnOnUncategorizedMove, HAND_WAZA_AddReflect, HAND_WAZA_ReflectOnUncategorizedMoveNoTarget, HAND_WAZA_AddLightScreen, HAND_WAZA_LightScreenOnUncategorizedMoveNoTarget, HAND_WAZA_AddSafeguard, HAND_WAZA_SafeguardOnUncategorizedMoveNoTarget, HAND_WAZA_AddMist, HAND_WAZA_MistOnUncategorizedMoveNoTarget, HAND_WAZA_AddTailwind, HAND_WAZA_TailwindOnUncategorizedMoveNoTarget, HAND_WAZA_AddLuckyChant, HAND_WAZA_LuckyChantOnUncategorizedMoveNoTarget, HAND_WAZA_AddSpikes, HAND_WAZA_SpikesOnUncategorizedMoveNoTarget, HAND_WAZA_AddToxicSpikes, HAND_WAZA_ToxicSpikesOnUncategorizedMoveNoTarget, HAND_WAZA_AddStealthRock, HAND_WAZA_StealthRockOnUncategorizedMoveNoTarget, HAND_WAZA_AddWideGuard, HAND_WAZA_WideGuardOnUncategorizedMoveNoTarget, HAND_WAZA_AddSideEffect, HAND_WAZA_AddTransform, HAND_WAZA_TransformOnUncategorizedMove, HAND_WAZA_AddLunarDance, HAND_WAZA_LunarDanceSetPosEffect, HAND_WAZA_GetHealingWishHandlers, HAND_WAZA_HealingWishSetPosEffect, HAND_WAZA_GetWishHandlers, HAND_WAZA_WishSetPosEffect, HAND_WAZA_GetFutureSightHandlers, HAND_WAZA_FutureSightArmDelayedAttack, HAND_WAZA_FutureSightShowMessage, HAND_WAZA_ArmDelayedAttack, HAND_WAZA_GetDoomDesireHandlers, HAND_WAZA_DoomDesireArmDelayedAttack, HAND_WAZA_DoomDesireShowMessage, HAND_WAZA_GetGastroAcidHandlers, HAND_WAZA_GastroAcidSuppressAbility, HAND_WAZA_GetRolePlayHandlers, HAND_WAZA_RolePlayCopyAbility, HAND_WAZA_GetUTurnHandlers, HAND_WAZA_UTurnSwitchOut, HAND_WAZA_GetRapidSpinHandlers, HAND_WAZA_RapidSpinClearBindingAndHazards, HAND_WAZA_GetBatonPassHandlers, HAND_WAZA_BatonPassSwitchOut, HAND_WAZA_GetTeleportHandlers, HAND_WAZA_TeleportCheckFail, HAND_WAZA_TeleportEscape, HAND_WAZA_TeleportShowFailMessage, HAND_WAZA_GetFlingHandlers, HAND_WAZA_FlingCheckFail, HAND_WAZA_FlingSetBasePower, HAND_WAZA_FlingShowMessage, HAND_WAZA_FlingUseItemOnTarget, HAND_WAZA_FlingRemoveItemAfterMove, HAND_WAZA_GetMagnetRiseHandlers, HAND_WAZA_MagnetRiseCheckFail, HAND_WAZA_MagnetRiseAddFloating, HAND_WAZA_GetHelpingHandHandlers, HAND_WAZA_HelpingHandSetGenericFlag, HAND_WAZA_HelpingHandClearProtectBypass, HAND_WAZA_HelpingHandAssistAlly, HAND_WAZA_HelpingHandBoostPower, HAND_WAZA_HelpingHandRemoveAtTurnEnd, HAND_WAZA_GetBeatUpHandlers, HAND_WAZA_BeatUpSetHitCount, HAND_WAZA_BeatUpSetBasePower, HAND_WAZA_FindBeatUpMember, HAND_WAZA_GetFakeOutHandlers, HAND_WAZA_FakeOutCheckFail, HAND_WAZA_GetWeatherHealHandlers, HAND_WAZA_WeatherHealSetRatio, HAND_WAZA_GetFlyHandlers, HAND_WAZA_FlyBeginFlight, HAND_WAZA_FlyChargeEndNoOp, HAND_WAZA_GetShadowForceHandlers, HAND_WAZA_ShadowForceBeginVanish, HAND_WAZA_ShadowForceChargeEndNoOp, HAND_WAZA_ShadowForceBreakProtect, HAND_WAZA_GetBounceHandlers, HAND_WAZA_BounceOnChargeTurn, HAND_WAZA_BounceNoOp, HAND_WAZA_AddDive, HAND_WAZA_DiveOnChargeTurn, HAND_WAZA_DiveNoOp, HAND_WAZA_AddDig, HAND_WAZA_DigOnChargeTurn, HAND_WAZA_DigNoOp, HAND_WAZA_AddSolarBeam, HAND_WAZA_SolarBeamSkipChargeInSun, HAND_WAZA_SolarBeamOnChargeTurn, HAND_WAZA_SolarBeamHalvePowerInBadWeather, HAND_WAZA_AddRazorWind, HAND_WAZA_RazorWindOnChargeTurn, HAND_WAZA_AddSkyAttack, HAND_WAZA_SkyAttackOnChargeTurn, HAND_WAZA_AddSkullBash, HAND_WAZA_SkullBashOnChargeTurn, HAND_WAZA_AddPluck, HAND_WAZA_PluckEatTargetBerry, HAND_WAZA_AddStruggle, HAND_WAZA_StruggleSetSkipFlag, HAND_WAZA_StruggleShowNoMovesMessage, HAND_WAZA_StruggleSetFlag4B, HAND_WAZA_AddDestinyBond, HAND_WAZA_DestinyBondOnUse, HAND_WAZA_RemoveOnUserAction, HAND_WAZA_DestinyBondOnFaint, HAND_WAZA_AddGrudge, HAND_WAZA_GrudgeOnUse, HAND_WAZA_GrudgeOnFaint, HAND_WAZA_AddMinimize, HAND_WAZA_MinimizeSetState, HAND_WAZA_AddDefenseCurl, HAND_WAZA_DefenseCurlSetState, HAND_WAZA_AddRoost, HAND_WAZA_RoostGroundFlyingType, HAND_WAZA_AddFocusPunch, HAND_WAZA_FocusPunchTense, HAND_WAZA_AddMetronome, HAND_WAZA_MetronomePickMove, HAND_WAZA_MetronomeSetFailMessage, HAND_WAZA_AddNaturePower, HAND_WAZA_NaturePowerPickMove, HAND_WAZA_NaturePowerSetFailMessage, HAND_WAZA_AddAssist, HAND_WAZA_AssistPickMove, HAND_WAZA_AddSleepTalk, HAND_WAZA_SleepTalkPickMove, HAND_WAZA_AddMirrorMove, HAND_WAZA_MirrorMovePickMove, HAND_WAZA_AddMeFirst, HAND_WAZA_MeFirstPickMove, HAND_WAZA_MeFirstBoostPower, HAND_WAZA_AddCopycat, HAND_WAZA_CopycatPickMove, HAND_WAZA_AddAllStatBoostChance, HAND_WAZA_AllStatBoostSetChance, HAND_WAZA_AddVenoshock, HAND_WAZA_VenoshockDoublePowerOnPoison, HAND_WAZA_AddHex, HAND_WAZA_HexDoublePowerOnStatus, HAND_WAZA_AddAcrobatics, HAND_WAZA_AcrobaticsDoublePowerWithoutItem, HAND_WAZA_AddStoredPower, HAND_WAZA_StoredPowerAddPowerPerStage, HAND_WAZA_AddHeavySlam, HAND_WAZA_HeavySlamSetPowerByWeight, HAND_WAZA_AddElectroBall, HAND_WAZA_ElectroBallSetPowerBySpeed, HAND_WAZA_AddEchoedVoice, HAND_WAZA_EchoedVoiceSetPowerByStreak, HAND_WAZA_AddRetaliate, HAND_WAZA_RetaliateDoublePowerAfterAllyFaint, HAND_WAZA_AddFoulPlay, HAND_WAZA_FoulPlayUseTargetAttack, HAND_WAZA_AddSoak, HAND_WAZA_SoakSetWaterType, HAND_WAZA_AddSimpleBeam, HAND_WAZA_SimpleBeamSetAbility, HAND_WAZA_AddEntrainment, HAND_WAZA_EntrainmentCopyAbility, HAND_WAZA_AddClearSmog, HAND_WAZA_ClearSmogResetTargetRanks, HAND_WAZA_AddIncinerate, HAND_WAZA_IncinerateBurnBerry, HAND_WAZA_AddCircleThrow, HAND_WAZA_CircleThrowForceSwitch, HAND_WAZA_AddSmackDown, HAND_WAZA_SmackDownGroundTarget, HAND_WAZA_AddShellSmash, HAND_WAZA_ShellSmashChangeStats, HAND_WAZA_AddReflectType, HAND_WAZA_ReflectTypeCopyTargetType, HAND_WAZA_AddAutotomize, HAND_WAZA_AutotomizeLoseWeight, HAND_WAZA_AddPsyshock, HAND_WAZA_PsyshockSwapDefenseStat, HAND_WAZA_AddChipAway, HAND_WAZA_ChipAwayIgnoreDefenseStages, HAND_WAZA_ChipAwayIgnoreEvasionStages, HAND_WAZA_AddWonderRoom, HAND_WAZA_WonderRoomToggle, HAND_WAZA_AddMagicRoom, HAND_WAZA_MagicRoomToggle, HAND_WAZA_AddFlameBurst, HAND_WAZA_FlameBurstDamageAdjacent, HAND_WAZA_AddSynchronoise, HAND_WAZA_SynchronoiseFailWithoutSharedType, HAND_WAZA_AddBestow, HAND_WAZA_BestowGiveItem, HAND_WAZA_AddFinalGambit, HAND_WAZA_FinalGambitSetFixedDamage, HAND_WAZA_AddAfterYou, HAND_WAZA_AfterYouMoveTargetNext, HAND_WAZA_AddQuash, HAND_WAZA_QuashMoveTargetLast, HAND_WAZA_AddRound, HAND_WAZA_RoundRegisterUse, HAND_WAZA_RoundDoublePower, HAND_WAZA_GetQuickGuardHandlers, HAND_WAZA_QuickGuardOnUncategorizedMoveNoTarget, HAND_WAZA_GetAllySwitchHandlers, HAND_WAZA_AllySwitchSwapPositions, HAND_WAZA_GetTelekinesisHandlers, HAND_WAZA_TelekinesisCheckTarget, HAND_WAZA_TelekinesisSetStatusMessage, HAND_WAZA_GetSkyDropHandlers, HAND_WAZA_SkyDropBlockAllyTarget, HAND_WAZA_SkyDropStartCharge, HAND_WAZA_SkyDropReleaseTarget, HAND_WAZA_SkyDropRedirectToHeldTarget, HAND_WAZA_SkyDropFailIfTargetGone, HAND_WAZA_SkyDropBlockFlyingTarget, HAND_WAZA_GetRelicSongHandlers, HAND_WAZA_RelicSongChangeForm, HAND_WAZA_GetForesightHandlers, HAND_WAZA_ForesightSetGhostType, HAND_WAZA_GetMiracleEyeHandlers, HAND_WAZA_MiracleEyeSetDarkType, HAND_WAZA_GetGrowthHandlers, HAND_WAZA_GrowthBoostInSun, HAND_WAZA_GetFreezeShockIceBurnHandlers, HAND_WAZA_FreezeShockIceBurnShowChargeMessage, HAND_WAZA_GetFusionHandlers, HAND_WAZA_FusionDoublePower, HAND_WAZA_FindPledgeCombo, HAND_WAZA_GetPledgeHandlers, HAND_WAZA_PledgeCheckCombo, HAND_WAZA_PledgeShowWaitMessage, HAND_WAZA_PledgeSkipWait, HAND_WAZA_PledgeSetCombinedPower, HAND_WAZA_PledgeSetCombinedMoveId, HAND_WAZA_PledgeApplyCombinedEffect
 * address:  0x021E0284
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Hidden setter that follows a linker veneer, so it cannot join the unit before it.
 * The callee's word result is a one-word struct (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 * Hidden getter that follows a linker veneer, so it cannot join the unit before it.
 * gPsyshockHandlers: the ov093 hint is contested at this address; the plain
 * `data a4` line resolves it as sole-ref/data.
 * gBestowHandlers: the ov093 hint is contested at this address; the plain
 * Cut from hand_waza.c by tools/splitfile.py.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_SERVER_FLOW_IsActionCounterSet  0x021C7EC4  thumb  ov093
 *   gWazaHandlerRegistry  0x021F3030  data
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_AddFactor  0x021D6F0C  thumb  ov093
 *   BTL_EVENT_FindFactor  0x021D732C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_EVENT_FindNextFactor  0x021D7360  thumb  ov093
 *   BTL_EVENT_GetFactorWork  0x021D70B4  thumb  ov093
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb  ov093
 *   BTL_POKEPARAM_GetMoveId  0x021D54C0  thumb  ov093
 *   WAZA_TOOL_GetType  0x0201C1C8  thumb
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_TYPEPAIR_MakeSingle  0x021E8CF0  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gHandWazaConversionHandlers     0x021F261C  data   ov093  a4
 *   gHandWazaCamouflageHandlers     0x021F2414  data   ov093  a4
 *   BTL_SERVER_FLOW_GetFieldSituationType  0x021C8174  thumb  ov093
 *   BTL_POKEPARAM_GetTypePair  0x021D57FC  thumb  ov093
 *   BTL_FIELD_IsStaticSlotInUse  0x021EF948  thumb  ov093
 *   BTL_SICKCONT_MakeKind2Index  0x021E8940  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gTrickRoomHandlers     0x021F26F4  data   ov093  a4
 *   gGravityHandlers     0x021F2424  data   ov093  a4
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SICKCONT_MakeKind3  0x021E899C  thumb  ov093
 *   gWaterSportHandlers     0x021F2664  data   ov093  a4
 *   gMudSportHandlers     0x021F2614  data   ov093  a4
 *   gDefogHandlers     0x021F29B8  data   ov093  a4
 *   HAND_SIDE_IsActive  0x06898CF4  thumb
 *   BTL_ID_IsMimicExcludedMove  0x0689CA7C  thumb
 *   gBrickBreakHandlers 0x021F2B70 data a4
 *   BTL_POKEPARAM_HasSubstitute 0x021D6D7C thumb ov093
 *   BTL_MAIN_IsPokeIdInSecondPair 0x021B9A40 thumb ov093
 *   BTL_EVENT_SetFactorSkipCheck  0x021D7320  thumb  ov093
 *   BTL_EVENT_ClearFactorSkipCheck   0x021D7324  thumb
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   gJumpKickHandlers     0x021F2504  data    a4
 *   BTL_POKEPARAM_IsTransformed 0x021D6D54 thumb ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId 0x021D67A8 thumb ov093
 *   BTL_POKEPARAM_GetLastSelectedMoveId 0x021D67B8 thumb ov093
 *   BTL_POKEPARAM_FindMoveSlot 0x021D5778 thumb ov093
 *   gMimicHandlers     0x021F280C  data   ov093  a4
 *   gSketchHandlers     0x021F264C  data   ov093  a4
 *   gRefreshHandlers     0x021F2434  data   ov093  a4
 *   gFollowMeHandlers 0x021F2D78 data a4
 *   BTL_POKEPARAM_HasMove 0x021D5750 thumb ov093
 *   BTL_SERVER_FLOW_GetRule  0x021C815C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair   0x021B9A24  thumb ov093
 *   BTL_POKEPARAM_HasSick   0x021D62C4  thumb ov093
 *   BTL_SERVER_FLOW_TestStateFlagBit0   0x021C830C  thumb ov093
 *   BTL_SERVER_FLOW_CheckAllyMoveAutoHitById   0x021C8290  thumb ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_CALC_MakeSickContPoke  0x021D7D9C  thumb  ov093
 *   gTrapHandlers     0x021F2644  data   ov093  a4
 *   gHazeHandlers     0x021F2594  data   ov093  a4
 *   gSplashHandlers     0x021F26FC  data   ov093  a4
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds  0x021C7F68  thumb  ov093
 *   BTL_CALC_GetCurseTargetKind  0x021D80A8  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_SICKCONT_MakeKind1Empty  0x021E89C0  thumb  ov093
 *   BTL_SERVER_FLOW_SetCurTurnStateFlag  0x021C83DC  thumb  ov093
 *   gCurseHandlers     0x021F28D8  data   ov093  a4
 *   gThunderWaveHandlers     0x021F24D4  data   ov093  a4
 *   gWorrySeedHandlers     0x021F2A48  data   ov093  a4
 *   gDreamEaterHandlers     0x021F28E8  data   ov093  a4
 *   gCaptivateHandlers     0x021F266C  data   ov093  a4
 *   gTriAttackHandlers     0x021F263C  data   ov093  a4
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 *   gTriAttackSickIds     0x021F286C  data   ov093  a4
 *   gChatterHandlers 0x021F253C data a4
 *   BTL_CALC_MakeSickContFromKind 0x021D7DC0 thumb ov093
 *   gSecretPowerHandlers     0x021F2908  data   ov093  a4
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_SERVER_FLOW_QueryPokeClientFlag  0x021C7ED8  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   BTL_SICKCONT_SetValue  0x021E8B28  thumb  ov093
 *   gBindSickHandlers     0x021F2918  data   ov093  a4
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   gWhirlpoolHandlers     0x021F2D98  data   ov093  a4
 *   gSuperFangHandlers     0x021F25A4  data   ov093  a4
 *   gDragonRageHandlers     0x021F26EC  data   ov093  a4
 *   gSonicBoomHandlers     0x021F256C  data   ov093  a4
 *   gEndeavorHandlers     0x021F2938  data   ov093  a4
 *   gLevelDamageHandlers     0x021F2554  data   ov093  a4
 *   gPsywaveHandlers     0x021F2494  data   ov093  a4
 *   BTL_POKEPARAM_GetCounter  0x021D69AC  thumb  ov093
 *   gSpitUpHandlers 0x021F2BD0 data a4
 *   gSwallowHandlers 0x021F2BE8 data a4
 *   gStockpileHandlers     0x021F2948  data   ov093  a4
 *   gCounterHandlers     0x021F2C00  data   ov093  a4
 *   gMirrorCoatHandlers     0x021F2C18  data   ov093  a4
 *   gMetalBurstHandlers     0x021F2C30  data   ov093  a4
 *   BTL_SERVER_FLOW_GetPosTableEntryForPoke  0x021C7D44  thumb  ov093
 *   BTL_SERVER_FLOW_DecideMoveTarget  0x021C8030  thumb  ov093
 *   BTL_CALC_MulRatio  0x021D7B10  thumb  ov093
 *   BTL_POKEPARAM_GetHitRecord  0x021D6940  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   gLastResortHandlers     0x021F25C4  data   ov093  a4
 *   BTL_POKEPARAM_GetMoveUsedFlag  0x021D54E0  thumb  ov093
 *   gSnoreHandlers     0x021F2978  data   ov093  a4
 *   gNightmareHandlers     0x021F24DC  data   ov093  a4
 *   gSuckerPunchHandlers     0x021F24B4  data   ov093  a4
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   BTL_SERVER_FLOW_GetActionWordByPokeId  0x021C804C  thumb  ov093
 *   BTL_ACTION_GetFightMove  0x021D8340  thumb  ov093
 *   WAZA_TOOL_IsDamaging  0x0201C314  thumb
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_AppendFrontOrder  0x021C831C  thumb  ov093
 *   HAND_COMMON_EventScaleDamage  0x021E8860  thumb  ov093
 *   gPursuitHandlers     0x021F2C48  data   ov093  a4
 *   gSelfDestructHandlers     0x021F2C60  data   ov093  a4
 *   gFocusEnergyHandlers     0x021F24FC  data   ov093  a4
 *   gChargeHandlers     0x021F2DD8  data   ov093  a4
 *   gPerishSongHandlers     0x021F2988  data   ov093  a4
 *   BTL_SICKCONT_MakeKind1Value  0x021E89D4  thumb  ov093
 *   gLeechSeedHandlers     0x021F250C  data   ov093  a4
 *   gPayDayHandlers     0x021F247C  data   ov093  a4
 *   BTL_SERVER_FLOW_TryAddMainCounter  0x021C83E8  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   gRageHandlers     0x021F2C78  data   ov093  a4
 *   gAquaRingHandlers     0x021F2514  data   ov093  a4
 *   BTL_SICKCONT_MakeKind2  0x021E896C  thumb  ov093
 *   gThrashHandlers     0x021F2C90  data   ov093  a4
 *   BTL_SERVER_FLOW_GetScratchBuffer 0x021C8120 thumb ov093
 *   gUproarHandlers     0x021F2E78  data   ov093  a4
 *   gTripleKickHandlers     0x021F29C8  data   ov093  a4
 *   gRolloutHandlers     0x021F2EA0  data   ov093  a4
 *   BTL_SERVER_FLOW_CalcPokeSpeedWrapper  0x021C81C8  thumb  ov093
 *   gRevengeHandlers     0x021F2474  data   ov093  a4
 *   gGyroBallHandlers     0x021F248C  data   ov093  a4
 *   gFlailHandlers     0x021F26AC  data   ov093  a4
 *   gFlailPowerTable     0x021F2CA8  data   ov093  a2
 *   d_021F2CAA     0x021F2CAA  data   ov093  a2
 *   gFacadeHandlers     0x021F249C  data   ov093  a4
 *   gPaybackHandlers     0x021F2444  data   ov093  a4
 *   gEruptionHandlers     0x021F24A4  data   ov093  a4
 *   WAZA_TOOL_GetPower  0x0201C1D8  thumb
 *   gWringOutHandlers     0x021F2564  data   ov093  a4
 *   BTL_POKEPARAM_GetHpRatioFixed  0x021D5C44  thumb  ov093
 *   BTL_CALC_MulRatioMin1  0x021D7B2C  thumb  ov093
 *   gBrineHandlers     0x021F24AC  data   ov093  a4
 *   gReturnHandlers     0x021F244C  data   ov093  a4
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   gFrustrationHandlers     0x021F241C  data  ov093  a4
 *   gWakeUpSlapHandlers     0x021F29F8  data  ov093  a4
 *   gSmellingSaltHandlers     0x021F2A08  data  ov093  a4
 *   gPresentHandlers     0x021F2CC0  data  a4
 *   BTL_CALC_RollPercent  0x021D7AF0  thumb  ov093
 *   BTL_POKEPARAM_IsHpFull  0x021D5B48  thumb  ov093
 *   BTL_POKEPARAM_GetMovePPChecked  0x021D5584  thumb  ov093
 *   gTrumpCardPowerByPp     0x021F2860  data  ov093  a4
 *   gPunishmentHandlers     0x021F24BC  data  a4
 *   gPunishmentStatIds     0x021F2D3C  data  ov093  a4
 *   gFuryCutterHandlers     0x021F24C4  data  ov093  a4
 *   BTL_POKEPARAM_GetMoveStreak  0x021D679C  thumb  ov093
 *   gAssuranceHandlers     0x021F25AC  data  ov093  a4
 *   gLowKickHandlers     0x021F24CC  data  ov093  a4
 *   gTrumpCardHandlers     0x021F272C  data   ov093  a4
 *   BTL_SERVER_FLOW_CalcPokeWeight  0x021C83A0  thumb  ov093
 *   gWeatherBallHandlers     0x021F2A18  data  ov093  a4
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
 *   gSkyUppercutHandlers  0x021F2464  data   ov093  a4
 *   gGustHandlers     0x021F2A28  data   ov093  a4
 *   gThunderHandlers     0x021F2D08  data   ov093  a4
 *   gBlizzardHandlers     0x021F246C  data   ov093  a4
 *   gJudgmentHandlers  0x021F25F4  data   a4
 *   gEarthquakeHandlers     0x021F2A58  data   ov093  a4
 *   BTL_SERVER_FLOW_CanUseHeldItem  0x021C824C  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   gTechnoBlastHandlers  0x021F271C  data   a4
 *   gKnockOffHandlers     0x021F2844  data   ov093  a4
 *   gHiddenPowerHandlers  0x021F2A78  data   a4
 *   POKE_TOOL_GetHiddenPowerType  0x02018790  thumb
 *   POKE_TOOL_GetHiddenPowerPower  0x02018820  thumb
 *   gNaturalGiftHandlers 0x021F2E18 data a4
 *   BTL_CALC_GetItemParam  0x021D805C  thumb  ov093
 *   BTLV_CORE_CheckEitherSlotPair   0x021E86E8  thumb ov093
 *   HAND_COMMON_IsLastToAct  0x021E8624  thumb  ov093
 *   HAND_COMMON_EventRedirectMove  0x021E8744  thumb  ov093
 *   HAND_COMMON_EventCounterMove  0x021E8798  thumb  ov093
 *   HAND_COMMON_EventQueueMoveNotice  0x021E8804  thumb  ov093
 *   gMagicCoatHandlers     0x021F2F18  data   ov093  a4
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   gSnatchHandlers     0x021F2E38  data   ov093  a4
 *   gTrickHandlers 0x021F2824 data a4
 *   gThiefHandlers     0x021F2A98  data   ov093  a4
 *   gMagnitudeHandlers 0x021F2E58 data a4
 *   BTLV_CORE_CheckPartySlotCondition 0x021E86C8 thumb ov093
 *   HAND_COMMON_IsItemBoundToSpecies 0x021E8638 thumb ov093
 *   gMagnitudeRows  0x021F2878  data   a1
 *   gStompHandlers     0x021F2804  data   a4
 *   gFalseSwipeHandlers     0x021F27FC  data   a4
 *   gSurfHandlers     0x021F2AB8  data   ov093  a4
 *   gEndureHandlers     0x021F2FC8  data   ov093  a4
 *   gProtectMoveIds     0x021F284C  data   a2
 *   gProtectHandlers     0x021F2D58  data   ov093  a4
 *   gProtectFailRange     0x021F2856  data   a1
 *   gBideHandlers     0x021F2FF8  data   a4
 *   BTL_POKEPARAM_GetHitCount  0x021D6920  thumb  ov093
 *   BTL_POKEPARAM_GetConsumedItem  0x021D6740  thumb  ov093
 *   gPsychoShiftHandlers     0x021F27C4  data   a4
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb  ov093
 *   BTL_SICKCONT_IsKind1Index15  0x021E8A78  thumb  ov093
 *   BTL_SICKCONT_MakeKind1Index15  0x021E8A58  thumb  ov093
 *   gPainSplitHandlers     0x021F27BC  data   a4
 *   gBellyDrumHandlers 0x021F27B4 data a4
 *   gRecycleHandlers     0x021F27CC  data   ov093  a4
 *   gAcupressureHandlers     0x021F27A4  data   ov093  a4
 *   BTL_POKEPARAM_GetStatStageRoom 0x021D5D50 thumb ov093
 *   gFeintHandlers 0x021F2B10 data a4
 *   BTL_MAIN_IsZero  0x021B9A5C  thumb  ov093
 *   BTL_SERVER_FLOW_CheckSideEffectActive  0x021C82C4  thumb  ov093
 *   BTL_ID_IsEncoreFailMove  0x0689C8AC  thumb
 *   BTL_POKEPARAM_CanChangeStatStage 0x021D5D14 thumb ov093
 *   gAcupressureStats 0x021F2D20 data a4
 *   gRestHandlers 0x021F2888 data a4
 *   BTL_CALC_MakeSickContTurns 0x021D7D78 thumb ov093
 *   gAttractHandlers 0x021F278C data a4
 *   BTL_POKEPARAM_GetLastTargetPos  0x021D67B0  thumb  ov093
 *   BTL_CALC_ListResistingTypes  0x021D7A9C  thumb  ov093
 *   MI_CpuCopy8  0x02082D44  arm
 *   gConversion2Handlers     0x021F2784  data   ov093  a4
 *   BTL_POKEPARAM_GetMovePPById  0x021D55A0  thumb  ov093
 *   gEncoreHandlers     0x021F25E4  data   ov093  a4
 *   gTauntHandlers     0x021F2774  data   ov093  a4
 *   gTormentHandlers     0x021F28A8  data   ov093  a4
 *   gDisableHandlers     0x021F2764  data   ov093  a4
 *   gImprisonHandlers     0x021F2534  data   ov093  a4
 *   gAromatherapyHandlers     0x021F2B88  data   ov093  a4
 *   gHealBellHandlers     0x021F2BA0  data   ov093  a4
 *   BTL_SERVER_FLOW_GetPartyOfPoke  0x021C7FCC  thumb  ov093
 *   BTL_SERVER_FLOW_GetPartyOfPokeIfClientUsed  0x021C7FE0  thumb  ov093
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   BTL_SERVER_FLOW_NextSerialNumberThunk  0x021C83CC  thumb  ov093
 *   gMementoHandlers     0x021F2744  data   ov093  a4
 *   gSpiteHandlers     0x021F273C  data   ov093  a4
 *   gPsychUpHandlers     0x021F25BC  data   ov093  a4
 *   gPowerSwapHandlers 0x021F2724 data a4
 *   gGuardSwapHandlers 0x021F2544 data a4
 *   gHeartSwapHandlers     0x021F275C  data   ov093  a4
 *   gPowerTrickHandlers 0x021F26BC data a4
 *   gPowerSplitHandlers     0x021F26E4  data   ov093  a4
 *   BTL_POKEPARAM_GetStatRaw  0x021D58A8  thumb  ov093
 *   gGuardSplitHandlers 0x021F2704 data a4
 *   gLockOnHandlers 0x021F26DC data a4
 *   BTL_SICKCONT_MakeKind4  0x021E8A28  thumb  ov093
 *   gReflectHandlers     0x021F25FC  data   ov093  a4
 *   gLightScreenHandlers     0x021F259C  data   ov093  a4
 *   gSafeguardHandlers     0x021F25CC  data   ov093  a4
 *   gMistHandlers     0x021F2794  data   ov093  a4
 *   gTailwindHandlers     0x021F25EC  data   ov093  a4
 *   gLuckyChantHandlers     0x021F260C  data   ov093  a4
 *   BTL_MAIN_IsPokeIdInFirstPair  0x021B9A50  thumb  ov093
 *   gSpikesHandlers     0x021F2604  data   ov093  a4
 *   gToxicSpikesHandlers     0x021F243C  data   ov093  a4
 *   gStealthRockHandlers     0x021F26B4  data   ov093  a4
 *   gTransformHandlers     0x021F2484  data   ov093  a4
 *   gWideGuardHandlers     0x021F2DF8  data   ov093  a4
 *   gLunarDanceHandlers     0x021F252C  data   ov093  a4
 *   BTL_SERVER_FLOW_CheckClientHasBackupPoke  0x021C7F24  thumb  ov093
 *   gHealingWishHandlers     0x021F2694  data   ov093  a4
 *   gWishHandlers     0x021F254C  data   ov093  a4
 *   BTL_ID_IsAbilityRolePlayBlocked  0x0689C91C  thumb
 *   gFutureSightHandlers     0x021F29D8  data   ov093  a4
 *   BTL_MAIN_GetEnemyLanePos  0x021B8C20  thumb  ov093
 *   BTL_SERVER_FLOW_GetTurnCount  0x021C8138  thumb  ov093
 *   gDoomDesireHandlers     0x021F29E8  data   ov093  a4
 *   gGastroAcidHandlers     0x021F2674  data   ov093  a4
 *   gRolePlayHandlers     0x021F24F4  data   ov093  a4
 *   gUTurnHandlers     0x021F2584  data   ov093  a4
 *   BTL_SERVER_FLOW_TrySetOnceFlag  0x021C7F4C  thumb  ov093
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   gRapidSpinHandlers     0x021F258C  data   ov093  a4
 *   gBatonPassHandlers     0x021F2454  data   ov093  a4
 *   gTeleportHandlers     0x021F2CD8  data   ov093  a4
 *   BTL_SERVER_FLOW_GetCompetitor  0x021C8168  thumb  ov093
 *   BTL_EVENT_KeepFactorRunning  0x021D70C8  thumb  ov093
 *   HAND_COMMON_IsHeldItemBoundToOwnSpecies  0x021E869C  thumb  ov093
 *   gFlingHandlers     0x021F2EC8  data   ov093  a4
 *   gMagnetRiseHandlers     0x021F2A38  data   ov093  a4
 *   BTL_SERVER_FLOW_GetActivePosPerSide   0x021C8180  thumb ov093
 *   BTL_EVENT_MarkFactorDead   0x021D7090  thumb ov093
 *   gHelpingHandHandlers     0x021F2EF0  data   ov093  a4
 *   BTL_POKEPARAM_IsAbleToBattle  0x021D5B7C  thumb  ov093
 *   gBeatUpHandlers     0x021F2A68  data   ov093  a4
 *   gFakeOutHandlers     0x021F242C  data   ov093  a4
 *   gWeatherHealHandlers     0x021F240C  data   ov093  a4
 *   gFlyHandlers     0x021F2A88  data   ov093  a4
 *   gBounceHandlers     0x021F2AA8  data   ov093  a4
 *   gShadowForceHandlers     0x021F2F40  data   ov093  a4
 *   gDiveHandlers     0x021F2AC8  data   ov093  a4
 *   gDigHandlers     0x021F2AD8  data   ov093  a4
 *   gSolarBeamHandlers     0x021F2AF8  data   ov093  a4
 *   gSkyAttackHandlers     0x021F25DC  data  a4
 *   gSkullBashHandlers     0x021F25D4  data   ov093  a4
 *   gRazorWindHandlers     0x021F27D4  data   ov093  a4
 *   gPluckHandlers     0x021F27AC  data   ov093  a4
 *   BTL_ID_IsMetronomeItemIgnoredMove  0x0689C8CC  thumb  ov095
 *   ITEM_IsBerry  0x020213C0  thumb
 *   gStruggleHandlers     0x021F2B28  data   ov093  a4
 *   gDestinyBondHandlers     0x021F2B40  data   ov093  a4
 *   gGrudgeHandlers     0x021F2B58  data   ov093  a4
 *   gMinimizeHandlers     0x021F276C  data   ov093  a4
 *   gDefenseCurlHandlers     0x021F2754  data   ov093  a4
 *   gRoostHandlers     0x021F255C  data   ov093  a4
 *   gFocusPunchHandlers     0x021F2734  data   ov093  a4
 *   BTL_SICKCONT_SetFlag  0x021E8BD0  thumb  ov093
 *   BTL_ID_GetMetronomeExcludedMoves  0x0689CA8C  thumb
 *   BTL_POKEPARAM_IsSemiInvulnerable  0x021D5C30  thumb  ov093
 *   BTL_CALC_PickRandomMoveExcluding  0x021D7E44  thumb  ov093
 *   gMetronomeWazaHandlers     0x021F28F8  data    a4
 *   BTL_ID_IsAssistExcludedMove  0x0689CA3C  thumb
 *   gNaturePowerHandlers     0x021F2928  data   ov093  a4
 *   gAssistHandlers     0x021F270C  data   ov093  a4
 *   BTL_ID_IsSleepTalkExcludedMove  0x0689CA1C  thumb
 *   gSleepTalkHandlers     0x021F2BB8  data   ov093  a4
 *   gMirrorMoveHandlers     0x021F2574  data   ov093  a4
 *   BTL_ID_IsMeFirstFailMove  0x0689C8BC  thumb
 *   BTL_SERVER_FLOW_IsPokeInPosTable 0x021C814C thumb ov093
 *   BTL_SERVER_FLOW_IsPokeAfflictedByStatus 0x021C8374 thumb ov093
 *   gMeFirstHandlers     0x021F2968  data    a4
 *   BTL_ID_IsCopycatExcludedMove  0x0689CA5C  thumb
 *   BTL_SERVER_FLOW_GetLastActionId  0x021C8114  thumb  ov093
 *   gCopycatHandlers     0x021F26C4  data    a4
 *   gAllStatBoostChanceHandlers     0x021F262C  data   ov093  a4
 *   gVenoshockHandlers     0x021F251C  data   ov093  a4
 *   gHexHandlers     0x021F2524  data   ov093  a4
 *   gAcrobaticsHandlers     0x021F268C  data   ov093  a4
 *   gStoredPowerStatIds     0x021F2404  data   ov093  a1
 *   gHeavySlamHandlers      0x021F2654  data   ov093  a4
 *   gStoredPowerHandlers    0x021F267C  data   ov093  a4
 *   gElectroBallHandlers    0x021F245C  data   ov093  a4
 *   BTL_ID_IsAbilityEntrainmentBlocked  0x0689C93C  thumb
 *   BTL_WAZAREC_IsUsedWaza  0x0689D064  thumb
 *   BTL_DEADREC_GetCount  0x0689D174  thumb
 *   BTL_DEADREC_GetPokeId  0x0689D184  thumb
 *   gEchoedVoiceHandlers     0x021F24EC  data   ov093  a4
 *   BTL_SERVER_FLOW_GetTurnRecord  0x021C812C  thumb  ov093
 *   BTL_SERVER_FLOW_GetHistoryList  0x021C8130  thumb  ov093
 *   gRetaliateHandlers     0x021F2624  data   ov093  a4
 *   gFoulPlayHandlers     0x021F2834  data   ov093  a4
 *   gSimpleBeamHandlers     0x021F27F4  data   ov093  a4
 *   gSoakHandlers     0x021F282C  data   ov093  a4
 *   gEntrainmentHandlers     0x021F27DC  data   ov093  a4
 *   gClearSmogHandlers     0x021F24E4  data   ov093  a4
 *   gCircleThrowHandlers     0x021F277C  data   ov093  a4
 *   gIncinerateHandlers     0x021F279C  data   ov093  a4
 *   BTL_SERVER_FLOW_IsPokeGroundedById  0x021C8234  thumb  ov093
 *   gSmackDownHandlers     0x021F28B8  data   ov093  a4
 *   gShellSmashHandlers     0x021F274C  data   ov093  a4
 *   gReflectTypeHandlers     0x021F2714  data   ov093  a4
 *   gAutotomizeHandlers     0x021F257C  data   ov093  a4
 *   BTL_POKEPARAM_GetWeight  0x021D67E8  thumb  ov093
 *   gPsyshockHandlers     0x021F26D4  data   a4
 *   gChipAwayHandlers     0x021F2998  data   ov093  a4
 *   gMagicRoomHandlers     0x021F2684  data   ov093  a4
 *   gFlameBurstHandlers     0x021F265C  data   ov093  a4
 *   BTL_SERVER_FLOW_GetPokeIdAtPos 0x021C7D34 thumb ov093
 *   gSynchronoiseHandlers 0x021F2634 data a4
 *   gWonderRoomHandlers     0x021F269C  data   ov093  a4
 *   BTL_TYPEPAIR_ShareType  0x021E8D48  thumb  ov093
 *   gBestowHandlers     0x021F283C  data   a4
 *   FILE_UTIL_IsMailItem 0x0202136C thumb
 *   gFinalGambitHandlers 0x021F2AE8 data a4
 *   gAfterYouHandlers     0x021F27EC  data   ov093  a4
 *   gQuashHandlers     0x021F25B4  data   ov093  a4
 *   BTL_WAZAREC_GetUsedWazaCount  0x0689D098  thumb
 *   gRoundHandlers     0x021F28C8  data   ov093  a4
 *   gQuickGuardHandlers     0x021F2DB8  data   ov093  a4
 *   gAllySwitchHandlers     0x021F26CC  data    a4
 *   BTL_SERVER_FLOW_GetClientIdBySide  0x021C8300  thumb  ov093
 *   BTL_MAIN_GetOwnLanePos  0x021B8C38  thumb  ov093
 *   BTL_MAIN_IsBackRowPos  0x021B99F0  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeIdAtFieldIndex  0x021C8020  thumb  ov093
 *   gTelekinesisHandlers     0x021F29A8  data   ov093  a4
 *   BTL_SERVER_FLOW_ProcMoveReflectOrAbsorbById  0x021C846C  thumb  ov093
 *   BTL_SERVER_FLOW_ReleaseBindingTargetById  0x021C8494  thumb  ov093
 *   gSkyDropHandlers     0x021F2F98  data   ov093  a4
 *   gRelicSongHandlers     0x021F281C  data   ov093  a4
 *   gForesightOdorSleuthHandlers     0x021F2898  data   ov093  a4
 *   gMiracleEyeHandlers     0x021F2958  data   ov093  a4
 *   gGrowthHandlers     0x021F26A4  data   ov093  a4
 *   BTL_WAZAREC_GetEffectiveWaza  0x0689D0C8  thumb
 *   gFreezeShockIceBurnHandlers     0x021F2814  data   ov093  a4
 *   gFusionFlareFusionBoltHandlers     0x021F27E4  data   ov093  a4
 *   gPledgeComboTable  0x021F2CF0  data  a4
 *   BTL_POKEPARAM_GetStoredPokeMove  0x021D6E50  thumb  ov093
 *   gPledgeHandlers     0x021F2F68  data   ov093  a4
 *   _u32_div_f                   0x0209C2B0  arm
 */
#ifdef __MWERKS__
/* The original callers take the condition word as a plain word. */
#define BTL_POKEPARAM_FindMoveSlot BTL_POKEPARAM_FindMoveSlotHeader
#define BTL_CALC_MakeSickContPoke BTL_CALC_MakeSickContPokeHeader
#define WAZA_TOOL_GetFlag WAZA_TOOL_GetFlagHeader
#define BTL_TYPEPAIR_MakeSingle BTL_TYPEPAIR_MakeSingleHeader
#define BTL_POKEPARAM_GetMovePPChecked BTL_POKEPARAM_GetMovePPCheckedHeader
#define BTL_SERVER_FLOW_GetPokeIdAtFieldIndex BTL_SERVER_FLOW_GetPokeIdAtFieldIndexHeader
#define BTL_POKEPARAM_HasMove BTL_POKEPARAM_HasMoveHeader
#define BTL_SERVER_FLOW_GetPosTableEntryForPoke BTL_SERVER_FLOW_GetPosTableEntryForPokeHeader
#define WAZA_TOOL_IsDamaging WAZA_TOOL_IsDamagingHeader
#define BTL_ID_IsAbilityRolePlayBlocked BTL_ID_IsAbilityRolePlayBlockedHeader
#define BTL_WAZAREC_GetUsedWazaCount BTL_WAZAREC_GetUsedWazaCountHeader
#define BTL_SERVER_FLOW_GetActionWordByPokeId BTL_SERVER_FLOW_GetActionWordByPokeIdHeader
#endif
#include "hand_waza_types.h"
#include "hand_common_protos.h"

#define SPECIES_CHATOT 0x1b9
#define STOCKPILE_MAX 3
#define MOVE_LAST_RESORT 0x183
#define BTL_EVENT_SIGNATURE struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId
#define BTL_TAUNT_TURNS 3
#define BTL_DISABLE_TURNS 4
#define BTL_FIELD_EFFECT_IMPRISON 3
#define BTL_STR_IMPRISON 0x24a
#define BTL_PARTY_CURE_MAX 12
#define BTL_MOVE_SLOT_COUNT 4
#define BTL_STR_CURE_PARTY_AROMATHERAPY 0x70
#define BTL_STR_CURE_PARTY_HEAL_BELL 0x6f
#define BTL_STR_SPITE 641
#define BTL_SPITE_PP_MAX 4
#define BTL_RANK_BACKUP_SIZE 28
#define BTL_STR_PSYCH_UP 0x417
#define BTL_STR_HEART_SWAP 673
#define BTL_STR_POWER_SWAP 676
#define BTL_STR_GUARD_SWAP 679
#define BTL_STR_POWER_TRICK 0x305
#define BTL_STR_POWER_SPLIT 0x448
#define BTL_STR_GUARD_SPLIT 0x44b
#define BTL_STR_LOCK_ON 0x28b
#define BTL_LOCK_ON_TURNS 2
#define BTL_SIDE_EFFECT_STR_REFLECT 0x7c
#define BTL_SIDE_EFFECT_STR_LIGHT_SCREEN 0x80
#define BTL_SIDE_EFFECT_STR_SAFEGUARD 0x84
#define BTL_SIDE_EFFECT_STR_MIST 0x88
#define BTL_SIDE_EFFECT_STR_TAILWIND 0x8c
#define BTL_SIDE_EFFECT_STR_LUCKY_CHANT 0x90
#define BTL_SIDE_EFFECT_STR_SPIKES 0x94
#define BTL_SIDE_EFFECT_STR_TOXIC_SPIKES 0x98
#define HAND_WAZA_DEFINES_ADD_SIDE_EFFECT
#define BTL_SIDE_EFFECT_STR_STEALTH_ROCK 0x9c
#define BTL_SIDE_EFFECT_STR_WIDE_GUARD 0xa0
#define BTL_STR_TRANSFORM 0x284
#define HAZARD_TOXIC_SPIKES 7
#define HAZARD_STEALTH_ROCK 8
#define ITEM_PARAM_FLING_POWER 10
#define MAGNET_RISE_TURNS 5
#define SICK_ROOST_GROUNDED 0x18
#define BTL_VISIBILITY_FOCUS 5
#define BTL_ANIM_FOCUS_PUNCH_TENSE 0x272
#define BTL_ANIM_MODE_PLAY 6
#define BTL_TARGET_SLOT_NONE 6
#define BTL_WAZA_FLAG_MIRRORABLE 6
#define BTL_TURN_FLAG_ACTION_TAKEN 3 /* turn flag index 3; not the flag BTL_TURN_FLAG_ACTION_TAKEN (index 1) of the ability handlers */
#define HAND_WAZA_ABILITY_SIMPLE 0x56
struct BtlEventFactor;
struct BtlParty;
struct BtlServerFlow;
struct BtlPokeParam;
struct BtlEventNode;
union SickCont;
BtlStrParam;
struct BtlPartyView;
/* The status that Chatter adds; an enum local keeps the constant in a register (see below). */
typedef enum { CHATTER_SICK_CONFUSION = BTL_SICK_CONFUSION } ChatterSick;

/* Kind 0x1a record as Feint fills it: byte 0 selects the effect group, bytes 1 and 2 are flags. */
struct FeintRemoveRecord {
    u32 header;
    u8 filter[3];
    u8 side;
};

/* Encore lasts 3 turns, 4 when the target already acted this turn; the enum type keeps the byte arithmetic of the original. */
typedef enum { ENCORE_TURNS_BASE } EncoreTurns;

/*
 * stand-in: an enum typed local keeps its start value from being folded into
 * the (u8) increment (a u8 or int local gets 4 here, the image has 3 plus an add).
 */
typedef enum { BTL_TURN_COUNT_NONE } BtlTurnCount;

#include "btl_server_types.h"
#include "../arm9/poke_tool.h"
#include "btl_pokeparam.h"
struct PokemonParam;
#include "../arm9/file_util.h"
#include "../ov095/hand_side.h"
#include "../arm9/palanm.h"
union BtlvSlot;
#include "../ov095/btl_id_sets.h"
struct BtlWazaRec;
#include "../ov095/btl_wazarec.h"
struct BtlDeadRec;
#include "../ov095/btl_deadrec.h"
#include "btl_field.h"
#include "hand_common.h"
#include "btl_server_flow.h"
#include "btl_calc.h"
#include "../arm9/waza_tool.h"
#include "btl_main.h"
#include "btl_event.h"
#include "btl_typepair.h"
#include "btl_sickcont.h"
#ifdef __MWERKS__
#undef BTL_POKEPARAM_FindMoveSlot
#undef BTL_CALC_MakeSickContPoke
#undef WAZA_TOOL_GetFlag
#undef BTL_TYPEPAIR_MakeSingle
#undef BTL_POKEPARAM_GetMovePPChecked
#undef BTL_SERVER_FLOW_GetPokeIdAtFieldIndex
#undef BTL_POKEPARAM_HasMove
#undef BTL_SERVER_FLOW_GetPosTableEntryForPoke
#undef WAZA_TOOL_IsDamaging
#undef BTL_ID_IsAbilityRolePlayBlocked
#undef BTL_WAZAREC_GetUsedWazaCount
#undef BTL_SERVER_FLOW_GetActionWordByPokeId
extern int BTL_SERVER_FLOW_GetActionWordByPokeId(struct BtlServerFlow *flow, int pokeId, u32 *action);
extern u32 BTL_WAZAREC_GetUsedWazaCount(struct BtlWazaRec *record, int moveId, int turnCount);
extern int BTL_ID_IsAbilityRolePlayBlocked(u16 abilityId);
extern u32 WAZA_TOOL_IsDamaging(u32 moveId);
extern int BTL_SERVER_FLOW_GetPosTableEntryForPoke(struct BtlServerFlow *flow, int pos);
extern int BTL_POKEPARAM_HasMove(struct BtlPokeParam *bpp, int moveId);
extern u8 BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(struct BtlServerFlow *flow, int position);
extern u16 BTL_TYPEPAIR_MakeSingle(int value);
extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 flagBit);
extern u32 BTL_CALC_MakeSickContPoke(int pokeId);
extern u8 BTL_POKEPARAM_FindMoveSlot(struct BtlPokeParam *bpp, int moveId);
#endif
void HAND_ITEM_GemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work, u8 gemType);
void HAND_ITEM_GemMoveDamageEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int HAND_WAZA_AddMoveHandler(struct BtlPokeParam *bpp, u16 moveId, u32 subPriority);
int HAND_WAZA_CanAddMoveHandler(int ownerId, int moveId, u8 *alreadyAdded);
void HAND_WAZA_RemoveMoveHandlerUnlessKept(struct BtlPokeParam *bpp, int moveId);
void HAND_WAZA_RemoveMoveHandlerOfPoke(struct BtlPokeParam *bpp, int moveId);
int HAND_WAZA_IsKeptOnSuspend(struct BtlEventFactor *factor, u32 *work);
void HAND_WAZA_RemoveMoveHandlerById(int ownerId, int moveId);
void HAND_WAZA_RemoveAllMoveHandlers(struct BtlPokeParam *bpp);
BtlEventHandler *HAND_WAZA_GetConversionHandlers(int *handlerCount);
void HAND_WAZA_ConversionEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_GetCamouflageHandlers(int *handlerCount);
void HAND_WAZA_CamouflageChangeType(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetTrickRoomHandlers(int *handlerCount);
void HAND_WAZA_TrickRoomAddFieldEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetGravityHandlers(int *handlerCount);
void HAND_WAZA_GravityAddFieldEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetWaterSportHandlers(int *handlerCount);
void HAND_WAZA_WaterSportAddFieldEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetMudSportHandlers(int *handlerCount);
void HAND_WAZA_MudSportAddFieldEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetDefogHandlers(int *handlerCount);
void HAND_WAZA_DefogLowerEvasionRemoveSideEffects(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetBrickBreakHandlers(int *handlerCount);
void HAND_WAZA_BrickBreakSetSkipCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_BrickBreakClearSkipCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_BrickBreakRemoveScreens(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int HAND_WAZA_BrickBreakSkipScreens(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId);
const BtlEventHandler *HAND_WAZA_GetJumpKickHandlers(int *handlerCount);
void HAND_WAZA_JumpKickCrashOnFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_JumpKickDealCrashDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
const BtlEventHandler *HAND_WAZA_GetMimicHandlers(int *handlerCount);
void HAND_WAZA_MimicCopyTargetMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetSketchHandlers(int *handlerCount);
void HAND_WAZA_SketchLearnTargetMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetFollowMeHandlers(int *handlerCount);
void HAND_WAZA_FollowMeFailOutsideMultiBattle(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_FollowMeShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_FollowMeRedirectTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_FollowMeRemoveFactor(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetRefreshHandlers(int *handlerCount);
void HAND_WAZA_RefreshCureMajorStatus(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetTrapHandlers(int *handlerCount);
void HAND_WAZA_TrapAddNoEscape(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetHazeHandlers(int *handlerCount);
void HAND_WAZA_HazeResetRanks(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetSplashHandlers(int *handlerCount);
void HAND_WAZA_SplashShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetCurseHandlers(int *handlerCount);
void HAND_WAZA_CurseSetTargetKind(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_CurseApply(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetThunderWaveHandlers(int *handlerCount);
void HAND_WAZA_ThunderWaveSetAccuracyCheckFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetWorrySeedHandlers(int *handlerCount);
void HAND_WAZA_WorrySeedFailOnTruantOrInsomnia(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_WorrySeedChangeAbility(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetDreamEaterHandlers(int *handlerCount);
void HAND_WAZA_DreamEaterFailIfAwake(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_DreamEaterSetFailFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetCaptivateHandlers(int *handlerCount);
void HAND_WAZA_CaptivateFailOnSameOrNoGender(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetTriAttackHandlers(int *handlerCount);
void HAND_WAZA_TriAttackOnDecideAddSick(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddSecretPower(int *handlerCount);
u8 HAND_WAZA_SecretPowerGetGroundEffect(struct BtlServerFlow *flow, u8 *effectKind, u8 *effectValue);
void HAND_WAZA_SecretPowerOnPrepareMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
void HAND_WAZA_SecretPowerOnAddEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddChatter(int *handlerCount);
void HAND_WAZA_ChatterOnDecideAddSick(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddTrap(int *handlerCount);
void HAND_WAZA_TrapOnDecideAddSick(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
void HAND_WAZA_TrapOnAddSickMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddWhirlpool(int *handlerCount);
void HAND_WAZA_WhirlpoolOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
void HAND_WAZA_WhirlpoolOnCalcDamageRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddSuperFang(int *handlerCount);
void HAND_WAZA_SuperFangOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddDragonRage(int *handlerCount);
void HAND_WAZA_DragonRageOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddSonicBoom(int *handlerCount);
void HAND_WAZA_SonicBoomOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddEndeavor(int *handlerCount);
void HAND_WAZA_EndeavorOnNoEffectCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
void HAND_WAZA_EndeavorOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddLevelDamage(int *handlerCount);
void HAND_WAZA_LevelDamageOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddPsywave(int *handlerCount);
void HAND_WAZA_PsywaveOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddStockpile(int *handlerCount);
void HAND_WAZA_StockpileOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
void HAND_WAZA_StockpileOnMoveEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddSpitUp(int *handlerCount);
void HAND_WAZA_StockpileUseOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
void HAND_WAZA_SpitUpOnGetMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
void HAND_WAZA_StockpileUseOnMoveEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddSwallow(int *handlerCount);
void HAND_WAZA_SwallowOnCalcHealRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddCounter(int *handlerCount);
void HAND_WAZA_CounterOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
void HAND_WAZA_CounterOnDecideTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
void HAND_WAZA_CounterOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddMirrorCoat(int *handlerCount);
void HAND_WAZA_MirrorCoatOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
void HAND_WAZA_MirrorCoatOnDecideTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
void HAND_WAZA_MirrorCoatOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddMetalBurst(int *handlerCount);
void HAND_WAZA_MetalBurstOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
void HAND_WAZA_MetalBurstOnDecideTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
void HAND_WAZA_MetalBurstOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
void HAND_WAZA_RetaliateOnMoveFailCheck(struct BtlServerFlow *flow, int pokeId, void *work, int damageType);
void HAND_WAZA_RetaliateOnDecideTarget(struct BtlServerFlow *flow, int pokeId, void *work, int damageType);
void HAND_WAZA_RetaliateOnCalcFixedDamage(struct BtlServerFlow *flow, int pokeId, void *work, int damageType, int ratio);
int HAND_WAZA_FindRetaliateHit(struct BtlPokeParam *poke, int damageType, struct BtlHitRecord *out);
BtlEventHandler *HAND_WAZA_AddLastResort(int *handlerCount);
void HAND_WAZA_LastResortOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddSnore(int *handlerCount);
void HAND_WAZA_SnoreOnActionCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
void HAND_WAZA_SnoreOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddNightmare(int *handlerCount);
void HAND_WAZA_NightmareOnNoEffectCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddSuckerPunch(int *handlerCount);
void HAND_WAZA_SuckerPunchCheckNoEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_PursuitGetHandlers(int *handlerCount);
void HAND_WAZA_PursuitQueueIntercept(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_PursuitAlwaysHitOnIntercept(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_PursuitDoublePowerOnIntercept(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_SelfDestructGetHandlers(int *handlerCount);
void HAND_WAZA_SelfDestructFaintOnHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_SelfDestructPushUserCmd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_SelfDestructFaintOnFinish(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_FocusEnergyGetHandlers(int *handlerCount);
void HAND_WAZA_FocusEnergyApplyEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_ChargeGetHandlers(int *handlerCount);
void HAND_WAZA_ChargeStoreOnUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaChargeWork *work);
void HAND_WAZA_ChargeBoostElectricPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaChargeWork *work);
void HAND_WAZA_ChargeArmOnNextMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaChargeWork *work);
void HAND_WAZA_ChargeExpireOnMoveEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaChargeWork *work);
BtlEventHandler *HAND_WAZA_PerishSongGetHandlers(int *handlerCount);
void HAND_WAZA_PerishSongShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_PerishSongClearNoEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_LeechSeedGetHandlers(int *handlerCount);
void HAND_WAZA_LeechSeedSetSickCont(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_PayDayGetHandlers(int *handlerCount);
void HAND_WAZA_PayDayScatterCoins(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_RageGetHandlers(int *handlerCount);
void HAND_WAZA_RageKeepOnExecute(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_RageRaiseAttackOnHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_RageEndOnActionStart(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work);
BtlEventHandler *HAND_WAZA_AquaRingGetHandlers(int *handlerCount);
void HAND_WAZA_AquaRingApplyEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_ThrashGetHandlers(int *handlerCount);
void HAND_WAZA_ThrashStartLock(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_ThrashAdvanceTurn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_ThrashEndOnSleep(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_UproarGetHandlers(int *handlerCount);
void HAND_WAZA_UproarStart(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 pokeId, HandWazaWork *work);
void HAND_WAZA_UproarEndOnFailure(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_UproarOnTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_UproarPreventSleep(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_UproarPreventSleepSilently(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work);
BtlEventHandler *HAND_WAZA_RolloutGetHandlers(int *handlerCount);
void HAND_WAZA_RolloutStartLock(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_RolloutEndOnDoneOrFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_RolloutEndOnMoveEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_RolloutEndLock(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_RolloutScalePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work);
BtlEventHandler *HAND_WAZA_TripleKickGetHandlers(int *handlerCount);
void HAND_WAZA_TripleKickRaisePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_TripleKickCheckEachHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_GyroBallGetHandlers(int *handlerCount);
void HAND_WAZA_GyroBallCalcPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_RevengeGetHandlers(int *handlerCount);
void HAND_WAZA_RevengeDoublePowerOnHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_FlailGetHandlers(int *handlerCount);
void HAND_WAZA_FlailCalcPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_FacadeGetHandlers(int *handlerCount);
void HAND_WAZA_FacadeDoublePowerOnStatus(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_PaybackGetHandlers(int *handlerCount);
void HAND_WAZA_PaybackDoublePowerIfTargetMoved(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_EruptionGetHandlers(int *handlerCount);
void HAND_WAZA_EruptionOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddWringOut(int *handlerCount);
void HAND_WAZA_WringOutOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddBrine(int *handlerCount);
void HAND_WAZA_BrineOnPowerRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddReturn(int *handlerCount);
void HAND_WAZA_ReturnOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddFrustration(int *handlerCount);
void HAND_WAZA_FrustrationOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddWakeUpSlap(int *handlerCount);
void HAND_WAZA_WakeUpSlapOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_WakeUpSlapOnDamageEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddSmellingSalt(int *handlerCount);
void HAND_WAZA_SmellingSaltOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_SmellingSaltOnDamageEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddPresent(int *handlerCount);
void HAND_WAZA_PresentOnVariantDecide(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_PresentOnHealEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_PresentOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddTrumpCard(int *handlerCount);
void HAND_WAZA_TrumpCardOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddPunishment(int *handlerCount);
void HAND_WAZA_PunishmentOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddFuryCutter(int *handlerCount);
void HAND_WAZA_FuryCutterOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddAssurance(int *handlerCount);
void HAND_WAZA_AssuranceOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddLowKick(int *handlerCount);
void HAND_WAZA_LowKickOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddWeatherBall(int *handlerCount);
void HAND_WAZA_WeatherBallOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_WeatherBallOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddGust(int *handlerCount);
void HAND_WAZA_GustOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_GustOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddSkyUppercut(int *handlerCount);
void HAND_WAZA_SkyUppercutOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddThunder(int *handlerCount);
void HAND_WAZA_ThunderOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_ThunderOnHitCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_ThunderOnAccuracyCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddBlizzard(int *handlerCount);
void HAND_WAZA_BlizzardOnHitCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddEarthquake(int *handlerCount);
void HAND_WAZA_EarthquakeOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_EarthquakeOnDamageRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddJudgment(int *handlerCount);
void HAND_WAZA_JudgmentOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddTechnoBlast(int *handlerCount);
void HAND_WAZA_TechnoBlastOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddHiddenPower(int *handlerCount);
void HAND_WAZA_HiddenPowerOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_HiddenPowerOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddNaturalGift(int *handlerCount);
void HAND_WAZA_NaturalGiftOnExecuteCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_NaturalGiftOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_NaturalGiftOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_NaturalGiftOnWazaFinish(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddKnockOff(int *handlerCount);
void HAND_WAZA_KnockOffOnDamageEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddMagicCoat(int *handlerCount);
void HAND_WAZA_MagicCoatOnExecuteCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_MagicCoatOnWazaExecute(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_MagicCoatOnWazaCounter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_MagicCoatOnWazaNotice(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_MagicCoatOnTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddSnatch(int *handlerCount);
void HAND_WAZA_SnatchOnWazaExecute(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_SnatchOnSnatchCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_SnatchOnSnatched(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_SnatchOnTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddThief(int *handlerCount);
void HAND_WAZA_ThiefOnWazaPrepare(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_ThiefOnDamageEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddTrick(int *handlerCount);
void HAND_WAZA_TrickOnWazaExecute(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddMagnitude(int *handlerCount);
void HAND_WAZA_MagnitudeOnWazaStart(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_MagnitudeSetDefaultLevel(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *magnitudeLevel);
int *HAND_WAZA_GetSurfHandlers(int *handlerCount);
void HAND_WAZA_SurfHitDiving(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_SurfDoubleDamageVsDiving(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_GetStompHandlers(int *handlerCount);
void HAND_WAZA_StompDoubleDamageVsMinimized(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_GetFalseSwipeHandlers(int *handlerCount);
void HAND_WAZA_FalseSwipeLeaveOneHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_GetEndureHandlers(int *handlerCount);
void HAND_WAZA_EndureBraceUp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, struct EndureWork *work);
void HAND_WAZA_EndureSurviveAtOneHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, struct EndureWork *work);
void HAND_WAZA_EndureRemoveAtTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_GetProtectHandlers(int *handlerCount);
void HAND_WAZA_ProtectResetStreakAfterOtherMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_ProtectCheckSuccess(BTL_EVENT_SIGNATURE, int *work);
void HAND_WAZA_ProtectResetStreakOnFail(BTL_EVENT_SIGNATURE, int *work);
void HAND_WAZA_ProtectActivate(BTL_EVENT_SIGNATURE, int *work);
void HAND_WAZA_ProtectIncrementStreak(struct BtlServerFlow *flow, int pokeId, int silent);
int *HAND_WAZA_GetBideHandlers(int *handlerCount);
void HAND_WAZA_BideAdvanceTurn(BTL_EVENT_SIGNATURE, struct BideWork *work);
void HAND_WAZA_BideSelectMessage(BTL_EVENT_SIGNATURE, struct BideWork *work);
void HAND_WAZA_BideCheckStoredDamage(BTL_EVENT_SIGNATURE, struct BideWork *work);
void HAND_WAZA_BideDecideTarget(BTL_EVENT_SIGNATURE, struct BideWork *work);
void HAND_WAZA_BideStoreDamage(BTL_EVENT_SIGNATURE, struct BideWork *work);
void HAND_WAZA_BideDoubleStoredDamage(BTL_EVENT_SIGNATURE, struct BideWork *work);
void HAND_WAZA_BideEndOnFail(BTL_EVENT_SIGNATURE, struct BideWork *work);
int HAND_WAZA_BideFindTarget(BTL_EVENT_SIGNATURE, struct BideWork *work);
void HAND_WAZA_BideCureStoringState(struct BtlServerFlow *flow, int pokeId, struct BideWork *work);
int *HAND_WAZA_GetRecycleHandlers(int *handlerCount);
void HAND_WAZA_RecycleRestoreItem(BTL_EVENT_SIGNATURE);
int *HAND_WAZA_GetPsychoShiftHandlers(int *handlerCount);
void HAND_WAZA_PsychoShiftTransferStatus(BTL_EVENT_SIGNATURE);
int *HAND_WAZA_GetPainSplitHandlers(int *handlerCount);
void HAND_WAZA_PainSplitAverageHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
u32 *HAND_WAZA_GetBellyDrumHandlers(u32 *handlerCount);
void HAND_WAZA_BellyDrumMaximizeAttack(int unused, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetFeintHandlers(int *handlerCount);
void HAND_WAZA_FeintSetBypassFlag(int unused, int unused2, int pokeId);
void HAND_WAZA_FeintBreakProtect(int unused, struct BtlServerFlow *flow, int pokeId, struct FeintWork *work);
void HAND_WAZA_FeintBreakSideGuard(int unused, struct BtlServerFlow *flow, int pokeId, struct FeintWork *work);
int *HAND_WAZA_GetAcupressureHandlers(int *handlerCount);
void HAND_WAZA_AcupressureRaiseRandomStat(int unused, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetRestHandlers(int *handlerCount);
void HAND_WAZA_RestCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_RestSleepAndHeal(int unused, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetAttractHandlers(int *handlerCount);
void HAND_WAZA_AttractCheckGender(int unused, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetConversion2Handlers(int *handlerCount);
void HAND_WAZA_Conversion2ChangeType(int unused, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetEncoreHandlers(int *handlerCount);
void HAND_WAZA_EncoreAddSick(int unused, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetTauntHandlers(int *handlerCount);
void HAND_WAZA_TauntOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddTorment(int *handlerCount);
void HAND_WAZA_TormentOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddDisable(int *handlerCount);
void HAND_WAZA_DisableOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddImprison(int *handlerCount);
void HAND_WAZA_ImprisonOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddAromatherapy(int *handlerCount);
void HAND_WAZA_AromatherapyOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddHealBell(int *handlerCount);
void HAND_WAZA_HealBellOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_CureParty(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work, u16 messageId);
u8 HAND_WAZA_CollectStatusedPokeIds(struct BtlParty *party, u8 startIndex, u8 limit, u8 *outIds);
BtlEventHandler *HAND_WAZA_AddMemento(int *handlerCount);
void HAND_WAZA_MementoOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddSpite(int *handlerCount);
void HAND_WAZA_SpiteOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddPsychUp(int *handlerCount);
void HAND_WAZA_PsychUpOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddHeartSwap(int *handlerCount);
void HAND_WAZA_HeartSwapOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddPowerSwap(int *handlerCount);
void HAND_WAZA_PowerSwapOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddGuardSwap(int *handlerCount);
void HAND_WAZA_GuardSwapOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddPowerTrick(int *handlerCount);
void HAND_WAZA_PowerTrickOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddPowerSplit(int *handlerCount);
void HAND_WAZA_PowerSplitOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddGuardSplit(int *handlerCount);
void HAND_WAZA_GuardSplitOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddLockOn(int *handlerCount);
void HAND_WAZA_LockOnOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddReflect(int *handlerCount);
void HAND_WAZA_ReflectOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddLightScreen(int *handlerCount);
void HAND_WAZA_LightScreenOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddSafeguard(int *handlerCount);
void HAND_WAZA_SafeguardOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddMist(int *handlerCount);
void HAND_WAZA_MistOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddTailwind(int *handlerCount);
void HAND_WAZA_TailwindOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddLuckyChant(int *handlerCount);
void HAND_WAZA_LuckyChantOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddSpikes(int *handlerCount);
void HAND_WAZA_SpikesOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddToxicSpikes(int *handlerCount);
void HAND_WAZA_ToxicSpikesOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddStealthRock(int *handlerCount);
void HAND_WAZA_StealthRockOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddWideGuard(int *handlerCount);
void HAND_WAZA_WideGuardOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddTransform(int *handlerCount);
void HAND_WAZA_TransformOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddLunarDance(int *handlerCount);
void HAND_WAZA_LunarDanceSetPosEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetHealingWishHandlers(int *handlerCount);
void HAND_WAZA_HealingWishSetPosEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetWishHandlers(int *handlerCount);
void HAND_WAZA_WishSetPosEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetFutureSightHandlers(int *handlerCount);
void HAND_WAZA_FutureSightArmDelayedAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_FutureSightShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_ArmDelayedAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int targetPosition);
int *HAND_WAZA_GetDoomDesireHandlers(int *handlerCount);
void HAND_WAZA_DoomDesireArmDelayedAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_DoomDesireShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetGastroAcidHandlers(int *handlerCount);
void HAND_WAZA_GastroAcidSuppressAbility(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetRolePlayHandlers(int *handlerCount);
void HAND_WAZA_RolePlayCopyAbility(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetUTurnHandlers(int *handlerCount);
void HAND_WAZA_UTurnSwitchOut(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetRapidSpinHandlers(int *handlerCount);
void HAND_WAZA_RapidSpinClearBindingAndHazards(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetBatonPassHandlers(int *handlerCount);
void HAND_WAZA_BatonPassSwitchOut(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetTeleportHandlers(int *handlerCount);
void HAND_WAZA_TeleportCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_TeleportEscape(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_TeleportShowFailMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetFlingHandlers(int *handlerCount);
void HAND_WAZA_FlingCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_FlingSetBasePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_FlingShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_FlingUseItemOnTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_FlingRemoveItemAfterMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_GetMagnetRiseHandlers(int *handlerCount);
void HAND_WAZA_MagnetRiseCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_MagnetRiseAddFloating(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetHelpingHandHandlers(int *handlerCount);
void HAND_WAZA_HelpingHandSetGenericFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_HelpingHandClearProtectBypass(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_HelpingHandAssistAlly(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_HelpingHandBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_HelpingHandRemoveAtTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetBeatUpHandlers(int *handlerCount);
void HAND_WAZA_BeatUpSetHitCount(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_BeatUpSetBasePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
struct BtlPokeParam *HAND_WAZA_FindBeatUpMember(struct BtlServerFlow *flow, u32 pokeId, u8 index);
int *HAND_WAZA_GetFakeOutHandlers(int *handlerCount);
void HAND_WAZA_FakeOutCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetWeatherHealHandlers(int *handlerCount);
void HAND_WAZA_WeatherHealSetRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetFlyHandlers(int *handlerCount);
void HAND_WAZA_FlyBeginFlight(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_FlyChargeEndNoOp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetShadowForceHandlers(int *handlerCount);
void HAND_WAZA_ShadowForceBeginVanish(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_ShadowForceChargeEndNoOp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_ShadowForceBreakProtect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetBounceHandlers(int *handlerCount);
void HAND_WAZA_BounceOnChargeTurn(int factor, void *flow, u32 pokeId);
void HAND_WAZA_BounceNoOp(void);
int *HAND_WAZA_AddDive(int *handlerCount);
void HAND_WAZA_DiveOnChargeTurn(int factor, void *flow, u32 pokeId);
void HAND_WAZA_DiveNoOp(void);
int *HAND_WAZA_AddDig(int *handlerCount);
void HAND_WAZA_DigOnChargeTurn(int factor, void *flow, u32 pokeId);
void HAND_WAZA_DigNoOp(void);
int *HAND_WAZA_AddSolarBeam(int *handlerCount);
void HAND_WAZA_SolarBeamSkipChargeInSun(int factor, void *flow, int pokeId);
void HAND_WAZA_SolarBeamOnChargeTurn(int factor, void *flow, int pokeId);
void HAND_WAZA_SolarBeamHalvePowerInBadWeather(int factor, void *flow, int pokeId);
int *HAND_WAZA_AddRazorWind(int *handlerCount);
void HAND_WAZA_RazorWindOnChargeTurn(int factor, void *flow, u32 pokeId);
int *HAND_WAZA_AddSkyAttack(int *handlerCount);
void HAND_WAZA_SkyAttackOnChargeTurn(int factor, void *flow, u32 pokeId);
int *HAND_WAZA_AddSkullBash(int *handlerCount);
void HAND_WAZA_SkullBashOnChargeTurn(int factor, void *flow, u32 pokeId);
int *HAND_WAZA_AddPluck(int *handlerCount);
void HAND_WAZA_PluckEatTargetBerry(int factor, void *flow, u32 pokeId);
int *HAND_WAZA_AddStruggle(int *handlerCount);
void HAND_WAZA_StruggleSetSkipFlag(int factor, int flow, int pokeId);
void HAND_WAZA_StruggleShowNoMovesMessage(int factor, void *flow, int pokeId);
void HAND_WAZA_StruggleSetFlag4B(int factor, int flow, int pokeId);
int *HAND_WAZA_AddDestinyBond(int *handlerCount);
void HAND_WAZA_DestinyBondOnUse(int factor, void *flow, u32 pokeId, u32 *work);
void HAND_WAZA_RemoveOnUserAction(struct BtlEventNode *factor, int flow, int pokeId);
void HAND_WAZA_DestinyBondOnFaint(int factor, void *flow, u32 pokeId);
int *HAND_WAZA_AddGrudge(int *handlerCount);
void HAND_WAZA_GrudgeOnUse(int factor, void *flow, u32 pokeId, u32 *work);
void HAND_WAZA_GrudgeOnFaint(void *factor, void *flow, int pokeId);
int *HAND_WAZA_AddMinimize(int *handlerCount);
void HAND_WAZA_MinimizeSetState(int factor, void *flow, int pokeId);
int *HAND_WAZA_AddDefenseCurl(int *handlerCount);
void HAND_WAZA_DefenseCurlSetState(int factor, void *flow, int pokeId);
int *HAND_WAZA_AddRoost(int *handlerCount);
void HAND_WAZA_RoostGroundFlyingType(int factor, void *flow, int pokeId);
int *HAND_WAZA_AddFocusPunch(int *handlerCount);
void HAND_WAZA_FocusPunchTense(int factor, void *flow, int pokeId);
int *HAND_WAZA_AddMetronome(int *handlerCount);
void HAND_WAZA_MetronomePickMove(int factor, int flow, int pokeId);
void HAND_WAZA_MetronomeSetFailMessage(int factor, int flow, int pokeId);
int *HAND_WAZA_AddNaturePower(int *handlerCount);
void HAND_WAZA_NaturePowerPickMove(int factor, int flow, int pokeId);
void HAND_WAZA_NaturePowerSetFailMessage(int factor, int flow, int pokeId);
int *HAND_WAZA_AddAssist(int *handlerCount);
void HAND_WAZA_AssistPickMove(void *factor, void *flow, int pokeId);
int *HAND_WAZA_AddSleepTalk(int *handlerCount);
void HAND_WAZA_SleepTalkPickMove(int factor, int flow, int pokeId, u32 *candidates);
int *HAND_WAZA_AddMirrorMove(int *handlerCount);
void HAND_WAZA_MirrorMovePickMove(int factor, int flow, int pokeId, u8 *targetPokeId);
int *HAND_WAZA_AddMeFirst(int *handlerCount);
void HAND_WAZA_MeFirstPickMove(void *factor, void *flow, int pokeId, u8 *targetPokeId);
void HAND_WAZA_MeFirstBoostPower(int factor, int flow, int pokeId);
int *HAND_WAZA_AddCopycat(int *handlerCount);
void HAND_WAZA_CopycatPickMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_AddAllStatBoostChance(int *handlerCount);
void HAND_WAZA_AllStatBoostSetChance(int factor, int flow, int pokeId);
int *HAND_WAZA_AddVenoshock(int *handlerCount);
void HAND_WAZA_VenoshockDoublePowerOnPoison(int factor, int flow, int pokeId);
int *HAND_WAZA_AddHex(int *handlerCount);
void HAND_WAZA_HexDoublePowerOnStatus(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddAcrobatics(int *handlerCount);
void HAND_WAZA_AcrobaticsDoublePowerWithoutItem(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddStoredPower(int *handlerCount);
void HAND_WAZA_StoredPowerAddPowerPerStage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddHeavySlam(int *handlerCount);
void HAND_WAZA_HeavySlamSetPowerByWeight(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddElectroBall(int *handlerCount);
void HAND_WAZA_ElectroBallSetPowerBySpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddEchoedVoice(int *handlerCount);
void HAND_WAZA_EchoedVoiceSetPowerByStreak(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddRetaliate(int *handlerCount);
void HAND_WAZA_RetaliateDoublePowerAfterAllyFaint(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddFoulPlay(int *handlerCount);
void HAND_WAZA_FoulPlayUseTargetAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddSoak(int *handlerCount);
void HAND_WAZA_SoakSetWaterType(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddSimpleBeam(int *handlerCount);
void HAND_WAZA_SimpleBeamSetAbility(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddEntrainment(int *handlerCount);
void HAND_WAZA_EntrainmentCopyAbility(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddClearSmog(int *handlerCount);
void HAND_WAZA_ClearSmogResetTargetRanks(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddIncinerate(int *handlerCount);
void HAND_WAZA_IncinerateBurnBerry(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddCircleThrow(int *handlerCount);
void HAND_WAZA_CircleThrowForceSwitch(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddSmackDown(int *handlerCount);
void HAND_WAZA_SmackDownGroundTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddShellSmash(int *handlerCount);
void HAND_WAZA_ShellSmashChangeStats(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddReflectType(int *handlerCount);
void HAND_WAZA_ReflectTypeCopyTargetType(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddAutotomize(int *handlerCount);
void HAND_WAZA_AutotomizeLoseWeight(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddPsyshock(int *handlerCount);
void HAND_WAZA_PsyshockSwapDefenseStat(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddChipAway(int *handlerCount);
void HAND_WAZA_ChipAwayIgnoreDefenseStages(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_ChipAwayIgnoreEvasionStages(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddWonderRoom(int *handlerCount);
void HAND_WAZA_WonderRoomToggle(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddMagicRoom(int *handlerCount);
void HAND_WAZA_MagicRoomToggle(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddFlameBurst(int *handlerCount);
void HAND_WAZA_FlameBurstDamageAdjacent(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddSynchronoise(int *handlerCount);
void HAND_WAZA_SynchronoiseFailWithoutSharedType(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddBestow(int *handlerCount);
void HAND_WAZA_BestowGiveItem(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddFinalGambit(int *handlerCount);
void HAND_WAZA_FinalGambitSetFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddAfterYou(int *handlerCount);
void HAND_WAZA_AfterYouMoveTargetNext(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddQuash(int *handlerCount);
void HAND_WAZA_QuashMoveTargetLast(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_AddRound(int *handlerCount);
void HAND_WAZA_RoundRegisterUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_RoundDoublePower(BTL_EVENT_SIGNATURE);
int *HAND_WAZA_GetQuickGuardHandlers(int *handlerCount);
void HAND_WAZA_QuickGuardOnUncategorizedMoveNoTarget(BTL_EVENT_SIGNATURE, int *work);
int *HAND_WAZA_GetAllySwitchHandlers(int *handlerCount);
void HAND_WAZA_AllySwitchSwapPositions(BTL_EVENT_SIGNATURE);
int *HAND_WAZA_GetTelekinesisHandlers(int *handlerCount);
void HAND_WAZA_TelekinesisCheckTarget(BTL_EVENT_SIGNATURE);
void HAND_WAZA_TelekinesisSetStatusMessage(BTL_EVENT_SIGNATURE);
int *HAND_WAZA_GetSkyDropHandlers(int *handlerCount);
void HAND_WAZA_SkyDropBlockAllyTarget(BTL_EVENT_SIGNATURE);
void HAND_WAZA_SkyDropStartCharge(BTL_EVENT_SIGNATURE);
void HAND_WAZA_SkyDropReleaseTarget(BTL_EVENT_SIGNATURE);
void HAND_WAZA_SkyDropRedirectToHeldTarget(BTL_EVENT_SIGNATURE);
void HAND_WAZA_SkyDropFailIfTargetGone(BTL_EVENT_SIGNATURE);
void HAND_WAZA_SkyDropBlockFlyingTarget(BTL_EVENT_SIGNATURE);
int *HAND_WAZA_GetRelicSongHandlers(int *handlerCount);
void HAND_WAZA_RelicSongChangeForm(BTL_EVENT_SIGNATURE);
int *HAND_WAZA_GetForesightHandlers(int *handlerCount);
void HAND_WAZA_ForesightSetGhostType(BTL_EVENT_SIGNATURE);
int *HAND_WAZA_GetMiracleEyeHandlers(int *handlerCount);
void HAND_WAZA_MiracleEyeSetDarkType(BTL_EVENT_SIGNATURE);
int *HAND_WAZA_GetGrowthHandlers(int *handlerCount);
void HAND_WAZA_GrowthBoostInSun(BTL_EVENT_SIGNATURE);
int *HAND_WAZA_GetFreezeShockIceBurnHandlers(int *handlerCount);
void HAND_WAZA_FreezeShockIceBurnShowChargeMessage(BTL_EVENT_SIGNATURE);
int *HAND_WAZA_GetFusionHandlers(int *handlerCount);
void HAND_WAZA_FusionDoublePower(BTL_EVENT_SIGNATURE);
int HAND_WAZA_FindPledgeCombo(u32 firstMove, u32 secondMove);
int *HAND_WAZA_GetPledgeHandlers(int *handlerCount);
void HAND_WAZA_PledgeCheckCombo(BTL_EVENT_SIGNATURE, struct PledgeWork *work);
void HAND_WAZA_PledgeShowWaitMessage(BTL_EVENT_SIGNATURE, struct PledgeWork *work);
void HAND_WAZA_PledgeSkipWait(BTL_EVENT_SIGNATURE, struct PledgeWork *work);
void HAND_WAZA_PledgeSetCombinedPower(BTL_EVENT_SIGNATURE, struct PledgeWork *work);
void HAND_WAZA_PledgeSetCombinedMoveId(BTL_EVENT_SIGNATURE, struct PledgeWork *work);
void HAND_WAZA_PledgeApplyCombinedEffect(BTL_EVENT_SIGNATURE, const struct PledgeWork *work);
extern const WazaHandlerEntry gWazaHandlerRegistry[WAZA_HANDLER_REGISTRY_COUNT];
extern BtlEventHandler gHandWazaConversionHandlers[];
extern BtlEventHandler gHandWazaCamouflageHandlers[];
extern const BtlEventHandler gTrickRoomHandlers[];
extern const BtlEventHandler gGravityHandlers[];
extern const BtlEventHandler gWaterSportHandlers[];
extern const BtlEventHandler gMudSportHandlers[];
extern const BtlEventHandler gDefogHandlers[];
extern const BtlEventHandler gBrickBreakHandlers[];
extern const BtlEventHandler gJumpKickHandlers[];
extern const BtlEventHandler gMimicHandlers[];
extern const BtlEventHandler gSketchHandlers[];
extern const BtlEventHandler gFollowMeHandlers[];
extern const BtlEventHandler gRefreshHandlers[];
extern const BtlEventHandler gTrapHandlers[];
extern const BtlEventHandler gHazeHandlers[];
extern const BtlEventHandler gSplashHandlers[];
extern const BtlEventHandler gCurseHandlers[];
extern const BtlEventHandler gThunderWaveHandlers[];
extern const BtlEventHandler gWorrySeedHandlers[];
extern const BtlEventHandler gDreamEaterHandlers[];
extern const BtlEventHandler gCaptivateHandlers[];
extern const BtlEventHandler gTriAttackHandlers[];
extern u32 gTriAttackSickIds[];
extern BtlEventHandler gChatterHandlers[];
extern BtlEventHandler gSecretPowerHandlers[];
extern BtlEventHandler gBindSickHandlers[];
extern BtlEventHandler gWhirlpoolHandlers[];
extern BtlEventHandler gSuperFangHandlers[];
extern BtlEventHandler gDragonRageHandlers[];
extern BtlEventHandler gSonicBoomHandlers[];
extern BtlEventHandler gEndeavorHandlers[];
extern BtlEventHandler gLevelDamageHandlers[];
extern BtlEventHandler gPsywaveHandlers[];
extern BtlEventHandler gSpitUpHandlers[];
extern BtlEventHandler gSwallowHandlers[];
extern BtlEventHandler gStockpileHandlers[];
extern BtlEventHandler gCounterHandlers[];
extern BtlEventHandler gMirrorCoatHandlers[];
extern BtlEventHandler gMetalBurstHandlers[];
extern BtlEventHandler gLastResortHandlers[];
extern BtlEventHandler gSnoreHandlers[];
extern BtlEventHandler gNightmareHandlers[];
extern BtlEventHandler gSuckerPunchHandlers[];
extern BtlEventHandler gPursuitHandlers[]; /* Pursuit handler table */
extern BtlEventHandler gSelfDestructHandlers[]; /* Self-Destruct and Explosion handler table */
extern BtlEventHandler gFocusEnergyHandlers[]; /* Focus Energy handler table (first row; used by unit_021E1E38) */
extern BtlEventHandler gChargeHandlers[]; /* Charge handler table */
extern BtlEventHandler gPerishSongHandlers[]; /* Perish Song handler table */
extern BtlEventHandler gLeechSeedHandlers[]; /* Leech Seed handler table */
extern BtlEventHandler gPayDayHandlers[]; /* Pay Day handler table */
extern BtlEventHandler gRageHandlers[]; /* Rage handler table */
extern BtlEventHandler gAquaRingHandlers[]; /* Aqua Ring handler table */
extern BtlEventHandler gThrashHandlers[]; /* Thrash, Petal Dance and Outrage handler table */
/*
 * lever: Word return from BTL_SICKCONT_MakeKind2 reserves the unused aggregate slot;
 * u8 pokeId in the Uproar start handler schedules its stack reload after the zero store at 021E23CE.
 */
extern BtlEventHandler gUproarHandlers[]; /* Uproar handler table */
extern BtlEventHandler gTripleKickHandlers[]; /* Triple Kick handler table */
extern BtlEventHandler gRolloutHandlers[]; /* Rollout and Ice Ball handler table */
extern BtlEventHandler gRevengeHandlers[]; /* Revenge and Avalanche handler table */
extern BtlEventHandler gGyroBallHandlers[]; /* Gyro Ball handler table */
extern BtlEventHandler gFlailHandlers[]; /* Flail and Reversal handler table */
extern HandFlailRow gFlailPowerTable[];    /* Flail and Reversal power table, five rows */
extern BtlEventHandler gFacadeHandlers[]; /* Facade handler table */
extern BtlEventHandler gPaybackHandlers[]; /* Payback handler table */
extern BtlEventHandler gEruptionHandlers[]; /* Eruption and Water Spout handler table */
extern BtlEventHandler gWringOutHandlers[];
extern BtlEventHandler gBrineHandlers[];
extern BtlEventHandler gReturnHandlers[];
extern BtlEventHandler gFrustrationHandlers[];
extern BtlEventHandler gWakeUpSlapHandlers[];
extern BtlEventHandler gSmellingSaltHandlers[];
extern BtlEventHandler gPresentHandlers[];
extern u16 gTrumpCardPowerByPp[]; /* Trump Card power by remaining PP of the move (0 to 4) */
extern BtlEventHandler gPunishmentHandlers[];
extern u32 gPunishmentStatIds[]; /* the seven stat ids whose raised stages count for Punishment */
extern BtlEventHandler gFuryCutterHandlers[];
extern BtlEventHandler gAssuranceHandlers[];
extern BtlEventHandler gLowKickHandlers[];
extern BtlEventHandler gTrumpCardHandlers[];
extern BtlEventHandler gWeatherBallHandlers[];
extern BtlEventHandler gSkyUppercutHandlers[];
extern BtlEventHandler gGustHandlers[];
extern BtlEventHandler gThunderHandlers[];
extern BtlEventHandler gBlizzardHandlers[];
extern BtlEventHandler gJudgmentHandlers[];
extern BtlEventHandler gEarthquakeHandlers[];
extern BtlEventHandler gTechnoBlastHandlers[];
extern BtlEventHandler gHiddenPowerHandlers[];
extern BtlEventHandler gNaturalGiftHandlers[];
extern BtlEventHandler gKnockOffHandlers[];
extern BtlEventHandler gMagicCoatHandlers[];
extern BtlEventHandler gSnatchHandlers[];
extern BtlEventHandler gTrickHandlers[];
extern BtlEventHandler gThiefHandlers[];
extern BtlEventHandler gMagnitudeHandlers[];
extern MagnitudeRow gMagnitudeRows[]; /* rolls below rollLimit give the row's Magnitude, the rows run from 4 to 10 */
extern int gStompHandlers[];
extern int gFalseSwipeHandlers[];
extern int gSurfHandlers[];
extern int gEndureHandlers[];
extern const u16 gProtectMoveIds[];
extern int gProtectHandlers[];
extern const u8 gProtectFailRange[];
extern int gBideHandlers[];
extern int gPsychoShiftHandlers[];
extern int gPainSplitHandlers[];
extern int gRecycleHandlers[];
extern u32 gBellyDrumHandlers[];
extern int gFeintHandlers[];
extern int gAcupressureHandlers[];
extern const u32 gAcupressureStats[];
extern int gRestHandlers[];
extern int gAttractHandlers[];
extern int gConversion2Handlers[];
extern int gEncoreHandlers[];
extern int gTauntHandlers[];
extern BtlEventHandler gTormentHandlers[];
extern BtlEventHandler gDisableHandlers[];
extern BtlEventHandler gImprisonHandlers[];
extern BtlEventHandler gAromatherapyHandlers[];
extern BtlEventHandler gHealBellHandlers[];
extern BtlEventHandler gMementoHandlers[];
extern BtlEventHandler gSpiteHandlers[];
extern BtlEventHandler gPsychUpHandlers[];
extern BtlEventHandler gHeartSwapHandlers[];
extern BtlEventHandler gPowerSwapHandlers[];
extern BtlEventHandler gGuardSwapHandlers[];
extern BtlEventHandler gPowerTrickHandlers[];
extern BtlEventHandler gPowerSplitHandlers[];
extern BtlEventHandler gGuardSplitHandlers[];
extern BtlEventHandler gLockOnHandlers[];
extern BtlEventHandler gReflectHandlers[];
extern BtlEventHandler gLightScreenHandlers[];
extern BtlEventHandler gSafeguardHandlers[];
extern BtlEventHandler gMistHandlers[];
extern BtlEventHandler gTailwindHandlers[];
extern BtlEventHandler gLuckyChantHandlers[];
extern BtlEventHandler gSpikesHandlers[];
extern BtlEventHandler gToxicSpikesHandlers[];
extern BtlEventHandler gStealthRockHandlers[];
extern BtlEventHandler gTransformHandlers[];
extern BtlEventHandler gWideGuardHandlers[];
extern BtlEventHandler gLunarDanceHandlers[];
extern int gHealingWishHandlers[];
extern int gWishHandlers[];
extern int gFutureSightHandlers[];
extern int gDoomDesireHandlers[];
extern int gGastroAcidHandlers[];
extern int gRolePlayHandlers[];
extern int gUTurnHandlers[];
extern int gRapidSpinHandlers[];
extern int gBatonPassHandlers[];
extern int gTeleportHandlers[];
extern int gFlingHandlers[];
extern int gMagnetRiseHandlers[];
extern int gHelpingHandHandlers[];
extern int gBeatUpHandlers[];
extern int gFakeOutHandlers[];
extern int gWeatherHealHandlers[];
extern int gFlyHandlers[];
extern int gBounceHandlers[];
extern int gShadowForceHandlers[];
extern int gDiveHandlers[];
extern int gDigHandlers[];
extern int gSolarBeamHandlers[];
extern int gSkyAttackHandlers[];
extern int gSkullBashHandlers[];
extern int gRazorWindHandlers[];
extern int gPluckHandlers[];
extern int gStruggleHandlers[];
extern int gDestinyBondHandlers[];
extern int gGrudgeHandlers[];
extern int gMinimizeHandlers[];
extern int gDefenseCurlHandlers[];
extern int gRoostHandlers[];
extern int gFocusPunchHandlers[];
extern int gMetronomeWazaHandlers[];
extern int gNaturePowerHandlers[];
extern int gAssistHandlers[];
extern int gSleepTalkHandlers[];
extern int gMirrorMoveHandlers[];
extern int gMeFirstHandlers[];
extern int gCopycatHandlers[];
extern int gAllStatBoostChanceHandlers[];
extern int gVenoshockHandlers[];
extern int gHexHandlers[];
extern int gAcrobaticsHandlers[];
extern const u8 gStoredPowerStatIds[7];
extern int gHeavySlamHandlers[];
extern int gStoredPowerHandlers[];
extern int gElectroBallHandlers[];
extern int gEchoedVoiceHandlers[];
extern int gRetaliateHandlers[];
extern int gFoulPlayHandlers[];
extern int gSimpleBeamHandlers[];
extern int gSoakHandlers[];
extern int gEntrainmentHandlers[];
extern int gClearSmogHandlers[];
extern int gIncinerateHandlers[];
extern int gCircleThrowHandlers[];
extern int gSmackDownHandlers[];
extern int gShellSmashHandlers[];
extern int gReflectTypeHandlers[];
extern int gAutotomizeHandlers[];
extern int gPsyshockHandlers[];
extern int gChipAwayHandlers[];
extern int gMagicRoomHandlers[];
extern int gFlameBurstHandlers[];
extern int gSynchronoiseHandlers[];
extern int gWonderRoomHandlers[];
extern int gBestowHandlers[];
extern int gFinalGambitHandlers[];
extern int gAfterYouHandlers[];
extern int gQuashHandlers[];
extern int gRoundHandlers[];
extern int gQuickGuardHandlers[]; /* Quick Guard handler table */
extern int gAllySwitchHandlers[]; /* Ally Switch handler table */
extern int gTelekinesisHandlers[]; /* Telekinesis handler table */
extern int gSkyDropHandlers[]; /* Sky Drop handler table */
extern int gRelicSongHandlers[]; /* Relic Song handler table */
extern int gForesightOdorSleuthHandlers[]; /* Foresight and Odor Sleuth handler table */
extern int gMiracleEyeHandlers[]; /* Miracle Eye handler table */
extern int gGrowthHandlers[]; /* Growth handler table */
extern int gFreezeShockIceBurnHandlers[]; /* Freeze Shock and Ice Burn handler table */
extern int gFusionFlareFusionBoltHandlers[]; /* Fusion Flare and Fusion Bolt handler table */
extern struct PledgeCombo gPledgeComboTable[3]; /* Pledge combination table */
extern int gPledgeHandlers[];                 /* Pledge handler table */



/*
 * Gem, move power (event 0x38): the attacker's move of the gem's type gets the
 * 1.5 boost when the gem was just used (work[0]) or the flow test says so.
 */
void HAND_ITEM_GemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work, u8 gemType)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && gemType == BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE)) {
        if (*work == BTL_GEM_STATE_CONSUMED || BTL_SERVER_FLOW_IsActionCounterSet(flow))
            BTL_EVENT_MultiplyVar(BTL_EVAR_MOVE_POWER_RATIO, BTL_GEM_RATIO);
    }
}




/* Gem, end of the move damage (event 0x88): the gem state moves from consumed to done. */
void HAND_ITEM_GemMoveDamageEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && *work == BTL_GEM_STATE_CONSUMED)
        *work = BTL_GEM_STATE_DONE;
}




/*
 * Add the handler of a move to the Pokemon when the move is chosen. Looks the
 * move up in the registry; returns 1 when a handler was added.
 */
int HAND_WAZA_AddMoveHandler(struct BtlPokeParam *bpp, u16 moveId, u32 subPriority)
{
    u32 index;
    u8 ownerId;
    u8 alreadyAdded;
    int handlerCount;
    BtlEventHandler *handlers;

    for (index = 0; index < WAZA_HANDLER_REGISTRY_COUNT; index++) {
        if (moveId == gWazaHandlerRegistry[index].moveId) {
            ownerId = BTL_POKEPARAM_GetPokeId(bpp);
            alreadyAdded = 0;
            if (HAND_WAZA_CanAddMoveHandler(ownerId, moveId, &alreadyAdded) != 0) {
                handlers = gWazaHandlerRegistry[index].getHandlers(&handlerCount);
                if (handlers != 0) {
                    BTL_EVENT_AddFactor(BTL_EVENT_TYPE_WAZA, moveId, 0, subPriority, ownerId, (uptr)handlers, handlerCount);
                    return 1;
                }
            }
            return 0;
        }
    }
    return 0;
}




/*
 * Check whether a move handler may be added: returns 0 when the owner already
 * holds one for the move (and sets *alreadyAdded) or holds too many handlers.
 */
int HAND_WAZA_CanAddMoveHandler(int ownerId, int moveId, u8 *alreadyAdded)
{
    struct BtlEventFactor *factor;
    u32 scanned = 0;

    for (factor = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_WAZA, ownerId); factor != 0; factor = BTL_EVENT_FindNextFactor(factor)) {
        if (moveId == BTL_EVENT_GetFactorKey(factor)) {
            *alreadyAdded = 1;
            return 0;
        }
        if (++scanned > WAZA_HANDLER_FACTOR_LIMIT)
            return 0;
    }
    return 1;
}




/* Remove the handlers of a move from the Pokemon unless their keep slot is set. */
void HAND_WAZA_RemoveMoveHandlerUnlessKept(struct BtlPokeParam *bpp, int moveId)
{
    struct BtlEventFactor *factor;
    struct BtlEventFactor *next;

    factor = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_WAZA, BTL_POKEPARAM_GetPokeId(bpp));
    while (factor != 0) {
        next = BTL_EVENT_FindNextFactor(factor);
        if (moveId == BTL_EVENT_GetFactorKey(factor) && BTL_EVENT_GetFactorWork(factor, BTL_FACTOR_WORK_KEEP) == 0) {
            BTL_EVENT_RemoveFactor(factor);
        }
        factor = next;
    }
}




/* Remove every handler of a move from the Pokemon (the second callee takes the first one's result). */
void HAND_WAZA_RemoveMoveHandlerOfPoke(struct BtlPokeParam *bpp, int moveId)
{
    HAND_WAZA_RemoveMoveHandlerById(BTL_POKEPARAM_GetPokeId(bpp), moveId);
}




/* Tells the event list whether a move handler stays active when its owner is suspended (the keep slot is set). */
int HAND_WAZA_IsKeptOnSuspend(struct BtlEventFactor *factor, u32 *work)
{
    if (work[BTL_FACTOR_WORK_KEEP] != 0) return 1;
    return 0;
}




/* Remove every handler of a move from the owner with that id. */
void HAND_WAZA_RemoveMoveHandlerById(int ownerId, int moveId)
{
    struct BtlEventFactor *factor = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_WAZA, ownerId);

    while (factor != 0) {
        if (moveId == BTL_EVENT_GetFactorKey(factor)) {
            BTL_EVENT_RemoveFactor(factor);
            factor = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_WAZA, ownerId);
        } else {
            factor = BTL_EVENT_FindNextFactor(factor);
        }
    }
}




/* Remove every move handler of the Pokemon. */
void HAND_WAZA_RemoveAllMoveHandlers(struct BtlPokeParam *bpp)
{
    int ownerId = BTL_POKEPARAM_GetPokeId(bpp);
    struct BtlEventFactor *factor;

    while ((factor = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_WAZA, ownerId)) != 0)
        BTL_EVENT_RemoveFactor(factor);
}




/* Conversion handler table (move 160): move effect. */
BtlEventHandler *HAND_WAZA_GetConversionHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gHandWazaConversionHandlers;
}




/* Conversion: the user becomes the type of one of its other moves that it does not have yet, chosen at random. */
void HAND_WAZA_ConversionEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 candidateTypes[4];
    struct BtlPokeParam *bpp;
    u32 moveCount;
    u16 slot;
    u16 candidateCount;
    u16 moveType;
    HandExChangeType *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        moveCount = BTL_POKEPARAM_GetMoveCount(bpp);
        slot = 0;
        candidateCount = 0;
        for (; slot < moveCount; slot++) {
            moveType = BTL_POKEPARAM_GetMoveId(bpp, (u8)slot);
            if (moveType != BTL_EVENT_GetFactorKey(factor)) {
                moveType = WAZA_TOOL_GetType(moveType);
                if (BTL_POKEPARAM_HasType(bpp, moveType) == 0) {
                    candidateTypes[candidateCount++] = moveType;
                }
            }
        }
        if (candidateCount != 0) {
            cmd = (HandExChangeType *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_CHANGE_TYPE, pokeId);
            cmd->typePair = BTL_TYPEPAIR_MakeSingle(candidateTypes[(u16)BTL_CALC_Random(candidateCount)]);
            cmd->pokeId = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}




/*
 * Camouflage handler table (move 293); the handler is in the next unit.
 * extent: 021E05C2 alignment padding.
 */
BtlEventHandler *HAND_WAZA_GetCamouflageHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gHandWazaCamouflageHandlers;
}



/* Camouflage: the user takes the type that matches the battle ground. */
void HAND_WAZA_CamouflageChangeType(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    int type;
    u16 typePair;
    HandExChangeType *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        switch (BTL_SERVER_FLOW_GetFieldSituationType(flow)) {
        case 1: case 2: case 3: case 8: case 9: case 15:
            type = POKETYPE_GROUND;
            break;
        case 4: case 14:
        default:
            type = POKETYPE_NORMAL;
            break;
        case 10:
            type = POKETYPE_ROCK;
            break;
        case 0: case 5:
            type = POKETYPE_GRASS;
            break;
        case 6: case 11: case 12:
            type = POKETYPE_WATER;
            break;
        case 7: case 13:
            type = POKETYPE_ICE;
            break;
        }
        typePair = BTL_TYPEPAIR_MakeSingle(type);
        if (typePair != BTL_POKEPARAM_GetTypePair(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_CHANGE_TYPE, pokeId);
            cmd->typePair = typePair;
            cmd->pokeId = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}



const BtlEventHandler *HAND_WAZA_GetTrickRoomHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gTrickRoomHandlers;
}



/* Trick Room: start the field effect for five turns, or end it when it is already active. */
void HAND_WAZA_TrickRoomAddFieldEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlFieldEffectAddCmd *addCmd;
    BtlFieldEffectRemoveCmd *removeCmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_FIELD_IsStaticSlotInUse(BTL_FIELD_EFFECT_TRICK_ROOM) == 0) {
            addCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_FIELD_EFFECT, pokeId);
            addCmd->effectId = BTL_FIELD_EFFECT_TRICK_ROOM;
            addCmd->duration = BTL_SICKCONT_MakeKind2Index(5);
            BTL_SERVER_FLOW_InitMsgRecord(&addCmd->message, BTL_STR_TYPE_POKE_NAME, 0x359);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&addCmd->message), pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, addCmd);
        } else {
            removeCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_REMOVE_FIELD_EFFECT, pokeId);
            removeCmd->effectId = BTL_FIELD_EFFECT_TRICK_ROOM;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, removeCmd);
        }
    }
}



const BtlEventHandler *HAND_WAZA_GetGravityHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gGravityHandlers;
}



/*
 * Gravity: start the field effect for five turns unless it is active, then
 * ground the Pokemon in the air. The message is set field by field (no call
 * to the message setter).
 */
void HAND_WAZA_GravityAddFieldEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlFieldEffectAddCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_FIELD_IsStaticSlotInUse(BTL_FIELD_EFFECT_GRAVITY) == 0) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_FIELD_EFFECT, pokeId);
            cmd->effectId = BTL_FIELD_EFFECT_GRAVITY;
            cmd->duration = BTL_SICKCONT_MakeKind2Index(5);
            cmd->message.strTypeHalf = BTL_STR_TYPE_PLAIN;
            cmd->message.strId = 0x75;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_CMD_KIND_APPLY_GRAVITY, pokeId);
        }
    }
}



const BtlEventHandler *HAND_WAZA_GetWaterSportHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWaterSportHandlers;
}



/* Water Sport: start the field effect, which lasts while the user stays in. */
void HAND_WAZA_WaterSportAddFieldEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlFieldEffectAddCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_FIELD_EFFECT, pokeId);
        cmd->effectId = BTL_FIELD_EFFECT_WATER_SPORT;
        cmd->duration = BTL_SICKCONT_MakeKind3(pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, BTL_STR_TYPE_PLAIN, 0x72);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}



const BtlEventHandler *HAND_WAZA_GetMudSportHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMudSportHandlers;
}



/* Mud Sport: start the field effect, which lasts while the user stays in. */
void HAND_WAZA_MudSportAddFieldEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlFieldEffectAddCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_FIELD_EFFECT, pokeId);
        cmd->effectId = BTL_FIELD_EFFECT_MUD_SPORT;
        cmd->duration = BTL_SICKCONT_MakeKind3(pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, BTL_STR_TYPE_PLAIN, 0x73);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}



const BtlEventHandler *HAND_WAZA_GetDefogHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gDefogHandlers;
}



/*
 * Defog: lower the target's evasion by one stage (unless it is behind a
 * substitute), then remove the side effects. The removal command holds a set
 * of side effect ids; each bit is guarded by the size byte of the set, the
 * way an inlined set-bit helper would check it.
 */
void HAND_WAZA_DefogLowerEvasionRemoveSideEffects(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 targetId;
    BtlRankEffectCmd *rankCmd;
    BtlRemoveSideEffectsCmd *removeCmd;
    u32 i;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        if (BTL_POKEPARAM_HasSubstitute(BTL_SERVER_FLOW_GetPokeParam(flow, targetId)) == 0) {
            rankCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, pokeId);
            rankCmd->rankKind = BTL_RANK_EVASION;
            rankCmd->volume = -1;
            rankCmd->flagB = 1;
            rankCmd->pokeCount = 1;
            rankCmd->pokeId = targetId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, rankCmd);
        }
        removeCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_REMOVE_SIDE_EFFECTS, pokeId);
        removeCmd->sideId = BTL_MAIN_IsPokeIdInSecondPair(targetId);
        removeCmd->bytes[0] = 3;
        for (i = 1; i < 3; i++)
            removeCmd->bytes[i] = 0;
        if (removeCmd->bytes[0] > 1)
            removeCmd->bytes[1] |= 1 << BTL_SIDE_EFFECT_REFLECT;
        if (removeCmd->bytes[0] > 1)
            removeCmd->bytes[1] |= 1 << BTL_SIDE_EFFECT_LIGHT_SCREEN;
        if (removeCmd->bytes[0] > 1)
            removeCmd->bytes[1] |= 1 << BTL_SIDE_EFFECT_MIST;
        if (removeCmd->bytes[0] > 1)
            removeCmd->bytes[1] |= 1 << BTL_SIDE_EFFECT_SAFEGUARD;
        if (removeCmd->bytes[0] > 1)
            removeCmd->bytes[1] |= 1 << BTL_SIDE_EFFECT_SPIKES;
        if (removeCmd->bytes[0] > 1)
            removeCmd->bytes[1] |= 1 << BTL_SIDE_EFFECT_TOXIC_SPIKES;
        if (removeCmd->bytes[0] > 2)
            removeCmd->bytes[2] |= 1 << (BTL_SIDE_EFFECT_STEALTH_ROCK - 8);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, removeCmd);
    }
}



/* Brick Break: the table holds the skip check setup, its removal and the screen removal. */
const BtlEventHandler *HAND_WAZA_GetBrickBreakHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gBrickBreakHandlers;
}



/* Brick Break: make the move's own damage calculation skip the screens. */
void HAND_WAZA_BrickBreakSetSkipCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_SetFactorSkipCheck(factor, HAND_WAZA_BrickBreakSkipScreens);
}



/* Brick Break: stop skipping the screens. */
void HAND_WAZA_BrickBreakClearSkipCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_ClearFactorSkipCheck(factor);
}



/* Brick Break: when the defender's side has Reflect or Light Screen, remove both and queue the end record. */
void HAND_WAZA_BrickBreakRemoveScreens(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    int sideId;
    BtlRemoveSideEffectsCmd *removeCmd;
    BtlByteCmd *endCmd;
    unsigned i;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        sideId = (int)BTL_MAIN_IsPokeIdInSecondPair((u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID));
        if (HAND_SIDE_IsActive(sideId, BTL_SIDE_EFFECT_REFLECT) != 0 || HAND_SIDE_IsActive(sideId, BTL_SIDE_EFFECT_LIGHT_SCREEN) != 0) {
            removeCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_REMOVE_SIDE_EFFECTS, pokeId);
            removeCmd->sideId = sideId;
            removeCmd->bytes[0] = 3;
            for (i = 1; i < 3; i++) {
                removeCmd->bytes[i] = 0;
            }
            if (removeCmd->bytes[0] > 1) {
                removeCmd->bytes[1] |= 1 << BTL_SIDE_EFFECT_REFLECT;
            }
            if (removeCmd->bytes[0] > 1) {
                removeCmd->bytes[1] |= 1 << BTL_SIDE_EFFECT_LIGHT_SCREEN;
            }
            BTL_SERVER_FLOW_CommitCmdRecord(flow, removeCmd);
            endCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_SIDE_EFFECTS_REMOVED, pokeId);
            endCmd->value = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, endCmd);
        }
    }
}



/*
 * Skip check of Brick Break (set with BTL_EVENT_SetFactorSkipCheck): skip the
 * factors of Reflect and Light Screen, which are side effect factors with the
 * keys 0 and 1.
 */
int HAND_WAZA_BrickBreakSkipScreens(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId)
{
    if (factorType == BTL_EVENT_TYPE_SIDE_EFFECT && key <= BTL_SIDE_EFFECT_LIGHT_SCREEN)
        return 1;
    return 0;
}



/* Jump Kick and High Jump Kick. */
const BtlEventHandler *HAND_WAZA_GetJumpKickHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gJumpKickHandlers;
}



/* Jump Kick: when the kick fails, the user takes the crash damage. */
void HAND_WAZA_JumpKickCrashOnFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        HAND_WAZA_JumpKickDealCrashDamage(factor, flow, pokeId, work);
}



/* Jump Kick: the user loses half of its maximum HP. */
void HAND_WAZA_JumpKickDealCrashDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct HandExDamage *cmd;
    int damage;

    damage = BTL_CALC_DivideMaxHpMin1(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), 2);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_DAMAGE, pokeId);
    cmd->pokeId = pokeId;
    cmd->amount = damage;
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, BTL_STR_TYPE_POKE_NAME, 0x386);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}



const BtlEventHandler *HAND_WAZA_GetMimicHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMimicHandlers;
}



/*
 * Mimic: copy the last move of the target into the slot of Mimic. The move
 * stays an int: the slot search takes the full value without narrowing.
 */
void HAND_WAZA_MimicCopyTargetMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *user;
    struct BtlPokeParam *target;
    int move;
    int selectedMove;
    int slot;
    BtlReplaceMoveCmd *replaceCmd;
    struct HandExMessage *messageCmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_IsTransformed(user) != 0)
            return;
        target = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID));
        move = BTL_POKEPARAM_GetLastUsedMoveId(target);
        selectedMove = BTL_POKEPARAM_GetLastSelectedMoveId(target);
        if (selectedMove != move)
            move = selectedMove;
        if (move == 0 || BTL_ID_IsMimicExcludedMove(move) != 0 || BTL_POKEPARAM_FindMoveSlot(user, move) != BTL_POKEPARAM_MOVE_COUNT)
            return;
        slot = BTL_POKEPARAM_FindMoveSlot(user, BTL_EVENT_GetFactorKey(factor));
        if (slot == BTL_POKEPARAM_MOVE_COUNT)
            return;
        replaceCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_REPLACE_MOVE, pokeId);
        replaceCmd->pokeId = pokeId;
        replaceCmd->slot = slot;
        replaceCmd->moveId = move;
        replaceCmd->fullPp = 0;
        replaceCmd->permanent = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, replaceCmd);
        messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->message, BTL_STR_TYPE_POKE_NAME, 0x2b0);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageCmd->message), pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageCmd->message), move);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
    }
}



const BtlEventHandler *HAND_WAZA_GetSketchHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSketchHandlers;
}



/*
 * Sketch: learn the last move of the target for good. It is refused for no
 * move, Struggle, Sketch, Chatter, a move the user knows, and when the user
 * is transformed.
 */
void HAND_WAZA_SketchLearnTargetMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *user;
    struct BtlPokeParam *target;
    int move;
    int selectedMove;
    int slot;
    int moveOrMessageId;
    BtlReplaceMoveCmd *replaceCmd;
    struct HandExMessage *messageCmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID));
        move = BTL_POKEPARAM_GetLastUsedMoveId(target);
        selectedMove = BTL_POKEPARAM_GetLastSelectedMoveId(target);
        if (selectedMove != move)
            move = selectedMove;
        if (move == 0)
            return;
        if (move == BTL_MOVE_SKETCH)
            return;
        if (move == BTL_MOVE_STRUGGLE)
            return;
        /* The same local holds Chatter for the check and then the base of the message id below. */
        moveOrMessageId = BTL_MOVE_CHATTER;
        if (move == moveOrMessageId || BTL_POKEPARAM_HasMove(user, move) != 0 || BTL_POKEPARAM_IsTransformed(user) != 0)
            return;
        slot = BTL_POKEPARAM_FindMoveSlot(user, BTL_EVENT_GetFactorKey(factor));
        if (slot == BTL_POKEPARAM_MOVE_COUNT)
            return;
        replaceCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_REPLACE_MOVE, pokeId);
        replaceCmd->pokeId = pokeId;
        replaceCmd->slot = slot;
        replaceCmd->moveId = move;
        replaceCmd->fullPp = 0;
        replaceCmd->permanent = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, replaceCmd);
        messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_MESSAGE, pokeId);
        moveOrMessageId += 240;
        BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->message, BTL_STR_TYPE_POKE_NAME, moveOrMessageId);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageCmd->message), pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageCmd->message), move);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
    }
}



/* Follow Me and Rage Powder: four entries. */
const BtlEventHandler *HAND_WAZA_GetFollowMeHandlers(int *handlerCount)
{
    *handlerCount = 4;
    return gFollowMeHandlers;
}



/* Follow Me: outside double and triple battles the move fails with a fixed reason (when no reason is set yet). */
void HAND_WAZA_FollowMeFailOutsideMultiBattle(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    int failReasonKey = BTL_EVAR_FAIL_REASON;

    if (BTL_SERVER_FLOW_GetRule(flow) == BTL_RULE_SINGLE || BTL_SERVER_FLOW_GetRule(flow) == BTL_RULE_ROTATION) {
        if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(failReasonKey) == 0)
            BTL_EVENT_OverwriteVar(failReasonKey, BTL_FAIL_REASON_NEEDS_MULTI_BATTLE);
    }
}



/* Follow Me: show the message and mark the factor as activated. */
void HAND_WAZA_FollowMeShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct HandExMessage *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, BTL_STR_TYPE_POKE_NAME, 0x29e);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        work[HAND_WORK_ACTIVATED] = 1;
    }
}



/*
 * Follow Me: in a double or triple battle, make the user the defender of a
 * move from an enemy, unless the move is Sky Drop or the user is blocked.
 */
void HAND_WAZA_FollowMeRedirectTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *user;
    u8 attackerId;
    u16 moveId;

    if (BTL_SERVER_FLOW_GetRule(flow) == BTL_RULE_SINGLE)
        return;
    if (BTL_SERVER_FLOW_GetRule(flow) == BTL_RULE_ROTATION)
        return;
    attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (BTL_MAIN_IsPokeSamePair(pokeId, attackerId) != 0)
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID) == BTL_MOVE_SKY_DROP)
        return;
    if (BTL_POKEPARAM_HasSick(user, BTL_SICK_BLOCKS_REDIRECT) != 0)
        return;
    if (BTL_SERVER_FLOW_TestStateFlagBit0((unsigned char *)flow) != 0)
        return;
    moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
    if (BTL_SERVER_FLOW_CheckAllyMoveAutoHitById(flow, attackerId, pokeId, moveId) != 0)
        return;
    BTL_EVENT_OverwriteVar(BTL_EVAR_DEFENDER_ID, pokeId);
}



/* Follow Me: remove the factors of this move from the user. */
void HAND_WAZA_FollowMeRemoveFactor(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_WAZA_RemoveMoveHandlerById(pokeId, BTL_EVENT_GetFactorKey(factor));
}



const BtlEventHandler *HAND_WAZA_GetRefreshHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRefreshHandlers;
}



/* Refresh: cure the user of poison, paralysis or burn. */
void HAND_WAZA_RefreshCureMajorStatus(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExCureSick *cmd;
    int sickIndex;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        sickIndex = BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId));
        if (sickIndex == BTL_SICK_POISON || sickIndex == BTL_SICK_PARALYSIS || sickIndex == BTL_SICK_BURN) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_CURE_SICK, pokeId);
            cmd->sickKind = sickIndex;
            cmd->pokeIds[0] = pokeId;
            cmd->pokeCount = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}



/* Spider Web, Mean Look and Block. */
const BtlEventHandler *HAND_WAZA_GetTrapHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gTrapHandlers;
}



/* Trapping moves: the target can no longer escape while the user stays in. */
void HAND_WAZA_TrapAddNoEscape(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlAddSickMessageCmd *cmd;
    u8 targetId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, targetId), BTL_SICK_NO_ESCAPE) == 0) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_SICK, pokeId);
            cmd->pokeId = targetId;
            cmd->sickKind = BTL_SICK_NO_ESCAPE;
#ifdef __MWERKS__
            cmd->cont.raw = BTL_CALC_MakeSickContPoke((unsigned int)pokeId);
#else
            cmd->cont.raw = BTL_CALC_MakeSickContPoke((unsigned int)pokeId).raw;
#endif
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, BTL_STR_TYPE_POKE_NAME, 0x368);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), targetId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}



const BtlEventHandler *HAND_WAZA_GetHazeHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gHazeHandlers;
}



/* Haze: reset the stat stages of every Pokemon in the battle and show the message. */
void HAND_WAZA_HazeResetRanks(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlResetRanksCmd *resetCmd;
    struct HandExMessage *messageCmd;
    int allPokeBit;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        resetCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RESET_RANKS, pokeId);
        allPokeBit = 0x10;
        resetCmd->pokeCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)((allPokeBit << 7) | BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, pokeId)), resetCmd->pokeIds);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, resetCmd);
        messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->message, BTL_STR_TYPE_PLAIN, 0x65);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
    }
}



const BtlEventHandler *HAND_WAZA_GetSplashHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSplashHandlers;
}



/* Splash: only the message. */
void HAND_WAZA_SplashShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExMessage *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, BTL_STR_TYPE_PLAIN, 102);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}



const BtlEventHandler *HAND_WAZA_GetCurseHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gCurseHandlers;
}



/* Curse: the target kind of the move depends on the user (a Ghost aims at one Pokemon). */
void HAND_WAZA_CurseSetTargetKind(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_TARGET_KIND, BTL_CALC_GetCurseTargetKind(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)));
}



/*
 * Curse: a Ghost user pays half of its HP and curses the target; any other
 * user gets speed -1, attack +1 and defense +1. The by-value return of
 * BTL_SICKCONT_MakeKind1Empty reserves a four byte stack temporary, which is
 * the second slot of the original frame.
 */
void HAND_WAZA_CurseApply(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *user;
    int ghostCursed;
    u8 targetId;
    BtlAddSickMessageCmd *sickCmd;
    BtlHpDeltaCmd *hpCmd;
    BtlRankEffectCmd *rankCmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    ghostCursed = 0;
    if (BTL_POKEPARAM_HasType(user, POKETYPE_GHOST)) {
        if (BTL_POKEPARAM_GetValue(user, BPP_VALUE_HP) > 0) {
            targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
            if (targetId != BTL_POKEID_NONE) {
                sickCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_SICK, pokeId);
                sickCmd->pokeId = targetId;
                sickCmd->sickKind = BTL_SICK_CURSE;
                sickCmd->cont = BTL_SICKCONT_MakeKind1Empty();
                BTL_SERVER_FLOW_InitMsgRecord(&sickCmd->message, BTL_STR_TYPE_POKE_NAME, 1064);
                BTL_SERVER_FLOW_AppendMsgRecordArg((&sickCmd->message), pokeId);
                BTL_SERVER_FLOW_AppendMsgRecordArg((&sickCmd->message), targetId);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, sickCmd);
                hpCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_HP_DELTA, pokeId);
                hpCmd->pokeId = pokeId;
                hpCmd->delta = -BTL_CALC_DivideMaxHpMin1(user, 2);
                hpCmd->mode = 1;
                hpCmd->header |= BTL_CMD_FLAG_SELF_INFLICTED;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, hpCmd);
            }
        }
        ghostCursed = 1;
    } else {
        rankCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, pokeId);
        rankCmd->pokeCount = 1;
        rankCmd->pokeId = pokeId;
        rankCmd->rankKind = BTL_RANK_SPEED;
        rankCmd->volume = -1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rankCmd);
        rankCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, pokeId);
        rankCmd->pokeCount = 1;
        rankCmd->pokeId = pokeId;
        rankCmd->rankKind = BTL_RANK_ATTACK;
        rankCmd->volume = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rankCmd);
        rankCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, pokeId);
        rankCmd->pokeCount = 1;
        rankCmd->pokeId = pokeId;
        rankCmd->rankKind = BTL_RANK_DEFENSE;
        rankCmd->volume = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rankCmd);
    }
    BTL_SERVER_FLOW_SetCurTurnStateFlag(flow, ghostCursed);
}



const BtlEventHandler *HAND_WAZA_GetThunderWaveHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gThunderWaveHandlers;
}



/* Thunder Wave (guess from the move id): set the result flag of the accuracy check event. */
void HAND_WAZA_ThunderWaveSetAccuracyCheckFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_ACCURACY_CHECK_FLAG, 1);
}



const BtlEventHandler *HAND_WAZA_GetWorrySeedHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gWorrySeedHandlers;
}



/* Worry Seed: fails when the target already has Truant or Insomnia. */
void HAND_WAZA_WorrySeedFailOnTruantOrInsomnia(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *target;
    int abilityValueId;
    u8 targetId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        abilityValueId = BPP_VALUE_ABILITY_ID;
        if (BTL_POKEPARAM_GetValue(target, BPP_VALUE_ABILITY_ID) == BTL_ABILITY_TRUANT || BTL_POKEPARAM_GetValue(target, abilityValueId) == BTL_ABILITY_INSOMNIA)
            BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_FAIL_FLAG, 1);
    }
}



/* Worry Seed: the target's ability becomes Insomnia. */
void HAND_WAZA_WorrySeedChangeAbility(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExChangeAbility *cmd;
    int targetId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_CHANGE_ABILITY, pokeId);
        cmd->pokeId = targetId;
        cmd->abilityId = BTL_ABILITY_INSOMNIA;
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, BTL_STR_TYPE_POKE_NAME, 0x195);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), cmd->pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), cmd->abilityId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}



const BtlEventHandler *HAND_WAZA_GetDreamEaterHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gDreamEaterHandlers;
}



/* Dream Eater: fails unless the defender is asleep. */
void HAND_WAZA_DreamEaterFailIfAwake(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    int defenderId;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    defenderId = (unsigned char)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, defenderId), BTL_SICK_SLEEP) == 0)
        BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_FAIL_FLAG, 1);
}



/* Dream Eater: the second event sets the fail flag unconditionally (for the attacker). */
void HAND_WAZA_DreamEaterSetFailFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_FAIL_FLAG, 1);
}



const BtlEventHandler *HAND_WAZA_GetCaptivateHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gCaptivateHandlers;
}



/* Captivate: fails when either Pokemon has no gender or both have the same gender. */
void HAND_WAZA_CaptivateFailOnSameOrNoGender(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *target;
    struct BtlPokeParam *user;
    u8 targetId;
    u8 userGender;
    u8 targetGender;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        userGender = BTL_POKEPARAM_GetValue(user, BPP_VALUE_GENDER);
        targetGender = BTL_POKEPARAM_GetValue(target, BPP_VALUE_GENDER);
        if (userGender == BTL_GENDER_NONE || targetGender == BTL_GENDER_NONE || userGender == targetGender)
            BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_FAIL_FLAG, 1);
    }
}



/* Tri Attack: the handler is in the next unit. */
const BtlEventHandler *HAND_WAZA_GetTriAttackHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gTriAttackHandlers;
}



/*
 * Tri Attack, event DECIDE_ADD_SICK (the handler table is in the previous
 * unit): picks paralysis, burn or freeze at random with a chance of 20 percent.
 */
void HAND_WAZA_TriAttackOnDecideAddSick(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    u32 sickId;
    union SickCont sickCont;
    int choiceCount;

    choiceCount = 3;
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        sickId = gTriAttackSickIds[(u8)BTL_CALC_Random(choiceCount)];
        sickCont = BTL_CALC_MakeDefaultSickCont(sickId);
        BTL_EVENT_OverwriteVar(HANDVAR_SICK_ID, sickId);
        BTL_EVENT_OverwriteVar(HANDVAR_SICK_CONT, sickCont.raw);
        BTL_EVENT_OverwriteVar(HANDVAR_ADD_SICK_PERCENT, 20);
    }
}



/* Secret Power: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddSecretPower(int *handlerCount)
{
    *handlerCount = 2;
    return gSecretPowerHandlers;
}



/*
 * Secret Power: maps the kind of ground the battle is fought on to the extra
 * effect. effectKind: 0 add a status, 1 lower a stat stage, 2 flinch.
 * effectValue: the status id or the stat stage id. Returns the number of the
 * animation that goes with the ground; either out pointer may be 0.
 */
u8 HAND_WAZA_SecretPowerGetGroundEffect(struct BtlServerFlow *flow, u8 *effectKind, u8 *effectValue)
{
    u8 anim;
    u8 kind;
    u8 value;
    int ground;

    ground = BTL_SERVER_FLOW_GetFieldSituationType(flow);
    switch (ground) {
    case 1:
    case 2:
    case 3:
    case 8:
    case 15:
        kind = 1;
        value = BTL_RANK_ACCURACY;
        anim = 1;
        break;
    case 4:
    case 14:
    default:
        kind = 0;
        value = BTL_SICK_PARALYSIS;
        anim = 0;
        break;
    case 10:
        kind = 2;
        value = 0;
        anim = 6;
        break;
    case 0:
    case 5:
        kind = 0;
        value = BTL_SICK_SLEEP;
        anim = 7;
        break;
    case 6:
    case 11:
    case 12:
        kind = 1;
        value = BTL_RANK_ATTACK;
        anim = 5;
        break;
    case 9:
        kind = 1;
        value = BTL_RANK_SPEED;
        anim = 2;
        break;
    case 7:
    case 13:
        kind = 0;
        value = BTL_SICK_FREEZE;
        anim = (ground == 7) ? value : 4;
        break;
    }
    if (effectKind)
        *effectKind = kind;
    if (effectValue)
        *effectValue = value;
    return anim;
}



/* Secret Power, event PREPARE_MOVE: hands the animation of the ground to the flow. */
void HAND_WAZA_SecretPowerOnPrepareMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID))
        BTL_SERVER_FLOW_SetCurTurnStateFlag(flow, HAND_WAZA_SecretPowerGetGroundEffect(flow, 0, 0));
}



/*
 * Secret Power, event ADD_EFFECT: with a chance of 30 percent adds the extra
 * effect of the ground. Skipped when an ability blocks extra effects.
 */
void HAND_WAZA_SecretPowerOnAddEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    struct BtlPokeParam *attacker;
    u8 targetId;
    u8 effectKind;
    u8 effectValue;
    struct HandExAddSick *addSick;
    struct HandExRankChange *rank;
    struct HandExFlinch *flinch;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID) && BTL_EVENT_GetVar(HANDVAR_EFFECT_BLOCKED) == 0 && BTL_CALC_Random(100) < 30) {
        attacker = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        targetId = BTL_EVENT_GetVar(HANDVAR_EFFECT_TARGET_ID);
        HAND_WAZA_SecretPowerGetGroundEffect(flow, &effectKind, &effectValue);
        switch (effectKind) {
        case 0:
            addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            addSick->pokeId = targetId;
            addSick->sickKind = effectValue;
            BTL_CALC_MakeSickContFromKind(effectValue, attacker, &addSick->sickCont);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
            break;
        case 1:
            rank = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
            rank->targetCount = 1;
            rank->pokeId = targetId;
            rank->rankKind = effectValue;
            rank->volume = -1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, rank);
            break;
        case 2:
            flinch = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_FLINCH, pokeId);
            flinch->pokeId = targetId;
            flinch->percent = 100;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, flinch);
            break;
        }
    }
}



/* Chatter (its handler is in the next unit): stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddChatter(int *handlerCount)
{
    *handlerCount = 1;
    return gChatterHandlers;
}



/*
 * Chatter, event DECIDE_ADD_SICK: only Chatot confuses, with a chance of 10
 * percent, or 30 percent when the Pokemon has used the move more than twice.
 * Lever: the constant 6 lives in r5 across the calls (movs r5,#6 before the
 * BTL_POKEPARAM_GetMon bl); an int local folds it into each use, an enum local keeps it.
 */
void HAND_WAZA_ChatterOnDecideAddSick(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    struct BtlPokeParam *attacker;
    u32 useCount;
    ChatterSick sickId;
    int percent;
    union SickCont sickCont;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        attacker = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_GetSpecies(attacker) == SPECIES_CHATOT) {
            useCount = BTL_SERVER_FLOW_QueryPokeClientFlag(flow, pokeId);
            if (useCount != 0) {
                sickId = CHATTER_SICK_CONFUSION;
                BTL_POKEPARAM_GetMon(attacker);
                if (useCount > 2)
                    percent = 30;
                else
                    percent = 10;
                BTL_CALC_MakeSickContFromKind(sickId, attacker, &sickCont);
                BTL_EVENT_OverwriteVar(HANDVAR_SICK_ID, sickId);
                BTL_EVENT_OverwriteVar(HANDVAR_SICK_CONT, sickCont.raw);
                BTL_EVENT_OverwriteVar(HANDVAR_ADD_SICK_PERCENT, percent);
            }
        }
    }
}



/* Wrap, Bind, Fire Spin, Clamp, Sand Tomb, Magma Storm: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddTrap(int *handlerCount)
{
    *handlerCount = 2;
    return gBindSickHandlers;
}



/* Trap moves, event DECIDE_ADD_SICK: records the move id in the status data. */
void HAND_WAZA_TrapOnDecideAddSick(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    union SickCont sickCont;
    u16 moveId;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    moveId = BTL_EVENT_GetFactorKey(factor);
    sickCont.raw = BTL_EVENT_GetVar(HANDVAR_SICK_CONT);
    BTL_SICKCONT_SetValue(&sickCont, moveId);
    BTL_EVENT_OverwriteVar(HANDVAR_SICK_CONT, sickCont.raw);
}



/* Trap moves, event ADD_SICK_MESSAGE: shows the message of the move that trapped the target. */
void HAND_WAZA_TrapOnAddSickMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    BtlStrParam *message;
    u8 defenderId;
    int messageId;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    if (BTL_EVENT_GetVar(HANDVAR_SICK_ID) != BTL_SICK_TRAP)
        return;
    message = (BtlStrParam *)BTL_EVENT_GetVar(HANDVAR_MESSAGE);
    defenderId = BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID);
    switch (BTL_EVENT_GetFactorKey(factor)) {
    case 0x23: /* Wrap */
        messageId = 0x32a;
        break;
    case 0x14: /* Bind */
        messageId = 0x323;
        break;
    case 0x53: /* Fire Spin */
        messageId = 0x33b;
        break;
    case 0x80: /* Clamp */
        messageId = 0x331;
        break;
    case 0x148: /* Sand Tomb */
        messageId = 0x341;
        break;
    case 0x1cf: /* Magma Storm */
        messageId = 0x33e;
        break;
    case 0xfa: /* Whirlpool */
        messageId = 0x338;
        break;
    default:
        return;
    }
    BTL_SERVER_FLOW_InitMsgRecord(message, HANDEX_MESSAGE_SET, messageId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(message, defenderId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(message, pokeId);
}



/* Whirlpool: stores the handler count and returns the handler table (the trap handlers plus two of its own). */
BtlEventHandler *HAND_WAZA_AddWhirlpool(int *handlerCount)
{
    *handlerCount = 4;
    return gWhirlpoolHandlers;
}



/* Whirlpool, event INVULNERABLE_CHECK: hits a target that is underwater (Dive). */
void HAND_WAZA_WhirlpoolOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID) && BTL_EVENT_GetVar(HANDVAR_SEMI_INVULNERABLE) == BTL_SEMI_INVULNERABLE_UNDERWATER)
        BTL_EVENT_OverwriteVar(HANDVAR_AVOID_FLAG, 0);
}



/* Whirlpool, event CALC_DAMAGE_RATIO: doubles the damage against a target that is underwater. */
void HAND_WAZA_WhirlpoolOnCalcDamageRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    int underwaterFlag;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        underwaterFlag = 4;
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID)), underwaterFlag)) {
            BTL_EVENT_MultiplyVar(HANDVAR_RATIO, underwaterFlag << 11);
        }
    }
}



/* Super Fang (its handler is in the next unit): stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddSuperFang(int *handlerCount)
{
    *handlerCount = 1;
    return gSuperFangHandlers;
}



/* Super Fang, event CALC_FIXED_DAMAGE: half of the target's current HP, at least 1. */
void HAND_WAZA_SuperFangOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    int hp;
    u16 damage;
    u8 defenderId;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        defenderId = BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID);
        hp = BTL_POKEPARAM_GetValue(BTL_SERVER_FLOW_GetPokeParam(flow, defenderId), BPP_VALUE_HP);
        damage = hp / 2;
        if (damage == 0) damage = 1;
        BTL_EVENT_OverwriteVar(HANDVAR_FIXED_DAMAGE, damage);
    }
}



/* Dragon Rage: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddDragonRage(int *handlerCount)
{
    *handlerCount = 1;
    return gDragonRageHandlers;
}



/* Dragon Rage, event CALC_FIXED_DAMAGE: 40 damage. */
void HAND_WAZA_DragonRageOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(HANDVAR_FIXED_DAMAGE, 40);
}



/* Sonic Boom (its handler is in the next unit): stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddSonicBoom(int *handlerCount)
{
    *handlerCount = 1;
    return gSonicBoomHandlers;
}



/* Sonic Boom, event CALC_FIXED_DAMAGE: 20 damage. */
void HAND_WAZA_SonicBoomOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(HANDVAR_FIXED_DAMAGE, 20);
}



/* Endeavor: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddEndeavor(int *handlerCount)
{
    *handlerCount = 2;
    return gEndeavorHandlers;
}



/* Endeavor, event NO_EFFECT_CHECK: no effect when the target has no more HP than the user. */
void HAND_WAZA_EndeavorOnNoEffectCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    struct BtlPokeParam *defender;
    struct BtlPokeParam *attacker;
    u8 defenderId;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        defenderId = BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID);
        defender = BTL_SERVER_FLOW_GetPokeParam(flow, defenderId);
        attacker = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_GetValue(defender, BPP_VALUE_HP) - BTL_POKEPARAM_GetValue(attacker, BPP_VALUE_HP) <= 0) {
            BTL_EVENT_OverwriteVar(HANDVAR_NO_EFFECT_FLAG, 1);
        }
    }
}



/* Endeavor, event CALC_FIXED_DAMAGE: the target's HP minus the user's HP. */
void HAND_WAZA_EndeavorOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    struct BtlPokeParam *attacker;
    int damage;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        attacker = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        damage = BTL_POKEPARAM_GetValue(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID)), BPP_VALUE_HP) - BTL_POKEPARAM_GetValue(attacker, BPP_VALUE_HP);
        if (damage < 0) damage = 1;
        BTL_EVENT_OverwriteVar(HANDVAR_FIXED_DAMAGE, damage);
    }
}



/* Seismic Toss and Night Shade: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddLevelDamage(int *handlerCount)
{
    *handlerCount = 1;
    return gLevelDamageHandlers;
}



/* Seismic Toss and Night Shade, event CALC_FIXED_DAMAGE: damage equal to the user's level. */
void HAND_WAZA_LevelDamageOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    int level;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    level = (unsigned char)BTL_POKEPARAM_GetValue(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BPP_VALUE_LEVEL);
    BTL_EVENT_OverwriteVar(HANDVAR_FIXED_DAMAGE, level);
}



/* Psywave (its handler is in the next unit): stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddPsywave(int *handlerCount)
{
    *handlerCount = 1;
    return gPsywaveHandlers;
}



/* Psywave, event CALC_FIXED_DAMAGE: level times a random 50 to 150 percent, at least 1. */
void HAND_WAZA_PsywaveOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    u8 level;
    u16 percent;
    u16 damage;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        level = BTL_POKEPARAM_GetValue(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BPP_VALUE_LEVEL);
        percent = BTL_CALC_Random(101) + 50;
        damage = (level * percent) / 100;
        if (damage == 0) damage = 1;
        BTL_EVENT_OverwriteVar(HANDVAR_FIXED_DAMAGE, damage);
    }
}



/* Stockpile: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddStockpile(int *handlerCount)
{
    *handlerCount = 2;
    return gStockpileHandlers;
}



/* Stockpile, event MOVE_FAIL_CHECK: fails when the user has stockpiled three times. */
void HAND_WAZA_StockpileOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID) && BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BPP_COUNTER_STOCKPILE) >= STOCKPILE_MAX)
        BTL_EVENT_OverwriteVar(HANDVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
}



/*
 * Stockpile, event MOVE_EFFECT: counts one more stockpile, shows the message
 * and raises Defense and Special Defense by one stage each; the two stat
 * counters only count when the stage really rose.
 * Lever: zeroOrCount is 0 (counter index) first and the new stockpile count later.
 */
void HAND_WAZA_StockpileOnMoveEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    struct BtlPokeParam *poke;
    struct HandExSetCounter *setCounter;
    struct HandExMessage *messageRecord;
    struct HandExRankChange *rank;
    u32 stockpile;
    int zeroOrCount;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        zeroOrCount = 0;
        stockpile = BTL_POKEPARAM_GetCounter(poke, BPP_COUNTER_STOCKPILE);
        if (stockpile >= STOCKPILE_MAX) return;
        setCounter = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
        setCounter->pokeId = pokeId;
        setCounter->counterId = zeroOrCount;
        zeroOrCount = stockpile + 1;
        setCounter->value = zeroOrCount;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, setCounter);
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x2d1);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), zeroOrCount);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
        rank = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
        rank->targetCount = 1;
        rank->pokeId = pokeId;
        rank->rankKind = BTL_RANK_DEFENSE;
        rank->volume = 1;
        rank->showMessage = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rank);
        setCounter = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
        setCounter->header |= HANDEX_FLAG_AFTER_SUCCESS;
        setCounter->pokeId = pokeId;
        setCounter->counterId = BPP_COUNTER_STOCKPILE_DEFENSE;
        setCounter->value = BTL_POKEPARAM_GetCounter(poke, BPP_COUNTER_STOCKPILE_DEFENSE) + 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, setCounter);
        rank = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
        rank->targetCount = 1;
        rank->pokeId = pokeId;
        rank->rankKind = BTL_RANK_SP_DEFENSE;
        rank->volume = 1;
        rank->showMessage = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rank);
        setCounter = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
        setCounter->header |= HANDEX_FLAG_AFTER_SUCCESS;
        setCounter->pokeId = pokeId;
        setCounter->counterId = BPP_COUNTER_STOCKPILE_SP_DEFENSE;
        setCounter->value = BTL_POKEPARAM_GetCounter(poke, BPP_COUNTER_STOCKPILE_SP_DEFENSE) + 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, setCounter);
    }
}



/* Spit Up: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddSpitUp(int *handlerCount)
{
    *handlerCount = 3;
    return gSpitUpHandlers;
}



/* Spit Up and Swallow, event MOVE_FAIL_CHECK: fails when the user has not stockpiled. */
void HAND_WAZA_StockpileUseOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID) && BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BPP_COUNTER_STOCKPILE) == 0)
        BTL_EVENT_OverwriteVar(HANDVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
}



static inline void SetBasePower(int power)
{
    BTL_EVENT_OverwriteVar(HANDVAR_BASE_POWER, power);
}



/*
 * Spit Up, event GET_MOVE_POWER: 100 power for each stockpile.
 * Lever: the product passed through a static inline helper is computed before the
 * helper's constant first argument is loaded (no result copy).
 */
void HAND_WAZA_SpitUpOnGetMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        SetBasePower(BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BPP_COUNTER_STOCKPILE) * 100);
}



/*
 * Spit Up and Swallow, event MOVE_END: takes back the Defense and Special
 * Defense that the stockpiles gave, shows the message and resets the counters.
 */
void HAND_WAZA_StockpileUseOnMoveEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    struct BtlPokeParam *poke;
    int defenseStages;
    int spDefenseStages;
    int stockpile;
    struct HandExRankChange *rank;
    struct HandExSetCounter *setCounter;
    struct HandExMessage *messageRecord;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_POKE_ID)) return;
    poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    defenseStages = BTL_POKEPARAM_GetCounter(poke, BPP_COUNTER_STOCKPILE_DEFENSE);
    spDefenseStages = BTL_POKEPARAM_GetCounter(poke, BPP_COUNTER_STOCKPILE_SP_DEFENSE);
    stockpile = BTL_POKEPARAM_GetCounter(poke, BPP_COUNTER_STOCKPILE);
    if (defenseStages != 0) {
        rank = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
        rank->targetCount = 1;
        rank->pokeId = pokeId;
        rank->rankKind = BTL_RANK_DEFENSE;
        rank->volume = -defenseStages;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rank);
        setCounter = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
        setCounter->pokeId = pokeId;
        setCounter->counterId = BPP_COUNTER_STOCKPILE_DEFENSE;
        setCounter->value = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, setCounter);
    }
    if (spDefenseStages != 0) {
        rank = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
        rank->targetCount = 1;
        rank->pokeId = pokeId;
        rank->rankKind = BTL_RANK_SP_DEFENSE;
        rank->volume = -spDefenseStages;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rank);
        setCounter = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
        setCounter->pokeId = pokeId;
        setCounter->counterId = BPP_COUNTER_STOCKPILE_SP_DEFENSE;
        setCounter->value = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, setCounter);
    }
    if (stockpile != 0) {
        setCounter = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
        setCounter->pokeId = pokeId;
        setCounter->counterId = BPP_COUNTER_STOCKPILE;
        setCounter->value = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, setCounter);
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 724);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}



/* Swallow (its handler is in the next unit): stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddSwallow(int *handlerCount)
{
    *handlerCount = 3;
    return gSwallowHandlers;
}



/*
 * Swallow, event CALC_HEAL_RATIO: heals a quarter, a half or all of the
 * maximum HP for one, two or three stockpiles (ratios in 20.12 fixed point).
 */
void HAND_WAZA_SwallowOnCalcHealRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    int two = 2;
    int ratio;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID)) {
        switch (BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BPP_COUNTER_STOCKPILE)) {
        case 1:
        default:
            ratio = 1 << 10;
            break;
        case 2:
            ratio = two << 10;
            break;
        case 3:
            ratio = two << 11;
            break;
        }
        BTL_EVENT_OverwriteVar(HANDVAR_RATIO, ratio);
    }
}



/* Counter: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddCounter(int *handlerCount)
{
    *handlerCount = 3;
    return gCounterHandlers;
}



/* Counter, event MOVE_FAIL_CHECK: fails unless a physical hit was taken this turn. */
void HAND_WAZA_CounterOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnMoveFailCheck(flow, pokeId, work, BTL_DAMAGE_TYPE_PHYSICAL);
}



/* Counter, event DECIDE_TARGET: targets the Pokemon that dealt the physical hit. */
void HAND_WAZA_CounterOnDecideTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnDecideTarget(flow, pokeId, work, BTL_DAMAGE_TYPE_PHYSICAL);
}



/*
 * Counter, event CALC_FIXED_DAMAGE: twice the damage of the physical hit.
 * The three moves share one body; only the constants differ.
 */
void HAND_WAZA_CounterOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnCalcFixedDamage(flow, pokeId, work, BTL_DAMAGE_TYPE_PHYSICAL, 2 << 12);
}



/* Mirror Coat: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddMirrorCoat(int *handlerCount)
{
    *handlerCount = 3;
    return gMirrorCoatHandlers;
}



/* Mirror Coat, event MOVE_FAIL_CHECK: fails unless a special hit was taken this turn. */
void HAND_WAZA_MirrorCoatOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnMoveFailCheck(flow, pokeId, work, BTL_DAMAGE_TYPE_SPECIAL);
}



/* Mirror Coat, event DECIDE_TARGET: targets the Pokemon that dealt the special hit. */
void HAND_WAZA_MirrorCoatOnDecideTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnDecideTarget(flow, pokeId, work, BTL_DAMAGE_TYPE_SPECIAL);
}



/* Mirror Coat, event CALC_FIXED_DAMAGE: twice the damage of the special hit. */
void HAND_WAZA_MirrorCoatOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnCalcFixedDamage(flow, pokeId, work, BTL_DAMAGE_TYPE_SPECIAL, 2 << 12);
}



/* Metal Burst: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddMetalBurst(int *handlerCount)
{
    *handlerCount = 3;
    return gMetalBurstHandlers;
}



/* Metal Burst, event MOVE_FAIL_CHECK: fails unless any hit was taken this turn. */
void HAND_WAZA_MetalBurstOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnMoveFailCheck(flow, pokeId, work, BTL_DAMAGE_TYPE_ANY);
}



/* Metal Burst, event DECIDE_TARGET: targets the Pokemon that dealt the last hit. */
void HAND_WAZA_MetalBurstOnDecideTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnDecideTarget(flow, pokeId, work, BTL_DAMAGE_TYPE_ANY);
}



/* Metal Burst, event CALC_FIXED_DAMAGE: one and a half times the damage of the last hit (6 << 10 is 1.5 in 20.12 fixed point). */
void HAND_WAZA_MetalBurstOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnCalcFixedDamage(flow, pokeId, work, BTL_DAMAGE_TYPE_ANY, 6 << 10);
}



/* Counter family, event MOVE_FAIL_CHECK: the move fails when no matching hit was taken. */
void HAND_WAZA_RetaliateOnMoveFailCheck(struct BtlServerFlow *flow, int pokeId, void *work, int damageType)
{
    struct BtlHitRecord hit;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID) && HAND_WAZA_FindRetaliateHit(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), damageType, &hit) == 0)
        BTL_EVENT_OverwriteVar(HANDVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
}



/*
 * Counter family, event DECIDE_TARGET: the target is the Pokemon that dealt the hit. When it
 * has left its position, the Pokemon now in that position is the target, then the
 * default target of a plain single-target move (move 1), then the attacker id as it was.
 */
void HAND_WAZA_RetaliateOnDecideTarget(struct BtlServerFlow *flow, int pokeId, void *work, int damageType)
{
    struct BtlHitRecord hit;
    int targetId;
    int pos;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        if (HAND_WAZA_FindRetaliateHit(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), damageType, &hit)) {
            targetId = hit.attackerId;
            if (BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, targetId) == BTL_POS_NONE) {
                pos = *(u8 *)&hit.hitFlags;
                targetId = BTL_POKEID_NONE;
                if (pos != BTL_POS_NONE)
                    targetId = BTL_SERVER_FLOW_GetPosTableEntryForPoke(flow, pos);
                if (targetId == BTL_POKEID_NONE) {
                    pos = BTL_SERVER_FLOW_DecideMoveTarget(flow, pokeId, 1);
                    if (pos != BTL_POS_NONE)
                        targetId = BTL_SERVER_FLOW_GetPosTableEntryForPoke(flow, pos);
                    if (targetId == BTL_POKEID_NONE)
                        targetId = hit.attackerId;
                }
            }
            BTL_EVENT_OverwriteVar(HANDVAR_DEFENDER_ID, targetId);
        }
    }
}



/* Counter family, event CALC_FIXED_DAMAGE: the damage of the hit times a ratio in 20.12 fixed point. */
void HAND_WAZA_RetaliateOnCalcFixedDamage(struct BtlServerFlow *flow, int pokeId, void *work, int damageType, int ratio)
{
    struct BtlHitRecord hit;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        if (HAND_WAZA_FindRetaliateHit(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), damageType, &hit)) {
            BTL_EVENT_OverwriteVar(HANDVAR_FIXED_DAMAGE, BTL_CALC_MulRatio(hit.damage, ratio));
        }
    }
}



/*
 * Counter family: looks through the hits taken this turn, newest first, for one
 * from a foe whose move has the damage type (0 matches any). Fills hit and returns 1 if found.
 */
int HAND_WAZA_FindRetaliateHit(struct BtlPokeParam *poke, int damageType, struct BtlHitRecord *out)
{
    u8 pokeId = BTL_POKEPARAM_GetPokeId(poke);
    u8 hitsAgo = 0;

    while (BTL_POKEPARAM_GetHitRecord(poke, 0, hitsAgo++, out)) {
        if (BTL_MAIN_IsPokeSamePair(pokeId, out->attackerId) == 0) {
            if (damageType == 0 || damageType == WAZA_TOOL_GetDamageType(out->moveId))
                return 1;
        }
    }
    return 0;
}



/* Last Resort (its handler is in the next unit): stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddLastResort(int *handlerCount)
{
    *handlerCount = 1;
    return gLastResortHandlers;
}



/*
 * Last Resort, event MOVE_FAIL_CHECK: fails unless the user knows Last Resort,
 * knows at least two moves and has used every other move.
 */
void HAND_WAZA_LastResortOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    struct BtlPokeParam *poke;
    u8 moveCount;
    u8 slot;
    u8 usedCount;
    int hasLastResort;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        moveCount = BTL_POKEPARAM_GetMoveCount(poke);
        usedCount = 0;
        hasLastResort = 0;
        for (slot = 0; slot < moveCount; slot++) {
            if (BTL_POKEPARAM_GetMoveId(poke, slot) == MOVE_LAST_RESORT) {
                hasLastResort = 1;
            } else if (BTL_POKEPARAM_GetMoveUsedFlag(poke, slot)) {
                usedCount++;
            }
        }
        if (hasLastResort == 0 || moveCount < 2 || usedCount < moveCount - 1)
            BTL_EVENT_OverwriteVar(HANDVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
    }
}



/* Snore: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddSnore(int *handlerCount)
{
    *handlerCount = 2;
    return gSnoreHandlers;
}



/* Snore, event ACTION_CHECK: sleep does not stop the user from using the move. */
void HAND_WAZA_SnoreOnActionCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID) && BTL_EVENT_GetVar(HANDVAR_FAIL_REASON) == BTL_FAIL_REASON_ASLEEP)
        BTL_EVENT_OverwriteVar(HANDVAR_GENERAL_FLAG, 1);
}



/* Snore, event MOVE_FAIL_CHECK: the move works only while the user is asleep. */
void HAND_WAZA_SnoreOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    int sickSleep = BTL_SICK_SLEEP;
    struct BtlPokeParam *poke;
    int failReasonKey;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        failReasonKey = HANDVAR_FAIL_REASON;
        if (BTL_EVENT_GetVar(failReasonKey) == BTL_FAIL_REASON_ASLEEP) {
            BTL_EVENT_OverwriteVar(failReasonKey, 0);
            return;
        }
        if (BTL_POKEPARAM_HasSick(poke, sickSleep) == 0)
            BTL_EVENT_OverwriteVar(failReasonKey, BTL_FAIL_REASON_MOVE_FAILED);
    }
}



/* Nightmare: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddNightmare(int *handlerCount)
{
    *handlerCount = 1;
    return gNightmareHandlers;
}



/* Nightmare, event NO_EFFECT_CHECK: no effect on a target that is not asleep. */
void HAND_WAZA_NightmareOnNoEffectCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    u8 defenderId;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        defenderId = BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID);
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, defenderId), BTL_SICK_SLEEP) == 0)
            BTL_EVENT_OverwriteVar(HANDVAR_NO_EFFECT_FLAG, 1);
    }
}



/* Sucker Punch (its handler is in the next unit): stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddSuckerPunch(int *handlerCount)
{
    *handlerCount = 1;
    return gSuckerPunchHandlers;
}





/*
 * Sucker Punch, no-effect check: the move fails unless the target still has
 * to act this turn with a damaging move.
 * The 12-byte tail (movs r1,#3; str r1,[r0]; ldr r0,[pc]; bx lr; .word) is an
 * unlabelled follower stub, not part of this function.
 * Lever: targetPoke = BTL_SERVER_FLOW_GetPokeParam(...) bound to a local before `targetWillAttack = 0`
 * keeps the `movs r4, #0` between the argument setup and the BTL_POKEPARAM_TestTurnFlag call.
 */
void HAND_WAZA_SuckerPunchCheckNoEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u32 targetAction;
    u8 targetId;
    int targetWillAttack;
    struct BtlPokeParam *targetPoke;
    u32 targetMove;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        targetPoke = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        targetWillAttack = 0;
        if (BTL_POKEPARAM_TestTurnFlag(targetPoke, BTL_TURN_FLAG_ACTION_FINISHED) == 0) {
            if (BTL_SERVER_FLOW_GetActionWordByPokeId(flow, targetId, &targetAction) != 0 && (targetMove = BTL_ACTION_GetFightMove((union BtlAction *)(&targetAction))) != 0 && WAZA_TOOL_IsDamaging(targetMove) != 0)
                targetWillAttack = 1;
        }
        if (targetWillAttack == 0) {
            if ((targetMove = BTL_ACTION_GetFightMove((union BtlAction *)(&targetAction))) == 0 || WAZA_TOOL_IsDamaging(targetMove) == 0) {
                if (BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1) != 0)
                    BTL_SERVER_FLOW_InitMsgRecord((BtlStrParam *)BTL_EVENT_GetVar(BTL_EVAR_NO_EFFECT_STRING), HANDEX_STR_STD, 0x47);
            }
        }
    }
}





/* Pursuit handler table getter: three handlers. */
BtlEventHandler *HAND_WAZA_PursuitGetHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gPursuitHandlers;
}





/*
 * Pursuit, before-switch event: when the Pokemon that leaves is an opponent
 * and the move can reach it, put this Pokemon on the list of Pokemon that
 * strike first.
 */
void HAND_WAZA_PursuitQueueIntercept(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u32 actionWord;
    u8 switchingId;

    if (BTL_SERVER_FLOW_GetActionWordByPokeId(flow, pokeId, &actionWord) != 0) {
        switchingId = BTL_EVENT_GetVar(BTL_EVAR_SWITCHING_POKE_ID);
        if (BTL_MAIN_IsPokeSamePair(switchingId, pokeId) == 0) {
            BTL_SERVER_FLOW_GetPokeViewPos(flow, switchingId);
            BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
            if (BTL_SERVER_FLOW_CheckAllyMoveAutoHitById(flow, pokeId, switchingId, 0) == 0)
                BTL_SERVER_FLOW_AppendFrontOrder(flow, pokeId);
        }
    }
}







/* Pursuit, always-hit query: a pursuit that interrupts a switch cannot miss. */
void HAND_WAZA_PursuitAlwaysHitOnIntercept(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_SERVER_FLOW_TestStateFlagBit0((unsigned char *)flow))
        BTL_EVENT_OverwriteVar(BTL_EVAR_RESULT_FLAG, 1);
}






/* Pursuit, base power event: a pursuit that interrupts a switch hits with double power. */
void HAND_WAZA_PursuitDoublePowerOnIntercept(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_SERVER_FLOW_TestStateFlagBit0((unsigned char *)flow) != 0)
            HAND_COMMON_EventScaleDamage(2);
    }
}




/* Self-Destruct and Explosion handler table getter: three handlers. */
BtlEventHandler *HAND_WAZA_SelfDestructGetHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gSelfDestructHandlers;
}




/* Self-Destruct and Explosion, move hit event: the user faints. */
void HAND_WAZA_SelfDestructFaintOnHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExFaint *faint;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        faint = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_FAINT, pokeId);
        faint->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, faint);
    }
}






/* Self-Destruct and Explosion, move execute query: push the user's explosion command. */
void HAND_WAZA_SelfDestructPushUserCmd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_SERVER_FLOW_PushCmdRecord(flow, 0x3b, pokeId);
}






/* Self-Destruct and Explosion, move finished event: the user faints (also when the move missed). */
void HAND_WAZA_SelfDestructFaintOnFinish(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExFaint *faint;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        faint = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_FAINT, pokeId);
        faint->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, faint);
    }
}




/* Focus Energy handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_FocusEnergyGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gFocusEnergyHandlers;
}






/*
 * Focus Energy, status move effect: raise the critical-hit rate of the user
 * unless it is already raised, then show the message.
 * The tail after the pop (movs r1,#4; str r1,[r0]; ldr r0,[pc]; bx lr) is an
 * unlabelled follower stub.
 */
void HAND_WAZA_FocusEnergyApplyEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExSetContFlag *setFlag;
    HandExMessage *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_CONT_FLAG_CRITICAL_UP) == 0) {
            setFlag = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_CONT_FLAG, pokeId);
            setFlag->pokeId = pokeId;
            setFlag->contFlag = BTL_CONT_FLAG_CRITICAL_UP;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, setFlag);
            message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&message->message, HANDEX_STR_SET, 0x411);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&message->message), pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
        }
    }
}






/* Charge handler table getter: four handlers. */
BtlEventHandler *HAND_WAZA_ChargeGetHandlers(int *handlerCount)
{
    *handlerCount = 4;
    return gChargeHandlers;
}






/*
 * Charge, move execute query: when the user executes Charge itself, show the
 * message and remember that the charge is stored.
 */
void HAND_WAZA_ChargeStoreOnUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaChargeWork *work)
{
    HandExMessage *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID) == BTL_EVENT_GetFactorKey(factor)) {
            message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&message->message, HANDEX_STR_SET, 0x298);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&message->message), pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
            BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_HANDLED_FLAG, 1);
            work->charged = 1;
            work->phase = 1;
        }
    }
}









/* Charge, power ratio event: an Electric move used with the charge doubles its power. */
void HAND_WAZA_ChargeBoostElectricPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaChargeWork *work)
{
    if (work->phase == 2) {
        if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
            if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == POKETYPE_ELECTRIC)
                BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_2_0);
        }
    }
}









/* Charge, move start event: the next move other than Charge takes the stored charge. */
void HAND_WAZA_ChargeArmOnNextMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaChargeWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID) != BTL_EVENT_GetFactorKey(factor))
            work->phase = 2;
    }
}







/* Charge, move end event: the charge is used up, remove the factor. */
void HAND_WAZA_ChargeExpireOnMoveEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaChargeWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (work->phase == 2)
            BTL_EVENT_RemoveFactor(factor);
    }
}





/* Perish Song handler table getter: two handlers. */
BtlEventHandler *HAND_WAZA_PerishSongGetHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gPerishSongHandlers;
}





/* Perish Song, move succeeded event: show the standard message. */
void HAND_WAZA_PerishSongShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExMessage *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&message->message, HANDEX_STR_STD, 0x77);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
    }
}






/* Perish Song, no-effect check: the move itself never fails. */
void HAND_WAZA_PerishSongClearNoEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID) == BTL_EVENT_GetFactorKey(factor))
            BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 0);
    }
}




/* Leech Seed handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_LeechSeedGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gLeechSeedHandlers;
}




/* Leech Seed, sick cont event: store the position of the seeder in the condition. */
void HAND_WAZA_LeechSeedSetSickCont(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        union SickCont seederCont = BTL_SICKCONT_MakeKind1Value(BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, pokeId));
        BTL_EVENT_OverwriteVar(BTL_EVAR_SICK_CONT, seederCont.raw);
    }
}




/* Pay Day handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_PayDayGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gPayDayHandlers;
}




/* Pay Day, move hit event: scatter coins worth five times the user's level. */
void HAND_WAZA_PayDayScatterCoins(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    int level;
    HandExMessage *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        level = BTL_POKEPARAM_GetValue(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_VALUE_LEVEL);
        if (BTL_SERVER_FLOW_TryAddMainCounter(flow, level * 5, pokeId) != 0) {
            message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&message->message, HANDEX_STR_STD, 0x7a);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
        }
    }
}




/* Rage handler table getter: three handlers. */
BtlEventHandler *HAND_WAZA_RageGetHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gRageHandlers;
}




/* Rage, move execute query: using Rage again keeps the rage; any other move ends it. */
void HAND_WAZA_RageKeepOnExecute(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work)
{
    int usedMoveId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        usedMoveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
        if (usedMoveId == BTL_EVENT_GetFactorKey(factor)) {
            work->active = 1;
            return;
        }
        HAND_WAZA_RemoveMoveHandlerOfPoke(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_EVENT_GetFactorKey(factor));
    }
}






/* Rage, damage end event: while the rage lasts, being hit raises Attack by one stage. */
void HAND_WAZA_RageRaiseAttackOnHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExRankChange *rank;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE) == 0 && BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) == 0) {
        rank = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
        rank->rankKind = BTL_RANK_ATTACK;
        rank->volume = 1;
        rank->showMessage = 0;
        rank->targetCount = 1;
        rank->targets[0] = pokeId;
        rank->fromMove = 1;
        BTL_SERVER_FLOW_InitMsgRecord(&rank->message, HANDEX_STR_SET, 0x214);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&rank->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rank);
    }
}






/* Rage, action start event: the rage ends when the Pokemon starts its next action. */
void HAND_WAZA_RageEndOnActionStart(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && work->active != 0)
        HAND_WAZA_RemoveMoveHandlerOfPoke(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_EVENT_GetFactorKey(factor));
}




/* Aqua Ring handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_AquaRingGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gAquaRingHandlers;
}






/* Aqua Ring, status move effect: add the Aqua Ring condition unless the user has it. */
void HAND_WAZA_AquaRingApplyEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExAddSick *addSick;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_SICK_AQUA_RING) == 0) {
            addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            addSick->sickKind = BTL_SICK_AQUA_RING;
            addSick->sickCont = BTL_SICKCONT_MakeKind1Empty();
            addSick->pokeId = pokeId;
            BTL_SERVER_FLOW_InitMsgRecord(&addSick->message, HANDEX_STR_SET, 0x259);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&addSick->message), pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
        }
    }
}






/* Thrash, Petal Dance and Outrage handler table getter: three handlers. */
BtlEventHandler *HAND_WAZA_ThrashGetHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gThrashHandlers;
}






/*
 * Thrash family, move execute query: lock the user into the move for two or
 * three turns, unless it is locked already.
 * Lever: BTL_SICKCONT_MakeKind2 returns a one-word struct, which reserves the
 * third frame word (`sub sp, #0xc` with push {r4-r7, lr}); see
 * docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md.
 */
void HAND_WAZA_ThrashStartLock(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work)
{
    HandExAddSick *addSick;
    u8 lockTurns;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_SICK_MOVE_LOCK) == 0 && work->active == 0) {
            lockTurns = BTL_CALC_Random(2) + 2;
            addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            addSick->sickKind = BTL_SICK_MOVE_LOCK;
            addSick->sickCont = BTL_SICKCONT_MakeKind2(lockTurns, BTL_EVENT_GetFactorKey(factor));
            addSick->suppressMessage = 0;
            addSick->pokeId = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
            work->active = 1;
            work->count = lockTurns;
        }
    }
}








/*
 * Thrash family, move end event: count down the lock. A failed move ends it;
 * when the turns run out the user becomes confused.
 */
void HAND_WAZA_ThrashAdvanceTurn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work)
{
    struct BtlPokeParam *poke;
    HandExCureSick *cureSick;
    HandExAddSick *addSick;
    int removeFactor;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (work->active != 0) {
            removeFactor = 0;
            if (work->count != 0)
                work->count = work->count - 1;
            if (BTL_EVENT_GetVar(BTL_EVAR_RESULT_FLAG) == 0) {
                cureSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
                cureSick->sickKind = BTL_SICK_MOVE_LOCK;
                removeFactor = 1;
                cureSick->pokeCount = 1;
                cureSick->pokeIds[0] = pokeId;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSick);
            }
            if (work->count == 0) {
                addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
                addSick->sickKind = BTL_SICK_CONFUSION;
                BTL_CALC_MakeSickContFromKind(BTL_SICK_CONFUSION, poke, &addSick->sickCont);
                removeFactor = 1;
                addSick->fromMove = 1;
                addSick->pokeId = pokeId;
                BTL_SERVER_FLOW_InitMsgRecord(&addSick->message, HANDEX_STR_SET, 0x168);
                BTL_SERVER_FLOW_AppendMsgRecordArg((&addSick->message), pokeId);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
            }
            if (removeFactor != 0)
                HAND_WAZA_RemoveMoveHandlerOfPoke(poke, BTL_EVENT_GetFactorKey(factor));
        }
    }
}








/* Thrash family, turn end event: a sleeping user loses the lock and the factor ends. */
void HAND_WAZA_ThrashEndOnSleep(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *poke;
    HandExCureSick *cureSick;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_HasSick(poke, BTL_SICK_SLEEP) != 0) {
            cureSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
            cureSick->sickKind = BTL_SICK_MOVE_LOCK;
            cureSick->pokeCount = 1;
            cureSick->pokeIds[0] = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSick);
            HAND_WAZA_RemoveMoveHandlerOfPoke(poke, BTL_EVENT_GetFactorKey(factor));
        }
    }
}





/* Uproar handler table getter: five handlers. */
BtlEventHandler *HAND_WAZA_UproarGetHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gUproarHandlers;
}





/*
 * Uproar, move hit event: lock the user into the move for three turns, show
 * the uproar message and wake every sleeping Pokemon.
 */
void HAND_WAZA_UproarStart(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 pokeId, HandWazaWork *work)
{
    HandExAddSick *addSick;
    HandExMessage *message;
    HandExCureSick *cureSick;
    HandPokeList *pokeList;
    u32 position;
    unsigned i;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) return;
    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_SICK_MOVE_LOCK) != 0) return;
    if (work->active != 0) return;
    addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
    addSick->sickKind = BTL_SICK_MOVE_LOCK;
    addSick->sickCont = BTL_SICKCONT_MakeKind2(3, BTL_EVENT_GetFactorKey(factor));
    addSick->suppressMessage = 0;
    addSick->pokeId = pokeId;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
    message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&message->message, HANDEX_STR_SET, 703);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&message->message), pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
    position = BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, pokeId);
    pokeList = (HandPokeList *)BTL_SERVER_FLOW_GetScratchBuffer(flow, 7);
    pokeList->count = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(position | BTL_TARGET_CODE_ALL_POKES), pokeList->pokeIds);
    for (i = 0; i < pokeList->count; i++) {
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeList->pokeIds[i]), BTL_SICK_SLEEP) != 0) {
            cureSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
            cureSick->sickKind = BTL_SICK_SLEEP;
            cureSick->pokeCount = 1;
            cureSick->pokeIds[0] = pokeList->pokeIds[i];
            BTL_SERVER_FLOW_InitMsgRecord(&cureSick->message, HANDEX_STR_SET, 706);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&cureSick->message), pokeList->pokeIds[i]);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSick);
        }
    }
    work->active = 1;
}







/* Uproar, move end event: a failed move ends the lock. */
void HAND_WAZA_UproarEndOnFailure(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExCureSick *cureSick;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_RESULT_FLAG) == 0) {
            cureSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
            cureSick->sickKind = BTL_SICK_MOVE_LOCK;
            cureSick->pokeCount = 1;
            cureSick->pokeIds[0] = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSick);
        }
    }
}







/*
 * Uproar, turn end event: while the lock lasts the uproar goes on; when it
 * has ended the Pokemon calms down and the factor is removed.
 */
void HAND_WAZA_UproarOnTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work)
{
    struct BtlPokeParam *poke;
    HandExMessage *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && work->active != 0) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_IsFainted(poke) == 0) {
            if (BTL_POKEPARAM_HasSick(poke, BTL_SICK_MOVE_LOCK) == 0) {
                message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
                BTL_SERVER_FLOW_InitMsgRecord(&message->message, HANDEX_STR_SET, 0x2CE);
                BTL_SERVER_FLOW_AppendMsgRecordArg((&message->message), pokeId);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
                HAND_WAZA_RemoveMoveHandlerOfPoke(poke, BTL_EVENT_GetFactorKey(factor));
            } else {
                message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
                BTL_SERVER_FLOW_InitMsgRecord(&message->message, HANDEX_STR_SET, 0x2CB);
                BTL_SERVER_FLOW_AppendMsgRecordArg((&message->message), pokeId);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
            }
        }
    }
}







/* Uproar, sick blocked query: while it lasts, a Pokemon cannot fall asleep; show why. */
void HAND_WAZA_UproarPreventSleep(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work)
{
    HandExMessage *message;
    u8 defenderId;

    if (work->active != 0 && BTL_EVENT_GetVar(BTL_EVAR_SICK_ID) == BTL_SICK_SLEEP && BTL_EVENT_OverwriteVar(BTL_EVAR_PREVENT_FLAG, 1) != 0) {
        message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        defenderId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        BTL_SERVER_FLOW_InitMsgRecord(&message->message, HANDEX_STR_SET, (u16)(defenderId == pokeId ? 0x2C8 : 0x2C5));
        BTL_SERVER_FLOW_AppendMsgRecordArg((&message->message), defenderId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
    }
}






/* Uproar, obedience override event: while it lasts, the prevent flag is set. */
void HAND_WAZA_UproarPreventSleepSilently(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work)
{
    if (work->active != 0)
        BTL_EVENT_OverwriteVar(BTL_EVAR_PREVENT_FLAG, 1);
}





/* Rollout and Ice Ball handler table getter: five handlers. */
BtlEventHandler *HAND_WAZA_RolloutGetHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gRolloutHandlers;
}





/* Rollout and Ice Ball, move execute query: lock the user into the move for five hits. */
void HAND_WAZA_RolloutStartLock(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work)
{
    struct BtlPokeParam *poke;
    HandExAddSick *addSick;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_HasSick(poke, BTL_SICK_MOVE_LOCK) == 0 && BTL_POKEPARAM_HasSick(poke, BTL_SICK_SLEEP) == 0 && work->active == 0) {
            addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            addSick->sickKind = BTL_SICK_MOVE_LOCK;
            addSick->sickCont = BTL_SICKCONT_MakeKind2(5, BTL_EVENT_GetFactorKey(factor));
            addSick->suppressMessage = 0;
            addSick->pokeId = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
            work->count = 0;
            work->limit = 5;
            work->active = 1;
        }
    }
}










/* Rollout and Ice Ball, move done and move failed events: the lock ends. */
void HAND_WAZA_RolloutEndOnDoneOrFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        HAND_WAZA_RolloutEndLock(factor, flow, pokeId, work);
}










/* Rollout and Ice Ball, move end event: a failed move ends the lock. */
void HAND_WAZA_RolloutEndOnMoveEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_RESULT_FLAG) == 0)
            HAND_WAZA_RolloutEndLock(factor, flow, pokeId, work);
    }
}









/* Rollout and Ice Ball: cure the lock and remove the factors of the move. */
void HAND_WAZA_RolloutEndLock(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work)
{
    HandExCureSick *cureSick;

    cureSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
    cureSick->pokeIds[0] = pokeId;
    cureSick->pokeCount = 1;
    cureSick->sickKind = BTL_SICK_MOVE_LOCK;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSick);
    work->active = 0;
    HAND_WAZA_RemoveMoveHandlerById(pokeId, BTL_EVENT_GetFactorKey(factor));
}









/*
 * Rollout and Ice Ball, base power event: the power doubles with every hit
 * already made and once more when Defense Curl was used; the factor ends
 * after the last hit.
 */
void HAND_WAZA_RolloutScalePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work)
{
    struct BtlPokeParam *poke;
    u32 i;
    int ratio;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        ratio = 1;
        for (i = 0; i < work->count; i++)
            ratio <<= 1;
        if (BTL_POKEPARAM_TestContFlag(poke, BTL_CONT_FLAG_DEFENSE_CURL))
            ratio <<= 1;
        HAND_COMMON_EventScaleDamage(ratio);
        work->count++;
        if ((int)work->count >= work->limit)
            HAND_WAZA_RemoveMoveHandlerById(pokeId, BTL_EVENT_GetFactorKey(factor));
    }
}









/* Triple Kick handler table getter: two handlers. */
BtlEventHandler *HAND_WAZA_TripleKickGetHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gTripleKickHandlers;
}







/* Triple Kick, base power event: ten times the number of the hit. */
void HAND_WAZA_TripleKickRaisePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, HandWazaWork *work)
{
    int hitNumber;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        hitNumber = work->count + 1;
        work->count = hitNumber;
        BTL_EVENT_OverwriteVar(BTL_EVAR_BASE_POWER, hitNumber * 10);
    }
}






/* 021E278C  Triple Kick, multi-hit count event: check accuracy for every hit */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl BTL_EVENT_GetVar; cmp r4, r0; bne loc_021E27A2; movs r0, #0x42; movs r1, #1; bl BTL_EVENT_OverwriteVar; pop {r4, pc}.
 */
void HAND_WAZA_TripleKickCheckEachHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_CHECK_EACH_HIT_FLAG, 1);
}





/* Gyro Ball handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_GyroBallGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gGyroBallHandlers;
}





/* Gyro Ball, base power event: 25 times the target speed over the user speed, plus one, at most 150. */
void HAND_WAZA_GyroBallCalcPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *userPoke;
    struct BtlPokeParam *targetPoke;
    int userSpeed;
    int targetSpeed;
    u32 power;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        userPoke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        targetPoke = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID));
        userSpeed = BTL_SERVER_FLOW_CalcPokeSpeedWrapper(flow, userPoke, 0);
        targetSpeed = BTL_SERVER_FLOW_CalcPokeSpeedWrapper(flow, targetPoke, 0);
        power = targetSpeed * 25 / userSpeed + 1;
        if (power > 0x96)
            power = 0x96;
        BTL_EVENT_OverwriteVar(BTL_EVAR_BASE_POWER, power);
    }
}





/* Revenge and Avalanche handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_RevengeGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRevengeHandlers;
}




/*
 * Revenge and Avalanche, base power event: the power doubles when the target
 * damaged the user earlier this turn.
 */
void HAND_WAZA_RevengeDoublePowerOnHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *poke;
    u8 targetId;
    u8 hitIndex;
    struct BtlHitRecord hit;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        hitIndex = 0;
        while (BTL_POKEPARAM_GetHitRecord(poke, 0, hitIndex++, &hit) != 0) {
            if (hit.attackerId == targetId && hit.damage != 0) {
                HAND_COMMON_EventScaleDamage(2);
                return;
            }
        }
    }
}




/* Flail and Reversal handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_FlailGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gFlailHandlers;
}




/* Flail and Reversal, base power event: the lower the HP ratio (in 48ths), the higher the power. */
void HAND_WAZA_FlailCalcPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *poke;
    int hp;
    int maxHp;
    u32 hpRatio;
    u32 rowIndex;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        hp = BTL_POKEPARAM_GetValue(poke, BTL_VALUE_HP);
        maxHp = BTL_POKEPARAM_GetValue(poke, BTL_VALUE_MAX_HP);
        hpRatio = hp * 0x30 / maxHp;
        if (hpRatio == 0)
            hpRatio = 1;
        for (rowIndex = 0; rowIndex < 5; rowIndex++) {
            if (hpRatio <= gFlailPowerTable[rowIndex].maxRatio)
                break;
        }
        BTL_EVENT_OverwriteVar(BTL_EVAR_BASE_POWER, gFlailPowerTable[rowIndex].power);
    }
}




/* Facade handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_FacadeGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gFacadeHandlers;
}




/* Facade, power ratio event: the power doubles when the user is burned, poisoned or paralyzed. */
void HAND_WAZA_FacadeDoublePowerOnStatus(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    int majorStatus;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        majorStatus = BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId));
        if (majorStatus == BTL_MAJOR_STATUS_POISON || majorStatus == BTL_MAJOR_STATUS_PARALYSIS || majorStatus == BTL_MAJOR_STATUS_BURN)
            BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_2_0);
    }
}




/* Payback handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_PaybackGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gPaybackHandlers;
}



/* Payback, base power event: the power doubles when the target has already moved this turn. */
void HAND_WAZA_PaybackDoublePowerIfTargetMoved(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_TestTurnFlag(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)), BTL_TURN_FLAG_MOVED))
            HAND_COMMON_EventScaleDamage(2);
    }
}



/* Eruption and Water Spout handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_EruptionGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gEruptionHandlers;
}



/* Eruption and Water Spout: the power falls with the user's remaining HP. */
void HAND_WAZA_EruptionOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *user;
    u32 hp;
    u32 maxHp;
    u32 power;
    u32 basePower;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        hp = BTL_POKEPARAM_GetValue(user, BTL_VALUE_HP);
        maxHp = BTL_POKEPARAM_GetValue(user, BTL_VALUE_MAX_HP);
        basePower = WAZA_TOOL_GetPower(BTL_EVENT_GetFactorKey(factor));
        power = basePower * hp / maxHp;
        if (power == 0)
            power = 1;
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
    }
}



/* Wring Out and Crush Grip. */
BtlEventHandler *HAND_WAZA_AddWringOut(int *handlerCount)
{
    *handlerCount = 1;
    return gWringOutHandlers;
}



/* Wring Out and Crush Grip: 120 power at full HP of the target, scaled by its HP ratio. */
void HAND_WAZA_WringOutOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u32 power;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        power = BTL_CALC_MulRatioMin1(0x78, BTL_POKEPARAM_GetHpRatioFixed(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)))) / 100;
        if (power == 0)
            power = 1;
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
    }
}



/* Brine. */
BtlEventHandler *HAND_WAZA_AddBrine(int *handlerCount)
{
    *handlerCount = 1;
    return gBrineHandlers;
}



/* Brine: double power when the target is at half HP or less. */
void HAND_WAZA_BrineOnPowerRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_GetHpRatioFixed(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))) <= 0x32 << 12)
            BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, 4 << 11);
    }
}



/* Return. */
BtlEventHandler *HAND_WAZA_AddReturn(int *handlerCount)
{
    *handlerCount = 1;
    return gReturnHandlers;
}



/* Return: power is the user's friendship times 10 over 25. */
void HAND_WAZA_ReturnOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u32 power;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        power = (u32)(POKE_TOOL_GetPartyValue(BTL_POKEPARAM_GetMon(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)), 9, 0) * 10) / 25;
        if (power == 0)
            power = 1;
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
    }
}



/* Frustration. */
BtlEventHandler *HAND_WAZA_AddFrustration(int *handlerCount)
{
    *handlerCount = 1;
    return gFrustrationHandlers;
}



/* Frustration: power is the user's unhappiness, 255 minus friendship, times 10 over 25. */
void HAND_WAZA_FrustrationOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u32 power;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        power = (u32)((0xff - POKE_TOOL_GetPartyValue(BTL_POKEPARAM_GetMon(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)), 9, 0)) * 10) / 25;
        if (power == 0)
            power = 1;
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
    }
}



/* Wake-Up Slap. */
BtlEventHandler *HAND_WAZA_AddWakeUpSlap(int *handlerCount)
{
    *handlerCount = 2;
    return gWakeUpSlapHandlers;
}



/* Wake-Up Slap: double power against a sleeping target without a substitute. */
void HAND_WAZA_WakeUpSlapOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *target;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        target = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID));
        if (BTL_POKEPARAM_HasSubstitute(target) == 0) {
            if (BTL_POKEPARAM_HasSick(target, BTL_SICK_SLEEP) != 0)
                HAND_COMMON_EventScaleDamage(2);
        }
    }
}



/* Wake-Up Slap: wake the target after the hit. */
void HAND_WAZA_WakeUpSlapOnDamageEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    HandExCureSick *cure;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DAMAGED_ID);
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, targetId), BTL_SICK_SLEEP) != 0) {
            cure = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
            cure->pokeIds[0] = targetId;
            cure->pokeCount = 1;
            cure->sickKind = BTL_SICK_SLEEP;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cure);
        }
    }
}



/* Smelling Salt. */
BtlEventHandler *HAND_WAZA_AddSmellingSalt(int *handlerCount)
{
    *handlerCount = 2;
    return gSmellingSaltHandlers;
}



/* Smelling Salt: double power against a paralyzed target without a substitute. */
void HAND_WAZA_SmellingSaltOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *target;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        target = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID));
        if (BTL_POKEPARAM_HasSubstitute(target) == 0) {
            if (BTL_POKEPARAM_HasSick(target, BTL_SICK_PARALYSIS) != 0)
                HAND_COMMON_EventScaleDamage(2);
        }
    }
}



/* Smelling Salt: cure the target's paralysis after the hit. */
void HAND_WAZA_SmellingSaltOnDamageEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    HandExCureSick *cure;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DAMAGED_ID);
        if (targetId != BTL_EVENT_NO_POKE) {
            if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, targetId), BTL_SICK_PARALYSIS) != 0) {
                cure = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
                cure->pokeIds[0] = targetId;
                cure->pokeCount = 1;
                cure->sickKind = BTL_SICK_PARALYSIS;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cure);
            }
        }
    }
}



/* Present. */
BtlEventHandler *HAND_WAZA_AddPresent(int *handlerCount)
{
    *handlerCount = 3;
    return gPresentHandlers;
}



/* Present: a one in five chance that the move heals instead of damaging. */
void HAND_WAZA_PresentOnVariantDecide(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_CALC_RollPercent(0x14) != 0)
            *work = BTL_EVENT_OverwriteVar(BTL_EVAR_HANDLED_FLAG, 1);
        BTL_SERVER_FLOW_SetCurTurnStateFlag(flow, (u8)(*work != 0));
    }
}



/* Present: heal a quarter of the target's HP, or show the failure message at full HP. */
void HAND_WAZA_PresentOnHealEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    HandExRecoverHp *heal;
    HandExMessage *message;
    struct BtlPokeParam *target;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && *work != 0) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        if (BTL_POKEPARAM_IsHpFull(target) == 0) {
            heal = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RECOVER_HP, pokeId);
            heal->pokeId = targetId;
            heal->amount = BTL_CALC_DivideMaxHpMin1(target, 4);
            BTL_SERVER_FLOW_InitMsgRecord(&heal->message, HANDEX_STR_SET, 0x183);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&heal->message), targetId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, heal);
        } else {
            message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&message->message, HANDEX_STR_SET, 0xd2);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&message->message), targetId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
        }
    }
}



/* Present: random power, 40 on the low rolls, 120 on the high rolls, 80 otherwise. */
void HAND_WAZA_PresentOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    int power;
    u32 roll;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        power = 0x50;
        roll = BTL_CALC_Random(0x50);
        if (roll < 0x28)
            power = 0x28;
        else if (roll >= 0x46)
            power = 0x78;
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
    }
}



/* Trump Card. */
BtlEventHandler *HAND_WAZA_AddTrumpCard(int *handlerCount)
{
    *handlerCount = 1;
    return gTrumpCardHandlers;
}



/* Trump Card: power from the PP left in the move. */
void HAND_WAZA_TrumpCardOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *user;
    u32 pp;
    int slot;
    int power;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        slot = BTL_POKEPARAM_FindMoveSlot(user, BTL_EVENT_GetFactorKey(factor));
        if (slot != BTL_MOVE_SLOT_NONE) {
            pp = (u8)(int)BTL_POKEPARAM_GetMovePPChecked(user, (int)slot);
            if (pp >= 5)
                pp = 4;
            power = gTrumpCardPowerByPp[pp];
        } else {
            power = 0x28;
        }
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
    }
}



/* Punishment. */
BtlEventHandler *HAND_WAZA_AddPunishment(int *handlerCount)
{
    *handlerCount = 1;
    return gPunishmentHandlers;
}



/* Punishment: 60 power plus 20 for every raised stat stage of the target, up to 200. */
void HAND_WAZA_PunishmentOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *target;
    u32 i;
    int rank;
    int raisedStages;
    u32 power;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        target = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID));
        raisedStages = 0;
        for (i = 0; i < 7; i++) {
            rank = BTL_POKEPARAM_GetValue(target, gPunishmentStatIds[i]);
            if (rank > 6)
                raisedStages += rank - 6;
        }
        power = raisedStages * 20 + 0x3c;
        if (power > PUNISHMENT_MAX_POWER)
            power = PUNISHMENT_MAX_POWER;
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
    }
}



/* Fury Cutter. */
BtlEventHandler *HAND_WAZA_AddFuryCutter(int *handlerCount)
{
    *handlerCount = 1;
    return gFuryCutterHandlers;
}



/* Fury Cutter: the power doubles with every consecutive use, up to 160. */
void HAND_WAZA_FuryCutterOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *user;
    u32 power;
    u32 streak;
    u32 i;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_GetLastUsedMoveId(user) == BTL_EVENT_GetFactorKey(factor)) {
            power = BTL_EVENT_GetVar(BTL_EVAR_WAZA_POWER);
            streak = BTL_POKEPARAM_GetMoveStreak(user);
            for (i = 0; i < streak; i++) {
                power <<= 1;
                if (power > FURY_CUTTER_MAX_POWER) {
                    power = FURY_CUTTER_MAX_POWER;
                    break;
                }
            }
            BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
        }
    }
}



/* Assurance. */
BtlEventHandler *HAND_WAZA_AddAssurance(int *handlerCount)
{
    *handlerCount = 1;
    return gAssuranceHandlers;
}



/* Assurance: double power when the target already took damage this turn. */
void HAND_WAZA_AssuranceOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_TestTurnFlag(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)), BTL_TURN_FLAG_DAMAGED) != 0)
            HAND_COMMON_EventScaleDamage(2);
    }
}



/* Low Kick and Grass Knot. */
BtlEventHandler *HAND_WAZA_AddLowKick(int *handlerCount)
{
    *handlerCount = 1;
    return gLowKickHandlers;
}



/* Low Kick and Grass Knot: power from the weight of the target (in tenths of a kilogram). */
void HAND_WAZA_LowKickOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u32 weight;
    int power;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        weight = BTL_SERVER_FLOW_CalcPokeWeight(flow, BTL_POKEPARAM_GetPokeId(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))));
        if (weight >= 2000) {
            power = 0x78;
        } else if (weight >= 1000) {
            power = 100;
        } else if (weight >= 500) {
            power = 80;
        } else if (weight >= 250) {
            power = 60;
        } else {
            power = 40;
            if (weight < 100)
                power = 20;
        }
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
    }
}



/* Weather Ball. */
BtlEventHandler *HAND_WAZA_AddWeatherBall(int *handlerCount)
{
    *handlerCount = 2;
    return gWeatherBallHandlers;
}



/* Weather Ball: the type and the animation variant follow the weather. */
void HAND_WAZA_WeatherBallOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    int variant;
    int weather;
    u8 type;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        weather = BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow);
        type = BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
        variant = 0;
        switch (weather) {
        case BTL_WEATHER_SUN:
            type = POKETYPE_FIRE;
            variant = 1;
            break;
        case BTL_WEATHER_RAIN:
            type = POKETYPE_WATER;
            variant = 4;
            break;
        case BTL_WEATHER_SAND:
            type = POKETYPE_ROCK;
            variant = 3;
            break;
        case BTL_WEATHER_HAIL:
            type = POKETYPE_ICE;
            variant = 2;
            break;
        }
        BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_TYPE, type);
        BTL_SERVER_FLOW_SetCurTurnStateFlag(flow, variant);
    }
}



/* Weather Ball: double power in any weather. */
void HAND_WAZA_WeatherBallOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, BTL_EVENT_GetVar(BTL_EVAR_WAZA_POWER) * 2);
    }
}



/* Gust and Twister. */
BtlEventHandler *HAND_WAZA_AddGust(int *handlerCount)
{
    *handlerCount = 2;
    return gGustHandlers;
}



/* Gust and Twister: they can hit a target that flies high (Fly, Bounce). */
void HAND_WAZA_GustOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_HIDE_KIND) == BTL_CONT_FLAG_FLYING)
            BTL_EVENT_OverwriteVar(BTL_EVAR_AVOID_FLAG, 0);
    }
}



/* Gust and Twister: double damage against a target that flies high. */
void HAND_WAZA_GustOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)), BTL_CONT_FLAG_FLYING) != 0)
            HAND_COMMON_EventScaleDamage(2);
    }
}



/* Sky Uppercut. */
BtlEventHandler *HAND_WAZA_AddSkyUppercut(int *handlerCount)
{
    *handlerCount = 1;
    return gSkyUppercutHandlers;
}



/* Sky Uppercut: it can hit a target that flies high (Fly, Bounce). */
void HAND_WAZA_SkyUppercutOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_HIDE_KIND) == BTL_CONT_FLAG_FLYING)
            BTL_EVENT_OverwriteVar(BTL_EVAR_AVOID_FLAG, 0);
    }
}



/* Thunder and Hurricane. */
BtlEventHandler *HAND_WAZA_AddThunder(int *handlerCount)
{
    *handlerCount = 3;
    return gThunderHandlers;
}



/* Thunder and Hurricane: they can hit a target that flies high. */
void HAND_WAZA_ThunderOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_HIDE_KIND) == BTL_CONT_FLAG_FLYING)
            BTL_EVENT_OverwriteVar(BTL_EVAR_AVOID_FLAG, 0);
    }
}



/* Thunder and Hurricane: they never miss in rain. */
void HAND_WAZA_ThunderOnHitCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_RAIN)
            BTL_EVENT_OverwriteVar(BTL_EVAR_HANDLED_FLAG, 1);
    }
}



/* Thunder and Hurricane: the accuracy falls to 50 in harsh sunlight. */
void HAND_WAZA_ThunderOnAccuracyCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_SUN)
            BTL_EVENT_OverwriteVar(BTL_EVAR_ACCURACY, 0x32);
    }
}



/* Blizzard. */
BtlEventHandler *HAND_WAZA_AddBlizzard(int *handlerCount)
{
    *handlerCount = 1;
    return gBlizzardHandlers;
}



/* Blizzard: it never misses in hail. */
void HAND_WAZA_BlizzardOnHitCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_HAIL)
            BTL_EVENT_OverwriteVar(BTL_EVAR_HANDLED_FLAG, 1);
    }
}



/* Earthquake. */
BtlEventHandler *HAND_WAZA_AddEarthquake(int *handlerCount)
{
    *handlerCount = 2;
    return gEarthquakeHandlers;
}



/* Earthquake and Magnitude: they can hit a target that is underground (Dig). */
void HAND_WAZA_EarthquakeOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_HIDE_KIND) == BTL_CONT_FLAG_DIGGING)
            BTL_EVENT_OverwriteVar(BTL_EVAR_AVOID_FLAG, 0);
    }
}



/* Earthquake and Magnitude: double damage against a target that is underground. */
void HAND_WAZA_EarthquakeOnDamageRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)), BTL_CONT_FLAG_DIGGING) != 0)
            BTL_EVENT_MultiplyVar(BTL_EVAR_DAMAGE_RATIO, BTL_RATIO_DOUBLE);
    }
}



/* Judgment. */
BtlEventHandler *HAND_WAZA_AddJudgment(int *handlerCount)
{
    *handlerCount = 1;
    return gJudgmentHandlers;
}



/* Judgment: the type follows the plate that the user holds. */
void HAND_WAZA_JudgmentOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_SERVER_FLOW_CanUseHeldItem(flow, pokeId) != 0) {
            u16 itemId = (u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId));
            int type = POKETYPE_NORMAL;
            switch (itemId) {
            case ITEM_FLAME_PLATE: type = POKETYPE_FIRE; break;
            case ITEM_SPLASH_PLATE: type = POKETYPE_WATER; break;
            case ITEM_ZAP_PLATE: type = POKETYPE_ELECTRIC; break;
            case ITEM_MEADOW_PLATE: type = POKETYPE_GRASS; break;
            case ITEM_ICICLE_PLATE: type = POKETYPE_ICE; break;
            case ITEM_FIST_PLATE: type = POKETYPE_FIGHTING; break;
            case ITEM_TOXIC_PLATE: type = POKETYPE_POISON; break;
            case ITEM_EARTH_PLATE: type = POKETYPE_GROUND; break;
            case ITEM_SKY_PLATE: type = POKETYPE_FLYING; break;
            case ITEM_MIND_PLATE: type = POKETYPE_PSYCHIC; break;
            case ITEM_INSECT_PLATE: type = POKETYPE_BUG; break;
            case ITEM_STONE_PLATE: type = POKETYPE_ROCK; break;
            case ITEM_SPOOKY_PLATE: type = POKETYPE_GHOST; break;
            case ITEM_DRACO_PLATE: type = POKETYPE_DRAGON; break;
            case ITEM_DREAD_PLATE: type = POKETYPE_DARK; break;
            case ITEM_IRON_PLATE: type = POKETYPE_STEEL; break;
            }
            BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_TYPE, type);
        }
    }
}



/* Techno Blast. */
BtlEventHandler *HAND_WAZA_AddTechnoBlast(int *handlerCount)
{
    *handlerCount = 1;
    return gTechnoBlastHandlers;
}



/* Techno Blast: the type and the animation variant follow the drive that the user holds. */
void HAND_WAZA_TechnoBlastOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_SERVER_FLOW_CanUseHeldItem(flow, pokeId) != 0) {
            u16 itemId = (u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId));
            int type = POKETYPE_NORMAL;
            int variant = 0;
            switch (itemId) {
            case ITEM_DOUSE_DRIVE: type = POKETYPE_WATER; variant = 1; break;
            case ITEM_SHOCK_DRIVE: type = POKETYPE_ELECTRIC; variant = 2; break;
            case ITEM_BURN_DRIVE: type = POKETYPE_FIRE; variant = 3; break;
            case ITEM_CHILL_DRIVE: type = POKETYPE_ICE; variant = 4; break;
            }
            BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_TYPE, type);
            BTL_SERVER_FLOW_SetCurTurnStateFlag(flow, variant);
        }
    }
}



/* Hidden Power. */
BtlEventHandler *HAND_WAZA_AddHiddenPower(int *handlerCount)
{
    *handlerCount = 2;
    return gHiddenPowerHandlers;
}



/* Hidden Power: the type comes from the user's individual values. */
void HAND_WAZA_HiddenPowerOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_TYPE, POKE_TOOL_GetHiddenPowerType(BTL_POKEPARAM_GetMon(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))));
}



/* Hidden Power: the power comes from the user's individual values. */
void HAND_WAZA_HiddenPowerOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, POKE_TOOL_GetHiddenPowerPower(BTL_POKEPARAM_GetMon(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))));
}



/* Natural Gift. */
BtlEventHandler *HAND_WAZA_AddNaturalGift(int *handlerCount)
{
    *handlerCount = 4;
    return gNaturalGiftHandlers;
}



/* Natural Gift: it fails when the user cannot use its item or the item has no Natural Gift power. */
void HAND_WAZA_NaturalGiftOnExecuteCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u16 itemId;
    int paramId;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_SERVER_FLOW_CanUseHeldItem(flow, pokeId) == 0) {
            BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
            return;
        }
        itemId = (u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId));
        paramId = ITEM_PARAM_NATURAL_GIFT_POWER;
        BTL_CALC_GetItemParam(itemId, paramId);
        if (itemId == 0 || BTL_CALC_GetItemParam(itemId, paramId) == 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
    }
}



/* Natural Gift: the type comes from the item. */
void HAND_WAZA_NaturalGiftOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_TYPE, BTL_CALC_GetItemParam((u32)(u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)), ITEM_PARAM_NATURAL_GIFT_TYPE));
}



/* Natural Gift: the power comes from the item. */
void HAND_WAZA_NaturalGiftOnWazaPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, BTL_CALC_GetItemParam((u32)(u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)), ITEM_PARAM_NATURAL_GIFT_POWER));
}



/* Natural Gift: the item is used up after the move. */
void HAND_WAZA_NaturalGiftOnWazaFinish(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HandExItemMessage *consume;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        consume = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ITEM_MESSAGE, pokeId);
        consume->consumeItem = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, consume);
    }
}



/* Knock Off. */
BtlEventHandler *HAND_WAZA_AddKnockOff(int *handlerCount)
{
    *handlerCount = 1;
    return gKnockOffHandlers;
}



/* Knock Off: remove the item that the target holds. */
void HAND_WAZA_KnockOffOnDamageEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    u16 itemId;
    HandExSetItem *setItem;
    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    targetId = (u8)BTL_EVENT_GetVar(BTL_EVAR_DAMAGED_ID);
    if (BTLV_CORE_CheckEitherSlotPair(flow, pokeId, targetId) != 0)
        return;
    itemId = (u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, targetId));
    if (itemId == 0)
        return;
    setItem = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_ITEM, pokeId);
    setItem->pokeId = targetId;
    setItem->itemId = 0;
    BTL_SERVER_FLOW_InitMsgRecord(&setItem->message, HANDEX_STR_SET, 0x41a);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&setItem->message), pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&setItem->message), targetId);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&setItem->message), itemId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, setItem);
}



/* Magic Coat. */
BtlEventHandler *HAND_WAZA_AddMagicCoat(int *handlerCount)
{
    *handlerCount = 5;
    return gMagicCoatHandlers;
}



/* Magic Coat: the user cannot use it when it is not allowed; moves of other Pokemon may be reflected. */
void HAND_WAZA_MagicCoatOnExecuteCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 userId = BTL_EVENT_GetVar(BTL_EVAR_POKE_ID);
    if (userId == pokeId) {
        if (HAND_COMMON_IsLastToAct(flow, pokeId) != 0) {
            BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
            return;
        }
    } else if (BTL_MAIN_IsPokeSamePair(pokeId, userId) == 0) {
        HAND_COMMON_EventRedirectMove(factor, flow, pokeId, (sptr)work);
    }
}



/* Magic Coat: announce the effect once when the user uses the move. */
void HAND_WAZA_MagicCoatOnWazaExecute(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HandExMessage *message;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && work[WAZA_WORK_ANNOUNCED] == 0) {
        message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&message->message, HANDEX_STR_SET, 761);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&message->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
        work[WAZA_WORK_ANNOUNCED] = 1;
    }
}



/* Magic Coat: reflect the move back at its user. */
void HAND_WAZA_MagicCoatOnWazaCounter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_COMMON_EventCounterMove(factor, flow, pokeId, (sptr)work);
}



/* Magic Coat: the first bounce of the turn queues the move notice. */
void HAND_WAZA_MagicCoatOnWazaNotice(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_EVENT_OverwriteVar(BTL_EVAR_HANDLED_FLAG, 1) != 0)
            HAND_COMMON_EventQueueMoveNotice(factor, flow, pokeId, (sptr)work);
    }
}



/* Magic Coat: the effect ends with the turn. */
void HAND_WAZA_MagicCoatOnTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_RemoveFactor(factor);
}



/* Snatch. */
BtlEventHandler *HAND_WAZA_AddSnatch(int *handlerCount)
{
    *handlerCount = 4;
    return gSnatchHandlers;
}



/* Snatch: announce the effect when the user uses the move. */
void HAND_WAZA_SnatchOnWazaExecute(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HandExMessage *message;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && HAND_COMMON_IsLastToAct(flow, pokeId) == 0) {
        message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&message->message, HANDEX_STR_SET, 751);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&message->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
        work[WAZA_WORK_ANNOUNCED] = 1;
    }
}



/* Snatch: take over a stealable move that another Pokemon is about to use. */
void HAND_WAZA_SnatchOnSnatchCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    if (attackerId != pokeId) {
        if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), WAZA_FLAG_SNATCH) != 0) {
            if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_SICK_SNATCH_BLOCK) == 0) {
                if (BTL_EVENT_OverwriteVar(BTL_EVAR_POKE_ID, pokeId) != 0) {
                    BTL_EVENT_OverwriteVar(BTL_EVAR_DEFENDER_ID, pokeId);
                    *work = 1;
                }
            }
        }
    }
}



/* Snatch: show the message that the move was snatched, then end the effect. */
void HAND_WAZA_SnatchOnSnatched(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HandExMessage *message;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *work != 0) {
        message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&message->message, HANDEX_STR_SET, 754);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&message->message), pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&message->message), BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
        BTL_EVENT_RemoveFactor(factor);
    }
}



/* Snatch: the effect ends with the turn. */
void HAND_WAZA_SnatchOnTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_RemoveFactor(factor);
}



/* Thief and Covet. */
BtlEventHandler *HAND_WAZA_AddThief(int *handlerCount)
{
    *handlerCount = 2;
    return gThiefHandlers;
}



/* Thief and Covet: remember whether the user already holds an item. */
void HAND_WAZA_ThiefOnWazaPrepare(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        *work = (BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) != 0) ? 1 : 0;
}



/* Thief and Covet: after the hit, take the item of the target when the user holds none. */
void HAND_WAZA_ThiefOnDamageEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    struct BtlPokeParam *target;
    HandExSwapItem *steal;
    HandExFlagRecord *flag;
    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    if (BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) != 0)
        return;
    if (*work != 0)
        return;
    targetId = BTL_EVENT_GetVar(BTL_EVAR_DAMAGED_ID);
    if (targetId == BTL_EVENT_NO_POKE)
        return;
    target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
    if (BTL_POKEPARAM_GetItem(target) == 0)
        return;
    if (BTLV_CORE_CheckEitherSlotPair(flow, pokeId, targetId) != 0)
        return;
    steal = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SWAP_ITEM, pokeId);
    steal->targetId = targetId;
    BTL_SERVER_FLOW_InitMsgRecord(&steal->swapMessage, HANDEX_STR_SET, 1057);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&steal->swapMessage), pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&steal->swapMessage), targetId);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&steal->swapMessage), BTL_POKEPARAM_GetItem(target));
    BTL_SERVER_FLOW_CommitCmdRecord(flow, steal);
    flag = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_FLAG_RECORD, pokeId);
    flag->header |= HANDEX_FLAG_ITEM_EVENT;
    flag->flag = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, flag);
}



/* Trick and Switcheroo. */
BtlEventHandler *HAND_WAZA_AddTrick(int *handlerCount)
{
    *handlerCount = 1;
    return gTrickHandlers;
}



/* Trick and Switcheroo: the user and the target exchange their held items. */
void HAND_WAZA_TrickOnWazaExecute(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    struct BtlPokeParam *user;
    struct BtlPokeParam *target;
    u16 userItem;
    u16 targetItem;
    int userSpecies;
    int targetSpecies;
    HandExSwapItem *swap;
    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    targetId = BTL_EVENT_GetVar(BTL_EVAR_DAMAGED_ID);
    if (BTLV_CORE_CheckPartySlotCondition(flow, pokeId) != 0)
        return;
    user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
    userItem = (int)BTL_POKEPARAM_GetItem(user);
    targetItem = (int)BTL_POKEPARAM_GetItem(target);
    if (userItem == 0 && targetItem == 0)
        return;
    userSpecies = BTL_POKEPARAM_GetSpecies(user);
    targetSpecies = BTL_POKEPARAM_GetSpecies(target);
    if (FILE_UTIL_IsMailItem(userItem) != 0)
        return;
    if (FILE_UTIL_IsMailItem(targetItem) != 0)
        return;
    if (HAND_COMMON_IsItemBoundToSpecies(userSpecies, targetItem) != 0)
        return;
    if (HAND_COMMON_IsItemBoundToSpecies(targetSpecies, userItem) != 0)
        return;
    if (HAND_COMMON_IsItemBoundToSpecies(userSpecies, userItem) != 0)
        return;
    if (HAND_COMMON_IsItemBoundToSpecies(targetSpecies, targetItem) != 0)
        return;
    swap = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SWAP_ITEM, pokeId);
    swap->targetId = targetId;
    BTL_SERVER_FLOW_InitMsgRecord(&swap->swapMessage, HANDEX_STR_SET, 682);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&swap->swapMessage), pokeId);
    if (targetItem != 0) {
        BTL_SERVER_FLOW_InitMsgRecord(&swap->userGetsMessage, HANDEX_STR_SET, 685);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&swap->userGetsMessage), pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&swap->userGetsMessage), targetItem);
    }
    if (userItem != 0) {
        BTL_SERVER_FLOW_InitMsgRecord(&swap->targetGetsMessage, HANDEX_STR_SET, 685);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&swap->targetGetsMessage), targetId);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&swap->targetGetsMessage), userItem);
    }
    BTL_SERVER_FLOW_CommitCmdRecord(flow, swap);
}



/* Magnitude. */
BtlEventHandler *HAND_WAZA_AddMagnitude(int *handlerCount)
{
    *handlerCount = 4;
    return gMagnitudeHandlers;
}



/* Magnitude: roll the magnitude, announce it and keep its power in the work word. */
void HAND_WAZA_MagnitudeOnWazaStart(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 row;
    u8 roll;
    HandExMessage *message;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        roll = BTL_CALC_Random(100);
        for (row = 0; row < MAGNITUDE_ROW_COUNT; row++) {
            if (roll < gMagnitudeRows[row].rollLimit)
                break;
        }
        *work = gMagnitudeRows[row].power;
        message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&message->message, HANDEX_STR_STANDARD, (u16)(row + 0x68));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
    }
}



/* Magnitude (move 222): event 0x37 of its table, whose other handler is in the previous unit.
   Defaults the magnitude level to 10 when none was chosen and publishes it. */
void HAND_WAZA_MagnitudeSetDefaultLevel(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *magnitudeLevel)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (*magnitudeLevel == 0)
            *magnitudeLevel = 10;
        BTL_EVENT_OverwriteVar(BTL_EVAR_MAGNITUDE, *magnitudeLevel);
    }
}



/* Surf (move 57): handler table, 2 rows. */
int *HAND_WAZA_GetSurfHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gSurfHandlers;
}



/* Surf, event 0x99: the move can hit a target that is diving. */
void HAND_WAZA_SurfHitDiving(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_TARGET_SEMI_INVULNERABLE) == BTL_SEMI_INVULNERABLE_DIVING)
            BTL_EVENT_OverwriteVar(BTL_EVAR_AVOID_BY_SEMI_INVULNERABLE, 0);
    }
}



/* Surf, event 0x47: doubles the damage against a target that is diving. */
void HAND_WAZA_SurfDoubleDamageVsDiving(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    int contFlag;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        /* 4 << 11 is 2.0 in the ratio format; the flag number is reused for the shift (register reuse of the original). */
        contFlag = BTL_CONT_FLAG_DIVING;
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)), BTL_CONT_FLAG_DIVING) != 0)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, contFlag << 11);
    }
}



/* Stomp (move 23) and Steamroller (move 537): handler table, 1 row. */
int *HAND_WAZA_GetStompHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gStompHandlers;
}



/* Stomp and Steamroller, event 0x47: doubles the damage against a minimized target. */
void HAND_WAZA_StompDoubleDamageVsMinimized(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    int contFlag;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        /* 8 << 10 is 2.0 in the ratio format. */
        contFlag = BTL_CONT_FLAG_MINIMIZED;
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)), BTL_CONT_FLAG_MINIMIZED) != 0)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, contFlag << 10);
    }
}



/* False Swipe (move 206): handler table, 1 row (its handler is the first function of the next unit). */
int *HAND_WAZA_GetFalseSwipeHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gFalseSwipeHandlers;
}



/* False Swipe (move 206), event 0x74: a lethal hit leaves the target with 1 HP (survive result 2). */
void HAND_WAZA_FalseSwipeLeaveOneHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_GENERIC_FLAG) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_SURVIVE_RESULT, 2);
    }
}



/* Endure (move 203): handler table, 6 rows. The first three handlers are shared with Protect. */
int *HAND_WAZA_GetEndureHandlers(int *handlerCount)
{
    *handlerCount = 6;
    return gEndureHandlers;
}



/* Endure, event 0xa0 (the move itself): shows the message, marks the user as braced and raises the streak. */
void HAND_WAZA_EndureBraceUp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, struct EndureWork *work)
{
    struct HandExMessage *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_MSG_KIND_SET, HAND_WAZA_STR_ENDURE_BRACED);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
        work->braced = 1;
        HAND_WAZA_ProtectIncrementStreak(flow, pokeId, 0);
    }
}



/* Endure, event 0x74: a lethal hit on the braced user leaves 1 HP (survive result 1). */
void HAND_WAZA_EndureSurviveAtOneHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, struct EndureWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (work->braced != 0) {
            if (BTL_EVENT_GetVar(BTL_EVAR_GENERIC_FLAG) != 0)
                BTL_EVENT_OverwriteVar(BTL_EVAR_SURVIVE_RESULT, 1);
        }
    }
}



/* Endure, event 0x76: the factor ends with the turn. */
void HAND_WAZA_EndureRemoveAtTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_RemoveFactor(factor);
}



/* Protect (move 182) and Detect (move 197): handler table, 4 rows. */
int *HAND_WAZA_GetProtectHandlers(int *handlerCount)
{
    *handlerCount = 4;
    return gProtectHandlers;
}



/* Protect, Detect and Endure, event 3: when the user last used a move outside the protect family, the streak restarts. */
void HAND_WAZA_ProtectResetStreakAfterOtherMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    unsigned i;
    int lastMoveId;
    struct HandExSetCounter *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        lastMoveId = BTL_POKEPARAM_GetLastUsedMoveId(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId));
        for (i = 0; i < 5; i++) {
            if (lastMoveId == gProtectMoveIds[i])
                return;
        }
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
        record->pokeId = pokeId;
        record->counterId = BTL_COUNTER_PROTECT_STREAK;
        record->value = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}



/* Protect, Detect, Endure, event 0x1f: fails the move on consecutive use (chance from gProtectFailRange)
   and when the user acts last of the turn. */
void HAND_WAZA_ProtectCheckSuccess(BTL_EVENT_SIGNATURE, int *work)
{
    unsigned streak;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        streak = BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_COUNTER_PROTECT_STREAK);
        if (streak != 0) {
            if (streak >= BTL_PROTECT_STREAK_MAX + 1)
                streak = BTL_PROTECT_STREAK_MAX;
            if (BTL_CALC_Random(gProtectFailRange[streak]) != 0) {
                BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_GENERIC);
                return;
            }
        }
        if (HAND_COMMON_IsLastToAct(flow, pokeId) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_GENERIC);
    }
}



/* Protect, Detect, Endure, event 0x21 (the move failed): the streak restarts and the factor ends. */
void HAND_WAZA_ProtectResetStreakOnFail(BTL_EVENT_SIGNATURE, int *work)
{
    struct HandExSetCounter *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
        record->pokeId = pokeId;
        record->counterId = BTL_COUNTER_PROTECT_STREAK;
        record->value = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
        BTL_EVENT_RemoveFactor(factor);
    }
}



/* Protect and Detect, event 0xa0 (the move itself): sets the protected turn flag, raises the streak, shows the message. */
void HAND_WAZA_ProtectActivate(BTL_EVENT_SIGNATURE, int *work)
{
    struct HandExTurnFlag *turnFlag;
    struct HandExMessage *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        BTL_SERVER_FLOW_GetPokeParam(flow, pokeId); /* the original discards this lookup */
        turnFlag = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_TURN_FLAG, pokeId);
        turnFlag->pokeId = pokeId;
        turnFlag->flag = BTL_TURN_FLAG_PROTECTED;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, turnFlag);
        HAND_WAZA_ProtectIncrementStreak(flow, pokeId, 0);
        message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&message->message, BTL_MSG_KIND_SET, HAND_WAZA_STR_PROTECT);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&message->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
    }
}



/* Raises the Protect streak counter of the Pokemon by one; silent goes into header flag bit 24. */
void HAND_WAZA_ProtectIncrementStreak(struct BtlServerFlow *flow, int pokeId, int silent)
{
    struct BtlPokeParam *bpp;
    struct HandExSetCounter *record;

    bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
    record->value = BTL_POKEPARAM_GetCounter(bpp, BTL_COUNTER_PROTECT_STREAK) + 1;
    record->pokeId = pokeId;
    record->counterId = BTL_COUNTER_PROTECT_STREAK;
    record->header = (record->header & ~HANDEX_FLAG_SILENT) | ((silent & 1) << 24);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
}



/* Bide (move 117): handler table, 7 rows. */
int *HAND_WAZA_GetBideHandlers(int *handlerCount)
{
    *handlerCount = 7;
    return gBideHandlers;
}



/* Bide, event 0x24: turn by turn. Phase 0 starts the storing status, phase 1 keeps storing, later phases release. */
void HAND_WAZA_BideAdvanceTurn(BTL_EVENT_SIGNATURE, struct BideWork *work)
{
    struct HandExAddSick *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        switch (work->phase) {
        case 0:
            record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            record->sickKind = BTL_SICK_BIDE;
            record->sickCont = BTL_SICKCONT_MakeKind1Value(BTL_EVENT_GetFactorKey(factor));
            record->pokeId = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
            BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_PHASE, 2);
            work->storing = 1;
            work->phase = 1;
            work->storedDamage = 0;
            break;
        case 1:
            BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_PHASE, 2);
            work->phase = 2;
            break;
        case 2:
        default:
            BTL_SERVER_FLOW_SetCurTurnStateFlag(flow, 1);
            HAND_WAZA_BideCureStoringState(flow, pokeId, work);
            break;
        }
    }
}



/* Bide, event 0x19: chooses the "storing energy" message of the first two turns. */
void HAND_WAZA_BideSelectMessage(BTL_EVENT_SIGNATURE, struct BideWork *work)
{
    BtlStrParam *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        message = (BtlStrParam *)BTL_EVENT_GetVar(BTL_EVAR_MESSAGE);
        switch (work->phase) {
        case 1:
            BTL_SERVER_FLOW_InitMsgRecord(message, BTL_MSG_KIND_SET, HAND_WAZA_STR_BIDE_STORING);
            BTL_SERVER_FLOW_AppendMsgRecordArg(message, pokeId);
            BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1);
            break;
        case 2:
            BTL_SERVER_FLOW_InitMsgRecord(message, BTL_MSG_KIND_SET, HAND_WAZA_STR_BIDE_STORING_MORE);
            BTL_SERVER_FLOW_AppendMsgRecordArg(message, pokeId);
            BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1);
            break;
        }
    }
}



/* Bide, event 0x1f: on release the move fails when no damage was stored or nobody hit the user. */
void HAND_WAZA_BideCheckStoredDamage(BTL_EVENT_SIGNATURE, struct BideWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (work->phase >= 2) {
            if (work->storedDamage == 0)
                BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_GENERIC);
            else if (work->targetId == BTL_POKEID_NONE)
                BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_GENERIC);
            work->phase = 3;
        }
    }
}



/* Bide, event 0x29: on release the target is the Pokemon that hit the user last. */
void HAND_WAZA_BideDecideTarget(BTL_EVENT_SIGNATURE, struct BideWork *work)
{
    int targetId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (work->phase >= 2) {
            targetId = HAND_WAZA_BideFindTarget(factor, flow, pokeId, work);
            work->targetId = targetId;
            BTL_EVENT_OverwriteVar(BTL_EVAR_DEFENDER_ID, targetId);
        }
    }
}



/* Bide, event 0x4b: while storing, adds the damage the user takes (not into a substitute). */
void HAND_WAZA_BideStoreDamage(BTL_EVENT_SIGNATURE, struct BideWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE) == 0) {
            if (work->storing != 0)
                work->storedDamage += BTL_EVENT_GetVar(BTL_EVAR_DAMAGE);
        }
    }
}



/* Bide, event 0x46: on release the damage is twice the stored damage. */
void HAND_WAZA_BideDoubleStoredDamage(BTL_EVENT_SIGNATURE, struct BideWork *work)
{
    int damage;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (work->phase >= 2) {
            BTL_SERVER_FLOW_GetPokeParam(flow, pokeId); /* the original discards this lookup */
            damage = work->storedDamage;
            if (damage != 0)
                damage *= 2;
            BTL_EVENT_OverwriteVar(BTL_EVAR_FIXED_DAMAGE, damage);
            work->phase = 3;
        }
    }
}



/* Bide, event 0x21 (the move failed): ends the storing status. */
void HAND_WAZA_BideEndOnFail(BTL_EVENT_SIGNATURE, struct BideWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        HAND_WAZA_BideCureStoringState(flow, pokeId, work);
}



/* Bide: finds the Pokemon to hit on release. It is the attacker of the first hit recorded in the last three turns;
   when that Pokemon has left its position, a random opponent is taken. Returns 0x1F when nothing hit the user. */
int HAND_WAZA_BideFindTarget(BTL_EVENT_SIGNATURE, struct BideWork *work)
{
    u8 scratch[16]; /* hit record at +6 (attacker id at +0xB), later the list of candidate ids */
    struct BtlPokeParam *bpp;
    unsigned turnAgo;
    int attackerId;
    int side;
    int candidateCount;

    bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    for (turnAgo = 0; turnAgo < 3; turnAgo++) {
        if (BTL_POKEPARAM_GetHitCount(bpp, (u8)turnAgo) != 0) {
            BTL_POKEPARAM_GetHitRecord(bpp, (u8)turnAgo, (int)0, (struct BtlHitRecord *)(&scratch[6]));
            attackerId = scratch[0xb];
            if (BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, attackerId) == BTL_SLOT_NONE) {
                side = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
                candidateCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(0x100 | side), scratch);
                if (candidateCount != 0)
                    attackerId = scratch[(u8)BTL_CALC_Random(candidateCount)];
                else
                    attackerId = BTL_POKEID_NONE;
            }
            return attackerId;
        }
    }
    return BTL_POKEID_NONE;
}



/* Bide: when the storing status is on, cures it and clears the flag. */
void HAND_WAZA_BideCureStoringState(struct BtlServerFlow *flow, int pokeId, struct BideWork *work)
{
    struct HandExCureSick *record;

    if (work->storing != 0) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
        record->sickKind = BTL_SICK_BIDE;
        record->pokeCount = 1;
        record->pokeIds[0] = pokeId;
        record->suppressMessage = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
        work->storing = 0;
    }
}



/* Recycle (move 278): handler table, 1 row. */
int *HAND_WAZA_GetRecycleHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRecycleHandlers;
}



/* Recycle, event 0xa0: if the user holds nothing and consumed an item, gives it back with a message. */
void HAND_WAZA_RecycleRestoreItem(BTL_EVENT_SIGNATURE)
{
    struct BtlPokeParam *bpp;
    int consumedItem;
    struct HandExSetItem *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_GetItem(bpp) == 0) {
            consumedItem = BTL_POKEPARAM_GetConsumedItem(bpp);
            if (consumedItem != 0) {
                record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_ITEM, pokeId);
                record->itemId = consumedItem;
                record->pokeId = pokeId;
                record->announce = 1;
                BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_MSG_KIND_SET, HAND_WAZA_STR_RECYCLE);
                BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), pokeId);
                BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), consumedItem);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
            }
        }
    }
}



/* Psycho Shift (move 375): handler table, 1 row. */
int *HAND_WAZA_GetPsychoShiftHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gPsychoShiftHandlers;
}



/* Psycho Shift, event 0xa0: moves the major status of the user to a target that has none. */
void HAND_WAZA_PsychoShiftTransferStatus(BTL_EVENT_SIGNATURE)
{
    struct BtlPokeParam *userBpp;
    int sickKind;
    u8 targetId;
    union SickCont sickCont;
    union SickCont newCont;
    struct HandExAddSick *addSick;
    struct HandExCureSick *cureSick;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        userBpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        sickKind = BTL_POKEPARAM_GetMajorStatusIndex(userBpp);
        if (sickKind != 0) {
            targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST);
            if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(flow, targetId)) == 0) {
                sickCont = BTL_POKEPARAM_GetSickContRaw(userBpp, sickKind);
                addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
                addSick->sickKind = sickKind;
                if (sickKind == BTL_SICK_POISON && BTL_SICKCONT_IsKind1Index15(sickCont) != 0)
                    newCont = BTL_SICKCONT_MakeKind1Index15();
                else
                    newCont = BTL_CALC_MakeDefaultSickCont(sickKind);
                addSick->sickCont = newCont;
                addSick->pokeId = targetId;
                addSick->suppressMessage = 1;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
                cureSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
                cureSick->sickKind = sickKind;
                cureSick->pokeCount = 1;
                cureSick->pokeIds[0] = pokeId;
                cureSick->header |= HANDEX_FLAG_SILENT;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSick);
                BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 0);
            }
        }
    }
}



/* Pain Split (move 220): handler table, 1 row. */
int *HAND_WAZA_GetPainSplitHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gPainSplitHandlers;
}



/* Pain Split, event 0xa0: both Pokemon end with the average of their current HP. */
void HAND_WAZA_PainSplitAverageHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *userBpp;
    struct BtlPokeParam *targetBpp;
    u32 userHp;
    u32 targetHp;
    u32 averageHp;
    struct HandExChangeHp *changeHp;
    struct HandExMessage *message;
    struct HandExRefreshHpGauge *gauge;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST);
    userBpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    targetBpp = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
    userHp = BTL_POKEPARAM_GetValue(userBpp, BPP_VALUE_HP);
    targetHp = BTL_POKEPARAM_GetValue(targetBpp, BPP_VALUE_HP);
    averageHp = (userHp + targetHp) / 2;
    changeHp = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CHANGE_HP, pokeId);
    changeHp->pokeCount = 2;
    changeHp->pokeIds[0] = pokeId;
    changeHp->amounts[0] = averageHp - userHp;
    changeHp->pokeIds[1] = targetId;
    changeHp->amounts[1] = averageHp - targetHp;
    changeHp->updateGauge = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, changeHp);
    message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&message->message, BTL_MSG_KIND_STD, HAND_WAZA_STR_PAIN_SPLIT);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
    gauge = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_REFRESH_HP_GAUGE, pokeId);
    gauge->pokeId = pokeId;
    gauge->mode = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, gauge);
    gauge = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_REFRESH_HP_GAUGE, pokeId);
    gauge->pokeId = targetId;
    gauge->mode = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, gauge);
}



/* Belly Drum (move 187): handler table, 1 row (its handler is the first function of the next unit). */
u32 *HAND_WAZA_GetBellyDrumHandlers(u32 *handlerCount)
{
    *handlerCount = 1;
    return gBellyDrumHandlers;
}



/* Belly Drum, event 0xa0: when the user has more than half HP and Attack can still rise, pays half the max HP
   and raises Attack to the maximum; shows its own message. */
void HAND_WAZA_BellyDrumMaximizeAttack(int unused, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *bpp;
    int halfMaxHp;
    int attackRoom;
    struct HandExChangeHp *changeHp;
    struct HandExRankChange *rankEffect;
    struct HandExMessage *message;
    struct HandExRefreshHpGauge *gauge;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        halfMaxHp = BTL_CALC_DivideMaxHpMin1(bpp, 2);
        attackRoom = BTL_POKEPARAM_GetStatStageRoom(bpp, BTL_RANK_ATTACK);
        if (BTL_POKEPARAM_GetValue(bpp, BPP_VALUE_HP) > (u32)halfMaxHp && attackRoom != 0) {
            changeHp = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CHANGE_HP, pokeId);
            changeHp->pokeCount = 1;
            changeHp->updateGauge = 1;
            changeHp->pokeIds[0] = pokeId;
            changeHp->amounts[0] = -halfMaxHp;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, changeHp);
            rankEffect = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
            rankEffect->rankKind = BTL_RANK_ATTACK;
            rankEffect->volume = attackRoom;
            rankEffect->targetCount = 1;
            rankEffect->pokeId = pokeId;
            rankEffect->fromMove = 1;
            rankEffect->showMessage = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, rankEffect);
            message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&message->message, BTL_MSG_KIND_SET, HAND_WAZA_STR_BELLY_DRUM);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&message->message), pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
            gauge = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_REFRESH_HP_GAUGE, pokeId);
            gauge->pokeId = pokeId;
            gauge->mode = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, gauge);
        }
    }
}



/* Feint (move 364): handler table, 3 rows. */
int *HAND_WAZA_GetFeintHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gFeintHandlers;
}



/*
 * Feint, event 0x2e: the move ignores protection (sets the shared flag).
 * Leaf with no calls and no pool; 10 instructions, 24 bytes.
 */
void HAND_WAZA_FeintSetBypassFlag(int unused, int unused2, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1);
}



/* Feint, event 0x45: when the target was protecting itself (or a guard was just removed), clears its protected turn
   flag and shows the message. */
void HAND_WAZA_FeintBreakProtect(int unused, struct BtlServerFlow *flow, int pokeId, struct FeintWork *work)
{
    u8 targetId;
    struct HandExTurnFlag *turnFlag;
    struct HandExMessage *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        if (BTL_POKEPARAM_TestTurnFlag(BTL_SERVER_FLOW_GetPokeParam(flow, targetId), BTL_TURN_FLAG_PROTECTED) != 0 || work->guardBroken != 0) {
            turnFlag = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CLEAR_TURN_FLAG, pokeId);
            turnFlag->pokeId = targetId;
            turnFlag->flag = BTL_TURN_FLAG_PROTECTED;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, turnFlag);
            message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&message->message, BTL_MSG_KIND_SET, HAND_WAZA_STR_FEINT);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&message->message), targetId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
        }
    }
}



/* Feint, event 0x23: removes Quick Guard or Wide Guard from the side of the target. */
void HAND_WAZA_FeintBreakSideGuard(int unused, struct BtlServerFlow *flow, int pokeId, struct FeintWork *work)
{
    int side;
    u32 i;
    struct FeintRemoveRecord *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        side = BTL_MAIN_IsZero(BTL_MAIN_IsPokeIdInSecondPair(pokeId));
        if (BTL_SERVER_FLOW_CheckSideEffectActive(flow, side, BTL_SIDE_EFFECT_WIDE_GUARD) != 0 || BTL_SERVER_FLOW_CheckSideEffectActive(flow, side, BTL_SIDE_EFFECT_QUICK_GUARD) != 0) {
            record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_REMOVE_SIDE_EFFECT, pokeId);
            record->side = side;
            record->filter[0] = 3;
            for (i = 1; i < 3; i++)
                record->filter[i] = 0;
            if (record->filter[0] > 2)
                record->filter[2] |= 2;
            if (record->filter[0] > 2)
                record->filter[2] |= 4;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
            work->guardBroken = 1;
        }
    }
}



/* Acupressure (move 367): handler table, 1 row (its handler is the first function of the next unit). */
int *HAND_WAZA_GetAcupressureHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gAcupressureHandlers;
}



/*
 * Acupressure, event 0xa0: raises a random stat of the target by 2 stages, among the stats that can still rise.
 * Lever: chained candidateCount = i = 0 initializes the index first; a fresh byte
 * pick for the random selection keeps the second loop's count in r4.
 * Reusing candidateCount for that selection swaps the second loop's r4/r5 allocation.
 */
void HAND_WAZA_AcupressureRaiseRandomStat(int unused, struct BtlServerFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *bpp;
    u8 candidateCount;
    u8 i;
    struct HandExRankChange *record;
    u8 pick;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST);
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        candidateCount = i = 0;
        for (; i < BTL_RANK_STAT_COUNT; i++) {
            if (BTL_POKEPARAM_CanChangeStatStage(bpp, gAcupressureStats[i], BTL_RANK_DIRECTION_RAISE) != 0)
                candidateCount++;
        }
        if (candidateCount != 0) {
            pick = BTL_CALC_Random(candidateCount);
            for (i = 0; i < BTL_RANK_STAT_COUNT; i++) {
                if (BTL_POKEPARAM_CanChangeStatStage(bpp, gAcupressureStats[i], BTL_RANK_DIRECTION_RAISE) != 0) {
                    if (pick == 0) {
                        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
                        record->pokeId = targetId;
                        record->targetCount = 1;
                        record->rankKind = gAcupressureStats[i];
                        record->volume = 2;
                        record->showMessage = 0;
                        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
                        return;
                    }
                    pick--;
                }
            }
        }
    }
}



/* Rest (move 156): handler table, 2 rows. */
int *HAND_WAZA_GetRestHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gRestHandlers;
}



/*
 * Rest, event 0x1f: sets the fail reason of the move. Two-key gate: only when this is the user and no reason was set yet.
 * Then, in order: already asleep (generic), a sleep-blocking condition, full HP, and an ability
 * (Insomnia or Vital Spirit) that stops sleep. The ability check is the only one that reads the 16-bit value.
 */
void HAND_WAZA_RestCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u16 abilityId;
    struct BtlPokeParam *bpp;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_FAIL_REASON) != 0)
        return;
    bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (BTL_POKEPARAM_HasSick(bpp, BTL_SICK_SLEEP) != 0) {
        BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_GENERIC);
        return;
    }
    if (BTL_POKEPARAM_HasSick(bpp, BTL_SICK_SLEEP_BLOCK) != 0) {
        BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_SLEEP_BLOCKED);
        return;
    }
    if (BTL_POKEPARAM_IsHpFull(bpp) != 0) {
        BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_HP_FULL);
        return;
    }
    abilityId = BTL_POKEPARAM_GetValue(bpp, BPP_VALUE_CURRENT_ABILITY);
    if (abilityId == ABILITY_INSOMNIA || abilityId == ABILITY_VITAL_SPIRIT)
        BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_ABILITY_BLOCKS_SLEEP);
}



/* Rest, event 0xa0: the user falls asleep for 3 turns and recovers all HP. */
void HAND_WAZA_RestSleepAndHeal(int unused, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *bpp;
    struct HandExAddSick *addSick;
    struct HandExRecoverHp *recover;
    struct HandExRefreshHpGauge *gauge;
    u32 maxHp;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_IsHpFull(bpp) == 0) {
            addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            addSick->pokeId = pokeId;
            addSick->sickKind = BTL_SICK_SLEEP;
            addSick->sickCont = BTL_CALC_MakeSickContTurns(3);
            addSick->suppressMessage = 1;
            addSick->useOwnMessage = 1;
            addSick->ignoreImmunity = 1;
            BTL_SERVER_FLOW_InitMsgRecord(&addSick->message, BTL_MSG_KIND_SET, HAND_WAZA_STR_REST);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&addSick->message), pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
            recover = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RECOVER_HP, pokeId);
            recover->pokeId = pokeId;
            maxHp = BTL_POKEPARAM_GetValue(bpp, BPP_VALUE_MAX_HP);
            recover->amount = maxHp - BTL_POKEPARAM_GetValue(bpp, BPP_VALUE_HP);
            recover->header |= HANDEX_FLAG_SILENT;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, recover);
            gauge = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_REFRESH_HP_GAUGE, pokeId);
            gauge->pokeId = pokeId;
            gauge->mode = 3;
            gauge->header |= HANDEX_FLAG_SILENT;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, gauge);
            BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 0);
        }
    }
}



/* Attract (move 213): handler table, 1 row. */
int *HAND_WAZA_GetAttractHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gAttractHandlers;
}



/* Attract, event 0x2c: no effect when either Pokemon is genderless or both have the same gender. */
void HAND_WAZA_AttractCheckGender(int unused, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *userBpp;
    struct BtlPokeParam *targetBpp;
    u8 userGender;
    u8 targetGender;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        userBpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        targetBpp = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID));
        userGender = BTL_POKEPARAM_GetValue(userBpp, BPP_VALUE_GENDER);
        targetGender = BTL_POKEPARAM_GetValue(targetBpp, BPP_VALUE_GENDER);
        if (userGender == BTL_GENDER_NONE || targetGender == BTL_GENDER_NONE || userGender == targetGender)
            BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1);
    }
}



/* Conversion 2 (move 176): handler table, 1 row. */
int *HAND_WAZA_GetConversion2Handlers(int *handlerCount)
{
    *handlerCount = 1;
    return gConversion2Handlers;
}



/* Conversion 2, event 0xa0: the user takes a random type that resists the type of the last move the target used.
   Types the user already has are removed from the candidate list first. */
void HAND_WAZA_Conversion2ChangeType(int unused, struct BtlServerFlow *flow, int pokeId)
{
    int lastMoveType;
    u8 *types;
    u32 typeCount;
    struct BtlPokeParam *userBpp;
    u32 i;
    int newType;
    struct HandExChangeType *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        lastMoveType = BTL_POKEPARAM_GetLastTargetPos(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST)));
        if (lastMoveType != 0x11) {
            types = BTL_SERVER_FLOW_GetScratchBuffer(flow, 0x11);
            typeCount = BTL_CALC_ListResistingTypes(lastMoveType, types);
            if (typeCount != 0) {
                userBpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
                i = 0;
                while (i < typeCount) {
                    if (BTL_POKEPARAM_HasType(userBpp, types[i]) != 0) {
                        if ((int)(typeCount - 1 - i) > 0)
                            MI_CpuCopy8(types + (i + 1), types + i, typeCount - 1 - i);
                        typeCount--;
                    } else {
                        i++;
                    }
                }
                if (typeCount != 0) {
                    newType = types[BTL_CALC_Random(typeCount)];
                    record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CHANGE_TYPE, pokeId);
                    record->typePair = BTL_TYPEPAIR_MakeSingle(newType);
                    record->pokeId = pokeId;
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
                }
            }
        }
    }
}



/* Encore (move 227): handler table, 1 row. */
int *HAND_WAZA_GetEncoreHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gEncoreHandlers;
}



/* Encore, event 0xa0: forces the target to repeat its last move when that move can be encored and has PP left. */
void HAND_WAZA_EncoreAddSick(int unused, struct BtlServerFlow *flow, int pokeId)
{
    EncoreTurns turns = 3;
    u8 targetId;
    struct BtlPokeParam *targetBpp;
    int lastMoveId;
    struct HandExAddSick *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST);
        targetBpp = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        lastMoveId = BTL_POKEPARAM_GetLastSelectedMoveId(targetBpp);
        if (BTL_POKEPARAM_HasSick(targetBpp, BTL_SICK_ENCORE) == 0 && BTL_ID_IsEncoreFailMove(lastMoveId) == 0 && BTL_POKEPARAM_GetMovePPById(targetBpp, lastMoveId) != 0) {
            if (BTL_POKEPARAM_TestTurnFlag(targetBpp, BTL_TURN_FLAG_ACTED) != 0)
                turns = (u8)(turns + 1);
            record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            record->sickKind = BTL_SICK_ENCORE;
            record->sickCont = BTL_SICKCONT_MakeKind2(turns, lastMoveId);
            record->pokeId = targetId;
            record->suppressMessage = 0;
            BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_MSG_KIND_SET, HAND_WAZA_STR_ENCORE);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), targetId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
        }
    }
}



/* Taunt (move 269): handler table, 1 row (its handler is the first function of the next unit). */
int *HAND_WAZA_GetTauntHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gTauntHandlers;
}



/* Taunt: the user taunts the target for 3 turns, 4 when the target already acted this turn. */
void HAND_WAZA_TauntOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlTurnCount turns = BTL_TAUNT_TURNS;
    u8 targetId;
    struct BtlPokeParam *target;
    struct HandExAddSick *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        if (BTL_POKEPARAM_HasSick(target, BTL_SICK_TAUNT) == 0) {
            if (BTL_POKEPARAM_TestTurnFlag(target, BTL_TURN_FLAG_ACTED) != 0)
                turns = (u8)(turns + 1);
            record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            record->sickKind = BTL_SICK_TAUNT;
            record->sickCont = BTL_CALC_MakeSickContTurns(turns);
            record->pokeId = targetId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
        }
    }
}



BtlEventHandler *HAND_WAZA_AddTorment(int *handlerCount)
{
    *handlerCount = 2;
    return gTormentHandlers;
}



/* Torment: the target cannot use the same move twice in a row (permanent status). */
void HAND_WAZA_TormentOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *target;
    struct HandExAddSick *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        if (BTL_POKEPARAM_HasSick(target, BTL_SICK_TORMENT) == 0) {
            record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            record->sickKind = BTL_SICK_TORMENT;
            record->sickCont = BTL_SICKCONT_MakeKind1Empty();
            record->pokeId = targetId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
        }
    }
}



BtlEventHandler *HAND_WAZA_AddDisable(int *handlerCount)
{
    *handlerCount = 1;
    return gDisableHandlers;
}



/* Disable: the target cannot use its last selected move for 4 turns, 5 when it already acted this turn. */
void HAND_WAZA_DisableOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlTurnCount turns;
    u8 targetId;
    struct BtlPokeParam *target;
    int moveId;
    struct HandExAddSick *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        if (BTL_POKEPARAM_HasSick(target, BTL_SICK_DISABLE) == 0) {
            moveId = BTL_POKEPARAM_GetLastSelectedMoveId(target);
            if (moveId != 0 && moveId != BTL_MOVE_STRUGGLE && BTL_POKEPARAM_HasMove(target, moveId) != 0) {
                turns = BTL_DISABLE_TURNS;
                if (BTL_POKEPARAM_TestTurnFlag(target, BTL_TURN_FLAG_ACTED) != 0)
                    turns = (u8)(turns + 1);
                record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
                record->sickKind = BTL_SICK_DISABLE;
                record->sickCont = BTL_SICKCONT_MakeKind2(turns, moveId);
                record->pokeId = targetId;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
            }
        }
    }
}



BtlEventHandler *HAND_WAZA_AddImprison(int *handlerCount)
{
    *handlerCount = 1;
    return gImprisonHandlers;
}



/* Imprison: the user seals the moves it knows against the opponents (field effect bound to the user). */
void HAND_WAZA_ImprisonOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExAddFieldEffect *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_FIELD_EFFECT, pokeId);
        record->effectKind = BTL_FIELD_EFFECT_IMPRISON;
        record->cont = BTL_SICKCONT_MakeKind3(pokeId);
        record->showMessage = 1;
        record->message.strTypeHalf = BTL_STRTYPE_SET;
        record->message.strId = BTL_STR_IMPRISON;
        record->message.argCountHalf = 1;
        record->message.args[0] = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}



BtlEventHandler *HAND_WAZA_AddAromatherapy(int *handlerCount)
{
    *handlerCount = 3;
    return gAromatherapyHandlers;
}



/* Aromatherapy: cure the status of the whole party (message 0x70). */
void HAND_WAZA_AromatherapyOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_WAZA_CureParty(factor, flow, pokeId, work, BTL_STR_CURE_PARTY_AROMATHERAPY);
}



BtlEventHandler *HAND_WAZA_AddHealBell(int *handlerCount)
{
    *handlerCount = 3;
    return gHealBellHandlers;
}



/* Heal Bell: cure the status of the whole party (message 0x6f). */
void HAND_WAZA_HealBellOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_WAZA_CureParty(factor, flow, pokeId, work, BTL_STR_CURE_PARTY_HEAL_BELL);
}



/* Shared body of Aromatherapy and Heal Bell: show the message, then cure every party member (and the ally's party in doubles). */
void HAND_WAZA_CureParty(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work, u16 messageId)
{
    struct BtlParty *ownParty;
    struct BtlParty *allyParty;
    u8 *curedIds;
    struct HandExMessage *messageRecord;
    struct HandExCureSick *cureRecord;
    u8 curedCount;
    u8 i;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        ownParty = (struct BtlParty *)BTL_SERVER_FLOW_GetPartyOfPoke(flow, pokeId);
        allyParty = (struct BtlParty *)BTL_SERVER_FLOW_GetPartyOfPokeIfClientUsed(flow, pokeId);
        curedIds = BTL_SERVER_FLOW_GetScratchBuffer(flow, BTL_PARTY_CURE_MAX);
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, BTL_STRTYPE_STD, messageId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
        curedCount = HAND_WAZA_CollectStatusedPokeIds(ownParty, 0, BTL_PARTY_CURE_MAX, curedIds);
        if (allyParty != 0)
            curedCount = curedCount + HAND_WAZA_CollectStatusedPokeIds(allyParty, curedCount, BTL_PARTY_CURE_MAX, curedIds);
        if (curedCount != 0) {
            if (curedCount > BTL_PARTY_CURE_MAX)
                curedCount = BTL_PARTY_CURE_MAX;
            cureRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
            cureRecord->pokeCount = curedCount;
            for (i = 0; i < curedCount; i++)
                cureRecord->pokeIds[i] = curedIds[i];
            cureRecord->sickKind = BTL_SICK_ALL_MAJOR;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cureRecord);
        }
    }
}



/* Collects the ids of the party members that have a major status into outIds, starting at startIndex and stopping at limit; returns how many were added. */
u8 HAND_WAZA_CollectStatusedPokeIds(struct BtlParty *party, u8 startIndex, u8 limit, u8 *outIds)
{
    u8 addedCount;
    u8 i;
    u8 memberCount = BTL_SLOT_GetCount((struct BtlSideSlot *)party);
    struct BtlPokeParam *member;

    addedCount = 0;
    for (i = 0; i < memberCount; i++) {
        if (startIndex >= limit)
            break;
        member = BTL_SLOT_GetPokeParam((struct BtlSideSlot *)party, i);
        if (BTL_POKEPARAM_GetMajorStatusIndex(member) != 0) {
            outIds[startIndex] = BTL_POKEPARAM_GetPokeId(member);
            startIndex = startIndex + 1;
            addedCount = addedCount + 1;
        }
    }
    return addedCount;
}



/*
 * Sibling of src/matched/BOX2_SEQ_StateBoxMenu.c and BOX2_SEQ_StateMoveMove.c.
 * The image computes r + 0x1E
 * separately for BOX2_MAIN_ChangeBoxFormPreserve and for the call after it; the (int) cast on
 * the first keeps the two expressions apart so they are not CSEd.
 */
BtlEventHandler *HAND_WAZA_AddMemento(int *handlerCount)
{
    *handlerCount = 1;
    return gMementoHandlers;
}



/* Memento: the user lowers the target's attack and special attack by 2 stages each, then faints. */
void HAND_WAZA_MementoOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 targetId;
    u32 serialNumber;
    enum { BTL_RANK_KIND_ATTACK = 1 } rankKind;
    int volume;
    struct HandExRankChange *rankRecord;
    struct HandExKillPoke *killRecord;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        serialNumber = BTL_SERVER_FLOW_NextSerialNumberThunk(flow);
        rankKind = BTL_RANK_KIND_ATTACK;
        rankRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_CHANGE, pokeId);
        rankRecord->targetCount = rankKind;
        rankRecord->pokeId = targetId;
        rankRecord->rankKind = rankKind;
        volume = rankKind - 3;
        rankRecord->volume = volume;
        rankRecord->serialNumber = serialNumber;
        rankRecord->showMessage = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rankRecord);
        rankRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_CHANGE, pokeId);
        rankRecord->targetCount = rankKind;
        rankRecord->pokeId = targetId;
        rankRecord->rankKind = 3;
        rankRecord->volume = volume;
        rankRecord->serialNumber = serialNumber;
        rankRecord->showMessage = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rankRecord);
        killRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_KILL_POKE, pokeId);
        killRecord->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, killRecord);
    }
}



BtlEventHandler *HAND_WAZA_AddSpite(int *handlerCount)
{
    *handlerCount = 1;
    return gSpiteHandlers;
}



/* Spite: the target loses up to 4 PP of the move it used last. */
void HAND_WAZA_SpiteOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *target;
    int moveId;
    int moveSlot;
    u8 amount;
    struct HandExReducePp *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        moveId = BTL_POKEPARAM_GetLastSelectedMoveId(target);
        moveSlot = BTL_POKEPARAM_FindMoveSlot(target, moveId);
        if (moveSlot != BTL_MOVE_SLOT_COUNT) {
            amount = BTL_POKEPARAM_GetMovePPChecked(target, moveSlot);
            if (amount > BTL_SPITE_PP_MAX)
                amount = BTL_SPITE_PP_MAX;
            if (amount != 0) {
                record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_REDUCE_PP, pokeId);
                record->pokeId = targetId;
                record->amount = amount;
                record->moveSlot = moveSlot;
                BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_STRTYPE_SET, BTL_STR_SPITE);
                BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), targetId);
                BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), moveId);
                BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), amount);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
            }
        }
    }
}



BtlEventHandler *HAND_WAZA_AddPsychUp(int *handlerCount)
{
    *handlerCount = 1;
    return gPsychUpHandlers;
}



/* Psych Up: the user copies all stat stages of the target. */
void HAND_WAZA_PsychUpOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *target;
    struct HandExSetRanks *ranksRecord;
    struct HandExMessage *messageRecord;
    u8 targetId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        ranksRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_RANKS, pokeId);
        ranksRecord->pokeId = pokeId;
        ranksRecord->ranks[0] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_ATTACK_RANK);
        ranksRecord->ranks[1] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_DEFENSE_RANK);
        ranksRecord->ranks[2] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_SP_ATTACK_RANK);
        ranksRecord->ranks[3] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_SP_DEFENSE_RANK);
        ranksRecord->ranks[4] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_SPEED_RANK);
        ranksRecord->ranks[5] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_ACCURACY_RANK);
        ranksRecord->ranks[6] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_EVASION_RANK);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, ranksRecord);
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, BTL_STRTYPE_SET, BTL_STR_PSYCH_UP);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), targetId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}



BtlEventHandler *HAND_WAZA_AddHeartSwap(int *handlerCount)
{
    *handlerCount = 1;
    return gHeartSwapHandlers;
}



/* Heart Swap: the user and the target swap all stat stages. */
void HAND_WAZA_HeartSwapOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *target;
    struct BtlPokeParam *user;
    u32 *userRanks;
    int i;
    struct HandExSetRanks *ranksRecord;
    struct HandExMessage *messageRecord;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        userRanks = (u32 *)BTL_SERVER_FLOW_GetScratchBuffer(flow, BTL_RANK_BACKUP_SIZE);
        for (i = BPP_VALUE_ATTACK_RANK; i <= BPP_VALUE_EVASION_RANK; i++) {
            userRanks[i - 1] = BTL_POKEPARAM_GetValue(user, i);
        }
        ranksRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_RANKS, pokeId);
        ranksRecord->pokeId = pokeId;
        ranksRecord->ranks[0] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_ATTACK_RANK);
        ranksRecord->ranks[1] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_DEFENSE_RANK);
        ranksRecord->ranks[2] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_SP_ATTACK_RANK);
        ranksRecord->ranks[3] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_SP_DEFENSE_RANK);
        ranksRecord->ranks[4] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_SPEED_RANK);
        ranksRecord->ranks[5] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_ACCURACY_RANK);
        ranksRecord->ranks[6] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_EVASION_RANK);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, ranksRecord);
        ranksRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_RANKS, pokeId);
        ranksRecord->pokeId = targetId;
        ranksRecord->ranks[0] = userRanks[0];
        ranksRecord->ranks[1] = userRanks[1];
        ranksRecord->ranks[2] = userRanks[2];
        ranksRecord->ranks[3] = userRanks[3];
        ranksRecord->ranks[4] = userRanks[4];
        ranksRecord->ranks[5] = userRanks[5];
        ranksRecord->ranks[6] = userRanks[6];
        BTL_SERVER_FLOW_CommitCmdRecord(flow, ranksRecord);
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, BTL_STRTYPE_SET, BTL_STR_HEART_SWAP);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}



BtlEventHandler *HAND_WAZA_AddPowerSwap(int *handlerCount)
{
    *handlerCount = 1;
    return gPowerSwapHandlers;
}



/* Power Swap: the user and the target swap their attack and special attack stages. */
void HAND_WAZA_PowerSwapOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *target;
    struct BtlPokeParam *user;
    u32 userAttackRank;
    u32 userSpAttackRank;
    struct HandExSetRanks *ranksRecord;
    struct HandExMessage *messageRecord;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        userAttackRank = BTL_POKEPARAM_GetValue(user, BPP_VALUE_ATTACK_RANK);
        userSpAttackRank = BTL_POKEPARAM_GetValue(user, BPP_VALUE_SP_ATTACK_RANK);
        ranksRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_RANKS, pokeId);
        ranksRecord->pokeId = pokeId;
        ranksRecord->ranks[0] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_ATTACK_RANK);
        ranksRecord->ranks[2] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_SP_ATTACK_RANK);
        ranksRecord->ranks[1] = BTL_POKEPARAM_GetValue(user, BPP_VALUE_DEFENSE_RANK);
        ranksRecord->ranks[3] = BTL_POKEPARAM_GetValue(user, BPP_VALUE_SP_DEFENSE_RANK);
        ranksRecord->ranks[4] = BTL_POKEPARAM_GetValue(user, BPP_VALUE_SPEED_RANK);
        ranksRecord->ranks[5] = BTL_POKEPARAM_GetValue(user, BPP_VALUE_ACCURACY_RANK);
        ranksRecord->ranks[6] = BTL_POKEPARAM_GetValue(user, BPP_VALUE_EVASION_RANK);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, ranksRecord);
        ranksRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_RANKS, pokeId);
        ranksRecord->pokeId = targetId;
        ranksRecord->ranks[0] = userAttackRank;
        ranksRecord->ranks[2] = userSpAttackRank;
        ranksRecord->ranks[1] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_DEFENSE_RANK);
        ranksRecord->ranks[3] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_SP_DEFENSE_RANK);
        ranksRecord->ranks[4] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_SPEED_RANK);
        ranksRecord->ranks[5] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_ACCURACY_RANK);
        ranksRecord->ranks[6] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_EVASION_RANK);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, ranksRecord);
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, BTL_STRTYPE_SET, BTL_STR_POWER_SWAP);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}



BtlEventHandler *HAND_WAZA_AddGuardSwap(int *handlerCount)
{
    *handlerCount = 1;
    return gGuardSwapHandlers;
}



/* Guard Swap: the user and the target swap their defense and special defense stages. */
void HAND_WAZA_GuardSwapOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *target;
    struct BtlPokeParam *user;
    u32 userDefenseRank;
    u32 userSpDefenseRank;
    struct HandExSetRanks *ranksRecord;
    struct HandExMessage *messageRecord;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        userDefenseRank = BTL_POKEPARAM_GetValue(user, BPP_VALUE_DEFENSE_RANK);
        userSpDefenseRank = BTL_POKEPARAM_GetValue(user, BPP_VALUE_SP_DEFENSE_RANK);
        ranksRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_RANKS, pokeId);
        ranksRecord->pokeId = pokeId;
        ranksRecord->ranks[0] = BTL_POKEPARAM_GetValue(user, BPP_VALUE_ATTACK_RANK);
        ranksRecord->ranks[2] = BTL_POKEPARAM_GetValue(user, BPP_VALUE_SP_ATTACK_RANK);
        ranksRecord->ranks[1] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_DEFENSE_RANK);
        ranksRecord->ranks[3] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_SP_DEFENSE_RANK);
        ranksRecord->ranks[4] = BTL_POKEPARAM_GetValue(user, BPP_VALUE_SPEED_RANK);
        ranksRecord->ranks[5] = BTL_POKEPARAM_GetValue(user, BPP_VALUE_ACCURACY_RANK);
        ranksRecord->ranks[6] = BTL_POKEPARAM_GetValue(user, BPP_VALUE_EVASION_RANK);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, ranksRecord);
        ranksRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_RANKS, pokeId);
        ranksRecord->pokeId = targetId;
        ranksRecord->ranks[0] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_ATTACK_RANK);
        ranksRecord->ranks[2] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_SP_ATTACK_RANK);
        ranksRecord->ranks[1] = userDefenseRank;
        ranksRecord->ranks[3] = userSpDefenseRank;
        ranksRecord->ranks[4] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_SPEED_RANK);
        ranksRecord->ranks[5] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_ACCURACY_RANK);
        ranksRecord->ranks[6] = BTL_POKEPARAM_GetValue(target, BPP_VALUE_EVASION_RANK);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, ranksRecord);
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, BTL_STRTYPE_SET, BTL_STR_GUARD_SWAP);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}



BtlEventHandler *HAND_WAZA_AddPowerTrick(int *handlerCount)
{
    *handlerCount = 1;
    return gPowerTrickHandlers;
}



/* Power Trick: the user swaps its attack and defense, and sets the flag that undoes it on the next use. */
void HAND_WAZA_PowerTrickOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *user;
    struct HandExSetContFlag *flagRecord;
    struct HandExSetStats *statsRecord;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        statsRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_STATS, pokeId);
        statsRecord->pokeId = pokeId;
        statsRecord->attack = BTL_POKEPARAM_GetStatRaw(user, BPP_VALUE_DEFENSE);
        statsRecord->defense = BTL_POKEPARAM_GetStatRaw(user, BPP_VALUE_ATTACK);
        statsRecord->setAttack = 1;
        statsRecord->setDefense = 1;
        BTL_SERVER_FLOW_InitMsgRecord(&statsRecord->message, BTL_STRTYPE_SET, BTL_STR_POWER_TRICK);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&statsRecord->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, statsRecord);
        flagRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_CONT_FLAG, pokeId);
        flagRecord->pokeId = pokeId;
        flagRecord->contFlag = BTL_CONT_FLAG_POWER_TRICK;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, flagRecord);
    }
}



BtlEventHandler *HAND_WAZA_AddPowerSplit(int *handlerCount)
{
    *handlerCount = 1;
    return gPowerSplitHandlers;
}



/* Power Split: the user and the target both take the average of their attack and of their special attack. */
void HAND_WAZA_PowerSplitOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *user;
    struct BtlPokeParam *target;
    int averageAttack;
    int averageSpAttack;
    struct HandExSetStats *statsRecord;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        averageAttack = (BTL_POKEPARAM_GetStatRaw(user, BPP_VALUE_ATTACK) + BTL_POKEPARAM_GetStatRaw(target, BPP_VALUE_ATTACK)) / 2;
        averageSpAttack = (BTL_POKEPARAM_GetStatRaw(user, BPP_VALUE_SP_ATTACK) + BTL_POKEPARAM_GetStatRaw(target, BPP_VALUE_SP_ATTACK)) / 2;
        statsRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_STATS, pokeId);
        statsRecord->pokeId = targetId;
        statsRecord->attack = averageAttack;
        statsRecord->spAttack = averageSpAttack;
        statsRecord->setAttack = 1;
        statsRecord->setSpAttack = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, statsRecord);
        statsRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_STATS, pokeId);
        statsRecord->pokeId = pokeId;
        statsRecord->attack = averageAttack;
        statsRecord->spAttack = averageSpAttack;
        statsRecord->setAttack = 1;
        statsRecord->setSpAttack = 1;
        BTL_SERVER_FLOW_InitMsgRecord(&statsRecord->message, BTL_STRTYPE_SET, BTL_STR_POWER_SPLIT);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&statsRecord->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, statsRecord);
    }
}



BtlEventHandler *HAND_WAZA_AddGuardSplit(int *handlerCount)
{
    *handlerCount = 1;
    return gGuardSplitHandlers;
}



/* Guard Split: the user and the target both take the average of their defense and of their special defense. */
void HAND_WAZA_GuardSplitOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *user;
    struct BtlPokeParam *target;
    int averageDefense;
    int averageSpDefense;
    struct HandExSetStats *statsRecord;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        averageDefense = (BTL_POKEPARAM_GetStatRaw(user, BPP_VALUE_DEFENSE) + BTL_POKEPARAM_GetStatRaw(target, BPP_VALUE_DEFENSE)) / 2;
        averageSpDefense = (BTL_POKEPARAM_GetStatRaw(user, BPP_VALUE_SP_DEFENSE) + BTL_POKEPARAM_GetStatRaw(target, BPP_VALUE_SP_DEFENSE)) / 2;
        statsRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_STATS, pokeId);
        statsRecord->pokeId = targetId;
        statsRecord->defense = averageDefense;
        statsRecord->spDefense = averageSpDefense;
        statsRecord->setDefense = 1;
        statsRecord->setSpDefense = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, statsRecord);
        statsRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_STATS, pokeId);
        statsRecord->pokeId = pokeId;
        statsRecord->defense = averageDefense;
        statsRecord->spDefense = averageSpDefense;
        statsRecord->setDefense = 1;
        statsRecord->setSpDefense = 1;
        BTL_SERVER_FLOW_InitMsgRecord(&statsRecord->message, BTL_STRTYPE_SET, BTL_STR_GUARD_SPLIT);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&statsRecord->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, statsRecord);
    }
}



BtlEventHandler *HAND_WAZA_AddLockOn(int *handlerCount)
{
    *handlerCount = 1;
    return gLockOnHandlers;
}



/* Lock-On and Mind Reader: the user's next move cannot miss the target (status lasts 2 turns). */
void HAND_WAZA_LockOnOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExAddSick *record;
    u8 targetId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
        record->pokeId = pokeId;
        record->sickKind = BTL_SICK_LOCK_ON;
        record->sickCont = BTL_SICKCONT_MakeKind4(targetId, BTL_LOCK_ON_TURNS);
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_STRTYPE_SET, BTL_STR_LOCK_ON);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), targetId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}



BtlEventHandler *HAND_WAZA_AddReflect(int *handlerCount)
{
    *handlerCount = 1;
    return gReflectHandlers;
}



/*
 * Reflect: a screen on the user's side for 5 turns.
 * The cont value is a one-word struct result (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 */
void HAND_WAZA_ReflectOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    union SickCont cont = BTL_SICKCONT_MakeKind2Index(5);
    u8 side = BTL_MAIN_IsPokeIdInSecondPair(pokeId);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_REFLECT, cont, BTL_SIDE_EFFECT_STR_REFLECT);
}



BtlEventHandler *HAND_WAZA_AddLightScreen(int *handlerCount)
{
    *handlerCount = 1;
    return gLightScreenHandlers;
}



/*
 * Light Screen: a screen on the user's side for 5 turns.
 * The cont value is a one-word struct result (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 */
void HAND_WAZA_LightScreenOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    union SickCont cont = BTL_SICKCONT_MakeKind2Index(5);
    u8 side = BTL_MAIN_IsPokeIdInSecondPair(pokeId);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_LIGHT_SCREEN, cont, BTL_SIDE_EFFECT_STR_LIGHT_SCREEN);
}



BtlEventHandler *HAND_WAZA_AddSafeguard(int *handlerCount)
{
    *handlerCount = 1;
    return gSafeguardHandlers;
}



/*
 * Safeguard: a ward on the user's side for 5 turns.
 * The cont value is a one-word struct result (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 */
void HAND_WAZA_SafeguardOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 side = BTL_MAIN_IsPokeIdInSecondPair(pokeId);
    union SickCont cont = BTL_SICKCONT_MakeKind2Index(5);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_SAFEGUARD, cont, BTL_SIDE_EFFECT_STR_SAFEGUARD);
}



BtlEventHandler *HAND_WAZA_AddMist(int *handlerCount)
{
    *handlerCount = 1;
    return gMistHandlers;
}



/* Mist: a ward on the user's side for 5 turns. */
void HAND_WAZA_MistOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    union SickCont cont = BTL_SICKCONT_MakeKind2Index(5);
    u8 side = BTL_MAIN_IsPokeIdInSecondPair(pokeId);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_MIST, cont, BTL_SIDE_EFFECT_STR_MIST);
}



BtlEventHandler *HAND_WAZA_AddTailwind(int *handlerCount)
{
    *handlerCount = 1;
    return gTailwindHandlers;
}



/*
 * Tailwind: a wind on the user's side for 4 turns.
 * The cont value is a one-word struct result (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 */
void HAND_WAZA_TailwindOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    union SickCont cont = BTL_SICKCONT_MakeKind2Index(4);
    u8 side = BTL_MAIN_IsPokeIdInSecondPair(pokeId);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_TAILWIND, cont, BTL_SIDE_EFFECT_STR_TAILWIND);
}



BtlEventHandler *HAND_WAZA_AddLuckyChant(int *handlerCount)
{
    *handlerCount = 1;
    return gLuckyChantHandlers;
}



/* Lucky Chant: a ward on the user's side for 5 turns. */
void HAND_WAZA_LuckyChantOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    union SickCont cont = BTL_SICKCONT_MakeKind2Index(5);
    u8 side = BTL_MAIN_IsPokeIdInSecondPair(pokeId);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_LUCKY_CHANT, cont, BTL_SIDE_EFFECT_STR_LUCKY_CHANT);
}



BtlEventHandler *HAND_WAZA_AddSpikes(int *handlerCount)
{
    *handlerCount = 1;
    return gSpikesHandlers;
}



/* Spikes: a permanent hazard on the opposing side. */
void HAND_WAZA_SpikesOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    union SickCont cont = BTL_SICKCONT_MakeKind1Empty();
    u8 side = BTL_MAIN_IsPokeIdInFirstPair(pokeId);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_SPIKES, cont, BTL_SIDE_EFFECT_STR_SPIKES);
}



BtlEventHandler *HAND_WAZA_AddToxicSpikes(int *handlerCount)
{
    *handlerCount = 1;
    return gToxicSpikesHandlers;
}



/* Toxic Spikes: a permanent hazard on the opposing side. */
void HAND_WAZA_ToxicSpikesOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    union SickCont cont = BTL_SICKCONT_MakeKind1Empty();
    u8 side = BTL_MAIN_IsPokeIdInFirstPair(pokeId);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_TOXIC_SPIKES, cont, BTL_SIDE_EFFECT_STR_TOXIC_SPIKES);
}



BtlEventHandler *HAND_WAZA_AddStealthRock(int *handlerCount)
{
    *handlerCount = 1;
    return gStealthRockHandlers;
}



/*
 * Stealth Rock: a permanent hazard on the opposing side.
 * The cont value is a one-word struct result (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 */
void HAND_WAZA_StealthRockOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    union SickCont cont = BTL_SICKCONT_MakeKind1Empty();
    u8 side = BTL_MAIN_IsPokeIdInFirstPair(pokeId);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_STEALTH_ROCK, cont, BTL_SIDE_EFFECT_STR_STEALTH_ROCK);
}



BtlEventHandler *HAND_WAZA_AddWideGuard(int *handlerCount)
{
    *handlerCount = 4;
    return gWideGuardHandlers;
}



/* Wide Guard: a ward on the user's side for 1 turn. */
void HAND_WAZA_WideGuardOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    union SickCont cont;

    cont = BTL_SICKCONT_MakeKind2Index(1);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, BTL_MAIN_IsPokeIdInSecondPair(pokeId), BTL_SIDE_EFFECT_WIDE_GUARD, cont, BTL_SIDE_EFFECT_STR_WIDE_GUARD);
    HAND_WAZA_ProtectIncrementStreak(flow, pokeId, 1);
}



/* Shared by the screens, wards and hazards: puts an effect of the given kind and duration on a side and shows the message. */
void HAND_WAZA_AddSideEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work,
                   u8 side, int effectKind, union SickCont cont, u16 messageId)
{
    struct HandExAddSideEffect *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SIDE_EFFECT, pokeId);
        record->effectKind = effectKind;
        record->side = side;
        record->cont = cont;
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_STRTYPE_STD, messageId);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), side);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}



BtlEventHandler *HAND_WAZA_AddTransform(int *handlerCount)
{
    *handlerCount = 1;
    return gTransformHandlers;
}



/* Transform: the user turns into the target. */
void HAND_WAZA_TransformOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExTransform *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_TRANSFORM, pokeId);
        record->targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_STRTYPE_SET, BTL_STR_TRANSFORM);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), record->targetId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}



BtlEventHandler *HAND_WAZA_AddLunarDance(int *handlerCount)
{
    *handlerCount = 1;
    return gLunarDanceHandlers;
}




/* Lunar Dance: arm the position effect for the slot and let the user faint. */
void HAND_WAZA_LunarDanceSetPosEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExSetPosEffect *posEffect;
    struct HandExFaint *faint;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID) && BTL_SERVER_FLOW_CheckClientHasBackupPoke(flow, pokeId) != 0) {
        posEffect = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_POS_EFFECT, pokeId);
        posEffect->effectKind = BTL_POS_EFFECT_LUNAR_DANCE;
        posEffect->position = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, posEffect);
        faint = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_FAINT, pokeId);
        faint->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, faint);
    }
}




/* Healing Wish getter: one handler row. */
int *HAND_WAZA_GetHealingWishHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gHealingWishHandlers;
}




/* Healing Wish: arm the position effect for the slot and let the user faint. */
void HAND_WAZA_HealingWishSetPosEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExSetPosEffect *posEffect;
    struct HandExFaint *faint;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID) && BTL_SERVER_FLOW_CheckClientHasBackupPoke(flow, pokeId) != 0) {
        posEffect = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_POS_EFFECT, pokeId);
        posEffect->effectKind = BTL_POS_EFFECT_HEALING_WISH;
        posEffect->position = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, posEffect);
        faint = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_FAINT, pokeId);
        faint->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, faint);
    }
}




/* Wish getter: one handler row. */
int *HAND_WAZA_GetWishHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWishHandlers;
}




/* Wish: arm the Wish position effect for the slot of the user. */
void HAND_WAZA_WishSetPosEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExSetPosEffect *posEffect;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        posEffect = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_POS_EFFECT, pokeId);
        posEffect->effectKind = BTL_POS_EFFECT_WISH;
        posEffect->position = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, posEffect);
    }
}




/* Future Sight getter: two handler rows. */
int *HAND_WAZA_GetFutureSightHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gFutureSightHandlers;
}




/* Future Sight: arm the delayed attack on the chosen target position. */
void HAND_WAZA_FutureSightArmDelayedAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 targetPosition;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        targetPosition = BTL_EVENT_GetVar(BTL_EVAR_TARGET_POSITION);
        HAND_WAZA_ArmDelayedAttack(factor, flow, pokeId, targetPosition);
    }
}




/* Future Sight: message that the user foresaw an attack. */
void HAND_WAZA_FutureSightShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExMessage *messageRecord;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x432);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}




/* Shared by Future Sight and Doom Desire: arm the delayed attack two turns ahead, owned by this factor. */
void HAND_WAZA_ArmDelayedAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int targetPosition)
{
    struct HandExSetPosEffect *posEffect;
    int userPosition;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID) && BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1) != 0) {
        if (targetPosition == BTL_SLOT_NONE) {
            userPosition = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
            targetPosition = BTL_MAIN_GetEnemyLanePos(BTL_SERVER_FLOW_GetRule(flow), userPosition, 0);
        }
        posEffect = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_POS_EFFECT, pokeId);
        posEffect->effectKind = BTL_POS_EFFECT_DELAYED_ATTACK;
        posEffect->position = targetPosition;
        posEffect->param = BTL_SERVER_FLOW_GetTurnCount(flow) + 2;
        posEffect->factorKey = BTL_EVENT_GetFactorKey(factor);
        posEffect->mode = 2;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, posEffect);
    }
}




/* Doom Desire getter: two handler rows. */
int *HAND_WAZA_GetDoomDesireHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gDoomDesireHandlers;
}




/* Doom Desire: arm the delayed attack on the chosen target position. */
void HAND_WAZA_DoomDesireArmDelayedAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 targetPosition;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        targetPosition = BTL_EVENT_GetVar(BTL_EVAR_TARGET_POSITION);
        HAND_WAZA_ArmDelayedAttack(factor, flow, pokeId, targetPosition);
    }
}




/* Doom Desire: message that the user chose destiny. */
void HAND_WAZA_DoomDesireShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExMessage *messageRecord;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x435);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}




/* Gastro Acid getter: one handler row. */
int *HAND_WAZA_GetGastroAcidHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gGastroAcidHandlers;
}




/* Gastro Acid: suppress the ability of the target and announce it. */
void HAND_WAZA_GastroAcidSuppressAbility(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExAddSickAnnounce *addSick;
    u8 targetId;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
        addSick->pokeId = targetId;
        addSick->sickKind = BTL_SICK_ABILITY_SUPPRESSED;
        addSick->sickCont = BTL_SICKCONT_MakeKind1Empty();
        BTL_SERVER_FLOW_InitMsgRecord(&addSick->message, HANDEX_MESSAGE_SET, 0x235);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&addSick->message), targetId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
    }
}




/* Role Play getter: one handler row. */
int *HAND_WAZA_GetRolePlayHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRolePlayHandlers;
}




/* Role Play: copy the ability of the target when it can be copied. */
void HAND_WAZA_RolePlayCopyAbility(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExChangeAbility *changeAbility;
    u8 targetId;
    int targetAbility;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        targetAbility = BTL_POKEPARAM_GetValue(BTL_SERVER_FLOW_GetPokeParam(flow, targetId), BPP_VALUE_ABILITY);
        if (BTL_ID_IsAbilityRolePlayBlocked(targetAbility) == 0) {
            changeAbility = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CHANGE_ABILITY, pokeId);
            changeAbility->pokeId = pokeId;
            changeAbility->abilityId = targetAbility;
            BTL_SERVER_FLOW_InitMsgRecord(&changeAbility->message, HANDEX_MESSAGE_SET, 0x26b);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&changeAbility->message), pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&changeAbility->message), targetId);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&changeAbility->message), changeAbility->abilityId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, changeAbility);
        }
    }
}



/* Registry hazard kinds that Rapid Spin checks on the side of the user. */
#define HAZARD_SPIKES 6



/* U-turn and Volt Switch getter: one handler row. */
int *HAND_WAZA_GetUTurnHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gUTurnHandlers;
}




/* U-turn and Volt Switch: announce the switch, then send the user back to its ball. */
void HAND_WAZA_UTurnSwitchOut(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExMessageAnim *messageAnim;
    struct HandExSwitchOut *switchOut;
    int trainerId;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID) && BTL_SERVER_FLOW_CheckClientHasBackupPoke(flow, pokeId) != 0 && BTL_SERVER_FLOW_TrySetOnceFlag((struct Flag *)flow) != 0) {
        trainerId = BTL_MAIN_PokeIdToClientIdThunk(pokeId);
        messageAnim = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_MESSAGE_ANIM, pokeId);
        messageAnim->pokeId = pokeId;
        BTL_SERVER_FLOW_InitMsgRecord(&messageAnim->message, HANDEX_MESSAGE_SET, 0x302);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageAnim->message), pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageAnim->message), trainerId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageAnim);
        switchOut = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SWITCH_OUT, pokeId);
        switchOut->messageId = (BTL_EVENT_GetFactorKey(factor) == 0x171) ? 0x283 : 0x284;
        switchOut->position = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
        switchOut->replacementSlot = BTL_SLOT_NONE;
        switchOut->header |= HANDEX_FLAG_NO_WAIT;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, switchOut);
    }
}




/* Rapid Spin getter: one handler row. */
int *HAND_WAZA_GetRapidSpinHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRapidSpinHandlers;
}



/* Rapid Spin: free the user from binding and Leech Seed, then clear the hazards on its side. */
void HAND_WAZA_RapidSpinClearBindingAndHazards(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *pokeParam;
    struct HandExCureSick *cureSick;
    struct HandExClearHazards *clearHazards;
    int side;
    u8 hasSpikes, hasToxicSpikes, hasStealthRock;
    u32 i;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        pokeParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_HasSick(pokeParam, BTL_SICK_LEECH_SEED) != 0) {
            cureSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
            cureSick->pokeCount = 1;
            cureSick->pokeIds[0] = pokeId;
            cureSick->sickKind = BTL_SICK_LEECH_SEED;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSick);
        }
        if (BTL_POKEPARAM_HasSick(pokeParam, BTL_SICK_BIND) != 0) {
            cureSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
            cureSick->pokeCount = 1;
            cureSick->pokeIds[0] = pokeId;
            cureSick->sickKind = BTL_SICK_BIND;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSick);
        }
        side = BTL_MAIN_IsPokeIdInSecondPair(pokeId);
        hasSpikes = HAND_SIDE_IsActive(side, HAZARD_SPIKES);
        hasToxicSpikes = HAND_SIDE_IsActive(side, HAZARD_TOXIC_SPIKES);
        hasStealthRock = HAND_SIDE_IsActive(side, HAZARD_STEALTH_ROCK);
        if (hasSpikes || hasToxicSpikes || hasStealthRock) {
            clearHazards = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_CLEAR_HAZARDS, pokeId);
            clearHazards->side = side;
            clearHazards->maskBytes[0] = 3;
            for (i = 1; i < 3; i++)
                clearHazards->maskBytes[i] = 0;
            if (hasSpikes && clearHazards->maskBytes[0] > 1)
                clearHazards->maskBytes[1] |= 0x40;
            if (hasToxicSpikes && clearHazards->maskBytes[0] > 1)
                clearHazards->maskBytes[1] |= 0x80;
            if (hasStealthRock && clearHazards->maskBytes[0] > 2)
                clearHazards->maskBytes[2] |= 1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, clearHazards);
        }
    }
}



/* Item parameters read by Fling. */
#define ITEM_PARAM_FLING_EFFECT 9



/* Value id of the base Attack stat of a species, used by Beat Up. */
#define BPP_VALUE_BASE_ATTACK 0x15



/* Number of party slots Beat Up walks through. */
#define BEAT_UP_PARTY_SLOTS 6




/* Baton Pass getter: one handler row. */
int *HAND_WAZA_GetBatonPassHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBatonPassHandlers;
}




/* Baton Pass: arm the pass-on position effect, flag the user as passing, show the switch animation. */
void HAND_WAZA_BatonPassSwitchOut(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExSetPosEffect *posEffect;
    struct HandExSetContFlag *setContFlag;
    struct HandExMessageAnim *messageAnim;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID) && BTL_SERVER_FLOW_CheckClientHasBackupPoke(flow, pokeId) != 0 && BTL_SERVER_FLOW_TrySetOnceFlag((struct Flag *)flow) != 0) {
        posEffect = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_POS_EFFECT, pokeId);
        posEffect->effectKind = BTL_POS_EFFECT_BATON_PASS;
        posEffect->position = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
        posEffect->param = pokeId;
        posEffect->mode = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, posEffect);
        setContFlag = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_CONT_FLAG, pokeId);
        setContFlag->pokeId = pokeId;
        setContFlag->contFlag = BTL_CONT_FLAG_BATON_PASS;
        setContFlag->header |= HANDEX_FLAG_NO_WAIT;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, setContFlag);
        messageAnim = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_MESSAGE_ANIM, pokeId);
        messageAnim->pokeId = pokeId;
        messageAnim->animMode = 1;
        messageAnim->header |= HANDEX_FLAG_NO_WAIT;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageAnim);
    }
}




/* Teleport getter: three handler rows. */
int *HAND_WAZA_GetTeleportHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gTeleportHandlers;
}




/* Teleport: fails in a trainer battle or when the user is bound and trapped. */
void HAND_WAZA_TeleportCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *pokeParam;

    if (BTL_SERVER_FLOW_GetCompetitor(flow) != 0 || BTL_SERVER_FLOW_GetRule(flow) != 0)
        BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
    pokeParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (BTL_POKEPARAM_HasSick(pokeParam, BTL_SICK_BIND) != 0 && BTL_POKEPARAM_HasSick(pokeParam, BTL_SICK_TRAPPED) != 0)
        BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
}




/* Teleport: keep the factor running and push the escape command. */
void HAND_WAZA_TeleportEscape(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        BTL_EVENT_KeepFactorRunning(factor);
        BTL_SERVER_FLOW_PushCmdRecord(flow, HAND_WAZA_KIND_ESCAPE, pokeId);
    }
}




/* Teleport: show the "but it failed" message. */
void HAND_WAZA_TeleportShowFailMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExMessage *messageRecord;

    if (BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1) != 0) {
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x2ff);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}




/* Fling getter: five handler rows. */
int *HAND_WAZA_GetFlingHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gFlingHandlers;
}




/* Fling: fails without a held item, without a Fling power, or in the listed battle situations. */
void HAND_WAZA_FlingCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId != BTL_EVENT_GetVar(HANDVAR_POKE_ID))
        return;
    {
        struct BtlPokeParam *pokeParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        u16 heldItem = (u32)BTL_POKEPARAM_GetItem(pokeParam);
        if (heldItem == 0 || BTL_CALC_GetItemParam(heldItem, ITEM_PARAM_FLING_POWER) == 0 || BTL_SERVER_FLOW_CanUseHeldItem(flow, pokeId) == 0
            || HAND_COMMON_IsHeldItemBoundToOwnSpecies(flow, pokeId) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
    }
}




/* Fling: the base power is the Fling power of the held item. */
void HAND_WAZA_FlingSetBasePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        u16 heldItem = (int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId));
        BTL_EVENT_OverwriteVar(BTL_EVAR_BASE_POWER, BTL_CALC_GetItemParam(heldItem, ITEM_PARAM_FLING_POWER));
    }
}




/* Fling: message that the user flung its item. */
void HAND_WAZA_FlingShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *pokeParam;
    u16 heldItem;
    struct HandExMessage *messageRecord;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    pokeParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    heldItem = (u32)BTL_POKEPARAM_GetItem(pokeParam);
    if (heldItem == 0)
        return;
    messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x30b);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), heldItem);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
}




/* Fling: remove the held item and, when the target is hit, use its effect on the target. */
void HAND_WAZA_FlingUseItemOnTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *pokeParam;
    u16 heldItem;
    struct HandExRemoveItem *removeItem;
    struct HandExUseItem *useItem;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    pokeParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    heldItem = (u32)BTL_POKEPARAM_GetItem(pokeParam);
    if (heldItem == 0)
        return;
    removeItem = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_REMOVE_ITEM, pokeId);
    removeItem->consumeKind = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, removeItem);
    *work = 1;
    if (BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE) == 0 && BTL_EVENT_GetVar(BTL_EVAR_MOVE_BLOCKED) == 0
        && BTL_CALC_GetItemParam(heldItem, ITEM_PARAM_FLING_EFFECT) != 0) {
        useItem = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_USE_ITEM, pokeId);
        useItem->targetId = BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID);
        useItem->itemId = heldItem;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, useItem);
    }
}




/* Fling: when the effect did not remove the item yet (work still 0), remove it after the move. */
void HAND_WAZA_FlingRemoveItemAfterMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *pokeParam;
    struct HandExRemoveItem *removeItem;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_POKE_ID))
        return;
    if (*work != 0)
        return;
    pokeParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if ((u16)(u32)BTL_POKEPARAM_GetItem(pokeParam) != 0) {
        removeItem = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_REMOVE_ITEM, pokeId);
        removeItem->consumeKind = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, removeItem);
    }
}




/* Magnet Rise getter: two handler rows. */
int *HAND_WAZA_GetMagnetRiseHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gMagnetRiseHandlers;
}




/* Magnet Rise: fails while the user is rooted or already floating. */
void HAND_WAZA_MagnetRiseCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *pokeParam;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID)) {
        pokeParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_HasSick(pokeParam, BTL_SICK_INGRAIN) != 0 || BTL_POKEPARAM_HasSick(pokeParam, BTL_SICK_FLOATING_BLOCK) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
    }
}




/* Magnet Rise: float the user for five turns and announce it. */
void HAND_WAZA_MagnetRiseAddFloating(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExAddSickAnnounce *addSick;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
    addSick->pokeId = pokeId;
    addSick->sickKind = BTL_SICK_MAGNET_RISE;
    addSick->sickCont = BTL_SICKCONT_MakeKind2Index(MAGNET_RISE_TURNS);
    BTL_SERVER_FLOW_InitMsgRecord(&addSick->message, HANDEX_MESSAGE_SET, 0x292);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&addSick->message), pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
}




/* Helping Hand getter: five handler rows. */
int *HAND_WAZA_GetHelpingHandHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gHelpingHandHandlers;
}




/* Helping Hand: set the generic result flag for the user (event 0x1c). */
void HAND_WAZA_HelpingHandSetGenericFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1);
}




/* Helping Hand: clear the protect bypass variable for the user (event 0x99). */
void HAND_WAZA_HelpingHandClearProtectBypass(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_PROTECT_BYPASS, 0);
}




/*
 * Helping Hand: needs a second Pokemon on the field; when the target ally is
 * still able and has not acted, announce the help, remember the ally in the
 * work slot and mark this factor dead. The factor is used last because the
 * factor and the work pointer both live on the stack here.
 */
void HAND_WAZA_HelpingHandAssistAlly(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    struct BtlPokeParam *targetParam;
    struct HandExMessage *messageRecord;

    if ((u32)BTL_SERVER_FLOW_GetActivePosPerSide(flow) <= 1)
        return;
    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    targetId = (u8)BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
    targetParam = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
    if (BTL_POKEPARAM_IsFainted(targetParam) != 0)
        return;
    if (BTL_POKEPARAM_TestTurnFlag(targetParam, BTL_TURN_FLAG_ACTED) != 0)
        return;
    messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x414);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), targetId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    *work = targetId;
    BTL_EVENT_MarkFactorDead(factor);
}




/* Helping Hand: the helped Pokemon (kept in the work slot) hits 1.5 times harder. */
void HAND_WAZA_HelpingHandBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (*work == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, 3 << 11);
}




/* Helping Hand: remove the factor at the end of the turn. */
void HAND_WAZA_HelpingHandRemoveAtTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID))
        BTL_EVENT_RemoveFactor(factor);
}




/* Beat Up getter: two handler rows. */
int *HAND_WAZA_GetBeatUpHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBeatUpHandlers;
}




/* Beat Up: one hit for each able party member (at least one), and restart the member cursor. */
void HAND_WAZA_BeatUpSetHitCount(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    int hitCount;
    u32 partyIndex;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    hitCount = 0;
    for (partyIndex = 0; partyIndex < BEAT_UP_PARTY_SLOTS; partyIndex++) {
        if (HAND_WAZA_FindBeatUpMember(flow, pokeId, partyIndex) != 0)
            hitCount++;
    }
    if (hitCount == 0)
        hitCount = 1;
    BTL_EVENT_OverwriteVar(BTL_EVAR_HIT_COUNT, hitCount);
    *work = 0;
}




/* Beat Up: the power of each hit comes from the base Attack of the next able member. */
void HAND_WAZA_BeatUpSetBasePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *attackerParam;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    attackerParam = HAND_WAZA_FindBeatUpMember(flow, pokeId, *work);
    if (attackerParam == 0)
        attackerParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    *work = *work + 1;
    if (*work >= BEAT_UP_PARTY_SLOTS)
        *work = 0;
    BTL_EVENT_OverwriteVar(BTL_EVAR_BASE_POWER, (u32)BTL_POKEPARAM_GetValue(attackerParam, BPP_VALUE_BASE_ATTACK) / 10 + 5);
}




/* Beat Up: the index-th party member that takes part (the user itself, or an able member without a status). */
struct BtlPokeParam *HAND_WAZA_FindBeatUpMember(struct BtlServerFlow *flow, u32 pokeId, u8 index)
{
    struct BtlParty *party;
    u32 partySize;
    u32 partyIndex;
    struct BtlPokeParam *member;
    int takesPart;

    party = (struct BtlParty *)BTL_SERVER_FLOW_GetPartyOfPoke(flow, pokeId);
    partySize = BTL_SLOT_GetCount((struct BtlSideSlot *)party);
    if (index >= partySize)
        return 0;
    for (partyIndex = 0; partyIndex < partySize; partyIndex++) {
        takesPart = 0;
        member = BTL_SLOT_GetPokeParam((struct BtlSideSlot *)party, (u8)partyIndex);
        if (pokeId == BTL_POKEPARAM_GetPokeId(member))
            takesPart = 1;
        else if (BTL_POKEPARAM_IsAbleToBattle(member) != 0 && BTL_POKEPARAM_GetMajorStatusIndex(member) == 0)
            takesPart = 1;
        if (takesPart != 0) {
            if (index == 0)
                return member;
            index = index - 1;
        }
    }
    return 0;
}




/* Fake Out getter: one handler row. */
int *HAND_WAZA_GetFakeOutHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gFakeOutHandlers;
}




/* Fake Out: fails unless it is the first turn since the user came in. */
void HAND_WAZA_FakeOutCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID)) {
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), 0) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
    }
}




/* Morning Sun, Synthesis and Moonlight getter: one handler row. */
int *HAND_WAZA_GetWeatherHealHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWeatherHealHandlers;
}



/* Weather ids as BTL_SERVER_FLOW_GetEffectiveWeatherThunk returns them. */


/* Morning Sun, Synthesis and Moonlight: the heal ratio (4096 based) depends on the weather. */
void HAND_WAZA_WeatherHealSetRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    int healRatio;
    if (pokeId != BTL_EVENT_GetVar(HANDVAR_POKE_ID))
        return;
    switch (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow)) {
    case BTL_WEATHER_SUN:
        healRatio = 0xaac;
        break;
    case BTL_WEATHER_RAIN:
    case BTL_WEATHER_SAND:
    case BTL_WEATHER_HAIL:
        healRatio = 2 << 9;
        break;
    default:
        healRatio = 2 << 10;
        break;
    }
    BTL_EVENT_OverwriteVar(BTL_EVAR_HEAL_RATIO, healRatio);
}




/* Fly getter: two handler rows. */
int *HAND_WAZA_GetFlyHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gFlyHandlers;
}




/* Fly, first turn: the user rises into the air (continuing flag and message). */
void HAND_WAZA_FlyBeginFlight(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExSetContFlag *setContFlag;
    struct HandExMessage *messageRecord;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    setContFlag = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_CONT_FLAG, pokeId);
    setContFlag->pokeId = pokeId;
    setContFlag->contFlag = BTL_CONT_FLAG_FLYING;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, setContFlag);
    messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x211);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
}




/* Fly: nothing to do on this event. */
void HAND_WAZA_FlyChargeEndNoOp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
}




/* Shadow Force getter: five handler rows. */
int *HAND_WAZA_GetShadowForceHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gShadowForceHandlers;
}




/* Shadow Force, first turn: the user vanishes (continuing flag and message). */
void HAND_WAZA_ShadowForceBeginVanish(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExSetContFlag *setContFlag;
    struct HandExMessage *messageRecord;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        setContFlag = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_CONT_FLAG, pokeId);
        setContFlag->pokeId = pokeId;
        setContFlag->contFlag = BTL_CONT_FLAG_SHADOW_FORCE;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, setContFlag);
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x21d);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}





/* Shadow Force: nothing to do on this event. */
void HAND_WAZA_ShadowForceChargeEndNoOp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
}





/* Shadow Force: when the target is protected, break the protection and say so. */
void HAND_WAZA_ShadowForceBreakProtect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExClearTurnFlag *clearTurnFlag;
    struct HandExMessage *messageRecord;
    u8 targetId;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        if (BTL_POKEPARAM_TestTurnFlag(BTL_SERVER_FLOW_GetPokeParam(flow, targetId), BTL_TURN_FLAG_PROTECTED) != 0) {
            clearTurnFlag = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_CLEAR_TURN_FLAG, pokeId);
            clearTurnFlag->pokeId = targetId;
            clearTurnFlag->turnFlag = BTL_TURN_FLAG_PROTECTED;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, clearTurnFlag);
            messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x208);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&messageRecord->message), targetId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
        }
    }
}





/* Bounce getter: two handler rows. */
int *HAND_WAZA_GetBounceHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBounceHandlers;
}



/* Bounce: on the charge turn, mark the user as airborne and print the charge message. */
void HAND_WAZA_BounceOnChargeTurn(int factor, void *flow, u32 pokeId)
{
    struct HandWazaStateRecord *state;
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        state = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_SET_STATE, pokeId);
        state->pokeId = pokeId;
        state->state = 3;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, state);
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x220);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&msg->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}



/* Bounce: handler of the event that follows the charge turn; it does nothing. */
void HAND_WAZA_BounceNoOp(void)
{
}



/* Dive: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddDive(int *handlerCount)
{
    *handlerCount = 2;
    return gDiveHandlers;
}



/* Dive: on the charge turn, mark the user as underwater and print the charge message. */
void HAND_WAZA_DiveOnChargeTurn(int factor, void *flow, u32 pokeId)
{
    struct HandWazaStateRecord *state;
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        state = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_SET_STATE, pokeId);
        state->pokeId = pokeId;
        state->state = 4;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, state);
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x217);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&msg->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}



/* Dive: handler of the event that follows the charge turn; it does nothing. */
void HAND_WAZA_DiveNoOp(void)
{
}



/* Dig: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddDig(int *handlerCount)
{
    *handlerCount = 2;
    return gDigHandlers;
}



/* Dig: on the charge turn, mark the user as underground and print the charge message. */
void HAND_WAZA_DigOnChargeTurn(int factor, void *flow, u32 pokeId)
{
    struct HandWazaStateRecord *state;
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        state = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_SET_STATE, pokeId);
        state->pokeId = pokeId;
        state->state = 5;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, state);
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x21a);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&msg->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}



/* Dig: handler of the event that follows the charge turn; it does nothing. */
void HAND_WAZA_DigNoOp(void)
{
}



/* Solar Beam: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddSolarBeam(int *handlerCount)
{
    *handlerCount = 3;
    return gSolarBeamHandlers;
}



/* Solar Beam: in sunshine the charge turn is skipped. */
void HAND_WAZA_SolarBeamSkipChargeInSun(int factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_SUN)
        BTL_EVENT_OverwriteVar(WAZAVAR_SKIP_FLAG, 1);
}



/* Solar Beam: on the charge turn, print the charge message. */
void HAND_WAZA_SolarBeamOnChargeTurn(int factor, void *flow, int pokeId)
{
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x229);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&msg->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}



/* Solar Beam: in rain, hail or sandstorm the power is halved. */
void HAND_WAZA_SolarBeamHalvePowerInBadWeather(int factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID) && (u8)(BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) + 254) <= 2)
        BTL_EVENT_MultiplyVar(WAZAVAR_POWER_RATIO, 2 << 10);
}



/* Razor Wind: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddRazorWind(int *handlerCount)
{
    *handlerCount = 1;
    return gRazorWindHandlers;
}



/* Razor Wind: on the charge turn, print the charge message. */
void HAND_WAZA_RazorWindOnChargeTurn(int factor, void *flow, u32 pokeId)
{
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x223);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&msg->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}



/* Sky Attack: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddSkyAttack(int *handlerCount)
{
    *handlerCount = 1;
    return gSkyAttackHandlers;
}



/* Sky Attack: on the charge turn, print the charge message. */
void HAND_WAZA_SkyAttackOnChargeTurn(int factor, void *flow, u32 pokeId)
{
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x226);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&msg->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}



/* Skull Bash: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddSkullBash(int *handlerCount)
{
    *handlerCount = 1;
    return gSkullBashHandlers;
}



/* Skull Bash: on the charge turn, print the charge message and raise the user's Defense. */
void HAND_WAZA_SkullBashOnChargeTurn(int factor, void *flow, u32 pokeId)
{
    struct HandWazaMessageRecord *msg;
    struct HandWazaRankRecord *rank;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x22c);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&msg->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        rank = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_RANK_EFFECT, pokeId);
        rank->pokeCount = 1;
        rank->pokeId = pokeId;
        rank->rankKind = BTL_RANK_DEFENSE;
        rank->volume = 1;
        rank->flagB = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rank);
    }
}



/* Pluck and Bug Bite: returns the handler table of the moves (the registry getter). */
int *HAND_WAZA_AddPluck(int *handlerCount)
{
    *handlerCount = 1;
    return gPluckHandlers;
}



/* Pluck and Bug Bite: eat the target berry and apply its effect to the user. */
void HAND_WAZA_PluckEatTargetBerry(int factor, void *flow, u32 pokeId)
{
    struct HandWazaConsumeItemRecord *consume;
    struct HandWazaItemEffectRecord *effect;
    u8 targetId;
    u16 itemId;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(WAZAVAR_ITEM_SLOT);
        itemId = (int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, targetId));
        if (ITEM_IsBerry(itemId) != 0) {
            consume = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_CONSUME_ITEM, pokeId);
            consume->pokeId = targetId;
            consume->flags = 0;
            BTL_SERVER_FLOW_InitMsgRecord(&consume->message, 2, 0x308);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&consume->message), pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&consume->message), itemId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, consume);
            effect = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_ITEM_EFFECT, pokeId);
            effect->header |= 2 << 23;
            effect->itemId = itemId;
            effect->pokeId = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, effect);
        }
    }
}



/* Struggle: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddStruggle(int *handlerCount)
{
    *handlerCount = 3;
    return gStruggleHandlers;
}



/* Struggle: set the skip flag (guess: the move never needs PP checking). */
void HAND_WAZA_StruggleSetSkipFlag(int factor, int flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(WAZAVAR_SKIP_FLAG, 1);
}



/* Struggle: print the message that the Pokemon has no moves left. */
void HAND_WAZA_StruggleShowNoMovesMessage(int factor, void *flow, int pokeId)
{
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x344);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&msg->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}



/* Struggle: set event flag 0x4b (guess: the move skips the usual accuracy or type checks). */
void HAND_WAZA_StruggleSetFlag4B(int factor, int flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(0x4b, 1);
}



/* Destiny Bond: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddDestinyBond(int *handlerCount)
{
    *handlerCount = 3;
    return gDestinyBondHandlers;
}



/* Destiny Bond: when used, print the message and arm the effect in the work area. */
void HAND_WAZA_DestinyBondOnUse(int factor, void *flow, u32 pokeId, u32 *work)
{
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x272);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&msg->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        work[6] = 1;
    }
}



/* Destiny Bond and Grudge: the effect ends when the user acts again. */
void HAND_WAZA_RemoveOnUserAction(struct BtlEventNode *factor, int flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID))
        BTL_EVENT_RemoveFactor((struct BtlEventFactor *)factor);
}



/* Destiny Bond: when the user faints from an attack, the attacker faints too. */
void HAND_WAZA_DestinyBondOnFaint(int factor, void *flow, u32 pokeId)
{
    struct HandWazaKillRecord *kill;
    void *attacker;
    u8 attackerId;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_DEFENDER_ID)) {
        if (BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) != 0) {
            if (BTL_ID_IsMetronomeItemIgnoredMove((u16)BTL_EVENT_GetVar(WAZAVAR_MOVE_ID)) == 0) {
                attackerId = BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID);
                attacker = BTL_SERVER_FLOW_GetPokeParam(flow, attackerId);
                if (BTL_MAIN_IsPokeSamePair(pokeId, attackerId) == 0 && BTL_POKEPARAM_IsFainted(attacker) == 0) {
                    BTL_EVENT_MarkFactorDead((struct BtlEventFactor *)(u8 *)factor);
                    kill = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_KILL, pokeId);
                    kill->pokeId = pokeId;
                    kill->flag = 1;
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, kill);
                    kill = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_KILL, pokeId);
                    kill->pokeId = BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID);
                    BTL_SERVER_FLOW_InitMsgRecord(&kill->message, 2, 0x275);
                    BTL_SERVER_FLOW_AppendMsgRecordArg((&kill->message), pokeId);
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, kill);
                }
            }
            BTL_EVENT_RemoveFactor((struct BtlEventFactor *)factor);
        }
    }
}



/* Grudge: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddGrudge(int *handlerCount)
{
    *handlerCount = 3;
    return gGrudgeHandlers;
}



/* Grudge: when used, print the message and arm the effect in the work area. */
void HAND_WAZA_GrudgeOnUse(int factor, void *flow, u32 pokeId, u32 *work)
{
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x278);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&msg->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        work[6] = 1;
    }
}



/*
 * Grudge: when the user faints from an attack, the PP of the move that
 * finished it drops to zero.
 *
 * lever: Callback kind 10 is reused as the multiplier, then decreased by 11;
 * this retains the live constant and reproduces the spill frame and muls.
 */
void HAND_WAZA_GrudgeOnFaint(void *factor, void *flow, int pokeId)
{
    u8 attackerId;
    void *attacker;
    u16 moveId;
    int slot;
    struct HandWazaPpRecord *pp;
    int multiplier;
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_DEFENDER_ID)) {
        if (BTL_ID_IsMetronomeItemIgnoredMove((u16)BTL_EVENT_GetVar(18)) == 0) {
            if (BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) != 0) {
                attackerId = BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID);
                attacker = BTL_SERVER_FLOW_GetPokeParam(flow, attackerId);
                moveId = BTL_EVENT_GetVar(20);
                slot = BTL_POKEPARAM_FindMoveSlot(attacker, moveId);
                if (slot != BTL_MOVE_SLOT_NONE) {
                    multiplier = 10;
                    pp = BTL_SERVER_FLOW_AllocCmdRecord(flow, multiplier, pokeId);
                    pp->pokeId = attackerId;
                    pp->slot = slot;
                    multiplier -= 11;
                    pp->amount = BTL_POKEPARAM_GetMovePPChecked(attacker, (u8)slot) * multiplier;
                    pp->flags |= 2;
                    BTL_SERVER_FLOW_InitMsgRecord(&pp->message, 2, 0x27b);
                    BTL_SERVER_FLOW_AppendMsgRecordArg((&pp->message), attackerId);
                    BTL_SERVER_FLOW_AppendMsgRecordArg((&pp->message), moveId);
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, pp);
                }
                BTL_EVENT_RemoveFactor((struct BtlEventFactor *)factor);
            }
        }
    }
}



/* Minimize: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddMinimize(int *handlerCount)
{
    *handlerCount = 1;
    return gMinimizeHandlers;
}



/* Minimize: mark the user as minimized. */
void HAND_WAZA_MinimizeSetState(int factor, void *flow, int pokeId)
{
    struct HandWazaStateRecord *state;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        state = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_SET_STATE, pokeId);
        state->pokeId = pokeId;
        state->state = 8;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, state);
    }
}



/* Defense Curl: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddDefenseCurl(int *handlerCount)
{
    *handlerCount = 1;
    return gDefenseCurlHandlers;
}



/* Defense Curl: mark the user as curled up. */
void HAND_WAZA_DefenseCurlSetState(int factor, void *flow, int pokeId)
{
    struct HandWazaStateRecord *state;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        state = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_SET_STATE, pokeId);
        state->pokeId = pokeId;
        state->state = 7;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, state);
    }
}



/* Roost: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddRoost(int *handlerCount)
{
    *handlerCount = 1;
    return gRoostHandlers;
}



/* Roost: add the status that removes the Flying type for the turn. */
void HAND_WAZA_RoostGroundFlyingType(int factor, void *flow, int pokeId)
{
    struct HandExAddSick *addSick;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_ADD_SICK, pokeId);
        addSick->pokeId = pokeId;
        addSick->fromMove = 1;
        addSick->sickKind = SICK_ROOST_GROUNDED;
        addSick->sickCont = BTL_SICKCONT_MakeKind2(1, 2);
        BTL_SICKCONT_SetFlag(&addSick->sickCont, 1);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
    }
}



/* Focus Punch: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddFocusPunch(int *handlerCount)
{
    *handlerCount = 1;
    return gFocusPunchHandlers;
}



/* Focus Punch: at the start of the turn, show the tensing animation and message. */
void HAND_WAZA_FocusPunchTense(int factor, void *flow, int pokeId)
{
    struct HandWazaStateRecord *state;
    struct HandWazaAnimRecord *anim;
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        state = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_VISIBILITY, pokeId);
        state->pokeId = pokeId;
        state->state = BTL_VISIBILITY_FOCUS;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, state);
        if (BTL_POKEPARAM_IsSemiInvulnerable(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) == 0) {
            anim = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_ANIMATION, pokeId);
            anim->animId = BTL_ANIM_FOCUS_PUNCH_TENSE;
            anim->target = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
            anim->mode = BTL_ANIM_MODE_PLAY;
            anim->flag = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, anim);
        }
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x268);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&msg->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}



/* Metronome: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddMetronome(int *handlerCount)
{
    *handlerCount = 2;
    return gMetronomeWazaHandlers;
}



/* Metronome: pick a random move other than the previous one and use it. */
void HAND_WAZA_MetronomePickMove(int factor, int flow, int pokeId)
{
    u32 previousMove;
    u16 moveId;
    int slot;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        moveId = BTL_CALC_PickRandomMoveExcluding((u16 *)BTL_ID_GetMetronomeExcludedMoves((s32 *)(&previousMove)), (u16)previousMove);
        slot = BTL_SERVER_FLOW_DecideMoveTarget((struct BtlServerFlow *)flow, pokeId, moveId);
        BTL_EVENT_OverwriteVar(WAZAVAR_MOVE_ID, moveId);
        BTL_EVENT_OverwriteVar(WAZAVAR_MOVE_SLOT, slot);
    }
}



/* Metronome: print the message that the move cannot be called, and fail it. */
void HAND_WAZA_MetronomeSetFailMessage(int factor, int flow, int pokeId)
{
    void *message;
    u16 moveId;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        message = (void *)BTL_EVENT_GetVar(WAZAVAR_FAIL_MESSAGE);
        moveId = BTL_EVENT_GetVar(WAZAVAR_MOVE_ID);
        BTL_SERVER_FLOW_InitMsgRecord(message, 1, 0x78);
        BTL_SERVER_FLOW_AppendMsgRecordArg(message, moveId);
        BTL_EVENT_OverwriteVar(WAZAVAR_SKIP_FLAG, 1);
    }
}



/* Nature Power: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddNaturePower(int *handlerCount)
{
    *handlerCount = 2;
    return gNaturePowerHandlers;
}



/*
 * Nature Power: pick the move to call from the terrain of the battle field.
 *
 * 16-case jump table on BTL_SERVER_FLOW_GetFieldSituationType(flow), gated on pokeId == BTL_EVENT_GetVar(2);
 * every value 0..15 is covered by eight bodies sitting at 6B66, 6B6A, 6B6E,
 * 6B72, 6B76, 6B7A, 6B7E, 6B82 -- that is the order they are written in
 * below.  Each body picks a move id (0x192 and 0x1aa come out of the pool
 * because they do not fit a movs); the id goes to BTL_SERVER_FLOW_DecideMoveTarget and to
 * BTL_EVENT_OverwriteVar(0x12,...), and BTL_SERVER_FLOW_DecideMoveTarget's result to BTL_EVENT_OverwriteVar(0xd,...).
 *
 * The `default:` label belongs on the case 4/14 group, not on a block of its
 * own: the `bhi` out-of-range arm of the table jumps to 6B6A, which is that
 * group's body, and the out-of-range arm being a real body is also what puts
 * the switch's temporary in r5 and the parameter flow in r4 (mwcc allocates r4 to
 * the first web the dispatch block defines).  `default:` as a separate group
 * costs 40 bytes of diff; without it at all the `bhi` lands on the shared tail.
 */
void HAND_WAZA_NaturePowerPickMove(int factor, int flow, int pokeId)
{
    u16 moveId;
    int slot;

    if (BTL_EVENT_GetVar(WAZAVAR_POKE_ID) != pokeId)
        return;
    switch (BTL_SERVER_FLOW_GetFieldSituationType((struct BtlServerFlow *)flow)) {
    case 1: case 2: case 3: case 8: case 15:
        moveId = 0x59;
        break;
    case 4: case 14: default:
        moveId = 0xa1;
        break;
    case 10:
        moveId = 0x9d;
        break;
    case 0: case 5:
        moveId = 0x192;
        break;
    case 6: case 11: case 12:
        moveId = 0x38;
        break;
    case 9:
        moveId = 0x1aa;
        break;
    case 7:
        moveId = 0x3b;
        break;
    case 13:
        moveId = 0x3a;
        break;
    }
    slot = BTL_SERVER_FLOW_DecideMoveTarget((struct BtlServerFlow *)flow, pokeId, moveId);
    BTL_EVENT_OverwriteVar(WAZAVAR_MOVE_ID, moveId);
    BTL_EVENT_OverwriteVar(WAZAVAR_MOVE_SLOT, slot);
}



/* Nature Power: print the message that the move cannot be called, and fail it. */
void HAND_WAZA_NaturePowerSetFailMessage(int factor, int flow, int pokeId)
{
    void *message;
    u16 moveId;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        message = (void *)BTL_EVENT_GetVar(WAZAVAR_FAIL_MESSAGE);
        moveId = BTL_EVENT_GetVar(WAZAVAR_MOVE_ID);
        BTL_SERVER_FLOW_InitMsgRecord(message, 1, 0x79);
        BTL_SERVER_FLOW_AppendMsgRecordArg(message, moveId);
        BTL_EVENT_OverwriteVar(WAZAVAR_SKIP_FLAG, 1);
    }
}



/* Assist: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddAssist(int *handlerCount)
{
    *handlerCount = 1;
    return gAssistHandlers;
}



/*
 * Assist: collect the callable moves of the other party members and use one
 * of them at random.
 *
 * lever: Both loop bounds and their accessor returns are u8; u32 n loses
 * its pre-loop reload, and u32 count schedules its reload before i's spill.
 */
void HAND_WAZA_AssistPickMove(void *factor, void *flow, int pokeId)
{
    void *party;
    u16 *moves;
    u8 partyCount;
    u8 memberIndex;
    u8 moveCount;
    u8 candidateCount, slot;
    void *member;
    u16 moveId;
    u8 pick;
    int moveSlot;
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        party = (struct BtlParty *)BTL_SERVER_FLOW_GetPartyOfPoke(flow, pokeId);
        moves = (u16 *)BTL_SERVER_FLOW_GetScratchBuffer(flow, 48);
        candidateCount = 0;
        partyCount = BTL_SLOT_GetCount(party);
        for (memberIndex = 0; memberIndex < partyCount; memberIndex++) {
            member = BTL_SLOT_GetPokeParam(party, memberIndex);
            if (pokeId != BTL_POKEPARAM_GetPokeId(member)) {
                moveCount = BTL_POKEPARAM_GetMoveCount(member);
                for (slot = 0; slot < moveCount; slot++) {
                    moveId = BTL_POKEPARAM_GetMoveId(member, slot);
                    if (BTL_ID_IsAssistExcludedMove(moveId) == 0) {
                        moves[candidateCount++] = moveId;
                    }
                }
            }
        }
        if (candidateCount != 0) {
            pick = BTL_CALC_Random(candidateCount);
            moveSlot = BTL_SERVER_FLOW_DecideMoveTarget((struct BtlServerFlow *)flow, pokeId, moves[pick]);
            BTL_EVENT_OverwriteVar(18, moves[pick]);
            BTL_EVENT_OverwriteVar(13, moveSlot);
        }
    }
}



/* Sleep Talk: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddSleepTalk(int *handlerCount)
{
    *handlerCount = 3;
    return gSleepTalkHandlers;
}



/* Sleep Talk: while asleep, pick one of the user's other moves at random. */
void HAND_WAZA_SleepTalkPickMove(int factor, int flow, int pokeId, u32 *candidates)
{
    void *user;
    u8 moveCount;
    u8 candidateCount;
    u8 slot;
    u16 candidate;
    int sickSleep = 2;
    u16 moveId;
    int moveSlot;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        user = BTL_SERVER_FLOW_GetPokeParam((struct BtlServerFlow *)flow, pokeId);
        if (BTL_POKEPARAM_HasSick(user, sickSleep) != 0) {
            moveCount = BTL_POKEPARAM_GetMoveCount(user);
            slot = 0;
            candidateCount = 0;
            for (; slot < moveCount; slot++) {
                candidate = BTL_POKEPARAM_GetMoveId(user, slot);
                if (BTL_ID_IsSleepTalkExcludedMove(candidate) == 0 && WAZA_TOOL_GetFlag(candidate, 1) == 0) {
                    candidates[candidateCount++] = candidate;
                }
            }
            if (candidateCount != 0) {
                moveId = candidates[(u8)BTL_CALC_Random(candidateCount)];
                moveSlot = BTL_SERVER_FLOW_DecideMoveTarget((struct BtlServerFlow *)flow, pokeId, moveId);
                BTL_EVENT_OverwriteVar(0x12, moveId);
                BTL_EVENT_OverwriteVar(0xd, moveSlot);
            } else {
                BTL_EVENT_OverwriteVar(WAZAVAR_FAIL_FLAG, 1);
            }
        }
    }
}



/* Mirror Move: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddMirrorMove(int *handlerCount)
{
    *handlerCount = 1;
    return gMirrorMoveHandlers;
}



/* Mirror Move: use the move that the target used last, if it can be mirrored. */
void HAND_WAZA_MirrorMovePickMove(int factor, int flow, int pokeId, u8 *targetPokeId)
{
    u8 targetSlot;
    u16 lastMove;
    u32 targetFlags;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        targetSlot = BTL_EVENT_GetVar(WAZAVAR_TARGET_SLOT);
        if (targetSlot == BTL_TARGET_SLOT_NONE) {
            targetFlags = BTL_SERVER_FLOW_GetFrontPosOfPoke((struct BtlServerFlow *)flow, pokeId);
            targetSlot = BTL_MAIN_GetEnemyLanePos(BTL_SERVER_FLOW_GetRule((struct BtlServerFlow *)flow), targetFlags, 0);
        }
        if (BTL_SERVER_FLOW_CollectAlivePokeIds((struct BtlServerFlow *)flow, targetSlot, targetPokeId) != 0) {
            lastMove = BTL_POKEPARAM_GetLastUsedMoveId(BTL_SERVER_FLOW_GetPokeParam((struct BtlServerFlow *)flow, *targetPokeId));
            if (lastMove == 0 || WAZA_TOOL_GetFlag(lastMove, BTL_WAZA_FLAG_MIRRORABLE) == 0) {
                BTL_EVENT_OverwriteVar(WAZAVAR_FAIL_FLAG, 1);
                return;
            }
            BTL_EVENT_OverwriteVar(WAZAVAR_MOVE_ID, lastMove);
            BTL_EVENT_OverwriteVar(WAZAVAR_MOVE_SLOT, targetSlot);
        }
    }
}



/* Me First: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddMeFirst(int *handlerCount)
{
    *handlerCount = 2;
    return gMeFirstHandlers;
}



/*
 * Me First: use the damaging move that the target chose for this turn, if
 * the target has not acted yet.
 *
 * extent: 202 bytes of code followed by 2-byte alignment nop at 021E6F02,
 * then the labelled Thumb veneer BTL_ID_IsMeFirstFailMove.
 */
void HAND_WAZA_MeFirstPickMove(void *factor, void *flow, int pokeId, u8 *targetPokeId)
{
    u8 targetSlot;
    u8 targetId;
    u32 targetFlags;
    u32 action;
    u32 moveId;
    int usable;
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        targetSlot = BTL_EVENT_GetVar(WAZAVAR_TARGET_SLOT);
        if (targetSlot == BTL_TARGET_SLOT_NONE) {
            targetFlags = BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, pokeId);
            targetSlot = BTL_MAIN_GetEnemyLanePos(BTL_SERVER_FLOW_GetRule(flow), targetFlags, 0);
        }
        if (BTL_SERVER_FLOW_CollectAlivePokeIds(flow, targetSlot, targetPokeId) != 0) {
            void *target;
            target = BTL_SERVER_FLOW_GetPokeParam(flow, *targetPokeId);
            targetId = *targetPokeId;
            usable = 0;
            if (BTL_POKEPARAM_TestTurnFlag(target, BTL_TURN_FLAG_ACTION_TAKEN) == 0) {
                if (BTL_SERVER_FLOW_GetActionWordByPokeId(flow, targetId, &action) != 0) {
                    if (BTL_SERVER_FLOW_IsPokeInPosTable(flow, targetId) != 0) {
                        if (BTL_SERVER_FLOW_IsPokeAfflictedByStatus(flow, targetId) == 0) {
                            moveId = BTL_ACTION_GetFightMove((union BtlAction *)(&action));
                            if (moveId != 0 && WAZA_TOOL_IsDamaging(moveId) != 0 && BTL_ID_IsMeFirstFailMove(moveId) == 0)
                                usable = 1;
                        }
                    }
                }
            }
            if (usable != 0) {
                BTL_EVENT_OverwriteVar(18, moveId);
                BTL_EVENT_OverwriteVar(13, targetSlot);
                return;
            }
        }
        BTL_EVENT_OverwriteVar(65, 1);
    }
}



/* Me First: raise the power of the called move by half. */
void HAND_WAZA_MeFirstBoostPower(int factor, int flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID))
        BTL_EVENT_MultiplyVar(WAZAVAR_POWER_RATIO, 3 << 11);
}



/* Copycat: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddCopycat(int *handlerCount)
{
    *handlerCount = 1;
    return gCopycatHandlers;
}



/* Copycat: use the move that was used last in the battle, if it can be copied. */
void HAND_WAZA_CopycatPickMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u16 moveId;
    int slot;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        moveId = BTL_SERVER_FLOW_GetLastActionId(flow);
        if (moveId != 0 && BTL_ID_IsCopycatExcludedMove(moveId) == 0) {
            slot = BTL_SERVER_FLOW_DecideMoveTarget((struct BtlServerFlow *)flow, pokeId, moveId);
            BTL_EVENT_OverwriteVar(WAZAVAR_MOVE_ID, moveId);
            BTL_EVENT_OverwriteVar(WAZAVAR_MOVE_SLOT, slot);
        }
    }
}



/* Ancient Power, Silver Wind and Ominous Wind: returns the handler table (the registry getter). */
int *HAND_WAZA_AddAllStatBoostChance(int *handlerCount)
{
    *handlerCount = 1;
    return gAllStatBoostChanceHandlers;
}



/* Ancient Power, Silver Wind and Ominous Wind: the all-stats boost has a 10 percent chance. */
void HAND_WAZA_AllStatBoostSetChance(int factor, int flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_DEFENDER_ID) && pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(WAZAVAR_SECONDARY_RATE, 10);
}



/* Venoshock: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddVenoshock(int *handlerCount)
{
    *handlerCount = 1;
    return gVenoshockHandlers;
}



/* Venoshock: double the power when the target is poisoned. */
void HAND_WAZA_VenoshockDoublePowerOnPoison(int factor, int flow, int pokeId)
{
    int ratioShift = 4;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam((struct BtlServerFlow *)flow, (u8)BTL_EVENT_GetVar(WAZAVAR_DEFENDER_ID)), BTL_SICK_POISON) != 0) {
            BTL_EVENT_MultiplyVar(WAZAVAR_POWER_RATIO, ratioShift << 11);
        }
    }
}



/* Hex: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddHex(int *handlerCount)
{
    *handlerCount = 1;
    return gHexHandlers;
}


/* Hex: double the power when the target has a major status condition. */
void HAND_WAZA_HexDoublePowerOnStatus(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))) != 0) {
            HAND_COMMON_EventScaleDamage(2);
        }
    }
}


/* Acrobatics: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddAcrobatics(int *handlerCount)
{
    *handlerCount = 1;
    return gAcrobaticsHandlers;
}


/* Acrobatics: double the power when the user holds no item. */
void HAND_WAZA_AcrobaticsDoublePowerWithoutItem(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) == 0)
            HAND_COMMON_EventScaleDamage(2);
    }
}


/* Stored Power: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddStoredPower(int *handlerCount)
{
    *handlerCount = 1;
    return gStoredPowerHandlers;
}


/*
 * Stored Power: add 20 power for each raised stat stage of the user (stage 6 is
 * neutral).  The bonus is a compound add onto the fetched value
 * (`power = get(0x30); power += sum * 0x14; set(0x30, power);`): it copies sum
 * into r1 and multiplies by 0x14 held in r0 like the image; every
 * single-expression spelling (`power + sum * 0x14`, an inline helper,
 * a narrow or enum multiplier local) multiplies in the constant's
 * register and is 4 bytes short.
 */
void HAND_WAZA_StoredPowerAddPowerPerStage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *user;
    int raisedStages;
    u32 i;
    int stage;
    int basePower;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        raisedStages = 0;
        for (i = 0; i < 7; i++) {
            stage = BTL_POKEPARAM_GetValue(user, gStoredPowerStatIds[i]) - 6;
            if (stage > 0) {
                raisedStages += stage;
            }
        }
        if (raisedStages != 0) {
            basePower = BTL_EVENT_GetVar(HAND_WAZA_EVAR_BASE_POWER);
            basePower += raisedStages * 0x14;
            BTL_EVENT_OverwriteVar(HAND_WAZA_EVAR_BASE_POWER, basePower);
        }
    }
}


/*
 * Heavy Slam and Heat Crash: returns the handler table of the move (the
 * registry getter).  This is the 12-byte store-and-return leaf after the pool
 * of the handler before it (twin of HAND_WAZA_AddEchoedVoice).
 */
int *HAND_WAZA_AddHeavySlam(int *handlerCount)
{
    *handlerCount = 1;
    return gHeavySlamHandlers;
}


/* Heavy Slam and Heat Crash: base power from the weight ratio of user to target (40 to 120). */
void HAND_WAZA_HeavySlamSetPowerByWeight(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *target;
    int userWeight;
    int targetWeight;
    int weightRatio;
    int basePower;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID));
        userWeight = BTL_SERVER_FLOW_CalcPokeWeight(flow, pokeId);
        targetWeight = BTL_SERVER_FLOW_CalcPokeWeight(flow, BTL_POKEPARAM_GetPokeId(target));
        weightRatio = userWeight / targetWeight;
        if (weightRatio >= 5) {
            basePower = 0x78;
        } else if (weightRatio == 4) {
            basePower = 0x64;
        } else if (weightRatio == 3) {
            basePower = 0x50;
        } else {
            basePower = 0x3c;
            if (weightRatio != 2) {
                basePower = 0x28;
            }
        }
        BTL_EVENT_OverwriteVar(HAND_WAZA_EVAR_BASE_POWER, basePower);
    }
}


/* Electro Ball: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddElectroBall(int *handlerCount)
{
    *handlerCount = 1;
    return gElectroBallHandlers;
}


/* Ability ids that these moves look at or set. */
#define HAND_WAZA_ABILITY_TRUANT 0x36


/* Value id of BTL_POKEPARAM_GetValue (the Pokemon value getter) that returns the ability. */
#define HAND_WAZA_BPP_VALUE_ABILITY 0x10


/* Type id of Water, packed twice into the type pair of the Soak record. */
#define HAND_WAZA_TYPE_WATER 10


/* Electro Ball: base power from the speed ratio of user to target (40 to 150). */
void HAND_WAZA_ElectroBallSetPowerBySpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    int userSpeed, targetSpeed, speedRatio, basePower;
    struct BtlPokeParam *userPoke, *targetPoke;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        userPoke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        targetPoke = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID));
        userSpeed = BTL_SERVER_FLOW_CalcPokeSpeedWrapper(flow, userPoke, 0);
        targetSpeed = BTL_SERVER_FLOW_CalcPokeSpeedWrapper(flow, targetPoke, 0);
        speedRatio = userSpeed / targetSpeed;
        if (speedRatio >= 4)
            basePower = 150;
        else if (speedRatio >= 3)
            basePower = 120;
        else if (speedRatio >= 2)
            basePower = 80;
        else {
            basePower = 60;
            if (speedRatio < 1)
                basePower = 40;
        }
        BTL_EVENT_OverwriteVar(HAND_WAZA_EVAR_BASE_POWER, basePower);
    }
}


/* Echoed Voice: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddEchoedVoice(int *handlerCount)
{
    *handlerCount = 1;
    return gEchoedVoiceHandlers;
}


/*
 * Echoed Voice: base power 40, 80, 120, 160, 200 for each turn in a row that the
 * move was used.  The decrement inside the call argument (`turn--`) is what puts the
 * `subs` before the result test; a `for (...; turn--)` step lands it after the branch.
 */
void HAND_WAZA_EchoedVoiceSetPowerByStreak(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    sptr turnRecord; int factorKey, turn, basePower;
    u32 streak;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        turnRecord = (sptr)BTL_SERVER_FLOW_GetTurnRecord(flow);
        factorKey = BTL_EVENT_GetFactorKey(factor);
        turn = BTL_SERVER_FLOW_GetTurnCount(flow) - 1;
        streak = 0;
        for (; turn >= 0;) {
            if ((struct BtlWazaRec *)BTL_WAZAREC_IsUsedWaza((struct BtlWazaRec *)turnRecord, factorKey, turn--) == 0)
                break;
            streak++;
        }
        switch (streak) {
        case 0: basePower = 0x28; break;
        case 1: basePower = 0x50; break;
        case 2: basePower = 0x78; break;
        case 3: basePower = 0xa0; break;
        default: basePower = 0xc8; break;
        }
        BTL_EVENT_OverwriteVar(HAND_WAZA_EVAR_BASE_POWER, basePower);
    }
}


/* Retaliate: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddRetaliate(int *handlerCount)
{
    *handlerCount = 1;
    return gRetaliateHandlers;
}


/* Retaliate: double the power when an ally of the user fainted on the previous turn. */
void HAND_WAZA_RetaliateDoublePowerAfterAllyFaint(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    sptr historyList;
    u32 faintCount;
    u8 i;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        historyList = (sptr)BTL_SERVER_FLOW_GetHistoryList(flow);
        faintCount = BTL_DEADREC_GetCount((struct BtlDeadRec *)historyList, 1);
        for (i = 0; i < faintCount; i++) {
            if (BTL_MAIN_IsPokeSamePair(pokeId, BTL_DEADREC_GetPokeId((struct BtlDeadRec *)historyList, 1, i)) != 0) {
                BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, 0x2000);
                return;
            }
        }
    }
}


/* Foul Play: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddFoulPlay(int *handlerCount)
{
    *handlerCount = 1;
    return gFoulPlayHandlers;
}


/* Foul Play: the damage formula reads the Attack of the target instead of the user. */
void HAND_WAZA_FoulPlayUseTargetAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 targetId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        BTL_EVENT_OverwriteVar(HAND_WAZA_EVAR_ATTACK_STAT_SOURCE_ID, targetId);
    }
}


/* Soak: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddSoak(int *handlerCount)
{
    *handlerCount = 1;
    return gSoakHandlers;
}


/* Soak: change the type of every target to Water. */
void HAND_WAZA_SoakSetWaterType(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u32 i;
    u32 targetCount;
    HandExChangeType *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetCount = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_COUNT);
        for (i = 0; i < targetCount; i++) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_CHANGE_TYPE, pokeId);
            cmd->typePair = BTL_TYPEPAIR_MakeSingle(HAND_WAZA_TYPE_WATER);
            cmd->pokeId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST + i);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}


/* Simple Beam: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddSimpleBeam(int *handlerCount)
{
    *handlerCount = 1;
    return gSimpleBeamHandlers;
}


/* Simple Beam: give every target the ability Simple, unless it has Truant. */
void HAND_WAZA_SimpleBeamSetAbility(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u32 i;
    u32 targetCount;
    struct HandWazaCmdSetAbility *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetCount = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_COUNT);
        for (i = 0; i < targetCount; i++) {
            if (BTL_POKEPARAM_GetValue(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST + i)), HAND_WAZA_BPP_VALUE_ABILITY) != HAND_WAZA_ABILITY_TRUANT) {
                cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_ABILITY, pokeId);
                cmd->pokeId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST + i);
                cmd->abilityId = HAND_WAZA_ABILITY_SIMPLE;
                BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HAND_WAZA_STR_SET, 0x195);
                BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), cmd->pokeId);
                BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), cmd->abilityId);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            }
        }
    }
}


/* Entrainment: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddEntrainment(int *handlerCount)
{
    *handlerCount = 1;
    return gEntrainmentHandlers;
}


/*
 * Entrainment: give every target the ability of the user, unless the user's
 * ability cannot be copied or the target has Truant.  The scan key is a `u8`
 * local assigned from the call, then passed: the inline cast
 * `(u8)BTL_EVENT_GetVar(i + 6)` adds an `adds r1, r0` copy the image does not have.
 */
void HAND_WAZA_EntrainmentCopyAbility(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u16 userAbility;
    u32 i;
    u32 targetCount;
    struct HandWazaCmdSetAbility *cmd;
    u8 targetId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        userAbility = BTL_POKEPARAM_GetValue(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), HAND_WAZA_BPP_VALUE_ABILITY);
        if (BTL_ID_IsAbilityEntrainmentBlocked(userAbility) == 0) {
            targetCount = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_COUNT);
            for (i = 0; i < targetCount; i++) {
                targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST + i);
                if (BTL_POKEPARAM_GetValue(BTL_SERVER_FLOW_GetPokeParam(flow, targetId), HAND_WAZA_BPP_VALUE_ABILITY) != HAND_WAZA_ABILITY_TRUANT) {
                    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_ABILITY, pokeId);
                    cmd->pokeId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST + i);
                    cmd->abilityId = userAbility;
                    BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HAND_WAZA_STR_SET, 0x195);
                    BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), cmd->pokeId);
                    BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), cmd->abilityId);
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
                }
            }
        }
    }
}


/* Clear Smog: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddClearSmog(int *handlerCount)
{
    *handlerCount = 1;
    return gClearSmogHandlers;
}


/* Clear Smog: reset all stat stages of the target and show the message. */
void HAND_WAZA_ClearSmogResetTargetRanks(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    struct HandWazaCmdResetRanks *resetCmd;
    struct HandExMessage *messageCmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) == 0) {
            targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
            resetCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_RESET_RANKS, pokeId);
            resetCmd->resetKind = 1;
            resetCmd->pokeId = targetId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, resetCmd);
            messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->message, HAND_WAZA_STR_SET, 0xc3);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&messageCmd->message), targetId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
        }
    }
}


/* Incinerate: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddIncinerate(int *handlerCount)
{
    *handlerCount = 1;
    return gIncinerateHandlers;
}


/*
 * Incinerate: burn up the berry that the target holds.  Gate on the attacker
 * and on the hit not landing on a substitute, then the (u8) of the defender id
 * keys BTL_SERVER_FLOW_GetPokeParam and the (u16) of BTL_POKEPARAM_GetItem is
 * the value ITEM_IsBerry must accept.  Both truncations are materialised in the image.
 */
void HAND_WAZA_IncinerateBurnBerry(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    u16 itemId;
    HandExSetItem *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) != 0)
        return;
    targetId = (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
    itemId = (u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, targetId));
    if (ITEM_IsBerry(itemId) == 0)
        return;
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_ITEM, pokeId);
    cmd->pokeId = targetId;
    cmd->itemId = 0;
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HAND_WAZA_STR_SET, 0x454);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), targetId);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), itemId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}


/* Circle Throw and Dragon Tail: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddCircleThrow(int *handlerCount)
{
    *handlerCount = 1;
    return gCircleThrowHandlers;
}


/* The move id whose factor key selects the Circle Throw text (the other text is for Dragon Tail). */
#define HAND_WAZA_MOVE_CIRCLE_THROW 0x1fd


/*
 * Circle Throw and Dragon Tail: force the target out of the battle.  The call result is
 * bound to `factorKey` before `strId = 0x1fd`: with the constant assigned first it is
 * hoisted above the call into a callee-saved register.
 */
void HAND_WAZA_CircleThrowForceSwitch(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct HandWazaCmdForceSwitch *cmd;
    int strId, factorKey;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_FORCE_SWITCH, pokeId);
        cmd->pokeId = BTL_EVENT_GetVar(HAND_WAZA_EVAR_TARGET_ID);
        factorKey = BTL_EVENT_GetFactorKey(factor);
        strId = HAND_WAZA_MOVE_CIRCLE_THROW;
        if (factorKey == strId)
            strId += 0x8e;
        else
            strId += 0x8f;
        cmd->strId = strId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}


/* Smack Down: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddSmackDown(int *handlerCount)
{
    *handlerCount = 2;
    return gSmackDownHandlers;
}


/*
 * Smack Down: ground the target (it loses Magnet Rise and Telekinesis) and bring
 * it down from Fly or Bounce.
 * lever: BTL_SICKCONT_MakeKind1Empty returns a one-word aggregate, reserving its frame temporary.
 */
void HAND_WAZA_SmackDownGroundTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    struct BtlPokeParam *target;
    int announced;
    struct HandExAddSick *addSickCmd;
    struct HandExCureSick *cureSickCmd;
    struct HandWazaCmdDropFromSky *dropCmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(HAND_WAZA_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        announced = 0;
        if (BTL_SERVER_FLOW_IsPokeAfflictedByStatus(flow, targetId) == 0) {
            if (BTL_SERVER_FLOW_IsPokeGroundedById(flow, targetId) != 0 && BTL_POKEPARAM_HasSick(target, HAND_WAZA_SICK_GROUND_GUARD) == 0) {
                addSickCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_ADD_SICK, pokeId);
                addSickCmd->pokeId = targetId;
                addSickCmd->sickKind = HAND_WAZA_SICK_SMACKED_DOWN;
                addSickCmd->sickCont = BTL_SICKCONT_MakeKind1Empty();
                BTL_SERVER_FLOW_InitMsgRecord(&addSickCmd->message, HAND_WAZA_STR_SET, 0x468);
                BTL_SERVER_FLOW_AppendMsgRecordArg((&addSickCmd->message), targetId);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, addSickCmd);
                announced = 1;
                if (BTL_POKEPARAM_HasSick(target, HAND_WAZA_SICK_MAGNET_RISE) != 0) {
                    cureSickCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_CURE_SICK, pokeId);
                    cureSickCmd->pokeCount = 1;
                    cureSickCmd->pokeIds[0] = targetId;
                    cureSickCmd->suppressMessage = 1;
                    cureSickCmd->sickKind = HAND_WAZA_SICK_MAGNET_RISE;
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSickCmd);
                }
                if (BTL_POKEPARAM_HasSick(target, HAND_WAZA_SICK_TELEKINESIS) != 0) {
                    cureSickCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_CURE_SICK, pokeId);
                    cureSickCmd->pokeCount = 1;
                    cureSickCmd->pokeIds[0] = targetId;
                    cureSickCmd->suppressMessage = 1;
                    cureSickCmd->sickKind = HAND_WAZA_SICK_TELEKINESIS;
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSickCmd);
                }
            }
            if (BTL_POKEPARAM_TestContFlag(target, HAND_WAZA_CONT_FLAG_FLYING) != 0) {
                dropCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_DROP_FROM_SKY, pokeId);
                dropCmd->pokeId = targetId;
                dropCmd->flyingFlag = HAND_WAZA_CONT_FLAG_FLYING;
                if (announced == 0) {
                    BTL_SERVER_FLOW_InitMsgRecord(&dropCmd->message, HAND_WAZA_STR_SET, 0x468);
                    BTL_SERVER_FLOW_AppendMsgRecordArg((&dropCmd->message), targetId);
                }
                BTL_SERVER_FLOW_CommitCmdRecord(flow, dropCmd);
            }
        }
    }
}


/* Shell Smash: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddShellSmash(int *handlerCount)
{
    *handlerCount = 1;
    return gShellSmashHandlers;
}


/* Shell Smash: lower Defense and Special Defense by one stage, raise Attack, Special Attack and Speed by two. */
void HAND_WAZA_ShellSmashChangeStats(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HandExRankChange *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_RANK_CHANGE, pokeId);
        cmd->rankKind = HAND_WAZA_RANK_DEFENSE;
        cmd->volume = -1;
        cmd->targetCount = 1;
        cmd->pokeId = pokeId;
        cmd->showMessage = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_RANK_CHANGE, pokeId);
        cmd->rankKind = HAND_WAZA_RANK_SP_DEFENSE;
        cmd->volume = -1;
        cmd->targetCount = 1;
        cmd->pokeId = pokeId;
        cmd->showMessage = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_RANK_CHANGE, pokeId);
        cmd->rankKind = HAND_WAZA_RANK_ATTACK;
        cmd->volume = 2;
        cmd->targetCount = 1;
        cmd->pokeId = pokeId;
        cmd->showMessage = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_RANK_CHANGE, pokeId);
        cmd->rankKind = HAND_WAZA_RANK_SP_ATTACK;
        cmd->volume = 2;
        cmd->targetCount = 1;
        cmd->pokeId = pokeId;
        cmd->showMessage = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_RANK_CHANGE, pokeId);
        cmd->rankKind = HAND_WAZA_RANK_SPEED;
        cmd->volume = 2;
        cmd->targetCount = 1;
        cmd->pokeId = pokeId;
        cmd->showMessage = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}


/* Reflect Type: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddReflectType(int *handlerCount)
{
    *handlerCount = 1;
    return gReflectTypeHandlers;
}


/*
 * Reflect Type: the user takes the type pair of the target, then a message names both.
 * The type record is halfword-stored through BTL_POKEPARAM_GetTypePair; the message
 * record gets the 4<<22 flag in its header word and the two-string tail
 * (user and target).
 */
void HAND_WAZA_ReflectTypeCopyTargetType(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    struct BtlPokeParam *target;
    HandExChangeType *typeCmd;
    struct HandExMessage *messageCmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    targetId = (u8)BTL_EVENT_GetVar(HAND_WAZA_EVAR_TARGET_ID);
    target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
    typeCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_CHANGE_TYPE, pokeId);
    typeCmd->pokeId = pokeId;
    typeCmd->typePair = BTL_POKEPARAM_GetTypePair(target);
    typeCmd->showMessage = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, typeCmd);
    messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_MESSAGE, pokeId);
    messageCmd->header |= 4 << 22;
    BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->message, HAND_WAZA_STR_SET, 0x441);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&messageCmd->message), pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg((&messageCmd->message), targetId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
}


/* Autotomize: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddAutotomize(int *handlerCount)
{
    *handlerCount = 1;
    return gAutotomizeHandlers;
}


/* Weight lost by Autotomize, in tenths of a kilogram (100 kg). */
#define HAND_WAZA_AUTOTOMIZE_WEIGHT_LOSS 0x3e8


/* Autotomize: the user loses 100 kg, down to a minimum weight of 0.1 kg. */
void HAND_WAZA_AutotomizeLoseWeight(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u32 weight, newWeight;
    struct HandWazaCmdLoseWeight *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        weight = BTL_POKEPARAM_GetWeight(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId));
        if (weight > 1) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_LOSE_WEIGHT, pokeId);
            newWeight = (weight > HAND_WAZA_AUTOTOMIZE_WEIGHT_LOSS + 1) ? weight - HAND_WAZA_AUTOTOMIZE_WEIGHT_LOSS : 1;
            cmd->pokeId = pokeId;
            cmd->newWeight = newWeight;
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HAND_WAZA_STR_SET, 0x44e);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}


/* Psyshock, Psystrike and Secret Sword: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddPsyshock(int *handlerCount)
{
    *handlerCount = 1;
    return gPsyshockHandlers;
}


/* Value of the event variable that the defense stat event leaves when the formula reads the special defense stat (guess). */
#define HAND_WAZA_DEFENSE_STAT_KIND_SPECIAL 0xb


/* Turns that Wonder Room and Magic Room last. */
#define HAND_WAZA_ROOM_TURNS 5


/* Position value that BTL_SERVER_FLOW_GetPokeIdAtPos returns for a Pokemon that is not on the field. */
#define HAND_WAZA_NO_POSITION 6


/*
 * Psyshock, Psystrike and Secret Sword: when the formula would read the special
 * defense stat, step the stat choice by one (to the plain defense stat).
 */
void HAND_WAZA_PsyshockSwapDefenseStat(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_EVENT_GetVar(HAND_WAZA_EVAR_DEFENSE_STAT_KIND) == HAND_WAZA_DEFENSE_STAT_KIND_SPECIAL)
        BTL_EVENT_OverwriteVar(HAND_WAZA_EVAR_DEFENSE_STAT_STEP, BTL_EVENT_GetVar(HAND_WAZA_EVAR_DEFENSE_STAT_STEP) + 1);
}


/* Chip Away and Sacred Sword: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddChipAway(int *handlerCount)
{
    *handlerCount = 2;
    return gChipAwayHandlers;
}


/* Chip Away and Sacred Sword: the formula ignores the stat stages of the target. */
void HAND_WAZA_ChipAwayIgnoreDefenseStages(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(HAND_WAZA_EVAR_IGNORE_STAGES_FLAG, 1);
}


/* Chip Away and Sacred Sword: the accuracy check ignores the evasion stage of the target. */
void HAND_WAZA_ChipAwayIgnoreEvasionStages(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(HAND_WAZA_EVAR_IGNORE_EVASION_FLAG, 1);
}


/* Wonder Room: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddWonderRoom(int *handlerCount)
{
    *handlerCount = 1;
    return gWonderRoomHandlers;
}


/* Wonder Room: start the field effect for five turns, or end it when it is already active. */
void HAND_WAZA_WonderRoomToggle(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    int fieldEffectId;
    BtlFieldEffectAddCmd *addCmd;
    BtlFieldEffectRemoveCmd *removeCmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        fieldEffectId = HAND_WAZA_FIELD_WONDER_ROOM;
        if (BTL_FIELD_IsStaticSlotInUse(fieldEffectId) == 0) {
            addCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_ADD_FIELD_EFFECT, pokeId);
            addCmd->effectId = fieldEffectId;
            addCmd->duration = BTL_SICKCONT_MakeKind2Index(HAND_WAZA_ROOM_TURNS);
            BTL_SERVER_FLOW_InitMsgRecord(&addCmd->message, HAND_WAZA_STR_STANDARD, 0xb2);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, addCmd);
        } else {
            removeCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_REMOVE_FIELD_EFFECT, pokeId);
            removeCmd->effectId = fieldEffectId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, removeCmd);
        }
    }
}


/* Magic Room: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddMagicRoom(int *handlerCount)
{
    *handlerCount = 1;
    return gMagicRoomHandlers;
}


/* Magic Room: start the field effect for five turns, or end it when it is already active. */
void HAND_WAZA_MagicRoomToggle(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    int fieldEffectId;
    BtlFieldEffectAddCmd *addCmd;
    BtlFieldEffectRemoveCmd *removeCmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        fieldEffectId = HAND_WAZA_FIELD_MAGIC_ROOM;
        if (BTL_FIELD_IsStaticSlotInUse(fieldEffectId) == 0) {
            addCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_ADD_FIELD_EFFECT, pokeId);
            addCmd->effectId = fieldEffectId;
            addCmd->duration = BTL_SICKCONT_MakeKind2Index(HAND_WAZA_ROOM_TURNS);
            BTL_SERVER_FLOW_InitMsgRecord(&addCmd->message, HAND_WAZA_STR_STANDARD, 0xb4);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, addCmd);
        } else {
            removeCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_REMOVE_FIELD_EFFECT, pokeId);
            removeCmd->effectId = fieldEffectId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, removeCmd);
        }
    }
}


/* Flame Burst: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddFlameBurst(int *handlerCount)
{
    *handlerCount = 1;
    return gFlameBurstHandlers;
}


/*
 * Flame Burst: every other living Pokemon next to the target loses one sixteenth of its maximum HP.
 * lever: the byte-valued count remains u8; +7 is a one-bit field assignment.
 */
void HAND_WAZA_FlameBurstDamageAdjacent(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 adjacentIds[4];
    u8 targetId, i;
    u8 adjacentCount;
    int targetPos;
    struct BtlPokeParam *adjacent;
    HandExDamage *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        targetPos = BTL_SERVER_FLOW_GetPokeIdAtPos(flow, targetId);
        if (targetPos != HAND_WAZA_NO_POSITION) {
            adjacentCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(0x900 | targetPos), adjacentIds);
            for (i = 0; i < adjacentCount; i++) {
                if (adjacentIds[i] != targetId) {
                    adjacent = BTL_SERVER_FLOW_GetPokeParam(flow, adjacentIds[i]);
                    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_DAMAGE, pokeId);
                    cmd->pokeId = adjacentIds[i];
                    cmd->amount = BTL_CALC_DivideMaxHpMin1(adjacent, 16);
                    cmd->unblockable = 1;
                    BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HAND_WAZA_STR_SET, 0x451);
                    BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), cmd->pokeId);
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
                }
            }
        }
    }
}


/* Synchronoise: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddSynchronoise(int *handlerCount)
{
    *handlerCount = 1;
    return gSynchronoiseHandlers;
}


/* Synchronoise: the move has no effect on a target that shares no type with the user. */
void HAND_WAZA_SynchronoiseFailWithoutSharedType(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    struct BtlPokeParam *target, *user;
    u32 userTypes;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        userTypes = BTL_POKEPARAM_GetTypePair(user);
        if (BTL_TYPEPAIR_ShareType(userTypes, BTL_POKEPARAM_GetTypePair(target)) == 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1);
    }
}


/* Bestow: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddBestow(int *handlerCount)
{
    *handlerCount = 1;
    return gBestowHandlers;
}


/* Value id of BTL_POKEPARAM_GetValue (the Pokemon value getter) that returns the current HP. */
#define HAND_WAZA_BPP_VALUE_HP 0xd


/*
 * Bestow: the user hands its held item to a target that holds none (the item can
 * be given away and the target species can hold it): one record takes the item
 * from the user, one gives it to the target with a message.
 */
void HAND_WAZA_BestowGiveItem(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    struct BtlPokeParam *target;
    u16 itemId;
    HandExSetItem *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(HAND_WAZA_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        itemId = (int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId));
        if (itemId != 0 && FILE_UTIL_IsMailItem(itemId) == 0 && (int)BTL_POKEPARAM_GetItem(target) == 0
            && HAND_COMMON_IsHeldItemBoundToOwnSpecies(flow, pokeId) == 0 && HAND_COMMON_IsHeldItemBoundToOwnSpecies(flow, targetId) == 0
            && HAND_COMMON_IsItemBoundToSpecies(BTL_POKEPARAM_GetSpecies(target), itemId) == 0) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_ITEM, pokeId);
            cmd->pokeId = pokeId;
            cmd->itemId = 0;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_ITEM, pokeId);
            cmd->pokeId = targetId;
            cmd->itemId = itemId;
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HAND_WAZA_STR_SET, 0x457);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), targetId);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), itemId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}


/* Final Gambit: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddFinalGambit(int *handlerCount)
{
    *handlerCount = 2;
    return gFinalGambitHandlers;
}


/* Final Gambit: the fixed damage is the current HP of the user. */
void HAND_WAZA_FinalGambitSetFixedDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(HAND_WAZA_EVAR_FIXED_DAMAGE, BTL_POKEPARAM_GetValue(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), HAND_WAZA_BPP_VALUE_HP));
}


/* After You: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddAfterYou(int *handlerCount)
{
    *handlerCount = 1;
    return gAfterYouHandlers;
}


/* After You: the target moves next this turn. */
void HAND_WAZA_AfterYouMoveTargetNext(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct HandWazaCmdTurnOrder *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_MOVE_NEXT, pokeId);
        cmd->pokeId = BTL_EVENT_GetVar(HAND_WAZA_EVAR_TARGET_ID);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HAND_WAZA_STR_SET, 1134);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), cmd->pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}


/* Quash: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddQuash(int *handlerCount)
{
    *handlerCount = 1;
    return gQuashHandlers;
}


/* Quash: the target moves last this turn. */
void HAND_WAZA_QuashMoveTargetLast(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct HandWazaCmdTurnOrder *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_MOVE_LAST, pokeId);
        cmd->pokeId = BTL_EVENT_GetVar(HAND_WAZA_EVAR_TARGET_ID);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HAND_WAZA_STR_SET, 1131);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&cmd->message), cmd->pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}


/* Round: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddRound(int *handlerCount)
{
    *handlerCount = 2;
    return gRoundHandlers;
}


/* Round: when the turn record shows the move was used this turn, queue a record with the move key (the follow-up Round of an ally). */
void HAND_WAZA_RoundRegisterUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    sptr turnRecord;
    u16 factorKey;
    struct HandWazaCmdRoundUsed *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        turnRecord = (sptr)BTL_SERVER_FLOW_GetTurnRecord(flow);
        factorKey = BTL_EVENT_GetFactorKey(factor);
        if (BTL_WAZAREC_GetUsedWazaCount((struct BtlWazaRec *)turnRecord, factorKey, BTL_SERVER_FLOW_GetTurnCount(flow)) == 1) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_ROUND_USED, pokeId);
            cmd->factorKey = factorKey;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}


/* Round, event 0x37 (move power): the power doubles when the move was already used this turn. */
void HAND_WAZA_RoundDoublePower(BTL_EVENT_SIGNATURE)
{
    struct BtlTurnRecord *turnRecord;
    u16 moveId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        turnRecord = (struct BtlTurnRecord *)BTL_SERVER_FLOW_GetTurnRecord(flow);
        moveId = BTL_EVENT_GetFactorKey(factor);
        if (BTL_WAZAREC_GetUsedWazaCount((struct BtlWazaRec *)turnRecord, moveId, BTL_SERVER_FLOW_GetTurnCount(flow)) > 1)
            HAND_COMMON_EventScaleDamage(2);
    }
}


/* Quick Guard (move 501): handler table, 4 rows (the first three are the Protect family rows). */
int *HAND_WAZA_GetQuickGuardHandlers(int *handlerCount)
{
    *handlerCount = 4;
    return gQuickGuardHandlers;
}


/* Quick Guard, event 0xa1 (move without target): a one-turn ward on the user's side, counted as a Protect use. */
void HAND_WAZA_QuickGuardOnUncategorizedMoveNoTarget(BTL_EVENT_SIGNATURE, int *work)
{
    union SickCont cont = BTL_SICKCONT_MakeKind2Index(1);
    u8 side = BTL_MAIN_IsPokeIdInSecondPair(pokeId);

    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_QUICK_GUARD_KIND, cont, HAND_WAZA_STR_QUICK_GUARD);
    HAND_WAZA_ProtectIncrementStreak(flow, pokeId, 1);
}


/* Ally Switch (move 502): handler table, 1 row. */
int *HAND_WAZA_GetAllySwitchHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gAllySwitchHandlers;
}


/*
 * Ally Switch, event 0xa0 (the move itself): finds the ally on the other lane of
 * the user's side and queues a swap of the two with a message.
 */
void HAND_WAZA_AllySwitchSwapPositions(BTL_EVENT_SIGNATURE)
{
    int viewPos, partnerId;
    u32 lanePos;
    struct HandExSwapPositions *record;

    viewPos = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
    partnerId = pokeId;
    switch (BTL_SERVER_FLOW_GetRule(flow)) {
    case BTL_RULE_DOUBLE:
        if (BTL_SERVER_FLOW_GetClientIdBySide(flow, BTL_MAIN_PokeIdToClientIdThunk(pokeId)) == BTL_CLIENT_ID_NONE) {
            lanePos = BTL_MAIN_GetOwnLanePos(viewPos, 0);
            if (lanePos == viewPos)
                lanePos = BTL_MAIN_GetOwnLanePos(viewPos, 1);
            partnerId = BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(flow, lanePos);
        }
        break;
    case BTL_RULE_TRIPLE:
        if (BTL_MAIN_IsBackRowPos(viewPos) == 0) {
            lanePos = BTL_MAIN_GetOwnLanePos(viewPos, 0);
            if (lanePos == viewPos)
                lanePos = BTL_MAIN_GetOwnLanePos(viewPos, 2);
            partnerId = BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(flow, lanePos);
        }
        break;
    }
    if (partnerId != pokeId) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SWAP_POSITIONS, pokeId);
        record->pokeId = pokeId;
        record->partnerId = partnerId;
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_STRTYPE_SET, HAND_WAZA_STR_ALLY_SWITCH);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), partnerId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}


/* Telekinesis (move 477): handler table, 2 rows. */
int *HAND_WAZA_GetTelekinesisHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gTelekinesisHandlers;
}


/* Telekinesis, event 0x2d (no-effect check): Diglett, Dugtrio and Pokemon held down by Ingrain or Smack Down are immune. */
void HAND_WAZA_TelekinesisCheckTarget(BTL_EVENT_SIGNATURE)
{
    struct BtlPokeParam *target;
    int species;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        u8 targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        species = BTL_POKEPARAM_GetSpecies(target);
        if (species == BTL_SPECIES_DIGLETT || species == BTL_SPECIES_DUGTRIO
            || BTL_POKEPARAM_HasSick(target, BTL_SICK_FLOATING_BLOCK) != 0
            || BTL_POKEPARAM_HasSick(target, BTL_SICK_INGRAIN) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1);
    }
}


/* Telekinesis, event 0x60 (status added): the status becomes Telekinesis and its message names the target. */
void HAND_WAZA_TelekinesisSetStatusMessage(BTL_EVENT_SIGNATURE)
{
    BtlMessageParam *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        message = (BtlMessageParam *)BTL_EVENT_GetVar(BTL_EVAR_MESSAGE);
        BTL_EVENT_OverwriteVar(BTL_EVAR_SICK_ID, BTL_SICK_TELEKINESIS);
        BTL_SERVER_FLOW_InitMsgRecord(message, BTL_STRTYPE_SET, HAND_WAZA_STR_TELEKINESIS);
        BTL_SERVER_FLOW_AppendMsgRecordArg(message, BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID));
    }
}


/* Sky Drop (move 507): handler table, 6 rows. */
int *HAND_WAZA_GetSkyDropHandlers(int *handlerCount)
{
    *handlerCount = 6;
    return gSkyDropHandlers;
}


/* Sky Drop, event 0x93 (charge check): the move cannot start on an ally. */
void HAND_WAZA_SkyDropBlockAllyTarget(BTL_EVENT_SIGNATURE)
{
    u8 targetId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        if (targetId != BTL_EVENT_NO_POKE && BTL_MAIN_IsPokeSamePair(pokeId, targetId) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_PREVENT_FLAG, 1);
    }
}


/* Sky Drop, event 0x95 (charge turn): takes the first target into the sky, or stops when no target can be taken. */
void HAND_WAZA_SkyDropStartCharge(BTL_EVENT_SIGNATURE)
{
    u8 targetId;
    int reflected;
    struct HandExMessage *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST);
        reflected = 0;
        if (targetId == BTL_EVENT_NO_POKE || BTL_SERVER_FLOW_ProcMoveReflectOrAbsorbById(flow, pokeId, targetId, &reflected) == 0) {
            BTL_EVENT_OverwriteVar(BTL_EVAR_PREVENT_FLAG, 1);
            if (reflected != 0)
                BTL_EVENT_OverwriteVar(BTL_EVAR_REFLECTED_FLAG, 1);
        } else if (BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1) != 0) {
            record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_STRTYPE_SET, HAND_WAZA_STR_SKY_DROP);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), targetId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
        }
    }
}


/* Sky Drop, event 0x98 (release of the charge): the held Pokemon is let go; the drop fails when it is gone. */
void HAND_WAZA_SkyDropReleaseTarget(BTL_EVENT_SIGNATURE)
{
    u8 counter, heldId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        counter = BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_COUNTER_BOUND_TARGET);
        if (counter == 0 || (u8)(counter - 1) >= BTL_BOUND_TARGET_LIMIT)
            heldId = BTL_EVENT_NO_POKE;
        else
            heldId = counter - 1;
        if (heldId == BTL_EVENT_NO_POKE || BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, heldId) == BTL_POS_NONE)
            BTL_EVENT_OverwriteVar(BTL_EVAR_PREVENT_FLAG, 1);
        BTL_SERVER_FLOW_ReleaseBindingTargetById(flow, pokeId);
    }
}


/* Sky Drop, event 0x2a (target decision, not in single or rotation battles): the held Pokemon is the target. */
void HAND_WAZA_SkyDropRedirectToHeldTarget(BTL_EVENT_SIGNATURE)
{
    u8 counter, heldId;

    if (BTL_SERVER_FLOW_GetRule(flow) != BTL_RULE_SINGLE && BTL_SERVER_FLOW_GetRule(flow) != BTL_RULE_ROTATION) {
        counter = BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_COUNTER_BOUND_TARGET);
        if (counter == 0 || (u8)(counter - 1) >= BTL_BOUND_TARGET_LIMIT)
            heldId = BTL_EVENT_NO_POKE;
        else
            heldId = counter - 1;
        if (heldId != BTL_EVENT_NO_POKE)
            BTL_EVENT_OverwriteVar(BTL_EVAR_DEFENDER_ID, heldId);
    }
}


/* Sky Drop, event 0x1f (execute check): the move fails when the held Pokemon is no longer on the field. */
void HAND_WAZA_SkyDropFailIfTargetGone(BTL_EVENT_SIGNATURE)
{
    u8 counter, heldId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        counter = BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_COUNTER_BOUND_TARGET);
        if (counter == 0 || (u8)(counter - 1) >= BTL_BOUND_TARGET_LIMIT)
            heldId = BTL_EVENT_NO_POKE;
        else
            heldId = counter - 1;
        if (heldId != BTL_EVENT_NO_POKE && BTL_SERVER_FLOW_IsPokeInPosTable(flow, heldId) == 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_GENERIC);
    }
}


/* Sky Drop, event 0x2c (no-effect check): Flying Pokemon are immune. */
void HAND_WAZA_SkyDropBlockFlyingTarget(BTL_EVENT_SIGNATURE)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_HasType(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)), BTL_TYPE_FLYING) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1);
    }
}


/* Relic Song (move 547): handler table, 1 row. */
int *HAND_WAZA_GetRelicSongHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRelicSongHandlers;
}


/* Relic Song, event 0x85 (after the hit): Meloetta changes between its Aria and Pirouette forms. */
void HAND_WAZA_RelicSongChangeForm(BTL_EVENT_SIGNATURE)
{
    int newForm;
    struct HandExChangeForm *record;
    struct BtlPokeParam *bpp;

    bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (BTL_POKEPARAM_GetSpecies(bpp) == BTL_SPECIES_MELOETTA && pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        newForm = BTL_POKEPARAM_GetValue(bpp, BTL_BPP_VALUE_FORM) == 0;
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CHANGE_MON_FORM, pokeId);
        record->pokeId = pokeId;
        record->form = newForm;
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_STRTYPE_SET, HAND_WAZA_STR_FORM_CHANGE);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}


/* Foresight (move 193) and Odor Sleuth (move 316): handler table, 2 rows. */
int *HAND_WAZA_GetForesightHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gForesightOdorSleuthHandlers;
}


/* Foresight and Odor Sleuth, event 0x62 (status added): the status remembers the Ghost type, which then loses its immunity. */
void HAND_WAZA_ForesightSetGhostType(BTL_EVENT_SIGNATURE)
{
    union SickCont cont;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        cont.raw = BTL_EVENT_GetVar(BTL_EVAR_SICK_CONT);
        BTL_SICKCONT_SetValue(&cont, BTL_TYPE_GHOST);
        BTL_EVENT_OverwriteVar(BTL_EVAR_SICK_CONT, cont.raw);
    }
}


/* Miracle Eye (move 357): handler table, 2 rows. */
int *HAND_WAZA_GetMiracleEyeHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gMiracleEyeHandlers;
}


/* Miracle Eye, event 0x62 (status added): the status remembers the Dark type, which then loses its immunity. */
void HAND_WAZA_MiracleEyeSetDarkType(BTL_EVENT_SIGNATURE)
{
    union SickCont cont;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        cont.raw = BTL_EVENT_GetVar(BTL_EVAR_SICK_CONT);
        BTL_SICKCONT_SetValue(&cont, BTL_TYPE_DARK);
        BTL_EVENT_OverwriteVar(BTL_EVAR_SICK_CONT, cont.raw);
    }
}


/* Growth (move 74): handler table, 1 row. */
int *HAND_WAZA_GetGrowthHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gGrowthHandlers;
}


/* Growth, event 0x59 (stage change volume): the boost of 1 stage becomes 2 stages in harsh sunlight. */
void HAND_WAZA_GrowthBoostInSun(BTL_EVENT_SIGNATURE)
{
    int volume;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_SUN) {
        volume = BTL_EVENT_GetVar(BTL_EVAR_VOLUME);
        if (volume == 1)
            volume++;
        BTL_EVENT_OverwriteVar(BTL_EVAR_VOLUME, volume);
    }
}


/* Freeze Shock (move 553) and Ice Burn (move 554): handler table, 1 row. */
int *HAND_WAZA_GetFreezeShockIceBurnHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gFreezeShockIceBurnHandlers;
}


/* Freeze Shock and Ice Burn, event 0x95 (charge turn): shows the message of the move being charged. */
void HAND_WAZA_FreezeShockIceBurnShowChargeMessage(BTL_EVENT_SIGNATURE)
{
    struct HandExMessage *record;
    int strId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetFactorKey(factor) == BTL_MOVE_FREEZE_SHOCK)
            strId = HAND_WAZA_STR_FREEZE_SHOCK_CHARGE;
        else
            strId = HAND_WAZA_STR_ICE_BURN_CHARGE;
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_STRTYPE_SET, (u16)strId);
        BTL_SERVER_FLOW_AppendMsgRecordArg((&record->message), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}


/* Fusion Flare (move 558) and Fusion Bolt (move 559): handler table, 1 row. */
int *HAND_WAZA_GetFusionHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gFusionFlareFusionBoltHandlers;
}


/* Fusion Flare and Fusion Bolt, event 0x38 (power ratio): doubles the power when the other Fusion move was the last one used this turn. */
void HAND_WAZA_FusionDoublePower(BTL_EVENT_SIGNATURE)
{
    struct BtlTurnRecord *turnRecord;
    int otherMove;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        turnRecord = (struct BtlTurnRecord *)BTL_SERVER_FLOW_GetTurnRecord(flow);
        switch (BTL_EVENT_GetFactorKey(factor)) {
        case BTL_MOVE_FUSION_FLARE:
            otherMove = BTL_MOVE_FUSION_BOLT;
            break;
        case BTL_MOVE_FUSION_BOLT:
            otherMove = BTL_MOVE_FUSION_FLARE;
            break;
        default:
            otherMove = 0;
            break;
        }
        if (otherMove != 0 && otherMove == BTL_WAZAREC_GetEffectiveWaza((struct BtlWazaRec *)turnRecord, BTL_SERVER_FLOW_GetTurnCount(flow))) {
            BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_DOUBLE);
            BTL_SERVER_FLOW_SetCurTurnStateFlag(flow, 1);
        }
    }
}


/* The combination that two Pledge moves make, in either order; PLEDGE_COMBO_NONE when they do not combine. */
int HAND_WAZA_FindPledgeCombo(u32 firstMove, u32 secondMove)
{
    u32 i;
    for (i = 0; i < 3; i++) {
        if ((firstMove == gPledgeComboTable[i].firstMove && secondMove == gPledgeComboTable[i].secondMove) ||
            (secondMove == gPledgeComboTable[i].firstMove && firstMove == gPledgeComboTable[i].secondMove))
            return gPledgeComboTable[i].combo;
    }
    return PLEDGE_COMBO_NONE;
}


/* Water Pledge, Fire Pledge and Grass Pledge (moves 518 to 520): handler table, 6 rows. */
int *HAND_WAZA_GetPledgeHandlers(int *handlerCount)
{
    *handlerCount = 6;
    return gPledgeHandlers;
}


/*
 * Pledge, event 0xa2 (move decision): when another Pokemon on the field has chosen a Pledge
 * move that combines with this one, records the combination and the partner, and the move
 * takes the type of the combination.
 */
void HAND_WAZA_PledgeCheckCombo(BTL_EVENT_SIGNATURE, struct PledgeWork *work)
{
    u16 partnerMove;
    u8 partnerId;
    int combo;
    u8 moveType;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_GetStoredPokeMove(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), &partnerId, &partnerMove) != 0) {
            combo = HAND_WAZA_FindPledgeCombo(BTL_EVENT_GetFactorKey(factor), partnerMove);
            moveType = BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
            if (combo != PLEDGE_COMBO_NONE) {
                work->combo = combo;
                work->combined = 1;
                work->partnerId = partnerId;
                switch (combo) {
                case PLEDGE_COMBO_RAINBOW:
                    moveType = BTL_TYPE_WATER;
                    break;
                case PLEDGE_COMBO_SEA_OF_FIRE:
                    moveType = BTL_TYPE_FIRE;
                    break;
                case PLEDGE_COMBO_SWAMP:
                    moveType = BTL_TYPE_GRASS;
                    break;
                }
                BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_TYPE, moveType);
            }
        }
    }
}


/* Pledge, event 0x23 (wait for the partner): shows the message that the user waits for its ally. */
void HAND_WAZA_PledgeShowWaitMessage(BTL_EVENT_SIGNATURE, struct PledgeWork *work)
{
    struct HandExMessage *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && work->combined != 0) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_STRTYPE_STD, HAND_WAZA_STR_PLEDGE_WAITING);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}


/* Pledge, event 0x40 (charge skip check): the combined move skips the waiting turn. */
void HAND_WAZA_PledgeSkipWait(BTL_EVENT_SIGNATURE, struct PledgeWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && work->combined != 0)
        BTL_EVENT_OverwriteVar(BTL_EVAR_SKIP_CHARGE_FLAG, 1);
}


/* Pledge, event 0x37 (move power): the combined move has a power of 150. */
void HAND_WAZA_PledgeSetCombinedPower(BTL_EVENT_SIGNATURE, struct PledgeWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && work->combined != 0)
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, PLEDGE_COMBINED_POWER);
}


/* Pledge, event 0x24 (move start): the combined move is announced and animated as the Pledge move of the combination. */
void HAND_WAZA_PledgeSetCombinedMoveId(BTL_EVENT_SIGNATURE, struct PledgeWork *work)
{
    int moveId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (work->combined != 0) {
            moveId = 0;
            switch (work->combo) {
            case PLEDGE_COMBO_RAINBOW:
                moveId = BTL_MOVE_WATER_PLEDGE;
                break;
            case PLEDGE_COMBO_SEA_OF_FIRE:
                moveId = BTL_MOVE_FIRE_PLEDGE;
                break;
            case PLEDGE_COMBO_SWAMP:
                moveId = BTL_MOVE_GRASS_PLEDGE;
                break;
            }
            BTL_EVENT_OverwriteVar(BTL_EVAR_EFFECTIVE_MOVE_ID, moveId);
        }
    }
}


/*
 * Pledge, event 0x85 (after the hit): puts the field effect of the combination on the right side
 * (rainbow on the user's side, sea of fire and swamp on the target's side) and plays its effect.
 * Levers: byte locals plus declaration order restore the spill and register assignment.
 */
void HAND_WAZA_PledgeApplyCombinedEffect(BTL_EVENT_SIGNATURE, const struct PledgeWork *work)
{
    int rawPos;
    struct HandExAddSideEffect *sideRecord;
    struct HandExPlayEffect *effectRecord;
    u8 side;
    int effectId;
    u8 ownSide;
    u8 targetSide;
    int effectTargetId;
    int pos;
    u8 strId;
    u8 effectKind;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && work->combined != 0) {
        effectKind = 14;
        ownSide = BTL_MAIN_IsPokeIdInSecondPair(pokeId);
        targetSide = BTL_MAIN_IsPokeIdInSecondPair((u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST));
        effectId = 0;
        strId = 0;
        effectTargetId = BTL_EVENT_NO_POKE;
        switch (work->combo) {
        case PLEDGE_COMBO_RAINBOW:
            strId = HAND_WAZA_STR_RAINBOW;
            effectKind = BTL_SIDE_EFFECT_RAINBOW;
            side = ownSide;
            effectId = BTL_EFFECT_RAINBOW;
            effectTargetId = pokeId;
            break;
        case PLEDGE_COMBO_SEA_OF_FIRE:
            strId = HAND_WAZA_STR_SEA_OF_FIRE;
            side = targetSide;
            effectKind = BTL_SIDE_EFFECT_SEA_OF_FIRE;
            effectId = BTL_EFFECT_SEA_OF_FIRE;
            effectTargetId = (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST);
            break;
        case PLEDGE_COMBO_SWAMP:
            strId = HAND_WAZA_STR_SWAMP;
            side = targetSide;
            effectKind = BTL_SIDE_EFFECT_SWAMP;
            effectId = BTL_EFFECT_SWAMP;
            effectTargetId = (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST);
            break;
        }
        if (effectKind != 14) {
            sideRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SIDE_EFFECT, pokeId);
            sideRecord->effectKind = effectKind;
            sideRecord->side = side;
            sideRecord->cont = BTL_SICKCONT_MakeKind2Index(4);
            BTL_SERVER_FLOW_InitMsgRecord(&sideRecord->message, BTL_STRTYPE_STD, strId);
            BTL_SERVER_FLOW_AppendMsgRecordArg((&sideRecord->message), side);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, sideRecord);
            if (effectTargetId != BTL_EVENT_NO_POKE) {
                rawPos = BTL_SERVER_FLOW_GetPokeIdAtPos(flow, effectTargetId);
                pos = rawPos;
                if (pos != BTL_POS_NONE) {
                    effectRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_PLAY_EFFECT, pokeId);
                    effectRecord->fromPos = pos;
                    effectRecord->toPos = BTL_POS_NONE;
                    effectRecord->effectId = effectId;
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, effectRecord);
                }
            }
        }
    }
}
