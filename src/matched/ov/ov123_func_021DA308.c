/*
 * function: PDWACC_STATE_StatePrintIntroMessage
 * address: 0x021DA308
 * packet: pkt_ov123_021DA308
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PDWACC_MESSAGE_PrintStream 0x021D9514 thumb ov123
 *   PDWACC_STATE_StateOpenConfirmMenu 0x021DA2DC thumb ov123
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 */
#include "../include/Obj22988.h"
typedef unsigned char u8;
extern void PDWACC_MESSAGE_PrintStream(char *,int);
extern void PDWACC_STATE_StateOpenConfirmMenu(char *);
extern void PDWACC_STATE_ChangeState(char *,int,int);
void PDWACC_STATE_StatePrintIntroMessage(char *p) { PDWACC_MESSAGE_PrintStream(*(char * *)&((struct Obj22988 *)p)->f10,2); PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StateOpenConfirmMenu,0x1b7); }
