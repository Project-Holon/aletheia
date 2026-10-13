/*
 * function: UNION_ONESELF_CheckBattleTeamParty
 * address: 0x0217BA6C
 * packet: pkt_ov019_0217BA6C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_ONESELF_CreateBattleTeamParty 0x0217B9CC thumb ov019
 *   UNION_ONESELF_DeleteParty 0x0217B9F4 thumb ov019
 *   POKE_REGULATION_CheckParty 0x0201A090 thumb
 */
#include "../include/Obj09409.h"
extern void *UNION_ONESELF_CreateBattleTeamParty(char *);
extern void UNION_ONESELF_DeleteParty(void *);
extern int POKE_REGULATION_CheckParty(void *, void *, unsigned int *);
int UNION_ONESELF_CheckBattleTeamParty(char *p, unsigned int *mask)
{
    void *party;
    int result;
    party = UNION_ONESELF_CreateBattleTeamParty(p);
    *mask = 0;
    if (party != 0) {
        result = POKE_REGULATION_CheckParty(((struct Obj09409 *)p)->f352C, party, mask);
        UNION_ONESELF_DeleteParty(party);
    } else {
        *mask = -1;
        result = 5;
    }
    return result;
}
