/*
 * function: func_021B9D6C
 * address: 0x021B9D6C
 * packet: pkt_ov100_021B9D6C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9CC4 0x021B9CC4 thumb ov100
 */
#include "../include/Obj22079.h"
typedef unsigned short u16;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int MYSTATUS_GetSize(void);
typedef unsigned char  u8;
extern u8 *GAME_DATA_GetMyStatus(void *p);
typedef unsigned int   u32;
struct Entry;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021B9CC4(int a);
void func_021B9D6C(int a) {
 int p=(int)GFL_NET_HANDLE_GetCurrentHandle();
 int k=MYSTATUS_GetSize();
 int v=(int)GAME_DATA_GetMyStatus((void *)(**(int * *)&((struct Obj22079 *)a)->f244));
 if(GFL_NET_SendToHandle((void *)p,(u16)0xc01,(u16)k,v)!=0) {
  GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7b,12);
  func_021B95B8((u8 *)a,(u32)((void (*)(void))func_021B9CC4));
 }
}
