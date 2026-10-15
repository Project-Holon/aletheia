/*
 * function: POKE_SUMMARY_MAIN_GetMoveWord
 * address:  0x021B7448
 * packet:   pkt_021B7448
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 */
#include "../include/Obj14314.h"
#include "../include/Obj24174.h"

extern unsigned int POKE_TOOL_GetPartyValue(void *, unsigned int, unsigned int);

unsigned short POKE_SUMMARY_MAIN_GetMoveWord(int *p)
{
    int *q = *(int * *)&((struct Obj24174 *)p)->f0;

    return POKE_TOOL_GetPartyValue((void *)((struct Obj14314 *)q)->f0, ((struct Obj14314 *)q)->f1B + 0x36, 0);
}
