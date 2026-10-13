/*
 * function: UNION_MSG_DeleteTitleWindow
 * address: 0x0217F624
 * packet: pkt_ov019_0217F624
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_MSGBG_DeletePlainWin 0x021915B4 thumb ov021
 */
#include "../include/Obj00033.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int FIELD_MSGBG_DeletePlainWin(void *a);
void UNION_MSG_DeleteTitleWindow(char *p) { if (((struct Obj00033 *)p)->f2818) { FIELD_MSGBG_DeletePlainWin((void *)(((struct Obj00033 *)p)->f2818)); ((struct Obj00033 *)p)->f2818=0; } }
