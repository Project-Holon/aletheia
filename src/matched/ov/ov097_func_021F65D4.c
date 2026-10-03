/*
 * function: func_021F65D4
 * address:  0x021F65D4
 * packet:   pkt_ov097_021F65D4
 * region:   ov097
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_020434DC  0x020434DC  arm
 *   func_021F6A28  0x021F6A28  thumb  ov097
 *   func_021F682C  0x021F682C  thumb  ov097
 *   func_021F683C  0x021F683C  thumb  ov097
 *   func_021F68FC  0x021F68FC  thumb  ov097
 *   func_021F6970  0x021F6970  thumb  ov097
 *   func_021F6A98  0x021F6A98  thumb  ov097
 *   func_021F6F24  0x021F6F24  thumb  ov097
 *   func_021F734C  0x021F734C  thumb  ov097
 *   func_021F69E4  0x021F69E4  thumb  ov097
 *   func_021F681C  0x021F681C  thumb  ov097
 *   func_021F67C8  0x021F67C8  thumb  ov097
 */

typedef unsigned short u16;

typedef unsigned int   u32;
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0204363C(u32 swap);
extern void func_0203D34C(u32 a, u32 b);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_021F6A28(int);
extern void func_021F682C(void);
extern void func_021F683C(void);
extern void func_021F68FC(int);
extern void func_021F6970(int);
extern void func_021F6A98(int);
extern void func_021F6F24(int);
extern void func_021F734C(int);
extern void func_021F69E4(int);
extern int func_021F681C(int, int, int);
extern void func_021F67C8(int, int);

void func_021F65D4(int a)
{
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_0204363C(1);
    func_021F6A28(a);
    func_021F682C();
    func_021F683C();
    func_021F68FC(a);
    func_021F6970(a);
    func_021F6A98(a);
    func_021F6F24(a);
    func_021F734C(a);
    func_0203D34C(1, 0x71);
    func_020434DC(0x17, 1);
    func_021F69E4(a);
    func_021F67C8(a, func_021F681C(a, 0x80, 4));
}
