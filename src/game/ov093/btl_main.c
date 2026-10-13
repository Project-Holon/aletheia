/*
 * file:     btl_main.c
 * unit:     yes
 * function: BTL_MAIN_ProcInit, BTL_MAIN_ProcMain, BTL_MAIN_IsRecordPlaybackDone, BTL_MAIN_ProcExit, BTL_MAIN_StartSetupTask, BTL_MAIN_StartCleanupTask, BTL_MAIN_IsCommCompetitor, BTL_MAIN_SetupOwnClient, BTL_MAIN_InitClientParties, BTL_MAIN_InitTrainerSlot, BTL_MAIN_GetPositionsPerClient, BTL_MAIN_InitFirstTwoTrainerSlots, func_021B6A3C, BTL_MAIN_CreateViewCore, BTL_MAIN_TaskSetupSingle, func_021B6C08, BTL_MAIN_TaskSetupDouble, BTL_MAIN_TaskSetupMulti, BTL_MAIN_TaskSetupTriple, BTL_MAIN_TaskSetupRotation, BTL_MAIN_TaskCommSingle, BTL_MAIN_TaskCommDouble, BTL_MAIN_RunSetupSeqKind1, BTL_MAIN_RunSetupSeqKind3, BTL_MAIN_SeqSyncRules, BTL_MAIN_SeqExchangeRegulation, BTL_MAIN_SeqExchangePlayers, BTL_MAIN_SeqExchangePerapVoice, BTL_MAIN_SeqCreateClientsKind1Solo, BTL_MAIN_SeqCreateClientsByMulti, BTL_MAIN_SeqCreateClientsKind3, BTL_MAIN_SeqCreateClientsKind1, BTL_MAIN_SeqCreateView, BTL_MAIN_StepClientsSolo, BTL_MAIN_StepParent, BTL_MAIN_StepChild, BTL_MAIN_MarkClientsDisconnected, BTL_MAIN_CheckAllClientsReady, BTL_MAIN_GetRule, BTL_MAIN_CheckSceneOff, BTL_MAIN_GetBadgeCount, BTL_MAIN_CheckShiftModePrompt, BTL_MAIN_GetTextSpeedFrames, BTL_MAIN_CheckEventOverlayAllowed, BTL_MAIN_GetPmsWork, BTL_MAIN_GetRuleSlotSpan, BTL_MAIN_GetActivePosPerSide, BTL_MAIN_CheckFrontPos, BTL_MAIN_GetCompetitor, BTL_MAIN_GetCommPos, BTL_MAIN_IsMultiMode, BTL_MAIN_GetWinBgm, BTL_MAIN_GetCompetitorKind, BTL_MAIN_GetFieldSituation, func_021B871C, BTL_MAIN_CheckZukanSeen, BTL_MAIN_GetZukanSeenCount, BTL_MAIN_GetGameData, BTL_MAIN_RegisterZukanSeen, BTL_MAIN_DecodeMessageCode, BTL_MAIN_DecodeMessageCodeBasic, BTL_MAIN_ExpandPosDouble, BTL_MAIN_ExpandPosTriple, BTL_MAIN_CountClientTrainers, BTL_MAIN_IsClientUsed, BTL_MAIN_GetClientSide, BTL_MAIN_IsLocalSide, BTL_MAIN_GetClientTrainerIndex, BTL_MAIN_GetEnemyLanePos, BTL_MAIN_GetOwnLanePos, BTL_MAIN_GetEnemyLanePosFromWork, BTL_MAIN_GetFacingPos
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
 *   func_021B93E0 0x021B93E0 thumb ov093
 *   func_021BA82C 0x021BA82C thumb ov093
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
 *   func_021B9DB8 0x021B9DB8 thumb ov093
 *   func_021BA094 0x021BA094 thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 *   func_021B9114 0x021B9114 thumb ov093
 *   func_021BA54C 0x021BA54C thumb ov093
 *   func_021BA6C0 0x021BA6C0 thumb ov093
 *   func_021BA878 0x021BA878 thumb ov093
 *   func_021BA2E4 0x021BA2E4 thumb ov093
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
 *   func_021BA0CC 0x021BA0CC thumb ov093
 *   func_021B9DE8 0x021B9DE8 thumb ov093
 *   BTL_ADAPTER_NoOp 0x021EEA54 thumb ov093
 *   BTL_NET_Exit 0x021D4254 thumb ov093
 *   BTL_CALC_NoOp 0x021D8058 thumb ov093
 *   BTLV_CORE_UnloadOverlays 0x021E8DF8 thumb ov093
 *   BTLV_CORE_UnloadDsiOverlay 0x021E88F8 thumb ov093
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_02007B44 0x02007B44 thumb
 *   func_02007B20 0x02007B20 thumb
 *   func_02007C20 0x02007C20 thumb
 *   func_021B997C 0x021B997C thumb ov093
 *   func_021BA710 0x021BA710 thumb ov093
 *   func_021BA128 0x021BA128 thumb ov093
 *   func_021B9E7C 0x021B9E7C thumb ov093
 *   func_021B9E38 0x021B9E38 thumb ov093
 *   func_0201AA18 0x0201AA18 thumb
 *   BTL_REC_InitReader 0x021EE644 thumb ov093
 *   BTL_CLIENT_AttachRemoteLink 0x021CD938 thumb ov093
 *   BTLV_CORE_Create 0x021E8F20 thumb ov093
 *   BTL_CLIENT_SetView 0x021CD95C thumb ov093
 *   func_021B9460 0x021B9460 thumb ov093
 *   BTL_SERVER_Create 0x021BA9C8 thumb ov093
 *   BTL_CLIENT_Create 0x021CD6F0 thumb ov093
 *   BTL_CLIENT_GetNetChannel 0x021CD978 thumb ov093
 *   BTL_SERVER_SetClientAdapter 0x021BAA94 thumb ov093
 *   BTL_SERVER_Restart 0x021BAB40 thumb ov093
 *   func_021E9034 0x021E9034 thumb ov093
 *   BTL_CLIENT_Delete 0x021CD8E0 thumb ov093
 *   func_021B9674 0x021B9674 thumb ov093
 *   BTL_SERVER_Delete 0x021BAB5C thumb ov093
 *   gBtlMainCommSingleSteps 0x021EFD1C data a4
 *   gBtlMainCommDoubleSteps 0x021EFD00 data a4
 *   GFL_USE_SetPlayersAudible 0x02005CA4 thumb arm9
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb arm9
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb arm9
 *   GFL_USE_IsBgmFading 0x02005E50 thumb arm9
 *   RINGTONE_SYS_RegisterSleepCallbacks 0x02029F6C thumb arm9
 *   d_021EFD38 0x021EFD38 data a4
 *   d_021EFD54 0x021EFD54 data a4
 *   BTL_NET_SendEntry 0x021D4294 thumb ov093
 *   BTL_NET_IsLeaderKnown 0x021D4348 thumb ov093
 *   BTL_NET_IsLeader 0x021D4360 thumb ov093
 *   BTL_NET_GetLeaderValue 0x021D4378 thumb ov093
 *   func_021BA1A8 0x021BA1A8 thumb ov093
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
 *   func_021BA648 0x021BA648 thumb ov093
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   BTL_NET_SendPlayerInfo 0x021D4808 thumb ov093
 *   BTL_NET_IsPlayerInfoReceived 0x021D4898 thumb ov093
 *   BTL_NET_GetPlayerInfo 0x021D48CC thumb ov093
 *   BTL_NET_SendRelayedPlayerInfo 0x021D4908 thumb ov093
 *   BTL_NET_IsRelayedPlayerInfoReceived 0x021D49B0 thumb ov093
 *   BTL_NET_GetRelayedPlayerInfo 0x021D49CC thumb ov093
 *   BTL_NET_FreeRelayedPlayerInfo 0x021D49E0 thumb ov093
 *   BTL_NET_FreeAfterPlayerInfoUse 0x021D4A04 thumb ov093
 *   func_021B9EF0 0x021B9EF0 thumb ov093
 *   func_021BA670 0x021BA670 thumb ov093
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
 *   func_021B9F70 0x021B9F70 thumb ov093
 *   func_021BA698 0x021BA698 thumb ov093
 *   func_02007B00 0x02007B00 thumb
 *   func_02082D44 0x02082D44 arm
 *   BTL_SERVER_CreateClientAdapter 0x021BAACC thumb ov093
 *   BTL_SERVER_SetClientWithoutAdapter 0x021BAB10 thumb ov093
 *   BTL_CLIENT_SetRequestParam 0x021CD960 thumb ov093
 *   func_021B9010 0x021B9010 thumb ov093
 *   BTL_SERVER_Update 0x021BAB9C thumb ov093
 *   BTL_CLIENT_RunTick 0x021CD97C thumb ov093
 *   func_021CDD94 0x021CDD94 thumb ov093
 *   func_021E908C 0x021E908C thumb ov093
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
 *   func_021B8CB0 0x021B8CB0 thumb ov093
 *   func_021B99F0 0x021B99F0 thumb ov093
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
extern void func_021B93E0(struct BtlSide *side, struct BtlMain *main, u32 sideIndex);
extern void func_021BA82C(struct BattleSetupParam *setup);
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
extern void func_021B9DB8(struct BtlMain *main);
extern void func_021BA094(struct BtlMain *main);
extern void func_021BA1B4(struct BtlMain *main, int arg);
extern u8 func_021B9114(struct BtlMain *main);
extern int func_021BA54C(struct BtlMain *main);
extern void func_021BA6C0(struct BtlMain *main);
extern void func_021BA878(struct BtlMain *main);
extern void func_021BA2E4(struct BtlMain *main);
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
extern void func_021BA0CC(struct BtlMain *main);
extern void func_021B9DE8(struct BtlMain *main);
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
extern int func_021B997C(struct BtlMain *main, unsigned int client);
extern u8 func_021BA710(int ownClient, int client);
extern void func_021BA128(struct BtlMain *main, int client, struct Party *party);
extern void func_021B9E7C(struct BtlTrainerSlot *slot, struct BattleTrainerData *trainer);
extern void func_021B9E38(struct BtlTrainerSlot *slot, int heapId, void *playerStatus);
extern u32 func_0201AA18(void *party);
extern void BTL_REC_InitReader(void *reader, void *recordBuffer, int size);
extern void BTL_CLIENT_AttachRemoteLink(struct BtlClient *client, void *reader);
extern struct BtlvCore *BTLV_CORE_Create(struct BtlMain *main, struct BtlClient *client, struct BtlSide *side, int isComm, u16 heapId);
extern void BTL_CLIENT_SetView(struct BtlClient *client, struct BtlvCore *viewCore);
extern void func_021B9460(struct BtlSide *side, struct BtlMain *main, u8 slot);
extern struct BtlServer *BTL_SERVER_Create(struct BtlMain *main, struct BattleRngState *rng, struct BtlSide *side, int isComm, u16 heapId);
extern struct BtlClient *BTL_CLIENT_Create(struct BtlMain *main, struct BtlSide *side, int unused, int netHandle, u16 clientId, u16 slotCount, u8 isOpponent, int isComm, int ownsSlots, struct BattleRngState *rng, u16 heapId);
extern u32 BTL_CLIENT_GetNetChannel(struct BtlClient *client);
extern void BTL_SERVER_SetClientAdapter(struct BtlServer *server, int clientRef, u8 clientId, u8 slotCount);
extern void BTL_SERVER_Restart(struct BtlServer *server);
extern void func_021E9034(struct BtlvCore *viewCore);
extern void BTL_CLIENT_Delete(struct BtlClient *client);
extern void func_021B9674(struct BtlSide *side);
extern void BTL_SERVER_Delete(struct BtlServer *server);
extern int (*d_021EFD38[7])(struct BtlMain *, u32 *);
extern int BTL_NET_SendEntry(u16 v);
extern int BTL_NET_IsLeaderKnown(void);
extern int BTL_NET_IsLeader(void);
extern u8 BTL_NET_GetLeaderValue(void);
extern int func_021BA1A8(struct BtlMain *main, int mask);
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
extern void func_021BA648(struct BtlMain *main, u8 client, void *dst);
extern int POKE_REGULATION_GetDataSize(void);
extern int BTL_NET_SendPlayerInfo(u32 a);
extern int BTL_NET_IsPlayerInfoReceived(void);
extern void *BTL_NET_GetPlayerInfo(u8);
extern u32 BTL_NET_SendRelayedPlayerInfo(void *);
extern int BTL_NET_IsRelayedPlayerInfoReceived(void);
extern void *BTL_NET_GetRelayedPlayerInfo(void);
extern void BTL_NET_FreeRelayedPlayerInfo(void);
extern void BTL_NET_FreeAfterPlayerInfoUse(void);
extern void func_021B9EF0(struct BtlTrainerSlot *slot, const void *src);
extern void func_021BA670(struct BtlMain *main, u8 client, void *src);
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
extern int func_021B9F70(struct BtlMain *main, int slot);
extern void func_021BA698(struct BtlMain *main, int client);
extern u32 func_02007B00(void);
extern void func_02082D44(const void *,void *,u32);
extern void BTL_SERVER_CreateClientAdapter(struct BtlServer *server, int unused, int netId, int clientId, u8 slotCount);
extern void BTL_SERVER_SetClientWithoutAdapter(struct BtlServer *server, u8 clientId, int slotCount);
extern void BTL_CLIENT_SetRequestParam(struct BtlClient *client, struct BtlServer *server);
extern u8 func_021B9010(struct BtlMain *main, u8 clientId);
extern int BTL_SERVER_Update(struct BtlServer *server);
extern int BTL_CLIENT_RunTick(struct BtlClient *client);
extern void func_021CDD94(struct BtlClient *client, void *buf);
extern void func_021E908C(struct BtlvCore *viewCore);
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
extern int (*d_021EFD54[7])(struct BtlMain *, u32 *);
extern u8 func_021B8CB0(struct BtlMain *main, u8 basePos);
extern u32 func_021B99F0(u32 basePos);

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
int BTL_MAIN_GetPositionsPerClient(struct BtlMain *main, u32 clientId);
void BTL_MAIN_InitFirstTwoTrainerSlots(struct BtlMain *main, struct BattleSetupParam *setup);
void func_021B6A3C(struct BtlMain *main, struct BattleSetupParam *setup);
void BTL_MAIN_CreateViewCore(struct BtlMain *main, struct BattleSetupParam *setup, int isComm);
int BTL_MAIN_TaskSetupSingle(u32 *unused, void *arg);
int func_021B6C08(u32 *unused, void *arg);
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
int func_021B871C(struct BtlMain *main);
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
      main->flags.unusedBit3 = 0;
      main->flags.unusedBit4 = 0;
      main->flags.commLost = 0;
      main->flags.commLostHandled = 0;
      main->flags.keepBgm = 0;
      main->flags.unusedBit6 = 0;
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
      func_021B93E0(&main->sides[0], main, 0);
      func_021B93E0(&main->sides[1], main, 1);
      func_021BA82C(main->setup);
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
        func_021B9DB8(main);
        func_021BA094(main);
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
          func_021BA1B4(main, 4);
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
        if (func_021B9114(main) == 0) {
            result = func_021BA54C(main);
            func_021BA6C0(main);
            func_021BA878(main);
            func_021BA2E4(main);
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
        func_021BA0CC(main);
        func_021B9DE8(main);
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
    startTask(task, main, func_021B6C08);
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
    if (func_021B9114(main) == 0) {
        srcVoice = func_02007B44(GAME_DATA_GetSaveControl(setup->gameData));
        main->voices[0] = func_02007B20(main->heapId);
        func_02007C20(main->voices[0], srcVoice);
        main->setup->voiceFlags[0] = func_021B997C(main, client);
    } else {
        for (client = 0; client < 4; client++) {
            voiceOrder[func_021BA710(main->ownClientId, (u8)client)] = main->setup->voiceFlags[client];
        }
        for (client = 0; client < 4; client++) {
            main->setup->voiceFlags[client] = voiceOrder[client];
        }
    }
}

void BTL_MAIN_InitClientParties(struct BtlMain *main, struct BattleSetupParam *setup)
{
    int firstSrc, secondSrc, thirdSrc, fourthSrc;

    firstSrc = func_021BA710(main->ownClientId, 0);
    secondSrc = func_021BA710(main->ownClientId, 1);
    func_021BA128(main, 0, setup->party[firstSrc]);
    func_021BA128(main, 1, setup->party[secondSrc]);
    thirdSrc = func_021BA710(main->ownClientId, 2);
    fourthSrc = func_021BA710(main->ownClientId, 3);
    if (setup->party[thirdSrc] != 0) {
        func_021BA128(main, 2, setup->party[thirdSrc]);
    }
    if (setup->party[fourthSrc] != 0) {
        func_021BA128(main, 3, setup->party[fourthSrc]);
    }
}

void BTL_MAIN_InitTrainerSlot(struct BtlMain *main, int slot)
{
    struct BattleSetupParam *setup = main->setup;
    int source = func_021BA710(main->ownClientId, slot);
    struct BtlTrainerSlot *trainerSlot = &main->trainers[slot];
    struct BattleTrainerData *trainer = setup->trainerData[source];
    if (trainer->trainerId != 0)
        func_021B9E7C(trainerSlot, trainer);
    else
        func_021B9E38(trainerSlot, main->heapId, setup->playerStatus[source]);
}

int BTL_MAIN_GetPositionsPerClient(struct BtlMain *main, u32 clientId)
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
        if (partner != 0 && (int)func_0201AA18(partner) > 0) {
            return 1;
        }
        return 2;
    }
    return 1;
}

void BTL_MAIN_InitFirstTwoTrainerSlots(struct BtlMain *main, struct BattleSetupParam *setup)
{
    if (setup->ownsSlots == 0) {
        func_021B9E38(&main->trainers[0], main->heapId, main->playerStatus);
        func_021B9E7C(&main->trainers[1], setup->trainerData[1]);
    } else {
        BTL_MAIN_InitTrainerSlot(main, 0);
        BTL_MAIN_InitTrainerSlot(main, 1);
    }
}

void func_021B6A3C(struct BtlMain *main, struct BattleSetupParam *setup)
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
    func_021B93E0(&main->sides[0], main, 0);
    func_021B9460(&main->sides[0], main, 0);
    func_021B9460(&main->sides[0], main, 1);
    func_021B93E0(&main->sides[1], main, 1);
    func_021B9460(&main->sides[1], main, 0);
    func_021B9460(&main->sides[1], main, 1);
    main->server = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
    main->hostsServer = 1;
    BTL_MAIN_InitFirstTwoTrainerSlots(main, setup);
    main->clients[0] = BTL_CLIENT_Create(main, &main->sides[0], 0, setup->netHandle, 0, 1, 0, isComm, setup->ownsSlots, &main->rng, main->heapId);
    main->clients[1] = BTL_CLIENT_Create(main, &main->sides[0], 0, setup->netHandle, 1, 1, 1, isComm, setup->ownsSlots, &main->rng, main->heapId);
    func_021B6A3C(main, setup);
    BTL_MAIN_CreateViewCore(main, setup, isComm);
    BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[0]), 0, 1);
    BTL_SERVER_SetClientAdapter(main->server, BTL_CLIENT_GetNetChannel(main->clients[1]), 1, 1);
    BTL_SERVER_Restart(main->server);
    main->tick = BTL_MAIN_StepClientsSolo;
    return 1;
}

int func_021B6C08(u32 *unused, void *arg)
{
    struct BtlMain *main = arg;
    u32 client;

    if (main->viewCore != 0) {
        func_021E9034(main->viewCore);
        main->viewCore = 0;
    }
    for (client = 0; client < 4; client++) {
        if (main->clients[client] != 0) {
            BTL_CLIENT_Delete(main->clients[client]);
        }
    }
    func_021B9674(&main->sides[0]);
    func_021B9674(&main->sides[1]);
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
    func_021B93E0(&main->sides[0], main, 0);
    func_021B9460(&main->sides[0], main, 0);
    func_021B9460(&main->sides[0], main, 1);
    func_021B93E0(&main->sides[1], main, 1);
    func_021B9460(&main->sides[1], main, 0);
    func_021B9460(&main->sides[1], main, 1);
    BTL_MAIN_InitFirstTwoTrainerSlots(main, setup);
    main->server = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
    main->hostsServer = 1;
    main->clients[0] = BTL_CLIENT_Create(main, &main->sides[0], 0, setup->netHandle, 0, 2, 0, isComm, setup->ownsSlots, &main->rng, main->heapId);
    main->clients[1] = BTL_CLIENT_Create(main, &main->sides[0], 0, setup->netHandle, 1, 2, 1, isComm, setup->ownsSlots, &main->rng, main->heapId);
    func_021B6A3C(main, setup);
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
    func_021B93E0(&main->sides[0], main, 0);
    func_021B93E0(&main->sides[1], main, 1);
    for (client = 0; client < 4; client++) {
        if (BTL_MAIN_IsClientUsed(main, client)) {
            func_021B9460(&main->sides[0], main, client);
            func_021B9460(&main->sides[1], main, client);
        }
    }
    if (!setup->ownsSlots) {
        func_021B9E38(&main->trainers[0], main->heapId, main->playerStatus);
        func_021B9E7C(&main->trainers[1], setup->trainerData[1]);
        if (BTL_MAIN_IsClientUsed(main, 2)) func_021B9E7C(&main->trainers[2], setup->trainerData[2]);
        if (BTL_MAIN_IsClientUsed(main, 3)) func_021B9E7C(&main->trainers[3], setup->trainerData[3]);
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
    func_021B93E0(&main->sides[0], main, 0);
    func_021B9460(&main->sides[0], main, 0);
    func_021B9460(&main->sides[0], main, 1);
    func_021B93E0(&main->sides[1], main, 1);
    func_021B9460(&main->sides[1], main, 0);
    func_021B9460(&main->sides[1], main, 1);
    BTL_MAIN_InitFirstTwoTrainerSlots(main, setup);
    main->server = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
    main->hostsServer = 1;
    main->clients[0] = BTL_CLIENT_Create(main, &main->sides[0], 0, setup->netHandle, 0, 3, 0, isComm, setup->ownsSlots, &main->rng, main->heapId);
    main->clients[1] = BTL_CLIENT_Create(main, &main->sides[0], 0, setup->netHandle, 1, 3, 1, isComm, setup->ownsSlots, &main->rng, main->heapId);
    func_021B6A3C(main, setup);
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
    func_021B93E0(&main->sides[0], main, 0);
    func_021B9460(&main->sides[0], main, 0);
    func_021B9460(&main->sides[0], main, 1);
    func_021B93E0(&main->sides[1], main, 1);
    func_021B9460(&main->sides[1], main, 0);
    func_021B9460(&main->sides[1], main, 1);
    main->server = BTL_SERVER_Create(main, &main->rng, &main->sides[1], isComm, main->heapId);
    main->hostsServer = 1;
    BTL_MAIN_InitFirstTwoTrainerSlots(main, setup);
    main->clients[0] = BTL_CLIENT_Create(main, &main->sides[0], 0, setup->netHandle, 0, 1, 0, isComm, setup->ownsSlots, &main->rng, main->heapId);
    main->clients[1] = BTL_CLIENT_Create(main, &main->sides[0], 0, setup->netHandle, 1, 1, 1, isComm, setup->ownsSlots, &main->rng, main->heapId);
    func_021B6A3C(main, setup);
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
        if (d_021EFD38[*step](main, &main->subStep)) {
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
        if (d_021EFD54[*step](main, &main->subStep)) {
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
        if (func_021BA1A8(main, 0x1000)) {
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
        func_021B93E0(&main->sides[0], main, 0);
        side = &main->sides[0];
        for (i = 0; i < 4; ++i) {
            if (BTL_MAIN_IsClientUsed(main, i)) {
                func_021BA128(main, (u8)i, BTL_NET_GetParty(i));
                func_021BA648(main, i, BTL_NET_GetParty(i));
                func_021B9460(side, main, i);
            }
        }
        ++*state;
        break;
    case 11:
        func_021B93E0(&main->sides[1], main, 1);
        for (i = 0; i < 4; ++i) {
            if (BTL_MAIN_IsClientUsed(main, i)) func_021B9460(&main->sides[1], main, i);
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
                    func_021B9E38(&main->trainers[i], main->heapId, status);
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
                    func_021BA670(main, i, main->trainers[i].handle);
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
            func_021B9EF0(&main->trainers[main->exchangeSlot], BTL_NET_GetRelayedPlayerInfo());
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
                if (BTL_MAIN_IsClientUsed(main, i) && !func_021B9F70(main, (u8)i)) {
                    src = (void *)BTL_NET_GetPerapVoice((u8)i);
                    if (src) {
                        main->voices[i] = func_02007B20(main->heapId);
                        func_02082D44(src, main->voices[i], func_02007B00());
                    }
                }
                func_021BA698(main, (u8)i);
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
            x = func_021B9010(main, clientId);
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
            func_021CDD94(main->clients[i], &main->defeatedClients);
            found = 1;
        }
    }
    func_021E908C(main->viewCore);
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
        func_021CDD94(main->clients[main->ownClientId], &main->defeatedClients);
        r = 1;
    }
    func_021E908C(main->viewCore);
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
            func_021CDD94(main->clients[i], &main->defeatedClients);
            r = 1;
        }
    }
    func_021E908C(main->viewCore);
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
        if (func_021BA1A8(main, 0x200) == 0) {
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



int func_021B871C(struct BtlMain *main)
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
        out[2] = func_021B8CB0(main, basePos);
        return 3;
    case BTL_RANGE_SELF_AND_ALLIES_IN_REACH:
        out[0] = basePos;
        out[1] = func_021B8CB0(main, basePos);
        if (out[0] > out[1]) {
            tmp = out[0];
            out[0] = out[1];
            out[1] = tmp;
        }
        return 2;
    case BTL_RANGE_ALLIES_IN_REACH:
    case BTL_RANGE_ALLIES_IN_REACH_ALT:
        out[0] = func_021B8CB0(main, basePos);
        return 1;
    case BTL_RANGE_ALL_ALLIES:
        out[0] = basePos;
        out[1] = func_021B8CB0(main, basePos);
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
 * row (func_021B99F0) reaches all three lanes of the other side; a position
 * in an outer row reaches the centre lane and the lane that faces it.
 * The facing-lane swap is written out in each case, as in the original.
 */
u8 BTL_MAIN_ExpandPosTriple(struct BtlMain *main, u32 rangeType, u32 basePos, u8 *out)
{
    u8 inMiddleRow = func_021B99F0(basePos);
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
