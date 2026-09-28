/*
 * function: func_02194954
 * address:  0x02194954
 * packet:   pkt_ov009_02194954
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021946F4  0x021946F4  arm  ov009
 *   func_02084F40  0x02084F40  arm
 *   func_02194834  0x02194834  arm  ov009
 *   d_021A590C     0x021A590C  data  a4
 */

extern int func_021946F4(int a, int e);
extern void func_02084F40(char *buf, const char *fmt, int b, int n);
extern void func_02194834(int a, char *buf, int c, int d, int e);
extern char d_021A590C[];

void func_02194954(int a, int b, int c, int d, int e)
{
    char buf[0x40];
    func_02084F40(buf, d_021A590C, b, func_021946F4(a, e));
    func_02194834(a, buf, c, d, e);
}
