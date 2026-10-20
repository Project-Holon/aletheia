#ifndef GAME_OV179_CDEMO_MAIN_H
#define GAME_OV179_CDEMO_MAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of cdemo_main.c, prototypes copied from their definitions. */

struct ProcSystem;

#include "../types.h"

int CDEMO_MAIN_Create(struct ProcSystem *p, u32 b, u32 c);
int CDEMO_MAIN_Update(int a, int b, int c, int d);
int CDEMO_MAIN_Destroy(void *p);
void CDEMO_MAIN_SetupVram(void);
void CDEMO_MAIN_SetupScreen(char *unused);
void CDEMO_MAIN_HidePlane(void);
void CDEMO_MAIN_SetScript(char *p);
void CDEMO_MAIN_Noop(char *p);
void CDEMO_MAIN_StartTask(int *p);
void CDEMO_MAIN_StopTask(char *p);
/* END mkheaders: generated region */

#endif
