/*
 * function: func_02183D1C
 * address:  0x02183D1C
 * packet:   pkt_02183D1C
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02183D40  0x02183D40  thumb  ov168
 */

typedef void (*fn_02183D1C)(int *, int *);

extern int func_02183D40(int *);

void func_02183D1C(int *p)
{
    if (func_02183D40(p) == 0)
        ((fn_02183D1C)(*(void **)((char *)p + 4)))(p, (int *)((char *)p + 8));
}
