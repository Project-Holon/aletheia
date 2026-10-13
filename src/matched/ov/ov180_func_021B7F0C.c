/*
 * function: func_021B7F0C
 * address: 0x021B7F0C
 * packet: pkt_ov180_021B7F0C
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B77C4 0x021B77C4 thumb ov180
 *   func_021B7604 0x021B7604 thumb ov180
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   func_021B756C 0x021B756C thumb ov180
 */
#include "../include/Obj04569.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_021B77C4(int *),func_021B7604(int *);
extern void CLACT_DeleteRenderer(void *);
extern void func_021B756C(char *);
void func_021B7F0C(int *p) { func_021B77C4(p); func_021B7604(p); CLACT_DeleteRenderer(((struct Obj04569 *)p)->f9118); func_021B756C((char *)p); }
