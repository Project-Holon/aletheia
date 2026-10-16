/*
 * file:     hand_item.c
 * unit:     yes
 * function: HAND_ITEM_RecoverHpPercentOfMaxHp, HAND_ITEM_GetFlavorHealAttackHandlers, HAND_ITEM_FlavorHealAttack, HAND_ITEM_FlavorHealAttackIfForcedUse, HAND_ITEM_GetFlavorHealDefenseHandlers, HAND_ITEM_FlavorHealDefense, HAND_ITEM_FlavorHealDefenseIfForcedUse, HAND_ITEM_GetFlavorHealSpeedHandlers, HAND_ITEM_FlavorHealSpeed, HAND_ITEM_FlavorHealSpeedIfForcedUse, HAND_ITEM_GetFlavorHealSpAttackHandlers, HAND_ITEM_FlavorHealSpAttack, HAND_ITEM_FlavorHealSpAttackIfForcedUse, HAND_ITEM_GetFlavorHealSpDefenseHandlers, HAND_ITEM_FlavorHealSpDefense, HAND_ITEM_FlavorHealSpDefenseIfForcedUse, HAND_ITEM_RequestUseAtHalfHpChecked, HAND_ITEM_RequestUseAtHalfHp, HAND_ITEM_RequestUseAtHalfHpDirect, HAND_ITEM_FlavorHeal, HAND_ITEM_GetRaiseAttackOneHandlers, HAND_ITEM_RaiseAttackOne, HAND_ITEM_GetRaiseDefenseOneHandlers, HAND_ITEM_RaiseDefenseOne, HAND_ITEM_GetRaiseSpeedOneHandlers, HAND_ITEM_RaiseSpeedOne, HAND_ITEM_GetRaiseSpAttackOneHandlers, HAND_ITEM_RaiseSpAttackOne, HAND_ITEM_GetRaiseSpDefenseOneHandlers, HAND_ITEM_RaiseSpDefenseOne, HAND_ITEM_GetRaiseCriticalRateHandlers, HAND_ITEM_RaiseCriticalRate, HAND_ITEM_GetRaiseRandomStatHandlers, HAND_ITEM_RaiseRandomStatTwo, HAND_ITEM_RaiseStat, HAND_ITEM_GetSuperEffectiveHitRecoverHandlers, HAND_ITEM_RequestUseOnSuperEffectiveHit, HAND_ITEM_RecoverHpByMaxHpDivisor, HAND_ITEM_GetWeakenDamageFireHandlers, HAND_ITEM_WeakenDamageFire, HAND_ITEM_GetWeakenDamageWaterHandlers, HAND_ITEM_WeakenDamageWater, HAND_ITEM_GetWeakenDamageElectricHandlers, HAND_ITEM_WeakenDamageElectric, HAND_ITEM_GetWeakenDamageGrassHandlers, HAND_ITEM_WeakenDamageGrass, HAND_ITEM_GetWeakenDamageIceHandlers, HAND_ITEM_WeakenDamageIce, HAND_ITEM_GetWeakenDamageFightingHandlers, HAND_ITEM_WeakenDamageFighting, HAND_ITEM_GetWeakenDamagePoisonHandlers, HAND_ITEM_WeakenDamagePoison, HAND_ITEM_GetWeakenDamageGroundHandlers, HAND_ITEM_WeakenDamageGround, HAND_ITEM_GetWeakenDamageFlyingHandlers, HAND_ITEM_WeakenDamageFlying, HAND_ITEM_GetWeakenDamagePsychicHandlers, HAND_ITEM_WeakenDamagePsychic, HAND_ITEM_GetWeakenDamageBugHandlers, HAND_ITEM_WeakenDamageBug, HAND_ITEM_GetWeakenDamageRockHandlers, HAND_ITEM_WeakenDamageRock, HAND_ITEM_GetWeakenDamageGhostHandlers, HAND_ITEM_KasibBerryWeakenGhostHit, HAND_ITEM_GetHabanBerryHandlers, HAND_ITEM_HabanBerryWeakenDragonHit, HAND_ITEM_GetColburBerryHandlers, HAND_ITEM_ColburBerryWeakenDarkHit, HAND_ITEM_GetBabiriBerryHandlers, HAND_ITEM_BabiriBerryWeakenSteelHit, HAND_ITEM_GetChilanBerryHandlers, HAND_ITEM_ChilanBerryWeakenNormalHit, HAND_ITEM_WeakenHitOfType, HAND_ITEM_ShowResistBerryMessage, HAND_ITEM_HpBerryCheckAfterDamage, HAND_ITEM_HpBerryCheckAtTurnEnd, HAND_ITEM_HpBerryCheckOnUse, HAND_ITEM_HpBerryCheckAndUse, HAND_ITEM_IsHpLowForTrigger, HAND_ITEM_IsHpAtOrBelowFraction, HAND_ITEM_GetCustapBerryHandlers, HAND_ITEM_CustapBerryMoveFirst, HAND_ITEM_CustapBerryShowMessage, HAND_ITEM_GetMicleBerryHandlers, HAND_ITEM_MicleBerryCheckOnSwitchIn, HAND_ITEM_MicleBerryCheckAfterDamage, HAND_ITEM_MicleBerryCheckAfterAction, HAND_ITEM_MicleBerryCheckHp, HAND_ITEM_MicleBerryRaiseAccuracy, HAND_ITEM_MicleBerryUseWhenForced, HAND_ITEM_JabocaBerryRememberPhysicalAttacker, HAND_ITEM_GetRowapBerryHandlers, HAND_ITEM_RowapBerryRememberSpecialAttacker, HAND_ITEM_RememberAttackerOfCategory, HAND_ITEM_HitBackAttacker, HAND_ITEM_GetWhiteHerbHandlers, HAND_ITEM_WhiteHerbCheckLoweredStats, HAND_ITEM_WhiteHerbCheckAfterAction, HAND_ITEM_WhiteHerbCheckOnStatChange, HAND_ITEM_WhiteHerbRestoreStats, HAND_ITEM_WhiteHerbUseWhenForced, HAND_ITEM_MentalHerbCheckCondition, HAND_ITEM_MentalHerbCureCondition, HAND_ITEM_MentalHerbUseWhenForced, HAND_ITEM_BrightPowderLowerAccuracy, HAND_ITEM_GetMachoBraceHandlers, HAND_ITEM_MachoBraceHalveSpeed, HAND_ITEM_QuickClawMoveFirst, HAND_ITEM_QuickClawShowMessage, HAND_ITEM_GetLaggingTailHandlers, HAND_ITEM_LaggingTailMoveLast, HAND_ITEM_GetKingsRockHandlers, HAND_ITEM_KingsRockSetFlinchChance, HAND_ITEM_KingsRockFlingFlinch, HAND_ITEM_GetRazorFangHandlers, HAND_ITEM_GetWideLensHandlers, HAND_ITEM_WideLensRaiseAccuracy, HAND_ITEM_RaiseCriticalRankByOne, HAND_ITEM_LuckyPunchRaiseCriticalRankChansey, HAND_ITEM_StickRaiseCriticalRankFarfetchd, HAND_ITEM_ZoomLensRaiseAccuracy, HAND_ITEM_LaxIncenseLowerAccuracy, HAND_ITEM_MuscleBandBoostPhysical, HAND_ITEM_WiseGlassesBoostSpecial, HAND_ITEM_DeepSeaToothDoubleSpAtk, HAND_ITEM_DeepSeaScaleDoubleSpDef, HAND_ITEM_GetMetalPowderHandlers, HAND_ITEM_MetalPowder_DoubleDefense, HAND_ITEM_GetQuickPowderHandlers, HAND_ITEM_QuickPowder_DoubleSpeed, HAND_ITEM_SoulDew_BoostSpAttack, HAND_ITEM_SoulDew_BoostSpDefense, HAND_ITEM_ThickClub_DoubleAttack, HAND_ITEM_GetChoiceBandHandlers, HAND_ITEM_ChoiceBand_BoostAttack, HAND_ITEM_GetChoiceSpecsHandlers, HAND_ITEM_ChoiceSpecs_BoostSpAttack, HAND_ITEM_ChoiceScarf_BoostSpeed, HAND_ITEM_Choice_LockMove, HAND_ITEM_Choice_ReleaseMoveLock, HAND_ITEM_FocusSash_CheckSurvive, HAND_ITEM_FocusSash_ConsumeAndAnnounce, HAND_ITEM_GetFocusBandHandlers, HAND_ITEM_FocusBand_CheckSurvive, HAND_ITEM_FocusBand_UseItem, HAND_ITEM_FocusBand_ShowMessage, HAND_ITEM_GetExpertBeltHandlers, HAND_ITEM_ExpertBelt_BoostSuperEffective, HAND_ITEM_LifeOrb_RecoilDamage, HAND_ITEM_LifeOrb_BoostDamage, HAND_ITEM_Metronome_BoostConsecutiveUse, HAND_ITEM_GetGripClawHandlers, HAND_ITEM_GripClaw_ExtendBind, HAND_ITEM_GetShellBellHandlers, HAND_ITEM_ShellBell_HealFromDamage, HAND_ITEM_GetLightClayHandlers, HAND_ITEM_LightClay_ExtendScreen, HAND_ITEM_GetPowerHerbHandlers, HAND_ITEM_PowerHerb_CheckSkipCharge, HAND_ITEM_PowerHerb_UseItem, HAND_ITEM_PowerHerb_ShowMessage, HAND_ITEM_GetLeftoversHandlers, HAND_ITEM_Leftovers_TriggerOnTurnEnd, HAND_ITEM_Leftovers_Heal, HAND_ITEM_GetBlackSludgeHandlers, HAND_ITEM_BlackSludge_HealOrDamage, HAND_ITEM_DestinyKnot_Infatuate, HAND_ITEM_GetStickyBarbHandlers, HAND_ITEM_StickyBarb_Transfer, HAND_ITEM_StickyBarb_TurnEndDamage, HAND_ITEM_PowerItem_HalveSpeed, HAND_ITEM_GetFlamePlateHandlers, HAND_ITEM_GetSplashPlateHandlers, HAND_ITEM_GetZapPlateHandlers, HAND_ITEM_GetMeadowPlateHandlers, HAND_ITEM_GetIciclePlateHandlers, HAND_ITEM_GetFistPlateHandlers, HAND_ITEM_GetToxicPlateHandlers, HAND_ITEM_GetEarthPlateHandlers, HAND_ITEM_GetSkyPlateHandlers, HAND_ITEM_GetMindPlateHandlers, HAND_ITEM_GetInsectPlateHandlers, HAND_ITEM_GetStonePlateHandlers, HAND_ITEM_GetSpookyPlateHandlers, HAND_ITEM_GetDracoPlateHandlers, HAND_ITEM_GetDreadPlateHandlers, HAND_ITEM_GetIronPlateHandlers, HAND_ITEM_GetBigRootHandlers, HAND_ITEM_BigRoot_BoostDrain, HAND_ITEM_GetSmokeBallHandlers, HAND_ITEM_SmokeBall_AllowEscape, HAND_ITEM_SmokeBallShowEscapeMessage, HAND_ITEM_GetAmuletCoinHandlers, HAND_ITEM_AmuletCoinFlagDoublePrizeOnEnter, HAND_ITEM_AmuletCoinFlagDoublePrizeOnEnterDone, HAND_ITEM_GetGriseousOrbHandlers, HAND_ITEM_GriseousOrbBoostDragonGhostPower, HAND_ITEM_GetIcyRockHandlers, HAND_ITEM_IcyRockExtendHail, HAND_ITEM_GetSmoothRockHandlers, HAND_ITEM_SmoothRockExtendSandstorm, HAND_ITEM_GetHeatRockHandlers, HAND_ITEM_HeatRockExtendSunshine, HAND_ITEM_GetDampRockHandlers, HAND_ITEM_DampRockExtendRain, HAND_ITEM_ExtendWeatherTurns, HAND_ITEM_GetLightBallHandlers, HAND_ITEM_LightBallDoublePikachuAttack, HAND_ITEM_LightBallFlingParalyze, HAND_ITEM_GetToxicOrbHandlers, HAND_ITEM_ToxicOrbPoisonHolderOnTurnEnd, HAND_ITEM_ToxicOrbFlingPoison, HAND_ITEM_GetFlameOrbHandlers, HAND_ITEM_FlameOrbBurnHolderOnTurnEnd, HAND_ITEM_FlameOrbFlingBurn, HAND_ITEM_GetSilverPowderHandlers, HAND_ITEM_SilverPowderBoostPower, HAND_ITEM_GetSoftSandHandlers, HAND_ITEM_SoftSandBoostPower, HAND_ITEM_GetHardStoneHandlers, HAND_ITEM_HardStoneBoostPower, HAND_ITEM_GetMiracleSeedHandlers, HAND_ITEM_MiracleSeedBoostPower, HAND_ITEM_GetBlackGlassesHandlers, HAND_ITEM_BlackGlassesBoostPower, HAND_ITEM_GetBlackBeltHandlers, HAND_ITEM_BlackBeltBoostPower, HAND_ITEM_GetMagnetHandlers, HAND_ITEM_MagnetBoostPower, HAND_ITEM_GetMetalCoatHandlers, HAND_ITEM_MetalCoatBoostPower, HAND_ITEM_GetMysticWaterHandlers, HAND_ITEM_MysticWaterBoostPower, HAND_ITEM_GetSharpBeakHandlers, HAND_ITEM_SharpBeakBoostPower, HAND_ITEM_GetPoisonBarbHandlers, HAND_ITEM_PoisonBarbBoostPower, HAND_ITEM_PoisonBarbFlingPoison, HAND_ITEM_GetNeverMeltIceHandlers, HAND_ITEM_NeverMeltIceBoostPower, HAND_ITEM_GetSpellTagHandlers, HAND_ITEM_SpellTagBoostPower, HAND_ITEM_GetTwistedSpoonHandlers, HAND_ITEM_TwistedSpoonBoostPower, HAND_ITEM_GetCharcoalHandlers, HAND_ITEM_CharcoalBoostPower, HAND_ITEM_GetDragonFangHandlers, HAND_ITEM_DragonFangBoostPower, HAND_ITEM_GetSilkScarfHandlers, HAND_ITEM_SilkScarfBoostPower, HAND_ITEM_GetOddIncenseHandlers, HAND_ITEM_OddIncenseBoostPower, HAND_ITEM_GetRockIncenseHandlers, HAND_ITEM_RockIncenseBoostPower, HAND_ITEM_GetSeaIncenseHandlers, HAND_ITEM_SeaIncenseBoostPower, HAND_ITEM_GetWaveIncenseHandlers, HAND_ITEM_WaveIncenseBoostPower, HAND_ITEM_GetRoseIncenseHandlers, HAND_ITEM_RoseIncenseBoostPower, HAND_ITEM_BoostMovePowerOfType, HAND_ITEM_GetLustrousOrbHandlers, HAND_ITEM_LustrousOrbMovePower, HAND_ITEM_GetAdamantOrbHandlers, HAND_ITEM_AdamantOrbMovePower, HAND_ITEM_GetIronBallHandlers, HAND_ITEM_IronBallSpeedRatio, HAND_ITEM_IronBallGroundCheck, HAND_ITEM_GetFloatStoneHandlers, HAND_ITEM_FloatStoneWeightRatio, HAND_ITEM_GetEvioliteHandlers, HAND_ITEM_EvioliteDefenseRatio, HAND_ITEM_GetRockyHelmetHandlers, HAND_ITEM_RockyHelmetDamageReaction, HAND_ITEM_GetAirBalloonHandlers, HAND_ITEM_AirBalloonEnterField, HAND_ITEM_AirBalloonGroundCheck, HAND_ITEM_AirBalloonPop, HAND_ITEM_GetRedCardHandlers, HAND_ITEM_RedCardForceSwitch, HAND_ITEM_GetRingTargetHandlers, HAND_ITEM_RingTargetImmunityOverride, HAND_ITEM_GetBindingBandHandlers, HAND_ITEM_BindingBandSickCont, HAND_ITEM_GetAbsorbBulbHandlers, HAND_ITEM_AbsorbBulbDamageReaction, HAND_ITEM_AbsorbBulbUse, HAND_ITEM_GetCellBatteryHandlers, HAND_ITEM_CellBatteryDamageReaction, HAND_ITEM_CellBatteryUse, HAND_ITEM_GetEjectButtonHandlers, HAND_ITEM_EjectButtonAfterDamage, HAND_ITEM_EjectButtonUse, HAND_ITEM_GetFireGemHandlers, HAND_ITEM_FireGemMovePower, HAND_ITEM_FireGemMoveUsed, HAND_ITEM_GetWaterGemHandlers, HAND_ITEM_WaterGemMovePower, HAND_ITEM_WaterGemMoveUsed, HAND_ITEM_GetElectricGemHandlers, HAND_ITEM_ElectricGemMovePower, HAND_ITEM_ElectricGemMoveUsed, HAND_ITEM_GetGrassGemHandlers, HAND_ITEM_GrassGemMovePower, HAND_ITEM_GrassGemMoveUsed, HAND_ITEM_GetIceGemHandlers, HAND_ITEM_IceGemMovePower, HAND_ITEM_IceGemMoveUsed, HAND_ITEM_GetFightingGemHandlers, HAND_ITEM_FightingGemMovePower, HAND_ITEM_FightingGemMoveUsed, HAND_ITEM_GetPoisonGemHandlers, HAND_ITEM_PoisonGemMovePower, HAND_ITEM_PoisonGemMoveUsed, HAND_ITEM_GetGroundGemHandlers, HAND_ITEM_GroundGemMovePower, HAND_ITEM_GroundGemMoveUsed, HAND_ITEM_GetFlyingGemHandlers, HAND_ITEM_FlyingGemMovePower, HAND_ITEM_FlyingGemMoveUsed, HAND_ITEM_GetPsychicGemHandlers, HAND_ITEM_PsychicGemMovePower, HAND_ITEM_PsychicGemMoveUsed, HAND_ITEM_GetBugGemHandlers, HAND_ITEM_BugGemMovePower, HAND_ITEM_BugGemMoveUsed, HAND_ITEM_GetRockGemHandlers, HAND_ITEM_RockGemMovePower, HAND_ITEM_RockGemMoveUsed, HAND_ITEM_GetGhostGemHandlers, HAND_ITEM_GhostGemMovePower, HAND_ITEM_GhostGemMoveUsed, HAND_ITEM_GetDragonGemHandlers, HAND_ITEM_DragonGemMovePower, HAND_ITEM_DragonGemMoveUsed, HAND_ITEM_GetDarkGemHandlers, HAND_ITEM_DarkGemMovePower, HAND_ITEM_DarkGemMoveUsed, HAND_ITEM_GetSteelGemHandlers, HAND_ITEM_SteelGemMovePower, HAND_ITEM_SteelGemMoveUsed, HAND_ITEM_GetNormalGemHandlers, HAND_ITEM_NormalGemMoveUsed, HAND_ITEM_NormalGemMovePower, HAND_ITEM_GemMoveUsed
 * address:  0x021DD588
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #9; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl HAND_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0xa; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl HAND_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0xc; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl HAND_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #1; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl HAND_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #3; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl HAND_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0xd; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl HAND_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #6; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl HAND_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #5; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl HAND_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #7; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl HAND_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0xf; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl HAND_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0x10; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl HAND_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 * extent: includes store-return follower 0x021DE974.

 *
 * symbols:
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_GetValue   0x021D59B4  thumb ov093
 *   HAND_ITEM_GetParam   0x021DCFF8  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord   0x021C8838  thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg   0x021C8860  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 *   BTL_EVENT_GetFactorKey   0x021D70A8  thumb ov093
 *   func_0209C2B0   0x0209C2B0  arm
 *   gBtlItemFlavorHealDefenseHandlers 0x021F1C2C data a4
 *   gBtlItemFlavorHealSpeedHandlers 0x021F1C54 data a4
 *   gBtlItemFlavorHealSpAttackHandlers 0x021F1C7C data a4
 *   gBtlItemFlavorHealSpDefenseHandlers 0x021F1CA4 data a4
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   HAND_ITEM_PushUseItem 0x021DD044 thumb ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   POKE_TOOL_GetNatureStatMod  0x020189D0  thumb
 *   BTL_CALC_MakeSickContFromKind  0x021D7DC0  thumb  ov093
 *   gBtlItemFlavorHealAttackHandlers     0x021F1C04  data   ov093  a4
 *   gBtlItemRaiseAttackOneHandlers     0x021F1CCC  data   ov093  a4
 *   gBtlItemRaiseDefenseOneHandlers     0x021F1CF4  data   ov093  a4
 *   gBtlItemRaiseSpeedOneHandlers     0x021F1D1C  data   ov093  a4
 *   gBtlItemRaiseSpAttackOneHandlers     0x021F1D44  data   ov093  a4
 *   gBtlItemRaiseSpDefenseOneHandlers     0x021F1D6C  data   ov093  a4
 *   BTL_POKEPARAM_TestContFlag   0x021D5BDC  thumb ov093
 *   gBtlItemRaiseCriticalRateHandlers     0x021F1D94  data   ov093  a4
 *   BTL_SERVER_FLOW_GetScratchBuffer  0x021C8120  thumb  ov093
 *   BTL_POKEPARAM_CanChangeStatStage  0x021D5D14  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   gBtlItemRaiseStatCandidates     0x021F1364  data  ov093  a1
 *   gBtlItemRaiseRandomStatHandlers     0x021F1DBC  data   ov093  a4
 *   gBtlItemSuperEffectiveHitRecoverHandlers     0x021F16CC  data   ov093  a4
 *   gBtlItemWeakenDamageFireHandlers     0x021F175C  data   ov093  a4
 *   gBtlItemWeakenDamageWaterHandlers     0x021F177C  data   ov093  a4
 *   gBtlItemWeakenDamageElectricHandlers     0x021F178C  data   ov093  a4
 *   gBtlItemWeakenDamageGrassHandlers     0x021F179C  data   ov093  a4
 *   gBtlItemWeakenDamageIceHandlers     0x021F17AC  data   ov093  a4
 *   gBtlItemWeakenDamageFightingHandlers     0x021F171C  data   ov093  a4
 *   gBtlItemWeakenDamagePoisonHandlers     0x021F17BC  data   ov093  a4
 *   gBtlItemWeakenDamageGroundHandlers     0x021F17CC  data   ov093  a4
 *   gBtlItemWeakenDamageFlyingHandlers     0x021F17DC  data   ov093  a4
 *   gBtlItemWeakenDamagePsychicHandlers     0x021F172C  data   ov093  a4
 *   gBtlItemWeakenDamageBugHandlers     0x021F17EC  data   ov093  a4
 *   gBtlItemWeakenDamageRockHandlers     0x021F17FC  data   ov093  a4
 *   gBtlItemWeakenDamageGhostHandlers     0x021F180C  data   ov093  a4
 *   gHabanBerryHandlers     0x021F181C  data   ov093  a4
 *   gColburBerryHandlers     0x021F182C  data   ov093  a4
 *   gBabiriBerryHandlers     0x021F183C  data   ov093  a4
 *   BTL_POKEPARAM_HasSubstitute  0x021D6D7C  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_SERVER_FLOW_IsActionCounterSet  0x021C7EC4  thumb  ov093
 *   HAND_COMMON_IsMoveTarget  0x021E85F8  thumb  ov093
 *   BTL_CALC_DivideMaxHp  0x021D7B60  thumb  ov093
 *   gChilanBerryHandlers     0x021F184C  data   ov093  a4
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 *   gCustapBerryHandlers     0x021F15EC  data   ov093  a4
 *   BTLV_CORE_MakeSlotKind1Value  0x021E89D4  thumb  ov093
 *   gJabocaBerryHandlers 0x021F160C data a4
 *   gMicleBerryHandlers     0x021F1E0C  data   ov093  a4
 *   BTL_ID_IsMetronomeItemIgnoredMove  0x0689C8CC  thumb  ov095
 *   BTL_EVENT_KeepFactorRunning  0x021D70C8  thumb  ov093
 *   gRowapBerryHandlers     0x021F162C  data   ov093  a4
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_HasLoweredStatStage 0x021D5D68 thumb ov093
 *   gMentalHerbHandlers 0x021F1A84 data a4
 *   BTL_CALC_FindMajorSick 0x021D7E10 thumb ov093
 *   HAND_ITEM_CureSickOnEaten  0x021DD19C  thumb  ov093
 *   gBrightPowderHandlers 0x021F1564 data a4
 *   gWhiteHerbHandlers     0x021F1E3C  data   ov093  a4
 *   gMachoBraceHandlers     0x021F156C  data   ov093  a4
 *   _ffltu         0x0209BE04  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   gLaggingTailHandlers     0x021F1394  data   ov093  a4
 *   gQuickClawHandlers 0x021F163C data a4
 *   HAND_ITEM_RollChance  0x021DCFD0  thumb  ov093
 *   gKingsRockHandlers     0x021F164C  data   ov093  a4
 *   HAND_ITEM_GetBoostRatio 0x021DD008 thumb ov093
 *   gScopeLensHandlers 0x021F158C data a4
 *   gLuckyPunchHandlers 0x021F146C data a4
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   gStickHandlers     0x021F13DC  data   ov093  a4
 *   gZoomLensHandlers     0x021F13D4  data   ov093  a4
 *   gRazorFangHandlers     0x021F165C  data   ov093  a4
 *   gWideLensHandlers     0x021F1584  data   ov093  a4
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   gLaxIncenseHandlers     0x021F1474  data   ov093  a4
 *   _fflt          0x0209BDBC  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   gMuscleBandHandlers     0x021F13E4  data   a4
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   gWiseGlassesHandlers     0x021F148C  data   ov093  a4
 *   gDeepSeaToothHandlers     0x021F13EC  data   ov093  a4
 *   gDeepSeaScaleHandlers     0x021F139C  data   a4
 *   gMetalPowderHandlers     0x021F1454  data   a4
 *   BTL_POKEPARAM_IsTransformed  0x021D6D54  thumb  ov093
 *   gQuickPowderHandlers     0x021F14AC  data   a4
 *   gSoulDewHandlers     0x021F16AC  data   a4
 *   gThickClubHandlers     0x021F13A4  data   a4
 *   gChoiceBandHandlers     0x021F18D4  data   a4
 *   gChoiceSpecsHandlers 0x021F18EC data a4
 *   gExpertBeltHandlers     0x021F150C  data   ov093  a4
 *   gChoiceScarfHandlers 0x021F1904 data a4
 *   gFocusSashHandlers 0x021F16BC data a4
 *   BTL_POKEPARAM_IsHpFull 0x021D5B48 thumb ov093
 *   gFocusBandHandlers 0x021F191C data a4
 *   gLifeOrbHandlers 0x021F16DC data a4
 *   gMetronomeHandlers 0x021F13BC data a4
 *   BTL_POKEPARAM_GetMoveStreak  0x021D679C  thumb  ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId  0x021D67A8  thumb  ov093
 *   gGripClawHandlers 0x021F1384 data a4
 *   BTLV_CORE_SetSlotIndex  0x021E8C9C  thumb  ov093
 *   gShellBellHandlers     0x021F152C  data   ov093  a4
 *   gLightClayHandlers     0x021F143C  data   ov093  a4
 *   BTLV_CORE_AddSlotIndex  0x021E8C50  thumb  ov093
 *   gPowerHerbHandlers     0x021F197C  data   ov093  a4
 *   gLeftoversHandlers     0x021F16EC  data   ov093  a4
 *   gBlackSludgeHandlers     0x021F14B4  data   ov093  a4
 *   gFlamePlateHandlers     0x021F15CC  data   ov093  a4
 *   gSplashPlateHandlers     0x021F147C  data   ov093  a4
 *   gZapPlateHandlers     0x021F136C  data   ov093  a4
 *   gMeadowPlateHandlers     0x021F15D4  data   ov093  a4
 *   gIciclePlateHandlers     0x021F13CC  data   ov093  a4
 *   gFistPlateHandlers     0x021F1494  data   ov093  a4
 *   gToxicPlateHandlers     0x021F149C  data   ov093  a4
 *   gEarthPlateHandlers     0x021F14E4  data   ov093  a4
 *   gSkyPlateHandlers     0x021F1594  data   ov093  a4
 *   gMindPlateHandlers     0x021F13F4  data   ov093  a4
 *   gInsectPlateHandlers     0x021F14A4  data   ov093  a4
 *   gStonePlateHandlers     0x021F1574  data   ov093  a4
 *   gSpookyPlateHandlers     0x021F1374  data   ov093  a4
 *   gDracoPlateHandlers     0x021F14D4  data   ov093  a4
 *   gDreadPlateHandlers     0x021F14EC  data   ov093  a4
 *   gIronPlateHandlers     0x021F1424  data   ov093  a4
 *   gBigRootHandlers     0x021F153C  data   ov093  a4
 *   BTL_SERVER_FLOW_CheckShowdownThunk 0x021C83D4 thumb ov093
 *   BTL_POKEPARAM_GetTypePair 0x021D57FC thumb ov093
 *   BTLV_CORE_HasByte 0x021E8D24 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos 0x021C8010 thumb ov093
 *   gDestinyKnotHandlers 0x021F154C data a4
 *   BTLV_CORE_MakeSlotKind3  0x021E899C  thumb  ov093
 *   gStickyBarbHandlers 0x021F16FC data
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   gPowerWeightHandlers 0x021F138C data a4
 *   gPowerBracerHandlers 0x021F1434 data a4
 *   gPowerBeltHandlers 0x021F15A4 data a4
 *   gPowerLensHandlers 0x021F1554 data a4
 *   gPowerBandHandlers 0x021F15B4 data a4
 *   gPowerAnkletHandlers 0x021F15C4 data a4
 *   BTLV_CORE_EventSetFlagIfAttacker  0x021E8878  thumb  ov093
 *   gSmokeBallHandlers     0x021F15FC  data   ov093  a4
 *   BTLV_CORE_EventTrySetFlagIfAttacker  0x021E889C  thumb  ov093
 *   BTL_SERVER_FLOW_SetMsgRecordSe  0x021C888C  thumb  ov093
 *   BTL_SERVER_FLOW_TryFinishMainCounter  0x021C8408  thumb  ov093
 *   gAmuletCoinHandlers     0x021F161C  data   ov093  a4
 *   gGriseousOrbHandlers     0x021F1534  data   ov093  a4
 *   gIcyRockHandlers     0x021F145C  data   ov093  a4
 *   gSmoothRockHandlers     0x021F1464  data   ov093  a4
 *   gHeatRockHandlers     0x021F151C  data   a4
 *   gDampRockHandlers     0x021F1514  data   ov093  a4
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 *   gLightBallHandlers     0x021F167C  data   ov093  a4
 *   BTLV_CORE_MakeSlotKind1Index15  0x021E8A58  thumb  ov093
 *   gToxicOrbHandlers     0x021F168C  data   ov093  a4
 *   gFlameOrbHandlers     0x021F169C  data   ov093  a4
 *   gSilverPowderHandlers     0x021F14F4  data   ov093  a4
 *   gSoftSandHandlers     0x021F13FC  data   ov093  a4
 *   gHardStoneHandlers     0x021F13AC  data   ov093  a4
 *   gMiracleSeedHandlers     0x021F137C  data   ov093  a4
 *   gBlackGlassesHandlers     0x021F13B4  data   ov093  a4
 *   gBlackBeltHandlers     0x021F142C  data   ov093  a4
 *   gMagnetHandlers     0x021F14C4  data   ov093  a4
 *   gMetalCoatHandlers     0x021F13C4  data   ov093  a4
 *   gMysticWaterHandlers     0x021F1444  data   ov093  a4
 *   gSharpBeakHandlers     0x021F144C  data   ov093  a4
 *   gPoisonBarbHandlers     0x021F170C  data   ov093  a4
 *   gNeverMeltIceHandlers     0x021F15AC  data    a4
 *   gSpellTagHandlers     0x021F15BC  data   ov093  a4
 *   gTwistedSpoonHandlers     0x021F1484  data   ov093  a4
 *   gCharcoalHandlers     0x021F15E4  data   ov093  a4
 *   gDragonFangHandlers     0x021F15DC  data   ov093  a4
 *   gSilkScarfHandlers     0x021F159C  data   ov093  a4
 *   gOddIncenseHandlers     0x021F155C  data   ov093  a4
 *   gRockIncenseHandlers     0x021F1404  data   ov093  a4
 *   gSeaIncenseHandlers     0x021F1544  data   ov093  a4
 *   gWaveIncenseHandlers     0x021F14DC  data   ov093  a4
 *   gRoseIncenseHandlers     0x021F1414  data    a4
 *   gLustrousOrbHandlers     0x021F141C  data   ov093  a4
 *   gBtlHandlerItemAdamantOrbHandlers     0x021F157C  data   ov093  a4
 *   gBtlHandlerItemIronBallHandlers     0x021F166C  data   ov093  a4
 *   gBtlHandlerItemFloatStoneHandlers     0x021F1504  data   ov093  a4
 *   BTL_SERVER_FLOW_IsPokeEvolvable  0x021C818C  thumb  ov093
 *   gBtlHandlerItemEvioliteHandlers     0x021F14FC  data   ov093  a4
 *   gBtlHandlerItemRockyHelmetHandlers     0x021F140C  data   ov093  a4
 *   BTL_FIELD_GetStaticSlotObject  0x021EF948  thumb  ov093
 *   gBtlHandlerItemAirBalloonHandlers     0x021F1934  data   ov093  a4
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SERVER_FLOW_CheckClientHasBackupPoke  0x021C7F24  thumb  ov093
 *   gBtlHandlerItemRedCardHandlers     0x021F14CC  data   ov093  a4
 *   gBtlHandlerItemRingTargetHandlers     0x021F14BC  data   ov093  a4
 *   gBtlHandlerItemBindingBandHandlers     0x021F1524  data   ov093  a4
 *   BTL_ID_IsGemIgnoredMove  0x0689C8EC  thumb
 *   BTLV_CORE_SetSlotFlag  0x021E8BD0  thumb  ov093
 *   gHandItemAbsorbBulbHandlers     0x021F173C  data    a4
 *   gHandItemCellBatteryHandlers     0x021F174C  data   ov093  a4
 *   BTL_SERVER_FLOW_IsPokeAfflictedByStatus  0x021C8374  thumb  ov093
 *   BTL_SERVER_FLOW_TestStateFlagBit0  0x021C830C  thumb  ov093
 *   BTL_SERVER_FLOW_TrySetOnceFlag  0x021C7F4C  thumb  ov093
 *   gHandItemEjectButtonHandlers     0x021F176C  data   ov093  a4
 *   HAND_ITEM_GemMovePower   0x021E0284  thumb
 *   gHandItemFireGemHandlers     0x021F1A3C  data    a4
 *   gHandItemWaterGemHandlers     0x021F1A54  data   ov093  a4
 *   gHandItemElectricGemHandlers     0x021F1874  data   ov093  a4
 *   gHandItemGrassGemHandlers     0x021F18A4  data   ov093  a4
 *   gHandItemIceGemHandlers     0x021F18BC  data   ov093  a4
 *   gHandItemFightingGemHandlers     0x021F194C  data   ov093  a4
 *   gHandItemPoisonGemHandlers     0x021F1994  data   ov093  a4
 *   gHandItemGroundGemHandlers     0x021F19AC  data   ov093  a4
 *   gHandItemFlyingGemHandlers     0x021F1A24  data   ov093  a4
 *   gHandItemPsychicGemHandlers     0x021F1A6C  data   ov093  a4
 *   gHandItemBugGemHandlers     0x021F185C  data   ov093  a4
 *   gHandItemRockGemHandlers     0x021F1964  data   ov093  a4
 *   gHandItemGhostGemHandlers     0x021F19DC  data   ov093  a4
 *   gHandItemDragonGemHandlers     0x021F1A0C  data   ov093  a4
 *   gHandItemDarkGemHandlers     0x021F188C  data   ov093  a4
 *   gHandItemSteelGemHandlers     0x021F19F4  data   ov093  a4
 *   WAZA_TOOL_IsDamaging  0x0201C314  thumb
 *   BTL_EVENT_IsFactorDead  0x021D7098  thumb  ov093
 *   BTL_EVENT_MarkFactorDead  0x021D7090  thumb  ov093
 *   gHandItemNormalGemHandlers     0x021F19C4  data   ov093  a4
 */
