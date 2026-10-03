/*
 * function: func_021BC948
 * address:  0x021BC948
 * packet:   pkt_ov093_021BC948
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D7674  0x021D7674  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7B10  0x021D7B10  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021D7540  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D59B4(u8 *p, int k);
extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D75A8(int key, u32 val);
extern void func_021D7674(int key, u32 a, u32 b, u32 c);
extern void func_021D70F0(u8 *p, int k);
extern int func_021D775C(int key);
extern u32 func_021D7B10(u32 a, u32 b);
extern int func_021D62A8(u8 *t);
extern void func_021D7540(int line);

u16 func_021BC948(u8 *p, u8 *x, int flag)
{
    u32 r;
    int k = func_021D59B4(x, 0xc);
    int one;
    func_021D74F8(1760);
    func_021D75EC(2, func_021D5440(x));
    func_021D75EC(0x2f, k);
    one = 1;
    func_021D75A8(0x51, 1);
    func_021D75A8(0x4a, 0);
    func_021D7674(0x35, one << 12, 410, one << 17);
    func_021D70F0(p, 0x13);
    r = func_021D7B10(func_021D775C(0x2f), func_021D775C(0x35));
    if (func_021D62A8(x) == 1 && func_021D775C(0x51) != 0)
        r = r * 25 / 100;
    if (r > 10000)
        r = 10000;
    if (flag != 0 && func_021D775C(0x4a) != 0)
        r = 10000 - r;
    func_021D7540(1792);
    return r;
}
