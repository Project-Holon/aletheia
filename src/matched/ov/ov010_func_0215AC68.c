/*
 * function: func_0215AC68
 * address:  0x0215AC68
 * packet:   pkt_ov010_0215AC68
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C248  0x0200C248  thumb
 *   func_0203F4E4  0x0203F4E4  arm
 *   func_02012F5C  0x02012F5C  thumb
 *   func_02008A7C  0x02008A7C  thumb
 */

typedef struct {
    int a;
    int b;
    int c;
    int d;
} V4;

extern int func_02159B10(int);
extern int func_0215A5E4(int);
extern int func_02012F08(void);
extern void func_0200C248(int, int);
extern void func_0203F4E4(V4 *);
extern int func_02012F5C(int);
extern void func_02008A7C(int, int, int, int, int);

int func_0215AC68(int a, int b)
{
    V4 v;
    int r4 = func_02159B10(a);
    int r5 = func_0215A5E4(b);

    func_0200C248(func_02012F08(), r4);
    func_0203F4E4(&v);
    func_02008A7C(func_02012F5C(r5), r4, v.a, v.b, v.c);
    return 0;
}
