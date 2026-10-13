/*
 * function: func_021D94C4
 * address: 0x021D94C4
 * packet: pkt_ov121_021D94C4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKEGRA_LoadCharDataPP 0x0202D6F4 thumb
 *   POKEGRA_ConvertCharTo2D 0x0202D214 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj13942.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 POKEGRA_LoadCharDataPP(void *a0, void *mon, u32 a2, u32 a3);
extern void POKEGRA_ConvertCharTo2D(void *,u16);
extern u32 func_020307B0(void *p);
unsigned func_021D94C4(int id,int heap)
{
    unsigned result=48;
    int found=0;
    int row,col,bit;
    void *object;
    void *allocation;
    u8 *table;
    heap=(heap&32767)|32768;
    allocation=(void *)POKEGRA_LoadCharDataPP(&object,(void *)id,(int)0,(u16)heap);
    POKEGRA_ConvertCharTo2D(object,heap);
    for(row=11;row>=0;row--) {
        for(col=0;col<12;col++) {
            unsigned *p=(unsigned *)(*(u8 * *)&((struct Obj13942 *)object)->f14+(row*12+col)*32);
            for(bit=7;bit>=0;bit--) {
                if(p[bit]) {
                    unsigned index=row*8+bit;
                    if(result<index) result=index;
                    found=1;
                }
            }
        }
        if(found) break;
    }
    func_020307B0(allocation);
    return result;
}
