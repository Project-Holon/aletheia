/*
 * function: func_021625CC
 * address: 0x021625CC
 * packet: pkt_ov010_021625CC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj07293.h"
typedef unsigned short u16;
void *func_021625CC(char *p, unsigned i) { char *r=*(char * *)&((struct Obj07293 *)p)->f24; if(!r) return 0; if(i>=((struct Obj07293 *)p)->f16) return 0; return r+i*20; }
