/*
 * function: CheckValidKey
 * address:  0x0219E274
 * packet:   pkt_ov009_0219E274
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      CheckValidKey (sb_server.o)
 *
 * BLOCKER (codegen only, size exact 96): the original copies the two InvalidKeys
 * words with `ldr r2,[r1]; ldr r1,[r1,#4]` then stores both, leaving r1 as the
 * destination address (`add r4, sp, #0`); mwcc swaps the second load to `ldr r0`
 * (so it can page the pop-order return through r0) and materialises r4 only
 * before the loop.  The loop, the `cmp r5,#2`/`blo` terminator and the two
 * returns are otherwise identical.  Spellings tried: for, do/while, goto, while.
 *
 * symbols:
 *   strcmp      0x020948E0  arm
 *   g_021A8120  0x021A8120  data
 */

extern int strcmp(char *a, char *b);
extern char *g_021A8120[];

static int CheckValidKey(char *key)
{
    char *InvalidKeys[2];
    unsigned int i;

    InvalidKeys[0] = g_021A8120[0];
    InvalidKeys[1] = g_021A8120[1];
    i = 0;
loop:
    if (strcmp(key, InvalidKeys[i]) == 0)
        return 0;
    i++;
    if (i < 2)
        goto loop;
    return 1;
}
