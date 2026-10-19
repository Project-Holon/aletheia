/*
 * file:     union_oneself.c
 * unit:     yes
 * function: UNION_ONESELF_TryStartSubEvent, UNION_ONESELF_GetFieldTalkEvent, UNION_ONESELF_RunPlayCategory, UNION_ONESELF_SetNextPlayCategory, UNION_ONESELF_SetNextPlayCategoryInMainPhase, UNION_ONESELF_GetRegulationId, UNION_ONESELF_GetRegulationFlag, UNION_ONESELF_IsBattleStatus, UNION_ONESELF_CreateBattleTeamParty, UNION_ONESELF_DeleteParty, UNION_ONESELF_LoadRegulation, UNION_ONESELF_CheckMyParty, UNION_ONESELF_CheckBattleTeamParty, UNION_ONESELF_CheckEntryParties, UNION_ONESELF_SetFieldBusy, UNION_ONESELF_HandleNetError, UNION_ONESELF_HandleNetErrorExit, UNION_ONESELF_IdleStart, UNION_ONESELF_IdleMain, UNION_ONESELF_ErrorMain, UNION_ONESELF_NoOpMain, UNION_ONESELF_FieldExitMain, UNION_ONESELF_ChatInputMain, UNION_ONESELF_ConnectParentStart, UNION_ONESELF_ConnectParentMain, UNION_ONESELF_ConnectParentEnd, UNION_ONESELF_ConnectChildStart, UNION_ONESELF_ConnectChildMain, UNION_ONESELF_ConnectChildEnd, UNION_ONESELF_TalkParentStart, UNION_ONESELF_TalkParentMain, UNION_ONESELF_TalkParentEnd, UNION_ONESELF_TalkParentAnswerWaitMain, UNION_ONESELF_TalkChildStart, UNION_ONESELF_TalkChildMain, UNION_ONESELF_TalkChildEnd, UNION_ONESELF_BattleMenuMain, UNION_ONESELF_TalkPlayingMain, UNION_ONESELF_TalkPlayingChildMain, UNION_ONESELF_TrainerCardMain, UNION_ONESELF_TradeMain, UNION_ONESELF_JoinMain, UNION_ONESELF_ConnectGroupMain, UNION_ONESELF_AppMain, UNION_ONESELF_ColosseumEnterParentMain, UNION_ONESELF_ColosseumEnterChildMain, UNION_ONESELF_ColosseumEntryMain, UNION_ONESELF_EntryMenuAddMember, UNION_ONESELF_EntryMenuRemoveMember, UNION_ONESELF_ColosseumSetupMain, UNION_ONESELF_ColosseumFreeMoveStart, UNION_ONESELF_ColosseumFreeMoveMain, UNION_ONESELF_ColosseumStandPosMain, UNION_ONESELF_ColosseumLeavePosMain, UNION_ONESELF_ColosseumPartySelectMain, UNION_ONESELF_ColosseumReadyWaitMain, UNION_ONESELF_ColosseumPartyExchangeMain, UNION_ONESELF_ColosseumBattleMain, UNION_ONESELF_ColosseumLeaveConfirmMain, UNION_ONESELF_ColosseumExitMain, UNION_ONESELF_ColosseumTrainerCardMain
 * address:  0x0217B80C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from unit_0217AE20.c, union_oneself.c by tools/splitfile.py.
 *
 * symbols:
 *   GF_PANIC_Fail 0x02034714 arm
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MET_TRAINERS_GetFromSave  0x0200ED48  thumb
 *   UNION_MSG_GetCategoryTableValue  0x0217F060  thumb  ov019
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   UNION_COMM_SetSituationParam 0x021734A8  thumb  ov012
 *   GAMESYSTEM_GetGameComm 0x02012138 thumb
 *   GAME_COMM_GetWork 0x02026474 thumb
 *   UNION_SCENE_CreateSubEvent 0x0217413C thumb ov012
 *   gUnionOneselfActionStart  0x02180074  data  a4
 *   gUnionOneselfActionMain  0x02180078  data  a4
 *   gUnionOneselfActionEnd  0x0218007C  data  a4
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   BATTLE_BOX_HasMon 0x0200BBA8 thumb
 *   BATTLE_BOX_CreateParty 0x0200BAF4 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   gUnionEmptyString1 0x021807E4 data a1
 *   POKE_REGULATION_LoadInto 0x0201A364 thumb
 *   REGULATION_SetRuleValue 0x0200AEE8 thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKE_REGULATION_CheckParty 0x0201A090 thumb
 *   FIELDMAP_CTRL_GRID_SetBusy 0x021A2E44 thumb ov021
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   UNION_COMM_InitConnectInfo 0x02173524 thumb ov012
 *   UNION_MSG_CloseAllWindows 0x0217F074 thumb ov019
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELD_PLAYER_GetFrontGridPos  0x021A3460  thumb  ov021
 *   UNION_COMM_RequestRestart  0x02172D20  thumb  ov012
 *   UNION_COMM_IsResetting  0x02172D68  thumb  ov012
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb  ov010
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   UNION_ONESELF_IsPlayerAtReceptionSpot  0x0217F7E4  thumb  ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   GAMESYSTEM_SetFieldMapState  0x02012124  thumb
 *   UNION_COMM_RequestShutdown  0x02172D38  thumb  ov012
 *   UNION_COMM_ReleaseWorks  0x02173420  thumb  ov012
 *   UNION_COMM_RequestStart  0x02172D50  thumb  ov012
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   UNION_SCENE_RequestScene  0x0217422C  thumb  ov012
 *   UNION_SCENE_IsScenePending  0x02174268  thumb  ov012
 *   UNION_COMM_SetChatPms  0x021736A0  thumb  ov012
 *   d_021807E8     0x021807E8  data  a4
 *   UNION_ONESELF_HandleNetError  0x0217BB04  thumb  ov019
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   UNION_COMMAND_SendPartnerMode  0x02173AFC  thumb  ov012
 *   GFL_NET_SetChangeoverModeWrapper  0x0203D14C  arm
 *   GFL_NET_IsConnectMember  0x0203D1C0  arm
 *   GFL_NET_SetAcceptConnection  0x0203D1E8  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GFL_NET_SYSTEM_GetConnectNum  0x020392B8  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   UNION_ONESELF_SetFieldBusy 0x0217BAF0 thumb ov019
 *   UNION_COMMAND_SendMyMac  0x02173A90  thumb ov012
 *   UNION_COMM_ClearPartnerSelects  0x02173518  thumb  ov012
 *   UNION_COMM_AddMemberFromBeaconPc  0x021735FC  thumb  ov012
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   UNION_COMMAND_SendMyStatus  0x02173B4C  thumb  ov012
 *   MATH_CountPopulation  0x02080D24  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   POKEPARTY_GetNonEggCount  0x0201AA1C  thumb
 *   POKEPARTY_GetBadEggCount  0x0201AAD4  thumb
 *   POKEPARTY_GetEggCount  0x0201AA88  thumb
 *   UNION_COMMAND_SendPartnerSelectA  0x02173A04  thumb ov012
 *   UNION_ONESELF_IsBattleStatus  0x0217B9BC  thumb ov019
 *   UNION_ONESELF_LoadRegulation  0x0217BA10  thumb ov019
 *   UNION_ONESELF_GetRegulationFlag  0x0217B974  thumb ov019
 *   UNION_ONESELF_CheckEntryParties  0x0217BAA8  thumb ov019
 *   UNION_COMMAND_SendPartnerSelectB  0x02173A48  thumb ov012
 *   UNION_CHARA_GetBeaconIndex 0x0217AEFC thumb ov019
 *   UNION_CHARA_GetSexByObjId  0x0217AF04  thumb ov019
 *   TRCARD_SYS_BuildProfile  0x0216F40C  thumb  ov010
 *   MI_CpuCopy8  0x02082D44  arm
 *   UNION_COMMAND_SendTrainerCard  0x02173BB0  thumb  ov012
 *   TRCARD_SYS_CreateEditWork  0x0216F7F4  thumb  ov010
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   GAME_DATA_GetMyStatusPlayer  0x02012950  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   MET_TRAINERS_Insert  0x0200ED54  thumb
 *   POKEPARTY_Create  0x0201A920  thumb
 *   UNION_COMM_SetGameKindByStatus  0x021736E0  thumb  ov012
 *   UNION_COMM_StartConnectSync  0x02172EDC  thumb  ov012
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   UNION_COMM_RemoveMemberOfBeaconPc  0x02173650  thumb  ov012
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   UNION_COMMAND_SendAppEntry  0x02173D38  thumb  ov012
 *   COLOSSEUM_Create  0x02174F4C  thumb  ov012
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   UNION_ONESELF_HandleNetErrorExit  0x0217BB20  thumb  ov019
 *   UNION_COMMAND_SendColosseumCancel  0x02173CB4  thumb  ov012
 *   COMM_ENTRY_MENU_Create  0x021CD48C  thumb  ov021
 *   COMM_ENTRY_MENU_Delete  0x021CD5A4  thumb  ov021
 *   COMM_ENTRY_MENU_SetCallbacks  0x021CD60C  thumb  ov021
 *   COMM_ENTRY_MENU_Main  0x021CD688  thumb  ov021
 *   MYSTATUS_GetTrainerView  0x02008554  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   UNION_COMM_AddMember  0x0217357C  thumb  ov012
 *   UNION_COMM_RemoveMember  0x02173614  thumb  ov012
 *   COLOSSEUM_AddCommandTable  0x02174B40  thumb  ov012
 *   COLOSSEUM_SendPlayerEntry  0x02174BB8  thumb  ov012
 *   COLOSSEUM_SendTrainerCard  0x02174C34  thumb  ov012
 *   COLOSSEUM_SetStartFlag  0x02175094  thumb  ov012
 *   COLOSSEUM_SetMyChoice  0x021750B0  thumb  ov012
 *   COMM_PLAYER_SearchGridPos  0x021679A4  thumb  ov010
 *   COLOSSEUM_SendChoiceRequest  0x02174CE4  thumb  ov012
 *   COLOSSEUM_GetMyChoiceReply  0x021750D0  thumb  ov012
 *   UNION_ONESELF_CheckMyParty  0x0217BA48  thumb  ov019
 *   UNION_ONESELF_CheckBattleTeamParty  0x0217BA6C  thumb  ov019
 *   UNION_ONESELF_CreateBattleTeamParty  0x0217B9CC  thumb  ov019
 *   PARTY_SELECT_LIST_Create  0x021CC720  thumb  ov021
 *   PARTY_SELECT_LIST_Main  0x021CC810  thumb  ov021
 *   PARTY_SELECT_LIST_Delete  0x021CC7B4  thumb  ov021
 *   UNION_ONESELF_DeleteParty  0x0217B9F4  thumb  ov019
 *   COLOSSEUM_SendReady  0x02174E20  thumb  ov012
 *   COLOSSEUM_SendReadyCancel  0x02174E64  thumb  ov012
 *   COLOSSEUM_ResetParties  0x02175240  thumb  ov012
 *   COLOSSEUM_ClearConfirmCount  0x02175208  thumb  ov012
 *   COLOSSEUM_AllPartiesReceived  0x02175214  thumb  ov012
 *   COLOSSEUM_SendParty  0x02174D98  thumb  ov012
 *   COLOSSEUM_SendBattlePositions  0x02174DF0  thumb  ov012
 *   POKEPARTY_Copy  0x0201AC2C  thumb
 *   POKE_REGULATION_AdjustPartyLevels  0x0201A2A8  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   SYSTEM_DATA_GetConfig  0x0200873C  thumb
 *   MYSTATUS_GetName  0x020084F4  thumb
 *   UNION_CHARA_ClearTable  0x0217AE20  thumb  ov019
 *   COLOSSEUM_SendFinish  0x02174F34  thumb  ov012
 *   UNION_COMM_ClearBeaconPcs  0x02173408  thumb  ov012
 *   COLOSSEUM_Delete  0x0217505C  thumb  ov012
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   MYSTATUS_GetRomCode  0x0200855C  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   UNION_MSG_GetNoReplyMsg  0x0217EC04  thumb  ov019
 *   UNION_MSG_GetTalkParentGreetingMsg  0x0217EC1C  thumb  ov019
 *   UNION_MSG_GetTalkParentCancelMsg  0x0217EC28  thumb  ov019
 *   UNION_MSG_GetTalkChildBusyMsg  0x0217EC34  thumb  ov019
 *   UNION_MSG_GetTalkParentAcceptMsg  0x0217EC40  thumb  ov019
 *   UNION_MSG_GetTalkParentRefuseMsg  0x0217EC54  thumb  ov019
 *   UNION_MSG_GetTalkChildOfferMsg  0x0217EC68  thumb  ov019
 *   UNION_MSG_GetTalkChildDeclineMsg  0x0217EC78  thumb  ov019
 *   UNION_MSG_GetTalkMenuPromptMsg  0x0217EC88  thumb  ov019
 *   UNION_MSG_GetColosseumStartMsg  0x0217EC94  thumb  ov019
 *   UNION_MSG_GetNotEnoughPokemonMsg  0x0217ECA0  thumb  ov019
 *   UNION_MSG_GetNoEggInPartyMsg  0x0217ECAC  thumb  ov019
 *   UNION_MSG_GetBadEggInPartyMsg  0x0217ECB8  thumb  ov019
 *   UNION_MSG_GetBadEggNoticeMsg  0x0217ECD0  thumb  ov019
 *   UNION_MSG_GetBattleChatMsg  0x0217ECE8  thumb  ov019
 *   UNION_MSG_GetPartnerBusyMsg  0x0217ED04  thumb  ov019
 *   UNION_MSG_GetTrainerCardChatMsg  0x0217ED10  thumb  ov019
 *   UNION_MSG_GetDrawChatMsg  0x0217ED2C  thumb  ov019
 *   UNION_MSG_GetTradeChatMsg  0x0217ED48  thumb  ov019
 *   UNION_MSG_GetSpinTradeChatMsg  0x0217ED64  thumb  ov019
 *   UNION_MSG_GetMultiBattleInviteMsg  0x0217ED80  thumb  ov019
 *   UNION_MSG_GetSpinTradeInviteMsg  0x0217ED8C  thumb  ov019
 *   UNION_MSG_GetDrawInviteMsg  0x0217ED98  thumb  ov019
 *   UNION_MSG_GetMultiBattleInviteDeclinedMsg  0x0217EDA4  thumb  ov019
 *   UNION_MSG_GetSpinTradeInviteDeclinedMsg  0x0217EDB0  thumb  ov019
 *   UNION_MSG_GetDrawInviteDeclinedMsg  0x0217EDBC  thumb  ov019
 *   UNION_MSG_GetSpinTradeNoEggMsg  0x0217EDC8  thumb  ov019
 *   UNION_MSG_GetSpinTradeBadEggMsg  0x0217EDD4  thumb  ov019
 *   UNION_MSG_GetSpinTradeWaitMsg  0x0217EDE0  thumb  ov019
 *   UNION_MSG_GetSpinTradeStartMsg  0x0217EDEC  thumb  ov019
 *   UNION_MSG_GetSpinTradeBusyMsg  0x0217EDF8  thumb  ov019
 *   UNION_MSG_GetDrawWaitMsg  0x0217EE04  thumb  ov019
 *   UNION_MSG_GetDrawStartMsg  0x0217EE10  thumb  ov019
 *   UNION_MSG_GetDrawBusyMsg  0x0217EE1C  thumb  ov019
 *   UNION_MSG_GetMultiBattleWaitMsg  0x0217EE28  thumb  ov019
 *   UNION_MSG_GetMultiBattleStartMsg  0x0217EE34  thumb  ov019
 *   UNION_MSG_GetMultiBattleBusyMsg  0x0217EE40  thumb  ov019
 *   UNION_MSG_CheckLanguageVersion  0x0217EE4C  thumb  ov019
 *   UNION_MSG_SetupTalkWindow  0x0217F098  thumb  ov019
 *   UNION_MSG_PrintTalkMsg  0x0217F188  thumb  ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb  ov019
 *   UNION_MSG_SetupYesNo  0x0217F22C  thumb  ov019
 *   UNION_MSG_DeleteYesNo  0x0217F24C  thumb  ov019
 *   UNION_MSG_SelectYesNo  0x0217F268  thumb  ov019
 *   UNION_MSG_SetupMainMenu  0x0217F360  thumb  ov019
 *   UNION_MSG_DeleteMainMenu  0x0217F378  thumb  ov019
 *   UNION_MSG_SelectMainMenu  0x0217F380  thumb  ov019
 *   UNION_MSG_SetupSubMenu  0x0217F388  thumb  ov019
 *   UNION_MSG_DeleteSubMenu  0x0217F4AC  thumb  ov019
 *   UNION_MSG_SelectSubMenu  0x0217F4B4  thumb  ov019
 *   UNION_MSG_SetupTitleWindow  0x0217F5E0  thumb  ov019
 *   UNION_MSG_DeleteTitleWindow  0x0217F624  thumb  ov019
 *   UNION_MSG_SetupRegulationWindow  0x0217F640  thumb  ov019
 *   UNION_MSG_CheckRegulationPrintEnd  0x0217F794  thumb  ov019
 *   UNION_MSG_DeleteRegulationWindow  0x0217F7B8  thumb  ov019
 *   COLOSSEUM_CheckAllEntered  0x0217FDC8  thumb  ov019
 *   COLOSSEUM_CheckAllTrainerCardsReceived  0x0217FDF8  thumb  ov019
 *   COLOSSEUM_IsPositionsReceived  0x0217FE24  thumb  ov019
 *   COLOSSEUM_ClearPositionsReceived  0x0217FE38  thumb  ov019
 *   COLOSSEUM_IsOnStandPos  0x0217FE44  thumb  ov019
 *   COLOSSEUM_CheckAllFinished  0x0217FEB8  thumb  ov019
 *   COLOSSEUM_IsAnyFinished  0x0217FEF4  thumb  ov019
 *   COLOSSEUM_IsOnCounterPos  0x0217FF14  thumb  ov019
 *   UNION_CHARA_IsChildObjId 0x0217AEE8 thumb ov019
 *   UNION_CHARA_IsUnionObjId 0x0217AF38 thumb ov019
 *   UNION_CHARA_CheckTalkable 0x0217AF4C thumb ov019
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef signed int s32;
typedef struct { s32 x, y, z; } VecFx32;
typedef enum { FALSE, TRUE } BOOL;

#include "../ov012/union_comm_types.h"
#include "union_chara_types.h"

void GF_PANIC_Fail(char *file, unsigned int line, char *expr);
struct GameData;
struct SaveControl;

extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gd);
struct FieldMap;
struct FieldPlayer;

extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
struct UnionRoomWork;

extern void UNION_COMM_SetSituationParam(struct UnionRoomWork *work, unsigned int id, unsigned int value);
struct GameSystem;
struct GameComm;

extern struct GameComm *GAMESYSTEM_GetGameComm(struct GameSystem *gameSystem);

extern void *GAME_COMM_GetWork(struct GameComm *comm);
struct UnionRoomWork;

extern void *UNION_SCENE_CreateSubEvent(struct GameSystem *gameSystem, void *fieldMap, UnionRoomWork *work);
struct BattleBoxSave;

extern struct BattleBoxSave *BATTLE_BOX_GetFromSave(struct SaveControl *save);
struct BoxMonGroup;

extern u32 BATTLE_BOX_HasMon(struct BoxMonGroup *box);
struct Party;

extern struct Party *BATTLE_BOX_CreateParty(struct BoxMonGroup *box, int heap);

extern u32 GFL_HEAP_Free(void *block);

extern void POKE_REGULATION_LoadInto(int memberId, void *dst);

extern void REGULATION_SetRuleValue(struct Regulation *regulation, u32 id, s32 value);

extern void *GAME_DATA_GetMyParty(const struct GameData *gameData);

extern int POKE_REGULATION_CheckParty(struct Regulation *reg, struct Party *party, unsigned int *flags);

extern void FIELDMAP_CTRL_GRID_SetBusy(struct FieldMap *fieldMap, unsigned int busy);

extern u32 GFL_NET_ERR_GetErrorLevel(void);
struct UnionConnectInfo;

void UNION_COMM_InitConnectInfo(struct UnionRoomWork *work, struct UnionConnectInfo *connect);

void UNION_MSG_CloseAllWindows(UnionRoomWork *unisys);
struct MmdlSys;

extern struct MmdlSys *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);

extern void FIELD_PLAYER_GetFrontGridPos(struct FieldPlayer *player, short *gridX, short *gridY, short *gridZ);

extern void UNION_COMM_RequestRestart(struct UnionRoomWork *work);

extern int UNION_COMM_IsResetting(struct UnionRoomWork *work);
struct Mmdl;

extern u16   FLDMMDL_GetObjId(struct Mmdl *mmdl);

extern struct Mmdl *FLDMMDL_SysSearchGridPos(struct MmdlSys *sys, unsigned int gridX, unsigned int gridZ, unsigned int flag);

extern int   GFL_NET_GetNegotiationNum(void);

extern u32   KEY_GetTrg(void);

extern int UNION_ONESELF_IsPlayerAtReceptionSpot(u32 fieldMap);

u32 UNION_MSG_CheckTalkPrintEnd(UnionRoomWork *unisys);

extern void GAMESYSTEM_SetFieldMapState(struct GameSystem *gameSystem, u32 state);

void UNION_COMM_RequestShutdown(struct UnionRoomWork *work);

extern void UNION_COMM_ReleaseWorks(UnionRoomWork *work);

extern void UNION_COMM_RequestStart(struct UnionRoomWork *work);

BOOL UNION_CHARA_IsChildObjId(u16 objId);

u16 UNION_CHARA_GetBeaconIndex(u32);

int UNION_CHARA_IsUnionObjId(u16 objId);

int UNION_CHARA_CheckTalkable(UnionRoomWork *work, u16 objId);

int UNION_ONESELF_TryStartSubEvent(struct GameSystem *gameSystem, void *fieldMap);

int UNION_ONESELF_GetFieldTalkEvent(void *gameSystem, void *pos);

int UNION_ONESELF_RunPlayCategory(UnionRoomWork *work, void *fieldMap);

extern int UNION_ONESELF_SetNextPlayCategory(UnionRoomWork *unisys, int nextState);

int UNION_ONESELF_SetNextPlayCategoryInMainPhase(UnionRoomWork *work, char playCategory);

int UNION_ONESELF_GetRegulationId(int status);

int UNION_ONESELF_GetRegulationFlag(int category);

int UNION_ONESELF_IsBattleStatus(unsigned int category);

extern void *UNION_ONESELF_CreateBattleTeamParty(UnionRoomWork *unisys);

extern void UNION_ONESELF_DeleteParty(void *party);

void UNION_ONESELF_LoadRegulation(UnionRoomWork *unisys, int category);

extern int UNION_ONESELF_CheckMyParty(UnionRoomWork *work, unsigned int *violationMask);

extern int UNION_ONESELF_CheckBattleTeamParty(UnionRoomWork *work, unsigned int *violationMask);

int UNION_ONESELF_CheckEntryParties(UnionRoomWork *work, int status, unsigned int *myPartyMask, unsigned int *battleTeamMask);

extern void UNION_ONESELF_SetFieldBusy(UnionRoomWork *unisys, void *fieldMap, unsigned int busy);

extern int UNION_ONESELF_HandleNetError(UnionRoomWork *unisys);

extern int UNION_ONESELF_HandleNetErrorExit(UnionRoomWork *unisys);

int UNION_ONESELF_IdleStart(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap);

int UNION_ONESELF_IdleMain(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap);

int UNION_ONESELF_ErrorMain(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap, u8 *step);

extern UnionOneselfActionEntry gUnionOneselfActionStart[];

extern UnionOneselfActionEntry gUnionOneselfActionMain[];

extern UnionOneselfActionEntry gUnionOneselfActionEnd[];

extern const char gUnionEmptyString1[];

/*
 * extent: follower 0217B83C already has its own source and shard.
 */
