/*
 * function: WIFI_BSUBWAY_GRAPHIC_DeleteBgAnim
 * address: 0x021D7FC4
 * packet: pkt_ov116_021D7FC4
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FB44 0x0203FB44 arm
 *   func_02030EAC 0x02030EAC arm
 */
#include "../include/Obj05322.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Node;
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02030EAC(struct Node *n);
void WIFI_BSUBWAY_GRAPHIC_DeleteBgAnim(u8 *p) {
    u32 x=((struct Obj05322 *)p)->f984;
    func_0203FB44(1,(u16)x,(u16)(x>>16));
    x=((struct Obj05322 *)p)->f988;
    func_0203FB44(2,(u16)x,(u16)(x>>16));
    if(((struct Obj05322 *)p)->fC) {
        func_02030EAC(((struct Obj05322 *)p)->fC);
        *(u32 *)&((struct Obj05322 *)p)->fC=0;
        ((struct Obj05322 *)p)->f10=0;
    }
    *(u16 *)0x04000050=0;
}
