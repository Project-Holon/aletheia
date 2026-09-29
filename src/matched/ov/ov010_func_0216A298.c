/*
 * function: func_0216A298
 * address:  0x0216A298
 * packet:   pkt_ov010_0216A298
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017988  0x02017988  thumb
 */

typedef unsigned int u32;

extern int func_0201AA18(void *list);
extern void *func_0201AB28(void *list, int idx);
extern int func_02017E1C(void *e, int k, int i);
extern void func_02017988(void *e, int i);

void func_0216A298(void *a, void *list)
{
    int i;
    int n;
    void *e;
    int x;
    int y;

    n = func_0201AA18(list);
    for (i = 0; i < n; i++) {
        e = func_0201AB28(list, i);
        x = func_02017E1C(e, 5, 0);
        y = func_02017E1C(e, 0x6f, 0);
        if (x == 0x1ec && y == 1)
            func_02017988(e, 0);
    }
}
