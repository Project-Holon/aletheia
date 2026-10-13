/*
 * function: RefStringHash
 * address:  0x0219DF30
 * packet:   pkt_ov009_0219DF30
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

int RefStringHash(void *elem, int numbuckets)
{
    return StringHash(*(char **)elem, numbuckets);
}
