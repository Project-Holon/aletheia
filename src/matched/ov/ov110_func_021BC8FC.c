/*
 * function: func_021BC8FC
 * address: 0x021BC8FC
 * packet: pkt_ov110_021BC8FC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: difference of stored fixed-point fields prevents shift factoring.
 * symbols:
 *   func_0207D658 0x0207D658 arm
 *   func_021BC964 0x021BC964 thumb ov110
 *   func_021B9BA4 0x021B9BA4 thumb ov110
 */
#include "../include/Obj03241.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_021BC964(void *, u8 *);
extern void *func_021B9BA4(void (*fn)(void *, u8 *), u8 *p, int n);
void func_021BC8FC(u8 *p,int a,int start,int end,int n)
{
    func_0207D658(0x4000050,a,start);
    ((struct Obj03241 *)p)->f0=a;
    ((struct Obj03241 *)p)->f14=n;
    ((struct Obj03241 *)p)->f8=start<<12;
    ((struct Obj03241 *)p)->fC=end<<12;
    ((struct Obj03241 *)p)->f10=(((struct Obj03241 *)p)->fC-((struct Obj03241 *)p)->f8)/n;
    ((struct Obj03241 *)p)->f18=0;
    ((struct Obj03241 *)p)->f1C=func_021B9BA4(func_021BC964,p,0);
}
