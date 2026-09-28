/*
 * function: func_0205EA08
 * address:  0x0205EA08
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_CheckNintendoShopAP (shop_usb.o)
 *
 * symbols:
 *   decodeSSID                       0x0205eb30 arm
 *   memcmp                           0x020923f0 arm
 *   @16365                           0x020a8118 data
 */

extern void func_0205EB30(char *ssid, unsigned char *buf);
extern int memcmp(const void *s1, const void *s2, unsigned long n);

int func_0205EA08(char *ssid)
{
    unsigned char buf[24];

    func_0205EB30(ssid, buf);
    if (memcmp(buf, "NDWCSHAP", 8) == 0) {
        return 1;
    }
    return 0;
}
