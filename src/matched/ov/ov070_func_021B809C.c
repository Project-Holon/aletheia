/*
 * function: ITEMMENU_SortAndRedraw
 * address: 0x021B809C
 * packet: pkt_ov070_021B809C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ITEMMENU_SortPocket 0x021B7F54 thumb ov070
 *   ITEMMENU_RedrawList 0x021B6138 thumb ov070
 */
#include "../include/Obj20666.h"

typedef unsigned char u8;
struct Obj;
extern void ITEMMENU_SortPocket(struct Obj *o);
extern void ITEMMENU_RedrawList(char *p);
void ITEMMENU_SortAndRedraw(u8 *p) { ITEMMENU_SortPocket((struct Obj *)p); ((struct Obj20666 *)p)->f818=0xFFFF; ITEMMENU_RedrawList((char *)p); }
