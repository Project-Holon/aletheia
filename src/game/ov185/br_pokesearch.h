#ifndef GAME_OV185_BR_POKESEARCH_H
#define GAME_OV185_BR_POKESEARCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_pokesearch.c, prototypes copied from their definitions. */

int BR_POKESEARCH_CreateWork(void *procSys,int unused,char *owner);
int BR_POKESEARCH_DestroyWork(int procSys,int unused,char *owner,char *work);
int BR_POKESEARCH_Update(int task,int unused,int unused2,char *work);
void BR_POKESEARCH_OpenTask(int task,int *state,char *work);
void BR_POKESEARCH_CloseTask(int task,int *state,char *work);
void BR_POKESEARCH_MainTask(int task, int unused, char *work);
void BR_POKESEARCH_HandleTouch(int task,int unused,char *work);
void BR_POKESEARCH_NetworkTask(int *task,unsigned *state,char *work);
void BR_POKESEARCH_DownloadDoneTask(int task,int *state,char *work);
void BR_POKESEARCH_ExitTask(int *task,int *state,char *work);
void BR_POKESEARCH_RefreshTask(int *task,int *state,char *work);
void BR_POKESEARCH_EnterListTask(int *task,int *state,char *work);
void BR_POKESEARCH_ChangePageTask(int *task,int *state,char *work);
void BR_POKESEARCH_ChangeCategoryTask(int *task,int *state,char *work);
void BR_POKESEARCH_CreateSidebar(char *work, int *owner);
void BR_POKESEARCH_ShowBg(char *work,char *owner);
void BR_POKESEARCH_CreateDetail(char *work,char *owner);
void BR_POKESEARCH_DestroyDetail(char *work,char *owner);
void BR_POKESEARCH_CreateText(char *work,int *owner);
void BR_POKESEARCH_DestroyText(char *work, int *unused);
void BR_POKESEARCH_CreateSearch(char *work,int *owner);
void BR_POKESEARCH_DestroySearch(char *work,char *owner);
void BR_POKESEARCH_CreateMsgbox(char *work, int *owner);
void BR_POKESEARCH_DestroyMsgbox(char *work, char *owner);
int BR_POKESEARCH_HitTab(int work, int touchX, int touchY);
int BR_POKESEARCH_HitPrev(int a, int b, int c);
int BR_POKESEARCH_HitNext(char *p,unsigned x,unsigned y);
/* END mkheaders: generated region */

#endif
