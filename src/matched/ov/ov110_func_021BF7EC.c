/*
 * function: PMS_INPUT_GetScrollRange
 * address: 0x021BF7EC
 * packet: pkt_ov110_021BF7EC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj13799.h"
typedef unsigned char u8;
typedef unsigned short u16;
void PMS_INPUT_GetScrollRange(const u8 *p,u16 *a,u16 *b) {
    *a=*(const u16 *)&((struct Obj13799 *)p)->f54;
    *b=*(const u16 *)&((struct Obj13799 *)p)->f56;
}
