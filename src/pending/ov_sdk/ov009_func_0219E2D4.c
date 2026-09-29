/*
 * function: mytok
 * address:  0x0219E2D4
 * packet:   pkt_ov009_0219E2D4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      mytok (sb_server.o)
 *
 * blocker (w5_nm): byte-correct.  The DWARF has one local (result) and a char
 * delim, and the static is function-local (_ZZ5mytokPccE6thestr), so the
 * cursor is the static itself with `*thestr++ = '\0'`; that gives every byte.
 * Our compiler emits the function-local static as `.bss+0`, while the vendor
 * relocates the named static; the `.bss` rule is ARM9-only and the vendor slot
 * is not section-relative, so +0x64 (0x021AEAF8) stays unresolved.  A file-scope
 * static or extern (which would resolve as sole-ref) changes 9 bytes: the tail
 * then stores before reloading the cursor.  Needs tooling (named local static
 * against our .bss slot), not C.  Tried before: file-scope static cursor with
 * an ip local, char temp, post-inc orders.
 *
 * symbols:
 *   .bss                           0x021AEAF8  data
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
