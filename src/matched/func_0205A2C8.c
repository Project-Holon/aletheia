/*
 * function: WDSGetRssi8
 * address:  0x0205A2C8
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcac wds.o.
 */
unsigned char WDSGetRssi8(unsigned char rssi)
{
    int v = rssi >> 2;
    if ((rssi & 2) == 0)
        v += 25;
    return (unsigned char)v;
}
