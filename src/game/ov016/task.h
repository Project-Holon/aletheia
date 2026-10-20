#ifndef GAME_OV016_TASK_H
#define GAME_OV016_TASK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of task.c, prototypes copied from their definitions. */

struct TCB;
typedef struct TCB TCB;

void DWCi_TSKlInit(void);
void DWCi_TSKlEnd(void);
void DWCi_TSKlAct(int kind);
TCB *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
void DWCi_TSKlChangeFunc(TCB *task, void (*func)(void *, void *));
void DWCi_TSKlDelete(int kind, void *task);
void DWCi_TSKlDeleteEx(unsigned int kind, TCB *task);
void DWCi_TSKlOperate(int kind, unsigned char flag);
/* END mkheaders: generated region */

#endif
