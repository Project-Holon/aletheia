#ifndef GAME_OV110_PMSIV_WORDWIN_H
#define GAME_OV110_PMSIV_WORDWIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pmsiv_wordwin.c, prototypes copied from their definitions. */

struct PmsivWordwin;
struct PmsInputView;
struct PmsInputData;
struct PmsivWordwinPtS;

#include "../ov110/pms_input_types.h"
#include "../types.h"

struct PmsivWordwin *PMSIV_WORDWIN_Create(struct PmsInputView *view, PmsInput *input, struct PmsInputData *wordData);
void PMSIV_WORDWIN_Delete(struct PmsivWordwin *p);
void PMSIV_WORDWIN_Setup(struct PmsivWordwin *p);
void PMSIV_WORDWIN_CreateActors(struct PmsivWordwin *p);
void PMSIV_WORDWIN_DrawList(struct PmsivWordwin *p);
void PMSIV_WORDWIN_DrawListFrom(struct PmsivWordwin *p,unsigned a);
void PMSIV_WORDWIN_StartOpen(struct PmsivWordwin *p);
int PMSIV_WORDWIN_IsOpen(struct PmsivWordwin *p);
void PMSIV_WORDWIN_StartClose(struct PmsivWordwin *p);
int PMSIV_WORDWIN_FinishClose(struct PmsivWordwin *p);
void PMSIV_WORDWIN_SetVisible(struct PmsivWordwin *p, unsigned visible);
void PMSIV_WORDWIN_SetCursorCell(struct PmsivWordwin *p, unsigned i);
void PMSIV_WORDWIN_Scroll(struct PmsivWordwin *p,int amount);
int PMSIV_WORDWIN_UpdateScroll(struct PmsivWordwin *p);
u32 PMSIV_WORDWIN_GetThumb(struct PmsivWordwin *p,struct PmsivWordwinPtS *out);
void PMSIV_WORDWIN_SetThumbRow(struct PmsivWordwin *p,unsigned a,unsigned n);
void PMSIV_WORDWIN_SetThumbY(struct PmsivWordwin *p,int y);
unsigned PMSIV_WORDWIN_GetThumbRow(struct PmsivWordwin *p, unsigned n);
void PMSIV_WORDWIN_ClearRows(struct PmsivWordwin *p,int amount);
void PMSIV_WORDWIN_ResetScroll(struct PmsivWordwin *p);
void PMSIV_WORDWIN_DrawCell(struct PmsivWordwin *p, u32 n, u32 y);
void PMSIV_WORDWIN_StartPickAnim(struct PmsivWordwin *p, unsigned i);
int PMSIV_WORDWIN_IsPickAnimDone(struct PmsivWordwin *p);
/* END mkheaders: generated region */

#endif
