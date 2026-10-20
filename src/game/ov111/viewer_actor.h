#ifndef GAME_OV111_VIEWER_ACTOR_H
#define GAME_OV111_VIEWER_ACTOR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of viewer_actor.c, prototypes copied from their definitions. */

#include "../ov111/viewer_types.h"
#include "../types.h"

void VIEWER_ACTOR_CreateObjects(ViewerTextWork *p);
void VIEWER_ACTOR_DeleteObjects(ViewerTextWork *p);
void VIEWER_ACTOR_Init3D(ViewerTextWork *p);
void VIEWER_ACTOR_Exit3D(ViewerTextWork *p);
void VIEWER_ACTOR_CreateModel(ViewerTextWork *p);
void VIEWER_ACTOR_DeleteModel(ViewerTextWork *p);
void VIEWER_ACTOR_DrawModel(ViewerTextWork *p);
void VIEWER_ACTOR_InitBgWindow(ViewerTextWork *p);
void VIEWER_ACTOR_DeleteBgWindow(ViewerTextWork *p);
void VIEWER_ACTOR_FlushBgWindow(ViewerTextWork *p);
void VIEWER_ACTOR_CreateFont(ViewerTextWork *p);
void VIEWER_ACTOR_DeleteFont(ViewerTextWork *p);
void VIEWER_ACTOR_PrintQueMain(ViewerTextWork *p);
int VIEWER_ACTOR_DispatchState(ViewerTextWork *p);
int VIEWER_ACTOR_StepWaitWipeIn(ViewerTextWork *p);
int VIEWER_ACTOR_UpdateMain(ViewerTextWork *p);
int VIEWER_ACTOR_StepWaitActorAnim(ViewerTextWork *p);
int VIEWER_ACTOR_StartWipe(ViewerTextWork *p);
int VIEWER_ACTOR_StepWaitWipeOut(ViewerTextWork *p);
void VIEWER_ACTOR_PrintTextAt(ViewerTextWork *p, int x, int k, int col);
void VIEWER_ACTOR_DrawLabel(ViewerTextWork *p, int mode, int idx);
int VIEWER_ACTOR_WrapAngle(int a, int b);
void VIEWER_ACTOR_StepBounce(ViewerTextWork *p);
void VIEWER_ACTOR_HandleDrag(ViewerTextWork *p, int unused, int touch, int x);
int VIEWER_ACTOR_HandleInput(ViewerTextWork *p);
int VIEWER_ACTOR_FindNearestPreset(int v);
void VIEWER_ACTOR_SelectActor(ViewerTextWork *p, int sel, int flag);
void VIEWER_ACTOR_ToggleFavorite(ViewerTextWork *p);
void VIEWER_ACTOR_SetPageCount(ViewerTextWork *p);
void VIEWER_ACTOR_SetRowDrawEnable(ViewerTextWork *p, int row, int v);
void VIEWER_ACTOR_UpdateRowVisibility(ViewerTextWork *p, int a, int b);
void VIEWER_ACTOR_SetSelection(ViewerTextWork *p, u16 v);
void VIEWER_ACTOR_SaveBadgeTimers(ViewerTextWork *p);
void VIEWER_ACTOR_LoadBadgeTimers(ViewerTextWork *p);
void VIEWER_ACTOR_LoadPalette(ViewerTextWork *p, int idx, int k);
void VIEWER_ACTOR_LoadTexture(ViewerTextWork *p, int idx, int k);
void VIEWER_ACTOR_SetRowActorDrawEnable(ViewerTextWork *p, int row, int n);
void VIEWER_ACTOR_RefreshRows(ViewerTextWork *p);
void VIEWER_ACTOR_HandleScrollRepeat(u8 *p, int value);
void VIEWER_ACTOR_ResetDragFlags(u8 *p);
void VIEWER_ACTOR_StepScrollCount(u8 *p, int idx);
void VIEWER_ACTOR_HandleTouchDrag(ViewerTextWork *p, int idx);
/* END mkheaders: generated region */

#endif