#include "hand_item_types.h"

#define STR_ID_MICLE_ACCURACY 0x404
#define STR_ID_JABOCA_ROWAP_HIT_BACK 0x407
#define STR_ID_WHITE_HERB_RESTORED 0x3f2
#define KINGS_ROCK_FLINCH_PERCENT 100   /* Fling flinch chance */
#define CRITICAL_RANK_PLUS_ONE 1
#define CRITICAL_RANK_PLUS_TWO 2
#define TURN_FLAG_ACTED 1   /* the Pokemon has acted this turn */
#define BTL_MOVE_SKY_DROP 507 /* (guess) the two-turn move that Power Herb cannot skip */
#define BTL_POISON_TYPE 3
#define BTL_NO_POKE_ID 0x1f
#define BTL_MOVE_FLAG_CONTACT 0
struct BtlEventFactor;
typedef struct Word { u32 v; } Word;

/* Services of the event variable stack and the battle server flow. */
extern int BTL_EVENT_GetVar(int key);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlServerFlow *flow, int pokeId);
/* Services of the poke parameter. */
extern int BTL_POKEPARAM_GetValue(struct BtlPokeParam *bpp, int valueId);
extern int HAND_ITEM_GetParam(struct BtlEventFactor *factor, int index);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlServerFlow *flow, int size, int pokeId);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *strParam, int strType, int strId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(void *strParam, u32 arg);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlServerFlow *flow, void *cmd);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern int func_0209C2B0(int dividend, int divisor);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sickId);
extern void HAND_ITEM_PushUseItem(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *pokeParam, u32 divisor);
extern void *BTL_POKEPARAM_GetMon(struct BtlPokeParam *pokeParam);
extern int POKE_TOOL_GetNatureStatMod(void *mon, int statIndex);
extern void BTL_CALC_MakeSickContFromKind(int sickKind, struct BtlPokeParam *pokeParam, union SickCont *out);
extern int BTL_POKEPARAM_TestContFlag(struct BtlPokeParam *bpp, u32 flagIndex);
extern int BTL_POKEPARAM_CanChangeStatStage(struct BtlPokeParam *pokeParam, int statId, int amount);
extern u32 BTL_CALC_Random(u32 range);
extern u32 BTL_POKEPARAM_HasSubstitute(struct BtlPokeParam *poke);
extern void BTL_EVENT_MultiplyVar(int key, s32 ratio);
extern u32 BTL_SERVER_FLOW_IsActionCounterSet(struct BtlServerFlow *flow);
extern int HAND_COMMON_IsMoveTarget(int pokeId);
extern u32 BTL_CALC_DivideMaxHp(struct BtlPokeParam *bpp, u32 divisor);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern int BTLV_CORE_MakeSlotKind1Value(u32 percent);
extern void BTL_EVENT_KeepFactorRunning(struct BtlEventFactor *factor);
extern int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *poke);
extern int BTL_POKEPARAM_HasLoweredStatStage(struct BtlPokeParam *poke);
extern int BTL_CALC_FindMajorSick(struct BtlPokeParam *poke);
void HAND_ITEM_CureSickOnEaten(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int sickKind);
extern int HAND_ITEM_RollChance(struct BtlServerFlow *flow, unsigned int percent);
extern int HAND_ITEM_GetBoostRatio(struct BtlEventFactor *factor);
extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *poke);
extern int BTL_POKEPARAM_TestTurnFlag(struct BtlPokeParam *poke, u32 flag);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern int BTL_POKEPARAM_IsTransformed(void *pokeParam);
extern u16 BTL_POKEPARAM_GetMoveStreak(void *pokeParam);
extern void BTLV_CORE_SetSlotIndex(u32 *sickCont, int value);
extern void BTLV_CORE_AddSlotIndex(u32 *sickCont, u32 turns);
extern int BTL_SERVER_FLOW_CheckShowdownThunk(struct BtlServerFlow *flow);
extern u16 BTL_POKEPARAM_GetTypePair(void *pokeParam);
extern int BTLV_CORE_HasByte(int typePair, int typeId);
extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 flagBit);
extern void BTLV_CORE_EventSetFlagIfAttacker(struct BtlEventFactor *factor, void *flow, int pokeId, void *work);
void HAND_ITEM_GemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work, u8 gemType);
void HAND_ITEM_RecoverHpPercentOfMaxHp(struct BtlEventFactor *factor, void *server, int pokeId);
int *HAND_ITEM_GetFlavorHealAttackHandlers(int *handlerCount);
void HAND_ITEM_FlavorHealAttack(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_ITEM_FlavorHealAttackIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_ITEM_GetFlavorHealDefenseHandlers(int *handlerCount);
void HAND_ITEM_FlavorHealDefense(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_ITEM_FlavorHealDefenseIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_ITEM_GetFlavorHealSpeedHandlers(int *handlerCount);
void HAND_ITEM_FlavorHealSpeed(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_ITEM_FlavorHealSpeedIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_ITEM_GetFlavorHealSpAttackHandlers(int *handlerCount);
void HAND_ITEM_FlavorHealSpAttack(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_ITEM_FlavorHealSpAttackIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_ITEM_GetFlavorHealSpDefenseHandlers(int *handlerCount);
void HAND_ITEM_FlavorHealSpDefense(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_ITEM_FlavorHealSpDefenseIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_ITEM_RequestUseAtHalfHpChecked(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_ITEM_RequestUseAtHalfHp(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_ITEM_RequestUseAtHalfHpDirect(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_ITEM_FlavorHeal(struct BtlEventFactor *factor, void *server, int pokeId, int *work, int statIndex);
int *HAND_ITEM_GetRaiseAttackOneHandlers(int *handlerCount);
void HAND_ITEM_RaiseAttackOne(struct BtlEventFactor *factor, void *server, int pokeId);
int *HAND_ITEM_GetRaiseDefenseOneHandlers(int *handlerCount);
void HAND_ITEM_RaiseDefenseOne(struct BtlEventFactor *factor, void *server, int pokeId);
int *HAND_ITEM_GetRaiseSpeedOneHandlers(int *handlerCount);
void HAND_ITEM_RaiseSpeedOne(struct BtlEventFactor *factor, void *server, int pokeId);
int *HAND_ITEM_GetRaiseSpAttackOneHandlers(int *handlerCount);
void HAND_ITEM_RaiseSpAttackOne(struct BtlEventFactor *factor, void *server, int pokeId);
int *HAND_ITEM_GetRaiseSpDefenseOneHandlers(int *handlerCount);
void HAND_ITEM_RaiseSpDefenseOne(struct BtlEventFactor *factor, void *server, int pokeId);
int *HAND_ITEM_GetRaiseCriticalRateHandlers(int *handlerCount);
void HAND_ITEM_RaiseCriticalRate(struct BtlEventFactor *factor, void *server, int pokeId);
int *HAND_ITEM_GetRaiseRandomStatHandlers(int *handlerCount);
void HAND_ITEM_RaiseRandomStatTwo(struct BtlEventFactor *factor, void *server, u8 pokeId);
void HAND_ITEM_RaiseStat(void *server, int pokeId, int statId, int amount);
int *HAND_ITEM_GetSuperEffectiveHitRecoverHandlers(int *handlerCount);
void HAND_ITEM_RequestUseOnSuperEffectiveHit(struct BtlEventFactor *factor, void *server, int pokeId);
void HAND_ITEM_RecoverHpByMaxHpDivisor(struct BtlEventFactor *factor, void *server, int pokeId);
int *HAND_ITEM_GetWeakenDamageFireHandlers(int *handlerCount);
void HAND_ITEM_WeakenDamageFire(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_ITEM_GetWeakenDamageWaterHandlers(int *handlerCount);
void HAND_ITEM_WeakenDamageWater(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_ITEM_GetWeakenDamageElectricHandlers(int *handlerCount);
void HAND_ITEM_WeakenDamageElectric(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_ITEM_GetWeakenDamageGrassHandlers(int *handlerCount);
void HAND_ITEM_WeakenDamageGrass(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_ITEM_GetWeakenDamageIceHandlers(int *handlerCount);
void HAND_ITEM_WeakenDamageIce(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_ITEM_GetWeakenDamageFightingHandlers(int *handlerCount);
void HAND_ITEM_WeakenDamageFighting(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_ITEM_GetWeakenDamagePoisonHandlers(int *handlerCount);
void HAND_ITEM_WeakenDamagePoison(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_ITEM_GetWeakenDamageGroundHandlers(int *handlerCount);
void HAND_ITEM_WeakenDamageGround(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_ITEM_GetWeakenDamageFlyingHandlers(int *handlerCount);
void HAND_ITEM_WeakenDamageFlying(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_ITEM_GetWeakenDamagePsychicHandlers(int *handlerCount);
void HAND_ITEM_WeakenDamagePsychic(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_ITEM_GetWeakenDamageBugHandlers(int *handlerCount);
void HAND_ITEM_WeakenDamageBug(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_ITEM_GetWeakenDamageRockHandlers(int *handlerCount);
void HAND_ITEM_WeakenDamageRock(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_ITEM_GetWeakenDamageGhostHandlers(int *handlerCount);
void HAND_ITEM_KasibBerryWeakenGhostHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_ITEM_GetHabanBerryHandlers(int *handlerCount);
void HAND_ITEM_HabanBerryWeakenDragonHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_ITEM_GetColburBerryHandlers(int *handlerCount);
void HAND_ITEM_ColburBerryWeakenDarkHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_ITEM_GetBabiriBerryHandlers(int *handlerCount);
void HAND_ITEM_BabiriBerryWeakenSteelHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_ITEM_GetChilanBerryHandlers(int *handlerCount);
void HAND_ITEM_ChilanBerryWeakenNormalHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int HAND_ITEM_WeakenHitOfType(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work, u8 moveType, int ignoreAffinity);
void HAND_ITEM_ShowResistBerryMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_HpBerryCheckAfterDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_HpBerryCheckAtTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_HpBerryCheckOnUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_HpBerryCheckAndUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int fraction, int checkTrigger);
int HAND_ITEM_IsHpLowForTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, unsigned int fraction);
int HAND_ITEM_IsHpAtOrBelowFraction(struct BtlServerFlow *flow, int pokeId, u32 fraction);
int *HAND_ITEM_GetCustapBerryHandlers(int *handlerCount);
void HAND_ITEM_CustapBerryMoveFirst(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_CustapBerryShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_ITEM_GetMicleBerryHandlers(int *handlerCount);
void HAND_ITEM_MicleBerryCheckOnSwitchIn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_MicleBerryCheckAfterDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_MicleBerryCheckAfterAction(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_MicleBerryCheckHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_MicleBerryRaiseAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_MicleBerryUseWhenForced(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void *HAND_ITEM_GetJabocaBerryHandlers(int *handlerCount);
void HAND_ITEM_JabocaBerryRememberPhysicalAttacker(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_ITEM_GetRowapBerryHandlers(int *handlerCount);
void HAND_ITEM_RowapBerryRememberSpecialAttacker(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_RememberAttackerOfCategory(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work, int moveCategory);
void HAND_ITEM_HitBackAttacker(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_ITEM_GetWhiteHerbHandlers(int *handlerCount);
void HAND_ITEM_WhiteHerbCheckLoweredStats(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int work);
void HAND_ITEM_WhiteHerbCheckAfterAction(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int work);
void HAND_ITEM_WhiteHerbCheckOnStatChange(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_WhiteHerbRestoreStats(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_WhiteHerbUseWhenForced(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void *HAND_ITEM_GetMentalHerbHandlers(int *handlerCount);
void HAND_ITEM_MentalHerbCheckCondition(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_MentalHerbCureCondition(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_MentalHerbUseWhenForced(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void *HAND_ITEM_GetBrightPowderHandlers(int *handlerCount);
void HAND_ITEM_BrightPowderLowerAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_ITEM_GetMachoBraceHandlers(int *handlerCount);
void HAND_ITEM_MachoBraceHalveSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void *HAND_ITEM_GetQuickClawHandlers(int *handlerCount);
void HAND_ITEM_QuickClawMoveFirst(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_QuickClawShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_ITEM_GetLaggingTailHandlers(int *handlerCount);
void HAND_ITEM_LaggingTailMoveLast(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_ITEM_GetKingsRockHandlers(int *handlerCount);
void HAND_ITEM_KingsRockSetFlinchChance(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_KingsRockFlingFlinch(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_ITEM_GetRazorFangHandlers(int *handlerCount);
int *HAND_ITEM_GetWideLensHandlers(int *handlerCount);
void HAND_ITEM_WideLensRaiseAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void *HAND_ITEM_GetScopeLensHandlers(int *handlerCount);
void HAND_ITEM_RaiseCriticalRankByOne(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void *HAND_ITEM_GetLuckyPunchHandlers(int *handlerCount);
void HAND_ITEM_LuckyPunchRaiseCriticalRankChansey(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_ITEM_GetStickHandlers(int *handlerCount);
void HAND_ITEM_StickRaiseCriticalRankFarfetchd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_ITEM_GetZoomLensHandlers(int *handlerCount);
void HAND_ITEM_ZoomLensRaiseAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_ITEM_GetLaxIncenseHandlers(int *handlerCount);
void HAND_ITEM_LaxIncenseLowerAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_ITEM_GetMuscleBandHandlers(int *handlerCount);
void HAND_ITEM_MuscleBandBoostPhysical(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_ITEM_GetWiseGlassesHandlers(int *handlerCount);
void HAND_ITEM_WiseGlassesBoostSpecial(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_ITEM_GetDeepSeaToothHandlers(int *handlerCount);
void HAND_ITEM_DeepSeaToothDoubleSpAtk(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_ITEM_GetDeepSeaScaleHandlers(int *handlerCount);
void HAND_ITEM_DeepSeaScaleDoubleSpDef(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_ITEM_GetMetalPowderHandlers(int *handlerCount);
void HAND_ITEM_MetalPowder_DoubleDefense(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetQuickPowderHandlers(int *count);
void HAND_ITEM_QuickPowder_DoubleSpeed(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetSoulDewHandlers(int *count);
void HAND_ITEM_SoulDew_BoostSpAttack(struct BtlEventFactor *factor, void *flow, int pokeId);
void HAND_ITEM_SoulDew_BoostSpDefense(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetThickClubHandlers(int *count);
void HAND_ITEM_ThickClub_DoubleAttack(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetChoiceBandHandlers(int *count);
void HAND_ITEM_ChoiceBand_BoostAttack(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetChoiceSpecsHandlers(int *count);
void HAND_ITEM_ChoiceSpecs_BoostSpAttack(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetChoiceScarfHandlers(int *count);
void HAND_ITEM_ChoiceScarf_BoostSpeed(struct BtlEventFactor *factor, void *flow, int pokeId);
void HAND_ITEM_Choice_LockMove(struct BtlEventFactor *factor, void *flow, int pokeId);
void HAND_ITEM_Choice_ReleaseMoveLock(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetFocusSashHandlers(int *count);
void HAND_ITEM_FocusSash_CheckSurvive(struct BtlEventFactor *factor, void *flow, int pokeId, int *work);
void HAND_ITEM_FocusSash_ConsumeAndAnnounce(struct BtlEventFactor *factor, void *flow, int pokeId, int *work);
int *HAND_ITEM_GetFocusBandHandlers(int *count);
void HAND_ITEM_FocusBand_CheckSurvive(struct BtlEventFactor *factor, void *flow, int pokeId, int *work);
void HAND_ITEM_FocusBand_UseItem(struct BtlEventFactor *factor, void *flow, int pokeId, int *work);
void HAND_ITEM_FocusBand_ShowMessage(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetExpertBeltHandlers(int *count);
void HAND_ITEM_ExpertBelt_BoostSuperEffective(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetLifeOrbHandlers(int *count);
void HAND_ITEM_LifeOrb_RecoilDamage(struct BtlEventFactor *factor, void *flow, int pokeId);
void HAND_ITEM_LifeOrb_BoostDamage(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetMetronomeHandlers(int *count);
void HAND_ITEM_Metronome_BoostConsecutiveUse(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetGripClawHandlers(int *count);
void HAND_ITEM_GripClaw_ExtendBind(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetShellBellHandlers(int *count);
void HAND_ITEM_ShellBell_HealFromDamage(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetLightClayHandlers(int *count);
void HAND_ITEM_LightClay_ExtendScreen(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetPowerHerbHandlers(int *count);
void HAND_ITEM_PowerHerb_CheckSkipCharge(struct BtlEventFactor *factor, void *flow, int pokeId, int *work);
void HAND_ITEM_PowerHerb_UseItem(struct BtlEventFactor *factor, void *flow, int pokeId, int *work);
void HAND_ITEM_PowerHerb_ShowMessage(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetLeftoversHandlers(int *count);
void HAND_ITEM_Leftovers_TriggerOnTurnEnd(struct BtlEventFactor *factor, void *flow, int pokeId);
void HAND_ITEM_Leftovers_Heal(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetBlackSludgeHandlers(int *count);
void HAND_ITEM_BlackSludge_HealOrDamage(struct BtlEventFactor *factor, void *flow, int pokeId);
void *HAND_ITEM_GetDestinyKnotHandlers(int *count);
void HAND_ITEM_DestinyKnot_Infatuate(struct BtlEventFactor *factor, void *flow, int pokeId);
void *HAND_ITEM_GetStickyBarbHandlers(int *count);
void HAND_ITEM_StickyBarb_Transfer(struct BtlEventFactor *factor, void *flow, int pokeId);
void HAND_ITEM_StickyBarb_TurnEndDamage(struct BtlEventFactor *factor, void *flow, int pokeId);
void *HAND_ITEM_GetPowerWeightHandlers(int *count);
void *HAND_ITEM_GetPowerBracerHandlers(int *count);
void *HAND_ITEM_GetPowerBeltHandlers(int *count);
void *HAND_ITEM_GetPowerLensHandlers(int *count);
void *HAND_ITEM_GetPowerBandHandlers(int *count);
void *HAND_ITEM_GetPowerAnkletHandlers(int *count);
void HAND_ITEM_PowerItem_HalveSpeed(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetFlamePlateHandlers(int *count);
int *HAND_ITEM_GetSplashPlateHandlers(int *count);
int *HAND_ITEM_GetZapPlateHandlers(int *count);
int *HAND_ITEM_GetMeadowPlateHandlers(int *count);
int *HAND_ITEM_GetIciclePlateHandlers(int *count);
int *HAND_ITEM_GetFistPlateHandlers(int *count);
int *HAND_ITEM_GetToxicPlateHandlers(int *count);
int *HAND_ITEM_GetEarthPlateHandlers(int *count);
int *HAND_ITEM_GetSkyPlateHandlers(int *count);
int *HAND_ITEM_GetMindPlateHandlers(int *count);
int *HAND_ITEM_GetInsectPlateHandlers(int *count);
int *HAND_ITEM_GetStonePlateHandlers(int *count);
int *HAND_ITEM_GetSpookyPlateHandlers(int *count);
int *HAND_ITEM_GetDracoPlateHandlers(int *count);
int *HAND_ITEM_GetDreadPlateHandlers(int *count);
int *HAND_ITEM_GetIronPlateHandlers(int *count);
int *HAND_ITEM_GetBigRootHandlers(int *count);
void HAND_ITEM_BigRoot_BoostDrain(struct BtlEventFactor *factor, void *flow, int pokeId);
int *HAND_ITEM_GetSmokeBallHandlers(int *count);
void HAND_ITEM_SmokeBall_AllowEscape(struct BtlEventFactor *factor, void *flow, int pokeId, void *work);
void HAND_ITEM_SmokeBallShowEscapeMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetAmuletCoinHandlers(int *handlerCount);
void HAND_ITEM_AmuletCoinFlagDoublePrizeOnEnter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_AmuletCoinFlagDoublePrizeOnEnterDone(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetGriseousOrbHandlers(int *handlerCount);
void HAND_ITEM_GriseousOrbBoostDragonGhostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetIcyRockHandlers(int *handlerCount);
void HAND_ITEM_IcyRockExtendHail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetSmoothRockHandlers(int *handlerCount);
void HAND_ITEM_SmoothRockExtendSandstorm(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetHeatRockHandlers(int *handlerCount);
void HAND_ITEM_HeatRockExtendSunshine(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetDampRockHandlers(int *handlerCount);
void HAND_ITEM_DampRockExtendRain(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_ExtendWeatherTurns(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int weather);
const BtlEventHandler *HAND_ITEM_GetLightBallHandlers(int *handlerCount);
void HAND_ITEM_LightBallDoublePikachuAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_LightBallFlingParalyze(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetToxicOrbHandlers(int *handlerCount);
void HAND_ITEM_ToxicOrbPoisonHolderOnTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_ToxicOrbFlingPoison(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetFlameOrbHandlers(int *handlerCount);
void HAND_ITEM_FlameOrbBurnHolderOnTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_FlameOrbFlingBurn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetSilverPowderHandlers(int *handlerCount);
void HAND_ITEM_SilverPowderBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetSoftSandHandlers(int *handlerCount);
void HAND_ITEM_SoftSandBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetHardStoneHandlers(int *handlerCount);
void HAND_ITEM_HardStoneBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetMiracleSeedHandlers(int *handlerCount);
void HAND_ITEM_MiracleSeedBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetBlackGlassesHandlers(int *handlerCount);
void HAND_ITEM_BlackGlassesBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetBlackBeltHandlers(int *handlerCount);
void HAND_ITEM_BlackBeltBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetMagnetHandlers(int *handlerCount);
void HAND_ITEM_MagnetBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetMetalCoatHandlers(int *handlerCount);
void HAND_ITEM_MetalCoatBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetMysticWaterHandlers(int *handlerCount);
void HAND_ITEM_MysticWaterBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetSharpBeakHandlers(int *handlerCount);
void HAND_ITEM_SharpBeakBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetPoisonBarbHandlers(int *handlerCount);
void HAND_ITEM_PoisonBarbBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_PoisonBarbFlingPoison(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetNeverMeltIceHandlers(int *handlerCount);
void HAND_ITEM_NeverMeltIceBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetSpellTagHandlers(int *handlerCount);
void HAND_ITEM_SpellTagBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetTwistedSpoonHandlers(int *handlerCount);
void HAND_ITEM_TwistedSpoonBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetCharcoalHandlers(int *handlerCount);
void HAND_ITEM_CharcoalBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetDragonFangHandlers(int *handlerCount);
void HAND_ITEM_DragonFangBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetSilkScarfHandlers(int *handlerCount);
void HAND_ITEM_SilkScarfBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetOddIncenseHandlers(int *handlerCount);
void HAND_ITEM_OddIncenseBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetRockIncenseHandlers(int *handlerCount);
void HAND_ITEM_RockIncenseBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetSeaIncenseHandlers(int *handlerCount);
void HAND_ITEM_SeaIncenseBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetWaveIncenseHandlers(int *handlerCount);
void HAND_ITEM_WaveIncenseBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
const BtlEventHandler *HAND_ITEM_GetRoseIncenseHandlers(int *handlerCount);
void HAND_ITEM_RoseIncenseBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_BoostMovePowerOfType(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int moveType);
const BtlEventHandler *HAND_ITEM_GetLustrousOrbHandlers(int *handlerCount);
void HAND_ITEM_LustrousOrbMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_ITEM_GetAdamantOrbHandlers(int *handlerCount);
void HAND_ITEM_AdamantOrbMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_ITEM_GetIronBallHandlers(int *handlerCount);
void HAND_ITEM_IronBallSpeedRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_IronBallGroundCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_ITEM_GetFloatStoneHandlers(int *handlerCount);
void HAND_ITEM_FloatStoneWeightRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_ITEM_GetEvioliteHandlers(int *handlerCount);
void HAND_ITEM_EvioliteDefenseRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_ITEM_GetRockyHelmetHandlers(int *handlerCount);
void HAND_ITEM_RockyHelmetDamageReaction(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_ITEM_GetAirBalloonHandlers(int *handlerCount);
void HAND_ITEM_AirBalloonEnterField(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_AirBalloonGroundCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_AirBalloonPop(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_ITEM_GetRedCardHandlers(int *handlerCount);
void HAND_ITEM_RedCardForceSwitch(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_ITEM_GetRingTargetHandlers(int *handlerCount);
void HAND_ITEM_RingTargetImmunityOverride(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_ITEM_GetBindingBandHandlers(int *handlerCount);
void HAND_ITEM_BindingBandSickCont(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_ITEM_GetAbsorbBulbHandlers(int *handlerCount);
void HAND_ITEM_AbsorbBulbDamageReaction(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_AbsorbBulbUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_ITEM_GetCellBatteryHandlers(int *handlerCount);
void HAND_ITEM_CellBatteryDamageReaction(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_CellBatteryUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_ITEM_GetEjectButtonHandlers(int *handlerCount);
void HAND_ITEM_EjectButtonAfterDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_ITEM_EjectButtonUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
BtlEventHandler *HAND_ITEM_GetFireGemHandlers(int *handlerCount);
void HAND_ITEM_FireGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_FireGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_ITEM_GetWaterGemHandlers(int *handlerCount);
void HAND_ITEM_WaterGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_WaterGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_ITEM_GetElectricGemHandlers(int *handlerCount);
void HAND_ITEM_ElectricGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_ElectricGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_ITEM_GetGrassGemHandlers(int *handlerCount);
void HAND_ITEM_GrassGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_GrassGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_ITEM_GetIceGemHandlers(int *handlerCount);
void HAND_ITEM_IceGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_IceGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_ITEM_GetFightingGemHandlers(int *handlerCount);
void HAND_ITEM_FightingGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_FightingGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_ITEM_GetPoisonGemHandlers(int *handlerCount);
void HAND_ITEM_PoisonGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_PoisonGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_ITEM_GetGroundGemHandlers(int *handlerCount);
void HAND_ITEM_GroundGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_GroundGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_ITEM_GetFlyingGemHandlers(int *handlerCount);
void HAND_ITEM_FlyingGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_FlyingGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_ITEM_GetPsychicGemHandlers(int *handlerCount);
void HAND_ITEM_PsychicGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_PsychicGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_ITEM_GetBugGemHandlers(int *handlerCount);
void HAND_ITEM_BugGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_BugGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_ITEM_GetRockGemHandlers(int *handlerCount);
void HAND_ITEM_RockGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_RockGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_ITEM_GetGhostGemHandlers(int *handlerCount);
void HAND_ITEM_GhostGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_GhostGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_ITEM_GetDragonGemHandlers(int *handlerCount);
void HAND_ITEM_DragonGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_DragonGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_ITEM_GetDarkGemHandlers(int *handlerCount);
void HAND_ITEM_DarkGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_DarkGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_ITEM_GetSteelGemHandlers(int *handlerCount);
void HAND_ITEM_SteelGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_SteelGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_ITEM_GetNormalGemHandlers(int *handlerCount);
void HAND_ITEM_NormalGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_NormalGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_ITEM_GemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work, u8 gemType);
extern int gBtlItemFlavorHealAttackHandlers[];
extern int gBtlItemFlavorHealDefenseHandlers[];
extern int gBtlItemFlavorHealSpeedHandlers[];
extern int gBtlItemFlavorHealSpAttackHandlers[];
extern int gBtlItemFlavorHealSpDefenseHandlers[];
extern int gBtlItemRaiseAttackOneHandlers[];
extern int gBtlItemRaiseDefenseOneHandlers[];
extern int gBtlItemRaiseSpeedOneHandlers[];
extern int gBtlItemRaiseSpAttackOneHandlers[];
extern int gBtlItemRaiseSpDefenseOneHandlers[];
extern int gBtlItemRaiseCriticalRateHandlers[];
extern u8 gBtlItemRaiseStatCandidates[BTL_RANK_KIND_COUNT];
extern int gBtlItemRaiseRandomStatHandlers[];
extern int gBtlItemSuperEffectiveHitRecoverHandlers[];
extern int gBtlItemWeakenDamageFireHandlers[];
extern int gBtlItemWeakenDamageWaterHandlers[];
extern int gBtlItemWeakenDamageElectricHandlers[];
extern int gBtlItemWeakenDamageGrassHandlers[];
extern int gBtlItemWeakenDamageIceHandlers[];
extern int gBtlItemWeakenDamageFightingHandlers[];
extern int gBtlItemWeakenDamagePoisonHandlers[];
extern int gBtlItemWeakenDamageGroundHandlers[];
extern int gBtlItemWeakenDamageFlyingHandlers[];
extern int gBtlItemWeakenDamagePsychicHandlers[];
extern int gBtlItemWeakenDamageBugHandlers[];
extern int gBtlItemWeakenDamageRockHandlers[];
extern int gBtlItemWeakenDamageGhostHandlers[];
extern int gHabanBerryHandlers[];
extern int gColburBerryHandlers[];
extern int gBabiriBerryHandlers[];
extern int gChilanBerryHandlers[];
extern int gCustapBerryHandlers[];
extern u8 gJabocaBerryHandlers[];
extern int gMicleBerryHandlers[];
extern int gRowapBerryHandlers[];
extern u8 gMentalHerbHandlers[];
extern u8 gBrightPowderHandlers[];
extern int gWhiteHerbHandlers[];
extern int gMachoBraceHandlers[];
extern u8 gQuickClawHandlers[];
extern int gLaggingTailHandlers[];
/*
 * extent: two-byte alignment padding at 021DE4F2.
 * lever: u8 result local narrows in r0 before copying to r1; twin 021DE3FC.
 */
extern int gKingsRockHandlers[];
extern u8 gScopeLensHandlers[];
extern u8 gLuckyPunchHandlers[];
extern int gStickHandlers;
extern int gZoomLensHandlers;
extern int gRazorFangHandlers[];
extern int gWideLensHandlers[];
extern int gLaxIncenseHandlers;
extern int gMuscleBandHandlers;
extern int gWiseGlassesHandlers;
extern int gDeepSeaToothHandlers;
extern int gDeepSeaScaleHandlers;
extern int gMetalPowderHandlers;
extern int gQuickPowderHandlers;
extern int gSoulDewHandlers;
extern int gThickClubHandlers;
extern int gChoiceBandHandlers;
extern int gChoiceSpecsHandlers;
extern int gChoiceScarfHandlers;
extern int gFocusSashHandlers;
extern int gFocusBandHandlers;
extern int gExpertBeltHandlers[];
extern int gLifeOrbHandlers;
extern int gMetronomeHandlers;
extern int gGripClawHandlers;
extern int gShellBellHandlers[];
extern int gLightClayHandlers[];
extern int gPowerHerbHandlers[];
extern int gLeftoversHandlers[];
extern int gBlackSludgeHandlers[];
extern u8 gDestinyKnotHandlers[];
extern unsigned char gStickyBarbHandlers[];
extern u8 gPowerWeightHandlers[], gPowerBracerHandlers[], gPowerBeltHandlers[], gPowerLensHandlers[], gPowerBandHandlers[], gPowerAnkletHandlers[];
extern int gFlamePlateHandlers[];
extern int gSplashPlateHandlers[];
extern int gZapPlateHandlers[];
extern int gMeadowPlateHandlers[];
extern int gIciclePlateHandlers[];
extern int gFistPlateHandlers[];
extern int gToxicPlateHandlers[];
extern int gEarthPlateHandlers[];
extern int gSkyPlateHandlers[];
extern int gMindPlateHandlers[];
extern int gInsectPlateHandlers[];
extern int gStonePlateHandlers[];
extern int gSpookyPlateHandlers[];
extern int gDracoPlateHandlers[];
extern int gDreadPlateHandlers[];
extern int gIronPlateHandlers[];
extern int gBigRootHandlers[];
extern int gSmokeBallHandlers[];
extern const BtlEventHandler gAmuletCoinHandlers[];
extern const BtlEventHandler gGriseousOrbHandlers[];
extern const BtlEventHandler gIcyRockHandlers[];
extern const BtlEventHandler gSmoothRockHandlers[];
extern const BtlEventHandler gHeatRockHandlers[];
extern const BtlEventHandler gDampRockHandlers[];
extern const BtlEventHandler gLightBallHandlers[];
extern const BtlEventHandler gToxicOrbHandlers[];
extern const BtlEventHandler gFlameOrbHandlers[];
extern const BtlEventHandler gSilverPowderHandlers[];
extern const BtlEventHandler gSoftSandHandlers[];
extern const BtlEventHandler gHardStoneHandlers[];
extern const BtlEventHandler gMiracleSeedHandlers[];
extern const BtlEventHandler gBlackGlassesHandlers[];
extern const BtlEventHandler gBlackBeltHandlers[];
extern const BtlEventHandler gMagnetHandlers[];
extern const BtlEventHandler gMetalCoatHandlers[];
extern const BtlEventHandler gMysticWaterHandlers[];
extern const BtlEventHandler gSharpBeakHandlers[];
extern const BtlEventHandler gPoisonBarbHandlers[];
extern const BtlEventHandler gNeverMeltIceHandlers[];
extern const BtlEventHandler gSpellTagHandlers[];
extern const BtlEventHandler gTwistedSpoonHandlers[];
extern const BtlEventHandler gCharcoalHandlers[];
extern const BtlEventHandler gDragonFangHandlers[];
extern const BtlEventHandler gSilkScarfHandlers[];
extern const BtlEventHandler gOddIncenseHandlers[];
extern const BtlEventHandler gRockIncenseHandlers[];
extern const BtlEventHandler gSeaIncenseHandlers[];
extern const BtlEventHandler gWaveIncenseHandlers[];
extern const BtlEventHandler gRoseIncenseHandlers[];
extern const BtlEventHandler gLustrousOrbHandlers[];
extern BtlEventHandler gBtlHandlerItemAdamantOrbHandlers[];
extern BtlEventHandler gBtlHandlerItemIronBallHandlers[];
extern BtlEventHandler gBtlHandlerItemFloatStoneHandlers[];
extern BtlEventHandler gBtlHandlerItemEvioliteHandlers[];
extern BtlEventHandler gBtlHandlerItemRockyHelmetHandlers[];
extern BtlEventHandler gBtlHandlerItemAirBalloonHandlers[];
extern BtlEventHandler gBtlHandlerItemRedCardHandlers[];
extern BtlEventHandler gBtlHandlerItemRingTargetHandlers[];
extern BtlEventHandler gBtlHandlerItemBindingBandHandlers[];
extern BtlEventHandler gHandItemAbsorbBulbHandlers[];
extern BtlEventHandler gHandItemCellBatteryHandlers[];
extern BtlEventHandler gHandItemEjectButtonHandlers[];
extern BtlEventHandler gHandItemFireGemHandlers[];
extern BtlEventHandler gHandItemWaterGemHandlers[];
extern BtlEventHandler gHandItemElectricGemHandlers[];
extern BtlEventHandler gHandItemGrassGemHandlers[];
extern BtlEventHandler gHandItemIceGemHandlers[];
extern BtlEventHandler gHandItemFightingGemHandlers[];
extern BtlEventHandler gHandItemPoisonGemHandlers[];
extern BtlEventHandler gHandItemGroundGemHandlers[];
extern BtlEventHandler gHandItemFlyingGemHandlers[];
extern BtlEventHandler gHandItemPsychicGemHandlers[];
extern BtlEventHandler gHandItemBugGemHandlers[];
extern BtlEventHandler gHandItemRockGemHandlers[];
extern BtlEventHandler gHandItemGhostGemHandlers[];
extern BtlEventHandler gHandItemDragonGemHandlers[];
extern BtlEventHandler gHandItemDarkGemHandlers[];
extern BtlEventHandler gHandItemSteelGemHandlers[];
extern BtlEventHandler gHandItemNormalGemHandlers[];


void HAND_ITEM_RecoverHpPercentOfMaxHp(struct BtlEventFactor *factor, void *server, int pokeId)
{
    HandExRecoverHp *cmd;
    int maxHp;
    u8 percent;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    maxHp = BTL_POKEPARAM_GetValue(BTL_SERVER_FLOW_GetPokeParam(server, pokeId), BTL_VALUE_MAX_HP);
    percent = (u8)HAND_ITEM_GetParam(factor, 2);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(server, HANDEX_KIND_RECOVER_HP, pokeId);
    cmd->pokeId = pokeId;
    cmd->amount = func_0209C2B0(maxHp * percent, 100);
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HANDEX_STR_SET, 908);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, BTL_EVENT_GetFactorKey(factor));
    BTL_SERVER_FLOW_CommitCmdRecord(server, cmd);
}


int *HAND_ITEM_GetFlavorHealAttackHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gBtlItemFlavorHealAttackHandlers;
}


void HAND_ITEM_FlavorHealAttack(struct BtlEventFactor *factor, void *server, int pokeId, int *work) { HAND_ITEM_FlavorHeal(factor, server, pokeId, work, 0); }


void HAND_ITEM_FlavorHealAttackIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) HAND_ITEM_FlavorHeal(factor, server, pokeId, work, 0);
}


int *HAND_ITEM_GetFlavorHealDefenseHandlers(int *handlerCount) { *handlerCount = 5; return gBtlItemFlavorHealDefenseHandlers; }


void HAND_ITEM_FlavorHealDefense(struct BtlEventFactor *factor, void *server, int pokeId, int *work) { HAND_ITEM_FlavorHeal(factor, server, pokeId, work, 1); }


void HAND_ITEM_FlavorHealDefenseIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) HAND_ITEM_FlavorHeal(factor, server, pokeId, work, 1);
}


int *HAND_ITEM_GetFlavorHealSpeedHandlers(int *handlerCount) { *handlerCount = 5; return gBtlItemFlavorHealSpeedHandlers; }


void HAND_ITEM_FlavorHealSpeed(struct BtlEventFactor *factor, void *server, int pokeId, int *work) { HAND_ITEM_FlavorHeal(factor, server, pokeId, work, 2); }


void HAND_ITEM_FlavorHealSpeedIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) HAND_ITEM_FlavorHeal(factor, server, pokeId, work, 2);
}


int *HAND_ITEM_GetFlavorHealSpAttackHandlers(int *handlerCount) { *handlerCount = 5; return gBtlItemFlavorHealSpAttackHandlers; }


void HAND_ITEM_FlavorHealSpAttack(struct BtlEventFactor *factor, void *server, int pokeId, int *work) { HAND_ITEM_FlavorHeal(factor, server, pokeId, work, 3); }


void HAND_ITEM_FlavorHealSpAttackIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) HAND_ITEM_FlavorHeal(factor, server, pokeId, work, 3);
}


int *HAND_ITEM_GetFlavorHealSpDefenseHandlers(int *handlerCount) { *handlerCount = 5; return gBtlItemFlavorHealSpDefenseHandlers; }


void HAND_ITEM_FlavorHealSpDefense(struct BtlEventFactor *factor, void *server, int pokeId, int *work) { HAND_ITEM_FlavorHeal(factor, server, pokeId, work, 4); }


void HAND_ITEM_FlavorHealSpDefenseIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) HAND_ITEM_FlavorHeal(factor, server, pokeId, work, 4);
}


void HAND_ITEM_RequestUseAtHalfHpChecked(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_USED] == 0 && BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(server, pokeId), BTL_SICK_ITEM_BLOCK) == 0) HAND_ITEM_HpBerryCheckAndUse(factor, server, pokeId, 2, 1);
}


void HAND_ITEM_RequestUseAtHalfHp(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_USED] == 0 && BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(server, pokeId), BTL_SICK_ITEM_BLOCK) == 0) HAND_ITEM_HpBerryCheckAndUse(factor, server, pokeId, 2, 0);
}


void HAND_ITEM_RequestUseAtHalfHpDirect(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_USED] == 0 && BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(server, pokeId), BTL_SICK_ITEM_BLOCK) == 0 && HAND_ITEM_IsHpAtOrBelowFraction(server, pokeId, 2) != 0) HAND_ITEM_PushUseItem(factor, server, pokeId);
}


void HAND_ITEM_FlavorHeal(struct BtlEventFactor *factor, void *server, int pokeId, int *work, int statIndex)
{
    struct BtlPokeParam *pokeParam;
    HandExRecoverHp *healCmd;
    HandExAddSick *sickCmd;

    if (work[ITEM_WORK_USED] == 0 && pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        pokeParam = BTL_SERVER_FLOW_GetPokeParam(server, pokeId);
        healCmd = BTL_SERVER_FLOW_AllocCmdRecord(server, HANDEX_KIND_RECOVER_HP, pokeId);
        healCmd->pokeId = pokeId;
        healCmd->amount = BTL_CALC_DivideMaxHpMin1(pokeParam, HAND_ITEM_GetParam(factor, 2));
        BTL_SERVER_FLOW_InitMsgRecord(&healCmd->message, HANDEX_STR_SET, 908);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&healCmd->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&healCmd->message, BTL_EVENT_GetFactorKey(factor));
        BTL_SERVER_FLOW_CommitCmdRecord(server, healCmd);
        if (POKE_TOOL_GetNatureStatMod(BTL_POKEPARAM_GetMon(pokeParam), statIndex) == -1) {
            sickCmd = BTL_SERVER_FLOW_AllocCmdRecord(server, HANDEX_KIND_ADD_SICK, pokeId);
            sickCmd->pokeId = pokeId;
            sickCmd->sickKind = BTL_SICK_CONFUSION;
            BTL_CALC_MakeSickContFromKind(BTL_SICK_CONFUSION, pokeParam, &sickCmd->sickCont);
            BTL_SERVER_FLOW_CommitCmdRecord(server, sickCmd);
        }
        work[ITEM_WORK_USED] = 1;
    }
}


int *HAND_ITEM_GetRaiseAttackOneHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gBtlItemRaiseAttackOneHandlers;
}


void HAND_ITEM_RaiseAttackOne(struct BtlEventFactor *factor, void *server, int pokeId)
{
    HAND_ITEM_RaiseStat(server, pokeId, BTL_RANK_ATTACK, 1);
}


int *HAND_ITEM_GetRaiseDefenseOneHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gBtlItemRaiseDefenseOneHandlers;
}


void HAND_ITEM_RaiseDefenseOne(struct BtlEventFactor *factor, void *server, int pokeId)
{
    HAND_ITEM_RaiseStat(server, pokeId, BTL_RANK_DEFENSE, 1);
}


int *HAND_ITEM_GetRaiseSpeedOneHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gBtlItemRaiseSpeedOneHandlers;
}


void HAND_ITEM_RaiseSpeedOne(struct BtlEventFactor *factor, void *server, int pokeId)
{
    HAND_ITEM_RaiseStat(server, pokeId, BTL_RANK_SPEED, 1);
}


int *HAND_ITEM_GetRaiseSpAttackOneHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gBtlItemRaiseSpAttackOneHandlers;
}


void HAND_ITEM_RaiseSpAttackOne(struct BtlEventFactor *factor, void *server, int pokeId)
{
    HAND_ITEM_RaiseStat(server, pokeId, BTL_RANK_SP_ATTACK, 1);
}


int *HAND_ITEM_GetRaiseSpDefenseOneHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gBtlItemRaiseSpDefenseOneHandlers;
}


void HAND_ITEM_RaiseSpDefenseOne(struct BtlEventFactor *factor, void *server, int pokeId)
{
    HAND_ITEM_RaiseStat(server, pokeId, BTL_RANK_SP_DEFENSE, 1);
}


int *HAND_ITEM_GetRaiseCriticalRateHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gBtlItemRaiseCriticalRateHandlers;
}


void HAND_ITEM_RaiseCriticalRate(struct BtlEventFactor *factor, void *server, int pokeId)
{
    HandExSetContFlag *flagCmd;
    HandExMessage *messageCmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(server, pokeId), BTL_CONT_FLAG_CRITICAL_UP) != 0)
        return;
    flagCmd = BTL_SERVER_FLOW_AllocCmdRecord(server, HANDEX_KIND_SET_CONT_FLAG, pokeId);
    flagCmd->pokeId = pokeId;
    flagCmd->contFlag = BTL_CONT_FLAG_CRITICAL_UP;
    BTL_SERVER_FLOW_CommitCmdRecord(server, flagCmd);
    messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(server, HANDEX_KIND_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->message, HANDEX_STR_SET, 1001);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->message, pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->message, BTL_EVENT_GetFactorKey(factor));
    BTL_SERVER_FLOW_CommitCmdRecord(server, messageCmd);
}


int *HAND_ITEM_GetRaiseRandomStatHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gBtlItemRaiseRandomStatHandlers;
}


void HAND_ITEM_RaiseRandomStatTwo(struct BtlEventFactor *factor, void *server, u8 pokeId)
{
    struct BtlPokeParam *pokeParam = BTL_SERVER_FLOW_GetPokeParam(server, pokeId);
    u8 *candidates = BTL_SERVER_FLOW_GetScratchBuffer(server, BTL_RANK_KIND_COUNT);
    u32 candidateCount;
    u32 i;
    u8 statId;

    i = 0;
    candidateCount = 0;
    for (; i < BTL_RANK_KIND_COUNT; i++) {
        statId = gBtlItemRaiseStatCandidates[i];
        if (BTL_POKEPARAM_CanChangeStatStage(pokeParam, statId, 1) != 0)
            candidates[candidateCount++] = statId;
    }
    if (candidateCount != 0)
        HAND_ITEM_RaiseStat(server, pokeId, candidates[BTL_CALC_Random(candidateCount)], 2);
}


void HAND_ITEM_RaiseStat(void *server, int pokeId, int statId, int amount)
{
    HandExRankChange *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(server, HANDEX_KIND_RANK_EFFECT, pokeId);
        cmd->rankKind = statId;
        cmd->volume = amount;
        cmd->targetCount = 1;
        cmd->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(server, cmd);
    }
}


int *HAND_ITEM_GetSuperEffectiveHitRecoverHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemSuperEffectiveHitRecoverHandlers;
}


void HAND_ITEM_RequestUseOnSuperEffectiveHit(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) == 0
        && BTL_EVENT_GetVar(BTL_EVAR_TYPE_AFFINITY) > BTL_AFFINITY_SUPER_EFFECTIVE_ABOVE
        && BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(server, pokeId), BTL_SICK_ITEM_BLOCK) == 0)
        HAND_ITEM_PushUseItem(factor, server, pokeId);
}


void HAND_ITEM_RecoverHpByMaxHpDivisor(struct BtlEventFactor *factor, void *server, int pokeId)
{
    struct BtlPokeParam *pokeParam;
    HandExRecoverHp *cmd;
    u8 divisor;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        pokeParam = BTL_SERVER_FLOW_GetPokeParam(server, pokeId);
        divisor = HAND_ITEM_GetParam(factor, 2);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(server, HANDEX_KIND_RECOVER_HP, pokeId);
        cmd->pokeId = pokeId;
        cmd->amount = BTL_CALC_DivideMaxHpMin1(pokeParam, divisor);
        BTL_SERVER_FLOW_CommitCmdRecord(server, cmd);
    }
}


int *HAND_ITEM_GetWeakenDamageFireHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageFireHandlers;
}


void HAND_ITEM_WeakenDamageFire(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_FIRE, 0);
}


int *HAND_ITEM_GetWeakenDamageWaterHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageWaterHandlers;
}


void HAND_ITEM_WeakenDamageWater(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_WATER, 0);
}


int *HAND_ITEM_GetWeakenDamageElectricHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageElectricHandlers;
}


void HAND_ITEM_WeakenDamageElectric(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_ELECTRIC, 0);
}


int *HAND_ITEM_GetWeakenDamageGrassHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageGrassHandlers;
}


void HAND_ITEM_WeakenDamageGrass(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_GRASS, 0);
}


int *HAND_ITEM_GetWeakenDamageIceHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageIceHandlers;
}


void HAND_ITEM_WeakenDamageIce(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_ICE, 0);
}


int *HAND_ITEM_GetWeakenDamageFightingHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageFightingHandlers;
}


void HAND_ITEM_WeakenDamageFighting(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_FIGHTING, 0);
}


int *HAND_ITEM_GetWeakenDamagePoisonHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamagePoisonHandlers;
}


void HAND_ITEM_WeakenDamagePoison(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_POISON, 0);
}


int *HAND_ITEM_GetWeakenDamageGroundHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageGroundHandlers;
}


void HAND_ITEM_WeakenDamageGround(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_GROUND, 0);
}


int *HAND_ITEM_GetWeakenDamageFlyingHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageFlyingHandlers;
}


void HAND_ITEM_WeakenDamageFlying(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_FLYING, 0);
}


int *HAND_ITEM_GetWeakenDamagePsychicHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamagePsychicHandlers;
}


void HAND_ITEM_WeakenDamagePsychic(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_PSYCHIC, 0);
}


int *HAND_ITEM_GetWeakenDamageBugHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageBugHandlers;
}


void HAND_ITEM_WeakenDamageBug(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_BUG, 0);
}


int *HAND_ITEM_GetWeakenDamageRockHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageRockHandlers;
}


void HAND_ITEM_WeakenDamageRock(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_ROCK, 0);
}


int *HAND_ITEM_GetWeakenDamageGhostHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageGhostHandlers;
}


/* Kasib Berry: halves a Ghost hit that is super effective. */
void HAND_ITEM_KasibBerryWeakenGhostHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, flow, pokeId, work, POKETYPE_GHOST, 0);
}


/* Handler table getter of Haban Berry. */
int *HAND_ITEM_GetHabanBerryHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gHabanBerryHandlers;
}


/* Haban Berry: halves a Dragon-type hit that is super effective. */
void HAND_ITEM_HabanBerryWeakenDragonHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, flow, pokeId, work, POKETYPE_DRAGON, 0);
}


/* Handler table getter of Colbur Berry. */
int *HAND_ITEM_GetColburBerryHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gColburBerryHandlers;
}


/* Colbur Berry: halves a Dark-type hit that is super effective. */
void HAND_ITEM_ColburBerryWeakenDarkHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, flow, pokeId, work, POKETYPE_DARK, 0);
}


