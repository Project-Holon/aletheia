/*
 * unit: yes
 * function: func_021B98A8, func_021B98F0
 * address: 0x021B98A8
 * packet: pkt_ov100_021B98A8
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 74 compiled bytes include empty stub 021B98F0; padding then separate leaf 021B98F4.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GAME_DATA_GetPlayerStatus 0x02012950 thumb
 *   MYSTATUS_Copy 0x02008494 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200ED48 0x0200ED48 thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200ED54 0x0200ED54 thumb
 */
#include "../include/Obj13707.h"
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
struct Big;
struct L0200ED54;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
extern struct Rec44 *GAME_DATA_GetPlayerStatus(struct Sub24 *p, u32 i);
extern void MYSTATUS_Copy(void *src, void *dst);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200ED48(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
void func_021B98A8(int a,int b,int c,int d,int e)
{
 int p;
 int q;
 if(e==(int)GFL_NET_HANDLE_GetCurrentHandle()) {
  p=(int)GAME_DATA_GetPlayerStatus((struct Sub24 *)(**(int * *)&((struct Obj13707 *)d)->f244),a);
  MYSTATUS_Copy((void *)c,(void *)p);
  q=(int)func_0200ED48(GAME_DATA_GetSaveControl((struct Big *)(**(int * *)&((struct Obj13707 *)d)->f244)));
 func_0200ED54((struct L0200ED54 *)q,func_02008530((const struct Sub0200852CObj *)p));
 }
}
void func_021B98F0(void) {}
