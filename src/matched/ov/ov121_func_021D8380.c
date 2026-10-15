/*
 * function: MYSTERY_DeleteCardMenu
 * address: 0x021D8380
 * packet: pkt_ov121_021D8380
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   MYSTERY_UTIL_DeleteDetailWindow 0x021DA698 thumb ov121
 */
#include "../include/Obj00326.h"
typedef unsigned int   u32;
extern void BG_SYS_ClearSlot(unsigned);
extern void BG_SYS_PushTile(unsigned);
extern void func_02040588(unsigned char which, unsigned char enable);
typedef unsigned char  u8;
extern void MYSTERY_UTIL_DeleteDetailWindow(u8 *p);
void MYSTERY_DeleteCardMenu(char *p) {
 if(((struct Obj00326 *)p)->f270!=0) {BG_SYS_ClearSlot(2);BG_SYS_PushTile(2);func_02040588(2,0);MYSTERY_UTIL_DeleteDetailWindow(((struct Obj00326 *)p)->f270);*(unsigned *)&((struct Obj00326 *)p)->f270=0;}
}
