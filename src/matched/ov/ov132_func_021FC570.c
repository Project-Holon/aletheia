/*
 * function: func_021FC570
 * address: 0x021FC570
 * packet: pkt_ov132_021FC570
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 */
#include "../include/Obj10564.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern u32 VM_GetU32(struct Cursor *);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
int func_021FC570(int unused,char *p) { u32 a,b,c; a=VM_GetU32(*(struct Cursor * *)&((struct Obj10564 *)p)->f4); b=VM_GetU32(*(struct Cursor * *)&((struct Obj10564 *)p)->f4); c=VM_GetU32(*(struct Cursor * *)&((struct Obj10564 *)p)->f4); GF_FONT_SetTextColor((u8)a,(u8)b,(u8)c); return 0; }
