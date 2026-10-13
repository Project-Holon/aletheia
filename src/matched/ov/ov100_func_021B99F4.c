/*
 * function: func_021B99F4
 * address: 0x021B99F4
 * packet: pkt_ov100_021B99F4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_Exit 0x0203CEAC arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B99D4 0x021B99D4 thumb ov100
 */
#include "../include/Obj22073.h"
extern int GFL_NET_Exit(int);
extern void func_021B95B8(unsigned char *,unsigned);
extern void func_021B99D4(unsigned char *a);
void func_021B99F4(unsigned a)
{
 if(++((struct Obj22073 *)a)->fCAC>60) {
  GFL_NET_Exit(0);
  func_021B95B8((unsigned char *)a,(unsigned)func_021B99D4);
 }
}
