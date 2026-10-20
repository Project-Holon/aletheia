#ifndef GAME_OV067_FRAME_LIST_H
#define GAME_OV067_FRAME_LIST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of frame_list.c, prototypes copied from their definitions. */

struct PrintSys;

#include "../ov067/frame_list_types.h"
#include "../ov067/frame_list_params.h"
#include "../types.h"

FrameList *FRAME_LIST_Create(const FrameListParams *params, u32 heapId);
void FRAME_LIST_Delete(FrameList *list);
void FRAME_LIST_AddItem(FrameList *list, unsigned mapIndex, unsigned value);
void FRAME_LIST_CopyMapToBuffer(FrameList *list, void *source, u32 fileIndex, u32 memberIndex, u32 mapSlot);
void FRAME_LIST_LoadPalettes(FrameList *list, u8 *palettes, u32 firstSlot, u32 srcSlot, u32 slotCount);
int FRAME_LIST_UpdateInit(FrameList *list);
int FRAME_LIST_Update(FrameList *list);
void FRAME_LIST_ClampScroll(FrameList *list);
void FRAME_LIST_Redraw(FrameList *list, int play);
int FRAME_LIST_ReadTouch(FrameList *list);
int FRAME_LIST_ReadKeys(FrameList *list);
int FRAME_LIST_HandleInput(FrameList *list);
void FRAME_LIST_UpdateHoldStage(FrameList *list);
u8 FRAME_LIST_GetStepFrames(const FrameList *list, int speed);
int FRAME_LIST_GetScrollRoom(const FrameList *list, int speed);
void FRAME_LIST_StartScroll(FrameList *list, s8 speed, u8 steps, u16 returnState, u32 playSe);
int FRAME_LIST_StepScroll(FrameList *list);
void FRAME_LIST_BeginScrollBarDrag(FrameList *list, int rectIndex);
u32 FRAME_LIST_GetScrollBarRow(FrameList *list);
void FRAME_LIST_FindScrollBarEntry(FrameList *list, u8 *outX, u8 *outY);
int FRAME_LIST_GetScrollBarTop(FrameList *list);
int FRAME_LIST_ClampToScrollBar(FrameList *list, unsigned int touchY);
int FRAME_LIST_StepScrollBarDrag(FrameList *list);
void FRAME_LIST_BeginRowDrag(FrameList *list, int row);
int FRAME_LIST_StepRowDrag(FrameList *list);
int FRAME_LIST_StartJump(FrameList *list, int row);
int FRAME_LIST_StartFlick(FrameList *list);
int FRAME_LIST_ClampBgFrameId(int bgFrame);
void FRAME_LIST_UploadRowTiles(FrameList *list, u32 item, u32 windowIndex);
void FRAME_LIST_ScrollBgRows(FrameList *list, int windowIndex, s8 y);
void FRAME_LIST_ClearBgRows(FrameList *list, u32 layer, s8 y);
signed char FRAME_LIST_GetRowPosition(const FrameList *list, int step);
signed char FRAME_LIST_WrapIndex(signed char index, signed char limit, int step);
void FRAME_LIST_DrawRowA(FrameList *list, int item, s8 y);
void FRAME_LIST_DrawRowB(FrameList *list, int item, s8 y);
void FRAME_LIST_SetRowPalette(FrameList *list, int row, u32 pltt);
void FRAME_LIST_SetCursorHighlight(FrameList *list, u32 newRow, u32 oldRow);
void FRAME_LIST_UpdateWindows(FrameList *list);
struct PrintSys *FRAME_LIST_GetPrinter(FrameList *list);
u32 FRAME_LIST_GetItemValue(FrameList *list, int index);
int FRAME_LIST_GetSelectedIndex(FrameList *list);
int FRAME_LIST_GetCursor(FrameList *list);
int FRAME_LIST_GetScrollPos(FrameList *list);
int FRAME_LIST_CanScrollDown(FrameList *list);
void FRAME_LIST_SetCursor(FrameList *list, int row);
void FRAME_LIST_ShowCursor(FrameList *list);
void FRAME_LIST_HideCursor(FrameList *list);
/* END mkheaders: generated region */

#endif
