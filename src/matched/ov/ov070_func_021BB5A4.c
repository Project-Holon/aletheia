/*
 * function: ITEMMENU_UpdateInputGuardAnim
 * address: 0x021BB5A4
 * packet: pkt_ov070_021BB5A4
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   ITEMMENU_GetItemCount 0x021B61C8 thumb ov070
 */
#include "../include/Obj00002.h"
typedef unsigned short u16;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
typedef unsigned char  u8;
extern int ITEMMENU_GetItemCount(u8 *p);
void ITEMMENU_UpdateInputGuardAnim(char *p) { if (((struct Obj00002 *)p)->f80C == 2 || ((struct Obj00002 *)p)->f80C == 3 || ITEMMENU_GetItemCount((u8 *)p) <= 1) CLACT_SetActorAnimSeq(((struct Obj00002 *)p)->f72C, 4); else CLACT_SetActorAnimSeq(((struct Obj00002 *)p)->f72C, 0); }
