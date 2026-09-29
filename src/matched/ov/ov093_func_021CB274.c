/*
 * function: func_021CB274
 * address:  0x021CB274
 * packet:   pkt_ov093_021CB274
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(u8 *p, int k);
extern int func_021D775C(int key);
extern void func_021D7540(int line);

u8 func_021CB274(u8 *p, u8 *a, u8 *b, u32 d)
{
    u8 r;
    func_021D74F8(656);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x16, b[6]);
    func_021D75EC(0x12, *(u16 *)b);
    func_021D7630(4, d);
    func_021D70F0(p, 0x2a);
    r = func_021D775C(4);
    func_021D7540(663);
    if (r == d) r = 0x1f;
    return r;
}
