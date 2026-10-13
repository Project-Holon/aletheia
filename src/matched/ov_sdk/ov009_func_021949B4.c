/*
 * function: func_021949B4
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
 *   func_02194724  0x02194724  arm  ov009
 *   OS_SPrintf  0x02084F40  arm
 *   func_02194754  0x02194754  arm  ov009
 *   d_021A5914     0x021A5914  data  a4
 */

extern int func_02194724(int *game, int pnum);
extern void OS_SPrintf(char *buf, const char *fmt, int b, int n);
extern void func_02194754(int a, char *buf, int c, int d, int e);
extern char d_021A5914[];

void func_021949B4(int a, int b, int c, int d, int e)
{
    char buf[0x40];
    OS_SPrintf(buf, d_021A5914, b, func_02194724((int *)a, e));
    func_02194754(a, buf, c, d, e);
}
