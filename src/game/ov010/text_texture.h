#ifndef GAME_OV010_TEXT_TEXTURE_H
#define GAME_OV010_TEXT_TEXTURE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of text_texture.c, prototypes copied from their definitions. */

struct Strbuf;
struct TexKey;
struct TexReq;
typedef struct TexKey TexKey;
typedef struct TexReq TexReq;

#include "../types.h"

int TEXT_TEXTURE_LoadTexPlttByName(void *file, const char *texName, void *extra, const char *plttName, struct Strbuf *text, u16 xPos, u16 yPos, u16 color, u16 heap, TexKey *out);
int TEXT_TEXTURE_GetTexFormatCount(void);
void TEXT_TEXTURE_ClearBitmap(void *bmp);
void TEXT_TEXTURE_PrintToClearedBitmap(struct Strbuf *text, u16 xPos, u16 yPos, u16 color, void *bmp, void *font);
void TEXT_TEXTURE_ConvertToTileOrder(void *srcBmp, void *dstBmp);
void TEXT_TEXTURE_UploadTextTexture(TexReq *req, struct Strbuf *text, u16 xPos, u16 yPos, u16 color, u16 heapId);
void TEXT_TEXTURE_UploadPalette(TexReq *req, void *dest);
/* END mkheaders: generated region */

#endif