int UNION_ONESELF_TryStartSubEvent(struct GameSystem *gameSystem, void *fieldMap)
{
    UnionRoomWork *work;
    UnionSubEvent *subEvent;
    int result;
    work = (UnionRoomWork *)GAME_COMM_GetWork((void *)GAMESYSTEM_GetGameComm(gameSystem));
    result = 0;
    subEvent = &work->subEvent;
    if (subEvent->id != 0 && subEvent->active == 0) result = (s32)UNION_SCENE_CreateSubEvent(gameSystem, fieldMap, work);
    return result;
}

/*
 * Unlabelled leaf (a .word after a pool in the ov019 listing): returns 0.
 * Callee of ov021 FIELD_EVENT_CHECK_CheckCommEvents, which passes (sys, pos).
 * Addresses are Black-image addresses.
 */
int UNION_ONESELF_GetFieldTalkEvent(void *gameSystem, void *pos)
{
    return 0;
}

int UNION_ONESELF_RunPlayCategory(UnionRoomWork *work, void *fieldMap)
{
    UnionMySituation *situation = (&work->mySituation);
    int result = 1;
    UnionOneselfActionFunc func;

    switch (situation->phase) {
    case 0:
        func = gUnionOneselfActionStart[situation->playCategory].func;
        break;
    case 1:
        func = gUnionOneselfActionMain[situation->playCategory].func;
        break;
    case 2:
        func = gUnionOneselfActionEnd[situation->playCategory].func;
        break;
    }
    if (func != 0) {
        result = func(work, situation, fieldMap, &situation->step);
    }
    if (result == 1) {
        situation->step = 0;
        situation->phase = situation->phase + 1;
        if (situation->phase > 2) {
            situation->phase = 0;
            situation->prevPlayCategory = situation->playCategory;
            situation->playCategory = situation->nextPlayCategory;
            situation->nextPlayCategory = 0;
        }
    }
    return situation->playCategory;
}

int UNION_ONESELF_SetNextPlayCategory(UnionRoomWork *work, int playCategory)
{
    (&work->mySituation)->nextPlayCategory = playCategory;
    return 1;
}

int UNION_ONESELF_SetNextPlayCategoryInMainPhase(UnionRoomWork *work, char playCategory)
{
    if ((&work->mySituation)->phase == 1) return UNION_ONESELF_SetNextPlayCategory(work, playCategory);
    return 0;
}

int UNION_ONESELF_GetRegulationId(int status)
{
    switch (status) {
    case 0: case 1: case 2: case 3:
        break;
    case 4: case 5:
        return 5;
    case 6: case 7:
        return 0x18;
    case 8: case 9:
        return 6;
    case 10: case 11:
        return 0x19;
    case 12: case 13:
        return 7;
    case 14: case 15:
        return 0x1a;
    case 16: case 17:
        return 8;
    case 18: case 19:
        return 0x1b;
    case 20: case 21:
        return 9;
    case 22: case 23:
        return 0x1c;
    }
    return 5;
}

int UNION_ONESELF_GetRegulationFlag(int status)
{
    switch (status) {
    case 0: case 1: case 2: case 3:
    case 5: case 7: case 9: case 11: case 13: case 15:
    case 17: case 19: case 21:
        break;
    case 4: case 6: case 8: case 10: case 12: case 14:
    case 16: case 18: case 20: case 22:
        return 1;
    }
    return 0;
}

int UNION_ONESELF_IsBattleStatus(unsigned int status)
{
    if (status < 4 || status > 23) return 0;
    return 1;
}

/*
 * Return from the legacy void tail forwarder 0200BAC8 is used by this caller.
 */
void *UNION_ONESELF_CreateBattleTeamParty(UnionRoomWork *work)
{
    void *battleTeam;
    battleTeam = BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(work->parent->gameData));
    if (BATTLE_BOX_HasMon(battleTeam) == 0) return 0;
    return BATTLE_BOX_CreateParty(battleTeam, UNION_HEAP_ID);
}

void UNION_ONESELF_DeleteParty(void *party)
{
    if (!party) GF_PANIC_Fail((char *)gUnionEmptyString1, 0, (char *)gUnionEmptyString1);
    GFL_HEAP_Free(party);
}

/*
 * Interface evidence: stub at 0201A364 moves r0 to r2, r1 to r0,
 * sets r1=0x69, then jumps through pool 02048F4C. the integrator owns it.
 */
void UNION_ONESELF_LoadRegulation(UnionRoomWork *work, int status)
{
    POKE_REGULATION_LoadInto(UNION_ONESELF_GetRegulationId(status), work->regulation);
    if (UNION_ONESELF_GetRegulationFlag(status) == 1) REGULATION_SetRuleValue(work->regulation, 13, 1);
    else REGULATION_SetRuleValue(work->regulation, 13, 0);
}

int UNION_ONESELF_CheckMyParty(UnionRoomWork *work, unsigned int *violationMask)
{
    void *party;
    *violationMask = 0;
    party = GAME_DATA_GetMyParty(work->parent->gameData);
    return POKE_REGULATION_CheckParty(work->regulation, party, violationMask);
}

int UNION_ONESELF_CheckBattleTeamParty(UnionRoomWork *work, unsigned int *violationMask)
{
    void *party;
    int result;
    party = UNION_ONESELF_CreateBattleTeamParty(work);
    *violationMask = 0;
    if (party != 0) {
        result = POKE_REGULATION_CheckParty(work->regulation, party, violationMask);
        UNION_ONESELF_DeleteParty(party);
    } else {
        *violationMask = -1;
        result = 5;
    }
    return result;
}

int UNION_ONESELF_CheckEntryParties(UnionRoomWork *work, int status, unsigned int *myPartyMask, unsigned int *battleTeamMask)
{
    int myPartyResult, battleTeamResult;
    *myPartyMask = 0;
    *battleTeamMask = 0;
    if (UNION_ONESELF_IsBattleStatus(status) == 0)
        return 1;
    UNION_ONESELF_LoadRegulation(work, status);
    myPartyResult = UNION_ONESELF_CheckMyParty(work, myPartyMask);
    battleTeamResult = UNION_ONESELF_CheckBattleTeamParty(work, battleTeamMask);
    if (myPartyResult == 0 || battleTeamResult == 0)
        return 1;
    return 0;
}

void UNION_ONESELF_SetFieldBusy(UnionRoomWork *work, void *fieldMap, unsigned int busy)
{
    work->fieldBusy = busy;
    FIELDMAP_CTRL_GRID_SetBusy(fieldMap, busy);
}

int UNION_ONESELF_HandleNetError(UnionRoomWork *work)
{
    if (GFL_NET_ERR_GetErrorLevel() != 0) {
        UNION_ONESELF_SetNextPlayCategory(work, 1);
        return 1;
    }
    return 0;
}

int UNION_ONESELF_HandleNetErrorExit(UnionRoomWork *work)
{
    if (UNION_ONESELF_HandleNetError(work) == 1) {
        UNION_ONESELF_SetNextPlayCategory(work, 50);
        return 1;
    }
    return 0;
}

int UNION_ONESELF_IdleStart(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap)
{
    UNION_COMM_InitConnectInfo(work, &situation->connect);
    UNION_COMM_SetSituationParam(work, 4, 0);
    UNION_MSG_CloseAllWindows(work);
    UNION_ONESELF_SetFieldBusy(work, fieldMap, 0);
    work->talkCancel = 0;
    return 1;
}

