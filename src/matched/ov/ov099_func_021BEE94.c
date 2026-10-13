/*
 * function: WIFICLUB_StateHandleNetError
 * address: 0x021BEE94
 * packet: pkt_ov099_021BEE94
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes after the 38-byte function.
 * blocker: ARM9 0203CB00 and 0203C628 lack outside code witnesses;
 *   tu --suggest-split leaves the singleton out.
 * blocker: 0x0203CB00 ARM verified MATCH, 52 bytes; copied from
 *   ov099_func_021BEAEC.c, leaf-cb00-r1.log.
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_FatalError) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; GFL_NET_STATE_FatalError 0x0203CADC arm.
 *   Leaf's unresolved site is ARM9 0203CADC.
 * blocker: 0x0203C628 ARM verified EXACT, 52 bytes; copied from
 *   ov099_func_021BEC60.c, blocker-c628-1.log.
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_WifiLoginMain(void);
 *   extern void GFL_NET_STATE_WifiConnected(void);
 *   int GFL_NET_STATE_IsWifiLoginOrConnected(void) {
 *       void *v = *(void **)(d_021469DC + 8);
 *       return v == (void *)GFL_NET_STATE_WifiLoginMain || v == (void *)GFL_NET_STATE_WifiConnected;
 *   }
 *   symbols: d_021469DC 0x021469DC data; GFL_NET_STATE_WifiLoginMain 0x0203C0F4 arm;
 *     GFL_NET_STATE_WifiConnected 0x0203C464 arm.
 * symbols:
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   GFL_NET_STATE_IsWifiLoginOrConnected 0x0203C628 arm
 */
typedef unsigned int u32;
extern int GFL_NET_STATE_IsFatalError(void);
extern int GFL_NET_STATE_IsWifiLoginOrConnected(void);
int WIFICLUB_StateHandleNetError(u32 p, int a) {
    if (!GFL_NET_STATE_IsFatalError() && !GFL_NET_STATE_IsWifiLoginOrConnected()) return a;
    *(u32 *)(p+460) = 10;
    return a;
}
