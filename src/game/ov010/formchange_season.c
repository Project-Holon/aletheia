/*
 * file:     formchange_season.c
 * unit:     yes
 * function: FORMCHANGE_UpdateSeasonForms
 * address:  0x0216AAE4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from scrcmd_trialhouse.c by tools/splitfile.py.
 *
 * symbols:
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   ZUKAN_SAVE_RegisterSeen  0x0200CFA0  thumb
 */
#include "script_work_types.h"
#include "formchange_shaymin_shared_types.h"

extern struct PokedexSave *ZUKAN_SAVE_GetFromGameData(struct GameData *gameData);

extern void ZUKAN_SAVE_RegisterSeen(struct PokedexSave *pokedex, struct PokemonParam *mon);

/* Party and Pokemon. */
extern u32 POKEPARTY_GetCount(struct Party *party);

extern struct PokemonParam *POKEPARTY_GetMember(struct Party *party, u32 index);

extern u32 POKE_TOOL_GetPartyValue(struct PokemonParam *mon, u32 paramId, void *buffer);

extern void POKE_TOOL_ChangeForm(struct PokemonParam *mon, u16 form);

void FORMCHANGE_UpdateSeasonForms(struct GameData *gameData, struct Party *party, int season);

#define SPECIES_DEERLING 585

#define SPECIES_SAWSBUCK 586

/*
 * Season change: walks every mon of a party and sets the form (field 0x6F)
 * of Deerling and Sawsbuck to the season index, registering each species once
 * with the Pokedex when one of its members actually changed.
 */
void FORMCHANGE_UpdateSeasonForms(struct GameData *gameData, struct Party *party, int season)
{
    struct PokedexSave *pokedex;
    int i;
    int count;
    int deerlingForm;
    int sawsbuckForm;
    int deerlingRegistered;
    int sawsbuckRegistered;

    pokedex = ZUKAN_SAVE_GetFromGameData(gameData);
    deerlingRegistered = 0;
    sawsbuckRegistered = 0;

    switch (season) {
    case 0:
        deerlingForm = 0;
        sawsbuckForm = 0;
        break;
    case 1:
        deerlingForm = 1;
        sawsbuckForm = 1;
        break;
    case 2:
        deerlingForm = 2;
        sawsbuckForm = 2;
        break;
    case 3:
        deerlingForm = 3;
        sawsbuckForm = 3;
        break;
    default:
        deerlingForm = 0;
        sawsbuckForm = 0;
        break;
    }

    count = POKEPARTY_GetCount(party);
    for (i = 0; i < count; i++) {
        struct PokemonParam *mon = POKEPARTY_GetMember(party, i);
        int species = POKE_TOOL_GetPartyValue(mon, PARAM_SPECIES, 0);
        int form = POKE_TOOL_GetPartyValue(mon, PARAM_FORM, 0);

        if (species == SPECIES_DEERLING && form != deerlingForm) {
            POKE_TOOL_ChangeForm(mon, deerlingForm);
            if (!deerlingRegistered) {
                ZUKAN_SAVE_RegisterSeen(pokedex, mon);
                deerlingRegistered = 1;
            }
        } else if (species == SPECIES_SAWSBUCK && form != sawsbuckForm) {
            POKE_TOOL_ChangeForm(mon, sawsbuckForm);
            if (!sawsbuckRegistered) {
                ZUKAN_SAVE_RegisterSeen(pokedex, mon);
                sawsbuckRegistered = 1;
            }
        }
    }
}
