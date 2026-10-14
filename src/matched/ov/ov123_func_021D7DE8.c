/*
 * function: GSYNC_STATE_BuildMonEntries
 * address: 0x021D7DE8
 * packet: pkt_ov123_021D7DE8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GSYNC_STATE_BuildMonEntry 0x021D7D18 thumb ov123
 */
#include "../include/Obj05367.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GSYNC_STATE_BuildMonEntry(u8 *,int,int,int,int,int,int);
void GSYNC_STATE_BuildMonEntries(u8 *p,int a,u8 *records) { int i; u8 *r; for(i=0;i<10;i++) { r=records+i*8; if(((struct Obj05367 *)r)->f4==0) break; GSYNC_STATE_BuildMonEntry(p,a,((struct Obj05367 *)r)->f4,r[9],r[8],((struct Obj05367 *)r)->f6,r[10]); } }