int UNION_ONESELF_IdleMain(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap)
{
    void *fieldPlayer;
    void *mmdlSys;
    void *mmdl;
    u16 objId;
    u16 beaconIndex;
    s16 gridX;
    s16 gridY;
    s16 gridZ;

    fieldPlayer = FIELDMAP_GetFieldPlayer(fieldMap);
    mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
    if (UNION_ONESELF_HandleNetError(work) == 1) {
        return 1;
    }
    if (UNION_COMM_IsResetting(work) == 1) {
        return 0;
    }
    if (situation->nextPlayCategory != 0) {
        return 1;
    }
    if (GFL_NET_GetNegotiationNum() > 1) {
        UNION_COMM_RequestRestart(work);
        return 0;
    }
    if (KEY_GetTrg() & 1) {
        FIELD_PLAYER_GetFrontGridPos(fieldPlayer, (short *)((&gridX)), (short *)((&gridY)), (&gridZ));
        mmdl = FLDMMDL_SysSearchGridPos(mmdlSys, gridX, gridZ, 0);
        if (mmdl == 0) {
            return 0;
        }
        objId = FLDMMDL_GetObjId(mmdl);
        if (UNION_CHARA_IsUnionObjId(objId) == 0 || UNION_CHARA_CheckTalkable(work, objId) == 0) {
            return 0;
        }
        situation->connect.requestId = objId;
        beaconIndex = UNION_CHARA_GetBeaconIndex(objId);
        UNION_COMM_SetSituationParam(work, 0, (u32)(&work->beaconPc[beaconIndex]));
        if (UNION_CHARA_IsChildObjId(objId) == 0) {
            if (work->beaconPc[beaconIndex].beacon.status == 0) {
                UNION_COMM_SetSituationParam(work, 1, (u32)(&work->beaconPc[beaconIndex]));
                UNION_ONESELF_SetNextPlayCategory(work, 5);
            } else {
                UNION_ONESELF_SetNextPlayCategory(work, 0xB);
            }
        } else {
            UNION_ONESELF_SetNextPlayCategory(work, 0xC);
        }
        UNION_ONESELF_SetFieldBusy(work, fieldMap, 1);
        return 1;
    }
    if (work->talkCancel == 1) {
        UNION_ONESELF_SetNextPlayCategory(work, 4);
        return 1;
    }
    if (UNION_ONESELF_IsPlayerAtReceptionSpot((u32)fieldMap) == 1) {
        if (work->fieldRequestArmed == 1) {
            UNION_ONESELF_SetFieldBusy(work, fieldMap, 1);
            UNION_ONESELF_SetNextPlayCategory(work, 3);
        }
    } else {
        work->fieldRequestArmed = 1;
    }
    return 0;
}

int UNION_ONESELF_ErrorMain(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap, u8 *step)
{
    switch (*step) {
    case 0:
        UNION_ONESELF_SetFieldBusy(work, fieldMap, 1);
        (*step)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(work) == 1) {
            UNION_MSG_CloseAllWindows(work);
            (*step)++;
        }
        break;
    case 2:
        if (GFL_NET_ERR_GetErrorLevel() != 0) {
            GAMESYSTEM_SetFieldMapState(work->parent->gameSystem, 1);
            return 0;
        }
        UNION_COMM_RequestShutdown(work);
        (*step)++;
        break;
    case 3:
        if (UNION_COMM_IsResetting(work) == 0)
            (*step)++;
        break;
    case 4:
        UNION_COMM_ReleaseWorks(work);
        UNION_COMM_InitConnectInfo(work, &situation->connect);
        UNION_COMM_RequestStart(work);
        (*step)++;
        break;
    case 5:
        if (UNION_COMM_IsResetting(work) == 0)
            (*step)++;
        break;
    default:
        UNION_ONESELF_SetNextPlayCategory(work, 0);
        return 1;
    }
    return 0;
}

int UNION_ONESELF_NoOpMain(void)
{
    return 1;
}

int UNION_ONESELF_FieldExitMain(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap, u8 *step)
{
    if (*step == 0) {
        work->fieldRequest = 1;
        (*step)++;
    }
    return 0;
}

/* Setup of the trade scene (0x14 bytes, scene 2). */
typedef struct UnionTradeSetup {
    int gameData;     /* 0x00 */
    int party;        /* 0x04 received party */
    u16 tradeMode;    /* 0x08 */
    u8  isEvent;      /* 0x0A */
    u8  isDemo;       /* 0x0B */
    int isComm;       /* 0x0C */
    int result;       /* 0x10 */
} UnionTradeSetup;

/* Parameter of the trade scene (0x30 bytes). */
typedef struct UnionTradeParam {
    u8  pad00[8];
    int result;               /* 0x08 */
    u8  pad0c[0x14 - 0x0c];
    int gameData;             /* 0x14 */
    int pad18;
    int party;                /* 0x1C */
    UnionTradeSetup *setup;   /* 0x20 */
} UnionTradeParam;

/* One opponent of the colosseum battle (0x0C bytes). */
typedef struct UnionBattleOpponent {
    void *party;      /* 0x68 */
    const void *myStatus;     /* 0x6C */
    u8  trainerView;  /* 0x70 */
} UnionBattleOpponent;

/* Battle setup of the colosseum battle scene (0xC4 bytes, scene 0x1A). */
typedef struct UnionBattleParam {
    void *party;                        /* 0x00 */
    void *myStatus;                     /* 0x04 */
    int pad08;
    void *config;                       /* 0x0C */
    int pad10;
    void *regulation;                   /* 0x14 */
    u8  pad18[0x34 - 0x18];
    int commMode;                       /* 0x34 */
    u8  pad38[0x60 - 0x38];
    u16 result;                         /* 0x60 */
    u8  pad62[0x64 - 0x62];
    int rule;                           /* 0x64 1 single, 2 multi */
    UnionBattleOpponent opponent[3];    /* 0x68 */
    int isComm;                         /* 0x8C */
    int recordMode;                     /* 0x90 */
    u8  pad94[0xc0 - 0x94];
    int *recordBuffer;                  /* 0xC0 */
} UnionBattleParam;

/* Parameter of the easy chat input scene (scene 0x1D, 12 bytes). */
typedef struct UnionChatInputParam {
    void *saveData;        /* 0x00 */
    int cancelled;         /* 0x04 nonzero: the player backed out */
    UnionPmsData *pms;     /* 0x08 sentence to edit */
} UnionChatInputParam;

/* Parameter of the scene 3 (8 bytes). */
typedef struct UnionSceneThreeParam {
    int pad00;
    struct GameData *gameData;   /* 0x04 */
} UnionSceneThreeParam;

/* Parameter of the scene 4 (0x18 bytes). */
typedef struct UnionSceneFourParam {
    int pad00;
    struct GameData *gameData;   /* 0x04 */
    void *party;                 /* 0x08 */
    void *saveData;              /* 0x0C */
    void *bag;                   /* 0x10 */
    int pad14;
} UnionSceneFourParam;

/* Draw parameters of G3D_SYSTEM_DrawObjectCulling (0x3C bytes). */
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);

extern void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, char *site, unsigned short tag);

extern void UNION_SCENE_RequestScene(UnionRoomWork *unisys, int sceneId, int param);

extern int UNION_SCENE_IsScenePending(UnionRoomWork *unisys);

extern void UNION_COMM_SetChatPms(UnionRoomWork *unisys, UnionPmsData *pms);

extern int  UNION_COMMAND_SendPartnerMode(int expected);

extern void GFL_NET_SetChangeoverModeWrapper(unsigned int mode, unsigned int flags, unsigned char *macAddr);

extern u32 GFL_NET_IsConnectMember(u32 index);

extern void GFL_NET_SetAcceptConnection(u32 unused, void *value);

extern void GFL_NET_SetLoginOption(u8 enable);

extern int  GFL_NET_SYSTEM_GetConnectNum(void);
struct GFLNetHandle;

extern struct GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);

extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);

int UNION_COMMAND_SendMyMac(void);
struct UnionConnectInfo;

extern void UNION_COMM_ClearPartnerSelects(struct UnionConnectInfo *connect);
struct UnionBeaconPc;

extern int UNION_COMM_AddMemberFromBeaconPc(struct UnionConnectInfo *connect, struct UnionBeaconPc *pc);
struct GFLNetHandle;

extern void GFL_NET_HANDLE_SetTimingSyncRange(struct GFLNetHandle *handle, u32 timingLow, u32 timingHigh);

extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct GFLNetHandle *handle, unsigned int timingLow, unsigned int timingHigh);

extern int UNION_COMMAND_SendMyStatus(struct UnionRoomWork *work);

extern u8 MATH_CountPopulation(u32 x);


struct GameData *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);
struct Party;

u32 POKEPARTY_GetNonEggCount(struct Party *party);

u32 POKEPARTY_GetBadEggCount(struct Party *party);

u32 POKEPARTY_GetEggCount(struct Party *party);

int UNION_COMMAND_SendPartnerSelectA(s32 select);

int UNION_COMMAND_SendPartnerSelectB(s32 select);

int UNION_CHARA_GetSexByObjId(struct UnionRoomWork *work, u16 objId);
struct TrainerCardProfile;

extern void TRCARD_SYS_BuildProfile(struct TrainerCardProfile *out, void *save, int mode, int flag, unsigned short heap);

extern void MI_CpuCopy8(const void *src, void *dst, int size);

extern u32 UNION_COMMAND_SendTrainerCard(struct UnionRoomWork *work);
struct EditWork;

extern struct EditWork *TRCARD_SYS_CreateEditWork(void *cardData, u8 *profile, u32 heapId);

extern u32 GFL_NET_IsParentAid(void);

extern void *MET_TRAINERS_GetFromSave(void *saveData);

extern u32 GFL_NET_GetHandleNetID(struct GFLNetHandle *handle);
struct MyStatus;

extern struct MyStatus *GAME_DATA_GetMyStatusPlayer(struct GameData *gd, unsigned int playerId);

extern u32 MYSTATUS_GetId(struct MyStatus *mystatus);
struct MetTrainersSave;

extern void MET_TRAINERS_Insert(struct MetTrainersSave *list, unsigned int value);

extern struct Party *POKEPARTY_Create(u32 heap);

extern void UNION_COMM_SetGameKindByStatus(unsigned int category);

extern void UNION_COMM_StartConnectSync(struct UnionRoomWork *work);

extern int GFL_NET_IsSessionNull(void);

extern void UNION_COMM_RemoveMemberOfBeaconPc(struct UnionConnectInfo *connect, struct UnionBeaconPc *pc);

extern void *GAME_DATA_GetTrainerRecord(struct GameData *gd);

extern u32 UNION_COMMAND_SendAppEntry(struct UnionRoomWork *work);
struct MyStatus;
struct ColosseumWork;

extern ColosseumWork *COLOSSEUM_Create(struct GameData *gameData, void *gameSystem, struct MyStatus *myStatus, u32 modeFlag);

extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gd);

extern int UNION_COMMAND_SendColosseumCancel(void);
struct CommEntryMenu;

extern struct CommEntryMenu *COMM_ENTRY_MENU_Create(struct MyStatus *myStatus, struct FieldMap *fieldMap, unsigned int minMembers, unsigned int maxMembers, unsigned int heapId, unsigned int menuMode, unsigned int isChild, unsigned char *mac);
struct CommEntryMenu;

extern u32 COMM_ENTRY_MENU_Delete(struct CommEntryMenu *menu);

extern void COMM_ENTRY_MENU_SetCallbacks(void *entryMenu, void *work, void *onAdd, void *onRemove);

extern u32 COMM_ENTRY_MENU_Main(struct CommEntryMenu *menu);

extern u8 MYSTATUS_GetTrainerView(struct MyStatus *mystatus);

extern int MYSTATUS_GetSex(const void *myStatus);

extern void UNION_COMM_AddMember(void *self, const u8 *mac, int gender, int trainerView);

extern void UNION_COMM_RemoveMember(struct UnionConnectInfo *connect, u8 *mac);

extern void COLOSSEUM_AddCommandTable(UnionRoomWork *unisys);

extern u32 COLOSSEUM_SendPlayerEntry(void *player, u32 flags);

extern int COLOSSEUM_SendTrainerCard(void *trainerCard);

extern void COLOSSEUM_SetStartFlag(struct ColosseumWork *work, s32 flag);

extern void COLOSSEUM_SetMyChoice(ColosseumWork *colosseum, int value);
struct CommPlayerWork;

extern int COMM_PLAYER_SearchGridPos(struct CommPlayerWork *work, int gridX, int gridY, int gridZ, int outId, int searchIndex);

extern struct Mmdl *FIELD_PLAYER_GetMmdl(struct FieldPlayer *player);

extern u32 COLOSSEUM_SendChoiceRequest(struct ColosseumWork *work);

extern u8 COLOSSEUM_GetMyChoiceReply(struct ColosseumWork *work);

extern int FLDMMDL_CheckPossibleAcmd(struct Mmdl *mmdl);

extern void FLDMMDL_SetAcmd(struct Mmdl *mmdl, unsigned short code);

extern int FLDMMDL_CheckEndAcmd(struct Mmdl *mmdl);
struct Mmdl;

extern int FLDMMDL_EndAcmd(struct Mmdl *mmdl);
struct PartySelectList;

extern struct PartySelectList *PARTY_SELECT_LIST_Create(void *owner, void *firstParty, void *secondParty, u32 sideFlagFirst, u32 sideFlagSecond, u16 heapId);

extern int PARTY_SELECT_LIST_Main(struct PartySelectList *list);

extern u32 PARTY_SELECT_LIST_Delete(struct PartySelectList *list, u32 *outFlag);

u32 COLOSSEUM_SendReady(void);

u32 COLOSSEUM_SendReadyCancel(void);

void COLOSSEUM_ResetParties(struct ColosseumWork *work, s32 keepOwn);

void COLOSSEUM_ClearConfirmCount(struct ColosseumWork *work);

int COLOSSEUM_AllPartiesReceived(struct ColosseumWork *work);

u32 COLOSSEUM_SendParty(void *party);

int COLOSSEUM_SendBattlePositions(void *positions);

void POKEPARTY_Copy(struct Party *src, struct Party *dst);

void POKE_REGULATION_AdjustPartyLevels(struct Regulation *reg, struct Party *party);

void *GAME_DATA_GetMyItem(struct GameData *gd);

void *SYSTEM_DATA_GetConfig(void *sys);

const void *MYSTATUS_GetName(const void *player);

void UNION_CHARA_ClearTable(struct UnionRoomWork *work);

int COLOSSEUM_SendFinish(void);

void UNION_COMM_ClearBeaconPcs(struct UnionRoomWork *work);

void COLOSSEUM_Delete(struct ColosseumWork *work, void *gameSystem);


u16 GFL_NET_SYSTEM_GetCurrentAid(void);

u8 MYSTATUS_GetRomCode(struct MyStatus *mystatus);
struct WordSet;

void WORDSET_SetSlotMyStatus(struct WordSet *words, u32 slot, void *source);

u16 UNION_MSG_GetNoReplyMsg(void ***ctx);

u16 UNION_MSG_GetTalkParentGreetingMsg(int sex);

u16 UNION_MSG_GetTalkParentCancelMsg(int sex);

u16 UNION_MSG_GetTalkChildBusyMsg(int sex);

u16 UNION_MSG_GetTalkParentAcceptMsg(int category, int sex);

u16 UNION_MSG_GetTalkParentRefuseMsg(int category, int sex);

u16 UNION_MSG_GetTalkChildOfferMsg(int category);

u16 UNION_MSG_GetTalkChildDeclineMsg(int category);

u16 UNION_MSG_GetTalkMenuPromptMsg(int sex);

u16 UNION_MSG_GetColosseumStartMsg(int sex);

u16 UNION_MSG_GetNotEnoughPokemonMsg(int sex);

u16 UNION_MSG_GetNoEggInPartyMsg(int sex);

u16 UNION_MSG_GetBadEggInPartyMsg(void ***ctx);

u16 UNION_MSG_GetBadEggNoticeMsg(void ***ctx);

u16 UNION_MSG_GetBattleChatMsg(int sex);

u16 UNION_MSG_GetPartnerBusyMsg(int sex);

u16 UNION_MSG_GetTrainerCardChatMsg(int sex);

u16 UNION_MSG_GetDrawChatMsg(int sex);

u16 UNION_MSG_GetTradeChatMsg(int sex);

u16 UNION_MSG_GetSpinTradeChatMsg(int sex);

u16 UNION_MSG_GetMultiBattleInviteMsg(int sex);

u16 UNION_MSG_GetSpinTradeInviteMsg(int sex);

u16 UNION_MSG_GetDrawInviteMsg(int sex);

u16 UNION_MSG_GetMultiBattleInviteDeclinedMsg(int sex);

u16 UNION_MSG_GetSpinTradeInviteDeclinedMsg(int sex);

u16 UNION_MSG_GetDrawInviteDeclinedMsg(int sex);

u16 UNION_MSG_GetSpinTradeNoEggMsg(int sex);

u16 UNION_MSG_GetSpinTradeBadEggMsg(int sex);

u16 UNION_MSG_GetSpinTradeWaitMsg(int sex);

u16 UNION_MSG_GetSpinTradeStartMsg(int sex);

u16 UNION_MSG_GetSpinTradeBusyMsg(int sex);