/* Handler table getter of Babiri Berry. */
int *HAND_ITEM_GetBabiriBerryHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBabiriBerryHandlers;
}


/* String ids of the item messages. */
#define STR_ID_RESIST_BERRY_EATEN 219

#define STR_ID_ITEM_ACTED_QUICK 0x401   /* Custap Berry and Quick Claw */


/*
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #8; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl HAND_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 */
/* Babiri Berry: halves a Steel hit that is super effective. */
void HAND_ITEM_BabiriBerryWeakenSteelHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, flow, pokeId, work, POKETYPE_STEEL, 0);
}


/* Handler table getter of Chilan Berry. */
int *HAND_ITEM_GetChilanBerryHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gChilanBerryHandlers;
}


/*
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0; str r4, [sp]; movs r4, #1; str r4, [sp, #4]; bl HAND_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 */
/* Chilan Berry: halves a Normal hit, super effective or not. */
void HAND_ITEM_ChilanBerryWeakenNormalHit(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_WeakenHitOfType(factor, flow, pokeId, work, POKETYPE_NORMAL, 1);
}


/*
 * Common check of the type-resist berries: the holder is the defender, the
 * move has the berry type, the hit is super effective (unless the berry
 * ignores affinity) and it did not land on a substitute. The damage ratio is
 * halved and the work word is set when the berry will show its message.
 */
