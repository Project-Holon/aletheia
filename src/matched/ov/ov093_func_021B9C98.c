/*
 * function: func_021B9C98
 * address: 0x021B9C98
 * packet: pkt_ov093_021B9C98
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT* (2 bytes alignment padding)
 * volatile: count byte re-read at 0x021B9C98 and 0x021B9CAC
 */
#include "../include/Obj20992.h"
typedef unsigned char u8;
typedef unsigned int u32;
int func_021B9C98(u8 *p,u32 v) {
    int i;
    for(i=0;i<*(volatile u8 *)&((struct Obj20992 *)p)->f18;i++) {
        u32 t=*(u32 *)((u32)p+(u32)i*4);
        if(t==v) return i;
    }
    return -1;
}
