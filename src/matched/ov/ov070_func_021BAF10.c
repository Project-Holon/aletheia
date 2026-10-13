/*
 * function: ITEMMENU_HideSideWindows
 * address: 0x021BAF10
 * packet: pkt_ov070_021BAF10
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj09882.h"
struct Descriptor;
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
void ITEMMENU_HideSideWindows(char *p) { func_020452E8(((struct Obj09882 *)p)->f504); func_020452E8(((struct Obj09882 *)p)->f764); func_020452E8(((struct Obj09882 *)p)->f75C); }
