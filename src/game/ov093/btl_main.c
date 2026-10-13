/*
 * file:     btl_main.c
 * unit:     yes
 * function: BTL_MAIN_ProcInit, BTL_MAIN_ProcMain, BTL_MAIN_IsRecordPlaybackDone, BTL_MAIN_ProcExit, BTL_MAIN_StartSetupTask, BTL_MAIN_StartCleanupTask, BTL_MAIN_IsCommCompetitor, BTL_MAIN_SetupOwnClient, BTL_MAIN_InitClientParties, BTL_MAIN_InitTrainerSlot, BTL_MAIN_GetPositionsPerClient, BTL_MAIN_InitFirstTwoTrainerSlots, BTL_MAIN_StartRecordPlayback, BTL_MAIN_CreateViewCore, BTL_MAIN_TaskSetupSingle, BTL_MAIN_TaskCleanup, BTL_MAIN_TaskSetupDouble, BTL_MAIN_TaskSetupMulti, BTL_MAIN_TaskSetupTriple, BTL_MAIN_TaskSetupRotation, BTL_MAIN_TaskCommSingle, BTL_MAIN_TaskCommDouble, BTL_MAIN_RunSetupSeqKind1, BTL_MAIN_RunSetupSeqKind3, BTL_MAIN_SeqSyncRules, BTL_MAIN_SeqExchangeRegulation, BTL_MAIN_SeqExchangePlayers, BTL_MAIN_SeqExchangePerapVoice, BTL_MAIN_SeqCreateClientsKind1Solo, BTL_MAIN_SeqCreateClientsByMulti, BTL_MAIN_SeqCreateClientsKind3, BTL_MAIN_SeqCreateClientsKind1, BTL_MAIN_SeqCreateView, BTL_MAIN_StepClientsSolo, BTL_MAIN_StepParent, BTL_MAIN_StepChild, BTL_MAIN_MarkClientsDisconnected, BTL_MAIN_CheckAllClientsReady, BTL_MAIN_GetRule, BTL_MAIN_CheckSceneOff, BTL_MAIN_GetBadgeCount, BTL_MAIN_CheckShiftModePrompt, BTL_MAIN_GetTextSpeedFrames, BTL_MAIN_CheckEventOverlayAllowed, BTL_MAIN_GetPmsWork, BTL_MAIN_GetRuleSlotSpan, BTL_MAIN_GetActivePosPerSide, BTL_MAIN_CheckFrontPos, BTL_MAIN_GetCompetitor, BTL_MAIN_GetCommPos, BTL_MAIN_IsMultiMode, BTL_MAIN_GetWinBgm, BTL_MAIN_GetCompetitorKind, BTL_MAIN_GetFieldSituation, BTL_MAIN_GetPlayerStatus, BTL_MAIN_CheckZukanSeen, BTL_MAIN_GetZukanSeenCount, BTL_MAIN_GetGameData, BTL_MAIN_RegisterZukanSeen, BTL_MAIN_DecodeMessageCode, BTL_MAIN_DecodeMessageCodeBasic, BTL_MAIN_ExpandPosDouble, BTL_MAIN_ExpandPosTriple, BTL_MAIN_CountClientTrainers, BTL_MAIN_IsClientUsed, BTL_MAIN_GetClientSide, BTL_MAIN_IsLocalSide, BTL_MAIN_GetClientTrainerIndex, BTL_MAIN_GetEnemyLanePos, BTL_MAIN_GetOwnLanePos, BTL_MAIN_GetEnemyLanePosFromWork, BTL_MAIN_GetFacingPos
 * address:  0x021B6100
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Battle main module (BTL_MAIN; the file name is a guess, no __FILE__ string before btl_server.c).
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082A7C 0x02082A7C arm
 *   BTLV_CORE_LoadOverlays 0x021E8DC4 thumb ov093
 *   BTLV_CORE_LoadDsiOverlay 0x021E88CC thumb ov093
 *   GFL_USE_IsMuteHookActive 0x020057C4 thumb
 *   GFL_USE_SetSleepVolumeHooks 0x020057AC thumb
 *   CONFIG_GetTextSpeed 0x02008374 thumb
 *   CONFIG_GetBattleScene 0x020083AC thumb
 *   CONFIG_GetBattleStyle 0x020083C8 thumb
 *   BTL_FIELD_Create 0x021EF958 thumb ov093
 *   BTL_SIDE_Init 0x021B93E0 thumb ov093
 *   BTL_SETUP_ClearResultStats 0x021BA82C thumb ov093
 *   func_0203F258 0x0203F258 arm
 *   BTL_CALC_Init 0x021D7840 thumb ov093
 *   BTL_SERVER_CMD_Dummy 0x021CD6EC thumb ov093
 *   BTL_CALC_CalcPrizeMoney 0x021D7F88 thumb ov093
 *   BTL_CLIENT_SET_Clear 0x021D8230 thumb ov093
 *   BTL_NET_Init 0x021D4150 thumb ov093
 *   BTL_CALC_SetHeapId 0x021D804C thumb ov093
 *   BTL_NET_HasCommError 0x021D4270 thumb ov093
 *   BTL_NET_IsInitialSyncDone 0x021D4230 thumb ov093
 *   BTL_ADAPTER_ClearSlots 0x021EEA30 thumb ov093
 *   BTL_MAIN_ClearTrainerSlotsAndVoices 0x021B9DB8 thumb ov093
 *   BTL_MAIN_CreateParties 0x021BA094 thumb ov093
 *   BTL_MAIN_TrainerRecordAdd 0x021BA1B4 thumb ov093
 *   BTL_MAIN_GetOwnsSlots 0x021B9114 thumb ov093
 *   BTL_MAIN_JudgeResult 0x021BA54C thumb ov093
 *   BTL_MAIN_StoreRecorderEntry 0x021BA6C0 thumb ov093
 *   BTL_MAIN_StoreResultStats 0x021BA878 thumb ov093
 *   BTL_MAIN_WriteBackResults 0x021BA2E4 thumb ov093
 *   BTL_REC_IsChannelDone 0x021EE894 thumb ov093
 *   func_0207D55C 0x0207D55C arm
 *   func_0207D534 0x0207D534 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   PM_VOICE_ResetMasterVolume 0x02006740 thumb
 *   BTL_FIELD_Delete 0x021EF980 thumb ov093
 *   BTL_NET_FreeRelayPacket 0x021D4D5C thumb ov093
 *   BTL_CALC_Exit 0x021D7894 thumb ov093
 *   BTL_MAIN_FreeParties 0x021BA0CC thumb ov093
 *   BTL_MAIN_FreeTrainerSlotsAndVoices 0x021B9DE8 thumb ov093
 *   BTL_ADAPTER_NoOp 0x021EEA54 thumb ov093
 *   BTL_NET_Exit 0x021D4254 thumb ov093
 *   BTL_CALC_NoOp 0x021D8058 thumb ov093
 *   BTLV_CORE_UnloadOverlays 0x021E8DF8 thumb ov093
 *   BTLV_CORE_UnloadDsiOverlay 0x021E88F8 thumb ov093
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_02007B44 0x02007B44 thumb
 *   func_02007B20 0x02007B20 thumb
 *   func_02007C20 0x02007C20 thumb
 *   BTL_MAIN_GetClientVoiceFlag 0x021B997C thumb ov093
 *   BTL_MAIN_GetRelativeClientIndex 0x021BA710 thumb ov093
 *   BTL_MAIN_SetClientParty 0x021BA128 thumb ov093
 *   BTL_TRAINER_SLOT_InitFromData 0x021B9E7C thumb ov093
 *   BTL_TRAINER_SLOT_InitPlayer 0x021B9E38 thumb ov093
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   BTL_REC_InitReader 0x021EE644 thumb ov093
 *   BTL_CLIENT_AttachRemoteLink 0x021CD938 thumb ov093
 *   BTLV_CORE_Create 0x021E8F20 thumb ov093
 *   BTL_CLIENT_SetView 0x021CD95C thumb ov093
 *   BTL_SIDE_SetupClientParty 0x021B9460 thumb ov093
 *   BTL_SERVER_Create 0x021BA9C8 thumb ov093
 *   BTL_CLIENT_Create 0x021CD6F0 thumb ov093
 *   BTL_CLIENT_GetNetChannel 0x021CD978 thumb ov093
 *   BTL_SERVER_SetClientAdapter 0x021BAA94 thumb ov093
 *   BTL_SERVER_Restart 0x021BAB40 thumb ov093
 *   BTLV_CORE_Delete 0x021E9034 thumb ov093
 *   BTL_CLIENT_Delete 0x021CD8E0 thumb ov093
 *   BTL_SIDE_DeletePokeParams 0x021B9674 thumb ov093
 *   BTL_SERVER_Delete 0x021BAB5C thumb ov093
 *   gBtlMainCommSingleSteps 0x021EFD1C data a4
 *   gBtlMainCommDoubleSteps 0x021EFD00 data a4
 *   GFL_USE_SetPlayersAudible 0x02005CA4 thumb arm9
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb arm9
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb arm9
 *   GFL_USE_IsBgmFading 0x02005E50 thumb arm9
 *   RINGTONE_SYS_RegisterSleepCallbacks 0x02029F6C thumb arm9
 *   gSetupSeqKind1Steps 0x021EFD38 data a4
 *   gSetupSeqKind3Steps 0x021EFD54 data a4
 *   BTL_NET_SendEntry 0x021D4294 thumb ov093
 *   BTL_NET_IsLeaderKnown 0x021D4348 thumb ov093
 *   BTL_NET_IsLeader 0x021D4360 thumb ov093
 *   BTL_NET_GetLeaderValue 0x021D4378 thumb ov093
 *   BTL_MAIN_CheckSetupStatusFlag 0x021BA1A8 thumb ov093
 *   BTL_NET_SendSetup 0x021D43B8 thumb ov093
 *   BTL_NET_GetSetup 0x021D440C thumb ov093
 *   BTL_NET_BeginSync 0x021D4AF4 thumb ov093
 *   BTL_NET_PollSync 0x021D4B18 thumb ov093
 *   BTL_NET_SendParty 0x021D4438 thumb ov093
 *   BTL_NET_IsPartyReceived 0x021D44CC thumb ov093
 *   BTL_NET_AllocRelayPacket 0x021D4D24 thumb ov093
 *   BTL_NET_FillRelayPacket 0x021D4D64 thumb ov093
 *   BTL_NET_SendRelayedParty 0x021D4680 thumb ov093
 *   BTL_NET_IsRelayedPartyReceived 0x021D4784 thumb ov093
 *   BTL_NET_GetParty 0x021D47A4 thumb ov093
 *   BTL_NET_FreeAfterPartyUse 0x021D4800 thumb ov093
 *   BTL_MAIN_CopyClientParty 0x021BA648 thumb ov093
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   BTL_NET_SendPlayerInfo 0x021D4808 thumb ov093
 *   BTL_NET_IsPlayerInfoReceived 0x021D4898 thumb ov093
 *   BTL_NET_GetPlayerInfo 0x021D48CC thumb ov093
 *   BTL_NET_SendRelayedPlayerInfo 0x021D4908 thumb ov093
 *   BTL_NET_IsRelayedPlayerInfoReceived 0x021D49B0 thumb ov093
 *   BTL_NET_GetRelayedPlayerInfo 0x021D49CC thumb ov093
 *   BTL_NET_FreeRelayedPlayerInfo 0x021D49E0 thumb ov093
 *   BTL_NET_FreeAfterPlayerInfoUse 0x021D4A04 thumb ov093
 *   BTL_TRAINER_SLOT_InitFromPacket 0x021B9EF0 thumb ov093
 *   BTL_MAIN_CopyClientPlayerStatus 0x021BA670 thumb ov093
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020084D4 0x020084D4 thumb
 *   BTL_NET_ResetAfterParty 0x021D4500 thumb ov093
 *   BTL_NET_SendPerapVoice 0x021D450C thumb ov093
 *   BTL_NET_IsPerapVoiceReceived 0x021D45FC thumb ov093
 *   BTL_NET_GetPerapVoice 0x021D4648 thumb ov093
 *   BTL_NET_ResetAfterPerapVoice 0x021D4674 thumb ov093
 *   BTL_MAIN_IsTrainerSlotNpc 0x021B9F70 thumb ov093
 *   BTL_MAIN_StoreClientVoiceFlag 0x021BA698 thumb ov093
 *   func_02007B00 0x02007B00 thumb
 *   func_02082D44 0x02082D44 arm
 *   BTL_SERVER_CreateClientAdapter 0x021BAACC thumb ov093
 *   BTL_SERVER_SetClientWithoutAdapter 0x021BAB10 thumb ov093
 *   BTL_CLIENT_SetRequestParam 0x021CD960 thumb ov093
 *   BTL_MAIN_GetPartnerClient 0x021B9010 thumb ov093
 *   BTL_SERVER_Update 0x021BAB9C thumb ov093
 *   BTL_CLIENT_RunTick 0x021CD97C thumb ov093
 *   BTL_CLIENT_GetCursor 0x021CDD94 thumb ov093
 *   BTLV_CORE_Update 0x021E908C thumb ov093
 *   BTL_SERVER_GetFinalData 0x021BABDC thumb ov093
 *   BTL_CLIENT_MarkCommandIssued 0x021CD914 thumb ov093
 *   func_02013080 0x02013080 thumb
 *   ov231_id 0x000000E7 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021809D8 0x021809D8 thumb ov231
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200CF28 0x0200CF28 thumb
 *   BTL_POKEPARAM_GetMon 0x021D5844 thumb ov093
 *   func_0200CFA0 0x0200CFA0 thumb
 *   BTL_MAIN_MapPosForRule 0x021B8CB0 thumb ov093
 *   BTL_MAIN_IsBackRowPos 0x021B99F0 thumb ov093
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
 *   BTL_MAIN_GetFieldSituation  0x021B8714  thumb  ov093
 *   NATSUKI_Calc  0x0201B7A0  thumb
 *   func_021D54F4 0x021D54F4 thumb ov093
 *   BTL_POKEPARAM_IsIllusionActive  0x021D6C24  thumb  ov093
 *   BTL_POKEPARAM_GetDisplayMon  0x021D5864  thumb  ov093
 *   BTL_POKEPARAM_Delete 0x021D53B8 thumb ov093
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   BTL_POKEPARAM_Create 0x021D4D84 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_SetFakeMon 0x021D5848 thumb ov093
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
 *   MYSTATUS_Create  0x0200846C  thumb
 *   MYSTATUS_Copy  0x02008494  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008510  0x02008510  thumb
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 *   STRBUF_Clone  0x02045874  arm
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
 *   BTLV_CORE_ResetDisplay  0x021E8E28  thumb  ov093
 *   BTL_POKEPARAM_GetUsedMoveTotal 0x021D54B4 thumb ov093
 *   BTL_SERVER_NotifyLevelUp  0x021BB8BC  thumb  ov093
 *   BTL_SERVER_NotifyCapture  0x021BB8DC  thumb  ov093
 *   BTL_SERVER_GetFlow  0x021BB964  thumb  ov093
 *   BTL_SERVER_FLOW_GetPlayerNoEffectCount  0x021C7CBC  thumb  ov093
 *   BTL_SERVER_FLOW_GetPlayerSuperEffectiveCount  0x021C7CC8  thumb  ov093
 *   BTL_SERVER_FLOW_GetPlayerResistedCount  0x021C7CD4  thumb  ov093
 *   BTL_SERVER_FLOW_GetOpponentNoEffectCount  0x021C7CDC  thumb  ov093
 *   BTL_SERVER_FLOW_GetOpponentResistedCount  0x021C7CE8  thumb  ov093
 *   BTL_SERVER_FLOW_GetTurnCount  0x021C8138  thumb  ov093
 *   BTL_SERVER_FLOW_GetSlotFlag  0x021C8140  thumb  ov093
 *   BTL_CLIENT_ReadRecorderEntry  0x021CD924  thumb  ov093
 *   BTL_CLIENT_StartRemoteStep  0x021CD984  thumb  ov093
 *   BTL_CLIENT_StartMainStep  0x021CD9B0  thumb  ov093
 *   BTL_CLIENT_AddPoints  0x021CD9F4  thumb  ov093
 *   BTL_CLIENT_IsWindowWaiting  0x021CDDA0  thumb  ov093
 *   BTL_CLIENT_IsWindowDone  0x021CDDCC  thumb  ov093
 */
#include "btl_main_types.h"


#define REG_MASTER_BRIGHT_A 0x0400006C
#define REG_MASTER_BRIGHT_B 0x0400106C

struct PerapVoice;
struct MsgBank;
struct U16Vec;
struct GameData;
struct Config;
struct Party;

/* The proc instance: the work object allocated for it hangs off the end of the header. */
struct ProcHandle
{
  u32 header[5];
  void *work;
};


/*
 * Battle main work helpers: client and position arithmetic.
 *
 * Position ids: bit 0 is the side (0 = player side, 1 = enemy side) and
 * bits 1.. are the lane on that side (0..2). A client id follows the same
 * rule: bit 0 is the side of the client.
 */

extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
extern void *PROCSYS_AllocProcWork(struct ProcHandle *proc, u32 size, u32 heapId);
extern void func_02082A7C(u32, void *, u32);
extern void BTLV_CORE_LoadOverlays(unsigned short heapId);
extern void BTLV_CORE_LoadDsiOverlay(void);
extern int GFL_USE_IsMuteHookActive(void);
extern void GFL_USE_SetSleepVolumeHooks(void);
extern u32 CONFIG_GetTextSpeed(struct Config *config);
extern u32 CONFIG_GetBattleScene(struct Config *config);
extern u32 CONFIG_GetBattleStyle(struct Config *config);
extern struct BtlField *BTL_FIELD_Create(u32 heapId);
extern void BTL_SIDE_Init(struct BtlSide *side, struct BtlMain *main, u32 sideIndex);
extern void BTL_SETUP_ClearResultStats(struct BattleSetupParam *setup);
extern void func_0203F258(struct BattleRngState *rng);
extern void BTL_CALC_Init(struct BattleRngState *rng, u32 heapId);
extern void BTL_SERVER_CMD_Dummy(void);
extern u32 BTL_CALC_CalcPrizeMoney(struct BattleSetupParam *setup);
extern void BTL_CLIENT_SET_Clear(struct BtlClientSet *set);
extern void BTL_NET_Init(unsigned int netHandle, u16 mask, u16 heapId);
extern void BTL_CALC_SetHeapId(u32 heapId);
extern int BTL_NET_HasCommError(void);
extern int BTL_NET_IsInitialSyncDone(void);
extern void BTL_ADAPTER_ClearSlots(int commPos);
extern void BTL_MAIN_ClearTrainerSlotsAndVoices(struct BtlMain *main);
extern void BTL_MAIN_CreateParties(struct BtlMain *main);
extern void BTL_MAIN_TrainerRecordAdd(struct BtlMain *main, int arg);
extern u8 BTL_MAIN_GetOwnsSlots(struct BtlMain *main);
extern int BTL_MAIN_JudgeResult(struct BtlMain *main);
extern void BTL_MAIN_StoreRecorderEntry(struct BtlMain *main);
extern void BTL_MAIN_StoreResultStats(struct BtlMain *main);
extern void BTL_MAIN_WriteBackResults(struct BtlMain *main);
extern int BTL_REC_IsChannelDone(void *reader, u8 client);
extern void GFL_USE_FadeOutBgm(u32);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern int func_0207D55C(volatile u16 *reg);
extern void func_0207D534(volatile u16 *reg, int level);
extern void BTL_FIELD_Delete(struct BtlField *field);
extern u32 func_020307B0(void *p);
extern void BTL_NET_FreeRelayPacket(void *p);
extern void BTL_CALC_Exit(void);
extern void BTL_MAIN_FreeParties(struct BtlMain *main);
extern void BTL_MAIN_FreeTrainerSlotsAndVoices(struct BtlMain *main);
extern void BTL_ADAPTER_NoOp(void);
extern void BTL_NET_Exit(void);
extern void BTL_CALC_NoOp(void);
extern void BTLV_CORE_UnloadOverlays(void);
extern void GFL_USE_SetPlayersAudible(int, u32);
extern void PM_VOICE_ResetMasterVolume(void);
extern void RINGTONE_SYS_RegisterSleepCallbacks(void);
extern void func_020315D4(struct ProcHandle *proc);
extern void func_020306F0(unsigned int);
extern void BTLV_CORE_UnloadDsiOverlay(void);
extern void *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern const struct PerapVoice *func_02007B44(void *sys);
extern struct PerapVoice *func_02007B20(u32 heapId);
extern void func_02007C20(struct PerapVoice *dest, const struct PerapVoice *src);
extern int BTL_MAIN_GetClientVoiceFlag(struct BtlMain *main, unsigned int client);
extern u8 BTL_MAIN_GetRelativeClientIndex(int ownClient, int client);
extern void BTL_MAIN_SetClientParty(struct BtlMain *main, int client, struct Party *party);
extern void BTL_TRAINER_SLOT_InitFromData(struct BtlTrainerSlot *slot, struct BattleTrainerData *trainer);
extern void BTL_TRAINER_SLOT_InitPlayer(struct BtlTrainerSlot *slot, int heapId, void *playerStatus);
extern u32 POKEPARTY_GetCount(void *party);
extern void BTL_REC_InitReader(void *reader, void *recordBuffer, int size);
extern void BTL_CLIENT_AttachRemoteLink(struct BtlClient *client, void *reader);
extern struct BtlvCore *BTLV_CORE_Create(struct BtlMain *main, struct BtlClient *client, struct BtlSide *side, int isComm, u16 heapId);
extern void BTL_CLIENT_SetView(struct BtlClient *client, struct BtlvCore *viewCore);
extern void BTL_SIDE_SetupClientParty(struct BtlSide *side, struct BtlMain *main, u8 slot);
extern struct BtlServer *BTL_SERVER_Create(struct BtlMain *main, struct BattleRngState *rng, struct BtlSide *side, int isComm, u16 heapId);
extern struct BtlClient *BTL_CLIENT_Create(struct BtlMain *main, struct BtlSide *side, int unused, int netHandle, u16 clientId, u16 slotCount, u8 isOpponent, int isComm, int ownsSlots, struct BattleRngState *rng, u16 heapId);
extern u32 BTL_CLIENT_GetNetChannel(struct BtlClient *client);
extern void BTL_SERVER_SetClientAdapter(struct BtlServer *server, int clientRef, u8 clientId, u8 slotCount);
extern void BTL_SERVER_Restart(struct BtlServer *server);
extern void BTLV_CORE_Delete(struct BtlvCore *viewCore);
extern void BTL_CLIENT_Delete(struct BtlClient *client);
extern void BTL_SIDE_DeletePokeParams(struct BtlSide *side);
extern void BTL_SERVER_Delete(struct BtlServer *server);
extern int (*gSetupSeqKind1Steps[7])(struct BtlMain *, u32 *);
extern int BTL_NET_SendEntry(u16 v);
extern int BTL_NET_IsLeaderKnown(void);
extern int BTL_NET_IsLeader(void);
extern u8 BTL_NET_GetLeaderValue(void);
extern int BTL_MAIN_CheckSetupStatusFlag(struct BtlMain *main, int mask);
extern u32 BTL_NET_SendSetup(u32 a);
extern int BTL_NET_GetSetup(void *);
extern void BTL_NET_BeginSync(int a);
extern int BTL_NET_PollSync(int a);
extern u8 BTL_NET_SendParty(u32 a);
extern int BTL_NET_IsPartyReceived(void);
extern void *BTL_NET_AllocRelayPacket(u32,u16);
extern void BTL_NET_FillRelayPacket(u32 *p, const void *src, u32 a);
extern u32 BTL_NET_SendRelayedParty(u32 *a);
extern int BTL_NET_IsRelayedPartyReceived(u32 a);
extern void *BTL_NET_GetParty(u8);
extern void BTL_NET_FreeAfterPartyUse(void);
extern void BTL_MAIN_CopyClientParty(struct BtlMain *main, u8 client, void *dst);
extern int POKE_REGULATION_GetDataSize(void);
extern int BTL_NET_SendPlayerInfo(u32 a);
extern int BTL_NET_IsPlayerInfoReceived(void);
extern void *BTL_NET_GetPlayerInfo(u8);
extern u32 BTL_NET_SendRelayedPlayerInfo(void *);
extern int BTL_NET_IsRelayedPlayerInfoReceived(void);
extern void *BTL_NET_GetRelayedPlayerInfo(void);
extern void BTL_NET_FreeRelayedPlayerInfo(void);
extern void BTL_NET_FreeAfterPlayerInfoUse(void);
extern void BTL_TRAINER_SLOT_InitFromPacket(struct BtlTrainerSlot *slot, const struct BtlTrainerPacket *src);
extern void BTL_MAIN_CopyClientPlayerStatus(struct BtlMain *main, u8 client, void *src);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(void *bank);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 STRBUF_GetEosChar(void);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_020084D4(u32 value, void *dst);
extern void BTL_NET_ResetAfterParty(void);
extern u32 BTL_NET_SendPerapVoice(u32 *);
extern int BTL_NET_IsPerapVoiceReceived(void);
extern u32 BTL_NET_GetPerapVoice(u32 a);
extern void BTL_NET_ResetAfterPerapVoice(void);
extern int BTL_MAIN_IsTrainerSlotNpc(struct BtlMain *main, int slot);
extern void BTL_MAIN_StoreClientVoiceFlag(struct BtlMain *main, int client);
extern u32 func_02007B00(void);
extern void func_02082D44(const void *,void *,u32);
extern void BTL_SERVER_CreateClientAdapter(struct BtlServer *server, int unused, int netId, int clientId, u8 slotCount);
extern void BTL_SERVER_SetClientWithoutAdapter(struct BtlServer *server, u8 clientId, int slotCount);
extern void BTL_CLIENT_SetRequestParam(struct BtlClient *client, struct BtlServer *server);
extern u8 BTL_MAIN_GetPartnerClient(struct BtlMain *main, u8 clientId);
extern int BTL_SERVER_Update(struct BtlServer *server);
extern int BTL_CLIENT_RunTick(struct BtlClient *client);
extern void BTL_CLIENT_GetCursor(struct BtlClient *client, void *buf);
extern void BTLV_CORE_Update(struct BtlvCore *viewCore);
extern void BTL_SERVER_GetFinalData(struct BtlServer *server, void *buf);
extern void BTL_CLIENT_MarkCommandIssued(struct BtlClient *client);
extern signed char func_02013080(u32 idx);
extern int func_02034AC4(int id);
extern void func_02034A5C(int id);
extern int func_021809D8(void);
extern u16 BTL_POKEPARAM_GetSpecies(void *mon);
extern int func_0200CED4(void *,unsigned int);
extern u16 func_0200CF28(void *zukanWork);
extern void *BTL_POKEPARAM_GetMon(void *);
extern void func_0200CFA0(void *zukanWork, void *mon);
extern u8 ov231_id[];
extern int (*gSetupSeqKind3Steps[7])(struct BtlMain *, u32 *);
#include "btl_server_types.h"
#include "../../matched/include/G_StateData.h"
struct Blk34;
struct PartyMon;
struct BtlPosTable;
typedef unsigned long long u64;
struct BtlPosTable { u16 firstCount; volatile u16 secondCount; u8 positions[6]; }; /* stand-in: volatile forces the reload of secondCount in each loop test */
extern u8 BTL_MAIN_DecodeMessageCode(struct BtlMain *main, int code, u8 *out);
extern int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *poke);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *poke);
extern u8 BTL_MAIN_GetClientTrainerIndex(struct BtlMain *main, u32 clientId, u8 nth);
extern int BTL_MAIN_IsMultiMode(struct BtlMain *main);
extern u32 BTL_MAIN_GetCompetitor(struct BtlMain *main);
extern int BTL_MAIN_IsClientUsed(struct BtlMain *main, unsigned char clientId);
extern int func_02007F1C(void *,u32,int,u16);
extern int func_02007E50(void *,u32,int,u16);
extern u32 GPOWER_ApplyPrizeMoney(u32 v);
extern void *GAME_DATA_GetMiscSave(struct GameData *gameData);
extern u32 func_0200C274(struct Blk34 *p);
extern u32 BTL_CALC_CalcDefeatMoneyLoss(u32 a, void *b);
extern struct FieldSituation *BTL_MAIN_GetFieldSituation(struct BtlMain *main);
extern void NATSUKI_Calc(void *a0, int a1, int a2, int a3);
extern void func_021D54F4(struct BtlPokeParam *src, struct BtlPokeParam *dst);
extern int BTL_POKEPARAM_IsIllusionActive(struct BtlPokeParam *poke);
extern void *BTL_POKEPARAM_GetDisplayMon(struct BtlPokeParam *poke);
extern void BTL_POKEPARAM_Delete(struct BtlPokeParam *poke);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern struct BtlPokeParam *BTL_POKEPARAM_Create(void *mon, u8 pokeId, u32 heapId);
extern int func_021D59B4(struct BtlPokeParam *poke, int paramId);
extern void BTL_POKEPARAM_SetFakeMon(struct BtlPokeParam *poke, void *mon);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void *POKE_TOOL_Create(u16 species, u16 level, u64 id, u16 heap);
extern void POKEPARTY_Init(struct Party *p);
extern void BTL_POKEPARAM_WriteBackToParam(struct BtlPokeParam *poke, int flag);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern void POKEPARTY_Copy(const struct Party *src, struct Party *dst);
extern void BTL_POKEPARAM_SetPokeParam(struct BtlPokeParam *poke, void *mon);
extern int BTL_POKEPARAM_IsLevelUpPending(struct BtlPokeParam *poke);
extern void *func_02007B50(struct PerapVoice *voice);
extern u32 func_02007C70(struct PerapVoice *p);
extern u32 BTL_MAIN_GetRule(struct BtlMain *main);
extern u8 BTL_MAIN_GetEnemyLanePos(int rule, u32 basePos, u32 lane);
extern int BTL_POKEPARAM_IsAbleToBattle(struct BtlPokeParam *poke);
extern unsigned int BTL_MAIN_CountClientTrainers(struct BtlMain *main, int clientId);
extern void BTL_POKEPARAM_ClearFakeMon(struct BtlPokeParam *poke);
extern void *MYSTATUS_Create(int a);
extern void MYSTATUS_Copy(void *src, void *dst);
extern u8 func_02008550(const void *myStatus);
extern void *func_02008510(void *a, int tag);
extern void PMSI_PARAM_ClearSentence(void *a);
extern void *STRBUF_Clone(void *src, u32 heapId);
extern void PMSI_PARAM_Copy(void *dst, const void *src);
extern void *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_SetChars(void *buf, const void *src, u32 n);
char *COMM_PLAYER_SUPPORT_GetCurrent(char *p);
extern struct Party *POKEPARTY_Create(u32);
int BTL_SETUP_CheckStatusFlag(struct BattleSetupParam *setup, int mask);
extern u32 sub_02008DF0(void *trainerRecord, int arg);
extern u32 sub_02008DAC(void *trainerRecord, int arg, u32 delta);
extern u8 BTL_MAIN_IsCommCompetitor(struct BattleSetupParam *setup);
extern void NATSUKI_CalcUseItem(void *, int, u16, u16);
extern int BTL_CALC_IsBossTrainer(u32);
extern void NATSUKI_CalcParty(void *a0, int a1, int a2);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 func_021D805C(void *p, u32 n);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *poke);
extern u32 _u32_div_f(u32, u32);
extern u32 BTL_CLIENT_SET_GetCount(u32 *set);
extern int BTL_CLIENT_SET_JudgeResult(struct BtlClientSet *set, int ownClientId, unsigned int competitor);
extern void BTL_CALC_SetRngState(void *);
extern void BTL_MAIN_InitClientParties(struct BtlMain *main, struct BattleSetupParam *setup);
extern void BTLV_CORE_ResetDisplay(void *p);
extern u8 BTL_POKEPARAM_GetUsedMoveTotal(struct BtlPokeParam *poke);
int BTL_MAIN_IsOpposingPos(int unusedWork, int posA, int posB);
unsigned char BTL_MAIN_GetSlotClientId(struct BtlMain *main, int slot);
u8 BTL_MAIN_PokeIdToClientId(u32 pokeId);
u8 BTL_MAIN_CollectLivingPokeIds(struct BtlMain *main, struct BtlSide *side, int code, u8 *outPokeIds);
u8 BTL_MAIN_GetTrainerSlotOfPoke(struct BtlMain *main, struct BtlSide *side, u32 pokeId);
unsigned char BTL_MAIN_GetViewPosOfPoke(struct BtlMain *main, struct BtlSide *side, unsigned int pokeId);
u8 BTL_MAIN_PokeIdToClientIdThunk(u32 pokeId);
u8 BTL_MAIN_GetSlotClientIdThunk(struct BtlMain *main, int slot);
unsigned char BTL_MAIN_GetSlotNthOfClient(struct BtlMain *main, unsigned char slot);
void BTL_MAIN_GetSlotClientAndNth(struct BtlMain *main, u8 slot, u8 *outClientId, u8 *outNth);
u8 BTL_MAIN_GetViewPosOfSlot(struct BtlMain *main, u32 slot);
u8 BTL_MAIN_GetSlotFromViewPos(struct BtlMain *main, u8 slot);
int BTL_MAIN_IsCommMulti(struct BtlMain *main);
int BTL_MAIN_SyncSideParty(struct BtlMain *main, int clientId);
int BTL_MAIN_SyncPartnerSideParty(struct BtlMain *main, u32 clientId);
unsigned char BTL_MAIN_IsSecondTeamClient(struct BtlMain *main, unsigned int clientId);
u8 BTL_MAIN_IsOwnClientSecondTeam(struct BtlMain *main);
u8 BTL_MAIN_GetOwnClientId(struct BtlMain *main);
u8 BTL_MAIN_GetOwnPartnerClient(struct BtlMain *main);
int BTL_MAIN_IsSameTeamClient(int clientA, int clientB);
u8 BTL_MAIN_GetOwnOpponentClient(struct BtlMain *main, int nth);
u32 BTL_MAIN_GetOpponentClient(struct BtlMain *main, int clientId, int nth);
void BTL_MAIN_AddItemToBag(struct BtlMain *main, u32 clientId, u32 itemId);
void BTL_MAIN_SubItemFromBag(struct BtlMain *main, u8 clientId, u32 itemId);
u32 BTL_MAIN_GetMyItem(struct BtlMain *main);
u32 BTL_MAIN_GetMapMatrix(struct BtlMain *main);
int BTL_MAIN_IsRecordingActive(struct BtlMain *main);
int BTL_MAIN_ReturnZero(struct BtlMain *main, int unused);
void BTL_MAIN_StoreSlotNthResult(struct BtlMain *main, u8 slot);
void BTL_MAIN_SetOutcomeIfUnset(struct BtlMain *main, u32 outcome);
int BTL_MAIN_JudgeResultThunk(struct BtlMain *main);
void BTL_MAIN_SetRecordInvalid(struct BtlMain *main);
u32 BTL_MAIN_GetPrizeMoney(struct BtlMain *main);
void BTL_MAIN_AddBonusMoney(struct BtlMain *main, int add);
u32 BTL_MAIN_GetBonusMoney(struct BtlMain *main);
void BTL_MAIN_SetDoubleMoney(struct BtlMain *main);
u32 BTL_MAIN_CalcPenaltyMoney(struct BtlMain *main);
void BTL_MAIN_SetKeepBgm(struct BtlMain *main);
void BTL_MAIN_UpdateFriendshipIfPlayer(struct BtlMain *main, struct BtlPokeParam *poke, int isHigh);
void BTL_MAIN_UpdateFriendship(struct BtlMain *main, struct BtlPokeParam *poke, int event);
void BTL_MAIN_CopyLiveToSnapshotPoke(struct BtlMain *main, int pokeId);
struct BtlPokeParam *BTL_MAIN_ResolveIllusionPoke(struct BtlMain *main, struct BtlSide *side, struct BtlPokeParam *poke);
void BTL_SIDE_Clear(struct BtlSide *side);
void BTL_SIDE_SetupClientParty(struct BtlSide *side, struct BtlMain *main, u8 clientId);
int BTL_MAIN_FindLastLivingPartyIndex(struct Party *party);
void BTL_SIDE_WriteBackParty(struct BtlSide *side, struct BtlMain *main, int clientId, int flag);
void BTL_SIDE_WriteBackPartyOrdered(struct BtlSide *side, struct BtlMain *main, int clientId);
int BTL_SIDE_GetParty(struct BtlSide *side, int clientId);
int BTL_SIDE_FindPokeIndexInClient(struct BtlSide *side, int clientId, int pokeId);
struct BtlPokeParam *BTL_SIDE_GetPokeAtPosThunk(struct BtlSide *side, u8 position);
u8 *BTL_SIDE_GetPokeAtPos(struct BtlMain *const *side, u8 position);
void *BTL_SIDE_GetClientPokeParam(struct BtlSide *side, unsigned int clientId, unsigned int nth);
struct BtlPokeParam *BTL_SIDE_GetClientPoke(struct BtlSide *side, u32 clientId, u8 nth);
struct BtlPokeParam *BTL_SIDE_GetPokeByIdThunk(struct BtlSide *side, int pokeId);
struct BtlPokeParam *BTL_SIDE_GetPokeById(struct BtlSide *side, u8 pokeId);
int BTL_MAIN_GetVoiceOfSlot(struct BtlMain *main, u32 slot, struct PerapVoice **outVoice);
int BTL_MAIN_GetClientVoiceFlag(struct BtlMain *main, unsigned int clientId);
int BTL_MAIN_GetPositionsPerClientThunk(struct BtlMain *main, unsigned int clientId);
u8 BTL_MAIN_GetViewPositionsPerClient(struct BtlMain *main, u32 clientId);
struct BtlPosTable *BTL_MAIN_GetPosTable(int tableIndex);
u32 BTL_MAIN_IsBackRowPos(u32 position);
int BTL_MAIN_GetFrontEnemyPos(u32 position, u8 *outPosition);
int BTL_MAIN_IsPokeSamePair(unsigned int pokeIdA, unsigned int pokeIdB);
unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int pokeId);
unsigned char BTL_MAIN_IsPokeIdInFirstPair(unsigned int pokeId);
u8 BTL_MAIN_IsZero(u32 value);
int BTL_MAIN_IsPosInTable(int tableIndex, u32 position);
u8 BTL_SLOT_GetRotateSrcIndex(u8 rotateKind);
int BTL_SLOT_GetRotateDstIndex(int rotateKind);
unsigned char BTL_MAIN_GetPosParity(unsigned int position);
struct BtlSideSlot *BTL_SIDE_GetSlotOfClient(struct BtlSide *side, int clientId);
struct BtlSideSlot *BTL_SIDE_GetSlotOfClientThunk(struct BtlSide *side, int clientId);
unsigned char BTL_SIDE_CountLivingOfClient(struct BtlSide *side, int clientId);
void BTL_MAIN_AddClientPoints(struct BtlMain *main, u8 clientId, u8 points);
void BTL_SLOT_Clear(struct BtlSideSlot *slot);
void BTL_SLOT_Add(struct BtlSideSlot *slot, struct BtlPokeParam *poke);
void BTL_SLOT_CompactLiving(struct BtlSideSlot *slot);
u8 BTL_SLOT_GetCount(struct BtlSideSlot *slot);
u8 BTL_SLOT_CountLiving(struct BtlSideSlot *slot);
u8 BTL_SLOT_CountLivingFrom(struct BtlSideSlot *slot, int from);
struct BtlPokeParam *BTL_SLOT_GetPoke(struct BtlSideSlot *slot, u32 index);
struct BtlPokeParam *BTL_SLOT_GetPokeParam(struct BtlSideSlot *slot, u32 index);
void BTL_SLOT_Swap(struct BtlSideSlot *slot, int indexA, int indexB);
void BTL_SLOT_MoveToEnd(struct BtlSideSlot *slot, u8 index);
void BTL_SLOT_Rotate(struct BtlSideSlot *slot, u8 rotateKind, struct BtlPokeParam **outFirst, struct BtlPokeParam **outLast);
int BTL_SLOT_FindPoke(struct BtlSideSlot *slot, struct BtlPokeParam *poke);
int BTL_SLOT_FindPokeId(struct BtlSideSlot *slot, int pokeId);
struct BtlPokeParam *BTL_SLOT_GetFirstLiving(struct BtlSideSlot *slot);
void BTL_SLOT_UpdateIllusion(struct BtlMain *main, struct BtlSideSlot *slot, int firstIndex);
void BTL_TRAINER_SLOT_InitFromData(struct BtlTrainerSlot *slot, struct BattleTrainerData *src);
u16 BTL_MAIN_GetTrainerItem(struct BtlMain *main, int slot, unsigned int index);
u32 BTL_MAIN_GetTrainerNameAndType(struct BtlMain *main, int slot, u32 *outTrainerType);
int BTL_MAIN_GetTrainerAiFlags(struct BtlMain *main, int slot);
u16 BTL_MAIN_GetTrainerId(struct BtlMain *main, int slot);
unsigned short BTL_MAIN_GetTrainerType(struct BtlMain *main, int slot);
void *BTL_MAIN_GetTrainerSentence(struct BtlMain *main, int slot, int mode);
int BTL_MAIN_GetTrainerHandle(struct BtlMain *main, int slot);
void BTL_MAIN_UpdateCommPlayerSupport(struct BtlMain *main);
u32 BTL_MAIN_GetField(struct BtlMain *main);
void BTL_MAIN_SetClientParty(struct BtlMain *main, int clientId, struct Party *party);
struct Party *BTL_MAIN_GetClientParty(struct BtlMain *main, int clientId, int useSaved);
void BTL_MAIN_TrainerRecordAddDelta(struct BtlMain *main, int arg, u32 delta);
char *BTL_MAIN_GetRegulationRules(struct BtlMain *main);
BOOL BTL_MAIN_IsRecordEnabledInComm(struct BtlMain *main);
int BTL_MAIN_IsRecordAllowed(struct BtlMain *main);
void BTL_MAIN_NotifyLevelUp(struct BtlMain *main, struct BtlPokeParam *poke);
void BTL_MAIN_UpdateFriendshipUseItem(struct BtlMain *main, struct BtlPokeParam *poke, int itemId);
void BTL_MAIN_NotifyCapture(struct BtlMain *main, u32 *captureInfo);
int BTL_MAIN_IsCommTrainerBattle(struct BtlMain *main);
u16 BTL_MAIN_GetLimitTimeCommand(struct BtlMain *main);
u16 BTL_MAIN_GetLimitTimeGame(struct BtlMain *main);
int BTL_MAIN_IsOwnWindowWaiting(struct BtlMain *main);
int BTL_MAIN_CheckOwnWindowDone(struct BtlMain *main);
void BTL_MAIN_CopyClientPlayerStatus(struct BtlMain *main, u8 client, void *dst);
void BTL_MAIN_RestartBattle(struct BtlMain *main, u16 stepArg);
void BTL_MAIN_StartClientMainSteps(struct BtlMain *main);
u32 BTL_MAIN_GetServerFlow(struct BtlMain *main);
void BTL_SERVER_NotifyLevelUp(struct BtlServer *server, struct BtlPokeParam *poke);
void BTL_SERVER_NotifyCapture(struct BtlServer *server, u32 *captureInfo);
u32 BTL_SERVER_GetFlow(struct BtlServer *server);
u16 BTL_SERVER_FLOW_GetPlayerNoEffectCount(void *flow);
u16 BTL_SERVER_FLOW_GetPlayerSuperEffectiveCount(void *flow);
u16 BTL_SERVER_FLOW_GetPlayerResistedCount(void *flow);
u16 BTL_SERVER_FLOW_GetOpponentNoEffectCount(void *flow);
u16 BTL_SERVER_FLOW_GetOpponentResistedCount(void *flow);
u16 BTL_SERVER_FLOW_GetTurnCount(void *flow);
unsigned char BTL_SERVER_FLOW_GetSlotFlag(void *flow, int arg);
void *BTL_CLIENT_ReadRecorderEntry(struct BtlClient *client, u32 *outSize);
void BTL_CLIENT_SetView(struct BtlClient *client, struct BtlvCore *view);
void BTL_CLIENT_StartRemoteStep(struct BtlClient *client, u16 stepArg);
void BTL_CLIENT_StartMainStep(struct BtlClient *client);
void BTL_CLIENT_AddPoints(struct BtlClient *client, u8 points);
int BTL_CLIENT_IsWindowWaiting(struct BtlClient *client);
u32 BTL_CLIENT_IsWindowDone(struct BtlClient *client);
extern const u8 gClientFirstPokeIds[4];
extern u8 gViewPosOfSlotDouble[2][3];
extern u8 gViewPosOfSlotTriple[2][3];
extern struct BtlPosTable gBtlPosTables[];

