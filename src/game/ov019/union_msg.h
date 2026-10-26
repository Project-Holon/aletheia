#ifndef GAME_OV019_UNION_MSG_H
#define GAME_OV019_UNION_MSG_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of union_msg.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov012/union_comm_types.h"

u16 UNION_MSG_GetNoReplyMsg(void ***ctx);
u16 UNION_MSG_GetTalkParentGreetingMsg(int i);
u16 UNION_MSG_GetTalkParentCancelMsg(int i);
u16 UNION_MSG_GetTalkChildBusyMsg(int i);
u16 UNION_MSG_GetTalkParentAcceptMsg(int i, int j);
u16 UNION_MSG_GetTalkParentRefuseMsg(int i, int j);
u16 UNION_MSG_GetTalkChildOfferMsg(int i);
u16 UNION_MSG_GetTalkChildDeclineMsg(int i);
u16 UNION_MSG_GetTalkMenuPromptMsg(int i);
u16 UNION_MSG_GetColosseumStartMsg(int i);
u16 UNION_MSG_GetNotEnoughPokemonMsg(int i);
u16 UNION_MSG_GetNoEggInPartyMsg(int i);
u16 UNION_MSG_GetBadEggInPartyMsg(void ***ctx);
u16 UNION_MSG_GetBadEggNoticeMsg(void ***ctx);
u16 UNION_MSG_GetBattleChatMsg(int i);
u16 UNION_MSG_GetPartnerBusyMsg(int i);
u16 UNION_MSG_GetTrainerCardChatMsg(int i);
u16 UNION_MSG_GetDrawChatMsg(int i);
u16 UNION_MSG_GetTradeChatMsg(int i);
u16 UNION_MSG_GetSpinTradeChatMsg(int i);
u16 UNION_MSG_GetMultiBattleInviteMsg(int i);
u16 UNION_MSG_GetSpinTradeInviteMsg(int i);
u16 UNION_MSG_GetDrawInviteMsg(int i);
u16 UNION_MSG_GetMultiBattleInviteDeclinedMsg(int i);
u16 UNION_MSG_GetSpinTradeInviteDeclinedMsg(int i);
u16 UNION_MSG_GetDrawInviteDeclinedMsg(int i);
u16 UNION_MSG_GetSpinTradeNoEggMsg(int i);
u16 UNION_MSG_GetSpinTradeBadEggMsg(int i);
u16 UNION_MSG_GetSpinTradeWaitMsg(int i);
u16 UNION_MSG_GetSpinTradeStartMsg(int i);
u16 UNION_MSG_GetSpinTradeBusyMsg(int i);
u16 UNION_MSG_GetDrawWaitMsg(int i);
u16 UNION_MSG_GetDrawStartMsg(int i);
u16 UNION_MSG_GetDrawBusyMsg(int i);
u16 UNION_MSG_GetMultiBattleWaitMsg(int i);
u16 UNION_MSG_GetMultiBattleStartMsg(int i);
u16 UNION_MSG_GetMultiBattleBusyMsg(int i);
int UNION_MSG_CheckLanguageVersion(UnionRoomWork *unisys, int language, int version);
void UNION_MSG_RegisterPartnerWords(UnionRoomWork *unisys);
void UNION_MSG_SetGreetingWordFlag(void *gameData, unsigned int language);
void UNION_MSG_CreateWordSet(UnionRoomWork *unisys);
void UNION_MSG_DeleteWordSet(UnionRoomWork *unisys);
int UNION_MSG_GetCategoryTableValue(int i);
void UNION_MSG_CloseAllWindows(UnionRoomWork *unisys);
void UNION_MSG_SetupTalkWindow(UnionRoomWork *unisys, void *fieldmap);
void UNION_MSG_DeleteTalkWindow(UnionRoomWork *unisys);
void UNION_MSG_PrintTalkMsg(UnionRoomWork *unisys, u32 msgId);
u32 UNION_MSG_CheckTalkPrintEnd(UnionRoomWork *unisys);
void UNION_MSG_SetupPrintTalkMsg(UnionRoomWork *unisys, void *fieldmap, u32 msgId);
void UNION_MSG_SetupYesNo(UnionRoomWork *unisys, void *fieldmap);
void UNION_MSG_DeleteYesNo(UnionRoomWork *unisys);
int UNION_MSG_SelectYesNo(UnionRoomWork *unisys, u32 *isYes);
void UNION_MSG_SetupMenu(UnionRoomWork *unisys, void *fieldmap, const void *listData, u32 listCount, const void *menuHeader);
void UNION_MSG_DeleteMenu(UnionRoomWork *unisys);
int UNION_MSG_SelectMenu(UnionRoomWork *unisys, void *fieldmap);
void UNION_MSG_SetupMainMenu(UnionRoomWork *unisys, void *fieldmap);
void UNION_MSG_DeleteMainMenu(UnionRoomWork *unisys);
int UNION_MSG_SelectMainMenu(UnionRoomWork *unisys, void *fieldmap);
void UNION_MSG_SetupSubMenu(UnionRoomWork *unisys, void *fieldmap, int kind, u8 *arg);
void UNION_MSG_DeleteSubMenu(UnionRoomWork *unisys);
int UNION_MSG_SelectSubMenu(UnionRoomWork *unisys, int *hit, u8 *st, int *flag, void *fieldmap);
void UNION_MSG_SetupTitleWindow(UnionRoomWork *unisys, void *fieldmap);
void UNION_MSG_DeleteTitleWindow(UnionRoomWork *unisys);
void UNION_MSG_SetupRegulationWindow(UnionRoomWork *unisys, void *fieldmap, u32 failMask, int mode, int titleKind);
u32 UNION_MSG_CheckRegulationPrintEnd(UnionRoomWork *unisys, void *fieldmap);
void UNION_MSG_DeleteRegulationWindow(UnionRoomWork *unisys);
int UNION_ONESELF_IsPlayerAtReceptionSpot(void *arg);
int UNION_CHARA_GetGroupCategory(int status);
int UNION_CHARA_IsWifiFriendBeacon(void *wifiFriends, UnionBeaconPc *beaconPc);
/* END mkheaders: generated region */

#endif
