/*
 * function: func_02194A78
 * address:  0x02194A78
 * packet:   pkt_ov009_02194A78
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02194724  0x02194724  arm  ov009
 *   func_02084F40  0x02084F40  arm
 *   func_02194834  0x02194834  arm  ov009
 *   d_021A5914     0x021A5914  data  a4
 */

extern int func_02194724(int a, int e);
extern void func_02084F40(char *buf, const char *fmt, int b, int n);
extern void func_02194834(int a, char *buf, int c, int d, int e);
extern char d_021A5914[];

void func_02194A78(int a, int b, int c, int d, int e)
{
    char buf[0x40];
    func_02084F40(buf, d_021A5914, b, func_02194724(a, e));
    func_02194834(a, buf, c, d, e);
}
