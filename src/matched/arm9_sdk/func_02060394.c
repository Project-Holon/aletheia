/*
 * function: func_02060394
 * address:  0x02060394
 * packet:   pkt_0205F7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Symbol at this offset is DWC_BACKUPlCheckSsid (libdwcbm dwc_backup.o,
 * dwc_backup.c:498).  DWARF: one formal (unsigned char *ssid) and one
 * local (int i).
 *
 * symbols:
 *   DWC_BACKUPlCheckSsid 0x02060394 arm
 */

int func_02060394(unsigned char *ssid)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (ssid[i] != 0)
            return 1;
    }
    return 0;
}
