/*
 * function: func_0206043C
 * address:  0x0206043C
 * packet:   pkt_0205F7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NCFGi_CheckAddress (check.o)
 *
 * symbols:
 *   (none)
 */

int func_0206043C(unsigned char *address)
{
    if (address[0] == 127) {
        return 0;
    }
    if (address[0] < 1) {
        return 0;
    }
    if (address[0] <= 223) {
        return 1;
    }
    return 0;
}
