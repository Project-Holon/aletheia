/*
 * function: func_021B9CC4
 * address: 0x021B9CC4
 * packet: pkt_ov100_021B9CC4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   func_02009CA8 0x02009CA8 thumb
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9C50 0x021B9C50 thumb ov100
 */
#include "../include/Obj03738.h"
typedef unsigned short u16;
typedef unsigned char u8;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
typedef unsigned int   u32;
struct BigObj;
struct TaskMenu;
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern void func_02009CA8(void *account, void *out);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
struct Link;
extern void func_02039C68(struct Link *p, unsigned int lo, unsigned int hi);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021B9C50(int a);
void func_021B9CC4(int a)
{
 u8 x[12];
 int k=12;
 if(func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7b,k)!=0) {
  if(((struct Obj03738 *)a)->f24C==7) {
   func_02009CA8((void *)GAME_DATA_GetWifiList((const struct BigObj *)(**(int * *)&((struct Obj03738 *)a)->f244)),x);
   if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc03,k,(u32)x)!=0) {
    func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x79,k);
    func_021B95B8((u8 *)a,(u32)func_021B9C50);
    if(((struct Obj03738 *)a)->fCC0!=0) {
     APP_TASKMENU_CloseMenu((struct TaskMenu *)(((struct Obj03738 *)a)->fCC0));
     ((struct Obj03738 *)a)->fCC0=0;
    }
   }
  } else {
   func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x79,k);
   if(((struct Obj03738 *)a)->fCC0!=0) {
    APP_TASKMENU_CloseMenu((struct TaskMenu *)(((struct Obj03738 *)a)->fCC0));
    ((struct Obj03738 *)a)->fCC0=0;
   }
   func_021B95B8((u8 *)a,(u32)func_021B9C50);
  }
 }
}