extern u8 BTL_MAIN_MapPosForRule(struct BtlMain *main, u8 basePos);
extern u32 BTL_MAIN_IsBackRowPos(u32 basePos);

int BTL_MAIN_ProcInit(struct ProcHandle *proc, u32 *step, struct BattleSetupParam *setup, struct BtlMain *main);
int BTL_MAIN_ProcMain(struct ProcHandle *proc, u32 *step, struct BattleSetupParam *setup, struct BtlMain *main);
int BTL_MAIN_IsRecordPlaybackDone(struct BtlMain *main);
int BTL_MAIN_ProcExit(struct ProcHandle *proc, u32 *step, int unused, struct BtlMain *main);
void BTL_MAIN_StartSetupTask(struct BtlTask *task, struct BtlMain *main, struct BattleSetupParam *setup);
void BTL_MAIN_StartCleanupTask(struct BtlTask *task, struct BtlMain *main, struct BattleSetupParam *setup);
u8 BTL_MAIN_IsCommCompetitor(struct BattleSetupParam *setup);
void BTL_MAIN_SetupOwnClient(struct BtlMain *main, struct BattleSetupParam *setup);
void BTL_MAIN_InitClientParties(struct BtlMain *main, struct BattleSetupParam *setup);
void BTL_MAIN_InitTrainerSlot(struct BtlMain *main, int slot);
u8 BTL_MAIN_GetPositionsPerClient(struct BtlMain *main, u32 clientId);
void BTL_MAIN_InitFirstTwoTrainerSlots(struct BtlMain *main, struct BattleSetupParam *setup);
void BTL_MAIN_StartRecordPlayback(struct BtlMain *main, struct BattleSetupParam *setup);
void BTL_MAIN_CreateViewCore(struct BtlMain *main, struct BattleSetupParam *setup, int isComm);
int BTL_MAIN_TaskSetupSingle(u32 *unused, void *arg);
int BTL_MAIN_TaskCleanup(u32 *unused, void *arg);
int BTL_MAIN_TaskSetupDouble(u32 *unused, void *arg);
int BTL_MAIN_TaskSetupMulti(u32 *unused, void *arg);
int BTL_MAIN_TaskSetupTriple(u32 *unused, void *arg);
int BTL_MAIN_TaskSetupRotation(u32 *unused, void *arg);
int BTL_MAIN_TaskCommSingle(u32 *step, void *arg);
int BTL_MAIN_TaskCommDouble(u32 *step, void *arg);
int BTL_MAIN_RunSetupSeqKind1(u32 *step, void *arg);
int BTL_MAIN_RunSetupSeqKind3(u32 *step, void *arg);
int BTL_MAIN_SeqSyncRules(struct BtlMain *main, u32 *state);
int BTL_MAIN_SeqExchangeRegulation(struct BtlMain *main, u32 *state);
int BTL_MAIN_SeqExchangePlayers(struct BtlMain *main, u32 *state);
int BTL_MAIN_SeqExchangePerapVoice(struct BtlMain *main, u32 *state);
int BTL_MAIN_SeqCreateClientsKind1Solo(struct BtlMain *main);
int BTL_MAIN_SeqCreateClientsByMulti(struct BtlMain *main);
int BTL_MAIN_SeqCreateClientsKind3(struct BtlMain *main);
int BTL_MAIN_SeqCreateClientsKind1(struct BtlMain *main);
int BTL_MAIN_SeqCreateView(struct BtlMain *main, int *step);
int BTL_MAIN_StepClientsSolo(struct BtlMain *main);
int BTL_MAIN_StepParent(struct BtlMain *main);
int BTL_MAIN_StepChild(struct BtlMain *main);
void BTL_MAIN_MarkClientsDisconnected(struct BtlMain *main);
int BTL_MAIN_CheckAllClientsReady(struct BtlMain *main);
u32 BTL_MAIN_GetRule(struct BtlMain *main);
unsigned int BTL_MAIN_CheckSceneOff(struct BtlMain *main);
u8 BTL_MAIN_GetBadgeCount(struct BtlMain *main);
int BTL_MAIN_CheckShiftModePrompt(struct BtlMain *main);
int BTL_MAIN_GetTextSpeedFrames(struct BtlMain *main);
int BTL_MAIN_CheckEventOverlayAllowed(struct BtlMain *main);
u32 BTL_MAIN_GetPmsWork(struct BtlMain *main);
unsigned int BTL_MAIN_GetRuleSlotSpan(struct BtlMain *main);
unsigned int BTL_MAIN_GetActivePosPerSide(struct BtlMain *main);
int BTL_MAIN_CheckFrontPos(struct BtlMain *main, unsigned int posIdx);
u32 BTL_MAIN_GetCompetitor(struct BtlMain *main);
u8 BTL_MAIN_GetCommPos(struct BtlMain *main);
int BTL_MAIN_IsMultiMode(struct BtlMain *main);
u16 BTL_MAIN_GetWinBgm(struct BtlMain *main);
int BTL_MAIN_GetCompetitorKind(struct BtlMain *main);
struct FieldSituation *BTL_MAIN_GetFieldSituation(struct BtlMain *main);
int BTL_MAIN_GetPlayerStatus(struct BtlMain *main);
int BTL_MAIN_CheckZukanSeen(struct BtlMain *main, void *mon);
u32 BTL_MAIN_GetZukanSeenCount(struct BtlMain *main);
u32 BTL_MAIN_GetGameData(struct BtlMain *main);
void BTL_MAIN_RegisterZukanSeen(struct BtlMain *main, unsigned char doRegister, void *mon);
u8 BTL_MAIN_DecodeMessageCode(struct BtlMain *main, int code, u8 *out);
u8 BTL_MAIN_DecodeMessageCodeBasic(struct BtlMain *main, u32 k, u32 v, u8 *out);
u8 BTL_MAIN_ExpandPosDouble(struct BtlMain *main, u32 rangeType, u8 basePos, u8 *out);
u8 BTL_MAIN_ExpandPosTriple(struct BtlMain *main, u32 rangeType, u32 basePos, u8 *out);
unsigned int BTL_MAIN_CountClientTrainers(struct BtlMain *main, int clientId);
int BTL_MAIN_IsClientUsed(struct BtlMain *main, unsigned char clientId);
unsigned char BTL_MAIN_GetClientSide(int unusedWork, unsigned int clientId);
int BTL_MAIN_IsLocalSide(struct BtlMain *main, unsigned char side);
u8 BTL_MAIN_GetClientTrainerIndex(struct BtlMain *main, u32 clientId, u8 nth);
u8 BTL_MAIN_GetEnemyLanePos(int rule, u32 basePos, u32 lane);
u8 BTL_MAIN_GetOwnLanePos(u32 basePos, u32 lane);
u8 BTL_MAIN_GetEnemyLanePosFromWork(struct BtlMain *main, u32 basePos, int lane);
u8 BTL_MAIN_GetFacingPos(int rule, u32 basePos);


int BTL_MAIN_ProcInit(struct ProcHandle *proc, u32 *step, struct BattleSetupParam *setup, struct BtlMain *main)
{
  u32 flagBit;
  u32 i;
  u32 battleStyle;
  int taskDone;
  switch (*step)
  {
    case 0:
      GFL_HEAP_CreateChildHeap(1, 0x12, 0x20000);
      GFL_HEAP_CreateChildHeap(1, 0x14, 0x8000);
      GFL_HEAP_CreateChildHeap(1, 0x13, 0xab100);
      main = PROCSYS_AllocProcWork(proc, 0x474, 0x12);
      func_02082A7C(0, main, 0x474);
      BTLV_CORE_LoadOverlays(0x13);
      BTLV_CORE_LoadDsiOverlay();
      if (!GFL_USE_IsMuteHookActive())
      {
        GFL_USE_SetSleepVolumeHooks();
        main->flags.sleepHooksSet = 1;
      }
      main->heapId = 0x12;
      main->setup = setup;
      setup->resultValue[0] = 6;
      main->playerStatus = main->setup->playerStatus[0];
      main->limitTimeGame = main->setup->limitTimeGame;
      main->limitTimeCommand = main->setup->limitTimeCommand;
      main->flags.moneyLocked = 0;
      main->flags.penaltyDone = 0;
      main->flags.commLost = 0;
      main->flags.commLostHandled = 0;
      main->flags.keepBgm = 0;
      main->flags.doubleMoney = 0;
      main->multiState = 0;
      main->tick = 0;
      flagBit = 0;
      main->viewCore = 0;
      main->outcome = 7;
      main->textSpeed = CONFIG_GetTextSpeed(main->setup->config);
      if (CONFIG_GetBattleScene(setup->config) == 0)
        flagBit = 1;
      main->flags.noBattleAnim = (u8) flagBit;
      main->field = BTL_FIELD_Create(main->heapId);
      BTL_SIDE_Init(&main->sides[0], main, 0);
      BTL_SIDE_Init(&main->sides[1], main, 1);
      BTL_SETUP_ClearResultStats(main->setup);
      main->tempBuffer = 0;
      main->netBuffer = 0;
      if (main->setup->ownsSlots == 0)
        func_0203F258(&main->rng);
      else
        main->rng = setup->rng;
      BTL_CALC_Init(&main->rng, main->heapId);
      BTL_SERVER_CMD_Dummy();
      main->prizeMoney = BTL_CALC_CalcPrizeMoney(setup);
      main->bonusMoney = 0;
      main->penaltyMoney = 0;
      if (main->setup->ownsSlots == 0)
      {
        for (i = 0; i < 4; i++)
          main->setup->voiceFlags[i] = 0;
      }
      BTL_CLIENT_SET_Clear(&main->defeatedClients);
      battleStyle = CONFIG_GetBattleStyle(setup->config);
      flagBit = 0;
      if (battleStyle != 0)
        flagBit = 1;
      main->isSetStyle = flagBit;
      BTL_NET_Init(setup->netHandle, setup->levelCap, 0x14);
      BTL_CALC_SetHeapId(0x12);
      (*step)++;
      break;

    case 1:
      if (main->setup->netHandle != 0 && BTL_NET_HasCommError())
      {
        main->flags.commLost = 1;
        main->flags.commLostHandled = 1;
        return 1;
      }
      if (BTL_NET_IsInitialSyncDone())
      {
        BTL_ADAPTER_ClearSlots(main->setup->commPos);
        BTL_MAIN_StartSetupTask(&main->task, main, main->setup);
        main->subStep = 0;
        BTL_MAIN_ClearTrainerSlotsAndVoices(main);
        BTL_MAIN_CreateParties(main);
        (*step)++;
      }
      break;

    case 2:
      if (main->task.current != 0)
      {
        if (main->task.current(&main->task.step, main->task.arg))
        {
          main->task.current = 0;
          main->task.step = 0;
        }
        taskDone = 0;
      }
      else if (main->task.queued != 0)
      {
        if (main->task.queued(&main->task.step, main->task.arg))
        {
          main->task.queued = 0;
          taskDone = 1;
        }
        else
          taskDone = 0;
      }
      else
        taskDone = 1;
      if (taskDone != 0)
      {
        if (main->flags.commLost != 0)
        {
          main->flags.commLostHandled = 1;
          return 1;
        }
        if (main->setup->competitor != 4)
          BTL_MAIN_TrainerRecordAdd(main, 4);
        return 1;
      }
      break;
  }

  return 0;
}

int BTL_MAIN_ProcMain(struct ProcHandle *proc, u32 *step, struct BattleSetupParam *setup, struct BtlMain *main)
{
    u32 result;
    u32 recordDone;

    if (main->tick == 0) {
        return 1;
    }
    if (main->tick(main) != 0) {
        if (BTL_MAIN_GetOwnsSlots(main) == 0) {
            result = BTL_MAIN_JudgeResult(main);
            BTL_MAIN_StoreRecorderEntry(main);
            BTL_MAIN_StoreResultStats(main);
            BTL_MAIN_WriteBackResults(main);
            switch (result) {
            case 1:
                main->setup->moneyDelta = main->prizeMoney + main->bonusMoney;
                break;
            case 0:
            case 2:
                main->setup->moneyDelta = -main->penaltyMoney;
                break;
            }
        } else {
            recordDone = BTL_MAIN_IsRecordPlaybackDone(main);
            main->setup->bits.recordComplete = recordDone;
        }
        return 1;
    }
    return 0;
}

int BTL_MAIN_IsRecordPlaybackDone(struct BtlMain *main)
{
    unsigned int client;
    for (client = 0; client < 4; client++) {
        if (BTL_MAIN_IsClientUsed(main, client)) {
            if (!BTL_REC_IsChannelDone(main->recordReader, client)) return 0;
        }
    }
    return 1;
}

static inline int runTask(struct BtlMain *main)
{
    if (main->task.current) {
        if (main->task.current(&main->task.step, main->task.arg)) {
            main->task.current = 0; main->task.step = 0;
        }
        return 0;
    }
    if (main->task.queued) {
        if (main->task.queued(&main->task.step, main->task.arg)) main->task.queued = 0;
        else return 0;
    }
    return 1;
}

/*
 * lever: cache each re-read fade level for the comparison and setter; associate callback integer offsets before adding the base.
 */
int BTL_MAIN_ProcExit(struct ProcHandle *proc, u32 *step, int unused, struct BtlMain *main)
{
    switch (*step) {
    case 0:
        if (!main->flags.keepBgm) GFL_USE_FadeOutBgm(30);
        main->fadeLevel = 0;
        if (func_0207D55C((volatile u16 *)REG_MASTER_BRIGHT_A) != 0) {
            main->fadeLevel = -16;
            func_0207D534((volatile u16 *)REG_MASTER_BRIGHT_A, -16);
            func_0207D534((volatile u16 *)REG_MASTER_BRIGHT_B, -16);
            *step += 2;
        } else *step += 1;
        break;
    case 1: {
        int level;
        level = main->fadeLevel;
        if (level > -16) {
            main->fadeLevel = level - 1;
            if (func_0207D55C((volatile u16 *)REG_MASTER_BRIGHT_A) > (level = main->fadeLevel))
                func_0207D534((volatile u16 *)REG_MASTER_BRIGHT_A, level);
            if (func_0207D55C((volatile u16 *)REG_MASTER_BRIGHT_B) > (level = main->fadeLevel))
                func_0207D534((volatile u16 *)REG_MASTER_BRIGHT_B, level);
        } else *step += 1;
        break;
    }
    case 2:
        if (!main->flags.keepBgm) {
            if (GFL_USE_IsBgmFading() == 0) { GFL_USE_CancelChangeAndStopBgm(); *step += 1; }
        } else *step += 1;
        break;
    case 3:
        if (main->field) { BTL_FIELD_Delete(main->field); main->field = 0; }
        if (main->tempBuffer) { func_020307B0(main->tempBuffer); main->tempBuffer = 0; }
        if (main->netBuffer) { BTL_NET_FreeRelayPacket(main->netBuffer); main->netBuffer = 0; }
        BTL_CALC_Exit();
        BTL_MAIN_FreeParties(main);
        BTL_MAIN_FreeTrainerSlotsAndVoices(main);
        BTL_MAIN_StartCleanupTask(&main->task, main, main->setup);
        *step += 1;
        break;
    case 4:
        if (runTask(main)) {
            BTL_ADAPTER_NoOp(); BTL_NET_Exit(); BTL_CALC_NoOp();
            *step += 1;
        }
        break;
    case 5:
        BTLV_CORE_UnloadOverlays();
        GFL_USE_SetPlayersAudible(1, 62);
        PM_VOICE_ResetMasterVolume();
        if (main->flags.sleepHooksSet) { RINGTONE_SYS_RegisterSleepCallbacks(); main->flags.sleepHooksSet = 0; }
        func_020315D4(proc);
        func_020306F0(19);
        func_020306F0(20);
        func_020306F0(18);
        BTLV_CORE_UnloadDsiOverlay();
        return 1;
    }
    return 0;
}

static inline void startTask(struct BtlTask *task, struct BtlMain *main, BtlStepFn fn)
{
    task->current = fn; task->queued = 0; task->arg = main; task->step = 0;
}

void BTL_MAIN_StartSetupTask(struct BtlTask *task, struct BtlMain *main, struct BattleSetupParam *setup)
{
    u32 slot;
    for (slot = 0; slot < 6; slot++) main->slotClientIds[slot] = 4;
    if (!setup->commPos) {
        switch (setup->rule) {
        case 0: startTask(task, main, BTL_MAIN_TaskSetupSingle); return;
        case 1:
            if (!setup->multiMode) { startTask(task, main, BTL_MAIN_TaskSetupDouble); return; }
            else { startTask(task, main, BTL_MAIN_TaskSetupMulti); return; }
        case 2: startTask(task, main, BTL_MAIN_TaskSetupTriple); return;
        case 3: startTask(task, main, BTL_MAIN_TaskSetupRotation); return;
        default: startTask(task, main, BTL_MAIN_TaskSetupSingle); return;
        }
    } else {
        switch (setup->rule) {
        case 0: startTask(task, main, BTL_MAIN_TaskCommSingle); return;
        case 1: startTask(task, main, BTL_MAIN_TaskCommDouble); return;
        case 2: startTask(task, main, BTL_MAIN_RunSetupSeqKind3); return;
        case 3: startTask(task, main, BTL_MAIN_RunSetupSeqKind1); return;
        default: startTask(task, main, BTL_MAIN_TaskSetupSingle); return;
        }
    }
}

/*
 * size: 324
 * lever: initializer stores first, second, object, state; object-first reallocates all tails.
 */
void BTL_MAIN_StartCleanupTask(struct BtlTask *task, struct BtlMain *main, struct BattleSetupParam *setup)
{
    startTask(task, main, BTL_MAIN_TaskCleanup);
}

u8 BTL_MAIN_IsCommCompetitor(struct BattleSetupParam *setup)
{
    switch (setup->competitor) {
    case 0: return 0;
    case 1: return 0;
    case 2: return 0;
    case 3: return 1;
    default: return 0;
    }
}

void BTL_MAIN_SetupOwnClient(struct BtlMain *main, struct BattleSetupParam *setup)
{
    u32 client;
    const struct PerapVoice *srcVoice;
    u8 voiceOrder[4];
    u8 ownClientId = setup->netId;

    client = 0;
    main->ownClientId = ownClientId;
    main->ownFirstSlot = BTL_MAIN_GetClientTrainerIndex(main, ownClientId, 0);
    BTL_MAIN_InitClientParties(main, setup);
    if (BTL_MAIN_GetOwnsSlots(main) == 0) {
        srcVoice = func_02007B44(GAME_DATA_GetSaveControl(setup->gameData));
        main->voices[0] = func_02007B20(main->heapId);
        func_02007C20(main->voices[0], srcVoice);
        main->setup->voiceFlags[0] = BTL_MAIN_GetClientVoiceFlag(main, client);
    } else {
        for (client = 0; client < 4; client++) {
            voiceOrder[BTL_MAIN_GetRelativeClientIndex(main->ownClientId, (u8)client)] = main->setup->voiceFlags[client];
        }
        for (client = 0; client < 4; client++) {
            main->setup->voiceFlags[client] = voiceOrder[client];
        }
    }
}

void BTL_MAIN_InitClientParties(struct BtlMain *main, struct BattleSetupParam *setup)
{
    int firstSrc, secondSrc, thirdSrc, fourthSrc;

    firstSrc = BTL_MAIN_GetRelativeClientIndex(main->ownClientId, 0);
    secondSrc = BTL_MAIN_GetRelativeClientIndex(main->ownClientId, 1);
    BTL_MAIN_SetClientParty(main, 0, setup->party[firstSrc]);
    BTL_MAIN_SetClientParty(main, 1, setup->party[secondSrc]);
    thirdSrc = BTL_MAIN_GetRelativeClientIndex(main->ownClientId, 2);
    fourthSrc = BTL_MAIN_GetRelativeClientIndex(main->ownClientId, 3);
    if (setup->party[thirdSrc] != 0) {
        BTL_MAIN_SetClientParty(main, 2, setup->party[thirdSrc]);
    }
    if (setup->party[fourthSrc] != 0) {
        BTL_MAIN_SetClientParty(main, 3, setup->party[fourthSrc]);
    }
}

void BTL_MAIN_InitTrainerSlot(struct BtlMain *main, int slot)
{
    struct BattleSetupParam *setup = main->setup;
    int source = BTL_MAIN_GetRelativeClientIndex(main->ownClientId, slot);
    struct BtlTrainerSlot *trainerSlot = &main->trainers[slot];
    struct BattleTrainerData *trainer = setup->trainerData[source];
    if (trainer->trainerId != 0)
        BTL_TRAINER_SLOT_InitFromData(trainerSlot, trainer);
    else
        BTL_TRAINER_SLOT_InitPlayer(trainerSlot, main->heapId, setup->playerStatus[source]);
}

u8 BTL_MAIN_GetPositionsPerClient(struct BtlMain *main, u32 clientId)
{
    struct BattleSetupParam *setup = main->setup;
    struct Party *partner;

    switch (setup->rule) {
    case 0:
        return 1;
    case 3:
        return 1;
    case 2:
        return 3;
    case 1:
        if (setup->multiMode == 0) {
            return 2;
        }
        if (setup->competitor == 3) {
            return 1;
        }
        partner = setup->party[(u8)((clientId + 2) & 3)];
        if (partner != 0 && (int)POKEPARTY_GetCount(partner) > 0) {
            return 1;
        }
        return 2;
    }
    return 1;
}

void BTL_MAIN_InitFirstTwoTrainerSlots(struct BtlMain *main, struct BattleSetupParam *setup)
{
    if (setup->ownsSlots == 0) {
        BTL_TRAINER_SLOT_InitPlayer(&main->trainers[0], main->heapId, main->playerStatus);
        BTL_TRAINER_SLOT_InitFromData(&main->trainers[1], setup->trainerData[1]);
    } else {
        BTL_MAIN_InitTrainerSlot(main, 0);
        BTL_MAIN_InitTrainerSlot(main, 1);
    }
}

void BTL_MAIN_StartRecordPlayback(struct BtlMain *main, struct BattleSetupParam *setup)
{
    if (setup->ownsSlots) {
        BTL_REC_InitReader(main->recordReader, setup->recordBuffer, setup->recordSize);
        BTL_CLIENT_AttachRemoteLink(main->clients[0], main->recordReader);
        BTL_CLIENT_AttachRemoteLink(main->clients[1], main->recordReader);
    }
}

/*
 * extent: final two zero bytes are alignment padding before the next labelled function.
 */
