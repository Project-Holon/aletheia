/*
 * file:     hand_tokusei.c
 * unit:     yes
 * function: HAND_TOKUSEI_AddAbilityHandlers, HAND_TOKUSEI_PackAbilityHandlerInfo, HAND_TOKUSEI_UnpackAbilityPriority, HAND_TOKUSEI_GetIntimidateHandlers, HAND_TOKUSEI_RemoveAbilityHandlers, HAND_TOKUSEI_DisableAbilityHandlers, HAND_TOKUSEI_EnableAbilityHandlers, HAND_TOKUSEI_SwapAbilityHandlers, HAND_TOKUSEI_GetPokeSpeed, HAND_TOKUSEI_RollChanceOrFlag, HAND_TOKUSEI_IntimidateOnEnter, HAND_TOKUSEI_GetInnerFocusHandlers, HAND_TOKUSEI_InnerFocusPreventFlinch, HAND_TOKUSEI_GetSteadfastHandlers, HAND_TOKUSEI_SteadfastOnFlinch, HAND_TOKUSEI_GetThickFatHandlers, HAND_TOKUSEI_ThickFatHalveFireIce, HAND_TOKUSEI_GetHugePowerHandlers, HAND_TOKUSEI_HugePowerDoubleAttack, HAND_TOKUSEI_SwiftSwimDoubleSpeed, HAND_TOKUSEI_GetSwiftSwimHandlers, HAND_TOKUSEI_ChlorophyllDoubleSpeed, HAND_TOKUSEI_GetChlorophyllHandlers, HAND_TOKUSEI_QuickFeetBoostSpeed, HAND_TOKUSEI_GetQuickFeetHandlers, HAND_TOKUSEI_TangledFeetHalveAccuracy, HAND_TOKUSEI_GetTangledFeetHandlers, HAND_TOKUSEI_HustleLowerAccuracy, HAND_TOKUSEI_HustleBoostPower, HAND_TOKUSEI_GetHustleHandlers, HAND_TOKUSEI_StallMoveLast, HAND_TOKUSEI_GetStallHandlers, HAND_TOKUSEI_SlowStartHalveSpeed, HAND_TOKUSEI_SlowStartHalveAttack, HAND_TOKUSEI_SlowStartOnEnter, HAND_TOKUSEI_SlowStartBeginOnce, HAND_TOKUSEI_SlowStartBegin, HAND_TOKUSEI_SlowStartCountTurn, HAND_TOKUSEI_GetSlowStartHandlers, HAND_TOKUSEI_CompoundEyesBoostAccuracy, HAND_TOKUSEI_GetCompoundEyesHandlers, HAND_TOKUSEI_SandVeilLowerAccuracy, HAND_TOKUSEI_SandVeilBlockSandDamage, HAND_TOKUSEI_GetSandVeilHandlers, HAND_TOKUSEI_SnowCloakLowerAccuracy, HAND_TOKUSEI_SnowCloakBlockHailDamage, HAND_TOKUSEI_GetSnowCloakHandlers, HAND_TOKUSEI_BlockWeatherDamage, HAND_TOKUSEI_TintedLensDoubleResisted, HAND_TOKUSEI_GetTintedLensHandlers, HAND_TOKUSEI_FilterHalveSuperEffective, HAND_TOKUSEI_GetFilterHandlers, HAND_TOKUSEI_SniperBoostCritical, HAND_TOKUSEI_GetSniperHandlers, HAND_TOKUSEI_SpeedBoostOnTurnEnd, HAND_TOKUSEI_GetSpeedBoostHandlers, HAND_TOKUSEI_AdaptabilityBoostSameType, HAND_TOKUSEI_GetAdaptabilityHandlers, HAND_TOKUSEI_BlazeBoostFire, HAND_TOKUSEI_GetBlazeHandlers, HAND_TOKUSEI_TorrentBoostWater, HAND_TOKUSEI_GetTorrentHandlers, HAND_TOKUSEI_OvergrowBoostGrass, HAND_TOKUSEI_GetOvergrowHandlers, HAND_TOKUSEI_SwarmBoostBug, HAND_TOKUSEI_GetSwarmHandlers, HAND_TOKUSEI_PinchBoostType, HAND_TOKUSEI_GutsBoostAttack, HAND_TOKUSEI_GetGutsHandlers, HAND_TOKUSEI_PlusMinusBoostSpecialPower, HAND_TOKUSEI_GetPlusMinusHandlers, HAND_TOKUSEI_CheckAllyHasAbility, HAND_TOKUSEI_IsCherrim, HAND_TOKUSEI_FlowerGiftUpdateForm, HAND_TOKUSEI_FlowerGiftUpdateFormIfOwner, HAND_TOKUSEI_ChangeCherrimForm, HAND_TOKUSEI_FlowerGiftReapplyForm, HAND_TOKUSEI_FlowerGiftRevertFormIfOwner, HAND_TOKUSEI_FlowerGiftRevertForm, HAND_TOKUSEI_FlowerGiftRevertFormOnFactorChange, HAND_TOKUSEI_FlowerGiftBoostAllyAttack, HAND_TOKUSEI_FlowerGiftBoostAllySpecialDefense, HAND_TOKUSEI_GetFlowerGiftHandlers, HAND_TOKUSEI_RivalryScalePower, HAND_TOKUSEI_GetRivalryHandlers, HAND_TOKUSEI_TechnicianBoostWeakMove, HAND_TOKUSEI_GetTechnicianHandlers, HAND_TOKUSEI_IronFistBoostPunchPower, HAND_TOKUSEI_GetIronFistHandlers, HAND_TOKUSEI_RecklessBoostRecoilPower, HAND_TOKUSEI_GetRecklessHandlers, HAND_TOKUSEI_MarvelScaleBoostDefense, HAND_TOKUSEI_GetMarvelScaleHandlers, HAND_TOKUSEI_MoldBreakerSetIgnoreAbilities, HAND_TOKUSEI_GetMoldBreakerFlagHandlers, HAND_TOKUSEI_GetIndirectGuardCause1Handlers, HAND_TOKUSEI_IndirectGuardCause1Block, HAND_TOKUSEI_IndirectGuardCause1ShowMessage, HAND_TOKUSEI_GetIndirectGuardCause6Handlers, HAND_TOKUSEI_IndirectGuardCause6Block, HAND_TOKUSEI_IndirectGuardCause6ShowMessage, HAND_TOKUSEI_GetIndirectGuardCause8Handlers, HAND_TOKUSEI_IndirectGuardCause8Block, HAND_TOKUSEI_IndirectGuardCause8ShowMessage, HAND_TOKUSEI_BlockIndirectDamage, HAND_TOKUSEI_ShowIndirectGuardMessage, HAND_TOKUSEI_HalveResidualDamage, HAND_TOKUSEI_GetHalveResidualDamageHandlers, HAND_TOKUSEI_LeafGuardBlockStatus, HAND_TOKUSEI_LeafGuardBlockOwnerEvent, HAND_TOKUSEI_GetLeafGuardHandlers, HAND_TOKUSEI_ParalysisGuard_CheckAdd, HAND_TOKUSEI_ParalysisGuard_CureOnEntry, HAND_TOKUSEI_ParalysisGuard_CureOnPeriodicCheck, HAND_TOKUSEI_GetParalysisGuardHandlers, HAND_TOKUSEI_SleepGuard_CheckAdd, HAND_TOKUSEI_SleepGuard_CureOnEntry, HAND_TOKUSEI_SleepGuard_CureOnPeriodicCheck, HAND_TOKUSEI_SleepGuard_BlockOwnerEvent0E, HAND_TOKUSEI_GetSleepGuardHandlers, HAND_TOKUSEI_FreezeGuard_CheckAdd, HAND_TOKUSEI_FreezeGuard_CureOnEntry, HAND_TOKUSEI_FreezeGuard_CureOnPeriodicCheck, HAND_TOKUSEI_GetFreezeGuardHandlers, HAND_TOKUSEI_PoisonGuard_CheckAdd, HAND_TOKUSEI_PoisonGuard_CureOnEntry, HAND_TOKUSEI_PoisonGuard_CureOnPeriodicCheck, HAND_TOKUSEI_GetPoisonGuardHandlers, HAND_TOKUSEI_BurnGuard_CheckAdd, HAND_TOKUSEI_BurnGuard_CureOnEntry, HAND_TOKUSEI_BurnGuard_CureOnPeriodicCheck, HAND_TOKUSEI_GetBurnGuardHandlers, HAND_TOKUSEI_ConfusionGuard_CheckAdd, HAND_TOKUSEI_ConfusionGuard_ShowBlockedMessage, HAND_TOKUSEI_ConfusionGuard_CureOnEntry, HAND_TOKUSEI_ConfusionGuard_CureOnPeriodicCheck, HAND_TOKUSEI_GetConfusionGuardHandlers, HAND_TOKUSEI_InfatuationGuard_CheckAdd, HAND_TOKUSEI_InfatuationGuard_CureOnEntry, HAND_TOKUSEI_InfatuationGuard_CureOnPeriodicCheck, HAND_TOKUSEI_InfatuationGuard_ShowBlockedMoveMessage, HAND_TOKUSEI_GetInfatuationGuardHandlers, HAND_TOKUSEI_BlockSickIfTargeted, HAND_TOKUSEI_ShowSickGuardMessage, HAND_TOKUSEI_SickGuard_ShowBlockedMessage, HAND_TOKUSEI_CureSickIfOwner, HAND_TOKUSEI_CureSick, HAND_TOKUSEI_Drizzle_StartRain, HAND_TOKUSEI_GetDrizzleHandlers, HAND_TOKUSEI_Drought_StartSun, HAND_TOKUSEI_GetDroughtHandlers, HAND_TOKUSEI_SandStream_StartSandstorm, HAND_TOKUSEI_GetSandStreamHandlers, HAND_TOKUSEI_SnowWarning_StartHail, HAND_TOKUSEI_GetSnowWarningHandlers, HAND_TOKUSEI_StartWeather, HAND_TOKUSEI_WeatherLock_ClearWeather, HAND_TOKUSEI_WeatherLock_SetFailFlag, HAND_TOKUSEI_GetWeatherLockHandlers, HAND_TOKUSEI_IceBody_HealInHail, HAND_TOKUSEI_GetIceBodyHandlers, HAND_TOKUSEI_RainDish_HealInRain, HAND_TOKUSEI_GetRainDishHandlers, HAND_TOKUSEI_HealInWeather, HAND_TOKUSEI_SolarPower_DamageInSun, HAND_TOKUSEI_SolarPower_BoostSpecialAttackInSun, HAND_TOKUSEI_GetSolarPowerHandlers, HAND_TOKUSEI_StatLossGuard_BlockForeignDrop, HAND_TOKUSEI_StatLossGuard_BlockForeignChange, HAND_TOKUSEI_StatLossGuard_BlockTargetedA, HAND_TOKUSEI_StatLossGuard_BlockTargetedB, HAND_TOKUSEI_StatLossGuard_BlockIfFlagged, HAND_TOKUSEI_GetStatLossGuardHandlers, HAND_TOKUSEI_Simple_DoubleStatChange, HAND_TOKUSEI_Simple_SetOwnerFlag, HAND_TOKUSEI_GetSimpleHandlers, HAND_TOKUSEI_Hydration_CureStatusInRain, HAND_TOKUSEI_GetHydrationHandlers, HAND_TOKUSEI_ShedSkinOnTurnEnd, HAND_TOKUSEI_AddShedSkin, HAND_TOKUSEI_PoisonHealOnSickDamage, HAND_TOKUSEI_AddPoisonHeal, HAND_TOKUSEI_ShellArmorOnCriticalCheck, HAND_TOKUSEI_AddShellArmor, HAND_TOKUSEI_SuperLuckOnCriticalCheck, HAND_TOKUSEI_AddSuperLuck, HAND_TOKUSEI_AngerPointOnDamageReaction, HAND_TOKUSEI_AddAngerPoint, HAND_TOKUSEI_PoisonPointOnDamageReaction, HAND_TOKUSEI_AddPoisonPoint, HAND_TOKUSEI_StaticOnDamageReaction, HAND_TOKUSEI_AddStatic, HAND_TOKUSEI_FlameBodyOnDamageReaction, HAND_TOKUSEI_AddFlameBody, HAND_TOKUSEI_CuteCharmOnDamageReaction, HAND_TOKUSEI_AddCuteCharm, HAND_TOKUSEI_EffectSporeOnDamageReaction, HAND_TOKUSEI_AddEffectSpore, HAND_TOKUSEI_TryAddContactSick, HAND_TOKUSEI_RoughSkinOnDamageReaction, HAND_TOKUSEI_AddRoughSkin, HAND_TOKUSEI_AftermathOnDamageReaction, HAND_TOKUSEI_AddAftermath, HAND_TOKUSEI_ForecastOnWeatherChange, HAND_TOKUSEI_AddForecast, HAND_TOKUSEI_SynchronizeOnSickAdded, HAND_TOKUSEI_AddSynchronize, HAND_TOKUSEI_MoldBreakerOnAbilityCheck, HAND_TOKUSEI_AddMoldBreaker, HAND_TOKUSEI_CloudNineOnWeatherCheck, HAND_TOKUSEI_AddCloudNine, HAND_TOKUSEI_AddTrace, HAND_TOKUSEI_TraceOnMemberIn, HAND_TOKUSEI_NaturalCureOnMemberOut, HAND_TOKUSEI_AddNaturalCure, HAND_TOKUSEI_DownloadOnMemberIn, HAND_TOKUSEI_AddDownload, HAND_TOKUSEI_ForewarnOnMemberIn, HAND_TOKUSEI_AddForewarn, HAND_TOKUSEI_AnticipationOnMemberIn, HAND_TOKUSEI_AnticipationFoeIsThreat, HAND_TOKUSEI_AddAnticipation, HAND_TOKUSEI_FriskShowOpponentItem, HAND_TOKUSEI_GetFriskHandlers, HAND_TOKUSEI_GetSturdyHandlers, HAND_TOKUSEI_SturdyBlockOneHitKo, HAND_TOKUSEI_SturdyEndureFromFullHp, HAND_TOKUSEI_SturdyShowEndureMessage, HAND_TOKUSEI_UnawareNeutralizeStatStages, HAND_TOKUSEI_UnawareIgnoreAccuracyStage, HAND_TOKUSEI_UnawareIgnoreEvasionStage, HAND_TOKUSEI_GetUnawareHandlers, HAND_TOKUSEI_HeatproofHalveFirePower, HAND_TOKUSEI_HeatproofHalveBurnDamage, HAND_TOKUSEI_GetHeatproofHandlers, HAND_TOKUSEI_AbsorbCheckMoveType, HAND_TOKUSEI_AbsorbRecoverHp, HAND_TOKUSEI_AbsorbRaiseStat, HAND_TOKUSEI_DrySkinWeatherEffect, HAND_TOKUSEI_DrySkinBoostFireDamage, HAND_TOKUSEI_DrySkinAbsorbWater, HAND_TOKUSEI_GetDrySkinHandlers, HAND_TOKUSEI_WaterAbsorbAbsorbWater, HAND_TOKUSEI_GetWaterAbsorbHandlers, HAND_TOKUSEI_VoltAbsorbAbsorbElectric, HAND_TOKUSEI_GetVoltAbsorbHandlers, HAND_TOKUSEI_GetMotorDriveHandlers, HAND_TOKUSEI_MotorDriveAbsorbElectric, HAND_TOKUSEI_ScrappyIgnoreGhostImmunity, HAND_TOKUSEI_GetScrappyHandlers, HAND_TOKUSEI_SoundproofBlockSoundMove, HAND_TOKUSEI_GetSoundproofHandlers, HAND_TOKUSEI_LevitateSetFlag, HAND_TOKUSEI_LevitateShowMessage, HAND_TOKUSEI_LevitateClearFlag, HAND_TOKUSEI_GetLevitateHandlers, HAND_TOKUSEI_WonderGuardBlockMove, HAND_TOKUSEI_GetWonderGuardHandlers, HAND_TOKUSEI_TruantToggleLoafing, HAND_TOKUSEI_TruantStartLoafing, HAND_TOKUSEI_TruantShowMessage, HAND_TOKUSEI_TruantClearLoafing, HAND_TOKUSEI_GetTruantHandlers, HAND_TOKUSEI_DampBlockExplosion, HAND_TOKUSEI_DampShowMessage, HAND_TOKUSEI_DampAddSkipCheck, HAND_TOKUSEI_DampRemoveSkipCheck, HAND_TOKUSEI_DampRemoveSkipCheckForOwner, HAND_TOKUSEI_DampSkipAftermath, HAND_TOKUSEI_GetDampHandlers, HAND_TOKUSEI_FlashFireBoostFireDamage, HAND_TOKUSEI_FlashFireClearFlag, HAND_TOKUSEI_FlashFireAbsorbFire, HAND_TOKUSEI_GetFlashFireHandlers, HAND_TOKUSEI_BadDreamsHurtSleepers, HAND_TOKUSEI_GetBadDreamsHandlers, HAND_TOKUSEI_RunAwayCheckEscape, HAND_TOKUSEI_RunAway_ShowEscapeMessage, HAND_TOKUSEI_GetRunAwayHandlers, HAND_TOKUSEI_MoldBreaker_ShowAbilityMessage, HAND_TOKUSEI_MoldBreaker_SkipCheck, HAND_TOKUSEI_MoldBreaker_InstallSkipCheck, HAND_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent4, HAND_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent6A, HAND_TOKUSEI_GetMoldBreakerSkipCheckHandlers, HAND_TOKUSEI_Forecast_ApplyWeatherForm, HAND_TOKUSEI_Forecast_ApplyWeatherFormOnEntry, HAND_TOKUSEI_Forecast_RefreshWeatherForm, HAND_TOKUSEI_Forecast_ResetFormWhenActive, HAND_TOKUSEI_Forecast_ResetFormOnAbilityChange, HAND_TOKUSEI_Forecast_ResetFormOnEvent6A, HAND_TOKUSEI_Forecast_ResetForm, HAND_TOKUSEI_Forecast_SetFormForWeather, HAND_TOKUSEI_GetForecastHandlers, HAND_TOKUSEI_GetStormDrainHandlers, HAND_TOKUSEI_StormDrain_CheckRedirect, HAND_TOKUSEI_StormDrain_AbsorbWaterMove, HAND_TOKUSEI_GetLightningRodHandlers, HAND_TOKUSEI_LightningRod_CheckRedirect, HAND_TOKUSEI_Redirect_ShowMessage, HAND_TOKUSEI_LightningRod_AbsorbElectricMove, HAND_TOKUSEI_CheckRedirectMoveType, HAND_TOKUSEI_SuctionCups_BlockForcedSwitch, HAND_TOKUSEI_GetSuctionCupsHandlers, HAND_TOKUSEI_LiquidOoze_DamageAttacker, HAND_TOKUSEI_LiquidOoze_RemoveFactorOnEventA3, HAND_TOKUSEI_GetLiquidOozeHandlers, HAND_TOKUSEI_Klutz_SkipCheck, HAND_TOKUSEI_Klutz_InstallSkipCheck, HAND_TOKUSEI_Klutz_InstallSkipCheckOnEntry, HAND_TOKUSEI_Klutz_RemoveSkipCheck, HAND_TOKUSEI_Klutz_NoticeHeldItem, HAND_TOKUSEI_Klutz_BlockNaturalGift, HAND_TOKUSEI_Klutz_ShowBlockedMoveMessage, HAND_TOKUSEI_GetKlutzHandlers, HAND_TOKUSEI_StickyHold_BlockTrick, HAND_TOKUSEI_StickyHold_BlockItemRemoval, HAND_TOKUSEI_StickyHold_ShowMessage, HAND_TOKUSEI_GetStickyHoldHandlers, HAND_TOKUSEI_GetPressureHandlers, HAND_TOKUSEI_Pressure_ShowAbilityMessage, HAND_TOKUSEI_Pressure_AddPPCost, HAND_TOKUSEI_GetMagicGuardHandlers, HAND_TOKUSEI_MagicGuard_ClearEffectFlag, HAND_TOKUSEI_GetStenchHandlers, HAND_TOKUSEI_Stench_SetFlinchChance, HAND_TOKUSEI_GetShadowTagHandlers, HAND_TOKUSEI_ShadowTag_PreventEscape, HAND_TOKUSEI_GetArenaTrapHandlers, HAND_TOKUSEI_ArenaTrap_PreventEscape, HAND_TOKUSEI_GetMagnetPullHandlers, HAND_TOKUSEI_MagnetPull_BlockSteelEscape, HAND_TOKUSEI_GetUnburdenHandlers, HAND_TOKUSEI_Unburden_MarkItemLost, HAND_TOKUSEI_Unburden_DoubleSpeed, HAND_TOKUSEI_GetPickupHandlers, HAND_TOKUSEI_Pickup_TakeUsedItem, HAND_TOKUSEI_GetPickpocketHandlers, HAND_TOKUSEI_Pickpocket_StealOnContact, HAND_TOKUSEI_CursedBody_DisableAttackerMove, HAND_TOKUSEI_GetCursedBodyHandlers, HAND_TOKUSEI_WeakArmor_LowerDefenseRaiseSpeed, HAND_TOKUSEI_GetWeakArmorHandlers, HAND_TOKUSEI_SheerForce_BoostPower, HAND_TOKUSEI_SheerForce_BlockAddedEffect, HAND_TOKUSEI_SheerForce_BlockAttackerSideEffect, HAND_TOKUSEI_SheerForce_FlagNoAddedEffect, HAND_TOKUSEI_GetSheerForceHandlers, HAND_TOKUSEI_SheerForce_IsBoostedMove, HAND_TOKUSEI_Defiant_RaiseAttackOnStatDrop, HAND_TOKUSEI_GetDefiantHandlers, HAND_TOKUSEI_Defeatist_HalvePowerAtLowHp, HAND_TOKUSEI_GetDefeatistHandlers, HAND_TOKUSEI_Multiscale_HalveDamageAtFullHp, HAND_TOKUSEI_GetMultiscaleHandlers, HAND_TOKUSEI_FriendGuard_ReduceAllyDamage, HAND_TOKUSEI_GetFriendGuardHandlers, HAND_TOKUSEI_Healer_CureAllyStatus, HAND_TOKUSEI_GetHealerHandlers, HAND_TOKUSEI_ToxicBoost_BoostPhysicalPower, HAND_TOKUSEI_GetToxicBoostHandlers, HAND_TOKUSEI_FlareBoost_BoostSpecialPower, HAND_TOKUSEI_GetFlareBoostHandlers, HAND_TOKUSEI_Telepathy_AvoidAllyAttack, HAND_TOKUSEI_GetTelepathyHandlers, HAND_TOKUSEI_Moody_RaiseAndLowerStat, HAND_TOKUSEI_GetMoodyHandlers, HAND_TOKUSEI_Overcoat_BlockWeatherDamage, HAND_TOKUSEI_GetOvercoatHandlers, HAND_TOKUSEI_PoisonTouch_PoisonOnContact, HAND_TOKUSEI_GetPoisonTouchHandlers, HAND_TOKUSEI_Regenerator_RecoverOnSwitchOut, HAND_TOKUSEI_GetRegeneratorHandlers, HAND_TOKUSEI_GetIndirectGuardCause2Handlers, HAND_TOKUSEI_IndirectGuardCause2_Block, HAND_TOKUSEI_IndirectGuardCause2_ShowMessage, HAND_TOKUSEI_GetSandRushHandlers, HAND_TOKUSEI_SandRush_DoubleSpeedInSand, HAND_TOKUSEI_GetWonderSkinHandlers, HAND_TOKUSEI_WonderSkin_CapStatusMoveAccuracy, HAND_TOKUSEI_GetAnalyticHandlers, HAND_TOKUSEI_Analytic_BoostPowerWhenMovingLast, HAND_TOKUSEI_GetSandForceHandlers, HAND_TOKUSEI_SandForceBoostPower, HAND_TOKUSEI_ZenModeUpdateForm, HAND_TOKUSEI_ZenModeRevertForm, HAND_TOKUSEI_GetZenModeHandlers, HAND_TOKUSEI_InfiltratorSkipSideCondition, HAND_TOKUSEI_InfiltratorEnableSkip, HAND_TOKUSEI_InfiltratorDisableSkip, HAND_TOKUSEI_GetInfiltratorHandlers, HAND_TOKUSEI_GetMoxieHandlers, HAND_TOKUSEI_MoxieRaiseAttackOnKnockOut, HAND_TOKUSEI_GetJustifiedHandlers, HAND_TOKUSEI_JustifiedRaiseAttackOnDarkHit, HAND_TOKUSEI_GetRattledHandlers, HAND_TOKUSEI_RattledRaiseSpeedOnHit, HAND_TOKUSEI_GetMummyHandlers, HAND_TOKUSEI_MummySpreadAbility, HAND_TOKUSEI_SapSipperAbsorbGrass, HAND_TOKUSEI_GetSapSipperHandlers, HAND_TOKUSEI_PranksterRaiseStatusPriority, HAND_TOKUSEI_GetPranksterHandlers, HAND_TOKUSEI_MagicBounceReflectMove, HAND_TOKUSEI_MagicBounceCounterMove, HAND_TOKUSEI_MagicBounceReflectMoveWithWindow, HAND_TOKUSEI_AddMagicBounce, HAND_TOKUSEI_HarvestRestoreBerry, HAND_TOKUSEI_AddHarvest, HAND_TOKUSEI_AddHeavyMetal, HAND_TOKUSEI_HeavyMetalDoubleWeight, HAND_TOKUSEI_AddLightMetal, HAND_TOKUSEI_LightMetalHalveWeight, HAND_TOKUSEI_ContraryInvertStatChange, HAND_TOKUSEI_AddContrary, HAND_TOKUSEI_UnnerveOnOwnerEnter, HAND_TOKUSEI_UnnerveAnnounce, HAND_TOKUSEI_UnnerveSkipBerry, HAND_TOKUSEI_AddUnnerve, HAND_TOKUSEI_ImposterTransform, HAND_TOKUSEI_AddImposter, HAND_TOKUSEI_AddIllusion, HAND_TOKUSEI_IllusionBreakOnHit, HAND_TOKUSEI_IllusionBreakOnOwnerEvent, HAND_TOKUSEI_IllusionBreakOnAbilityChange, HAND_TOKUSEI_IllusionBreak, HAND_TOKUSEI_AddVictoryStar, HAND_TOKUSEI_VictoryStarBoostAccuracy, HAND_ITEM_AddFactor, HAND_ITEM_RemoveUnforcedFactors, HAND_ITEM_AddHeldItemFactor, HAND_ITEM_AddForcedFactor, HAND_ITEM_RemoveFactor, HAND_ITEM_DisablePokeFactors, HAND_ITEM_EnablePokeFactors, HAND_ITEM_RollChance, HAND_ITEM_GetParam, HAND_ITEM_GetBoostRatio, HAND_ITEM_PushUseItem, HAND_ITEM_CheriBerryOnTrigger, HAND_ITEM_CheriBerryOnEaten, HAND_ITEM_AddCheriBerry, HAND_ITEM_ChestoBerryOnTrigger, HAND_ITEM_ChestoBerryOnEaten, HAND_ITEM_AddChestoBerry, HAND_ITEM_RawstBerryOnTrigger, HAND_ITEM_RawstBerryOnEaten, HAND_ITEM_AddRawstBerry, HAND_ITEM_AspearBerryOnTrigger, HAND_ITEM_AspearBerryOnEaten, HAND_ITEM_AddAspearBerry, HAND_ITEM_PersimBerryOnTrigger, HAND_ITEM_PersimBerryOnEaten, HAND_ITEM_AddPersimBerry, HAND_ITEM_PechaBerryOnTrigger, HAND_ITEM_PechaBerryOnEaten, HAND_ITEM_AddPechaBerry, HAND_ITEM_LumBerryOnTrigger, HAND_ITEM_LumBerryOnEaten, HAND_ITEM_AddLumBerry, HAND_ITEM_CureSickOnTrigger, HAND_ITEM_CureSickOnEaten, HAND_ITEM_CheckHasSick, HAND_ITEM_AddLeppaBerry, HAND_ITEM_LeppaBerryOnLastMoveEmpty, HAND_ITEM_LeppaBerryOnAnyMoveEmptyChecked, HAND_ITEM_LeppaBerryOnAnyMoveEmpty, HAND_ITEM_LeppaBerryClaimTrigger, HAND_ITEM_LeppaBerryOnEaten, HAND_ITEM_LeppaBerryOnForcedUse, HAND_ITEM_FindLastMoveEmptySlot, HAND_ITEM_FindEmptyMoveSlot, HAND_ITEM_PushRecoverPp, HAND_ITEM_AddOranBerry, HAND_ITEM_RecoverHpOnTrigger, HAND_ITEM_RecoverHpOnCheck, HAND_ITEM_RecoverHpOnLowHp, HAND_ITEM_RecoverFixedHpOnEaten, HAND_ITEM_AddBerryJuice, HAND_ITEM_AddSitrusBerry
 * address:  0x021D8484
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btl_calc.c, btl_action_word.c, hand_tokusei.c by tools/splitfile.py.
 *
 * symbols:
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   WAZA_TOOL_GetParam   0x0201BD28  thumb
 *   WAZA_TOOL_GetFlag   0x0201BEB8  thumb
 *   gInnerFocusHandlers     0x021F0710  data   ov093  a4
 *   BTL_EVENT_AddFactor  0x021D6F0C  thumb  ov093
 *   gAbilityHandlerRegistry     0x021F0E74  data  ov093
 *   BTL_EVENT_FindFactor 0x021D732C thumb ov093
 *   BTL_EVENT_RemoveFactor 0x021D7040 thumb ov093
 *   BTL_EVENT_DisablePokeFactors 0x021D7404 thumb ov093
 *   BTL_EVENT_EnablePokeFactors 0x021D7438 thumb ov093
 *   func_021D58A8 0x021D58A8 thumb ov093
 *   gIntimidateHandlers 0x021F08C0 data ov093 a4
 *   BTL_CALC_RollPercent 0x021D7AF0 thumb ov093
 *   BTL_SERVER_FLOW_QueryMainFlag 0x021C82B8 thumb ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SERVER_FLOW_GetScratchBuffer  0x021C8120  thumb  ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds  0x021C7F68  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb
 *   gSteadfastHandlers     0x021F07B0  data   ov093  a4
 *   gThickFatHandlers     0x021F05B8  data   ov093  a4
 *   gHugePowerHandlers 0x021F07C8 data ov093 a4
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   gSwiftSwimHandlers 0x021F0740 data ov093 a4
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk 0x021C8288 thumb ov093
 *   gChlorophyllHandlers 0x021F05D8 data a4
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   gTangledFeetHandlers 0x021F0668 data ov093 a4
 *   BTL_CALC_MulRatio  0x021D7B10  thumb  ov093
 *   gQuickFeetHandlers     0x021F0748  data   ov093  a4
 *   HAND_TOKUSEI_PackAbilityHandlerInfo 0x021D84F0 thumb ov093
 *   gStallHandlers 0x021F05A0 data a4
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_GetActionWordByPokeId   0x021C804C  thumb ov093
 *   gHustleHandlers     0x021F09C0  data   ov093  a4
 *   gCompoundEyesHandlers 0x021F0650 data a4
 *   gSlowStartHandlers     0x021F0D6C  data   ov093  a4
 *   gSandVeilHandlers     0x021F09E0  data   ov093  a4
 *   gTintedLensHandlers 0x021F0738 data a4
 *   BTL_CALC_SummarizeTypeAffinity 0x021D7AD4 thumb ov093
 *   gSnowCloakHandlers     0x021F09F0  data   ov093  a4
 *   gFilterHandlers 0x021F07C0 data a4
 *   gSniperHandlers 0x021F07B8 data a4
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   gSpeedBoostHandlers     0x021F0698  data   ov093  a4
 *   BTL_CALC_DivideMaxHp  0x021D7B60  thumb  ov093
 *   gAdaptabilityHandlers     0x021F07D8  data   ov093  a4
 *   gBlazeHandlers     0x021F06B0  data   ov093  a4
 *   gTorrentHandlers     0x021F0610  data   ov093  a4
 *   gOvergrowHandlers     0x021F0648  data   ov093  a4
 *   gSwarmHandlers     0x021F0640  data   ov093  a4
 *   gGutsHandlers     0x021F0638  data   ov093  a4
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   gPlusMinusHandlers     0x021F06A0  data   ov093  a4
 *   gFlowerGiftHandlers     0x021F0E1C  data   ov093  a4
 *   gTechnicianHandlers 0x021F0608 data a4
 *   gRivalryHandlers     0x021F07E0  data   ov093  a4
 *   gIronFistHandlers 0x021F0758 data a4
 *   gMarvelScaleHandlers     0x021F06A8  data   ov093  a4
 *   gRecklessHandlers     0x021F0720  data   ov093  a4
 *   gMoldBreakerFlagHandlers     0x021F0618  data   ov093  a4
 *   gIndirectGuardCause1Handlers     0x021F0880  data   ov093  a4
 *   gIndirectGuardCause6Handlers     0x021F0890  data   ov093  a4
 *   gHalveResidualDamageHandlers 0x021F06B8 data a4
 *   BTL_CALC_HasDefaultSickCont 0x021D7D6C thumb ov093
 *   gLeafGuardHandlers 0x021F0A40 data a4
 *   gIndirectGuardCause8Handlers     0x021F08A0  data   ov093  a4
 *   gParalysisGuardHandlers     0x021F0BFC  data   ov093  a4
 *   gSleepGuardHandlers     0x021F0D3C  data   ov093  a4
 *   gFreezeGuardHandlers     0x021F0C4C  data   ov093  a4
 *   gPoisonGuardHandlers     0x021F0C74  data   ov093  a4
 *   gConfusionGuardHandlers     0x021F0BB4  data   ov093  a4
 *   gBurnGuardHandlers     0x021F0C9C  data   ov093  a4
 *   gInfatuationGuardHandlers     0x021F0CC4  data   ov093  a4
 *   gDrizzleHandlers     0x021F08D0  data   ov093  a4
 *   gDroughtHandlers     0x021F08E0  data   ov093  a4
 *   gSandStreamHandlers     0x021F08F0  data   ov093  a4
 *   gSnowWarningHandlers     0x021F0900  data   ov093  a4
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   gSolarPowerHandlers     0x021F0930  data   ov093  a4
 *   gStatLossGuardHandlers 0x021F0CEC data a4
 *   HAND_COMMON_IsMoveTarget 0x021E85F8 thumb ov093
 *   gWeatherLockHandlers     0x021F0910  data   ov093  a4
 *   gIceBodyHandlers     0x021F05C0  data   ov093  a4
 *   gRainDishHandlers     0x021F0670  data   ov093  a4
 *   gHydrationHandlers     0x021F05A8  data   a4
 *   gSimpleHandlers     0x021F0A88  data   ov093  a4
 *   BTL_ID_IsAbilityTraceBlocked  0x0689C944  thumb
 *   HAND_TOKUSEI_RollChanceOrFlag  0x021D85C0  thumb  ov093
 *   gShedSkinHandlers     0x021F0878  data   ov093  a4
 *   gPoisonHealHandlers     0x021F0870  data   ov093  a4
 *   gSuperLuckHandlers 0x021F0860 data a4
 *   func_021D5D50   0x021D5D50  thumb ov093
 *   gShellArmorHandlers     0x021F0868  data   ov093  a4
 *   gPoisonPointHandlers 0x021F0850 data a4
 *   BTL_CALC_MakeDefaultSickCont 0x021D7D18 thumb ov093
 *   gStaticHandlers 0x021F0848 data a4
 *   gFlameBodyHandlers 0x021F0840 data a4
 *   BTL_SERVER_FLOW_CheckShowdownThunk  0x021C83D4  thumb  ov093
 *   BTL_CALC_MakeSickContFromKind  0x021D7DC0  thumb  ov093
 *   gCuteCharmHandlers     0x021F0838  data   ov093  a4
 *   BTL_CALC_Random   0x021D78AC  thumb ov093
 *   gAngerPointHandlers     0x021F0858  data   ov093  a4
 *   BTL_POKEPARAM_IsFainted   0x021D5B68  thumb ov093
 *   gEffectSporeHandlers     0x021F0830  data   ov093  a4
 *   gRoughSkinHandlers     0x021F0828  data   ov093  a4
 *   BTLV_CORE_PackByteTwice   0x021E8CF0  thumb ov093
 *   gAftermathHandlers     0x021F0820  data   ov093  a4
 *   BTLV_CORE_IsSlotKind1Index15   0x021E8A78  thumb ov093
 *   gForecastHandlerEntries     0x021F0818  data   ov093  a4
 *   gSynchronizeHandlers     0x021F0810  data   ov093  a4
 *   gMoldBreakerHandlerEntries     0x021F0808  data   ov093  a4
 *   BTL_MAIN_IsPosInTable 0x021B9A6C thumb ov093
 *   BTL_SERVER_FLOW_GetRule 0x021C815C thumb ov093
 *   gCloudNineHandlers     0x021F0800  data   ov093  a4
 *   gTraceHandlers     0x021F07F8  data   ov093  a4
 *   gNaturalCureHandlers 0x021F07F0 data a4
 *   gDownloadHandlers     0x021F0970  data   ov093  a4
 *   BTL_SERVER_FLOW_CollectOpponentPokeIds   0x021C7D54  thumb ov093
 *   gAnticipationHandlers     0x021F09A0  data   ov093  a4
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   WAZA_TOOL_GetPower 0x0201C1D8 thumb
 *   WAZA_TOOL_GetCategory 0x0201C1BC thumb
 *   gForewarnHandlers 0x021F0980 data a4
 *   BTL_POKEPARAM_GetTypePair   0x021D57FC  thumb ov093
 *   WAZA_TOOL_IsDamaging   0x0201C314  thumb
 *   WAZA_TOOL_GetType    0x0201C1C8  thumb
 *   BTL_CALC_GetTypeAffinityVsPair   0x021D799C  thumb ov093
 *   BTL_EVENT_SetFactorSkipCheck  0x021D7320  thumb  ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   gFriskHandlers 0x021F09B0 data a4
 *   gSturdyHandlers 0x021F0B00 data a4
 *   BTL_POKEPARAM_IsHpFull 0x021D5B48 thumb ov093
 *   BTL_CALC_Max   0x021D7B08  thumb ov093
 *   gUnawareHandlers     0x021F0B18  data   ov093  a4
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   gDrySkinHandlers 0x021F0B30 data a4
 *   gWaterAbsorbHandlers 0x021F0730 data a4
 *   gMotorDriveHandlers 0x021F0798 data a4
 *   gScrappyHandlers 0x021F0790 data a4
 *   gHeatproofHandlers     0x021F09D0  data   ov093  a4
 *   gLevitateHandlers 0x021F0A10 data a4
 *   gSoundproofHandlers     0x021F0788  data   ov093  a4
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   gTruantHandlers 0x021F0B94 data a4
 *   gWonderGuardHandlers     0x021F0660  data   ov093  a4
 *   BTL_EVENT_ClearFactorSkipCheck  0x021D7324  thumb  ov093
 *   BTLV_CORE_EventSetFlagIfAttacker  0x021E8878  thumb  ov093
 *   gDampHandlers     0x021F0BD4  data   ov093  a4
 *   gBadDreamsHandlers 0x021F07E8 data a4
 *   gFlashFireHandlers     0x021F0A28  data   ov093  a4
 *   BTL_ID_IsGemIgnoredMove  0x0689C8EC  thumb
 *   BTL_ID_IsAbilityIgnoredByMoldBreaker  0x0689C9B0  thumb
 *   BTLV_CORE_EventTrySetFlagIfAttacker  0x021E889C  thumb  ov093
 *   BTL_SERVER_FLOW_SetMsgRecordSe  0x021C888C  thumb  ov093
 *   gRunAwayHandlers     0x021F08B0  data   ov093  a4
 *   gMoldBreakerSkipCheckHandlers 0x021F0C24 data a4
 *   gLightningRodHandlers 0x021F0A70 data a4
 *   BTL_SERVER_FLOW_CheckAllyMoveAutoHitById  0x021C8290  thumb  ov093
 *   gForecastHandlers     0x021F0DD4  data   ov093  a4
 *   gStormDrainHandlers     0x021F0A58  data   ov093  a4
 *   BTL_EVENT_MarkFactorDead   0x021D7090  thumb
 *   gSuctionCupsHandlers     0x021F05F0  data   ov093  a4
 *   gLiquidOozeHandlers     0x021F0920  data   ov093  a4
 *   BTL_ID_IsPressureNoExtraPpMove  0x0689C8DC  thumb
 *   BTL_EVENT_GetFactorPokeId  0x021D70AC  thumb  ov093
 *   gKlutzExemptItemIds     0x021F0B78  data   a2
 *   gKlutzHandlers     0x021F0D9C  data   ov093  a4
 *   gStickyHoldHandlers     0x021F0AA0  data   ov093  a4
 *   gPressureHandlers     0x021F0AB8  data   ov093  a4
 *   gMagicGuardHandlers 0x021F06F8 data a4
 *   gShadowTagHandlers 0x021F06E8 data a4
 *   gStenchHandlers     0x021F06F0  data   ov093  a4
 *   BTL_SERVER_FLOW_IsPokeGroundedById  0x021C8234  thumb  ov093
 *   gArenaTrapHandlers     0x021F06E0  data   ov093  a4
 *   gMagnetPullHandlers     0x021F06D8  data   ov093  a4
 *   BTL_ID_IsMetronomeItemIgnoredMove  0x0689C8CC  thumb  ov095
 *   gUnburdenHandlers     0x021F0960  data   ov093  a4
 *   BTL_POKEPARAM_GetConsumedItem 0x021D6740 thumb ov093
 *   gPickpocketHandlers 0x021F06C0 data a4
 *   BTLV_CORE_CheckEitherSlotPair  0x021E86E8  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2  0x021E896C  thumb  ov093
 *   gPickupHandlers     0x021F06C8  data   ov093  a4
 *   gCursedBodyHandlers 0x021F0718 data a4
 *   gSheerForceHandlers 0x021F0D14 data a4
 *   WAZA_TOOL_GetRankEffectCount  0x0201C020  thumb
 *   WAZA_TOOL_GetRankEffect  0x0201C0BC  thumb
 *   gWeakArmorHandlers     0x021F07D0  data   ov093  a4
 *   gDefiantHandlers     0x021F0688  data   ov093  a4
 *   gMultiscaleHandlers 0x021F0690 data a4
 *   gDefeatistHandlers     0x021F07A8  data   ov093  a4
 *   gFriendGuardHandlers 0x021F0780 data a4
 *   gHealerHandlers     0x021F0778  data   ov093  a4
 *   gToxicBoostHandlers     0x021F0768  data   ov093  a4
 *   gFlareBoostHandlers     0x021F0620  data   ov093  a4
 *   gTelepathyHandlers     0x021F05E8  data   ov093  a4
 *   gMoodyHandlers 0x021F0658 data a4
 *   gOvercoatHandlers 0x021F05F8 data a4
 *   gPoisonTouchHandlers 0x021F0600 data a4
 *   gRegeneratorHandlers     0x021F0700  data   ov093  a4
 *   gIndirectGuardCause2Handlers     0x021F0940  data   ov093  a4
 *   gWonderSkinHandlers 0x021F06D0 data a4
 *   gAnalyticHandlers 0x021F0628 data a4
 *   HAND_COMMON_IsLastToAct 0x021E8624 thumb ov093
 *   gSandRushHandlers     0x021F0950  data   ov093  a4
 *   gSandForceHandlers 0x021F0990 data a4
 *   BTL_MAIN_IsPokeIdInSecondPair 0x021B9A40 thumb ov093
 *   gZenModeHandlers     0x021F0B48  data   ov093  a4
 *   gInfiltratorHandlers     0x021F0A00  data   ov093  a4
 *   gMoxieHandlers     0x021F0770  data   ov093  a4
 *   gJustifiedHandlers     0x021F05D0  data   ov093  a4
 *   gRattledHandlers     0x021F05B0  data   ov093  a4
 *   gSapSipperHandlers 0x021F05C8 data a4
 *   gMummyHandlers     0x021F0678  data   ov093  a4
 *   BTLV_CORE_EventCounterMove  0x021E8798  thumb  ov093
 *   BTLV_CORE_EventRedirectMove  0x021E8744  thumb  ov093
 *   gPranksterHandlers     0x021F0630  data   ov093  a4
 *   BTLV_CORE_EventQueueMoveNotice  0x021E8804  thumb  ov093
 *   ITEM_IsBerry  0x020213C0  thumb
 *   gMagicBounceHandlers     0x021F0AD0  data   ov093  a4
 *   gLightMetalHandlers 0x021F05E0 data a4
 *   gContraryHandlers 0x021F0708 data a4
 *   BTL_MAIN_IsZero  0x021B9A5C  thumb  ov093
 *   gUnnerveHandlers 0x021F0AE8 data a4
 *   BTL_MAIN_GetFacingPos  0x021B8C5C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeIdAtFieldIndex  0x021C8020  thumb  ov093
 *   gHarvestHandlers     0x021F0728  data   ov093  a4
 *   gHeavyMetalHandlers     0x021F0680  data   ov093  a4
 *   BTL_POKEPARAM_IsIllusionActive  0x021D6C24  thumb  ov093
 *   gImposterHandlers     0x021F0750  data   ov093  a4
 *   gIllusionHandlers     0x021F0B60  data   ov093  a4
 *   gItemHandlerRegistry     0x021F1EA4  data  ov093
 *   BTL_EVENT_FindNextFactor  0x021D7360  thumb  ov093
 *   BTL_EVENT_GetFactorWork  0x021D70B4  thumb  ov093
 *   BTL_EVENT_EnableFactorSpecialEvent 0x021D70BC thumb ov093
 *   BTL_EVENT_SetFactorWork 0x021D70DC thumb ov093
 *   BTL_CALC_GetMonParamWithHeap   0x021D805C  thumb
 *   BTL_EVENT_KeepFactorRunning 0x021D70C8 thumb ov093
 *   gCheriBerryHandlers 0x021F1AC4 data a4
 *   gChestoBerryHandlers 0x021F1AEC data a4
 *   gRawstBerryHandlers 0x021F1DE4 data a4
 *   gAspearBerryHandlers 0x021F1B14 data a4
 *   gPersimBerryHandlers 0x021F1B3C data a4
 *   gPechaBerryHandlers 0x021F1B64 data a4
 *   gLumBerryHandlers 0x021F1B8C data a4
 *   BTL_EVENT_TryGetVar  0x021D778C  thumb  ov093
 *   BTL_CALC_FindMajorSick  0x021D7E10  thumb  ov093
 *   gVictoryStarHandlers     0x021F0760  data   ov093  a4
 *   BTL_POKEPARAM_GetLastSelectedMoveId 0x021D67B8 thumb ov093
 *   BTL_POKEPARAM_FindMoveSlot 0x021D5778 thumb ov093
 *   BTL_POKEPARAM_GetMovePPChecked 0x021D5584 thumb ov093
 *   BTL_POKEPARAM_GetMovePPLost 0x021D554C thumb ov093
 *   gOranBerryHandlers 0x021F1BB4 data a4
 *   HAND_ITEM_HpBerryCheckAndUse 0x021DDE30 thumb ov093
 *   HAND_ITEM_IsHpAtOrBelowFraction 0x021DDEA4 thumb ov093
 *   gLeppaBerryHandlers     0x021F1E6C  data   ov093  a4
 *   gBerryJuiceHandlers     0x021F1AA4  data   ov093  a4
 *   gSitrusBerryHandlers     0x021F1BDC  data   ov093  a4
 */
