/*
 * function: func_021C7FCC
 * address: 0x021C7FCC
 * packet: pkt_ov093_021C7FCC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u8 func_021B8DDC(u32 x);
extern char *func_021B9AF8(char *, int);
char *func_021C7FCC(u8 *p, int i) { return func_021B9AF8(*(char * *)&((struct Obj00003 *)p)->f8, func_021B8DDC(i)); }