void BTL_MAIN_CreateViewCore(struct BtlMain *main, struct BattleSetupParam *setup, int isComm)
{
    struct BtlClient *client;
    struct BtlvCore *viewCore;
    if (setup->ownsSlots)
        client = main->clients[setup->netId];
    else
        client = main->clients[0];
    viewCore = BTLV_CORE_Create(main, client, &main->sides[0], isComm, 0x13);
    main->viewCore = viewCore;
    BTL_CLIENT_SetView(client, viewCore);
}

int BTL_MAIN_TaskSetupSingle(u32 *unused, void *arg)
{
    struct BtlMain *main = arg;
    struct BattleSetupParam *setup;
    int isComm;
    setup = main->setup;
    isComm = BTL_MAIN_IsCommCompetitor(setup);
    main->clientCount = 2;
    main->slotClientIds[0] = 0;
    main->slotClientIds[1] = 1;
    BTL_MAIN_SetupOwnClient(main, setup);
    BTL_SIDE_Init(&main->sides[0], main, 0);
    BTL_SIDE_SetupClientParty(&main->sides[0], main, 0);
    BTL_SIDE_SetupClientParty(&main->sides[0], main, 1);
    BTL_SIDE_Init(&main->sides[1], main, 1);
    BTL_SIDE_SetupClientParty(&main->sides[1], main, 0);
    BTL_SIDE_SetupClientParty(&main->sides[1], main, 1);
    main->server = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
    main->hostsServer = 1;
    BTL_MAIN_InitFirstTwoTrainerSlots(main, setup);
    main->clients[0] = BTL_CLIENT_Create(main, &main->sides[0], 0, setup->netHandle, 0, 1, 0, isComm, setup->ownsSlots, &main->rng, main->heapId);
    main->clients[1] = BTL_CLIENT_Create(main, &main->sides[0], 0, setup->netHandle, 1, 1, 1, isComm, setup->ownsSlots, &main->rng, main->heapId);
    BTL_MAIN_StartRecordPlayback(main, setup);
    BTL_MAIN_CreateViewCore(main, setup, isComm);
    BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[0]), 0, 1);
    BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[1]), 1, 1);
    BTL_SERVER_Restart(main->server);
    main->tick = BTL_MAIN_StepClientsSolo;
    return 1;
}

int BTL_MAIN_TaskCleanup(u32 *unused, void *arg)
{
    struct BtlMain *main = arg;
    u32 client;

    if (main->viewCore != 0) {
        BTLV_CORE_Delete(main->viewCore);
        main->viewCore = 0;
    }
    for (client = 0; client < 4; client++) {
        if (main->clients[client] != 0) {
            BTL_CLIENT_Delete(main->clients[client]);
        }
    }
    BTL_SIDE_DeletePokeParams(&main->sides[0]);
    BTL_SIDE_DeletePokeParams(&main->sides[1]);
    if (main->server != 0) {
        BTL_SERVER_Delete(main->server);
    }
    if (main->subServer != 0) {
        BTL_SERVER_Delete(main->subServer);
    }
    return 1;
}

int BTL_MAIN_TaskSetupDouble(u32 *unused, void *arg)
{
    struct BtlMain *main = arg;
    struct BattleSetupParam *setup;
    int isComm;
    setup = main->setup;
    isComm = BTL_MAIN_IsCommCompetitor(setup);
    main->ownClientId = 0;
    main->clientCount = 2;
    main->slotClientIds[0] = 0;
    main->slotClientIds[1] = 1;
    main->slotClientIds[2] = 0;
    main->slotClientIds[3] = 1;
    BTL_MAIN_SetupOwnClient(main, setup);
    BTL_SIDE_Init(&main->sides[0], main, 0);
    BTL_SIDE_SetupClientParty(&main->sides[0], main, 0);
    BTL_SIDE_SetupClientParty(&main->sides[0], main, 1);
    BTL_SIDE_Init(&main->sides[1], main, 1);
    BTL_SIDE_SetupClientParty(&main->sides[1], main, 0);
    BTL_SIDE_SetupClientParty(&main->sides[1], main, 1);
    BTL_MAIN_InitFirstTwoTrainerSlots(main, setup);
    main->server = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
    main->hostsServer = 1;
    main->clients[0] = BTL_CLIENT_Create(main, &main->sides[0], 0, setup->netHandle, 0, 2, 0, isComm, setup->ownsSlots, &main->rng, main->heapId);
    main->clients[1] = BTL_CLIENT_Create(main, &main->sides[0], 0, setup->netHandle, 1, 2, 1, isComm, setup->ownsSlots, &main->rng, main->heapId);
    BTL_MAIN_StartRecordPlayback(main, setup);
    BTL_MAIN_CreateViewCore(main, setup, isComm);
    BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[0]), 0, 2);
    BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[1]), 1, 2);
    BTL_SERVER_Restart(main->server);
    main->tick = BTL_MAIN_StepClientsSolo;
    return 1;
}

/*
 * lever: the boolean passed narrow is an int local; isComm declared after sideBlock puts it at sp+0x1c.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`sideBlock = main;` before `sideBlock = &main->sides[0];`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
int BTL_MAIN_TaskSetupMulti(u32 *unused, void *arg)
{
    struct BtlMain *main = arg;
    struct BattleSetupParam *setup;
    int client;
    u8 slotCount;
    int isOpponent;
    struct BtlSide *sideBlock;
    struct BattleRngState *rngState;
    int isComm;
    setup = main->setup;
    isComm = BTL_MAIN_IsCommCompetitor(setup);
    main->ownClientId = 0;
    main->clientCount = 2;
    main->slotClientIds[0] = 0;
    main->slotClientIds[2] = 0;
    main->slotClientIds[1] = 1;
    main->slotClientIds[3] = 1;
    switch (setup->multiMode) {
    case 0: break;
    case 1: case 2: case 3:
        main->slotClientIds[2] = 2;
        main->slotClientIds[3] = 3;
        main->clientCount = 4;
        break;
    case 4:
        main->slotClientIds[3] = 3;
        main->clientCount = 3;
        break;
    }
    BTL_MAIN_SetupOwnClient(main, setup);
    BTL_SIDE_Init(&main->sides[0], main, 0);
    BTL_SIDE_Init(&main->sides[1], main, 1);
    for (client = 0; client < 4; client++) {
        if (BTL_MAIN_IsClientUsed(main, client)) {
            BTL_SIDE_SetupClientParty(&main->sides[0], main, client);
            BTL_SIDE_SetupClientParty(&main->sides[1], main, client);
        }
    }
    if (!setup->ownsSlots) {
        BTL_TRAINER_SLOT_InitPlayer(&main->trainers[0], main->heapId, main->playerStatus);
        BTL_TRAINER_SLOT_InitFromData(&main->trainers[1], setup->trainerData[1]);
        if (BTL_MAIN_IsClientUsed(main, 2)) BTL_TRAINER_SLOT_InitFromData(&main->trainers[2], setup->trainerData[2]);
        if (BTL_MAIN_IsClientUsed(main, 3)) BTL_TRAINER_SLOT_InitFromData(&main->trainers[3], setup->trainerData[3]);
    } else {
        for (client = 0; client < 4; client++) {
            if (BTL_MAIN_IsClientUsed(main, client)) BTL_MAIN_InitTrainerSlot(main, (u8)client);
        }
    }
    main->server = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
    main->hostsServer = 1;
    rngState = &main->rng;
    sideBlock = &main->sides[0];
    for (client = 0; client < 4; client++) {
        if (BTL_MAIN_IsClientUsed(main, client)) {
            slotCount = BTL_MAIN_CountClientTrainers(main, (u8)client);
            isOpponent = 0;
            if (client != 0) isOpponent = 1;
            main->clients[client] = BTL_CLIENT_Create(main, sideBlock, 0, setup->netHandle, client, slotCount, isOpponent, isComm, setup->ownsSlots, rngState, main->heapId);
        }
    }
    if (setup->ownsSlots) {
        BTL_REC_InitReader(main->recordReader, setup->recordBuffer, setup->recordSize);
        for (client = 0; client < 4; client++) {
            if (BTL_MAIN_IsClientUsed(main, client)) BTL_CLIENT_AttachRemoteLink(main->clients[client], main->recordReader);
        }
    }
    BTL_MAIN_CreateViewCore(main, setup, isComm);
    for (client = 0; client < 4; client++) {
        if (BTL_MAIN_IsClientUsed(main, client)) {
            slotCount = BTL_MAIN_CountClientTrainers(main, (u8)client);
            BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[client]), client, slotCount);
        }
    }
    BTL_SERVER_Restart(main->server);
    main->tick = BTL_MAIN_StepClientsSolo;
    return 1;
}

int BTL_MAIN_TaskSetupTriple(u32 *unused, void *arg)
{
    struct BtlMain *main = arg;
    struct BattleSetupParam *setup;
    int isComm;
    setup = main->setup;
    isComm = BTL_MAIN_IsCommCompetitor(setup);
    main->clientCount = 2;
    main->hostsServer = 1;
    main->slotClientIds[0] = 0;
    main->slotClientIds[1] = 1;
    main->slotClientIds[2] = 0;
    main->slotClientIds[3] = 1;
    main->slotClientIds[4] = 0;
    main->slotClientIds[5] = 1;
    BTL_MAIN_SetupOwnClient(main, setup);
    BTL_SIDE_Init(&main->sides[0], main, 0);
    BTL_SIDE_SetupClientParty(&main->sides[0], main, 0);
    BTL_SIDE_SetupClientParty(&main->sides[0], main, 1);
    BTL_SIDE_Init(&main->sides[1], main, 1);
    BTL_SIDE_SetupClientParty(&main->sides[1], main, 0);
    BTL_SIDE_SetupClientParty(&main->sides[1], main, 1);
    BTL_MAIN_InitFirstTwoTrainerSlots(main, setup);
    main->server = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
    main->hostsServer = 1;
    main->clients[0] = BTL_CLIENT_Create(main, &main->sides[0], 0, setup->netHandle, 0, 3, 0, isComm, setup->ownsSlots, &main->rng, main->heapId);
    main->clients[1] = BTL_CLIENT_Create(main, &main->sides[0], 0, setup->netHandle, 1, 3, 1, isComm, setup->ownsSlots, &main->rng, main->heapId);
    BTL_MAIN_StartRecordPlayback(main, setup);
    BTL_MAIN_CreateViewCore(main, setup, isComm);
    BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[0]), 0, 3);
    BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[1]), 1, 3);
    BTL_SERVER_Restart(main->server);
    main->tick = BTL_MAIN_StepClientsSolo;
    return 1;
}

int BTL_MAIN_TaskSetupRotation(u32 *unused, void *arg)
{
    struct BtlMain *main = arg;
    struct BattleSetupParam *setup;
    int isComm;
    setup = main->setup;
    isComm = BTL_MAIN_IsCommCompetitor(setup);
    main->clientCount = 2;
    main->slotClientIds[0] = 0;
    main->slotClientIds[1] = 1;
    main->slotClientIds[2] = 0;
    main->slotClientIds[3] = 1;
    main->slotClientIds[4] = 0;
    main->slotClientIds[5] = 1;
    BTL_MAIN_SetupOwnClient(main, setup);
    BTL_SIDE_Init(&main->sides[0], main, 0);
    BTL_SIDE_SetupClientParty(&main->sides[0], main, 0);
    BTL_SIDE_SetupClientParty(&main->sides[0], main, 1);
    BTL_SIDE_Init(&main->sides[1], main, 1);
    BTL_SIDE_SetupClientParty(&main->sides[1], main, 0);
    BTL_SIDE_SetupClientParty(&main->sides[1], main, 1);
    main->server = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
    main->hostsServer = 1;
    BTL_MAIN_InitFirstTwoTrainerSlots(main, setup);
    main->clients[0] = BTL_CLIENT_Create(main, &main->sides[0], 0, setup->netHandle, 0, 1, 0, isComm, setup->ownsSlots, &main->rng, main->heapId);
    main->clients[1] = BTL_CLIENT_Create(main, &main->sides[0], 0, setup->netHandle, 1, 1, 1, isComm, setup->ownsSlots, &main->rng, main->heapId);
    BTL_MAIN_StartRecordPlayback(main, setup);
    BTL_MAIN_CreateViewCore(main, setup, isComm);
    BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[0]), 0, 1);
    BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[1]), 1, 1);
    BTL_SERVER_Restart(main->server);
    main->tick = BTL_MAIN_StepClientsSolo;
    return 1;
}

extern int (*gBtlMainCommSingleSteps[7])(struct BtlMain *, u32 *);

int BTL_MAIN_TaskCommSingle(u32 *step, void *arg)
{
    struct BtlMain *main = arg;
    if (*step == 0) {
        main->clientCount = 2;
        main->slotClientIds[0] = 0;
        main->slotClientIds[1] = 1;
        main->ownClientId = main->setup->netId;
        main->ownFirstSlot = BTL_MAIN_GetClientTrainerIndex(main, main->ownClientId, 0);
        *step = *step + 1;
        return 0;
    }
    if (*step < 7) {
        if (gBtlMainCommSingleSteps[*step](main, &main->subStep) != 0) {
            main->subStep = 0;
            *step = *step + 1;
        }
        return 0;
    }
    return 1;
}

extern int (*gBtlMainCommDoubleSteps[7])(struct BtlMain *, u32 *);

int BTL_MAIN_TaskCommDouble(u32 *step, void *arg)
{
    struct BtlMain *main = arg;
    if (*step == 0) {
        switch (main->setup->multiMode) {
        case 0:
        default:
            main->clientCount = 2;
            main->slotClientIds[0] = 0;
            main->slotClientIds[1] = 1;
            main->slotClientIds[2] = 0;
            main->slotClientIds[3] = 1;
            break;
        case 2:
            main->multiState = 2;
        case 1:
            main->clientCount = 4;
            main->slotClientIds[0] = 0;
            main->slotClientIds[1] = 1;
            main->slotClientIds[2] = 2;
            main->slotClientIds[3] = 3;
            break;
        }
        main->ownClientId = main->setup->netId;
        main->ownFirstSlot = BTL_MAIN_GetClientTrainerIndex(main, main->ownClientId, 0);
        *step = *step + 1;
        return 0;
    }
    if (*step < 7) {
        if (gBtlMainCommDoubleSteps[*step](main, &main->subStep) != 0) {
            main->subStep = 0;
            *step = *step + 1;
        }
        return 0;
    }
    return 1;
}


int BTL_MAIN_RunSetupSeqKind1(u32 *step, void *arg)
{
    struct BtlMain *main = arg;

    if (*step == 0) {
        main->clientCount = 2;
        main->slotClientIds[0] = 0;
        main->slotClientIds[1] = 1;
        main->slotClientIds[2] = 0;
        main->slotClientIds[3] = 1;
        main->slotClientIds[4] = 0;
        main->slotClientIds[5] = 1;
        main->ownClientId = main->setup->netId;
        main->ownFirstSlot = BTL_MAIN_GetClientTrainerIndex(main, main->ownClientId, 0);
        *step = *step + 1;
        return 0;
    }
    if ((u32)*step < 7) {
        if (gSetupSeqKind1Steps[*step](main, &main->subStep)) {
            main->subStep = 0;
            *step = *step + 1;
        }
        return 0;
    }
    return 1;
}






int BTL_MAIN_RunSetupSeqKind3(u32 *step, void *arg)
{
    struct BtlMain *main = arg;

    if (*step == 0) {
        main->clientCount = 2;
        main->slotClientIds[0] = 0;
        main->slotClientIds[1] = 1;
        main->slotClientIds[2] = 0;
        main->slotClientIds[3] = 1;
        main->slotClientIds[4] = 0;
        main->slotClientIds[5] = 1;
        main->ownClientId = main->setup->netId;
        main->ownFirstSlot = BTL_MAIN_GetClientTrainerIndex(main, main->ownClientId, 0);
        *step = *step + 1;
        return 0;
    }
    if ((u32)*step < 7) {
        if (gSetupSeqKind3Steps[*step](main, &main->subStep)) {
            main->subStep = 0;
            *step = *step + 1;
        }
        return 0;
    }
    return 1;
}




int BTL_MAIN_SeqSyncRules(struct BtlMain *main, u32 *state)
{
    struct BattleSetupParam *setup;
    if (BTL_NET_HasCommError()) {
        main->flags.commLost = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        if (BTL_NET_SendEntry(main->ownClientId)) ++*state;
        break;
    case 1:
        if (BTL_NET_IsLeaderKnown()) {
            main->pad46A = 0;
            main->hostsServer = BTL_NET_IsLeader();
            main->setup->resultValue[1] = BTL_NET_GetLeaderValue();
            if (BTL_NET_IsLeader()) *state = 2;
            else *state = 3;
        }
        break;
    case 2:
        *(struct BattleRngState *)&main->ruleExchange = main->rng;
        main->ruleExchange.resultCount = main->setup->resultCount;
        main->ruleExchange.limitTimeGame = main->setup->limitTimeGame;
        main->ruleExchange.limitTimeCommand = main->setup->limitTimeCommand;
        if (BTL_MAIN_CheckSetupStatusFlag(main, 0x1000)) {
            main->ruleExchange.textSpeed = main->textSpeed;
            main->ruleExchange.sceneOff = main->flags.noBattleAnim;
        } else {
            main->ruleExchange.textSpeed = 2;
            main->ruleExchange.sceneOff = 1;
        }
        if (BTL_NET_SendSetup((u32)&main->ruleExchange)) ++*state;
        break;
    case 3:
        if (BTL_NET_GetSetup(&main->ruleExchange)) {
            setup = main->setup;
            setup->resultCount = main->ruleExchange.resultCount;
            setup->rng = *(struct BattleRngState *)&main->ruleExchange;
            main->rng = *(struct BattleRngState *)&main->ruleExchange;
            main->flags.noBattleAnim = main->ruleExchange.sceneOff;
            main->textSpeed = main->ruleExchange.textSpeed;
            main->limitTimeGame = main->ruleExchange.limitTimeGame;
            main->limitTimeCommand = main->ruleExchange.limitTimeCommand;
            return 1;
        }
        break;
    }
    return 0;
}




/*
 * lever: slot starts at 1 and is conditionally assigned 3; ternary reverses the short branch.
 */
int BTL_MAIN_SeqExchangeRegulation(struct BtlMain *main, u32 *state)
{
    struct BattleSetupParam *setup;
    u32 i;
    struct BtlSide *side;
    int slot;
    setup = main->setup;
    if (BTL_NET_HasCommError()) {
        main->flags.commLost = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        BTL_NET_BeginSync((u8)2);
        ++*state;
        break;
    case 1:
        if (BTL_NET_PollSync((u8)2)) ++*state;
        break;
    case 2:
        if (BTL_NET_SendParty((u32)(setup->party[0]))) ++*state;
        break;
    case 3:
        if (BTL_NET_IsPartyReceived()) {
            if (!main->multiState) *state = 10;
            else {
                if (main->hostsServer) {
                    main->netBuffer = BTL_NET_AllocRelayPacket(POKE_REGULATION_GetDataSize(), (main->heapId & 0x7fff) | 0x8000);
                }
                main->exchangeIndex = 0;
                ++*state;
            }
        }
        break;
    case 4:
        slot = 1;
        if (main->exchangeIndex) slot = 3;
        main->exchangeSlot = slot;
        if (main->hostsServer) BTL_NET_FillRelayPacket(main->netBuffer, setup->party[main->exchangeSlot], main->exchangeSlot);
        BTL_NET_BeginSync((u8)(main->exchangeIndex + 6));
        ++*state;
        break;
    case 5:
        if (BTL_NET_PollSync((u8)(main->exchangeIndex + 6))) ++*state;
        break;
    case 6:
        if (!main->hostsServer || BTL_NET_SendRelayedParty(main->netBuffer)) ++*state;
        break;
    case 7:
        if (BTL_NET_IsRelayedPartyReceived(main->exchangeSlot)) {
            ++main->exchangeIndex;
            if (main->exchangeIndex >= main->multiState) {
                if (main->hostsServer) {
                    BTL_NET_FreeRelayPacket(main->netBuffer);
                    main->netBuffer = 0;
                }
                *state = 10;
            } else *state = 4;
        }
        break;
    case 10:
        BTL_SIDE_Init(&main->sides[0], main, 0);
        side = &main->sides[0];
        for (i = 0; i < 4; ++i) {
            if (BTL_MAIN_IsClientUsed(main, i)) {
                BTL_MAIN_SetClientParty(main, (u8)i, BTL_NET_GetParty(i));
                BTL_MAIN_CopyClientParty(main, i, BTL_NET_GetParty(i));
                BTL_SIDE_SetupClientParty(side, main, i);
            }
        }
        ++*state;
        break;
    case 11:
        BTL_SIDE_Init(&main->sides[1], main, 1);
        for (i = 0; i < 4; ++i) {
            if (BTL_MAIN_IsClientUsed(main, i)) BTL_SIDE_SetupClientParty(&main->sides[1], main, i);
        }
        ++*state;
        break;
    case 12:
        BTL_NET_FreeAfterPartyUse();
        ++*state;
        break;
    default:
        return 1;
    }
    return 0;
}