#include "btl_action_word_types.h"
#include "hand_tokusei_types.h"

extern struct BtlEventFactor *BTL_EVENT_FindFactor(int factorType, int pokeId);

extern void BTL_EVENT_DisablePokeFactors(u32 pokeId, int factorType);

extern int BTL_EVENT_EnablePokeFactors(int pokeId, int factorType);

int BTL_SERVER_FLOW_QueryMainFlag(struct BtlServerFlow *flow, int flagId);

u8 *BTL_SERVER_FLOW_GetScratchBuffer(struct BtlServerFlow *flow, int bufferId);

u8 BTL_SERVER_FLOW_CollectAlivePokeIds(struct BtlServerFlow *flow, int posKey, u8 *out);

void BTL_SERVER_FLOW_PushCmdRecord(struct BtlServerFlow *flow, int kind, int pokeId);

struct BtlEventFactor *HAND_TOKUSEI_AddAbilityHandlers(struct BtlPokeParam *bpp);

unsigned int HAND_TOKUSEI_PackAbilityHandlerInfo(unsigned int priority, unsigned int handlerCount);

int HAND_TOKUSEI_UnpackAbilityPriority(u32 *packedInfo);

void HAND_TOKUSEI_RemoveAbilityHandlers(struct BtlPokeParam *bpp);

void HAND_TOKUSEI_DisableAbilityHandlers(struct BtlPokeParam *bpp);

void HAND_TOKUSEI_EnableAbilityHandlers(struct BtlPokeParam *bpp);

void HAND_TOKUSEI_SwapAbilityHandlers(struct BtlPokeParam *bppA, struct BtlPokeParam *bppB);

u16 HAND_TOKUSEI_GetPokeSpeed(struct BtlPokeParam *bpp);

int HAND_TOKUSEI_RollChanceOrFlag(struct BtlServerFlow *flow, u32 percent);

u8 *HAND_TOKUSEI_GetIntimidateHandlers(u32 *packedInfo);

void HAND_TOKUSEI_IntimidateOnEnter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

int *HAND_TOKUSEI_GetInnerFocusHandlers(int *packedInfo);

extern AbilityHandlerEntry gAbilityHandlerRegistry[ABILITY_REGISTRY_COUNT];

extern u8 gIntimidateHandlers[];

extern int gInnerFocusHandlers[];

/* Adds the handler table of the ability that the poke holds to the event factor list. */
struct BtlEventFactor *HAND_TOKUSEI_AddAbilityHandlers(struct BtlPokeParam *bpp)
{
    u16 abilityId = func_021D59B4(bpp, 0x10);
    u32 i;
    u32 speed;
    u8 pokeId;
    int priority;
    u32 handlerCount;
    u32 handlers;

    for (i = 0; i < ABILITY_REGISTRY_COUNT; i++) {
        if (abilityId == gAbilityHandlerRegistry[i].abilityId) {
            speed = HAND_TOKUSEI_GetPokeSpeed(bpp);
            pokeId = BTL_POKEPARAM_GetPokeId(bpp);
            handlers = gAbilityHandlerRegistry[i].getHandlers(&handlerCount);
            priority = HAND_TOKUSEI_UnpackAbilityPriority(&handlerCount);
            return BTL_EVENT_AddFactor(BTL_EVENT_TYPE_ABILITY, abilityId, priority, speed, pokeId, (BtlEventHandler *)handlers, handlerCount);
        }
    }
    return 0;
}

/* Packs the factor priority into the high half and the handler count into the low half. */
unsigned int HAND_TOKUSEI_PackAbilityHandlerInfo(unsigned int priority, unsigned int handlerCount)
{
    return (priority << 16) | handlerCount;
}

/* Splits the packed info: leaves the handler count in place and returns the priority (5 when none is packed). */
int HAND_TOKUSEI_UnpackAbilityPriority(u32 *packedInfo) { u16 priority = *packedInfo >> 16; if (priority == 0) priority = ABILITY_DEFAULT_PRIORITY; *packedInfo &= 65535; return priority; }

void HAND_TOKUSEI_RemoveAbilityHandlers(struct BtlPokeParam *bpp) { int pokeId = BTL_POKEPARAM_GetPokeId(bpp); struct BtlEventFactor *factor; while ((factor=BTL_EVENT_FindFactor(BTL_EVENT_TYPE_ABILITY,pokeId)) != 0) { BTL_EVENT_RemoveFactor(factor); } }

void HAND_TOKUSEI_DisableAbilityHandlers(struct BtlPokeParam *bpp) { BTL_EVENT_DisablePokeFactors(BTL_POKEPARAM_GetPokeId(bpp),BTL_EVENT_TYPE_ABILITY); }

void HAND_TOKUSEI_EnableAbilityHandlers(struct BtlPokeParam *bpp) { if (!BTL_EVENT_EnablePokeFactors(BTL_POKEPARAM_GetPokeId(bpp),BTL_EVENT_TYPE_ABILITY)) HAND_TOKUSEI_AddAbilityHandlers(bpp); }

/* Swaps the abilities of two pokes: removes both handler sets, then adds both again. */
void HAND_TOKUSEI_SwapAbilityHandlers(struct BtlPokeParam *bppA, struct BtlPokeParam *bppB)
{
    int pokeIdA = BTL_POKEPARAM_GetPokeId(bppA);
    int pokeIdB = BTL_POKEPARAM_GetPokeId(bppB);
    struct BtlEventFactor *factorA = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_ABILITY, pokeIdA);
    struct BtlEventFactor *factorB = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_ABILITY, pokeIdB);

    if (factorA != 0)
        BTL_EVENT_RemoveFactor(factorA);
    if (factorB != 0)
        BTL_EVENT_RemoveFactor(factorB);
    HAND_TOKUSEI_AddAbilityHandlers(bppA);
    HAND_TOKUSEI_AddAbilityHandlers(bppB);
}

u16 HAND_TOKUSEI_GetPokeSpeed(struct BtlPokeParam *bpp) { return func_021D58A8(bpp,12); }

/* True after a percent roll succeeds, or when the flow flag 1 is set. */
int HAND_TOKUSEI_RollChanceOrFlag(struct BtlServerFlow *flow, u32 percent) { int result; if (BTL_CALC_RollPercent(percent)) return 1; result=BTL_SERVER_FLOW_QueryMainFlag(flow,1)!=0; return result; }

u8 *HAND_TOKUSEI_GetIntimidateHandlers(u32 *packedInfo) { *packedInfo=2; return gIntimidateHandlers; }

/* Intimidate: lowers the attack of every opposing poke when the owner enters. */
void HAND_TOKUSEI_IntimidateOnEnter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    int pos;
    u8 *targets;
    int targetCount;
    u32 i;
    BtlRankCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    pos = BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, pokeId);
    targets = BTL_SERVER_FLOW_GetScratchBuffer(flow, 6);
    targetCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(pos | 0x100), targets);
    if (targetCount == 0)
        return;
    BTL_SERVER_FLOW_PushCmdRecord(flow, 2, pokeId);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 0xe, pokeId);
    cmd->statId = 1;
    cmd->amount = -1;
    cmd->showMessage = 1;
    cmd->targetCount = targetCount;
    for (i = 0; i < (u32)targetCount; i++)
        cmd->targets[i] = targets[i];
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    BTL_SERVER_FLOW_PushCmdRecord(flow, 3, pokeId);
}

/* Inner Focus: handler table. */
int *HAND_TOKUSEI_GetInnerFocusHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gInnerFocusHandlers;
}

#define SLOW_START_TURNS 5

#define BTL_STR_SLOW_START_BEGIN 0x1F0

#define BTL_STR_SLOW_START_END 0x1F3

#define MOVE_MIRROR_COAT 243

#define MOVE_METAL_BURST 368

#define MOVE_CATEGORY_OHKO 9

#define MOVE_NATURAL_GIFT 0x16B

#define MOVE_TRICK 0x10F

#define MOVE_SWITCHEROO 0x19F

#define BTL_FAIL_REASON_ITEM_UNUSABLE 0x13

#define STENCH_FLINCH_CHANCE 10

#define OPPONENT_ID_BUFFER_SIZE 4

struct BtlMessage;

/* Slow Start state kept in the factor work area. */
typedef struct {
    int started;
    int turnCount;
    int finished;
    int active;
} SlowStartWork;

/* Header word of the server command made by BTL_SERVER_FLOW_AllocCmdRecord. */
struct BtlCmdHeader { u32 lowBits : 23; u32 announce : 1; u32 kind : 8; };

/* One candidate move Forewarn may reveal: the foe that owns it and the move. */
typedef struct { u8 pokeId, pad; u16 moveId; } ForewarnCandidate;

/* The work area of a Klutz factor. */
typedef struct KlutzWork {
    int skipCheckSet;
    int pad04;
    int moveBlocked;
} KlutzWork;

/* The number of turns of Disable: 4, or 5 when the target has already acted this turn. */
typedef enum { DISABLE_TURNS_BASE = 4, DISABLE_TURNS_ACTED = 5 } DisableTurns;

extern int WAZA_TOOL_GetDamageType(int moveId);

extern u32 WAZA_TOOL_GetParam(u16 moveId, u32 field);

extern int BTL_CALC_HasDefaultSickCont(int condition);

extern int HAND_COMMON_IsMoveTarget(int pokeId);

int func_021D5D50(struct BtlPokeParam *pokeParam, int rankKind);

extern int BTL_SERVER_FLOW_CheckShowdownThunk(struct BtlServerFlow *flow);

extern void BTL_CALC_MakeSickContFromKind(int sickKind, struct BtlPokeParam *attacker, union SickCont *out);

extern u32 BTL_CALC_Random(u32 range);

extern int BTLV_CORE_IsSlotKind1Index15(union SickCont sickCont);

extern int BTL_ID_IsAbilityTraceBlocked(u16 abilityId);

extern int BTL_MAIN_IsPosInTable(int mask, u32 slot);

extern u8 BTL_POKEPARAM_GetMoveCount(struct BtlPokeParam *pokeParam);

extern u16 BTL_POKEPARAM_GetMoveId(struct BtlPokeParam *pokeParam, int moveIndex);

extern u16 WAZA_TOOL_GetPower(u16 moveId);

extern u32 WAZA_TOOL_GetCategory(u16 moveId);

extern u16 BTL_POKEPARAM_GetTypePair(struct BtlPokeParam *pokeParam);

extern u8 WAZA_TOOL_GetType(u16 moveId);

extern int BTL_CALC_GetTypeAffinityVsPair(int attackType, int defenderTypes);

extern void BTLV_CORE_EventSetFlagIfAttacker(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int unusedArg);

/* Ability handlers: Run Away, Mold Breaker (and Turboblaze, Teravolt), Forecast, Storm Drain, Lightning Rod. */
extern int BTLV_CORE_EventTrySetFlagIfAttacker(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

extern int BTL_ID_IsAbilityIgnoredByMoldBreaker(unsigned short abilityId);

extern int BTL_ID_IsGemIgnoredMove(int moveId);

extern int BTL_SERVER_FLOW_CheckAllyMoveAutoHitById(struct BtlServerFlow *flow, int attackerId, int defenderId, int moveId);

extern int BTL_ID_IsPressureNoExtraPpMove(int moveId);

extern u16 BTL_POKEPARAM_GetConsumedItem(struct BtlPokeParam *bpp);

extern int BTLV_CORE_CheckEitherSlotPair(struct BtlServerFlow *flow, int pokeIdA, int pokeIdB);

extern int func_021D5D14(struct BtlPokeParam *bpp, int statId, int direction);

extern u8 WAZA_TOOL_GetRankEffectCount(u16 moveId);

extern u8 WAZA_TOOL_GetRankEffect(u16 moveId, u32 index, s32 *out);

extern u32 BTL_CALC_DivideMaxHp(struct BtlPokeParam *bpp, u32 divisor);

extern int BTL_POKEPARAM_IsHpFull(struct BtlPokeParam *bpp);

extern int HAND_COMMON_IsLastToAct(struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_InnerFocusPreventFlinch(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

int *HAND_TOKUSEI_GetSteadfastHandlers(int *packedInfo);

void HAND_TOKUSEI_SteadfastOnFlinch(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

int *HAND_TOKUSEI_GetThickFatHandlers(int *packedInfo);

void HAND_TOKUSEI_ThickFatHalveFireIce(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

u8 *HAND_TOKUSEI_GetHugePowerHandlers(u32 *packedInfo);

void HAND_TOKUSEI_HugePowerDoubleAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_SwiftSwimDoubleSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

u8 *HAND_TOKUSEI_GetSwiftSwimHandlers(u32 *packedInfo);

void HAND_TOKUSEI_ChlorophyllDoubleSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

u8 *HAND_TOKUSEI_GetChlorophyllHandlers(u32 *packedInfo);

void HAND_TOKUSEI_QuickFeetBoostSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

int *HAND_TOKUSEI_GetQuickFeetHandlers(int *packedInfo);

void HAND_TOKUSEI_TangledFeetHalveAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

u8 *HAND_TOKUSEI_GetTangledFeetHandlers(u32 *packedInfo);

void HAND_TOKUSEI_HustleLowerAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_HustleBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

int *HAND_TOKUSEI_GetHustleHandlers(int *packedInfo);

void HAND_TOKUSEI_StallMoveLast(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_GetStallHandlers(unsigned int *packedInfo);

void HAND_TOKUSEI_SlowStartHalveSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, SlowStartWork *work);

void HAND_TOKUSEI_SlowStartHalveAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, SlowStartWork *work);

void HAND_TOKUSEI_SlowStartOnEnter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, SlowStartWork *work);

void HAND_TOKUSEI_SlowStartBeginOnce(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, SlowStartWork *work);

void HAND_TOKUSEI_SlowStartBegin(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, SlowStartWork *work);

void HAND_TOKUSEI_SlowStartCountTurn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, SlowStartWork *work);

int *HAND_TOKUSEI_GetSlowStartHandlers(int *packedInfo);

void HAND_TOKUSEI_CompoundEyesBoostAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_GetCompoundEyesHandlers(int *packedInfo);

void HAND_TOKUSEI_SandVeilLowerAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_SandVeilBlockSandDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);

int *HAND_TOKUSEI_GetSandVeilHandlers(int *packedInfo);

void HAND_TOKUSEI_SnowCloakLowerAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_SnowCloakBlockHailDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);

int *HAND_TOKUSEI_GetSnowCloakHandlers(int *packedInfo);

void HAND_TOKUSEI_BlockWeatherDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work, unsigned char weather);

