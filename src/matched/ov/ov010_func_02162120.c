/*
 * function: func_02162120
 * address:  0x02162120
 * packet:   pkt_ov010_02162120
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216230C  0x0216230C  thumb
 *   func_02162254  0x02162254  thumb
 *   func_02162278  0x02162278  thumb
 *   d_02172990     0x02172990  data  ov010  a4
 */

typedef unsigned short u16;

typedef int (*Fn)(int, int, u16 *, u16 *);

extern void func_0216230C(int, u16);
extern int func_02162254(int, u16, u16 *);
extern void func_02162278(int, u16, u16, u16);
extern Fn d_02172990[];

void func_02162120(int a, int b, int c)
{
    u16 t[4];
    u16 s[4];
    int i;
    int r;

    for (i = 0; i < 3; i++) {
        if ((c & (1 << i)) == 0) {
            func_0216230C(a, i);
        } else if (func_02162254(a, i, s) != 0) {
            r = d_02172990[s[3]](a, b, s, t);
            func_0216230C(a, i);
            if (r != 0)
                func_02162278(a, i, t[2], t[3]);
        }
    }
}
