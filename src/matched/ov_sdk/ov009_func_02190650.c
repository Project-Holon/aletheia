/*
 * function: func_02190650
 * address:  0x02190650
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Bump the +0x238 counter of the object at *a, run the three-stage request
 * with a local out-parameter, and stop at the first stage that reports an
 * error.  The third stage is skipped when the produced object's +8 word is
 * zero.  Returns 0 when every stage passes.
 */

extern int func_0218E114(void *a, int b, int c, void **pp, int d, int e, int f);
struct GPIOperation_s;
extern int func_021903B0(void **connection, struct GPIOperation_s *operation);
extern int func_02186E9C(void *a, int x);

int func_02190650(void *a, int a1, int a2, int a3, int a4)
{
    char *q;
    void *v;
    int r;

    q = *(char **)a;
    *(int *)(q + 0x238) += 1;

    r = func_0218E114(a, 3, a1, &v, a2, a3, a4);
    if (r != 0)
        return r;
    r = func_021903B0(a, v);
    if (r != 0)
        return r;

    if (*(int *)((char *)v + 8) != 0) {
        r = func_02186E9C(a, *(int *)((char *)v + 0x18));
        if (r != 0)
            return r;
    }
    return 0;
}
