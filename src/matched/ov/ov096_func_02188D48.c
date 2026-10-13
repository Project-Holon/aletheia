/*
 * function: func_02188D48
 * address: 0x02188D48
 * packet: pkt_ov096_02188D48
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WAZA_TOOL_GetPower 0x0201C1D8 thumb
 */
#include "../include/Obj10177.h"
typedef unsigned short u16;
extern u16 WAZA_TOOL_GetPower(void *p);
int func_02188D48(int a, unsigned char *b) { ((struct Obj10177 *)b)->f38=WAZA_TOOL_GetPower((void *)(((struct Obj10177 *)b)->f2)); return ((struct Obj10177 *)b)->fC4; }
