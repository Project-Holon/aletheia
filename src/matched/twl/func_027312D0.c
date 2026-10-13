/*
 * function: OS_IsAvailableWireless_ltdmain
 * address:  0x027312D0
 * packet:   pkt_027312D0
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

int OS_IsAvailableWireless_ltdmain(void)
{
    return ((**(volatile unsigned int **)0x02FFFDFC << 28) >> 31) == 1;
}
