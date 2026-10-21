#ifndef GAME_ARM9_BILLBOARD_H
#define GAME_ARM9_BILLBOARD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of billboard.c, prototypes copied from their definitions. */

struct Blk3;
struct BbBoard;
struct BbImage;
struct G3dResource;
struct G3dCamera;
struct LightSlot;

#include "../types.h"
#include "../sdk_fx.h"

void *BILLBOARD_Create(u8 *src, u32 heap);
void BILLBOARD_Delete(void *p);
void BILLBOARD_SetFixedNormal(u8 *board, short *normal);
void BILLBOARD_SetScale(u8 *dst, struct Blk3 *src);
void BILLBOARD_SetDiffuse(u8 *dst, u16 *src);
void BILLBOARD_SetAmbient(u8 *dst, u16 *src);
void BILLBOARD_SetSpecular(u8 *dst, u16 *src);
void BILLBOARD_SetEmission(u8 *dst, u16 *src);
void BILLBOARD_SetPolyIdBase(u8 *dst, u8 *src);
void BILLBOARD_SetQuadShape(u8 *dst, u8 val);
void BILLBOARD_SetImageOffset(u8 *dst, int a, int b);
void BILLBOARD_GetImageSizeFromFlags(s32 flags, u16 *a, u16 *b);
int BILLBOARD_FindFreeImage(struct BbBoard *board, int *outIndex);
void BILLBOARD_BindImageResource(struct BbImage *image, struct G3dResource *resource);
void BILLBOARD_SetImageFormat(struct BbImage *image, u32 formatIndex, s32 sizeCode, u32 columns, u8 rows);
u32 BILLBOARD_AddImage(struct BbBoard *board, struct G3dResource *resource, u32 formatIndex, u32 sizeCode, u8 columns, u8 rows);
u32 BILLBOARD_AddImageFromArchive(struct BbBoard *board, u32 arcId, u32 dataId, u32 formatIndex, u32 sizeCode, u8 columns, u8 rows);
int BILLBOARD_AddImageFromVramKeys(struct BbBoard *board, int texVramKey, int plttVramKey, int formatIndex, u32 sizeCode, u8 columns, u8 rows);
void BILLBOARD_TrimImageResource(struct BbBoard *board, u32 index);
void BILLBOARD_DeleteImage(struct BbBoard *board, int index);
void BILLBOARD_ReleaseImageVramIfUsed(struct BbBoard *board, u32 index);
void BILLBOARD_ReleaseImageVram(struct BbBoard *board, int index);
void BILLBOARD_DeleteAllImages(struct BbBoard *board);
void BILLBOARD_GetImageVramAddr(struct BbBoard *board, int index, int *outTexVramOffset);
int BILLBOARD_GetImagePlttVramOffset(struct BbBoard *board, int index, int *outPlttVramOffset);
void BILLBOARD_GetImageTexKey(struct BbBoard *board, int index, u32 *outTexVramKey);
void BILLBOARD_SetImageTexAddr(struct BbBoard *board, int imageIndex, u32 texKey);
void BILLBOARD_GetImagePlttKey(struct BbBoard *board, int imageIndex, u32 *outPlttKey);
void BILLBOARD_CalcImageFrameRange(struct BbBoard *board, u32 imageIndex, int frame, int *outOffset, int *outFrameSize, u8 useFrameIndex);
s32 BILLBOARD_AddElem(struct BbBoard *board, u32 imageIndex, u16 scaleX, u16 scaleY, VecFx32 *pos, u8 alpha, u32 light, u32 facingMode);
void BILLBOARD_FreeElem(struct BbBoard *board, u32 elemIndex);
void BILLBOARD_GetElemId(struct BbBoard *board, u32 elemIndex, u16 *outImageIndex);
void BILLBOARD_SetElemId(struct BbBoard *board, u32 elemIndex, u16 *imageIndex);
void BILLBOARD_SetElemPos(struct BbBoard *board, int elemIndex, VecFx32 *pos);
void BILLBOARD_GetElemCell(struct BbBoard *board, int elemIndex, u16 *outCell);
void BILLBOARD_SetElemCell(struct BbBoard *board, int elemIndex, u16 *cell);
void BILLBOARD_SetElemScale(struct BbBoard *board, int elemIndex, const s16 *scaleX, const s16 *scaleY);
void BILLBOARD_SetElemAlpha(struct BbBoard *board, int elemIndex, u8 *alpha);
void BILLBOARD_SetElemPolyId(struct BbBoard *board, int elemIndex, u8 *polyId);
u32 BILLBOARD_GetElemVisible(struct BbBoard *board, int elemIndex);
void BILLBOARD_SetElemVisible(struct BbBoard *board, u32 elemIndex, u32 *visible);
u32 BILLBOARD_GetElemFlipS(struct BbBoard *board, int elemIndex);
void BILLBOARD_SetElemFlipS(struct BbBoard *board, u32 elemIndex, u32 *flipS);
void BILLBOARD_SetElemFlipT(struct BbBoard *board, u32 elemIndex, u32 *flipT);
void BILLBOARD_SetElemRotZ(struct BbBoard *board, int elemIndex, u16 *rotZ);
void BILLBOARD_Draw(struct BbBoard *board, struct G3dCamera *camera, struct LightSlot *lights);
/* END mkheaders: generated region */

#endif
