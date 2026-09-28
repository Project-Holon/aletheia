/*
 * function: func_0205EB20
 * address:  0x0205EB20
 * packet:   pkt_0205EB20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_GetNintendoUSBWepKey (libdwcac.TWL.HYB.a(shop_usb.o))
 *
 * symbols:
 *   makeUsbWepKey                    0x0205ec7c arm
 */

extern void makeUsbWepKey(unsigned char *seed, unsigned char *wepkey);

void func_0205EB20(char *ssid, unsigned char *wep)
{
    makeUsbWepKey((unsigned char *)ssid + 12, wep);
}
