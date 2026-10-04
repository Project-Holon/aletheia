/*
 * unit: yes
 * function: func_0215EC2C, func_0215EC40
 * address: 0x0215EC2C
 * packet: pkt_ov010_0215EC2C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0215F104 0x0215F104 thumb ov010
 *   func_021C6078 0x021C6078 thumb ov021
 */
#include "../include/Obj12315.h"
extern int func_0215F104(void *, int);
typedef enum { B_FALSE, B_TRUE } Bool;
int func_0215EC2C(void *p)
{
    return func_0215F104(p, 8) != 0 ? B_FALSE : B_TRUE;
}
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_021C6078(void *, void *, u8);
void *func_0215EC40(u16 *a, void *b)
{
    return func_021C6078(((struct Obj12315 *)b)->f8, ((struct Obj12315 *)b)->f10, *a);
}
