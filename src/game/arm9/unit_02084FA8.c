/*
 * file:     unit_02084FA8.c
 * function: func_02084FA8
 * address:  0x02084FA8
 * packet:   pkt_02084FA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   STD_TVSNPrintf  0x0208D834  arm
 */

extern int STD_TVSNPrintf(char *s, unsigned int n, const char *format, void *arg);

int func_02084FA8(char *s, unsigned int n, const char *format, void *arg)
{
    return STD_TVSNPrintf(s, n, format, arg);
}
