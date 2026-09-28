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
 * SDK symbol: DWCi_AC_CheckNintendoShopAP (shop_usb.o, libdwcac.TWL.HYB.a)
 *
 * symbols:
 *   decodeSSID       0x0205EB30  arm
 *   memcmp           0x020923F0  arm
 *   str_020A8118     0x020A8118  data
 */

extern void decodeSSID(char *ssid, unsigned char *buf);
extern int memcmp(const void *a, const void *b, unsigned long n);
extern char str_020A8118[];

int func_0205EA08(char *ssid)
{
    unsigned char buf[24];

    decodeSSID(ssid, buf);
    return memcmp(buf, str_020A8118, 8) == 0;
}
