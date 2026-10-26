#ifndef GAME_OV021_IRCBATTLEMENU_H
#define GAME_OV021_IRCBATTLEMENU_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ircbattlemenu.c, prototypes copied from their definitions. */

struct IrcBattleWinDesc;
struct TcbTask;
struct ProcWork;
typedef struct IrcBattleWinDesc IrcBattleWinDesc;

#include "../ov021/ircbattlemenu_types.h"
#include "../ov021/ircbattlemenu_types.h"
#include "../types.h"
#include "../ov010/event_ircbattle_shared_types.h"

void IRCBATTLEMENU_StoreSeqFunc(IrcBattleMenuSeqFunc *dest, IrcBattleMenuSeqFunc seq);
void IRCBATTLEMENU_SetSeq(IrcBattleMenuWork *work, IrcBattleMenuSeqFunc seq, u32 line);
void IRCBATTLEMENU_InitBgLayers(IrcBattleMenuWork *work);
void IRCBATTLEMENU_FadePaletteBank(IrcBattleMenuWork *work, u32 bank, u32 rows);
void IRCBATTLEMENU_SetSubPaletteActive(IrcBattleMenuWork *work, int isActive);
void IRCBATTLEMENU_CreateTimeIcon(IrcBattleMenuWork *work);
void IRCBATTLEMENU_ClearMessageWindow(IrcBattleMenuWork *work);
void IRCBATTLEMENU_DeleteMsgWin(IrcBattleMenuWork *work);
void IRCBATTLEMENU_CreateButtonWindows(int count, u32 *msgIds, IrcBattleMenuWork *work, IrcBattleWinDesc *descs, int *centerX, int *centerY);
void IRCBATTLEMENU_DeleteButtonWindows(IrcBattleMenuWork *work);
void IRCBATTLEMENU_TouchCallback(u32 index, s32 event, void *);
void IRCBATTLEMENU_LoadMenuGraphics(IrcBattleMenuWork *work);
void IRCBATTLEMENU_LoadSubBgScreen(IrcBattleMenuWork *work, u32 screenId);
void IRCBATTLEMENU_SeqSetupTopMenu(IrcBattleMenuWork *work);
void IRCBATTLEMENU_FreeMenuGraphics(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqWaitFadeEnd(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqStartFadeOut(IrcBattleMenuWork *work);
void IRCBATTLEMENU_HookTopMenuPressed(void *param, u32 frame);
void IRCBATTLEMENU_SeqIdleTop(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqPressTopButton(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqWaitNotEnoughMsg(IrcBattleMenuWork *work);
int IRCBATTLEMENU_TouchTopMenu(u32 index, IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqUpdateTouchTop(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqSetupKindMenu(IrcBattleMenuWork *work);
void IRCBATTLEMENU_HookKindMenuPressed(void *param, u32 frame);
void IRCBATTLEMENU_SeqIdleKind(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqPressKindButton(IrcBattleMenuWork *work);
void IRCBATTLEMENU_HookKindBackPressed(void *param, u32 frame);
void IRCBATTLEMENU_SeqIdleKindBack(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqPressKindBack(IrcBattleMenuWork *work);
int IRCBATTLEMENU_TouchKindMenu(u32 index, IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqSetupRuleMenu(IrcBattleMenuWork *work);
void IRCBATTLEMENU_HookPartyMenuPressed(void *param, u32 frame);
void IRCBATTLEMENU_SeqIdleParty(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqPressPartyButton(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqUpdateTouchParty(IrcBattleMenuWork *work);
int IRCBATTLEMENU_TouchPartyMenu(u32 index, IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqSetupPartyMenu(IrcBattleMenuWork *work);
void IRCBATTLEMENU_HookRuleMenuPressed(void *param, u32 frame);
void IRCBATTLEMENU_SeqIdleRule(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqPressRuleButton(IrcBattleMenuWork *work);
int IRCBATTLEMENU_TouchRuleMenu(u32 index, IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqUpdateTouchSub(IrcBattleMenuWork *work);
void IRCBATTLEMENU_LoadActorResources(IrcBattleMenuWork *work);
void IRCBATTLEMENU_DeleteMenuActors(IrcBattleMenuWork *work);
void IRCBATTLEMENU_CreateTopMenuActors(IrcBattleMenuWork *work);
void IRCBATTLEMENU_CreateKindMenuActors(IrcBattleMenuWork *work);
void IRCBATTLEMENU_CreateMainMenuActors(IrcBattleMenuWork *work);
void IRCBATTLEMENU_CreateSubMenuActors(IrcBattleMenuWork *work);
void IRCBATTLEMENU_CreateDecoration(IrcBattleMenuWork *work, u32 posX, u32 posY, u32 index, u32 anim);
void IRCBATTLEMENU_DeleteClact(IrcBattleMenuWork *work);
void IRCBATTLEMENU_OpenYesNoMenu(IrcBattleMenuWork *work);
int IRCBATTLEMENU_IsMessageEnd(IrcBattleMenuWork *work);
void IRCBATTLEMENU_PrintMessage(IrcBattleMenuWork *work, u32 isInstant);
void IRCBATTLEMENU_SeqSaveQuestion(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqSaveMain(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqSaveStart(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqWaitTouchExit(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqSaveYesNo(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqSaveQuestionWait(IrcBattleMenuWork *work);
void IRCBATTLEMENU_VBlankTask(struct TcbTask *task, void *arg);
int IRCBATTLEMENU_Init(struct ProcWork *proc, u32 seq, IrcBattleEntryWork *param);
u32 IRCBATTLEMENU_Main(u32 proc, u32 seq, u32 param, IrcBattleMenuWork *work);
int IRCBATTLEMENU_Exit(struct ProcWork *proc, u32 seq, IrcBattleEntryWork *param, IrcBattleMenuWork *work);
/* END mkheaders: generated region */

#endif
