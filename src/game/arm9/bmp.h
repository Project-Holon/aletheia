#ifndef GAME_ARM9_BMP_H
#define GAME_ARM9_BMP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of bmp.c, prototypes copied from their definitions. */

struct Bmp;

#include "../types.h"
#include "../arm9/nns_g2d_res_types.h"

struct Bmp *BMP_Create(u32 widthTiles, u32 heightTiles, u32 tileBytes, u16 heapId);
struct Bmp *BMP_CreateFromBuffer(void *pixels, u32 widthTiles, u32 heightTiles, u32 tileBytes, u16 heapId);
struct Bmp *BMP_CreateFromVram(void *pixels, u32 widthTiles, u32 heightTiles, u32 tileBytes, u16 heapId);
void BMP_Delete(struct Bmp *bmp);
void *BMP_GetPixels(const struct Bmp *bmp);
u16 BMP_GetWidth(const struct Bmp *bmp);
u16 BMP_GetHeight(const struct Bmp *bmp);
u32 BMP_GetByteSize(const struct Bmp *bmp);
void BMP_CopyPixels(const struct Bmp *src, struct Bmp *dst);
struct Bmp *BMP_CreateFromArchive(u32 arcId, u32 memberId, u32 compressed, u32 heapId);
void BMP_InitFromCharData(struct Bmp *bmp, NNSG2dCharacterData *charData, u32 heapId);
u8 BMP_GetTileBytes(struct Bmp *bmp);
void BMP_Blit(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY, int dstX, int dstY, u32 w, u32 h, u16 colorKey);
void BMP_BlitPaletteOffset(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY, u32 dstX, u32 dstY, u32 w, u32 h, u16 colorKey, u16 paletteBase);
void BMP_FillRect(struct Bmp *bmp, u32 x, u32 y, u32 w, u16 h, u8 value);
void BMP_Clear(struct Bmp *bmp, u8 value);
void BMP_Blit4bpp(struct Bmp *src, struct Bmp *dst, s32 srcX, s32 srcY, s32 dstX, s32 dstY, u32 w, u32 h, u16 colorKey);
void BMP_Blit8bpp(struct Bmp *src, struct Bmp *dst, s32 srcX, s32 srcY, s32 dstX, s32 dstY, u32 w, u32 h, u16 colorKey);
void BMP_Blit4bppTo8bpp(struct Bmp *src, struct Bmp *dst, s32 srcX, s32 srcY, s32 dstX, s32 dstY, u32 w, u32 h, u16 colorKey, u8 paletteBase);
void BMP_Blit4bppToVram(struct Bmp *src, struct Bmp *dst, u16 srcX, u16 srcY, s16_p07 dstX, s16_p07 dstY, u16 w, u16 h, u16 colorKey);
void BMP_Blit8bppToVram(struct Bmp *src, struct Bmp *dst, u16 srcX, u16 srcY, s16_p07 dstX, s16_p07 dstY, u16 w, u16 h, u16 colorKey);
void BMP_FillRect4bpp(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u32 value);
void BMP_FillRect8bpp(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u8 value);
void BMP_FillRect4bppVram(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u8 value);
void BMP_FillRect8bppVram(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u8 value);
struct Bmp *BMP_ConvertToLinear(struct Bmp *bmp, u32 keepCopy, u16 heapId);
/* END mkheaders: generated region */

#endif
