/*
 * function: func_02194300
 * address:  0x02194300
 * packet:   pkt_ov021_02194300
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021945A0  0x021945A0  thumb  ov021
 *   func_02194434  0x02194434  thumb  ov021
 */

typedef unsigned short u16;

extern int func_021945A0(int x);
extern void *func_02194434(void *a, int c, void *d, int e, int f, void *g);

void func_02194300(u16 *a, int b, int c, u16 *d, int e, int f)
{
    u16 i;
    unsigned char *q = *(unsigned char **)(a + 4);

    func_021945A0(*d);
    for (i = 0; i < *a; i++) {
        if (*(int *)(q + 8) == 0) {
            *(void **)(q + 8) = func_02194434(a, c, d, e, f, q);
            *(int *)q = b;
            *(u16 *)(q + 6) = a[1];
            return;
        }
        q += 0xc;
    }
}
