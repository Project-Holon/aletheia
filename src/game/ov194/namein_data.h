#ifndef GAME_OV194_NAMEIN_DATA_H
#define GAME_OV194_NAMEIN_DATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of namein_data.c, prototypes copied from their definitions. */

#include "../types.h"

void *NAMEIN_GRAPHIC_LoadArcMember(u32 a, u16 b);
void NAMEIN_GRAPHIC_FreeMember(void *p);
u32 *NAMEIN_GRAPHIC_CreateMembers(u16 heap);
void NAMEIN_GRAPHIC_DeleteMembers(u8 *p);
u32 NAMEIN_GRAPHIC_GetWord(const u8 *p, u32 i);
u16 NAMEIN_GRAPHIC_GetGridWidth(const u16 *p);
u16 NAMEIN_GRAPHIC_GetGridHeight(const u16 *p);
u32 NAMEIN_GRAPHIC_GetGridCell(u8 *p, u16 a, u16 b);
void *NAMEIN_GRAPHIC_LoadCharMember(int a, u16 b);
void NAMEIN_GRAPHIC_FreeHandle(void *p);
u16 NAMEIN_GRAPHIC_GetTableCount(const u16 *p);
void NAMEIN_GRAPHIC_CopyTableEntries(const char *p,int i,u16 *dst,u32 n,u8 *count);
int NAMEIN_GRAPHIC_PickTable8(int p, int idx, unsigned short *tab, int val, unsigned char *out);
int NAMEIN_GRAPHIC_PickTableE(int p, int idx, unsigned short *tab, int val, unsigned char *out);
int NAMEIN_GRAPHIC_PickTable14(char *p, int index, unsigned short *table, unsigned n, unsigned char *out);
u16 NAMEIN_GRAPHIC_FindTableIndex(const char *p,const u16 *b);
int NAMEIN_GRAPHIC_CompareEntry(const unsigned short *a, const unsigned short *b);
void *NAMEIN_GRAPHIC_LoadPairMember(u16 a);
void NAMEIN_GRAPHIC_FreePairMember(void *p);
int NAMEIN_GRAPHIC_GetPairCount(const u16 *p);
unsigned short NAMEIN_GRAPHIC_GetPairEntry(char *base, int i, int j);
int NAMEIN_GRAPHIC_NextPairChar(char *p, const unsigned short *key, unsigned short *out);
u32 NAMEIN_GRAPHIC_IsNameCharValid(u16 *s, u32 x);
/* END mkheaders: generated region */

#endif