int HAND_ITEM_WeakenHitOfType(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work, u8 moveType, int ignoreAffinity)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && moveType == BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE)
        && (ignoreAffinity != 0 || BTL_EVENT_GetVar(BTL_EVAR_TYPE_AFFINITY) > BTL_AFFINITY_SUPER_EFFECTIVE_ABOVE)
        && BTL_POKEPARAM_HasSubstitute(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) == 0) {
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_HALF);
        if (BTL_SERVER_FLOW_IsActionCounterSet(flow) == 0)
            *work = 1;
        return 1;
    }
    return 0;
}


/* Resist berry: shows the message that the berry weakened the hit. */
void HAND_ITEM_ShowResistBerryMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HandExItemMessage *record;
    if (*work != 0 && HAND_COMMON_IsMoveTarget(pokeId) != 0) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ITEM_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, HANDEX_STR_SET, STR_ID_RESIST_BERRY_EATEN);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, BTL_EVENT_GetFactorKey(factor));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}


/*
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
/* HP berries, damage event: eat when HP is low, honoring the trigger kind. */
void HAND_ITEM_HpBerryCheckAfterDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        HAND_ITEM_HpBerryCheckAndUse(factor, flow, pokeId, HAND_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE), 1);
    }
}


/* HP berries, turn end event: eat when HP is low (no trigger kind test). */
void HAND_ITEM_HpBerryCheckAtTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        HAND_ITEM_HpBerryCheckAndUse(factor, flow, pokeId, HAND_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE), 0);
    }
}


