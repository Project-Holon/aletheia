/*
 * function: func_021B95F4
 * address: 0x021B95F4
 * packet: pkt_ov110_021B95F4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020247F0 0x020247F0 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj22311.h"
extern void func_020247F0(char *);
extern void func_020307B0(void *);
void func_021B95F4(char *a) { if(a) { func_020247F0(*(char * *)&((struct Obj22311 *)a)->f4); func_020307B0(a); } }
