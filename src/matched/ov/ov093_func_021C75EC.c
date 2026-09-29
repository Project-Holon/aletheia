/*
 * function: func_021C75EC
 * address:  0x021C75EC
 * packet:   pkt_ov093_021C75EC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D5814(void *p, int k);
extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D75A8(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(u8 *p, int k);
extern int func_021D775C(int key);
extern void func_021D7540(int line);

int func_021C75EC(u8 *p, u8 *a, int k)
{
    int f = func_021D5814(a, k);
    u32 v = 0x1000;
    int x;
    int r;

    func_021D74F8(12664);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x51, f);
    func_021D70F0(p, 0x40);
    x = func_021D775C(0x51);
    if (x != 0)
        v = 0x1800;
    func_021D75EC(0x44, x);
    func_021D75A8(0x35, v);
    func_021D70F0(p, 0x41);
    r = func_021D775C(0x35);
    func_021D7540(12681);
    return r;
}
