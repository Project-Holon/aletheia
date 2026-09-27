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
 *   func_02094A28  0x02094A28  arm
 *   func_02168454  0x02168454  arm  ov009
 *   func_0209477C  0x0209477C  arm
 */

extern char *func_02094A28(const char *s, int c);
extern int func_02168454(const char *key, const char *value, char *string, char sep);
extern int func_0209477C(const char *s);

int func_0216848C(const char *key, const char *value, char *string, char sep)
{
    func_02168454(key, value, func_02094A28(string, 0), sep);
    return func_0209477C(string);
}
