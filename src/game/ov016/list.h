#ifndef GAME_OV016_LIST_H
#define GAME_OV016_LIST_H

/* Public functions of list.c, prototypes copied from their definitions. */

struct ListCB;
struct tagLISTCB;
typedef struct ListCB ListCB;

ListCB *DWCi_LSTlForm(void);
void DWCi_LSTlDelete(struct tagLISTCB *list);
void DWCi_LSTlErase(void *ob);
void DWCi_LSTlInsert(void *pos, void *ob);
void DWCi_LSTlPushBack(char *p, void *ob);
void DWCi_LSTlPushFront(char *p, void *ob);

#endif
