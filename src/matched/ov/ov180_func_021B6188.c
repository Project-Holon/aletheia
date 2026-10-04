/*
 * function: func_021B6188
 * address: 0x021B6188
 * packet: pkt_ov180_021B6188
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj24481.h"
typedef unsigned char u8;
struct Node;
extern void func_02030EAC(struct Node *);
void func_021B6188(u8 *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj24481 *)p)->f4);
}
