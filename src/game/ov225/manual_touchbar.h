
struct TcbTask;
#ifndef GAME_OV225_MANUAL_TOUCHBAR_H
#define GAME_OV225_MANUAL_TOUCHBAR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of manual_touchbar.c, prototypes copied from their definitions. */

void *MANUAL_COMMON_CreateTouchbar(char *owner);
void MANUAL_COMMON_DeleteTouchbar(char *touchbar);
void MANUAL_COMMON_UpdateTouchbar(char *touchbar);
void MANUAL_COMMON_SetTouchbarState(char *touchbar,unsigned state);
void MANUAL_COMMON_SetTouchbarSelection(char *touchbar,unsigned count,unsigned selected);
unsigned MANUAL_COMMON_GetTouchbarSelected(char *touchbar);
unsigned MANUAL_COMMON_GetTouchbarPressed(char *touchbar);
void MANUAL_COMMON_TouchbarTaskNoop(struct TcbTask *task, void *data);
void MANUAL_COMMON_CreateTouchbarWidget(char *touchbar);
void MANUAL_COMMON_TouchbarNoop(void *unused);
void MANUAL_COMMON_CreateTouchbarSlots(char *touchbar);
void MANUAL_COMMON_DeleteTouchbarSlots(char *touchbar);
void MANUAL_COMMON_UpdateTouchbarSlots(char *touchbar);
void MANUAL_COMMON_DrawTouchbarIdle(char *touchbar);
void MANUAL_COMMON_DrawTouchbarStart(char *touchbar);
void MANUAL_COMMON_DrawTouchbarEnd(char *touchbar);
void MANUAL_COMMON_DrawTouchbarContinue(char *touchbar);
void MANUAL_COMMON_LoadTouchbarActors(char *touchbar);
void MANUAL_COMMON_DeleteTouchbarActors(char *touchbar);
void MANUAL_COMMON_UpdateTouchbarActors(char *touchbar);
void MANUAL_COMMON_ResetTouchbar(char *touchbar);
/* END mkheaders: generated region */

#endif
