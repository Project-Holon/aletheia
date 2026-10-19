/*
 * function: IRCBATTLEMATCH_RecvTrainerInfoHandler
 * address: 0x021B9910
 * packet: pkt_ov100_021B9910
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GAME_DATA_GetMyStatusPlayer 0x02012950 thumb
 *   WIFILIST_InsertFriend 0x0200F5EC thumb
 */
#include "../include/Obj10215.h"
#include "../include/Obj22070.h"
typedef unsigned short u16;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
typedef unsigned int   u32;
struct Rec44;
struct Sub24;
extern struct Rec44 *GAME_DATA_GetMyStatusPlayer(struct Sub24 *p, u32 i);
extern int WIFILIST_InsertFriend(void *a0, void *a1, void *a2, void *a3);
void IRCBATTLEMATCH_RecvTrainerInfoHandler(int a,int b,int c,int d,int e)
{
 int p = ((struct Obj10215 *)d)->f244;
 int q = ((struct Obj22070 *)p)->f0;
 if (e == (int)GFL_NET_HANDLE_GetCurrentHandle()) {
  if (a != GFL_NET_SYSTEM_GetCurrentAid()) {
   int r = (int)GAME_DATA_GetMyStatusPlayer((struct Sub24 *)q,a);
   ((struct Obj10215 *)d)->fC90 = WIFILIST_InsertFriend((void *)q,(void *)r,(void *)c,(void *)(((struct Obj10215 *)d)->f278));
  }
 }
}