u16 UNION_MSG_GetDrawWaitMsg(int sex);

u16 UNION_MSG_GetDrawStartMsg(int sex);

u16 UNION_MSG_GetDrawBusyMsg(int sex);

u16 UNION_MSG_GetMultiBattleWaitMsg(int sex);

u16 UNION_MSG_GetMultiBattleStartMsg(int sex);

u16 UNION_MSG_GetMultiBattleBusyMsg(int sex);

int UNION_MSG_CheckLanguageVersion(UnionRoomWork *unisys, int nation, int area);

int UNION_MSG_GetCategoryTableValue(int category);

void UNION_MSG_SetupTalkWindow(UnionRoomWork *unisys, u8 *fieldMap);

void UNION_MSG_PrintTalkMsg(UnionRoomWork *unisys, u32 messageId);

void UNION_MSG_SetupPrintTalkMsg(UnionRoomWork *unisys, u8 *fieldMap, u32 messageId);

void UNION_MSG_SetupYesNo(UnionRoomWork *unisys, u32 fieldMap);

void UNION_MSG_DeleteYesNo(UnionRoomWork *unisys);

int UNION_MSG_SelectYesNo(UnionRoomWork *unisys, u32 *out);

void UNION_MSG_SetupMainMenu(UnionRoomWork *unisys, u32 fieldMap);

void UNION_MSG_DeleteMainMenu(UnionRoomWork *unisys);

int UNION_MSG_SelectMainMenu(UnionRoomWork *unisys, int fieldMap);

void UNION_MSG_SetupSubMenu(UnionRoomWork *unisys, int fieldMap, int menuId, u8 *outArg);

void UNION_MSG_DeleteSubMenu(UnionRoomWork *unisys);

int UNION_MSG_SelectSubMenu(UnionRoomWork *unisys, int *enteredSubmenu, u8 *arg, int *showHelp, u32 fieldMap);

void UNION_MSG_SetupTitleWindow(UnionRoomWork *unisys, u32 fieldMap);

void UNION_MSG_DeleteTitleWindow(UnionRoomWork *unisys);

void UNION_MSG_SetupRegulationWindow(UnionRoomWork *unisys, u32 fieldMap, u32 failMask, int ruleId, int stage);

u32 UNION_MSG_CheckRegulationPrintEnd(UnionRoomWork *unisys, u32 fieldMap);

void UNION_MSG_DeleteRegulationWindow(UnionRoomWork *unisys);

int COLOSSEUM_CheckAllEntered(ColosseumWork *colosseum);

int COLOSSEUM_CheckAllTrainerCardsReceived(ColosseumWork *colosseum);

int COLOSSEUM_IsPositionsReceived(ColosseumWork *colosseum);

void COLOSSEUM_ClearPositionsReceived(ColosseumWork *colosseum);

int COLOSSEUM_IsOnStandPos(int a, int mode, unsigned int *out);

int COLOSSEUM_CheckAllFinished(ColosseumWork *colosseum);

int COLOSSEUM_IsAnyFinished(ColosseumWork *colosseum);

int COLOSSEUM_IsOnCounterPos(void *a);

extern int d_021807E8[];


int UNION_ONESELF_ChatInputMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ConnectParentStart(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap);

int UNION_ONESELF_ConnectParentMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ConnectParentEnd(UnionRoomWork *unisys);

int UNION_ONESELF_ConnectChildStart(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap);

int UNION_ONESELF_ConnectChildMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ConnectChildEnd(UnionRoomWork *unisys);

int UNION_ONESELF_TalkParentStart(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_TalkParentMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_TalkParentEnd(UnionRoomWork *unisys);

int UNION_ONESELF_TalkParentAnswerWaitMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_TalkChildStart(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_TalkChildMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_TalkChildEnd(void);

int UNION_ONESELF_BattleMenuMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_TalkPlayingMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_TalkPlayingChildMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_TrainerCardMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_TradeMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_JoinMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ConnectGroupMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_AppMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ColosseumEnterParentMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ColosseumEnterChildMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ColosseumEntryMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

void UNION_ONESELF_EntryMenuAddMember(UnionRoomWork *unisys, const void *myStatus, const u8 *mac);

void UNION_ONESELF_EntryMenuRemoveMember(UnionRoomWork *unisys, const void *myStatus, const u8 *mac);

int UNION_ONESELF_ColosseumSetupMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ColosseumFreeMoveStart(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap);

int UNION_ONESELF_ColosseumFreeMoveMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ColosseumStandPosMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ColosseumLeavePosMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ColosseumPartySelectMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ColosseumReadyWaitMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ColosseumPartyExchangeMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ColosseumBattleMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ColosseumLeaveConfirmMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ColosseumExitMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ColosseumTrainerCardMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int UNION_ONESELF_ChatInputMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    UnionChatInputParam *param;
    UnionChatInputParam *finished;
    UnionPmsData *sentence;
    int cancelled;
    switch (*seq) {
    case 0:
        if (unisys->talkCancel == 0)
            return 1;
        unisys->talkCancel = 0;
        GFL_USE_PlaySeDefaultVolume(0x54B);
        param = GFL_HEAP_Alloc(4, 12, 1, (char *)d_021807E8, 0x41A);
        param->saveData = GAME_DATA_GetSaveControl(unisys->parent->gameData);
        unisys->sceneParam = param;
        UNION_SCENE_RequestScene(unisys, 0x1d, (int)param);
        (*seq)++;
        break;
    case 1:
        if (UNION_SCENE_IsScenePending(unisys) == 0)
            (*seq)++;
        break;
    case 2:
        finished = ((UnionChatInputParam *)unisys->sceneParam);
        sentence = finished->pms;
        cancelled = finished->cancelled;
        if (cancelled == 0)
            UNION_COMM_SetChatPms(unisys, sentence);
        GFL_HEAP_Free(((UnionChatInputParam *)unisys->sceneParam));
        unisys->sceneParam = 0;
        return 1;
    }
    return 0;
}

int UNION_ONESELF_ConnectParentStart(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap)
{
    GFL_USE_PlaySeDefaultVolume(0x547);
    UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 0xE2);
    return 1;
}

/*
 * Addresses are Black-image addresses.
 */
int UNION_ONESELF_ConnectParentMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    int slot;

    if (UNION_ONESELF_HandleNetError(unisys) == 1) {
        return 1;
    }
    switch (*seq) {
    case 0:
        GFL_NET_SetChangeoverModeWrapper(1, 1, 0);
        situation->waitTimer = 0;
        (*seq)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 0) {
            break;
        }
        if (GFL_NET_GetNegotiationNum() > 1) {
            for (slot = 2; slot < 5; slot++) {
                if ((int)GFL_NET_IsConnectMember((u8)slot) == 1) {
                    break;
                }
            }
            if (slot < 5 || GFL_NET_SYSTEM_GetConnectNum() > 2) {
                UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetNoReplyMsg((void ***)unisys));
                UNION_ONESELF_SetNextPlayCategory(unisys, 0);
                UNION_COMM_RequestRestart(unisys);
                *seq = 4;
            } else {
                GFL_NET_SetLoginOption(1);
                GFL_NET_SetAcceptConnection((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0);
                *seq = 2;
            }
        } else {
            situation->waitTimer++;
            if (situation->waitTimer > 600 || (KEY_GetTrg() & 2)) {
                UNION_COMM_RequestRestart(unisys);
                UNION_ONESELF_SetNextPlayCategory(unisys, 0);
                UNION_COMM_SetSituationParam(unisys, 1, 0);
                if (situation->waitTimer > 600) {
                    UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetNoReplyMsg((void ***)unisys));
                } else {
                    UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 10);
                }
                *seq = 5;
            }
        }
        break;
    case 2:
        if (situation->connect.partnerMac.enabled == 1) {
            if (GF_STANDARD_CompareBytes(situation->connect.partnerMac.mac, situation->connect.talkPc->mac, 6) != 0) {
                if (UNION_COMMAND_SendPartnerMode(2) == 1) {
                    GFL_NET_SetLoginOption(0);
                    *seq = 6;
                }
            } else {
                if (UNION_COMMAND_SendPartnerMode(1) == 1) {
                    GFL_USE_PlaySeDefaultVolume(0x806);
                    UNION_ONESELF_SetNextPlayCategory(unisys, 7);
                    UNION_COMM_SetSituationParam(unisys, 3, (u32)situation->connect.talkPc);
                    UNION_COMM_SetSituationParam(unisys, 1, 0);
                    *seq = 3;
                }
            }
        }
        break;
    case 3:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1) {
            return 1;
        }
        break;
    case 4:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1 && (KEY_GetTrg() & 0xF3)) {
            return 1;
        }
        break;
    case 5:
        if (UNION_COMM_IsResetting(unisys) == 0) {
            *seq = 4;
        }
        break;
    case 6:
        if (GFL_NET_SYSTEM_GetConnectNum() <= 1) {
            UNION_COMM_RequestRestart(unisys);
            (*seq)++;
        }
        break;
    case 7:
        if (UNION_COMM_IsResetting(unisys) == 0) {
            situation->connect.partnerMac.enabled = 0;
            *seq = 0;
        }
        break;
    }
    return 0;
}

/*
 * Remaining two bytes are alignment padding.
 */
int UNION_ONESELF_ConnectParentEnd(UnionRoomWork *unisys)
{
    UNION_COMM_SetSituationParam(unisys, 1, 0);
    return 1;
}

int UNION_ONESELF_ConnectChildStart(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap)
{
    GFL_USE_PlaySeDefaultVolume(0x806);
    UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 7);
    UNION_ONESELF_SetFieldBusy(unisys, fieldMap, 1);
    return 1;
}

int UNION_ONESELF_ConnectChildMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    if (UNION_ONESELF_HandleNetError(unisys) == 1)
        return 1;

    switch (*seq) {
    case 0:
        if (situation->connect.connectParam == 0)
            GF_PANIC_Fail((char *)gUnionEmptyString1, 0, (char *)gUnionEmptyString1);
        GFL_NET_SetChangeoverModeWrapper(2, 1, situation->connect.connectParam->mac);
        situation->waitTimer = 0;
        *seq = 1;
        break;
    case 1:
        if (GFL_NET_GetNegotiationNum() > 1) {
            GFL_NET_SetLoginOption(1);
            *seq = 3;
            break;
        }
        situation->waitTimer++;
        if (situation->waitTimer > 600 || (KEY_GetTrg() & 2)) {
            UNION_COMM_RequestRestart(unisys);
            UNION_ONESELF_SetNextPlayCategory(unisys, 0);
            UNION_COMM_SetSituationParam(unisys, 2, 0);
            if (situation->waitTimer > 600)
                UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 8);
            else
                UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 10);
            *seq = 2;
        }
        break;
    case 2:
        if (UNION_COMM_IsResetting(unisys) == 0 && UNION_MSG_CheckTalkPrintEnd(unisys) == 1 && (KEY_GetTrg() & 0xf3))
            return 1;
        break;
    case 3:
        if (UNION_COMMAND_SendMyMac() == 1)
            *seq = 4;
        break;
    case 4:
        switch (situation->connect.partnerMode) {
        case 1:
            UNION_COMM_SetSituationParam(unisys, 3, (u32)situation->connect.connectParam);
            UNION_COMM_SetSituationParam(unisys, 2, 0);
            UNION_ONESELF_SetNextPlayCategory(unisys, 9);
            return 1;
        case 2:
            UNION_COMM_SetSituationParam(unisys, 2, 0);
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 8);
            UNION_COMM_RequestRestart(unisys);
            *seq = 5;
            break;
        }
        break;
    case 5:
        if (UNION_COMM_IsResetting(unisys) == 0 && UNION_MSG_CheckTalkPrintEnd(unisys) == 1 && (KEY_GetTrg() & 0xf3)) {
            UNION_ONESELF_SetNextPlayCategory(unisys, 0);
            return 1;
        }
        break;
    }
    return 0;
}

int UNION_ONESELF_ConnectChildEnd(UnionRoomWork *unisys)
{
    UNION_COMM_SetSituationParam(unisys, 2, 0);
    return 1;
}

int UNION_ONESELF_TalkParentStart(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    void *commLink;
    if (UNION_ONESELF_HandleNetError(unisys) == 1)
        return 1;
    if (situation->prevPlayCategory == 10) {
        situation->subState = 1;
        return 1;
    }
    situation->subState = 0;
    switch (*seq) {
    case 0:
        UNION_COMM_ClearPartnerSelects(&situation->connect);
        UNION_COMM_SetSituationParam(unisys, 4, 1);
        UNION_COMM_AddMemberFromBeaconPc(&situation->connect, (situation->connect.connectPc));
        commLink = GFL_NET_HANDLE_GetCurrentHandle();
        GFL_NET_HANDLE_SetTimingSyncRange(commLink, 2, 0x14);
        (*seq)++;
        break;
    case 1:
        commLink = GFL_NET_HANDLE_GetCurrentHandle();
        if (GFL_NET_HANDLE_IsTimingSyncRange(commLink, 2, 0x14) == 1)
            (*seq)++;
        break;
    case 2:
        if (UNION_COMMAND_SendMyStatus(unisys) == 1)
            (*seq)++;
        break;
    case 3:
        if (MATH_CountPopulation(situation->connect.myStatusRecvBits) > 1)
            return 1;
        break;
    }
    return 0;
}

int UNION_ONESELF_TalkParentMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    void *party;
    int menuResult;

    if (UNION_ONESELF_HandleNetError(unisys) == 1)
        return 1;

    switch (*seq) {
    case 0:
        if (situation->subState == 1) {
            situation->subState = 0;
        } else if (situation->connect.talkCount == 0) {
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetTalkParentGreetingMsg(situation->connect.talkParam->sex));
            situation->connect.talkCount++;
        } else {
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetTalkMenuPromptMsg(situation->connect.talkParam->sex));
        }
        (*seq)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1)
            (*seq)++;
        break;
    case 2:
        UNION_MSG_SetupMainMenu(unisys, (u32)fieldMap);
        (*seq)++;
        break;
    case 3:
        party = GAME_DATA_GetMyParty(unisys->parent->gameData);
        menuResult = UNION_MSG_SelectMainMenu(unisys, (int)fieldMap);
        if (menuResult == -1)
            break;
        UNION_MSG_DeleteMainMenu(unisys);
        if (menuResult == -2 || menuResult == 0) {
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetTalkParentCancelMsg(situation->connect.talkParam->sex));
            situation->connect.partnerSelectA = 0;
            UNION_ONESELF_SetNextPlayCategory(unisys, 8);
            return 1;
        }
        if (menuResult == 0x18) {
            GAMESYSTEM_GetGameData(unisys->parent->gameSystem);
            if ((int)POKEPARTY_GetNonEggCount(party) < 2) {
                UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetNotEnoughPokemonMsg(situation->connect.talkParam->sex));
                *seq = 4;
                break;
            }
        } else if (menuResult == 0x19) {
            if ((int)POKEPARTY_GetBadEggCount(party) > 0) {
                UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetBadEggInPartyMsg((void ***)unisys));
                *seq = 4;
                break;
            } else if (POKEPARTY_GetEggCount(party) == 0) {
                UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetNoEggInPartyMsg(situation->connect.talkParam->sex));
                *seq = 4;
                break;
            }
        }
        if (menuResult == 0x1b) {
            UNION_ONESELF_SetNextPlayCategory(unisys, 10);
            return 1;
        }
        situation->connect.partnerSelectA = menuResult;
        UNION_ONESELF_SetNextPlayCategory(unisys, 8);
        return 1;
    case 4:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1)
            *seq = 0;
        break;
    }
    return 0;
}

int UNION_ONESELF_TalkParentEnd(UnionRoomWork *unisys)
{
    UNION_MSG_DeleteMainMenu(unisys);
    return 1;
}

