/*
 * function: func_02163C9C
 * address:  0x02163C9C
 * packet:   pkt_ov010_02163C9C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D7E8  0x0216D7E8  thumb
 *   func_0216D660  0x0216D660  thumb
 *   func_0216D7F8  0x0216D7F8  thumb
 *   func_0216D66C  0x0216D66C  thumb
 */

typedef short s16;

extern int func_0216D7E8(void *p);
extern int func_0216D660(void *p);
extern int func_0216D7F8(void *p);
extern int func_0216D66C(void *p);

int func_02163C9C(int a, int b, int c)
{
    int base;
    int d;
    int hi;
    int lo;

    base = func_0216D7E8((void *)a);
    d = func_0216D660((void *)a);
    if (d != -1) {
        hi = (s16)(base + d);
        lo = (s16)(base - d);
        if (lo > b || hi < b)
            return 1;
    }
    base = func_0216D7F8((void *)a);
    d = func_0216D66C((void *)a);
    if (d != -1) {
        hi = (s16)(base + d);
        lo = (s16)(base - d);
        if (lo > c || hi < c)
            return 1;
    }
    return 0;
}
