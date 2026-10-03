/*
 * function: func_021C5590
 * address: 0x021C5590
 * packet: pkt_ov127_021C5590
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021C3EE0 0x021C3EE0 thumb ov127
 *   func_021C3FDC 0x021C3FDC thumb ov127
 *   func_021C40A0 0x021C40A0 thumb ov127
 *   d_021C6130 0x021C6130 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { void *f0; void *f4; u16 count; u8 a,b; } Obj;
extern void *func_02030734(u16, u32, int, const char *, u16);
extern void *func_021C3EE0(void *, void *, u32, u32);
extern void func_021C3FDC(void *, void *, int, int, u32);
extern void func_021C40A0(u8 *p, int a, int b, int c);
extern const char d_021C6130[];
Obj *func_021C5590(void *p, void *q, u32 n, void *r, int s, u32 b, u32 heap)
{
    Obj *o = func_02030734(heap, 12, 1, d_021C6130, 161);
    o->f0 = func_021C3EE0(p, q, n, heap);
    o->count = n;
    o->f4 = func_02030734(heap, 20 * o->count, 1, d_021C6130, 168);
    o->a = 2;
    o->b = b;
    func_021C3FDC(o->f0, r, o->b, s, heap);
    func_021C40A0(o->f0, o->b, 255, heap);
    return o;
}
