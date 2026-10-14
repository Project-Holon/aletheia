/*
 * function: FIELD_SOUND_SYSTEM_IsSlotSoundTracked
 * address:  0x021D21E0
 * packet:   pkt_ov021_021D21E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gFieldSoundSlotTable     0x021DD614  data  ov021  a4
 */

#include "../include/G_Ent021DD614.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ent021DD614 Ent021DD614;

extern struct Ent021DD614 gFieldSoundSlotTable[];

int FIELD_SOUND_SYSTEM_IsSlotSoundTracked(u32 id)
{
    u32 i;

    for (i = 0; i < 0x15; i++) {
        if (id == gFieldSoundSlotTable[i].id && gFieldSoundSlotTable[i].flag == 1) {
            return 1;
        }
    }
    return 0;
}
