#ifndef GAME_OV210_ZKNSEARCH_RESULT_H
#define GAME_OV210_ZKNSEARCH_RESULT_H

#include "../ov210/zknsearch_types.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zknsearch_result.c, prototypes copied from their definitions. */

#include "../ov210/zknsearch_types.h"

void ZKNSEARCH_RESULT_InitFrameList(ZknSearchWork *ctx);
void ZKNSEARCH_RESULT_DeleteFrameList(ZknSearchWork *work);
void ZKNSEARCH_RESULT_SetRow1(ZknSearchWork *work, unsigned row, ZknSearchBmpWin *window, int y, int flag);
void ZKNSEARCH_RESULT_Noop1(void);
void ZKNSEARCH_RESULT_Noop2(void);
void ZKNSEARCH_RESULT_SetRow2(ZknSearchWork *work, unsigned row, ZknSearchBmpWin *window, int y, int flag);
void ZKNSEARCH_RESULT_Noop3(void);
void ZKNSEARCH_RESULT_MoveRow1(ZknSearchWork *work, int delta);
void ZKNSEARCH_RESULT_SetRowMulti(ZknSearchWork *work,int index,void *data,int value,int flag);
void ZKNSEARCH_RESULT_Noop4(void);
void ZKNSEARCH_RESULT_MoveRow2(ZknSearchWork *work, int delta);
void ZKNSEARCH_RESULT_SetRow3(ZknSearchWork *work, unsigned row, ZknSearchBmpWin *window, int y, int flag);
void ZKNSEARCH_RESULT_Noop5(void);
void ZKNSEARCH_RESULT_MoveRow3(ZknSearchWork *work, int delta);
void ZKNSEARCH_RESULT_SetRow4(ZknSearchWork *work, unsigned row, ZknSearchBmpWin *window, int y, int flag);
void ZKNSEARCH_RESULT_Noop6(void);
void ZKNSEARCH_RESULT_MoveRow4(ZknSearchWork *work, int delta);
/* END mkheaders: generated region */

#endif
