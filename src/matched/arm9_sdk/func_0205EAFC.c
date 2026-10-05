/*
 * function: func_0205EAFC
 * address:  0x0205EAFC
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_CheckNintendoUsbAP (shop_usb.o)
 *
 * symbols:
 *   memcmp                           0x020923f0 arm
 *   g_020A8124                       0x020a8124 data
 */

extern int memcmp(const void *s1, const void *s2, unsigned long n);

extern const char g_020A8124[]; /* "NWCUSBAP", the vendor object's @16393 */

int func_0205EAFC(char *ssid)
{
    if (memcmp(ssid, g_020A8124, 8) == 0) {
        return 1;
    }
    return 0;
}
