/*
 * function: func_021B9BB8
 * address: 0x021B9BB8
 * packet: pkt_ov071_021B9BB8
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7070 0x021B7070 thumb ov071
 */
#include "../include/Obj02123.h"

extern void func_021B7070(int *, int *);
void func_021B9BB8(char *p, char *q) { func_021B7070(*(int * *)&((struct Obj02123 *)p)->f4, (int *)(q + 0x298)); }
