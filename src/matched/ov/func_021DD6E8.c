/*
 * function: func_021DD6E8
 * address:  0x021DD6E8
 * packet:   pkt_021DD6E8
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020179B8  0x020179B8  thumb
 *   func_0201747C  0x0201747C  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_020307B0  0x020307B0  arm
 */
typedef unsigned int u32;

extern void func_020179B8(void *a, u32 b);
extern void *func_0201747C(void *a, u32 b);
extern u32 func_0200CA1C(u32 v);
extern void func_0200CFA0(u32 v, void *p);
extern void func_020307B0(void *p);

void func_021DD6E8(void **pp, void *a, u32 b)
{
    void *r;

    func_020179B8(a, b);
    r = func_0201747C(a, 0x4c);
    func_0200CFA0(func_0200CA1C(*(u32 *)*pp), r);
    func_020307B0(r);
}
