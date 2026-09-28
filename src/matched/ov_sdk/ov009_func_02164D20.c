/*
 * function: CPSi_char_from_big
 * address:  0x02164D20
 * packet:   pkt_ov009_02164D20
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_char_from_big (biginteger.o)
 *
 * symbols:
 */

void CPSi_char_from_big(unsigned char *d, unsigned short *s, int numbytes)
{
    unsigned char *p;

    d += numbytes - 1;
    while (numbytes > 1) {
        p = d - 1;
        *d = (unsigned char)*s;
        d -= 2;
        *p = (unsigned char)(*s++ >> 8);
        numbytes -= 2;
    }
    if (numbytes > 0)
        *d = (unsigned char)*s;
}
