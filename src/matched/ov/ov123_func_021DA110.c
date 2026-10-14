/*
 * function: PDWACC_STATE_StateRestartTimeIcon
 * address: 0x021DA110
 * packet: pkt_ov123_021DA110
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PDWACC_MESSAGE_PrintStream 0x021D9514 thumb ov123
 *   PDWACC_MESSAGE_RestartTimeIcon 0x021D95B4 thumb ov123
 *   PDWACC_STATE_StateSaveStart 0x021DA0E4 thumb ov123
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 */
#include "../include/Obj14000.h"
typedef unsigned char u8;
extern void PDWACC_MESSAGE_PrintStream(char *,int);
extern void PDWACC_MESSAGE_RestartTimeIcon(char *);
extern void PDWACC_STATE_StateSaveStart(char *);
extern void PDWACC_STATE_ChangeState(char *,int,int);
void PDWACC_STATE_StateRestartTimeIcon(char *p) { PDWACC_MESSAGE_PrintStream(*(char * *)&((struct Obj14000 *)p)->f10,6); PDWACC_MESSAGE_RestartTimeIcon(*(char * *)&((struct Obj14000 *)p)->f10); PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StateSaveStart,0x112); }
