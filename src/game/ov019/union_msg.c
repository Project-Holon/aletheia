/*
 * file:     union_msg.c
 * unit:     yes
 * function: UNION_MSG_GetNoReplyMsg, UNION_MSG_GetTalkParentGreetingMsg, UNION_MSG_GetTalkParentCancelMsg, UNION_MSG_GetTalkChildBusyMsg, UNION_MSG_GetTalkParentAcceptMsg, UNION_MSG_GetTalkParentRefuseMsg, UNION_MSG_GetTalkChildOfferMsg, UNION_MSG_GetTalkChildDeclineMsg, UNION_MSG_GetTalkMenuPromptMsg, UNION_MSG_GetColosseumStartMsg, UNION_MSG_GetNotEnoughPokemonMsg, UNION_MSG_GetNoEggInPartyMsg, UNION_MSG_GetBadEggInPartyMsg, UNION_MSG_GetBadEggNoticeMsg, UNION_MSG_GetBattleChatMsg, UNION_MSG_GetPartnerBusyMsg, UNION_MSG_GetTrainerCardChatMsg, UNION_MSG_GetDrawChatMsg, UNION_MSG_GetTradeChatMsg, UNION_MSG_GetSpinTradeChatMsg, UNION_MSG_GetMultiBattleInviteMsg, UNION_MSG_GetSpinTradeInviteMsg, UNION_MSG_GetDrawInviteMsg, UNION_MSG_GetMultiBattleInviteDeclinedMsg, UNION_MSG_GetSpinTradeInviteDeclinedMsg, UNION_MSG_GetDrawInviteDeclinedMsg, UNION_MSG_GetSpinTradeNoEggMsg, UNION_MSG_GetSpinTradeBadEggMsg, UNION_MSG_GetSpinTradeWaitMsg, UNION_MSG_GetSpinTradeStartMsg, UNION_MSG_GetSpinTradeBusyMsg, UNION_MSG_GetDrawWaitMsg, UNION_MSG_GetDrawStartMsg, UNION_MSG_GetDrawBusyMsg, UNION_MSG_GetMultiBattleWaitMsg, UNION_MSG_GetMultiBattleStartMsg, UNION_MSG_GetMultiBattleBusyMsg, UNION_MSG_CheckLanguageVersion, UNION_MSG_RegisterPartnerWords, UNION_MSG_SetGreetingWordFlag, UNION_MSG_CreateWordSet, UNION_MSG_DeleteWordSet, UNION_MSG_GetCategoryTableValue, UNION_MSG_CloseAllWindows, UNION_MSG_SetupTalkWindow, UNION_MSG_DeleteTalkWindow, UNION_MSG_PrintTalkMsg, UNION_MSG_CheckTalkPrintEnd, UNION_MSG_SetupPrintTalkMsg, UNION_MSG_SetupYesNo, UNION_MSG_DeleteYesNo, UNION_MSG_SelectYesNo, UNION_MSG_SetupMenu, UNION_MSG_DeleteMenu, UNION_MSG_SelectMenu, UNION_MSG_SetupMainMenu, UNION_MSG_DeleteMainMenu, UNION_MSG_SelectMainMenu, UNION_MSG_SetupSubMenu, UNION_MSG_DeleteSubMenu, UNION_MSG_SelectSubMenu, UNION_MSG_SetupTitleWindow, UNION_MSG_DeleteTitleWindow, UNION_MSG_SetupRegulationWindow, UNION_MSG_CheckRegulationPrintEnd, UNION_MSG_DeleteRegulationWindow, UNION_ONESELF_IsPlayerAtReceptionSpot, UNION_CHARA_GetGroupCategory, UNION_CHARA_IsWifiFriendBeacon
 * address:  0x0217EC04
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   SAVEDATA_PanicFail  0x02034714  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   func_020084F4  0x020084F4  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   d_0218031C 0x0218031C data a2
 *   d_0218034C  0x0218034C  data a2
 *   d_02180330  0x02180330  data a2
 *   d_02180348  0x02180348  data a2
 *   d_021805E4 0x021805E4 data a2
 *   d_02180648  0x02180648  data a2
 *   d_0218053C  0x0218053C  data a2
 *   d_02180570  0x02180570  data a2
 *   d_02180300  0x02180300  data a2
 *   d_0218032C  0x0218032C  data a2
 *   d_02180320  0x02180320  data a2
 *   d_02180318  0x02180318  data a2
 *   d_02180328 0x02180328 data a2
 *   d_02180324 0x02180324 data a2
 *   func_020056EC 0x020056EC thumb
 *   d_02180380 0x02180380 data a2
 *   d_0218033C  0x0218033C  data a2
 *   d_02180368 0x02180368 data a2
 *   d_02180370 0x02180370 data a2
 *   d_02180360 0x02180360 data a2
 *   d_02180390     0x02180390  data  a2
 *   d_02180314  0x02180314  data a2
 *   d_02180310  0x02180310  data a2
 *   d_02180340  0x02180340  data a2
 *   d_02180304  0x02180304  data a2
 *   d_02180308  0x02180308  data a2
 *   d_02180344  0x02180344  data a2
 *   d_02180350  0x02180350  data a2
 *   d_02180338  0x02180338  data a2
 *   d_0218035C  0x0218035C  data a2
 *   d_02180358  0x02180358  data a2
 *   d_02180354  0x02180354  data a2
 *   d_021802F8  0x021802F8  data a2
 *   d_021802F0  0x021802F0  data a2
 *   d_021802F4  0x021802F4  data a2
 *   d_02180334  0x02180334  data a2
 *   d_0218030C  0x0218030C  data a2
 *   d_021802FC  0x021802FC  data a2
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetString  0x02045924  arm
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   WORDSET_SetSlotFromMsgE7  0x0201F048  thumb
 *   WORDSET_DeleteMsgdataF094  0x0201F094  thumb
 *   d_021807F8     0x021807F8  data  a1
 *   PMS_WORD_GetSaveData  0x02024988  thumb
 *   PMS_WORD_SetFlag  0x020249A0  thumb
 *   d_0218044C     0x0218044C  data
 *   WORDSET_Create 0x0201EC74 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   d_021806AC 0x021806AC data a1
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_CreatePlainWin  0x02191558  thumb  ov021
 *   FIELD_MSGBG_ClearPlainWin  0x021915EC  thumb  ov021
 *   FIELD_MSGBG_OpenPlainWin  0x0219160C  thumb  ov021
 *   FIELD_MSGBG_DeletePlainWin  0x021915B4  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgData  0x021904C8  thumb  ov021
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   FIELD_MSGBG_PlainWinPrintStream  0x021916A8  thumb  ov021
 *   FIELD_MSGBG_PlainWinMain 0x021916E0 thumb ov021
 *   FIELD_MSGBG_CreateYesNoMenu 0x02190BE4 thumb ov021
 *   FIELD_MSGBG_DeleteMenuFunc 0x021909BC thumb ov021
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb  ov021
 *   FIELD_MSGBG_CreateMenuItemsFromTable  0x02190A28  thumb  ov021
 *   FIELD_MSGBG_CreateMenuFuncWork  0x02190988  thumb  ov021
 *   FIELD_MSGBG_IsPrintQueFinished  0x0219049C  thumb  ov021
 *   FIELD_MSGBG_MenuFuncMain  0x021909E4  thumb  ov021
 *   d_0218042C 0x0218042C data a4
 *   d_021804DC 0x021804DC data a4
 *   d_0218046C     0x0218046C  data  a4
 *   d_021805A4     0x021805A4  data  a4
 *   d_021807FC     0x021807FC  data  a1
 *   d_0218050C     0x0218050C  data  a4
 *   d_021804B4     0x021804B4  data  a4
 *   d_021803A0     0x021803A0  data  ov019  a1
 *   FIELD_MSGBG_PlainWinPrintMsg  0x0219161C  thumb  ov021
 *   POKE_REGULATION_CreateText  0x0201A4D4  thumb
 *   REGULATION_CreateCupName  0x0200AE3C  thumb
 *   FIELD_MSGBG_PlainWinPrintStr  0x02191648  thumb  ov021
 *   FIELD_MSGBG_PlainWinPrintStrColor  0x02191674  thumb  ov021
 *   FIELD_MSGBG_GetPrintQue 0x021904A8 thumb ov021
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   POKE_REGULATION_DeleteText 0x0201A570 thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   GAME_DATA_GetPlayerDirection  0x02012AD0  thumb
 *   d_02180718     0x02180718  data   ov019 a4
 *   func_02009D50 0x02009D50 thumb
 *   ARC_TOOL_CreateHandle   0x020490F4  arm
 *   SAVEDATA_PanicFail   0x02034714  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   UNION_ONESELF_TalkParentMain  0x0217C2AC  thumb  ov019
 *   UNION_ONESELF_TalkChildMain  0x0217C5A8  thumb  ov019
 *   UNION_ONESELF_BattleMenuMain  0x0217C88C  thumb  ov019
 *   UNION_ONESELF_TalkPlayingChildMain  0x0217CEB8  thumb  ov019
 *   UNION_ONESELF_ColosseumEnterParentMain  0x0217D7A4  thumb  ov019
 *   UNION_ONESELF_ColosseumEnterChildMain  0x0217D890  thumb  ov019
 */