int UNION_ONESELF_TalkParentAnswerWaitMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    if (UNION_ONESELF_HandleNetError(unisys) == 1)
        return 1;

    switch (*seq) {
    case 0:
        if (UNION_COMMAND_SendPartnerSelectA(situation->connect.partnerSelectA) == 1) {
            if (situation->connect.partnerSelectA == 0) {
                UNION_ONESELF_SetNextPlayCategory(unisys, 0x27);
                return 1;
            }
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetTalkParentAcceptMsg(situation->connect.partnerSelectA, situation->connect.talkParam->sex));
            (*seq)++;
        }
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) != 0) {
            if (situation->connect.partnerSelectB == 1) {
                UNION_ONESELF_SetNextPlayCategory(unisys, situation->connect.partnerSelectA + 11);
                (*seq)++;
            } else if (situation->connect.partnerSelectB == 0) {
                UNION_ONESELF_SetNextPlayCategory(unisys, 0x27);
                UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetTalkParentRefuseMsg(situation->connect.partnerSelectA, situation->connect.talkParam->sex));
                return 1;
            }
        }
        break;
    case 2:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1)
            return 1;
        break;
    }
    return 0;
}

int UNION_ONESELF_TalkChildStart(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    void *commLink;
    if (UNION_ONESELF_HandleNetError(unisys) == 1)
        return 1;
    switch (*seq) {
    case 0:
        UNION_COMM_ClearPartnerSelects(&situation->connect);
        UNION_COMM_SetSituationParam(unisys, 4, 1);
        UNION_COMM_AddMemberFromBeaconPc(&situation->connect, (situation->connect.connectPc));
        commLink = GFL_NET_HANDLE_GetCurrentHandle();
        GFL_NET_HANDLE_SetTimingSyncRange(commLink, 2, 0x14);
        (*seq)++;
        break;
    case 1:
        commLink = GFL_NET_HANDLE_GetCurrentHandle();
        if (GFL_NET_HANDLE_IsTimingSyncRange(commLink, 2, 0x14) == 1)
            (*seq)++;
        break;
    case 2:
        if (UNION_COMMAND_SendMyStatus(unisys) == 1)
            (*seq)++;
        break;
    case 3:
        if (MATH_CountPopulation(situation->connect.myStatusRecvBits) > 1)
            return 1;
        break;
    }
    return 0;
}

int UNION_ONESELF_TalkChildMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    int accepted;
    void *party;

    if (UNION_ONESELF_HandleNetError(unisys) == 1)
        return 1;
    if (UNION_MSG_CheckTalkPrintEnd(unisys) == 0)
        return 0;

    switch (*seq) {
    case 0:
        UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 9);
        (*seq)++;
        break;
    case 1:
        if (situation->connect.partnerSelectA == 0xff)
            break;
        if (situation->connect.partnerSelectA == 0) {
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetTalkChildBusyMsg(situation->connect.talkParam->sex));
            UNION_ONESELF_SetNextPlayCategory(unisys, 0x27);
            return 1;
        }
        if (situation->connect.partnerSelectA < 0x1b) {
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetTalkChildOfferMsg(situation->connect.partnerSelectA));
            if (UNION_ONESELF_IsBattleStatus(situation->connect.partnerSelectA) == 1) {
                UNION_ONESELF_LoadRegulation(unisys, situation->connect.partnerSelectA);
                UNION_MSG_SetupRegulationWindow(unisys, (u32)fieldMap, 0, UNION_ONESELF_GetRegulationFlag(situation->connect.partnerSelectA), 0);
                *seq = 2;
            } else {
                *seq = 3;
            }
        } else if (UNION_COMMAND_SendPartnerSelectB(0) == 1) {
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 0x13d);
            UNION_ONESELF_SetNextPlayCategory(unisys, 0x27);
            return 1;
        }
        break;
    case 2:
        if (UNION_MSG_CheckRegulationPrintEnd(unisys, (u32)fieldMap) == 1)
            *seq = 3;
        break;
    case 3:
        UNION_MSG_DeleteRegulationWindow(unisys);
        UNION_MSG_SetupYesNo(unisys, (u32)fieldMap);
        (*seq)++;
        break;
    case 4:
        situation->subState = 0;
        if (UNION_MSG_SelectYesNo(unisys, (u32 *)(&accepted)) != 1)
            break;
        party = GAME_DATA_GetMyParty(unisys->parent->gameData);
        UNION_MSG_DeleteYesNo(unisys);
        if (UNION_ONESELF_CheckEntryParties(unisys, situation->connect.partnerSelectA, &situation->partyFailMask, &situation->teamFailMask) == 0) {
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 0x13e);
            accepted = 0;
        } else if (situation->connect.partnerSelectA == 0x18 && accepted == 1) {
            GAMESYSTEM_GetGameData(unisys->parent->gameSystem);
            if ((int)POKEPARTY_GetNonEggCount(party) < 2) {
                accepted = 0;
                situation->subState = 1;
            }
        } else if (situation->connect.partnerSelectA == 0x19 && accepted == 1) {
            if ((int)POKEPARTY_GetBadEggCount(party) > 0) {
                accepted = 0;
                situation->subState = 3;
            } else if (POKEPARTY_GetEggCount(party) == 0) {
                accepted = 0;
                situation->subState = 2;
            }
        }
        situation->connect.partnerSelectB = accepted;
        (*seq)++;
        break;
    case 5:
        if (UNION_COMMAND_SendPartnerSelectB(situation->connect.partnerSelectB) == 1) {
            if (situation->partyFailMask != 0 && situation->teamFailMask != 0)
                *seq = 6;
            else
                *seq = 10;
        }
        break;
    case 6:
        UNION_MSG_SetupRegulationWindow(unisys, (u32)fieldMap, situation->partyFailMask, UNION_ONESELF_GetRegulationFlag(situation->connect.partnerSelectA), 1);
        (*seq)++;
        break;
    case 7:
        if (UNION_MSG_CheckRegulationPrintEnd(unisys, (u32)fieldMap) == 1 && (KEY_GetTrg() & 3)) {
            UNION_MSG_DeleteRegulationWindow(unisys);
            if (situation->teamFailMask == -1)
                *seq = 10;
            else
                (*seq)++;
        }
        break;
    case 8:
        UNION_MSG_SetupRegulationWindow(unisys, (u32)fieldMap, situation->partyFailMask, UNION_ONESELF_GetRegulationFlag(situation->connect.partnerSelectA), 2);
        (*seq)++;
        break;
    case 9:
        if (UNION_MSG_CheckRegulationPrintEnd(unisys, (u32)fieldMap) == 1 && (KEY_GetTrg() & 3)) {
            UNION_MSG_DeleteRegulationWindow(unisys);
            *seq = 10;
        }
        break;
    case 10:
        if (situation->connect.partnerSelectB == 0) {
            if (situation->subState == 1)
                UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 0x28);
            else if (situation->subState == 2)
                UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 0x2f);
            else if (situation->subState == 3)
                UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetBadEggNoticeMsg((void ***)unisys));
            else
                UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetTalkChildDeclineMsg(situation->connect.partnerSelectA));
            UNION_ONESELF_SetNextPlayCategory(unisys, 0x27);
            return 1;
        }
        UNION_ONESELF_SetNextPlayCategory(unisys, situation->connect.partnerSelectA + 11);
        *seq = 11;
        break;
    case 11:
        return 1;
    }
    return 0;
}

int UNION_ONESELF_TalkChildEnd(void)
{
    return 1;
}

int UNION_ONESELF_BattleMenuMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    int enteredSubmenu;
    int showHelp;
    int choice;

    if (UNION_ONESELF_HandleNetError(unisys) == 1)
        return 1;
    if (UNION_MSG_CheckTalkPrintEnd(unisys) == 0)
        return 0;

    switch (*seq) {
    case 0:
        situation->subState = 0;
        (*seq)++;
        break;
    case 1:
        if (situation->subState == 5)
            UNION_MSG_SetupTitleWindow(unisys, (u32)fieldMap);
        else if (situation->subState == 0)
            UNION_MSG_DeleteTitleWindow(unisys);
        UNION_MSG_SetupSubMenu(unisys, (int)fieldMap, situation->subState, (u8 *)(&situation->subMenuArg));
        (*seq)++;
        break;
    case 2:
        choice = UNION_MSG_SelectSubMenu(unisys, &enteredSubmenu, (u8 *)(&situation->subMenuArg), &showHelp, (u32)fieldMap);
        if (enteredSubmenu == 1) {
            situation->subState = choice;
            UNION_MSG_DeleteSubMenu(unisys);
            (*seq)--;
        } else if (choice == -2 || choice == 0) {
            UNION_MSG_DeleteSubMenu(unisys);
            if (situation->subState > 0) {
                situation->subState = 0;
                (*seq)--;
            } else {
                UNION_MSG_DeleteTitleWindow(unisys);
                UNION_ONESELF_SetNextPlayCategory(unisys, 7);
                return 1;
            }
        } else if (showHelp == 1) {
            UNION_MSG_DeleteTitleWindow(unisys);
            UNION_MSG_DeleteSubMenu(unisys);
            UNION_ONESELF_LoadRegulation(unisys, choice);
            situation->connect.partnerSelectA = choice;
            *seq = 3;
        } else if (choice != -1) {
            UNION_MSG_DeleteTitleWindow(unisys);
            UNION_MSG_DeleteSubMenu(unisys);
            if (UNION_ONESELF_CheckEntryParties(unisys, choice, &situation->partyFailMask, &situation->teamFailMask) == 0) {
                UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 0x13e);
                *seq = 5;
            } else {
                situation->connect.partnerSelectA = choice;
                UNION_ONESELF_SetNextPlayCategory(unisys, 8);
                return 1;
            }
        }
        break;
    case 3:
        UNION_MSG_SetupRegulationWindow(unisys, (u32)fieldMap, 0, UNION_ONESELF_GetRegulationFlag(situation->connect.partnerSelectA), 0);
        (*seq)++;
        break;
    case 4:
        if (UNION_MSG_CheckRegulationPrintEnd(unisys, (u32)fieldMap) == 1 && (KEY_GetTrg() & 3)) {
            UNION_MSG_DeleteRegulationWindow(unisys);
            *seq = 1;
        }
        break;
    case 5:
        UNION_MSG_SetupRegulationWindow(unisys, (u32)fieldMap, situation->partyFailMask, UNION_ONESELF_GetRegulationFlag(situation->connect.partnerSelectA), 1);
        (*seq)++;
        break;
    case 6:
        if (UNION_MSG_CheckRegulationPrintEnd(unisys, (u32)fieldMap) == 1 && (KEY_GetTrg() & 3)) {
            UNION_MSG_DeleteRegulationWindow(unisys);
            if (situation->teamFailMask == -1)
                *seq = 9;
            else
                (*seq)++;
        }
        break;
    case 7:
        UNION_MSG_SetupRegulationWindow(unisys, (u32)fieldMap, situation->partyFailMask, UNION_ONESELF_GetRegulationFlag(situation->connect.partnerSelectA), 2);
        (*seq)++;
        break;
    case 8:
        if (UNION_MSG_CheckRegulationPrintEnd(unisys, (u32)fieldMap) == 1 && (KEY_GetTrg() & 3)) {
            UNION_MSG_DeleteRegulationWindow(unisys);
            *seq = 9;
        }
        break;
    case 9:
        UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetTalkMenuPromptMsg(situation->connect.talkParam->sex));
        *seq = 0;
        break;
    }
    return 0;
}

int UNION_ONESELF_TalkPlayingMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    int beaconIndex, partnerStatus;
    u32 firstAnswer, secondAnswer;
    void *party;
    beaconIndex = UNION_CHARA_GetBeaconIndex(situation->connect.requestId);
    partnerStatus = unisys->beaconPc[beaconIndex].beacon.status;
    switch (*seq) {
    case 0:
        situation->connect.partnerSelectA = partnerStatus;
        switch (partnerStatus) {
        case 1: UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetPartnerBusyMsg(situation->connect.talkParam->sex)); UNION_ONESELF_SetNextPlayCategory(unisys, 0); *seq=2; goto done;
        case 2: UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetTrainerCardChatMsg(situation->connect.talkParam->sex)); UNION_ONESELF_SetNextPlayCategory(unisys, 0); *seq=2; goto done;
        case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
        case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
            UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetBattleChatMsg(situation->connect.talkParam->sex)); UNION_ONESELF_SetNextPlayCategory(unisys, 0); *seq=2; goto done;
        case 20: case 21: case 22: case 23:
            if ((int)unisys->beaconPc[beaconIndex].beacon.connectNum < UNION_MSG_GetCategoryTableValue(partnerStatus)) {
                UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetMultiBattleInviteMsg(situation->connect.talkParam->sex));
                UNION_ONESELF_LoadRegulation(unisys,partnerStatus);
                UNION_MSG_SetupRegulationWindow(unisys,(int)fieldMap,(int)0,UNION_ONESELF_GetRegulationFlag(partnerStatus),0);
                *seq = 3;
                goto done;
            }
            UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetBattleChatMsg(situation->connect.talkParam->sex));
            UNION_ONESELF_SetNextPlayCategory(unisys, 0); *seq=2; goto done;
        case 25:
            if ((int)unisys->beaconPc[beaconIndex].beacon.connectNum < UNION_MSG_GetCategoryTableValue(partnerStatus) &&
                unisys->beaconPc[beaconIndex].beacon.appActive == 0) {
                UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetSpinTradeInviteMsg(situation->connect.talkParam->sex));
                *seq = 10;
                goto done;
            }
            UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetSpinTradeChatMsg(situation->connect.talkParam->sex)); UNION_ONESELF_SetNextPlayCategory(unisys, 0); *seq=2; goto done;
        case 3:
            if ((int)unisys->beaconPc[beaconIndex].beacon.connectNum < UNION_MSG_GetCategoryTableValue(partnerStatus)) {
                UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetDrawInviteMsg(situation->connect.talkParam->sex));
                *seq = 10;
                goto done;
            }
            UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetDrawChatMsg(situation->connect.talkParam->sex)); UNION_ONESELF_SetNextPlayCategory(unisys, 0); *seq=2; goto done;
        case 24: UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetTradeChatMsg(situation->connect.talkParam->sex)); UNION_ONESELF_SetNextPlayCategory(unisys, 0); *seq=2; goto done;
        case 0: default: UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,0x151); UNION_ONESELF_SetNextPlayCategory(unisys, 0); *seq=2; goto done;
        }
        break;
    case 2:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1 && (KEY_GetTrg() & 0xf3)) return 1;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1) return 1;
        break;
    case 3:
        if (UNION_MSG_CheckRegulationPrintEnd(unisys,(u32)fieldMap) == 1) *seq = 4;
        break;
    case 4:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1) {
            UNION_MSG_DeleteRegulationWindow(unisys); UNION_MSG_SetupYesNo(unisys,(u32)fieldMap); (*seq)++;
        }
        break;
    case 5:
        if (UNION_MSG_SelectYesNo(unisys,&firstAnswer) == 1) {
            UNION_MSG_DeleteYesNo(unisys);
            if (firstAnswer == 0) {
                UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetMultiBattleInviteDeclinedMsg(situation->connect.talkParam->sex));
                UNION_ONESELF_SetNextPlayCategory(unisys, 0); *seq = 2;
            } else if (UNION_ONESELF_CheckEntryParties(unisys,situation->connect.partnerSelectA,&situation->partyFailMask,&situation->teamFailMask) == 0) {
                UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,0x13e); UNION_ONESELF_SetNextPlayCategory(unisys, 0); *seq = 6;
            } else {
                situation->connect.partnerSelectB = firstAnswer; UNION_ONESELF_SetNextPlayCategory(unisys, 0x26);
                UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetMultiBattleWaitMsg(situation->connect.talkParam->sex)); *seq = 1;
            }
        }
        break;
    case 6:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1) return 1;
        UNION_MSG_SetupRegulationWindow(unisys,(int)fieldMap,(int)situation->partyFailMask,UNION_ONESELF_GetRegulationFlag(situation->connect.partnerSelectA),1); (*seq)++;
        break;
    case 7:
        if (UNION_MSG_CheckRegulationPrintEnd(unisys,(u32)fieldMap) == 1 && (KEY_GetTrg() & 3)) {
            UNION_MSG_DeleteRegulationWindow(unisys);
            if (situation->teamFailMask == -1) *seq = 1; else (*seq)++;
        }
        break;
    case 8:
        UNION_MSG_SetupRegulationWindow(unisys,(int)fieldMap,(int)situation->partyFailMask,UNION_ONESELF_GetRegulationFlag(situation->connect.partnerSelectA),2); (*seq)++;
        break;
    case 9:
        if (UNION_MSG_CheckRegulationPrintEnd(unisys,(u32)fieldMap) == 1 && (KEY_GetTrg() & 3)) {
            UNION_MSG_DeleteRegulationWindow(unisys); *seq = 1;
        }
        break;
    case 10:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1) {
            UNION_MSG_SetupYesNo(unisys,(u32)fieldMap); (*seq)++;
        }
        break;
    case 11:
        if (UNION_MSG_SelectYesNo(unisys,&secondAnswer) == 1) {
            UNION_MSG_DeleteYesNo(unisys);
            if (secondAnswer == 0) {
                switch (situation->connect.partnerSelectA) {
                case 3: UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetDrawInviteDeclinedMsg(situation->connect.talkParam->sex)); break;
                case 25: UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetSpinTradeInviteDeclinedMsg(situation->connect.talkParam->sex)); break;
                }
                UNION_ONESELF_SetNextPlayCategory(unisys, 0); *seq = 2;
            } else {
                situation->connect.partnerSelectB = secondAnswer; UNION_ONESELF_SetNextPlayCategory(unisys, 0x26); *seq = 1;
                switch (situation->connect.partnerSelectA) {
                case 3: UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetDrawWaitMsg(situation->connect.talkParam->sex)); break;
                case 25:
                    party = GAME_DATA_GetMyParty(unisys->parent->gameData);
                    if ((int)POKEPARTY_GetBadEggCount(party) > 0) {
                        UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetSpinTradeBadEggMsg(situation->connect.talkParam->sex));
                        UNION_ONESELF_SetNextPlayCategory(unisys, 0); *seq = 2;
                    } else if (POKEPARTY_GetEggCount(party) == 0) {
                        UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetSpinTradeNoEggMsg(situation->connect.talkParam->sex));
                        UNION_ONESELF_SetNextPlayCategory(unisys, 0); *seq = 2;
                    } else UNION_MSG_SetupPrintTalkMsg(unisys,fieldMap,UNION_MSG_GetSpinTradeWaitMsg(situation->connect.talkParam->sex));
                    break;
                }
            }
        }
        break;
    }
