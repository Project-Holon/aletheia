/*
 * unit: yes
 * function: COMPATIBLE_IRC_SYS_StepSyncTiming,COMPATIBLE_IRC_SYS_IsPartnerReady
 * address: 0x021B62AC
 * packet: pkt_ov101_021B62AC
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 */
struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);
int COMPATIBLE_IRC_SYS_StepSyncTiming(int *p)
{
    if(p[30]) return 1;
    switch(p[17]) {
    case 0:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),14,13);
        p[17]=1;
        break;
    case 1:
        if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),14,13)) p[17]=2;
        break;
    case 2:
        p[17]=0;
        return 1;
    }
    return 0;
}
int COMPATIBLE_IRC_SYS_IsPartnerReady(int *p) { if(p[30]) return 1; return p[20]; }
