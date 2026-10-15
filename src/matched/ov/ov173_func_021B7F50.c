/*
 * function: POKE_SUMMARY_ACTOR_IsTaskMenuOpen
 * address: 0x021B7F50
 * packet: pkt_ov173_021B7F50
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj24189.h"
int POKE_SUMMARY_ACTOR_IsTaskMenuOpen(char *p)
{
    if (((struct Obj24189 *)p)->f220 != 0)
        return 1;
    return 0;
}
