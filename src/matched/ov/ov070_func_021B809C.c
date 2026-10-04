/*
 * function: func_021B809C
 * address: 0x021B809C
 * packet: pkt_ov070_021B809C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7F54 0x021B7F54 thumb ov070
 *   func_021B6138 0x021B6138 thumb ov070
 */
#include "../include/Obj20666.h"

typedef unsigned char u8;
extern void func_021B7F54(void *p);
extern void func_021B6138(void *p);
void func_021B809C(u8 *p) { func_021B7F54(p); ((struct Obj20666 *)p)->f818=0xFFFF; func_021B6138(p); }
