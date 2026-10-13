/*
 * function: PMSIV_CATEGORY_StartClose
 * address: 0x021BB7A0
 * packet: pkt_ov110_021BB7A0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after return.
 * symbols:
 *   PMSIV_BGSCROLL_Start 0x021BC78C thumb ov110
 */
#include "../include/Obj22367.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void PMSIV_BGSCROLL_Start(u8 *,int,int,int,int);
void PMSIV_CATEGORY_StartClose(u8 *p) { ((struct Obj22367 *)p)->f10=0; PMSIV_BGSCROLL_Start(p+56,1,1,0,6); }
