/*
 * function: func_0220C0B4
 * address: 0x0220C0B4
 * packet: pkt_ov197_0220C0B4
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * matching: arc declared before first/second fixes the three spill homes.
 *   0204ABF0 argument4 is u16: caller explicitly truncates i*32.
 *   0202F138 result widened to reproduce caller's explicit u16 narrowing;
 *   its own sub_0202F138 returns u16, which removed the observed shifts.
 * symbols:
 *   func_0202F138 0x0202F138 thumb
 *   func_02020F08 0x02020F08 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02020E60 0x02020E60 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_02020F0C 0x02020F0C thumb
 *   func_02020F10 0x02020F10 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj00315.h"
#include "../include/Obj25015.h"
#include "../include/Obj25016.h"
#include "../include/Obj25017.h"
#include "../include/Obj25018.h"
#include "../include/Obj25019.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 func_0202F138(u32 i);
extern unsigned func_02020F08(void),func_02020E60(unsigned,unsigned);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204A6C8(void *,unsigned,unsigned,unsigned,u16);
typedef signed int     s32;
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern int func_02020F0C(void),func_02020F10(void);
extern int func_0204AF28(void *,unsigned,unsigned,unsigned);
extern void func_02049238(void *);
void func_0220C0B4(char *p)
{
    u16 item,i;
    void *arc;
    unsigned first,second;
    int a;
    if(((struct Obj25015 *)(*(char * *)&((struct Obj00315 *)p)->f0))->f8==1) {item=(unsigned)func_0202F138(0);first=3;second=4;}
    else {first=1;item=1;second=2;}
    arc=func_020490F4(func_02020F08(),(u16)((((struct Obj25016 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC&0x7fff)|0x8000));
    for(i=0;i<7;i++) {
        *(int *)(p+i*4+0x544)=func_0204A6C8(arc,func_02020E60(item,first),0,1,((struct Obj25017 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
        *(int *)(p+i*4+0x568)=func_0204ABF0(arc,func_02020E60(item,second),1,(u16)(i*32),((struct Obj25018 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    }
    a=func_02020F0C();
    ((struct Obj00315 *)p)->f58C=func_0204AF28(arc,a,func_02020F10(),((struct Obj25019 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    func_02049238(arc);
}
