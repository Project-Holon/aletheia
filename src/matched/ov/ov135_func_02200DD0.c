/*
 * function: func_02200DD0
 * address: 0x02200DD0
 * packet: pkt_ov135_02200DD0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049B40 0x02049B40 arm
 *   func_02040588 0x02040588 arm
 *   func_02043598 0x02043598 arm
 *   func_02200AB4 0x02200AB4 thumb ov135
 *   func_02200B34 0x02200B34 thumb ov135
 */
#include "../include/Obj00137.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02043598(u32, u32);
extern void func_02200AB4(u8 *);
extern void func_02200B34(u8 *);
void func_02200DD0(u8 *p)
{
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(0, 1, 0xe, 0, 0x48);
    func_0201F5BC(0, 0x1f, 0xb, 0, 0x48);
    if (((struct Obj00137 *)p)->fE18 == 0) {
        func_02040588(4, 0);
        func_02040588(5, 0);
        func_02043598(0x10, 0);
    }
    if (((struct Obj00137 *)p)->f1C == 9) {
        func_02200AB4(p);
        func_02200B34(p);
    }
}
