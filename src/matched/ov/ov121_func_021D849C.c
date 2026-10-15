/*
 * function: MYSTERY_DeletePartyMenu
 * address: 0x021D849C
 * packet: pkt_ov121_021D849C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_UTIL_ClearWindowList 0x021DA2A8 thumb ov121
 *   MYSTERY_UTIL_DeleteWindowList 0x021DA280 thumb ov121
 *   BG_SYS_PushTile 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj00326.h"
typedef unsigned char  u8;
extern void MYSTERY_UTIL_ClearWindowList(u8 *p);
extern void MYSTERY_UTIL_DeleteWindowList(u8 *p);
typedef unsigned int   u32;
extern void BG_SYS_PushTile(unsigned);
extern void func_02040588(unsigned char which, unsigned char enable);
void MYSTERY_DeletePartyMenu(char *p) {
 if(((struct Obj00326 *)p)->f28C) {
  *(unsigned short *)0x04001050=0;
  MYSTERY_UTIL_ClearWindowList(((struct Obj00326 *)p)->f28C);MYSTERY_UTIL_DeleteWindowList(((struct Obj00326 *)p)->f28C);
  *(unsigned *)&((struct Obj00326 *)p)->f28C=0;
  BG_SYS_PushTile(4);func_02040588(6,0);
 }
}
