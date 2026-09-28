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
 * BLOCKER (codegen only, size exact 104): string.h's strtok reference
 * implementation with a file-static `thestr` counter, but mwcc does not use it
 * here.  The original increments the static with a load/`add r2,r3,#1`/store
 * sequence and returns the accepting token via the `bxeq lr` fast exit; mwcc
 * instead keeps the static in the global pointer g_021AEAF8[0] only, indexes
 * the source with a callee-saved r4 and folds the epilogue into popeq.  The
 * parse loop, delimiter store and `*p=0` are semantically right.  The exact
 * GameSpy/glibc strtok body could not be recovered from the object.
 *
 * symbols:
 *   g_021AEAF8  0x021AEAF8  data
 */

extern char *g_021AEAF8[];

static char *mytok(char *instr, char delim)
{
    char *result;
    char *p;
    static int thestr;

    if (instr != 0)
        g_021AEAF8[0] = instr;
    result = g_021AEAF8[0];
    p = result;
    while (*p != 0 && *p != delim)
        p++;
    g_021AEAF8[0] = p;
    if (p == result)
        result = 0;
    if (*p == 0)
        return result;
    *p = 0;
    {
        int t = thestr;
        thestr = t + 1;
    }
    g_021AEAF8[0] = p + 1;
    return result;
}
