#ifndef GAME_OV217_PERCENTAGE_H
#define GAME_OV217_PERCENTAGE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of percentage.c, prototypes copied from their definitions. */

struct PercentageTemplate;
struct ClactUnit;
struct Percentage;

#include "../types.h"

u32 PERCENTAGE_Create(u32 heapId, const struct PercentageTemplate *tmpl, struct ClactUnit *unit);
u32 PERCENTAGE_Destroy(struct Percentage *pct);
void PERCENTAGE_SetPosition(struct Percentage *pct, u32 x, u32 y);
void PERCENTAGE_SetValue(struct Percentage *pct, u32 value);
void PERCENTAGE_SetVisible(struct Percentage *pct, unsigned int visible);
void PERCENTAGE_SetVisibleImpl(struct Percentage *pct, unsigned int visible);
void PERCENTAGE_Layout(struct Percentage *pct);
void PERCENTAGE_StoreValue(struct Percentage *pct, u8 value);
void PERCENTAGE_StorePosition(struct Percentage *pct, u32 x, u32 y);
u8 PERCENTAGE_GetOnesDigit(struct Percentage *pct);
u8 PERCENTAGE_GetTensDigit(struct Percentage *pct);
u8 PERCENTAGE_GetHundredsDigit(struct Percentage *pct);
void PERCENTAGE_GetOnesPosition(const struct Percentage *pct, s16 *x, s16 *y);
void PERCENTAGE_GetTensPosition(const struct Percentage *pct, s16 *x, s16 *y);
void PERCENTAGE_GetHundredsPosition(const struct Percentage *pct, s16 *x, s16 *y);
struct Percentage *PERCENTAGE_Alloc(u32 heapId);
u32 PERCENTAGE_Free(struct Percentage *pct);
void PERCENTAGE_ClearFields(struct Percentage *pct, u32 heapId);
void PERCENTAGE_Setup(struct Percentage *pct, const struct PercentageTemplate *tmpl, struct ClactUnit *unit);
void PERCENTAGE_Exit(struct Percentage *pct);
void PERCENTAGE_StoreUnit(struct Percentage *pct, struct ClactUnit *unit);
void PERCENTAGE_CreateActors(struct Percentage *pct);
void PERCENTAGE_DeleteActors(struct Percentage *pct);
void PERCENTAGE_StoreTemplate(struct Percentage *pct, const struct PercentageTemplate *tmpl);
/* END mkheaders: generated region */

#endif
