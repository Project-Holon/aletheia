/*
 * function: func_0202BA9C
 * address:  0x0202BA9C
 * packet:   pkt_0202BA9C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

static inline void set3(int *d, int x, int y, int z)
{
    d[0] = x;
    d[1] = y;
    d[2] = z;
}

void func_0202BA9C(char *p, const int *a, const int *b)
{
    set3((int *)(p + 0xC), a[0], a[1], a[2]);
    set3((int *)(p + 0x18), b[0], b[1], b[2]);
}
