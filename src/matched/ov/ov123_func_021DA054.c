/*
 * function: PDWACC_STATE_StateFadeOutBgm
 * address: 0x021DA054
 * packet: pkt_ov123_021DA054
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 *   PDWACC_STATE_StateWaitFade 0x021DA03C thumb ov123
 */
#include "../include/Obj22985.h"
extern void WIPE_SYS_Start(void *,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
typedef unsigned int   u32;
extern void GFL_USE_FadeOutBgm(u32 a);
extern void PDWACC_STATE_ChangeState(char *,int,int);
extern void PDWACC_STATE_StateWaitFade(char *p);
void PDWACC_STATE_StateFadeOutBgm(char *p) { WIPE_SYS_Start(0,0,0,0x7fff,6,1,((struct Obj22985 *)p)->f0); GFL_USE_FadeOutBgm(6); PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StateWaitFade,0xe7); }
