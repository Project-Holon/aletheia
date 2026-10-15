/*
 * function: DWCi_GetDefaultMatchFilter
 * address:  0x0216FAD4
 * packet:   pkt_ov009_0216FAD4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GetDefaultMatchFilter (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   OS_SNPrintf  0x02084F80  arm
 *   func_0209477C  0x0209477C  arm
 *   g_021A20E0     0x021A20E0  data
 *   g_021A20F0     0x021A20F0  data
 *   g_021A209C     0x021A209C  data
 *   g_021A20A4     0x021A20A4  data
 *   g_021A2170     0x021A2170  data
 *   g_021A217C     0x021A217C  data
 *   g_021A2108     0x021A2108  data
 *   g_021A2164     0x021A2164  data
 */

extern int OS_SNPrintf(char *dst, unsigned int len, const char *fmt, ...);
typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);
extern char g_021A20E0[];
extern char g_021A20F0[];
extern char g_021A209C[];
extern char g_021A20A4[];
extern char g_021A2170[];
extern char g_021A217C[];
extern char g_021A2108[];
extern char g_021A2164[];

int DWCi_GetDefaultMatchFilter(char *filter, int profileID, unsigned char numEntry, unsigned char matchType,
                  unsigned char hostState)
{
    char tempFilter[511];

    if (hostState == 3)
        OS_SNPrintf(tempFilter, 511, g_021A20F0, g_021A20E0, 0, g_021A20E0, 2);
    else
        OS_SNPrintf(tempFilter, 511, g_021A209C, g_021A20E0, hostState);
    OS_SNPrintf(filter, 511, g_021A2108, g_021A2164, 90, g_021A20A4, profileID, numEntry, numEntry,
                  g_021A2170, matchType, g_021A217C, 0, tempFilter);
    return func_0209477C((const u8 *)filter);
}
