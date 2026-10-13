/*
 * function: ITEMMENU_IsBrowseMode
 * address: 0x021B811C
 * packet: pkt_ov070_021B811C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:

 */
#include "../include/Obj20667.h"

typedef unsigned char u8;
int ITEMMENU_IsBrowseMode(u8 *p) { int v = ((struct Obj20667 *)p)->f10; if (v==0 || v==1 || v==3) return 1; return 0; }
