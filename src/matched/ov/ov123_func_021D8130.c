/*
 * function: GSYNC_STATE_StateWaitMessageThenSend
 * address: 0x021D8130
 * packet: pkt_ov123_021D8130
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MESSAGE_UpdateStream 0x021D580C thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateSendListRequest 0x021D80B8 thumb ov123
 */
#include "../include/Obj22964.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GSYNC_MESSAGE_UpdateStream(char *);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateSendListRequest(char *p);
void GSYNC_STATE_StateWaitMessageThenSend(char *p) { if(GSYNC_MESSAGE_UpdateStream(*(char * *)&((struct Obj22964 *)p)->f18)) GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateSendListRequest,0x5b3); }
