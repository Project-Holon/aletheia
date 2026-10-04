/*
 * function: func_021FB948
 * address: 0x021FB948
 * packet: pkt_ov132_021FB948
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_02030734 0x02030734 arm
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FBA14 0x021FBA14 thumb ov132
 *   d_021FDD00 0x021FDD00 data a4
 */
#include "../include/Obj03824.h"
#include "../include/Obj04518.h"
#include "../include/Obj08166.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201134C(void *);
extern int func_021FB1F4(char *,int);
extern void *func_021F9DA0(char *p);
extern void *func_021F9DA4(char *p, u32 i);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void *func_021FADA0(char *,u32,u32,u32);
extern void func_021FBA14(int,int *);
extern const char d_021FDD00[];
int func_021FB948(int unused,char *p)
{
    char *owner,*q;
    int mask;
    u32 rate,start,delta,wait;
    u8 i;
    owner=*(char * *)&((struct Obj04518 *)p)->f0;
    mask=func_021FB1F4(p,func_0201134C(((struct Obj04518 *)p)->f4));
    rate=func_0201134C(((struct Obj04518 *)p)->f4);
    start=func_0201134C(((struct Obj04518 *)p)->f4);
    delta=func_0201134C(((struct Obj04518 *)p)->f4);
    wait=func_0201134C(((struct Obj04518 *)p)->f4);
    func_021F9DA0(((struct Obj08166 *)owner)->f34);
    for(i=0;i<4;i++) {
        if(mask&(1<<i)) {
            q=func_02030734(((struct Obj08166 *)owner)->f0,36,0,d_021FDD00,0x493);
            *(char * *)&((struct Obj03824 *)q)->f1C=owner;
            ((struct Obj03824 *)q)->f18=func_021F9DA4(((struct Obj08166 *)owner)->f34,i);
            ((struct Obj03824 *)q)->f0=((struct Obj08166 *)owner)->f34;
            ((struct Obj03824 *)q)->f4=start;
            ((struct Obj03824 *)q)->f8=start+delta;
            ((struct Obj03824 *)q)->fC=rate;
            ((struct Obj03824 *)q)->fE=0;
            ((struct Obj03824 *)q)->f20=func_021FADA0(owner,(u32)func_021FBA14,(u32)q,10);
        }
    }
    if(wait==1) {((struct Obj04518 *)p)->f14=rate;return 1;}
    return 0;
}

