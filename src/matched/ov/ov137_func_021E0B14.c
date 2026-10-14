/*
 * function: GURU2_MAIN_ActivatePlayerUnit
 * address: 0x021E0B14
 * packet: pkt_ov137_021E0B14
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_InitPlayerUnit 0x021E0B38 thumb ov137
 */
#include "../include/Obj23779.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_MAIN_InitPlayerUnit(char *,char *,int);
void GURU2_MAIN_ActivatePlayerUnit(char *p,char *q) { char *r; int offset; r=p+0x664; offset=((struct Obj23779 *)q)->f10*0x7c; *(int *)(r+offset)=1; *(char **)(r+offset+0x78)=q; GURU2_MAIN_InitPlayerUnit(p,r+offset,0); }
