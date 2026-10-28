#ifndef GAME_OV088_SAVE_CONTROL_INTR_H
#define GAME_OV088_SAVE_CONTROL_INTR_H
struct SaveControl;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of save_control_intr.c, prototypes copied from their definitions. */

struct SaveControlIntr;
typedef struct SaveControlIntr SaveControlIntr;

#include "../types.h"

void *SAVE_CONTROL_INTR_Create(int heapId, struct SaveControl *saveControl);
void SAVE_CONTROL_INTR_Delete(void *p);
void SAVE_CONTROL_INTR_Start(SaveControlIntr *intr);
u32 SAVE_CONTROL_INTR_Update(SaveControlIntr *intr);
void SAVE_CONTROL_INTR_Pause(SaveControlIntr *intr);
void SAVE_CONTROL_INTR_Resume(SaveControlIntr *intr);
int SAVE_CONTROL_INTR_IsPausedOrFinished(SaveControlIntr *intr);
void SAVE_CONTROL_INTR_NoOp(void *intr);
int SAVE_CONTROL_INTR_IsFinished(SaveControlIntr *intr);
void SAVE_CONTROL_INTR_Cancel(void *arg);
/* END mkheaders: generated region */

#endif
