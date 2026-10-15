/*
 * function: func_0216848C
 * address:  0x0216848C
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWC_AddCommonKeyValueString: appends one key-value pair and returns the whole string's length.
 *
 * symbols:
 *   strchr  0x02094A28  arm
 *   func_02168454  0x02168454  arm  ov009
 *   strlen  0x0209477C  arm
 */

extern char *strchr(const char *s, int c);
extern int func_02168454(const char *key, const char *value, char *string, char sep);
typedef unsigned char  u8;
extern int strlen(const u8 *s);

int func_0216848C(const char *key, const char *value, char *string, char sep)
{
    func_02168454(key, value, strchr(string, 0), sep);
    return strlen((const u8 *)string);
}
