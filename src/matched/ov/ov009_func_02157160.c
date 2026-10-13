/*
 * function: DWC_RAPCOMMON_ClearNetError
 * address: 0x02157160
 * packet: pkt_ov009_02157160
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_STATE_SetWifiError 0x0203CA04 arm
 *   GFL_NET_STATE_ClearErrorMode 0x0203C968 arm
 *   func_02059F18 0x02059F18 arm
 */
extern void GFL_NET_STATE_SetWifiError(void);
extern void GFL_NET_STATE_ClearErrorMode(void);
extern void func_02059F18(void);
void DWC_RAPCOMMON_ClearNetError(void)
{
    GFL_NET_STATE_SetWifiError();
    GFL_NET_STATE_ClearErrorMode();
    func_02059F18();
}
