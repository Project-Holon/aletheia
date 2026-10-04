/*
 * function: func_021BF784
 * address: 0x021BF784
 * packet: pkt_ov110_021BF784
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two trailing zero alignment bytes.
 * symbols:
 *   func_021BEDC4 0x021BEDC4 thumb ov110
 */
#include "../include/Obj22392.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021BEDC4(u8 *);
u32 func_021BF784(u8 *p) {
    if(((struct Obj22392 *)p)->f60!=0) return -1;
    return func_021BEDC4(p+0x54);
}