int BTL_MAIN_SeqExchangePlayers(struct BtlMain *main, u32 *state)
{
    struct BattleSetupParam *setup;
    u32 i;
    void *bank;
    void *defaultName;
    void *nameStr;
    u16 *src;
    u16 *dst;
    u16 buf[16];
    int slot;
    setup = main->setup;
    if (BTL_NET_HasCommError()) {
        main->flags.commLost = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        BTL_NET_BeginSync((u8)4);
        ++*state;
        break;
    case 1:
        if (BTL_NET_PollSync((u8)4)) ++*state;
        break;
    case 2:
        if (BTL_NET_SendPlayerInfo((u32)(main->playerStatus))) ++*state;
        break;
    case 3:
        if (BTL_NET_IsPlayerInfoReceived()) {
            for (i = 0; i < main->clientCount; ++i) {
                void *status = BTL_NET_GetPlayerInfo(i);
                if (status) {
                    BTL_TRAINER_SLOT_InitPlayer(&main->trainers[i], main->heapId, status);
                    if (i != main->ownClientId && setup->bits.hidePlayerNames) {
                        int j;
                        bank = func_02045B38(0, 2, 0x51, main->heapId);
                        nameStr = func_02045EC0(bank, 15);
                        MSGDATA_Delete(bank);
                        src = STRBUF_GetChars(nameStr);
                        for (j = 0; j < 15 && (u32)j < STRBUF_GetLength(nameStr); ++j) buf[j] = src[j];
                        dst = buf;
                        dst[j] = STRBUF_GetEosChar();
                        STRBUF_Delete(nameStr);
                        func_020084D4((u32)(main->trainers[i].handle), dst);
                        STRBUF_Delete(main->trainers[i].name);
                        bank = func_02045B38(0, 2, 0x51, main->heapId);
                        defaultName = func_02045EC0(bank, 15);
                        MSGDATA_Delete(bank);
                        main->trainers[i].name = defaultName;
                    }
                    BTL_MAIN_CopyClientPlayerStatus(main, i, main->trainers[i].handle);
                }
            }
            ++*state;
        }
        break;
    case 4:
        if (!main->multiState) *state = 10;
        else { main->exchangeIndex = 0; ++*state; }
        break;
    case 5:
        BTL_NET_BeginSync((u8)(main->exchangeIndex + 8));
        ++*state;
        break;
    case 6:
        if (BTL_NET_PollSync((u8)(main->exchangeIndex + 8))) ++*state;
        break;
    case 7:
        slot = 1;
        if (main->exchangeIndex) slot = 3;
        main->exchangeSlot = slot;
        if (main->hostsServer && !BTL_NET_SendRelayedPlayerInfo(setup->trainerData[main->exchangeSlot])) break;
        ++*state;
    case 8:
        if (BTL_NET_IsRelayedPlayerInfoReceived()) {
            BTL_TRAINER_SLOT_InitFromPacket(&main->trainers[main->exchangeSlot], BTL_NET_GetRelayedPlayerInfo());
            BTL_NET_FreeRelayedPlayerInfo();
            ++main->exchangeIndex;
            if (main->exchangeIndex >= main->multiState) *state = 10;
            else *state = 5;
        }
        break;
    case 10:
        BTL_NET_FreeAfterPlayerInfoUse();
        ++*state;
        break;
    default:
        return 1;
    }
    return 0;
}




int BTL_MAIN_SeqExchangePerapVoice(struct BtlMain *main, u32 *state)
{
    struct BattleSetupParam *setup;
    u32 i;
    const struct PerapVoice *src;
    setup = main->setup;
    if (BTL_NET_HasCommError()) {
        main->flags.commLost = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        BTL_NET_ResetAfterParty();
        BTL_NET_BeginSync(3);
        ++*state;
        break;
    case 1:
        if (BTL_NET_PollSync(3)) ++*state;
        break;
    case 2:
        if (BTL_NET_SendPerapVoice((u32 *)func_02007B44(GAME_DATA_GetSaveControl(setup->gameData)))) ++*state;
        break;
    case 3:
        if (BTL_NET_IsPerapVoiceReceived()) {
            for (i = 0; i < 4; ++i) {
                if (BTL_MAIN_IsClientUsed(main, i) && !BTL_MAIN_IsTrainerSlotNpc(main, (u8)i)) {
                    src = (void *)BTL_NET_GetPerapVoice((u8)i);
                    if (src) {
                        main->voices[i] = func_02007B20(main->heapId);
                        func_02082D44(src, main->voices[i], func_02007B00());
                    }
                }
                BTL_MAIN_StoreClientVoiceFlag(main, (u8)i);
            }
            BTL_NET_ResetAfterPerapVoice();
            ++*state;
        }
        break;
    default:
        return 1;
    }
    return 0;
}




int BTL_MAIN_SeqCreateClientsKind1Solo(struct BtlMain *main)
{
    struct BattleSetupParam *setup;
    u8 clientId;
    int isComm;
    u32 i, flag;
    setup = main->setup;
    clientId = main->ownClientId;
    isComm = (int)BTL_MAIN_IsCommCompetitor(setup);
    if (BTL_NET_HasCommError()) {
        main->flags.commLost = 1;
        return 1;
    }
    if (main->hostsServer) {
        main->server = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
        main->clients[clientId] = BTL_CLIENT_Create(main, &main->sides[0], setup->commPos, setup->netHandle, clientId, (u8)1, 0, isComm, (u8)0, &main->rng, main->heapId);
        BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[clientId]), clientId, 1);
        flag = 1;
        if (clientId != 0) flag = 0;
        BTL_SERVER_CreateClientAdapter(main->server, setup->commPos, setup->netHandle, (u8)flag, 1);
    } else {
        main->clients[clientId] = BTL_CLIENT_Create(main, &main->sides[0], setup->commPos, setup->netHandle, clientId, (u8)1, 0, isComm, (u8)0, &main->rng, main->heapId);
        main->subServer = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
        for (i = 0; i < 4; i++) {
            if (BTL_MAIN_IsClientUsed(main, i))
                BTL_SERVER_SetClientWithoutAdapter(main->subServer, i, 1);
        }
        BTL_CLIENT_SetRequestParam(main->clients[clientId], main->subServer);
    }
    return 1;
}




/*
 * Twin of BTL_MAIN_SeqCreateClientsKind3 and BTL_MAIN_SeqCreateClientsKind1Solo (same callees). The locals clientId, slotCount
 * and isComm must be u8 and BTL_MAIN_IsCommCompetitor must return u8 (it returns only 0 or 1): mwcc keeps
 * the reload of a spilled narrow local below the outgoing stack stores, see
 * docs/idioms/a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local.md. With an int
 * isComm it hoisted the reload and the argument setup order differed (69 bytes).
 */
int BTL_MAIN_SeqCreateClientsByMulti(struct BtlMain *main)
{
    struct BattleSetupParam *setup;
    u8 clientId;
    u8 slotCount;
    u8 isComm;
    u32 i;
    u8 x;
    setup = main->setup;
    clientId = main->ownClientId;
    isComm = BTL_MAIN_IsCommCompetitor(setup);
    slotCount = (setup->multiMode == 0) ? 2 : 1;
    if (BTL_NET_HasCommError()) {
        main->flags.commLost = 1;
        return 1;
    }
    if (main->hostsServer) {
        main->server = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
        main->clients[clientId] = BTL_CLIENT_Create(main, &main->sides[0], setup->commPos, setup->netHandle, clientId, (u8)slotCount, 0, isComm, (u8)0, &main->rng, main->heapId);
        BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[clientId]), clientId, slotCount);
        if (setup->multiMode == 2) {
            x = BTL_MAIN_GetPartnerClient(main, clientId);
            main->clients[1] = BTL_CLIENT_Create(main, &main->sides[0], setup->commPos, setup->netHandle, 1, (u8)slotCount, 1, isComm, (u8)0, &main->rng, main->heapId);
            BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[1]), 1, slotCount);
            main->clients[3] = BTL_CLIENT_Create(main, &main->sides[0], setup->commPos, setup->netHandle, 3, (u8)slotCount, 1, isComm, (u8)0, &main->rng, main->heapId);
            BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[3]), 3, slotCount);
            BTL_SERVER_CreateClientAdapter(main->server, setup->commPos, setup->netHandle, (u8)x, slotCount);
        } else {
            for (i = 0; i < main->clientCount; i++) {
                if (i != clientId)
                    BTL_SERVER_CreateClientAdapter(main->server, setup->commPos, setup->netHandle, (u8)i, slotCount);
            }
        }
    } else {
        main->clients[clientId] = BTL_CLIENT_Create(main, &main->sides[0], setup->commPos, setup->netHandle, clientId, (u8)slotCount, 0, isComm, (u8)0, &main->rng, main->heapId);
        main->subServer = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
        for (i = 0; i < 4; i++) {
            if (BTL_MAIN_IsClientUsed(main, i))
                BTL_SERVER_SetClientWithoutAdapter(main->subServer, i, BTL_MAIN_GetPositionsPerClient(main, (u8)i));
        }
        BTL_CLIENT_SetRequestParam(main->clients[clientId], main->subServer);
    }
    return 1;
}





int BTL_MAIN_SeqCreateClientsKind3(struct BtlMain *main)
{
    struct BattleSetupParam *setup;
    u8 clientId;
    int isComm;
    u32 i, flag;
    setup = main->setup;
    clientId = main->ownClientId;
    isComm = (int)BTL_MAIN_IsCommCompetitor(setup);
    if (BTL_NET_HasCommError()) {
        main->flags.commLost = 1;
        return 1;
    }
    if (main->hostsServer) {
        main->server = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
        main->clients[clientId] = BTL_CLIENT_Create(main, &main->sides[0], setup->commPos, setup->netHandle, clientId, (u8)3, 0, isComm, (u8)0, &main->rng, main->heapId);
        BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[clientId]), clientId, 3);
        flag = 0;
        if (clientId == 0) flag = 1;
        BTL_SERVER_CreateClientAdapter(main->server, setup->commPos, setup->netHandle, (u8)flag, 3);
    } else {
        main->clients[clientId] = BTL_CLIENT_Create(main, &main->sides[0], setup->commPos, setup->netHandle, clientId, (u8)3, 0, isComm, (u8)0, &main->rng, main->heapId);
        main->subServer = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
        for (i = 0; i < 4; i++) {
            if (BTL_MAIN_IsClientUsed(main, i))
                BTL_SERVER_SetClientWithoutAdapter(main->subServer, i, BTL_MAIN_GetPositionsPerClient(main, (u8)i));
        }
        BTL_CLIENT_SetRequestParam(main->clients[clientId], main->subServer);
    }
    return 1;
}





int BTL_MAIN_SeqCreateClientsKind1(struct BtlMain *main)
{
    u8 clientId;
    struct BattleSetupParam *setup;
    int isComm;
    u32 i;
    clientId = main->ownClientId;
    setup = main->setup;
    isComm = (int)BTL_MAIN_IsCommCompetitor(setup);
    if (BTL_NET_HasCommError()) {
        main->flags.commLost = 1;
        return 1;
    }
    if (main->hostsServer) {
        main->server = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
        main->clients[clientId] = BTL_CLIENT_Create(main, &main->sides[0], setup->commPos, setup->netHandle, clientId, (u8)1, 0, isComm, (u8)0, &main->rng, main->heapId);
        BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[clientId]), clientId, 1);
        for (i = 0; i < main->clientCount; i++) {
            if (i != clientId)
                BTL_SERVER_CreateClientAdapter(main->server, setup->commPos, setup->netHandle, (u8)i, 1);
        }
    } else {
        main->clients[clientId] = BTL_CLIENT_Create(main, &main->sides[0], setup->commPos, setup->netHandle, clientId, (u8)1, 0, isComm, (u8)0, &main->rng, main->heapId);
        main->subServer = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
        for (i = 0; i < 4; i++) {
            if (BTL_MAIN_IsClientUsed(main, i))
                BTL_SERVER_SetClientWithoutAdapter(main->subServer, i, BTL_MAIN_GetPositionsPerClient(main, (u8)i));
        }
        BTL_CLIENT_SetRequestParam(main->clients[clientId], main->subServer);
    }
    return 1;
}





int BTL_MAIN_SeqCreateView(struct BtlMain *main, int *step)
{
    int isComm;
    struct BtlvCore *viewCore;
    if (BTL_NET_HasCommError()) {
        main->flags.commLost = 1;
        return 1;
    }
    if (*step == 0) {
        isComm = BTL_MAIN_IsCommCompetitor(main->setup);
        viewCore = BTLV_CORE_Create(main, main->clients[main->ownClientId], &main->sides[0], isComm, 0x13);
        main->viewCore = viewCore;
        BTL_CLIENT_SetView(main->clients[main->ownClientId], viewCore);
        if (main->hostsServer) {
            main->tick = BTL_MAIN_StepParent;
            BTL_SERVER_Restart(main->server);
        } else {
            main->tick = BTL_MAIN_StepChild;
        }
        *step = *step + 1;
    } else {
        return 1;
    }
    return 0;
}






int BTL_MAIN_StepClientsSolo(struct BtlMain *main)
{
    int i, found = 0;
    BTL_SERVER_Update(main->server);
    for (i = 0; i < 4; i++) {
        if (main->clients[i] != 0 &&
            BTL_CLIENT_RunTick(main->clients[i]) != 0) {
            BTL_CLIENT_GetCursor(main->clients[i], &main->defeatedClients);
            found = 1;
        }
    }
    BTLV_CORE_Update(main->viewCore);
    return found;
}






int BTL_MAIN_StepParent(struct BtlMain *main)
{
    int r, i;
    if (main->flags.commLost == 0) {
        if (BTL_NET_HasCommError()) {
            main->flags.commLost = 1;
            BTL_MAIN_MarkClientsDisconnected(main);
        }
    } else if (main->flags.commLostHandled != 0) {
        return 1;
    }
    r = BTL_SERVER_Update(main->server);
    if (r) {
        BTL_SERVER_GetFinalData(main->server, &main->defeatedClients);
    }
    for (i = 0; i < 4; i++) {
        if (main->clients[i] != 0 && main->clientReady[i] == 0) {
            main->clientReady[i] = BTL_CLIENT_RunTick(main->clients[i]);
        }
    }
    if (BTL_MAIN_CheckAllClientsReady(main)) {
        BTL_CLIENT_GetCursor(main->clients[main->ownClientId], &main->defeatedClients);
        r = 1;
    }
    BTLV_CORE_Update(main->viewCore);
    return r;
}






int BTL_MAIN_StepChild(struct BtlMain *main)
{
    int r, i;
    if (main->flags.commLost == 0) {
        if (BTL_NET_HasCommError()) {
            main->flags.commLost = 1;
            BTL_MAIN_MarkClientsDisconnected(main);
        }
    } else if (main->flags.commLostHandled != 0) {
        return 1;
    }
    r = 0;
    for (i = 0; i < 4; i++) {
        if (main->clients[i] != 0 &&
            BTL_CLIENT_RunTick(main->clients[i]) != 0) {
            BTL_CLIENT_GetCursor(main->clients[i], &main->defeatedClients);
            r = 1;
        }
    }
    BTLV_CORE_Update(main->viewCore);
    return r;
}





void BTL_MAIN_MarkClientsDisconnected(struct BtlMain *main)
{
    unsigned int i;
    for (i = 0; i < 4; i++) {
        void *client = main->clients[i];
        if (client) BTL_CLIENT_MarkCommandIssued(client);
    }
}





int BTL_MAIN_CheckAllClientsReady(struct BtlMain *main)
{
    unsigned int i;
    for (i = 0; i < 4; i++) {
        if (main->clients[i] != 0 && main->clientReady[i] == 0) return 0;
    }
    return 1;
}






u32 BTL_MAIN_GetRule(struct BtlMain *main)
{
    return main->setup->rule;
}





unsigned int BTL_MAIN_CheckSceneOff(struct BtlMain *main) { return main->flags.noBattleAnim; }






/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; adds r0, #0x80; ldrb r0, [r0]; bx lr.
 */
u8 BTL_MAIN_GetBadgeCount(struct BtlMain *main) { return main->setup->badgeCount; }





/*
 * note 2026-10-05: the arm9 witness src/matched/arm9/CONFIG_GetBattleStyle.c exists (EXACT); the only wildcard is that bl, so this lifts to EXACT after the integrator regenerates the manifest/labels.
 */
int BTL_MAIN_CheckShiftModePrompt(struct BtlMain *main)
{
    if (BTL_MAIN_GetCompetitor(main) == 1 && BTL_MAIN_GetRule(main) == 0 && BTL_MAIN_GetCommPos(main) == 0 && CONFIG_GetBattleStyle(main->setup->config) == 0) return 1;
    return 0;
}





int BTL_MAIN_GetTextSpeedFrames(struct BtlMain *main) { return func_02013080(main->textSpeed); }






int BTL_MAIN_CheckEventOverlayAllowed(struct BtlMain *main)
{
    int r;
    if (main->setup->competitor <= 1) {
        func_02034AC4((int)ov231_id);
        r = func_021809D8();
        func_02034A5C((int)ov231_id);
        if (r == 0) {
            return 0;
        }
        if (BTL_MAIN_CheckSetupStatusFlag(main, 0x200) == 0) {
            return 1;
        }
    }
    return 0;
}






/* 021B8630  first round: the guard "competitor > 1 return 0" came back bls.  The image
 * takes the guard, so the guarded read is the fall-through arm. */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldr r1, [r0]; ldr r0, [r1]; cmp r0, #1; bhi loc_021B863C; ldr r0, [r1, #0x70]; bx lr; movs r0, #0; bx lr.
 */
u32 BTL_MAIN_GetPmsWork(struct BtlMain *main)
{
    struct BattleSetupParam *setup = main->setup;
    if (setup->competitor <= 1)
        return setup->pmsWork;
    return 0;
}





unsigned int BTL_MAIN_GetRuleSlotSpan(struct BtlMain *main) { switch (main->setup->rule) { case 0:return 1; case 1:return 3; case 2:return 5; case 3:return 5; default:return 5; } }





unsigned int BTL_MAIN_GetActivePosPerSide(struct BtlMain *main) { switch (main->setup->rule) { case 0:return 1; case 1:return 2; case 2:return 3; case 3:return 1; default:return 1; } }





int BTL_MAIN_CheckFrontPos(struct BtlMain *main, unsigned int posIdx) { if (posIdx < BTL_MAIN_GetActivePosPerSide(main)*2) return 1; return 0; }





u32 BTL_MAIN_GetCompetitor(struct BtlMain *main)
{
    return main->setup->competitor;
}






/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; adds r0, #0x20; ldrb r0, [r0]; bx lr.
 */
u8 BTL_MAIN_GetCommPos(struct BtlMain *main) { return main->setup->commPos; }





/*
 * The SDK symbol list names 0x021B86CA CTRDGi_IsTaskBusy(pt), the busy-flag test (pt->busy != 0).
 * That address lies inside this function (adds #0x22 after the ldr): it is not a separate entry.
 * The final two zero bytes are alignment padding before the next function.
 */
int BTL_MAIN_IsMultiMode(struct BtlMain *main) { if (main->setup->multiMode) return 1; return 0; }





u16 BTL_MAIN_GetWinBgm(struct BtlMain *main)
{
    return main->setup->bgmWin;
}


int BTL_MAIN_GetCompetitorKind(struct BtlMain *main) { switch(main->setup->competitor) { case 0:return 0; case 1:return 1; case 2:return 2; case 3:return 2; default:return 1; } }


struct FieldSituation *BTL_MAIN_GetFieldSituation(struct BtlMain *main)
{
    return &main->setup->fieldSituation;
}



int BTL_MAIN_GetPlayerStatus(struct BtlMain *main)
{
    return (int)main->playerStatus;
}


int BTL_MAIN_CheckZukanSeen(struct BtlMain *main, void *mon) { unsigned int species=BTL_POKEPARAM_GetSpecies(mon); return func_0200CED4(main->setup->zukanWork,species); }


u32 BTL_MAIN_GetZukanSeenCount(struct BtlMain *main)
{
    return func_0200CF28((struct Blk37 *)(main->setup->zukanWork));
}



u32 BTL_MAIN_GetGameData(struct BtlMain *main)
{
    return (u32)main->setup->gameData;
}


void BTL_MAIN_RegisterZukanSeen(struct BtlMain *main, unsigned char doRegister, void *mon) { if(BTL_MAIN_GetCompetitor(main)<=1 && doRegister!=0) func_0200CFA0(main->setup->zukanWork,BTL_POKEPARAM_GetMon(mon)); }



u8 BTL_MAIN_DecodeMessageCode(struct BtlMain *main, int code, u8 *out)
{
    u8 hi = code >> 8;
    u8 lo = code;

    if (hi == 0) {
        *out = lo;
        return *out != 6;
    }
    if (lo != 6) {
        switch (main->setup->rule) {
        case 0:
        default:
            return BTL_MAIN_DecodeMessageCodeBasic(main, hi, lo, out);
        case 1:
            return BTL_MAIN_ExpandPosDouble(main, hi, lo, out);
        case 2:
            return BTL_MAIN_ExpandPosTriple(main, hi, lo, out);
        case 3:
            return BTL_MAIN_DecodeMessageCodeBasic(main, hi, lo, out);
        }
    }
    *out = 6;
    return 0;
}



u8 BTL_MAIN_DecodeMessageCodeBasic(struct BtlMain *main, u32 k, u32 v, u8 *out)
{
    switch (k) {
    case 0:
    case 4:
    case 7:
    default:
        return 0;
    case 1:
    case 2:
    case 6:
        *out = BTL_MAIN_GetEnemyLanePosFromWork(main, v, 0);
        break;
    case 3:
        *out = v;
        break;
    case 5:
    case 8:
        out[0] = 0;
        out[1] = 1;
        return 2;
    }
    return 1;
}


/*
 * Double battle: fill out[] with the positions that a range kind reaches
 * from basePos and return how many were written.
 */
u8 BTL_MAIN_ExpandPosDouble(struct BtlMain *main, u32 rangeType, u8 basePos, u8 *out)
{
    u8 tmp;

    switch (rangeType) {
    case BTL_RANGE_DEFAULT:
    default:
        return 0;
    case BTL_RANGE_ENEMIES_IN_REACH:
    case BTL_RANGE_ALL_ENEMIES:
        out[0] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 0);
        out[1] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 1);
        return 2;
    case BTL_RANGE_OTHERS_IN_REACH:
        out[0] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 0);
        out[1] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 1);
        out[2] = BTL_MAIN_MapPosForRule(main, basePos);
        return 3;
    case BTL_RANGE_SELF_AND_ALLIES_IN_REACH:
        out[0] = basePos;
        out[1] = BTL_MAIN_MapPosForRule(main, basePos);
        if (out[0] > out[1]) {
            tmp = out[0];
            out[0] = out[1];
            out[1] = tmp;
        }
        return 2;
    case BTL_RANGE_ALLIES_IN_REACH:
    case BTL_RANGE_ALLIES_IN_REACH_ALT:
        out[0] = BTL_MAIN_MapPosForRule(main, basePos);
        return 1;
    case BTL_RANGE_ALL_ALLIES:
        out[0] = basePos;
        out[1] = BTL_MAIN_MapPosForRule(main, basePos);
        return 2;
    case BTL_RANGE_ALL_IN_REACH:
    case BTL_RANGE_EVERY_POSITION:
        out[0] = 0;
        out[1] = 1;
        out[2] = 2;
        out[3] = 3;
        return 4;
    }
}


/*
 * Triple battle: fill out[] with the positions that a range kind reaches
 * from basePos and return how many were written. A position in the middle
 * row (BTL_MAIN_IsBackRowPos) reaches all three lanes of the other side; a position
 * in an outer row reaches the centre lane and the lane that faces it.
 * The facing-lane swap is written out in each case, as in the original.
 */
