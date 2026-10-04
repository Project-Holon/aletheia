/*
 * function: func_021C0140
 * address:  0x021C0140
 * packet:   pkt_ov021_021C0140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Links two sub-objects of the owner (EXACT*: 2 bytes of trailing padding).
 *
 * symbols:
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C7260  0x021C7260  thumb  ov021
 *   func_021C71D4  0x021C71D4  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned short u16;
typedef unsigned char  u8;
extern u32 func_02188D38(u8 *p);
extern void *func_021C7260(u32 a, u16 b, int c);
extern void *func_021C71D4(u32 a, u32 b, u32 c);
extern void func_021C6DE0(u8 *p, u32 a, u32 b);

void func_021C0140(u32 *p)
{
    u32 o = p[1];
    u32 r = func_02188D38((u8 *)o);
    u32 a = (u32)func_021C7260(o, 0x14, 3);
    u32 b = (u32)func_021C71D4(o, 0x14, 5);

    func_021C6DE0((u8 *)r, a, 0);
    func_021C6DE0((u8 *)r, b, a);
}
