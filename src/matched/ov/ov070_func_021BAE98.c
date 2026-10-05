/*
 * function: func_021BAE98
 * address:  0x021BAE98
 * packet:   pkt_ov070_021BAE98
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_021BAF38  0x021BAF38  thumb  ov070
 *   func_021BA96C  0x021BA96C  thumb  ov070
 */
#include "../include/Obj06178.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_021BAF38(int, int);
extern void func_021BA96C(int, unsigned);

void func_021BAE98(int p)
{
    ((struct Obj06178 *)p)->f504 = func_020450F0(2, 3, 0x15, 0xC, 3, 0xC, 1);
    ((struct Obj06178 *)p)->f75C = func_020450F0(2, 1, 0x15, 8, 3, 0xC, 1);
    ((struct Obj06178 *)p)->f764 = func_020450F0(2, 9, 0x15, 9, 3, 0xC, 1);
    func_021BAF38(p, ((struct Obj06178 *)p)->f80C);
    func_021BA96C(p, ((struct Obj06178 *)p)->f80C);
}
