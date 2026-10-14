/*
 * function: PDWACC_STATE_StateSaveStart
 * address: 0x021DA0E4
 * packet: pkt_ov123_021DA0E4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PDWACC_MESSAGE_UpdateStream 0x021D95F0 thumb ov123
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 *   PDWACC_STATE_StateSaveMainWait 0x021DA0B8 thumb ov123
 */
#include "../include/Obj10456.h"
extern int PDWACC_MESSAGE_UpdateStream(char *);
extern int GAME_DATA_SaveStart(int);
extern void PDWACC_STATE_ChangeState(char *,int,int);
extern void PDWACC_STATE_StateSaveMainWait(char *p);
void PDWACC_STATE_StateSaveStart(char *p) { if(PDWACC_MESSAGE_UpdateStream(*(char * *)&((struct Obj10456 *)p)->f10)) { ((struct Obj10456 *)p)->f6C=1; GAME_DATA_SaveStart(((struct Obj10456 *)p)->f20); PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StateSaveMainWait,0x109); } }
