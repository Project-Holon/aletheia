#ifndef GAME_OV181_STAFF_ROLL_H
#define GAME_OV181_STAFF_ROLL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of staff_roll.c, prototypes copied from their definitions. */

struct Proc;

#include "../types.h"

int STAFF_ROLL_Init(struct Proc *p, int unused, void *arg);
int STAFF_ROLL_Main(int unused0, int unused1, int unused2, char *work);
int STAFF_ROLL_Exit(void *p);
int STAFF_ROLL_RunState(char *p);
int STAFF_ROLL_Setup(u8 *p);
int STAFF_ROLL_CheckWipeDone(char *p);
int STAFF_ROLL_Teardown(char *p);
int STAFF_ROLL_StateWaitIntro(char *p);
int STAFF_ROLL_RunScript(char *p);
void STAFF_ROLL_SetupVramBanks(void);
void STAFF_ROLL_SetupBackgrounds(void);
void STAFF_ROLL_TeardownBackgrounds(void);
void STAFF_ROLL_LoadGraphics(void);
void STAFF_ROLL_ReloadGraphics(void *unused, int mode);
void STAFF_ROLL_VblankTask(struct TcbTask *task, void *p);
void STAFF_ROLL_AddVblankTask(char *p);
void STAFF_ROLL_RemoveVblankTask(char *p);
void STAFF_ROLL_InitText(char *p);
void STAFF_ROLL_DeleteText(char *p);
void STAFF_ROLL_BuildRowList(char *p);
void STAFF_ROLL_DeleteRowList(char *p);
void STAFF_ROLL_PrintRow(char *p, void *s, unsigned rowIndex);
void STAFF_ROLL_PrintNextRow(char *p);
void STAFF_ROLL_BlitRow(char *p);
void STAFF_ROLL_LoadRows(char *p);
void STAFF_ROLL_FreeRows(char *p);
void STAFF_ROLL_InitWindows(char *p);
void STAFF_ROLL_DeleteWindows(char *p);
void STAFF_ROLL_SetWindowFlags(char *p, u32 flags);
void STAFF_ROLL_FlushWindows(char *p);
void STAFF_ROLL_Init3d(char *p);
void STAFF_ROLL_Exit3d(char *p);
void STAFF_ROLL_Draw3d(char *p);
void STAFF_ROLL_InitLights(u8 *p);
void STAFF_ROLL_QueueLight(u8 *p, int index, int duration);
void STAFF_ROLL_AdvanceLights(u8 *p);
void STAFF_ROLL_UpdateLights(char *p);
void STAFF_ROLL_SetLightMode(u8 *p, u32 mode);
int STAFF_ROLL_StartWipe(u8 *p, int delay);
void STAFF_ROLL_UpdateBrightness(char *p);
void STAFF_ROLL_UpdateInput(u8 *p);
void STAFF_ROLL_ShiftRow(u8 *p,u8 *out,u32 n);
void STAFF_ROLL_ScrollWindows(char *p);
void STAFF_ROLL_PrintText(char *p, unsigned char *q, void *s, int y);
void STAFF_ROLL_PrintRowText(char *p,u8 *q);
void STAFF_ROLL_PrintEntry(char *p, unsigned char *q);
int STAFF_ROLL_StepFadeIn(char *p);
int STAFF_ROLL_StepFadeOut(char *p);
int STAFF_ROLL_StepWindowSlide(char *p);
int STAFF_ROLL_CmdPrintEntry(char *p, unsigned char *q);
int STAFF_ROLL_CmdShowEntry(char *p, unsigned char *q);
int STAFF_ROLL_CmdSetEntryMode(char *p, unsigned char *q);
int STAFF_ROLL_CmdStartScroll(char *p);
int STAFF_ROLL_CmdStopScroll(char *p);
int STAFF_ROLL_CmdEnd(char *p);
int STAFF_ROLL_CmdNop(void);
int STAFF_ROLL_CmdShowPlane(void);
int STAFF_ROLL_CmdHidePlane(void);
int STAFF_ROLL_CmdQueueLight(u8 *p,u8 *q);
int STAFF_ROLL_CmdSetRecord(char *ctx, unsigned char *rec);
/* END mkheaders: generated region */

#endif
