#ifndef GAME_OV110_PMSIV_CATEGORY_H
#define GAME_OV110_PMSIV_CATEGORY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pmsiv_category.c, prototypes copied from their definitions. */

struct PmsivCategory;
struct PmsInputView;
struct PmsInputState;
struct PmsInputData;

#include "../types.h"

struct PmsivCategory *PMSIV_CATEGORY_Create(struct PmsInputView *view, struct PmsInputState *input, struct PmsInputData *wordData);
void PMSIV_CATEGORY_Delete(struct PmsivCategory *p);
void PMSIV_CATEGORY_Setup(struct PmsivCategory *p, void *data);
u8 *PMSIV_CATEGORY_MakeCategoryButtons(struct PmsivCategory *p, u8 *q);
u8 *PMSIV_CATEGORY_MakeKanaWindow(struct PmsivCategory *p, u8 *q);
u8 *PMSIV_CATEGORY_MakeTitleWindow(struct PmsivCategory *p, u8 *q);
void PMSIV_CATEGORY_MakeListWindow(struct PmsivCategory *p);
void PMSIV_CATEGORY_CreateCursor(struct PmsivCategory *p);
void PMSIV_CATEGORY_SetCursorVisible(struct PmsivCategory *p, int enable);
void PMSIV_CATEGORY_MoveCursor(struct PmsivCategory *p, unsigned index);
void PMSIV_CATEGORY_StartFadeIn(struct PmsivCategory *p);
int PMSIV_CATEGORY_IsFadeInDone(struct PmsivCategory *p);
void PMSIV_CATEGORY_StartClose(struct PmsivCategory *p);
int PMSIV_CATEGORY_StepClose(struct PmsivCategory *p);
void PMSIV_CATEGORY_ResetBgScroll(struct PmsivCategory *p);
void PMSIV_CATEGORY_StartFadeOut(struct PmsivCategory *p);
int PMSIV_CATEGORY_IsFadeOutDone(struct PmsivCategory *p);
void PMSIV_CATEGORY_StartBlendOut(struct PmsivCategory *p);
int PMSIV_CATEGORY_IsBlendOutDone(struct PmsivCategory *p);
void PMSIV_CATEGORY_StartBlendIn(struct PmsivCategory *p);
int PMSIV_CATEGORY_IsBlendInDone(struct PmsivCategory *p);
void PMSIV_CATEGORY_ApplyBgOffset(struct PmsivCategory *p);
void PMSIV_CATEGORY_RefreshScreens(struct PmsivCategory *p);
int PMSIV_CATEGORY_IsReady(struct PmsivCategory *p);
void PMSIV_CATEGORY_DrawTitle(struct PmsivCategory *p);
void PMSIV_CATEGORY_ShowWordList(struct PmsivCategory *p, int flag);
void PMSIV_CATEGORY_StartListScrollOut(struct PmsivCategory *p, u32 unused);
void PMSIV_CATEGORY_DrawWordList(struct PmsivCategory *p, unsigned count);
int PMSIV_CATEGORY_IsListReady(struct PmsivCategory *p, int waitForPrint);
void PMSIV_CATEGORY_StartSelectAnim(struct PmsivCategory *p, unsigned index);
int PMSIV_CATEGORY_IsSelectAnimDone(struct PmsivCategory *p);
/* END mkheaders: generated region */

#endif
