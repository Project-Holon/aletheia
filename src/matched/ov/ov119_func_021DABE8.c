/*
 * function: func_021DABE8
 * address: 0x021DABE8
 * packet: pkt_ov119_021DABE8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DABB0 0x021DABB0 thumb ov119
 */
#include "../include/Obj22731.h"
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
typedef unsigned char  u8;
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void func_021D8E84(void *p, int v);
extern void func_021DABB0(char *);
void func_021DABE8(char *p) {
 if(func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),22,8)) {
  GFL_NET_SetAutoExit(1);
  GFL_NET_SetLoginOption(1);
  ((struct Obj22731 *)p)->fF2C=0;
  func_021D8E84(p,(int)func_021DABB0);
 }
}
