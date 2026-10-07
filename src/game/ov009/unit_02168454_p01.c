/*
 * file:     unit_02168454_p01.c
 * unit:     yes
 * function: func_02168454, func_0216848C
 * address:  0x02168454
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021A1FF8  0x021A1FF8  data
 *   OS_SNPrintf  0x02084F80  arm
 *   func_0209477C  0x0209477C  arm
 *   func_02094A28  0x02094A28  arm
 */
typedef unsigned char  u8;

extern int OS_SNPrintf(char *dst, int len, const char *fmt, ...);
extern int func_0209477C(const u8 *s);
extern char *func_02094A28(const char *s, int c);
int func_02168454(const char *key, const char *value, char *string, char sep);
int func_0216848C(const char *key, const char *value, char *string, char sep);
extern char d_021A1FF8[];


/*
 * DWC_SetCommonKeyValueString: writes one separator-key-separator-value pair and returns its length.
 */
int func_02168454(const char *key, const char *value, char *string, char sep)
{
    OS_SNPrintf(string, 0x1000, d_021A1FF8, sep, key, sep, value);
    return func_0209477C((const u8 *)string);
}


/*
 * DWC_AddCommonKeyValueString: appends one key-value pair and returns the whole string's length.
 */
int func_0216848C(const char *key, const char *value, char *string, char sep)
{
    func_02168454(key, value, func_02094A28(string, 0), sep);
    return func_0209477C((const u8 *)string);
}
