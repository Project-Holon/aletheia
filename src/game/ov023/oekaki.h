#ifndef GAME_OV023_OEKAKI_H
#define GAME_OV023_OEKAKI_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of oekaki.c, prototypes copied from their definitions. */

struct TcbTask;
struct Proc;
struct ClActor;
struct BmpWin;
struct TaskMenu;
struct StrokeBytes;
typedef struct ClActor ClActor;
typedef struct TaskMenu TaskMenu;
typedef struct StrokeBytes StrokeBytes;

#include "../ov023/oekaki_types.h"
#include "../types.h"
#include "../ov022/union_app_types.h"

void OEKAKI_RegisterNetCommands(OekakiWork *work);
void OEKAKI_RecvCanvasChunk(int netId, int size, CanvasChunk *chunk, OekakiWork *work, int netHandle);
void OEKAKI_RecvStroke(int netId, int size, const StrokeRec *stroke, OekakiWork *work);
void OEKAKI_RecvStrokes(int netId, int size, const u8 *strokes, OekakiWork *work);
void OEKAKI_RecvReset(int netId, int size, int unused, OekakiWork *work);
void OEKAKI_RecvSyncMessage(int netId, int size, const OekakiSyncMsg *msg, OekakiWork *work);
void OEKAKI_RecvAck(int netId, int size, int unused, OekakiWork *work);
void OEKAKI_RecvMemberJoined(int netId, int size, u8 *data, OekakiWork *work, int netHandle);
void OEKAKI_RecvCanvasDone(int netId, int size, int unused, OekakiWork *work);
u32 OEKAKI_SendCanvasChunk(OekakiWork *work, int chunkIndex, int unused);
CanvasChunk *OEKAKI_GetRecvChunk(int netId, OekakiWork *work);
void OEKAKI_OpenGroup(OekakiWork *work, int maxCount);
int OEKAKI_Init(void *task, int *state, OekakiParam *param);
int OEKAKI_Main(void *task, int *state, int unused, OekakiWork *work);
int OEKAKI_Exit(struct Proc *task, int *seq, void *unused, OekakiWork *work);
void OEKAKI_VBlankTask(struct TcbTask *task, void *work);
void OEKAKI_OnMemberJoined(int netId, UnionAppEntry *entry, void *arg);
void OEKAKI_OnMemberLeft(int netId, UnionAppEntry *entry, void *work);
void OEKAKI_SetVramBanks(void);
void OEKAKI_SetupBgs(void);
void OEKAKI_InitWork(OekakiWork *work);
void OEKAKI_FreeWork(OekakiWork *work);
void OEKAKI_ResetDisplay(void);
void OEKAKI_LoadBgGraphics(OekakiWork *work, void *archive);
void OEKAKI_LoadSpriteResources(OekakiWork *work, void *archive);
void OEKAKI_CreateActors(OekakiWork *p);
void OEKAKI_CreateWindows(OekakiWork *p, void *task);
void OEKAKI_DeleteWindows(OekakiWork *p);
void OEKAKI_SetCursorPosition(ClActor *actor, int x, int y);
void OEKAKI_MakeEmptyStroke(StrokeRec *stroke, int color, int size);
void OEKAKI_HandleTouch(OekakiWork *p);
void OEKAKI_SelectColorButton(ClActor **buttons, int selected);
void OEKAKI_SetQuitButtonPressed(ClActor *button, int pressed);
int OEKAKI_StepDraw(OekakiWork *p, int procState);
void OEKAKI_ApplyRemoteStrokes(OekakiWork *p);
int OEKAKI_StepStart(OekakiWork *p, int procState);
int OEKAKI_StepHideCursors(OekakiWork *p, int procState);
int OEKAKI_StepEnterDraw(OekakiWork *p, int procState);
int OEKAKI_StepOpenQuitMenu(OekakiWork *p, int procState);
int OEKAKI_StepQuitMenuResult(OekakiWork *p, int procState);
int OEKAKI_StepSendQuitRequest(OekakiWork *p, int procState);
int OEKAKI_StepResetWaitTimer(OekakiWork *p, int procState);
int OEKAKI_StepWaitQuitReply(OekakiWork *p, int procState);
int OEKAKI_StepSendQuitConfirm(OekakiWork *p, int procState);
int OEKAKI_StepCancelQuit(OekakiWork *p, int procState);
int OEKAKI_StepShowQuitMessage(OekakiWork *p, int procState);
int OEKAKI_StepWaitQuitMessage(OekakiWork *p, int procState);
int OEKAKI_StepWaitThenFadeOut(OekakiWork *p, int procState);
int OEKAKI_StepOpenFinishMenu(OekakiWork *p, int procState);
int OEKAKI_StepFinishMenuResult(OekakiWork *p, int procState);
void OEKAKI_RegisterPlayerName(OekakiWork *p, int wordIndex, int netId);
int OEKAKI_StepSendFinishRequest(OekakiWork *p, int procState);
int OEKAKI_StepShowFinishMessage(OekakiWork *p, int procState);
int OEKAKI_StepWaitFinishMessage(OekakiWork *p, int procState);
int OEKAKI_StepCheckMembers(OekakiWork *p, int procState);
int OEKAKI_StepKeepState(int unused, int procState);
int OEKAKI_StepShowWaitMessage(OekakiWork *p, int procState);
int OEKAKI_StepWaitMessage(OekakiWork *p, int procState);
int OEKAKI_StepShowSyncMessage(OekakiWork *p, int procState);
int OEKAKI_StepWaitSyncAck(OekakiWork *p, int procState);
int OEKAKI_StepWaitSyncTimer(OekakiWork *p, int procState);
void OEKAKI_HandleEvent(OekakiWork *p, int event, int netId);
void OEKAKI_BlitBrush(struct BmpWin *canvas, const u8 *brushPixels, int x, int y, int width, int height, int srcX, int srcY, int maxCutX, int maxCutY);
void OEKAKI_DrawLine(struct BmpWin *canvas, const u8 *brushPixels, int x1, int y1, int *px, int *py, int newStroke, int prevCount);
void OEKAKI_StoreLastPoints(StrokeRec *strokes, LastPoint *last);
void OEKAKI_DrawStrokes(struct BmpWin *canvas, StrokeRec *strokes, LastPoint *last, int redraw);
void OEKAKI_UpdateRemoteCursors(OekakiWork *p);
void OEKAKI_AnimatePalette(u16 *angle);
int OEKAKI_CountMembers(OekakiWork *p);
void OEKAKI_RefreshNamePlates(struct BmpWin **windows, u16 color, OekakiWork *p);
void OEKAKI_SendStrokes(OekakiWork *p);
int OEKAKI_GetMemberCount(OekakiWork *p);
int OEKAKI_UpdateMemberSlots(OekakiWork *p);
void OEKAKI_PrintMessage(OekakiWork *p, u32 msgId, int mode);
int OEKAKI_IsMessageDone(OekakiWork *p);
void OEKAKI_ClearMessageWindow(OekakiWork *p);
void OEKAKI_HostOpenGroupLimited(OekakiWork *p, int flag);
int OEKAKI_UpdateMembers(OekakiWork *p);
void OEKAKI_SetNextScene(OekakiWork *p, u32 nextScene);
void OEKAKI_ApplySceneChange(OekakiWork *p, int mode);
void OEKAKI_CloseMenuIfOpen(OekakiWork *p);
int OEKAKI_IsQuitTouched(OekakiWork *p);
void OEKAKI_MakeStroke(StrokeRec *stroke, TouchPoint *path, int color, int size);
int OEKAKI_GetJoinedCount(OekakiWork *p);
int OEKAKI_GetJoinedBits(OekakiWork *p);
void OEKAKI_EnableDisplays(void);
TaskMenu *OEKAKI_OpenYesNoMenu(OekakiWork *p);
int OEKAKI_PollYesNoMenu(OekakiWork *p);
void OEKAKI_CloseYesNoMenu(OekakiWork *p);
void OEKAKI_RegisterMetPlayers(OekakiWork *p);
void OEKAKI_UpdatePrintJobs(OekakiWork *p);
void OEKAKI_SendPendingCommand(OekakiWork *p);
void OEKAKI_QueueCommand(OekakiWork *p, int commandId, int arg);
int OEKAKI_GetPrevQueueIndex(StrokeQueue *queue);
void OEKAKI_AdvanceQueueTailIfUsed(StrokeQueue *queue);
void OEKAKI_AdvanceQueueTail(StrokeQueue *queue);
void OEKAKI_ClearStrokeGroup(StrokeRec *rec);
void OEKAKI_PopStrokeGroup(StrokeQueue *queue);
void OEKAKI_StoreStroke(StrokeBytes *stroke, StrokeQueue *queue, int index);
void OEKAKI_PeekStroke(StrokeRec *dst, StrokeQueue *queue);
void OEKAKI_FillSendGroup(StrokeGroup *sendGroup, StrokeQueue *queue);
/* END mkheaders: generated region */

#endif