void HAND_TOKUSEI_TintedLensDoubleResisted(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_GetTintedLensHandlers(int *packedInfo);

void HAND_TOKUSEI_FilterHalveSuperEffective(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_GetFilterHandlers(int *packedInfo);

void HAND_TOKUSEI_SniperBoostCritical(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_GetSniperHandlers(int *packedInfo);

void HAND_TOKUSEI_SpeedBoostOnTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

int *HAND_TOKUSEI_GetSpeedBoostHandlers(int *packedInfo);

void HAND_TOKUSEI_AdaptabilityBoostSameType(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

int *HAND_TOKUSEI_GetAdaptabilityHandlers(int *packedInfo);

void HAND_TOKUSEI_BlazeBoostFire(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

int *HAND_TOKUSEI_GetBlazeHandlers(int *packedInfo);

void HAND_TOKUSEI_TorrentBoostWater(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

int *HAND_TOKUSEI_GetTorrentHandlers(int *packedInfo);

void HAND_TOKUSEI_OvergrowBoostGrass(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

int *HAND_TOKUSEI_GetOvergrowHandlers(int *packedInfo);

void HAND_TOKUSEI_SwarmBoostBug(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

int *HAND_TOKUSEI_GetSwarmHandlers(int *packedInfo);

void HAND_TOKUSEI_PinchBoostType(struct BtlServerFlow *flow, int pokeId, int moveType);

void HAND_TOKUSEI_GutsBoostAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

int *HAND_TOKUSEI_GetGutsHandlers(int *packedInfo);

void HAND_TOKUSEI_PlusMinusBoostSpecialPower(struct BtlEventFactor *factor, void *server, int pokeId, u8 *work);

int *HAND_TOKUSEI_GetPlusMinusHandlers(int *handlerCount);

int HAND_TOKUSEI_CheckAllyHasAbility(void *server, int pokeId, u8 *idBuf, int abilityId);

int HAND_TOKUSEI_IsCherrim(void *server, int pokeId);

void HAND_TOKUSEI_FlowerGiftUpdateForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work);

void HAND_TOKUSEI_FlowerGiftUpdateFormIfOwner(struct BtlEventFactor *factor, void *server, int pokeId, int *work);

void HAND_TOKUSEI_ChangeCherrimForm(struct BtlEventFactor *factor, void *server, u32 pokeId, u32 form, u8 announce);

void HAND_TOKUSEI_FlowerGiftReapplyForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work);

void HAND_TOKUSEI_FlowerGiftRevertFormIfOwner(struct BtlEventFactor *factor, void *server, int pokeId, int *work);

void HAND_TOKUSEI_FlowerGiftRevertForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work);

void HAND_TOKUSEI_FlowerGiftRevertFormOnFactorChange(struct BtlEventFactor *factor, void *server, int pokeId, int *work);

void HAND_TOKUSEI_FlowerGiftBoostAllyAttack(struct BtlEventFactor *factor, void *server, int pokeId);

void HAND_TOKUSEI_FlowerGiftBoostAllySpecialDefense(struct BtlEventFactor *factor, void *server, int pokeId);

int *HAND_TOKUSEI_GetFlowerGiftHandlers(int *handlerCount);

void HAND_TOKUSEI_RivalryScalePower(struct BtlEventFactor *factor, void *server, int pokeId);

int *HAND_TOKUSEI_GetRivalryHandlers(int *handlerCount);

void HAND_TOKUSEI_TechnicianBoostWeakMove(struct BtlEventFactor *factor, void *server, int pokeId);

void *HAND_TOKUSEI_GetTechnicianHandlers(int *handlerCount);

void HAND_TOKUSEI_IronFistBoostPunchPower(struct BtlEventFactor *factor, void *server, int pokeId);

void *HAND_TOKUSEI_GetIronFistHandlers(int *handlerCount);

void HAND_TOKUSEI_RecklessBoostRecoilPower(struct BtlEventFactor *factor, void *server, int pokeId);

int *HAND_TOKUSEI_GetRecklessHandlers(int *handlerCount);

void HAND_TOKUSEI_MarvelScaleBoostDefense(struct BtlEventFactor *factor, void *server, int pokeId);

int *HAND_TOKUSEI_GetMarvelScaleHandlers(int *handlerCount);

void HAND_TOKUSEI_MoldBreakerSetIgnoreAbilities(struct BtlEventFactor *factor, void *server, int pokeId);

int *HAND_TOKUSEI_GetMoldBreakerFlagHandlers(int *handlerCount);

int *HAND_TOKUSEI_GetIndirectGuardCause1Handlers(int *handlerCount);

void HAND_TOKUSEI_IndirectGuardCause1Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work);

void HAND_TOKUSEI_IndirectGuardCause1ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work);

int *HAND_TOKUSEI_GetIndirectGuardCause6Handlers(int *handlerCount);

void HAND_TOKUSEI_IndirectGuardCause6Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work);

void HAND_TOKUSEI_IndirectGuardCause6ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work);

int *HAND_TOKUSEI_GetIndirectGuardCause8Handlers(int *handlerCount);

void HAND_TOKUSEI_IndirectGuardCause8Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work);

void HAND_TOKUSEI_IndirectGuardCause8ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work);

void HAND_TOKUSEI_BlockIndirectDamage(struct BtlServerFlow *server, int pokeId, int *work, int blockedCause);

void HAND_TOKUSEI_ShowIndirectGuardMessage(struct BtlServerFlow *server, int pokeId, int *work, int stringId);

void HAND_TOKUSEI_HalveResidualDamage(struct BtlEventFactor *factor, void *server, int pokeId);

void *HAND_TOKUSEI_GetHalveResidualDamageHandlers(int *handlerCount);

void HAND_TOKUSEI_LeafGuardBlockStatus(struct BtlEventFactor *factor, void *server, int pokeId, int *work);

void HAND_TOKUSEI_LeafGuardBlockOwnerEvent(struct BtlEventFactor *factor, void *server, int pokeId);

void *HAND_TOKUSEI_GetLeafGuardHandlers(int *handlerCount);

void HAND_TOKUSEI_ParalysisGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work);

void HAND_TOKUSEI_ParalysisGuard_CureOnEntry(void *factor, void *flow, int pokeId);

void HAND_TOKUSEI_ParalysisGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId);

int *HAND_TOKUSEI_GetParalysisGuardHandlers(int *count);

void HAND_TOKUSEI_SleepGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work);

void HAND_TOKUSEI_SleepGuard_CureOnEntry(void *factor, void *flow, int pokeId);

void HAND_TOKUSEI_SleepGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId);

void HAND_TOKUSEI_SleepGuard_BlockOwnerEvent0E(void *factor, void *flow, int pokeId);

int *HAND_TOKUSEI_GetSleepGuardHandlers(int *count);

void HAND_TOKUSEI_FreezeGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work);

void HAND_TOKUSEI_FreezeGuard_CureOnEntry(void *factor, void *flow, int pokeId);

void HAND_TOKUSEI_FreezeGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId);

int *HAND_TOKUSEI_GetFreezeGuardHandlers(int *count);

void HAND_TOKUSEI_PoisonGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work);

void HAND_TOKUSEI_PoisonGuard_CureOnEntry(void *factor, void *flow, int pokeId);

void HAND_TOKUSEI_PoisonGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId);

int *HAND_TOKUSEI_GetPoisonGuardHandlers(int *count);

void HAND_TOKUSEI_BurnGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work);

void HAND_TOKUSEI_BurnGuard_CureOnEntry(void *factor, void *flow, int pokeId);

void HAND_TOKUSEI_BurnGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId);

int *HAND_TOKUSEI_GetBurnGuardHandlers(int *count);

void HAND_TOKUSEI_ConfusionGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work);

void HAND_TOKUSEI_ConfusionGuard_ShowBlockedMessage(void *factor, void *flow, int pokeId, int *work);

void HAND_TOKUSEI_ConfusionGuard_CureOnEntry(void *factor, void *flow, int pokeId);

void HAND_TOKUSEI_ConfusionGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId);

int *HAND_TOKUSEI_GetConfusionGuardHandlers(int *count);

void HAND_TOKUSEI_InfatuationGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work);

void HAND_TOKUSEI_InfatuationGuard_CureOnEntry(void *factor, void *flow, int pokeId);

void HAND_TOKUSEI_InfatuationGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId);

void HAND_TOKUSEI_InfatuationGuard_ShowBlockedMoveMessage(void *factor, void *flow, int pokeId);

int *HAND_TOKUSEI_GetInfatuationGuardHandlers(int *count);

int HAND_TOKUSEI_BlockSickIfTargeted(void *flow, int pokeId, int sickIndex);

void HAND_TOKUSEI_ShowSickGuardMessage(void *factor, void *flow, int pokeId, int *work, u16 strId);

void HAND_TOKUSEI_SickGuard_ShowBlockedMessage(void *factor, void *flow, int pokeId, int *work);

void HAND_TOKUSEI_CureSickIfOwner(void *flow, int pokeId, int sickIndex);

void HAND_TOKUSEI_CureSick(void *flow, int pokeId, int sickIndex);

void HAND_TOKUSEI_Drizzle_StartRain(void *factor, void *flow, int pokeId);

int *HAND_TOKUSEI_GetDrizzleHandlers(int *count);

void HAND_TOKUSEI_Drought_StartSun(void *factor, void *flow, int pokeId);

int *HAND_TOKUSEI_GetDroughtHandlers(int *count);

void HAND_TOKUSEI_SandStream_StartSandstorm(void *factor, void *flow, int pokeId);

int *HAND_TOKUSEI_GetSandStreamHandlers(int *count);

void HAND_TOKUSEI_SnowWarning_StartHail(void *factor, void *flow, int pokeId);

int *HAND_TOKUSEI_GetSnowWarningHandlers(int *count);

void HAND_TOKUSEI_StartWeather(void *flow, int pokeId, int weather);

void HAND_TOKUSEI_WeatherLock_ClearWeather(void *factor, void *flow, int pokeId);

void HAND_TOKUSEI_WeatherLock_SetFailFlag(void);

int *HAND_TOKUSEI_GetWeatherLockHandlers(int *count);

void HAND_TOKUSEI_IceBody_HealInHail(void *factor, void *flow, int pokeId);

int *HAND_TOKUSEI_GetIceBodyHandlers(int *count);

void HAND_TOKUSEI_RainDish_HealInRain(void *factor, void *flow, int pokeId);

int *HAND_TOKUSEI_GetRainDishHandlers(int *count);

void HAND_TOKUSEI_HealInWeather(void *flow, int pokeId, int weather);

void HAND_TOKUSEI_SolarPower_DamageInSun(void *factor, void *flow, int pokeId);

void HAND_TOKUSEI_SolarPower_BoostSpecialAttackInSun(void *factor, void *flow, int pokeId);

int *HAND_TOKUSEI_GetSolarPowerHandlers(int *count);

void HAND_TOKUSEI_StatLossGuard_BlockForeignDrop(void *factor, void *flow, int pokeId);

void HAND_TOKUSEI_StatLossGuard_BlockForeignChange(void *factor, void *flow, int pokeId);

void HAND_TOKUSEI_StatLossGuard_BlockTargetedA(void *factor, void *flow, int pokeId);

void HAND_TOKUSEI_StatLossGuard_BlockTargetedB(void *factor, void *flow, int pokeId);

void HAND_TOKUSEI_StatLossGuard_BlockIfFlagged(void *factor, void *flow, int pokeId);

void *HAND_TOKUSEI_GetStatLossGuardHandlers(int *count);

void HAND_TOKUSEI_Simple_DoubleStatChange(void *factor, void *flow, int pokeId);

void HAND_TOKUSEI_Simple_SetOwnerFlag(void *factor, void *flow, int pokeId);

int *HAND_TOKUSEI_GetSimpleHandlers(int *count);

void HAND_TOKUSEI_Hydration_CureStatusInRain(void *factor, void *flow, int pokeId);

int *HAND_TOKUSEI_GetHydrationHandlers(int *count);

void HAND_TOKUSEI_ShedSkinOnTurnEnd(int myHandle, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_AddShedSkin(int *handlerCount);

void HAND_TOKUSEI_PoisonHealOnSickDamage(int myHandle, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_AddPoisonHeal(int *handlerCount);

void HAND_TOKUSEI_ShellArmorOnCriticalCheck(int myHandle, int flow, int pokeId);

void *HAND_TOKUSEI_AddShellArmor(int *handlerCount);

void HAND_TOKUSEI_SuperLuckOnCriticalCheck(int myHandle, int flow, int pokeId);

void *HAND_TOKUSEI_AddSuperLuck(int *handlerCount);

void HAND_TOKUSEI_AngerPointOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_AddAngerPoint(int *handlerCount);

void HAND_TOKUSEI_PoisonPointOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_AddPoisonPoint(int *handlerCount);

void HAND_TOKUSEI_StaticOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_AddStatic(int *handlerCount);

void HAND_TOKUSEI_FlameBodyOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_AddFlameBody(int *handlerCount);

void HAND_TOKUSEI_CuteCharmOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_AddCuteCharm(int *handlerCount);

void HAND_TOKUSEI_EffectSporeOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_AddEffectSpore(int *handlerCount);

void HAND_TOKUSEI_TryAddContactSick(struct BtlServerFlow *flow, int pokeId, int sickKind, union SickCont sickCont, u8 percent);

void HAND_TOKUSEI_RoughSkinOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_AddRoughSkin(int *handlerCount);

void HAND_TOKUSEI_AftermathOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_AddAftermath(int *handlerCount);

void HAND_TOKUSEI_ForecastOnWeatherChange(int myHandle, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_AddForecast(int *handlerCount);

void HAND_TOKUSEI_SynchronizeOnSickAdded(int myHandle, struct BtlServerFlow *flow, int pokeId);

void *HAND_TOKUSEI_AddSynchronize(int *handlerCount);

void HAND_TOKUSEI_MoldBreakerOnAbilityCheck(int myHandle, int flow, int pokeId);

void *HAND_TOKUSEI_AddMoldBreaker(int *handlerCount);

void HAND_TOKUSEI_CloudNineOnWeatherCheck(int myHandle, int flow, int pokeId);

void *HAND_TOKUSEI_AddCloudNine(int *handlerCount);

void *HAND_TOKUSEI_AddTrace(int *handlerCount);

void HAND_TOKUSEI_TraceOnMemberIn(int myHandle, struct BtlServerFlow *flow, int pokeId, int *work);

void HAND_TOKUSEI_NaturalCureOnMemberOut(int myHandle, void *flowWork, int pokeId);

void *HAND_TOKUSEI_AddNaturalCure(int *handlerCount);

void HAND_TOKUSEI_DownloadOnMemberIn(int myHandle, int flowWork, u8 pokeId);

int *HAND_TOKUSEI_AddDownload(int *handlerCount);

void HAND_TOKUSEI_ForewarnOnMemberIn(int myHandle, struct BtlServerFlow *flow, int pokeId);

int *HAND_TOKUSEI_AddForewarn(int *handlerCount);

void HAND_TOKUSEI_AnticipationOnMemberIn(int myHandle, struct BtlServerFlow *flow, int pokeId);

int HAND_TOKUSEI_AnticipationFoeIsThreat(struct BtlPokeParam *myPoke, struct BtlPokeParam *foe);

int *HAND_TOKUSEI_AddAnticipation(int *handlerCount);

void HAND_TOKUSEI_FriskShowOpponentItem(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

BtlEventHandler *HAND_TOKUSEI_GetFriskHandlers(int *handlerCount);

BtlEventHandler *HAND_TOKUSEI_GetSturdyHandlers(int *handlerCount);

void HAND_TOKUSEI_SturdyBlockOneHitKo(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_SturdyEndureFromFullHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);

void HAND_TOKUSEI_SturdyShowEndureMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);

void HAND_TOKUSEI_UnawareNeutralizeStatStages(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_UnawareIgnoreAccuracyStage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_UnawareIgnoreEvasionStage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

BtlEventHandler *HAND_TOKUSEI_GetUnawareHandlers(int *handlerCount);

void HAND_TOKUSEI_HeatproofHalveFirePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_HeatproofHalveBurnDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

BtlEventHandler *HAND_TOKUSEI_GetHeatproofHandlers(int *handlerCount);

int HAND_TOKUSEI_AbsorbCheckMoveType(struct BtlServerFlow *flow, int pokeId, int moveType);

void HAND_TOKUSEI_AbsorbRecoverHp(struct BtlServerFlow *flow, int pokeId, int divisor);

void HAND_TOKUSEI_AbsorbRaiseStat(struct BtlServerFlow *flow, int pokeId, u32 statId, int amount);

void HAND_TOKUSEI_DrySkinWeatherEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_DrySkinBoostFireDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_DrySkinAbsorbWater(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

BtlEventHandler *HAND_TOKUSEI_GetDrySkinHandlers(int *handlerCount);

void HAND_TOKUSEI_WaterAbsorbAbsorbWater(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

BtlEventHandler *HAND_TOKUSEI_GetWaterAbsorbHandlers(int *handlerCount);

void HAND_TOKUSEI_VoltAbsorbAbsorbElectric(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

BtlEventHandler *HAND_TOKUSEI_GetVoltAbsorbHandlers(int *handlerCount);

BtlEventHandler *HAND_TOKUSEI_GetMotorDriveHandlers(int *handlerCount);

void HAND_TOKUSEI_MotorDriveAbsorbElectric(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_ScrappyIgnoreGhostImmunity(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

BtlEventHandler *HAND_TOKUSEI_GetScrappyHandlers(int *handlerCount);

void HAND_TOKUSEI_SoundproofBlockSoundMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

BtlEventHandler *HAND_TOKUSEI_GetSoundproofHandlers(int *handlerCount);

void HAND_TOKUSEI_LevitateSetFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);

void HAND_TOKUSEI_LevitateShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);

void HAND_TOKUSEI_LevitateClearFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);

BtlEventHandler *HAND_TOKUSEI_GetLevitateHandlers(int *handlerCount);

void HAND_TOKUSEI_WonderGuardBlockMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

BtlEventHandler *HAND_TOKUSEI_GetWonderGuardHandlers(int *handlerCount);

void HAND_TOKUSEI_TruantToggleLoafing(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);

void HAND_TOKUSEI_TruantStartLoafing(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);

void HAND_TOKUSEI_TruantShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);

void HAND_TOKUSEI_TruantClearLoafing(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);

BtlEventHandler *HAND_TOKUSEI_GetTruantHandlers(int *handlerCount);

void HAND_TOKUSEI_DampBlockExplosion(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);

void HAND_TOKUSEI_DampShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);

void HAND_TOKUSEI_DampAddSkipCheck(struct BtlEventFactor *factor);

void HAND_TOKUSEI_DampRemoveSkipCheck(struct BtlEventFactor *factor);

void HAND_TOKUSEI_DampRemoveSkipCheckForOwner(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

int HAND_TOKUSEI_DampSkipAftermath(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId);

BtlEventHandler *HAND_TOKUSEI_GetDampHandlers(int *handlerCount);

void HAND_TOKUSEI_FlashFireBoostFireDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_FlashFireClearFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_FlashFireAbsorbFire(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

BtlEventHandler *HAND_TOKUSEI_GetFlashFireHandlers(int *handlerCount);

void HAND_TOKUSEI_BadDreamsHurtSleepers(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

BtlEventHandler *HAND_TOKUSEI_GetBadDreamsHandlers(int *handlerCount);

void HAND_TOKUSEI_RunAwayCheckEscape(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int unusedArg);

void HAND_TOKUSEI_RunAway_ShowEscapeMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandler *HAND_TOKUSEI_GetRunAwayHandlers(int *handlerCount);

void HAND_TOKUSEI_MoldBreaker_ShowAbilityMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

int HAND_TOKUSEI_MoldBreaker_SkipCheck(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId);

void HAND_TOKUSEI_MoldBreaker_InstallSkipCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *skipCheckSet);

void HAND_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent4(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *skipCheckSet);

void HAND_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent6A(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *skipCheckSet);

const BtlEventHandler *HAND_TOKUSEI_GetMoldBreakerSkipCheckHandlers(int *handlerCount);

void HAND_TOKUSEI_Forecast_ApplyWeatherForm(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *formActive);

void HAND_TOKUSEI_Forecast_ApplyWeatherFormOnEntry(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *formActive);

void HAND_TOKUSEI_Forecast_RefreshWeatherForm(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *formActive);

void HAND_TOKUSEI_Forecast_ResetFormWhenActive(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *formActive);

void HAND_TOKUSEI_Forecast_ResetFormOnAbilityChange(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_Forecast_ResetFormOnEvent6A(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_Forecast_ResetForm(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_Forecast_SetFormForWeather(struct BtlServerFlow *flow, int pokeId, u32 weather);

const BtlEventHandler *HAND_TOKUSEI_GetForecastHandlers(int *handlerCount);

const BtlEventHandler *HAND_TOKUSEI_GetStormDrainHandlers(int *handlerCount);

void HAND_TOKUSEI_StormDrain_CheckRedirect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *redirected);

void HAND_TOKUSEI_StormDrain_AbsorbWaterMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandler *HAND_TOKUSEI_GetLightningRodHandlers(int *handlerCount);

void HAND_TOKUSEI_LightningRod_CheckRedirect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *redirected);

void HAND_TOKUSEI_Redirect_ShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *redirected);

void HAND_TOKUSEI_LightningRod_AbsorbElectricMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

int HAND_TOKUSEI_CheckRedirectMoveType(struct BtlServerFlow *flow, int pokeId, int *work, int typeId);

void HAND_TOKUSEI_SuctionCups_BlockForcedSwitch(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandler *HAND_TOKUSEI_GetSuctionCupsHandlers(int *handlerCount);

void HAND_TOKUSEI_LiquidOoze_DamageAttacker(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_LiquidOoze_RemoveFactorOnEventA3(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandler *HAND_TOKUSEI_GetLiquidOozeHandlers(int *handlerCount);

int HAND_TOKUSEI_Klutz_SkipCheck(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId);

void HAND_TOKUSEI_Klutz_InstallSkipCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, KlutzWork *work);

void HAND_TOKUSEI_Klutz_InstallSkipCheckOnEntry(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, KlutzWork *work);

void HAND_TOKUSEI_Klutz_RemoveSkipCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_Klutz_NoticeHeldItem(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_Klutz_BlockNaturalGift(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, KlutzWork *work);

void HAND_TOKUSEI_Klutz_ShowBlockedMoveMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, KlutzWork *work);

const BtlEventHandler *HAND_TOKUSEI_GetKlutzHandlers(int *handlerCount);

void HAND_TOKUSEI_StickyHold_BlockTrick(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_StickyHold_BlockItemRemoval(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *messagePending);

void HAND_TOKUSEI_StickyHold_ShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *messagePending);

const BtlEventHandler *HAND_TOKUSEI_GetStickyHoldHandlers(int *handlerCount);

const BtlEventHandler *HAND_TOKUSEI_GetPressureHandlers(int *handlerCount);

void HAND_TOKUSEI_Pressure_ShowAbilityMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_Pressure_AddPPCost(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandler *HAND_TOKUSEI_GetMagicGuardHandlers(int *handlerCount);

void HAND_TOKUSEI_MagicGuard_ClearEffectFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandler *HAND_TOKUSEI_GetStenchHandlers(int *handlerCount);

void HAND_TOKUSEI_Stench_SetFlinchChance(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandler *HAND_TOKUSEI_GetShadowTagHandlers(int *handlerCount);

void HAND_TOKUSEI_ShadowTag_PreventEscape(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandler *HAND_TOKUSEI_GetArenaTrapHandlers(int *handlerCount);

void HAND_TOKUSEI_ArenaTrap_PreventEscape(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandler *HAND_TOKUSEI_GetMagnetPullHandlers(int *handlerCount);

void HAND_TOKUSEI_MagnetPull_BlockSteelEscape(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

int *HAND_TOKUSEI_GetUnburdenHandlers(int *handlerCount);

void HAND_TOKUSEI_Unburden_MarkItemLost(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work);

void HAND_TOKUSEI_Unburden_DoubleSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work);

int *HAND_TOKUSEI_GetPickupHandlers(int *handlerCount);

void HAND_TOKUSEI_Pickup_TakeUsedItem(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId);

void *HAND_TOKUSEI_GetPickpocketHandlers(int *handlerCount);

void HAND_TOKUSEI_Pickpocket_StealOnContact(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

void HAND_TOKUSEI_CursedBody_DisableAttackerMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

int *HAND_TOKUSEI_GetCursedBodyHandlers(int *handlerCount);

void HAND_TOKUSEI_WeakArmor_LowerDefenseRaiseSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u32 ownerId);

int *HAND_TOKUSEI_GetWeakArmorHandlers(int *handlerCount);

void HAND_TOKUSEI_SheerForce_BoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

void HAND_TOKUSEI_SheerForce_BlockAddedEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

void HAND_TOKUSEI_SheerForce_BlockAttackerSideEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

void HAND_TOKUSEI_SheerForce_FlagNoAddedEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

int *HAND_TOKUSEI_GetSheerForceHandlers(int *handlerCount);

int HAND_TOKUSEI_SheerForce_IsBoostedMove(u16 moveId);

void HAND_TOKUSEI_Defiant_RaiseAttackOnStatDrop(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u32 ownerId);

int *HAND_TOKUSEI_GetDefiantHandlers(int *handlerCount);

void HAND_TOKUSEI_Defeatist_HalvePowerAtLowHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

int *HAND_TOKUSEI_GetDefeatistHandlers(int *handlerCount);

void HAND_TOKUSEI_Multiscale_HalveDamageAtFullHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

int *HAND_TOKUSEI_GetMultiscaleHandlers(int *handlerCount);

void HAND_TOKUSEI_FriendGuard_ReduceAllyDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, unsigned int ownerId);

int *HAND_TOKUSEI_GetFriendGuardHandlers(int *handlerCount);

void HAND_TOKUSEI_Healer_CureAllyStatus(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

int *HAND_TOKUSEI_GetHealerHandlers(int *handlerCount);

void HAND_TOKUSEI_ToxicBoost_BoostPhysicalPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

int *HAND_TOKUSEI_GetToxicBoostHandlers(int *handlerCount);

void HAND_TOKUSEI_FlareBoost_BoostSpecialPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

int *HAND_TOKUSEI_GetFlareBoostHandlers(int *handlerCount);

void HAND_TOKUSEI_Telepathy_AvoidAllyAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u32 ownerId);

int *HAND_TOKUSEI_GetTelepathyHandlers(int *handlerCount);

void HAND_TOKUSEI_Moody_RaiseAndLowerStat(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId);

void *HAND_TOKUSEI_GetMoodyHandlers(int *handlerCount);

void HAND_TOKUSEI_Overcoat_BlockWeatherDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

void *HAND_TOKUSEI_GetOvercoatHandlers(int *handlerCount);

void HAND_TOKUSEI_PoisonTouch_PoisonOnContact(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

void *HAND_TOKUSEI_GetPoisonTouchHandlers(unsigned int *packedInfo);

void HAND_TOKUSEI_Regenerator_RecoverOnSwitchOut(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

int *HAND_TOKUSEI_GetRegeneratorHandlers(int *handlerCount);

int *HAND_TOKUSEI_GetIndirectGuardCause2Handlers(int *handlerCount);

void HAND_TOKUSEI_IndirectGuardCause2_Block(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work);

void HAND_TOKUSEI_IndirectGuardCause2_ShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work);

int *HAND_TOKUSEI_GetSandRushHandlers(int *handlerCount);

void HAND_TOKUSEI_SandRush_DoubleSpeedInSand(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

void *HAND_TOKUSEI_GetWonderSkinHandlers(int *handlerCount);

void HAND_TOKUSEI_WonderSkin_CapStatusMoveAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

void *HAND_TOKUSEI_GetAnalyticHandlers(int *handlerCount);

void HAND_TOKUSEI_Analytic_BoostPowerWhenMovingLast(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);

BtlEventHandler *HAND_TOKUSEI_GetSandForceHandlers(u32 *handlerCount);

void HAND_TOKUSEI_SandForceBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work);

void HAND_TOKUSEI_ZenModeUpdateForm(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work);

void HAND_TOKUSEI_ZenModeRevertForm(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work);

BtlEventHandler *HAND_TOKUSEI_GetZenModeHandlers(u32 *handlerCount);

int HAND_TOKUSEI_InfiltratorSkipSideCondition(struct BtlEventFactor *factor, void *context, int targetFactorType, int eventId, u16 targetKey, u8 targetOwnerId);

void HAND_TOKUSEI_InfiltratorEnableSkip(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work);

void HAND_TOKUSEI_InfiltratorDisableSkip(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work);

BtlEventHandler *HAND_TOKUSEI_GetInfiltratorHandlers(u32 *handlerCount);

BtlEventHandler *HAND_TOKUSEI_GetMoxieHandlers(u32 *handlerCount);

void HAND_TOKUSEI_MoxieRaiseAttackOnKnockOut(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work);

BtlEventHandler *HAND_TOKUSEI_GetJustifiedHandlers(u32 *handlerCount);

void HAND_TOKUSEI_JustifiedRaiseAttackOnDarkHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work);

BtlEventHandler *HAND_TOKUSEI_GetRattledHandlers(u32 *handlerCount);

void HAND_TOKUSEI_RattledRaiseSpeedOnHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work);

BtlEventHandler *HAND_TOKUSEI_GetMummyHandlers(u32 *handlerCount);

void HAND_TOKUSEI_MummySpreadAbility(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work);

void HAND_TOKUSEI_SapSipperAbsorbGrass(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work);

BtlEventHandler *HAND_TOKUSEI_GetSapSipperHandlers(u32 *handlerCount);

void HAND_TOKUSEI_PranksterRaiseStatusPriority(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work);

BtlEventHandler *HAND_TOKUSEI_GetPranksterHandlers(u32 *handlerCount);

void HAND_TOKUSEI_MagicBounceReflectMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work);

void HAND_TOKUSEI_MagicBounceCounterMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work);

void HAND_TOKUSEI_MagicBounceReflectMoveWithWindow(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int work);

const BtlEventHandlerEntry *HAND_TOKUSEI_AddMagicBounce(int *count);

void HAND_TOKUSEI_HarvestRestoreBerry(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandlerEntry *HAND_TOKUSEI_AddHarvest(int *count);

const BtlEventHandlerEntry *HAND_TOKUSEI_AddHeavyMetal(int *count);

void HAND_TOKUSEI_HeavyMetalDoubleWeight(int factor, int flow, int pokeId);

const BtlEventHandlerEntry *HAND_TOKUSEI_AddLightMetal(int *count);

void HAND_TOKUSEI_LightMetalHalveWeight(int factor, int flow, int pokeId);

void HAND_TOKUSEI_ContraryInvertStatChange(int factor, int flow, int pokeId, int *work);

const BtlEventHandlerEntry *HAND_TOKUSEI_AddContrary(int *count);

void HAND_TOKUSEI_UnnerveOnOwnerEnter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, UnnerveWork *work);

void HAND_TOKUSEI_UnnerveAnnounce(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, UnnerveWork *work);

int HAND_TOKUSEI_UnnerveSkipBerry(struct BtlEventFactor *factor, void *context, int targetFactorType, int eventId, u16 targetKey, u8 targetOwnerId);

const BtlEventHandlerEntry *HAND_TOKUSEI_AddUnnerve(int *count);

void HAND_TOKUSEI_ImposterTransform(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandlerEntry *HAND_TOKUSEI_AddImposter(int *count);

const BtlEventHandlerEntry *HAND_TOKUSEI_AddIllusion(int *count);

void HAND_TOKUSEI_IllusionBreakOnHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_IllusionBreakOnOwnerEvent(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_IllusionBreakOnAbilityChange(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_TOKUSEI_IllusionBreak(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandlerEntry *HAND_TOKUSEI_AddVictoryStar(int *count);

void HAND_TOKUSEI_VictoryStarBoostAccuracy(int factor, int flow, unsigned int pokeId);

struct BtlEventFactor *HAND_ITEM_AddFactor(struct BtlPokeParam *poke, u32 itemId);

void HAND_ITEM_RemoveUnforcedFactors(struct BtlPokeParam *poke);

struct BtlEventFactor *HAND_ITEM_AddHeldItemFactor(struct BtlPokeParam *poke);

struct BtlEventFactor *HAND_ITEM_AddForcedFactor(struct BtlPokeParam *poke, unsigned int itemId);

void HAND_ITEM_RemoveFactor(struct BtlEventFactor *factor);

void HAND_ITEM_DisablePokeFactors(struct BtlPokeParam *poke);

void HAND_ITEM_EnablePokeFactors(struct BtlPokeParam *poke);

int HAND_ITEM_RollChance(struct BtlServerFlow *flow, unsigned int percent);

int HAND_ITEM_GetParam(struct BtlEventFactor *factor, int paramIndex);

int HAND_ITEM_GetBoostRatio(struct BtlEventFactor *factor);

void HAND_ITEM_PushUseItem(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_ITEM_CheriBerryOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_ITEM_CheriBerryOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandlerEntry *HAND_ITEM_AddCheriBerry(int *count);

void HAND_ITEM_ChestoBerryOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_ITEM_ChestoBerryOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandlerEntry *HAND_ITEM_AddChestoBerry(int *count);

void HAND_ITEM_RawstBerryOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_ITEM_RawstBerryOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandlerEntry *HAND_ITEM_AddRawstBerry(int *count);

void HAND_ITEM_AspearBerryOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_ITEM_AspearBerryOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandlerEntry *HAND_ITEM_AddAspearBerry(int *count);

void HAND_ITEM_PersimBerryOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_ITEM_PersimBerryOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandlerEntry *HAND_ITEM_AddPersimBerry(int *count);

void HAND_ITEM_PechaBerryOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_ITEM_PechaBerryOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandlerEntry *HAND_ITEM_AddPechaBerry(int *count);

void HAND_ITEM_LumBerryOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_ITEM_LumBerryOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandlerEntry *HAND_ITEM_AddLumBerry(int *count);

void HAND_ITEM_CureSickOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int sickKind);

void HAND_ITEM_CureSickOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int sickKind);

int HAND_ITEM_CheckHasSick(struct BtlServerFlow *flow, int pokeId, int sickKind);

const BtlEventHandlerEntry *HAND_ITEM_AddLeppaBerry(int *count);

void HAND_ITEM_LeppaBerryOnLastMoveEmpty(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_ITEM_LeppaBerryOnAnyMoveEmptyChecked(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_ITEM_LeppaBerryOnAnyMoveEmpty(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_ITEM_LeppaBerryClaimTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_ITEM_LeppaBerryOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 pokeId, int *work);

void HAND_ITEM_LeppaBerryOnForcedUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 pokeId, int *work);

u8 HAND_ITEM_FindLastMoveEmptySlot(struct BtlServerFlow *flow, int pokeId);

u8 HAND_ITEM_FindEmptyMoveSlot(struct BtlServerFlow *flow, int pokeId);

int HAND_ITEM_PushRecoverPp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 pokeId, int *work, int allowAnyLostSlot);

const BtlEventHandlerEntry *HAND_ITEM_AddOranBerry(int *count);

void HAND_ITEM_RecoverHpOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_ITEM_RecoverHpOnCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_ITEM_RecoverHpOnLowHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

void HAND_ITEM_RecoverFixedHpOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

const BtlEventHandlerEntry *HAND_ITEM_AddBerryJuice(int *count);

const BtlEventHandlerEntry *HAND_ITEM_AddSitrusBerry(int *count);

extern int gSteadfastHandlers[];

extern int gThickFatHandlers[];

extern u8 gHugePowerHandlers[];

extern u8 gSwiftSwimHandlers[];

extern u8 gChlorophyllHandlers[];

extern u8 gTangledFeetHandlers[];

extern int gQuickFeetHandlers[];

extern unsigned char gStallHandlers[];

extern int gHustleHandlers[];

extern unsigned char gCompoundEyesHandlers[];

extern int gSlowStartHandlers[];

extern int gSandVeilHandlers[];

extern unsigned char gTintedLensHandlers[];

extern int gSnowCloakHandlers[];

extern unsigned char gFilterHandlers[];

extern unsigned int gSniperHandlers;

extern int gSpeedBoostHandlers[];

extern int gAdaptabilityHandlers[];

extern int gBlazeHandlers[];

extern int gTorrentHandlers[];

extern int gOvergrowHandlers[];

extern int gSwarmHandlers[];

extern int gGutsHandlers[];

extern int gPlusMinusHandlers[];

extern int gFlowerGiftHandlers[];

extern unsigned int gTechnicianHandlers;

extern int gRivalryHandlers[];

extern unsigned int gIronFistHandlers;

extern int gMarvelScaleHandlers[];

extern int gRecklessHandlers[];

extern int gMoldBreakerFlagHandlers[];

extern int gIndirectGuardCause1Handlers[];

extern int gIndirectGuardCause6Handlers[];

extern unsigned int gHalveResidualDamageHandlers;

extern unsigned int gLeafGuardHandlers;

extern int gIndirectGuardCause8Handlers[];

extern int gParalysisGuardHandlers[];

extern int gSleepGuardHandlers[];

extern int gFreezeGuardHandlers[];

extern int gPoisonGuardHandlers[];

extern int gConfusionGuardHandlers[];

extern int gBurnGuardHandlers[];

extern int gInfatuationGuardHandlers[];

extern int gDrizzleHandlers[];

extern int gDroughtHandlers[];

extern int gSandStreamHandlers[];

extern int gSnowWarningHandlers[];

extern int gSolarPowerHandlers[];

extern unsigned int gStatLossGuardHandlers;

extern int gWeatherLockHandlers[];

extern int gIceBodyHandlers[];

extern int gRainDishHandlers[];

extern int gHydrationHandlers[];

extern int gSimpleHandlers[];

extern int gShedSkinHandlers[];

extern int gPoisonHealHandlers[];

extern int gSuperLuckHandlers[];

extern int gShellArmorHandlers[];

extern int gPoisonPointHandlers[];

extern int gStaticHandlers[];

extern int gFlameBodyHandlers[];

extern int gCuteCharmHandlers[];

extern int gAngerPointHandlers[];

extern int gEffectSporeHandlers[];

extern int gRoughSkinHandlers[];

extern int gAftermathHandlers[];

extern int gForecastHandlerEntries[];

extern int gSynchronizeHandlers[];

extern int gMoldBreakerHandlerEntries[];

extern int gCloudNineHandlers[];

extern int gTraceHandlers[];

extern unsigned char gNaturalCureHandlers[];

extern int gDownloadHandlers[];

extern int gForewarnHandlers;

extern int gAnticipationHandlers[];

/* Handler tables: pairs of an event id and the function that answers it. */
extern BtlEventHandler gFriskHandlers[], gSturdyHandlers[];

extern BtlEventHandler gUnawareHandlers[];

extern BtlEventHandler gDrySkinHandlers[];

extern BtlEventHandler gWaterAbsorbHandlers[];

extern BtlEventHandler gMotorDriveHandlers[];

extern BtlEventHandler gScrappyHandlers[];

extern BtlEventHandler gHeatproofHandlers[];

extern BtlEventHandler gLevitateHandlers[];

extern BtlEventHandler gSoundproofHandlers[];

extern BtlEventHandler gTruantHandlers[];

extern BtlEventHandler gWonderGuardHandlers[];

extern BtlEventHandler gDampHandlers[];

extern BtlEventHandler gFlashFireHandlers[];

extern BtlEventHandler gBadDreamsHandlers[];

extern const BtlEventHandler gRunAwayHandlers[];

extern const BtlEventHandler gMoldBreakerSkipCheckHandlers[];

extern const BtlEventHandler gLightningRodHandlers[];

extern const BtlEventHandler gForecastHandlers[];

extern const BtlEventHandler gStormDrainHandlers[];

extern const BtlEventHandler gSuctionCupsHandlers[];

extern const BtlEventHandler gLiquidOozeHandlers[];

extern const u16 gKlutzExemptItemIds[];

extern const BtlEventHandler gKlutzHandlers[];

extern const BtlEventHandler gStickyHoldHandlers[];

extern const BtlEventHandler gPressureHandlers[];

extern const BtlEventHandler gMagicGuardHandlers[];

extern const BtlEventHandler gShadowTagHandlers[];

extern const BtlEventHandler gStenchHandlers[];

extern const BtlEventHandler gArenaTrapHandlers[];

extern const BtlEventHandler gMagnetPullHandlers[];

extern int gUnburdenHandlers[];

extern u8 gPickpocketHandlers[];

extern int gPickupHandlers[];

extern int gCursedBodyHandlers;

extern int gSheerForceHandlers;

extern int gWeakArmorHandlers[];

extern int gDefiantHandlers[];

extern int gMultiscaleHandlers;

extern int gDefeatistHandlers[];

extern int gFriendGuardHandlers;

extern int gHealerHandlers[];

extern int gToxicBoostHandlers[];

extern int gFlareBoostHandlers[];

extern int gTelepathyHandlers[];

extern u8 gMoodyHandlers[];

extern unsigned char gOvercoatHandlers[];

extern unsigned char gPoisonTouchHandlers[];

extern int gRegeneratorHandlers[];

extern int gIndirectGuardCause2Handlers[];

extern unsigned char gWonderSkinHandlers[];

extern unsigned char gAnalyticHandlers[];

extern int gSandRushHandlers[];

extern BtlEventHandler gSandForceHandlers[];

extern BtlEventHandler gZenModeHandlers[];

extern BtlEventHandler gInfiltratorHandlers[];

extern BtlEventHandler gMoxieHandlers[];

extern BtlEventHandler gJustifiedHandlers[];

extern BtlEventHandler gRattledHandlers[];

extern BtlEventHandler gSapSipperHandlers[];

extern BtlEventHandler gMummyHandlers[];

extern BtlEventHandler gPranksterHandlers[];

/* Handler tables defined in the overlay data, one per ability or item. */
extern const BtlEventHandlerEntry gMagicBounceHandlers[];

extern const BtlEventHandlerEntry gLightMetalHandlers[];

extern const BtlEventHandlerEntry gContraryHandlers[];

extern const BtlEventHandlerEntry gUnnerveHandlers[];

extern const BtlEventHandlerEntry gHarvestHandlers[];

extern const BtlEventHandlerEntry gHeavyMetalHandlers[];

extern const BtlEventHandlerEntry gImposterHandlers[];

extern const BtlEventHandlerEntry gIllusionHandlers[];

extern const BtlEventHandlerEntry gVictoryStarHandlers[];

extern const BtlEventHandlerEntry gCheriBerryHandlers[];

extern const BtlEventHandlerEntry gChestoBerryHandlers[];

extern const BtlEventHandlerEntry gRawstBerryHandlers[];

extern const BtlEventHandlerEntry gAspearBerryHandlers[];

extern const BtlEventHandlerEntry gPersimBerryHandlers[];

extern const BtlEventHandlerEntry gPechaBerryHandlers[];

extern const BtlEventHandlerEntry gLumBerryHandlers[];

extern const BtlEventHandlerEntry gLeppaBerryHandlers[];

extern const BtlEventHandlerEntry gOranBerryHandlers[];

extern const BtlEventHandlerEntry gBerryJuiceHandlers[];

extern const BtlEventHandlerEntry gSitrusBerryHandlers[];

extern ItemHandlerEntry gItemHandlerRegistry[ITEM_HANDLER_COUNT];

/* Inner Focus: prevents flinching. */
void HAND_TOKUSEI_InnerFocusPreventFlinch(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

/* Steadfast: handler table. */
int *HAND_TOKUSEI_GetSteadfastHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gSteadfastHandlers;
}

/* Steadfast: raises the speed of the poke that flinched by one rank. */
void HAND_TOKUSEI_SteadfastOnFlinch(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlRankCmd *cmd;

    if (BTL_EVENT_GetVar(BTL_EVAR_FAIL_REASON) == BTL_FAIL_REASON_FLINCH) {
        if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 0xe, pokeId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->statId = 5;
            cmd->amount = 1;
            cmd->showMessage = 0;
            cmd->targetCount = 1;
            cmd->targets[0] = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}

/* Thick Fat: handler table. */
int *HAND_TOKUSEI_GetThickFatHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gThickFatHandlers;
}

/* Thick Fat: halves the attack power of fire and ice moves against the owner. */
void HAND_TOKUSEI_ThickFatHalveFireIce(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 moveType;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        moveType = BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
        if (moveType == POKETYPE_ICE || moveType == POKETYPE_FIRE)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_5);
    }
}

/* Huge Power and Pure Power: handler table. */
u8 *HAND_TOKUSEI_GetHugePowerHandlers(u32 *packedInfo)
{
    *packedInfo = 1;
    return gHugePowerHandlers;
}

/* Huge Power and Pure Power: doubles the attack power of physical moves. */
void HAND_TOKUSEI_HugePowerDoubleAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_PHYSICAL)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
    }
}

/* Swift Swim: doubles the speed in rain. */
void HAND_TOKUSEI_SwiftSwimDoubleSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_RAIN)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
    }
}

/* Swift Swim: handler table. */
u8 *HAND_TOKUSEI_GetSwiftSwimHandlers(u32 *packedInfo)
{
    *packedInfo = 1;
    return gSwiftSwimHandlers;
}

/* Chlorophyll: doubles the speed in sun. */
void HAND_TOKUSEI_ChlorophyllDoubleSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_SUN)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
    }
}

