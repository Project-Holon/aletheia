/*
 * function: func_021B84D0
 * address: 0x021B84D0
 * packet: pkt_ov106_021B84D0
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: count halfword re-read at 0x021B84D6 and 0x021B84F4.
 */
#include "../include/Obj22263.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
int func_021B84D0(u8 *p) {
    int i;
    int found;
    found=0;
    i=0;
    for (; i<*(volatile u16 *)&((struct Obj22263 *)p)->f554; i++) {
        if ((*(u8 **)(p+0x188+i*32))[13] != 0) {found=1; break;}
    }
    if(found) return (s16)(24*i);
    return -1;
}
