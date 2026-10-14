/*
 * function: PDWACC_STATE_StateWaitFadeClearNumbers
 * address: 0x021DA408
 * packet: pkt_ov123_021DA408
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   PDWACC_MESSAGE_DeleteNumberWindows 0x021D9918 thumb ov123
 *   PDWACC_STATE_StateFadeOutBgm 0x021DA054 thumb ov123
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 */
#include "../include/Obj22989.h"
typedef unsigned char u8;
extern unsigned int WIPE_SYS_EndCheck(void);
extern unsigned int KEY_GetTrg(void);
extern void PDWACC_MESSAGE_DeleteNumberWindows(char *);
extern void PDWACC_STATE_StateFadeOutBgm(char *);
extern void PDWACC_STATE_ChangeState(char *,int,int);
void PDWACC_STATE_StateWaitFadeClearNumbers(char *p) { if(WIPE_SYS_EndCheck() && KEY_GetTrg()) { PDWACC_MESSAGE_DeleteNumberWindows(*(char * *)&((struct Obj22989 *)p)->f10); PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StateFadeOutBgm,0x22c); } }