/* Chlorophyll: handler table. */
u8 *HAND_TOKUSEI_GetChlorophyllHandlers(u32 *packedInfo)
{
    *packedInfo = 1;
    return gChlorophyllHandlers;
}

/* Quick Feet: a poke with a status condition gets 1.5 times speed and ignores the paralysis penalty. */
void HAND_TOKUSEI_QuickFeetBoostSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *bpp;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_GetMajorStatusIndex(bpp) != 0) {
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_1_5);
            BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 0);
        }
    }
}

/* Quick Feet: handler table. */
int *HAND_TOKUSEI_GetQuickFeetHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gQuickFeetHandlers;
}

/* Tangled Feet: halves the accuracy of moves against a confused owner. */
void HAND_TOKUSEI_TangledFeetHalveAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_SICK_CONFUSION))
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_5);
    }
}

/* Tangled Feet: handler table. */
u8 *HAND_TOKUSEI_GetTangledFeetHandlers(u32 *packedInfo)
{
    *packedInfo = 1;
    return gTangledFeetHandlers;
}

/* Hustle: physical moves of the owner lose accuracy. */
void HAND_TOKUSEI_HustleLowerAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && WAZA_TOOL_GetDamageType((unsigned short)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_PHYSICAL)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_8);
}

/* Hustle: physical moves of the owner get 1.5 times power. */
void HAND_TOKUSEI_HustleBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_PHYSICAL) {
            BTL_EVENT_OverwriteVar(BTL_EVAR_POWER, BTL_CALC_MulRatio(BTL_EVENT_GetVar(BTL_EVAR_POWER), BTL_RATIO_1_5));
        }
    }
}

/* Hustle: handler table. */
int *HAND_TOKUSEI_GetHustleHandlers(int *packedInfo)
{
    *packedInfo = 2;
    return gHustleHandlers;
}

/* Stall: the owner moves last in its priority bracket. */
void HAND_TOKUSEI_StallMoveLast(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_ACTION_ORDER, 0);
}

/* Stall: handler table, one handler at priority 7. */
void *HAND_TOKUSEI_GetStallHandlers(unsigned int *packedInfo)
{
    *packedInfo = HAND_TOKUSEI_PackAbilityHandlerInfo(7, 1);
    return gStallHandlers;
}

/* Slow Start: halves the speed while the effect is active. */
void HAND_TOKUSEI_SlowStartHalveSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, SlowStartWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && work->active != 0)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_5);
}

/* Slow Start: halves the attack power of physical moves while the effect is active. */
void HAND_TOKUSEI_SlowStartHalveAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, SlowStartWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && work->active != 0 && WAZA_TOOL_GetDamageType((unsigned short)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_PHYSICAL)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_5);
}

/* Slow Start: starts the effect when the owner enters. */
void HAND_TOKUSEI_SlowStartOnEnter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, SlowStartWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        HAND_TOKUSEI_SlowStartBegin(factor, flow, pokeId, work);
}

/* Slow Start: starts the effect once if it has not started. */
void HAND_TOKUSEI_SlowStartBeginOnce(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, SlowStartWork *work)
{
    if (work->started == 0)
        HAND_TOKUSEI_SlowStartBegin(factor, flow, pokeId, work);
}

/* Slow Start: resets the work area and shows the start message. */
void HAND_TOKUSEI_SlowStartBegin(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, SlowStartWork *work)
{
    BtlMessageCmd *msg;

    work->started = 1;
    work->turnCount = 0;
    work->finished = 0;
    work->active = 1;
    msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, 4, pokeId);
    msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
    BTL_SERVER_FLOW_InitMsgRecord(&msg->strParam, BTL_STR_TYPE_STD, BTL_STR_SLOW_START_BEGIN);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->strParam, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
}

/*
 * Slow Start: counts the turns on which the owner took an action other than
 * a switch; after 5 it shows the end message and ends the effect.
 */
void HAND_TOKUSEI_SlowStartCountTurn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, SlowStartWork *work)
{
    BtlActionWord action;
    BtlMessageCmd *msg;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    if (work->finished != 0)
        return;
    if (work->turnCount < SLOW_START_TURNS) {
        if (BTL_SERVER_FLOW_GetActionWordByPokeId(flow, pokeId, (u32 *)&action) == 0)
            return;
        if (action.kind == BTL_ACTION_CHANGE)
            return;
        work->turnCount += 1;
    }
    if (work->turnCount < SLOW_START_TURNS)
        return;
    msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, 4, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&msg->strParam, BTL_STR_TYPE_STD, BTL_STR_SLOW_START_END);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->strParam, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    work->active = 0;
    work->finished = 1;
}

/* Slow Start: handler table. */
int *HAND_TOKUSEI_GetSlowStartHandlers(int *packedInfo)
{
    *packedInfo = 6;
    return gSlowStartHandlers;
}

/* Compound Eyes: multiplies the accuracy of the owner's moves by 1.3. */
void HAND_TOKUSEI_CompoundEyesBoostAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_1_3);
}

/* Compound Eyes: handler table. */
void *HAND_TOKUSEI_GetCompoundEyesHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gCompoundEyesHandlers;
}

/* Sand Veil: lowers the accuracy of moves against the owner in a sandstorm. */
void HAND_TOKUSEI_SandVeilLowerAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_SAND)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_8);
}

/* Sand Veil: no damage from the sandstorm. */
void HAND_TOKUSEI_SandVeilBlockSandDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_TOKUSEI_BlockWeatherDamage(factor, flow, pokeId, work, BTL_WEATHER_SAND);
}

/* Sand Veil: handler table. */
int *HAND_TOKUSEI_GetSandVeilHandlers(int *packedInfo)
{
    *packedInfo = 2;
    return gSandVeilHandlers;
}

/* Snow Cloak: lowers the accuracy of moves against the owner in hail. */
void HAND_TOKUSEI_SnowCloakLowerAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_HAIL)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_8);
}

/* Snow Cloak: no damage from hail. */
void HAND_TOKUSEI_SnowCloakBlockHailDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_TOKUSEI_BlockWeatherDamage(factor, flow, pokeId, work, BTL_WEATHER_HAIL);
}

/* Snow Cloak: handler table. */
int *HAND_TOKUSEI_GetSnowCloakHandlers(int *packedInfo)
{
    *packedInfo = 2;
    return gSnowCloakHandlers;
}

/* Prevents the weather damage of the given weather for the owner. */
void HAND_TOKUSEI_BlockWeatherDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work, unsigned char weather)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(BTL_EVAR_DAMAGE) > 0 && weather == BTL_EVENT_GetVar(BTL_EVAR_WEATHER))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

/* Tinted Lens: doubles the damage of moves that are not very effective. */
void HAND_TOKUSEI_TintedLensDoubleResisted(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_CALC_SummarizeTypeAffinity(BTL_EVENT_GetVar(BTL_EVAR_TYPE_AFFINITY)) == BTL_AFFINITY_RESISTED)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
}

/* Tinted Lens: handler table. */
void *HAND_TOKUSEI_GetTintedLensHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gTintedLensHandlers;
}

/* Filter and Solid Rock: moves that are super effective against the owner do 0.75 times damage. */
void HAND_TOKUSEI_FilterHalveSuperEffective(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_CALC_SummarizeTypeAffinity(BTL_EVENT_GetVar(BTL_EVAR_TYPE_AFFINITY)) == BTL_AFFINITY_SUPER_EFFECTIVE)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_75);
}

/* Filter and Solid Rock: handler table. */
void *HAND_TOKUSEI_GetFilterHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gFilterHandlers;
}

/* Sniper: critical hits of the owner do 1.5 times damage again. */
void HAND_TOKUSEI_SniperBoostCritical(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_EVENT_GetVar(BTL_EVAR_CRITICAL_FLAG))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_1_5);
}

/* Sniper: handler table. */
void *HAND_TOKUSEI_GetSniperHandlers(int *packedInfo) { *packedInfo = 1; return &gSniperHandlers; }

/* Speed Boost: raises the speed of the owner by one rank at the end of the turn. */
void HAND_TOKUSEI_SpeedBoostOnTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlRankCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), 0) != 0) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 14, pokeId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->statId = 5;
            cmd->targetCount = 1;
            cmd->targets[0] = pokeId;
            cmd->amount = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}

/* Speed Boost: handler table. */
int *HAND_TOKUSEI_GetSpeedBoostHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gSpeedBoostHandlers;
}

/* Adaptability: moves of the owner that get the same type bonus do twice the damage. */
void HAND_TOKUSEI_AdaptabilityBoostSameType(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_SAME_TYPE_FLAG) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
    }
}

/* Adaptability: handler table. */
int *HAND_TOKUSEI_GetAdaptabilityHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gAdaptabilityHandlers;
}

/* Blaze. */
void HAND_TOKUSEI_BlazeBoostFire(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_TOKUSEI_PinchBoostType(flow, pokeId, POKETYPE_FIRE);
}

/* Blaze: handler table. */
int *HAND_TOKUSEI_GetBlazeHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gBlazeHandlers;
}

/* Torrent. */
void HAND_TOKUSEI_TorrentBoostWater(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_TOKUSEI_PinchBoostType(flow, pokeId, POKETYPE_WATER);
}

/* Torrent: handler table. */
int *HAND_TOKUSEI_GetTorrentHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gTorrentHandlers;
}

/* Overgrow. */
void HAND_TOKUSEI_OvergrowBoostGrass(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_TOKUSEI_PinchBoostType(flow, pokeId, POKETYPE_GRASS);
}

/* Overgrow: handler table. */
int *HAND_TOKUSEI_GetOvergrowHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gOvergrowHandlers;
}

/* Swarm. */
void HAND_TOKUSEI_SwarmBoostBug(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_TOKUSEI_PinchBoostType(flow, pokeId, POKETYPE_BUG);
}

/* Swarm: handler table. */
int *HAND_TOKUSEI_GetSwarmHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gSwarmHandlers;
}

/* Blaze, Torrent, Overgrow and Swarm: moves of the given type do 1.5 times damage when the owner has a third of its HP or less. */
void HAND_TOKUSEI_PinchBoostType(struct BtlServerFlow *flow, int pokeId, int moveType)
{
    struct BtlPokeParam *bpp;
    u32 hpThreshold;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        hpThreshold = BTL_CALC_DivideMaxHp(bpp, 3);
        if (func_021D59B4(bpp, 13) <= hpThreshold) {
            if (moveType == BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE))
                BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_1_5);
        }
    }
}

/* Guts: physical moves of an owner with a status condition do 1.5 times damage. */
void HAND_TOKUSEI_GutsBoostAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) != 0) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_PHYSICAL)
                BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_1_5);
        }
    }
}

/* Guts: handler table. */
int *HAND_TOKUSEI_GetGutsHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gGutsHandlers;
}

/* Plus/Minus (ability 57/58): power event of the owner, special move, an ally has Plus or Minus. */
void HAND_TOKUSEI_PlusMinusBoostSpecialPower(struct BtlEventFactor *factor, void *server, int pokeId, u8 *work)
{
    if (pokeId == BTL_EVENT_GetVar(3)) {
        if (HAND_TOKUSEI_CheckAllyHasAbility(server, pokeId, work, 0x39) != 0 || HAND_TOKUSEI_CheckAllyHasAbility(server, pokeId, work, 0x3a) != 0) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(0x12)) == 2)
                BTL_EVENT_MultiplyVar(0x35, 6 << 10);
        }
    }
}

int *HAND_TOKUSEI_GetPlusMinusHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gPlusMinusHandlers;
}

/* Collects the pokemon on the side of pokeId into idBuf; true if another one has ability abilityId. */
int HAND_TOKUSEI_CheckAllyHasAbility(void *server, int pokeId, u8 *idBuf, int abilityId)
{
    int side;
    u8 count;
    u8 i;

    side = BTL_SERVER_FLOW_GetPokeViewPos(server, pokeId);
    if (side != 6) {
        count = BTL_SERVER_FLOW_CollectAlivePokeIds(server, (u16)((7 << 8) | side), idBuf);
        for (i = 0; i < count; i++) {
            if (pokeId != idBuf[i]) {
                if (abilityId == func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(server, idBuf[i]), 0x11))
                    return 1;
            }
        }
    }
    return 0;
}

/* True if the pokemon is Cherrim (species 421). */
int HAND_TOKUSEI_IsCherrim(void *server, int pokeId)
{
    if (BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam(server, pokeId)) == 0x1a5) return 1;
    return 0;
}

/* Flower Gift: Cherrim takes the sunshine form when the weather is sun; marks the work flag. */
void HAND_TOKUSEI_FlowerGiftUpdateForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (HAND_TOKUSEI_IsCherrim(server, pokeId)) {
        HAND_TOKUSEI_ChangeCherrimForm(factor, server, pokeId, (unsigned char)(BTL_SERVER_FLOW_GetEffectiveWeatherThunk(server) == 1), 1);
        *work = 1;
    }
}

void HAND_TOKUSEI_FlowerGiftUpdateFormIfOwner(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(2)) HAND_TOKUSEI_FlowerGiftUpdateForm(factor, server, pokeId, work);
}

/* Queues a form change of pokeId to form, unless it already has that form. */
void HAND_TOKUSEI_ChangeCherrimForm(struct BtlEventFactor *factor, void *server, u32 pokeId, u32 form, u8 announce)
{
    u8 *cmd;

    if (form != func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(server, pokeId), 0x13)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(server, 0x39, pokeId);
        cmd[4] = pokeId;
        cmd[5] = form;
        ((struct BtlCmdHeader *)cmd)->announce = announce;
        BTL_SERVER_FLOW_InitMsgRecord(cmd + 8, 2, 0xde);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct BtlMessage *)(cmd + 8), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(server, cmd);
    }
}

void HAND_TOKUSEI_FlowerGiftReapplyForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (*work != 0 && HAND_TOKUSEI_IsCherrim(server, pokeId) != 0)
        HAND_TOKUSEI_ChangeCherrimForm(factor, server, pokeId, (u8)(BTL_SERVER_FLOW_GetEffectiveWeatherThunk(server) == 1), 1);
}

void HAND_TOKUSEI_FlowerGiftRevertFormIfOwner(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (*work && pokeId == BTL_EVENT_GetVar(2) && HAND_TOKUSEI_IsCherrim(server, pokeId))
        HAND_TOKUSEI_ChangeCherrimForm(factor, server, pokeId, 0, 0);
}

void HAND_TOKUSEI_FlowerGiftRevertForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (*work && HAND_TOKUSEI_IsCherrim(server, pokeId)) HAND_TOKUSEI_ChangeCherrimForm(factor, server, pokeId, 0, 0);
}

void HAND_TOKUSEI_FlowerGiftRevertFormOnFactorChange(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    int factorKey;

    if (*work != 0 && HAND_TOKUSEI_IsCherrim(server, pokeId) != 0) {
        if (pokeId == BTL_EVENT_GetVar(2)) {
            factorKey = BTL_EVENT_GetVar(0x10);
            if (factorKey != BTL_EVENT_GetFactorKey(factor))
                HAND_TOKUSEI_ChangeCherrimForm(factor, server, pokeId, 0, 0);
        }
    }
}

/* Flower Gift: ally of the attacker, sun, physical move: attack x1.5. */
void HAND_TOKUSEI_FlowerGiftBoostAllyAttack(struct BtlEventFactor *factor, void *server, int pokeId)
{
    u8 attackerId;

    if (HAND_TOKUSEI_IsCherrim(server, pokeId) != 0 && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(server) == 1) {
        attackerId = BTL_EVENT_GetVar(3);
        if (BTL_MAIN_IsPokeSamePair(pokeId, attackerId) != 0) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(0x12)) == 1)
                BTL_EVENT_MultiplyVar(0x35, 3 << 11);
        }
    }
}

/* Flower Gift: ally of the defender, sun, special move: special defense x1.5. */
void HAND_TOKUSEI_FlowerGiftBoostAllySpecialDefense(struct BtlEventFactor *factor, void *server, int pokeId)
{
    u8 defenderId;

    if (HAND_TOKUSEI_IsCherrim(server, pokeId) != 0 && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(server) == 1) {
        defenderId = BTL_EVENT_GetVar(4);
        if (BTL_MAIN_IsPokeSamePair(pokeId, defenderId) != 0) {
            if (BTL_EVENT_GetVar(0x1a) == 2)
                BTL_EVENT_MultiplyVar(0x35, 6 << 10);
        }
    }
}

int *HAND_TOKUSEI_GetFlowerGiftHandlers(int *handlerCount)
{
    *handlerCount = 11;
    return gFlowerGiftHandlers;
}

/* Rivalry: same gender x1.25, opposite gender x0.75, genderless no change. */
void HAND_TOKUSEI_RivalryScalePower(struct BtlEventFactor *factor, void *server, int pokeId)
{
    void *attacker;
    void *defender;
    u8 attackerGender;
    u8 defenderGender;

    if (pokeId == BTL_EVENT_GetVar(3)) {
        attacker = BTL_SERVER_FLOW_GetPokeParam(server, pokeId);
        defender = BTL_SERVER_FLOW_GetPokeParam(server, (u8)BTL_EVENT_GetVar(4));
        attackerGender = func_021D59B4(attacker, 0x12);
        defenderGender = func_021D59B4(defender, 0x12);
        if (attackerGender != 2 && defenderGender != 2) {
            if (attackerGender == defenderGender) {
                BTL_EVENT_MultiplyVar(0x31, 5 << 10);
                return;
            }
            BTL_EVENT_MultiplyVar(0x31, 3 << 10);
        }
    }
}

int *HAND_TOKUSEI_GetRivalryHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRivalryHandlers;
}

/* Technician: moves with base power 60 or less x1.5. */
void HAND_TOKUSEI_TechnicianBoostWeakMove(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(3) && (unsigned int)BTL_EVENT_GetVar(0x30) <= 0x3c) BTL_EVENT_MultiplyVar(0x31, 0x30 << 7);
}

void *HAND_TOKUSEI_GetTechnicianHandlers(int *handlerCount) { *handlerCount = 1; return &gTechnicianHandlers; }

/* Iron Fist: punching moves (move flag 7) x1.2. */
void HAND_TOKUSEI_IronFistBoostPunchPower(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(3) && WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(0x12), 7)) BTL_EVENT_MultiplyVar(0x31, 0x1333);
}

void *HAND_TOKUSEI_GetIronFistHandlers(int *handlerCount) { *handlerCount = 1; return &gIronFistHandlers; }

/* Reckless: recoil moves, Jump Kick and Hi Jump Kick x1.2. */
void HAND_TOKUSEI_RecklessBoostRecoilPower(struct BtlEventFactor *factor, void *server, int pokeId)
{
    u16 moveId;

    if (pokeId == BTL_EVENT_GetVar(3)) {
        moveId = BTL_EVENT_GetVar(0x12);
        if (WAZA_TOOL_GetParam(moveId, 0x1e) != 0 || moveId == 0x1a || moveId == 0x88)
            BTL_EVENT_MultiplyVar(0x31, 0x1333);
    }
}

int *HAND_TOKUSEI_GetRecklessHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRecklessHandlers;
}

/* Marvel Scale: defender has a status condition, physical move: defense x1.5. */
void HAND_TOKUSEI_MarvelScaleBoostDefense(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(4)) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(server, pokeId))) {
            BTL_EVENT_GetVar(0x12);
            if (BTL_EVENT_GetVar(0x1a) == 1)
                BTL_EVENT_MultiplyVar(0x35, 0x1800);
        }
    }
}

int *HAND_TOKUSEI_GetMarvelScaleHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMarvelScaleHandlers;
}

/* Mold Breaker: sets the ignore-ability flag while the owner attacks. */
void HAND_TOKUSEI_MoldBreakerSetIgnoreAbilities(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(3))
        BTL_EVENT_OverwriteVar(0x51, 1);
}

int *HAND_TOKUSEI_GetMoldBreakerFlagHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMoldBreakerFlagHandlers;
}

int *HAND_TOKUSEI_GetIndirectGuardCause1Handlers(int *handlerCount)
{
    *handlerCount = 2;
    return gIndirectGuardCause1Handlers;
}

