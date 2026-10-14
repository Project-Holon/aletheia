/*
 * function: GURU2_MAIN_StateWaitPlayerData
 * address: 0x021DED3C
 * packet: pkt_ov137_021DED3C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_CountActiveMembers 0x021E17EC thumb ov137
 *   GURU2_MAIN_AnyMemberHasEligiblePokemon 0x021E1910 thumb ov137
 *   GURU2_COMM_Send 0x021DCBC4 thumb ov137
 */
#include "../include/Obj03304.h"
typedef unsigned char u8;
extern int GURU2_MAIN_CountActiveMembers(char *p);
extern int GURU2_MAIN_AnyMemberHasEligiblePokemon(char *p);
typedef unsigned int   u32;
extern void GURU2_COMM_Send(void *p, u32 a, const void *b, u32 c);
int GURU2_MAIN_StateWaitPlayerData(u8 *p)
{
    if (((struct Obj03304 *)p)->f30 == GURU2_MAIN_CountActiveMembers((char *)p)) {
        if (GURU2_MAIN_AnyMemberHasEligiblePokemon((char *)p) == 1) {
            GURU2_COMM_Send(((struct Obj03304 *)p)->fDC, 10253, 0, 0);
            ((struct Obj03304 *)p)->f0 = 45;
        } else {
            GURU2_COMM_Send(((struct Obj03304 *)p)->fDC, 10254, 0, 0);
            ((struct Obj03304 *)p)->f0 = 15;
        }
    }
    return 0;
}
