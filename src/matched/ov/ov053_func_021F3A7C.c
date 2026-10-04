/*
 * function: func_021F3A7C
 * address: 0x021F3A7C
 * packet: pkt_ov053_021F3A7C
 * region: ov053
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F3AA0 0x021F3AA0 thumb ov053
 *   func_021F3B10 0x021F3B10 thumb ov053
 *   func_021F3B20 0x021F3B20 thumb ov053
 */
#include "../include/Obj03650.h"

extern int func_021F3AA0(char *, int);
extern void func_021F3B10(char *,int);
extern void func_021F3B20(char *,int);
void func_021F3A7C(char *p, int a) { int v=func_021F3AA0(p,a); if (((struct Obj03650 *)p)->f64<v) func_021F3B10(p,v); else if(v<((struct Obj03650 *)p)->f64) func_021F3B20(p,v); }
