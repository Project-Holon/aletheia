#ifndef GAME_OV105_IRC_RESULT_H
#define GAME_OV105_IRC_RESULT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of irc_result.c, prototypes copied from their definitions. */

struct Proc;
struct ClactActor;
struct Unit;
struct TcbTask;

#include "../ov105/irc_result_types.h"
#include "../types.h"
#include "../ov102/irc_text_system_types.h"
#include "../ov104/irc_rhythm_types.h"
#include "../ov101/compatible_irc_sys_types.h"
#include "../ov101/compatible_irc_sys_types.h"

int IRC_RESULT_Init(struct Proc *proc,void *state,IrcResultContext *context);
int IRC_RESULT_Exit(struct Proc *proc,int unused1,int unused2,IrcResult *work);
int IRC_RESULT_Main(void *proc,u32 *state,void *unused,IrcResult *work);
void IRC_RESULT_InitScreen(IrcResultScreen *screen,u16 heapId);
void IRC_RESULT_ExitScreen(IrcResultScreen *screen);
void IRC_RESULT_DrawScreen(IrcResultScreen *screen);
struct ClactActor *IRC_RESULT_GetScreenActor(IrcResultScreen *screen, int index);
struct Unit *IRC_RESULT_GetScreenActorUnit(IrcResultScreen *screen);
void IRC_RESULT_ScreenVBlankTask(struct TcbTask *task, void *arg);
void IRC_RESULT_InitBackgrounds(IrcResultScreen *screen,u16 heapId);
void IRC_RESULT_ExitBackgrounds(u32 *bgCharRegion);
void IRC_RESULT_VBlankBackgrounds(void *unused);
void IRC_RESULT_InitActorSystem(IrcResultActorSystem *sys,const void *config,u16 heapId);
void IRC_RESULT_ExitActorSystem(IrcResultActorSystem *sys);
void IRC_RESULT_DrawActorSystem(void *unused);
void IRC_RESULT_VBlankActorSystem(void *unused);
struct ClactActor *IRC_RESULT_GetActor(IrcResultActorSystem *sys, int index);
struct Unit *IRC_RESULT_GetActorUnit(IrcResultActorSystem *sys);
void IRC_RESULT_InitTextSystem(IrcTextSystem *text, int fontStyle, u16 heapId);
void IRC_RESULT_ExitTextSystem(IrcTextSystem *text);
u32 IRC_RESULT_RunPrintQueue(IrcTextSystem *text);
void *IRC_RESULT_GetFont(IrcTextSystem *text);
void *IRC_RESULT_GetPrintQueue(IrcTextSystem *text);
void *IRC_RESULT_GetMessages(IrcTextSystem *text);
void *IRC_RESULT_GetWordSet(IrcTextSystem *text);
void IRC_RESULT_InitMessageWindow(IrcTextWindow *win, u32 layer, u32 x, u8 y, u8 width, u8 height, u8 paletteNo, u16 heapId);
void IRC_RESULT_InitTextWindow(IrcTextWindow *win,u32 layer,u32 x,u8 y,u8 width,u8 height,u8 paletteNo,u16 clearColor,u8 slot,u16 heapId);
void IRC_RESULT_ExitTextWindow(IrcTextWindow *win);
int IRC_RESULT_UpdateTextWindow(IrcTextWindow *win,IrcTextSystem *text);
void IRC_RESULT_PrintMessage(IrcTextWindow *win,IrcTextSystem *text,int msgId,int x,s16 y);
void IRC_RESULT_PrintCenteredMessage(IrcTextWindow *win,IrcTextSystem *text,int msgId);
void IRC_RESULT_PrintMessageWithNumber(IrcTextWindow *win, IrcTextSystem *text, u8 msgId, u16 number, u16 slot);
void IRC_RESULT_PrintMessageWithNames(IrcTextWindow *win, IrcTextSystem *text, int msgId, IrcCompatibleProfile *own, IrcCompatibleProfile *partner, int unused);
void IRC_RESULT_PrintRewardMessage(IrcTextWindow *win, IrcTextSystem *text, IrcCompatibleProfile *own, unsigned quantity, int msgId);
void IRC_RESULT_SetState(IrcResult *work, IrcResultStateFn fn);
void IRC_RESULT_Finish(IrcResult *work);
void IRC_RESULT_StateStart(IrcResult *work,u16 *step);
void IRC_RESULT_StateShowScore(IrcResult *work,u16 *step);
void IRC_RESULT_StateEnd(IrcResult *work,u16 *step);
void IRC_RESULT_InitScoreDisplay(IrcResultScoreDisplay *display,IrcResultScreen *screen,int score);
void IRC_RESULT_ShowDigit(IrcResultScoreDisplay *display, int i);
int IRC_RESULT_UpdateScoreDisplay(IrcResultScoreDisplay *display);
int IRC_RESULT_IsDigitShown(IrcResultScoreDisplay *display,int i);
void IRC_RESULT_SetScoreDigits(IrcResultScoreDisplay *display, unsigned score);
void IRC_RESULT_InitRankFade(IrcResultRankFade *fade,int id,int score,u16 heapId);
void IRC_RESULT_ExitRankFade(IrcResultRankFade *fade);
void IRC_RESULT_UpdateRankFade(IrcResultRankFade *fade);
void IRC_RESULT_StartRankFade(IrcResultRankFade *fade);
unsigned IRC_RESULT_IsRankFadeFinished(IrcResultRankFade *fade);
void IRC_RESULT_BlendPaletteEntry(u16 *color,int n,u8 div,u8 paletteBank,u8 colorIndex,u16 from,u16 to);
int IRC_RESULT_GetScoreRank(unsigned score, int *nearNextRank);
unsigned int IRC_RESULT_GetRewardQuantity(unsigned int score,int bonusDay);
int IRC_RESULT_GiveReward(IrcResult *work);
/* END mkheaders: generated region */

#endif
