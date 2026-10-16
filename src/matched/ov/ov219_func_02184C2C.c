/*
 * function: BEACON_DETAIL_CreateTaskMenuWin
 * address: 0x02184C2C
 * packet: pkt_ov219_02184C2C
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_WIN_Create 0x02027FEC thumb
 *   d_02185E40 0x02185E40 data ov219 a4
 */
#include "../include/Obj14776.h"
typedef unsigned char u8;typedef unsigned short u16;
struct Entry {unsigned x,y,z;};
extern const struct Entry d_02185E40[];
extern unsigned APP_TASKMENU_WIN_Create(unsigned,unsigned,unsigned,unsigned,u8,u16);
void BEACON_DETAIL_CreateTaskMenuWin(char *p,int i)
{
    if(*(unsigned *)(p+0xc05c+i*4)==0){
        *(unsigned *)(p+0xc05c+i*4)=APP_TASKMENU_WIN_Create(((struct Obj14776 *)p)->fC058,(unsigned)(p+0xc08c+i*12),(u8)d_02185E40[i].x,(u8)d_02185E40[i].y,(u8)d_02185E40[i].z,(u16)((struct Obj14776 *)p)->f0);
    }
}
