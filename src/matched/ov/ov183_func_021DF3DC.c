/*
 * function: BR_CODEIN_SearchMainList
 * address: 0x021DF3DC
 * packet: pkt_ov183_021DF3DC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021DF41A
 * symbols:
 *   BR_UTIL_GetListMenuField 0x021FCE0C thumb ov186
 *   BR_UTIL_MainListMenu 0x021FCD0C thumb ov186
 *   BR_CODEIN_SearchUpdateActor 0x021DF620 thumb ov183
 */
#include "../include/Obj00786.h"
typedef signed char s8;
extern int BR_UTIL_GetListMenuField(char *p, unsigned field);
extern void BR_UTIL_MainListMenu(char *p);
extern void BR_CODEIN_SearchUpdateActor(char *, unsigned int, s8, int);
void BR_CODEIN_SearchMainList(char *p, int a)
{
    unsigned int old, current;
    s8 direction;
    old = BR_UTIL_GetListMenuField(((struct Obj00786 *)p)->f4, 1);
    BR_UTIL_MainListMenu(((struct Obj00786 *)p)->f4);
    current = BR_UTIL_GetListMenuField(((struct Obj00786 *)p)->f4, 1);
    direction = BR_UTIL_GetListMenuField(((struct Obj00786 *)p)->f4, 2);
    if (direction != 0 && old != current) BR_CODEIN_SearchUpdateActor(p, current, direction, a);
}
