/*
 * function: CAMERA_ResetCore
 * address:  0x02702080
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087A04  0x02087A04  arm twl a2
 */

typedef unsigned int u32;
typedef unsigned short u16;
#define reg_04004004 (*(volatile u16 *)0x04004004)
#define reg_04004200 (*(volatile u16 *)0x04004200)
extern void func_02087A04(u32);

void CAMERA_ResetCore(void) {
    reg_04004004 |= 4;
    reg_04004200 = 0;
    func_02087A04(0x1e);
    reg_04004004 |= 0x100;
    func_02087A04(0x1e);
    reg_04004200 = 0x22;
    func_02087A04(0x2008);
    reg_04004004 &= 0xfeff;
}
