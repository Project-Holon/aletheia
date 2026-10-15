/*
 * function: gpiStatusInfoKeyCompFunc
 * address:  0x0218D864
 * packet:   pkt_ov009_0218D864
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   strcmp                0x020948E0  arm
*/

extern int strcmp(const char *s1, const char *s2);

int gpiStatusInfoKeyCompFunc(char **elem1, char **elem2)
{
    return strcmp(*elem1, *elem2);
}
