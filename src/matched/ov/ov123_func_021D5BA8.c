/*
 * function: func_021D5BA8
 * address: 0x021D5BA8
 * packet: pkt_ov123_021D5BA8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWC_NdCleanupAsync 0x021C5B80 arm ov114
 */
#include "../include/Obj10437.h"
extern int DWC_NdCleanupAsync(void);
int func_021D5BA8(char *p){if(!((struct Obj10437 *)p)->fC4){if(DWC_NdCleanupAsync())((struct Obj10437 *)p)->fC4=1;}return ((struct Obj10437 *)p)->fB0==0;}
