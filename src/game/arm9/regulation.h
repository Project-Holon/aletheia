#ifndef GAME_ARM9_REGULATION_H
#define GAME_ARM9_REGULATION_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of regulation.c, prototypes copied from their definitions. */

struct Regulation;
struct ShooterSettings;
struct RegulationCard;
struct RegulationParty;
struct BattleCompetitionSave;
struct Party;
struct SaveControl;

#include "../types.h"

u32 REGULATION_GetCompetitionSize(void);
struct Regulation *REGULATION_Create(u32 heapId);
void REGULATION_Copy(const struct Regulation *src, struct Regulation *dest);
void *REGULATION_NoOp(void *card);
void REGULATION_GetCupName(struct Regulation *rule, void *dest);
void *REGULATION_CreateCupName(struct Regulation *rule, u32 heapId);
u32 REGULATION_GetRuleValue(const struct Regulation *rule, u32 id);
void REGULATION_SetRuleValue(struct Regulation *rule, u32 id, s32 value);
u32 REGULATION_GetVetoBit(const struct Regulation *rule, u32 id, s32 bit);
void REGULATION_GetShooterSettings(struct Regulation *rule, struct ShooterSettings *out);
u8 *REGULATION_Card_GetCupName(struct RegulationCard *card);
s32 REGULATION_Card_GetValue(struct RegulationCard *card, u32 id);
void REGULATION_Card_SetValue(struct RegulationCard *card, u32 id, s32 value);
u32 REGULATION_Card_IsCrcValid(struct RegulationCard *card);
u16 REGULATION_Card_CalcCrc(struct RegulationCard *card);
struct RegulationCard *REGULATION_GetCard(struct RegulationCard *cards, u32 index);
void REGULATION_SetCard(struct RegulationCard *cards, u32 index, const struct RegulationCard *src);
void REGULATION_InitParty(struct RegulationParty *party);
struct RegulationParty *REGULATION_GetParty(struct BattleCompetitionSave *competition, u32 index);
s32 REGULATION_Party_GetValue(struct RegulationParty *party, u32 id, u8 member);
void REGULATION_Party_SetValue(struct RegulationParty *party, int id, u8 member, s32 value);
void REGULATION_BuildParty(struct RegulationParty *dest, struct Party *party);
void BATTLE_COMPETITION_Init(struct BattleCompetitionSave *competition);
struct BattleCompetitionSave *BATTLE_COMPETITION_GetFromSave(struct SaveControl *save);
/* END mkheaders: generated region */

#endif
