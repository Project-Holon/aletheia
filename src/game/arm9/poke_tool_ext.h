#ifndef GAME_ARM9_POKE_TOOL_EXT_H
#define GAME_ARM9_POKE_TOOL_EXT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of poke_tool_ext.c, prototypes copied from their definitions. */

struct PokemonParam;
struct Party;
struct BoxPokemon;

#include "../types.h"

u8 POKE_TOOL_IsPPRestorable(struct PokemonParam *pp, u32 slot);
u32 POKE_TOOL_RestorePP(struct PokemonParam *pp, u32 slot, u32 amount);
void POKE_TOOL_HealFull(struct PokemonParam *pp);
void POKE_TOOL_HealParty(struct Party *party);
u32 POKE_TOOL_GetGraphicIndex(struct BoxPokemon *box);
u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 female, u32 isEgg);
u32 POKE_TOOL_GetIconPalette(struct BoxPokemon *box);
int POKE_TOOL_GetIconPaletteArcId(void);
int POKE_TOOL_GetIconCellArcId(void);
int POKE_TOOL_GetIconCellArcIdSub(void);
int POKE_TOOL_GetIconCellEntryId(void);
int POKE_TOOL_GetIconCellEntryIdSub(void);
/* END mkheaders: generated region */

#endif
