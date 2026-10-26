
struct TcbTask;
#ifndef GAME_OV225_MANUAL_CATEGORY_H
#define GAME_OV225_MANUAL_CATEGORY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of manual_category.c, prototypes copied from their definitions. */

char *MANUAL_CATEGORY_CreateList(char *p,char *data);
void MANUAL_CATEGORY_DeleteList(char *p);
int MANUAL_CATEGORY_IsListFinished(char *p);
void MANUAL_CATEGORY_TaskNoop(struct TcbTask *unused0, void *unused1);
/* END mkheaders: generated region */

#endif
