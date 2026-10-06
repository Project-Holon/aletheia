/*
 * function: func_021D6E08
 * address: 0x021D6E08
 * packet: pkt_ov123_021D6E08
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 */
#include "../include/Obj00063.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D6FF0(char *);
int func_021D6E08(char *p,int x)
{
    switch (x) {
    case 503:
        ((struct Obj00063 *)p)->f80=0xfff1;
        func_021D6EE0((u8 *)p,(int)func_021D6FF0,0xd3);
        return 1;
    case 502:
        ((struct Obj00063 *)p)->f80=0xfff2;
        func_021D6EE0((u8 *)p,(int)func_021D6FF0,0xd7);
        return 1;
    }
    if (x>=400) {
        ((struct Obj00063 *)p)->f80=0xfff3;
        func_021D6EE0((u8 *)p,(int)func_021D6FF0,0xdd);
        return 1;
    }
    return 0;
}
