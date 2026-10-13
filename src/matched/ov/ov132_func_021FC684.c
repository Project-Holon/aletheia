/*
 * function: func_021FC684
 * address: 0x021FC684
 * packet: pkt_ov132_021FC684
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FCA38 0x021FCA38 thumb ov132
 *   GAME_COMM_RequestExitNoCallback 0x02026400 thumb
 */
#include "../include/Obj03291.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern void func_021FCA38(char *);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *);
void func_021FC684(char *p) { func_021FCA38(p); GAME_COMM_RequestExitNoCallback(*(struct Comm * *)&((struct Obj03291 *)p)->f50); }
