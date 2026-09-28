/*
 * function: DWC_AC_CheckWiFiStation
 * address:  0x0205BFD4
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcac dwc_ac.o.
 */
extern int DWCi_AC_CheckNintendoShopAP(void *ssid, int len);

int DWC_AC_CheckWiFiStation(void *ssid, unsigned short len)
{
    if (len != 32)
        return 0;
    return DWCi_AC_CheckNintendoShopAP(ssid, len);
}
