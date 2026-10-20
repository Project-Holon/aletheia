#ifndef GAME_OV016_ATERMSET_H
#define GAME_OV016_ATERMSET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of atermset.c, prototypes copied from their definitions. */

struct _ATERMApConfigState;
typedef struct _ATERMApConfigState ATERMApConfigState;

void *soAlloc(unsigned long name, long size);
void soFree(unsigned long name, void *ptr, long size);
int DWCi_RakurakuATERMi_ApConfigStart(int prio, int maxap, void (*notify)(struct _ATERMApConfigState *), void *(*alloc)(unsigned long), void (*free)(void *), unsigned long stackSize);
int ATERMi_ApConfigEnd(void);
int ATERMi_ApConfigGetState(ATERMApConfigState *state);
int DWCi_RakurakuATERMi_ApConfigGetResult(int a);
/* END mkheaders: generated region */

#endif
