/*
 * function: GAME_BEACON_SEARCH_Exit
 * address: 0x02164C20
 * packet: pkt_ov010_02164C20
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIH_DWC_Delete 0x020103E4 thumb
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GAME_BEACON_SEARCH_OnNetExit 0x02164C5C thumb ov010
 */
#include "../include/Obj18982.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIH_DWC_Delete(u8 *);
extern int GFL_NET_Exit(int a0);
extern void GAME_BEACON_SEARCH_OnNetExit(u8 *p);
int GAME_BEACON_SEARCH_Exit(int a,int b,u8 *p) { WIH_DWC_Delete(*(u8 * *)&((struct Obj18982 *)p)->f80); GFL_NET_Exit((int)GAME_BEACON_SEARCH_OnNetExit); return 1; }