done:
    return 0;
}

int UNION_ONESELF_TalkPlayingChildMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    int partnerSex;

    switch (*seq) {
    case 0:
        partnerSex = UNION_CHARA_GetSexByObjId(unisys, situation->connect.requestId);
        switch (unisys->beaconPc[UNION_CHARA_GetBeaconIndex(situation->connect.requestId)].beacon.status) {
        case 1:
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetPartnerBusyMsg(partnerSex));
            break;
        case 2:
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetTrainerCardChatMsg(partnerSex));
            break;
        case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
        case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
        case 20: case 21: case 22: case 23:
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetBattleChatMsg(partnerSex));
            break;
        case 25:
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetSpinTradeChatMsg(partnerSex));
            break;
        case 3:
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetDrawChatMsg(partnerSex));
            break;
        case 24:
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetTradeChatMsg(partnerSex));
            break;
        case 0:
        default:
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 0x151);
            break;
        }
        UNION_ONESELF_SetNextPlayCategory(unisys, 0);
        (*seq)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1 && (KEY_GetTrg() & 0xf3))
            return 1;
        break;
    }
    return 0;
}

int UNION_ONESELF_TrainerCardMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    u8 *cardBytes;
    if (UNION_ONESELF_HandleNetError(unisys) == 1)
        return 1;
    switch (*seq) {
    case 0:
        if (unisys->myTrainerCard != 0 || unisys->recvTrainerCard != 0)
            GF_PANIC_Fail((char *)gUnionEmptyString1, 0, (char *)gUnionEmptyString1);
        unisys->myTrainerCard = GFL_HEAP_Alloc(0x41, 0x678, 1, (char *)d_021807E8, 0x9B3);
        unisys->recvTrainerCard = GFL_HEAP_Alloc(0x41, 0x678, 1, (char *)d_021807E8, 0x9B5);
        TRCARD_SYS_BuildProfile(unisys->myTrainerCard, unisys->parent->gameData, 1, 0, 0x41);
        MI_CpuCopy8(unisys->myTrainerCard, unisys->recvTrainerCard, 0x678);
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 3, 0x14);
        UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_CheckLanguageVersion(unisys, situation->connect.talkParam->nation, situation->connect.talkParam->area));
        (*seq)++;
        break;
    case 1:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 3, 0x14) == 1)
            (*seq)++;
        break;
    case 2:
        if (UNION_COMMAND_SendTrainerCard(unisys) == 1)
            (*seq)++;
        break;
    case 3:
        if (situation->connect.trainerCardReceived == 1 && UNION_MSG_CheckTalkPrintEnd(unisys) == 1) {
            cardBytes = unisys->recvTrainerCard;
            cardBytes[4] |= 0x20;
            unisys->partnerCard = TRCARD_SYS_CreateEditWork(unisys->parent->gameData, unisys->recvTrainerCard, 0x41);
            (*seq)++;
        }
        break;
    case 4:
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 4, 0x14);
        (*seq)++;
        break;
    case 5:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 4, 0x14) == 1)
            (*seq)++;
        break;
    case 6:
        UNION_SCENE_RequestScene(unisys, 1, (int)(unisys->partnerCard));
        (*seq)++;
        break;
    case 7:
        if (UNION_SCENE_IsScenePending(unisys) == 0)
            (*seq)++;
        break;
    case 8:
        UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 0x10);
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 5, 0x14);
        (*seq)++;
        break;
    case 9:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) != 0 && GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 5, 0x14) == 1) {
            GFL_HEAP_Free(unisys->myTrainerCard);
            GFL_HEAP_Free(unisys->recvTrainerCard);
            unisys->partnerCard = 0;
            unisys->myTrainerCard = 0;
            unisys->recvTrainerCard = 0;
            if (GFL_NET_IsParentAid() == 1)
                UNION_ONESELF_SetNextPlayCategory(unisys, 7);
            else
                UNION_ONESELF_SetNextPlayCategory(unisys, 9);
            return 1;
        }
        break;
    }
    return 0;
}

int UNION_ONESELF_TradeMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    void *gameData;
    void *commState;
    UnionTradeParam *param;
    UnionTradeSetup *setup;
    if (*seq != 4 && UNION_ONESELF_HandleNetError(unisys) == 1)
        return 1;
    switch (*seq) {
    case 0:
        UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 0x26);
        (*seq)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1) {
            GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 6, 0x14);
            (*seq)++;
        }
        break;
    case 2:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 6, 0x14) == 1) {
            gameData = GAMESYSTEM_GetGameData(unisys->parent->gameSystem);
            commState = MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(gameData));
            MET_TRAINERS_Insert(commState, MYSTATUS_GetId(GAME_DATA_GetMyStatusPlayer(gameData, GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle()) ^ 1)));
            (*seq)++;
        }
        break;
    case 3:
        param = GFL_HEAP_Alloc(0x41, 0x30, 1, (char *)d_021807E8, 0xA54);
        param->gameData = (int)GAMESYSTEM_GetGameData(unisys->parent->gameSystem);
        param->party = (int)POKEPARTY_Create(0x41);
        setup = GFL_HEAP_Alloc(4, 0x14, 0, (char *)d_021807E8, 0xA5B);
        setup->gameData = param->gameData;
        setup->party = param->party;
        setup->tradeMode = 0;
        setup->isEvent = 0;
        setup->isDemo = 0;
        setup->isComm = 1;
        setup->result = 0;
        param->setup = setup;
        param->result = 0;
        unisys->sceneParam = param;
        UNION_SCENE_RequestScene(unisys, 2, (int)param);
        (*seq)++;
        break;
    case 4:
        if (UNION_SCENE_IsScenePending(unisys) == 0) {
            param = ((UnionTradeParam *)unisys->sceneParam);
            GFL_HEAP_Free(param->setup);
            GFL_HEAP_Free((void *)param->party);
            GFL_HEAP_Free(((UnionTradeParam *)unisys->sceneParam));
            unisys->sceneParam = 0;
            (*seq)++;
        }
        break;
    case 5:
        UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 0x10);
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 7, 0x14);
        (*seq)++;
        break;
    case 6:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) != 0 && GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 7, 0x14) == 1) {
            if (GFL_NET_IsParentAid() == 1)
                UNION_ONESELF_SetNextPlayCategory(unisys, 7);
            else
                UNION_ONESELF_SetNextPlayCategory(unisys, 9);
            return 1;
        }
        break;
    }
    return 0;
}

int UNION_ONESELF_JoinMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    int beaconIndex;
    int requiredCount;
    beaconIndex = UNION_CHARA_GetBeaconIndex(situation->connect.requestId);
    if (UNION_ONESELF_HandleNetError(unisys) == 1)
        return 1;
    switch (*seq) {
    case 0:
        situation->connect.serviceLocked = 1;
        UNION_COMM_SetGameKindByStatus(situation->connect.partnerSelectA);
        GFL_NET_SetChangeoverModeWrapper(2, 1, unisys->beaconPc[beaconIndex].mac);
        situation->waitTimer = 0;
        (*seq)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 0)
            break;
        if (GFL_NET_GetNegotiationNum() > 1) {
            GFL_NET_SetLoginOption(1);
            requiredCount = UNION_MSG_GetCategoryTableValue(situation->connect.partnerSelectA);
            if (requiredCount <= (int)GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) {
                *seq = 4;
            } else {
                UNION_COMM_SetSituationParam(unisys, 3, (u32)&unisys->beaconPc[beaconIndex]);
                situation->connect.serviceFlag = 1;
                switch (situation->connect.partnerSelectA) {
                case 0x14:
                    UNION_ONESELF_SetNextPlayCategory(unisys, (int)0x1f);
                    break;
                case 0x15:
                    UNION_ONESELF_SetNextPlayCategory(unisys, (int)0x20);
                    break;
                case 0x16:
                    UNION_ONESELF_SetNextPlayCategory(unisys, (int)0x21);
                    break;
                case 0x17:
                    UNION_ONESELF_SetNextPlayCategory(unisys, (int)0x22);
                    break;
                case 3:
                    UNION_ONESELF_SetNextPlayCategory(unisys, (int)0xe);
                    break;
                case 0x19:
                    UNION_ONESELF_SetNextPlayCategory(unisys, (int)0x24);
                    break;
                default:
                    GF_PANIC_Fail((char *)gUnionEmptyString1, (int)0, (char *)gUnionEmptyString1);
                    break;
                }
                *seq = 3;
            }
        } else {
            situation->waitTimer++;
            if (situation->waitTimer > 600 || (KEY_GetTrg() & 2)) {
                situation->connect.serviceLocked = 0;
                UNION_ONESELF_SetNextPlayCategory(unisys, (int)0);
                *seq = 4;
            }
        }
        break;
    case 2:
        switch (situation->connect.partnerSelectA) {
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetMultiBattleBusyMsg(situation->connect.talkParam->sex));
            break;
        case 3:
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetDrawBusyMsg(situation->connect.talkParam->sex));
            break;
        case 0x19:
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetSpinTradeBusyMsg(situation->connect.talkParam->sex));
            break;
        }
        *seq = 3;
        break;
    case 3:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1)
            return 1;
        break;
    case 4:
        UNION_COMM_RequestRestart(unisys);
        (*seq)++;
        break;
    case 5:
        if (UNION_COMM_IsResetting(unisys) == 0)
            *seq = 2;
        break;
    }
    return 0;
}

int UNION_ONESELF_ConnectGroupMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    int linkState;
    UnionBeaconPc *connectPc;
    if (*seq < 3 && UNION_ONESELF_HandleNetError(unisys) == 1)
        return 1;
    switch (*seq) {
    case 0:
        UNION_COMM_StartConnectSync(unisys);
        (*seq)++;
        break;
    case 1:
        if (UNION_COMM_IsResetting(unisys) != 0)
            break;
        linkState = GFL_NET_IsSessionNull();
        if (linkState == 1) {
            connectPc = situation->connect.connectPc;
            if (connectPc != 0) {
                UNION_COMM_RemoveMemberOfBeaconPc((struct UnionConnectInfo *)(&situation->connect), connectPc);
                UNION_COMM_SetSituationParam(unisys, 3, 0);
            }
            UNION_COMM_RequestStart(unisys);
            (*seq)++;
        }
        break;
    case 2:
        if (UNION_COMM_IsResetting(unisys) == 0)
            (*seq)++;
        break;
    case 3:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1) {
            if (KEY_GetTrg() & 0xf3)
                return 1;
        }
        break;
    }
    return 0;
}

int UNION_ONESELF_AppMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    UnionSceneThreeParam *paramThree;
    UnionSceneFourParam *paramFour;
    if (*seq != 4 && *seq != 5 && *seq != 8 && UNION_ONESELF_HandleNetError(unisys) == 1)
        return 1;
    switch (*seq) {
    case 0:
        if (situation->connect.serviceFlag == 1)
            *seq = 6;
        else
            (*seq)++;
        break;
    case 1:
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 8, 0x14);
        (*seq)++;
        break;
    case 2:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 8, 0x14) == 1)
            (*seq)++;
        break;
    case 3:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1) {
            if (situation->playCategory == 0xe) {
                paramThree = GFL_HEAP_Alloc(0x41, 8, 1, (char *)d_021807E8, 0xB9A);
                paramThree->gameData = unisys->parent->gameData;
                unisys->sceneParam = paramThree;
                UNION_SCENE_RequestScene(unisys, 3, (int)paramThree);
            } else {
                paramFour = GFL_HEAP_Alloc(0x41, 0x18, 1, (char *)d_021807E8, 0xBA2);
                paramFour->gameData = unisys->parent->gameData;
                paramFour->party = GAME_DATA_GetMyParty(unisys->parent->gameData);
                paramFour->saveData = GAME_DATA_GetSaveControl(unisys->parent->gameData);
                paramFour->bag = GAME_DATA_GetTrainerRecord(unisys->parent->gameData);
                unisys->sceneParam = paramFour;
                UNION_SCENE_RequestScene(unisys, 4, (int)paramFour);
            }
            (*seq)++;
        }
        break;
    case 4:
        if (UNION_SCENE_IsScenePending(unisys) == 0) {
            GFL_HEAP_Free(unisys->sceneParam);
            unisys->sceneParam = 0;
            if (GFL_NET_ERR_GetErrorLevel() != 0) {
                UNION_ONESELF_SetNextPlayCategory(unisys, 1);
                return 1;
            }
            UNION_COMM_RequestStart(unisys);
            (*seq)++;
        }
        break;
    case 5:
        if (UNION_COMM_IsResetting(unisys) == 0)
            return 1;
        break;
    case 6:
        if (UNION_COMMAND_SendAppEntry(unisys) == 1)
            (*seq)++;
        break;
    case 7:
        switch (unisys->entryResult) {
        case 1:
            if (situation->playCategory == 0xe)
                UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetDrawStartMsg(situation->connect.talkParam->sex));
            else
                UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetSpinTradeStartMsg(situation->connect.talkParam->sex));
            *seq = 3;
            break;
        case 2:
            if (situation->playCategory == 0xe)
                UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetDrawBusyMsg(situation->connect.talkParam->sex));
            else
                UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetSpinTradeBusyMsg(situation->connect.talkParam->sex));
            UNION_COMM_RequestRestart(unisys);
            *seq = 8;
            break;
        }
        break;
    case 8:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1 && UNION_COMM_IsResetting(unisys) == 0) {
            UNION_COMM_SetSituationParam(unisys, 3, 0);
            return 1;
        }
        break;
    }
    return 0;
}

int UNION_ONESELF_ColosseumEnterParentMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    UnionParentWork *parent;
    if (*seq < 4 && UNION_ONESELF_HandleNetError(unisys) == 1)
        return 1;
    switch (*seq) {
    case 0:
        if (unisys->colosseum != 0)
            GF_PANIC_Fail((char *)gUnionEmptyString1, 0, (char *)gUnionEmptyString1);
        parent = unisys->parent;
        unisys->colosseum = COLOSSEUM_Create(parent->gameData, parent->gameSystem, parent->myStatus, situation->connect.serviceFlag);
        UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetColosseumStartMsg(situation->connect.talkParam->sex));
        (*seq)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1)
            (*seq)++;
        break;
    case 2:
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0xb, 0x14);
        (*seq)++;
        break;
    case 3:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0xb, 0x14) == 1)
            (*seq)++;
        break;
    case 4:
        UNION_SCENE_RequestScene(unisys, situation->connect.partnerSelectA + 1, 0);
        (*seq)++;
        break;
    case 5:
        if (UNION_SCENE_IsScenePending(unisys) == 0) {
            UNION_ONESELF_SetFieldBusy(unisys, fieldMap, 1);
            UNION_ONESELF_SetNextPlayCategory(unisys, 0x28);
            return 1;
        }
        break;
    }
    return 0;
}

