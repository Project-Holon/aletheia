/*
 * unit: yes
 * function: GFL_NET_DEVWIFI_IsOffline, GFL_NET_DEVWIFI_IsIdle, GFL_NET_DEVWIFI_GetAidBitmap, GFL_NET_DEVWIFI_GetMyAid
 * address: 0x021552AC
 * packet: pkt_ov009_021552AC
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Follower GFL_NET_DEVWIFI_IsIdle resolves through the verified ov009 02156CAC leaf;
 * ov010's same-address allocator is a different function.
 * symbols:
 *   DWC_RAP_IsDisconnected 0x02156D84 thumb ov009
 *   DWC_RAP_IsWorkAllocated 0x02155388 thumb ov009
 *   DWC_RAP_IsStateIdle 0x02156CAC thumb ov009
 *   DWC_GetAIDBitmap 0x0216B908 arm ov009
 *   DWC_RAP_GetMyAidIfConnected 0x021562EC thumb ov009
 */
extern int DWC_RAP_IsDisconnected(void);
extern int DWC_RAP_IsWorkAllocated(void);
extern int DWC_RAP_IsStateIdle(void);
extern int DWC_GetAIDBitmap(void);
extern int DWC_RAP_GetMyAidIfConnected(void);
int GFL_NET_DEVWIFI_IsOffline(void)
{
    int r;
    r = DWC_RAP_IsDisconnected();
    if (!DWC_RAP_IsWorkAllocated()) r |= 1;
    return r;
}
int GFL_NET_DEVWIFI_IsIdle(void)
{
    return DWC_RAP_IsStateIdle();
}
int GFL_NET_DEVWIFI_GetAidBitmap(void)
{
    return DWC_GetAIDBitmap();
}
int GFL_NET_DEVWIFI_GetMyAid(void)
{
    return DWC_RAP_GetMyAidIfConnected();
}
