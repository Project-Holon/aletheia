#ifndef GAME_OV104_IRC_RHYTHM_H
#define GAME_OV104_IRC_RHYTHM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of irc_rhythm.c, prototypes copied from their definitions. */

struct Proc;
struct ClactActor;
struct Unit;
struct TcbTask;

#include "../ov104/irc_rhythm_types.h"
#include "../types.h"
#include "../ov102/irc_text_system_types.h"
#include "../ov101/compatible_irc_sys_types.h"

int IRC_RHYTHM_Init(struct Proc *proc,void *state,IrcRhythmContext *context);
int IRC_RHYTHM_Exit(struct Proc *proc,int unused1,int unused2,IrcRhythm *work);
int IRC_RHYTHM_Main(void *proc,u32 *state,void *unused,IrcRhythm *work);
void IRC_RHYTHM_InitScreen(IrcScreen *screen,u16 heapId);
void IRC_RHYTHM_ExitScreen(IrcScreen *screen);
void IRC_RHYTHM_DrawScreen(IrcScreen *screen);
struct ClactActor *IRC_RHYTHM_GetScreenActor(IrcScreen *screen, int index);
struct Unit *IRC_RHYTHM_GetScreenActorUnit(IrcScreen *screen);
void IRC_RHYTHM_ScreenVBlankTask(struct TcbTask *task,void *arg);
void IRC_RHYTHM_InitBackgrounds(IrcScreen *screen,u16 heapId);
void IRC_RHYTHM_ExitBackgrounds(u32 *bgCharRegion);
void IRC_RHYTHM_VBlankBackgrounds(void *unused);
void IRC_RHYTHM_InitActorSystem(IrcActorSystem *sys,const void *config,u16 heapId);
void IRC_RHYTHM_ExitActorSystem(IrcActorSystem *sys);
void IRC_RHYTHM_DrawActorSystem(void *unused);
void IRC_RHYTHM_VBlankActorSystem(void *unused);
struct ClactActor *IRC_RHYTHM_GetActor(IrcActorSystem *sys, int index);
struct Unit *IRC_RHYTHM_GetActorUnit(IrcActorSystem *sys);
void IRC_RHYTHM_InitTextSystem(IrcTextSystem *text, int fontStyle, u16 heapId);
void IRC_RHYTHM_ExitTextSystem(IrcTextSystem *text);
int IRC_RHYTHM_RunPrintQueue(IrcTextSystem *text);
void *IRC_RHYTHM_GetFont(IrcTextSystem *text);
void *IRC_RHYTHM_GetPrintQueue(IrcTextSystem *text);
void *IRC_RHYTHM_GetMessages(IrcTextSystem *text);
void *IRC_RHYTHM_GetWordSet(IrcTextSystem *text);
void IRC_RHYTHM_InitMessageWindow(IrcTextWindow *win, u32 layer, u32 x, u8 y, u8 width, u8 height, u8 paletteNo, u16 heapId);
void IRC_RHYTHM_InitTextWindow(IrcTextWindow *win,u32 layer,u32 x,u8 y,u8 width,u8 height,u8 paletteNo,u16 clearColor,u8 slot,u16 heapId);
void IRC_RHYTHM_ExitTextWindow(IrcTextWindow *win);
int IRC_RHYTHM_UpdateTextWindow(IrcTextWindow *win,IrcTextSystem *text);
void IRC_RHYTHM_PrintMessage(IrcTextWindow *win,IrcTextSystem *text,int msgId,int x,s16 y);
void IRC_RHYTHM_PrintCenteredMessage(IrcTextWindow *win,IrcTextSystem *text,int msgId);
void IRC_RHYTHM_PrintCenteredMessageColor(IrcTextWindow *win,IrcTextSystem *text,int msgId,u16 color);
void IRC_RHYTHM_PrintMessageWithName(IrcTextWindow *win, IrcTextSystem *text, int msgId, IrcCompatibleProfile *profile, s16 x, s16 y, u16 unused);
void IRC_RHYTHM_ClearTextWindow(IrcTextWindow *win);
void IRC_RHYTHM_InitCountdown(IrcRhythmCountdown *countdown, IrcScreen *screen, int unused);
void IRC_RHYTHM_ExitCountdown(IrcRhythmCountdown *countdown);
void IRC_RHYTHM_UpdateCountdown(IrcRhythmCountdown *countdown);
void IRC_RHYTHM_StartCountdown(IrcRhythmCountdown *countdown);
u32 IRC_RHYTHM_IsCountdownFinished(IrcRhythmCountdown *countdown);
void IRC_RHYTHM_SetState(IrcRhythm *work, IrcRhythmStateFn fn);
void IRC_RHYTHM_Finish(IrcRhythm *work);
void IRC_RHYTHM_StateIntro(IrcRhythm *work,u16 *step);
void IRC_RHYTHM_StateCountdown(IrcRhythm *work,u16 *step);
void IRC_RHYTHM_StateTapping(IrcRhythm *work,u16 *step);
void IRC_RHYTHM_StateResult(IrcRhythm *work,u16 *step);
void IRC_RHYTHM_StateAbort(IrcRhythm *work,u16 *step);
void IRC_RHYTHM_InitRecord(IrcRhythmRecord *record);
void IRC_RHYTHM_StartRecord(IrcRhythmRecord *record);
int IRC_RHYTHM_IsRecordFull(IrcRhythmRecord *record);
void IRC_RHYTHM_RecordTap(IrcRhythmRecord *record);
int IRC_RHYTHM_JudgeTap(IrcRhythmRecord *record);
void IRC_RHYTHM_InitNetSync(IrcRhythmNetSync *sync,IrcSys *ircSys);
void IRC_RHYTHM_ExitNetSync(IrcRhythmNetSync *sync);
int IRC_RHYTHM_SendRecord(IrcRhythmNetSync *sync,const IrcRhythmRecord *record);
void IRC_RHYTHM_GetPartnerRecord(IrcRhythmNetSync *sync,IrcRhythmRecord *out);
void IRC_RHYTHM_OnRecordReceived(int aid,int size,int data,IrcRhythmNetSync *sync,void *handle);
IrcRhythmRecord *IRC_RHYTHM_GetRecordReceiveBuffer(int aid,IrcRhythmNetSync *sync);
int IRC_RHYTHM_GetTouchTap(IrcPoint *out);
int IRC_RHYTHM_CalcSyncScore(IrcRhythm *work);
int IRC_RHYTHM_BlendPaletteEntry(u32 target,u16 *color,int angle,int paletteBank,u8 colorIndex,u16 from,u16 to);
void IRC_RHYTHM_InitParticles(IrcRhythmParticles *particles,IrcScreen *screen,int mode,int firstActor,int surface);
void IRC_RHYTHM_ExitParticles(IrcRhythmParticles *particles);
void IRC_RHYTHM_UpdateParticles(IrcRhythmParticles *particles);
void IRC_RHYTHM_SpawnBurst(IrcRhythmParticles *particles, const IrcPoint *center, int palette);
void IRC_RHYTHM_InitParticle(IrcRhythmParticle *particle, struct ClactActor *actor, int surface);
void IRC_RHYTHM_UpdateParticle(IrcRhythmParticle *particle);
void IRC_RHYTHM_StartParticle(IrcRhythmParticle *particle, const IrcPoint *start, const IrcPoint *end, int palette, u32 lifetime);
u32 IRC_RHYTHM_IsParticleActive(IrcRhythmParticle *particle);
void IRC_RHYTHM_InitPulse(IrcRhythmPulse *pulse, int unused);
void IRC_RHYTHM_ExitPulse(IrcRhythmPulse *pulse);
void IRC_RHYTHM_UpdatePulse(IrcRhythmPulse *pulse);
void IRC_RHYTHM_StartPulse(IrcRhythmPulse *pulse);
void IRC_RHYTHM_ClearBlendTask(struct TcbTask *task,void *arg);
/* END mkheaders: generated region */

#endif
