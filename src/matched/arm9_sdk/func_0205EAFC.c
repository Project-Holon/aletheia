/*
 * function: func_0205EAFC
 * address:  0x0205EAFC
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * SDK symbol: DWCi_AC_CheckNintendoUsbAP (shop_usb.o, libdwcac.TWL.HYB.a)
 *
 * symbols:
 *   memcmp          0x020923F0  arm
 *   str_020A8124    0x020A8124  data
 */

extern int memcmp(const void *a, const void *b, unsigned long n);

extern char str_020A8124[];

int func_0205EAFC(char *ssid)
{
    return memcmp(ssid, str_020A8124, 8) == 0;
}