/* HP berries, use event: eat when HP is low. */
void HAND_ITEM_HpBerryCheckOnUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (HAND_ITEM_IsHpAtOrBelowFraction(flow, pokeId, HAND_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE)) != 0) HAND_ITEM_PushUseItem(factor, flow, pokeId);
}


/* Eats the berry when the holder's HP is at or below 1/fraction. */
void HAND_ITEM_HpBerryCheckAndUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int fraction, int checkTrigger)
{
    int isLow;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (checkTrigger != 0)
            isLow = HAND_ITEM_IsHpLowForTrigger(factor, flow, pokeId, fraction);
        else
            isLow = HAND_ITEM_IsHpAtOrBelowFraction(flow, pokeId, fraction);
        if (isLow != 0)
            HAND_ITEM_PushUseItem(factor, flow, pokeId);
    }
}


/* Same HP test, only when the trigger kind is 0 or 1. */
int HAND_ITEM_IsHpLowForTrigger(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, unsigned int fraction)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && (unsigned char)BTL_EVENT_GetVar(BTL_EVAR_TRIGGER_KIND) <= 1) return HAND_ITEM_IsHpAtOrBelowFraction(flow, pokeId, fraction);
    return 0;
}


/* True when the Pokemon's HP is at or below max HP / fraction (Gluttony halves a fraction above 2). */
int HAND_ITEM_IsHpAtOrBelowFraction(struct BtlServerFlow *flow, int pokeId, u32 fraction)
{
    struct BtlPokeParam *poke;
    u32 hp;

    poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (BTL_POKEPARAM_GetValue(poke, BTL_VALUE_ABILITY) == BTL_ABILITY_GLUTTONY && fraction > 2)
        fraction >>= 1;
    if (fraction == 0)
        fraction = 1;
    if ((u32)BTL_POKEPARAM_GetValue(poke, BTL_VALUE_MAX_HP) > 1) {
        hp = BTL_POKEPARAM_GetValue(poke, BTL_VALUE_HP);
        if (hp <= BTL_CALC_DivideMaxHp(poke, fraction))
            return 1;
    }
    return 0;
}


/* Handler table getter of Custap Berry. */
int *HAND_ITEM_GetCustapBerryHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gCustapBerryHandlers;
}


/* Custap Berry: moves first in its priority bracket when HP is at or below 1/4. */
void HAND_ITEM_CustapBerryMoveFirst(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && HAND_ITEM_IsHpAtOrBelowFraction(flow, pokeId, 4) != 0 && BTL_EVENT_OverwriteVar(BTL_EVAR_ACTION_ORDER, BTL_ACTION_ORDER_FIRST) != 0) HAND_ITEM_PushUseItem(factor, flow, pokeId);
}


/* Custap Berry: shows the message and clears the work word. */
void HAND_ITEM_CustapBerryShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HandExMessage *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, HANDEX_STR_SET, STR_ID_ITEM_ACTED_QUICK);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, BTL_EVENT_GetFactorKey(factor));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
        *work = 0;
    }
}


/* Handler table getter of Micle Berry. */
int *HAND_ITEM_GetMicleBerryHandlers(int *handlerCount)
{
    *handlerCount = 6;
    return gMicleBerryHandlers;
}


/* Micle Berry, switch-in event: eat when HP is low. */
void HAND_ITEM_MicleBerryCheckOnSwitchIn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 fraction;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        fraction = HAND_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE);
        if (HAND_ITEM_IsHpLowForTrigger(factor, flow, pokeId, fraction) != 0)
            HAND_ITEM_PushUseItem(factor, flow, pokeId);
    }
}


/* Micle Berry, damage event: check the holder. */
void HAND_ITEM_MicleBerryCheckAfterDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) HAND_ITEM_MicleBerryCheckHp(factor, flow, pokeId, work);
}


/* Micle Berry, after-action event: check unless the turn phase is 6. */
void HAND_ITEM_MicleBerryCheckAfterAction(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (BTL_EVENT_GetVar(BTL_EVAR_TURN_PHASE) != 6) HAND_ITEM_MicleBerryCheckAfterDamage(factor, flow, pokeId, work);
}


/* Micle Berry: eat when HP is at or below the item fraction. */
void HAND_ITEM_MicleBerryCheckHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    unsigned char fraction;
    BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    fraction = HAND_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE);
    if (HAND_ITEM_IsHpAtOrBelowFraction(flow, pokeId, fraction) != 0) HAND_ITEM_PushUseItem(factor, flow, pokeId);
}


/* Micle Berry, use event: the next move's accuracy rises (status 0x22, 120 percent). */
void HAND_ITEM_MicleBerryRaiseAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HandExAddSickMessage *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
        record->pokeId = pokeId;
        record->sickKind = BTL_SICK_MICLE_ACCURACY;
        record->sickCont.raw = BTLV_CORE_MakeSlotKind1Value(BTL_RATIO_MICLE_ACCURACY);
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, HANDEX_STR_SET, STR_ID_MICLE_ACCURACY);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, BTL_EVENT_GetFactorKey(factor));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}


/* Micle Berry, forced use event (Fling): acts only when the work slot says the item was used from outside. */
void HAND_ITEM_MicleBerryUseWhenForced(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work) { if (work[ITEM_WORK_FORCED_USE]) HAND_ITEM_MicleBerryRaiseAccuracy(factor, flow, pokeId, work); }


/*
 * interface: r3 is untouched before bl; forward its incoming fourth argument.
 * lever: fourth argument keeps r3 live; three arguments give ldr/cmp r3.
 */
/* Handler table getter of Jaboca Berry. */
void *HAND_ITEM_GetJabocaBerryHandlers(int *handlerCount) { *handlerCount=2; return gJabocaBerryHandlers; }


/* Jaboca Berry, hit event: remembers the attacker of a physical hit. */
void HAND_ITEM_JabocaBerryRememberPhysicalAttacker(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work) { HAND_ITEM_RememberAttackerOfCategory(factor, flow, pokeId, work, BTL_MOVE_CATEGORY_PHYSICAL); }



/* Handler table getter of Rowap Berry. */
int *HAND_ITEM_GetRowapBerryHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gRowapBerryHandlers;
}



/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #2; str r4, [sp]; bl HAND_ITEM_RememberAttackerOfCategory; add sp, #4; pop {r3, r4, pc}.
 */
/* Rowap Berry, hit event: remembers the attacker of a special hit. */
void HAND_ITEM_RowapBerryRememberSpecialAttacker(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work) { HAND_ITEM_RememberAttackerOfCategory(factor, flow, pokeId, work, BTL_MOVE_CATEGORY_SPECIAL); }



/*
 * Jaboca and Rowap Berry: when the holder is hit by a move of the berry's
 * category (not through a substitute), store the attacker id plus one in the
 * work word and queue a "keep the item" use record. The hit-back damage is
 * dealt later by the use event.
 */
void HAND_ITEM_RememberAttackerOfCategory(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work, int moveCategory)
{
    HandExUseItem *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) == 0
        && BTL_ID_IsMetronomeItemIgnoredMove(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == 0 && moveCategory == BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE)) {
        BTL_EVENT_KeepFactorRunning(factor);
        *work = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) + 1;
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_USE_ITEM, pokeId);
        record->useFlags |= HANDEX_USE_ITEM_KEEP_ITEM;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}



/*
 * Jaboca and Rowap Berry, use event: the work word holds the attacker id plus
 * one. Damage the attacker for max HP / item divisor unless it has fainted.
 */
void HAND_ITEM_HitBackAttacker(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HandExDamage *record;
    struct BtlPokeParam *attacker;
    u8 attackerId;
    u8 divisor;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *work != 0) {
        attackerId = *work - 1;
        attacker = BTL_SERVER_FLOW_GetPokeParam(flow, attackerId);
        if (BTL_POKEPARAM_IsFainted(attacker) == 0) {
            divisor = HAND_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE);
            record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_DAMAGE, pokeId);
            record->pokeId = attackerId;
            record->amount = BTL_CALC_DivideMaxHpMin1(attacker, divisor);
            BTL_SERVER_FLOW_InitMsgRecord(&record->message, HANDEX_STR_SET, STR_ID_JABOCA_ROWAP_HIT_BACK);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, record->pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, BTL_EVENT_GetFactorKey(factor));
            BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
        }
    }
}



/* Handler table getter of White Herb. */
int *HAND_ITEM_GetWhiteHerbHandlers(int *handlerCount)
{
    *handlerCount = 6;
    return gWhiteHerbHandlers;
}



/*
 * interface: BTL_SERVER_FLOW_GetPokeParam leaves r0 live for the following call; r1 carries pokeId.
 */
/* White Herb: act when the holder has a lowered stat stage. */
void HAND_ITEM_WhiteHerbCheckLoweredStats(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int work) { if (BTL_POKEPARAM_HasLoweredStatStage(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))) HAND_ITEM_PushUseItem(factor, flow, pokeId); }





/*
 * extent: two-byte alignment padding at 021DE26E.
 * interface: original restores r3 from r7 before calling 021DE228.
 */
/* White Herb, after-action event: check unless the turn phase is 6. */
void HAND_ITEM_WhiteHerbCheckAfterAction(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int work) { if (BTL_EVENT_GetVar(BTL_EVAR_TURN_PHASE) != 6) HAND_ITEM_WhiteHerbCheckLoweredStats(factor, flow, pokeId, work); }





/*
 * extent: two-byte alignment padding at 021DE29E.
 * interface: BTL_SERVER_FLOW_GetPokeParam leaves r0 live for the following call; r1 carries pokeId.
 */
/* White Herb, stat change event: act when the holder has a lowered stat stage. */
void HAND_ITEM_WhiteHerbCheckOnStatChange(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId) { if(pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) { if(BTL_POKEPARAM_HasLoweredStatStage(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))) HAND_ITEM_PushUseItem(factor, flow, pokeId); } }





/* White Herb, use event: restores the lowered stat stages and shows the message. */
void HAND_ITEM_WhiteHerbRestoreStats(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HandExRestoreRanks *restore;
    HandExMessage *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        restore = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RESTORE_RANKS, pokeId);
        restore->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, restore);
        message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&message->message, HANDEX_STR_SET, STR_ID_WHITE_HERB_RESTORED);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&message->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&message->message, BTL_EVENT_GetFactorKey(factor));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
    }
}




/* White Herb, forced use event (Fling): acts only when the item was used from outside. */
void HAND_ITEM_WhiteHerbUseWhenForced(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work) { if (work[ITEM_WORK_FORCED_USE]) HAND_ITEM_WhiteHerbRestoreStats(factor, flow, pokeId, work); }




/*
 * interface: r3 is untouched before bl; forward its incoming fourth argument.
 * lever: fourth argument keeps r3 live; three arguments give ldr/cmp r3.
 */
/* Handler table getter of Mental Herb. */
void *HAND_ITEM_GetMentalHerbHandlers(int *handlerCount) { *handlerCount=4; return gMentalHerbHandlers; }




/*
 * extent: two-byte alignment padding at 021DE34A.
 * interface: BTL_SERVER_FLOW_GetPokeParam leaves r0 live for the following call; r1 carries pokeId.
 */
/* Mental Herb: act when the holder has one of the conditions it cures. */
void HAND_ITEM_MentalHerbCheckCondition(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId) { if(pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) { if(BTL_CALC_FindMajorSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))) HAND_ITEM_PushUseItem(factor, flow, pokeId); } }





/* Mental Herb, use event: cures the volatile conditions. */
void HAND_ITEM_MentalHerbCureCondition(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_CureSickOnEaten(factor, flow, pokeId, BTL_SICK_ANY_VOLATILE);
}