void HAND_TOKUSEI_IndirectGuardCause1Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_TOKUSEI_BlockIndirectDamage(server, pokeId, work, 0x1);
}

void HAND_TOKUSEI_IndirectGuardCause1ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_TOKUSEI_ShowIndirectGuardMessage(server, pokeId, work, 0xc9);
}

int *HAND_TOKUSEI_GetIndirectGuardCause6Handlers(int *handlerCount)
{
    *handlerCount = 2;
    return gIndirectGuardCause6Handlers;
}

void HAND_TOKUSEI_IndirectGuardCause6Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_TOKUSEI_BlockIndirectDamage(server, pokeId, work, 0x6);
}

void HAND_TOKUSEI_IndirectGuardCause6ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_TOKUSEI_ShowIndirectGuardMessage(server, pokeId, work, 0xcf);
}

int *HAND_TOKUSEI_GetIndirectGuardCause8Handlers(int *handlerCount)
{
    *handlerCount = 2;
    return gIndirectGuardCause8Handlers;
}

void HAND_TOKUSEI_IndirectGuardCause8Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_TOKUSEI_BlockIndirectDamage(server, pokeId, work, 0x8);
}

void HAND_TOKUSEI_IndirectGuardCause8ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_TOKUSEI_ShowIndirectGuardMessage(server, pokeId, work, 0xc6);
}

/* Indirect damage guard: when the owner takes damage of cause 8 or blockedCause, cancel it and arm the work flag. */
void HAND_TOKUSEI_BlockIndirectDamage(struct BtlServerFlow *server, int pokeId, int *work, int blockedCause)
{
    if (pokeId == BTL_EVENT_GetVar(2) && pokeId != BTL_EVENT_GetVar(3)) {
        if (blockedCause == 8 || blockedCause == BTL_EVENT_GetVar(0x1f)) {
            if (BTL_EVENT_GetVar(0x20) < 0)
                work[0] = BTL_EVENT_OverwriteVar(0x41, 1);
        }
    }
}

/* Shows the guard message once; work[0] is the armed flag, work[1] the weather of the last message. */
void HAND_TOKUSEI_ShowIndirectGuardMessage(struct BtlServerFlow *server, int pokeId, int *work, int stringId)
{
    int weather;
    u8 *cmd;

    if (pokeId == BTL_EVENT_GetVar(2) && work[0] != 0) {
        weather = BTL_EVENT_GetVar(0x19);
        if (weather == 0 || work[1] != weather) {
            BTL_SERVER_FLOW_PushCmdRecord(server, 2, pokeId);
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(server, 4, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(cmd + 4, 2, stringId);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct BtlMessage *)(cmd + 4), pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(server, cmd);
            BTL_SERVER_FLOW_PushCmdRecord(server, 3, pokeId);
            work[1] = weather;
        }
        work[0] = 0;
    }
}

/* Halves residual damage: doubles the damage divisor of the owner. */
void HAND_TOKUSEI_HalveResidualDamage(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(2)) BTL_EVENT_OverwriteVar(0x20, BTL_EVENT_GetVar(0x20) << 1);
}

void *HAND_TOKUSEI_GetHalveResidualDamageHandlers(int *handlerCount) { *handlerCount = 1; return &gHalveResidualDamageHandlers; }

/* Leaf Guard: in sun, the defender cannot get a major status condition or the condition 0xe. */
void HAND_TOKUSEI_LeafGuardBlockStatus(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    int condition;
    if (pokeId == BTL_EVENT_GetVar(4) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(server) == 1) {
        condition = BTL_EVENT_GetVar(0x1d);
        if (BTL_CALC_HasDefaultSickCont(condition) || condition == 0xe) *work = BTL_EVENT_OverwriteVar(0x41, 1);
    }
}

/* Leaf Guard: in sun, cancels the event for the owner. */
void HAND_TOKUSEI_LeafGuardBlockOwnerEvent(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(2) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(server) == 1) BTL_EVENT_OverwriteVar(0x41, 1);
}

void *HAND_TOKUSEI_GetLeafGuardHandlers(int *handlerCount) { *handlerCount = 3; return &gLeafGuardHandlers; }

void HAND_TOKUSEI_ParalysisGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = HAND_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_PARALYSIS);
}

void HAND_TOKUSEI_ParalysisGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_PARALYSIS);
}

void HAND_TOKUSEI_ParalysisGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_PARALYSIS);
}

int *HAND_TOKUSEI_GetParalysisGuardHandlers(int *count)
{
    *count = 5;
    return gParalysisGuardHandlers;
}

void HAND_TOKUSEI_SleepGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    int blocked;

    blocked = HAND_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_SLEEP);
    *work = blocked;
    if (blocked == 0)
        *work = HAND_TOKUSEI_BlockSickIfTargeted(flow, pokeId, 0xe);
}

void HAND_TOKUSEI_SleepGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_SLEEP);
}

void HAND_TOKUSEI_SleepGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_SLEEP);
}

void HAND_TOKUSEI_SleepGuard_BlockOwnerEvent0E(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

int *HAND_TOKUSEI_GetSleepGuardHandlers(int *count)
{
    *count = 6;
    return gSleepGuardHandlers;
}

void HAND_TOKUSEI_FreezeGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = HAND_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_FREEZE);
}

void HAND_TOKUSEI_FreezeGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_FREEZE);
}

void HAND_TOKUSEI_FreezeGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_FREEZE);
}

int *HAND_TOKUSEI_GetFreezeGuardHandlers(int *count)
{
    *count = 5;
    return gFreezeGuardHandlers;
}

void HAND_TOKUSEI_PoisonGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = HAND_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_POISON);
}

void HAND_TOKUSEI_PoisonGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_POISON);
}

void HAND_TOKUSEI_PoisonGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_POISON);
}

int *HAND_TOKUSEI_GetPoisonGuardHandlers(int *count)
{
    *count = 5;
    return gPoisonGuardHandlers;
}

void HAND_TOKUSEI_BurnGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = HAND_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_BURN);
}

void HAND_TOKUSEI_BurnGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_BURN);
}

void HAND_TOKUSEI_BurnGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_BURN);
}

int *HAND_TOKUSEI_GetBurnGuardHandlers(int *count)
{
    *count = 5;
    return gBurnGuardHandlers;
}

void HAND_TOKUSEI_ConfusionGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = HAND_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_CONFUSION);
}

void HAND_TOKUSEI_ConfusionGuard_ShowBlockedMessage(void *factor, void *flow, int pokeId, int *work)
{
    HAND_TOKUSEI_ShowSickGuardMessage(factor, flow, pokeId, work, 0x165);
}

void HAND_TOKUSEI_ConfusionGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_CONFUSION);
}

void HAND_TOKUSEI_ConfusionGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_CONFUSION);
}

int *HAND_TOKUSEI_GetConfusionGuardHandlers(int *count)
{
    *count = 4;
    return gConfusionGuardHandlers;
}

void HAND_TOKUSEI_InfatuationGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = HAND_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_INFATUATION);
}

void HAND_TOKUSEI_InfatuationGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_INFATUATION);
}

void HAND_TOKUSEI_InfatuationGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_INFATUATION);
}

void HAND_TOKUSEI_InfatuationGuard_ShowBlockedMoveMessage(void *factor, void *flow, int pokeId)
{
    TokuseiMessageCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && (u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID) == 0x1bd) {
        if (BTL_EVENT_OverwriteVar(0x40, 1) != 0) {
            BTL_SERVER_FLOW_PushCmdRecord(flow, 2, pokeId);
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 4, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, 2, 0xd2);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            BTL_SERVER_FLOW_PushCmdRecord(flow, 3, pokeId);
        }
    }
}

int *HAND_TOKUSEI_GetInfatuationGuardHandlers(int *count)
{
    *count = 5;
    return gInfatuationGuardHandlers;
}

int HAND_TOKUSEI_BlockSickIfTargeted(void *flow, int pokeId, int sickIndex)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && sickIndex == BTL_EVENT_GetVar(BTL_EVAR_SICK_ID))
        return BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
    return 0;
}

void HAND_TOKUSEI_ShowSickGuardMessage(void *factor, void *flow, int pokeId, int *work, u16 strId)
{
    TokuseiMessageCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && *work == 1) {
        BTL_SERVER_FLOW_PushCmdRecord(flow, 2, pokeId);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 4, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, 2, strId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        BTL_SERVER_FLOW_PushCmdRecord(flow, 3, pokeId);
        *work = 0;
    }
}

void HAND_TOKUSEI_SickGuard_ShowBlockedMessage(void *factor, void *flow, int pokeId, int *work)
{
    HAND_TOKUSEI_ShowSickGuardMessage(factor, flow, pokeId, work, 0xd2);
}

void HAND_TOKUSEI_CureSickIfOwner(void *flow, int pokeId, int sickIndex)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        HAND_TOKUSEI_CureSick(flow, pokeId, sickIndex);
}

void HAND_TOKUSEI_CureSick(void *flow, int pokeId, int sickIndex)
{
    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), sickIndex) != 0) {
        TokuseiCureSickCmd *cmd;

        BTL_SERVER_FLOW_PushCmdRecord(flow, 2, pokeId);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 0xb, pokeId);
        cmd->sickIndex = sickIndex;
        cmd->showMessage = 1;
        cmd->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        BTL_SERVER_FLOW_PushCmdRecord(flow, 3, pokeId);
    }
}

void HAND_TOKUSEI_Drizzle_StartRain(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_StartWeather(flow, pokeId, TKS_WEATHER_RAIN);
}

int *HAND_TOKUSEI_GetDrizzleHandlers(int *count)
{
    *count = 2;
    return gDrizzleHandlers;
}

void HAND_TOKUSEI_Drought_StartSun(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_StartWeather(flow, pokeId, TKS_WEATHER_SUN);
}

int *HAND_TOKUSEI_GetDroughtHandlers(int *count)
{
    *count = 2;
    return gDroughtHandlers;
}

void HAND_TOKUSEI_SandStream_StartSandstorm(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_StartWeather(flow, pokeId, TKS_WEATHER_SAND);
}

int *HAND_TOKUSEI_GetSandStreamHandlers(int *count)
{
    *count = 2;
    return gSandStreamHandlers;
}

void HAND_TOKUSEI_SnowWarning_StartHail(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_StartWeather(flow, pokeId, TKS_WEATHER_HAIL);
}

int *HAND_TOKUSEI_GetSnowWarningHandlers(int *count)
{
    *count = 2;
    return gSnowWarningHandlers;
}

void HAND_TOKUSEI_StartWeather(void *flow, int pokeId, int weather)
{
    TokuseiWeatherCmd *cmd;
    int cmdFlagKind = 2;

    if (pokeId == BTL_EVENT_GetVar(cmdFlagKind)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 0x1d, pokeId);
        cmd->flags |= cmdFlagKind << 22;
        cmd->weather = weather;
        cmd->turns = 0xff;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}

void HAND_TOKUSEI_WeatherLock_ClearWeather(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        TokuseiWeatherCmd *cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 0x1d, pokeId);

        cmd->flags |= 2 << 22;
        cmd->weather = 0;
        cmd->announce = 1;
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, 1, 0x5e);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}

void HAND_TOKUSEI_WeatherLock_SetFailFlag(void)
{
    BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

int *HAND_TOKUSEI_GetWeatherLockHandlers(int *count)
{
    *count = 2;
    return gWeatherLockHandlers;
}

void HAND_TOKUSEI_IceBody_HealInHail(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_HealInWeather(flow, pokeId, TKS_WEATHER_HAIL);
}

int *HAND_TOKUSEI_GetIceBodyHandlers(int *count)
{
    *count = 1;
    return gIceBodyHandlers;
}

void HAND_TOKUSEI_RainDish_HealInRain(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_HealInWeather(flow, pokeId, TKS_WEATHER_RAIN);
}

int *HAND_TOKUSEI_GetRainDishHandlers(int *count)
{
    *count = 1;
    return gRainDishHandlers;
}

void HAND_TOKUSEI_HealInWeather(void *flow, int pokeId, int weather)
{
    struct BtlPokeParam *bpp;
    TokuseiHpCmd *cmd;

    if (weather == BTL_EVENT_GetVar(BTL_EVAR_WEATHER) && pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 5, pokeId);
        cmd->flags |= 0x800000;
        cmd->pokeId = pokeId;
        cmd->amount = BTL_CALC_DivideMaxHpMin1(bpp, 0x10);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
    }
}

void HAND_TOKUSEI_SolarPower_DamageInSun(void *factor, void *flow, int pokeId)
{
    int damage;
    TokuseiHpCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(BTL_EVAR_WEATHER) == TKS_WEATHER_SUN) {
        damage = BTL_CALC_DivideMaxHpMin1(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), 8);
        BTL_SERVER_FLOW_PushCmdRecord(flow, 2, pokeId);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 7, pokeId);
        cmd->pokeId = pokeId;
        cmd->amount = damage;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        BTL_SERVER_FLOW_PushCmdRecord(flow, 3, pokeId);
    }
}

void HAND_TOKUSEI_SolarPower_BoostSpecialAttackInSun(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == TKS_WEATHER_SUN) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == 2)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, 0x1800);
    }
}

int *HAND_TOKUSEI_GetSolarPowerHandlers(int *count)
{
    *count = 2;
    return gSolarPowerHandlers;
}

void HAND_TOKUSEI_StatLossGuard_BlockForeignDrop(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_EVENT_GetVar(BTL_EVAR_SICK_ID) != 8)
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

void HAND_TOKUSEI_StatLossGuard_BlockForeignChange(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

void HAND_TOKUSEI_StatLossGuard_BlockTargetedA(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

void HAND_TOKUSEI_StatLossGuard_BlockTargetedB(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(0x47, 1);
}

void HAND_TOKUSEI_StatLossGuard_BlockIfFlagged(void *factor, void *flow, int pokeId)
{
    if (HAND_COMMON_IsMoveTarget(pokeId) != 0 && BTL_EVENT_GetVar(5) == 1)
        BTL_EVENT_OverwriteVar(0x47, 1);
}

void *HAND_TOKUSEI_GetStatLossGuardHandlers(int *count)
{
    *count = 5;
    return &gStatLossGuardHandlers;
}

void HAND_TOKUSEI_Simple_DoubleStatChange(void *factor, void *flow, int pokeId)
{
    unsigned short doubled;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        doubled = BTL_EVENT_GetVar(BTL_EVAR_EFFECT_PERCENT) * 2;
        BTL_EVENT_OverwriteVar(BTL_EVAR_EFFECT_PERCENT, doubled);
    }
}

void HAND_TOKUSEI_Simple_SetOwnerFlag(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(0x45, 1);
}

int *HAND_TOKUSEI_GetSimpleHandlers(int *count)
{
    *count = 3;
    return gSimpleHandlers;
}

void HAND_TOKUSEI_Hydration_CureStatusInRain(void *factor, void *flow, int pokeId)
{
    TokuseiCureSickCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == TKS_WEATHER_RAIN) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))) {
            BTL_SERVER_FLOW_PushCmdRecord(flow, 2, pokeId);
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 0xb, pokeId);
            cmd->sickIndex = 0x24;
            cmd->pokeId = pokeId;
            cmd->showMessage = 1;
            cmd->flags |= 0x2000000;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            BTL_SERVER_FLOW_PushCmdRecord(flow, 3, pokeId);
        }
    }
}

int *HAND_TOKUSEI_GetHydrationHandlers(int *count)
{
    *count = 1;
    return gHydrationHandlers;
}

/* Contact abilities roll this chance (percent) to affect the attacker. */
#define CONTACT_ABILITY_PERCENT 30

/* Shed Skin: at the end of the turn, a 33% chance to cure the Pokemon's status condition. */
void HAND_TOKUSEI_ShedSkinOnTurnEnd(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExCureSick *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))) {
            if (HAND_TOKUSEI_RollChanceOrFlag(flow, 0x21)) {
                record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
                record->header |= HANDEX_FLAG_SHOW_ABILITY;
                record->header |= HANDEX_FLAG_SHOW_CURE_MESSAGE;
                record->sickKind = 0x24;
                record->pokeIds[0] = pokeId;
                record->pokeCount = 1;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
            }
        }
    }
}

void *HAND_TOKUSEI_AddShedSkin(int *handlerCount)
{
    *handlerCount = 1;
    return gShedSkinHandlers;
}

/* Poison Heal: while poisoned, the poison damage becomes 0 and the Pokemon recovers 1/8 of its HP. */
void HAND_TOKUSEI_PoisonHealOnSickDamage(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *self;
    struct HandExRecoverHp *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(BTL_EVAR_SICK_ID) == BTL_SICK_POISON) {
        self = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        BTL_EVENT_OverwriteVar(BTL_EVAR_DAMAGE, 0);
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RECOVER_HP, pokeId);
        record->amount = BTL_CALC_DivideMaxHpMin1(self, 8);
        record->pokeId = pokeId;
        record->header |= HANDEX_FLAG_SHOW_ABILITY;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}

void *HAND_TOKUSEI_AddPoisonHeal(int *handlerCount)
{
    *handlerCount = 1;
    return gPoisonHealHandlers;
}

/* Shell Armor / Battle Armor: the defender takes no critical hits (sets the general flag). */
void HAND_TOKUSEI_ShellArmorOnCriticalCheck(int myHandle, int flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

void *HAND_TOKUSEI_AddShellArmor(int *handlerCount)
{
    *handlerCount = 1;
    return gShellArmorHandlers;
}

/* Super Luck: the attacker's critical hit rank goes up by one. */
void HAND_TOKUSEI_SuperLuckOnCriticalCheck(int myHandle, int flow, int pokeId)
{
    unsigned char rank;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        rank = BTL_EVENT_GetVar(BTL_EVAR_CRITICAL_RANK) + 1;
        BTL_EVENT_OverwriteVar(BTL_EVAR_CRITICAL_RANK, rank);
    }
}

void *HAND_TOKUSEI_AddSuperLuck(int *handlerCount)
{
    *handlerCount = 1;
    return gSuperLuckHandlers;
}

/* Anger Point: when the defender takes a critical hit (not through a substitute),
   its Attack rises as far as it can go. */
void HAND_TOKUSEI_AngerPointOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *defender;
    struct HandExRankChange *record;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) != 0)
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_CRITICAL_FLAG) == 0)
        return;
    defender = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (func_021D5D50(defender, BTL_RANK_ATTACK) <= 0)
        return;
    record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
    record->rankKind = BTL_RANK_ATTACK;
    record->volume = func_021D5D50(defender, BTL_RANK_ATTACK);
    record->showMessage = 1;
    record->targetCount = 1;
    record->pokeId = pokeId;
    record->fromMove = 1;
    record->header |= HANDEX_FLAG_SHOW_ABILITY;
    BTL_SERVER_FLOW_InitMsgRecord(&record->message, HANDEX_MESSAGE_SET, 0x1e1);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
}

void *HAND_TOKUSEI_AddAngerPoint(int *handlerCount)
{
    *handlerCount = 1;
    return gAngerPointHandlers;
}

/* Poison Point: contact may poison the attacker. */
void HAND_TOKUSEI_PoisonPointOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    union SickCont sickCont;
    sickCont = BTL_CALC_MakeDefaultSickCont(BTL_SICK_POISON);
    HAND_TOKUSEI_TryAddContactSick(flow, pokeId, BTL_SICK_POISON, sickCont, CONTACT_ABILITY_PERCENT);
}

void *HAND_TOKUSEI_AddPoisonPoint(int *handlerCount)
{
    *handlerCount = 1;
    return gPoisonPointHandlers;
}

/* Static: contact may paralyze the attacker. */
void HAND_TOKUSEI_StaticOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    union SickCont sickCont;
    sickCont = BTL_CALC_MakeDefaultSickCont(BTL_SICK_PARALYSIS);
    HAND_TOKUSEI_TryAddContactSick(flow, pokeId, BTL_SICK_PARALYSIS, sickCont, CONTACT_ABILITY_PERCENT);
}

void *HAND_TOKUSEI_AddStatic(int *handlerCount)
{
    *handlerCount = 1;
    return gStaticHandlers;
}

/* Flame Body: contact may burn the attacker. */
void HAND_TOKUSEI_FlameBodyOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    union SickCont sickCont;
    sickCont = BTL_CALC_MakeDefaultSickCont(BTL_SICK_BURN);
    HAND_TOKUSEI_TryAddContactSick(flow, pokeId, BTL_SICK_BURN, sickCont, CONTACT_ABILITY_PERCENT);
}

void *HAND_TOKUSEI_AddFlameBody(int *handlerCount)
{
    *handlerCount = 1;
    return gFlameBodyHandlers;
}

/* Cute Charm: contact may infatuate the attacker when the two have opposite genders
   (neither is genderless). */
void HAND_TOKUSEI_CuteCharmOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *defender;
    struct BtlPokeParam *attacker;
    u8 defenderGender;
    u8 attackerGender;
    union SickCont sickCont;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) == 0 && BTL_SERVER_FLOW_CheckShowdownThunk(flow) == 0) {
        defender = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        attacker = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID));
        defenderGender = func_021D59B4(defender, BPP_VALUE_GENDER);
        attackerGender = func_021D59B4(attacker, BPP_VALUE_GENDER);
        if (defenderGender != BTL_GENDER_NONE && attackerGender != BTL_GENDER_NONE && defenderGender != attackerGender) {
            BTL_CALC_MakeSickContFromKind(BTL_SICK_INFATUATION, defender, &sickCont);
            HAND_TOKUSEI_TryAddContactSick(flow, pokeId, BTL_SICK_INFATUATION, sickCont, 0x1e);
        }
    }
}

void *HAND_TOKUSEI_AddCuteCharm(int *handlerCount)
{
    *handlerCount = 1;
    return gCuteCharmHandlers;
}

/* Effect Spore: contact may poison (about 1 in 3), paralyze or put the attacker to sleep. */
void HAND_TOKUSEI_EffectSporeOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    u32 roll;
    int sickKind;
    union SickCont sickCont;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) != 0)
        return;
    roll = BTL_CALC_Random(0x1e);
    if (roll > 0x14) {
        sickKind = BTL_SICK_POISON;
    } else {
        sickKind = BTL_SICK_PARALYSIS;
        if (roll <= 10)
            sickKind = BTL_SICK_SLEEP;
    }
    sickCont = BTL_CALC_MakeDefaultSickCont(sickKind);
    HAND_TOKUSEI_TryAddContactSick(flow, pokeId, sickKind, sickCont, 0x1e);
}

void *HAND_TOKUSEI_AddEffectSpore(int *handlerCount)
{
    *handlerCount = 1;
    return gEffectSporeHandlers;
}

/* Shared by the contact status abilities: if the hit made contact and the percent
   roll succeeds, add the status condition to the attacker. */
void HAND_TOKUSEI_TryAddContactSick(struct BtlServerFlow *flow, int pokeId, int sickKind, union SickCont sickCont, u8 percent)
{
    struct HandExAddSick *record;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) != 0)
        return;
    if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), 0) == 0)
        return;
    if (HAND_TOKUSEI_RollChanceOrFlag(flow, percent) == 0)
        return;
    record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
    record->header |= HANDEX_FLAG_SHOW_ABILITY;
    record->sickKind = sickKind;
    record->sickCont.raw = sickCont.raw;
    record->suppressMessage = 0;
    record->pokeId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
}

/* Rough Skin: a contact hit damages the attacker by 1/8 of its HP. */
void HAND_TOKUSEI_RoughSkinOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExDamage *record;
    u8 attackerId;
    struct BtlPokeParam *attacker;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) != 0)
        return;
    if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), 0) == 0)
        return;
    attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    attacker = BTL_SERVER_FLOW_GetPokeParam(flow, attackerId);
    if (BTL_POKEPARAM_IsFainted(attacker) != 0)
        return;
    record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_DAMAGE, pokeId);
    record->header |= HANDEX_FLAG_SHOW_ABILITY;
    record->pokeId = attackerId;
    record->amount = BTL_CALC_DivideMaxHpMin1(attacker, 8);
    BTL_SERVER_FLOW_InitMsgRecord(&record->message, HANDEX_MESSAGE_SET, 0x1ae);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, attackerId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
}

void *HAND_TOKUSEI_AddRoughSkin(int *handlerCount)
{
    *handlerCount = 1;
    return gRoughSkinHandlers;
}

/* Aftermath: when a contact hit makes the defender faint, the attacker takes 1/4 of its HP as damage. */
void HAND_TOKUSEI_AftermathOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExDamage *record;
    u8 attackerId;
    struct BtlPokeParam *attacker;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    if (BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) == 0)
        return;
    if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), 0) == 0)
        return;
    attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    attacker = BTL_SERVER_FLOW_GetPokeParam(flow, attackerId);
    record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_DAMAGE, pokeId);
    record->header |= HANDEX_FLAG_SHOW_ABILITY;
    record->pokeId = attackerId;
    record->amount = BTL_CALC_DivideMaxHpMin1(attacker, 4);
    record->unblockable = 1;
    BTL_SERVER_FLOW_InitMsgRecord(&record->message, HANDEX_MESSAGE_SET, 0x192);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, attackerId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
}

void *HAND_TOKUSEI_AddAftermath(int *handlerCount)
{
    *handlerCount = 1;
    return gAftermathHandlers;
}

/*
 * Forecast: when the weather changes, a Pokemon that has this ability switches
 * form to match it. Four gates come first (the species check passes, no battle
 * lock, the Pokemon is alive, the new form differs from the current one), then
 * the window-in, record, window-out sequence.
 */
void HAND_TOKUSEI_ForecastOnWeatherChange(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *self;
    struct HandExChangeType *record;
    u8 weather;

    if (HAND_COMMON_IsMoveTarget(pokeId) == 0)
        return;
    if (BTL_SERVER_FLOW_CheckShowdownThunk(flow) != 0)
        return;
    self = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (BTL_POKEPARAM_IsFainted(self) != 0)
        return;
    weather = (u8)BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
    if (weather == 0x11)
        return;
    if (BTL_POKEPARAM_HasType(self, weather) != 0)
        return;
    BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_ABILITY_WINDOW_IN, pokeId);
    record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CHANGE_FORM, pokeId);
    record->typePair = BTLV_CORE_PackByteTwice(weather);
    record->pokeId = pokeId;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_ABILITY_WINDOW_OUT, pokeId);
}

void *HAND_TOKUSEI_AddForecast(int *handlerCount)
{
    *handlerCount = 1;
    return gForecastHandlerEntries;
}

/* Synchronize: a poison, paralysis or burn inflicted on this Pokemon is passed on to
   the Pokemon that caused it. */
void HAND_TOKUSEI_SynchronizeOnSickAdded(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExAddSick *record;
    int sickKind;
    u8 attackerId;
    struct BtlPokeParam *self;
    union SickCont inflictedCont;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    sickKind = BTL_EVENT_GetVar(BTL_EVAR_SICK_ID);
    if (sickKind != BTL_SICK_POISON && sickKind != BTL_SICK_PARALYSIS && sickKind != BTL_SICK_BURN)
        return;
    attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    if (attackerId == BTL_POKEID_NONE || attackerId == pokeId)
        return;
    self = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    inflictedCont.raw = BTL_EVENT_GetVar(BTL_EVAR_SICK_CONT);
    BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_ABILITY_WINDOW_IN, pokeId);
    record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
    record->pokeId = attackerId;
    record->sickKind = sickKind;
    if (sickKind == BTL_SICK_POISON && BTLV_CORE_IsSlotKind1Index15(inflictedCont))
        record->sickCont.raw = inflictedCont.raw;
    else
        BTL_CALC_MakeSickContFromKind(sickKind, self, &record->sickCont);
    record->suppressMessage = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_ABILITY_WINDOW_OUT, pokeId);
}

void *HAND_TOKUSEI_AddSynchronize(int *handlerCount)
{
    *handlerCount = 1;
    return gSynchronizeHandlers;
}

/* Mold Breaker: when this Pokemon attacks, set the general flag so the defender's ability is ignored. */
void HAND_TOKUSEI_MoldBreakerOnAbilityCheck(int myHandle, int flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

void *HAND_TOKUSEI_AddMoldBreaker(int *handlerCount)
{
    *handlerCount = 1;
    return gMoldBreakerHandlerEntries;
}

/* Cloud Nine / Air Lock: the weather this Pokemon sees is cleared. */
void HAND_TOKUSEI_CloudNineOnWeatherCheck(int myHandle, int flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_TYPE, 0);
}

void *HAND_TOKUSEI_AddCloudNine(int *handlerCount)
{
    *handlerCount = 1;
    return gCloudNineHandlers;
}

void *HAND_TOKUSEI_AddTrace(int *handlerCount)
{
    *handlerCount = 1;
    return gTraceHandlers;
}

/*
 * Trace: copy a foe's ability. The work flag is 1 when the first attempt found no
 * Pokemon with a copyable ability; the handler then retries as foes enter the field.
 */
void HAND_TOKUSEI_TraceOnMemberIn(int myHandle, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 foeIds[3];
    u8 candidateIds[3];
    u8 tracedId;
    u32 abilityId;
    u8 enteringId;
    u8 candidateCount, i, choice;
    u32 foeCount;
    u16 foeMask;
    int slot;
    struct BtlPokeParam *foe;
    int foeAbility;
    struct HandExChangeAbility *record;
    enteringId = BTL_EVENT_GetVar(BTL_EVAR_POKE_ID);
    tracedId = BTL_POKEID_NONE;
    abilityId = 0;
    if (enteringId == pokeId) {
        foeMask = BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, pokeId);
        foeCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(foeMask | 0x100), foeIds);
        for (candidateCount = 0, i = 0; i < foeCount; i++) {
            if (!BTL_ID_IsAbilityTraceBlocked((u16)func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(flow, foeIds[i]), BPP_VALUE_ABILITY))) candidateIds[candidateCount++] = foeIds[i];
        }
        if (candidateCount != 0) {
            choice = candidateCount == 1 ? 0 : BTL_CALC_Random(candidateCount);
            foe = BTL_SERVER_FLOW_GetPokeParam(flow, candidateIds[choice]);
            abilityId = func_021D59B4(foe, BPP_VALUE_ABILITY);
            tracedId = BTL_POKEPARAM_GetPokeId(foe);
        } else {
            *work = 1;
        }
    } else if (!BTL_MAIN_IsPokeSamePair(enteringId, pokeId) && *work == 1) {
        slot = BTL_SERVER_FLOW_GetPokeViewPos(flow, enteringId);
        foeMask = BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, pokeId);
        if (slot != BTL_SLOT_NONE && (BTL_SERVER_FLOW_GetRule(flow) != 2 || BTL_MAIN_IsPosInTable(foeMask, slot))) {
            foeAbility = func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(flow, enteringId), BPP_VALUE_ABILITY);
            if (!BTL_ID_IsAbilityTraceBlocked((u16)foeAbility)) { abilityId = foeAbility; tracedId = enteringId; }
        }
    }
    if (abilityId != 0 && pokeId != BTL_POKEID_NONE) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CHANGE_ABILITY, pokeId);
        record->pokeId = pokeId;
        record->abilityId = abilityId;
        record->announce = 1;
        record->header |= HANDEX_FLAG_SHOW_ABILITY;
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, HANDEX_MESSAGE_SET, 0x17d);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, tracedId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, record->abilityId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}

/* Natural Cure: when the Pokemon leaves the field, cure its status condition. */
void HAND_TOKUSEI_NaturalCureOnMemberOut(int myHandle, void *flowWork, int pokeId)
{
    struct HandExCureSick *record;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flowWork, HANDEX_KIND_CURE_SICK, pokeId);
        record->sickKind = 0x24;
        record->pokeCount = 1;
        record->pokeIds[0] = pokeId;
        record->suppressMessage = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flowWork, record);
    }
}

void *HAND_TOKUSEI_AddNaturalCure(int *handlerCount)
{
    *handlerCount = 1;
    return gNaturalCureHandlers;
}

/* The defense sums are u16 accumulators; a u8 third parameter keeps its reload
   after the +0xf store. */

