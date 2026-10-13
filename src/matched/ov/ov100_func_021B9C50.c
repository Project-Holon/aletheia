/*
 * function: func_021B9C50
 * address: 0x021B9C50
 * packet: pkt_ov100_021B9C50
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: switch cases preserve three equality compares; disjunction folds to a range test.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   func_02087C6C 0x02087C6C arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B96B8 0x021B96B8 thumb ov100
 *   func_021B9BE4 0x021B9BE4 thumb ov100
 */
#include "../include/Obj22077.h"
typedef unsigned short u16;
typedef unsigned char u8;
struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern void func_02087C6C(void *);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021B96B8(u8 *a);
extern void func_021B9BE4(int a);
void func_021B9C50(int a)
{
 u8 x[6];
 int k=12;
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x79,k)!=0) {
  int t=((struct Obj22077 *)a)->f24C;
  switch(t) {
  case 9: case 10: case 11:
   func_021B95B8((u8 *)a,(u32)func_021B96B8);
   return;
  default: break;
  }
  func_02087C6C(x);
  if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc04,6,(u32)x)!=0) {
   GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7d,k);
   func_021B95B8((u8 *)a,(u32)func_021B9BE4);
  }
 }
}