int UNION_ONESELF_ColosseumEnterChildMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    UnionParentWork *parent;
    if (*seq < 4 && UNION_ONESELF_HandleNetError(unisys) == 1)
        return 1;
    switch (*seq) {
    case 0:
        if (situation->connect.serviceFlag == 0)
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetColosseumStartMsg(situation->connect.talkParam->sex));
        else
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, UNION_MSG_GetMultiBattleStartMsg(situation->connect.talkParam->sex));
        (*seq)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1)
            (*seq)++;
        break;
    case 2:
        if (situation->connect.serviceFlag == 0)
            GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0xb, 0x14);
        (*seq)++;
        break;
    case 3:
        if (situation->connect.serviceFlag == 0) {
            if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0xb, 0x14) == 1)
                (*seq)++;
        } else {
            (*seq)++;
        }
        break;
    case 4:
        UNION_SCENE_RequestScene(unisys, situation->connect.partnerSelectA + 1, 0);
        (*seq)++;
        break;
    case 5:
        if (UNION_SCENE_IsScenePending(unisys) == 0) {
            if (unisys->colosseum != 0)
                GF_PANIC_Fail((char *)gUnionEmptyString1, 0, (char *)gUnionEmptyString1);
            parent = unisys->parent;
            unisys->colosseum = COLOSSEUM_Create(parent->gameData, parent->gameSystem, parent->myStatus, situation->connect.serviceFlag);
            UNION_ONESELF_SetFieldBusy(unisys, fieldMap, 1);
            UNION_ONESELF_SetNextPlayCategory(unisys, 0x28);
            return 1;
        }
        break;
    }
    return 0;
}

int UNION_ONESELF_ColosseumEntryMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum = unisys->colosseum;
    int entryResult;

    GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle());
    if (colosseum == 0)
        GF_PANIC_Fail((char *)gUnionEmptyString1, 0, (char *)gUnionEmptyString1);

    if (UNION_ONESELF_HandleNetErrorExit(unisys) == 1) {
        if (colosseum->entryMenu != 0)
            COMM_ENTRY_MENU_Delete(colosseum->entryMenu);
        UNION_MSG_CloseAllWindows(unisys);
        return 1;
    }

    switch (*seq) {
    case 0:
        if (UNION_MSG_GetCategoryTableValue(situation->connect.partnerSelectA) == 2) {
            colosseum->parentSetting = 1;
            if (GFL_NET_IsParentAid() == 1) {
                if (UNION_COMMAND_SendColosseumCancel() == 1)
                    *seq = 100;
            } else {
                *seq = 100;
            }
            break;
        }
        GFL_NET_SetLoginOption(0);
        if (GFL_NET_IsParentAid() == 1) {
            colosseum->entryMenu = COMM_ENTRY_MENU_Create(GAME_DATA_GetMyStatus(unisys->parent->gameData), fieldMap,
                                    UNION_MSG_GetCategoryTableValue(situation->connect.partnerSelectA),
                                    UNION_MSG_GetCategoryTableValue(situation->connect.partnerSelectA), 0x41, 0, 0, 0);
            COMM_ENTRY_MENU_SetCallbacks(colosseum->entryMenu, unisys, UNION_ONESELF_EntryMenuAddMember, UNION_ONESELF_EntryMenuRemoveMember);
        } else if (situation->connect.serviceFlag == 0) {
            colosseum->entryMenu = COMM_ENTRY_MENU_Create(GAME_DATA_GetMyStatus(unisys->parent->gameData), fieldMap,
                                    UNION_MSG_GetCategoryTableValue(situation->connect.partnerSelectA),
                                    UNION_MSG_GetCategoryTableValue(situation->connect.partnerSelectA), 0x41, 2, 0, 0);
        } else {
            colosseum->entryMenu = COMM_ENTRY_MENU_Create(GAME_DATA_GetMyStatus(unisys->parent->gameData), fieldMap,
                                    UNION_MSG_GetCategoryTableValue(situation->connect.partnerSelectA),
                                    UNION_MSG_GetCategoryTableValue(situation->connect.partnerSelectA), 0x41, 3, 0, 0);
        }
        if (situation->connect.serviceFlag == 0) {
            UNION_COMM_SetGameKindByStatus(situation->status);
            GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0xc, 0x14);
        }
        (*seq)++;
        break;
    case 1:
        if (situation->connect.serviceFlag == 0) {
            if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0xc, 0x14) == 1) {
                GFL_NET_SetAcceptConnection((int)GFL_NET_HANDLE_GetCurrentHandle(), (void *)1);
                (*seq)++;
            }
        } else {
            (*seq)++;
        }
        break;
    case 2:
        (*seq)++;
        break;
    case 3:
        entryResult = COMM_ENTRY_MENU_Main(colosseum->entryMenu);
        if (entryResult != 0) {
            colosseum->entryBits = COMM_ENTRY_MENU_Delete(colosseum->entryMenu);
            colosseum->entryMenu = 0;
            switch (entryResult) {
            case 1:
                *seq = 100;
                GFL_NET_SetLoginOption(1);
                break;
            case 2:
                *seq = 200;
                break;
            case 3:
                *seq = 200;
                break;
            case 4:
                *seq = 200;
                break;
            default:
                GF_PANIC_Fail((char *)gUnionEmptyString1, 0, (char *)gUnionEmptyString1);
                break;
            }
        }
        break;
    case 4:
        break;
    case 100:
        colosseum->parentSetting = 1;
        UNION_ONESELF_SetNextPlayCategory(unisys, 0x29);
        return 1;
    case 200:
        UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 0x14c);
        colosseum->parentSetting = 2;
        (*seq)++;
        break;
    case 201:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1) {
            UNION_ONESELF_SetNextPlayCategory(unisys, 0x32);
            UNION_ONESELF_SetFieldBusy(unisys, fieldMap, 1);
            return 1;
        }
        break;
    case 300:
        colosseum->parentSetting = 2;
        UNION_ONESELF_SetNextPlayCategory(unisys, 0x32);
        UNION_ONESELF_SetFieldBusy(unisys, fieldMap, 1);
        return 1;
    }
    return 0;
}

void UNION_ONESELF_EntryMenuAddMember(UnionRoomWork *unisys, const void *myStatus, const u8 *mac)
{
    int gender = MYSTATUS_GetTrainerView((struct MyStatus *)myStatus);
    int trainerView = MYSTATUS_GetSex(myStatus);
    UNION_COMM_AddMember(&unisys->mySituation.connect, mac, gender, (u8)trainerView);
}

void UNION_ONESELF_EntryMenuRemoveMember(UnionRoomWork *unisys, const void *myStatus, const u8 *mac)
{
    UNION_COMM_RemoveMember(&unisys->mySituation.connect, (u8 *)mac);
}

int UNION_ONESELF_ColosseumSetupMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum = unisys->colosseum;
    int myIndex;
    int playerCount;
    int playerIndex;
    int gender;
    void *commState;

    myIndex = GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle());
    if (colosseum == 0)
        GF_PANIC_Fail((char *)gUnionEmptyString1, (int)0, (char *)gUnionEmptyString1);

    if (UNION_ONESELF_HandleNetErrorExit(unisys) == 1) {
        UNION_MSG_CloseAllWindows(unisys);
        return 1;
    }

    switch (*seq) {
    case 0:
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0xd, 0x14);
        (*seq)++;
        break;
    case 1:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0xd, 0x14) == 1)
            (*seq)++;
        break;
    case 2:
        COLOSSEUM_AddCommandTable(unisys);
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0xe, 0x14);
        (*seq)++;
        break;
    case 3:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0xe, 0x14) == 1)
            (*seq)++;
        break;
    case 4:
        if (COLOSSEUM_SendPlayerEntry(&colosseum->player[myIndex], 0) == 1)
            (*seq)++;
        break;
    case 5:
        if (COLOSSEUM_CheckAllEntered(colosseum) == 1) {
            playerCount = GFL_NET_GetNegotiationNum();
            for (playerIndex = 0; playerIndex < playerCount; playerIndex++) {
                if (colosseum->player[playerIndex].isEntered == 1) {
                    gender = MYSTATUS_GetTrainerView((struct MyStatus *)(&colosseum->player[playerIndex]));
                    UNION_COMM_AddMember(&situation->connect, colosseum->player[playerIndex].statusExtra, gender,
                                  (u8)MYSTATUS_GetSex(&colosseum->player[playerIndex]));
                }
            }
            (*seq)++;
        }
        break;
    case 6:
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0xf, 0x14);
        (*seq)++;
        break;
    case 7:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0xf, 0x14) == 1)
            (*seq)++;
        break;
    case 8:
        if (COLOSSEUM_SendTrainerCard(colosseum->trainerCard[myIndex]) == 1)
            (*seq)++;
        break;
    case 9:
        if (COLOSSEUM_CheckAllTrainerCardsReceived(colosseum) == 1)
            (*seq)++;
        break;
    case 10:
        commState = MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(unisys->parent->gameSystem)));
        playerCount = GFL_NET_GetNegotiationNum();
        for (playerIndex = 0; playerIndex < playerCount; playerIndex++) {
            if (colosseum->player[playerIndex].isEntered == 1 && playerIndex != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle()))
                MET_TRAINERS_Insert(commState, MYSTATUS_GetId((struct MyStatus *)(&colosseum->player[playerIndex])));
        }
        COLOSSEUM_SetStartFlag(colosseum, 1);
        UNION_ONESELF_SetNextPlayCategory(unisys, 0x2a);
        return 1;
    }
    return 0;
}

int UNION_ONESELF_ColosseumFreeMoveStart(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap)
{
    UNION_MSG_CloseAllWindows(unisys);
    UNION_ONESELF_SetFieldBusy(unisys, fieldMap, 0);
    return 1;
}

int UNION_ONESELF_ColosseumFreeMoveMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum = unisys->colosseum;
    void *fieldCtrl;
    int talkPlayer;
    unsigned sideFlags;
    int found;
    s16 position[3];

    fieldCtrl = FIELDMAP_GetFieldPlayer((void *)fieldMap);
    if (UNION_ONESELF_HandleNetErrorExit(unisys) == 1) {
        UNION_MSG_CloseAllWindows(unisys);
        return 1;
    }

    if (*seq == 0) {
        if (COLOSSEUM_IsOnStandPos((int)fieldMap, UNION_MSG_GetCategoryTableValue(situation->connect.partnerSelectA), &sideFlags) == 1) {
            COLOSSEUM_SetMyChoice(colosseum, sideFlags);
            UNION_ONESELF_SetNextPlayCategory(unisys, 0x2b);
            UNION_ONESELF_SetFieldBusy(unisys, fieldMap, 1);
            return 1;
        }
        if (COLOSSEUM_IsAnyFinished(colosseum) == 1) {
            UNION_ONESELF_SetNextPlayCategory(unisys, 0x32);
            UNION_ONESELF_SetFieldBusy(unisys, fieldMap, 1);
            return 1;
        }
        if (COLOSSEUM_IsOnCounterPos((void *)fieldMap) == 1) {
            UNION_ONESELF_SetNextPlayCategory(unisys, 0x31);
            UNION_ONESELF_SetFieldBusy(unisys, fieldMap, 1);
            return 1;
        }
        if (KEY_GetTrg() & 1) {
            found = 0;
            FIELD_PLAYER_GetFrontGridPos(fieldCtrl, (short *)((&position[2])), (short *)((&position[1])), (&position[0]));
            if (COMM_PLAYER_SearchGridPos((void *)(colosseum->commPlayer), position[2], position[1], position[0], (int)(&talkPlayer), (int)(&found)) == 1) {
                colosseum->talkPlayer = talkPlayer;
                UNION_ONESELF_SetNextPlayCategory(unisys, 0x33);
                UNION_ONESELF_SetFieldBusy(unisys, fieldMap, 1);
                return 1;
            }
        }
    }
    return 0;
}

int UNION_ONESELF_ColosseumStandPosMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum = unisys->colosseum;
    void *transition;
    unsigned sideFlags;
    int answer;

    if (UNION_ONESELF_HandleNetErrorExit(unisys) == 1) {
        UNION_MSG_CloseAllWindows(unisys);
        return 1;
    }

    switch (*seq) {
    case 0:
        (*seq)++;
        break;
    case 1:
        if (COLOSSEUM_SendChoiceRequest(colosseum) == 1)
            (*seq)++;
        break;
    case 2:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) != 0) {
            answer = COLOSSEUM_GetMyChoiceReply(colosseum);
            if (answer == 1) {
                (*seq)++;
            } else if (answer == 0) {
                UNION_ONESELF_SetNextPlayCategory(unisys, 0x2c);
                return 1;
            }
        }
        break;
    case 3:
        transition = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)fieldMap));
        if (FLDMMDL_CheckPossibleAcmd(transition) == 1) {
            COLOSSEUM_IsOnStandPos((int)fieldMap, UNION_MSG_GetCategoryTableValue(situation->connect.partnerSelectA), &sideFlags);
            FLDMMDL_SetAcmd(transition, (sideFlags & 1) ? 2 : 3);
            (*seq)++;
        }
        break;
    case 4:
        transition = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)fieldMap));
        if (FLDMMDL_CheckEndAcmd(transition) == 1) {
            FLDMMDL_EndAcmd(transition);
            UNION_ONESELF_SetNextPlayCategory(unisys, 0x2d);
            return 1;
        }
        break;
    }
    return 0;
}

int UNION_ONESELF_ColosseumLeavePosMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum = unisys->colosseum;
    void *transition;
    unsigned sideFlags;

    transition = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)fieldMap));
    if (UNION_ONESELF_HandleNetErrorExit(unisys) == 1) {
        UNION_MSG_CloseAllWindows(unisys);
        return 1;
    }

    switch (*seq) {
    case 0:
        COLOSSEUM_SetMyChoice(colosseum, 0xff);
        (*seq)++;
        break;
    case 1:
        if (COLOSSEUM_SendChoiceRequest(colosseum) == 1)
            (*seq)++;
        break;
    case 2:
        if (COLOSSEUM_GetMyChoiceReply(colosseum) != 0xff)
            (*seq)++;
        break;
    case 3:
        UNION_MSG_CloseAllWindows(unisys);
        (*seq)++;
        break;
    case 4:
        if (FLDMMDL_CheckPossibleAcmd(transition) == 1) {
            COLOSSEUM_IsOnStandPos((int)fieldMap, UNION_MSG_GetCategoryTableValue(situation->connect.partnerSelectA), &sideFlags);
            FLDMMDL_SetAcmd(transition, (sideFlags & 1) ? 0xb : 0xa);
            (*seq)++;
        }
        break;
    case 5:
        if (FLDMMDL_CheckEndAcmd(transition) == 1) {
            FLDMMDL_EndAcmd(transition);
            UNION_ONESELF_SetNextPlayCategory(unisys, 0x2a);
            return 1;
        }
        break;
    }
    return 0;
}

