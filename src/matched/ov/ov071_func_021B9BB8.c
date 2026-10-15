/*
 * function: MONOLITH_TOOL_CreateMarker
 * address: 0x021B9BB8
 * packet: pkt_ov071_021B9BB8
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MONOLITH_TOOL_CreateBlink 0x021B7070 thumb ov071
 */
#include "../include/Obj02123.h"

extern void MONOLITH_TOOL_CreateBlink(int *, int *);
void MONOLITH_TOOL_CreateMarker(char *p, char *q) { MONOLITH_TOOL_CreateBlink(*(int * *)&((struct Obj02123 *)p)->f4, (int *)(q + 0x298)); }
