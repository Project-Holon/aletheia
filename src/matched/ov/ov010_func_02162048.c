/*
 * function: func_02162048
 * address:  0x02162048
 * packet:   pkt_ov010_02162048
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216210C  0x0216210C  thumb
 *   func_02162298  0x02162298  thumb
 *   func_0216220C  0x0216220C  thumb
 *   d_0217144C     0x0217144C  data  ov010  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 x;
    u16 b;
    u16 t;
} S;

extern int func_0216210C(u16 *);
extern void func_02162298(u16 *, int, int);
extern void func_0216220C(u16 *, S *);
extern int d_0217144C[];

void func_02162048(u16 *a, int b, int c)
{
    S s;
    int t;

    if (func_0216210C(a) == 0) {
        func_02162298(a, b, c);
        return;
    }
    t = d_0217144C[c];
    if (t != 4) {
        s.x = *a;
        s.b = b;
        s.t = t;
        func_0216220C(a, &s);
    }
}
