/*
 * function: PlayerOpInt
 * address:  0x021949B4
 * packet:   pkt_ov009_021949B4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      PlayerOpInt (libdwcgsgstats.TWL.HYB.a(gstats.o))
 *
 * symbols:
 *   GetPlayerIndex  0x02194724  arm  ov009
 *   OS_SPrintf  0x02084F40  arm
 *   ServerOpInt  0x02194754  arm  ov009
 *   d_021A5914     0x021A5914  data  a4
 */

extern int GetPlayerIndex(int *game, int pnum);
extern void OS_SPrintf(char *buf, const char *fmt, int b, int n);
extern void ServerOpInt(int a, char *buf, int c, int d, int e);
extern char d_021A5914[];

void PlayerOpInt(int a, int b, int c, int d, int e)
{
    char buf[0x40];
    OS_SPrintf(buf, d_021A5914, b, GetPlayerIndex((int *)a, e));
    ServerOpInt(a, buf, c, d, e);
}
