#ifndef GAME_OV194_NAMEIN_GRAPHIC_H
#define GAME_OV194_NAMEIN_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of namein_graphic.c, prototypes copied from their definitions. */

#include "../types.h"

void NAMEIN_GRAPHIC_InitGrid(u8 *p,int mode,void *font,void *window,void *data,void *palette,u32 heap);
void NAMEIN_GRAPHIC_DeleteGrid(u8 *p);
void NAMEIN_GRAPHIC_UpdateGrid(char *p,char *q);
int NAMEIN_GRAPHIC_GetGridAction(char *p, unsigned short *out);
u32 NAMEIN_GRAPHIC_GetGridIndex(const u8 *p);
int NAMEIN_GRAPHIC_IsGridDrawDone(char *p);
void *NAMEIN_GRAPHIC_GetGridMode(const u8 *p);
u32 NAMEIN_GRAPHIC_GridIndex(u32 a,u32 b,u32 c);
int NAMEIN_GRAPHIC_SetGridMode(char *p,int mode);
int NAMEIN_GRAPHIC_AnimateGrid(char *p);
void NAMEIN_GRAPHIC_SwitchGridMode(char *p, u32 mode);
void NAMEIN_GRAPHIC_SetGridSelection(char *p,int index,int variant);
int NAMEIN_GRAPHIC_KanaKeyMove(char *p,int *out);
int NAMEIN_GRAPHIC_KanaKeyAction(char *p,int *out);
int NAMEIN_GRAPHIC_KanaTouch(char *p,int *out);
void NAMEIN_GRAPHIC_ApplyKanaAction(char *p,int *input);
int NAMEIN_GRAPHIC_SymbolKeyMove(char *p,int *out);
int NAMEIN_GRAPHIC_SymbolKeyAction(char *p,int *out);
int NAMEIN_GRAPHIC_SymbolTouch(char *p,int *out);
void NAMEIN_GRAPHIC_ApplySymbolAction(char *p,int *input);
void NAMEIN_GRAPHIC_InitMsgBox(unsigned char *p,int a,int b,int c,int d,unsigned short e);
void NAMEIN_GRAPHIC_DeleteMsgBox(u8 *p);
void NAMEIN_GRAPHIC_PrintMsg(char *p,int value);
void NAMEIN_GRAPHIC_PrintPokeMsg(char *p,int value,u32 id,u32 form,u16 heap);
void NAMEIN_GRAPHIC_PrintMonMsg(char *p,int value,void *mon);
int NAMEIN_GRAPHIC_IsMsgDrawDone(u8 *p);
void NAMEIN_GRAPHIC_InitTcbl(char *p, int v);
void NAMEIN_GRAPHIC_DeleteTcbl(unsigned char *p);
void NAMEIN_GRAPHIC_PrintNameStream(char *p,char *q,int *w,u32 heap);
void NAMEIN_GRAPHIC_InitIconActor(u8 *o, u32 mode, u32 iconIndex, u32 iconForm, u32 s0, u32 s1, u32 s2, void *s3, u32 s4, u16 heap);
void NAMEIN_GRAPHIC_DeleteIconActor(unsigned char *p);
void NAMEIN_GRAPHIC_UpdateIconTouch(char *p);
void NAMEIN_GRAPHIC_FlushIconOam(unsigned char *p);
unsigned NAMEIN_GRAPHIC_IsIconAnimDone(unsigned char *p);
void NAMEIN_GRAPHIC_StartIconAnim(unsigned char *p);
int NAMEIN_GRAPHIC_StepIconAnim(char *p);
int NAMEIN_GRAPHIC_GetIconMode(int x, int y);
int NAMEIN_GRAPHIC_IsPointInRect(int *p, int *q);
int NAMEIN_GRAPHIC_GetNameForAction(u8 *p, int a, int b);
void NAMEIN_GRAPHIC_CommitName(char *p);
int NAMEIN_GRAPHIC_IsNameValid(int p);
void NAMEIN_GRAPHIC_InitCallback(u8 *a, u32 b, u32 c);
void NAMEIN_GRAPHIC_ClearCallback(void *p);
void NAMEIN_GRAPHIC_RunCallback(u8 *p);
unsigned NAMEIN_GRAPHIC_GetCallbackState(unsigned char *p);
void NAMEIN_GRAPHIC_SetCallback(unsigned char *p,unsigned value);
void NAMEIN_GRAPHIC_FinishCallback(unsigned char *p);
void NAMEIN_GRAPHIC_CallbackWaitDraw(unsigned char *p,int *unused,unsigned char *q);
void NAMEIN_GRAPHIC_CallbackFadeIn(unsigned char *p,int *state);
void NAMEIN_GRAPHIC_CallbackFadeOut(unsigned char *p,int *state);
void NAMEIN_GRAPHIC_CallbackWaitPrint(unsigned char *a, int *state, char *p);
void NAMEIN_GRAPHIC_CallbackGridAction(unsigned char *owner,void *unused,char *p);
void NAMEIN_GRAPHIC_CallbackFinish(unsigned char *a, int unused, char *p);
void NAMEIN_GRAPHIC_CallbackPauseSave(unsigned char *p,int *state,unsigned char *q);
unsigned char *NAMEIN_GRAPHIC_CreateDisplay(unsigned swap, unsigned short heap);
void NAMEIN_GRAPHIC_DeleteDisplay(unsigned char *p);
void NAMEIN_GRAPHIC_DrawDisplay(u8 *p);
unsigned NAMEIN_GRAPHIC_GetDisplayHandle(unsigned char *p);
void NAMEIN_GRAPHIC_DisplayMainTask(struct TcbTask *a, void *b);
void NAMEIN_GRAPHIC_InitBg(void *p, unsigned short heap);
void NAMEIN_GRAPHIC_ExitBg(void *p);
void NAMEIN_GRAPHIC_Empty(u8 *unused);
void NAMEIN_GRAPHIC_ResetBg(u8 *unused);
void NAMEIN_GRAPHIC_InitClact(unsigned char *p, int a, int b);
void NAMEIN_GRAPHIC_ExitClact(u8 *p);
void NAMEIN_GRAPHIC_DrawClact(u8 *unused);
void NAMEIN_GRAPHIC_VBlankClact(u8 *unused);
u32 NAMEIN_GRAPHIC_LoadWord(const u32 *p);
/* END mkheaders: generated region */

#endif