u8 BTL_MAIN_ExpandPosTriple(struct BtlMain *main, u32 rangeType, u32 basePos, u8 *out)
{
    u8 inMiddleRow = BTL_MAIN_IsBackRowPos(basePos);
    u8 facingLane;

    switch (rangeType) {
    case BTL_RANGE_DEFAULT:
    case BTL_RANGE_ENEMIES_IN_REACH:
    default:
        if (inMiddleRow) {
            out[0] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 0);
            out[1] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 1);
            out[2] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 2);
            return 3;
        }
        out[0] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 1);
        facingLane = (u8)(basePos >> 1);
        if (facingLane == 0) facingLane = 2;
        else if (facingLane == 2) facingLane = 0;
        out[1] = BTL_MAIN_GetEnemyLanePos(2, basePos, facingLane);
        return 2;
    case BTL_RANGE_ALL_ENEMIES:
        out[0] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 0);
        out[1] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 1);
        out[2] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 2);
        return 3;
    case BTL_RANGE_ALL_ALLIES:
        out[0] = BTL_MAIN_GetOwnLanePos(basePos, 0);
        out[1] = BTL_MAIN_GetOwnLanePos(basePos, 1);
        out[2] = BTL_MAIN_GetOwnLanePos(basePos, 2);
        return 3;
    case BTL_RANGE_EVERY_POSITION:
        out[0] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 0);
        out[1] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 1);
        out[2] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 2);
        out[3] = BTL_MAIN_GetOwnLanePos(basePos, 0);
        out[4] = BTL_MAIN_GetOwnLanePos(basePos, 1);
        out[5] = BTL_MAIN_GetOwnLanePos(basePos, 2);
        return 6;
    case BTL_RANGE_OTHERS_IN_REACH:
        if (inMiddleRow) {
            out[0] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 0);
            out[1] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 1);
            out[2] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 2);
            out[3] = BTL_MAIN_GetOwnLanePos(basePos, 0);
            out[4] = BTL_MAIN_GetOwnLanePos(basePos, 2);
            return 5;
        }
        out[0] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 1);
        facingLane = (u8)(basePos >> 1);
        if (facingLane == 0) facingLane = 2;
        else if (facingLane == 2) facingLane = 0;
        out[1] = BTL_MAIN_GetEnemyLanePos(2, basePos, facingLane);
        out[2] = BTL_MAIN_GetOwnLanePos(basePos, 1);
        return 3;
    case BTL_RANGE_SELF_AND_ALLIES_IN_REACH:
        if (inMiddleRow) {
            out[0] = basePos;
            out[1] = BTL_MAIN_GetOwnLanePos(basePos, 0);
            out[2] = BTL_MAIN_GetOwnLanePos(basePos, 2);
            return 3;
        }
        out[0] = basePos;
        out[1] = BTL_MAIN_GetOwnLanePos(basePos, 1);
        return 2;
    case BTL_RANGE_ALLIES_IN_REACH_ALT:
        if (inMiddleRow) {
            out[0] = BTL_MAIN_GetOwnLanePos(basePos, 0);
            out[1] = BTL_MAIN_GetOwnLanePos(basePos, 2);
            return 2;
        }
        out[0] = BTL_MAIN_GetOwnLanePos(basePos, 1);
        return 1;
    case BTL_RANGE_ALLIES_IN_REACH:
        if (inMiddleRow) {
            out[0] = BTL_MAIN_GetOwnLanePos(basePos, 0);
            out[1] = BTL_MAIN_GetOwnLanePos(basePos, 2);
            return 2;
        }
        out[0] = BTL_MAIN_GetOwnLanePos(basePos, 1);
        return 1;
    case BTL_RANGE_ALL_IN_REACH:
        if (inMiddleRow) {
            out[0] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 0);
            out[1] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 1);
            out[2] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 2);
            out[3] = BTL_MAIN_GetOwnLanePos(basePos, 0);
            out[4] = BTL_MAIN_GetOwnLanePos(basePos, 2);
            out[5] = basePos;
            return 6;
        }
        out[0] = BTL_MAIN_GetEnemyLanePosFromWork(main, basePos, 1);
        facingLane = (u8)(basePos >> 1);
        if (facingLane == 0) facingLane = 2;
        else if (facingLane == 2) facingLane = 0;
        out[1] = BTL_MAIN_GetEnemyLanePos(2, basePos, facingLane);
        out[2] = BTL_MAIN_GetOwnLanePos(basePos, 1);
        out[3] = basePos;
        return 4;
    }
}


/* Number of trainer entries that are controlled by clientId. */
unsigned int BTL_MAIN_CountClientTrainers(struct BtlMain *main, int clientId)
{
    unsigned int count;
    unsigned int i;

    i = 0;
    count = 0;
    for (; i < 6; i++) {
        if (clientId == main->slotClientIds[i]) {
            count++;
        }
    }
    return count;
}

/* Nonzero when clientId (0..3) controls at least one trainer entry. */
int BTL_MAIN_IsClientUsed(struct BtlMain *main, unsigned char clientId)
{
    unsigned int i;

    if (clientId < 4) {
        for (i = 0; i < 6; i++) {
            if (clientId == main->slotClientIds[i]) {
                return 1;
            }
        }
    }
    return 0;
}

/* Side of a client: bit 0 of its id. The main pointer is not read. */
unsigned char BTL_MAIN_GetClientSide(int unusedWork, unsigned int clientId)
{
    (void)unusedWork;
    return clientId & 1;
}

/* Nonzero when side is the side of the local network id. */
int BTL_MAIN_IsLocalSide(struct BtlMain *main, unsigned char side)
{
    if (side == BTL_MAIN_GetClientSide((int)main, main->ownClientId)) {
        return 1;
    }
    return 0;
}


/* Index of the nth trainer entry that clientId controls, or 6 when none. */
u8 BTL_MAIN_GetClientTrainerIndex(struct BtlMain *main, u32 clientId, u8 nth)
{
    u8 i;

    for (i = 0; i < 6; i++) {
        if (clientId == main->slotClientIds[i]) {
            if (nth == 0) {
                return i;
            }
            nth--;
        }
    }
    return 6;
}


/*
 * Position of a lane on the side opposite to basePos. The rule argument is
 * not read here; it keeps the call shape of BTL_MAIN_GetEnemyLanePosFromWork.
 */
u8 BTL_MAIN_GetEnemyLanePos(int rule, u32 basePos, u32 lane)
{
    if ((basePos & 1) == 0) {
        return lane * 2 + 1;
    }
    return lane * 2;
}


/* Position of a lane on the same side as basePos. */
u8 BTL_MAIN_GetOwnLanePos(u32 basePos, u32 lane)
{
    if ((basePos & 1) == 0) {
        return lane * 2;
    }
    return lane * 2 + 1;
}


/* Enemy side lane position, with the battle rule taken from the setup. */
u8 BTL_MAIN_GetEnemyLanePosFromWork(struct BtlMain *main, u32 basePos, int lane)
{
    return BTL_MAIN_GetEnemyLanePos(main->setup->rule, basePos, lane);
}


/* Position that faces basePos across the field, by battle rule. */
u8 BTL_MAIN_GetFacingPos(int rule, u32 basePos)
{
    u8 lane;

    switch (rule) {
    default:
    case 0:
        return BTL_MAIN_GetEnemyLanePos(rule, basePos, 0);
    case 1:
        lane = basePos >> 1;
        return BTL_MAIN_GetEnemyLanePos(rule, basePos, (u8)(1 ^ lane));
    case 2:
        lane = basePos >> 1;
        if (lane == 0) {
            lane = 2;
        } else if (lane == 2) {
            lane = 0;
        }
        return BTL_MAIN_GetEnemyLanePos(rule, basePos, lane);
    case 3:
        return BTL_MAIN_GetEnemyLanePos(rule, basePos, 0);
    }
}


u8 BTL_MAIN_MapPosForRule(struct BtlMain *main, u8 basePos)
{
    switch (main->setup->rule) {
    case 0:
        return basePos;
    case 3:
        return basePos;
    case 1:
        return (basePos + 2) & 3;
    case 2:
        return basePos;
    }
    return basePos;
}












int BTL_MAIN_IsOpposingPos(int unusedWork, int posA, int posB)
{
    int differs = 1;
    if ((posA & 1) == (posB & 1)) differs = 0;
    return differs;
}












unsigned char BTL_MAIN_GetSlotClientId(struct BtlMain *main, int slot)
{
    return main->slotClientIds[slot];
}













u8 BTL_MAIN_PokeIdToClientId(u32 pokeId)
{
    u8 clientId;
    for (clientId = 0; clientId < 4; clientId++) {
        u8 first = gClientFirstPokeIds[clientId];
        u8 last = first + 5;
        if (pokeId >= first && pokeId <= last) return clientId;
    }
    return 0;
}













u8 BTL_MAIN_CollectLivingPokeIds(struct BtlMain *main, struct BtlSide *side, int code, u8 *outPokeIds)
{
    u8 positions[8];
    u8 posCount;
    u8 count;
    u8 i;
    struct BtlPokeParam *poke;

    posCount = BTL_MAIN_DecodeMessageCode(main, code, positions);
    i = 0;
    count = 0;
    for (; i < posCount; i++) {
        poke = BTL_SIDE_GetPokeAtPosThunk(side, positions[i]);
        if (poke && !BTL_POKEPARAM_IsFainted(poke)) {
            outPokeIds[count++] = BTL_POKEPARAM_GetPokeId(poke);
        }
    }
    return count;
}













u8 BTL_MAIN_GetTrainerSlotOfPoke(struct BtlMain *main, struct BtlSide *side, u32 pokeId)
{
    u8 clientId = BTL_MAIN_PokeIdToClientId(pokeId);
    int index = BTL_SIDE_FindPokeIndexInClient(side, clientId, pokeId);

    if (index >= 0) {
        u8 slot = BTL_MAIN_GetClientTrainerIndex(main, clientId, index);
        if (slot != 6) return slot;
    }
    return 6;
}












unsigned char BTL_MAIN_GetViewPosOfPoke(struct BtlMain *main, struct BtlSide *side, unsigned int pokeId)
{
    int slot = BTL_MAIN_GetTrainerSlotOfPoke(main, side, pokeId);
    if (slot != 6) return BTL_MAIN_GetViewPosOfSlot(main, slot);
    return 255;
}













/*
 * tail-call thunk to BTL_MAIN_PokeIdToClientId
 */
u8 BTL_MAIN_PokeIdToClientIdThunk(u32 pokeId)
{
    return BTL_MAIN_PokeIdToClientId(pokeId);
}













u8 BTL_MAIN_GetSlotClientIdThunk(struct BtlMain *main, int slot)
{
    return BTL_MAIN_GetSlotClientId(main, slot);
}












unsigned char BTL_MAIN_GetSlotNthOfClient(struct BtlMain *main, unsigned char slot)
{
    unsigned char i, clientId, count;
    i = slot;
    clientId = BTL_MAIN_GetSlotClientId(main, slot);
    count = 0;
    while (i-- != 0) {
        if (clientId == main->slotClientIds[i]) count++;
    }
    return count;
}













void BTL_MAIN_GetSlotClientAndNth(struct BtlMain *main, u8 slot, u8 *outClientId, u8 *outNth)
{
    u8 i = slot;
    u8 count;
    *outClientId = BTL_MAIN_GetSlotClientId(main, slot);
    count = 0;
    while (i-- != 0) {
        if (*outClientId == main->slotClientIds[i]) {
            count++;
        }
    }
    *outNth = count;
}













u8 BTL_MAIN_GetViewPosOfSlot(struct BtlMain *main, u32 slot)
{
    int sameSide = 1;
    u8 side;
    u32 rule;
    int result;
    if ((main->ownFirstSlot & 1) != (slot & 1)) {
        sameSide = 0;
    }
    side = sameSide;
    rule = main->setup->rule;
    if (rule == 0) {
        result = 0;
        if (side == 0) {
            result = 1;
        }
        return result;
    }
    if (rule == 1) {
        return gViewPosOfSlotDouble[side][(u8)(slot >> 1)];
    }
    return gViewPosOfSlotTriple[side][(u8)(slot >> 1)];
}













u8 BTL_MAIN_GetSlotFromViewPos(struct BtlMain *main, u8 slot)
{
    u8 parity = slot & 1;
    u32 rule = main->setup->rule;
    u8 ownParity;
    int result;
    if (rule == 0) {
        if (parity != 0) {
            result = 1;
            if (main->ownFirstSlot != 0) {
                result = 0;
            }
            return result;
        }
        return main->ownFirstSlot;
    }
    ownParity = main->ownFirstSlot & 1;
    if (parity != 0) {
        return (ownParity ^ 1) + (slot - 3);
    }
    return ownParity + (slot - 2);
}












int BTL_MAIN_IsCommMulti(struct BtlMain *main)
{
    unsigned int competitor;
    if (BTL_MAIN_IsMultiMode(main)) {
        competitor = BTL_MAIN_GetCompetitor(main);
        if (competitor != 1 && competitor != 0) return 1;
    }
    return 0;
}












int BTL_MAIN_SyncSideParty(struct BtlMain *main, int clientId)
{
    BTL_SIDE_WriteBackParty(&main->sides[0], main, clientId, 0);
    return BTL_SIDE_GetParty(&main->sides[0], clientId);
}













int BTL_MAIN_SyncPartnerSideParty(struct BtlMain *main, u32 clientId)
{
    u8 partner;
    if (BTL_MAIN_IsMultiMode(main)) {
        partner = (clientId + 2) & 3;
        if (BTL_MAIN_IsClientUsed(main, partner)) {
            BTL_SIDE_WriteBackParty(&main->sides[0], main, partner, 0);
            return BTL_SIDE_GetParty(&main->sides[0], partner);
        }
    }
    return 0;
}












unsigned char BTL_MAIN_IsSecondTeamClient(struct BtlMain *main, unsigned int clientId)
{
    if (BTL_MAIN_IsMultiMode(main)) return (unsigned char)((clientId & 2) != 0);
    return 0;
}












u8 BTL_MAIN_IsOwnClientSecondTeam(struct BtlMain *main)
{
    return BTL_MAIN_IsSecondTeamClient(main, main->ownClientId);
}













u8 BTL_MAIN_GetOwnClientId(struct BtlMain *main)
{
    return main->ownClientId;
}












u8 BTL_MAIN_GetOwnPartnerClient(struct BtlMain *main) { return BTL_MAIN_GetPartnerClient(main, main->ownClientId); }












u8 BTL_MAIN_GetPartnerClient(struct BtlMain *main, u8 clientId)
{
    u8 partner;
    partner = (clientId + 2) & 3;
    if (!BTL_MAIN_IsClientUsed(main, partner)) partner = 4;
    return partner;
}












int BTL_MAIN_IsSameTeamClient(int clientA, int clientB)
{
    if (clientA == clientB) return 1;
    if (clientA == (u8)((clientB + 2) & 3)) return 1;
    return 0;
}












u8 BTL_MAIN_GetOwnOpponentClient(struct BtlMain *main, int nth)
{
    return BTL_MAIN_GetOpponentClient(main, main->ownClientId, nth);
}












u32 BTL_MAIN_GetOpponentClient(struct BtlMain *main, int clientId, int nth)
{
    u8 candidate;
    clientId &= 1;
    clientId ^= 1;
    if (nth) {
        candidate = clientId + ((nth & 1) << 1);
        if (BTL_MAIN_IsClientUsed(main, candidate)) clientId = candidate;
    }
    return clientId;
}












void BTL_MAIN_AddItemToBag(struct BtlMain *main, u32 clientId, u32 itemId)
{
    struct BattleSetupParam *setup;
    setup = main->setup;
    if (setup->ownsSlots == 0 && clientId == main->ownClientId) func_02007F1C(setup->myItem, itemId, 1, main->heapId);
}












void BTL_MAIN_SubItemFromBag(struct BtlMain *main, u8 clientId, u32 itemId)
{
    struct BattleSetupParam *setup;
    setup = main->setup;
    if (setup->ownsSlots == 0 && clientId == main->ownClientId) func_02007E50(setup->myItem, itemId, 1, main->heapId);
}













/*
 * double deref: *(u32*)(*p + 0x60)
 */
u32 BTL_MAIN_GetMyItem(struct BtlMain *main)
{
    return (u32)main->setup->myItem;
}













/*
 * double deref: *(u32*)(*p + 0x64)
 */
u32 BTL_MAIN_GetMapMatrix(struct BtlMain *main)
{
    return (u32)main->setup->mapMatrix;
}












int BTL_MAIN_IsRecordingActive(struct BtlMain *main)
{
    struct BattleSetupParam *setup;
    setup = main->setup;
    if (setup->recordBuffer != 0 && setup->ownsSlots == 0) return 1;
    return 0;
}













/* 021B9114  ldr r0,[r0]; adds r0,#0x23; ldrb r0,[r0] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; adds r0, #0x23; ldrb r0, [r0]; bx lr.
 */
u8 BTL_MAIN_GetOwnsSlots(struct BtlMain *main) { return main->setup->ownsSlots; }













/* 021B911C  movs r0,#0; bx lr */
/*
 * Returns the constant #0.
 */
int BTL_MAIN_ReturnZero(struct BtlMain *main, int unused) { return 0; }












void BTL_MAIN_StoreSlotNthResult(struct BtlMain *main, u8 slot)
{
    u8 count;
    u8 clientId;
    u8 i;
    if (main->setup->resultValue[0] == 6) {
        i = slot;
        clientId = BTL_MAIN_GetSlotClientId(main, slot);
        count = 0;
        while (i--) {
            if (clientId == main->slotClientIds[i])
                count++;
        }
        main->setup->resultValue[0] = count;
    }
}












void BTL_MAIN_SetOutcomeIfUnset(struct BtlMain *main, u32 outcome)
{
    if (main->outcome == 7) main->outcome = outcome;
}













/*
 * tail-call thunk to BTL_MAIN_JudgeResult
 */
int BTL_MAIN_JudgeResultThunk(struct BtlMain *main)
{
    return BTL_MAIN_JudgeResult(main);
}












void BTL_MAIN_SetRecordInvalid(struct BtlMain *main)
{
    main->setup->bits.recordInvalid = 1;
}













u32 BTL_MAIN_GetPrizeMoney(struct BtlMain *main)
{
    if (main->flags.moneyLocked == 0) {
        if (main->flags.doubleMoney) {
            main->prizeMoney = main->prizeMoney << 1;
        }
        main->prizeMoney = GPOWER_ApplyPrizeMoney(main->prizeMoney);
        main->flags.moneyLocked = 1;
    }
    return main->prizeMoney;
}













/*
 * Unlabelled Thumb leaf in a .word run.  If bit 3 of p[0x473] is clear,
 * adds `add` to the word at p+0x434 and clamps it to 0x1869f.
 * The bit test is a lsls #0x1c / lsrs #0x1f pair, so the promoted value
 * must stay unsigned.
 */
void BTL_MAIN_AddBonusMoney(struct BtlMain *main, int add)
{
    if (((unsigned int)(*(u8 *)&main->flags) << 28 >> 31) != 0)
        return;
    main->bonusMoney += add;
    if ((u32)main->bonusMoney > 0x1869f)
        main->bonusMoney = 0x1869f;
}












u32 BTL_MAIN_GetBonusMoney(struct BtlMain *main)
{
    u32 money;
    money = main->bonusMoney;
    if (main->flags.doubleMoney) {
        money *= 2;
        if (money > 99999) money = 99999;
    }
    return money;
}












/*
 * Unlabelled Thumb leaf in a .word run:
 *   ldr r2,[pc,#8]; movs r1,#0x40; ldrb r3,[r0,r2]; orrs r1,r3; strb r1,[r0,r2]; bx lr
 * with pool word 0x473.  Sets bit 6 of the byte at p+0x473.
 */
void BTL_MAIN_SetDoubleMoney(struct BtlMain *main)
{
    main->flags.doubleMoney = 1;
}













u32 BTL_MAIN_CalcPenaltyMoney(struct BtlMain *main)
{
    u32 penalty;
    u32 maxLoss;
    u32 loss;

    penalty = 0;
    if (main->flags.penaltyDone == 0) {
        if (main->setup->competitor <= 1) {
            maxLoss = func_0200C274(GAME_DATA_GetMiscSave(main->setup->gameData));
            loss = BTL_CALC_CalcDefeatMoneyLoss(main->setup->badgeCount, BTL_SIDE_GetSlotOfClientThunk(&main->sides[1], main->ownClientId));
            if (loss > maxLoss)
                loss = maxLoss;
            penalty = loss;
            main->penaltyMoney = penalty;
        }
        main->flags.penaltyDone = 1;
    }
    return penalty;
}












void BTL_MAIN_SetKeepBgm(struct BtlMain *main)
{
    main->flags.keepBgm = 1;
}












void BTL_MAIN_UpdateFriendshipIfPlayer(struct BtlMain *main, struct BtlPokeParam *poke, int isHigh)
{
    struct BattleSetupParam *setup;
    setup = main->setup;
    if (setup->competitor <= 1 && setup->ownsSlots == 0) BTL_MAIN_UpdateFriendship(main, poke, isHigh ? 5 : 4);
}













void BTL_MAIN_UpdateFriendship(struct BtlMain *main, struct BtlPokeParam *poke, int event)
{
    u8 pokeId;
    void *snapshotMon;
    void *liveMon;
    struct FieldSituation *field;

    pokeId = BTL_POKEPARAM_GetPokeId(poke);
    snapshotMon = BTL_SIDE_GetPokeById(&main->sides[1], pokeId);
    liveMon = BTL_SIDE_GetPokeById(&main->sides[0], pokeId);
    snapshotMon = BTL_POKEPARAM_GetMon(snapshotMon);
    liveMon = BTL_POKEPARAM_GetMon(liveMon);
    field = BTL_MAIN_GetFieldSituation(main);
    NATSUKI_Calc(snapshotMon, event, field->zoneId, (u16)((main->heapId & 0x7fff) | 0x8000));
    NATSUKI_Calc(liveMon, event, field->zoneId, (u16)((main->heapId & 0x7fff) | 0x8000));
}












void BTL_MAIN_CopyLiveToSnapshotPoke(struct BtlMain *main, int pokeId)
{
    struct BtlPokeParam *snapshot = BTL_SIDE_GetPokeByIdThunk(&main->sides[1], pokeId);
    struct BtlPokeParam *live = BTL_SIDE_GetPokeByIdThunk(&main->sides[0], pokeId);
    func_021D54F4(live, snapshot);
}













struct BtlPokeParam *BTL_MAIN_ResolveIllusionPoke(struct BtlMain *main, struct BtlSide *side, struct BtlPokeParam *poke)
{
    struct BtlPokeParam *member;
    void *displayMon;
    void *memberMon;
    int clientId;
    struct BtlSideSlot *slot;
    u32 count;
    u32 i;

