/*
 * function: func_021BF1C4
 * address: 0x021BF1C4
 * packet: pkt_ov110_021BF1C4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD808 0x021BD808 thumb ov110
 *   func_020362DC 0x020362DC arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021BEE60 0x021BEE60 thumb ov110
 *   func_021BF0C0 0x021BF0C0 thumb ov110
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BD808(u8 *,void *);
extern u32 func_020362DC(void);
extern void func_020061E4(u32 a);
extern void func_021BEE60(u8 *p, u32 *q);
extern void func_021BF0C0(u8 *p, u32 *q);
void func_021BF1C4(u8 *p,void *q) {
    if(func_021BD808(p,q) && *(u32 *)&((struct Obj00012 *)p)->f70==0 && !(func_020362DC()&2)) { func_020061E4(1352); return; }
    if(*(u32 *)&((struct Obj00012 *)p)->f70==0) func_021BEE60(p,q);
    else func_021BF0C0(p,q);
}
