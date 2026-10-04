/*
 * function: func_021C7F04
 * address: 0x021C7F04
 * packet: pkt_ov093_021C7F04
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021C7EEC 0x021C7EEC thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 func_021B8588(void **p);
extern int func_021C7EEC(u8 *, int);
int func_021C7F04(u8 *p, int i) { if (func_021B8588(((struct Obj00003 *)p)->f4) != 3) return func_021C7EEC(p, i); return 3; }
