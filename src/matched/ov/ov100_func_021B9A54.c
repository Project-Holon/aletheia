/*
 * function: func_021B9A54
 * address: 0x021B9A54
 * packet: pkt_ov100_021B9A54
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: one-word aggregate assignment schedules the stack address before its load/store.
 * symbols:
 *   func_021BA3A4 0x021BA3A4 thumb ov100
 *   func_021BA454 0x021BA454 thumb ov100
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9A1C 0x021B9A1C thumb ov100
 *   d_021BB664 0x021BB664 data a4
 *   d_021BB678 0x021BB678 data a4
 */
#include "../include/Obj00060.h"
struct Word { int x; };
extern const struct Word d_021BB664,d_021BB678;
extern void func_021BA3A4(struct Word *,int);
extern void func_021BA454(int,int);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned int,unsigned int);
typedef unsigned char  u8;
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021B9A1C(unsigned a);
void func_021B9A54(int a)
{
 if(((struct Obj00060 *)a)->fC90!=0) {
  struct Word x=d_021BB664;
  func_021BA3A4(&x,a);
 } else {
  struct Word x=d_021BB678;
  func_021BA3A4(&x,a);
 }
 func_021BA454(0x22,a);
 GFL_USE_PlaySeDefaultVolume(0x764);
 GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7f,12);
 func_021B95B8((u8 *)a,(u32)func_021B9A1C);
}
