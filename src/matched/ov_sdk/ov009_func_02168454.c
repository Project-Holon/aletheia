/*
 * function: DWC_SetCommonKeyValueString
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
 *   gDwcCommonKvFormat  0x021A1FF8  data
 *   OS_SNPrintf  0x02084F80  arm
 *   strlen  0x0209477C  arm
 */

extern char gDwcCommonKvFormat[];
extern int OS_SNPrintf(char *dst, int len, const char *fmt, ...);
typedef unsigned char  u8;
extern int strlen(const u8 *s);

int DWC_SetCommonKeyValueString(const char *key, const char *value, char *string, char sep)
{
    OS_SNPrintf(string, 0x1000, gDwcCommonKvFormat, sep, key, sep, value);
    return strlen((const u8 *)string);
}
