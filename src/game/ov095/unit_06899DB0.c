/*
 * file:     unit_06899DB0.c
 * function: func_06899DB0
 * address: 0x06899DB0
 * packet: pkt_ov095_06899DB0
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_06899DC8 0x06899DC8 thumb ov095
 */
#include "../../matched/include/Obj21886.h"
typedef unsigned int u32;
extern int func_06899DC8(u32);
int func_06899DB0(unsigned char *p) { return func_06899DC8(((struct Obj21886 *)p)->fB0) == 0; }
