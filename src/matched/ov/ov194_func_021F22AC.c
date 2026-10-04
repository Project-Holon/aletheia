/*
 * function: func_021F22AC
 * address: 0x021F22AC
 * packet: pkt_ov194_021F22AC
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4F7C 0x021F4F7C thumb ov194
 *   func_021F2150 0x021F2150 thumb ov194
 *   func_021F2190 0x021F2190 thumb ov194
 */
#include "../include/Obj10807.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021F4F7C(char *,const u16 *,u16 *),func_021F2150(u8 *),func_021F2190(char *,u16);
int func_021F22AC(char *p) { u16 v;if(((struct Obj10807 *)p)->f1E!=0 && func_021F4F7C(*(char * *)&((struct Obj10807 *)p)->f90,(u16 *)((u32)p+(((struct Obj10807 *)p)->f1E-1)*2),&v)) { func_021F2150((u8 *)p);func_021F2190(p,v);return 1; }return 0; }
