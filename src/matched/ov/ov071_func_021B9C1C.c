/*
 * function: MONOLITH_TOOL_DeleteScrollArrows
 * address: 0x021B9C1C
 * packet: pkt_ov071_021B9C1C
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MONOLITH_TOOL_DeleteActorAt 0x021B7168 thumb ov071
 */
#include "../include/Obj13185.h"

extern void MONOLITH_TOOL_DeleteActorAt(void *);
void MONOLITH_TOOL_DeleteScrollArrows(char *p) { MONOLITH_TOOL_DeleteActorAt(((struct Obj13185 *)p)->f18); MONOLITH_TOOL_DeleteActorAt(((struct Obj13185 *)p)->f1C); }
