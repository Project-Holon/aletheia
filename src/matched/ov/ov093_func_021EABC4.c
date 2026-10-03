/*
 * function: func_021EABC4
 * address:  0x021EABC4
 * packet:   pkt_ov093_021EABC4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9100  0x021E9100  thumb  ov093
 *   func_020457B0  0x020457B0  arm
 *   func_021EA55C  0x021EA55C  thumb  ov093
 *   func_021EAC44  0x021EAC44  thumb  ov093
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 *func_021E9100(void *p, u32 k);
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_021EA55C(u32 a, void *b);
extern void func_021EAC44(u32 a, void *b);
extern void func_020307B0(void *p);

void func_021EABC4(u8 *a, u32 x, u32 y, u32 z)
{
    u32 *t = func_021E9100(a, 12);

    t[0] = (u32)func_020457B0(0x20, (u16)((*(u16 *)(a + 0x184) & 0x7fff) | 0x8000));
    t[1] = (u32)func_020457B0(0x20, (u16)((*(u16 *)(a + 0x184) & 0x7fff) | 0x8000));
    t[2] = z;
    func_021EA55C(x, (void *)t[0]);
    func_021EA55C(y, (void *)t[1]);
    func_021EAC44(*(u32 *)(a + 0x180), t);
    func_020307B0((void *)t[0]);
    func_020307B0((void *)t[1]);
}
