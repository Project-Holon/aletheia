/*
 * function: PLIST_MESSAGE_IsWindowOpen
 * address: 0x021BB7D8
 * packet: pkt_ov091_021BB7D8
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj20887.h"
typedef unsigned int u32;
int PLIST_MESSAGE_IsWindowOpen(void *unused, u32 p) { if (((struct Obj20887 *)p)->f0 != 4) return 1; return 0; }