struct WordSet;
struct MsgBank;
struct U16Vec;
struct Handle;
struct VecFx32;
#include "../ov021/field_msgbg_types.h"
#include "../ov012/union_comm_types.h"

#ifndef NULL
#define NULL ((void *)0)
#endif



/* One entry of a menu list table: message id and the value the menu returns. */
typedef struct UnionMenuItem {
    u32 msgId;
    u32 value;
} UnionMenuItem;

/* One submenu definition (8 bytes): its item table and the item count. */
typedef struct UnionSubMenuDef {
    const UnionMenuItem *items;
    u8 itemCount;
    u8 pad05[3];                   /* alignment of the 8-byte table entry */
} UnionSubMenuDef;

/* A tile position in the field. */
typedef struct UnionTilePos {
    s16 x;
    s16 z;
} UnionTilePos;

extern void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, const void *site, unsigned short tag);
extern void *GAME_DATA_GetSaveControl(void *p);
extern u32 GFL_HEAP_Free(void *p);
void SAVEDATA_PanicFail(const void *expr, u32 line, const void *file);
extern void MI_CpuCopy8(const void *a, void *b, int c);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u8 func_02008550(const void *obj);
extern void *FIELDMAP_GetFieldPlayer(void *p);
const void *func_020084F4(const void *p);
void WORDSET_SetSlotMyStatus(void *p, u32 i, void *a);
extern u32 func_020056EC(u32 v);
extern u8 func_0200856C(const void *obj);
extern u8 func_02008570(const void *obj);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_SetString(void *o, const void *src);
extern void WORDSET_SetSlotTag(void *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void STRBUF_Delete(void *vec);
extern void *MSGDATA_AllocString(void *bank, u32 index);
extern void WORDSET_SetSlotFromMsgE7(void *p, u32 i, u32 n);
extern void WORDSET_DeleteMsgdataF094(void *p, u32 i, u32 a, u32 n);
extern void *PMS_WORD_GetSaveData(int a0);
extern void PMS_WORD_SetFlag(void *p, int bit);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern u32 WORDSET_DeleteStrbufED04(void *p);
extern unsigned int FIELDMAP_GetMsgBg(void *p);
extern int FIELD_MSGBG_CreateMsgData(u32 a, u32 b);
extern void *FIELD_MSGBG_CreatePlainWin(void *a, u32 b, u32 c, u16 d, u16 e, u16 f, u16 g);
extern void FIELD_MSGBG_ClearPlainWin(void *r);
extern void FIELD_MSGBG_OpenPlainWin(void *p);
extern int FIELD_MSGBG_DeletePlainWin(void *a);
extern u32 FIELD_MSGBG_DeleteMsgData(void *a0);
extern void MSGDATA_ReadString(void *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(void *ws, void *dst, void *src);
extern void FIELD_MSGBG_PlainWinPrintStream(void *r, u32 b, u16 c, u32 d);
extern u32 FIELD_MSGBG_PlainWinMain(void *p);
extern u32 *FIELD_MSGBG_CreateYesNoMenu(void *a, u32 b);
extern int FIELD_MSGBG_DeleteMenuFunc(void *a);
extern int FIELD_MSGBG_YesNoMenuMain(void *h);
extern u32 FIELD_MSGBG_CreateMenuItemsFromTable(const void *arr, int n, u32 c, u16 d);
extern struct Handle *FIELD_MSGBG_CreateMenuFuncWork(void *a, const void *b, u32 c, u32 d, u32 x, u16 y, u16 z, u32 w);
extern int FIELD_MSGBG_IsPrintQueFinished(void *p);
extern int FIELD_MSGBG_MenuFuncMain(void *h);
extern void FIELD_MSGBG_PlainWinPrintMsg(void *r, int b, int c, u32 d);
extern u8 *POKE_REGULATION_CreateText(void *a0, u32 a1, u16 a2, u32 a3);
extern void *REGULATION_CreateCupName(void *p, u32 heap);
extern void FIELD_MSGBG_PlainWinPrintStr(void *r, int b, int c, u32 d);
extern void  FIELD_MSGBG_PlainWinPrintStrColor(void *a, int b, u16 c, u32 d, int e);
extern u32 FIELD_MSGBG_GetPrintQue(void *p);
extern u32 PRINTSYS_QUE_IsFinished(const void *p);
extern void POKE_REGULATION_DeleteText(void *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern u8 *GAMESYSTEM_GetMyPlayerWork(const void *p);
extern void FIELD_PLAYER_GetPos(void *a, void *v);
extern u16 GAME_DATA_GetPlayerDirection(const void *p);
extern int func_02009D50(void *obj, const void *unused, u32 id, u32 kind, void *out);
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
void UNION_MSG_SetGreetingWordFlag(int gameData, unsigned int language);
void UNION_MSG_CreateWordSet(UnionRoomWork *unisys);
void UNION_MSG_DeleteWordSet(UnionRoomWork *unisys);
int UNION_MSG_GetCategoryTableValue(int i);
void UNION_MSG_CloseAllWindows(UnionRoomWork *unisys);
void UNION_MSG_SetupTalkWindow(UnionRoomWork *unisys, u8 *fieldmap);
void UNION_MSG_DeleteTalkWindow(UnionRoomWork *unisys);
void UNION_MSG_PrintTalkMsg(UnionRoomWork *unisys, u32 msgId);
u32 UNION_MSG_CheckTalkPrintEnd(UnionRoomWork *unisys);
void UNION_MSG_SetupPrintTalkMsg(UnionRoomWork *unisys, u8 *fieldmap, u32 msgId);
void UNION_MSG_SetupYesNo(UnionRoomWork *unisys, u32 fieldmap);
void UNION_MSG_DeleteYesNo(UnionRoomWork *unisys);
int UNION_MSG_SelectYesNo(UnionRoomWork *unisys, u32 *isYes);
void UNION_MSG_SetupMenu(UnionRoomWork *unisys, u32 fieldmap, u32 listData, u32 listCount, u32 menuHeader);
void UNION_MSG_DeleteMenu(UnionRoomWork *unisys);
int UNION_MSG_SelectMenu(UnionRoomWork *unisys, u32 fieldmap);
void UNION_MSG_SetupMainMenu(UnionRoomWork *unisys, u32 fieldmap);
void UNION_MSG_DeleteMainMenu(UnionRoomWork *unisys);
int UNION_MSG_SelectMainMenu(UnionRoomWork *unisys, int fieldmap);
void UNION_MSG_SetupSubMenu(UnionRoomWork *unisys, int fieldmap, int kind, u8 *arg);
void UNION_MSG_DeleteSubMenu(UnionRoomWork *unisys);
int UNION_MSG_SelectSubMenu(UnionRoomWork *unisys, int *hit, u8 *st, int *flag, u32 fieldmap);
void UNION_MSG_SetupTitleWindow(UnionRoomWork *unisys, u32 fieldmap);
void UNION_MSG_DeleteTitleWindow(UnionRoomWork *unisys);
void UNION_MSG_SetupRegulationWindow(UnionRoomWork *unisys, u32 fieldmap, u32 failMask, int mode, int titleKind);
u32 UNION_MSG_CheckRegulationPrintEnd(UnionRoomWork *unisys, u32 fieldmap);
void UNION_MSG_DeleteRegulationWindow(UnionRoomWork *unisys);
int UNION_ONESELF_IsPlayerAtReceptionSpot(u32 arg);
int UNION_CHARA_GetGroupCategory(int status);
int UNION_CHARA_IsWifiFriendBeacon(void *wifiFriends, UnionBeaconPc *beaconPc);
extern const u16 d_0218031C[];
extern const u16 d_0218034C[];
extern const u16 d_02180330[];
extern const u16 d_02180348[];
extern const u16 d_021805E4[][2];
extern const u16 d_02180648[][2];
extern const u16 d_0218053C[];
extern const u16 d_02180570[];
extern const u16 d_02180300[];
extern const u16 d_0218032C[];
extern const u16 d_02180320[];
extern const u16 d_02180318[];
extern const u16 d_02180328[];
extern const u16 d_02180324[];
extern const u16 d_02180380[][2];
extern const u16 d_0218033C[];
extern const u16 d_02180368[][2];
extern const u16 d_02180370[][2];
extern const u16 d_02180360[][2];
extern const u16 d_02180390[][2];
extern const u16 d_02180314[];
extern const u16 d_02180310[];
extern const u16 d_02180340[];
extern const u16 d_02180304[];
extern const u16 d_02180308[];
extern const u16 d_02180344[];
extern const u16 d_02180350[];
extern const u16 d_02180338[];
extern const u16 d_0218035C[];
extern const u16 d_02180358[];
extern const u16 d_02180354[];
extern const u16 d_021802F8[];
extern const u16 d_021802F0[];
extern const u16 d_021802F4[];
extern const u16 d_02180334[];
extern const u16 d_0218030C[];
extern const u16 d_021802FC[];
extern const char d_021807F8[];
extern int d_0218044C[];
extern const u8 d_021806AC[][4];
extern const u32 d_0218042C[];
extern const u32 d_021804DC[];
extern const FieldMenuHeader d_0218046C;
extern const UnionSubMenuDef d_021805A4[];
extern const char d_021807FC[];
extern const u32  d_0218050C[];
extern const u32  d_021804B4[];
extern const u8  d_021803A0[][2][2];
extern const UnionTilePos d_02180718[];


u16 UNION_MSG_GetNoReplyMsg(void ***ctx)
{
    return d_0218031C[func_02008550(**ctx)];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from UNION_ONESELF_TalkParentMain.
 */
u16 UNION_MSG_GetTalkParentGreetingMsg(int i)
{
    return d_0218034C[i];
}


u16 UNION_MSG_GetTalkParentCancelMsg(int i)
{
    return d_02180330[i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from UNION_ONESELF_TalkChildMain.
 */
u16 UNION_MSG_GetTalkChildBusyMsg(int i)
{
    return d_02180348[i];
}


u16 UNION_MSG_GetTalkParentAcceptMsg(int i, int j)
{
    return d_021805E4[i - 2][j];
}


u16 UNION_MSG_GetTalkParentRefuseMsg(int i, int j)
{
    return d_02180648[i - 2][j];
}


u16 UNION_MSG_GetTalkChildOfferMsg(int i)
{
    return d_0218053C[i - 2];
}


u16 UNION_MSG_GetTalkChildDeclineMsg(int i)
{
    return d_02180570[i - 2];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from UNION_ONESELF_TalkParentMain and UNION_ONESELF_BattleMenuMain.
 */
u16 UNION_MSG_GetTalkMenuPromptMsg(int i)
{
    return d_02180300[i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from UNION_ONESELF_ColosseumEnterParentMain / UNION_ONESELF_ColosseumEnterChildMain.
 */
u16 UNION_MSG_GetColosseumStartMsg(int i)
{
    return d_0218032C[i];
}


u16 UNION_MSG_GetNotEnoughPokemonMsg(int i)
{
    return d_02180320[i];
}


u16 UNION_MSG_GetNoEggInPartyMsg(int i)
{
    return d_02180318[i];
}


u16 UNION_MSG_GetBadEggInPartyMsg(void ***ctx)
{
    return d_02180328[func_02008550(**ctx)];
}


u16 UNION_MSG_GetBadEggNoticeMsg(void ***ctx)
{
    return d_02180324[func_02008550(**ctx)];
}


/*
 * Extent follower UNION_MSG_GetPartnerBusyMsg is already filed separately.
 */
u16 UNION_MSG_GetBattleChatMsg(int i)
{
    return d_02180380[func_020056EC(4)][i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from UNION_ONESELF_TalkPlayingChildMain.
 */
u16 UNION_MSG_GetPartnerBusyMsg(int i)
{
    return d_0218033C[i];
}


u16 UNION_MSG_GetTrainerCardChatMsg(int i)
{
    return d_02180368[func_020056EC(2)][i];
}


u16 UNION_MSG_GetDrawChatMsg(int i)
{
    return d_02180370[func_020056EC(4)][i];
}


u16 UNION_MSG_GetTradeChatMsg(int i)
{
    return d_02180360[func_020056EC(2)][i];
}


u16 UNION_MSG_GetSpinTradeChatMsg(int i)
{
    return d_02180390[func_020056EC(4)][i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run)
 * inside the listing extent of UNION_MSG_GetSpinTradeChatMsg.
 */
u16 UNION_MSG_GetMultiBattleInviteMsg(int i)
{
    return d_02180314[i];
}


u16 UNION_MSG_GetSpinTradeInviteMsg(int i)
{
    return d_02180310[i];
}


u16 UNION_MSG_GetDrawInviteMsg(int i)
{
    return d_02180340[i];
}


u16 UNION_MSG_GetMultiBattleInviteDeclinedMsg(int i)
{
    return d_02180304[i];
}


u16 UNION_MSG_GetSpinTradeInviteDeclinedMsg(int i)
{
    return d_02180308[i];
}


u16 UNION_MSG_GetDrawInviteDeclinedMsg(int i)
{
    return d_02180344[i];
}


u16 UNION_MSG_GetSpinTradeNoEggMsg(int i)
{
    return d_02180350[i];
}


u16 UNION_MSG_GetSpinTradeBadEggMsg(int i)
{
    return d_02180338[i];
}


u16 UNION_MSG_GetSpinTradeWaitMsg(int i)
{
    return d_0218035C[i];
}


u16 UNION_MSG_GetSpinTradeStartMsg(int i)
{
    return d_02180358[i];
}


u16 UNION_MSG_GetSpinTradeBusyMsg(int i)
{
    return d_02180354[i];
}


u16 UNION_MSG_GetDrawWaitMsg(int i)
{
    return d_021802F8[i];
}


u16 UNION_MSG_GetDrawStartMsg(int i)
{
    return d_021802F0[i];
}


u16 UNION_MSG_GetDrawBusyMsg(int i)
{
    return d_021802F4[i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run)
 * inside the listing extent of UNION_MSG_GetSpinTradeChatMsg.
 */
u16 UNION_MSG_GetMultiBattleWaitMsg(int i)
{
    return d_02180334[i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from UNION_ONESELF_ColosseumEnterChildMain.
 */
u16 UNION_MSG_GetMultiBattleStartMsg(int i)
{
    return d_0218030C[i];
}


u16 UNION_MSG_GetMultiBattleBusyMsg(int i)
{
    return d_021802FC[i];
}


int UNION_MSG_CheckLanguageVersion(UnionRoomWork *unisys, int language, int version)
{
    int myStatus = (int)GAME_DATA_GetMyStatus((void *)unisys->parent->gameData);
    int myLanguage = func_0200856C((const void *)myStatus);
    int myVersion = func_02008570((const void *)myStatus);

    if (language == 0)
        return 15;
    if (myLanguage != language) {
        if (version == 0)
            return 13;
        return 12;
    }
    if (version == 0 || myVersion == version)
        return 15;
    return 14;
}


void UNION_MSG_RegisterPartnerWords(UnionRoomWork *unisys)
{
    void *greetingStr;
    void *nameStr;
    u32 myStatus;
    u16 *nameChars;
    UnionMySituation *situation = &unisys->mySituation;
    int language;
    u8 sex;
    int greetingMsgId;
    const UnionBeacon *partner;

    myStatus = (u32)unisys->parent->myStatus;
    if (unisys->msgWork.msgData == 0)
        SAVEDATA_PanicFail(d_021807F8, 0, d_021807F8);
    if (unisys->msgWork.wordSet == 0)
        SAVEDATA_PanicFail(d_021807F8, 0, d_021807F8);

    partner = situation->connect.talkParam;
    if (partner != 0) {
        nameChars = (u16 *)partner->name;
        language = partner->language;
        sex = partner->sex;
    } else {
        nameChars = (u16 *)func_020084F4((const void *)myStatus);
        language = 2;
        sex = (int)func_02008550((const void *)myStatus);
    }
    nameStr = STRBUF_Create(0x20, UNION_HEAP_ID);
    STRBUF_SetString(nameStr, nameChars);
    WORDSET_SetSlotTag(unisys->msgWork.wordSet, 0, nameStr, sex, 1, language);
    STRBUF_Delete(nameStr);
    WORDSET_SetSlotMyStatus(unisys->msgWork.wordSet, 1, (void *)myStatus);

    switch (language) {
    case 1: greetingMsgId = 0xe7; break;
    case 2: greetingMsgId = 0xe8; break;
    case 3: greetingMsgId = 0xe9; break;
    case 4: greetingMsgId = 0xea; break;
    case 5: greetingMsgId = 0xeb; break;
    case 7: greetingMsgId = 0xec; break;
    case 8: greetingMsgId = 0xee; break;
    default: greetingMsgId = 0xed; break;
    }
    greetingStr = MSGDATA_AllocString(unisys->msgWork.msgData, greetingMsgId);
    WORDSET_SetSlotTag(unisys->msgWork.wordSet, 2, greetingStr, sex, 1, language);
    STRBUF_Delete(greetingStr);

    if (situation->connect.talkParam != 0 && situation->connect.talkParam->nation != 0) {
        WORDSET_SetSlotFromMsgE7(unisys->msgWork.wordSet, 3, situation->connect.talkParam->nation);
        if (situation->connect.talkParam->area != 0)
            WORDSET_DeleteMsgdataF094(unisys->msgWork.wordSet, 4, situation->connect.talkParam->nation, situation->connect.talkParam->area);
    }
    UNION_MSG_SetGreetingWordFlag((int)unisys->parent->gameData, language);
}


void UNION_MSG_SetGreetingWordFlag(int gameData, unsigned int language)
{
    int pmsWordSave;
    unsigned short langIndex;

    pmsWordSave = (int)PMS_WORD_GetSaveData((int)GAME_DATA_GetSaveControl((void *)gameData));
    langIndex = language - 1;
    if (language >= 1 && language <= 8) {
        if (langIndex < 8) {
            PMS_WORD_SetFlag((int *)pmsWordSave, d_0218044C[langIndex]);
            return;
        }
        PMS_WORD_SetFlag((int *)pmsWordSave, 7);
        return;
    }
    PMS_WORD_SetFlag((int *)pmsWordSave, 7);
}


void UNION_MSG_CreateWordSet(UnionRoomWork *unisys)
{
    if (unisys->msgWork.wordSet == 0) {
        unisys->msgWork.wordSet = WORDSET_Create(5, 0x40, UNION_HEAP_ID);
        UNION_MSG_RegisterPartnerWords(unisys);
    }
}


void UNION_MSG_DeleteWordSet(UnionRoomWork *unisys)
{
    if (unisys->msgWork.wordSet != 0) {
        WORDSET_DeleteStrbufED04(unisys->msgWork.wordSet);
        unisys->msgWork.wordSet = 0;
    }
}


int UNION_MSG_GetCategoryTableValue(int i)
{
    if (i >= 27) return 0;
    return d_021806AC[i][0];
}


void UNION_MSG_CloseAllWindows(UnionRoomWork *unisys)
{
    UNION_MSG_DeleteRegulationWindow(unisys);
    UNION_MSG_DeleteTitleWindow(unisys);
    UNION_MSG_DeleteYesNo(unisys);
    UNION_MSG_DeleteMenu(unisys);
    UNION_MSG_DeleteTalkWindow(unisys);
}


void UNION_MSG_SetupTalkWindow(UnionRoomWork *unisys, u8 *fieldmap)
{
    int fieldMsgBg;

    if (unisys->msgWork.talkWin == 0) {
        if (unisys->msgWork.msgData != 0)
            SAVEDATA_PanicFail((const char *)d_021807F8, 0, (const char *)d_021807F8);
        fieldMsgBg = FIELDMAP_GetMsgBg(fieldmap);
        unisys->msgWork.msgData = (struct MsgBank *)FIELD_MSGBG_CreateMsgData(fieldMsgBg, 200);
        unisys->msgWork.strTemp = (struct Strbuf *)STRBUF_Create(0x100, UNION_HEAP_ID);
        unisys->msgWork.strExpand = (struct Strbuf *)STRBUF_Create(0x100, UNION_HEAP_ID);
        UNION_MSG_CreateWordSet(unisys);
        unisys->msgWork.talkWin = FIELD_MSGBG_CreatePlainWin((void *)fieldMsgBg, (u32)unisys->msgWork.msgData, 0, 1, 0x13, 0x1e, 4);
    } else {
        FIELD_MSGBG_ClearPlainWin(unisys->msgWork.talkWin);
    }
}


void UNION_MSG_DeleteTalkWindow(UnionRoomWork *unisys)
{
    if (unisys->msgWork.talkWin != 0) {
        FIELD_MSGBG_OpenPlainWin(unisys->msgWork.talkWin);
        FIELD_MSGBG_DeletePlainWin(unisys->msgWork.talkWin);
        unisys->msgWork.talkWin = 0;
        unisys->msgTalkPrinting = 0;
        STRBUF_Delete(unisys->msgWork.strTemp);
        STRBUF_Delete(unisys->msgWork.strExpand);
        unisys->msgWork.strTemp = 0;
        unisys->msgWork.strExpand = 0;
    }
    if (unisys->msgWork.msgData != 0) {
        UNION_MSG_DeleteWordSet(unisys);
        FIELD_MSGBG_DeleteMsgData(unisys->msgWork.msgData);
        unisys->msgWork.msgData = 0;
    }
}


void UNION_MSG_PrintTalkMsg(UnionRoomWork *unisys, u32 msgId)
{
    if (unisys->msgWork.talkWin == 0) {
        SAVEDATA_PanicFail((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    MSGDATA_ReadString(unisys->msgWork.msgData, msgId, unisys->msgWork.strTemp);
    WORDSET_CopyTaggedText(unisys->msgWork.wordSet, unisys->msgWork.strExpand, unisys->msgWork.strTemp);
    FIELD_MSGBG_PlainWinPrintStream(unisys->msgWork.talkWin, 0, 0, (u32)unisys->msgWork.strExpand);
    unisys->msgTalkPrinting = 1;
}


u32 UNION_MSG_CheckTalkPrintEnd(UnionRoomWork *unisys)
{
    if (unisys->msgWork.talkWin == 0 || unisys->msgTalkPrinting == 0)
        return 1;
    return FIELD_MSGBG_PlainWinMain(unisys->msgWork.talkWin);
}


void UNION_MSG_SetupPrintTalkMsg(UnionRoomWork *unisys, u8 *fieldmap, u32 msgId)
{
    UNION_MSG_SetupTalkWindow(unisys, fieldmap);
    UNION_MSG_RegisterPartnerWords(unisys);
    UNION_MSG_PrintTalkMsg(unisys, msgId);
}


void UNION_MSG_SetupYesNo(UnionRoomWork *unisys, u32 fieldmap)
{
    if (unisys->msgWork.yesNo == 0) {
        unisys->msgWork.yesNo = FIELD_MSGBG_CreateYesNoMenu((u16 *)FIELDMAP_GetMsgBg((u8 *)fieldmap), 0);
    }
}


void UNION_MSG_DeleteYesNo(UnionRoomWork *unisys)
{
    if (unisys->msgWork.yesNo != 0) {
        FIELD_MSGBG_DeleteMenuFunc(unisys->msgWork.yesNo);
        unisys->msgWork.yesNo = 0;
    }
}


int UNION_MSG_SelectYesNo(UnionRoomWork *unisys, u32 *isYes)
{
    int result;

    if (unisys->msgWork.yesNo == 0) {
        SAVEDATA_PanicFail((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    result = FIELD_MSGBG_YesNoMenuMain(unisys->msgWork.yesNo);
    if (result == 2) {
        return 0;
    }
    *isYes = (result == 0) ? 1 : 0;
    return 1;
}


void UNION_MSG_SetupMenu(UnionRoomWork *unisys, u32 fieldmap, u32 listData, u32 listCount, u32 menuHeader)
{
    u32 fieldMsgBg = FIELDMAP_GetMsgBg((u8 *)fieldmap);

    if (unisys->msgWork.menu == 0) {
        u32 menuList = FIELD_MSGBG_CreateMenuItemsFromTable((const UnionMenuItem *)listData, listCount, (u32)unisys->msgWork.msgData, UNION_HEAP_ID);
        unisys->msgWork.menu = FIELD_MSGBG_CreateMenuFuncWork((u16 *)fieldMsgBg, (const u8 *)menuHeader, menuList, 0, 0, 0, 0, 1);
    }
}


void UNION_MSG_DeleteMenu(UnionRoomWork *unisys)
{
    if (unisys->msgWork.menu != 0) {
        FIELD_MSGBG_DeleteMenuFunc(unisys->msgWork.menu);
        unisys->msgWork.menu = 0;
    }
}


int UNION_MSG_SelectMenu(UnionRoomWork *unisys, u32 fieldmap)
{
    u32 fieldMsgBg = FIELDMAP_GetMsgBg((u8 *)fieldmap);

    if (fieldMsgBg == 0) {
        SAVEDATA_PanicFail((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    if (fieldMsgBg != 0 && FIELD_MSGBG_IsPrintQueFinished((u8 *)fieldMsgBg) == 0) {
        return -1;
    }
    if (unisys->msgWork.menu == 0) {
        SAVEDATA_PanicFail((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    return FIELD_MSGBG_MenuFuncMain(unisys->msgWork.menu);
}


void UNION_MSG_SetupMainMenu(UnionRoomWork *unisys, u32 fieldmap)
{
    UNION_MSG_SetupMenu(unisys, fieldmap, (u32)d_021804DC, 6, (u32)d_0218042C);
}


void UNION_MSG_DeleteMainMenu(UnionRoomWork *unisys)
{
    UNION_MSG_DeleteMenu(unisys);
}


/*
 * Unlabelled tail-call thunk (ldr r3 / bx r3, no push); called from
 * UNION_ONESELF_TalkParentMain.
 */
int UNION_MSG_SelectMainMenu(UnionRoomWork *unisys, int fieldmap)
{
    return UNION_MSG_SelectMenu(unisys, fieldmap);
}


void UNION_MSG_SetupSubMenu(UnionRoomWork *unisys, int fieldmap, int kind, u8 *arg)
{
    FieldMenuHeader t;
    u8 v;
    u32 *obj;

    arg[3] = kind;
    t = d_0218046C;
    v = d_021805A4[kind].itemCount;
    t.itemCount = v;
    t.maxLines = v;
    t.height = t.itemCount << 1;
    if (kind == 1 || kind == 5)
        t.width = 0x1e;
    if (kind >= 5)
        t.posY = 5;

    if (kind == 1) {
        obj = GFL_HEAP_Alloc(0x41, 0x30, 1, d_021807FC, 0x647);
        MI_CpuCopy8(d_0218050C, obj, 0x30);
        obj[0] = arg[0] + 0xff;
        obj[2] = arg[1] + 0x104;
        obj[4] = arg[2] + 0x106;
        UNION_MSG_SetupMenu(unisys, fieldmap, (u32)obj, v, (u32)(&t));
        GFL_HEAP_Free(obj);
    } else if (kind == 5) {
        obj = GFL_HEAP_Alloc(0x41, 0x28, 1, d_021807FC, 0x657);
        MI_CpuCopy8(d_021804B4, obj, 0x28);
        obj[0] = arg[1] + 0x104;
        obj[2] = arg[2] + 0x106;
        UNION_MSG_SetupMenu(unisys, fieldmap, (u32)obj, v, (u32)(&t));
        GFL_HEAP_Free(obj);
    } else {
        UNION_MSG_SetupMenu(unisys, fieldmap, (u32)d_021805A4[kind].items, v, (u32)(&t));
    }
}


/*
 * Unlabelled tail-call thunk (ldr r3 / bx r3, no push); called from
 * UNION_ONESELF_BattleMenuMain.
 */
void UNION_MSG_DeleteSubMenu(UnionRoomWork *unisys)
{
    UNION_MSG_DeleteMenu(unisys);
}


#pragma opt_propagation off


/*
 * note: final push 2026-10-05 G4L6. Case -2 reads the entry table by byte offset (off = st[3] * 8,
 *   set after the zero test) with opt_propagation off, so the table address stays one live value
 *   for the pair-pointer load (indexed) and the count byte (+4). Struct-index forms and the
 *   un-pragma'd forms propagate the address into each use (two pool words) or hoist the pool load.
 */
int UNION_MSG_SelectSubMenu(UnionRoomWork *unisys, int *hit, u8 *st, int *flag, u32 fieldmap)
{
    u32 key;
    u32 i;
    const UnionMenuItem *pairs;

    *hit = 0;
    *flag = 0;
    key = UNION_MSG_SelectMenu(unisys, fieldmap);
    switch (key) {
    case (u32)-1:
        return key;
    case (u32)-2: {
        u32 off;
        const u8 *base;
        if (st[3] == 0)
            return key;
        off = st[3] * 8;
        base = (const u8 *)d_021805A4;
        pairs = *(const UnionMenuItem * const *)(base + off);
        key = pairs[*(base + off + 4) - 1].value;
        break;
    }
    case 0x64:
        return d_021803A0[st[0]][st[1]][st[2]];
    case 0x96:
        *flag = 1;
        return d_021803A0[st[0]][st[1]][st[2]];
    }

    if (st[3] == 0) {
        if (key == (u32)d_0218050C) {
            if (st[0] == 4)
                st[0] = 0;
        } else if (key == (u32)d_021804B4) {
            st[0] = 4;
        }
    }

    for (i = 0; (i < 8) ? 1 : 0; i++) {
        if (d_021805A4[i].items == (const UnionMenuItem *)key) {
            *hit = 1;
            return i;
        }
        switch (st[3]) {
        case 0:
        case 1:
            break;
        case 2:
            if (key < 5) {
                st[0] = key;
                *hit = 1;
                return 1;
            }
            break;
        case 3:
        case 6:
            if (key < 2) {
                st[1] = key;
                *hit = 1;
                if (st[3] == 6)
                    return 5;
                return 1;
            }
            break;
        case 4:
        case 7:
            if (key < 2) {
                st[2] = key;
                *hit = 1;
                if (st[3] == 7)
                    return 5;
                return 1;
            }
            break;
        case 5:
            break;
        }
    }
    SAVEDATA_PanicFail((const char *)d_021807F8, 0, (const char *)d_021807F8);
    return 0;
}


#pragma opt_propagation reset


#pragma opt_propagation reset


void UNION_MSG_SetupTitleWindow(UnionRoomWork *unisys, u32 fieldmap)
{
    if (unisys->msgWork.infoWin == 0) {
        u32 infoWin = (u32)FIELD_MSGBG_CreatePlainWin((void *)FIELDMAP_GetMsgBg((u8 *)fieldmap), (u32)unisys->msgWork.msgData, 0, 1, 1, 0x1e, 2);
        unisys->msgWork.infoWin = (void *)infoWin;
        FIELD_MSGBG_PlainWinPrintMsg((void *)infoWin, 0, 0, 0x103);
    }
}


void UNION_MSG_DeleteTitleWindow(UnionRoomWork *unisys)
{
    if (unisys->msgWork.infoWin) {
        FIELD_MSGBG_DeletePlainWin(unisys->msgWork.infoWin);
        unisys->msgWork.infoWin = 0;
    }
}


/*
 * pass 4 2026-10-06 P4L11: closed. The palette value is assigned as a full
 * constant in each arm (pal = 0x1040 / 0x440). mwcc splits each constant into
 * movs + lsls #6 and merges the common shift at the join, which gives the same
 * stream as "pal = 0x41 / 0x11; pal <<= 6;" but a different pre-allocation
 * graph: self r5, h and pal r7, flag and tile temps r6 as in the original.
 * EXACT under --lang c99 and --lang c.
 */
void UNION_MSG_SetupRegulationWindow(UnionRoomWork *unisys, u32 fieldmap, u32 failMask, int mode, int titleKind)
{
    u32 fieldMsgBg = FIELDMAP_GetMsgBg((u8 *)fieldmap);
    void *title;
    long i;
    int flag;

    if (unisys->msgWork.wordSet == 0)
        SAVEDATA_PanicFail((const char *)d_021807F8, 0, (const char *)d_021807F8);
    if (unisys->msgWork.infoWin != 0)
        SAVEDATA_PanicFail((const char *)d_021807F8, 0, (const char *)d_021807F8);
    if (unisys->regulationText != 0)
        SAVEDATA_PanicFail((const char *)d_021807F8, 0, (const char *)d_021807F8);

    flag = 1;
    if (mode != 1)
        flag = 0;
    unisys->msgWork.infoWin = FIELD_MSGBG_CreatePlainWin((void *)fieldMsgBg, (u32)unisys->msgWork.msgData, 0, 1, 1, 0x1a, 0x10);
    unisys->regulationText = (UnionRegulationText *)POKE_REGULATION_CreateText(unisys->regulation, (u32)unisys->msgWork.wordSet, UNION_HEAP_ID, flag);
    UNION_MSG_RegisterPartnerWords(unisys);

    if (titleKind == 0) {
        title = REGULATION_CreateCupName(unisys->regulation, UNION_HEAP_ID);
        FIELD_MSGBG_PlainWinPrintStr(unisys->msgWork.infoWin, 0, 0, (u32)title);
        STRBUF_Delete(title);
    } else {
        FIELD_MSGBG_PlainWinPrintMsg(unisys->msgWork.infoWin, 0, 0, titleKind == 1 ? 0x14f : 0x150);
    }

    for (i = 0; i < 6; i++) {
        int pal;
        if (failMask & (1 << i)) {
            pal = 0x1040;
        } else {
            pal = 0x440;
        }
        FIELD_MSGBG_PlainWinPrintStrColor(unisys->msgWork.infoWin, 0, (i * 2 + 4) * 8, (u32)unisys->regulationText->label[i], pal);
        FIELD_MSGBG_PlainWinPrintStrColor(unisys->msgWork.infoWin, 0x70, (i * 2 + 4) * 8, (u32)unisys->regulationText->value[i], pal);
    }
}


u32 UNION_MSG_CheckRegulationPrintEnd(UnionRoomWork *unisys, u32 fieldmap)
{
    u32 printQue = FIELD_MSGBG_GetPrintQue((u32 *)FIELDMAP_GetMsgBg((u8 *)fieldmap));

    if (unisys->regulationText == 0)
        return 1;
    return PRINTSYS_QUE_IsFinished((void *)printQue);
}


void UNION_MSG_DeleteRegulationWindow(UnionRoomWork *unisys)
{
    if (unisys->regulationText) {
        FIELD_MSGBG_DeletePlainWin(unisys->msgWork.infoWin);
        unisys->msgWork.infoWin = 0;
        POKE_REGULATION_DeleteText(unisys->regulationText);
        unisys->regulationText = 0;
    }
}


int UNION_ONESELF_IsPlayerAtReceptionSpot(u32 arg)
{
    int v[3];
    u32 r4;
    void *h5;
    u32 i;
    int x, z;

    h5 = FIELDMAP_GetFieldPlayer((void *)arg);
    r4 = (u32)GAMESYSTEM_GetMyPlayerWork(FIELDMAP_GetGameSystem((void *)arg));
    FIELD_PLAYER_GetPos(h5, (struct VecFx32 *)v);
    v[0] = (v[0] >> 4) / 4096;
    v[2] = (v[2] >> 4) / 4096;
    GAME_DATA_GetPlayerDirection((const void *)r4);
    x = v[0];
    z = v[2];
    for (i = 0; i < 1; i++) {
        if (x == d_02180718[i].x && z == d_02180718[i].z) {
            return 1;
        }
    }
    return 0;
}


int UNION_CHARA_GetGroupCategory(int status)
{
    if (status >= 4 && status <= 23)
        return 1;
    switch (status) {
    case 3:
        return 4;
    case 24:
        return 2;
    case 25:
        return 5;
    case 26:
        return 3;
    default:
        return 0;
    }
}


int UNION_CHARA_IsWifiFriendBeacon(void *wifiFriends, UnionBeaconPc *beaconPc)
{
    u32 out;

    if (func_02009D50(wifiFriends, beaconPc->beacon.name, beaconPc->beacon.trainerId, beaconPc->beacon.sex, &out) == 1) {
        return 1;
    } else {
        return 0;
    }
}
