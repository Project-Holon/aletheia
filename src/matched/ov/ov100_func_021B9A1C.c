/*
 * function: func_021B9A1C
 * address: 0x021B9A1C
 * packet: pkt_ov100_021B9A1C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B99F4 0x021B99F4 thumb ov100
 */
#include "../include/Obj22074.h"
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
typedef unsigned char  u8;
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void func_021B95B8(unsigned char *,unsigned);
extern void func_021B99F4(unsigned a);
void func_021B9A1C(unsigned a)
{
 if(func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7f,12)!=0) {
  GFL_NET_SetAutoExit(0); GFL_NET_SetLoginOption(0);
  ((struct Obj22074 *)a)->fCAC=0;
  func_021B95B8((unsigned char *)a,(unsigned)func_021B99F4);
 }
}
