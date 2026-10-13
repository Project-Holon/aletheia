/*
 * function: WIFICLUB_StateWatchConnection
 * address: 0x021BEC60
 * packet: pkt_ov099_021BEC60
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0203CB00, 0203C628 and 0203C5EC lack code witnesses.
 * lever: duplicate state-update tail in each arm, goto shared return;
 *   writing one update after the outer branch cross-jumps the earlier call.
 * blocker: 0x0203CB00 ARM verified MATCH, 52 bytes; copied from
 *   ov099_func_021BEB68.c (leaf-cb00-r1.log).
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_FatalError) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; GFL_NET_STATE_FatalError 0x0203CADC arm.
 * blocker: 0x0203C628 ARM verified EXACT, 52 bytes, blocker-c628-1.log.
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_WifiLoginMain(void);
 *   extern void GFL_NET_STATE_WifiConnected(void);
 *   int GFL_NET_STATE_IsWifiLoginOrConnected(void) {
 *       void *v = *(void **)(d_021469DC + 8);
 *       return v == (void *)GFL_NET_STATE_WifiLoginMain || v == (void *)GFL_NET_STATE_WifiConnected;
 *   }
 *   symbols: d_021469DC 0x021469DC data; GFL_NET_STATE_WifiLoginMain 0x0203C0F4 arm;
 *     GFL_NET_STATE_WifiConnected 0x0203C464 arm.
 * blocker: 0x0203C5EC ARM verified EXACT, 20 bytes, blocker-c5ec-1.log.
 *   extern char *d_021469DC;
 *   int GFL_NET_STATE_IsWifiDisconnectFinal(void) { return *(unsigned char *)(d_021469DC + 0x4a); }
 *   symbols: d_021469DC 0x021469DC data.
 * symbols:
 *   POKE_REGULATION_DeleteText 0x0201A570 thumb
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   GFL_NET_STATE_GetWifiState 0x0203C3EC arm
 *   WIFICLUB_OnFatalError 0x021BE900 thumb ov099
 *   GFL_NET_STATE_IsWifiLoginOrConnected 0x0203C628 arm
 *   WIFICLUBACTOR_IsReady 0x021B96CC thumb ov099
 *   WIFICLUB_ClearPeerActors 0x021BE26C thumb ov099
 *   GFL_NET_STATE_IsWifiDisconnectFinal 0x0203C5EC arm
 *   GFL_NET_IsConnectMember 0x0203D1C0 arm
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   WIFICLUB_BeginIdle 0x021BE4F0 thumb ov099
 */
extern void POKE_REGULATION_DeleteText(void *);
extern int GFL_NET_STATE_IsFatalError(void);
extern int GFL_NET_STATE_GetWifiState(void);
extern void WIFICLUB_OnFatalError(char *);
extern int GFL_NET_STATE_IsWifiLoginOrConnected(void);
extern int WIFICLUBACTOR_IsReady(int *);
extern void WIFICLUB_ClearPeerActors(char *);
extern int GFL_NET_STATE_IsWifiDisconnectFinal(void);
typedef unsigned int   u32;
extern u32 GFL_NET_IsConnectMember(u32 index);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern int WIFICLUB_BeginIdle(char *, int);
int WIFICLUB_StateWatchConnection(char *p, int ret)
{
    if (*(int *)(p + 0x1e0) > 0) {
        *(int *)(p + 0x1e0) -= 1;
        return ret;
    }
    if (*(void **)(p + 0x1344)) {
        POKE_REGULATION_DeleteText(*(void **)(p + 0x1344));
        *(void **)(p + 0x1344) = 0;
    }
    if (GFL_NET_STATE_IsFatalError() || GFL_NET_STATE_GetWifiState() == 3) {
        WIFICLUB_OnFatalError(p);
    } else {
        if (GFL_NET_STATE_IsWifiLoginOrConnected()) {
            if (WIFICLUBACTOR_IsReady((int *)(p + 0x274)) == 1) WIFICLUB_ClearPeerActors(p);
            *(int *)(p + 0x1cc) = WIFICLUB_BeginIdle(p, 0);
            goto done;
        } else {
            if (GFL_NET_STATE_GetWifiState() < 4 && !GFL_NET_STATE_IsWifiDisconnectFinal() && GFL_NET_IsConnectMember(0xff)) goto done;
            GFL_NET_STATE_WifiDisconnect(1);
            if (WIFICLUBACTOR_IsReady((int *)(p + 0x274)) == 1) WIFICLUB_ClearPeerActors(p);
        }
        *(int *)(p + 0x1cc) = WIFICLUB_BeginIdle(p, 0);
    }
done:
    return ret;
}
