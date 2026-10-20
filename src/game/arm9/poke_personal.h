#ifndef GAME_ARM9_POKE_PERSONAL_H
#define GAME_ARM9_POKE_PERSONAL_H

struct PersonalData *POKE_PERSONAL_Create(u32 species, int form, u32 heap);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of poke_personal.c, prototypes copied from their definitions. */

struct PersonalData;

#include "../types.h"

void POKE_PERSONAL_OpenHandle(u32 heap);
void POKE_PERSONAL_LoadData(u32 species, int form, void *dst);
void POKE_PERSONAL_LoadDataDirect(u32 species, int form, void *dst);
struct PersonalData *POKE_PERSONAL_Create(u32 species, int form, u32 heap);
void POKE_PERSONAL_Delete(struct PersonalData *data);
u32 POKE_PERSONAL_GetParam(const struct PersonalData *data, u32 field);
u32 POKE_PERSONAL_IsFixedGender(u32 ability);
u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);
u32 POKE_PERSONAL_GetFormDataId(u32 species, s32 form);
/* END mkheaders: generated region */

#endif
