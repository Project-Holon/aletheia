/*
 * function: func_0218BACC
 * address:  0x0218BACC
 * packet:   pkt_ov021_0218BACC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    unsigned char pad[0x1DC];
    void *arr[7];
} S;

unsigned short func_0218BACC(S *p, void *v)
{
    int i;
    if (v == 0)
        return 0;
    for (i = 0; i < 7; i++) {
        if (p->arr[i] == v)
            return 0xFFF0 | i;
    }
    return 0;
}
