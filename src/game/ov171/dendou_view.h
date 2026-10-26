#ifndef GAME_OV171_DENDOU_VIEW_H
#define GAME_OV171_DENDOU_VIEW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dendou_view.c, prototypes copied from their definitions. */

struct ProcSys;
struct ClactActor;

#include "../ov171/dendou_view_types.h"
#include "../types.h"

int DENDOU_VIEW_ProcInit(struct ProcSys *proc, void *unused, DendouViewParams *params);
int DENDOU_VIEW_ProcMain(int unusedA, int unusedB, int unusedC, DendouViewWork *work);
int DENDOU_VIEW_ProcExit(void *work);
void DENDOU_VIEW_StartVBlankTask(DendouViewWork *work);
void DENDOU_VIEW_StopVBlankTask(DendouViewWork *work);
void DENDOU_VIEW_VBlankTask(struct TcbTask *unused, void *work);
void DENDOU_VIEW_InitVram(void);
const void *DENDOU_VIEW_GetVramBanks(void);
void DENDOU_VIEW_InitBgs(void);
void DENDOU_VIEW_ExitBgs(void);
void DENDOU_VIEW_LoadGraphics(void);
void DENDOU_VIEW_InitPalAnm(DendouViewWork *work);
void DENDOU_VIEW_ExitPalAnm(DendouViewWork *work);
void DENDOU_VIEW_ApplyPaletteFade(DendouViewWork *work);
int DENDOU_VIEW_IsPaletteFadeBusy(DendouViewWork *work);
void DENDOU_VIEW_InitBlend(void);
void DENDOU_VIEW_InitText(DendouViewWork *work);
void DENDOU_VIEW_ExitText(DendouViewWork *work);
void DENDOU_VIEW_LoadHallOfFame(DendouViewWork *work);
void DENDOU_VIEW_FreeHallOfFame(DendouViewWork *work);
int DENDOU_VIEW_RunState(DendouViewWork *work);
int DENDOU_VIEW_StateInit(DendouViewWork *work);
int DENDOU_VIEW_StateExit(DendouViewWork *work);
int DENDOU_VIEW_StateWaitWipe(DendouViewWork *work);
u32 DENDOU_VIEW_StateWaitButton(DendouViewWork *work);
int DENDOU_VIEW_StateOverview(DendouViewWork *work);
int DENDOU_VIEW_StateChangeRow(DendouViewWork *work);
int DENDOU_VIEW_StateEnterDetail(DendouViewWork *work);
int DENDOU_VIEW_StateDetail(DendouViewWork *work);
int DENDOU_VIEW_StateLeaveDetail(DendouViewWork *work);
int DENDOU_VIEW_StateRotate(DendouViewWork *work);
int DENDOU_VIEW_StateStartExit(DendouViewWork *work);
int DENDOU_VIEW_StartWipeIn(DendouViewWork *work, int nextState);
int DENDOU_VIEW_StartWipeOut(DendouViewWork *work, int nextState);
int DENDOU_VIEW_StartButtonAnim(DendouViewWork *work, int buttonActor, int animSeq, int nextState);
int DENDOU_VIEW_StepRow(DendouViewWork *work, s8 step);
int DENDOU_VIEW_StepCursor(DendouViewWork *work, s8 step);
int DENDOU_VIEW_IsMemberLeftOfCenter(DendouViewWork *work, int member);
u8 DENDOU_VIEW_CountRotationSteps(DendouViewWork *work, s8 from, int target, s8 step);
void DENDOU_VIEW_StartRotation(DendouViewWork *work, int step);
int DENDOU_VIEW_AdvanceRotation(DendouViewWork *work);
void DENDOU_VIEW_InitWindows(DendouViewWork *work);
void DENDOU_VIEW_ExitWindows(DendouViewWork *work);
void DENDOU_VIEW_FlushWindows(DendouViewWork *work);
void DENDOU_VIEW_PresentWindow(DendouViewWindow *window);
void DENDOU_VIEW_DrawTitle(DendouViewWork *work);
void DENDOU_VIEW_DrawPageCounter(DendouViewWork *work);
void DENDOU_VIEW_DrawMemberInfo(DendouViewWork *work);
void DENDOU_VIEW_ClearInfoWindow(DendouViewWork *work);
void DENDOU_VIEW_InitActors(DendouViewWork *work);
void DENDOU_VIEW_ExitActors(DendouViewWork *work);
void DENDOU_VIEW_UpdateActors(DendouViewWork *work);
void DENDOU_VIEW_SetActorVisible(DendouViewWork *work, int actorIndex, int visible);
void DENDOU_VIEW_SetActorAnim(DendouViewWork *work, int actorIndex, int animSeq);
int DENDOU_VIEW_IsActorAnimActive(DendouViewWork *work, int actorIndex);
void DENDOU_VIEW_MoveActor(DendouViewWork *work, int actorIndex, int dx, int dy);
void DENDOU_VIEW_GetActorPos(DendouViewWork *work, int actorIndex, s16 *outX, s16 *outY);
void DENDOU_VIEW_InitClactSystem(DendouViewWork *work);
void DENDOU_VIEW_LoadButtonResources(DendouViewWork *work);
void DENDOU_VIEW_ReleaseCharacter(DendouViewWork *work, int slot);
void DENDOU_VIEW_ReleasePalette(DendouViewWork *work, int slot);
void DENDOU_VIEW_ReleaseCellAnim(DendouViewWork *work, int slot);
void DENDOU_VIEW_ReleaseResources(DendouViewWork *work);
struct ClactActor *DENDOU_VIEW_CreateActor(DendouViewWork *work, const DendouViewActorTemplate *tmpl);
void DENDOU_VIEW_CreateButtonActors(DendouViewWork *work);
void DENDOU_VIEW_DeleteActor(DendouViewWork *work, int actorIndex);
void DENDOU_VIEW_DeleteActors(DendouViewWork *work);
void DENDOU_VIEW_SwitchRowActors(DendouViewWork *work);
int DENDOU_VIEW_GetActiveActorBase(DendouViewWork *work);
void DENDOU_VIEW_PlaceActorOnEllipse(DendouViewWork *work, int actorIndex, int angle);
void DENDOU_VIEW_SortActorPriorities(DendouViewWork *work);
void DENDOU_VIEW_InitPaletteFade(DendouViewWork *work, int initFade);
void DENDOU_VIEW_InitPageCounterOam(DendouViewWork *work);
void DENDOU_VIEW_ExitPageCounterOam(DendouViewWork *work);
int DENDOU_VIEW_ReadOverviewInput(DendouViewWork *work);
int DENDOU_VIEW_ReadDetailInput(DendouViewWork *work);
int DENDOU_VIEW_ReadTouchedMember(DendouViewWork *work);
/* END mkheaders: generated region */

#endif
