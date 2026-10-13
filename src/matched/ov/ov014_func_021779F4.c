/*
 * function: func_021779F4
 * address:  0x021779F4
 * packet:   pkt_ov014_021779F4
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data   a4
 *   WIH_GetOwnAid  0x021795A4  thumb  ov014
 *   func_02177ACC  0x02177ACC  thumb  ov014
 *   func_02178E4C  0x02178E4C  thumb  ov014
 */

#include "../include/G_W.h"

typedef unsigned char u8;

extern struct W *g_pWhPipeWork;
extern unsigned short WIH_GetOwnAid(void);
extern unsigned int func_02177ACC(void);
extern int func_02178E4C(void);

int func_021779F4(void)
{
    if (((u8 *)g_pWhPipeWork) == 0)
        return 0;
    if (WIH_GetOwnAid() == 0 && func_02177ACC() == 0)
        return 0;
    if (func_02178E4C() == 4 || func_02178E4C() == 5)
        return 1;
    return 0;
}
