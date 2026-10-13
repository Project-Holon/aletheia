/*
 * function: KeyValHashKey
 * address:  0x0219E8C4
 * packet:   pkt_ov009_0219E8C4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   StringHash                   0x0219E848  arm
*/

extern int StringHash(char *s, int numbuckets);

int KeyValHashKey(void *elem, int numbuckets)
{
    return StringHash(*(char **)elem, numbuckets);
}
