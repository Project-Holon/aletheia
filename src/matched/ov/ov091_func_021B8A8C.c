/*
 * function: func_021B8A8C
 * address: 0x021B8A8C
 * packet: pkt_ov091_021B8A8C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B8AC4 0x021B8AC4 thumb ov091
 *   func_021B8DB4 0x021B8DB4 thumb ov091
 */
#include "../include/Obj00009.h"
extern void func_021B8AC4(unsigned char *);
extern void func_021B8DB4(unsigned char *);
void func_021B8A8C(unsigned char *p) { func_021B8AC4(p); if(p[15]==4) func_021B8DB4(p); if(p[15]!=4) p[14]=2; if(*(unsigned char *)(*(unsigned *)&((struct Obj00009 *)p)->f280+99)==1) { p[14]=2; p[15]=1; } }
