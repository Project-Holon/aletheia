/*
 * file:     hidden_item.c
 * unit:     yes
 * function: HIDDEN_ITEM_GetIndex, HIDDEN_ITEM_GetFlag, HIDDEN_ITEM_Respawn, HIDDEN_ITEM_GetTable
 * address:  0x021646E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_skill_check.c, calender.c, game_beacon_search.c, game_beacon_accessor.c by tools/splitfile.py.
 *
 * symbols:
 *   HiddenItemTable     0x02171534  data
 *   ZONEDATA_PopTimeFlagsCleared  0x0201440C  thumb
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   ZONEDATA_ResetEventFlag  0x0201433C  thumb
 */
#include "field_skill_check_shared_types.h"

struct EventWork;

#define HIDDEN_ITEM_SCRIPT_FIRST 8000

#define HIDDEN_ITEM_SCRIPT_LAST 8799

#define HIDDEN_ITEM_FLAG_BASE 900

#define HIDDEN_ITEM_COUNT 177

#define HIDDEN_ITEM_RESPAWN_PERCENT 20

/* One record of the hidden item table at HiddenItemTable. */
typedef struct HiddenItemEntry {
    u16 flagIndex;    /* the event flag is flagIndex + HIDDEN_ITEM_FLAG_BASE */
    u8 isDowsable;
    u8 respawns;      /* takes part in the daily respawn roll */
    u16 zoneId;
    u16 gridX;
    u16 gridZ;
} HiddenItemEntry;

#include "../arm9/zonedata.h"

#include "../arm9/gfl_use.h"


extern const HiddenItemEntry HiddenItemTable[];

u16 HIDDEN_ITEM_GetIndex(u32 scriptId);

u16 HIDDEN_ITEM_GetFlag(u16 scriptId);

void HIDDEN_ITEM_Respawn(struct EventWork *eventWork);

const HiddenItemEntry *HIDDEN_ITEM_GetTable(unsigned short *count);

/*
 * Hidden item index of a script id, or 0 when the id is outside the
 * hidden item script range.
 */
u16 HIDDEN_ITEM_GetIndex(u32 scriptId)
{
    if (scriptId < HIDDEN_ITEM_SCRIPT_FIRST || scriptId > HIDDEN_ITEM_SCRIPT_LAST) {
        return 0;
    }
    return scriptId - HIDDEN_ITEM_SCRIPT_FIRST;
}

/* Event flag of the hidden item that a script id stands for. */
u16 HIDDEN_ITEM_GetFlag(u16 scriptId)
{
    return HiddenItemTable[HIDDEN_ITEM_GetIndex(scriptId)].flagIndex + HIDDEN_ITEM_FLAG_BASE;
}

/*
 * Daily hidden item respawn: when the time flags were cleared, every
 * respawning entry has a 20% chance to reset its event flag.
 */
void HIDDEN_ITEM_Respawn(struct EventWork *eventWork)
{
    u32 i;

    if (ZONEDATA_PopTimeFlagsCleared(eventWork) != 0) {
        for (i = 0; i < HIDDEN_ITEM_COUNT; i++) {
            const HiddenItemEntry *entry = HiddenItemTable + i;

            if (entry->respawns != 0) {
                if (GFL_USE_GetRandom(100) < HIDDEN_ITEM_RESPAWN_PERCENT) {
                    ZONEDATA_ResetEventFlag(eventWork, (u16)(entry->flagIndex + HIDDEN_ITEM_FLAG_BASE));
                }
            }
        }
    }
}

/* Returns the hidden item table and stores its entry count. */
const HiddenItemEntry *HIDDEN_ITEM_GetTable(unsigned short *count)
{
    *count = HIDDEN_ITEM_COUNT;
    return HiddenItemTable;
}
