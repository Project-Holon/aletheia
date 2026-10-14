/*
 * function: WORLDTRADE_SEARCH_StatePrintMessage172
 * address: 0x021FE974
 * packet: pkt_ov135_021FE974
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_SEARCH_PrintMessage 0x021FF318 thumb ov135
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void WORLDTRADE_SEARCH_PrintMessage(u8 *p, u32 k, int b, int c, int d);extern void WORLDTRADE_SetNextState(char *,unsigned,unsigned);extern void WORLDTRADE_SetStateAndReturn(void *,unsigned,unsigned);extern void GFL_USE_PlaySeDefaultVolume(int);
int WORLDTRADE_SEARCH_StatePrintMessage172(char *p) {WORLDTRADE_SEARCH_PrintMessage((u8 *)p,172,4,0,0xf0f);WORLDTRADE_SetNextState(p,24,3);WORLDTRADE_SetStateAndReturn(p,0,21);GFL_USE_PlaySeDefaultVolume(0x557);return 2;}
