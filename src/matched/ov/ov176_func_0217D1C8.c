/*
 * function: func_0217D1C8
 * address: 0x0217D1C8
 * packet: pkt_ov176_0217D1C8
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow.
 * symbols:
 *   func_021E5548 0x021E5548 thumb ov177
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   func_021E7520 0x021E7520 thumb ov177
 */
#include "../include/Obj02889.h"
typedef signed int     s32;
typedef unsigned int   u32;
struct Reg2;
extern int func_021E5548(int *p);
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);
extern int func_021E7520(int,int,int,int,int,int,int,int,int,int,unsigned short);
void func_0217D1C8(char *p, int value)
{
    int a;
    int b;
    if (((struct Obj02889 *)p)->f14 == 0) {
        a = func_021E5548((int *)(((struct Obj02889 *)p)->f1B4));
        b = REGULATION_Card_GetValue((struct Reg2 *)(((struct Obj02889 *)p)->f38), 11);
        ((struct Obj02889 *)p)->f14 = func_021E7520(value, a, ((struct Obj02889 *)p)->f1B0, ((struct Obj02889 *)p)->f1A8,
            ((struct Obj02889 *)p)->f1AC, ((struct Obj02889 *)p)->f24, ((struct Obj02889 *)p)->f2C, 1, 0, b, ((struct Obj02889 *)p)->f1C8);
    }
}
