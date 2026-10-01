/*
 * function: func_021A8E10
 * address:  0x021A8E10
 * packet:   pkt_ov021_021A8E10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

typedef struct {
    int pad[2];
    int f8;
} T;

typedef struct {
    char pad[0xf8];
    T *pf8;
} S;

int func_021A8E10(S *s)
{
    T *p = s->pf8;
    if (p == 0) {
        return 0;
    }
    return p->f8;
}
