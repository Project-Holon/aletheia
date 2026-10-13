/*
 * file:     unit_021771F8.c
 * function: NET_WHPIPE_IsWhIdle, func_0217720C, func_02177214
 * address:  0x021771F8
 * packet:   pkt_ov014_021771F8
 * region:   ov014
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIH_GetSysState  0x02178E4C  thumb  ov014
 *   NET_WHPIPE_GetConnectBitmap  0x02177C3C  thumb  ov014
 *   NET_WHPIPE_GetOwnAid  0x02177C44  thumb  ov014
 */

extern int WIH_GetSysState(void);
extern unsigned int NET_WHPIPE_GetConnectBitmap(void);
extern int NET_WHPIPE_GetOwnAid(void);
unsigned int func_0217720C(void);
int func_02177214(void);

int NET_WHPIPE_IsWhIdle(void)
{
    if (WIH_GetSysState() == 1)
        return 1;
    return 0;
}

unsigned int func_0217720C(void)
{
    return NET_WHPIPE_GetConnectBitmap();
}

int func_02177214(void)
{
    return NET_WHPIPE_GetOwnAid();
}
