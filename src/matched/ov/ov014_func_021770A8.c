/*
 * function: GFL_NET_DEVWIRELESS_OnShutdownDone
 * address: 0x021770A8
 * packet: pkt_ov014_021770A8
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sDevWirelessWork 0x021797A0 data a4
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
extern u8 *sDevWirelessWork;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
int GFL_NET_DEVWIRELESS_OnShutdownDone(void *arg)
{
    if (*(void (**)(void *))(sDevWirelessWork+4) != 0)
        (*(void (**)(void *))(sDevWirelessWork+4))(arg);
    func_020307B0(sDevWirelessWork);
    sDevWirelessWork=0;
    return 1;
}
