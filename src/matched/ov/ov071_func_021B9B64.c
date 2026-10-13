/*
 * function: MONOLITH_TOOL_CreateBackButton
 * address: 0x021B9B64
 * packet: pkt_ov071_021B9B64
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MONOLITH_TOOL_CreateButton 0x021B6A0C thumb ov071
 *   func_020355C4 0x020355C4 arm
 *   func_021B6B58 0x021B6B58 thumb ov071
 */
#include "../include/Obj02123.h"

extern void MONOLITH_TOOL_CreateButton(void *, void *, int, int, int, int, int, void *);
typedef unsigned char  u8;
extern u8 func_020355C4(void);
extern void func_021B6B58(void **p, int v);
void MONOLITH_TOOL_CreateBackButton(char *p, char *q) { MONOLITH_TOOL_CreateButton(((struct Obj02123 *)p)->f4, q + 8, 1, 2, 0x40, 0xb4, 0x24, 0); if (func_020355C4() == 1) func_021B6B58((void **)(q + 8), 0); }
