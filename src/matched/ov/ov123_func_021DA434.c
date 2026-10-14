/*
 * function: PDWACC_STATE_StatePrintResultMessage
 * address: 0x021DA434
 * packet: pkt_ov123_021DA434
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PDWACC_MESSAGE_PrintNumberWindows 0x021D9844 thumb ov123
 *   PDWACC_MESSAGE_PrintInWindow 0x021D9730 thumb ov123
 *   PDWACC_STATE_StateWaitFadeClearNumbers 0x021DA408 thumb ov123
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 */
#include "../include/Obj08118.h"
typedef unsigned char u8;
extern void PDWACC_MESSAGE_PrintNumberWindows(char *,int,int);
extern void PDWACC_MESSAGE_PrintInWindow(char *,int);
extern void PDWACC_STATE_StateWaitFadeClearNumbers(char *);
extern void PDWACC_STATE_ChangeState(char *,int,int);
void PDWACC_STATE_StatePrintResultMessage(char *p) { PDWACC_MESSAGE_PrintNumberWindows(*(char * *)&((struct Obj08118 *)p)->f10,((struct Obj08118 *)p)->f28,((struct Obj08118 *)p)->f28); PDWACC_MESSAGE_PrintInWindow(*(char * *)&((struct Obj08118 *)p)->f10,7); PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StateWaitFadeClearNumbers,0x23c); }
