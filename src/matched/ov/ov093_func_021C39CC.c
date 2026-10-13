/*
 * function: BTL_SERVER_FLOW_IsForceSwitchByParty
 * address: 0x021C39CC
 * packet: pkt_ov093_021C39CC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 */
#include "../include/Obj13329.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef enum { FALSE = 0, TRUE = 1 } BOOL;
extern u32 BTL_MAIN_GetRule(void **p);
extern void *BTL_MAIN_GetCompetitor(void ***);
BOOL BTL_SERVER_FLOW_IsForceSwitchByParty(u8 *p)
{
    u32 a;
    void *b;
    a = BTL_MAIN_GetRule(((struct Obj13329 *)p)->f4);
    b = BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj13329 *)p)->f4);
    if (a == 0) {
        if (b == 0) {
            return FALSE;
        } else {
            return TRUE;
        }
    }
    return TRUE;
}
