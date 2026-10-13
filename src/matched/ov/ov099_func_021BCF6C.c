/*
 * unit: yes
 * function: WIFICLUB_StateRulePreviewKey, WIFICLUB_StateRulePreviewClose, WIFICLUB_StateIdle
 * address: 0x021BCF6C
 * packet: pkt_ov099_021BCF6C
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
#include "../include/Obj22035.h"
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern void WIFICLUB_DeleteRuleWindow(char *);
int WIFICLUB_StateRulePreviewKey(char *p, int ret)
{
    if (KEY_GetTrg() != 0) {
        WIFICLUB_DeleteRuleWindow(p);
        ((struct Obj04412 *)p)->f1CC = 0x7C;
    }
    return ret;
}
int WIFICLUB_StateRulePreviewClose(char *p, int ret)
{
    ((struct Obj22035 *)p)->f1CC = 0x60;
    return ret;
}
int WIFICLUB_StateIdle(char *p, int ret)
{
    return ret;
}
