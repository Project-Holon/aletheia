#ifndef GAME_OV129_WF2DMAP_SCENE_H
#define GAME_OV129_WF2DMAP_SCENE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wf2dmap_scene.c, prototypes copied from their definitions. */

struct Wf2dmapSceneCell;
struct DispVramCfg;
typedef struct Wf2dmapSceneCell Wf2dmapSceneCell;

#include "../types.h"

struct TcbTask;

int WF2DMAP_SCENE_Draw(int a, int b, int c, char *scene);
int WF2DMAP_SCENE_Delete(void *procWork,int b,int c,char *scene);
void WF2DMAP_SCENE_InitBg(void);
void WF2DMAP_SCENE_VBlank(struct TcbTask *a, void *sceneArg);
void WF2DMAP_SCENE_SetSlot(char *scene,int slotId);
void WF2DMAP_SCENE_BuildGrid(char *scene);
void WF2DMAP_SCENE_ResetState(char *scene, int state);
int WF2DMAP_SCENE_Start(char *scene);
int WF2DMAP_SCENE_StepWipeIn(char *scene);
int WF2DMAP_SCENE_StepWaitInput(char *scene);
int WF2DMAP_SCENE_StepUpdate(char *scene);
int WF2DMAP_SCENE_StepAnimate(char *scene);
int WF2DMAP_SCENE_Dispatch(char *scene);
void WF2DMAP_SCENE_HandleInput(char *scene);
int WF2DMAP_SCENE_GetGridNumber(u8 *scene);
int WF2DMAP_SCENE_CheckGridNumber(u8 *scene);
void WF2DMAP_SCENE_BuildNumberList(char *scene);
void WF2DMAP_SCENE_ClearSelection(const Wf2dmapSceneCell *cells);
void WF2DMAP_SCENE_CreateButtons(char *scene);
void WF2DMAP_SCENE_SetButtonCursor(u8 *scene,int buttonIdx);
void WF2DMAP_SCENE_HandleButton(u32 buttonIdx, s32 isRelease, void *);
void WF2DMAP_SCENE_ProcessPending(char *scene);
void WF2DMAP_SCENE_ClearPending(char *scene);
int WF2DMAP_SCENE_FindCellByValue(u8 *scene,int value);
int WF2DMAP_SCENE_FindLastCellByValue(u8 *scene,int value);
void WF2DMAP_SCENE_InitClact(char *scene,const struct DispVramCfg *heapId);
void WF2DMAP_SCENE_LoadActorAssets(char *scene);
void WF2DMAP_SCENE_DeleteActors(char *scene);
void WF2DMAP_SCENE_CreateCellActors(char *scene);
void WF2DMAP_SCENE_CreateCursorActors(char *scene);
void WF2DMAP_SCENE_CreateExtraActors(char *scene);
void WF2DMAP_SCENE_SetCursorVisible(char *scene, int cursorIdx, int visible);
void WF2DMAP_SCENE_MoveCursor(u8 *scene,int cellIdx);
void WF2DMAP_SCENE_SetCursorPos(char *scene,int cellIdx);
void WF2DMAP_SCENE_SetCursorPosBySlot(char *scene,int cellIdx,int cursorIdx);
void WF2DMAP_SCENE_UpdateCursorAnim(char *scene);
void WF2DMAP_SCENE_SetOamPos(char *oam, int x, int y);
void WF2DMAP_SCENE_UpdateOam(char *scene);
int WF2DMAP_SCENE_GetCellAnim(int state,int flag);
void WF2DMAP_SCENE_SetCellFlags(void *scene);
void WF2DMAP_SCENE_LayoutCells(char *scene,int animate);
void WF2DMAP_SCENE_UpdateCellRects(char *scene);
void WF2DMAP_SCENE_CreateOam(char *scene);
void WF2DMAP_SCENE_DeleteOam(u8 *scene);
void WF2DMAP_SCENE_RegisterCompressedPalette(u8 *scene);
void WF2DMAP_SCENE_CreateTextOams(u8 *scene);
void WF2DMAP_SCENE_CreateTextOam(u8 *scene, int index, int argX, int argY, int unused);
void WF2DMAP_SCENE_CreateWindow(void **windowOut,int msgId,int x,int y,int w,int tiles,int palette,void *msgBank,int number);
void WF2DMAP_SCENE_DrawMessage(void *window,int msgId,void *msgBank,u32 number);
void WF2DMAP_SCENE_ShowMessage(void *window, int sel, void *msgBank, unsigned int number);
/* END mkheaders: generated region */

#endif
