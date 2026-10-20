#ifndef GAME_OV021_PLACE_NAME_LETTER_H
#define GAME_OV021_PLACE_NAME_LETTER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of place_name_letter.c, prototypes copied from their definitions. */

struct BmpOamSys;
typedef struct BmpOamSys BmpOamSys;

#include "../ov021/field_place_name_types.h"
#include "../types.h"

PlaceNameLetter *PLACE_NAME_LETTER_Create(u32 heapId, BmpOamSys *bmpOamSys, u16 space, int paletteId);
void PLACE_NAME_LETTER_Delete(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_Setup(PlaceNameLetter *letter, const PlaceNameLetterParam *param);
void PLACE_NAME_LETTER_Update(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_Start(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_SetVisible(PlaceNameLetter *letter, unsigned int visible);
int PLACE_NAME_LETTER_GetWidth(PlaceNameLetter *letter);
int PLACE_NAME_LETTER_GetHeight(PlaceNameLetter *letter);
u32 PLACE_NAME_LETTER_GetX(PlaceNameLetter *letter);
u32 PLACE_NAME_LETTER_GetY(PlaceNameLetter *letter);
unsigned int PLACE_NAME_LETTER_IsActive(PlaceNameLetter *letter);
PlaceNameLetter *PLACE_NAME_LETTER_AllocWork(u32 heapId);
u32 PLACE_NAME_LETTER_FreeWork(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_InitWork(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_CreateBmp(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_DeleteBmp(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_CreateBmpOam(PlaceNameLetter *letter, BmpOamSys *bmpOamSys, u16 space, int paletteId);
void PLACE_NAME_LETTER_DeleteBmpOam(PlaceNameLetter *letter);
u16 PLACE_NAME_LETTER_GetHeapId(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_SetHeapId(PlaceNameLetter *letter, int heapId);
u16 PLACE_NAME_LETTER_GetChar(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_SetChar(PlaceNameLetter *letter, u16 ch);
u32 PLACE_NAME_LETTER_GetActive(PlaceNameLetter *letter);
u32 PLACE_NAME_LETTER_GetIntX(PlaceNameLetter *letter);
u32 PLACE_NAME_LETTER_GetIntY(PlaceNameLetter *letter);
u8 PLACE_NAME_LETTER_GetWidthRaw(PlaceNameLetter *letter);
u8 PLACE_NAME_LETTER_GetHeightRaw(PlaceNameLetter *letter);
PlaceNameLetterMotion *PLACE_NAME_LETTER_GetMotion(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_MeasureGlyph(PlaceNameLetter *letter);
int PLACE_NAME_LETTER_IsFinished(PlaceNameLetter *letter);
int PLACE_NAME_LETTER_IsXDone(PlaceNameLetter *letter);
int PLACE_NAME_LETTER_IsYDone(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_UpdateActive(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_StepX(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_StepY(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_Activate(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_Deactivate(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_ComputeAcceleration(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_SetMotion(PlaceNameLetter *letter, const PlaceNameLetterParam *param);
void PLACE_NAME_LETTER_ClearBmp(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_PrintChar(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_UpdateOamPos(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_SetVisibleRaw(PlaceNameLetter *letter, unsigned int visible);
/* END mkheaders: generated region */

#endif
