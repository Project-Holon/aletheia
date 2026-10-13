/*
 * function: FIELD_GIMMICK_GATE_FreeNewsList
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
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void FIELD_GIMMICK_GATE_FreeNewsList(char *p) { if (((struct Obj03645 *)p)->f20) { func_020307B0(((struct Obj03645 *)p)->f20); ((struct Obj03645 *)p)->f20=0; p[0x24]=0; } }
