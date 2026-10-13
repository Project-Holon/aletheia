/*
 * function: WIFICLUB_StateRuleSetKey
 * address: 0x021BCEAC
 * packet: pkt_ov099_021BCEAC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   WIFICLUB_DeleteRuleWindow 0x021BC06C thumb ov099
 */
#include "../include/Obj04412.h"
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern void WIFICLUB_DeleteRuleWindow(char *);
int WIFICLUB_StateRuleSetKey(char *p, int ret)
{
    if (KEY_GetTrg() != 0) {
        WIFICLUB_DeleteRuleWindow(p);
        ((struct Obj04412 *)p)->f1CC = 0x4E;
    }
    return ret;
}
