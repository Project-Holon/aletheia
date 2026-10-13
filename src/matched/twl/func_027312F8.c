/*
 * function: OS_IsForceDisableWireless_ltdmain
 * address:  0x027312F8
 * packet:   pkt_027312F8
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

int OS_IsForceDisableWireless_ltdmain(void)
{
    volatile unsigned char *p = (volatile unsigned char *)0x02FFFD68;
    return ((unsigned int)p[4] << 31 >> 31) == 1;
}
