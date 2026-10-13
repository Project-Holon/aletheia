/*
 * unit: yes
 * function: GFL_NET_DEVWIFI_IsFriendWaiting, GFL_NET_DEVWIFI_IsVchatEnabled, GFL_NET_DEVWIFI_GetNewClientAid, GFL_NET_DEVWIFI_SetAllowConnect, GFL_NET_DEVWIFI_IsInSession
 * address: 0x02155338
 * packet: pkt_ov009_02155338
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Follower GFL_NET_DEVWIFI_SetAllowConnect resolves through the verified existing 02156CF4
 * unit after its function inventory was corrected to include 02156D70.
 * symbols:
 *   DWC_RAP_GetFriendStatus 0x02156874 thumb ov009
 *   DWC_RAP_GetVchatEnabled 0x02156B70 thumb ov009
 *   DWC_RAP_GetNewClientAid 0x02156B8C thumb ov009
 *   DWC_RAP_StoreAllowConnect 0x02156D70 thumb ov009
 *   DWC_RAP_IsStateInSession 0x02156CD0 thumb ov009
 */
extern unsigned char DWC_RAP_GetFriendStatus(int);
typedef signed short s16;
typedef unsigned int u32;
extern s16 DWC_RAP_GetVchatEnabled(void);
extern int DWC_RAP_GetNewClientAid(void);
extern void DWC_RAP_StoreAllowConnect(u32);
extern int DWC_RAP_IsStateInSession(void);
int GFL_NET_DEVWIFI_IsFriendWaiting(int n)
{
    if (DWC_RAP_GetFriendStatus(n) == 6) return 1;
    return 0;
}
s16 GFL_NET_DEVWIFI_IsVchatEnabled(void)
{
    return DWC_RAP_GetVchatEnabled();
}
int GFL_NET_DEVWIFI_GetNewClientAid(void)
{
    return DWC_RAP_GetNewClientAid();
}
void GFL_NET_DEVWIFI_SetAllowConnect(u32 v)
{
    DWC_RAP_StoreAllowConnect(v);
}
int GFL_NET_DEVWIFI_IsInSession(void)
{
    return DWC_RAP_IsStateInSession();
}
