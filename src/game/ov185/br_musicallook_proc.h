#ifndef GAME_OV185_BR_POKESEARCH_H
#define GAME_OV185_BR_POKESEARCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_musicallook_proc.c, prototypes copied from their definitions. */

struct BrDownloadOwner;
struct BrPokeSearchWork;
struct BrUtilTask;

int BR_POKESEARCH_CreateWork(void *procSys,int unused,struct BrDownloadOwner *owner);
int BR_POKESEARCH_DestroyWork(void *procSys,int unused,struct BrDownloadOwner *owner,struct BrPokeSearchWork *work);
int BR_POKESEARCH_Update(int task,int unused,int unused2,struct BrPokeSearchWork *work);
void BR_POKESEARCH_OpenTask(struct BrUtilTask *task,int *state,struct BrPokeSearchWork *work);
void BR_POKESEARCH_CloseTask(struct BrUtilTask *task,int *state,struct BrPokeSearchWork *work);
void BR_POKESEARCH_MainTask(struct BrUtilTask *task, int unused, struct BrPokeSearchWork *work);
void BR_POKESEARCH_HandleTouch(struct BrUtilTask *task,int unused,struct BrPokeSearchWork *work);
void BR_POKESEARCH_NetworkTask(struct BrUtilTask *task,unsigned *state,struct BrPokeSearchWork *work);
void BR_POKESEARCH_DownloadDoneTask(struct BrUtilTask *task,int *state,struct BrPokeSearchWork *work);
void BR_POKESEARCH_ExitTask(struct BrUtilTask *task,int *state,struct BrPokeSearchWork *work);
void BR_POKESEARCH_RefreshTask(struct BrUtilTask *task,int *state,struct BrPokeSearchWork *work);
void BR_POKESEARCH_EnterListTask(struct BrUtilTask *task,int *state,struct BrPokeSearchWork *work);
void BR_POKESEARCH_ChangePageTask(struct BrUtilTask *task,int *state,struct BrPokeSearchWork *work);
void BR_POKESEARCH_ChangeCategoryTask(struct BrUtilTask *task,int *state,struct BrPokeSearchWork *work);
void BR_POKESEARCH_CreateSidebar(struct BrPokeSearchWork *work, struct BrDownloadOwner *owner);
void BR_POKESEARCH_ShowBg(struct BrPokeSearchWork *work,struct BrDownloadOwner *owner);
void BR_POKESEARCH_CreateDetail(struct BrPokeSearchWork *work,struct BrDownloadOwner *owner);
void BR_POKESEARCH_DestroyDetail(struct BrPokeSearchWork *work,struct BrDownloadOwner *owner);
void BR_POKESEARCH_CreateText(struct BrPokeSearchWork *work,struct BrDownloadOwner *owner);
void BR_POKESEARCH_DestroyText(struct BrPokeSearchWork *work, struct BrDownloadOwner *unused);
void BR_POKESEARCH_CreateSearch(struct BrPokeSearchWork *work,struct BrDownloadOwner *owner);
void BR_POKESEARCH_DestroySearch(struct BrPokeSearchWork *work,struct BrDownloadOwner *owner);
void BR_POKESEARCH_CreateMsgbox(struct BrPokeSearchWork *work, struct BrDownloadOwner *owner);
void BR_POKESEARCH_DestroyMsgbox(struct BrPokeSearchWork *work, struct BrDownloadOwner *owner);
int BR_POKESEARCH_HitTab(struct BrPokeSearchWork *work, int touchX, int touchY);
int BR_POKESEARCH_HitPrev(struct BrPokeSearchWork *work, int touchX, int touchY);
int BR_POKESEARCH_HitNext(struct BrPokeSearchWork *p,unsigned x,unsigned y);
/* END mkheaders: generated region */

#endif
