/*
 * function: wcslen
 * address:  0x02096578
 * packet:   pkt_02095AA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned short u16;

int wcslen(const u16 *s)
{
    int n = -1;
    u16 c;

    do {
        c = *s++;
        n++;
    } while (c != 0);
    return n;
}
