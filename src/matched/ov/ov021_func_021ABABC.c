/*
 * function: func_021ABABC
 * address:  0x021ABABC
 * packet:   pkt_ov021_021ABABC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AB760  0x021AB760  thumb
 *   func_0218E124  0x0218E124  thumb
 *   func_021ABBA0  0x021ABBA0  thumb
 *   FX_Div         0x0207C768  arm
 *   _ll_mul        0x0209C054  arm
 *   func_0218ED34  0x0218ED34  thumb
 *   func_0218ED48  0x0218ED48  thumb
 *   func_0218ED58  0x0218ED58  thumb
 */

typedef unsigned short u16;
typedef long long s64;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021AB760(u8 *p);
extern void func_0218E124(u8 *a, u32 s);
extern void func_021ABBA0(const u16 *r, void *v, int *o1, int *o2);
extern int FX_Div(int a, int b);
extern void func_0218ED34(u8 *p, u16 v);
extern void func_0218ED48(u8 *p, u16 v);
extern void func_0218ED58(u8 *p, u32 v);

/*
 * const on p lets the three loads from p schedule above the store of t to the
 * address-taken d (docs/idioms/a-const-parameter-hoists-field-loads-above-a-
 * call-result-store-into-an-address-taken-local.md). One reused temporary v
 * keeps the quotient on the left of each add and stops x and y being
 * forward-substituted into their calls; z, the last, is.
 */
void func_021ABABC(int a0, const u16 *p, void *q)
{
    int h = func_021AB760((u8 *)a0);
    int s;
    int d;
    int t;
    int x, y, z;
    int v;

    func_0218E124((u8 *)h, 0);
    func_021ABBA0(p, q, &s, &d);
    d = t = FX_Div(d, s);
    v = p[10] - p[6];
    v = v * t / 4096;
    x = v + p[6];
    v = p[11] - p[7];
    v = v * t / 4096;
    y = v + p[7];
    v = *(const int *)(p + 12) - *(const int *)(p + 8);
    v = (int)(((s64)v * t + 0x800) >> 12);
    z = v + *(const int *)(p + 8);
    func_0218ED34((u8 *)h, x);
    func_0218ED48((u8 *)h, y);
    func_0218ED58((u8 *)h, z);
}
