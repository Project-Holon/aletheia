/*
 * function: UNION_MSG_DeleteRegulationWindow
 * address: 0x0217F7B8
 * packet: pkt_ov019_0217F7B8
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_MSGBG_DeletePlainWin 0x021915B4 thumb ov021
 *   POKE_REGULATION_DeleteText 0x0201A570 thumb
 */
#include "../include/Obj00033.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int FIELD_MSGBG_DeletePlainWin(void *a);
extern void POKE_REGULATION_DeleteText(void *p);
void UNION_MSG_DeleteRegulationWindow(char *p) { if(((struct Obj00033 *)p)->f3530) { FIELD_MSGBG_DeletePlainWin((void *)(((struct Obj00033 *)p)->f2818)); ((struct Obj00033 *)p)->f2818=0; POKE_REGULATION_DeleteText(((struct Obj00033 *)p)->f3530); ((struct Obj00033 *)p)->f3530=0; } }
