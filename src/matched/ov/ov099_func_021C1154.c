/*
 * function: WIFICLUB_HandleNetFailure
 * address: 0x021C1154
 * packet: pkt_ov099_021C1154
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero alignment bytes at 0x021C119E.
 * blocker: ARM9 0x0203CB00 lacks an outside code witness.
 * blocker: 0x0203CB00 ARM verified MATCH, 52 bytes, blocker-1.log.
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_FatalError) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; GFL_NET_STATE_FatalError 0x0203CADC arm.
 *   Leaf's only unresolved site is ARM9 0x0203CADC; the integrator owns it.
 * symbols:
 *   GFL_NET_STATE_GetWifiState 0x0203C3EC arm
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   WIFICLUB_SetPartnerNameWord 0x021BA874 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   WIFICLUB_OnFatalError 0x021BE900 thumb ov099
 */
extern int GFL_NET_STATE_GetWifiState(void);
extern int GFL_NET_STATE_IsFatalError(void);
extern void WIFICLUB_SetPartnerNameWord(char *, int);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern void WIFICLUB_OnFatalError(char *);
int WIFICLUB_HandleNetFailure(char *p)
{
    if (GFL_NET_STATE_GetWifiState() >= 3) {
        WIFICLUB_SetPartnerNameWord(p, *(int *)(p + 0x1f0));
        WIFICLUB_ShowStreamedMessage(p, 15, 0);
        *(int *)(p + 0x1cc) = 19;
    } else {
        if (GFL_NET_STATE_IsFatalError() != 0) WIFICLUB_OnFatalError(p);
        else return 0;
    }
    *(unsigned short *)(p + 0x244) = 0;
    return 1;
}
