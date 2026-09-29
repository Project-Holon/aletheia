/*
 * function: mytok
 * address:  0x0219E2D4
 * packet:   pkt_ov009_0219E2D4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      mytok (sb_server.o)
 *
 * note: the static is function-local (_ZZ5mytokPccE6thestr), so the cursor is
 * the static itself, with a post-incrementing store of the terminator.  Our
 * compiler relocates it as `.bss`+0; the symbols: line places that section
 * from the static's name.
 *
 * symbols:
 *   _ZZ5mytokPccE6thestr            0x021AEAF8  data
 */

char *mytok(char *instr, char delim)
{
    char *result;
    static char *thestr;

    if (instr)
        thestr = instr;
    result = thestr;
    while (*thestr && *thestr != delim)
        thestr++;
    if (thestr == result)
        result = 0;
    if (*thestr)
        *thestr++ = '\0';
    return result;
}
