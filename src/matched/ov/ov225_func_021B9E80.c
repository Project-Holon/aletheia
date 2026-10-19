/*
 * function: MANUAL_COMMON_SetScreenId
 * address: 0x021B9E80
 * packet: pkt_ov225_021B9E80
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gManualCommonDataAllocFile 0x021BC004 data a1
 *   func_02030734 0x02030734 arm
 *   ARC_UTIL_LoadHandleMemberWithSize 0x0204A39C arm
 *   DC_FlushRange 0x020862F0 arm
 *   GX_LoadBG2Scr 0x0207EB78 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj04650.h"
typedef unsigned short u16;
extern const char gManualCommonDataAllocFile[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void *ARC_UTIL_LoadHandleMemberWithSize(void *,int,int,unsigned,unsigned *);
extern void DC_FlushRange(const void *,unsigned);
extern void GX_LoadBG2Scr(const void *,unsigned,unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void MANUAL_COMMON_SetScreenId(char *p,unsigned id)
{
    if(((struct Obj04650 *)p)->f30!=id) {
        unsigned size;
        void *buf;
        ((struct Obj04650 *)p)->f30=id;
        if(((struct Obj04650 *)p)->f30==0xffff) {
            buf=func_02030734(((struct Obj04650 *)p)->f4,0x18000,1,gManualCommonDataAllocFile,245);
            size=0x18000;
        } else {
            buf=ARC_UTIL_LoadHandleMemberWithSize(((struct Obj04650 *)p)->f28,((struct Obj04650 *)p)->f30,1,((struct Obj04650 *)p)->f4,&size);
        }
        DC_FlushRange(buf,size);GX_LoadBG2Scr(buf,0,0x18000);func_020307B0(buf);
    }
}
