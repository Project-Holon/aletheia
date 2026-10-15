/*
 * function: OS_GetTickLo
 * address:  0x02087170
 * packet:   pkt_02087170
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_tick.o OS_GetTickLo.
 */

unsigned short OS_GetTickLo(void)
{
    return *(volatile unsigned short *)0x04000100;
}
