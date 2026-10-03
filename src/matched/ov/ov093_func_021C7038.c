/*
 * function: func_021C7038
 * address:  0x021C7038
 * packet:   pkt_ov093_021C7038
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021C70D4  0x021C70D4  thumb  ov093
 *   func_021D794C  0x021D794C  thumb  ov093
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
extern void func_021C70D4(u8 *p, u8 *b);
extern int func_021D794C(int a, int b);

int func_021C7038(u8 *p, u8 *a, u8 *b, u32 q, u8 s)
{
    int x, y, r;
    func_021D74F8(12290);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x15, s);
    func_021D75EC(0x16, q);
    func_021D7630(0x4b, 0);
    func_021D7630(0x4c, 0);
    func_021C70D4(p, b);
    func_021D70F0(p, 0x3e);
    x = func_021D775C(0x4b);
    y = func_021D775C(0x4c);
    func_021D7540(12303);
    if (y) return 3;
    r = func_021D794C(q, s);
    if (r == 0 && x) r = 3;
    return r;
}
