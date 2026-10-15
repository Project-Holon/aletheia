/*
 * function: value_for_key_safe
 * address:  0x02193FD0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The module block when the test passes, else the fallback object.
 *
 * symbols:
 *   gGstatsEmptyString  0x021A5890  data
 *   value_for_key  0x02193F00  arm  ov009
 */

extern char gGstatsEmptyString[];
extern char *value_for_key(char *s, char *key);

char *value_for_key_safe(char *s, char *key)
{
    char *p = value_for_key(s, key);

    return p ? p : gGstatsEmptyString;
}

