/*
 * function: ITEMMENU_ShowInputGuardError
 * address: 0x021B8080
 * packet: pkt_ov070_021B8080
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj20665.h"

typedef unsigned char u8;
typedef unsigned short u16;
extern void GFL_USE_PlaySeDefaultVolume(unsigned int id);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void ITEMMENU_ShowInputGuardError(u8 *p) { GFL_USE_PlaySeDefaultVolume(0x663); CLACT_SetActorAnimSeq(((struct Obj20665 *)p)->f72C,2); }
