/*
 * function: func_02159CC4
 * address:  0x02159CC4
 * packet:   pkt_ov010_02159CC4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159D84  0x02159D84  thumb  ov010
 *   func_02159DC8  0x02159DC8  thumb  ov010
 *   func_02159DCC  0x02159DCC  thumb  ov010
 *   func_02159C68  0x02159C68  thumb  ov010
 *   func_02159DEC  0x02159DEC  thumb  ov010
 */

typedef unsigned int u32;

extern void *func_02159D84(int, int);
extern int func_02159DC8(void *);
extern u32 func_02159DCC(void *, int);
extern void func_02159C68(void *, void *, int);
extern void func_02159DEC(void *);

void func_02159CC4(u32 *a, int b, int c)
{
    void *l = func_02159D84(c, b);
    int n = func_02159DC8(l);
    int i;
    for (i = 0; i < n; i++) {
        u32 t = func_02159DCC(l, i);
        if (t == a[1])
            func_02159C68(a, l, c);
    }
    func_02159DEC(l);
}
