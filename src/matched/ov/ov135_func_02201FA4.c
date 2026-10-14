/*
 * function: WORLDTRADE_SERVER_StateShowErrorMessage
 * address: 0x02201FA4
 * packet: pkt_ov135_02201FA4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WORLDTRADE_SERVER_GetErrorMessageId 0x02201F18 thumb ov135
 *   DPW_TR_IsAsyncEnd 0x021C866C arm ov114
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   WORLDTRADE_DeleteTimeIcon 0x021F4FC4 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 WORLDTRADE_SERVER_GetErrorMessageId(u8 *p);
extern int DPW_TR_IsAsyncEnd(void);
extern void WORLDTRADE_SetNextState(u8 *,u32,u32),WORLDTRADE_SetStateAndReturn(u8 *,u32,u32),WORLDTRADE_DeleteTimeIcon(u8 *);
int WORLDTRADE_SERVER_StateShowErrorMessage(u8 *p) { WORLDTRADE_SERVER_GetErrorMessageId(p); if(DPW_TR_IsAsyncEnd()) WORLDTRADE_SetNextState(p,41,48); else WORLDTRADE_SetNextState(p,41,46); WORLDTRADE_SetStateAndReturn(p,0,21); WORLDTRADE_DeleteTimeIcon(p); return 2; }
