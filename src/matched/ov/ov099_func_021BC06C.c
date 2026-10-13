/*
 * function: WIFICLUB_DeleteRuleWindow
 * address: 0x021BC06C
 * packet: pkt_ov099_021BC06C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_REGULATION_DeleteText 0x0201A570 thumb
 *   WIFICLUB_DeleteWindow 0x021BA8BC thumb ov099
 */
#include "../include/Obj04412.h"
extern void POKE_REGULATION_DeleteText(void *);
extern int WIFICLUB_DeleteWindow(void *);
void WIFICLUB_DeleteRuleWindow(char *p)
{
    POKE_REGULATION_DeleteText(((struct Obj04412 *)p)->f1344);
    *(int *)&((struct Obj04412 *)p)->f1344 = 0;
    *(int *)&((struct Obj04412 *)p)->f19C = WIFICLUB_DeleteWindow(((struct Obj04412 *)p)->f19C);
}
