/*
 * function: func_0220B954
 * address: 0x0220B954
 * packet: pkt_ov207_0220B954
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   overlay94 0x0000005E data
 *   func_02202058 0x02202058 thumb ov094
 */
#include "../include/Obj00174.h"
typedef unsigned short u16;
extern int func_02034AC4(int);
extern char overlay94[];
extern void *func_02021518(unsigned);
typedef unsigned int   u32;
struct Obj02021EE4;
struct PalAnmSlot;
extern void func_02021EE4(struct Obj02021EE4 *o, int v);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void *func_02202058(void *,int,void *,void *,void *,u16);
void func_0220B954(unsigned *p)
{
    func_02034AC4((int)overlay94);
    p[22]=(unsigned)func_02021518(((struct Obj00174 *)p)->f0);
    func_02021EE4((void *)p[22],1);
    func_0202155C((void *)p[22],1,480,((struct Obj00174 *)p)->f0);
    func_0202155C((void *)p[22],3,480,((struct Obj00174 *)p)->f0);
    p[21]=(unsigned)func_02202058((void *)p[8],0,(void *)p[22],(void *)p[6],p+20,((struct Obj00174 *)p)->f0);
    p[19]=0;
}
