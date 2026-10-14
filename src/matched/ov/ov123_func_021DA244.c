/*
 * function: PDWACC_STATE_StateWaitStreamThenSendRequest
 * address: 0x021DA244
 * packet: pkt_ov123_021DA244
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PDWACC_MESSAGE_UpdateStream 0x021D95F0 thumb ov123
 *   PDWACC_STATE_StateSendRequest 0x021DA3A0 thumb ov123
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 */
#include "../include/Obj22987.h"
typedef unsigned char u8;
extern int PDWACC_MESSAGE_UpdateStream(char *);
extern void PDWACC_STATE_StateSendRequest(char *);
extern void PDWACC_STATE_ChangeState(char *,int,int);
void PDWACC_STATE_StateWaitStreamThenSendRequest(char *p) { if(PDWACC_MESSAGE_UpdateStream(*(char * *)&((struct Obj22987 *)p)->f10)) PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StateSendRequest,0x172); }
