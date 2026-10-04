/*
 * function: func_021F079C
 * address: 0x021F079C
 * packet: pkt_ov032_021F079C
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * volatile: count byte at +0x8c re-read at 021F07A2 and 021F07BE.
 */
#include "../include/Obj07629.h"
typedef unsigned char u8;
void func_021F079C(u8 *p,int v) { int n,i; n=*(volatile u8 *)&((struct Obj07629 *)p)->f8C; for(i=0;i<n;i++) if(v==p[i+0x8d]) return; *(volatile u8 *)&((struct Obj07629 *)p)->f8C=*(volatile u8 *)&((struct Obj07629 *)p)->f8C+1; (p+n)[0x8d]=v; }
