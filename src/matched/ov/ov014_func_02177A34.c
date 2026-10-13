/*
 * function: NET_WHPIPE_IsAidConnected
 * address:  0x02177A34
 * packet:   pkt_ov014_02177A34
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data   a4
 *   WIH_GetSysState  0x02178E4C  thumb  ov014
 *   WIH_GetBitmap  0x02178E38  thumb  ov014
 */

#include "../include/G_W.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern struct W *g_pWhPipeWork;
extern int WIH_GetSysState(void);
typedef unsigned short u16;
extern u16 WIH_GetBitmap(void);

int NET_WHPIPE_IsAidConnected(u16 n)
{
    if (((u8 *)g_pWhPipeWork) == 0)
        return 0;
    if (WIH_GetSysState() != 4 && WIH_GetSysState() != 5)
        return 0;
    if (WIH_GetBitmap() & (1 << n))
        return 1;
    return 0;
}
