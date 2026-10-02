/*
 * function: func_0216A390
 * address:  0x0216A390
 * packet:   pkt_ov010_0216A390
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017988  0x02017988  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0200CA1C(int a);
extern int func_0201AA18();
extern int func_0201AB28();
extern int func_02017E1C();
extern void func_02017988();
extern void func_0200CFA0();

void func_0216A390(int a0, int a1)
{
    int found;
    int n;
    int l4;
    int i;
    int e;
    int v;
    int w;

    l4 = func_0200CA1C(a0);
    found = 0;
    n = func_0201AA18(a1);
    for (i = 0; i < n; i++) {
        e = func_0201AB28(a1, i);
        v = func_02017E1C(e, 5, 0);
        w = func_02017E1C(e, 0x6f, 0);
        if (v == 0x1EC && w == 1) {
            func_02017988(e, 0);
            if (found == 0) {
                func_0200CFA0(l4, e);
                found = 1;
            }
        }
    }
}
