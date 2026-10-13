/*
 * function: WIFICLUBACTOR_SetPlayerState
 * address: 0x021BA228
 * packet: pkt_ov099_021BA228
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUBACTOR_UpdatePlayer 0x021BA418 thumb ov099
 *   WIFICLUBACTOR_NoOpAnim 0x021BA2D0 thumb ov099
 *   WIFICLUBACTOR_QueueActorMove 0x021BA5B4 thumb ov099
 */
#include "../include/Obj02800.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WIFICLUBACTOR_UpdatePlayer(void *,void *); extern int WIFICLUBACTOR_NoOpAnim(void *,void *); extern void WIFICLUBACTOR_QueueActorMove(void *,int,void *);
void WIFICLUBACTOR_SetPlayerState(void *w,u8 *s) { ((struct Obj02800 *)s)->f10=(void *)WIFICLUBACTOR_UpdatePlayer; ((struct Obj02800 *)s)->f18=(void *)WIFICLUBACTOR_NoOpAnim; ((struct Obj02800 *)s)->fC=0; WIFICLUBACTOR_QueueActorMove(w,0,s); }
