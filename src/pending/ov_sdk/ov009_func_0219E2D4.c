/*
 * function: mytok
 * address:  0x0219E2D4
 * packet:   pkt_ov009_0219E2D4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      mytok (sb_server.o)
 *
 * BLOCKER (register allocation only, size exact 104): the file-scope static
 * `thestr` is the token cursor itself (the object shows a single ABS32 at
 * +0x64, `_ZZ5mytokPccE6thestr` -> 0x021AEAF8, and the tail reads that pointer
 * and writes back pointer+1), so the body is the GameSpy strtok: save the
 * input into the static, walk `ip` while `*ip && *ip != delim` writing the
 * static each step, clear the token byte, bump the static and return the
 * token start.  mwcc reproduces every branch, both epilogues and the 104-byte
 * extent but keeps the cursor in r3 and the character in ip (r12), while the
 * original keeps the cursor in ip (r12) and the character in r3.  Every
 * spelling tried (char* static, char temp, aliasing instr/result, post-inc
 * order) leaves mwcc with the same swap; the object is hand-spelled.
 *
 * symbols:
 *   thestr  0x021AEAF8  data
 */

static char *thestr;

static char *mytok(char *instr, int delim)
{
    char *result;
    char *ip;

    if (instr != 0)
        thestr = instr;
    result = thestr;
    ip = result;
    while (*ip != 0 && *ip != delim)
    {
        ip++;
        thestr = ip;
    }
    if (ip == result)
        result = 0;
    if (*ip == 0)
        return result;
    *ip = 0;
    thestr++;
    return result;
}
