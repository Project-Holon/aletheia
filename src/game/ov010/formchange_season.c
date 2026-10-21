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
#ifdef __MWERKS__
#define POKE_TOOL_ChangeForm POKE_TOOL_ChangeForm_header
#endif
#include "../arm9/poke_tool.h"
#ifdef __MWERKS__
#undef POKE_TOOL_ChangeForm
#endif
#include "script_work_types.h"
#include "formchange_shaymin_shared_types.h"

#include "../arm9/zukan_save.h"
struct ZukanSave;


/* Party and Pokemon. */
#include "../arm9/pokeparty.h"



#ifdef __MWERKS__
extern void POKE_TOOL_ChangeForm(struct PokemonParam *mon, u16 form); /* original prototype; the definition differs in return type, argument width */
#else
#endif

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
                ZUKAN_SAVE_RegisterSeen((struct ZukanSave *)pokedex, mon);
                deerlingRegistered = 1;
            }
        } else if (species == SPECIES_SAWSBUCK && form != sawsbuckForm) {
            POKE_TOOL_ChangeForm(mon, sawsbuckForm);
            if (!sawsbuckRegistered) {
                ZUKAN_SAVE_RegisterSeen((struct ZukanSave *)pokedex, mon);
                sawsbuckRegistered = 1;
            }
        }
    }
}
