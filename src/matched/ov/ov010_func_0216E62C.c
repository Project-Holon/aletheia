/*
 * function: func_0216E62C
 * address:  0x0216E62C
 * packet:   pkt_ov010_0216E62C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017988  0x02017988  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   d_02172554  0x02172554  data  ov010  a2
 *   d_02172556  0x02172556  data  ov010  a2
 */

typedef unsigned short u16;

extern int func_0200CA1C(void);
extern int func_02017E1C(int a, int b, int c);
extern void func_02017988(int a, u16 v);
extern void func_0200CFA0(int a, int b);
extern u16 d_02172554[][2];
extern u16 d_02172556[][2];

void func_0216E62C(int unused, int p, u16 id)
{
    int h;
    int t;
    int i;

    h = func_0200CA1C();
    t = func_02017E1C(p, 5, 0);
    for (i = 0; i < 25; i++) {
        if (id == d_02172554[i][0]) {
            int v = d_02172556[i][0];
            if (t == 0x19c) {
                func_02017988(p, v);
                func_0200CFA0(h, p);
            }
            return;
        }
    }
}
