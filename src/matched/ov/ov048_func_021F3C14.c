/*
 * function: func_021F3C14
 * address: 0x021F3C14
 * packet: pkt_ov048_021F3C14
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj03645.h"
extern void func_020307B0(void *p);
void func_021F3C14(char *p) { if (((struct Obj03645 *)p)->f20) { func_020307B0(((struct Obj03645 *)p)->f20); ((struct Obj03645 *)p)->f20=0; p[0x24]=0; } }