/* Mental Herb, forced use event (Fling): acts only when the item was used from outside. */
void HAND_ITEM_MentalHerbUseWhenForced(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work) { if (work[ITEM_WORK_FORCED_USE]) HAND_ITEM_MentalHerbCureCondition(factor, flow, pokeId, work); }




/* Handler table getter of Bright Powder. */
void *HAND_ITEM_GetBrightPowderHandlers(int *handlerCount) { *handlerCount=1; return gBrightPowderHandlers; }


/* Bright Powder, accuracy event: lowers the attacker's accuracy by the item percent (the holder is the defender). */
void HAND_ITEM_BrightPowderLowerAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u32 percentLeft;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        percentLeft = 100 - HAND_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE);
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, (int)(percentLeft > 0 ? (float)(percentLeft << 12) + 0.5f : (float)(percentLeft << 12) - 0.5f) / 100);
    }
}


/* Handler table getter of Macho Brace. */
int *HAND_ITEM_GetMachoBraceHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMachoBraceHandlers;
}

#undef STR_ID_ITEM_ACTED_QUICK

#define STR_ID_ITEM_ACTED_QUICK 0x401   /* Quick Claw and Custap Berry */


/*
 * Macho Brace, speed event: halves the speed ratio. The original reuses the
 * poke id variable key (2) as the shift count, so the ratio is 2 << 10.
 */
void HAND_ITEM_MachoBraceHalveSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId) { int pokeIdVar=BTL_EVAR_POKE_ID; if(pokeId == BTL_EVENT_GetVar(pokeIdVar)) BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, pokeIdVar<<10); }


/* Handler table getter of Quick Claw. */
void *HAND_ITEM_GetQuickClawHandlers(int *handlerCount) { *handlerCount=2; return gQuickClawHandlers; }



/* Quick Claw, action order event: with the item percent chance the holder moves first. */
void HAND_ITEM_QuickClawMoveFirst(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 percent;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        percent = HAND_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE);
        if (HAND_ITEM_RollChance(flow, percent) != 0 && BTL_EVENT_OverwriteVar(BTL_EVAR_ACTION_ORDER, BTL_ACTION_ORDER_FIRST) != 0)
            HAND_ITEM_PushUseItem(factor, flow, pokeId);
    }
}



/* Quick Claw, use event: shows the message and clears the work word. */
void HAND_ITEM_QuickClawShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HandExMessage *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, HANDEX_STR_SET, STR_ID_ITEM_ACTED_QUICK);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, BTL_EVENT_GetFactorKey(factor));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
        *work = 0;
    }
}


/* Handler table getter of Lagging Tail. */
int *HAND_ITEM_GetLaggingTailHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gLaggingTailHandlers;
}




/* 021DE4A0  shape F1: gate on BTL_EVENT_GetVar(2) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #2; adds r4, r2, #0; bl BTL_EVENT_GetVar; cmp r4, r0; bne loc_021DE4B6; movs r0, #0x11; movs r1, #0; bl BTL_EVENT_OverwriteVar; pop {r4, pc}.
 */
/* Lagging Tail, action order event: the holder moves last. */
void HAND_ITEM_LaggingTailMoveLast(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_ACTION_ORDER, BTL_ACTION_ORDER_LAST);
}




/* Handler table getter of King's Rock. */
int *HAND_ITEM_GetKingsRockHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gKingsRockHandlers;
}




/* King's Rock, extra effect chance event: sets the flinch chance to the item percent if no chance is fixed yet. */
void HAND_ITEM_KingsRockSetFlinchChance(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId) { u8 percent; if(pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_EVENT_GetVar(BTL_EVAR_EFFECT_PERCENT_LOCKED)==0) { percent=HAND_ITEM_GetParam(factor,BTL_ITEM_PARAM_VALUE); BTL_EVENT_OverwriteVar(BTL_EVAR_EFFECT_PERCENT,percent); } }





/* King's Rock, forced use event (Fling): the target flinches for sure. */
void HAND_ITEM_KingsRockFlingFlinch(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HandExFlinch *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_FLINCH, pokeId);
        record->pokeId = pokeId;
        record->percent = KINGS_ROCK_FLINCH_PERCENT;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}



/* Handler table getter of Razor Fang (same handlers as King's Rock). */
int *HAND_ITEM_GetRazorFangHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gRazorFangHandlers;
}



/* Handler table getter of Wide Lens. */
int *HAND_ITEM_GetWideLensHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWideLensHandlers;
}



/* Wide Lens, accuracy event: raises the attacker's accuracy by the item percent. */
void HAND_ITEM_WideLensRaiseAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId) { if(pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO,HAND_ITEM_GetBoostRatio(factor)); }



/* Handler table getter of Scope Lens (Razor Claw uses the same table). */
void *HAND_ITEM_GetScopeLensHandlers(int *handlerCount) { *handlerCount=1; return gScopeLensHandlers; }



/*
 * lever: u8 local holds getter result before increment; narrow callee argument.
 */
/* Scope Lens and Razor Claw, critical rank event: raises the critical rank by one. */
void HAND_ITEM_RaiseCriticalRankByOne(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId) { u8 rank; if(pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) { rank=BTL_EVENT_GetVar(BTL_EVAR_CRITICAL_RANK); BTL_EVENT_OverwriteVar(BTL_EVAR_CRITICAL_RANK,(u8)(rank+CRITICAL_RANK_PLUS_ONE)); } }



/* Handler table getter of Lucky Punch. */
void *HAND_ITEM_GetLuckyPunchHandlers(int *handlerCount) { *handlerCount=1; return gLuckyPunchHandlers; }




/* Lucky Punch, critical rank event: raises the critical rank by two when the attacker is a Chansey. */
void HAND_ITEM_LuckyPunchRaiseCriticalRankChansey(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 rank;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) == BTL_SPECIES_CHANSEY) {
            rank = BTL_EVENT_GetVar(BTL_EVAR_CRITICAL_RANK);
            BTL_EVENT_OverwriteVar(BTL_EVAR_CRITICAL_RANK, (u8)(rank + CRITICAL_RANK_PLUS_TWO));
        }
    }
}




/* Handler table getter of Stick. */
int *HAND_ITEM_GetStickHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return &gStickHandlers;
}




/* Stick, critical rank event: raises the critical rank by two when the attacker is a Farfetch'd. */
void HAND_ITEM_StickRaiseCriticalRankFarfetchd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 rank;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) == BTL_SPECIES_FARFETCHD) {
            rank = BTL_EVENT_GetVar(BTL_EVAR_CRITICAL_RANK);
            BTL_EVENT_OverwriteVar(BTL_EVAR_CRITICAL_RANK, (u8)(rank + CRITICAL_RANK_PLUS_TWO));
        }
    }
}




/* Handler table getter of Zoom Lens. */
int *HAND_ITEM_GetZoomLensHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return &gZoomLensHandlers;
}



/* Zoom Lens, accuracy event: raises the accuracy by the item percent when the defender has already acted. */
void HAND_ITEM_ZoomLensRaiseAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 defenderId;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        defenderId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        if (BTL_POKEPARAM_TestTurnFlag(BTL_SERVER_FLOW_GetPokeParam(flow, defenderId), TURN_FLAG_ACTED) != 0)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, HAND_ITEM_GetBoostRatio(factor));
    }
}



/* Handler table getter of Lax Incense. */
int *HAND_ITEM_GetLaxIncenseHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return &gLaxIncenseHandlers;
}



/* Lax Incense, accuracy event: lowers the attacker's accuracy by the item percent (the holder is the defender). */
void HAND_ITEM_LaxIncenseLowerAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u16 percentLeft;
    float ratio;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        percentLeft = 100 - HAND_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE);
        if (percentLeft != 0)
            ratio = 0.5f + (float)(percentLeft << 12);
        else
            ratio = (float)(percentLeft << 12) - 0.5f;
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, (int)ratio / 100);
    }
}



/* Handler table getter of Muscle Band. */
int *HAND_ITEM_GetMuscleBandHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return &gMuscleBandHandlers;
}



/* Muscle Band, move power event: boosts physical moves by the item percent. */
void HAND_ITEM_MuscleBandBoostPhysical(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == BTL_MOVE_CATEGORY_PHYSICAL)
            BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, HAND_ITEM_GetBoostRatio(factor));
    }
}



/* Handler table getter of Wise Glasses. */
int *HAND_ITEM_GetWiseGlassesHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return &gWiseGlassesHandlers;
}



/* Wise Glasses, move power event: boosts special moves by the item percent. */
void HAND_ITEM_WiseGlassesBoostSpecial(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == BTL_MOVE_CATEGORY_SPECIAL)
            BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, HAND_ITEM_GetBoostRatio(factor));
    }
}



/* Handler table getter of Deep Sea Tooth. */
int *HAND_ITEM_GetDeepSeaToothHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return &gDeepSeaToothHandlers;
}



/* Deep Sea Tooth, attack ratio event: doubles the special attack of a Clamperl. */
void HAND_ITEM_DeepSeaToothDoubleSpAtk(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) == BTL_SPECIES_CLAMPERL) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == BTL_MOVE_CATEGORY_SPECIAL)
                BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_DOUBLE);
        }
    }
}



/* Handler table getter of Deep Sea Scale. */
int *HAND_ITEM_GetDeepSeaScaleHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return &gDeepSeaScaleHandlers;
}


/* Deep Sea Scale, defense ratio event: doubles the special defense of a Clamperl (the holder is the defender). */
void HAND_ITEM_DeepSeaScaleDoubleSpDef(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) == BTL_SPECIES_CLAMPERL) {
            if (BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) == BTL_MOVE_CATEGORY_SPECIAL)
                BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_DOUBLE);
        }
    }
}


/* Handler table getter of Metal Powder. */
int *HAND_ITEM_GetMetalPowderHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return &gMetalPowderHandlers;
}


void HAND_ITEM_MetalPowder_DoubleDefense(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *defender;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        defender = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_GetSpecies(defender) == BTL_ITEM_DITTO_SPECIES && BTL_POKEPARAM_IsTransformed(defender) == 0) {
            if (BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) == 1)
                BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, 4 << 11);
        }
    }
}


int *HAND_ITEM_GetQuickPowderHandlers(int *count)
{
    *count = 1;
    return &gQuickPowderHandlers;
}


void HAND_ITEM_QuickPowder_DoubleSpeed(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *pokeParam;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        pokeParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_GetSpecies(pokeParam) == BTL_ITEM_DITTO_SPECIES && BTL_POKEPARAM_IsTransformed(pokeParam) == 0)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, 2 << 12);
    }
}


int *HAND_ITEM_GetSoulDewHandlers(int *count)
{
    *count = 2;
    return &gSoulDewHandlers;
}


/* Soul Dew: Latias and Latios (species 380, 381) get 1.5 times special attack. */
void HAND_ITEM_SoulDew_BoostSpAttack(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if ((u32)BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) - 380 <= 1) {
            if (BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) == 2)
                BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, 6144);
        }
    }
}


/* Soul Dew: the same species get 1.5 times special defense. */
void HAND_ITEM_SoulDew_BoostSpDefense(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if ((u32)BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) - 380 <= 1) {
            if (BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) == 2)
                BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, 6 << 10);
        }
    }
}


int *HAND_ITEM_GetThickClubHandlers(int *count)
{
    *count = 1;
    return &gThickClubHandlers;
}


/* Thick Club: Cubone and Marowak (species 104, 105) double their physical attack. */
void HAND_ITEM_ThickClub_DoubleAttack(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if ((u32)BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) - 0x68 <= 1) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == 1)
                BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, 2 << 12);
        }
    }
}


int *HAND_ITEM_GetChoiceBandHandlers(int *count)
{
    *count = 3;
    return &gChoiceBandHandlers;
}


/* Choice Band: 1.5 times power for physical moves. */
void HAND_ITEM_ChoiceBand_BoostAttack(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == 1)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, 6144);
    }
}


int *HAND_ITEM_GetChoiceSpecsHandlers(int *count)
{
    *count = 3;
    return &gChoiceSpecsHandlers;
}


/* Choice Specs: 1.5 times power for special moves. */
void HAND_ITEM_ChoiceSpecs_BoostSpAttack(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == 2)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, 6144);
    }
}


int *HAND_ITEM_GetChoiceScarfHandlers(int *count)
{
    *count = 3;
    return &gChoiceScarfHandlers;
}


/* Choice Scarf: 1.5 times speed. */
void HAND_ITEM_ChoiceScarf_BoostSpeed(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, 6144);
}


/* Choice items: lock the holder into the move it just used (anything but Struggle, 0xa5). */
void HAND_ITEM_Choice_LockMove(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    u16 moveId;
    HandExAddSickFull *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
        if (moveId != 0xa5) {
            cmd = (HandExAddSickFull *)BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            cmd->pokeId = pokeId;
            cmd->sickKind = BTL_SICK_MOVE_LOCK;
            cmd->sickCont = BTLV_CORE_MakeSlotKind1Value(moveId);
            cmd->mode = 2;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}


/* Choice items: release the move lock when the holder leaves the field. */
void HAND_ITEM_Choice_ReleaseMoveLock(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    HandExCureSickSlot *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        cmd = (HandExCureSickSlot *)BTL_SERVER_FLOW_AllocCmdRecord(flow, 11, pokeId);
        cmd->sickIndex = BTL_SICK_MOVE_LOCK;
        cmd->pokeId = pokeId;
        cmd->flagA = 1;
        cmd->flagB = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}


int *HAND_ITEM_GetFocusSashHandlers(int *count)
{
    *count = 2;
    return &gFocusSashHandlers;
}


/* Focus Sash: a hit at full HP leaves the holder at 1 HP. */
void HAND_ITEM_FocusSash_CheckSurvive(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (BTL_POKEPARAM_IsHpFull(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)))
            *work = BTL_EVENT_OverwriteVar(BTL_EVAR_ENDURE_REASON, 3);
        else
            *work = 0;
    }
}


/* Focus Sash: consume the item and show its message after it saved the holder. */
void HAND_ITEM_FocusSash_ConsumeAndAnnounce(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    HandExConsumeItem *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *work != 0) {
        cmd = (HandExConsumeItem *)BTL_SERVER_FLOW_AllocCmdRecord(flow, 0x23, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HANDEX_STR_SET, 0x3ef);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, BTL_EVENT_GetFactorKey(factor));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        *work = 0;
    }
}


int *HAND_ITEM_GetFocusBandHandlers(int *count)
{
    *count = 3;
    return &gFocusBandHandlers;
}


/* Focus Band: a random chance (item parameter) to survive a hit with 1 HP. */
void HAND_ITEM_FocusBand_CheckSurvive(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    int chance;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        chance = (unsigned char)HAND_ITEM_GetParam(factor, 2);
        if (HAND_ITEM_RollChance(flow, chance))
            *work = BTL_EVENT_OverwriteVar(BTL_EVAR_ENDURE_REASON, 3);
        else
            *work = 0;
    }
}


/* Focus Band: use the item when it saved the holder. */
void HAND_ITEM_FocusBand_UseItem(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (*work) {
            HAND_ITEM_PushUseItem(factor, flow, pokeId);
            *work = 0;
        }
    }
}


/* Focus Band: show the message that the holder hung on. */
void HAND_ITEM_FocusBand_ShowMessage(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    HandExMessage *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        cmd = (HandExMessage *)BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HANDEX_STR_SET, 0x3ef);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, BTL_EVENT_GetFactorKey(factor));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}


int *HAND_ITEM_GetExpertBeltHandlers(int *count)
{
    *count = 1;
    return gExpertBeltHandlers;
}


/* Expert Belt: a super effective hit (affinity above 3) is boosted by the item's ratio. */
void HAND_ITEM_ExpertBelt_BoostSuperEffective(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_TYPE_AFFINITY) > BTL_AFFINITY_SUPER_EFFECTIVE_ABOVE)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, HAND_ITEM_GetBoostRatio(factor));
    }
}


int *HAND_ITEM_GetLifeOrbHandlers(int *count)
{
    *count = 2;
    return &gLifeOrbHandlers;
}


/* Life Orb: the attacker loses a tenth of its maximum HP after dealing damage. */
void HAND_ITEM_LifeOrb_RecoilDamage(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *attacker;
    HandExLoseHp *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        attacker = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        cmd = (HandExLoseHp *)BTL_SERVER_FLOW_AllocCmdRecord(flow, 7, pokeId);
        cmd->pokeId = pokeId;
        cmd->amount = BTL_CALC_DivideMaxHpMin1(attacker, 10);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HANDEX_STR_SET, 0x3f5);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}


/* Life Orb: the attacker's damage is boosted by the item's ratio. */
void HAND_ITEM_LifeOrb_BoostDamage(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, HAND_ITEM_GetBoostRatio(factor));
}


int *HAND_ITEM_GetMetronomeHandlers(int *count)
{
    *count = 1;
    return &gMetronomeHandlers;
}


/* Metronome: each consecutive use of the same move adds the item's step to the power, up to 200 percent. */
void HAND_ITEM_Metronome_BoostConsecutiveUse(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *attacker;
    u16 streak;
    u16 percent;
    u16 moveId;
    int ratio;
    float scaled;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_ID_IsMetronomeItemIgnoredMove(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == 0) {
            attacker = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
            streak = (int)BTL_POKEPARAM_GetMoveStreak(attacker);
            if (streak >= 1) {
                moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
                if (moveId == BTL_POKEPARAM_GetLastUsedMoveId(attacker)) {
                    percent = streak * HAND_ITEM_GetParam(factor, 2) + 100;
                    if (percent > 200)
                        percent = 200;
                    if (percent != 0)
                        scaled = 0.5f + (float)(percent << 12);
                    else
                        scaled = (float)(percent << 12) - 0.5f;
                    ratio = (int)scaled;
                    BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, ratio / 100);
                }
            }
        }
    }
}


int *HAND_ITEM_GetGripClawHandlers(int *count)
{
    *count = 1;
    return &gGripClawHandlers;
}


/* Grip Claw: a binding status applied by the holder is stretched to the longer duration. */
void HAND_ITEM_GripClaw_ExtendBind(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    int sickCont;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_EVENT_GetVar(BTL_EVAR_SICK_ID) == BTL_SICK_BIND) {
        sickCont = BTL_EVENT_GetVar(BTL_EVAR_SICK_CONT);
        BTLV_CORE_SetSlotIndex((u32 *)&sickCont, 8);
        BTL_EVENT_OverwriteVar(BTL_EVAR_SICK_CONT, sickCont);
    }
}


int *HAND_ITEM_GetShellBellHandlers(int *count)
{
    *count = 1;
    return gShellBellHandlers;
}


/*
 * Shell Bell: after the holder dealt damage (and no other effect blocks it),
 * it recovers the damage divided by the item's parameter, at least 1 HP.
 */
void HAND_ITEM_ShellBell_HealFromDamage(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    int damage, amount;
    HandExRecoverHp *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_SHEER_FORCE_FLAG) != 0)
        return;
    damage = BTL_EVENT_GetVar(BTL_EVAR_DAMAGE);
    if (damage == 0)
        return;
    amount = func_0209C2B0(damage, HAND_ITEM_GetParam(factor, 2));
    if (amount == 0)
        amount = 1;
    cmd = (HandExRecoverHp *)BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RECOVER_HP, pokeId);
    cmd->pokeId = pokeId;
    cmd->amount = amount;
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HANDEX_STR_SET, 0x392);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, BTL_EVENT_GetFactorKey(factor));
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}


int *HAND_ITEM_GetLightClayHandlers(int *count)
{
    *count = 1;
    return gLightClayHandlers;
}


/* Light Clay: a screen set up by the holder lasts the item's parameter in extra turns. */
void HAND_ITEM_LightClay_ExtendScreen(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    int sickCont;
    u8 extraTurns;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && (u32)BTL_EVENT_GetVar(BTL_EVAR_SCREEN_KIND) <= 1) {
        sickCont = BTL_EVENT_GetVar(BTL_EVAR_SICK_CONT);
        extraTurns = HAND_ITEM_GetParam(factor, 2);
        BTLV_CORE_AddSlotIndex((u32 *)&sickCont, extraTurns);
        BTL_EVENT_OverwriteVar(BTL_EVAR_SICK_CONT, sickCont);
    }
}


