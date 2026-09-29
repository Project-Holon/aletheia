/*
 * function: func_021C6F34
 * address:  0x021C6F34
 * packet:   pkt_ov093_021C6F34
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
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_021C6FB0  0x021C6FB0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u8 val);
extern void func_021D70F0(u8 *p, int k);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern int func_021D5814(u8 *p, int k);
extern void func_021C6FB0(u8 *p, u8 *a);

int func_021C6F34(u8 *p, u8 *a, int f)
{
    int t;
    u8 x, y;
    if (f) {
        t = func_021D5814(a, 2);
    } else {
        t = 0;
    }
    func_021D74F8(12220);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x51, t);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x12);
    func_021C6FB0(p, a);
    x = func_021D775C(0x51);
    y = func_021D775C(0x41);
    func_021D7540(12228);
    if (y) return 0;
    return x;
}
