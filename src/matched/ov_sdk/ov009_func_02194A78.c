/*
 * function: PlayerOpString
 * address:  0x02194A78
 * packet:   pkt_ov009_02194A78
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      PlayerOpString (libdwcgsgstats.TWL.HYB.a(gstats.o))
 *
 * symbols:
 *   GetPlayerIndex  0x02194724  arm  ov009
 *   OS_SPrintf  0x02084F40  arm
 *   ServerOpString  0x02194834  arm  ov009
 *   d_021A5914     0x021A5914  data  a4
 */

extern int GetPlayerIndex(int *game, int pnum);
extern void OS_SPrintf(char *buf, const char *fmt, int b, int n);
extern void ServerOpString(int a, char *buf, int c, int d, int e);
extern char d_021A5914[];

void PlayerOpString(int a, int b, int c, int d, int e)
{
    char buf[0x40];
    OS_SPrintf(buf, d_021A5914, b, GetPlayerIndex((int *)a, e));
    ServerOpString(a, buf, c, d, e);
}
