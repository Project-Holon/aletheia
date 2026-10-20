#ifndef GAME_OV211_ZUKAN_SEARCH_PROC_H
#define GAME_OV211_ZUKAN_SEARCH_PROC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_search_proc.c, prototypes copied from their definitions. */

struct ProcSystem;
struct ZukanSearchOwner;
struct ZukanSearchWork;
struct Proc;

int ZUKAN_SEARCH_PROC_Create(struct ProcSystem *obj,int unused,struct ZukanSearchOwner *owner);
int ZUKAN_SEARCH_PROC_IsDone(int unused1,int unused2,int unused3,struct ZukanSearchWork *work);
int ZUKAN_SEARCH_PROC_Delete(struct Proc *obj);
int ZUKAN_SEARCH_PROC_Update(struct ZukanSearchWork *work);
/* END mkheaders: generated region */

#endif
