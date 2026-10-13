/*
 * function: PMS_WORDLIST_JumpDown
 * address: 0x021BF3D4
 * packet: pkt_ov110_021BF3D4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PMS_INPUT_VIEW_GetWordwinItem 0x021BAD20 thumb ov110
 *   PMS_WORDLIST_GetSelectedIndex 0x021BEDD0 thumb ov110
 */
#include "../include/Obj04450.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned PMS_INPUT_VIEW_GetWordwinItem(u8 *,unsigned);
extern unsigned PMS_WORDLIST_GetSelectedIndex(u8 *);
int PMS_WORDLIST_JumpDown(u8 *p,u8 *q) {
 if(((struct Obj04450 *)q)->f0<((struct Obj04450 *)q)->f2) {
  ((struct Obj04450 *)q)->f0=PMS_INPUT_VIEW_GetWordwinItem(p,((struct Obj04450 *)q)->f2);
  ((struct Obj04450 *)q)->f8=0;
  if((int)PMS_WORDLIST_GetSelectedIndex(q)<((struct Obj04450 *)q)->f4-2) return 2;
  q[6]=0; return 3;
 }
 return 4;
}
