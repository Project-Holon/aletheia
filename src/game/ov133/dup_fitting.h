#ifndef GAME_OV133_DUP_FITTING_H
#define GAME_OV133_DUP_FITTING_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dup_fitting.c, prototypes copied from their definitions. */

struct DupFittingWork;

#include "../types.h"

u8 *DUP_FITTING_Create(u8 *parent, int heap);
void DUP_FITTING_Delete(char *work);
int DUP_FITTING_Main(struct DupFittingWork *work);
void DUP_FITTING_VBlank(void *unused, u8 *work);
void DUP_FITTING_InitDisplay(u8 *work);
void DUP_FITTING_InitModels(u8 *work);
void DUP_FITTING_InitBgLayer(const void *t,unsigned int id);
void DUP_FITTING_InitRenderObj(u8 *work);
void DUP_FITTING_InitFrames(u8 *work);
void DUP_FITTING_AddFitElemById(u8 *work,u16 id);
void DUP_FITTING_RandomPos(void *unused, int *pos);
void DUP_FITTING_FreeElements(u8 *work);
void DUP_FITTING_UpdateIdle(u8 *work);
void *DUP_FITTING_SetModelTransform(u8 *work, u16 base, short speed, u16 rx, u16 ry);
void DUP_FITTING_FreeHeldElem(u8 *work);
void DUP_FITTING_UpdateCursor(u8 *work);
void DUP_FITTING_RotateToCursor(u8 *work, int unused_x, int unused_y);
int DUP_FITTING_PickElem(u8 *work, void *list, u32 kind);
void DUP_FITTING_AttachElem(u8 *work,int sound);
void DUP_FITTING_CreateFitElem(u8 *work);
void DUP_FITTING_ReleaseElem(u8 *work);
void DUP_FITTING_ReturnElem(u8 *work, int unused);
void DUP_FITTING_MoveElem(u8 *work);
void DUP_FITTING_UpdateHeldElem(u8 *work);
int DUP_FITTING_SelectFrame(u8 *work);
void DUP_FITTING_UpdateSubMode(u8 *work);
void DUP_FITTING_UpdateRotation(u8 *work);
int DUP_FITTING_IsFrameOwned(unsigned char *work,unsigned int id);
int DUP_FITTING_FindNearestFrame(u8 *work, void *manager, const int *pos, u16 *limit);
void DUP_FITTING_DrawElems(struct DupFittingWork *work);
void DUP_FITTING_UpdateHeldVisible(u8 *work);
int DUP_FITTING_HitCircle(int x,int y,int radius,float scale);
void DUP_FITTING_SortFrames(u8 *work, int kind, u16 start);
u16 DUP_FITTING_FrameWeight(u8 *work, u8 *frame, int kind);
void DUP_FITTING_DrawFrames(u8 *work);
int DUP_FITTING_HandleTouch(u8 *work);
void DUP_FITTING_ResetSlots(u8 *work);
void DUP_FITTING_HandlePickTouch(u8 *work);
void DUP_FITTING_DragRotate(u8 *work);
void DUP_FITTING_SaveOutfits(char *work);
void DUP_FITTING_DrawBackActors(u8 *work);
void DUP_FITTING_EnterPoseMode(u8 *work);
void DUP_FITTING_ExitPoseMode(unsigned char *work);
void DUP_FITTING_UpdatePose(u8 *work);
void DUP_FITTING_StepPoseRotate(u8 *work,u16 a,int delta,u16 duration);
void DUP_FITTING_StepPoseHold(unsigned char *work,unsigned int limit);
void DUP_FITTING_StepPoseSlide(u8 *work, int *a, int *b, u16 duration);
void DUP_FITTING_CreateText(u8 *work);
void DUP_FITTING_DeleteText(unsigned char *work);
void DUP_FITTING_SetText(u8 *work, unsigned int index, void *object);
void DUP_FITTING_SetTextMon(unsigned char *work);
void DUP_FITTING_SetTextItem(u8 *work, u8 *entry);
void DUP_FITTING_SetTextHelp(u8 *work, int state);
void DUP_FITTING_CreateActors(u8 *work);
void DUP_FITTING_DeleteActors(unsigned char *work);
void DUP_FITTING_UpdateActorTimers(u8 *work);
void DUP_FITTING_ResetActorPose(u8*work);
/* END mkheaders: generated region */

#endif
