/*
 * function: func_021D8B0C
 * address: 0x021D8B0C
 * packet: pkt_ov123_021D8B0C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D66D0 0x021D66D0 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8A9C 0x021D8A9C thumb ov123
 *   func_020307B0 0x020307B0 arm
 *   func_0203C9AC 0x0203C9AC arm
 *   func_0203C938 0x0203C938 arm
 */
#include "../include/Obj03272.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021D66D0(u8 *p, int n);
extern int func_02012DD0(u8 *p);
extern void func_020307B0(void *);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);
extern u32 func_0203C938(u8 mode);
extern void func_021D6EE0(char *,int,int);
extern void func_021D8A9C(char *p);
void func_021D8B0C(char *p)
{
    if (((struct Obj03272 *)p)->f70<100) ++((struct Obj03272 *)p)->f70;
    func_021D66D0(((struct Obj03272 *)p)->f14,((struct Obj03272 *)p)->f70);
    switch (func_02012DD0(((struct Obj03272 *)p)->f2C)) {
    case 1:
        if (((struct Obj03272 *)p)->f34) {
            func_020307B0(((struct Obj03272 *)p)->f34);
            ((struct Obj03272 *)p)->f34=0;
        }
        break;
    case 3:
        func_0203C9AC(0,0,0,0x3f3);
        func_0203C938(0);
        break;
    case 2:
        p[0xad]=0;
        func_021D6EE0(p,(int)func_021D8A9C,0x8e6);
        break;
    }
}
