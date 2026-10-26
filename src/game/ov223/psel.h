#ifndef GAME_OV223_PSEL_H
#define GAME_OV223_PSEL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of psel.c, prototypes copied from their definitions. */

struct IcaAnime;
struct PselRecord;
struct PselWork;

#include "../types.h"

void PSEL_SetAnimFrame(struct IcaAnime *anime, int frame);
struct PselRecord *PSEL_CreateRecords(u32 heap,u32 count);
void PSEL_DeleteRecords(void *p);
int PSEL_Init(void *a,int unused,void *c);
int PSEL_Exit(void *a, int unused1, int unused2, u8 *ctx);
int PSEL_Main(void *a,int *state,void *b,char *p);
void PSEL_Task(void *unused,char *p);
void PSEL_DrawObjects(char *p);
void PSEL_CreateG3dUtil(char *p);
void PSEL_DeleteG3dUtil(int *p);
void PSEL_SetupListAnime(u8 *p);
void PSEL_DeleteListAnime(char *p);
void PSEL_UpdateListAnime(char *p);
void PSEL_SetupSelectAnime(char *p);
void PSEL_DeleteSelectAnime(char *p);
void PSEL_UpdateSelectAnime(char *p);
void PSEL_SetAnimTarget(char *p,int type,int flag);
int PSEL_IsAnimTargetReached(char *p);
void PSEL_StepAnim(char *p);
void PSEL_SetAnimTargetIndex(char *p,unsigned index);
void PSEL_StepAnimIndex(char *p);
void PSEL_SelectUnit(char *p,unsigned next);
void PSEL_UpdateUnitAnime(char *p);
void PSEL_CreateUnits(char *p);
void PSEL_DeleteUnits(char *p);
int PSEL_InterpolateCurve(s16 *pos,int *size,u16 a,u16 b,u8 c,u8 d,u8 e,u8 f,u32 duration,u8 amplitude,u32 time);
void PSEL_UpdateUnitPositions(struct PselWork *p);
void PSEL_SetUnitVisible(char *p,unsigned selected);
void PSEL_UpdateFadeUnit(char *p);
int PSEL_IsUnitAnimDone(char *p);
void PSEL_UpdateUnitAnime2(char *p);
void PSEL_CreateUnits2(char *p);
void PSEL_DeleteActors(char *p);
void PSEL_SetActorPosition(char *p,int flag);
void PSEL_UpdateActorPosition(char *p);
void PSEL_CreateBmpWindows(u16 *p);
void PSEL_NopBgWindows(int *unused);
void PSEL_InitBgLayers(u16 *p);
void PSEL_ClearBgLayer2(unsigned char *work);
void PSEL_DeleteBgLayers(u16 *p);
void PSEL_NopBgDelete(unsigned char *work);
void PSEL_SetBgSys(const u16 *p);
void PSEL_ClearBgLayerEx(char *unused);
void PSEL_UploadBgPalette(u16 *p);
void PSEL_NopBgUpdate(char *unused);
void PSEL_CreateWin(char *p);
void PSEL_DeleteWin(char *p);
void PSEL_UpdateTcbl(int *p);
int PSEL_UpdateWindows(char *p);
void PSEL_SetMode(char *p, int idx);
int PSEL_IsModeDone(char *a);
void PSEL_UpdateSubWindow(char *p);
void PSEL_PrintSubWindow(char *p, int idx);
void PSEL_ClearWin(char *p);
void PSEL_ClearWin2(char *p);
void PSEL_ClearWin3(char *p);
void PSEL_CreateTaskRes(char *p);
void PSEL_DeleteTaskResData(int *p);
void PSEL_ShowTaskRes(char *p);
void PSEL_DeleteTaskRes(char *p);
void PSEL_UpdateTaskResWin(char *p);
void PSEL_SetTaskResActive(char *p);
u32 PSEL_IsTaskResFinished(char *p);
/* END mkheaders: generated region */

#endif
