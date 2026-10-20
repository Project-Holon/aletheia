#ifndef GAME_OV093_BTL_SICKCONT_H
#define GAME_OV093_BTL_SICKCONT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_sickcont.c, prototypes copied from their definitions. */

union SickCont;

#include "../ov093/btl_pokeparam_types.h"
#include "../types.h"

union SickCont BTL_SICKCONT_MakeNone(void);
int BTL_SICKCONT_IsNone(union SickCont slot);
union SickCont BTL_SICKCONT_MakeKind2Index(u32 index);
union SickCont BTL_SICKCONT_MakeKind2(u32 index, u32 value);
union SickCont BTL_SICKCONT_MakeKind3(u32 index);
union SickCont BTL_SICKCONT_MakeKind1Empty(void);
union SickCont BTL_SICKCONT_MakeKind1Value(u32 value);
union SickCont BTL_SICKCONT_MakeKind1(u32 index, u32 value);
union SickCont BTL_SICKCONT_MakeKind4(u32 hi, u32 lo);
union SickCont BTL_SICKCONT_MakeKind1Index15(void);
int BTL_SICKCONT_IsKind1Index15(union SickCont slot);
u8 BTL_SICKCONT_GetPosition(union SickCont slot);
void BTL_SICKCONT_SetPosition(union SickCont *slot, u8 pos);
u8 BTL_SICKCONT_GetLow(union SickCont slot);
void BTL_SICKCONT_SetValue(union SickCont *slot, u16 value);
u16 BTL_SICKCONT_GetValue(union SickCont slot);
void BTL_SICKCONT_SetFlag(union SickCont *slot, int flag);
u32 BTL_SICKCONT_GetFlag(union SickCont slot);
void BTL_SICKCONT_AddIndex(union SickCont *slot, u32 delta);
void BTL_SICKCONT_SetIndex(union SickCont *slot, int count);
/* END mkheaders: generated region */

#endif
