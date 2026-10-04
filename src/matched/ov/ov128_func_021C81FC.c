/*
 * function: func_021C81FC
 * address: 0x021C81FC
 * packet: pkt_ov128_021C81FC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C85A4 0x021C85A4 thumb ov128
 *   func_021CA294 0x021CA294 thumb ov128
 *   func_020061E4 0x020061E4 thumb
 */
#include "../include/Obj00179.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int   u32;
extern void func_021C85A4(u8 *p, u8 *a, u8 *b, int x, int y, int n, u16 c);
extern void func_021CA294(u8 *, int);
extern void func_020061E4(u32 a);
void func_021C81FC(u8 *p, void *a, u8 *b, u16 c)
{
    int n = ((struct Obj00179 *)p)->f102 == 2 ? 2 : 1;
    func_021C85A4(p, a, b, ((struct Obj00179 *)p)->f0, ((struct Obj00179 *)p)->f4, n, c);
    func_021CA294(b, ((struct Obj00179 *)p)->f4);
    func_020061E4(0x548);
}
