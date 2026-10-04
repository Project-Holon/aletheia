/*
 * function: func_021BEFF8
 * address: 0x021BEFF8
 * packet: pkt_ov217_021BEFF8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pool 021BF088 is 021C3AC8; dropping contested ov217 data hint resolves sole-ref evidence.
 * symbols:
 *   d_021C3AC8 0x021C3AC8 data a4
 *   func_021C0900 0x021C0900 thumb ov217
 */
#include "../include/Obj05561.h"
typedef unsigned char u8;
struct Row { u8 x,y,w,h; int fields[8]; };
extern const struct Row d_021C3AC8[];
extern unsigned func_021C0900(int);
void func_021BEFF8(u8 *p)
{
    const struct Row *row;
    u8 *q;
    row=&d_021C3AC8[((struct Obj05561 *)p)->f34];
    q=p+0x2fe;
    q[2]=func_021C0900(row->fields[0]+row->fields[4]-16);
    p[0x2fe]=func_021C0900(row->fields[1]+row->fields[5]-16);
    q[3]=func_021C0900(q[2]+32);
    q[1]=func_021C0900(p[0x2fe]+32);
    row=&d_021C3AC8[((struct Obj05561 *)p)->f34];
    q=p+0x302;
    q[2]=func_021C0900(row->fields[0]+row->fields[6]-16);
    p[0x302]=func_021C0900(row->fields[1]+row->fields[7]-16);
    q[3]=func_021C0900(q[2]+32);
    q[1]=func_021C0900(p[0x302]+32);
}