/* Download: on entering the field, compare the foes' total Defense and Special
   Defense and raise Attack or Special Attack by one stage accordingly. */
void HAND_TOKUSEI_DownloadOnMemberIn(int myHandle, int flowWork, u8 pokeId)
{
    u8 foeIds[4];
    u8 foeCount;
    u16 defenseSum;
    u16 spDefenseSum;
    u8 i;
    int rankKind;
    void *foe;
    struct HandExRankChange *record;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    foeCount = BTL_SERVER_FLOW_CollectOpponentPokeIds((struct BtlServerFlow *)flowWork, pokeId, foeIds);
    if (foeCount == 0)
        return;
    defenseSum = 0;
    spDefenseSum = 0;
    for (i = 0; i < foeCount; i++) {
        foe = BTL_SERVER_FLOW_GetPokeParam((struct BtlServerFlow *)flowWork, foeIds[i]);
        defenseSum = defenseSum + (u16)func_021D59B4(foe, BPP_VALUE_DEFENSE);
        spDefenseSum = spDefenseSum + (u16)func_021D59B4(foe, BPP_VALUE_SP_DEFENSE);
    }
    if (defenseSum >= spDefenseSum)
        rankKind = BTL_RANK_SP_ATTACK;
    else
        rankKind = BTL_RANK_ATTACK;
    record = BTL_SERVER_FLOW_AllocCmdRecord((struct BtlServerFlow *)flowWork, HANDEX_KIND_RANK_EFFECT, pokeId);
    record->header |= HANDEX_FLAG_SHOW_ABILITY;
    record->targetCount = 1;
    record->pokeId = pokeId;
    record->rankKind = rankKind;
    record->volume = 1;
    BTL_SERVER_FLOW_CommitCmdRecord((struct BtlServerFlow *)flowWork, record);
}

int *HAND_TOKUSEI_AddDownload(int *handlerCount)
{
    *handlerCount = 2;
    return gDownloadHandlers;
}

/* Move ids Forewarn rates as counter moves. */
#define MOVE_COUNTER 68

/* Type affinity value of a hit that is neither resisted nor super effective. */
#define AFFINITY_NORMAL 3

/* Forewarn's rating of a move: its power, or a fixed rating for variable-power moves. */
static inline u32 getMoveThreat(u16 moveId)
{
    u32 value;
    if (WAZA_TOOL_GetDamageType(moveId)) {
        value = (u8)WAZA_TOOL_GetPower(moveId);
        if (value == 1) {
            if (WAZA_TOOL_GetCategory(moveId) == MOVE_CATEGORY_OHKO) value = 150;
            else if (moveId == MOVE_COUNTER || moveId == MOVE_MIRROR_COAT || moveId == MOVE_METAL_BURST) value = 120;
            else value = 80;
        }
    } else {
        value = 1;
    }
    return value;
}

/* Forewarn: on entering the field, reveal the strongest move among the foes
   (ties are chosen at random). */
void HAND_TOKUSEI_ForewarnOnMemberIn(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    u8 foeIds[4];
    struct BtlPokeParam *foe;
    ForewarnCandidate *candidates;
    u8 foeCount, moveCount, i;
    u16 moveId;
    u8 candidateCount, j, choice;
    u32 bestThreat, threat;
    struct HandExMessage *record;
    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) return;
    foeCount = BTL_SERVER_FLOW_CollectOpponentPokeIds(flow, pokeId, foeIds);
    bestThreat = 0;
    candidateCount = 0;
    candidates = (ForewarnCandidate *)BTL_SERVER_FLOW_GetScratchBuffer(flow, 12);
    for (i = 0; i < foeCount; i++) {
        foe = BTL_SERVER_FLOW_GetPokeParam(flow, foeIds[i]);
        moveCount = BTL_POKEPARAM_GetMoveCount(foe);
        for (j = 0; j < moveCount; j++) {
            moveId = BTL_POKEPARAM_GetMoveId(foe, j);
            threat = getMoveThreat(moveId);
            if (threat >= bestThreat) {
                if (threat > bestThreat) { bestThreat = threat; candidateCount = 0; }
                candidates[candidateCount].pokeId = BTL_POKEPARAM_GetPokeId(foe);
                candidates[candidateCount].moveId = moveId;
                candidateCount++;
            }
        }
    }
    if (candidateCount == 0) return;
    choice = BTL_CALC_Random(candidateCount);
    BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_ABILITY_WINDOW_IN, pokeId);
    record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&record->message, HANDEX_MESSAGE_SET, 0x1b1);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, candidates[choice].pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, candidates[choice].moveId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_ABILITY_WINDOW_OUT, pokeId);
}

int *HAND_TOKUSEI_AddForewarn(int *handlerCount) { *handlerCount = 2; return &gForewarnHandlers; }

/* Anticipation: on entering the field, announce it if a foe has a move that is
   super effective against this Pokemon or is a one-hit KO. */
void HAND_TOKUSEI_AnticipationOnMemberIn(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    u8 foeIds[4];
    u8 foeCount;
    u8 i;
    struct BtlPokeParam *myPoke;
    struct HandExMessage *record;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    foeCount = BTL_SERVER_FLOW_CollectOpponentPokeIds(flow, pokeId, foeIds);
    myPoke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    for (i = 0; i < foeCount; i++) {
        if (HAND_TOKUSEI_AnticipationFoeIsThreat(myPoke, BTL_SERVER_FLOW_GetPokeParam(flow, foeIds[i])) != 0)
            break;
    }
    if (i == foeCount)
        return;
    BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_ABILITY_WINDOW_IN, pokeId);
    record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&record->message, HANDEX_MESSAGE_SET, 0x1b4);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_ABILITY_WINDOW_OUT, pokeId);
}

/* Whether the foe has a one-hit KO move or a damaging move super effective against myPoke. */
int HAND_TOKUSEI_AnticipationFoeIsThreat(struct BtlPokeParam *myPoke, struct BtlPokeParam *foe)
{
    u16 myTypes;
    u8 moveCount;
    u8 i;
    u16 moveId;

    myTypes = BTL_POKEPARAM_GetTypePair(myPoke);
    moveCount = BTL_POKEPARAM_GetMoveCount(foe);
    for (i = 0; i < moveCount; i++) {
        moveId = BTL_POKEPARAM_GetMoveId(foe, i);
        if (WAZA_TOOL_GetCategory(moveId) == MOVE_CATEGORY_OHKO)
            return 1;
        if (WAZA_TOOL_IsDamaging(moveId) != 0) {
            if (BTL_CALC_GetTypeAffinityVsPair(WAZA_TOOL_GetType(moveId), myTypes) > AFFINITY_NORMAL)
                return 1;
        }
    }
    return 0;
}

int *HAND_TOKUSEI_AddAnticipation(int *handlerCount)
{
    *handlerCount = 2;
    return gAnticipationHandlers;
}

/* Frisk: on entry, shows the held item of one opposing Pokemon chosen at random. */
void HAND_TOKUSEI_FriskShowOpponentItem(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u16 itemIds[4];
    u8 targetIds[4];
    u8 targetCount;
    u8 itemCount;
    u8 i;
    u8 choice;
    BtlMessageCmd *cmd;
    struct BtlPokeParam *target;
    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) return;
    targetCount = BTL_SERVER_FLOW_CollectOpponentPokeIds(flow, pokeId, targetIds);
    itemCount = 0;
    for (i = 0; i < targetCount; i++) {
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetIds[i]);
        itemIds[itemCount] = BTL_POKEPARAM_GetItem(target);
        if (itemIds[itemCount] != 0) itemCount++;
    }
    if (itemCount == 0) return;
    choice = BTL_CALC_Random(itemCount);
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_FRISK_ITEM);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, itemIds[choice]);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
}

BtlEventHandler *HAND_TOKUSEI_GetFriskHandlers(int *handlerCount) { *handlerCount = 2; return gFriskHandlers; }

BtlEventHandler *HAND_TOKUSEI_GetSturdyHandlers(int *handlerCount) { *handlerCount = 3; return gSturdyHandlers; }

/* Sturdy: a one-hit knockout move against the owner has no effect. */
void HAND_TOKUSEI_SturdyBlockOneHitKo(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlMessageCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    if (BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1) == 0)
        return;
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
}

/* Sturdy: at full HP the owner survives a knockout blow; work[0] tells the message handler. */
void HAND_TOKUSEI_SturdyEndureFromFullHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (BTL_POKEPARAM_IsHpFull(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) != 0) {
            *work = BTL_EVENT_OverwriteVar(BTL_EVAR_ENDURE_REASON, BTL_ENDURE_REASON_STURDY);
            return;
        }
        *work = 0;
    }
}

/* Sturdy: shows the message after the owner has endured a blow. */
void HAND_TOKUSEI_SturdyShowEndureMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    BtlMessageCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    if (*work == 0)
        return;
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_STURDY_ENDURE);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
    *work = 0;
}

/* Unaware: the attacker ignores the defender's defense boosts, the defender ignores the attacker's attack boosts. */
void HAND_TOKUSEI_UnawareNeutralizeStatStages(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        BTL_EVENT_OverwriteVar(BTL_EVAR_DEFENSE_STAGE, BTL_STAT_STAGE_NEUTRAL);
        return;
    }
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_ATTACK_STAGE, BTL_STAT_STAGE_NEUTRAL);
}

/* Unaware: when the owner defends, sets the generic flag (ignores the attacker's accuracy boosts). */
void HAND_TOKUSEI_UnawareIgnoreAccuracyStage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 1);
}

/* Unaware: when the owner attacks, sets the generic flag (ignores the defender's evasion boosts). */
void HAND_TOKUSEI_UnawareIgnoreEvasionStage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 1);
}

BtlEventHandler *HAND_TOKUSEI_GetUnawareHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gUnawareHandlers;
}

/* Heatproof: fire moves against the owner lose half their power. */
void HAND_TOKUSEI_HeatproofHalveFirePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == POKETYPE_FIRE)
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_0_5);
}

/* Heatproof: burn damage to the owner is halved (at least 1). */
void HAND_TOKUSEI_HeatproofHalveBurnDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    int damage;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_SICK_ID) != BTL_SICK_BURN)
        return;
    damage = BTL_EVENT_GetVar(BTL_EVAR_DAMAGE);
    BTL_EVENT_OverwriteVar(BTL_EVAR_DAMAGE, BTL_CALC_Max(damage / 2, 1));
}

BtlEventHandler *HAND_TOKUSEI_GetHeatproofHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gHeatproofHandlers;
}

/* Absorb abilities: nonzero when a move of moveType from another Pokemon hits the owner and is nullified. */
int HAND_TOKUSEI_AbsorbCheckMoveType(struct BtlServerFlow *flow, int pokeId, int moveType)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && moveType == BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE))
        return BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1);
    return 0;
}

/* Absorb abilities: restore 1/divisor of the owner's HP, or show "no effect" at full HP. */
void HAND_TOKUSEI_AbsorbRecoverHp(struct BtlServerFlow *flow, int pokeId, int divisor)
{
    struct BtlPokeParam *owner;
    BtlRecoverHpCmd *recoverCmd;
    BtlMessageCmd *messageCmd;

    owner = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (BTL_POKEPARAM_IsHpFull(owner) == 0) {
        recoverCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_RECOVER_HP, pokeId);
        recoverCmd->pokeId = pokeId;
        recoverCmd->amount = BTL_CALC_DivideMaxHpMin1(owner, divisor);
        recoverCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_InitMsgRecord(&recoverCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABSORB_RECOVER_HP);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&recoverCmd->strParam, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, recoverCmd);
    } else {
        messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->strParam, pokeId);
        messageCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
    }
    BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 1);
}

/* Absorb abilities: raise a stat of the owner, or show "no effect" when it cannot rise. */
void HAND_TOKUSEI_AbsorbRaiseStat(struct BtlServerFlow *flow, int pokeId, u32 statId, int amount)
{
    BtlRankCmd *rankCmd;
    BtlMessageCmd *messageCmd;

    if (func_021D5D14(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), statId, amount) != 0) {
        rankCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_RANK, pokeId);
        rankCmd->targetCount = 1;
        rankCmd->targets[0] = pokeId;
        rankCmd->showMessage = 1;
        rankCmd->statId = statId;
        rankCmd->amount = amount;
        rankCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rankCmd);
    } else {
        messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->strParam, pokeId);
        messageCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
    }
}

/* Dry Skin: sun hurts the owner by 1/8, rain restores 1/8. */
void HAND_TOKUSEI_DrySkinWeatherEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlDamageCmd *damageCmd;
    BtlRecoverHpCmd *recoverCmd;
    struct BtlPokeParam *owner;
    u8 weather;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        owner = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        weather = BTL_EVENT_GetVar(BTL_EVAR_WEATHER);
        if (weather == BTL_WEATHER_SUN) {
            BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
            damageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_DAMAGE, pokeId);
            damageCmd->pokeId = pokeId;
            damageCmd->amount = BTL_CALC_DivideMaxHpMin1(owner, 8);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, damageCmd);
            BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
        } else if (weather == BTL_WEATHER_RAIN) {
            recoverCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_RECOVER_HP, pokeId);
            recoverCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            recoverCmd->pokeId = pokeId;
            recoverCmd->amount = BTL_CALC_DivideMaxHpMin1(owner, 8);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, recoverCmd);
        }
    }
}

/* Dry Skin: fire moves against the owner gain 1.25 times power. */
void HAND_TOKUSEI_DrySkinBoostFireDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == POKETYPE_FIRE)
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_25);
}

/* Dry Skin: absorbs water moves and restores 1/4 of the HP. */
void HAND_TOKUSEI_DrySkinAbsorbWater(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(flow, pokeId, POKETYPE_WATER))
        HAND_TOKUSEI_AbsorbRecoverHp(flow, pokeId, 4);
}

BtlEventHandler *HAND_TOKUSEI_GetDrySkinHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gDrySkinHandlers;
}

/* Water Absorb: absorbs water moves and restores 1/4 of the HP. */
void HAND_TOKUSEI_WaterAbsorbAbsorbWater(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(flow, pokeId, POKETYPE_WATER))
        HAND_TOKUSEI_AbsorbRecoverHp(flow, pokeId, 4);
}

BtlEventHandler *HAND_TOKUSEI_GetWaterAbsorbHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWaterAbsorbHandlers;
}

/* Volt Absorb: absorbs electric moves and restores 1/4 of the HP. */
void HAND_TOKUSEI_VoltAbsorbAbsorbElectric(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(flow, pokeId, POKETYPE_ELECTRIC))
        HAND_TOKUSEI_AbsorbRecoverHp(flow, pokeId, 4);
}

/* Volt Absorb's table is the second row after the start of Motor Drive's table object. */
BtlEventHandler *HAND_TOKUSEI_GetVoltAbsorbHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMotorDriveHandlers + 1;
}

BtlEventHandler *HAND_TOKUSEI_GetMotorDriveHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMotorDriveHandlers;
}

/* Motor Drive: absorbs electric moves and raises Speed by one stage. */
void HAND_TOKUSEI_MotorDriveAbsorbElectric(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(flow, pokeId, POKETYPE_ELECTRIC))
        HAND_TOKUSEI_AbsorbRaiseStat(flow, pokeId, BTL_STAT_SPEED, 1);
}

/* Scrappy: the owner's attacks ignore the immunity of Ghost types. */
void HAND_TOKUSEI_ScrappyIgnoreGhostImmunity(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_TYPE) == POKETYPE_GHOST)
        BTL_EVENT_OverwriteVar(BTL_EVAR_IMMUNITY_OVERRIDE_FLAG, 1);
}

BtlEventHandler *HAND_TOKUSEI_GetScrappyHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gScrappyHandlers;
}

/* Soundproof: sound moves against the owner have no effect. */
void HAND_TOKUSEI_SoundproofBlockSoundMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlMessageCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), BTL_WAZA_FLAG_SOUND) != 0 && BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1) != 0) {
            BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
        }
    }
}

BtlEventHandler *HAND_TOKUSEI_GetSoundproofHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSoundproofHandlers;
}

/* Levitate: sets the generic flag once for the owner; work[0] gets the result. */
void HAND_TOKUSEI_LevitateSetFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_FORCE_FLOATING_FLAG) == 0)
            *work = BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 1);
    }
}

/* Levitate: shows "no effect" once when the flag was set. */
void HAND_TOKUSEI_LevitateShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    BtlMessageCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *work != 0) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
        cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        *work = 0;
    }
}

/* Levitate: clears the flag when the owner's event ends. */
void HAND_TOKUSEI_LevitateClearFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        *work = 0;
}

BtlEventHandler *HAND_TOKUSEI_GetLevitateHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gLevitateHandlers;
}

/* Wonder Guard: damaging moves from another Pokemon that are not super effective have no effect. */
void HAND_TOKUSEI_WonderGuardBlockMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlMessageCmd *cmd;
    struct BtlPokeParam *defender;
    u16 moveId;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    defender = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
    if (WAZA_TOOL_IsDamaging(moveId) == 0)
        return;
    if (moveId == BTL_MOVE_STRUGGLE)
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_TYPE_AFFINITY) > BTL_AFFINITY_NEUTRAL)
        return;
    if (BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1) == 0)
        return;
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
}

BtlEventHandler *HAND_TOKUSEI_GetWonderGuardHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWonderGuardHandlers;
}

/* Truant: every other turn the owner loafs; work[0] is the loafing flag, work[1] the fail result. */
void HAND_TOKUSEI_TruantToggleLoafing(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (*work != 0) {
            work[1] = BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_ABILITY);
            *work = 0;
        } else
            *work = 1;
    }
}

/* Truant: starts loafing for the next turn after the owner acted. */
void HAND_TOKUSEI_TruantStartLoafing(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_POKEPARAM_TestTurnFlag(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), 0))
            *work = 1;
    }
}

/* Truant: shows the loafing message when the fail result is set. */
void HAND_TOKUSEI_TruantShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    BtlMessageCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && work[1] != 0) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
        cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_TRUANT_LOAFING);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        work[1] = 0;
    }
}

/* Truant: clears the loafing flag when the event variable 12 is 7. */
void HAND_TOKUSEI_TruantClearLoafing(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(12) == 7)
        *work = 0;
}

BtlEventHandler *HAND_TOKUSEI_GetTruantHandlers(int *handlerCount)
{
    *handlerCount = 4;
    return gTruantHandlers;
}

/* Damp: Explosion and Self-Destruct fail; work[0] is the fail result, work[1] the move. */
void HAND_TOKUSEI_DampBlockExplosion(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u16 moveId;
    moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
    *work = 0;
    if (moveId == BTL_MOVE_EXPLOSION || moveId == BTL_MOVE_SELF_DESTRUCT) {
        if (BTL_EVENT_GetVar(BTL_EVAR_FAIL_REASON) == 0) {
            *work = BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_ABILITY);
            work[1] = moveId;
        }
    }
}

/* Damp: shows the message that names the owner and the blocked move. */
void HAND_TOKUSEI_DampShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    BtlMessageCmd *cmd;
    u32 ownerId;

    if (*work != 0) {
        ownerId = (u8)BTL_EVENT_GetVar(BTL_EVAR_POKE_ID);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
        cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_DAMP_BLOCK);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, ownerId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, work[1]);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        *work = 0;
    }
}

/* Damp: while the owner is on the field, Aftermath is blocked. */
void HAND_TOKUSEI_DampAddSkipCheck(struct BtlEventFactor *factor)
{
    BTL_EVENT_SetFactorSkipCheck(factor, HAND_TOKUSEI_DampSkipAftermath);
}

/* Damp: removes the skip check. */
void HAND_TOKUSEI_DampRemoveSkipCheck(struct BtlEventFactor *factor)
{
    BTL_EVENT_ClearFactorSkipCheck(factor);
}

/* Damp: removes the skip check when the owner's event comes. */
void HAND_TOKUSEI_DampRemoveSkipCheckForOwner(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_ClearFactorSkipCheck(factor);
}

/* Damp: skip check that blocks the factors of the Aftermath ability. */
int HAND_TOKUSEI_DampSkipAftermath(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId)
{
    if (factorType == BTL_EVENT_TYPE_ABILITY && key == ABILITY_AFTERMATH) {
        return 1;
    }
    return 0;
}

BtlEventHandler *HAND_TOKUSEI_GetDampHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gDampHandlers;
}

/* Flash Fire: after absorbing fire, the owner's fire moves gain 1.5 times power. */
void HAND_TOKUSEI_FlashFireBoostFireDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_CONT_FLAG_FLASH_FIRE) && BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == POKETYPE_FIRE)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_1_5);
}

/* Flash Fire: clears the absorbed-fire flag of the owner. */
void HAND_TOKUSEI_FlashFireClearFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlContFlagCmd *cmd;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_CONT_FLAG_FLASH_FIRE)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_CLEAR_CONT_FLAG, pokeId);
        cmd->pokeId = pokeId;
        cmd->flagIndex = BTL_CONT_FLAG_FLASH_FIRE;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}

/* Flash Fire: absorbs fire moves; the first time it also sets the absorbed-fire flag. */
void HAND_TOKUSEI_FlashFireAbsorbFire(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlMessageCmd *messageCmd;
    BtlContFlagCmd *flagCmd;

    if (HAND_TOKUSEI_AbsorbCheckMoveType(flow, pokeId, POKETYPE_FIRE) != 0) {
        BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_CONT_FLAG_FLASH_FIRE) == 0) {
            messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_FLASH_FIRE_ABSORB);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->strParam, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
            flagCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_SET_CONT_FLAG, pokeId);
            flagCmd->pokeId = pokeId;
            flagCmd->flagIndex = BTL_CONT_FLAG_FLASH_FIRE;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, flagCmd);
        } else {
            messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->strParam, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
        }
        BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
    }
}

BtlEventHandler *HAND_TOKUSEI_GetFlashFireHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gFlashFireHandlers;
}

/* Bad Dreams: hurts every sleeping opposing Pokemon by 1/8 of its HP. */
void HAND_TOKUSEI_BadDreamsHurtSleepers(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 victimIds[4];
    struct BtlPokeParam *victim;
    u8 victimCount;
    int popupOpen;
    BtlDamageCmd *cmd;
    u8 i;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        popupOpen = 0;
        victimCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, pokeId) | 0x100), victimIds);
        for (i = 0; i < victimCount; i++) {
            victim = BTL_SERVER_FLOW_GetPokeParam(flow, victimIds[i]);
            if (BTL_POKEPARAM_HasSick(victim, BTL_SICK_SLEEP)) {
                if (!popupOpen) {
                    popupOpen = 1;
                    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
                }
                cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_DAMAGE, pokeId);
                cmd->pokeId = victimIds[i];
                cmd->amount = BTL_CALC_DivideMaxHpMin1(victim, 8);
                BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_BAD_DREAMS_HURT);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, victimIds[i]);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            }
        }
        if (popupOpen) BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
    }
}

BtlEventHandler *HAND_TOKUSEI_GetBadDreamsHandlers(int *handlerCount) { *handlerCount = 1; return gBadDreamsHandlers; }

/* Run Away: the first handler of its table; belongs to hand_tokusei_021db0e4.c. */
void HAND_TOKUSEI_RunAwayCheckEscape(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int unusedArg)
{
    BTLV_CORE_EventSetFlagIfAttacker(factor, flow, pokeId, unusedArg);
}

/* Run Away: after the escape check passes, show the escape message with its sound. */
void HAND_TOKUSEI_RunAway_ShowEscapeMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExMessage *msg;

    if (BTLV_CORE_EventTrySetFlagIfAttacker(factor, flow, pokeId) != 0) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_MESSAGE, pokeId);
        msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 1, 0x48);
        BTL_SERVER_FLOW_SetMsgRecordSe(&msg->message, 0x56a);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}

const BtlEventHandler *HAND_TOKUSEI_GetRunAwayHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gRunAwayHandlers;
}

/* Mold Breaker, Turboblaze, Teravolt: when the poke enters, show the message of its own ability. */
void HAND_TOKUSEI_MoldBreaker_ShowAbilityMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExMessage *msg;
    int strId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        switch (BTL_EVENT_GetFactorKey(factor)) {
        case 0xa3:
            strId = 0x1f9;
            break;
        case 0xa4:
            strId = 0x1f6;
            break;
        default:
            strId = 0x1ba;
            break;
        }
        BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_TOKWIN_IN, pokeId);
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, strId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_TOKWIN_OUT, pokeId);
    }
}

/* Skip check of the holder: ability factors listed as breakable are skipped. */
int HAND_TOKUSEI_MoldBreaker_SkipCheck(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId)
{
    if (factorType == BTL_EVENT_TYPE_ABILITY && BTL_ID_IsAbilityIgnoredByMoldBreaker(key))
        return 1;
    return 0;
}

/* Mold Breaker: when the holder attacks, install the skip check on its factor (BTL_EVENT_SetFactorSkipCheck stores the pointer unchanged). */
void HAND_TOKUSEI_MoldBreaker_InstallSkipCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *skipCheckSet)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && *skipCheckSet == 0) {
        BTL_EVENT_SetFactorSkipCheck(factor, HAND_TOKUSEI_MoldBreaker_SkipCheck);
        *skipCheckSet = 1;
    }
}

void HAND_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent4(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *skipCheckSet)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *skipCheckSet == 1) {
        BTL_EVENT_ClearFactorSkipCheck(factor);
        *skipCheckSet = 0;
    }
}

void HAND_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent6A(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *skipCheckSet)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *skipCheckSet == 1) {
        BTL_EVENT_ClearFactorSkipCheck(factor);
        *skipCheckSet = 0;
    }
}

const BtlEventHandler *HAND_TOKUSEI_GetMoldBreakerSkipCheckHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gMoldBreakerSkipCheckHandlers;
}

/* Forecast: set the form of the holder from the current weather. */
void HAND_TOKUSEI_Forecast_ApplyWeatherForm(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *formActive)
{
    HAND_TOKUSEI_Forecast_SetFormForWeather(flow, pokeId, BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow));
    *formActive = 1;
}

void HAND_TOKUSEI_Forecast_ApplyWeatherFormOnEntry(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *formActive)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) HAND_TOKUSEI_Forecast_ApplyWeatherForm(factor, flow, pokeId, formActive);
}

void HAND_TOKUSEI_Forecast_RefreshWeatherForm(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *formActive)
{
    if (*formActive != 0) HAND_TOKUSEI_Forecast_SetFormForWeather(flow, pokeId, BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow));
}

void HAND_TOKUSEI_Forecast_ResetFormWhenActive(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *formActive)
{
    if (*formActive != 0) HAND_TOKUSEI_Forecast_ResetForm(factor, flow, pokeId);
}

/* Go back to the base form when the holder gets another ability. */
void HAND_TOKUSEI_Forecast_ResetFormOnAbilityChange(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    int newAbilityId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        newAbilityId = BTL_EVENT_GetVar(BTL_EVAR_NEW_ABILITY_ID);
        if (newAbilityId != BTL_EVENT_GetFactorKey(factor)) HAND_TOKUSEI_Forecast_ResetForm(factor, flow, pokeId);
    }
}

void HAND_TOKUSEI_Forecast_ResetFormOnEvent6A(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) HAND_TOKUSEI_Forecast_ResetForm(factor, flow, pokeId);
}

/* Put a Castform that is not in its base form back to the base form. */
void HAND_TOKUSEI_Forecast_ResetForm(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExChangeForm *cmd;
    struct BtlPokeParam *bpp;

    bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (BTL_POKEPARAM_GetSpecies(bpp) == SPECIES_CASTFORM && func_021D59B4(bpp, BPP_VALUE_FORM) != 0) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_CHANGE_FORM, pokeId);
        cmd->pokeId = pokeId;
        cmd->form = 0;
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, 2, 0xde);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}

/* Change a Castform to the form of the weather (none, sun, rain, hail); other weather gives the base form. */
void HAND_TOKUSEI_Forecast_SetFormForWeather(struct BtlServerFlow *flow, int pokeId, u32 weather)
{
    HandExChangeForm *cmd;
    struct BtlPokeParam *bpp;
    u32 currentForm;
    u32 newForm;

    bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (BTL_POKEPARAM_GetSpecies(bpp) == SPECIES_CASTFORM) {
        currentForm = (u8)func_021D59B4(bpp, BPP_VALUE_FORM);
        switch (weather) {
        case 0:
            newForm = 0;
            break;
        case 1:
            newForm = 1;
            break;
        case 2:
            newForm = 2;
            break;
        case 3:
            newForm = 3;
            break;
        default:
            newForm = 0;
            break;
        }
        if (newForm != currentForm) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_CHANGE_FORM, pokeId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->pokeId = pokeId;
            cmd->form = newForm;
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, 2, 0xde);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}

const BtlEventHandler *HAND_TOKUSEI_GetForecastHandlers(int *handlerCount)
{
    *handlerCount = 9;
    return gForecastHandlers;
}

const BtlEventHandler *HAND_TOKUSEI_GetStormDrainHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gStormDrainHandlers;
}

/* Storm Drain: redirect single-target water moves to the holder. */
void HAND_TOKUSEI_StormDrain_CheckRedirect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *redirected)
{
    *redirected = HAND_TOKUSEI_CheckRedirectMoveType(flow, pokeId, redirected, POKETYPE_WATER);
}

/* Storm Drain: a water move that hit the holder is absorbed; the holder gains a Sp. Atk rank. */
void HAND_TOKUSEI_StormDrain_AbsorbWaterMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(flow, pokeId, POKETYPE_WATER) != 0) HAND_TOKUSEI_AbsorbRaiseStat(flow, pokeId, BTL_STAT_SP_ATTACK, 1);
}

const BtlEventHandler *HAND_TOKUSEI_GetLightningRodHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gLightningRodHandlers;
}

/* Lightning Rod: redirect single-target electric moves to the holder. */
void HAND_TOKUSEI_LightningRod_CheckRedirect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *redirected)
{
    *redirected = HAND_TOKUSEI_CheckRedirectMoveType(flow, pokeId, redirected, POKETYPE_ELECTRIC);
}

/* Lightning Rod and Storm Drain: show the message when a move was redirected to the holder. */
void HAND_TOKUSEI_Redirect_ShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *redirected)
{
    HandExMessage *msg;

    if (*redirected != 0) {
        if (HAND_COMMON_IsMoveTarget(pokeId) != 0) {
            msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_MESSAGE, pokeId);
            msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
            BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x1c0);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        }
        *redirected = 0;
    }
}

/* Lightning Rod: an electric move that hit the holder is absorbed; the holder gains a Sp. Atk rank. */
void HAND_TOKUSEI_LightningRod_AbsorbElectricMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(flow, pokeId, POKETYPE_ELECTRIC) != 0) HAND_TOKUSEI_AbsorbRaiseStat(flow, pokeId, BTL_STAT_SP_ATTACK, 1);
}

/* True if a move of typeId from another poke can be redirected to the poke pokeId. */
int HAND_TOKUSEI_CheckRedirectMoveType(struct BtlServerFlow *flow, int pokeId, int *work, int typeId)
{
    u8 attackerId;
    u16 moveId;
    u8 targetId;

    attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    if (attackerId != pokeId && typeId == BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE)) {
        moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
        if (BTL_SERVER_FLOW_CheckAllyMoveAutoHitById(flow, attackerId, pokeId, moveId) == 0 && BTL_ID_IsGemIgnoredMove(moveId) == 0) {
            targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
            if (BTL_EVENT_OverwriteVar(BTL_EVAR_DEFENDER_ID, pokeId) != 0 && targetId != pokeId)
                return 1;
        }
    }
    return 0;
}

/* Suction Cups: when the holder is the target, prevent the forced switch and show the message. */
void HAND_TOKUSEI_SuctionCups_BlockForcedSwitch(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExMessage *msg;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1) != 0) {
            msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_MESSAGE, pokeId);
            msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
            BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x1c6);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        }
    }
}

const BtlEventHandler *HAND_TOKUSEI_GetSuctionCupsHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSuctionCupsHandlers;
}

