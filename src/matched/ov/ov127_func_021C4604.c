/*
 * function: func_021C4604
 * address: 0x021C4604
 * packet: pkt_ov127_021C4604
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_MAP_IsEmpty 0x021C4790 thumb ov127
 */
#include "../include/Obj10467.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int WF2DMAP_MAP_IsEmpty(char *);
void *func_021C4604(u8 *p) { u32 i; for(i=0;i<((struct Obj10467 *)p)->fC;i++) { if(WF2DMAP_MAP_IsEmpty(*(char * *)&((struct Obj10467 *)p)->f8+i*24)==1) return *(char * *)&((struct Obj10467 *)p)->f8+i*24; } return 0; }
