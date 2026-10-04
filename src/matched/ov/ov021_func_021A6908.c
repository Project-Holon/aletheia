/*
 * function: func_021A6908
 * address:  0x021A6908
 * packet:   pkt_ov021_021A6908
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_021A5B6C  0x021A5B6C  thumb  ov021
 *   func_021A6870  0x021A6870  thumb  ov021
 *   func_021A6708  0x021A6708  thumb  ov021
 *   func_021A6750  0x021A6750  thumb  ov021
 *   func_021A6768  0x021A6768  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_0216D608(void *o);
extern int func_021A5B6C(u8 *p, void *o, u32 v, u32 z);
extern void func_021A6870(u8 *p);
extern void func_021A6708(void *a);
extern void func_021A6750(void *a);
extern void func_021A6768(void *a);
extern void func_0216D5E0(int a0, int a1);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *o, u32 v);
extern void func_0216D548(u32 *p, u32 v);
extern void func_021A3964(u8 *o, u32 v);

u32 func_021A6908(u8 *p, u32 a1)
{
    void *o = *(void **)(p + 0x1C);
    u32 r6 = func_0216D608(o);

    if (func_021A5B6C(p, o, r6, 0)) {
        func_021A6870(p);
        return a1;
    }
    func_021A6708(p);
    func_021A6750(p);
    func_021A6768(p);
    func_0216D5E0((int)o, r6);
    func_0216D410(o, func_02197E7C(r6, 0x10));
    func_0216D548(o, 0x18);
    *(u32 *)p = 1;
    func_021A3964(*(u8 **)(p + 0x14), 1);
    return r6;
}
