/*
 * function: sakeSetGame
 * address:  0x021DD25C
 * packet:   pkt_021DD25C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   strcpy  0x02094798  arm
 *
 * Re-arm the object: clear both the +4 and +0x18 ranges, store the +0x14
 * count and set the live flag at +0.
 */

extern char *strcpy(char *dst, const char *src);

void sakeSetGame(char *p, int b, int c, int d)
{
    strcpy(p + 4, (const char *)b);
    strcpy(p + 0x18, (const char *)d);
    *(int *)(p + 0x14) = c;
    *(int *)p = 1;
}

