/*
 * function: DWCi_AC_GetNintendoShopWepKey
 * address:  0x0205EA44
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_GetNintendoShopWepKey (shop_usb.o)
 *
 * symbols:
 *   decodeSSID                       0x0205eb30 arm
 *   makeShopWepKey                   0x0205ec2c arm
 */

extern void decodeSSID(char *ssid, unsigned char *buf);
extern void func_0205EC2C(unsigned char *seed, unsigned char *wepkey);

void DWCi_AC_GetNintendoShopWepKey(char *ssid, unsigned char *wep)
{
    unsigned char buf[24];

    decodeSSID(ssid, buf);
    func_0205EC2C(buf, wep);
}
