/*
 * unit: yes
 * function: func_021D6FF0,func_021D706C
 * address: 0x021D6FF0
 * packet: pkt_ov123_021D6FF0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: unit includes the 28-byte store-and-tail stub at 021D706C.
 * symbols:
 *   func_021B9774 0x021B9774 thumb ov114
 *   func_021D584C 0x021D584C thumb ov123
 *   func_021D5950 0x021D5950 thumb ov123
 *   func_021D5960 0x021D5960 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D6F70 0x021D6F70 thumb ov123
 *   func_021D6F04 0x021D6F04 thumb ov123
 */
#include "../include/Obj02182.h"
#include "../include/Obj22956.h"
#include "../include/Obj22957.h"
typedef unsigned char  u8;
extern void func_021B9774(u8 *p);
extern void func_021D584C(char *);
typedef unsigned int   u32;
extern int func_021D5950(u8 *p, int x);
extern void func_021D5960(char *,int,int);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D6F70(int a);
extern void func_021D6F04(char *);
void func_021D6FF0(char *p)
{
    int n=((struct Obj02182 *)p)->f80+29;
    if (((struct Obj02182 *)p)->f10) func_021B9774(((struct Obj02182 *)p)->f10);
    if (((struct Obj02182 *)p)->f80==0xfff0) n=39;
    else if (((struct Obj02182 *)p)->f80==0xfff1) n=40;
    else if (((struct Obj02182 *)p)->f80==0xfff2) n=41;
    else if (((struct Obj02182 *)p)->f80==0xfff3) n=38;
    else if (((struct Obj02182 *)p)->f80<=0 || ((struct Obj02182 *)p)->f80>=10) n=38;
    func_021D584C(*(char * *)&((struct Obj02182 *)p)->f18);
    func_021D5950((u8 *)(*(char * *)&((struct Obj02182 *)p)->f18),n);
    func_021D5960(*(char * *)&((struct Obj02182 *)p)->f18,1,16);
    func_021D6EE0((u8 *)p,(int)func_021D6F70,0x1b9);
}
void func_021D706C(char *p)
{
    ((struct Obj22957 *)(*(char * *)&((struct Obj22956 *)p)->f20))->f1C8=6;
    func_021D6EE0((u8 *)p,(int)func_021D6F04,0x1c9);
}
