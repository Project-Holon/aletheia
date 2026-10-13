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

extern int STD_TVSNPrintf(char *dst, unsigned int len, const char *format, void *vlist);

int func_02084FA8(char *dst, unsigned int len, const char *format, void *vlist)
{
    return STD_TVSNPrintf(dst, len, format, vlist);
}
