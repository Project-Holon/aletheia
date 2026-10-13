/*
 * function: INITi_IsRunOnTwl
 * address:  0x02004EB4
 * packet:   pkt_02004EB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

int INITi_IsRunOnTwl(void)
{
    return (*(volatile unsigned char *)0x04004000 & 3) == 1;
}
