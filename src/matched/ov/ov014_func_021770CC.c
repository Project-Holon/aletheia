/*
 * function: GFL_NET_DEVWIRELESS_Cleanup
 * address: 0x021770CC
 * packet: pkt_ov014_021770CC
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sDevWirelessWork 0x021797A0 data a4
 *   GFL_NET_DEVWIRELESS_OnShutdownDone 0x021770A8 thumb ov014
 *   NET_WHPIPE_RequestEnd 0x02177EB0 thumb ov014
 */
typedef unsigned char u8;
extern u8 *sDevWirelessWork;
extern int GFL_NET_DEVWIRELESS_OnShutdownDone(void *);
extern int NET_WHPIPE_RequestEnd(int a);
int GFL_NET_DEVWIRELESS_Cleanup(void (*cb)(void *))
{
    if(sDevWirelessWork != 0) {
        *(void (**)(void *))(sDevWirelessWork+4)=cb;
        return NET_WHPIPE_RequestEnd((int)GFL_NET_DEVWIRELESS_OnShutdownDone);
    }
    return 1;
}
