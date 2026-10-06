/*
 * function: func_021FE8A8
 * address: 0x021FE8A8
 * packet: pkt_ov135_021FE8A8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FF318 0x021FF318 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 */
#include "../include/Obj14176.h"
extern void func_021FF318(unsigned char *p, unsigned int k, int b, int c, int d);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021F4E98(u8 *p, u32 a, u32 b);
int func_021FE8A8(char *p)
{
    if (++((struct Obj14176 *)p)->fDFC > 45) {
        func_021FF318((unsigned char *)p, 38, 1, 0, 0xf0f);
        func_021F4E98((u8 *)p, 23, 1);
        ((struct Obj14176 *)p)->fE1A = 1;
    }
    return 2;
}
