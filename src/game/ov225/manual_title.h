
struct TcbTask;
#ifndef GAME_OV225_MANUAL_TITLE_H
#define GAME_OV225_MANUAL_TITLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of manual_title.c, prototypes copied from their definitions. */

struct ManualMenuList;
struct ManualDetailOwner;
struct ManualData;

struct ManualMenuList *MANUAL_CATEGORY_CreateDetailList(struct ManualDetailOwner *p, struct ManualData *data);
void MANUAL_CATEGORY_DeleteDetailList(char *p);
int MANUAL_CATEGORY_IsDetailFinished(char *p);
void MANUAL_CATEGORY_DetailTaskNoop(struct TcbTask *unused0, void *unused1);
/* END mkheaders: generated region */

#endif
