#ifndef GAME_OV072_TOWNMAP_GRH_H
#define GAME_OV072_TOWNMAP_GRH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of townmap_grh.c, prototypes copied from their definitions. */

struct ClactActor;
struct DispVram;

#include "../ov072/townmap_types.h"
#include "../types.h"
#include "../ov072/townmap_grh_types.h"

void TOWNMAP_GRH_InitTextBox(TownMapTextBox *box, int bgId, void *font, void *msg, u8 x, u8 y, u8 width, u8 height, u16 heapId);
void TOWNMAP_GRH_ExitTextBox(TownMapTextBox *box);
void TOWNMAP_GRH_PrintTextBoxMessage(TownMapTextBox *box, u32 msgId, int x, int y);
void TOWNMAP_GRH_ClearTextBox(TownMapTextBox *box);
void TOWNMAP_GRH_InitLabel(TownMapLabel *label, int bgId, void *font, void *msg, struct ClactActor *marker, u16 heapId);
void TOWNMAP_GRH_ExitLabel(TownMapLabel *label);
void TOWNMAP_GRH_UpdateLabel(TownMapLabel *label);
void TOWNMAP_GRH_SetLabelTown(TownMapLabel *label, TownMapTown *town);
void TOWNMAP_GRH_SetLabelVisible(TownMapLabel *label, u32 visible);
void TOWNMAP_GRH_InitTouch(TownMapTouch *touch, int heapId);
void TOWNMAP_GRH_ClearTouch(TownMapTouch *touch);
void TOWNMAP_GRH_UpdateTouch(TownMapTouch *touch);
int TOWNMAP_GRH_GetTouchDrag(TownMapTouch *touch, TownMapVec *delta, u32 *dragState);
void TOWNMAP_GRH_RestartTouchDrag(TownMapTouch *touch);
void TOWNMAP_GRH_EmptyTask(void *task, void *arg);
TownMapGfx *TOWNMAP_GRH_Create(u16 heapId);
void TOWNMAP_GRH_Delete(TownMapGfx *gfx);
void TOWNMAP_GRH_DrawSprites(TownMapGfx *gfx);
u8 TOWNMAP_GRH_GetBgId(TownMapGfx *gfx, u32 i);
struct Unit *TOWNMAP_GRH_GetHandle(TownMapGfx *gfx, int n);
struct ClactActor *TOWNMAP_GRH_GetActor(TownMapGfx *gfx, int n);
void TOWNMAP_GRH_GetResourceIds(TownMapGfx *gfx, int *charId, int *cellId, int *palId);
void TOWNMAP_GRH_ResetDisplay(void);
void TOWNMAP_GRH_UpdateTask(void *task, void *gfx);
void TOWNMAP_GRH_InitBgLayers(TownMapGfx *gfx, u16 heapId);
void TOWNMAP_GRH_ExitBgLayers(TownMapGfx *gfx);
void TOWNMAP_GRH_TransferBgData(TownMapGfx *gfx);
void TOWNMAP_GRH_InitSprites(TownMapSprites *sprites, const struct DispVram *banks, u16 heapId);
void TOWNMAP_GRH_ExitSprites(TownMapSprites *sprites);
void TOWNMAP_GRH_DrawClactSystem(int arg);
void TOWNMAP_GRH_VBlankSprites(TownMapSprites *sprites);
struct ClactActor *TOWNMAP_GRH_GetSpriteActor(TownMapSprites *sprites, int n);
struct Unit *TOWNMAP_GRH_GetSpriteHandle(TownMapSprites *sprites, int n);
int TOWNMAP_GRH_GetSpriteResourceId(TownMapSprites *sprites, int i);
TownMapInfoRow *TOWNMAP_GRH_LoadTownInfo(int heapId);
void TOWNMAP_GRH_FreeTownInfo(TownMapInfoRow *info);
unsigned short TOWNMAP_GRH_GetTownInfoValue(TownMapInfoRow *info, u16 row, int col);
int TOWNMAP_GRH_FindRecordIndex(TownMapInfoRow *info, int id);
/* END mkheaders: generated region */

#endif
