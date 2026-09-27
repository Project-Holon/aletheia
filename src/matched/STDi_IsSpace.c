/*
 * function: STDi_IsSpace
 * address:  0x0208CF5C
 * packet:   pkt_0208CF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libstd std_string.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * The space set is one 24-bit mask over '\t'..' ' tested with a register
 * shift; the result local preset to 0 is what gives `mov r0,#0` ahead of
 * the `bxhi` (a switch builds a jump table, a ternary a second exit).
 */

int STDi_IsSpace(int c)
{
    int ret = 0;
    unsigned int d = (unsigned int)(c - 9);
    if (d <= 0x17 && (0x0080001F & (1 << d)))
        ret = 1;
    return ret;
}
