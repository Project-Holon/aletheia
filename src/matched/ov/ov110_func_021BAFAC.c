/*
 * function: PMSI_SEARCH_PopKey
 * address: 0x021BAFAC
 * packet: pkt_ov110_021BAFAC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:

 */
#include "../include/Obj08000.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
int PMSI_SEARCH_PopKey(u32 p) { if (((struct Obj08000 *)p)->fAF0==0) return 0; if (((struct Obj08000 *)p)->fAEC==255) --((struct Obj08000 *)p)->fAF0; *(u16 *)(p+((struct Obj08000 *)p)->fAF0*2+0xad4)=255; return 1; }
