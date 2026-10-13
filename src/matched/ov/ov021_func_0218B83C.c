/*
 * function: FIELD_BUILDMODEL_UpdateSeason
 * address:  0x0218B83C
 * packet:   pkt_ov021_0218B83C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_UpdateSeasonState  0x0218BCF4  thumb
 *   FIELD_BUILDMODEL_UpdateAnimSet  0x0218C124  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12562.h"

extern void FIELD_BUILDMODEL_UpdateSeasonState(char *p);
extern void FIELD_BUILDMODEL_UpdateAnimSet(char *p, char *q);

void FIELD_BUILDMODEL_UpdateSeason(char *p)
{
    int i;
    unsigned u;

    FIELD_BUILDMODEL_UpdateSeasonState(p + 8);
    for (i = 0; i < 7; i++) {
        char *q = *(char **)(p + 0x1DC + i * 4);
        if (q != 0)
            FIELD_BUILDMODEL_UpdateAnimSet(p, q + 0xC);
    }
    for (u = 0; u < ((struct Obj12562 *)p)->f1D4; u++)
        FIELD_BUILDMODEL_UpdateAnimSet(p, *(char * *)&((struct Obj12562 *)p)->f1D8 + u * 0x18);
}
