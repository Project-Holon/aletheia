#ifndef GAME_OV206_ZUKAN_INFO_H
#define GAME_OV206_ZUKAN_INFO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_info.c, prototypes copied from their definitions. */

struct ZukanInfo;
struct MsgBank;
struct PrintQueue;
struct Unit;

#include "../types.h"

void *ZUKAN_INFO_CreateFromMon(u16 heap,void *mon,unsigned formTableNeeded,unsigned showCurrent,unsigned mode,unsigned femaleFlag,u8 bgLayerBase,struct Unit *clactUnit,unsigned font,struct PrintQueue *unused,unsigned objOverrideA,unsigned objOverrideB,unsigned objOverrideC);
void *ZUKAN_INFO_Create(u32 heap, u16 species, u16 form, u16 gender, u16 rare, u32 personalParam, u32 formTableNeeded, u32 showCurrent, u32 mode, u32 femaleFlag, u8 bgLayerBase, struct Unit *clactUnit, u32 font, struct PrintQueue *unused, u32 objOverrideA, u32 objOverrideB, u32 objOverrideC);
void ZUKAN_INFO_Delete(char *p);
void ZUKAN_INFO_Update(char *p);
void ZUKAN_INFO_ClearDisplay(char *p);
void ZUKAN_INFO_ClearActors(char *p);
void ZUKAN_INFO_NotifyMoveDone(char *p);
void ZUKAN_INFO_NotifyFadeDone(char *p);
int ZUKAN_INFO_IsMoving(char *p);
int ZUKAN_INFO_IsDone(char *p);
void ZUKAN_INFO_Start(char *p);
void ZUKAN_INFO_SetPokemon(char *p, u16 species, u16 form, u16 gender, u16 rare, int personalParam, int showCurrent);
void ZUKAN_INFO_ShowPage(char *p,int mode);
void ZUKAN_INFO_SetPokemonPage(char *p, u16 species, u16 form, u16 gender, u16 rare, int personalParam, int showCurrent, int page);
void ZUKAN_INFO_Show(struct ZukanInfo *p);
void ZUKAN_INFO_Hide(struct ZukanInfo *p);
void ZUKAN_INFO_Task(int unused, char *p);
void ZUKAN_INFO_CreateWindows(char *p);
void ZUKAN_INFO_DeleteWindows(char *p);
void ZUKAN_INFO_DrawText(int heap,struct BmpWin *window,void *printer,struct GfFont *font,struct Strbuf *input,unsigned short right,unsigned short y,unsigned short color,int alignment,struct WordSet *expansion);
void ZUKAN_INFO_DrawMessage(int heap,struct BmpWin *window,struct MsgBank *bank,void *printer,struct GfFont *font,int message,unsigned short x,unsigned short y,unsigned short color,int alignment,struct WordSet *expansion);
void ZUKAN_INFO_DrawMainPage(char *p);
void ZUKAN_INFO_DrawPage(char *p, int idx);
void ZUKAN_INFO_ClearSlotWindows(char *p);
void ZUKAN_INFO_FlushSlotWindows(char *p);
void ZUKAN_INFO_CreateBgBmp(struct ZukanInfo *e);
void ZUKAN_INFO_DeleteMainWindows(char *p);
void ZUKAN_INFO_FlushMainWindow(void *obj);
void ZUKAN_INFO_SetActors(void *info, void *x, void *y, void *slot);
void ZUKAN_INFO_ReleaseActor(char *p, int i);
void ZUKAN_INFO_RegisterGfx(char *p,int index);
void ZUKAN_INFO_ReleaseGfx(char *p, int i);
void ZUKAN_INFO_CreateActor(char *p,int x,int y,int index);
void ZUKAN_INFO_DeleteActor(char *p, int i);
void ZUKAN_INFO_DisableActors(char *p);
void ZUKAN_INFO_CreateIconActors(struct ZukanInfo *p);
void ZUKAN_INFO_DeleteIconActors(char *p);
void ZUKAN_INFO_ShowFormPair(char *p,int mode,int which);
void ZUKAN_INFO_LayoutFormPair(struct ZukanInfo *p, unsigned x, unsigned y, int row);
void ZUKAN_INFO_LayoutFormPairEx(struct ZukanInfo *p, unsigned x, unsigned y, int z, int row);
void ZUKAN_INFO_DeleteRow(char *p, int index);
void ZUKAN_INFO_DisableOtherRows(struct ZukanInfo *p);
void ZUKAN_INFO_InitFormGfx(struct ZukanInfo *p);
void ZUKAN_INFO_DeleteFormGfx(char *p);
void ZUKAN_INFO_CreateSpeciesActor(struct ZukanInfo *p, u32 a, u32 b, u32 idx);
void ZUKAN_INFO_DeleteActorPair(struct ZukanInfo *p, int i);
void ZUKAN_INFO_DisableUnselected(struct ZukanInfo *p);
void ZUKAN_INFO_RefreshDisplay(struct ZukanInfo *p);
void ZUKAN_INFO_RefreshPage(struct ZukanInfo *p, int v);
s32 ZUKAN_INFO_BlendPalette(struct ZukanInfo *p);
void ZUKAN_INFO_SetDrawEnable(struct ZukanInfo *p, int v);
void ZUKAN_INFO_SetSlotDrawEnable(struct ZukanInfo *p, int v);
void ZUKAN_INFO_LoadResources(struct ZukanInfo *p);
void ZUKAN_INFO_FreeResources(struct ZukanInfo *p);
u32 ZUKAN_INFO_GetTypeArchiveId(void);
int ZUKAN_INFO_GetSpeciesCellFileId(int v);
int ZUKAN_INFO_GetPaletteFileId(int unused);
int ZUKAN_INFO_GetCellAnimFileId(int v);
int ZUKAN_INFO_GetCellAnimMode(int v);
u32 ZUKAN_INFO_GetIconArchiveId(void);
u32 ZUKAN_INFO_GetFormFlag(u32 a, u32 b);
/* END mkheaders: generated region */

#endif
