/*
 * function: TeamOpString
 * address:  0x02194954
 * packet:   pkt_ov009_02194954
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TeamOpString (libdwcgsgstats.TWL.HYB.a(gstats.o))
 *
 * symbols:
 *   GetTeamIndex  0x021946F4  arm  ov009
 *   OS_SPrintf  0x02084F40  arm
 *   ServerOpString  0x02194834  arm  ov009
 *   d_021A590C     0x021A590C  data  a4
 */

extern int GetTeamIndex(int *game, int tnum);
extern void OS_SPrintf(char *buf, const char *fmt, int b, int n);
extern void ServerOpString(int a, char *buf, int c, int d, int e);
extern char d_021A590C[];

void TeamOpString(int a, int b, int c, int d, int e)
{
    char buf[0x40];
    OS_SPrintf(buf, d_021A590C, b, GetTeamIndex((int *)a, e));
    ServerOpString(a, buf, c, d, e);
}
