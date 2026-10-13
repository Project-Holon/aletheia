/*
 * function: ITEMMENU_PrintMenuTitle
 * address: 0x021B9BA0
 * packet: pkt_ov070_021B9BA0
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   ITEMMENU_PrintToWindow 0x021BB6E0 thumb ov070
 */
#include "../include/Obj01516.h"
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void ITEMMENU_PrintToWindow(int, unsigned *, unsigned, unsigned short, short, unsigned short);
void ITEMMENU_PrintMenuTitle(char *p) { MSGDATA_ReadString((struct MsgBank *)(((struct Obj01516 *)p)->f51C), 0x87, (void *)(((struct Obj01516 *)p)->f524)); ITEMMENU_PrintToWindow((int)p, (unsigned *)(p + 0x774), *(unsigned *)&((struct Obj01516 *)p)->f524, 0, 4, 0x3DC0); }