int UNION_ONESELF_ColosseumPartySelectMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum = unisys->colosseum;
    int partyFailMask;
    int teamFailMask;
    int selectedIndex;
    int failMask;
    int modeFlag;
    int teamFlag;
    int menuResult;

    if (UNION_MSG_CheckTalkPrintEnd(unisys) == 0)
        return 0;

    switch (*seq) {
    case 0:
        situation->subState = 0;
        (*seq)++;
    case 1:
        if (BATTLE_BOX_HasMon((struct BoxMonGroup *)BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(unisys->parent->gameData))) == 1) {
            (*seq)++;
        } else {
            colosseum->partySource = 0;
            situation->subState++;
            *seq = 4;
        }
        break;
    case 2:
        UNION_MSG_CloseAllWindows(unisys);
        UNION_ONESELF_CheckMyParty(unisys, (unsigned int *)(&partyFailMask));
        UNION_ONESELF_CheckBattleTeamParty(unisys, (unsigned int *)(&teamFailMask));
        modeFlag = partyFailMask != 0;
        teamFlag = teamFailMask != 0;
        unisys->partySelectParam = UNION_ONESELF_CreateBattleTeamParty(unisys);
        unisys->partySelect = PARTY_SELECT_LIST_Create((void *)fieldMap, (void *)GAME_DATA_GetMyParty(unisys->parent->gameData), (void *)unisys->partySelectParam, modeFlag, teamFlag, 0x15);
        (*seq)++;
        break;
    case 3:
        if (PARTY_SELECT_LIST_Main(unisys->partySelect) == 1) {
            menuResult = PARTY_SELECT_LIST_Delete(unisys->partySelect, (u32 *)(&selectedIndex));
            unisys->partySelect = 0;
            if (menuResult == 2) {
                UNION_ONESELF_DeleteParty(unisys->partySelectParam);
                unisys->partySelectParam = 0;
                UNION_ONESELF_SetNextPlayCategory(unisys, 0x2c);
                return 1;
            }
            switch (menuResult) {
            case 0:
                colosseum->partySource = 0;
                break;
            case 1:
                colosseum->partySource = 1;
                break;
            }
            UNION_ONESELF_DeleteParty(unisys->partySelectParam);
            unisys->partySelectParam = 0;
            (*seq)++;
        }
        break;
    case 4:
        failMask = 0;
        if (colosseum->partySource == 0) {
            UNION_ONESELF_CheckMyParty(unisys, (unsigned int *)(&failMask));
            modeFlag = 1;
        } else {
            UNION_ONESELF_CheckBattleTeamParty(unisys, (unsigned int *)(&failMask));
            modeFlag = 2;
        }
        if (failMask != 0) {
            UNION_MSG_SetupTalkWindow(unisys, fieldMap);
            UNION_MSG_SetupRegulationWindow(unisys, (u32)fieldMap, failMask, UNION_ONESELF_GetRegulationFlag(situation->status), modeFlag);
            *seq = 5;
        } else {
            UNION_ONESELF_SetNextPlayCategory(unisys, 0x2e);
            return 1;
        }
        break;
    case 5:
        if (UNION_MSG_CheckRegulationPrintEnd(unisys, (u32)fieldMap) == 1) {
            UNION_MSG_SetupPrintTalkMsg(unisys, (u8 *)fieldMap, 0x115);
            (*seq)++;
        }
        break;
    case 6:
        if (KEY_GetTrg() & 3) {
            UNION_MSG_DeleteRegulationWindow(unisys);
            if (situation->subState == 0) {
                *seq = 0;
            } else {
                UNION_ONESELF_SetNextPlayCategory(unisys, 0x2c);
                return 1;
            }
        }
        break;
    }
    return 0;
}

int UNION_ONESELF_ColosseumReadyWaitMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum;

    colosseum = unisys->colosseum;
    if (UNION_ONESELF_HandleNetErrorExit(unisys) == 1) {
        UNION_MSG_CloseAllWindows(unisys);
        return 1;
    }
    if (colosseum->allReady == 1) {
        UNION_ONESELF_SetNextPlayCategory(unisys, 0x2f);
        colosseum->allReady = 0;
        colosseum->readySent = 0;
        return 1;
    }
    switch (*seq) {
    case 0:
        UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 0x116);
        (*seq)++;
        break;
    case 1:
        if (COLOSSEUM_SendReady() == 1) {
            colosseum->readySent = 1;
            (*seq)++;
        }
        break;
    case 2:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1 && (KEY_GetTrg() & 2))
            *seq = 100;
        break;
    case 100:
        if (COLOSSEUM_SendReadyCancel() == 1)
            (*seq)++;
        break;
    case 101:
        if (colosseum->readySent == 0) {
            UNION_ONESELF_SetNextPlayCategory(unisys, 0x2c);
            return 1;
        }
        break;
    }
    return 0;
}

int UNION_ONESELF_ColosseumPartyExchangeMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum;
    int myIndex;
    void *party;

    colosseum = unisys->colosseum;
    myIndex = GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle());
    if (UNION_ONESELF_HandleNetErrorExit(unisys) == 1) {
        UNION_MSG_CloseAllWindows(unisys);
        return 1;
    }
    switch (*seq) {
    case 0:
        switch (colosseum->partySource) {
        case 0:
        default:
            POKEPARTY_Copy(GAME_DATA_GetMyParty(unisys->parent->gameData), (colosseum->party[myIndex]));
            break;
        case 1:
            party = UNION_ONESELF_CreateBattleTeamParty(unisys);
            POKEPARTY_Copy(party, (colosseum->party[myIndex]));
            UNION_ONESELF_DeleteParty(party);
            break;
        }
        POKE_REGULATION_AdjustPartyLevels((void *)(unisys->regulation), (void *)(colosseum->party[myIndex]));
        (*seq)++;
        break;
    case 1:
        COLOSSEUM_ResetParties(colosseum, 1);
        COLOSSEUM_ClearPositionsReceived(colosseum);
        COLOSSEUM_ClearConfirmCount(colosseum);
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x14, 0x14);
        (*seq)++;
        break;
    case 2:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x14, 0x14) == 1)
            (*seq)++;
        break;
    case 3:
        if (COLOSSEUM_SendParty(colosseum->party[myIndex]) == 1)
            (*seq)++;
        break;
    case 4:
        if (COLOSSEUM_AllPartiesReceived(colosseum) == 1)
            (*seq)++;
        break;
    case 5:
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x10, 0x14);
        (*seq)++;
        break;
    case 6:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x10, 0x14) == 1)
            (*seq)++;
        break;
    case 7:
        if (GFL_NET_IsParentAid() == 1) {
            if (COLOSSEUM_SendBattlePositions((void *)colosseum->choice) == 1)
                (*seq)++;
        } else {
            (*seq)++;
        }
        break;
    case 8:
        if (COLOSSEUM_IsPositionsReceived(colosseum) == 1) {
            UNION_ONESELF_SetNextPlayCategory(unisys, 0x30);
            return 1;
        }
        break;
    }
    return 0;
}

int UNION_ONESELF_ColosseumBattleMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum;
    int myIndex;
    int messageId;
    UnionBattleParam *battle;
    int playerIndex;
    int opponentCount;
    int opponentSlot;

    colosseum = unisys->colosseum;
    myIndex = GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle());
    if (*seq < 3 && UNION_ONESELF_HandleNetErrorExit(unisys) == 1) {
        UNION_MSG_CloseAllWindows(unisys);
        return 1;
    }
    switch (*seq) {
    case 0:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) != 1)
            break;
        switch (situation->connect.partnerSelectA) {
        default:
            messageId = 0x117;
            break;
        case 6:
        case 7:
        case 22:
        case 23:
            messageId = 0x118;
            break;
        case 20:
        case 21:
            messageId = 0x11b;
            break;
        case 10:
        case 11:
        case 18:
        case 19:
            messageId = 0x119;
            break;
        case 14:
        case 15:
            messageId = 0x11a;
            break;
        }
        UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, messageId);
        (*seq)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1) {
            GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 0x14);
            (*seq)++;
        }
        break;
    case 2:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 0x14) == 1) {
            UNION_MSG_CloseAllWindows(unisys);
            (*seq)++;
        }
        break;
    case 3:
        battle = GFL_HEAP_Alloc(0x41, 0xc4, 1, (char *)d_021807E8, 0x10c4);
        battle->party = colosseum->party[myIndex];
        battle->myStatus = GAME_DATA_GetMyItem(unisys->parent->gameData);
        battle->config = SYSTEM_DATA_GetConfig(GAME_DATA_GetSaveControl(unisys->parent->gameData));
        battle->commMode = 0x1a;
        battle->regulation = unisys->regulation;
        battle->recordBuffer = GFL_HEAP_Alloc(0x41, 0x70, 1, (char *)d_021807E8, 0x10ce);
        opponentCount = 0;
        for (playerIndex = 0; playerIndex < GFL_NET_GetNegotiationNum(); playerIndex++) {
            if (playerIndex == myIndex)
                continue;
            if ((colosseum->battlePosition[myIndex] & 1) == (colosseum->battlePosition[playerIndex] & 1))
                opponentSlot = 0;
            else
                opponentSlot = ++opponentCount;
            battle->opponent[opponentSlot].party = colosseum->party[playerIndex];
            battle->opponent[opponentSlot].myStatus = MYSTATUS_GetName(&colosseum->player[playerIndex]);
            battle->opponent[opponentSlot].trainerView = MYSTATUS_GetSex(&colosseum->player[playerIndex]);
        }
        switch (situation->connect.partnerSelectA) {
        case 20:
        case 21:
        case 22:
        case 23:
            battle->rule = 2;
            break;
        default:
            battle->rule = 1;
            break;
        }
        battle->isComm = 1;
        battle->recordMode = 0;
        battle->result = 0;
        unisys->sceneParam = battle;
        UNION_SCENE_RequestScene(unisys, 0x1a, (int)battle);
        (*seq)++;
        break;
    case 4:
        if (UNION_SCENE_IsScenePending(unisys) == 1)
            break;
        GFL_HEAP_Free(((UnionBattleParam *)unisys->sceneParam)->recordBuffer);
        GFL_HEAP_Free(((UnionBattleParam *)unisys->sceneParam));
        unisys->sceneParam = 0;
        UNION_ONESELF_SetNextPlayCategory(unisys, 0x2c);
        return 1;
    }
    return 0;
}

int UNION_ONESELF_ColosseumLeaveConfirmMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    void *transition;
    int confirmed;

    transition = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
    if (UNION_ONESELF_HandleNetErrorExit(unisys) == 1) {
        UNION_MSG_CloseAllWindows(unisys);
        return 1;
    }
    switch (*seq) {
    case 0:
        UNION_MSG_SetupPrintTalkMsg(unisys, (u8 *)fieldMap, 0x14e);
        (*seq)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) != 0) {
            UNION_MSG_SetupYesNo(unisys, (u32)fieldMap);
            (*seq)++;
        }
        break;
    case 2:
        if (UNION_MSG_SelectYesNo(unisys, (u32 *)(&confirmed)) == 1) {
            UNION_MSG_DeleteYesNo(unisys);
            if (confirmed == 0) {
                *seq = 3;
            } else {
                UNION_ONESELF_SetNextPlayCategory(unisys, 0x32);
                return 1;
            }
        }
        break;
    case 3:
        if (FLDMMDL_CheckPossibleAcmd(transition) == 1) {
            FLDMMDL_SetAcmd(transition, 8);
            (*seq)++;
        }
        break;
    case 4:
        if (FLDMMDL_CheckEndAcmd(transition) == 1) {
            FLDMMDL_EndAcmd(transition);
            UNION_ONESELF_SetNextPlayCategory(unisys, 0x2a);
            return 1;
        }
        break;
    }
    return 0;
}

int UNION_ONESELF_ColosseumExitMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum;
    int entryBits;
    int aid;

    colosseum = unisys->colosseum;
    if (*seq < 7 && GFL_NET_ERR_GetErrorLevel() != 0 && UNION_MSG_CheckTalkPrintEnd(unisys) == 1) {
        UNION_ONESELF_SetFieldBusy(unisys, fieldMap, 1);
        *seq = 7;
    }
    switch (*seq) {
    case 0:
        UNION_ONESELF_SetFieldBusy(unisys, fieldMap, 1);
        if (colosseum->parentSetting == 2) {
            if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1)
                *seq = 6;
        } else {
            UNION_MSG_SetupPrintTalkMsg(unisys, fieldMap, 0x14c);
            (*seq)++;
        }
        break;
    case 1:
        if (COLOSSEUM_SendFinish() == 1)
            (*seq)++;
        break;
    case 2:
        if (COLOSSEUM_CheckAllFinished(colosseum) == 1)
            (*seq)++;
        break;
    case 3:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1)
            (*seq)++;
        break;
    case 4:
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x13, 0x14);
        (*seq)++;
        break;
    case 5:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x13, 0x14) == 1) {
            GFL_NET_SetLoginOption(0);
            (*seq)++;
        }
        break;
    case 6:
        if (GFL_NET_IsParentAid() == 1) {
            entryBits = colosseum->entryBits;
            if (GFL_NET_SYSTEM_GetConnectNum() <= 1) {
                (*seq)++;
                break;
            }
            for (aid = 0; aid < 5; aid++) {
                if (aid != GFL_NET_SYSTEM_GetCurrentAid() && ((1 << aid) & entryBits)) {
                    if ((int)GFL_NET_IsConnectMember((u8)aid) == 1)
                        break;
                }
            }
            if (aid == 5)
                (*seq)++;
        } else {
            (*seq)++;
        }
        break;
    case 7:
        if (colosseum->leaveSent == 1 && UNION_COMM_IsResetting(unisys) == 1)
            return 0;
        if (GFL_NET_ERR_GetErrorLevel() != 0) {
            UNION_MSG_CloseAllWindows(unisys);
            GAMESYSTEM_SetFieldMapState((unisys->parent->gameSystem), 1);
            return 0;
        }
        UNION_COMM_RequestShutdown(unisys);
        (*seq)++;
        break;
    case 8:
        if (UNION_COMM_IsResetting(unisys) == 0)
            (*seq)++;
        break;
    case 9:
        colosseum->exitRequested = 1;
        UNION_COMM_ClearBeaconPcs(unisys);
        UNION_CHARA_ClearTable(unisys);
        UNION_COMM_InitConnectInfo(unisys, &situation->connect);
        UNION_SCENE_RequestScene(unisys, 0x19, 0);
        (*seq)++;
        break;
    case 10:
        if (UNION_SCENE_IsScenePending(unisys) == 0) {
            if (unisys->colosseum != 0) {
                COLOSSEUM_Delete(unisys->colosseum, unisys->parent->gameSystem);
                unisys->colosseum = 0;
            }
            UNION_COMM_RequestStart(unisys);
            (*seq)++;
        }
        break;
    case 11:
        if (UNION_COMM_IsResetting(unisys) == 0)
            return 1;
        break;
    }
    return 0;
}

int UNION_ONESELF_ColosseumTrainerCardMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum;
    int partnerStatus;
    int cardRank;
    int messageId;
    void *partnerCard;

    colosseum = unisys->colosseum;
    switch (*seq) {
    case 0:
        UNION_ONESELF_SetFieldBusy(unisys, fieldMap, 1);
        partnerStatus = MYSTATUS_GetRomCode((struct MyStatus *)((&colosseum->player[colosseum->talkPlayer])));
        if (partnerStatus == 0x14 || partnerStatus == 0x15) {
            cardRank = ((u8 *)colosseum->trainerCard[colosseum->talkPlayer])[3];
            if (cardRank < 5) {
                messageId = 0x156 + cardRank;
            } else if (cardRank == 5) {
                switch (partnerStatus) {
                case 0x15:
                    messageId = 0x15c;
                    break;
                case 0x14:
                    messageId = 0x15b;
                    break;
                default:
                    messageId = 0x15d;
                    break;
                }
            } else {
                messageId = 0x15d;
            }
        } else {
            messageId = 0x15d;
        }
        UNION_MSG_SetupTalkWindow(unisys, fieldMap);
        WORDSET_SetSlotMyStatus((struct WordSet *)(unisys->msgWork.wordSet), 0, &colosseum->player[colosseum->talkPlayer]);
        UNION_MSG_PrintTalkMsg(unisys, messageId);
        (*seq)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(unisys) == 1 && (KEY_GetTrg() & 3)) {
            UNION_MSG_CloseAllWindows(unisys);
            ((u8 *)colosseum->trainerCard[colosseum->talkPlayer])[4] |= 0x20;
            partnerCard = TRCARD_SYS_CreateEditWork(unisys->parent->gameData, (u8 *)colosseum->trainerCard[colosseum->talkPlayer], 0x41);
            unisys->sceneParam = partnerCard;
            UNION_SCENE_RequestScene(unisys, 0x1c, (int)partnerCard);
            (*seq)++;
        }
        break;
    case 2:
        if (UNION_SCENE_IsScenePending(unisys) == 0) {
            unisys->sceneParam = 0;
            (*seq)++;
        }
        break;
    case 3:
        UNION_ONESELF_SetNextPlayCategory(unisys, 0x2a);
        return 1;
    }
    return 0;
}
