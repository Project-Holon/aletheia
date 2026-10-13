/*
 * function: PMSI_SEARCH_ClearInput
 * address: 0x021BAFE4
 * packet: pkt_ov110_021BAFE4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
#include "../include/Obj03750.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void PMSI_SEARCH_ClearInput(u32 p) { int i; for(i=0;i<13;i++) *(u16 *)(p+i*2+0xad4)=255; ((struct Obj03750 *)p)->fAF0=0; ((struct Obj03750 *)p)->fAF1=0; }
