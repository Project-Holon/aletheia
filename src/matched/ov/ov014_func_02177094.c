/*
 * unit: yes
 * function: GFL_NET_DEVWIRELESS_Update,GFL_NET_DEVWIRELESS_RequestDisconnect
 * address: 0x02177094
 * packet: pkt_ov014_02177094
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: lead and unlabelled tail-call follower at 0x021770A0.
 * symbols:
 *   NET_WHPIPE_Update 0x0217796C thumb ov014
 *   NET_WHPIPE_RequestFinalize 0x021776C4 thumb ov014
 */
typedef unsigned int u32;
extern void NET_WHPIPE_Update(u32);
extern int NET_WHPIPE_RequestFinalize(void);
int GFL_NET_DEVWIRELESS_Update(u32 a)
{
    NET_WHPIPE_Update(a);
    return 1;
}
int GFL_NET_DEVWIRELESS_RequestDisconnect(void)
{
    return NET_WHPIPE_RequestFinalize();
}
