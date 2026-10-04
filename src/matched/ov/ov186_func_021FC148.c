/*
 * function: func_021FC148
 * address: 0x021FC148
 * packet: pkt_ov186_021FC148
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049238 0x02049238 arm
 *   func_021FC31C 0x021FC31C thumb ov186
 *   func_021FC344 0x021FC344 thumb ov186
 *   func_021FC36C 0x021FC36C thumb ov186
 */
#include "../include/Obj01770.h"
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern unsigned func_0204AC18(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern void func_02049B68(void *,unsigned,unsigned,unsigned,unsigned,unsigned);
extern void func_02049238(void *);
extern unsigned short func_021FC31C(unsigned),func_021FC344(unsigned),func_021FC36C(unsigned);
void func_021FC148(char *p,unsigned i,unsigned heap)
{
    void *h;
    h=func_020490F4(0x89,heap);
    *(unsigned *)(p+i*4)=func_0204AC18(h,func_021FC31C(((struct Obj01770 *)p)->fF8),i,0,0,13,heap);
    if(i==0){
        func_02049B68(h,func_021FC344(((struct Obj01770 *)p)->fF8),0,0,0,heap);
        func_02049B68(h,func_021FC36C(((struct Obj01770 *)p)->fF8),0,0x1c0,0x20,heap);
    }else{
        func_02049B68(h,func_021FC344(((struct Obj01770 *)p)->fF8),4,0,0,heap);
        func_02049B68(h,func_021FC36C(((struct Obj01770 *)p)->fF8),4,0x1c0,0x20,heap);
    }
    func_02049238(h);
}
