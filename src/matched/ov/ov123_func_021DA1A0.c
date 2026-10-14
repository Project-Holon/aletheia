/*
 * function: PDWACC_STATE_StatePrintNumbersMessage
 * address: 0x021DA1A0
 * packet: pkt_ov123_021DA1A0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PDWACC_MESSAGE_PrintNumberWindows 0x021D9844 thumb ov123
 *   PDWACC_MESSAGE_PrintInWindow 0x021D9730 thumb ov123
 *   PDWACC_STATE_StateWaitInputPrintNumbers 0x021DA16C thumb ov123
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 */
#include "../include/Obj08117.h"
typedef unsigned char u8;
extern void PDWACC_MESSAGE_PrintNumberWindows(char *,int,int);
extern void PDWACC_MESSAGE_PrintInWindow(char *,int);
extern void PDWACC_STATE_StateWaitInputPrintNumbers(char *);
extern void PDWACC_STATE_ChangeState(char *,int,int);
void PDWACC_STATE_StatePrintNumbersMessage(char *p) { PDWACC_MESSAGE_PrintNumberWindows(*(char * *)&((struct Obj08117 *)p)->f10,((struct Obj08117 *)p)->f28,((struct Obj08117 *)p)->f28); PDWACC_MESSAGE_PrintInWindow(*(char * *)&((struct Obj08117 *)p)->f10,8); PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StateWaitInputPrintNumbers,0x13c); }
