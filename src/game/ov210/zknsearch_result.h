#ifndef GAME_OV210_ZKNSEARCH_RESULT_H
#define GAME_OV210_ZKNSEARCH_RESULT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zknsearch_result.c, prototypes copied from their definitions. */

#include "../types.h"

void ZKNSEARCH_RESULT_InitFrameList(char *ctx);
void ZKNSEARCH_RESULT_DeleteFrameList(u8 *work);
void ZKNSEARCH_RESULT_SetRow1(int work, unsigned row, int window, int y, int flag);
void ZKNSEARCH_RESULT_Noop1(void);
void ZKNSEARCH_RESULT_Noop2(void);
void ZKNSEARCH_RESULT_SetRow2(int work, unsigned row, int window, int y, int flag);
void ZKNSEARCH_RESULT_Noop3(void);
void ZKNSEARCH_RESULT_MoveRow1(int work, int delta);
void ZKNSEARCH_RESULT_SetRowMulti(char *work,int index,void *data,int value,int flag);
void ZKNSEARCH_RESULT_Noop4(void);
void ZKNSEARCH_RESULT_MoveRow2(int work, int delta);
void ZKNSEARCH_RESULT_SetRow3(int work, unsigned row, int window, int y, int flag);
void ZKNSEARCH_RESULT_Noop5(void);
void ZKNSEARCH_RESULT_MoveRow3(int work, int delta);
void ZKNSEARCH_RESULT_SetRow4(ZknSearchWork *work, unsigned row, unsigned *window, int y, int flag);
void ZKNSEARCH_RESULT_Noop6(void);
void ZKNSEARCH_RESULT_MoveRow4(int work, int delta);
/* END mkheaders: generated region */

#endif
