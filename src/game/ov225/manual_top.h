#ifndef GAME_OV225_MANUAL_TOP_H
#define GAME_OV225_MANUAL_TOP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of manual_top.c, prototypes copied from their definitions. */

char *MANUAL_COMMON_CreateDialog(char *owner, char *data);
void MANUAL_COMMON_DeleteDialog(char *dialog);
int MANUAL_COMMON_UpdateDialog(char *dialog);
void MANUAL_COMMON_DialogTaskNoop(void *unused);
void MANUAL_COMMON_LoadDialogAssets(char *dialog);
void MANUAL_COMMON_CreateDialogWindows(char *dialog);
void MANUAL_COMMON_SetDialogBgMode(char *dialog);
void MANUAL_COMMON_DeleteDialogStep(char *dialog);
void MANUAL_COMMON_DeleteDialogWindows(char *dialog);
int MANUAL_COMMON_UpdateDialogInput(char *dialog);
/* END mkheaders: generated region */

#endif
