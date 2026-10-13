/*
 * unit: yes
 * function: GFL_NET_DEVWIFI_Begin, GFL_NET_DEVWIFI_Update
 * address: 0x021551B0
 * packet: pkt_ov009_021551B0
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetWifiUserData 0x0203D5EC arm
 *   GFL_NET_GetFriendList 0x0203D610 arm
 *   DWC_RAP_CreateWork 0x0215539C thumb ov009
 *   DWC_RAP_RunStateMachine 0x0215592C thumb ov009
 */
typedef unsigned int u32;
extern u32 GFL_NET_GetWifiUserData(void);
extern u32 GFL_NET_GetFriendList(void);
extern int DWC_RAP_CreateWork(int, int);
extern int DWC_RAP_RunStateMachine(int);
int GFL_NET_DEVWIFI_Begin(void (*cb)(int))
{
    u32 a;
    int r;
    a = GFL_NET_GetWifiUserData();
    r = DWC_RAP_CreateWork(a, GFL_NET_GetFriendList());
    if (cb) cb(1);
    return r;
}
int GFL_NET_DEVWIFI_Update(int a)
{
    return DWC_RAP_RunStateMachine(a);
}
