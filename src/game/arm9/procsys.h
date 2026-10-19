#ifndef GAME_ARM9_PROCSYS_H
#define GAME_ARM9_PROCSYS_H

/* Public functions of procsys.c, prototypes copied from their definitions. */

struct Proc;
typedef struct Proc Proc;

void PROCSYS_CreateGlobal(int heapId);
int PROCSYS_MainGlobal(void);
void *PROCSYS_Create(int heapId);
void PROCSYS_FreeProc(Proc *proc);
void *PROCSYS_AllocProcWork(Proc *proc, u32 size, u32 heapId);
void PROCSYS_FreeProcWork(Proc *proc);
u32 PROCSYS_StepProc(Proc *proc);

#endif
