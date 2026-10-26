/*
 * file:     regulation.c
 * unit:     yes
 * function: REGULATION_GetCompetitionSize, REGULATION_Create, REGULATION_Copy, REGULATION_NoOp, REGULATION_GetCupName, REGULATION_CreateCupName, REGULATION_GetRuleValue, REGULATION_SetRuleValue, REGULATION_GetVetoBit, REGULATION_GetShooterSettings, REGULATION_Card_GetCupName, REGULATION_Card_GetValue, REGULATION_Card_SetValue, REGULATION_Card_IsCrcValid, REGULATION_Card_CalcCrc, REGULATION_GetCard, REGULATION_SetCard, REGULATION_InitParty, REGULATION_GetParty, REGULATION_Party_GetValue, REGULATION_Party_SetValue, REGULATION_BuildParty, BATTLE_COMPETITION_Init, BATTLE_COMPETITION_GetFromSave
 * address:  0x0200ADE8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mystery_data.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   GF_STANDARD_CalcCrc16  0x0203F1FC  arm
 *   func_0200ADF0_File  0x020A71B4  data
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   POKEPARTY_GetCount           0x0201AA18  thumb
 *   POKEPARTY_GetMember          0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue      0x02017E1C  thumb
 */
#include "wifilist_tail_shared_types.h"

struct MsgBank;

struct U16Vec;

struct Party;

struct SaveControl;

/* A party Pokemon (0xDC bytes), addressed as words; only a pointer passes here. */
struct PokeParam {
    u32 data[0x37];
};

#include "../types.h"

#include "regulation_types.h"

/* Shooter settings that REGULATION_GetShooterSettings fills. */
struct ShooterSettings {
    u8 vetoItemBit[7];
    u8 isEnabled;
};

/* A 0x160-byte regulation card: the rule set plus card data and a CRC. */

/* The party a regulation card is entered with (0x1E bytes). */
struct RegulationParty {
    u16 monsNo[6];
    u8  formNo[6];
    u8  hasItemBits;
    u8  femaleBits;
    u8  reserved[10];
};

/* Save block 0x2F, the battle competition save (0x2FC bytes). */
struct BattleCompetitionSave {
    struct RegulationCard cards[2];
    struct RegulationParty parties[2];
};

#include "mi_memory.h"


#include "gf_standard.h"

#include "gfl_heap_wrap.h"

#include "msgdata.h"
struct Strbuf;



#include "strbuf.h"

#include "pokeparty.h"
struct PokemonParam;


#include "poke_tool.h"

#include "save_control.h"

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

extern const char func_0200ADF0_File[];

u32 REGULATION_GetCompetitionSize(void)
{
    return sizeof(struct BattleCompetitionSave);
}

struct Regulation *REGULATION_Create(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, sizeof(struct Regulation), 1, func_0200ADF0_File,
                         0x73);
}

void REGULATION_Copy(const struct Regulation *src, struct Regulation *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct Regulation));
}

void *REGULATION_NoOp(void *card)
{
    return card;
}

void REGULATION_GetCupName(struct Regulation *rule, void *dest)
{
    struct MsgBank *bank = MSGDATA_CreateFromArchive(0, 2, 0xA6, 1);
    MSGDATA_ReadString(bank, rule->cupNo, dest);
    MSGDATA_Delete(bank);
}

void *REGULATION_CreateCupName(struct Regulation *rule, u32 heapId)
{
    void *name = STRBUF_Create(0x1A, heapId);
    REGULATION_GetCupName(rule, name);
    return name;
}

u32 REGULATION_GetRuleValue(const struct Regulation *rule, u32 id)
{
    u32 value = 0;
    switch (id) {
    case 0:  value = rule->cupNo; break;
    case 1:  value = rule->ruleNo; break;
    case 2:  value = rule->numLo; break;
    case 3:  value = rule->numHi; break;
    case 4:  value = rule->level; break;
    case 5:  value = rule->levelRange; break;
    case 6:  value = rule->levelTotal; break;
    case 7:  value = rule->bothPoke; break;
    case 8:  value = rule->bothItem; break;
    case 11: value = rule->mustPoke; break;
    case 12: value = rule->mustPokeForm; break;
    case 13: value = rule->shooter; break;
    case 15: value = rule->timeVs; break;
    case 16: value = rule->timeCommand; break;
    case 17: value = rule->nickname; break;
    case 18: value = rule->cameraMode; break;
    case 19: value = rule->showPoke; break;
    case 20: value = rule->showPokeTime; break;
    case 21: value = rule->battleType; break;
    case 22: value = rule->battleCount; break;
    }
    return value;
}

void REGULATION_SetRuleValue(struct Regulation *rule, u32 id, s32 value)
{
    switch (id) {
    case 0:  if (value < 7)     { rule->cupNo = value; } break;
    case 1:  if (value < 6)     { rule->ruleNo = value; } break;
    case 2:  if (value < 6)     { rule->numLo = value; } break;
    case 3:  if (value < 6)     { rule->numHi = value; } break;
    case 4:  if (value <= 100)  { rule->level = value; } break;
    case 5:  if (value <= 6)    { rule->levelRange = value; } break;
    case 6:  if (value <= 600)  { rule->levelTotal = value; } break;
    case 7:  if (value < 2)     { rule->bothPoke = value; } break;
    case 8:  if (value < 2)     { rule->bothItem = value; } break;
    case 11: if (value < SPECIES_LAST + 2) { rule->mustPoke = value; } break;
    case 12: rule->mustPokeForm = value; break;
    case 13: if (value < 2)     { rule->shooter = value; } break;
    case 15: rule->timeVs = value; break;
    case 16: rule->timeCommand = value; break;
    case 17: if (value < 2)     { rule->nickname = value; } break;
    case 18: rule->cameraMode = value; break;
    case 19: if (value < 2)     { rule->showPoke = value; } break;
    case 20: if (value <= 0x63) { rule->showPokeTime = value; } break;
    case 21: if (value < 6)     { rule->battleType = value; } break;
    case 22: rule->battleCount = value; break;
    }
}

