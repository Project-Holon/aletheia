/*
 * function: func_0218BA48
 * address:  0x0218BA48
 * packet:   pkt_ov021_0218BA48
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

void func_0218BA48(S *p, void *v)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (p->arr[i] == v) {
            p->arr[i] = 0;
            return;
        }
    }
}
