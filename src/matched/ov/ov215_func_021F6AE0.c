/*
 * function: func_021F6AE0
 * address: 0x021F6AE0
 * packet: pkt_ov215_021F6AE0
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MCSS_Exit 0x02014BA8 thumb
 */
#include "../include/Obj25760.h"
typedef unsigned char u8;
extern void MCSS_Exit(u8 *);
void func_021F6AE0(char *p){MCSS_Exit(*(u8 * *)&((struct Obj25760 *)p)->f30);}
