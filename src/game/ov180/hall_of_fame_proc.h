#ifndef GAME_OV180_HALL_OF_FAME_PROC_H
#define GAME_OV180_HALL_OF_FAME_PROC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of hall_of_fame_proc.c, prototypes copied from their definitions. */

struct Proc;

#include "../types.h"
#include "../ov180/hall_of_fame_types.h"

int HALL_OF_FAME_ProcInit(struct Proc *proc, void *unused, u32 args);
int HALL_OF_FAME_ProcMain(int proc, int unused, int unused2, HallOfFameWork *work);
int HALL_OF_FAME_ProcExit(struct Proc *proc);
void HALL_OF_FAME_AddVBlankTaskMon(HallOfFameWork *work);
void HALL_OF_FAME_AddVBlankTaskTrainer(HallOfFameWork *work);
void HALL_OF_FAME_RemoveVBlankTask(HallOfFameWork *work);
void HALL_OF_FAME_VBlankMon(void);
void HALL_OF_FAME_VBlankTrainer(void);
void HALL_OF_FAME_SetVramBanks(int subScreen);
int HALL_OF_FAME_GetVramBanksAddr(int subScreen);
void HALL_OF_FAME_InitGraphicsSystem(void);
void HALL_OF_FAME_ExitGraphicsSystem(void);
void HALL_OF_FAME_SetupDisplay(void);
/* END mkheaders: generated region */

#endif
