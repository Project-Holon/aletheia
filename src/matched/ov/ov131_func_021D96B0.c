/*
 * function: func_021D96B0
 * address: 0x021D96B0
 * packet: pkt_ov131_021D96B0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021DC844 0x021DC844 data a1
 */
#include "../include/Obj02189.h"
#include "../include/Obj14075.h"
#include "../include/Obj23159.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char d_021DC844[];
u8 *func_021D96B0(u8 *a)
{
    u8 *p;
    u8 i;
    p=func_02030734(((struct Obj14075 *)a)->f0,296,0,d_021DC844,315);
    ((struct Obj02189 *)p)->f0=0;
    ((struct Obj02189 *)p)->f4=0;
    ((struct Obj02189 *)p)->f8=0;
    ((struct Obj02189 *)p)->f10=0;
    ((struct Obj02189 *)p)->f14=0;
    ((struct Obj02189 *)p)->f18=0;
    ((struct Obj02189 *)p)->f24=0;
    p[42]=5;
    p[41]=255;
    if ((*(u8 **)(a+8))[13]==2 && ((struct Obj23159 *)(*(u8 * *)&((struct Obj14075 *)a)->f8))->f14!=0) p[43]=5;
    else p[43]=4;
    for(i=0;i<5;i++) {
        p[0xb0+i*24]=255;
        *(u32 *)(p+0xb4+i*24)=0;
    }
    return p;
}
