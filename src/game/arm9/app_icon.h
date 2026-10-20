#ifndef GAME_ARM9_APP_ICON_H
#define GAME_ARM9_APP_ICON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of app_icon.c, prototypes copied from their definitions. */

struct ArcHandle;
struct PokemonParam;

#include "../types.h"

u32 APP_ICON_GetArchiveId(void);
u32 APP_ICON_GetTouchBarFileId(void);
u8 APP_ICON_GetTypePaletteOffset(int type);
u32 APP_ICON_GetTypeCellFileId(u32 type);
u32 APP_ICON_GetTypePaletteFileId(u32 mapping);
u32 APP_ICON_GetTypeAnimFileId(u32 mapping);
u8 APP_ICON_GetMoveKindPaletteOffset(u8 kind);
u32 APP_ICON_GetMoveKindCellFileId(u32 kind);
u32 APP_ICON_GetMoveKindPaletteFileId(void);
u32 APP_ICON_GetMoveKindAnimFileId(void);
u32 APP_ICON_GetStatusCellFileId(u32 mapping);
u32 APP_ICON_GetStatusPaletteFileId(u32 mapping);
u32 APP_ICON_GetStatusAnimFileId(void);
u32 APP_ICON_GetStatusFrameFileId(void);
u32 APP_ICON_GetStatusDataFileId(void);
u32 APP_ICON_GetStatusExtraFileId(void);
void APP_ICON_LoadTouchBar(struct ArcHandle *arc, int bgFrame, u32 heapId, int charOffset, u32 palNo);
u32 APP_ICON_GetItemCellFileId(void);
u32 APP_ICON_GetItemPaletteFileId(void);
u32 APP_ICON_GetItemAnimFileId(u32 mapping);
u32 APP_ICON_GetItemFrameFileId(u32 mapping);
u32 APP_ICON_GetItemDataFileId(void);
u32 APP_ICON_GetItemExtraFileId(void);
u32 APP_ICON_GetItemAnim2FileId(u32 mapping);
u32 APP_ICON_GetItemFrame2FileId(u32 mapping);
u32 APP_ICON_GetSealCellFileId(void);
u32 APP_ICON_GetSealPaletteFileId(void);
u32 APP_ICON_GetSealAnimFileId(u32 mapping);
u32 APP_ICON_GetSealFrameFileId(u32 mapping);
int APP_ICON_GetStatusIconAnim(const struct PokemonParam *pp);
int APP_ICON_GetBallCellFileId(int mapping);
int APP_ICON_GetBallPaletteFileId(int mapping);
int APP_ICON_GetBallAnimFileId(int mapping);
int APP_ICON_GetBallFrameFileId(int mapping);
int APP_ICON_GetBallThrowCellFileId(int ballId);
int APP_ICON_GetBallThrowAnimFileId(int ballId);
int APP_ICON_GetBallOpenCellFileId(int ballId, int mapping);
int APP_ICON_GetBallOpenPaletteFileId(int ballId, int mapping);
int APP_ICON_GetBallOpenAnimFileId(void);
int APP_ICON_GetEffectCellFileId(int mapping);
int APP_ICON_GetEffectPaletteFileId(int mapping);
int APP_ICON_GetEffectAnimFileId(int mapping);
int APP_ICON_GetNoneFileId(void);
int APP_ICON_GetGearCellFileId(int mapping);
int APP_ICON_GetGearPaletteFileId(int mapping);
int APP_ICON_GetGearAnimFileId(int mapping);
int APP_ICON_GetGearDataFileId(void);
int APP_ICON_GetGearExtraFileId(int mapping);
int APP_ICON_GetGearFrameFileId(int mapping);
int APP_ICON_GetGearAnim2FileId(int mapping);
/* END mkheaders: generated region */

#endif