    if (BTL_POKEPARAM_IsIllusionActive(poke)) {
        clientId = BTL_MAIN_PokeIdToClientIdThunk(BTL_POKEPARAM_GetPokeId(poke));
        displayMon = BTL_POKEPARAM_GetDisplayMon(poke);
        slot = BTL_SIDE_GetSlotOfClientThunk(side, clientId);
        count = BTL_SLOT_GetCount(slot);
        for (i = 0; i < count; i++) {
            member = BTL_SLOT_GetPokeParam(slot, (u8)i);
            memberMon = BTL_POKEPARAM_GetMon(member);
            if (memberMon == displayMon)
                return member;
        }
    }
    return poke;
}













void BTL_SIDE_Init(struct BtlSide *side, struct BtlMain *main, u32 sideIndex)
{
    u32 i;
    u32 j;
    u32 k;

    side->main = main;
    side->sideIndex = sideIndex;
    for (i = 0; i < 4; i++)
        BTL_SLOT_Clear(&side->slots[i]);
    for (j = 0; j < 0x18; j++)
        side->pokeParams[j] = 0;
    for (k = 0; k < 4; k++)
        side->parties[k] = 0;
}












void BTL_SIDE_Clear(struct BtlSide *side)
{
    unsigned int i;
    for (i = 0; i < 24; i++) {
        if (side->pokeParams[i] != 0) {
            BTL_POKEPARAM_Delete(side->pokeParams[i]);
            side->pokeParams[i] = 0;
        }
    }
    for (i = 0; i < 4; i++) BTL_SLOT_Clear(&side->slots[i]);
}












#pragma opt_lifetimes off












/*
 * 2026-10-05 (wave P5, pengy share): EXACT. Needs #pragma opt_lifetimes off (per-function
 * pragma) and the clear of nw written AFTER the BTL_MAIN_GetClientParty call (l2 = f(...); nw = 0;).
 * Written before the call, the zero took r0 instead of the original r1. Other levers: raw
 * offsets, early locals qs = a + 4 and qo = c * 0x1c, declaration order qo, qs, list, n, v, nw,
 * x, j, i, y, cnt, comma-form loop headers, e = POKEPARTY_GetMember() as its own statement.
 */
void BTL_SIDE_SetupClientParty(struct BtlSide *side, struct BtlMain *main, u8 clientId)
{
    u32 slotOffset;
    char *slotBase;
    struct Party *party;
    u32 count;
    struct BtlPokeParam *poke;
    void *mon;
    u8 newSpecies;
    u8 firstPokeId;
    u32 j;
    int i;
    u8 pokeId;
    int lastValid;
    party = BTL_MAIN_GetClientParty(main, clientId, side->sideIndex);
    slotBase = (char *)side->slots;
    slotOffset = clientId * 0x1c;
    count = POKEPARTY_GetCount(party);
    firstPokeId = gClientFirstPokeIds[clientId];
    side->parties[clientId] = party;
    for (i = 0, pokeId = firstPokeId; i < count; i++, pokeId++) {
        mon = POKEPARTY_GetMember(party, i);
        side->pokeParams[pokeId] = BTL_POKEPARAM_Create(mon, pokeId, 0x12);
        BTL_SLOT_Add((struct BtlSideSlot *)(slotBase + slotOffset), side->pokeParams[pokeId]);
    }
    lastValid = BTL_MAIN_FindLastLivingPartyIndex(party);
    if (lastValid > 0) {
        for (i = 0, pokeId = firstPokeId; i < lastValid; i++, pokeId++) {
                if (func_021D59B4(side->pokeParams[pokeId], 0x11) == 0x95)
                    BTL_POKEPARAM_SetFakeMon(side->pokeParams[pokeId], POKEPARTY_GetMember(party, lastValid));
            }
    }
    if (BTL_MAIN_GetCompetitor(main) == 0 && clientId == 1) {
        for (j = 0; j < count; j++, firstPokeId++) {
            poke = side->pokeParams[firstPokeId];
            if (BTL_POKEPARAM_GetSpecies(poke) == 0x23B && func_021D59B4(poke, 0x11) == 0x95) {
                struct Party *playerParty;
                u8 playerCount, q;
                playerParty = BTL_MAIN_GetClientParty(main, 0, side->sideIndex);
                newSpecies = 0;
                playerCount = POKEPARTY_GetCount(playerParty);
                for (q = 0; q < playerCount; q++) {
                    u16 species = func_02017E1C(POKEPARTY_GetMember(playerParty, q), 5, 0);
                    if (species == 0xf3) { newSpecies = 0xf4; break; }
                    if (species == 0xf4) { newSpecies = 0xf5; break; }
                    if (species == 0xf5) { newSpecies = 0xf3; break; }
                }
                if (newSpecies != 0) {
                    if (main->tempBuffer == 0)
                        main->tempBuffer = POKE_TOOL_Create(newSpecies, func_021D59B4(poke, 0xf), 0, main->heapId);
                    BTL_POKEPARAM_SetFakeMon(poke, main->tempBuffer);
                }
            }
        }
    }
    BTL_SLOT_CompactLiving((struct BtlSideSlot *)(slotBase + slotOffset));
}












#pragma opt_lifetimes reset













int BTL_MAIN_FindLastLivingPartyIndex(struct Party *party)
{
    int i;
    void *mon;

    for (i = POKEPARTY_GetCount(party) - 1; i >= 0; i--) {
        mon = POKEPARTY_GetMember(party, i);
        if (func_02017E1C(mon, 0x4c, 0) == 0 && func_02017E1C(mon, 0xa0, 0) != 0)
            return i;
    }
    return -1;
}












void BTL_SIDE_DeletePokeParams(struct BtlSide *side)
{
    unsigned int i;
    for (i = 0; i < 24; i++) {
        if (side->pokeParams[i] != 0) {
            BTL_POKEPARAM_Delete(side->pokeParams[i]);
            side->pokeParams[i] = 0;
        }
    }
}












void BTL_SIDE_WriteBackParty(struct BtlSide *side, struct BtlMain *main, int clientId, int flag)
{
    struct Party *party;
    struct BtlSideSlot *slot;
    u32 count, i, j;
    struct BtlPokeParam *poke;
    void *mon;
    void *displayMon;
    u8 illusionLinks[6];
    party = (struct Party *)BTL_SIDE_GetParty(side, clientId);
    slot = BTL_SIDE_GetSlotOfClient(side, clientId);
    count = POKEPARTY_GetCount(party);
    POKEPARTY_Init(main->tempParty);
    for (i = 0; i < 6; i++) illusionLinks[i] = 6;
    for (i = 0; i < count; i++) {
        poke = BTL_SLOT_GetPoke(slot, (u8)i);
        BTL_POKEPARAM_WriteBackToParam(poke, flag);
        POKEPARTY_Add(main->tempParty, BTL_POKEPARAM_GetMon(poke));
        if (BTL_POKEPARAM_IsIllusionActive(poke)) {
            displayMon = BTL_POKEPARAM_GetDisplayMon(poke);
            for (j = 0; j < count; j++) {
                if (displayMon == BTL_POKEPARAM_GetMon(BTL_SLOT_GetPoke(slot, (u8)j))) {
                    illusionLinks[i] = j;
                    break;
                }
            }
        }
    }
    POKEPARTY_Copy(main->tempParty, party);
    for (i = 0; i < count; i++) {
        mon = POKEPARTY_GetMember(party, i);
        poke = BTL_SLOT_GetPoke(slot, (u8)i);
        BTL_POKEPARAM_SetPokeParam(poke, mon);
        if (illusionLinks[i] != 6)
            BTL_POKEPARAM_SetFakeMon(poke, POKEPARTY_GetMember(party, illusionLinks[i]));
    }
}













void BTL_SIDE_WriteBackPartyOrdered(struct BtlSide *side, struct BtlMain *main, int clientId)
{
    struct Party *party;
    struct BtlSideSlot *slot;
    u32 count;
    u32 firstPokeId;
    u32 i;
    u32 j;
    struct BtlPokeParam *poke;

    party = (struct Party *)BTL_SIDE_GetParty(side, clientId);
    slot = BTL_SIDE_GetSlotOfClient(side, clientId);
    count = POKEPARTY_GetCount(party);
    POKEPARTY_Init(main->tempParty);
    firstPokeId = gClientFirstPokeIds[clientId];
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            poke = BTL_SLOT_GetPoke(slot, (u8)j);
            if (firstPokeId + i == BTL_POKEPARAM_GetPokeId(poke)) {
                BTL_POKEPARAM_WriteBackToParam(poke, 1);
                POKEPARTY_Add(main->tempParty, BTL_POKEPARAM_GetMon(poke));
                if (BTL_POKEPARAM_IsLevelUpPending(poke) != 0)
                    main->setup->resultFlags[i] = 1;
                break;
            }
        }
    }
    POKEPARTY_Copy(main->tempParty, party);
}












int BTL_SIDE_GetParty(struct BtlSide *side, int clientId)
{
    return (int)side->parties[clientId];
}













int BTL_SIDE_FindPokeIndexInClient(struct BtlSide *side, int clientId, int pokeId)
{
    struct BtlSideSlot *slot = &side->slots[clientId];
    unsigned int count = BTL_SLOT_GetCount(slot);
    unsigned int i;
    for (i = 0; i < count; i++) {
        if (pokeId == BTL_POKEPARAM_GetPokeId(BTL_SLOT_GetPokeParam(slot, (unsigned char)i)))
            return i;
    }
    return -1;
}













/*
 * tail-call thunk to BTL_SIDE_GetPokeAtPos
 */
struct BtlPokeParam *BTL_SIDE_GetPokeAtPosThunk(struct BtlSide *side, u8 position)
{
    return (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain *const *)side, position);
}













/* The side parameter is typed as a pointer to its first member (the main object); a BtlSide pointer changes the schedule. */
u8 *BTL_SIDE_GetPokeAtPos(struct BtlMain *const *side, u8 position)
{
    u8 i = position;
    struct BtlMain *main = *side;
    u8 clientId;
    u8 nth;
    char *slot;

    clientId = BTL_MAIN_GetSlotClientId(main, position);
    nth = 0;
    while (i-- != 0) {
        if (clientId == main->slotClientIds[i])
            nth++;
    }
    slot = (char *)side + 4 + clientId * 0x1c;
    if (nth < BTL_SLOT_GetCount((struct BtlSideSlot *)slot))
        return (u8 *)BTL_SLOT_GetPokeParam((struct BtlSideSlot *)slot, nth);
    return 0;
}












void *BTL_SIDE_GetClientPokeParam(struct BtlSide *side, unsigned int clientId, unsigned int nth)
{
    return (void *)BTL_SLOT_GetPoke(&side->slots[clientId], nth);
}












struct BtlPokeParam *BTL_SIDE_GetClientPoke(struct BtlSide *side, u32 clientId, u8 nth)
{
    return BTL_SLOT_GetPokeParam(&side->slots[clientId], nth);
}













struct BtlPokeParam *BTL_SIDE_GetPokeByIdThunk(struct BtlSide *side, int pokeId)
{
    return side->pokeParams[pokeId];
}













struct BtlPokeParam *BTL_SIDE_GetPokeById(struct BtlSide *side, u8 pokeId)
{
    return side->pokeParams[pokeId];
}












/*
 * evidence: original narrows second argument before 021B8ED8 call.
 */
int BTL_MAIN_GetVoiceOfSlot(struct BtlMain *main, u32 slot, struct PerapVoice **outVoice)
{
    struct PerapVoice *voice;
    u32 clientId = BTL_MAIN_GetSlotClientIdThunk(main, BTL_MAIN_GetSlotFromViewPos(main, slot));
    voice = main->voices[clientId];
    if (voice != 0) {
        *outVoice = voice;
        return 1;
    }
    return 0;
}












int BTL_MAIN_GetClientVoiceFlag(struct BtlMain *main, unsigned int clientId)
{
    if (BTL_MAIN_GetOwnsSlots(main) == 0) {
        struct PerapVoice **voices = main->voices;
        if (voices[clientId] != 0 && func_02007B50(voices[clientId]) != 0)
            return func_02007C70(voices[clientId]);
        return 0;
    }
    return main->setup->voiceFlags[clientId];
}













int BTL_MAIN_GetPositionsPerClientThunk(struct BtlMain *main, unsigned int clientId)
{
    return BTL_MAIN_GetPositionsPerClient(main, clientId);
}












/*
 * evidence: entry r1 is forwarded unchanged to the two-argument 021B6994.
 */
u8 BTL_MAIN_GetViewPositionsPerClient(struct BtlMain *main, u32 clientId)
{
    u8 result = BTL_MAIN_GetPositionsPerClient(main, clientId);
    if (BTL_MAIN_GetRule(main) == 3) result += 2;
    return result;
}













struct BtlPosTable *BTL_MAIN_GetPosTable(int tableIndex)
{
    return &gBtlPosTables[tableIndex];
}













u32 BTL_MAIN_IsBackRowPos(u32 position) { return (position == 2 || position == 3) ? 1 : 0; }















int BTL_MAIN_GetFrontEnemyPos(u32 position, u8 *outPosition)
{
    if (BTL_MAIN_IsBackRowPos(position) == 0) {
        *outPosition = BTL_MAIN_GetEnemyLanePos(2, position, (u8)(position >> 1));
        return 1;
    }
    return 0;
}















int BTL_MAIN_IsPokeSamePair(unsigned int pokeIdA, unsigned int pokeIdB)
{
    unsigned char inSecondPair = BTL_MAIN_IsPokeIdInSecondPair(pokeIdA);
    if (inSecondPair == BTL_MAIN_IsPokeIdInSecondPair(pokeIdB)) return 1;
    return 0;
}















unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int pokeId)
{
    BOOL result;
    if (pokeId < 12) result = FALSE;
    else result = TRUE;
    return result;
}
















unsigned char BTL_MAIN_IsPokeIdInFirstPair(unsigned int pokeId)
{
    return BTL_MAIN_IsZero(BTL_MAIN_IsPokeIdInSecondPair(pokeId));
}
















/* 021B9A5C  cmp r0,#0; bne; movs r0,#1; else 0; zext8 */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: cmp r0, #0; bne loc_021B9A64; movs r0, #1; b loc_021B9A66; movs r0, #0; lsls r0, r0, #0x18; lsrs r0, r0, #0x18; bx lr.
 */
u8 BTL_MAIN_IsZero(u32 value) { return value == 0; }
















int BTL_MAIN_IsPosInTable(int tableIndex, u32 position)
{
    struct BtlPosTable *table = BTL_MAIN_GetPosTable(tableIndex);
    u32 i;

    for (i = 0; i < table->firstCount; i++) {
        if (position == table->positions[i])
            return 1;
    }
    for (i = 0; i < table->secondCount; i++) {
        if (position == *((u8 *)table + 7 + i))
            return 1;
    }
    return 0;
}















u8 BTL_SLOT_GetRotateSrcIndex(u8 rotateKind)
{
    switch (rotateKind) {
    case 2: return 1;
    case 3: return 2;
    default: return 0;
    }
}















int BTL_SLOT_GetRotateDstIndex(int rotateKind)
{
    switch (rotateKind) {
    case 2: return 2;
    case 3: return 1;
    default: return 0;
    }
}















unsigned char BTL_MAIN_GetPosParity(unsigned int position)
{
    return position & 1;
}















struct BtlSideSlot *BTL_SIDE_GetSlotOfClient(struct BtlSide *side, int clientId)
{
    return &side->slots[clientId];
}















struct BtlSideSlot *BTL_SIDE_GetSlotOfClientThunk(struct BtlSide *side, int clientId)
{
    return &side->slots[clientId];
}
















unsigned char BTL_SIDE_CountLivingOfClient(struct BtlSide *side, int clientId)
{
    return BTL_SLOT_CountLiving(BTL_SIDE_GetSlotOfClientThunk(side, clientId));
}















void BTL_MAIN_AddClientPoints(struct BtlMain *main, u8 clientId, u8 points)
{
    struct BtlClient *client;
    if (main->hostsServer && BTL_MAIN_IsClientUsed(main, clientId)) {
        client = main->clients[clientId];
        if (client) BTL_CLIENT_AddPoints(client, points);
    }
}















void BTL_SLOT_Clear(struct BtlSideSlot *slot)
{
    int i;
    slot->count = 0;
    for (i = 0; i < 6; i++) slot->items[i] = 0;
}















void BTL_SLOT_Add(struct BtlSideSlot *slot, struct BtlPokeParam *poke)
{
    u8 n = slot->count;
    slot->count = n + 1;
    slot->items[n] = poke;
}















void BTL_SLOT_CompactLiving(struct BtlSideSlot *slot)
{
    unsigned int j;
    int i;
    j = 0;
    i = 0;
    for (; j < slot->count; j++) {
        if (BTL_POKEPARAM_IsAbleToBattle(slot->items[i])) i++;
        else BTL_SLOT_MoveToEnd(slot, i);
    }
}















/* 021B9B94  ldrb r0,[r0,#0x18] */
/*
 * Reads the u8 field at #0x18 of the argument and returns it.
 */
u8 BTL_SLOT_GetCount(struct BtlSideSlot *slot) { return slot->count; }















u8 BTL_SLOT_CountLiving(struct BtlSideSlot *slot)
{
    int i;
    u32 count;
    i = 0;
    count = 0;
    for (; i < slot->count; i++) if (BTL_POKEPARAM_IsAbleToBattle(slot->items[i])) count++;
    return count;
}















u8 BTL_SLOT_CountLivingFrom(struct BtlSideSlot *slot, int from)
{
    u32 count = 0;
    for (; from < slot->count; from++) if (BTL_POKEPARAM_IsAbleToBattle(slot->items[from])) count++;
    return count;
}















struct BtlPokeParam *BTL_SLOT_GetPoke(struct BtlSideSlot *slot, u32 index)
{
    if (index < slot->count)
        return slot->items[index];
    return 0;
}















/* 021B9C00  same shape as 021B9BF0 */
struct BtlPokeParam *BTL_SLOT_GetPokeParam(struct BtlSideSlot *slot, u32 index)
{
    if (index < slot->count)
        return slot->items[index];
    return 0;
}















void BTL_SLOT_Swap(struct BtlSideSlot *slot, int indexA, int indexB)
{
    struct BtlPokeParam *temp = slot->items[indexA];
    slot->items[indexA] = slot->items[indexB];
    slot->items[indexB] = temp;
}















void BTL_SLOT_MoveToEnd(struct BtlSideSlot *slot, u8 index)
{
    struct BtlPokeParam *moved = slot->items[index];
    for (; index < slot->count - 1; index++) slot->items[index] = slot->items[index + 1];
    slot->items[index] = moved;
}















void BTL_SLOT_Rotate(struct BtlSideSlot *slot, u8 rotateKind, struct BtlPokeParam **outFirst, struct BtlPokeParam **outLast)
{
    struct BtlPokeParam *temp;
    int a;
    int b;

    if (rotateKind != 0) {
        if (rotateKind != 1) {
            temp = slot->items[0];
            a = BTL_SLOT_GetRotateSrcIndex(rotateKind);
            b = BTL_SLOT_GetRotateDstIndex(rotateKind);
            slot->items[0] = slot->items[a];
            slot->items[a] = slot->items[b];
            slot->items[b] = temp;
            if (outFirst)
                *outFirst = temp;
            if (outLast)
                *outLast = slot->items[0];
        }
    }
}














int BTL_SLOT_FindPoke(struct BtlSideSlot *slot, struct BtlPokeParam *poke)
{
    int i;
    /* stand-in: volatile read, the count is reloaded in every loop test */
    for (i = 0; i < *(volatile u8 *)&slot->count; i++) {
        if (slot->items[i] == poke) return i;
    }
    return -1;
}














int BTL_SLOT_FindPokeId(struct BtlSideSlot *slot, int pokeId)
{
    int i;
    for (i = 0; i < slot->count; i++) if (pokeId == BTL_POKEPARAM_GetPokeId(slot->items[i])) return i;
    return -1;
}














struct BtlPokeParam *BTL_SLOT_GetFirstLiving(struct BtlSideSlot *slot)
{
    int i;
    for (i = 0; i < slot->count; i++) if (BTL_POKEPARAM_IsAbleToBattle(slot->items[i])) return slot->items[i];
    return 0;
}















void BTL_SLOT_UpdateIllusion(struct BtlMain *main, struct BtlSideSlot *slot, int firstIndex)
{
    int lastAlive;
    struct BtlPokeParam *poke;
    void *displayMon;

    for (lastAlive = slot->count - 1; lastAlive > 0; lastAlive--) {
        if (BTL_POKEPARAM_IsAbleToBattle(slot->items[lastAlive]) != 0)
            break;
    }
    if (BTL_MAIN_GetRule(main) != 3)
        firstIndex = BTL_MAIN_CountClientTrainers(main, firstIndex);
    else
        firstIndex = 3;
    for (; firstIndex < slot->count; firstIndex++) {
        poke = slot->items[firstIndex];
        if (func_021D59B4(poke, 0x11) == 0x95) {
            if (firstIndex < lastAlive) {
                BTL_POKEPARAM_SetFakeMon(poke, BTL_POKEPARAM_GetMon(slot->items[lastAlive]));
            } else {
                displayMon = BTL_POKEPARAM_GetDisplayMon(poke);
                if (displayMon != main->tempBuffer)
                    BTL_POKEPARAM_ClearFakeMon(poke);
            }
        }
    }
    for (firstIndex = 0; firstIndex < slot->count; firstIndex++)
        BTL_POKEPARAM_IsIllusionActive(slot->items[firstIndex]);
}














void BTL_MAIN_ClearTrainerSlotsAndVoices(struct BtlMain *main)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        main->trainers[i].handle = 0;
        main->trainers[i].trainerId = 0;
        main->trainers[i].aiFlags = 0;
    }
    for (i = 0; i < 4; i++) main->voices[i] = 0;
}















void BTL_MAIN_FreeTrainerSlotsAndVoices(struct BtlMain *main)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        if (main->trainers[i].handle) {
            func_020307B0(main->trainers[i].handle);
            main->trainers[i].handle = 0;
        }
        if (main->trainers[i].name) {
            func_020307B0(main->trainers[i].name);
            main->trainers[i].name = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if (main->voices[i]) {
            func_020307B0(main->voices[i]);
            main->voices[i] = 0;
        }
    }
}