int *HAND_ITEM_GetPowerHerbHandlers(int *count)
{
    *count = 3;
    return gPowerHerbHandlers;
}


/* Power Herb: a two-turn move (except Sky Drop) skips its charge turn. */
void HAND_ITEM_PowerHerb_CheckSkipCharge(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID) != BTL_MOVE_SKY_DROP) {
            if (BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 1))
                *work = 1;
        }
    }
}


/* Power Herb: use up the item when the charge turn was skipped. */
void HAND_ITEM_PowerHerb_UseItem(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && *work != 0)
        HAND_ITEM_PushUseItem(factor, flow, pokeId);
}


/* Power Herb: show the message that the holder became fully charged. */
void HAND_ITEM_PowerHerb_ShowMessage(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    HandExMessage *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        cmd = (HandExMessage *)BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HANDEX_STR_SET, 0x3fe);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, BTL_EVENT_GetFactorKey(factor));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}


int *HAND_ITEM_GetLeftoversHandlers(int *count)
{
    *count = 2;
    return gLeftoversHandlers;
}


/* Leftovers: at the end of the turn, if the holder is hurt, start the item effect. */
void HAND_ITEM_Leftovers_TriggerOnTurnEnd(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    HandExItemUse *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_POKEPARAM_IsHpFull(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) == 0) {
            cmd = (HandExItemUse *)BTL_SERVER_FLOW_AllocCmdRecord(flow, 0, pokeId);
            cmd->flags = (cmd->flags & ~1) | 1;
            BTL_EVENT_KeepFactorRunning(factor);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}


/* Leftovers: recover a sixteenth of the maximum HP. */
void HAND_ITEM_Leftovers_Heal(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *holder;
    HandExRecoverHp *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        holder = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_IsHpFull(holder) == 0) {
            cmd = (HandExRecoverHp *)BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RECOVER_HP, pokeId);
            cmd->pokeId = pokeId;
            cmd->amount = BTL_CALC_DivideMaxHpMin1(holder, 16);
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HANDEX_STR_SET, 0x392);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, BTL_EVENT_GetFactorKey(factor));
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}


int *HAND_ITEM_GetBlackSludgeHandlers(int *count)
{
    *count = 1;
    return gBlackSludgeHandlers;
}


/*
 * Black Sludge: a Poison type holder recovers (item parameter) of its maximum
 * HP at the end of the turn; any other holder loses an eighth.
 */
void HAND_ITEM_BlackSludge_HealOrDamage(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *holder;
    HandExRecoverHp *heal;
    HandExLoseHp *hurt;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_SERVER_FLOW_CheckShowdownThunk(flow) == 0) {
        holder = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTLV_CORE_HasByte(BTL_POKEPARAM_GetTypePair(holder), BTL_POISON_TYPE)) {
            heal = (HandExRecoverHp *)BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RECOVER_HP, pokeId);
            heal->pokeId = pokeId;
            heal->amount = BTL_CALC_DivideMaxHpMin1(holder, HAND_ITEM_GetParam(factor, 2));
            BTL_SERVER_FLOW_InitMsgRecord(&heal->message, HANDEX_STR_SET, 0x392);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&heal->message, pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&heal->message, BTL_EVENT_GetFactorKey(factor));
            BTL_SERVER_FLOW_CommitCmdRecord(flow, heal);
        } else {
            hurt = (HandExLoseHp *)BTL_SERVER_FLOW_AllocCmdRecord(flow, 7, pokeId);
            hurt->pokeId = pokeId;
            hurt->amount = BTL_CALC_DivideMaxHpMin1(holder, 8);
            hurt->flags |= 2;
            hurt->effectId = 0x25f;
            hurt->effectParam = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
            hurt->effectKind = 6;
            BTL_SERVER_FLOW_InitMsgRecord(&hurt->message, HANDEX_STR_SET, 0x40e);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&hurt->message, pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&hurt->message, BTL_EVENT_GetFactorKey(factor));
            BTL_SERVER_FLOW_CommitCmdRecord(flow, hurt);
        }
    }
}


void *HAND_ITEM_GetDestinyKnotHandlers(int *count)
{
    *count = 1;
    return gDestinyKnotHandlers;
}


/*
 * 2026-10-03 (wave B3 lane 10): EXACT*. BTLV_CORE_MakeSlotKind3 returns a one-word struct (Word), as in the other matched callers; its return temporary is the second frame word (see docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md).
 */
/* Destiny Knot: when the holder is infatuated by an attacker, the attacker is infatuated too. */
void HAND_ITEM_DestinyKnot_Infatuate(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    u8 attackerId;
    HandExAddSickFull *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_SICK_ID) != BTL_SICK_INFATUATION)
        return;
    attackerId = (u8)BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    if (attackerId == BTL_NO_POKE_ID)
        return;
    cmd = (HandExAddSickFull *)BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
    cmd->pokeId = attackerId;
    cmd->sickKind = BTL_SICK_INFATUATION;
    *(union SickCont *)&cmd->sickCont = BTLV_CORE_MakeSlotKind3(pokeId);
    cmd->flagD = 1;
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HANDEX_STR_SET, 0x14a);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, attackerId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, BTL_EVENT_GetFactorKey(factor));
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}


void *HAND_ITEM_GetStickyBarbHandlers(int *count)
{
    *count = 2;
    return gStickyBarbHandlers;
}


/* Sticky Barb: a contact hit on the holder (not into a substitute) moves the barb to an item-less attacker. */
void HAND_ITEM_StickyBarb_Transfer(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    u8 attackerId;
    HandExStealItem *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) == 0) {
        if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), BTL_MOVE_FLAG_CONTACT) != 0) {
            attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
            if (BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, attackerId)) == 0) {
                cmd = (HandExStealItem *)BTL_SERVER_FLOW_AllocCmdRecord(flow, 0x24, pokeId);
                cmd->pokeId = attackerId;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            }
        }
    }
}


/* Sticky Barb: the holder loses an eighth of its maximum HP at the end of the turn. */
void HAND_ITEM_StickyBarb_TurnEndDamage(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *holder;
    HandExLoseHp *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        holder = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        cmd = (HandExLoseHp *)BTL_SERVER_FLOW_AllocCmdRecord(flow, 7, pokeId);
        cmd->pokeId = pokeId;
        cmd->amount = BTL_CALC_DivideMaxHpMin1(holder, HAND_ITEM_GetParam(factor, 2));
        cmd->flags |= 2;
        cmd->effectId = 0x25f;
        cmd->effectParam = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
        cmd->effectKind = 6;
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HANDEX_STR_SET, 0x40e);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, BTL_EVENT_GetFactorKey(factor));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}


void *HAND_ITEM_GetPowerWeightHandlers(int *count)
{
    *count = 1;
    return gPowerWeightHandlers;
}


void *HAND_ITEM_GetPowerBracerHandlers(int *count)
{
    *count = 1;
    return gPowerBracerHandlers;
}


void *HAND_ITEM_GetPowerBeltHandlers(int *count)
{
    *count = 1;
    return gPowerBeltHandlers;
}


void *HAND_ITEM_GetPowerLensHandlers(int *count)
{
    *count = 1;
    return gPowerLensHandlers;
}


void *HAND_ITEM_GetPowerBandHandlers(int *count)
{
    *count = 1;
    return gPowerBandHandlers;
}


void *HAND_ITEM_GetPowerAnkletHandlers(int *count)
{
    *count = 1;
    return gPowerAnkletHandlers;
}


/* Power Weight, Bracer, Belt, Lens, Band and Anklet: the holder's speed is halved. */
void HAND_ITEM_PowerItem_HalveSpeed(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, 2 << 10);
}


int *HAND_ITEM_GetFlamePlateHandlers(int *count)
{
    *count = 1;
    return gFlamePlateHandlers;
}


int *HAND_ITEM_GetSplashPlateHandlers(int *count)
{
    *count = 1;
    return gSplashPlateHandlers;
}


int *HAND_ITEM_GetZapPlateHandlers(int *count)
{
    *count = 1;
    return gZapPlateHandlers;
}


int *HAND_ITEM_GetMeadowPlateHandlers(int *count)
{
    *count = 1;
    return gMeadowPlateHandlers;
}


int *HAND_ITEM_GetIciclePlateHandlers(int *count)
{
    *count = 1;
    return gIciclePlateHandlers;
}


int *HAND_ITEM_GetFistPlateHandlers(int *count)
{
    *count = 1;
    return gFistPlateHandlers;
}


int *HAND_ITEM_GetToxicPlateHandlers(int *count)
{
    *count = 1;
    return gToxicPlateHandlers;
}


int *HAND_ITEM_GetEarthPlateHandlers(int *count)
{
    *count = 1;
    return gEarthPlateHandlers;
}


int *HAND_ITEM_GetSkyPlateHandlers(int *count)
{
    *count = 1;
    return gSkyPlateHandlers;
}


int *HAND_ITEM_GetMindPlateHandlers(int *count)
{
    *count = 1;
    return gMindPlateHandlers;
}


int *HAND_ITEM_GetInsectPlateHandlers(int *count)
{
    *count = 1;
    return gInsectPlateHandlers;
}


int *HAND_ITEM_GetStonePlateHandlers(int *count)
{
    *count = 1;
    return gStonePlateHandlers;
}


int *HAND_ITEM_GetSpookyPlateHandlers(int *count)
{
    *count = 1;
    return gSpookyPlateHandlers;
}


int *HAND_ITEM_GetDracoPlateHandlers(int *count)
{
    *count = 1;
    return gDracoPlateHandlers;
}


int *HAND_ITEM_GetDreadPlateHandlers(int *count)
{
    *count = 1;
    return gDreadPlateHandlers;
}


int *HAND_ITEM_GetIronPlateHandlers(int *count)
{
    *count = 1;
    return gIronPlateHandlers;
}


int *HAND_ITEM_GetBigRootHandlers(int *count)
{
    *count = 1;
    return gBigRootHandlers;
}


/* Big Root: the holder's draining move recovers more HP, by the item's ratio. */
void HAND_ITEM_BigRoot_BoostDrain(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, HAND_ITEM_GetBoostRatio(factor));
}


int *HAND_ITEM_GetSmokeBallHandlers(int *count)
{
    *count = 2;
    return gSmokeBallHandlers;
}


/* Smoke Ball: guaranteed escape; forwards to the shared escape check (the second handler of the item is in the next file). */
void HAND_ITEM_SmokeBall_AllowEscape(struct BtlEventFactor *factor, void *flow, int pokeId, void *work)
{
    BTLV_CORE_EventSetFlagIfAttacker(factor, flow, pokeId, work);
}


/* Smoke Ball (guess): after the escape check passes, show the escape message with its sound. */
void HAND_ITEM_SmokeBallShowEscapeMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    TokuseiMessageCmd *msg;

    if (BTLV_CORE_EventTrySetFlagIfAttacker(factor, flow, pokeId) != 0) {
        msg = (TokuseiMessageCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->strParam, BTL_STR_TYPE_STANDARD, 0x3ec);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->strParam, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->strParam, BTL_EVENT_GetFactorKey(factor));
        BTL_SERVER_FLOW_SetMsgRecordSe(&msg->strParam, 0x56a);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}


/* Amulet Coin and Luck Incense: two entries. */
const BtlEventHandler *HAND_ITEM_GetAmuletCoinHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gAmuletCoinHandlers;
}


/* Amulet Coin: when the holder enters, flag the prize money as doubled. */
void HAND_ITEM_AmuletCoinFlagDoublePrizeOnEnter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_SERVER_FLOW_TryFinishMainCounter(flow, pokeId);
}


/*
 * Amulet Coin: the same flag again at the second enter event, without the
 * holder check.
 */
void HAND_ITEM_AmuletCoinFlagDoublePrizeOnEnterDone(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BTL_SERVER_FLOW_TryFinishMainCounter(flow, pokeId);
}


const BtlEventHandler *HAND_ITEM_GetGriseousOrbHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gGriseousOrbHandlers;
}


/* Griseous Orb: 1.2 times power for Dragon and Ghost moves of a Giratina. */
void HAND_ITEM_GriseousOrbBoostDragonGhostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 moveType;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    if (BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) != BTL_SPECIES_GIRATINA)
        return;
    moveType = BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
    if (moveType == BTL_TYPE_DRAGON || moveType == BTL_TYPE_GHOST)
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, 0x1333);
}


const BtlEventHandler *HAND_ITEM_GetIcyRockHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gIcyRockHandlers;
}


/* Icy Rock: hail lasts longer. */
void HAND_ITEM_IcyRockExtendHail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_ExtendWeatherTurns(factor, flow, pokeId, BTL_WEATHER_HAIL);
}


const BtlEventHandler *HAND_ITEM_GetSmoothRockHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSmoothRockHandlers;
}


/* Smooth Rock: sandstorm lasts longer. */
void HAND_ITEM_SmoothRockExtendSandstorm(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_ExtendWeatherTurns(factor, flow, pokeId, BTL_WEATHER_SAND);
}


const BtlEventHandler *HAND_ITEM_GetHeatRockHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gHeatRockHandlers;
}


/* Heat Rock: sunshine lasts longer. */
void HAND_ITEM_HeatRockExtendSunshine(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_ExtendWeatherTurns(factor, flow, pokeId, BTL_WEATHER_SUN);
}


const BtlEventHandler *HAND_ITEM_GetDampRockHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gDampRockHandlers;
}


/* Damp Rock: rain lasts longer. */
void HAND_ITEM_DampRockExtendRain(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_ExtendWeatherTurns(factor, flow, pokeId, BTL_WEATHER_RAIN);
}


/* Weather rocks: when the holder sets the given weather, replace its turn count with the item parameter. */
void HAND_ITEM_ExtendWeatherTurns(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int weather)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && weather == BTL_EVENT_GetVar(BTL_EVAR_WEATHER))
        BTL_EVENT_OverwriteVar(BTL_EVAR_WEATHER_TURNS, HAND_ITEM_GetParam(factor, BTL_ITEM_PARAM_BOOST_PERCENT));
}


/* Light Ball: two entries. */
const BtlEventHandler *HAND_ITEM_GetLightBallHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gLightBallHandlers;
}


/* Light Ball: doubles the attack ratio of a Pikachu. */
void HAND_ITEM_LightBallDoublePikachuAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) == BTL_SPECIES_PIKACHU)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
}


/* Light Ball, Fling: paralyze the target. */
void HAND_ITEM_LightBallFlingParalyze(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlItemAddSickCmd *cmd;
    unsigned char flingerId;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    flingerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    cmd = (BtlItemAddSickCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_SICK, flingerId);
    cmd->pokeId = pokeId;
    cmd->sickKind = TKS_SICK_PARALYSIS;
    cmd->sickCont = BTL_CALC_MakeDefaultSickCont(TKS_SICK_PARALYSIS);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}


/* Toxic Orb: two entries. */
const BtlEventHandler *HAND_ITEM_GetToxicOrbHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gToxicOrbHandlers;
}


/* Toxic Orb: at turn end badly poison the holder and show the message. */
void HAND_ITEM_ToxicOrbPoisonHolderOnTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlItemAddSickCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    cmd = (BtlItemAddSickCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_SICK, pokeId);
    cmd->sickKind = TKS_SICK_POISON;
    cmd->sickCont = BTLV_CORE_MakeSlotKind1Index15();
    cmd->hideMessage = 0;
    cmd->pokeId = pokeId;
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STANDARD, 0xf0);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, BTL_EVENT_GetFactorKey(factor));
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}


/*
 * Toxic Orb, Fling: badly poison the target.
 *
 * BTLV_CORE_MakeSlotKind1Index15 returns the condition record by value; that is what reserves
 * the empty frame word (push r3 / sub sp, #4). An int return drops it.
 */
void HAND_ITEM_ToxicOrbFlingPoison(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlItemAddSickCmd *cmd;
    unsigned char flingerId;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    flingerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    cmd = (BtlItemAddSickCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_SICK, flingerId);
    cmd->pokeId = pokeId;
    cmd->sickKind = TKS_SICK_POISON;
    cmd->sickCont = BTLV_CORE_MakeSlotKind1Index15();
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}


/* Flame Orb: two entries. */
const BtlEventHandler *HAND_ITEM_GetFlameOrbHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gFlameOrbHandlers;
}


/* Flame Orb: at turn end burn the holder and show the message. */
void HAND_ITEM_FlameOrbBurnHolderOnTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlItemAddSickCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    cmd = (BtlItemAddSickCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_SICK, pokeId);
    cmd->sickKind = TKS_SICK_BURN;
    cmd->sickCont = BTL_CALC_MakeDefaultSickCont(TKS_SICK_BURN);
    cmd->hideMessage = 0;
    cmd->pokeId = pokeId;
    /* The message argument is written here and again by the second append below. */
    cmd->strParam.args[1] = BTL_EVENT_GetFactorKey(factor);
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STANDARD, 0x102);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, BTL_EVENT_GetFactorKey(factor));
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}


/* Flame Orb, Fling: burn the target. */
void HAND_ITEM_FlameOrbFlingBurn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlItemAddSickCmd *cmd;
    unsigned char flingerId;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    flingerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    cmd = (BtlItemAddSickCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_SICK, flingerId);
    cmd->pokeId = pokeId;
    cmd->sickKind = TKS_SICK_BURN;
    cmd->sickCont = BTL_CALC_MakeDefaultSickCont(TKS_SICK_BURN);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}


/* Silver Powder. */
const BtlEventHandler *HAND_ITEM_GetSilverPowderHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSilverPowderHandlers;
}


void HAND_ITEM_SilverPowderBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_BUG);
}


/* Soft Sand. */
const BtlEventHandler *HAND_ITEM_GetSoftSandHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSoftSandHandlers;
}


void HAND_ITEM_SoftSandBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_GROUND);
}


/* Hard Stone. */
const BtlEventHandler *HAND_ITEM_GetHardStoneHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gHardStoneHandlers;
}


void HAND_ITEM_HardStoneBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_ROCK);
}


/* Miracle Seed. */
const BtlEventHandler *HAND_ITEM_GetMiracleSeedHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMiracleSeedHandlers;
}


/* Miracle Seed. */
void HAND_ITEM_MiracleSeedBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_GRASS);
}


/* Black Glasses. */
const BtlEventHandler *HAND_ITEM_GetBlackGlassesHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBlackGlassesHandlers;
}


/* Black Glasses: 1.2 times power for Dark moves of the holder. */
void HAND_ITEM_BlackGlassesBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_DARK);
}


/* Black Belt. */
const BtlEventHandler *HAND_ITEM_GetBlackBeltHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBlackBeltHandlers;
}


/* Black Belt. */
void HAND_ITEM_BlackBeltBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_FIGHTING);
}


/* Magnet. */
const BtlEventHandler *HAND_ITEM_GetMagnetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMagnetHandlers;
}


/* Magnet. */
void HAND_ITEM_MagnetBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_ELECTRIC);
}


/* Metal Coat. */
const BtlEventHandler *HAND_ITEM_GetMetalCoatHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMetalCoatHandlers;
}


/* Metal Coat. */
void HAND_ITEM_MetalCoatBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_STEEL);
}


/* Mystic Water. */
const BtlEventHandler *HAND_ITEM_GetMysticWaterHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMysticWaterHandlers;
}


/* Mystic Water. */
void HAND_ITEM_MysticWaterBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_WATER);
}


/* Sharp Beak. */
const BtlEventHandler *HAND_ITEM_GetSharpBeakHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSharpBeakHandlers;
}


/* Sharp Beak. */
void HAND_ITEM_SharpBeakBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_FLYING);
}


/* Poison Barb: two entries. */
const BtlEventHandler *HAND_ITEM_GetPoisonBarbHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gPoisonBarbHandlers;
}


/* Poison Barb. */
void HAND_ITEM_PoisonBarbBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_POISON);
}


/*
 * Poison Barb, Fling: poison the target. Same shape as the Light Ball
 * version, with the poison condition.
 */
