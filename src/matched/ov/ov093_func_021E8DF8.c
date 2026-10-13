/*
 * function: BTLV_CORE_UnloadOverlays
 * address:  0x021E8DF8
 * packet:   pkt_ov093_021E8DF8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov094_id       0x0000005E  data
 *   ov095_id       0x0000005F  data
 *   ov096_id       0x00000060  data
 *   BTLV_CORE_ExitDisplay  0x021E8F08  thumb  ov093
 *   func_02034A5C  0x02034A5C  arm
 *   GFL_NET_IsNetTypeWifi  0x0203D29C  arm
 */
extern char ov094_id[], ov095_id[], ov096_id[];
extern void BTLV_CORE_ExitDisplay(void);
extern void func_02034A5C(int id);
typedef unsigned int   u32;
extern u32 GFL_NET_IsNetTypeWifi(void);

void BTLV_CORE_UnloadOverlays(void)
{
    BTLV_CORE_ExitDisplay();
    func_02034A5C((int)ov094_id);
    func_02034A5C((int)ov095_id);
    if (GFL_NET_IsNetTypeWifi() == 0) {
        func_02034A5C((int)ov096_id);
    }
}
