/*
 * function: func_021BFED0
 * address: 0x021BFED0
 * packet: pkt_ov110_021BFED0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding follow the return.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043AF4 0x02043AF4 arm
 */
#include "../include/Obj06392.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
typedef unsigned int   u32;
struct Bmp;
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
void func_021BFED0(u8 *p,int amount) {
    int start,end;
    if(amount>0) {
        start=(u8)(((struct Obj06392 *)p)->f94+192);
        end=(u8)(start+24*amount);
    } else {
        end=((struct Obj06392 *)p)->f94;
        start=(u8)(end+24*amount);
    }
    if(start<end) {
        func_02043AF4(func_02045770((struct Descriptor *)((struct Obj06392 *)p)->fC),(s16)0,(s16)start,(u16)208,(u16)(end-start),(u8)0);
    } else {
        func_02043AF4(func_02045770((struct Descriptor *)((struct Obj06392 *)p)->fC),(s16)0,(s16)start,(u16)208,(u16)(256-start),(u8)0);
        func_02043AF4(func_02045770((struct Descriptor *)((struct Obj06392 *)p)->fC),(s16)0,(s16)0,(u16)208,(u16)end,(u8)0);
    }
}
