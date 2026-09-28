/*
 * function: func_0217F130
 * address:  0x0217F130
 * packet:   pkt_ov009_0217F130
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiInt64ToString (gsplatformutil.o)
 *
 * symbols:
 *   func_02084F40                  0x02084F40  arm
 *   g_021A3834                     0x021A3834  data
 */

extern int func_02084F40(char *dst, char *fmt, ...);
extern char g_021A3834[];

void func_0217F130(char *theNumberStr, long long theNumber)
{
    func_02084F40(theNumberStr, g_021A3834, theNumber);
}
