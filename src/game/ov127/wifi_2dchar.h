#ifndef GAME_OV127_WIFI_2DCHAR_H
#define GAME_OV127_WIFI_2DCHAR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifi_2dchar.c, prototypes copied from their definitions. */

struct Wifi2dcharContext;
struct Wifi2dcharActor;
typedef struct Wifi2dcharContext Wifi2dcharContext;
typedef struct Wifi2dcharActor Wifi2dcharActor;

#include "../types.h"

Wifi2dcharContext *WIFI_2DCHAR_Create(void *a, void *b, u32 count, u32 heap);
void WIFI_2DCHAR_Delete(u8 *p);
void WIFI_2DCHAR_SetupBmpCell(u8 *p, int a, int b, int c, int d);
void WIFI_2DCHAR_ReleaseCells(u8 *p);
void WIFI_2DCHAR_SetupCells(u8 *p,int a,int b,int c,int d);
void WIFI_2DCHAR_ReleaseBmpCells(u8 *p);
void WIFI_2DCHAR_RegisterBmp(u8 *p, int a, int b, int c);
void WIFI_2DCHAR_ReleaseBmp(u8 *p);
Wifi2dcharActor *WIFI_2DCHAR_SpawnActor(Wifi2dcharContext *ctx, const s16 *pos, int idx, u32 heap);
void WIFI_2DCHAR_DeleteActor(u8 *p);
void WIFI_2DCHAR_SetActorPos(u8 *p,int x,int y);
void WIFI_2DCHAR_SetActorDrawPriority(u8 *p, u32 v);
int WIFI_2DCHAR_GetActorDrawPriority(u8 *p);
void WIFI_2DCHAR_SetActorDrawEnable(char *p, int a);
void WIFI_2DCHAR_SetSubActorDrawEnable(char *p, int a);
int WIFI_2DCHAR_GetActorDrawEnable(char *p);
u32 WIFI_2DCHAR_GetActorCellArgB(u8 *p);
u32 WIFI_2DCHAR_GetActorAnimId(char *p);
void WIFI_2DCHAR_SetActorAnimIndex(char *p,u32 a);
int WIFI_2DCHAR_GetActorAnimSeqCount(char *p);
void WIFI_2DCHAR_SetSubActorPos(char *p,int x,int y);
void WIFI_2DCHAR_SetActorAnim(Wifi2dcharActor *p, int idx, int a);
void WIFI_2DCHAR_StepActorAnim(u8 *p);
void WIFI_2DCHAR_RegisterCellAnims(char *p, int unused, u32 heap);
void WIFI_2DCHAR_ReleaseCellAnims(char *p, int unused);
int WIFI_2DCHAR_GetCellIndex(int a);
int WIFI_2DCHAR_IsBmpCellEnabled(int unused0, int unused1);
void WIFI_2DCHAR_RegisterCell(char *p, int i, int a, int b, int c, int mode);
void WIFI_2DCHAR_RegisterBmpCharCell(Wifi2dcharContext *ctx, int i, u32 a, u32 b, u32 c);
void WIFI_2DCHAR_RegisterCharCell(u8 *p, int i, u32 a, u32 b, u32 c);
void WIFI_2DCHAR_ReleaseCell(char *p, int i);
void WIFI_2DCHAR_ReleaseCellPair(char *p,int i);
void WIFI_2DCHAR_ReleaseCellChar(u8 *p, int i);
int WIFI_2DCHAR_IsCellUsed(char *p, int i);
void WIFI_2DCHAR_RegisterBmpHandles(u8 *p, u32 a, u32 heap);
void WIFI_2DCHAR_ReleaseBmpHandles(char *p);
int WIFI_2DCHAR_IsHandleValid(int *p);
void WIFI_2DCHAR_RegisterPalette(u8 *p,u32 a,u32 b,u32 heap);
void WIFI_2DCHAR_ReleasePalette(u8 *p);
void WIFI_2DCHAR_RegisterBmpAnims(u8 *p,u32 heap);
void WIFI_2DCHAR_ReleaseBmpAnims(u8 *p);
void *WIFI_2DCHAR_FindFreeActor(u8 *p);
void WIFI_2DCHAR_StepActorAnimDispatch(u8 *p);
void WIFI_2DCHAR_SetAnimSeq(u8 *p, u32 i);
void WIFI_2DCHAR_SetAnimSeq4(u8 *p, u32 i);
void WIFI_2DCHAR_SetAnimSeqPlus5(u8 *p, u32 i);
void WIFI_2DCHAR_AdvanceAnimSeq(u8 *p, u32 i);
void WIFI_2DCHAR_SetAnimSeqPlus9(u8 *p, u32 i);
void WIFI_2DCHAR_SetAnimSeqPlus5B(u8 *p, u32 i);
void WIFI_2DCHAR_SetAnimSeqPlus5C(u8 *p, u32 i);
void WIFI_2DCHAR_SetAnimSeqPlus5D(u8 *p, u32 i);
void WIFI_2DCHAR_SetAnimSeqPlus5E(u8 *p, u32 i);
void WIFI_2DCHAR_AddAnimFrame(u8 *p);
void WIFI_2DCHAR_AddAnimFrame2(u8 *p);
/* END mkheaders: generated region */

#endif
