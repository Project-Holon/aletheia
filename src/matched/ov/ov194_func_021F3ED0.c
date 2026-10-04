/*
 * function: func_021F3ED0
 * address: 0x021F3ED0
 * packet: pkt_ov194_021F3ED0
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02031140 0x02031140 arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj10810.h"
struct S02031140;extern void func_0201CE48(int);extern void func_02031140(struct S02031140 *);extern void func_02082BCC(void *,int,int);
void func_021F3ED0(unsigned char *p){if(((struct Obj10810 *)p)->f0)func_0201CE48(((struct Obj10810 *)p)->f0);func_02031140(*(struct S02031140 * *)&((struct Obj10810 *)p)->f4);func_02082BCC(p,0,16);}
