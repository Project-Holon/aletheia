/*
 * function: UNION_ONESELF_CheckMyParty
 * address: 0x0217BA48
 * packet: pkt_ov019_0217BA48
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKE_REGULATION_CheckParty 0x0201A090 thumb
 */
#include "../include/Obj09409.h"
#include "../include/Obj19403.h"
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern int POKE_REGULATION_CheckParty(void *, void *, unsigned int *);
int UNION_ONESELF_CheckMyParty(char *p, unsigned int *mask)
{
    void *party;
    *mask = 0;
    party = GAME_DATA_GetMyParty(((struct Obj19403 *)(*(char * *)&((struct Obj09409 *)p)->f0))->f8);
    return POKE_REGULATION_CheckParty(((struct Obj09409 *)p)->f352C, party, mask);
}
