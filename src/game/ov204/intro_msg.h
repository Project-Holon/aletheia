#ifndef GAME_OV204_INTRO_MSG_H
#define GAME_OV204_INTRO_MSG_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of intro_msg.c, prototypes copied from their definitions. */

#include "../types.h"

char *INTRO_MSG_Create(u16 heap);
void INTRO_MSG_Delete(char *p);
void INTRO_MSG_SetMsgBank(char *p, unsigned a, unsigned short b);
void INTRO_MSG_Main(u8*p);
void INTRO_MSG_PrintText(char *p, void *a, int flag);
void INTRO_MSG_DrawWindowBorder(u8*p);
u32 INTRO_MSG_GetPrintState(u8*p);
int INTRO_MSG_UpdatePrint(char *a);
int *INTRO_MSG_InitMenuDesc(char *p, int v);
void INTRO_MSG_CreateMenuList(char *p,u32 *entries,u32 count,int flag);
void INTRO_MSG_DrawMenuList(char *p);
void INTRO_MSG_MainMenuList(u8 *p);
int INTRO_MSG_GetMenuChoice(u8 *p,int *out);
int INTRO_MSG_GetWordSet(u8 *p);
void INTRO_MSG_StartTimeIcon(u8 *p);
void INTRO_MSG_DeleteTimeIcon(u8 *p);
/* END mkheaders: generated region */

#endif
