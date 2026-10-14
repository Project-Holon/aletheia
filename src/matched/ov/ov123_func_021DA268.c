/*
 * function: PDWACC_STATE_StateTimeIconMessage
 * address: 0x021DA268
 * packet: pkt_ov123_021DA268
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PDWACC_MESSAGE_PrintStream 0x021D9514 thumb ov123
 *   PDWACC_MESSAGE_RestartTimeIcon 0x021D95B4 thumb ov123
 *   PDWACC_STATE_StateWaitStreamThenSendRequest 0x021DA244 thumb ov123
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 */
#include "../include/Obj14002.h"
typedef unsigned char u8;
extern void PDWACC_MESSAGE_PrintStream(char *,int);
extern void PDWACC_MESSAGE_RestartTimeIcon(char *);
extern void PDWACC_STATE_StateWaitStreamThenSendRequest(char *);
extern void PDWACC_STATE_ChangeState(char *,int,int);
void PDWACC_STATE_StateTimeIconMessage(char *p) { PDWACC_MESSAGE_PrintStream(*(char * *)&((struct Obj14002 *)p)->f10,3); PDWACC_MESSAGE_RestartTimeIcon(*(char * *)&((struct Obj14002 *)p)->f10); PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StateWaitStreamThenSendRequest,0x17b); }
