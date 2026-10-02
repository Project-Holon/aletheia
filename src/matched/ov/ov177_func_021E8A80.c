/*
 * function: func_021E8A80
 * address:  0x021E8A80
 * packet:   pkt_ov177_021E8A80
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

typedef struct {
    void (*fn)(void *, int *, int);
    int a;
    int b;
} CB;

void func_021E8A80(CB *p)
{
    void (*fn)(void *, int *, int) = p->fn;

    if (fn != 0) {
        fn(p, &p->a, p->b);
    }
}
