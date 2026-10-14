/*
 * function: PDWACC_STATE_StateSaveMainWait
 * address: 0x021DA0B8
 * packet: pkt_ov123_021DA0B8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Unsigned result-minus-two range test emits subs/cmp/bhi.
 * symbols:
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   PDWACC_MESSAGE_PrintStream 0x021D9514 thumb ov123
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 *   PDWACC_STATE_StateWaitInputStream 0x021DA090 thumb ov123
 */
#include "../include/Obj10455.h"
extern int GAME_DATA_SaveMain(unsigned char *);
extern void PDWACC_MESSAGE_PrintStream(char *,int);
extern void PDWACC_STATE_ChangeState(char *,int,int);
extern void PDWACC_STATE_StateWaitInputStream(char *p);
void PDWACC_STATE_StateSaveMainWait(char *p) { if((unsigned int)(GAME_DATA_SaveMain(((struct Obj10455 *)p)->f20)-2)<=1) { ((struct Obj10455 *)p)->f6C=0; PDWACC_MESSAGE_PrintStream(*(char * *)&((struct Obj10455 *)p)->f10,11); PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StateWaitInputStream,0xfe); } }