u32 REGULATION_GetVetoBit(const struct Regulation *rule, u32 id, s32 bit)
{
    s32 byte = bit / 8;
    s32 shift = bit % 8;
    switch (id) {
    case 9:
        if (rule->vetoPokeBit[byte] & (1 << shift)) {
            return 1;
        }
        break;
    case 10:
        if (rule->vetoItemBit[byte] & (1 << shift)) {
            return 1;
        }
        break;
    case 14:
        if (rule->vetoShooterBit[byte] & (1 << shift)) {
            return 1;
        }
        break;
    }
    return 0;
}

void REGULATION_GetShooterSettings(struct Regulation *rule, struct ShooterSettings *out)
{
    MI_CpuFill8(out, 0, sizeof(struct ShooterSettings));
    out->isEnabled = REGULATION_GetRuleValue(rule, 13);
    if (out->isEnabled >= 2) {
        out->isEnabled = 1;
    }
    MI_CpuCopy8(rule->vetoShooterBit, out, 7);
}

u8 *REGULATION_Card_GetCupName(struct RegulationCard *card)
{
    return card->cupName;
}

s32 REGULATION_Card_GetValue(struct RegulationCard *card, u32 id)
{
    switch (id) {
    case 1:  return card->cupId;
    case 2:  return card->romVersion;
    case 3:  return card->startYear;
    case 4:  return card->startMonth;
    case 5:  return card->startDay;
    case 6:  return card->endYear;
    case 7:  return card->endMonth;
    case 8:  return card->endDay;
    case 9:  return card->status;
    case 10: return card->bgm;
    case 11: return card->sameMatch;
    case 12: return card->cardType;
    }
    return (sptr)card;
}

void REGULATION_Card_SetValue(struct RegulationCard *card, u32 id, s32 value)
{
    switch (id) {
    case 1:  card->cupId      = value; break;
    case 2:  card->romVersion = value; break;
    case 3:  card->startYear  = value; break;
    case 4:  card->startMonth = value; break;
    case 5:  card->startDay   = value; break;
    case 6:  card->endYear    = value; break;
    case 7:  card->endMonth   = value; break;
    case 8:  card->endDay     = value; break;
    case 9:  card->status     = value; break;
    case 10: card->bgm        = value; break;
    case 11: card->sameMatch  = value; break;
    case 12: card->cardType   = value; break;
    }
}

u32 REGULATION_Card_IsCrcValid(struct RegulationCard *card)
{
    if (card->crc == REGULATION_Card_CalcCrc(card)) {
        return 1;
    }
    return 0;
}

u16 REGULATION_Card_CalcCrc(struct RegulationCard *card)
{
    return GF_STANDARD_CalcCrc16((u8 *)card, 0x15E);
}

struct RegulationCard *REGULATION_GetCard(struct RegulationCard *cards, u32 index)
{
    return &cards[index];
}

void REGULATION_SetCard(struct RegulationCard *cards, u32 index, const struct RegulationCard *src)
{
    cards[index] = *src;
}

void REGULATION_InitParty(struct RegulationParty *party)
{
    MI_CpuFill8(party, 0, sizeof(struct RegulationParty));
}

struct RegulationParty *REGULATION_GetParty(struct BattleCompetitionSave *competition, u32 index)
{
    return &competition->parties[index];
}

s32 REGULATION_Party_GetValue(struct RegulationParty *party, u32 id, u8 member)
{
    switch (id) {
    case 0: return party->monsNo[member];
    case 1: return party->formNo[member];
    case 2: return (party->hasItemBits >> member) & 1;
    case 3: return (party->femaleBits >> member) & 1;
    }
    return 0;
}

void REGULATION_Party_SetValue(struct RegulationParty *party, int id, u8 member, s32 value)
{
    switch (id) {
    case 0: party->monsNo[member] = value; break;
    case 1: party->formNo[member] = value; break;
    case 2: party->hasItemBits |= (u8)((value == 1) << member); break;
    case 3: party->femaleBits |= (u8)((value == 1) << member); break;
    }
}

/*
 * Rebuild the four per-slot fields for every entry the accessor count reports;
 * the count is a call, so it is re-evaluated on the loop back-edge, and the
 * third argument of every accumulate call is truncated to u8.
 */
void REGULATION_BuildParty(struct RegulationParty *dest, struct Party *party)
{
    int i;

    REGULATION_InitParty(dest);
    for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
        struct PokeParam *mon = (struct PokeParam *)POKEPARTY_GetMember(party, i);

        if (POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0xa9, 0) != 0) {
            REGULATION_Party_SetValue(dest, 0, i, POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 5, 0));
            REGULATION_Party_SetValue(dest, 1, i, POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0x6f, 0));
            REGULATION_Party_SetValue(dest, 2, i, POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 6, 0) != 0);
            REGULATION_Party_SetValue(dest, 3, i, POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0x6e, 0));
        }
    }
}

void BATTLE_COMPETITION_Init(struct BattleCompetitionSave *competition)
{
    MI_CpuFill8(competition, 0, sizeof(struct BattleCompetitionSave));
}

struct BattleCompetitionSave *BATTLE_COMPETITION_GetFromSave(struct SaveControl *save)
{
    return SAVE_CONTROL_GetBlock(save, 0x2F);
}
