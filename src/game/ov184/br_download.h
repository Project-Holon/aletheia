struct Proc;
#ifndef GAME_OV184_BR_DOWNLOAD_H
#define GAME_OV184_BR_DOWNLOAD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_download.c, prototypes copied from their definitions. */

struct BrDownloadOwner;
struct Proc;
struct BrDownloadWork;
struct BrUtilTask;

int BR_DOWNLOAD_Create(void *obj,int b,struct BrDownloadOwner *q);
int BR_DOWNLOAD_Delete(struct Proc *obj,int b,struct BrDownloadOwner *q,struct BrDownloadWork *p);
int BR_DOWNLOAD_Main(int a,int b,int c,struct BrDownloadWork *p);
void BR_DOWNLOAD_StepFadeIn(struct BrUtilTask *a, int *state, struct BrDownloadWork *p);
void BR_DOWNLOAD_StepClose(struct BrUtilTask *a, int *state, struct BrDownloadWork *p);
void BR_DOWNLOAD_HandleTouch(struct BrUtilTask *a,int b,struct BrDownloadWork *p);
void BR_DOWNLOAD_DownloadTask(struct BrUtilTask *task,unsigned *state,struct BrDownloadWork *p);
void BR_DOWNLOAD_Begin3d(struct BrDownloadWork *p, struct BrDownloadOwner *q);
void BR_DOWNLOAD_End3d(struct BrDownloadWork *p, struct BrDownloadOwner *q);
void BR_DOWNLOAD_CreateButtons(struct BrDownloadWork *p, struct BrDownloadOwner *q);
void BR_DOWNLOAD_ResetSlots(struct BrDownloadWork *work, struct BrDownloadOwner *p);
/* END mkheaders: generated region */

#endif
