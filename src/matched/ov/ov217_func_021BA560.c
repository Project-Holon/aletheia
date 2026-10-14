/*
 * function: func_021BA560
 * address: 0x021BA560
 * packet: pkt_ov217_021BA560
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   RESEARCH_COMMON_GetPreviousScreen 0x021C09C8 thumb ov217
 *   RESEARCH_COMMON_GetEntryHandled 0x021C09CC thumb ov217
 *   func_021BA3B0 0x021BA3B0 thumb ov217
 *   func_021BA3B4 0x021BA3B4 thumb ov217
 */
#include "../include/Obj25827.h"
extern unsigned RESEARCH_COMMON_GetPreviousScreen(void *);
extern unsigned RESEARCH_COMMON_GetEntryHandled(void *);
extern void func_021BA3B0(void *,unsigned);
extern unsigned func_021BA3B4(unsigned,unsigned);
void func_021BA560(char *p)
{
    void *owner=((struct Obj25827 *)p)->f0;
    unsigned a=RESEARCH_COMMON_GetPreviousScreen(owner),b=RESEARCH_COMMON_GetEntryHandled(owner);
    if(a!=0 && b==0) {
        unsigned mode;
        switch(a) {case 2:default:mode=0;break;case 3:mode=1;break;}
        func_021BA3B0(p,mode);
    } else {
        if(func_021BA3B4((unsigned)p,0)!=0) func_021BA3B0(p,0);
        else func_021BA3B0(p,1);
    }
}