/* Liquid Ooze: when the holder is the target of a draining move, damage the attacker by the drained amount instead. */
void HAND_TOKUSEI_LiquidOoze_DamageAttacker(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u16 amount;
    HandExDamage *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        amount = BTL_EVENT_GetVar(BTL_EVAR_VOLUME);
        BTL_EVENT_OverwriteVar(BTL_EVAR_VOLUME, 0);
        if (amount != 0) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_DAMAGE, pokeId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->pokeId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
            cmd->amount = amount;
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, 2, 0x1c9);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, cmd->pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}

/* Liquid Ooze: remove the factor of the holder when the event that names the holder arrives. */
void HAND_TOKUSEI_LiquidOoze_RemoveFactorOnEventA3(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_MarkFactorDead(factor);
}

const BtlEventHandler *HAND_TOKUSEI_GetLiquidOozeHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gLiquidOozeHandlers;
}

/* Ability handlers: Klutz, Sticky Hold, Pressure. */
#define KLUTZ_EXEMPT_ITEM_COUNT 13

/* Klutz skip check: item factors of the holder are skipped, except the items in the exempt list. */
int HAND_TOKUSEI_Klutz_SkipCheck(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId)
{
    u32 i;

    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(context, ownerId), 0x10) != 0)
        return 0;
    if (factorType == 5 && ownerId == BTL_EVENT_GetFactorPokeId(other)) {
        for (i = 0; i < KLUTZ_EXEMPT_ITEM_COUNT; i++) {
            if (key == gKlutzExemptItemIds[i])
                return 0;
        }
        return 1;
    }
    return 0;
}

void HAND_TOKUSEI_Klutz_InstallSkipCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, KlutzWork *work)
{
    if (work->skipCheckSet == 0) {
        BTL_EVENT_SetFactorSkipCheck(factor, HAND_TOKUSEI_Klutz_SkipCheck);
        work->skipCheckSet = 1;
    }
}

void HAND_TOKUSEI_Klutz_InstallSkipCheckOnEntry(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, KlutzWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        HAND_TOKUSEI_Klutz_InstallSkipCheck(factor, flow, pokeId, work);
}

void HAND_TOKUSEI_Klutz_RemoveSkipCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_ClearFactorSkipCheck(factor);
}

/* Klutz: tell the server flow that the held item of the holder changed its effect. */
void HAND_TOKUSEI_Klutz_NoticeHeldItem(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExPokeNotice *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_POKE_NOTICE, pokeId);
        cmd->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}

/* Klutz: Natural Gift fails when the holder uses it. */
void HAND_TOKUSEI_Klutz_BlockNaturalGift(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, KlutzWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        unsigned short moveId = (unsigned short)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
        work->moveBlocked = 0;
        if (moveId == MOVE_NATURAL_GIFT && pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
            work->moveBlocked = BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_ITEM_UNUSABLE);
    }
}

/* Klutz: show the message for the blocked move. */
void HAND_TOKUSEI_Klutz_ShowBlockedMoveMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, KlutzWork *work)
{
    HandExMessage *msg;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && work->moveBlocked != 0) {
        BTL_EVENT_GetVar(BTL_EVAR_POKE_ID);
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_MESSAGE, pokeId);
        msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x389);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        work->moveBlocked = 0;
    }
}

const BtlEventHandler *HAND_TOKUSEI_GetKlutzHandlers(int *handlerCount)
{
    *handlerCount = 7;
    return gKlutzHandlers;
}

/* Sticky Hold: Trick and Switcheroo against the holder have no effect. */
void HAND_TOKUSEI_StickyHold_BlockTrick(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u16 moveId;
    HandExMessage *msg;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
        if (moveId == MOVE_TRICK || moveId == MOVE_SWITCHEROO) {
            if (BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1) != 0) {
                msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_MESSAGE, pokeId);
                msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
                BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0xd2);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
            }
        }
    }
}

/* Sticky Hold: block the removal of the item of the holder when another poke causes it. */
void HAND_TOKUSEI_StickyHold_BlockItemRemoval(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *messagePending)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(BTL_EVAR_SELF_CAUSED_FLAG) == 0)
        *messagePending = BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

void HAND_TOKUSEI_StickyHold_ShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *messagePending)
{
    HandExMessage *msg;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *messagePending != 0) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_MESSAGE, pokeId);
        msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x1ed);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        *messagePending = 0;
    }
}

const BtlEventHandler *HAND_TOKUSEI_GetStickyHoldHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gStickyHoldHandlers;
}

const BtlEventHandler *HAND_TOKUSEI_GetPressureHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gPressureHandlers;
}

/* Pressure: when the poke enters, show the ability window and the message. */
void HAND_TOKUSEI_Pressure_ShowAbilityMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExMessage *msg;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_TOKWIN_IN, pokeId);
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x1e7);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_TOKWIN_OUT, pokeId);
    }
}

static inline void overwriteVarU8(int key, u8 value)
{
    BTL_EVENT_OverwriteVar(key, value);
}

/* Pressure: a move of an opposing poke costs one more PP. */
void HAND_TOKUSEI_Pressure_AddPPCost(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    int extraCost;
    u16 moveId;

    if (BTL_MAIN_IsPokeSamePair((u8)BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID), pokeId) == 0) {
        extraCost = 0;
        if (HAND_COMMON_IsMoveTarget(pokeId) != 0) {
            extraCost = 1;
        } else {
            moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
            if (WAZA_TOOL_GetCategory(moveId) == 10)
                extraCost = 1;
            else if (BTL_ID_IsPressureNoExtraPpMove(moveId) != 0)
                extraCost = 1;
        }
        if (extraCost != 0)
            overwriteVarU8(BTL_EVAR_VOLUME, BTL_EVENT_GetVar(BTL_EVAR_VOLUME) + 1);
    }
}

/* Ability handlers: Magic Guard, Stench, Shadow Tag, Arena Trap, and the table getter of Magnet Pull. */
#define ABILITY_SHADOW_TAG 0x17

const BtlEventHandler *HAND_TOKUSEI_GetMagicGuardHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMagicGuardHandlers;
}

/* Magic Guard: when the holder is the target, clear the effect flag. */
void HAND_TOKUSEI_MagicGuard_ClearEffectFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 0);
}

const BtlEventHandler *HAND_TOKUSEI_GetStenchHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gStenchHandlers;
}

/* Stench: when the holder attacks and the move has no flinch chance of its own, give it the Stench chance. */
void HAND_TOKUSEI_Stench_SetFlinchChance(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && (unsigned char)BTL_EVENT_GetVar(BTL_EVAR_EFFECT_PERCENT_LOCKED) == 0)
        BTL_EVENT_OverwriteVar(BTL_EVAR_EFFECT_PERCENT, STENCH_FLINCH_CHANCE);
}

const BtlEventHandler *HAND_TOKUSEI_GetShadowTagHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gShadowTagHandlers;
}

/* Shadow Tag: opposing pokes cannot escape, unless one of them has Shadow Tag too. */
void HAND_TOKUSEI_ShadowTag_PreventEscape(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 opponentIds[OPPONENT_ID_BUFFER_SIZE];
    u32 opponentCount;
    u8 i;

    if (BTL_MAIN_IsPokeSamePair((u8)BTL_EVENT_GetVar(BTL_EVAR_POKE_ID), pokeId) == 0) {
        opponentCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, pokeId) | 0x100), opponentIds);
        for (i = 0; i < opponentCount; i++) {
            if (func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(flow, opponentIds[i]), BPP_VALUE_CURRENT_ABILITY) == ABILITY_SHADOW_TAG)
                return;
        }
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
    }
}

const BtlEventHandler *HAND_TOKUSEI_GetArenaTrapHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gArenaTrapHandlers;
}

/* Arena Trap: opposing pokes cannot escape while one of them passes the ground check. */
void HAND_TOKUSEI_ArenaTrap_PreventEscape(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 opponentIds[OPPONENT_ID_BUFFER_SIZE];
    u32 opponentCount;
    u8 i;

    if (BTL_MAIN_IsPokeSamePair((u8)BTL_EVENT_GetVar(BTL_EVAR_POKE_ID), pokeId) == 0) {
        opponentCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, pokeId) | 0x100), opponentIds);
        for (i = 0; i < opponentCount; i++) {
            if (BTL_SERVER_FLOW_IsPokeGroundedById(flow, opponentIds[i]) == 0) {
                BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
                return;
            }
        }
    }
}

const BtlEventHandler *HAND_TOKUSEI_GetMagnetPullHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMagnetPullHandlers;
}

/* Magnet Pull: a Steel-type Pokemon among the owner's targets cannot escape. */
void HAND_TOKUSEI_MagnetPull_BlockSteelEscape(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    u8 targetIds[4];
    u32 targetCount;
    u8 i;

    if (BTL_MAIN_IsPokeSamePair((u8)BTL_EVENT_GetVar(BTL_EVAR_POKE_ID), ownerId) == 0) {
        targetCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, ownerId) | 0x100), targetIds);
        for (i = 0; i < targetCount; i++) {
            if (BTL_POKEPARAM_HasType(BTL_SERVER_FLOW_GetPokeParam(flow, targetIds[i]), POKETYPE_STEEL) != 0)
                BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
        }
    }
}

int *HAND_TOKUSEI_GetUnburdenHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gUnburdenHandlers;
}

/* Unburden: remember that the owner is about to lose its held item. */
void HAND_TOKUSEI_Unburden_MarkItemLost(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(BTL_EVAR_SELF_CAUSED_FLAG) == 0
        && BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, ownerId)))
        *work = 1;
}

/* Unburden: once the item is gone, the speed of the owner doubles. */
void HAND_TOKUSEI_Unburden_DoubleSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *work == 1) {
        if (BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, ownerId)) == 0) {
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
        }
    }
}

int *HAND_TOKUSEI_GetPickupHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gPickupHandlers;
}

/* Pickup: an owner without an item takes a random item that a Pokemon around it used this turn. */
void HAND_TOKUSEI_Pickup_TakeUsedItem(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId)
{
    TokuseiPickupScratch *scratch;
    struct BtlPokeParam *candidate;
    BtlSetItemCmd *cmd;
    u32 posKey;
    u8 i;
    u8 holderCount;
    u8 selectedId;
    u16 itemId;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && !BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, ownerId))) {
        posKey = BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, ownerId);
        scratch = (TokuseiPickupScratch *)BTL_SERVER_FLOW_GetScratchBuffer(flow, sizeof(TokuseiPickupScratch));
        scratch->candidateCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(posKey | 0x200), scratch->candidateIds);
        holderCount = 0;
        scratch->spare = 0;
        for (i = 0; i < (u32)scratch->candidateCount; i++) {
            candidate = BTL_SERVER_FLOW_GetPokeParam(flow, scratch->candidateIds[i]);
            if (BTL_POKEPARAM_TestTurnFlag(candidate, BTL_TURN_FLAG_ITEM_USED) && BTL_POKEPARAM_GetConsumedItem(candidate)) {
                scratch->holderIds[holderCount++] = BTL_POKEPARAM_GetPokeId(candidate);
            }
        }
        if (holderCount) {
            selectedId = (scratch->candidateIds + (u8)BTL_CALC_Random(holderCount))[6];
            itemId = BTL_POKEPARAM_GetConsumedItem(BTL_SERVER_FLOW_GetPokeParam(flow, selectedId));
            if (itemId) {
                cmd = (BtlSetItemCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_SET_ITEM, ownerId);
                cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
                cmd->pokeId = ownerId;
                cmd->itemId = itemId;
                cmd->clearConsumed = 1;
                cmd->sourcePokeId = selectedId;
                BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_PICKUP);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, ownerId);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, itemId);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            }
        }
    }
}

void *HAND_TOKUSEI_GetPickpocketHandlers(int *handlerCount) { *handlerCount = 1; return gPickpocketHandlers; }

/* Pickpocket: when a contact move hits the owner, the owner takes the item of the attacker. */
void HAND_TOKUSEI_Pickpocket_StealOnContact(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    u8 attackerId;
    struct BtlPokeParam *owner;
    struct BtlPokeParam *attacker;
    BtlStealItemCmd *cmd;

    if (HAND_COMMON_IsMoveTarget(ownerId) != 0) {
        attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
        if (BTLV_CORE_CheckEitherSlotPair(flow, ownerId, attackerId) == 0
            && WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), BTL_WAZA_FLAG_CONTACT) != 0) {
            owner = BTL_SERVER_FLOW_GetPokeParam(flow, ownerId);
            attacker = BTL_SERVER_FLOW_GetPokeParam(flow, attackerId);
            if (BTL_POKEPARAM_GetItem(owner) == 0 && BTL_POKEPARAM_GetItem(attacker) != 0) {
                cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_STEAL_ITEM, ownerId);
                cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
                cmd->victimId = attackerId;
                BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_PICKPOCKET);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, attackerId);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, BTL_POKEPARAM_GetItem(attacker));
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            }
        }
    }
}

/*
 * Cursed Body: sometimes disables the move that hit the owner.
 * note:     BTLV_CORE_MakeSlotKind2 returns a one-word struct: its return temporary is
 *           the unreferenced third frame word and moves turns/moveId to r6/r7
 *           (an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md);
 *           the enum DisableTurns keeps turns + 1 out of constant folding.
 */
void HAND_TOKUSEI_CursedBody_DisableAttackerMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    u8 attackerId;
    u16 moveId;
    DisableTurns turns;
    struct BtlPokeParam *attacker;
    BtlAddSickCmd *cmd;

    turns = DISABLE_TURNS_BASE;
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)
        && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) == 0
        && BTL_SERVER_FLOW_CheckShowdownThunk(flow) == 0) {
        attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
        attacker = BTL_SERVER_FLOW_GetPokeParam(flow, attackerId);
        if (BTL_POKEPARAM_HasSick(attacker, BTL_SICK_DISABLE) == 0) {
            moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID_USED);
            if (moveId != 0 && moveId != BTL_MOVE_STRUGGLE && BTL_ID_IsMetronomeItemIgnoredMove(moveId) == 0
                && HAND_TOKUSEI_RollChanceOrFlag(flow, 30) != 0) {
                if (BTL_POKEPARAM_TestTurnFlag(attacker, BTL_TURN_FLAG_ACTED) != 0) {
                    turns = (DisableTurns)(u8)(turns + 1);
                }
                cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_SICK, ownerId);
                cmd->sickId = BTL_SICK_DISABLE;
                cmd->sickCont = BTLV_CORE_MakeSlotKind2(turns, moveId);
                cmd->targetId = attackerId;
                cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            }
        }
    }
}

/* Cursed Body handler table (one handler). */
int *HAND_TOKUSEI_GetCursedBodyHandlers(int *handlerCount) { *handlerCount = 1; return &gCursedBodyHandlers; }

/* Weak Armor: a physical hit lowers the defense of the owner and raises its speed. */
void HAND_TOKUSEI_WeakArmor_LowerDefenseRaiseSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u32 ownerId)
{
    BtlRankCmd *cmd;
    struct BtlPokeParam *owner;
    int canChange;
    if (ownerId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        return;
    }
    if (BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) != BTL_DAMAGE_TYPE_PHYSICAL) {
        return;
    }
    if (BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) != 0) {
        return;
    }
    owner = BTL_SERVER_FLOW_GetPokeParam(flow, ownerId);
    canChange = 0;
    if (func_021D5D14(owner, BTL_STAT_DEFENSE, -1) != 0 || func_021D5D14(owner, BTL_STAT_SPEED, 1) != 0) {
        canChange = 1;
    }
    if (canChange == 0) {
        return;
    }
    if (BTL_POKEPARAM_IsFainted(owner) != 0) {
        return;
    }
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, ownerId);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, ownerId);
    cmd->targetCount = 1;
    cmd->targets[0] = ownerId;
    cmd->showMessage = 1;
    cmd->statId = BTL_STAT_DEFENSE;
    cmd->amount = -1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, ownerId);
    cmd->targetCount = 1;
    cmd->targets[0] = ownerId;
    cmd->showMessage = 1;
    cmd->statId = BTL_STAT_SPEED;
    cmd->amount = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, ownerId);
}

int *HAND_TOKUSEI_GetWeakArmorHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWeakArmorHandlers;
}

/* Sheer Force: moves with an added effect hit 1.3 times harder. */
void HAND_TOKUSEI_SheerForce_BoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && HAND_TOKUSEI_SheerForce_IsBoostedMove(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)))
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_3);
}

/* Sheer Force: the added effect of such a move does not happen. */
void HAND_TOKUSEI_SheerForce_BlockAddedEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && HAND_TOKUSEI_SheerForce_IsBoostedMove(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

/* Sheer Force: the side effect that would follow the attack of the owner is prevented. */
void HAND_TOKUSEI_SheerForce_BlockAttackerSideEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

/* Sheer Force: marks such a move as having no added effect. */
void HAND_TOKUSEI_SheerForce_FlagNoAddedEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && HAND_TOKUSEI_SheerForce_IsBoostedMove(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)))
        BTL_EVENT_OverwriteVar(BTL_EVAR_ADDED_EFFECT_OFF_FLAG, 1);
}

int *HAND_TOKUSEI_GetSheerForceHandlers(int *handlerCount) { *handlerCount = 5; return &gSheerForceHandlers; }

/* True when Sheer Force boosts the move: it has an added effect that is not a self stat loss. */
int HAND_TOKUSEI_SheerForce_IsBoostedMove(u16 moveId)
{
    u32 category = WAZA_TOOL_GetCategory(moveId);
    if (WAZA_TOOL_GetParam(moveId, BTL_WAZA_PARAM_ADDED_EFFECT_RATE) != 0) {
        return 1;
    }
    switch (category) {
    case BTL_WAZA_CATEGORY_DAMAGE_PLUS_EFFECT:
        if (WAZA_TOOL_GetParam(moveId, BTL_WAZA_PARAM_ADDED_EFFECT_KIND) == 8) {
            return 0;
        }
    case BTL_WAZA_CATEGORY_DAMAGE_PLUS_SICK:
        return 1;
    case BTL_WAZA_CATEGORY_DAMAGE_PLUS_RANK: {
        u32 effectCount;
        u32 i;
        s32 amount;
        effectCount = WAZA_TOOL_GetRankEffectCount(moveId);
        for (i = 0; i < effectCount; i++) {
            WAZA_TOOL_GetRankEffect(moveId, i, &amount);
            if (amount < 0) {
                return 0;
            }
        }
        return 1;
    }
    default:
        if (moveId == BTL_MOVE_SECRET_POWER) {
            return 1;
        }
        return 0;
    }
}

/* Defiant: when an enemy lowers a stat of the owner, its attack rises by two stages. */
void HAND_TOKUSEI_Defiant_RaiseAttackOnStatDrop(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u32 ownerId)
{
    BtlRankCmd *cmd;
    u8 attackerId;
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)
        && (attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID), BTL_MAIN_IsPokeSamePair(ownerId, attackerId)) == 0
        && BTL_EVENT_GetVar(BTL_EVAR_VOLUME) < 0) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, ownerId);
        cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        cmd->statId = BTL_STAT_ATTACK;
        cmd->amount = 2;
        cmd->showMessage = 1;
        cmd->targetCount = 1;
        cmd->targets[0] = ownerId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}

int *HAND_TOKUSEI_GetDefiantHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gDefiantHandlers;
}

/* Defeatist: at half hit points or less, the power of the owner is halved. */
void HAND_TOKUSEI_Defeatist_HalvePowerAtLowHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    struct BtlPokeParam *owner;
    u32 hp;
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        owner = BTL_SERVER_FLOW_GetPokeParam(flow, ownerId);
        hp = func_021D59B4(owner, BTL_POKEPARAM_VALUE_HP);
        if (hp <= BTL_CALC_DivideMaxHp(owner, 2)) {
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_5);
        }
    }
}

int *HAND_TOKUSEI_GetDefeatistHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gDefeatistHandlers;
}

/* Multiscale: at full hit points, damage to the owner is halved. */
void HAND_TOKUSEI_Multiscale_HalveDamageAtFullHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_POKEPARAM_IsHpFull(BTL_SERVER_FLOW_GetPokeParam(flow, ownerId)))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_5);
}

int *HAND_TOKUSEI_GetMultiscaleHandlers(int *handlerCount) { *handlerCount = 1; return &gMultiscaleHandlers; }

/* Friend Guard: damage to an ally of the owner is reduced to three quarters. */
void HAND_TOKUSEI_FriendGuard_ReduceAllyDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, unsigned int ownerId)
{
    unsigned char defenderId;
    defenderId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
    if (defenderId != ownerId && BTL_MAIN_IsPokeSamePair(ownerId, defenderId))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_75);
}

int *HAND_TOKUSEI_GetFriendGuardHandlers(int *handlerCount) { *handlerCount = 1; return &gFriendGuardHandlers; }

/* Healer: sometimes cures the major status condition of an ally. */
void HAND_TOKUSEI_Healer_CureAllyStatus(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    u8 allyIds[4];
    u8 allyCount;
    u8 i;
    BtlCureSickCmd *cmd;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        allyCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(0x400 | BTL_SERVER_FLOW_GetPokeViewPos(flow, ownerId)), allyIds);
        for (i = 0; i < allyCount; i++) {
            if (allyIds[i] != ownerId) {
                if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(flow, allyIds[i])) && HAND_TOKUSEI_RollChanceOrFlag(flow, 30)) {
                    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_CURE_SICK, ownerId);
                    cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
                    cmd->flags |= BTL_CMD_FLAG_ABILITY_ON_ALLY;
                    cmd->showMessage = 1;
                    cmd->pokeId = allyIds[i];
                    cmd->sickIndex = BTL_CURE_ALL_MAJOR;
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
                }
            }
        }
    }
}

int *HAND_TOKUSEI_GetHealerHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gHealerHandlers;
}

/* Toxic Boost: while poisoned, the physical power of the owner is 1.5 times. */
void HAND_TOKUSEI_ToxicBoost_BoostPhysicalPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)
        && BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, ownerId), BTL_SICK_POISON) != 0
        && BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) == BTL_DAMAGE_TYPE_PHYSICAL) {
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_5);
    }
}

int *HAND_TOKUSEI_GetToxicBoostHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gToxicBoostHandlers;
}

/* Flare Boost: while burned, the special power of the owner is 1.5 times. */
void HAND_TOKUSEI_FlareBoost_BoostSpecialPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)
        && BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, ownerId), BTL_SICK_BURN) != 0
        && BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) == BTL_DAMAGE_TYPE_SPECIAL) {
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_5);
    }
}

int *HAND_TOKUSEI_GetFlareBoostHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gFlareBoostHandlers;
}

/* Telepathy: damaging moves of an ally do not hit the owner. */
void HAND_TOKUSEI_Telepathy_AvoidAllyAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u32 ownerId)
{
    BtlMessageCmd *cmd;
    u8 attackerId;
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
        if (BTL_MAIN_IsPokeSamePair(ownerId, attackerId) != 0
            && ownerId != attackerId
            && WAZA_TOOL_IsDamaging((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) != 0
            && BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1) != 0) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_MESSAGE, ownerId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_TELEPATHY_AVOID);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, ownerId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}

int *HAND_TOKUSEI_GetTelepathyHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gTelepathyHandlers;
}

/*
 * Moody: at the end of the turn one stat of the owner rises by two stages and another falls by one.
 * The pointer-sum form of the random pick preserves the load sequence of the candidate lists.
 * Signed byte storage of -1 preserves the subtraction from the live one.
 */
void HAND_TOKUSEI_Moody_RaiseAndLowerStat(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId)
{
    TokuseiMoodyScratch *scratch;
    struct BtlPokeParam *owner;
    u8 raisableCount;
    u8 lowerableCount;
    u32 i;
    u8 pairCount;
    u32 j;
    u8 raiseStat;
    u8 lowerStat;
    u16 pair;
    BtlRankCmd *cmd;
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        scratch = (TokuseiMoodyScratch *)BTL_SERVER_FLOW_GetScratchBuffer(flow, sizeof(TokuseiMoodyScratch));
        owner = BTL_SERVER_FLOW_GetPokeParam(flow, ownerId);
        lowerableCount = 0;
        raisableCount = 0;
        for (i = 0; i < BTL_STAT_COUNT_RANKED; i++) {
            if (func_021D5D14(owner, i + 1, 1)) scratch->raisableStats[raisableCount++] = i + 1;
            if (func_021D5D14(owner, i + 1, -1)) scratch->lowerableStats[lowerableCount++] = i + 1;
        }
        lowerStat = 0;
        raiseStat = 0;
        if (raisableCount == 0 && lowerableCount != 0) {
            lowerStat = (scratch->lowerableStats + BTL_CALC_Random(lowerableCount))[0];
        } else if (raisableCount != 0 && lowerableCount == 0) {
            raiseStat = (scratch->raisableStats + BTL_CALC_Random(raisableCount))[0];
        } else if (raisableCount != 0 && lowerableCount != 0) {
            pairCount = 0;
            for (i = 0; i < raisableCount; i++) {
                for (j = 0; j < lowerableCount; j++) {
                    if (scratch->raisableStats[i] != scratch->lowerableStats[j]) {
                        scratch->pairs[pairCount++] = (scratch->raisableStats[i] << 8) | scratch->lowerableStats[j];
                        if (pairCount >= 0x54) break;
                    }
                }
            }
            pair = scratch->pairs[BTL_CALC_Random(pairCount)];
            raiseStat = pair >> 8;
            lowerStat = pair;
        }
        BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, ownerId);
        if (raiseStat) {
            cmd = (BtlRankCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, ownerId);
            cmd->targetCount = 1;
            cmd->targets[0] = ownerId;
            cmd->statId = raiseStat;
            cmd->amount = 2;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
        if (lowerStat) {
            cmd = (BtlRankCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, ownerId);
            cmd->targetCount = 1;
            cmd->targets[0] = ownerId;
            cmd->statId = lowerStat;
            cmd->amount = -1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
        BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, ownerId);
    }
}

void *HAND_TOKUSEI_GetMoodyHandlers(int *handlerCount) { *handlerCount = 1; return gMoodyHandlers; }

/* Overcoat: weather damage to the owner is prevented. */
void HAND_TOKUSEI_Overcoat_BlockWeatherDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(BTL_EVAR_DAMAGE) > 0)
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

void *HAND_TOKUSEI_GetOvercoatHandlers(int *handlerCount) { *handlerCount = 1; return gOvercoatHandlers; }

/* Poison Touch: a contact move of the owner sometimes poisons the defender. */
void HAND_TOKUSEI_PoisonTouch_PoisonOnContact(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    BtlAddSickCmd *cmd;
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)
        && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) == 0
        && BTL_EVENT_GetVar(BTL_EVAR_EFFECT_BLOCKED_FLAG) == 0
        && WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), BTL_WAZA_FLAG_CONTACT) != 0
        && HAND_TOKUSEI_RollChanceOrFlag(flow, 30) != 0) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_SICK, ownerId);
        cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
        cmd->targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        cmd->sickId = BTL_SICK_POISON;
        cmd->sickCont = BTL_CALC_MakeDefaultSickCont(BTL_SICK_POISON);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_POISON_TOUCH);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, cmd->targetId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}

void *HAND_TOKUSEI_GetPoisonTouchHandlers(unsigned int *packedInfo)
{
    *packedInfo = HAND_TOKUSEI_PackAbilityHandlerInfo(4, 1);
    return gPoisonTouchHandlers;
}

/*
 * Regenerator: when the owner leaves the field, it recovers a third of its
 * hit points (at most what it lacks). Two live calls with no free saved
 * register put the first result on the stack.
 */
void HAND_TOKUSEI_Regenerator_RecoverOnSwitchOut(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    struct BtlPokeParam *owner;
    u32 recoverAmount, missingHp;
    BtlRegenerateHpCmd *cmd;

    if (ownerId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    owner = BTL_SERVER_FLOW_GetPokeParam(flow, ownerId);
    if (BTL_POKEPARAM_IsFainted(owner) != 0)
        return;
    if (BTL_POKEPARAM_IsHpFull(owner) != 0)
        return;
    recoverAmount = BTL_CALC_DivideMaxHpMin1(owner, 3);
    missingHp = func_021D59B4(owner, BTL_POKEPARAM_VALUE_MAX_HP) - func_021D59B4(owner, BTL_POKEPARAM_VALUE_HP);
    if (recoverAmount > missingHp)
        recoverAmount = missingHp;
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_REGENERATE_HP, ownerId);
    cmd->pokeId = ownerId;
    cmd->amount = recoverAmount;
    cmd->mode = 1;
    cmd->showBar = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}

int *HAND_TOKUSEI_GetRegeneratorHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRegeneratorHandlers;
}

int *HAND_TOKUSEI_GetIndirectGuardCause2Handlers(int *handlerCount)
{
    *handlerCount = 2;
    return gIndirectGuardCause2Handlers;
}

/* Indirect damage guard of cause 2: blocks the damage (same family as cause 1, 6 and 8). */
void HAND_TOKUSEI_IndirectGuardCause2_Block(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work)
{
    HAND_TOKUSEI_BlockIndirectDamage(flow, ownerId, work, 0x2);
}

/* Indirect damage guard of cause 2: shows its message. */
void HAND_TOKUSEI_IndirectGuardCause2_ShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work)
{
    HAND_TOKUSEI_ShowIndirectGuardMessage(flow, ownerId, work, 0xcc);
}

int *HAND_TOKUSEI_GetSandRushHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gSandRushHandlers;
}

/* Sand Rush: in a sandstorm the speed of the owner doubles. */
void HAND_TOKUSEI_SandRush_DoubleSpeedInSand(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_SAND)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
}

void *HAND_TOKUSEI_GetWonderSkinHandlers(int *handlerCount) { *handlerCount = 1; return gWonderSkinHandlers; }

/* Wonder Skin: the accuracy of a status move against the owner is at most 50. */
void HAND_TOKUSEI_WonderSkin_CapStatusMoveAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)
        && BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) == BTL_DAMAGE_TYPE_STATUS
        && (unsigned int)BTL_EVENT_GetVar(BTL_EVAR_ACCURACY) > 50)
        BTL_EVENT_OverwriteVar(BTL_EVAR_ACCURACY, 50);
}

void *HAND_TOKUSEI_GetAnalyticHandlers(int *handlerCount) { *handlerCount = 1; return gAnalyticHandlers; }

/* Analytic: when every other Pokemon has already moved, the power of the owner is 1.3 times. */
void HAND_TOKUSEI_Analytic_BoostPowerWhenMovingLast(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)
        && BTL_ID_IsMetronomeItemIgnoredMove(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == 0
        && HAND_COMMON_IsLastToAct(flow, ownerId) != 0)
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_3);
}

BtlEventHandler *HAND_TOKUSEI_GetSandForceHandlers(u32 *handlerCount) { *handlerCount = 2; return gSandForceHandlers; }

/* Sand Force: while the owner attacks in a sandstorm, Ground, Rock and Steel moves get 1.3 times power. */
void HAND_TOKUSEI_SandForceBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work)
{
    u8 moveType;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_SAND) {
        moveType = BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
        if (moveType == POKETYPE_GROUND || moveType == POKETYPE_ROCK || moveType == POKETYPE_STEEL)
            BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_3);
    }
}

/* Zen Mode: a Darmanitan at half HP or less takes the Zen form; above half it takes the base form. */
void HAND_TOKUSEI_ZenModeUpdateForm(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work)
{
    struct BtlPokeParam *bpp;
    u8 wantZenForm;
    BtlFormChangeCmd *cmd;

    bpp = BTL_SERVER_FLOW_GetPokeParam(flow, ownerId);
    if (BTL_POKEPARAM_GetSpecies(bpp) == SPECIES_DARMANITAN) {
        wantZenForm = (func_021D59B4(bpp, BTL_BPP_VALUE_HP) <= BTL_CALC_DivideMaxHp(bpp, 2));
        if (wantZenForm != func_021D59B4(bpp, BTL_BPP_VALUE_FORM)) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_FORM_CHANGE, ownerId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->pokeId = ownerId;
            cmd->form = wantZenForm;
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_ABILITY_LINE, (u16)(wantZenForm == 1 ? BTL_STR_ZEN_MODE_ON : BTL_STR_ZEN_MODE_OFF));
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}

