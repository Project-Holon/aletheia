/*
 * function: func_021B6B2C
 * address:  0x021B6B2C
 * packet:   pkt_ov067_021B6B2C
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     the heap id and a4/a5 are reloaded from their stack slots before
 *           every call because the callees take them as u16 (with u32 callee
 *           parameters they stay in registers: 300 bytes); `a3 = a3 - f()`
 *           (`-=` truncates the call result first).
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_021B6AE4  0x021B6AE4  thumb  ov067
 *   func_021B6C4C  0x021B6C4C  thumb  ov067
 *   func_02045808  0x02045808  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045C04  0x02045C04  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02045B38(u32 a, u32 b, u32 c, u16 d);
extern void *func_0201EC64(u16 heap);
extern void *func_020457B0(u32 size, u16 heap);
extern void *func_02045EC0(void *h, u32 idx);
extern u32 func_0201D304(void *a, u32 b, u32 c);
extern void func_021B6AE4(u32 p, u32 a, u16 b, u16 c, void *s0, u32 s1, u16 s2, u32 s3);
extern u32 func_021B6C4C(void *a, u32 b, u32 c);
extern void func_02045808(void *v);
extern void func_0201EFA4(void *obj, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_0201F250(void *obj, void *a, void *b);
extern void func_0201ED04(void *p);
extern void func_02045C04(void *p);

void func_021B6B2C(u32 a0, u32 a1, u32 a2, u16 a3, u16 a4, u16 a5, u32 a6, u32 a7, u16 heap)
{
    void *m;
    void *w;
    void *buf;
    void *s;
    u16 t;

    m = func_02045B38(0, 2, 0xa3, heap);
    w = func_0201EC64(heap);
    buf = func_020457B0(0xa, heap);
    s = func_02045EC0(m, 0);
    t = func_0201D304(s, a2, 0);
    func_021B6AE4(a0, a1, a3, a4, s, a2, a5, 2);
    a3 = a3 - func_021B6C4C(s, a2, 2);
    func_02045808(s);
    s = func_02045EC0(m, 1);
    func_0201EFA4(w, 0, a6, 8, 0, 1);
    func_0201F250(w, buf, s);
    func_021B6AE4(a0, a1, a3, a4, buf, a2, a5, 1);
    func_02045808(s);
    s = func_02045EC0(m, 2);
    func_0201EFA4(w, 0, a7, 8, 0, 1);
    func_0201F250(w, buf, s);
    func_021B6AE4(a0, a1, a3 + t, a4, buf, a2, a5, 0);
    func_02045808(s);
    func_02045808(buf);
    func_0201ED04(w);
    func_02045C04(m);
}
