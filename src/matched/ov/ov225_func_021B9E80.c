/*
 * function: func_021B9E80
 * address: 0x021B9E80
 * packet: pkt_ov225_021B9E80
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BC004 0x021BC004 data a1
 *   func_02030734 0x02030734 arm
 *   func_0204A39C 0x0204A39C arm
 *   func_020862F0 0x020862F0 arm
 *   func_0207EB78 0x0207EB78 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj04650.h"
typedef unsigned short u16;
extern const char d_021BC004[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void *func_0204A39C(void *,int,int,unsigned,unsigned *);
extern void func_020862F0(const void *,unsigned);
extern void func_0207EB78(const void *,unsigned,unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021B9E80(char *p,unsigned id)
{
    if(((struct Obj04650 *)p)->f30!=id) {
        unsigned size;
        void *buf;
        ((struct Obj04650 *)p)->f30=id;
        if(((struct Obj04650 *)p)->f30==0xffff) {
            buf=func_02030734(((struct Obj04650 *)p)->f4,0x18000,1,d_021BC004,245);
            size=0x18000;
        } else {
            buf=func_0204A39C(((struct Obj04650 *)p)->f28,((struct Obj04650 *)p)->f30,1,((struct Obj04650 *)p)->f4,&size);
        }
        func_020862F0(buf,size);func_0207EB78(buf,0,0x18000);func_020307B0(buf);
    }
}
