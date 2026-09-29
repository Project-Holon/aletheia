/*
 * function: func_0217D160
 * address:  0x0217D160
 * packet:   pkt_ov018_0217D160
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   func_02082A48  0x02082A48  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02037190  0x02037190  arm
 *   func_0217DE44  0x0217DE44  thumb  ov018
 *   func_0217DA90  0x0217DA90  thumb  ov018
 *   func_0217DA18  0x0217DA18  thumb  ov018
 *   func_0217D904  0x0217D904  thumb  ov018
 *   func_0217D870  0x0217D870  thumb  ov018
 *   func_0217D6C8  0x0217D6C8  thumb  ov018
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02030EAC();
extern void func_02082A48();
extern void func_020307B0();
extern void func_02037190();
extern void func_0217DE44();
extern void func_0217DA90();
extern void func_0217DA18();
extern void func_0217D904();
extern void func_0217D870();
extern void func_0217D6C8();

void func_0217D160(int a0)
{
    func_02030EAC(*(int *)(a0 + 0x34));
    func_02082A48(0, 0x05000400, 2);
    func_0217DE44(a0);
    func_0217DA90(a0);
    func_0217DA18(a0);
    func_0217D904(a0);
    func_0217D870(a0);
    func_0217D6C8(a0);
    func_020307B0(a0);
    func_02037190();
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    *(volatile u16 *)0x04001050 = 0;
}
