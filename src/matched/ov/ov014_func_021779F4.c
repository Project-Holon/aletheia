/*
 * function: NET_WHPIPE_IsConnected
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
 *   NET_WHPIPE_GetChildBitmap  0x02177ACC  thumb  ov014
 *   WIH_GetSysState  0x02178E4C  thumb  ov014
 */

#include "../include/G_W.h"

typedef unsigned char u8;

extern struct W *g_pWhPipeWork;
extern unsigned short WIH_GetOwnAid(void);
extern unsigned int NET_WHPIPE_GetChildBitmap(void);
extern int WIH_GetSysState(void);

int NET_WHPIPE_IsConnected(void)
{
    if (((u8 *)g_pWhPipeWork) == 0)
        return 0;
    if (WIH_GetOwnAid() == 0 && NET_WHPIPE_GetChildBitmap() == 0)
        return 0;
    if (WIH_GetSysState() == 4 || WIH_GetSysState() == 5)
        return 1;
    return 0;
}
