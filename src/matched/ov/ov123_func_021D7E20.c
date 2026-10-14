/*
 * function: GSYNC_STATE_ApplyIconRecords
 * address: 0x021D7E20
 * packet: pkt_ov123_021D7E20
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_DISP_SetIconRecordSpecies 0x021D6AA8 thumb ov123
 */
#include "../include/Obj22962.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GSYNC_DISP_SetIconRecordSpecies(char *,int,u16);
void GSYNC_STATE_ApplyIconRecords(u8 *p,u8 *list) { int i; u16 n; for(i=0;i<20;i++) { n=*(u16 *)(list+92+i*2); if(n!=0 && list[132+i]!=0 && n<=626) GSYNC_DISP_SetIconRecordSpecies(*(char * *)&((struct Obj22962 *)p)->f14,i,n); } }
