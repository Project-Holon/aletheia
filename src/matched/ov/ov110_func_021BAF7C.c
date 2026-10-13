/*
 * function: PMSI_SEARCH_PushKey
 * address: 0x021BAF7C
 * packet: pkt_ov110_021BAF7C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:

 */
#include "../include/Obj10274.h"
typedef unsigned char u8;
typedef unsigned short u16;
void PMSI_SEARCH_PushKey(unsigned p,int v) { int n; *(u16 *)(p+((struct Obj10274 *)p)->fAF0*2+0xad4)=v; n=((struct Obj10274 *)p)->fAF0+1; if(n>12) n=12; else if(n<0) n=0; ((struct Obj10274 *)p)->fAF0=n; }