/* Zen Mode: when the Darmanitan leaves or loses the ability, it returns to the base form. */
void HAND_TOKUSEI_ZenModeRevertForm(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work)
{
    BtlFormChangeCmd *cmd;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam(flow, ownerId)) == SPECIES_DARMANITAN) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_FORM_CHANGE, ownerId);
            cmd->pokeId = ownerId;
            cmd->form = 0;
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_ABILITY_LINE, BTL_STR_ZEN_MODE_OFF);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, ownerId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}

BtlEventHandler *HAND_TOKUSEI_GetZenModeHandlers(u32 *handlerCount)
{
    *handlerCount = 3;
    return gZenModeHandlers;
}

/*
 * Infiltrator skip check: skips the screen-type side conditions that belong to
 * the other side than the Infiltrator's owner.
 */
int HAND_TOKUSEI_InfiltratorSkipSideCondition(struct BtlEventFactor *factor, void *context, int targetFactorType, int eventId, u16 targetKey, u8 targetOwnerId)
{
    u8 ownSide;

    if (targetFactorType == BTL_EVENT_TYPE_SIDE_CONDITION) {
        ownSide = BTL_MAIN_IsPokeIdInSecondPair(BTL_EVENT_GetFactorPokeId(factor));
        if (ownSide != targetOwnerId && targetKey <= BTL_SIDE_CONDITION_SCREEN_KEY_MAX)
            return 1;
    }
    return 0;
}

/* Infiltrator: while the owner attacks, install the skip check on its factor. */
void HAND_TOKUSEI_InfiltratorEnableSkip(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_SetFactorSkipCheck(factor, HAND_TOKUSEI_InfiltratorSkipSideCondition);
}

/* Infiltrator: when the owner's attack ends, remove the skip check again. */
void HAND_TOKUSEI_InfiltratorDisableSkip(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_ClearFactorSkipCheck(factor);
}

BtlEventHandler *HAND_TOKUSEI_GetInfiltratorHandlers(u32 *handlerCount)
{
    *handlerCount = 2;
    return gInfiltratorHandlers;
}

BtlEventHandler *HAND_TOKUSEI_GetMoxieHandlers(u32 *handlerCount)
{
    *handlerCount = 1;
    return gMoxieHandlers;
}

/* Moxie: the owner raises its Attack by one rank for each defender it knocked out. */
void HAND_TOKUSEI_MoxieRaiseAttackOnKnockOut(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work)
{
    u32 defenderCount;
    u32 i;
    BtlRankCmd *cmd;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        defenderCount = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_COUNT);
        for (i = 0; i < defenderCount; i++) {
            if (BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(i + BTL_EVAR_DEFENDER_FIRST))) != 0) {
                cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_CHANGE, ownerId);
                cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
                cmd->targetCount = 1;
                cmd->targets[0] = ownerId;
                cmd->statId = BTL_RANK_STAT_ATTACK;
                cmd->amount = 1;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            }
        }
    }
}

BtlEventHandler *HAND_TOKUSEI_GetJustifiedHandlers(u32 *handlerCount)
{
    *handlerCount = 1;
    return gJustifiedHandlers;
}

/* Justified: when a Dark move hits the owner, it raises its Attack by one rank. */
void HAND_TOKUSEI_JustifiedRaiseAttackOnDarkHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work)
{
    BtlRankCmd *cmd;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) == 0 && BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == POKETYPE_DARK) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_CHANGE, ownerId);
        cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        cmd->targetCount = 1;
        cmd->targets[0] = ownerId;
        cmd->statId = BTL_RANK_STAT_ATTACK;
        cmd->amount = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}

BtlEventHandler *HAND_TOKUSEI_GetRattledHandlers(u32 *handlerCount)
{
    *handlerCount = 1;
    return gRattledHandlers;
}

/* Rattled: when a Bug, Ghost or Dark move hits the owner, it raises its Speed by one rank. */
void HAND_TOKUSEI_RattledRaiseSpeedOnHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work)
{
    BtlRankCmd *cmd;
    u8 moveType;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) == 0) {
        moveType = BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
        if (moveType == POKETYPE_DARK || moveType == POKETYPE_BUG || moveType == POKETYPE_GHOST) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_CHANGE, ownerId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->targetCount = 1;
            cmd->targets[0] = ownerId;
            cmd->statId = BTL_RANK_STAT_SPEED;
            cmd->amount = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}

BtlEventHandler *HAND_TOKUSEI_GetMummyHandlers(u32 *handlerCount)
{
    *handlerCount = 1;
    return gMummyHandlers;
}

/*
 * Mummy: when a contact move hits the owner, the attacker's ability becomes
 * Mummy, unless it already is Mummy or one side has no Pokemon left.
 */
void HAND_TOKUSEI_MummySpreadAbility(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work)
{
    BtlAbilityChangeCmd *cmd;
    u8 attackerId;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) == 0 && BTL_SERVER_FLOW_CheckShowdownThunk(flow) == 0
        && WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), WAZA_FLAG_CONTACT) != 0) {
        attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
        if (func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(flow, attackerId), BTL_BPP_VALUE_ABILITY) != ABILITY_MUMMY) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ABILITY_CHANGE, ownerId);
            cmd->abilityId = ABILITY_MUMMY;
            cmd->pokeId = attackerId;
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_WITH_POKE_NAME, BTL_STR_MUMMY_SPREAD);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, cmd->pokeId);
            if (BTL_MAIN_IsPokeSamePair(ownerId, attackerId) == 0)
                cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}

/* Sap Sipper: a Grass move aimed at the owner is absorbed and raises its Attack by one rank. */
void HAND_TOKUSEI_SapSipperAbsorbGrass(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(flow, ownerId, POKETYPE_GRASS))
        HAND_TOKUSEI_AbsorbRaiseStat(flow, ownerId, BTL_RANK_STAT_ATTACK, 1);
}

BtlEventHandler *HAND_TOKUSEI_GetSapSipperHandlers(u32 *handlerCount) { *handlerCount = 1; return gSapSipperHandlers; }

/* Prankster: the owner's status moves get one priority step. */
void HAND_TOKUSEI_PranksterRaiseStatusPriority(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work)
{
    u8 priority;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_STATUS) {
        priority = BTL_EVENT_GetVar(BTL_EVAR_MOVE_PRIORITY);
        BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_PRIORITY, priority + 1);
    }
}

BtlEventHandler *HAND_TOKUSEI_GetPranksterHandlers(u32 *handlerCount)
{
    *handlerCount = 1;
    return gPranksterHandlers;
}

/* Magic Bounce: the first of its two handlers is the one that Magic Coat uses to reflect a status move. */
void HAND_TOKUSEI_MagicBounceReflectMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work)
{
    BTLV_CORE_EventRedirectMove(factor, flow, ownerId, work);
}

/* Magic Bounce: the second handler is the one that Magic Coat uses to counter a status move aimed at the owner. */
void HAND_TOKUSEI_MagicBounceCounterMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId, void *work)
{
    BTLV_CORE_EventCounterMove(factor, flow, ownerId, work);
}

/* Magic Bounce: reflect the incoming move and show the ability window. */
void HAND_TOKUSEI_MagicBounceReflectMoveWithWindow(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 1) != 0) {
        BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_KIND_ABILITY_WINDOW_IN, pokeId);
        BTLV_CORE_EventQueueMoveNotice(factor, flow, pokeId, work);
        BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_KIND_ABILITY_WINDOW_OUT, pokeId);
    }
}

const BtlEventHandlerEntry *HAND_TOKUSEI_AddMagicBounce(int *count)
{
    *count = 3;
    return gMagicBounceHandlers;
}

/* Harvest: give back the consumed Berry when the Pokemon holds nothing (always in sun, else 50%). */
void HAND_TOKUSEI_HarvestRestoreBerry(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExSetItem *rec;
    struct BtlPokeParam *poke;
    u32 itemId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        itemId = BTL_POKEPARAM_GetConsumedItem(poke);
        if (itemId != 0 && ITEM_IsBerry(itemId) != 0 && BTL_POKEPARAM_GetItem(poke) == 0
            && (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_SUN || HAND_TOKUSEI_RollChanceOrFlag(flow, 50) != 0)) {
            rec = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_ITEM, pokeId);
            rec->header |= HANDEX_FLAG_SHOW_ABILITY;
            rec->itemId = itemId;
            rec->pokeId = pokeId;
            rec->announce = 1;
            BTL_SERVER_FLOW_InitMsgRecord(&rec->message, HANDEX_STR_SET, 0x1db);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->message, pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->message, itemId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, rec);
        }
    }
}

const BtlEventHandlerEntry *HAND_TOKUSEI_AddHarvest(int *count)
{
    *count = 1;
    return gHarvestHandlers;
}

const BtlEventHandlerEntry *HAND_TOKUSEI_AddHeavyMetal(int *count)
{
    *count = 1;
    return gHeavyMetalHandlers;
}

/* Heavy Metal: double the weight. */
void HAND_TOKUSEI_HeavyMetalDoubleWeight(int factor, int flow, int pokeId) { if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_DOUBLE); }

const BtlEventHandlerEntry *HAND_TOKUSEI_AddLightMetal(int *count) { *count = 1; return gLightMetalHandlers; }

/*
 * Light Metal: halve the weight.
 * extent: trailing two-byte zero alignment at 021DCC2A.
 */
void HAND_TOKUSEI_LightMetalHalveWeight(int factor, int flow, int pokeId) { if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_HALF); }

/* Contrary: invert the stat change. */
void HAND_TOKUSEI_ContraryInvertStatChange(int factor, int flow, int pokeId, int *work) { if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) *work = BTL_EVENT_OverwriteVar(BTL_EVAR_VOLUME,-BTL_EVENT_GetVar(BTL_EVAR_VOLUME)); }

const BtlEventHandlerEntry *HAND_TOKUSEI_AddContrary(int *count) { *count = 1; return gContraryHandlers; }

/* Unnerve, when its owner enters. */
void HAND_TOKUSEI_UnnerveOnOwnerEnter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, UnnerveWork *work) { if(pokeId==BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) HAND_TOKUSEI_UnnerveAnnounce(factor,flow,pokeId,work); }

/* Unnerve: show the ability window once and install the Berry skip check. */
void HAND_TOKUSEI_UnnerveAnnounce(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, UnnerveWork *work)
{
    HandExMessage *rec;
    u32 side;

    if (work->announced == 0) {
        side = BTL_MAIN_IsZero(BTL_MAIN_IsPokeIdInSecondPair(pokeId));
        BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_KIND_ABILITY_WINDOW_IN, pokeId);
        rec = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&rec->message, HANDEX_STR_STANDARD, 0xb0);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->message, side);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rec);
        BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_KIND_ABILITY_WINDOW_OUT, pokeId);
        BTL_EVENT_SetFactorSkipCheck(factor, HAND_TOKUSEI_UnnerveSkipBerry);
        work->announced = 1;
    }
}

/*
 * Unnerve skip check: a Berry held by a Pokemon of the other side is skipped.
 * extent: callback followed by store-and-return leaf at 021DCD14.
 * stack: the last two arguments sit in stack slots; the body reads the
 * halfword at +0 and the byte at +4 using a common stack base.
 */
int HAND_TOKUSEI_UnnerveSkipBerry(struct BtlEventFactor *factor, void *context, int targetFactorType, int eventId, u16 targetKey, u8 targetOwnerId)
{
    if(targetFactorType==BTL_EVENT_TYPE_ITEM) {
        if(!BTL_MAIN_IsPokeSamePair(BTL_EVENT_GetFactorPokeId(factor),targetOwnerId)) {
            if(ITEM_IsBerry(targetKey)) return 1;
        }
    }
    return 0;
}

const BtlEventHandlerEntry *HAND_TOKUSEI_AddUnnerve(int *count) { *count=3; return gUnnerveHandlers; }

/* Imposter: transform into the Pokemon facing the owner, unless one of the two has fainted. */
void HAND_TOKUSEI_ImposterTransform(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExTransform *rec;
    struct BtlPokeParam *targetPoke;
    int targetId;
    int position;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        position = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
        targetId = BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(flow, BTL_MAIN_GetFacingPos(BTL_SERVER_FLOW_GetRule(flow), position));
        targetPoke = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        if (BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) == 0 && BTL_POKEPARAM_IsFainted(targetPoke) == 0) {
            rec = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_TRANSFORM, pokeId);
            rec->header |= HANDEX_FLAG_SHOW_ABILITY;
            rec->targetId = targetId;
            BTL_SERVER_FLOW_InitMsgRecord(&rec->message, HANDEX_STR_SET, 0x284);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->message, pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->message, rec->targetId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, rec);
        }
    }
}

const BtlEventHandlerEntry *HAND_TOKUSEI_AddImposter(int *count)
{
    *count = 1;
    return gImposterHandlers;
}

const BtlEventHandlerEntry *HAND_TOKUSEI_AddIllusion(int *count)
{
    *count = 3;
    return gIllusionHandlers;
}

/* Illusion: the disguise ends when the owner is hit (not through a substitute). */
void HAND_TOKUSEI_IllusionBreakOnHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId) { if(pokeId==BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG)==0) HAND_TOKUSEI_IllusionBreak(factor,flow,pokeId); }

/* Illusion: the disguise ends on another event about the owner. */
void HAND_TOKUSEI_IllusionBreakOnOwnerEvent(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId) { if(pokeId==BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) HAND_TOKUSEI_IllusionBreak(factor,flow,pokeId); }

/* Illusion: the disguise ends when the owner's ability changes to another ability. */
void HAND_TOKUSEI_IllusionBreakOnAbilityChange(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId) { int newAbilityId; newAbilityId=BTL_EVENT_GetVar(BTL_EVAR_NEW_ABILITY_ID); if(newAbilityId!=BTL_EVENT_GetFactorKey(factor) && pokeId==BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) HAND_TOKUSEI_IllusionBreak(factor,flow,pokeId); }

/* Illusion: drop the disguise when it is active. */
void HAND_TOKUSEI_IllusionBreak(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExEndIllusion *rec;
    if (BTL_POKEPARAM_IsIllusionActive(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))) {
        rec = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_END_ILLUSION, pokeId);
        rec->pokeId = pokeId;
        BTL_SERVER_FLOW_InitMsgRecord(&rec->message, HANDEX_STR_SET, 478);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rec);
    }
}

const BtlEventHandlerEntry *HAND_TOKUSEI_AddVictoryStar(int *count)
{
    *count = 1;
    return gVictoryStarHandlers;
}

/*
 * Victory Star: raise the accuracy of the owner's side by 10%.
 * lever: u8 result local reproduces 021DCEA6/021DCEA8 truncation in r0,
 * then shift-copy to r1; inline narrowing produced an extra register copy.
 */
void HAND_TOKUSEI_VictoryStarBoostAccuracy(int factor, int flow, unsigned int pokeId) { unsigned char attackerId; attackerId=BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID); if(BTL_MAIN_IsPokeSamePair(pokeId,attackerId)) BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO,BTL_RATIO_ACCURACY_BOOST); }

/* Add the event factor of an item to the factor list; 0 if the item has no handler. */
struct BtlEventFactor *HAND_ITEM_AddFactor(struct BtlPokeParam *poke, u32 itemId)
{
    u32 i;
    u16 speed;
    u8 ownerId;
    u32 handlerTable;
    u32 handlerCount;

    for (i = 0; i < ITEM_HANDLER_COUNT; i++) {
        if (itemId == gItemHandlerRegistry[i].itemId) {
            speed = func_021D58A8(poke, 0xc);
            ownerId = BTL_POKEPARAM_GetPokeId(poke);
            handlerTable = gItemHandlerRegistry[i].getHandlers(&handlerCount);
            return BTL_EVENT_AddFactor(BTL_EVENT_TYPE_ITEM, itemId, 6, speed, ownerId, (BtlEventHandler *)handlerTable, handlerCount);
        }
    }
    return 0;
}

/* Remove the item factors of a Pokemon, except those that were added from outside. */
void HAND_ITEM_RemoveUnforcedFactors(struct BtlPokeParam *poke)
{
    struct BtlEventFactor *factor = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_ITEM, BTL_POKEPARAM_GetPokeId(poke));
    while (factor != 0) {
        struct BtlEventFactor *next = BTL_EVENT_FindNextFactor(factor);
        if (BTL_EVENT_GetFactorWork(factor, ITEM_WORK_FORCED_USE) == 0)
            BTL_EVENT_RemoveFactor(factor);
        factor = next;
    }
}

/*
 * Add the factor of the held item.
 * interface: 021D5B40's u16 field result is kept as a full register value
 * until the explicit halfword truncation at 021DCF68/021DCF6C; the caller
 * therefore uses a wide result and a u16 021DCEC4 argument, as the listing shows.
 */
struct BtlEventFactor *HAND_ITEM_AddHeldItemFactor(struct BtlPokeParam *poke) { int heldItem; heldItem=BTL_POKEPARAM_GetItem(poke); if(heldItem) return HAND_ITEM_AddFactor(poke,(unsigned short)heldItem); return 0; }

/* Add the factor of an item from outside (not held) and mark it as forced. */
struct BtlEventFactor *HAND_ITEM_AddForcedFactor(struct BtlPokeParam *poke, unsigned int itemId) { struct BtlEventFactor *factor; if(itemId) { factor=HAND_ITEM_AddFactor(poke,itemId); if(factor) { BTL_EVENT_EnableFactorSpecialEvent(factor); BTL_EVENT_SetFactorWork(factor,ITEM_WORK_FORCED_USE,1); return factor; } } return 0; }

/*
 * Remove one item factor.
 * tail-call thunk to BTL_EVENT_RemoveFactor
 */
void HAND_ITEM_RemoveFactor(struct BtlEventFactor *factor)
{
    BTL_EVENT_RemoveFactor(factor);
}

/* Switch off the item factors of a Pokemon. */
void HAND_ITEM_DisablePokeFactors(struct BtlPokeParam *poke) { BTL_EVENT_DisablePokeFactors(BTL_POKEPARAM_GetPokeId(poke),BTL_EVENT_TYPE_ITEM); }

/* Switch the item factors of a Pokemon on again; add the held item's factor when there is none. */
void HAND_ITEM_EnablePokeFactors(struct BtlPokeParam *poke) { if(!BTL_EVENT_EnablePokeFactors(BTL_POKEPARAM_GetPokeId(poke),BTL_EVENT_TYPE_ITEM)) HAND_ITEM_AddHeldItemFactor(poke); }

/*
 * An item chance succeeds when the percent roll passes or the battle rule says so.
 * interface: 021C82B8 forwards r1=2 unchanged to 021B911C; r0 is consumed
 * after the call at 021DCFEA, requiring a result despite its legacy void extern.
 */
int HAND_ITEM_RollChance(struct BtlServerFlow *flow, unsigned int percent) { if(BTL_CALC_RollPercent(percent)) return 1; if(BTL_SERVER_FLOW_QueryMainFlag(flow,2)) return 1; return 0; }

/*
 * Parameter of the item behind an event factor.
 * 021DCFF8  pass-through: second callee takes the first one's result
 * Leaf with no calls and no pool; 6 instructions, 16 bytes: push {r4, lr}; adds r4, r1, #0; bl BTL_EVENT_GetFactorKey; adds r1, r4, #0; bl BTL_CALC_GetMonParamWithHeap; pop {r4, pc}.
 */
int HAND_ITEM_GetParam(struct BtlEventFactor *factor, int paramIndex)
{
    return BTL_CALC_GetMonParamWithHeap(BTL_EVENT_GetFactorKey(factor), paramIndex);
}

/* Boost ratio (4096 = 1.0) of an item whose parameter 2 is a percent bonus. */
int HAND_ITEM_GetBoostRatio(struct BtlEventFactor *factor) { int percent; float ratio; percent=HAND_ITEM_GetParam(factor,2)+100; if(percent>0) ratio=0.5f+(float)(percent<<12); else ratio=(float)(percent<<12)-0.5f; return (int)ratio/100; }

/* Mark the item as used and ask the flow to show it. */
void HAND_ITEM_PushUseItem(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BTL_EVENT_KeepFactorRunning(factor);
    BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_KIND_USE_ITEM, pokeId);
}

/* Cheri Berry (cures paralysis). */
void HAND_ITEM_CheriBerryOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnTrigger(factor, flow, pokeId, BTL_SICK_PARALYSIS);
}

void HAND_ITEM_CheriBerryOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnEaten(factor, flow, pokeId, BTL_SICK_PARALYSIS);
}

const BtlEventHandlerEntry *HAND_ITEM_AddCheriBerry(int *count)
{
    *count = 5;
    return gCheriBerryHandlers;
}

/* Chesto Berry (cures sleep). */
void HAND_ITEM_ChestoBerryOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnTrigger(factor, flow, pokeId, BTL_SICK_SLEEP);
}

void HAND_ITEM_ChestoBerryOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnEaten(factor, flow, pokeId, BTL_SICK_SLEEP);
}

const BtlEventHandlerEntry *HAND_ITEM_AddChestoBerry(int *count)
{
    *count = 5;
    return gChestoBerryHandlers;
}

/* Rawst Berry (cures burn). */
void HAND_ITEM_RawstBerryOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnTrigger(factor, flow, pokeId, BTL_SICK_BURN);
}

void HAND_ITEM_RawstBerryOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnEaten(factor, flow, pokeId, BTL_SICK_BURN);
}

const BtlEventHandlerEntry *HAND_ITEM_AddRawstBerry(int *count)
{
    *count = 5;
    return gRawstBerryHandlers;
}

/* Aspear Berry (cures freeze). */
void HAND_ITEM_AspearBerryOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnTrigger(factor, flow, pokeId, BTL_SICK_FREEZE);
}

void HAND_ITEM_AspearBerryOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnEaten(factor, flow, pokeId, BTL_SICK_FREEZE);
}

const BtlEventHandlerEntry *HAND_ITEM_AddAspearBerry(int *count)
{
    *count = 5;
    return gAspearBerryHandlers;
}

/* Persim Berry (cures confusion). */
void HAND_ITEM_PersimBerryOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnTrigger(factor, flow, pokeId, BTL_SICK_CONFUSION);
}

void HAND_ITEM_PersimBerryOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnEaten(factor, flow, pokeId, BTL_SICK_CONFUSION);
}

const BtlEventHandlerEntry *HAND_ITEM_AddPersimBerry(int *count)
{
    *count = 5;
    return gPersimBerryHandlers;
}

/* Pecha Berry (cures poison). */
void HAND_ITEM_PechaBerryOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnTrigger(factor, flow, pokeId, BTL_SICK_POISON);
}

void HAND_ITEM_PechaBerryOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnEaten(factor, flow, pokeId, BTL_SICK_POISON);
}

const BtlEventHandlerEntry *HAND_ITEM_AddPechaBerry(int *count)
{
    *count = 5;
    return gPechaBerryHandlers;
}

/* Lum Berry (cures any status). */
void HAND_ITEM_LumBerryOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnTrigger(factor, flow, pokeId, BTL_SICK_ANY);
}

void HAND_ITEM_LumBerryOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnEaten(factor, flow, pokeId, BTL_SICK_ANY);
}

const BtlEventHandlerEntry *HAND_ITEM_AddLumBerry(int *count)
{
    *count = 5;
    return gLumBerryHandlers;
}

/* Status berry used on its own: cure the status when the trigger kind allows it. */
void HAND_ITEM_CureSickOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int sickKind)
{
    int triggerKind;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_EVENT_TryGetVar(BTL_EVAR_TRIGGER_KIND, &triggerKind) == 0 || triggerKind == 3 || triggerKind == 0) {
            if (HAND_ITEM_CheckHasSick(flow, pokeId, sickKind) != 0)
                HAND_ITEM_PushUseItem(factor, flow, pokeId);
        }
    }
}

/* Status berry eaten through another move: cure the status. */
void HAND_ITEM_CureSickOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int sickKind)
{
    HandExCureSick *rec;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && HAND_ITEM_CheckHasSick(flow, pokeId, sickKind)) {
        rec = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
        rec->sickKind = sickKind;
        rec->pokeCount = 1;
        rec->pokeIds[0] = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rec);
    }
}

/* Does the Pokemon have the status condition that the berry cures? */
int HAND_ITEM_CheckHasSick(struct BtlServerFlow *flow, int pokeId, int sickKind)
{
    struct BtlPokeParam *poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    switch (sickKind) {
    case BTL_SICK_ANY:
        if (BTL_POKEPARAM_GetMajorStatusIndex(poke) == 0 && BTL_POKEPARAM_HasSick(poke, BTL_SICK_CONFUSION) == 0)
            break;
        return 1;
    case BTL_SICK_ANY_MAJOR:
        if (BTL_POKEPARAM_GetMajorStatusIndex(poke) != 0)
            return 1;
        return 0;
    case BTL_SICK_ANY_VOLATILE:
        if (BTL_CALC_FindMajorSick(poke) != 0)
            return 1;
        return 0;
    default:
        return BTL_POKEPARAM_HasSick(poke, sickKind);
    }
    return 0;
}

const BtlEventHandlerEntry *HAND_ITEM_AddLeppaBerry(int *count)
{
    *count = 7;
    return gLeppaBerryHandlers;
}

/* Leppa Berry: use it when the last used move is out of PP. */
void HAND_ITEM_LeppaBerryOnLastMoveEmpty(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (HAND_ITEM_FindLastMoveEmptySlot(flow, pokeId) != BTL_MOVE_SLOT_NONE)
            HAND_ITEM_PushUseItem(factor, flow, pokeId);
    }
}

/* Leppa Berry: use it when any move is out of PP (checked for the trigger kinds 0 and 2). */
void HAND_ITEM_LeppaBerryOnAnyMoveEmptyChecked(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    int triggerKind;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        triggerKind = BTL_EVENT_GetVar(BTL_EVAR_TRIGGER_KIND);
        if (triggerKind != 2 && triggerKind != 0) return;
        if (HAND_ITEM_FindEmptyMoveSlot(flow, pokeId) != BTL_MOVE_SLOT_NONE)
            HAND_ITEM_PushUseItem(factor, flow, pokeId);
    }
}

/* Leppa Berry: use it when any move is out of PP. */
void HAND_ITEM_LeppaBerryOnAnyMoveEmpty(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (HAND_ITEM_FindEmptyMoveSlot(flow, pokeId) != BTL_MOVE_SLOT_NONE)
            HAND_ITEM_PushUseItem(factor, flow, pokeId);
    }
}

/* Leppa Berry: claim the trigger when the last used move is out of PP. */
void HAND_ITEM_LeppaBerryClaimTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && HAND_ITEM_FindLastMoveEmptySlot(flow, pokeId) != BTL_MOVE_SLOT_NONE)
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 1);
}

/*
 * Leppa Berry eaten through another move: restore the PP of an empty move.
 * extent: trailing two-byte alignment padding.
 * prototype: third DD39C input widened to full register width; no truncation at call.
 */
void HAND_ITEM_LeppaBerryOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) HAND_ITEM_PushRecoverPp(factor, flow, pokeId, work, 0);
}

/*
 * Leppa Berry used from outside: restore the PP of an empty move, or of a move that lost PP.
 * extent: trailing two-byte alignment padding.
 */
void HAND_ITEM_LeppaBerryOnForcedUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) HAND_ITEM_PushRecoverPp(factor, flow, pokeId, work, 1);
}

/*
 * Slot of the last used move when it is out of PP, else the none value.
 * extent: trailing two-byte alignment padding.
 * prototype: C7CF4 result used and r1 supplied; 5584 index is the u8 return of 5778.
 */
u8 HAND_ITEM_FindLastMoveEmptySlot(struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *poke;
    u8 slot;
    poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    slot = BTL_POKEPARAM_FindMoveSlot(poke, BTL_POKEPARAM_GetLastSelectedMoveId(poke));
    if (slot != BTL_MOVE_SLOT_NONE && BTL_POKEPARAM_GetMovePPChecked(poke, slot) == 0) return slot;
    return BTL_MOVE_SLOT_NONE;
}

/* First move slot that is out of PP, else the none value. */
u8 HAND_ITEM_FindEmptyMoveSlot(struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *poke;
    u32 moveCount, i;
    poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    moveCount = BTL_POKEPARAM_GetMoveCount(poke);
    for (i = 0; i < moveCount; i++) {
        if (BTL_POKEPARAM_GetMovePPChecked(poke, (u8)i) == 0) return (u8)i;
    }
    return BTL_MOVE_SLOT_NONE;
}

/* Restore 10 PP of an empty move slot (with allowAnyLostSlot, of any move that lost PP). */
int HAND_ITEM_PushRecoverPp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 pokeId, int *work, int allowAnyLostSlot)
{
    struct BtlPokeParam *poke;
    u32 i;
    u32 moveCount;
    u8 slot;
    HandExRecoverPp *rec;
    poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    slot = HAND_ITEM_FindLastMoveEmptySlot(flow, pokeId);
    if (slot == BTL_MOVE_SLOT_NONE) {
        slot = HAND_ITEM_FindEmptyMoveSlot(flow, pokeId);
        if (slot == BTL_MOVE_SLOT_NONE && allowAnyLostSlot) {
            moveCount = BTL_POKEPARAM_GetMoveCount(poke);
            for (i = 0; i < moveCount; i++) {
                if (BTL_POKEPARAM_GetMovePPLost(poke, i)) {
                    slot = i;
                    break;
                }
            }
        }
    }
    if (slot != BTL_MOVE_SLOT_NONE) {
        rec = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RECOVER_PP, pokeId);
        rec->volume = 10;
        rec->pokeId = pokeId;
        rec->moveSlot = slot;
        rec->showItem = 1;
        BTL_SERVER_FLOW_InitMsgRecord(&rec->message, HANDEX_STR_SET, 0x38f);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->message, BTL_EVENT_GetFactorKey(factor));
        BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->message, BTL_POKEPARAM_GetMoveId(poke, slot));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rec);
        return 1;
    }
    return 0;
}

const BtlEventHandlerEntry *HAND_ITEM_AddOranBerry(int *count) { *count = 5; return gOranBerryHandlers; }

/* HP-restoring berries (Oran, Berry Juice, Sitrus): use the item when HP is low, unless Heal Block applies. */
void HAND_ITEM_RecoverHpOnTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), 15) == 0)
        HAND_ITEM_HpBerryCheckAndUse(factor, flow, pokeId, 2, 1);
}

void HAND_ITEM_RecoverHpOnCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), 15) == 0)
        HAND_ITEM_HpBerryCheckAndUse(factor, flow, pokeId, 2, 0);
}

void HAND_ITEM_RecoverHpOnLowHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), 15) == 0 && HAND_ITEM_IsHpAtOrBelowFraction(flow, pokeId, 2) != 0)
        HAND_ITEM_PushUseItem(factor, flow, pokeId);
}

/* Fixed-amount HP berry eaten through another move: restore the amount from the item parameter. */
void HAND_ITEM_RecoverFixedHpOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExRecoverHp *rec;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        rec = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RECOVER_HP, pokeId);
        rec->pokeId = pokeId;
        rec->amount = HAND_ITEM_GetParam(factor, 2);
        BTL_SERVER_FLOW_InitMsgRecord(&rec->message, HANDEX_STR_SET, 908);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->message, BTL_EVENT_GetFactorKey(factor));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rec);
    }
}

const BtlEventHandlerEntry *HAND_ITEM_AddBerryJuice(int *count)
{
    *count = 4;
    return gBerryJuiceHandlers;
}

const BtlEventHandlerEntry *HAND_ITEM_AddSitrusBerry(int *count)
{
    *count = 5;
    return gSitrusBerryHandlers;
}
