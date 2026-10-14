/*
 * function: PDWACC_STATE_StateWaitInputStream
 * address: 0x021DA090
 * packet: pkt_ov123_021DA090
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PDWACC_MESSAGE_UpdateStream 0x021D95F0 thumb ov123
 *   KEY_GetTrg 0x020362DC arm
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 *   PDWACC_STATE_StateFadeOutBgm 0x021DA054 thumb ov123
 */
#include "../include/Obj22986.h"
extern int PDWACC_MESSAGE_UpdateStream(char *);
extern unsigned int KEY_GetTrg(void);
extern void PDWACC_STATE_ChangeState(char *,int,int);
extern void PDWACC_STATE_StateFadeOutBgm(char *p);
void PDWACC_STATE_StateWaitInputStream(char *p) { if(PDWACC_MESSAGE_UpdateStream(*(char * *)&((struct Obj22986 *)p)->f10) && KEY_GetTrg()!=0) PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StateFadeOutBgm,0xf1); }
