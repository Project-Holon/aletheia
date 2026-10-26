#ifndef GAME_OV174_LOCAL_TVT_CHARA_H
#define GAME_OV174_LOCAL_TVT_CHARA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of local_tvt_chara.c, prototypes copied from their definitions. */

#include "../types.h"

char *LOCAL_TVT_CHARA_Create(char *p,int index);
void LOCAL_TVT_CHARA_Delete(unsigned char *unused,char *p);
void LOCAL_TVT_CHARA_Update(u8 *p,u8 *q);
void LOCAL_TVT_CHARA_SetActive(u8 *unused,u8 *q,int unused2);
int LOCAL_TVT_CHARA_IsDone(u8 *unused, char *p);
void LOCAL_TVT_CHARA_SetupPalette(char *p,u8 *q);
void LOCAL_TVT_CHARA_SetupActors(u8 *p, u8 *q);
void LOCAL_TVT_CHARA_LoadPalette(char *p, char *q, int id);
void LOCAL_TVT_CHARA_CopyTiles(u8 *a, u8 *b, int c, int d, int e);
void LOCAL_TVT_CHARA_DrawLabel(u8 *p,u8 *q);
void LOCAL_TVT_CHARA_ShowWindow(u8 *a, u8 *p);
unsigned LOCAL_TVT_CHARA_GetState(unsigned char *p);
void LOCAL_TVT_CHARA_SetState(char *p, int v);
void LOCAL_TVT_CHARA_ClearState(char *p);
/* END mkheaders: generated region */

#endif
