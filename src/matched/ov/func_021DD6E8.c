/*
 * function: func_021DD6E8
 * address:  0x021DD6E8
 * packet:   pkt_021DD6E8
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020179B8  0x020179B8  thumb
 *   func_0201747C  0x0201747C  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_020307B0  0x020307B0  arm
 */
typedef unsigned int u32;

struct Blk37;
extern int func_020179B8(int a0, int a1);
struct Mon;
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void *func_0200CA1C(void *a);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void func_020307B0(void *p);

void func_021DD6E8(void **pp, void *a, u32 b)
{
    void *r;

    func_020179B8((int)a, b);
    r = func_0201747C(a, 0x4c);
    func_0200CFA0(func_0200CA1C((void *)(*(u32 *)*pp)), r);
    func_020307B0(r);
}
