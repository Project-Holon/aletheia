/*
 * function: func_021B9824
 * address: 0x021B9824
 * packet: pkt_ov100_021B9824
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: alignment then separately filed follower func_021B9848.
 * symbols:
 *   func_02080D24 0x02080D24 arm
 */
#include "../include/Obj13706.h"
extern unsigned char func_02080D24(unsigned x);
void func_021B9824(int a,int b)
{
 if(func_02080D24(((struct Obj13706 *)a)->f2E8 |= 1 << b)>=2) ((struct Obj13706 *)a)->f2EC=1;
}
