/*
 * function: MUS_COMM_FUNC_Delete
 * address: 0x021FC684
 * packet: pkt_ov132_021FC684
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUS_COMM_FUNC_DeleteBuffers 0x021FCA38 thumb ov132
 *   GAME_COMM_RequestExitNoCallback 0x02026400 thumb
 */
#include "../include/Obj03291.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern void MUS_COMM_FUNC_DeleteBuffers(char *);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *);
void MUS_COMM_FUNC_Delete(char *p) { MUS_COMM_FUNC_DeleteBuffers(p); GAME_COMM_RequestExitNoCallback(*(struct Comm * *)&((struct Obj03291 *)p)->f50); }
