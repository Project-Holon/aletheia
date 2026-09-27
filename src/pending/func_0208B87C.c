/*
 * function: func_0208B87C
 * address:  0x0208B87C
 * packet:   pkt_0208B87C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * note:     spi/ARM9/pm.o PMi_WaitVBlank.  Same size (52 bytes); only the
 *           scratch register assignment differs: the original keeps the
 *           register address in r2 and the count in r0, the best C tried
 *           (a volatile local + reload) keeps the address in r0.  Functionally
 *           identical; left as a documented near miss.
 *
 * symbols:
 *   g_02FFFC3C  0x02FFFC3C  data  a4
 */

extern volatile unsigned int g_02FFFC3C;

void func_0208B87C(void)
{
    volatile unsigned int vcount = g_02FFFC3C;

    while (vcount == g_02FFFC3C) {
    }
}
