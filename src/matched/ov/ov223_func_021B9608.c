/*
 * function: func_021B9608
 * address: 0x021B9608
 * region: ov223
 * isa: thumb
 * packet: pkt_ov223_021B9608
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204E6E0 0x0204E6E0 arm
 *   func_0204E6F4 0x0204E6F4 arm
 *   func_020355C4 0x020355C4 arm
 * 3159C's r0 return is consumed despite its legacy void declaration.
 * 3064C preserves all three visibly loaded original arguments.
 */
#include "../include/Obj03961.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern void func_0204E720(u32,int,int,int);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(void *,u32,u32);
extern void func_02082BCC(void *,u32,u32);
extern u32 func_0204E6E0(void);
extern void func_0204E6F4(int);
extern u8 func_020355C4(void);
int func_021B9608(void *a,int unused,void *c)
{
    char *p;
    func_0204E720(3,16,16,0);
    func_0203064C(1,135,1<<20);
    p=func_0203159C(a,2168,135);
    func_02082BCC(p,0,2168);
    ((struct Obj03961 *)p)->f0=135;
    ((struct Obj03961 *)p)->f4=c;
    ((struct Obj03961 *)p)->f874=func_0204E6E0();
    func_0204E6F4(1);
    ((struct Obj03961 *)p)->f8=func_020355C4();
    ((struct Obj03961 *)p)->f228=4;
    ((struct Obj03961 *)p)->f22C=4;
    ((struct Obj03961 *)p)->f230=0;
    ((struct Obj03961 *)p)->fC=0;
    return 1;
}
