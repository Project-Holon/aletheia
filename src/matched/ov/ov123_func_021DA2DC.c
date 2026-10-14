/*
 * function: PDWACC_STATE_StateOpenConfirmMenu
 * address: 0x021DA2DC
 * packet: pkt_ov123_021DA2DC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PDWACC_MESSAGE_UpdateStream 0x021D95F0 thumb ov123
 *   PDWACC_MESSAGE_OpenYesNoMenu 0x021D9670 thumb ov123
 *   PDWACC_STATE_StateConfirmMenuSelect 0x021DA290 thumb ov123
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 */
#include "../include/Obj10457.h"
typedef unsigned char u8;
extern int PDWACC_MESSAGE_UpdateStream(char *);
extern int PDWACC_MESSAGE_OpenYesNoMenu(char *,int);
extern void PDWACC_STATE_StateConfirmMenuSelect(char *);
extern void PDWACC_STATE_ChangeState(char *,int,int);
void PDWACC_STATE_StateOpenConfirmMenu(char *p) { if(PDWACC_MESSAGE_UpdateStream(*(char * *)&((struct Obj10457 *)p)->f10)) { ((struct Obj10457 *)p)->f14=PDWACC_MESSAGE_OpenYesNoMenu(*(char * *)&((struct Obj10457 *)p)->f10,0); PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StateConfirmMenuSelect,0x1a6); } }
