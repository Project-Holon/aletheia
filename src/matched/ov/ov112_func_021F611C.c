/*
 * function: func_021F611C
 * address: 0x021F611C
 * packet: pkt_ov112_021F611C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021F63B8 0x021F63B8 thumb ov112
 *   d_021F83D4 0x021F83D4 data a4
 */
#include "../include/Obj10306.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_021F63B8(void *,int,u32,u32);
extern const char d_021F83D4[];
#define SLOT (*(char ***)(a+4))[i]
char *func_021F611C(char *a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g)
{
    int i;
    for(i=0;i<((struct Obj10306 *)a)->f0;i++) {
        if(SLOT==0) {
            SLOT=func_02030734((u16)((struct Obj10306 *)a)->f14,292,1,d_021F83D4,763);
            *(u32 *)(SLOT+240)=i;
            *(u32 *)(SLOT+244)=((struct Obj10306 *)a)->f14;
            *(u32 *)(SLOT+200)=b;
            *(u32 *)(SLOT+204)=c;
            *(u32 *)(SLOT+208)=d;
            *(u16 *)(SLOT+252)=0;
            *(u32 *)(SLOT+212)=4096;
            *(u32 *)(SLOT+216)=4096;
            *(u32 *)(SLOT+220)=4096;
            *(u32 *)(SLOT+248)=f;
            func_021F63B8(a,i,e,g);
            break;
        }
    }
    return SLOT;
}
