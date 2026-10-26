#ifndef GAME_OV133_DUP_FITTING_H
#define GAME_OV133_DUP_FITTING_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dup_fitting.c, prototypes copied from their definitions. */

struct DupFittingWork;

#include "../types.h"

u8 *DUP_FITTING_Create(u8 *parent, int heap);
void DUP_FITTING_Delete(char *obj);
int DUP_FITTING_Main(struct DupFittingWork *work);
void DUP_FITTING_VBlank(void *unused, struct DupFittingWork *work);
void DUP_FITTING_InitDisplay(struct DupFittingWork *work);
void DUP_FITTING_InitModels(struct DupFittingWork *work);
void DUP_FITTING_InitBgLayer(const void *t,unsigned int id);
void DUP_FITTING_InitRenderObj(struct DupFittingWork *work);
void DUP_FITTING_InitFrames(struct DupFittingWork *work);
void DUP_FITTING_AddFitElemById(struct DupFittingWork *work,u16 id);
void DUP_FITTING_RandomPos(void *unused, int *pos);
void DUP_FITTING_FreeElements(struct DupFittingWork *work);
void DUP_FITTING_UpdateIdle(struct DupFittingWork *work);
void *DUP_FITTING_SetModelTransform(struct DupFittingWork *work, u16 base, short speed, u16 rx, u16 ry);
void DUP_FITTING_FreeHeldElem(struct DupFittingWork *work);
void DUP_FITTING_UpdateCursor(struct DupFittingWork *work);
void DUP_FITTING_RotateToCursor(struct DupFittingWork *work, int unused_x, int unused_y);
int DUP_FITTING_PickElem(struct DupFittingWork *work, void *list, u32 kind);
void DUP_FITTING_AttachElem(struct DupFittingWork *work,int sound);
void DUP_FITTING_CreateFitElem(struct DupFittingWork *work);
void DUP_FITTING_ReleaseElem(struct DupFittingWork *work);
void DUP_FITTING_ReturnElem(struct DupFittingWork *work, int unused);
void DUP_FITTING_MoveElem(struct DupFittingWork *work);
void DUP_FITTING_UpdateHeldElem(struct DupFittingWork *work);
int DUP_FITTING_SelectFrame(struct DupFittingWork *work);
void DUP_FITTING_UpdateSubMode(struct DupFittingWork *work);
void DUP_FITTING_UpdateRotation(struct DupFittingWork *work);
int DUP_FITTING_IsFrameOwned(struct DupFittingWork *work,unsigned int id);
int DUP_FITTING_FindNearestFrame(struct DupFittingWork *work, void *manager, const int *pos, u16 *limit);
void DUP_FITTING_DrawElems(struct DupFittingWork *work);
void DUP_FITTING_UpdateHeldVisible(struct DupFittingWork *work);
int DUP_FITTING_HitCircle(int x,int y,int radius,float scale);
void DUP_FITTING_SortFrames(struct DupFittingWork *work, int kind, u16 start);
u16 DUP_FITTING_FrameWeight(struct DupFittingWork *work, u8 *frame, int kind);
void DUP_FITTING_DrawFrames(struct DupFittingWork *work);
int DUP_FITTING_HandleTouch(struct DupFittingWork *work);
void DUP_FITTING_ResetSlots(struct DupFittingWork *work);
void DUP_FITTING_HandlePickTouch(struct DupFittingWork *work);
void DUP_FITTING_DragRotate(struct DupFittingWork *work);
void DUP_FITTING_SaveOutfits(struct DupFittingWork *work);
void DUP_FITTING_DrawBackActors(struct DupFittingWork *work);
void DUP_FITTING_EnterPoseMode(struct DupFittingWork *work);
void DUP_FITTING_ExitPoseMode(struct DupFittingWork *work);
void DUP_FITTING_UpdatePose(struct DupFittingWork *work);
void DUP_FITTING_StepPoseRotate(struct DupFittingWork *work,u16 a,int delta,u16 duration);
void DUP_FITTING_StepPoseHold(struct DupFittingWork *work,unsigned int limit);
void DUP_FITTING_StepPoseSlide(struct DupFittingWork *work, int *a, int *b, u16 duration);
void DUP_FITTING_CreateText(struct DupFittingWork *work);
void DUP_FITTING_DeleteText(struct DupFittingWork *work);
void DUP_FITTING_SetText(struct DupFittingWork *work, unsigned int index, void *object);
void DUP_FITTING_SetTextMon(struct DupFittingWork *work);
void DUP_FITTING_SetTextItem(struct DupFittingWork *work, u8 *entry);
void DUP_FITTING_SetTextHelp(struct DupFittingWork *work, int state);
void DUP_FITTING_CreateActors(struct DupFittingWork *work);
void DUP_FITTING_DeleteActors(struct DupFittingWork *work);
void DUP_FITTING_UpdateActorTimers(struct DupFittingWork *work);
void DUP_FITTING_ResetActorPose(struct DupFittingWork *work);
/* END mkheaders: generated region */

#endif
