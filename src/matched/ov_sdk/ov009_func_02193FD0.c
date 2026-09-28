/*
 * function: func_02193FD0
 * address:  0x02193FD0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The module block when the test passes, else the fallback object.
 *
 * symbols:
 *   g_021A5890  0x021A5890  data
 *   func_02193F00  0x02193F00  arm  ov009
 */

extern char g_021A5890[];
extern char *func_02193F00(void);

char *func_02193FD0(void)
{
    char *p = func_02193F00();

    return p ? p : g_021A5890;
}

