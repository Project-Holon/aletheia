/*
 * function: WORLDTRADE_SERVER_Exit
 * address: 0x02200C94
 * packet: pkt_ov135_02200C94
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D55C 0x0207D55C arm
 *   WORLDTRADE_SUBLCD_SetSlotActorPositionsLower 0x021FFD74 thumb ov135
 *   WORLDTRADE_SERVER_DeleteStrings 0x02200EC8 thumb ov135
 *   WORLDTRADE_SERVER_DeleteWindows 0x02200E94 thumb ov135
 *   WORLDTRADE_SERVER_ExitBgPlanes 0x02200DB8 thumb ov135
 *   WORLDTRADE_TITLE_ExitBgPlanes 0x022000E4 thumb ov135
 *   WORLDTRADE_ClearBusyFlag 0x021F4EC8 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0207D55C(volatile u16 *reg);
extern void WORLDTRADE_SUBLCD_SetSlotActorPositionsLower(char *p);
extern void WORLDTRADE_SERVER_DeleteStrings(u8 *);
extern void WORLDTRADE_SERVER_DeleteWindows(u8 *);
extern void WORLDTRADE_SERVER_ExitBgPlanes(void);
extern void WORLDTRADE_TITLE_ExitBgPlanes(char *p);
extern void WORLDTRADE_ClearBusyFlag(u8 *);
int WORLDTRADE_SERVER_Exit(u8 *p) { if(func_0207D55C((u16 *)0x0400106c)) WORLDTRADE_SUBLCD_SetSlotActorPositionsLower((char *)p); WORLDTRADE_SERVER_DeleteStrings(p); WORLDTRADE_SERVER_DeleteWindows(p); WORLDTRADE_SERVER_ExitBgPlanes(); WORLDTRADE_TITLE_ExitBgPlanes((char *)p); WORLDTRADE_ClearBusyFlag(p); return 0; }
