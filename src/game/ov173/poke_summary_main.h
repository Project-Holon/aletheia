#ifndef GAME_OV173_POKE_SUMMARY_MAIN_H
#define GAME_OV173_POKE_SUMMARY_MAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of poke_summary_main.c, prototypes copied from their definitions. */

struct ProcOwner;
struct ScanContext;

#include "../types.h"

int POKE_SUMMARY_MAIN_Create(struct ProcOwner *obj, int unused, u8 *input);
int POKE_SUMMARY_MAIN_Update(void *unused0,u32 *state,void *unused2,u8 *work);
int POKE_SUMMARY_MAIN_Delete(void *work,u32 unused,u32 args,char *ctx);
void POKE_SUMMARY_MAIN_CreateTaskMenu(u8 *work);
void POKE_SUMMARY_MAIN_DeleteTaskMenu(u8 *work);
void POKE_SUMMARY_MAIN_UpdateTaskMenu(int *work);
void POKE_SUMMARY_MAIN_InitScreen(u8 *work);
void POKE_SUMMARY_MAIN_ExitScreen(char *work);
void POKE_SUMMARY_MAIN_VBlankCallback(struct TcbTask *unused, void *work);
void POKE_SUMMARY_MAIN_SetVramBanks(void);
void POKE_SUMMARY_MAIN_InitDisplay(void);
void POKE_SUMMARY_MAIN_ExitDisplay(void);
void POKE_SUMMARY_MAIN_CreateMsgWindows(u8 *work, u8 *archiveHandle);
int POKE_SUMMARY_MAIN_DeleteMsgWindow(int *work);
void POKE_SUMMARY_MAIN_CreateBmpWindows(u8 *work);
void POKE_SUMMARY_MAIN_DeleteBmpWindows(char *work);
void POKE_SUMMARY_MAIN_CreateText(char *work);
void POKE_SUMMARY_MAIN_DeleteText(char *work);
int POKE_SUMMARY_MAIN_WaitWipe(int *work);
int POKE_SUMMARY_MAIN_HandleInput(char *work);
int POKE_SUMMARY_MAIN_UpdateText(char *work);
int POKE_SUMMARY_MAIN_OpenMenu(u8 *work);
int POKE_SUMMARY_MAIN_UpdateMenu(u8 *work);
int POKE_SUMMARY_MAIN_ApplyMove(char **work);
int POKE_SUMMARY_MAIN_ShowTextKind6(int *work);
int POKE_SUMMARY_MAIN_ShowMoveText(char *work);
int POKE_SUMMARY_MAIN_StartWipe(char *work);
void POKE_SUMMARY_MAIN_RefreshMoveList(char *work);
void POKE_SUMMARY_MAIN_PrintAligned(char *work, int index, struct GfFont *font, u16 color, int align, u8 y);
void POKE_SUMMARY_MAIN_PrintValue(char *work,u32 idx,u32 number,u32 digits,u8 padding);
void POKE_SUMMARY_MAIN_DrawMovesPage(char *work);
u32 POKE_SUMMARY_MAIN_CountMoves(struct ScanContext *work);
void POKE_SUMMARY_MAIN_DrawMoveRow(char *work,u8 first,u8 row);
void POKE_SUMMARY_MAIN_RedrawMoveList(char *work);
void POKE_SUMMARY_MAIN_BuildMoveList(char *work);
void POKE_SUMMARY_MAIN_DeleteMoveList(char *work);
void POKE_SUMMARY_MAIN_DrawMoveDetail(char *work,int move);
void POKE_SUMMARY_MAIN_SetTextByKind(char *work, u32 kind);
u16 POKE_SUMMARY_MAIN_GetRecordWord(char **work);
unsigned short POKE_SUMMARY_MAIN_GetMoveWord(int *work);
void POKE_SUMMARY_MAIN_StartTextStream(char *work, u32 kind);
void POKE_SUMMARY_MAIN_ClearWindow(char *work);
int POKE_SUMMARY_MAIN_SoundStateCallback(unsigned int state);
u8 POKE_SUMMARY_MAIN_CountFreeMoves(void ***work);
int POKE_SUMMARY_MAIN_ShowTextKind3(u8 *work);
int POKE_SUMMARY_MAIN_ClearWindowWaitA(char *work);
int POKE_SUMMARY_MAIN_SetFlagReturn8(u8 **pp);
int POKE_SUMMARY_MAIN_ClearWindowWaitB(char *work);
int POKE_SUMMARY_MAIN_Finish(u8 *work);
/* END mkheaders: generated region */

#endif
