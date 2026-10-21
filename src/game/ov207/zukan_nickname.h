#ifndef GAME_OV207_ZUKAN_NICKNAME_H
#define GAME_OV207_ZUKAN_NICKNAME_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_nickname.c, prototypes copied from their definitions. */

struct GfFont;
struct ZukanNicknameWork;
typedef struct ZukanNicknameWork ZukanNicknameWork;

#include "../types.h"

char *ZUKAN_NICKNAME_Create(u16 heap,u32 a,u32 b,u32 c,u32 d,u32 e,struct GfFont *f,u32 g,void *h);
void ZUKAN_NICKNAME_Delete(ZukanNicknameWork *p);
int ZUKAN_NICKNAME_Main(ZukanNicknameWork *p);
void ZUKAN_NICKNAME_SetupScreen(ZukanNicknameWork *p);
int ZUKAN_NICKNAME_GetResult(ZukanNicknameWork *p);
void ZUKAN_NICKNAME_TransferPalette(void *a, ZukanNicknameWork *p);
void ZUKAN_NICKNAME_InitKeyboard(ZukanNicknameWork *p);
void ZUKAN_NICKNAME_DeleteKeyboard(ZukanNicknameWork *p);
void ZUKAN_NICKNAME_UpdateInfoWindow(ZukanNicknameWork *a);
/* END mkheaders: generated region */

#endif
