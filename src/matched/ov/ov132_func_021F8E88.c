/*
 * function: func_021F8E88
 * address: 0x021F8E88
 * packet: pkt_ov132_021F8E88
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F9E50 0x021F9E50 thumb ov132
 */
#include "../include/Obj14084.h"
typedef unsigned short u16;typedef unsigned int u32;
extern char *func_021F9E50(unsigned);
void func_021F8E88(char *p){int i;*(char * *)&((struct Obj14084 *)p)->f6C=func_021F9E50(((struct Obj14084 *)p)->f0);for(i=0;i<8;i++)*(int *)((u32)p+i*4+0x70)=0;}
