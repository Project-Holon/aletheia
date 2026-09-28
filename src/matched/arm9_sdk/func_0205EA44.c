/*
 * function: func_0205EA44
 * address:  0x0205EA44
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK symbol: DWCi_AC_GetNintendoShopWepKey (shop_usb.o, libdwcac.TWL.HYB.a)
 *
 * symbols:
 *   decodeSSID       0x0205EB30  arm
 *   makeShopWepKey   0x0205EC2C  arm
 */

extern void decodeSSID(char *ssid, unsigned char *buf);
extern void makeShopWepKey(unsigned char *seed, unsigned char *wepkey);

void func_0205EA44(char *ssid, unsigned char *wep)
{
    unsigned char buf[24];

    decodeSSID(ssid, buf);
    makeShopWepKey(buf, wep);
}
