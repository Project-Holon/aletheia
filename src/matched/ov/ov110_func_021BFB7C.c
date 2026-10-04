/*
 * function: func_021BFB7C
 * address: 0x021BFB7C
 * packet: pkt_ov110_021BFB7C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two trailing zero alignment bytes.
 * symbols:
 *   func_021BC868 0x021BC868 thumb ov110
 */
#include "../include/Obj22403.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BC868(u8 *p, int a, int b, int start, int end, int frames);
void func_021BFB7C(u8 *p) {
    ((struct Obj22403 *)p)->f88=0;
    func_021BC868(p+0x4c,4,63,124,0,12);
}
