/*
 * function: NCFGi_CheckSsid
 * address:  0x02060394
 * packet:   pkt_0205F7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NCFGi_CheckSsid (check.o)
 *
 * symbols:
 *   (none)
 */

int NCFGi_CheckSsid(unsigned char *ssid)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (ssid[i] != 0) {
            return 1;
        }
    }
    return 0;
}
