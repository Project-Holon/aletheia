/*
 * function: PDWACC_STATE_StateWaitInputPrintNumbers
 * address: 0x021DA16C
 * packet: pkt_ov123_021DA16C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   PDWACC_MESSAGE_PrintNumberWindows 0x021D9844 thumb ov123
 *   PDWACC_MESSAGE_PrintInWindow 0x021D9730 thumb ov123
 *   PDWACC_STATE_StateWaitInputClearWindow 0x021DA138 thumb ov123
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 */
#include "../include/Obj08116.h"
typedef unsigned char u8;
extern unsigned int KEY_GetTrg(void);
extern void PDWACC_MESSAGE_PrintNumberWindows(char *,int,int);
extern void PDWACC_MESSAGE_PrintInWindow(char *,int);
extern void PDWACC_STATE_StateWaitInputClearWindow(char *);
extern void PDWACC_STATE_ChangeState(char *,int,int);
void PDWACC_STATE_StateWaitInputPrintNumbers(char *p) { if(KEY_GetTrg()) { PDWACC_MESSAGE_PrintNumberWindows(*(char * *)&((struct Obj08116 *)p)->f10,((struct Obj08116 *)p)->f28,((struct Obj08116 *)p)->f28); PDWACC_MESSAGE_PrintInWindow(*(char * *)&((struct Obj08116 *)p)->f10,9); PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StateWaitInputClearWindow,0x12a); } }