void HAND_ITEM_PoisonBarbFlingPoison(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlItemAddSickCmd *cmd;
    unsigned char flingerId;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    flingerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    cmd = (BtlItemAddSickCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_SICK, flingerId);
    cmd->pokeId = pokeId;
    cmd->sickKind = TKS_SICK_POISON;
    cmd->sickCont = BTL_CALC_MakeDefaultSickCont(TKS_SICK_POISON);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}


/* Never-Melt Ice. */
const BtlEventHandler *HAND_ITEM_GetNeverMeltIceHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gNeverMeltIceHandlers;
}


/* Never-Melt Ice. */
void HAND_ITEM_NeverMeltIceBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_ICE);
}


/* Spell Tag. */
const BtlEventHandler *HAND_ITEM_GetSpellTagHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSpellTagHandlers;
}


/* Spell Tag. */
void HAND_ITEM_SpellTagBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_GHOST);
}


/* Twisted Spoon. */
const BtlEventHandler *HAND_ITEM_GetTwistedSpoonHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gTwistedSpoonHandlers;
}


/* Twisted Spoon. */
void HAND_ITEM_TwistedSpoonBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_PSYCHIC);
}


/* Charcoal. */
const BtlEventHandler *HAND_ITEM_GetCharcoalHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gCharcoalHandlers;
}


/* Charcoal. */
void HAND_ITEM_CharcoalBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_FIRE);
}


/* Dragon Fang. */
const BtlEventHandler *HAND_ITEM_GetDragonFangHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gDragonFangHandlers;
}


/* Dragon Fang. */
void HAND_ITEM_DragonFangBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_DRAGON);
}


/* Silk Scarf. */
const BtlEventHandler *HAND_ITEM_GetSilkScarfHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSilkScarfHandlers;
}


/* Silk Scarf. */
void HAND_ITEM_SilkScarfBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_NORMAL);
}


/* Odd Incense. */
const BtlEventHandler *HAND_ITEM_GetOddIncenseHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gOddIncenseHandlers;
}


/* Odd Incense. */
void HAND_ITEM_OddIncenseBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_PSYCHIC);
}


/* Rock Incense. */
const BtlEventHandler *HAND_ITEM_GetRockIncenseHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRockIncenseHandlers;
}


/* Rock Incense. */
void HAND_ITEM_RockIncenseBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_ROCK);
}


/* Sea Incense. */
const BtlEventHandler *HAND_ITEM_GetSeaIncenseHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSeaIncenseHandlers;
}


/* Sea Incense. */
void HAND_ITEM_SeaIncenseBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_WATER);
}


/* Wave Incense. */
const BtlEventHandler *HAND_ITEM_GetWaveIncenseHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWaveIncenseHandlers;
}


/* Wave Incense. */
void HAND_ITEM_WaveIncenseBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_WATER);
}


/* Rose Incense. */
const BtlEventHandler *HAND_ITEM_GetRoseIncenseHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRoseIncenseHandlers;
}


/* Rose Incense. */
void HAND_ITEM_RoseIncenseBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    HAND_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_GRASS);
}


/*
 * Type boost items: when the holder attacks with a move of the given type,
 * scale the move power by the ratio that the item parameter gives.
 */
void HAND_ITEM_BoostMovePowerOfType(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int moveType)
{
    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    if (moveType != BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE))
        return;
    BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, HAND_ITEM_GetBoostRatio(factor));
}


/* Lustrous Orb. */
const BtlEventHandler *HAND_ITEM_GetLustrousOrbHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gLustrousOrbHandlers;
}


/* Lustrous Orb: Palkia's Dragon and Water moves get the item's power ratio. */
void HAND_ITEM_LustrousOrbMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 moveType;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    if (BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) != SPECIES_PALKIA)
        return;
    moveType = BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
    if (moveType == POKETYPE_DRAGON || moveType == POKETYPE_WATER)
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, HAND_ITEM_GetBoostRatio(factor));
}


/* Adamant Orb handler table: one handler, move power. */
BtlEventHandler *HAND_ITEM_GetAdamantOrbHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBtlHandlerItemAdamantOrbHandlers;
}


/* Adamant Orb: Dialga's Dragon and Steel moves get the item's power ratio. */
void HAND_ITEM_AdamantOrbMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 moveType;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    if (BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) != SPECIES_DIALGA)
        return;
    moveType = BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
    if (moveType == POKETYPE_DRAGON || moveType == POKETYPE_STEEL)
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, HAND_ITEM_GetBoostRatio(factor));
}


/* Iron Ball handler table: speed ratio and ground check. */
BtlEventHandler *HAND_ITEM_GetIronBallHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlHandlerItemIronBallHandlers;
}


/* Iron Ball: halves the speed of the holder. */
void HAND_ITEM_IronBallSpeedRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    int keyAndShift = 2; /* the same 2 is the poke id key and the shift of the 0.5 ratio */

    if (pokeId == BTL_EVENT_GetVar(keyAndShift))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, keyAndShift << 10);
}


/* Iron Ball: the holder counts as grounded. */
void HAND_ITEM_IronBallGroundCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}


/* Float Stone handler table: weight ratio. */
BtlEventHandler *HAND_ITEM_GetFloatStoneHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBtlHandlerItemFloatStoneHandlers;
}


/* Float Stone: halves the weight of the holder. */
void HAND_ITEM_FloatStoneWeightRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    int keyAndShift = 2; /* the same 2 is the poke id key and the shift of the 0.5 ratio */

    if (pokeId == BTL_EVENT_GetVar(keyAndShift))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, keyAndShift << 10);
}


/* Eviolite handler table: defense ratio. */
BtlEventHandler *HAND_ITEM_GetEvioliteHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBtlHandlerItemEvioliteHandlers;
}


/* Eviolite: x1.5 defense while the holder can still evolve. */
void HAND_ITEM_EvioliteDefenseRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_SERVER_FLOW_IsPokeEvolvable(flow, pokeId))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, 6 << 10);
}


/* Rocky Helmet handler table: damage reaction. */
BtlEventHandler *HAND_ITEM_GetRockyHelmetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBtlHandlerItemRockyHelmetHandlers;
}


/* Rocky Helmet: a contact move that hit the holder costs the attacker 1/6 of its max HP. */
void HAND_ITEM_RockyHelmetDamageReaction(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlLoseHpCmd *cmd;
    struct BtlPokeParam *attacker;
    int divisor;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) != 0)
        return;
    if (!WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), 0))
        return;
    cmd = (BtlLoseHpCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_LOSE_HP, pokeId);
    cmd->pokeId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    attacker = BTL_SERVER_FLOW_GetPokeParam(flow, cmd->pokeId);
    divisor = (u8)HAND_ITEM_GetParam(factor, BTL_ITEM_PARAM_DAMAGE_DIVISOR);
    cmd->amount = BTL_CALC_DivideMaxHpMin1(attacker, divisor);
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STANDARD, 424);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, cmd->pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}


/* Air Balloon handler table: enter field, ground check, damage reaction. */
BtlEventHandler *HAND_ITEM_GetAirBalloonHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gBtlHandlerItemAirBalloonHandlers;
}


/* Air Balloon: announces the balloon when the holder enters the field, unless a field effect forbids it. */
void HAND_ITEM_AirBalloonEnterField(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlMessageCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    if (BTL_FIELD_GetStaticSlotObject(BTL_FIELD_EFFECT_GRAVITY_QUERY) != 0)
        return;
    cmd = (BtlMessageCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STANDARD, 0x198);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}


/* Air Balloon: the holder counts as floating. */
void HAND_ITEM_AirBalloonGroundCheck(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 1);
}


/* Air Balloon: when the holder is hit it loses the item and a message is shown. */
void HAND_ITEM_AirBalloonPop(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlItemSetItemCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    cmd = (BtlItemSetItemCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_SET_ITEM, pokeId);
    cmd->pokeId = pokeId;
    cmd->itemId = 0;
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STANDARD, 0x19b);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}


/* Red Card handler table: damage reaction at the end of the move. */
BtlEventHandler *HAND_ITEM_GetRedCardHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBtlHandlerItemRedCardHandlers;
}


/* Red Card: after the holder is hit, the attacker is forced out of the field. */
void HAND_ITEM_RedCardForceSwitch(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlItemMessageCmd *messageCmd;
    BtlForceSwitchCmd *switchCmd;
    u8 attackerId;

    if (HAND_COMMON_IsMoveTarget(pokeId) == 0)
        return;
    attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    if (BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, attackerId) == 6)
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_SHEER_FORCE_FLAG) != 0)
        return;
    if (BTL_SERVER_FLOW_CheckClientHasBackupPoke(flow, attackerId) == 0)
        return;
    if (BTL_SERVER_FLOW_CheckShowdownThunk(flow) != 0)
        return;
    messageCmd = (BtlItemMessageCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ITEM_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->strParam, BTL_STR_TYPE_STANDARD, 0x1a1);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->strParam, pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->strParam, attackerId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
    switchCmd = (BtlForceSwitchCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_FORCE_SWITCH, pokeId);
    switchCmd->pokeId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    switchCmd->mode = BTL_FORCE_SWITCH_MODE_ITEM;
    switchCmd->strId = BTL_FORCE_SWITCH_STR_ID;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, switchCmd);
}


/* Ring Target handler table: type immunity check. */
BtlEventHandler *HAND_ITEM_GetRingTargetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBtlHandlerItemRingTargetHandlers;
}


/* Ring Target: the holder as defender loses its type immunities. */
void HAND_ITEM_RingTargetImmunityOverride(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (BTL_SERVER_FLOW_IsActionCounterSet(flow) == 0 && pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_IMMUNITY_OVERRIDE_FLAG, 1);
}


/* Binding Band handler table. */
BtlEventHandler *HAND_ITEM_GetBindingBandHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBtlHandlerItemBindingBandHandlers;
}


/* Binding Band: the attacker's binding move gets the stronger content flag (event 0x62). */
void HAND_ITEM_BindingBandSickCont(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u32 sickCont;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    sickCont = BTL_EVENT_GetVar(BTL_EVAR_SICK_CONT);
    BTLV_CORE_SetSlotFlag(&sickCont, 1);
    BTL_EVENT_OverwriteVar(BTL_EVAR_SICK_CONT, sickCont);
}



/* Absorb Bulb handler table: damage reaction, use item. */
BtlEventHandler *HAND_ITEM_GetAbsorbBulbHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gHandItemAbsorbBulbHandlers;
}



/* Absorb Bulb: a Water move hit the holder; use the item if its Sp. Atk can rise. */
void HAND_ITEM_AbsorbBulbDamageReaction(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) != 0)
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) != POKETYPE_WATER)
        return;
    if (BTL_POKEPARAM_CanChangeStatStage(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_RANK_SP_ATTACK, 1) == 0)
        return;
    HAND_ITEM_PushUseItem(factor, flow, pokeId);
}



/* Absorb Bulb: raise the Sp. Atk of the holder by one stage. */
void HAND_ITEM_AbsorbBulbUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlRankCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    cmd = (BtlRankCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_CHANGE, pokeId);
    cmd->targetCount = 1;
    cmd->targets[0] = pokeId;
    cmd->statId = BTL_RANK_SP_ATTACK;
    cmd->amount = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}



/* Cell Battery handler table: damage reaction, use item. */
BtlEventHandler *HAND_ITEM_GetCellBatteryHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gHandItemCellBatteryHandlers;
}



/* Cell Battery: an Electric move hit the holder; use the item if its Attack can rise. */
void HAND_ITEM_CellBatteryDamageReaction(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) == 0
        && BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == POKETYPE_ELECTRIC) {
        if (BTL_POKEPARAM_CanChangeStatStage(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_RANK_ATTACK, 1) != 0) {
            HAND_ITEM_PushUseItem(factor, flow, pokeId);
        }
    }
}



/* Cell Battery: raise the Attack of the holder by one stage. */
void HAND_ITEM_CellBatteryUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlRankCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    cmd = (BtlRankCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_CHANGE, pokeId);
    cmd->targetCount = 1;
    cmd->targets[0] = pokeId;
    cmd->statId = BTL_RANK_ATTACK;
    cmd->amount = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}



/* Eject Button handler table: after the damage of a move, use item. */
BtlEventHandler *HAND_ITEM_GetEjectButtonHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gHandItemEjectButtonHandlers;
}



/* Eject Button: after the holder was hit, use the item if the flow allows the holder to switch out. */
void HAND_ITEM_EjectButtonAfterDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (HAND_COMMON_IsMoveTarget(pokeId) != 0 && BTL_EVENT_GetVar(BTL_EVAR_SHEER_FORCE_FLAG) == 0 && BTL_SERVER_FLOW_IsPokeAfflictedByStatus(flow, pokeId) == 0
        && BTL_SERVER_FLOW_CheckShowdownThunk(flow) == 0 && BTL_SERVER_FLOW_TestStateFlagBit0(flow) == 0 && BTL_SERVER_FLOW_CheckClientHasBackupPoke(flow, pokeId) != 0
        && BTL_SERVER_FLOW_TrySetOnceFlag(flow) != 0) {
        HAND_ITEM_PushUseItem(factor, flow, pokeId);
    }
}



/* Eject Button: show the message and switch the holder out. */
void HAND_ITEM_EjectButtonUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    BtlMessageCmd *messageCmd;
    BtlSwitchOutCmd *switchCmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_SERVER_FLOW_CheckClientHasBackupPoke(flow, pokeId) != 0) {
        messageCmd = (BtlMessageCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->strParam, BTL_STR_TYPE_STANDARD, BTL_STR_ID_EJECT_BUTTON);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->strParam, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
        switchCmd = (BtlSwitchOutCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_SWITCH_OUT, pokeId);
        switchCmd->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, switchCmd);
    }
}



/* Fire Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetFireGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemFireGemHandlers;
}



/* Fire Gem: boost Fire moves (event 0x38). */
void HAND_ITEM_FireGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_FIRE);
}



/* Fire Gem: use up the gem when a Fire move is used (event 0x81). */
void HAND_ITEM_FireGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_FIRE);
}



/* Water Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetWaterGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemWaterGemHandlers;
}



/* Water Gem: boost Water moves (event 0x38). */
void HAND_ITEM_WaterGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_WATER);
}



/* Water Gem: use up the gem when a Water move is used (event 0x81). */
void HAND_ITEM_WaterGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_WATER);
}



/* Electric Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetElectricGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemElectricGemHandlers;
}



/* Electric Gem: boost Electric moves (event 0x38). */
void HAND_ITEM_ElectricGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_ELECTRIC);
}



/* Electric Gem: use up the gem when a Electric move is used (event 0x81). */
void HAND_ITEM_ElectricGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_ELECTRIC);
}



/* Grass Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetGrassGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemGrassGemHandlers;
}



/* Grass Gem: boost Grass moves (event 0x38). */
void HAND_ITEM_GrassGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_GRASS);
}



/* Grass Gem: use up the gem when a Grass move is used (event 0x81). */
void HAND_ITEM_GrassGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_GRASS);
}



/* Ice Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetIceGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemIceGemHandlers;
}



/* Ice Gem: boost Ice moves (event 0x38). */
void HAND_ITEM_IceGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_ICE);
}



/* Ice Gem: use up the gem when a Ice move is used (event 0x81). */
void HAND_ITEM_IceGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_ICE);
}



/* Fighting Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetFightingGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemFightingGemHandlers;
}



/* Fighting Gem: boost Fighting moves (event 0x38). */
void HAND_ITEM_FightingGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_FIGHTING);
}



/* Fighting Gem: use up the gem when a Fighting move is used (event 0x81). */
void HAND_ITEM_FightingGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_FIGHTING);
}



/* Poison Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetPoisonGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemPoisonGemHandlers;
}



/* Poison Gem: boost Poison moves (event 0x38). */
void HAND_ITEM_PoisonGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_POISON);
}



/* Poison Gem: use up the gem when a Poison move is used (event 0x81). */
void HAND_ITEM_PoisonGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_POISON);
}



/* Ground Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetGroundGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemGroundGemHandlers;
}



/* Ground Gem: boost Ground moves (event 0x38). */
void HAND_ITEM_GroundGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_GROUND);
}



/* Ground Gem: use up the gem when a Ground move is used (event 0x81). */
void HAND_ITEM_GroundGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_GROUND);
}



/* Flying Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetFlyingGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemFlyingGemHandlers;
}



/* Flying Gem: boost Flying moves (event 0x38). */
void HAND_ITEM_FlyingGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_FLYING);
}



/* Flying Gem: use up the gem when a Flying move is used (event 0x81). */
void HAND_ITEM_FlyingGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_FLYING);
}



/* Psychic Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetPsychicGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemPsychicGemHandlers;
}



/* Psychic Gem: boost Psychic moves (event 0x38). */
void HAND_ITEM_PsychicGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_PSYCHIC);
}



/* Psychic Gem: use up the gem when a Psychic move is used (event 0x81). */
void HAND_ITEM_PsychicGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_PSYCHIC);
}



/* Bug Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetBugGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemBugGemHandlers;
}



/* Bug Gem: boost Bug moves (event 0x38). */
void HAND_ITEM_BugGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_BUG);
}



/* Bug Gem: use up the gem when a Bug move is used (event 0x81). */
void HAND_ITEM_BugGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_BUG);
}



/* Rock Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetRockGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemRockGemHandlers;
}



/* Rock Gem: boost Rock moves (event 0x38). */
void HAND_ITEM_RockGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_ROCK);
}



/* Rock Gem: use up the gem when a Rock move is used (event 0x81). */
void HAND_ITEM_RockGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_ROCK);
}



/* Ghost Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetGhostGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemGhostGemHandlers;
}



/* Ghost Gem: boost Ghost moves (event 0x38). */
void HAND_ITEM_GhostGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_GHOST);
}



/* Ghost Gem: use up the gem when a Ghost move is used (event 0x81). */
void HAND_ITEM_GhostGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_GHOST);
}



/* Dragon Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetDragonGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemDragonGemHandlers;
}



/* Dragon Gem: boost Dragon moves (event 0x38). */
void HAND_ITEM_DragonGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_DRAGON);
}



/* Dragon Gem: use up the gem when a Dragon move is used (event 0x81). */
void HAND_ITEM_DragonGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_DRAGON);
}



/* Dark Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetDarkGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemDarkGemHandlers;
}



/* Dark Gem: boost Dark moves (event 0x38). */
void HAND_ITEM_DarkGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_DARK);
}



/* Dark Gem: use up the gem when a Dark move is used (event 0x81). */
void HAND_ITEM_DarkGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_DARK);
}



/* Steel Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetSteelGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemSteelGemHandlers;
}



/* Steel Gem: boost Steel moves (event 0x38). */
void HAND_ITEM_SteelGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_STEEL);
}



/* Steel Gem: use up the gem when a Steel move is used (event 0x81). */
void HAND_ITEM_SteelGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_STEEL);
}



/* Normal Gem handler table: move used, move power, end of the move damage. */
BtlEventHandler *HAND_ITEM_GetNormalGemHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gHandItemNormalGemHandlers;
}



/* Normal Gem: use up the gem when a Normal move is used (event 0x81). */
void HAND_ITEM_NormalGemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMoveUsed(factor, flow, pokeId, work, POKETYPE_NORMAL);
}



/* Normal Gem: boost Normal moves (event 0x38). */
void HAND_ITEM_NormalGemMovePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    HAND_ITEM_GemMovePower(factor, flow, pokeId, work, POKETYPE_NORMAL);
}



/*
 * Gem, move used (event 0x81): when the attacker uses a damaging move of the
 * gem's type and the gem is still there, mark the item as used up, show the
 * message and set work[0] to BTL_GEM_STATE_CONSUMED.
 */
void HAND_ITEM_GemMoveUsed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work, u8 gemType)
{
    u16 moveId;
    BtlItemMessageCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && gemType == BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE)) {
        moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
        if (WAZA_TOOL_IsDamaging(moveId) != 0 && BTL_ID_IsGemIgnoredMove(moveId) == 0 && BTL_EVENT_IsFactorDead(factor) == 0
            && BTL_SERVER_FLOW_IsActionCounterSet(flow) == 0) {
            BTL_EVENT_MarkFactorDead(factor);
            cmd = (BtlItemMessageCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ITEM_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_SET, BTL_STR_ID_GEM_BOOST);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, BTL_EVENT_GetFactorKey(factor));
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID));
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            *work = BTL_GEM_STATE_CONSUMED;
        }
    }
}
