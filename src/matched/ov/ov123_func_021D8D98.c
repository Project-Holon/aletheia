/*
 * function: func_021D8D98
 * address: 0x021D8D98
 * packet: pkt_ov123_021D8D98
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D65F4 0x021D65F4 thumb ov123
 *   func_021D57B8 0x021D57B8 thumb ov123
 *   func_021D5A7C 0x021D5A7C thumb ov123
 *   func_021D6650 0x021D6650 thumb ov123
 *   func_021D62BC 0x021D62BC thumb ov123
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8D08 0x021D8D08 thumb ov123
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj03798.h"
extern void func_021D65F4(unsigned char *p);
extern void func_021D57B8(char *,int);
extern void func_021D5A7C(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021D6650(u8 *p, int flag);
extern void func_021D62BC(u8 *p, int i, u32 v);
extern void func_021D62B4(u8 *p, unsigned int i);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D8D08(char *p);
void func_021D8D98(char *p)
{
    if (--((struct Obj03798 *)p)->f60==0) {
        func_021D65F4((unsigned char *)(*(char * *)&((struct Obj03798 *)p)->f14));
        func_021D57B8(*(char * *)&((struct Obj03798 *)p)->f18,8);
        func_021D5A7C(*(char * *)&((struct Obj03798 *)p)->f18);
        func_021D6650(((struct Obj03798 *)p)->f14,1);
        func_021D62BC(((struct Obj03798 *)p)->f14,4,5);
        func_021D62BC(((struct Obj03798 *)p)->f14,0,0);
        func_021D62B4(((struct Obj03798 *)p)->f14,12);
        GFL_USE_PlaySeDefaultVolume(0x657);
        func_021D6EE0((u8 *)p,(int)func_021D8D08,0x9a8);
    }
}
