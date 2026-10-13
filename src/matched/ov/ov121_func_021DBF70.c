/*
 * function: func_021DBF70
 * address: 0x021DBF70
 * packet: pkt_ov121_021DBF70
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DC024 0x021DC024 thumb ov121
 *   func_021DC02C 0x021DC02C thumb ov121
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 */
#include "../include/Obj08097.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021DC024(void *); extern char *func_021DC02C(void *); extern u32 POKE_TOOL_CalcIconPalette(u32,u32,u32,u32);
u32 func_021DBF70(void *p) { char *q; if (func_021DC024(p)==1) { q=func_021DC02C(p); return POKE_TOOL_CalcIconPalette(((struct Obj08097 *)q)->f1A,((struct Obj08097 *)q)->f1C,((struct Obj08097 *)q)->f35,((struct Obj08097 *)q)->f5C); } return 0; }
