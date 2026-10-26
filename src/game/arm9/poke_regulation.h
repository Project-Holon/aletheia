#ifndef GAME_ARM9_POKE_REGULATION_H
#define GAME_ARM9_POKE_REGULATION_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of poke_regulation.c, prototypes copied from their definitions. */

struct Regulation;
struct Pokemon;
struct Party;
struct Strbuf;
struct WordSet;
struct RegulationText;

#include "../types.h"

int POKE_REGULATION_IsInSpeciesTable(unsigned short species);
int POKE_REGULATION_CheckPokemon(const struct Regulation *reg, struct Pokemon *mon);
int POKE_REGULATION_CheckSelection(struct Regulation *reg, struct Party *party, u8 *order);
int POKE_REGULATION_CheckPartyUsable(const struct Regulation *reg, struct Party *party);
int POKE_REGULATION_CheckPokemonFlags(const struct Regulation *reg, struct Pokemon *mon, u32 *flags);
int POKE_REGULATION_CheckParty(const struct Regulation *reg, struct Party *party, u32 *flags);
u32 POKE_REGULATION_AdjustLevel(const struct Regulation *reg, u32 level);
void POKE_REGULATION_AdjustPartyLevels(const struct Regulation *reg, struct Party *party);
void POKE_REGULATION_ResetPartyNicknames(const struct Regulation *reg, struct Party *party, u32 unused);
void *POKE_REGULATION_Load(int memberId, int heapId);
void POKE_REGULATION_LoadInto(int memberId, void *dst);
struct Strbuf *POKE_REGULATION_BuildPartySizeLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);
struct Strbuf *POKE_REGULATION_BuildLevelLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);
struct Strbuf *POKE_REGULATION_GetBannedSpeciesLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);
struct Strbuf *POKE_REGULATION_GetSpeciesClauseLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);
struct Strbuf *POKE_REGULATION_GetItemClauseLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);
struct Strbuf *POKE_REGULATION_GetBattleModeLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);
struct RegulationText *POKE_REGULATION_CreateText(const struct Regulation *reg, struct WordSet *wordSet, u16 heapId, u32 battleMode);
void POKE_REGULATION_DeleteText(struct RegulationText *text);
int POKE_REGULATION_FindValidOrder(const struct Regulation *reg, struct Party *party, char *picked);
int POKE_REGULATION_CheckOrder(const struct Regulation *reg, struct Party *party, u8 *order, char *picked, u32 *flags);
int POKE_REGULATION_NextOrder(u8 *order);
int POKE_REGULATION_GetDataSize(void);
/* END mkheaders: generated region */

#endif
