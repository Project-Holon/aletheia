/*
 * function: func_021BF580
 * address: 0x021BF580
 * packet: pkt_ov204_021BF580
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 */
#include "../include/Obj01292.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202F038(u8 *);
void func_021BF580(u8 *p)
{
    if(*(u8 * *)&((struct Obj01292 *)p)->f44!=0){func_0202F038(*(u8 * *)&((struct Obj01292 *)p)->f44);*(u8 * *)&((struct Obj01292 *)p)->f44=0;}
}