void BTL_TRAINER_SLOT_InitPlayer(struct BtlTrainerSlot *slot, int heapId, void *playerStatus)
{
    u16 flag;

    void *handle = MYSTATUS_Create(heapId);

    slot->handle = handle;
    MYSTATUS_Copy(playerStatus, handle);
    flag = 0;
    slot->trainerId = 0;
    if (func_02008550(slot->handle))
        flag = 1;
    slot->trainerType = flag;
    slot->name = func_02008510(slot->handle, 0x12);
    PMSI_PARAM_ClearSentence(slot->winWord);
    PMSI_PARAM_ClearSentence(slot->loseWord);
}














void BTL_TRAINER_SLOT_InitFromData(struct BtlTrainerSlot *slot, struct BattleTrainerData *src)
{
    unsigned int i;

    slot->handle = 0;
    if (src) {
        slot->trainerId = src->trainerId;
        slot->trainerType = src->trainerType;
        slot->name = STRBUF_Clone(src->name, 0x12);
        slot->aiFlags = src->aiFlags;
        func_02082D44(src->itemIds, slot->itemIds, 8);
        PMSI_PARAM_Copy(slot->winWord, src->winWord);
        PMSI_PARAM_Copy(slot->loseWord, src->loseWord);
    } else {
        slot->trainerId = 0;
        slot->trainerType = 0;
        slot->name = 0;
        for (i = 0; i < 4; i++) {
            slot->itemIds[i] = 0;
        }
        PMSI_PARAM_ClearSentence(slot->winWord);
        PMSI_PARAM_ClearSentence(slot->loseWord);
    }
}





















void BTL_TRAINER_SLOT_InitFromPacket(struct BtlTrainerSlot *slot, const struct BtlTrainerPacket *src)
{
    unsigned int i;
    void *nameBuf;
    int nameLength;

    slot->handle = 0;
    if (src) {
        slot->trainerId = src->trainerId;
        slot->trainerType = src->trainerType;
        nameBuf = STRBUF_Create(0x20, 0x12);
        nameLength = src->nameLength + 1;
        slot->name = nameBuf;
        STRBUF_SetChars(nameBuf, src->nameChars, nameLength);
        slot->aiFlags = src->aiFlags;
        func_02082D44((void *)src->itemIds, slot->itemIds, 8);
        PMSI_PARAM_Copy(slot->winWord, src->winWord);
        PMSI_PARAM_Copy(slot->loseWord, src->loseWord);
    } else {
        slot->trainerId = 0;
        slot->trainerType = 0;
        slot->name = 0;
        for (i = 0; i < 4; i++) {
            slot->itemIds[i] = 0;
        }
        PMSI_PARAM_ClearSentence(slot->winWord);
        PMSI_PARAM_ClearSentence(slot->loseWord);
    }
}





















/* 021B9F70  movs r2,#0x28; muls r2,r1,r2; adds r0,r0,r2; ldr r0,[r0,#0x20] */
int BTL_MAIN_IsTrainerSlotNpc(struct BtlMain *main, int slot) { return main->trainers[slot].handle == 0; }




















u16 BTL_MAIN_GetTrainerItem(struct BtlMain *main, int slot, unsigned int index)
{
    struct BtlTrainerSlot *trainer;
    if (BTL_MAIN_IsTrainerSlotNpc(main, slot)) {
        trainer = &main->trainers[slot];
        if (index < 4) return trainer->itemIds[index];
    }
    return 0;
}




















u32 BTL_MAIN_GetTrainerNameAndType(struct BtlMain *main, int slot, u32 *outTrainerType)
{
    *outTrainerType = main->trainers[slot].trainerType;
    return (u32)main->trainers[slot].name;
}





















int BTL_MAIN_GetTrainerAiFlags(struct BtlMain *main, int slot)
{
    if (BTL_MAIN_GetCompetitor(main) == 0) {
        slot = 8;
        if (BTL_MAIN_CheckSetupStatusFlag(main, slot)) {
            return slot << 8;
        }
        if (BTL_MAIN_GetRule(main) == 1) {
            return 0x80;
        }
    } else {
        if (BTL_MAIN_IsTrainerSlotNpc(main, slot)) {
            return main->trainers[slot].aiFlags;
        }
    }
    return 0;
}




















u16 BTL_MAIN_GetTrainerId(struct BtlMain *main, int slot)
{
    if (BTL_MAIN_IsTrainerSlotNpc(main, slot)) return main->trainers[slot].trainerId;
    return 0;
}



















unsigned short BTL_MAIN_GetTrainerType(struct BtlMain *main, int slot)
{
    return main->trainers[slot].trainerType;
}



















void *BTL_MAIN_GetTrainerSentence(struct BtlMain *main, int slot, int mode)
{
    if ((int)BTL_MAIN_GetCompetitor(main) == 2 && BTL_MAIN_IsTrainerSlotNpc(main, slot)) {
        if (mode == 1) return main->trainers[slot].loseWord;
        return main->trainers[slot].winWord;
    }
    return 0;
}



















int BTL_MAIN_GetTrainerHandle(struct BtlMain *main, int slot)
{
    if (BTL_MAIN_IsTrainerSlotNpc(main, slot)) return 0;
    return (int)main->trainers[slot].handle;
}




















/*
 * branch, so the pool relocation cannot be witnessed.  All bytes correct.
 */
void BTL_MAIN_UpdateCommPlayerSupport(struct BtlMain *main)
{
    COMM_PLAYER_SUPPORT_GetCurrent((char *)main->setup->pmsWork);
}



















/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0xaf; lsls r1, r1, #2; ldr r0, [r0, r1]; bx lr.
 */
u32 BTL_MAIN_GetField(struct BtlMain *main) { return (u32)main->field; }



















void BTL_MAIN_CreateParties(struct BtlMain *main)
{
    unsigned int i;
    for (i = 0; i < 4; i++) {
        main->battleParties[i] = POKEPARTY_Create(0x12);
        main->savedParties[i] = POKEPARTY_Create(0x12);
    }
    main->tempParty = POKEPARTY_Create(0x12);
}




















void BTL_MAIN_FreeParties(struct BtlMain *main)
{
    unsigned int i;

    for (i = 0; i < 4; i++) {
        if (main->battleParties[i]) {
            func_020307B0(main->battleParties[i]);
            main->battleParties[i] = 0;
        }
        if (main->savedParties[i]) {
            func_020307B0(main->savedParties[i]);
            main->savedParties[i] = 0;
        }
    }
    if (main->tempParty) {
        func_020307B0(main->tempParty);
        main->tempParty = 0;
    }
}




















void BTL_MAIN_SetClientParty(struct BtlMain *main, int clientId, struct Party *party)
{
    if (main->battleParties[clientId]) {
        POKEPARTY_Init(main->battleParties[clientId]);
        POKEPARTY_Init(main->savedParties[clientId]);
        POKEPARTY_Copy(party, main->battleParties[clientId]);
        POKEPARTY_Copy(party, main->savedParties[clientId]);
        if (POKEPARTY_GetCount(main->savedParties[clientId])) {
            POKEPARTY_GetMember(main->savedParties[clientId], 0);
        }
    }
}



















struct Party *BTL_MAIN_GetClientParty(struct BtlMain *main, int clientId, int useSaved)
{
    if (useSaved) {
        if (POKEPARTY_GetCount(main->savedParties[clientId]))
            POKEPARTY_GetMember(main->savedParties[clientId], 0);
        return main->savedParties[clientId];
    }
    return main->battleParties[clientId];
}




















int BTL_MAIN_CheckSetupStatusFlag(struct BtlMain *main, int mask)
{
    return BTL_SETUP_CheckStatusFlag(main->setup, mask);
}



















void BTL_MAIN_TrainerRecordAdd(struct BtlMain *main, int arg)
{
    if (main->setup->ownsSlots == 0)
        sub_02008DF0(main->setup->trainerRecord, arg);
}



















void BTL_MAIN_TrainerRecordAddDelta(struct BtlMain *main, int arg, u32 delta)
{
    if (main->setup->ownsSlots == 0)
        sub_02008DAC(main->setup->trainerRecord, arg, delta);
}



















char *BTL_MAIN_GetRegulationRules(struct BtlMain *main)
{
    return (char *)main->setup->regulationRules;
}



















BOOL BTL_MAIN_IsRecordEnabledInComm(struct BtlMain *main)
{
    BOOL result = FALSE;
    if (BTL_MAIN_IsCommCompetitor(main->setup) == 1) {
        if (main->setup->recordEnabled) result = TRUE;
    }
    return result;
}



















int BTL_MAIN_IsRecordAllowed(struct BtlMain *main)
{
    int competitor;
    if (BTL_MAIN_IsCommCompetitor(main->setup) == 1) return BTL_MAIN_IsRecordEnabledInComm(main);
    competitor = (int)BTL_MAIN_GetCompetitor(main);
    switch (competitor) {
    case 0:
    case 1: return 1;
    default: return 0;
    }
}


















void BTL_MAIN_NotifyLevelUp(struct BtlMain *main, struct BtlPokeParam *poke)
{
    BTL_MAIN_UpdateFriendship(main, poke, 0);
    BTL_SERVER_NotifyLevelUp(main->server, poke);
}



















void BTL_MAIN_UpdateFriendshipUseItem(struct BtlMain *main, struct BtlPokeParam *poke, int itemId)
{
    u8 pokeId;
    void *snapshotPoke;
    void *livePoke;
    void *snapshotMon;
    void *liveMon;
    struct FieldSituation *field;

    pokeId = BTL_POKEPARAM_GetPokeId(poke);
    snapshotPoke = BTL_SIDE_GetPokeById(&main->sides[1], pokeId);
    livePoke = BTL_SIDE_GetPokeById(&main->sides[0], pokeId);
    snapshotMon = BTL_POKEPARAM_GetMon(snapshotPoke);
    liveMon = BTL_POKEPARAM_GetMon(livePoke);
    field = BTL_MAIN_GetFieldSituation(main);
    NATSUKI_CalcUseItem(snapshotMon, itemId, field->zoneId, (main->heapId & 0x7fff) | 0x8000);
    NATSUKI_CalcUseItem(liveMon, itemId, field->zoneId, (main->heapId & 0x7fff) | 0x8000);
}


















void BTL_MAIN_NotifyCapture(struct BtlMain *main, u32 *captureInfo)
{
    struct BtlServer *server = main->server;
    if (server) BTL_SERVER_NotifyCapture(server, captureInfo);
}


















void BTL_MAIN_WriteBackResults(struct BtlMain *main)
{
    struct Party *party;
    u32 n, move, ownPartnerClient, i0, k, slot;
    struct BtlSideSlot *group;
    u32 count, total, maximum, i, base, j, rowObj;
    void *old, *mon;
    struct BtlPokeParam *poke;
    u32 rowFainted, rowStart, rowStatus;
    if (main->setup->ownsSlots != 0) return;
    if (main->setup->competitor <= 1) {
        BTL_SIDE_WriteBackPartyOrdered(&main->sides[1], main, (u8)main->ownClientId);
        party = (struct Party *)BTL_SIDE_GetParty(&main->sides[1], (u8)main->ownClientId);
        if (main->setup->competitor == 1 && BTL_CALC_IsBossTrainer((u16)(u32)BTL_MAIN_GetTrainerType(main, 1)))
            NATSUKI_CalcParty(party, BTL_MAIN_GetFieldSituation(main)->zoneId, (u16)((main->heapId & 0x7fff) | 0x8000));
        if (main->setup->competitor == 1) {
            n = POKEPARTY_GetCount(party);
            for (i0 = 0; i0 < n; i0++) {
                old = POKEPARTY_GetMember(main->setup->party[0], i0);
                mon = POKEPARTY_GetMember(party, i0);
                move = (u16)func_02017E1C(old, 6, 0);
                if (!func_021D805C((void *)move, 0x10))
                    POKE_TOOL_SetPartyValue(mon, 6, move);
                else if (move != func_02017E1C(mon, 6, 0))
                    POKE_TOOL_SetPartyValue(mon, 6, 0);
            }
        }
        POKEPARTY_Copy(party, main->setup->party[0]);
        for (i0 = 0; i0 < (u32)POKEPARTY_GetCount(party); i0++) POKEPARTY_GetMember(party, i0);
    }
    if (main->setup->competitor == 0) {
        ownPartnerClient = (u8)BTL_MAIN_GetOpponentClient(main, (u8)main->ownClientId, 0);
        BTL_SIDE_WriteBackParty(&main->sides[1], main, ownPartnerClient, 1);
        POKEPARTY_Copy((void *)BTL_SIDE_GetParty(&main->sides[1], ownPartnerClient), main->setup->party[1]);
    }
    if (main->setup->competitor == 4) return;
    for (k = 0; k < 4; k++) {
        slot = BTL_MAIN_GetRelativeClientIndex((u8)main->ownClientId, (u8)k);
        for (j = 0; j < 6; j++) { rowObj = (u32)main->setup; rowStart = slot * 6; *(u8 *)(j + (rowStart + rowObj) + 0xc8) = 0; }
        if (BTL_MAIN_IsClientUsed(main, (u8)slot)) {
            group = BTL_SIDE_GetSlotOfClient(&main->sides[0], slot);
            count = BTL_SLOT_GetCount(group);
            total = maximum = 0;
            base = gClientFirstPokeIds[slot];
            for (j = 0; j < count; j++) {
                poke = BTL_SLOT_GetPoke(group, (u8)j);
                i = (u8)(BTL_POKEPARAM_GetPokeId(poke) - base);
                total += func_021D59B4(poke, 13);
                maximum += func_021D59B4(poke, 14);
                if (BTL_POKEPARAM_IsFainted(poke)) { rowObj = (u32)main->setup; rowFainted = slot * 6; *(u8 *)(i + (rowFainted + (u32)main->setup) + 0xc8) = 2; }
                else if (BTL_POKEPARAM_GetMajorStatusIndex(poke)) { rowObj = (u32)main->setup; rowStatus = slot * 6; *(u8 *)(i + (rowStatus + rowObj) + 0xc8) = 1; }
            }
            *(u32 *)((char *)main->setup + slot * 4 + 0xe0) = _u32_div_f(total * 100, maximum);
        }
    }
}


















int BTL_MAIN_IsCommTrainerBattle(struct BtlMain *main)
{
    int competitor = (int)BTL_MAIN_GetCompetitor(main);
    switch (competitor) {
    case 2:
    case 3: return 1;
    default: return 0;
    }
}



















int BTL_MAIN_JudgeResult(struct BtlMain *main)
{
    int result;

    if ((int)BTL_MAIN_GetCompetitor(main) == 4) {
        result = 1;
    } else if (main->flags.commLost) {
        result = 6;
    } else if (main->setup->resultValue[0] != 6) {
        result = 5;
    } else if (BTL_CLIENT_SET_GetCount(&main->defeatedClients.count)) {
        result = BTL_CLIENT_SET_JudgeResult(&main->defeatedClients, main->ownClientId, (unsigned int)BTL_MAIN_GetCompetitor(main));
    } else {
        if (main->outcome == 7) {
            main->outcome = 1;
        }
        result = main->outcome;
    }
    main->setup->moneyRate = result;
    return result;
}



















u16 BTL_MAIN_GetLimitTimeCommand(struct BtlMain *main)
{
    return main->limitTimeCommand;
}


















/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x11; lsls r1, r1, #6; ldrh r0, [r0, r1]; bx lr.
 */
u16 BTL_MAIN_GetLimitTimeGame(struct BtlMain *main) { return main->limitTimeGame; }



















int BTL_MAIN_IsOwnWindowWaiting(struct BtlMain *main)
{
    struct BattleSetupParam *setup = main->setup;
    if (setup->ownsSlots == 0) {
        if (main->limitTimeGame != 0)
            return BTL_CLIENT_IsWindowWaiting(main->clients[main->ownClientId]);
        return 0;
    }
    return BTL_CLIENT_IsWindowWaiting(main->clients[main->ownClientId]);
}


















int BTL_MAIN_CheckOwnWindowDone(struct BtlMain *main)
{
    int done;
    if (main->setup->ownsSlots) {
        done = BTL_CLIENT_IsWindowDone(main->clients[main->ownClientId]);
        if (done) main->outcome = 2;
        return done;
    }
    return 0;
}


















void BTL_MAIN_CopyClientParty(struct BtlMain *main, u8 client, void *dst)
{
    int index;
    struct Party *party;
    index = BTL_MAIN_GetRelativeClientIndex(main->ownClientId, client);
    party = main->setup->party[index];
    if (party != 0) POKEPARTY_Copy(dst, party);
}


















void BTL_MAIN_CopyClientPlayerStatus(struct BtlMain *main, u8 client, void *dst)
{
    int index;
    void *status;
    index = BTL_MAIN_GetRelativeClientIndex(main->ownClientId, client);
    status = main->setup->playerStatus[index];
    if (status != 0) MYSTATUS_Copy(dst, status);
}


















void BTL_MAIN_StoreClientVoiceFlag(struct BtlMain *main, int client)
{
    int index;
    index = BTL_MAIN_GetRelativeClientIndex(main->ownClientId, client);
    main->setup->voiceFlags[index] = BTL_MAIN_GetClientVoiceFlag(main, client);
}



















void BTL_MAIN_StoreRecorderEntry(struct BtlMain *main)
{
    int size;
    void *src;

    if (BTL_MAIN_IsRecordingActive(main)) {
        src = BTL_CLIENT_ReadRecorderEntry(main->clients[main->ownClientId], (u32 *)(&size));
        if (src) {
            func_02082D44(src, main->setup->recordBuffer, size);
            main->setup->recordSize = size;
            main->setup->rng = main->rng;
        }
    }
}


















u8 BTL_MAIN_GetRelativeClientIndex(int ownClient, int client)
{
    u8 ownParity;
    u8 clientParity;
    if (ownClient == client) return 0;
    ownParity = ownClient & 1;
    clientParity = client & 1;
    if (ownParity == clientParity) return 2;
    return client <= 1U ? 1 : 3;
}



















/*
 * BTL_CLIENT_SetView takes two arguments (its own file: `p->v = v`), and the
 * value passed second is the BTLV_CORE_Create result just stored at p + 4:
 * that is the `adds r1, r0, #0` the one-argument prototype could not
 * produce (twin: ov093_func_021B835C).
 */
void BTL_MAIN_RestartBattle(struct BtlMain *main, u16 stepArg)
{
    unsigned int i;
    int isComm;

    isComm = BTL_MAIN_IsCommCompetitor(main->setup);
    BTL_CALC_SetRngState(&main->rng);
    BTL_MAIN_InitClientParties(main, main->setup);
    BTL_SIDE_Clear(&main->sides[0]);
    BTL_SIDE_Clear(&main->sides[1]);
    for (i = 0; i < 4; i++) {
        if (BTL_MAIN_IsClientUsed(main, (u8)i)) {
            BTL_SIDE_SetupClientParty(&main->sides[1], main, i);
            BTL_SIDE_SetupClientParty(&main->sides[0], main, i);
            BTL_CLIENT_StartRemoteStep(main->clients[i], stepArg);
        }
    }
    BTLV_CORE_Delete(main->viewCore);
    BTLV_CORE_ResetDisplay((void *)0x13);
    main->viewCore = BTLV_CORE_Create(main, main->clients[main->setup->netId], &main->sides[0], isComm, 0x13);
    BTL_CLIENT_SetView(main->clients[main->setup->netId], main->viewCore);
    BTL_SERVER_Restart(main->server);
}


















void BTL_MAIN_StartClientMainSteps(struct BtlMain *main)
{
    unsigned int i;
    for (i = 0; i < 4; i++) {
        if (BTL_MAIN_IsClientUsed(main, (u8)i)) BTL_CLIENT_StartMainStep(main->clients[i]);
    }
}



















u32 BTL_MAIN_GetServerFlow(struct BtlMain *main)
{
    return BTL_SERVER_GetFlow(main->server);
}



















void BTL_SETUP_ClearResultStats(struct BattleSetupParam *setup)
{
    setup->turnCount = 0;
    setup->stats[0] = 0;
    setup->stats[1] = 0;
    setup->stats[2] = 0;
    setup->stats[3] = 0;
    setup->stats[4] = 0;
    setup->stats[5] = 0;
    setup->won = 0;
    setup->enemyFainted = 0;
    setup->ownFainted = 0;
    setup->moveUseTotal = 0;
    setup->hpSum = 0;
}



















void BTL_MAIN_StoreResultStats(struct BtlMain *main)
{
    struct BattleSetupParam *setup;
    void *flow;
    struct BtlSideSlot *slot;
    u32 count;
    u32 aliveCount;
    u32 i;
    struct BtlPokeParam *poke;
    if (main->server == 0)
        return;
    flow = (void *)BTL_SERVER_GetFlow(main->server);
    setup = main->setup;
    setup->turnCount = BTL_SERVER_FLOW_GetTurnCount(flow);
    setup->stats[0] = BTL_SERVER_FLOW_GetSlotFlag(flow, 0);
    setup->stats[1] = BTL_SERVER_FLOW_GetPlayerNoEffectCount(flow);
    setup->stats[2] = BTL_SERVER_FLOW_GetPlayerSuperEffectiveCount(flow);
    setup->stats[3] = BTL_SERVER_FLOW_GetPlayerResistedCount(flow);
    setup->stats[4] = BTL_SERVER_FLOW_GetOpponentNoEffectCount(flow);
    setup->stats[5] = BTL_SERVER_FLOW_GetOpponentResistedCount(flow);
    if (setup->moneyRate == 1)
        setup->won = 1;
    slot = BTL_SIDE_GetSlotOfClient(&main->sides[1], 0);
    count = BTL_SLOT_GetCount(slot);
    aliveCount = BTL_SLOT_CountLiving(slot);
    for (i = 0; i < count; i++) {
        poke = BTL_SLOT_GetPoke(slot, (u8)i);
        setup->moveUseTotal += BTL_POKEPARAM_GetUsedMoveTotal(poke);
        setup->hpSum += (u16)func_021D59B4(poke, 13);
    }
    setup->ownFainted = count - aliveCount;
    slot = BTL_SIDE_GetSlotOfClient(&main->sides[1], 1);
    count = BTL_SLOT_GetCount(slot);
    aliveCount = BTL_SLOT_CountLiving(slot);
    setup->enemyFainted = count - aliveCount;
    if (BTL_MAIN_IsClientUsed(main, 3)) {
        slot = BTL_SIDE_GetSlotOfClient(&main->sides[1], 3);
        if (slot) {
            count = BTL_SLOT_GetCount(slot);
            aliveCount = BTL_SLOT_CountLiving(slot);
            setup->enemyFainted += (u8)(count - aliveCount);
        }
    }
}
