/*
 * function: func_021F7EC0
 * address: 0x021F7EC0
 * packet: pkt_ov135_021F7EC0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021F8668 0x021F8668 thumb ov135
 */
#include "../include/Obj10576.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021F4D14(char *p);
extern void func_021F4CE4(char *p);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021F8668(u8 *dst, u8 *p);
int func_021F7EC0(u8 *p)
{
    int result;
    result = func_021F4D14((char *)p);
    if (result == 1) {
        func_021F4CE4((char *)p);
        func_021F4EC0(p, 7, 7);
        ((struct Obj10576 *)p)->f28 = 2;
        ((struct Obj10576 *)p)->fEB4 = 1;
        func_021F8668(p + 0xE4, p);
    } else if (result == 2) {
        func_021F4CE4((char *)p);
        func_021F4EC0(p, 5, 5);
        ((struct Obj10576 *)p)->f28 = 2;
    }
    return 2;
}
