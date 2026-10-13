/*
 * function: WIFICLUB_StateWatchLogin
 * address: 0x021BEAEC
 * packet: pkt_ov099_021BEAEC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: ARM9 0x0203C600 and 0x0203CB00 have no outside code witness.
 * extent: 122 bytes code followed by two zero alignment bytes.
 * blocker: 0x0203C600 ARM verified EXACT, 40 bytes, leaf-c600-r1.log.
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_WifiLoginMain(void);
 *   int GFL_NET_STATE_IsWifiLoginState(void) {
 *       return *(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_WifiLoginMain;
 *   }
 *   symbols: d_021469DC 0x021469DC data; GFL_NET_STATE_WifiLoginMain 0x0203C0F4 arm.
 * blocker: 0x0203CB00 ARM verified MATCH, 52 bytes, leaf-cb00-r1.log.
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_FatalError) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; GFL_NET_STATE_FatalError 0x0203CADC arm.
 *   Leaf's only unresolved site is ARM9 0x0203CADC.
 * symbols:
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   DWC_RAP_IsUserDataChanged 0x02156C84 thumb ov009
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   GFL_NET_STATE_IsWifiLoginState 0x0203C600 arm
 *   WIFICLUB_BuildOwnStatus 0x021BE6F0 thumb ov099
 *   WIFICLUB_RefreshVisibleList 0x021BE788 thumb ov099
 *   WIFICLUB_BeginIdle 0x021BE4F0 thumb ov099
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   GFL_NET_STATE_GetWifiState 0x0203C3EC arm
 *   WIFICLUB_OnFatalError 0x021BE900 thumb ov099
 */
extern int WIFICLUB_UpdateTalkStream(char *, int);
extern unsigned char DWC_RAP_IsUserDataChanged(void);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern int GFL_NET_STATE_IsWifiLoginState(void);
extern void WIFICLUB_BuildOwnStatus(char *, int, int);
extern int WIFICLUB_RefreshVisibleList(char *);
extern int WIFICLUB_BeginIdle(char *, int);
extern int GFL_NET_STATE_IsFatalError(void);
extern int GFL_NET_STATE_GetWifiState(void);
extern void WIFICLUB_OnFatalError(char *);
int WIFICLUB_StateWatchLogin(char *p, int ret)
{
    if (!WIFICLUB_UpdateTalkStream(p, ret)) return ret;
    if (DWC_RAP_IsUserDataChanged()) {
        *(int *)(p + 0x1cc) = 0x3c;
        WIFICLUB_ShowStreamedMessage(p, 0x1e, 1);
    }
    if (GFL_NET_STATE_IsWifiLoginState()) {
        if (*(int *)(p + 0x1e8)) {
            *(int *)(p + 0x1cc) = 7;
        } else {
            WIFICLUB_BuildOwnStatus(p, 1, 2);
            WIFICLUB_RefreshVisibleList(p);
            *(int *)(p + 0x1cc) = WIFICLUB_BeginIdle(p, 0);
        }
    } else {
        if (GFL_NET_STATE_IsFatalError() || GFL_NET_STATE_GetWifiState() == 3) WIFICLUB_OnFatalError(p);
    }
    return ret;
}
