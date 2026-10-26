#ifndef GAME_OV110_PMS_SELECT_GRAPHIC_H
#define GAME_OV110_PMS_SELECT_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pms_select_graphic.c, prototypes copied from their definitions. */

struct Proc;
struct PmsSelectGraphicArgs;
struct PmsSelectGraphic;
struct PmsSelectGraphicBg;
struct GfFont;
struct PmsSelectGraphicColorRec;
struct PmsSelectGraphicScene;
struct DispVramCfg;

#include "../types.h"
#include "../ov067/touchbar_types.h"

struct TcbTask;

int PMS_SELECT_GRAPHIC_ProcInit(struct Proc *owner, int unused, struct PmsSelectGraphicArgs *args);
int PMS_SELECT_GRAPHIC_ProcExit(struct Proc *proc, int unused, int unused2, struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_IsPrintDone(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_SetResult(int *state, struct PmsSelectGraphic *p, int next);
int PMS_SELECT_GRAPHIC_ProcMain(void *unused, int *state, void *unused2, struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_Setup(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_Teardown(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_CreateBg(struct PmsSelectGraphicBg *bg, u16 heap, struct GfFont *font, void *print, void *bank);
void PMS_SELECT_GRAPHIC_DeleteBg(struct PmsSelectGraphicBg *bg);
void PMS_SELECT_GRAPHIC_ColorRowBg(struct PmsSelectGraphicBg *bg, u8 row, u32 pal, int flag);
void PMS_SELECT_GRAPHIC_BlendBlinkColors(u16 *angle, u16 *out, const struct PmsSelectGraphicColorRec *recs, u8 count);
void PMS_SELECT_GRAPHIC_UpdateBgBlink(struct PmsSelectGraphicBg *bg);
void PMS_SELECT_GRAPHIC_ResetBgBlink(struct PmsSelectGraphicBg *bg);
void PMS_SELECT_GRAPHIC_ColorTitleBg(struct PmsSelectGraphicBg *bg, int pal);
TouchBar *PMS_SELECT_GRAPHIC_CreateTouchBar(int unused, void *actorUnit, int heap);
void PMS_SELECT_GRAPHIC_DeleteTouchBar(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_UpdateTouchBar(TouchBar *touchBar);
void *PMS_SELECT_GRAPHIC_OpenRowMenu(void *res, void *bank, u16 heapId);
void PMS_SELECT_GRAPHIC_CloseRowMenu(void *menu);
void PMS_SELECT_GRAPHIC_UpdateRowMenu(void *menu);
void PMS_SELECT_GRAPHIC_CreateRows(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_DeleteRows(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_UpdateDraw(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_RedrawRows(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_DrawRows(struct PmsSelectGraphic *p, int flag);
void PMS_SELECT_GRAPHIC_PlaceScrollThumb(struct PmsSelectGraphic *p, int force);
int PMS_SELECT_GRAPHIC_StartThumbDrag(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_GetThumbRow(unsigned y, int count, short *out, short *pos);
int PMS_SELECT_GRAPHIC_UpdateThumbDrag(struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_UpdateInput(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_FlushRowWindows(struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_FlushRowWindow(void *printQueue, void *window, int *pending);
void PMS_SELECT_GRAPHIC_DrawNewRow(struct PmsSelectGraphic *p, u8 row, int unused, int flag);
void PMS_SELECT_GRAPHIC_DrawSavedRow(struct PmsSelectGraphic *p, u8 row, u8 which, int flag);
int PMS_SELECT_GRAPHIC_GetTouchedRow(void);
int PMS_SELECT_GRAPHIC_ShowTouchBar(void *unused, struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_StepList(void *unused, struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_HideTouchBar(void *unused, struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_StepOpenRowMenu(void *unused, struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_StepRowMenu(void *unused, struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_StepCloseRowMenu(void *unused, struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_StepOpenEditScreen(int *step, struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_StepCloseEditScreen(int *step, struct PmsSelectGraphic *p);
struct PmsSelectGraphicScene *PMS_SELECT_GRAPHIC_CreateScene(unsigned arg, u16 heap);
void PMS_SELECT_GRAPHIC_DeleteScene(struct PmsSelectGraphicScene *scene);
void PMS_SELECT_GRAPHIC_UpdateScene(struct PmsSelectGraphicScene *scene);
void *PMS_SELECT_GRAPHIC_GetSceneActorUnit(struct PmsSelectGraphicScene *scene);
void PMS_SELECT_GRAPHIC_SceneTask(struct TcbTask *taskId, void *work);
void PMS_SELECT_GRAPHIC_InitSceneBgs(struct PmsSelectGraphicScene *scene, u16 heap);
void PMS_SELECT_GRAPHIC_ExitSceneBgs(struct PmsSelectGraphicScene *scene);
void PMS_SELECT_GRAPHIC_UpdateSceneNothing(struct PmsSelectGraphicScene *scene);
void PMS_SELECT_GRAPHIC_TransferSceneBgs(struct PmsSelectGraphicScene *scene);
void PMS_SELECT_GRAPHIC_InitSceneActors(void **unitOut, struct DispVramCfg *vram, unsigned heap);
void PMS_SELECT_GRAPHIC_ExitSceneActors(void **unit);
void PMS_SELECT_GRAPHIC_DrawSceneActors(void *unit);
void PMS_SELECT_GRAPHIC_VBlankSceneActors(void *unit);
void *PMS_SELECT_GRAPHIC_ReadPointer(void **p);
/* END mkheaders: generated region */

#endif
