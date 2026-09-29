/*
 * function: func_021C4304
 * address:  0x021C4304
 * packet:   pkt_ov093_021C4304
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021C43C0  0x021C43C0  thumb  ov093
 *   func_021C43D0  0x021C43D0  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021C43E0  0x021C43E0  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021C88E4  0x021C88E4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern int func_021C43C0(u8 *c);
extern int func_021C43D0(u8 *c);
extern void func_021D7630(int key, u32 val);
extern u8 *func_021C43E0(u8 *c, u8 i);
extern void func_021D70F0(u8 *p, int k);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern int func_021C88E4(u8 *p);

int func_021C4304(u8 *p, u16 *b, u8 *a, u8 *c, int *out)
{
    u8 n1;
    u8 n2;
    u8 i;
    func_021D74F8(9370);
    func_021D75EC(3, func_021D5440(a));
    n1 = func_021C43C0(c);
    n2 = func_021C43D0(c);
    func_021D75EC(5, n2);
    func_021D7630(0x51, 1);
    for (i = 0; i < n2; i++) {
        func_021D75EC(i + 6, func_021D5440(func_021C43E0(c, i)));
    }
    func_021D75EC(0x12, *b);
    if (n1 != 0) {
        if (n2 != 0) {
            func_021D70F0(p, 0xa0);
        }
    } else {
        func_021D70F0(p, 0xa1);
    }
    *out = func_021D775C(0x51);
    func_021D7540(9402);
    if (func_021C88E4(p) != 0) {
        return 1;
    }
    return 0;
}
