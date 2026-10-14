/*
 * function: GURU2_MAIN_AnyMemberHasEligiblePokemon
 * address: 0x021E1910
 * packet: pkt_ov137_021E1910
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GURU2_MAIN_PartyHasEligiblePokemon 0x021E18CC thumb ov137
 *   GURU2_MAIN_IsMemberPresent 0x021E1768 thumb ov137
 *   GURU2_COMM_GetPartyCopy 0x021DCE00 thumb ov137
 */
#include "../include/Obj03304.h"
extern int GURU2_MAIN_PartyHasEligiblePokemon(void *);
extern int GURU2_MAIN_IsMemberPresent(char *, int);
extern int GURU2_COMM_GetPartyCopy(char *p, int i);
int GURU2_MAIN_AnyMemberHasEligiblePokemon(char *p)
{
    int i;
    if (GURU2_MAIN_PartyHasEligiblePokemon(((struct Obj03304 *)p)->f24) == 1)
        return 1;
    for (i = 0; i < 5; i++) {
        if (GURU2_MAIN_IsMemberPresent(p, i) != 0 && GURU2_MAIN_PartyHasEligiblePokemon((void *)GURU2_COMM_GetPartyCopy(*(char * *)&((struct Obj03304 *)p)->fDC, i)) == 1)
            return 1;
    }
    return 0;
}
