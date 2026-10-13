/*
 * function: IRC_RANKING_SeqInit
 * address: 0x021B7890
 * packet: pkt_ov106_021B7890
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   IRC_RANKING_SeqSetFunc 0x021B78D0 thumb ov106
 */
#include "../include/Obj22256.h"
extern void MI_CpuFill8(void *,unsigned char,unsigned int); extern void IRC_RANKING_SeqSetFunc(unsigned char *,unsigned int);
void IRC_RANKING_SeqInit(unsigned char *p,unsigned int a,unsigned int b) { MI_CpuFill8(p,0,16); ((struct Obj22256 *)p)->fC=a; IRC_RANKING_SeqSetFunc(p,b); }
