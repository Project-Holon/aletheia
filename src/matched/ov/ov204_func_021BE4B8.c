/*
 * function: func_021BE4B8
 * address: 0x021BE4B8
 * packet: pkt_ov204_021BE4B8
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF624 0x021BF624 thumb ov204
 *   func_021BF67C 0x021BF67C arm ov204
 *   func_021BF7CC 0x021BF7CC thumb ov204
 *   d_021BFFE4 0x021BFFE4 data a1
 */
#include "../include/Obj10874.h"
extern void func_021BF624(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i);
extern void func_021BF67C(char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int species, unsigned char i);
typedef unsigned char  u8;
extern void func_021BF7CC(u8 *p, u8 index, int flag);
extern const char d_021BFFE4[];
int func_021BE4B8(char *p, int unused, unsigned *q)
{
    if (q[1] == 0) {
        func_021BF624(((struct Obj10874 *)p)->f8, q[2], q[3], 0, (void *)d_021BFFE4, q[0]);
        func_021BF7CC(((struct Obj10874 *)p)->f8, q[0], 1);
    } else {
        func_021BF67C(((struct Obj10874 *)p)->f8, q[2], q[3], 0x1000, q[1], q[0]);
    }
    return 1;
}
