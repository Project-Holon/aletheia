/*
 * function: func_0219CF00
 * address:  0x0219CF00
 * packet:   pkt_ov021_0219CF00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int func_0219CF00(int *t, unsigned int id, unsigned short *out)
{
    unsigned int i;
    unsigned char *p;
    unsigned int n;
    unsigned int j;
    unsigned char *q;
    unsigned int m;

    t = (int *)t[7];
    i = 0;
    n = *(unsigned short *)((char *)t + 4);
    p = (unsigned char *)t[3];
    for (; i < n; i++, p += 12) {
        if (*(unsigned short *)p == id) {
            *out = *(int *)(p + 8);
            return 1;
        }
    }
    m = *(unsigned short *)((char *)t + 6);
    j = 0;
    q = (unsigned char *)t[4];
    for (; j < m; j++, q += 20) {
        if (*(unsigned short *)(q + 8) == id && *(int *)(q + 0x10) != 0) {
            *out = *(int *)(q + 4);
            return 1;
        }
    }
    return 0;
}
