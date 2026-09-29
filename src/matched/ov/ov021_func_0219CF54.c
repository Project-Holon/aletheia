/*
 * function: func_0219CF54
 * address:  0x0219CF54
 * packet:   pkt_ov021_0219CF54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02046EFC  0x02046EFC  arm
 */

extern void func_02046EFC(void *);

int func_0219CF54(int *t, unsigned int id)
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
            *(unsigned short *)p = 0xFFFF;
            return 1;
        }
    }
    m = *(unsigned short *)((char *)t + 6);
    j = 0;
    q = (unsigned char *)t[4];
    for (; j < m; j++, q += 20) {
        if (*(int *)(q + 0x10) != 0 && *(unsigned short *)(q + 8) == id) {
            *q = 0;
            func_02046EFC(*(void **)(q + 0x10));
            *(int *)(q + 0x10) = 0;
            return 1;
        }
    }
    return 0;
}
