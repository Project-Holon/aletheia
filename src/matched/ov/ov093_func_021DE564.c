/*
 * function: HAND_ITEM_RaiseCriticalRankByOne, HAND_ITEM_GetLuckyPunchHandlers
 * address: 0x021DE564
 * packet: pkt_ov093_021DE564
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: u8 local holds getter result before increment; narrow callee argument.
 * unit: yes
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 *   gLuckyPunchHandlers 0x021F146C data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
void HAND_ITEM_RaiseCriticalRankByOne(int a, int b, int c) { u8 j; if(c == BTL_EVENT_GetVar(3)) { j=BTL_EVENT_GetVar(0x2c); BTL_EVENT_OverwriteVar(0x2c,(u8)(j+1)); } }
extern u8 gLuckyPunchHandlers[];
void *HAND_ITEM_GetLuckyPunchHandlers(int *p) { *p=1; return gLuckyPunchHandlers; }
