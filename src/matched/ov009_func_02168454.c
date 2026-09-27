/*
 * function: func_02168454
 * address:  0x02168454
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWC_SetCommonKeyValueString: writes one separator-key-separator-value pair and returns its length.
 *
 * symbols:
 *   d_021A1FF8  0x021A1FF8  data
 *   OS_SNPrintf  0x02084F80  arm
 *   func_0209477C  0x0209477C  arm
 */

extern char d_021A1FF8[];
extern int OS_SNPrintf(char *dst, int len, const char *fmt, ...);
extern int func_0209477C(const char *s);

int func_02168454(const char *key, const char *value, char *string, char sep)
{
    OS_SNPrintf(string, 0x1000, d_021A1FF8, sep, key, sep, value);
    return func_0209477C(string);
}
