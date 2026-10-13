/*
 * function: func_02165844
 * address: 0x02165844
 * packet: pkt_ov010_02165844
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_BEACON_CheckActionPriority 0x02027060 thumb
 *   GAME_BEACON_RequestSend 0x02026FB8 thumb
 *   GAME_BEACON_Work 0x02146940 data
 *   func_0216586C 0x0216586C thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 GAME_BEACON_CheckActionPriority(u32 a);
extern void GAME_BEACON_RequestSend(void *);
extern char *GAME_BEACON_Work;
extern int func_0216586C(int a0, int a1);
void func_02165844(void *v) { if(GAME_BEACON_CheckActionPriority(0x31)) { func_0216586C((int)(GAME_BEACON_Work+4),(int)v); GAME_BEACON_RequestSend(GAME_BEACON_Work+4); } }
