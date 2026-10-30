#ifndef GAME_OV194_NAMEIN_GRAPHIC_FIELD_H
#define GAME_OV194_NAMEIN_GRAPHIC_FIELD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of namein_graphic_field.c, prototypes copied from their definitions. */

struct Strbuf;

#include "../types.h"
#include "../ov194/namein_graphic_shared_types.h"

int NAMEIN_GRAPHIC_FadeCellColor(u16 *out, u16 *phase, u32 step, u32 row, u8 idx, u16 a, u16 b);
/* NameinFontArg: the DS code passes the font pointer through a halfword parameter (original
 * prototype); a host build needs the whole pointer. See docs/ORIGINAL_BUGS.tsv. */
#ifdef __MWERKS__
typedef u16 NameinFontArg;
#else
struct GfFont;
typedef struct GfFont *NameinFontArg;
#endif
void NAMEIN_GRAPHIC_InitInputField(u8 *p, struct Strbuf *a, u16 b, NameinFontArg c, struct PrintQueue *d, u8 *e, int f);
void NAMEIN_GRAPHIC_DeleteInputField(u8 *p);
int NAMEIN_GRAPHIC_RefreshInputField(u8 *p);
int NAMEIN_GRAPHIC_Backspace(unsigned char *p);
int NAMEIN_GRAPHIC_AppendChar(char *p, unsigned short v);
int NAMEIN_GRAPHIC_AppendCandidate(unsigned char *p, unsigned short a, u32 b);
int NAMEIN_GRAPHIC_ApplyConversion(u8 *a,int b);
int NAMEIN_GRAPHIC_RevertChar(char *p);
int NAMEIN_GRAPHIC_IsFieldDrawDone(unsigned char *p);
int NAMEIN_GRAPHIC_FindCellAtPoint(const char *p,int *point,NameinGraphicPair *out);
int NAMEIN_GRAPHIC_PickerGetBox(char *a, NameinGraphicPair *b, NameinGraphicBox *c);
int NAMEIN_GRAPHIC_FindCellByValue(const char *p,int target,NameinGraphicPair *out);
void NAMEIN_GRAPHIC_ConvertCellMode(NameinGraphicPair *p, int oldmode, int newmode);
void NAMEIN_GRAPHIC_CopyToStrbuf(char *self, struct Strbuf *dst);
void NAMEIN_GRAPHIC_ClearSecondary(char *p);
void NAMEIN_GRAPHIC_CommitSecondary(char *p);
void NAMEIN_GRAPHIC_ClearPrimary(u8 *p);
void NAMEIN_GRAPHIC_AppendString(char *p,const u16 *q);
int NAMEIN_GRAPHIC_IsFieldFull(char *p);
u32 NAMEIN_GRAPHIC_GetLength(const u8 *p);
u32 NAMEIN_GRAPHIC_GetSecondaryLength(const u8 *p);
int NAMEIN_GRAPHIC_PickCandidate(u8 *p,int direction);
int NAMEIN_GRAPHIC_HasNonSpace(u8 *p);
#if LANGUAGE != LANGUAGE_JAPANESE
void NAMEIN_GRAPHIC_LoadGrid(void **a, int b, void **c);
#endif
void NAMEIN_GRAPHIC_ClearPicker(void *p);
unsigned NAMEIN_GRAPHIC_PickerToChar(char *p,int *input,unsigned short *out);
void NAMEIN_GRAPHIC_PickerMove(char *a, int *b, int *c);
void NAMEIN_GRAPHIC_DrawCellTips(char *p,char *target,void *window,void *font,u16 heap);
int NAMEIN_GRAPHIC_KanaGetBox(const int *p,int *out);
void NAMEIN_GRAPHIC_KanaMove(int *p,int *delta,u8 *saved);
void NAMEIN_GRAPHIC_SymbolMove(int *p,int *delta,unsigned char *s);
int NAMEIN_GRAPHIC_GridValue(NameinGraphicPair *p,NameinGraphicPair *out);
int NAMEIN_GRAPHIC_ComputeGridValue(const NameinGraphicPair *p,NameinGraphicPair *out);
/* END mkheaders: generated region */

/* InitPicker takes no table index in the Japanese build. */
#if LANGUAGE == LANGUAGE_JAPANESE
void NAMEIN_GRAPHIC_InitPicker(char *p, unsigned mode, void **table, u32 unused);
#else
void NAMEIN_GRAPHIC_InitPicker(char *p, unsigned mode, int index, void **table, u32 unused);
#endif

#endif
