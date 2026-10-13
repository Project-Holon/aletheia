/*
 * function: PMS_WORDLIST_PageUp
 * address: 0x021BF338
 * packet: pkt_ov110_021BF338
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj04449.h"
typedef unsigned char u8;
typedef unsigned short u16;
int PMS_WORDLIST_PageUp(u8 *p) {
 if(((struct Obj04449 *)p)->f0!=0) {
  if(((struct Obj04449 *)p)->f0>=6) { ((struct Obj04449 *)p)->f0-=6; ((struct Obj04449 *)p)->f8=-6; }
  else { ((struct Obj04449 *)p)->f8=-((struct Obj04449 *)p)->f0; ((struct Obj04449 *)p)->f0=0; }
  return 2;
 }
 return 4;
}
