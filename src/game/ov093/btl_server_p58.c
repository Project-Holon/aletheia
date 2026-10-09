/*
 * function: func_021C43F0
 * address:  0x021C43F0
 * packet:   pkt_ov093_021C43F0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C443C  0x021C443C  thumb  ov093
 *   func_021BD2B4  0x021BD2B4  thumb  ov093
 *   func_021BD34C  0x021BD34C  thumb  ov093
 *   func_021C444C  0x021C444C  thumb  ov093
 *   func_021C445C  0x021C445C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021C443C(u8 *a);
extern void func_021BD2B4(u8 *it, u8 **q);
extern int func_021BD34C(u8 *it, u8 **q, u8 **x);
extern void func_021C444C(u8 *a, u8 *x);
extern void func_021C445C(u8 *a, u8 *p);

void func_021C43F0(u8 *p, u8 *a)
{
    u32 it;
    u8 *x;
    func_021C443C(a);
    func_021BD2B4((u8 *)&it, (u8 **)p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &x)) {
        func_021C444C(a, x);
    }
    func_021C445C(a, p);
}
