#ifndef GAME_OV184_BR_DOWNLOAD_H
#define GAME_OV184_BR_DOWNLOAD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_download.c, prototypes copied from their definitions. */

int BR_DOWNLOAD_Create(void *obj,int b,char *q);
int BR_DOWNLOAD_Delete(int obj,int b,char *q,char *p);
int BR_DOWNLOAD_Main(int a,int b,int c,char *p);
void BR_DOWNLOAD_StepFadeIn(int a, int *state, char *p);
void BR_DOWNLOAD_StepClose(int a, int *state, char *p);
void BR_DOWNLOAD_HandleTouch(int a,int b,char *p);
void BR_DOWNLOAD_DownloadTask(int *task,unsigned *state,char *p);
void BR_DOWNLOAD_Begin3d(char *p, char *q);
void BR_DOWNLOAD_End3d(char *p, char *q);
void BR_DOWNLOAD_CreateButtons(char *p, const char *q);
void BR_DOWNLOAD_ResetSlots(int *slots, char *p);
/* END mkheaders: generated region */

#endif
