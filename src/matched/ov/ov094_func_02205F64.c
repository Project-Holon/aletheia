/*
 * function: func_02205F64
 * address:  0x02205F64
 * packet:   pkt_ov094_02205F64
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct { void *h; } E;
typedef struct { char pad[0x1fc]; E a[4]; } W;
extern void func_0204B3B4(void *h);

void func_02205F64(W *p)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (p->a[i].h != 0) {
            func_0204B3B4(p->a[i].h);
            p->a[i].h = 0;
        }
    }
}
