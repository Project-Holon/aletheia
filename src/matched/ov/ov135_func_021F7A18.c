/*
 * function: WORLDTRADE_DEPOSIT_WaitWipeIn
 * address: 0x021F7A18
 * packet: pkt_ov135_021F7A18
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WORLDTRADE_DEPOSIT_PrintMessage 0x021F7538 thumb ov135
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void);
extern void WORLDTRADE_DEPOSIT_PrintMessage(u8 *p, u32 b, u32 c, u32 d, u32 e);
extern void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b);
int WORLDTRADE_DEPOSIT_WaitWipeIn(u8 *p) { if(WIPE_SYS_EndCheck()){WORLDTRADE_DEPOSIT_PrintMessage(p,9,1,0,0xf0f);WORLDTRADE_SetNextState(p,16,1);}return 2; }
