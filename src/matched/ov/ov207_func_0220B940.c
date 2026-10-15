/*
 * function: ZUKAN_NICKNAME_GetResult
 * address: 0x0220B940
 * packet: pkt_ov207_0220B940
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Extra: ARM9-free blocker getter for assigned 0220B0A4; ownership and SDK checks clear.
 */
#include "../include/Obj25413.h"
int ZUKAN_NICKNAME_GetResult(char *p)
{
    return ((struct Obj25413 *)p)->f40;
}
