/*
 * function: gsiInt64ToString
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
 *   OS_SPrintf                  0x02084F40  arm
 *   gGsInt64Format                     0x021A3834  data
 */

extern int OS_SPrintf(char *dst, char *fmt, ...);
extern char gGsInt64Format[];

void gsiInt64ToString(char *theNumberStr, long long theNumber)
{
    OS_SPrintf(theNumberStr, gGsInt64Format, theNumber);
}
